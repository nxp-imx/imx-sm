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
/* Interface (SCMI) cpu protocol.                                           */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x10000U

/* SCMI cpu protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION             0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES          0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES  0x2U
#define COMMAND_CPU_ATTRIBUTES               0x3U
#define COMMAND_CPU_START                    0x4U
#define COMMAND_CPU_STOP                     0x5U
#define COMMAND_CPU_RESET_VECTOR_SET         0x6U
#define COMMAND_CPU_SLEEP_MODE_SET           0x7U
#define COMMAND_CPU_IRQ_WAKE_SET             0x8U
#define COMMAND_CPU_NON_IRQ_WAKE_SET         0x9U
#define COMMAND_CPU_PD_LPM_CONFIG_SET        0xAU
#define COMMAND_CPU_CLK_LPM_CONFIG_SET       0xBU
#define COMMAND_NEGOTIATE_PROTOCOL_VERSION   0x10U
#define COMMAND_SUPPORTED_MASK               0x10FFFUL

/* SCMI max cpu argument lengths */
#define CPU_MAX_NAME          16U
#define CPU_MAX_MASK_T        SCMI_ARRAY(12U, uint32_t)
#define CPU_MAX_PDCONFIGS_T   SCMI_ARRAY(8U, pd_lpm_config_t)
#define CPU_MAX_CLKCONFIGS_T  SCMI_ARRAY(8U, clk_lpm_config_t)

/* SCMI CPU sleep modes */
#define CPU_SLEEP_RUN      0U
#define CPU_SLEEP_WAIT     1U
#define CPU_SLEEP_STOP     2U
#define CPU_SLEEP_SUSPEND  3U

/* SCMI CPU LPM settings */
#define CPU_LPM_SETTING_ON_NEVER          0U
#define CPU_LPM_SETTING_ON_RUN            1U
#define CPU_LPM_SETTING_ON_RUN_WAIT       2U
#define CPU_LPM_SETTING_ON_RUN_WAIT_STOP  3U
#define CPU_LPM_SETTING_ON_ALWAYS         4U

/* Local macros */

/* SCMI cpu protocol attributes */
#define CPU_PROTO_ATTR_NUM_CPUS(x)  (((x) & 0xFFFFU) << 0U)

/* SCMI cpu reset vector set flags */
#define CPU_VEC_FLAGS_RESUME(x)  (((x) & 0x80000000U) >> 31U)
#define CPU_VEC_FLAGS_START(x)   (((x) & 0x40000000U) >> 30U)
#define CPU_VEC_FLAGS_BOOT(x)    (((x) & 0x20000000U) >> 29U)
#define CPU_VEC_FLAGS_TABLE(x)   (((x) & 0x1U) >> 0U)

/* Local types */

/* SCMI CPU PD LPM configuration */
typedef struct
{
    /* Power domain ID */
    uint32_t domainId;
    /* LPM setting */
    uint32_t lpmSetting;
    /* Retention mask */
    uint32_t retMask;
} pd_lpm_config_t;

/* SCMI CPU clock LPM configuration */
typedef struct
{
    /* Clock ID */
    uint32_t clockId;
    /* LPM setting */
    uint32_t lpmSetting;
} clk_lpm_config_t;

/* Response type for ProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol version */
    uint32_t version;
} msg_tcpu0_t;

/* Response type for ProtocolAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol attributes */
    uint32_t attributes;
} msg_tcpu1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rcpu2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_tcpu2_t;

/* Request type for CpuAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the CPU */
    uint32_t cpuId;
} msg_rcpu3_t;

/* Response type for CpuAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* CPU attributes */
    uint32_t attributes;
    /* ASCII name string */
    uint8_t name[CPU_MAX_NAME];
} msg_tcpu3_t;

/* Request type for CpuStart() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the CPU */
    uint32_t cpuId;
} msg_rcpu4_t;

/* Request type for CpuStop() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the CPU */
    uint32_t cpuId;
} msg_rcpu5_t;

/* Request type for CpuResetVectorSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the CPU */
    uint32_t cpuId;
    /* Reset vector flags */
    uint32_t flags;
    /* Lower vector */
    uint32_t resetVectorLow;
    /* Upper vector */
    uint32_t resetVectorHigh;
} msg_rcpu6_t;

