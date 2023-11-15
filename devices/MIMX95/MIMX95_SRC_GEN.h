/*
** ###################################################################
**     Processors:          MIMX95_cm33
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX95_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2023 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**
** ###################################################################
*/

/*!
 * @file MIMX95_SRC_GEN.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for MIMX95_SRC_GEN
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_SRC_GEN_H_)  /* Check if memory map has not been already included */
#define MIMX95_SRC_GEN_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SRC_GEN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_GEN_Peripheral_Access_Layer SRC_GEN Peripheral Access Layer
 * @{
 */

/** SRC_GEN - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t AUTHEN_CTRL;                       /**< Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t SCR;                               /**< SRC Control Register, offset: 0x10 */
  __IO uint32_t SRTMR;                             /**< SRC Reset Trigger Mode Register, offset: 0x14 */
  __IO uint32_t SRMASK;                            /**< SRC Reset Trigger Mode Mask Register, offset: 0x18 */
       uint8_t RESERVED_2[36];
  __I  uint32_t SBMR1;                             /**< SRC Boot Mode Register 1, offset: 0x40 */
  __I  uint32_t SBMR2;                             /**< SRC Boot Mode Register 2, offset: 0x44 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SMRSR;                             /**< SRC Mix Slices Reset Status Register, offset: 0x4C */
  __IO uint32_t SRESR;                             /**< SRC Reset Events Status Register, offset: 0x50 */
  __IO uint32_t GPR1;                              /**< SRC General Purpose Register 1, offset: 0x54 */
  __IO uint32_t GPR2;                              /**< SRC General Purpose Register 2, offset: 0x58 */
  __IO uint32_t GPR3;                              /**< SRC General Purpose Register 3, offset: 0x5C */
  __IO uint32_t GPR4;                              /**< SRC General Purpose Register 4, offset: 0x60 */
  __IO uint32_t GPR5;                              /**< SRC General Purpose Register 5, offset: 0x64 */
  __IO uint32_t GPR6;                              /**< SRC General Purpose Register 6, offset: 0x68 */
  __IO uint32_t GPR7;                              /**< SRC General Purpose Register 7, offset: 0x6C */
  __IO uint32_t GPR8;                              /**< SRC General Purpose Register 8, offset: 0x70 */
  __IO uint32_t GPR9;                              /**< SRC General Purpose Register 9, offset: 0x74 */
  __IO uint32_t GPR10;                             /**< SRC General Purpose Register 10, offset: 0x78 */
  __IO uint32_t GPR11;                             /**< SRC General Purpose Register 11, offset: 0x7C */
  __IO uint32_t GPR12;                             /**< SRC General Purpose Register 12, offset: 0x80 */
  __IO uint32_t GPR13;                             /**< SRC General Purpose Register 13, offset: 0x84 */
  __IO uint32_t GPR14;                             /**< SRC General Purpose Register 14, offset: 0x88 */
  __IO uint32_t GPR15;                             /**< SRC General Purpose Register 15, offset: 0x8C */
  __IO uint32_t GPR16;                             /**< SRC General Purpose Register 16, offset: 0x90 */
  __IO uint32_t GPR17;                             /**< SRC General Purpose Register 17, offset: 0x94 */
  __IO uint32_t GPR18;                             /**< SRC General Purpose Register 18, offset: 0x98 */
  __IO uint32_t GPR19;                             /**< SRC General Purpose Register 19, offset: 0x9C */
       uint8_t RESERVED_4[96];
  __IO uint32_t GPR20;                             /**< SRC General Purpose Register 20, offset: 0x100 */
  __IO uint32_t CM_QUIESCE;                        /**< SRC_CORTEX_M_QUIESCE, offset: 0x104 */
  __IO uint32_t COLD_RESET_SSAR_ACK_CTRL;          /**< Cold reset SSAR acknowledge control, offset: 0x108 */
  __IO uint32_t SP_ISO_CTRL;                       /**< SRC special ISO Control, offset: 0x10C */
  __IO uint32_t ROM_LP_CTRL;                       /**< ROM Low Power Control, offset: 0x110 */
  __I  uint32_t A55_DENY_STAT;                     /**< A55 Q_Channel Deny Status, offset: 0x114 */
  __IO uint32_t EVENT_RESET_SYSMAN_ACK_CTRL;       /**< Event Reset SYSMAN acknowledge control, offset: 0x118 */
       uint8_t RESERVED_6[4];
  __IO uint32_t SRMR[14];                          /**< SRC Reset Mode Register (SRMR), array offset: 0x120, array step: 0x4 */
} SRC_GEN_Type;

/* ----------------------------------------------------------------------------
   -- SRC_GEN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_GEN_Register_Masks SRC_GEN Register Masks
 * @{
 */

/*! @name AUTHEN_CTRL - Authentication Control */
/*! @{ */

#define SRC_GEN_AUTHEN_CTRL_LOCK_CFG_MASK (0x80U)
#define SRC_GEN_AUTHEN_CTRL_LOCK_CFG_SHIFT (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..General registers are not locked.
 *  0b1..LOCK_CFG and registers in the list are locked.
 */
#define SRC_GEN_AUTHEN_CTRL_LOCK_CFG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & SRC_GEN_AUTHEN_CTRL_LOCK_CFG_MASK)

#define SRC_GEN_AUTHEN_CTRL_TZ_USER_MASK (0x100U)
#define SRC_GEN_AUTHEN_CTRL_TZ_USER_SHIFT (8U)
/*! TZ_USER - Allow user mode access
 *  0b0..General registers can only be written in privilege mode.
 *  0b1..General registers can be written either in privilege mode or user mode.
 */
#define SRC_GEN_AUTHEN_CTRL_TZ_USER(x)   (((uint32_t)(((uint32_t)(x)) << SRC_GEN_AUTHEN_CTRL_TZ_USER_SHIFT)) & SRC_GEN_AUTHEN_CTRL_TZ_USER_MASK)

#define SRC_GEN_AUTHEN_CTRL_TZ_NS_MASK   (0x200U)
#define SRC_GEN_AUTHEN_CTRL_TZ_NS_SHIFT  (9U)
/*! TZ_NS - Allow non-secure mode access
 *  0b0..General registers can only be written in secure mode.
 *  0b1..General registers can be written either in secure mode or non-secure mode.
 */
#define SRC_GEN_AUTHEN_CTRL_TZ_NS(x)     (((uint32_t)(((uint32_t)(x)) << SRC_GEN_AUTHEN_CTRL_TZ_NS_SHIFT)) & SRC_GEN_AUTHEN_CTRL_TZ_NS_MASK)

#define SRC_GEN_AUTHEN_CTRL_LOCK_TZ_MASK (0x800U)
#define SRC_GEN_AUTHEN_CTRL_LOCK_TZ_SHIFT (11U)
/*! LOCK_TZ - Lock TZ_NS and TZ_USER bits
 *  0b0..TZ_NS and TZ_USER value can be changed.
 *  0b1..LOCK_TZ, TZ_NS and TZ_USER value cannot be changed.
 */
#define SRC_GEN_AUTHEN_CTRL_LOCK_TZ(x)   (((uint32_t)(((uint32_t)(x)) << SRC_GEN_AUTHEN_CTRL_LOCK_TZ_SHIFT)) & SRC_GEN_AUTHEN_CTRL_LOCK_TZ_MASK)

#define SRC_GEN_AUTHEN_CTRL_LOCK_LIST_MASK (0x8000U)
#define SRC_GEN_AUTHEN_CTRL_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST value can be changed.
 *  0b1..LOCK_LIST and WHITE_LIST value cannot be changed.
 */
#define SRC_GEN_AUTHEN_CTRL_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & SRC_GEN_AUTHEN_CTRL_LOCK_LIST_MASK)

