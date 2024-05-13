/*
** ###################################################################
**
** Copyright 2023-2024 NXP
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
 * @addtogroup CONFIG_MX95EVK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing coniguration info for the SCMI RPC.
 */
/*==========================================================================*/

#ifndef CONFIG_SCMI_H
#define CONFIG_SCMI_H

/* Defines */

/*--------------------------------------------------------------------------*/
/* SCMI AGENT0 Config (M7)                                                  */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI agent 0 */
#define SM_SCMI_AGNT0_CONFIG \
    { \
        .name = "M7", \
        .scmiInst = 0U, \
        .domId = 4U, \
        .secure = 0U, \
        .seenvId = 1U, \
        .buttonPerms[DEV_SM_BUTTON_0] = SM_SCMI_PERM_NOTIFY, \
        .clkPerms[DEV_SM_CLK_CAN1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPTMR1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPTMR2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_M7SYSTICK] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_M7] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_TSTMR2] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_M7P] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[BRD_SM_CTRL_BUTTON] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_TEST] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_CAN1_RX] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPTMR2_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPTMR2_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPTMR2_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART3_CTS] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART3_RXD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPUART3_TXD] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_M7_LOCKUP] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_M7_RESET] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_SW0] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_SW1] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_WDOG5] = SM_SCMI_PERM_ALL, \
        .fusaPerms = SM_SCMI_PERM_EXCLUSIVE, \
        .lmmPerms[2] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_M7] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_M7] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN1] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG5] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO14] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO15] = SM_SCMI_PERM_ALL, \
        .rtcPerms[BRD_SM_RTC_PCA2131] = SM_SCMI_PERM_ALL, \
        .rtcPerms[DEV_SM_RTC_BBNSM] = SM_SCMI_PERM_PRIV, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF09] = SM_SCMI_PERM_SET, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF5301] = SM_SCMI_PERM_SET, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF5302] = SM_SCMI_PERM_SET, \
        .sensorPerms[DEV_SM_SENSOR_TEMP_ANA] = SM_SCMI_PERM_ALL, \
        .sysPerms = SM_SCMI_PERM_ALL, \
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

/*! Config for SCMI channel 2 */
#define SM_SCMI_CHN2_CONFIG \
    { \
        .agentId = 0U, \
        .type = SM_SCMI_CHN_P2A_PRIORITY, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 2U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI Instance 0 Config (M7)                                              */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI instance 0 */
#define SM_SCMI0_CONFIG \
    { \
        .lmId = 1U, \
        .numAgents = 1U, \
        .firstAgent = 0U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI AGENT1 Config (AP-S)                                                */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI agent 1 */
#define SM_SCMI_AGNT1_CONFIG \
    { \
        .name = "AP-S", \
        .scmiInst = 1U, \
        .domId = 3U, \
        .secure = 1U, \
        .clkPerms[DEV_SM_CLK_A55C0_GPR_SEL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_A55C1_GPR_SEL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_A55C2_GPR_SEL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_A55C3_GPR_SEL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_A55C4_GPR_SEL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_A55C5_GPR_SEL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_A55PERIPH] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_A55P_GPR_SEL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_A55] = SM_SCMI_PERM_ALL, \
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
        .cpuPerms[DEV_SM_CPU_A55C4] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_A55C5] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_A55P] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_SW2] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_WDOG3] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_WDOG4] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_A55C0] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_A55C1] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_A55C2] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_A55C3] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_A55C4] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_A55C5] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_A55P] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_A55] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_DRAM] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN2] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO2] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART1] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART6] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART7] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART8] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG4] = SM_SCMI_PERM_ALL, \
        .sysPerms = SM_SCMI_PERM_ALL, \
    }

/*! Config for SCMI channel 3 */
#define SM_SCMI_CHN3_CONFIG \
    { \
        .agentId = 1U, \
        .type = SM_SCMI_CHN_A2P, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 3U, \
    }

