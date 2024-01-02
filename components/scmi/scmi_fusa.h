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

#ifndef SCMI_FUSA_H
#define SCMI_FUSA_H

/*!
 * @addtogroup scmi_proto_fusa
 * @{
 */

/*!
 * @file
 * @brief Header file containing the client-side API for the System Control and
 * Management Interface (SCMI) fusa protocol.
 */

/* Defines */

/*!
 * @name SCMI FuSa protocol message IDs
 */
/** @{ */
/*! Get current FuSa system state */
#define SCMI_MSG_FUSA_FEENV_STATE_GET        0x3U
/*! Request F-EENV transition to new state */
#define SCMI_MSG_FUSA_FEENV_STATE_SET        0x4U
/*! Configure F-EENV notifications */
#define SCMI_MSG_FUSA_FEENV_STATE_NOTIFY     0x5U
/*! Get S-EENV state */
#define SCMI_MSG_FUSA_SEENV_STATE_GET        0x6U
/*! Set S-EENV state */
#define SCMI_MSG_FUSA_SEENV_STATE_SET        0x7U
/*! Get fault state */
#define SCMI_MSG_FUSA_FAULT_GET              0x8U
/*! Set fault state */
#define SCMI_MSG_FUSA_FAULT_SET              0x9U
/*! Enable/disable fault notifications */
#define SCMI_MSG_FUSA_FAULT_GROUP_NOTIFY     0xAU
/*! Temporarily disable fault handling */
#define SCMI_MSG_FUSA_SCHECK_EVNTRIG         0xBU
/*! Start CRC calculation */
#define SCMI_MSG_FUSA_CRC_CALCULATE          0xCU
/*! Get CRC calculation result */
#define SCMI_MSG_FUSA_CRC_RESULT_GET         0xDU
/*! Read F-EENV state change notification event */
#define SCMI_MSG_FUSA_FEENV_STATE_EVENT      0x0U
/*! Read S-EENV state request notification event */
#define SCMI_MSG_FUSA_SEENV_STATE_REQ_EVENT  0x1U
/*! Read fault notification event */
#define SCMI_MSG_FUSA_FAULT_EVENT            0x2U
/** @} */

/*!
 * @name SCMI FuSa F-EENV states
 */
/** @{ */
/*! Initial state during boot up */
#define SCMI_FUSA_FEENV_STATE_INIT            0U
/*! Waiting for all S-EENVs to be safety ready */
#define SCMI_FUSA_FEENV_STATE_PRE_SAFETY      1U
/*! Running in normal safety context */
#define SCMI_FUSA_FEENV_STATE_SAFETY_RUNTIME  2U
/*! SoC power standby requested, waiting for S-EENV to be off */
#define SCMI_FUSA_FEENV_STATE_SOC_STANDBY     3U
/*! SoC shutdown requested, waiting for S-EENV to be off */
#define SCMI_FUSA_FEENV_STATE_SOC_SHUTDOWN    4U
/*! SoC graceful reset requested, waiting for S-EENV to be off */
#define SCMI_FUSA_FEENV_STATE_SOC_RESET       5U
/** @} */

/*!
 * @name SCMI FuSa S-EENV states
 */
/** @{ */
/*! Initial S-EENV state */
#define SCMI_FUSA_SEENV_STATE_INIT            0U
/*! S-EENV is ready to transition to the RUNTIME state */
#define SCMI_FUSA_SEENV_STATE_SAFETY_READY    1U
/*! Running in normal safety context */
#define SCMI_FUSA_SEENV_STATE_SAFETY_RUNTIME  2U
/*! Transitioned to a terminal state */
#define SCMI_FUSA_SEENV_STATE_TERMINAL        3U
/** @} */

/* Macros */

/*!
 * @name SCMI FuSa protocol attributes 1
 */
