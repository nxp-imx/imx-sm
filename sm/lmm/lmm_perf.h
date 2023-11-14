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
 * @addtogroup LMM_PERF
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager
 * performance domains.
 */
/*==========================================================================*/

#ifndef LMM_PERF_H
#define LMM_PERF_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Get an LM performance domain name.
 *
 * @param[in]     lmId            LM call is for
 * @param[in]     domainId        Domain name to get
 * @param[out]    perfNameAddr    Return pointer to name
 * @param[out]    len             Return max length of all domain names
 *
 * This function allows the caller to get the name of a performance domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the name is returned.
 * - others returned by ::SM_PERFNAMEGET
 */
int32_t LMM_PerfNameGet(uint32_t lmId, uint32_t domainId,
    string *perfNameAddr, int32_t *len);

/*!
 * Get info for an LM performance domain.
 *
 * @param[in]   lmId        LM call is for
 * @param[in]   domainId    Identifier for the domain
 * @param[out]  info        Pointer to return info
 *
 * This function allows the caller to get the info for a
 * performance domain. The description contains the rate limit,
 * sustained frequency and sustained performance.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the info is returned.
 * - others returned by ::SM_PERFINFOGET
 */
int32_t LMM_PerfInfoGet(uint32_t lmId, uint32_t domainId,
    dev_sm_perf_info_t *info);

/*!
 * Get the number of levels for an LM performance domain.
 *
 * @param[in]   lmId        LM call is for
 * @param[in]   domainId    Identifier for the domain
 * @param[out]  numLevels   Pointer to return num levels
 *
 * This function allows the caller to get the number of levels for
 * a performance domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the number of levels is returned.
 * - others returned by ::SM_PERFNUMLEVELSGET
 */
int32_t LMM_PerfNumLevelsGet(uint32_t lmId, uint32_t domainId,
    uint32_t *numLevels);

/*!
 * Get an LM performance domain level description.
 *
 * @param[in]   lmId        LM call is for
 * @param[in]   domainId    Identifier for the domain
 * @param[in]   levelIndex  Index of level
 * @param[out]  desc        Pointer to return description
 *
 * This function allows the caller to get the description of a
 * performance domain level. The description contains the value,
 * power cost, and latency.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the description is returned.
 * - others returned by ::SM_PERFDESCRIBE
 */
int32_t LMM_PerfDescribe(uint32_t lmId, uint32_t domainId,
    uint32_t levelIndex, dev_sm_perf_desc_t *desc);

/*!
 * Set an LM performance level.
 *
 * @param[in]  lmId              LM call is for
 * @param[in]  domainId          Identifier for the domain
 * @param[in]  performanceLevel  Performance level to set
 *
 * This function allows the caller to set the level of a performance
 * domain synchronously. The level is recorded per LM and aggregated.
 * The resulting level is the max of all LM levels for this domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the domain level was set successfully.
 * - ::SM_ERR_INVALID_PARAMETERS if \a lmId out of range
 * - ::SM_ERR_NOT_FOUND if \a domainId out of range
 * - others returned by ::SM_PERFLEVELSET
 */
int32_t LMM_PerfLevelSet(uint32_t lmId, uint32_t domainId,
    uint32_t performanceLevel);

/*!
 * Get an LM performance level.
 *
 * @param[in]   lmId              LM call is for
 * @param[in]   domainId          Identifier for the domain
 * @param[out]  performanceLevel  Pointer to return the level
 *
 * This function allows the caller to get the performance level of a
 * performance domain synchronously.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the domain level was returned successfully.
 * - others returned by ::SM_PERFLEVELGET
 */
int32_t LMM_PerfLevelGet(uint32_t lmId, uint32_t domainId,
    uint32_t *performanceLevel);

#endif /* LMM_PERF_H */

/** @} */

