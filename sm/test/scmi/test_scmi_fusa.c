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

        /* Protocol Attributes*/
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
    }
    else
    {
        printf("Skipped as FuSa not enabled!\n");
    }

    printf("\n");
}