/** @{ */
/*! Number of fault sources */
#define SCMI_FUSA_PROTO_ATTR1_NUM_FAULT(x)  (((x) & 0xFFFF0000U) >> 16U)
/*! Number of CRC channels supported */
#define SCMI_FUSA_PROTO_ATTR1_NUM_CRC(x)    (((x) & 0xFF00U) >> 8U)
/*! Number of S-EENV LM in the system */
#define SCMI_FUSA_PROTO_ATTR1_NUM_SEENV(x)  (((x) & 0xFFU) >> 0U)
/** @} */

/*!
 * @name SCMI FuSa F-eenv set flags
 */
/** @{ */
/*! Graceful request */
#define SCMI_FUSA_FLAGS_GRACEFUL(x)  (((x) & 0x1U) << 0U)
/** @} */

/*!
 * @name SCMI FuSa notification flags
 */
/** @{ */
/*! Enable notifications for F-EENV state change */
#define SCMI_FUSA_FEENV_NOTIFY_ENABLE(x)  (((x) & 0x1U) << 0U)
/** @} */

/*!
 * @name SCMI FuSa fault get state flags
 */
/** @{ */
/*! Fault state */
#define SCMI_FUSA_FAULT_GET_STATE(x)  (((x) & 0x1U) >> 0U)
/** @} */

/*!
 * @name SCMI FuSa fault get state flags
 */
/** @{ */
/*! Fault state */
#define SCMI_FUSA_FAULT_SET_STATE(x)  (((x) & 0x1U) << 0U)
/** @} */

/*!
 * @name SCMI FuSa fault event flags
 */
/** @{ */
/*! Fault state (1 detected, 0 resolved) */
#define SCMI_FUSA_FAULT_FLAG_STATE(x)  (((x) & 0x1U) >> 0U)
/** @} */

/* Functions */

/*!
 * Get protocol version.
 *
 * @param[in]     channel  A2P channel for comms
 * @param[out]    version  Protocol version. For this revision of the
 *                         specification, this value must be 0x10000
 *
 * On success, this function returns the Protocol version. For this version of
 * the specification, the return value must be 0x10000, which corresponds to
 * version 1.0.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 */
int32_t SCMI_FusaProtocolVersion(uint32_t channel, uint32_t *version);

/*!
 * Get protocol attributes.
 *
 * @param[in]     channel      A2P channel for comms
 * @param[out]    attributes1  Protocol attributes 1:<BR>
 *                             Bits[31:16] Number of Fault sources (this number
 *                             defines valid range of the fault ID identifiers
 *                             used in the fault functions)<BR>
 *                             Bits[15:8] Number of CRC channels supported<BR>
 *                             Bits[7:0] Number of S-EENV LM in the system (not
 *                             counting the F-EENV itself)
 * @param[out]    attributes2  Protocol attributes 2:<BR>
 *                             Bits[31:0] Reserved, must be zero
 *
 * This function returns the implementation details associated with this
 * protocol.
 *
 * Access macros:
 * - ::SCMI_FUSA_PROTO_ATTR1_NUM_FAULT() - Number of fault sources
 * - ::SCMI_FUSA_PROTO_ATTR1_NUM_CRC() - Number of CRC channels supported
 * - ::SCMI_FUSA_PROTO_ATTR1_NUM_SEENV() - Number of S-EENV LM in the system
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 */
int32_t SCMI_FusaProtocolAttributes(uint32_t channel, uint32_t *attributes1,
    uint32_t *attributes2);

/*!
 * Get protocol message attributes.
 *
 * @param[in]     channel     A2P channel for comms
 * @param[in]     messageId   Message ID of the message
 * @param[out]    attributes  Message attributes. Flags that are associated
 *                            with a specific function in the protocol.<BR>
 *                            In the current version of the specification, this
 *                            value is always 0
 *
 * On success, this function returns the implementation details associated with
 * a specific message in this protocol. An example message ID is
 * ::SCMI_MSG_FUSA_FEENV_STATE_GET.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: in case the message is implemented and available to
 *   use.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature.
 * - ::SCMI_ERR_NOT_FOUND: if the message identified by \a messageId is
 *   invalid or not implemented.
 */
