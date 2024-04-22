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
/* Interface (SCMI) perf protocol.                                          */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x40000U

/* SCMI perf protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION               0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES            0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES    0x2U
#define COMMAND_PERFORMANCE_DOMAIN_ATTRIBUTES  0x3U
#define COMMAND_PERFORMANCE_DESCRIBE_LEVELS    0x4U
#define COMMAND_PERFORMANCE_LIMITS_SET         0x5U
#define COMMAND_PERFORMANCE_LIMITS_GET         0x6U
#define COMMAND_PERFORMANCE_LEVEL_SET          0x7U
#define COMMAND_PERFORMANCE_LEVEL_GET          0x8U
#define COMMAND_NEGOTIATE_PROTOCOL_VERSION     0x10U
#define COMMAND_SUPPORTED_MASK                 0x101FFUL

/* SCMI max performance domain argument lengths */
#define PERF_MAX_NAME        16U
#define PERF_MAX_PERFLEVELS  SCMI_ARRAY(8U, perf_level_t)

/* SCMI performance power units */
#define PERF_POWER_UNIT_ABSTRACT  0U
#define PERF_POWER_UNIT_MW        1U
#define PERF_POWER_UNIT_UW        2U

/* Local macros */

/* SCMI performance protocol attributes */
#define PERF_PROTO_ATTR_POWER_UNIT(x)   (((x) & 0x3U) << 16U)
#define PERF_PROTO_ATTR_NUM_DOMAINS(x)  (((x) & 0xFFFFU) << 0U)

/* SCMI performance message attributes */
#define PERF_MSG_ATTR_FAST(x)  (((x) & 0x1U) << 0U)

/* SCMI performance domain attributes */
#define PERF_ATTR_LIMIT(x)         (((x) & 0x1U) << 31U)
#define PERF_ATTR_LEVEL(x)         (((x) & 0x1U) << 30U)
#define PERF_ATTR_LIMIT_NOTIFY(x)  (((x) & 0x1U) << 29U)
#define PERF_ATTR_LEVEL_NOTIFY(x)  (((x) & 0x1U) << 28U)
#define PERF_ATTR_FAST(x)          (((x) & 0x1U) << 27U)
#define PERF_ATTR_EXT_NAME(x)      (((x) & 0x1U) << 26U)
#define PERF_ATTR_IDX_MODE(x)      (((x) & 0x1U) << 25U)

/* SCMI performance domain rate limits */
#define PERF_RATE_LIMIT_USECONDS(x)  (((x) & 0xFFFFFU) << 0U)

/* SCMI performance num levels */
#define PERF_NUM_LEVELS_REMAING_LEVELS(x)  (((x) & 0xFFFFU) << 16U)
#define PERF_NUM_LEVELS_NUM_LEVELS(x)      (((x) & 0xFFFU) << 0U)

/* SCMI performance level attributes */
#define PERF_LEVEL_ATTR_LATENCY(x)  (((x) & 0xFFFFU) << 0U)

/* Local types */

/* SCMI performance level */
typedef struct
{
    /* Performance level value */
    uint32_t value;
    /* Power cost */
    uint32_t powerCost;
    /* Attributes */
    uint32_t attributes;
    /* Indicative Frequency */
    uint32_t indicativeFrequency;
    /* Level Index */
    uint32_t levelIndex;
} perf_level_t;

/* Response type for ProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol version */
    uint32_t version;
} msg_tperf0_t;

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
    /* The length in bytes of the shared memory region */
    uint32_t statisticsLen;
} msg_tperf1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rperf2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Flags associated with a specific function in the protocol */
    uint32_t attributes;
} msg_tperf2_t;

/* Request type for PerformanceDomainAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the performance domain */
    uint32_t domainId;
} msg_rperf3_t;

/* Response type for PerformanceDomainAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Domain attributes */
    uint32_t attributes;
    /* Rate limit */
    uint32_t rateLimit;
    /* Base frequency */
    uint32_t sustainedFreq;
    /* Sustained performance */
    uint32_t sustainedPerfLevel;
    /* ASCII name string */
    uint8_t name[PERF_MAX_NAME];
} msg_tperf3_t;