#define SRC_GEN_AUTHEN_CTRL_WHITE_LIST_MASK (0xFFFF0000U)
#define SRC_GEN_AUTHEN_CTRL_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Domain ID white list
 *  0b0000000000000001..Core with domain ID=0 can write General registers.
 *  0b0000000000000010..Core with domain ID=1 can write General registers.
 *  0b0000000000000100..Core with domain ID=2 can write General registers.
 *  0b0000000000001000..Core with domain ID=3 can write General registers.
 *  0b0000000000010000..Core with domain ID=4 can write General registers.
 *  0b0000000000100000..Core with domain ID=5 can write General registers.
 *  0b0000000001000000..Core with domain ID=6 can write General registers.
 *  0b0000000010000000..Core with domain ID=7 can write General registers.
 *  0b0000000100000000..Core with domain ID=8 can write General registers.
 *  0b0000001000000000..Core with domain ID=9 can write General registers.
 *  0b0000010000000000..Core with domain ID=10 can write General registers.
 *  0b0000100000000000..Core with domain ID=11 can write General registers.
 *  0b0001000000000000..Core with domain ID=12 can write General registers.
 *  0b0010000000000000..Core with domain ID=13 can write General registers.
 *  0b0100000000000000..Core with domain ID=14 can write General registers.
 *  0b1000000000000000..Core with domain ID=15 can write General registers.
 */
