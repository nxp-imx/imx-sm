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
/* Interface (SCMI) sys protocol.                                           */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x20001U

/* SCMI sys protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION             0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES          0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES  0x2U
#define COMMAND_SYSTEM_POWER_STATE_SET       0x3U
#define COMMAND_SYSTEM_POWER_STATE_NOTIFY    0x5U
#define COMMAND_NEGOTIATE_PROTOCOL_VERSION   0x10U
#define COMMAND_SUPPORTED_MASK               0x1002FUL

/* SCMI system power states */
#define SYS_STATE_SHUTDOWN       0x00000000U
#define SYS_STATE_COLD_RESET     0x00000001U
#define SYS_STATE_WARM_RESET     0x00000002U
#define SYS_STATE_POWER_UP       0x00000003U
#define SYS_STATE_SUSPEND        0x00000004U
#define SYS_STATE_WAKE           0x80000000U
#define SYS_STATE_FULL_SHUTDOWN  0x80000001U
#define SYS_STATE_FULL_RESET     0x80000002U
#define SYS_STATE_FULL_SUSPEND   0x80000003U
#define SYS_STATE_FULL_WAKE      0x80000004U
#define SYS_STATE_GRP_SHUTDOWN   0x80000005U
#define SYS_STATE_GRP_RESET      0x80000006U
#define SYS_STATE_MODE           0xC0000000U

/* Local macros */

/* SCMI system message attributes */
#define SYS_MSG_ATTR_WARM(x)     (((x) & 0x1U) << 31U)
#define SYS_MSG_ATTR_SUSPEND(x)  (((x) & 0x1U) << 30U)

/* SCMI system power state flags */
#define SYS_FLAGS_GRACEFUL(x)  (((x) & 0x1U) >> 0U)

/* SCMI system notification flags */
#define SYS_NOTIFY_ENABLE(x)  (((x) & 0x1U) >> 0U)

/* SCMI system event flags */
#define SYS_NOTIFIER_GRACEFUL(x)  (((x) & 0x1U) << 0U)

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
} msg_tsys0_t;

/* Response type for ProtocolAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol attributes */
    uint32_t attributes;
} msg_tsys1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rsys2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_tsys2_t;

/* Request type for SystemPowerStateSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Power state set flags */
    uint32_t flags;
    /* System state */
    uint32_t systemState;
} msg_rsys3_t;

/* Request type for SystemPowerStateNotify() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Notification flags */
    uint32_t notifyEnable;
} msg_rsys5_t;

/* Request type for NegotiateProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* The negotiated protocol version the agent intends to use */
    uint32_t version;
} msg_rsys16_t;

/* Request type for SystemPowerStateNotifier() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the agent that caused the event */
    uint32_t agentId;
    /* Notification events */
    uint32_t flags;
    /* System state */
    uint32_t systemState;
    /* Timeout */
    uint32_t timeout;
} msg_rsys32_t;

/* Local functions */

static int32_t SysProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tsys0_t *out);
static int32_t SysProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tsys1_t *out);
static int32_t SysProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rsys2_t *in, msg_tsys2_t *out);
static int32_t SystemPowerStateSet(const scmi_caller_t *caller,
    const msg_rsys3_t *in, const scmi_msg_status_t *out, uint32_t *len);
static int32_t SystemPowerStateNotify(const scmi_caller_t *caller,
    const msg_rsys5_t *in, const scmi_msg_status_t *out);
static int32_t SysNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rsys16_t *in, const scmi_msg_status_t *out);
static int32_t SystemPowerStateNotifier(scmi_msg_id_t msgId,
    const lmm_rpc_trigger_t *trigger);
