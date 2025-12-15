/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 1.0, 2026
**     Build:               b241030
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file BLK_CTRL_WAKEUPMIX.h
 * @version 1.0
 * @date 2026-01-10
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
 */

#if !defined(BLK_CTRL_WAKEUPMIX_H_)
#define BLK_CTRL_WAKEUPMIX_H_                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_WAKEUPMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_WAKEUPMIX_Peripheral_Access_Layer BLK_CTRL_WAKEUPMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_WAKEUPMIX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[24];
  __I  uint32_t EARC_PLL_STATUS;                   /**< EARC Audio PLL status bits, offset: 0x18 */
  __IO uint32_t SAI_CLK_SEL;                       /**< sai3~5 mclk1~3 clk root mux settings, offset: 0x1C */
  __I  uint32_t VOLT_DETECT;                       /**< Voltage detectors output, offset: 0x20 */
       uint8_t RESERVED_1[4];
  __IO uint32_t AXI_ATTR_CFG;                      /**< AXI CACHE CONTROL BIT, offset: 0x28 */
  __IO uint32_t IPG_DEBUG_CM33;                    /**< IPG DEBUG mask bit, offset: 0x2C */
  __IO uint32_t IPG_DEBUG_CA55C0;                  /**< IPG DEBUG mask bit for CA55 core0, offset: 0x30 */
  __IO uint32_t IPG_DEBUG_CA55C1;                  /**< IPG DEBUG mask bit for CA55 core1, offset: 0x34 */
  __IO uint32_t IPG_DEBUG_CA55C2;                  /**< IPG DEBUG mask bit for CA55 core2, offset: 0x38 */
  __IO uint32_t IPG_DEBUG_CA55C3;                  /**< IPG DEBUG mask bit for CA55 core3, offset: 0x3C */
       uint8_t RESERVED_2[8];
  __IO uint32_t IPG_DEBUG_CM7;                     /**< IPG DEBUG mask bit, offset: 0x48 */
  __IO uint32_t IPG_DEBUG_2_CM33;                  /**< IPG DEBUG mask bit, offset: 0x4C */
  __IO uint32_t IPG_DEBUG_2_CA55C0;                /**< IPG DEBUG mask bit for CA55 core0, offset: 0x50 */
  __IO uint32_t IPG_DEBUG_2_CA55C1;                /**< IPG DEBUG mask bit for CA55 core1, offset: 0x54 */
  __IO uint32_t IPG_DEBUG_2_CA55C2;                /**< IPG DEBUG mask bit for CA55 core2, offset: 0x58 */
  __IO uint32_t IPG_DEBUG_2_CA55C3;                /**< IPG DEBUG mask bit for CA55 core3, offset: 0x5C */
       uint8_t RESERVED_3[8];
  __IO uint32_t IPG_DEBUG_2_CM7;                   /**< IPG DEBUG mask bit, offset: 0x68 */
       uint8_t RESERVED_4[4];
  __IO uint32_t DBG_TRACE_CTL;                     /**< DEBUG TRACE control, offset: 0x70 */
       uint8_t RESERVED_5[16];
  __IO uint32_t SMMU_TBU_IRQ_SETUP;                /**< SMMU TBU IRQ resynchronization setup, offset: 0x84 */
       uint8_t RESERVED_6[4];
  __IO uint32_t INITIATOR_TIMEOUT;                 /**< NOC initiator timeout status, offset: 0x8C */
  __IO uint32_t NIU_TO_MW0;                        /**< Timeout Control for NOC wakeup NIU master m_w_0, offset: 0x90 */
  __IO uint32_t NIU_TO_MW1;                        /**< Timeout Control for NOC wakeup NIU master m_w_1, offset: 0x94 */
  __IO uint32_t NIU_TO_MW2;                        /**< Timeout Control for NOC wakeup NIU master m_w_2, offset: 0x98 */
  __IO uint32_t NIU_TO_MW3;                        /**< Timeout Control for NOC wakeup NIU master m_w_3, offset: 0x9C */
  __IO uint32_t NIU_TO_MW4;                        /**< Timeout Control for NOC wakeup NIU master m_w_4, offset: 0xA0 */
  __IO uint32_t NIU_TO_MW5;                        /**< Timeout Control for NOC wakeup NIU master m_w_5, offset: 0xA4 */
  __IO uint32_t NIU_TO_MW6;                        /**< Timeout Control for NOC wakeup NIU master m_w_6, offset: 0xA8 */
  __IO uint32_t NIU_TO_MW7;                        /**< Timeout Control for NOC wakeup NIU master m_w_7, offset: 0xAC */
  __IO uint32_t NIU_TO_MW8;                        /**< Timeout Control for NOC wakeup NIU master m_w_8, offset: 0xB0 */
  __IO uint32_t NIU_TO_MW9;                        /**< Timeout Control for NOC wakeup NIU master m_w_9, offset: 0xB4 */
  __IO uint32_t NIU_TO_MW10;                       /**< Timeout Control for NOC wakeup NIU master m_w_10, offset: 0xB8 */
  __IO uint32_t NIU_TO_MW11;                       /**< Timeout Control for NOC wakeup NIU master m_w_11, offset: 0xBC */
  __IO uint32_t QOS_CTL_0;                         /**< QoS control for wakeupmix initiators into NOC WAKEUP, offset: 0xC0 */
  __IO uint32_t QOS_CTL_1;                         /**< QoS control for wakeupmix initiators into NOC WAKEUP, offset: 0xC4 */
  __IO uint32_t QOS_CTL_2;                         /**< QoS control for wakeupmix initiators into NOC WAKEUP, continued, offset: 0xC8 */
       uint8_t RESERVED_7[4];
  __IO uint32_t IPG_STOP_CTL_0;                    /**< IPG_STOP control register 0, offset: 0xD0 */
  __I  uint32_t IPG_STOP_ACK_STATUS_0;             /**< IPG_STOP_ACK status 0, offset: 0xD4 */
  __IO uint32_t IPG_DOZE_CTL_0;                    /**< IPG_DOZE control 0, offset: 0xD8 */
       uint32_t IPG_WAIT_CTL_0;                    /**< IPG_WAIT control 0, offset: 0xDC */
  __IO uint32_t IPG_STOP_CTL_1;                    /**< IPG_STOP control register 1, offset: 0xE0 */
       uint32_t IPG_STOP_ACK_STATUS_1;             /**< IPG_STOP_ACK status 1, offset: 0xE4 */
  __IO uint32_t IPG_DOZE_CTL_1;                    /**< IPG_DOZE control 1, offset: 0xE8 */
  __IO uint32_t IPG_WAIT_CTL_1;                    /**< IPG_WAIT control 1, offset: 0xEC */
       uint8_t RESERVED_8[16];
  __IO uint32_t QREQ_CTL_0;                        /**< QREQ control register 0, offset: 0x100 */
  __I  uint32_t QACCEPT_STATUS_0;                  /**< QACCEPT status register 0, offset: 0x104 */
  __I  uint32_t QDENY_STATUS_0;                    /**< QDENY status register 0, offset: 0x108 */
  __I  uint32_t QACTIVE_STATUS_0;                  /**< QACTIVE status register 0, offset: 0x10C */
  __IO uint32_t QREQ_CTL_1;                        /**< QREQ control register 1, offset: 0x110 */
  __I  uint32_t QACCEPT_STATUS_1;                  /**< QACCEPT status register 1, offset: 0x114 */
  __I  uint32_t QDENY_STATUS_1;                    /**< QDENY status register 1, offset: 0x118 */
  __I  uint32_t QACTIVE_STATUS_1;                  /**< QACTIVE status register 1, offset: 0x11C */
  __IO uint32_t QREQ_CTL_2;                        /**< QREQ control register 2, offset: 0x120 */
  __I  uint32_t QACCEPT_STATUS_2;                  /**< QACCEPT status register 2, offset: 0x124 */
  __I  uint32_t QDENY_STATUS_2;                    /**< QDENY status register 2, offset: 0x128 */
  __I  uint32_t QACTIVE_STATUS_2;                  /**< QACTIVE status register 2, offset: 0x12C */
       uint8_t RESERVED_9[208];
  __IO uint32_t ATU_CONF;                          /**< ATU configuration control, offset: 0x200 */
       uint8_t RESERVED_10[176];
  __IO uint32_t FORCE_ON_OFF_3;                    /**< ipc_clk clock gating override controls force_on_off + force_on_off_sel, offset: 0x2B4 */
       uint8_t RESERVED_11[4];
  __IO uint32_t FORCE_ON_OFF_5;                    /**< ipc_clk clock gating override controls force_on_off + force_on_off_sel, offset: 0x2BC */
       uint8_t RESERVED_12[4];
  __IO uint32_t FORCE_ON_OFF_7;                    /**< ipc_clk clock gating override controls force_on_off + force_on_off_sel, offset: 0x2C4 */
  __IO uint32_t FORCE_ON_OFF_8;                    /**< ipc_clk clock gating override controls force_on_off + force_on_off_sel, offset: 0x2C8 */
       uint8_t RESERVED_13[8];
  __IO uint32_t FORCE_ON_OFF_11;                   /**< ipc_clk clock gating override controls force_on_off + force_on_off_sel, offset: 0x2D4 */
  __IO uint32_t FORCE_ON_OFF_12;                   /**< ipc_clk clock gating override controls force_on_off + force_on_off_sel, offset: 0x2D8 */
       uint8_t RESERVED_14[8];
  __IO uint32_t FORCE_ON_OFF_15;                   /**< ipc_clk clock gating override controls force_on_off + force_on_off_sel, offset: 0x2E4 */
  __IO uint32_t FORCE_ON_OFF_16;                   /**< ipc_clk clock gating override controls force_on_off + force_on_off_sel, offset: 0x2E8 */
       uint8_t RESERVED_15[4];
  __IO uint32_t GPT_IPP_IND_CAPIN1_MUX_CTRL;       /**< GPT IPP_IND_CAPIN1 MUX CTRL, offset: 0x2F0 */
  __IO uint32_t GPT_IPP_IND_CAPIN2_MUX_CTRL;       /**< GPT IPP_IND_CAPIN2 MUX CTRL, offset: 0x2F4 */
  __IO uint32_t GPT2_IPP_IND_CLKIN_CLK;            /**< GPT2 IPP IND CLKIN CLK, offset: 0x2F8 */
       uint8_t RESERVED_16[4];
  __IO uint32_t GPT3_IPP_IND_CLKIN_CLK;            /**< GPT3 IPP IND CLKIN CLK, offset: 0x300 */
  __IO uint32_t GPT4_IPP_IND_CLKIN_CLK;            /**< GPT4 IPP IND CLKIN CLK, offset: 0x304 */
  __IO uint32_t GPT5_IPP_IND_CLKIN_CLK;            /**< GPT5 IPP IND CLKIN CLK, offset: 0x308 */
  __IO uint32_t GPT2_3_4_5;                        /**< GPT PIN MUX, offset: 0x30C */
  __IO uint32_t ASRC_MCLKOUT_MUX;                  /**< ASRC MCLKOUT MUX, offset: 0x310 */
  __IO uint32_t BYPASS_AUDMIX_IP_CTRL;             /**< BYPASS_AUDMIX_IP_CTRL, offset: 0x314 */
} BLK_CTRL_WAKEUPMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_WAKEUPMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_WAKEUPMIX_Register_Masks BLK_CTRL_WAKEUPMIX Register Masks
 * @{
 */

/*! @name EARC_PLL_STATUS - EARC Audio PLL status bits */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_lock_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_lock_SHIFT (0U)
/*! earc_pll_lock - EARC AUDIO PLL lock status */
#define BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_lock(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_lock_SHIFT)) & BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_lock_MASK)

#define BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_lol_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_lol_SHIFT (1U)
/*! earc_pll_lol - EARC AUDIO PLL loss of lock status */
#define BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_lol(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_lol_SHIFT)) & BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_lol_MASK)

#define BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_powerup_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_powerup_SHIFT (2U)
/*! earc_pll_powerup - EARC AUDIO PLL powerup status */
#define BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_powerup(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_powerup_SHIFT)) & BLK_CTRL_WAKEUPMIX_EARC_PLL_STATUS_earc_pll_powerup_MASK)
/*! @} */

/*! @name SAI_CLK_SEL - sai3~5 mclk1~3 clk root mux settings */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_SHIFT (0U)
/*! SAI3_MCLK1 - SAI3 master clock 1 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_MASK (0x1EU)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_SHIFT (1U)
/*! SAI3_MCLK2 - SAI3 master clock 2 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_MASK (0x1E0U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_SHIFT (5U)
/*! SAI3_MCLK3 - SAI3 master clock 3 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_SHIFT (9U)
/*! SAI4_MCLK1 - SAI4 master clock 1 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_MASK (0x3C00U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_SHIFT (10U)
/*! SAI4_MCLK2 - SAI4 master clock 2 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_MASK (0x3C000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_SHIFT (14U)
/*! SAI4_MCLK3 - SAI4 master clock 3 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK1_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK1_SHIFT (18U)
/*! SAI5_MCLK1 - SAI5 master clock 1 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK1_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK1_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK2_MASK (0x780000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK2_SHIFT (19U)
/*! SAI5_MCLK2 - SAI5 master clock 2 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK2_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK2_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK3_MASK (0x7800000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK3_SHIFT (23U)
/*! SAI5_MCLK3 - SAI5 master clock 3 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK3_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI5_MCLK3_MASK)
/*! @} */

/*! @name VOLT_DETECT - Voltage detectors output */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_AON_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_AON_SHIFT (0U)
/*! supply_detector_AON - Voltage detectors output of AON */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_AON_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_AON_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_GPIO_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_GPIO_SHIFT (1U)
/*! supply_detector_GPIO - Voltage detectors output of GPIO */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_GPIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_GPIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_GPIO_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_SD2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_SD2_SHIFT (2U)
/*! supply_detector_SD2 - Voltage detectors output of SD2 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_SD2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_SD2_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_SD2_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_WAKEUP_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_WAKEUP_SHIFT (3U)
/*! supply_detector_WAKEUP - Voltage detectors output of WAKEUP */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_WAKEUP_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_WAKEUP_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_CCM_DAP_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_CCM_DAP_SHIFT (4U)
/*! supply_detector_CCM_DAP - Voltage detectors output of CCM DAP */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_CCM_DAP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_CCM_DAP_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_CCM_DAP_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_ENET_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_ENET_SHIFT (5U)
/*! supply_detector_ENET - Voltage detectors output of ENET */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_ENET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_ENET_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_supply_detector_ENET_MASK)
/*! @} */

