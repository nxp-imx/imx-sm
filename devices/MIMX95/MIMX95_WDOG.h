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
**         CMSIS Peripheral Access Layer for MIMX95_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
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

/*!
 * @file MIMX95_WDOG.h
 * @version 1.0
 * @date 2021-11-16
 * @brief CMSIS Peripheral Access Layer for MIMX95_WDOG
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_WDOG_H_)  /* Check if memory map has not been already included */
#define MIMX95_WDOG_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */

/** WDOG - Register Layout Typedef */
typedef struct
{
    __IO uint32_t CS;    /**< Watchdog Control and Status Register, offset: 0x0 */
    __IO uint32_t CNT;   /**< Watchdog Counter Register, offset: 0x4 */
    __IO uint32_t TOVAL; /**< Watchdog Timeout Value Register, offset: 0x8 */
    __IO uint32_t WIN;   /**< Watchdog Window Register, offset: 0xC */
} WDOG_Type;

/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/*! @name CS - Watchdog Control and Status Register */
/*! @{ */

#define WDOG_CS_STOP_MASK  (0x1U)
#define WDOG_CS_STOP_SHIFT (0U)
/*! STOP - Stop Enable
 *  0b0..Watchdog disabled in chip stop mode.
 *  0b1..Watchdog enabled in chip stop mode.
 */
#define WDOG_CS_STOP(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_STOP_SHIFT)) & WDOG_CS_STOP_MASK)

#define WDOG_CS_WAIT_MASK  (0x2U)
#define WDOG_CS_WAIT_SHIFT (1U)
/*! WAIT - Wait Enable
 *  0b0..Watchdog disabled in chip wait mode.
 *  0b1..Watchdog enabled in chip wait mode.
 */
#define WDOG_CS_WAIT(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_WAIT_SHIFT)) & WDOG_CS_WAIT_MASK)

#define WDOG_CS_DBG_MASK  (0x4U)
#define WDOG_CS_DBG_SHIFT (2U)
/*! DBG - Debug Enable
 *  0b0..Watchdog disabled in chip debug mode.
 *  0b1..Watchdog enabled in chip debug mode.
 */
#define WDOG_CS_DBG(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_DBG_SHIFT)) & WDOG_CS_DBG_MASK)

#define WDOG_CS_TST_MASK  (0x18U)
#define WDOG_CS_TST_SHIFT (3U)
/*! TST - Watchdog Test
 *  0b00..Watchdog test mode disabled.
 *  0b01..Watchdog user mode enabled. (Watchdog test mode disabled.) After testing the watchdog, software should
 *        use this setting to indicate that the watchdog is functioning normally in user mode.
 *  0b10..Watchdog test mode enabled, only the low byte is used. CNT[CNTLOW] is compared with TOVAL[TOVALLOW].
 *  0b11..Watchdog test mode enabled, only the high byte is used. CNT[CNTHIGH] is compared with TOVAL[TOVALHIGH].
 */
#define WDOG_CS_TST(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_TST_SHIFT)) & WDOG_CS_TST_MASK)

#define WDOG_CS_UPDATE_MASK  (0x20U)
#define WDOG_CS_UPDATE_SHIFT (5U)
/*! UPDATE - Allow updates
 *  0b0..Updates not allowed. After the initial configuration, the watchdog cannot be later modified without forcing a
 * reset. 0b1..Updates allowed. Software can modify the watchdog configuration registers within 1024 bus clocks after
 * performing the unlock write sequence.
 */
#define WDOG_CS_UPDATE(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_UPDATE_SHIFT)) & WDOG_CS_UPDATE_MASK)

#define WDOG_CS_INT_MASK  (0x40U)
#define WDOG_CS_INT_SHIFT (6U)
/*! INT - Watchdog Interrupt
 *  0b0..Watchdog interrupts are disabled. Watchdog resets are not delayed.
 *  0b1..Watchdog interrupts are enabled. Watchdog resets are delayed by 128 bus clocks from the interrupt vector fetch.
 */
#define WDOG_CS_INT(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_INT_SHIFT)) & WDOG_CS_INT_MASK)

#define WDOG_CS_EN_MASK  (0x80U)
#define WDOG_CS_EN_SHIFT (7U)
/*! EN - Watchdog Enable
 *  0b0..Watchdog disabled.
 *  0b1..Watchdog enabled.
 */
#define WDOG_CS_EN(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_EN_SHIFT)) & WDOG_CS_EN_MASK)

#define WDOG_CS_CLK_MASK  (0x300U)
#define WDOG_CS_CLK_SHIFT (8U)
/*! CLK - Watchdog Clock
 */
#define WDOG_CS_CLK(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_CLK_SHIFT)) & WDOG_CS_CLK_MASK)

#define WDOG_CS_RCS_MASK  (0x400U)
#define WDOG_CS_RCS_SHIFT (10U)
/*! RCS - Reconfiguration Success
 *  0b0..Reconfiguring WDOG.
 *  0b1..Reconfiguration is successful.
 */
