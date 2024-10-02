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
 * @addtogroup CONFIG_SIMU
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
        .basePerms[DEV_SM_BASE_DEV_TEST] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_0] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_1] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_2] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_3] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_6] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_7] = SM_SCMI_PERM_ALL, \
        .fusaPerms = SM_SCMI_PERM_ALL, \
        .gprPerms[DEV_SM_GPR_0] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_1] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_4] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_RESV] = SM_SCMI_PERM_ALL, \
        .sensorPerms[DEV_SM_SENSOR_0] = SM_SCMI_PERM_ALL, \
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
        .seenvId = 2U, \
        .basePerms[DEV_SM_BASE_DEV_TEST] = SM_SCMI_PERM_PRIV, \
        .buttonPerms[DEV_SM_BUTTON_0] = SM_SCMI_PERM_NOTIFY, \
        .clkPerms[DEV_SM_CLK_0] = SM_SCMI_PERM_GET, \
        .clkPerms[DEV_SM_CLK_1] = SM_SCMI_PERM_ALL, \
        .cpuPerms[DEV_SM_CPU_2] = SM_SCMI_PERM_ALL, \
        .ctrlPerms[DEV_SM_CTRL_TEST] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_4] = SM_SCMI_PERM_ALL, \
        .faultPerms[DEV_SM_FAULT_5] = SM_SCMI_PERM_ALL, \
        .gprPerms[DEV_SM_GPR_1] = SM_SCMI_PERM_ALL, \
        .lmmPerms[1] = SM_SCMI_PERM_ALL, \
        .lmmPerms[2] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_2] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_3] = SM_SCMI_PERM_ALL, \
        .pdPerms[DEV_SM_PD_4] = SM_SCMI_PERM_GET, \
        .pdPerms[DEV_SM_PD_5] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_0] = SM_SCMI_PERM_ALL, \
        .perfPerms[DEV_SM_PERF_1] = SM_SCMI_PERM_SET, \
        .perlpiPerms[DEV_SM_PERLPI_RESV] = SM_SCMI_PERM_ALL, \
        .rstPerms[DEV_SM_RST_1] = SM_SCMI_PERM_ALL, \
        .sensorPerms[DEV_SM_SENSOR_1] = SM_SCMI_PERM_ALL, \
        .sysPerms = SM_SCMI_PERM_ALL, \
        .voltPerms[DEV_SM_VOLT_1] = SM_SCMI_PERM_SET, \
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
        .seenvId = 3U, \
        .basePerms[DEV_SM_BASE_AGENT_1] = SM_SCMI_PERM_ALL, \
        .buttonPerms[DEV_SM_BUTTON_0] = SM_SCMI_PERM_ALL, \
        .clkPerms[DEV_SM_CLK_2] = SM_SCMI_PERM_ALL, \
        .daisyPerms[DEV_SM_DAISY_0] = SM_SCMI_PERM_ALL, \
        .gprPerms[DEV_SM_GPR_2] = SM_SCMI_PERM_ALL, \
        .lmmPerms[1] = SM_SCMI_PERM_NOTIFY, \
        .lmmPerms[2] = SM_SCMI_PERM_GET, \
        .pdPerms[DEV_SM_PD_6] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_RESV] = SM_SCMI_PERM_ALL, \
        .pinPerms[DEV_SM_PIN_0] = SM_SCMI_PERM_ALL, \
        .rstPerms[DEV_SM_RST_2] = SM_SCMI_PERM_ALL, \
        .rtcPerms[BRD_SM_RTC_PMIC] = SM_SCMI_PERM_ALL, \
        .rtcPerms[DEV_SM_RTC_BBNSM] = SM_SCMI_PERM_ALL, \
        .sensorPerms[BRD_SM_SENSOR_0] = SM_SCMI_PERM_ALL, \
        .voltPerms[DEV_SM_VOLT_2] = SM_SCMI_PERM_ALL, \
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
/* SCMI AGENT3 Config (TEST-NS)                                             */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI agent 3 */
#define SM_SCMI_AGNT3_CONFIG \
    { \
        .name = "TEST-NS", \
        .scmiInst = 2U, \
        .domId = 16U, \
        .secure = 0U, \
        .seenvId = 4U, \
        .cpuPerms[DEV_SM_CPU_2] = SM_SCMI_PERM_ALL, \
        .perlpiPerms[DEV_SM_PERLPI_RESV] = SM_SCMI_PERM_ALL, \
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

/*--------------------------------------------------------------------------*/
/* SCMI Instance 2 Config (TEST)                                            */
/*--------------------------------------------------------------------------*/

/*! Config for SCMI instance 2 */
#define SM_SCMI2_CONFIG \
    { \
        .lmId = 3U, \
        .numAgents = 1U, \
        .firstAgent = 3U, \
    }

/*--------------------------------------------------------------------------*/
/* SCMI Agent Config                                                        */
/*--------------------------------------------------------------------------*/

/*! Config for number of SCMI agents */
#define SM_SCMI_NUM_AGNT  4U

/*! Config data array for SCMI agents */
#define SM_SCMI_AGNT_CONFIG_DATA \
    SM_SCMI_AGNT0_CONFIG, \
    SM_SCMI_AGNT1_CONFIG, \
    SM_SCMI_AGNT2_CONFIG, \
    SM_SCMI_AGNT3_CONFIG

/*--------------------------------------------------------------------------*/
/* SCMI Channel Config                                                      */
/*--------------------------------------------------------------------------*/

/*! Config for number of SCMI channels */
#define SM_SCMI_NUM_CHN  9U

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
    SM_SCMI_CHN8_CONFIG

/*--------------------------------------------------------------------------*/
/* SCMI Config                                                              */
/*--------------------------------------------------------------------------*/

/*! Config for number of SCMI instances */
#define SM_NUM_SCMI  3U

/*! Config data array for SCMI instances */
#define SM_SCMI_CONFIG_DATA \
    SM_SCMI0_CONFIG, \
    SM_SCMI1_CONFIG, \
    SM_SCMI2_CONFIG

/*! Max words to buffer for notification messages */
#define SM_SCMI_MAX_NOTIFY  24U

#endif /* CONFIG_SCMI_H */

/** @} */

