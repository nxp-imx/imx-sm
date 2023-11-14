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
 * @addtogroup LMM_BBM
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager battery
 * backed module.
 */
/*==========================================================================*/

#ifndef LMM_BBM_H
#define LMM_BBM_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/*!
 * @name LMM BBM trigger parameters
 */
/** @{ */
#define LMM_TRIGGER_PARM_RTC_ALARM     0x0U  /*!< Trigger RTC alarm */
#define LMM_TRIGGER_PARM_RTC_ROLLOVER  0x1U  /*!< Trigger RTC rollover */
#define LMM_TRIGGER_PARM_RTC_UPDATE    0x2U  /*!< Trigger RTC updated */
/** @} */

/* Types */

/* Functions */

/*!
 * Write an LM GPR value.
 *
 * @param[in]     lmId         LM call is for
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
 * - others returned by ::SM_BBMGPRSET
 */
int32_t LMM_BbmGprSet(uint32_t lmId, uint32_t index, uint32_t value);

/*!
 * Read an LM GPR value.
 *
 * @param[in]     lmId     LM call is for
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
 * - others returned by ::SM_BBMGPRGET
 */
int32_t LMM_BbmGprGet(uint32_t lmId, uint32_t index, uint32_t *value);

/*!
 * Get an LM RTC name.
 *
 * @param[in]     lmId         LM call is for
 * @param[in]     rtcId        RTC name to get
 * @param[out]    rtcNameAddr  Return pointer to name
 * @param[out]    len          Return max length of all RTC names
 *
 * This function allows the caller to get the name of an RTC.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the name is returned.
 * - others returned by ::SM_BBMRTCNAMEGET
 */
int32_t LMM_BbmRtcNameGet(uint32_t lmId, uint32_t rtcId, string *rtcNameAddr,
    int32_t *len);

/*!
 * Get an LM RTC description.
 *
 * @param[in]     lmId         LM call is for
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
 * - ::SM_ERR_SUCCESS: if the description is returned.
 * - others returned by ::SM_BBMRTCDESCRIBE
 */
int32_t LMM_BbmRtcDescribe(uint32_t lmId, uint32_t rtcId, uint32_t *secWidth,
    uint32_t *tickWidth, uint32_t *ticksPerSec);

/*!
 * Set an LM RTC time.
 *
 * @param[in]     lmId     LM call is for
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
 * - others returned by ::SM_BBMRTCTIMESET
 */
int32_t LMM_BbmRtcTimeSet(uint32_t lmId, uint32_t rtcId, uint64_t val,
    bool ticks);

/*!
 * Get an LM RTC time.
 *
 * @param[in]     lmId     LM call is for
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
 * - others returned by ::SM_BBMRTCTIMEGET
 */
int32_t LMM_BbmRtcTimeGet(uint32_t lmId, uint32_t rtcId, uint64_t *val,
    bool ticks);

/*!
 * Set an LM RTC alarm.
 *
 * @param[in]     lmId     LM call is for
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
 * - others returned by ::SM_BBMRTCALARMSET
 */
int32_t LMM_BbmRtcAlarmSet(uint32_t lmId, uint32_t rtcId, bool enable,
    uint64_t val);

/*!
 * Enable an LM RTC rollover event.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     rtcId    Identifier of the RTC
 *
 * This function allows a caller to enable/disable an RTC rollover event.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the event was enabled.
 * - others returned by ::SM_BBMRTCROLLOVER
 */
int32_t LMM_BbmRtcRollover(uint32_t lmId, uint32_t rtcId);

/*!
 * Read the LM button state.
 *
 * @param[in]     lmId            LM call is for
 * @param[out]    buttonAsserted  State of the ON/OFF button
 *
 * This function allows a caller to read the ON/OFF button state.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the button status was read.
 * - others returned by ::SM_BBMBUTTONGET
 */
int32_t LMM_BbmButtonGet(uint32_t lmId, bool *buttonAsserted);

/*!
 * Report RTC alarm.
 *
 * This function reports an RTC alarm event to the LMM. The LMM will clear
 * the alarm request for all LM with an alarm at this time. It will then
 * configure the RTC alarm to the nearest remaining LM alarm.
 *
 * @param[in]  rtcId  RTC to report an event for
 */
void LMM_BbmRtcAlarmEvent(uint32_t rtcId);

/*!
 * Report RTC rollover event.
 *
 * This function reports an RTC rollover event to the LMM. The LMM will clear
 * the event request.
 *
 * @param[in]  rtcId  RTC to report an event for
 */
void LMM_BbmRtcRolloverEvent(uint32_t rtcId);

/*!
 * Report RTC update event.
 *
 * This function reports an RTC update event to the LMM.
 *
 * @param[in]  rtcId  RTC to report an event for
 */
void LMM_BbmRtcUpdateEvent(uint32_t rtcId);

/*!
 * Report button event.
 *
 * This function reports a button event to the LMM. The LMM will clear
 * the event request.
 */
void LMM_BbmButtonEvent(void);

#endif /* LMM_BBM_H */

/** @} */

