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
 * @addtogroup LMM_POWER
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager power
 * domains.
 */
/*==========================================================================*/

#ifndef LMM_POWER_H
#define LMM_POWER_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Get a power domain name.
 *
 * @param[in]     lmId            LM call is for
 * @param[in]     domainId        Domain name to get
 * @param[out]    domainNameAddr  Return pointer to name
 * @param[out]    len             Return max length of all domain names
 *
 * This function allows the caller to get the name of a power domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the name is returned.
 * - others returned by ::SM_POWERDOMAINNAMEGET
 */
int32_t LMM_PowerDomainNameGet(uint32_t lmId, uint32_t domainId,
    string *domainNameAddr, int32_t *len);

/*!
 * Get an LM  power state name.
 *
 * @param[in]     lmId           LM call is for
 * @param[in]     powerState     State name to get
 * @param[out]    stateNameAddr  Return pointer to name
 * @param[out]    len            Return max length of all state names
 *
 * This function allows the caller to get the name of a power state.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the name is returned.
 * - others returned by ::SM_POWERSTATENAMEGET
 */
int32_t LMM_PowerStateNameGet(uint32_t lmId, uint32_t powerState,
    string *stateNameAddr, int32_t *len);

/*!
 * Set an LM power domain state.
 *
 * @param[in]     lmId        LM requesting the operation
 * @param[in]     domainId    Identifier for the power domain
 * @param[in]     powerState  Requested power state
 *
 * This function requests the power state for a power domain be set for
 * a specific LM. The requested \a powerState is saved for the power domain
 * \a domainID for the LM indicated by \a lmId. The aggregation policy is to
 * set the underlying state of that power domain to the maximum power state
 * requested by any LM for that domain. This is done by looping through all
 * of the saved states to find the max and then passing that on to the device
 * or board. Note the power domains and power states are device/board specific
 * and this function doesn't interpret them other than to assume a higher
 * numbered power state satisfies the power needs of a lower numbered state.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the power state is set.
 * - ::SM_ERR_INVALID_PARAMETERS if \a lmId out of range
 * - ::SM_ERR_NOT_FOUND if \a domainId out of range
 * - others returned by ::SM_POWERSTATESET
 */
int32_t LMM_PowerStateSet(uint32_t lmId, uint32_t domainId,
    uint8_t powerState);

/*!
 * Get an LM power state.
 *
 * @param[in]     lmId        LM requesting the operation
 * @param[in]     domainId    Identifier for the power domain
 * @param[out]    powerState  Pointer to return the power state
 *
 * This function allows the caller to request the current power state of
 * a power domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the current power state is returned successfully.
 * - others returned by ::SM_POWERSTATEGET
 */
int32_t LMM_PowerStateGet(uint32_t lmId, uint32_t domainId,
    uint8_t *powerState);

#endif /* LMM_POWER_H */

/** @} */

