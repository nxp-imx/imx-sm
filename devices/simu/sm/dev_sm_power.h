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

#ifndef DEV_SM_POWER_H
#define DEV_SM_POWER_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_SIMU_POWER
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device power domains.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device power domains */
#define DEV_SM_NUM_POWER        7UL

/*! Number of device power states */
#define DEV_SM_NUM_POWER_STATE  4U

/*!
 * @name Device power domain indexes
 */
/** @{ */
#define DEV_SM_PD_0  0U  /*!< Power domain 0 */
#define DEV_SM_PD_1  1U  /*!< Power domain 1 */
#define DEV_SM_PD_2  2U  /*!< Power domain 2 */
#define DEV_SM_PD_3  3U  /*!< Power domain 3 */
#define DEV_SM_PD_4  4U  /*!< Power domain 4 */
#define DEV_SM_PD_5  5U  /*!< Power domain 5 */
#define DEV_SM_PD_6  6U  /*!< Power domain 6 */
/** @} */

/*!
 * @name Device power domain states
 */
/** @{ */
#define DEV_SM_POWER_STATE_OFF  0U  /*!< Power off */
#define DEV_SM_POWER_STATE_P1   1U  /*!< Power P1 */
#define DEV_SM_POWER_STATE_P2   2U  /*!< Power P2 */
#define DEV_SM_POWER_STATE_ON   3U  /*!< Power on */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

#include "dev_sm_power_api.h"

#endif /* DEV_SM_POWER_H */

