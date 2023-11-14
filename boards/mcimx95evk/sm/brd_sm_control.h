/*
** ###################################################################
**
**     Copyright 2023 NXP
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/*!
 * @addtogroup BRD_SM_MX95EVK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the board controls.
 */
/*==========================================================================*/

#ifndef BRD_SM_CONTROL_H
#define BRD_SM_CONTROL_H

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Defines */

/*!
 * @name Board redirection defines
 * @{
 */
#define SM_CONTROLGET          BRD_SM_ControlGet          /*!< Control get */
#define SM_CONTROLFLAGSSET     BRD_SM_ControlFlagsSet     /*!< Control flags */
/** @} */

/*! Number of board controls */
#define BRD_SM_NUM_CTRL  5UL

/*! Total number of controls */
#define SM_NUM_CTRL  (DEV_SM_NUM_CTRL + BRD_SM_NUM_CTRL)

/*!
 * @name BRD_SM control domain indexes
 */
/** @{ */
#define BRD_SM_CTRL_SD3_WAKE    (DEV_SM_NUM_CTRL + 0U)  /*!< PCAL6408A-0 */
#define BRD_SM_CTRL_PCIE1_WAKE  (DEV_SM_NUM_CTRL + 1U)  /*!< PCAL6408A-4 */
#define BRD_SM_CTRL_BT_WAKE     (DEV_SM_NUM_CTRL + 2U)  /*!< PCAL6408A-5 */
#define BRD_SM_CTRL_PCIE2_WAKE  (DEV_SM_NUM_CTRL + 3U)  /*!< PCAL6408A-6 */
#define BRD_SM_CTRL_BUTTON      (DEV_SM_NUM_CTRL + 4U)  /*!< PCAL6408A-7 */
/** @} */

/* Types */

/* Functions */

/*!
 * @name Board control functions
 * @{
 */

/*!
 * Get a board control value.
 *
 * @param[in]     ctrlId   Index of control to read
 * @param[out]    numRtn   Return pointer to number of array elements
 * @param[out]    rtn      Pointer to array to store return
 *
 * This function allows a caller to read an array of values for
 * a control.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if ctrlId is not valid.
 */
int32_t BRD_SM_ControlGet(uint32_t ctrlId, uint32_t *numRtn, uint32_t *rtn);

/*!
 * Configure notification flags for a control.
 *
 * @param[in]     ctrlId   Index of control to take action
 * @param[in]     flags    Action to take
 *
 * This function allows a caller to configure the notification flags.
 * These often enable/disable hardware interrupts.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if ctrlId is not valid.
 */
int32_t BRD_SM_ControlFlagsSet(uint32_t ctrlId, uint32_t flags);

/*!
 * Control handler.
 *
 * @param[in]     status   Interrupt status
 * @param[in]     val      Signal state
 */
void BRD_SM_ControlHandler(uint8_t status, uint8_t val);

/** @} */

#endif /* BRD_SM_CONTROL_H */

/** @} */

