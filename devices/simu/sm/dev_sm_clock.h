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

#ifndef DEV_SM_CLOCK_H
#define DEV_SM_CLOCK_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_SIMU_CLOCK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device clocks.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device clocks */
#define DEV_SM_NUM_CLOCK  (CLOCK_NUM_SRC + CLOCK_NUM_ROOT + \
    CLOCK_NUM_GPR_SEL + CLOCK_NUM_CGC)

/*!
 * @name Device clock domain indexes
 */
/** @{ */
#define CLOCK_NUM_SRC           6U /*!< Number of clock sources */

#define DEV_SM_CLK_SRC_0        0U /*!< Clock Source 0 */
#define DEV_SM_CLK_SRC_1        1U /*!< Clock Source 1 */
#define DEV_SM_CLK_SRC_2        2U /*!< Clock Source 2 */
#define DEV_SM_CLK_SRC_3        3U /*!< Clock Source 3 */
#define DEV_SM_CLK_SRC_4        4U /*!< Clock Source 4 */
#define DEV_SM_CLK_SRC_5        5U /*!< Clock Source 5 */

#define CLOCK_NUM_ROOT          10U /*!< Number of clock roots */
#define CLOCK_NUM_ROOT_MUX_SEL  4U /*!< Number of root mux selections */

#define DEV_SM_CLK_0            0U /*!< Clock 0 */
#define DEV_SM_CLK_1            1U /*!< Clock 1 */
#define DEV_SM_CLK_2            2U /*!< Clock 2 */
#define DEV_SM_CLK_3            3U /*!< Clock 3 */
#define DEV_SM_CLK_4            4U /*!< Clock 4 */
#define DEV_SM_CLK_5            5U /*!< Clock 5 */
#define DEV_SM_CLK_6            6U /*!< Clock 6 */
#define DEV_SM_CLK_7            7U /*!< Clock 7 */
#define DEV_SM_CLK_8            8U /*!< Clock 8 */
#define DEV_SM_CLK_9            9U /*!< Clock 9 */

#define CLOCK_NUM_GPR_SEL       2U /*!< Number of GPR selections */
#define CLOCK_NUM_GPR_MUX_SEL   2U /*!< Number of GPR mux selections */

#define DEV_SM_GPR_SEL_0        0U /*!< GPR 0 */
#define DEV_SM_GPR_SEL_1        1U /*!< GPR 1 */

#define CLOCK_NUM_CGC           1U /*!< Number of CGC */

#define DEV_SM_CGM_0            0U /*!< CGM 0 */

/* Clock source identifiers */
#define CLOCK_SRC_0             DEV_SM_CLK_SRC_0 /*!< Clock Source 0 */
#define CLOCK_SRC_1             DEV_SM_CLK_SRC_1 /*!< Clock Source 1 */
#define CLOCK_SRC_2             DEV_SM_CLK_SRC_2 /*!< Clock Source 2 */
#define CLOCK_SRC_3             DEV_SM_CLK_SRC_3 /*!< Clock Source 3 */
#define CLOCK_SRC_4             DEV_SM_CLK_SRC_4 /*!< Clock Source 4 */
#define CLOCK_SRC_5             DEV_SM_CLK_SRC_5 /*!< Clock Source 5 */

/* Clock root identifiers */
/*! Clock Root 0 */
#define CLOCK_ROOT_0            CLOCK_NUM_SRC + DEV_SM_CLK_0

/*! Clock Root 1 */
#define CLOCK_ROOT_1            CLOCK_NUM_SRC + DEV_SM_CLK_1

/*! Clock Root 2 */
#define CLOCK_ROOT_2            CLOCK_NUM_SRC + DEV_SM_CLK_2

/*! Clock Root 3 */
#define CLOCK_ROOT_3            CLOCK_NUM_SRC + DEV_SM_CLK_3

/*! Clock Root 4 */
#define CLOCK_ROOT_4            CLOCK_NUM_SRC + DEV_SM_CLK_4

/*! Clock Root 5 */
#define CLOCK_ROOT_5            CLOCK_NUM_SRC + DEV_SM_CLK_5

/*! Clock Root 6 */
#define CLOCK_ROOT_6            CLOCK_NUM_SRC + DEV_SM_CLK_6

/*! Clock Root 7 */
#define CLOCK_ROOT_7            CLOCK_NUM_SRC + DEV_SM_CLK_7

/*! Clock Root 8 */
#define CLOCK_ROOT_8            CLOCK_NUM_SRC + DEV_SM_CLK_8

/*! Clock Root 9 */
#define CLOCK_ROOT_9            CLOCK_NUM_SRC + DEV_SM_CLK_9

/* GPR clock selections */
#define CLOCK_GPR_0  \
    ((CLOCK_NUM_SRC + CLOCK_NUM_ROOT) + DEV_SM_GPR_SEL_0) /*!< Clock GPR 0 */

#define CLOCK_GPR_1  \
    ((CLOCK_NUM_SRC + CLOCK_NUM_ROOT) + DEV_SM_GPR_SEL_1) /*!< Clock GPR 1 */

/*! CGM clock identifiers */
#define CLOCK_CGM_0  \
    ((CLOCK_NUM_SRC + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL) + DEV_SM_CGM_0)
/** @} */

/*!
 * @name Device round parameters
 */
/** @{ */
#define DEV_SM_CLOCK_ROUND_DOWN        0x0U   /*!< Round rate down */
#define DEV_SM_CLOCK_ROUND_UP          0x1U   /*!< Round rate up */
#define DEV_SM_CLOCK_ROUND_AUTO        0x2U   /*!< Automatically select closest rate */
/** @} */

/*! Number of extended clock attributes */
#define DEV_SM_NUM_CLOCK_EXT        1U

/*!
 * @name Device extended clock parameters
 */
/** @{ */
#define DEV_SM_CLOCK_EXT_SSC  0x80U   /*!< Spread spectrum extended clock type */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

/* coverity[misra_c_2012_rule_20_1_violation] */
#include "dev_sm_clock_api.h"

#endif /* DEV_SM_CLOCK_H */

