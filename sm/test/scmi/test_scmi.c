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
/* Unit test for the SCMI protocol.                                         */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "scmi_internal.h"

/* Local defines */

/* Local types */

typedef struct
{
    uint32_t protNum;
    uint32_t protVer;
} scmi_prot_info_t;

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test SCMI protocol                                                       */
/*--------------------------------------------------------------------------*/
void TEST_Scmi(void)
{
    /* RPC_00010 RPC_00010 SCMI tests */
    printf("**** SCMI Protocol Tests ***\n\n");

    /* Test list protocols */
    {
        uint32_t numProtocols = 0U;
        uint32_t protocols[SCMI_BASE_MAX_PROTOCOLS] = { 0 };

        CHECK(SCMI_BaseDiscoverListProtocols(SM_TEST_DEFAULT_CHN, 0U,
            &numProtocols, protocols));

        printf("Test SCMI_ProtocolVersion() and "
            "SCMI_NegotiateProtocolVersion(%u) \n", SM_TEST_DEFAULT_CHN);

        /* Loop over protocols */
        for (uint32_t protIndex = 0U; protIndex < numProtocols; protIndex++)
        {
            uint32_t prot = (protocols[protIndex/4U]
                >> ((protIndex % 4U) * 8U)) & 0xFFU;

            /* Test protocol version and negotiate protocol attributes */
            {
                uint32_t ver = 0U;
                uint32_t index = 0U;

                static const scmi_prot_info_t s_scmiProtInfo[] =
                {
                    {SCMI_PROTOCOL_BASE,  SCMI_BASE_PROT_VER},
                    {SCMI_PROTOCOL_POWER,  SCMI_POWER_PROT_VER},
                    {SCMI_PROTOCOL_SYS,  SCMI_SYSTEM_PROT_VER},
                    {SCMI_PROTOCOL_PERF,  SCMI_PERF_PROT_VER },
                    {SCMI_PROTOCOL_CLOCK,  SCMI_CLOCK_PROT_VER},
                    {SCMI_PROTOCOL_SENSOR,  SCMI_SENSOR_PROT_VER},
                    {SCMI_PROTOCOL_RESET,  SCMI_RESET_PROT_VER},
                    {SCMI_PROTOCOL_VOLTAGE,  SCMI_VOLT_PROT_VER},
                    {SCMI_PROTOCOL_PINCTRL,  SCMI_PINCTRL_PROT_VER},
                    {SCMI_PROTOCOL_LMM,  SCMI_LMM_PROT_VER},
                    {SCMI_PROTOCOL_BBM,  SCMI_BBM_PROT_VER},
                    {SCMI_PROTOCOL_CPU,  SCMI_CPU_PROT_VER},
                    {SCMI_PROTOCOL_FUSA,  SCMI_FUSA_PROT_VER},
                    {SCMI_PROTOCOL_MISC,  SCMI_MISC_PROT_VER}
                };

                /* Find protocol */
                for (index = 0U; index < (sizeof(s_scmiProtInfo) /
                    sizeof(scmi_prot_info_t)); index++)
                {
                    if (s_scmiProtInfo[index].protNum == prot)
                    {
                        break;
                    }
                }

                /* Check protocol found */
                BCHECK(index < (sizeof(s_scmiProtInfo)
                    / sizeof(scmi_prot_info_t)));

                /* Check protocol version */
                CHECK(SCMI_ProtocolVersion(SM_TEST_DEFAULT_CHN, prot, &ver));
                printf("protocol=0x%x  ver=0x%08X\n", prot, ver);

                BCHECK(ver == s_scmiProtInfo[index].protVer);

                /* Check valid major and minor version */
                CHECK(SCMI_NegotiateProtocolVersion(SM_TEST_DEFAULT_CHN,
                    prot, ver));

                /* Check invalid major version */
                NECHECK(SCMI_NegotiateProtocolVersion(SM_TEST_DEFAULT_CHN,
                    prot, ver + 0x10000U), SM_ERR_NOT_SUPPORTED);

                /* Check invalid minor version */
                NECHECK(SCMI_NegotiateProtocolVersion(SM_TEST_DEFAULT_CHN,
                    prot, ver + 0x1U), SM_ERR_NOT_SUPPORTED);
            }
        }
        printf("\n");

        printf("**** SCMI Test Invalid Message Lengths ***\n\n");
        /* Loop over protocols */
        for (uint32_t protIndex = 0U; protIndex < numProtocols; protIndex++)
        {
            uint32_t prot = (protocols[protIndex/4U]
                >> ((protIndex % 4U) * 8U)) & 0xFFU;
            uint32_t header = 0U;

            /* Test with bad message ID */
            NECHECK(SCMI_ProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
                prot, 64U, NULL), SCMI_ERR_NOT_FOUND);

            /* Test with NULL */
            CHECK(SCMI_ProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
                prot, 0U, NULL));

            /* INNER LOOP: messageIds */
            for (uint32_t messIndex = 0U; messIndex < 32U; messIndex++)
            {
                int32_t status = 0;
                uint32_t attributes = 0U;

                /* Ensure valid message per Protocol */
                status = SCMI_ProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
                    prot, messIndex, &attributes);

                /* Skip invalid messages */
                if (status != SCMI_ERR_SUCCESS)
                {
                    continue;
                }
                /* Valid messageId */
                else
                {
                    /* Send expecting to receive an error */
                    CHECK(SCMI_A2pTx(SM_TEST_DEFAULT_CHN, prot,
                        messIndex, 2U, &header));

                    /* Check to ensure protocol error returned */
                    NECHECK(SCMI_A2pRx(SM_TEST_DEFAULT_CHN, 2U,
                        header), SCMI_ERR_PROTOCOL_ERROR);
                }
            }

            /* Invalid messageId */
            CHECK(SCMI_A2pTx(SM_TEST_DEFAULT_CHN, prot,
                32U, 2U, &header));

            /* Check to ensure protocol error returned */
            NECHECK(SCMI_A2pRx(SM_TEST_DEFAULT_CHN, 2U,
                header), SCMI_ERR_PROTOCOL_ERROR);

        }
    }

    {
        uint32_t header = 0U;
        uint32_t ver = 0U;

        /* Test invalid channel */
        printf("**** SCMI Test Invalid Channel ***\n\n");

        /* Invalid channel */
        NECHECK(SCMI_A2pTx(SM_SCMI_NUM_CHN, 0U, 0U, 0U,
            &header), SCMI_ERR_INVALID_PARAMETERS);

        /* Invalid channel */
        NECHECK(SCMI_A2pRx(SM_SCMI_NUM_CHN, 0U, 0U),
            SCMI_ERR_INVALID_PARAMETERS);

        /* Invalid channel */
        NECHECK(SCMI_BaseProtocolVersion(SM_SCMI_NUM_CHN, &ver),
            SCMI_ERR_INVALID_PARAMETERS);

        /* Invalid channel */
        NECHECK(SCMI_BaseProtocolMessageAttributes(SM_SCMI_NUM_CHN,
            SCMI_MSG_BASE_DISCOVER_VENDOR, NULL),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    printf("\n");
}

