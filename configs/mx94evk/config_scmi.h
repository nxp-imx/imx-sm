/*
** ###################################################################
**
** Copyright 2025-2026 NXP
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
 * @addtogroup CONFIG_MX94EVK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing configuration info for the SCMI RPC.
 */
/*==========================================================================*/

#ifndef CONFIG_SCMI_H
#define CONFIG_SCMI_H

/* Includes */

#include "config_user.h"

/* Defines */

/*--------------------------------------------------------------------------*/
/* SCMI AGENT0 Config (M33S-S)                                              */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI agent 0 */
#define SM_SCMI_AGNT0_CONFIG \
    { \
        .name = "M33S-S", \
        .scmiInst = 0U, \
        .domId = 13U, \
        .secure = 0U, \
        .buttonPerms[DEV_SM_BUTTON_0] = SM_SCMI_PERM_NOTIFY, \
        .clkPerms[DEV_SM_CLK_LPUART3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART8] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_M33SYNCSYSTICK] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_TPM5] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_TPM6] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_M33S] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[BRD_SM_CTRL_BUTTON] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_TEST] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[BRD_SM_CTRL_TEST_A] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART3_CTS] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART3_RXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART3_TXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART8_RXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART8_TXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_TPM5_CH_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_TPM5_CH_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_TPM6_CH_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_TPM6_CH_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_TPM6_CLK] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_M33_SYNC_LOCKUP] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_M33_SYNC_RST] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_WDOG7] = SM_SCMI_PERM_ALL, \
        .lmmPerms[2] = SM_SCMI_PERM_NOTIFY, \
        .lmmPerms[3] = SM_SCMI_PERM_NOTIFY, \
        .lmmPerms[4] = SM_SCMI_PERM_NOTIFY, \
        .pdPerms[DEV_SM_PD_M33S] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_NETC] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_M33S] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART8] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG7] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_DAP_TCLK_SWCLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_DAP_TMS_SWDIO] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO30] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO31] = SM_SCMI_PERM_ALL, \
        .rtcPerms[BRD_SM_RTC_PCA2131] = SM_SCMI_PERM_PRIV, \
        .rtcPerms[DEV_SM_RTC_BBNSM] = SM_SCMI_PERM_PRIV, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF09] = SM_SCMI_PERM_SET, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF53] = SM_SCMI_PERM_SET, \
        .sensorPerms[DEV_SM_SENSOR_TEMP_ANA] = SM_SCMI_PERM_SET, \
        .sysPerms = SM_SCMI_PERM_PRIV, \
    }

/*! Config for SCMI channel 0 */
#define SM_SCMI_CHN0_CONFIG \
    { \
        .agentId = 0U, \
        .type = SM_SCMI_CHN_A2P, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 0U, \
    }

/*! Config for SCMI channel 1 */
#define SM_SCMI_CHN1_CONFIG \
    { \
        .agentId = 0U, \
        .type = SM_SCMI_CHN_P2A_NOTIFY, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 1U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI AGENT1 Config (M33S-NS)                                             */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI agent 1 */
#define SM_SCMI_AGNT1_CONFIG \
    { \
        .name = "M33S-NS", \
        .scmiInst = 0U, \
        .domId = 13U, \
        .secure = 0U, \
        .faultPerms[DEV_SM_FAULT_WDOG8] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_NETC] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG8] = SM_SCMI_PERM_ALL, \
        .sysPerms = SM_SCMI_PERM_NOTIFY, \
    }

/*! Config for SCMI channel 2 */
#define SM_SCMI_CHN2_CONFIG \
    { \
        .agentId = 1U, \
        .type = SM_SCMI_CHN_A2P, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 2U, \
    }