/* Request type for PerformanceDescribeLevels() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the performance domain */
    uint32_t domainId;
    /* Index to the first level */
    uint32_t skipIndex;
} msg_rperf4_t;

/* Response type for PerformanceDescribeLevels() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Number of levels */
    uint32_t numLevels;
    /* Array of performance levels */
    perf_level_t perfLevels[PERF_MAX_PERFLEVELS];
} msg_tperf4_t;

/* Request type for PerformanceLimitsSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the performance domain */
    uint32_t domainId;
    /* Maximum allowed performance level, or level index */
    uint32_t rangeMax;
    /* Minimum allowed performance level, or level index */
    uint32_t rangeMin;
} msg_rperf5_t;

/* Request type for PerformanceLimitsGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the performance domain */
    uint32_t domainId;
} msg_rperf6_t;

/* Response type for PerformanceLimitsGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Maximum allowed performance level, or level index */
    uint32_t rangeMax;
    /* Minimum allowed performance level, or level index */
    uint32_t rangeMin;
} msg_tperf6_t;

/* Request type for PerformanceLevelSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the performance domain */
    uint32_t domainId;
    /* Requested performance level, or level index */
    uint32_t performanceLevel;
} msg_rperf7_t;

/* Request type for PerformanceLevelGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the performance domain */
    uint32_t domainId;
} msg_rperf8_t;

/* Response type for PerformanceLevelGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Current performance level, or level index, of the domain */
    uint32_t performanceLevel;
} msg_tperf8_t;

/* Request type for NegotiateProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* The negotiated protocol version the agent intends to use */
    uint32_t version;
} msg_rperf16_t;

/* Local functions */

static int32_t PerfProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tperf0_t *out);
static int32_t PerfProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tperf1_t *out);
static int32_t PerfProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rperf2_t *in, msg_tperf2_t *out);
static int32_t PerformanceDomainAttributes(const scmi_caller_t *caller,
    const msg_rperf3_t *in, msg_tperf3_t *out);
static int32_t PerformanceDescribeLevels(const scmi_caller_t *caller,
    const msg_rperf4_t *in, msg_tperf4_t *out, uint32_t *len);
static int32_t PerformanceLimitsSet(const scmi_caller_t *caller,
    const msg_rperf5_t *in, const scmi_msg_status_t *out);
static int32_t PerformanceLimitsGet(const scmi_caller_t *caller,
    const msg_rperf6_t *in, msg_tperf6_t *out);
static int32_t PerformanceLevelSet(const scmi_caller_t *caller,
    const msg_rperf7_t *in, const scmi_msg_status_t *out);
static int32_t PerformanceLevelGet(const scmi_caller_t *caller,
    const msg_rperf8_t *in, msg_tperf8_t *out);