/*! @name AXI_ATTR_CFG - AXI CACHE CONTROL BIT */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc1_SHIFT (0U)
/*! arcache_usdhc1 - Static value of arcache[1] = CACHEABLE (C) for AXI initiator usdhc1
 *  0b0..Non-cacheable reads
 *  0b1..Cacheable reads
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc1_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc1_SHIFT (1U)
/*! awcache_usdhc1 - Static value of awcache[1] = CACHEABLE (C) for AXI initiator usdhc1
 *  0b0..Non-cacheable writes
 *  0b1..Cacheable writes
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc1_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc2_SHIFT (2U)
/*! arcache_usdhc2 - Static value of arcache[1] = CACHEABLE (C) for AXI initiator usdhc2
 *  0b0..Non-cacheable reads
 *  0b1..Cacheable reads
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc2_SHIFT (3U)
/*! awcache_usdhc2 - Static value of awcache[1] = CACHEABLE (C) for AXI initiator usdhc2
 *  0b0..Non-cacheable writes
 *  0b1..Cacheable writes
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc2_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc3_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc3_SHIFT (4U)
/*! arcache_usdhc3 - Static value of arcache[1] = CACHEABLE (C) for AXI initiator usdhc3
 *  0b0..Non-cacheable reads
 *  0b1..Cacheable reads
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_usdhc3_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc3_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc3_SHIFT (5U)
/*! awcache_usdhc3 - Static value of awcache[1] = CACHEABLE (C) for AXI initiator usdhc3
 *  0b0..Non-cacheable writes
 *  0b1..Cacheable writes
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc3_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_usdhc3_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_ahbap_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_ahbap_SHIFT (6U)
/*! arcache_ahbap - Static value of arcache[1] = CACHEABLE (C) for AXI initiator ahbap
 *  0b0..Non-cacheable reads
 *  0b1..Cacheable reads
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_ahbap(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_ahbap_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_ahbap_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_ahbap_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_ahbap_SHIFT (7U)
/*! awcache_ahbap - Static value of awcache[1] = CACHEABLE (C) for AXI initiator ahbap
 *  0b0..Non-cacheable writes
 *  0b1..Cacheable writes
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_ahbap(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_ahbap_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_ahbap_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_xspi_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_xspi_SHIFT (8U)
/*! arcache_xspi - Static value of arcache[1] = CACHEABLE (C) for AXI initiator xspi
 *  0b0..Non-cacheable reads
 *  0b1..Cacheable reads
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_xspi(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_xspi_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_arcache_xspi_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_xspi_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_xspi_SHIFT (9U)
/*! awcache_xspi - Static value of awcache[1] = CACHEABLE (C) for AXI initiator xspi
 *  0b0..Non-cacheable writes
 *  0b1..Cacheable writes
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_xspi(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_xspi_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_awcache_xspi_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM33 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_wdog5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_edma2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C0 - IPG DEBUG mask bit for CA55 core0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_wdog5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_edma2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C1 - IPG DEBUG mask bit for CA55 core1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_wdog5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_edma2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C2 - IPG DEBUG mask bit for CA55 core2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_wdog5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_edma2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C3 - IPG DEBUG mask bit for CA55 core3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_wdog5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_edma2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM7 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_can3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_flexio2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpi2c8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpit2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpit2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpit2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpit2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpit2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi3_SHIFT (13U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi4_SHIFT (14U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi5_SHIFT (15U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi6_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi6_SHIFT (16U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi7_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi7_SHIFT (17U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi8_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi8_SHIFT (18U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lpspi8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lptmr2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lptmr2_SHIFT (19U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lptmr2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lptmr2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_lptmr2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm3_SHIFT (20U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm4_SHIFT (21U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm5_SHIFT (22U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm6_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm6_SHIFT (23U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_tpm6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog3_SHIFT (24U)
/*! wdog3 - WDOG3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog4_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog4_SHIFT (25U)
/*! wdog4 - WDOG4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_WDOG5_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog5_SHIFT (26U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_wdog5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_i3c2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_i3c2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_i3c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_i3c2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_i3c2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai3_SHIFT (28U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai4_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai4_SHIFT (29U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai5_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai5_SHIFT (30U)
/*! sai5 - SAI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_edma2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_edma2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_edma2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_edma2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_edma2_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CM33 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_edma3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_gpt5_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C0 - IPG DEBUG mask bit for CA55 core0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_edma3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_gpt5_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C1 - IPG DEBUG mask bit for CA55 core1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_edma3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_gpt5_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C2 - IPG DEBUG mask bit for CA55 core2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_edma3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_gpt5_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C3 - IPG DEBUG mask bit for CA55 core3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_edma3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_gpt5_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CM7 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_edma3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_edma3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_edma3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_edma3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_edma3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_sai6_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_sai6_SHIFT (1U)
/*! sai6 - SAI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_sai6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_sai6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_sai6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt5_SHIFT (5U)
/*! gpt5 - GPT5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_gpt5_MASK)
/*! @} */

/*! @name DBG_TRACE_CTL - DEBUG TRACE control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_clken_csswo_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_clken_csswo_SHIFT (0U)
/*! clken_csswo - Enable control of the debug/trace CSSWO clock. 0: trace_en_swo disabled, trace
 *    port clock OFF 1: trace_en_swo enabled, trace port clock ON
 */
#define BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_clken_csswo(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_clken_csswo_SHIFT)) & BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_clken_csswo_MASK)
/*! @} */

/*! @name SMMU_TBU_IRQ_SETUP - SMMU TBU IRQ resynchronization setup */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SMMU_TBU_IRQ_SETUP_stretch_ratio_MASK (0x3U)
#define BLK_CTRL_WAKEUPMIX_SMMU_TBU_IRQ_SETUP_stretch_ratio_SHIFT (0U)
/*! stretch_ratio - SMMU TBU IRQ stretch ratio for resynchronization
 *  0b00..Stretch IRQ pulse by 2
 *  0b01..Stretch IRQ pulse by 4
 *  0b10..Stretch IRQ pulse by 8
 *  0b11..Stretch IRQ pulse by 16
 */
#define BLK_CTRL_WAKEUPMIX_SMMU_TBU_IRQ_SETUP_stretch_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SMMU_TBU_IRQ_SETUP_stretch_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_SMMU_TBU_IRQ_SETUP_stretch_ratio_MASK)
/*! @} */

/*! @name INITIATOR_TIMEOUT - NOC initiator timeout status */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0r_timeout_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0r_timeout_SHIFT (0U)
/*! mw0r_timeout - Initiator timeout for mw0r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0w_timeout_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0w_timeout_SHIFT (1U)
/*! mw0w_timeout - Initiator timeout for mw0w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw0w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw1_timeout_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw1_timeout_SHIFT (2U)
/*! mw1_timeout - Initiator timeout for mw1_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw1_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw1_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw1_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2r_timeout_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2r_timeout_SHIFT (3U)
/*! mw2r_timeout - Initiator timeout for mw2r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2w_timeout_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2w_timeout_SHIFT (4U)
/*! mw2w_timeout - Initiator timeout for mw2w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw2w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3r_timeout_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3r_timeout_SHIFT (5U)
/*! mw3r_timeout - Initiator timeout for mw3r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3w_timeout_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3w_timeout_SHIFT (6U)
/*! mw3w_timeout - Initiator timeout for mw3w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw3w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4r_timeout_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4r_timeout_SHIFT (7U)
/*! mw4r_timeout - Initiator timeout for mw4r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4w_timeout_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4w_timeout_SHIFT (8U)
/*! mw4w_timeout - Initiator timeout for mw4w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw4w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5r_timeout_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5r_timeout_SHIFT (9U)
/*! mw5r_timeout - Initiator timeout for mw5r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5w_timeout_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5w_timeout_SHIFT (10U)
/*! mw5w_timeout - Initiator timeout for mw5w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw5w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6r_timeout_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6r_timeout_SHIFT (11U)
/*! mw6r_timeout - Initiator timeout for mw6r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6w_timeout_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6w_timeout_SHIFT (12U)
/*! mw6w_timeout - Initiator timeout for mw6w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw6w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw7_timeout_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw7_timeout_SHIFT (13U)
/*! mw7_timeout - Initiator timeout for mw7_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw7_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw7_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw7_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw8_timeout_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw8_timeout_SHIFT (14U)
/*! mw8_timeout - Initiator timeout for mw8_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw8_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw8_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw8_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw9_timeout_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw9_timeout_SHIFT (15U)
/*! mw9_timeout - Initiator timeout for mw9_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw9_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw9_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw9_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10r_timeout_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10r_timeout_SHIFT (16U)
/*! mw10r_timeout - Initiator timeout for mw10r_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10r_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10r_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10r_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10w_timeout_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10w_timeout_SHIFT (17U)
/*! mw10w_timeout - Initiator timeout for mw10w_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10w_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10w_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw10w_timeout_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw11_timeout_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw11_timeout_SHIFT (18U)
/*! mw11_timeout - Initiator timeout for mw11_timeout */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw11_timeout(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw11_timeout_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_mw11_timeout_MASK)
/*! @} */

/*! @name NIU_TO_MW0 - Timeout Control for NOC wakeup NIU master m_w_0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW0_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW1 - Timeout Control for NOC wakeup NIU master m_w_1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW1_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW2 - Timeout Control for NOC wakeup NIU master m_w_2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW2_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW3 - Timeout Control for NOC wakeup NIU master m_w_3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW3_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW4 - Timeout Control for NOC wakeup NIU master m_w_4 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW4_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW5 - Timeout Control for NOC wakeup NIU master m_w_5 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW5_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW6 - Timeout Control for NOC wakeup NIU master m_w_6 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW6_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW7 - Timeout Control for NOC wakeup NIU master m_w_7 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW7_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW8 - Timeout Control for NOC wakeup NIU master m_w_8 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW8_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW9 - Timeout Control for NOC wakeup NIU master m_w_9 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_upd_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_upd_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_upd(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_dis_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_dis_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_dis(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW9_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW10 - Timeout Control for NOC wakeup NIU master m_w_10 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_upd_MASK  (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_upd_SHIFT (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_upd(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_dis_MASK  (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_dis_SHIFT (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_dis(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW10_dis_MASK)
/*! @} */

/*! @name NIU_TO_MW11 - Timeout Control for NOC wakeup NIU master m_w_11 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_clk_div_ratio_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_clk_div_ratio_SHIFT (0U)
/*! clk_div_ratio - Timeout clock divider ratio selection
 *  0b000..Div by 4
 *  0b001..Div by 8
 *  0b010..Div by 16 (default)
 *  0b011..Div by 32
 *  0b100..Div by 64
 *  0b101..Div by 128
 *  0b110..Div by 256
 *  0b111..Div by 512
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_clk_div_ratio(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_clk_div_ratio_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_clk_div_ratio_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_upd_MASK  (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_upd_SHIFT (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_upd(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_upd_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_upd_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_dis_MASK  (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_dis_SHIFT (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_dis(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_dis_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MW11_dis_MASK)
/*! @} */

/*! @name QOS_CTL_0 - QoS control for wakeupmix initiators into NOC WAKEUP */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw2_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw2_SHIFT (0U)
/*! ar_qos_default_mw2 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw2_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw2_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw2_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw2_SHIFT (4U)
/*! aw_qos_default_mw2 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw2_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw2_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw3_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw3_SHIFT (8U)
/*! ar_qos_default_mw3 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw3_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw3_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw3_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw3_SHIFT (12U)
/*! aw_qos_default_mw3 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw3_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw3_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw10_MASK (0x70000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw10_SHIFT (16U)
/*! ar_qos_default_mw10 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw10_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw10_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw10_MASK (0x700000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw10_SHIFT (20U)
/*! aw_qos_default_mw10 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw10_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw10_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw9_MASK (0x7000000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw9_SHIFT (24U)
/*! ar_qos_default_mw9 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw9_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_ar_qos_default_mw9_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw9_MASK (0x70000000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw9_SHIFT (28U)
/*! aw_qos_default_mw9 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw9_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_0_aw_qos_default_mw9_MASK)
/*! @} */

