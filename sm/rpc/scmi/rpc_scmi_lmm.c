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
/* File containing the implementation of the System Control and Management  */
/* Interface (SCMI) lmm protocol.                                           */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x10000U

/* SCMI lmm protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION             0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES          0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES  0x2U
#define COMMAND_LMM_ATTRIBUTES               0x3U
#define COMMAND_LMM_BOOT                     0x4U
#define COMMAND_LMM_RESET                    0x5U
#define COMMAND_LMM_SHUTDOWN                 0x6U
#define COMMAND_LMM_WAKE                     0x7U
#define COMMAND_LMM_SUSPEND                  0x8U
#define COMMAND_LMM_NOTIFY                   0x9U
#define COMMAND_LMM_RESET_REASON             0xAU
#define COMMAND_SUPPORTED_MASK               0x7FFUL

/* SCMI LMM max argument lengths */
#define LMM_MAX_NAME     16U
#define LMM_MAX_EXTINFO  SCMI_ARRAY(16U, uint32_t)

/* SCMI LM ID */
#define LMM_ID_DISCOVER  0xFFFFFFFFU

/* SCMI LM State */
#define LMM_STATE_OFF      0U
#define LMM_STATE_ON       1U
#define LMM_STATE_SUSPEND  2U

/* Local macros */

/* SCMI LMM protocol attributes */
#define LMM_PROTO_ATTR_NUM_LM(x)  (((x) & 0xFFU) << 0U)

/* SCMI LM request flags */
#define LMM_FLAGS_GRACEFUL(x)  (((x) & 0x1U) >> 0U)

/* SCMI boot reason flags */
#define LMM_BOOT_FLAG_VLD(x)      (((x) & 0x1U) << 31U)
#define LMM_BOOT_FLAG_ORG_VLD(x)  (((x) & 0x1U) << 28U)
#define LMM_BOOT_FLAG_ORIGIN(x)   (((x) & 0xFU) << 24U)
#define LMM_BOOT_FLAG_ERR_VLD(x)  (((x) & 0x1U) << 23U)
#define LMM_BOOT_FLAG_ERR_ID(x)   (((x) & 0x7FFFU) << 8U)
#define LMM_BOOT_FLAG_REASON(x)   (((x) & 0xFFU) << 0U)

/* SCMI shutdown reason flags */
#define LMM_SHUTDOWN_FLAG_VLD(x)      (((x) & 0x1U) << 31U)
#define LMM_SHUTDOWN_FLAG_EXT_LEN(x)  (((x) & 0x3U) << 29U)
#define LMM_SHUTDOWN_FLAG_ORG_VLD(x)  (((x) & 0x1U) << 28U)
#define LMM_SHUTDOWN_FLAG_ORIGIN(x)   (((x) & 0xFU) << 24U)
#define LMM_SHUTDOWN_FLAG_ERR_VLD(x)  (((x) & 0x1U) << 23U)
#define LMM_SHUTDOWN_FLAG_ERR_ID(x)   (((x) & 0x7FFFU) << 8U)
#define LMM_SHUTDOWN_FLAG_REASON(x)   (((x) & 0xFFU) << 0U)

/* SCMI LMM notification flags */
#define LMM_NOTIFY_BOOT(x)      (((x) & 0x1U) >> 0U)
#define LMM_NOTIFY_SHUTDOWN(x)  (((x) & 0x2U) >> 1U)
#define LMM_NOTIFY_SUSPEND(x)   (((x) & 0x4U) >> 2U)
#define LMM_NOTIFY_WAKE(x)      (((x) & 0x8U) >> 3U)

/* SCMI LM event flags */
#define LMM_EVENT_BOOT(x)      (((x) & 0x1U) << 0U)
#define LMM_EVENT_SHUTDOWN(x)  (((x) & 0x1U) << 1U)
#define LMM_EVENT_SUSPEND(x)   (((x) & 0x1U) << 2U)
#define LMM_EVENT_WAKE(x)      (((x) & 0x1U) << 3U)

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
} msg_tlmm0_t;

/* Response type for ProtocolAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol attributes */
    uint32_t attributes;
} msg_tlmm1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rlmm2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_tlmm2_t;