static int32_t PerfNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rperf16_t *in, const scmi_msg_status_t *out);
static int32_t PerfResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_PerfDispatchCommand(scmi_caller_t *caller,
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
            lenOut = sizeof(msg_tperf0_t);
            status = PerfProtocolVersion(caller,
                (const scmi_msg_header_t*) in, (msg_tperf0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tperf1_t);
            status = PerfProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tperf1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tperf2_t);
            status = PerfProtocolMessageAttributes(caller,
                (const msg_rperf2_t*) in, (msg_tperf2_t*) out);
            break;
        case COMMAND_PERFORMANCE_DOMAIN_ATTRIBUTES:
            lenOut = sizeof(msg_tperf3_t);
            status = PerformanceDomainAttributes(caller,
                (const msg_rperf3_t*) in, (msg_tperf3_t*) out);
            break;
        case COMMAND_PERFORMANCE_DESCRIBE_LEVELS:
            lenOut = sizeof(msg_tperf4_t);
            status = PerformanceDescribeLevels(caller,
                (const msg_rperf4_t*) in, (msg_tperf4_t*) out, &lenOut);
            break;
        case COMMAND_PERFORMANCE_LIMITS_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = PerformanceLimitsSet(caller, (const msg_rperf5_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_PERFORMANCE_LIMITS_GET:
            lenOut = sizeof(msg_tperf6_t);
            status = PerformanceLimitsGet(caller, (const msg_rperf6_t*) in,
                (msg_tperf6_t*) out);
            break;
        case COMMAND_PERFORMANCE_LEVEL_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = PerformanceLevelSet(caller, (const msg_rperf7_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_PERFORMANCE_LEVEL_GET:
            lenOut = sizeof(msg_tperf8_t);
            status = PerformanceLevelGet(caller, (const msg_rperf8_t*) in,
                (msg_tperf8_t*) out);
            break;
        case COMMAND_NEGOTIATE_PROTOCOL_VERSION:
            lenOut = sizeof(const scmi_msg_status_t);
            status = PerfNegotiateProtocolVersion(caller,
                (const msg_rperf16_t*) in, (const scmi_msg_status_t*) out);
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
int32_t RPC_SCMI_PerfDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return PerfResetAgentConfig(lmId, agentId, permissionsReset);
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
/*   specification, this value must be 0x40000                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_PerfProtocolVersion(). See section 4.5.3.1 in the SCMI spec.        */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PerfProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tperf0_t *out)
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
/*   Bits[31:18] Reserved, must be zero.                                    */
/*   Bits[17:16] Power Unit:                                                */
/*   Set to 2 if the power consumption of performance levels is expressed   */
/*   in uW.                                                                 */
/*   Set to 1 if the power consumption of performance levels is expressed   */
/*   in mW.                                                                 */
/*   Set to 0 if the power consumption of performance levels is expressed   */
/*   in an abstract linear scale.                                           */
/*   All other values are reserved and must not be used.                    */
/*   Bits[15:0] Number of performance domains                               */
/* - out->statisticsAddressLow: Low address: The lower 32 bits of the       */
/*   physical address where the statistics shared memory region is          */
/*   located. This value should be 64-bit aligned. The address must be in   */
/*   the memory map of the calling agent. If the statisticsLen field is 0,  */
/*   then this field is invalid and must be ignored                         */
/* - out->statisticsAddressHigh: High address: The upper 32 bit of the      */
/*   physical address where the shared memory region is located. The        */
/*   address must be in the memory map of the calling agent. If the         */
/*   statisticsLen field is 0, then this field is invalid and must be       */
/*   ignored                                                                */
/* - out->statisticsLen: The length in bytes of the shared memory region.   */
/*   A value of 0 in this field indicates that the platform does not        */
/*   support the statistics shared memory region                            */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_PerfProtocolAttributes(). See section 4.5.3.3 in the SCMI spec.     */
/*                                                                          */
/*  Access macros:                                                          */
/* - PERF_PROTO_ATTR_POWER_UNIT() - Power Unit                              */
/* - PERF_PROTO_ATTR_NUM_DOMAINS() - Number of performance domains          */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PerfProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tperf1_t *out)
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
        /* Return number of performance domains */
        out->attributes = PERF_PROTO_ATTR_NUM_DOMAINS((uint32_t)
            SM_NUM_PERF);

        /* Power consumption in mW */
        out->attributes |= PERF_PROTO_ATTR_POWER_UNIT((uint32_t)
            PERF_POWER_UNIT_MW);

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
/* - out->attributes: Flags associated with a specific function in the      */
/*   protocol.                                                              */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] FastChannel Support.                                            */
/*   Set to 1 if there is at least one dedicated FastChannel available for  */
/*   this message.                                                          */
/*   Set to 0 if this there are no FastChannels available this message      */
/*                                                                          */
/* Process the PROTOCOL_MESSAGE_ATTRIBUTES message. Platform handler for    */
/* SCMI_PerfProtocolMessageAttributes(). See section 4.5.3.4 in the SCMI    */
/* spec.                                                                    */
/*                                                                          */
/*  Access macros:                                                          */
/* - PERF_MSG_ATTR_FAST() - FastChannel Support                             */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is invalid    */
/*   or not provided by this platform implementation.                       */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PerfProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rperf2_t *in, msg_tperf2_t *out)
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
/* Get performance domain attributes                                        */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the performance domain                    */
/* - out->attributes: Domain attributes:                                    */
/*   Bit[31] Can set limits.                                                */
/*   Set to 1 if calling agent is allowed to set the performance limits on  */
/*   the domain.                                                            */
/*   Set to 0 if a calling agent is not allowed to set limits on the        */
/*   performance limits on the domain.                                      */
/*   Bit[30] Can set performance level.                                     */
/*   Set to 1 if calling agent is allowed to set the performance of a       */
/*   domain.                                                                */
/*   Set to 0 if a calling agent is not allowed to set the performance of   */
/*   a domain.                                                              */
/*   Only one agent can set the performance of a given domain.              */
/*   Bit[29] Performance limits change notifications support.               */
/*   Set to 1 if performance limits change notifications are supported for  */
/*   this domain.                                                           */
/*   Set to 0 if performance limits change notifications are not supported  */
/*   for this domain.                                                       */
/*   Bit[28] Performance level change notifications support.                */
/*   Set to 1 if performance level change notifications are supported for   */
/*   this domain.                                                           */
/*   Set to 0 if performance level change notifications are not supported   */
/*   for this domain.                                                       */
/*   Bit[27] FastChannel Support.                                           */
/*   Set to 1 if there is at least one FastChannel available for this       */
/*   domain.                                                                */
/*   Set to 0 if there are no FastChannels available for this domain.       */
/*   Bit[26] Extended performance domain name.                              */
/*   If set to 1, the performance domain name is greater than 16 bytes.     */
/*   If set to 0, extended performance domain name is not supported.        */
/*   Bit[25] Level Indexing Mode.                                           */
/*   If set to 1, it indicates that the platform uses Level Indexing Mode.  */
/*   All functions which utilize performance level as a parameter need to   */
/*   specify the corresponding level index instead of the performance       */
/*   level when Level Indexing Mode is used.                                */
/*   If set to 0, Level Indexing Mode is not used.                          */
/*   Bits[24:0] Reserved and set to zero                                    */
/* - out->rateLimit: Rate limit:                                            */
/*   Bits[31:20] Reserved and set to zero.                                  */
/*   Bits[19:0] Rate Limit in microseconds, indicating the minimum time     */
/*   required between successive requests. A value of 0 indicates that      */
/*   this field is not supported by the platform. This field does not       */
/*   apply to FastChannels                                                  */
/* - out->sustainedFreq: Base frequency:  corresponds to the sustained      */
/*   performance level. Expressed in units of kHz                           */
/* - out->sustainedPerfLevel: Sustained performance: performance level      */
/*   value that corresponds to the sustained performance delivered by the   */
/*   platform                                                               */
/* - out->name: Null terminated ASCII string of up to 16 bytes in length    */
/*   describing a domain name. When Bit[26] of attributes field is set to   */
/*   1, this field contains the lower 15 bytes of the NULL terminated       */
/*   performance domain name                                                */
/*                                                                          */
/* Process the PERFORMANCE_DOMAIN_ATTRIBUTES message. Platform handler for  */
/* SCMI_PerformanceDomainAttributes(). See section 4.5.3.5 in the SCMI      */
/* spec.                                                                    */
/*                                                                          */
/*  Access macros:                                                          */
/* - PERF_ATTR_LIMIT() - Can set limits                                     */
/* - PERF_ATTR_LEVEL() - Can set performance level                          */
/* - PERF_ATTR_LIMIT_NOTIFY() - Performance limits change notifications     */
/*   support                                                                */
/* - PERF_ATTR_LEVEL_NOTIFY() - Performance level change notifications      */
/*   support                                                                */
/* - PERF_ATTR_FAST() - FastChannel Support                                 */
/* - PERF_ATTR_EXT_NAME() - Extended performance domain name                */
/* - PERF_ATTR_IDX_MODE() - Level Indexing Mode                             */
/* - PERF_RATE_LIMIT_USECONDS() - Rate Limit in microseconds, indicating    */
/*   the minimum time required between successive requests                  */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid performance domain attributes are found.      */
/* - SM_ERR_NOT_FOUND: if domainId does not point to a valid domain.        */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PerformanceDomainAttributes(const scmi_caller_t *caller,
    const msg_rperf3_t *in, msg_tperf3_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    const uint8_t *nameAddr = (const uint8_t*) "";
    dev_sm_perf_info_t info;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_PERF))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get perf domain info */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_PerfInfoGet(caller->lmId, in->domainId, &info);
    }

    /* Get the perf name */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_PerfNameGet(caller->lmId, in->domainId,
            (string*) &nameAddr, NULL);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        /* Copy info */
        out->rateLimit = info.rateLimit;
        out->sustainedFreq = info.sustainedFreq;
        out->sustainedPerfLevel = info.sustainedPerfLevel;

        /* No notifications */
        out->attributes
            = PERF_ATTR_LIMIT_NOTIFY(0UL)
            | PERF_ATTR_LEVEL_NOTIFY(0UL)
            | PERF_ATTR_FAST(0UL)
            | PERF_ATTR_EXT_NAME(0UL)
            | PERF_ATTR_IDX_MODE(1UL)
            | PERF_RATE_LIMIT_USECONDS(0UL);

        /* Can set performance levels */
        if ((g_scmiAgentConfig[caller->agentId].perfPerms[in->domainId]
            >= SM_SCMI_PERM_PRIV))
        {
            out->attributes |= PERF_ATTR_LEVEL(1UL);
        }

        /* Can set limits */
        if ((g_scmiAgentConfig[caller->agentId].perfPerms[in->domainId]
            >= SM_SCMI_PERM_SET))
        {
            out->attributes |= PERF_ATTR_LIMIT(1UL);
        }

        /* Copy out name */
        RPC_SCMI_StrCpy(out->name, nameAddr, PERF_MAX_NAME);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get performance level descriptions                                       */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the performance domain                    */
