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
 * @addtogroup MB_LOOPBACK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the public API for the MU-based mailbox
 * (MB_LOOPBACK).
 */
/*==========================================================================*/

#ifndef MB_LOOPBACK_H
#define MB_LOOPBACK_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Initialize MB instance.
 *
 * @param[in]     inst        Instance
 * @param[in]     db          Doorbell
 * @param[in]     noIrq       true then don't enable the interrupt
 * @param[in]     initCount   Init count for agent channels
 *
 * Initializes the MB.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t MB_LOOPBACK_Init(uint8_t inst, uint8_t db, bool noIrq,
    uint32_t initCount);

/*!
 * Get MB shared memory address.
 *
 * @param[in]     inst        Instance
 * @param[in]     db          Doorbell
 *
 * Returns the address for the MB instance shared memory. The address is
 * unique per MB instance and doorbell.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
uint32_t *MB_LOOPBACK_SmaGet(uint8_t inst, uint8_t db);

/*!
 * Ring MB doorbell.
 *
 * @param[in]     inst        Instance to ring
 * @param[in]     db          Doorbell
 *
 * Directly calls the dispatch for the doorbell.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t MB_LOOPBACK_DoorbellRing(uint8_t inst, uint8_t db);

/*!
 * Set abort status.
 *
 * @param[in]     inst        Instance to ring
 * @param[in]     state       True = abort asserted
 *
 * Directly sets the abort state.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t MB_LOOPBACK_AbortSet(uint8_t inst, bool state);

/*!
 * Get doorbell state and clear.
 *
 * @param[in]     inst        Instance to check
 * @param[in]     db          Doorbell
 *
 * This reads the state for \a db and clears if pending.
 *
 * @return Returns true if the doorbell was pending.
 */
bool MB_LOOPBACK_DoorbellState(uint8_t inst, uint8_t db);

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
int32_t MB_LOOPBACK_IsAborted(uint8_t inst, uint8_t db);

#endif /* MB_LOOPBACK_H */

/** @} */

