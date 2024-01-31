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
/* Unit test for the SCMI BBM RTC protocol.                                 */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "lmm.h"
#include "scmi_internal.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiRtcNone(uint32_t channel, uint32_t resource);
static void TEST_ScmiRtcPriv(bool pass, uint32_t channel,
    uint32_t resource);
static void TEST_ScmiRtcExclusive(bool pass, uint32_t channel,
    uint32_t resource, uint32_t lmId);

/*--------------------------------------------------------------------------*/
/* Test SCMI BBM RTC protocol                                               */
/*--------------------------------------------------------------------------*/
void TEST_ScmiBbmRtc(void)
{
    int32_t status = 0;
    uint32_t agentId, channel, resource, numRtc, lmId = 0U;

    /* BBM tests */
    printf("**** Battery-backed Module RTC Protocol Tests ***\n\n");

    /* Test protocol attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_BbmProtocolAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_BbmProtocolAttributes(SM_TEST_DEFAULT_CHN,
            &attributes));
        numRtc = SCMI_BBM_PROTO_ATTR_NUM_RTC(attributes);
        printf("  numRtc=%u\n", numRtc);
    }

    /* Attributes -- invalid RTC and invalid channel*/
    {
        uint32_t attributes = 0U;
        uint8_t name[SCMI_BBM_MAX_NAME] = { 0 };

        NECHECK(SCMI_BbmRtcAttributes(SM_TEST_DEFAULT_CHN,
            numRtc, &attributes, name), SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_BbmRtcAttributes(SM_SCMI_NUM_CHN,
            numRtc, &attributes, name), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* RTC Time Get -- invalid RTC and invalid channel*/
    {
        uint32_t flags = 0U;
        scmi_rtc_time_t val;

        NECHECK(SCMI_BbmRtcTimeGet(SM_TEST_DEFAULT_CHN,
            numRtc, flags, &val), SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_BbmRtcTimeGet(SM_SCMI_NUM_CHN,
            numRtc, flags, &val), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* RTC Set -- invalid RTC invalid channel*/
    {
        uint32_t flags = 0U;
        scmi_rtc_time_t val;
        val.upper = 0U;
        val.lower = 0U;

        NECHECK(SCMI_BbmRtcTimeSet(SM_TEST_DEFAULT_CHN,
            numRtc, flags, val), SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_BbmRtcTimeSet(SM_SCMI_NUM_CHN,
            numRtc, flags, val), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* RTC Notify -- invalid RTC invalid channel*/
    {
        uint32_t flags = 0U;

        NECHECK(SCMI_BbmRtcNotify(SM_TEST_DEFAULT_CHN,
            numRtc, flags), SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_BbmRtcNotify(SM_SCMI_NUM_CHN,
            numRtc, flags), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Alarm Set -- invalid RTC and invalid */
    {
        uint32_t flags = 0U;
        scmi_rtc_time_t val;
        val.upper = 0U;
        val.lower = 0U;

        NECHECK(SCMI_BbmRtcAlarmSet(SM_TEST_DEFAULT_CHN,
            numRtc, flags, val), SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_BbmRtcAlarmSet(SM_SCMI_NUM_CHN,
            numRtc, flags, val), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Invalid channel */
    {
        uint32_t flags = 0;

        NECHECK(SCMI_BbmRtcEvent(SM_SCMI_NUM_CHN,
            &flags), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Test message attributes */
    {
        printf("SCMI_BbmProtocolMessageAttributes(%u, RTC_TIME_GET)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_BbmProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_BBM_RTC_TIME_GET, NULL));

        NCHECK(SCMI_BbmProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            30U, NULL));
    }

    /* Loop over BBM test resources */
    status = TEST_ConfigFirstGet(TEST_RTC, &agentId,
        &channel, &resource, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].rtcPerms[resource];

        /* Test functions with no perm required */
        TEST_ScmiRtcNone(channel, resource);

        /* Test functions with PRIV perm required */
        TEST_ScmiRtcPriv(perm >= SM_SCMI_PERM_PRIV, channel, resource);

        /* Test functions with EXCLUSIVE perm required */
        TEST_ScmiRtcExclusive(perm >= SM_SCMI_PERM_EXCLUSIVE,
            channel, resource, lmId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_RTC, &agentId,
            &channel, &resource, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI BBM functions with no access                                   */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiRtcNone(uint32_t channel, uint32_t resource)
{
    /* RTC Time Get */
    {
        uint32_t flags = SCMI_BBM_RTC_FLAGS_TICKS(1U);
        scmi_rtc_time_t val = {0U, 0U};

        printf("SCMI_BbmRtcTimeGet(%u, 0x%X)\n", channel, flags);
        CHECK(SCMI_BbmRtcTimeGet(channel, resource, flags, &val));

        flags = SCMI_BBM_RTC_FLAGS_TICKS(0U);
        printf("SCMI_BbmRtcTimeGet(%u, 0x%X)\n", channel, flags);
        CHECK(SCMI_BbmRtcTimeGet(channel, resource, flags, &val));

        CHECK(SCMI_BbmRtcTimeGet(channel, resource, flags, NULL));
    }

    /* RTC Attributes  */
    {
        uint32_t attributes = 0U;
        uint8_t name[SCMI_BBM_MAX_NAME] = { 0 };

        printf("SCMI_BbmRtcAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_BbmRtcAttributes(channel,
            resource, &attributes, name));

        CHECK(SCMI_BbmRtcAttributes(channel,
            resource, NULL, NULL));
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI BBM functions with PRIV access                                 */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiRtcPriv(bool pass, uint32_t channel,
    uint32_t resource)
{
    if (pass)
    {
        uint32_t flags = SCMI_BBM_RTC_FLAGS_TICKS(0U);
        scmi_rtc_time_t val = {0U, 0U};

        printf("SCMI_BbmRtcTimeGet(%u, 0x%X)\n", channel, flags);
        CHECK(SCMI_BbmRtcTimeGet(channel, resource, flags, &val));

        flags = SCMI_BBM_ALARM_FLAGS_ENABLE(1U);
        val.lower += 2U;

        /* RPC_00260 Set the alarm */
        printf("SCMI_BbmRtcAlarmSet(%u, 0x%X, %u)\n", channel, flags,
            val.lower);
        CHECK(SCMI_BbmRtcAlarmSet(channel, resource, flags, val));
        flags = SCMI_BBM_NOTIFY_RTC_ALARM(1U);

        /* RPC_00270 Request notification */
        printf("SCMI_BbmNotify(%u, 0x%X)\n", channel, flags);
        CHECK(SCMI_BbmRtcNotify(channel, resource, flags));

        /* Wait for the notification */
        printf("Wait for alarm ...\n");
        {
            int32_t status;
            uint32_t protocolId = 0U;
            uint32_t messageId = 0U;

            do
            {
                status = SCMI_P2aPending(channel + 1U, &protocolId,
                    &messageId);
            }
            while (status != SCMI_ERR_SUCCESS);

            BCHECK(protocolId == SCMI_PROTOCOL_BBM);
            BCHECK(messageId == 0U);
        }

        /* Collect pending event */
        printf("SCMI_BbmRtcEvent(%u)\n", channel + 1U);
        CHECK(SCMI_BbmRtcEvent(channel + 1U, &flags));
        if (SCMI_BBM_EVENT_RTC_ALARM(flags) != 1U)
        {
            CHECK(SM_ERR_TEST);
        }
        CHECK(SCMI_BbmRtcNotify(channel, resource, 0U));

        /* Invalid Alarm, set in the past */
        flags = SCMI_BBM_ALARM_FLAGS_ENABLE(1U);
        val.lower = 0U;

        NECHECK(SCMI_BbmRtcAlarmSet(channel, resource, flags, val),
            SCMI_ERR_INVALID_PARAMETERS);
    }
    else
    {
        uint32_t flags = SCMI_BBM_ALARM_FLAGS_ENABLE(1U);
        scmi_rtc_time_t val = {10004U, 0U};

        NCHECK(SCMI_BbmRtcAlarmSet(channel, resource, flags, val));
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI BBM functions with EXCLUSIVE access                            */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiRtcExclusive(bool pass, uint32_t channel,
    uint32_t resource, uint32_t lmId)
{
    uint32_t flags = SCMI_BBM_RTC_FLAGS_TICKS(1U);
    scmi_rtc_time_t val = {5000U, 0U};

    printf("SCMI_BbmRtcTimeSet(%u, 0x%X, %u)\n", channel, flags,
        val.lower);
    XCHECK(pass, SCMI_BbmRtcTimeSet(channel, resource, flags, val));

    flags = SCMI_BBM_RTC_FLAGS_TICKS(0U);
    val.lower = 10000U;
    printf("SCMI_BbmRtcTimeSet(%u, 0x%X, %u)\n", channel, flags,
        val.lower);
    XCHECK(pass, SCMI_BbmRtcTimeSet(channel, resource, flags, val));

    if (pass)
    {
        printf("SCMI_BbmRtcTimeGet(%u, 0x%X)\n", channel, flags);
        CHECK(SCMI_BbmRtcTimeGet(channel, resource, flags, &val));
        printf("Wait two seconds ...\n");
        while (val.lower < 10002U)
        {
            CHECK(SCMI_BbmRtcTimeGet(channel, resource, flags, &val));
        }
    }

    /* RPC_00270 Test RTC rollover */
    flags = SCMI_BBM_RTC_FLAGS_TICKS(0U);
    val.lower = 0xFFFFFFFEU;
    printf("SCMI_BbmRtcTimeSet(%u, 0x%X, %u)\n", channel, flags,
        val.lower);
    XCHECK(pass, SCMI_BbmRtcTimeSet(channel, resource, flags, val));
    flags = SCMI_BBM_NOTIFY_RTC_ROLLOVER(1U);
    printf("SCMI_BbmNotify(%u, 0x%X)\n", channel, flags);
    XCHECK(pass, SCMI_BbmRtcNotify(channel, resource, flags));
    if (pass)
    {
        printf("Wait for rollover ...\n");
        CHECK(SCMI_BbmRtcEvent(channel + 1U, &flags));
        if (SCMI_BBM_EVENT_RTC_ROLLOVER(flags) != 1U)
        {
            CHECK(SM_ERR_TEST);
        }
    }
    XCHECK(pass, SCMI_BbmRtcNotify(channel, resource, 0U));

    /* Notification - Rollover */
    if (pass)
    {
        /* Request to notify on rollover */
        flags = SCMI_BBM_NOTIFY_RTC_ROLLOVER(1U);
        printf("SCMI_BbmNotify(%u, 0x%X)\n", channel, flags);
        CHECK(SCMI_BbmRtcNotify(channel, resource, flags));

        /* Change Time */
        flags = SCMI_BBM_RTC_FLAGS_TICKS(0U);
        val.lower = 0xFFFFFFFEU;
        printf("SCMI_BbmRtcTimeSet(%u, 0x%X, %u)\n", channel, flags,
            val.lower);
        CHECK(SCMI_BbmRtcTimeSet(channel, resource, flags, val));

        /* Event */
        printf("Wait for rollover notification ...\n");
        CHECK(SCMI_BbmRtcEvent(channel + 1U, &flags));
        if (SCMI_BBM_EVENT_RTC_ROLLOVER(flags) != 1U)
        {
            CHECK(SM_ERR_TEST);
        }
    }

    flags = SCMI_BBM_RTC_FLAGS_TICKS(0U);
    val.lower = 10000U;
    printf("SCMI_BbmRtcTimeSet(%u, 0x%X, %u)\n", channel, flags,
        val.lower);
    XCHECK(pass, SCMI_BbmRtcTimeSet(channel, resource, flags, val));

    /* RPC_00270 Notification - Updated Time */
    if (pass)
    {
        /* Request to notify when updated */
        flags = SCMI_BBM_NOTIFY_RTC_UPDATED(1U);
        printf("SCMI_BbmNotify(%u, 0x%X)\n", channel, flags);
        CHECK(SCMI_BbmRtcNotify(channel, resource, flags));

        /* Change Time */
        flags = SCMI_BBM_RTC_FLAGS_TICKS(0U);
        val.lower = 10000U;
        printf("SCMI_BbmRtcTimeSet(%u, 0x%X, %u)\n", channel, flags,
            val.lower);
        CHECK(SCMI_BbmRtcTimeSet(channel, resource, flags, val));

        /* Event */
        printf("Wait for update ...\n");
        CHECK(SCMI_BbmRtcEvent(channel + 1U, &flags));
        if (SCMI_BBM_EVENT_RTC_UPDATED(flags) != 1U)
        {
            CHECK(SM_ERR_TEST);
        }

        /* Pass in NULL for flags on BbmRtcEvent*/
        uint32_t flags2 = SCMI_BBM_NOTIFY_RTC_UPDATED(1U);
        scmi_rtc_time_t val2 = {5000U, 0U};

        /* Request to notify when updated */
        CHECK(SCMI_BbmRtcNotify(channel, resource, flags2));

        /* Change Time */
        flags2 = SCMI_BBM_RTC_FLAGS_TICKS(0U);
        val2.lower = 20000U;
        CHECK(SCMI_BbmRtcTimeSet(channel, resource, flags2, val2));

        /* Event */
        CHECK(SCMI_BbmRtcEvent(channel + 1U, NULL));
    }

#ifdef SIMU
    /* Reset Config */
    if (pass)
    {
        scmi_rtc_time_t resetVal = {0U, 0U};

        /* Get current time */
        printf("SCMI_BbmRtcTimeGet(%u, 0x%X)\n", channel, flags);
        CHECK(SCMI_BbmRtcTimeGet(channel, resource, flags, &resetVal));

        uint32_t resetFlags = SCMI_BBM_ALARM_FLAGS_ENABLE(1U);
        resetVal.lower += 2U;

        /* Set the alarm */
        printf("SCMI_BbmRtcAlarmSet(%u, 0x%X, %u)\n", channel, resetFlags,
            val.lower);
        CHECK(SCMI_BbmRtcAlarmSet(channel, resource, resetFlags, resetVal));

        /* Reset */
        uint32_t sysManager = 0U;
        printf("LMM_SystemLmShutdown(%u, %u)\n", sysManager, lmId);
        CHECK(LMM_SystemLmShutdown(sysManager, 0U, lmId, false, &g_swReason));
    }
#endif
}

