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
/* misc.                                                                    */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Set a control value                                                      */
/*--------------------------------------------------------------------------*/
int32_t LMM_MiscControlSet(uint32_t lmId, uint32_t ctrlId, uint32_t numVal,
    const uint32_t *val)
{
    /* Just passthru to board/device */
    return SM_CONTROLSET(ctrlId, numVal, val);
}

/*--------------------------------------------------------------------------*/
/* Get a control value                                                      */
/*--------------------------------------------------------------------------*/
int32_t LMM_MiscControlGet(uint32_t lmId, uint32_t ctrlId, uint32_t *numRtn,
    uint32_t *rtn)
{
    /* Just passthru to board/device */
    return SM_CONTROLGET(ctrlId, numRtn, rtn);
}

/*--------------------------------------------------------------------------*/
/* Do a control action                                                      */
/*--------------------------------------------------------------------------*/
int32_t LMM_MiscControlAction(uint32_t lmId, uint32_t ctrlId,
    uint32_t action, uint32_t numArg, const uint32_t *arg, uint32_t *numRtn,
    uint32_t *rtn)
{
    /* Just passthru to board/device */
    return SM_CONTROLACTION(ctrlId, action, numArg, arg, numRtn, rtn);
}

/*--------------------------------------------------------------------------*/
/* Update control notification flags                                        */
/*--------------------------------------------------------------------------*/
int32_t LMM_MiscControlFlagsSet(uint32_t lmId, uint32_t ctrlId,
    uint32_t flags)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check parameters */
    if (lmId >= SM_NUM_LM)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Check parameters */
    if ((status == SM_ERR_SUCCESS) && (ctrlId >= SM_NUM_CTRL))
    {
        status = SM_ERR_NOT_FOUND;
    }

    if (status == SM_ERR_SUCCESS)
    {
        static uint32_t s_ctrlNotify[SM_NUM_CTRL][SM_NUM_LM];
        uint32_t newFlags = 0U;

        /* Record new state */
        s_ctrlNotify[ctrlId][lmId] = flags;

        /* Aggregate power state */
        for (uint32_t lm = 0U; lm < SM_NUM_LM; lm++)
        {
            newFlags |= s_ctrlNotify[ctrlId][lm];
        }

        /* Inform device of notify flags, device will check if changed */
        status = SM_CONTROLFLAGSSET(ctrlId, newFlags);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return passover data                                                     */
/*--------------------------------------------------------------------------*/
int32_t LMM_MiscRomPassoverGet(uint32_t lmId,
    const rom_passover_t **passover)
{
    /* Just passthru to board/device */
    return SM_ROMPASSOVERGET(passover);
}

/*--------------------------------------------------------------------------*/
/* Report control event                                                     */
/*--------------------------------------------------------------------------*/
void LMM_MiscControlEvent(uint32_t ctrlId, uint32_t flags)
{
    /* Dispatch for all LM */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        lmm_rpc_trigger_t trigger =
        {
            .event = LMM_TRIGGER_CTRL,
            .parm[0] = ctrlId,
            .parm[1] = flags
        };

        (void) LMM_RpcNotificationTrigger(dstLm, trigger);
    }
}

