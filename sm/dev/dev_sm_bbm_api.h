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
/*!
 * @addtogroup DEV_SM_BBM_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device battery-backed module.
 */
/*==========================================================================*/

#ifndef DEV_SM_BBM_API_H
#define DEV_SM_BBM_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Initialize the BBM. Does not clear the status flags.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the BBM was initialized successfully.
 */
int32_t DEV_SM_BbmInit(void);

/*!
 * Clear the BBM status flags.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the BBM was cleared successfully.
 */
int32_t DEV_SM_BbmClear(void);

/*!
 * Read BBM boot status flags.
 *
 * @param[out]  flags    mask of boot status flags
 *
 * This function allows a caller to read the BBM status flags captured
 * at boot.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the BBM boot status was successfully read.
 * - ::SM_ERR_NOT_FOUND: if the BBM captured no boot status.
 */
int32_t DEV_SM_BbmGetBootStatus(uint32_t *flags);

/*!
 * Write a device GPR value.
 *
 * @param[in]     index    Index of GPR to write
 * @param[in]     value    32-bit value to write to the GPR
 *
 * This function allows a caller to write to persistent storage, a general
 * purpose register (GPR).
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the GPR was successfully written.
 * - ::SM_ERR_NOT_FOUND: if the index is not valid.
 */
int32_t DEV_SM_BbmGprSet(uint32_t index, uint32_t value);

/*!
 * Read a device GPR value.
 *
 * @param[in]     index    Index of GPR to read
 * @param[out]    value    32-bit value read from the GPR
 *
 * This function allows a caller to read from persistent storage, a general
 * purpose register (GPR).
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the GPR was successfully read.
 * - ::SM_ERR_NOT_FOUND: if the index is not valid.
 */
int32_t DEV_SM_BbmGprGet(uint32_t index, uint32_t *value);

/*!
 * Get a device RTC name.
 *
 * @param[in]     rtcId        RTC name to get
 * @param[out]    rtcNameAddr  Return pointer to name
 * @param[out]    len          Return max length of all RTC names
 *
 * This function allows the caller to get the name of an RTC.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a rtcId is invalid.
 */
int32_t DEV_SM_BbmRtcNameGet(uint32_t rtcId, string *rtcNameAddr,
    int32_t *len);

/*!
 * Get a device RTC description.
 *
 * @param[in]     rtcId        RTC description to get
 * @param[out]    secWidth     Return pointer to seconds width
 * @param[out]    tickWidth    Return pointer to tick width
 * @param[out]    ticksPerSec  Return pointer to ticks per second
 *
 * This function allows the caller to get the description of an RTC.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a rtcId is invalid.
 */
int32_t DEV_SM_BbmRtcDescribe(uint32_t rtcId, uint32_t *secWidth,
    uint32_t *tickWidth, uint32_t *ticksPerSec);

/*!
 * Set a device RTC time.
 *
 * @param[in]     rtcId    Identifier of the RTC
 * @param[in]     val      Time in seconds/ticks to write to the RTC
 * @param[in]     ticks    true = ticks, false = seconds
 *
 * This function allows a caller to set the RTC time. Time can be set in units
 * of ticks or seconds.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the RTC time was successfully set.
 * - ::SM_ERR_NOT_FOUND: if \a rtcId pertains to a non-existent RTC.
 * - ::SM_ERR_INVALID_PARAMETERS: if the time is not valid (beyond the
 *   range of the RTC).
 */
int32_t DEV_SM_BbmRtcTimeSet(uint32_t rtcId, uint64_t val, bool ticks);

/*!
 * Get a device RTC time.
 *
 * @param[in]     rtcId    Identifier of the RTC
 * @param[out]    val      Time in seconds/ticks read from the RTC
 * @param[in]     ticks    true = ticks, false = seconds
 *
 * This function allows a caller to read the RTC time. Time can be read in
 * units of ticks or seconds.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the RTC time was successfully read.
 * - ::SM_ERR_NOT_FOUND: if \a rtcId pertains to a non-existent RTC.
 */
int32_t DEV_SM_BbmRtcTimeGet(uint32_t rtcId, uint64_t *val, bool ticks);

/*!
 * Get a device RTC state.
 *
 * @param[in]     rtcId    Identifier of the RTC
 * @param[out]    state    Bit mask of state flags
 *
 * This function allows a caller to read the RTC state.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the RTC state was successfully read.
 * - ::SM_ERR_NOT_FOUND: if \a rtcId pertains to a non-existent RTC.
 */
int32_t DEV_SM_BbmRtcStateGet(uint32_t rtcId, uint32_t *state);

/*!
 * Set a device RTC alarm.
 *
 * @param[in]     rtcId    Identifier of the RTC
 * @param[in]     enable   Enable flag (1=enabled, 0=disabled)
 * @param[in]     val      Alarm time in seconds to write to the RTC
 *
 * This function allows a caller to enable/disable and set the time for the RTC
 * alarm. The alarm can be set in seconds only.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the alarm was successfully set.
 * - ::SM_ERR_NOT_FOUND: if \a rtcId pertains to a non-existent RTC.
 * - ::SM_ERR_INVALID_PARAMETERS: if the time is not valid (beyond the
 *   range of the RTC alarm).
 */
int32_t DEV_SM_BbmRtcAlarmSet(uint32_t rtcId, bool enable, uint64_t val);

/*!
 * Enable a device RTC rollover event.
 *
 * @param[in]     rtcId    Identifier of the RTC
 *
 * This function allows a caller to enable/disable an RTC rollover event.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the event was enabled.
 * - ::SM_ERR_NOT_FOUND: if \a rtcId pertains to a non-existent RTC.
 */
int32_t DEV_SM_BbmRtcRollover(uint32_t rtcId);

/*!
 * Read the device button state.
 *
 * @param[out]  buttonAsserted  State of the ON/OFF button
 *
 * This function allows a caller to read the ON/OFF button state.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the button status was read.
 */
int32_t DEV_SM_BbmButtonGet(bool *buttonAsserted);

/*!
 * Handle BBM interrupt.
 *
 * This function reads the BBNSM interrupt status, dispatches handlers,
 * and clears the pending conditions.
 */
void DEV_SM_BbmHandler(void);

#endif /* DEV_SM_BBM_API_H */

/** @} */

