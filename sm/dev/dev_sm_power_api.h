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
 * @addtogroup DEV_SM_POWER_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device power domains.
 */
/*==========================================================================*/

#ifndef DEV_SM_POWER_API_H
#define DEV_SM_POWER_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Initialize the device power function.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 */
int32_t DEV_SM_PowerInit(void);

/*!
 * Get a power domain name.
 *
 * @param[in]     domainId        Domain name to get
 * @param[out]    domainNameAddr  Return pointer to name
 * @param[out]    len             Return max length of all domain names
 *
 * This function allows the caller to get the name of a power domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 */
int32_t DEV_SM_PowerDomainNameGet(uint32_t domainId, string *domainNameAddr,
    int32_t *len);

/*!
 * Get a power state name.
 *
 * @param[in]     powerState     State name to get
 * @param[out]    stateNameAddr  Return pointer to name
 * @param[out]    len            Return max length of all state names
 *
 * This function allows the caller to get the name of a power state.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a powerState is invalid.
 */
int32_t DEV_SM_PowerStateNameGet(uint32_t powerState, string *stateNameAddr,
    int32_t *len);

/*!
 * Set device power domain state.
 *
 * @param[in]     domainId    Power domain to set
 * @param[in]     powerState  Requested power state
 *
 * This function requests the power state for a device power domain be set.
 * For the simulated device, this is just saved so it can be returned with
 * DEV_SM_PowerStateGet().
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND if \a domainId is out of range
 */
int32_t DEV_SM_PowerStateSet(uint32_t domainId, uint8_t powerState);

/*!
 * Get device power domain state.
 *
 * @param[in]     domainId    Power domain to get
 * @param[out]    powerState  Pointer to return the power state
 *
 * This function returns the power state of the specified power domain.
 * For the simulated device, this is just returns the power state set with
 * DEV_SM_PowerStateSet().
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND if \a domainId is out of range
 */
int32_t DEV_SM_PowerStateGet(uint32_t domainId, uint8_t *powerState);

/*!
 * Get device power retention mask.
 *
 * @param[in]     domainId  Power domain to get
 * @param[out]    retMask   Pointer to return the power state
 *
 * This function returns the retention mask for a power domain.
 * The mask contains 1s for the memories associated with the
 * power domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND if \a domainId is out of range
 */
int32_t DEV_SM_PowerRetMaskGet(uint32_t domainId, uint32_t *retMask);

#endif /* DEV_SM_POWER_API_H */

/** @} */