/* Request type for LmmAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the logical machine */
    uint32_t lmId;
} msg_rlmm3_t;

/* Response type for LmmAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Return LM */
    uint32_t lmId;
    /* LM attributes */
    uint32_t attributes;
    /* Current state of the LM */
    uint32_t state;
    /* Last error status recorded */
    int32_t errStatus;
    /* ASCII name string */
    uint8_t name[LMM_MAX_NAME];
} msg_tlmm3_t;

/* Request type for LmmBoot() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the logical machine */
    uint32_t lmId;
} msg_rlmm4_t;

/* Request type for LmmReset() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the logical machine */
    uint32_t lmId;
    /* Reset flags */
    uint32_t flags;
} msg_rlmm5_t;

/* Request type for LmmShutdown() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the logical machine */
    uint32_t lmId;
    /* Shutdown flags */
    uint32_t flags;
} msg_rlmm6_t;

/* Request type for LmmWake() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the logical machine */
    uint32_t lmId;
} msg_rlmm7_t;

/* Request type for LmmSuspend() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the logical machine */
    uint32_t lmId;
} msg_rlmm8_t;

/* Request type for LmmNotify() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the logical machine */
    uint32_t lmId;
    /* Notification flags */
    uint32_t flags;
} msg_rlmm9_t;

/* Request type for LmmResetReason() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the logical machine */
    uint32_t lmId;
} msg_rlmm10_t;

/* Response type for LmmResetReason() */
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
    uint32_t extInfo[LMM_MAX_EXTINFO];
} msg_tlmm10_t;

/* Request type for LmmEvent() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the LM that caused the transition */
    uint32_t lmId;
    /* Identifier for the LM the event is for */
    uint32_t eventLm;
    /* LM events */
    uint32_t flags;
} msg_rlmm32_t;

/* Local functions */

static int32_t LmmProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tlmm0_t *out);
static int32_t LmmProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tlmm1_t *out);
static int32_t LmmProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rlmm2_t *in, msg_tlmm2_t *out);
static int32_t LmmAttributes(const scmi_caller_t *caller,
    const msg_rlmm3_t *in, msg_tlmm3_t *out);
static int32_t LmmBoot(const scmi_caller_t *caller, const msg_rlmm4_t *in,
    const scmi_msg_status_t *out);
static int32_t LmmReset(const scmi_caller_t *caller, const msg_rlmm5_t *in,
    const scmi_msg_status_t *out);
static int32_t LmmShutdown(const scmi_caller_t *caller, const msg_rlmm6_t *in,
    const scmi_msg_status_t *out);
static int32_t LmmWake(const scmi_caller_t *caller, const msg_rlmm7_t *in,
    const scmi_msg_status_t *out);
static int32_t LmmSuspend(const scmi_caller_t *caller, const msg_rlmm8_t *in,
    const scmi_msg_status_t *out);
static int32_t LmmNotify(const scmi_caller_t *caller, const msg_rlmm9_t *in,
    const scmi_msg_status_t *out);
static int32_t LmmResetReason(const scmi_caller_t *caller,
    const msg_rlmm10_t *in, msg_tlmm10_t *out, uint32_t *len);
