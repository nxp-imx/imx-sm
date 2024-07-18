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
/* Interface (SCMI) voltage protocol.                                       */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x20001U

/* SCMI voltage protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION             0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES          0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES  0x2U
#define COMMAND_VOLTAGE_DOMAIN_ATTRIBUTES    0x3U
#define COMMAND_VOLTAGE_DESCRIBE_LEVELS      0x4U
#define COMMAND_VOLTAGE_CONFIG_SET           0x5U
#define COMMAND_VOLTAGE_CONFIG_GET           0x6U
#define COMMAND_VOLTAGE_LEVEL_SET            0x7U
#define COMMAND_VOLTAGE_LEVEL_GET            0x8U
#define COMMAND_NEGOTIATE_PROTOCOL_VERSION   0x10U
#define COMMAND_SUPPORTED_MASK               0x101FFULL

/* SCMI max voltage argument lengths */
#define VOLTAGE_MAX_NAME     16U
#define VOLTAGE_MAX_VOLTAGE  SCMI_ARRAY(8U, int32_t)

/* SCMI voltage domain modes */
#define VOLTAGE_DOMAIN_MODES_OFF  0x0U
#define VOLTAGE_DOMAIN_MODES_ON   0x7U

/* Local macros */

/* SCMI voltage protocol attributes */
#define VOLTAGE_PROTO_ATTR_NUM_VOLTS(x)  (((x) & 0xFFFFU) << 0U)

/* SCMI voltage domain attributes */
#define VOLTAGE_ATTR_ASYNC(x)     (((x) & 0x1U) << 31U)
#define VOLTAGE_ATTR_EXT_NAME(x)  (((x) & 0x1U) << 30U)

/* SCMI voltage description flags */
#define VOLTAGE_FLAGS_REMAINING_LEVELS(x)  (((x) & 0xFFFFU) << 16U)
#define VOLTAGE_FLAGS_FORMAT(x)            (((x) & 0x1U) << 12U)
#define VOLTAGE_FLAGS_NUM_LEVELS(x)        (((x) & 0xFFFU) << 0U)

/* SCMI voltage configs (set) */
#define VOLTAGE_CONFIG_SET_MODE(x)  (((x) & 0xFU) >> 0U)

/* SCMI voltage configs (get) */
#define VOLTAGE_CONFIG_GET_MODE(x)  (((x) & 0xFU) << 0U)

/* SCMI voltage set flags */
#define VOLTAGE_SET_FLAGS_ASYNC(x)  (((x) & 0x1U) >> 0U)

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
} msg_tvoltage0_t;

/* Response type for ProtocolAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol attributes */
    uint32_t attributes;
} msg_tvoltage1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rvoltage2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_tvoltage2_t;

/* Request type for VoltageDomainAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the domain */
    uint32_t domainId;
} msg_rvoltage3_t;

/* Response type for VoltageDomainAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Domain attributes */
    uint32_t attributes;
    /* ASCII name string */
    uint8_t name[VOLTAGE_MAX_NAME];
} msg_tvoltage3_t;

/* Request type for VoltageDescribeLevels() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the voltage domain */
    uint32_t domainId;
    /* Index of the first voltage level */
    uint32_t levelIndex;
} msg_rvoltage4_t;

/* Response type for VoltageDescribeLevels() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Domain flags */
    uint32_t flags;
    /* Voltage Array expressed in microvolts (uV) */
    int32_t voltage[VOLTAGE_MAX_VOLTAGE];
} msg_tvoltage4_t;

/* Request type for VoltageConfigSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the voltage domain */
    uint32_t domainId;
    /* Domain config */
    uint32_t config;
} msg_rvoltage5_t;

/* Request type for VoltageConfigGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the voltage domain */
    uint32_t domainId;
} msg_rvoltage6_t;

/* Response type for VoltageConfigGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Domain config */
    uint32_t config;
} msg_tvoltage6_t;

/* Request type for VoltageLevelSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the voltage domain */
    uint32_t domainId;
    /* Voltage set flags */
    uint32_t flags;
    /* The voltage level, in microvolts (uV), to set the domain to */
    int32_t voltageLevel;
} msg_rvoltage7_t;

