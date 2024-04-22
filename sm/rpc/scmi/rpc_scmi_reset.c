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
/* Interface (SCMI) reset protocol.                                         */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x30001U

/* SCMI reset protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION             0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES          0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES  0x2U
#define COMMAND_RESET_DOMAIN_ATTRIBUTES      0x3U
#define COMMAND_RESET                        0x4U
#define COMMAND_NEGOTIATE_PROTOCOL_VERSION   0x10U
#define COMMAND_SUPPORTED_MASK               0x1001FUL

/* SCMI max reset argument lengths */
#define RESET_MAX_NAME  16U

/* SCMI reset architectural reset states */
#define RESET_ARCH_COLD  0x00000000U

/* Local macros */

/* SCMI reset protocol attributes */
#define RESET_PROTO_ATTR_NUM_RESETS(x)  (((x) & 0xFFFFU) << 0U)

/* SCMI reset attributes */
#define RESET_ATTR_ASYNC(x)          (((x) & 0x1U) << 31U)
#define RESET_ATTR_NOTIFICATIONS(x)  (((x) & 0x1U) << 30U)
#define RESET_ATTR_EXT_NAME(x)       (((x) & 0x1U) << 29U)

/* SCMI reset flags */
#define RESET_FLAGS_ASYNC(x)   (((x) & 0x4U) >> 2U)
#define RESET_FLAGS_SIGNAL(x)  (((x) & 0x2U) >> 1U)
#define RESET_FLAGS_AUTO(x)    (((x) & 0x1U) >> 0U)

/* SCMI architectural reset states */
#define RESET_STATE_ARCH(x)  (((x) & 0x80000000U) >> 31U)

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
} msg_treset0_t;

/* Response type for ProtocolAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol attributes */
    uint32_t attributes;
} msg_treset1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rreset2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_treset2_t;

/* Request type for ResetDomainAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the reset domain */
    uint32_t domainId;
} msg_rreset3_t;

/* Response type for ResetDomainAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Domain attributes */
    uint32_t attributes;
    /* Maximum time (in uS) required to reset */
    uint32_t latency;
    /* ASCII name string */
    uint8_t name[RESET_MAX_NAME];
} msg_treset3_t;

/* Request type for Reset() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the reset domain */
    uint32_t domainId;
    /* Reset flags */
    uint32_t flags;
    /* The reset state being requested */
    uint32_t resetState;
} msg_rreset4_t;

/* Request type for NegotiateProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* The negotiated protocol version the agent intends to use */
    uint32_t version;
} msg_rreset16_t;

/* Local functions */

static int32_t ResetProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_treset0_t *out);
static int32_t ResetProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_treset1_t *out);
static int32_t ResetProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rreset2_t *in, msg_treset2_t *out);
static int32_t ResetDomainAttributes(const scmi_caller_t *caller,
    const msg_rreset3_t *in, msg_treset3_t *out);
static int32_t Reset(const scmi_caller_t *caller, const msg_rreset4_t *in,
    const scmi_msg_status_t *out);
