/*
** ###################################################################
**
** Copyright 2023 NXP
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
/* File containing the implementation of the Logical Machine Manager        */
/* FuSa.                                                                    */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Init LMM FuSa management                                                 */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaInit(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return number of S-EENV                                                  */
/*--------------------------------------------------------------------------*/
void LMM_SsenvNumGet(uint32_t *num)
{
    /* Count S-EENV */
    *num = 0U;
    for (uint32_t lmId = 0U; lmId < SM_NUM_LM; lmId++)
    {
        if (g_lmmConfig[lmId].safeType == LMM_SAFE_TYPE_SEENV)
        {
            (*num)++;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Get current FuSa system state                                            */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaFeenvStateGet(uint32_t lmId, uint32_t *feenvState,
    uint32_t *mselMode)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Request F-EENV transition to new state                                   */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaFeenvStateSet(uint32_t lmId, uint32_t feenvState,
    bool graceful)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Switch state */
    switch (feenvState)
    {
        case LMM_FUSA_FEENV_STATE_SOC_STANDBY:
            /* System suspend (graceful only) */
            status = LMM_SystemSuspend(lmId, 0U);
            break;
        case LMM_FUSA_FEENV_STATE_SOC_SHUTDOWN:
            /* System shutdown */
            status = LMM_SystemShutdown(lmId, 0U, graceful,
                &g_swReason);
            break;
        case LMM_FUSA_FEENV_STATE_SOC_RESET:
            /* System reset*/
            status = LMM_SystemReset(lmId, 0U, graceful,
                &g_swReason);
            break;
        case LMM_FUSA_FEENV_STATE_PRE_SAFETY:
        case LMM_FUSA_FEENV_STATE_SAFETY_RUNTIME:
        default:
            status = SM_ERR_INVALID_PARAMETERS;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get S-EENV state                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaSeenvStateGet(uint32_t lmId, uint32_t *seenvState)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set S-EENV state                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaSeenvStateSet(uint32_t lmId, uint32_t seenvState,
    uint32_t pingCookie, uint32_t scstSignature)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get fault state                                                          */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaFaultGet(uint32_t lmId, uint32_t faultId,
    bool *state)
{
    return LMM_FaultGet(faultId, state);
}

/*--------------------------------------------------------------------------*/
/* Set fault                                                                */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaFaultSet(uint32_t lmId, uint32_t faultId, bool set)
{
    int32_t status;

    status = LMM_FaultSet(lmId, faultId, set);

    /* TODO: Work through fault with no reaction */

    if ((status == SM_ERR_SUCCESS) && !set)
    {
        /* Send FuSa fault clear notification */
        for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
        {
            lmm_rpc_trigger_t trigger =
            {
                .event = LMM_TRIGGER_FUSA_FAULT,
                .parm[0] = faultId,
                .parm[1] = 0U,
                .parm[2] = lmId
            };

            (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Temporarily disable fault handling                                       */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaScheckEvntrig(uint32_t lmId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Complete fault handling                                                  */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaFaultRecover(uint32_t faultId, uint32_t *reaction,
    uint32_t *lm)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Send FuSa fault set notification */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        lmm_rpc_trigger_t trigger =
        {
            .event = LMM_TRIGGER_FUSA_FAULT,
            .parm[0] = faultId,
            .parm[1] = 1U,
            .parm[2] = 0U
        };

        (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Complete fault handling                                                  */
/*--------------------------------------------------------------------------*/
void LMM_FusaFaultCleared(uint32_t faultId)
{
    /* Send FuSa fault clear notification */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        lmm_rpc_trigger_t trigger =
        {
            .event = LMM_TRIGGER_FUSA_FAULT,
            .parm[0] = faultId,
            .parm[1] = 0U,
            .parm[2] = 0U
        };

        (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
    }
}

/*--------------------------------------------------------------------------*/
/* Calculate CRC                                                            */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaCrcCalculate(uint32_t lmId, uint32_t crcChannel,
    uint32_t crcCfg, uint64_t memStart, uint32_t memSize)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get CRC calculation results                                              */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaCrcResultGet(uint32_t lmId, uint32_t crcChannel,
    uint64_t *memStart, uint32_t *memSize, uint32_t *crcResult)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

