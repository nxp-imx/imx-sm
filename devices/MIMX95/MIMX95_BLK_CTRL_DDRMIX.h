/*
** ###################################################################
**     Processors:          MIMX95_cm33
**
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
 * @file MIMX95_BLK_CTRL_DDRMIX.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for MIMX95_BLK_CTRL_DDRMIX
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_BLK_CTRL_DDRMIX_H_)  /* Check if memory map has not been already included */
#define MIMX95_BLK_CTRL_DDRMIX_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_DDRMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_DDRMIX_Peripheral_Access_Layer BLK_CTRL_DDRMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_DDRMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t HWFFC_CTRL;                        /**< DDRPHY DfiClk, DflCtlClk HWFFC Control, offset: 0x0 */
       uint8_t RESERVED_0[8];
  __IO uint32_t DDRC_STOP_CTRL;                    /**< DDR Controller ipg_stop SW control, offset: 0xC */
  __IO uint32_t AUTO_CG_CTRL;                      /**< DDR Controller automatic clock gating control when no AXI transmit, offset: 0x10 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DDRC_EXCLUSIVE_EN;                 /**< DDRC AXI exclusive access monitor enable, offset: 0x18 */
  __IO uint32_t DDRC_URGENT_EN;                    /**< DDRC real_time read urgent and read urgent enable, offset: 0x1C */
  __IO uint32_t RT_MASTER_ID_0_1;                  /**< DDRC real_time master 6bit extend-ID range 0 and range 1, offset: 0x20 */
  __IO uint32_t RT_MASTER_ID_2_3;                  /**< DDRC real_time master 6bit extend-ID range 2 and range 3, offset: 0x24 */
       uint8_t RESERVED_2[4];
  __IO uint32_t AXI_PARITY_ERR_INJECT;             /**< DDRMIX AXI parity error injection register, offset: 0x2C */
  __IO uint32_t RT_MASTER_ID_4_5;                  /**< DDRC real_time master 6bit extend-ID range 4 and range 5, offset: 0x30 */
  __IO uint32_t RT_MASTER_ID_6_7;                  /**< DDRC real_time master 6bit extend-ID range 6 and range 7, offset: 0x34 */
} BLK_CTRL_DDRMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_DDRMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_DDRMIX_Register_Masks BLK_CTRL_DDRMIX Register Masks
 * @{
 */

/*! @name HWFFC_CTRL - DDRPHY DfiClk, DflCtlClk HWFFC Control */
/*! @{ */

#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_MASK (0x1U)
#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_SHIFT (0U)
/*! HWFFC_EN - DDRPHY DfiClk, DfiCtlClk HWFFC Enable */
#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_SHIFT)) & BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_MASK)

#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_MASK (0x2U)
#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_SHIFT (1U)
/*! HWFFC_SEL - DDRPHY DfiClk, DfiCtlClk HWFFC Select */
#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_SHIFT)) & BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_MASK)
/*! @} */

/*! @name DDRC_STOP_CTRL - DDR Controller ipg_stop SW control */
/*! @{ */

#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_MASK (0x1U)
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_SHIFT (0U)
/*! DDRC_STOP - DDR Controller ipg_stop. */
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_SHIFT)) & BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_MASK)

#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_MASK (0x2U)
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_SHIFT (1U)
/*! DDRC_STOP_ACK - DDR Controller ipg_stop_ack. */
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_SHIFT)) & BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_MASK)

#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_MASK (0x4U)
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_SHIFT (2U)
/*! DDRC_DRAM_SELF_REFRESH - DDR Controller ddrc_dram_self_refresh. */
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_SHIFT)) & BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_DRAM_SELF_REFRESH_MASK)

#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_MASK (0x10U)
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_SHIFT (4U)
/*! DDRC_STOP_HOLD_EN - DDR Controller ipg_stop holds for a period of time before clearing. */
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_SHIFT)) & BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_EN_MASK)

#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_MASK (0xFFFFFF00U)
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_SHIFT (8U)
/*! DDRC_STOP_HOLD_PERIOD - DDR Controller ipg_stop hold period before clearing. */
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_SHIFT)) & BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_HOLD_PERIOD_MASK)
/*! @} */

/*! @name AUTO_CG_CTRL - DDR Controller automatic clock gating control when no AXI transmit */
/*! @{ */

#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_MASK (0xFFFFU)
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_SHIFT (0U)
/*! SSI_IDLE_STRAP - Number of cycles for SSI being idle before DDRC clock gating. */
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_SHIFT)) & BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_MASK)

