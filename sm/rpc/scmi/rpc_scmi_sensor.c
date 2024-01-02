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
/* Interface (SCMI) sensor protocol.                                        */
/*==========================================================================*/

/* Includes */

#include "rpc_scmi_internal.h"
#include "lmm.h"

/* Local defines */

/* Protocol version */
#define PROTOCOL_VERSION  0x30001U

/* SCMI sensor protocol message IDs and masks */
#define COMMAND_PROTOCOL_VERSION             0x0U
#define COMMAND_PROTOCOL_ATTRIBUTES          0x1U
#define COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES  0x2U
#define COMMAND_SENSOR_DESCRIPTION_GET       0x3U
#define COMMAND_SENSOR_TRIP_POINT_NOTIFY     0x4U
#define COMMAND_SENSOR_TRIP_POINT_CONFIG     0x5U
#define COMMAND_SENSOR_READING_GET           0x6U
#define COMMAND_SENSOR_CONFIG_GET            0x9U
#define COMMAND_SENSOR_CONFIG_SET            0xAU
#define COMMAND_NEGOTIATE_PROTOCOL_VERSION   0x10U
#define COMMAND_SUPPORTED_MASK               0x1067FUL

/* SCMI max sensor argument lengths */
#define SENSOR_MAX_NAME      16U
#define SENSOR_MAX_DESC      SCMI_ARRAY(8U, sensor_desc_t)
#define SENSOR_MAX_READINGS  SCMI_ARRAY(4U, sensor_reading_t)

/* SCMI sensor TP events */
#define SENSOR_TP_NONE  0U
#define SENSOR_TP_POS   1U
#define SENSOR_TP_NEG   2U
#define SENSOR_TP_BOTH  3U

/* Local macros */

/* SCMI sensor protocol attributes */
#define SENSOR_PROTO_ATTR_MAX_PENDING(x)  (((x) & 0xFFU) << 16U)
#define SENSOR_PROTO_ATTR_NUM_SENSORS(x)  (((x) & 0xFFFFU) << 0U)

/* SCMI num sensor flags */
#define SENSOR_NUM_SENSOR_FLAGS_REMAINING_DESCS(x)  (((x) & 0xFFFFU) << 16U)
#define SENSOR_NUM_SENSOR_FLAGS_NUM_DESCS(x)        (((x) & 0xFFFU) << 0U)

/* SCMI sensor attributes (low) */
#define SENSOR_ATTR_LOW_ASYNC(x)         (((x) & 0x1U) << 31U)
#define SENSOR_ATTR_LOW_CONTINUOUS(x)    (((x) & 0x1U) << 30U)
#define SENSOR_ATTR_LOW_EXT_NAME(x)      (((x) & 0x1U) << 29U)
#define SENSOR_ATTR_LOW_TIME_EXP(x)      (((x) & 0x1FU) << 10U)
#define SENSOR_ATTR_LOW_TIME_SUPPORT(x)  (((x) & 0x1U) << 9U)
#define SENSOR_ATTR_LOW_EXT_ATTR(x)      (((x) & 0x1U) << 8U)
#define SENSOR_ATTR_LOW_NUM_TP(x)        (((x) & 0xFFU) << 0U)

/* SCMI sensor attributes (high) */
#define SENSOR_ATTR_HIGH_NUM_AXIS(x)      (((x) & 0x3FU) << 16U)
#define SENSOR_ATTR_HIGH_SENSOR_EXP(x)    (((x) & 0x1FU) << 11U)
#define SENSOR_ATTR_HIGH_AXIS_SUPPORT(x)  (((x) & 0x1U) << 8U)
#define SENSOR_ATTR_HIGH_SENSOR_TYPE(x)   (((x) & 0xFFU) << 0U)

/* SCMI sensor event control */
#define SENSOR_EV_CTRL_ENABLE(x)  (((x) & 0x1U) >> 0U)

/* SCMI sensor trip point event control */
#define SENSOR_TP_EV_CTRL_TRIP_ID(x)  (((x) & 0xFF0U) >> 4U)
#define SENSOR_TP_EV_CTRL(x)          (((x) & 0x3U) >> 0U)

/* SCMI sensor read flags */
#define SENSOR_READ_FLAGS_ASYNC(x)  (((x) & 0x1U) >> 0U)

/* SCMI sensor config (get) */
#define SENSOR_CONFIG_GET_UPDATE_INTV_SEC(x)  (((x) & 0xFFFFU) << 16U)
#define SENSOR_CONFIG_GET_UPDATE_INTV_EXP(x)  (((x) & 0x1FU) << 11U)
#define SENSOR_CONFIG_GET_TS_ENABLED(x)       (((x) & 0x1U) << 1U)
#define SENSOR_CONFIG_GET_ENABLED(x)          (((x) & 0x1U) << 0U)

