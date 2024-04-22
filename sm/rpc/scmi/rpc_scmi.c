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
/* File containing the implementation of the System Control and Management  */
/* Interface (SCMI).                                                        */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "rpc_smt.h"
#include "config_scmi.h"
#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

#define SCMI_NUM_Q  2U

/* Local macros */

/* SCMI header creation */
#define SCMI_HEADER_TOKEN_MASK  0x3FFU
#define SCMI_HEADER_MSG(x)  (((x) & 0xFFU) << 0U)
#define SCMI_HEADER_TYPE(x)  (((x) & 0x3U) << 8U)
#define SCMI_HEADER_PROTOCOL(x)  (((x) & 0xFFU) << 10U)
#define SCMI_HEADER_TOKEN(x)  (((x) & SCMI_HEADER_TOKEN_MASK) << 18U)

/* SCMI header extraction */
#define SCMI_HEADER_MSG_EX(x)  (((x) & 0xFFU) >> 0U)
#define SCMI_HEADER_TYPE_EX(x)  (((x) & 0x300U) >> 8U)
#define SCMI_HEADER_PROTOCOL_EX(x)  (((x) & 0x3FC00U) >> 10U)
#define SCMI_HEADER_TOKEN_EX(x)  (((x) & 0x0FFC0000U) >> 18U)

/* Local types */

typedef struct
{
    uint32_t header;
    int32_t status;
} channel_err_t;

typedef struct
{
    uint32_t head;
    uint32_t tail;
    uint32_t count;
    uint32_t data[SM_SCMI_MAX_NOTIFY];
} notify_queue_t;

/* Local variables */

static const uint8_t s_protocolList[] =
{
    (uint8_t) SCMI_PROTOCOL_BASE,
    (uint8_t) SCMI_PROTOCOL_POWER,
    (uint8_t) SCMI_PROTOCOL_SYSTEM,
    (uint8_t) SCMI_PROTOCOL_PERF,
    (uint8_t) SCMI_PROTOCOL_CLOCK,
    (uint8_t) SCMI_PROTOCOL_SENSOR,
    (uint8_t) SCMI_PROTOCOL_RESET,
    (uint8_t) SCMI_PROTOCOL_VOLTAGE,
    (uint8_t) SCMI_PROTOCOL_PINCTRL,
    (uint8_t) SCMI_PROTOCOL_LMM,
    (uint8_t) SCMI_PROTOCOL_BBM,
    (uint8_t) SCMI_PROTOCOL_CPU,
#ifdef USES_FUSA
    (uint8_t) SCMI_PROTOCOL_FUSA,
#endif
    (uint8_t) SCMI_PROTOCOL_MISC
};

static uint32_t s_token[SM_SCMI_NUM_CHN];
static uint32_t s_channel2queue[SM_SCMI_NUM_CHN];
static uint32_t s_agent2channel[SM_SCMI_NUM_AGNT][SCMI_NUM_Q];
static notify_queue_t s_queue[SM_SCMI_NUM_AGNT][SCMI_NUM_Q];
#ifdef MONITOR
static channel_err_t s_channelErr[SM_SCMI_NUM_CHN];
#endif

/* Local functions */

static void *RPC_SCMI_HdrAddrGet(uint32_t scmiChannel);
static bool RPC_SCMI_ChannelFree(uint32_t scmiChannel);
static int32_t RPC_SCMI_IsAborted(uint32_t scmiChannel);
static void RPC_SCMI_A2pDispatch(uint32_t scmiChannel);
static int32_t RPC_SCMI_A2pSubDispatch(scmi_caller_t *caller,
    uint32_t protocolId, uint32_t messageId);
static void RPC_SCMI_P2aDispatch(uint32_t scmiChannel);
static int32_t RPC_SCMI_A2pRx(scmi_caller_t *caller, void* msgRx,
    uint32_t len);