#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_MASK (0x10000U)
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_SHIFT (16U)
/*! AUTO_CG_ENA - DDR Controller automatic clock gating enable bit. */
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_SHIFT)) & BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_MASK)

#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_MASK (0x20000U)
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_SHIFT (17U)
/*! HWFFC_ACG_FORCE_B - DDR Controller hwffc and auto CG send ipg_stop allow bit. Can only programmed once. */
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_SHIFT)) & BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_MASK)

#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_MASK (0x1000000U)
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_SHIFT (24U)
/*! GATE_DDRC_CLK - DDR Auto Clock Gating is allowed for DDR Controller clock ipg_clk_ddrc. */
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_SHIFT)) & BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_CLK_MASK)

#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_MASK (0x4000000U)
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_SHIFT (26U)
/*! GATE_DDRC_IPS_CLK - DDR Auto Clock Gating is allowed for DDR Controller IPS clock ips_clk_ddrc. */
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_SHIFT)) & BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRC_IPS_CLK_MASK)

#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_MASK (0x10000000U)
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_SHIFT (28U)
/*! GATE_DDRPHY_DFICLK - DDR Auto Clock Gating is allowed for DDRPHY DfiClk clock. */
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_SHIFT)) & BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_DFICLK_MASK)

#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_MASK (0x40000000U)
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_SHIFT (30U)
/*! GATE_DDRPHY_APBCLK - DDR Auto Clock Gating is allowed for DDRPHY APBCLK clock. */
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_SHIFT)) & BLK_CTRL_DDRMIX_AUTO_CG_CTRL_GATE_DDRPHY_APBCLK_MASK)
/*! @} */

/*! @name DDRC_EXCLUSIVE_EN - DDRC AXI exclusive access monitor enable */
/*! @{ */

#define BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_MASK (0x1U)
#define BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_SHIFT (0U)
/*! EXCLUSIVE_EN - DDRC AXI exclusive access monitor enable */
#define BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_SHIFT)) & BLK_CTRL_DDRMIX_DDRC_EXCLUSIVE_EN_EXCLUSIVE_EN_MASK)
/*! @} */

/*! @name DDRC_URGENT_EN - DDRC real_time read urgent and read urgent enable */
/*! @{ */

#define BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_MASK (0x1U)
#define BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_SHIFT (0U)
/*! READ_URGENT_EN - DDRC ddrc_read_urgent is enabled */
#define BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_SHIFT)) & BLK_CTRL_DDRMIX_DDRC_URGENT_EN_READ_URGENT_EN_MASK)

#define BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_MASK (0x2U)
#define BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_SHIFT (1U)
/*! AR_RT_URGENT_EN - DDRC ipa_ar_rt_urgent is enabled */
#define BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_SHIFT)) & BLK_CTRL_DDRMIX_DDRC_URGENT_EN_AR_RT_URGENT_EN_MASK)
/*! @} */

