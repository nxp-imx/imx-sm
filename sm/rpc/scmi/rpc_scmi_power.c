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
/* Interface (SCMI) power protocol.                                         */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x30001U

/* SCMI power protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION             0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES          0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES  0x2U
#define COMMAND_POWER_DOMAIN_ATTRIBUTES      0x3U
#define COMMAND_POWER_STATE_SET              0x4U
#define COMMAND_POWER_STATE_GET              0x5U
#define COMMAND_NEGOTIATE_PROTOCOL_VERSION   0x10U
#define COMMAND_SUPPORTED_MASK               0x1003FULL

/* SCMI max power argument lengths */
#define POWER_MAX_NAME  16U

/* SCMI power domain states */
#define POWER_DOMAIN_STATE_ON   0x00000000U
#define POWER_DOMAIN_STATE_OFF  0x40000000U

/* Local macros */

/* SCMI power protocol attributes */
#define POWER_PROTO_ATTR_NUM_DOMAINS(x)  (((x) & 0xFFFFU) << 0U)

/* SCMI power domain attributes */
#define POWER_ATTR_CHANGE(x)      (((x) & 0x1U) << 31U)
#define POWER_ATTR_ASYNC(x)       (((x) & 0x1U) << 30U)
#define POWER_ATTR_SYNC(x)        (((x) & 0x1U) << 29U)
#define POWER_ATTR_CHANGE_REQ(x)  (((x) & 0x1U) << 28U)
#define POWER_ATTR_EXT_NAME(x)    (((x) & 0x1U) << 27U)

/* SCMI power state set flags */
#define POWER_FLAGS_ASYNC(x)  (((x) & 0x1U) >> 0U)

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
} msg_tpower0_t;

/* Response type for ProtocolAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol attributes */
    uint32_t attributes;
    /* Low address */
    uint32_t statisticsAddressLow;
    /* High address */
    uint32_t statisticsAddressHigh;
    /* The length in bytes of the statistics shared memory region */
    uint32_t statisticsLen;
} msg_tpower1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rpower2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_tpower2_t;

/* Request type for PowerDomainAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the domain */
    uint32_t domainId;
} msg_rpower3_t;

/* Response type for PowerDomainAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Domain attributes */
    uint32_t attributes;
    /* ASCII name string */
    uint8_t name[POWER_MAX_NAME];
} msg_tpower3_t;

/* Request type for PowerStateSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Power set flags */
    uint32_t flags;
    /* Identifier for the power domain */
    uint32_t domainId;
    /* Parameter identifying the power state of the domain */
    uint32_t powerState;
} msg_rpower4_t;

/* Request type for PowerStateGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the power domain */
    uint32_t domainId;
} msg_rpower5_t;

/* Response type for PowerStateGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Parameter identifying the power state of the domain */
    uint32_t powerState;
} msg_tpower5_t;

/* Request type for NegotiateProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* The negotiated protocol version the agent intends to use */
    uint32_t version;
} msg_rpower16_t;

/* Local functions */

static int32_t PowerProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tpower0_t *out);
static int32_t PowerProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tpower1_t *out);
static int32_t PowerProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rpower2_t *in, msg_tpower2_t *out);
static int32_t PowerDomainAttributes(const scmi_caller_t *caller,
    const msg_rpower3_t *in, msg_tpower3_t *out);
static int32_t PowerStateSet(const scmi_caller_t *caller,
    const msg_rpower4_t *in, const scmi_msg_status_t *out);
static int32_t PowerStateGet(const scmi_caller_t *caller,
    const msg_rpower5_t *in, msg_tpower5_t *out);
