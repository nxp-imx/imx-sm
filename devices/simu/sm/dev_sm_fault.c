/*
** ###################################################################
**
**     Copyright 2023-2024 NXP
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/* File containing the implementation of the device faults.                 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Initialize fault handling                                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_FaultInit(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Complete fault processing                                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_FaultComplete(dev_sm_rst_rec_t resetRec)
{
    return SM_FAULTCOMPLETE(resetRec);
}

/*--------------------------------------------------------------------------*/
/* Get a fault state                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_FaultGet(uint32_t faultId, bool *state)
{
    /* Not asserted */
    *state = false;

    return SM_ERR_SUCCESS;
}

/*--------------------------------------------------------------------------*/
/* Set (trigger) or clear a fault                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_FaultSet(uint32_t lmId, uint32_t faultId, bool set)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check fault */
    if (faultId >= DEV_SM_NUM_FAULT)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }
    else
    {
        if (set)
        {
            dev_sm_rst_rec_t resetRec =
            {
                .valid = true,
                .reason = DEV_SM_REASON_FAULT,
                .errId = faultId,
                .validErr = true,
            };

            /* Update record */
            if (lmId != 0U)
            {
                resetRec.origin = lmId;
                resetRec.validOrigin = true;
            }

            /* Finalize fault flow */
            status = DEV_SM_FaultComplete(resetRec);

            /* Reset if fault handling failed */
            if (status != SM_ERR_SUCCESS)
            {
                /* Finalize system reset flow */
                (void) DEV_SM_SystemRstComp(&resetRec);
            }
        }
    }

    /* Return status */
    return status;
}

