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
/*!
 * @addtogroup RPC_SCMI
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing internal functions and defines for the
 * System Control and Management Interface (SCMI) implementation.
 */
/*==========================================================================*/

#ifndef RPC_SCMI_INTERNAL_H
#define RPC_SCMI_INTERNAL_H

/* Includes */

#include "config_scmi.h"
#include "sm.h"
#include "rpc_scmi.h"
#include "rpc_scmi_config.h"
#include "rpc_scmi_base.h"
#include "rpc_scmi_power.h"
#include "rpc_scmi_sys.h"
#include "rpc_scmi_perf.h"
#include "rpc_scmi_clock.h"
#include "rpc_scmi_sensor.h"
#include "rpc_scmi_reset.h"
#include "rpc_scmi_voltage.h"
#include "rpc_scmi_pinctrl.h"
#include "rpc_scmi_lmm.h"
#include "rpc_scmi_bbm.h"
#include "rpc_scmi_cpu.h"
#include "rpc_scmi_misc.h"
#ifdef USES_FUSA
#include "rpc_scmi_fusa.h"
#endif

/* Defines */

/*! Vendor string returned by BASE_DISCOVER_VENDOR */
#define SCMI_VENDOR         "NXP"

/*! Subvendor string returned by BASE_DISCOVER_SUB_VENDOR */
#define SCMI_SUB_VENDOR     "IMX"

/*! Payload buffer size */
#define SCMI_PAYLOAD_LEN    100U

/*! Macro to determine max elements in the payload */
#define SCMI_ARRAY(X, Y)    ((SCMI_PAYLOAD_LEN - (X)) / sizeof(Y))

/* Types */

/*! SCMI message structure (header only) */
typedef struct
{
    uint32_t header;  /*!< header (protocol, message, token*/
} scmi_msg_header_t;

/* Functions */

/*!
 * @name SCMI internal functions
 * @{
 */

/*!
 * Check queue space (P2A).
 *
 * @param[in]     agentId     Agent to send message
 * @param[in]     len         Length of message in bytes
 * @param[in]     queue       Notify or priority queue
 *
 * Check if sufficient space for a desired notification.
 *
 * @return Returns true if insufficient space.
 */
bool RPC_SCMI_P2aTxQFull(uint32_t agentId, uint32_t len, uint32_t queue);

/*!
 * Transmit SCMI payload (P2A).
 *
 * @param[in]     agentId     Agent to send message
 * @param[in]     msgId       ID of message
 * @param[in]     msg         Pointer to message to send
 * @param[in]     len         Length of message in bytes
 * @param[in]     queue       Notify or priority queue
 *
 * This function transmits an SCMI payload using the P2A protocol.
 * The \a agentId parameter identifies the queue to use. The channel
 * used is the SCMI channel of the ::SM_SCMI_CHN_P2A_NOTIFY type found for
 * the agent. The \a len parameter is the size in bytes of the source
 * payload.
 */
void RPC_SCMI_P2aTxQ(uint32_t agentId, scmi_msg_id_t msgId, uint32_t *msg,
    uint32_t len, uint32_t queue);

/*!
 * Bounded string copy.
 *
 * @param[out]    dst     Destination pointer
 * @param[in]     src     Source pointer
 * @param[in]     maxLen  Max length to copy
 *
 * This function copies a string from \a src to \a dst. The copy will
 * not exceed \a maxLen.
 */
void RPC_SCMI_StrCpy(uint8_t *dst, const uint8_t *src, uint32_t maxLen);

/*!
 * Get number of protocols.
 *
 * @return Returns the number of protocols.
 */
uint32_t RPC_SCMI_NumProtocolsGet(void);

/*!
 * Get a compressed list of protocols.
 *
 * @param[in]   skip             Number of ptocols to skip
 * @param[in]   numWords         Number of buffer words
 * @param[out]  numProtocols     Pointer to return the number of protocols
 * @param[out]  protocolListDst  Pointer to buffer to return protocol list
 *
 * This function copies a string from \a src to \a dst. The copy will
 * not exceed \a maxLen bytes.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_INVALID_PARAMETERS if no protocols could be returned
 */
int32_t RPC_SCMI_ProtocolListGet(uint32_t skip, uint32_t numWords,
    uint32_t *numProtocols, uint32_t *protocolListDst);

/** @} */

#endif /* RPC_SCMI_INTERNAL_H */

/** @} */

