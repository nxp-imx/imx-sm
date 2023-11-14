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
/* Interface (SCMI) base protocol.                                          */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x20000U

/* SCMI base protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION                      0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES                   0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES           0x2U
#define COMMAND_BASE_DISCOVER_VENDOR                  0x3U
#define COMMAND_BASE_DISCOVER_SUB_VENDOR              0x4U
#define COMMAND_BASE_DISCOVER_IMPLEMENTATION_VERSION  0x5U
#define COMMAND_BASE_DISCOVER_LIST_PROTOCOLS          0x6U
#define COMMAND_BASE_DISCOVER_AGENT                   0x7U
#define COMMAND_BASE_SET_DEVICE_PERMISSIONS           0x9U
#define COMMAND_BASE_RESET_AGENT_CONFIGURATION        0xBU
#define COMMAND_SUPPORTED_MASK                        0xAFFUL

/* SCMI max base argument lengths */
#define BASE_MAX_NAME              16U
#define BASE_MAX_VENDORIDENTIFIER  16U
#define BASE_MAX_PROTOCOLS         SCMI_ARRAY(8U, uint32_t)

/* SCMI agent ID */
#define BASE_ID_DISCOVER  0xFFFFFFFFU

/* Local macros */

/* SCMI power protocol attributes */
#define BASE_PROTO_ATTR_NUM_AGENTS(x)     (((x) & 0xFFU) << 8U)
#define BASE_PROTO_ATTR_NUM_PROTOCOLS(x)  (((x) & 0xFFU) << 0U)

/* SCMI base device permission flags */
#define BASE_PERM_FLAGS_ACCESS_TYPE(x)  (((x) & 0x1U) >> 0U)

/* SCMI base reset agents flags */
#define BASE_FLAGS_PERMISSIONS(x)  (((x) & 0x1U) >> 0U)

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
} msg_tbase0_t;

/* Response type for ProtocolAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol attributes */
    uint32_t attributes;
} msg_tbase1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rbase2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_tbase2_t;

/* Response type for BaseDiscoverVendor() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* ASCII name string */
    uint8_t vendorIdentifier[BASE_MAX_VENDORIDENTIFIER];
} msg_tbase3_t;

/* Response type for BaseDiscoverSubVendor() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* ASCII name string */
    uint8_t vendorIdentifier[BASE_MAX_VENDORIDENTIFIER];
} msg_tbase4_t;

/* Response type for BaseDiscoverImplementationVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Build number from git */
    uint32_t implementationVersion;
} msg_tbase5_t;

/* Request type for BaseDiscoverListProtocols() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Number of protocols to skip */
    uint32_t skip;
} msg_rbase6_t;

/* Response type for BaseDiscoverListProtocols() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Number of protocols that are returned by this call */
    uint32_t numProtocols;
    /* Array of protocol identifiers */
    uint32_t protocols[BASE_MAX_PROTOCOLS];
} msg_tbase6_t;

/* Request type for BaseDiscoverAgent() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier of the agent whose identification is requested */
    uint32_t agentId;
} msg_rbase7_t;

/* Response type for BaseDiscoverAgent() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Identifier of the agent whose identification is requested */
    uint32_t agentId;
    /* ASCII name string */
    uint8_t name[BASE_MAX_NAME];
} msg_tbase7_t;

/* Request type for BaseSetDevicePermissions() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier of the Agent */
    uint32_t agentId;
    /* Identifier of the device */
    uint32_t deviceId;
    /* Device permission flags */
    uint32_t flags;
} msg_rbase9_t;

/* Request type for BaseResetAgentConfiguration() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier of the Agent */
    uint32_t agentId;
    /* Reset agent flags */
    uint32_t flags;
} msg_rbase11_t;

/* Local functions */

static int32_t BaseProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbase0_t *out);
static int32_t BaseProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbase1_t *out);
static int32_t BaseProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rbase2_t *in, msg_tbase2_t *out);
static int32_t BaseDiscoverVendor(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbase3_t *out);
static int32_t BaseDiscoverSubVendor(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbase4_t *out);
static int32_t BaseDiscoverImplementationVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbase5_t *out);
static int32_t BaseDiscoverListProtocols(const scmi_caller_t *caller,
    const msg_rbase6_t *in, msg_tbase6_t *out, uint32_t *len);
