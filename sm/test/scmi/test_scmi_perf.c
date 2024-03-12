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
/* Unit test for the SCMI performance protocol.                             */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiPerfNone(uint8_t perm, uint32_t channel,
    uint32_t domainId);
static void TEST_ScmiPerfSet(bool pass, uint32_t channel,
    uint32_t domainId);
static void TEST_ScmiPerfPriv(bool pass, uint32_t channel,
    uint32_t domainId, uint32_t lmId);

/*--------------------------------------------------------------------------*/
/* Test SCMI performance protocol                                           */
/*--------------------------------------------------------------------------*/
void TEST_ScmiPerf(void)
{
    int32_t status = 0;
    uint32_t numDomains = 0U;
    uint32_t agentId, channel, domainId, lmId = 0U;

    /* RPC_00010 RPC_00090 RPC_00160 Performance tests */
    printf("**** Performance Domain Protocol Tests ***\n\n");

    /* Protocol Version*/
    {
        uint32_t ver = 0U;

        printf("SCMI_PerfProtocolVersion(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_PerfProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_PERF_PROT_VER);
    }

    /* Protocol Attributes */
    {
        uint32_t attributes = 0U;
        uint32_t statisticsAddressLow = 1U;
        uint32_t statisticsAddressHigh = 1U;
        uint32_t statisticsLen = 1U;
        /* Initialize to 1, since not supported, SCMI will change
            the values to 0. */

        printf("SCMI_PowerProtocolAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_PerfProtocolAttributes(SM_TEST_DEFAULT_CHN, &attributes,
            &statisticsAddressLow, &statisticsAddressHigh, &statisticsLen));
        numDomains = SCMI_PERF_PROTO_ATTR_NUM_DOMAINS(attributes);
        printf("  numDomains=%u\n", numDomains);
        printf("  powerUnit=%u\n",
            SCMI_PERF_PROTO_ATTR_POWER_UNIT(attributes));

        /* SPEC: should be 0 - NOT SUPPORTED */
        BCHECK(statisticsLen == 0U);
        BCHECK(statisticsAddressLow == 0U);
        BCHECK(statisticsAddressHigh == 0U);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PerfProtocolAttributes(SM_SCMI_NUM_CHN, NULL,
            NULL, NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_PerfProtocolAttributes(SM_TEST_DEFAULT_CHN, NULL,
            NULL, NULL, NULL));
    }

    /* Message Attributes */
    {
        /* Pass Case */
        printf("SCMI_PerfProtocolMessageAttributes(%u, LEVEL_GET)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_PerfProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_PERFORMANCE_LEVEL_GET, NULL));

        /* Fail Case -- Invalid messageId */
        NCHECK(SCMI_PerfProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            30U, NULL));
    }

    /* Domain Attributes */
    {
        /* Domain Attributes -- Invalid domainId */
        NECHECK(SCMI_PerformanceDomainAttributes(SM_TEST_DEFAULT_CHN,
            numDomains, NULL, NULL, NULL, NULL, NULL),
            SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PerformanceDomainAttributes(SM_SCMI_NUM_CHN,
            0U, NULL, NULL, NULL, NULL, NULL),
            SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_PerformanceDomainAttributes(SM_TEST_DEFAULT_CHN,
            0U, NULL, NULL, NULL, NULL, NULL));
    }

    /* Level Set -- Invalid domainId */
    {
        NECHECK(SCMI_PerformanceLevelSet(SM_TEST_DEFAULT_CHN,
            numDomains, 500UL), SCMI_ERR_NOT_FOUND);
    }

    /* Level Get -- Invalid domainId */
    {
        uint32_t perfLevel = 0U;

        NECHECK(SCMI_PerformanceLevelGet(SM_TEST_DEFAULT_CHN,
            numDomains, &perfLevel), SCMI_ERR_NOT_FOUND);
    }

    /* Limit Set -- Invalid domainId */
    {
        uint32_t rangeMax = 0U;
        uint32_t rangeMin = 0U;

        NECHECK(SCMI_PerformanceLimitsSet(SM_TEST_DEFAULT_CHN, numDomains,
            rangeMax, rangeMin), SCMI_ERR_NOT_FOUND);
    }

    /* Limit Get */
    {
        /* Limit Get -- Invalid domainId */
        uint32_t rangeMax = 0U;
        uint32_t rangeMin = 0U;

        NECHECK(SCMI_PerformanceLimitsGet(SM_TEST_DEFAULT_CHN, numDomains,
            &rangeMax, &rangeMin), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PerformanceLimitsGet(SM_SCMI_NUM_CHN, 0U,
            NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_PerformanceLimitsGet(SM_TEST_DEFAULT_CHN, 0U,
            NULL, NULL));
    }

    /* Describe Levels */
    {
        /* Describe Levels -- Invalid domainId */
        uint32_t skipIndex = 0U;
        uint32_t numLevels = 0U;
        scmi_perf_level_t perfLevels[SCMI_PERF_MAX_PERFLEVELS];

        NECHECK(SCMI_PerformanceDescribeLevels(SM_TEST_DEFAULT_CHN,
            numDomains, skipIndex, &numLevels, perfLevels),
            SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PerformanceDescribeLevels(SM_SCMI_NUM_CHN,
            0U, skipIndex, NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_PerformanceDescribeLevels(SM_TEST_DEFAULT_CHN,
            0U, skipIndex, NULL, NULL));
    }

    /* Loop over performance test domains */
    status = TEST_ConfigFirstGet(TEST_PERF, &agentId,
        &channel, &domainId, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].perfPerms[domainId];

        /* Test functions with no perm required */
        TEST_ScmiPerfNone(perm, channel, domainId);

        /* Test functions with SET perm required */
        TEST_ScmiPerfSet(perm >= SM_SCMI_PERM_SET, channel, domainId);

        /* Test functions with PRIV perm required */
        TEST_ScmiPerfPriv(perm >= SM_SCMI_PERM_PRIV, channel, domainId,
            lmId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_PERF, &agentId,
            &channel, &domainId, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI performance functions with NO access                           */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiPerfNone(uint8_t perm, uint32_t channel,
    uint32_t domainId)
{
    uint32_t maxSkip = 0U;

    /* Describe Levels */
    {
        uint32_t skipIndex = 0U;
        uint32_t numLevels = 0U;
        scmi_perf_level_t perfLevels[SCMI_PERF_MAX_PERFLEVELS];

        printf("SCMI_PerformanceDescribeLevels(%u, %u)\n", channel,
            domainId);

        /* DO    : Describe Levels, unpackage data */
        /* WHILE : More voltages to send           */
        do
        {
            CHECK(SCMI_PerformanceDescribeLevels(channel, domainId,
                skipIndex, &numLevels, perfLevels));

            for (uint32_t level = 0U; level
                < SCMI_PERF_NUM_LEVELS_NUM_LEVELS(numLevels);
                level++)
            {
                printf("     %u, %u, %u\n", perfLevels[level].value,
                    perfLevels[level].powerCost,
                    SCMI_PERF_LEVEL_ATTR_LATENCY(perfLevels[level]
                    .attributes));
            }

            skipIndex += SCMI_PERF_NUM_LEVELS_NUM_LEVELS(numLevels);
        }
        while (SCMI_PERF_NUM_LEVELS_REMAING_LEVELS(numLevels) > 0U);

        /* Used for Invalid skipIndex */
        maxSkip = skipIndex;
    }

    /* Describe Level -- Invalid skipIndex */
    {
        uint32_t numLevels = 0U;
        scmi_perf_level_t perfLevels[SCMI_PERF_MAX_PERFLEVELS];

        NECHECK(SCMI_PerformanceDescribeLevels(channel,
            domainId, maxSkip, &numLevels, perfLevels),
            SCMI_ERR_OUT_OF_RANGE);
    }

    /* Domain Attributes */
    {
        uint32_t attributes = 0U;
        uint32_t rateLimit = 0U;
        uint32_t sustainedFreq = 0U;
        uint32_t sustainedPerfLevel = 0U;
        uint8_t name[SCMI_PERF_MAX_NAME] = { 0 };
        name[0] = 0U;

        printf("SCMI_PerformanceDomainAttributes(%u, %u)\n", channel,
            domainId);
        CHECK(SCMI_PerformanceDomainAttributes(channel, domainId,
            &attributes, &rateLimit, &sustainedFreq, &sustainedPerfLevel,
            name));

        /* Case 1: Priv Permissions -- all perms */
        if (perm >= SM_SCMI_PERM_PRIV)
        {
            BCHECK(SCMI_PERF_ATTR_LEVEL(attributes) == 1UL);
            BCHECK(SCMI_PERF_ATTR_LIMIT(attributes) == 1UL);
        }
        /* Case 2: Set Permissions -- limit perms */
        else if (perm >= SM_SCMI_PERM_SET)
        {
            BCHECK(SCMI_PERF_ATTR_LEVEL(attributes) == 0UL);
            BCHECK(SCMI_PERF_ATTR_LIMIT(attributes) == 1UL);
        }
        /* Case 3: No Permissions -- no perms */
        else
        {
            BCHECK(SCMI_PERF_ATTR_LEVEL(attributes) == 0UL);
            BCHECK(SCMI_PERF_ATTR_LIMIT(attributes) == 0UL);
        }

        /* Attribute Extraction */
        printf("  setLimits=%d\n",
            SCMI_PERF_ATTR_LIMIT(attributes));
        printf("  setPerfLevel=%d\n",
            SCMI_PERF_ATTR_LEVEL(attributes));
        printf("  limitNotifyEnable=%d\n",
            SCMI_PERF_ATTR_LIMIT_NOTIFY(attributes));
        printf("  levelNotifyEnable=%d\n",
            SCMI_PERF_ATTR_LEVEL_NOTIFY(attributes));
        printf("  fastChannel=%d\n",
            SCMI_PERF_ATTR_FAST(attributes));
        printf("  extendedName=%d\n",
            SCMI_PERF_ATTR_EXT_NAME(attributes));
        printf("  levelIndexMode=%d\n",
            SCMI_PERF_ATTR_IDX_MODE(attributes));
        printf("  rateLimit=%d\n",
            SCMI_PERF_RATE_LIMIT_USECONDS(rateLimit));
        printf("  sustainedFreq=%u\n", sustainedFreq);
        printf("  sustainedPerfLevel=%u\n", sustainedPerfLevel);
        printf("  name=%s\n",  name);
    }

}

/*--------------------------------------------------------------------------*/
/* Test SCMI performance functions with SET access                          */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiPerfSet(bool pass, uint32_t channel,
    uint32_t domainId)
{
    /* Adequate Permissions */
    if (pass)
    {
        uint32_t rangeMax = 0U;
        uint32_t rangeMin = 0U;

        /* Get Limit */
        printf("SCMI_PerformanceLimitsGet(%u, %u)\n", channel, domainId);
        CHECK(SCMI_PerformanceLimitsGet(channel, domainId, &rangeMax,
            &rangeMin));
        printf("  range=%u-%u\n", rangeMin, rangeMax);

        /* Set Limit - NOT SUPPORTED */
        NECHECK(SCMI_PerformanceLimitsSet(channel, domainId, rangeMax,
            rangeMin), SCMI_ERR_NOT_SUPPORTED);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PerformanceLimitsSet(SM_SCMI_NUM_CHN, domainId, rangeMax,
            rangeMin), SCMI_ERR_INVALID_PARAMETERS);
    }
    /* ACCESS DENIED */
    else
    {
        NECHECK(SCMI_PerformanceLimitsSet(channel, domainId, 0U,
            0U), SCMI_ERR_DENIED);
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI performance functions with PRIV access                         */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiPerfPriv(bool pass, uint32_t channel,
    uint32_t domainId, uint32_t lmId)
{
    uint32_t perfLevel = 0U;

    if (pass)
    {
        printf("SCMI_PerformanceLevelGet(%u, %u)\n", channel, domainId);
        CHECK(SCMI_PerformanceLevelGet(channel, domainId, &perfLevel));
        printf("  performanceLevel=%u\n", perfLevel);

        printf("SCMI_PerformanceLevelSet(%u, %u, %u)\n",
            channel, domainId, perfLevel);
        CHECK(SCMI_PerformanceLevelSet(channel, domainId, perfLevel));

        printf("SCMI_PerformanceLevelGet(%u, %u)\n", channel, domainId);
        CHECK(SCMI_PerformanceLevelGet(channel, domainId, &perfLevel));
        printf("  performanceLevel=%u\n", perfLevel);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PerformanceLevelGet(SM_SCMI_NUM_CHN, domainId, NULL),
            SCMI_ERR_INVALID_PARAMETERS);
        NECHECK(SCMI_PerformanceLevelSet(SM_SCMI_NUM_CHN, domainId, perfLevel),
            SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_PerformanceLevelGet(channel, domainId, NULL));
    }

/* Reset Config */
#ifdef SIMU
    if (pass)
    {
        /* Reset */
        uint32_t sysManager = 0U;
        printf("LMM_SystemLmShutdown(%u, %u)\n", sysManager, lmId);
        CHECK(LMM_SystemLmShutdown(sysManager, 0U, lmId, false, &g_swReason));
    }
#endif
}

