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
/* Unit test for the SCMI reset protocol.                                   */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiResetNone(uint32_t channel, uint32_t domainId);
static void TEST_ScmiResetExclusive(bool pass, uint32_t channel,
    uint32_t domainId, uint32_t lmId);

/*--------------------------------------------------------------------------*/
/* Test SCMI reset protocol                                                 */
/*--------------------------------------------------------------------------*/
void TEST_ScmiReset(void)
{
    uint32_t numDomains = 0U;
    uint32_t agentId, channel, domainId, lmId;
    int32_t status;

    /* RPC_00120 Reset tests */
    printf("**** Reset Protocol Test ****\n\n");

    /* Protocol Version */
    {
        uint32_t ver = 0U;

        printf("SCMI_ResetProtocolVersion(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_ResetProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_RESET_PROT_VER);
    }

    /* Protocol Attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_ResetProtocolAttributes(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_ResetProtocolAttributes(SM_TEST_DEFAULT_CHN,
            &attributes));
        numDomains = SCMI_RESET_PROTO_ATTR_NUM_RESETS(attributes);
        printf("  numDomains=%u\n", numDomains);
    }

    /* Protocol Message Attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_ResetProtocolMessageAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_ResetProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_RESET_DOMAIN_ATTRIBUTES, &attributes));

        /* Check if attributes is 0 */
        BCHECK(attributes == 0U);

        /* Pass in invalid Message ID,
            will come out to SCMI_ERR_NOT_FOUND */
        NECHECK(SCMI_ResetProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            30U, NULL), SCMI_ERR_NOT_FOUND);
    }

    /* Domain Attributes */
    {
        uint32_t attributes = 0U;
        uint32_t latency = 0U;
        uint8_t name[SCMI_RESET_MAX_NAME] = { 0 };

        printf("SCMI_ResetDomainAttributes(%u, %u)\n", SM_TEST_DEFAULT_CHN,
            numDomains);

        /* Domain Attributes -- Invalid domainId  */
        NECHECK(SCMI_ResetDomainAttributes(SM_TEST_DEFAULT_CHN, numDomains,
            &attributes, &latency, name), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_ResetDomainAttributes(SM_SCMI_NUM_CHN, 0U,
            NULL, NULL, NULL), SM_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_ResetDomainAttributes(SM_TEST_DEFAULT_CHN, 0U,
            NULL, NULL, NULL));
    }

    /* Reset */
    {
        /* Reset -- Invalid domainId */
        uint32_t flags = SCMI_RESET_FLAGS_ASYNC(0U) | SCMI_RESET_FLAGS_SIGNAL(0U)
            | SCMI_RESET_FLAGS_AUTO(1U);

        NECHECK(SCMI_Reset(SM_TEST_DEFAULT_CHN, numDomains,
            flags, SCMI_RESET_ARCH_COLD), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_Reset(SM_SCMI_NUM_CHN, 0U,
            flags, SCMI_RESET_ARCH_COLD), SM_ERR_INVALID_PARAMETERS);
    }


    /* Loop over reset test domains */
    status = TEST_ConfigFirstGet(TEST_RST, &agentId,
        &channel, &domainId, &lmId);
    while(status == SCMI_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].rstPerms[domainId];

        /* Test functions with no perm required */
        TEST_ScmiResetNone(channel, domainId);

        /* Test functions with EXCLUSIVE perm required */
        TEST_ScmiResetExclusive(perm >= SM_SCMI_PERM_EXCLUSIVE,
            channel, domainId, lmId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_RST, &agentId,
            &channel, &domainId, &lmId);
    }

    printf("\n");
}

/*--------------------------------------------------------------------------*/
/* Test SCMI control functions with Notify access                           */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiResetNone(uint32_t channel, uint32_t domainId)
{
    /* Domain Attributes */
    {
        uint32_t attributes = 0U;
        uint32_t latency = 0U;
        uint8_t name[SCMI_RESET_MAX_NAME] = { 0 };

        printf("SCMI_ResetDomainAttributes(%u, %u)\n", channel, domainId);
        CHECK(SCMI_ResetDomainAttributes(channel, domainId,
            &attributes, &latency, name));
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI control functions with EXCLUSIVE access                        */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiResetExclusive(bool pass, uint32_t channel,
    uint32_t domainId, uint32_t lmId)
{
    uint32_t flags = 0U;

    /* Access check */
    flags = SCMI_RESET_FLAGS_ASYNC(0U)| SCMI_RESET_FLAGS_SIGNAL(0U)
        | SCMI_RESET_FLAGS_AUTO(1U);

    XECHECK(pass, SCMI_Reset(channel, domainId,
        flags, SCMI_RESET_ARCH_COLD), SCMI_ERR_DENIED);

    if(pass)
    {
        /* Asynchronous Call -- Should Fail */
        flags = SCMI_RESET_FLAGS_ASYNC(1U)| SCMI_RESET_FLAGS_SIGNAL(0U)
            | SCMI_RESET_FLAGS_AUTO(1U);

        NECHECK(SCMI_Reset(channel, domainId,
            flags, SCMI_RESET_ARCH_COLD), SCMI_ERR_INVALID_PARAMETERS);

        /* Reset functionality with different flag inputs */
        flags = SCMI_RESET_FLAGS_ASYNC(0U) | SCMI_RESET_FLAGS_SIGNAL(0U)
            | SCMI_RESET_FLAGS_AUTO(1U);

        printf("SCMI_Reset(%u, %u)\n", channel, domainId);
        CHECK(SCMI_Reset(channel, domainId,
            flags, SCMI_RESET_ARCH_COLD));

        /* Reset functionality with different flag inputs */
        flags = SCMI_RESET_FLAGS_ASYNC(0U) | SCMI_RESET_FLAGS_SIGNAL(1U)
            | SCMI_RESET_FLAGS_AUTO(0U);

        printf("SCMI_Reset(%u, %u)\n", channel, domainId);
        CHECK(SCMI_Reset(channel, domainId,
            flags, SCMI_RESET_ARCH_COLD));

        /* Invalid Parameters -- arch */
        printf("SCMI_Reset(%u, %u)\n", channel, domainId);
        NECHECK(SCMI_Reset(channel, domainId,
            flags, 2U), SCMI_ERR_INVALID_PARAMETERS);

        /* Non-Arch */
        printf("SCMI_Reset(%u, %u)\n", channel, domainId);
        CHECK(SCMI_Reset(channel, domainId,
            flags, 0X80000000));

        /* Reset functionality with different flag inputs */
        flags = SCMI_RESET_FLAGS_ASYNC(0U) | SCMI_RESET_FLAGS_SIGNAL(0U)
            | SCMI_RESET_FLAGS_AUTO(0U);

        printf("SCMI_Reset(%u, %u)\n", channel, domainId);
        CHECK(SCMI_Reset(channel, domainId,
            flags, SCMI_RESET_ARCH_COLD));

        /* Reset Config */
#ifdef SIMU
        /* Reset */
        uint32_t sysManager = 0U;
        printf("LMM_SystemLmShutdown(%u, %u)\n", sysManager, lmId);
        CHECK(LMM_SystemLmShutdown(sysManager, 0U, lmId, false, &g_swReason));
#endif

    }
    else
    {
        flags = SCMI_RESET_FLAGS_ASYNC(0U)| SCMI_RESET_FLAGS_SIGNAL(0U)
            | SCMI_RESET_FLAGS_AUTO(1U);

        XECHECK(pass, SCMI_Reset(channel, domainId,
            flags, SCMI_RESET_ARCH_COLD), SCMI_ERR_DENIED);
    }
}

