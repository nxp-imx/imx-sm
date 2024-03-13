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

#include "test_scmi.h"
#include "rpc_scmi.h"

void TEST_ScmiFusa(void)
{
    /* RPC_00410 FuSa tests */
    printf("**** FuSa Protocol Test ****\n\n");

    /* Check if FuSa supported */
    if (SCMI_FusaProtocolVersion(SM_TEST_DEFAULT_CHN, NULL) !=
        SCMI_ERR_NOT_SUPPORTED)
    {
        /* Protocol Version */
        {
            uint32_t ver = 0U;

            printf("SCMI_FusaProtocolAttributes(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
            printf("  ver=0x%08X\n", ver);

            BCHECK(ver == SCMI_FUSA_PROT_VER);
        }

        /* Protocol Attributes */
        {
            uint32_t attributes1 = 0U;
            uint32_t attributes2 = 0U;

            printf("SCMI_FusaProtocolAttributes(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaProtocolAttributes(SM_TEST_DEFAULT_CHN,
                &attributes1, &attributes2));
            printf("  numFault=%u\n",
                SCMI_FUSA_PROTO_ATTR1_NUM_FAULT(attributes1));
            printf("  numSeenvId=%u\n",
                SCMI_FUSA_PROTO_ATTR1_NUM_SEENV_ID(attributes1));
            printf("  numSeenvLm=%u\n",
                SCMI_FUSA_PROTO_ATTR1_NUM_SEENV_LM(attributes1));
        }

        /* Protocol Message Attributes */
        {
            uint32_t attributes = 0U;

            printf("SCMI_FusaProtocolMessageAttributes(%u)\n",
                SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
                2U, &attributes));

            /* Check if attributes is 0 */
            BCHECK(attributes == 0U);

            /* Pass in invalid Message ID,
                will come out to SCMI_ERR_NOT_FOUND */
            printf("SCMI_FusaProtocolMessageAttributes(%u, %u)\n",
                SM_TEST_DEFAULT_CHN, 30U);

            /* Ensure proper error code is returned */
            NECHECK(SCMI_FusaProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
                30U, NULL), SCMI_ERR_NOT_FOUND);
        }

        /* FusaFeenv State Notify */
        {
            printf("SCMI_FusaFeenvStateNotify(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaFeenvStateNotify(SM_TEST_DEFAULT_CHN, 1U /*notifyenable*/));
        }

        /* FusaFeenv State Get */
        {
            uint32_t feenvState = 0U, mselMode = 0U;

            printf("SCMI_FusaFeenvStateGet(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaFeenvStateGet(SM_TEST_DEFAULT_CHN, &feenvState,
                &mselMode));
            printf("SCMI_FusaFeenvStateGet: feenvState=%u mselMode=%u\n",feenvState,
                mselMode);
        }