/*! Config for SCMI channel 4 */
#define SM_SCMI_CHN4_CONFIG \
    { \
        .agentId = 1U, \
        .type = SM_SCMI_CHN_P2A_NOTIFY, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 4U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI AGENT2 Config (AP-NS)                                               */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI agent 2 */
#define SM_SCMI_AGNT2_CONFIG \
    { \
        .name = "AP-NS", \
        .scmiInst = 1U, \
        .domId = 3U, \
        .secure = 0U, \
        .buttonPerms[DEV_SM_BUTTON_0] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_AUDIOPLL1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_AUDIOPLL1_VCO] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_AUDIOPLL2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_AUDIOPLL2_VCO] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_AUDIOXCVR] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CAN2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CAN3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CAN4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CAN5] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CCMCKO1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CCMCKO2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CCMCKO3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_CCMCKO4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_DISP1PIX] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_DISP2PIX] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_DISP3PIX] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_DISPOCRAM] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENETREF] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_ENETTIMER1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_EXT1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_EXT2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_EXT] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_EXT_GPR_SEL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_FLEXIO1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_FLEXIO2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_FLEXSPI1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_HSIOPCIEAUX] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_HSIOPLL] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_HSIOPLL_VCO] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_I3C1SLOW] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_I3C1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_I3C2SLOW] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_I3C2] = SM_SCMI_PERM_ALL, \
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
        .clkPerms[DEV_SM_CLK_LPUART1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART5] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART6] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART7] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_LPUART8] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MIPIPHYCFG] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MIPIPHYPLLBYPASS] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MIPIPHYPLLREF] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MIPITESTBYTE] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MQS1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_MQS2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_PDM] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_SAI1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_SAI2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_SAI3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_SAI4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_SAI5] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_SPDIF] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_TPM2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_TPM4] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_TPM5] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_TPM6] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_USBPHYBURUNIN] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_USDHC1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_USDHC2] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_USDHC3] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_V2XPK] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_VIDEOPLL1] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_VIDEOPLL1_VCO] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_VPUDSP] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_XSPISLVROOT] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[BRD_SM_CTRL_BT_WAKE] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_BUTTON] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_PCIE1_WAKE] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_PCIE2_WAKE] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[BRD_SM_CTRL_SD3_WAKE] = SM_SCMI_PERM_NOTIFY, \
        .ctrlPerms[DEV_SM_CTRL_ADC_TEST] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_MQS1_SETTINGS] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_PDM_CLK_SEL] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_SAI1_MCLK] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_SAI3_MCLK] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_SAI4_MCLK] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_SAI5_MCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_CAN2_RX] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_CAN3_RX] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_CAN4_RX] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_CAN5_RX] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_EARC_PHY_SPDIF] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_EXT1_CLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_10] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_11] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_12] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_13] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_14] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_15] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_16] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_17] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_18] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_19] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_20] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_21] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_22] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_23] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_24] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_25] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_26] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_27] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_30] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_31] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_4] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_5] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_6] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_7] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_8] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXIO1_9] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXSPI1_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXSPI1_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXSPI1_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXSPI1_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXSPI1_4] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXSPI1_5] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXSPI1_6] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXSPI1_7] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXSPI1_DQS] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_FLEXSPI1_SCK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_I3C2_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_I3C2_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C3_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C3_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C4_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C4_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C5_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C5_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C6_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C6_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C7_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C7_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C8_SCL] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPI2C8_SDA] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPSPI4_SCK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPSPI4_SDI] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_LPSPI4_SDO] = SM_SCMI_PERM_ALL, \
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
        .daisyPerms[DEV_SM_DAISY_NETC_EMDC] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_EMDIO] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_ETH0_RMII_RX_ER] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_ETH1_RMII_RX_ER] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_TMR_1588_TRIG1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_NETC_TMR_1588_TRIG2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_PDM_BITSTREAM_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_PDM_BITSTREAM_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_PDM_BITSTREAM_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_PDM_BITSTREAM_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI1_MCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI2_RXDATA_6] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI2_RXDATA_7] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI3_RXBCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI3_RXSYNC] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI4_RXBCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI4_RXDATA_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI4_RXSYNC] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI4_TXBCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI4_TXSYNC] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI5_RXBCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI5_RXDATA_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI5_RXDATA_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI5_RXDATA_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI5_RXDATA_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI5_RXSYNC] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI5_TXBCLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_SAI5_TXSYNC] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC3_CLK] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC3_CMD] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC3_DAT0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC3_DAT1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC3_DAT2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_USDHC3_DAT3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_0] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_1] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_3] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_4] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_5] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_6] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_7] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_CS] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_DQS] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_XSPI_SCK] = SM_SCMI_PERM_ALL, \
        .gprPerms[DEV_SM_GPR_4] = SM_SCMI_PERM_ALL, \
        .gprPerms[DEV_SM_GPR_5] = SM_SCMI_PERM_ALL, \
        .gprPerms[DEV_SM_GPR_6] = SM_SCMI_PERM_ALL, \
        .gprPerms[DEV_SM_GPR_7] = SM_SCMI_PERM_ALL, \
        .lmmPerms[1] = SM_SCMI_PERM_NOTIFY, \
        .pdPerms[DEV_SM_PD_CAMERA] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_DISPLAY] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_GPU] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_HSIO_TOP] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_NETC] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_NPU] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_VPU] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_A55] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_CAM] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_DISP] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_DRAM] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_GPU] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_NPU] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_VPU] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN2] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_CAN5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO2] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_GPIO5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART1] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART5] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART6] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART7] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_LPUART8] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG3] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_WDOG4] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_CCM_CLKO1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_CCM_CLKO2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_CCM_CLKO3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_CCM_CLKO4] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_DAP_TCLK_SWCLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_DAP_TDI] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_DAP_TDO_TRACESWO] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_DAP_TMS_SWDIO] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_MDC] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_MDIO] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_RD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_RD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_RD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_RD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_RXC] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_RX_CTL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_TD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_TD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_TD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_TD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_TXC] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET1_TX_CTL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_MDC] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_MDIO] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_RD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_RD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_RD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_RD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_RXC] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_RX_CTL] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_TD0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_TD1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_TD2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_TD3] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_TXC] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_ENET2_TX_CTL] = SM_SCMI_PERM_ALL, \
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
        .pinPerms[DEV_SM_PIN_GPIO_IO16] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO17] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO18] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO19] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO20] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO21] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO22] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO23] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO24] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO25] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO26] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO27] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO28] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO29] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO30] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO31] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO32] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO33] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO34] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO35] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO36] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_GPIO_IO37] = SM_SCMI_PERM_ALL, \
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
        .pinPerms[DEV_SM_PIN_SD2_RESET_B] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD2_VSELECT] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD3_CLK] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD3_CMD] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD3_DATA0] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD3_DATA1] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD3_DATA2] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_SD3_DATA3] = SM_SCMI_PERM_ALL, \
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
        .rtcPerms[DEV_SM_RTC_BBNSM] = SM_SCMI_PERM_ALL, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF09] = SM_SCMI_PERM_ALL, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF5301] = SM_SCMI_PERM_SET, \
        .sensorPerms[BRD_SM_SENSOR_TEMP_PF5302] = SM_SCMI_PERM_SET, \
        .sensorPerms[DEV_SM_SENSOR_TEMP_A55] = SM_SCMI_PERM_ALL, \
        .sensorPerms[DEV_SM_SENSOR_TEMP_ANA] = SM_SCMI_PERM_SET, \
        .sysPerms = SM_SCMI_PERM_NOTIFY, \
    }

