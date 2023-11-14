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
/* Unit test for the SCMI base protocol.                                    */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiBaseNone(uint32_t channel);
static void TEST_ScmiBasePriv(bool pass, uint32_t channel,
    uint32_t resource);

/*--------------------------------------------------------------------------*/
/* Test SCMI base protocol                                                  */
/*--------------------------------------------------------------------------*/
void TEST_ScmiBase(void)
{
    int32_t status = 0;
    uint32_t agentId, channel, resource, lmId = 0;

    /* Base tests */
    printf("**** Base Protocol Tests ***\n\n");

    /* Test protocol version */
    {
        uint32_t ver = 0U;

        printf("SCMI_BaseProtocolVersion(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_BaseProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_BASE_PROT_VER);
    }

    /* Test build info */
    {
        printf("SCMI_BaseProtocolMessageAttributes(%u, DISCOVER_VENDOR)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_BaseProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_BASE_DISCOVER_VENDOR, NULL));

        NCHECK(SCMI_BaseProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            30U, NULL));
    }

    /* Test vendor */
    {
        uint8_t name[SCMI_BASE_MAX_VENDORIDENTIFIER];

        printf("SCMI_BaseDiscoverVendor(%u)\n", SM_TEST_DEFAULT_CHN);
        name[0] = 0U;
        CHECK(SCMI_BaseDiscoverVendor(SM_TEST_DEFAULT_CHN, name));
        printf("  name=%s\n",  name);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_BaseDiscoverVendor(SM_SCMI_NUM_CHN, name),
            SM_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_BaseDiscoverVendor(SM_TEST_DEFAULT_CHN, NULL));
    }

    /* Test sub vendor */
    {
        uint8_t name[SCMI_BASE_MAX_VENDORIDENTIFIER];

        printf("SCMI_BaseDiscoverSubVendor(%u)\n", SM_TEST_DEFAULT_CHN);
        name[0] = 0U;
        CHECK(SCMI_BaseDiscoverSubVendor(SM_TEST_DEFAULT_CHN, name));
        printf("  name=%s\n",  name);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_BaseDiscoverSubVendor(SM_SCMI_NUM_CHN, name),
            SM_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_BaseDiscoverSubVendor(SM_TEST_DEFAULT_CHN, NULL));
    }

    /* Test version */
    {
        uint32_t implementationVersion = 0U;

        printf("SCMI_BaseDiscoverImplementationVersion(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_BaseDiscoverImplementationVersion(SM_TEST_DEFAULT_CHN,
            &implementationVersion));
        printf("  implementationVersion=0x%08X\n", implementationVersion);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_BaseDiscoverImplementationVersion(SM_SCMI_NUM_CHN, NULL),
            SM_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_BaseDiscoverImplementationVersion(SM_TEST_DEFAULT_CHN, NULL));
    }

    /* Test abort */
    {
        uint32_t implementationVersion = 0U;
        int32_t localStatus;

        printf("SCMI_AbortSet(%u, true)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_AbortSet(SM_TEST_DEFAULT_CHN, true));

        printf("SCMI_BaseDiscoverImplementationVersion(%u)\n",
            SM_TEST_DEFAULT_CHN);
        localStatus = SCMI_BaseDiscoverImplementationVersion(SM_TEST_DEFAULT_CHN,
            &implementationVersion);

        /* Check for abort */
        if (localStatus != SCMI_ERR_ABORT_ERROR)
        {
            CHECK(SCMI_ERR_ABORT_ERROR);
        }

        printf("SCMI_AbortSet(%u, false)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_AbortSet(SM_TEST_DEFAULT_CHN, false));
    }

    /* Test list protocols */
    {
        uint32_t numProtocols = 0U;
        uint32_t protocols[SCMI_BASE_MAX_PROTOCOLS] = {};

        printf("SCMI_BaseDiscoverListProtocols(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_BaseDiscoverListProtocols(SM_TEST_DEFAULT_CHN, 0U,
            &numProtocols, protocols));
        printf("  numProtocols=%u\n", numProtocols);
        for (uint32_t p = 0U; p < numProtocols; p++)
        {
            uint32_t prot = protocols[p/4U] >> ((p % 4U) * 8U);

            printf("  prot%u=0x%02X\n", p, prot & 0xFFU);
        }

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_BaseDiscoverListProtocols(SM_SCMI_NUM_CHN, 0U,
            NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_BaseDiscoverListProtocols(SM_TEST_DEFAULT_CHN, 0U,
            NULL, NULL));
    }

    /* Loop over base test agents */
    status = TEST_ConfigFirstGet(TEST_BASE, &agentId,
        &channel, &resource, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].basePerms[resource];

        /* Test functions with no perm required */
        TEST_ScmiBaseNone(channel);

        /* Test functions with PRIV perm required */
        TEST_ScmiBasePriv(perm >= SM_SCMI_PERM_PRIV, channel, resource);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_BASE, &agentId,
            &channel, &resource, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI base functions with no access                                  */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiBaseNone(uint32_t channel)
{
    {
        uint8_t name[SCMI_BASE_MAX_NAME];
        uint32_t agentId = SCMI_BASE_ID_DISCOVER;

        printf("SCMI_BaseDiscoverAgent(%u, SCMI_BASE_ID_DISCOVER)\n",
            channel);
        name[0] = 0U;
        CHECK(SCMI_BaseDiscoverAgent(channel, &agentId, name));

        /* Name as NULL */
        CHECK(SCMI_BaseDiscoverAgent(channel, &agentId, NULL));

        /* Invalid Parameters */
        NECHECK(SCMI_BaseDiscoverAgent(channel, NULL, name),
            SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Invalid CHannel */
        NECHECK(SCMI_BaseDiscoverAgent(SM_SCMI_NUM_CHN, NULL, NULL),
            SCMI_ERR_INVALID_PARAMETERS);

        /* BASE_ID_DISCOVER */
        uint32_t tempAgent = SCMI_BASE_ID_DISCOVER;

        CHECK(SCMI_BaseDiscoverAgent(channel, &tempAgent, name));
        BCHECK(tempAgent == agentId);

        /* Call as the platform */
        tempAgent = 0U;
        CHECK(SCMI_BaseDiscoverAgent(channel, &tempAgent, name));
        printf("   name=%s\n", name);

        /* Invalid agent */
        tempAgent = 100000U;
        NECHECK(SCMI_BaseDiscoverAgent(channel, &tempAgent, name),
            SCMI_ERR_NOT_FOUND);
    }

    {
        uint32_t attributes = 0U;

        printf("SCMI_BaseProtocolAttributes(%u)\n", channel);
        CHECK(SCMI_BaseProtocolAttributes(channel, &attributes));
        printf("  numProtocols=%u\n",
            SCMI_BASE_PROTO_ATTR_NUM_PROTOCOLS(attributes));
        printf("  numAgents=%u\n",
            SCMI_BASE_PROTO_ATTR_NUM_AGENTS(attributes));

        for (uint32_t agentId = 1U; agentId
            <= SCMI_BASE_PROTO_ATTR_NUM_AGENTS(attributes); agentId++)
        {
            uint32_t newAgentId = agentId;
            uint8_t name[SCMI_BASE_MAX_NAME];

            printf("SCMI_BaseDiscoverAgent(%u, %u)\n", channel,
                newAgentId);
            name[0] = 0U;
            CHECK(SCMI_BaseDiscoverAgent(channel, &newAgentId, name));
            printf("  name=%s\n",  name);
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI base functions with PRIV access                                */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiBasePriv(bool pass, uint32_t channel,
    uint32_t resource)
{
    uint32_t scmiInst = g_scmiAgentConfig[resource].scmiInst;
    uint32_t agent = resource + 1U
        - g_scmiConfig[scmiInst].firstAgent;

    /* Reset Agent Config */
    if (pass)
    {
        printf("SCMI_BaseResetAgentConfiguration(%u, %u, 0)\n", agent,
            resource);
        CHECK(SCMI_BaseResetAgentConfiguration(channel, agent, 0U));

        /* Attempt to reset System Manager */
        NECHECK(SCMI_BaseResetAgentConfiguration(channel, 0U, 0U),
            SCMI_ERR_NOT_FOUND);

        /* Reset an Invalid Channel */
        NECHECK(SCMI_BaseResetAgentConfiguration(SM_SCMI_NUM_CHN, 0U, 0U),
            SM_ERR_INVALID_PARAMETERS);

        /* Set Device Permissions */
        uint32_t flags = 0U;
        int32_t status = 0;

        /* Give Access */
        flags = 1U;
        printf("SCMI_BaseSetDevicePermissions(%u, %u, %u)\n", channel,
            0U, flags);
        status = SCMI_BaseSetDevicePermissions(channel, agent,
            0U, flags);
        printf("   status=%d\n", status);

        /* Remove Access */
        flags = 0U;
        printf("SCMI_BaseSetDevicePermissions(%u, %u, %u)\n", channel,
            0U, flags);
        status = SCMI_BaseSetDevicePermissions(channel, agent,
            0U, flags);
        printf("   status=%d\n", status);

        status = SCMI_BaseSetDevicePermissions(SM_SCMI_NUM_CHN, agent,
            0U, flags);
        BCHECK(status == SM_ERR_INVALID_PARAMETERS);
    }
    /* ACCESS DENIED */
    else
    {
        NECHECK(SCMI_BaseResetAgentConfiguration(channel, agent, 0U),
            SCMI_ERR_DENIED);
    }

}

