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
/* Code to obtain test config data.                                         */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include <stdlib.h>
#include "test.h"
#include "test_config.h"
#include "config_test.h"
#include "smt.h"

/* Local defines */

/* Local types */

/* Local variables */

static const test_chn_config_t s_testConfig[SM_NUM_TEST_CHN] =
{
    SM_TEST_CHN_CONFIG_DATA
};

static uint32_t s_testIndex = 0U;

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Configure for running tests                                              */
/*--------------------------------------------------------------------------*/
int32_t TEST_Config(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Load test config into client API */
    for (uint32_t channel = 0U; channel < SM_NUM_TEST_CHN; channel++)
    {
        /* Configure client channel */
        status = SMT_ChannelConfig(channel, s_testConfig[channel].mbInst,
            s_testConfig[channel].mbDoorbell, s_testConfig[channel].sma);

        /* Exit if error */
        if (status != SM_ERR_SUCCESS)
        {
            break;
        }
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Return first matching test case                                          */
/*--------------------------------------------------------------------------*/
int32_t TEST_ConfigFirstGet(uint8_t testId, uint32_t *agentId,
    uint32_t *smtChannel, uint32_t *rsrc, uint32_t *lmId)
{
    s_testIndex = 0U;

    return TEST_ConfigNextGet(testId, agentId, smtChannel, rsrc, lmId);
}

/*--------------------------------------------------------------------------*/
/* Return next matching test case                                           */
/*--------------------------------------------------------------------------*/
int32_t TEST_ConfigNextGet(uint8_t testId, uint32_t *agentId,
    uint32_t *smtChannel, uint32_t *rsrc, uint32_t *lmId)
{
    int32_t status = SM_ERR_OUT_OF_RANGE;

#if SM_SCMI_NUM_TEST > 0
    static const test_scmi_config_t s_testScmiConfig[SM_SCMI_NUM_TEST] =
    {
        SM_SCMI_TEST_CONFIG_DATA
    };

    while (s_testIndex < SM_SCMI_NUM_TEST)
    {
        if (s_testScmiConfig[s_testIndex].testId == testId)
        {
            /* Return test info */
            *smtChannel = s_testScmiConfig[s_testIndex].channel;
            *rsrc = s_testScmiConfig[s_testIndex].rsrc;
            *agentId = s_testConfig[*smtChannel].agentId;

            /* Logical Machine info */
            uint8_t inst = g_scmiAgentConfig[*agentId].scmiInst;
            *lmId = g_scmiConfig[inst].lmId;

            /* Increment test */
            s_testIndex++;

            /* Exit and return result */
            status = SM_ERR_SUCCESS;
            break;
        }
        else
        {
            /* Increment test */
            s_testIndex++;
        }
    }
#endif

    return status;
}