/* Request type for VoltageLevelGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the voltage domain */
    uint32_t domainId;
} msg_rvoltage8_t;

/* Response type for VoltageLevelGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* The voltage level, in microvolts (uV), that the domain is set to */
    int32_t voltageLevel;
} msg_tvoltage8_t;

/* Request type for NegotiateProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* The negotiated protocol version the agent intends to use */
    uint32_t version;
} msg_rvoltage16_t;

/* Local functions */

static int32_t VoltageProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tvoltage0_t *out);
static int32_t VoltageProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tvoltage1_t *out);
static int32_t VoltageProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rvoltage2_t *in, msg_tvoltage2_t *out);
static int32_t VoltageDomainAttributes(const scmi_caller_t *caller,
    const msg_rvoltage3_t *in, msg_tvoltage3_t *out);
static int32_t VoltageDescribeLevels(const scmi_caller_t *caller,
    const msg_rvoltage4_t *in, msg_tvoltage4_t *out, uint32_t *len);
static int32_t VoltageConfigSet(const scmi_caller_t *caller,
    const msg_rvoltage5_t *in, const scmi_msg_status_t *out);
static int32_t VoltageConfigGet(const scmi_caller_t *caller,
    const msg_rvoltage6_t *in, msg_tvoltage6_t *out);
static int32_t VoltageLevelSet(const scmi_caller_t *caller,
    const msg_rvoltage7_t *in, const scmi_msg_status_t *out);
static int32_t VoltageLevelGet(const scmi_caller_t *caller,
    const msg_rvoltage8_t *in, msg_tvoltage8_t *out);
