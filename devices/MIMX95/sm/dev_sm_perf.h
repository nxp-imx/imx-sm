/*
** ###################################################################
**
**     Copyright 2023, 2026 NXP
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

#ifndef DEV_SM_PERF_H
#define DEV_SM_PERF_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX95_PERF
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device performance domains.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "fsl_supply.h"

/* Defines */

/*! Number of device performance domains */
#define DEV_SM_NUM_PERF     13U

/*!
 * @name Device performance domain indexes
 */
/** @{ */
#define DEV_SM_PERF_ELE     0U   /*!< ELE domain */
#define DEV_SM_PERF_M33     1U   /*!< M33 domain */
#define DEV_SM_PERF_WAKEUP  2U   /*!< WAKEUP domain */
#define DEV_SM_PERF_M7      3U   /*!< M7 domain */
#define DEV_SM_PERF_DRAM    4U   /*!< DRAM domain */
#define DEV_SM_PERF_HSIO    5U   /*!< HSIO domain */
#define DEV_SM_PERF_NPU     6U   /*!< NPU domain */
#define DEV_SM_PERF_NOC     7U   /*!< NOC domain */
#define DEV_SM_PERF_A55     8U   /*!< A55 domain */
#define DEV_SM_PERF_GPU     9U   /*!< GPU domain */
#define DEV_SM_PERF_VPU     10U  /*!< VPU domain */
#define DEV_SM_PERF_CAM     11U  /*!< CAM domain */
#define DEV_SM_PERF_DISP    12U  /*!< DISP domain */
/** @} */

/*!
 * @name Device performance domain levels
 */
/** @{ */
#define DEV_SM_PERF_LVL_PRK  0U  /*!< Default/reset drive */
#define DEV_SM_PERF_LVL_LOW  1U  /*!< Low drive per datasheet */
#define DEV_SM_PERF_LVL_NOM  2U  /*!< Nominal drive per datasheet */
#define DEV_SM_PERF_LVL_ODV  3U  /*!< Overdrive per datasheet */
#define DEV_SM_PERF_LVL_SOD  4U  /*!< Super overdrive per datasheet */
/** @} */

/* Types */

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
 * Set frequency of a performance domain.
 *
 * @param[in]  domainId   Identifier for the domain
 * @param[in]  perfLevel  Performance level to set
 *
 * This function allows the caller to set the frequency setpoint of a
 * performance domain to a setpoint associated with the specified
 * performance level.  The voltage level required for the specified
 * setpoint must be set before/after calling this function based
 * on directionality.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the domain level was set successfully.
 * - ::SM_ERR_NOT_FOUND if \a domainId out of range
 */
int32_t DEV_SM_PerfFreqSet(uint32_t domainId, uint32_t perfLevel);

/*!
 * Configure performance level for system sleep.
 *
 * @param[in]   perfLevelSleep  Level for system sleep performance domains
 *
 * This function configures the level for system sleep performance
 * domains.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the domain level was returned successfully.
 * - ::SM_ERR_OUT_OF_RANGE: if \a perfLevelSleep is invalid.
 */
int32_t DEV_SM_PerfSystemSleep(uint32_t perfLevelSleep);

/*!
 * Configure performance level for system wakeup.
 *
 * @param[in]   perfLevelSleep  Level for system sleep performance domains
 *
 * This function restores the level for system sleep performance
 * domains.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the domain level was returned successfully.
 */
int32_t DEV_SM_PerfSystemWake(uint32_t perfLevelSleep);

/** @} */

/* Include SM device API */

/* coverity[misra_c_2012_rule_20_1_violation] */
#include "dev_sm_perf_api.h"

#endif /* DEV_SM_PERF_H */

