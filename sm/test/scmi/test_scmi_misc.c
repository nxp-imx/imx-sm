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

static uint32_t numDevCtrl = 0U;
static uint32_t numBrdCtrl = 0U;

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
    uint32_t lmId = 0U;

    /* RPC_00350 RPC_00160 Misc tests */
    printf("**** Misc Protocol Tests ***\n\n");

    /* Test protocol version */
    {
        uint32_t ver = 0U;

        printf("SCMI_MiscProtocolVersion()\n");
        CHECK(SCMI_MiscProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_MISC_PROT_VER);
    }

    /* Negotiate Protocol Attributes */
    {
        printf("SCMI_MiscNegotiateProtocolVersion(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_MiscNegotiateProtocolVersion(SM_TEST_DEFAULT_CHN,
            SCMI_MISC_PROT_VER));
    }

    /* Test protocol attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_MiscProtocolAttributes()\n");
        CHECK(SCMI_MiscProtocolAttributes(SM_TEST_DEFAULT_CHN,
            &attributes));
        numDevCtrl = SCMI_MISC_PROTO_ATTR_NUM_DEV_CTRL(attributes);
        numBrdCtrl = SCMI_MISC_PROTO_ATTR_NUM_BRD_CTRL(attributes);
        printf("  numDevCtrl=%u\n", numDevCtrl);
        printf("  numBrdCtrl=%u\n", numBrdCtrl);
    }

    /* Test message attributes */
    {
        printf("SCMI_MiscProtocolMessageAttributes(CONTROL_GET)\n");
        CHECK(SCMI_MiscProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_MISC_CONTROL_GET, NULL));

        NCHECK(SCMI_MiscProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            30U, NULL));
    }

    /* RPC_00400 Test build info */
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

    /* MiscReasonAttributes */
    {
        uint32_t reasonId = DEV_SM_REASON_POR;
        uint32_t attributes = 0U;
        uint8_t name[16];

        printf("SCMI_MiscReasonAttributes(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_MiscReasonAttributes(SM_TEST_DEFAULT_CHN, reasonId,
            &attributes, &name[0]));

        /* Check Invalid reason */
        NECHECK(SCMI_MiscReasonAttributes(SM_TEST_DEFAULT_CHN,
            SM_NUM_REASON, &attributes, &name[0]), SM_ERR_NOT_FOUND);

        /* Invalid channel number */
        NECHECK(SCMI_MiscReasonAttributes(SM_NUM_TEST_CHN, SM_NUM_REASON,
            &attributes, &name[0]), SCMI_ERR_INVALID_PARAMETERS);

#ifdef SIMU
        /* Branch coverage */
        CHECK(SCMI_MiscReasonAttributes(SM_TEST_DEFAULT_CHN,
            DEV_SM_REASON_FAULT, NULL, &name[0]));

        /* Branch coverage */
        CHECK(SCMI_MiscReasonAttributes(SM_TEST_DEFAULT_CHN,
            DEV_SM_REASON_FAULT, &attributes, NULL));
