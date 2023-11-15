/*
** ###################################################################
**     Processor:           _CM33
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
 * @file MIMX95_GPC_CPU_CTRL.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for MIMX95_GPC_CPU_CTRL
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_GPC_CPU_CTRL_H_)  /* Check if memory map has not been already included */
#define MIMX95_GPC_CPU_CTRL_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- GPC_CPU_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_CPU_CTRL_Peripheral_Access_Layer GPC_CPU_CTRL Peripheral Access Layer
 * @{
 */

/** GPC_CPU_CTRL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t CMC_AUTHEN_CTRL;                   /**< CMC Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CMC_MISC;                          /**< Miscellaneous, offset: 0xC */
  __IO uint32_t CMC_MODE_CTRL;                     /**< CPU mode control, offset: 0x10 */
  __I  uint32_t CMC_MODE_STAT;                     /**< CPU mode Status, offset: 0x14 */
  __I  uint32_t CMC_PIN_STAT;                      /**< CMC pin Status, offset: 0x18 */
       uint8_t RESERVED_2[228];
  __IO uint32_t CMC_IRQ_WAKEUP_MASK[12];           /**< IRQ wake-up mask register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_3[16];
  __IO uint32_t CMC_NON_IRQ_WAKEUP_MASK;           /**< CMC non-IRQ wakeup mask, offset: 0x140 */
       uint8_t RESERVED_4[12];
  __I  uint32_t CMC_IRQ_WAKEUP_STAT[12];           /**< IRQ status register, array offset: 0x150, array step: 0x4 */
       uint8_t RESERVED_5[16];
  __I  uint32_t CMC_NON_IRQ_WAKEUP_STAT;           /**< CMC non-IRQ wakeup status, offset: 0x190 */
       uint8_t RESERVED_6[108];
  __IO uint32_t CMC_SLEEP_A55_HDSK_CTRL;           /**< CMC sleep A55_HDSK control, offset: 0x200 */
  __I  uint32_t CMC_SLEEP_A55_HDSK_STAT;           /**< CMC sleep A55_HDSK status, offset: 0x204 */
  __IO uint32_t CMC_SLEEP_SSAR_CTRL;               /**< CMC sleep SSAR control, offset: 0x208 */
  __I  uint32_t CMC_SLEEP_SSAR_STAT;               /**< CMC sleep SSAR status, offset: 0x20C */
  __IO uint32_t CMC_SLEEP_LPCG_CTRL;               /**< CMC sleep LPCG control, offset: 0x210 */
  __I  uint32_t CMC_SLEEP_LPCG_STAT;               /**< CMC sleep LPCG status, offset: 0x214 */
  __IO uint32_t CMC_SLEEP_PLL_CTRL;                /**< CMC sleep PLL control, offset: 0x218 */
  __I  uint32_t CMC_SLEEP_PLL_STAT;                /**< CMC sleep PLL status, offset: 0x21C */
  __IO uint32_t CMC_SLEEP_ISO_CTRL;                /**< CMC sleep isolation control, offset: 0x220 */
  __I  uint32_t CMC_SLEEP_ISO_STAT;                /**< CMC sleep isolation status, offset: 0x224 */
  __IO uint32_t CMC_SLEEP_MEM_CTRL;                /**< CMC sleep memory control, offset: 0x228 */
  __I  uint32_t CMC_SLEEP_MEM_STAT;                /**< CMC sleep memory status, offset: 0x22C */
  __IO uint32_t CMC_SLEEP_RESET_CTRL;              /**< CMC sleep reset control, offset: 0x230 */
  __I  uint32_t CMC_SLEEP_RESET_STAT;              /**< CMC sleep reset status, offset: 0x234 */
  __IO uint32_t CMC_SLEEP_POWER_CTRL;              /**< CMC sleep power control, offset: 0x238 */
  __I  uint32_t CMC_SLEEP_POWER_STAT;              /**< CMC sleep power status, offset: 0x23C */
  __IO uint32_t CMC_SLEEP_RSV2_CTRL;               /**< CMC sleep rsv2 control, offset: 0x240 */
  __I  uint32_t CMC_SLEEP_RSV2_STAT;               /**< CMC sleep rsv2 status, offset: 0x244 */
  __IO uint32_t CMC_SLEEP_SYSMAN_CTRL;             /**< CMC sleep Sysman control, offset: 0x248 */
  __I  uint32_t CMC_SLEEP_SYSMAN_STAT;             /**< CMC Sleep Sysman status, offset: 0x24C */
       uint8_t RESERVED_7[56];
  __IO uint32_t CMC_WAKEUP_RSV2_CTRL;              /**< CMC wakeup rsv2 control, offset: 0x288 */
  __I  uint32_t CMC_WAKEUP_RSV2_STAT;              /**< CMC wakeup rsv2 status, offset: 0x28C */
  __IO uint32_t CMC_WAKEUP_POWER_CTRL;             /**< CMC wakeup power control, offset: 0x290 */
  __I  uint32_t CMC_WAKEUP_POWER_STAT;             /**< CMC wakeup power status, offset: 0x294 */
  __IO uint32_t CMC_WAKEUP_MEM_CTRL;               /**< CMC wakeup memory control, offset: 0x298 */
  __I  uint32_t CMC_WAKEUP_MEM_STAT;               /**< CMC wakeup memory status, offset: 0x29C */
  __IO uint32_t CMC_WAKEUP_RESET_CTRL;             /**< CMC wakeup reset control, offset: 0x2A0 */
  __I  uint32_t CMC_WAKEUP_RESET_STAT;             /**< CMC sleep reset status, offset: 0x2A4 */
  __IO uint32_t CMC_WAKEUP_ISO_CTRL;               /**< CMC wakeup isolation control, offset: 0x2A8 */
  __I  uint32_t CMC_WAKEUP_ISO_STAT;               /**< CMC wakeup isolation status, offset: 0x2AC */
  __IO uint32_t CMC_WAKEUP_PLL_CTRL;               /**< CMC wakeup PLL control, offset: 0x2B0 */
  __I  uint32_t CMC_WAKEUP_PLL_STAT;               /**< CMC wakeup PLL status, offset: 0x2B4 */
  __IO uint32_t CMC_WAKEUP_LPCG_CTRL;              /**< CMC wakeup LPCG control, offset: 0x2B8 */
  __I  uint32_t CMC_WAKEUP_LPCG_STAT;              /**< CMC wakeup LPCG status, offset: 0x2BC */
  __IO uint32_t CMC_WAKEUP_MTR_CTRL;               /**< CMC wakeup MTR control, offset: 0x2C0 */
  __I  uint32_t CMC_WAKEUP_MTR_STAT;               /**< CMC wakeup MTR status, offset: 0x2C4 */
  __IO uint32_t CMC_WAKEUP_SSAR_CTRL;              /**< CMC wakeup SSAR control, offset: 0x2C8 */
  __I  uint32_t CMC_WAKEUP_SSAR_STAT;              /**< CMC wakeup SSAR status, offset: 0x2CC */
  __IO uint32_t CMC_WAKEUP_A55_HDSK_CTRL;          /**< CMC wakeup A55_HDSK control, offset: 0x2D0 */
  __I  uint32_t CMC_WAKEUP_A55_HDSK_STAT;          /**< CMC wakeup A55_HDSK status, offset: 0x2D4 */
  __IO uint32_t CMC_WAKEUP_SYSMAN_CTRL;            /**< CMC wakeup Sysman control, offset: 0x2D8 */
  __I  uint32_t CMC_WAKEUP_SYSMAN_STAT;            /**< CMC wakeup Sysman status, offset: 0x2DC */
       uint8_t RESERVED_8[160];
  __IO uint32_t CMC_SYS_SLEEP_CTRL;                /**< CMC system sleep control, offset: 0x380 */
       uint8_t RESERVED_9[12];
  __IO uint32_t CMC_DEBUG;                         /**< CMC debug, offset: 0x390 */
} GPC_CPU_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- GPC_CPU_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_CPU_CTRL_Register_Masks GPC_CPU_CTRL Register Masks
 * @{
 */

/*! @name CMC_AUTHEN_CTRL - CMC Authentication Control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_CFG_MASK (0x80U)
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_CFG_SHIFT (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..The value of low power configuration fields are not locked.
 *  0b1..The value of low power configuration fields are locked. It locks the CPUx_CM registers which are marked
 *       as "Locked by LOCK_CFG field" in the function field.
 */
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_CFG(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_CFG_MASK)

#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_USER_MASK   (0x100U)
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_USER_SHIFT  (8U)
/*! USER - Allow user mode access
 *  0b0..Allow only privilege mode to access CPU mode control registers
 *  0b1..Allow both privilege and user mode to access CPU mode control registers
 */
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_USER(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_AUTHEN_CTRL_USER_SHIFT)) & GPC_CPU_CTRL_CMC_AUTHEN_CTRL_USER_MASK)

