/*
** ###################################################################
**
**     Copyright 2023 NXP
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
/*!
 * @addtogroup DEV_SM_FAULT_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device faults.
 */
/*==========================================================================*/

#ifndef DEV_SM_FAULT_API_H
#define DEV_SM_FAULT_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Initialize the device fault handling.
 *
 * This function initializes the HW like the FCCU.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_FaultInit(void);

/*!
 * Complete a fault.
 *
 * @param[in]     resetRec  Reset record to store
 *
 * Used to report a need for fault handling. Calls ::SM_FAULTCOMPLETE
 * which uses the configured reaction/lm to reset/shutdown the system or
 * an LM. The record is stored for the system or LM.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by ::SM_FAULTCOMPLETE
 */
int32_t DEV_SM_FaultComplete(dev_sm_rst_rec_t resetRec);

/*!
 * Get the configured reaction to a fault.
 *
 * @param[in]     resetRec  Reset record to store
 * @param[out]    reaction  Pointer to return the reaction
 * @param[out]    lm        Pointer to return the LM (if applicable)
 *
 * Obtains the fault reaction. Useful to make decisions about a fault
 * at the device level.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by ::SM_FAULTREACTIONGET
 */
int32_t DEV_SM_FaultReactionGet(dev_sm_rst_rec_t resetRec,
    uint32_t *reaction, uint32_t *lm);

/*!
 * Get the state of a fault.
 *
 * @param[in]     faultId   Fault ID
 * @param[out]    state     Pointer to return the state
 *
 * Obtains the state of a fault.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 */
int32_t DEV_SM_FaultGet(uint32_t faultId, bool *state);

/*!
 * Set the state of a fault.
 *
 * @param[in]     lmId      LM requesting to set the fault
 * @param[in]     faultId   Fault ID
 * @param[out]    set       Pointer to return the state
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by DEV_SM_FaultComplete()
 */
int32_t DEV_SM_FaultSet(uint32_t lmId, uint32_t faultId, bool set);

#endif /* DEV_SM_FAULT_API_H */

/** @} */