#endif
    }

    /* MiscSiInfo */
    {
        uint32_t deviceId = 0U, siRev = 0U, partNum = 0U;
        uint8_t name[16];

        printf("SCMI_MiscSiInfo(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_MiscSiInfo(SM_TEST_DEFAULT_CHN, &deviceId, &siRev,
            &partNum, &name[0]));
        printf("SCMI_MiscSiInfo deviceId: %u siRev: %u partNum: %u name: %s\n",
            deviceId, siRev, partNum, name);

        /* Branch coverage */
        {
            /* Invalid Channel */
            NECHECK(SCMI_MiscSiInfo(SM_NUM_TEST_CHN, &deviceId, &siRev,
                &partNum, &name[0]), SCMI_ERR_INVALID_PARAMETERS);

            /* deviceId = NULL */
            CHECK(SCMI_MiscSiInfo(SM_TEST_DEFAULT_CHN, NULL, &siRev,
                &partNum, &name[0]));

            /* siRev = NULL */
            CHECK(SCMI_MiscSiInfo(SM_TEST_DEFAULT_CHN, &deviceId, NULL,
                &partNum, &name[0]));

            /* partnum = NULL */
            CHECK(SCMI_MiscSiInfo(SM_TEST_DEFAULT_CHN, &deviceId, &siRev,
                NULL, &name[0]));

            /* name = NULL */
            CHECK(SCMI_MiscSiInfo(SM_TEST_DEFAULT_CHN, &deviceId, &siRev,
                &partNum, NULL));
        }
    }

    /* MiscCfgInfo */
    {
        uint32_t mSel = 0U;
        uint8_t cfgName[16];

        printf("SCMI_MiscCfgInfo(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_MiscCfgInfo(SM_TEST_DEFAULT_CHN, &mSel,
            &cfgName[0]));
        printf("SCMI_MiscCfgInfo mSel: %u cfgName: %s\n",
            mSel, cfgName);

        /*Branch coverage */
        {
            /* Invalid Channel */
            NECHECK(SCMI_MiscCfgInfo(SM_NUM_TEST_CHN, &mSel, &cfgName[0]),
                SCMI_ERR_INVALID_PARAMETERS);

            /* mSel = NULL */
            CHECK(SCMI_MiscCfgInfo(SM_TEST_DEFAULT_CHN, NULL,
                &cfgName[0]));

            /* cfgName = NULL */
            CHECK(SCMI_MiscCfgInfo(SM_TEST_DEFAULT_CHN, &mSel,
                NULL));
        }
    }

    /* MiscSyslog */
    {
        uint32_t flags = 0x0U, logIndex = 0U;
        uint32_t numLogFlags = 0U;
        uint32_t sysLog[16];

        printf("SCMI_MiscSyslog(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_MiscSyslog(SM_TEST_DEFAULT_CHN, flags, logIndex,
            &numLogFlags, &sysLog[0]));
        printf("SCMI_MiscSyslog: sysLogFlags: %u sysLog: %s\n",
            numLogFlags, (uint8_t *)sysLog);

        /* Invalid channel */
        NECHECK(SCMI_MiscSyslog(SM_NUM_TEST_CHN, flags, logIndex,
            &numLogFlags, &sysLog[0]), SCMI_ERR_INVALID_PARAMETERS);

        /*numLogFlags = NULL */
        CHECK(SCMI_MiscSyslog(SM_TEST_DEFAULT_CHN, flags, logIndex,
            NULL, &sysLog[0]));

        /*sysLog = NULL */
        CHECK(SCMI_MiscSyslog(SM_TEST_DEFAULT_CHN, flags, logIndex,
            &numLogFlags, NULL));
    }

    /* RPC_00370 Test ROM data */
    {
        uint32_t numPassover = 0U;
        uint32_t passoverBuffer[SCMI_MISC_MAX_PASSOVER] = { 0 };
#ifdef INC_LIBC
        const rom_passover_t *passover
            = (const rom_passover_t*) passoverBuffer;
#endif

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

#ifdef SIMU
        /* Branch coverage */
        SM_TestModeSet(SM_TEST_MODE_DEV_LVL1);
        NECHECK(SCMI_MiscRomPassoverGet(SM_TEST_DEFAULT_CHN, &numPassover,
            passoverBuffer), SM_ERR_TEST);
        SM_TestModeSet(SM_TEST_MODE_OFF);
#endif
    }

    /* Control Set */
    {
        /* Control Set -- Invalid ctrlId */
        uint32_t val = 0x1234ABCDU;

        NECHECK(SCMI_MiscControlSet(SM_TEST_DEFAULT_CHN, numDevCtrl,
            1U, &val), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscControlSet(SM_SCMI_NUM_CHN, 0U,
            1U, &val), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Control Get */
    {
        /* Control Get -- Invalid ctrlId */
        NECHECK(SCMI_MiscControlGet(SM_TEST_DEFAULT_CHN, numDevCtrl, NULL,
            NULL), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscControlGet(SM_SCMI_NUM_CHN, 0U, NULL, NULL),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Control Action */
    {
        /* Control Action -- Invalid ctrlId */
        const uint32_t arg[3] = {5U, 1U, 2U};
        uint32_t numVal = 0U;
        uint32_t rtnVal[5] = {0U, 0U, 0U, 0U, 0U};

        NECHECK(SCMI_MiscControlAction(SM_TEST_DEFAULT_CHN, numDevCtrl, 23U,
            3, arg, &numVal, rtnVal), SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscControlAction(SM_SCMI_NUM_CHN, 0U, 23U,
            3, arg, NULL, NULL), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Control Notify */
    {
        /* Control Notify -- Invalid ctrlId */
        printf("SCMI_MiscControlNotify(%u, %u)\n", SM_TEST_DEFAULT_CHN,
            ctrlId);
        NECHECK(SCMI_MiscControlNotify(SM_TEST_DEFAULT_CHN, numDevCtrl, 1U),
            SCMI_ERR_NOT_FOUND);

        /* Branch -- Invalid Channel */
        NECHECK(SCMI_MiscControlNotify(SM_SCMI_NUM_CHN, 0U, 1U),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* RPC_00380 Test reset reason */
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

        /* Branch coverage */
        {
            /* Branch -- Invalid Channel */
            NECHECK(SCMI_MiscResetReason(SM_SCMI_NUM_CHN, flags, &bootFlags,
                &shutdownFlags, extInfo), SCMI_ERR_INVALID_PARAMETERS);

            /* Branch -- Null params */
            CHECK(SCMI_MiscResetReason(SM_TEST_DEFAULT_CHN, flags, NULL,
                NULL, NULL));

            /* Branch -- Get reset reason */
            flags = SCMI_MISC_REASON_FLAG_SYSTEM(1U);
            CHECK(SCMI_MiscResetReason(SM_TEST_DEFAULT_CHN, flags, &bootFlags,
                &shutdownFlags, extInfo));
        }
    }

    /* Invalid notification */
    {
        scmi_msg_id_t msgId =
        {
            .protocolId = 0xFFU,
            .messageId = 0xFFU
        };
        lmm_rpc_trigger_t trigger = { 0 };

        printf("RPC_SCMI_MiscDispatchNotification()\n");
        NCHECK(RPC_SCMI_MiscDispatchNotification(msgId, &trigger));
    }

    /* MiscBoardInfo */
    {
        uint32_t attributes = 0U;
        uint8_t brdName[SCMI_MISC_MAX_BRDNAME];

        printf("SCMI_MiscBoardInfo(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_MiscBoardInfo(SM_TEST_DEFAULT_CHN, &attributes, brdName));
        printf("  brdName=%s\n",  brdName);
        printf("  attributes=%u\n",  attributes);

        {
            /* Invalid channel */
            NECHECK(SCMI_MiscBoardInfo(SM_NUM_TEST_CHN, &attributes, brdName),
                SCMI_ERR_INVALID_PARAMETERS);

            /* attributes = NULL */
            CHECK(SCMI_MiscBoardInfo(SM_TEST_DEFAULT_CHN, NULL, brdName));

            /* brdName = NULL */
            CHECK(SCMI_MiscBoardInfo(SM_TEST_DEFAULT_CHN, &attributes, NULL));
        }
    }

    /* Loop over control test domains */
    status = TEST_ConfigFirstGet(TEST_CTRL, &agentId,
        &channel, &ctrlId, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint32_t sCtrlId = ctrlId;
        uint8_t perm = g_scmiAgentConfig[agentId].ctrlPerms[ctrlId];

        /* Convert to slit ctrlId */
        if (ctrlId >= numDevCtrl)
        {
            sCtrlId = (sCtrlId - numDevCtrl) | SCMI_MISC_CTRL_FLAG_BRD;
        }

        /* Test functions with GET perm required */
        TEST_ScmiMiscGet(perm >= SM_SCMI_PERM_GET, channel, sCtrlId);

        /* RPC_00170 Test functions with notify perms required */
        TEST_ScmiMiscNotify(perm >= SM_SCMI_PERM_NOTIFY,channel, sCtrlId);

        /* Test functions with EXCLUSIVE perm required */
        TEST_ScmiMiscExclusive(perm >= SM_SCMI_PERM_EXCLUSIVE, channel,
            sCtrlId, lmId);

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
#ifdef SIMU
        /* RPC_00360 Misc Control Notify & Event */
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
#endif
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
        /* RPC_00360 Control Set */
        printf("SCMI_MiscControlSet(%u, %u)\n", channel, ctrlId);
        CHECK(SCMI_MiscControlSet(channel, ctrlId,
            1U, &val));

        printf("SCMI_MiscControlGet(%u, %u)\n", channel, ctrlId);
        CHECK(SCMI_MiscControlGet(channel, ctrlId, &numVal, rtnVal));

#ifdef SIMU
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
#endif

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
            CHECK(LMM_SystemLmShutdown(sysManager, 0U, lmId, false,
                &g_swReason));
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

