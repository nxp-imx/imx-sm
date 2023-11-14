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
/* Unit test for the SCMI power protocol.                                   */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiPowerNone(uint32_t channel, uint32_t domainId);
static void TEST_ScmiPowerSet(bool pass, uint32_t channel,
    uint32_t domainId, uint32_t lmId);

/*--------------------------------------------------------------------------*/
/* Test SCMI power protocol                                                 */
/*--------------------------------------------------------------------------*/
void TEST_ScmiPower(void)
{
    int32_t status = 0;
    uint32_t numDomains = 0U;
    uint32_t agentId, channel, domainId, lmId = 0U;

    /* Power domain tests */
    printf("**** Power Domain Protocol Tests ***\n\n");

    /* Test protocol version */
    {
        uint32_t ver = 0U;

        printf("SCMI_PowerProtocolVersion(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_PowerProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_POWER_PROT_VER);
    }

    /* Test protocol attributes */
    {
        uint32_t attributes = 0U;
        uint32_t powerRegAddressLow = 1U;
        uint32_t powerRegAddressHigh = 1U;
        uint32_t powerRegLen = 1U;

        printf("SCMI_PowerProtocolAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_PowerProtocolAttributes(SM_TEST_DEFAULT_CHN, &attributes,
            NULL, NULL, NULL));
        numDomains =
            SCMI_POWER_PROTO_ATTR_NUM_DOMAINS(attributes);
        printf("  numDomains=%u\n", numDomains);

        /* None null values */
        CHECK(SCMI_PowerProtocolAttributes(SM_TEST_DEFAULT_CHN, NULL,
            NULL, NULL, NULL));

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PowerProtocolAttributes(SM_SCMI_NUM_CHN, &attributes,
            NULL, NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

        printf("SCMI_PowerProtocolAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_PowerProtocolAttributes(SM_TEST_DEFAULT_CHN, &attributes,
            &powerRegAddressLow, &powerRegAddressHigh, &powerRegLen));
    }

    /* Test message attributes */
    {
        printf("SCMI_PowerProtocolMessageAttributes(%u, STATE_SET)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_PowerProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_POWER_STATE_SET, NULL));

        printf("SCMI_PowerProtocolMessageAttributes(%u, 30)\n",
            SM_TEST_DEFAULT_CHN);
        NCHECK(SCMI_PowerProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            30U, NULL));
    }

    /* Error Test : Domain Attributes */
    {
        /* Test power attributes for invalid domain */
        NCHECK(SCMI_PowerDomainAttributes(SM_TEST_DEFAULT_CHN, numDomains,
            NULL, NULL));

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PowerDomainAttributes(SM_SCMI_NUM_CHN, 0U,
            NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointers */
        CHECK(SCMI_PowerDomainAttributes(SM_TEST_DEFAULT_CHN, 0U,
            NULL, NULL));
    }

    /* Power State Set */
    {
        /* Test PowerStateGet for invalid domain */
        NCHECK(SCMI_PowerStateSet(SM_TEST_DEFAULT_CHN, numDomains,
            0, 0));

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PowerStateSet(SM_SCMI_NUM_CHN, 0U, 0, 0),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Power State Get */
    {
        /* Test PowerStateSet for invalid domain */
        uint32_t powerState = 0;
        NCHECK(SCMI_PowerStateGet(SM_TEST_DEFAULT_CHN, numDomains,
            &powerState));

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PowerStateGet(SM_SCMI_NUM_CHN, 0U,
            &powerState), SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_PowerStateGet(SM_TEST_DEFAULT_CHN, 0U, NULL));

    }

    /* Loop over power test domains */
    status = TEST_ConfigFirstGet(TEST_PD, &agentId,
        &channel, &domainId, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].pdPerms[domainId];

        /* Test functions with no perm required */
        TEST_ScmiPowerNone(channel, domainId);

        /* Test functions with SET perm required */
        TEST_ScmiPowerSet(perm >= SM_SCMI_PERM_SET, channel, domainId,
            lmId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_PD, &agentId,
            &channel, &domainId, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI power functions with no access                                 */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiPowerNone(uint32_t channel, uint32_t domainId)
{
    /* Test power attributes */
    {
        uint32_t attributes = 0U;
        uint8_t name[SCMI_POWER_MAX_NAME];

        printf("SCMI_PowerDomainAttributes(%u, %u)\n", channel, domainId);
        name[0] = 0U;
        CHECK(SCMI_PowerDomainAttributes(channel, domainId,
            &attributes, name));
        printf("  extendedName=%u\n",
            SCMI_POWER_ATTR_EXT_NAME(attributes));
        printf("  domainChangeReqNote=%u\n",
            SCMI_POWER_ATTR_CHANGE_REQ(attributes));
        printf("  syncSupport=%u\n",
            SCMI_POWER_ATTR_SYNC(attributes));
        printf("  asyncSupport=%u\n",
            SCMI_POWER_ATTR_ASYNC(attributes));
        printf("  domainChangeNote=%u\n",
            SCMI_POWER_ATTR_CHANGE(attributes));
        printf("  name=%s\n",  name);
    }

    /* Test power get */
    {
        uint32_t powerState = 0U;

        printf("SCMI_PowerStateGet(%u, %u)\n", channel, domainId);
        CHECK(SCMI_PowerStateGet(channel, domainId,
            &powerState));
        printf("  powerState=0x%08x\n", powerState);
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI power functions with SET access                                */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiPowerSet(bool pass, uint32_t channel,
    uint32_t domainId, uint32_t lmId)
{
    /* Adequate Set Permissions */
    if (pass)
    {
        /* Test Power Set OFF */
        printf("SCMI_PowerStateSet(%u, %u, 0, STATE_OFF)\n",
            channel, domainId);
        CHECK(SCMI_PowerStateSet(channel, domainId,
            0U, SCMI_POWER_DOMAIN_STATE_OFF));

        /* Get Power State OFF */
        {
            uint32_t powerState = 0U;

            printf("SCMI_PowerStateGet(%u, %u)\n", channel, domainId);
            CHECK(SCMI_PowerStateGet(channel, domainId,
                &powerState));
            printf("  powerState=0x%08x\n", powerState);

            BCHECK(powerState == SCMI_POWER_DOMAIN_STATE_OFF);
        }

        /* Test power Set ON*/
        printf("SCMI_PowerStateSet(%u, %u, 0, STATE_ON)\n",
            channel, domainId);
        CHECK(SCMI_PowerStateSet(channel, domainId,
            0U, SCMI_POWER_DOMAIN_STATE_ON));

        /* Test PowerStateSet for invalid async flag */
        {
            uint32_t flags = SCMI_POWER_FLAGS_ASYNC(1U);

            NCHECK(SCMI_PowerStateSet(channel, domainId,
                flags, SCMI_POWER_DOMAIN_STATE_ON));
        }

        /* Get Power State ON */
        {
            uint32_t powerState = 0U;

            printf("SCMI_PowerStateGet(%u, %u)\n", channel, domainId);
            CHECK(SCMI_PowerStateGet(channel, domainId,
                &powerState));
            printf("  powerState=0x%08x\n", powerState);

            BCHECK(powerState == SCMI_POWER_DOMAIN_STATE_ON);
        }

#ifdef SIMU

        /* Reset */
        printf("LMM_SystemLmBoot(%u, %u)\n", 0U, lmId);
        CHECK(LMM_SystemLmBoot(0U, 0U, lmId, &g_swReason));

        /* Run over Default Case */
        printf("SCMI_PowerStateSet(%u, %u, 0, 5U)\n",
            channel, domainId);
        NCHECK(SCMI_PowerStateSet(channel, domainId,
            0U, 6U));

        /* Run over Default Case */
        printf("SCMI_PowerStateSet(%u, %u, 0, 5U)\n",
            channel, domainId);
        CHECK(SCMI_PowerStateSet(channel, domainId,
            0U, 2U));

        /* Get Power State DEFAULT */
        {
            uint32_t powerState = 0U;

            printf("SCMI_PowerStateGet(%u, %u)\n", channel, domainId);
            CHECK(SCMI_PowerStateGet(channel, domainId,
                &powerState));
            printf("  powerState=0x%08x\n", powerState);

            BCHECK(powerState == 2U);
        }

        /* Reset */
        printf("LMM_SystemLmShutdown(%u, %u)\n", 0U, lmId);
        CHECK(LMM_SystemLmShutdown(0U, 0U, lmId, false, &g_swReason));

        /* Ensure correctness */
        {
            uint32_t powerState = 0U;

            printf("SCMI_PowerStateGet(%u, %u)\n", channel, domainId);
            CHECK(SCMI_PowerStateGet(channel, domainId,
                &powerState));
            printf("  powerState=0x%08x\n", powerState);

            BCHECK(powerState == SCMI_POWER_DOMAIN_STATE_OFF);
        }
#endif
    }
    /* ACCESS DENIED */
    else
    {
        /* Test power Set ON */
        NECHECK(SCMI_PowerStateSet(channel, domainId,
            0U, SCMI_POWER_DOMAIN_STATE_ON), SCMI_ERR_DENIED);
    }
}