static int32_t BaseDiscoverAgent(const scmi_caller_t *caller,
    const msg_rbase7_t *in, msg_tbase7_t *out);
static int32_t BaseSetDevicePermissions(const scmi_caller_t *caller,
    const msg_rbase9_t *in, const scmi_msg_status_t *out);
static int32_t BaseResetAgentConfiguration(const scmi_caller_t *caller,
    const msg_rbase11_t *in, const scmi_msg_status_t *out);
static int32_t BaseResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_BaseDispatchCommand(scmi_caller_t *caller,
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
            lenOut = sizeof(msg_tbase0_t);
            status = BaseProtocolVersion(caller,
                (const scmi_msg_header_t*) in, (msg_tbase0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tbase1_t);
            status = BaseProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tbase1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tbase2_t);
            status = BaseProtocolMessageAttributes(caller,
                (const msg_rbase2_t*) in, (msg_tbase2_t*) out);
            break;
        case COMMAND_BASE_DISCOVER_VENDOR:
            lenOut = sizeof(msg_tbase3_t);
            status = BaseDiscoverVendor(caller, (const scmi_msg_header_t*) in,
                (msg_tbase3_t*) out);
            break;
        case COMMAND_BASE_DISCOVER_SUB_VENDOR:
            lenOut = sizeof(msg_tbase4_t);
            status = BaseDiscoverSubVendor(caller,
                (const scmi_msg_header_t*) in, (msg_tbase4_t*) out);
            break;
        case COMMAND_BASE_DISCOVER_IMPLEMENTATION_VERSION:
            lenOut = sizeof(msg_tbase5_t);
            status = BaseDiscoverImplementationVersion(caller,
                (const scmi_msg_header_t*) in, (msg_tbase5_t*) out);
            break;
        case COMMAND_BASE_DISCOVER_LIST_PROTOCOLS:
            lenOut = sizeof(msg_tbase6_t);
            status = BaseDiscoverListProtocols(caller,
                (const msg_rbase6_t*) in, (msg_tbase6_t*) out, &lenOut);
            break;
        case COMMAND_BASE_DISCOVER_AGENT:
            lenOut = sizeof(msg_tbase7_t);
            status = BaseDiscoverAgent(caller, (const msg_rbase7_t*) in,
                (msg_tbase7_t*) out);
            break;
        case COMMAND_BASE_SET_DEVICE_PERMISSIONS:
            lenOut = sizeof(const scmi_msg_status_t);
            status = BaseSetDevicePermissions(caller,
                (const msg_rbase9_t*) in, (const scmi_msg_status_t*) out);
            break;
        case COMMAND_BASE_RESET_AGENT_CONFIGURATION:
            lenOut = sizeof(const scmi_msg_status_t);
            status = BaseResetAgentConfiguration(caller,
                (const msg_rbase11_t*) in, (const scmi_msg_status_t*) out);
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
int32_t RPC_SCMI_BaseDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return BaseResetAgentConfig(lmId, agentId, permissionsReset);
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
/*   specification, this value must be 0x20000                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_BaseProtocolVersion(). See section 4.2.2.1 in the SCMI spec.        */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BaseProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbase0_t *out)
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
/*   Bits[15:8] Number of agents in the system.                             */
/*   Bits[7:0] Number of protocols that are implemented, excluding the      */
/*   Base protocol                                                          */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_BaseProtocolAttributes(). See section 4.2.2.2 in the SCMI spec.     */
/*                                                                          */
/*  Access macros:                                                          */
/* - BASE_PROTO_ATTR_NUM_AGENTS() - Number of agents in the system          */
/* - BASE_PROTO_ATTR_NUM_PROTOCOLS() - Number of protocols that are         */
/*   implemented, excluding the Base protocol                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BaseProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbase1_t *out)
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
        out->attributes
            = BASE_PROTO_ATTR_NUM_AGENTS(((uint32_t) g_scmiConfig[
                caller->scmiInst].numAgents))
            | BASE_PROTO_ATTR_NUM_PROTOCOLS(RPC_SCMI_NumProtocolsGet()
                - 1U);
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
/* SCMI_BaseProtocolMessageAttributes(). See section 4.2.2.3 in the SCMI    */
/* spec.                                                                    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is not        */
/*   provided by this platform implementation.                              */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BaseProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rbase2_t *in, msg_tbase2_t *out)
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
/* Get vendor identifier                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->vendorIdentifier: Null terminated ASCII string of up to 16 bytes  */
/*   with a vendor name                                                     */
/*                                                                          */
/* Process the BASE_DISCOVER_VENDOR message. Platform handler for           */
/* SCMI_BaseDiscoverVendor(). See section 4.2.2.4 in the SCMI spec.         */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BaseDiscoverVendor(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbase3_t *out)
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
        /* Copy out vendor identifier */
        RPC_SCMI_StrCpy(out->vendorIdentifier, (const uint8_t *)
            SCMI_VENDOR, BASE_MAX_VENDORIDENTIFIER);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get sub-vendor identifier                                                */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->vendorIdentifier: Null terminated ASCII string of up to 16 bytes  */
