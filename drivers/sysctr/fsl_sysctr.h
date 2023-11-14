/*
 * Copyright 2023 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DRV_SYSCTR_H
#define DRV_SYSCTR_H

/*!
 * @addtogroup sysctr_driver
 * @{
 */

/*! @file */

/* Includes */
#include "fsl_common.h"

/* SYSCTR counts at a rate of 24 MHz (1/24 usec period).  Conversions
   to/from usec can be calculated using the following:

    1 tick = 1/24 usec  --> ticks / 24 = usec
    1 usec = 24 ticks --> usec * 24 = ticks
*/

/*! Convert ticks to microseconds */
#define SYSCTR_TICKS_TO_USEC(ticks)     ((ticks) / 24U)

/*! Convert microseconds to ticks */
#define SYSCTR_USEC_TO_TICKS(usec)      ((usec) * 24U)

/*! Convert ticks to microseconds (64-bit) */
#define SYSCTR_TICKS_TO_USEC64(ticks)   (((uint64_t) (ticks)) / 24ULL)

/*! Convert microseconds to ticks (64-bit) */
#define SYSCTR_USEC_TO_TICKS64(usec)    (((uint64_t) (usec)) * 24ULL)

/* Types */

/* Externs */

/* Functions */

/*!
 * @name System Counter Functions
 * @{
 */

/*!
 * This function initializes and enables the system counter.
 */
void SYSCTR_Init(void);

/*!
 * This function returns the system counter value as a 64-bit clock
 * cycle count.
 *
 * @return Returns the system counter value.
 */
uint64_t SYSCTR_GetCounter64(void);

/*!
 * This function returns the system counter value as a 32-bit clock
 * cycle count.
 *
 * @return Returns the system counter value.
 */
uint32_t SYSCTR_GetCounter32(void);

/*!
 * This function returns the system counter time in uS. The return
 * value is 64 bits.
 *
 * @return Returns the system counter value in uS.
 */
uint64_t SYSCTR_GetUsec64(void);

/*!
 * This function returns the system counter time in uS. The return
 * value is 32 bits.
 *
 * @return Returns the system counter value in uS.
 */
uint32_t SYSCTR_GetUsec32(void);

/*!
 * This function delays the indicated number of uS.
 *
 * @param[in]     usec        Number of microseconds to delay
 */
void SYSCTR_TimeDelay(uint32_t usec);

/** @} */

#endif /* DRV_SYSCTR_H */

/** @} */

