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
/*!
 * @addtogroup RPC_SCMI
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the System Control and Management
 * Interface (SCMI).
 */
/*==========================================================================*/

#ifndef RPC_SCMI_H
#define RPC_SCMI_H

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "rpc_smt.h"

/* Defines */

/*!
 * @name Protocol IDs
 */
/** @{ */
/*! Base protocol */
#define SCMI_PROTOCOL_BASE         0x10U
/*! Power domain management protocol */
#define SCMI_PROTOCOL_POWER        0x11U
/*! System power management protocol */
#define SCMI_PROTOCOL_SYSTEM       0x12U
/*! Performance domain management protocol */
#define SCMI_PROTOCOL_PERF         0x13U
/*! Clock management protocol */
#define SCMI_PROTOCOL_CLOCK        0x14U
/*! Sensor management protocol */
#define SCMI_PROTOCOL_SENSOR       0x15U
/*! Reset domain management protocol */
#define SCMI_PROTOCOL_RESET        0x16U
/*! Voltage domain management protocol */
#define SCMI_PROTOCOL_VOLTAGE      0x17U
/*! Pin control protocol */
#define SCMI_PROTOCOL_PINCTRL      0x19U
/*! LM management protocol */
#define SCMI_PROTOCOL_LMM          0x80U
/*! BBM management protocol */
#define SCMI_PROTOCOL_BBM          0x81U
/*! CPU management protocol */
#define SCMI_PROTOCOL_CPU          0x82U
/*! FuSa protocol */
#define SCMI_PROTOCOL_FUSA         0x83U
/*! Misc protocol */
#define SCMI_PROTOCOL_MISC         0x84U
/** @} */

/*!
 * @name Queue IDs
 */
/** @{ */
/*! Standard notification queue */
#define SCMI_NOTIFY_Q               0U
/*! Priority notification queue */
#define SCMI_PRIORITY_Q             1U
/** @} */

/* Types */

/*! SCMI full message structure */
typedef struct
{
    uint32_t header;  /*!< Message header */
    uint32_t payload[SMT_BUFFER_PAYLOAD / 4U]; /*!< Payload */
} scmi_msg_t;

/*! SCMI message structure (status only) */
typedef struct
{
    uint32_t header;  /*!< Header (protocol, message, token*/
    int32_t status;   /*!< Status (see @ref STATUS "SM error codes") */
} scmi_msg_status_t;

/*! SCMI message ID structure */
typedef struct
{
    uint32_t protocolId;  /*!< Protocol ID */
    uint32_t messageId;   /*!< Message ID */
} scmi_msg_id_t;

/*!
 * SCMI caller structure
 *
 * Structure containing all parameters of a client call. Passed around
 * internal function calls to reduce constant lookup. Filled in by the
 * RPC_SCMI_A2pDispatch() function before calling further dispatch.
 */
typedef struct
{
    scmi_msg_t *msgCopy;     /*!< Pointer to rx buffer copy */
    scmi_msg_status_t *msg;  /*!< Pointer to message buffer */
    uint32_t lenCopy;        /*!< Length of rx message */
    uint32_t lenMsg;         /*!< Length of tx message */
    uint32_t lmId;           /*!< Caller logical machine */
    uint32_t scmiInst;       /*!< Caller SCMI instance */
    uint32_t agentId;        /*!< Caller SCMI agent */
    uint32_t instAgentId;    /*!< Caller instance agent */
    uint32_t scmiChannel;    /*!< Caller SCMI channel */
    uint32_t header;         /*!< Snooped header of message */
    uint32_t safeType;       /*!< Safety classification */
    bool extension;          /*!< Vendor extension protocol */
} scmi_caller_t;

/* Functions */

/*!
 * @name SCMI module functions
 * @{
 */

