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
 * @addtogroup DEV_SM_RESET_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device reset domains.
 */
/*==========================================================================*/

#ifndef DEV_SM_RESET_API_H
#define DEV_SM_RESET_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Get a reset domain name.
 *
 * @param[in]     domainId        Domain name to get
 * @param[out]    domainNameAddr  Return pointer to name
 * @param[out]    len             Return max length of all domain names
 *
 * This function allows the caller to get the name of a reset domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 */
int32_t DEV_SM_ResetDomainNameGet(uint32_t domainId, string *domainNameAddr,
    int32_t *len);

/*!
 * Reset a device reset domain.
 *
 * @param[in]     domainId      Identifier for the reset domain
 * @param[in]     resetState    Device-specific reset action
 * @param[in]     toggle        Autonomous reset action
 * @param[in]     assertNegate  Reset polarity
 *
 * This function allows a caller to reset the specified reset domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the operation was successful.
 */
int32_t DEV_SM_ResetDomain(uint32_t domainId, uint32_t resetState,
    bool toggle, bool assertNegate);

#endif /* DEV_SM_RESET_API_H */

/** @} */

