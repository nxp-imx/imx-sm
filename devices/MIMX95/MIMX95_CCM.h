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
 * @file MIMX95_CCM.h
 * @version 1.0
 * @date 2021-11-16
 * @brief CMSIS Peripheral Access Layer for MIMX95_CCM
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_CCM_H_)  /* Check if memory map has not been already included */
#define MIMX95_CCM_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Peripheral_Access_Layer CCM Peripheral Access Layer
 * @{
 */

/** CCM - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x80 */
    struct {                                         /* offset: 0x0 */
      __IO uint32_t RW;                                /**< Clock Root Control Register, offset: 0x0 */
      __IO uint32_t SET;                               /**< Clock Root Control Register, offset: 0x4 */
      __IO uint32_t CLR;                               /**< Clock Root Control Register, offset: 0x8 */
      __IO uint32_t TOG;                               /**< Clock Root Control Register, offset: 0xC */
    } CLOCK_ROOT_CONTROL;
         uint8_t RESERVED_0[16];
    __I  uint32_t STATUS0;                           /**< Clock root working status, array offset: 0x20, array step: 0x80 */
         uint8_t RESERVED_1[12];
    __IO uint32_t AUTHEN;                            /**< Clock root access control, array offset: 0x30, array step: 0x80 */
         uint8_t RESERVED_2[76];
  } CLOCK_ROOT[123];
  uint8_t RESERVED_0[2688];
  struct
  { /* offset: 0x4800, array step: 0x20 */
     struct
     {                 /* offset: 0x4800 */
         uint32_t RW;  /**< General Purpose Register, offset: 0x4800 */
         uint32_t SET; /**< General Purpose Register, offset: 0x4804 */
         uint32_t CLR; /**< General Purpose Register, offset: 0x4808 */
         uint32_t TOG; /**< General Purpose Register, offset: 0x480C */
     } GPR_SHARED;
     struct
     {                      /* offset: 0x4810 */
         __IO uint32_t RW;  /**< GPR access control, offset: 0x4810 */
         __IO uint32_t SET; /**< GPR access control, offset: 0x4814 */
         __IO uint32_t CLR; /**< GPR access control, offset: 0x4818 */
         __IO uint32_t TOG; /**< GPR access control, offset: 0x481C */
     } GPR_SHARED_AUTHEN;
  } GPR_SHARED[8];
  uint8_t RESERVED_1[768];
  struct {                                         /* offset: 0x4C00, array step: 0x20 */
    struct {                                         /* offset: 0x4C00 */
      __IO uint32_t RW;                                /**< General purpose register, offset: 0x4C00 */
      __IO uint32_t SET;                               /**< General purpose register, offset: 0x4C04 */
      __IO uint32_t CLR;                               /**< General purpose register, offset: 0x4C08 */
      __IO uint32_t TOG;                               /**< General purpose register, offset: 0x4C0C */
    } GPR_PRIVATE;
    struct {                                         /* offset: 0x4C10 */
      __IO uint32_t RW;                                /**< GPR access control, offset: 0x4C10 */
      __IO uint32_t SET;                               /**< GPR access control, offset: 0x4C14 */
      __IO uint32_t CLR;                               /**< GPR access control, offset: 0x4C18 */
      __IO uint32_t TOG;                               /**< GPR access control, offset: 0x4C1C */
    } GPR_PRIVATE_AUTHEN;
  } GPR_PRIVATE[16];
       uint8_t RESERVED_2[512];
  struct {                                         /* offset: 0x5000, array step: 0x40 */
    __IO uint32_t DIRECT;                            /**< Clock source direct control, array offset: 0x5000, array step: 0x40 */
    __I  uint32_t LPM_STATUS0;                       /**< Low power mode information transfer status, array offset: 0x5004, array step: 0x40 */
    __I  uint32_t LPM_STATUS1;                       /**< Low power mode information transfer status, array offset: 0x5008, array step: 0x40 */
         uint8_t RESERVED_0[4];
    __IO uint32_t LPM0;                              /**< Clock source low power mode setting, array offset: 0x5010, array step: 0x40 */
    __IO uint32_t LPM1;                              /**< clock source low power mode setting, array offset: 0x5014, array step: 0x40 */
         uint8_t RESERVED_1[4];
    __I  uint32_t LPM_CUR;                           /**< LPM setting of current CPU domain, array offset: 0x501C, array step: 0x40 */
    __I  uint32_t STATUS0;                           /**< Clock source working status, array offset: 0x5020, array step: 0x40 */
    __I  uint32_t STATUS1;                           /**< Clock source domain status, array offset: 0x5024, array step: 0x40 */
         uint8_t RESERVED_2[8];
    __IO uint32_t AUTHEN;                            /**< Clock Source access control, array offset: 0x5030, array step: 0x40 */
         uint8_t RESERVED_3[12];
  } OSCPLL[39];
       uint8_t RESERVED_3[9792];
  struct {                                         /* offset: 0x8000, array step: 0x40 */
    __IO uint32_t DIRECT;                            /**< LPCG direct control, array offset: 0x8000, array step: 0x40 */
    __I  uint32_t LPM_STATUS0;                       /**< Low power mode information transfer status, array offset: 0x8004, array step: 0x40 */
    __I  uint32_t LPM_STATUS1;                       /**< Low power mode information transfer status, array offset: 0x8008, array step: 0x40 */
         uint8_t RESERVED_0[4];
    __IO uint32_t LPM0;                              /**< LPCG low power mode setting, array offset: 0x8010, array step: 0x40 */
    __IO uint32_t LPM1;                              /**< LPCG low power mode setting, array offset: 0x8014, array step: 0x40 */
         uint8_t RESERVED_1[4];
    __IO uint32_t LPM_CUR;                           /**< LPM setting of current CPU domain, array offset: 0x801C, array step: 0x40 */
    __I  uint32_t STATUS0;                           /**< LPCG working status, array offset: 0x8020, array step: 0x40 */
    __I  uint32_t STATUS1;                           /**< LPCG domain status, array offset: 0x8024, array step: 0x40 */
         uint8_t RESERVED_2[8];
    __IO uint32_t AUTHEN;                            /**< LPCG access control, array offset: 0x8030, array step: 0x40 */
         uint8_t RESERVED_3[12];
  } LPCG[256];
} CCM_Type;

/* ----------------------------------------------------------------------------
   -- CCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Register_Masks CCM Register Masks
 * @{
 */

/*! @name CLOCK_ROOT - Clock Root Control Register */
/*! @{ */

#define CCM_CLOCK_ROOT_DIV_MASK                  (0xFFU)
#define CCM_CLOCK_ROOT_DIV_SHIFT                 (0U)
/*! DIV - Clock division fraction. */
#define CCM_CLOCK_ROOT_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_DIV_SHIFT)) & CCM_CLOCK_ROOT_DIV_MASK)

#define CCM_CLOCK_ROOT_MUX_MASK                  (0x300U)
#define CCM_CLOCK_ROOT_MUX_SHIFT                 (8U)
/*! MUX - Clock multiplexer.
 *  0b10..Select clock source 2
 *  0b00..Select clock source 0
 *  0b01..Select clock source 1
 *  0b11..Select clock source 3
 */
#define CCM_CLOCK_ROOT_MUX(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_MUX_SHIFT)) & CCM_CLOCK_ROOT_MUX_MASK)

#define CCM_CLOCK_ROOT_OFF_MASK                  (0x1000000U)
#define CCM_CLOCK_ROOT_OFF_SHIFT                 (24U)
/*! OFF - Shutdown clock root.
 *  0b0..Clock is running.
 *  0b1..Turn off clock.
 */
#define CCM_CLOCK_ROOT_OFF(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_OFF_SHIFT)) & CCM_CLOCK_ROOT_OFF_MASK)
/*! @} */

/*! @name CLOCK_ROOT_STATUS0 - Clock root working status */
/*! @{ */

#define CCM_CLOCK_ROOT_STATUS0_DIV_MASK          (0xFFU)
#define CCM_CLOCK_ROOT_STATUS0_DIV_SHIFT         (0U)
/*! DIV - Current clock root DIV setting */
#define CCM_CLOCK_ROOT_STATUS0_DIV(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_DIV_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_DIV_MASK)