#define WDOG_CS_RCS(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_RCS_SHIFT)) & WDOG_CS_RCS_MASK)

#define WDOG_CS_ULK_MASK  (0x800U)
#define WDOG_CS_ULK_SHIFT (11U)
/*! ULK - Unlock status
 *  0b0..WDOG is locked.
 *  0b1..WDOG is unlocked.
 */
#define WDOG_CS_ULK(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_ULK_SHIFT)) & WDOG_CS_ULK_MASK)

#define WDOG_CS_PRES_MASK  (0x1000U)
#define WDOG_CS_PRES_SHIFT (12U)
/*! PRES - Watchdog prescaler
 *  0b0..256 prescaler disabled.
 *  0b1..256 prescaler enabled.
 */
#define WDOG_CS_PRES(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_PRES_SHIFT)) & WDOG_CS_PRES_MASK)

#define WDOG_CS_CMD32EN_MASK  (0x2000U)
#define WDOG_CS_CMD32EN_SHIFT (13U)
/*! CMD32EN - Enables or disables WDOG support for 32-bit (otherwise 16-bit or 8-bit) refresh/unlock command write words
 *  0b0..Disables support for 32-bit refresh/unlock command write words. Only 16-bit or 8-bit is supported.
 *  0b1..Enables support for 32-bit refresh/unlock command write words. 16-bit or 8-bit is NOT supported.
 */
#define WDOG_CS_CMD32EN(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_CMD32EN_SHIFT)) & WDOG_CS_CMD32EN_MASK)

#define WDOG_CS_FLG_MASK  (0x4000U)
#define WDOG_CS_FLG_SHIFT (14U)
/*! FLG - Watchdog Interrupt Flag
 *  0b0..No interrupt occurred.
 *  0b1..An interrupt occurred.
 */
#define WDOG_CS_FLG(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_FLG_SHIFT)) & WDOG_CS_FLG_MASK)

#define WDOG_CS_WIN_MASK  (0x8000U)
#define WDOG_CS_WIN_SHIFT (15U)
/*! WIN - Watchdog Window
 *  0b0..Window mode disabled.
 *  0b1..Window mode enabled.
 */
#define WDOG_CS_WIN(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CS_WIN_SHIFT)) & WDOG_CS_WIN_MASK)
/*! @} */

/*! @name CNT - Watchdog Counter Register */
/*! @{ */

#define WDOG_CNT_CNTLOW_MASK  (0xFFU)
#define WDOG_CNT_CNTLOW_SHIFT (0U)
/*! CNTLOW - Low byte of the Watchdog Counter
 */
#define WDOG_CNT_CNTLOW(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CNT_CNTLOW_SHIFT)) & WDOG_CNT_CNTLOW_MASK)

#define WDOG_CNT_CNTHIGH_MASK  (0xFF00U)
#define WDOG_CNT_CNTHIGH_SHIFT (8U)
/*! CNTHIGH - High byte of the Watchdog Counter
 */
#define WDOG_CNT_CNTHIGH(x) (((uint32_t)(((uint32_t)(x)) << WDOG_CNT_CNTHIGH_SHIFT)) & WDOG_CNT_CNTHIGH_MASK)
/*! @} */

/*! @name TOVAL - Watchdog Timeout Value Register */
/*! @{ */

#define WDOG_TOVAL_TOVALLOW_MASK  (0xFFU)
#define WDOG_TOVAL_TOVALLOW_SHIFT (0U)
/*! TOVALLOW - Low byte of the timeout value
 */
#define WDOG_TOVAL_TOVALLOW(x) (((uint32_t)(((uint32_t)(x)) << WDOG_TOVAL_TOVALLOW_SHIFT)) & WDOG_TOVAL_TOVALLOW_MASK)

#define WDOG_TOVAL_TOVALHIGH_MASK  (0xFF00U)
#define WDOG_TOVAL_TOVALHIGH_SHIFT (8U)
/*! TOVALHIGH - High byte of the timeout value
 */
#define WDOG_TOVAL_TOVALHIGH(x) \
    (((uint32_t)(((uint32_t)(x)) << WDOG_TOVAL_TOVALHIGH_SHIFT)) & WDOG_TOVAL_TOVALHIGH_MASK)
/*! @} */

/*! @name WIN - Watchdog Window Register */
/*! @{ */

#define WDOG_WIN_WINLOW_MASK  (0xFFU)
#define WDOG_WIN_WINLOW_SHIFT (0U)
/*! WINLOW - Low byte of Watchdog Window
 */
#define WDOG_WIN_WINLOW(x) (((uint32_t)(((uint32_t)(x)) << WDOG_WIN_WINLOW_SHIFT)) & WDOG_WIN_WINLOW_MASK)