/* SCMI sensor config (set) */
#define SENSOR_CONFIG_SET_UPDATE_INTV_SEC(x)  (((x) & 0xFFFF0000U) >> 16U)
#define SENSOR_CONFIG_SET_UPDATE_INTV_EXP(x)  (((x) & 0xF800U) >> 11U)
#define SENSOR_CONFIG_SET_ROUND(x)            (((x) & 0x600U) >> 9U)
#define SENSOR_CONFIG_SET_TS_ENABLE(x)        (((x) & 0x2U) >> 1U)
#define SENSOR_CONFIG_SET_ENABLE(x)           (((x) & 0x1U) >> 0U)

/* SCMI sensor event description */
#define SENSOR_EVENT_DIRECTION(x)  (((x) & 0x1U) << 16U)
#define SENSOR_EVENT_TP_ID(x)      (((x) & 0xFFU) << 0U)

/* Local types */

/* SCMI sensor descriptor */
typedef struct
{
    /* Identifier for the sensor */
    uint32_t sensorId;
    /* Lower 32 bit of the sensor attributes */
    uint32_t sensorAttributesLow;
    /* Upper 32 bit of the sensor attributes */
    uint32_t sensorAttributesHigh;
    /* A NULL terminated UTF-8 format string with the sensor name, of up to
        16 bytes */
    uint8_t name[16];
} sensor_desc_t;

/* SCMI sensor reading */
typedef struct
{
    /* Lower 32 bits of the sensor value */
    int32_t sensorValueLow;
    /* Higher 32 bits of the sensor value */
    int32_t sensorValueHigh;
    /* Lower 32 bits of the timestamp */
    uint32_t timestampLow;
    /* Higher 32 bits of the timestamp */
    uint32_t timestampHigh;
} sensor_reading_t;

/* Response type for ProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Protocol version */
    uint32_t version;
} msg_tsensor0_t;

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
    uint32_t sensorRegAddressLow;
    /* High address */
    uint32_t sensorRegAddressHigh;
    /* Stats length */
    uint32_t sensorRegLen;
} msg_tsensor1_t;

/* Request type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* message ID of the message */
    uint32_t messageId;
} msg_rsensor2_t;

/* Response type for ProtocolMessageAttributes() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Message attributes */
    uint32_t attributes;
} msg_tsensor2_t;

/* Request type for SensorDescriptionGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Descriptor index */
    uint32_t descIndex;
} msg_rsensor3_t;

/* Response type for SensorDescriptionGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Flags for number of sensors */
    uint32_t numSensorFlags;
    /* An array of sensor descriptors */
    sensor_desc_t desc[SENSOR_MAX_DESC];
} msg_tsensor3_t;

/* Request type for SensorTripPointNotify() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the sensor */
    uint32_t sensorId;
    /* Event control */
    uint32_t sensorEventControl;
} msg_rsensor4_t;

/* Request type for SensorTripPointConfig() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the sensor */
    uint32_t sensorId;
    /* Event control */
    uint32_t tripPointEvCtrl;
    /* Lower 32 bits of the sensor value */
    int32_t tripPointValLow;
    /* Higher 32 bits of the sensor value */
    int32_t tripPointValHigh;
} msg_rsensor5_t;

/* Request type for SensorReadingGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the sensor */
    uint32_t sensorId;
    /* Read flags */
    uint32_t flags;
} msg_rsensor6_t;

/* Response type for SensorReadingGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* An array of sensor readings */
    sensor_reading_t readings[SENSOR_MAX_READINGS];
} msg_tsensor6_t;

/* Request type for SensorConfigGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the sensor */
    uint32_t sensorId;
} msg_rsensor9_t;

/* Response type for SensorConfigGet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Return status */
    int32_t status;
    /* Sensor config */
    uint32_t sensorConfig;
} msg_tsensor9_t;

/* Request type for SensorConfigSet() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Identifier for the sensor */
    uint32_t sensorId;
    /* Sensor config */
    uint32_t sensorConfig;
} msg_rsensor10_t;

/* Request type for NegotiateProtocolVersion() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* The negotiated protocol version the agent intends to use */
    uint32_t version;
} msg_rsensor16_t;

/* Request type for SensorTripPointEvent() */
typedef struct
{
    /* Header word */
    uint32_t header;
    /* Refers to the agent that caused this event */
    uint32_t agentId;
    /* Identifier for the sensor that has tripped */
    uint32_t sensorId;
    /* Event flags */
    uint32_t tripPointDesc;
} msg_rsensor32_t;

/* Local functions */

static int32_t SensorProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tsensor0_t *out);
static int32_t SensorProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tsensor1_t *out);
static int32_t SensorProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rsensor2_t *in, msg_tsensor2_t *out);
static int32_t SensorDescriptionGet(const scmi_caller_t *caller,
    const msg_rsensor3_t *in, msg_tsensor3_t *out, uint32_t *len);
static int32_t SensorTripPointNotify(const scmi_caller_t *caller,
    const msg_rsensor4_t *in, const scmi_msg_status_t *out);