static int32_t ResetNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rreset16_t *in, const scmi_msg_status_t *out);
static int32_t ResetResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_ResetDispatchCommand(scmi_caller_t *caller,
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
            lenOut = sizeof(msg_treset0_t);
            status = ResetProtocolVersion(caller,
                (const scmi_msg_header_t*) in, (msg_treset0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_treset1_t);
            status = ResetProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_treset1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_treset2_t);
            status = ResetProtocolMessageAttributes(caller,
                (const msg_rreset2_t*) in, (msg_treset2_t*) out);
            break;
        case COMMAND_RESET_DOMAIN_ATTRIBUTES:
            lenOut = sizeof(msg_treset3_t);
            status = ResetDomainAttributes(caller, (const msg_rreset3_t*) in,
                (msg_treset3_t*) out);
            break;
        case COMMAND_RESET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = Reset(caller, (const msg_rreset4_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_NEGOTIATE_PROTOCOL_VERSION:
            lenOut = sizeof(const scmi_msg_status_t);
            status = ResetNegotiateProtocolVersion(caller,
                (const msg_rreset16_t*) in, (const scmi_msg_status_t*) out);
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
/* Dispatch SCMI reset                                                      */
/*                                                                          */
/* Parameters:                                                              */
/* - lmId: LM to reset                                                      */
/* - agentId: Message ID to dispatch                                        */
/* - permissionsReset: True to reset permissions                            */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_ResetDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return ResetResetAgentConfig(lmId, agentId, permissionsReset);
}

/*==========================================================================*/
/* Custom Protocol Implementation                                           */
/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Get protocol version                                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->version: Protocol version. For this revision of the               */
/*   specification, this value must be 0x30001                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_ResetProtocolVersion(). See section 4.8.2.1 in the SCMI spec.       */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ResetProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_treset0_t *out)
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
/*   Bits[31:16] Reserved, must be zero.                                    */
/*   Bits[15:0] Number of reset domains                                     */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_ResetProtocolAttributes(). See section 4.8.2.3 in the SCMI spec.    */
/*                                                                          */
/*  Access macros:                                                          */
/* - RESET_PROTO_ATTR_NUM_RESETS() - Number of reset domains                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ResetProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_treset1_t *out)
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
        /* Return number of resets */
        out->attributes = RESET_PROTO_ATTR_NUM_RESETS((uint32_t)
            SM_NUM_RESET);
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
/* SCMI_ResetProtocolMessageAttributes(). See section 4.8.2.4 in the SCMI   */
/* spec.                                                                    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is invalid    */
/*   or not provided by this platform implementation.                       */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ResetProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rreset2_t *in, msg_treset2_t *out)
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
/* Get reset domain attributes                                              */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the reset domain                          */
/* - out->attributes: Domain attributes:                                    */
/*   Bit[31] Asynchronous reset support.                                    */
/*   Set to 1 if this domain can be reset asynchronously.                   */
/*   Set to 0 if this domain can only be reset synchronously.               */
/*   Bit[30] Reset notifications support.                                   */
/*   Set to 1 if reset notifications are supported for this domain.         */
/*   Set to 0 if reset notifications are not supported for this domain.     */
/*   Bit[29] Extended reset domain name.                                    */
/*   If set to 1, the reset domain name is greater than 16 bytes.           */
/*   If set to 0, extended reset domain name is not supported.              */
/*   Bits[28:0] Reserved, must be zero                                      */
/* - out->latency: Maximum time (in uS) required to reset. A value of       */
/*   0xFFFFFFFF indicates this field is not supported by the platform       */
/* - out->name: Null-terminated ASCII string of up to 16 bytes in length    */
/*   describing the reset domain name. When Bit[29] of attributes field is  */
/*   set to 1, this field contains the lower 15 bytes of the NULL           */
/*   terminated reset domain name                                           */
/*                                                                          */
/* Process the RESET_DOMAIN_ATTRIBUTES message. Platform handler for        */
/* SCMI_ResetDomainAttributes(). See section 4.8.2.5 in the SCMI spec.      */
/*                                                                          */
/*  Access macros:                                                          */
/* - RESET_ATTR_ASYNC() - Asynchronous reset support                        */
/* - RESET_ATTR_NOTIFICATIONS() - Reset notifications support               */
/* - RESET_ATTR_EXT_NAME() - Extended reset domain name                     */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid reset domain attributes were returned.        */
/* - SM_ERR_NOT_FOUND: if domainId pertains to a non-existent domain.       */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ResetDomainAttributes(const scmi_caller_t *caller,
    const msg_rreset3_t *in, msg_treset3_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    const uint8_t *nameAddr = (const uint8_t*) "";

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_RESET))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get the domain name */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_ResetDomainNameGet(caller->lmId, in->domainId,
            (string*) &nameAddr, NULL);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        /* Sync responses only, no notificaions */
        out->attributes
            = RESET_ATTR_ASYNC(0UL)
            | RESET_ATTR_NOTIFICATIONS(0UL)
            | RESET_ATTR_EXT_NAME(0UL);

        /* Latency not supported */
        out->latency = 0xFFFFFFFFU;

        /* Copy out name */
        RPC_SCMI_StrCpy(out->name, nameAddr, RESET_MAX_NAME);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset domain                                                             */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the reset domain                          */