/*! Config for SCMI channel 3 */
#define SM_SCMI_CHN3_CONFIG \
    { \
        .agentId = 1U, \
        .type = SM_SCMI_CHN_P2A_NOTIFY, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 3U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI Instance 0 Config (M33S)                                            */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI instance 0 */
#define SM_SCMI0_CONFIG \
    { \
        .lmId = 1U, \
        .numAgents = 2U, \
        .firstAgent = 0U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI AGENT2 Config (M7)                                                  */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI agent 2 */
#define SM_SCMI_AGNT2_CONFIG \
    { \
        .name = "M7", \
        .scmiInst = 1U, \
        .domId = 4U, \
        .secure = 0U, \
        .seenvId = 1U, \
        .buttonPerms[DEV_SM_BUTTON_0] = SM_SCMI_PERM_NOTIFY, \
        .clkPerms[DEV_SM_CLK_BISS] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CAN1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENCPLL_PFD0] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENCPLL_PFD0_UNGATED] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENCPLL_PFD1_UNGATED] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENCPLL_VCO] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENDAT21] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENDAT22] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENDAT31FAST] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENDAT31SLOW] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_FLEXIO3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_FLEXIO4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_GPT3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_GPT4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_HIPERFACE1SYNC] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_HIPERFACE1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_HIPERFACE2SYNC] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_HIPERFACE2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPTMR1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPTMR2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART11] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_M70SYSTICK] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_TPM4] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_M7P0] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[BRD_SM_CTRL_BUTTON] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_PCA2131] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[BRD_SM_CTRL_TEST] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[BRD_SM_CTRL_TEST_A] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_BISS1_PULSE_STR_CTL] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_ENC_DIAG_MUX_SEL] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_ENDAT3_STATUS] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_ENDAT_STRETCH_CTRL] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_GPT_MUX] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_HPF1_INTR_CTRL] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_HPF1_SYNC_SRC_CFG1] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_HPF1_SYNC_SRC_CFG2] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_HPF2_INTR_CTRL] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_HPF2_SYNC_SRC_CFG1] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_HPF2_SYNC_SRC_CFG2] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_HPF_SYNC_OUT_CTL] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_XBAR_DIR_CTRL] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_XBAR_DIR_CTRL_2] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_XBAR_TRIG_SYNC] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_XBAR_TRIG_SYNC_2] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_XBAR_TRIG_SYNC_3] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_XBAR_TRIG_SYNC_4] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_CAN1_RX] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_ENCODER2_CLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_ENCODER2_IN] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM1_PWMX_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM1_PWMX_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM2_PWMX_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM2_PWMX_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM3_PWMA_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM3_PWMA_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM3_PWMA_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM3_PWMA_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM3_PWMB_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM3_PWMB_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM3_PWMB_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM3_PWMB_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM3_PWMX_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM3_PWMX_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM3_PWMX_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_GPT_MUX_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_GPT_MUX_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_GPT_MUX_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_GPT_MUX_4] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_GPT_MUX_5] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_GPT_MUX_6] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_GPT_MUX_7] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_GPT_MUX_8] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_GPT_MUX_9] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPTMR2_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPTMR2_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPTMR2_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART11_RXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART11_TXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SINC4_EMBIT_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SINC4_EMBIT_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SINC4_EMBIT_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SINC4_EMCLK_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SINC4_EMCLK_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SINC4_EMCLK_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_TPM4_CH_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_10] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_11] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_12] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_13] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_14] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_15] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_16] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_17] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_18] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_19] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_20] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_30] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_31] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_32] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_33] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_34] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_35] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_36] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_37] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_38] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_39] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_40] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_41] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_42] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_43] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_44] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_45] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_46] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_47] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_48] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_4] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_5] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_6] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_7] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_8] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XBAR1_IN_9] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_M7_LOCKUP] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_M7_RST] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_SWNCF00] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_SWNCF01] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_WDOG5] = SM_SCMI_PERM_ALL, \
        .fusaPerms = SM_SCMI_PERM_PRIV, \
        .lmmPerms[1] = SM_SCMI_PERM_NOTIFY, \
        .lmmPerms[4] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_M70] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_NETC] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_M70] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN1] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART11] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG5] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO24] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO25] = SM_SCMI_PERM_ALL, \
        .rtcPerms[BRD_SM_RTC_PCA2131] = SM_SCMI_PERM_ALL, \
        .rtcPerms[DEV_SM_RTC_BBNSM] = SM_SCMI_PERM_PRIV, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF09] = SM_SCMI_PERM_SET, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF53] = SM_SCMI_PERM_SET, \
        .sensorPerms[DEV_SM_SENSOR_TEMP_ANA] = SM_SCMI_PERM_ALL, \
        .sysPerms = SM_SCMI_PERM_ALL, \
    }

