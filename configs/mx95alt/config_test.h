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
 * @addtogroup CONFIG_MX95ALT
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
/* LM1 Test Config (Boot)                                                   */
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
/* Test Channel Config                                                      */
/*--------------------------------------------------------------------------*/

/*! Config for number of test channels */
#define SM_NUM_TEST_CHN  3U

/*! Config data array for test channels */
#define SM_TEST_CHN_CONFIG_DATA \
    SM_TEST_CHN0_CONFIG, \
    SM_TEST_CHN1_CONFIG, \
    SM_TEST_CHN2_CONFIG

/*--------------------------------------------------------------------------*/
/* Test Config                                                              */
/*--------------------------------------------------------------------------*/

/*! Config for number of tests */
#define SM_SCMI_NUM_TEST  0U

/*! Config data array for tests */
#define SM_SCMI_TEST_CONFIG_DATA

/*! Default channel for non-agent specific tests */
#define SM_TEST_DEFAULT_CHN  0U

#endif /* CONFIG_TEST_H */

/** @} */

