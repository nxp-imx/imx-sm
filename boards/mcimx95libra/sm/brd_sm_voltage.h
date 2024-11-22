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
 * @addtogroup BRD_SM_MX95EVK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the board voltages.
 */
/*==========================================================================*/

#ifndef BRD_SM_VOLTAGE_H
#define BRD_SM_VOLTAGE_H

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Defines */

/*!
 * @name Board redirection defines
 * @{
 */
#define SM_VOLTAGENAMEGET       BRD_SM_VoltageNameGet   /*!< Voltage name */
#define SM_VOLTAGEDESCRIBE      BRD_SM_VoltageDescribe  /*!< Voltage describe */
#define SM_VOLTAGEMODESET       BRD_SM_VoltageModeSet   /*!< Set voltage mode */
#define SM_VOLTAGEMODEGET       BRD_SM_VoltageModeGet   /*!< Get coltage mode */
#define SM_VOLTAGELEVELSET      BRD_SM_VoltageLevelSet  /*!< Set voltage level */
#define SM_VOLTAGELEVELGET      BRD_SM_VoltageLevelGet  /*!< Get voltage level */
/** @} */

/*! Number of board voltages */
#define BRD_SM_NUM_VOLT  7UL

/*! Total number of sensors */
#define SM_NUM_VOLT  (DEV_SM_NUM_VOLT + BRD_SM_NUM_VOLT)

/*!
 * @name BRD_SM voltage domains
 */
/** @{ */
#define BRD_SM_VOLT_VDD_GPIO_3P3  (DEV_SM_NUM_VOLT + 0U)  /*!< VDD GPIO 3.3v */
#define BRD_SM_VOLT_VDD_ANA_0P8   (DEV_SM_NUM_VOLT + 1U)  /*!< VDD ANA 0.8v */
#define BRD_SM_VOLT_VDD_GPIO_1P8  (DEV_SM_NUM_VOLT + 2U)  /*!< VDD GPIO 1.8v */
#define BRD_SM_VOLT_VDDQ_DDR      (DEV_SM_NUM_VOLT + 3U)  /*!< DDR VDDQ */
#define BRD_SM_VOLT_VDD2_DDR      (DEV_SM_NUM_VOLT + 4U)  /*!< DDR VDD2 */
#define BRD_SM_VOLT_SD_CARD       (DEV_SM_NUM_VOLT + 5U)  /*!< SD1 */
#define BRD_SM_VOLT_NVCC_SD2      (DEV_SM_NUM_VOLT + 6U)  /*!< SD2 */
/** @} */

/* Types */

/* Functions */

/*!
 * Get a board voltage domain name.
 *
 * @param[in]     domainId        Domain name to get
 * @param[out]    voltNameAddr    Return pointer to name
 * @param[out]    len             Return max length of all domain names
 *
 * This function allows the caller to get the name of a voltage domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 */
int32_t BRD_SM_VoltageNameGet(uint32_t domainId, string *voltNameAddr,
    int32_t *len);

/*!
 * Get a board voltage domain description.
 *
 * @param[in]     domainId  Voltage description to get
 * @param[out]    range     Pointer to return range
 *
 * This function allows the caller to get the voltage range for
 * a voltage. The range contains the high, low, and step voltage
 * in microvolts (uV).
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 */
int32_t BRD_SM_VoltageDescribe(uint32_t domainId,
    dev_sm_voltage_range_t *range);

/*!
 * Set a board voltage mode.
 *
 * @param[in]     domainId      Identifier for the voltage domain
 * @param[in]     voltMode      Voltage mode to set
 *
 * This function allows the caller to set the current mode of
 * a voltage domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 */
int32_t BRD_SM_VoltageModeSet(uint32_t domainId, uint8_t voltMode);

/*!
 * Get a board voltage mode.
 *
 * @param[in]     domainId      Identifier for the voltage domain
 * @param[out]    voltMode      Pointer to return the voltage mode
 *
 * This function allows the caller to request the current mode of
 * a voltage domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 */
int32_t BRD_SM_VoltageModeGet(uint32_t domainId, uint8_t *voltMode);

/*!
 * Set a board voltage level.
 *
 * @param[in]     domainId      Identifier for the voltage domain
 * @param[in]     voltageLevel  Voltage level to set
 *
 * This function allows the caller to set the current level of
 * a voltage domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 * - ::SM_ERR_INVALID_PARAMETERS: if \a voltageLevel is negative.
 * - other from BRD_SM_SupplyLevelSet()
 */
int32_t BRD_SM_VoltageLevelSet(uint32_t domainId, int32_t voltageLevel);

/*!
 * Get a board voltage level.
 *
 * @param[in]     domainId      Identifier for the voltage domain
 * @param[out]    voltageLevel  Pointer to return the voltage level
 *
 * This function allows the caller to request the current level of
 * a voltage domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 * - other from BRD_SM_SupplyLevelGet()
 */
int32_t BRD_SM_VoltageLevelGet(uint32_t domainId, int32_t *voltageLevel);

/*!
 * Restore voltage levels.
 *
 * This function writes the last set voltage levels back to the PMICs.
 */
void BRD_SM_VoltageRestore(void);

#endif /* BRD_SM_VOLTAGE_H */

/** @} */

