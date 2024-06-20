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
/* Interface (SCMI) bbm protocol.                                           */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x10000U

/* SCMI bbm protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION             0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES          0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES  0x2U
#define COMMAND_BBM_GPR_SET                  0x3U
#define COMMAND_BBM_GPR_GET                  0x4U
#define COMMAND_BBM_RTC_ATTRIBUTES           0x5U
#define COMMAND_BBM_RTC_TIME_SET             0x6U
#define COMMAND_BBM_RTC_TIME_GET             0x7U
#define COMMAND_BBM_RTC_ALARM_SET            0x8U
#define COMMAND_BBM_BUTTON_GET               0x9U
#define COMMAND_BBM_RTC_NOTIFY               0xAU
#define COMMAND_BBM_BUTTON_NOTIFY            0xBU
#define COMMAND_BBM_RTC_STATE                0xCU
#define COMMAND_NEGOTIATE_PROTOCOL_VERSION   0x10U
#define COMMAND_SUPPORTED_MASK               0x11FFFUL

/* SCMI BBM max argument lengths */
#define BBM_MAX_NAME  16U

/* Local macros */

/* SCMI BBM protocol attributes */
#define BBM_PROTO_ATTR_NUM_RTC(x)  (((x) & 0xFFU) << 16U)
#define BBM_PROTO_ATTR_NUM_GPR(x)  (((x) & 0xFFFFU) << 0U)

/* SCMI RTC attributes */
#define BBM_RTC_ATTR_SEC_WIDTH(x)   (((x) & 0xFFU) << 24U)
#define BBM_RTC_ATTR_TICK_WIDTH(x)  (((x) & 0xFFU) << 16U)
#define BBM_RTC_ATTR_TICKS(x)       (((x) & 0xFFFFU) << 0U)

/* SCMI BBM RTC flags */
#define BBM_RTC_FLAGS_TICKS(x)  (((x) & 0x1U) >> 0U)

/* SCMI BBM RTC alarm flags */
#define BBM_ALARM_FLAGS_ENABLE(x)  (((x) & 0x1U) >> 0U)

/* SCMI BBM RTC notification flags */
#define BBM_NOTIFY_RTC_UPDATED(x)   (((x) & 0x4U) >> 2U)
#define BBM_NOTIFY_RTC_ROLLOVER(x)  (((x) & 0x2U) >> 1U)
#define BBM_NOTIFY_RTC_ALARM(x)     (((x) & 0x1U) >> 0U)

/* SCMI BBM button notification flags */
#define BBM_NOTIFY_BUTTON_DETECT(x)  (((x) & 0x1U) >> 0U)

/* SCMI BBM RTC state flags */
#define BBM_RTC_STATE_BATT_LOW(x)  (((x) & 0x1U) << 1U)
#define BBM_RTC_STATE_RESET(x)     (((x) & 0x1U) << 0U)

/* SCMI BBM RTC event flags */
#define BBM_EVENT_RTC_ID(x)        (((x) & 0xFFU) << 24U)
#define BBM_EVENT_RTC_UPDATED(x)   (((x) & 0x1U) << 2U)
#define BBM_EVENT_RTC_ROLLOVER(x)  (((x) & 0x1U) << 1U)
#define BBM_EVENT_RTC_ALARM(x)     (((x) & 0x1U) << 0U)

/* SCMI BBM button event flags */
#define BBM_EVENT_BUTTON_DETECTED(x)  (((x) & 0x1U) << 0U)

/* Local types */

/* SCMI RTC time */
typedef struct
{
    /* Lower 32 bits of the time in seconds/ticks */
    uint32_t lower;
    /* Upper 32 bits of the time in seconds/ticks */
    uint32_t upper;
} rtc_time_t;

/* Response type for ProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol version */
    uint32_t version;
} msg_tbbm0_t;

/* Response type for ProtocolAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol attributes */
    uint32_t attributes;
} msg_tbbm1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rbbm2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_tbbm2_t;

/* Request type for BbmGprSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Index of GPR to write */
    uint32_t index;
    /* 32-bit value to write to the GPR */
    uint32_t value;
} msg_rbbm3_t;

/* Request type for BbmGprGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Index of GPR to read */
    uint32_t index;
} msg_rbbm4_t;

/* Response type for BbmGprGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* 32-bit value read from the GPR */
    uint32_t value;
} msg_tbbm4_t;

/* Request type for BbmRtcAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier of the RTC */
    uint32_t rtcId;
} msg_rbbm5_t;

