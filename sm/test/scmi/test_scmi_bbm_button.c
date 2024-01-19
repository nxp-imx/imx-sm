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
/* Unit test for the SCMI BBM button protocol.                              */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "rpc_scmi_bbm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void TEST_ScmiButtonNone(uint32_t channel, uint32_t resource);
static void TEST_ScmiButtonNotify(bool pass, uint32_t channel,
    uint32_t resource);

/*--------------------------------------------------------------------------*/
/* Test SCMI BBM button protocol                                            */
/*--------------------------------------------------------------------------*/
void TEST_ScmiBbmButton(void)
{
    int32_t status;
    uint32_t agentId, channel, resource, lmId;

    /* BBM tests */
    printf("**** Battery-backed Module Button Protocol Tests ***\n\n");

    /* Test protocol version */
    {
        uint32_t ver = 0U;

        printf("SCMI_BbmProtocolVersion(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_BbmProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_BBM_PROT_VER);
    }

    /* Invalid channel for BbmButonGet */
    {
        uint32_t buttonState = 0;

        NECHECK(SCMI_BbmButtonGet(SM_SCMI_NUM_CHN,
            &buttonState), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Invalid channel for BbmButtonNotify */
    {
        uint32_t flags = 0;

        NECHECK(SCMI_BbmButtonNotify(SM_SCMI_NUM_CHN,
            flags), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Invalid channel */
    {
        uint32_t flags = 0;

        NECHECK(SCMI_BbmButtonEvent(SM_SCMI_NUM_CHN,
            &flags), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Invalid notification */
    {
        scmi_msg_id_t msgId =
        {
            .protocolId = 0xFFU,
            .messageId = 0xFFU
        };
        lmm_rpc_trigger_t trigger = { 0 };

        printf("RPC_SCMI_BbmDispatchNotification()\n");
        RPC_SCMI_BbmDispatchNotification(msgId, trigger);
    }

    /* Loop over BBM test resources */
    status = TEST_ConfigFirstGet(TEST_BUTTON, &agentId,
        &channel, &resource, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].buttonPerms[resource];

        /* Test functions with no perm required */
        TEST_ScmiButtonNone(channel, resource);

        /* Test functions with NOTIFY perm required */
        TEST_ScmiButtonNotify(perm >= SM_SCMI_PERM_SET, channel, resource);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_BUTTON, &agentId,
            &channel, &resource, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI BBM functions with no access                                   */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiButtonNone(uint32_t channel, uint32_t resource)
{
    uint32_t btn = 1U;

    printf("SCMI_BbmButtonGet(%u)\n", channel);
    while (btn == 1U)
    {
        CHECK(SCMI_BbmButtonGet(channel, &btn));
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI BBM functions with NOTIFY access                               */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiButtonNotify(bool pass, uint32_t channel,
    uint32_t resource)
{
#if defined(SIMU) || !defined(TEST_ALL)
    /* Adequate Set Permissions */
    if (pass)
    {
        CHECK(SCMI_BbmButtonGet(channel, NULL));

        /* Test ON/OFF button is released */
        {
            uint32_t btn = 1U;

            while (btn == 1U)
            {
                CHECK(SCMI_BbmButtonGet(channel, &btn));
            }
        }

        /* Test ON/OFF button notification */
        {
            uint32_t flags = SCMI_BBM_NOTIFY_BUTTON_DETECT(1U);

            CHECK(SCMI_BbmButtonNotify(channel, flags));
            printf("Wait for ON/OFF button alarm ...\n");
            CHECK(SCMI_BbmButtonEvent(channel + 1U, &flags));
            if (flags != SCMI_BBM_EVENT_BUTTON_DETECTED(1U))
            {
                CHECK(SM_ERR_TEST);
            }
            CHECK(SCMI_BbmButtonNotify(channel, 0U));
        }

        /* Test ON/OFF button is pressed */
        {
            uint32_t btn = 0U;

            while (btn == 0U)
            {
                CHECK(SCMI_BbmButtonGet(channel, &btn));
            }
        }

        /* Pass in NULL for flags on BbmButtonEvent */
        {
            uint32_t flags = SCMI_BBM_NOTIFY_BUTTON_DETECT(1U);

            CHECK(SCMI_BbmButtonNotify(channel, flags));

            CHECK(SCMI_BbmButtonEvent(channel + 1U, NULL));

            CHECK(SCMI_BbmButtonNotify(channel, 0U));
        }

    }
    /* Access denied */
    else
    {
        uint32_t flags = SCMI_BBM_NOTIFY_BUTTON_DETECT(1U);

        NECHECK(SCMI_BbmButtonNotify(channel, flags),
            SCMI_ERR_DENIED);
    }
#endif
}