static int32_t PowerNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rpower16_t *in, const scmi_msg_status_t *out);
static int32_t PowerResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_PowerDispatchCommand(scmi_caller_t *caller,
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
            lenOut = sizeof(msg_tpower0_t);
            status = PowerProtocolVersion(caller,
                (const scmi_msg_header_t*) in, (msg_tpower0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tpower1_t);
            status = PowerProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tpower1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tpower2_t);
            status = PowerProtocolMessageAttributes(caller,
                (const msg_rpower2_t*) in, (msg_tpower2_t*) out);
            break;
        case COMMAND_POWER_DOMAIN_ATTRIBUTES:
            lenOut = sizeof(msg_tpower3_t);
            status = PowerDomainAttributes(caller, (const msg_rpower3_t*) in,
                (msg_tpower3_t*) out);
            break;
        case COMMAND_POWER_STATE_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = PowerStateSet(caller, (const msg_rpower4_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_POWER_STATE_GET:
            lenOut = sizeof(msg_tpower5_t);
            status = PowerStateGet(caller, (const msg_rpower5_t*) in,
                (msg_tpower5_t*) out);
            break;
        case COMMAND_NEGOTIATE_PROTOCOL_VERSION:
            lenOut = sizeof(const scmi_msg_status_t);
            status = PowerNegotiateProtocolVersion(caller,
                (const msg_rpower16_t*) in, (const scmi_msg_status_t*) out);
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
int32_t RPC_SCMI_PowerDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return PowerResetAgentConfig(lmId, agentId, permissionsReset);
}

/*==========================================================================*/
/* Custom Protocol Implementation                                           */
/*==========================================================================*/

/* Local variables */

static uint8_t s_powerState[SM_NUM_POWER][SM_SCMI_NUM_AGNT];

/* Local functions */

static int32_t PowerStateUpdate(uint32_t lmId, uint32_t agentId,
    uint32_t domainId, uint32_t powerState);

/*--------------------------------------------------------------------------*/
/* Get protocol version                                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->version: Protocol version. For this revision of the               */
/*   specification, this value must be 0x30001                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_PowerProtocolVersion(). See section 4.3.2.1 in the SCMI spec.       */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PowerProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tpower0_t *out)
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
/*   Bits[15:0] Number of power domains                                     */
/* - out->statisticsAddressLow: Low address: The lower 32 bits of the       */
/*   physical address where the statistics shared memory region is located  */
/* - out->statisticsAddressHigh: High address: The upper 32 bits of the     */
/*   physical address where the statistics shared memory region is located  */
/* - out->statisticsLen: The length in bytes of the statistics shared       */
/*   memory region. A value of 0 in this field indicates that the platform  */
/*   does not support the statistics shared memory region                   */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_PowerProtocolAttributes(). See section 4.3.2.3 in the SCMI spec.    */
/*                                                                          */
/*  Access macros:                                                          */
/* - POWER_PROTO_ATTR_NUM_DOMAINS() - Number of power domains               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PowerProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tpower1_t *out)
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
        /* Return number of domains */
        out->attributes = POWER_PROTO_ATTR_NUM_DOMAINS(SM_NUM_POWER);

        /* Statistics not supported */
        out->statisticsAddressLow = 0U;
        out->statisticsAddressHigh = 0U;
        out->statisticsLen = 0U;
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
/* SCMI_PowerProtocolMessageAttributes(). See section 4.3.2.4 in the SCMI   */
/* spec.                                                                    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is invalid    */
/*   or not implemented.                                                    */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PowerProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rpower2_t *in, msg_tpower2_t *out)
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
        uint64_t mask = COMMAND_SUPPORTED_MASK;

        /* Always zero */
        out->attributes = 0U;

        /* Is message supported ? */
        if ((in->messageId >= 64U)
            || (((mask >> in->messageId) & 0x1ULL) == 0ULL))
        {
            status = SM_ERR_NOT_FOUND;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get power domain attributes                                              */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the domain. Domain identifiers are        */
/*   limited to 16 bits, and the upper 16 bits of this field are ignored    */
/*   by the platform                                                        */
/* - out->attributes: Domain attributes:                                    */
/*   Bit[31] Power state change notifications support.                      */
/*   Set to 1 if power state change notifications are supported on this     */
/*   domain.                                                                */
/*   Set to 0 if power state change notifications are not supported on      */
/*   this domain.                                                           */
/*   Bit[30] Power state asynchronous support.                              */
/*   Set to 1 if power state can be set asynchronously.                     */
/*   Set to 0 if power state cannot be set asynchronously.                  */
/*   Bit[29] Power state synchronous support.                               */
/*   Set to 1 if power state can be set synchronously.                      */
/*   Set to 0 if power state cannot be set synchronously.                   */
/*   Bit[28] Power state change requested notifications support.            */
/*   Set to 1 if power state change requested notifications are supported   */
/*   on this domain.                                                        */
/*   Set to 0 if power state change requested notifications are not         */
/*   supported on this domain.                                              */
/*   Bit[27] Extended power domain name.                                    */
/*   If set to 1, the power domain name is greater than 16 bytes.           */
/*   If set to 0, extended power domain name is not supported               */
/* - out->name: Null-terminated ASCII string of up to 16 bytes in length    */
/*   describing the power domain name. When Bit[27] of attributes field is  */
/*   set to 1, this field returns the NULL terminated lower 15 bytes of     */
/*   the power domain name                                                  */
/*                                                                          */
/* Process the POWER_DOMAIN_ATTRIBUTES message. Platform handler for        */
/* SCMI_PowerDomainAttributes(). See section 4.3.2.5 in the SCMI spec.      */
/*                                                                          */
/*  Access macros:                                                          */
/* - POWER_ATTR_CHANGE() - Power state change notifications support         */
/* - POWER_ATTR_ASYNC() - Power state asynchronous support                  */
/* - POWER_ATTR_SYNC() - Power state synchronous support                    */
/* - POWER_ATTR_CHANGE_REQ() - Power state change requested notifications   */
/*   support                                                                */
/* - POWER_ATTR_EXT_NAME() - Extended power domain name                     */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid power domain attributes are returned.         */
/* - SM_ERR_NOT_FOUND: if domainId pertains to a non-existent domain.       */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PowerDomainAttributes(const scmi_caller_t *caller,
    const msg_rpower3_t *in, msg_tpower3_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    const uint8_t *nameAddr = (const uint8_t*) "";

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_POWER))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get the domain name */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_PowerDomainNameGet(caller->lmId, in->domainId,
            (string*) &nameAddr, NULL);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        /* Sync responses only, no notificaions */
        out->attributes
            = POWER_ATTR_CHANGE(0UL)
            | POWER_ATTR_ASYNC(0UL)
            | POWER_ATTR_SYNC(0UL)
            | POWER_ATTR_CHANGE_REQ(0UL)
            | POWER_ATTR_EXT_NAME(0UL);

        /* Adjust based on access */
        if (g_scmiAgentConfig[caller->agentId].pdPerms[in->domainId]
            >= SM_SCMI_PERM_SET)
        {
            out->attributes |= POWER_ATTR_SYNC(1UL);
        }

        /* Copy out name */
        RPC_SCMI_StrCpy(out->name, nameAddr, POWER_MAX_NAME);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set power state                                                          */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->flags: Power set flags:                                            */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Async flag.                                                     */