static int32_t VoltageNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rvoltage16_t *in, const scmi_msg_status_t *out);
static int32_t VoltageResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_VoltageDispatchCommand(scmi_caller_t *caller,
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
            lenOut = sizeof(msg_tvoltage0_t);
            status = VoltageProtocolVersion(caller,
                (const scmi_msg_header_t*) in, (msg_tvoltage0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tvoltage1_t);
            status = VoltageProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tvoltage1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tvoltage2_t);
            status = VoltageProtocolMessageAttributes(caller,
                (const msg_rvoltage2_t*) in, (msg_tvoltage2_t*) out);
            break;
        case COMMAND_VOLTAGE_DOMAIN_ATTRIBUTES:
            lenOut = sizeof(msg_tvoltage3_t);
            status = VoltageDomainAttributes(caller,
                (const msg_rvoltage3_t*) in, (msg_tvoltage3_t*) out);
            break;
        case COMMAND_VOLTAGE_DESCRIBE_LEVELS:
            lenOut = sizeof(msg_tvoltage4_t);
            status = VoltageDescribeLevels(caller,
                (const msg_rvoltage4_t*) in, (msg_tvoltage4_t*) out,
                &lenOut);
            break;
        case COMMAND_VOLTAGE_CONFIG_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = VoltageConfigSet(caller, (const msg_rvoltage5_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_VOLTAGE_CONFIG_GET:
            lenOut = sizeof(msg_tvoltage6_t);
            status = VoltageConfigGet(caller, (const msg_rvoltage6_t*) in,
                (msg_tvoltage6_t*) out);
            break;
        case COMMAND_VOLTAGE_LEVEL_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = VoltageLevelSet(caller, (const msg_rvoltage7_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_VOLTAGE_LEVEL_GET:
            lenOut = sizeof(msg_tvoltage8_t);
            status = VoltageLevelGet(caller, (const msg_rvoltage8_t*) in,
                (msg_tvoltage8_t*) out);
            break;
        case COMMAND_NEGOTIATE_PROTOCOL_VERSION:
            lenOut = sizeof(const scmi_msg_status_t);
            status = VoltageNegotiateProtocolVersion(caller,
                (const msg_rvoltage16_t*) in,
                (const scmi_msg_status_t*) out);
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
int32_t RPC_SCMI_VoltageDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return VoltageResetAgentConfig(lmId, agentId, permissionsReset);
}

/*==========================================================================*/
/* Custom Protocol Implementation                                           */
/*==========================================================================*/

/* Local variables */

static uint8_t s_voltState[SM_NUM_VOLT][SM_SCMI_NUM_AGNT];

/* Local functions */

static int32_t VoltageConfigUpdate(uint32_t lmId, uint32_t agentId,
    uint32_t domainId, uint8_t mode);

/*--------------------------------------------------------------------------*/
/* Get protocol version                                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->version: Protocol version. For this revision of the               */
/*   specification, this value must be 0x20001                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_VoltageProtocolVersion(). See section 4.9.2.1 in the SCMI spec.     */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t VoltageProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tvoltage0_t *out)
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
/*   Bits[15:0] Number of voltage domains                                   */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_VoltageProtocolAttributes(). See section 4.9.2.3 in the SCMI spec.  */
/*                                                                          */
/*  Access macros:                                                          */
/* - VOLTAGE_PROTO_ATTR_NUM_VOLTS() - Number of voltage domains             */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t VoltageProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tvoltage1_t *out)
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
        /* Return number of voltage domains */
        out->attributes = VOLTAGE_PROTO_ATTR_NUM_VOLTS(SM_NUM_VOLT);
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
/* SCMI_VoltageProtocolMessageAttributes(). See section 4.9.2.4 in the      */
/* SCMI spec.                                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is invalid    */
/*   or not provided by this platform implementation.                       */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t VoltageProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rvoltage2_t *in, msg_tvoltage2_t *out)
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
/* Get voltage domain attributes                                            */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the domain. Domain identifiers are        */
/*   limited to 16 bits, and the upper 16 bits of this field are ignored    */
/*   by the platform                                                        */
/* - out->attributes: Domain attributes:                                    */
/*   Bit[31] Asynchronous voltage level set support.                        */
/*   Set to 1 if the voltage level of this domain can be set                */
/*   asynchronously.                                                        */
/*   Set to 0 if the voltage level of this domain can only be set           */
/*   synchronously.                                                         */
/*   Bit[30] Extended voltage domain name.                                  */
/*   If set to 1, the voltage domain name is greater than 16 bytes.         */
/*   If set to 0, extended voltage domain name is not supported.            */
/*   Bits[29:0] Reserved, must be zero                                      */
/* - out->name: Null-terminated ASCII string of up to 16 bytes in length    */
/*   describing the voltage domain name. When Bit[30] of attributes field   */
/*   is set to 1, this field contains the lower 15 bytes of the NULL        */
/*   terminated voltage domain name                                         */
/*                                                                          */
/* Process the VOLTAGE_DOMAIN_ATTRIBUTES message. Platform handler for      */
/* SCMI_VoltageDomainAttributes(). See section 4.9.2.5 in the SCMI spec.    */
/*                                                                          */
/*  Access macros:                                                          */
/* - VOLTAGE_ATTR_ASYNC() - Asynchronous voltage level set support          */
/* - VOLTAGE_ATTR_EXT_NAME() - Extended voltage domain name                 */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid power domain attributes are returned.         */
/* - SM_ERR_NOT_FOUND: if domainId pertains to a non-existent domain.       */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t VoltageDomainAttributes(const scmi_caller_t *caller,
    const msg_rvoltage3_t *in, msg_tvoltage3_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    const uint8_t *nameAddr = (const uint8_t*) "";

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_VOLT))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get the domain name */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_VoltageNameGet(caller->lmId, in->domainId,
            (string*) &nameAddr, NULL);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        /* Sync responses only */
        out->attributes
            = VOLTAGE_ATTR_ASYNC(0UL)
            | VOLTAGE_ATTR_EXT_NAME(0UL);

        /* Copy out name */
        RPC_SCMI_StrCpy(out->name, nameAddr, VOLTAGE_MAX_NAME);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get voltage level descriptions                                           */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the voltage domain                        */