#define CCM_CLOCK_ROOT_STATUS0_MUX_MASK          (0x300U)
#define CCM_CLOCK_ROOT_STATUS0_MUX_SHIFT         (8U)
/*! MUX - Current clock root MUX setting */
#define CCM_CLOCK_ROOT_STATUS0_MUX(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_MUX_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_MUX_MASK)

#define CCM_CLOCK_ROOT_STATUS0_OFF_MASK          (0x1000000U)
#define CCM_CLOCK_ROOT_STATUS0_OFF_SHIFT         (24U)
/*! OFF - Current clock root OFF setting
 *  0b0..Clock is running.
 *  0b1..Turn off clock.
 */
#define CCM_CLOCK_ROOT_STATUS0_OFF(x)            (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_OFF_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_OFF_MASK)

#define CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_MASK   (0x10000000U)
#define CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_SHIFT  (28U)
/*! SLICE_BUSY - Indication for clock generation logic is applying new setting.
 *  0b0..Clock generation logic is not busy.
 *  0b1..Clock generation logic is applying new setting.
 */
#define CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY(x)     (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_SLICE_BUSY_MASK)

#define CCM_CLOCK_ROOT_STATUS0_UPDATE_FORWARD_MASK (0x20000000U)
#define CCM_CLOCK_ROOT_STATUS0_UPDATE_FORWARD_SHIFT (29U)
/*! UPDATE_FORWARD - Update forward */
#define CCM_CLOCK_ROOT_STATUS0_UPDATE_FORWARD(x) (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_UPDATE_FORWARD_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_UPDATE_FORWARD_MASK)

#define CCM_CLOCK_ROOT_STATUS0_UPDATE_REVERSE_MASK (0x40000000U)
#define CCM_CLOCK_ROOT_STATUS0_UPDATE_REVERSE_SHIFT (30U)
/*! UPDATE_REVERSE - Update reverse */
#define CCM_CLOCK_ROOT_STATUS0_UPDATE_REVERSE(x) (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_UPDATE_REVERSE_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_UPDATE_REVERSE_MASK)

#define CCM_CLOCK_ROOT_STATUS0_CHANGING_MASK     (0x80000000U)
#define CCM_CLOCK_ROOT_STATUS0_CHANGING_SHIFT    (31U)
/*! CHANGING - Changing */
#define CCM_CLOCK_ROOT_STATUS0_CHANGING(x)       (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_STATUS0_CHANGING_SHIFT)) & CCM_CLOCK_ROOT_STATUS0_CHANGING_MASK)
/*! @} */

/* The count of CCM_CLOCK_ROOT_STATUS0 */
#define CCM_CLOCK_ROOT_STATUS0_COUNT             (128U)

/*! @name CLOCK_ROOT_AUTHEN - Clock root access control */
/*! @{ */

#define CCM_CLOCK_ROOT_AUTHEN_TZ_USER_MASK       (0x100U)
#define CCM_CLOCK_ROOT_AUTHEN_TZ_USER_SHIFT      (8U)
/*! TZ_USER - User access permission
 *  0b1..Clock Root settings can be changed in user mode.
 *  0b0..Clock Root settings cannot be changed in user mode.
 */
#define CCM_CLOCK_ROOT_AUTHEN_TZ_USER(x)         (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_AUTHEN_TZ_USER_SHIFT)) & CCM_CLOCK_ROOT_AUTHEN_TZ_USER_MASK)

#define CCM_CLOCK_ROOT_AUTHEN_TZ_NS_MASK         (0x200U)
#define CCM_CLOCK_ROOT_AUTHEN_TZ_NS_SHIFT        (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_CLOCK_ROOT_AUTHEN_TZ_NS(x)           (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_AUTHEN_TZ_NS_SHIFT)) & CCM_CLOCK_ROOT_AUTHEN_TZ_NS_MASK)

#define CCM_CLOCK_ROOT_AUTHEN_LOCK_TZ_MASK       (0x800U)
#define CCM_CLOCK_ROOT_AUTHEN_LOCK_TZ_SHIFT      (11U)
/*! LOCK_TZ - Lock Trustzone settings
 *  0b0..Trustzone settings is not locked.
 *  0b1..Trustzone settings is locked.
 */
#define CCM_CLOCK_ROOT_AUTHEN_LOCK_TZ(x)         (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_AUTHEN_LOCK_TZ_SHIFT)) & CCM_CLOCK_ROOT_AUTHEN_LOCK_TZ_MASK)

#define CCM_CLOCK_ROOT_AUTHEN_LOCK_LIST_MASK     (0x8000U)
#define CCM_CLOCK_ROOT_AUTHEN_LOCK_LIST_SHIFT    (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..White list is not locked.
 *  0b1..White list is locked.
 */
#define CCM_CLOCK_ROOT_AUTHEN_LOCK_LIST(x)       (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_AUTHEN_LOCK_LIST_SHIFT)) & CCM_CLOCK_ROOT_AUTHEN_LOCK_LIST_MASK)

#define CCM_CLOCK_ROOT_AUTHEN_WHITE_LIST_MASK    (0xFFFF0000U)
#define CCM_CLOCK_ROOT_AUTHEN_WHITE_LIST_SHIFT   (16U)
/*! WHITE_LIST - White list settings */
#define CCM_CLOCK_ROOT_AUTHEN_WHITE_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_CLOCK_ROOT_AUTHEN_WHITE_LIST_SHIFT)) & CCM_CLOCK_ROOT_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_CLOCK_ROOT_AUTHEN */
#define CCM_CLOCK_ROOT_AUTHEN_COUNT              (123U)

/*! @name GPR_SHARED0_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED0_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED0_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 */
#define CCM_GPR_SHARED0_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED0_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED0_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED0_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock Trustzone settings
 *  0b0..Trustzone settings is not locked.
 *  0b1..Trustzone settings is locked.
 */
#define CCM_GPR_SHARED0_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..White list is not locked.
 *  0b1..White list is locked.
 */
#define CCM_GPR_SHARED0_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - White list settings */
#define CCM_GPR_SHARED0_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED0_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED1 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED1_CA55_CORE0_CLOCK_SELECT_MASK (0x1U)
#define CCM_GPR_SHARED1_CA55_CORE0_CLOCK_SELECT_SHIFT (0U)
/*! CA55_CLOCK_SELECT - Clock select signal between ccm clock root and ARM PLL clock
 *  0b0..Clkroot_arm_a55 is used.
 *  0b1..The clock output of ARM PLL is selected.
 */
#define CCM_GPR_SHARED1_CA55_CORE0_CLOCK_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_CA55_CORE0_CLOCK_SELECT_SHIFT)) & CCM_GPR_SHARED1_CA55_CORE0_CLOCK_SELECT_MASK)

#define CCM_GPR_SHARED1_CA55_CORE1_CLOCK_SELECT_MASK (0x2U)
#define CCM_GPR_SHARED1_CA55_CORE1_CLOCK_SELECT_SHIFT (1U)
/*! CA55_CORE1_CLOCK_SELECT - Clock select signal between ccm clock root and ARM PLL clock
 *  0b0..arm_a55_clk_root is used.
 *  0b1..The clock output of ARM PLL is selected.
 */
#define CCM_GPR_SHARED1_CA55_CORE1_CLOCK_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_CA55_CORE1_CLOCK_SELECT_SHIFT)) & CCM_GPR_SHARED1_CA55_CORE1_CLOCK_SELECT_MASK)

#define CCM_GPR_SHARED1_CA55_CORE2_CLOCK_SELECT_MASK (0x4U)
#define CCM_GPR_SHARED1_CA55_CORE2_CLOCK_SELECT_SHIFT (2U)
/*! CA55_CORE2_CLOCK_SELECT - Clock select signal between ccm clock root and ARM PLL clock
 *  0b0..arm_a55_clk_root is used.
 *  0b1..The clock output of ARM PLL is selected.
 */
#define CCM_GPR_SHARED1_CA55_CORE2_CLOCK_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_CA55_CORE2_CLOCK_SELECT_SHIFT)) & CCM_GPR_SHARED1_CA55_CORE2_CLOCK_SELECT_MASK)

#define CCM_GPR_SHARED1_CA55_CORE3_CLOCK_SELECT_MASK (0x8U)
#define CCM_GPR_SHARED1_CA55_CORE3_CLOCK_SELECT_SHIFT (3U)
/*! CA55_CORE3_CLOCK_SELECT - Clock select signal between ccm clock root and ARM PLL clock
 *  0b0..arm_a55_clk_root is used.
 *  0b1..The clock output of ARM PLL is selected.
 */
