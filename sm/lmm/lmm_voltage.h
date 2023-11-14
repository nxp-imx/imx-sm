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
 * @addtogroup LMM_VOLTAGE
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager voltages.
 */
/*==========================================================================*/

#ifndef LMM_VOLTAGE_H
#define LMM_VOLTAGE_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Init LM voltage management.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: initialized successfully.
 */
int32_t LMM_VoltageInit(void);

/*!
 * Get a voltage domain name.
 *
 * @param[in]     lmId            LM call is for
 * @param[in]     domainId        Domain name to get
 * @param[out]    voltNameAddr    Return pointer to name
 * @param[out]    len             Return max length of all domain names
 *
 * This function allows the caller to get the name of a voltage domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the name is returned.
 * - others returned by ::SM_VOLTAGENAMEGET
 */
int32_t LMM_VoltageNameGet(uint32_t lmId, uint32_t domainId,
    string *voltNameAddr, int32_t *len);

/*!
 * Get a voltage mode name.
 *
 * @param[in]     lmId          LM call is for
 * @param[in]     voltMode      Mode name to get
 * @param[out]    modeNameAddr  Return pointer to name
 * @param[out]    len           Return max length of all mode names
 *
 * This function allows the caller to get the name of a voltage mode.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the name is returned.
 * - others returned by ::SM_VOLTAGEMODENAMEGET
 */
int32_t LMM_VoltageModeNameGet(uint32_t lmId, uint32_t voltMode,
    string *modeNameAddr, int32_t *len);

/*!
 * Get an LM voltage domain description.
 *
 * @param[in]     lmId      LM call is for
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
 * - ::SM_ERR_SUCCESS: if the range is returned.
 * - others returned by ::SM_VOLTAGEDESCRIBE
 */
int32_t LMM_VoltageDescribe(uint32_t lmId, uint32_t domainId,
    dev_sm_voltage_range_t *range);

/*!
 * Set an LM voltage mode.
 *
 * @param[in]     lmId          LM requesting the operation
 * @param[in]     domainId      Identifier for the voltage domain
 * @param[in]     voltMode      Voltage mode to set
 *
 * This function requests the voltage mode for a voltage domain be set for
 * a specific LM. The requested \a voltMode is saved for the voltage domain
 * \a domainID for the LM indicated by \a lmId. The aggregation policy is to
 * set the underlying state of that voltage domain to the maximum voltage mode
 * requested by any LM for that domain. This is done by looping through all
 * of the saved modes to find the max and then passing that on to the device
 * or board. Note the voltage domains and voltage modes are device/board specific
 * and this function doesn't interpret them other than to assume a higher
 * numbered voltage mode satisfies the voltage needs of a lower numbered mode.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the current voltage mode is set successfully.
 * - ::SM_ERR_INVALID_PARAMETERS: if the parameters are invalid.
 * - others returned by ::SM_VOLTAGEMODESET
 */
int32_t LMM_VoltageModeSet(uint32_t lmId, uint32_t domainId,
    uint8_t voltMode);

/*!
 * Get an LM voltage mode.
 *
 * @param[in]     lmId          LM requesting the operation
 * @param[in]     domainId      Identifier for the voltage domain
 * @param[out]    voltMode      Pointer to return the voltage mode
 *
 * This function allows the caller to request the current mode of
 * a voltage domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the current voltage mode is returned successfully.
 * - others returned by ::SM_VOLTAGEMODEGET
 */
int32_t LMM_VoltageModeGet(uint32_t lmId, uint32_t domainId,
    uint8_t *voltMode);

/*!
 * Set an LM voltage level.
 *
 * @param[in]     lmId          LM requesting the operation
 * @param[in]     domainId      Identifier for the voltage domain
 * @param[in]     voltageLevel  Voltage level to set
 *
 * This function allows the caller to set the current level of
 * a voltage domain. Levels are not aggregated. Any valid set will
 * result in a voltage change.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the current voltage level is set successfully.
 * - others returned by ::SM_VOLTAGELEVELSET
 */
int32_t LMM_VoltageLevelSet(uint32_t lmId, uint32_t domainId,
    int32_t voltageLevel);

/*!
 * Get an LM voltage level.
 *
 * @param[in]     lmId          LM requesting the operation
 * @param[in]     domainId      Identifier for the voltage domain
 * @param[out]    voltageLevel  Pointer to return the voltage level
 *
 * This function allows the caller to request the current level of
 * a voltage domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the current voltage level is returned successfully.
 * - others returned by ::SM_VOLTAGELEVELGET
 */
int32_t LMM_VoltageLevelGet(uint32_t lmId, uint32_t domainId,
    int32_t *voltageLevel);

#endif /* LMM_VOLTAGE_H */

/** @} */

