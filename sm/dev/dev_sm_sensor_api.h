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
 * @addtogroup DEV_SM_SENSOR_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device sensors.
 */
/*==========================================================================*/

#ifndef DEV_SM_SENSOR_API_H
#define DEV_SM_SENSOR_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/*! Device sensor description structure */
typedef struct
{
    /*! Type of sensor */
    uint8_t sensorType;
    /*! Sensor reading power-of-10 multiplier */
    int8_t sensorExponent;
    /*! Number of trip points */
    uint8_t numTripPoints;
    /*! Time stamp support */
    bool timestampSupport;
    /*! Timestamp power-of-10 multiplier */
    int8_t timestampExponent;
} dev_sm_sensor_desc_t;

/* Functions */

/*!
 * Initialize sensors.
 *
 * This function initializes the sensors.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_SensorInit(void);

/*!
 * Configure and start a sensor.
 *
 * @param[in]     sensorId        Sensor to power on
 *
 * This function initializes the sensor. It is used after the power
 * domain containing the sensor is turned on.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_SensorConfigStart(uint32_t sensorId);

/*!
 * Enable and start a sensor.
 *
 * @param[in]     sensorId        Sensor to power off
 *
 * This function enables and starts a sensor a sensor. The sensor
 * must already be configured using DEV_SM_SensorConfigStart().
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_SensorPowerUp(uint32_t sensorId);

/*!
 * Stop and disable a sensor.
 *
 * @param[in]     sensorId        Sensor to power off
 *
 * This function stops and disables a sensor to save power.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_SensorPowerDown(uint32_t sensorId);

/*!
 * Get a sensor name.
 *
 * @param[in]     sensorId        Sensor name to get
 * @param[out]    sensorNameAddr  Return pointer to name
 * @param[out]    len             Return max length of all sensor names
 *
 * This function allows the caller to get the name of a sensor.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a sensorId is invalid.
 */
int32_t DEV_SM_SensorNameGet(uint32_t sensorId, string *sensorNameAddr,
    int32_t *len);

/*!
 * Get a device sensor description.
 *
 * @param[in]     sensorId   Sensor description to get
 * @param[out]    desc       Return pointer to the description
 *
 * This function allows the caller to get the description of a sensor.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a sensorId is invalid.
 */
int32_t DEV_SM_SensorDescribe(uint32_t sensorId,
    dev_sm_sensor_desc_t *desc);

/*!
 * Read a device sensor.
 *
 * @param[in]     sensorId         Sensor to read
 * @param[out]    sensorValue      Return pointer to sensor value
 * @param[out]    sensorTimestamp  Return pointer to timestamp
 *
 * This function allows the caller to read the value of a sensor.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a sensorId is invalid.
 */
int32_t DEV_SM_SensorReadingGet(uint32_t sensorId, int64_t *sensorValue,
    uint64_t *sensorTimestamp);

/*!
 * Configure a trip point for a device sensor.
 *
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
 * - ::SM_ERR_NOT_FOUND: if \a sensorId is invalid.
 */
int32_t DEV_SM_SensorTripPointSet(uint32_t sensorId, uint8_t tripPoint,
    int64_t value, uint8_t eventControl);

/*!
 * Enable/disable a device sensor.
 *
 * @param[in]     sensorId            Sensor to enable/disable
 * @param[in]     enable              True to enable
 * @param[in]     timestampReporting  True to enable timestamp reporting
 *
 * This function allows the caller to enable/disable a sensor.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a sensorId is invalid.
 */
int32_t DEV_SM_SensorEnable(uint32_t sensorId, bool enable,
    bool timestampReporting);

/*!
 * Get enable/disable state of a device sensor.
 *
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
 * - ::SM_ERR_NOT_FOUND: if \a sensorId is invalid.
 */
int32_t DEV_SM_SensorIsEnabled(uint32_t sensorId, bool *enabled,
    bool *timestampReporting);

/*!
 * Report a temp sensor interrupt.
 *
 * @param[in]     idx         Sensor interrupt from
 * @param[in]     threshold   Threshold interrupt from
 *
 * This function allows the interrupt handlers to report interrupts
 * from the temp sensor.
 */
void DEV_SM_SensorHandler(uint32_t idx, uint8_t threshold);

#endif /* DEV_SM_SENSOR_API_H */

/** @} */

