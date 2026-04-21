/*
** ###################################################################
**
**     Copyright 2026 NXP
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
 * Header file containing the SM API for the board clocks.
 */
/*==========================================================================*/

#ifndef BRD_SM_CLOCK_H
#define BRD_SM_CLOCK_H

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Defines */

/*!
 * @name Board redirection defines
 * @{
 */
#define SM_CLOCKRATESET       BRD_SM_ClockRateSet   /*!< Clock rate set */
/** @} */

/* Types */

/* Functions */

/*!
 * Init board clock override.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t BRD_SM_ClockInit(void);

/*!
 * Set a board clock rate.
 *
 * @param[in]     clockId   Identifier for the clock device
 * @param[in]     rate      Clock rate in hertz
 * @param[in]     roundSel  Device-specific rounding option
 *
 * This function allows the caller to set the clock rate of a clock.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a clockId is invalid.
 * - ::SM_ERR_INVALID_PARAMETERS: if \a rate or \a roundSel is invalid.
 */
int32_t BRD_SM_ClockRateSet(uint32_t clockId, uint64_t rate,
    uint32_t roundSel);

#endif /* BRD_SM_CLOCK_H */

/** @} */

