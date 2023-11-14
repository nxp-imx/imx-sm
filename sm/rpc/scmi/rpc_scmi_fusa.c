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
/* Interface (SCMI) fusa protocol.                                          */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x10000U

/* SCMI fusa protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION             0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES          0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES  0x2U
#define COMMAND_FUSA_FEENV_STATE_GET         0x3U
#define COMMAND_FUSA_FEENV_STATE_SET         0x4U
#define COMMAND_FUSA_FEENV_STATE_NOTIFY      0x5U
#define COMMAND_FUSA_SEENV_STATE_GET         0x6U
#define COMMAND_FUSA_SEENV_STATE_SET         0x7U
#define COMMAND_FUSA_FAULT_GET               0x8U
#define COMMAND_FUSA_FAULT_SET               0x9U
#define COMMAND_FUSA_FAULT_GROUP_NOTIFY      0xAU
#define COMMAND_FUSA_SCHECK_EVNTRIG          0xBU
#define COMMAND_FUSA_CRC_CALCULATE           0xCU
#define COMMAND_FUSA_CRC_RESULT_GET          0xDU
#define COMMAND_SUPPORTED_MASK               0x3FFFUL

/* SCMI FuSa F-EENV states */
#define FUSA_FEENV_STATE_INIT            0U
#define FUSA_FEENV_STATE_PRE_SAFETY      1U
#define FUSA_FEENV_STATE_SAFETY_RUNTIME  2U
#define FUSA_FEENV_STATE_SOC_STANDBY     3U
#define FUSA_FEENV_STATE_SOC_SHUTDOWN    4U
#define FUSA_FEENV_STATE_SOC_RESET       5U

/* SCMI FuSa S-EENV states */
#define FUSA_SEENV_STATE_INIT            0U
#define FUSA_SEENV_STATE_SAFETY_READY    1U
#define FUSA_SEENV_STATE_SAFETY_RUNTIME  2U
#define FUSA_SEENV_STATE_TERMINAL        3U

/* Local macros */

/* SCMI FuSa protocol attributes 1 */
#define FUSA_PROTO_ATTR1_NUM_FAULT(x)  (((x) & 0xFFFFU) << 16U)
#define FUSA_PROTO_ATTR1_NUM_CRC(x)    (((x) & 0xFFU) << 8U)
#define FUSA_PROTO_ATTR1_NUM_SEENV(x)  (((x) & 0xFFU) << 0U)

/* SCMI FuSa F-eenv set flags */
#define FUSA_FLAGS_GRACEFUL(x)  (((x) & 0x1U) >> 0U)

/* SCMI FuSa notification flags */
#define FUSA_FEENV_NOTIFY_ENABLE(x)  (((x) & 0x1U) >> 0U)

/* SCMI FuSa fault get state flags */
#define FUSA_FAULT_GET_STATE(x)  (((x) & 0x1U) << 0U)

/* SCMI FuSa fault get state flags */
#define FUSA_FAULT_SET_STATE(x)  (((x) & 0x1U) >> 0U)

/* SCMI FuSa fault event flags */
#define FUSA_FAULT_FLAG_STATE(x)  (((x) & 0x1U) << 0U)

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
} msg_tfusa0_t;

/* Response type for ProtocolAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol attributes 1 */
    uint32_t attributes1;
    /* Protocol attributes 2 */
    uint32_t attributes2;
} msg_tfusa1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rfusa2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_tfusa2_t;

/* Response type for FusaFeenvStateGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Parameter identifying the safety state of the F-EENV */
    uint32_t feenvState;
    /* Mode selector value as returned by SAF */
    uint32_t mselMode;
} msg_tfusa3_t;

/* Request type for FusaFeenvStateSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Parameter identifying the requested safety state of the F-EENV */
    uint32_t feenvState;
    /* F-EENV set state flags */
    uint32_t flags;
} msg_rfusa4_t;

/* Request type for FusaFeenvStateNotify() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Notification flags */
    uint32_t notifyEnable;
} msg_rfusa5_t;

/* Response type for FusaSeenvStateGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Parameter identifying the safety state of the S-EENV */
    uint32_t seenvState;
} msg_tfusa6_t;

/* Request type for FusaSeenvStateSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Parameter to set the safety state of the S-EENV */
    uint32_t seenvState;
    /* Cookie value last sent by the F-EENV */
    uint32_t pingCookie;
    /* Last result of local core self-test routine executed by the S-EENV */
    uint32_t scstSignature;
} msg_rfusa7_t;

