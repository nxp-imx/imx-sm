/*
** ###################################################################
**
**     Copyright 2025-2026 NXP
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

#ifndef DEV_SM_POWER_H
#define DEV_SM_POWER_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX94_POWER
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device power domains.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "fsl_power.h"
#include "fsl_src.h"

/* Defines */

/*! Number of device power domains */
#define DEV_SM_NUM_POWER        (PWR_NUM_MIX_SLICE + PWR_NUM_MIX_VSLICE)

/*! Number of device power states */
#define DEV_SM_NUM_POWER_STATE  2U

/*!
 * @name Device power domain indexes
 *
 * See the Domain Slice List table in the System Reset Controller (SRC) section
 * of the i.MX95 RM.
 */
/** @{ */
#define DEV_SM_PD_ANA         PWR_MIX_SLICE_IDX_ANA        /*!< 0: Analog domain */
#define DEV_SM_PD_AON         PWR_MIX_SLICE_IDX_AON        /*!< 1: Always-on domain */
#define DEV_SM_PD_BBSM        PWR_MIX_SLICE_IDX_BBSM       /*!< 2: BB domain */
#define DEV_SM_PD_M71         PWR_MIX_SLICE_IDX_M7_1       /*!< 3: M71 platform domain */
#define DEV_SM_PD_CCMSRCGPC   PWR_MIX_SLICE_IDX_CCMSRCGPC  /*!< 4: System domain */
#define DEV_SM_PD_A55C0       PWR_MIX_SLICE_IDX_A55C0      /*!< 5: CA55 core 0 domain */
#define DEV_SM_PD_A55C1       PWR_MIX_SLICE_IDX_A55C1      /*!< 6: CA55 core 1 domain */
#define DEV_SM_PD_A55C2       PWR_MIX_SLICE_IDX_A55C2      /*!< 7: CA55 core 2 domain */
#define DEV_SM_PD_A55C3       PWR_MIX_SLICE_IDX_A55C3      /*!< 8: CA55 core 3 domain */
#define DEV_SM_PD_A55P        PWR_MIX_SLICE_IDX_A55P       /*!< 9: CA55 platform domain */
#define DEV_SM_PD_DDR         PWR_MIX_SLICE_IDX_DDR        /*!< 10: DRAM domain */
#define DEV_SM_PD_DISPLAY     PWR_MIX_SLICE_IDX_DISPLAY    /*!< 11: Display domain */
#define DEV_SM_PD_M70         PWR_MIX_SLICE_IDX_M7_0       /*!< 12: M70 platform domain */
#define DEV_SM_PD_HSIO_TOP    PWR_MIX_SLICE_IDX_HSIO_TOP   /*!< 13: HSIO domain */
#define DEV_SM_PD_HSIO_WAON   PWR_MIX_SLICE_IDX_HSIO_WAON  /*!< 14: HSIO always-on domain */
#define DEV_SM_PD_NETC        PWR_MIX_SLICE_IDX_NETC       /*!< 15: NETC domain */
#define DEV_SM_PD_NOC         PWR_MIX_SLICE_IDX_NOC        /*!< 16: NOC domain */
#define DEV_SM_PD_NPU         PWR_MIX_SLICE_IDX_NPU        /*!< 17: NPU domain */
#define DEV_SM_PD_WAKEUP      PWR_MIX_SLICE_IDX_WAKEUP     /*!< 18: Wakeup domain */
#define DEV_SM_PD_M33S        PWR_MIX_VSLICE_IDX_M33S      /*!< 19: M33S domain (virtual) */
/** @} */

/*!
 * @name Device power domain states
 */
/** @{ */
#define DEV_SM_POWER_STATE_OFF  0U  /*!< Power off */
#define DEV_SM_POWER_STATE_ON   1U  /*!< Power on */
/** @} */

/* Types */

/* Functions */

/*!
 * Initialize the device power function.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 */
int32_t DEV_SM_PowerInit(void);

/** @} */

/* Include SM device API */

/* coverity[misra_c_2012_rule_20_1_violation] */
#include "dev_sm_power_api.h"

#endif /* DEV_SM_POWER_H */