#define CCM_GPR_SHARED1_CA55_CORE3_CLOCK_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_CA55_CORE3_CLOCK_SELECT_SHIFT)) & CCM_GPR_SHARED1_CA55_CORE3_CLOCK_SELECT_MASK)

#define CCM_GPR_SHARED1_CA55_CORE4_CLOCK_SELECT_MASK (0x10U)
#define CCM_GPR_SHARED1_CA55_CORE4_CLOCK_SELECT_SHIFT (4U)
/*! CA55_CORE4_CLOCK_SELECT - Clock select signal between ccm clock root and ARM PLL clock
 *  0b0..arm_a55_clk_root is used.
 *  0b1..The clock output of ARM PLL is selected.
 */
#define CCM_GPR_SHARED1_CA55_CORE4_CLOCK_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_CA55_CORE4_CLOCK_SELECT_SHIFT)) & CCM_GPR_SHARED1_CA55_CORE4_CLOCK_SELECT_MASK)

#define CCM_GPR_SHARED1_CA55_CORE5_CLOCK_SELECT_MASK (0x20U)
#define CCM_GPR_SHARED1_CA55_CORE5_CLOCK_SELECT_SHIFT (5U)
/*! CA55_CORE5_CLOCK_SELECT - Clock select signal between ccm clock root and ARM PLL clock
 *  0b0..arm_a55_clk_root is used.
 *  0b1..The clock output of ARM PLL is selected.
 */
#define CCM_GPR_SHARED1_CA55_CORE5_CLOCK_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_CA55_CORE5_CLOCK_SELECT_SHIFT)) & CCM_GPR_SHARED1_CA55_CORE5_CLOCK_SELECT_MASK)

#define CCM_GPR_SHARED1_CA55_PLATFORM_CLOCK_SELECT_MASK (0x40U)
#define CCM_GPR_SHARED1_CA55_PLATFORM_CLOCK_SELECT_SHIFT (6U)
/*! CA55_PLATFORM_CLOCK_SELECT - Clock select signal between ccm clock root and ARM PLL clock
 *  0b0..arm_a55_clk_root is used.
 *  0b1..The clock output of ARM PLL is selected.
 */
#define CCM_GPR_SHARED1_CA55_PLATFORM_CLOCK_SELECT(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_CA55_PLATFORM_CLOCK_SELECT_SHIFT)) & CCM_GPR_SHARED1_CA55_PLATFORM_CLOCK_SELECT_MASK)
/*! @} */

/*! @name GPR_SHARED1_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED1_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED1_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 */
#define CCM_GPR_SHARED1_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED1_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED1_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED1_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock Trustzone settings
 *  0b0..Trustzone settings is not locked.
 *  0b1..Trustzone settings is locked.
 */
#define CCM_GPR_SHARED1_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..White list is not locked.
 *  0b1..White list is locked.
 */
#define CCM_GPR_SHARED1_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - White list settings */
#define CCM_GPR_SHARED1_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED1_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED2 - General Purpose Register */
/*! @{ */

#define CCM_GPR_SHARED2_DRAM_PLL_BYPASS_MASK (0x1U)
#define CCM_GPR_SHARED2_DRAM_PLL_BYPASS_SHIFT (0U)
/*! DRAM_PLL_BYPASS - Clock select signal between ccm clock root and DRAM PLL clock
 *  0b0..The clock output of DRAM PLL is selected.
 *  0b1..Dram_alt_clk_root is selected.
 */
#define CCM_GPR_SHARED2_DRAM_PLL_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_DRAM_PLL_BYPASS_SHIFT)) & CCM_GPR_SHARED2_DRAM_PLL_BYPASS_MASK)

#define CCM_GPR_SHARED2_ANAMIX_TEMPSENSE_CLK_SEL_MASK (0x2U)
#define CCM_GPR_SHARED2_ANAMIX_TEMPSENSE_CLK_SEL_SHIFT (1U)
/*! ANAMIX_TEMPSENSE_CLK_SEL - Clock select signal between 24MHz oscillator clock and FRO clock
 *  0b0..24MHz oscillator clock is selected.
 *  0b1..FRO clock is selected.
 */
#define CCM_GPR_SHARED2_ANAMIX_TEMPSENSE_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_ANAMIX_TEMPSENSE_CLK_SEL_SHIFT)) & CCM_GPR_SHARED2_ANAMIX_TEMPSENSE_CLK_SEL_MASK)
/*! @} */

/*! @name GPR_SHARED2_AUTHEN - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED2_AUTHEN_TZ_USER_MASK      (0x100U)
#define CCM_GPR_SHARED2_AUTHEN_TZ_USER_SHIFT     (8U)
/*! TZ_USER - User access permission
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 */
#define CCM_GPR_SHARED2_AUTHEN_TZ_USER(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_TZ_USER_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_TZ_USER_MASK)

#define CCM_GPR_SHARED2_AUTHEN_TZ_NS_MASK        (0x200U)
#define CCM_GPR_SHARED2_AUTHEN_TZ_NS_SHIFT       (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED2_AUTHEN_TZ_NS(x)          (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_TZ_NS_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_TZ_NS_MASK)

#define CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_MASK      (0x800U)
#define CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_SHIFT     (11U)
/*! LOCK_TZ - Lock Trustzone settings
 *  0b0..Trustzone settings is not locked.
 *  0b1..Trustzone settings is locked.
 */
#define CCM_GPR_SHARED2_AUTHEN_LOCK_TZ(x)        (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_LOCK_TZ_MASK)

#define CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_MASK    (0x8000U)
#define CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..White list is not locked.
 *  0b1..White list is locked.
 */
#define CCM_GPR_SHARED2_AUTHEN_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_LOCK_LIST_MASK)

#define CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_MASK   (0xFFFF0000U)
#define CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - White list settings */
#define CCM_GPR_SHARED2_AUTHEN_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED2_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_SHARED - GPR access control */
/*! @{ */

#define CCM_GPR_SHARED_TZ_USER_MASK              (0x100U)
#define CCM_GPR_SHARED_TZ_USER_SHIFT             (8U)
/*! TZ_USER - User access permission
 *  0b1..Registers of shared GPR slice can be changed in user mode.
 *  0b0..Registers of shared GPR slice cannot be changed in user mode.
 */
#define CCM_GPR_SHARED_TZ_USER(x)                (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED_TZ_USER_SHIFT)) & CCM_GPR_SHARED_TZ_USER_MASK)

#define CCM_GPR_SHARED_TZ_NS_MASK                (0x200U)
#define CCM_GPR_SHARED_TZ_NS_SHIFT               (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_SHARED_TZ_NS(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED_TZ_NS_SHIFT)) & CCM_GPR_SHARED_TZ_NS_MASK)

#define CCM_GPR_SHARED_LOCK_TZ_MASK              (0x800U)
#define CCM_GPR_SHARED_LOCK_TZ_SHIFT             (11U)
/*! LOCK_TZ - Lock Trustzone settings
 *  0b0..Trustzone settings is not locked.
 *  0b1..Trustzone settings is locked.
 */
#define CCM_GPR_SHARED_LOCK_TZ(x)                (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED_LOCK_TZ_SHIFT)) & CCM_GPR_SHARED_LOCK_TZ_MASK)

#define CCM_GPR_SHARED_LOCK_LIST_MASK            (0x8000U)
#define CCM_GPR_SHARED_LOCK_LIST_SHIFT           (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..White list is not locked.
 *  0b1..White list is locked.
 */
#define CCM_GPR_SHARED_LOCK_LIST(x)              (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED_LOCK_LIST_SHIFT)) & CCM_GPR_SHARED_LOCK_LIST_MASK)

#define CCM_GPR_SHARED_WHITE_LIST_MASK           (0xFFFF0000U)
#define CCM_GPR_SHARED_WHITE_LIST_SHIFT          (16U)
/*! WHITE_LIST - White list settings */
#define CCM_GPR_SHARED_WHITE_LIST(x)             (((uint32_t)(((uint32_t)(x)) << CCM_GPR_SHARED_WHITE_LIST_SHIFT)) & CCM_GPR_SHARED_WHITE_LIST_MASK)
/*! @} */

