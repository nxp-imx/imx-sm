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
/* Interface (SCMI) misc protocol.                                          */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x10000U

/* SCMI misc protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION             0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES          0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES  0x2U
#define COMMAND_MISC_CONTROL_SET             0x3U
#define COMMAND_MISC_CONTROL_GET             0x4U
#define COMMAND_MISC_CONTROL_ACTION          0x5U
#define COMMAND_MISC_DISCOVER_BUILD_INFO     0x6U
#define COMMAND_MISC_ROM_PASSOVER_GET        0x7U
#define COMMAND_MISC_CONTROL_NOTIFY          0x8U
#define COMMAND_MISC_REASON_ATTRIBUTES       0x9U
#define COMMAND_MISC_RESET_REASON            0xAU
#define COMMAND_MISC_SI_INFO                 0xBU
#define COMMAND_NEGOTIATE_PROTOCOL_VERSION   0x10U
#define COMMAND_SUPPORTED_MASK               0x10FFFUL

/* SCMI max misc argument lengths */
#define MISC_MAX_BUILDDATE  16U
#define MISC_MAX_BUILDTIME  16U
#define MISC_MAX_NAME       16U
#define MISC_MAX_SINAME     16U
#define MISC_MAX_VAL_T      SCMI_ARRAY(8U, uint32_t)
#define MISC_MAX_VAL        SCMI_ARRAY(8U, uint32_t)
#define MISC_MAX_ARG_T      SCMI_ARRAY(12U, uint32_t)
#define MISC_MAX_RTN        SCMI_ARRAY(8U, uint32_t)
#define MISC_MAX_PASSOVER   SCMI_ARRAY(8U, uint32_t)
#define MISC_MAX_EXTINFO    SCMI_ARRAY(16U, uint32_t)

/* Local macros */

/* SCMI misc protocol attributes */
#define MISC_PROTO_ATTR_NUM_REASON(x)  (((x) & 0xFFU) << 16U)
#define MISC_PROTO_ATTR_NUM_CTRL(x)    (((x) & 0xFFFFU) << 0U)

/* SCMI reason flags */
#define MISC_REASON_FLAG_SYSTEM(x)  (((x) & 0x1U) >> 0U)

/* SCMI boot reason flags */
#define MISC_BOOT_FLAG_VLD(x)      (((x) & 0x1U) << 31U)
#define MISC_BOOT_FLAG_ORG_VLD(x)  (((x) & 0x1U) << 28U)
#define MISC_BOOT_FLAG_ORIGIN(x)   (((x) & 0xFU) << 24U)
#define MISC_BOOT_FLAG_ERR_VLD(x)  (((x) & 0x1U) << 23U)
#define MISC_BOOT_FLAG_ERR_ID(x)   (((x) & 0x7FFFU) << 8U)
#define MISC_BOOT_FLAG_REASON(x)   (((x) & 0xFFU) << 0U)

/* SCMI shutdown reason flags */
#define MISC_SHUTDOWN_FLAG_VLD(x)      (((x) & 0x1U) << 31U)
#define MISC_SHUTDOWN_FLAG_EXT_LEN(x)  (((x) & 0x3U) << 29U)
#define MISC_SHUTDOWN_FLAG_ORG_VLD(x)  (((x) & 0x1U) << 28U)
#define MISC_SHUTDOWN_FLAG_ORIGIN(x)   (((x) & 0xFU) << 24U)
#define MISC_SHUTDOWN_FLAG_ERR_VLD(x)  (((x) & 0x1U) << 23U)
#define MISC_SHUTDOWN_FLAG_ERR_ID(x)   (((x) & 0x7FFFU) << 8U)
#define MISC_SHUTDOWN_FLAG_REASON(x)   (((x) & 0xFFU) << 0U)

/* Local types */

/* Response type for ProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol version */
    uint32_t version;
} msg_tmisc0_t;

/* Response type for ProtocolAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol attributes */
    uint32_t attributes;
} msg_tmisc1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rmisc2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_tmisc2_t;