/*! Config for SCMI channel 4 */
#define SM_SCMI_CHN4_CONFIG \
    { \
        .agentId = 2U, \
        .type = SM_SCMI_CHN_A2P, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 4U, \
    }

/*! Config for SCMI channel 5 */
#define SM_SCMI_CHN5_CONFIG \
    { \
        .agentId = 2U, \
        .type = SM_SCMI_CHN_P2A_NOTIFY, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 5U, \
    }

/*! Config for SCMI channel 6 */
#define SM_SCMI_CHN6_CONFIG \
    { \
        .agentId = 2U, \
        .type = SM_SCMI_CHN_P2A_PRIORITY, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 6U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI Instance 1 Config (M7)                                              */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI instance 1 */
#define SM_SCMI1_CONFIG \
    { \
        .lmId = 2U, \
        .numAgents = 1U, \
        .firstAgent = 2U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI AGENT3 Config (M71)                                                 */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI agent 3 */
#define SM_SCMI_AGNT3_CONFIG \
    { \
        .name = "M71", \
        .scmiInst = 2U, \
        .domId = 14U, \
        .secure = 0U, \
        .seenvId = 2U, \
        .buttonPerms[DEV_SM_BUTTON_0] = SM_SCMI_PERM_NOTIFY, \
        .clkPerms[DEV_SM_CLK_GPT1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_GPT2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART12] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_M71SYSTICK] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_TPM2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_XSPISLVROOT] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_M7P1] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[BRD_SM_CTRL_BUTTON] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_TEST] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[BRD_SM_CTRL_TEST_A] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM4_PWMA_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM4_PWMA_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM4_PWMA_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM4_PWMA_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM4_PWMB_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM4_PWMB_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM4_PWMB_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM4_PWMB_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM4_PWMX_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXPWM4_PWMX_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_GPT1_CLKIN] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPIT3_EXT_TRIG_IN_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_TPM3_CH_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_CS] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_DQS] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_SCK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_SLV_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_SLV_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_SLV_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_SLV_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_SLV_4] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_SLV_5] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_SLV_6] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_SLV_7] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_M7_1_LOCKUP] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_M7_1_RST] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_SWNCF02] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_WDOG6] = SM_SCMI_PERM_ALL, \
        .fusaPerms = SM_SCMI_PERM_PRIV, \
        .lmmPerms[1] = SM_SCMI_PERM_NOTIFY, \
        .lmmPerms[4] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_M71] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_NETC] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_M70] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART12] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG6] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO26] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO27] = SM_SCMI_PERM_ALL, \
        .rtcPerms[BRD_SM_RTC_PCA2131] = SM_SCMI_PERM_PRIV, \
        .rtcPerms[DEV_SM_RTC_BBNSM] = SM_SCMI_PERM_PRIV, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF09] = SM_SCMI_PERM_SET, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF53] = SM_SCMI_PERM_SET, \
        .sensorPerms[DEV_SM_SENSOR_TEMP_ANA] = SM_SCMI_PERM_SET, \
        .sysPerms = SM_SCMI_PERM_ALL, \
    }

/*! Config for SCMI channel 7 */
#define SM_SCMI_CHN7_CONFIG \
    { \
        .agentId = 3U, \
        .type = SM_SCMI_CHN_A2P, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 7U, \
    }

/*! Config for SCMI channel 8 */
#define SM_SCMI_CHN8_CONFIG \
    { \
        .agentId = 3U, \
        .type = SM_SCMI_CHN_P2A_NOTIFY, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 8U, \
    }

/*! Config for SCMI channel 9 */
#define SM_SCMI_CHN9_CONFIG \
    { \
        .agentId = 3U, \
        .type = SM_SCMI_CHN_P2A_PRIORITY, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 9U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI Instance 2 Config (M71)                                             */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI instance 2 */
#define SM_SCMI2_CONFIG \
    { \
        .lmId = 3U, \
        .numAgents = 1U, \
        .firstAgent = 3U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI AGENT4 Config (AP-S)                                                */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI agent 4 */
#define SM_SCMI_AGNT4_CONFIG \
    { \
        .name = "AP-S", \
        .scmiInst = 3U, \
        .domId = 3U, \
        .secure = 1U, \
        .clkPerms[DEV_SM_CLK_ARMPLL_PFD0] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ARMPLL_PFD0_UNGATED] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ARMPLL_PFD1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ARMPLL_PFD1_UNGATED] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ARMPLL_PFD2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ARMPLL_PFD2_UNGATED] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ARMPLL_PFD3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ARMPLL_PFD3_UNGATED] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ARMPLL_VCO] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_A55C0] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_A55C1] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_A55C2] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_A55C3] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_A55P] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_WDOG3] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_WDOG4] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_A55P] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_A55] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN2] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO2] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO6] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO7] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART10] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART1] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART6] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART7] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART9] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG4] = SM_SCMI_PERM_ALL, \
        .sysPerms = SM_SCMI_PERM_ALL, \
    }

