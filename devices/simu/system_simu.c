/*
** ###################################################################
**
** Copyright 2025-2026 NXP
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

#include <stdint.h>
#include <unistd.h>
#include <system_simu.h>

/* Local defines */

/* ----------------------------------------------------------------------------
   -- SystemTimeDelay(usec)
   ---------------------------------------------------------------------------- */
void SystemTimeDelay(uint32_t usec)
{
    (void) usleep(usec);
}

/* ----------------------------------------------------------------------------
   -- SystemMemoryProbe(addr, val, width)
   ---------------------------------------------------------------------------- */
uint32_t SystemMemoryProbe(const void *addr, void *val, uint8_t width)
{
    uint32_t rtn = 0U;
    /* coverity[misra_c_2012_rule_11_6_violation] */
    uint32_t pAddr = (uint32_t) addr;

    if ((pAddr >= 0x80000000UL) && (pAddr < 0x80010000UL))
    {
        // Perform the probe
        switch (width)
        {
            default:
                /* Pointer coversion required for generic memory access */
                /* coverity[misra_c_2012_rule_11_5_violation] */
                *((uint8_t *) val) = *((const uint8_t *) addr);
                break;
            case 16:
                /* Pointer coversion required for generic memory access */
                /* coverity[misra_c_2012_rule_11_5_violation] */
                *((uint16_t *) val) = *((const uint16_t *) addr);
                break;
            case 32:
                /* Pointer coversion required for generic memory access */
                /* coverity[misra_c_2012_rule_11_5_violation] */
                *((uint32_t *) val) = *((const uint32_t *) addr);
                break;
        }
    }
    else
    {
        rtn = 1U;
    }

    return rtn;
}

