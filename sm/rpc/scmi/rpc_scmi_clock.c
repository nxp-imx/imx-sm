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
/* Interface (SCMI) clock protocol.                                         */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x20001U

/* SCMI clock protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION             0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES          0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES  0x2U
#define COMMAND_CLOCK_ATTRIBUTES             0x3U
#define COMMAND_CLOCK_DESCRIBE_RATES         0x4U
#define COMMAND_CLOCK_RATE_SET               0x5U
#define COMMAND_CLOCK_RATE_GET               0x6U
#define COMMAND_CLOCK_CONFIG_SET             0x7U
#define COMMAND_CLOCK_CONFIG_GET             0xBU
#define COMMAND_CLOCK_POSSIBLE_PARENTS_GET   0xCU
#define COMMAND_CLOCK_PARENT_SET             0xDU
#define COMMAND_CLOCK_PARENT_GET             0xEU
#define COMMAND_CLOCK_GET_PERMISSIONS        0xFU
#define COMMAND_SUPPORTED_MASK               0xF8FFUL

/* SCMI max clock argument lengths */
#define CLOCK_MAX_NAME     16U
#define CLOCK_MAX_RATES    SCMI_ARRAY(8U, clock_rate_t)
#define CLOCK_MAX_PARENTS  SCMI_ARRAY(8U, uint32_t)

/* SCMI clock round options */
#define CLOCK_ROUND_DOWN  0U
#define CLOCK_ROUND_UP    1U
#define CLOCK_ROUND_AUTO  2U

/* Local macros */

/* SCMI clock protocol attributes */
#define CLOCK_PROTO_ATTR_MAX_PENDING(x)  (((x) & 0xFFU) << 16U)
#define CLOCK_PROTO_ATTR_NUM_CLOCKS(x)   (((x) & 0xFFFFU) << 0U)

/* SCMI clock attributes */
#define CLOCK_ATTR_CHANGE(x)      (((x) & 0x1U) << 31U)
#define CLOCK_ATTR_CHANGE_REQ(x)  (((x) & 0x1U) << 30U)
#define CLOCK_ATTR_EXT_NAME(x)    (((x) & 0x1U) << 29U)
#define CLOCK_ATTR_PARENT(x)      (((x) & 0x1U) << 28U)
#define CLOCK_ATTR_RESTRICTED(x)  (((x) & 0x1U) << 1U)
#define CLOCK_ATTR_ENABLED(x)     (((x) & 0x1U) << 0U)

/* SCMI clock num rate flags */
#define CLOCK_NUM_RATE_FLAGS_REMAING_RATES(x)  (((x) & 0xFFFFU) << 16U)
#define CLOCK_NUM_RATE_FLAGS_FORMAT(x)         (((x) & 0x1U) << 12U)
#define CLOCK_NUM_RATE_FLAGS_NUM_RATES(x)      (((x) & 0xFFFU) << 0U)

/* SCMI clock rate flags */
#define CLOCK_RATE_FLAGS_ROUND(x)    (((x) & 0xCU) >> 2U)
#define CLOCK_RATE_FLAGS_NO_RESP(x)  (((x) & 0x2U) >> 1U)
#define CLOCK_RATE_FLAGS_ASYNC(x)    (((x) & 0x1U) >> 0U)

/* SCMI clock config attributes */
#define CLOCK_CONFIG_SET_OEM(x)     (((x) & 0xFF0000U) >> 16U)
#define CLOCK_CONFIG_SET_ENABLE(x)  (((x) & 0x3U) >> 0U)

/* SCMI clock config get flags */
#define CLOCK_CONFIG_FLAGS_OEM(x)  (((x) & 0xFFU) >> 0U)

/* SCMI clock config */
#define CLOCK_CONFIG_GET_ENABLE(x)  (((x) & 0x1U) << 0U)

/* SCMI clock num rate flags */
#define CLOCK_NUM_PARENT_FLAGS_REMAING_PARENTS(x)  (((x) & 0xFFU) << 24U)
#define CLOCK_NUM_PARENT_FLAGS_NUM_PARENTS(x)      (((x) & 0xFFU) << 0U)

/* SCMI clock permissions */
#define CLOCK_PERM_STATE(x)   (((x) & 0x1U) << 31U)
#define CLOCK_PERM_PARENT(x)  (((x) & 0x1U) << 30U)
#define CLOCK_PERM_RATE(x)    (((x) & 0x1U) << 29U)

/* Local types */

/* SCMI clock rate */
typedef struct
{
    /* Lower 32 bits of the physical rate in Hertz */
    uint32_t lower;
    /* Upper 32 bits of the physical rate in Hertz */
    uint32_t upper;
} clock_rate_t;

/* Response type for ProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol version */
    uint32_t version;
} msg_tclock0_t;

/* Response type for ProtocolAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol attributes */
    uint32_t attributes;
} msg_tclock1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rclock2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_tclock2_t;

/* Request type for ClockAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the clock device */
    uint32_t clockId;
} msg_rclock3_t;

/* Response type for ClockAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Clock attributes */
    uint32_t attributes;
    /* ASCII name string */
    uint8_t name[CLOCK_MAX_NAME];
} msg_tclock3_t;

/* Request type for ClockDescribeRates() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the clock device */
    uint32_t clockId;
    /* Index to the first rate value */
    uint32_t rateIndex;
} msg_rclock4_t;

