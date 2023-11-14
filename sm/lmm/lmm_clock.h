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
 * @addtogroup LMM_CLOCK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager clocks.
 */
/*==========================================================================*/

#ifndef LMM_CLOCK_H
#define LMM_CLOCK_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Init LM clock management.
 *
 * @param[in]     numClock       Number of clocks
 * @param[in]     clockList      List of clocks
 *
 * This function copies current clock state. This include is used when an
 * LM is rebooted.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: initialized successfully.
 */
int32_t LMM_ClockInit(uint32_t numClock, const uint32_t *clockList);

/*!
 * Get an LM clock name.
 *
 * @param[in]     lmId           LM call is for
 * @param[in]     clockId        Clock name to get
 * @param[out]    clockNameAddr  Return pointer to name
 * @param[out]    len            Return max length of all clock names
 *
 * This function allows the caller to get the name of a clock.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the name is returned.
 * - others returned by ::SM_CLOCKNAMEGET
 */
int32_t LMM_ClockNameGet(uint32_t lmId, uint32_t clockId,
    string *clockNameAddr, int32_t *len);

/*!
 * Get an LM clock description.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     clockId  Clock description to get
 * @param[out]    range    Pointer to return range
 *
 * This function allows the caller to get the frequency range for
 * a clock. The range contains the high, low, and step frequencies
 * in hertz.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the range is returned.
 * - others returned by ::SM_CLOCKDESCRIBE
 */
int32_t LMM_ClockDescribe(uint32_t lmId, uint32_t clockId,
    dev_sm_clock_range_t *range);

/*!
 * Get an LM clock mux option.
 *
 * @param[in]     lmId      LM call is for
 * @param[in]     clockId   Clock description to get
 * @param[in]     idx       Mux index to get
 * @param[out]    mux       Pointer to return the clock index
 *                          of mux input
 * @param[out]    numMuxes  Number of mux inputs
 *
 * This function allows the caller to get the clock ID of the mux
 * input \a idx.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the range is returned.
 * - others returned by ::SM_CLOCKMUXGET
 */
int32_t LMM_ClockMuxGet(uint32_t lmId, uint32_t clockId, uint32_t idx,
    uint32_t *mux, uint32_t *numMuxes);

/*!
 * Set an LM clock rate.
 *
 * @param[in]     lmId      LM call is for
 * @param[in]     clockId   Identifier for the clock device
 * @param[in]     rate      Clock rate in hertz
 * @param[in]     roundSel  Device-specific rounding option
 *
 * This function allows the caller to set the clock rate of a clock
 * synchronously. Nothing is aggregated and one rate exists per clock.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the clock rate was set successfully.
 * - others returned by ::SM_CLOCKRATESET
 */
int32_t LMM_ClockRateSet(uint32_t lmId, uint32_t clockId, uint64_t rate,
    uint32_t roundSel);

/*!
 * Get an LM clock rate.
 *
 * @param[in]     lmId      LM call is for
 * @param[in]     clockId   Identifier for the clock device
 * @param[out]    rate      Pointer to return rate in hertz
 *
 * This function allows the caller to get the clock rate of a clock
 * synchronously.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the clock rate was returned successfully.
 * - others returned by ::SM_CLOCKRATEGET
 */
int32_t LMM_ClockRateGet(uint32_t lmId, uint32_t clockId,
    uint64_t *rate);

/*!
 * Reset clock rate back to that captured at boot.
 *
 * @param[in]     lmId      LM call is for
 * @param[in]     clockId   Identifier for the clock device
 *
 * This function allows the caller to reset the clock rate and
 * parent back to those captured in LMM_ClockInit().
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the clock was reset successfully.
 * - others returned by LMM_ClockParentSet() or LMM_ClockRateSet().
 */
int32_t LMM_ClockReset(uint32_t lmId, uint32_t clockId);

/*!
 * Set an LM clock enable state.
 *
 * @param[in]     lmId      LM call is for
 * @param[in]     clockId   Identifier for the clock device
 * @param[in]     enable    Clock enable (true = enabled)
 *
 * This function allows the caller to set the clock state of a clock
 * synchronously. True indicates the clock should be enabled. The
 * state is recorded per LM and aggregated. It is enabled if any LM
 * has enabled. It is only disabled when all LM have requested the
 * clock be disabled.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the clock state was set successfully.
 * - ::SM_ERR_INVALID_PARAMETERS if \a lmId out of range
 * - ::SM_ERR_NOT_FOUND if \a clockId out of range
 * - others returned by ::SM_CLOCKENABLE
 */
int32_t LMM_ClockEnable(uint32_t lmId, uint32_t clockId, bool enable);

/*!
 * Get an LM clock enable state.
 *
 * @param[in]     lmId      LM call is for
 * @param[in]     clockId   Identifier for the clock device
 * @param[out]    enabled   Pointer to return the state
 *
 * This function allows the caller to get the clock state of a clock
 * synchronously. True indicates the clock is enabled.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the clock state was returned successfully.
 * - others returned by ::SM_CLOCKISENABLED
 */
int32_t LMM_ClockIsEnabled(uint32_t lmId, uint32_t clockId, bool *enabled);

/*!
 * Set an LM clock parent.
 *
 * @param[in]     lmId      LM call is for
 * @param[in]     clockId   Identifier for the clock device
 * @param[in]     parent    Clock parent
 *
 * This function allows the caller to set the clock parent of a clock
 * synchronously. Nothing is aggregated and one parent exists per clock.
 * The \a parent parameter is another clock ID.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the clock rate was set successfully.
 * - others returned by ::SM_CLOCKPARENTSET
 */
int32_t LMM_ClockParentSet(uint32_t lmId, uint32_t clockId, uint32_t parent);

/*!
 * Get an LM clock parent.
 *
 * @param[in]     lmId      LM call is for
 * @param[in]     clockId   Identifier for the clock device
 * @param[out]    parent    Pointer to return the clock parent
 *
 * This function allows the caller to get the clock parent of a clock.
 * The returned parent is another clock ID.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the clock rate was set successfully.
 * - others returned by ::SM_CLOCKPARENTGET
 */
int32_t LMM_ClockParentGet(uint32_t lmId, uint32_t clockId, uint32_t *parent);

#endif /* LMM_CLOCK_H */

/** @} */

