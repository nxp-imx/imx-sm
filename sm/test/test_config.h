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
 * @file
 * @brief
 *
 * Header file containing the unit test configuration data.
 *
 * @addtogroup TEST TEST: Unit Test
 *
 * @brief Module for unit tests.
 *
 * @{
 */
/*==========================================================================*/

#ifndef TEST_CONFIG_H
#define TEST_CONFIG_H

/* Includes */

#include "config_scmi.h"
#include "rpc_scmi_config.h"

/* Defines */

/* Local defines */

/*!
 * @name Test IDs
 */
/** @{ */
#define TEST_BASE    0U   /*!< Test using base protocol */
#define TEST_PD      1U   /*!< Test using power domain protocol */
#define TEST_SYS     2U   /*!< Test using system power protocol */
#define TEST_PERF    3U   /*!< Test using performance protocol */
#define TEST_CLK     4U   /*!< Test using clock protocol */
#define TEST_SENSOR  5U   /*!< Test using sensor protocol */
#define TEST_RST     6U   /*!< Test using reset protocol */
#define TEST_VOLT    7U   /*!< Test using voltage protocol */
#define TEST_LMM     8U   /*!< Test using LMM protocol */
#define TEST_GPR     9U   /*!< Test using BBM GPR protocol */
#define TEST_RTC     10U  /*!< Test using BBM RTC protocol */
#define TEST_BUTTON  11U  /*!< Test using BBM button protocol */
#define TEST_CPU     12U  /*!< Test using CPU protocol */
#define TEST_PIN     13U  /*!< Test using pin control protocol */
#define TEST_DAISY   14U  /*!< Test using pin daisy protocol */
#define TEST_CTRL    15U  /*!< Test using control protocol */
#define TEST_FUSA    16U  /*!< Test using FuSa EENV protocol */
#define TEST_FAULT   17U  /*!< Test using FuSa fault protocol */
/** @} */

/* Types */

/*!
 * Test channel config structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    uint8_t mbInst;      /*!< Index to MU SDK driver, see MU_BASE_PTRS */
    uint8_t mbDoorbell;  /*!< Mailbox doorbell to use */
    uint8_t agentId;     /*!< Agent ID the test is from */
    uint32_t sma;        /*!< Shared memory address */
} test_chn_config_t;

/*!
 * Test SCMI config structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    uint32_t testId;   /*!< Protocol to test */
    uint32_t channel;  /*!< Test channel to use */
    uint32_t rsrc;     /*!< Resource for test */
} test_scmi_config_t;

/* Functions */

/*!
 * Configure the client API for testing.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by SMT_ChannelConfig()
 */
int32_t TEST_Config(void);

/*!
 * Get first test info from test configuration.
 *
 * @param[in]     testId      Test type
 * @param[out]    agentId     Return agent to test
 * @param[out]    smtChannel  Return channel to use for test
 * @param[out]    rsrc        Return resource to test
 * @param[out]    lmId        Return LM for test
 *
 * Returns the info for the first test of type \a testId.
 * For example ::TEST_BASE.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_OUT_OF_RANGE: if no such test found
 */
int32_t TEST_ConfigFirstGet(uint8_t testId, uint32_t *agentId,
    uint32_t *smtChannel, uint32_t *rsrc, uint32_t *lmId);

/*!
 * Get next test info from test configuration.
 *
 * @param[in]     testId      Test type
 * @param[out]    agentId     Return agent to test
 * @param[out]    smtChannel  Return channel to use for test
 * @param[out]    rsrc        Return resource to test
 * @param[out]    lmId        Return LM for test
 *
 * Returns the info for the next test of type \a testId.
 * For example ::TEST_BASE.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_OUT_OF_RANGE: if no more such tests found
 */
int32_t TEST_ConfigNextGet(uint8_t testId, uint32_t *agentId,
    uint32_t *smtChannel, uint32_t *rsrc, uint32_t *lmId);

#endif /* TEST_CONFIG_H */

/** @} */

