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

#ifndef DEV_SM_SENSOR_H
#define DEV_SM_SENSOR_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_SIMU_SENSOR
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device sensors.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device sensors */
#define DEV_SM_NUM_SENSOR   3UL

/*!
 * @name Device sensor domain indexes
 */
/** @{ */
#define DEV_SM_SENSOR_0  0U   /*!< Sensor 0 */
#define DEV_SM_SENSOR_1  1U   /*!< Sensor 1 */
#define DEV_SM_SENSOR_2  2U   /*!< Sensor 2 */
/** @} */

/*!
 * @name Device sensor TP events
 */
/** @{ */
#define DEV_SM_SENSOR_TP_NONE     0U  /*!< Disables event generation */
#define DEV_SM_SENSOR_TP_RISING   1U  /*!< Crossed in a positive direction */
#define DEV_SM_SENSOR_TP_FALLING  2U  /*!< Crossed in a negative direction */
#define DEV_SM_SENSOR_TP_BOTH     3U  /*!< Crossed in either direction */
#define DEV_SM_SENSOR_TP_HIGH     4U  /*!< At a higher value */
#define DEV_SM_SENSOR_TP_LOW      5U  /*!< At a lower value */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

#include "dev_sm_sensor_api.h"

#endif /* DEV_SM_SENSOR_H */

