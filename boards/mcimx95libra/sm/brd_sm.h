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

#ifndef BRD_SM_H
#define BRD_SM_H

/*==========================================================================*/
/*!
 * @addtogroup BRD_SM_MX95EVK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the SM abstraction of the board.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "brd_sm_handlers.h"
#include "brd_sm_control.h"
#include "brd_sm_sensor.h"
#include "brd_sm_voltage.h"
#include "brd_sm_bbm.h"
#include "board.h"
#include "brd_sm_api.h"

/* Defines */

/*! Board name string */
#define BRD_SM_NAME  "i.MX95 EVK"

/*! Board attributes */
#define BRD_SM_ATTR  0x0

/*!
 * @name Board redirection defines
 * @{
 */
#define SM_SYSTEMRESET  BRD_SM_SystemReset       /*!< Reset */
/** @} */

/* Types */

/* External variables */

/* Functions */

/*!
 * Reset the system.
 *
 * Redirect to just spin.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS
 */
int32_t BRD_SM_SystemReset(void);

/** @} */

#endif /* BRD_SM_H */