#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_NONSECURE_MASK (0x200U)
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_NONSECURE_SHIFT (9U)
/*! NONSECURE - Allow non-secure mode access
 *  0b0..Allow only secure mode to access CPU mode control
 *  0b1..Allow both secure and non-secure mode to access CPU mode control registers
 */
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_NONSECURE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_AUTHEN_CTRL_NONSECURE_SHIFT)) & GPC_CPU_CTRL_CMC_AUTHEN_CTRL_NONSECURE_MASK)

#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_SETTING_MASK (0x800U)
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_SETTING_SHIFT (11U)
/*! LOCK_SETTING - Lock NONSECURE and USER
 *  0b0..NONSECURE and USER fields are not locked
 *  0b1..NONSECURE and USER fields are locked
 */
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_SETTING(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_SETTING_SHIFT)) & GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_SETTING_MASK)

#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_LIST_MASK (0x8000U)
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_LIST_SHIFT (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST is not locked
 *  0b1..WHITE_LIST is locked
 */
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_LIST(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & GPC_CPU_CTRL_CMC_AUTHEN_CTRL_LOCK_LIST_MASK)

#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_WHITE_LIST_MASK (0xFFFF0000U)
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_WHITE_LIST_SHIFT (16U)
/*! WHITE_LIST - Domain ID white list */
#define GPC_CPU_CTRL_CMC_AUTHEN_CTRL_WHITE_LIST(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & GPC_CPU_CTRL_CMC_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name CMC_MISC - Miscellaneous */
/*! @{ */

#define GPC_CPU_CTRL_CMC_MISC_NMI_STAT_MASK      (0x1U)
#define GPC_CPU_CTRL_CMC_MISC_NMI_STAT_SHIFT     (0U)
/*! NMI_STAT - Non-masked interrupt status
 *  0b0..NMI is not asserted
 *  0b1..NMI is asserted
 */
#define GPC_CPU_CTRL_CMC_MISC_NMI_STAT(x)        (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MISC_NMI_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_MISC_NMI_STAT_MASK)

#define GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK (0x2U)
#define GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_SHIFT (1U)
/*! SLEEP_HOLD_EN - Allow cpu_sleep_hold_req assert during CPU low power status
 *  0b0..Disable cpu_sleep_hold_req
 *  0b1..Allow cpu_sleep_hold_req to assert during CPU low power status
 */
#define GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN(x)   (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_SHIFT)) & GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK)

#define GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_STAT_MASK (0x4U)
#define GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_STAT_SHIFT (2U)
/*! SLEEP_HOLD_STAT - Status of cpu_sleep_hold_ack_b
 *  0b0..CPU sleep hold is acknowledged
 *  0b1..CPU is not in sleep hold
 */
#define GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_STAT_MASK)

#define GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_UPDATE_VALID_MASK (0x8U)
#define GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_UPDATE_VALID_SHIFT (3U)
/*! SLEEP_HOLD_UPDATE_VALID - Allow to use the updated cpu_sleep_hold_req logic */
#define GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_UPDATE_VALID(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_UPDATE_VALID_SHIFT)) & GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_UPDATE_VALID_MASK)

#define GPC_CPU_CTRL_CMC_MISC_GIC_WAKEUP_STAT_MASK (0x10U)
#define GPC_CPU_CTRL_CMC_MISC_GIC_WAKEUP_STAT_SHIFT (4U)
/*! GIC_WAKEUP_STAT - GIC wakeup request status */
#define GPC_CPU_CTRL_CMC_MISC_GIC_WAKEUP_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MISC_GIC_WAKEUP_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_MISC_GIC_WAKEUP_STAT_MASK)

#define GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK       (0x20U)
#define GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_SHIFT      (5U)
/*! IRQ_MUX - IRQ select
 *  0b0..From raw IRQ
 *  0b1..From GIC
 */
#define GPC_CPU_CTRL_CMC_MISC_IRQ_MUX(x)         (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_SHIFT)) & GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK)

#define GPC_CPU_CTRL_CMC_MISC_SW_WAKEUP_MASK     (0x40U)
#define GPC_CPU_CTRL_CMC_MISC_SW_WAKEUP_SHIFT    (6U)
/*! SW_WAKEUP - software wakeup. Used for CPU hotplug. */
#define GPC_CPU_CTRL_CMC_MISC_SW_WAKEUP(x)       (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MISC_SW_WAKEUP_SHIFT)) & GPC_CPU_CTRL_CMC_MISC_SW_WAKEUP_MASK)
/*! @} */

/*! @name CMC_MODE_CTRL - CPU mode control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET_MASK (0x3U)
#define GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET_SHIFT (0U)
/*! CPU_MODE_TARGET - The CPU mode the CPU platform should transit to on next sleep event
 *  0b00..Stay in RUN mode
 *  0b01..Transit to WAIT mode
 *  0b10..Transit to STOP mode
 *  0b11..Transit to SUSPEND mode
 */
#define GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET_SHIFT)) & GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET_MASK)

#define GPC_CPU_CTRL_CMC_MODE_CTRL_WFE_EN_MASK   (0x10U)
#define GPC_CPU_CTRL_CMC_MODE_CTRL_WFE_EN_SHIFT  (4U)
/*! WFE_EN - WFE assertion can be sleep event
 *  0b0..WFE assertion can not trigger low power
 *  0b1..WFE assertion can trigger low power
 */
#define GPC_CPU_CTRL_CMC_MODE_CTRL_WFE_EN(x)     (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MODE_CTRL_WFE_EN_SHIFT)) & GPC_CPU_CTRL_CMC_MODE_CTRL_WFE_EN_MASK)
/*! @} */

/*! @name CMC_MODE_STAT - CPU mode Status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_MODE_STAT_CPU_MODE_CURRENT_MASK (0x3U)
#define GPC_CPU_CTRL_CMC_MODE_STAT_CPU_MODE_CURRENT_SHIFT (0U)
/*! CPU_MODE_CURRENT - Current CPU mode
 *  0b00..CPU is currently in RUN mode
 *  0b01..CPU is currently in WAIT mode
 *  0b10..CPU is currently in STOP mode
 *  0b11..CPU is currently in SUSPEND mode
 */
#define GPC_CPU_CTRL_CMC_MODE_STAT_CPU_MODE_CURRENT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MODE_STAT_CPU_MODE_CURRENT_SHIFT)) & GPC_CPU_CTRL_CMC_MODE_STAT_CPU_MODE_CURRENT_MASK)

#define GPC_CPU_CTRL_CMC_MODE_STAT_CPU_MODE_PREVIOUS_MASK (0xCU)
#define GPC_CPU_CTRL_CMC_MODE_STAT_CPU_MODE_PREVIOUS_SHIFT (2U)
/*! CPU_MODE_PREVIOUS - Previous CPU mode
 *  0b00..CPU was previously in RUN mode
 *  0b01..CPU was previously in WAIT mode
 *  0b10..CPU was previously in STOP mode
 *  0b11..CPU was previously in SUSPEND mode
 */
#define GPC_CPU_CTRL_CMC_MODE_STAT_CPU_MODE_PREVIOUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MODE_STAT_CPU_MODE_PREVIOUS_SHIFT)) & GPC_CPU_CTRL_CMC_MODE_STAT_CPU_MODE_PREVIOUS_MASK)

#define GPC_CPU_CTRL_CMC_MODE_STAT_SLEEP_TRANS_BUSY_MASK (0x100U)
#define GPC_CPU_CTRL_CMC_MODE_STAT_SLEEP_TRANS_BUSY_SHIFT (8U)
/*! SLEEP_TRANS_BUSY - Busy on CPU mode transition of sleep, not include set point trans busy. */
#define GPC_CPU_CTRL_CMC_MODE_STAT_SLEEP_TRANS_BUSY(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MODE_STAT_SLEEP_TRANS_BUSY_SHIFT)) & GPC_CPU_CTRL_CMC_MODE_STAT_SLEEP_TRANS_BUSY_MASK)

#define GPC_CPU_CTRL_CMC_MODE_STAT_WAKEUP_TRANS_BUSY_MASK (0x200U)
#define GPC_CPU_CTRL_CMC_MODE_STAT_WAKEUP_TRANS_BUSY_SHIFT (9U)
/*! WAKEUP_TRANS_BUSY - Busy on CPU mode transition of wakeup, not include set point trans busy. */
#define GPC_CPU_CTRL_CMC_MODE_STAT_WAKEUP_TRANS_BUSY(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MODE_STAT_WAKEUP_TRANS_BUSY_SHIFT)) & GPC_CPU_CTRL_CMC_MODE_STAT_WAKEUP_TRANS_BUSY_MASK)

#define GPC_CPU_CTRL_CMC_MODE_STAT_SLEEPING_IDLE_MASK (0x400U)
#define GPC_CPU_CTRL_CMC_MODE_STAT_SLEEPING_IDLE_SHIFT (10U)
/*! SLEEPING_IDLE - Completed CPU mode and set point transition of sleep sequence, in a sleeping_idle state. */
#define GPC_CPU_CTRL_CMC_MODE_STAT_SLEEPING_IDLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MODE_STAT_SLEEPING_IDLE_SHIFT)) & GPC_CPU_CTRL_CMC_MODE_STAT_SLEEPING_IDLE_MASK)

#define GPC_CPU_CTRL_CMC_MODE_STAT_SLEEP_REQUEST_MASK (0x10000U)
#define GPC_CPU_CTRL_CMC_MODE_STAT_SLEEP_REQUEST_SHIFT (16U)
/*! SLEEP_REQUEST - Status of sleep_request input port */
#define GPC_CPU_CTRL_CMC_MODE_STAT_SLEEP_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MODE_STAT_SLEEP_REQUEST_SHIFT)) & GPC_CPU_CTRL_CMC_MODE_STAT_SLEEP_REQUEST_MASK)

#define GPC_CPU_CTRL_CMC_MODE_STAT_WFE_REQUEST_MASK (0x20000U)
#define GPC_CPU_CTRL_CMC_MODE_STAT_WFE_REQUEST_SHIFT (17U)
/*! WFE_REQUEST - Status of standby_wfe input port */
#define GPC_CPU_CTRL_CMC_MODE_STAT_WFE_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MODE_STAT_WFE_REQUEST_SHIFT)) & GPC_CPU_CTRL_CMC_MODE_STAT_WFE_REQUEST_MASK)

#define GPC_CPU_CTRL_CMC_MODE_STAT_WAKEUP_REQUEST_MASK (0x40000U)
#define GPC_CPU_CTRL_CMC_MODE_STAT_WAKEUP_REQUEST_SHIFT (18U)
/*! WAKEUP_REQUEST - "ORed" of all unmasked IRQ in. */
#define GPC_CPU_CTRL_CMC_MODE_STAT_WAKEUP_REQUEST(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MODE_STAT_WAKEUP_REQUEST_SHIFT)) & GPC_CPU_CTRL_CMC_MODE_STAT_WAKEUP_REQUEST_MASK)

#define GPC_CPU_CTRL_CMC_MODE_STAT_FSM_STATE_MASK (0x1F000000U)
#define GPC_CPU_CTRL_CMC_MODE_STAT_FSM_STATE_SHIFT (24U)
/*! FSM_STATE - CPU mode trans FSM state. */
#define GPC_CPU_CTRL_CMC_MODE_STAT_FSM_STATE(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_MODE_STAT_FSM_STATE_SHIFT)) & GPC_CPU_CTRL_CMC_MODE_STAT_FSM_STATE_MASK)
/*! @} */

/*! @name CMC_PIN_STAT - CMC pin Status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_PIN_STAT_A55_HDSK_REQUEST_STAT_MASK (0x1U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_A55_HDSK_REQUEST_STAT_SHIFT (0U)
/*! A55_HDSK_REQUEST_STAT - cpu_mode_trans_a55_hdsk_request pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_A55_HDSK_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_A55_HDSK_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_A55_HDSK_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_SSAR_REQUEST_STAT_MASK (0x2U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_SSAR_REQUEST_STAT_SHIFT (1U)
/*! SSAR_REQUEST_STAT - cpu_mode_trans_ssar_request pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_SSAR_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_SSAR_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_SSAR_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_LPCG_REQUEST_STAT_MASK (0x4U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_LPCG_REQUEST_STAT_SHIFT (2U)
/*! LPCG_REQUEST_STAT - cpu_mode_trans_lpcg_request pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_LPCG_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_LPCG_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_LPCG_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_PLL_REQUEST_STAT_MASK (0x8U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_PLL_REQUEST_STAT_SHIFT (3U)
/*! PLL_REQUEST_STAT - cpu_mode_trans_pll_request pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_PLL_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_PLL_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_PLL_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_ISO_REQUEST_STAT_MASK (0x10U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_ISO_REQUEST_STAT_SHIFT (4U)
/*! ISO_REQUEST_STAT - cpu_mode_trans_iso_request pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_ISO_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_ISO_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_ISO_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_MEM_REQUEST_STAT_MASK (0x20U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_MEM_REQUEST_STAT_SHIFT (5U)
/*! MEM_REQUEST_STAT - cpu_mode_trans_mem_request pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_MEM_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_MEM_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_MEM_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_RESET_REQUEST_STAT_MASK (0x40U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_RESET_REQUEST_STAT_SHIFT (6U)
/*! RESET_REQUEST_STAT - cpu_mode_trans_reset_request pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_RESET_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_RESET_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_RESET_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_POWER_REQUEST_STAT_MASK (0x80U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_POWER_REQUEST_STAT_SHIFT (7U)
/*! POWER_REQUEST_STAT - cpu_mode_trans_power_request pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_POWER_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_POWER_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_POWER_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_MTR_REQUEST_STAT_MASK (0x100U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_MTR_REQUEST_STAT_SHIFT (8U)
/*! MTR_REQUEST_STAT - cpu_mode_trans_mtr_request pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_MTR_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_MTR_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_MTR_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_SYSMAN_REQUEST_STAT_MASK (0x200U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_SYSMAN_REQUEST_STAT_SHIFT (9U)
/*! SYSMAN_REQUEST_STAT - cpu_mode_trans_sysman_request pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_SYSMAN_REQUEST_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_SYSMAN_REQUEST_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_SYSMAN_REQUEST_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_A55_HDSK_DONE_STAT_MASK (0x10000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_A55_HDSK_DONE_STAT_SHIFT (16U)
/*! A55_HDSK_DONE_STAT - cpu_mode_trans_a55_hdsk_done pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_A55_HDSK_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_A55_HDSK_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_A55_HDSK_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_SSAR_DONE_STAT_MASK (0x20000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_SSAR_DONE_STAT_SHIFT (17U)
/*! SSAR_DONE_STAT - cpu_mode_trans_ssar_done pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_SSAR_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_SSAR_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_SSAR_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_LPCG_DONE_STAT_MASK (0x40000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_LPCG_DONE_STAT_SHIFT (18U)
/*! LPCG_DONE_STAT - cpu_mode_trans_lpcg_done pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_LPCG_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_LPCG_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_LPCG_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_PLL_DONE_STAT_MASK (0x80000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_PLL_DONE_STAT_SHIFT (19U)
/*! PLL_DONE_STAT - cpu_mode_trans_pll_done pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_PLL_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_PLL_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_PLL_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_ISO_DONE_STAT_MASK (0x100000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_ISO_DONE_STAT_SHIFT (20U)
/*! ISO_DONE_STAT - cpu_mode_trans_iso_done pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_ISO_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_ISO_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_ISO_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_MEM_DONE_STAT_MASK (0x200000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_MEM_DONE_STAT_SHIFT (21U)
/*! MEM_DONE_STAT - cpu_mode_trans_mem_done pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_MEM_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_MEM_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_MEM_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_RESET_DONE_STAT_MASK (0x400000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_RESET_DONE_STAT_SHIFT (22U)
/*! RESET_DONE_STAT - cpu_mode_trans_reset_done pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_RESET_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_RESET_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_RESET_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_POWER_DONE_STAT_MASK (0x800000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_POWER_DONE_STAT_SHIFT (23U)
/*! POWER_DONE_STAT - cpu_mode_trans_power_done pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_POWER_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_POWER_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_POWER_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_MTR_DONE_STAT_MASK (0x1000000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_MTR_DONE_STAT_SHIFT (24U)
/*! MTR_DONE_STAT - cpu_mode_trans_mtr_done pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_MTR_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_MTR_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_MTR_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_SYSMAN_DONE_STAT_MASK (0x2000000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_SYSMAN_DONE_STAT_SHIFT (25U)
/*! SYSMAN_DONE_STAT - cpu_mode_trans_sysman_done pin status. */
#define GPC_CPU_CTRL_CMC_PIN_STAT_SYSMAN_DONE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_SYSMAN_DONE_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_SYSMAN_DONE_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_CPU_MODE_STAT_MASK (0x60000000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_CPU_MODE_STAT_SHIFT (29U)
/*! CPU_MODE_STAT - cpu_power_mode pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_CPU_MODE_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_CPU_MODE_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_CPU_MODE_STAT_MASK)

#define GPC_CPU_CTRL_CMC_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_SHIFT (31U)
/*! DEBUG_WAKEUP_ACK_STAT - debug wakeup acknowledge pin status */
#define GPC_CPU_CTRL_CMC_PIN_STAT_DEBUG_WAKEUP_ACK_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_PIN_STAT_DEBUG_WAKEUP_ACK_STAT_MASK)
/*! @} */

/*! @name CMC_IRQ_WAKEUP_MASK - IRQ wake-up mask register */
/*! @{ */

#define GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_SHIFT (0U)
/*! IRQ_WAKEUP_MASK - IRQ Wake-up mask */
#define GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_SHIFT)) & GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_IRQ_WAKEUP_MASK_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK */
#define GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT   (12U)

/*! @name CMC_NON_IRQ_WAKEUP_MASK - CMC non-IRQ wakeup mask */
/*! @{ */

#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_MASK (0x1U)
#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_SHIFT (0U)
/*! EVENT_WAKEUP_MASK - "1" means the event cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_SHIFT)) & GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_MASK_EVENT_WAKEUP_MASK_MASK)

#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_MASK (0x2U)
#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_SHIFT (1U)
/*! DEBUG_WAKEUP_MASK - "1" means the debug_wakeup_request cannot wakeup CPU platform */
#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_SHIFT)) & GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_MASK_DEBUG_WAKEUP_MASK_MASK)
/*! @} */

/*! @name CMC_IRQ_WAKEUP_STAT - IRQ status register */
/*! @{ */

#define GPC_CPU_CTRL_CMC_IRQ_WAKEUP_STAT_IRQ_WAKEUP_STAT_MASK (0xFFFFFFFFU)
#define GPC_CPU_CTRL_CMC_IRQ_WAKEUP_STAT_IRQ_WAKEUP_STAT_SHIFT (0U)
/*! IRQ_WAKEUP_STAT - IRQ status */
#define GPC_CPU_CTRL_CMC_IRQ_WAKEUP_STAT_IRQ_WAKEUP_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_IRQ_WAKEUP_STAT_IRQ_WAKEUP_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_IRQ_WAKEUP_STAT_IRQ_WAKEUP_STAT_MASK)
/*! @} */

/* The count of GPC_CPU_CTRL_CMC_IRQ_WAKEUP_STAT */
#define GPC_CPU_CTRL_CMC_IRQ_WAKEUP_STAT_COUNT   (12U)

/*! @name CMC_NON_IRQ_WAKEUP_STAT - CMC non-IRQ wakeup status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_MASK (0x1U)
#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_SHIFT (0U)
/*! EVENT_WAKEUP_STAT - Event wakeup status
 *  0b0..No event wakeup is requested
 *  0b1..Event wakeup is requested
 */
#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_STAT_EVENT_WAKEUP_STAT_MASK)

#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_MASK (0x2U)
#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_SHIFT (1U)
/*! DEBUG_WAKEUP_STAT - Debug wakeup status
 *  0b0..No debug wakeup is requested
 *  0b1..Debug wakeup is requested
 */
#define GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_SHIFT)) & GPC_CPU_CTRL_CMC_NON_IRQ_WAKEUP_STAT_DEBUG_WAKEUP_STAT_MASK)
/*! @} */

/*! @name CMC_SLEEP_A55_HDSK_CTRL - CMC sleep A55_HDSK control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE. */
#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_A55_HDSK_STAT - CMC sleep A55_HDSK status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_SSAR_CTRL - CMC sleep SSAR control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE. */
#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_SSAR_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_SSAR_STAT - CMC sleep SSAR status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_SLEEP_SSAR_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_SSAR_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_SSAR_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_LPCG_CTRL - CMC sleep LPCG control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_LPCG_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_LPCG_STAT - CMC sleep LPCG status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_SLEEP_LPCG_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_LPCG_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_LPCG_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_PLL_CTRL - CMC sleep PLL control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_PLL_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_PLL_STAT - CMC sleep PLL status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_PLL_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_PLL_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_SLEEP_PLL_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_PLL_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_PLL_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_ISO_CTRL - CMC sleep isolation control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_ISO_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_ISO_STAT - CMC sleep isolation status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_ISO_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_ISO_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_SLEEP_ISO_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_ISO_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_ISO_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_MEM_CTRL - CMC sleep memory control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_MEM_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_MEM_STAT - CMC sleep memory status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_MEM_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_MEM_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_SLEEP_MEM_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_MEM_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_MEM_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_RESET_CTRL - CMC sleep reset control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_RESET_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_RESET_STAT - CMC sleep reset status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_RESET_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_RESET_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_SLEEP_RESET_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_RESET_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_RESET_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_POWER_CTRL - CMC sleep power control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_POWER_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_POWER_STAT - CMC sleep power status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_POWER_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_POWER_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_SLEEP_POWER_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_POWER_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_POWER_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_RSV2_CTRL - CMC sleep rsv2 control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_RSV2_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_RSV2_STAT - CMC sleep rsv2 status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_SLEEP_RSV2_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_RSV2_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_RSV2_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SLEEP_SYSMAN_CTRL - CMC sleep Sysman control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE. */
#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_SLEEP_SYSMAN_STAT - CMC Sleep Sysman status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_SLEEP_SYSMAN_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_RSV2_CTRL - CMC wakeup rsv2 control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_RSV2_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_RSV2_STAT - CMC wakeup rsv2 status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_WAKEUP_RSV2_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_RSV2_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_RSV2_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_POWER_CTRL - CMC wakeup power control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_POWER_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_POWER_STAT - CMC wakeup power status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_WAKEUP_POWER_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_POWER_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_POWER_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_MEM_CTRL - CMC wakeup memory control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_MEM_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_MEM_STAT - CMC wakeup memory status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_WAKEUP_MEM_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_MEM_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_MEM_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_RESET_CTRL - CMC wakeup reset control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_RESET_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_RESET_STAT - CMC sleep reset status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_WAKEUP_RESET_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_RESET_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_RESET_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_ISO_CTRL - CMC wakeup isolation control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_ISO_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_ISO_STAT - CMC wakeup isolation status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_WAKEUP_ISO_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_ISO_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_ISO_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_PLL_CTRL - CMC wakeup PLL control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_PLL_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_PLL_STAT - CMC wakeup PLL status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_WAKEUP_PLL_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_PLL_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_PLL_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_LPCG_CTRL - CMC wakeup LPCG control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_LPCG_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_LPCG_STAT - CMC wakeup LPCG status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_WAKEUP_LPCG_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_LPCG_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_LPCG_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_MTR_CTRL - CMC wakeup MTR control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_MTR_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_MTR_STAT - CMC wakeup MTR status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_WAKEUP_MTR_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_MTR_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_MTR_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_SSAR_CTRL - CMC wakeup SSAR control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_SSAR_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_SSAR_STAT - CMC wakeup SSAR status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_WAKEUP_SSAR_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_SSAR_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_SSAR_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_A55_HDSK_CTRL - CMC wakeup A55_HDSK control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_A55_HDSK_STAT - CMC wakeup A55_HDSK status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_WAKEUP_SYSMAN_CTRL - CMC wakeup Sysman control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_STEP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_STEP_CNT_SHIFT (0U)
/*! STEP_CNT - Step count, usage depends on CNT_MODE */
#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_STEP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_STEP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_STEP_CNT_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_CNT_MODE_MASK (0x30000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_CNT_MODE_SHIFT (28U)
/*! CNT_MODE - Count mode
 *  0b00..Counter disable mode: not use step counter, step completes once receiving step_done
 *  0b01..Counter delay mode: delay after receiving step_done, delay cycle number is STEP_CNT
 *  0b10..Ignore step_done response, the counter starts to count once step begins, when counter reaches STEP_CNT value, the step completes
 *  0b11..Time out mode, the counter starts to count once step begins, the step completes when either step_done received or counting to STEP_CNT value
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_CNT_MODE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_CNT_MODE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_CNT_MODE_MASK)

#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_DISABLE_MASK (0x80000000U)
#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_DISABLE_SHIFT (31U)
/*! DISABLE - Disable this step
 *  0b0..This step is enabled.
 *  0b1..This step is disabled. GPC will skip this step and not send any request.
 */
#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_DISABLE_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_CTRL_DISABLE_MASK)
/*! @} */

/*! @name CMC_WAKEUP_SYSMAN_STAT - CMC wakeup Sysman status */
/*! @{ */

#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_STAT_RSP_CNT_MASK (0xFFFFFFU)
#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_STAT_RSP_CNT_SHIFT (0U)
/*! RSP_CNT - Response count, record the delay from step start to step_done received */
#define GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_STAT_RSP_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_STAT_RSP_CNT_SHIFT)) & GPC_CPU_CTRL_CMC_WAKEUP_SYSMAN_STAT_RSP_CNT_MASK)
/*! @} */

/*! @name CMC_SYS_SLEEP_CTRL - CMC system sleep control */
/*! @{ */

#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_WAIT_MASK (0x1U)
#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_WAIT_SHIFT (0U)
/*! SS_WAIT - Request system sleep when CPU is in WAIT mode
 *  0b0..Do not request system sleep when CPU is in WAIT mode
 *  0b1..Request system sleep when CPU is in WAIT mode
 */
#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_WAIT(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_WAIT_SHIFT)) & GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_WAIT_MASK)

#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_STOP_MASK (0x2U)
#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_STOP_SHIFT (1U)
/*! SS_STOP - Request system sleep when CPU is in STOP mode
 *  0b0..Do not request system sleep when CPU is in STOP mode
 *  0b1..Request system sleep when CPU is in STOP mode
 */
#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_STOP(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_STOP_SHIFT)) & GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_STOP_MASK)

#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK (0x4U)
#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_SHIFT (2U)
/*! SS_SUSPEND - Request system sleep when CPU is in SUSPEND mode
 *  0b0..Do not request system sleep when CPU is in SUSPEND mode
 *  0b1..Request system sleep when CPU is in SUSPEND mode
 */
#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_SHIFT)) & GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK)

#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_MASK (0x10000U)
#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_SHIFT (16U)
/*! SYS_SLEEP_BUSY - Indicates the CPU is busy entering system sleep mode. */
#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_SHIFT)) & GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SYS_SLEEP_BUSY_MASK)

#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_MASK (0x20000U)
#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_SHIFT (17U)
/*! SYS_WAKEUP_BUSY - Indicates the CPU is busy exiting system sleep mode. */
#define GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_SHIFT)) & GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SYS_WAKEUP_BUSY_MASK)
/*! @} */

/*! @name CMC_DEBUG - CMC debug */
/*! @{ */

#define GPC_CPU_CTRL_CMC_DEBUG_PRETEND_SLEEP_MASK (0x1U)
#define GPC_CPU_CTRL_CMC_DEBUG_PRETEND_SLEEP_SHIFT (0U)
/*! PRETEND_SLEEP - Write 1 to force CMC into sleep. Used to debug GPC status. Locked by LOCK_CFG field. */
#define GPC_CPU_CTRL_CMC_DEBUG_PRETEND_SLEEP(x)  (((uint32_t)(((uint32_t)(x)) << GPC_CPU_CTRL_CMC_DEBUG_PRETEND_SLEEP_SHIFT)) & GPC_CPU_CTRL_CMC_DEBUG_PRETEND_SLEEP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPC_CPU_CTRL_Register_Masks */


/* GPC_CPU_CTRL - Peripheral instance base addresses */
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM33 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE       (0x44470000u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM33 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CM33            ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE        (0x44470800u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CM7 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CM7             ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_0 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE     (0x44471000u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_0 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_0          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_1 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE     (0x44471800u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_1 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_1          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_2 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE     (0x44472000u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_2 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_2          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_3 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE     (0x44472800u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_3 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_3          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_4 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_4_BASE     (0x44473000u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_4 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_4          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_4_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_5 base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_5_BASE     (0x44473800u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_5 base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_5          ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_5_BASE)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER base address */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE (0x44474000u)
/** Peripheral CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER base pointer */
#define CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER    ((GPC_CPU_CTRL_Type *)CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE)
/** Array initializer of GPC_CPU_CTRL peripheral base addresses */
#define GPC_CPU_CTRL_BASE_ADDRS                  { CCMSRCGPC__GPC__GPC_CTRL_CM33_BASE, CCMSRCGPC__GPC__GPC_CTRL_CM7_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_0_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_1_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_2_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_3_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_4_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_5_BASE, CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER_BASE }
/** Array initializer of GPC_CPU_CTRL peripheral base pointers */
#define GPC_CPU_CTRL_BASE_PTRS                   { CCMSRCGPC__GPC__GPC_CTRL_CM33, CCMSRCGPC__GPC__GPC_CTRL_CM7, CCMSRCGPC__GPC__GPC_CTRL_CA55_0, CCMSRCGPC__GPC__GPC_CTRL_CA55_1, CCMSRCGPC__GPC__GPC_CTRL_CA55_2, CCMSRCGPC__GPC__GPC_CTRL_CA55_3, CCMSRCGPC__GPC__GPC_CTRL_CA55_4, CCMSRCGPC__GPC__GPC_CTRL_CA55_5, CCMSRCGPC__GPC__GPC_CTRL_CA55_CLUSTER }

/*!
 * @}
 */ /* end of group GPC_CPU_CTRL_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_GPC_CPU_CTRL_H_) */
