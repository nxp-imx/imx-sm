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
/* system.                                                                  */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint32_t s_modeSel = 0U;
static uint8_t s_lmState[SM_NUM_LM];
static int32_t s_lmError[SM_NUM_LM];
static lmm_rst_rec_t s_lmBootReason[SM_NUM_LM];
static lmm_rst_rec_t s_lmShutdownReason[SM_NUM_LM];

/* Global variables */

const lmm_rst_rec_t g_swReason = DEV_SM_RST_REC_SW;
static const lmm_start_t s_lmmStart[SM_LM_NUM_START] =
{
    SM_LM_START_DATA
};

/* Local functions */

static int32_t LMM_DoBoot(lmm_rpc_trigger_t *trigger,
    const lmm_rst_rec_t *bootRec);
static int32_t LMM_DoShutdown(lmm_rpc_trigger_t *trigger,
    const lmm_rst_rec_t *shutdownRec);
static int32_t LM_ProcessStart(uint32_t lmId, uint32_t start);
static int32_t LM_ProcessStop(uint32_t lmId, uint32_t stop);
static int32_t LM_ClockStart(uint32_t lmId, uint32_t rsrc, uint32_t numArg,
    const uint64_t *arg);

/*--------------------------------------------------------------------------*/
/* Init LMM system                                                          */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemInit(void)
{
    int32_t status = SM_ERR_SUCCESS;
    lmm_rst_rec_t bootRec, shutdownRec;

    /* Get system reset reason */
    LM_SystemReason(0U, &bootRec, &shutdownRec);

    /* Default for SM LM */
    s_lmBootReason[0] = bootRec;
    s_lmShutdownReason[0] = shutdownRec;

    /* Default for all LM */
    for (uint32_t lmId = 0U; lmId < SM_NUM_LM; lmId++)
    {
        s_lmShutdownReason[lmId] = shutdownRec;
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Set mode select                                                          */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemModeSelSet(uint32_t mSel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check mSel*/
    if (mSel < SM_LM_NUM_MSEL)
    {
        s_modeSel = mSel;
    }
    else
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Return reset reason name                                                 */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemReasonNameGet(uint32_t lmId, uint32_t resetReason,
    string *reasonNameAddr, int32_t *len)
{
    /* Just passthru to board/device */
    return SM_SYSTEMREASONNAMEGET(resetReason, reasonNameAddr, len);
}

/*--------------------------------------------------------------------------*/
/* Complete system reset handling                                           */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemRstComp(lmm_rst_rec_t resetRec)
{
    int32_t status;

    status = LMM_SystemReset(0U, 0U, false, &resetRec);

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Full system shutdown                                                     */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemShutdown(uint32_t lmId, uint32_t agentId,
    bool graceful, const lmm_rst_rec_t *shutdownRec)
{
    int32_t status = SM_ERR_SUCCESS;
    lmm_rpc_trigger_t trigger =
    {
        .rpcInst = 0U,
        .event = LMM_TRIGGER_SYSTEM,
        .parm[0] = LMM_TRIGGER_PARM_SHUTDOWN,
        .parm[1] = agentId,
        .parm[2] = 0U,
        .parm[3] = graceful ? 1U : 0U
    };

    /* Notify LMs via system */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        if (graceful || (lmId != dstLm))
        {
            (void) LMM_RpcNotificationTrigger(dstLm, trigger);
        }
    }

    /* Force shutdown? */
    if (!graceful)
    {
        lmm_rst_rec_t newShutdownRec = *shutdownRec;

        /* Update record */
        if (newShutdownRec.reason == g_swReason.reason)
        {
            newShutdownRec.origin = lmId;
            newShutdownRec.validOrigin = true;
            newShutdownRec.errId = agentId;
            newShutdownRec.validErr = true;
        }

        /* Save reason */
        DEV_SM_SystemShutdownRecSet(newShutdownRec);

        /* Request system shutdown */
        status = SM_SYSTEMSHUTDOWN();
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Full system reset                                                        */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemReset(uint32_t lmId, uint32_t agentId, bool graceful,
    const lmm_rst_rec_t *resetRec)
{
    int32_t status = SM_ERR_SUCCESS;
    lmm_rpc_trigger_t trigger =
    {
        .rpcInst = 0U,
        .event = LMM_TRIGGER_SYSTEM,
        .parm[0] = LMM_TRIGGER_PARM_RESET,
        .parm[1] = agentId,
        .parm[2] = 0U,
        .parm[3] = graceful ? 1U : 0U,
    };

    /* Notify LMs via system */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        if (graceful || (lmId != dstLm))
        {
            (void) LMM_RpcNotificationTrigger(dstLm, trigger);
        }
    }

    /* Force reset? */
    if (!graceful)
    {
        lmm_rst_rec_t newResetRec = *resetRec;

        /* Update record */
        if (newResetRec.reason == g_swReason.reason)
        {
            newResetRec.origin = lmId;
            newResetRec.validOrigin = true;
            newResetRec.errId = agentId;
            newResetRec.validErr = true;
        }

        /* Save reason */
        newResetRec.reset = true;
        DEV_SM_SystemShutdownRecSet(newResetRec);

        /* Request system reset */
        status = SM_SYSTEMRESET();
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Full system suspend                                                      */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemSuspend(uint32_t lmId, uint32_t agentId)
{
    int32_t status = SM_ERR_SUCCESS;
    lmm_rpc_trigger_t trigger =
    {
        .rpcInst = 0U,
        .event = LMM_TRIGGER_SYSTEM,
        .parm[0] = LMM_TRIGGER_PARM_SUSPEND,
        .parm[1] = agentId,
        .parm[2] = 0U,
        .parm[3] = 1U
    };

    /* Notify LMs via system */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        (void) LMM_RpcNotificationTrigger(dstLm, trigger);
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Full system wake                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemWake(uint32_t lmId, uint32_t agentId)
{
    int32_t status = SM_ERR_SUCCESS;
    lmm_rpc_trigger_t trigger =
    {
        .rpcInst = 0U,
        .event = LMM_TRIGGER_SYSTEM,
        .parm[0] = LMM_TRIGGER_PARM_WAKE,
        .parm[1] = agentId,
        .parm[2] = 0U,
        .parm[3] = 1U
    };

    /* Notify LMs via system */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        (void) LMM_RpcNotificationTrigger(dstLm, trigger);
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Return system reset (shutdown/boot) reason                               */
/*--------------------------------------------------------------------------*/
void LM_SystemReason(uint32_t lmId, lmm_rst_rec_t *bootRec,
    lmm_rst_rec_t *shutdownRec)
{
    int32_t status;
    uint32_t flags;

    /* Get system shutdown reason */
    DEV_SM_SystemShutdownRecGet(shutdownRec);

    /* Valid record? */
    if (shutdownRec->valid)
    {
        /* Reset */
        *bootRec = *shutdownRec;
    }
    else
    {
        lmm_rst_rec_t br = DEV_SM_RST_REC_POR;

        /* POR */
        *bootRec = br;
    }

    /* Get BBM status */
    status = SM_BBMGETBOOTSTATUS(&flags);

    /* Update boot record */
    if (status == SM_ERR_SUCCESS)
    {
        if ((flags & (DEV_SM_BBM_BOOT_BUTTON | DEV_SM_BBM_BOOT_ALARM
            | DEV_SM_BBM_BOOT_ROLLOVER)) != 0U)
        {
            lmm_rst_rec_t bbmRec = DEV_SM_RST_REC_BBM;

            *bootRec = bbmRec;
            bootRec->errId = flags;
            bootRec->validErr = true;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Set system power mode                                                    */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemPowerModeSet(uint32_t lmId, uint32_t powerMode)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check LM */
    if (lmId >= SM_NUM_LM)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        static uint32_t s_powerMode[SM_NUM_LM];
        uint32_t newMode = 0U;

        /* Record new power mode */
        s_powerMode[lmId] = powerMode;

        /* Aggregate power mode */
        for (uint32_t lm = 0U; lm < SM_NUM_LM; lm++)
        {
            newMode |= s_powerMode[lm];
        }

        /* Inform device of power mode */
        SM_SYSTEMPOWERMODESET(newMode);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return LM status                                                         */
/*--------------------------------------------------------------------------*/
int32_t LM_SystemLmStatus(uint32_t lmId, uint32_t stateLm, uint32_t *state,
    int32_t *errStatus)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check LM */
    if (stateLm >= SM_NUM_LM)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return info */
        *state = (uint32_t) s_lmState[stateLm];
        *errStatus = s_lmError[stateLm];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Check if an LM can be booted                                             */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemLmCheck(uint32_t bootLm)
{
    int32_t status = SM_ERR_NOT_FOUND;
    uint32_t idx = g_lmmConfig[bootLm].start - 1U;

    /* Loop over start list */
    while ((status != SM_ERR_SUCCESS) && (idx < SM_LM_NUM_START))
    {
        const lmm_start_t *ptr = &s_lmmStart[idx];

        /* End for this LM */
        if (ptr->lmId != bootLm)
        {
            break;
        }

        /* CPU command? */
        if (ptr->ss == LMM_SS_CPU)
        {
            /* Check vector */
            status = LMM_CpuBootCheck(ptr->lmId, ptr->rsrc);
        }

        /* Next entry */
        idx++;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Boot LM                                                                  */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemLmBoot(uint32_t lmId, uint32_t agentId, uint32_t bootLm,
    const lmm_rst_rec_t *bootRec)
{
    lmm_rpc_trigger_t trigger =
    {
        .event = LMM_TRIGGER_SYSTEM,
        .parm[0] = LMM_TRIGGER_PARM_LM_BOOT,
        .parm[1] = agentId,
        .parm[2] = bootLm,
        .parm[3] = lmId
    };

    return LMM_DoBoot(&trigger, bootRec);
}

/*--------------------------------------------------------------------------*/
/* Shutdown LM                                                              */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemLmShutdown(uint32_t lmId, uint32_t agentId,
    uint32_t shutdownLm, bool graceful, const lmm_rst_rec_t *shutdownRec)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check LM */
    if (shutdownLm >= SM_NUM_LM)
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check LM state */
    if ((status == SM_ERR_SUCCESS)
        && (s_lmState[shutdownLm] != LMM_STATE_LM_OFF))
    {
        lmm_rpc_trigger_t trigger =
        {
            .event = LMM_TRIGGER_SYSTEM,
            .parm[0] = LMM_TRIGGER_PARM_LM_SHUTDOWN,
            .parm[1] = agentId,
            .parm[2] = shutdownLm,
            .parm[3] = graceful ? 1U : 0U
        };

        /* Notify LM via system */
        if (graceful || (lmId != shutdownLm))
        {
            (void) LMM_RpcNotificationTrigger(shutdownLm, trigger);
        }

        /* Force shutdown? */
        if (!graceful)
        {
            /* From LM */
            trigger.parm[3] = lmId;

            status = LMM_DoShutdown(&trigger, shutdownRec);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset LM                                                                 */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemLmReset(uint32_t lmId, uint32_t agentId, uint32_t resetLm,
    bool warm, bool graceful, const lmm_rst_rec_t *resetRec)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check LM */
    if (resetLm >= SM_NUM_LM)
    {
        status = SM_ERR_NOT_FOUND;
    }

    if (status == SM_ERR_SUCCESS)
    {
        lmm_rpc_trigger_t trigger =
        {
            .rpcInst = 0U,
            .event = LMM_TRIGGER_SYSTEM,
            .parm[0] = LMM_TRIGGER_PARM_LM_COLD_RESET,
            .parm[1] = agentId,
            .parm[2] = resetLm,
            .parm[3] = graceful ? 1U : 0U
        };

        /* Warm reset? */
        if (warm)
        {
            trigger.parm[0] = LMM_TRIGGER_PARM_LM_WARM_RESET;
        }

        /* Notify LM via system */
        if (graceful || (lmId != resetLm))
        {
            (void) LMM_RpcNotificationTrigger(resetLm, trigger);
        }

        /* Force reset? */
        if (!graceful)
        {
            /* From LM */
            trigger.parm[3] = lmId;

            /* Shutdown LM */
            status = LMM_DoShutdown(&trigger, resetRec);

            /* Boot the LM */
            if (status == SM_ERR_SUCCESS)
            {
                status = LMM_DoBoot(&trigger, resetRec);
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Suspend LM                                                               */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemLmSuspend(uint32_t lmId, uint32_t agentId,
    uint32_t suspendLm)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check LM */
    if (suspendLm >= SM_NUM_LM)
    {
        status = SM_ERR_NOT_FOUND;
    }

    if (status == SM_ERR_SUCCESS)
    {
        lmm_rpc_trigger_t trigger =
        {
            .rpcInst = 0U,
            .event = LMM_TRIGGER_SYSTEM,
            .parm[0] = LMM_TRIGGER_PARM_LM_SUSPEND,
            .parm[1] = agentId,
            .parm[2] = suspendLm,
            .parm[3] = 1U
        };

        /* Notify LM via system */
        (void) LMM_RpcNotificationTrigger(suspendLm, trigger);
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Wake (resume) LM                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_SystemLmWake(uint32_t lmId, uint32_t agentId, uint32_t wakeLm)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check LM */
    if (wakeLm >= SM_NUM_LM)
    {
        status = SM_ERR_NOT_FOUND;
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Send notifications */
        for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
        {
            lmm_rpc_trigger_t trigger =
            {
                .event = LMM_TRIGGER_SYSTEM,
                .parm[0] = LMM_TRIGGER_PARM_LM_WAKE,
                .parm[1] = lmId,
                .parm[2] = wakeLm
            };

            (void) LMM_RpcNotificationTrigger(dstLm, trigger);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return LM reset (shutdown/boot) reason                                   */
/*--------------------------------------------------------------------------*/
int32_t LM_SystemLmReason(uint32_t lmId, uint32_t reasonLm,
    lmm_rst_rec_t *bootRec, lmm_rst_rec_t *shutdownRec)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check LM */
    if (reasonLm >= SM_NUM_LM)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return records */
        *bootRec = s_lmBootReason[reasonLm];
        *shutdownRec = s_lmShutdownReason[reasonLm];
    }

    /* Return status */
    return status;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Do LM Boot                                                               */
/*--------------------------------------------------------------------------*/
static int32_t LMM_DoBoot(lmm_rpc_trigger_t *trigger,
    const lmm_rst_rec_t *bootRec)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t bootLm = trigger->parm[2];

    if (s_lmState[bootLm] == LMM_STATE_LM_OFF)
    {
        /* Start resources */
        if (g_lmmConfig[bootLm].start != 0U)
        {
            status = LM_ProcessStart(bootLm,
                g_lmmConfig[bootLm].start - 1U);
        }

        if (status == SM_ERR_SUCCESS)
        {
            uint32_t agentId = trigger->parm[1];
            uint32_t lmId = trigger->parm[3];

            /* Send notifications */
            trigger->event = LMM_TRIGGER_LM;
            trigger->parm[0] = LMM_TRIGGER_PARM_LM_BOOT;
            for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
            {
                (void) LMM_RpcNotificationTrigger(dstLm, *trigger);
            }

            /* Record state */
            s_lmState[bootLm] = LMM_STATE_LM_ON;

            /* Record boot reason */
            s_lmBootReason[bootLm] = *bootRec;
            if (bootRec->reason == g_swReason.reason)
            {
                s_lmBootReason[bootLm].origin = lmId;
                s_lmBootReason[bootLm].validOrigin = true;
                s_lmBootReason[bootLm].errId = agentId;
                s_lmBootReason[bootLm].validErr = true;
            }
        }

        /* Record status */
        s_lmError[bootLm] = status;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Do LM Shutdown                                                           */
/*--------------------------------------------------------------------------*/
static int32_t LMM_DoShutdown(lmm_rpc_trigger_t *trigger,
    const lmm_rst_rec_t *shutdownRec)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t shutdownLm = trigger->parm[2];

    if (s_lmState[shutdownLm] != LMM_STATE_LM_OFF)
    {
        /* Stop resources */
        if (g_lmmConfig[shutdownLm].stop != 0U)
        {
            status = LM_ProcessStop(shutdownLm,
                g_lmmConfig[shutdownLm].stop - 1U);
        }

        /* Reset the RPC configuration */
        if (status == SM_ERR_SUCCESS)
        {
            status = LMM_RpcReset(shutdownLm);
        }

        if (status == SM_ERR_SUCCESS)
        {
            uint32_t agentId = trigger->parm[1];
            uint32_t lmId = trigger->parm[3];

            /* Notify all LMs via LM */
            trigger->event = LMM_TRIGGER_LM;
            trigger->parm[0] = LMM_TRIGGER_PARM_LM_SHUTDOWN;
            for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
            {
                (void) LMM_RpcNotificationTrigger(dstLm, *trigger);
            }

            /* Record state */
            s_lmState[shutdownLm] = LMM_STATE_LM_OFF;
            s_lmBootReason[shutdownLm].valid = false;

            /* Record shutdown reason */
            s_lmShutdownReason[shutdownLm] = *shutdownRec;
            if (shutdownRec->reason == g_swReason.reason)
            {
                s_lmShutdownReason[shutdownLm].origin = lmId;
                s_lmShutdownReason[shutdownLm].validOrigin = true;
                s_lmShutdownReason[shutdownLm].errId = agentId;
                s_lmShutdownReason[shutdownLm].validErr = true;
            }
        }

        /* Record status */
        s_lmError[shutdownLm] = status;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Process start list                                                       */
/*--------------------------------------------------------------------------*/
static int32_t LM_ProcessStart(uint32_t lmId, uint32_t start)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t idx = start;

    /* Loop over start list */
    while ((status == SM_ERR_SUCCESS) && (idx < SM_LM_NUM_START))
    {
        const lmm_start_t *ptr = &s_lmmStart[idx];

        /* End for this LM? */
        if (ptr->lmId != lmId)
        {
            break;
        }

        /* For this mode? */
        if (ptr->mSel == s_modeSel)
        {
            /* Process start command */
            switch (ptr->ss)
            {
                case LMM_SS_PD:
                    status = LMM_PowerStateSet(ptr->lmId, ptr->rsrc,
                        DEV_SM_POWER_STATE_ON);
                    break;
                case LMM_SS_PERF:
                    status = LMM_PerfLevelSet(ptr->lmId, ptr->rsrc,
                        (uint32_t) ptr->arg[0]);
                    break;
                case LMM_SS_CLK:
                    status = LM_ClockStart(ptr->lmId, ptr->rsrc,
                        ptr->numArg, ptr->arg);
                    break;
                case LMM_SS_CPU:
                    status = LMM_CpuResetVectorReset(ptr->lmId,
                        ptr->rsrc);
                    if (status == SM_ERR_SUCCESS)
                    {
                        status = LMM_CpuStart(ptr->lmId, ptr->rsrc);
                    }
                    break;
                default:
                    status = SM_ERR_NOT_SUPPORTED;
                    break;
            }
        }

        /* Next entry */
        idx++;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Process stop list                                                        */
/*--------------------------------------------------------------------------*/
static int32_t LM_ProcessStop(uint32_t lmId, uint32_t stop)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t idx = stop;
    static const lmm_stop_t s_lmmStop[SM_LM_NUM_STOP] =
    {
        SM_LM_STOP_DATA
    };

    /* Loop over stop list */
    while ((status == SM_ERR_SUCCESS) && (idx < SM_LM_NUM_STOP))
    {
        const lmm_stop_t *ptr = &s_lmmStop[idx];

        /* End for this LM? */
        if (ptr->lmId != lmId)
        {
            break;
        }

        /* For this mode? */
        if (ptr->mSel == s_modeSel)
        {
            /* Process stop command */
            switch (ptr->ss)
            {
                case LMM_SS_PD:
                    status = LMM_PowerStateSet(ptr->lmId, ptr->rsrc,
                        DEV_SM_POWER_STATE_OFF);
                    break;
                case LMM_SS_PERF:
                    status = LMM_PerfLevelSet(ptr->lmId, ptr->rsrc, 0U);
                    break;
                case LMM_SS_CLK:
                    status = LMM_ClockEnable(ptr->lmId, ptr->rsrc, false);
                    break;
                case LMM_SS_CPU:
                    status = LMM_CpuStop(ptr->lmId, ptr->rsrc);
                    break;
                default:
                    status = SM_ERR_NOT_SUPPORTED;
                    break;
            }
        }

        /* Next entry */
        idx++;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Start clock                                                              */
/*--------------------------------------------------------------------------*/
static int32_t LM_ClockStart(uint32_t lmId, uint32_t rsrc, uint32_t numArg,
    const uint64_t *arg)
{
    int32_t status = SM_ERR_SUCCESS;
    uint64_t rate = 0ULL;
    uint32_t parent = SM_NUM_CLOCK;

    /* Evaluate arguments */
    for (uint32_t idx = 0U; idx < numArg; idx++)
    {
        if (arg[idx] < SM_NUM_CLOCK)
        {
            parent = (uint32_t) arg[idx];
        }
        else
        {
            rate = arg[idx];
        }
    }

    /* Turn clock off if we will be changing */
    if ((parent < SM_NUM_CLOCK) || (rate != 0ULL))
    {
        /* Turn off clock */
        status = LMM_ClockEnable(lmId, rsrc, false);
    }

    /* Set parent */
    if ((status == SM_ERR_SUCCESS) && (parent < SM_NUM_CLOCK))
    {
        status = LMM_ClockParentSet(lmId, rsrc, parent);
    }

    /* Set rate */
    if ((status == SM_ERR_SUCCESS) && (rate != 0ULL))
    {
        status = LMM_ClockRateSet(lmId, rsrc, rate,
            DEV_SM_CLOCK_ROUND_DOWN);
    }

    /* Turn on clock */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_ClockEnable(lmId, rsrc, true);
    }

    /* Return status */
    return status;
}

