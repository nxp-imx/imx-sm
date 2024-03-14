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
#define DEV_SM_NUM_PERF     21U

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
#define DEV_SM_PERF_A55PER  13U  /*!< A55PER domain */
#define DEV_SM_PERF_A55P    14U  /*!< A55P domain */
#define DEV_SM_PERF_A55C0   15U  /*!< A55C0 domain */
#define DEV_SM_PERF_A55C1   16U  /*!< A55C1 domain */
#define DEV_SM_PERF_A55C2   17U  /*!< A55C2 domain */
#define DEV_SM_PERF_A55C3   18U  /*!< A55C3 domain */
#define DEV_SM_PERF_A55C4   19U  /*!< A55C4 domain */
#define DEV_SM_PERF_A55C5   20U  /*!< A55C5 domain */
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

/** @} */

/* Include SM device API */

// coverity[misra_c_2012_rule_20_1_violation:FALSE]
#include "dev_sm_perf_api.h"

#endif /* DEV_SM_PERF_H */