/*! @name GPR_PRIVATE - General purpose register */
/*! @{ */

#define CCM_GPR_PRIVATE_GPR_MASK                 (0xFFFFFFFFU)
#define CCM_GPR_PRIVATE_GPR_SHIFT                (0U)
/*! GPR - GP register */
#define CCM_GPR_PRIVATE_GPR(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_GPR_SHIFT)) & CCM_GPR_PRIVATE_GPR_MASK)
/*! @} */

/*! @name GPR_PRIVATE - GPR access control */
/*! @{ */

#define CCM_GPR_PRIVATE_TZ_USER_MASK             (0x100U)
#define CCM_GPR_PRIVATE_TZ_USER_SHIFT            (8U)
/*! TZ_USER - User access permission
 *  0b1..Registers of private GPR can be changed in user mode.
 *  0b0..Registers of private GPR cannot be changed in user mode.
 */
#define CCM_GPR_PRIVATE_TZ_USER(x)               (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_TZ_USER_SHIFT)) & CCM_GPR_PRIVATE_TZ_USER_MASK)

#define CCM_GPR_PRIVATE_TZ_NS_MASK               (0x200U)
#define CCM_GPR_PRIVATE_TZ_NS_SHIFT              (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_GPR_PRIVATE_TZ_NS(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_TZ_NS_SHIFT)) & CCM_GPR_PRIVATE_TZ_NS_MASK)

#define CCM_GPR_PRIVATE_LOCK_TZ_MASK             (0x800U)
#define CCM_GPR_PRIVATE_LOCK_TZ_SHIFT            (11U)
/*! LOCK_TZ - Lock Trustzone settings
 *  0b0..Trustzone settings is not locked.
 *  0b1..Trustzone settings is locked.
 */
#define CCM_GPR_PRIVATE_LOCK_TZ(x)               (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_LOCK_TZ_SHIFT)) & CCM_GPR_PRIVATE_LOCK_TZ_MASK)

#define CCM_GPR_PRIVATE_LOCK_LIST_MASK           (0x8000U)
#define CCM_GPR_PRIVATE_LOCK_LIST_SHIFT          (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..White list is not locked.
 *  0b1..White list is locked.
 */
#define CCM_GPR_PRIVATE_LOCK_LIST(x)             (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_LOCK_LIST_SHIFT)) & CCM_GPR_PRIVATE_LOCK_LIST_MASK)

#define CCM_GPR_PRIVATE_WHITE_LIST_MASK          (0xFFFF0000U)
#define CCM_GPR_PRIVATE_WHITE_LIST_SHIFT         (16U)
/*! WHITE_LIST - White list settings */
#define CCM_GPR_PRIVATE_WHITE_LIST(x)            (((uint32_t)(((uint32_t)(x)) << CCM_GPR_PRIVATE_WHITE_LIST_SHIFT)) & CCM_GPR_PRIVATE_WHITE_LIST_MASK)
/*! @} */

/*! @name OSCPLL_DIRECT - Clock source direct control */
/*! @{ */

#define CCM_OSCPLL_DIRECT_ON_MASK                (0x1U)
#define CCM_OSCPLL_DIRECT_ON_SHIFT               (0U)
/*! ON - Turn on clock source
 *  0b0..Clock source is OFF.
 *  0b1..Clock source is ON.
 */
#define CCM_OSCPLL_DIRECT_ON(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_DIRECT_ON_SHIFT)) & CCM_OSCPLL_DIRECT_ON_MASK)
/*! @} */

/* The count of CCM_OSCPLL_DIRECT */
#define CCM_OSCPLL_DIRECT_COUNT                  (39U)

