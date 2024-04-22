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

/* Includes */
#include "fsl_systick.h"

/* Local Defines */

/* Specify margin to allow for CPU cycles needed for calculating
 * differences between snapshots of SysTick 
 */ 
#define SYSTICK_ELAPSE_MARGIN   1024U

#define SYSTICK_CTRL_CLKSOURCE(x) \
    (((uint32_t)(((uint32_t)(x)) << SysTick_CTRL_CLKSOURCE_Pos)) & SysTick_CTRL_CLKSOURCE_Msk)

#define SYSTICK_CTRL_TICKINT(x) \
    (((uint32_t)(((uint32_t)(x)) << SysTick_CTRL_TICKINT_Pos)) & SysTick_CTRL_TICKINT_Msk)

/* Local Types */

/* Local Functions */

/* Local Variables */
static uint32_t s_sysTickRate = 0U;
static uint32_t s_sysTickMax = 0U;

/*--------------------------------------------------------------------------*/
/* SysTick initialization                                                   */
/*--------------------------------------------------------------------------*/
void SYSTICK_Init(uint32_t enableInt, uint32_t clkSource, uint32_t tickRate,
                  uint32_t reloadVal)
{
    /* Clamp reload value at 2x margin needed to calculate counter diffs */
    uint32_t reloadValClamped = (reloadVal < SYSTICK_ELAPSE_MARGIN) ?
        (SYSTICK_ELAPSE_MARGIN << 1U) : reloadVal;

    /* Configure and enable SYSTICK */
    SysTick->LOAD  = reloadValClamped;
    SysTick->VAL   = 0U;
    SysTick->CTRL  = SYSTICK_CTRL_CLKSOURCE(clkSource) | 
                     SYSTICK_CTRL_TICKINT(enableInt) |
                     SysTick_CTRL_ENABLE_Msk;

    /* Update locally stored rate */
    s_sysTickRate = tickRate;
    s_sysTickMax = reloadValClamped - SYSTICK_ELAPSE_MARGIN;
}

/*--------------------------------------------------------------------------*/
/* SysTick update locally stored clock rate                                 */
/*--------------------------------------------------------------------------*/
void SYSTICK_UpdateRate(uint32_t tickRate)
{
    s_sysTickRate = tickRate;
}

/*--------------------------------------------------------------------------*/
/* SysTick get rate                                                         */
/*--------------------------------------------------------------------------*/
uint32_t SYSTICK_GetRate(void)
{
    return s_sysTickRate;
}

/*--------------------------------------------------------------------------*/
/* SysTick calculate ticks                                                  */
/*--------------------------------------------------------------------------*/
uint64_t SYSTICK_UsecToTicks(uint32_t usec)
{
    uint64_t ticks = s_sysTickRate;

    ticks = (ticks * usec) / 1000000U;

    return ticks;
}

/*--------------------------------------------------------------------------*/
/* Delay (busy loop) specified number of cycles using the SysTick           */
/*--------------------------------------------------------------------------*/
void SYSTICK_CycleDelay(uint32_t cycles)
{
    uint32_t cntStart, cntEnd;

    cntStart = SysTick->VAL;
    /* Loop until done */
    do
    {
        cntEnd = SysTick->VAL;
    } while (SYSTICK_TickDiff32(cntStart, cntEnd)
             < (cycles & SysTick_VAL_CURRENT_Msk));
}

/*--------------------------------------------------------------------------*/
/* Delay (busy loop) specified number of usec using default SysTick rate    */
/*--------------------------------------------------------------------------*/
void SYSTICK_TimeDelay(uint32_t usec)
{
    uint64_t ticks = SYSTICK_UsecToTicks(usec);
    
    /* Loop to break delay into smaller chunks */
    while (ticks >  s_sysTickMax)
    {
        SYSTICK_CycleDelay(s_sysTickMax);
        ticks -= s_sysTickMax;
    }
    SYSTICK_CycleDelay((uint32_t) ticks & 0xFFFFFFFFU);
}

/*--------------------------------------------------------------------------*/
/* Reutrn the systick counter value                                         */
/*--------------------------------------------------------------------------*/
uint32_t SYSTICK_GetCounter32(void)
{
    /* return value */
    return SysTick->VAL;
}

/*--------------------------------------------------------------------------*/
/* Calculate difference between SysTick captures                            */
/*--------------------------------------------------------------------------*/
uint32_t SYSTICK_TickDiff32(uint32_t cntStart, uint32_t cntEnd)
{
    uint32_t diff;

    if (cntStart < cntEnd)
    {
        diff = (SysTick->LOAD+1U) - cntEnd + cntStart;
    }
    else
    {
        diff = cntStart - cntEnd;
    }

    return diff;
}

/** @} */

