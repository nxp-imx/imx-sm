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
/* Unit test for the SCMI control protocol.                                 */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "lmm.h"
#include "rpc_scmi_misc.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiMiscGet(bool pass, uint32_t channel,
    uint32_t ctrlId);
static void TEST_ScmiMiscNotify(bool pass, uint32_t channel,
    uint32_t ctrlId);
static void TEST_ScmiMiscExclusive(bool pass, uint32_t channel,
    uint32_t ctrlId, uint32_t lmId);

/*--------------------------------------------------------------------------*/
/* Test SCMI control protocol                                               */
/*--------------------------------------------------------------------------*/
void TEST_ScmiMisc(void)
{
    int32_t status = 0;
    uint32_t agentId = 0U;
    uint32_t channel = 0U;
    uint32_t ctrlId = 0U;
    uint32_t numCtrl = 0U;
    uint32_t lmId = 0U;

    /* Control tests */
    printf("**** Control Protocol Tests ***\n\n");

    /* Test protocol version */
    {
        uint32_t ver = 0U;

        printf("SCMI_MiscProtocolVersion()\n");
        CHECK(SCMI_MiscProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_MISC_PROT_VER);
    }

    /* Test protocol attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_MiscProtocolAttributes()\n");
        CHECK(SCMI_MiscProtocolAttributes(SM_TEST_DEFAULT_CHN,
            &attributes));
        numCtrl = SCMI_MISC_PROTO_ATTR_NUM_CTRL(attributes);
        printf("  numCtrl=%u\n", numCtrl);
    }

    /* Test message attributes */
    {
        printf("SCMI_MiscProtocolMessageAttributes(CONTROL_GET)\n");
        CHECK(SCMI_MiscProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_MISC_CONTROL_GET, NULL));

        NCHECK(SCMI_MiscProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            30U, NULL));
    }

    /* Test build info */
    {
        uint32_t buildNum = 0U;
        uint32_t buildCommit = 0U;
        uint8_t buildDate[SCMI_MISC_MAX_BUILDDATE];
        uint8_t buildTime[SCMI_MISC_MAX_BUILDDATE];

        printf("SCMI_MiscDiscoverBuildInfo(%u)\n",
            SM_TEST_DEFAULT_CHN);
        buildDate[0] = 0U;
        buildTime[0] = 0U;
        CHECK(SCMI_MiscDiscoverBuildInfo(SM_TEST_DEFAULT_CHN, &buildNum,
            &buildCommit, buildDate, buildTime));
        printf("  buildNum=%u\n",  buildNum);
        printf("  buildCommit=%08x\n",  buildCommit);
        printf("  buildDate=%s\n",  buildDate);
        printf("  buildTime=%s\n",  buildTime);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscDiscoverBuildInfo(SM_SCMI_NUM_CHN, NULL,
            NULL, NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_MiscDiscoverBuildInfo(SM_TEST_DEFAULT_CHN, NULL,
            NULL, NULL, NULL));
    }

    /* Test ROM data */
    {
        uint32_t numPassover = 0U;
        uint32_t passoverBuffer[SCMI_MISC_MAX_PASSOVER] = {};
        const rom_passover_t *passover
            = (const rom_passover_t*) passoverBuffer;

        printf("SCMI_MiscRomPassoverGet(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_MiscRomPassoverGet(SM_TEST_DEFAULT_CHN, &numPassover,
            passoverBuffer));
        printf("  tag=0x%X\n", passover->tag);
        printf("  size=0x%X\n", passover->size);
        printf("  ver=0x%X\n", passover->ver);
        printf("  bootStage=0x%X\n", passover->bootStage);
        printf("  bootDevType=0x%X\n", passover->bootDevType);
        printf("  bootDevInst=0x%X\n", passover->bootDevInst);
        printf("  devPageSize=0x%X\n", passover->devPageSize);
        printf("  imgOfs=0x%X\n", passover->imgOfs);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscRomPassoverGet(SM_SCMI_NUM_CHN, NULL,
            NULL), SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        CHECK(SCMI_MiscRomPassoverGet(SM_TEST_DEFAULT_CHN, NULL,
            NULL));
    }

    /* Control Set */
    {
        /* Control Set -- Invalid ctrlId */
        uint32_t val = 0x1234ABCDU;

        NECHECK(SCMI_MiscControlSet(SM_TEST_DEFAULT_CHN, numCtrl,
            1U, &val), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscControlSet(SM_SCMI_NUM_CHN, 0U,
            1U, &val), SM_ERR_INVALID_PARAMETERS);
    }

    /* Control Get */
    {
        /* Control Get -- Invalid ctrlId */
        NECHECK(SCMI_MiscControlGet(SM_TEST_DEFAULT_CHN, numCtrl, NULL,
            NULL), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscControlGet(SM_SCMI_NUM_CHN, 0U, NULL, NULL),
            SM_ERR_INVALID_PARAMETERS);
    }

    /* Control Action */
    {
        /* Control Action -- Invalid ctrlId */
        const uint32_t arg[3] = {5U, 1U, 2U};
        uint32_t numVal = 0U;
        uint32_t rtnVal[5] = {0U, 0U, 0U, 0U, 0U};

        NECHECK(SCMI_MiscControlAction(SM_TEST_DEFAULT_CHN, numCtrl, 23U,
            3, arg, &numVal, rtnVal), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscControlAction(SM_SCMI_NUM_CHN, 0U, 23U,
            3, arg, NULL, NULL), SM_ERR_INVALID_PARAMETERS);
    }

    /* Control Notify */
    {
        /* Control Notify -- Invalid ctrlId */
        printf("SCMI_MiscControlNotify(%u, %u)\n", SM_TEST_DEFAULT_CHN,
            ctrlId);
        NECHECK(SCMI_MiscControlNotify(SM_TEST_DEFAULT_CHN, numCtrl, 1U),
            SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscControlNotify(SM_SCMI_NUM_CHN, 0U, 1U),
            SM_ERR_INVALID_PARAMETERS);
    }

    /* Test reset reason */
    {
        uint32_t flags = SCMI_MISC_REASON_FLAG_SYSTEM(0U);
        uint32_t bootFlags = 0U;
        uint32_t shutdownFlags = 0U;
        uint32_t extInfo[SCMI_MISC_MAX_EXTINFO];

        printf("SCMI_MiscResetReason(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_MiscResetReason(SM_TEST_DEFAULT_CHN, flags, &bootFlags,
            &shutdownFlags, extInfo));

        printf("  bootFlags.valid=%u\n",
            SCMI_MISC_BOOT_FLAG_ORG_VLD(bootFlags));
        printf("  bootFlags.origin=%u\n",
            SCMI_MISC_BOOT_FLAG_ORIGIN(bootFlags));
        printf("  bootFlags.errId=%u\n",
            SCMI_MISC_BOOT_FLAG_ERR_ID(bootFlags));
        printf("  bootFlags.reason=%u\n",
            SCMI_MISC_BOOT_FLAG_REASON(bootFlags));

        printf("  shutdownFlags.extLen=%u\n",
            SCMI_MISC_SHUTDOWN_FLAG_EXT_LEN(shutdownFlags));
        printf("  shutdownFlags.valid=%u\n",
            SCMI_MISC_SHUTDOWN_FLAG_ORG_VLD(shutdownFlags));
        printf("  shutdownFlags.origin=%u\n",
            SCMI_MISC_SHUTDOWN_FLAG_ORIGIN(shutdownFlags));
        printf("  shutdownFlags.errId=%u\n",
            SCMI_MISC_SHUTDOWN_FLAG_ERR_ID(shutdownFlags));
        printf("  shutdownFlags.reason=%u\n",
            SCMI_MISC_SHUTDOWN_FLAG_REASON(shutdownFlags));

        for (uint32_t i = 0U; i <
            SCMI_MISC_SHUTDOWN_FLAG_EXT_LEN(shutdownFlags); i++)
        {
            printf("  extInfo[%u]=0x%08X\n", i, extInfo[i]);
        }

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscResetReason(SM_SCMI_NUM_CHN, flags, &bootFlags,
            &shutdownFlags, extInfo), SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Null params */
        CHECK(SCMI_MiscResetReason(SM_TEST_DEFAULT_CHN, flags, NULL,
            NULL, NULL));
    }

    /* Invalid notification */
    {
        scmi_msg_id_t msgId =
        {
            .protocolId = 0xFFU,
            .messageId = 0xFFU
        };
        lmm_rpc_trigger_t trigger = {};

        printf("RPC_SCMI_MiscDispatchNotification()\n");
        RPC_SCMI_MiscDispatchNotification(msgId, trigger);
    }

    /* Loop over control test domains */
    status = TEST_ConfigFirstGet(TEST_CTRL, &agentId,
        &channel, &ctrlId, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].ctrlPerms[ctrlId];

        /* Test functions with GET perm required */
        TEST_ScmiMiscGet(perm >= SM_SCMI_PERM_GET, channel, ctrlId);

        /* Test functions with notify perms required */
        TEST_ScmiMiscNotify(perm >= SM_SCMI_PERM_NOTIFY,channel, ctrlId);

        /* Test functions with EXCLUSIVE perm required */
        TEST_ScmiMiscExclusive(perm >= SM_SCMI_PERM_EXCLUSIVE, channel,
            ctrlId, lmId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_CTRL, &agentId,
            &channel, &ctrlId, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI control functions with GET access                              */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiMiscGet(bool pass, uint32_t channel,
    uint32_t ctrlId)
{
    uint32_t numVal = 0U;
    uint32_t val = 0U;

    /* Adequate Set Permissions */
    if (pass)
    {
        printf("SCMI_MiscControlGet(%u, %u)\n", channel, ctrlId);
        CHECK(SCMI_MiscControlGet(channel, ctrlId, &numVal, &val));

        /* Branch -- Nullpointer */
        CHECK(SCMI_MiscControlGet(channel, ctrlId, NULL, NULL));
    }
    /* ACCESS DENIED */
    else
    {
        NECHECK(SCMI_MiscControlGet(channel, ctrlId, &numVal, &val),
            SCMI_ERR_DENIED);
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI control functions with Notify access                           */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiMiscNotify(bool pass, uint32_t channel,
    uint32_t ctrlId)
{
    /* Adequate Permissions */
    if (pass)
    {
        /* Misc Control Notify & Event */
        uint32_t flags = 1U;

        /* Request notification */
        printf("SCMI_MiscControlNotify(%u, %u)\n", channel, ctrlId);
        CHECK(SCMI_MiscControlNotify(channel, ctrlId, flags));

        /* Wait for the notification */
        printf("Wait for notification...\n");
        printf("SCMI_MiscControlEvent(%u, %u)\n", channel, ctrlId);

        uint32_t recChannel = channel + 1U;
        uint32_t tempId = ctrlId;

        CHECK(SCMI_MiscControlEvent(recChannel, &tempId, &flags));

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscControlEvent(SM_SCMI_NUM_CHN, NULL, NULL),
            SCMI_ERR_INVALID_PARAMETERS);

        /* Branch -- Nullpointer */
        flags = 1U;

        /* Request notification */
        printf("SCMI_MiscControlNotify(%u, %u)\n", channel, ctrlId);
        CHECK(SCMI_MiscControlNotify(channel, ctrlId, flags));

        /* Wait for the notification */
        printf("Wait for notification...\n");
        printf("SCMI_MiscControlEvent(%u, %u)\n", channel, ctrlId);

        tempId = ctrlId;

        CHECK(SCMI_MiscControlEvent(recChannel, NULL, NULL));

    }
    /* ACCESS DENIED */
    else
    {
        /* Request notification */
        printf("SCMI_MiscControlNotify(%u, %u)\n", channel, ctrlId);
        NECHECK(SCMI_MiscControlNotify(channel, ctrlId, 1U),
            SCMI_ERR_DENIED);
    }

}

/*--------------------------------------------------------------------------*/
/* Test SCMI control functions with EXCLUSIVE access                        */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiMiscExclusive(bool pass, uint32_t channel,
    uint32_t ctrlId, uint32_t lmId)
{
    uint32_t val = 0x1234ABCDU;
    const uint32_t arg[3] = {5U, 1U, 2U};
    uint32_t numVal = 0U;
    uint32_t rtnVal[5] = {0U, 0U, 0U, 0U, 0U};

    /* Adequate Set Permissions */
    if (pass)
    {
        /* Control Set */
        printf("SCMI_MiscControlSet(%u, %u)\n", channel, ctrlId);
        CHECK(SCMI_MiscControlSet(channel, ctrlId,
            1U, &val));

        printf("SCMI_MiscControlGet(%u, %u)\n", channel, ctrlId);
        CHECK(SCMI_MiscControlGet(channel, ctrlId, &numVal, rtnVal));

        if ((numVal != 1U) || (rtnVal[0] != 0x1234ABCDU))
        {
            CHECK(SM_ERR_TEST);
        }

        /* Control Action */
        printf("SCMI_MiscControlAction(%u, %u)\n", channel, ctrlId);
        CHECK(SCMI_MiscControlAction(channel, ctrlId, 23U, 3, arg,
            &numVal, rtnVal));

        if (numVal != 3U)
        {
            CHECK(SM_ERR_TEST);
        }
        else
        {
            for (uint32_t idx = 0U; idx < numVal; idx++)
            {
                printf("  rtnVal[%u] = %u\n", idx, rtnVal[idx]);
            }
        }

        /* Branch -- Nullpointer */
        CHECK(SCMI_MiscControlAction(channel, ctrlId, 23U,
            3, arg, NULL, NULL));

#ifdef SIMU
        /* Reset Config */
        if (pass)
        {
            /* Reset */
            uint32_t sysManager = 0U;
            printf("LMM_SystemLmShutdown(%u, %u)\n", sysManager, lmId);
            CHECK(LMM_SystemLmShutdown(sysManager, 0U, lmId, false, &g_swReason));
        }
#endif
    }
    /* Access denied */
    else
    {
        /* Control Set */
        NECHECK(SCMI_MiscControlSet(channel, ctrlId,
            1U, &val), SCMI_ERR_DENIED);

        /* Control Action */
        NECHECK(SCMI_MiscControlAction(channel, ctrlId, 23U, 3, arg,
            &numVal, rtnVal), SCMI_ERR_DENIED);
    }
}

