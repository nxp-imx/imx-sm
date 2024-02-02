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
/* Unit test for the SCMI system protocol.                                  */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "lmm.h"
#include "rpc_scmi_sys.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiSystemNotify(bool pass, uint32_t channel);
static void TEST_ScmiSystemSet(bool pass, uint32_t channel);
static void TEST_ScmiSystemExclusive(bool pass, uint32_t channel,
    uint32_t lmId);

/*--------------------------------------------------------------------------*/
/* Test SCMI system protocol                                                */
/*--------------------------------------------------------------------------*/
void TEST_ScmiSystem(void)
{
    int32_t status = 0;
    uint32_t agentId, channel, resource, lmId = 0U;

    /* RPC_00010 RPC_00080 RPC_00160 System power tests */
    printf("**** System Power Tests ***\n\n");

    /* Test protocol version */
    {
        uint32_t ver = 0U;

        printf("SCMI_SysProtocolVersion(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_SysProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_SYSTEM_PROT_VER);
    }

    /* Test Protocol Attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_SysProtocolAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_SysProtocolAttributes(SM_TEST_DEFAULT_CHN, &attributes));
    }

    /* Test message attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_SysProtocolMessageAttributes(%u, STATE_SET)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_SysProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_SYSTEM_POWER_STATE_SET, &attributes));
        printf("  suspendSuported=%u\n",
            SCMI_SYS_MSG_ATTR_SUSPEND(attributes));
        printf("  warmResetSupported=%u\n",
            SCMI_SYS_MSG_ATTR_WARM(attributes));

        printf("SCMI_SysProtocolMessageAttributes(%u, "
            "SCMI_MSG_SYS_POWER_STATE_NOTIFY)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_SysProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_SYSTEM_POWER_STATE_NOTIFY, &attributes));
        printf("  suspendSuported=%u\n",
            SCMI_SYS_MSG_ATTR_SUSPEND(attributes));
        printf("  warmResetSupported=%u\n",
            SCMI_SYS_MSG_ATTR_WARM(attributes));
    }

    /* Invalid notification */
    {
        scmi_msg_id_t msgId =
        {
            .protocolId = 0xFFU,
            .messageId = 0xFFU
        };
        lmm_rpc_trigger_t trigger = { 0 };

        printf("RPC_SCMI_SysDispatchNotification()\n");
        RPC_SCMI_SysDispatchNotification(msgId, &trigger);
    }

    /* Loop over system power tests */
    status = TEST_ConfigFirstGet(TEST_SYS, &agentId,
        &channel, &resource, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].sysPerms;

        /* RPC_00170 Test functions with NOTIFY perm required */
        TEST_ScmiSystemNotify(perm >= SM_SCMI_PERM_NOTIFY, channel);

        /* Test functions with SET perm required */
        TEST_ScmiSystemSet(perm >= SM_SCMI_PERM_SET, channel);

        /* Test functions with EXCLUSIVE perm required */
        TEST_ScmiSystemExclusive(perm >= SM_SCMI_PERM_EXCLUSIVE, channel,
            lmId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_SYS, &agentId,
            &channel, &resource, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI performance functions with NOTIFY access                       */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiSystemNotify(bool pass, uint32_t channel)
{
    uint32_t attributes = 0U;

    printf("SCMI_SystemPowerStateNotify(%u, true)\n", channel);
    XCHECK(pass, SCMI_SystemPowerStateNotify(channel,
        SCMI_SYS_NOTIFY_ENABLE(1U)));

    printf("SCMI_SystemPowerStateNotify(%u, true)\n", channel);
    XCHECK(pass, SCMI_SystemPowerStateNotify(channel,
        SCMI_SYS_NOTIFY_ENABLE(0U)));

    if (pass)
    {
        printf("SCMI_SysProtocolMessageAttributes(%u, "
            "SCMI_MSG_SYS_POWER_STATE_NOTIFY)\n", channel);
        CHECK(SCMI_SysProtocolMessageAttributes(channel,
            SCMI_MSG_SYSTEM_POWER_STATE_NOTIFY, &attributes));
    }
    else
    {
        uint32_t notifyEnable = SCMI_SYS_NOTIFY_ENABLE(1U);

        printf("SCMI_SystemPowerStateNotify(%u, true)\n", channel);
        NECHECK(SCMI_SystemPowerStateNotify(channel, notifyEnable),
            SCMI_ERR_NOT_SUPPORTED);

        printf("SCMI_SysProtocolMessageAttributes(%u, "
            "SCMI_MSG_SYS_POWER_STATE_NOTIFY)\n", channel);
        NECHECK(SCMI_SysProtocolMessageAttributes(channel,
            SCMI_MSG_SYSTEM_POWER_STATE_NOTIFY, &attributes),
            SCMI_ERR_NOT_SUPPORTED);
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI performance functions with SET access                          */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiSystemSet(bool pass, uint32_t channel)
{
    uint32_t flags = SCMI_SYS_FLAGS_GRACEFUL(1U);
    uint32_t attributes = 0U;

    printf("SCMI_SystemPowerStateSet(%u, STATE_SHUTDOWN)\n", channel);
    XCHECK(pass, SCMI_SystemPowerStateSet(channel, flags,
        SCMI_SYS_STATE_SHUTDOWN));

    /* Adequate Permissions */
    if (pass)
    {
        /* System Power State Notify */
        printf("SCMI_SysProtocolMessageAttributes(%u, "
            "SCMI_MSG_SYS_POWER_STATE_NOTIFY)\n", channel);
        CHECK(SCMI_SysProtocolMessageAttributes(channel,
            SCMI_MSG_SYSTEM_POWER_STATE_NOTIFY, &attributes));

        /* System Power State Set */
        printf("SCMI_SysProtocolMessageAttributes(%u, "
            "SCMI_MSG_SYS_POWER_STATE_NOTIFY)\n", channel);
        CHECK(SCMI_SysProtocolMessageAttributes(channel,
            SCMI_MSG_SYSTEM_POWER_STATE_SET, &attributes));

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_SystemPowerStateSet(SM_SCMI_NUM_CHN, flags,
            SCMI_SYS_STATE_SHUTDOWN), SCMI_ERR_INVALID_PARAMETERS);
    }
    /* ACCESS DENIED */
    else
    {
        /* System Power State Notify */
        NECHECK(SCMI_SysProtocolMessageAttributes(channel,
            SCMI_MSG_SYSTEM_POWER_STATE_NOTIFY, &attributes),
            SCMI_ERR_NOT_SUPPORTED);

        /* System Power State Set */
        NECHECK(SCMI_SysProtocolMessageAttributes(channel,
            SCMI_MSG_SYSTEM_POWER_STATE_SET, &attributes),
            SCMI_ERR_NOT_SUPPORTED);
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI performance functions with EXCLUSIVE access                    */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiSystemExclusive(bool pass, uint32_t channel,
    uint32_t lmId)
{
}