/* - in->skipIndex: Index to the first level: Number of performance         */
/*   levels, in numerically ascending order of level values, to skip over   */
/*   before returning the first performance level in the return             */
/*   performance level array                                                */
/* - out->numLevels: Number of levels:                                      */
/*   Bits[31:16] Number of remaining performance levels.                    */
/*   Bits[15:12] Reserved, must be zero.                                    */
/*   Bits[11:0] Number of performance levels that are returned by this      */
/*   call                                                                   */
/* - out->perfLevels: Array of performance levels: numeric ascending        */
/*   order, to be described. N is specified by Bits[11:0] of numLevels      */
/*   field. Each array entry is composed of three 32-bit words with the     */
/*   following format:                                                      */
/*   uint32 entry[0] Performance level value.                               */
/*   uint32 entry[1] Power cost.                                            */
/*   A value of zero indicates that the power cost is not reported by the   */
/*   platform.                                                              */
/*   uint32 entry[2] Attributes                                             */
/*   Bits[31:16] Reserved, must be zero.                                    */
/*   Bits[15:0] Worst-case transition latency in microseconds to move from  */
/*   any supported performance to the level indicated by this entry in the  */
/*   array                                                                  */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the PERFORMANCE_DESCRIBE_LEVELS message. Platform handler for    */
/* SCMI_PerformanceDescribeLevels(). See section 4.5.3.6 in the SCMI spec.  */
/*                                                                          */
/*  Access macros:                                                          */
/* - PERF_NUM_LEVELS_REMAING_LEVELS() - Number of remaining performance     */
/*   levels                                                                 */
/* - PERF_NUM_LEVELS_NUM_LEVELS() - Number of performance levels that are   */
/*   returned by this call                                                  */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid performance levels are returned.              */
/* - SM_ERR_NOT_FOUND: if domainId does not point to a valid domain.        */
/* - SM_ERR_OUT_OF_RANGE: if levelIndex is out of range.                    */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PerformanceDescribeLevels(const scmi_caller_t *caller,
    const msg_rperf4_t *in, msg_tperf4_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t levels = 0U;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_PERF))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get number of levels */
    if (status == SM_ERR_SUCCESS)
    {
        /* Get number of levels */
        status = LMM_PerfNumLevelsGet(caller->lmId, in->domainId,
            &levels);
    }

    /* Check level bounds */
    if ((status == SM_ERR_SUCCESS) && (in->skipIndex >= levels))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Get levels? */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t index;

        out->numLevels = 0U;
        for (index = 0U; index < PERF_MAX_PERFLEVELS; index++)
        {
            dev_sm_perf_desc_t lmmDesc;

            /* Break out if done */
            if ((index + in->skipIndex) >= levels)
            {
                break;
            }

            /* Get performance level */
            status = LMM_PerfDescribe(caller->lmId, in->domainId,
                index + in->skipIndex, &lmmDesc);

            /* Success? */
            if (status == SM_ERR_SUCCESS)
            {
                /* Copy out data */
                out->perfLevels[index].value = lmmDesc.value;
                out->perfLevels[index].powerCost = lmmDesc.powerCost;
                out->perfLevels[index].attributes = lmmDesc.latency;
                out->perfLevels[index].indicativeFrequency= lmmDesc.value;
                out->perfLevels[index].levelIndex= index + in->skipIndex;

                /* Increment count */
                (out->numLevels)++;
            }
        }

        /* Update length */
        *len = (3U * sizeof(uint32_t))
            + (out->numLevels * sizeof(perf_level_t));

        /* Append remaining levels */
        out->numLevels |= PERF_NUM_LEVELS_REMAING_LEVELS(levels
            - (index + in->skipIndex));
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set performance limits                                                   */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the performance domain                    */
/* - in->rangeMax: Maximum allowed performance level, or level index.       */
/*   If this field is set to 0, the platform ignores it and any             */
/*   pre-existing limit on maximum allowed performance level is left        */
/*   unchanged. Both rangeMax and rangeMin cannot be zero at the same time  */
/* - in->rangeMin: Minimum allowed performance level, or level index.       */
/*   If this field is set to 0, the platform ignores it and any             */
/*   pre-existing limit on minimum allowed performance level is left        */
/*   unchanged. Both rangeMax and rangeMin cannot be zero at the same time  */
/*                                                                          */
/* Process the PERFORMANCE_LIMITS_SET message. Platform handler for         */
/* SCMI_PerformanceLimitsSet(). Requires access greater than or equal to    */
/* SET. See section 4.5.3.7 in the SCMI spec.                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the function successfully set the limits of         */
/*   operation. If setting a limit requires modifying the current           */
/*   performance level of the domain, the function can return before this   */
/*   change has been completed. However, the change in performance level    */
/*   must still take place.                                                 */
/* - SM_ERR_NOT_FOUND: if the performance domain identified by domainId     */
/*   does not exist.                                                        */
/* - SM_ERR_OUT_OF_RANGE: if the limits set lie outside the highest and     */
/*   lowest performance levels that are described by                        */
/*   PERFORMANCE_DESCRIBED_LEVELS, or if rangeMax and rangeMin are both     */
/*   zero.                                                                  */
/* - SM_ERR_DENIED: if the calling agent is not permitted to change the     */
/*   performance limits for the domain, as described by                     */
/*   PERFORMANCE_DOMAIN_ATTRIBUTES.                                         */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PerformanceLimitsSet(const scmi_caller_t *caller,
    const msg_rperf5_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_PERF))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].perfPerms[in->domainId]
        < SM_SCMI_PERM_SET))
    {
        status = SM_ERR_DENIED;
    }

    /* Not currently supported */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get performance limits                                                   */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the performance domain                    */
