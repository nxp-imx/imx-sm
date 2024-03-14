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
#define DEV_SM_NUM_CPU  4U

/*! Number of device peripheral LPIs */
#define DEV_SM_NUM_PERLPI   1U

/*!
 * @name Device CPU indexes
 */
/** @{ */
#define DEV_SM_CPU_0  0U  /*!< CPU 0 */
#define DEV_SM_CPU_1  1U  /*!< CPU 1 */
#define DEV_SM_CPU_2  2U  /*!< CPU 2 */
#define DEV_SM_CPU_3  3U  /*!< CPU 3 */
/** @} */

/*!
 * @name CPU sleep modes
 */
/** @{ */
/*! On */
#define DEV_SM_CPU_SLEEP_MODE_RUN        0U
/*! Wait mode */
#define DEV_SM_CPU_SLEEP_MODE_WAIT       1U
/*! Stop mode */
#define DEV_SM_CPU_SLEEP_MODE_STOP       2U
/*! Suspend mode */
#define DEV_SM_CPU_SLEEP_MODE_SUSPEND    3U
/** @} */

/*!
 * @name Device peripheral LPI indexes
 */
/** @{ */
#define DEV_SM_PERLPI_RESV      0U   /*!< 0: Test */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

// coverity[misra_c_2012_rule_20_1_violation:FALSE]
#include "dev_sm_cpu_api.h"

#endif /* DEV_SM_CPU_H */

