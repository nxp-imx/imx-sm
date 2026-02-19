/*
** ###################################################################
**
** Copyright 2023-2026 NXP
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
/* Unit test for the device SM API.                                         */
/*==========================================================================*/

/* DEV_00010 */

/* Include Config */

/* Includes */

#include "test.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test IRQ handlers                                                        */
/*--------------------------------------------------------------------------*/
void TEST_DevSmHandler(void)
{
#ifndef SIMU
    const uint32_t fakeStack[10] = { 0 };
#endif

    printf("TEST_DevSmHandler\n");
#ifndef SIMU
    SM_TestModeSet(SM_TEST_MODE_DEV_LVL1);

    NVIC_EnableIRQ(NMI_INT_TRIGGER);
    SCB->ICSR |= 1UL << SCB_ICSR_PENDNMISET_Pos;

#ifdef BUS_FAULT_INT_TRIGGER
    BusFault_Handler(&fakeStack[0]);
#endif

#ifdef USAGE_FAULT_INT_TRIGGER
    UsageFault_Handler(&fakeStack[0]);
#endif

#ifdef MEM_MANAGEMENT_FAULT_INT
    MemManage_Handler(&fakeStack[0]);
#endif

#ifdef HARD_FAULT_INT_TRIGGER
    HardFault_Handler(&fakeStack[0]);
#endif

#ifdef WDOG1_IRQ_HANDLER
    NVIC_EnableIRQ(WDOG1_IRQ_HANDLER);
    NVIC_SetPendingIRQ(WDOG1_IRQ_HANDLER);
#endif

#ifdef WDOG2_IRQ_HANDLER
    NVIC_EnableIRQ(WDOG2_IRQ_HANDLER);
    NVIC_SetPendingIRQ(WDOG2_IRQ_HANDLER);
#endif

#ifdef WDOG3_IRQ_HANDLER
    NVIC_EnableIRQ(WDOG3_IRQ_HANDLER);
    NVIC_SetPendingIRQ(WDOG3_IRQ_HANDLER);
#endif

#ifdef WDOG4_IRQ_HANDLER
    NVIC_EnableIRQ(WDOG4_IRQ_HANDLER);
    NVIC_SetPendingIRQ(WDOG4_IRQ_HANDLER);
#endif

#ifdef WDOG5_IRQ_HANDLER
    NVIC_EnableIRQ(WDOG5_IRQ_HANDLER);
    NVIC_SetPendingIRQ(WDOG5_IRQ_HANDLER);
#endif

#ifdef WDOG6_IRQ_HANDLER
    NVIC_EnableIRQ(WDOG6_IRQ_HANDLER);
    NVIC_SetPendingIRQ(WDOG6_IRQ_HANDLER);
#endif

#ifdef WDOG7_IRQ_HANDLER
    NVIC_EnableIRQ(WDOG7_IRQ_HANDLER);
    NVIC_SetPendingIRQ(WDOG7_IRQ_HANDLER);
#endif

#ifdef WDOG8_IRQ_HANDLER
    NVIC_EnableIRQ(WDOG8_IRQ_HANDLER);
    NVIC_SetPendingIRQ(WDOG8_IRQ_HANDLER);
#endif

#ifdef TMPSNS_ANA1_IRQ_HANDLER
    NVIC_EnableIRQ(TMPSNS_ANA1_IRQ_HANDLER);
    NVIC_SetPendingIRQ(TMPSNS_ANA1_IRQ_HANDLER);
#endif

#ifdef TMPSNS_ANA2_IRQ_HANDLER
    NVIC_EnableIRQ(TMPSNS_ANA2_IRQ_HANDLER);
    NVIC_SetPendingIRQ(TMPSNS_ANA2_IRQ_HANDLER);
#endif

#ifdef TMPSNS_CRTX1_IRQ_HANDLER
    NVIC_EnableIRQ(TMPSNS_CRTX1_IRQ_HANDLER);
    NVIC_SetPendingIRQ(TMPSNS_CRTX1_IRQ_HANDLER);
#endif

#ifdef TMPSNS_CRTX2_IRQ_HANDLER
    NVIC_EnableIRQ(TMPSNS_CRTX2_IRQ_HANDLER);
    NVIC_SetPendingIRQ(TMPSNS_CRTX2_IRQ_HANDLER);
#endif

#ifdef ELE_GRP1_IRQ_HANDLER
    NVIC_EnableIRQ(ELE_GRP1_IRQ_HANDLER);
    NVIC_SetPendingIRQ(ELE_GRP1_IRQ_HANDLER);
#endif

#ifdef ELE_GRP2_IRQ_HANDLER
    NVIC_EnableIRQ(ELE_GRP2_IRQ_HANDLER);
    NVIC_SetPendingIRQ(ELE_GRP2_IRQ_HANDLER);
#endif

#ifdef ELE_GRP3_IRQ_HANDLER
    NVIC_EnableIRQ(ELE_GRP3_IRQ_HANDLER);
    NVIC_SetPendingIRQ(ELE_GRP3_IRQ_HANDLER);
#endif

#ifdef CM7_RESET_IRQ_HANDLER
    NVIC_EnableIRQ(CM7_RESET_IRQ_HANDLER);
    NVIC_SetPendingIRQ(CM7_RESET_IRQ_HANDLER);
#endif

#ifdef CM7_LOCKUP_IRQ_HANDLER
    NVIC_EnableIRQ(CM7_LOCKUP_IRQ_HANDLER);
    NVIC_SetPendingIRQ(CM7_LOCKUP_IRQ_HANDLER);
#endif

#ifdef CM71_RESET_IRQ_HANDLER
    NVIC_EnableIRQ(CM71_RESET_IRQ_HANDLER);
    NVIC_SetPendingIRQ(CM71_RESET_IRQ_HANDLER);
#endif

#ifdef CM71_LOCKUP_IRQ_HANDLER
    NVIC_EnableIRQ(CM71_LOCKUP_IRQ_HANDLER);
    NVIC_SetPendingIRQ(CM71_LOCKUP_IRQ_HANDLER);
#endif

#ifdef CM33S_RESET_IRQ_HANDLER
    NVIC_EnableIRQ(CM33S_RESET_IRQ_HANDLER);
    NVIC_SetPendingIRQ(CM33S_RESET_IRQ_HANDLER);
#endif

#ifdef CM33S_LOCKUP_IRQ_HANDLER
    NVIC_EnableIRQ(CM33S_LOCKUP_IRQ_HANDLER);
    NVIC_SetPendingIRQ(CM33S_LOCKUP_IRQ_HANDLER);
#endif

#ifdef MU1_A_IRQ_HANDLER
    NVIC_EnableIRQ(MU1_A_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU1_A_IRQ_HANDLER);
#endif

#ifdef MU2_A_IRQ_HANDLER
    NVIC_EnableIRQ(MU2_A_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU2_A_IRQ_HANDLER);
#endif

#ifdef MU3_A_IRQ_HANDLER
    NVIC_EnableIRQ(MU3_A_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU3_A_IRQ_HANDLER);
#endif

#ifdef MU3_B_IRQ_HANDLER
    NVIC_EnableIRQ(MU3_B_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU3_B_IRQ_HANDLER);
#endif

#ifdef MU4_A_IRQ_HANDLER
    NVIC_EnableIRQ(MU4_A_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU4_A_IRQ_HANDLER);
#endif

#ifdef MU4_B_IRQ_HANDLER
    NVIC_EnableIRQ(MU4_B_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU4_B_IRQ_HANDLER);
#endif

#ifdef MU5_A_IRQ_HANDLER
    NVIC_EnableIRQ(MU5_A_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU5_A_IRQ_HANDLER);
#endif

#ifdef MU6_A_IRQ_HANDLER
    NVIC_EnableIRQ(MU6_A_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU6_A_IRQ_HANDLER);
#endif

#ifdef MU6_B_IRQ_HANDLER
    NVIC_EnableIRQ(MU6_B_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU6_B_IRQ_HANDLER);
#endif

#ifdef MU7_A_IRQ_HANDLER
    NVIC_EnableIRQ(MU7_A_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU7_A_IRQ_HANDLER);
#endif

#ifdef MU7_B_IRQ_HANDLER
    NVIC_EnableIRQ(MU7_B_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU7_B_IRQ_HANDLER);
#endif

#ifdef MU8_A_IRQ_HANDLER
    NVIC_EnableIRQ(MU8_A_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU8_A_IRQ_HANDLER);
#endif

#ifdef MU8_B_IRQ_HANDLER
    NVIC_EnableIRQ(MU8_B_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU8_B_IRQ_HANDLER);
#endif

#ifdef MU9_A_IRQ_HANDLER
    NVIC_EnableIRQ(MU9_A_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU9_A_IRQ_HANDLER);
#endif

#ifdef MU9_B_IRQ_HANDLER
    NVIC_EnableIRQ(MU9_B_IRQ_HANDLER);
    NVIC_SetPendingIRQ(MU9_B_IRQ_HANDLER);
#endif

#ifdef INC_LIBC
    uint64_t timeMsec = DEV_SM_GetTimerMsec();
    printf("TimeMsec_H: %u TimeMsec_L: %u\n",
        UINT64_H(timeMsec), UINT64_L(timeMsec));
#else
    (void) DEV_SM_GetTimerMsec();
#endif

#ifdef MU6_B_IRQ_HANDLER
    uint32_t basePrio = 0U;
    (void) DEV_SM_IrqPrioBaseGet(MU6_B_IRQ_HANDLER, &basePrio);

    uint32_t irqCntr = 0U;
    (void) DEV_SM_IrqPrioCntrGet(MU6_B_IRQ_HANDLER, &irqCntr);

    (void) DEV_SM_IrqPrioCntrSet(MU6_B_IRQ_HANDLER, irqCntr);
#endif
    basePrio = 1U << __NVIC_PRIO_BITS;
    (void) DEV_SM_IrqPrioBaseSet(MU6_B_IRQ_HANDLER, basePrio);
    (void) DEV_SM_IrqPrioBaseSet(NotAvail_IRQn, 0U);
    (void) DEV_SM_IrqPrioBaseGet(NotAvail_IRQn, &basePrio);
    (void) DEV_SM_IrqPrioCntrSet(NotAvail_IRQn, 0U);
    (void) DEV_SM_IrqPrioCntrGet(NotAvail_IRQn, &irqCntr);

    SM_TestModeSet(SM_TEST_MODE_OFF);
#endif
}