/*! @name QOS_CTL_1 - QoS control for wakeupmix initiators into NOC WAKEUP */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw4_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw4_SHIFT (0U)
/*! ar_qos_default_mw4 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw4_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw4_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw4_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw4_SHIFT (4U)
/*! aw_qos_default_mw4 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw4_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw4_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw5_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw5_SHIFT (8U)
/*! ar_qos_default_mw5 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw5_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw5_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw5_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw5_SHIFT (12U)
/*! aw_qos_default_mw5 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw5_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw5_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw6_MASK (0x70000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw6_SHIFT (16U)
/*! ar_qos_default_mw6 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw6_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw6_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw6_MASK (0x700000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw6_SHIFT (20U)
/*! aw_qos_default_mw6 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw6_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw6_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw11_MASK (0x7000000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw11_SHIFT (24U)
/*! ar_qos_default_mw11 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw11_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_ar_qos_default_mw11_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw11_MASK (0x70000000U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw11_SHIFT (28U)
/*! aw_qos_default_mw11 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw11_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_1_aw_qos_default_mw11_MASK)
/*! @} */

/*! @name QOS_CTL_2 - QoS control for wakeupmix initiators into NOC WAKEUP, continued */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_ar_qos_default_mw8_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_ar_qos_default_mw8_SHIFT (0U)
/*! ar_qos_default_mw8 - Read-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_ar_qos_default_mw8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_2_ar_qos_default_mw8_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_2_ar_qos_default_mw8_MASK)

#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_aw_qos_default_mw8_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_aw_qos_default_mw8_SHIFT (4U)
/*! aw_qos_default_mw8 - Write-channel QOS default value */
#define BLK_CTRL_WAKEUPMIX_QOS_CTL_2_aw_qos_default_mw8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QOS_CTL_2_aw_qos_default_mw8_SHIFT)) & BLK_CTRL_WAKEUPMIX_QOS_CTL_2_aw_qos_default_mw8_MASK)
/*! @} */

/*! @name IPG_STOP_CTL_0 - IPG_STOP control register 0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can2_stop_enable_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can2_stop_enable_SHIFT (0U)
/*! can2_stop_enable - CAN2 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can2_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can2_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can2_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can3_stop_enable_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can3_stop_enable_SHIFT (1U)
/*! can3_stop_enable - CAN3 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can3_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can3_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can3_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can4_stop_enable_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can4_stop_enable_SHIFT (2U)
/*! can4_stop_enable - CAN4 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can4_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can4_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can4_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can5_stop_enable_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can5_stop_enable_SHIFT (3U)
/*! can5_stop_enable - CAN5 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can5_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can5_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_can5_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_edma2_stop_enable_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_edma2_stop_enable_SHIFT (4U)
/*! edma2_stop_enable - EDMA2 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_edma2_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_edma2_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_edma2_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_edma3_stop_enable_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_edma3_stop_enable_SHIFT (5U)
/*! edma3_stop_enable - EDMA3 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_edma3_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_edma3_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_edma3_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_flexspi1_stop_enable_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_flexspi1_stop_enable_SHIFT (8U)
/*! flexspi1_stop_enable - FlexSPI1 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_flexspi1_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_flexspi1_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_flexspi1_stop_enable_MASK)
/*! @} */

/*! @name IPG_STOP_ACK_STATUS_0 - IPG_STOP_ACK status 0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can2_stop_ack_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can2_stop_ack_SHIFT (0U)
/*! can2_stop_ack - CAN2 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can2_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can2_stop_ack_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can2_stop_ack_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can3_stop_ack_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can3_stop_ack_SHIFT (1U)
/*! can3_stop_ack - CAN3 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can3_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can3_stop_ack_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can3_stop_ack_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can4_stop_ack_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can4_stop_ack_SHIFT (2U)
/*! can4_stop_ack - CAN4 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can4_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can4_stop_ack_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can4_stop_ack_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can5_stop_ack_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can5_stop_ack_SHIFT (3U)
/*! can5_stop_ack - CAN5 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can5_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can5_stop_ack_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_can5_stop_ack_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_edma2_stop_ack_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_edma2_stop_ack_SHIFT (4U)
/*! edma2_stop_ack - EDMA2 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_edma2_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_edma2_stop_ack_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_edma2_stop_ack_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_edma3_stop_ack_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_edma3_stop_ack_SHIFT (5U)
/*! edma3_stop_ack - EDMA3 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_edma3_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_edma3_stop_ack_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_edma3_stop_ack_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_flexspi1_stop_ack_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_flexspi1_stop_ack_SHIFT (8U)
/*! flexspi1_stop_ack - FlexSPI1 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_flexspi1_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_flexspi1_stop_ack_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_flexspi1_stop_ack_MASK)
/*! @} */

/*! @name IPG_DOZE_CTL_0 - IPG_DOZE control 0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can2_doze_enable_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can2_doze_enable_SHIFT (0U)
/*! can2_doze_enable - CAN2 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can2_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can2_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can2_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can3_doze_enable_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can3_doze_enable_SHIFT (1U)
/*! can3_doze_enable - CAN3 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can3_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can3_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can3_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can4_doze_enable_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can4_doze_enable_SHIFT (2U)
/*! can4_doze_enable - CAN4 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can4_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can4_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can4_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can5_doze_enable_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can5_doze_enable_SHIFT (3U)
/*! can5_doze_enable - CAN5 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can5_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can5_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_can5_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexio1_doze_enable_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexio1_doze_enable_SHIFT (6U)
/*! flexio1_doze_enable - FlexIO1 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexio1_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexio1_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexio1_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexio2_doze_enable_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexio2_doze_enable_SHIFT (7U)
/*! flexio2_doze_enable - FlexIO2 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexio2_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexio2_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexio2_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexspi1_doze_enable_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexspi1_doze_enable_SHIFT (8U)
/*! flexspi1_doze_enable - FlexSPI1 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexspi1_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexspi1_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_flexspi1_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c3_doze_enable_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c3_doze_enable_SHIFT (9U)
/*! lpi2c3_doze_enable - LPI2C3 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c3_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c3_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c3_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c4_doze_enable_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c4_doze_enable_SHIFT (10U)
/*! lpi2c4_doze_enable - LPI2C4 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c4_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c4_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c4_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c5_doze_enable_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c5_doze_enable_SHIFT (11U)
/*! lpi2c5_doze_enable - LPI2C5 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c5_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c5_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c5_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c6_doze_enable_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c6_doze_enable_SHIFT (12U)
/*! lpi2c6_doze_enable - LPI2C6 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c6_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c6_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c6_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c7_doze_enable_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c7_doze_enable_SHIFT (13U)
/*! lpi2c7_doze_enable - LPI2C7 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c7_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c7_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c7_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c8_doze_enable_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c8_doze_enable_SHIFT (14U)
/*! lpi2c8_doze_enable - LPI2C8 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c8_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c8_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpi2c8_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpit2_doze_enable_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpit2_doze_enable_SHIFT (15U)
/*! lpit2_doze_enable - LPIT2 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpit2_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpit2_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpit2_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi3_doze_enable_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi3_doze_enable_SHIFT (16U)
/*! lpspi3_doze_enable - LPSPI3 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi3_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi3_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi3_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi4_doze_enable_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi4_doze_enable_SHIFT (17U)
/*! lpspi4_doze_enable - LPSPI4 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi4_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi4_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi4_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi5_doze_enable_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi5_doze_enable_SHIFT (18U)
/*! lpspi5_doze_enable - LPSPI5 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi5_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi5_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi5_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi6_doze_enable_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi6_doze_enable_SHIFT (19U)
/*! lpspi6_doze_enable - LPSPI6 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi6_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi6_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi6_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi7_doze_enable_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi7_doze_enable_SHIFT (20U)
/*! lpspi7_doze_enable - LPSPI7 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi7_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi7_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi7_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi8_doze_enable_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi8_doze_enable_SHIFT (21U)
/*! lpspi8_doze_enable - LPSPI8 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi8_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi8_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpspi8_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart3_doze_enable_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart3_doze_enable_SHIFT (22U)
/*! lpuart3_doze_enable - LPUART3 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart3_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart3_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart3_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart4_doze_enable_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart4_doze_enable_SHIFT (23U)
/*! lpuart4_doze_enable - LPUART4 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart4_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart4_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart4_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart5_doze_enable_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart5_doze_enable_SHIFT (24U)
/*! lpuart5_doze_enable - LPUART5 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart5_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart5_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart5_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart6_doze_enable_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart6_doze_enable_SHIFT (25U)
/*! lpuart6_doze_enable - LPUART6 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart6_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart6_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart6_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart7_doze_enable_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart7_doze_enable_SHIFT (26U)
/*! lpuart7_doze_enable - LPUART7 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart7_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart7_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart7_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart8_doze_enable_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart8_doze_enable_SHIFT (27U)
/*! lpuart8_doze_enable - LPUART8 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart8_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart8_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_0_lpuart8_doze_enable_MASK)
/*! @} */

/*! @name IPG_STOP_CTL_1 - IPG_STOP control register 1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm3_stop_enable_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm3_stop_enable_SHIFT (3U)
/*! tpm3_stop_enable - TPM3 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm3_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm3_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm3_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm4_stop_enable_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm4_stop_enable_SHIFT (4U)
/*! tpm4_stop_enable - TPM4 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm4_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm4_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm4_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm5_stop_enable_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm5_stop_enable_SHIFT (5U)
/*! tpm5_stop_enable - TPM5 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm5_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm5_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm5_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm6_stop_enable_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm6_stop_enable_SHIFT (6U)
/*! tpm6_stop_enable - TPM6 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm6_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm6_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_tpm6_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog3_stop_enable_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog3_stop_enable_SHIFT (7U)
/*! wdog3_stop_enable - WDOG3 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog3_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog3_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog3_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog4_stop_enable_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog4_stop_enable_SHIFT (8U)
/*! wdog4_stop_enable - WDOG4 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog4_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog4_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog4_stop_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog5_stop_enable_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog5_stop_enable_SHIFT (9U)
/*! wdog5_stop_enable - WDOG5 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog5_stop_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog5_stop_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_wdog5_stop_enable_MASK)
/*! @} */

/*! @name IPG_DOZE_CTL_1 - IPG_DOZE control 1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm3_doze_enable_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm3_doze_enable_SHIFT (3U)
/*! tpm3_doze_enable - TPM3 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm3_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm3_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm3_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm4_doze_enable_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm4_doze_enable_SHIFT (4U)
/*! tpm4_doze_enable - TPM4 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm4_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm4_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm4_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm5_doze_enable_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm5_doze_enable_SHIFT (5U)
/*! tpm5_doze_enable - TPM5 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm5_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm5_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm5_doze_enable_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm6_doze_enable_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm6_doze_enable_SHIFT (6U)
/*! tpm6_doze_enable - TPM6 ipg_doze control */
#define BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm6_doze_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm6_doze_enable_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DOZE_CTL_1_tpm6_doze_enable_MASK)
/*! @} */

/*! @name IPG_WAIT_CTL_1 - IPG_WAIT control 1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog3_wait_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog3_wait_SHIFT (7U)
/*! wdog3_wait - WDOG3 ipg_wait control */
#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog3_wait(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog3_wait_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog3_wait_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog4_wait_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog4_wait_SHIFT (8U)
/*! wdog4_wait - WDOG4 ipg_wait control */
#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog4_wait(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog4_wait_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog4_wait_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog5_wait_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog5_wait_SHIFT (9U)
/*! wdog5_wait - WDOG5 ipg_wait control */
#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog5_wait(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog5_wait_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_wdog5_wait_MASK)
/*! @} */

