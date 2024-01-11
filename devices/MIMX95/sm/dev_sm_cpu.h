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

#ifndef DEV_SM_CPU_H
#define DEV_SM_CPU_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX95_CPU
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
#include "fsl_cpu.h"

/* Defines */

/*! Number of device CPUs */
#define DEV_SM_NUM_CPU      CPU_NUM_IDX

/*!
 * @name Device CPU indexes
 *
 * See the CPU Mode Control (CMC) list in General Power Controller (GPC) section
 * of the i.MX95 RM.
 */
/** @{ */
#define DEV_SM_CPU_M33P     CPU_IDX_M33P   /*!< 0: CM33 (SM) */
#define DEV_SM_CPU_M7P      CPU_IDX_M7P    /*!< 1: CM7 */
#define DEV_SM_CPU_A55C0    CPU_IDX_A55C0  /*!< 2: CA55 core 0 */
#define DEV_SM_CPU_A55C1    CPU_IDX_A55C1  /*!< 3: CA55 core 1 */
#define DEV_SM_CPU_A55C2    CPU_IDX_A55C2  /*!< 4: CA55 core 2 */
#define DEV_SM_CPU_A55C3    CPU_IDX_A55C3  /*!< 5: CA55 core 3 */
#define DEV_SM_CPU_A55C4    CPU_IDX_A55C4  /*!< 6: CA55 core 4 */
#define DEV_SM_CPU_A55C5    CPU_IDX_A55C5  /*!< 7: CA55 core 5 */
#define DEV_SM_CPU_A55P     CPU_IDX_A55P   /*!< 8: CA55 platform */
/** @} */

/*!
 * @name CPU sleep modes
 */
/** @{ */
/*! On */
#define DEV_SM_CPU_SLEEP_MODE_RUN        CPU_SLEEP_MODE_RUN
/*! Wait mode */
#define DEV_SM_CPU_SLEEP_MODE_WAIT       CPU_SLEEP_MODE_WAIT
/*! Stop mode */
#define DEV_SM_CPU_SLEEP_MODE_STOP       CPU_SLEEP_MODE_STOP
/*! Suspend mode */
#define DEV_SM_CPU_SLEEP_MODE_SUSPEND    CPU_SLEEP_MODE_SUSPEND
/** @} */

/*!
 * @name CPU sleep flags
 *
 */
/** @{ */
#define DEV_SM_CPU_SLEEP_FLAG_IRQ_MUX   0x1U
#define DEV_SM_CPU_SLEEP_FLAG_A55P_WAKE 0x2U
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

#include "dev_sm_cpu_api.h"

#endif /* DEV_SM_CPU_H */

