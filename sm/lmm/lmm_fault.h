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
/*!
 * @addtogroup LMM_FAULT
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager faults.
 */
/*==========================================================================*/

#ifndef LMM_FAULT_H
#define LMM_FAULT_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Complete a fault.
 *
 * @param[in]     resetRec  Reset record to store
 *
 * Used to report a need for a reset or shutdown. Uses the configured
 * reaction/lm to reset/shutdown the system or an LM. The record is
 * stored for the system or LM.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by ::SM_SYSTEMRSTCOMP
 */
int32_t LMM_FaultComplete(dev_sm_rst_rec_t resetRec);

/*!
 * Get fault reaction info.
 *
 * @param[in]     resetRec      Reset record
 * @param[in,out] reaction      Fault reaction
 * @param[in,out] lm            Target LM
 *
 * Gets fault reaction info from the LM fault configuration data.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND if \a resetRec.errId is not a valid faultId.
 */
int32_t LMM_FaultReactionGet(dev_sm_rst_rec_t resetRec,
    uint32_t *reaction, uint32_t *lm);

/*!
 * Get fault state.
 *
 * @param[in]     faultId       Fault ID
 * @param[out]    state         State, true if asserted
 *
 * Gets the state of a fault.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by ::SM_FAULTGET
 */
int32_t LMM_FaultGet(uint32_t faultId, bool *state);

/*!
 * Set fault state.
 *
 * @param[in]     lmId          LM requesting
 * @param[in]     faultId       Fault ID
 * @param[in]     set           True to set, false to clear
 *
 * Sets the state of a fault. If \a set is true, will assert the fault
 * if possible. This is the case for SCP SW faults. May be true for
 * faults that can be triggered with fault injection. If \a set is false,
 * will deassert the fault if manually set. Will clear a fault if the
 * state is latched.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by ::SM_FAULTSET
 */
int32_t LMM_FaultSet(uint32_t lmId, uint32_t faultId, bool set);

#endif /* LMM_FAULT_H */

/** @} */