/* - in->levelIndex: Index of the first voltage level. The first to be      */
/*   described in the return voltage array                                  */
/* - out->flags: Domain flags:                                              */
/*   Descriptor for the voltage levels supported by this domain.            */
/*   Bits[31:16] Number of remaining voltage levels. This field should be   */
/*   0 if Bit[12] is 1.                                                     */
/*   Bits[15:13] Reserved, must be zero.                                    */
/*   Bit[12] Return format:                                                 */
/*   If this bit is set to 1, the Voltage Array is a triplet that           */
/*   constitutes a segment in the following form:                           */
/*   voltage[0] is the lowest voltage level that the domain supports.       */
/*   voltage[1] is the highest voltage level that the domain supports.      */
/*   voltage[2] is the step size between two successive voltage levels      */
/*   that the domain supports.                                              */
/*   If this bit is set to 0, each element of the Voltage Array represents  */
/*   a discrete voltage level that the voltage domain supports.             */
/*   Bits[11:0] Number of voltage levels that are returned by this call.    */
/*   This field should be 3 if Bit[12] is 1                                 */
/* - out->voltage: Voltage Array expressed in microvolts (uV):              */
/*   If Bit[12] of the flags field is set to 0, each array entry            */
/*   represents a discrete voltage level.                                   */
/*   If Bit[12] of the flags field is set to 1, then each entry is a        */
/*   member of a segment {lowest voltage level, highest voltage level,      */
/*   step size} as described above.                                         */
/*   N is specified by Bits[11:0] of flags field                            */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the VOLTAGE_DESCRIBE_LEVELS message. Platform handler for        */
/* SCMI_VoltageDescribeLevels(). See section 4.9.2.6 in the SCMI spec.      */
/*                                                                          */
/*  Access macros:                                                          */
/* - VOLTAGE_FLAGS_REMAINING_LEVELS() - Number of remaining voltage levels  */
/* - VOLTAGE_FLAGS_FORMAT() - Return format                                 */
/* - VOLTAGE_FLAGS_NUM_LEVELS() - Number of voltage levels that are         */
/*   returned by this call                                                  */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the voltage levels are returned successfully.       */
/* - SM_ERR_NOT_FOUND: if the domain identified by domainId does not        */
/*   exist.                                                                 */
/* - SM_ERR_OUT_OF_RANGE: if the levelIndex is outside of valid range.      */
/* - SM_ERR_NOT_SUPPORTED: if the request is not supported.                 */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t VoltageDescribeLevels(const scmi_caller_t *caller,
    const msg_rvoltage4_t *in, msg_tvoltage4_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    dev_sm_voltage_range_t range = {0, 0, 0};

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_VOLT))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Only support return of one range */
    if ((status == SM_ERR_SUCCESS) && (in->levelIndex != 0U))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Get clock range */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_VoltageDescribe(caller->lmId, in->domainId, &range);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        out->flags = VOLTAGE_FLAGS_NUM_LEVELS(3UL)
            | VOLTAGE_FLAGS_FORMAT(1UL);

        /* Record range */
        out->voltage[0] = range.lowestVolt;
        out->voltage[1] = range.highestVolt;
        out->voltage[2] = range.stepSize;

        /* Update length */
        *len = (3U + 3U) * sizeof(uint32_t);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set voltage configuration                                                */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the voltage domain                        */
