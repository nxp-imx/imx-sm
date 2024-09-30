/*
** ###################################################################
**     Processor:           _CM33
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX95_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
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
 * @file mx95_GPC_GLOBAL.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for MIMX95_GPC_GLOBAL
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_GPC_GLOBAL_H_)  /* Check if memory map has not been already included */
#define MIMX95_GPC_GLOBAL_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- GPC_GLOBAL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_GLOBAL_Peripheral_Access_Layer GPC_GLOBAL Peripheral Access Layer
 * @{
 */

/** GPC_GLOBAL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t GPC_GLOB_AUTHEN_CTRL;              /**< GPC Global Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[20];
  __IO uint32_t GPC_MASTER;                        /**< GPC master CPU configuration, offset: 0x1C */
       uint8_t RESERVED_2[32];
  __IO uint32_t GPC_SYS_SLEEP;                     /**< GPC system sleep control, offset: 0x40 */
       uint8_t RESERVED_3[12];
  __IO uint32_t GPC_CPU_DOMAIN_ASSIGNMENT[9];      /**< GPC domain assignment, array offset: 0x50, array step: 0x4 */
       uint8_t RESERVED_4[140];
  __IO uint32_t GPC_PMIC_CTRL;                     /**< PMIC standby control from GPC, offset: 0x100 */
       uint8_t RESERVED_5[4];
  __IO uint32_t GPC_PMIC_STBY_ACK_CTRL;            /**< PMIC standby acknowledge control, offset: 0x108 */
       uint8_t RESERVED_6[244];
  __IO uint32_t GPC_ROSC_CTRL;                     /**< RCOSC control, offset: 0x200 */
       uint8_t RESERVED_7[4];
  __IO uint32_t GPC_EFUSE_CTRL;                    /**< eFUSE control, offset: 0x208 */
  __IO uint32_t GPC_ELE_HDSK_CTRL;                 /**< ELE Handshake control, offset: 0x20C */
} GPC_GLOBAL_Type;

/* ----------------------------------------------------------------------------
   -- GPC_GLOBAL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_GLOBAL_Register_Masks GPC_GLOBAL Register Masks
 * @{
 */

/*! @name GPC_GLOB_AUTHEN_CTRL - GPC Global Authentication Control */
/*! @{ */

#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_CFG_MASK (0x80U)
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_CFG_SHIFT (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..The value of low power configuration fields are not locked.
 *  0b1..The value of low power configuration fields are locked. Refer to the function field of each gpc_global registers.
 */
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_CFG(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_CFG_MASK)

#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_USER_MASK (0x100U)
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_USER_SHIFT (8U)
/*! USER - Allow user mode access
 *  0b0..Allow only privilege mode to access CPU mode control registers
 *  0b1..Allow both privilege and user mode to access CPU mode control registers
 */
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_USER(x)  (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_USER_SHIFT)) & GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_USER_MASK)

#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_NONSECURE_MASK (0x200U)
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_NONSECURE_SHIFT (9U)
/*! NONSECURE - Allow non-secure mode access
 *  0b0..Allow only secure mode to access CPU mode registers
 *  0b1..Allow both secure and non-secure mode to access CPU mode control registers.
 */
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_NONSECURE(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_NONSECURE_SHIFT)) & GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_NONSECURE_MASK)

#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_SETTING_MASK (0x800U)
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_SETTING_SHIFT (11U)
/*! LOCK_SETTING - Lock NONSECURE and USER
 *  0b0..NONSECURE and USER fields are not locked
 *  0b1..NONSECURE and USER fields are locked
 */
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_SETTING(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_SETTING_SHIFT)) & GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_SETTING_MASK)

#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_LIST_MASK (0x8000U)
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST is not locked
 *  0b1..WHITE_LIST is locked
 */
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_LOCK_LIST_MASK)

#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_WHITE_LIST_MASK (0xFFFF0000U)
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Domain ID white list */
#define GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & GPC_GLOBAL_GPC_GLOB_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name GPC_MASTER - GPC master CPU configuration */
/*! @{ */

