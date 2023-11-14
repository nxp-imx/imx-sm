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
 * @addtogroup DEV_SM_PERF_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device performance domains.
 */
/*==========================================================================*/

#ifndef DEV_SM_PERF_API_H
#define DEV_SM_PERF_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/*! Device performance info structure */
typedef struct
{
    /*! Min time in uS between calls */
    uint32_t rateLimit;
    /*! Sustained performance level in KHz */
    uint32_t sustainedFreq;
    /*! Performance level value matching above */
    uint32_t sustainedPerfLevel;
} dev_sm_perf_info_t;

/*! Device performance description structure */
typedef struct
{
    /*! Performance level value */
    uint32_t value;
    /*! Power cost */
    uint32_t powerCost;
    /*! Transition latency in uS */
    uint32_t latency;
} dev_sm_perf_desc_t;

/* Functions */

/*!
 * Initialize performance domains.
 *
 * @param[in]     bootPerfLevel   Boot performance level
 * @param[in]     runPerfLevel    Run performance level for all active domains
 *
 * This function initializes the performance domains.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_OUT_OF_RANGE: if run performance level invalid.
 * - ::SM_ERR_HARDWARE_ERROR: if run performance level transition failed.
 */
int32_t DEV_SM_PerfInit(uint32_t bootPerfLevel, uint32_t runPerfLevel);

/*!
 * Get a performance domain name.
 *
 * @param[in]     domainId        Domain name to get
 * @param[out]    perfNameAddr    Return pointer to name
 * @param[out]    len             Return max length of all domain names
 *
 * This function allows the caller to get the name of a performance domain.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 */
int32_t DEV_SM_PerfNameGet(uint32_t domainId, string *perfNameAddr,
    int32_t *len);

/*!
 * Get info for a device performance domain.
 *
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
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 */
int32_t DEV_SM_PerfInfoGet(uint32_t domainId, dev_sm_perf_info_t *info);

/*!
 * Get the number of levels for a device performance domain.
 *
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
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 */
int32_t DEV_SM_PerfNumLevelsGet(uint32_t domainId, uint32_t *numLevels);

/*!
 * Get a device performance domain level description.
 *
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
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 * - ::SM_ERR_OUT_OF_RANGE: if \a levelIndex is invalid.
 */
int32_t DEV_SM_PerfDescribe(uint32_t domainId, uint32_t levelIndex,
    dev_sm_perf_desc_t *desc);

/*!
 * Set a device performance level.
 *
 * @param[in]  domainId   Identifier for the domain
 * @param[in]  perfLevel  Performance level to set
 *
 * This function allows the caller to set the level of a performance
 * domain synchronously.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the domain level was set successfully.
 * - ::SM_ERR_NOT_FOUND if \a domainId out of range
 */
int32_t DEV_SM_PerfLevelSet(uint32_t domainId, uint32_t perfLevel);

/*!
 * Get a device performance level.
 *
 * @param[in]   domainId   Identifier for the domain
 * @param[out]  perfLevel  Pointer to return the level
 *
 * This function allows the caller to get the performance level of a
 * performance domain synchronously.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the domain level was returned successfully.
 * - ::SM_ERR_NOT_FOUND: if \a domainId is invalid.
 */
int32_t DEV_SM_PerfLevelGet(uint32_t domainId, uint32_t *perfLevel);

#endif /* DEV_SM_PERF_API_H */

/** @} */

