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
/* Unit test for the SCMI LMM protocol.                                     */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "lmm.h"
#include "rpc_scmi_lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiLmmNotify(bool pass, uint32_t channel,
    uint32_t lm);
static void TEST_ScmiLmmGet(bool pass, uint32_t channel, uint32_t lm);
static void TEST_ScmiLmmSet(bool pass, uint32_t channel, uint32_t lm,
    uint32_t lmId);
static void TEST_ScmiLmmPriv(bool pass, uint32_t channel, uint32_t lm,
    uint32_t lmId);

/*--------------------------------------------------------------------------*/
/* Test SCMI LMM protocol                                                   */
/*--------------------------------------------------------------------------*/
void TEST_ScmiLmm(void)
{
    int32_t status = 0;
    uint32_t numLm = 0U;
    uint32_t agentId, channel, lm, lmId = 0U;

    /* LM_00010 RPC_00180 RPC_00160 LMM tests */
    printf("**** LMM Protocol Tests ***\n\n");

    /* Test protocol version */
    {
        uint32_t ver = 0U;

        printf("SCMI_LmmProtocolVersion()\n");
        CHECK(SCMI_LmmProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_LMM_PROT_VER);
    }

    /* Test protocol attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_LmmProtocolAttributes(0)\n");
        CHECK(SCMI_LmmProtocolAttributes(SM_TEST_DEFAULT_CHN, &attributes));
        numLm =
            SCMI_LMM_PROTO_ATTR_NUM_LM(attributes);
        printf("  numLm=%u\n", numLm);
    }

    /* Test SCMI_LmmNegotiateProtocolVersion */
    {
        uint32_t version = 1234U;

        printf(" SCMI_LmmNegotiateProtocolVersion\n");
        NECHECK( SCMI_LmmNegotiateProtocolVersion(SM_TEST_DEFAULT_CHN,
            version), SCMI_ERR_NOT_SUPPORTED);
    }

    /* Test LMM message attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_LmmProtocolAttributes(0)\n");
        CHECK(SCMI_LmmProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_LMM_ATTRIBUTES, &attributes));
    }

    /* Test LMM attributes for invalid domain */
    {
        printf("SCMI_LmmAttributes(%u)\n", numLm);
        NCHECK(SCMI_LmmAttributes(SM_TEST_DEFAULT_CHN, &numLm, NULL, NULL,
            NULL, NULL));
    }

    /* Test LMM attributes for invalid domain */
    {
        printf("SCMI_LmmAttributes(%u)\n", numLm);
        NCHECK(SCMI_LmmAttributes(SM_TEST_DEFAULT_CHN, NULL, NULL, NULL,
            NULL, NULL));

        NECHECK(SCMI_LmmAttributes(SM_SCMI_NUM_CHN, NULL, NULL, NULL,
            NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* LmmBoot -- Invalid lm */
    {
        printf("SCMI_LmmBoot(%u, %u)\n", SM_TEST_DEFAULT_CHN, numLm);
        NECHECK(SCMI_LmmBoot(SM_TEST_DEFAULT_CHN, numLm),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_LmmBoot(SM_SCMI_NUM_CHN, numLm),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* LmmReset -- Invalid lm */
    {
        uint32_t flags = 0U;

        printf("SCMI_LmmReset(%u, %u, false)\n", SM_TEST_DEFAULT_CHN, numLm);
        NECHECK(SCMI_LmmReset(SM_TEST_DEFAULT_CHN, numLm, flags),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_LmmReset(SM_SCMI_NUM_CHN, numLm, flags),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* LmmSuspend -- Invalid lm */
    {
        printf("SCMI_LmmSuspend(%u, %u)\n", SM_TEST_DEFAULT_CHN, numLm);
        NECHECK(SCMI_LmmSuspend(SM_TEST_DEFAULT_CHN, numLm),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_LmmSuspend(SM_SCMI_NUM_CHN, numLm),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* LmmShutdown -- Invalid lm */
    {
        uint32_t flags = 0U;

        printf("SCMI_LmmShutdown(%u, %u)\n", SM_TEST_DEFAULT_CHN, numLm);
        NECHECK(SCMI_LmmShutdown(SM_TEST_DEFAULT_CHN, numLm, flags),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_LmmShutdown(SM_SCMI_NUM_CHN, numLm, flags),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* LmmWake -- Invalid lm */
    {
        printf("SCMI_LmmWake(%u, %u)\n", SM_TEST_DEFAULT_CHN, numLm);
        NECHECK(SCMI_LmmWake(SM_TEST_DEFAULT_CHN, numLm),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_LmmWake(SM_SCMI_NUM_CHN, numLm),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* LmmNotify -- Invalid lm */
    {
        uint32_t flags = 0U;

        printf("SCMI_LmmNotify(%u, %u, 0x%08X)\n",
            SM_TEST_DEFAULT_CHN, numLm, flags);
        NECHECK(SCMI_LmmNotify(SM_TEST_DEFAULT_CHN, numLm, flags),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_LmmNotify(SM_SCMI_NUM_CHN, numLm, flags),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    {
        NECHECK(SCMI_LmmEvent(SM_SCMI_NUM_CHN, NULL, NULL, NULL),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* LmmPowerOn Invalid lm Invalid channel */
    {
        printf("SCMI_LmmPowerOn(%u, %u)\n", SM_TEST_DEFAULT_CHN, numLm);
        NECHECK(SCMI_LmmPowerOn(SM_TEST_DEFAULT_CHN, numLm),
            SCMI_ERR_NOT_FOUND);

        printf("SCMI_LmmPowerOn(%u, %u)\n", SM_SCMI_NUM_CHN, numLm);
        NECHECK(SCMI_LmmPowerOn(SM_SCMI_NUM_CHN, numLm),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Invalid notification */
    {
        scmi_msg_id_t msgId =
        {
            .protocolId = 0xFFU,
            .messageId = 0xFFU
        };
        lmm_rpc_trigger_t trigger = { 0 };

        printf("RPC_SCMI_LmmDispatchNotification()\n");
        NCHECK(RPC_SCMI_LmmDispatchNotification(msgId, &trigger));
    }

    /* LmmShutdown Invalid lm Invalid domain*/
    {
        uint32_t bootFlags = 0U, shutdownFlags = 0U, extInfo = 0U;
        printf("SCMI_LmmResetReason(%u, %u)\n", SM_TEST_DEFAULT_CHN, numLm);
        NECHECK(SCMI_LmmResetReason(SM_TEST_DEFAULT_CHN, numLm, &bootFlags,
            &shutdownFlags, &extInfo), SCMI_ERR_NOT_FOUND);

        printf("SCMI_LmmResetReason(%u, %u)\n", SM_SCMI_NUM_CHN, numLm);
        NECHECK(SCMI_LmmResetReason(SM_SCMI_NUM_CHN, numLm, &bootFlags,
            &shutdownFlags, &extInfo), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Loop over power test domains */
    status = TEST_ConfigFirstGet(TEST_LMM, &agentId,
        &channel, &lm, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].lmmPerms[lm];

        /* Test functions with GET perm required */
        TEST_ScmiLmmGet(perm >= SM_SCMI_PERM_GET, channel, lm);

        /* RPC_00170 Test functions with NOTIFY perm required */
        TEST_ScmiLmmNotify(perm >= SM_SCMI_PERM_NOTIFY,
            channel, lm);

        /* Test functions with SET perm required */
        TEST_ScmiLmmSet(perm >= SM_SCMI_PERM_SET, channel, lm, lmId);

        /* Test functions with PRIV perm required */
        TEST_ScmiLmmPriv(perm >= SM_SCMI_PERM_PRIV,
            channel, lm, lmId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_LMM, &agentId,
            &channel, &lm, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI LMM functions with NOTIFY access                               */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiLmmNotify(bool pass, uint32_t channel, uint32_t lm)
{
    uint32_t flags = SCMI_LMM_NOTIFY_BOOT(0U) | SCMI_LMM_NOTIFY_SHUTDOWN(0U);

    /* LM_00040 LM_00050 Adequate Access Permissions */
    if (pass)
    {
        printf("SCMI_LmmNotify(%u, %u, 0x%08X)\n", channel, lm, flags);
        CHECK(SCMI_LmmNotify(channel, lm, flags));
    }
    /* Access denied */
    else
    {
        printf("SCMI_LmmNotify(%u, %u, 0x%08X)\n", channel, lm, flags);
        NECHECK(SCMI_LmmNotify(channel, lm, flags), SCMI_ERR_DENIED);
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI LMM functions with GET access                                  */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiLmmGet(bool pass, uint32_t channel, uint32_t lm)
{
    /* Test LMM attributes */
    {
        uint32_t attributes = 0U;
        uint32_t state = 0U;
        int32_t errStatus = 0;
        uint8_t name[SCMI_LMM_MAX_NAME];
        uint32_t newlm = lm;

        /* RPC_00220 Get status */
        printf("SCMI_LmmAttributes(%u, %u)\n", channel, newlm);
        name[0] = 0U;

        /* Adequate Permissions */
        if (pass)
        {
            CHECK(SCMI_LmmAttributes(channel, &newlm, &attributes,
                &state, &errStatus, name));
            printf("  state=0x%08x\n", state);
            printf("  errStatus=0x%08x\n", errStatus);
            printf("  name=%s\n", name);
        }
        /* ACCESS DENIED */
        else
        {
            NECHECK(SCMI_LmmAttributes(channel, &newlm, &attributes,
                &state, &errStatus, name), SCMI_ERR_DENIED);
        }
    }

    /* Test LMM discovery */
    {
        uint32_t lmm = SCMI_LMM_ID_DISCOVER;
        printf("SCMI_LmmAttributes(%u, %u)\n", channel, lmm);
        CHECK(SCMI_LmmAttributes(channel, &lmm, NULL, NULL,
            NULL, NULL));
        printf("  lm=%u\n", lmm);
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI LMM functions with SET access                                  */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiLmmSet(bool pass, uint32_t channel, uint32_t lm,
    uint32_t lmId)
{
    /* Adequate Permissions */
    if (pass)
    {
        uint32_t flags;

        /* Cause Event to Occur */
        flags = SCMI_LMM_FLAGS_GRACEFUL(0U);
        printf("SCMI_LmmBoot(%u, %u)\n", channel, lm);
        CHECK(SCMI_LmmBoot(channel, lm));

        /* RPC_00210 Send notification -- Shutdown */
        flags = SCMI_LMM_NOTIFY_BOOT(0U) | SCMI_LMM_NOTIFY_SHUTDOWN(1U);
        printf("SCMI_LmmNotify(%u, %u, 0x%08X)\n", channel, lm, flags);
        CHECK(SCMI_LmmNotify(channel, lm, flags));

        /* Cause Event to Occur */
        const uint32_t sequences[24] = { 0U };
        flags = SCMI_LMM_FLAGS_GRACEFUL(0U);
        printf("SCMI_LmmShutdown(%u, %u)\n", channel, lm);
        CHECK(SCMI_LmmShutdown(channel, lm, flags));
        SCMI_SequenceRestore(sequences);

        /* Event */
        {
            flags = 0U;
            uint32_t eventLm = 0U;
            uint32_t recId = 0U;

            printf("SCMI_LmmEvent(%u, %u)\n", channel, lm);
            CHECK(SCMI_LmmEvent(channel + 1U, &recId, &eventLm, &flags));

            BCHECK(SCMI_LMM_EVENT_SHUTDOWN(flags) == 1U);
        }

        /* RPC_00210 Send notification -- Boot */
        flags = SCMI_LMM_NOTIFY_BOOT(1U) | SCMI_LMM_NOTIFY_SHUTDOWN(0U);
        printf("SCMI_LmmNotify(%u, %u, 0x%08X)\n", channel, lm, flags);
        CHECK(SCMI_LmmNotify(channel, lm, flags));

        /* Cause Event to Occur */
        printf("SCMI_LmmBoot(%u, %u)\n", channel, lm);
        CHECK(SCMI_LmmBoot(channel, lm));

        /* Event */
        {
            flags = 0U;
            uint32_t eventLm = 0U;
            uint32_t recId = 0U;

            printf("SCMI_LmmEvent(%u, %u)\n", channel, lm);
            CHECK(SCMI_LmmEvent(channel + 1U, &recId, &eventLm, &flags));

            BCHECK(SCMI_LMM_EVENT_BOOT(flags) == 1U);
        }

#if 0
        /* Branch coverage */
        {
            flags = 0U;
            uint32_t eventLm = 0U;
            uint32_t recId = 0U;

            CHECK(SCMI_LmmBoot(channel, lm));
            CHECK(SCMI_LmmEvent(channel + 1U, NULL, &eventLm, &flags));

            CHECK(SCMI_LmmBoot(channel, lm));
            CHECK(SCMI_LmmEvent(channel + 1U, &recId, NULL, &flags));

            CHECK(SCMI_LmmBoot(channel, lm));
            CHECK(SCMI_LmmEvent(channel + 1U, &recId, &eventLm, NULL));
        }
#endif
        /* No notification */
        flags = SCMI_LMM_NOTIFY_BOOT(0U) | SCMI_LMM_NOTIFY_SHUTDOWN(0U);
        printf("SCMI_LmmNotify(%u, %u, 0x%08X)\n", channel, lm, flags);
        CHECK(SCMI_LmmNotify(channel, lm, flags));

        /* LmmWake -- Call on Self */
        printf("SCMI_LmmWake(%u, %u)\n", channel, lm);
        NECHECK(SCMI_LmmWake(channel, lmId), SCMI_ERR_INVALID_PARAMETERS);
    }
    /* Access denied */
    else
    {
        printf("SCMI_LmmWake(%u, %u)\n", channel, lm);
        NECHECK(SCMI_LmmWake(channel, lm), SCMI_ERR_DENIED);
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI LMM functions with PRIV access                                 */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiLmmPriv(bool pass, uint32_t channel, uint32_t lm,
    uint32_t lmId)
{
    uint32_t flags = 0U;

    /* Adequate Permissions */
    if (pass)
    {
        printf("SCMI_LmmBoot(%u, %u)\n", channel, lm);
        CHECK(SCMI_LmmBoot(channel, lm));
        printf("SCMI_LmmReset(%u, %u, false)\n", channel, lm);
        CHECK(SCMI_LmmReset(channel, lm, flags));
        printf("SCMI_LmmSuspend(%u, %u)\n", channel, lm);
        CHECK(SCMI_LmmSuspend(channel, lm));
        printf("SCMI_LmmShutdown(%u, %u)\n", channel, lm);
        CHECK(SCMI_LmmShutdown(channel, lm, flags));
        printf("SCMI_LmmPowerOn(%u, %u)\n", channel, lm);
        CHECK(SCMI_LmmPowerOn(channel, lm));

        /* LmmBoot -- Call on Self */
        {
            printf("SCMI_LmmBoot(%u, %u)\n", channel, 0U);
            NECHECK(SCMI_LmmBoot(channel, lmId),
                SCMI_ERR_INVALID_PARAMETERS);
        }

        /* LmmReset -- Call on Self */
        {
            printf("SCMI_LmmReset(%u, %u, false)\n", channel, lm);
            NECHECK(SCMI_LmmReset(channel, lmId, flags),
                SCMI_ERR_INVALID_PARAMETERS);
        }

        /* LmmShutdown -- Call on Self */
        {
            printf("SCMI_LmmShutdown(%u, %u)\n", channel, lm);
            NECHECK(SCMI_LmmShutdown(channel, lmId, flags),
                SCMI_ERR_INVALID_PARAMETERS);
        }

        /* LmmShutdown */
        {
            uint32_t bootFlags = 0U, shutdownFlags = 0U, extInfo =0U;
            printf("SCMI_LmmResetReason(%u, %u)\n", channel, lm);
            CHECK(SCMI_LmmResetReason(channel, lmId, &bootFlags,
                &shutdownFlags, &extInfo));

            /* Branch coverage */
            {
                CHECK(SCMI_LmmResetReason(channel, lmId, NULL,
                    &shutdownFlags, &extInfo));
                CHECK(SCMI_LmmResetReason(channel, lmId, &bootFlags,
                    NULL, &extInfo));
                CHECK(SCMI_LmmResetReason(channel, lmId, &bootFlags,
                    &shutdownFlags, NULL));
            }
        }
        /* LM_00020 Reset Config */
#ifdef SIMU
        if (pass)
        {
            /* Reset */
            uint32_t sysManager = 0U;
            printf("LMM_SystemLmShutdown(%u, %u)\n", sysManager, lmId);
            CHECK(LMM_SystemLmShutdown(sysManager, 0U, lmId, false,
                &g_swReason));
        }
#endif
    }
    /* Access denied */
    else
    {
        printf("SCMI_LmmBoot(%u, %u)\n", channel, lm);
        NECHECK(SCMI_LmmBoot(channel, lm), SCMI_ERR_DENIED);
        printf("SCMI_LmmReset(%u, %u, false)\n", channel, lm);
        NECHECK(SCMI_LmmReset(channel, lm, flags), SCMI_ERR_DENIED);
        printf("SCMI_LmmSuspend(%u, %u)\n", channel, lm);
        NECHECK(SCMI_LmmSuspend(channel, lm), SCMI_ERR_DENIED);
        printf("SCMI_LmmShutdown(%u, %u)\n", channel, lm);
        NECHECK(SCMI_LmmShutdown(channel, lm, flags), SCMI_ERR_DENIED);
        printf("SCMI_LmmPowerOn(%u, %u)\n", channel, lm);
        NECHECK(SCMI_LmmPowerOn(channel, lm), SCMI_ERR_DENIED);

        /* LmmShutdown */
        {
            uint32_t bootFlags = 0U, shutdownFlags = 0U, extInfo =0U;
            printf("SCMI_LmmResetReason(%u, %u)\n", channel, lm);
            NECHECK(SCMI_LmmResetReason(channel, lmId, &bootFlags,
                &shutdownFlags, &extInfo), SCMI_ERR_DENIED);
        }
    }
}

