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
/* File containing the implementation of the Logical Machine Manager        */
/* FuSa.                                                                    */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* LMM FuSA S-EENV info */
typedef struct
{
    uint32_t state;
} lmm_seenv_info_t;

/* Local variables */

static uint32_t s_feenvState = LMM_FUSA_FEENV_STATE_INIT;
static uint32_t s_mSelMode = 0U;
static lmm_seenv_info_t s_seenvInfo[SM_LM_NUM_SEENV] = { 0U };

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Init LMM FuSa management                                                 */
/*--------------------------------------------------------------------------*/
// coverity[misra_c_2012_rule_8_13_violation:FALSE]
int32_t LMM_FusaInit(uint32_t *mSel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Save mSel Mode */
    s_mSelMode = *mSel;

    /* Call SCST/SAF to check HW state */

    /* Update F-EENV state */
    s_feenvState = LMM_FUSA_FEENV_STATE_PRE_SAFETY;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return number of S-EENV LM                                               */
/*--------------------------------------------------------------------------*/
void LMM_SsenvLmNumGet(uint32_t *num)
{
    /* Init to 0 */
    *num = 0U;

    /* Count S-EENV LM */
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
int32_t LMM_FusaFeenvStateGet(const lmm_fusa_id_t *caller,
    uint32_t *feenvState, uint32_t *mselMode)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return state */
    *feenvState = s_feenvState;
    *mselMode = s_mSelMode;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get S-EENV state                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaSeenvStateGet(const lmm_fusa_id_t *caller,
    const lmm_fusa_id_t *target, uint32_t *seenvState)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check S-EENV ID */
    if (caller->seenvId >= SM_LM_NUM_SEENV)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Get state */
        *seenvState = s_seenvInfo[caller->seenvId].state;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set S-EENV state                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaSeenvStateSet(const lmm_fusa_id_t *caller,
    uint32_t seenvState, uint32_t pingCookie)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check S-EENV ID */
    if (caller->seenvId >= SM_LM_NUM_SEENV)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Save state */
        s_seenvInfo[caller->seenvId].state = LMM_FUSA_SEENV_STATE_INIT;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get fault state                                                          */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaFaultGet(const lmm_fusa_id_t *caller, uint32_t faultId,
    bool *state)
{
    /* Get fault and return */
    return LMM_FaultGet(faultId, state);
}

/*--------------------------------------------------------------------------*/
/* Set fault                                                                */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaFaultSet(const lmm_fusa_id_t *caller, uint32_t faultId,
    bool set)
{
    int32_t status;

    /* Set fault state */
    status = LMM_FaultSet(caller->lmId, faultId, set);

    /* Call was to clear the fault? */
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
                .parm[2] = caller->lmId
            };

            /* Send notification */
            (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Temporarily disable fault handling                                       */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaScheckEvntrig(const lmm_fusa_id_t *caller)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Request S-check                                                          */
/*--------------------------------------------------------------------------*/
int32_t LMM_FusaScheckTestExec(const lmm_fusa_id_t *caller,
    uint32_t targetTestId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Complete fault handling                                                  */
/*--------------------------------------------------------------------------*/
// coverity[misra_c_2012_rule_8_13_violation:FALSE]
int32_t LMM_FusaFaultRecover(uint32_t faultId, uint32_t *reaction,
    // coverity[misra_c_2012_rule_8_13_violation:FALSE]
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

        /* Send notification */
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

        /* Send notification */
        (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
    }
}

/*--------------------------------------------------------------------------*/
/* Report full shutdown/reset                                               */
/*--------------------------------------------------------------------------*/
void LMM_FusaExit(const lmm_rst_rec_t *shutdownRec)
{
}

/*--------------------------------------------------------------------------*/
/* Recover from global error                                                */
/*--------------------------------------------------------------------------*/
void LMM_FusaGlobalRecovery(uint32_t status)
{
    dev_sm_rst_rec_t resetRec =
    {
        .reason = DEV_SM_REASON_FUSA_SRECO,
        .errId = (uint32_t) status,
        .validErr = true,
        .valid = true
    };

    /* Finalize system reset flow */
    (void) DEV_SM_SystemRstComp(&resetRec);
}

/*--------------------------------------------------------------------------*/
/* Report exception                                                         */
/*--------------------------------------------------------------------------*/
void LMM_FuSaExceptionHandler(const dev_sm_rst_rec_t *resetRec)
{
}

/*--------------------------------------------------------------------------*/
/* Report assertion error                                                   */
/*--------------------------------------------------------------------------*/
void LMM_FuSaAssertionFailure(int32_t status)
{
    /* Assert fault */
    (void) LMM_FaultSet(0U, DEV_SM_FAULT_SM_ERR, true);
}