/*! @name QREQ_CTL_0 - QREQ control register 0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can2_qreq_n_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can2_qreq_n_SHIFT (0U)
/*! can2_qreq_n - CAN2 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can2_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can2_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can2_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can3_qreq_n_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can3_qreq_n_SHIFT (1U)
/*! can3_qreq_n - CAN3 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can3_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can3_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can3_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can4_qreq_n_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can4_qreq_n_SHIFT (2U)
/*! can4_qreq_n - CAN4 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can4_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can4_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can4_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can5_qreq_n_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can5_qreq_n_SHIFT (3U)
/*! can5_qreq_n - CAN5 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can5_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can5_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_can5_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_edma2_qreq_n_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_edma2_qreq_n_SHIFT (4U)
/*! edma2_qreq_n - EDMA2 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_edma2_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_edma2_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_edma2_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_edma3_qreq_n_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_edma3_qreq_n_SHIFT (5U)
/*! edma3_qreq_n - EDMA3 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_edma3_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_edma3_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_edma3_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexio1_qreq_n_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexio1_qreq_n_SHIFT (6U)
/*! flexio1_qreq_n - FlexIO1 flexio qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexio1_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexio1_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexio1_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexio2_qreq_n_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexio2_qreq_n_SHIFT (7U)
/*! flexio2_qreq_n - FlexIO2 flexio qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexio2_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexio2_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexio2_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexspi1_qreq_n_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexspi1_qreq_n_SHIFT (8U)
/*! flexspi1_qreq_n - FlexSPI1 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexspi1_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexspi1_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_flexspi1_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c3_qreq_n_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c3_qreq_n_SHIFT (9U)
/*! lpi2c3_qreq_n - LPI2C3 lpi2c qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c3_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c3_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c3_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c4_qreq_n_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c4_qreq_n_SHIFT (10U)
/*! lpi2c4_qreq_n - LPI2C4 lpi2c qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c4_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c4_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c4_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c5_qreq_n_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c5_qreq_n_SHIFT (11U)
/*! lpi2c5_qreq_n - LPI2C5 lpi2c qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c5_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c5_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c5_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c6_qreq_n_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c6_qreq_n_SHIFT (12U)
/*! lpi2c6_qreq_n - LPI2C6 lpi2c qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c6_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c6_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c6_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c7_qreq_n_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c7_qreq_n_SHIFT (13U)
/*! lpi2c7_qreq_n - LPI2C7 lpi2c qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c7_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c7_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c7_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c8_qreq_n_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c8_qreq_n_SHIFT (14U)
/*! lpi2c8_qreq_n - LPI2C8 lpi2c qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c8_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c8_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpi2c8_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpit2_qreq_n_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpit2_qreq_n_SHIFT (15U)
/*! lpit2_qreq_n - LPIT2 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpit2_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpit2_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpit2_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi3_qreq_n_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi3_qreq_n_SHIFT (16U)
/*! lpspi3_qreq_n - LPSPI3 lpspi qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi3_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi3_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi3_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi4_qreq_n_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi4_qreq_n_SHIFT (17U)
/*! lpspi4_qreq_n - LPSPI4 lpspi qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi4_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi4_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi4_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi5_qreq_n_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi5_qreq_n_SHIFT (18U)
/*! lpspi5_qreq_n - LPSPI5 lpspi qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi5_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi5_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi5_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi6_qreq_n_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi6_qreq_n_SHIFT (19U)
/*! lpspi6_qreq_n - LPSPI6 lpspi qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi6_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi6_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi6_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi7_qreq_n_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi7_qreq_n_SHIFT (20U)
/*! lpspi7_qreq_n - LPSPI7 lpspi qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi7_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi7_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi7_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi8_qreq_n_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi8_qreq_n_SHIFT (21U)
/*! lpspi8_qreq_n - LPSPI8 lpspi qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi8_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi8_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpspi8_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart3_qreq_n_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart3_qreq_n_SHIFT (22U)
/*! lpuart3_qreq_n - LPUART3 lpuart qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart3_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart3_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart3_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart4_qreq_n_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart4_qreq_n_SHIFT (23U)
/*! lpuart4_qreq_n - LPUART4 lpuart qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart4_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart4_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart4_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart5_qreq_n_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart5_qreq_n_SHIFT (24U)
/*! lpuart5_qreq_n - LPUART5 lpuart qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart5_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart5_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart5_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart6_qreq_n_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart6_qreq_n_SHIFT (25U)
/*! lpuart6_qreq_n - LPUART6 lpuart qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart6_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart6_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart6_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart7_qreq_n_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart7_qreq_n_SHIFT (26U)
/*! lpuart7_qreq_n - LPUART7 lpuart qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart7_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart7_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart7_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart8_qreq_n_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart8_qreq_n_SHIFT (27U)
/*! lpuart8_qreq_n - LPUART8 lpuart qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart8_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart8_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_lpuart8_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio2_qreq_n_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio2_qreq_n_SHIFT (28U)
/*! gpio2_qreq_n - GPIO2 AHB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio2_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio2_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio2_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio3_qreq_n_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio3_qreq_n_SHIFT (29U)
/*! gpio3_qreq_n - GPIO3 AHB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio3_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio3_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio3_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio4_qreq_n_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio4_qreq_n_SHIFT (30U)
/*! gpio4_qreq_n - GPIO4 AHB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio4_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio4_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio4_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio5_qreq_n_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio5_qreq_n_SHIFT (31U)
/*! gpio5_qreq_n - GPIO5 AHB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio5_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio5_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_gpio5_qreq_n_MASK)
/*! @} */

/*! @name QACCEPT_STATUS_0 - QACCEPT status register 0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can2_qaccept_n_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can2_qaccept_n_SHIFT (0U)
/*! can2_qaccept_n - CAN2 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can2_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can2_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can2_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can3_qaccept_n_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can3_qaccept_n_SHIFT (1U)
/*! can3_qaccept_n - CAN3 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can3_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can3_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can3_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can4_qaccept_n_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can4_qaccept_n_SHIFT (2U)
/*! can4_qaccept_n - CAN4 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can4_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can4_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can4_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can5_qaccept_n_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can5_qaccept_n_SHIFT (3U)
/*! can5_qaccept_n - CAN5 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can5_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can5_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_can5_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_edma2_qaccept_n_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_edma2_qaccept_n_SHIFT (4U)
/*! edma2_qaccept_n - EDMA2 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_edma2_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_edma2_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_edma2_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_edma3_qaccept_n_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_edma3_qaccept_n_SHIFT (5U)
/*! edma3_qaccept_n - EDMA3 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_edma3_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_edma3_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_edma3_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexio1_qaccept_n_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexio1_qaccept_n_SHIFT (6U)
/*! flexio1_qaccept_n - FlexIO1 flexio qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexio1_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexio1_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexio1_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexio2_qaccept_n_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexio2_qaccept_n_SHIFT (7U)
/*! flexio2_qaccept_n - FlexIO2 flexio qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexio2_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexio2_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexio2_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexspi1_qaccept_n_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexspi1_qaccept_n_SHIFT (8U)
/*! flexspi1_qaccept_n - FlexSPI1 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexspi1_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexspi1_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_flexspi1_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c3_qaccept_n_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c3_qaccept_n_SHIFT (9U)
/*! lpi2c3_qaccept_n - LPI2C3 lpi2c qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c3_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c3_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c3_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c4_qaccept_n_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c4_qaccept_n_SHIFT (10U)
/*! lpi2c4_qaccept_n - LPI2C4 lpi2c qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c4_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c4_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c4_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c5_qaccept_n_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c5_qaccept_n_SHIFT (11U)
/*! lpi2c5_qaccept_n - LPI2C5 lpi2c qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c5_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c5_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c5_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c6_qaccept_n_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c6_qaccept_n_SHIFT (12U)
/*! lpi2c6_qaccept_n - LPI2C6 lpi2c qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c6_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c6_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c6_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c7_qaccept_n_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c7_qaccept_n_SHIFT (13U)
/*! lpi2c7_qaccept_n - LPI2C7 lpi2c qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c7_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c7_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c7_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c8_qaccept_n_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c8_qaccept_n_SHIFT (14U)
/*! lpi2c8_qaccept_n - LPI2C8 lpi2c qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c8_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c8_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpi2c8_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpit2_qaccept_n_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpit2_qaccept_n_SHIFT (15U)
/*! lpit2_qaccept_n - LPIT2 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpit2_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpit2_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpit2_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi3_qaccept_n_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi3_qaccept_n_SHIFT (16U)
/*! lpspi3_qaccept_n - LPSPI3 lpspi qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi3_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi3_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi3_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi4_qaccept_n_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi4_qaccept_n_SHIFT (17U)
/*! lpspi4_qaccept_n - LPSPI4 lpspi qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi4_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi4_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi4_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi5_qaccept_n_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi5_qaccept_n_SHIFT (18U)
/*! lpspi5_qaccept_n - LPSPI5 lpspi qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi5_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi5_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi5_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi6_qaccept_n_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi6_qaccept_n_SHIFT (19U)
/*! lpspi6_qaccept_n - LPSPI6 lpspi qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi6_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi6_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi6_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi7_qaccept_n_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi7_qaccept_n_SHIFT (20U)
/*! lpspi7_qaccept_n - LPSPI7 lpspi qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi7_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi7_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi7_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi8_qaccept_n_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi8_qaccept_n_SHIFT (21U)
/*! lpspi8_qaccept_n - LPSPI8 lpspi qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi8_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi8_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpspi8_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart3_qaccept_n_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart3_qaccept_n_SHIFT (22U)
/*! lpuart3_qaccept_n - LPUART3 lpuart qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart3_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart3_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart3_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart4_qaccept_n_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart4_qaccept_n_SHIFT (23U)
/*! lpuart4_qaccept_n - LPUART4 lpuart qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart4_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart4_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart4_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart5_qaccept_n_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart5_qaccept_n_SHIFT (24U)
/*! lpuart5_qaccept_n - LPUART5 lpuart qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart5_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart5_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart5_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart6_qaccept_n_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart6_qaccept_n_SHIFT (25U)
/*! lpuart6_qaccept_n - LPUART6 lpuart qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart6_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart6_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart6_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart7_qaccept_n_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart7_qaccept_n_SHIFT (26U)
/*! lpuart7_qaccept_n - LPUART7 lpuart qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart7_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart7_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart7_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart8_qaccept_n_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart8_qaccept_n_SHIFT (27U)
/*! lpuart8_qaccept_n - LPUART8 lpuart qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart8_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart8_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_lpuart8_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio2_qaccept_n_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio2_qaccept_n_SHIFT (28U)
/*! gpio2_qaccept_n - GPIO2 AHB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio2_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio2_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio2_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio3_qaccept_n_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio3_qaccept_n_SHIFT (29U)
/*! gpio3_qaccept_n - GPIO3 AHB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio3_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio3_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio3_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio4_qaccept_n_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio4_qaccept_n_SHIFT (30U)
/*! gpio4_qaccept_n - GPIO4 AHB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio4_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio4_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio4_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio5_qaccept_n_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio5_qaccept_n_SHIFT (31U)
/*! gpio5_qaccept_n - GPIO5 AHB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio5_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio5_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_gpio5_qaccept_n_MASK)
/*! @} */

/*! @name QDENY_STATUS_0 - QDENY status register 0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can2_qdeny_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can2_qdeny_SHIFT (0U)
/*! can2_qdeny - CAN2 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can2_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can2_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can2_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can3_qdeny_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can3_qdeny_SHIFT (1U)
/*! can3_qdeny - CAN3 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can3_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can3_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can3_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can4_qdeny_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can4_qdeny_SHIFT (2U)
/*! can4_qdeny - CAN4 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can4_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can4_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can4_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can5_qdeny_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can5_qdeny_SHIFT (3U)
/*! can5_qdeny - CAN5 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can5_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can5_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_can5_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_edma2_qdeny_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_edma2_qdeny_SHIFT (4U)
/*! edma2_qdeny - EDMA2 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_edma2_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_edma2_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_edma2_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_edma3_qdeny_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_edma3_qdeny_SHIFT (5U)
/*! edma3_qdeny - EDMA3 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_edma3_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_edma3_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_edma3_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexio1_qdeny_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexio1_qdeny_SHIFT (6U)
/*! flexio1_qdeny - FlexIO1 flexio qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexio1_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexio1_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexio1_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexio2_qdeny_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexio2_qdeny_SHIFT (7U)
/*! flexio2_qdeny - FlexIO2 flexio qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexio2_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexio2_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexio2_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexspi1_qdeny_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexspi1_qdeny_SHIFT (8U)
/*! flexspi1_qdeny - FlexSPI1 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexspi1_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexspi1_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_flexspi1_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c3_qdeny_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c3_qdeny_SHIFT (9U)
/*! lpi2c3_qdeny - LPI2C3 lpi2c qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c3_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c3_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c3_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c4_qdeny_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c4_qdeny_SHIFT (10U)
/*! lpi2c4_qdeny - LPI2C4 lpi2c qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c4_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c4_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c4_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c5_qdeny_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c5_qdeny_SHIFT (11U)
/*! lpi2c5_qdeny - LPI2C5 lpi2c qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c5_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c5_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c5_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c6_qdeny_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c6_qdeny_SHIFT (12U)
/*! lpi2c6_qdeny - LPI2C6 lpi2c qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c6_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c6_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c6_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c7_qdeny_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c7_qdeny_SHIFT (13U)
/*! lpi2c7_qdeny - LPI2C7 lpi2c qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c7_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c7_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c7_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c8_qdeny_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c8_qdeny_SHIFT (14U)
/*! lpi2c8_qdeny - LPI2C8 lpi2c qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c8_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c8_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpi2c8_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpit2_qdeny_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpit2_qdeny_SHIFT (15U)
/*! lpit2_qdeny - LPIT2 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpit2_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpit2_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpit2_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi3_qdeny_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi3_qdeny_SHIFT (16U)
/*! lpspi3_qdeny - LPSPI3 lpspi qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi3_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi3_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi3_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi4_qdeny_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi4_qdeny_SHIFT (17U)
/*! lpspi4_qdeny - LPSPI4 lpspi qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi4_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi4_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi4_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi5_qdeny_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi5_qdeny_SHIFT (18U)
/*! lpspi5_qdeny - LPSPI5 lpspi qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi5_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi5_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi5_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi6_qdeny_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi6_qdeny_SHIFT (19U)
/*! lpspi6_qdeny - LPSPI6 lpspi qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi6_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi6_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi6_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi7_qdeny_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi7_qdeny_SHIFT (20U)
/*! lpspi7_qdeny - LPSPI7 lpspi qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi7_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi7_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi7_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi8_qdeny_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi8_qdeny_SHIFT (21U)
/*! lpspi8_qdeny - LPSPI8 lpspi qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi8_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi8_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpspi8_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart3_qdeny_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart3_qdeny_SHIFT (22U)
/*! lpuart3_qdeny - LPUART3 lpuart qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart3_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart3_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart3_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart4_qdeny_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart4_qdeny_SHIFT (23U)
/*! lpuart4_qdeny - LPUART4 lpuart qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart4_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart4_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart4_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart5_qdeny_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart5_qdeny_SHIFT (24U)
/*! lpuart5_qdeny - LPUART5 lpuart qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart5_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart5_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart5_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart6_qdeny_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart6_qdeny_SHIFT (25U)
/*! lpuart6_qdeny - LPUART6 lpuart qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart6_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart6_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart6_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart7_qdeny_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart7_qdeny_SHIFT (26U)
/*! lpuart7_qdeny - LPUART7 lpuart qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart7_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart7_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart7_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart8_qdeny_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart8_qdeny_SHIFT (27U)
/*! lpuart8_qdeny - LPUART8 lpuart qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart8_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart8_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_lpuart8_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio2_qdeny_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio2_qdeny_SHIFT (28U)
/*! gpio2_qdeny - GPIO2 AHB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio2_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio2_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio2_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio3_qdeny_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio3_qdeny_SHIFT (29U)
/*! gpio3_qdeny - GPIO3 AHB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio3_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio3_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio3_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio4_qdeny_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio4_qdeny_SHIFT (30U)
/*! gpio4_qdeny - GPIO4 AHB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio4_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio4_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio4_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio5_qdeny_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio5_qdeny_SHIFT (31U)
/*! gpio5_qdeny - GPIO5 AHB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio5_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio5_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_0_gpio5_qdeny_MASK)
/*! @} */

