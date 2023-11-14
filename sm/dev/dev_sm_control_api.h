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
 * @addtogroup DEV_SM_CTRL_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device controls.
 */
/*==========================================================================*/

#ifndef DEV_SM_CONTROL_API_H
#define DEV_SM_CONTROL_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Set a device control value.
 *
 * @param[in]     ctrlId   Index of control to write
 * @param[in]     numVal   Number of array elements
 * @param[in]     val      Pointer to array of values to set
 *
 * This function allows a caller to write an array of values for
 * a control.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if ctrlId is not valid.
 */
int32_t DEV_SM_ControlSet(uint32_t ctrlId, uint32_t numVal,
    const uint32_t *val);

/*!
 * Get a device control value.
 *
 * @param[in]     ctrlId   Index of control to read
 * @param[out]    numRtn   Return pointer to number of array elements
 * @param[out]    rtn      Pointer to array to store return
 *
 * This function allows a caller to read an array of values for
 * a control.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if ctrlId is not valid.
 */
int32_t DEV_SM_ControlGet(uint32_t ctrlId, uint32_t *numRtn, uint32_t *rtn);

/*!
 * Perform action on a device control.
 *
 * @param[in]     ctrlId   Index of control to take action
 * @param[in]     action   Action to take
 * @param[in]     numArg   Number of argument array elements
 * @param[in]     arg      Pointer to array of argument values
 * @param[out]    numRtn   Return pointer to number of array elements
 * @param[out]    rtn      Pointer to array to store return
 *
 * This function allows a caller to perform an action on a control. The
 * actions are device and control specific.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if ctrlId is not valid.
 */
int32_t DEV_SM_ControlAction(uint32_t ctrlId, uint32_t action,
    uint32_t numArg, const uint32_t *arg, uint32_t *numRtn, uint32_t *rtn);

/*!
 * Configure notification flags for a control.
 *
 * @param[in]     ctrlId   Index of control to take action
 * @param[in]     flags    Action to take
 *
 * This function allows a caller to configure the notification flags.
 * These often enable/disable hardware interrupts.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if ctrlId is not valid.
 */
int32_t DEV_SM_ControlFlagsSet(uint32_t ctrlId, uint32_t flags);

#endif /* DEV_SM_CONTROL_API_H */

/** @} */