/*! Config for SCMI channel 10 */
#define SM_SCMI_CHN10_CONFIG \
    { \
        .agentId = 4U, \
        .type = SM_SCMI_CHN_A2P, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 10U, \
    }

/*! Config for SCMI channel 11 */
#define SM_SCMI_CHN11_CONFIG \
    { \
        .agentId = 4U, \
        .type = SM_SCMI_CHN_P2A_NOTIFY, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 11U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI AGENT5 Config (AP-NS)                                               */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI agent 5 */
#define SM_SCMI_AGNT5_CONFIG \
    { \
        .name = "AP-NS", \
        .scmiInst = 3U, \
        .domId = 3U, \
        .secure = 0U, \
        .buttonPerms[DEV_SM_BUTTON_0] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_AUDIOPLL1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_AUDIOPLL1_VCO] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_AUDIOPLL2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_AUDIOPLL2_VCO] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CAN2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CAN3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CAN4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CAN5] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CCMCKO1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CCMCKO2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CCMCKO3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CCMCKO4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_DISPPIX] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ECAT] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENETREF] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENETTIMER1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENETTIMER2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENETTIMER3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_EXT1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_EXT2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_EXT] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_EXT_GPR_SEL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_FLEXIO1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_FLEXIO2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_HSIOPCIEAUX] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_HSIOPLL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_HSIOPLL_VCO] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_I3C1SLOW] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_I3C2SLOW] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LDBPLL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LDBPLL_VCO] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPI2C2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPI2C3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPI2C4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPI2C5] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPI2C6] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPI2C7] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPI2C8] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPSPI1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPSPI2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPSPI3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPSPI4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPSPI5] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPSPI6] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPSPI7] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPSPI8] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART10] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART5] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART6] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART7] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART9] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MAC0] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MAC1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MAC2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MAC3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MAC4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MAC5] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_NPU_CGC] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_PDM] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_SAI1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_SAI2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_SAI3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_SAI4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_USBPHYBURUNIN] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_USDHC1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_USDHC2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_USDHC3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_XSPI1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_XSPI2] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[BRD_SM_CTRL_BT_WAKE] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_BUTTON] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_FAN] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_PCIE1_WAKE] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_PCIE2_WAKE] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_SD3_WAKE] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_TEST_A] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_ADC_TEST] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_ADC_TRIGGER] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_MQS1_SETTINGS] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_MQS2_SETTINGS] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_PDM_CLK_SEL] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_SAI1_MCLK] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_SAI2_MCLK] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_SAI3_MCLK] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_SAI4_MCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_CAN2_RX] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_CAN3_RX] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_CAN4_RX] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_CAN5_RX] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_ECAT_MDIO] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_ECAT_PROM] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_ETH4_RXD_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_ETH4_RXD_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_ETH4_RXD_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_ETH4_RXD_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_ETH4_RX_CLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_ETH4_RX_CTL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_ETH4_TX_CLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_EXT1_CLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO2_11] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_I3C2_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_I3C2_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C3_HREQ] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C3_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C3_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C4_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C4_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C5_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C5_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C6_HREQ] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C6_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C6_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C7_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C7_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C8_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C8_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPIT2_EXT_TRIG_IN_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPSPI3_PCS_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPSPI4_PCS_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPSPI5_PCS_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPSPI6_PCS_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPSPI7_PCS_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPSPI8_PCS_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART10_CTS] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART10_RXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART10_TXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART4_CTS] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART4_RXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART4_TXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART5_CTS] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART5_RXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART5_TXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART6_CTS] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART6_RXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART6_TXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART7_RXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART7_TXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART9_RXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART9_TXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_1588MUX_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_1588MUX_10] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_1588MUX_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_1588MUX_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_1588MUX_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_1588MUX_4] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_1588MUX_5] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_1588MUX_6] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_1588MUX_7] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_1588MUX_8] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_1588MUX_9] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_CMPLX_EMDIO] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_PDM_BITSTREAM_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_PDM_BITSTREAM_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_PDM_BITSTREAM_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_PDM_BITSTREAM_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI1_MCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI2_MCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI2_RXBCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI2_RXDATA_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI2_RXSYNC] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI2_TXBCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI2_TXSYNC] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI3_RXBCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI3_TXSYNC] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI4_MCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI4_RXBCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI4_RXDATA_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI4_RXSYNC] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI4_TXBCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI4_TXSYNC] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC2_WP_ON] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC3_CMD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC3_DAT0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC3_DAT1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC3_DAT2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC3_DAT3] = SM_SCMI_PERM_ALL, \
        .gprPerms[DEV_SM_GPR_4] = SM_SCMI_PERM_ALL, \
        .gprPerms[DEV_SM_GPR_5] = SM_SCMI_PERM_ALL, \
        .gprPerms[DEV_SM_GPR_6] = SM_SCMI_PERM_ALL, \
        .gprPerms[DEV_SM_GPR_7] = SM_SCMI_PERM_ALL, \
        .lmmPerms[1] = SM_SCMI_PERM_NOTIFY, \
        .lmmPerms[2] = SM_SCMI_PERM_NOTIFY, \
        .lmmPerms[3] = SM_SCMI_PERM_NOTIFY, \
        .pdPerms[DEV_SM_PD_DISPLAY] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_HSIO_TOP] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_NETC] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_NPU] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_A55] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_NPU] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN2] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO2] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO6] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO7] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART10] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART1] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART6] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART7] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART9] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG4] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_CCM_CLKO1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_CCM_CLKO2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_CCM_CLKO3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_CCM_CLKO4] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_DAP_TDI] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_DAP_TDO_TRACESWO] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_COL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_CRS] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_RXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_RXD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_RXD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_RXD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_RX_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_RX_DV] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_RX_ER] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_TXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_TXD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_TXD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_TXD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_TX_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_TX_EN] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH0_TX_ER] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_COL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_CRS] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_RXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_RXD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_RXD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_RXD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_RX_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_RX_DV] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_RX_ER] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_TXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_TXD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_TXD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_TXD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_TX_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_TX_EN] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH1_TX_ER] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_MDC_GPIO1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_MDIO_GPIO2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_RXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_RXD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_RXD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_RXD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_RX_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_RX_CTL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_TXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_TXD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_TXD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_TXD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_TX_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH2_TX_CTL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_MDC_GPIO1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_MDIO_GPIO2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_RXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_RXD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_RXD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_RXD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_RX_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_RX_CTL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_TXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_TXD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_TXD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_TXD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_TX_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH3_TX_CTL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_MDC_GPIO1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_MDIO_GPIO2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_RXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_RXD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_RXD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_RXD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_RX_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_RX_CTL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_TXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_TXD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_TXD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_TXD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_TX_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ETH4_TX_CTL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO00] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO01] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO02] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO03] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO04] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO05] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO06] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO07] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO08] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO09] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO10] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO11] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO12] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO13] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO14] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO15] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO16] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO17] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO18] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO19] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO20] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO21] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO22] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO23] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO28] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO29] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO32] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO33] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO34] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO35] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO36] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO37] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO38] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO39] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO40] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO41] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO42] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO43] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO44] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO45] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO46] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO47] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO48] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO49] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO50] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO51] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO52] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO53] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO54] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO55] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO56] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO57] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_I2C2_SCL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_I2C2_SDA] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_PDM_BIT_STREAM0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_PDM_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SAI1_RXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SAI1_TXC] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SAI1_TXD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SAI1_TXFS] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD1_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD1_CMD] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD1_DATA0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD1_DATA1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD1_DATA2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD1_DATA3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD1_DATA4] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD1_DATA5] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD1_DATA6] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD1_DATA7] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD1_STROBE] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_CD_B] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_CMD] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_DATA0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_DATA1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_DATA2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_DATA3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_GPIO0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_GPIO1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_GPIO2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_GPIO3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_RESET_B] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_VSELECT] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_UART1_RXD] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_UART1_TXD] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_DATA0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_DATA1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_DATA2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_DATA3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_DATA4] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_DATA5] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_DATA6] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_DATA7] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_DQS] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_SCLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_SS0_B] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_XSPI1_SS1_B] = SM_SCMI_PERM_ALL, \
        .rstPerms[DEV_SM_RST_ECAT_IP_RESETN] = SM_SCMI_PERM_ALL, \
        .rtcPerms[BRD_SM_RTC_PCA2131] = SM_SCMI_PERM_PRIV, \
        .rtcPerms[DEV_SM_RTC_BBNSM] = SM_SCMI_PERM_ALL, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF09] = SM_SCMI_PERM_ALL, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF53] = SM_SCMI_PERM_SET, \
        .sensorPerms[DEV_SM_SENSOR_TEMP_A55] = SM_SCMI_PERM_ALL, \
        .sensorPerms[DEV_SM_SENSOR_TEMP_ANA] = SM_SCMI_PERM_SET, \
        .sysPerms = SM_SCMI_PERM_NOTIFY, \
    }