/* Request type for CpuSleepModeSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the CPU */
    uint32_t cpuId;
    /* Sleep mode flags */
    uint32_t flags;
    /* Target sleep mode */
    uint32_t sleepMode;
} msg_rcpu7_t;

/* Request type for CpuIrqWakeSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the CPU */
    uint32_t cpuId;
    /* Index of first mask to set */
    uint32_t maskIdx;
    /* Number of masks to set */
    uint32_t numMask;
    /* Mask data array */
    uint32_t mask[CPU_MAX_MASK_T];
} msg_rcpu8_t;

/* Request type for CpuNonIrqWakeSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the CPU */
    uint32_t cpuId;
    /* Index of first mask to set */
    uint32_t maskIdx;
    /* Number of masks to set */
    uint32_t numMask;
    /* Mask data array */
    uint32_t mask[CPU_MAX_MASK_T];
} msg_rcpu9_t;

/* Request type for CpuPdLpmConfigSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the CPU */
    uint32_t cpuId;
    /* Number of power domains to configure */
    uint32_t numConfigs;
    /* LPM configuration data array */
    pd_lpm_config_t pdConfigs[CPU_MAX_PDCONFIGS_T];
} msg_rcpu10_t;

/* Request type for CpuClkLpmConfigSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the CPU */
    uint32_t cpuId;
    /* Number of power domains to configure */
    uint32_t numConfigs;
    /* LPM configuration data array */
    clk_lpm_config_t clkConfigs[CPU_MAX_CLKCONFIGS_T];
} msg_rcpu11_t;

/* Request type for NegotiateProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* The negotiated protocol version the agent intends to use */
    uint32_t version;
} msg_rcpu16_t;

/* Local functions */

static int32_t CpuProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tcpu0_t *out);
static int32_t CpuProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tcpu1_t *out);
static int32_t CpuProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rcpu2_t *in, msg_tcpu2_t *out);
static int32_t CpuAttributes(const scmi_caller_t *caller,
    const msg_rcpu3_t *in, msg_tcpu3_t *out);
static int32_t CpuStart(const scmi_caller_t *caller, const msg_rcpu4_t *in,
    const scmi_msg_status_t *out);
static int32_t CpuStop(const scmi_caller_t *caller, const msg_rcpu5_t *in,
    const scmi_msg_status_t *out);
static int32_t CpuResetVectorSet(const scmi_caller_t *caller,
    const msg_rcpu6_t *in, const scmi_msg_status_t *out);
static int32_t CpuSleepModeSet(const scmi_caller_t *caller,
    const msg_rcpu7_t *in, const scmi_msg_status_t *out);
static int32_t CpuIrqWakeSet(const scmi_caller_t *caller,
    const msg_rcpu8_t *in, const scmi_msg_status_t *out);
static int32_t CpuNonIrqWakeSet(const scmi_caller_t *caller,
    const msg_rcpu9_t *in, const scmi_msg_status_t *out);
static int32_t CpuPdLpmConfigSet(const scmi_caller_t *caller,
    const msg_rcpu10_t *in, const scmi_msg_status_t *out);
static int32_t CpuClkLpmConfigSet(const scmi_caller_t *caller,
    const msg_rcpu11_t *in, const scmi_msg_status_t *out);
