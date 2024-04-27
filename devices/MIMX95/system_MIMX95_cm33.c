/*
** ###################################################################
**     Processors:          MIMX95_cm33
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX95RM, Internal, November. 2021
**     Version:             rev. 1.0, 2021-11-16
**     Build:               b220818
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-11-16)
**         Initial version.
**
** ###################################################################
*/

#include "system_MIMX95_cm33.h"
#include "fsl_reset.h"
#include "fsl_systick.h"
#include "board.h"

/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */
uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

void SystemInit(void)
{
    /* Enable memory management, bus, and usage faults */
    SCB->SHCSR |= (SCB_SHCSR_USGFAULTENA_Msk | SCB_SHCSR_BUSFAULTENA_Msk
        | SCB_SHCSR_MEMFAULTENA_Msk);

    /* Enable unaligned access and divide by 0 faults */
    SCB->CCR |= (SCB_CCR_UNALIGN_TRP_Msk | SCB_CCR_DIV_0_TRP_Msk);

    /* Configure priority grouping */
    NVIC_SetPriorityGrouping(IRQ_PRIGROUP);

    /* GCC may utilize FPU registers if GP register pressure is high.  FPU must
     * be enabled before FPU instructions or FPU register usage.
     *
     * Note:  As of v8.1 CP8, 9, 14 and 15 are also controlled by CP10 enables.
     */
    uint32_t cpacr = SCB->CPACR;

    /* Set bits 20-23 of CPACR to enable FPU coprocessors (CP10 and CP11) */
    SCB->CPACR = cpacr | (0xFUL << 20U);
    __DSB();
    __ISB();

    /* Disable NMI generation for sources assigned to other CPUs */
    BLK_CTRL_S_AONMIX->NMI_MASK |= (BLK_CTRL_S_AONMIX_NMI_MASK_CM7_MASK |
                                    BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_MASK |
                                    BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_MASK |
                                    BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_MASK);

    /* Disable all SRC boot reset holds */
    SRC_GEN->SCR = 0xFFFFFFFFU;

    /* Mask reset sources handled by SM */
    SRC_GEN->SRMASK = (1UL << RST_REASON_CM7_LOCKUP) | 
                      (1UL << RST_REASON_CM7_SWREQ) |
                      (1UL << RST_REASON_SENTINEL) |
                      (1UL << RST_REASON_WDOG3) |
                      (1UL << RST_REASON_WDOG4) |
                      (1UL << RST_REASON_WDOG5);

    // coverity[misra_c_2012_rule_2_2_violation:FALSE]
    SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

// coverity[misra_c_2012_rule_1_2_violation:FALSE]
__attribute__((weak)) void SystemInitHook(void)
{
    /* Void implementation of the weak function. */
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate(void)
{
}

/* ----------------------------------------------------------------------------
   -- SystemExit()
   ---------------------------------------------------------------------------- */

void SystemExit(void)
{
#ifdef BUILD_EMU
    *(volatile uint32_t *)(SYSTEM_EMU_KILL_ADDR) = SYSTEM_EMU_KILL_EVENT;
#endif
}

/* ----------------------------------------------------------------------------
   -- SystemDebugWaitAttach()
   ---------------------------------------------------------------------------- */
void SystemDebugWaitAttach(void)
{
    while ((CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk) == 0U)
    {
        /* Kick the dog */
        BOARD_WdogRefresh();
    }

    // coverity[misra_c_2012_rule_1_2_violation:FALSE]
    __BKPT(0);
}

/* ----------------------------------------------------------------------------
   -- SystemTimeDelay(usec)
   ---------------------------------------------------------------------------- */
void SystemTimeDelay(uint32_t usec)
{
    SYSTICK_TimeDelay(usec);
}

/* ----------------------------------------------------------------------------
   -- SystemMemoryProbe(addr, val, width)
   ---------------------------------------------------------------------------- */
uint32_t SystemMemoryProbe(const void *addr, void *val, uint8_t width)
{
    uint32_t fault = 0U;

    // Save current CCR (Configuration Control Register)
    uint32_t ccr = SCB->CCR;

    // Ignore bus faults during all exceptions
    SCB->CCR = ccr | SCB_CCR_BFHFNMIGN_Msk;

    // Store current FAULTMASK
    uint32_t mask = __get_FAULTMASK();

    // Prevent activation of all exceptions except NMI (FAULTMASK = 1)
    __disable_fault_irq();

    // Perform the probe
    switch(width)
    {
        case 8:
            *((uint8_t *) val) = *((const uint8_t *) addr);
            break;

        case 16:
            *((uint16_t *) val) = *((const uint16_t *) addr);
            break;

        case 32:
            *((uint32_t *) val) = *((const uint32_t *) addr);
            break;

        default :
            ; /* Intentional empty default */
            break;
    }

    // Check for bus faults
    uint32_t cfsr = SCB->CFSR;
    if ((cfsr & SCB_CFSR_BFARVALID_Msk) != 0U)
    {
        // Return fault status register
        fault = cfsr;

        // Clear the fault (W1C)
        SCB->CFSR = cfsr | SCB_CFSR_BFARVALID_Msk;
    }

    // Enable bus faults
    SCB->CCR = ccr;

    // Restore previous FAULTMASK
    __set_FAULTMASK(mask);

    return fault;
}

