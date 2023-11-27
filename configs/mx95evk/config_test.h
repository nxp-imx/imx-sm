/*
** ###################################################################
**
** Copyright 2023 NXP
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
        .mbInst = 8U, \
        .mbDoorbell = 0U, \
        .agentId = 0U, \
    }

/*! Config for test channel 1 */
#define SM_TEST_CHN1_CONFIG \
    { \
        .mbInst = 8U, \
        .mbDoorbell = 1U, \
        .agentId = 0U, \
    }

/*! Config for test channel 2 */
#define SM_TEST_CHN2_CONFIG \
    { \
        .mbInst = 8U, \
        .mbDoorbell = 2U, \
        .agentId = 0U, \
    }

/*--------------------------------------------------------------------------*/
/* LM2 Test Config (AP)                                                     */
/*--------------------------------------------------------------------------*/

/*! Config for test channel 3 */
#define SM_TEST_CHN3_CONFIG \
    { \
        .mbInst = 0U, \
        .mbDoorbell = 0U, \
        .agentId = 1U, \
    }

/*! Config for test channel 4 */
#define SM_TEST_CHN4_CONFIG \
    { \
        .mbInst = 0U, \
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
#define SM_SCMI_NUM_TEST  32U

/*! Config data array for tests */
#define SM_SCMI_TEST_CONFIG_DATA \
    {.testId = TEST_BUTTON, .channel = 5U, .rsrc = DEV_SM_BUTTON_0}, \
    {.testId = TEST_CLK, .channel = 0U, .rsrc = DEV_SM_CLK_LPUART3}, \
    {.testId = TEST_CLK, .channel = 5U, .rsrc = DEV_SM_CLK_CAMCM0}, \
    {.testId = TEST_CLK, .channel = 5U, .rsrc = DEV_SM_CLK_DISPOCRAM}, \
    {.testId = TEST_CLK, .channel = 5U, .rsrc = DEV_SM_CLK_ENETREF}, \
    {.testId = TEST_CLK, .channel = 5U, .rsrc = DEV_SM_CLK_ENETTIMER1}, \
    {.testId = TEST_CLK, .channel = 5U, .rsrc = DEV_SM_CLK_LPUART8}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART3_CTS}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART3_RXD}, \
    {.testId = TEST_DAISY, .channel = 0U, .rsrc = DEV_SM_DAISY_LPUART3_TXD}, \
    {.testId = TEST_DAISY, .channel = 5U, .rsrc = DEV_SM_DAISY_NETC_EMDC}, \
    {.testId = TEST_DAISY, .channel = 5U, .rsrc = DEV_SM_DAISY_NETC_EMDIO}, \
    {.testId = TEST_DAISY, .channel = 5U, .rsrc = DEV_SM_DAISY_NETC_ETH0_RMII_RX_ER}, \
    {.testId = TEST_DAISY, .channel = 5U, .rsrc = DEV_SM_DAISY_NETC_ETH1_RMII_RX_ER}, \
    {.testId = TEST_DAISY, .channel = 5U, .rsrc = DEV_SM_DAISY_NETC_TMR_1588_TRIG1}, \
    {.testId = TEST_DAISY, .channel = 5U, .rsrc = DEV_SM_DAISY_NETC_TMR_1588_TRIG2}, \
    {.testId = TEST_GPR, .channel = 5U, .rsrc = DEV_SM_GPR_4}, \
    {.testId = TEST_PD, .channel = 0U, .rsrc = DEV_SM_PD_A55P}, \
    {.testId = TEST_PD, .channel = 0U, .rsrc = DEV_SM_PD_M7}, \
    {.testId = TEST_PD, .channel = 5U, .rsrc = DEV_SM_PD_CAMERA}, \
    {.testId = TEST_PD, .channel = 5U, .rsrc = DEV_SM_PD_CAMERA}, \
    {.testId = TEST_PD, .channel = 5U, .rsrc = DEV_SM_PD_DISPLAY}, \
    {.testId = TEST_PD, .channel = 5U, .rsrc = DEV_SM_PD_GPU}, \
    {.testId = TEST_PD, .channel = 5U, .rsrc = DEV_SM_PD_HSIO_TOP}, \
    {.testId = TEST_PD, .channel = 5U, .rsrc = DEV_SM_PD_NPU}, \
    {.testId = TEST_PD, .channel = 5U, .rsrc = DEV_SM_PD_VPU}, \
    {.testId = TEST_PERF, .channel = 5U, .rsrc = DEV_SM_PERF_CAM}, \
    {.testId = TEST_PERF, .channel = 5U, .rsrc = DEV_SM_PERF_DISP}, \
    {.testId = TEST_PERF, .channel = 5U, .rsrc = DEV_SM_PERF_NPU}, \
    {.testId = TEST_PERF, .channel = 5U, .rsrc = DEV_SM_PERF_VPU}, \
    {.testId = TEST_PIN, .channel = 5U, .rsrc = DEV_SM_PIN_UART1_RXD}, \
    {.testId = TEST_RTC, .channel = 5U, .rsrc = DEV_SM_RTC_BBM}

/*! Default channel for non-agent specific tests */
#define SM_TEST_DEFAULT_CHN  0U

#endif /* CONFIG_TEST_H */

/** @} */

