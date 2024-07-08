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
/* Unit test for the SCMI cpu protocol.                                     */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiCpuNone(uint32_t channel, uint32_t domainId);
static void TEST_ScmiCpuExclusive(bool pass, uint32_t channel,
    uint32_t domainId, uint32_t lmId);

/*--------------------------------------------------------------------------*/
/* Test SCMI cpu protocol                                                   */
/*--------------------------------------------------------------------------*/
void TEST_ScmiCpu(void)
{
    int32_t status = 0;
    uint32_t numCpu = 0U;
    uint32_t agentId, channel, domainId, lmId = 0U;

    /* RPC_00290 RPC_00160  CPU tests */
    printf("**** CPU Protocol Tests ***\n\n");

    /* Test Protocol Version */
    {
        uint32_t ver = 0U;

        printf("SCMI_CpuProtocolVersion(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_CpuProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_CPU_PROT_VER);
    }

    /* Test Protocol Attributes */
    {
        uint32_t attributes = 0U;

        printf("SCMI_CpuProtocolAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_CpuProtocolAttributes(SM_TEST_DEFAULT_CHN,
            &attributes));
        numCpu = SCMI_CPU_PROTO_ATTR_NUM_CPUS(attributes);
        printf("  numCpu=%u\n", numCpu);
    }

    /* Test Message Attributes */
    {
        uint32_t attributes = 0U;

        /* Should WORK : Valid Message ID */
        printf("SCMI_CpuProtocolMessageAttributes(%u, STATE_SET)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_CpuProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_CPU_ATTRIBUTES, &attributes));
        printf("  attributes=%u\n", attributes);

        /* Spec states should always be 0 */
        BCHECK(attributes == 0U);
    }

    /* Use numCpu to overwrite the bounds */

    /* CpuAttributes -- invalid cpuId and invalid channel */
    {
        uint32_t attributes = 0U;
        uint8_t name[SCMI_CPU_MAX_NAME];

        printf("SCMI_CpuAttributes(%u, %u)\n", SM_TEST_DEFAULT_CHN,
            numCpu);
        name[0] = 0U;
        NECHECK(SCMI_CpuAttributes(SM_TEST_DEFAULT_CHN, numCpu,
            &attributes, name), SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_CpuAttributes(SM_SCMI_NUM_CHN, numCpu,
            &attributes, name), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* CpuStart -- invalid cpuId and invalid channel */
    {
        printf("SCMI_CpuStart(%u, %u)\n", SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuStart(SM_TEST_DEFAULT_CHN, numCpu),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_CpuStart(SM_SCMI_NUM_CHN, numCpu),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* CpuStop -- invalid cpuId and invalid channel */
    {
        printf("SCMI_CpuStop(%u, %u)\n", SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuStop(SM_TEST_DEFAULT_CHN, numCpu),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_CpuStop(SM_SCMI_NUM_CHN, numCpu),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* CpuResetVecorSet -- invalid cpuId and invalid channel */
    {
        uint32_t flags = SCMI_CPU_VEC_FLAGS_RESUME(1UL);
        uint32_t resetVectorLow = 1U;
        uint32_t resetVectorHigh = 1U;

        printf("SCMI_CpuResetVectorSet(%u, %u)\n",
            SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuResetVectorSet(SM_TEST_DEFAULT_CHN, numCpu,
            flags, resetVectorLow, resetVectorHigh),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_CpuResetVectorSet(SM_SCMI_NUM_CHN, numCpu,
            flags, resetVectorLow, resetVectorHigh),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* CpuInfoGet -- invalid cpuId and invalid channel */
    {
        uint32_t runmode = 0U, sleepmode = 0U;
        uint32_t low_vector = 0U, high_vector = 0U;

        printf("SCMI_CpuInfoGet(%u, %u)\n", SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuInfoGet(SM_TEST_DEFAULT_CHN, numCpu, &runmode,
            &sleepmode, &low_vector, &high_vector),
            SCMI_ERR_NOT_FOUND);

        printf("CPUInfoGet: runmode: %u sleepmode: %u vector l:h: %u: %u\n",
            runmode, sleepmode, low_vector, high_vector);
        NECHECK(SCMI_CpuInfoGet(SM_SCMI_NUM_CHN, numCpu, &runmode,
            &sleepmode, &low_vector, &high_vector),
            SM_ERR_INVALID_PARAMETERS);
    }

    /* CpuSleepModeSet -- invalid cpuId and invalid channel */
    {
        uint32_t flags = 0U;
        printf("SCMI_CpuSleepModeSet(%u, %u)\n",
            SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuSleepModeSet(SM_TEST_DEFAULT_CHN, numCpu, flags,
            SCMI_CPU_SLEEP_SUSPEND), SM_ERR_NOT_FOUND);

        printf("SCMI_CpuSleepModeSet(%u, %u)\n",
            SM_SCMI_NUM_CHN, numCpu);
        NECHECK(SCMI_CpuSleepModeSet(SM_SCMI_NUM_CHN, numCpu, flags,
            SCMI_CPU_SLEEP_SUSPEND), SM_ERR_INVALID_PARAMETERS);
    }

    /* CPUIrqWakeSet -- invalid cpuId and invalid channel */
    {
        uint32_t maskidx = 0U, mask = 0U;

        printf("SCMI_CpuIrqWakeSet:(%u, %u)\n",
            SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuIrqWakeSet(SM_TEST_DEFAULT_CHN, numCpu, maskidx,
            1U, &mask), SM_ERR_NOT_FOUND);

        printf("SCMI_CpuIrqWakeSet(%u, %u)\n",
            SM_SCMI_NUM_CHN, numCpu);
        NECHECK(SCMI_CpuIrqWakeSet(SM_SCMI_NUM_CHN, numCpu, maskidx,
            1U, &mask), SM_ERR_INVALID_PARAMETERS);
    }

    /* CPUNonIrqWakeSet -- invalid cpuId and invalid channel */
    {
        uint32_t maskidx = 0U, mask = 0U;

        printf("SCMI_CpuNonIrqWakeSet: (%u, %u)\n",
            SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuNonIrqWakeSet(SM_TEST_DEFAULT_CHN, numCpu, maskidx,
            1U, &mask), SM_ERR_NOT_FOUND);

        printf("SCMI_CpuNonIrqWakeSet(%u, %u) Invalid channel\n",
            SM_SCMI_NUM_CHN, numCpu);
        NECHECK(SCMI_CpuNonIrqWakeSet(SM_SCMI_NUM_CHN, numCpu, maskidx,
            1U, &mask), SM_ERR_INVALID_PARAMETERS);

    }

    /* CpuPdLpmConfigsSet -- Invalid cpuId and Invalid channel */
    {
        uint32_t numConfigs = 1U;
        scmi_pd_lpm_config_t lpm_config = {0U};
        lpm_config.domainId = 0U;
        lpm_config.lpmSetting = 0U;
        lpm_config.retMask = 0x0U;

        printf("SCMI_CpuPdLpmConfigSet:(%u, %u)\n",
            SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuPdLpmConfigSet(SM_TEST_DEFAULT_CHN, numCpu,
            numConfigs, &lpm_config), SM_ERR_NOT_FOUND);

        printf("SCMI_CpuPdLpmConfigSet:(%u, %u)\n",
            SM_SCMI_NUM_CHN, numCpu);
        NECHECK(SCMI_CpuPdLpmConfigSet(SM_SCMI_NUM_CHN, numCpu,numConfigs,
            &lpm_config), SM_ERR_INVALID_PARAMETERS);

    }

    /* CpuPerLpmConfigSet -- Invalid cpuId and Invalid channel */
    {
        uint32_t numConfigs = 1U;
        scmi_per_lpm_config_t per_lpm_config = {0U};
        per_lpm_config.perId= 0U;
        per_lpm_config.lpmSetting = 0U;

#ifdef SIMU
        per_lpm_config.perId= 1U;
        printf("SCMI_CpuPerLpmConfigSet (%u, %u) Invalid perID\n",
            SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuPerLpmConfigSet(SM_TEST_DEFAULT_CHN, 1U, numConfigs,
            &per_lpm_config), SM_ERR_NOT_FOUND);
#endif

        printf("SCMI_CpuPerLpmConfigSet:(%u, %u)\n",
            SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuPerLpmConfigSet(SM_TEST_DEFAULT_CHN, numCpu,
            numConfigs, &per_lpm_config), SM_ERR_NOT_FOUND);

        printf("SCMI_CpuPerLpmConfigSet:(%u, %u)\n",
            SM_SCMI_NUM_CHN, numCpu);
        NECHECK(SCMI_CpuPerLpmConfigSet(SM_SCMI_NUM_CHN, numCpu,
            numConfigs, &per_lpm_config), SM_ERR_INVALID_PARAMETERS);
    }

    /* Loop over cpu test domains */
    status = TEST_ConfigFirstGet(TEST_CPU, &agentId,
        &channel, &domainId, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].cpuPerms[domainId];

        /* Test functions with no perm required */
        TEST_ScmiCpuNone(channel, domainId);

        /* Test functions with SET perm required */
        TEST_ScmiCpuExclusive(perm >= SM_SCMI_PERM_EXCLUSIVE,
            channel, domainId, lmId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_CPU, &agentId,
            &channel, &domainId, &lmId);
    }

    printf("\n");
}

/*--------------------------------------------------------------------------*/
/* Test SCMI cpu functions with no access                                   */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiCpuNone(uint32_t channel, uint32_t domainId)
{
    uint32_t attributes = 0U;
    uint8_t name[SCMI_CPU_MAX_NAME] = { 0 };

    printf("SCMI_CpuAttributes(%u, %u)\n", channel, domainId);
    name[0] = 0U;
    CHECK(SCMI_CpuAttributes(channel, domainId,
        &attributes, name));

    /* Branch: attributes = NULL */
    CHECK(SCMI_CpuAttributes(channel, domainId,
        NULL, name));

    /* Branch: name = NULL */
    CHECK(SCMI_CpuAttributes(channel, domainId,
        &attributes, NULL));

    /* NegotiateProtocolVersion -- valid cpuId and valid channel */
    {
        uint32_t version = 1234U;
        printf("SCMI_CpuNegotiateProtocolVersion(%u, %u)\n",
            channel, domainId);
        NECHECK(SCMI_CpuNegotiateProtocolVersion(channel, version),
            SCMI_ERR_NOT_SUPPORTED);
    }

    /* CpuInfoGet -- valid cpuId and valid channel */
    {
        uint32_t runmode = 0U, sleepmode = 0U;
        uint32_t low_vector = 0U, high_vector = 0U;

        printf("SCMI_CpuInfoGet(%u, %u)\n", channel, domainId);
        CHECK(SCMI_CpuInfoGet(channel, domainId, &runmode,
            &sleepmode, &low_vector, &high_vector));

        /*Branch: RunMode =  NULL */
        CHECK(SCMI_CpuInfoGet(channel, domainId, NULL,
            &sleepmode, &low_vector, &high_vector));

        /*Branch: sleepMode =  NULL */
        CHECK(SCMI_CpuInfoGet(channel, domainId, &runmode,
            NULL, &low_vector, &high_vector));

        /*Branch: low_vector =  NULL */
        CHECK(SCMI_CpuInfoGet(channel, domainId, &runmode,
            &sleepmode, NULL, &high_vector));

        /*Branch: high_vector =  NULL */
        CHECK(SCMI_CpuInfoGet(channel, domainId, &runmode,
            &sleepmode, &low_vector, NULL));
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI cpu functions with exclusive access                            */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiCpuExclusive(bool pass, uint32_t channel,
    uint32_t domainId, uint32_t lmId)
{
    /* Adequate Access Permissions */
    if (pass)
    {
        /* CPU Start */
        printf("SCMI_CpuStart(%u, %u)\n", channel, domainId);
        CHECK(SCMI_CpuStart(channel, domainId));

        /* CPU Stop */
        printf("SCMI_CpuStop(%u, %u)\n", channel, domainId);
        CHECK(SCMI_CpuStop(channel, domainId));

        /* RPC_00300 CPU Reset Vector Set */
        {
            uint32_t flags = 0U;
            uint32_t resetVectorLow = 0U;
            uint32_t resetVectorHigh = 0U;

            /* Case 1: Resume Flag */
            flags = SCMI_CPU_VEC_FLAGS_RESUME(1UL);
            printf("SCMI_CpuResetVectorSet(%u, %u)\n", channel, domainId);
            CHECK(SCMI_CpuResetVectorSet(channel, domainId, flags,
                resetVectorLow, resetVectorHigh));

            /* Case 2: Boot Flag */
            flags = SCMI_CPU_VEC_FLAGS_BOOT(1UL);
            printf("SCMI_CpuResetVectorSet(%u, %u)\n", channel, domainId);
            CHECK(SCMI_CpuResetVectorSet(channel, domainId, flags,
                resetVectorLow, resetVectorHigh));

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

        /* CPU Sleep mode set */
        {
            uint32_t flags = 0U;

            /* Case 1: Sleep Mode: Run */
            printf("SCMI_CpuSleepModeSet(%u, %u) sleep_mode: Run\n",
                channel, domainId);
            CHECK(SCMI_CpuSleepModeSet(channel, domainId, flags,
                SCMI_CPU_SLEEP_RUN));

            /* Case 2: Sleep Mode: Wait */
            printf("SCMI_CpuSleepModeSet(%u, %u) sleep_mode: Wait\n",
                channel, domainId);
            CHECK(SCMI_CpuSleepModeSet(channel, domainId, flags,
                SCMI_CPU_SLEEP_WAIT));

            /* Case 3: Sleep Mode: Stop */
            printf("SCMI_CpuSleepModeSet(%u, %u) sleep_mode: Stop\n",
                channel, domainId);
            CHECK(SCMI_CpuSleepModeSet(channel, domainId, flags,
                SCMI_CPU_SLEEP_STOP));

            /* Case 4: Sleep Mode: Suspend*/
            printf("SCMI_CpuSleepModeSet(%u, %u) sleep_mode: Suspend\n",
                channel, domainId);
            CHECK(SCMI_CpuSleepModeSet(channel, domainId, flags,
                SCMI_CPU_SLEEP_SUSPEND));

            /* Case 5: Sleep Mode: Invalid*/
            printf("SCMI_CpuSleepModeSet(%u, %u) Invalid sleep mode\n",
                channel, domainId);
            NECHECK(SCMI_CpuSleepModeSet(channel, domainId, flags,
                SCMI_CPU_SLEEP_SUSPEND + 1U), SCMI_ERR_INVALID_PARAMETERS);
        }

        /* CpuIrqWakeSet */
        {
            uint32_t maskidx = 0U, mask = 0U;
            printf("SCMI_CpuIrqWakeSet(%u, %u)\n",
                channel, domainId);
            CHECK(SCMI_CpuIrqWakeSet(channel, domainId, maskidx,
                1U, &mask));
        }

        /* CpuNonIrqWakeSet */
        {
            uint32_t maskidx = 0U, mask = 0U;
            printf("SCMI_CpuNonIrqWakeSet(%u, %u)\n",
                channel, domainId);
            CHECK(SCMI_CpuNonIrqWakeSet(channel, domainId, maskidx,
                1U, &mask));
        }

        /* CpuPdLpmConfigsSet */
        {
            uint32_t numConfig = 1U;
            scmi_pd_lpm_config_t lpm_config = {0U};
            lpm_config.domainId = domainId;
            lpm_config.lpmSetting = SCMI_CPU_LPM_SETTING_ON_NEVER;
            lpm_config.retMask = 0x0U;

            printf("SCMI_CpuPdLpmConfigSet (%u, %u)\n",
                channel, domainId);
            CHECK(SCMI_CpuPdLpmConfigSet(channel, domainId,
                numConfig, &lpm_config));
        }

        /* CpuPerLpmConfigSet */
        {
            uint32_t numConfig = 1U;
            scmi_per_lpm_config_t per_lpm_config = {0U};
            per_lpm_config.perId= 0U;
            per_lpm_config.lpmSetting = 0U;
            printf("SCMI_CpuPerLpmConfigSet (%u, %u)\n",
                channel, domainId);
            CHECK(SCMI_CpuPerLpmConfigSet(channel, domainId,
                numConfig, &per_lpm_config));
        }

    }
    /* ACCESS DENIED */
    else
    {
        printf("SCMI_CpuStart(%u, %u)\n", channel, domainId);
        NECHECK(SCMI_CpuStart(channel, domainId), SCMI_ERR_DENIED);

        /* CPU Stop */
        printf("SCMI_CpuStop(%u, %u)\n", channel, domainId);
        NECHECK(SCMI_CpuStop(channel, domainId), SCMI_ERR_DENIED);

        /* CPU Reset Vector Set */
        uint32_t resetVectorLow = 0U;
        uint32_t resetVectorHigh = 0U;
        uint32_t maskidx = 0U, mask = 0U;
        uint32_t flags = SCMI_CPU_VEC_FLAGS_RESUME(1UL);

        printf("SCMI_CpuResetVectorSet(%u, %u)\n", channel, domainId);
        NECHECK(SCMI_CpuResetVectorSet(channel, domainId, flags,
            resetVectorLow, resetVectorHigh), SCMI_ERR_DENIED);

        /* Sleep Mode Set */
        flags = 0U;
        printf("SCMI_CpuSleepModeSet(%u, %u) Permission error\n",
            channel, domainId);
        NECHECK(SCMI_CpuSleepModeSet(channel, domainId, flags,
            SCMI_CPU_SLEEP_SUSPEND), SM_ERR_DENIED);

        printf("SCMI_CpuIrqWakeSet(%u, %u)\n",
            channel, domainId);
        NECHECK(SCMI_CpuIrqWakeSet(channel, domainId, maskidx,
            1U, &mask), SCMI_ERR_DENIED);

        printf("SCMI_CpuNonIrqWakeSet(%u, %u)\n",
            channel, domainId);
        NECHECK(SCMI_CpuNonIrqWakeSet(channel, domainId, maskidx,
            1U, &mask), SCMI_ERR_DENIED);

        /* CpuPdLpmConfigsSet */
        {
            uint32_t numConfig = 1U;
            scmi_pd_lpm_config_t lpm_config = {0U};
            lpm_config.domainId = domainId;
            lpm_config.lpmSetting = SCMI_CPU_LPM_SETTING_ON_NEVER;
            lpm_config.retMask = 0x0U;

            printf("SCMI_CpuPdLpmConfigSet (%u, %u)\n",
                channel, domainId);
            CHECK(SCMI_CpuPdLpmConfigSet(channel, domainId,
                numConfig, &lpm_config));
        }

        /* CpuPerLpmConfigSet */
        {
            uint32_t numConfig = 1U;
            scmi_per_lpm_config_t per_lpm_config = {0U};
            per_lpm_config.perId= 0U;
            per_lpm_config.lpmSetting = 0U;

            printf("SCMI_CpuPerLpmConfigSet (%u, %u)\n",
                channel, domainId);
            NECHECK(SCMI_CpuPerLpmConfigSet(channel, domainId,
                numConfig, &per_lpm_config), SCMI_ERR_DENIED);
        }
    }
}