static int32_t SysResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_SysDispatchCommand(scmi_caller_t *caller,
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
            lenOut = sizeof(msg_tsys0_t);
            status = SysProtocolVersion(caller, (const scmi_msg_header_t*) in,
                (msg_tsys0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tsys1_t);
            status = SysProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tsys1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tsys2_t);
            status = SysProtocolMessageAttributes(caller,
                (const msg_rsys2_t*) in, (msg_tsys2_t*) out);
            break;
        case COMMAND_SYSTEM_POWER_STATE_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = SystemPowerStateSet(caller, (const msg_rsys3_t*) in,
                (const scmi_msg_status_t*) out, &lenOut);
            break;
        case COMMAND_SYSTEM_POWER_STATE_NOTIFY:
            lenOut = sizeof(const scmi_msg_status_t);
            status = SystemPowerStateNotify(caller, (const msg_rsys5_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_NEGOTIATE_PROTOCOL_VERSION:
            lenOut = sizeof(const scmi_msg_status_t);
            status = SysNegotiateProtocolVersion(caller,
                (const msg_rsys16_t*) in, (const scmi_msg_status_t*) out);
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
int32_t RPC_SCMI_SysDispatchNotification(scmi_msg_id_t msgId,
    const lmm_rpc_trigger_t *trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Handle notifications */
    switch (msgId.messageId)
    {
        case RPC_SCMI_NOTIFY_SYSTEM_POWER_STATE_NOTIFIER:
            status = SystemPowerStateNotifier(msgId, trigger);
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
int32_t RPC_SCMI_SysDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return SysResetAgentConfig(lmId, agentId, permissionsReset);
}

/*==========================================================================*/
/* Custom Protocol Implementation                                           */
/*==========================================================================*/

/* Local variables */

static uint32_t s_powerMode[SM_SCMI_NUM_AGNT];
static bool s_sysNotify[SM_SCMI_NUM_AGNT];

/* Local functions */

static int32_t SystemPowerUpdate(const scmi_caller_t *caller, uint32_t lmId,
    uint32_t systemState, bool graceful);
static int32_t SystemPowerMode(uint32_t lmId, uint32_t agentId,
    uint32_t powerMode);

/*--------------------------------------------------------------------------*/
/* Get protocol version                                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->version: Protocol version. For this revision of the               */
/*   specification, this value must be 0x20001                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_SysProtocolVersion(). See section 4.4.2.1 in the SCMI spec.         */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SysProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tsys0_t *out)
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
/*   Bits[31:0] Reserved, must be zero                                      */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_SysProtocolAttributes(). See section 4.4.2.3 in the SCMI spec.      */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SysProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tsys1_t *out)
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
        /* No attributes */
        out->attributes = 0U;
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
/* - out->attributes: Message attributes: Flags associated with a specific  */
/*   function in the protocol.                                              */
/*   If message ID is for SYSTEM_POWER_STATE_SET, the attributes have the   */
/*   following format:                                                      */
/*   Bit[31] System warm reset support.                                     */
/*   Set to 1 if system warm reset is supported.                            */
/*   Set to 0 if system warm reset is not supported.                        */
/*   Bit[30] System suspend support.                                        */
/*   Set to 1 if system suspend is supported.                               */
/*   Set to 0 if system suspend is not supported.                           */
/*   Bits[29:0] Reserved, must be zero.                                     */
/*   For all values of message ID, this value is zero                       */
/*                                                                          */
/* Process the PROTOCOL_MESSAGE_ATTRIBUTES message. Platform handler for    */
/* SCMI_SysProtocolMessageAttributes(). See section 4.4.2.4 in the SCMI     */
/* spec.                                                                    */
/*                                                                          */
/*  Access macros:                                                          */
/* - SYS_MSG_ATTR_WARM() - System warm reset support                        */
/* - SYS_MSG_ATTR_SUSPEND() - System suspend (sleep) support                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is invalid    */
/*   or not provided by this platform implementation.                       */
/* - SM_ERR_NOT_SUPPORTED: when message ID is set to the                    */
/*   SYSTEM_POWER_STATE_NOTIFY function identifier and notifications are    */
/*   not supported.                                                         */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SysProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rsys2_t *in, msg_tsys2_t *out)
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

        /* Initially zero */
        out->attributes = 0U;

        /* Is message supported ? */
        if ((in->messageId >= 32U) || (((mask >> in->messageId)
            & 0x1U) == 0U))
        {
            status = SM_ERR_NOT_FOUND;
        }
    }

    /* State transitions supported? */
    if ((status == SM_ERR_SUCCESS)
        && (in->messageId == COMMAND_SYSTEM_POWER_STATE_SET))
    {
        if (g_scmiAgentConfig[caller->agentId].sysPerms
            < SM_SCMI_PERM_SET)
        {
            status = SM_ERR_NOT_SUPPORTED;
        }
        else
        {
            /* Warm reset supported */
            out->attributes |= SYS_MSG_ATTR_WARM(1UL);
        }
    }

    /* Notifications supported? */
    if ((status == SM_ERR_SUCCESS)
        && (in->messageId == COMMAND_SYSTEM_POWER_STATE_NOTIFY))
    {
        if (g_scmiAgentConfig[caller->agentId].sysPerms
            < SM_SCMI_PERM_NOTIFY)
        {
            status = SM_ERR_NOT_SUPPORTED;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set system power state                                                   */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->flags: Power state set flags. This parameter has the following     */
/*   format:                                                                */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Graceful request. This flag is ignored for power up requests.   */
/*   Set to 1 if the request is a graceful request.                         */
/*   Set to 0 if the request is a forceful request                          */
/* - in->systemState: System state. Can be one of:                          */
/*   0x0 System shutdown (off).                                             */
/*   0x1 System cold reset.                                                 */
/*   0x2 System warm reset.                                                 */
/*   0x3 System power-up (boot).                                            */
/*   0x4 System suspend (sleep).                                            */
/*   0x5 - 0x7FFFFFFF Reserved, must not be used.                           */
/*   0x80000000 - 0xFFFFFFFF Might be used for vendor-defined               */
/*   implementations of system power state. These can include additional    */
/*   parameters. The prototype for vendor-defined calls is beyond the       */
/*   scope of this specification                                            */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the SYSTEM_POWER_STATE_SET message. Platform handler for         */
/* SCMI_SystemPowerStateSet(). Requires access greater than or equal to     */
/* SET/PRIV/EXCLUSIVE. See section 4.4.2.5 in the SCMI spec.                */
/*                                                                          */
/*  Access macros:                                                          */
/* - SYS_FLAGS_GRACEFUL() - Graceful request                                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_INVALID_PARAMETERS: if the requested power state is not valid.  */
/* - SM_ERR_NOT_SUPPORTED: if the requested state is not supported for      */
/*   the calling agent.                                                     */
/* - SM_ERR_DENIED: for system suspend requests when there are              */
/*   application processors, other than the caller, in a running or idle    */
/*   state.                                                                 */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SystemPowerStateSet(const scmi_caller_t *caller,
    const msg_rsys3_t *in, const scmi_msg_status_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    bool graceful = SYS_FLAGS_GRACEFUL(in->flags) != 0U;
    bool mode = (in->systemState & SYS_STATE_MODE) == SYS_STATE_MODE;
    uint32_t agentId = caller->agentId;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check permissions */
    if (status == SM_ERR_SUCCESS)
    {
        uint8_t reqPerm = SM_SCMI_PERM_SET;

        /* Determine perms */
        if (!graceful)
        {
            /* Check target power state */
            if (in->systemState < SYS_STATE_FULL_SHUTDOWN)
            {
                reqPerm = SM_SCMI_PERM_PRIV;
            }
            else
            {
                reqPerm = SM_SCMI_PERM_EXCLUSIVE;
            }
        }

        /* Support mode */
        if (mode)
        {
            reqPerm = SM_SCMI_PERM_PRIV;
        }

        if (g_scmiAgentConfig[agentId].sysPerms < reqPerm)
        {
            status = SM_ERR_DENIED;
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        uint32_t lmId = caller->lmId;

        if (mode)
        {
            /* Update mode */
            status = SystemPowerMode(caller->lmId, agentId,
                in->systemState & ~SYS_STATE_MODE);
        }
        else
        {
            /* Request power transition */
            status = SystemPowerUpdate(caller, lmId, in->systemState,
                graceful);

            /* May be nothing to return result to */
            if ((status == SM_ERR_SUCCESS) && (!graceful))
            {
                *len = 0U;
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure system state notifications                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->notifyEnable: Notification flags:                                  */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Notify enable:                                                  */
/*   If this value is set to 0, the platform does not send any system       */
/*   power state notifier messages to the calling agent.                    */
/*   If this value is set to 1, the platform does send system power state   */
/*   notifier messages functions to the calling agent                       */
/*                                                                          */
/* Process the SYSTEM_POWER_STATE_NOTIFY message. Platform handler for      */
/* SCMI_SystemPowerStateNotify(). Requires access greater than or equal to  */
/* NOTIFY. See section 4.4.2.7 in the SCMI spec.                            */
/*                                                                          */
/*  Access macros:                                                          */
/* - SYS_NOTIFY_ENABLE() - Notify enable                                    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS                                                         */
/* - SM_ERR_NOT_SUPPORTED: if notifications are not supported or            */
/*   available to the calling agent.                                        */
/* - SM_ERR_INVALID_PARAMETERS: if notify_enable specifies invalid or       */
/*   impermissible values.                                                  */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SystemPowerStateNotify(const scmi_caller_t *caller,
    const msg_rsys5_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].sysPerms
        < SM_SCMI_PERM_NOTIFY))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Record notification enable */
    if (status == SM_ERR_SUCCESS)
    {
        s_sysNotify[caller->agentId]
            = (SYS_NOTIFY_ENABLE(in->notifyEnable) != 0U);
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
/* SCMI_SysNegotiateProtocolVersion(). See section 4.4.2.2 in the SCMI      */
/* spec.                                                                    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the negotiated protocol version is supported by     */
/*   the platform. All commands, responses, and notifications post          */
/*   successful return of this command must comply with the negotiated      */
/*   version.                                                               */
/* - SM_ERR_NOT_SUPPORTED: if the protocol version is not supported.        */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SysNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rsys16_t *in, const scmi_msg_status_t *out)
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
/* Send system power state notifier                                         */
/*                                                                          */
/* Parameters:                                                              */
/* - msgId: Message ID to dispatch                                          */
/* - trigger: Trigger data                                                  */
/*--------------------------------------------------------------------------*/
static int32_t SystemPowerStateNotifier(scmi_msg_id_t msgId,
    const lmm_rpc_trigger_t *trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all agents */
    for (uint32_t dstAgent = 0U; dstAgent < SM_SCMI_NUM_AGNT; dstAgent++)
    {
        /* Agent belong to instance? */
        if ((g_scmiAgentConfig[dstAgent].scmiInst == trigger->rpcInst)
            && (s_sysNotify[dstAgent]))
        {
            msg_rsys32_t out;

            /* Fill in data */
            out.agentId = trigger->parm[1];
            out.flags = trigger->parm[3];
            out.systemState = trigger->parm[0];
            out.timeout = 0U;

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
static int32_t SysResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Disable notifications */
    s_sysNotify[agentId] = false;

    /* Reset power mode */
    if (s_powerMode[agentId] != 0U)
    {
        status = SystemPowerMode(lmId, agentId, 0U);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Update system power state                                                */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - lmId: LM to change state for                                           */
/* - systemState: new system power state                                    */
/*--------------------------------------------------------------------------*/
static int32_t SystemPowerUpdate(const scmi_caller_t *caller, uint32_t lmId,
    uint32_t systemState, bool graceful)
{
    int32_t status = SM_ERR_SUCCESS;

    /* New state? */
    switch (systemState)
    {
        case SYS_STATE_SHUTDOWN:
            /* Shutdown */
            status = LMM_SystemLmShutdown(caller->lmId, caller->instAgentId,
                lmId, graceful, &g_swReason);
            break;
        case SYS_STATE_COLD_RESET:
            /* Cold Reset */
            status = LMM_SystemLmReset(caller->lmId, caller->instAgentId,
                lmId, false, graceful, &g_swReason);
            break;
        case SYS_STATE_WARM_RESET:
            /* Warm Reset */
            status = LMM_SystemLmReset(caller->lmId, caller->instAgentId,
                lmId, true, graceful, &g_swReason);
            break;
        case SYS_STATE_POWER_UP:
            /* Power up */
            status = SM_ERR_NOT_SUPPORTED;
            break;
        case SYS_STATE_SUSPEND:
        case SYS_STATE_WAKE:
            /* Suspend */
            status = SM_ERR_NOT_SUPPORTED;
            break;
        case SYS_STATE_FULL_SHUTDOWN:
            /* System shutdown */
            status = LMM_SystemShutdown(caller->lmId,
                caller->instAgentId, graceful, &g_swReason);
            break;
        case SYS_STATE_FULL_RESET:
            /* System reset*/
            status = LMM_SystemReset(caller->lmId,
                caller->instAgentId, graceful, &g_swReason);
            break;
        case SYS_STATE_FULL_SUSPEND:
            /* System suspend */
            status = LMM_SystemSuspend(caller->lmId,
                caller->instAgentId);
            break;
        case SYS_STATE_FULL_WAKE:
            /* System wake*/
            status = LMM_SystemWake(caller->lmId,
                caller->instAgentId);
            break;
        case SYS_STATE_GRP_SHUTDOWN:
            /* System shutdown */
            status = LMM_SystemGrpShutdown(caller->lmId,
                caller->instAgentId, graceful, &g_swReason, 0U);
            break;
        case SYS_STATE_GRP_RESET:
            /* System reset*/
            status = LMM_SystemGrpReset(caller->lmId,
                caller->instAgentId, graceful, &g_swReason, 0U);
            break;
        default:
            status = SM_ERR_INVALID_PARAMETERS;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Aggregate and update the system power mode                               */
/*                                                                          */
/* Parameters:                                                              */
/* - lmId: LM to update                                                     */
/* - agentId: Message to update                                             */
/* - mode: New system mode                                                  */
/*--------------------------------------------------------------------------*/
static int32_t SystemPowerMode(uint32_t lmId, uint32_t agentId,
    uint32_t powerMode)
{
    uint32_t scmiInst = g_scmiAgentConfig[agentId].scmiInst;
    uint32_t firstAgent = g_scmiConfig[scmiInst].firstAgent;
    uint32_t numAgents = g_scmiConfig[scmiInst].numAgents;
    uint32_t newMode = 0U;

    /* Record power mode for this agent */
    s_powerMode[agentId] = powerMode;

    /* Calculate new aggregate mode for the LM */
    for (uint32_t a = firstAgent; a < (firstAgent + numAgents); a++)
    {
        newMode |= s_powerMode[a];
    }

    /* Inform LMM of system mode */
    return LMM_SystemPowerModeSet(lmId, newMode);
}

