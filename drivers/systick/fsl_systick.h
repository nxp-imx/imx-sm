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

#ifndef DRV_SYSTICK_H
#define DRV_SYSTICK_H

/*!
 * @addtogroup systick_driver
 * @{
 */

/*! @file */

/* Includes */
#include "fsl_common.h"

/* Defines */

/* Types */

/* Externs */

/* Functions */

/*!
 * @name System Timer (SysTick) Functions
 * @{
 */

/*!
 * Initialize the SYSTICK module.
 *
 * @param[in]     enableInt   Enable value
 * @param[in]     clkSource   Clock source
 * @param[in]     tickRate    Tick rate
 * @param[in]     reloadVal   Reload value
 */
void SYSTICK_Init(uint32_t enableInt, uint32_t clkSource, uint32_t tickRate,
                  uint32_t reloadVal);

/*!
 * Update locally stored clock rate.
 *
 * @param[in]     tickRate    New rate
 */
void SYSTICK_UpdateRate(uint32_t tickRate);

/*!
 * Get locally stored clock rate.
 *
 * @return Rate.
 */
uint32_t SYSTICK_GetRate(void);

/*!
 * Convert microseconds to ticks.
 *
 * @param[in]     usec        Pointer to ROM ID
 *
 * @return Tick count.
 */
uint64_t SYSTICK_UsecToTicks(uint32_t usec);

/*!
 * Delay (busy loop) specified number of cycles using the SysTick.
 *
 * @param[in]     cycles      number of cycles
 */
void SYSTICK_CycleDelay(uint32_t cycles);

/*!
 * Delay (busy loop) specified number of usec using default SysTick rate.
 *
 * @param[in]     usec        number of microseconds
 */
void SYSTICK_TimeDelay(uint32_t usec);

/*!
 * Get 32-bit counter.
 *
 * @return 32-bit count value.
 */
uint32_t SYSTICK_GetCounter32(void);

/*!
 * Calculate difference between SysTick captures.
 *
 * @param[in]     cntStart    start counter
 * @param[in]     cntEnd      end counter
 *
 * @return Difference count.
 */
uint32_t SYSTICK_TickDiff32(uint32_t cntStart, uint32_t cntEnd);

/** @} */


#endif /* DRV_SYSTICK_H */

/** @} */