/* - in->flags: Reset flags:                                                */
/*   This parameter allows the agent to specify additional conditions and   */
/*   requirements specific to the request, and has the following format:    */
/*   Bits[31:3] Reserved, must be zero.                                     */
/*   Bit[2] Async flag. Only valid if Bit[0] is set to 1.                   */
/*   Set to 1 if the reset must complete asynchronously.                    */
/*   Set to 0 if the reset must complete synchronously.                     */
/*   Bit[1] Explicit signal. This flag is ignored when Bit[0] is set to 1.  */
/*   Set to 1 to explicitly assert reset signal.                            */
/*   Set to 0 to explicitly de-assert reset signal.                         */
/*   Bit[0] Autonomous Reset action.                                        */
/*   Set to 1 if the reset must be performed autonomously by the platform.  */
/*   Set to 0 if the reset signal shall be explicitly asserted and          */
/*   de-asserted by the caller                                              */
/* - in->resetState: The reset state being requested. The format of this    */
/*   parameter is specified in Table 19                                     */
/*                                                                          */
/* Process the RESET message. Platform handler for SCMI_Reset(). Requires   */
/* access greater than or equal to EXCLUSIVE. See section 4.8.2.6 in the    */
/* SCMI spec.                                                               */
/*                                                                          */
/*  Access macros:                                                          */
/* - RESET_FLAGS_ASYNC() - Async flag                                       */
/* - RESET_FLAGS_SIGNAL() - Explicit signal                                 */
/* - RESET_FLAGS_AUTO() - Autonomous Reset action                           */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the operation was successful.                       */
/* - SM_ERR_NOT_FOUND: if the reset domain identified by domainId does      */
/*   not exist.                                                             */
/* - SM_ERR_INVALID_PARAMETERS: if an illegal or unsupported reset state    */
/*   is specified or if the flags field is invalid.                         */
/* - SM_ERR_GENERIC_ERROR: if the operation failed, for example if there    */
/*   are other active users of the reset domain.                            */
/* - SM_ERR_DENIED: if the calling agent is not allowed to reset the        */
/*   specified reset domain.                                                */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t Reset(const scmi_caller_t *caller, const msg_rreset4_t *in,
    const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    uint8_t lmmState = DEV_SM_RST_COLD;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_RESET))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].rstPerms[in->domainId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Check async flag */
    if (status == SM_ERR_SUCCESS)
    {
        bool async = (RESET_FLAGS_ASYNC(in->flags) != 0U);

        if (async)
        {
            status = SM_ERR_INVALID_PARAMETERS;
        }
    }

    /* Check and translate resets */
    if (status == SM_ERR_SUCCESS)
    {
        bool arch = RESET_STATE_ARCH(in->resetState) == 0U;

        if (arch)
        {
            switch (in->resetState)
            {
                case RESET_ARCH_COLD:
                    lmmState = DEV_SM_RST_COLD;
                    break;
                default:
                    status = SM_ERR_INVALID_PARAMETERS;
                    break;
            }
        }
        else
        {
            lmmState = ((uint8_t) (in->resetState & 0x7FFFFFFFU));
        }
    }

    /* Request reset */
    if (status == SM_ERR_SUCCESS)
    {
        bool autonomous = (RESET_FLAGS_AUTO(in->flags) != 0U);
        bool assertNegate = (RESET_FLAGS_SIGNAL(in->flags) != 0U);

        status = LMM_ResetDomain(caller->lmId, in->domainId, lmmState,
            autonomous, assertNegate);
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
/* SCMI_ResetNegotiateProtocolVersion(). See section 4.8.2.2 in the SCMI    */
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
static int32_t ResetNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rreset16_t *in, const scmi_msg_status_t *out)
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
/* Reset agent configuration                                                */
/*                                                                          */
/* Parameters:                                                              */
/* - lmId: LM to reset                                                      */
/* - agentId: Message ID to dispatch                                        */
/* - permissionsReset: True to reset permissions                            */
/*--------------------------------------------------------------------------*/
static int32_t ResetResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