static int32_t RPC_SCMI_A2pTx(const scmi_caller_t *caller, uint32_t len,
    int32_t status);

/*--------------------------------------------------------------------------*/
/* Init SCMI instance                                                       */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_Init(uint8_t scmiInst)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check instance */
    if (scmiInst >= SM_NUM_SCMI)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Init each agent for instance */
        for (uint32_t agentId = 0U; agentId < SM_SCMI_NUM_AGNT; agentId++)
        {
            /* Agent belong to instance? */
            if (g_scmiAgentConfig[agentId].scmiInst == scmiInst)
            {
                status = RPC_SCMI_AgentInit(agentId);
            }
        }
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Init SCMI agent                                                          */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_AgentInit(uint32_t agentId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check agent */
    if (agentId >= SM_SCMI_NUM_AGNT)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    if (status == SM_ERR_SUCCESS)
    {
        uint32_t initCount = 0U;

        /* Init transport for each agent channel */
        for (uint32_t scmiChannel = 0U; scmiChannel < SM_SCMI_NUM_CHN;
            scmiChannel++)
        {
            /* Channel belong to agent? */
            if (g_scmiChannelConfig[scmiChannel].agentId == agentId)
            {
                bool noIrq = (g_scmiChannelConfig[scmiChannel].type
                    == SM_SCMI_CHN_P2A);

                /* Record P2A notification channel */
                if (g_scmiChannelConfig[scmiChannel].type
                    == SM_SCMI_CHN_P2A_NOTIFY)
                {
                    s_agent2channel[agentId][SCMI_NOTIFY_Q]
                        = scmiChannel;
                    s_channel2queue[scmiChannel] = SCMI_NOTIFY_Q;
                }

                /* Record P2A priority notification channel */
                if (g_scmiChannelConfig[scmiChannel].type
                    == SM_SCMI_CHN_P2A_PRIORITY)
                {
                    s_agent2channel[agentId][SCMI_PRIORITY_Q]
                        = scmiChannel;
                    s_channel2queue[scmiChannel] = SCMI_PRIORITY_Q;
                }

                /* First channel for this agent? */
                if (initCount == 0U)
                {
                    /* Reset P2A queues */
                    s_queue[agentId][SCMI_NOTIFY_Q].head = 0U;
                    s_queue[agentId][SCMI_NOTIFY_Q].tail = 0U;
                    s_queue[agentId][SCMI_NOTIFY_Q].count = 0U;
                    s_queue[agentId][SCMI_PRIORITY_Q].head = 0U;
                    s_queue[agentId][SCMI_PRIORITY_Q].tail = 0U;
                    s_queue[agentId][SCMI_PRIORITY_Q].count = 0U;
                }

                /* Reset token */
                s_token[scmiChannel] = 0U;

                /* Reset transport */
                switch (g_scmiChannelConfig[scmiChannel].xportType)
                {
                    case SM_XPORT_SMT:
                        /* Init SMT channel */
                        status = RPC_SMT_Init(
                            g_scmiChannelConfig[scmiChannel].xportChannel,
                            noIrq, initCount);
                        break;
                    default:
                        status = SM_ERR_INVALID_PARAMETERS;
                        break;
                }

                /* Increment init count for an agent */
                initCount++;
            }
        }
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI doorbell                                                   */
/*--------------------------------------------------------------------------*/
void RPC_SCMI_Dispatch(uint32_t scmiChannel)
{
    /* Check channel type */
    switch (g_scmiChannelConfig[scmiChannel].type)
    {
        case SM_SCMI_CHN_A2P:
            RPC_SCMI_A2pDispatch(scmiChannel);
            break;
        case SM_SCMI_CHN_P2A:
        case SM_SCMI_CHN_P2A_NOTIFY:
        case SM_SCMI_CHN_P2A_PRIORITY:
            RPC_SCMI_P2aDispatch(scmiChannel);
            break;
        default:
            ; /* Intentional empty default */
            break;
    }
}

/*--------------------------------------------------------------------------*/
/* Send P2A message                                                         */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_P2aTx(uint32_t scmiChannel, uint32_t protocolId,
    uint32_t messageId, uint32_t len, uint32_t *header, bool notify)
{
    int32_t status;
    scmi_msg_status_t *msg;

    /* Get transport buffer address */
    msg = (scmi_msg_status_t*) RPC_SCMI_HdrAddrGet(scmiChannel);

    /* Generate header */
    *header = SCMI_HEADER_MSG(messageId)
        | SCMI_HEADER_PROTOCOL(protocolId)
        | SCMI_HEADER_TOKEN(s_token[scmiChannel]);
    if (notify)
    {
        *header |= SCMI_HEADER_TYPE(3UL);
    }
    msg->header = *header;

    /* Increment token */
    s_token[scmiChannel]++;
    s_token[scmiChannel] &= SCMI_HEADER_TOKEN_MASK;

    /* Send message via transport */
    switch (g_scmiChannelConfig[scmiChannel].xportType)
    {
        case SM_XPORT_SMT:
            status = RPC_SMT_Tx(
                g_scmiChannelConfig[scmiChannel].xportChannel, len,
                false, notify);
            break;
        default:
            status = SM_ERR_NOT_SUPPORTED;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Receive P2A message                                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_P2aRx(uint32_t scmiChannel, uint32_t minLen,
    uint32_t header)
{
    /* Return status */
    return SM_ERR_SUCCESS;
}

/*--------------------------------------------------------------------------*/
/* Check queue full status                                                  */
/*--------------------------------------------------------------------------*/
bool RPC_SCMI_P2aTxQFull(uint32_t agentId, uint32_t len, uint32_t queue)
{
    bool rtn = false;

    if ((len / 4U) > (SM_SCMI_MAX_NOTIFY - s_queue[agentId][queue].count))
    {
        rtn = true;
    }

    /* Return status */
    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Queue message to send on P2A channel                                     */
/*--------------------------------------------------------------------------*/
void RPC_SCMI_P2aTxQ(uint32_t agentId, scmi_msg_id_t msgId, uint32_t *msg,
    uint32_t len, uint32_t queue)
{
    /* Check space in queue */
    if (!RPC_SCMI_P2aTxQFull(agentId, len, queue))
    {
        /* Generate header */
        uint32_t header = SCMI_HEADER_MSG(msgId.messageId)
            | SCMI_HEADER_PROTOCOL(msgId.protocolId)
            | SCMI_HEADER_TYPE(3UL)
            | SCMI_HEADER_TOKEN(len);
        msg[0] = header;

        /* Queue message data */
        for (uint32_t idx = 0U; idx < (len / 4U); idx++)
        {
            s_queue[agentId][queue].data[s_queue[agentId][queue].head]
                = msg[idx];
            s_queue[agentId][queue].head = (s_queue[agentId][queue].head
                + 1U) % SM_SCMI_MAX_NOTIFY;
            s_queue[agentId][queue].count++;
        }

        /* Trigger xmit */
        RPC_SCMI_P2aDispatch(s_agent2channel[agentId][queue]);
    }
}

/*--------------------------------------------------------------------------*/
/* Bounded string copy                                                      */
/*--------------------------------------------------------------------------*/
void RPC_SCMI_StrCpy(uint8_t *dst, const uint8_t *src, uint32_t maxLen)
{
    uint8_t *pDst = dst;
    const uint8_t *pSrc = src;
    uint32_t len = 1U;

    while ((len < maxLen) && (*pSrc != 0U))
    {
        *pDst = *pSrc;
        pDst++;
        pSrc++;
        len++;
    }
    *pDst = 0U;
}

/*--------------------------------------------------------------------------*/
/* Get number of protocols                                                  */
/*--------------------------------------------------------------------------*/
uint32_t RPC_SCMI_NumProtocolsGet(void)
{
    return sizeof(s_protocolList);
}

/*--------------------------------------------------------------------------*/
/* Get compressed list of protocols                                         */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_ProtocolListGet(uint32_t skip, uint32_t numWords,
    uint32_t *numProtocols, uint32_t *protocolListDst)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t len = sizeof(s_protocolList);

    /* Zero out response */
    *numProtocols = 0U;
    for (uint32_t word = 0U; word < numWords; word++)
    {
        protocolListDst[word] = 0U;
    }

    /* Fill in list */
    uint32_t count = 0U;
    for (uint32_t proto = skip; proto < len; proto++)
    {
        /* Insert protocol */
        protocolListDst[count / 4U] |= ((uint32_t) s_protocolList[proto])
            << ((count % 4U) * 8U);

        /* Next position */
        count++;

        /* Stop if out of space */
        if ((count / 4U) >= numWords)
        {
            break;
        }
    }
    *numProtocols = count;

    if (count == 0U)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset SCMI instance                                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_Reset(uint8_t scmiInst)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Reset all agents of this instance */
    for (uint32_t agentId = 0U; agentId < SM_SCMI_NUM_AGNT; agentId++)
    {
        /* Reset SCMI state */
        if (g_scmiAgentConfig[agentId].scmiInst == scmiInst)
        {
            /* Reset agent */
            status = RPC_SCMI_BaseDispatchReset(g_scmiConfig[scmiInst].lmId,
                agentId, true);
        }

        /* Exit on error */
        if (status != SM_ERR_SUCCESS)
        {
            break;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Trigger SCMI notification                                                */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_Trigger(const lmm_rpc_trigger_t *trigger)
{
    int32_t status;

    scmi_msg_id_t msgId;

    /* Queue via protocol */
    switch (trigger->event)
    {
        case LMM_TRIGGER_SYSTEM:
            msgId.protocolId = SCMI_PROTOCOL_SYSTEM;
            msgId.messageId = RPC_SCMI_NOTIFY_SYSTEM_POWER_STATE_NOTIFIER;
            status = RPC_SCMI_SysDispatchNotification(msgId, trigger);
            break;
        case LMM_TRIGGER_SENSOR:
            msgId.protocolId = SCMI_PROTOCOL_SENSOR;
            msgId.messageId = RPC_SCMI_NOTIFY_SENSOR_TRIP_POINT_EVENT;
            status = RPC_SCMI_SensorDispatchNotification(msgId, trigger);
            break;
        case LMM_TRIGGER_LM:
            msgId.protocolId = SCMI_PROTOCOL_LMM;
            msgId.messageId = RPC_SCMI_NOTIFY_LMM_EVENT;
            status = RPC_SCMI_LmmDispatchNotification(msgId, trigger);
            break;
        case LMM_TRIGGER_RTC:
            msgId.protocolId = SCMI_PROTOCOL_BBM;
            msgId.messageId = RPC_SCMI_NOTIFY_BBM_RTC_EVENT;
            status = RPC_SCMI_BbmDispatchNotification(msgId, trigger);
            break;
        case LMM_TRIGGER_BUTTON:
            msgId.protocolId = SCMI_PROTOCOL_BBM;
            msgId.messageId = RPC_SCMI_NOTIFY_BBM_BUTTON_EVENT;
            status = RPC_SCMI_BbmDispatchNotification(msgId, trigger);
            break;
#ifdef USES_FUSA
        case LMM_TRIGGER_FUSA_FEENV:
            msgId.protocolId = SCMI_PROTOCOL_FUSA;
            msgId.messageId = RPC_SCMI_NOTIFY_FUSA_FEENV_STATE_EVENT;
            status = RPC_SCMI_FusaDispatchNotification(msgId, trigger);
            break;
        case LMM_TRIGGER_FUSA_SEENV:
            msgId.protocolId = SCMI_PROTOCOL_FUSA;
            msgId.messageId = RPC_SCMI_NOTIFY_FUSA_SEENV_STATE_REQ_EVENT;
            status = RPC_SCMI_FusaDispatchNotification(msgId, trigger);
            break;
        case LMM_TRIGGER_FUSA_FAULT:
            msgId.protocolId = SCMI_PROTOCOL_FUSA;
            msgId.messageId = RPC_SCMI_NOTIFY_FUSA_FAULT_EVENT;
            status = RPC_SCMI_FusaDispatchNotification(msgId, trigger);
            break;
#endif
        case LMM_TRIGGER_CTRL:
            msgId.protocolId = SCMI_PROTOCOL_MISC;
            msgId.messageId = RPC_SCMI_NOTIFY_MISC_CONTROL_EVENT;
            status = RPC_SCMI_MiscDispatchNotification(msgId, trigger);
            break;
        default:
            status = SM_ERR_INVALID_PARAMETERS;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Dump collected SCMI errors                                               */
/*--------------------------------------------------------------------------*/
void RPC_SCMI_ErrorDump(uint8_t scmiInst)
{
#ifdef MONITOR
    /* Loop over channels */
    for (uint32_t scmiChannel = 0U; scmiChannel < SM_SCMI_NUM_CHN;
        scmiChannel++)
    {
        uint32_t agent = g_scmiChannelConfig[scmiChannel].agentId;

        if (g_scmiAgentConfig[agent].scmiInst == scmiInst)
        {
            channel_err_t *err = &s_channelErr[scmiChannel];

            if (err->status != SM_ERR_SUCCESS)
            {
                uint32_t header = err->header;

                printf("SCMI err (chn=%u): ", scmiChannel);
                printf("protocolId=0x%X", SCMI_HEADER_PROTOCOL_EX(header));
                printf(", messageId=0x%X", SCMI_HEADER_MSG_EX(header));
                printf(", status=%d\n", err->status);

                /* Clear log */
                err->status = SM_ERR_SUCCESS;
            }
        }
    }
#endif
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Get buffer address                                                       */
/*--------------------------------------------------------------------------*/
static void *RPC_SCMI_HdrAddrGet(uint32_t scmiChannel)
{
    void *addr = NULL;

    /* Get message buffer address */
    switch (g_scmiChannelConfig[scmiChannel].xportType)
    {
        case SM_XPORT_SMT:
            addr = RPC_SMT_HdrAddrGet(
                g_scmiChannelConfig[scmiChannel].xportChannel);
            break;
        default:
            ; /* Intentional empty default */
            break;
    }

    return addr;
}

/*--------------------------------------------------------------------------*/
/* Get channel free status                                                  */
/*--------------------------------------------------------------------------*/
static bool RPC_SCMI_ChannelFree(uint32_t scmiChannel)
{
    bool channelFree = false;

    switch (g_scmiChannelConfig[scmiChannel].xportType)
    {
        case SM_XPORT_SMT:
            channelFree = RPC_SMT_ChannelFree(
                g_scmiChannelConfig[scmiChannel].xportChannel);
            break;
        default:
            ; /* Intentional empty default */
            break;
    }

    return channelFree;
}

/*--------------------------------------------------------------------------*/
/* Get abort status                                                         */
/*                                                                          */
/* Parameters:                                                              */
/* - scmiChannel: SCMI channel                                              */
/*                                                                          */
/* This function returns SM_ERR_ABORT_ERROR if the channel is aborted.      */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_INVALID_PARAMETERS: if the configured transport is not          */
/*   supported                                                              */
/* - others returned by the transport abort function (e.g.                  */
/*   RPC_SMT_IsAborted())                                                   */
/*--------------------------------------------------------------------------*/
static int32_t RPC_SCMI_IsAborted(uint32_t scmiChannel)
{
    int32_t status;

    /* Get abort status */
    switch (g_scmiChannelConfig[scmiChannel].xportType)
    {
        case SM_XPORT_SMT:
            status = RPC_SMT_IsAborted(
                g_scmiChannelConfig[scmiChannel].xportChannel);
            break;
        default:
            status = SM_ERR_NOT_SUPPORTED;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI A2P request                                                */
/*--------------------------------------------------------------------------*/
static void RPC_SCMI_A2pDispatch(uint32_t scmiChannel)
{
    scmi_caller_t caller = { 0 };

    /* Record channel */
    caller.scmiChannel = scmiChannel;

    /* Map channel to agent */
    caller.agentId = (uint32_t) g_scmiChannelConfig[scmiChannel].agentId;

    /* Map agent to instance */
    caller.scmiInst= (uint32_t) g_scmiAgentConfig[caller.agentId].scmiInst;

    /* Map instance to LM */
    caller.lmId= g_scmiConfig[caller.scmiInst].lmId;

    /* Record safety type */
    caller.safeType= (uint32_t) g_lmmConfig[caller.lmId].safeType;

    /* Record S-EENV ID */
    caller.seenvId= (uint32_t) g_scmiAgentConfig[caller.agentId].seenvId;

    /* Map agent to instance agent */
    caller.instAgentId = caller.agentId + 1U
        - g_scmiConfig[caller.scmiInst].firstAgent;

    /* Get the message buffer address */
    caller.msg = (scmi_msg_status_t*) RPC_SCMI_HdrAddrGet(scmiChannel);
    caller.lenMsg = sizeof(scmi_msg_status_t);

    /* Get the buffer? */
    if (caller.msg != NULL)
    {
        int32_t status;
        static scmi_msg_t s_msgCopy;

        /* Check if aborted */
        status = RPC_SCMI_IsAborted(scmiChannel);

        /* Copy receive data and do CRC */
        if (status == SM_ERR_SUCCESS)
        {
            caller.msgCopy = &s_msgCopy;
            status = RPC_SCMI_A2pRx(&caller, (void*) &s_msgCopy,
                sizeof(s_msgCopy));
        }
        else
        {
            /* Use caller header to return error status */
            caller.header = caller.msg->header;
        }

        /* Get header */
        if (status == SM_ERR_SUCCESS)
        {
            caller.header = s_msgCopy.header;

            /* Check message type */
            if (SCMI_HEADER_TYPE_EX(caller.header) != 0U)
            {
                status = SM_ERR_COMMS_ERROR;
            }
        }

        if (status == SM_ERR_SUCCESS)
        {
            uint32_t protocolId;
            uint32_t messageId;
            uint32_t token;

            /* Decompose header */
            protocolId = SCMI_HEADER_PROTOCOL_EX(caller.header);
            messageId = SCMI_HEADER_MSG_EX(caller.header);
            token = SCMI_HEADER_TOKEN_EX(caller.header);

            /* Protocol extension? */
            if (protocolId >= 0x90U)
            {
                caller.extension = true;
                protocolId -= 0x80U;
            }

            /* SCMI token sequence check? */
            if (g_scmiChannelConfig[scmiChannel].sequence
                == SM_SCMI_SEQ_TOKEN)
            {
                /* Check token */
                if (token != s_token[scmiChannel])
                {
                    status = SM_ERR_SEQ_ERROR;
                }
            }

            /* Increment token */
            s_token[scmiChannel]++;
            s_token[scmiChannel] &= SCMI_HEADER_TOKEN_MASK;

            if (status == SM_ERR_SUCCESS)
            {
                /* Dispatch subrequest */
                status = RPC_SCMI_A2pSubDispatch(&caller, protocolId,
                    messageId);
            }
        }

        /* Send response */
        if (caller.lenMsg > 0U)
        {
            (void) RPC_SCMI_A2pTx(&caller, caller.lenMsg, status);
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI A2P subrequest                                             */
/*--------------------------------------------------------------------------*/
static int32_t RPC_SCMI_A2pSubDispatch(scmi_caller_t *caller,
    uint32_t protocolId, uint32_t messageId)
{
    int32_t status = SM_ERR_SUCCESS;

    switch (protocolId)
    {
        case SCMI_PROTOCOL_BASE:
            status = RPC_SCMI_BaseDispatchCommand(caller, messageId);
            break;
        case SCMI_PROTOCOL_POWER:
            status = RPC_SCMI_PowerDispatchCommand(caller, messageId);
            break;
        case SCMI_PROTOCOL_SYSTEM:
            status = RPC_SCMI_SysDispatchCommand(caller, messageId);
            break;
        case SCMI_PROTOCOL_PERF:
            status = RPC_SCMI_PerfDispatchCommand(caller, messageId);
            break;
        case SCMI_PROTOCOL_CLOCK:
            status = RPC_SCMI_ClockDispatchCommand(caller, messageId);
            break;
        case SCMI_PROTOCOL_SENSOR:
            status = RPC_SCMI_SensorDispatchCommand(caller, messageId);
            break;
        case SCMI_PROTOCOL_RESET:
            status = RPC_SCMI_ResetDispatchCommand(caller, messageId);
            break;
        case SCMI_PROTOCOL_VOLTAGE:
            status = RPC_SCMI_VoltageDispatchCommand(caller, messageId);
            break;
        case SCMI_PROTOCOL_PINCTRL:
            status = RPC_SCMI_PinctrlDispatchCommand(caller, messageId);
            break;
        case SCMI_PROTOCOL_LMM:
            status = RPC_SCMI_LmmDispatchCommand(caller, messageId);
            break;
        case SCMI_PROTOCOL_BBM:
            status = RPC_SCMI_BbmDispatchCommand(caller, messageId);
            break;
        case SCMI_PROTOCOL_CPU:
            status = RPC_SCMI_CpuDispatchCommand(caller, messageId);
            break;
#ifdef USES_FUSA
        case SCMI_PROTOCOL_FUSA:
            status = RPC_SCMI_FusaDispatchCommand(caller, messageId);
            break;
#endif
        case SCMI_PROTOCOL_MISC:
            status = RPC_SCMI_MiscDispatchCommand(caller, messageId);
            break;
        default:
            status = SM_ERR_NOT_SUPPORTED;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI P2A request                                                */
/*--------------------------------------------------------------------------*/
static void RPC_SCMI_P2aDispatch(uint32_t scmiChannel)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t agentId = g_scmiChannelConfig[scmiChannel].agentId;
    uint32_t queue = s_channel2queue[scmiChannel];
    uint32_t *msg = NULL;

    /* Check if a message to send */
    if (s_queue[agentId][queue].count == 0U)
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check if xport free to send a message */
    if (status == SM_ERR_SUCCESS)
    {
        if (!RPC_SCMI_ChannelFree(scmiChannel))
        {
            status = SM_ERR_BUSY;
        }
    }

    /* Get message buffer address */
    if (status == SM_ERR_SUCCESS)
    {
        msg = (uint32_t*) RPC_SCMI_HdrAddrGet(scmiChannel);
        if (msg == NULL)
        {
            status = SM_ERR_GENERIC_ERROR;
        }
    }

    /* All clear to send a message */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t header = s_queue[agentId][queue].data[
            s_queue[agentId][queue].tail];
        uint32_t len = SCMI_HEADER_TOKEN_EX(header);

        /* Copy out message data */
        for (uint32_t idx = 0U; idx < (len / 4U); idx++)
        {
            msg[idx] = s_queue[agentId][queue].data[
                s_queue[agentId][queue].tail];
            s_queue[agentId][queue].tail = (s_queue[agentId][queue].tail
                + 1U) % SM_SCMI_MAX_NOTIFY;
            s_queue[agentId][queue].count--;
        }

        /* Send message */
        (void) RPC_SCMI_P2aTx(scmiChannel, SCMI_HEADER_PROTOCOL_EX(header),
            SCMI_HEADER_MSG_EX(header), len, &header, true);
    }
}

/*--------------------------------------------------------------------------*/
/* Receive A2P command                                                      */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - msgRx: Pointer to the destination buffer                               */
/* - len: Size in bytes of the destination buffer                           */
/*                                                                          */
/* This function receives an SCMI payload using the A2P protocol.           */
/* The caller parameter identifies the calling client. The msgRx            */
/* parameter points to a buffer to copy the payload to. The len             */
/* parameter is the size in bytes of the destination buffer.                */
/*                                                                          */
/* This function then calls the linked transport receive function (e.g.     */
/* RPC_SMT_Rx()).                                                           */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_INVALID_PARAMETERS: if the configured transport is not          */
/*   supported                                                              */
/* - SM_ERR_PROTOCOL_ERROR: if the header stored in caller doesn't          */
/*   match the header found in the buffer                                   */
/* - others returned by the transport receive function (e.g. RPC_SMT_Rx())  */
/*--------------------------------------------------------------------------*/
static int32_t RPC_SCMI_A2pRx(scmi_caller_t *caller, void* msgRx,
    uint32_t len)
{
    int32_t status;
    uint32_t size = len;
    uint32_t scmiChannel = caller->scmiChannel;

    /* Copy out message */
    switch (g_scmiChannelConfig[scmiChannel].xportType)
    {
        case SM_XPORT_SMT:
            status = RPC_SMT_Rx(
                g_scmiChannelConfig[scmiChannel].xportChannel,
                msgRx, &size, true);
            break;
        default:
            status = SM_ERR_NOT_SUPPORTED;
            break;
    }

    /* Save rx length for checking later */
    caller->lenCopy = size;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Send A2P response                                                        */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - len: Size in bytes of the payload                                      */
/* - status: Status to insert into the payload                              */
/*                                                                          */
/* This function transmits an SCMI payload using the A2P protocol.          */
/* The caller parameter identifies the calling client. The len              */
/* parameter is the size in bytes of the source payload. Note the           */
/* buffer address and header are in caller. These were set when             */
/* the RPC was made and should not be changed, but can be used to           */
/* write in the return data.                                                */
/*                                                                          */
/* This function then calls the linked transport receive function (e.g.     */
/* RPC_SMT_Tx()).                                                           */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_INVALID_PARAMETERS: if the configured transport is not          */
/*   supported                                                              */
/* - others returned by the transport transmit function (e.g. RPC_SMT_Tx()) */
/*--------------------------------------------------------------------------*/
static int32_t RPC_SCMI_A2pTx(const scmi_caller_t *caller, uint32_t len,
    int32_t status)
{
    int32_t rtn;
    uint32_t header = caller->header;
    uint32_t scmiChannel = caller->scmiChannel;
    uint32_t newLen = len;

    /* Add in header */
    caller->msg->header = header;
    caller->msg->status = status;

#ifdef MONITOR
    /* Log error */
    if ((status != SM_ERR_SUCCESS)
        && (s_channelErr[scmiChannel].status == SM_ERR_SUCCESS))
    {
        s_channelErr[scmiChannel].header = header;
        s_channelErr[scmiChannel].status = status;
    }
#endif

    /* Adjust size on error */
    if (status != SM_ERR_SUCCESS)
    {
        newLen = sizeof(scmi_msg_status_t);
    }

    /* Send response via transport */
    switch (g_scmiChannelConfig[scmiChannel].xportType)
    {
        case SM_XPORT_SMT:
            rtn = RPC_SMT_Tx(g_scmiChannelConfig[scmiChannel].xportChannel,
                newLen, true, true);
            break;
        default:
            rtn = SM_ERR_NOT_SUPPORTED;
            break;
    }

    return rtn;
}

