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
 * Interface (SCMI) clock protocol.
 */
/*==========================================================================*/

#ifndef RPC_SCMI_CLOCK_H
#define RPC_SCMI_CLOCK_H

/* Includes */

#include "rpc_scmi.h"

/* Functions */

/*!
 * @name SCMI clock protocol functions
 * @{
 */

/*!
 * Dispatch SCMI clock protocol message.
 *
 * @param[in]     caller      Caller info
 * @param[in]     messageId   ID of requested operation
 *
 * This function dispatches an SCMI clock protocol message. The \a caller
 * parameter identifies the calling client. The \a messageId indicates the
 * desired operation.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_INVALID_PARAMETERS if \a messageId isn't supported
 * - others returned by called functions
 */
int32_t RPC_SCMI_ClockDispatchCommand(scmi_caller_t *caller,
    uint32_t messageId);

/*!
 * Dispatch SCMI clock protocol reset.
 *
 * @param[in]     lmId              LM being reset
 * @param[in]     agentId           Agent being reset
 * @param[in]     permissionsReset  Also reset access rights
 *
 * This function dispatches an SCMI clock protocol reset. The \a lmId
 * parameter specifies the resetting LM and \a agentId the agent to reset.
 * The \a permissionsReset bool indicates if access rights should be
 * reset (true = yes). All resources that can be configured via the
 * protocol will always be reset.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t RPC_SCMI_ClockDispatchReset(uint32_t lmId, uint32_t agentId,
    bool permissionsReset);

/** @} */

#endif /* RPC_SCMI_CLOCK_H */

/** @} */

