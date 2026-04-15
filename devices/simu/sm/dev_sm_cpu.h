/*
** ###################################################################
**
**     Copyright 2023-2026 NXP
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

#ifndef DEV_SM_CPU_H
#define DEV_SM_CPU_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_SIMU_CPU
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device CPUs.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device CPUs */
#define DEV_SM_NUM_CPU  9U

/*! Number of device peripheral LPIs */
#define DEV_SM_NUM_PERLPI   1U

/*! DEV_SM_CPU disabled */
#define DEV_SM_CPU_FUSED_DISABLED   1U

/*! Number of device CPU sleep modes */
#define DEV_SM_CPU_NUM_SLEEP_MODE      4U

/*!
 * @name Device CPU indexes
 */
/** @{ */
#define DEV_SM_CPU_0  0U  /*!< CPU 0 */
#define DEV_SM_CPU_1  1U  /*!< CPU 1 */
#define DEV_SM_CPU_2  2U  /*!< CPU 2 */
#define DEV_SM_CPU_3  3U  /*!< CPU 3 */
#define DEV_SM_CPU_4  4U  /*!< CPU 4 */
#define DEV_SM_CPU_5  5U  /*!< CPU 5 */
#define DEV_SM_CPU_6  6U  /*!< CPU 6 */
#define DEV_SM_CPU_7  7U  /*!< CPU 7 */
#define DEV_SM_CPU_8  8U  /*!< CPU 8 */
/** @} */

/*!
 * @name CPU run modes
 */
/** @{ */
/*! On */
#define DEV_SM_CPU_RUN_MODE_RUN    0U
/*! Wait mode */
#define DEV_SM_CPU_RUN_MODE_HOLD   1U
/*! Stop mode */
#define DEV_SM_CPU_RUN_MODE_STOP   2U
/*! Suspend mode */
#define DEV_SM_CPU_RUN_MODE_SLEEP  3U
/** @} */

/*!
 * @name CPU sleep modes
 */
/** @{ */
/*! On */
#define DEV_SM_CPU_SLEEP_MODE_RUN      0U
/*! Wait mode */
#define DEV_SM_CPU_SLEEP_MODE_WAIT     1U
/*! Stop mode */
#define DEV_SM_CPU_SLEEP_MODE_STOP     2U
/*! Suspend mode */
#define DEV_SM_CPU_SLEEP_MODE_SUSPEND  3U

/*! Select between GPC or GIC for wakeup */
#define DEV_SM_CPU_SLEEP_FLAG_IRQ_MUX    0x1U
/*! Wake A55 CPU during A55 platform wakeup */
#define DEV_SM_CPU_SLEEP_FLAG_A55P_WAKE  0x2U
/*! Enable LP compute during system sleep */
#define DEV_SM_CPU_SLEEP_FLAG_LP_COMPUTE 0x4U
/** @} */

/*!
 * @name Device peripheral LPI indexes
 */
/** @{ */
#define DEV_SM_PERLPI_RESV  0U   /*!< 0: Test */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

/* coverity[misra_c_2012_rule_20_1_violation] */
#include "dev_sm_cpu_api.h"

#endif /* DEV_SM_CPU_H */

