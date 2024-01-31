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
/* Unit test for the SCMI BBM GPR protocol.                                 */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiGprGet(bool pass, uint32_t channel,
    uint32_t resource);
static void TEST_ScmiGprExclusive(bool pass, uint32_t channel,
    uint32_t resource);

/*--------------------------------------------------------------------------*/
/* Test SCMI BBM GPR protocol                                               */
/*--------------------------------------------------------------------------*/
void TEST_ScmiBbmGpr(void)
{
    int32_t status;
    uint32_t numGpr;
    uint32_t agentId, channel, resource, lmId;

    /* RPC_00230 BBM tests */
    printf("**** Battery-backed Module GPR Protocol Tests ***\n\n");

    /* Test protocol attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_BbmProtocolAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_BbmProtocolAttributes(SM_TEST_DEFAULT_CHN,
            &attributes));
        numGpr = SCMI_BBM_PROTO_ATTR_NUM_GPR(attributes);
        printf("  numGpr=%u\n", numGpr);
    }

    /* Test for invalid GPR Get and invalid channel*/
    {
        NECHECK(SCMI_BbmGprGet(SM_TEST_DEFAULT_CHN, numGpr, NULL),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_BbmGprGet(SM_SCMI_NUM_CHN, numGpr, NULL),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Test for invalid GPR Set and invalid channel */
    {
        NECHECK(SCMI_BbmGprSet(SM_TEST_DEFAULT_CHN, numGpr, 4U),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_BbmGprSet(SM_SCMI_NUM_CHN, numGpr, 4U),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Loop over BBM test resources */
    status = TEST_ConfigFirstGet(TEST_GPR, &agentId,
        &channel, &resource, &lmId);
    while (status == SCMI_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].gprPerms[resource];

        /* Test functions with GET perm required */
        TEST_ScmiGprGet(perm >= SM_SCMI_PERM_GET, channel, resource);

        /* Test functions with EXCLUSIVE perm required */
        TEST_ScmiGprExclusive(perm >= SM_SCMI_PERM_EXCLUSIVE,
            channel, resource);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_GPR, &agentId,
            &channel, &resource, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI BBM functions with GET access                                  */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiGprGet(bool pass, uint32_t channel,
    uint32_t resource)
{
    uint32_t value = 0U;

    printf("SCMI_BbmGprGet(%u, %u)\n", channel, resource);
    XCHECK(pass, SCMI_BbmGprGet(channel, resource, &value));

    XCHECK(pass, SCMI_BbmGprGet(channel, resource, NULL));
}

/*--------------------------------------------------------------------------*/
/* Test SCMI BBM functions with EXCLUSIVE access                            */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiGprExclusive(bool pass, uint32_t channel,
    uint32_t resource)
{
    uint32_t value = 0U;

    /* RPC_00240 Test read/write GPR */
    printf("SCMI_BbmGprSet(%u, %u, %u)\n", channel, resource, 500U);
    XCHECK(pass, SCMI_BbmGprSet(channel, resource, 500U));

    if (pass)
    {
        printf("SCMI_BbmGprGet(%u, %u)\n", channel, resource);
        CHECK(SCMI_BbmGprGet(channel, resource, &value));
        BCHECK(value == 500U);
    }
}

