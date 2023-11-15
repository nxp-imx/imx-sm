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
 * @addtogroup DEV_SM_MX95_BBM
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device battery-backed module.
 */
/*==========================================================================*/

#ifndef DEV_SM_BBM_H
#define DEV_SM_BBM_H

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device GPR */
#define DEV_SM_NUM_GPR     8UL
/*! Number of device RTC */
#define DEV_SM_NUM_RTC     1UL
/*! Number of device buttons */
#define DEV_SM_NUM_BUTTON  1UL

/*!
 * @name Device bbm gpr indexes
 */
/** @{ */
#define DEV_SM_GPR_0  0U  /*!< GPR 0 */
#define DEV_SM_GPR_1  1U  /*!< GPR 1 */
#define DEV_SM_GPR_2  2U  /*!< GPR 2 */
#define DEV_SM_GPR_3  3U  /*!< GPR 3 */
#define DEV_SM_GPR_4  4U  /*!< GPR 4 */
#define DEV_SM_GPR_5  5U  /*!< GPR 5 */
#define DEV_SM_GPR_6  6U  /*!< GPR 6 */
#define DEV_SM_GPR_7  7U  /*!< GPR 7 */
/** @} */

/*!
 * @name Device bbm rtc indexes
 */
/** @{ */
#define DEV_SM_RTC_BBM  0U  /*!< BBM RTC */
/** @} */

/*!
 * @name Device bbm button indexes
 */
/** @{ */
#define DEV_SM_BUTTON_0  0U  /*!< BBM button */
/** @} */

/*!
 * @name Device bbm boot status flags
 *
 * Flags captured at boot indicating BBM status. Most are conditions that
 * caused the system to power on except ::DEV_SM_BBM_BOOT_OFF which
 * indicates the BBM requested power off. These flags are not mutually
 * exclusive. Returned by DEV_SM_BbmGetBootStatus().
 */
/** @{ */
#define DEV_SM_BBM_BOOT_OFF       BIT32(0U)  /*!< Self powered off */
#define DEV_SM_BBM_BOOT_BUTTON    BIT32(1U)  /*!< Button power on */
#define DEV_SM_BBM_BOOT_ALARM     BIT32(2U)  /*!< RTC alarm powered on */
#define DEV_SM_BBM_BOOT_ROLLOVER  BIT32(3U)  /*!< RTC rollover powered on */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

#include "dev_sm_bbm_api.h"

#endif /* DEV_SM_BBM_H */