int32_t SCMI_FusaProtocolMessageAttributes(uint32_t channel,
    uint32_t messageId, uint32_t *attributes);

/*!
 * Get current FuSa system state.
 *
 * @param[in]     channel     A2P channel for comms
 * @param[out]    feenvState  Parameter identifying the safety state of the
 *                            F-EENV
 * @param[out]    mselMode    Mode selector value as returned by SAF
 *
 * This function is used to get the current FuSa system state and operation
 * mode selected by the SAF mSel. An example state is
 * ::SCMI_FUSA_FEENV_STATE_PRE_SAFETY.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the current F-EENV state is returned successfully.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller
 *   is not an S-EENV.
 * - ::SCMI_ERR_DENIED: if the calling agent is not allowed to get the F-EENV
 *   state.
 */
int32_t SCMI_FusaFeenvStateGet(uint32_t channel, uint32_t *feenvState,
    uint32_t *mselMode);

/*!
 * Request F-EENV transition to new state.
 *
 * @param[in]     channel     A2P channel for comms
 * @param[in]     feenvState  Parameter identifying the requested safety state
 *                            of the F-EENV
 * @param[in]     flags       F-EENV set state flags. This parameter has the
 *                            following format:<BR>
 *                            Bits[31:1] Reserved, must be zero.<BR>
 *                            Bit[0] Graceful request.<BR>
 *                            Set to 1 if the request is a graceful
 *                            request.<BR>
 *                            Set to 0 if the request is a forceful
 *                            request.<BR>
 *                            In graceful transition, the S-EENVs are notified
 *                            and SM waits for their transition to off state
 *
 * This function is used by an S-EENV to request the F-EENV (and the whole SoC)
 * to transition to a new power state. Only the SoC standby, SoC shutdown and
 * SoC reset states can be requested. An example state is
 * ::SCMI_FUSA_FEENV_STATE_SAFETY_RUNTIME.
 *
 * Access macros:
 * - ::SCMI_FUSA_FLAGS_GRACEFUL() - Graceful request
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the F-EENV state was set successfully.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller
 *   is not an S-EENV.
 * - ::SCMI_ERR_INVALID_PARAMETERS: if the requested state or flags are
 *   invalid.
 * - ::SCMI_ERR_DENIED: if the calling agent is not allowed to set the F-EENV
 *   state.
 */
int32_t SCMI_FusaFeenvStateSet(uint32_t channel, uint32_t feenvState,
    uint32_t flags);

/*!
 * Configure F-EENV notifications.
 *
 * @param[in]     channel       A2P channel for comms
 * @param[in]     notifyEnable  Notification flags:<BR>
 *                              Bits[31:1] Reserved, must be zero.<BR>
 *                              Bit[0] State change notification:<BR>
 *                              Set to 1 to send notification.<BR>
 *                              Set to 0 if no notification
 *
 * This function is used to request notification on FuSa state changes.
 *
 * Access macros:
 * - ::SCMI_FUSA_FEENV_NOTIFY_ENABLE() - Enable notifications for F-EENV state
 *   change
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the notification state successfully updated.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller
 *   is not an S-EENV.
 * - ::SCMI_ERR_DENIED: if the calling agent is not permitted to request the
 *   notification.
 */
int32_t SCMI_FusaFeenvStateNotify(uint32_t channel, uint32_t notifyEnable);

/*!
 * Get S-EENV state.
 *
 * @param[in]     channel     A2P channel for comms
 * @param[out]    seenvState  Parameter identifying the safety state of the
 *                            S-EENV
 *
 * This function is used by any S-EENV to retrieve information about itself as
 * it is recorded in the F-EENV internal memory. An example state is
 * ::SCMI_FUSA_SEENV_STATE_INIT.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the S-EENV state is returned successfully.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller
 *   is not an S-EENV.
 */
int32_t SCMI_FusaSeenvStateGet(uint32_t channel, uint32_t *seenvState);