/*! @name QACTIVE_STATUS_0 - QACTIVE status register 0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can2_qactive_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can2_qactive_SHIFT (0U)
/*! can2_qactive - CAN2 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can2_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can2_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can2_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can3_qactive_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can3_qactive_SHIFT (1U)
/*! can3_qactive - CAN3 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can3_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can3_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can3_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can4_qactive_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can4_qactive_SHIFT (2U)
/*! can4_qactive - CAN4 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can4_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can4_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can4_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can5_qactive_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can5_qactive_SHIFT (3U)
/*! can5_qactive - CAN5 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can5_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can5_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_can5_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_edma2_qactive_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_edma2_qactive_SHIFT (4U)
/*! edma2_qactive - EDMA2 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_edma2_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_edma2_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_edma2_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_edma3_qactive_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_edma3_qactive_SHIFT (5U)
/*! edma3_qactive - EDMA3 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_edma3_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_edma3_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_edma3_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexio1_qactive_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexio1_qactive_SHIFT (6U)
/*! flexio1_qactive - FlexIO1 flexio qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexio1_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexio1_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexio1_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexio2_qactive_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexio2_qactive_SHIFT (7U)
/*! flexio2_qactive - FlexIO2 flexio qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexio2_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexio2_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexio2_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexspi1_qactive_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexspi1_qactive_SHIFT (8U)
/*! flexspi1_qactive - FlexSPI1 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexspi1_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexspi1_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_flexspi1_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c3_qactive_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c3_qactive_SHIFT (9U)
/*! lpi2c3_qactive - LPI2C3 lpi2c qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c3_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c3_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c3_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c4_qactive_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c4_qactive_SHIFT (10U)
/*! lpi2c4_qactive - LPI2C4 lpi2c qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c4_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c4_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c4_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c5_qactive_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c5_qactive_SHIFT (11U)
/*! lpi2c5_qactive - LPI2C5 lpi2c qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c5_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c5_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c5_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c6_qactive_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c6_qactive_SHIFT (12U)
/*! lpi2c6_qactive - LPI2C6 lpi2c qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c6_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c6_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c6_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c7_qactive_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c7_qactive_SHIFT (13U)
/*! lpi2c7_qactive - LPI2C7 lpi2c qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c7_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c7_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c7_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c8_qactive_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c8_qactive_SHIFT (14U)
/*! lpi2c8_qactive - LPI2C8 lpi2c qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c8_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c8_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpi2c8_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpit2_qactive_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpit2_qactive_SHIFT (15U)
/*! lpit2_qactive - LPIT2 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpit2_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpit2_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpit2_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi3_qactive_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi3_qactive_SHIFT (16U)
/*! lpspi3_qactive - LPSPI3 lpspi qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi3_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi3_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi3_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi4_qactive_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi4_qactive_SHIFT (17U)
/*! lpspi4_qactive - LPSPI4 lpspi qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi4_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi4_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi4_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi5_qactive_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi5_qactive_SHIFT (18U)
/*! lpspi5_qactive - LPSPI5 lpspi qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi5_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi5_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi5_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi6_qactive_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi6_qactive_SHIFT (19U)
/*! lpspi6_qactive - LPSPI6 lpspi qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi6_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi6_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi6_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi7_qactive_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi7_qactive_SHIFT (20U)
/*! lpspi7_qactive - LPSPI7 lpspi qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi7_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi7_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi7_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi8_qactive_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi8_qactive_SHIFT (21U)
/*! lpspi8_qactive - LPSPI8 lpspi qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi8_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi8_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpspi8_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart3_qactive_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart3_qactive_SHIFT (22U)
/*! lpuart3_qactive - LPUART3 lpuart qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart3_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart3_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart3_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart4_qactive_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart4_qactive_SHIFT (23U)
/*! lpuart4_qactive - LPUART4 lpuart qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart4_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart4_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart4_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart5_qactive_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart5_qactive_SHIFT (24U)
/*! lpuart5_qactive - LPUART5 lpuart qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart5_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart5_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart5_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart6_qactive_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart6_qactive_SHIFT (25U)
/*! lpuart6_qactive - LPUART6 lpuart qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart6_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart6_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart6_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart7_qactive_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart7_qactive_SHIFT (26U)
/*! lpuart7_qactive - LPUART7 lpuart qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart7_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart7_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart7_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart8_qactive_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart8_qactive_SHIFT (27U)
/*! lpuart8_qactive - LPUART8 lpuart qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart8_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart8_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_lpuart8_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio2_qactive_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio2_qactive_SHIFT (28U)
/*! gpio2_qactive - GPIO2 AHB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio2_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio2_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio2_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio3_qactive_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio3_qactive_SHIFT (29U)
/*! gpio3_qactive - GPIO3 AHB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio3_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio3_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio3_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio4_qactive_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio4_qactive_SHIFT (30U)
/*! gpio4_qactive - GPIO4 AHB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio4_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio4_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio4_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio5_qactive_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio5_qactive_SHIFT (31U)
/*! gpio5_qactive - GPIO5 AHB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio5_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio5_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_gpio5_qactive_MASK)
/*! @} */

/*! @name QREQ_CTL_1 - QREQ control register 1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm3_qreq_n_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm3_qreq_n_SHIFT (3U)
/*! tpm3_qreq_n - TPM3 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm3_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm3_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm3_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm4_qreq_n_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm4_qreq_n_SHIFT (4U)
/*! tpm4_qreq_n - TPM4 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm4_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm4_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm4_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm5_qreq_n_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm5_qreq_n_SHIFT (5U)
/*! tpm5_qreq_n - TPM5 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm5_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm5_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm5_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm6_qreq_n_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm6_qreq_n_SHIFT (6U)
/*! tpm6_qreq_n - TPM6 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm6_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm6_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_tpm6_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog3_qreq_n_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog3_qreq_n_SHIFT (7U)
/*! wdog3_qreq_n - WDOG3 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog3_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog3_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog3_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog4_qreq_n_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog4_qreq_n_SHIFT (8U)
/*! wdog4_qreq_n - WDOG4 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog4_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog4_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog4_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog5_qreq_n_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog5_qreq_n_SHIFT (9U)
/*! wdog5_qreq_n - WDOG5 qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog5_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog5_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_1_wdog5_qreq_n_MASK)
/*! @} */

/*! @name QACCEPT_STATUS_1 - QACCEPT status register 1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm3_qaccept_n_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm3_qaccept_n_SHIFT (3U)
/*! tpm3_qaccept_n - TPM3 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm3_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm3_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm3_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm4_qaccept_n_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm4_qaccept_n_SHIFT (4U)
/*! tpm4_qaccept_n - TPM4 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm4_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm4_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm4_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm5_qaccept_n_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm5_qaccept_n_SHIFT (5U)
/*! tpm5_qaccept_n - TPM5 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm5_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm5_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm5_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm6_qaccept_n_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm6_qaccept_n_SHIFT (6U)
/*! tpm6_qaccept_n - TPM6 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm6_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm6_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_tpm6_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog3_qaccept_n_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog3_qaccept_n_SHIFT (7U)
/*! wdog3_qaccept_n - WDOG3 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog3_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog3_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog3_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog4_qaccept_n_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog4_qaccept_n_SHIFT (8U)
/*! wdog4_qaccept_n - WDOG4 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog4_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog4_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog4_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog5_qaccept_n_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog5_qaccept_n_SHIFT (9U)
/*! wdog5_qaccept_n - WDOG5 qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog5_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog5_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_1_wdog5_qaccept_n_MASK)
/*! @} */

/*! @name QDENY_STATUS_1 - QDENY status register 1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm3_qdeny_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm3_qdeny_SHIFT (3U)
/*! tpm3_qdeny - TPM3 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm3_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm3_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm3_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm4_qdeny_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm4_qdeny_SHIFT (4U)
/*! tpm4_qdeny - TPM4 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm4_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm4_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm4_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm5_qdeny_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm5_qdeny_SHIFT (5U)
/*! tpm5_qdeny - TPM5 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm5_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm5_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm5_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm6_qdeny_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm6_qdeny_SHIFT (6U)
/*! tpm6_qdeny - TPM6 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm6_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm6_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_tpm6_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog3_qdeny_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog3_qdeny_SHIFT (7U)
/*! wdog3_qdeny - WDOG3 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog3_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog3_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog3_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog4_qdeny_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog4_qdeny_SHIFT (8U)
/*! wdog4_qdeny - WDOG4 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog4_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog4_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog4_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog5_qdeny_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog5_qdeny_SHIFT (9U)
/*! wdog5_qdeny - WDOG5 qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog5_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog5_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_1_wdog5_qdeny_MASK)
/*! @} */

/*! @name QACTIVE_STATUS_1 - QACTIVE status register 1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm3_qactive_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm3_qactive_SHIFT (3U)
/*! tpm3_qactive - TPM3 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm3_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm3_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm3_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm4_qactive_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm4_qactive_SHIFT (4U)
/*! tpm4_qactive - TPM4 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm4_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm4_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm4_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm5_qactive_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm5_qactive_SHIFT (5U)
/*! tpm5_qactive - TPM5 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm5_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm5_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm5_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm6_qactive_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm6_qactive_SHIFT (6U)
/*! tpm6_qactive - TPM6 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm6_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm6_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_tpm6_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog3_qactive_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog3_qactive_SHIFT (7U)
/*! wdog3_qactive - WDOG3 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog3_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog3_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog3_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog4_qactive_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog4_qactive_SHIFT (8U)
/*! wdog4_qactive - WDOG4 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog4_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog4_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog4_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog5_qactive_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog5_qactive_SHIFT (9U)
/*! wdog5_qactive - WDOG5 qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog5_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog5_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_1_wdog5_qactive_MASK)
/*! @} */

