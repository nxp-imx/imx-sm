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
/* Unit test for the SCMI voltage protocol.                                 */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiVoltageNone(uint32_t channel, uint32_t domainId);
static void TEST_ScmiVoltageSet(bool pass, uint32_t channel,
    uint32_t domainId, uint32_t agentId, uint32_t lmId);
static void TEST_ScmiVoltageExclusive(bool pass, uint32_t channel,
    uint32_t domainId);

/*--------------------------------------------------------------------------*/
/* Test SCMI voltage protocol                                               */
/*--------------------------------------------------------------------------*/
void TEST_ScmiVoltage(void)
{
    int32_t status = 0;
    uint32_t numDomains = 0U;
    uint32_t agentId, channel, domainId, lmId = 0U;

    /* Voltage tests */
    printf("**** Voltage Domain Protocol Test ****\n\n");

    /* Protocol Version */
    {
        uint32_t version = 0U;

        printf("SCMI_VoltageProtocolVersion(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_VoltageProtocolVersion(SM_TEST_DEFAULT_CHN, &version));
        printf("  ver=0x%08X\n", version);

        /* Check to ensure the proper version was returned */
        BCHECK(version == SCMI_VOLT_PROT_VER);
    }

    /* Protocol Attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_VoltageProtocolAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_VoltageProtocolAttributes(SM_TEST_DEFAULT_CHN,
            &attributes));
        numDomains = SCMI_VOLTAGE_PROTO_ATTR_NUM_VOLTS(attributes);
        printf("  numDomains=%u\n", numDomains);
    }

    /* Protocol Message Attributes */
    {
        uint32_t attributes = 0U;

        /* Should WORK : Valid Message ID */
        printf("SCMI_VoltageProtocolMessageAttributes(%u, STATE_SET)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_VoltageProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_VOLTAGE_DOMAIN_ATTRIBUTES, &attributes));
        printf("  attributes=%u\n", attributes);

        /* Spec states should always be 0 */
        BCHECK(attributes == 0U);

        /* Should FAIL : Invalid Message ID */
        NECHECK(SCMI_VoltageProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            30U, NULL), SCMI_ERR_NOT_FOUND);

    }

    /* Domain Attributes -- Invalid domainId  */
    {
        uint32_t attributes = 0U;
        uint8_t name[SCMI_VOLTAGE_MAX_NAME] = {};

        /* Ensure proper error code is returned */
        NECHECK(SCMI_VoltageDomainAttributes(SM_TEST_DEFAULT_CHN,
            numDomains, &attributes, name), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_VoltageDomainAttributes(SM_SCMI_NUM_CHN,
            0U, NULL, NULL), SM_ERR_INVALID_PARAMETERS);

        /* Null Params */
        CHECK(SCMI_VoltageDomainAttributes(SM_TEST_DEFAULT_CHN,
            0U, NULL, NULL));
    }

    /* Config Get -- Invalid domainId */
    {
        uint32_t config = 0U;

        /* Ensure proper error code is returned */
        NECHECK(SCMI_VoltageConfigGet(SM_TEST_DEFAULT_CHN, numDomains,
            &config), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_VoltageConfigGet(SM_SCMI_NUM_CHN, numDomains,
            &config), SM_ERR_INVALID_PARAMETERS);

        /* Null Params */
        CHECK(SCMI_VoltageConfigGet(SM_TEST_DEFAULT_CHN, 0U,
            NULL));
    }

    /* Config Set -- Invalid domainId */
    {
        /* Ensure proper error code is returned */
        NECHECK(SCMI_VoltageConfigSet(SM_TEST_DEFAULT_CHN,
            numDomains, SCMI_VOLTAGE_DOMAIN_MODES_OFF), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_VoltageConfigSet(SM_SCMI_NUM_CHN,
            numDomains, SCMI_VOLTAGE_DOMAIN_MODES_OFF),
            SM_ERR_INVALID_PARAMETERS);
    }

    /* Level Get -- Invalid domainId */
    {
        int32_t voltageLevel = 0;

        /* Ensure proper error code is returned */
        NECHECK(SCMI_VoltageLevelGet(SM_TEST_DEFAULT_CHN, numDomains,
            &voltageLevel), SCMI_ERR_NOT_FOUND);
    }

    /* Level Set -- Invalid domainId */
    {
        uint32_t flags = SCMI_VOLTAGE_SET_FLAGS_ASYNC(0U);

        /* Ensure proper error code is returned */
        NECHECK(SCMI_VoltageLevelSet(SM_TEST_DEFAULT_CHN, numDomains,
            flags, (int32_t) SCMI_VOLTAGE_DOMAIN_MODES_OFF),
            SCMI_ERR_NOT_FOUND);
    }

    /* Describe Levels -- Invalid domainId */
    {
        uint32_t levelIndex = 0U;
        uint32_t flags = 0U;
        int32_t voltage[SCMI_VOLTAGE_MAX_VOLTAGE] = {};

        NECHECK(SCMI_VoltageDescribeLevels(SM_TEST_DEFAULT_CHN,
            numDomains, levelIndex, &flags, voltage), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_VoltageDescribeLevels(SM_SCMI_NUM_CHN,
            0U, levelIndex, NULL, NULL), SM_ERR_INVALID_PARAMETERS);

        /* Null Params */
        CHECK(SCMI_VoltageDescribeLevels(SM_TEST_DEFAULT_CHN,
            0U, levelIndex, NULL, NULL));
    }

    /* Loop over voltage test domains */
    status = TEST_ConfigFirstGet(TEST_VOLT, &agentId,
        &channel, &domainId, &lmId);
    while (status == SCMI_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].voltPerms[domainId];

        /* Test functions with no perm required */
        TEST_ScmiVoltageNone(channel, domainId);

        /* Test functions with SET perm required */
        TEST_ScmiVoltageSet(perm >= SM_SCMI_PERM_SET, channel, domainId,
            agentId, lmId);

        /* Test functions with EXCLUSIVE perm required */
        TEST_ScmiVoltageExclusive(perm >= SM_SCMI_PERM_EXCLUSIVE,
            channel, domainId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_VOLT, &agentId,
            &channel, &domainId, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI voltage functions with no access                               */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiVoltageNone(uint32_t channel, uint32_t domainId)
{
    uint32_t maxLevel = 0U;

    /* Describe Levels */
    {
        uint32_t levelIndex = 0U;
        uint32_t flags = 0U;

        /* DO    : Describe Levels, unpackage data */
        /* WHILE : More voltages to send           */
        do
        {
            int32_t voltage[SCMI_VOLTAGE_MAX_VOLTAGE] = {};

            printf("SCMI_VoltageDescribeLevels(%u, %u)\n",
                channel, domainId);
            CHECK(SCMI_VoltageDescribeLevels(channel,
                domainId, levelIndex, &flags, voltage));

            printf("   remainingLevels=%u\n",
                SCMI_VOLTAGE_FLAGS_REMAINING_LEVELS(flags));

            uint32_t numLevels =
                SCMI_VOLTAGE_FLAGS_NUM_LEVELS(flags);
            printf("   numLevels=%u\n", numLevels);

            for (uint32_t loopIndex = 0U; loopIndex < numLevels;
                loopIndex++)
            {
                printf("   voltage[%u]=%u\n", loopIndex + levelIndex,
                    voltage[loopIndex]);
            }
            levelIndex += numLevels;
        }
        while (SCMI_VOLTAGE_FLAGS_REMAINING_LEVELS(flags) > 0U);

        /* Used for Invalid levelIndex */
        maxLevel = levelIndex;
    }

    /* Describe Level -- Invalid levelIndex */
    {
        uint32_t flags = 0U;
        int32_t voltage[SCMI_VOLTAGE_MAX_VOLTAGE] = {};

        NECHECK(SCMI_VoltageDescribeLevels(channel,
            domainId, maxLevel, &flags, voltage),
            SCMI_ERR_OUT_OF_RANGE);
    }

    /* Domain Attributes */
    {
        uint32_t attributes = 0U;
        uint8_t name[SCMI_VOLTAGE_MAX_NAME] = {};

        printf("SCMI_VoltageDomainAttributes(%u, %u)\n", channel, domainId);
        CHECK(SCMI_VoltageDomainAttributes(channel, domainId,
            &attributes, name));

        /* We do not support Extended Name, ensure 0 */
        BCHECK(SCMI_VOLTAGE_ATTR_EXT_NAME(attributes) == 0U);
        /* Only support Synchronous calls */
        BCHECK(SCMI_VOLTAGE_ATTR_ASYNC(attributes) == 0U);

        printf("  asyncSupport=%u\n",
            SCMI_VOLTAGE_ATTR_ASYNC(attributes));
        printf("  extDomainName=%u\n",
            SCMI_VOLTAGE_ATTR_EXT_NAME(attributes));
        printf("  name=%s\n", name);
    }

    /* Config Get */
    {
        uint32_t config = 0U;

        printf("SCMI_VoltageConfigGet(%u, %u)\n", channel, domainId);
        CHECK(SCMI_VoltageConfigGet(channel, domainId,
            &config));
        printf("   config=%u\n",
            SCMI_VOLTAGE_CONFIG_GET_MODE(config));
    }

    /* Level Get */
    {
        int32_t voltageLevel = 0;

        printf("SCMI_VoltageLevelGet(%u, %u)\n", channel, domainId);
        CHECK(SCMI_VoltageLevelGet(channel, domainId,
            &voltageLevel));
        printf("   voltageLevel=%i\n", voltageLevel);
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI voltage functions with set access                              */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiVoltageSet(bool pass, uint32_t channel,
    uint32_t domainId, uint32_t agentId, uint32_t lmId)
{
    /* Adequate Set Permissions */
    if (pass)
    {
        /* Config Set */
        uint32_t config = 0U;
        printf("SCMI_VoltageConfigSet(%u, %u)\n", channel, domainId);

        /* Turn it on */
        CHECK(SCMI_VoltageConfigSet(channel, domainId,
            SCMI_VOLTAGE_DOMAIN_MODES_ON));
        CHECK(SCMI_VoltageConfigGet(channel, domainId, &config));

        /* Ensure Correctness */
        BCHECK(SCMI_VOLTAGE_CONFIG_GET_MODE(config)
            == SCMI_VOLTAGE_DOMAIN_MODES_ON);

        /* Turn it off */
        CHECK(SCMI_VoltageConfigSet(channel, domainId,
            SCMI_VOLTAGE_DOMAIN_MODES_OFF));
        CHECK(SCMI_VoltageConfigGet(channel, domainId, &config));

        /* Ensure Correctness */
        BCHECK(config == SCMI_VOLTAGE_DOMAIN_MODES_OFF);

        /* Run over default case */
        CHECK(SCMI_VoltageConfigSet(channel, domainId, 1U));
        CHECK(SCMI_VoltageConfigGet(channel, domainId, &config));

        /* Run over default case */
        NECHECK(SCMI_VoltageConfigSet(channel, domainId, 6U),
            SCMI_ERR_INVALID_PARAMETERS);

#ifdef SIMU
        /* Reset */
        printf("LMM_SystemLmBoot(%u, %u)\n", 0U, lmId);
        CHECK(LMM_SystemLmBoot(0U, 0U, lmId, &g_swReason));

        /* RESET AGENT CONFIG */
        /* Turn it on */
        CHECK(SCMI_VoltageConfigSet(channel, domainId,
            SCMI_VOLTAGE_DOMAIN_MODES_ON));

        /* Reset */
        uint32_t sysManager = 0U;
        printf("LMM_SystemLmShutdown(%u, %u)\n", sysManager, lmId);
        CHECK(LMM_SystemLmShutdown(sysManager, 0U, lmId, false, &g_swReason));

        /* Ensure Correctness */
        CHECK(SCMI_VoltageConfigGet(channel, domainId, &config));
        BCHECK(config == SCMI_VOLTAGE_DOMAIN_MODES_OFF);

#endif
        /* Current Issue :: No direct access to call this function */
    }
    /* Access denied */
    else
    {
        NECHECK(SCMI_VoltageConfigSet(channel, domainId,
            SCMI_VOLTAGE_DOMAIN_MODES_ON), SCMI_ERR_DENIED);
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI voltage functions with exclusive access                        */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiVoltageExclusive(bool pass, uint32_t channel,
    uint32_t domainId)
{
    uint32_t flags = 0U;
    int32_t voltage[SCMI_VOLTAGE_MAX_VOLTAGE] = {};

    /* Adequate Set Permissions */
    if(pass)
    {
        /* Level Set */
        int32_t voltageLevel = 0;
        int32_t currLevel = 0;
        int32_t checkLevel = 0;
        printf("SCMI_VoltageLevelSet(%u, %u)\n", channel, domainId);

        /* Get the current level, receive voltage array */
        currLevel = SCMI_VoltageLevelGet(channel, domainId, &voltageLevel);
        CHECK(SCMI_VoltageDescribeLevels(channel, domainId, 0U, &flags,
            voltage));

        /* Synchronous Call -- Should Set to min, then reset to original */
        printf("SCMI_VoltageLevelSet(%u, %u)\n", channel, domainId);

        flags = SCMI_VOLTAGE_SET_FLAGS_ASYNC(0U);
        CHECK(SCMI_VoltageLevelSet(channel, domainId,
            flags, voltage[0]));

        /* Ensure Correctness */
        checkLevel = SCMI_VoltageLevelGet(channel, domainId,
            &voltageLevel);
        BCHECK(checkLevel == voltage[0]);

        /* Reset Voltage to its original state */
        CHECK(SCMI_VoltageLevelSet(channel, domainId,
            flags, currLevel));

        /* Ensure Correctness */
        checkLevel = SCMI_VoltageLevelGet(channel, domainId,
            &voltageLevel);
        BCHECK(checkLevel == currLevel);

        /* Asynchronous Call -- Should Fail */
        flags = SCMI_VOLTAGE_SET_FLAGS_ASYNC(1U);
        NCHECK(SCMI_VoltageLevelSet(channel, domainId,
            flags, currLevel));

        /* Branch -- Invalid Channel */
        flags = SCMI_VOLTAGE_SET_FLAGS_ASYNC(0U);
        NECHECK(SCMI_VoltageLevelSet(SM_SCMI_NUM_CHN, domainId,
            flags, currLevel), SCMI_ERR_INVALID_PARAMETERS);
        NECHECK(SCMI_VoltageLevelGet(SM_SCMI_NUM_CHN, domainId,
            NULL), SCMI_ERR_INVALID_PARAMETERS);

        CHECK(SCMI_VoltageLevelGet(channel, domainId, NULL));
    }
    /* Access denied */
    else
    {
        NECHECK(SCMI_VoltageLevelSet(channel, domainId,
            0U, voltage[0]), SCMI_ERR_DENIED);
    }
}

