/*
** ###################################################################
**
** Copyright 2023-2024 NXP
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** o Redistributions of source code must retain the above copyright notice, this list
**   of conditions and the following disclaimer.
**
** o Redistributions in binary form must reproduce the above copyright notice, this
**   list of conditions and the following disclaimer in the documentation and/or
**   other materials provided with the distribution.
**
** o Neither the name of the copyright holder nor the names of its
**   contributors may be used to endorse or promote products derived from this
**   software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
** ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
** ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/* File containing the implementation of the Shared Memory Transport (SMT). */
/*==========================================================================*/

/* Includes */

#include <stdint.h>
#include "sm.h"
#include "rpc_smt.h"
#include "config_smt.h"
#include "rpc_scmi.h"
#ifdef USES_MB_LOOPBACK
#include "mb_loopback.h"
#endif
#ifdef USES_MB_MU
#include "mb_mu.h"
#endif
#include "crc.h"

/* Local defines */

#define SMT_FREE      (1UL << 0U)
#define SMT_ERROR     (1UL << 1U)
#define SMT_COMP_INT  (1UL << 0U)

/* Local types */

typedef struct
{
    uint32_t resv;
    volatile uint32_t channelStatus;
    uint32_t impStatus;
    uint32_t impCrc;
    uint32_t channelFlags;
    uint32_t length;
    uint32_t header;
    uint32_t payload[SMT_BUFFER_PAYLOAD / 4U];
} rpc_smt_buf_t;

/* Local variables */

static const rpc_smt_chn_config_t s_smtConfig[SM_NUM_SMT_CHN] =
{
    SM_SMT_CHN_CONFIG_DATA
};

static bool s_smtInProgress[SM_NUM_SMT_CHN];

/* Local functions */

static rpc_smt_buf_t *RPC_SMT_SmaGet(uint32_t smtChannel);
static int32_t RPC_SMT_DoorbellRing(uint32_t smtChannel);

