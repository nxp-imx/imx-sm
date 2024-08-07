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
 * @addtogroup RPC_SMT
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the public API for the Shared Memory Transport
 * (SMT) as defined by SCMI v3.2 spec.
 */
/*==========================================================================*/

#ifndef RPC_SMT_H
#define RPC_SMT_H

/* Includes */

#include "sm.h"

/* Defines */

/*! SMT buffer size */
#define SMT_BUFFER_SIZE     128U
/*! SMT buffer header size */
#define SMT_BUFFER_HEADER   24U
/*! SMT buffer payload size */
#define SMT_BUFFER_PAYLOAD  (SMT_BUFFER_SIZE - SMT_BUFFER_HEADER - 4U)

/* Functions */

/*!
 * Initialize the SMT channel.
 *
 * @param[in]     smtChannel  SMT channel
 * @param[in]     noIrq       true then don't enable the interrupt
 * @param[in]     initCount   Init count for agent channels
 *
 * This function initializes the shared memory area. It calls the mailbox
 * driver to initialize that as well. It leaves the channel free and ready
 * to receive messages.
 *
 * @return Returns the buffer address.
 */
int32_t RPC_SMT_Init(uint32_t smtChannel, bool noIrq, uint32_t initCount);

/*!
 * Get SMT payload address.
 *
 * @param[in]     smtChannel  SMT channel
 *
 * This function gets the address of the header/payload in the shared memory
 * buffer. The returned address can be used to directly read/write the payload
 * area of the shared memory buffer. This is only way to write data to be
 * sent with RPC_SMT_Tx(). Note reading data is normally done with RPC_SMT_Rx()
 * which makes a copy for the caller.
 *
 * @return Returns the buffer address.
 */
void *RPC_SMT_HdrAddrGet(uint32_t smtChannel);

/*!
 * Get SMT channel status.
 *
 * @param[in]     smtChannel  SMT channel
 *
 * This function returns the channel status.
 *
 * @return Channel status. True if the channel is free, false
           if busy.
 */
bool RPC_SMT_ChannelFree(uint32_t smtChannel);

/*!
 * Dispatch SMT doorbell.
 *
 * @param[in]     smtChannel  SMT channel
 *
 * This function dispatches an SMT doorbell interrupt. The \a smtChannel
 * parameter is used to index into the local const SMT config structure
 * to find the linked RPC type and RPC channel. The RPC disptch function
 * is then called.
 */
void RPC_SMT_Dispatch(uint32_t smtChannel);

/*!
 * Get SMT doorbell state and clear.
 *
 * @param[in]     smtChannel  SMT channel
 *
 * This reads the doorbell state for \a smtChannel and clears if pending.
 *
 * @return Returns true if the doorbell was pending.
 */
bool RPC_SMT_DoorbellState(uint32_t smtChannel);

/*!
 * Get abort status.
 *
 * @param[in]     smtChannel  SMT channel
 *
 * Returns if the SMT channel is in an aborted state.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if not aborted.
 * - ::SM_ERR_ABORT_ERROR: if aborted.
 * - ::SM_ERR_OUT_OF_RANGE: if \a smtChannel is invalid.
 */
int32_t RPC_SMT_IsAborted(uint32_t smtChannel);

/*!
 * Transmit SMT payload.
 *
 * @param[in]     smtChannel  SMT channel buffer to send
 * @param[in]     len         Size of payload to transmit
 * @param[in]     callee      Caller/callee boolean
 * @param[in]     compInt     Caller wants a completion interrupt
 *
 * This function transmits an SMT payload. The payload should have been
 * written directly into the buffer using the address obtained via
 * RPC_SMT_HdrAddrGet(). The \a smtChannel parameter identifies the channel
 * to send on. The \a len parameter specifies the size of the payload in
 * bytes. The \a callee boolean parameter specifies the protocol direction:
 *
 * - false: caller, initiation of a call on an empty channel, trigger a
 *          doorbell
 * - true:  calee, send a response on a busy channel, trigger a completion
 *          doorbell if requested
 *
 * This function may calculate the CRC of the payload and write it into
 * the shared memory area depending on configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_PROTOCOL_ERROR if the len is greater than the buffer size
 * - ::SM_ERR_GENERIC_ERROR if the configured buffer is NULL
 * - others returned by RPC_SMT_DoorbellRing()
 */
int32_t RPC_SMT_Tx(uint32_t smtChannel, uint32_t len, bool callee,
    bool compInt);

/*!
 * Receive SMT payload.
 *
 * @param[in]     smtChannel  SMT channel buffer to read
 * @param[out]    msgRx       Pointer to the destination buffer
 * @param[inout]  len         Pointer to destination buffer size
 * @param[in]     callee      Caller/callee boolean
 *
 * This function receives an SMT payload. The \a smtChannel parameter
 * identifies the channel to read. The \a msgRx parameter points to a
 * buffer to copy the payload to. The \a len parameter is passed in as
 * the max size of the destination buffer but returns the actual size
 * unless the max is exceeded.
 *
 * After making the copy, this function may calculate the CRC of the
 * destination buffer and compare it to the sent CRC. This depends on
 * the configuration of the channel.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_CRC_ERROR if the CRC fails to match
 * - ::SM_ERR_GENERIC_ERROR if the configured buffer is NULL
 */
int32_t RPC_SMT_Rx(uint32_t smtChannel, void* msgRx, uint32_t *len,
    bool callee);

#endif /* RPC_SMT_H */

/** @} */