static int32_t CpuNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rcpu16_t *in, const scmi_msg_status_t *out);
static int32_t CpuResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_CpuDispatchCommand(scmi_caller_t *caller,
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
            lenOut = sizeof(msg_tcpu0_t);
            status = CpuProtocolVersion(caller, (const scmi_msg_header_t*) in,
                (msg_tcpu0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tcpu1_t);
            status = CpuProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tcpu1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tcpu2_t);
            status = CpuProtocolMessageAttributes(caller,
                (const msg_rcpu2_t*) in, (msg_tcpu2_t*) out);
            break;
        case COMMAND_CPU_ATTRIBUTES:
            lenOut = sizeof(msg_tcpu3_t);
            status = CpuAttributes(caller, (const msg_rcpu3_t*) in,
                (msg_tcpu3_t*) out);
            break;
        case COMMAND_CPU_START:
            lenOut = sizeof(const scmi_msg_status_t);
            status = CpuStart(caller, (const msg_rcpu4_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_CPU_STOP:
            lenOut = sizeof(const scmi_msg_status_t);
            status = CpuStop(caller, (const msg_rcpu5_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_CPU_RESET_VECTOR_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = CpuResetVectorSet(caller, (const msg_rcpu6_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_CPU_SLEEP_MODE_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = CpuSleepModeSet(caller, (const msg_rcpu7_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_CPU_IRQ_WAKE_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = CpuIrqWakeSet(caller, (const msg_rcpu8_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_CPU_NON_IRQ_WAKE_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = CpuNonIrqWakeSet(caller, (const msg_rcpu9_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_CPU_PD_LPM_CONFIG_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = CpuPdLpmConfigSet(caller, (const msg_rcpu10_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_CPU_CLK_LPM_CONFIG_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = CpuClkLpmConfigSet(caller, (const msg_rcpu11_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_NEGOTIATE_PROTOCOL_VERSION:
            lenOut = sizeof(const scmi_msg_status_t);
            status = CpuNegotiateProtocolVersion(caller,
                (const msg_rcpu16_t*) in, (const scmi_msg_status_t*) out);
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
int32_t RPC_SCMI_CpuDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return CpuResetAgentConfig(lmId, agentId, permissionsReset);
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
/*   specification, this value must be 0x10000                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_CpuProtocolVersion().                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tcpu0_t *out)
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
/*   Bits[15:0] Number of CPUs                                              */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_CpuProtocolAttributes().                                            */
/*                                                                          */
/*  Access macros:                                                          */
/* - CPU_PROTO_ATTR_NUM_CPUS() - Number of CPUs                             */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tcpu1_t *out)
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
        /* Return number of CPUs */
        out->attributes = CPU_PROTO_ATTR_NUM_CPUS((uint32_t) SM_NUM_CPU);
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
/* SCMI_CpuProtocolMessageAttributes().                                     */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is invalid    */
/*   or not implemented.                                                    */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rcpu2_t *in, msg_tcpu2_t *out)
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
/* Get CPU attributes                                                       */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->cpuId: Identifier for the CPU                                      */
/* - out->attributes: CPU attributes:                                       */
/*   Bits[31:0] Reserved, must be zero                                      */
/* - out->name: A NULL terminated ASCII string with the CPU name, of up to  */
/*   16 bytes                                                               */
/*                                                                          */
/* Process the CPU_ATTRIBUTES message. Platform handler for                 */
/* SCMI_CpuAttributes().                                                    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if valid attributes are returned.                      */
/* - SM_ERR_NOT_FOUND: if cpuId does not point to a valid CPU.              */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuAttributes(const scmi_caller_t *caller,
    const msg_rcpu3_t *in, msg_tcpu3_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    const uint8_t *nameAddr = (const uint8_t*) "";

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check CPU */
    if ((status == SM_ERR_SUCCESS) && (in->cpuId >= SM_NUM_CPU))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get the CPU name */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_CpuNameGet(caller->lmId, in->cpuId,
            (string*) &nameAddr, NULL);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        /* No attributes */
        out->attributes = 0U;

        /* Copy out name */
        RPC_SCMI_StrCpy(out->name, nameAddr, CPU_MAX_NAME);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Start a CPU                                                              */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->cpuId: Identifier for the CPU                                      */
/*                                                                          */
/* Process the CPU_START message. Platform handler for SCMI_CpuStart().     */
/* Requires access greater than or equal to EXCLUSIVE.                      */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the CPU is started successfully.                    */
/* - SM_ERR_NOT_FOUND: if cpuId does not point to a valid CPU.              */
/* - SM_ERR_DENIED: if the calling agent is not allowed to start this       */
/*   CPU.                                                                   */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuStart(const scmi_caller_t *caller, const msg_rcpu4_t *in,
    const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check CPU */
    if ((status == SM_ERR_SUCCESS) && (in->cpuId >= SM_NUM_CPU))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].cpuPerms[in->cpuId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Start CPU */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_CpuStart(caller->lmId, in->cpuId);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Stop a CPU                                                               */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->cpuId: Identifier for the CPU                                      */
/*                                                                          */
/* Process the CPU_STOP message. Platform handler for SCMI_CpuStop().       */
/* Requires access greater than or equal to EXCLUSIVE.                      */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the CPU is stopped successfully.                    */
/* - SM_ERR_NOT_FOUND: if cpuId does not point to a valid CPU.              */
/* - SM_ERR_DENIED: if the calling agent is not allowed to stop this        */
/*   CPU.                                                                   */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuStop(const scmi_caller_t *caller, const msg_rcpu5_t *in,
    const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check CPU */
    if ((status == SM_ERR_SUCCESS) && (in->cpuId >= SM_NUM_CPU))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].cpuPerms[in->cpuId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Stop CPU */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_CpuStop(caller->lmId, in->cpuId);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set reset vector                                                         */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->cpuId: Identifier for the CPU                                      */
/* - in->flags: Reset vector flags:                                         */
/*   Bit[31] Resume flag.                                                   */
/*   Set to 1 to update the reset vector used on resume.                    */
/*   Bit[30] Boot flag.                                                     */
/*   Set to 1 to update the reset vector used for boot.                     */
/*   Bits[29:1] Reserved, must be zero.                                     */
/*   Bit[0] Table flag.                                                     */
/*   Set to 1 if vector is the vector table base address.                   */
/* - in->resetVectorLow: Lower vector:                                      */
/*   If bit[0] of flags is 0, the lower 32 bits of the physical address     */
/*   where the CPU should execute from on reset.                            */
/*   If bit[0] of flags is 1, the lower 32 bits of the vector table base    */
/*   address                                                                */
/* - in->resetVectorHigh: Upper vector:                                     */
/*   If bit[0] of flags is 0, the upper 32 bits of the physical address     */
/*   where the CPU should execute from on reset.                            */
/*   If bit[0] of flags is 1, the upper 32 bits of the vector table base    */
/*   address                                                                */
/*                                                                          */
/* Process the CPU_RESET_VECTOR_SET message. Platform handler for           */
/* SCMI_CpuResetVectorSet(). Requires access greater than or equal to       */
/* EXCLUSIVE.                                                               */
/*                                                                          */
/*  Access macros:                                                          */
/* - CPU_VEC_FLAGS_RESUME() - Resume flag                                   */
/* - CPU_VEC_FLAGS_START() - Start flag                                     */
/* - CPU_VEC_FLAGS_BOOT() - Boot flag                                       */
/* - CPU_VEC_FLAGS_TABLE() - Table flag                                     */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the CPU reset vector is set successfully.           */
/* - SM_ERR_NOT_FOUND: if cpuId does not point to a valid CPU.              */
/* - SM_ERR_INVALID_PARAMETERS: if the requested vector type is not         */
/*   supported by this CPU.                                                 */
/* - SM_ERR_DENIED: if the calling agent is not allowed to set the reset    */
/*   vector of this CPU.                                                    */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuResetVectorSet(const scmi_caller_t *caller,
    const msg_rcpu6_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool boot = CPU_VEC_FLAGS_BOOT(in->flags) != 0U;
    bool start = CPU_VEC_FLAGS_START(in->flags) != 0U;
    bool resume = CPU_VEC_FLAGS_RESUME(in->flags) != 0U;
    bool table = CPU_VEC_FLAGS_TABLE(in->flags) != 0U;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check CPU */
    if ((status == SM_ERR_SUCCESS) && (in->cpuId >= SM_NUM_CPU))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].cpuPerms[in->cpuId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Check flags */
    if ((!boot) && (!resume) && (!start))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Set boot address */
    if (status == SM_ERR_SUCCESS)
    {
        uint64_t resetVector = (((uint64_t) in->resetVectorHigh) << 32U)
            | (uint64_t) in->resetVectorLow;

        status = LMM_CpuResetVectorSet(caller->lmId, in->cpuId,
            resetVector, boot, start, resume, table);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set a CPU sleep target mode                                              */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->cpuId: Identifier for the CPU                                      */
/* - in->flags: Sleep mode flags:                                           */
/*   Bits[31:1] Reserved, must be zero.                                     */
/*   Bit[0] IRQ mux:                                                        */
/*   If set to 1 the the wakeup mux source is the GIC, else if 0 then the   */
/*   GPC                                                                    */
/* - in->sleepMode: Target sleep mode                                       */
/*                                                                          */
/* Process the CPU_SLEEP_MODE_SET message. Platform handler for             */
/* SCMI_CpuSleepModeSet(). Requires access greater than or equal to         */
/* EXCLUSIVE.                                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the CPU is started successfully.                    */
/* - SM_ERR_NOT_FOUND: if cpuId does not point to a valid CPU.              */
/* - SM_ERR_INVALID_PARAMETERS: if sleepMode is invalid.                    */
/* - SM_ERR_DENIED: if the calling agent is not allowed to configure        */
/*   this CPU.                                                              */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuSleepModeSet(const scmi_caller_t *caller,
    const msg_rcpu7_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t sleepMode = in->sleepMode;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check CPU */
    if ((status == SM_ERR_SUCCESS) && (in->cpuId >= SM_NUM_CPU))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].cpuPerms[in->cpuId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Check and translate to device CPU sleep mode */
    if (status == SM_ERR_SUCCESS)
    {
        switch (sleepMode)
        {
            case CPU_SLEEP_RUN:
                sleepMode = DEV_SM_CPU_SLEEP_MODE_RUN;
                break;
            case CPU_SLEEP_WAIT:
                sleepMode = DEV_SM_CPU_SLEEP_MODE_WAIT;
                break;
            case CPU_SLEEP_STOP:
                sleepMode = DEV_SM_CPU_SLEEP_MODE_STOP;
                break;
            case CPU_SLEEP_SUSPEND:
                sleepMode = DEV_SM_CPU_SLEEP_MODE_SUSPEND;
                break;
            default:
                status = SM_ERR_INVALID_PARAMETERS;
                break;
        }
    }

    /* Set CPU sleep mode */
    if (status == SM_ERR_SUCCESS)
    {
        /* Set sleep mode */
        status = LMM_CpuSleepModeSet(caller->lmId, in->cpuId, sleepMode,
            in->flags);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set a CPU IRQ wake mask                                                  */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->cpuId: Identifier for the CPU                                      */
/* - in->maskIdx: Index of first mask to set                                */
/* - in->numMask: Number of masks to set                                    */
/* - in->mask: Mask data array                                              */
/*                                                                          */
/* Process the CPU_IRQ_WAKE_SET message. Platform handler for               */
/* SCMI_CpuIrqWakeSet(). Requires access greater than or equal to           */
/* EXCLUSIVE.                                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the CPU is started successfully.                    */
/* - SM_ERR_NOT_FOUND: if cpuId does not point to a valid CPU.              */
/* - SM_ERR_INVALID_PARAMETERS: if maskIdx or numMask is invalid.           */
/* - SM_ERR_DENIED: if the calling agent is not allowed to configure        */
/*   this CPU.                                                              */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuIrqWakeSet(const scmi_caller_t *caller,
    const msg_rcpu8_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < ((4U + in->numMask) * sizeof(uint32_t)))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check CPU */
    if ((status == SM_ERR_SUCCESS) && (in->cpuId >= SM_NUM_CPU))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].cpuPerms[in->cpuId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Write all the masks */
    for (uint32_t idx = 0U; idx < in->numMask; idx++)
    {
        /* Check status */
        if (status != SM_ERR_SUCCESS)
        {
            break;
        }

        /* Set mask */
        status = LMM_CpuIrqWakeSet(caller->lmId, in->cpuId, in->maskIdx
            + idx, in->mask[idx]);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set a CPU non-IRQ wake mask                                              */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->cpuId: Identifier for the CPU                                      */
/* - in->maskIdx: Index of first mask to set                                */
/* - in->numMask: Number of masks to set                                    */
/* - in->mask: Mask data array                                              */
/*                                                                          */
/* Process the CPU_NON_IRQ_WAKE_SET message. Platform handler for           */
/* SCMI_CpuNonIrqWakeSet(). Requires access greater than or equal to        */
/* EXCLUSIVE.                                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the CPU is started successfully.                    */
/* - SM_ERR_NOT_FOUND: if cpuId does not point to a valid CPU.              */
/* - SM_ERR_INVALID_PARAMETERS: if maskIdx or numMask is invalid.           */
/* - SM_ERR_DENIED: if the calling agent is not allowed to configure        */
/*   this CPU.                                                              */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuNonIrqWakeSet(const scmi_caller_t *caller,
    const msg_rcpu9_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < ((4U + in->numMask) * sizeof(uint32_t)))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check CPU */
    if ((status == SM_ERR_SUCCESS) && (in->cpuId >= SM_NUM_CPU))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].cpuPerms[in->cpuId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Write all the masks */
    for (uint32_t idx = 0U; idx < in->numMask; idx++)
    {
        /* Check status */
        if (status != SM_ERR_SUCCESS)
        {
            break;
        }

        /* Set mask */
        status = LMM_CpuNonIrqWakeSet(caller->lmId, in->cpuId, in->maskIdx
            + idx, in->mask[idx]);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure a list of power domain LPM configs                             */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->cpuId: Identifier for the CPU                                      */
/* - in->numConfigs: Number of power domains to configure                   */
/* - in->pdConfigs: LPM configuration data array                            */
/*                                                                          */
/* Process the CPU_PD_LPM_CONFIG_SET message. Platform handler for          */
/* SCMI_CpuPdLpmConfigSet(). Requires access greater than or equal to       */
/* EXCLUSIVE.                                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the CPU is started successfully.                    */
/* - SM_ERR_NOT_FOUND: if cpuId or a power domain does not exist.           */
/* - SM_ERR_INVALID_PARAMETERS: if numConfigs or an LPM setting is          */
/*   invalid.                                                               */
/* - SM_ERR_DENIED: if the calling agent is not allowed to configure        */
/*   this CPU.                                                              */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuPdLpmConfigSet(const scmi_caller_t *caller,
    const msg_rcpu10_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t numConfigs = in->numConfigs;

    /* Check request length */
    if (caller->lenCopy < ((3U * sizeof(uint32_t))
        + (numConfigs * sizeof(pd_lpm_config_t))))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check CPU */
    if ((status == SM_ERR_SUCCESS) && (in->cpuId >= SM_NUM_CPU))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].cpuPerms[in->cpuId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Write all the configs */
    for (uint32_t idx = 0U; idx < numConfigs; idx++)
    {
        const pd_lpm_config_t *config = &in->pdConfigs[idx];

        /* Check status */
        if (status != SM_ERR_SUCCESS)
        {
            break;
        }

        /* Set config */
        status = LMM_CpuPdLpmConfigSet(caller->lmId, in->cpuId,
            config->domainId, config->lpmSetting, config->retMask);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure a list of clock LPM configs                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->cpuId: Identifier for the CPU                                      */
/* - in->numConfigs: Number of power domains to configure                   */
/* - in->clkConfigs: LPM configuration data array                           */
/*                                                                          */
/* Process the CPU_CLK_LPM_CONFIG_SET message. Platform handler for         */
/* SCMI_CpuClkLpmConfigSet(). Requires access greater than or equal to      */
/* EXCLUSIVE.                                                               */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the CPU is started successfully.                    */
/* - SM_ERR_NOT_FOUND: if cpuId or a power domain does not exist.           */
/* - SM_ERR_INVALID_PARAMETERS: if numConfigs or an LPM setting is          */
/*   invalid.                                                               */
/* - SM_ERR_DENIED: if the calling agent is not allowed to configure        */
/*   this CPU.                                                              */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuClkLpmConfigSet(const scmi_caller_t *caller,
    const msg_rcpu11_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t numConfigs = in->numConfigs;

    /* Check request length */
    if (caller->lenCopy < ((3U * sizeof(uint32_t))
        + (numConfigs * sizeof(clk_lpm_config_t))))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check CPU */
    if ((status == SM_ERR_SUCCESS) && (in->cpuId >= SM_NUM_CPU))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].cpuPerms[in->cpuId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Write all the configs */
    for (uint32_t idx = 0U; idx < numConfigs; idx++)
    {
        const clk_lpm_config_t *config = &in->clkConfigs[idx];

        /* Check status */
        if (status != SM_ERR_SUCCESS)
        {
            break;
        }

        /* Set config */
        status = LMM_CpuClkLpmConfigSet(caller->lmId, in->cpuId,
            config->clockId, config->lpmSetting);
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
/* SCMI_CpuNegotiateProtocolVersion().                                      */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the negotiated protocol version is supported by     */
/*   the platform. All commands, responses, and notifications post          */
/*   successful return of this command must comply with the negotiated      */
/*   version.                                                               */
/* - SM_ERR_NOT_SUPPORTED: if the protocol version is not supported.        */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t CpuNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rcpu16_t *in, const scmi_msg_status_t *out)
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
static int32_t CpuResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over all CPUs */
    for (uint32_t cpuId = 0U; cpuId < SM_NUM_CPU; cpuId++)
    {
        /* Reset rate */
        if (g_scmiAgentConfig[agentId].cpuPerms[cpuId]
            >= SM_SCMI_PERM_EXCLUSIVE)
        {
            (void) LMM_CpuResetVectorReset(lmId, cpuId);
        }
    }

    /* Return status */
    return status;
}