/*--------------------------------------------------------------------------*/
/* Init SMT channel                                                         */
/*--------------------------------------------------------------------------*/
int32_t RPC_SMT_Init(uint32_t smtChannel, bool noIrq, uint32_t initCount)
{
    int32_t status = SM_ERR_SUCCESS;
    rpc_smt_buf_t *buf = RPC_SMT_SmaGet(smtChannel);

    /* Check channel */
    if (smtChannel >= SM_NUM_SMT_CHN)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Check for error? */
    if (status == SM_ERR_SUCCESS)
    {
        /* Init mailbox */
        switch (s_smtConfig[smtChannel].mbType)
        {
#ifdef USES_MB_LOOPBACK
            case SM_MB_LOOPBACK:
                status = MB_LOOPBACK_Init(s_smtConfig[smtChannel].mbInst,
                    s_smtConfig[smtChannel].mbDoorbell, noIrq, initCount);
                break;
#endif
#ifdef USES_MB_MU
            case SM_MB_MU:
                status = MB_MU_Init(s_smtConfig[smtChannel].mbInst,
                    s_smtConfig[smtChannel].mbDoorbell, noIrq, initCount);
                break;
#endif
            default:
                status = SM_ERR_INVALID_PARAMETERS;
                break;
        }
    }

    /* Init the SMT header */
    if (status == SM_ERR_SUCCESS)
    {
        /* Clear buffer + ECC */
        for (uint32_t word = 0U; word < (SMT_BUFFER_SIZE / 4U); word++)
        {
            uint32_t *sma = (uint32_t*) buf;
            sma[word] = 0U;
        }

        /* Mark channel CRC mode */
        buf->impStatus = s_smtConfig[smtChannel].crc;

        /* Mark channel as free */
        buf->channelStatus = SMT_FREE;

        /* Not in progress */
        s_smtInProgress[smtChannel] = false;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get SMT header address                                                   */
/*--------------------------------------------------------------------------*/
void *RPC_SMT_HdrAddrGet(uint32_t smtChannel)
{
    void *rtn = NULL;
    rpc_smt_buf_t *buf = RPC_SMT_SmaGet(smtChannel);

    /* Get address of header */
    if (buf != NULL)
    {
        rtn = (void*) &buf->header;
    }

    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Get SMT channel free status                                              */
/*--------------------------------------------------------------------------*/
bool RPC_SMT_ChannelFree(uint32_t smtChannel)
{
    const rpc_smt_buf_t *buf = RPC_SMT_SmaGet(smtChannel);
    bool freeState = true;

    /* Check for valid buffer */
    if (buf != NULL)
    {
        freeState = ((buf->channelStatus & SMT_FREE) != 0U);
    }

    return freeState;
}

/*--------------------------------------------------------------------------*/
/* Dispatch SMT doorbell                                                    */
/*--------------------------------------------------------------------------*/
void RPC_SMT_Dispatch(uint32_t smtChannel)
{
    /* Call RPC-specific dispatcher */
    switch (s_smtConfig[smtChannel].rpcType)
    {
        case SM_RPC_SCMI:
            RPC_SCMI_Dispatch(s_smtConfig[smtChannel].rpcChannel);
            break;
        default:
            ; /* Intentional empty default */
            break;
    }

    /* Not completed? */
    if (s_smtInProgress[smtChannel])
    {
        rpc_smt_buf_t *buf = RPC_SMT_SmaGet(smtChannel);

        /* Mark channel in error */
        buf->channelFlags = SMT_ERROR;

        /* Force completion */
        (void) RPC_SMT_Tx(smtChannel, 0U, true, false);
    }
}

/*--------------------------------------------------------------------------*/
/* Get doorbell state and clear                                             */
/*--------------------------------------------------------------------------*/
bool RPC_SMT_DoorbellState(uint32_t smtChannel)
{
    bool state = false;

    /* Check channel */
    if (smtChannel < SM_NUM_SMT_CHN)
    {
        switch (s_smtConfig[smtChannel].mbType)
        {
#ifdef USES_MB_LOOPBACK
            case SM_MB_LOOPBACK:
                state = MB_LOOPBACK_DoorbellState(
                    s_smtConfig[smtChannel].mbInst,
                    s_smtConfig[smtChannel].mbDoorbell);
                break;
#endif
#ifdef USES_MB_MU
            case SM_MB_MU:
                state = MB_MU_DoorbellState(s_smtConfig[smtChannel].mbInst,
                    s_smtConfig[smtChannel].mbDoorbell);
                break;
#endif
            default:
                ; /* Intentional empty default */
                break;
        }
    }

    /* Return state */
    return state;
}

/*--------------------------------------------------------------------------*/
/* Get abort status                                                         */
/*--------------------------------------------------------------------------*/
int32_t RPC_SMT_IsAborted(uint32_t smtChannel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check channel */
    if (smtChannel >= SM_NUM_SMT_CHN)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Check for error? */
    if (status == SM_ERR_SUCCESS)
    {
        switch (s_smtConfig[smtChannel].mbType)
        {
#ifdef USES_MB_LOOPBACK
            case SM_MB_LOOPBACK:
                status = MB_LOOPBACK_IsAborted(s_smtConfig[smtChannel].mbInst,
                    s_smtConfig[smtChannel].mbDoorbell);
                break;
#endif
#ifdef USES_MB_MU
            case SM_MB_MU:
                status = MB_MU_IsAborted(s_smtConfig[smtChannel].mbInst,
                    s_smtConfig[smtChannel].mbDoorbell);
                break;
#endif
            default:
                status = SM_ERR_INVALID_PARAMETERS;
                break;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* SMT send                                                                 */
/*--------------------------------------------------------------------------*/
int32_t RPC_SMT_Tx(uint32_t smtChannel, uint32_t len, bool callee,
    bool compInt)
{
    int32_t status = SM_ERR_SUCCESS;
    rpc_smt_buf_t *buf = RPC_SMT_SmaGet(smtChannel);

    /* Check length */
    if (len > (SMT_BUFFER_SIZE - SMT_BUFFER_HEADER))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }
    else
    {
        uint32_t impStatus = s_smtConfig[smtChannel].crc;

        if (callee)
        {
            /* Check if free */
            if (RPC_SMT_ChannelFree(smtChannel))
            {
                status = SM_ERR_PROTOCOL_ERROR;
            }
        }
        else
        {
            /* Check if busy */
            if (!RPC_SMT_ChannelFree(smtChannel))
            {
                status = SM_ERR_PROTOCOL_ERROR;
            }
        }

        if (status == SM_ERR_SUCCESS)
        {
            /* Fill in reserved */
            buf->resv = 0U;

            /* Mark channel CRC mode */
            buf->impStatus = impStatus;

            /* Completion interrupt if caller wants */
            if (!callee)
            {
                if (compInt)
                {
                    buf->channelFlags = SMT_COMP_INT;
                }
                else
                {
                    buf->channelFlags = 0U;
                }
            }

            /* Fill in length */
            buf->length = len;

            /* Calculate CRC */
            switch (impStatus)
            {
                case SM_SMT_CRC_XOR:
                    // coverity[misra_c_2012_rule_18_1_violation:FALSE]
                    buf->impCrc = CRC_Xor((const uint32_t*) &buf->header,
                        len / 4U);
                    break;
                case SM_SMT_CRC_CRC32:
                    buf->impCrc = CRC_Crc32((const uint8_t*) &buf->header,
                        len);
                    break;
                default:
                    ; /* Intentional empty while */
                    break;
            }

            if (callee)
            {
                /* Mark as free */
                buf->channelStatus |= SMT_FREE;

                /* Mark as complete */
                s_smtInProgress[smtChannel] = false;
            }
            else
            {
                /* Mark as busy */
                buf->channelStatus &= ~SMT_FREE;
            }

            if (callee)
            {
                /* Generate completion interrupt */
                if ((buf->channelFlags & SMT_COMP_INT) != 0U)
                {
                    status = RPC_SMT_DoorbellRing(smtChannel);
                }
            }
            else
            {
                /* Generate interrupt */
                status = RPC_SMT_DoorbellRing(smtChannel);
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* SMT receive                                                              */
/*--------------------------------------------------------------------------*/
int32_t RPC_SMT_Rx(uint32_t smtChannel, void* msgRx, uint32_t *len,
    bool callee)
{
    int32_t status = SM_ERR_SUCCESS;
    const rpc_smt_buf_t *buf = RPC_SMT_SmaGet(smtChannel);
    uint32_t impStatus = s_smtConfig[smtChannel].crc;

    /* Callee? */
    if (callee)
    {
        /* Mark in progress */
        s_smtInProgress[smtChannel] = true;
    }

    /* Check length */
    if (buf->length > *len)
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }
    else
    {
        if (callee)
        {
            /* Check if free */
            if (RPC_SMT_ChannelFree(smtChannel))
            {
                status = SM_ERR_PROTOCOL_ERROR;
            }
        }
        else
        {
            /* Check if busy */
            if (!RPC_SMT_ChannelFree(smtChannel))
            {
                status = SM_ERR_PROTOCOL_ERROR;
            }
        }

        if (status == SM_ERR_SUCCESS)
        {
            /* Record the length */
            *len = buf->length;

            /* Copy payload */
            (void) memcpy(msgRx, (const void*) &buf->header, *len);

            /* Check the CRC */
            switch (impStatus)
            {
                case SM_SMT_CRC_XOR:
                    if (buf->impCrc != CRC_Xor((const uint32_t*) msgRx,
                        *len / 4U))
                    {
                        status = SM_ERR_CRC_ERROR;
                    }
                    break;
                case SM_SMT_CRC_CRC32:
                    if (buf->impCrc != CRC_Crc32((const uint8_t*) msgRx,
                        *len))
                    {
                        status = SM_ERR_CRC_ERROR;
                    }
                    break;
                default:
                    ; /* Intentional empty while */
                    break;
            }
        }
    }

    /* Return status */
    return status;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Get SMT SMA                                                              */
/*--------------------------------------------------------------------------*/
static rpc_smt_buf_t *RPC_SMT_SmaGet(uint32_t smtChannel)
{
    rpc_smt_buf_t *buf = NULL;

    switch (s_smtConfig[smtChannel].mbType)
    {
#ifdef USES_MB_LOOPBACK
        case SM_MB_LOOPBACK:
            buf = (rpc_smt_buf_t*) MB_LOOPBACK_SmaGet(
                s_smtConfig[smtChannel].mbInst,
                s_smtConfig[smtChannel].mbDoorbell);
            break;
#endif
#ifdef USES_MB_MU
        case SM_MB_MU:
            buf = (rpc_smt_buf_t*) MB_MU_SmaGet(
                s_smtConfig[smtChannel].mbInst,
                s_smtConfig[smtChannel].mbDoorbell);
            break;
#endif
        default:
            ; /* Intentional empty default */
            break;
    }

    return buf;
}

/*--------------------------------------------------------------------------*/
/* Trigger MB doorbell                                                      */
/*--------------------------------------------------------------------------*/
static int32_t RPC_SMT_DoorbellRing(uint32_t smtChannel)
{
    int32_t status = SM_ERR_SUCCESS;

    switch (s_smtConfig[smtChannel].mbType)
    {
#ifdef USES_MB_LOOPBACK
        case SM_MB_LOOPBACK:
            break;
#endif
#ifdef USES_MB_MU
        case SM_MB_MU:
            status = MB_MU_DoorbellRing(
                s_smtConfig[smtChannel].mbInst,
                s_smtConfig[smtChannel].mbDoorbell);
            break;
#endif
        default:
            ; /* Intentional empty default */
            break;
    }

    /* Return status */
    return status;
}