/* Response type for BbmRtcAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* RTC attributes */
    uint32_t attributes;
    /* ASCII name string */
    uint8_t name[BBM_MAX_NAME];
} msg_tbbm5_t;

/* Request type for BbmRtcTimeSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier of the RTC */
    uint32_t rtcId;
    /* RTC flags */
    uint32_t flags;
    /* Time in seconds/ticks to write to the RTC */
    rtc_time_t val;
} msg_rbbm6_t;

/* Request type for BbmRtcTimeGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier of the RTC */
    uint32_t rtcId;
    /* RTC flags */
    uint32_t flags;
} msg_rbbm7_t;

/* Response type for BbmRtcTimeGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Time in seconds/ticks read from the RTC */
    rtc_time_t val;
} msg_tbbm7_t;

/* Request type for BbmRtcAlarmSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier of the RTC */
    uint32_t rtcId;
    /* Alarm flags */
    uint32_t flags;
    /* Alarm time in seconds to write to the RTC */
    rtc_time_t val;
} msg_rbbm8_t;

/* Response type for BbmButtonGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* State of the ON/OFF button */
    uint32_t buttonState;
} msg_tbbm9_t;

/* Request type for BbmRtcNotify() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier of the RTC */
    uint32_t rtcId;
    /* Notification flags */
    uint32_t flags;
} msg_rbbm10_t;

/* Request type for BbmButtonNotify() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Notification flags */
    uint32_t flags;
} msg_rbbm11_t;

/* Request type for BbmRtcState() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier of the RTC */
    uint32_t rtcId;
} msg_rbbm12_t;

/* Response type for BbmRtcState() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* State of the RTC */
    uint32_t state;
} msg_tbbm12_t;

/* Request type for NegotiateProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* The negotiated protocol version the agent intends to use */
    uint32_t version;
} msg_rbbm16_t;

/* Request type for BbmRtcEvent() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* RTC events */
    uint32_t flags;
} msg_rbbm32_t;

/* Request type for BbmButtonEvent() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Button events */
    uint32_t flags;
} msg_rbbm33_t;

/* Local functions */

static int32_t BbmProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbbm0_t *out);
static int32_t BbmProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbbm1_t *out);
static int32_t BbmProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rbbm2_t *in, msg_tbbm2_t *out);
static int32_t BbmGprSet(const scmi_caller_t *caller, const msg_rbbm3_t *in,
    const scmi_msg_status_t *out);
static int32_t BbmGprGet(const scmi_caller_t *caller, const msg_rbbm4_t *in,
    msg_tbbm4_t *out);
static int32_t BbmRtcAttributes(const scmi_caller_t *caller,
    const msg_rbbm5_t *in, msg_tbbm5_t *out);
static int32_t BbmRtcTimeSet(const scmi_caller_t *caller,
    const msg_rbbm6_t *in, const scmi_msg_status_t *out);
static int32_t BbmRtcTimeGet(const scmi_caller_t *caller,
    const msg_rbbm7_t *in, msg_tbbm7_t *out);
static int32_t BbmRtcAlarmSet(const scmi_caller_t *caller,
    const msg_rbbm8_t *in, const scmi_msg_status_t *out);
static int32_t BbmButtonGet(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbbm9_t *out);
static int32_t BbmRtcNotify(const scmi_caller_t *caller,
    const msg_rbbm10_t *in, const scmi_msg_status_t *out);
static int32_t BbmButtonNotify(const scmi_caller_t *caller,
    const msg_rbbm11_t *in, const scmi_msg_status_t *out);
static int32_t BbmRtcState(const scmi_caller_t *caller,
    const msg_rbbm12_t *in, msg_tbbm12_t *out);
static int32_t BbmNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rbbm16_t *in, const scmi_msg_status_t *out);
static int32_t BbmRtcEvent(scmi_msg_id_t msgId,
    const lmm_rpc_trigger_t *trigger);
static int32_t BbmButtonEvent(scmi_msg_id_t msgId,
    const lmm_rpc_trigger_t *trigger);
