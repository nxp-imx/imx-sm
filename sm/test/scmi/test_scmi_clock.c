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
/* Unit test for the SCMI clock protocol.                                   */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiClockNone(uint32_t channel, uint32_t clockId);
static void TEST_ScmiClockSet(bool pass, uint32_t channel,
    uint32_t clockId);
static void TEST_ScmiClockExclusive(bool pass, uint32_t channel,
    uint32_t clockId, uint32_t lmId);

/*--------------------------------------------------------------------------*/
/* Test SCMI clock protocol                                                 */
/*--------------------------------------------------------------------------*/
void TEST_ScmiClock(void)
{
    int32_t status;
    uint32_t numClocks;
    uint32_t agentId, channel, clockId, lmId;

    /* Clock tests */
    printf("**** Clock Protocol Tests ***\n\n");

    /* Test protocol version */
    {
        uint32_t ver = 0U;

        printf("SCMI_ClockProtocolVersion()\n");
        CHECK(SCMI_ClockProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_CLOCK_PROT_VER);
    }

    /* Test protocol attributes */
    {
        uint32_t attributes = 0U;
        uint32_t maxPending;

        printf("SCMI_ClockProtocolAttributes()\n");
        CHECK(SCMI_ClockProtocolAttributes(SM_TEST_DEFAULT_CHN,
            &attributes));
        numClocks =
            SCMI_CLOCK_PROTO_ATTR_NUM_CLOCKS(attributes);
        maxPending = SCMI_CLOCK_PROTO_ATTR_MAX_PENDING(attributes);
        printf("  numClocks=%u\n", numClocks);
        printf("  maxPending=%u\n", maxPending);
    }

    /* Test message attributes */
    {
        printf("SCMI_ClockProtocolMessageAttributes(RATE_SET)\n");
        CHECK(SCMI_ClockProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_CLOCK_RATE_SET, NULL));

        printf("SCMI_ClockProtocolMessageAttributes(30)\n");
        NCHECK(SCMI_ClockProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            30U, NULL));
    }

    /* Test clock attributes for invalid clock and invalid channel*/
    {
        NCHECK(SCMI_ClockAttributes(SM_TEST_DEFAULT_CHN, numClocks, NULL,
            NULL));

        NECHECK(SCMI_ClockAttributes(SM_SCMI_NUM_CHN, numClocks, NULL,
            NULL), SM_ERR_INVALID_PARAMETERS);
    }

    /* Test clock rate set for invalid clock and invalid channel*/
    {
        uint32_t flags = SCMI_CLOCK_RATE_FLAGS_ROUND(SCMI_CLOCK_ROUND_DOWN);
        scmi_clock_rate_t rate = {1000U, 0U};

        printf("SCMI_ClockRateSet(%u, %u, 0x%08X, %u)\n",
            SM_TEST_DEFAULT_CHN, numClocks, flags, rate.lower);
        NCHECK(SCMI_ClockRateSet(SM_TEST_DEFAULT_CHN, numClocks,
            flags, rate));

        NECHECK(SCMI_ClockRateSet(SM_SCMI_NUM_CHN, numClocks,
            flags, rate), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Test coverage of exceeding max amount of sensors in
        ClockConfigSet and invalid channel*/
    {
        uint32_t attr = SCMI_CLOCK_CONFIG_SET_ENABLE(1U);

        NCHECK(SCMI_ClockConfigSet(SM_TEST_DEFAULT_CHN,numClocks,
            attr, 0U));

        NECHECK(SCMI_ClockConfigSet(SCMI_ERR_INVALID_PARAMETERS, numClocks,
            attr, 0U), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Test coverage of exceeding max amount of sensors in
        ClockConfigGet */
    {
        uint32_t flags = SCMI_CLOCK_CONFIG_SET_ENABLE(1U);
        uint32_t attr = 0U;
        uint32_t config = 0U;
        uint32_t oemConfigVal = 0U;

        NECHECK(SCMI_ClockConfigGet(SM_TEST_DEFAULT_CHN, numClocks,
            flags, &attr, &config, &oemConfigVal), SM_ERR_NOT_FOUND);

        NECHECK(SCMI_ClockConfigGet(SM_SCMI_NUM_CHN, numClocks,
            flags, &attr, &config, &oemConfigVal),
            SM_ERR_INVALID_PARAMETERS);
    }

    /* Test coverage of exceeding max amount of sensors in
        ClockDescribeRates */
    {
        scmi_clock_rate_t rates[SCMI_CLOCK_MAX_RATES];
        uint32_t flags = 0;

        NCHECK(SCMI_ClockDescribeRates(SM_TEST_DEFAULT_CHN, numClocks,
            0U, &flags, rates));
    }


    /* Test coverage of exceeding max amount of sensors in
        ClockRateGet and invalid channel*/
    {
        scmi_clock_rate_t rates[SCMI_CLOCK_MAX_RATES];

        NECHECK(SCMI_ClockRateGet(SM_SCMI_NUM_CHN, numClocks,
            rates), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Test coverage of exceeding max amount of sensors in
        ClockParentSet and invalid channel*/
    {
        uint32_t parentId = 0U;

        NECHECK(SCMI_ClockParentSet(SM_TEST_DEFAULT_CHN, numClocks,
            parentId), SM_ERR_NOT_FOUND);

        NECHECK(SCMI_ClockParentSet(SM_SCMI_NUM_CHN, numClocks,
            parentId), SM_ERR_INVALID_PARAMETERS);
    }

    /* Test coverage of exceeding max amount of sensors in
        ClockParentGet and invalid channel*/
    {
        uint32_t parentId = 0U;

        NECHECK(SCMI_ClockParentGet(SM_TEST_DEFAULT_CHN, numClocks,
            &parentId), SM_ERR_NOT_FOUND);

        NECHECK(SCMI_ClockParentGet(SM_SCMI_NUM_CHN, numClocks,
            &parentId), SM_ERR_INVALID_PARAMETERS);
    }

    /* Test coverage of exceeding max amount of sensors in
        ClockPossibleParentGet */
    {
        uint32_t numParent = 0;
        uint32_t parents = 0;

        NECHECK(SCMI_ClockPossibleParentsGet(SM_TEST_DEFAULT_CHN, numClocks,
            0U, &numParent, &parents), SM_ERR_NOT_FOUND);

        NECHECK(SCMI_ClockPossibleParentsGet(SM_SCMI_NUM_CHN, numClocks,
            0U, &numParent, &parents), SM_ERR_INVALID_PARAMETERS);
    }

    /* Loop over clock test domains */
    status = TEST_ConfigFirstGet(TEST_CLK, &agentId,
        &channel, &clockId, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].clkPerms[clockId];

        /* Test functions with no perm required */
        TEST_ScmiClockNone(channel, clockId);

        /* Test functions with SET perm required */
        TEST_ScmiClockSet(perm >= SM_SCMI_PERM_SET, channel, clockId);

        /* Test functions with EXCLUSIVE perm required */
        TEST_ScmiClockExclusive(perm >= SM_SCMI_PERM_EXCLUSIVE, channel,
            clockId, lmId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_CLK, &agentId,
            &channel, &clockId, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI clock functions with no access                                 */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiClockNone(uint32_t channel, uint32_t clockId)
{
    uint32_t attributes = 0U;
    uint8_t name[SCMI_CLOCK_MAX_NAME];
    uint32_t numRatesFlags = 0U;
    scmi_clock_rate_t rates[SCMI_CLOCK_MAX_RATES] = { 0 };

    printf("SCMI_ClockAttributes(%u, %u)\n", channel, clockId);
    name[0] = 0U;
    CHECK(SCMI_ClockAttributes(channel, clockId, &attributes,
        name));
    printf("  enabled=%u\n",
        SCMI_CLOCK_ATTR_ENABLED(attributes));
    printf("  extendedName=%u\n",
        SCMI_CLOCK_ATTR_EXT_NAME(attributes));
    printf("  clockChangeReqNote=%u\n",
        SCMI_CLOCK_ATTR_CHANGE_REQ(attributes));
    printf("  clockChangeNote=%u\n",
        SCMI_CLOCK_ATTR_CHANGE(attributes));
    printf("  parentSup=%u\n",
        SCMI_CLOCK_ATTR_PARENT(attributes));
    printf("  name=%s\n",  name);

    CHECK(SCMI_ClockAttributes(channel, clockId, NULL,
        NULL));

    printf("SCMI_ClockDescribeRates(%u, %u)\n", channel, clockId);
    CHECK(SCMI_ClockDescribeRates(channel, clockId, 0U,
        &numRatesFlags, rates));
    printf("  numRates=%u\n",
        SCMI_CLOCK_NUM_RATE_FLAGS_NUM_RATES(numRatesFlags));
    printf("  formatRange=%u\n",
        SCMI_CLOCK_NUM_RATE_FLAGS_FORMAT(numRatesFlags));
    printf("  remainingRates=%u\n",
        SCMI_CLOCK_NUM_RATE_FLAGS_REMAING_RATES(numRatesFlags));

    NECHECK(SCMI_ClockDescribeRates(channel, clockId, 2U,
        &numRatesFlags, rates), SM_ERR_OUT_OF_RANGE);

    NECHECK(SCMI_ClockDescribeRates(SM_SCMI_NUM_CHN, clockId, 0U,
        &numRatesFlags, rates), SM_ERR_INVALID_PARAMETERS);

    CHECK(SCMI_ClockDescribeRates(channel, clockId, 0U,
        NULL, NULL));

    /* Config get test*/
    {
        uint32_t attributesConfigGet = 0U;
        uint32_t flagConfigGet = 0U;
        uint32_t config = 0U;
        uint32_t extendedConfigVal = 0U;

        printf("SCMI_ClockConfigGet(%u, %u)\n", channel, clockId);
        CHECK(SCMI_ClockConfigGet(channel, clockId, flagConfigGet,
            &attributesConfigGet, &config, &extendedConfigVal));

        printf("  enabled=%u\n",
            SCMI_CLOCK_CONFIG_GET_ENABLE(config));
        printf("  ext=%u\n",
            SCMI_CLOCK_CONFIG_FLAGS_EXT_CONFIG(extendedConfigVal));

        CHECK(SCMI_ClockConfigGet(channel, clockId, flagConfigGet,
            NULL, NULL, NULL));

        /* Invalid parameter check for ConfigGet*/
        printf("SCMI_ClockConfigGet(%u, %u)\n", channel, clockId);
        NECHECK(SCMI_ClockConfigGet(channel, clockId,
            SCMI_CLOCK_CONFIG_FLAGS_EXT_CONFIG(2U),
            &attributesConfigGet, &config, &extendedConfigVal),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    {
        uint32_t skipParents = 0U;
        uint32_t numParentsFlags = 0U;
        uint32_t attributesParent = 0U;
        uint32_t parents[SCMI_CLOCK_MAX_PARENTS] = { 0 };

        CHECK(SCMI_ClockAttributes(channel, clockId, &attributesParent,
            name));

        if(SCMI_CLOCK_ATTR_PARENT(attributesParent) == 1U)
        {
            printf("SCMI_ClockPossibleParentsGet(%u, %u)\n",
                channel, clockId);
            CHECK(SCMI_ClockPossibleParentsGet(channel, clockId,
                skipParents, &numParentsFlags, parents));

            CHECK(SCMI_ClockPossibleParentsGet(channel, clockId,
                skipParents, NULL, NULL));

            uint32_t remainingParents =
                SCMI_CLOCK_NUM_PARENT_FLAGS_REMAING_PARENTS(numParentsFlags);
            printf("  remaining parents= %u\n", remainingParents);

            uint32_t numParents =
                SCMI_CLOCK_NUM_PARENT_FLAGS_NUM_PARENTS(numParentsFlags);
            printf("  parent clock identifiers= %u\n", numParents);

            for(uint32_t i = 0U; i < numParents; i++)
            {
                printf("  possible parent clock = %u\n", parents[i]);
            }

            NECHECK(SCMI_ClockPossibleParentsGet(channel, clockId,
                256U, &numParentsFlags, parents), SM_ERR_OUT_OF_RANGE);
        }
        else
        {
            NECHECK(SCMI_ClockPossibleParentsGet(channel, clockId,
                skipParents,&numParentsFlags, parents),
                SM_ERR_NOT_SUPPORTED);
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI clock functions with SET access                                */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiClockSet(bool pass, uint32_t channel,
    uint32_t clockId)
{
    uint32_t attributes = SCMI_CLOCK_CONFIG_SET_ENABLE(1U);

    printf("SCMI_ClockConfigSet(%u, %u, true)\n", channel, clockId);
    XCHECK(pass, SCMI_ClockConfigSet(channel, clockId,
        attributes, 0U));

    /* Error check for invalid enabled number*/
    NECHECK(SCMI_ClockConfigSet(channel, clockId,
        SCMI_CLOCK_CONFIG_SET_ENABLE(2U), 0U), SM_ERR_INVALID_PARAMETERS);

    if (pass)
    {
        printf("SCMI_ClockAttributes(%u, %u)\n", channel, clockId);
        CHECK(SCMI_ClockAttributes(channel, clockId, &attributes, NULL));
        printf("  enabled=%u\n",
            SCMI_CLOCK_ATTR_ENABLED(attributes));
    }


}

/*--------------------------------------------------------------------------*/
/* Test SCMI clock functions with EXCLUSIVE access                          */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiClockExclusive(bool pass, uint32_t channel,
    uint32_t clockId, uint32_t lmId)
{
    uint32_t flags = SCMI_CLOCK_RATE_FLAGS_ROUND(3U);
    scmi_clock_rate_t rate = {20000000U, 0U};

    printf("SCMI_ClockRateSet(%u, %u, 0x%08X, %u)\n", channel, clockId,
        flags, rate.lower);
    XCHECK(pass, SCMI_ClockRateSet(channel, clockId, flags, rate));
    flags = SCMI_CLOCK_RATE_FLAGS_ROUND(SCMI_CLOCK_ROUND_AUTO);
    XCHECK(pass, SCMI_ClockRateSet(channel, clockId, flags, rate));
    flags = SCMI_CLOCK_RATE_FLAGS_ROUND(SCMI_CLOCK_ROUND_UP);
    XCHECK(pass, SCMI_ClockRateSet(channel, clockId, flags, rate));
    flags = SCMI_CLOCK_RATE_FLAGS_ROUND(SCMI_CLOCK_ROUND_DOWN);
    XCHECK(pass, SCMI_ClockRateSet(channel, clockId, flags, rate));

    if (pass)
    {
        printf("SCMI_ClockRateGet(%u, %u)\n", channel, clockId);
        CHECK(SCMI_ClockRateGet(channel, clockId, &rate));
        printf("  rate=%u\n", rate.lower);

        CHECK(SCMI_ClockRateGet(channel, clockId, NULL));
    }

    /* Test ClockRateSet for invalid async flag */
    {
        uint32_t asyncflag = SCMI_CLOCK_RATE_FLAGS_ASYNC(1U);

        NCHECK(SCMI_ClockRateSet(channel, clockId,
            asyncflag, rate));
    }

#ifdef SIMU
    /* Reset Config */
    if (pass)
    {
        /* Reset */
        printf("LMM_SystemLmBoot(%u, %u)\n", 0U, lmId);
        CHECK(LMM_SystemLmBoot(0U, 0U, lmId, &g_swReason));

        /* Turn on the Clock */
        uint32_t attr = SCMI_CLOCK_CONFIG_SET_ENABLE(1U);

        printf("SCMI_ClockConfigSet(%u, %u)\n",
            channel, clockId);
        CHECK(SCMI_ClockConfigSet(channel, clockId,
            attr, 0U));

        /* Reset */
        uint32_t sysManager = 0U;
        printf("LMM_SystemLmReset(%u, %u)\n", sysManager, lmId);
        CHECK(LMM_SystemLmReset(sysManager, 0U, lmId, true, false,
            &g_swReason));

        /* Ensure Clock was turned off */
        uint32_t attributes = 0U;
        uint8_t name[SCMI_CLOCK_MAX_NAME];

        printf("SCMI_ClockAttributes(%u)\n", clockId);
        CHECK(SCMI_ClockAttributes(channel, clockId, &attributes,
            name));
        printf("  enabled=%u\n",
            SCMI_CLOCK_ATTR_ENABLED(attributes));

        BCHECK(SCMI_CLOCK_ATTR_ENABLED(attributes) == 0U);
    }
#endif

    /* Test for parentget and parentset*/
    if(pass)
    {
        uint32_t parentId = 0U;
        uint32_t attributes = 0U;
        uint8_t name[SCMI_CLOCK_MAX_NAME];

        CHECK(SCMI_ClockAttributes(channel, clockId, &attributes, name));

        printf("SCMI_ClockParentGet(%u, %u)\n", channel, clockId);
        CHECK(SCMI_ClockParentGet(channel, clockId, &parentId));
        printf(" parentId=%u\n", parentId);

        CHECK(SCMI_ClockParentGet(channel, clockId, NULL));

        if(SCMI_CLOCK_ATTR_PARENT(attributes) == 1U)
        {
            printf("SCMI_ClockParentSet(%u, %u)\n", channel, clockId);
            XCHECK(pass, SCMI_ClockParentSet(channel, clockId, parentId));
        }
    }
    else
    {
        uint32_t parentId = 0U;

        NECHECK(SCMI_ClockParentSet(channel, clockId, parentId),
            SCMI_ERR_DENIED);
    }
}

