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
#include "fsl_sysctr.h"

/* Local Types */

/* Local Functions */

/* Local Variables */

/*--------------------------------------------------------------------------*/
/* Initialize and enable SYSCTR                                             */
/*--------------------------------------------------------------------------*/
void SYSCTR_Init(void)
{
    SYS_CTR_CONTROL->CNTCR =
        SYS_CTR_CONTROL_CNTCR_HDBG(1U) |
        SYS_CTR_CONTROL_CNTCR_EN(1U);
}


/*--------------------------------------------------------------------------*/
/* Get 64-bit counter value from SYSCTR (counter is 56-bit)                 */
/*--------------------------------------------------------------------------*/
uint64_t SYSCTR_GetCounter64(void)
{
    uint32_t ls, ms, ms2;

    /* Do consecutive reads to guard against ripple */
    do
    {
        ms = SYS_CTR_CONTROL->CNTCV1;
        ls = SYS_CTR_CONTROL->CNTCV0;
        ms2 = SYS_CTR_CONTROL->CNTCV1;
    } while (ms != ms2);

    uint64_t ticks = ms;
    ticks = (ticks << 32U) | ls;

    return ticks;
}

/*--------------------------------------------------------------------------*/
/* Get 32-bit counter value from SYSCTR (32 LSBs counter)                   */
/*--------------------------------------------------------------------------*/
uint32_t SYSCTR_GetCounter32(void)
{
    return SYS_CTR_CONTROL->CNTCV0;
}


/*--------------------------------------------------------------------------*/
/* Get 64-bit count of usec since SYSCTR has started                        */
/*--------------------------------------------------------------------------*/
uint64_t SYSCTR_GetUsec64(void)
{
    return SYSCTR_TICKS_TO_USEC64(SYSCTR_GetCounter64());
}


/*--------------------------------------------------------------------------*/
/* Get 32-bit count of usec since SYSCTR has started                        */
/*--------------------------------------------------------------------------*/
uint32_t SYSCTR_GetUsec32(void)
{
    return SYSCTR_TICKS_TO_USEC(SYSCTR_GetCounter32());
}


/*--------------------------------------------------------------------------*/
/* Delay (busy loop) specified number of usec using the SYSCTR              */
/*--------------------------------------------------------------------------*/
void SYSCTR_TimeDelay(uint32_t usec)
{
    uint64_t delayTicks;
    uint64_t startTicks;

    startTicks = SYSCTR_GetCounter64();
    delayTicks = SYSCTR_USEC_TO_TICKS64(usec);

    while ((SYSCTR_GetCounter64() - startTicks) < delayTicks)
    {
    }
}
