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
/* Unit test for the SCMI protocol.                                         */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "scmi_internal.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test SCMI protocol                                                       */
/*--------------------------------------------------------------------------*/
void TEST_Scmi(void)
{
    /* SCMI tests */
    printf("**** SCMI Protocol Tests ***\n\n");

    /* Test list protocols */
    {
        uint32_t numProtocols = 0U;
        uint32_t protocols[SCMI_BASE_MAX_PROTOCOLS] = {};

        printf("**** SCMI Test Invalid Message Lengths ***\n\n");
        CHECK(SCMI_BaseDiscoverListProtocols(SM_TEST_DEFAULT_CHN, 0U,
            &numProtocols, protocols));

        /* Loop over protocols */
        for (uint32_t protIndex = 0U; protIndex < numProtocols; protIndex++)
        {
            uint32_t prot = (protocols[protIndex/4U]
                >> ((protIndex % 4U) * 8U)) & 0xFFU;
            uint32_t header = 0U;

            /* Test with bad message ID */
            NECHECK(SCMI_ProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
                prot, 32U, NULL), SCMI_ERR_NOT_FOUND);

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