/*! Config for SCMI channel 12 */
#define SM_SCMI_CHN12_CONFIG \
    { \
        .agentId = 5U, \
        .type = SM_SCMI_CHN_A2P, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 12U, \
    }

/*! Config for SCMI channel 13 */
#define SM_SCMI_CHN13_CONFIG \
    { \
        .agentId = 5U, \
        .type = SM_SCMI_CHN_P2A_NOTIFY, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 13U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI Instance 3 Config (AP)                                              */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI instance 3 */
#define SM_SCMI3_CONFIG \
    { \
        .lmId = 4U, \
        .numAgents = 2U, \
        .firstAgent = 4U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI Agent Config                                                        */
/*--------------------------------------------------------------------------*/

/*! Config for number of SCMI agents */
#define SM_SCMI_NUM_AGNT  6U

/*! Config data array for SCMI agents */
#define SM_SCMI_AGNT_CONFIG_DATA \
    SM_SCMI_AGNT0_CONFIG, \
    SM_SCMI_AGNT1_CONFIG, \
    SM_SCMI_AGNT2_CONFIG, \
    SM_SCMI_AGNT3_CONFIG, \
    SM_SCMI_AGNT4_CONFIG, \
    SM_SCMI_AGNT5_CONFIG

/*--------------------------------------------------------------------------*/
/* SCMI Channel Config                                                      */
/*--------------------------------------------------------------------------*/

/*! Config for number of SCMI channels */
#define SM_SCMI_NUM_CHN  14U

/*! Config data array for SCMI channels */
#define SM_SCMI_CHN_CONFIG_DATA \
    SM_SCMI_CHN0_CONFIG, \
    SM_SCMI_CHN1_CONFIG, \
    SM_SCMI_CHN2_CONFIG, \
    SM_SCMI_CHN3_CONFIG, \
    SM_SCMI_CHN4_CONFIG, \
    SM_SCMI_CHN5_CONFIG, \
    SM_SCMI_CHN6_CONFIG, \
    SM_SCMI_CHN7_CONFIG, \
    SM_SCMI_CHN8_CONFIG, \
    SM_SCMI_CHN9_CONFIG, \
    SM_SCMI_CHN10_CONFIG, \
    SM_SCMI_CHN11_CONFIG, \
    SM_SCMI_CHN12_CONFIG, \
    SM_SCMI_CHN13_CONFIG

/*--------------------------------------------------------------------------*/
/* SCMI Config                                                              */
/*--------------------------------------------------------------------------*/

/*! Config for number of SCMI instances */
#define SM_NUM_SCMI  4U

/*! Config data array for SCMI instances */
#define SM_SCMI_CONFIG_DATA \
    SM_SCMI0_CONFIG, \
    SM_SCMI1_CONFIG, \
    SM_SCMI2_CONFIG, \
    SM_SCMI3_CONFIG

/*! Max words to buffer for notification messages */
#define SM_SCMI_MAX_NOTIFY  24U

#endif /* CONFIG_SCMI_H */

/** @} */