/*!
 * Set S-EENV state.
 *
 * @param[in]     channel        A2P channel for comms
 * @param[in]     seenvState     Parameter to set the safety state of the
 *                               S-EENV
 * @param[in]     pingCookie     Cookie value last sent by the F-EENV
 * @param[in]     scstSignature  Last result of local core self-test routine
 *                               executed by the S-EENV
 *
 * This function is used by the S-EENVs to inform SM about transition to a new
 * state. The SM accepts this transition and records the S-EENV state
 * internally. Collecting the state information from all S-EENVs is important
 * for SM to transition between various F-EENV states. An example state is
 * ::SCMI_FUSA_SEENV_STATE_SAFETY_READY.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the S-EENV state is set successfully.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller
 *   is not an S-EENV.
 * - ::SCMI_ERR_INVALID_PARAMETERS: if the requested state is invalid.
 */
int32_t SCMI_FusaSeenvStateSet(uint32_t channel, uint32_t seenvState,
    uint32_t pingCookie, uint32_t scstSignature);

/*!
 * Get fault state.
 *
 * @param[in]     channel  A2P channel for comms
 * @param[in]     faultId  Global fault identifier
 * @param[out]    flags    State of the fault:<BR>
 *                         Bits[31:1] Reserved, must be zero.<BR>
 *                         Bit[0] Fault state.<BR>
 *                         Set to 1 if the fault is set.<BR>
 *                         Set to 0 if the fault is cleared
 *
 * This function is used by the S-EENVs to determine an immediate state of a SW
 * fault (NCF). The agents (S-EENVs) shall not use this (and no other) RPC call
 * during fault resolution process. The fault ID and fault resolution state are
 * communicated directly using the direct channel.
 *
 * Access macros:
 * - ::SCMI_FUSA_FAULT_GET_STATE() - Fault state
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the fault state is returned successfully.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller
 *   is not an S-EENV.
 * - ::SCMI_ERR_NOT_FOUND: if \a faultId is invalid.
 * - ::SCMI_ERR_DENIED: if the calling agent is not permitted to get the
 *   state.
 */
int32_t SCMI_FusaFaultGet(uint32_t channel, uint32_t faultId,
    uint32_t *flags);

/*!
 * Set fault state.
 *
 * @param[in]     channel  A2P channel for comms
 * @param[in]     faultId  Global fault identifier
 * @param[in]     flags    State of the fault:<BR>
 *                         Bits[31:1] Reserved, must be zero.<BR>
 *                         Bit[0] Fault state.<BR>
 *                         Set to 1 to set the fault.<BR>
 *                         Set to 0 to clear the fault
 *
 * This function is used by the S-EENVs to assert a SW fault (NCF) at the FCCU
 * module.
 *
 * Access macros:
 * - ::SCMI_FUSA_FAULT_SET_STATE() - Fault state
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the fault state is set successfully.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller
 *   is not an S-EENV.
 * - ::SCMI_ERR_NOT_FOUND: if \a faultId is invalid.
 * - ::SCMI_ERR_DENIED: if the calling agent is not permitted to set the
 *   state.
 */
int32_t SCMI_FusaFaultSet(uint32_t channel, uint32_t faultId,
    uint32_t flags);