/*   with a sub-vendor name                                                 */
/*                                                                          */
/* Process the BASE_DISCOVER_SUB_VENDOR message. Platform handler for       */
/* SCMI_BaseDiscoverSubVendor(). See section 4.2.2.5 in the SCMI spec.      */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BaseDiscoverSubVendor(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbase4_t *out)
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
        /* Copy out sub vendor identifier */
        RPC_SCMI_StrCpy(out->vendorIdentifier,
            (const uint8_t *) SCMI_SUB_VENDOR, BASE_MAX_VENDORIDENTIFIER);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get implementation version                                               */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->implementationVersion: Build number from git                      */
/*                                                                          */
/* Process the BASE_DISCOVER_IMPLEMENTATION_VERSION message. Platform       */
/* handler for SCMI_BaseDiscoverImplementationVersion(). See section        */
/* 4.2.2.6 in the SCMI spec.                                                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BaseDiscoverImplementationVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tbase5_t *out)
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
        out->implementationVersion = SM_BUILD;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Discover protocols                                                       */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->skip: Number of protocols to skip                                  */
/* - out->numProtocols: Number of protocols that are returned by this call  */
/* - out->protocols: Array of protocol identifiers. Listed are those        */
/*   implemented, excluding the base protocol, with four protocol           */
/*   identifiers packed into each array element                             */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the BASE_DISCOVER_LIST_PROTOCOLS message. Platform handler for   */
/* SCMI_BaseDiscoverListProtocols(). See section 4.2.2.7 in the SCMI spec.  */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if a valid list of protocols is found.                 */
/* - SM_ERR_INVALID_PARAMETERS: if skip field is invalid.                   */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BaseDiscoverListProtocols(const scmi_caller_t *caller,
    const msg_rbase6_t *in, msg_tbase6_t *out, uint32_t *len)
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
        /* Get compressed list of protocols excluding base */
        status = RPC_SCMI_ProtocolListGet(in->skip + 1U,
            BASE_MAX_PROTOCOLS, &(out->numProtocols), out->protocols);
    }

    /* Update length */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t newLen = out->numProtocols;

        if (newLen != 0U)
        {
            newLen = (((newLen - 1U) / 4U) + 1U) * 4U;
        }

        /* Array plus size of header, status, and numProtocols */
        *len = newLen + (3U * sizeof(uint32_t));
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get agent information                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->agentId: Identifier of the agent whose identification is           */
/*   requested                                                              */
/* - out->agentId: Identifier of the agent whose identification is          */
/*   requested. This field is:                                              */
/*   - populated with the agent ID of the calling agent, when the \a        */
/*   agentId parameter passed via the function is 0xFFFFFFFF.               */
/*   - identical to the agentId field passed via the calling                */
/*   parameters, in all other cases                                         */
/* - out->name: Null terminated ASCII string of up to 16 bytes in length    */
/*                                                                          */
/* Process the BASE_DISCOVER_AGENT message. Platform handler for            */
/* SCMI_BaseDiscoverAgent(). See section 4.2.2.8 in the SCMI spec.          */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: If a valid agent identifier is found.                  */
/* - SM_ERR_NOT_FOUND: if agentId does not point to a valid agent.          */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BaseDiscoverAgent(const scmi_caller_t *caller,
    const msg_rbase7_t *in, msg_tbase7_t *out)
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
        /* Self discovery */
        if (in->agentId != BASE_ID_DISCOVER)
        {
            out->agentId = in->agentId;
        }
        else
        {
            out->agentId = caller->instAgentId;
        }

        /* Check agent */
        if ((out->agentId > SM_SCMI_NUM_AGNT)
            || (out->agentId > g_scmiConfig[caller->scmiInst].numAgents))
        {
            status = SM_ERR_NOT_FOUND;
        }
    }

    /* Copy out agent name */
    if (status == SM_ERR_SUCCESS)
    {
        if (out->agentId == 0U)
        {
            RPC_SCMI_StrCpy(out->name, (const uint8_t*)
                "platform", BASE_MAX_NAME);
        }
        else
        {
            uint32_t agent = out->agentId - 1U
                + g_scmiConfig[caller->scmiInst].firstAgent;

            RPC_SCMI_StrCpy(out->name, (const uint8_t*)
                g_scmiAgentConfig[agent].name, BASE_MAX_NAME);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set device permissions                                                   */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->agentId: Identifier of the Agent                                   */
/* - in->deviceId: Identifier of the device                                 */
/* - in->flags: Device permission flags:                                    */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Access Type:                                                    */
/*   This bit defines the permissions of the agent to access platform       */
/*   resources associated with the device.                                  */
/*   If set to 0, deny agent access to the device.                          */
/*   If set to 1, allow agent access to the device                          */
/*                                                                          */
/* Process the BASE_SET_DEVICE_PERMISSIONS message. Platform handler for    */
/* SCMI_BaseSetDevicePermissions(). Requires access greater than or equal   */
/* to PRIV. See section 4.2.2.10 in the SCMI spec.                          */
/*                                                                          */
/*  Access macros:                                                          */
/* - BASE_PERM_FLAGS_ACCESS_TYPE() - Access Type                            */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the device permissions was set successfully    */
/*   for the agent specified by agentId.                                    */
/* - SM_ERR_NOT_FOUND: if agentId or deviceId does not exist.               */
/* - SM_ERR_INVALID_PARAMETERS: if flags is invalid.                        */
/* - SM_ERR_NOT_SUPPORTED: if the function is not supported.                */
/* - SM_ERR_DENIED: if the calling agent is not allowed to set the          */
/*   permissions of the agent specified by agentId.                         */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BaseSetDevicePermissions(const scmi_caller_t *caller,
    const msg_rbase9_t *in, const scmi_msg_status_t *out)
{
#if SM_NUM_DEVICE > 0
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Return data */
    if (status == SM_ERR_SUCCESS)
    {
        bool allow = BASE_PERM_FLAGS_ACCESS_TYPE(in->flags) != 0U;

        /* Check agent */
        if ((in->agentId == 0U)
            || (in->agentId > SM_SCMI_NUM_AGNT)
            || (in->agentId > g_scmiConfig[caller->scmiInst].numAgents))
        {
            status = SM_ERR_NOT_FOUND;
        }
        else
        {
            uint32_t agent = in->agentId - 1U
                + g_scmiConfig[caller->scmiInst].firstAgent;
            uint8_t domId = g_scmiAgentConfig[agent].domId;
            bool secure = (g_scmiAgentConfig[agent].secure != 0U);

            /* Check device */
            if (in->deviceId >= SM_NUM_DEVICE)
            {
                status = SM_ERR_NOT_FOUND;
            }
            else
            {
                /* Check permissions */
                if (g_scmiAgentConfig[caller->agentId].basePerms[
                        in->deviceId + SM_NUM_AGENT] < SM_SCMI_PERM_PRIV)
                {
                    status = SM_ERR_DENIED;
                }
            }

            /* Call device permission function */
            if (status == SM_ERR_SUCCESS)
            {
                status = SM_RDCACCESSSET(in->deviceId, allow, domId,
                    secure);
            }
        }
    }
#else
    int32_t status = SM_ERR_NOT_SUPPORTED;
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset platform resource settings for an agent                            */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->agentId: Identifier of the Agent                                   */
/* - in->flags: Reset agent flags:                                          */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Permissions Reset:                                              */
/*   If set to 0, maintain all access permission settings of the agent.     */
/*   If set to 1, reset all access permission settings of the agent.        */
/*   This function must always reset the platform resource settings         */
/*   configured by the agent specified by agentId. Platform resource        */
/*   settings refer to Device, Power Domain, Performance Domain, Clocks,    */
/*   Sensors and other settings configured by the agent specified by \a     */
/*   agentId                                                                */
/*                                                                          */
/* Process the BASE_RESET_AGENT_CONFIGURATION message. Platform handler     */
/* for SCMI_BaseResetAgentConfiguration(). Requires access greater than or  */
/* equal to PRIV. See section 4.2.2.12 in the SCMI spec.                    */
/*                                                                          */
/*  Access macros:                                                          */
/* - BASE_FLAGS_PERMISSIONS() - Permissions Reset                           */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: If a valid agent identifier is found.                  */
/* - SM_ERR_NOT_FOUND: if agentId does not point to a valid agent.          */
/* - SM_ERR_DENIED: if the calling agent is not allowed to set the reset    */
/*   the agent specified by agentId.                                        */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t BaseResetAgentConfiguration(const scmi_caller_t *caller,
    const msg_rbase11_t *in, const scmi_msg_status_t *out)
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
        bool permissionsReset = BASE_FLAGS_PERMISSIONS(in->flags) != 0U;

        /* Check agent */
        if ((in->agentId == 0U)
            || (in->agentId > SM_SCMI_NUM_AGNT)
            || (in->agentId > g_scmiConfig[caller->scmiInst].numAgents))
        {
            status = SM_ERR_NOT_FOUND;
        }
        else
        {
            uint32_t agent = in->agentId - 1U
                + g_scmiConfig[caller->scmiInst].firstAgent;

            /* Check permissions */
            if (g_scmiAgentConfig[caller->agentId].basePerms[agent]
                < SM_SCMI_PERM_PRIV)
            {
                status = SM_ERR_DENIED;
            }

            /* Call base reset function */
            if (status == SM_ERR_SUCCESS)
            {
                status = BaseResetAgentConfig(caller->lmId, agent,
                    permissionsReset);
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
static int32_t BaseResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status;

#if SM_NUM_DEVICE > 0
    /* Reset device permissions */
    if (permissionsReset)
    {
        /* Loop over devices */
        for (uint32_t deviceId = 0U; deviceId < SM_NUM_DEVICE; deviceId++)
        {
            if (g_scmiAgentConfig[agentId].basePerms[deviceId
                + SM_NUM_AGENT] >= SM_SCMI_PERM_PRIV)
            {
                uint8_t domId = g_scmiAgentConfig[agentId].domId;
                bool secure = (g_scmiAgentConfig[agentId].secure != 0U);

                (void) SM_RDCACCESSSET(deviceId, false, domId,
                    secure);
            }
        }
    }
#endif

    /* Reset sensor protocol */
    status = RPC_SCMI_SensorDispatchReset(lmId, agentId,
        permissionsReset);

    /* Reset CPU protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_CpuDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Reset BBM protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_BbmDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Reset misc protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_MiscDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Reset performance protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_PerfDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Reset sys protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_SysDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Reset FuSa protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_FusaDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Reset voltage protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_VoltageDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Reset reset protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_ResetDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Reset clock protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_ClockDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Reset power protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_PowerDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Reset LMM protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_LmmDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Reset Pinctrl protocol */
    if (status == SM_ERR_SUCCESS)
    {
        status = RPC_SCMI_PinctrlDispatchReset(lmId, agentId,
            permissionsReset);
    }

    /* Return status */
    return status;
}