/* Request type for MiscControlSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the control */
    uint32_t ctrlId;
    /* Size of the value data */
    uint32_t numVal;
    /* Value data array */
    uint32_t val[MISC_MAX_VAL_T];
} msg_rmisc3_t;

/* Request type for MiscControlGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the control */
    uint32_t ctrlId;
} msg_rmisc4_t;

/* Response type for MiscControlGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Size of the return data in words */
    uint32_t numVal;
    /* Return data array */
    uint32_t val[MISC_MAX_VAL];
} msg_tmisc4_t;

/* Request type for MiscControlAction() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the control */
    uint32_t ctrlId;
    /* Action for the control */
    uint32_t action;
    /* Size of the argument data */
    uint32_t numArg;
    /* Argument data array */
    uint32_t arg[MISC_MAX_ARG_T];
} msg_rmisc5_t;

/* Response type for MiscControlAction() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Size of the return data in words */
    uint32_t numRtn;
    /* Return data array */
    uint32_t rtn[MISC_MAX_RTN];
} msg_tmisc5_t;

/* Response type for MiscDiscoverBuildInfo() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Build number */
    uint32_t buildNum;
    /* Most significant 32 bits of the git commit hash */
    uint32_t buildCommit;
    /* Date of build */
    uint8_t buildDate[MISC_MAX_BUILDDATE];
    /* Time of build */
    uint8_t buildTime[MISC_MAX_BUILDTIME];
} msg_tmisc6_t;

/* Response type for MiscRomPassoverGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Size of the passover data in words */
    uint32_t numPassover;
    /* Passover data array */
    uint32_t passover[MISC_MAX_PASSOVER];
} msg_tmisc7_t;

/* Request type for MiscControlNotify() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the control */
    uint32_t ctrlId;
    /* Notification flags, varies by control */
    uint32_t flags;
} msg_rmisc8_t;

/* Request type for MiscReasonAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the reason */
    uint32_t reasonId;
} msg_rmisc9_t;

/* Response type for MiscReasonAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Reason attributes */
    uint32_t attributes;
    /* ASCII name string */
    uint8_t name[MISC_MAX_NAME];
} msg_tmisc9_t;

/* Request type for MiscResetReason() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Reason flags */
    uint32_t flags;
} msg_rmisc10_t;

/* Response type for MiscResetReason() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Boot reason flags */
    uint32_t bootFlags;
    /* Shutdown reason flags */
    uint32_t shutdownFlags;
    /* Array of extended info words */
    uint32_t extInfo[MISC_MAX_EXTINFO];
} msg_tmisc10_t;

/* Response type for MiscSiInfo() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Silicon specific device ID */
    uint32_t deviceId;
    /* Silicon specific revision */
    uint32_t siRev;
    /* Silicon specific part number */
    uint32_t partNum;
    /* Silicon name/revision */
    uint8_t siName[MISC_MAX_SINAME];
} msg_tmisc11_t;

/* Request type for NegotiateProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* The negotiated protocol version the agent intends to use */
    uint32_t version;
} msg_rmisc16_t;

/* Request type for MiscControlEvent() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the control that caused the event */
    uint32_t ctrlId;
    /* Event flags, varies by control */
    uint32_t flags;
} msg_rmisc32_t;

/* Local functions */

static int32_t MiscProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tmisc0_t *out);
static int32_t MiscProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tmisc1_t *out);
static int32_t MiscProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rmisc2_t *in, msg_tmisc2_t *out);
static int32_t MiscControlSet(const scmi_caller_t *caller,
    const msg_rmisc3_t *in, const scmi_msg_status_t *out);
static int32_t MiscControlGet(const scmi_caller_t *caller,
    const msg_rmisc4_t *in, msg_tmisc4_t *out, uint32_t *len);
static int32_t MiscControlAction(const scmi_caller_t *caller,
    const msg_rmisc5_t *in, msg_tmisc5_t *out, uint32_t *len);
static int32_t MiscDiscoverBuildInfo(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tmisc6_t *out);
static int32_t MiscRomPassoverGet(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tmisc7_t *out, uint32_t *len);
static int32_t MiscControlNotify(const scmi_caller_t *caller,
    const msg_rmisc8_t *in, const scmi_msg_status_t *out);
