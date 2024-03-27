/*
** ###################################################################
**
**     Copyright 2023-2024 NXP
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
 * @addtogroup DEV_SM_CLOCK_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device clocks.
 */
/*==========================================================================*/

#ifndef DEV_SM_CLOCK_API_H
#define DEV_SM_CLOCK_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/*! Device clock range structure */
typedef struct
{
    /*! Lowest rate (hz) of clock */
    uint64_t lowestRate;
    /*! Highest rate (hz) of clock */
    uint64_t highestRate;
    /*! Step size (hz) of clock */
    uint64_t stepSize;
} dev_sm_clock_range_t;

/* Functions */

/*!
 * Get a clock name.
 *
 * @param[in]     clockId        Clock name to get
 * @param[out]    clockNameAddr  Return pointer to name
 * @param[out]    len            Return max length of all clock names
 *
 * This function allows the caller to get the name of a clock.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a clockId is invalid.
 */
int32_t DEV_SM_ClockNameGet(uint32_t clockId, string *clockNameAddr,
    int32_t *len);

/*!
 * Get a device clock description.
 *
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
 * - ::SM_ERR_NOT_FOUND: if \a clockId is invalid.
 */
int32_t DEV_SM_ClockDescribe(uint32_t clockId,
    dev_sm_clock_range_t *range);

/*!
 * Get a device clock mux option.
 *
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
 * - ::SM_ERR_NOT_FOUND: if \a clockId is invalid.
 * - ::SM_ERR_OUT_OF_RANGE : if \a idx is invalid.
 * - ::SM_ERR_NOT_SUPPORTED : if no mux input.
 */
int32_t DEV_SM_ClockMuxGet(uint32_t clockId, uint32_t idx, uint32_t *mux,
    uint32_t *numMuxes);

/*!
 * Set a device clock rate.
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
int32_t DEV_SM_ClockRateSet(uint32_t clockId, uint64_t rate,
    uint32_t roundSel);

/*!
 * Get a device clock rate.
 *
 * @param[in]     clockId   Identifier for the clock device
 * @param[out]    rate      Clock rate in hertz
 *
 * This function allows the caller to get the clock rate of a clock.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a clockId is invalid.
 */
int32_t DEV_SM_ClockRateGet(uint32_t clockId, uint64_t *rate);

/*!
 * Set a device clock enable state.
 *
 * @param[in]     clockId   Identifier for the clock device
 * @param[in]     enable    Clock enable (true = enabled)
 *
 * This function allows the caller to set the clock state of a clock.
 * True indicates the clock should be enabled.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND if \a clockId out of range
 * - ::SM_ERR_INVALID_PARAMETERS: if the clock state cannot be changed.
 */
int32_t DEV_SM_ClockEnable(uint32_t clockId, bool enable);

/*!
 * Get a device clock enable state.
 *
 * @param[in]     clockId   Identifier for the clock device
 * @param[out]    enabled   Pointer to return the state
 *
 * This function allows the caller to get the clock state of a clock.
 * True indicates the clock is enabled.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND if \a clockId out of range
 */
int32_t DEV_SM_ClockIsEnabled(uint32_t clockId, bool *enabled);

/*!
 * Set a device clock parent.
 *
 * @param[in]     clockId   Identifier for the clock device
 * @param[in]     parent    Clock parent
 *
 * This function allows the caller to set the clock parent of a clock.
 * The \a parent parameter is another clock ID.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a clockId is invalid.
 * - ::SM_ERR_INVALID_PARAMETERS: if \a parent is invalid.
 */
int32_t DEV_SM_ClockParentSet(uint32_t clockId, uint32_t parent);

/*!
 * Get a device clock parent.
 *
 * @param[in]     clockId   Identifier for the clock device
 * @param[out]    parent    Pointer to return the clock parent
 *
 * This function allows the caller to get the clock parent of a clock.
 * The returned parent is another clock ID.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a clockId is invalid.
 */
int32_t DEV_SM_ClockParentGet(uint32_t clockId, uint32_t *parent);

/*!
 * Set a device extended clock data value.
 *
 * @param[in]     clockId            Identifier for the clock device
 * @param[in]     extId              Extended data identifier
 * @param[in]     extConfigValue     Extended configuration value
 *
 * This function allows the caller to set clock extendeed data.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the clock rate was set successfully.
 * - ::SM_ERR_NOT_FOUND: if \a supported extId not found.
 * - ::SM_ERR_INVALID_PARAMETERS: if \a clockId is invalid
 */
int32_t DEV_SM_ClockExtendedSet(uint32_t clockId, uint32_t extId,
    uint32_t extConfigValue);

/*!
 * Get a device extended clock data value.
 *
 * @param[in]     clockId            Identifier for the clock device
 * @param[in]     extId              Extended data identifier
 * @param[out]    extConfigValue     Pointer to return the extended data value
 *
 * This function allows the caller to get clock extended data.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the clock rate was set successfully.
 * - ::SM_ERR_NOT_FOUND: if \a supported extId not found.
 * - ::SM_ERR_INVALID_PARAMETERS: if \a clockId is invalid
 */
int32_t DEV_SM_ClockExtendedGet(uint32_t clockId, uint32_t extId,
    uint32_t *extConfigValue);

#endif /* DEV_SM_CLOCK_API_H */

/** @} */

