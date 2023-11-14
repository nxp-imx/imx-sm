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
/* Unit test for the SM device timers.                                      */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include <stdio.h>
#include "dev_sm.h"
#include "fsl_sysctr.h"
#include "fsl_systick.h"
#include "board.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test SM device timers                                                    */
/*--------------------------------------------------------------------------*/
void TEST_DevTimers(void)
{
    for (uint32_t msec = 0U; msec <= 1000U; msec += BOARD_TICK_PERIOD_MSEC)
    {
        uint32_t sysTickUsec = msec * 1000U;
        uint64_t globalMsecStart = (uint32_t) DEV_SM_GetTimerMsec();
        uint32_t sysCtrStart = SYSCTR_GetUsec32();
        SystemTimeDelay(sysTickUsec);
        uint32_t sysCtrEnd = SYSCTR_GetUsec32();
        uint64_t globalMsecEnd = (uint32_t) DEV_SM_GetTimerMsec();

        uint32_t globalMsec = (uint32_t) ((globalMsecEnd - globalMsecStart)
            & 0xFFFFFFFFU);
        uint32_t sysCtrMsec = (sysCtrEnd - sysCtrStart) / 1000U;

        printf("SysTick = %u msec, Global = %u msec, SYSCTR = %u msec\n",
            msec, globalMsec, sysCtrMsec);

        if (msec != globalMsec)
        {
            printf("WARNING: DEV_SM_GetTimerMsec mismatch\n");
        }

        if (msec != sysCtrMsec)
        {
            printf("WARNING: SYSCTR mismatch\n");
        }
    }

    printf("\n");
}

