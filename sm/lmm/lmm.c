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
/* File containing the implementation of the Logical Machine Manager.       */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "rpc_scmi.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

static volatile uint32_t s_bootLm;
static volatile uint8_t s_bootSkip;
static volatile int32_t s_bootStatus;
static uint64_t s_lmStartTime[SM_NUM_LM];

/*--------------------------------------------------------------------------*/
/* Init logical machine manager                                             */
/*--------------------------------------------------------------------------*/
int32_t LMM_Init(uint32_t *mSel)
{
    int32_t status;
    uint32_t numClock;
    const uint32_t *clockList;

    /* Init LMM system management */
    status = LMM_SystemInit();

    /* Success? */
    if (status == SM_ERR_SUCCESS)
    {
        /* Get LM0 default resource state */
        DEV_SM_LmmInitGet(&numClock, &clockList);

        /* Init LMM clock management */
        status = LMM_ClockInit(numClock, clockList);
    }

    /* Init LMM voltage management */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_VoltageInit();
    }

    /* Init LMM CPU management */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_CpuInit();
    }

#ifdef USES_FUSA
    /* Init FuSa */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_FusaInit(mSel);
    }
#endif

    /* Init LMs */
    if (status == SM_ERR_SUCCESS)
    {
        /* Loop over LMs */
        for (uint32_t lmId = 0U; lmId < SM_NUM_LM; lmId++)
        {
            /* Init RPC */
            switch (g_lmmConfig[lmId].rpcType)
            {
                case SM_RPC_NONE:
                    break;
                case SM_RPC_SCMI:
                    /* Init SCMI instance */
                    status = RPC_SCMI_Init(g_lmmConfig[lmId].rpcInst);
                    break;
                default:
                    status = SM_ERR_INVALID_PARAMETERS;
                    break;
            }

            /* Exit loop on error */
            if (status != SM_ERR_SUCCESS)
            {
                break;
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Boot logical machines                                                    */
/*                                                                          */
/* Note only call from main(). Cannot be called from an interrupt context.  */
/*--------------------------------------------------------------------------*/
int32_t LMM_Boot(uint32_t mSel, uint32_t lmmInitFlags)
{
    int32_t status;

    /* Inform LM system of mode select */
    status = LMM_SystemModeSelSet(mSel);

    /* Get starting system counter */
    uint64_t startTime = DEV_SM_Usec64Get();

    /* Boot LMs */
    if ((status == SM_ERR_SUCCESS)
        && ((lmmInitFlags & LM_INIT_FLAGS_BOOT) != 0U))
    {
        /* Loop over boot order */
        for (uint8_t bootOrder = 1U; bootOrder <= SM_NUM_LM; bootOrder++)
        {
            /* Loop over LMs */
            for (uint32_t lmId = 0U; lmId < SM_NUM_LM; lmId++)
            {
                /* Boot if LM requested in this order */
                if (g_lmmConfig[lmId].boot[mSel] == bootOrder)
                {
                    uint64_t bootTime = startTime
                        + ((uint64_t) g_lmmConfig[lmId].rtime);

                    /* Wait until start time */
                    while (DEV_SM_Usec64Get() < bootTime)
                    {
                        ; /* Intentional empty while */
                    }

                    /* Record calling parms */
                    s_bootLm = lmId;
                    s_bootSkip = g_lmmConfig[lmId].bootSkip[mSel];

                    /* Trigger SWI handler */
                    SWI_Trigger();

                    /* Collect status */
                    status = s_bootStatus;
                }

                /* Exit loop on error */
                if (status != SM_ERR_SUCCESS)
                {
                    break;
                }
            }

            /* Exit loop on error */
            if (status != SM_ERR_SUCCESS)
            {
                break;
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Post-boot clean-up                                                       */
/*                                                                          */
/* Run any clean-up required after starting all LM                          */
/*--------------------------------------------------------------------------*/
int32_t LMM_PostBoot(uint32_t mSel, uint32_t lmmInitFlags)
{
    /* Just passthru to board/device */
    return SM_SYSTEMPOSTBOOT(mSel, lmmInitFlags);
}

/*--------------------------------------------------------------------------*/
/* Return LM name                                                           */
/*--------------------------------------------------------------------------*/
int32_t LMM_LmNameGet(uint32_t lmId, uint32_t lm, string *lmNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Length requested? */
    if (len != NULL)
    {
        static int32_t s_maxLen = 0;

        /* Already known? */
        if (s_maxLen == 0)
        {
            /* Loop over array */
            for (uint32_t idx = 0U; idx < SM_NUM_LM; idx++)
            {
                /* Get max len */
                s_maxLen = MAX(s_maxLen, (int32_t)
                    DEV_SM_StrLen(g_lmmConfig[idx].name));
            }
        }

        /* Return result */
        *len = s_maxLen;
    }

    /* Return pointer to name */
    *lmNameAddr = g_lmmConfig[lm].name;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset the RPC                                                            */
/*--------------------------------------------------------------------------*/
int32_t LMM_RpcReset(uint32_t lmId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Init RPC */
    switch (g_lmmConfig[lmId].rpcType)
    {
        case SM_RPC_NONE:
            break;
        case SM_RPC_SCMI:
            status = RPC_SCMI_Reset(g_lmmConfig[lmId].rpcInst);
            break;
        default:
            status = SM_ERR_INVALID_PARAMETERS;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Trigger notification event in the RPC                                    */
/*--------------------------------------------------------------------------*/
int32_t LMM_RpcNotificationTrigger(uint32_t lmId,
    const lmm_rpc_trigger_t *trigger)
{
    int32_t status = SM_ERR_SUCCESS;
    lmm_rpc_trigger_t newTrigger = *trigger;

    /* Add instance */
    newTrigger.rpcInst = g_lmmConfig[lmId].rpcInst;

    /* Dispatch to RPC interface */
    switch (g_lmmConfig[lmId].rpcType)
    {
        case SM_RPC_NONE:
            break;
        case SM_RPC_SCMI:
            status = RPC_SCMI_Trigger(&newTrigger);
            break;
        default:
            status = SM_ERR_INVALID_PARAMETERS;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Dump all collected errors                                                */
/*--------------------------------------------------------------------------*/
void LMM_ErrorDump(void)
{
    /* Loop over LMs */
    for (uint32_t lmId = 0U; lmId < SM_NUM_LM; lmId++)
    {
        /* Dump RPC errors */
        switch (g_lmmConfig[lmId].rpcType)
        {
            case SM_RPC_NONE:
                break;
            case SM_RPC_SCMI:
                RPC_SCMI_ErrorDump(g_lmmConfig[lmId].rpcInst);
                break;
            default:
                ; /* Intentional empty default */
                break;
        }
    }

    /* Dump device/board errors */
    SM_ERRORDUMP();
}

/*--------------------------------------------------------------------------*/
/* Common LMM handler                                                       */
/*--------------------------------------------------------------------------*/
void LMM_Handler(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Not required to boot? */
    if (s_bootSkip != 0U)
    {
        /* Check if possible to boot? */
        status = LMM_SystemLmCheck(s_bootLm);
    }

    /* Okay to try to start? */
    if (status == SM_ERR_SUCCESS)
    {
        lmm_rst_rec_t bootRec, shutdownRec;

        /* Get system reason info */
        LM_SystemReason(0U, &bootRec, &shutdownRec);

        /* Boot LM and store status */
        s_bootStatus = LMM_SystemLmBoot(0U, 0U, s_bootLm, &bootRec);

        /* Store boot time */
        s_lmStartTime[s_bootLm] = DEV_SM_Usec64Get();
    }
    else
    {
        /* Report no error */
        s_bootStatus = SM_ERR_SUCCESS;
    }
}

/*--------------------------------------------------------------------------*/
/* Get LM boot time                                                         */
/*--------------------------------------------------------------------------*/
uint64_t LMM_BootTimeGet(uint32_t lmId)
{
    return s_lmStartTime[lmId];
}

/*--------------------------------------------------------------------------*/
/* Get cfg file name                                                        */
/*--------------------------------------------------------------------------*/
string LMM_CfgNameGet(void)
{
    static string cfgName = SM_LM_CFG_NAME;

    return cfgName;
}

