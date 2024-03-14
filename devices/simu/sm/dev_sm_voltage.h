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

#ifndef DEV_SM_VOLTAGE_H
#define DEV_SM_VOLTAGE_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_SIMU_VOLTAGE
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device voltages.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device voltage domains */
#define DEV_SM_NUM_VOLT       3UL

/*! Number of device voltage modes */
#define DEV_SM_NUM_VOLT_MODE  3U

/*!
 * @name Device voltage domain indexes
 */
/** @{ */
#define DEV_SM_VOLT_0  0U  /*!< Voltage 0 */
#define DEV_SM_VOLT_1  1U  /*!< Voltage 1 */
#define DEV_SM_VOLT_2  2U  /*!< Voltage 2 */
/** @} */

/*!
 * @name Device voltage modes
 */
/** @{ */
#define DEV_SM_VOLT_MODE_OFF   0U  /*!< Off */
#define DEV_SM_VOLT_MODE_STBY  1U  /*!< Standby */
#define DEV_SM_VOLT_MODE_ON    2U  /*!< On */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

// coverity[misra_c_2012_rule_20_1_violation:FALSE]
#include "dev_sm_voltage_api.h"

#endif /* DEV_SM_VOLTAGE_H */