#define SRC_GEN_AUTHEN_CTRL_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & SRC_GEN_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name SCR - SRC Control Register */
/*! @{ */

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_M33_MASK (0x1U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_M33_SHIFT (0U)
/*! Boot_reset_release_M33 - If A55 boot, the CM33 will be held under reset until boot core writes
 *    this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_M33(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_M33_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_M33_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU0_MASK (0x2U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU0_SHIFT (1U)
/*! Boot_reset_release_A55_CPU0 - If M33 boot, the CA55 CPU0 will be held under reset until boot
 *    core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU0(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU0_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU0_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU1_MASK (0x4U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU1_SHIFT (2U)
/*! Boot_reset_release_A55_CPU1 - If M33 boot, the CA55 CPU1 will be held under reset until boot
 *    core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU1(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU1_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU1_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU2_MASK (0x8U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU2_SHIFT (3U)
/*! Boot_reset_release_A55_CPU2 - If M33 boot, the CA55 CPU2 will be held under reset until boot
 *    core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU2(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU2_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU2_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU3_MASK (0x10U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU3_SHIFT (4U)
/*! Boot_reset_release_A55_CPU3 - If M33 boot, the CA55 CPU3 will be held under reset until boot
 *    core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU3(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU3_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU3_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU4_MASK (0x20U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU4_SHIFT (5U)
/*! Boot_reset_release_A55_CPU4 - If M33 boot, the CA55 CPU4 will be held under reset until boot
 *    core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU4(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU4_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU4_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU5_MASK (0x40U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU5_SHIFT (6U)
/*! Boot_reset_release_A55_CPU5 - If M33 boot, the CA55 CPU5 will be held under reset until boot
 *    core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU5(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU5_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_CPU5_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_PLAT_MASK (0x80U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_PLAT_SHIFT (7U)
/*! Boot_reset_release_A55_PLAT - If M33 boot, the CA55 Platform will be held under reset until boot
 *    core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_PLAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_PLAT_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_A55_PLAT_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_CAMERAMIX_MASK (0x100U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_CAMERAMIX_SHIFT (8U)
/*! Boot_reset_release_CAMERAMIX - CAMERAMIX will be held under reset until boot core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_CAMERAMIX(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_CAMERAMIX_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_CAMERAMIX_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_DDRMIX_MASK (0x200U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_DDRMIX_SHIFT (9U)
/*! Boot_reset_release_DDRMIX - If M33 boot, the DDRMIX will be held under reset until boot core
 *    writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_DDRMIX(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_DDRMIX_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_DDRMIX_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_DISPLAYMIX_MASK (0x400U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_DISPLAYMIX_SHIFT (10U)
/*! Boot_reset_release_DISPLAYMIX - DISPLAYMIX will be held under reset until boot core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_DISPLAYMIX(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_DISPLAYMIX_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_DISPLAYMIX_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_GPUMIX_MASK (0x800U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_GPUMIX_SHIFT (11U)
/*! Boot_reset_release_GPUMIX - GPUMIX will be held under reset until boot core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_GPUMIX(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_GPUMIX_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_GPUMIX_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_M7MIX_MASK (0x1000U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_M7MIX_SHIFT (12U)
/*! Boot_reset_release_M7MIX - M7MIX will be held under reset until boot core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_M7MIX(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_M7MIX_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_M7MIX_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_NETCMIX_MASK (0x2000U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_NETCMIX_SHIFT (13U)
/*! Boot_reset_release_NETCMIX - NETCMIX will be held under reset until boot core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_NETCMIX(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_NETCMIX_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_NETCMIX_MASK)

#define SRC_GEN_SCR_BOOT_RESET_RELEASE_VPUMIX_MASK (0x4000U)
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_VPUMIX_SHIFT (14U)
/*! Boot_reset_release_VPUMIX - VPUMIX will be held under reset until boot core writes this bit to 1. Once this bit is set to 1, it will be locked.
 *  0b0..Hold reset.
 *  0b1..Release reset.
 */
#define SRC_GEN_SCR_BOOT_RESET_RELEASE_VPUMIX(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SCR_BOOT_RESET_RELEASE_VPUMIX_SHIFT)) & SRC_GEN_SCR_BOOT_RESET_RELEASE_VPUMIX_MASK)
/*! @} */

/*! @name SRTMR - SRC Reset Trigger Mode Register */
/*! @{ */

#define SRC_GEN_SRTMR_RST_EVT_0_MODE_MASK (0x1U)
#define SRC_GEN_SRTMR_RST_EVT_0_MODE_SHIFT (0U)
/*! RST_EVT_0_MODE - mode configuration bit for reset event CM33_LOCKUP_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as CM33_LOCKUP_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when CM33_LOCKUP_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_0_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_0_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_0_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_1_MODE_MASK (0x2U)
#define SRC_GEN_SRTMR_RST_EVT_1_MODE_SHIFT (1U)
/*! RST_EVT_1_MODE - mode configuration bit for reset event CM33_SYS_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as CM33_SYS_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when CM33_SYS_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_1_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_1_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_1_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_2_MODE_MASK (0x4U)
#define SRC_GEN_SRTMR_RST_EVT_2_MODE_SHIFT (2U)
/*! RST_EVT_2_MODE - mode configuration bit for reset event CM7_LOCKUP_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as CM7_LOCKUP_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when CM7_LOCKUP_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_2_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_2_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_2_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_3_MODE_MASK (0x8U)
#define SRC_GEN_SRTMR_RST_EVT_3_MODE_SHIFT (3U)
/*! RST_EVT_3_MODE - mode configuration bit for reset event CM7_SYS_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as CM7_SYS_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when CM7_SYS_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_3_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_3_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_3_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_4_MODE_MASK (0x10U)
#define SRC_GEN_SRTMR_RST_EVT_4_MODE_SHIFT (4U)
/*! RST_EVT_4_MODE - mode configuration bit for reset event FCCU_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as FCCU_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when FCCU_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_4_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_4_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_4_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_5_MODE_MASK (0x20U)
#define SRC_GEN_SRTMR_RST_EVT_5_MODE_SHIFT (5U)
/*! RST_EVT_5_MODE - mode configuration bit for reset event JTAG_SW_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as JTAG_SW_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when JTAG_SW_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_5_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_5_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_5_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_6_MODE_MASK (0x40U)
#define SRC_GEN_SRTMR_RST_EVT_6_MODE_SHIFT (6U)
/*! RST_EVT_6_MODE - mode configuration bit for reset event SENTINEL_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as SENTINEL_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when SENTINEL_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_6_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_6_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_6_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_7_MODE_MASK (0x80U)
#define SRC_GEN_SRTMR_RST_EVT_7_MODE_SHIFT (7U)
/*! RST_EVT_7_MODE - mode configuration bit for reset event TEMPSENSE_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as TEMPSENSE_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when TEMPSENSE_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_7_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_7_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_7_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_8_MODE_MASK (0x100U)
#define SRC_GEN_SRTMR_RST_EVT_8_MODE_SHIFT (8U)
/*! RST_EVT_8_MODE - mode configuration bit for reset event WDOG1_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as WDOG1_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when WDOG1_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_8_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_8_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_8_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_9_MODE_MASK (0x200U)
#define SRC_GEN_SRTMR_RST_EVT_9_MODE_SHIFT (9U)
/*! RST_EVT_9_MODE - mode configuration bit for reset event WDOG2_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as WDOG2_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when WDOG2_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_9_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_9_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_9_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_10_MODE_MASK (0x400U)
#define SRC_GEN_SRTMR_RST_EVT_10_MODE_SHIFT (10U)
/*! RST_EVT_10_MODE - mode configuration bit for reset event WDOG3_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as WDOG3_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when WDOG3_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_10_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_10_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_10_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_11_MODE_MASK (0x800U)
#define SRC_GEN_SRTMR_RST_EVT_11_MODE_SHIFT (11U)
/*! RST_EVT_11_MODE - mode configuration bit for reset event WDOG4_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as WDOG4_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when WDOG4_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_11_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_11_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_11_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_12_MODE_MASK (0x1000U)
#define SRC_GEN_SRTMR_RST_EVT_12_MODE_SHIFT (12U)
/*! RST_EVT_12_MODE - mode configuration bit for reset event WDOG5_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as WDOG5_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when WDOG5_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_12_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_12_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_12_MODE_MASK)

#define SRC_GEN_SRTMR_RST_EVT_13_MODE_MASK (0x2000U)
#define SRC_GEN_SRTMR_RST_EVT_13_MODE_SHIFT (13U)
/*! RST_EVT_13_MODE - mode configuration bit for reset event JTAG_RST_B_RST_EVT
 *  0b0..level mode : affected region enters and stays in reset as long as JTAG_RST_B_RST_EVT is active
 *  0b1..edge mode : affected region enters reset when JTAG_RST_B_RST_EVT becomes active and will leave reset even if event is active
 */
#define SRC_GEN_SRTMR_RST_EVT_13_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRTMR_RST_EVT_13_MODE_SHIFT)) & SRC_GEN_SRTMR_RST_EVT_13_MODE_MASK)
/*! @} */

/*! @name SRMASK - SRC Reset Trigger Mode Mask Register */
/*! @{ */

#define SRC_GEN_SRMASK_RST_EVT_0_MASK_MASK (0x1U)
#define SRC_GEN_SRMASK_RST_EVT_0_MASK_SHIFT (0U)
/*! RST_EVT_0_MASK - mask bit for reset event CM33_LOCKUP_RST_EVT
 *  0b0..reset event CM33_LOCKUP_RST_EVT is not masked
 *  0b1..reset event CM33_LOCKUP_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_0_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_0_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_0_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_1_MASK_MASK (0x2U)
#define SRC_GEN_SRMASK_RST_EVT_1_MASK_SHIFT (1U)
/*! RST_EVT_1_MASK - mask bit for reset event CM33_SYS_RST_EVT
 *  0b0..reset event CM33_SYS_RST_EVT is not masked
 *  0b1..reset event CM33_SYS_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_1_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_1_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_1_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_2_MASK_MASK (0x4U)
#define SRC_GEN_SRMASK_RST_EVT_2_MASK_SHIFT (2U)
/*! RST_EVT_2_MASK - mask bit for reset event CM7_LOCKUP_RST_EVT
 *  0b0..reset event CM7_LOCKUP_RST_EVT is not masked
 *  0b1..reset event CM7_LOCKUP_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_2_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_2_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_2_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_3_MASK_MASK (0x8U)
#define SRC_GEN_SRMASK_RST_EVT_3_MASK_SHIFT (3U)
/*! RST_EVT_3_MASK - mask bit for reset event CM7_SYS_RST_EVT
 *  0b0..reset event CM7_SYS_RST_EVT is not masked
 *  0b1..reset event CM7_SYS_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_3_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_3_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_3_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_4_MASK_MASK (0x10U)
#define SRC_GEN_SRMASK_RST_EVT_4_MASK_SHIFT (4U)
/*! RST_EVT_4_MASK - mask bit for reset event FCCU_RST_EVT
 *  0b0..reset event FCCU_RST_EVT is not masked
 *  0b1..reset event FCCU_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_4_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_4_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_4_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_5_MASK_MASK (0x20U)
#define SRC_GEN_SRMASK_RST_EVT_5_MASK_SHIFT (5U)
/*! RST_EVT_5_MASK - mask bit for reset event JTAG_SW_RST_EVT
 *  0b0..reset event JTAG_SW_RST_EVT is not masked
 *  0b1..reset event JTAG_SW_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_5_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_5_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_5_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_6_MASK_MASK (0x40U)
#define SRC_GEN_SRMASK_RST_EVT_6_MASK_SHIFT (6U)
/*! RST_EVT_6_MASK - mask bit for reset event SENTINEL_RST_EVT
 *  0b0..reset event SENTINEL_RST_EVT is not masked
 *  0b1..reset event SENTINEL_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_6_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_6_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_6_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_7_MASK_MASK (0x80U)
#define SRC_GEN_SRMASK_RST_EVT_7_MASK_SHIFT (7U)
/*! RST_EVT_7_MASK - mask bit for reset event TEMPSENSE_RST_EVT
 *  0b0..reset event TEMPSENSE_RST_EVT is not masked
 *  0b1..reset event TEMPSENSE_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_7_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_7_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_7_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_8_MASK_MASK (0x100U)
#define SRC_GEN_SRMASK_RST_EVT_8_MASK_SHIFT (8U)
/*! RST_EVT_8_MASK - mask bit for reset event WDOG1_RST_EVT
 *  0b0..reset event WDOG1_RST_EVT is not masked
 *  0b1..reset event WDOG1_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_8_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_8_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_8_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_9_MASK_MASK (0x200U)
#define SRC_GEN_SRMASK_RST_EVT_9_MASK_SHIFT (9U)
/*! RST_EVT_9_MASK - mask bit for reset event WDOG2_RST_EVT
 *  0b0..reset event WDOG2_RST_EVT is not masked
 *  0b1..reset event WDOG2_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_9_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_9_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_9_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_10_MASK_MASK (0x400U)
#define SRC_GEN_SRMASK_RST_EVT_10_MASK_SHIFT (10U)
/*! RST_EVT_10_MASK - mask bit for reset event WDOG3_RST_EVT
 *  0b0..reset event WDOG3_RST_EVT is not masked
 *  0b1..reset event WDOG3_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_10_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_10_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_10_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_11_MASK_MASK (0x800U)
#define SRC_GEN_SRMASK_RST_EVT_11_MASK_SHIFT (11U)
/*! RST_EVT_11_MASK - mask bit for reset event WDOG4_RST_EVT
 *  0b0..reset event WDOG4_RST_EVT is not masked
 *  0b1..reset event WDOG4_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_11_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_11_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_11_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_12_MASK_MASK (0x1000U)
#define SRC_GEN_SRMASK_RST_EVT_12_MASK_SHIFT (12U)
/*! RST_EVT_12_MASK - mask bit for reset event WDOG5_RST_EVT
 *  0b0..reset event WDOG5_RST_EVT is not masked
 *  0b1..reset event WDOG5_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_12_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_12_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_12_MASK_MASK)

#define SRC_GEN_SRMASK_RST_EVT_13_MASK_MASK (0x2000U)
#define SRC_GEN_SRMASK_RST_EVT_13_MASK_SHIFT (13U)
/*! RST_EVT_13_MASK - mask bit for reset event JTAG_RST_B_RST_EVT
 *  0b0..reset event JTAG_RST_B_RST_EVT is not masked
 *  0b1..reset event JTAG_RST_B_RST_EVT is masked
 */
#define SRC_GEN_SRMASK_RST_EVT_13_MASK(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMASK_RST_EVT_13_MASK_SHIFT)) & SRC_GEN_SRMASK_RST_EVT_13_MASK_MASK)
/*! @} */

/*! @name SBMR1 - SRC Boot Mode Register 1 */
/*! @{ */

#define SRC_GEN_SBMR1_BOOT_CFG0_MASK     (0xFFFFFFFFU)
#define SRC_GEN_SBMR1_BOOT_CFG0_SHIFT    (0U)
/*! BOOT_CFG0 - This bit field stores the BOOT_CFG8 fuse values. Please refer to the Fusemap for the fuse details. */
#define SRC_GEN_SBMR1_BOOT_CFG0(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SBMR1_BOOT_CFG0_SHIFT)) & SRC_GEN_SBMR1_BOOT_CFG0_MASK)
/*! @} */

/*! @name SBMR2 - SRC Boot Mode Register 2 */
/*! @{ */

#define SRC_GEN_SBMR2_BOOT_CFG1_MASK     (0xFFFFU)
#define SRC_GEN_SBMR2_BOOT_CFG1_SHIFT    (0U)
/*! BOOT_CFG1 - This bit field stores the BOOT_CFG0[15:0] fuse values. Please refer to the Fusemap for the fuse details. */
#define SRC_GEN_SBMR2_BOOT_CFG1(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SBMR2_BOOT_CFG1_SHIFT)) & SRC_GEN_SBMR2_BOOT_CFG1_MASK)

#define SRC_GEN_SBMR2_SDP_DIS_MASK       (0x10000U)
#define SRC_GEN_SBMR2_SDP_DIS_SHIFT      (16U)
/*! SDP_DIS - Stores the value of SDP_DIS from fusemap. Please see the fusemap for fuse details. */
#define SRC_GEN_SBMR2_SDP_DIS(x)         (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SBMR2_SDP_DIS_SHIFT)) & SRC_GEN_SBMR2_SDP_DIS_MASK)

#define SRC_GEN_SBMR2_BOOT_CFG2_MASK     (0x3C0000U)
#define SRC_GEN_SBMR2_BOOT_CFG2_SHIFT    (18U)
/*! BOOT_CFG2 - This bit field stores the BOOT_CFG0[31:28] fuse values. Please refer to the Fusemap for the fuse details. */
#define SRC_GEN_SBMR2_BOOT_CFG2(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SBMR2_BOOT_CFG2_SHIFT)) & SRC_GEN_SBMR2_BOOT_CFG2_MASK)

#define SRC_GEN_SBMR2_CCMSRCGPCMIX_BLK_CTRL_MASK (0xC00000U)
#define SRC_GEN_SBMR2_CCMSRCGPCMIX_BLK_CTRL_SHIFT (22U)
/*! CCMSRCGPCMIX_BLK_CTRL - Stores the value of CCMSRCGPCMIX_BLK_CTRL[1:0] from fusemap. Please see the fusemap for fuse details. */
#define SRC_GEN_SBMR2_CCMSRCGPCMIX_BLK_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SBMR2_CCMSRCGPCMIX_BLK_CTRL_SHIFT)) & SRC_GEN_SBMR2_CCMSRCGPCMIX_BLK_CTRL_MASK)

#define SRC_GEN_SBMR2_IPP_BOOT_MODE_MASK (0x3F000000U)
#define SRC_GEN_SBMR2_IPP_BOOT_MODE_SHIFT (24U)
/*! IPP_BOOT_MODE - Boot mode from pins */
#define SRC_GEN_SBMR2_IPP_BOOT_MODE(x)   (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SBMR2_IPP_BOOT_MODE_SHIFT)) & SRC_GEN_SBMR2_IPP_BOOT_MODE_MASK)

#define SRC_GEN_SBMR2_DIR_BT_DIS_MASK    (0x80000000U)
#define SRC_GEN_SBMR2_DIR_BT_DIS_SHIFT   (31U)
/*! DIR_BT_DIS - Stores the value of DIR_BT_DIS from fusemap. Please see the fusemap for fuse details. */
#define SRC_GEN_SBMR2_DIR_BT_DIS(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SBMR2_DIR_BT_DIS_SHIFT)) & SRC_GEN_SBMR2_DIR_BT_DIS_MASK)
/*! @} */

/*! @name SMRSR - SRC Mix Slices Reset Status Register */
/*! @{ */

#define SRC_GEN_SMRSR_RESET_DOMAIN_FLAG_MASK (0x1FFFFFFU)
#define SRC_GEN_SMRSR_RESET_DOMAIN_FLAG_SHIFT (0U)
/*! RESET_DOMAIN_FLAG - Indicates which reset event request asserted the reset */
#define SRC_GEN_SMRSR_RESET_DOMAIN_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SMRSR_RESET_DOMAIN_FLAG_SHIFT)) & SRC_GEN_SMRSR_RESET_DOMAIN_FLAG_MASK)
/*! @} */

/*! @name SRESR - SRC Reset Events Status Register */
/*! @{ */

#define SRC_GEN_SRESR_SRC_POR_B_FLAG_MASK (0x1U)
#define SRC_GEN_SRESR_SRC_POR_B_FLAG_SHIFT (0U)
/*! SRC_POR_B_FLAG - Indicates whether the reset was the result of the system_por_b
 *  0b0..Reset is not asserted by system_por_b
 *  0b1..Reset is asserted by system_por_b
 */
#define SRC_GEN_SRESR_SRC_POR_B_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_SRC_POR_B_FLAG_SHIFT)) & SRC_GEN_SRESR_SRC_POR_B_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_0_FLAG_MASK (0x2U)
#define SRC_GEN_SRESR_RST_EVT_0_FLAG_SHIFT (1U)
/*! RST_EVT_0_FLAG - indicates if reset event CM33_LOCKUP_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_0_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_0_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_0_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_1_FLAG_MASK (0x4U)
#define SRC_GEN_SRESR_RST_EVT_1_FLAG_SHIFT (2U)
/*! RST_EVT_1_FLAG - indicates if reset event CM33_SYS_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_1_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_1_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_1_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_2_FLAG_MASK (0x8U)
#define SRC_GEN_SRESR_RST_EVT_2_FLAG_SHIFT (3U)
/*! RST_EVT_2_FLAG - indicates if reset event CM7_LOCKUP_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_2_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_2_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_2_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_3_FLAG_MASK (0x10U)
#define SRC_GEN_SRESR_RST_EVT_3_FLAG_SHIFT (4U)
/*! RST_EVT_3_FLAG - indicates if reset event CM7_SYS_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_3_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_3_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_3_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_4_FLAG_MASK (0x20U)
#define SRC_GEN_SRESR_RST_EVT_4_FLAG_SHIFT (5U)
/*! RST_EVT_4_FLAG - indicates if reset event FCCU_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_4_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_4_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_4_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_5_FLAG_MASK (0x40U)
#define SRC_GEN_SRESR_RST_EVT_5_FLAG_SHIFT (6U)
/*! RST_EVT_5_FLAG - indicates if reset event JTAG_SW_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_5_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_5_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_5_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_6_FLAG_MASK (0x80U)
#define SRC_GEN_SRESR_RST_EVT_6_FLAG_SHIFT (7U)
/*! RST_EVT_6_FLAG - indicates if reset event SENTINEL_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_6_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_6_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_6_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_7_FLAG_MASK (0x100U)
#define SRC_GEN_SRESR_RST_EVT_7_FLAG_SHIFT (8U)
/*! RST_EVT_7_FLAG - indicates if reset event TEMPSENSE_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_7_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_7_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_7_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_8_FLAG_MASK (0x200U)
#define SRC_GEN_SRESR_RST_EVT_8_FLAG_SHIFT (9U)
/*! RST_EVT_8_FLAG - indicates if reset event WDOG1_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_8_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_8_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_8_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_9_FLAG_MASK (0x400U)
#define SRC_GEN_SRESR_RST_EVT_9_FLAG_SHIFT (10U)
/*! RST_EVT_9_FLAG - indicates if reset event WDOG2_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_9_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_9_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_9_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_10_FLAG_MASK (0x800U)
#define SRC_GEN_SRESR_RST_EVT_10_FLAG_SHIFT (11U)
/*! RST_EVT_10_FLAG - indicates if reset event WDOG3_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_10_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_10_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_10_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_11_FLAG_MASK (0x1000U)
#define SRC_GEN_SRESR_RST_EVT_11_FLAG_SHIFT (12U)
/*! RST_EVT_11_FLAG - indicates if reset event WDOG4_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_11_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_11_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_11_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_12_FLAG_MASK (0x2000U)
#define SRC_GEN_SRESR_RST_EVT_12_FLAG_SHIFT (13U)
/*! RST_EVT_12_FLAG - indicates if reset event WDOG5_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_12_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_12_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_12_FLAG_MASK)

#define SRC_GEN_SRESR_RST_EVT_13_FLAG_MASK (0x4000U)
#define SRC_GEN_SRESR_RST_EVT_13_FLAG_SHIFT (14U)
/*! RST_EVT_13_FLAG - indicates if reset event JTAG_RST_B_RST_EVT has been occurecd
 *  0b0..did not occure
 *  0b1..reset event occurec
 */
#define SRC_GEN_SRESR_RST_EVT_13_FLAG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRESR_RST_EVT_13_FLAG_SHIFT)) & SRC_GEN_SRESR_RST_EVT_13_FLAG_MASK)
/*! @} */

/*! @name GPR1 - SRC General Purpose Register 1 */
/*! @{ */

#define SRC_GEN_GPR1_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GEN_GPR1_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR1_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR1_GPR_SHIFT)) & SRC_GEN_GPR1_GPR_MASK)
/*! @} */

/*! @name GPR2 - SRC General Purpose Register 2 */
/*! @{ */

#define SRC_GEN_GPR2_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GEN_GPR2_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR2_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR2_GPR_SHIFT)) & SRC_GEN_GPR2_GPR_MASK)
/*! @} */

/*! @name GPR3 - SRC General Purpose Register 3 */
/*! @{ */

#define SRC_GEN_GPR3_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GEN_GPR3_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR3_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR3_GPR_SHIFT)) & SRC_GEN_GPR3_GPR_MASK)
/*! @} */

/*! @name GPR4 - SRC General Purpose Register 4 */
/*! @{ */

#define SRC_GEN_GPR4_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GEN_GPR4_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR4_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR4_GPR_SHIFT)) & SRC_GEN_GPR4_GPR_MASK)
/*! @} */

/*! @name GPR5 - SRC General Purpose Register 5 */
/*! @{ */

#define SRC_GEN_GPR5_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GEN_GPR5_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR5_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR5_GPR_SHIFT)) & SRC_GEN_GPR5_GPR_MASK)
/*! @} */

/*! @name GPR6 - SRC General Purpose Register 6 */
/*! @{ */

#define SRC_GEN_GPR6_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GEN_GPR6_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR6_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR6_GPR_SHIFT)) & SRC_GEN_GPR6_GPR_MASK)
/*! @} */

/*! @name GPR7 - SRC General Purpose Register 7 */
/*! @{ */

#define SRC_GEN_GPR7_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GEN_GPR7_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR7_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR7_GPR_SHIFT)) & SRC_GEN_GPR7_GPR_MASK)
/*! @} */

/*! @name GPR8 - SRC General Purpose Register 8 */
/*! @{ */

#define SRC_GEN_GPR8_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GEN_GPR8_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR8_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR8_GPR_SHIFT)) & SRC_GEN_GPR8_GPR_MASK)
/*! @} */

/*! @name GPR9 - SRC General Purpose Register 9 */
/*! @{ */

#define SRC_GEN_GPR9_GPR_MASK            (0xFFFFFFFFU)
#define SRC_GEN_GPR9_GPR_SHIFT           (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR9_GPR(x)              (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR9_GPR_SHIFT)) & SRC_GEN_GPR9_GPR_MASK)
/*! @} */

/*! @name GPR10 - SRC General Purpose Register 10 */
/*! @{ */

#define SRC_GEN_GPR10_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GEN_GPR10_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR10_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR10_GPR_SHIFT)) & SRC_GEN_GPR10_GPR_MASK)
/*! @} */

/*! @name GPR11 - SRC General Purpose Register 11 */
/*! @{ */

#define SRC_GEN_GPR11_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GEN_GPR11_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR11_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR11_GPR_SHIFT)) & SRC_GEN_GPR11_GPR_MASK)
/*! @} */

/*! @name GPR12 - SRC General Purpose Register 12 */
/*! @{ */

#define SRC_GEN_GPR12_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GEN_GPR12_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR12_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR12_GPR_SHIFT)) & SRC_GEN_GPR12_GPR_MASK)
/*! @} */

/*! @name GPR13 - SRC General Purpose Register 13 */
/*! @{ */

#define SRC_GEN_GPR13_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GEN_GPR13_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR13_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR13_GPR_SHIFT)) & SRC_GEN_GPR13_GPR_MASK)
/*! @} */

/*! @name GPR14 - SRC General Purpose Register 14 */
/*! @{ */

#define SRC_GEN_GPR14_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GEN_GPR14_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR14_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR14_GPR_SHIFT)) & SRC_GEN_GPR14_GPR_MASK)
/*! @} */

/*! @name GPR15 - SRC General Purpose Register 15 */
/*! @{ */

#define SRC_GEN_GPR15_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GEN_GPR15_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR15_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR15_GPR_SHIFT)) & SRC_GEN_GPR15_GPR_MASK)
/*! @} */

/*! @name GPR16 - SRC General Purpose Register 16 */
/*! @{ */

#define SRC_GEN_GPR16_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GEN_GPR16_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR16_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR16_GPR_SHIFT)) & SRC_GEN_GPR16_GPR_MASK)
/*! @} */

/*! @name GPR17 - SRC General Purpose Register 17 */
/*! @{ */

#define SRC_GEN_GPR17_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GEN_GPR17_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR17_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR17_GPR_SHIFT)) & SRC_GEN_GPR17_GPR_MASK)
/*! @} */

/*! @name GPR18 - SRC General Purpose Register 18 */
/*! @{ */

#define SRC_GEN_GPR18_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GEN_GPR18_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR18_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR18_GPR_SHIFT)) & SRC_GEN_GPR18_GPR_MASK)
/*! @} */

/*! @name GPR19 - SRC General Purpose Register 19 */
/*! @{ */

#define SRC_GEN_GPR19_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GEN_GPR19_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR19_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR19_GPR_SHIFT)) & SRC_GEN_GPR19_GPR_MASK)
/*! @} */

/*! @name GPR20 - SRC General Purpose Register 20 */
/*! @{ */

#define SRC_GEN_GPR20_GPR_MASK           (0xFFFFFFFFU)
#define SRC_GEN_GPR20_GPR_SHIFT          (0U)
/*! GPR - General purpose register */
#define SRC_GEN_GPR20_GPR(x)             (((uint32_t)(((uint32_t)(x)) << SRC_GEN_GPR20_GPR_SHIFT)) & SRC_GEN_GPR20_GPR_MASK)
/*! @} */

/*! @name CM_QUIESCE - SRC_CORTEX_M_QUIESCE */
/*! @{ */

#define SRC_GEN_CM_QUIESCE_SAFE_CM33_AHB_REQ_MASK (0x1U)
#define SRC_GEN_CM_QUIESCE_SAFE_CM33_AHB_REQ_SHIFT (0U)
/*! SAFE_CM33_AHB_REQ - CM33 platform safe reset req control
 *  0b0..No effect
 *  0b1..request CM33 platform to be reset at safe state
 */
#define SRC_GEN_CM_QUIESCE_SAFE_CM33_AHB_REQ(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_CM_QUIESCE_SAFE_CM33_AHB_REQ_SHIFT)) & SRC_GEN_CM_QUIESCE_SAFE_CM33_AHB_REQ_MASK)

#define SRC_GEN_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_MASK (0x2U)
#define SRC_GEN_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_SHIFT (1U)
/*! SAFE_CM33_AHB_ACK_STAT - CM33 platform safe reset ahb ack status
 *  0b0..No CM33 platform safe reset req or it could not be placed in safe state for reset sequencing
 *  0b1..CM33 platform is in safe state for reset sequencing
 */
#define SRC_GEN_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_SHIFT)) & SRC_GEN_CM_QUIESCE_SAFE_CM33_AHB_ACK_STAT_MASK)
/*! @} */

/*! @name COLD_RESET_SSAR_ACK_CTRL - Cold reset SSAR acknowledge control */
/*! @{ */

#define SRC_GEN_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_MASK (0x3FFFU)
#define SRC_GEN_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_SHIFT (0U)
/*! SSAR_CNT_CFG - ssar count configure. Usage depends on CNT_MODE, locked by LOCK_CFG field */
#define SRC_GEN_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_SHIFT)) & SRC_GEN_COLD_RESET_SSAR_ACK_CTRL_SSAR_CNT_CFG_MASK)

#define SRC_GEN_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_MASK (0xC0000000U)
#define SRC_GEN_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_SHIFT (30U)
/*! CNT_MODE - Configure the acknowledge counter working mode. Locked by LOCK_CFG field
 *  0b00..Not use counter, raise done to cold_reset_controller once get EdgeLock Enclave ack
 *  0b01..Delay after receiving EdgeLock Enclave ack, delay cycle number is CNT_CFG
 *  0b10..Ignore EdgeLock Enclave ack, raise done to cold_reset_controller when counting to CNT_CFG value
 *  0b11..Time out mode, raise done to cold_reset_controller when either EdgeLock Enclave ack received or counting to CNT_CFG value
 */
#define SRC_GEN_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_SHIFT)) & SRC_GEN_COLD_RESET_SSAR_ACK_CTRL_CNT_MODE_MASK)
/*! @} */

/*! @name ROM_LP_CTRL - ROM Low Power Control */
/*! @{ */

#define SRC_GEN_ROM_LP_CTRL_AONMIX_ROM_LP_EN_MASK (0x1U)
#define SRC_GEN_ROM_LP_CTRL_AONMIX_ROM_LP_EN_SHIFT (0U)
/*! AONMIX_ROM_LP_EN - Low power control enable for ROM in AONMIX */
#define SRC_GEN_ROM_LP_CTRL_AONMIX_ROM_LP_EN(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_ROM_LP_CTRL_AONMIX_ROM_LP_EN_SHIFT)) & SRC_GEN_ROM_LP_CTRL_AONMIX_ROM_LP_EN_MASK)
/*! @} */

/*! @name A55_DENY_STAT - A55 Q_Channel Deny Status */
/*! @{ */

#define SRC_GEN_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_MASK (0x1U)
#define SRC_GEN_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_SHIFT (0U)
/*! A55_CORE0_PWRDN_DENY_STAT - A55 CORE 0 Q_Channel pwrdn deny status */
#define SRC_GEN_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_SHIFT)) & SRC_GEN_A55_DENY_STAT_A55_CORE0_PWRDN_DENY_STAT_MASK)

#define SRC_GEN_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_MASK (0x2U)
#define SRC_GEN_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_SHIFT (1U)
/*! A55_CORE1_PWRDN_DENY_STAT - A55 CORE 1 Q_Channel pwrdn deny status */
#define SRC_GEN_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_SHIFT)) & SRC_GEN_A55_DENY_STAT_A55_CORE1_PWRDN_DENY_STAT_MASK)

#define SRC_GEN_A55_DENY_STAT_A55_CORE2_PWRDN_DENY_STAT_MASK (0x4U)
#define SRC_GEN_A55_DENY_STAT_A55_CORE2_PWRDN_DENY_STAT_SHIFT (2U)
/*! A55_CORE2_PWRDN_DENY_STAT - A55 CORE 2 Q_Channel pwrdn deny status */
#define SRC_GEN_A55_DENY_STAT_A55_CORE2_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_A55_DENY_STAT_A55_CORE2_PWRDN_DENY_STAT_SHIFT)) & SRC_GEN_A55_DENY_STAT_A55_CORE2_PWRDN_DENY_STAT_MASK)

#define SRC_GEN_A55_DENY_STAT_A55_CORE3_PWRDN_DENY_STAT_MASK (0x8U)
#define SRC_GEN_A55_DENY_STAT_A55_CORE3_PWRDN_DENY_STAT_SHIFT (3U)
/*! A55_CORE3_PWRDN_DENY_STAT - A55 CORE 3 Q_Channel pwrdn deny status */
#define SRC_GEN_A55_DENY_STAT_A55_CORE3_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_A55_DENY_STAT_A55_CORE3_PWRDN_DENY_STAT_SHIFT)) & SRC_GEN_A55_DENY_STAT_A55_CORE3_PWRDN_DENY_STAT_MASK)

#define SRC_GEN_A55_DENY_STAT_A55_CORE4_PWRDN_DENY_STAT_MASK (0x10U)
#define SRC_GEN_A55_DENY_STAT_A55_CORE4_PWRDN_DENY_STAT_SHIFT (4U)
/*! A55_CORE4_PWRDN_DENY_STAT - A55 CORE 4 Q_Channel pwrdn deny status */
#define SRC_GEN_A55_DENY_STAT_A55_CORE4_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_A55_DENY_STAT_A55_CORE4_PWRDN_DENY_STAT_SHIFT)) & SRC_GEN_A55_DENY_STAT_A55_CORE4_PWRDN_DENY_STAT_MASK)

#define SRC_GEN_A55_DENY_STAT_A55_CORE5_PWRDN_DENY_STAT_MASK (0x20U)
#define SRC_GEN_A55_DENY_STAT_A55_CORE5_PWRDN_DENY_STAT_SHIFT (5U)
/*! A55_CORE5_PWRDN_DENY_STAT - A55 CORE 5 Q_Channel pwrdn deny status */
#define SRC_GEN_A55_DENY_STAT_A55_CORE5_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_A55_DENY_STAT_A55_CORE5_PWRDN_DENY_STAT_SHIFT)) & SRC_GEN_A55_DENY_STAT_A55_CORE5_PWRDN_DENY_STAT_MASK)

#define SRC_GEN_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_MASK (0x40U)
#define SRC_GEN_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_SHIFT (6U)
/*! A55_CLUSTER_PWRDN_DENY_STAT - A55 Cluster Q_Channel pwrdn deny status */
#define SRC_GEN_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_SHIFT)) & SRC_GEN_A55_DENY_STAT_A55_CLUSTER_PWRDN_DENY_STAT_MASK)

#define SRC_GEN_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_MASK (0x80U)
#define SRC_GEN_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_SHIFT (7U)
/*! A55_CLUSTER_CLKOFF_DENY_STAT - A55 Cluster Q_Channel clockoff deny status */
#define SRC_GEN_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_SHIFT)) & SRC_GEN_A55_DENY_STAT_A55_CLUSTER_CLKOFF_DENY_STAT_MASK)
/*! @} */

/*! @name EVENT_RESET_SYSMAN_ACK_CTRL - Event Reset SYSMAN acknowledge control */
/*! @{ */

#define SRC_GEN_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_CFG_MASK (0xFFU)
#define SRC_GEN_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_CFG_SHIFT (0U)
/*! CNT_CFG - sysman count configure. Usage depends on CNT_MODE, locked by LOCK_CFG field */
#define SRC_GEN_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_CFG_SHIFT)) & SRC_GEN_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_CFG_MASK)

#define SRC_GEN_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_MODE_MASK (0xC0000000U)
#define SRC_GEN_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_MODE_SHIFT (30U)
/*! CNT_MODE - Configure the acknowledge counter working mode. Locked by LOCK_CFG field
 *  0b00..Not use counter, raise done to cold_reset_controller once get EdgeLock Enclave ack
 *  0b01..Delay after receiving EdgeLock Enclave ack, delay cycle number is CNT_CFG
 *  0b10..Ignore EdgeLock Enclave ack, raise done to cold_reset_controller when counting to CNT_CFG value
 *  0b11..Time out mode, raise done to cold_reset_controller when either EdgeLock Enclave ack received or counting to CNT_CFG value
 */
#define SRC_GEN_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SRC_GEN_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_MODE_SHIFT)) & SRC_GEN_EVENT_RESET_SYSMAN_ACK_CTRL_CNT_MODE_MASK)
/*! @} */

/*! @name SRMR - SRC Reset Mode Register (SRMR) */
/*! @{ */

#define SRC_GEN_SRMR_RSTR_0_MASK         (0x1U)
#define SRC_GEN_SRMR_RSTR_0_SHIFT        (0U)
/*! RSTR_0 - configuration bit for independent reset of reset region ANAMIX by event <a>
 *  0b0..independent reset of reset region ANAMIX by event <a> is disabled
 *  0b1..independent reset of reset region ANAMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_0(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_0_SHIFT)) & SRC_GEN_SRMR_RSTR_0_MASK)

#define SRC_GEN_SRMR_RSTR_1_MASK         (0x2U)
#define SRC_GEN_SRMR_RSTR_1_SHIFT        (1U)
/*! RSTR_1 - configuration bit for independent reset of reset region AONMIX_TOP by event <a>
 *  0b0..independent reset of reset region AONMIX_TOP by event <a> is disabled
 *  0b1..independent reset of reset region AONMIX_TOP by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_1(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_1_SHIFT)) & SRC_GEN_SRMR_RSTR_1_MASK)

#define SRC_GEN_SRMR_RSTR_2_MASK         (0x4U)
#define SRC_GEN_SRMR_RSTR_2_SHIFT        (2U)
/*! RSTR_2 - configuration bit for independent reset of reset region AONMIX_M33 by event <a>
 *  0b0..independent reset of reset region AONMIX_M33 by event <a> is disabled
 *  0b1..independent reset of reset region AONMIX_M33 by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_2(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_2_SHIFT)) & SRC_GEN_SRMR_RSTR_2_MASK)

#define SRC_GEN_SRMR_RSTR_3_MASK         (0x8U)
#define SRC_GEN_SRMR_RSTR_3_SHIFT        (3U)
/*! RSTR_3 - configuration bit for independent reset of reset region AONMIX_SENTINEL by event <a>
 *  0b0..independent reset of reset region AONMIX_SENTINEL by event <a> is disabled
 */
#define SRC_GEN_SRMR_RSTR_3(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_3_SHIFT)) & SRC_GEN_SRMR_RSTR_3_MASK)

#define SRC_GEN_SRMR_RSTR_4_MASK         (0x10U)
#define SRC_GEN_SRMR_RSTR_4_SHIFT        (4U)
/*! RSTR_4 - configuration bit for independent reset of reset region BBSMMIX by event <a>
 *  0b0..independent reset of reset region BBSMMIX by event <a> is disabled
 *  0b1..independent reset of reset region BBSMMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_4(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_4_SHIFT)) & SRC_GEN_SRMR_RSTR_4_MASK)

#define SRC_GEN_SRMR_RSTR_5_MASK         (0x20U)
#define SRC_GEN_SRMR_RSTR_5_SHIFT        (5U)
/*! RSTR_5 - configuration bit for independent reset of reset region CAMERAMIX by event <a>
 *  0b0..independent reset of reset region CAMERAMIX by event <a> is disabled
 *  0b1..independent reset of reset region CAMERAMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_5(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_5_SHIFT)) & SRC_GEN_SRMR_RSTR_5_MASK)

#define SRC_GEN_SRMR_RSTR_6_MASK         (0x40U)
#define SRC_GEN_SRMR_RSTR_6_SHIFT        (6U)
/*! RSTR_6 - configuration bit for independent reset of reset region CCMSRCGCMIX by event <a>
 *  0b0..independent reset of reset region CCMSRCGCMIX by event <a> is disabled
 *  0b1..independent reset of reset region CCMSRCGCMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_6(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_6_SHIFT)) & SRC_GEN_SRMR_RSTR_6_MASK)

#define SRC_GEN_SRMR_RSTR_7_MASK         (0x80U)
#define SRC_GEN_SRMR_RSTR_7_SHIFT        (7U)
/*! RSTR_7 - configuration bit for independent reset of reset region CORTEXAMIX_CORE0 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE0 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE0 by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_7(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_7_SHIFT)) & SRC_GEN_SRMR_RSTR_7_MASK)

#define SRC_GEN_SRMR_RSTR_8_MASK         (0x100U)
#define SRC_GEN_SRMR_RSTR_8_SHIFT        (8U)
/*! RSTR_8 - configuration bit for independent reset of reset region CORTEXAMIX_CORE1 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE1 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE1 by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_8(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_8_SHIFT)) & SRC_GEN_SRMR_RSTR_8_MASK)

#define SRC_GEN_SRMR_RSTR_9_MASK         (0x200U)
#define SRC_GEN_SRMR_RSTR_9_SHIFT        (9U)
/*! RSTR_9 - configuration bit for independent reset of reset region CORTEXAMIX_CORE2 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE2 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE2 by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_9(x)           (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_9_SHIFT)) & SRC_GEN_SRMR_RSTR_9_MASK)

#define SRC_GEN_SRMR_RSTR_10_MASK        (0x400U)
#define SRC_GEN_SRMR_RSTR_10_SHIFT       (10U)
/*! RSTR_10 - configuration bit for independent reset of reset region CORTEXAMIX_CORE3 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE3 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE3 by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_10(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_10_SHIFT)) & SRC_GEN_SRMR_RSTR_10_MASK)

#define SRC_GEN_SRMR_RSTR_11_MASK        (0x800U)
#define SRC_GEN_SRMR_RSTR_11_SHIFT       (11U)
/*! RSTR_11 - configuration bit for independent reset of reset region CORTEXAMIX_CORE4 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE4 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE4 by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_11(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_11_SHIFT)) & SRC_GEN_SRMR_RSTR_11_MASK)

#define SRC_GEN_SRMR_RSTR_12_MASK        (0x1000U)
#define SRC_GEN_SRMR_RSTR_12_SHIFT       (12U)
/*! RSTR_12 - configuration bit for independent reset of reset region CORTEXAMIX_CORE5 by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_CORE5 by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_CORE5 by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_12(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_12_SHIFT)) & SRC_GEN_SRMR_RSTR_12_MASK)

#define SRC_GEN_SRMR_RSTR_13_MASK        (0x2000U)
#define SRC_GEN_SRMR_RSTR_13_SHIFT       (13U)
/*! RSTR_13 - configuration bit for independent reset of reset region CORTEXAMIX_PLATFORM by event <a>
 *  0b0..independent reset of reset region CORTEXAMIX_PLATFORM by event <a> is disabled
 *  0b1..independent reset of reset region CORTEXAMIX_PLATFORM by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_13(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_13_SHIFT)) & SRC_GEN_SRMR_RSTR_13_MASK)

#define SRC_GEN_SRMR_RSTR_14_MASK        (0x4000U)
#define SRC_GEN_SRMR_RSTR_14_SHIFT       (14U)
/*! RSTR_14 - configuration bit for independent reset of reset region DDRMIX_TOP by event <a>
 *  0b0..independent reset of reset region DDRMIX_TOP by event <a> is disabled
 *  0b1..independent reset of reset region DDRMIX_TOP by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_14(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_14_SHIFT)) & SRC_GEN_SRMR_RSTR_14_MASK)

#define SRC_GEN_SRMR_RSTR_15_MASK        (0x8000U)
#define SRC_GEN_SRMR_RSTR_15_SHIFT       (15U)
/*! RSTR_15 - configuration bit for independent reset of reset region DDRMIX_PHY by event <a>
 *  0b0..independent reset of reset region DDRMIX_PHY by event <a> is disabled
 *  0b1..independent reset of reset region DDRMIX_PHY by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_15(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_15_SHIFT)) & SRC_GEN_SRMR_RSTR_15_MASK)

#define SRC_GEN_SRMR_RSTR_16_MASK        (0x10000U)
#define SRC_GEN_SRMR_RSTR_16_SHIFT       (16U)
/*! RSTR_16 - configuration bit for independent reset of reset region DISPLAYMIX by event <a>
 *  0b0..independent reset of reset region DISPLAYMIX by event <a> is disabled
 *  0b1..independent reset of reset region DISPLAYMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_16(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_16_SHIFT)) & SRC_GEN_SRMR_RSTR_16_MASK)

#define SRC_GEN_SRMR_RSTR_17_MASK        (0x20000U)
#define SRC_GEN_SRMR_RSTR_17_SHIFT       (17U)
/*! RSTR_17 - configuration bit for independent reset of reset region GPUMIX by event <a>
 *  0b0..independent reset of reset region GPUMIX by event <a> is disabled
 *  0b1..independent reset of reset region GPUMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_17(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_17_SHIFT)) & SRC_GEN_SRMR_RSTR_17_MASK)

#define SRC_GEN_SRMR_RSTR_18_MASK        (0x40000U)
#define SRC_GEN_SRMR_RSTR_18_SHIFT       (18U)
/*! RSTR_18 - configuration bit for independent reset of reset region HSIOMIX by event <a>
 *  0b0..independent reset of reset region HSIOMIX by event <a> is disabled
 *  0b1..independent reset of reset region HSIOMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_18(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_18_SHIFT)) & SRC_GEN_SRMR_RSTR_18_MASK)

#define SRC_GEN_SRMR_RSTR_19_MASK        (0x80000U)
#define SRC_GEN_SRMR_RSTR_19_SHIFT       (19U)
/*! RSTR_19 - configuration bit for independent reset of reset region M7MIX by event <a>
 *  0b0..independent reset of reset region M7MIX by event <a> is disabled
 *  0b1..independent reset of reset region M7MIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_19(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_19_SHIFT)) & SRC_GEN_SRMR_RSTR_19_MASK)

#define SRC_GEN_SRMR_RSTR_20_MASK        (0x100000U)
#define SRC_GEN_SRMR_RSTR_20_SHIFT       (20U)
/*! RSTR_20 - configuration bit for independent reset of reset region NETCMIX by event <a>
 *  0b0..independent reset of reset region NETCMIX by event <a> is disabled
 *  0b1..independent reset of reset region NETCMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_20(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_20_SHIFT)) & SRC_GEN_SRMR_RSTR_20_MASK)

#define SRC_GEN_SRMR_RSTR_21_MASK        (0x200000U)
#define SRC_GEN_SRMR_RSTR_21_SHIFT       (21U)
/*! RSTR_21 - configuration bit for independent reset of reset region NOCMIX by event <a>
 *  0b0..independent reset of reset region NOCMIX by event <a> is disabled
 *  0b1..independent reset of reset region NOCMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_21(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_21_SHIFT)) & SRC_GEN_SRMR_RSTR_21_MASK)

#define SRC_GEN_SRMR_RSTR_22_MASK        (0x400000U)
#define SRC_GEN_SRMR_RSTR_22_SHIFT       (22U)
/*! RSTR_22 - configuration bit for independent reset of reset region NPUMIX by event <a>
 *  0b0..independent reset of reset region NPUMIX by event <a> is disabled
 *  0b1..independent reset of reset region NPUMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_22(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_22_SHIFT)) & SRC_GEN_SRMR_RSTR_22_MASK)

#define SRC_GEN_SRMR_RSTR_23_MASK        (0x800000U)
#define SRC_GEN_SRMR_RSTR_23_SHIFT       (23U)
/*! RSTR_23 - configuration bit for independent reset of reset region VPUMIX by event <a>
 *  0b0..independent reset of reset region VPUMIX by event <a> is disabled
 *  0b1..independent reset of reset region VPUMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_23(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_23_SHIFT)) & SRC_GEN_SRMR_RSTR_23_MASK)

#define SRC_GEN_SRMR_RSTR_24_MASK        (0x1000000U)
#define SRC_GEN_SRMR_RSTR_24_SHIFT       (24U)
/*! RSTR_24 - configuration bit for independent reset of reset region WAKEUPMIX by event <a>
 *  0b0..independent reset of reset region WAKEUPMIX by event <a> is disabled
 *  0b1..independent reset of reset region WAKEUPMIX by event <a> is enabled
 */
#define SRC_GEN_SRMR_RSTR_24(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GEN_SRMR_RSTR_24_SHIFT)) & SRC_GEN_SRMR_RSTR_24_MASK)
/*! @} */

/* The count of SRC_GEN_SRMR */
#define SRC_GEN_SRMR_COUNT               (14U)


/*!
 * @}
 */ /* end of group SRC_GEN_Register_Masks */


/* SRC_GEN - Peripheral instance base addresses */
/** Peripheral SRC_GEN base address */
#define SRC_GEN_BASE     (0x44460000u)
/** Peripheral SRC_GEN base pointer */
#define SRC_GEN          ((SRC_GEN_Type *)SRC_GEN_BASE)
/** Array initializer of SRC_GEN peripheral base addresses */
#define SRC_GEN_BASE_ADDRS               { SRC_GEN_BASE }
/** Array initializer of SRC_GEN peripheral base pointers */
#define SRC_GEN_BASE_PTRS                { SRC_GEN }

/*!
 * @}
 */ /* end of group SRC_GEN_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_SRC_GEN_H_) */
