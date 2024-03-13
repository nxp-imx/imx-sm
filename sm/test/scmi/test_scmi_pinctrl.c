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
static void TEST_ScmiPinctrlNone(uint32_t channel, uint32_t identifier);
static void TEST_ScmiPinctrlExclusive(bool pass, uint32_t channel,
    uint32_t identifier, uint32_t lmId);

/*--------------------------------------------------------------------------*/
/* Test SCMI pinctrl protocol                                               */
/*--------------------------------------------------------------------------*/
void TEST_ScmiPinctrl(void)
{
    uint32_t pins = 0U;
    uint32_t groups = 0U;
    uint32_t functions = 0U;

    /* RPC_00010 RPC_00140 RPC_00160 Pin control tests */
    printf("**** Pinctrl Protocol Test ****\n\n");

    /* Protocol Version */
    {
        uint32_t ver = 0U;

        printf("SCMI_PinctrlProtocolVersion(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_PinctrlProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_PINCTRL_PROT_VER);
    }

    /* Protocol Attributes */
    {
        uint32_t attributesLow = 0U;
        uint32_t attributesHigh = 0U;

        printf("SCMI_PinctrlProtocolAttributes(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_PinctrlProtocolAttributes(SM_TEST_DEFAULT_CHN,
            &attributesLow, &attributesHigh));

        groups = SCMI_PINCTRL_PROTO_ATTR_LOW_NUM_GROUPS(attributesLow);
        pins = SCMI_PINCTRL_PROTO_ATTR_LOW_NUM_PINS(attributesLow);
        functions = SCMI_PINCTRL_PROTO_ATTR_HIGH_NUM_FUNCTIONS(
            attributesHigh);
        printf("Pins = %u ", pins);
        printf("Groups = %u ", groups);
        printf("Functions = %u\n", functions);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PinctrlProtocolAttributes(SM_SCMI_NUM_CHN,
            NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_PinctrlProtocolAttributes(SM_TEST_DEFAULT_CHN,
            NULL, NULL));
    }

    /* Protocol Message Attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_PinctrlProtocolMessageAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_PinctrlProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_PINCTRL_ATTRIBUTES, &attributes));

        /* Check if attributes is 0 */
        BCHECK(attributes == 0U);

        /* Ensure proper error code is returned */
        NECHECK(SCMI_PinctrlProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            30U, NULL), SCMI_ERR_NOT_FOUND);
    }

    /* Pinctrl Attributes */
    {

        uint32_t attributes = 0U;
        uint8_t name[SCMI_PINCTRL_MAX_NAME];
        uint32_t flags = 0U;

        for (uint8_t i = 0U; i < SCMI_PINCTRL_MAX_NAME; i++)
        {
            name[i] = 0U;
        }

        /* Pass in out of bounds identifier for pins
            will come out to SCMI_ERR_NOT_FOUND */
        flags = SCMI_PINCTRL_FLAGS_SELECTOR(0U);

        /* Ensure proper error code is returned */
        NECHECK(SCMI_PinctrlAttributes(SM_TEST_DEFAULT_CHN,
            pins, flags, &attributes, name), SCMI_ERR_NOT_FOUND);

        /* Pass in out of bounds identifier for groups
            will come out to SCMI_ERR_NOT_FOUND */
        flags = SCMI_PINCTRL_FLAGS_SELECTOR(1U);

        /* Ensure proper error code is returned */
        NECHECK(SCMI_PinctrlAttributes(SM_TEST_DEFAULT_CHN,
            groups, flags, &attributes, name), SCMI_ERR_NOT_FOUND);

        /* Pass in out of bounds identifier for functions
            will come out to SCMI_ERR_NOT_FOUND */
        flags = SCMI_PINCTRL_FLAGS_SELECTOR(2U);

        /* Ensure proper error code is returned */
        NECHECK(SCMI_PinctrlAttributes(SM_TEST_DEFAULT_CHN,
            functions, flags, &attributes, name), SCMI_ERR_NOT_FOUND);

        if (pins > 0U)
        {
            flags = SCMI_PINCTRL_FLAGS_SELECTOR(0U);

            printf("SCMI_PinctrlAttributes(%u,%u,%u)\n",
                SM_TEST_DEFAULT_CHN, 0U, flags);
            CHECK(SCMI_PinctrlAttributes(SM_TEST_DEFAULT_CHN,
                0U, flags, &attributes, name));

            printf("Extended name = %u, ",
                SCMI_PINCTRL_ATTR_EXT_NAME(attributes));
            printf("Num pins = %u\n", SCMI_PINCTRL_ATTR_NUM(attributes));

            /* Branch -- Invalid Channel */
            NECHECK(SCMI_PinctrlAttributes(SM_SCMI_NUM_CHN,
                0U, flags, NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

            /* Branch -- Nullpointers */
            CHECK(SCMI_PinctrlAttributes(SM_TEST_DEFAULT_CHN,
                0U, flags, NULL, NULL));
        }

        if (groups > 0U)
        {
            flags = SCMI_PINCTRL_FLAGS_SELECTOR(1U);

            printf("SCMI_PinctrlAttributes(%u,%u,%u)\n",
                SM_TEST_DEFAULT_CHN, 0U, flags);
            CHECK(SCMI_PinctrlAttributes(SM_TEST_DEFAULT_CHN,
                0U, flags, &attributes, name));

            printf("Extended name = %u, ",
                SCMI_PINCTRL_ATTR_EXT_NAME(attributes));
            printf("Num groups = %u\n",
                SCMI_PINCTRL_ATTR_NUM(attributes));

            /* Branch -- Invalid Channel */
            NECHECK(SCMI_PinctrlAttributes(SM_SCMI_NUM_CHN,
                0U, flags, NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

            /* Branch -- Nullpointers */
            CHECK(SCMI_PinctrlAttributes(SM_TEST_DEFAULT_CHN,
                0U, flags, NULL, NULL));
        }

        if (functions > 0U)
        {
            flags = SCMI_PINCTRL_FLAGS_SELECTOR(2U);

            printf("SCMI_PinctrlAttributes(%u,%u,%u)\n",
                SM_TEST_DEFAULT_CHN, 0U, flags);
            CHECK(SCMI_PinctrlAttributes(SM_TEST_DEFAULT_CHN,
                0U, flags, &attributes, name));

            printf("Extended name = %u\n",
                SCMI_PINCTRL_ATTR_EXT_NAME(attributes));

            /* Branch -- Invalid Channel */
            NECHECK(SCMI_PinctrlAttributes(SM_SCMI_NUM_CHN,
                0U, flags, NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

            /* Branch -- Nullpointers */
            CHECK(SCMI_PinctrlAttributes(SM_TEST_DEFAULT_CHN,
                0U, flags, NULL, NULL));
        }
    }

    /* Edge Cases -------------------------------------------------- */

    /* Config Get -- invalids */
    {
        uint32_t attr_cfg = (uint32_t) SCMI_PINCTRL_CONFIG_FLAG_TYPE;
        uint32_t attributes = SCMI_PINCTRL_GET_ATTR_CONFIG(attr_cfg);
        uint32_t numConfigs = 0U;
        scmi_pin_config_t configs[10] = { 0 };

        /* NOT FOUND */
        NECHECK(SCMI_PinctrlSettingsGet(SM_TEST_DEFAULT_CHN, SM_NUM_PIN,
            attributes, NULL, &numConfigs, configs), SCMI_ERR_NOT_FOUND);

        /* INVALID PARAMETERS */
        attr_cfg = (uint32_t) SCMI_PINCTRL_CONFIG_FLAG_ALL;
        attributes = SCMI_PINCTRL_GET_ATTR_CONFIG(attr_cfg)
            | SCMI_PINCTRL_GET_ATTR_SELECTOR(3UL);

        NECHECK(SCMI_PinctrlSettingsGet(SM_TEST_DEFAULT_CHN, 0U,
            attributes, NULL, &numConfigs, configs),
            SCMI_ERR_INVALID_PARAMETERS);

        /* NOT SUPPORTED -- Group */
        attributes = SCMI_PINCTRL_GET_ATTR_CONFIG(attr_cfg) |
            SCMI_PINCTRL_GET_ATTR_SELECTOR(1UL);

        NECHECK(SCMI_PinctrlSettingsGet(SM_TEST_DEFAULT_CHN, 0U,
            attributes, NULL, &numConfigs, configs), SCMI_ERR_NOT_SUPPORTED);

        /* NOT SUPPORTED -- Unsupported Custom Config */
        attr_cfg = (uint32_t) SCMI_PINCTRL_CONFIG_FLAG_TYPE;
        attributes = SCMI_PINCTRL_GET_ATTR_CONFIG(attr_cfg)
            | SCMI_PINCTRL_GET_ATTR_SELECTOR(0UL)
            | SCMI_PINCTRL_GET_ATTR_CONFIG_TYPE(255UL);

        NECHECK(SCMI_PinctrlSettingsGet(SM_TEST_DEFAULT_CHN, 0U,
            attributes, NULL, &numConfigs, configs), SCMI_ERR_NOT_SUPPORTED);

        /* Branch -- Invalid Channel */
        attr_cfg = (uint32_t) SCMI_PINCTRL_CONFIG_FLAG_ALL;
        attributes = SCMI_PINCTRL_GET_ATTR_CONFIG(attr_cfg);
        NECHECK(SCMI_PinctrlSettingsGet(SM_SCMI_NUM_CHN, 0U,
            attributes, NULL, NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointers */
        CHECK(SCMI_PinctrlSettingsGet(SM_TEST_DEFAULT_CHN, 0U,
            attributes, NULL, NULL, NULL));
    }

    /* Config Set -- invalids */
    {
        uint32_t attr_cfg = (uint32_t) SCMI_PINCTRL_CONFIG_FLAG_ALL;
        uint32_t attributes
            = SCMI_PINCTRL_GET_ATTR_CONFIG(attr_cfg);
        uint32_t numConfigs = 0U;
        scmi_pin_config_t configs[10] = { 0 };

        CHECK(SCMI_PinctrlSettingsGet(SM_TEST_DEFAULT_CHN, 0U, attributes,
            NULL, &numConfigs, configs));

        /* INVALID PARAMETERS */
        attributes = SCMI_PINCTRL_SET_ATTR_NUM_CONFIGS(1U)
            | SCMI_PINCTRL_SET_ATTR_SELECTOR(3U);

        NECHECK(SCMI_PinctrlSettingsConfigure(SM_TEST_DEFAULT_CHN, 0U, 0U,
            attributes, configs), SCMI_ERR_INVALID_PARAMETERS);

        /* NOT SUPPORTED -- Group */
        attributes = SCMI_PINCTRL_SET_ATTR_NUM_CONFIGS(1U)
            | SCMI_PINCTRL_SET_ATTR_SELECTOR(1U);

        NECHECK(SCMI_PinctrlSettingsConfigure(SM_TEST_DEFAULT_CHN, 0U, 0U,
            attributes, configs), SCMI_ERR_NOT_SUPPORTED);

        /* NOT SUPPORTED -- Unsupported Custom Config */
        configs[0].type = 255U;
        configs[0].value = 0U;

        NECHECK(SCMI_PinctrlSettingsConfigure(SM_TEST_DEFAULT_CHN, 0U,
            0U, attributes, configs), SCMI_ERR_NOT_SUPPORTED);

        /* NOT FOUND */
        attributes = SCMI_PINCTRL_SET_ATTR_NUM_CONFIGS(1U)
            | SCMI_PINCTRL_SET_ATTR_SELECTOR(0U);
        configs[0].type = SCMI_PINCTRL_TYPE_MUX;

        NECHECK(SCMI_PinctrlSettingsConfigure(SM_TEST_DEFAULT_CHN, SM_NUM_PIN,
            0U, attributes, configs), SCMI_ERR_NOT_FOUND);
    }

    /* PinctrlNegotiateProtocolVersion */
    {
        uint32_t version = 0x1234U;
        printf("SCMI_PinctrlNegotiateProtocolVersion(%u, %x)\n", SM_TEST_DEFAULT_CHN,
            version);
        NECHECK(SCMI_PinctrlNegotiateProtocolVersion(SM_TEST_DEFAULT_CHN, version),
            SM_ERR_NOT_SUPPORTED);
    }

    int32_t status = 0;
    uint32_t agentId, channel, identifier, lmId = 0U;

    /* Loop over power test domains */
    status = TEST_ConfigFirstGet(TEST_PIN, &agentId,
        &channel, &identifier, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].pinPerms[identifier];

        /* Test functions with no perm required */
        TEST_ScmiPinctrlNone(channel, identifier);

        /* Test functions with SET perm required */
        TEST_ScmiPinctrlExclusive(perm >= SM_SCMI_PERM_EXCLUSIVE, channel,
            identifier, lmId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_PIN, &agentId,
            &channel, &identifier, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI power functions with no access                                 */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiPinctrlNone(uint32_t channel, uint32_t identifier)
{
    /* Config Get */
    {
        /* RETURN ALL CONFIGS ----------------------------------- */
        uint32_t attr_cfg = (uint32_t) SCMI_PINCTRL_CONFIG_FLAG_ALL;
        uint32_t attributes
            = SCMI_PINCTRL_GET_ATTR_CONFIG(attr_cfg);
        uint32_t numConfigs = 0U;
        uint32_t functionSelected = 0U;

        /* DO    : Describe configs, unpackage data */
        /* WHILE : More configs to send            */
        do
        {
            scmi_pin_config_t configs[10] = { 0 };

            printf("SCMI_PinctrlSettingsGet(%u, %u, %u)\n", channel,
                identifier, attributes);
            CHECK(SCMI_PinctrlSettingsGet(channel, identifier, attributes,
                &functionSelected, &numConfigs, configs));

            /* Ensure numConfigs returned */
            BCHECK(SCMI_PINCTRL_NUM_CONFIG_FLAGS_NUM_CONFIGS(numConfigs)
                != 0U);

            /* Print all attributes */
            printf("  selector=%u\n",
                SCMI_PINCTRL_SET_ATTR_SELECTOR(attributes));
            printf("  numConfigs=%x\n",
                SCMI_PINCTRL_NUM_CONFIG_FLAGS_NUM_CONFIGS(numConfigs));

            /* Print all configurations */
            for (uint32_t index = 0U; index < numConfigs; index++)
            {
                printf("   configs[%u]: type=%u, value=%u\n",
                    index, configs[index].type, configs[index].value);
            }
        }
        while (SCMI_PINCTRL_NUM_CONFIG_FLAGS_REMAING_CONFIGS(numConfigs)
            > 0U);

        /* RETURN ALL CONFIGS -- skip 1 ------------------------- */
        attributes = SCMI_PINCTRL_GET_ATTR_CONFIG(attr_cfg)
            | SCMI_PINCTRL_GET_ATTR_SKIP_CONFIGS(1UL);
        numConfigs = 0U;

        /* DO    : Describe configs, unpackage data */
        /* WHILE : More configs to send            */
        do
        {
            scmi_pin_config_t configs[10] = { 0 };

            printf("SCMI_PinctrlSettingsGet(%u, %u, %u)\n", channel,
                identifier, attributes);
            CHECK(SCMI_PinctrlSettingsGet(channel, identifier, attributes,
                &functionSelected, &numConfigs, configs));

            /* Ensure numConfigs returned */
            BCHECK(SCMI_PINCTRL_NUM_CONFIG_FLAGS_NUM_CONFIGS(numConfigs)
                != 0U);

            /* Print all attributes */
            printf("  selector=%u\n",
                SCMI_PINCTRL_SET_ATTR_SELECTOR(attributes));
            printf("  numConfigs=%x\n",
                SCMI_PINCTRL_NUM_CONFIG_FLAGS_NUM_CONFIGS(numConfigs));

            /* Print all configurations */
            for (uint32_t index = 0U; index < numConfigs; index++)
            {
                printf("   configs[%u]: type=%u, value=%u\n",
                    index, configs[index].type, configs[index].value);
            }
        }
        while (SCMI_PINCTRL_NUM_CONFIG_FLAGS_REMAING_CONFIGS(numConfigs)
            > 0U);

        /* RETURN TYPE  ----------------------------------------- */
        attr_cfg = (uint32_t) SCMI_PINCTRL_CONFIG_FLAG_TYPE;
        attributes = SCMI_PINCTRL_GET_ATTR_CONFIG(attr_cfg)
            | SCMI_PINCTRL_GET_ATTR_CONFIG_TYPE(SCMI_PINCTRL_TYPE_MUX);
        scmi_pin_config_t configs[1] = { 0 };

        printf("SCMI_PinctrlSettingsGet(%u, %u, %u)\n", channel,
            identifier, attributes);
        CHECK(SCMI_PinctrlSettingsGet(channel, identifier, attributes,
            &functionSelected, &numConfigs, configs));

        /* Print the configuration */
        printf("  configType=%u\n",
            SCMI_PINCTRL_GET_ATTR_CONFIG_TYPE(attributes));
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI power functions with exclusive access                          */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiPinctrlExclusive(bool pass, uint32_t channel,
    uint32_t identifier, uint32_t lmId)
{

    /* Adequate Access Permissions */
    if (pass)
    {
        uint32_t functionSelected = 0U;

        /* Get the current Config */
        uint32_t attr_cfg = (uint32_t) SCMI_PINCTRL_CONFIG_FLAG_ALL;
        uint32_t attributes
            = SCMI_PINCTRL_GET_ATTR_CONFIG(attr_cfg);
        uint32_t numConfigs = 0U;
        scmi_pin_config_t configs[10] = { 0 };

        printf("SCMI_PinctrlSettingsGet(%u, %u, %u)\n", channel,
            identifier, attributes);
        CHECK(SCMI_PinctrlSettingsGet(channel, identifier, attributes,
            &functionSelected, &numConfigs, configs));

        /* Set to the current config */
        uint32_t num = SCMI_PINCTRL_NUM_CONFIG_FLAGS_NUM_CONFIGS(numConfigs);
        attributes = SCMI_PINCTRL_SET_ATTR_NUM_CONFIGS(num) |
            SCMI_PINCTRL_GET_ATTR_SELECTOR(0UL);

        printf("SCMI_PinctrlSettingsConfigure(%u, %u, %u)\n", channel,
            identifier, attributes);
        CHECK(SCMI_PinctrlSettingsConfigure(channel, identifier, 0U,
            attributes, configs));
        uint32_t flags = 0x0U;
        printf("SCMI_PinctrlRequest(%u, %u)\n", channel,
            identifier);
        CHECK(SCMI_PinctrlRequest(channel, identifier, flags));

        printf("SCMI_PinctrlRelease(%u, %u)\n", channel,
            identifier);
        CHECK(SCMI_PinctrlRelease(channel, identifier, flags));

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_PinctrlSettingsConfigure(SM_SCMI_NUM_CHN, identifier,
            0U, attributes, configs), SCMI_ERR_INVALID_PARAMETERS);

#ifdef SIMU
        num += 2;

        configs[2].type = SCMI_PINCTRL_TYPE_DAISY_ID;
        configs[2].value = 0;

        configs[3].type = SCMI_PINCTRL_TYPE_DAISY_CFG;
        configs[3].value = 0;

        attributes = SCMI_PINCTRL_SET_ATTR_NUM_CONFIGS(num) |
            SCMI_PINCTRL_SET_ATTR_SELECTOR(0U);

        printf("SCMI_PinctrlSettingsConfigure(%u, %u, %u)\n", channel,
            identifier, attributes);
        CHECK(SCMI_PinctrlSettingsConfigure(channel, identifier, 0U,
            attributes, configs));
#endif
    }
    /* ACCESS DENIED */
    else
    {
        uint32_t functionSelected = 0U;

        uint32_t attr_cfg = (uint32_t) SCMI_PINCTRL_CONFIG_FLAG_ALL;
        uint32_t attributes
            = SCMI_PINCTRL_GET_ATTR_CONFIG(attr_cfg);
        uint32_t numConfigs = 0U;
        scmi_pin_config_t configs[10] = { 0 };

        printf("SCMI_PinctrlSettingsGet(%u, %u, %u)\n", channel,
            identifier, attributes);
        CHECK(SCMI_PinctrlSettingsGet(channel, identifier, attributes,
            &functionSelected, &numConfigs, configs));

        /* Set to the current config */
        uint32_t num = SCMI_PINCTRL_NUM_CONFIG_FLAGS_NUM_CONFIGS(numConfigs);
        attributes = SCMI_PINCTRL_SET_ATTR_NUM_CONFIGS(num) |
            SCMI_PINCTRL_GET_ATTR_SELECTOR(0UL);

        NECHECK(SCMI_PinctrlSettingsConfigure(channel, identifier, 0U,
            attributes, configs), SCMI_ERR_DENIED);

        uint32_t flags = 0x0U;
        printf("SCMI_PinctrlRequest(%u, %u)\n", channel, identifier);
        NECHECK(SCMI_PinctrlRequest(channel, identifier, flags), SCMI_ERR_DENIED);

        printf("SCMI_PinctrlRelease(%u, %u)\n", channel, identifier);
        NECHECK(SCMI_PinctrlRelease(channel, identifier, flags), SCMI_ERR_DENIED);
    }

    /* Reset */
    uint32_t sysManager = 0U;
    printf("LMM_SystemLmShutdown(%u, %u)\n", sysManager, lmId);
    CHECK(LMM_SystemLmShutdown(sysManager, 0U, lmId, false, &g_swReason));
}