/* Response type for ClockDescribeRates() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Descriptor for the rates supported by this clock */
    uint32_t numRatesFlags;
    /* Rate array */
    clock_rate_t rates[CLOCK_MAX_RATES];
} msg_tclock4_t;

/* Request type for ClockRateSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Rate flags */
    uint32_t flags;
    /* Identifier for the clock device */
    uint32_t clockId;
    /* Clock rate */
    clock_rate_t rate;
} msg_rclock5_t;

/* Request type for ClockRateGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the clock device */
    uint32_t clockId;
} msg_rclock6_t;

/* Response type for ClockRateGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Clock rate */
    clock_rate_t rate;
} msg_tclock6_t;

/* Request type for ClockConfigSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the clock device */
    uint32_t clockId;
    /* Config attributes */
    uint32_t attributes;
    /* OEM specified configuration value */
    uint32_t oemConfigVal;
} msg_rclock7_t;

/* Request type for ClockConfigGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the clock device */
    uint32_t clockId;
    /* Config flags */
    uint32_t flags;
} msg_rclock11_t;

/* Response type for ClockConfigGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Reserved, must be zero */
    uint32_t attributes;
    /* Config */
    uint32_t config;
    /* OEM specified configuration value */
    uint32_t oemConfigVal;
} msg_tclock11_t;

/* Request type for ClockPossibleParentsGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the clock device */
    uint32_t clockId;
    /* The number of parents to skip over */
    uint32_t skipParents;
} msg_rclock12_t;

/* Response type for ClockPossibleParentsGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Descriptor for the possible parents for this clock */
    uint32_t numParentsFlags;
    /* Array of parents */
    uint32_t parents[CLOCK_MAX_PARENTS];
} msg_tclock12_t;

/* Request type for ClockParentSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the clock device */
    uint32_t clockId;
    /* Identifier for the parent */
    uint32_t parentId;
} msg_rclock13_t;

/* Request type for ClockParentGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the clock device */
    uint32_t clockId;
} msg_rclock14_t;

/* Response type for ClockParentGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Identifier for the parent */
    uint32_t parentId;
} msg_tclock14_t;

/* Request type for ClockGetPermissions() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the clock device */
    uint32_t clockId;
} msg_rclock15_t;

/* Response type for ClockGetPermissions() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Permissions */
    uint32_t permissions;
} msg_tclock15_t;

/* Local functions */

static int32_t ClockProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tclock0_t *out);
static int32_t ClockProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tclock1_t *out);
static int32_t ClockProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rclock2_t *in, msg_tclock2_t *out);
static int32_t ClockAttributes(const scmi_caller_t *caller,
    const msg_rclock3_t *in, msg_tclock3_t *out);
static int32_t ClockDescribeRates(const scmi_caller_t *caller,
    const msg_rclock4_t *in, msg_tclock4_t *out, uint32_t *len);
static int32_t ClockRateSet(const scmi_caller_t *caller,
    const msg_rclock5_t *in, const scmi_msg_status_t *out);
static int32_t ClockRateGet(const scmi_caller_t *caller,
    const msg_rclock6_t *in, msg_tclock6_t *out);
static int32_t ClockConfigSet(const scmi_caller_t *caller,
    const msg_rclock7_t *in, const scmi_msg_status_t *out);
static int32_t ClockConfigGet(const scmi_caller_t *caller,
    const msg_rclock11_t *in, msg_tclock11_t *out);
static int32_t ClockPossibleParentsGet(const scmi_caller_t *caller,
    const msg_rclock12_t *in, msg_tclock12_t *out, uint32_t *len);
static int32_t ClockParentSet(const scmi_caller_t *caller,
    const msg_rclock13_t *in, const scmi_msg_status_t *out);
static int32_t ClockParentGet(const scmi_caller_t *caller,
    const msg_rclock14_t *in, msg_tclock14_t *out);
static int32_t ClockGetPermissions(const scmi_caller_t *caller,
    const msg_rclock15_t *in, msg_tclock15_t *out);
