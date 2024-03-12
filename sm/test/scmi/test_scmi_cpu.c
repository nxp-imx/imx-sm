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
        CHECK(SCMI_CpuProtocolAttributes(SM_TEST_DEFAULT_CHN, &attributes));
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

    /* CpuAttributes -- invalid cpuId and invalid channel*/
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

    /* CpuStart -- invalid cpuId and invalid channel*/
    {
        printf("SCMI_CpuStart(%u, %u)\n", SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuStart(SM_TEST_DEFAULT_CHN, numCpu),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_CpuStart(SM_SCMI_NUM_CHN, numCpu),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* CpuStop -- invalid cpuId and invalid channel*/
    {
        printf("SCMI_CpuStop(%u, %u)\n", SM_TEST_DEFAULT_CHN, numCpu);
        NECHECK(SCMI_CpuStop(SM_TEST_DEFAULT_CHN, numCpu),
            SCMI_ERR_NOT_FOUND);

        NECHECK(SCMI_CpuStop(SM_SCMI_NUM_CHN, numCpu),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* CpuResetVecorSet -- invalid cpuId and invalid channel*/
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
                CHECK(LMM_SystemLmShutdown(sysManager, 0U, lmId, false, &g_swReason));
            }
#endif

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
        uint32_t flags = SCMI_CPU_VEC_FLAGS_RESUME(1UL);

        printf("SCMI_CpuResetVectorSet(%u, %u)\n", channel, domainId);
        NECHECK(SCMI_CpuResetVectorSet(channel, domainId, flags,
            resetVectorLow, resetVectorHigh), SCMI_ERR_DENIED);
    }
}

