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

/*==========================================================================*/
/* Unit test for the SM I/O performance.                                    */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include <stdio.h>
#include "fsl_systick.h"

/* Local defines */
#define WRITE32(a,v)    (*(volatile uint32_t *)(a) = (v))
#define READ32(a)       (*(volatile uint32_t *)(a))

/* Local types */

/* Local variables */
static uint32_t const s_muBaseAddrs[] = MU_BASE_ADDRS;


/* Local functions */
uint32_t ProfileIoRead(uint32_t ioAddr, uint32_t *readData)
{
    uint32_t start = SysTick->VAL;
    *readData = READ32(ioAddr);
    uint32_t end = SysTick->VAL;
    uint32_t diff = SYSTICK_TickDiff32(start, end);
    uint64_t nsec64 = diff;
    nsec64 = (nsec64 * 1000000000U) / SYSTICK_GetRate();
    uint32_t nsec = (uint32_t) (nsec64 & 0xFFFFFFFFU);

    return nsec;
}

uint32_t ProfileIoWrite(uint32_t ioAddr, uint32_t writeData)
{
    uint32_t start = SysTick->VAL;
    WRITE32(ioAddr, writeData);
    uint32_t end = SysTick->VAL;
    uint32_t diff = SYSTICK_TickDiff32(start, end);
    uint64_t nsec64 = diff;
    nsec64 = (nsec64 * 1000000000U) / SYSTICK_GetRate();
    uint32_t nsec = (uint32_t) (nsec64 & 0xFFFFFFFFU);

    return nsec;
}

/*--------------------------------------------------------------------------*/
/* Test SM I/O performance                                                  */
/*--------------------------------------------------------------------------*/
void TEST_DevPerfIo(void)
{
    uint32_t tmp = 0U;

    printf("MU1_MUA read took %u nsec\n", ProfileIoRead(s_muBaseAddrs[0],
        &tmp));
    printf("MU2_MUA read took %u nsec\n", ProfileIoRead(s_muBaseAddrs[0],
        &tmp));
    printf("BBNSM GPR[0] read took %u nsec\n", ProfileIoRead(
        (uint32_t) &BBNSM->GPR[0], &tmp));
    printf("BBNSM GPR[0] write took %u nsec\n", ProfileIoWrite(
        (uint32_t) &BBNSM->GPR[0], 0U));

    printf("\n");
}