/* - in->config: Domain config:                                             */
/*   Bits[31:4] Reserved, must be zero.                                     */
/*   Bits[3:0] Mode: The operating mode the voltage domain should be set    */
/*   to, as described in Table 21                                           */
/*                                                                          */
/* Process the VOLTAGE_CONFIG_SET message. Platform handler for             */
/* SCMI_VoltageConfigSet(). Requires access greater than or equal to SET.   */
/* See section 4.9.2.7 in the SCMI spec.                                    */
/*                                                                          */
/*  Access macros:                                                          */
/* - VOLTAGE_CONFIG_SET_MODE() - Voltage mode                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the voltage domain configuration has been set       */
/*   successfully.                                                          */
/* - SM_ERR_NOT_FOUND: if the voltage domain identified by domainId does    */
/*   not exist.                                                             */
/* - SM_ERR_INVALID_PARAMETERS: if the requested configuration is not       */
/*   supported by the voltage domain.                                       */
/* - SM_ERR_NOT_SUPPORTED: if the request is not supported.                 */
/* - SM_ERR_DENIED: if the calling agent is not allowed to set the          */
/*   configuration of this voltage domain. An example would be if this      */
/*   voltage domain is exclusive to another agent.                          */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t VoltageConfigSet(const scmi_caller_t *caller,
    const msg_rvoltage5_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t agentId = caller->agentId;
    uint8_t voltMode = (uint8_t) VOLTAGE_CONFIG_SET_MODE(in->config);

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_VOLT))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].voltPerms[in->domainId]
        < SM_SCMI_PERM_SET))
    {
        status = SM_ERR_DENIED;
    }

    /* Check and translate to device power states as easier to track */
    if (status == SM_ERR_SUCCESS)
    {
        switch (voltMode)
        {
            case VOLTAGE_DOMAIN_MODES_OFF:
                voltMode = DEV_SM_VOLT_MODE_OFF;
                break;
            case VOLTAGE_DOMAIN_MODES_ON:
                voltMode = DEV_SM_VOLT_MODE_ON;
                break;
            default:
                if (voltMode >= SM_NUM_VOLT_MODE)
                {
                    status = SM_ERR_INVALID_PARAMETERS;
                }
                break;
        }
    }

    /* Update tracking */
    if (status == SM_ERR_SUCCESS)
    {

        status = VoltageConfigUpdate(caller->lmId, agentId, in->domainId,
            voltMode);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get voltage configuration                                                */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the voltage domain                        */
/* - out->config: Domain config:                                            */
/*   Bits[31:4] Reserved, must be zero.                                     */
/*   Bits[3:0] Mode: The operating mode of the voltage domain, as           */
/*   described in Table 21                                                  */
/*                                                                          */
/* Process the VOLTAGE_CONFIG_GET message. Platform handler for             */
/* SCMI_VoltageConfigGet(). See section 4.9.2.8 in the SCMI spec.           */
/*                                                                          */
/*  Access macros:                                                          */
/* - VOLTAGE_CONFIG_GET_MODE() - Voltage mode                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the voltage domain configuration was successfully   */
/*   returned.                                                              */
/* - SM_ERR_NOT_FOUND: if domainId does not point to a valid voltage        */
/*   domain.                                                                */
/* - SM_ERR_NOT_SUPPORTED: if the request is not supported.                 */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t VoltageConfigGet(const scmi_caller_t *caller,
    const msg_rvoltage6_t *in, msg_tvoltage6_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    uint8_t voltMode;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_VOLT))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get the LMM voltage mode */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_VoltageModeGet(caller->lmId, in->domainId, &voltMode);
    }

    /* Translate to SCMI power state */
    if (status == SM_ERR_SUCCESS)
    {
        switch (voltMode)
        {
            case DEV_SM_VOLT_MODE_OFF:
                voltMode = VOLTAGE_DOMAIN_MODES_OFF;
                break;
            case DEV_SM_VOLT_MODE_ON:
                voltMode = VOLTAGE_DOMAIN_MODES_ON;
                break;
            default:
                ; /* Intentional empty default */
                break;
        }

        /* Return mode */
        out->config = (uint8_t) VOLTAGE_CONFIG_GET_MODE(voltMode);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set voltage level                                                        */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the voltage domain                        */
/* - in->flags: Voltage set flags:                                          */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] Async flag:                                                     */
/*   Set to 1 if the voltage level is to be set asynchronously.             */
/*   Set 0 to if the voltage level is to be set synchronously. In this      */
/*   case, the call will return when the voltage level has been set         */
/* - in->voltageLevel: The voltage level, in microvolts (uV), to set the    */
/*   domain to                                                              */
/*                                                                          */
/* Process the VOLTAGE_LEVEL_SET message. Platform handler for              */
/* SCMI_VoltageLevelSet(). Requires access greater than or equal to         */
/* EXCLUSIVE. See section 4.9.2.9 in the SCMI spec.                         */
/*                                                                          */
/*  Access macros:                                                          */
/* - VOLTAGE_SET_FLAGS_ASYNC() - Async flag                                 */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the voltage domain has been set to the desired      */
/*   level.                                                                 */
/* - SM_ERR_NOT_FOUND: if the voltage domain identified by domainId does    */
/*   not exist.                                                             */
/* - SM_ERR_INVALID_PARAMETERS: if the requested voltage level is not       */
/*   supported by the voltage domain.                                       */
/* - SM_ERR_NOT_SUPPORTED: if the request is not supported.                 */
/* - SM_ERR_DENIED: if the calling agent is not allowed to set the          */
/*   voltage level of this voltage domain. An example would be if this      */
/*   voltage domain is exclusive to another agent.                          */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t VoltageLevelSet(const scmi_caller_t *caller,
    const msg_rvoltage7_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_VOLT))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].voltPerms[in->domainId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Check for delayed response */
    if ((status == SM_ERR_SUCCESS) && (VOLTAGE_SET_FLAGS_ASYNC(in->flags)
        != 0U))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Set voltage level */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_VoltageLevelSet(caller->lmId, in->domainId,
            in->voltageLevel);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get voltage level                                                        */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the voltage domain                        */
/* - out->voltageLevel: The voltage level, in microvolts (uV), that the     */
/*   domain is set to                                                       */
/*                                                                          */
/* Process the VOLTAGE_LEVEL_GET message. Platform handler for              */
/* SCMI_VoltageLevelGet(). See section 4.9.2.10 in the SCMI spec.           */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the voltage level of the domain was returned        */
/*   successfully.                                                          */
/* - SM_ERR_NOT_FOUND: if domainId does not point to a valid voltage        */
/*   domain.                                                                */
/* - SM_ERR_NOT_SUPPORTED: if the request is not supported.                 */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t VoltageLevelGet(const scmi_caller_t *caller,
    const msg_rvoltage8_t *in, msg_tvoltage8_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_VOLT))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get voltage level */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_VoltageLevelGet(caller->lmId, in->domainId,
            &(out->voltageLevel));
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
/* SCMI_VoltageNegotiateProtocolVersion(). See section 4.9.2.2 in the SCMI  */
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
static int32_t VoltageNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rvoltage16_t *in, const scmi_msg_status_t *out)
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
static int32_t VoltageResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all voltage domains */
    for (uint32_t domainId = 0U; domainId < SM_NUM_VOLT; domainId++)
    {
        /* Turn off voltage */
        if (s_voltState[domainId][agentId] != VOLTAGE_DOMAIN_MODES_OFF)
        {
            status = VoltageConfigUpdate(lmId, agentId, domainId,
                VOLTAGE_DOMAIN_MODES_OFF);
        }
    }

    /* TODO: reset voltage level */

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Aggregate and update the voltage mode                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - lmId: LM to update                                                     */
/* - agentId: Message to update                                             */
/* - domainId: Voltage domain                                               */
/* - mode: New voltage mode                                                 */
/*--------------------------------------------------------------------------*/
static int32_t VoltageConfigUpdate(uint32_t lmId, uint32_t agentId,
    uint32_t domainId, uint8_t mode)
{
    uint32_t scmiInst = g_scmiAgentConfig[agentId].scmiInst;
    uint32_t firstAgent = g_scmiConfig[scmiInst].firstAgent;
    uint32_t numAgents = g_scmiConfig[scmiInst].numAgents;
    uint8_t maxvoltMode = VOLTAGE_DOMAIN_MODES_OFF;

    /* Record agent voltage mode for this domain */
    s_voltState[domainId][agentId] = mode;

    /* Calculate new aggregate state for the domain */
    for (uint32_t a = firstAgent; a < (firstAgent + numAgents); a++)
    {
        /* Keep max state */
        if (s_voltState[domainId][a] > maxvoltMode)
        {
            maxvoltMode = s_voltState[domainId][a];
        }
    }

    /* Inform LMM of voltage mode, LMM will check if changed */
    return LMM_VoltageModeSet(lmId, domainId, maxvoltMode);
}