/*! @name OSCPLL_LPM_STATUS0 - Low power mode information transfer status */
/*! @{ */

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN0_MASK (0x3U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN0_SHIFT (0U)
/*! CPU_MODE_DOMAIN0 - Current mode of CPU domain 0
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN0(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN0_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN0_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN0_MASK (0x4U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN0_SHIFT (2U)
/*! TRANS_REQ_DOMAIN0 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN0(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN0_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN0_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN1_MASK (0x30U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN1_SHIFT (4U)
/*! CPU_MODE_DOMAIN1 - Current mode of CPU domain 1
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN1(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN1_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN1_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN1_MASK (0x40U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN1_SHIFT (6U)
/*! TRANS_REQ_DOMAIN1 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN1(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN1_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN1_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN2_MASK (0x300U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN2_SHIFT (8U)
/*! CPU_MODE_DOMAIN2 - Current mode of CPU domain 2
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN2(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN2_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN2_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN2_MASK (0x400U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN2_SHIFT (10U)
/*! TRANS_REQ_DOMAIN2 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN2(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN2_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN2_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN3_MASK (0x3000U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN3_SHIFT (12U)
/*! CPU_MODE_DOMAIN3 - Current mode of CPU domain 3
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN3(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN3_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN3_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN3_MASK (0x4000U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN3_SHIFT (14U)
/*! TRANS_REQ_DOMAIN3 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN3(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN3_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN3_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN4_MASK (0x30000U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN4_SHIFT (16U)
/*! CPU_MODE_DOMAIN4 - Current mode of CPU domain 4
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN4(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN4_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN4_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN4_MASK (0x40000U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN4_SHIFT (18U)
/*! TRANS_REQ_DOMAIN4 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN4(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN4_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN4_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN5_MASK (0x300000U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN5_SHIFT (20U)
/*! CPU_MODE_DOMAIN5 - Current mode of CPU domain 5
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN5(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN5_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN5_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN5_MASK (0x400000U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN5_SHIFT (22U)
/*! TRANS_REQ_DOMAIN5 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN5(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN5_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN5_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN6_MASK (0x3000000U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN6_SHIFT (24U)
/*! CPU_MODE_DOMAIN6 - Current mode of CPU domain 6
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN6(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN6_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN6_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN6_MASK (0x4000000U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN6_SHIFT (26U)
/*! TRANS_REQ_DOMAIN6 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN6(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN6_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN6_MASK)

#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN7_MASK (0x30000000U)
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN7_SHIFT (28U)
/*! CPU_MODE_DOMAIN7 - Current mode of CPU domain 7
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN7(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN7_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_CPU_MODE_DOMAIN7_MASK)

#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN7_MASK (0x40000000U)
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN7_SHIFT (30U)
/*! TRANS_REQ_DOMAIN7 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN7(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN7_SHIFT)) & CCM_OSCPLL_LPM_STATUS0_TRANS_REQ_DOMAIN7_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM_STATUS0 */
#define CCM_OSCPLL_LPM_STATUS0_COUNT             (39U)

/*! @name OSCPLL_LPM_STATUS1 - Low power mode information transfer status */
/*! @{ */

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN8_MASK (0x3U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN8_SHIFT (0U)
/*! CPU_MODE_DOMAIN8 - Current mode of CPU domain 8
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN8(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN8_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN8_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN8_MASK (0x4U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN8_SHIFT (2U)
/*! TRANS_REQ_DOMAIN8 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN8(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN8_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN8_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN9_MASK (0x30U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN9_SHIFT (4U)
/*! CPU_MODE_DOMAIN9 - Current mode of CPU domain 9
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN9(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN9_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN9_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN9_MASK (0x40U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN9_SHIFT (6U)
/*! TRANS_REQ_DOMAIN9 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN9(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN9_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN9_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN10_MASK (0x300U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN10_SHIFT (8U)
/*! CPU_MODE_DOMAIN10 - Current mode of CPU domain 10
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN10(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN10_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN10_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN10_MASK (0x400U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN10_SHIFT (10U)
/*! TRANS_REQ_DOMAIN10 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN10(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN10_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN10_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN11_MASK (0x3000U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN11_SHIFT (12U)
/*! CPU_MODE_DOMAIN11 - Current mode of CPU domain 11
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN11(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN11_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN11_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN11_MASK (0x4000U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN11_SHIFT (14U)
/*! TRANS_REQ_DOMAIN11 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN11(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN11_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN11_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN12_MASK (0x30000U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN12_SHIFT (16U)
/*! CPU_MODE_DOMAIN12 - Current mode of CPU domain 12
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN12(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN12_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN12_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN12_MASK (0x40000U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN12_SHIFT (18U)
/*! TRANS_REQ_DOMAIN12 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN12(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN12_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN12_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN13_MASK (0x300000U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN13_SHIFT (20U)
/*! CPU_MODE_DOMAIN13 - Current mode of CPU domain 13
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN13(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN13_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN13_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN13_MASK (0x400000U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN13_SHIFT (22U)
/*! TRANS_REQ_DOMAIN13 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN13(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN13_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN13_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN14_MASK (0x3000000U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN14_SHIFT (24U)
/*! CPU_MODE_DOMAIN14 - Current mode of CPU domain 14
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN14(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN14_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN14_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN14_MASK (0x4000000U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN14_SHIFT (26U)
/*! TRANS_REQ_DOMAIN14 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN14(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN14_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN14_MASK)

#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN15_MASK (0x30000000U)
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN15_SHIFT (28U)
/*! CPU_MODE_DOMAIN15 - Current mode of CPU domain 15
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN15(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN15_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_CPU_MODE_DOMAIN15_MASK)

#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN15_MASK (0x40000000U)
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN15_SHIFT (30U)
/*! TRANS_REQ_DOMAIN15 - GPC request CCM to enable or disable OSCPLL. This signal will turn to low once CCM complete response to GPC. */
#define CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN15(x) (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN15_SHIFT)) & CCM_OSCPLL_LPM_STATUS1_TRANS_REQ_DOMAIN15_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM_STATUS1 */
#define CCM_OSCPLL_LPM_STATUS1_COUNT             (39U)

/*! @name OSCPLL_LPM0 - Clock source low power mode setting */
/*! @{ */

#define CCM_OSCPLL_LPM0_LPM_SETTING_D0_MASK      (0x7U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D0_SHIFT     (0U)
/*! LPM_SETTING_D0 - Clock Source low power mode setting in DOMAIN0
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND Mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D0(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D0_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D0_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D1_MASK      (0x70U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D1_SHIFT     (4U)
/*! LPM_SETTING_D1 - Clock Source low power mode setting in DOMAIN1
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND Mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D1(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D1_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D1_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D2_MASK      (0x700U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D2_SHIFT     (8U)
/*! LPM_SETTING_D2 - Clock Source low power mode setting in DOMAIN2
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND Mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D2(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D2_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D2_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D3_MASK      (0x7000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D3_SHIFT     (12U)
/*! LPM_SETTING_D3 - Clock Source low power mode setting in DOMAIN3
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND Mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D3(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D3_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D3_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D4_MASK      (0x70000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D4_SHIFT     (16U)
/*! LPM_SETTING_D4 - Clock Source low power mode setting in DOMAIN4
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND Mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D4(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D4_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D4_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D5_MASK      (0x700000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D5_SHIFT     (20U)
/*! LPM_SETTING_D5 - Clock Source low power mode setting in DOMAIN5
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND Mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D5(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D5_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D5_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D6_MASK      (0x7000000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D6_SHIFT     (24U)
/*! LPM_SETTING_D6 - Clock Source low power mode setting in DOMAIN6
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND Mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D6(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D6_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D6_MASK)

#define CCM_OSCPLL_LPM0_LPM_SETTING_D7_MASK      (0x70000000U)
#define CCM_OSCPLL_LPM0_LPM_SETTING_D7_SHIFT     (28U)
/*! LPM_SETTING_D7 - Clock Source low power mode setting in DOMAIN7
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND Mode.
 */
#define CCM_OSCPLL_LPM0_LPM_SETTING_D7(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM0_LPM_SETTING_D7_SHIFT)) & CCM_OSCPLL_LPM0_LPM_SETTING_D7_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM0 */
#define CCM_OSCPLL_LPM0_COUNT                    (39U)

/*! @name OSCPLL_LPM1 - clock source low power mode setting */
/*! @{ */

#define CCM_OSCPLL_LPM1_LPM_SETTING_D8_MASK      (0x7U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D8_SHIFT     (0U)
/*! LPM_SETTING_D8 - Clock Source LPM in DOMAIN8
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D8(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D8_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D8_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D9_MASK      (0x70U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D9_SHIFT     (4U)
/*! LPM_SETTING_D9 - Clock Source LPM in DOMAIN9
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D9(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D9_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D9_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D10_MASK     (0x700U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D10_SHIFT    (8U)
/*! LPM_SETTING_D10 - Clock Source LPM in DOMAIN10
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D10(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D10_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D10_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D11_MASK     (0x7000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D11_SHIFT    (12U)
/*! LPM_SETTING_D11 - Clock Source LPM in DOMAIN11
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D11(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D11_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D11_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D12_MASK     (0x70000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D12_SHIFT    (16U)
/*! LPM_SETTING_D12 - Clock Source LPM in DOMAIN12
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D12(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D12_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D12_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D13_MASK     (0x700000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D13_SHIFT    (20U)
/*! LPM_SETTING_D13 - Clock Source LPM in DOMAIN13
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D13(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D13_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D13_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D14_MASK     (0x7000000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D14_SHIFT    (24U)
/*! LPM_SETTING_D14 - Clock Source LPM in DOMAIN14
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D14(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D14_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D14_MASK)

#define CCM_OSCPLL_LPM1_LPM_SETTING_D15_MASK     (0x70000000U)
#define CCM_OSCPLL_LPM1_LPM_SETTING_D15_SHIFT    (28U)
/*! LPM_SETTING_D15 - Clock Source LPM in DOMAIN15
 *  0b000..Clock Source will be OFF in any CPU mode.
 *  0b001..Clock Source will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b010..Clock Source will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b011..Clock Source will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 *  0b100..Clock Source will be ON in RUN/WAIT/STOP/SUSPEND mode.
 */
#define CCM_OSCPLL_LPM1_LPM_SETTING_D15(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM1_LPM_SETTING_D15_SHIFT)) & CCM_OSCPLL_LPM1_LPM_SETTING_D15_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM1 */
#define CCM_OSCPLL_LPM1_COUNT                    (39U)

/*! @name OSCPLL_LPM_CUR - LPM setting of current CPU domain */
/*! @{ */

#define CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_MASK  (0x7U)
#define CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_SHIFT (0U)
/*! LPM_SETTING_CUR - LPM SETTING of current CPU DOMAIN */
#define CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR(x)    (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_SHIFT)) & CCM_OSCPLL_LPM_CUR_LPM_SETTING_CUR_MASK)
/*! @} */

/* The count of CCM_OSCPLL_LPM_CUR */
#define CCM_OSCPLL_LPM_CUR_COUNT                 (39U)

/*! @name OSCPLL_STATUS0 - Clock source working status */
/*! @{ */

#define CCM_OSCPLL_STATUS0_ON_MASK               (0x1U)
#define CCM_OSCPLL_STATUS0_ON_SHIFT              (0U)
/*! ON - Clock source current state
 *  0b0..Clock source is OFF.
 *  0b1..Clock source is ON.
 */
#define CCM_OSCPLL_STATUS0_ON(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_ON_SHIFT)) & CCM_OSCPLL_STATUS0_ON_MASK)

#define CCM_OSCPLL_STATUS0_STATUS_EARLY_MASK     (0x10U)
#define CCM_OSCPLL_STATUS0_STATUS_EARLY_SHIFT    (4U)
#define CCM_OSCPLL_STATUS0_STATUS_EARLY(x)       (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_STATUS_EARLY_SHIFT)) & CCM_OSCPLL_STATUS0_STATUS_EARLY_MASK)

#define CCM_OSCPLL_STATUS0_STATUS_LATE_MASK      (0x20U)
#define CCM_OSCPLL_STATUS0_STATUS_LATE_SHIFT     (5U)
#define CCM_OSCPLL_STATUS0_STATUS_LATE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_STATUS_LATE_SHIFT)) & CCM_OSCPLL_STATUS0_STATUS_LATE_MASK)

#define CCM_OSCPLL_STATUS0_IN_USE_MASK           (0x1000U)
#define CCM_OSCPLL_STATUS0_IN_USE_SHIFT          (12U)
/*! IN_USE - This Clock Source is being used or not.
 *  0b0..Clock Source is not being used.
 *  0b1..Clock Source is being used.
 */
#define CCM_OSCPLL_STATUS0_IN_USE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS0_IN_USE_SHIFT)) & CCM_OSCPLL_STATUS0_IN_USE_MASK)
/*! @} */

/* The count of CCM_OSCPLL_STATUS0 */
#define CCM_OSCPLL_STATUS0_COUNT                 (39U)

/*! @name OSCPLL_STATUS1 - Clock source domain status */
/*! @{ */

#define CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_MASK    (0xFFFFU)
#define CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_SHIFT   (0U)
/*! DOMAIN_ACTIVE - Domain active */
#define CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE(x)      (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_SHIFT)) & CCM_OSCPLL_STATUS1_DOMAIN_ACTIVE_MASK)

#define CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_MASK    (0xFFFF0000U)
#define CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_SHIFT   (16U)
/*! DOMAIN_ENABLE - Domain enable */
#define CCM_OSCPLL_STATUS1_DOMAIN_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_SHIFT)) & CCM_OSCPLL_STATUS1_DOMAIN_ENABLE_MASK)
/*! @} */

/* The count of CCM_OSCPLL_STATUS1 */
#define CCM_OSCPLL_STATUS1_COUNT                 (39U)

/*! @name OSCPLL_AUTHEN - Clock Source access control */
/*! @{ */

#define CCM_OSCPLL_AUTHEN_CPULPM_MODE_MASK       (0x4U)
#define CCM_OSCPLL_AUTHEN_CPULPM_MODE_SHIFT      (2U)
/*! CPULPM_MODE - CPULPM mode enable
 *  0b0..Disable CPULPM mode.
 *  0b1..Enable CPULPM mode.
 */
#define CCM_OSCPLL_AUTHEN_CPULPM_MODE(x)         (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_CPULPM_MODE_SHIFT)) & CCM_OSCPLL_AUTHEN_CPULPM_MODE_MASK)

#define CCM_OSCPLL_AUTHEN_AUTO_CTRL_MASK         (0x8U)
#define CCM_OSCPLL_AUTHEN_AUTO_CTRL_SHIFT        (3U)
/*! AUTO_CTRL - Auto mode enable
 *  0b0..Disable Auto mode
 *  0b1..Enable Auto mode
 */
#define CCM_OSCPLL_AUTHEN_AUTO_CTRL(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_AUTO_CTRL_SHIFT)) & CCM_OSCPLL_AUTHEN_AUTO_CTRL_MASK)

#define CCM_OSCPLL_AUTHEN_LOCK_MODE_MASK         (0x80U)
#define CCM_OSCPLL_AUTHEN_LOCK_MODE_SHIFT        (7U)
/*! LOCK_MODE
 *  0b0..CPULPM_MODE and AUTO_CTRL is not locked.
 *  0b1..CPULPM_MODE and AUTO_CTRL is locked.
 */
#define CCM_OSCPLL_AUTHEN_LOCK_MODE(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_LOCK_MODE_SHIFT)) & CCM_OSCPLL_AUTHEN_LOCK_MODE_MASK)

#define CCM_OSCPLL_AUTHEN_TZ_USER_MASK           (0x100U)
#define CCM_OSCPLL_AUTHEN_TZ_USER_SHIFT          (8U)
/*! TZ_USER - User access permission
 *  0b1..Clock Source settings can be changed in user mode.
 *  0b0..Clock Source settings cannot be changed in user mode.
 */
#define CCM_OSCPLL_AUTHEN_TZ_USER(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_TZ_USER_SHIFT)) & CCM_OSCPLL_AUTHEN_TZ_USER_MASK)

#define CCM_OSCPLL_AUTHEN_TZ_NS_MASK             (0x200U)
#define CCM_OSCPLL_AUTHEN_TZ_NS_SHIFT            (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_OSCPLL_AUTHEN_TZ_NS(x)               (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_TZ_NS_SHIFT)) & CCM_OSCPLL_AUTHEN_TZ_NS_MASK)

#define CCM_OSCPLL_AUTHEN_LOCK_TZ_MASK           (0x800U)
#define CCM_OSCPLL_AUTHEN_LOCK_TZ_SHIFT          (11U)
/*! LOCK_TZ - Lock Trustzone settings
 *  0b0..Trustzone settings is not locked.
 *  0b1..Trustzone settings is locked.
 */
#define CCM_OSCPLL_AUTHEN_LOCK_TZ(x)             (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_LOCK_TZ_SHIFT)) & CCM_OSCPLL_AUTHEN_LOCK_TZ_MASK)

#define CCM_OSCPLL_AUTHEN_LOCK_LIST_MASK         (0x8000U)
#define CCM_OSCPLL_AUTHEN_LOCK_LIST_SHIFT        (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..White list is not locked.
 *  0b1..White list is locked.
 */
#define CCM_OSCPLL_AUTHEN_LOCK_LIST(x)           (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_LOCK_LIST_SHIFT)) & CCM_OSCPLL_AUTHEN_LOCK_LIST_MASK)

#define CCM_OSCPLL_AUTHEN_WHITE_LIST_MASK        (0xFFFF0000U)
#define CCM_OSCPLL_AUTHEN_WHITE_LIST_SHIFT       (16U)
/*! WHITE_LIST - White list */
#define CCM_OSCPLL_AUTHEN_WHITE_LIST(x)          (((uint32_t)(((uint32_t)(x)) << CCM_OSCPLL_AUTHEN_WHITE_LIST_SHIFT)) & CCM_OSCPLL_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_OSCPLL_AUTHEN */
#define CCM_OSCPLL_AUTHEN_COUNT                  (39U)

/*! @name LPCG_DIRECT - LPCG direct control */
/*! @{ */

#define CCM_LPCG_DIRECT_ON_MASK                  (0x1U)
#define CCM_LPCG_DIRECT_ON_SHIFT                 (0U)
/*! ON - Turn on LPCG
 *  0b0..LPCG is OFF.
 *  0b1..LPCG is ON.
 */
#define CCM_LPCG_DIRECT_ON(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_DIRECT_ON_SHIFT)) & CCM_LPCG_DIRECT_ON_MASK)

#define CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_MASK (0x4U)
#define CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_SHIFT (2U)
/*! CLKOFF_ACK_TIMEOUT_EN - Clock off handshake timeout enable
 *  0b0..disable
 *  0b1..enable
 */
#define CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_SHIFT)) & CCM_LPCG_DIRECT_CLKOFF_ACK_TIMEOUT_EN_MASK)
/*! @} */

/* The count of CCM_LPCG_DIRECT */
#define CCM_LPCG_DIRECT_COUNT                    (256U)

/*! @name LPCG_LPM_STATUS0 - Low power mode information transfer status */
/*! @{ */

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN0_MASK (0x3U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN0_SHIFT (0U)
/*! CPU_MODE_DOMAIN0 - Current mode of CPU domain 0
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN0(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN0_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN0_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN0_MASK (0x4U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN0_SHIFT (2U)
/*! TRANS_REQ_DOMAIN0 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN0(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN0_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN0_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN1_MASK (0x30U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN1_SHIFT (4U)
/*! CPU_MODE_DOMAIN1 - Current mode of CPU domain 1
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN1(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN1_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN1_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN1_MASK (0x40U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN1_SHIFT (6U)
/*! TRANS_REQ_DOMAIN1 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN1(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN1_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN1_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN2_MASK (0x300U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN2_SHIFT (8U)
/*! CPU_MODE_DOMAIN2 - Current mode of CPU domain 2
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN2(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN2_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN2_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN2_MASK (0x400U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN2_SHIFT (10U)
/*! TRANS_REQ_DOMAIN2 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN2(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN2_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN2_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN3_MASK (0x3000U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN3_SHIFT (12U)
/*! CPU_MODE_DOMAIN3 - Current mode of CPU domain 3
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN3(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN3_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN3_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN3_MASK (0x4000U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN3_SHIFT (14U)
/*! TRANS_REQ_DOMAIN3 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN3(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN3_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN3_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN4_MASK (0x30000U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN4_SHIFT (16U)
/*! CPU_MODE_DOMAIN4 - Current mode of CPU domain 4
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN4(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN4_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN4_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN4_MASK (0x40000U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN4_SHIFT (18U)
/*! TRANS_REQ_DOMAIN4 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN4(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN4_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN4_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN5_MASK (0x300000U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN5_SHIFT (20U)
/*! CPU_MODE_DOMAIN5 - Current mode of CPU domain 5
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN5(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN5_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN5_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN5_MASK (0x400000U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN5_SHIFT (22U)
/*! TRANS_REQ_DOMAIN5 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN5(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN5_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN5_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN6_MASK (0x3000000U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN6_SHIFT (24U)
/*! CPU_MODE_DOMAIN6 - Current mode of CPU domain 6
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN6(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN6_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN6_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN6_MASK (0x4000000U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN6_SHIFT (26U)
/*! TRANS_REQ_DOMAIN6 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN6(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN6_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN6_MASK)

#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN7_MASK (0x30000000U)
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN7_SHIFT (28U)
/*! CPU_MODE_DOMAIN7 - Current mode of CPU domain 7
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN7(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN7_SHIFT)) & CCM_LPCG_LPM_STATUS0_CPU_MODE_DOMAIN7_MASK)

#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN7_MASK (0x40000000U)
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN7_SHIFT (30U)
/*! TRANS_REQ_DOMAIN7 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN7(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN7_SHIFT)) & CCM_LPCG_LPM_STATUS0_TRANS_REQ_DOMAIN7_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM_STATUS0 */
#define CCM_LPCG_LPM_STATUS0_COUNT               (256U)

/*! @name LPCG_LPM_STATUS1 - Low power mode information transfer status */
/*! @{ */

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN8_MASK (0x3U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN8_SHIFT (0U)
/*! CPU_MODE_DOMAIN8 - Current mode of CPU domain 8
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN8(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN8_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN8_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN8_MASK (0x4U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN8_SHIFT (2U)
/*! TRANS_REQ_DOMAIN8 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN8(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN8_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN8_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN9_MASK (0x30U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN9_SHIFT (4U)
/*! CPU_MODE_DOMAIN9 - Current mode of CPU domain 9
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN9(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN9_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN9_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN9_MASK (0x40U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN9_SHIFT (6U)
/*! TRANS_REQ_DOMAIN9 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN9(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN9_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN9_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN10_MASK (0x300U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN10_SHIFT (8U)
/*! CPU_MODE_DOMAIN10 - Current mode of CPU domain 10
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN10(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN10_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN10_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN10_MASK (0x400U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN10_SHIFT (10U)
/*! TRANS_REQ_DOMAIN10 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN10(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN10_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN10_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN11_MASK (0x3000U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN11_SHIFT (12U)
/*! CPU_MODE_DOMAIN11 - Current mode of CPU domain 11
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN11(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN11_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN11_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN11_MASK (0x4000U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN11_SHIFT (14U)
/*! TRANS_REQ_DOMAIN11 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN11(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN11_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN11_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN12_MASK (0x30000U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN12_SHIFT (16U)
/*! CPU_MODE_DOMAIN12 - Current mode of CPU domain 12
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN12(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN12_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN12_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN12_MASK (0x40000U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN12_SHIFT (18U)
/*! TRANS_REQ_DOMAIN12 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN12(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN12_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN12_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN13_MASK (0x300000U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN13_SHIFT (20U)
/*! CPU_MODE_DOMAIN13 - Current mode of CPU domain 13
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN13(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN13_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN13_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN13_MASK (0x400000U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN13_SHIFT (22U)
/*! TRANS_REQ_DOMAIN13 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN13(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN13_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN13_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN14_MASK (0x3000000U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN14_SHIFT (24U)
/*! CPU_MODE_DOMAIN14 - Current mode of CPU domain 14
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN14(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN14_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN14_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN14_MASK (0x4000000U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN14_SHIFT (26U)
/*! TRANS_REQ_DOMAIN14 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN14(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN14_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN14_MASK)

#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN15_MASK (0x30000000U)
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN15_SHIFT (28U)
/*! CPU_MODE_DOMAIN15 - Current mode of CPU domain 15
 *  0b00..CPU is in RUN mode
 *  0b01..CPU is in WAIT mode
 *  0b10..CPU is in STOP mode
 *  0b11..CPU is in SUSPEND mode
 */
#define CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN15(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN15_SHIFT)) & CCM_LPCG_LPM_STATUS1_CPU_MODE_DOMAIN15_MASK)

#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN15_MASK (0x40000000U)
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN15_SHIFT (30U)
/*! TRANS_REQ_DOMAIN15 - GPC request CCM to enable or disable LPCG. This signal will turn to low once CCM complete response to GPC. */
#define CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN15(x) (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN15_SHIFT)) & CCM_LPCG_LPM_STATUS1_TRANS_REQ_DOMAIN15_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM_STATUS1 */
#define CCM_LPCG_LPM_STATUS1_COUNT               (256U)

/*! @name LPCG_LPM0 - LPCG low power mode setting */
/*! @{ */

#define CCM_LPCG_LPM0_LPM_SETTING_D0_MASK        (0x3U)
#define CCM_LPCG_LPM0_LPM_SETTING_D0_SHIFT       (0U)
/*! LPM_SETTING_D0 - LPCG low power mode setting in DOMAIN0
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D0(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D0_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D0_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D1_MASK        (0x30U)
#define CCM_LPCG_LPM0_LPM_SETTING_D1_SHIFT       (4U)
/*! LPM_SETTING_D1 - LPCG low power mode setting in DOMAIN1
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D1(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D1_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D1_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D2_MASK        (0x300U)
#define CCM_LPCG_LPM0_LPM_SETTING_D2_SHIFT       (8U)
/*! LPM_SETTING_D2 - LPCG low power mode setting in DOMAIN2
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D2(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D2_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D2_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D3_MASK        (0x3000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D3_SHIFT       (12U)
/*! LPM_SETTING_D3 - LPCG low power mode setting in DOMAIN3
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D3(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D3_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D3_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D4_MASK        (0x30000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D4_SHIFT       (16U)
/*! LPM_SETTING_D4 - LPCG low power mode setting in DOMAIN4
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D4(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D4_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D4_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D5_MASK        (0x300000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D5_SHIFT       (20U)
/*! LPM_SETTING_D5 - LPCG low power mode setting in DOMAIN5
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D5(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D5_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D5_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D6_MASK        (0x3000000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D6_SHIFT       (24U)
/*! LPM_SETTING_D6 - LPCG low power mode setting in DOMAIN6
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D6(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D6_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D6_MASK)

#define CCM_LPCG_LPM0_LPM_SETTING_D7_MASK        (0x30000000U)
#define CCM_LPCG_LPM0_LPM_SETTING_D7_SHIFT       (28U)
/*! LPM_SETTING_D7 - LPCG low power mode setting in DOMAIN7
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM0_LPM_SETTING_D7(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM0_LPM_SETTING_D7_SHIFT)) & CCM_LPCG_LPM0_LPM_SETTING_D7_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM0 */
#define CCM_LPCG_LPM0_COUNT                      (256U)

/*! @name LPCG_LPM1 - LPCG low power mode setting */
/*! @{ */

#define CCM_LPCG_LPM1_LPM_SETTING_D8_MASK        (0x3U)
#define CCM_LPCG_LPM1_LPM_SETTING_D8_SHIFT       (0U)
/*! LPM_SETTING_D8 - LPCG low power mode setting in DOMAIN8.
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D8(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D8_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D8_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D9_MASK        (0x30U)
#define CCM_LPCG_LPM1_LPM_SETTING_D9_SHIFT       (4U)
/*! LPM_SETTING_D9 - LPCG low power mode setting in DOMAIN9.
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D9(x)          (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D9_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D9_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D10_MASK       (0x300U)
#define CCM_LPCG_LPM1_LPM_SETTING_D10_SHIFT      (8U)
/*! LPM_SETTING_D10 - LPCG low power mode setting in DOMAIN10.
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D10(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D10_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D10_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D11_MASK       (0x3000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D11_SHIFT      (12U)
/*! LPM_SETTING_D11 - LPCG low power mode setting in DOMAIN11.
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D11(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D11_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D11_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D12_MASK       (0x30000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D12_SHIFT      (16U)
/*! LPM_SETTING_D12 - LPCG low power mode setting in DOMAIN12.
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D12(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D12_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D12_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D13_MASK       (0x300000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D13_SHIFT      (20U)
/*! LPM_SETTING_D13 - LPCG low power mode setting in DOMAIN13.
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D13(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D13_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D13_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D14_MASK       (0x3000000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D14_SHIFT      (24U)
/*! LPM_SETTING_D14 - LPCG low power mode setting in DOMAIN14.
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D14(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D14_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D14_MASK)

#define CCM_LPCG_LPM1_LPM_SETTING_D15_MASK       (0x30000000U)
#define CCM_LPCG_LPM1_LPM_SETTING_D15_SHIFT      (28U)
/*! LPM_SETTING_D15 - LPCG low power mode setting in DOMAIN15.
 *  0b00..LPCG will be OFF in any CPU mode.
 *  0b01..LPCG will be ON in RUN mode, OFF in WAIT/STOP/SUSPEND mode.
 *  0b10..LPCG will be ON in RUN/WAIT mode, OFF in STOP/SUSPEND mode.
 *  0b11..LPCG will be ON in RUN/WAIT/STOP mode, OFF in SUSPEND mode.
 */
#define CCM_LPCG_LPM1_LPM_SETTING_D15(x)         (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM1_LPM_SETTING_D15_SHIFT)) & CCM_LPCG_LPM1_LPM_SETTING_D15_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM1 */
#define CCM_LPCG_LPM1_COUNT                      (256U)

/*! @name LPCG_LPM_CUR - LPM setting of current CPU domain */
/*! @{ */

#define CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_MASK    (0x3U)
#define CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_SHIFT   (0U)
/*! LPM_SETTING_CUR - LPM SETTING of current CPU DOMAIN */
#define CCM_LPCG_LPM_CUR_LPM_SETTING_CUR(x)      (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_SHIFT)) & CCM_LPCG_LPM_CUR_LPM_SETTING_CUR_MASK)
/*! @} */

/* The count of CCM_LPCG_LPM_CUR */
#define CCM_LPCG_LPM_CUR_COUNT                   (256U)

/*! @name LPCG_STATUS0 - LPCG working status */
/*! @{ */

#define CCM_LPCG_STATUS0_ON_MASK                 (0x1U)
#define CCM_LPCG_STATUS0_ON_SHIFT                (0U)
/*! ON - LPCG work status
 *  0b0..LPCG is OFF.
 *  0b1..LPCG is ON.
 */
#define CCM_LPCG_STATUS0_ON(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_STATUS0_ON_SHIFT)) & CCM_LPCG_STATUS0_ON_MASK)
/*! @} */

/* The count of CCM_LPCG_STATUS0 */
#define CCM_LPCG_STATUS0_COUNT                   (256U)

/*! @name LPCG_STATUS1 - LPCG domain status */
/*! @{ */

#define CCM_LPCG_STATUS1_DOMAIN_ACTIVE_MASK      (0xFFFFU)
#define CCM_LPCG_STATUS1_DOMAIN_ACTIVE_SHIFT     (0U)
/*! DOMAIN_ACTIVE - Domain active */
#define CCM_LPCG_STATUS1_DOMAIN_ACTIVE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_STATUS1_DOMAIN_ACTIVE_SHIFT)) & CCM_LPCG_STATUS1_DOMAIN_ACTIVE_MASK)

#define CCM_LPCG_STATUS1_DOMAIN_ENABLE_MASK      (0xFFFF0000U)
#define CCM_LPCG_STATUS1_DOMAIN_ENABLE_SHIFT     (16U)
/*! DOMAIN_ENABLE - Domain enable */
#define CCM_LPCG_STATUS1_DOMAIN_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_STATUS1_DOMAIN_ENABLE_SHIFT)) & CCM_LPCG_STATUS1_DOMAIN_ENABLE_MASK)
/*! @} */

/* The count of CCM_LPCG_STATUS1 */
#define CCM_LPCG_STATUS1_COUNT                   (256U)

/*! @name LPCG_AUTHEN - LPCG access control */
/*! @{ */

#define CCM_LPCG_AUTHEN_CPULPM_MODE_MASK         (0x4U)
#define CCM_LPCG_AUTHEN_CPULPM_MODE_SHIFT        (2U)
/*! CPULPM_MODE - CPULPM mode enable
 *  0b0..Disable CPULPM mode, this LPCG is in Direct Control mode.
 *  0b1..Enable CPULPM mode, this LPCG is in CPULPM mode.
 */
#define CCM_LPCG_AUTHEN_CPULPM_MODE(x)           (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_CPULPM_MODE_SHIFT)) & CCM_LPCG_AUTHEN_CPULPM_MODE_MASK)

#define CCM_LPCG_AUTHEN_LOCK_MODE_MASK           (0x80U)
#define CCM_LPCG_AUTHEN_LOCK_MODE_SHIFT          (7U)
/*! LOCK_MODE
 *  0b0..CPULPM_MODE is not locked.
 *  0b1..CPULPM_MODE is locked.
 */
#define CCM_LPCG_AUTHEN_LOCK_MODE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_LOCK_MODE_SHIFT)) & CCM_LPCG_AUTHEN_LOCK_MODE_MASK)

#define CCM_LPCG_AUTHEN_TZ_USER_MASK             (0x100U)
#define CCM_LPCG_AUTHEN_TZ_USER_SHIFT            (8U)
/*! TZ_USER - User access permission
 *  0b1..LPCG settings can be changed in user mode.
 *  0b0..LPCG settings cannot be changed in user mode.
 */
#define CCM_LPCG_AUTHEN_TZ_USER(x)               (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_TZ_USER_SHIFT)) & CCM_LPCG_AUTHEN_TZ_USER_MASK)

#define CCM_LPCG_AUTHEN_TZ_NS_MASK               (0x200U)
#define CCM_LPCG_AUTHEN_TZ_NS_SHIFT              (9U)
/*! TZ_NS - Non-secure access permission
 *  0b0..Cannot be changed in Non-secure mode.
 *  0b1..Can be changed in Non-secure mode.
 */
#define CCM_LPCG_AUTHEN_TZ_NS(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_TZ_NS_SHIFT)) & CCM_LPCG_AUTHEN_TZ_NS_MASK)

#define CCM_LPCG_AUTHEN_LOCK_TZ_MASK             (0x800U)
#define CCM_LPCG_AUTHEN_LOCK_TZ_SHIFT            (11U)
/*! LOCK_TZ - Lock Trustzone settings
 *  0b0..Trustzone settings is not locked.
 *  0b1..Trustzone settings is locked.
 */
#define CCM_LPCG_AUTHEN_LOCK_TZ(x)               (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_LOCK_TZ_SHIFT)) & CCM_LPCG_AUTHEN_LOCK_TZ_MASK)

#define CCM_LPCG_AUTHEN_LOCK_LIST_MASK           (0x8000U)
#define CCM_LPCG_AUTHEN_LOCK_LIST_SHIFT          (15U)
/*! LOCK_LIST - Lock white list
 *  0b0..White list is not locked.
 *  0b1..White list is locked.
 */
#define CCM_LPCG_AUTHEN_LOCK_LIST(x)             (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_LOCK_LIST_SHIFT)) & CCM_LPCG_AUTHEN_LOCK_LIST_MASK)

#define CCM_LPCG_AUTHEN_WHITE_LIST_MASK          (0xFFFF0000U)
#define CCM_LPCG_AUTHEN_WHITE_LIST_SHIFT         (16U)
/*! WHITE_LIST - White list */
#define CCM_LPCG_AUTHEN_WHITE_LIST(x)            (((uint32_t)(((uint32_t)(x)) << CCM_LPCG_AUTHEN_WHITE_LIST_SHIFT)) & CCM_LPCG_AUTHEN_WHITE_LIST_MASK)
/*! @} */

/* The count of CCM_LPCG_AUTHEN */
#define CCM_LPCG_AUTHEN_COUNT                    (256U)


/*!
 * @}
 */ /* end of group CCM_Register_Masks */


/* CCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE                            (0x54450000u)
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE_NS                         (0x44450000u)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL                                 ((CCM_Type *)CCM_CTRL_BASE)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL_NS                              ((CCM_Type *)CCM_CTRL_BASE_NS)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { CCM_CTRL_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { CCM_CTRL }
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS_NS                        { CCM_CTRL_BASE_NS }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS_NS                         { CCM_CTRL_NS }
#else
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE                            (0x44450000u)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL                                 ((CCM_Type *)CCM_CTRL_BASE)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { CCM_CTRL_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { CCM_CTRL }
#endif

/*!
 * @}
 */ /* end of group CCM_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_CCM_H_) */