/*! @name QREQ_CTL_2 - QREQ control register 2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_flexio1_apb_qreq_n_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_flexio1_apb_qreq_n_SHIFT (6U)
/*! flexio1_apb_qreq_n - FlexIO1 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_flexio1_apb_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_flexio1_apb_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_flexio1_apb_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_flexio2_apb_qreq_n_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_flexio2_apb_qreq_n_SHIFT (7U)
/*! flexio2_apb_qreq_n - FlexIO2 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_flexio2_apb_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_flexio2_apb_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_flexio2_apb_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c3_ips_qreq_n_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c3_ips_qreq_n_SHIFT (9U)
/*! lpi2c3_ips_qreq_n - LPI2C3 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c3_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c3_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c3_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c4_ips_qreq_n_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c4_ips_qreq_n_SHIFT (10U)
/*! lpi2c4_ips_qreq_n - LPI2C4 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c4_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c4_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c4_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c5_ips_qreq_n_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c5_ips_qreq_n_SHIFT (11U)
/*! lpi2c5_ips_qreq_n - LPI2C5 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c5_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c5_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c5_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c6_ips_qreq_n_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c6_ips_qreq_n_SHIFT (12U)
/*! lpi2c6_ips_qreq_n - LPI2C6 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c6_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c6_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c6_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c7_ips_qreq_n_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c7_ips_qreq_n_SHIFT (13U)
/*! lpi2c7_ips_qreq_n - LPI2C7 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c7_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c7_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c7_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c8_ips_qreq_n_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c8_ips_qreq_n_SHIFT (14U)
/*! lpi2c8_ips_qreq_n - LPI2C8 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c8_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c8_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpi2c8_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi3_ips_qreq_n_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi3_ips_qreq_n_SHIFT (16U)
/*! lpspi3_ips_qreq_n - LPSPI3 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi3_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi3_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi3_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi4_ips_qreq_n_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi4_ips_qreq_n_SHIFT (17U)
/*! lpspi4_ips_qreq_n - LPSPI4 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi4_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi4_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi4_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi5_ips_qreq_n_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi5_ips_qreq_n_SHIFT (18U)
/*! lpspi5_ips_qreq_n - LPSPI5 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi5_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi5_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi5_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi6_ips_qreq_n_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi6_ips_qreq_n_SHIFT (19U)
/*! lpspi6_ips_qreq_n - LPSPI6 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi6_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi6_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi6_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi7_ips_qreq_n_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi7_ips_qreq_n_SHIFT (20U)
/*! lpspi7_ips_qreq_n - LPSPI7 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi7_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi7_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi7_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi8_ips_qreq_n_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi8_ips_qreq_n_SHIFT (21U)
/*! lpspi8_ips_qreq_n - LPSPI8 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi8_ips_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi8_ips_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpspi8_ips_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart3_apb_qreq_n_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart3_apb_qreq_n_SHIFT (22U)
/*! lpuart3_apb_qreq_n - LPUART3 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart3_apb_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart3_apb_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart3_apb_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart4_apb_qreq_n_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart4_apb_qreq_n_SHIFT (23U)
/*! lpuart4_apb_qreq_n - LPUART4 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart4_apb_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart4_apb_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart4_apb_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart5_apb_qreq_n_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart5_apb_qreq_n_SHIFT (24U)
/*! lpuart5_apb_qreq_n - LPUART5 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart5_apb_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart5_apb_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart5_apb_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart6_apb_qreq_n_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart6_apb_qreq_n_SHIFT (25U)
/*! lpuart6_apb_qreq_n - LPUART6 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart6_apb_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart6_apb_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart6_apb_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart7_apb_qreq_n_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart7_apb_qreq_n_SHIFT (26U)
/*! lpuart7_apb_qreq_n - LPUART7 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart7_apb_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart7_apb_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart7_apb_qreq_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart8_apb_qreq_n_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart8_apb_qreq_n_SHIFT (27U)
/*! lpuart8_apb_qreq_n - LPUART8 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart8_apb_qreq_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart8_apb_qreq_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_lpuart8_apb_qreq_n_MASK)
/*! @} */

/*! @name QACCEPT_STATUS_2 - QACCEPT status register 2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_flexio1_apb_qaccept_n_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_flexio1_apb_qaccept_n_SHIFT (6U)
/*! flexio1_apb_qaccept_n - FlexIO1 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_flexio1_apb_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_flexio1_apb_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_flexio1_apb_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_flexio2_apb_qaccept_n_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_flexio2_apb_qaccept_n_SHIFT (7U)
/*! flexio2_apb_qaccept_n - FlexIO2 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_flexio2_apb_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_flexio2_apb_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_flexio2_apb_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c3_ips_qaccept_n_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c3_ips_qaccept_n_SHIFT (9U)
/*! lpi2c3_ips_qaccept_n - LPI2C3 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c3_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c3_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c3_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c4_ips_qaccept_n_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c4_ips_qaccept_n_SHIFT (10U)
/*! lpi2c4_ips_qaccept_n - LPI2C4 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c4_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c4_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c4_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c5_ips_qaccept_n_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c5_ips_qaccept_n_SHIFT (11U)
/*! lpi2c5_ips_qaccept_n - LPI2C5 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c5_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c5_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c5_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c6_ips_qaccept_n_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c6_ips_qaccept_n_SHIFT (12U)
/*! lpi2c6_ips_qaccept_n - LPI2C6 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c6_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c6_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c6_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c7_ips_qaccept_n_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c7_ips_qaccept_n_SHIFT (13U)
/*! lpi2c7_ips_qaccept_n - LPI2C7 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c7_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c7_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c7_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c8_ips_qaccept_n_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c8_ips_qaccept_n_SHIFT (14U)
/*! lpi2c8_ips_qaccept_n - LPI2C8 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c8_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c8_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpi2c8_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi3_ips_qaccept_n_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi3_ips_qaccept_n_SHIFT (16U)
/*! lpspi3_ips_qaccept_n - LPSPI3 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi3_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi3_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi3_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi4_ips_qaccept_n_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi4_ips_qaccept_n_SHIFT (17U)
/*! lpspi4_ips_qaccept_n - LPSPI4 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi4_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi4_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi4_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi5_ips_qaccept_n_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi5_ips_qaccept_n_SHIFT (18U)
/*! lpspi5_ips_qaccept_n - LPSPI5 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi5_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi5_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi5_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi6_ips_qaccept_n_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi6_ips_qaccept_n_SHIFT (19U)
/*! lpspi6_ips_qaccept_n - LPSPI6 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi6_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi6_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi6_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi7_ips_qaccept_n_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi7_ips_qaccept_n_SHIFT (20U)
/*! lpspi7_ips_qaccept_n - LPSPI7 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi7_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi7_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi7_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi8_ips_qaccept_n_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi8_ips_qaccept_n_SHIFT (21U)
/*! lpspi8_ips_qaccept_n - LPSPI8 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi8_ips_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi8_ips_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpspi8_ips_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart3_apb_qaccept_n_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart3_apb_qaccept_n_SHIFT (22U)
/*! lpuart3_apb_qaccept_n - LPUART3 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart3_apb_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart3_apb_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart3_apb_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart4_apb_qaccept_n_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart4_apb_qaccept_n_SHIFT (23U)
/*! lpuart4_apb_qaccept_n - LPUART4 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart4_apb_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart4_apb_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart4_apb_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart5_apb_qaccept_n_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart5_apb_qaccept_n_SHIFT (24U)
/*! lpuart5_apb_qaccept_n - LPUART5 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart5_apb_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart5_apb_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart5_apb_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart6_apb_qaccept_n_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart6_apb_qaccept_n_SHIFT (25U)
/*! lpuart6_apb_qaccept_n - LPUART6 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart6_apb_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart6_apb_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart6_apb_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart7_apb_qaccept_n_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart7_apb_qaccept_n_SHIFT (26U)
/*! lpuart7_apb_qaccept_n - LPUART7 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart7_apb_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart7_apb_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart7_apb_qaccept_n_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart8_apb_qaccept_n_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart8_apb_qaccept_n_SHIFT (27U)
/*! lpuart8_apb_qaccept_n - LPUART8 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart8_apb_qaccept_n(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart8_apb_qaccept_n_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_lpuart8_apb_qaccept_n_MASK)
/*! @} */

/*! @name QDENY_STATUS_2 - QDENY status register 2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_flexio1_apb_qdeny_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_flexio1_apb_qdeny_SHIFT (6U)
/*! flexio1_apb_qdeny - FlexIO1 APB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_flexio1_apb_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_flexio1_apb_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_flexio1_apb_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_flexio2_apb_qdeny_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_flexio2_apb_qdeny_SHIFT (7U)
/*! flexio2_apb_qdeny - FlexIO2 APB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_flexio2_apb_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_flexio2_apb_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_flexio2_apb_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c3_ips_qdeny_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c3_ips_qdeny_SHIFT (9U)
/*! lpi2c3_ips_qdeny - LPI2C3 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c3_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c3_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c3_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c4_ips_qdeny_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c4_ips_qdeny_SHIFT (10U)
/*! lpi2c4_ips_qdeny - LPI2C4 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c4_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c4_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c4_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c5_ips_qdeny_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c5_ips_qdeny_SHIFT (11U)
/*! lpi2c5_ips_qdeny - LPI2C5 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c5_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c5_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c5_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c6_ips_qdeny_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c6_ips_qdeny_SHIFT (12U)
/*! lpi2c6_ips_qdeny - LPI2C6 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c6_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c6_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c6_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c7_ips_qdeny_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c7_ips_qdeny_SHIFT (13U)
/*! lpi2c7_ips_qdeny - LPI2C7 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c7_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c7_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c7_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c8_ips_qdeny_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c8_ips_qdeny_SHIFT (14U)
/*! lpi2c8_ips_qdeny - LPI2C8 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c8_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c8_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpi2c8_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi3_ips_qdeny_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi3_ips_qdeny_SHIFT (16U)
/*! lpspi3_ips_qdeny - LPSPI3 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi3_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi3_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi3_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi4_ips_qdeny_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi4_ips_qdeny_SHIFT (17U)
/*! lpspi4_ips_qdeny - LPSPI4 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi4_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi4_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi4_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi5_ips_qdeny_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi5_ips_qdeny_SHIFT (18U)
/*! lpspi5_ips_qdeny - LPSPI5 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi5_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi5_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi5_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi6_ips_qdeny_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi6_ips_qdeny_SHIFT (19U)
/*! lpspi6_ips_qdeny - LPSPI6 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi6_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi6_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi6_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi7_ips_qdeny_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi7_ips_qdeny_SHIFT (20U)
/*! lpspi7_ips_qdeny - LPSPI7 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi7_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi7_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi7_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi8_ips_qdeny_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi8_ips_qdeny_SHIFT (21U)
/*! lpspi8_ips_qdeny - LPSPI8 IPS qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi8_ips_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi8_ips_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpspi8_ips_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart3_apb_qdeny_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart3_apb_qdeny_SHIFT (22U)
/*! lpuart3_apb_qdeny - LPUART3 APB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart3_apb_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart3_apb_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart3_apb_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart4_apb_qdeny_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart4_apb_qdeny_SHIFT (23U)
/*! lpuart4_apb_qdeny - LPUART4 APB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart4_apb_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart4_apb_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart4_apb_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart5_apb_qdeny_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart5_apb_qdeny_SHIFT (24U)
/*! lpuart5_apb_qdeny - LPUART5 APB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart5_apb_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart5_apb_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart5_apb_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart6_apb_qdeny_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart6_apb_qdeny_SHIFT (25U)
/*! lpuart6_apb_qdeny - LPUART6 APB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart6_apb_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart6_apb_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart6_apb_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart7_apb_qdeny_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart7_apb_qdeny_SHIFT (26U)
/*! lpuart7_apb_qdeny - LPUART7 APB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart7_apb_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart7_apb_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart7_apb_qdeny_MASK)

#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart8_apb_qdeny_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart8_apb_qdeny_SHIFT (27U)
/*! lpuart8_apb_qdeny - LPUART8 APB qdeny status */
#define BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart8_apb_qdeny(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart8_apb_qdeny_SHIFT)) & BLK_CTRL_WAKEUPMIX_QDENY_STATUS_2_lpuart8_apb_qdeny_MASK)
/*! @} */

/*! @name QACTIVE_STATUS_2 - QACTIVE status register 2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_flexio1_apb_qactive_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_flexio1_apb_qactive_SHIFT (6U)
/*! flexio1_apb_qactive - FlexIO1 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_flexio1_apb_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_flexio1_apb_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_flexio1_apb_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_flexio2_apb_qactive_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_flexio2_apb_qactive_SHIFT (7U)
/*! flexio2_apb_qactive - FlexIO2 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_flexio2_apb_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_flexio2_apb_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_flexio2_apb_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c3_ips_qactive_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c3_ips_qactive_SHIFT (9U)
/*! lpi2c3_ips_qactive - LPI2C3 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c3_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c3_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c3_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c4_ips_qactive_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c4_ips_qactive_SHIFT (10U)
/*! lpi2c4_ips_qactive - LPI2C4 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c4_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c4_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c4_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c5_ips_qactive_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c5_ips_qactive_SHIFT (11U)
/*! lpi2c5_ips_qactive - LPI2C5 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c5_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c5_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c5_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c6_ips_qactive_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c6_ips_qactive_SHIFT (12U)
/*! lpi2c6_ips_qactive - LPI2C6 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c6_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c6_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c6_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c7_ips_qactive_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c7_ips_qactive_SHIFT (13U)
/*! lpi2c7_ips_qactive - LPI2C7 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c7_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c7_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c7_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c8_ips_qactive_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c8_ips_qactive_SHIFT (14U)
/*! lpi2c8_ips_qactive - LPI2C8 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c8_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c8_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpi2c8_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi3_ips_qactive_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi3_ips_qactive_SHIFT (16U)
/*! lpspi3_ips_qactive - LPSPI3 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi3_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi3_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi3_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi4_ips_qactive_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi4_ips_qactive_SHIFT (17U)
/*! lpspi4_ips_qactive - LPSPI4 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi4_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi4_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi4_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi5_ips_qactive_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi5_ips_qactive_SHIFT (18U)
/*! lpspi5_ips_qactive - LPSPI5 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi5_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi5_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi5_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi6_ips_qactive_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi6_ips_qactive_SHIFT (19U)
/*! lpspi6_ips_qactive - LPSPI6 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi6_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi6_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi6_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi7_ips_qactive_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi7_ips_qactive_SHIFT (20U)
/*! lpspi7_ips_qactive - LPSPI7 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi7_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi7_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi7_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi8_ips_qactive_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi8_ips_qactive_SHIFT (21U)
/*! lpspi8_ips_qactive - LPSPI8 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi8_ips_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi8_ips_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpspi8_ips_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart3_apb_qactive_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart3_apb_qactive_SHIFT (22U)
/*! lpuart3_apb_qactive - LPUART3 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart3_apb_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart3_apb_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart3_apb_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart4_apb_qactive_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart4_apb_qactive_SHIFT (23U)
/*! lpuart4_apb_qactive - LPUART4 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart4_apb_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart4_apb_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart4_apb_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart5_apb_qactive_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart5_apb_qactive_SHIFT (24U)
/*! lpuart5_apb_qactive - LPUART5 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart5_apb_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart5_apb_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart5_apb_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart6_apb_qactive_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart6_apb_qactive_SHIFT (25U)
/*! lpuart6_apb_qactive - LPUART6 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart6_apb_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart6_apb_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart6_apb_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart7_apb_qactive_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart7_apb_qactive_SHIFT (26U)
/*! lpuart7_apb_qactive - LPUART7 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart7_apb_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart7_apb_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart7_apb_qactive_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart8_apb_qactive_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart8_apb_qactive_SHIFT (27U)
/*! lpuart8_apb_qactive - LPUART8 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart8_apb_qactive(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart8_apb_qactive_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_lpuart8_apb_qactive_MASK)
/*! @} */

