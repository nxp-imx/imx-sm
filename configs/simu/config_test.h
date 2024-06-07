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
 * Header file containing coniguration info for the unit tests.
 */
/*==========================================================================*/

#ifndef CONFIG_TEST_H
#define CONFIG_TEST_H

/* Defines */

/*--------------------------------------------------------------------------*/
/* LM0 Test Config (SM)                                                     */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* LM1 Test Config (M7)                                                     */
/*--------------------------------------------------------------------------*/

/*! Config for test channel 0 */
#define SM_TEST_CHN0_CONFIG \
    { \
        .mbInst = 0U, \
        .mbDoorbell = 0U, \
        .agentId = 0U, \
    }

/*! Config for test channel 1 */
#define SM_TEST_CHN1_CONFIG \
    { \
        .mbInst = 0U, \
        .mbDoorbell = 1U, \
        .agentId = 0U, \
    }

/*! Config for test channel 2 */
#define SM_TEST_CHN2_CONFIG \
    { \
        .mbInst = 0U, \
        .mbDoorbell = 2U, \
        .agentId = 0U, \
    }

/*--------------------------------------------------------------------------*/
/* LM2 Test Config (AP)                                                     */
/*--------------------------------------------------------------------------*/

/*! Config for test channel 3 */
#define SM_TEST_CHN3_CONFIG \
    { \
        .mbInst = 1U, \
        .mbDoorbell = 0U, \
        .agentId = 1U, \
    }

/*! Config for test channel 4 */
#define SM_TEST_CHN4_CONFIG \
    { \
        .mbInst = 1U, \
        .mbDoorbell = 1U, \
        .agentId = 1U, \
    }

/*! Config for test channel 5 */
#define SM_TEST_CHN5_CONFIG \
    { \
        .mbInst = 2U, \
        .mbDoorbell = 0U, \
        .agentId = 2U, \
    }

/*! Config for test channel 6 */
#define SM_TEST_CHN6_CONFIG \
    { \
        .mbInst = 2U, \
        .mbDoorbell = 1U, \
        .agentId = 2U, \
    }

/*--------------------------------------------------------------------------*/
/* Test Channel Config                                                      */
/*--------------------------------------------------------------------------*/

/*! Config for number of test channels */
#define SM_NUM_TEST_CHN  7U

/*! Config data array for test channels */
#define SM_TEST_CHN_CONFIG_DATA \
    SM_TEST_CHN0_CONFIG, \
    SM_TEST_CHN1_CONFIG, \
    SM_TEST_CHN2_CONFIG, \
    SM_TEST_CHN3_CONFIG, \
    SM_TEST_CHN4_CONFIG, \
    SM_TEST_CHN5_CONFIG, \
    SM_TEST_CHN6_CONFIG

/*--------------------------------------------------------------------------*/
/* Test Config                                                              */
/*--------------------------------------------------------------------------*/

/*! Config for number of tests */
#define SM_SCMI_NUM_TEST  36U

/*! Config data array for tests */
#define SM_SCMI_TEST_CONFIG_DATA \
    {.testId = TEST_BASE, .channel = 0U, .rsrc = DEV_SM_BASE_AGENT_1}, \
    {.testId = TEST_BUTTON, .channel = 0U, .rsrc = DEV_SM_BUTTON_0}, \
    {.testId = TEST_BUTTON, .channel = 5U, .rsrc = DEV_SM_BUTTON_0}, \
    {.testId = TEST_CLK, .channel = 3U, .rsrc = DEV_SM_CLK_0}, \
    {.testId = TEST_CLK, .channel = 5U, .rsrc = DEV_SM_CLK_2}, \
    {.testId = TEST_CPU, .channel = 0U, .rsrc = DEV_SM_CPU_1}, \
    {.testId = TEST_CPU, .channel = 3U, .rsrc = DEV_SM_CPU_2}, \
    {.testId = TEST_CTRL, .channel = 3U, .rsrc = DEV_SM_CTRL_TEST}, \
    {.testId = TEST_CTRL, .channel = 5U, .rsrc = DEV_SM_CTRL_TEST}, \
    {.testId = TEST_GPR, .channel = 5U, .rsrc = DEV_SM_GPR_2}, \
    {.testId = TEST_GPR, .channel = 5U, .rsrc = DEV_SM_GPR_3}, \
    {.testId = TEST_LMM, .channel = 0U, .rsrc = 2U}, \
    {.testId = TEST_LMM, .channel = 3U, .rsrc = 1U}, \
    {.testId = TEST_PD, .channel = 3U, .rsrc = DEV_SM_PD_2}, \
    {.testId = TEST_PD, .channel = 3U, .rsrc = DEV_SM_PD_4}, \
    {.testId = TEST_PD, .channel = 5U, .rsrc = DEV_SM_PD_6}, \
    {.testId = TEST_PERF, .channel = 3U, .rsrc = DEV_SM_PERF_0}, \
    {.testId = TEST_PERF, .channel = 3U, .rsrc = DEV_SM_PERF_1}, \
    {.testId = TEST_PERF, .channel = 5U, .rsrc = DEV_SM_PERF_1}, \
    {.testId = TEST_PIN, .channel = 5U, .rsrc = DEV_SM_PIN_0}, \
    {.testId = TEST_RST, .channel = 0U, .rsrc = DEV_SM_RST_0}, \
    {.testId = TEST_RST, .channel = 3U, .rsrc = DEV_SM_RST_1}, \
    {.testId = TEST_RST, .channel = 5U, .rsrc = DEV_SM_RST_2}, \
    {.testId = TEST_RTC, .channel = 0U, .rsrc = DEV_SM_RTC_BBNSM}, \
    {.testId = TEST_RTC, .channel = 5U, .rsrc = BRD_SM_RTC_PMIC}, \
    {.testId = TEST_RTC, .channel = 5U, .rsrc = DEV_SM_RTC_BBNSM}, \
    {.testId = TEST_SENSOR, .channel = 0U, .rsrc = DEV_SM_SENSOR_0}, \
    {.testId = TEST_SENSOR, .channel = 0U, .rsrc = DEV_SM_SENSOR_1}, \
    {.testId = TEST_SENSOR, .channel = 3U, .rsrc = DEV_SM_SENSOR_0}, \
    {.testId = TEST_SENSOR, .channel = 3U, .rsrc = DEV_SM_SENSOR_1}, \
    {.testId = TEST_SENSOR, .channel = 5U, .rsrc = BRD_SM_SENSOR_0}, \
    {.testId = TEST_SYS, .channel = 3U, .rsrc = 0U}, \
    {.testId = TEST_SYS, .channel = 5U, .rsrc = 0U}, \
    {.testId = TEST_VOLT, .channel = 0U, .rsrc = DEV_SM_VOLT_1}, \
    {.testId = TEST_VOLT, .channel = 3U, .rsrc = DEV_SM_VOLT_1}, \
    {.testId = TEST_VOLT, .channel = 5U, .rsrc = DEV_SM_VOLT_2}

/*! Default channel for non-agent specific tests */
#define SM_TEST_DEFAULT_CHN  0U

#endif /* CONFIG_TEST_H */

/** @} */