static int32_t SensorTripPointConfig(const scmi_caller_t *caller,
    const msg_rsensor5_t *in, const scmi_msg_status_t *out);
static int32_t SensorReadingGet(const scmi_caller_t *caller,
    const msg_rsensor6_t *in, msg_tsensor6_t *out, uint32_t *len);
static int32_t SensorConfigGet(const scmi_caller_t *caller,
    const msg_rsensor9_t *in, msg_tsensor9_t *out);
static int32_t SensorConfigSet(const scmi_caller_t *caller,
    const msg_rsensor10_t *in, const scmi_msg_status_t *out);
static int32_t SensorNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rsensor16_t *in, const scmi_msg_status_t *out);
static int32_t SensorTripPointEvent(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger);
static int32_t SensorResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/*--------------------------------------------------------------------------*/
/* Dispatch SCMI command                                                    */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - messageId: Message ID to dispatch                                      */
/*--------------------------------------------------------------------------*/
int32_t RPC_SCMI_SensorDispatchCommand(scmi_caller_t *caller,
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
            lenOut = sizeof(msg_tsensor0_t);
            status = SensorProtocolVersion(caller,
                (const scmi_msg_header_t*) in, (msg_tsensor0_t*) out);
            break;
        case COMMAND_PROTOCOL_ATTRIBUTES:
            lenOut = sizeof(msg_tsensor1_t);
            status = SensorProtocolAttributes(caller,
                (const scmi_msg_header_t*) in, (msg_tsensor1_t*) out);
            break;
        case COMMAND_PROTOCOL_MESSAGE_ATTRIBUTES:
            lenOut = sizeof(msg_tsensor2_t);
            status = SensorProtocolMessageAttributes(caller,
                (const msg_rsensor2_t*) in, (msg_tsensor2_t*) out);
            break;
        case COMMAND_SENSOR_DESCRIPTION_GET:
            lenOut = sizeof(msg_tsensor3_t);
            status = SensorDescriptionGet(caller, (const msg_rsensor3_t*) in,
                (msg_tsensor3_t*) out, &lenOut);
            break;
        case COMMAND_SENSOR_TRIP_POINT_NOTIFY:
            lenOut = sizeof(const scmi_msg_status_t);
            status = SensorTripPointNotify(caller, (const msg_rsensor4_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_SENSOR_TRIP_POINT_CONFIG:
            lenOut = sizeof(const scmi_msg_status_t);
            status = SensorTripPointConfig(caller, (const msg_rsensor5_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_SENSOR_READING_GET:
            lenOut = sizeof(msg_tsensor6_t);
            status = SensorReadingGet(caller, (const msg_rsensor6_t*) in,
                (msg_tsensor6_t*) out, &lenOut);
            break;
        case COMMAND_SENSOR_CONFIG_GET:
            lenOut = sizeof(msg_tsensor9_t);
            status = SensorConfigGet(caller, (const msg_rsensor9_t*) in,
                (msg_tsensor9_t*) out);
            break;
        case COMMAND_SENSOR_CONFIG_SET:
            lenOut = sizeof(const scmi_msg_status_t);
            status = SensorConfigSet(caller, (const msg_rsensor10_t*) in,
                (const scmi_msg_status_t*) out);
            break;
        case COMMAND_NEGOTIATE_PROTOCOL_VERSION:
            lenOut = sizeof(const scmi_msg_status_t);
            status = SensorNegotiateProtocolVersion(caller,
                (const msg_rsensor16_t*) in, (const scmi_msg_status_t*) out);
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
int32_t RPC_SCMI_SensorDispatchNotification(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Handle notifications */
    switch(msgId.messageId)
    {
        case RPC_SCMI_NOTIFY_SENSOR_TRIP_POINT_EVENT:
            status = SensorTripPointEvent(msgId, trigger);
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
int32_t RPC_SCMI_SensorDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    return SensorResetAgentConfig(lmId, agentId, permissionsReset);
}

/*==========================================================================*/
/* Custom Protocol Implementation                                           */
/*==========================================================================*/

/* Local variables */

static uint32_t s_sensorNotify[SM_SCMI_NUM_AGNT];

/*--------------------------------------------------------------------------*/
/* Get protocol version                                                     */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - out->version: Protocol version. For this revision of the               */
/*   specification, this value must be 0x30001                              */
/*                                                                          */
/* Process the PROTOCOL_VERSION message. Platform handler for               */
/* SCMI_SensorProtocolVersion(). See section 4.7.2.1 in the SCMI spec.      */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SensorProtocolVersion(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tsensor0_t *out)
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
/*   Bits[23:16] Maximum number of outstanding asynchronous functions that  */
/*   is supported by the platform.                                          */
/*   Bits[15:0] Number of sensors that is present and managed by the        */
/*   platform                                                               */
/* - out->sensorRegAddressLow: Low address: This value indicates the lower  */
/*   32 bits of the physical address where the sensor shared memory region  */
/*   is located. This value should be 64-bit aligned. The address must be   */
/*   in the memory map of the calling agent. If the sensorRegLen field is   */
/*   0, then this field is invalid and must be ignored by the agent         */
/* - out->sensorRegAddressHigh: High address: This value indicates the      */
/*   upper 32 bits of the physical address where the shared memory region   */
/*   is located. The address must be in the memory map of the calling       */
/*   agent. If the sensorRegLen field is 0, then this field is invalid and  */
/*   must be ignored by the agent                                           */
/* - out->sensorRegLen: Stats length: This value indicates the length in    */
/*   bytes of the shared memory region. A value of 0 in this field          */
/*   indicates that the platform does not implement the sensor shared       */
/*   memory                                                                 */
/*                                                                          */
/* Process the PROTOCOL_ATTRIBUTES message. Platform handler for            */
/* SCMI_SensorProtocolAttributes(). See section 4.7.2.3 in the SCMI spec.   */
/*                                                                          */
/*  Access macros:                                                          */
/* - SENSOR_PROTO_ATTR_MAX_PENDING() - Maximum number of outstanding        */
/*   asynchronous functions that is supported by the platform               */
/* - SENSOR_PROTO_ATTR_NUM_SENSORS() - Number of sensors that is present    */
/*   and managed by the platform                                            */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SensorProtocolAttributes(const scmi_caller_t *caller,
    const scmi_msg_header_t *in, msg_tsensor1_t *out)
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
        /* Return number of sensors, no async calls */
        out->attributes
            = SENSOR_PROTO_ATTR_MAX_PENDING(0UL)
            | SENSOR_PROTO_ATTR_NUM_SENSORS(SM_NUM_SENSOR);

        /* Statistics not supported */
        out->sensorRegAddressLow = 0U;
        out->sensorRegAddressHigh = 0U;
        out->sensorRegLen = 0U;
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
/* - out->attributes: Message attributes. Attributes that are associated    */
/*   with the message that is specified by message ID. Currently, this      */
/*   field returns the value of 0                                           */
/*                                                                          */
/* Process the PROTOCOL_MESSAGE_ATTRIBUTES message. Platform handler for    */
/* SCMI_SensorProtocolMessageAttributes(). See section 4.7.2.4 in the SCMI  */
/* spec.                                                                    */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: in case the message is implemented and available to    */
/*   use.                                                                   */
/* - SM_ERR_NOT_FOUND: if the message identified by messageId is not        */
/*   provided by this platform implementation.                              */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SensorProtocolMessageAttributes(const scmi_caller_t *caller,
    const msg_rsensor2_t *in, msg_tsensor2_t *out)
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
/* Get sensor descriptors                                                   */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->descIndex: Descriptor index                                        */
/* - out->numSensorFlags: Flags for number of sensors:                      */
/*   Bits[31:16] Number of remaining sensor descriptors.                    */
/*   Bits[15:12] Reserved, must be zero.                                    */
/*   Bits[11:0] Number of sensor descriptors that are returned by this      */
/*   current call                                                           */
/* - out->desc: An array of sensor descriptors                              */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the SENSOR_DESCRIPTION_GET message. Platform handler for         */
/* SCMI_SensorDescriptionGet(). See section 4.7.2.5 in the SCMI spec.       */
/*                                                                          */
/*  Access macros:                                                          */
/* - SENSOR_NUM_SENSOR_FLAGS_REMAINING_DESCS() - Number of remaining        */
/*   sensor descriptors                                                     */
/* - SENSOR_NUM_SENSOR_FLAGS_NUM_DESCS() - Number of sensor descriptors     */
/*   that are returned by this current call                                 */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the sensor description was returned successfully.   */
/* - SM_ERR_INVALID_PARAMETERS: if descIndex out of range.                  */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SensorDescriptionGet(const scmi_caller_t *caller,
    const msg_rsensor3_t *in, msg_tsensor3_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check description bounds */
    if ((status == SM_ERR_SUCCESS) && (in->descIndex >= SM_NUM_SENSOR))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Get descriptions? */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t sensor;

        out->numSensorFlags = 0U;
        for (sensor = 0U; sensor < SENSOR_MAX_DESC; sensor++)
        {
            dev_sm_sensor_desc_t lmmDesc;
            const uint8_t *nameAddr = (const uint8_t*) "";

            /* Break out if done */
            if ((sensor + in->descIndex) >= SM_NUM_SENSOR)
            {
                break;
            }

            /* Get the sensor name */
            if (status == SM_ERR_SUCCESS)
            {
                status = LMM_SensorNameGet(caller->lmId, sensor
                    + in->descIndex, (string*) &nameAddr, NULL);
            }

            /* Copy out name */
            if (status == SM_ERR_SUCCESS)
            {
                RPC_SCMI_StrCpy(out->desc[sensor].name, nameAddr,
                    SENSOR_MAX_NAME);
            }

            /* Get sensor description */
            status = LMM_SensorDescribe(caller->lmId,
                sensor + in->descIndex, &lmmDesc);

            /* Copy out data */
            if (status == SM_ERR_SUCCESS)
            {
                uint32_t attributes;

                /* Sensor number */
                out->desc[sensor].sensorId = sensor + in->descIndex;

                /* Sensor attributes (low) */
                attributes = SENSOR_ATTR_LOW_NUM_TP(
                    (uint32_t) lmmDesc.numTripPoints);
                if (lmmDesc.timestampSupport)
                {
                    attributes |= SENSOR_ATTR_LOW_TIME_SUPPORT(1U);
                    attributes |= SENSOR_ATTR_LOW_TIME_EXP(
                        (uint32_t) lmmDesc.timestampExponent);
                }
                out->desc[sensor].sensorAttributesLow = attributes;

                /* Sensor attributes (high) */
                attributes
                    = SENSOR_ATTR_HIGH_SENSOR_TYPE(
                    (uint32_t) lmmDesc.sensorType);
                attributes |= SENSOR_ATTR_HIGH_SENSOR_EXP(
                    (uint32_t) lmmDesc.sensorExponent);

                out->desc[sensor].sensorAttributesHigh = attributes;
            }

            /* Increment count */
            (out->numSensorFlags)++;
        }

        /* Update length */
        *len = (3U * sizeof(uint32_t))
            + (out->numSensorFlags * sizeof(sensor_desc_t));

        /* Append remaining levels */
        out->numSensorFlags |= SENSOR_NUM_SENSOR_FLAGS_REMAINING_DESCS(
            SM_NUM_SENSOR - (sensor + in->descIndex));
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure sensor trip point notification                                 */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->sensorId: Identifier for the sensor                                */
/* - in->sensorEventControl: Event control:                                 */
/*   Bits[31:1] Reserved.                                                   */
/*   Bit[0] Globally controls generation of notifications on crossing of    */
/*   configured trip-points pertaining to the specified sensor.             */
/*   If this bit is set to 1, notifications are sent whenever the sensor    */
/*   value crosses any of the trip-points that have been configured.        */
/*   If this bit is set to 0, no notifications are sent for any of the      */
/*   trip-points                                                            */
/*                                                                          */
/* Process the SENSOR_TRIP_POINT_NOTIFY message. Platform handler for       */
/* SCMI_SensorTripPointNotify(). Requires access greater than or equal to   */
/* NOTIFY. See section 4.7.2.8 in the SCMI spec.                            */
/*                                                                          */
/*  Access macros:                                                          */
/* - SENSOR_EV_CTRL_ENABLE() - Controls generation of notifications on      */
/*   crossing of configured trip-points                                     */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS.                                                        */
/* - SM_ERR_NOT_FOUND: if sensorId does not point to an existing sensor.    */
/* - SM_ERR_INVALID_PARAMETERS: if the input sensorEventControl flag        */
/*   contains invalid or illegal settings.                                  */
/* - SM_ERR_NOT_SUPPORTED: if the platform does not support trip point      */
/*   event notifications for the sensor.                                    */
/* - SM_ERR_DENIED: if the calling agent is not permitted to set a trip     */
/*   point on this sensor.                                                  */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SensorTripPointNotify(const scmi_caller_t *caller,
    const msg_rsensor4_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool enable = SENSOR_EV_CTRL_ENABLE(in->sensorEventControl) != 0U;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check sensor */
    if ((status == SM_ERR_SUCCESS) && (in->sensorId >= SM_NUM_SENSOR))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].sensorPerms[in->sensorId]
        < SM_SCMI_PERM_NOTIFY))
    {
        status = SM_ERR_DENIED;
    }

    /* Record notification enable */
    if (status == SM_ERR_SUCCESS)
    {
        if (enable)
        {
            s_sensorNotify[caller->agentId] |= (1UL << in->sensorId);
        }
        else
        {
            s_sensorNotify[caller->agentId] &= ~(1UL << in->sensorId);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure sensor trip point                                              */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->sensorId: Identifier for the sensor                                */
/* - in->tripPointEvCtrl: Event control:                                    */
/*   Bits[31:12] Reserved.                                                  */
/*   Bits[11:4] trip point ID: Identifier for the selected trip point.      */
/*   This value should be equal to or less than the total number of trip    */
/*   points that are supported by this sensor as advertised in its          */
/*   descriptor.                                                            */
/*   Bits[3:2] Reserved for future use.                                     */
/*   Bits[1:0] Event control for the trip-point:                            */
/*   If set to 0, disables event generation for this trip-point (this is    */
/*   the default state).                                                    */
/*   If set to 1, enables event generation when this trip-point value is    */
/*   reached or crossed in a positive direction.                            */
/*   If set to 2, enables event generation when this trip-point value is    */
/*   reached or crossed in a negative direction.                            */
/*   If set to 3, enables event generation when this trip-point value is    */
/*   reached or crossed in either direction                                 */
/* - in->tripPointValLow: Lower 32 bits of the sensor value: corresponds    */
/*   to this trip-point. The default value is 0                             */
/* - in->tripPointValHigh: Higher 32 bits of the sensor value: corresponds  */
/*   to this trip-point. The default value is 0                             */
/*                                                                          */
/* Process the SENSOR_TRIP_POINT_CONFIG message. Platform handler for       */
/* SCMI_SensorTripPointConfig(). Requires access greater than or equal to   */
/* EXCLUSIVE. See section 4.7.2.9 in the SCMI spec.                         */
/*                                                                          */
/*  Access macros:                                                          */
/* - SENSOR_TP_EV_CTRL_TRIP_ID() - Trip point ID                            */
/* - SENSOR_TP_EV_CTRL() - Event control for the trip-point                 */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the sensor trip point was set successfully.         */
/* - SM_ERR_NOT_FOUND: if sensorId does not point to an existing sensor.    */
/* - SM_ERR_INVALID_PARAMETERS: if the input parameters specify             */
/*   incorrect or illegal values.                                           */
/* - SM_ERR_NOT_SUPPORTED: if the platform does not support trip point      */
/*   event notifications for the sensor.                                    */
/* - SM_ERR_DENIED: if the calling agent is not permitted to set a trip     */
/*   point on this sensor.                                                  */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SensorTripPointConfig(const scmi_caller_t *caller,
    const msg_rsensor5_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check sensor */
    if ((status == SM_ERR_SUCCESS) && (in->sensorId >= SM_NUM_SENSOR))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].sensorPerms[in->sensorId]
        < SM_SCMI_PERM_EXCLUSIVE))
    {
        status = SM_ERR_DENIED;
    }

    /* Set sensor trip point */
    if (status == SM_ERR_SUCCESS)
    {
        uint8_t tripPoint
            = (uint8_t) SENSOR_TP_EV_CTRL_TRIP_ID(in->tripPointEvCtrl);
        uint8_t eventControl
            = (uint8_t) SENSOR_TP_EV_CTRL(in->tripPointEvCtrl);
        uint64_t tp = (int64_t) ((((uint64_t) in->tripPointValHigh)
            << 32U) | (uint64_t) in->tripPointValLow);
        int64_t tpValue = (int64_t) tp;

        status = LMM_SensorTripPointSet(caller->lmId, in->sensorId,
            tripPoint, tpValue, eventControl);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Read sensor                                                              */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->sensorId: Identifier for the sensor                                */
/* - in->flags: Read flags:                                                 */
/*   Bits[31:1] Reserved.                                                   */
/*   Bit[0] Async flag:                                                     */
/*   Set to 1 if the sensor is to be read asynchronously.                   */
/*   Set to 0 to if the sensor is to be read synchronously                  */
/* - out->readings: An array of sensor readings: where N is:                */
/*   - 1 for sensors which measure scalar values.                           */
/*   - the number of sensor axes for sensors which report values along      */
/*   axes. All axes should be reported in order                             */
/* - len: Pointer to length (can modify)                                    */
/*                                                                          */
/* Process the SENSOR_READING_GET message. Platform handler for             */
/* SCMI_SensorReadingGet(). See section 4.7.2.12 in the SCMI spec.          */
/*                                                                          */
/*  Access macros:                                                          */
/* - SENSOR_READ_FLAGS_ASYNC() - Async flag                                 */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the reading was successfully returned for a         */
/*   synchronous request or if the function was successfully enqueued for   */
/*   an asynchronous request.                                               */
/* - SM_ERR_NOT_FOUND: if sensorId does not point to an existing sensor.    */
/* - SM_ERR_INVALID_PARAMETERS: if the flags input specifies illegal or     */
/*   invalid settings.                                                      */
/* - SM_ERR_PROTOCOL_ERROR: if the function is used to read updates from    */
/*   a disabled sensor.                                                     */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SensorReadingGet(const scmi_caller_t *caller,
    const msg_rsensor6_t *in, msg_tsensor6_t *out, uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    bool async = SENSOR_READ_FLAGS_ASYNC(in->flags) != 0U;
    int64_t sensorValue = 0;
    uint64_t sensorTimestamp = 0U;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check sensor */
    if ((status == SM_ERR_SUCCESS) && (in->sensorId >= SM_NUM_SENSOR))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check for delayed response */
    if ((status == SM_ERR_SUCCESS) && async)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Check if enabled */
    if (status == SM_ERR_SUCCESS)
    {
        bool enabled;
        bool timestampReporting;

        status = LMM_SensorIsEnabled(caller->lmId, in->sensorId,
            &enabled, &timestampReporting);

        if ((status == SM_ERR_SUCCESS) && (!enabled))
        {
            status = SM_ERR_PROTOCOL_ERROR;
        }
    }

    /* Get sensor reading */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_SensorReadingGet(caller->lmId, in->sensorId,
            &sensorValue, &sensorTimestamp);
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Record result */
        out->readings[0].sensorValueHigh = SM_INT64_H(sensorValue);
        out->readings[0].sensorValueLow = SM_INT64_L(sensorValue);
        out->readings[0].timestampHigh = SM_UINT64_H(sensorTimestamp);
        out->readings[0].timestampLow = SM_UINT64_L(sensorTimestamp);

        /* Update length */
        *len = (2U * sizeof(uint32_t))
            + (1U * sizeof(sensor_reading_t));
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get sensor configuration                                                 */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->sensorId: Identifier for the sensor                                */
/* - out->sensorConfig: Sensor config:                                      */
/*   Bits[31:11] sensor update interval:                                    */
/*   Bits[31:16] sec - Seconds.                                             */
/*   Bits[15:11] exponent - twos complement format representing the         */
/*   power-of-10 multiplier that is applied to the sec field.               */
/*   The time duration between successive updates of the sensor value. The  */
/*   representation is in the [sec] x 10[exponent] format, in units of      */
/*   seconds.                                                               */
/*   This field is set to 0 if the sensor does not require or support an    */
/*   update interval.                                                       */
/*   Bits[10:2] Reserved.                                                   */
/*   Bit[1] Timestamp reporting:                                            */
/*   Set to 1 if the sensor value provided by the platform is timestamped.  */
/*   Set to 0 if the sensor value provided by the platform is not           */
/*   timestamped.                                                           */
/*   Bit[0] Sensor State:                                                   */
/*   Set to 1 if the sensor is enabled.                                     */
/*   Set to 0 if the sensor is disabled                                     */
/*                                                                          */
/* Process the SENSOR_CONFIG_GET message. Platform handler for              */
/* SCMI_SensorConfigGet(). See section 4.7.2.10 in the SCMI spec.           */
/*                                                                          */
/*  Access macros:                                                          */
/* - SENSOR_CONFIG_GET_UPDATE_INTV_SEC() - Seconds                          */
/* - SENSOR_CONFIG_GET_UPDATE_INTV_EXP() - Twos complement format           */
/*   representing the power-of-10 multiplier that is applied to the sec     */
/*   field                                                                  */
/* - SENSOR_CONFIG_GET_TS_ENABLED() - Timestamp reporting                   */
/* - SENSOR_CONFIG_GET_ENABLED() - Sensor State                             */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the sensor configuration was returned               */
/*   successfully.                                                          */
/* - SM_ERR_NOT_FOUND: if sensorId does not point to an existing sensor.    */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SensorConfigGet(const scmi_caller_t *caller,
    const msg_rsensor9_t *in, msg_tsensor9_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool enabled;
    bool timestampReporting;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check sensor */
    if ((status == SM_ERR_SUCCESS) && (in->sensorId >= SM_NUM_SENSOR))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Get sensor enable */
    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_SensorIsEnabled(caller->lmId, in->sensorId,
            &enabled, &timestampReporting);
    }

    /* Return results */
    if (status == SM_ERR_SUCCESS)
    {
        out->sensorConfig
            = SENSOR_CONFIG_GET_UPDATE_INTV_SEC(0UL)
            | SENSOR_CONFIG_GET_UPDATE_INTV_EXP(0UL);

        if (enabled)
        {
            out->sensorConfig |= SENSOR_CONFIG_GET_ENABLED(1U);
        }
        if (timestampReporting)
        {
            out->sensorConfig |= SENSOR_CONFIG_GET_TS_ENABLED(1U);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set sensor configuration                                                 */
/*                                                                          */
/* Parameters:                                                              */
/* - caller: Caller info                                                    */
/* - in->sensorId: Identifier for the sensor                                */
/* - in->sensorConfig: Sensor config:                                       */
/*   Bits[31:11] sensor update interval:                                    */
/*   Bits[31:16] sec - Seconds.                                             */
/*   Bits[15:11] exponent - twos complement format representing the         */
/*   power-of-10 multiplier that is applied to the sec field.               */
/*   The time duration between successive updates of the sensor value. The  */
/*   representation is in the [sec] x 10[exponent] format, in units of      */
/*   seconds.                                                               */
/*   This field should be set to 0 if the sensor update interval does not   */
/*   need to be updated or if the sensor does not support configuring the   */
/*   sensor update interval.                                                */
/*   Bits[10:9] Round up/down:                                              */
/*   If Bit[10] is set to 1, the platform rounds up/down autonomously to    */
/*   choose a sensor update interval closest to the requested update        */
/*   interval, and Bit[9] is ignored.                                       */
/*   If Bit[10] is set to 0, then the platform rounds up if Bit[9] is set   */
/*   to 1, and rounds down if Bit[9] is set to 0.                           */
/*   Bits[8:2] Reserved.                                                    */
/*   Bit[1] Timestamp reporting:                                            */
/*   Set to 1 if the sensor value provided by the platform should be        */
/*   timestamped.                                                           */
/*   Set to 0 if the sensor value provided by the platform should not be    */
/*   timestamped.                                                           */
/*   If the sensor does not support timestamp reporting or its              */
/*   configuration, this bit should be set to 0.                            */
/*   Bit[0] Sensor State:                                                   */
/*   Set to 1 if the sensor should be enabled.                              */
/*   Set to 0 if the sensor should be disabled                              */
/*                                                                          */
/* Process the SENSOR_CONFIG_SET message. Platform handler for              */
/* SCMI_SensorConfigSet(). Requires access greater than or equal to SET.    */
/* See section 4.7.2.11 in the SCMI spec.                                   */
/*                                                                          */
/*  Access macros:                                                          */
/* - SENSOR_CONFIG_SET_UPDATE_INTV_SEC() - Seconds                          */
/* - SENSOR_CONFIG_SET_UPDATE_INTV_EXP() - Twos complement format           */
/*   representing the power-of-10 multiplier that is applied to the sec     */
/*   field                                                                  */
/* - SENSOR_CONFIG_SET_ROUND() - Round up/down                              */
/* - SENSOR_CONFIG_SET_TS_ENABLE() - Timestamp reporting                    */
/* - SENSOR_CONFIG_SET_ENABLE() - Sensor State                              */
/*                                                                          */
/* Return errors:                                                           */
/* - SM_ERR_SUCCESS: if the sensor configuration was set successfully.      */
/* - SM_ERR_NOT_FOUND: if sensorId does not point to an existing sensor.    */
/* - SM_ERR_INVALID_PARAMETERS: if the input parameters specify             */
/*   incorrect or illegal values.                                           */
/* - SM_ERR_NOT_SUPPORTED: if the configuration requested by this           */
/*   function is not supported by the sensor.                               */
/* - SM_ERR_DENIED: if the calling agent is not permitted to configure      */
/*   this sensor.                                                           */
/* - SM_ERR_PROTOCOL_ERROR: if the incoming payload is too small.           */
/*--------------------------------------------------------------------------*/
static int32_t SensorConfigSet(const scmi_caller_t *caller,
    const msg_rsensor10_t *in, const scmi_msg_status_t *out)
{
    int32_t status = SM_ERR_SUCCESS;
    bool enable = SENSOR_CONFIG_SET_ENABLE(in->sensorConfig) != 0U;
    bool timestampReporting
        = SENSOR_CONFIG_SET_TS_ENABLE(in->sensorConfig) != 0U;

    /* Check request length */
    if (caller->lenCopy < sizeof(*in))
    {
        status = SM_ERR_PROTOCOL_ERROR;
    }

    /* Check sensor */
    if ((status == SM_ERR_SUCCESS) && (in->sensorId >= SM_NUM_SENSOR))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check permissions */
    if ((status == SM_ERR_SUCCESS)
        && (g_scmiAgentConfig[caller->agentId].sensorPerms[in->sensorId]
        < SM_SCMI_PERM_SET))
    {
        status = SM_ERR_DENIED;
    }

    if (status == SM_ERR_SUCCESS)
    {
        status = LMM_SensorEnable(caller->lmId, in->sensorId, enable,
            timestampReporting);
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
/* SCMI_SensorNegotiateProtocolVersion(). See section 4.7.2.2 in the SCMI   */
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
static int32_t SensorNegotiateProtocolVersion(const scmi_caller_t *caller,
    const msg_rsensor16_t *in, const scmi_msg_status_t *out)
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
/* Send sensor trip point event                                             */
/*                                                                          */
/* Parameters:                                                              */
/* - msgId: Message ID to dispatch                                          */
/* - trigger: Trigger data                                                  */
/*--------------------------------------------------------------------------*/
static int32_t SensorTripPointEvent(scmi_msg_id_t msgId,
    lmm_rpc_trigger_t trigger)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    /* Loop over all agents */
    for (uint32_t dstAgent = 0U; dstAgent < SM_SCMI_NUM_AGNT; dstAgent++)
    {
        uint32_t sensorId = trigger.parm[0];
        bool enable = ((s_sensorNotify[dstAgent]
            >> sensorId) & 0x1U) != 0U;

        /* Agent belong to instance? */
        if ((g_scmiAgentConfig[dstAgent].scmiInst == trigger.rpcInst)
            && enable)
        {
            uint32_t tripPointDesc = SENSOR_EVENT_TP_ID(trigger.parm[1])
                | SENSOR_EVENT_DIRECTION(trigger.parm[2]);
            msg_rsensor32_t out;

            /* Fill in data */
            out.agentId = 0U;
            out.sensorId = sensorId;
            out.tripPointDesc = tripPointDesc;

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
static int32_t SensorResetAgentConfig(uint32_t lmId, uint32_t agentId,
    bool permissionsReset)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Disable notifications */
    s_sensorNotify[agentId] = 0U;

    /* Return status */
    return status;
}

