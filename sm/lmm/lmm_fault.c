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
/* faults.                                                                  */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Complete fault handling                                                  */
/*--------------------------------------------------------------------------*/
int32_t LMM_FaultComplete(dev_sm_rst_rec_t resetRec)
{
    int32_t status;
    uint32_t reaction = LMM_REACT_SYS_RESET;
    uint32_t lm = 0U;

    /* Get fault reaction */
    status = LMM_FaultReactionGet(resetRec, &reaction, &lm);

#ifdef USES_FUSA
    /* Let FuSa handle */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_FusaFaultRecover(resetRec.errId, &reaction, &lm);
    }
#endif

    /* Do reaction */
    if (status == SM_ERR_SUCCESS)
    {
        switch(reaction)
        {
            case LMM_REACT_SYS_RESET:
                status = LMM_SystemReset(0U, 0U, false, &resetRec);
                break;
            case LMM_REACT_SYS_SHUTDOWN:
                status = LMM_SystemShutdown(0U, 0U, false, &resetRec);
                break;
            case LMM_REACT_LM_RESET:
                status = LMM_SystemLmReset(0U, 0U, lm, false, false,
                    &resetRec);
                break;
            case LMM_REACT_LM_SHUTDOWN:
                status = LMM_SystemLmShutdown(0U, 0U, lm, false,
                    &resetRec);
                break;
            case LMM_REACT_BOARD:
                status = BRD_SM_CustomFault(resetRec, lm);
                break;
            case LMM_REACT_FUSA:
                /* Return error to cause FCCU to leave pending */
                status = SM_ERR_GENERIC_ERROR;
                break;
            case LMM_REACT_NONE:
                ; /* Intentional empty case */
                break;
            default:
                status = SM_ERR_INVALID_PARAMETERS;
                break;
        }
    }

#ifdef USES_FUSA
    /* Let FuSa know cleared */
    if (status == SM_ERR_SUCCESS)
    {
        LMM_FusaFaultCleared(resetRec.errId);
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get fault reaction                                                       */
/*--------------------------------------------------------------------------*/
int32_t LMM_FaultReactionGet(dev_sm_rst_rec_t resetRec,
    uint32_t *reaction, uint32_t *lm)
{
    int32_t status = SM_ERR_SUCCESS;
    static const lmm_fault_t s_lmmfault[SM_NUM_FAULT] =
    {
        SM_LM_FAULT_DATA
    };

    /* Check fault */
    if (resetRec.errId >= SM_NUM_FAULT)
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get fault reaction */
    if (status == SM_ERR_SUCCESS)
    {
        *reaction = s_lmmfault[resetRec.errId].reaction;
        *lm = s_lmmfault[resetRec.errId].lm;

        /* Allow board to log or change reaction */
        status = BRD_SM_FaultReactionGet(resetRec, reaction, lm);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get fault state                                                          */
/*--------------------------------------------------------------------------*/
int32_t LMM_FaultGet(uint32_t faultId, bool *state)
{
    return SM_FAULTGET(faultId, state);
}

/*--------------------------------------------------------------------------*/
/* Assert/clear a fault                                                     */
/*--------------------------------------------------------------------------*/
int32_t LMM_FaultSet(uint32_t lmId, uint32_t faultId, bool set)
{
    return SM_FAULTSET(lmId, faultId, set);
}

