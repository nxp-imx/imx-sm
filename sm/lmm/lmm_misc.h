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
/*!
 * @addtogroup LMM_MISC
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager misc.
 */
/*==========================================================================*/

#ifndef LMM_MISC_H
#define LMM_MISC_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/*! SCMI Control ID Flags */
#define LMM_CTRL_FLAG_BRD  0x8000U

/* Types */

/* Functions */

/*!
 * Set an LM control value.
 *
 * @param[in]     lmId     LM call is for
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
 * - ::SM_ERR_SUCCESS: if the value is set.
 * - others returned by ::SM_CONTROLSET
 */
int32_t LMM_MiscControlSet(uint32_t lmId, uint32_t ctrlId, uint32_t numVal,
    const uint32_t *val);

/*!
 * Get an LM control value.
 *
 * @param[in]     lmId     LM call is for
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
 * - ::SM_ERR_SUCCESS: if the value returned.
 * - others returned by ::SM_CONTROLGET
 */
int32_t LMM_MiscControlGet(uint32_t lmId, uint32_t ctrlId, uint32_t *numRtn,
    uint32_t *rtn);

/*!
 * Set an extended LM control value.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     ctrlId   Index of control to write
 * @param[in]     addr     Address of write
 * @param[in]     numVal   Number of array elements
 * @param[in]     val      Pointer to array of values to set
 *
 * This function allows a caller to write an array of values for
 * a control. Extra parameters allow this write to be more complex
 * such as to an I2C.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the value is set.
 * - others returned by ::SM_CONTROLEXTSET
 */
int32_t LMM_MiscControlExtSet(uint32_t lmId, uint32_t ctrlId, uint32_t addr,
    uint32_t numVal, const uint32_t *val);

/*!
 * Get an extended LM control value.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     ctrlId   Index of control to read
 * @param[in]     addr     Address of read
 * @param[in]     numRtn   Number of array elements
 * @param[out]    rtn      Pointer to array to store return
 *
 * This function allows a caller to read an array of values for
 * a control. Extra parameters allow this read to be more complex
 * such as from an I2C.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the value returned.
 * - others returned by ::SM_CONTROLEXTGET
 */
int32_t LMM_MiscControlExtGet(uint32_t lmId, uint32_t ctrlId, uint32_t addr,
    uint32_t numRtn, uint32_t *rtn);

/*!
 * Perform action on an LM control.
 *
 * @param[in]     lmId     LM call is for
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
 * - ::SM_ERR_SUCCESS: if the action completed.
 * - others returned by ::SM_CONTROLACTION
 */
int32_t LMM_MiscControlAction(uint32_t lmId, uint32_t ctrlId,
    uint32_t action, uint32_t numArg, const uint32_t *arg, uint32_t *numRtn,
    uint32_t *rtn);

/*!
 * Configure notification flags for a control.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     ctrlId   Index of control to take action
 * @param[in]     flags    Action to take
 *
 * This function allows a caller to configure the notification flags.
 * These often enable/disable hardware interrupts.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the flags are set.
 * - others returned by ::SM_CONTROLACTION
 */
int32_t LMM_MiscControlFlagsSet(uint32_t lmId, uint32_t ctrlId,
    uint32_t flags);

/*!
 * Get passover data from ROM.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     passover Pointer to return passover pointer
 *
 * This function allows a caller to obtain a pointer to the ROM
 * passover data.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if pointer is returned.
 * - others returned by ::SM_ROMPASSOVERGET
 */
int32_t LMM_MiscRomPassoverGet(uint32_t lmId,
    const rom_passover_t **passover);

/*!
 * Report control event.
 *
 * This function reports a control event to the LMM.
 *
 * @param[in]  ctrlId     Control to report an event for
 * @param[in]  flags      Flags for event type
 */
void LMM_MiscControlEvent(uint32_t ctrlId, uint32_t flags);

#endif /* LMM_MISC_H */

/** @} */