/*! @name RT_MASTER_ID_0_1 - DDRC real_time master 6bit extend-ID range 0 and range 1 */
/*! @{ */

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_MASK (0x3FU)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_SHIFT (0U)
/*! RANGE_0_ID - DDRC real_time master ID range 0 ID */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_ID_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_MASK (0x3F00U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_SHIFT (8U)
/*! RANGE_0_MASK - DDRC real_time master ID range 0 ID mask */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_MASK_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_MASK (0x8000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_SHIFT (15U)
/*! RANGE_0_EN - DDRC real_time master ID range 0 enable */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_0_EN_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_MASK (0x3F0000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_SHIFT (16U)
/*! RANGE_1_ID - DDRC real_time master ID range 1 ID */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_ID_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_MASK (0x3F000000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_SHIFT (24U)
/*! RANGE_1_MASK - DDRC real_time master ID range 1 ID mask */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_MASK_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_MASK (0x80000000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_SHIFT (31U)
/*! RANGE_1_EN - DDRC real_time master ID range 1 enable */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_0_1_RANGE_1_EN_MASK)
/*! @} */

/*! @name RT_MASTER_ID_2_3 - DDRC real_time master 6bit extend-ID range 2 and range 3 */
/*! @{ */

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_MASK (0x3FU)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_SHIFT (0U)
/*! RANGE_2_ID - DDRC real_time master ID range 2 ID */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_ID_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_MASK (0x3F00U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_SHIFT (8U)
/*! RANGE_2_MASK - DDRC real_time master ID range 2 ID mask */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_MASK_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_MASK (0x8000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_SHIFT (15U)
/*! RANGE_2_EN - DDRC real_time master ID range 2 enable */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_2_EN_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_MASK (0x3F0000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_SHIFT (16U)
/*! RANGE_3_ID - DDRC real_time master ID range 3 ID */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_ID_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_MASK (0x3F000000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_SHIFT (24U)
/*! RANGE_3_MASK - DDRC real_time master ID range 3 ID mask */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_MASK_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_MASK (0x80000000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_SHIFT (31U)
/*! RANGE_3_EN - DDRC real_time master ID range 3 enable */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_2_3_RANGE_3_EN_MASK)
/*! @} */

/*! @name AXI_PARITY_ERR_INJECT - DDRMIX AXI parity error injection register */
/*! @{ */

#define BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_MASK (0x1U)
#define BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_SHIFT (0U)
/*! WDATA_ERR_INJ - DDRMIX AXI parity error injection on wdatachk[0] */
#define BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_SHIFT)) & BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_WDATA_ERR_INJ_MASK)

#define BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_MASK (0x10000U)
#define BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_SHIFT (16U)
/*! RDATA_ERR_INJ - DDRMIX AXI parity error injection on rdatachk[0] */
#define BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_SHIFT)) & BLK_CTRL_DDRMIX_AXI_PARITY_ERR_INJECT_RDATA_ERR_INJ_MASK)
/*! @} */

/*! @name RT_MASTER_ID_4_5 - DDRC real_time master 6bit extend-ID range 4 and range 5 */
/*! @{ */

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_MASK (0x3FU)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_SHIFT (0U)
/*! RANGE_4_ID - DDRC real_time master ID range 4 ID */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_ID_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_MASK (0x3F00U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_SHIFT (8U)
/*! RANGE_4_MASK - DDRC real_time master ID range 4 ID mask */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_MASK_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_MASK (0x8000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_SHIFT (15U)
/*! RANGE_4_EN - DDRC real_time master ID range 4 enable */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_4_EN_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_MASK (0x3F0000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_SHIFT (16U)
/*! RANGE_5_ID - DDRC real_time master ID range 5 ID */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_ID_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_MASK (0x3F000000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_SHIFT (24U)
/*! RANGE_5_MASK - DDRC real_time master ID range 5 ID mask */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_MASK_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_MASK (0x80000000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_SHIFT (31U)
/*! RANGE_5_EN - DDRC real_time master ID range 5 enable */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_4_5_RANGE_5_EN_MASK)
/*! @} */

/*! @name RT_MASTER_ID_6_7 - DDRC real_time master 6bit extend-ID range 6 and range 7 */
/*! @{ */

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_MASK (0x3FU)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_SHIFT (0U)
/*! RANGE_6_ID - DDRC real_time master ID range 6 ID */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_ID_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_MASK (0x3F00U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_SHIFT (8U)
/*! RANGE_6_MASK - DDRC real_time master ID range 6 ID mask */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_MASK_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_MASK (0x8000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_SHIFT (15U)
/*! RANGE_6_EN - DDRC real_time master ID range 6 enable */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_6_EN_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_MASK (0x3F0000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_SHIFT (16U)
/*! RANGE_7_ID - DDRC real_time master ID range 7 ID */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_ID_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_MASK (0x3F000000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_SHIFT (24U)
/*! RANGE_7_MASK - DDRC real_time master ID range 7 ID mask */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_MASK_MASK)

#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_MASK (0x80000000U)
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_SHIFT (31U)
/*! RANGE_7_EN - DDRC real_time master ID range 7 enable */
#define BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_SHIFT)) & BLK_CTRL_DDRMIX_RT_MASTER_ID_6_7_RANGE_7_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_DDRMIX_Register_Masks */


/* BLK_CTRL_DDRMIX - Peripheral instance base addresses */
/** Peripheral DDRC__BLK_CTRL_DDRMIX base address */
#define BLK_CTRL_DDRMIX_BASE               (0x4E010000u)
/** Peripheral BLK_CTRL_DDRMIX base pointer */
#define BLK_CTRL_DDRMIX                    ((BLK_CTRL_DDRMIX_Type *)BLK_CTRL_DDRMIX_BASE)
/** Array initializer of BLK_CTRL_DDRMIX peripheral base addresses */
#define BLK_CTRL_DDRMIX_BASE_ADDRS           { BLK_CTRL_DDRMIX_BASE }
/** Array initializer of BLK_CTRL_DDRMIX peripheral base pointers */
#define BLK_CTRL_DDRMIX_BASE_PTRS            { BLK_CTRL_DDRMIX }

/*!
 * @}
 */ /* end of group BLK_CTRL_DDRMIX_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_BLK_CTRL_DDRMIX_H_) */