/*   Set to 1 if power transition must be done asynchronously.              */
/*   Set to 0 if power state transition must be done synchronously.         */
/*   The async flag is ignored for application processor domains            */
/* - in->domainId: Identifier for the power domain                          */
/* - in->powerState: Parameter identifying the power state of the domain.   */
/*   Note platform-specific                                                 */
/*                                                                          */
/* Process the POWER_STATE_SET message. Platform handler for                */
/* SCMI_PowerStateSet(). Requires access greater than or equal to SET. See  */
/* section 4.3.2.6 in the SCMI spec.                                        */
/*                                                                          */
/*  Access macros:                                                          */
/* - POWER_FLAGS_ASYNC() - Async flag                                       */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: for a power domain that can only be set                */
/*   synchronously, this status is returned after the power domain has      */
/*   transitioned to the desired state. For a power domain that is managed  */
/*   asynchronously, this status is returned if the function parameters     */
/*   are valid, and the power state change has been scheduled.              */
/* - SM_ERR_NOT_FOUND: if the power domain identified by domainId does      */
/*   not exist.                                                             */
/* - SM_ERR_INVALID_PARAMETERS: if the requested power state does not       */
/*   represent a valid state for the power domain that is identified by     */
/*   domainId.                                                              */
/* - SM_ERR_NOT_SUPPORTED: if the request is not supported.                 */
/* - SM_ERR_DENIED: if the calling agent is not allowed to set the state    */
/*   of this power domain. An example would be if this power domain is      */
/*   exclusive to another agent.                                            */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PowerStateSet(const scmi_caller_t *caller,
    const msg_rpower4_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool async = POWER_FLAGS_ASYNC(in->flags) != 0U;
    uint32_t agentId = caller->agentId;
    uint8_t state = DEV_SM_POWER_STATE_OFF;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_POWER))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[agentId].pdPerms[in->domainId]
        < SM_SCMI_PERM_SET))
    {
        status = SM_ERR_DENIED;
    }

    /* Check for async request */
    if ((status == SM_ERR_SUCCESS) && async)
    {
        /* Support sync only */
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check and translate to device power states as easier to track */
    if (status == SM_ERR_SUCCESS)
    {
        switch (in->powerState)
        {
            case POWER_DOMAIN_STATE_OFF:
                state = DEV_SM_POWER_STATE_OFF;
                break;
            case POWER_DOMAIN_STATE_ON:
                state = DEV_SM_POWER_STATE_ON;
                break;
            default:
                state = (uint8_t) (in->powerState & ~((uint32_t)
                    POWER_DOMAIN_STATE_OFF));
                break;
        }

        /* Update tracking */
        status = PowerStateUpdate(caller->lmId, agentId, in->domainId,
            state);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get power state                                                          */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the power domain                          */
/* - out->powerState: Parameter identifying the power state of the domain.  */
/*   Note platform-specific                                                 */
/*                                                                          */
/* Process the POWER_STATE_GET message. Platform handler for                */
/* SCMI_PowerStateGet(). See section 4.3.2.7 in the SCMI spec.              */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the current power state is returned successfully.   */
/* - SM_ERR_NOT_FOUND: if domainId does not point to a valid power          */
/*   domain.                                                                */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PowerStateGet(const scmi_caller_t *caller,
    const msg_rpower5_t *in, msg_tpower5_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    uint8_t state;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_POWER))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get the LMM power state */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_PowerStateGet(caller->lmId, in->domainId, &state);
    }

    /* Translate to SCMI power state */
    if (status == SM_ERR_SUCCESS)
    {
        switch (state)
        {
            case DEV_SM_POWER_STATE_OFF:
                out->powerState = POWER_DOMAIN_STATE_OFF;
                break;
            case DEV_SM_POWER_STATE_ON:
                out->powerState = POWER_DOMAIN_STATE_ON;
                break;
            default:
                out->powerState = state;
                break;
        }
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
/* SCMI_PowerNegotiateProtocolVersion(). See section 4.3.2.2 in the SCMI    */
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
static int32_t PowerNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rpower16_t *in, const scmi_msg_status_t *out)
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
static int32_t PowerResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all power domains */
    for (uint32_t domainId = 0U; domainId < SM_NUM_POWER; domainId++)
    {
        /* Turn off power */
        if (s_powerState[domainId][agentId] != DEV_SM_POWER_STATE_OFF)
        {
            (void) PowerStateUpdate(lmId, agentId, domainId,
                DEV_SM_POWER_STATE_OFF);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Aggregate and update the power state                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - lmId: LM to update                                                     */
/* - agentId: Message to update                                             */
/* - domainId: Voltage domain                                               */
/* - powerState: New power state                                            */
/*--------------------------------------------------------------------------*/
static int32_t PowerStateUpdate(uint32_t lmId, uint32_t agentId,
    uint32_t domainId, uint32_t powerState)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check power state */
    if (powerState >= SM_NUM_POWER_STATE)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }
    else
    {
        uint32_t scmiInst = g_scmiAgentConfig[agentId].scmiInst;
        uint32_t firstAgent = g_scmiConfig[scmiInst].firstAgent;
        uint32_t numAgents = g_scmiConfig[scmiInst].numAgents;

        uint8_t maxPowerState = DEV_SM_POWER_STATE_OFF;

        /* Record agent power state for this domain */
        s_powerState[domainId][agentId] = (uint8_t) powerState;

        /* Calculate new aggregate state for the domain */
        for (uint32_t a = firstAgent; a < (firstAgent + numAgents); a++)
        {
            /* Keep max state */
            if (s_powerState[domainId][a] > maxPowerState)
            {
                maxPowerState = s_powerState[domainId][a];
            }
        }

        /* Inform LMM of power state, LMM will check if changed */
        status = LMM_PowerStateSet(lmId, domainId, maxPowerState);
    }

    /* Return status */
    return status;
}

