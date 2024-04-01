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

#ifndef SYSTEM_MIMX95_cm33_H
#define SYSTEM_MIMX95_cm33_H /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "fsl_device_registers.h"

#define DEFAULT_SYSTEM_CLOCK 200000000u

/* EMU event port definitions */
#define SYSTEM_EMU_KILL_ADDR    0x3001FFE0U
#define SYSTEM_EMU_KILL_EVENT   0x000000AAU
#define SYSTEM_EMU_QIWC_ADDR    0x204D7F00U
#define SYSTEM_EMU_QIWC_START   0x000000C1U
#define SYSTEM_EMU_QIWC_STOP    0x000000C2U

/* IRQ Priority grouping (PRIGROUP) configured as follows:
 *      1-bit group priority field
 *      3-bit subgroup priority field
 *
 *      Note:  actual bits of priority fields are MSB of fields as defined
 *             by __NVIC_PRIO_BITS
 */
#define IRQ_PRIGROUP                      6U

/* IRQ handler priorities */
#define IRQ_PRIO_PREEMPT_CRITICAL         0U    /* Critical preemptive */
#define IRQ_PRIO_PREEMPT_VERY_HIGH        1U    /* Very high preemptive */
#define IRQ_PRIO_PREEMPT_HIGH             2U    /* High preemptive */
#define IRQ_PRIO_PREEMPT_ABOVE_NORMAL     3U    /* Above normal preemptive */
#define IRQ_PRIO_PREEMPT_NORMAL           4U    /* Normal preemptive */
#define IRQ_PRIO_PREEMPT_BELOW_NORMAL     5U    /* Below normal preemptive */
#define IRQ_PRIO_PREEMPT_LOW              6U    /* Low preemptive */
#define IRQ_PRIO_PREEMPT_VERY_LOW         7U    /* Very low preemptive */

#define IRQ_PRIO_NOPREEMPT_CRITICAL       8U    /* Critical nonpreemptive */
#define IRQ_PRIO_NOPREEMPT_VERY_HIGH      9U    /* Very high nonpreemptive */
#define IRQ_PRIO_NOPREEMPT_HIGH           10U   /* High nonpreemptive */
#define IRQ_PRIO_NOPREEMPT_ABOVE_NORMAL   11U   /* Above normal nonpreemptive */
#define IRQ_PRIO_NOPREEMPT_NORMAL         12U   /* Normal nonpreemptive */
#define IRQ_PRIO_NOPREEMPT_BELOW_NORMAL   13U   /* Below normal nonpreemptive */
#define IRQ_PRIO_NOPREEMPT_LOW            14U   /* Low nonpreemptive */
#define IRQ_PRIO_NOPREEMPT_VERY_LOW       15U   /* Very low nonpreemptive */

/**
 * @brief System clock frequency (core clock)
 *
 * The system clock frequency supplied to the SysTick timer and the processor
 * core clock. This variable can be used by the user application to setup the
 * SysTick timer or configure other parameters. It may also be used by debugger to
 * query the frequency of the debug timer or configure the trace clock speed
 * SystemCoreClock is initialized with a correct predefined value.
 */
extern uint32_t SystemCoreClock;

/**
 * @brief Setup the microcontroller system.
 *
 * Typically this function configures the oscillator (PLL) that is part of the
 * microcontroller device. For systems with variable clock speed it also updates
 * the variable SystemCoreClock. SystemInit is called from startup_device file.
 */
void SystemInit(void);

/**
 * @brief SystemInit function hook.
 *
 * This weak function allows to call specific initialization code during the
 * SystemInit() execution.This can be used when an application specific code needs
 * to be called as close to the reset entry as possible (for example the Multicore
 * Manager MCMGR_EarlyInit() function call).
 * NOTE: No global r/w variables can be used in this hook function because the
 * initialization of these variables happens after this function.
 */
void SystemInitHook(void);

/**
 * @brief Updates the SystemCoreClock variable.
 *
 * It must be called whenever the core clock is changed during program
 * execution. SystemCoreClockUpdate() evaluates the clock register settings and calculates
 * the current core clock.
 */
void SystemCoreClockUpdate(void);

/**
 * @brief Tear down of the microcontroller system.
 *
 * Typically this function will terminate the session for simulator execution or
 * raise a fault.
 */
void SystemExit(void);

/**
 * @brief SystemDebugWaitAttach
 *
 * Function to spin with WDOG servicing to allow debug attach.
 */
void SystemDebugWaitAttach(void);

/**
 * @brief SystemTimeDelay
 *
 * Delays the specified number of usec.
 */
void SystemTimeDelay(uint32_t usec);

/**
 * @brief SystemMemoryProbe
 *
 * Probe memory and catch bus faults.
 */
uint32_t SystemMemoryProbe(const void *addr, void *val, uint8_t width);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_MIMX95_cm33_H */

