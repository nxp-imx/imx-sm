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
#include "eMcem.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Initialize fault handling                                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_FaultInit(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Init FCCU */
    if (eMcem_Init(&eMcem_Config) != (Std_ReturnType) E_OK)
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Complete fault processing                                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_FaultComplete(dev_sm_rst_rec_t resetRec)
{
    int32_t status;

    /* Call handler */
    status = SM_FAULTCOMPLETE(resetRec);

    /* Stop taking faults on error */
    if (status != SM_ERR_SUCCESS)
    {
        /* Disable FCCU interrupts if not recovered - allows
           delayed recovery via clear with DEV_SM_FaultSet() */
        NVIC_DisableIRQ(FCCU0_IRQn);
        NVIC_DisableIRQ(FCCU1_IRQn);
        NVIC_DisableIRQ(FCCU2_IRQn);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get fault reaction info                                                  */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_FaultReactionGet(dev_sm_rst_rec_t resetRec,
    uint32_t *reaction, uint32_t *lm)
{
    return SM_FAULTREACTIONGET(resetRec, reaction, lm);
}

/*--------------------------------------------------------------------------*/
/* Get a fault state                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_FaultGet(uint32_t faultId, bool *state)
{
    int32_t status = SM_ERR_SUCCESS;
    eMcem_FaultContainerType errorContainer = {};

    /* Get fault errors */
    if (eMcem_GetErrorsStatus(&errorContainer) != (Std_ReturnType) E_OK)
    {
        status = SM_ERR_HARDWARE_ERROR;
    }
    else
    {
        /* Get fault status */
        *state = (eMcem_FaultPending(&errorContainer,
            (eMcem_FaultType) faultId) != 0U);
    }

    /* Not asserted */
    *state = false;

    return status;
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
            /* Skip M7 SW faults as can't access */
            if ((faultId < DEV_SM_FAULT_SW6)
                || (faultId > DEV_SM_FAULT_SW11))
            {
                /* Assert fault */
                if (eMcem_AssertSWFault((eMcem_FaultType) faultId)
                    != (Std_ReturnType) E_OK)
                {
                    status = SM_ERR_HARDWARE_ERROR;
                }
            }
            else
            {
                status = SM_ERR_INVALID_PARAMETERS;
            }
        }
        else
        {
            /* Skip M7 SW faults as can't access */
            if ((faultId < DEV_SM_FAULT_SW6)
                || (faultId > DEV_SM_FAULT_SW11))
            {
                /* Negate fault */
                if (eMcem_DeassertSWFault((eMcem_FaultType) faultId)
                    != (Std_ReturnType) E_OK)
                {
                    status = SM_ERR_HARDWARE_ERROR;
                }
            }

            if (status == SM_ERR_SUCCESS)
            {
                /* Clear latched fault condition */
                if (eMcem_ClearFaults((eMcem_FaultType) faultId)
                    != (Std_ReturnType) E_OK)
                {
                    status = SM_ERR_HARDWARE_ERROR;
                }
                else
                {
                    /* Re-enable FCCU interrupts */
                    NVIC_EnableIRQ(FCCU0_IRQn);
                    NVIC_EnableIRQ(FCCU1_IRQn);
                    NVIC_EnableIRQ(FCCU2_IRQn);
                }
            }
        }
    }

    /* Return status */
    return status;
}