/*! Config for SCMI channel 5 */
#define SM_SCMI_CHN5_CONFIG \
    { \
        .agentId = 2U, \
        .type = SM_SCMI_CHN_A2P, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 5U, \
    }

/*! Config for SCMI channel 6 */
#define SM_SCMI_CHN6_CONFIG \
    { \
        .agentId = 2U, \
        .type = SM_SCMI_CHN_P2A_NOTIFY, \
        .xportType = SM_XPORT_SMT, \
        .xportChannel = 6U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI Instance 1 Config (AP)                                              */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI instance 1 */
#define SM_SCMI1_CONFIG \
    { \
        .lmId = 2U, \
        .numAgents = 2U, \
        .firstAgent = 1U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI Agent Config                                                        */
/*--------------------------------------------------------------------------*/

/*! Config for number of SCMI agents */
#define SM_SCMI_NUM_AGNT  3U

/*! Config data array for SCMI agents */
#define SM_SCMI_AGNT_CONFIG_DATA \
    SM_SCMI_AGNT0_CONFIG, \
    SM_SCMI_AGNT1_CONFIG, \
    SM_SCMI_AGNT2_CONFIG

/*--------------------------------------------------------------------------*/
/* SCMI Channel Config                                                      */
/*--------------------------------------------------------------------------*/

/*! Config for number of SCMI channels */
#define SM_SCMI_NUM_CHN  7U

/*! Config data array for SCMI channels */
#define SM_SCMI_CHN_CONFIG_DATA \
    SM_SCMI_CHN0_CONFIG, \
    SM_SCMI_CHN1_CONFIG, \
    SM_SCMI_CHN2_CONFIG, \
    SM_SCMI_CHN3_CONFIG, \
    SM_SCMI_CHN4_CONFIG, \
    SM_SCMI_CHN5_CONFIG, \
    SM_SCMI_CHN6_CONFIG

/*--------------------------------------------------------------------------*/
/* SCMI Config                                                              */
/*--------------------------------------------------------------------------*/

/*! Config for number of SCMI instances */
#define SM_NUM_SCMI  2U

/*! Config data array for SCMI instances */
#define SM_SCMI_CONFIG_DATA \
    SM_SCMI0_CONFIG, \
    SM_SCMI1_CONFIG

/*! Max words to buffer for notification messages */
#define SM_SCMI_MAX_NOTIFY  24U

#endif /* CONFIG_SCMI_H */

/** @} */

