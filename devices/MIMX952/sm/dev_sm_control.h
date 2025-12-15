/*
** ###################################################################
**
**     Copyright 2026 NXP
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

#ifndef DEV_SM_CONTROL_H
#define DEV_SM_CONTROL_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX952_CTRL
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device controls.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device controls */
#define DEV_SM_NUM_CTRL  10UL

/*!
 * @name Device control indexes
 */
/** @{ */
#define DEV_SM_CTRL_PDM_CLK_SEL    0U   /*!< AON PDM clock sel */
#define DEV_SM_CTRL_MQS1_SETTINGS  1U   /*!< AON MQS settings */
#define DEV_SM_CTRL_SAI3_MCLK      2U   /*!< WAKE SAI3 MCLK */
#define DEV_SM_CTRL_SAI4_MCLK      3U   /*!< WAKE SAI4 MCLK */
#define DEV_SM_CTRL_SAI5_MCLK      4U   /*!< WAKE SAI5 MCLK */
#define DEV_SM_CTRL_ADC_TEST       5U   /*!< BBSM SNVS ADC enable */
#define DEV_SM_CTRL_ASRC1_MCLK     6U   /*!< WAKE ASRC1 MCLK */
#define DEV_SM_CTRL_ASRC2_MCLK     7U   /*!< WAKE ASRC2 MCLK */
#define DEV_SM_CTRL_BYPASS_AUDMIX  8U   /*!< WAKE BYPASS AUDMIX IP */
#define DEV_SM_CTRL_COMBO_PHY      9U   /*!< PCIE/NETC COMBO PHY Mode sel */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

/* coverity[misra_c_2012_rule_20_1_violation] */
#include "dev_sm_control_api.h"

#endif /* DEV_SM_CONTROL_H */