static int32_t MiscReasonAttributes(const scmi_caller_t *caller,
    const msg_rmisc9_t *in, msg_tmisc9_t *out);
static int32_t MiscResetReason(const scmi_caller_t *caller,
    const msg_rmisc10_t *in, msg_tmisc10_t *out, uint32_t *len);
static int32_t MiscSiInfo(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tmisc11_t *out);
static int32_t MiscNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rmisc16_t *in, const scmi_msg_status_t *out);
static int32_t MiscControlEvent(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger);
static int32_t MiscResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_MiscDispatchCommand(scmi_caller_t *caller,
    uint32_t messageId)
{
    int32_t status = SM_ERR_SUCCESS;
    const scmi_msg_t *in = caller->msgCopy;
    scmi_msg_status_t *out = caller->msg;
    uint32_t lenOut = sizeof(scmi_msg_status_t);

    /* Handle standard messages */
    switch(messageId)
    {
        case COMMAND_PROTOCOL_VERSION:
            lenOut = sizeof(msg_tmisc0_t);
            status = MiscProtocolVersion(caller,
                (const scmi_msg_header_t*) in, (msg_tmisc0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tmisc1_t);
            status = MiscProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tmisc1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tmisc2_t);
            status = MiscProtocolMessageAttributes(caller,
                (const msg_rmisc2_t*) in, (msg_tmisc2_t*) out);
            break;
        case COMMAND_MISC_CONTROL_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = MiscControlSet(caller, (const msg_rmisc3_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_MISC_CONTROL_GET:
            lenOut = sizeof(msg_tmisc4_t);
            status = MiscControlGet(caller, (const msg_rmisc4_t*) in,
                (msg_tmisc4_t*) out, &lenOut);
            break;
        case COMMAND_MISC_CONTROL_ACTION:
            lenOut = sizeof(msg_tmisc5_t);
            status = MiscControlAction(caller, (const msg_rmisc5_t*) in,
                (msg_tmisc5_t*) out, &lenOut);
            break;
        case COMMAND_MISC_DISCOVER_BUILD_INFO:
            lenOut = sizeof(msg_tmisc6_t);
            status = MiscDiscoverBuildInfo(caller,
                (const scmi_msg_header_t*) in, (msg_tmisc6_t*) out);
            break;
        case COMMAND_MISC_ROM_PASSOVER_GET:
            lenOut = sizeof(msg_tmisc7_t);
            status = MiscRomPassoverGet(caller, (const scmi_msg_header_t*) in,
                (msg_tmisc7_t*) out, &lenOut);
            break;
        case COMMAND_MISC_CONTROL_NOTIFY:
            lenOut = sizeof(const scmi_msg_status_t);
            status = MiscControlNotify(caller, (const msg_rmisc8_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_MISC_REASON_ATTRIBUTES:
            lenOut = sizeof(msg_tmisc9_t);
            status = MiscReasonAttributes(caller, (const msg_rmisc9_t*) in,
                (msg_tmisc9_t*) out);
            break;
        case COMMAND_MISC_RESET_REASON:
            lenOut = sizeof(msg_tmisc10_t);
            status = MiscResetReason(caller, (const msg_rmisc10_t*) in,
                (msg_tmisc10_t*) out, &lenOut);
            break;
        case COMMAND_MISC_SI_INFO:
            lenOut = sizeof(msg_tmisc11_t);
            status = MiscSiInfo(caller, (const scmi_msg_header_t*) in,
                (msg_tmisc11_t*) out);
            break;
        case COMMAND_NEGOTIATE_PROTOCOL_VERSION:
            lenOut = sizeof(const scmi_msg_status_t);
            status = MiscNegotiateProtocolVersion(caller,
                (const msg_rmisc16_t*) in, (const scmi_msg_status_t*) out);
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
int32_t RPC_SCMI_MiscDispatchNotification(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Handle notifications */
    switch(msgId.messageId)
    {
        case RPC_SCMI_NOTIFY_MISC_CONTROL_EVENT:
            status = MiscControlEvent(msgId, trigger);
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
int32_t RPC_SCMI_MiscDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return MiscResetAgentConfig(lmId, agentId, permissionsReset);
}

/*==========================================================================*/
/* Custom Protocol Implementation                                           */
/*==========================================================================*/

/* Local variables */

static uint32_t s_ctrlNotify[SM_NUM_CTRL][SM_SCMI_NUM_AGNT];

/* Local functions */

static int32_t MiscControlUpdate(uint32_t lmId, uint32_t agentId,
    uint32_t ctrlId, uint32_t flags);

/*--------------------------------------------------------------------------*/
/* Get protocol version                                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->version: Protocol version. For this revision of the               */
/*   specification, this value must be 0x10000                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_MiscProtocolVersion().                                              */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tmisc0_t *out)
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
/*   Bits[31:24] Reserved, must be zero.                                    */
/*   Bits[23:16] Number of reasons.                                         */
/*   Bits[15:0] Number of controls                                          */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_MiscProtocolAttributes().                                           */
/*                                                                          */
/*  Access macros:                                                          */
/* - MISC_PROTO_ATTR_NUM_REASON() - Number of reasons                       */
/* - MISC_PROTO_ATTR_NUM_CTRL() - Number of controls                        */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tmisc1_t *out)
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
        /* Return number of controls */
        out->attributes
            = MISC_PROTO_ATTR_NUM_REASON(SM_NUM_REASON)
            | MISC_PROTO_ATTR_NUM_CTRL(SM_NUM_CTRL);
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
/*   In the current version of the specification, this value is always 0    */
/*                                                                          */
/* Process the PROTOCOL_MESSAGE_ATTRIBUTES message. Platform handler for    */
/* SCMI_MiscProtocolMessageAttributes().                                    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is invalid    */
/*   or not implemented.                                                    */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rmisc2_t *in, msg_tmisc2_t *out)
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
/* Set a control value                                                      */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->ctrlId: Identifier for the control                                 */
/* - in->numVal: Size of the value data                                     */
/* - in->val: Value data array                                              */
/*                                                                          */
/* Process the MISC_CONTROL_SET message. Platform handler for               */
/* SCMI_MiscControlSet(). Requires access greater than or equal to          */
/* EXCLUSIVE.                                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the control is set successfully.                    */
/* - SM_ERR_NOT_FOUND: if ctrlId does not point to a valid control.         */
/* - SM_ERR_DENIED: if the calling agent is not allowed to set this         */
/*   control.                                                               */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscControlSet(const scmi_caller_t *caller,
    const msg_rmisc3_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < ((3U + in->numVal) * sizeof(uint32_t)))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check control */
    if ((status == SM_ERR_SUCCESS) && (in->ctrlId >= SM_NUM_CTRL))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].ctrlPerms[in->ctrlId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Set control */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_MiscControlSet(caller->lmId, in->ctrlId, in->numVal,
            in->val);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get a control value                                                      */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->ctrlId: Identifier for the control                                 */
/* - out->numVal: Size of the return data in words                          */
/* - out->val: Return data array                                            */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the MISC_CONTROL_GET message. Platform handler for               */
/* SCMI_MiscControlGet(). Requires access greater than or equal to GET.     */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the control is returned successfully.               */
/* - SM_ERR_NOT_FOUND: if ctrlId does not point to a valid control.         */
/* - SM_ERR_DENIED: if the calling agent is not allowed to get this         */
/*   control.                                                               */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscControlGet(const scmi_caller_t *caller,
    const msg_rmisc4_t *in, msg_tmisc4_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check control */
    if ((status == SM_ERR_SUCCESS) && (in->ctrlId >= SM_NUM_CTRL))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].ctrlPerms[in->ctrlId]
        < SM_SCMI_PERM_GET))
    {
        status = SM_ERR_DENIED;
    }

    /* Get control */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_MiscControlGet(caller->lmId, in->ctrlId, &(out->numVal),
            out->val);
    }

    /* Update length */
    if (status == SM_ERR_SUCCESS)
    {
        *len = (3U + out->numVal) * sizeof(uint32_t);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Initiate an action on a control value                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->ctrlId: Identifier for the control                                 */
/* - in->action: Action for the control                                     */
/* - in->numArg: Size of the argument data                                  */
/* - in->arg: Argument data array                                           */
/* - out->numRtn: Size of the return data in words                          */
/* - out->rtn: Return data array                                            */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the MISC_CONTROL_ACTION message. Platform handler for            */
/* SCMI_MiscControlAction(). Requires access greater than or equal to       */
/* EXCLUSIVE.                                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the action is successfully.                         */
/* - SM_ERR_NOT_FOUND: if ctrlId does not point to a valid control.         */
/* - SM_ERR_DENIED: if the calling agent is not allowed to initiate the     */
/*   action on this control.                                                */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscControlAction(const scmi_caller_t *caller,
    const msg_rmisc5_t *in, msg_tmisc5_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < ((4U + in->numArg) * sizeof(uint32_t)))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check control */
    if ((status == SM_ERR_SUCCESS) && (in->ctrlId >= SM_NUM_CTRL))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].ctrlPerms[in->ctrlId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Get control */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_MiscControlAction(caller->lmId, in->ctrlId, in->action,
            in->numArg, in->arg, &(out->numRtn), out->rtn);
    }

    /* Update length */
    if (status == SM_ERR_SUCCESS)
    {
        *len = (3U + out->numRtn) * sizeof(uint32_t);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get implementation build info                                            */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->buildNum: Build number                                            */
/* - out->buildCommit: Most significant 32 bits of the git commit hash      */
/* - out->buildDate: Date of build. Null terminated ASCII string of up to   */
/*   16 bytes in length                                                     */
/* - out->buildTime: Time of build. Null terminated ASCII string of up to   */
/*   16 bytes in length                                                     */
/*                                                                          */
/* Process the MISC_DISCOVER_BUILD_INFO message. Platform handler for       */
/* SCMI_MiscDiscoverBuildInfo().                                            */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the build info is returned.                    */
/* - SM_ERR_NOT_SUPPORTED: if the data is not available.                    */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscDiscoverBuildInfo(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tmisc6_t *out)
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
        /* Copy out build number and commit */
        out->buildNum = SM_BUILD;
        out->buildCommit = SM_COMMIT;

        /* Copy out build date */
        RPC_SCMI_StrCpy(out->buildDate, ((uint8_t const *) SM_DATE),
            MISC_MAX_BUILDDATE);

        /* Copy out build time */
        RPC_SCMI_StrCpy(out->buildTime, ((uint8_t const *) SM_TIME),
            MISC_MAX_BUILDTIME);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get ROM passover data                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->numPassover: Size of the passover data in words                   */
/* - out->passover: Passover data array                                     */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the MISC_ROM_PASSOVER_GET message. Platform handler for          */
/* SCMI_MiscRomPassoverGet().                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the ROM passover data is returned.             */
/* - SM_ERR_NOT_SUPPORTED: if the data is not available.                    */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscRomPassoverGet(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tmisc7_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t numPassover = sizeof(rom_passover_t) / sizeof(uint32_t);
    const rom_passover_t *passover;

    /* Check passover size */
    COMPILE_ASSERT((sizeof(rom_passover_t) / sizeof(uint32_t))
        <= MISC_MAX_PASSOVER);

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Get info */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_MiscRomPassoverGet(caller->lmId, &passover);
    }

    /* Return data */
    if (status == SM_ERR_SUCCESS)
    {
        /* Update num passover */
        out->numPassover = numPassover;

        /* Copy data */
        memcpy((void*) out->passover, (const void*) passover,
            out->numPassover * sizeof(uint32_t));

        /* Update length */
        *len = (3U + out->numPassover) * sizeof(uint32_t);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure control notifications                                          */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->ctrlId: Identifier for the control                                 */
/* - in->flags: Notification flags, varies by control                       */
/*                                                                          */
/* Process the MISC_CONTROL_NOTIFY message. Platform handler for            */
/* SCMI_MiscControlNotify(). Requires access greater than or equal to       */
/* NOTIFY.                                                                  */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the notification successfully updated.              */
/* - SM_ERR_NOT_FOUND: if the LM identified by ctrlId does not exist.       */
/* - SM_ERR_INVALID_PARAMETERS, if the input attributes flag specifies      */
/*   unsupported or invalid configurations.                                 */
/* - SM_ERR_DENIED: if the calling agent is not permitted to request the    */
/*   notification.                                                          */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscControlNotify(const scmi_caller_t *caller,
    const msg_rmisc8_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check control */
    if ((status == SM_ERR_SUCCESS) && (in->ctrlId >= SM_NUM_CTRL))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].ctrlPerms[in->ctrlId]
        < SM_SCMI_PERM_NOTIFY))
    {
        status = SM_ERR_DENIED;
    }

    /* Update notification flags */
    if (status == SM_ERR_SUCCESS)
    {
        status = MiscControlUpdate(caller->lmId, caller->agentId,
            in->ctrlId, in->flags);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get (reset) reason attributes                                            */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->reasonId: Identifier for the reason                                */
/* - out->attributes: Reason attributes. This parameter has the following   */
/*   format:                                                                */
/*   Bits[31:0] Reserved, must be zero                                      */
/* - out->name: Null-terminated ASCII string of up to 16 bytes in length    */
/*   describing the reason                                                  */
/*                                                                          */
/* Process the MISC_REASON_ATTRIBUTES message. Platform handler for         */
/* SCMI_MiscReasonAttributes().                                             */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid reason attributes are returned.               */
/* - SM_ERR_NOT_FOUND: if reasonId pertains to a non-existent reason.       */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscReasonAttributes(const scmi_caller_t *caller,
    const msg_rmisc9_t *in, msg_tmisc9_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    const uint8_t *nameAddr = (const uint8_t*) "";

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check reason */
    if ((status == SM_ERR_SUCCESS) && (in->reasonId >= SM_NUM_REASON))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get the reason name */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_SystemReasonNameGet(caller->lmId, in->reasonId,
            (string*) &nameAddr, NULL);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        /* Always zero */
        out->attributes = 0U;

        /* Copy out name */
        RPC_SCMI_StrCpy(out->name, nameAddr, MISC_MAX_NAME);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Read the reason the LM/system last booted/shutdown/reset                 */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->flags: Reason flags. This parameter has the following format:      */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] System:                                                         */
/*   Set to 1 to return the system reason.                                  */
/*   Set to 0 to return the LM reason                                       */
/* - out->bootFlags: Boot reason flags. This parameter has the following    */
/*   format:                                                                */
/*   Bits[31] Valid.                                                        */
/*   Set to 1 if the entire reason is valid.                                */
/*   Set to 0 if the entire reason is not valid.                            */
/*   Bits[30:29] Reserved, must be zero.                                    */
/*   Bit[28] Valid origin:                                                  */
/*   Set to 1 if the origin field is valid.                                 */
/*   Set to 0 if the origin field is not valid.                             */
/*   Bits[27:24] Origin.                                                    */
/*   Bit[23] Valid err ID:                                                  */
/*   Set to 1 if the error ID field is valid.                               */
/*   Set to 0 if the error ID field is not valid.                           */
/*   Bits[22:8] Error ID.                                                   */
/*   Bit[7:0] Reason                                                        */
/* - out->shutdownFlags: Shutdown reason flags. This parameter has the      */
/*   following format:                                                      */
/*   Bits[31] Valid.                                                        */
/*   Set to 1 if the entire reason is valid.                                */
/*   Set to 0 if the entire reason is not valid.                            */
/*   Bits[30:29] Number of valid extended info words.                       */
/*   Bit[28] Valid origin:                                                  */
/*   Set to 1 if the origin field is valid.                                 */
/*   Set to 0 if the origin field is not valid.                             */
/*   Bits[27:24] Origin.                                                    */
/*   Bit[23] Valid err ID:                                                  */
/*   Set to 1 if the error ID field is valid.                               */
/*   Set to 0 if the error ID field is not valid.                           */
/*   Bits[22:8] Error ID.                                                   */
/*   Bit[7:0] Reason                                                        */
/* - out->extInfo: Array of extended info words                             */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the MISC_RESET_REASON message. Platform handler for              */
/* SCMI_MiscResetReason().                                                  */
/*                                                                          */
/*  Access macros:                                                          */
/* - MISC_REASON_FLAG_SYSTEM() - System                                     */
/* - MISC_BOOT_FLAG_VLD() - Valid                                           */
/* - MISC_BOOT_FLAG_ORG_VLD() - Valid origin                                */
/* - MISC_BOOT_FLAG_ORIGIN() - LM source of action                          */
/* - MISC_BOOT_FLAG_ERR_VLD() - Valid error ID                              */
/* - MISC_BOOT_FLAG_ERR_ID() - Error ID                                     */
/* - MISC_BOOT_FLAG_REASON() - Reason                                       */
/* - MISC_SHUTDOWN_FLAG_VLD() - Valid                                       */
/* - MISC_SHUTDOWN_FLAG_EXT_LEN() - Number of valid extended info words     */
/* - MISC_SHUTDOWN_FLAG_ORG_VLD() - Valid origin                            */
/* - MISC_SHUTDOWN_FLAG_ORIGIN() - LM source of action                      */
/* - MISC_SHUTDOWN_FLAG_ERR_VLD() - Valid error ID                          */
/* - MISC_SHUTDOWN_FLAG_ERR_ID() - Error ID                                 */
/* - MISC_SHUTDOWN_FLAG_REASON() - Reason                                   */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscResetReason(const scmi_caller_t *caller,
    const msg_rmisc10_t *in, msg_tmisc10_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    lmm_rst_rec_t bootRec;
    lmm_rst_rec_t shutdownRec;
    bool sys = MISC_REASON_FLAG_SYSTEM(in->flags) != 0U;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Get reset reason */
    if (status == SM_ERR_SUCCESS)
    {
        if (sys)
        {
            /* Get reset info */
            LM_SystemReason(caller->lmId, &bootRec,
                &shutdownRec);
        }
        else
        {
            /* Get LM reset info */
            status = LM_SystemLmReason(caller->lmId, caller->lmId,
                &bootRec, &shutdownRec);
        }
    }

    /* Fill in return data */
    if (status == SM_ERR_SUCCESS)
    {
        /* Update record size */
        uint32_t extLen = MIN(shutdownRec.extLen, MISC_MAX_EXTINFO);
        extLen = MIN(extLen, DEV_SM_NUM_EXT_INFO);

        /* Fill in boot info */
        out->bootFlags
            = MISC_BOOT_FLAG_VLD(bootRec.valid ? 1UL : 0UL)
            | MISC_BOOT_FLAG_ORG_VLD(bootRec.validOrigin ? 1UL : 0UL)
            | MISC_BOOT_FLAG_ORIGIN(bootRec.origin)
            | MISC_BOOT_FLAG_ERR_VLD(bootRec.validErr ? 1UL : 0UL)
            | MISC_BOOT_FLAG_ERR_ID(bootRec.errId)
            | MISC_BOOT_FLAG_REASON(bootRec.reason);

        /* Fill in shutdown info */
        out->shutdownFlags
            = MISC_SHUTDOWN_FLAG_VLD(shutdownRec.valid ? 1UL : 0UL)
            | MISC_SHUTDOWN_FLAG_EXT_LEN(extLen)
            | MISC_SHUTDOWN_FLAG_ORG_VLD(shutdownRec.validOrigin ? 1UL : 0UL)
            | MISC_SHUTDOWN_FLAG_ORIGIN(shutdownRec.origin)
            | MISC_SHUTDOWN_FLAG_ERR_VLD(shutdownRec.validErr ? 1UL : 0UL)
            | MISC_SHUTDOWN_FLAG_ERR_ID(shutdownRec.errId)
            | MISC_SHUTDOWN_FLAG_REASON(shutdownRec.reason);

        /* Copy extended words */
        for (uint32_t idx = 0U; idx < extLen; idx++)
        {
            out->extInfo[idx] = shutdownRec.extInfo[idx];
        }

        /* Update length */
        *len = (4U + extLen) * sizeof(uint32_t);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get silicon info                                                         */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->deviceId: Silicon specific device ID                              */
/* - out->siRev: Silicon specific revision                                  */
/* - out->partNum: Silicon specific part number                             */
/* - out->siName: Silicon name/revision. Null terminated ASCII string of    */
/*   up to 16 bytes in length                                               */
/*                                                                          */
/* Process the MISC_SI_INFO message. Platform handler for                   */
/* SCMI_MiscSiInfo().                                                       */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscSiInfo(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tmisc11_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    const uint8_t *nameAddr = (const uint8_t*) "";
    uint32_t deviceId;
    uint32_t siRev;
    uint32_t partNum;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Get the silicon info */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_SIINFOGET(&deviceId, &siRev, &partNum,
            (string*) &nameAddr);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        /* Return data */
        out->deviceId = deviceId;
        out->siRev = siRev;
        out->partNum = partNum;

        /* Copy out name */
        RPC_SCMI_StrCpy(out->siName, nameAddr, MISC_MAX_SINAME);
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
/* SCMI_MiscNegotiateProtocolVersion().                                     */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the negotiated protocol version is supported by     */
/*   the platform. All commands, responses, and notifications post          */
/*   successful return of this command must comply with the negotiated      */
/*   version.                                                               */
/* - SM_ERR_NOT_SUPPORTED: if the protocol version is not supported.        */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t MiscNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rmisc16_t *in, const scmi_msg_status_t *out)
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
/* Send misc control event                                                  */
/*                                                                          */
/* Parameters:                                                              */
/* - msgId: Message ID to dispatch                                          */
/* - trigger: Trigger data                                                  */
/*--------------------------------------------------------------------------*/
static int32_t MiscControlEvent(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all agents */
    for (uint32_t dstAgent = 0U; dstAgent < SM_SCMI_NUM_AGNT; dstAgent++)
    {
        uint32_t ctrlId = trigger.parm[0];
        uint32_t flags = trigger.parm[1];

        /* Agent belong to instance? */
        if ((g_scmiAgentConfig[dstAgent].scmiInst == trigger.rpcInst)
            && ((s_ctrlNotify[ctrlId][dstAgent] & flags) != 0U))
        {
            msg_rmisc32_t out;

            /* Fill in data */
            out.ctrlId = ctrlId;
            out.flags = flags;

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
static int32_t MiscResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all controls */
    for (uint32_t ctrlId = 0U; ctrlId < SM_NUM_CTRL; ctrlId++)
    {
        (void) MiscControlUpdate(lmId, agentId, ctrlId, 0U);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Aggregate and update a control notification                              */
/*                                                                          */
/* Parameters:                                                              */
/* - lmId: LM to update                                                     */
/* - agentId: Message to update                                             */
/* - ctrlId: control                                                        */
/* - flags: Notification enable flags                                       */
/*--------------------------------------------------------------------------*/
static int32_t MiscControlUpdate(uint32_t lmId, uint32_t agentId,
    uint32_t ctrlId, uint32_t flags)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check control */
    if (ctrlId >= SM_NUM_CTRL)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }
    else
    {
        uint32_t scmiInst = g_scmiAgentConfig[agentId].scmiInst;
        uint32_t firstAgent = g_scmiConfig[scmiInst].firstAgent;
        uint32_t numAgents = g_scmiConfig[scmiInst].numAgents;

        uint32_t newFlags = 0U;

        /* Record agent flags for this control */
        s_ctrlNotify[ctrlId][agentId] =flags;

        /* Calculate new aggregate state for the flags */
        for (uint32_t a = firstAgent; a < (firstAgent + numAgents); a++)
        {
            newFlags |= s_ctrlNotify[ctrlId][a];
        }

        /* Inform LMM of flags, LMM will check if changed */
        status = LMM_MiscControlFlagsSet(lmId, ctrlId, newFlags);
    }

    /* Return status */
    return status;
}