/*!
 * Initialize SCMI instance.
 *
 * @param[in]     scmiInst  SCMI instance
 *
 * This function initializes SCMI instance data strucures. It also calls to
 * initialize all the associated transport channels. Only called from
 * RPC_SCMI_Init().
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t RPC_SCMI_Init(uint8_t scmiInst);

/*!
 * Init buffer for exchanging a message.
 *
 * @param[in]     scmiChannel Channel for comms
 * @param[out]    msg         Pointer to return payload header address
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_INVALID_PARAMETERS: if the buffer address is incorrectly
 *   configured.
 */
int32_t RPC_SCMI_BufInit(uint32_t scmiChannel, void **msg);

/*!
 * Dispatch SCMI request.
 *
 * @param[in]     scmiChannel  SCMI channel
 *
 * This function dispatches an SCMI doorbell interrupt. The \a scmiChannel
 * parameter is used to index into the global const SCMI channel config
 * structure to find the channel type (A2P or P2A). The specific directional
 * SCMI dispatch function is then called.
 */
void RPC_SCMI_Dispatch(uint32_t scmiChannel);

/*!
 * Send P2A message.
 *
 * @param[in]     scmiChannel P2A channel for comms
 * @param[in]     protocolId  Protocol ID
 * @param[in]     messageId   Message ID
 * @param[in]     len         Length of buffer to send
 * @param[out]    header      Pointer to return header value
 * @param[out]    notify      True if notification
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Send a P2A message. Calls the transport to send the buffer. Blocks
 * until the channel is free to send. The \a scmiChannel parameter should
 * be a P2A channel. The \a len parameter is the size in bytes of the
 * payload + header.
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_INVALID_PARAMETERS: if the buffer address is incorrectly
 *   configured.
 * - ::SM_ERR_OUT_OF_RANGE: if the channel is incorrectly configured.
 * - ::SM_ERR_PROTOCOL_ERROR: if the message is too big.
 */
int32_t RPC_SCMI_P2aTx(uint32_t scmiChannel, uint32_t protocolId,
    uint32_t messageId, uint32_t len, uint32_t *header, bool notify);

/*!
 * Receive P2A response.
 *
 * @param[in]     scmiChannel P2A channel for comms
 * @param[in]     minLen      Minimum length of message
 * @param[in]     header      Return header value
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Receive a response sent by the agent to the platform (P2A). Calls the
 * transport to receive the buffer. Blocks until the message is available.
 * The \a scmiChannel parameter should be the channel the message was sent on
 * via RPC_SCMI_P2aTx(). The \a minLen is the minimum size message in bytes
 * expected including the payload + header.
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_INVALID_PARAMETERS: if the buffer address is incorrectly
 *   configured.
 * - ::SM_ERR_OUT_OF_RANGE: if the channel is incorrectly configured.
 * - ::SM_ERR_PROTOCOL_ERROR: if the header doesn't match or if the
 *   received message is too small.
 */
int32_t RPC_SCMI_P2aRx(uint32_t scmiChannel, uint32_t minLen, uint32_t header);

/*!
 * Reset SCMI instance.
 *
 * @param[in]     scmiInst  SCMI instance
 *
 * This function resets the SCMI instance data strucures. Its state is
 * returned to the initial value configured when first booted. This function
 * is only called from LMM_RpcReset() when an LM is powered off or reset.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t RPC_SCMI_Reset(uint8_t scmiInst);

/*!
 * Trigger SCMI notification.
 *
 * @param[in]     trigger     Structure with trigger information
 *
 * This function triggers a notification event. The \a trigger structure
 * contains a parameter indicating which SCMI instance is targeted. It also
 * contains the trigger event and event speciic parameters. Only called
 * from LMM_RpcNotificationTrigger().
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t RPC_SCMI_Trigger(lmm_rpc_trigger_t trigger);

/*!
 * Dump collected SCMI errors.
 *
 * @param[in]     scmiInst  SCMI instance
 *
 * Dump any captured errors for the specidifed SCMI instance.
 */
void RPC_SCMI_ErrorDump(uint8_t scmiInst);

/** @} */

#endif /* RPC_SCMI_H */

/** @} */