/*!
 * Enable/disable fault notifications.
 *
 * @param[in]     channel          A2P channel for comms
 * @param[in]     faultIdFirst     First global fault identifier to be
 *                                 configured
 * @param[in]     faultMask        Mask of faults to modify.<BR>
 *                                 Set to 1 to modify the fault
 *                                 notification.<BR>
 *                                 Set to 0 to leave unmodified
 * @param[in]     notifyEnable     Fault notification enables.<BR>
 *                                 Set to 1 to enable a fault notification.<BR>
 *                                 Set to 0 to disable a fault
 *                                 notification.<BR>
 *                                 Only bits also set to 1 in \a faultMask are
 *                                 modified
 * @param[out]    faultIdFirstGet  Return equal to \a faultIdFirst
 * @param[out]    notifyEnabled    Fault notification enabled state.<BR>
 *                                 Set to 1 indicates the fault notification is
 *                                 enabled.<BR>
 *                                 Set to 0 indicates the fault notification is
 *                                 disabled
 *
 * This function is used to request notification on fault occurrence for one or
 * more faults. Up to 32 faults can be enabled or disabled using one call. The
 * \a faultIdFirst parameter is the faultId bit[0] of the other parameters maps
 * to. Each higher bit then maps to the next faultId.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the fault notification is updated successfully for
 *   some faults.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller
 *   is not an S-EENV.
 * - ::SCMI_ERR_NOT_FOUND: if \a faultIdFirst is invalid.
 * - ::SCMI_ERR_DENIED: if the calling agent is not permitted to modify any
 *   of the requested notifications.
 */
int32_t SCMI_FusaFaultGroupNotify(uint32_t channel, uint32_t faultIdFirst,
    uint32_t faultMask, uint32_t notifyEnable, uint32_t *faultIdFirstGet,
    uint32_t *notifyEnabled);

/*!
 * Temporarily disable fault handling.
 *
 * @param[in]     channel  A2P channel for comms
 *
 * This function is used by the S-EENV during sCheck event processing to
 * temporarily disable user handling of faults being tested. This is used
 * whenever an S-EENV sCheck is about to inject faults for testing purposes and
 * needs to pause normal SM fault processing. In this mode, the injected faults
 * are handled internally by SAF.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if fault handling disabled for the caller.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller
 *   is not an S-EENV.
 */
int32_t SCMI_FusaScheckEvntrig(uint32_t channel);

/*!
 * Start CRC calculation.
 *
 * @param[in]     channel       A2P channel for comms
 * @param[in]     crcChannel    Index of CRC channel
 * @param[in]     crcCfg        CRC CFG value
 * @param[in]     memStartLow   Start address (lower 32-bits)
 * @param[in]     memStartHigh  Start address (upper 32-bits)
 * @param[in]     memSize       Byte count
 *
 * This function can be used by any client to request a HW-accelerated CRC
 * calculation of a memory block. The CRC module is used internally by the SM
 * to accomplish this task. CRC calculation is performed asynchronously, the
 * operation status and result can be retrieved using the
 * SCMI_FusaCrcResultGet() function.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the CRC calcultation started successfully.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller
 *   is not an S-EENV.
 * - ::SCMI_ERR_NOT_FOUND: if \a crcChannel is invalid.
 * - ::SCMI_ERR_INVALID_PARAMETERS: if any of the parameters are invalid.
 * - ::SCMI_ERR_BUSY: if the CRC channel is already performing a CRC
 *   calculation.
 * - ::SCMI_ERR_DENIED: if the calling agent is not permitted to use this CRC
 *   channel.
 */
int32_t SCMI_FusaCrcCalculate(uint32_t channel, uint32_t crcChannel,
    uint32_t crcCfg, uint32_t memStartLow, uint32_t memStartHigh,
    uint32_t memSize);

/*!
 * Get CRC calculation result.
 *
 * @param[in]     channel       A2P channel for comms
 * @param[in]     crcChannel    Index of CRC channel
 * @param[out]    memStartLow   Start address (lower 32-bits)
 * @param[out]    memStartHigh  Start address (upper 32-bits)
 * @param[out]    memSize       Byte count
 * @param[out]    crcResult     Resulting CRC value
 *
 * This function can be used by any client to retrieve the CRC value calculated
 * by the last SCMI_FusaCrcCalculate() function call.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the CRC calcultation completed successfully.
 * - ::SCMI_ERR_NOT_SUPPORTED: if FuSa not an enabled feature or the caller
 *   is not an S-EENV.
 * - ::SCMI_ERR_NOT_FOUND: if \a crcChannel is invalid.
 * - ::SCMI_ERR_BUSY: if the CRC channel has not completed the CRC
 *   calculation.
 * - ::SCMI_ERR_DENIED: if the calling agent is not permitted to use this CRC
 *   channel.
 */