#define WDOG_WIN_WINHIGH_MASK  (0xFF00U)
#define WDOG_WIN_WINHIGH_SHIFT (8U)
/*! WINHIGH - High byte of Watchdog Window
 */
#define WDOG_WIN_WINHIGH(x) (((uint32_t)(((uint32_t)(x)) << WDOG_WIN_WINHIGH_SHIFT)) & WDOG_WIN_WINHIGH_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group WDOG_Register_Masks */

/* WDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** Peripheral WDOG1 base address */
#define WDOG1_BASE (0x542D0000u)
/** Peripheral WDOG1 base address */
#define WDOG1_BASE_NS (0x442D0000u)
/** Peripheral WDOG1 base pointer */
#define WDOG1 ((WDOG_Type *)WDOG1_BASE)
/** Peripheral WDOG1 base pointer */
#define WDOG1_NS ((WDOG_Type *)WDOG1_BASE_NS)
/** Peripheral WDOG2 base address */
#define WDOG2_BASE (0x542E0000u)
/** Peripheral WDOG2 base address */
#define WDOG2_BASE_NS (0x442E0000u)
/** Peripheral WDOG2 base pointer */
#define WDOG2 ((WDOG_Type *)WDOG2_BASE)
/** Peripheral WDOG2 base pointer */
#define WDOG2_NS ((WDOG_Type *)WDOG2_BASE_NS)
/** Peripheral WDOG3 base address */
#define WDOG3_BASE (0x52490000u)
/** Peripheral WDOG3 base address */
#define WDOG3_BASE_NS (0x42490000u)
/** Peripheral WDOG3 base pointer */
#define WDOG3 ((WDOG_Type *)WDOG3_BASE)
/** Peripheral WDOG3 base pointer */
#define WDOG3_NS ((WDOG_Type *)WDOG3_BASE_NS)
/** Peripheral WDOG4 base address */
#define WDOG4_BASE (0x524A0000u)
/** Peripheral WDOG4 base address */
#define WDOG4_BASE_NS (0x424A0000u)
/** Peripheral WDOG4 base pointer */
#define WDOG4 ((WDOG_Type *)WDOG4_BASE)
/** Peripheral WDOG4 base pointer */
#define WDOG4_NS ((WDOG_Type *)WDOG4_BASE_NS)
/** Peripheral WDOG5 base address */
#define WDOG5_BASE (0x524B0000u)
/** Peripheral WDOG5 base address */
#define WDOG5_BASE_NS (0x424B0000u)
/** Peripheral WDOG5 base pointer */
#define WDOG5 ((WDOG_Type *)WDOG5_BASE)
/** Peripheral WDOG5 base pointer */
#define WDOG5_NS ((WDOG_Type *)WDOG5_BASE_NS)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                                            \
    {                                                              \
        WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE \
    }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                    \
    {                                     \
        WDOG1, WDOG2, WDOG3, WDOG4, WDOG5 \
    }
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS_NS                                                        \
    {                                                                             \
        WDOG1_BASE_NS, WDOG2_BASE_NS, WDOG3_BASE_NS, WDOG4_BASE_NS, WDOG5_BASE_NS \
    }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS_NS                                \
    {                                                    \
        WDOG1_NS, WDOG2_NS, WDOG3_NS, WDOG4_NS, WDOG5_NS \
    }
#else
/** Peripheral WDOG1 base address */
#define WDOG1_BASE (0x442D0000u)
/** Peripheral WDOG1 base pointer */
#define WDOG1      ((WDOG_Type *)WDOG1_BASE)
/** Peripheral WDOG2 base address */
#define WDOG2_BASE (0x442E0000u)
/** Peripheral WDOG2 base pointer */
#define WDOG2      ((WDOG_Type *)WDOG2_BASE)
/** Peripheral WDOG3 base address */
#define WDOG3_BASE (0x42490000u)
/** Peripheral WDOG3 base pointer */
#define WDOG3      ((WDOG_Type *)WDOG3_BASE)
/** Peripheral WDOG4 base address */
#define WDOG4_BASE (0x424A0000u)
/** Peripheral WDOG4 base pointer */
#define WDOG4      ((WDOG_Type *)WDOG4_BASE)
/** Peripheral WDOG5 base address */
#define WDOG5_BASE (0x424B0000u)
/** Peripheral WDOG5 base pointer */
#define WDOG5      ((WDOG_Type *)WDOG5_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                                            \
    {                                                              \
        WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE \
    }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                    \
    {                                     \
        WDOG1, WDOG2, WDOG3, WDOG4, WDOG5 \
    }
#endif
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                                  \
    {                                                              \
        WDOG1_IRQn, WDOG2_IRQn, WDOG3_IRQn, WDOG4_IRQn, WDOG5_IRQn \
    }
/* Extra definition */
#define WDOG_UPDATE_KEY  (0xD928C520U)
#define WDOG_REFRESH_KEY (0xB480A602U)

/*!
 * @}
 */ /* end of group WDOG_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_WDOG_H_) */
