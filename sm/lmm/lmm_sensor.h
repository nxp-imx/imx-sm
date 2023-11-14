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
 * @addtogroup LMM_SENSOR
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager sensors.
 */
/*==========================================================================*/

#ifndef LMM_SENSOR_H
#define LMM_SENSOR_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Get a sensor name.
 *
 * @param[in]     lmId            LM call is for
 * @param[in]     sensorId        Sensor name to get
 * @param[out]    sensorNameAddr  Return pointer to name
 * @param[out]    len             Return max length of all sensor names
 *
 * This function allows the caller to get the name of a sensor.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the name is returned.
 * - others returned by ::SM_SENSORNAMEGET
 */
int32_t LMM_SensorNameGet(uint32_t lmId, uint32_t sensorId,
    string *sensorNameAddr, int32_t *len);

/*!
 * Get a sensor description.
 *
 * @param[in]     lmId       LM call is for
 * @param[in]     sensorId   Sensor description to get
 * @param[out]    desc       Return pointer to the description
 *
 * This function allows the caller to get the description of a sensor.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the description is returned.
 * - others returned by ::SM_SENSORDESCRIBE
 */
int32_t LMM_SensorDescribe(uint32_t lmId, uint32_t sensorId,
    dev_sm_sensor_desc_t *desc);

/*!
 * Read a sensor.
 *
 * @param[in]     lmId             LM call is for
 * @param[in]     sensorId         Sensor to read
 * @param[out]    sensorValue      Return pointer to sensor value
 * @param[out]    sensorTimestamp  Return pointer to timestamp
 *
 * This function allows the caller to read the value of a sensor.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the value is returned.
 * - others returned by ::SM_SENSORREADINGGET
 */
int32_t LMM_SensorReadingGet(uint32_t lmId, uint32_t sensorId,
    int64_t *sensorValue, uint64_t *sensorTimestamp);

/*!
 * Configure a trip point for a sensor.
 *
 * @param[in]     lmId          LM call is for
 * @param[in]     sensorId      Sensor to configure TP
 * @param[in]     tripPoint     Trip point ID
 * @param[in]     value         Value to trip at
 * @param[in]     eventControl  Event control (notifications)
 *
 * This function allows the caller to configure one of the trip
 * points for a sensor. The caller can also configure which crossing
 * direction will generate a notification.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the sensor TP is configured.
 * - others returned by ::SM_SENSORTRIPPOINTSET
 */
int32_t LMM_SensorTripPointSet(uint32_t lmId, uint32_t sensorId,
    uint8_t tripPoint, int64_t value, uint8_t eventControl);

/*!
 * Enable/disable a sensor.
 *
 * @param[in]     lmId                LM call is for
 * @param[in]     sensorId            Sensor to enable/disable
 * @param[in]     enable              True to enable
 * @param[in]     timestampReporting  True to enable timestamp reporting
 *
 * This function allows the caller to enable/disable a sensor.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the sensor is enabled/disabled.
 * - others returned by ::SM_SENSORENABLE
 */
int32_t LMM_SensorEnable(uint32_t lmId, uint32_t sensorId, bool enable,
    bool timestampReporting);

/*!
 * Get enable/disable state of a sensor.
 *
 * @param[in]     lmId                LM call is for
 * @param[in]     sensorId            Sensor to get state
 * @param[out]    enabled             Return pointer to enable
 * @param[out]    timestampReporting  Return pointer to reporting
 *
 * This function allows the caller to get the enable/disable
 * state of a sensor.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the sensor state is returned.
 * - others returned by ::SM_SENSORISENABLED
 */
int32_t LMM_SensorIsEnabled(uint32_t lmId, uint32_t sensorId,
    bool *enabled, bool *timestampReporting);

/*!
 * Report sensor trip point event.
 *
 * This function reports a sensor event to the LMM.
 *
 * @param[in]  sensorId   Sensor to report an event for
 * @param[in]  tripPoint  Trip point to report an event for
 * @param[in]  dir        Direction of event (1 = rising edge)
 */
void LMM_SensorEvent(uint32_t sensorId, uint8_t tripPoint, uint8_t dir);

#endif /* LMM_SENSOR_H */

/** @} */