int32_t SCMI_FusaCrcResultGet(uint32_t channel, uint32_t crcChannel,
    uint32_t *memStartLow, uint32_t *memStartHigh, uint32_t *memSize,
    uint32_t *crcResult);

/*!
 * Negotiate the protocol version.
 *
 * @param[in]     channel  A2P channel for comms
 * @param[in]     version  The negotiated protocol version the agent intends to
 *                         use
 *
 * This command is used to negotiate the protocol version that the agent
 * intends to use, if it does not support the version returned by the
 * SCMI_ProtocolVersion() function. There is no limit on the number of
 * negotiations which can be attempted by the agent. All commands, responses,
 * and notifications must comply with the protocol version which was last
 * negotiated successfully. Using protocol versions different from the version
 * returned by SCMI_ProtocolVersion() without successful negotiation is
 * considered best effort, and functionality is not guaranteed.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 *
 * Return errors (see @ref SCMI_STATUS "SCMI error codes"):
 * - ::SCMI_ERR_SUCCESS: if the negotiated protocol version is supported by the
 *   platform. All commands, responses, and notifications post successful
 *   return of this command must comply with the negotiated version.
 * - ::SCMI_ERR_NOT_SUPPORTED: if the protocol version is not supported.
 */
int32_t SCMI_FusaNegotiateProtocolVersion(uint32_t channel,
    uint32_t version);

/*!
 * Read F-EENV state change notification event.
 *
 * @param[in]     channel     P2A notify channel for comms.
 * @param[out]    feenvState  Parameter identifying the requested state of the
 *                            F-EENV.
 * @param[out]    mselMode    Mode selector value as returned by SAF.
 *
 * This notification is sent when the SM (F-EENV) FuSa state machine is
 * requested to gracefully transition to a new state. See all F-EENV states for
 * the SCMI_FusaFeenvStateGet() function description. FuSa relevant agents
 * (S-EENVs) may react to the notification also by advancing to a new state
 * within their S-EENV state machine.
 *
 * To receive the notification, agents need to subscribe using the
 * SCMI_FusaFeenvStateNotify() function.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 */
int32_t SCMI_FusaFeenvStateEvent(uint32_t channel, uint32_t *feenvState,
    uint32_t *mselMode);

/*!
 * Read S-EENV state request notification event.
 *
 * @param[in]     channel     P2A notify channel for comms.
 * @param[out]    pingCookie  Random cookie value
 *
 * This notification can be sent by the SM (F-EENV) any time to request the
 * S-EENVs to report their state using the SCMI_FusaSeenvStateSet() function.
 *
 * To receive the notification, agents need to subscribe using the
 * SCMI_FusaFeenvStateNotify() function. I.e. this notification is sent to any
 * S-EENV which has previously subscribed to F-EENV state notifications.
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 */
int32_t SCMI_FusaSeenvStateReqEvent(uint32_t channel, uint32_t *pingCookie);

/*!
 * Read fault notification event.
 *
 * @param[in]     channel  P2A notify channel for comms.
 * @param[out]    faultId  Global fault identifier
 * @param[out]    flags    Fault state flags
 *
 * This notification is sent by the SM fault handler called from the SAF eMCEM
 * driver when the FCCU reports a fault or when a previously reported fault has
 * been successfully resolved. This is an informative notification broadcast to
 * the agents who subscribed using the SCMI_FusaFaultGroupNotify() function.
 *
 * Access macros:
 * - ::SCMI_FUSA_FAULT_FLAG_STATE() - Fault state (1 detected, 0 resolved)
 *
 * @return Returns the status (::SCMI_ERR_SUCCESS = success).
 */
int32_t SCMI_FusaFaultEvent(uint32_t channel, uint32_t *faultId,
    uint32_t *flags);

#endif /* SCMI_FUSA_H */

/** @} */