static int32_t BbmResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_BbmDispatchCommand(scmi_caller_t *caller,
    uint32_t messageId)
{
    int32_t status = SM_ERR_SUCCESS;
    const scmi_msg_t *in = caller->msgCopy;
    scmi_msg_status_t *out = caller->msg;
    uint32_t lenOut = sizeof(scmi_msg_status_t);

    /* Handle standard messages */
    switch (messageId)
    {
        case COMMAND_PROTOCOL_VERSION:
            lenOut = sizeof(msg_tbbm0_t);
            status = BbmProtocolVersion(caller, (const scmi_msg_header_t*) in,
                (msg_tbbm0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tbbm1_t);
            status = BbmProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tbbm1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tbbm2_t);
            status = BbmProtocolMessageAttributes(caller,
                (const msg_rbbm2_t*) in, (msg_tbbm2_t*) out);
            break;
        case COMMAND_BBM_GPR_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = BbmGprSet(caller, (const msg_rbbm3_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_BBM_GPR_GET:
            lenOut = sizeof(msg_tbbm4_t);
            status = BbmGprGet(caller, (const msg_rbbm4_t*) in,
                (msg_tbbm4_t*) out);
            break;
        case COMMAND_BBM_RTC_ATTRIBUTES:
            lenOut = sizeof(msg_tbbm5_t);
            status = BbmRtcAttributes(caller, (const msg_rbbm5_t*) in,
                (msg_tbbm5_t*) out);
            break;
        case COMMAND_BBM_RTC_TIME_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = BbmRtcTimeSet(caller, (const msg_rbbm6_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_BBM_RTC_TIME_GET:
            lenOut = sizeof(msg_tbbm7_t);
            status = BbmRtcTimeGet(caller, (const msg_rbbm7_t*) in,
                (msg_tbbm7_t*) out);
            break;
        case COMMAND_BBM_RTC_ALARM_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = BbmRtcAlarmSet(caller, (const msg_rbbm8_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_BBM_BUTTON_GET:
            lenOut = sizeof(msg_tbbm9_t);
            status = BbmButtonGet(caller, (const scmi_msg_header_t*) in,
                (msg_tbbm9_t*) out);
            break;
        case COMMAND_BBM_RTC_NOTIFY:
            lenOut = sizeof(const scmi_msg_status_t);
            status = BbmRtcNotify(caller, (const msg_rbbm10_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_BBM_BUTTON_NOTIFY:
            lenOut = sizeof(const scmi_msg_status_t);
            status = BbmButtonNotify(caller, (const msg_rbbm11_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_BBM_RTC_STATE:
            lenOut = sizeof(msg_tbbm12_t);
            status = BbmRtcState(caller, (const msg_rbbm12_t*) in,
                (msg_tbbm12_t*) out);
            break;
        case COMMAND_NEGOTIATE_PROTOCOL_VERSION:
            lenOut = sizeof(const scmi_msg_status_t);
            status = BbmNegotiateProtocolVersion(caller,
                (const msg_rbbm16_t*) in, (const scmi_msg_status_t*) out);
            break;
        default:
            status = SM_ERR_NOT_SUPPORTED;
            break;
    }

    /* Update length */
    caller->lenMsg = lenOut;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI notifications                                              */
/*                                                                          */
/* Parameters:                                                              */
/* - msgId: Message ID to dispatch                                          */
/* - trigger: Trigger data                                                  */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_BbmDispatchNotification(scmi_msg_id_t msgId,
    const lmm_rpc_trigger_t *trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Handle notifications */
    switch (msgId.messageId)
    {
        case RPC_SCMI_NOTIFY_BBM_RTC_EVENT:
            status = BbmRtcEvent(msgId, trigger);
            break;
        case RPC_SCMI_NOTIFY_BBM_BUTTON_EVENT:
            status = BbmButtonEvent(msgId, trigger);
            break;
        default:
            status = SM_ERR_NOT_SUPPORTED;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI reset                                                      */
/*                                                                          */
/* Parameters:                                                              */
/* - lmId: LM to reset                                                      */
/* - agentId: Message ID to dispatch                                        */
/* - permissionsReset: True to reset permissions                            */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_BbmDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return BbmResetAgentConfig(lmId, agentId, permissionsReset);
}

/*==========================================================================*/
/* Custom Protocol Implementation                                           */
/*==========================================================================*/

/* Local types */

typedef struct
{
    bool alarmEnabled;
    bool alarmNotify[SM_SCMI_NUM_AGNT];
    bool rolloverNotify[SM_SCMI_NUM_AGNT];
    bool updateNotify[SM_SCMI_NUM_AGNT];
} rtc_info_t;

/* Local variables */

static rtc_info_t s_rtcInfo[SM_NUM_RTC];
static bool s_buttonNotify[SM_SCMI_NUM_AGNT];

/*--------------------------------------------------------------------------*/
/* Get protocol version                                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->version: Protocol version. For this revision of the               */
/*   specification, this value must be 0x10000                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_BbmProtocolVersion().                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbbm0_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Return data */
    if (status == SM_ERR_SUCCESS)
    {
        /* Return version */
        out->version = PROTOCOL_VERSION;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get protocol attributes                                                  */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->attributes: Protocol attributes:                                  */
/*   Bits[31:8] Number of RTC.                                              */
/*   Bits[15:0] Number of persistent storage (GPR) words                    */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_BbmProtocolAttributes().                                            */
/*                                                                          */
/*  Access macros:                                                          */
/* - BBM_PROTO_ATTR_NUM_RTC() - Number of RTCs                              */
/* - BBM_PROTO_ATTR_NUM_GPR() - Number of persistent storage (GPR) words    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbbm1_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Return data */
    if (status == SM_ERR_SUCCESS)
    {
        /* Return attributes */
        out->attributes = BBM_PROTO_ATTR_NUM_RTC(SM_NUM_RTC)
            | BBM_PROTO_ATTR_NUM_GPR(SM_NUM_GPR);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get protocol message attributes                                          */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->messageId: Message ID of the message                               */
/* - out->attributes: Message attributes. Flags that are associated with a  */
/*   specific function in the protocol.                                     */
/*   For all functions in this protocol, this parameter has a value of 0    */
/*                                                                          */
/* Process the PROTOCOL_MESSAGE_ATTRIBUTES message. Platform handler for    */
/* SCMI_BbmProtocolMessageAttributes().                                     */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is invalid    */
/*   or not provided by this platform implementation.                       */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rbbm2_t *in, msg_tbbm2_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Return data */
    if (status == SM_ERR_SUCCESS)
    {
        /* Always zero */
        out->attributes = 0U;

        /* Is message supported ? */
        if ((in->messageId >= 32U)
            || (((COMMAND_SUPPORTED_MASK >> in->messageId) & 0x1U) == 0U))
        {
            status = SM_ERR_NOT_FOUND;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Write a GPR value                                                        */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->index: Index of GPR to write                                       */
/* - in->value: 32-bit value to write to the GPR                            */
/*                                                                          */
/* Process the BBM_GPR_SET message. Platform handler for SCMI_BbmGprSet().  */
/* Requires access greater than or equal to EXCLUSIVE.                      */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the GPR was successfully written.                   */
/* - SM_ERR_NOT_FOUND: if the index is not valid.                           */
/* - SM_ERR_DENIED: if the agent does not have permission to write the      */
/*   specified GPR.                                                         */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmGprSet(const scmi_caller_t *caller, const msg_rbbm3_t *in,
    const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check GPR */
    if ((status == SM_ERR_SUCCESS) && (in->index >= SM_NUM_GPR))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].gprPerms[in->index]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Write GPR */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_BbmGprSet(caller->lmId, in->index, in->value);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Read a GPR value                                                         */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->index: Index of GPR to read                                        */
/* - out->value: 32-bit value read from the GPR                             */
/*                                                                          */
/* Process the BBM_GPR_GET message. Platform handler for SCMI_BbmGprGet().  */
/* Requires access greater than or equal to GET.                            */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the GPR was successfully read.                      */
/* - SM_ERR_NOT_FOUND: if the index is not valid.                           */
/* - SM_ERR_DENIED: if the agent does not have permission to read the       */
/*   specified GPR.                                                         */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmGprGet(const scmi_caller_t *caller, const msg_rbbm4_t *in,
    msg_tbbm4_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check GPR */
    if ((status == SM_ERR_SUCCESS) && (in->index >= SM_NUM_GPR))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].gprPerms[in->index]
        < SM_SCMI_PERM_GET))
    {
        status = SM_ERR_DENIED;
    }

    /* Read GPR */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_BbmGprGet(caller->lmId, in->index,
            &(out->value));
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get attributes for an RTC                                                */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->rtcId: Identifier of the RTC                                       */
/* - out->attributes: RTC attributes:                                       */
/*   Bit[31:24] Bit width of RTC seconds.                                   */
/*   Bit[23:16] Bit width of RTC ticks.                                     */
/*   Bits[15:0] RTC ticks per second                                        */
/* - out->name: Null-terminated ASCII string of up to 16 bytes in length    */
/*   describing the RTC name                                                */
/*                                                                          */
/* Process the BBM_RTC_ATTRIBUTES message. Platform handler for             */
/* SCMI_BbmRtcAttributes().                                                 */
/*                                                                          */
/*  Access macros:                                                          */
/* - BBM_RTC_ATTR_SEC_WIDTH() - Bit width of RTC seconds                    */
/* - BBM_RTC_ATTR_TICK_WIDTH() - Bit width of RTC ticks                     */
/* - BBM_RTC_ATTR_TICKS() - RTC ticks per second                            */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid power domain attributes are returned.         */
/* - SM_ERR_NOT_FOUND: if rtcId pertains to a non-existent RTC.             */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmRtcAttributes(const scmi_caller_t *caller,
    const msg_rbbm5_t *in, msg_tbbm5_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    const uint8_t *nameAddr = (const uint8_t*) "";
    uint32_t secWidth;
    uint32_t tickWidth;
    uint32_t ticksPerSec;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check RTC */
    if ((status == SM_ERR_SUCCESS) && (in->rtcId >= SM_NUM_RTC))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get the domain name */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_BbmRtcNameGet(caller->lmId, in->rtcId,
            (string*) &nameAddr, NULL);
    }

    /* Get the domain name */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_BbmRtcDescribe(caller->lmId, in->rtcId,
            &secWidth, &tickWidth, &ticksPerSec);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        /* Copy out info */
        out->attributes = BBM_RTC_ATTR_SEC_WIDTH(secWidth)
            | BBM_RTC_ATTR_TICK_WIDTH(tickWidth)
            | BBM_RTC_ATTR_TICKS(ticksPerSec);

        /* Copy out name */
        RPC_SCMI_StrCpy(out->name, nameAddr, BBM_MAX_NAME);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set an RTC time                                                          */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->rtcId: Identifier of the RTC                                       */
/* - in->flags: RTC flags:                                                  */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] RTC time format:                                                */
/*   Set to 1 if the time is in ticks.                                      */
/*   Set to 0 if the time is in seconds                                     */
/* - in->val: Time in seconds/ticks to write to the RTC                     */
/*                                                                          */
/* Process the BBM_RTC_TIME_SET message. Platform handler for               */
/* SCMI_BbmRtcTimeSet(). Requires access greater than or equal to           */
/* EXCLUSIVE.                                                               */
/*                                                                          */
/*  Access macros:                                                          */
/* - BBM_RTC_FLAGS_TICKS() - RTC time format                                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the RTC time was successfully set.                  */
/* - SM_ERR_NOT_FOUND: if rtcId pertains to a non-existent RTC.             */
/* - SM_ERR_INVALID_PARAMETERS: if the time is not valid (beyond the        */
/*   range of the RTC).                                                     */
/* - SM_ERR_DENIED: if the agent does not have permission to set the        */
/*   RTC.                                                                   */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmRtcTimeSet(const scmi_caller_t *caller,
    const msg_rbbm6_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check RTC */
    if ((status == SM_ERR_SUCCESS) && (in->rtcId >= SM_NUM_RTC))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].rtcPerms[in->rtcId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Set time if no error */
    if (status == SM_ERR_SUCCESS)
    {
        bool ticks = BBM_RTC_FLAGS_TICKS(in->flags) != 0U;
        uint64_t lmTime = (((uint64_t) in->val.upper) << 32U)
            | (uint64_t) in->val.lower;

        /* Set time */
        status = LMM_BbmRtcTimeSet(caller->lmId, in->rtcId, lmTime,
            ticks);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get an RTC time                                                          */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->rtcId: Identifier of the RTC                                       */
/* - in->flags: RTC flags:                                                  */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] RTC time format:                                                */
/*   Set to 1 if the time is in ticks.                                      */
/*   Set to 0 if the time is in seconds                                     */
/* - out->val: Time in seconds/ticks read from the RTC                      */
/*                                                                          */
/* Process the BBM_RTC_TIME_GET message. Platform handler for               */
/* SCMI_BbmRtcTimeGet().                                                    */
/*                                                                          */
/*  Access macros:                                                          */
/* - BBM_RTC_FLAGS_TICKS() - RTC time format                                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the RTC time was successfully read.                 */
/* - SM_ERR_NOT_FOUND: if rtcId pertains to a non-existent RTC.             */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmRtcTimeGet(const scmi_caller_t *caller,
    const msg_rbbm7_t *in, msg_tbbm7_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool ticks = BBM_RTC_FLAGS_TICKS(in->flags) != 0U;
    uint64_t lmTime;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check RTC */
    if ((status == SM_ERR_SUCCESS) && (in->rtcId >= SM_NUM_RTC))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get time */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_BbmRtcTimeGet(caller->lmId, in->rtcId, &lmTime,
            ticks);
    }

    /* Covert to return format */
    if (status == SM_ERR_SUCCESS)
    {
        out->val.lower = SM_UINT64_L(lmTime);
        out->val.upper = SM_UINT64_H(lmTime);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set an RTC alarm                                                         */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->rtcId: Identifier of the RTC                                       */
/* - in->flags: Alarm flags:                                                */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] RTC enable flag:                                                */
/*   Set to 1 if the RTC alarm should be enabled.                           */
/*   Set to 0 if the RTC alarm should be disabled                           */
/* - in->val: Alarm time in seconds to write to the RTC                     */
/*                                                                          */
/* Process the BBM_RTC_ALARM_SET message. Platform handler for              */
/* SCMI_BbmRtcAlarmSet(). Requires access greater than or equal to PRIV.    */
/*                                                                          */
/*  Access macros:                                                          */
/* - BBM_ALARM_FLAGS_ENABLE() - RTC enable flag                             */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the alarm was successfully set.                     */
/* - SM_ERR_NOT_FOUND: if rtcId pertains to a non-existent RTC.             */
/* - SM_ERR_INVALID_PARAMETERS: if the time is not valid (beyond the        */
/*   range of the RTC alarm).                                               */
/* - SM_ERR_DENIED: if the agent does not have permission to set the RTC    */
/*   alarm.                                                                 */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmRtcAlarmSet(const scmi_caller_t *caller,
    const msg_rbbm8_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check RTC */
    if ((status == SM_ERR_SUCCESS) && (in->rtcId >= SM_NUM_RTC))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].rtcPerms[in->rtcId]
        < SM_SCMI_PERM_PRIV))
    {
        status = SM_ERR_DENIED;
    }

    /* Set alarm if no error */
    if (status == SM_ERR_SUCCESS)
    {
        uint64_t lmTime = (((uint64_t) in->val.upper) << 32U)
            | (uint64_t) in->val.lower;
        s_rtcInfo[in->rtcId].alarmEnabled
            = BBM_ALARM_FLAGS_ENABLE(in->flags) != 0U;

        /* Set alarm */
        status = LMM_BbmRtcAlarmSet(caller->lmId, in->rtcId,
            s_rtcInfo[in->rtcId].alarmEnabled, lmTime);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Read the button state                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->buttonState: State of the ON/OFF button                           */
/*                                                                          */
/* Process the BBM_BUTTON_GET message. Platform handler for                 */
/* SCMI_BbmButtonGet().                                                     */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the button status was read.                         */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmButtonGet(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbbm9_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool buttonAsserted;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Get button state */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_BbmButtonGet(caller->lmId, &buttonAsserted);
    }

    /* Covert to return format */
    if (status == SM_ERR_SUCCESS)
    {
        out->buttonState = buttonAsserted ? 1U : 0U;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure BBM RTC notifications                                          */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->rtcId: Identifier of the RTC                                       */
/* - in->flags: Notification flags:                                         */
/*   Bits[31:3] Reserved, must be zero.                                     */
/*   Bit[2] Update enable:                                                  */
/*   Set to 1 to send notification.                                         */
/*   Set to 0 if no notification.                                           */
/*   Bit[1] Rollover enable:                                                */
/*   Set to 1 to send notification.                                         */
/*   Set to 0 if no notification.                                           */
/*   Bit[0] Alarm enable:                                                   */
/*   Set to 1 to send notification.                                         */
/*   Set to 0 if no notification                                            */
/*                                                                          */
/* Process the BBM_RTC_NOTIFY message. Platform handler for                 */
/* SCMI_BbmRtcNotify(). Requires access greater than or equal to NOTIFY.    */
/*                                                                          */
/*  Access macros:                                                          */
/* - BBM_NOTIFY_RTC_UPDATED() - Enable RTC update notification              */
/* - BBM_NOTIFY_RTC_ROLLOVER() - Enable RTC rollover notification           */
/* - BBM_NOTIFY_RTC_ALARM() - Enable RTC alarm notification                 */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the notification configuration was successfully     */
/*   updated.                                                               */
/* - SM_ERR_NOT_FOUND: if rtcId pertains to a non-existent RTC.             */
/* - SM_ERR_DENIED: if the agent does not have permission to request RTC    */
/*   notifications.                                                         */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmRtcNotify(const scmi_caller_t *caller,
    const msg_rbbm10_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check RTC */
    if ((status == SM_ERR_SUCCESS) && (in->rtcId >= SM_NUM_RTC))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].rtcPerms[in->rtcId]
        < SM_SCMI_PERM_NOTIFY))
    {
        status = SM_ERR_DENIED;
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Record alarm notification */
        s_rtcInfo[in->rtcId].alarmNotify[caller->agentId]
            = (BBM_NOTIFY_RTC_ALARM(in->flags) != 0U);

        /* Record rollover notification */
        s_rtcInfo[in->rtcId].rolloverNotify[caller->agentId]
            = (BBM_NOTIFY_RTC_ROLLOVER(in->flags) != 0U);

        /* Record update notification */
        s_rtcInfo[in->rtcId].updateNotify[caller->agentId]
            = (BBM_NOTIFY_RTC_UPDATED(in->flags) != 0U);
    }

    /* Enable rollover interrupt if requested */
    if ((status == SM_ERR_SUCCESS)
        && (BBM_NOTIFY_RTC_ROLLOVER(in->flags) != 0U))
    {
        status = LMM_BbmRtcRollover(caller->lmId, in->rtcId);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure BBM button notifications                                       */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->flags: Notification flags:                                         */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Enable button:                                                  */
/*   Set to 1 to send notification.                                         */
/*   Set to 0 if no notification                                            */
/*                                                                          */
/* Process the BBM_BUTTON_NOTIFY message. Platform handler for              */
/* SCMI_BbmButtonNotify(). Requires access greater than or equal to         */
/* NOTIFY.                                                                  */
/*                                                                          */
/*  Access macros:                                                          */
/* - BBM_NOTIFY_BUTTON_DETECT() - Enable button notifications               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the notification configuration was successfully     */
/*   updated.                                                               */
/* - SM_ERR_DENIED: if the agent does not have permission to request        */
/*   button notifications.                                                  */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmButtonNotify(const scmi_caller_t *caller,
    const msg_rbbm11_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].buttonPerms[0U]
        < SM_SCMI_PERM_NOTIFY))
    {
        status = SM_ERR_DENIED;
    }

    /* Set notifications */
    if (status == SM_ERR_SUCCESS)
    {
        s_buttonNotify[caller->agentId]
            = (BBM_NOTIFY_BUTTON_DETECT(in->flags) != 0U);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get the state of an an RTC                                               */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->rtcId: Identifier of the RTC                                       */
/* - out->state: State of the RTC:                                          */
/*   Bits[31:2] Reserved, must be zero.                                     */
/*   Bit[1] Battery state:                                                  */
/*   Set to 1 if battery low.                                               */
/*   Set to 0 if battery good.                                              */
/*   Bit[0] Time state:                                                     */
/*   Set to 1 if RTC value reset.                                           */
/*   Set to 0 if RTC value retained                                         */
/*                                                                          */
/* Process the BBM_RTC_STATE message. Platform handler for                  */
/* SCMI_BbmRtcState().                                                      */
/*                                                                          */
/*  Access macros:                                                          */
/* - BBM_RTC_STATE_BATT_LOW() - Low battery                                 */
/* - BBM_RTC_STATE_RESET() - State lost and reset                           */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the alarm was successfully set.                     */
/* - SM_ERR_INVALID_PARAMETERS: if the time is not valid (beyond the        */
/*   range of the RTC alarm).                                               */
/* - SM_ERR_DENIED: if the agent does not have permission to set the RTC    */
/*   alarm.                                                                 */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmRtcState(const scmi_caller_t *caller,
    const msg_rbbm12_t *in, msg_tbbm12_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check RTC */
    if ((status == SM_ERR_SUCCESS) && (in->rtcId >= SM_NUM_RTC))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get state */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_BbmRtcStateGet(caller->lmId, in->rtcId, &out->state);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Negotiate the protocol version                                           */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->version: The negotiated protocol version the agent intends to use  */
/*                                                                          */
/* Process the NEGOTIATE_PROTOCOL_VERSION message. Platform handler for     */
/* SCMI_BbmNegotiateProtocolVersion().                                      */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the negotiated protocol version is supported by     */
/*   the platform. All commands, responses, and notifications post          */
/*   successful return of this command must comply with the negotiated      */
/*   version.                                                               */
/* - SM_ERR_NOT_SUPPORTED: if the protocol version is not supported.        */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BbmNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rbbm16_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check major version */
    if ((status == SM_ERR_SUCCESS) && (SCMI_VER_MAJOR(in->version)
        == SCMI_VER_MAJOR(PROTOCOL_VERSION)))
    {
        /* Check minor version */
        if (SCMI_VER_MINOR(in->version) > SCMI_VER_MINOR(PROTOCOL_VERSION))
        {
            status = SM_ERR_NOT_SUPPORTED;
        }
    }
    else
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Send bbm rtc event                                                       */
/*                                                                          */
/* Parameters:                                                              */
/* - msgId: Message ID to dispatch                                          */
/* - trigger: Trigger data                                                  */
/*--------------------------------------------------------------------------*/
static int32_t BbmRtcEvent(scmi_msg_id_t msgId,
    const lmm_rpc_trigger_t *trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all agents */
    for (uint32_t dstAgent = 0U; dstAgent < SM_SCMI_NUM_AGNT; dstAgent++)
    {
        /* Agent belong to instance? */
        if (g_scmiAgentConfig[dstAgent].scmiInst == trigger->rpcInst)
        {
            uint32_t rtcId = trigger->parm[0];
            uint32_t event = trigger->parm[1];
            msg_rbbm33_t out;

            if ((event == LMM_TRIGGER_PARM_RTC_ALARM)
                && (s_rtcInfo[rtcId].alarmNotify[dstAgent]))
            {
                /* Fill in data */
                out.flags
                    = BBM_EVENT_RTC_ALARM(1U)
                    | BBM_EVENT_RTC_ID(rtcId);

                /* Queue notification */
                RPC_SCMI_P2aTxQ(dstAgent, msgId, (uint32_t*) &out,
                    sizeof(out), SCMI_NOTIFY_Q);
            }
            if ((event == LMM_TRIGGER_PARM_RTC_ROLLOVER)
                && (s_rtcInfo[rtcId].rolloverNotify[dstAgent]))
            {
                /* Fill in data */
                out.flags
                    = BBM_EVENT_RTC_ROLLOVER(1U)
                    | BBM_EVENT_RTC_ID(rtcId);

                /* Queue notification */
                RPC_SCMI_P2aTxQ(dstAgent, msgId, (uint32_t*) &out,
                    sizeof(out), SCMI_NOTIFY_Q);
            }
            if ((event == LMM_TRIGGER_PARM_RTC_UPDATE)
                && (s_rtcInfo[rtcId].updateNotify[dstAgent]))
            {
                /* Fill in data */
                out.flags
                    = BBM_EVENT_RTC_UPDATED(1U)
                    | BBM_EVENT_RTC_ID(rtcId);

                /* Queue notification */
                RPC_SCMI_P2aTxQ(dstAgent, msgId, (uint32_t*) &out,
                    sizeof(out), SCMI_NOTIFY_Q);
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Send bbm button event                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - msgId: Message ID to dispatch                                          */
/* - trigger: Trigger data                                                  */
/*--------------------------------------------------------------------------*/
static int32_t BbmButtonEvent(scmi_msg_id_t msgId,
    const lmm_rpc_trigger_t *trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all agents */
    for (uint32_t dstAgent = 0U; dstAgent < SM_SCMI_NUM_AGNT; dstAgent++)
    {
        /* Agent belong to instance? */
        if ((g_scmiAgentConfig[dstAgent].scmiInst == trigger->rpcInst)
            && s_buttonNotify[dstAgent])
        {
            msg_rbbm33_t out;

            /* Fill in data */
            out.flags = BBM_EVENT_BUTTON_DETECTED(1U);

            /* Queue notification */
            RPC_SCMI_P2aTxQ(dstAgent, msgId, (uint32_t*) &out,
                sizeof(out), SCMI_NOTIFY_Q);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset agent configuration                                                */
/*                                                                          */
/* Parameters:                                                              */
/* - lmId: LM to reset                                                      */
/* - agentId: Message ID to dispatch                                        */
/* - permissionsReset: True to reset permissions                            */
/*--------------------------------------------------------------------------*/
static int32_t BbmResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Disable notifications */
    s_buttonNotify[agentId] = false;

    /* Loop over all RTC */
    for (uint32_t rtcId = 0U; rtcId < SM_NUM_RTC; rtcId++)
    {
        /* Disable notifications */
        s_rtcInfo[rtcId].rolloverNotify[agentId] = false;
        s_rtcInfo[rtcId].updateNotify[agentId] = false;

        if ((g_lmmConfig[lmId].autoBoot != LMM_AUTO_RTC)
            && (g_lmmConfig[lmId].autoBoot != LMM_AUTO_BOTH))
        {
            /* Disable notifications */
            s_rtcInfo[rtcId].alarmNotify[agentId] = false;

            /* Disable RTC alarm */
            if (s_rtcInfo[rtcId].alarmEnabled)
            {
                s_rtcInfo[rtcId].alarmEnabled = false;
                status = LMM_BbmRtcAlarmSet(lmId, rtcId, false, 0U);
            }
        }
    }

    /* Return status */
    return status;
}