/*! @name ATU_CONF - ATU configuration control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_pm_en_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_pm_en_SHIFT (0U)
/*! atu_a_pm_en - ATU A PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_error_on_miss_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_error_on_miss_SHIFT (1U)
/*! atu_a_error_on_miss - ATU A Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_a_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_pm_en_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_pm_en_SHIFT (4U)
/*! atu_usdhc_1_pm_en - ATU USDHC 1 PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_error_on_miss_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_error_on_miss_SHIFT (5U)
/*! atu_usdhc_1_error_on_miss - ATU USDHC 1 Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_1_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_pm_en_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_pm_en_SHIFT (8U)
/*! atu_usdhc_2_pm_en - ATU USDHC 2 PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_error_on_miss_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_error_on_miss_SHIFT (9U)
/*! atu_usdhc_2_error_on_miss - ATU USDHC 2 Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_2_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_pm_en_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_pm_en_SHIFT (12U)
/*! atu_usdhc_3_pm_en - ATU USDHC 3 PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_error_on_miss_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_error_on_miss_SHIFT (13U)
/*! atu_usdhc_3_error_on_miss - ATU USDHC 3 Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_usdhc_3_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_pm_en_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_pm_en_SHIFT (16U)
/*! atu_ahbap_pm_en - ATU AHBAP PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_error_on_miss_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_error_on_miss_SHIFT (17U)
/*! atu_ahbap_error_on_miss - ATU AHBAP Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_ahbap_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_pm_en_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_pm_en_SHIFT (20U)
/*! atu_v2x_pm_en - ATU V2X PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_error_on_miss_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_error_on_miss_SHIFT (21U)
/*! atu_v2x_error_on_miss - ATU V2X Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_v2x_error_on_miss_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_pm_en_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_pm_en_SHIFT (24U)
/*! atu_xspi_pm_en - ATU XSPI PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_pm_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_pm_en_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_pm_en_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_error_on_miss_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_error_on_miss_SHIFT (25U)
/*! atu_xspi_error_on_miss - ATU XSPI Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_error_on_miss(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_error_on_miss_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_atu_xspi_error_on_miss_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_3 - ipc_clk clock gating override controls force_on_off + force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt2_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt2_SHIFT (22U)
/*! ipc_bus_nogate_clk_gpt2 - clock gating override enable of ipc_bus_nogate_clk_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt2_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt2_SHIFT (23U)
/*! sel_ipc_bus_nogate_clk_gpt2 - clock gating override select of ipc_bus_nogate_clk_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt3_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt3_SHIFT (24U)
/*! ipc_bus_nogate_clk_gpt3 - clock gating override enable of ipc_bus_nogate_clk_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt3_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt3_SHIFT (25U)
/*! sel_ipc_bus_nogate_clk_gpt3 - clock gating override select of ipc_bus_nogate_clk_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt4_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt4_SHIFT (26U)
/*! ipc_bus_nogate_clk_gpt4 - clock gating override enable of ipc_bus_nogate_clk_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt4_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt4_SHIFT (27U)
/*! sel_ipc_bus_nogate_clk_gpt4 - clock gating override select of ipc_bus_nogate_clk_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt5_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt5_SHIFT (28U)
/*! ipc_bus_nogate_clk_gpt5 - clock gating override enable of ipc_bus_nogate_clk_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_ipc_bus_nogate_clk_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt5_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt5_SHIFT (29U)
/*! sel_ipc_bus_nogate_clk_gpt5 - clock gating override select of ipc_bus_nogate_clk_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_3_sel_ipc_bus_nogate_clk_gpt5_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_5 - ipc_clk clock gating override controls force_on_off + force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai5_SHIFT (16U)
/*! ipc_bus_nogate_clk_sai5 - clock gating override enable of ipc_bus_nogate_clk_sai5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai5_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai5_SHIFT (17U)
/*! sel_ipc_bus_nogate_clk_sai5 - clock gating override select of ipc_bus_nogate_clk_sai5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai3_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai3_SHIFT (18U)
/*! ipc_bus_nogate_clk_sai3 - clock gating override enable of ipc_bus_nogate_clk_sai3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai3_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai3_SHIFT (19U)
/*! sel_ipc_bus_nogate_clk_sai3 - clock gating override select of ipc_bus_nogate_clk_sai3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai4_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai4_SHIFT (20U)
/*! ipc_bus_nogate_clk_sai4 - clock gating override enable of ipc_bus_nogate_clk_sai4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_ipc_bus_nogate_clk_sai4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai4_SHIFT (21U)
/*! sel_ipc_bus_nogate_clk_sai4 - clock gating override select of ipc_bus_nogate_clk_sai4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_5_sel_ipc_bus_nogate_clk_sai4_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_7 - ipc_clk clock gating override controls force_on_off + force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt5_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt5_SHIFT (14U)
/*! ipc_clkroot_24m_wakeupmix_gpt5 - clock gating override enable of ipc_ipc_clkroot_24m_wakeupmix_gpt5. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt5_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt5_SHIFT (15U)
/*! sel_ipc_clkroot_24m_wakeupmix_gpt5 - clock gating override select of ipc_ipc_clkroot_24m_wakeupmix_gpt5. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_ipc_clkroot_24m_wakeupmix_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_ipc_clkroot_24m_wakeupmix_SHIFT (16U)
/*! ipc_ipc_clkroot_24m_wakeupmix - clock gating override enable of ipc_ipc_clkroot_24m_wakeupmix. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_ipc_clkroot_24m_wakeupmix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_ipc_clkroot_24m_wakeupmix_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_ipc_clkroot_24m_wakeupmix_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_ipc_clkroot_24m_wakeupmix_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_ipc_clkroot_24m_wakeupmix_SHIFT (17U)
/*! sel_ipc_ipc_clkroot_24m_wakeupmix - clock gating override select of ipc_ipc_clkroot_24m_wakeupmix. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_ipc_clkroot_24m_wakeupmix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_ipc_clkroot_24m_wakeupmix_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_ipc_clkroot_24m_wakeupmix_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt2_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt2_SHIFT (18U)
/*! ipc_clkroot_24m_wakeupmix_gpt2 - clock gating override enable of ipc_ipc_clkroot_24m_wakeupmix_gpt2. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt2_SHIFT (19U)
/*! sel_ipc_clkroot_24m_wakeupmix_gpt2 - clock gating override select of ipc_ipc_clkroot_24m_wakeupmix_gpt2. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt3_SHIFT (20U)
/*! ipc_clkroot_24m_wakeupmix_gpt3 - clock gating override enable of ipc_ipc_clkroot_24m_wakeupmix_gpt3. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt3_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt3_SHIFT (21U)
/*! sel_ipc_clkroot_24m_wakeupmix_gpt3 - clock gating override select of ipc_ipc_clkroot_24m_wakeupmix_gpt3. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt4_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt4_SHIFT (22U)
/*! ipc_clkroot_24m_wakeupmix_gpt4 - clock gating override enable of ipc_ipc_clkroot_24m_wakeupmix_gpt4. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_ipc_clkroot_24m_wakeupmix_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt4_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt4_SHIFT (23U)
/*! sel_ipc_clkroot_24m_wakeupmix_gpt4 - clock gating override select of ipc_ipc_clkroot_24m_wakeupmix_gpt4. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_7_sel_ipc_clkroot_24m_wakeupmix_gpt4_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_8 - ipc_clk clock gating override controls force_on_off + force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt2_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt2_SHIFT (16U)
/*! ipc_ipc_clkroot_gpt2 - clock gating override enable of ipc_ipc_clkroot_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt2_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt2_SHIFT (17U)
/*! sel_ipc_ipc_clkroot_gpt2 - clock gating override select of ipc_ipc_clkroot_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt3_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt3_SHIFT (18U)
/*! ipc_ipc_clkroot_gpt3 - clock gating override enable of ipc_ipc_clkroot_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt3_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt3_SHIFT (19U)
/*! sel_ipc_ipc_clkroot_gpt3 - clock gating override select of ipc_ipc_clkroot_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt4_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt4_SHIFT (20U)
/*! ipc_ipc_clkroot_gpt4 - clock gating override enable of ipc_ipc_clkroot_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt4_SHIFT (21U)
/*! sel_ipc_ipc_clkroot_gpt4 - clock gating override select of ipc_ipc_clkroot_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt5_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt5_SHIFT (22U)
/*! ipc_ipc_clkroot_gpt5 - clock gating override enable of ipc_ipc_clkroot_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_ipc_ipc_clkroot_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt5_SHIFT (23U)
/*! sel_ipc_ipc_clkroot_gpt5 - clock gating override select of ipc_ipc_clkroot_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_8_sel_ipc_ipc_clkroot_gpt5_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_11 - ipc_clk clock gating override controls force_on_off + force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_1_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_1_SHIFT (18U)
/*! ipc_sai5_mclk_1 - clock gating override enable of ipc_sai5_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_1_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_1_SHIFT (19U)
/*! sel_ipc_sai5_mclk_1 - clock gating override select of ipc_sai5_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_2_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_2_SHIFT (20U)
/*! ipc_sai5_mclk_2 - clock gating override enable of ipc_sai5_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_2_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_2_SHIFT (21U)
/*! sel_ipc_sai5_mclk_2 - clock gating override select of ipc_sai5_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_3_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_3_SHIFT (22U)
/*! ipc_sai5_mclk_3 - clock gating override enable of ipc_sai5_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai5_mclk_3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_3_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_3_SHIFT (23U)
/*! sel_ipc_sai5_mclk_3 - clock gating override select of ipc_sai5_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai5_mclk_3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_1_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_1_SHIFT (24U)
/*! ipc_sai3_mclk_1 - clock gating override enable of ipc_sai3_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_1_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_1_SHIFT (25U)
/*! sel_ipc_sai3_mclk_1 - clock gating override select of ipc_sai3_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_2_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_2_SHIFT (26U)
/*! ipc_sai3_mclk_2 - clock gating override enable of ipc_sai3_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_2_SHIFT (27U)
/*! sel_ipc_sai3_mclk_2 - clock gating override select of ipc_sai3_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_3_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_3_SHIFT (28U)
/*! ipc_sai3_mclk_3 - clock gating override enable of ipc_sai3_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai3_mclk_3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_3_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_3_SHIFT (29U)
/*! sel_ipc_sai3_mclk_3 - clock gating override select of ipc_sai3_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai3_mclk_3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai4_mclk_1_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai4_mclk_1_SHIFT (30U)
/*! ipc_sai4_mclk_1 - clock gating override enable of ipc_sai4_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai4_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai4_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_ipc_sai4_mclk_1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai4_mclk_1_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai4_mclk_1_SHIFT (31U)
/*! sel_ipc_sai4_mclk_1 - clock gating override select of ipc_sai4_mclk_1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai4_mclk_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai4_mclk_1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_11_sel_ipc_sai4_mclk_1_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_12 - ipc_clk clock gating override controls force_on_off + force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_2_SHIFT (0U)
/*! ipc_sai4_mclk_2 - clock gating override enable of ipc_sai4_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_2_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_2_SHIFT (1U)
/*! sel_ipc_sai4_mclk_2 - clock gating override select of ipc_sai4_mclk_2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_3_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_3_SHIFT (2U)
/*! ipc_sai4_mclk_3 - clock gating override enable of ipc_sai4_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_ipc_sai4_mclk_3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_3_SHIFT (3U)
/*! sel_ipc_sai4_mclk_3 - clock gating override select of ipc_sai4_mclk_3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_12_sel_ipc_sai4_mclk_3_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_15 - ipc_clk clock gating override controls force_on_off + force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt5_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt5_SHIFT (6U)
/*! clkroot_32k_wakeupmix_gpt5 - clock gating override enable of ipc_ipc_clkroot_32k_wakeupmix_gpt5. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt5_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt5_SHIFT (7U)
/*! sel_clkroot_32k_wakeupmix_gpt5 - clock gating override select of ipc_ipc_clkroot_32k_wakeupmix_gpt5. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_ipc_bus_nogate_clk_xspi_slv_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_ipc_bus_nogate_clk_xspi_slv_SHIFT (8U)
/*! ipc_bus_nogate_clk_xspi_slv - clock gating override enable of ipc_bus_nogate_clk_xspi_slv */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_ipc_bus_nogate_clk_xspi_slv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_ipc_bus_nogate_clk_xspi_slv_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_ipc_bus_nogate_clk_xspi_slv_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_ipc_bus_nogate_clk_xspi_slv_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_ipc_bus_nogate_clk_xspi_slv_SHIFT (9U)
/*! sel_ipc_bus_nogate_clk_xspi_slv - clock gating override select of ipc_bus_nogate_clk_xspi_slv */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_ipc_bus_nogate_clk_xspi_slv(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_ipc_bus_nogate_clk_xspi_slv_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_ipc_bus_nogate_clk_xspi_slv_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_24m_wakeupmix_safety_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_24m_wakeupmix_safety_SHIFT (10U)
/*! clkroot_24m_wakeupmix_safety - clock gating override enable of ipc_ipc_clkroot_24m_wakeupmix_safety. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_24m_wakeupmix_safety(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_24m_wakeupmix_safety_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_24m_wakeupmix_safety_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_24m_wakeupmix_safety_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_24m_wakeupmix_safety_SHIFT (11U)
/*! sel_clkroot_24m_wakeupmix_safety - clock gating override select of ipc_ipc_clkroot_24m_wakeupmix_safety. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_24m_wakeupmix_safety(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_24m_wakeupmix_safety_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_24m_wakeupmix_safety_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt2_SHIFT (12U)
/*! clkroot_32k_wakeupmix_gpt2 - clock gating override enable of ipc_ipc_clkroot_32k_wakeupmix_gpt2. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt2_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt2_SHIFT (13U)
/*! sel_clkroot_32k_wakeupmix_gpt2 - clock gating override select of ipc_ipc_clkroot_32k_wakeupmix_gpt2. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt3_SHIFT (14U)
/*! clkroot_32k_wakeupmix_gpt3 - clock gating override enable of ipc_ipc_clkroot_32k_wakeupmix_gpt3. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt3_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt3_SHIFT (15U)
/*! sel_clkroot_32k_wakeupmix_gpt3 - clock gating override select of ipc_ipc_clkroot_32k_wakeupmix_gpt3. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt4_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt4_SHIFT (16U)
/*! clkroot_32k_wakeupmix_gpt4 - clock gating override enable of ipc_ipc_clkroot_32k_wakeupmix_gpt4. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_clkroot_32k_wakeupmix_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt4_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt4_SHIFT (17U)
/*! sel_clkroot_32k_wakeupmix_gpt4 - clock gating override select of ipc_ipc_clkroot_32k_wakeupmix_gpt4. FUNCTION DISABLED */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_15_sel_clkroot_32k_wakeupmix_gpt4_MASK)
/*! @} */