#define GPC_GLOBAL_GPC_MASTER_CPU_MASTER_MASK    (0x1FFU)
#define GPC_GLOBAL_GPC_MASTER_CPU_MASTER_SHIFT   (0U)
/*! CPU_MASTER - Setting to 1 means CPU is the master CPU of its domain */
#define GPC_GLOBAL_GPC_MASTER_CPU_MASTER(x)      (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_MASTER_CPU_MASTER_SHIFT)) & GPC_GLOBAL_GPC_MASTER_CPU_MASTER_MASK)
/*! @} */

/*! @name GPC_SYS_SLEEP - GPC system sleep control */
/*! @{ */

#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU_DISABLE_MASK (0x1FF0000U)
#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU_DISABLE_SHIFT (16U)
/*! FORCE_CPU_DISABLE - Force CPU into a system sleep status */
#define GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU_DISABLE_SHIFT)) & GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU_DISABLE_MASK)
/*! @} */

/*! @name GPC_CPU_DOMAIN_ASSIGNMENT - GPC domain assignment */
/*! @{ */

#define GPC_GLOBAL_GPC_CPU_DOMAIN_ASSIGNMENT_CPU_DOMAIN_MASK (0xFU)
#define GPC_GLOBAL_GPC_CPU_DOMAIN_ASSIGNMENT_CPU_DOMAIN_SHIFT (0U)
/*! CPU_DOMAIN - CPU domain assignment
 *  0b0000..Domain 0
 *  0b0001..Domain 1
 *  0b0010..Domain 2
 *  0b0011..Domain 3
 *  0b0100..Domain 4
 *  0b0101..Domain 5
 *  0b0110..Domain 6
 *  0b0111..Domain 7
 *  0b1000..Domain 8
 *  0b1001..Domain 9
 *  0b1010..Domain 10
 *  0b1011..Domain 11
 *  0b1100..Domain 12
 *  0b1101..Domain 13
 *  0b1110..Domain 14
 *  0b1111..Domain 15
 */
#define GPC_GLOBAL_GPC_CPU_DOMAIN_ASSIGNMENT_CPU_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_CPU_DOMAIN_ASSIGNMENT_CPU_DOMAIN_SHIFT)) & GPC_GLOBAL_GPC_CPU_DOMAIN_ASSIGNMENT_CPU_DOMAIN_MASK)
/*! @} */

/* The count of GPC_GLOBAL_GPC_CPU_DOMAIN_ASSIGNMENT */
#define GPC_GLOBAL_GPC_CPU_DOMAIN_ASSIGNMENT_COUNT (9U)

/*! @name GPC_PMIC_CTRL - PMIC standby control from GPC */
/*! @{ */

#define GPC_GLOBAL_GPC_PMIC_CTRL_PMIC_STBY_EN_MASK (0x1U)
#define GPC_GLOBAL_GPC_PMIC_CTRL_PMIC_STBY_EN_SHIFT (0U)
/*! PMIC_STBY_EN - Assert the PMIC standby request when system sleep
 *  0b1..Enter PMIC standby request
 *  0b0..Exit PMIC standby request
 */
#define GPC_GLOBAL_GPC_PMIC_CTRL_PMIC_STBY_EN(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_PMIC_CTRL_PMIC_STBY_EN_SHIFT)) & GPC_GLOBAL_GPC_PMIC_CTRL_PMIC_STBY_EN_MASK)
/*! @} */

/*! @name GPC_PMIC_STBY_ACK_CTRL - PMIC standby acknowledge control */
/*! @{ */

#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_CFG_MASK (0xFFFU)
#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_CFG_SHIFT (0U)
/*! STBY_ON_CNT_CFG - PMIC standby on acknowledge count configure. Usage depends on STBY_ON_CNT_MODE. Locked by LOCK_CFG field. */
#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_CFG_SHIFT)) & GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_CFG_MASK)

#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_MODE_MASK (0xC000U)
#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_MODE_SHIFT (14U)
/*! STBY_ON_CNT_MODE - PMIC standby on acknowledge count mode. Locked by LOCK_CFG field.
 *  0b00..Finish the process once pmic_standby signal changes
 *  0b01..Finish the process once getting acknowledge from PMIC
 *  0b10..Ignore PMIC acknowledge, the delay counter starts to count once pmic_standby changes
 *  0b11..Time out mode, the counter starts to count once pmic_standby changes, then finishes the process when
 *        either acknowledge received or counting to CNT_CFG value
 */
