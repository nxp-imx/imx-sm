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
 * @addtogroup MB_MU
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the public API for the MU-based mailbox
 * (MB_MU).
 */
/*==========================================================================*/

#ifndef MB_MU_H
#define MB_MU_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Initialize MU instance.
 *
 * @param[in]     inst        Instance
 * @param[in]     db          Doorbell
 * @param[in]     noIrq       true then don't enable the interrupt
 * @param[in]     initCount   Init count for agent channels
 *
 * Initializes the MU. Enables the general interrupts used for doorbells.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t MB_MU_Init(uint8_t inst, uint8_t db, bool noIrq, uint32_t initCount);

/*!
 * Get MU shared memory address.
 *
 * @param[in]     inst        Instance
 * @param[in]     db          Doorbell
 *
 * Returns the address for the MU instance shared memory. The address is
 * unique per MU instance and doorbell.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
uint32_t *MB_MU_SmaGet(uint8_t inst, uint8_t db);

/*!
 * Ring MU doorbell.
 *
 * @param[in]     inst        Instance to ring
 * @param[in]     db          Doorbell (aka general interrupt)
 *
 * This asserts the specified doorbell interrupt \a db for the specified
 * instance \a inst. The instance is translated to the linked MU.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t MB_MU_DoorbellRing(uint8_t inst, uint8_t db);

/*!
 * Get doorbell state and clear.
 *
 * @param[in]     inst        Instance to check
 * @param[in]     db          Doorbell (aka general interrupt)
 *
 * This reads the state for \a db and clears if pending.
 *
 * @return Returns true if the doorbell was pending.
 */
bool MB_MU_DoorbellState(uint8_t inst, uint8_t db);

/*!
 * Get abort status.
 *
 * @param[in]     inst        Instance to ring
 * @param[in]     db          Doorbell
 *
 * Returns if the MB is in an aborted state.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if MB not aborted.
 * - ::SM_ERR_ABORT_ERROR: if MB is aborted.
 * - ::SM_ERR_OUT_OF_RANGE: if calling parameters invalid.
 */
int32_t MB_MU_IsAborted(uint8_t inst, uint8_t db);

/*!
 * Handle MU interrupt.
 *
 * @param[in]     mu          MU with pending interrupt
 *
 * This function processes an MU interrupt. The \a mu parameter specifies the
 * index into the SDK base pointer array as defined by MU_BASE_PTRS. This
 * function reads and clears all pending interrupts. It calls the linked
 * transport function.
 */
void MB_MU_Handler(uint32_t mu);

#endif /* MB_MU_H */

/** @} */