/*! @name FORCE_ON_OFF_16 - ipc_clk clock gating override controls force_on_off + force_on_off_sel */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt2_SHIFT (10U)
/*! ipc_ipp_clk_gpt2 - clock gating override enable of ipc_ipp_clk_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt2_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt2_SHIFT (11U)
/*! sel_ipc_ipp_clk_gpt2 - clock gating override select of ipc_ipp_clk_gpt2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt3_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt3_SHIFT (12U)
/*! ipc_ipp_clk_gpt3 - clock gating override enable of ipc_ipp_clk_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt3_SHIFT (13U)
/*! sel_ipc_ipp_clk_gpt3 - clock gating override select of ipc_ipp_clk_gpt3 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt4_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt4_SHIFT (14U)
/*! ipc_ipp_clk_gpt4 - clock gating override enable of ipc_ipp_clk_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt4_SHIFT (15U)
/*! sel_ipc_ipp_clk_gpt4 - clock gating override select of ipc_ipp_clk_gpt4 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt5_SHIFT (16U)
/*! ipc_ipp_clk_gpt5 - clock gating override enable of ipc_ipp_clk_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_ipp_clk_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt5_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt5_SHIFT (17U)
/*! sel_ipc_ipp_clk_gpt5 - clock gating override select of ipc_ipp_clk_gpt5 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_ipp_clk_gpt5_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_audmix_ipg_clk_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_audmix_ipg_clk_SHIFT (18U)
/*! ipc_audmix_ipg_clk - clock gating override enable of ipc_audmix_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_audmix_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_audmix_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_audmix_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_audmix_ipg_clk_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_audmix_ipg_clk_SHIFT (19U)
/*! sel_ipc_audmix_ipg_clk - clock gating override select of ipc_audmix_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_audmix_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_audmix_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_audmix_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc1_aud_pll1_ipg_clk_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc1_aud_pll1_ipg_clk_SHIFT (20U)
/*! ipc_asrc1_aud_pll1_ipg_clk - clock gating override enable of ipc_asrc1_aud_pll1_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc1_aud_pll1_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc1_aud_pll1_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc1_aud_pll1_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc1_aud_pll1_ipg_clk_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc1_aud_pll1_ipg_clk_SHIFT (21U)
/*! sel_ipc_asrc1_aud_pll1_ipg_clk - clock gating override select of ipc_asrc1_aud_pll1_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc1_aud_pll1_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc1_aud_pll1_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc1_aud_pll1_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc1_aud_pll2_ipg_clk_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc1_aud_pll2_ipg_clk_SHIFT (22U)
/*! ipc_asrc1_aud_pll2_ipg_clk - clock gating override enable of ipc_asrc1_aud_pll2_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc1_aud_pll2_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc1_aud_pll2_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc1_aud_pll2_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc1_aud_pll2_ipg_clk_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc1_aud_pll2_ipg_clk_SHIFT (23U)
/*! sel_ipc_asrc1_aud_pll2_ipg_clk - clock gating override select of ipc_asrc1_aud_pll2_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc1_aud_pll2_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc1_aud_pll2_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc1_aud_pll2_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc2_aud_pll1_ipg_clk_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc2_aud_pll1_ipg_clk_SHIFT (24U)
/*! ipc_asrc2_aud_pll1_ipg_clk - clock gating override enable of ipc_asrc2_aud_pll1_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc2_aud_pll1_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc2_aud_pll1_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc2_aud_pll1_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc2_aud_pll1_ipg_clk_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc2_aud_pll1_ipg_clk_SHIFT (25U)
/*! sel_ipc_asrc2_aud_pll1_ipg_clk - clock gating override select of ipc_asrc2_aud_pll1_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc2_aud_pll1_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc2_aud_pll1_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc2_aud_pll1_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc2_aud_pll2_ipg_clk_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc2_aud_pll2_ipg_clk_SHIFT (26U)
/*! ipc_asrc2_aud_pll2_ipg_clk - clock gating override enable of ipc_asrc2_aud_pll2_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc2_aud_pll2_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc2_aud_pll2_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_asrc2_aud_pll2_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc2_aud_pll2_ipg_clk_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc2_aud_pll2_ipg_clk_SHIFT (27U)
/*! sel_ipc_asrc2_aud_pll2_ipg_clk - clock gating override select of ipc_asrc2_aud_pll2_ipg_clk */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc2_aud_pll2_ipg_clk(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc2_aud_pll2_ipg_clk_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_asrc2_aud_pll2_ipg_clk_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_bus_nogate_clk_asrc1_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_bus_nogate_clk_asrc1_SHIFT (28U)
/*! ipc_bus_nogate_clk_asrc1 - clock gating override enable of ipc_bus_nogate_clk_asrc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_bus_nogate_clk_asrc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_bus_nogate_clk_asrc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_bus_nogate_clk_asrc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_bus_nogate_clk_asrc1_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_bus_nogate_clk_asrc1_SHIFT (29U)
/*! sel_ipc_bus_nogate_clk_asrc1 - clock gating override select of ipc_bus_nogate_clk_asrc1 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_bus_nogate_clk_asrc1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_bus_nogate_clk_asrc1_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_bus_nogate_clk_asrc1_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_bus_nogate_clk_asrc2_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_bus_nogate_clk_asrc2_SHIFT (30U)
/*! ipc_bus_nogate_clk_asrc2 - clock gating override enable of ipc_bus_nogate_clk_asrc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_bus_nogate_clk_asrc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_bus_nogate_clk_asrc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_ipc_bus_nogate_clk_asrc2_MASK)

#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_bus_nogate_clk_asrc2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_bus_nogate_clk_asrc2_SHIFT (31U)
/*! sel_ipc_bus_nogate_clk_asrc2 - clock gating override select of ipc_bus_nogate_clk_asrc2 */
#define BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_bus_nogate_clk_asrc2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_bus_nogate_clk_asrc2_SHIFT)) & BLK_CTRL_WAKEUPMIX_FORCE_ON_OFF_16_sel_ipc_bus_nogate_clk_asrc2_MASK)
/*! @} */

/*! @name GPT_IPP_IND_CAPIN1_MUX_CTRL - GPT IPP_IND_CAPIN1 MUX CTRL */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt2_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt2_SHIFT (0U)
/*! gpt2 - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt3_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt3_SHIFT (4U)
/*! gpt3 - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt4_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt4_SHIFT (8U)
/*! gpt4 - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt5_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt5_SHIFT (12U)
/*! gpt5 - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN1_MUX_CTRL_gpt5_MASK)
/*! @} */

/*! @name GPT_IPP_IND_CAPIN2_MUX_CTRL - GPT IPP_IND_CAPIN2 MUX CTRL */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt2_MASK (0x3U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt2_SHIFT (0U)
/*! gpt2 - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt2_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt2_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt3_MASK (0xCU)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt3_SHIFT (2U)
/*! gpt3 - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt3_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt3_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt4_MASK (0x30U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt4_SHIFT (4U)
/*! gpt4 - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt4_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt4_MASK)

#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt5_MASK (0xC0U)
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt5_SHIFT (6U)
/*! gpt5 - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt5_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT_IPP_IND_CAPIN2_MUX_CTRL_gpt5_MASK)
/*! @} */

/*! @name GPT2_IPP_IND_CLKIN_CLK - GPT2 IPP IND CLKIN CLK */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT2_IPP_IND_CLKIN_CLK_mux_ctrl_MASK (0x1FU)
#define BLK_CTRL_WAKEUPMIX_GPT2_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT (0U)
/*! mux_ctrl - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT2_IPP_IND_CLKIN_CLK_mux_ctrl(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT2_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT2_IPP_IND_CLKIN_CLK_mux_ctrl_MASK)
/*! @} */

/*! @name GPT3_IPP_IND_CLKIN_CLK - GPT3 IPP IND CLKIN CLK */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT3_IPP_IND_CLKIN_CLK_mux_ctrl_MASK (0x1FU)
#define BLK_CTRL_WAKEUPMIX_GPT3_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT (0U)
/*! mux_ctrl - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT3_IPP_IND_CLKIN_CLK_mux_ctrl(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT3_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT3_IPP_IND_CLKIN_CLK_mux_ctrl_MASK)
/*! @} */

/*! @name GPT4_IPP_IND_CLKIN_CLK - GPT4 IPP IND CLKIN CLK */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT4_IPP_IND_CLKIN_CLK_mux_ctrl_MASK (0x1FU)
#define BLK_CTRL_WAKEUPMIX_GPT4_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT (0U)
/*! mux_ctrl - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT4_IPP_IND_CLKIN_CLK_mux_ctrl(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT4_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT4_IPP_IND_CLKIN_CLK_mux_ctrl_MASK)
/*! @} */

/*! @name GPT5_IPP_IND_CLKIN_CLK - GPT5 IPP IND CLKIN CLK */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT5_IPP_IND_CLKIN_CLK_mux_ctrl_MASK (0x1FU)
#define BLK_CTRL_WAKEUPMIX_GPT5_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT (0U)
/*! mux_ctrl - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT5_IPP_IND_CLKIN_CLK_mux_ctrl(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT5_IPP_IND_CLKIN_CLK_mux_ctrl_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT5_IPP_IND_CLKIN_CLK_mux_ctrl_MASK)
/*! @} */

/*! @name GPT2_3_4_5 - GPT PIN MUX */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPT2_3_4_5_pinmux_sel_MASK (0xFFFU)
#define BLK_CTRL_WAKEUPMIX_GPT2_3_4_5_pinmux_sel_SHIFT (0U)
/*! pinmux_sel - defines the output of the mux */
#define BLK_CTRL_WAKEUPMIX_GPT2_3_4_5_pinmux_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPT2_3_4_5_pinmux_sel_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPT2_3_4_5_pinmux_sel_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_WAKEUPMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_WAKEUPMIX_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* BLK_CTRL_WAKEUPMIX_H_ */