static int32_t ClockResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_ClockDispatchCommand(scmi_caller_t *caller,
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
            lenOut = sizeof(msg_tclock0_t);
            status = ClockProtocolVersion(caller,
                (const scmi_msg_header_t*) in, (msg_tclock0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tclock1_t);
            status = ClockProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tclock1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tclock2_t);
            status = ClockProtocolMessageAttributes(caller,
                (const msg_rclock2_t*) in, (msg_tclock2_t*) out);
            break;
        case COMMAND_CLOCK_ATTRIBUTES:
            lenOut = sizeof(msg_tclock3_t);
            status = ClockAttributes(caller, (const msg_rclock3_t*) in,
                (msg_tclock3_t*) out);
            break;
        case COMMAND_CLOCK_DESCRIBE_RATES:
            lenOut = sizeof(msg_tclock4_t);
            status = ClockDescribeRates(caller, (const msg_rclock4_t*) in,
                (msg_tclock4_t*) out, &lenOut);
            break;
        case COMMAND_CLOCK_RATE_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = ClockRateSet(caller, (const msg_rclock5_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_CLOCK_RATE_GET:
            lenOut = sizeof(msg_tclock6_t);
            status = ClockRateGet(caller, (const msg_rclock6_t*) in,
                (msg_tclock6_t*) out);
            break;
        case COMMAND_CLOCK_CONFIG_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = ClockConfigSet(caller, (const msg_rclock7_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_CLOCK_CONFIG_GET:
            lenOut = sizeof(msg_tclock11_t);
            status = ClockConfigGet(caller, (const msg_rclock11_t*) in,
                (msg_tclock11_t*) out);
            break;
        case COMMAND_CLOCK_POSSIBLE_PARENTS_GET:
            lenOut = sizeof(msg_tclock12_t);
            status = ClockPossibleParentsGet(caller,
                (const msg_rclock12_t*) in, (msg_tclock12_t*) out, &lenOut);
            break;
        case COMMAND_CLOCK_PARENT_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = ClockParentSet(caller, (const msg_rclock13_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_CLOCK_PARENT_GET:
            lenOut = sizeof(msg_tclock14_t);
            status = ClockParentGet(caller, (const msg_rclock14_t*) in,
                (msg_tclock14_t*) out);
            break;
        case COMMAND_CLOCK_GET_PERMISSIONS:
            lenOut = sizeof(msg_tclock15_t);
            status = ClockGetPermissions(caller, (const msg_rclock15_t*) in,
                (msg_tclock15_t*) out);
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
int32_t RPC_SCMI_ClockDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return ClockResetAgentConfig(lmId, agentId, permissionsReset);
}

/*==========================================================================*/
/* Custom Protocol Implementation                                           */
/*==========================================================================*/

/* Local variables */

static uint32_t s_clockState[SM_NUM_CLOCK];

/* Local functions */

static int32_t ClockConfigUpdate(uint32_t lmId, uint32_t agentId,
    uint32_t clockId, bool enable);

/*--------------------------------------------------------------------------*/
/* Get protocol version                                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->version: Protocol version. For this revision of the               */
/*   specification, this value must be 0x20001                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_ClockProtocolVersion(). See section 4.6.2.1 in the SCMI spec.       */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tclock0_t *out)
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
/*   Bits[23:16] Maximum number of pending asynchronous clock rate changes  */
/*   supported by the platform.                                             */
/*   Bits[15:0] Number of clocks                                            */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_ClockProtocolAttributes(). See section 4.6.2.2 in the SCMI spec.    */
/*                                                                          */
/*  Access macros:                                                          */
/* - CLOCK_PROTO_ATTR_MAX_PENDING() - Maximum number of pending             */
/*   asynchronous clock rate changes supported by the platform              */
/* - CLOCK_PROTO_ATTR_NUM_CLOCKS() - Number of clocks                       */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tclock1_t *out)
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
        /* Return number of clocks, no async calls */
        out->attributes
            = CLOCK_PROTO_ATTR_MAX_PENDING(0UL)
            | CLOCK_PROTO_ATTR_NUM_CLOCKS(SM_NUM_CLOCK);
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
/* SCMI_ClockProtocolMessageAttributes(). See section 4.6.2.3 in the SCMI   */
/* spec.                                                                    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is invalid    */
/*   or not provided by this platform implementation.                       */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rclock2_t *in, msg_tclock2_t *out)
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
/* Get clock attributes                                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->clockId: Identifier for the clock device                           */
/* - out->attributes: Clock attributes:                                     */
/*   Bit[31] Clock rate change notifications support.                       */
/*   Set to 1 if clock rate change notifications are supported for this     */
/*   clock.                                                                 */
/*   Set to 0 if clock rate change notifications are not supported for      */
/*   this clock.                                                            */
/*   Bit[30] Clock rate change requested notifications support.             */
/*   Set to 1 if clock rate change requested notifications are supported    */
/*   for this clock.                                                        */
/*   Set to 0 if clock rate change requested notifications are not          */
/*   supported for this clock.                                              */
/*   Bit[29] Extended Clock name.                                           */
/*   If set to 1, the clock name is greater than 16 bytes.                  */
/*   If set to 0, extended clock name is not supported.                     */
/*   Bit[28] Parent clock identifier support.                               */
/*   Set to 1 if parent clock identifiers are advertised for this clock.    */
/*   Set to 0 if parent clock identifiers are not advertised for this       */
/*   clock.                                                                 */
/*   Bits[27:2] Reserved, must be zero.                                     */
/*   Bit[1] Restricted clock.                                               */
/*   Set to 1 if the clock has restrictions on changing some of its         */
/*   configuration or settings, and the CLOCK_GET_PERMISSIONS command, as   */
/*   specified in Section 4.6.2.16, can be used to discover the             */
/*   restrictions in place. Set to 0 if either of the following are true:   */
/*   -- The clocks restrictions cannot be discovered because                */
/*   CLOCK_GET_PERMISSIONS is not implemented.                              */
/*   -- The clock has no restrictions on changing its configuration or      */
/*   setting. Attempts to change a restricted clock configuration or        */
/*   setting returns DENIED.                                                */
/*   Bit[0] Enabled/disabled.                                               */
/*   If set to 1, the clock device is enabled.                              */
/*   If set to 0, the clock device is disabled                              */
/* - out->name: A NULL terminated ASCII string with the clock name, of up   */
/*   to 16 bytes. When Bit[29] of attributes field is set to 1, this field  */
/*   contains the lower 15 bytes of the NULL terminated clock name          */
/*                                                                          */
/* Process the CLOCK_ATTRIBUTES message. Platform handler for               */
/* SCMI_ClockAttributes(). See section 4.6.2.4 in the SCMI spec.            */
/*                                                                          */
/*  Access macros:                                                          */
/* - CLOCK_ATTR_CHANGE() - Clock rate change notifications support          */
/* - CLOCK_ATTR_CHANGE_REQ() - Clock rate change requested notifications    */
/*   support                                                                */
/* - CLOCK_ATTR_EXT_NAME() - Extended Clock name                            */
/* - CLOCK_ATTR_PARENT() - Parent clock identifier support                  */
/* - CLOCK_ATTR_RESTRICTED() - Restricted clock                             */
/* - CLOCK_ATTR_ENABLED() - Enabled/disabled                                */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid clock attributes are returned.                */
/* - SM_ERR_NOT_FOUND: if clockId does not point to a valid clock           */
/*   device.                                                                */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockAttributes(const scmi_caller_t *caller,
    const msg_rclock3_t *in, msg_tclock3_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    const uint8_t *nameAddr = (const uint8_t*) "";
    bool enabled;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check clock */
    if ((status == SM_ERR_SUCCESS) && (in->clockId >= SM_NUM_CLOCK))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get clock enable status */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_ClockIsEnabled(caller->lmId, in->clockId, &enabled);
    }

    /* Get the clock name */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_ClockNameGet(caller->lmId, in->clockId, (string*)
            &nameAddr, NULL);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t mux;
        uint32_t numMuxes;

        /* No notifications */
        out->attributes
            = CLOCK_ATTR_CHANGE(0UL)
            | CLOCK_ATTR_CHANGE_REQ(0UL)
            | CLOCK_ATTR_EXT_NAME(0UL);

        /* Parents? */
        if (LMM_ClockMuxGet(caller->lmId, in->clockId, 0U, &mux,
            &numMuxes) == SM_ERR_SUCCESS)
        {
            out->attributes |= CLOCK_ATTR_PARENT(1UL);
        }

        /* Restricted? */
        if ((g_scmiAgentConfig[caller->agentId].clkPerms[in->clockId]
            < SM_SCMI_PERM_EXCLUSIVE))
        {
            out->attributes |= CLOCK_ATTR_RESTRICTED(1UL);
        }

        /* Return enable status */
        if (enabled)
        {
            out->attributes |= CLOCK_ATTR_ENABLED(1UL);
        }

        /* Copy out name */
        RPC_SCMI_StrCpy(out->name, nameAddr, CLOCK_MAX_NAME);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get clock rate description                                               */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->clockId: Identifier for the clock device                           */
/* - in->rateIndex: Index to the first rate value. Will be first described  */
/*   in the return rate array                                               */
/* - out->numRatesFlags: Descriptor for the rates supported by this clock.  */
/*   Bits[31:16] Number of remaining rates. This field should be 0 if       */
/*   Bit[12] is 1.                                                          */
/*   Bits[15:13] Reserved, must be zero.                                    */
/*   Bit[12] Return format:                                                 */
/*   If this bit is set to 1, the Rate Array is a triplet that constitutes  */
/*   a segment in the following form:                                       */
/*   rates[0] is the lowest physical rate that the clock can synthesize in  */
/*   the segment.                                                           */
/*   rates[1] is the highest physical rate that the clock can synthesize    */
/*   in the segment.                                                        */
/*   rates[2] is the step size between two successive physical rates that   */
/*   the clock can synthesize within the segment.                           */
/*   If this bit is set to 0, each element of the rate array represents a   */
/*   discrete physical rate that the clock can synthesize.                  */
/*   Bits[11:0] Number of rates that are returned by this call. This field  */
/*   should be 3 if Bit[12] is 1                                            */
/* - out->rates: Rate array:                                                */
/*   If Bit[12] of the numRatesFlags field is set to 0, each array entry    */
/*   is composed of two 32-bit words and has the following format:          */
/*   Lower word: Lower 32 bits of the physical rate in Hertz.               */
/*   Upper word: Upper 32 bits of the physical rate in Hertz.               */
/*   If Bit[12] of the numRatesFlags field is set to 1, then each entry is  */
/*   a member of a segment {lowest rate, highest rate, step size} as        */
/*   described above.                                                       */
/*   N is specified by Bits[11:0] of numRatesFlags field                    */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the CLOCK_DESCRIBE_RATES message. Platform handler for           */
/* SCMI_ClockDescribeRates(). See section 4.6.2.5 in the SCMI spec.         */
/*                                                                          */
/*  Access macros:                                                          */
/* - CLOCK_NUM_RATE_FLAGS_REMAING_RATES() - Number of remaining rates       */
/* - CLOCK_NUM_RATE_FLAGS_FORMAT() - Return format                          */
/* - CLOCK_NUM_RATE_FLAGS_NUM_RATES() - Number of rates that are returned   */
/*   by this call                                                           */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid clock rates were returned.                    */
/* - SM_ERR_NOT_FOUND: if the clock identified by clockId does not          */
/*   exist.                                                                 */
/* - SM_ERR_OUT_OF_RANGE: if the rate_index is outside of valid range.      */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockDescribeRates(const scmi_caller_t *caller,
    const msg_rclock4_t *in, msg_tclock4_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    dev_sm_clock_range_t range = {0ULL, 0ULL, 0ULL};

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check clock */
    if ((status == SM_ERR_SUCCESS) && (in->clockId >= SM_NUM_CLOCK))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Only support return of one range */
    if ((status == SM_ERR_SUCCESS) && (in->rateIndex != 0U))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Get clock range */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_ClockDescribe(caller->lmId, in->clockId, &range);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        out->numRatesFlags
            = CLOCK_NUM_RATE_FLAGS_REMAING_RATES(0UL)
            | CLOCK_NUM_RATE_FLAGS_NUM_RATES(3UL)
            | CLOCK_NUM_RATE_FLAGS_FORMAT(1UL);

        out->rates[0].upper = SM_UINT64_H(range.lowestRate);
        out->rates[0].lower = SM_UINT64_L(range.lowestRate);
        out->rates[1].upper = SM_UINT64_H(range.highestRate);
        out->rates[1].lower = SM_UINT64_L(range.highestRate);
        out->rates[2].upper = SM_UINT64_H(range.stepSize);
        out->rates[2].lower = SM_UINT64_L(range.stepSize);

        /* Update length */
        *len = (3U * sizeof(uint32_t)) + (3U * sizeof(clock_rate_t));
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set clock rate                                                           */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->flags: Rate flags:                                                 */
/*   Bits[31:4] Reserved, must be zero.                                     */
/*   Bits[3:2] Round up/down:                                               */
/*   If Bit[3] is set to 1, the platform rounds up/down autonomously to     */
/*   choose a physical rate closest to the requested rate, and Bit[2] is    */
/*   ignored.                                                               */
/*   If Bit[3] is set to 0, the platform:                                   */
/*   -- rounds up if Bit[2] is set to 1                                     */
/*   -- rounds down if Bit[2] is set to 0                                   */
/*   Bit[1] Ignore delayed response:                                        */
/*   If the Async flag, bit[0], is set to 1 and this bit is set to 1, the   */
/*   platform does not send a CLOCK_RATE_SET delayed response.              */
/*   If the Async flag, bit[0], is set to 1 and this bit is set to 0, the   */
/*   platform does send a CLOCK_RATE_SET delayed response.                  */
/*   If the Async flag, bit[0], is set to 0, then this bit field is         */
/*   ignored by the platform.                                               */
/*   Bit[0] Async flag:                                                     */
/*   Set to 1 if clock rate is to be set asynchronously. In this case the   */
/*   call is completed with CLOCK_RATE_SET_COMPLETE message if bit[1] is    */
/*   set to 0. For more details, see section 4.6.3.1. A SUCCESS return      */
/*   code in this case indicates that the platform has successfully queued  */
/*   this function.                                                         */
/*   Set 0 to if the clock rate is to be set synchronously. In this case,   */
/*   the call will return when the clock rate setting has been completed    */
/* - in->clockId: Identifier for the clock device                           */
/* - in->rate: Clock rate:                                                  */
/*   Lower word: Lower 32 bits of the physical rate in Hertz.               */
/*   Upper word: Upper 32 bits of the physical rate in Hertz                */
/*                                                                          */
/* Process the CLOCK_RATE_SET message. Platform handler for                 */
/* SCMI_ClockRateSet(). Requires access greater than or equal to            */
/* EXCLUSIVE. See section 4.6.2.6 in the SCMI spec.                         */
/*                                                                          */
/*  Access macros:                                                          */
/* - CLOCK_RATE_FLAGS_ROUND() - Round up/down                               */
/* - CLOCK_RATE_FLAGS_NO_RESP() - Ignore delayed response                   */
/* - CLOCK_RATE_FLAGS_ASYNC() - Async flag                                  */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the clock rate was set successfully for a           */
/*   synchronous request or if the function was successfully enqueued for   */
/*   an asynchronous request.                                               */
/* - SM_ERR_NOT_FOUND: if the clock identified by clockId does not          */
/*   exist.                                                                 */
/* - SM_ERR_INVALID_PARAMETERS: if the requested rate is not supported      */
/*   by the clock, or the flags parameter specifies invalid or illegal      */
/*   options.                                                               */
/* - SM_ERR_BUSY: if there are too many asynchronous clock rate changes     */
/*   pending. The PROTOCOL_ATTRIBUTES function provides the maximum number  */
/*   of pending asynchronous clock rate changes supported by the platform.  */
/* - SM_ERR_DENIED: if the clock rate cannot be set because of              */
/*   dependencies, e.g. if there are other users of the clock.              */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockRateSet(const scmi_caller_t *caller,
    const msg_rclock5_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool async = CLOCK_RATE_FLAGS_ASYNC(in->flags) != 0U;
    uint32_t roundSel = CLOCK_RATE_FLAGS_ROUND(in->flags);

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check clock */
    if ((status == SM_ERR_SUCCESS) && (in->clockId >= SM_NUM_CLOCK))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check round */
    if (roundSel > CLOCK_ROUND_AUTO)
    {
        roundSel = CLOCK_ROUND_AUTO;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].clkPerms[in->clockId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Check for async request */
    if ((status == SM_ERR_SUCCESS) && async)
    {
        /* Support sync only */
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Set clock rate */
    if (status == SM_ERR_SUCCESS)
    {
        uint64_t lmRate = (((uint64_t) in->rate.upper) << 32U)
            | (uint64_t) in->rate.lower;

        status = LMM_ClockRateSet(caller->lmId, in->clockId, lmRate,
            roundSel);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get clock rate                                                           */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->clockId: Identifier for the clock device                           */
/* - out->rate: Clock rate:                                                 */
/*   Lower word: Lower 32 bits of the physical rate in Hertz.               */
/*   Upper word: Upper 32 bits of the physical rate in Hertz                */
/*                                                                          */
/* Process the CLOCK_RATE_GET message. Platform handler for                 */
/* SCMI_ClockRateGet(). See section 4.6.2.7 in the SCMI spec.               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the current clock rate was successfully returned.   */
/* - SM_ERR_NOT_FOUND: if the clock identified by clockId does not          */
/*   exist.                                                                 */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockRateGet(const scmi_caller_t *caller,
    const msg_rclock6_t *in, msg_tclock6_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check clock */
    if ((status == SM_ERR_SUCCESS) && (in->clockId >= SM_NUM_CLOCK))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get clock rate */
    if (status == SM_ERR_SUCCESS)
    {
        uint64_t lmRate = 0U;

        status = LMM_ClockRateGet(caller->lmId, in->clockId, &lmRate);

        out->rate.upper = SM_UINT64_H(lmRate);
        out->rate.lower = SM_UINT64_L(lmRate);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set clock configuration                                                  */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->clockId: Identifier for the clock device                           */
/* - in->attributes: Config attributes:                                     */
/*   Bits[31:24] Reserved, must be zero.                                    */
/*   Bits[23:16] OEM specified config type.                                 */
/*   The possible values of this field are out of the scope of this         */
/*   specification and are defined by the OEM.                              */
/*   A value of 0 indicates that this field is unused.                      */
/*   Bits[15:2] Reserved, must be zero.                                     */
/*   Bits[1:0] Enable/Disable:                                              */
/*   If set to 3, the state of the clock device is unchanged. It is         */
/*   invalid to use this value if Bits[23:16] is set to 0.                  */
/*   The value of 2 is reserved for future use.                             */
/*   If set to 1, the clock device is to be enabled.                        */
/*   If set to 0, the clock device is to be disabled                        */
/* - in->oemConfigVal: OEM specified configuration value: ccorresponding    */
/*   to the OEM specified configuration type specified by Bits[23:16] of    */
/*   attributes field.                                                      */
/*   This field is used to set implementation defined configurations of     */
/*   the clock device. It can be ignored if OEM specified config type       */
/*   specified by Bits[23:16] of attributes field is set to 0               */
/*                                                                          */
/* Process the CLOCK_CONFIG_SET message. Platform handler for               */
/* SCMI_ClockConfigSet(). Requires access greater than or equal to SET.     */
/* See section 4.6.2.8 in the SCMI spec.                                    */
/*                                                                          */
/*  Access macros:                                                          */
/* - CLOCK_CONFIG_SET_OEM() - OEM specified config type                     */
/* - CLOCK_CONFIG_SET_ENABLE() - Enable/Disable                             */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the clock configuration has been set successfully.  */
/* - SM_ERR_NOT_FOUND: if the clock identified by clockId does not          */
/*   exist.                                                                 */
/* - SM_ERR_INVALID_PARAMETERS, if the input attributes flag specifies      */
/*   unsupported or invalid configurations.                                 */
/* - SM_ERR_DENIED: if the clock config cannot be set because of lack of    */
/*   permissions.                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockConfigSet(const scmi_caller_t *caller,
    const msg_rclock7_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t agentId = caller->agentId;
    uint32_t enable = CLOCK_CONFIG_SET_ENABLE(in->attributes);

    /* Check request length */
    if (caller->lenCopy < (sizeof(*in) - sizeof(uint32_t)))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check clock */
    if ((status == SM_ERR_SUCCESS) && (in->clockId >= SM_NUM_CLOCK))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check OEM update */
    if ((status == SM_ERR_SUCCESS) && (enable > 1U))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].clkPerms[in->clockId]
        < SM_SCMI_PERM_SET))
    {
        status = SM_ERR_DENIED;
    }

    /* Update tracking */
    if (status == SM_ERR_SUCCESS)
    {
        status = ClockConfigUpdate(caller->lmId, agentId, in->clockId,
            enable == 1U);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get clock configuration                                                  */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->clockId: Identifier for the clock device                           */
/* - in->flags: Config flags:                                               */
/*   Bits[31:8] Reserved, must be zero.                                     */
/*   Bits[7:0] OEM specified config type.                                   */
/*   Value of 0 indicates that this field is unused                         */
/* - out->attributes: Reserved, must be zero                                */
/* - out->config: Config:                                                   */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Enable/Disable If set to 1, the clock device is enabled.        */
/*   If set to 0, the clock device is disabled                              */
/* - out->oemConfigVal: OEM specified configuration value: corresponding    */
/*   to the OEM specified configuration type specified by Bits[7:0] of      */
/*   attributes field of the function.                                      */
/*   This field is ignored if OEM specified config type field specified by  */
/*   Bits[7:0] of attributes field of the function is set to 0              */
/*                                                                          */
/* Process the CLOCK_CONFIG_GET message. Platform handler for               */
/* SCMI_ClockConfigGet(). See section 4.6.2.9 in the SCMI spec.             */
/*                                                                          */
/*  Access macros:                                                          */
/* - CLOCK_CONFIG_FLAGS_OEM() - OEM specified config type                   */
/* - CLOCK_CONFIG_GET_ENABLE() - Enable/Disable                             */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the clock configuration has been successfully       */
/*   returned.                                                              */
/* - SM_ERR_NOT_FOUND: if the clock identified by clockId does not          */
/*   exist.                                                                 */
/* - SM_ERR_INVALID_PARAMETERS, if the input attributes flag specifies      */
/*   unsupported or invalid configurations.                                 */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockConfigGet(const scmi_caller_t *caller,
    const msg_rclock11_t *in, msg_tclock11_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t oem = CLOCK_CONFIG_FLAGS_OEM(in->flags);
    bool enabled;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check clock */
    if ((status == SM_ERR_SUCCESS) && (in->clockId >= SM_NUM_CLOCK))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check OEM */
    if ((status == SM_ERR_SUCCESS) && (oem != 0U))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Get clock enable status */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_ClockIsEnabled(caller->lmId, in->clockId, &enabled);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t getEnabled = enabled ? 1UL : 0UL;

        out->attributes = 0U;
        out->config = CLOCK_CONFIG_GET_ENABLE(getEnabled);
        out->oemConfigVal = 0U;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get all possible parents                                                 */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->clockId: Identifier for the clock device                           */
/* - in->skipParents: The number of parents to skip over: those before      */
/*   returning the first possible parent in the return parent array         */
/* - out->numParentsFlags: Descriptor for the possible parents for this     */
/*   clock.                                                                 */
/*   Bits[31:24] Number of remaining parents.                               */
/*   Bits[23:8] Reserved, must be zero.                                     */
/*   Bits[7:0] Number of parent clock identifiers that are returned by      */
/*   this call                                                              */
/* - out->parents: Array of parents                                         */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the CLOCK_POSSIBLE_PARENTS_GET message. Platform handler for     */
/* SCMI_ClockPossibleParentsGet(). See section 4.6.2.13 in the SCMI spec.   */
/*                                                                          */
/*  Access macros:                                                          */
/* - CLOCK_NUM_PARENT_FLAGS_REMAING_PARENTS() - Number of remaining         */
/*   parents                                                                */
/* - CLOCK_NUM_PARENT_FLAGS_NUM_PARENTS() - Number of parent clock          */
/*   identifiers that are returned by this call                             */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the possible clock parents have been successfully   */
/*   returned.                                                              */
/* - SM_ERR_NOT_FOUND: if the clock identified by clock_id does not         */
/*   exist.                                                                 */
/* - SM_ERR_NOT_SUPPORTED: if the request is not supported.                 */
/* - SM_ERR_DENIED: if the calling agent is not allowed to get the          */
/*   possible parents.                                                      */
/*                                                                          */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockPossibleParentsGet(const scmi_caller_t *caller,
    const msg_rclock12_t *in, msg_tclock12_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t numMuxes = 0U;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check clock */
    if ((status == SM_ERR_SUCCESS) && (in->clockId >= SM_NUM_CLOCK))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get number of muxes */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t mux;

        status = LMM_ClockMuxGet(caller->lmId, in->clockId, 0U,
            &mux, &numMuxes);
    }

    /* Check parent bounds */
    if ((status == SM_ERR_SUCCESS) && (in->skipParents >= numMuxes))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Get parents? */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t index;

        out->numParentsFlags = 0U;
        for (index = 0U; index < CLOCK_MAX_PARENTS; index++)
        {
            uint32_t mux;
            uint32_t temp;

            /* Break out if done */
            if ((index + in->skipParents) >= numMuxes)
            {
                break;
            }

            /* Get parent */
            status = LMM_ClockMuxGet(caller->lmId, in->clockId,
                index + in->skipParents, &mux, &temp);

            /* Success? */
            if (status == SM_ERR_SUCCESS)
            {
                /* Copy out data */
                out->parents[index] = mux;

                /* Increment count */
                (out->numParentsFlags)++;
            }
        }

        /* Update length */
        *len = (3U * sizeof(uint32_t))
            + (out->numParentsFlags * sizeof(uint32_t));

        /* Append remaining parents */
        out->numParentsFlags |= CLOCK_NUM_PARENT_FLAGS_REMAING_PARENTS(
            numMuxes - (index + in->skipParents));
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set clock parent                                                         */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->clockId: Identifier for the clock device                           */
/* - in->parentId: Identifier for the parent: aka clock device to set as    */
/*   the parent of the clock specified by clockId                           */
/*                                                                          */
/* Process the CLOCK_PARENT_SET message. Platform handler for               */
/* SCMI_ClockParentSet(). Requires access greater than or equal to          */
/* EXCLUSIVE. See section 4.6.2.14 in the SCMI spec.                        */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the clock parent has been set successfully.         */
/* - SM_ERR_NOT_FOUND: if the clock identified by clockId or parentId       */
/*   does not exist.                                                        */
/* - SM_ERR_INVALID_PARAMETERS, if the parent is not an option for the      */
/*   specified clock.                                                       */
/* - SM_ERR_OUT_OF_RANGE: changing the parent clock is not possible         */
/*   because of inability to maintain child clock requirements.             */
/* - SM_ERR_NOT_SUPPORTED: if the request is not supported.                 */
/* - SM_ERR_DENIED: if the calling agent is not allowed to set the          */
/*   parent.                                                                */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockParentSet(const scmi_caller_t *caller,
    const msg_rclock13_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check clock */
    if ((status == SM_ERR_SUCCESS) && (in->clockId >= SM_NUM_CLOCK))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].clkPerms[in->clockId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Set clock parent */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_ClockParentSet(caller->lmId, in->clockId,
            in->parentId);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get clock parent                                                         */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->clockId: Identifier for the clock device                           */
/* - out->parentId: Identifier for the parent: aka clock device to set as   */
/*   the parent of the clock specified by clockId                           */
/*                                                                          */
/* Process the CLOCK_PARENT_GET message. Platform handler for               */
/* SCMI_ClockParentGet(). See section 4.6.2.15 in the SCMI spec.            */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the clock parent has been successfully returned.    */
/* - SM_ERR_NOT_FOUND: if the clock identified by clockId does not          */
/*   exist.                                                                 */
/* - SM_ERR_NOT_SUPPORTED: if the request is not supported.                 */
/* - SM_ERR_DENIED: f the calling agent is not allowed to get the           */
/*   parent.                                                                */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockParentGet(const scmi_caller_t *caller,
    const msg_rclock14_t *in, msg_tclock14_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check clock */
    if ((status == SM_ERR_SUCCESS) && (in->clockId >= SM_NUM_CLOCK))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get parent */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_ClockParentGet(caller->lmId, in->clockId,
            &out->parentId);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get clock permissions                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->clockId: Identifier for the clock device                           */
/* - out->permissions: Permissions:                                         */
/*   Bit[31] Clock state control                                            */
/*   Set to 1 if the clock can be disabled or enabled by the agent.         */
/*   Set to 0 if the clock state cannot be changed by the agent. Attempts   */
/*   to change the clock state using SCMI_ClockConfigSet() function         */
/*   returns DENIED.                                                        */
/*   Bit[30] Clock parent control                                           */
/*   Set to 1 if the clock parent can be changed by the agent.              */
/*   Set to 0 if the clock parent cannot be changed by the agent.           */
/*   SCMI_ClockParentSet() function returns DENIED.                         */
/*   Bit[29] Clock rate control                                             */
/*   Set to 1 if the clock rate can be changed by the agent.                */
/*   Set to 0 if the clock rate cannot be changed by the agent.             */
/*   SCMI_ClockRateSet() function returns DENIED.                           */
/*    Bits[28:0] Reserved, must be zero                                     */
/*                                                                          */
/* Process the CLOCK_GET_PERMISSIONS message. Platform handler for          */
/* SCMI_ClockGetPermissions(). See section 4.6.2.16 in the SCMI spec.       */
/*                                                                          */
/*  Access macros:                                                          */
/* - CLOCK_PERM_STATE() - Clock state control                               */
/* - CLOCK_PERM_PARENT() - Clock parent control                             */
/* - CLOCK_PERM_RATE() - Clock rate control                                 */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid clock permissions are returned.               */
/* - SM_ERR_NOT_FOUND: if the clock identified by clockId does not          */
/*   exist.                                                                 */
/* - SM_ERR_NOT_SUPPORTED: if the request is not supported.                 */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t ClockGetPermissions(const scmi_caller_t *caller,
    const msg_rclock15_t *in, msg_tclock15_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check clock */
    if ((status == SM_ERR_SUCCESS) && (in->clockId >= SM_NUM_CLOCK))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        /* Initial value */
        out->permissions = 0U;

        /* Enable? */
        if ((g_scmiAgentConfig[caller->agentId].clkPerms[in->clockId]
            >= SM_SCMI_PERM_SET))
        {
            out->permissions |= CLOCK_PERM_STATE(1UL);
        }

        /* Set parent/rate? */
        if ((g_scmiAgentConfig[caller->agentId].clkPerms[in->clockId]
            >= SM_SCMI_PERM_EXCLUSIVE))
        {
            out->permissions |= CLOCK_PERM_RATE(1UL)
                | CLOCK_PERM_PARENT(1UL);
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
static int32_t ClockResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all clocks */
    for (uint32_t clockId = 0U; clockId < SM_NUM_CLOCK; clockId++)
    {
        /* Disable clock */
        if ((s_clockState[clockId] & (1UL << agentId)) != 0U)
        {
            ClockConfigUpdate(lmId, agentId, clockId,
                false);
        }

        /* Reset rate */
        if (g_scmiAgentConfig[agentId].clkPerms[clockId]
            >= SM_SCMI_PERM_EXCLUSIVE)
        {
            (void) LMM_ClockReset(lmId, clockId);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Aggregate and update the clock enable                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - lmId: LM to update                                                     */
/* - agentId: Message to update                                             */
/* - domainId: Voltage domain                                               */
/* - enable: New clock enable                                               */
/*--------------------------------------------------------------------------*/
static int32_t ClockConfigUpdate(uint32_t lmId, uint32_t agentId,
    uint32_t clockId, bool enable)
{
    uint32_t scmiInst = g_scmiAgentConfig[agentId].scmiInst;
    uint32_t firstAgent = g_scmiConfig[scmiInst].firstAgent;
    uint32_t numAgents = g_scmiConfig[scmiInst].numAgents;
    uint32_t mask;
    uint32_t clockState;
    bool clockEnable;

    /* Record state of clock by agent */
    if (enable)
    {
        /* Mark as enabled */
        s_clockState[clockId] |= (1UL << agentId);
    }
    else
    {
        /* Mark as disabled */
        s_clockState[clockId] &= ~(1UL << agentId);
    }

    /* Extract enable */
    mask = ((1UL << numAgents) - 1UL) << firstAgent;
    clockState = s_clockState[clockId] & mask;
    clockEnable = (clockState != 0U);

    /* Inform LMM of clock state, LMM will check if changed */
    return LMM_ClockEnable(lmId, clockId, clockEnable);
}