/* - out->rangeMax: Maximum allowed performance level, or level index       */
/* - out->rangeMin: Minimum allowed performance level, or level index       */
/*                                                                          */
/* Process the PERFORMANCE_LIMITS_GET message. Platform handler for         */
/* SCMI_PerformanceLimitsGet(). See section 4.5.3.8 in the SCMI spec.       */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the performance limits are returned successfully.   */
/* - SM_ERR_NOT_FOUND: if domainId does not point to a valid domain.        */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PerformanceLimitsGet(const scmi_caller_t *caller,
    const msg_rperf6_t *in, msg_tperf6_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t numLevels;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_PERF))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get number of levels */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_PerfNumLevelsGet(caller->lmId, in->domainId,
            &numLevels);
    }

    /* Get levels? */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t index;

        /* Set initial extremes */
        out->rangeMin = 0xFFFFFFFFU;
        out->rangeMax = 0x0U;

        /* Loop over levels */
        for (index = 0U; index < numLevels; index++)
        {
            dev_sm_perf_desc_t desc;

            /* Get performance level */
            status = LMM_PerfDescribe(caller->lmId, in->domainId,
                index, &desc);

            /* Error? */
            if (status != SM_ERR_SUCCESS)
            {
                break;
            }

            /* Check min */
            if (desc.value < out->rangeMin)
            {
                out->rangeMin = desc.value;
            }

            /* Check max */
            if (desc.value > out->rangeMax)
            {
                out->rangeMax = desc.value;
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set performance level                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the performance domain                    */
/* - in->performanceLevel: Requested performance level, or level index      */
/*                                                                          */
/* Process the PERFORMANCE_LEVEL_SET message. Platform handler for          */
/* SCMI_PerformanceLevelSet(). Requires access greater than or equal to     */
/* PRIV. See section 4.5.3.9 in the SCMI spec.                              */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the platform has accepted the function and          */
/*   scheduled it for processing.                                           */
/* - SM_ERR_NOT_FOUND: if the domainId parameter does not point to a        */
/*   valid domain.                                                          */
/* - SM_ERR_OUT_OF_RANGE: if the requested performance level is outside     */
/*   the currently allowed range.                                           */
/* - SM_ERR_DENIED: if the calling agent is not permitted to change the     */
/*   performance level for a domain, as described by                        */
/*   PERFORMANCE_DOMAIN_ATTRIBUTES.                                         */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PerformanceLevelSet(const scmi_caller_t *caller,
    const msg_rperf7_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_PERF))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].perfPerms[in->domainId]
        < SM_SCMI_PERM_PRIV))
    {
        status = SM_ERR_DENIED;
    }

    /* Call LMM to set */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_PerfLevelSet(caller->lmId, in->domainId,
            in->performanceLevel);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get performance level                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->domainId: Identifier for the performance domain                    */
/* - out->performanceLevel: Current performance level, or level index, of   */
/*   the domain                                                             */
/*                                                                          */
/* Process the PERFORMANCE_LEVEL_GET message. Platform handler for          */
/* SCMI_PerformanceLevelGet(). See section 4.5.3.10 in the SCMI spec.       */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the performance level is returned successfully      */
/* - SM_ERR_NOT_FOUND: if domainId does not point to a valid domain.        */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t PerformanceLevelGet(const scmi_caller_t *caller,
    const msg_rperf8_t *in, msg_tperf8_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check domain */
    if ((status == SM_ERR_SUCCESS) && (in->domainId >= SM_NUM_PERF))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get level from LMM */
    if (status == SM_ERR_SUCCESS)

    {
        status = LMM_PerfLevelGet(caller->lmId, in->domainId,
            &(out->performanceLevel));
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
/* SCMI_PerfNegotiateProtocolVersion(). See section 4.5.3.2 in the SCMI     */
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
static int32_t PerfNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rperf16_t *in, const scmi_msg_status_t *out)
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
static int32_t PerfResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