#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_MODE_SHIFT)) & GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_ON_CNT_MODE_MASK)

#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_CFG_MASK (0xFFF0000U)
#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_CFG_SHIFT (16U)
/*! STBY_OFF_CNT_CFG - PMIC standby off acknowledge count configure. Usage depends on STBY_OFF_CNT_MODE. Locked by LOCK_CFG field. */
#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_CFG(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_CFG_SHIFT)) & GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_CFG_MASK)

#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_MODE_MASK (0xC0000000U)
#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_MODE_SHIFT (30U)
/*! STBY_OFF_CNT_MODE - PMIC standby off acknowledge count mode. Locked by LOCK_CFG field.
 *  0b00..Finish the process once pmic_standby signal changes
 *  0b01..Finish the process once getting acknowledge from PMIC
 *  0b10..Ignore PMIC acknowledge, the delay counter starts to count once pmic_standby changes
 *  0b11..Time out mode, the counter starts to count once pmic_standby changes, then finishes the process when
 *        either acknowledge received or counting to CNT_CFG value
 */
#define GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_MODE_SHIFT)) & GPC_GLOBAL_GPC_PMIC_STBY_ACK_CTRL_STBY_OFF_CNT_MODE_MASK)
/*! @} */

/*! @name GPC_ROSC_CTRL - RCOSC control */
/*! @{ */

#define GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_MASK (0x1U)
#define GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_SHIFT (0U)
/*! ROSC_OFF_EN - Shut off the 24 MHz RCOSC clock when system sleep
 *  0b0..Keep 24 MHz ROSC clock running during system sleep
 *  0b1..Shut off 24 MHz ROSC clock during system sleep
 */
#define GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_SHIFT)) & GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_MASK)
/*! @} */

/*! @name GPC_EFUSE_CTRL - eFUSE control */
/*! @{ */

#define GPC_GLOBAL_GPC_EFUSE_CTRL_EFUSE_PD_EN_MASK (0x1U)
#define GPC_GLOBAL_GPC_EFUSE_CTRL_EFUSE_PD_EN_SHIFT (0U)
/*! EFUSE_PD_EN - eFUSE power down enable
 *  0b0..Do not Power Down efuse during system sleep
 *  0b1..Power Down efuse during system sleep
 */
#define GPC_GLOBAL_GPC_EFUSE_CTRL_EFUSE_PD_EN(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_EFUSE_CTRL_EFUSE_PD_EN_SHIFT)) & GPC_GLOBAL_GPC_EFUSE_CTRL_EFUSE_PD_EN_MASK)
/*! @} */

/*! @name GPC_ELE_HDSK_CTRL - ELE Handshake control */
/*! @{ */

#define GPC_GLOBAL_GPC_ELE_HDSK_CTRL_ELE_HDSK_EN_MASK (0x1U)
#define GPC_GLOBAL_GPC_ELE_HDSK_CTRL_ELE_HDSK_EN_SHIFT (0U)
/*! ELE_HDSK_EN - GPC-to-ELE handshake enable
 *  0b0..Disable GPC-to-ELE handshake during system sleep sequence
 *  0b1..Enable GPC-to-ELE handshake during system sleep sequence
 */
#define GPC_GLOBAL_GPC_ELE_HDSK_CTRL_ELE_HDSK_EN(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_ELE_HDSK_CTRL_ELE_HDSK_EN_SHIFT)) & GPC_GLOBAL_GPC_ELE_HDSK_CTRL_ELE_HDSK_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPC_GLOBAL_Register_Masks */


/* GPC_GLOBAL - Peripheral instance base addresses */
/** Peripheral GPC_GLOBAL base address */
#define GPC_GLOBAL_BASE                             (0x44474800u)
/** Peripheral GPC_GLOBAL base pointer */
#define GPC_GLOBAL                                  ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE)
/** Array initializer of GPC_GLOBAL peripheral base addresses */
#define GPC_GLOBAL_BASE_ADDRS                       { GPC_GLOBAL_BASE }
/** Array initializer of GPC_GLOBAL peripheral base pointers */
#define GPC_GLOBAL_BASE_PTRS                        { GPC_GLOBAL }

/*!
 * @}
 */ /* end of group GPC_GLOBAL_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_GPC_GLOBAL_H_) */