/* Request type for FusaFaultGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Global fault identifier */
    uint32_t faultId;
} msg_rfusa8_t;

/* Response type for FusaFaultGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* State of the fault */
    uint32_t flags;
} msg_tfusa8_t;

/* Request type for FusaFaultSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Global fault identifier */
    uint32_t faultId;
    /* State of the fault */
    uint32_t flags;
} msg_rfusa9_t;

/* Request type for FusaFaultGroupNotify() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* First global fault identifier to be configured */
    uint32_t faultIdFirst;
    /* Mask of faults to modify */
    uint32_t faultMask;
    /* Fault notification enables */
    uint32_t notifyEnable;
} msg_rfusa10_t;

/* Response type for FusaFaultGroupNotify() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Return equal to faultIdFirst */
    uint32_t faultIdFirstGet;
    /* Fault notification enabled state */
    uint32_t notifyEnabled;
} msg_tfusa10_t;

/* Request type for FusaCrcCalculate() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* index of CRC channel */
    uint32_t crcChannel;
    /* CRC CFG value */
    uint32_t crcCfg;
    /* start address (lower 32-bits) */
    uint32_t memStartLow;
    /* start address (upper 32-bits) */
    uint32_t memStartHigh;
    /* byte count */
    uint32_t memSize;
} msg_rfusa12_t;

/* Request type for FusaCrcResultGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* index of CRC channel */
    uint32_t crcChannel;
} msg_rfusa13_t;

/* Response type for FusaCrcResultGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* start address (lower 32-bits) */
    uint32_t memStartLow;
    /* start address (upper 32-bits) */
    uint32_t memStartHigh;
    /* byte count */
    uint32_t memSize;
    /* resulting CRC value */
    uint32_t crcResult;
} msg_tfusa13_t;

/* Request type for FusaFeenvStateEvent() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Parameter identifying the requested state of the F-EENV */
    uint32_t feenvState;
    /* Mode selector value as returned by SAF */
    uint32_t mselMode;
} msg_rfusa32_t;

/* Request type for FusaSeenvStateReqEvent() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Random cookie value */
    uint32_t pingCookie;
} msg_rfusa33_t;

/* Request type for FusaFaultEvent() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Global fault identifier */
    uint32_t faultId;
    /* Fault state flags */
    uint32_t flags;
} msg_rfusa34_t;

/* Local functions */

static int32_t FusaProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tfusa0_t *out);
static int32_t FusaProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tfusa1_t *out);
static int32_t FusaProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rfusa2_t *in, msg_tfusa2_t *out);
static int32_t FusaFeenvStateGet(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tfusa3_t *out);
static int32_t FusaFeenvStateSet(const scmi_caller_t *caller,
    const msg_rfusa4_t *in, const scmi_msg_status_t *out);
static int32_t FusaFeenvStateNotify(const scmi_caller_t *caller,
    const msg_rfusa5_t *in, const scmi_msg_status_t *out);
static int32_t FusaSeenvStateGet(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tfusa6_t *out);
static int32_t FusaSeenvStateSet(const scmi_caller_t *caller,
    const msg_rfusa7_t *in, const scmi_msg_status_t *out);
static int32_t FusaFaultGet(const scmi_caller_t *caller,
    const msg_rfusa8_t *in, msg_tfusa8_t *out);
static int32_t FusaFaultSet(const scmi_caller_t *caller,
    const msg_rfusa9_t *in, const scmi_msg_status_t *out);
static int32_t FusaFaultGroupNotify(const scmi_caller_t *caller,
    const msg_rfusa10_t *in, msg_tfusa10_t *out);
static int32_t FusaScheckEvntrig(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, const scmi_msg_status_t *out);
static int32_t FusaCrcCalculate(const scmi_caller_t *caller,
    const msg_rfusa12_t *in, const scmi_msg_status_t *out);
static int32_t FusaCrcResultGet(const scmi_caller_t *caller,
    const msg_rfusa13_t *in, msg_tfusa13_t *out);