#ifdef SIMU
        /* Fusaseenv State Get */
        {
            uint32_t seenvId = 0U, lmId = 0U, seenvState = 0U;

            printf("SCMI_FusaSeenvStateGet(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaSeenvStateGet(SM_TEST_DEFAULT_CHN, &seenvId,
                &lmId, &seenvState));
            printf("SCMI_FusaSeenvStateGet: seenvId=%u lmId=%u seenvState=%u\n",
                seenvId, lmId, seenvState);
        }

        /* Fusaseenv State Set */
        {
            uint32_t pingCookie = 0U, seenvState = 0U;

            printf("SCMI_FusaSeenvStateSet(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaSeenvStateSet(SM_TEST_DEFAULT_CHN, seenvState, pingCookie));
        }

        /* Fusaseenv State Set: Invalid seevState */
        {
            uint32_t pingCookie = 0U, seenvState = SM_LM_NUM_SEENV;

            printf("SCMI_FusaSeenvStateSet(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaSeenvStateSet(SM_TEST_DEFAULT_CHN, seenvState, pingCookie));
        }

        /* Fusa fault Get */
        {
            uint32_t faultId = 3U, flag = 0U;

            printf("SCMI_FusaFaultGet(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaFaultGet(SM_TEST_DEFAULT_CHN, faultId,
                &flag));
            printf("SCMI_FusaFaultGet: faultId=%u flag: %x\n",
                faultId, flag);
        }

        /* Fusa fault Group Notify */
        {
            uint32_t faultIdFirst = 0U, faultmask = 0xffU, NotifyEnable = 0xFFU;
            uint32_t FaultIdFirstGet = 0U, NotifyEnabled = 0U;

            printf("SCMI_FusaFaultGroupNotify(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaFaultGroupNotify(SM_TEST_DEFAULT_CHN, faultIdFirst,
                faultmask, NotifyEnable, &FaultIdFirstGet, &NotifyEnabled));
            printf("SCMI_FusaFaultGroupNotify: FaultFirstGet=%u NotifyEnabled: %x\n",
                FaultIdFirstGet, NotifyEnabled);
        }

        /* Fusa scheck event trigger */
        {
            printf("SCMI_FusaScheckEvntrig(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaScheckEvntrig(SM_TEST_DEFAULT_CHN));
        }

        /* Fusa scheck test exec */
        {
            uint32_t targetTestId = 0U;
            printf("SCMI_FusaScheckEvntrig(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaScheckTestExec(SM_TEST_DEFAULT_CHN, targetTestId));
        }

        /* Fusa negotiate protocol version */
        {
            uint32_t version = 0x10000U;
            printf("SCMI_FusaNegotiateProtocolVersion(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaNegotiateProtocolVersion(SM_TEST_DEFAULT_CHN, version));
        }

        /* send notification */
        {
            for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
            {
                lmm_rpc_trigger_t trigger =
                {
                    .event = LMM_TRIGGER_FUSA_FEENV,
                    .parm[0] = 0U,
                    .parm[1] = 0U,
                    .parm[2] = 1U
                };

                /* Send notification */
                (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
            }

            for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
            {
                lmm_rpc_trigger_t trigger =
                {
                    .event = LMM_TRIGGER_FUSA_SEENV,
                    .parm[0] = 0U,
                    .parm[1] = 0U,
                    .parm[2] = 1U
                };
                /* Send notification */
                (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
            }
        }

        /*Fusa Feenv State Event*/
        {
            uint32_t feenvState = 0U, mSelMode = 0U;
            printf("SCMI_FusaFeenvStateEvent(%u)\n", SCMI_PRIORITY_Q);
            CHECK(SCMI_FusaFeenvStateEvent(2, &feenvState, &mSelMode));
            printf("SCMI_FusaFeenvStateEvent: FeenvState: %u, mSelMode: %u\n", feenvState,
                mSelMode);
        }

        /*Fusa Seenv State Request Event*/
        {
            uint32_t pingcookie = 0U;
            printf("SCMI_FusaSeenvStateReqEvent(%u)\n", SCMI_PRIORITY_Q);
            CHECK(SCMI_FusaSeenvStateReqEvent(2, &pingcookie));
            printf(":SCMI_FusaSeenvStateReqEvent pingcookie: %u\n", pingcookie);
        }

        /*Fusa fault Set*/
        {
            uint32_t faultId = 3U, flag = 0xffU;

            printf("SCMI_FusaFaultSet(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaFaultSet(SM_TEST_DEFAULT_CHN, faultId,
                flag));
        }
        /*Fusa fault Set:  clear the fault*/
        {
            uint32_t faultId = 3U, flag = 0x0U;

            printf("SCMI_FusaFaultSet(%u)\n", SM_TEST_DEFAULT_CHN);
            CHECK(SCMI_FusaFaultSet(SM_TEST_DEFAULT_CHN, faultId,
                flag));
        }
        /*Fusa fault Event*/
        {
            uint32_t faultId = 0U, flag = 0U;

            printf("SCMI_FusaFaultEvent(SCMI_PRIORITY_Q)\n");
            CHECK(SCMI_FusaFaultEvent(2 /*SCMI_PRIORITY_Q*/, &faultId,
                &flag));
            printf("SCMI_FusaFaultEvent: faultId: %u flag: %x\n", faultId, flag);
        }
#endif
    }
    else
    {
        printf("Skipped as FuSa not enabled!\n");
    }

    printf("\n");
}

