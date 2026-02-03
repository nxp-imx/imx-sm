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
 * @addtogroup CONFIG_MX94ALT
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing configuration info for the unit tests.
 */
/*==========================================================================*/

#ifndef CONFIG_TEST_H
#define CONFIG_TEST_H

/* Includes */

#include "config_user.h"

/* Defines */

/*--------------------------------------------------------------------------*/
/* LM0 Test Config (SM)                                                     */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* LM1 Test Config (Boot)                                                   */
/*--------------------------------------------------------------------------*/

/*! Config for test channel 0 */
#define SM_TEST_CHN0_CONFIG \
    { \
        .mbInst = 14U, \
        .mbDoorbell = 0U, \
        .agentId = 0U, \
    }

/*! Config for test channel 1 */
#define SM_TEST_CHN1_CONFIG \
    { \
        .mbInst = 14U, \
        .mbDoorbell = 1U, \
        .agentId = 0U, \
    }

/*! Config for test channel 2 */
#define SM_TEST_CHN2_CONFIG \
    { \
        .mbInst = 14U, \
        .mbDoorbell = 2U, \
        .agentId = 0U, \
    }

/*! Config for test channel 3 */
#define SM_TEST_CHN3_CONFIG \
    { \
        .mbInst = 16U, \
        .mbDoorbell = 0U, \
        .agentId = 1U, \
    }

/*! Config for test channel 4 */
#define SM_TEST_CHN4_CONFIG \
    { \
        .mbInst = 16U, \
        .mbDoorbell = 1U, \
        .agentId = 1U, \
    }

/*! Config for test channel 5 */
#define SM_TEST_CHN5_CONFIG \
    { \
        .mbInst = 8U, \
        .mbDoorbell = 0U, \
        .agentId = 2U, \
    }

/*! Config for test channel 6 */
#define SM_TEST_CHN6_CONFIG \
    { \
        .mbInst = 8U, \
        .mbDoorbell = 1U, \
        .agentId = 2U, \
    }

/*! Config for test channel 7 */
#define SM_TEST_CHN7_CONFIG \
    { \
        .mbInst = 12U, \
        .mbDoorbell = 0U, \
        .agentId = 3U, \
    }

/*! Config for test channel 8 */
#define SM_TEST_CHN8_CONFIG \
    { \
        .mbInst = 12U, \
        .mbDoorbell = 1U, \
        .agentId = 3U, \
    }

/*! Config for test channel 9 */
#define SM_TEST_CHN9_CONFIG \
    { \
        .mbInst = 0U, \
        .mbDoorbell = 0U, \
        .agentId = 4U, \
    }

/*! Config for test channel 10 */
#define SM_TEST_CHN10_CONFIG \
    { \
        .mbInst = 0U, \
        .mbDoorbell = 1U, \
        .agentId = 4U, \
    }

/*! Config for test channel 11 */
#define SM_TEST_CHN11_CONFIG \
    { \
        .mbInst = 2U, \
        .mbDoorbell = 0U, \
        .agentId = 5U, \
    }

/*! Config for test channel 12 */
#define SM_TEST_CHN12_CONFIG \
    { \
        .mbInst = 2U, \
        .mbDoorbell = 1U, \
        .agentId = 5U, \
    }

/*--------------------------------------------------------------------------*/
/* Test Channel Config                                                      */
/*--------------------------------------------------------------------------*/

/*! Config for number of test channels */
#define SM_NUM_TEST_CHN  13U

/*! Config data array for test channels */
#define SM_TEST_CHN_CONFIG_DATA \
    SM_TEST_CHN0_CONFIG, \
    SM_TEST_CHN1_CONFIG, \
    SM_TEST_CHN2_CONFIG, \
    SM_TEST_CHN3_CONFIG, \
    SM_TEST_CHN4_CONFIG, \
    SM_TEST_CHN5_CONFIG, \
    SM_TEST_CHN6_CONFIG, \
    SM_TEST_CHN7_CONFIG, \
    SM_TEST_CHN8_CONFIG, \
    SM_TEST_CHN9_CONFIG, \
    SM_TEST_CHN10_CONFIG, \
    SM_TEST_CHN11_CONFIG, \
    SM_TEST_CHN12_CONFIG

/*--------------------------------------------------------------------------*/
/* Test Config                                                              */
/*--------------------------------------------------------------------------*/

/*! Config for number of tests */
#define SM_SCMI_NUM_TEST  34U

/*! Config data array for tests */
#define SM_SCMI_TEST_CONFIG_DATA \
    {.testId = TEST_BUTTON, .channel = 0U, .rsrc = DEV_SM_BUTTON_0}, \
    {.testId = TEST_CLK, .channel = 0U, .rsrc = DEV_SM_CLK_LPUART3}, \
    {.testId = TEST_CLK, .channel = 0U, .rsrc = DEV_SM_CLK_LPUART4}, \
    {.testId = TEST_CLK, .channel = 0U, .rsrc = DEV_SM_CLK_LPUART5}, \
    {.testId = TEST_CLK, .channel = 0U, .rsrc = DEV_SM_CLK_LPUART8}, \
    {.testId = TEST_CLK, .channel = 0U, .rsrc = DEV_SM_CLK_NPU_CGC}, \
    {.testId = TEST_CLK, .channel = 0U, .rsrc = DEV_SM_CLK_SAI1}, \
    {.testId = TEST_CTRL, .channel = 0U, .rsrc = DEV_SM_CTRL_MQS1_SETTINGS}, \
    {.testId = TEST_CTRL, .channel = 0U, .rsrc = DEV_SM_CTRL_SAI1_MCLK}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART3_CTS}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART3_RXD}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART3_TXD}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART4_CTS}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART4_RXD}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART4_TXD}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART5_CTS}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART5_RXD}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART5_TXD}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART8_RXD}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART8_TXD}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_SAI1_MCLK}, \
    {.testId = TEST_GPR, .channel = 0U, .rsrc = DEV_SM_GPR_4}, \
    {.testId = TEST_PD, .channel = 0U, .rsrc = DEV_SM_PD_HSIO_TOP}, \
    {.testId = TEST_PD, .channel = 0U, .rsrc = DEV_SM_PD_M70}, \
    {.testId = TEST_PD, .channel = 0U, .rsrc = DEV_SM_PD_M71}, \
    {.testId = TEST_PD, .channel = 0U, .rsrc = DEV_SM_PD_NPU}, \
    {.testId = TEST_PD, .channel = 0U, .rsrc = DEV_SM_PD_NPU}, \
    {.testId = TEST_PERF, .channel = 0U, .rsrc = DEV_SM_PERF_NPU}, \
    {.testId = TEST_PERLPI, .channel = 0U, .rsrc = DEV_SM_PERLPI_LPUART3}, \
    {.testId = TEST_PERLPI, .channel = 0U, .rsrc = DEV_SM_PERLPI_LPUART4}, \
    {.testId = TEST_PERLPI, .channel = 0U, .rsrc = DEV_SM_PERLPI_LPUART5}, \
    {.testId = TEST_PERLPI, .channel = 0U, .rsrc = DEV_SM_PERLPI_LPUART8}, \
    {.testId = TEST_RTC, .channel = 0U, .rsrc = DEV_SM_RTC_BBNSM}, \
    {.testId = TEST_RTC, .channel = 0U, .rsrc = DEV_SM_RTC_BBNSM}

/*! Default channel for non-agent specific tests */
#define SM_TEST_DEFAULT_CHN  0U

#endif /* CONFIG_TEST_H */

/** @} */