static int32_t FusaFeenvStateEvent(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger);
static int32_t FusaSeenvStateReqEvent(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger);
static int32_t FusaFaultEvent(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger);
static int32_t FusaResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_FusaDispatchCommand(scmi_caller_t *caller,
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
            lenOut = sizeof(msg_tfusa0_t);
            status = FusaProtocolVersion(caller,
                (const scmi_msg_header_t*) in, (msg_tfusa0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tfusa1_t);
            status = FusaProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tfusa1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tfusa2_t);
            status = FusaProtocolMessageAttributes(caller,
                (const msg_rfusa2_t*) in, (msg_tfusa2_t*) out);
            break;
        case COMMAND_FUSA_FEENV_STATE_GET:
            lenOut = sizeof(msg_tfusa3_t);
            status = FusaFeenvStateGet(caller, (const scmi_msg_header_t*) in,
                (msg_tfusa3_t*) out);
            break;
        case COMMAND_FUSA_FEENV_STATE_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = FusaFeenvStateSet(caller, (const msg_rfusa4_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_FUSA_FEENV_STATE_NOTIFY:
            lenOut = sizeof(const scmi_msg_status_t);
            status = FusaFeenvStateNotify(caller, (const msg_rfusa5_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_FUSA_SEENV_STATE_GET:
            lenOut = sizeof(msg_tfusa6_t);
            status = FusaSeenvStateGet(caller, (const scmi_msg_header_t*) in,
                (msg_tfusa6_t*) out);
            break;
        case COMMAND_FUSA_SEENV_STATE_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = FusaSeenvStateSet(caller, (const msg_rfusa7_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_FUSA_FAULT_GET:
            lenOut = sizeof(msg_tfusa8_t);
            status = FusaFaultGet(caller, (const msg_rfusa8_t*) in,
                (msg_tfusa8_t*) out);
            break;
        case COMMAND_FUSA_FAULT_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = FusaFaultSet(caller, (const msg_rfusa9_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_FUSA_FAULT_GROUP_NOTIFY:
            lenOut = sizeof(msg_tfusa10_t);
            status = FusaFaultGroupNotify(caller, (const msg_rfusa10_t*) in,
                (msg_tfusa10_t*) out);
            break;
        case COMMAND_FUSA_SCHECK_EVNTRIG:
            lenOut = sizeof(const scmi_msg_status_t);
            status = FusaScheckEvntrig(caller, (const scmi_msg_header_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_FUSA_CRC_CALCULATE:
            lenOut = sizeof(const scmi_msg_status_t);
            status = FusaCrcCalculate(caller, (const msg_rfusa12_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_FUSA_CRC_RESULT_GET:
            lenOut = sizeof(msg_tfusa13_t);
            status = FusaCrcResultGet(caller, (const msg_rfusa13_t*) in,
                (msg_tfusa13_t*) out);
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
int32_t RPC_SCMI_FusaDispatchNotification(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Handle notifications */
    switch(msgId.messageId)
    {
        case RPC_SCMI_NOTIFY_FUSA_FEENV_STATE_EVENT:
            status = FusaFeenvStateEvent(msgId, trigger);
            break;
        case RPC_SCMI_NOTIFY_FUSA_SEENV_STATE_REQ_EVENT:
            status = FusaSeenvStateReqEvent(msgId, trigger);
            break;
        case RPC_SCMI_NOTIFY_FUSA_FAULT_EVENT:
            status = FusaFaultEvent(msgId, trigger);
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
int32_t RPC_SCMI_FusaDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return FusaResetAgentConfig(lmId, agentId, permissionsReset);
}

/*==========================================================================*/
/* Custom Protocol Implementation                                           */
/*==========================================================================*/

/* Local types */

typedef struct
{
    BITARRAY_DEC(faultNotify, SM_NUM_FAULT);
} fusa_info_t;

/* Local variables */

static fusa_info_t s_fusaInfo[SM_SCMI_NUM_AGNT];
static BITARRAY_DEC(stateNotify, SM_NUM_AGENT);

/*--------------------------------------------------------------------------*/
/* Get protocol version                                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->version: Protocol version. For this revision of the               */
/*   specification, this value must be 0x10000                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_FusaProtocolVersion().                                              */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tfusa0_t *out)
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
/* - out->attributes1: Protocol attributes 1:                               */
/*   Bits[31:16] Number of Fault sources (this number defines valid range   */
/*   of the fault ID identifiers used in the fault functions)               */
/*   Bits[15:8] Number of CRC channels supported                            */
/*   Bits[7:0] Number of S-EENV LM in the system (not counting the F-EENV   */
/*   itself)                                                                */
/* - out->attributes2: Protocol attributes 2:                               */
/*   Bits[31:0] Reserved, must be zero                                      */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_FusaProtocolAttributes().                                           */
/*                                                                          */
/*  Access macros:                                                          */
/* - FUSA_PROTO_ATTR1_NUM_FAULT() - Number of fault sources                 */
/* - FUSA_PROTO_ATTR1_NUM_CRC() - Number of CRC channels supported          */
/* - FUSA_PROTO_ATTR1_NUM_SEENV() - Number of S-EENV LM in the system       */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tfusa1_t *out)
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
        uint32_t numSeenv = 0U;

        /* Get number of S-EENV */
        LMM_SsenvNumGet(&numSeenv);

        /* Set attributes 1 */
        out->attributes1
            = FUSA_PROTO_ATTR1_NUM_FAULT((uint32_t) SM_NUM_FAULT)
            | FUSA_PROTO_ATTR1_NUM_CRC((uint32_t) SM_NUM_CRC)
            | FUSA_PROTO_ATTR1_NUM_SEENV(numSeenv);

        /* Attributes 2 always 0 */
        out->attributes2 = 0U;
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
/* SCMI_FusaProtocolMessageAttributes().                                    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature.                  */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is invalid    */
/*   or not implemented.                                                    */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rfusa2_t *in, msg_tfusa2_t *out)
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
        uint32_t mask = COMMAND_SUPPORTED_MASK;

        /* Always zero */
        out->attributes = 0U;

        /* Is message supported ? */
        if ((in->messageId >= 32U) || (((mask >> in->messageId)
            & 0x1U) == 0U))
        {
            status = SM_ERR_NOT_FOUND;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get current FuSa system state                                            */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->feenvState: Parameter identifying the safety state of the F-EENV  */
/* - out->mselMode: Mode selector value as returned by SAF                  */
/*                                                                          */
/* Process the FUSA_FEENV_STATE_GET message. Platform handler for           */
/* SCMI_FusaFeenvStateGet(). Requires access greater than or equal to GET.  */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the current F-EENV state is returned successfully.  */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller     */
/*   is not an S-EENV.                                                      */
/* - SM_ERR_DENIED: if the calling agent is not allowed to get the          */
/*   F-EENV state.                                                          */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaFeenvStateGet(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tfusa3_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check call from S-EENV */
    if ((status == SM_ERR_SUCCESS)
        && (caller->safeType != LMM_SAFE_TYPE_SEENV))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].fusaPerms
        < SM_SCMI_PERM_GET))
    {
        status = SM_ERR_DENIED;
    }

    /* Get requested info */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_FusaFeenvStateGet(caller->lmId, &(out->feenvState),
            &(out->mselMode));
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Request F-EENV transition to new state                                   */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->feenvState: Parameter identifying the requested safety state of    */
/*   the F-EENV                                                             */
/* - in->flags: F-EENV set state flags. This parameter has the following    */
/*   format:                                                                */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Graceful request.                                               */
/*   Set to 1 if the request is a graceful request.                         */
/*   Set to 0 if the request is a forceful request.                         */
/*   In graceful transition, the S-EENVs are notified and SM waits for      */
/*   their transition to off state                                          */
/*                                                                          */
/* Process the FUSA_FEENV_STATE_SET message. Platform handler for           */
/* SCMI_FusaFeenvStateSet(). Requires access greater than or equal to SET.  */
/*                                                                          */
/*  Access macros:                                                          */
/* - FUSA_FLAGS_GRACEFUL() - Graceful request                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the F-EENV state was set successfully.              */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller     */
/*   is not an S-EENV.                                                      */
/* - SM_ERR_INVALID_PARAMETERS: if the requested state or flags are         */
/*   invalid.                                                               */
/* - SM_ERR_DENIED: if the calling agent is not allowed to set the          */
/*   F-EENV state.                                                          */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaFeenvStateSet(const scmi_caller_t *caller,
    const msg_rfusa4_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool graceful = FUSA_FLAGS_GRACEFUL(in->flags) != 0U;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check call from S-EENV */
    if ((status == SM_ERR_SUCCESS)
        && (caller->safeType != LMM_SAFE_TYPE_SEENV))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].fusaPerms
        < SM_SCMI_PERM_SET))
    {
        status = SM_ERR_DENIED;
    }

    /* Change system state */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_FusaFeenvStateSet(caller->lmId, in->feenvState,
            graceful);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure F-EENV notifications                                           */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->notifyEnable: Notification flags:                                  */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] State change notification:                                      */
/*   Set to 1 to send notification.                                         */
/*   Set to 0 if no notification                                            */
/*                                                                          */
/* Process the FUSA_FEENV_STATE_NOTIFY message. Platform handler for        */
/* SCMI_FusaFeenvStateNotify(). Requires access greater than or equal to    */
/* NOTIFY.                                                                  */
/*                                                                          */
/*  Access macros:                                                          */
/* - FUSA_FEENV_NOTIFY_ENABLE() - Enable notifications for F-EENV state     */
/*   change                                                                 */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the notification state successfully updated.        */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller     */
/*   is not an S-EENV.                                                      */
/* - SM_ERR_DENIED: if the calling agent is not permitted to request the    */
/*   notification.                                                          */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaFeenvStateNotify(const scmi_caller_t *caller,
    const msg_rfusa5_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check call from S-EENV */
    if ((status == SM_ERR_SUCCESS)
        && (caller->safeType != LMM_SAFE_TYPE_SEENV))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].fusaPerms
        < SM_SCMI_PERM_NOTIFY))
    {
        status = SM_ERR_DENIED;
    }

    /* Record notification enable */
    if (status == SM_ERR_SUCCESS)
    {
        if (FUSA_FEENV_NOTIFY_ENABLE(in->notifyEnable) != 0U)
        {
            BITARRAY_SET(stateNotify, caller->agentId);
        }
        else
        {
            BITARRAY_CLR(stateNotify, caller->agentId);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get S-EENV state                                                         */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->seenvState: Parameter identifying the safety state of the S-EENV  */
/*                                                                          */
/* Process the FUSA_SEENV_STATE_GET message. Platform handler for           */
/* SCMI_FusaSeenvStateGet().                                                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the S-EENV state is returned successfully.          */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller     */
/*   is not an S-EENV.                                                      */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaSeenvStateGet(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tfusa6_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check call from S-EENV */
    if ((status == SM_ERR_SUCCESS)
        && (caller->safeType != LMM_SAFE_TYPE_SEENV))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Get requested info */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_FusaSeenvStateGet(caller->lmId, &(out->seenvState));
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set S-EENV state                                                         */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->seenvState: Parameter to set the safety state of the S-EENV        */
/* - in->pingCookie: Cookie value last sent by the F-EENV                   */
/* - in->scstSignature: Last result of local core self-test routine         */
/*   executed by the S-EENV                                                 */
/*                                                                          */
/* Process the FUSA_SEENV_STATE_SET message. Platform handler for           */
/* SCMI_FusaSeenvStateSet().                                                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the S-EENV state is set successfully.               */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller     */
/*   is not an S-EENV.                                                      */
/* - SM_ERR_INVALID_PARAMETERS: if the requested state is invalid.          */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaSeenvStateSet(const scmi_caller_t *caller,
    const msg_rfusa7_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check call from S-EENV */
    if ((status == SM_ERR_SUCCESS)
        && (caller->safeType != LMM_SAFE_TYPE_SEENV))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Change system state */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_FusaSeenvStateSet(caller->lmId, in->seenvState,
            in->pingCookie, in->scstSignature);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get fault state                                                          */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->faultId: Global fault identifier                                   */
/* - out->flags: State of the fault:                                        */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Fault state.                                                    */
/*   Set to 1 if the fault is set.                                          */
/*   Set to 0 if the fault is cleared                                       */
/*                                                                          */
/* Process the FUSA_FAULT_GET message. Platform handler for                 */
/* SCMI_FusaFaultGet(). Requires access greater than or equal to GET.       */
/*                                                                          */
/*  Access macros:                                                          */
/* - FUSA_FAULT_GET_STATE() - Fault state                                   */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the fault state is returned successfully.           */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller     */
/*   is not an S-EENV.                                                      */
/* - SM_ERR_NOT_FOUND: if faultId is invalid.                               */
/* - SM_ERR_DENIED: if the calling agent is not permitted to get the        */
/*   state.                                                                 */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaFaultGet(const scmi_caller_t *caller,
    const msg_rfusa8_t *in, msg_tfusa8_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool state = false;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check call from S-EENV */
    if ((status == SM_ERR_SUCCESS)
        && (caller->safeType != LMM_SAFE_TYPE_SEENV))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check fault */
    if ((status == SM_ERR_SUCCESS)
        && (((int32_t) in->faultId) >=  ((int32_t) SM_NUM_FAULT)))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].faultPerms[in->faultId]
        < SM_SCMI_PERM_GET))
    {
        status = SM_ERR_DENIED;
    }

    /* Get fault state */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_FusaFaultGet(caller->lmId, in->faultId,
            &state);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        out->flags = FUSA_FAULT_GET_STATE(state ? 1UL : 0UL);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set fault state                                                          */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->faultId: Global fault identifier                                   */
/* - in->flags: State of the fault:                                         */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Fault state.                                                    */
/*   Set to 1 to set the fault.                                             */
/*   Set to 0 to clear the fault                                            */
/*                                                                          */
/* Process the FUSA_FAULT_SET message. Platform handler for                 */
/* SCMI_FusaFaultSet(). Requires access greater than or equal to SET.       */
/*                                                                          */
/*  Access macros:                                                          */
/* - FUSA_FAULT_SET_STATE() - Fault state                                   */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the fault state is set successfully.                */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller     */
/*   is not an S-EENV.                                                      */
/* - SM_ERR_NOT_FOUND: if faultId is invalid.                               */
/* - SM_ERR_DENIED: if the calling agent is not permitted to set the        */
/*   state.                                                                 */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaFaultSet(const scmi_caller_t *caller,
    const msg_rfusa9_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check call from S-EENV */
    if ((status == SM_ERR_SUCCESS)
        && (caller->safeType != LMM_SAFE_TYPE_SEENV))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check fault */
    if ((status == SM_ERR_SUCCESS)
        && (((int32_t) in->faultId) >=  ((int32_t) SM_NUM_FAULT)))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].faultPerms[in->faultId]
        < SM_SCMI_PERM_SET))
    {
        status = SM_ERR_DENIED;
    }

    /* Change system state */
    if (status == SM_ERR_SUCCESS)
    {
        bool set = FUSA_FAULT_SET_STATE(in->flags) != 0U;

        /* Update state */
        status = LMM_FusaFaultSet(caller->lmId, in->faultId, set);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable fault notifications                                       */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->faultIdFirst: First global fault identifier to be configured       */
/* - in->faultMask: Mask of faults to modify.                               */
/*   Set to 1 to modify the fault notification.                             */
/*   Set to 0 to leave unmodified                                           */
/* - in->notifyEnable: Fault notification enables.                          */
/*   Set to 1 to enable a fault notification.                               */
/*   Set to 0 to disable a fault notification.                              */
/*   Only bits also set to 1 in faultMask are modified                      */
/* - out->faultIdFirstGet: Return equal to faultIdFirst                     */
/* - out->notifyEnabled: Fault notification enabled state.                  */
/*   Set to 1 indicates the fault notification is enabled.                  */
/*   Set to 0 indicates the fault notification is disabled                  */
/*                                                                          */
/* Process the FUSA_FAULT_GROUP_NOTIFY message. Platform handler for        */
/* SCMI_FusaFaultGroupNotify(). Requires access greater than or equal to    */
/* NOTIFY.                                                                  */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the fault notification is updated successfully for  */
/*   some faults.                                                           */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller     */
/*   is not an S-EENV.                                                      */
/* - SM_ERR_NOT_FOUND: if faultIdFirst is invalid.                          */
/* - SM_ERR_DENIED: if the calling agent is not permitted to modify any     */
/*   of the requested notifications.                                        */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaFaultGroupNotify(const scmi_caller_t *caller,
    const msg_rfusa10_t *in, msg_tfusa10_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check call from S-EENV */
    if ((status == SM_ERR_SUCCESS)
        && (caller->safeType != LMM_SAFE_TYPE_SEENV))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check fault */
    if ((status == SM_ERR_SUCCESS)
        && (((int32_t) in->faultIdFirst) >=  ((int32_t) SM_NUM_FAULT)))
    {
        status = SM_ERR_NOT_FOUND;
    }

    if (status == SM_ERR_SUCCESS)
    {
        bool found = false;

        /* Nothing enabled */
        out->notifyEnabled = 0U;
        out->faultIdFirstGet = in->faultIdFirst;

        /* Loop over faults */
        for (uint32_t idx = 0U; idx < 32U; idx++)
        {
            uint32_t agentId = caller->agentId;
            uint32_t faultId = idx + in->faultIdFirst;

            /* Check fault */
            if (((int32_t) faultId) >=  ((int32_t) SM_NUM_FAULT))
            {
                break;
            }

            /* Check mask */
            if ((in->faultMask & BIT32(idx)) != 0U)
            {
                /* Check permissions */
                if (g_scmiAgentConfig[caller->agentId].faultPerms[faultId]
                    < SM_SCMI_PERM_NOTIFY)
                {
                    status = SM_ERR_DENIED;
                }
                else
                {
                    /* Record in notify bit array */
                    if ((in->notifyEnable & BIT32(idx)) != 0U)
                    {
                        BITARRAY_SET(s_fusaInfo[agentId].faultNotify,
                            faultId);
                    }
                    else
                    {
                        BITARRAY_CLR(s_fusaInfo[agentId].faultNotify,
                            faultId);
                    }

                    /* One updated */
                    found = true;
                }
            }

            /* Update notify enabled */
            if (BITARRAY_GET(s_fusaInfo[agentId].faultNotify, faultId)
                != 0U)
            {
                out->notifyEnabled |= BIT32(idx);
            }
        }

        /* One found then no error */
        if (found)
        {
            status = SM_ERR_SUCCESS;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Temporarily disable fault handling                                       */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/*                                                                          */
/* Process the FUSA_SCHECK_EVNTRIG message. Platform handler for            */
/* SCMI_FusaScheckEvntrig().                                                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if fault handling disabled for the caller.             */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller     */
/*   is not an S-EENV.                                                      */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaScheckEvntrig(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check call from S-EENV */
    if ((status == SM_ERR_SUCCESS)
        && (caller->safeType != LMM_SAFE_TYPE_SEENV))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Report S-check event trigger */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_FusaScheckEvntrig(caller->lmId);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Start CRC calculation                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->crcChannel: Index of CRC channel                                   */
/* - in->crcCfg: CRC CFG value                                              */
/* - in->memStartLow: Start address (lower 32-bits)                         */
/* - in->memStartHigh: Start address (upper 32-bits)                        */
/* - in->memSize: Byte count                                                */
/*                                                                          */
/* Process the FUSA_CRC_CALCULATE message. Platform handler for             */
/* SCMI_FusaCrcCalculate(). Requires access greater than or equal to SET.   */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the CRC calcultation started successfully.          */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller     */
/*   is not an S-EENV.                                                      */
/* - SM_ERR_NOT_FOUND: if crcChannel is invalid.                            */
/* - SM_ERR_INVALID_PARAMETERS: if any of the parameters are invalid.       */
/* - SM_ERR_BUSY: if the CRC channel is already performing a CRC            */
/*   calculation.                                                           */
/* - SM_ERR_DENIED: if the calling agent is not permitted to use this       */
/*   CRC channel.                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaCrcCalculate(const scmi_caller_t *caller,
    const msg_rfusa12_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check call from S-EENV */
    if ((status == SM_ERR_SUCCESS)
        && (caller->safeType != LMM_SAFE_TYPE_SEENV))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check CRC channel */
    if ((status == SM_ERR_SUCCESS)
        && (in->crcChannel >= SM_NUM_CRC))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].crcPerms[in->crcChannel]
        < SM_SCMI_PERM_SET))
    {
        status = SM_ERR_DENIED;
    }

    /* Change system state */
    if (status == SM_ERR_SUCCESS)
    {
        uint64_t memStart = (((uint64_t) in->memStartHigh) << 32U)
            | (uint64_t) in->memStartLow;

        status = LMM_FusaCrcCalculate(caller->lmId, in->crcChannel,
            in->crcCfg, memStart, in->memSize);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get CRC calculation result                                               */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->crcChannel: Index of CRC channel                                   */
/* - out->memStartLow: Start address (lower 32-bits)                        */
/* - out->memStartHigh: Start address (upper 32-bits)                       */
/* - out->memSize: Byte count                                               */
/* - out->crcResult: Resulting CRC value                                    */
/*                                                                          */
/* Process the FUSA_CRC_RESULT_GET message. Platform handler for            */
/* SCMI_FusaCrcResultGet(). Requires access greater than or equal to SET.   */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the CRC calcultation completed successfully.        */
/* - SM_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller     */
/*   is not an S-EENV.                                                      */
/* - SM_ERR_NOT_FOUND: if crcChannel is invalid.                            */
/* - SM_ERR_BUSY: if the CRC channel has not completed the CRC              */
/*   calculation.                                                           */
/* - SM_ERR_DENIED: if the calling agent is not permitted to use this       */
/*   CRC channel.                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t FusaCrcResultGet(const scmi_caller_t *caller,
    const msg_rfusa13_t *in, msg_tfusa13_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    uint64_t memStart = 0ULL;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check call from S-EENV */
    if ((status == SM_ERR_SUCCESS)
        && (caller->safeType != LMM_SAFE_TYPE_SEENV))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check CRC channel */
    if ((status == SM_ERR_SUCCESS)
        && (in->crcChannel >= SM_NUM_CRC))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].crcPerms[in->crcChannel]
        < SM_SCMI_PERM_SET))
    {
        status = SM_ERR_DENIED;
    }

    /* Get fault state */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_FusaCrcResultGet(caller->lmId, in->crcChannel,
            &memStart, &(out->memSize), &(out->crcResult));
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        out->memStartHigh = SM_UINT64_H(memStart);
        out->memStartLow = SM_UINT64_L(memStart);
    }
    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Send fusa feenv state event                                              */
/*                                                                          */
/* Parameters:                                                              */
/* - msgId: Message ID to dispatch                                          */
/* - trigger: Trigger data                                                  */
/*--------------------------------------------------------------------------*/
static int32_t FusaFeenvStateEvent(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all agents */
    for (uint32_t dstAgent = 0U; dstAgent < SM_SCMI_NUM_AGNT; dstAgent++)
    {
        /* Agent belong to instance? */
        if ((g_scmiAgentConfig[dstAgent].scmiInst == trigger.rpcInst)
            && (BITARRAY_GET(stateNotify, dstAgent) != 0U))
        {
            msg_rfusa32_t out;

            /* Fill in data */
            out.feenvState = trigger.parm[0];
            out.mselMode = trigger.parm[1];

            /* Check if queue is full */
            if (!RPC_SCMI_P2aTxQFull(dstAgent, sizeof(out),
                SCMI_PRIORITY_Q))
            {
                /* Queue notification */
                RPC_SCMI_P2aTxQ(dstAgent, msgId, (uint32_t*) &out,
                    sizeof(out), SCMI_PRIORITY_Q);
            }
            else
            {
                status = SM_ERR_BUSY;
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Send fusa seenv state req event                                          */
/*                                                                          */
/* Parameters:                                                              */
/* - msgId: Message ID to dispatch                                          */
/* - trigger: Trigger data                                                  */
/*--------------------------------------------------------------------------*/
static int32_t FusaSeenvStateReqEvent(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all agents */
    for (uint32_t dstAgent = 0U; dstAgent < SM_SCMI_NUM_AGNT; dstAgent++)
    {
        /* Agent belong to instance? */
        if ((g_scmiAgentConfig[dstAgent].scmiInst == trigger.rpcInst)
            && (BITARRAY_GET(stateNotify, dstAgent) != 0U))
        {
            msg_rfusa33_t out;

            /* Fill in data */
            out.pingCookie = trigger.parm[0];

            /* Check if queue is full */
            if (!RPC_SCMI_P2aTxQFull(dstAgent, sizeof(out),
                SCMI_PRIORITY_Q))
            {
                /* Queue notification */
                RPC_SCMI_P2aTxQ(dstAgent, msgId, (uint32_t*) &out,
                    sizeof(out), SCMI_PRIORITY_Q);
            }
            else
            {
                status = SM_ERR_BUSY;
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Send fusa fault event                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - msgId: Message ID to dispatch                                          */
/* - trigger: Trigger data                                                  */
/*--------------------------------------------------------------------------*/
static int32_t FusaFaultEvent(scmi_msg_id_t msgId, lmm_rpc_trigger_t trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all agents */
    for (uint32_t dstAgent = 0U; dstAgent < SM_SCMI_NUM_AGNT; dstAgent++)
    {
        uint32_t fault = trigger.parm[0];

        /* Agent belong to instance? */
        if ((g_scmiAgentConfig[dstAgent].scmiInst == trigger.rpcInst)
            && (BITARRAY_GET(s_fusaInfo[dstAgent].faultNotify, fault)
            != 0U))
        {
            msg_rfusa34_t out;

            /* Fill in data */
            out.faultId = fault;
            out.flags = trigger.parm[1];

            /* Check if queue is full */
            if (!RPC_SCMI_P2aTxQFull(dstAgent, sizeof(out),
                SCMI_PRIORITY_Q))
            {
                /* Queue notification */
                RPC_SCMI_P2aTxQ(dstAgent, msgId, (uint32_t*) &out,
                    sizeof(out), SCMI_PRIORITY_Q);
            }
            else
            {
                status = SM_ERR_BUSY;
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
static int32_t FusaResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Disable state notifications */
    BITARRAY_CLR(stateNotify, agentId);

    /* Disable fault notifications */
    for (uint32_t idx = 0U; idx < BITARRAY_SIZE(SM_NUM_FAULT); idx++)
    {
        s_fusaInfo[agentId].faultNotify[idx] = 0U;
    }

    /* Return status */
    return status;
}

