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

#ifndef DEV_SM_PIN_H
#define DEV_SM_PIN_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_SIMU_PIN
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device pins.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device pins */
#define DEV_SM_NUM_PIN    4U
/*! Number of device daisy */
#define DEV_SM_NUM_DAISY  2U

/*!
 * @name Device pin indexes
 */
/** @{ */
#define DEV_SM_PIN_0  0U  /*!< Pin 0 */
#define DEV_SM_PIN_1  1U  /*!< Pin 1 */
#define DEV_SM_PIN_2  2U  /*!< Pin 2 */
#define DEV_SM_PIN_3  3U  /*!< Pin 3 */
/** @} */

/*!
 * @name Device daisy indexes
 */
/** @{ */
#define DEV_SM_DAISY_0  0U  /*!< Daisy 0 */
#define DEV_SM_DAISY_1  1U  /*!< Daisy 1 */
/** @} */

/*!
 * @name Device pin config types
 */
/** @{ */
#define DEV_SM_PIN_TYPE_MUX     0U  /*!< Pin mux */
#define DEV_SM_PIN_TYPE_CONFIG  1U  /*!< Pin config */
#define DEV_SM_PIN_TYPE_DAISY   2U  /*!< Pin daisy */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

// coverity[misra_c_2012_rule_20_1_violation:FALSE]
#include "dev_sm_pin_api.h"

#endif /* DEV_SM_PIN_H */