static int32_t LmmEvent(scmi_msg_id_t msgId, lmm_rpc_trigger_t trigger);
static int32_t LmmResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_LmmDispatchCommand(scmi_caller_t *caller,
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
            lenOut = sizeof(msg_tlmm0_t);
            status = LmmProtocolVersion(caller, (const scmi_msg_header_t*) in,
                (msg_tlmm0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tlmm1_t);
            status = LmmProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tlmm1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tlmm2_t);
            status = LmmProtocolMessageAttributes(caller,
                (const msg_rlmm2_t*) in, (msg_tlmm2_t*) out);
            break;
        case COMMAND_LMM_ATTRIBUTES:
            lenOut = sizeof(msg_tlmm3_t);
            status = LmmAttributes(caller, (const msg_rlmm3_t*) in,
                (msg_tlmm3_t*) out);
            break;
        case COMMAND_LMM_BOOT:
            lenOut = sizeof(const scmi_msg_status_t);
            status = LmmBoot(caller, (const msg_rlmm4_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_LMM_RESET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = LmmReset(caller, (const msg_rlmm5_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_LMM_SHUTDOWN:
            lenOut = sizeof(const scmi_msg_status_t);
            status = LmmShutdown(caller, (const msg_rlmm6_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_LMM_WAKE:
            lenOut = sizeof(const scmi_msg_status_t);
            status = LmmWake(caller, (const msg_rlmm7_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_LMM_SUSPEND:
            lenOut = sizeof(const scmi_msg_status_t);
            status = LmmSuspend(caller, (const msg_rlmm8_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_LMM_NOTIFY:
            lenOut = sizeof(const scmi_msg_status_t);
            status = LmmNotify(caller, (const msg_rlmm9_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_LMM_RESET_REASON:
            lenOut = sizeof(msg_tlmm10_t);
            status = LmmResetReason(caller, (const msg_rlmm10_t*) in,
                (msg_tlmm10_t*) out, &lenOut);
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
int32_t RPC_SCMI_LmmDispatchNotification(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Handle notifications */
    switch(msgId.messageId)
    {
        case RPC_SCMI_NOTIFY_LMM_EVENT:
            status = LmmEvent(msgId, trigger);
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
int32_t RPC_SCMI_LmmDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return LmmResetAgentConfig(lmId, agentId, permissionsReset);
}

/*==========================================================================*/
/* Custom Protocol Implementation                                           */
/*==========================================================================*/

/* Local variables */

static uint8_t s_lmmNotify[SM_NUM_LM][SM_SCMI_NUM_AGNT];

/*--------------------------------------------------------------------------*/
/* Get protocol version                                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->version: Protocol version. For this revision of the               */
/*   specification, this value must be 0x10000                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_LmmProtocolVersion().                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t LmmProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tlmm0_t *out)
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
/*   Bits[31:8] Reserved, must be zero.                                     */
/*   Bits[7:0] Number of logical machines                                   */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_LmmProtocolAttributes().                                            */
/*                                                                          */
/*  Access macros:                                                          */
/* - LMM_PROTO_ATTR_NUM_LM() - Number of logical machines                   */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t LmmProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tlmm1_t *out)
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
        /* Return number of LMs */
        out->attributes = LMM_PROTO_ATTR_NUM_LM(SM_NUM_LM);
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
/* SCMI_LmmProtocolMessageAttributes().                                     */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is invalid    */
/*   or not provided by this platform implementation.                       */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t LmmProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rlmm2_t *in, msg_tlmm2_t *out)
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
/* Get logical machine attributes                                           */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->lmId: Identifier for the logical machine. 0xFFFFFFFF for self.     */
/*   Will be updated with actual LM ID                                      */
/* - out->lmId: Return LM. Identifier of the LM whose identification is     */
/*   requested. This field is:                                              */
/*   - Populated with the lmId of the calling agent, when the lmId          */
/*   parameter passed via the function is 0xFFFFFFFF.                       */
/*   - Identical to the lmId field passed via the calling parameters, in    */
/*   all other cases                                                        */
/* - out->attributes: LM attributes:                                        */
/*   Bits[31:0] Reserved, must be zero                                      */
/* - out->state: Current state of the LM                                    */
/* - out->errStatus: Last error status recorded                             */
/* - out->name: A NULL terminated ASCII string with the LM name, of up to   */
/*   16 bytes                                                               */
/*                                                                          */
/* Process the LMM_ATTRIBUTES message. Platform handler for                 */
/* SCMI_LmmAttributes(). Requires access greater than or equal to           */
/* NONE/GET.                                                                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid attributes are returned.                      */
/* - SM_ERR_NOT_FOUND: if lmId does not point to a valid logical            */
/*   machine.                                                               */
/* - SM_ERR_DENIED: if the calling agent is not allowed to get info for     */
/*   the LM specified by lmId.                                              */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t LmmAttributes(const scmi_caller_t *caller,
    const msg_rlmm3_t *in, msg_tlmm3_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    const uint8_t *nameAddr = (const uint8_t*) "";

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Self discovery */
    if (status == SM_ERR_SUCCESS)
    {
        if (in->lmId != LMM_ID_DISCOVER)
        {
            out->lmId = in->lmId;
        }
        else
        {
            out->lmId = caller->lmId;
        }
    }

    /* Check LM */
    if ((status == SM_ERR_SUCCESS) && (out->lmId >= SM_NUM_LM))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS) && (caller->lmId != out->lmId)
        && (g_scmiAgentConfig[caller->agentId].lmmPerms[in->lmId]
        < SM_SCMI_PERM_GET))
    {
        status = SM_ERR_DENIED;
    }

    /* Get LM status */
    if (status == SM_ERR_SUCCESS)
    {
        status = LM_SystemLmStatus(caller->lmId, out->lmId, &(out->state),
            &(out->errStatus));
    }

    /* Get the LM name */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_LmNameGet(out->lmId, out->lmId, (string*) &nameAddr,
            NULL);
    }

    /* Return data */
    if (status == SM_ERR_SUCCESS)
    {
        /* Clear attributes */
        out->attributes = 0U;

        /* Copy out name */
        RPC_SCMI_StrCpy(out->name, nameAddr, LMM_MAX_NAME);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Boot (power on) an LM                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->lmId: Identifier for the logical machine                           */
/*                                                                          */
/* Process the LMM_BOOT message. Platform handler for SCMI_LmmBoot().       */
/* Requires access greater than or equal to PRIV.                           */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the LM successfully booted.                         */
/* - SM_ERR_NOT_FOUND: if the LM identified by lmId does not exist.         */
/* - SM_ERR_INVALID_PARAMETERS, if lmId is the same as the caller.          */
/* - SM_ERR_DENIED: if the calling agent is not allowed to manage the LM    */
/*   specified by lmId.                                                     */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t LmmBoot(const scmi_caller_t *caller, const msg_rlmm4_t *in,
    const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check LM */
    if ((status == SM_ERR_SUCCESS) && (in->lmId >= SM_NUM_LM))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].lmmPerms[in->lmId]
        < SM_SCMI_PERM_PRIV))
    {
        status = SM_ERR_DENIED;
    }

    /* Check not self */
    if ((status == SM_ERR_SUCCESS) && (in->lmId ==  caller->lmId))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Boot LM */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_SystemLmBoot(caller->lmId, caller->instAgentId,
            in->lmId, &g_swReason);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset an LM                                                              */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->lmId: Identifier for the logical machine                           */
/* - in->flags: Reset flags:                                                */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Graceful request:                                               */
/*   Set to 1 if the request is a graceful request.                         */
/*   Set to 0 if the request is a forceful request                          */
/*                                                                          */
/* Process the LMM_RESET message. Platform handler for SCMI_LmmReset().     */
/* Requires access greater than or equal to PRIV.                           */
/*                                                                          */
/*  Access macros:                                                          */
/* - LMM_FLAGS_GRACEFUL() - Graceful request                                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the LM successfully booted.                         */
/* - SM_ERR_NOT_FOUND: if the LM identified by lmId does not exist.         */
/* - SM_ERR_INVALID_PARAMETERS, if lmId is the same as the caller.          */
/* - SM_ERR_DENIED: if the calling agent is not allowed to manage the LM    */
/*   specified by lmId.                                                     */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t LmmReset(const scmi_caller_t *caller, const msg_rlmm5_t *in,
    const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool graceful = LMM_FLAGS_GRACEFUL(in->flags) != 0U;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check LM */
    if ((status == SM_ERR_SUCCESS) && (in->lmId >= SM_NUM_LM))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].lmmPerms[in->lmId]
        < SM_SCMI_PERM_PRIV))
    {
        status = SM_ERR_DENIED;
    }

    /* Check not self */
    if ((status == SM_ERR_SUCCESS) && (in->lmId ==  caller->lmId))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Reset LM */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_SystemLmReset(caller->lmId, caller->instAgentId,
            in->lmId, false, graceful, &g_swReason);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Shutdown (power off) an LM                                               */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->lmId: Identifier for the logical machine                           */
/* - in->flags: Shutdown flags:                                             */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Graceful request:                                               */
/*   Set to 1 if the request is a graceful request.                         */
/*   Set to 0 if the request is a forceful request                          */
/*                                                                          */
/* Process the LMM_SHUTDOWN message. Platform handler for                   */
/* SCMI_LmmShutdown(). Requires access greater than or equal to PRIV.       */
/*                                                                          */
/*  Access macros:                                                          */
/* - LMM_FLAGS_GRACEFUL() - Graceful request                                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the LM successfully booted.                         */
/* - SM_ERR_NOT_FOUND: if the LM identified by lmid does not exist.         */
/* - SM_ERR_INVALID_PARAMETERS, if lmId is the same as the caller.          */
/* - SM_ERR_DENIED: if the calling agent is not allowed to manage the LM    */
/*   specified by lmId.                                                     */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t LmmShutdown(const scmi_caller_t *caller, const msg_rlmm6_t *in,
    const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool graceful = LMM_FLAGS_GRACEFUL(in->flags) != 0U;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check LM */
    if ((status == SM_ERR_SUCCESS) && (in->lmId >= SM_NUM_LM))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].lmmPerms[in->lmId]
        < SM_SCMI_PERM_PRIV))
    {
        status = SM_ERR_DENIED;
    }

    /* Check not self */
    if ((status == SM_ERR_SUCCESS) && (in->lmId ==  caller->lmId))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Shutdown LM */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_SystemLmShutdown(caller->lmId, caller->instAgentId,
            in->lmId, graceful, &g_swReason);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Wake (resume) an LM from a low power state                               */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->lmId: Identifier for the logical machine                           */
/*                                                                          */
/* Process the LMM_WAKE message. Platform handler for SCMI_LmmWake().       */
/* Requires access greater than or equal to SET.                            */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the LM successfully booted.                         */
/* - SM_ERR_NOT_FOUND: if the LM identified by lmId does not exist.         */
/* - SM_ERR_INVALID_PARAMETERS, if lmId is the same as the caller.          */
/* - SM_ERR_DENIED: if the calling agent is not allowed to manage the LM    */
/*   specified by lmId.                                                     */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t LmmWake(const scmi_caller_t *caller, const msg_rlmm7_t *in,
    const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check LM */
    if ((status == SM_ERR_SUCCESS) && (in->lmId >= SM_NUM_LM))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].lmmPerms[in->lmId]
        < SM_SCMI_PERM_SET))
    {
        status = SM_ERR_DENIED;
    }

    /* Check not self */
    if ((status == SM_ERR_SUCCESS) && (in->lmId ==  caller->lmId))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Wake LM */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_SystemLmWake(caller->lmId, caller->instAgentId,
            in->lmId);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Request an LM gracefully suspend (sleep)                                 */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->lmId: Identifier for the logical machine                           */
/*                                                                          */
/* Process the LMM_SUSPEND message. Platform handler for                    */
/* SCMI_LmmSuspend(). Requires access greater than or equal to PRIV.        */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the LM successfully booted.                         */
/* - SM_ERR_NOT_FOUND: if the LM identified by lmId does not exist.         */
/* - SM_ERR_INVALID_PARAMETERS, if lmId is the same as the caller.          */
/* - SM_ERR_DENIED: if the calling agent is not allowed to manage the LM    */
/*   specified by lmId.                                                     */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t LmmSuspend(const scmi_caller_t *caller, const msg_rlmm8_t *in,
    const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check LM */
    if ((status == SM_ERR_SUCCESS) && (in->lmId >= SM_NUM_LM))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].lmmPerms[in->lmId]
        < SM_SCMI_PERM_PRIV))
    {
        status = SM_ERR_DENIED;
    }

    /* Check not self */
    if ((status == SM_ERR_SUCCESS) && (in->lmId ==  caller->lmId))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Suspend LM */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_SystemLmSuspend(caller->lmId, caller->instAgentId,
            in->lmId);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure LM notifications                                               */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->lmId: Identifier for the logical machine                           */
/* - in->flags: Notification flags:                                         */
/*   Bits[31:3] Reserved, must be zero.                                     */
/*   Bit[3] Wake (resume) notification:                                     */
/*   Set to 1 to send notification.                                         */
/*   Set to 0 if no notification.                                           */
/*   Bit[2] Suspend (sleep) notification:                                   */
/*   Set to 1 to send notification.                                         */
/*   Set to 0 if no notification.                                           */
/*   Bit[1] Shutdown (off) notification:                                    */
/*   Set to 1 to send notification.                                         */
/*   Set to 0 if no notification.                                           */
/*   Bit[0] Boot (on) notification:                                         */
/*   Set to 1 to send notification.                                         */
/*   Set to 0 if no notification                                            */
/*                                                                          */
/* Process the LMM_NOTIFY message. Platform handler for SCMI_LmmNotify().   */
/* Requires access greater than or equal to NOTIFY.                         */
/*                                                                          */
/*  Access macros:                                                          */
/* - LMM_NOTIFY_BOOT() - Enable notifications for boot                      */
/* - LMM_NOTIFY_SHUTDOWN() - Enable notifications for shutdown              */
/* - LMM_NOTIFY_SUSPEND() - Enable notifications for suspend (sleep)        */
/* - LMM_NOTIFY_WAKE() - Enable notifications for wake (resume)             */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the notification state successfully updated.        */
/* - SM_ERR_NOT_FOUND: if the LM identified by lmid does not exist.         */
/* - SM_ERR_INVALID_PARAMETERS, if the input attributes flag specifies      */
/*   unsupported or invalid configurations.                                 */
/* - SM_ERR_DENIED: if the calling agent is not permitted to request the    */
/*   notification.                                                          */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t LmmNotify(const scmi_caller_t *caller, const msg_rlmm9_t *in,
    const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check LM */
    if ((status == SM_ERR_SUCCESS) && (in->lmId >= SM_NUM_LM))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if (status == SM_ERR_SUCCESS)
    {
        if (g_scmiAgentConfig[caller->agentId].lmmPerms[in->lmId]
            < SM_SCMI_PERM_NOTIFY)
        {
            status = SM_ERR_DENIED;
        }
        else
        {
            s_lmmNotify[in->lmId][caller->agentId]
                = (uint8_t) in->flags;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Read the reason the LM last booted/shutdown/reset                        */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->lmId: Identifier for the logical machine                           */
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
/* Process the LMM_RESET_REASON message. Platform handler for               */
/* SCMI_LmmResetReason(). Requires access greater than or equal to GET.     */
/*                                                                          */
/*  Access macros:                                                          */
/* - LMM_BOOT_FLAG_VLD() - Valid                                            */
/* - LMM_BOOT_FLAG_ORG_VLD() - Valid origin                                 */
/* - LMM_BOOT_FLAG_ORIGIN() - LM source of action                           */
/* - LMM_BOOT_FLAG_ERR_VLD() - Valid error ID                               */
/* - LMM_BOOT_FLAG_ERR_ID() - Error ID                                      */
/* - LMM_BOOT_FLAG_REASON() - Reason                                        */
/* - LMM_SHUTDOWN_FLAG_VLD() - Valid                                        */
/* - LMM_SHUTDOWN_FLAG_EXT_LEN() - Number of valid extended info words      */
/* - LMM_SHUTDOWN_FLAG_ORG_VLD() - Valid origin                             */
/* - LMM_SHUTDOWN_FLAG_ORIGIN() - LM source of action                       */
/* - LMM_SHUTDOWN_FLAG_ERR_VLD() - Valid error ID                           */
/* - LMM_SHUTDOWN_FLAG_ERR_ID() - Error ID                                  */
/* - LMM_SHUTDOWN_FLAG_REASON() - Reason                                    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the notification state successfully updated.        */
/* - SM_ERR_NOT_FOUND: if the LM identified by lmid does not exist.         */
/* - SM_ERR_DENIED: if the calling agent is not permitted to request the    */
/*   reset reason.                                                          */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t LmmResetReason(const scmi_caller_t *caller,
    const msg_rlmm10_t *in, msg_tlmm10_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    lmm_rst_rec_t bootRec;
    lmm_rst_rec_t shutdownRec;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check LM */
    if ((status == SM_ERR_SUCCESS) && (in->lmId >= SM_NUM_LM))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].lmmPerms[in->lmId]
        < SM_SCMI_PERM_GET))
    {
        status = SM_ERR_DENIED;
    }

    /* Get reset info */
    if (status == SM_ERR_SUCCESS)
    {
        status = LM_SystemLmReason(caller->lmId, in->lmId, &bootRec,
            &shutdownRec);
    }

    /* Fill in return data */
    if (status == SM_ERR_SUCCESS)
    {

        /* Update record size */
        uint32_t extLen = MIN(shutdownRec.extLen, LMM_MAX_EXTINFO);
        extLen = MIN(extLen, DEV_SM_NUM_EXT_INFO);

        /* Fill in boot info */
        out->bootFlags
            = LMM_BOOT_FLAG_VLD(bootRec.valid ? 1UL : 0UL)
            | LMM_BOOT_FLAG_ORG_VLD(bootRec.validOrigin ? 1UL : 0UL)
            | LMM_BOOT_FLAG_ORIGIN(bootRec.origin)
            | LMM_BOOT_FLAG_ERR_VLD(bootRec.validErr ? 1UL : 0UL)
            | LMM_BOOT_FLAG_ERR_ID(bootRec.errId)
            | LMM_BOOT_FLAG_REASON(bootRec.reason);

        /* Fill in shutdown info */
        out->shutdownFlags
            = LMM_SHUTDOWN_FLAG_VLD(shutdownRec.valid ? 1UL : 0UL)
            | LMM_SHUTDOWN_FLAG_EXT_LEN(extLen)
            | LMM_SHUTDOWN_FLAG_ORG_VLD(shutdownRec.validOrigin ? 1UL : 0UL)
            | LMM_SHUTDOWN_FLAG_ORIGIN(shutdownRec.origin)
            | LMM_SHUTDOWN_FLAG_ERR_VLD(shutdownRec.validErr ? 1UL : 0UL)
            | LMM_SHUTDOWN_FLAG_ERR_ID(shutdownRec.errId)
            | LMM_SHUTDOWN_FLAG_REASON(shutdownRec.reason);

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
/* Send lmm event                                                           */
/*                                                                          */
/* Parameters:                                                              */
/* - msgId: Message ID to dispatch                                          */
/* - trigger: Trigger data                                                  */
/*--------------------------------------------------------------------------*/
static int32_t LmmEvent(scmi_msg_id_t msgId, lmm_rpc_trigger_t trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all agents */
    for (uint32_t dstAgent = 0U; dstAgent < SM_SCMI_NUM_AGNT; dstAgent++)
    {
        /* Agent belong to instance? */
        if (g_scmiAgentConfig[dstAgent].scmiInst == trigger.rpcInst)
        {
            uint32_t event = trigger.parm[0];
            uint32_t lmId = trigger.parm[1];
            uint32_t eventLm = trigger.parm[2];
            msg_rlmm32_t out;

            if ((event == LMM_TRIGGER_PARM_LM_BOOT)
                && (LMM_NOTIFY_BOOT(s_lmmNotify[eventLm][dstAgent]) != 0U))
            {
                /* Fill in data */
                out.lmId = lmId;
                out.eventLm = eventLm;
                out.flags = LMM_EVENT_BOOT(1U);

                /* Queue notification */
                RPC_SCMI_P2aTxQ(dstAgent, msgId, (uint32_t*) &out,
                    sizeof(out), SCMI_NOTIFY_Q);
            }
            if ((event == LMM_TRIGGER_PARM_LM_SHUTDOWN)
                && (LMM_NOTIFY_SHUTDOWN(s_lmmNotify[eventLm][dstAgent]) != 0U))
            {
                /* Fill in data */
                out.lmId = lmId;
                out.eventLm = eventLm;
                out.flags = LMM_EVENT_SHUTDOWN(1U);

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
/* Reset agent configuration                                                */
/*                                                                          */
/* Parameters:                                                              */
/* - lmId: LM to reset                                                      */
/* - agentId: Message ID to dispatch                                        */
/* - permissionsReset: True to reset permissions                            */
/*--------------------------------------------------------------------------*/
static int32_t LmmResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Disable notifications */
    for (uint32_t lm = 0U; lm < SM_NUM_LM; lm++)
    {
        s_lmmNotify[lm][agentId] = 0U;
    }

    /* Return status */
    return status;
}

