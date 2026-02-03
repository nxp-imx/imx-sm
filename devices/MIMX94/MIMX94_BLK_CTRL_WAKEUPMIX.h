/*
** ###################################################################
**     Processor:           _CM33
**     Compiler:            Keil ARM C/C++ Compiler
**     Build:               b231211
**
**     Abstract:
**         CMSIS Peripheral Access Layer for mx94_CM33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2024 NXP
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
 * @file mx94_BLK_CTRL_WAKEUPMIX.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for mx94_BLK_CTRL_WAKEUPMIX
 *
 * CMSIS Peripheral Access Layer for mx94
 */

/* Prevention from multiple including the same memory map */
#if !defined(mx94_BLK_CTRL_WAKEUPMIX_H_)  /* Check if memory map has not been already included */
#define mx94_BLK_CTRL_WAKEUPMIX_H_

#include "MIMX94_COMMON.h"

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_WAKEUPMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_WAKEUPMIX_Peripheral_Access_Layer BLK_CTRL_WAKEUPMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_WAKEUPMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t I3C2_SDA_IRQ;                      /**< I3C SDA IRQ CONTROL BIT, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t MQS2_SETTINGS;                     /**< Setting for MQS#2, offset: 0x10 */
       uint8_t RESERVED_1[8];
  __IO uint32_t SAI_CLK_SEL;                       /**< sai2-4 mclk1-3 clk root mux settings, offset: 0x1C */
  __I  uint32_t VOLT_DETECT;                       /**< Voltage detectors output, offset: 0x20 */
  __IO uint32_t I3C2_WAKEUP;                       /**< I3C2 WAKEUPX CLR, offset: 0x24 */
  __IO uint32_t AXI_ATTR_CFG;                      /**< AXI CACHE CONTROL BIT, offset: 0x28 */
  __IO uint32_t IPG_DEBUG_CM33;                    /**< IPG DEBUG mask bit, offset: 0x2C */
  __IO uint32_t IPG_DEBUG_CA55C0;                  /**< IPG DEBUG mask bit for CA55 core0, offset: 0x30 */
  __IO uint32_t IPG_DEBUG_CA55C1;                  /**< IPG DEBUG mask bit for CA55 core1, offset: 0x34 */
  __IO uint32_t IPG_DEBUG_CA55C2;                  /**< IPG DEBUG mask bit for CA55 core2, offset: 0x38 */
  __IO uint32_t IPG_DEBUG_CA55C3;                  /**< IPG DEBUG mask bit for CA55 core3, offset: 0x3C */
  __IO uint32_t IPG_DEBUG_CM7_0;                   /**< IPG DEBUG mask bit, offset: 0x40 */
  __IO uint32_t IPG_DEBUG_CM7_1;                   /**< IPG DEBUG mask bit, offset: 0x44 */
  __IO uint32_t IPG_DEBUG_CM33SYNC;                /**< IPG DEBUG mask bit, offset: 0x48 */
  __IO uint32_t IPG_DEBUG_2_CM33;                  /**< IPG DEBUG mask bit, offset: 0x4C */
  __IO uint32_t IPG_DEBUG_2_CA55C0;                /**< IPG DEBUG mask bit for CA55 core0, offset: 0x50 */
  __IO uint32_t IPG_DEBUG_2_CA55C1;                /**< IPG DEBUG mask bit for CA55 core1, offset: 0x54 */
  __IO uint32_t IPG_DEBUG_2_CA55C2;                /**< IPG DEBUG mask bit for CA55 core2, offset: 0x58 */
  __IO uint32_t IPG_DEBUG_2_CA55C3;                /**< IPG DEBUG mask bit for CA55 core3, offset: 0x5C */
  __IO uint32_t IPG_DEBUG_2_CM7_0;                 /**< IPG DEBUG mask bit, offset: 0x60 */
  __IO uint32_t IPG_DEBUG_2_CM7_1;                 /**< IPG DEBUG mask bit, offset: 0x64 */
  __IO uint32_t IPG_DEBUG_2_CM33SYNC;              /**< IPG DEBUG mask bit, offset: 0x68 */
       uint8_t RESERVED_2[4];
  __IO uint32_t DBG_TRACE_CTL;                     /**< DEBUG TRACE control, offset: 0x70 */
       uint8_t RESERVED_3[16];
  __IO uint32_t SMMU_TBU_IRQ_SETUP;                /**< SMMU TBU IRQ resynchronization setup, offset: 0x84 */
       uint8_t RESERVED_4[4];
  __IO uint32_t INITIATOR_TIMEOUT;                 /**< NOC initiator timeout status, offset: 0x8C */
  __IO uint32_t NIU_TO_MA0;                        /**< Timeout Control for NOC main NIU master m_a_0, offset: 0x90 */
  __IO uint32_t NIU_TO_MA1;                        /**< Timeout Control for NOC main NIU master m_a_1, offset: 0x94 */
  __IO uint32_t NIU_TO_MA2;                        /**< Timeout Control for NOC main NIU master m_a_2, offset: 0x98 */
  __IO uint32_t NIU_TO_MA3;                        /**< Timeout Control for NOC main NIU master m_a_3, offset: 0x9C */
  __IO uint32_t NIU_TO_MA4;                        /**< Timeout Control for NOC main NIU master m_a_4, offset: 0xA0 */
  __IO uint32_t NIU_TO_MA5;                        /**< Timeout Control for NOC main NIU master m_a_5, offset: 0xA4 */
  __IO uint32_t NIU_TO_MA6;                        /**< Timeout Control for NOC main NIU master m_a_6, offset: 0xA8 */
  __IO uint32_t NIU_TO_MA7;                        /**< Timeout Control for NOC main NIU master m_a_7, offset: 0xAC */
  __IO uint32_t NIU_TO_MA8;                        /**< Timeout Control for NOC main NIU master m_a_8, offset: 0xB0 */
  __IO uint32_t NIU_TO_MD0;                        /**< Timeout Control for NOC mega NIU master m_d_0, offset: 0xB4 */
  __IO uint32_t NIU_TO_MD1;                        /**< Timeout Control for NOC mega NIU master m_d_1, offset: 0xB8 */
  __IO uint32_t NIU_TO_MD2;                        /**< Timeout Control for NOC mega NIU master m_d_2, offset: 0xBC */
  __IO uint32_t NIU_TO_MD3;                        /**< Timeout Control for NOC mega NIU master m_d_3, offset: 0xC0 */
  __IO uint32_t NIU_TO_MD4;                        /**< Timeout Control for NOC mega NIU master m_d_4, offset: 0xC4 */
  __IO uint32_t NIU_TO_MD6;                        /**< Timeout Control for NOC mega NIU master m_d_6, offset: 0xC8 */
  __IO uint32_t NIU_TO_MD7;                        /**< Timeout Control for NOC mega NIU master m_d_7, offset: 0xCC */
  __IO uint32_t IPG_STOP_CTL_0;                    /**< IPG_STOP control register #0, offset: 0xD0 */
  __I  uint32_t IPG_STOP_ACK_STATUS_0;             /**< IPG_STOP_ACK status #0, offset: 0xD4 */
       uint8_t RESERVED_5[4];
       uint32_t IPG_WAIT_CTL_0;                    /**< IPG_WAIT control #0, offset: 0xDC */
  __IO uint32_t IPG_STOP_CTL_1;                    /**< IPG_STOP control register #1, offset: 0xE0 */
       uint32_t IPG_STOP_ACK_STATUS_1;             /**< IPG_STOP_ACK status #1, offset: 0xE4 */
       uint8_t RESERVED_6[4];
  __IO uint32_t IPG_WAIT_CTL_1;                    /**< IPG_WAIT control #1, offset: 0xEC */
       uint8_t RESERVED_7[16];
  __IO uint32_t QREQ_CTL_0;                        /**< QREQ control register #0, offset: 0x100 */
  __I  uint32_t QACCEPT_STATUS_0;                  /**< QACCEPT status register #0, offset: 0x104 */
       uint8_t RESERVED_8[4];
  __I  uint32_t QACTIVE_STATUS_0;                  /**< QACTIVE status register #0, offset: 0x10C */
       uint8_t RESERVED_9[16];
  __IO uint32_t QREQ_CTL_2;                        /**< QREQ control register #2, offset: 0x120 */
  __I  uint32_t QACCEPT_STATUS_2;                  /**< QACCEPT status register #2, offset: 0x124 */
       uint8_t RESERVED_10[4];
  __I  uint32_t QACTIVE_STATUS_2;                  /**< QACTIVE status register #2, offset: 0x12C */
  __IO uint32_t QREQ_CTL_3;                        /**< QREQ control register #3, offset: 0x130 */
  __I  uint32_t QACCEPT_STATUS_3;                  /**< QACCEPT status register #1, offset: 0x134 */
       uint8_t RESERVED_11[4];
  __I  uint32_t QACTIVE_STATUS_3;                  /**< QACTIVE status register #3, offset: 0x13C */
       uint8_t RESERVED_12[192];
  __IO uint32_t ATU_CONF;                          /**< IPG_WAIT control #1, offset: 0x200 */
       uint8_t RESERVED_13[12];
  __IO uint32_t HIPERFACE1_SYNC_CTL1;              /**< Hiperface #1 sync source configuration register #1/2, offset: 0x210 */
  __IO uint32_t HIPERFACE1_SYNC_CTL2;              /**< Hiperface #1 sync source configuration register #2/2, offset: 0x214 */
  __IO uint32_t HIPERFACE2_SYNC_CTL1;              /**< Hiperface #2 sync source configuration register #1/2, offset: 0x218 */
  __IO uint32_t HIPERFACE2_SYNC_CTL2;              /**< Hiperface #2 interrupt control register #2/2, offset: 0x21C */
  __IO uint32_t HIPERFACE1_INT_CTL;                /**< Hiperface #1 interrupt control, offset: 0x220 */
  __IO uint32_t HIPERFACE2_INT_CTL;                /**< Hiperface #2 interrupt control, offset: 0x224 */
       uint8_t RESERVED_14[4];
  __I  uint32_t ENDAT3_STATUS;                     /**< EnDat 3.0 status register, offset: 0x22C */
  __IO uint32_t FLEXIO1_3_MUX0_SEL;                /**< FlexIO #1/#3 IO mux #0 selection, offset: 0x230 */
  __IO uint32_t FLEXIO1_3_MUX1_SEL;                /**< FlexIO #1/#3 IO mux #1 selection, offset: 0x234 */
  __IO uint32_t FLEXIO1_3_MUX2_SEL;                /**< FlexIO #1/#3 IO mux #2 selection, offset: 0x238 */
  __IO uint32_t FLEXIO2_4_MUX0_SEL;                /**< FlexIO #2/#4 IO mux #0 selection, offset: 0x23C */
  __IO uint32_t FLEXIO2_4_MUX1_SEL;                /**< FlexIO #2/#4 IO mux #1 selection, offset: 0x240 */
  __IO uint32_t DIAG_ENCODER_MUX_SEL;              /**< Encoder diagnostic bus mux selection, offset: 0x244 */
  __IO uint32_t ENCODER_MUX_SEL;                   /**< Encoder bus mux selection, offset: 0x248 */
       uint8_t RESERVED_15[4];
  __IO uint32_t XBAR_AOI_WE;                       /**< XBAR and AOI write protect register, offset: 0x250 */
  __IO uint32_t XBAR_TRIG_SYNC_CTRL1;              /**< XBAR trigger synchronizer control register1, offset: 0x254 */
  __IO uint32_t XBAR_TRIG_SYNC_CTRL2;              /**< XBAR trigger synchronizer control register2, offset: 0x258 */
  __IO uint32_t XBAR_TRIG_SYNC_CTRL3;              /**< XBAR trigger synchronizer control register2, offset: 0x25C */
  __IO uint32_t XBAR_TRIG_SYNC_CTRL4;              /**< XBAR trigger synchronizer control register2, offset: 0x260 */
  __IO uint32_t QTIMER_CTRL1;                      /**< Qtimer miscellaneous control register 1, offset: 0x264 */
  __IO uint32_t QTIMER_CTRL2;                      /**< Qtimer miscellaneous control register 2, offset: 0x268 */
       uint8_t RESERVED_16[4];
  __IO uint32_t XBAR_DIR_CTRL1;                    /**< XBAR IO direction control register #1, offset: 0x270 */
  __IO uint32_t XBAR_DIR_CTRL2;                    /**< XBAR IO direction control register #2, offset: 0x274 */
  __IO uint32_t LPIT_TRIG_SEL;                     /**< LPIT trigger input select register, offset: 0x278 */
       uint8_t RESERVED_17[4];
  __IO uint32_t BISS1_EOT_CTL;                     /**< BISS #1 EOT interrupt ctrl register, offset: 0x280 */
  __I  uint32_t BISS1_EOT_STATUS;                  /**< BISS #1 EOT interrupt status register, offset: 0x284 */
       uint8_t RESERVED_18[8];
  __IO uint32_t IOMUX_GPIO_CTRL_0;                 /**< IOMUX GPIO selection / override control register #0, offset: 0x290 */
  __IO uint32_t IOMUX_GPIO_CTRL_1;                 /**< IOMUX GPIO selection / override control register #1, offset: 0x294 */
  __IO uint32_t IOMUX_GPIO_CTRL_2;                 /**< IOMUX GPIO selection / override control register #2, offset: 0x298 */
  __IO uint32_t IOMUX_GPIO_CTRL_3;                 /**< IOMUX GPIO selection / override control register #3, offset: 0x29C */
  __IO uint32_t IOMUX_GPIO_CTRL_4;                 /**< IOMUX GPIO selection / override control register #4, offset: 0x2A0 */
  __IO uint32_t IOMUX_GPIO_CTRL_5;                 /**< IOMUX GPIO selection / override control register #5, offset: 0x2A4 */
} BLK_CTRL_WAKEUPMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_WAKEUPMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_WAKEUPMIX_Register_Masks BLK_CTRL_WAKEUPMIX Register Masks
 * @{
 */

/*! @name I3C2_SDA_IRQ - I3C SDA IRQ CONTROL BIT */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_ENABLE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_ENABLE_SHIFT (0U)
/*! enable - IRQ enable bit */
#define BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_I3C2_SDA_IRQ_ENABLE_MASK)
/*! @} */

/*! @name MQS2_SETTINGS - Setting for MQS#2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_MQS_EN_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_MQS_EN_SHIFT (1U)
/*! MQS_EN - MQS enable */
#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_MQS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_MQS_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_MQS_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_SOFT_RESET_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_SOFT_RESET_SHIFT (2U)
/*! SOFT_RESET - MQS software Reset */
#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_SOFT_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_SOFT_RESET_SHIFT)) & BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_SOFT_RESET_MASK)

#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_OVERSAMPLE_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_OVERSAMPLE_SHIFT (3U)
/*! OVERSAMPLE - MQS oversample enable */
#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_OVERSAMPLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_OVERSAMPLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_OVERSAMPLE_MASK)

#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_CLK_DIVIDE_MASK (0xFF00U)
#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_CLK_DIVIDE_SHIFT (8U)
/*! CLK_DIVIDE - MQS clock divide factor configuration */
#define BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_CLK_DIVIDE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_CLK_DIVIDE_SHIFT)) & BLK_CTRL_WAKEUPMIX_MQS2_SETTINGS_CLK_DIVIDE_MASK)
/*! @} */

/*! @name SAI_CLK_SEL - sai2-4 mclk1-3 clk root mux settings */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK1_SHIFT (0U)
/*! SAI2_MCLK1 - SAI2 master clock #1 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK1_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK1_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK2_MASK (0x1EU)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK2_SHIFT (1U)
/*! SAI2_MCLK2 - SAI2 master clock #2 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK2_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK2_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK3_MASK (0x1E0U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK3_SHIFT (5U)
/*! SAI2_MCLK3 - SAI2 master clock #3 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK3_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI2_MCLK3_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_SHIFT (9U)
/*! SAI3_MCLK1 - SAI3 master clock #1 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK1_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_MASK (0x3C00U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_SHIFT (10U)
/*! SAI3_MCLK2 - SAI3 master clock #2 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK2_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_MASK (0x3C000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_SHIFT (14U)
/*! SAI3_MCLK3 - SAI3 master clock #3 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI3_MCLK3_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_SHIFT (18U)
/*! SAI4_MCLK1 - SAI4 master clock #1 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK1_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_MASK (0x780000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_SHIFT (19U)
/*! SAI4_MCLK2 - SAI4 master clock #2 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK2_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_MASK (0x7800000U)
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_SHIFT (23U)
/*! SAI4_MCLK3 - SAI4 master clock #3 source selection */
#define BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI_CLK_SEL_SAI4_MCLK3_MASK)
/*! @} */

/*! @name VOLT_DETECT - Voltage detectors output */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_AON_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_AON_SHIFT (0U)
/*! supply_detector_AON - Voltage detectors output of AON */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_AON_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_AON_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_GPIO_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_GPIO_SHIFT (1U)
/*! supply_detector_GPIO - Voltage detectors output of GPIO */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_GPIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_GPIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_GPIO_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_SD2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_SD2_SHIFT (2U)
/*! supply_detector_SD2 - Voltage detectors output of SD2 */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_SD2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_SD2_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_SD2_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_WAKEUP_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_WAKEUP_SHIFT (3U)
/*! supply_detector_WAKEUP - Voltage detectors output of WAKEUP */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_WAKEUP_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_WAKEUP_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_CCM_DAP_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_CCM_DAP_SHIFT (4U)
/*! supply_detector_CCM_DAP - Voltage detectors output of CCM DAP */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_CCM_DAP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_CCM_DAP_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_CCM_DAP_MASK)

#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_ENET_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_ENET_SHIFT (5U)
/*! supply_detector_ENET - Voltage detectors output of ENET */
#define BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_ENET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_ENET_SHIFT)) & BLK_CTRL_WAKEUPMIX_VOLT_DETECT_SUPPLY_DETECTOR_ENET_MASK)
/*! @} */

/*! @name I3C2_WAKEUP - I3C2 WAKEUPX CLR */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_IRQ_CLR_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_IRQ_CLR_SHIFT (0U)
/*! irq_clr - I3C wakeup interrupt clear. */
#define BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_IRQ_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_IRQ_CLR_SHIFT)) & BLK_CTRL_WAKEUPMIX_I3C2_WAKEUP_IRQ_CLR_MASK)
/*! @} */

/*! @name AXI_ATTR_CFG - AXI CACHE CONTROL BIT */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_SHIFT (0U)
/*! arcache_usdhc1 - Static value of arcache[1] = CACHEABLE (C) for AXI initiator usdhc1
 *  0b1..Cacheable reads
 *  0b0..Non-cacheable reads
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_SHIFT (1U)
/*! awcache_usdhc1 - Static value of awcache[1] = CACHEABLE (C) for AXI initiator usdhc1
 *  0b1..Cacheable writes
 *  0b0..Non-cacheable writes
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_SHIFT (2U)
/*! arcache_usdhc2 - Static value of arcache[1] = CACHEABLE (C) for AXI initiator usdhc2
 *  0b1..Cacheable reads
 *  0b0..Non-cacheable reads
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_SHIFT (3U)
/*! awcache_usdhc2 - Static value of awcache[1] = CACHEABLE (C) for AXI initiator usdhc2
 *  0b1..Cacheable writes
 *  0b0..Non-cacheable writes
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC3_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC3_SHIFT (4U)
/*! arcache_usdhc3 - Static value of arcache[1] = CACHEABLE (C) for AXI initiator usdhc3
 *  0b1..Cacheable reads
 *  0b0..Non-cacheable reads
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC3_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC3_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC3_SHIFT (5U)
/*! awcache_usdhc3 - Static value of awcache[1] = CACHEABLE (C) for AXI initiator usdhc3
 *  0b1..Cacheable writes
 *  0b0..Non-cacheable writes
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC3_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM33 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN4_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN4_SHIFT (2U)
/*! can4 - CAN4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN5_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN5_SHIFT (3U)
/*! can5 - CAN5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_CAN5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPI2C8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT3_SHIFT (13U)
/*! lpit3 - IT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPIT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI3_SHIFT (14U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI4_SHIFT (15U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI5_SHIFT (16U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI6_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI6_SHIFT (17U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI7_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI7_SHIFT (18U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI8_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI8_SHIFT (19U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPSPI8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPTMR2_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPTMR2_SHIFT (20U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM3_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM3_SHIFT (21U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM4_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM4_SHIFT (22U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM5_SHIFT (23U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM6_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM6_SHIFT (24U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG5_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG5_SHIFT (25U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG6_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG6_SHIFT (26U)
/*! wdog6 - WDOG6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_WDOG6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_I3C2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_I3C2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI2_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI2_SHIFT (28U)
/*! sai2 - SAI2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI3_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI3_SHIFT (29U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI4_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI4_SHIFT (30U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_SAI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_EDMA2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_EDMA2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_EDMA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_EDMA2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33_EDMA2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C0 - IPG DEBUG mask bit for CA55 core0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN4_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN4_SHIFT (2U)
/*! can4 - CAN4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN5_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN5_SHIFT (3U)
/*! can5 - CAN5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_CAN5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPI2C8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT3_SHIFT (13U)
/*! lpit3 - IT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPIT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI3_SHIFT (14U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI4_SHIFT (15U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI5_SHIFT (16U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI6_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI6_SHIFT (17U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI7_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI7_SHIFT (18U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI8_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI8_SHIFT (19U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPSPI8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPTMR2_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPTMR2_SHIFT (20U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM3_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM3_SHIFT (21U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM4_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM4_SHIFT (22U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM5_SHIFT (23U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM6_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM6_SHIFT (24U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG5_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG5_SHIFT (25U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG6_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG6_SHIFT (26U)
/*! wdog6 - WDOG6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_WDOG6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_I3C2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_I3C2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI2_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI2_SHIFT (28U)
/*! sai2 - SAI2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI3_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI3_SHIFT (29U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI4_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI4_SHIFT (30U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_SAI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_EDMA2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_EDMA2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_EDMA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_EDMA2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C0_EDMA2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C1 - IPG DEBUG mask bit for CA55 core1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN4_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN4_SHIFT (2U)
/*! can4 - CAN4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN5_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN5_SHIFT (3U)
/*! can5 - CAN5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_CAN5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPI2C8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT3_SHIFT (13U)
/*! lpit3 - IT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPIT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI3_SHIFT (14U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI4_SHIFT (15U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI5_SHIFT (16U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI6_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI6_SHIFT (17U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI7_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI7_SHIFT (18U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI8_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI8_SHIFT (19U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPSPI8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPTMR2_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPTMR2_SHIFT (20U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM3_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM3_SHIFT (21U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM4_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM4_SHIFT (22U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM5_SHIFT (23U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM6_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM6_SHIFT (24U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG5_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG5_SHIFT (25U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG6_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG6_SHIFT (26U)
/*! wdog6 - WDOG6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_WDOG6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_I3C2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_I3C2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI2_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI2_SHIFT (28U)
/*! sai2 - SAI2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI3_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI3_SHIFT (29U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI4_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI4_SHIFT (30U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_SAI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_EDMA2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_EDMA2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_EDMA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_EDMA2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C1_EDMA2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C2 - IPG DEBUG mask bit for CA55 core2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN4_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN4_SHIFT (2U)
/*! can4 - CAN4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN5_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN5_SHIFT (3U)
/*! can5 - CAN5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_CAN5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_FLEXIO1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_FLEXIO1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_FLEXIO2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_FLEXIO2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPI2C8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPIT2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPIT2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPIT3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPIT3_SHIFT (13U)
/*! lpit3 - IT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPIT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPIT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPIT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI3_SHIFT (14U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI4_SHIFT (15U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI5_SHIFT (16U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI6_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI6_SHIFT (17U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI7_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI7_SHIFT (18U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI8_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI8_SHIFT (19U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPSPI8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPTMR2_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPTMR2_SHIFT (20U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM3_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM3_SHIFT (21U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM4_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM4_SHIFT (22U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM5_SHIFT (23U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM6_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM6_SHIFT (24U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_WDOG5_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_WDOG5_SHIFT (25U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_WDOG6_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_WDOG6_SHIFT (26U)
/*! wdog6 - WDOG6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_WDOG6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_WDOG6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_WDOG6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_I3C2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_I3C2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI2_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI2_SHIFT (28U)
/*! sai2 - SAI2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI3_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI3_SHIFT (29U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI4_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI4_SHIFT (30U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_SAI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_EDMA2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_EDMA2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_EDMA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_EDMA2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C2_EDMA2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C3 - IPG DEBUG mask bit for CA55 core3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN4_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN4_SHIFT (2U)
/*! can4 - CAN4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN5_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN5_SHIFT (3U)
/*! can5 - CAN5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_CAN5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_FLEXIO1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_FLEXIO1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_FLEXIO2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_FLEXIO2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPI2C8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPIT2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPIT2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPIT3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPIT3_SHIFT (13U)
/*! lpit3 - IT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPIT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPIT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPIT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI3_SHIFT (14U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI4_SHIFT (15U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI5_SHIFT (16U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI6_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI6_SHIFT (17U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI7_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI7_SHIFT (18U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI8_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI8_SHIFT (19U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPSPI8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPTMR2_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPTMR2_SHIFT (20U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM3_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM3_SHIFT (21U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM4_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM4_SHIFT (22U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM5_SHIFT (23U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM6_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM6_SHIFT (24U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_WDOG5_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_WDOG5_SHIFT (25U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_WDOG6_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_WDOG6_SHIFT (26U)
/*! wdog6 - WDOG6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_WDOG6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_WDOG6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_WDOG6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_I3C2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_I3C2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI2_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI2_SHIFT (28U)
/*! sai2 - SAI2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI3_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI3_SHIFT (29U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI4_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI4_SHIFT (30U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_SAI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_EDMA2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_EDMA2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_EDMA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_EDMA2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CA55C3_EDMA2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM7_0 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN4_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN4_SHIFT (2U)
/*! can4 - CAN4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN5_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN5_SHIFT (3U)
/*! can5 - CAN5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_CAN5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_FLEXIO1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_FLEXIO1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_FLEXIO2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_FLEXIO2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPI2C8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPIT2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPIT2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPIT3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPIT3_SHIFT (13U)
/*! lpit3 - IT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPIT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPIT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPIT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI3_SHIFT (14U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI4_SHIFT (15U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI5_SHIFT (16U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI6_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI6_SHIFT (17U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI7_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI7_SHIFT (18U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI8_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI8_SHIFT (19U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPSPI8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPTMR2_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPTMR2_SHIFT (20U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM3_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM3_SHIFT (21U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM4_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM4_SHIFT (22U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM5_SHIFT (23U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM6_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM6_SHIFT (24U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_WDOG5_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_WDOG5_SHIFT (25U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_WDOG6_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_WDOG6_SHIFT (26U)
/*! wdog6 - WDOG6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_WDOG6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_WDOG6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_WDOG6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_I3C2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_I3C2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI2_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI2_SHIFT (28U)
/*! sai2 - SAI2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI3_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI3_SHIFT (29U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI4_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI4_SHIFT (30U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_SAI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_EDMA2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_EDMA2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_EDMA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_EDMA2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_0_EDMA2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM7_1 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN4_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN4_SHIFT (2U)
/*! can4 - CAN4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN5_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN5_SHIFT (3U)
/*! can5 - CAN5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_CAN5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_FLEXIO1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_FLEXIO1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_FLEXIO2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_FLEXIO2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPI2C8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPIT2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPIT2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPIT3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPIT3_SHIFT (13U)
/*! lpit3 - IT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPIT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPIT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPIT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI3_SHIFT (14U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI4_SHIFT (15U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI5_SHIFT (16U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI6_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI6_SHIFT (17U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI7_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI7_SHIFT (18U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI8_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI8_SHIFT (19U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPSPI8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPTMR2_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPTMR2_SHIFT (20U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM3_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM3_SHIFT (21U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM4_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM4_SHIFT (22U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM5_SHIFT (23U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM6_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM6_SHIFT (24U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_WDOG5_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_WDOG5_SHIFT (25U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_WDOG6_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_WDOG6_SHIFT (26U)
/*! wdog6 - WDOG6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_WDOG6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_WDOG6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_WDOG6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_I3C2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_I3C2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI2_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI2_SHIFT (28U)
/*! sai2 - SAI2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI3_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI3_SHIFT (29U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI4_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI4_SHIFT (30U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_SAI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_EDMA2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_EDMA2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_EDMA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_EDMA2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_1_EDMA2_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM33SYNC - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN2_SHIFT (0U)
/*! can2 - CAN2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN3_SHIFT (1U)
/*! can3 - CAN3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN4_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN4_SHIFT (2U)
/*! can4 - CAN4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN5_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN5_SHIFT (3U)
/*! can5 - CAN5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_CAN5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_FLEXIO1_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_FLEXIO1_SHIFT (4U)
/*! flexio1 - FlexIO1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_FLEXIO2_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_FLEXIO2_SHIFT (5U)
/*! flexio2 - FlexIO2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C3_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C3_SHIFT (6U)
/*! lpi2c3 - I2C3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C4_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C4_SHIFT (7U)
/*! lpi2c4 - I2C4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C5_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C5_SHIFT (8U)
/*! lpi2c5 - I2C5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C6_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C6_SHIFT (9U)
/*! lpi2c6 - I2C6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C7_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C7_SHIFT (10U)
/*! lpi2c7 - I2C7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C8_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C8_SHIFT (11U)
/*! lpi2c8 - I2C8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPI2C8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPIT2_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPIT2_SHIFT (12U)
/*! lpit2 - IT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPIT3_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPIT3_SHIFT (13U)
/*! lpit3 - IT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPIT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPIT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPIT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI3_SHIFT (14U)
/*! lpspi3 - SPI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI4_SHIFT (15U)
/*! lpspi4 - SPI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI5_SHIFT (16U)
/*! lpspi5 - SPI5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI6_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI6_SHIFT (17U)
/*! lpspi6 - SPI6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI7_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI7_SHIFT (18U)
/*! lpspi7 - SPI7 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI8_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI8_SHIFT (19U)
/*! lpspi8 - SPI8 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPSPI8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPTMR2_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPTMR2_SHIFT (20U)
/*! lptmr2 - TMR2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM3_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM3_SHIFT (21U)
/*! tpm3 - TPM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM4_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM4_SHIFT (22U)
/*! tpm4 - TPM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM5_SHIFT (23U)
/*! tpm5 - TPM5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM6_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM6_SHIFT (24U)
/*! tpm6 - TPM6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_WDOG5_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_WDOG5_SHIFT (25U)
/*! wdog5 - WDOG5 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_WDOG6_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_WDOG6_SHIFT (26U)
/*! wdog6 - WDOG6 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_WDOG6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_WDOG6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_WDOG6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_I3C2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_I3C2_SHIFT (27U)
/*! i3c2 - I3C2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI2_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI2_SHIFT (28U)
/*! sai2 - SAI2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI3_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI3_SHIFT (29U)
/*! sai3 - SAI3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI4_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI4_SHIFT (30U)
/*! sai4 - SAI4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_SAI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_EDMA2_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_EDMA2_SHIFT (31U)
/*! edma2 - EDMA2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_EDMA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_EDMA2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM33SYNC_EDMA2_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CM33 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_EDMA3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_EDMA3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_EDMA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_EDMA3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_EDMA3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_EDMA4_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_EDMA4_SHIFT (1U)
/*! edma4 - EDMA4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_EDMA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_EDMA4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_EDMA4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_GPT4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM1_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM1_SHIFT (5U)
/*! pwm1 - PWM1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM2_SHIFT (6U)
/*! pwm2 - PWM2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM3_SHIFT (7U)
/*! pwm3 - PWM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM4_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM4_SHIFT (8U)
/*! pwm4 - PWM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_PWM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC1_SHIFT (9U)
/*! sinc1 - SINC1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC2_SHIFT (10U)
/*! sinc2 - SINC2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC3_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC3_SHIFT (11U)
/*! sinc3 - SINC3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC4_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC4_SHIFT (12U)
/*! sinc4 - SINC4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33_SINC4_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C0 - IPG DEBUG mask bit for CA55 core0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_EDMA3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_EDMA3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_EDMA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_EDMA3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_EDMA3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_EDMA4_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_EDMA4_SHIFT (1U)
/*! edma4 - EDMA4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_EDMA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_EDMA4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_EDMA4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_GPT4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM1_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM1_SHIFT (5U)
/*! pwm1 - PWM1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM2_SHIFT (6U)
/*! pwm2 - PWM2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM3_SHIFT (7U)
/*! pwm3 - PWM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM4_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM4_SHIFT (8U)
/*! pwm4 - PWM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_PWM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC1_SHIFT (9U)
/*! sinc1 - SINC1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC2_SHIFT (10U)
/*! sinc2 - SINC2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC3_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC3_SHIFT (11U)
/*! sinc3 - SINC3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC4_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC4_SHIFT (12U)
/*! sinc4 - SINC4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C0_SINC4_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C1 - IPG DEBUG mask bit for CA55 core1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_EDMA3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_EDMA3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_EDMA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_EDMA3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_EDMA3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_EDMA4_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_EDMA4_SHIFT (1U)
/*! edma4 - EDMA4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_EDMA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_EDMA4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_EDMA4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_GPT4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM1_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM1_SHIFT (5U)
/*! pwm1 - PWM1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM2_SHIFT (6U)
/*! pwm2 - PWM2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM3_SHIFT (7U)
/*! pwm3 - PWM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM4_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM4_SHIFT (8U)
/*! pwm4 - PWM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_PWM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC1_SHIFT (9U)
/*! sinc1 - SINC1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC2_SHIFT (10U)
/*! sinc2 - SINC2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC3_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC3_SHIFT (11U)
/*! sinc3 - SINC3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC4_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC4_SHIFT (12U)
/*! sinc4 - SINC4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C1_SINC4_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C2 - IPG DEBUG mask bit for CA55 core2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_EDMA3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_EDMA3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_EDMA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_EDMA3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_EDMA3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_EDMA4_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_EDMA4_SHIFT (1U)
/*! edma4 - EDMA4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_EDMA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_EDMA4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_EDMA4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_GPT4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM1_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM1_SHIFT (5U)
/*! pwm1 - PWM1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM2_SHIFT (6U)
/*! pwm2 - PWM2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM3_SHIFT (7U)
/*! pwm3 - PWM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM4_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM4_SHIFT (8U)
/*! pwm4 - PWM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_PWM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC1_SHIFT (9U)
/*! sinc1 - SINC1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC2_SHIFT (10U)
/*! sinc2 - SINC2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC3_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC3_SHIFT (11U)
/*! sinc3 - SINC3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC4_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC4_SHIFT (12U)
/*! sinc4 - SINC4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C2_SINC4_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CA55C3 - IPG DEBUG mask bit for CA55 core3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_EDMA3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_EDMA3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_EDMA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_EDMA3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_EDMA3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_EDMA4_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_EDMA4_SHIFT (1U)
/*! edma4 - EDMA4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_EDMA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_EDMA4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_EDMA4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_GPT4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM1_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM1_SHIFT (5U)
/*! pwm1 - PWM1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM2_SHIFT (6U)
/*! pwm2 - PWM2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM3_SHIFT (7U)
/*! pwm3 - PWM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM4_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM4_SHIFT (8U)
/*! pwm4 - PWM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_PWM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC1_SHIFT (9U)
/*! sinc1 - SINC1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC2_SHIFT (10U)
/*! sinc2 - SINC2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC3_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC3_SHIFT (11U)
/*! sinc3 - SINC3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC4_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC4_SHIFT (12U)
/*! sinc4 - SINC4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CA55C3_SINC4_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CM7_0 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_EDMA3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_EDMA3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_EDMA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_EDMA3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_EDMA3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_EDMA4_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_EDMA4_SHIFT (1U)
/*! edma4 - EDMA4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_EDMA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_EDMA4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_EDMA4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_GPT4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM1_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM1_SHIFT (5U)
/*! pwm1 - PWM1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM2_SHIFT (6U)
/*! pwm2 - PWM2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM3_SHIFT (7U)
/*! pwm3 - PWM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM4_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM4_SHIFT (8U)
/*! pwm4 - PWM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_PWM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC1_SHIFT (9U)
/*! sinc1 - SINC1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC2_SHIFT (10U)
/*! sinc2 - SINC2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC3_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC3_SHIFT (11U)
/*! sinc3 - SINC3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC4_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC4_SHIFT (12U)
/*! sinc4 - SINC4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_0_SINC4_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CM7_1 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_EDMA3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_EDMA3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_EDMA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_EDMA3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_EDMA3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_EDMA4_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_EDMA4_SHIFT (1U)
/*! edma4 - EDMA4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_EDMA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_EDMA4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_EDMA4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_GPT4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM1_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM1_SHIFT (5U)
/*! pwm1 - PWM1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM2_SHIFT (6U)
/*! pwm2 - PWM2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM3_SHIFT (7U)
/*! pwm3 - PWM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM4_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM4_SHIFT (8U)
/*! pwm4 - PWM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_PWM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC1_SHIFT (9U)
/*! sinc1 - SINC1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC2_SHIFT (10U)
/*! sinc2 - SINC2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC3_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC3_SHIFT (11U)
/*! sinc3 - SINC3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC4_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC4_SHIFT (12U)
/*! sinc4 - SINC4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM7_1_SINC4_MASK)
/*! @} */

/*! @name IPG_DEBUG_2_CM33SYNC - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_EDMA3_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_EDMA3_SHIFT (0U)
/*! edma3 - EDMA3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_EDMA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_EDMA3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_EDMA3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_EDMA4_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_EDMA4_SHIFT (1U)
/*! edma4 - EDMA4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_EDMA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_EDMA4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_EDMA4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT2_SHIFT (2U)
/*! gpt2 - GPT2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT3_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT3_SHIFT (3U)
/*! gpt3 - GPT3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT4_SHIFT (4U)
/*! gpt4 - GPT4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_GPT4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM1_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM1_SHIFT (5U)
/*! pwm1 - PWM1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM2_SHIFT (6U)
/*! pwm2 - PWM2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM3_SHIFT (7U)
/*! pwm3 - PWM3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM4_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM4_SHIFT (8U)
/*! pwm4 - PWM4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_PWM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC1_SHIFT (9U)
/*! sinc1 - SINC1 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC2_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC2_SHIFT (10U)
/*! sinc2 - SINC2 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC3_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC3_SHIFT (11U)
/*! sinc3 - SINC3 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC4_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC4_SHIFT (12U)
/*! sinc4 - SINC4 debug */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG_2_CM33SYNC_SINC4_MASK)
/*! @} */

/*! @name DBG_TRACE_CTL - DEBUG TRACE control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_CLKEN_CSSWO_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_CLKEN_CSSWO_SHIFT (0U)
/*! clken_csswo - Enable control of the debug/trace CSSWO clock. 0: trace_en_swo disabled, trace
 *    port clock OFF 1: trace_en_swo enabled, trace port clock ON
 */
#define BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_CLKEN_CSSWO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_CLKEN_CSSWO_SHIFT)) & BLK_CTRL_WAKEUPMIX_DBG_TRACE_CTL_CLKEN_CSSWO_MASK)
/*! @} */

/*! @name SMMU_TBU_IRQ_SETUP - SMMU TBU IRQ resynchronization setup */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SMMU_TBU_IRQ_SETUP_STRETCH_RATIO_MASK (0x3U)
#define BLK_CTRL_WAKEUPMIX_SMMU_TBU_IRQ_SETUP_STRETCH_RATIO_SHIFT (0U)
/*! stretch_ratio - SMMU TBU IRQ stretch ratio for resynchronization
 *  0b00..Stretch IRQ pulse by 2
 *  0b01..Stretch IRQ pulse by 4
 *  0b10..Stretch IRQ pulse by 8
 *  0b11..Stretch IRQ pulse by 16
 */
#define BLK_CTRL_WAKEUPMIX_SMMU_TBU_IRQ_SETUP_STRETCH_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SMMU_TBU_IRQ_SETUP_STRETCH_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_SMMU_TBU_IRQ_SETUP_STRETCH_RATIO_MASK)
/*! @} */

/*! @name INITIATOR_TIMEOUT - NOC initiator timeout status */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA0_RD_TIMEOUT_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA0_RD_TIMEOUT_SHIFT (0U)
/*! ma0_rd_timeout - Initiator timeout for NOC MAIN read port ma0 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA0_RD_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA0_RD_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA0_RD_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA0_WR_TIMEOUT_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA0_WR_TIMEOUT_SHIFT (1U)
/*! ma0_wr_timeout - Initiator timeout for NOC MAIN write port ma0 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA0_WR_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA0_WR_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA0_WR_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA1_RD_TIMEOUT_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA1_RD_TIMEOUT_SHIFT (2U)
/*! ma1_rd_timeout - Initiator timeout for NOC MAIN read port ma1 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA1_RD_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA1_RD_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA1_RD_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA1_WR_TIMEOUT_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA1_WR_TIMEOUT_SHIFT (3U)
/*! ma1_wr_timeout - Initiator timeout for NOC MAIN write port ma1 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA1_WR_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA1_WR_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA1_WR_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA2_RD_TIMEOUT_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA2_RD_TIMEOUT_SHIFT (4U)
/*! ma2_rd_timeout - Initiator timeout for NOC MAIN read port ma2 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA2_RD_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA2_RD_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA2_RD_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA2_WR_TIMEOUT_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA2_WR_TIMEOUT_SHIFT (5U)
/*! ma2_wr_timeout - Initiator timeout for NOC MAIN write port ma2 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA2_WR_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA2_WR_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA2_WR_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA3_RD_TIMEOUT_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA3_RD_TIMEOUT_SHIFT (6U)
/*! ma3_rd_timeout - Initiator timeout for NOC MAIN read port ma3 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA3_RD_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA3_RD_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA3_RD_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA3_WR_TIMEOUT_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA3_WR_TIMEOUT_SHIFT (7U)
/*! ma3_wr_timeout - Initiator timeout for NOC MAIN write port ma3 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA3_WR_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA3_WR_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA3_WR_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA4_RD_TIMEOUT_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA4_RD_TIMEOUT_SHIFT (8U)
/*! ma4_rd_timeout - Initiator timeout for NOC MAIN read port ma4 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA4_RD_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA4_RD_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA4_RD_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA4_WR_TIMEOUT_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA4_WR_TIMEOUT_SHIFT (9U)
/*! ma4_wr_timeout - Initiator timeout for NOC MAIN write port ma4 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA4_WR_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA4_WR_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA4_WR_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA5_RD_TIMEOUT_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA5_RD_TIMEOUT_SHIFT (10U)
/*! ma5_rd_timeout - Initiator timeout for NOC MAIN read port ma5 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA5_RD_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA5_RD_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA5_RD_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA5_WR_TIMEOUT_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA5_WR_TIMEOUT_SHIFT (11U)
/*! ma5_wr_timeout - Initiator timeout for NOC MAIN write port ma5 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA5_WR_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA5_WR_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA5_WR_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA6_RD_TIMEOUT_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA6_RD_TIMEOUT_SHIFT (12U)
/*! ma6_rd_timeout - Initiator timeout for NOC MAIN read port ma6 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA6_RD_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA6_RD_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA6_RD_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA6_WR_TIMEOUT_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA6_WR_TIMEOUT_SHIFT (13U)
/*! ma6_wr_timeout - Initiator timeout for NOC MAIN write port ma6 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA6_WR_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA6_WR_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA6_WR_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA7_RD_TIMEOUT_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA7_RD_TIMEOUT_SHIFT (14U)
/*! ma7_rd_timeout - Initiator timeout for NOC MAIN read port ma7 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA7_RD_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA7_RD_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA7_RD_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA7_WR_TIMEOUT_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA7_WR_TIMEOUT_SHIFT (15U)
/*! ma7_wr_timeout - Initiator timeout for NOC MAIN write port ma7 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA7_WR_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA7_WR_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA7_WR_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA8_RD_TIMEOUT_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA8_RD_TIMEOUT_SHIFT (16U)
/*! ma8_rd_timeout - Initiator timeout for NOC MAIN read port ma8 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA8_RD_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA8_RD_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA8_RD_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA8_WR_TIMEOUT_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA8_WR_TIMEOUT_SHIFT (17U)
/*! ma8_wr_timeout - Initiator timeout for NOC MAIN write port ma8 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA8_WR_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA8_WR_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MA8_WR_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD0_TIMEOUT_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD0_TIMEOUT_SHIFT (24U)
/*! md0_timeout - Initiator timeout for NOC MEGA port md0 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD0_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD0_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD0_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD1_TIMEOUT_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD1_TIMEOUT_SHIFT (25U)
/*! md1_timeout - Initiator timeout for NOC MEGA port md1 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD1_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD1_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD1_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD2_TIMEOUT_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD2_TIMEOUT_SHIFT (26U)
/*! md2_timeout - Initiator timeout for NOC MEGA port md2 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD2_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD2_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD2_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD3_TIMEOUT_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD3_TIMEOUT_SHIFT (27U)
/*! md3_timeout - Initiator timeout for NOC MEGA port md3 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD3_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD3_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD3_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD4_TIMEOUT_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD4_TIMEOUT_SHIFT (28U)
/*! md4_timeout - Initiator timeout for NOC MEGA port md4 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD4_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD4_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD4_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD6_TIMEOUT_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD6_TIMEOUT_SHIFT (30U)
/*! md6_timeout - Initiator timeout for NOC MEGA port md6 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD6_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD6_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD6_TIMEOUT_MASK)

#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD7_TIMEOUT_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD7_TIMEOUT_SHIFT (31U)
/*! md7_timeout - Initiator timeout for NOC MEGA port md7 */
#define BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD7_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD7_TIMEOUT_SHIFT)) & BLK_CTRL_WAKEUPMIX_INITIATOR_TIMEOUT_MD7_TIMEOUT_MASK)
/*! @} */

/*! @name NIU_TO_MA0 - Timeout Control for NOC main NIU master m_a_0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA0_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MA1 - Timeout Control for NOC main NIU master m_a_1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA1_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MA2 - Timeout Control for NOC main NIU master m_a_2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA2_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MA3 - Timeout Control for NOC main NIU master m_a_3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA3_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MA4 - Timeout Control for NOC main NIU master m_a_4 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA4_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MA5 - Timeout Control for NOC main NIU master m_a_5 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA5_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MA6 - Timeout Control for NOC main NIU master m_a_6 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA6_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MA7 - Timeout Control for NOC main NIU master m_a_7 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA7_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MA8 - Timeout Control for NOC main NIU master m_a_8 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MA8_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MD0 - Timeout Control for NOC mega NIU master m_d_0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD0_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MD1 - Timeout Control for NOC mega NIU master m_d_1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD1_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MD2 - Timeout Control for NOC mega NIU master m_d_2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD2_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MD3 - Timeout Control for NOC mega NIU master m_d_3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD3_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MD4 - Timeout Control for NOC mega NIU master m_d_4 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD4_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MD6 - Timeout Control for NOC mega NIU master m_d_6 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD6_DIS_MASK)
/*! @} */

/*! @name NIU_TO_MD7 - Timeout Control for NOC mega NIU master m_d_7 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_CLK_DIV_RATIO_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_CLK_DIV_RATIO_SHIFT (0U)
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
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_CLK_DIV_RATIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_CLK_DIV_RATIO_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_CLK_DIV_RATIO_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_UPD_MASK   (0x8000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_UPD_SHIFT  (15U)
/*! upd - Timeout divider selection update control */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_UPD(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_UPD_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_UPD_MASK)

#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_DIS_MASK   (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_DIS_SHIFT  (31U)
/*! dis - Timeout disable
 *  0b0..Timeout feature is enabled
 *  0b1..Timeout feature is disabled
 */
#define BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_DIS(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_NIU_TO_MD7_DIS_MASK)
/*! @} */

/*! @name IPG_STOP_CTL_0 - IPG_STOP control register #0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN2_STOP_ENABLE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN2_STOP_ENABLE_SHIFT (0U)
/*! can2_stop_enable - CAN#2 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN2_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN2_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN2_STOP_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN3_STOP_ENABLE_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN3_STOP_ENABLE_SHIFT (1U)
/*! can3_stop_enable - CAN#3 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN3_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN3_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN3_STOP_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN4_STOP_ENABLE_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN4_STOP_ENABLE_SHIFT (2U)
/*! can4_stop_enable - CAN#4 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN4_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN4_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN4_STOP_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN5_STOP_ENABLE_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN5_STOP_ENABLE_SHIFT (3U)
/*! can5_stop_enable - CAN#5 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN5_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN5_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_CAN5_STOP_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_EDMA2_STOP_ENABLE_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_EDMA2_STOP_ENABLE_SHIFT (4U)
/*! edma2_stop_enable - EDMA#2 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_EDMA2_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_EDMA2_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_EDMA2_STOP_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_EDMA3_STOP_ENABLE_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_EDMA3_STOP_ENABLE_SHIFT (5U)
/*! edma3_stop_enable - EDMA#3 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_EDMA3_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_EDMA3_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_EDMA3_STOP_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_XSPI1_STOP_ENABLE_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_XSPI1_STOP_ENABLE_SHIFT (8U)
/*! xspi1_stop_enable - XSPI#1 ipg_stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_XSPI1_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_XSPI1_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_0_XSPI1_STOP_ENABLE_MASK)
/*! @} */

/*! @name IPG_STOP_ACK_STATUS_0 - IPG_STOP_ACK status #0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN2_STOP_ACK_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN2_STOP_ACK_SHIFT (0U)
/*! can2_stop_ack - CAN#2 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN2_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN2_STOP_ACK_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN2_STOP_ACK_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN3_STOP_ACK_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN3_STOP_ACK_SHIFT (1U)
/*! can3_stop_ack - CAN#3 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN3_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN3_STOP_ACK_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN3_STOP_ACK_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN4_STOP_ACK_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN4_STOP_ACK_SHIFT (2U)
/*! can4_stop_ack - CAN#4 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN4_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN4_STOP_ACK_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN4_STOP_ACK_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN5_STOP_ACK_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN5_STOP_ACK_SHIFT (3U)
/*! can5_stop_ack - CAN#5 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN5_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN5_STOP_ACK_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_CAN5_STOP_ACK_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_EDMA2_STOP_ACK_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_EDMA2_STOP_ACK_SHIFT (4U)
/*! edma2_stop_ack - EDMA#2 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_EDMA2_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_EDMA2_STOP_ACK_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_EDMA2_STOP_ACK_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_EDMA3_STOP_ACK_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_EDMA3_STOP_ACK_SHIFT (5U)
/*! edma3_stop_ack - EDMA#3 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_EDMA3_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_EDMA3_STOP_ACK_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_EDMA3_STOP_ACK_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_XSPI1_STOP_ACK_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_XSPI1_STOP_ACK_SHIFT (8U)
/*! xspi1_stop_ack - XSPI#1 ipg_stop_ack status */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_XSPI1_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_XSPI1_STOP_ACK_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_ACK_STATUS_0_XSPI1_STOP_ACK_MASK)
/*! @} */

/*! @name IPG_STOP_CTL_1 - IPG_STOP control register #1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM3_STOP_ENABLE_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM3_STOP_ENABLE_SHIFT (3U)
/*! tpm3_stop_enable - TPM#3 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM3_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM3_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM3_STOP_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM4_STOP_ENABLE_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM4_STOP_ENABLE_SHIFT (4U)
/*! tpm4_stop_enable - TPM#4 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM4_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM4_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM4_STOP_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM5_STOP_ENABLE_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM5_STOP_ENABLE_SHIFT (5U)
/*! tpm5_stop_enable - TPM#5 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM5_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM5_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM5_STOP_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM6_STOP_ENABLE_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM6_STOP_ENABLE_SHIFT (6U)
/*! tpm6_stop_enable - TPM#6 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM6_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM6_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_TPM6_STOP_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_WDOG5_STOP_ENABLE_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_WDOG5_STOP_ENABLE_SHIFT (7U)
/*! wdog5_stop_enable - WDOG#5 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_WDOG5_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_WDOG5_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_WDOG5_STOP_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_WDOG6_STOP_ENABLE_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_WDOG6_STOP_ENABLE_SHIFT (8U)
/*! wdog6_stop_enable - WDOG#6 stop control */
#define BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_WDOG6_STOP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_WDOG6_STOP_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_STOP_CTL_1_WDOG6_STOP_ENABLE_MASK)
/*! @} */

/*! @name IPG_WAIT_CTL_1 - IPG_WAIT control #1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_WDOG5_WAIT_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_WDOG5_WAIT_SHIFT (7U)
/*! wdog5_wait - WDOG#5 ipg_wait control */
#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_WDOG5_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_WDOG5_WAIT_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_WDOG5_WAIT_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_WDOG6_WAIT_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_WDOG6_WAIT_SHIFT (8U)
/*! wdog6_wait - WDOG#6 ipg_wait control */
#define BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_WDOG6_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_WDOG6_WAIT_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_WAIT_CTL_1_WDOG6_WAIT_MASK)
/*! @} */

/*! @name QREQ_CTL_0 - QREQ control register #0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO2_QREQ_N_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO2_QREQ_N_SHIFT (28U)
/*! gpio2_qreq_n - GPIO#2 AHB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO2_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO2_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO2_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO3_QREQ_N_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO3_QREQ_N_SHIFT (29U)
/*! gpio3_qreq_n - GPIO#3 AHB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO3_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO3_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO3_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO4_QREQ_N_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO4_QREQ_N_SHIFT (30U)
/*! gpio4_qreq_n - GPIO#4 AHB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO4_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO4_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO4_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO5_QREQ_N_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO5_QREQ_N_SHIFT (31U)
/*! gpio5_qreq_n - GPIO#5 AHB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO5_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO5_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_0_GPIO5_QREQ_N_MASK)
/*! @} */

/*! @name QACCEPT_STATUS_0 - QACCEPT status register #0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO2_QACCEPT_N_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO2_QACCEPT_N_SHIFT (28U)
/*! gpio2_qaccept_n - GPIO#2 AHB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO2_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO2_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO2_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO3_QACCEPT_N_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO3_QACCEPT_N_SHIFT (29U)
/*! gpio3_qaccept_n - GPIO#3 AHB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO3_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO3_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO3_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO4_QACCEPT_N_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO4_QACCEPT_N_SHIFT (30U)
/*! gpio4_qaccept_n - GPIO#4 AHB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO4_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO4_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO4_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO5_QACCEPT_N_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO5_QACCEPT_N_SHIFT (31U)
/*! gpio5_qaccept_n - GPIO#5 AHB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO5_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO5_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_0_GPIO5_QACCEPT_N_MASK)
/*! @} */

/*! @name QACTIVE_STATUS_0 - QACTIVE status register #0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO2_QACTIVE_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO2_QACTIVE_SHIFT (28U)
/*! gpio2_qactive - GPIO#2 AHB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO2_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO2_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO2_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO3_QACTIVE_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO3_QACTIVE_SHIFT (29U)
/*! gpio3_qactive - GPIO#3 AHB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO3_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO3_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO3_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO4_QACTIVE_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO4_QACTIVE_SHIFT (30U)
/*! gpio4_qactive - GPIO#4 AHB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO4_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO4_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO4_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO5_QACTIVE_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO5_QACTIVE_SHIFT (31U)
/*! gpio5_qactive - GPIO#5 AHB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO5_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO5_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_0_GPIO5_QACTIVE_MASK)
/*! @} */

/*! @name QREQ_CTL_2 - QREQ control register #2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_FLEXIO1_APB_QREQ_N_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_FLEXIO1_APB_QREQ_N_SHIFT (6U)
/*! flexio1_apb_qreq_n - FlexIO#1 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_FLEXIO1_APB_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_FLEXIO1_APB_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_FLEXIO1_APB_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_FLEXIO2_APB_QREQ_N_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_FLEXIO2_APB_QREQ_N_SHIFT (7U)
/*! flexio2_apb_qreq_n - FlexIO#2 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_FLEXIO2_APB_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_FLEXIO2_APB_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_FLEXIO2_APB_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C3_IPS_QREQ_N_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C3_IPS_QREQ_N_SHIFT (9U)
/*! lpi2c3_ips_qreq_n - LP-I2C#3 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C3_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C3_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C3_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C4_IPS_QREQ_N_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C4_IPS_QREQ_N_SHIFT (10U)
/*! lpi2c4_ips_qreq_n - LP-I2C#4 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C4_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C4_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C4_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C5_IPS_QREQ_N_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C5_IPS_QREQ_N_SHIFT (11U)
/*! lpi2c5_ips_qreq_n - LP-I2C#5 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C5_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C5_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C5_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C6_IPS_QREQ_N_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C6_IPS_QREQ_N_SHIFT (12U)
/*! lpi2c6_ips_qreq_n - LP-I2C#6 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C6_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C6_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C6_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C7_IPS_QREQ_N_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C7_IPS_QREQ_N_SHIFT (13U)
/*! lpi2c7_ips_qreq_n - LP-I2C#7 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C7_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C7_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C7_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C8_IPS_QREQ_N_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C8_IPS_QREQ_N_SHIFT (14U)
/*! lpi2c8_ips_qreq_n - LP-I2C#8 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C8_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C8_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPI2C8_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI3_IPS_QREQ_N_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI3_IPS_QREQ_N_SHIFT (16U)
/*! lpspi3_ips_qreq_n - LP-SPI#3 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI3_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI3_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI3_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI4_IPS_QREQ_N_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI4_IPS_QREQ_N_SHIFT (17U)
/*! lpspi4_ips_qreq_n - LP-SPI#4 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI4_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI4_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI4_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI5_IPS_QREQ_N_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI5_IPS_QREQ_N_SHIFT (18U)
/*! lpspi5_ips_qreq_n - LP-SPI#5 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI5_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI5_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI5_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI6_IPS_QREQ_N_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI6_IPS_QREQ_N_SHIFT (19U)
/*! lpspi6_ips_qreq_n - LP-SPI#6 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI6_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI6_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI6_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI7_IPS_QREQ_N_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI7_IPS_QREQ_N_SHIFT (20U)
/*! lpspi7_ips_qreq_n - LP-SPI#7 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI7_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI7_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI7_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI8_IPS_QREQ_N_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI8_IPS_QREQ_N_SHIFT (21U)
/*! lpspi8_ips_qreq_n - LP-SPI#8 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI8_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI8_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPSPI8_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART3_APB_QREQ_N_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART3_APB_QREQ_N_SHIFT (22U)
/*! lpuart3_apb_qreq_n - LP-UART#3 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART3_APB_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART3_APB_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART3_APB_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART4_APB_QREQ_N_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART4_APB_QREQ_N_SHIFT (23U)
/*! lpuart4_apb_qreq_n - LP-UART#4 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART4_APB_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART4_APB_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART4_APB_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART5_APB_QREQ_N_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART5_APB_QREQ_N_SHIFT (24U)
/*! lpuart5_apb_qreq_n - LP-UART#5 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART5_APB_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART5_APB_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART5_APB_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART6_APB_QREQ_N_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART6_APB_QREQ_N_SHIFT (25U)
/*! lpuart6_apb_qreq_n - LP-UART#6 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART6_APB_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART6_APB_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART6_APB_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART7_APB_QREQ_N_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART7_APB_QREQ_N_SHIFT (26U)
/*! lpuart7_apb_qreq_n - LP-UART#7 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART7_APB_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART7_APB_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART7_APB_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART8_APB_QREQ_N_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART8_APB_QREQ_N_SHIFT (27U)
/*! lpuart8_apb_qreq_n - LP-UART#8 APB qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART8_APB_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART8_APB_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_2_LPUART8_APB_QREQ_N_MASK)
/*! @} */

/*! @name QACCEPT_STATUS_2 - QACCEPT status register #2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_FLEXIO1_APB_QACCEPT_N_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_FLEXIO1_APB_QACCEPT_N_SHIFT (6U)
/*! flexio1_apb_qaccept_n - FlexIO#1 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_FLEXIO1_APB_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_FLEXIO1_APB_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_FLEXIO1_APB_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_FLEXIO2_APB_QACCEPT_N_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_FLEXIO2_APB_QACCEPT_N_SHIFT (7U)
/*! flexio2_apb_qaccept_n - FlexIO#2 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_FLEXIO2_APB_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_FLEXIO2_APB_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_FLEXIO2_APB_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C3_IPS_QACCEPT_N_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C3_IPS_QACCEPT_N_SHIFT (9U)
/*! lpi2c3_ips_qaccept_n - LP-I2C#3 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C3_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C3_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C3_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C4_IPS_QACCEPT_N_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C4_IPS_QACCEPT_N_SHIFT (10U)
/*! lpi2c4_ips_qaccept_n - LP-I2C#4 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C4_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C4_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C4_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C5_IPS_QACCEPT_N_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C5_IPS_QACCEPT_N_SHIFT (11U)
/*! lpi2c5_ips_qaccept_n - LP-I2C#5 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C5_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C5_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C5_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C6_IPS_QACCEPT_N_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C6_IPS_QACCEPT_N_SHIFT (12U)
/*! lpi2c6_ips_qaccept_n - LP-I2C#6 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C6_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C6_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C6_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C7_IPS_QACCEPT_N_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C7_IPS_QACCEPT_N_SHIFT (13U)
/*! lpi2c7_ips_qaccept_n - LP-I2C#7 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C7_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C7_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C7_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C8_IPS_QACCEPT_N_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C8_IPS_QACCEPT_N_SHIFT (14U)
/*! lpi2c8_ips_qaccept_n - LP-I2C#8 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C8_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C8_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPI2C8_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI3_IPS_QACCEPT_N_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI3_IPS_QACCEPT_N_SHIFT (16U)
/*! lpspi3_ips_qaccept_n - LP-SPI#3 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI3_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI3_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI3_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI4_IPS_QACCEPT_N_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI4_IPS_QACCEPT_N_SHIFT (17U)
/*! lpspi4_ips_qaccept_n - LP-SPI#4 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI4_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI4_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI4_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI5_IPS_QACCEPT_N_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI5_IPS_QACCEPT_N_SHIFT (18U)
/*! lpspi5_ips_qaccept_n - LP-SPI#5 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI5_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI5_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI5_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI6_IPS_QACCEPT_N_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI6_IPS_QACCEPT_N_SHIFT (19U)
/*! lpspi6_ips_qaccept_n - LP-SPI#6 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI6_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI6_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI6_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI7_IPS_QACCEPT_N_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI7_IPS_QACCEPT_N_SHIFT (20U)
/*! lpspi7_ips_qaccept_n - LP-SPI#7 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI7_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI7_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI7_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI8_IPS_QACCEPT_N_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI8_IPS_QACCEPT_N_SHIFT (21U)
/*! lpspi8_ips_qaccept_n - LP-SPI#8 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI8_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI8_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPSPI8_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART3_APB_QACCEPT_N_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART3_APB_QACCEPT_N_SHIFT (22U)
/*! lpuart3_apb_qaccept_n - LP-UART#3 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART3_APB_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART3_APB_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART3_APB_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART4_APB_QACCEPT_N_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART4_APB_QACCEPT_N_SHIFT (23U)
/*! lpuart4_apb_qaccept_n - LP-UART#4 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART4_APB_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART4_APB_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART4_APB_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART5_APB_QACCEPT_N_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART5_APB_QACCEPT_N_SHIFT (24U)
/*! lpuart5_apb_qaccept_n - LP-UART#5 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART5_APB_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART5_APB_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART5_APB_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART6_APB_QACCEPT_N_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART6_APB_QACCEPT_N_SHIFT (25U)
/*! lpuart6_apb_qaccept_n - LP-UART#6 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART6_APB_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART6_APB_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART6_APB_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART7_APB_QACCEPT_N_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART7_APB_QACCEPT_N_SHIFT (26U)
/*! lpuart7_apb_qaccept_n - LP-UART#7 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART7_APB_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART7_APB_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART7_APB_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART8_APB_QACCEPT_N_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART8_APB_QACCEPT_N_SHIFT (27U)
/*! lpuart8_apb_qaccept_n - LP-UART#8 APB qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART8_APB_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART8_APB_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_2_LPUART8_APB_QACCEPT_N_MASK)
/*! @} */

/*! @name QACTIVE_STATUS_2 - QACTIVE status register #2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_FLEXIO1_APB_QACTIVE_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_FLEXIO1_APB_QACTIVE_SHIFT (6U)
/*! flexio1_apb_qactive - FlexIO#1 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_FLEXIO1_APB_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_FLEXIO1_APB_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_FLEXIO1_APB_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_FLEXIO2_APB_QACTIVE_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_FLEXIO2_APB_QACTIVE_SHIFT (7U)
/*! flexio2_apb_qactive - FlexIO#2 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_FLEXIO2_APB_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_FLEXIO2_APB_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_FLEXIO2_APB_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C3_IPS_QACTIVE_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C3_IPS_QACTIVE_SHIFT (9U)
/*! lpi2c3_ips_qactive - LP-I2C#3 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C3_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C3_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C3_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C4_IPS_QACTIVE_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C4_IPS_QACTIVE_SHIFT (10U)
/*! lpi2c4_ips_qactive - LP-I2C#4 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C4_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C4_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C4_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C5_IPS_QACTIVE_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C5_IPS_QACTIVE_SHIFT (11U)
/*! lpi2c5_ips_qactive - LP-I2C#5 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C5_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C5_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C5_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C6_IPS_QACTIVE_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C6_IPS_QACTIVE_SHIFT (12U)
/*! lpi2c6_ips_qactive - LP-I2C#6 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C6_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C6_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C6_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C7_IPS_QACTIVE_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C7_IPS_QACTIVE_SHIFT (13U)
/*! lpi2c7_ips_qactive - LP-I2C#7 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C7_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C7_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C7_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C8_IPS_QACTIVE_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C8_IPS_QACTIVE_SHIFT (14U)
/*! lpi2c8_ips_qactive - LP-I2C#8 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C8_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C8_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPI2C8_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI3_IPS_QACTIVE_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI3_IPS_QACTIVE_SHIFT (16U)
/*! lpspi3_ips_qactive - LP-SPI#3 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI3_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI3_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI3_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI4_IPS_QACTIVE_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI4_IPS_QACTIVE_SHIFT (17U)
/*! lpspi4_ips_qactive - LP-SPI#4 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI4_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI4_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI4_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI5_IPS_QACTIVE_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI5_IPS_QACTIVE_SHIFT (18U)
/*! lpspi5_ips_qactive - LP-SPI#5 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI5_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI5_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI5_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI6_IPS_QACTIVE_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI6_IPS_QACTIVE_SHIFT (19U)
/*! lpspi6_ips_qactive - LP-SPI#6 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI6_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI6_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI6_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI7_IPS_QACTIVE_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI7_IPS_QACTIVE_SHIFT (20U)
/*! lpspi7_ips_qactive - LP-SPI#7 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI7_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI7_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI7_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI8_IPS_QACTIVE_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI8_IPS_QACTIVE_SHIFT (21U)
/*! lpspi8_ips_qactive - LP-SPI#8 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI8_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI8_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPSPI8_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART3_APB_QACTIVE_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART3_APB_QACTIVE_SHIFT (22U)
/*! lpuart3_apb_qactive - LP-UART#3 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART3_APB_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART3_APB_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART3_APB_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART4_APB_QACTIVE_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART4_APB_QACTIVE_SHIFT (23U)
/*! lpuart4_apb_qactive - LP-UART#4 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART4_APB_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART4_APB_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART4_APB_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART5_APB_QACTIVE_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART5_APB_QACTIVE_SHIFT (24U)
/*! lpuart5_apb_qactive - LP-UART#5 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART5_APB_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART5_APB_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART5_APB_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART6_APB_QACTIVE_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART6_APB_QACTIVE_SHIFT (25U)
/*! lpuart6_apb_qactive - LP-UART#6 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART6_APB_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART6_APB_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART6_APB_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART7_APB_QACTIVE_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART7_APB_QACTIVE_SHIFT (26U)
/*! lpuart7_apb_qactive - LP-UART#7 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART7_APB_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART7_APB_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART7_APB_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART8_APB_QACTIVE_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART8_APB_QACTIVE_SHIFT (27U)
/*! lpuart8_apb_qactive - LP-UART#8 APB qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART8_APB_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART8_APB_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_2_LPUART8_APB_QACTIVE_MASK)
/*! @} */

/*! @name QREQ_CTL_3 - QREQ control register #3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI3_IPS_QREQ_N_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI3_IPS_QREQ_N_SHIFT (0U)
/*! sai3_ips_qreq_n - SAI#3 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI3_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI3_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI3_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI4_IPS_QREQ_N_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI4_IPS_QREQ_N_SHIFT (1U)
/*! sai4_ips_qreq_n - SAI#4 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI4_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI4_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI4_IPS_QREQ_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI2_IPS_QREQ_N_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI2_IPS_QREQ_N_SHIFT (2U)
/*! sai2_ips_qreq_n - SAI#5 IPS qreq_n control */
#define BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI2_IPS_QREQ_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI2_IPS_QREQ_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QREQ_CTL_3_SAI2_IPS_QREQ_N_MASK)
/*! @} */

/*! @name QACCEPT_STATUS_3 - QACCEPT status register #1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI3_IPS_QACCEPT_N_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI3_IPS_QACCEPT_N_SHIFT (0U)
/*! sai3_ips_qaccept_n - SAI#3 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI3_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI3_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI3_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI4_IPS_QACCEPT_N_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI4_IPS_QACCEPT_N_SHIFT (1U)
/*! sai4_ips_qaccept_n - SAI#4 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI4_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI4_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI4_IPS_QACCEPT_N_MASK)

#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI2_IPS_QACCEPT_N_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI2_IPS_QACCEPT_N_SHIFT (2U)
/*! sai2_ips_qaccept_n - SAI#5 IPS qaccept_n status */
#define BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI2_IPS_QACCEPT_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI2_IPS_QACCEPT_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACCEPT_STATUS_3_SAI2_IPS_QACCEPT_N_MASK)
/*! @} */

/*! @name QACTIVE_STATUS_3 - QACTIVE status register #3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI3_IPS_QACTIVE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI3_IPS_QACTIVE_SHIFT (0U)
/*! sai3_ips_qactive - SAI#3 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI3_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI3_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI3_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI4_IPS_QACTIVE_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI4_IPS_QACTIVE_SHIFT (1U)
/*! sai4_ips_qactive - SAI#4 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI4_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI4_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI4_IPS_QACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI2_IPS_QACTIVE_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI2_IPS_QACTIVE_SHIFT (2U)
/*! sai2_ips_qactive - SAI#5 IPS qactive status */
#define BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI2_IPS_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI2_IPS_QACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QACTIVE_STATUS_3_SAI2_IPS_QACTIVE_MASK)
/*! @} */

/*! @name ATU_CONF - IPG_WAIT control #1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_A_PM_EN_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_A_PM_EN_SHIFT (0U)
/*! atu_a_pm_en - ATU A PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_A_PM_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_A_PM_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_A_PM_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_A_ERROR_ON_MISS_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_A_ERROR_ON_MISS_SHIFT (1U)
/*! atu_a_error_on_miss - ATU A Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_A_ERROR_ON_MISS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_A_ERROR_ON_MISS_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_A_ERROR_ON_MISS_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_0_PM_EN_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_0_PM_EN_SHIFT (4U)
/*! atu_m7_0_pm_en - ATU M7 #0 PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_0_PM_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_0_PM_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_0_PM_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_0_ERROR_ON_MISS_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_0_ERROR_ON_MISS_SHIFT (5U)
/*! atu_m7_0_error_on_miss - ATU M7 #0 Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_0_ERROR_ON_MISS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_0_ERROR_ON_MISS_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_0_ERROR_ON_MISS_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_1_PM_EN_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_1_PM_EN_SHIFT (8U)
/*! atu_m7_1_pm_en - ATU M7 #1 PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_1_PM_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_1_PM_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_1_PM_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_1_ERROR_ON_MISS_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_1_ERROR_ON_MISS_SHIFT (9U)
/*! atu_m7_1_error_on_miss - ATU M7 #1 Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_1_ERROR_ON_MISS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_1_ERROR_ON_MISS_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M7_1_ERROR_ON_MISS_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M_PM_EN_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M_PM_EN_SHIFT (12U)
/*! atu_m_pm_en - ATU MEGA PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M_PM_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M_PM_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M_PM_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M_ERROR_ON_MISS_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M_ERROR_ON_MISS_SHIFT (13U)
/*! atu_m_error_on_miss - ATU MEGA Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M_ERROR_ON_MISS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M_ERROR_ON_MISS_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M_ERROR_ON_MISS_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M33SYNC_PM_EN_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M33SYNC_PM_EN_SHIFT (16U)
/*! atu_m33sync_pm_en - ATU M33SYNC PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M33SYNC_PM_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M33SYNC_PM_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M33SYNC_PM_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M33SYNC_ERROR_ON_MISS_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M33SYNC_ERROR_ON_MISS_SHIFT (17U)
/*! atu_m33sync_error_on_miss - ATU M33SYNC Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M33SYNC_ERROR_ON_MISS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M33SYNC_ERROR_ON_MISS_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_M33SYNC_ERROR_ON_MISS_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_V2X_PM_EN_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_V2X_PM_EN_SHIFT (20U)
/*! atu_v2x_pm_en - ATU V2X PM enable */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_V2X_PM_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_V2X_PM_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_V2X_PM_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_V2X_ERROR_ON_MISS_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_V2X_ERROR_ON_MISS_SHIFT (21U)
/*! atu_v2x_error_on_miss - ATU V2X Error-on-miss */
#define BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_V2X_ERROR_ON_MISS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_V2X_ERROR_ON_MISS_SHIFT)) & BLK_CTRL_WAKEUPMIX_ATU_CONF_ATU_V2X_ERROR_ON_MISS_MASK)
/*! @} */

/*! @name HIPERFACE1_SYNC_CTL1 - Hiperface #1 sync source configuration register #1/2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_MASK (0xFFFFU)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_SHIFT (0U)
/*! sync_div - Hiperface sync divider ratio */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_LOAD_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_LOAD_SHIFT (16U)
/*! sync_div_load - Hiperface sync divider ratio load/reload */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_LOAD(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_LOAD_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_LOAD_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_ENABLE_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_ENABLE_SHIFT (17U)
/*! sync_div_enable - Hiperface sync clock divider enable */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_DIV_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_ENABLE_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_ENABLE_SHIFT (18U)
/*! sync_enable - Hiperface sync enable */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_SOURCE_SEL_MASK (0x180000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_SOURCE_SEL_SHIFT (19U)
/*! sync_source_sel - Hiperface sync source select */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_SOURCE_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_SOURCE_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_CDC_BYPASS_B_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_CDC_BYPASS_B_SHIFT (21U)
/*! cdc_bypass_b - Hiperface sync CDC resynchronizer bypass control */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_CDC_BYPASS_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_CDC_BYPASS_B_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_CDC_BYPASS_B_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_STRETCH_BYPASS_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_STRETCH_BYPASS_SHIFT (22U)
/*! stretch_bypass - Hiperface sync stretcher bypass control */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_STRETCH_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_STRETCH_BYPASS_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_STRETCH_BYPASS_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_DIVIDER_BYPASS_B_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_DIVIDER_BYPASS_B_SHIFT (23U)
/*! divider_bypass_b - Hiperface sync divider bypass control */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_DIVIDER_BYPASS_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_DIVIDER_BYPASS_B_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_DIVIDER_BYPASS_B_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_START_SEL_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_START_SEL_SHIFT (24U)
/*! sync_start_sel - Hiperface (CCM) sync start/stop control mode selection */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_START_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_START_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_START_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_START_STOP_B_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_START_STOP_B_SHIFT (25U)
/*! sync_start_stop_b - Hiperface (CCM) sync source start/stop control */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_START_STOP_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_START_STOP_B_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_START_STOP_B_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_CLK_ENABLE_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_CLK_ENABLE_SHIFT (26U)
/*! sync_clk_enable - Hiperface sync's RESYNC clock enable */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_CLK_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_CLK_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_SYNC_CLK_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_CLK_SOURCE_SEL_MASK (0x18000000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_CLK_SOURCE_SEL_SHIFT (27U)
/*! clk_source_sel - Hiperface sync's RESYNC clock selection */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_CLK_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_CLK_SOURCE_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL1_CLK_SOURCE_SEL_MASK)
/*! @} */

/*! @name HIPERFACE1_SYNC_CTL2 - Hiperface #1 sync source configuration register #2/2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL2_STRETCH_WIDTH_MASK (0x1FFU)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL2_STRETCH_WIDTH_SHIFT (0U)
/*! stretch_width - Hiperface sync source pulse stretcher width */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL2_STRETCH_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL2_STRETCH_WIDTH_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_SYNC_CTL2_STRETCH_WIDTH_MASK)
/*! @} */

/*! @name HIPERFACE2_SYNC_CTL1 - Hiperface #2 sync source configuration register #1/2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_MASK (0xFFFFU)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_SHIFT (0U)
/*! sync_div - Hiperface sync divider ratio */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_LOAD_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_LOAD_SHIFT (16U)
/*! sync_div_load - Hiperface sync divider ratio load/reload */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_LOAD(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_LOAD_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_LOAD_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_ENABLE_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_ENABLE_SHIFT (17U)
/*! sync_div_enable - Hiperface sync clock divider enable */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_DIV_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_ENABLE_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_ENABLE_SHIFT (18U)
/*! sync_enable - Hiperface sync enable */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_SOURCE_SEL_MASK (0x180000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_SOURCE_SEL_SHIFT (19U)
/*! sync_source_sel - Hiperface sync source select */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_SOURCE_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_SOURCE_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_CDC_BYPASS_B_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_CDC_BYPASS_B_SHIFT (21U)
/*! cdc_bypass_b - Hiperface sync CDC resynchronizer bypass control */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_CDC_BYPASS_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_CDC_BYPASS_B_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_CDC_BYPASS_B_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_STRETCH_BYPASS_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_STRETCH_BYPASS_SHIFT (22U)
/*! stretch_bypass - Hiperface sync stretcher bypass control */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_STRETCH_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_STRETCH_BYPASS_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_STRETCH_BYPASS_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_DIVIDER_BYPASS_B_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_DIVIDER_BYPASS_B_SHIFT (23U)
/*! divider_bypass_b - Hiperface sync divider bypass control */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_DIVIDER_BYPASS_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_DIVIDER_BYPASS_B_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_DIVIDER_BYPASS_B_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_START_SEL_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_START_SEL_SHIFT (24U)
/*! sync_start_sel - Hiperface (CCM) sync start/stop control mode selection */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_START_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_START_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_START_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_START_STOP_B_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_START_STOP_B_SHIFT (25U)
/*! sync_start_stop_b - Hiperface (CCM) sync source start/stop control */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_START_STOP_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_START_STOP_B_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_START_STOP_B_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_CLK_ENABLE_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_CLK_ENABLE_SHIFT (26U)
/*! sync_clk_enable - Hiperface sync's RESYNC clock enable */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_CLK_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_CLK_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_SYNC_CLK_ENABLE_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_CLK_SOURCE_SEL_MASK (0x18000000U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_CLK_SOURCE_SEL_SHIFT (27U)
/*! clk_source_sel - Hiperface sync's RESYNC clock selection */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_CLK_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_CLK_SOURCE_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL1_CLK_SOURCE_SEL_MASK)
/*! @} */

/*! @name HIPERFACE2_SYNC_CTL2 - Hiperface #2 interrupt control register #2/2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL2_STRETCH_WIDTH_MASK (0x1FFU)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL2_STRETCH_WIDTH_SHIFT (0U)
/*! stretch_width - Hiperface sync source pulse stretcher width */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL2_STRETCH_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL2_STRETCH_WIDTH_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_SYNC_CTL2_STRETCH_WIDTH_MASK)
/*! @} */

/*! @name HIPERFACE1_INT_CTL - Hiperface #1 interrupt control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_INT_CTL_INT_CLEAR_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_INT_CTL_INT_CLEAR_SHIFT (0U)
/*! int_clear - Hiperface interrupt clear */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_INT_CTL_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_INT_CTL_INT_CLEAR_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_INT_CTL_INT_CLEAR_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_INT_CTL_INT_MASK_N_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_INT_CTL_INT_MASK_N_SHIFT (4U)
/*! int_mask_n - Hiperface interrupt mask */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE1_INT_CTL_INT_MASK_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE1_INT_CTL_INT_MASK_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE1_INT_CTL_INT_MASK_N_MASK)
/*! @} */

/*! @name HIPERFACE2_INT_CTL - Hiperface #2 interrupt control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_INT_CTL_INT_CLEAR_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_INT_CTL_INT_CLEAR_SHIFT (0U)
/*! int_clear - Hiperface interrupt clear */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_INT_CTL_INT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_INT_CTL_INT_CLEAR_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_INT_CTL_INT_CLEAR_MASK)

#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_INT_CTL_INT_MASK_N_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_INT_CTL_INT_MASK_N_SHIFT (4U)
/*! int_mask_n - Hiperface interrupt mask */
#define BLK_CTRL_WAKEUPMIX_HIPERFACE2_INT_CTL_INT_MASK_N(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_HIPERFACE2_INT_CTL_INT_MASK_N_SHIFT)) & BLK_CTRL_WAKEUPMIX_HIPERFACE2_INT_CTL_INT_MASK_N_MASK)
/*! @} */

/*! @name ENDAT3_STATUS - EnDat 3.0 status register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_ENDAT3_STATUS_SHORT_STATUS_MASK (0xFFU)
#define BLK_CTRL_WAKEUPMIX_ENDAT3_STATUS_SHORT_STATUS_SHIFT (0U)
/*! short_status - EnDAT3.0 short_status[7:0] */
#define BLK_CTRL_WAKEUPMIX_ENDAT3_STATUS_SHORT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENDAT3_STATUS_SHORT_STATUS_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENDAT3_STATUS_SHORT_STATUS_MASK)
/*! @} */

/*! @name FLEXIO1_3_MUX0_SEL - FlexIO #1/#3 IO mux #0 selection */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX0_SEL_OUTPUT_SEL_MASK (0xFFFFU)
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX0_SEL_OUTPUT_SEL_SHIFT (0U)
/*! output_sel - Output mux selection */
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX0_SEL_OUTPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX0_SEL_OUTPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX0_SEL_OUTPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX0_SEL_INPUT_SEL_MASK (0xFFFF0000U)
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX0_SEL_INPUT_SEL_SHIFT (16U)
/*! input_sel - Input mux selection */
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX0_SEL_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX0_SEL_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX0_SEL_INPUT_SEL_MASK)
/*! @} */

/*! @name FLEXIO1_3_MUX1_SEL - FlexIO #1/#3 IO mux #1 selection */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX1_SEL_OUTPUT_SEL_MASK (0x3FFFU)
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX1_SEL_OUTPUT_SEL_SHIFT (0U)
/*! output_sel - Output mux selection */
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX1_SEL_OUTPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX1_SEL_OUTPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX1_SEL_OUTPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX1_SEL_INPUT_SEL_MASK (0x3FFF0000U)
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX1_SEL_INPUT_SEL_SHIFT (16U)
/*! input_sel - Input mux selection */
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX1_SEL_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX1_SEL_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX1_SEL_INPUT_SEL_MASK)
/*! @} */

/*! @name FLEXIO1_3_MUX2_SEL - FlexIO #1/#3 IO mux #2 selection */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX2_SEL_OUTPUT_SEL_MASK (0xFFFU)
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX2_SEL_OUTPUT_SEL_SHIFT (0U)
/*! output_sel - Output mux selection */
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX2_SEL_OUTPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX2_SEL_OUTPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX2_SEL_OUTPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX2_SEL_INPUT_SEL_MASK (0xFFF0000U)
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX2_SEL_INPUT_SEL_SHIFT (16U)
/*! input_sel - Input mux selection */
#define BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX2_SEL_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX2_SEL_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_FLEXIO1_3_MUX2_SEL_INPUT_SEL_MASK)
/*! @} */

/*! @name FLEXIO2_4_MUX0_SEL - FlexIO #2/#4 IO mux #0 selection */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX0_SEL_OUTPUT_SEL_MASK (0xFFFFU)
#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX0_SEL_OUTPUT_SEL_SHIFT (0U)
/*! output_sel - Output mux selection */
#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX0_SEL_OUTPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX0_SEL_OUTPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX0_SEL_OUTPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX0_SEL_INPUT_SEL_MASK (0xFFFF0000U)
#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX0_SEL_INPUT_SEL_SHIFT (16U)
/*! input_sel - Input mux selection */
#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX0_SEL_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX0_SEL_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX0_SEL_INPUT_SEL_MASK)
/*! @} */

/*! @name FLEXIO2_4_MUX1_SEL - FlexIO #2/#4 IO mux #1 selection */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX1_SEL_OUTPUT_SEL_MASK (0xFFFU)
#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX1_SEL_OUTPUT_SEL_SHIFT (0U)
/*! output_sel - Output mux selection */
#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX1_SEL_OUTPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX1_SEL_OUTPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX1_SEL_OUTPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX1_SEL_INPUT_SEL_MASK (0xFFF0000U)
#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX1_SEL_INPUT_SEL_SHIFT (16U)
/*! input_sel - Input mux selection */
#define BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX1_SEL_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX1_SEL_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_FLEXIO2_4_MUX1_SEL_INPUT_SEL_MASK)
/*! @} */

/*! @name DIAG_ENCODER_MUX_SEL - Encoder diagnostic bus mux selection */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_DIAG_ENCODER_MUX_SEL_DIAG_ENC1_SEL_MASK (0x3U)
#define BLK_CTRL_WAKEUPMIX_DIAG_ENCODER_MUX_SEL_DIAG_ENC1_SEL_SHIFT (0U)
/*! diag_enc1_sel - diag_enc1_sel */
#define BLK_CTRL_WAKEUPMIX_DIAG_ENCODER_MUX_SEL_DIAG_ENC1_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_DIAG_ENCODER_MUX_SEL_DIAG_ENC1_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_DIAG_ENCODER_MUX_SEL_DIAG_ENC1_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_DIAG_ENCODER_MUX_SEL_DIAG_ENC2_SEL_MASK (0x30U)
#define BLK_CTRL_WAKEUPMIX_DIAG_ENCODER_MUX_SEL_DIAG_ENC2_SEL_SHIFT (4U)
/*! diag_enc2_sel - diag_enc2_sel */
#define BLK_CTRL_WAKEUPMIX_DIAG_ENCODER_MUX_SEL_DIAG_ENC2_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_DIAG_ENCODER_MUX_SEL_DIAG_ENC2_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_DIAG_ENCODER_MUX_SEL_DIAG_ENC2_SEL_MASK)
/*! @} */

/*! @name ENCODER_MUX_SEL - Encoder bus mux selection */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL0_MASK (0x3U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL0_SHIFT (0U)
/*! encoder_sel0 - encoder_sel0 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL0_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL0_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL2_MASK (0xCU)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL2_SHIFT (2U)
/*! encoder_sel2 - encoder_sel2 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL2_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL2_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL4_MASK (0x30U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL4_SHIFT (4U)
/*! encoder_sel4 - encoder_sel4 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL4_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL4_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL6_MASK (0xC0U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL6_SHIFT (6U)
/*! encoder_sel6 - encoder_sel6 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL6_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL6_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL8_MASK (0x300U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL8_SHIFT (8U)
/*! encoder_sel8 - encoder_sel8 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL8_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL8_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL10_MASK (0xC00U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL10_SHIFT (10U)
/*! encoder_sel10 - encoder_sel10 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL10_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL10_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL12_MASK (0x3000U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL12_SHIFT (12U)
/*! encoder_sel12 - encoder_sel12 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL12(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL12_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL12_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL14_MASK (0xC000U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL14_SHIFT (14U)
/*! encoder_sel14 - encoder_sel14 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL14(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL14_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL14_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL16_MASK (0x30000U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL16_SHIFT (16U)
/*! encoder_sel16 - encoder_sel16 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL16(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL16_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL16_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL18_MASK (0xC0000U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL18_SHIFT (18U)
/*! encoder_sel18 - encoder_sel18 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL18(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL18_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL18_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL20_MASK (0x300000U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL20_SHIFT (20U)
/*! encoder_sel20 - encoder_sel20 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL20(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL20_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL20_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL22_MASK (0xC00000U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL22_SHIFT (22U)
/*! encoder_sel22 - encoder_sel22 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL22(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL22_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL22_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL24_MASK (0x3000000U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL24_SHIFT (24U)
/*! encoder_sel24 - encoder_sel24 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL24(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL24_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL24_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL26_MASK (0xC000000U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL26_SHIFT (26U)
/*! encoder_sel26 - encoder_sel26 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL26(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL26_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL26_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL28_MASK (0x30000000U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL28_SHIFT (28U)
/*! encoder_sel28 - encoder_sel28 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL28(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL28_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL28_MASK)

#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL30_MASK (0xC0000000U)
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL30_SHIFT (30U)
/*! encoder_sel30 - encoder_sel30 */
#define BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL30(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL30_SHIFT)) & BLK_CTRL_WAKEUPMIX_ENCODER_MUX_SEL_ENCODER_SEL30_MASK)
/*! @} */

/*! @name XBAR_AOI_WE - XBAR and AOI write protect register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_AOI_WE_WE_MASK   (0x1U)
#define BLK_CTRL_WAKEUPMIX_XBAR_AOI_WE_WE_SHIFT  (0U)
/*! WE - Register write enable bit of XBAR and AOI */
#define BLK_CTRL_WAKEUPMIX_XBAR_AOI_WE_WE(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_AOI_WE_WE_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_AOI_WE_WE_MASK)
/*! @} */

/*! @name XBAR_TRIG_SYNC_CTRL1 - XBAR trigger synchronizer control register1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_POL_SEL_MASK (0xFFFFU)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_POL_SEL_SHIFT (0U)
/*! POL_SEL - Trigger out polarity select */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_POL_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_POL_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_POL_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_ASYNC_EN_MASK (0xFFFF0000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_ASYNC_EN_SHIFT (16U)
/*! ASYNC_EN - Asynchronous trigger in enable */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_ASYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_ASYNC_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_ASYNC_EN_MASK)
/*! @} */

/*! @name XBAR_TRIG_SYNC_CTRL2 - XBAR trigger synchronizer control register2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_SYNC_ENABLE_MASK (0xFFFFU)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_SYNC_ENABLE_SHIFT (0U)
/*! SYNC_ENABLE - Trigger out synchronizer enable */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_SYNC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_SYNC_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_SYNC_ENABLE_MASK)
/*! @} */

/*! @name XBAR_TRIG_SYNC_CTRL3 - XBAR trigger synchronizer control register2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH0_MASK (0xFU)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH0_SHIFT (0U)
/*! PULSE_WIDTH0 - Pulse width control register of channel0 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH0_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH0_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH1_MASK (0xF0U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH1_SHIFT (4U)
/*! PULSE_WIDTH1 - Pulse width control register of channel1 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH1_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH1_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH2_MASK (0xF00U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH2_SHIFT (8U)
/*! PULSE_WIDTH2 - Pulse width control register of channel2 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH2_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH2_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH3_MASK (0xF000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH3_SHIFT (12U)
/*! PULSE_WIDTH3 - Pulse width control register of channel3 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH3_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH3_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH4_MASK (0xF0000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH4_SHIFT (16U)
/*! PULSE_WIDTH4 - Pulse width control register of channel4 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH4_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH4_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH5_MASK (0xF00000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH5_SHIFT (20U)
/*! PULSE_WIDTH5 - Pulse width control register of channel5 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH5_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH5_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH6_MASK (0xF000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH6_SHIFT (24U)
/*! PULSE_WIDTH6 - Pulse width control register of channel6 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH6_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH6_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH7_MASK (0xF0000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH7_SHIFT (28U)
/*! PULSE_WIDTH7 - Pulse width control register of channel7 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH7_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL3_PULSE_WIDTH7_MASK)
/*! @} */

/*! @name XBAR_TRIG_SYNC_CTRL4 - XBAR trigger synchronizer control register2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH8_MASK (0xFU)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH8_SHIFT (0U)
/*! PULSE_WIDTH8 - Pulse width control register of channel8 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH8_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH8_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH9_MASK (0xF0U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH9_SHIFT (4U)
/*! PULSE_WIDTH9 - Pulse width control register of channel9 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH9_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH9_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH10_MASK (0xF00U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH10_SHIFT (8U)
/*! PULSE_WIDTH10 - Pulse width control register of channel10 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH10_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH10_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH11_MASK (0xF000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH11_SHIFT (12U)
/*! PULSE_WIDTH11 - Pulse width control register of channel11 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH11_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH11_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH12_MASK (0xF0000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH12_SHIFT (16U)
/*! PULSE_WIDTH12 - Pulse width control register of channel12 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH12(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH12_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH12_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH13_MASK (0xF00000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH13_SHIFT (20U)
/*! PULSE_WIDTH13 - Pulse width control register of channel13 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH13(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH13_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH13_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH14_MASK (0xF000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH14_SHIFT (24U)
/*! PULSE_WIDTH14 - Pulse width control register of channel14 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH14(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH14_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH14_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH15_MASK (0xF0000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH15_SHIFT (28U)
/*! PULSE_WIDTH15 - Pulse width control register of channel15 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH15(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH15_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL4_PULSE_WIDTH15_MASK)
/*! @} */

/*! @name QTIMER_CTRL1 - Qtimer miscellaneous control register 1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR_CNTS_FREEZE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR_CNTS_FREEZE_SHIFT (0U)
/*! QTIMER1_TMR_CNTS_FREEZE - QTIMER1 timer counter freeze */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR0_INPUT_SEL_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR0_INPUT_SEL_SHIFT (1U)
/*! QTIMER1_TMR0_INPUT_SEL - QTIMER1 TMR0 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR1_INPUT_SEL_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR1_INPUT_SEL_SHIFT (2U)
/*! QTIMER1_TMR1_INPUT_SEL - QTIMER1 TMR1 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR2_INPUT_SEL_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR2_INPUT_SEL_SHIFT (3U)
/*! QTIMER1_TMR2_INPUT_SEL - QTIMER1 TMR2 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR3_INPUT_SEL_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR3_INPUT_SEL_SHIFT (4U)
/*! QTIMER1_TMR3_INPUT_SEL - QTIMER1 TMR3 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR_CNTS_FREEZE_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR_CNTS_FREEZE_SHIFT (8U)
/*! QTIMER2_TMR_CNTS_FREEZE - QTIMER2 timer counter freeze */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR0_INPUT_SEL_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR0_INPUT_SEL_SHIFT (9U)
/*! QTIMER2_TMR0_INPUT_SEL - QTIMER2 TMR0 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR1_INPUT_SEL_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR1_INPUT_SEL_SHIFT (10U)
/*! QTIMER2_TMR1_INPUT_SEL - QTIMER2 TMR1 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR2_INPUT_SEL_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR2_INPUT_SEL_SHIFT (11U)
/*! QTIMER2_TMR2_INPUT_SEL - QTIMER2 TMR2 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR3_INPUT_SEL_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR3_INPUT_SEL_SHIFT (12U)
/*! QTIMER2_TMR3_INPUT_SEL - QTIMER2 TMR3 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR_CNTS_FREEZE_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR_CNTS_FREEZE_SHIFT (16U)
/*! QTIMER3_TMR_CNTS_FREEZE - QTIMER3 timer counter freeze */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR0_INPUT_SEL_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR0_INPUT_SEL_SHIFT (17U)
/*! QTIMER3_TMR0_INPUT_SEL - QTIMER3 TMR0 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR1_INPUT_SEL_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR1_INPUT_SEL_SHIFT (18U)
/*! QTIMER3_TMR1_INPUT_SEL - QTIMER3 TMR1 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR2_INPUT_SEL_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR2_INPUT_SEL_SHIFT (19U)
/*! QTIMER3_TMR2_INPUT_SEL - QTIMER3 TMR2 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR3_INPUT_SEL_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR3_INPUT_SEL_SHIFT (20U)
/*! QTIMER3_TMR3_INPUT_SEL - QTIMER3 TMR3 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR_CNTS_FREEZE_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR_CNTS_FREEZE_SHIFT (24U)
/*! QTIMER4_TMR_CNTS_FREEZE - QTIMER4 timer counter freeze */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR0_INPUT_SEL_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR0_INPUT_SEL_SHIFT (25U)
/*! QTIMER4_TMR0_INPUT_SEL - QTIMER4 TMR0 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR1_INPUT_SEL_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR1_INPUT_SEL_SHIFT (26U)
/*! QTIMER4_TMR1_INPUT_SEL - QTIMER4 TMR1 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR2_INPUT_SEL_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR2_INPUT_SEL_SHIFT (27U)
/*! QTIMER4_TMR2_INPUT_SEL - QTIMER4 TMR2 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR3_INPUT_SEL_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR3_INPUT_SEL_SHIFT (28U)
/*! QTIMER4_TMR3_INPUT_SEL - QTIMER4 TMR3 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR3_INPUT_SEL_MASK)
/*! @} */

/*! @name QTIMER_CTRL2 - Qtimer miscellaneous control register 2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR_CNTS_FREEZE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR_CNTS_FREEZE_SHIFT (0U)
/*! QTIMER5_TMR_CNTS_FREEZE - QTIMER5 timer counter freeze */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR0_INPUT_SEL_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR0_INPUT_SEL_SHIFT (1U)
/*! QTIMER5_TMR0_INPUT_SEL - QTIMER5 TMR0 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR1_INPUT_SEL_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR1_INPUT_SEL_SHIFT (2U)
/*! QTIMER5_TMR1_INPUT_SEL - QTIMER5 TMR1 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR2_INPUT_SEL_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR2_INPUT_SEL_SHIFT (3U)
/*! QTIMER5_TMR2_INPUT_SEL - QTIMER5 TMR2 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR3_INPUT_SEL_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR3_INPUT_SEL_SHIFT (4U)
/*! QTIMER5_TMR3_INPUT_SEL - QTIMER5 TMR3 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR_CNTS_FREEZE_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR_CNTS_FREEZE_SHIFT (8U)
/*! QTIMER6_TMR_CNTS_FREEZE - QTIMER6 timer counter freeze */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR0_INPUT_SEL_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR0_INPUT_SEL_SHIFT (9U)
/*! QTIMER6_TMR0_INPUT_SEL - QTIMER6 TMR0 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR1_INPUT_SEL_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR1_INPUT_SEL_SHIFT (10U)
/*! QTIMER6_TMR1_INPUT_SEL - QTIMER6 TMR1 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR2_INPUT_SEL_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR2_INPUT_SEL_SHIFT (11U)
/*! QTIMER6_TMR2_INPUT_SEL - QTIMER6 TMR2 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR3_INPUT_SEL_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR3_INPUT_SEL_SHIFT (12U)
/*! QTIMER6_TMR3_INPUT_SEL - QTIMER6 TMR3 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR_CNTS_FREEZE_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR_CNTS_FREEZE_SHIFT (16U)
/*! QTIMER7_TMR_CNTS_FREEZE - QTIMER7 timer counter freeze */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR0_INPUT_SEL_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR0_INPUT_SEL_SHIFT (17U)
/*! QTIMER7_TMR0_INPUT_SEL - QTIMER7 TMR0 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR1_INPUT_SEL_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR1_INPUT_SEL_SHIFT (18U)
/*! QTIMER7_TMR1_INPUT_SEL - QTIMER7 TMR1 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR2_INPUT_SEL_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR2_INPUT_SEL_SHIFT (19U)
/*! QTIMER7_TMR2_INPUT_SEL - QTIMER7 TMR2 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR3_INPUT_SEL_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR3_INPUT_SEL_SHIFT (20U)
/*! QTIMER7_TMR3_INPUT_SEL - QTIMER7 TMR3 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR_CNTS_FREEZE_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR_CNTS_FREEZE_SHIFT (24U)
/*! QTIMER8_TMR_CNTS_FREEZE - QTIMER8 timer counter freeze */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR0_INPUT_SEL_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR0_INPUT_SEL_SHIFT (25U)
/*! QTIMER8_TMR0_INPUT_SEL - QTIMER8 TMR0 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR1_INPUT_SEL_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR1_INPUT_SEL_SHIFT (26U)
/*! QTIMER8_TMR1_INPUT_SEL - QTIMER8 TMR1 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR2_INPUT_SEL_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR2_INPUT_SEL_SHIFT (27U)
/*! QTIMER8_TMR2_INPUT_SEL - QTIMER8 TMR2 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR3_INPUT_SEL_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR3_INPUT_SEL_SHIFT (28U)
/*! QTIMER8_TMR3_INPUT_SEL - QTIMER8 TMR3 input select */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR3_INPUT_SEL_MASK)
/*! @} */

/*! @name XBAR_DIR_CTRL1 - XBAR IO direction control register #1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_4_SHIFT (4U)
/*! IOMUXC_XBAR_DIR_SEL_4 - IOMUXC XBAR_INOUT4 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_4_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_4_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_5_SHIFT (5U)
/*! IOMUXC_XBAR_DIR_SEL_5 - IOMUXC XBAR_INOUT5 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_5_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_5_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_6_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_6_SHIFT (6U)
/*! IOMUXC_XBAR_DIR_SEL_6 - IOMUXC XBAR_INOUT6 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_6_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_6_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_7_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_7_SHIFT (7U)
/*! IOMUXC_XBAR_DIR_SEL_7 - IOMUXC XBAR_INOUT7 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_7_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_7_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_8_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_8_SHIFT (8U)
/*! IOMUXC_XBAR_DIR_SEL_8 - IOMUXC XBAR_INOUT8 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_8_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_8_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_9_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_9_SHIFT (9U)
/*! IOMUXC_XBAR_DIR_SEL_9 - IOMUXC XBAR_INOUT9 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_9_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_9_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_10_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_10_SHIFT (10U)
/*! IOMUXC_XBAR_DIR_SEL_10 - IOMUXC XBAR_INOUT10 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_10_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_10_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_11_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_11_SHIFT (11U)
/*! IOMUXC_XBAR_DIR_SEL_11 - IOMUXC XBAR_INOUT11 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_11_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_11_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_12_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_12_SHIFT (12U)
/*! IOMUXC_XBAR_DIR_SEL_12 - IOMUXC XBAR_INOUT12 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_12(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_12_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_12_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_13_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_13_SHIFT (13U)
/*! IOMUXC_XBAR_DIR_SEL_13 - IOMUXC XBAR_INOUT13 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_13(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_13_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_13_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_14_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_14_SHIFT (14U)
/*! IOMUXC_XBAR_DIR_SEL_14 - IOMUXC XBAR_INOUT14 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_14(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_14_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_14_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_15_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_15_SHIFT (15U)
/*! IOMUXC_XBAR_DIR_SEL_15 - IOMUXC XBAR_INOUT15 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_15(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_15_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_15_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_16_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_16_SHIFT (16U)
/*! IOMUXC_XBAR_DIR_SEL_16 - IOMUXC XBAR_INOUT16 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_16(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_16_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_16_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_17_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_17_SHIFT (17U)
/*! IOMUXC_XBAR_DIR_SEL_17 - IOMUXC XBAR_INOUT17 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_17(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_17_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_17_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_18_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_18_SHIFT (18U)
/*! IOMUXC_XBAR_DIR_SEL_18 - IOMUXC XBAR_INOUT18 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_18(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_18_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_18_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_19_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_19_SHIFT (19U)
/*! IOMUXC_XBAR_DIR_SEL_19 - IOMUXC XBAR_INOUT19 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_19(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_19_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_19_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_20_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_20_SHIFT (20U)
/*! IOMUXC_XBAR_DIR_SEL_20 - IOMUXC XBAR_INOUT20 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_20(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_20_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_20_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_21_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_21_SHIFT (21U)
/*! IOMUXC_XBAR_DIR_SEL_21 - IOMUXC XBAR_INOUT21 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_21(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_21_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_21_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_22_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_22_SHIFT (22U)
/*! IOMUXC_XBAR_DIR_SEL_22 - IOMUXC XBAR_INOUT22 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_22(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_22_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_22_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_23_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_23_SHIFT (23U)
/*! IOMUXC_XBAR_DIR_SEL_23 - IOMUXC XBAR_INOUT23 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_23(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_23_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_23_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_24_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_24_SHIFT (24U)
/*! IOMUXC_XBAR_DIR_SEL_24 - IOMUXC XBAR_INOUT24 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_24(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_24_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_24_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_25_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_25_SHIFT (25U)
/*! IOMUXC_XBAR_DIR_SEL_25 - IOMUXC XBAR_INOUT25 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_25(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_25_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_25_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_26_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_26_SHIFT (26U)
/*! IOMUXC_XBAR_DIR_SEL_26 - IOMUXC XBAR_INOUT26 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_26(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_26_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_26_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_27_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_27_SHIFT (27U)
/*! IOMUXC_XBAR_DIR_SEL_27 - IOMUXC XBAR_INOUT27 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_27(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_27_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_27_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_28_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_28_SHIFT (28U)
/*! IOMUXC_XBAR_DIR_SEL_28 - IOMUXC XBAR_INOUT28 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_28(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_28_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_28_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_29_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_29_SHIFT (29U)
/*! IOMUXC_XBAR_DIR_SEL_29 - IOMUXC XBAR_INOUT29 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_29(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_29_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_29_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_30_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_30_SHIFT (30U)
/*! IOMUXC_XBAR_DIR_SEL_30 - IOMUXC XBAR_INOUT30 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_30(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_30_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_30_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_31_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_31_SHIFT (31U)
/*! IOMUXC_XBAR_DIR_SEL_31 - IOMUXC XBAR_INOUT31 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_31(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_31_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_31_MASK)
/*! @} */

/*! @name XBAR_DIR_CTRL2 - XBAR IO direction control register #2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_32_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_32_SHIFT (0U)
/*! IOMUXC_XBAR_DIR_SEL_32 - IOMUXC XBAR_INOUT32 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_32(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_32_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_32_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_33_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_33_SHIFT (1U)
/*! IOMUXC_XBAR_DIR_SEL_33 - IOMUXC XBAR_INOUT33 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_33(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_33_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_33_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_34_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_34_SHIFT (2U)
/*! IOMUXC_XBAR_DIR_SEL_34 - IOMUXC XBAR_INOUT34 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_34(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_34_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_34_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_35_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_35_SHIFT (3U)
/*! IOMUXC_XBAR_DIR_SEL_35 - IOMUXC XBAR_INOUT35 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_35(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_35_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_35_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_36_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_36_SHIFT (4U)
/*! IOMUXC_XBAR_DIR_SEL_36 - IOMUXC XBAR_INOUT36 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_36(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_36_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_36_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_37_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_37_SHIFT (5U)
/*! IOMUXC_XBAR_DIR_SEL_37 - IOMUXC XBAR_INOUT37 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_37(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_37_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_37_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_38_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_38_SHIFT (6U)
/*! IOMUXC_XBAR_DIR_SEL_38 - IOMUXC XBAR_INOUT38 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_38(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_38_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_38_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_39_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_39_SHIFT (7U)
/*! IOMUXC_XBAR_DIR_SEL_39 - IOMUXC XBAR_INOUT39 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_39(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_39_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_39_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_40_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_40_SHIFT (8U)
/*! IOMUXC_XBAR_DIR_SEL_40 - IOMUXC XBAR_INOUT40 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_40(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_40_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_40_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_41_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_41_SHIFT (9U)
/*! IOMUXC_XBAR_DIR_SEL_41 - IOMUXC XBAR_INOUT41 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_41(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_41_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_41_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_42_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_42_SHIFT (10U)
/*! IOMUXC_XBAR_DIR_SEL_42 - IOMUXC XBAR_INOUT42 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_42(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_42_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_42_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_43_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_43_SHIFT (11U)
/*! IOMUXC_XBAR_DIR_SEL_43 - IOMUXC XBAR_INOUT43 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_43(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_43_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_43_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_44_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_44_SHIFT (12U)
/*! IOMUXC_XBAR_DIR_SEL_44 - IOMUXC XBAR_INOUT44 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_44(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_44_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_44_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_45_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_45_SHIFT (13U)
/*! IOMUXC_XBAR_DIR_SEL_45 - IOMUXC XBAR_INOUT45 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_45(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_45_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_45_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_46_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_46_SHIFT (14U)
/*! IOMUXC_XBAR_DIR_SEL_46 - IOMUXC XBAR_INOUT46 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_46(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_46_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_46_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_47_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_47_SHIFT (15U)
/*! IOMUXC_XBAR_DIR_SEL_47 - IOMUXC XBAR_INOUT47 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_47(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_47_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_47_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_48_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_48_SHIFT (16U)
/*! IOMUXC_XBAR_DIR_SEL_48 - IOMUXC XBAR_INOUT48 function direction select */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_48(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_48_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_48_MASK)
/*! @} */

/*! @name LPIT_TRIG_SEL - LPIT trigger input select register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG0_INPUT_SEL_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG0_INPUT_SEL_SHIFT (0U)
/*! LPIT1_TRIG0_INPUT_SEL - LPIT1 TRIG0 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG1_INPUT_SEL_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG1_INPUT_SEL_SHIFT (1U)
/*! LPIT1_TRIG1_INPUT_SEL - LPIT1 TRIG1 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG2_INPUT_SEL_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG2_INPUT_SEL_SHIFT (2U)
/*! LPIT1_TRIG2_INPUT_SEL - LPIT1 TRIG2 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG3_INPUT_SEL_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG3_INPUT_SEL_SHIFT (3U)
/*! LPIT1_TRIG3_INPUT_SEL - LPIT1 TRIG3 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG0_INPUT_SEL_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG0_INPUT_SEL_SHIFT (8U)
/*! LPIT2_TRIG0_INPUT_SEL - LPIT2 TRIG0 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG1_INPUT_SEL_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG1_INPUT_SEL_SHIFT (9U)
/*! LPIT2_TRIG1_INPUT_SEL - LPIT2 TRIG1 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG2_INPUT_SEL_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG2_INPUT_SEL_SHIFT (10U)
/*! LPIT2_TRIG2_INPUT_SEL - LPIT2 TRIG2 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG3_INPUT_SEL_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG3_INPUT_SEL_SHIFT (11U)
/*! LPIT2_TRIG3_INPUT_SEL - LPIT2 TRIG3 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG0_INPUT_SEL_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG0_INPUT_SEL_SHIFT (16U)
/*! LPIT3_TRIG0_INPUT_SEL - LPIT3 TRIG0 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG1_INPUT_SEL_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG1_INPUT_SEL_SHIFT (17U)
/*! LPIT3_TRIG1_INPUT_SEL - LPIT3 TRIG1 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG2_INPUT_SEL_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG2_INPUT_SEL_SHIFT (18U)
/*! LPIT3_TRIG2_INPUT_SEL - LPIT3 TRIG2 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG3_INPUT_SEL_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG3_INPUT_SEL_SHIFT (19U)
/*! LPIT3_TRIG3_INPUT_SEL - LPIT3 TRIG3 input select */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG3_INPUT_SEL_MASK)
/*! @} */

/*! @name BISS1_EOT_CTL - BISS #1 EOT interrupt ctrl register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_CTL_BISS_EOT_RISE_INT_B_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_CTL_BISS_EOT_RISE_INT_B_SHIFT (0U)
/*! biss_eot_rise_int_b - biss_eot_rise_int_b interrupt signal from BISS */
#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_CTL_BISS_EOT_RISE_INT_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_BISS1_EOT_CTL_BISS_EOT_RISE_INT_B_SHIFT)) & BLK_CTRL_WAKEUPMIX_BISS1_EOT_CTL_BISS_EOT_RISE_INT_B_MASK)

#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_CTL_BISS_EOT_FALL_INT_B_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_CTL_BISS_EOT_FALL_INT_B_SHIFT (1U)
/*! biss_eot_fall_int_b - biss_eot_fall_int_b interrupt signal from BISS */
#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_CTL_BISS_EOT_FALL_INT_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_BISS1_EOT_CTL_BISS_EOT_FALL_INT_B_SHIFT)) & BLK_CTRL_WAKEUPMIX_BISS1_EOT_CTL_BISS_EOT_FALL_INT_B_MASK)
/*! @} */

/*! @name BISS1_EOT_STATUS - BISS #1 EOT interrupt status register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_STATUS_BISS_EOT_RISE_INT_B_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_STATUS_BISS_EOT_RISE_INT_B_SHIFT (0U)
/*! biss_eot_rise_int_b - biss_eot_rise_int_b interrupt signal from BISS */
#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_STATUS_BISS_EOT_RISE_INT_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_BISS1_EOT_STATUS_BISS_EOT_RISE_INT_B_SHIFT)) & BLK_CTRL_WAKEUPMIX_BISS1_EOT_STATUS_BISS_EOT_RISE_INT_B_MASK)

#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_STATUS_BISS_EOT_FALL_INT_B_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_STATUS_BISS_EOT_FALL_INT_B_SHIFT (1U)
/*! biss_eot_fall_int_b - biss_eot_fall_int_b interrupt signal from BISS */
#define BLK_CTRL_WAKEUPMIX_BISS1_EOT_STATUS_BISS_EOT_FALL_INT_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_BISS1_EOT_STATUS_BISS_EOT_FALL_INT_B_SHIFT)) & BLK_CTRL_WAKEUPMIX_BISS1_EOT_STATUS_BISS_EOT_FALL_INT_B_MASK)
/*! @} */

/*! @name IOMUX_GPIO_CTRL_0 - IOMUX GPIO selection / override control register #0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL0_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL0_SHIFT (0U)
/*! sel0 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR0_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR0_SHIFT (3U)
/*! ovr0 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL1_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL1_SHIFT (4U)
/*! sel1 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR1_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR1_SHIFT (7U)
/*! ovr1 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL2_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL2_SHIFT (8U)
/*! sel2 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR2_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR2_SHIFT (11U)
/*! ovr2 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL3_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL3_SHIFT (12U)
/*! sel3 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR3_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR3_SHIFT (15U)
/*! ovr3 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL4_MASK (0x70000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL4_SHIFT (16U)
/*! sel4 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR4_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR4_SHIFT (19U)
/*! ovr4 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL5_MASK (0x700000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL5_SHIFT (20U)
/*! sel5 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR5_SHIFT (23U)
/*! ovr5 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL6_MASK (0x7000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL6_SHIFT (24U)
/*! sel6 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR6_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR6_SHIFT (27U)
/*! ovr6 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL7_MASK (0x70000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL7_SHIFT (28U)
/*! sel7 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_SEL7_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR7_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR7_SHIFT (31U)
/*! ovr7 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_0_OVR7_MASK)
/*! @} */

/*! @name IOMUX_GPIO_CTRL_1 - IOMUX GPIO selection / override control register #1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL0_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL0_SHIFT (0U)
/*! sel0 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR0_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR0_SHIFT (3U)
/*! ovr0 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL1_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL1_SHIFT (4U)
/*! sel1 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR1_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR1_SHIFT (7U)
/*! ovr1 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL2_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL2_SHIFT (8U)
/*! sel2 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR2_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR2_SHIFT (11U)
/*! ovr2 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL3_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL3_SHIFT (12U)
/*! sel3 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR3_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR3_SHIFT (15U)
/*! ovr3 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL4_MASK (0x70000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL4_SHIFT (16U)
/*! sel4 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR4_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR4_SHIFT (19U)
/*! ovr4 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL5_MASK (0x700000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL5_SHIFT (20U)
/*! sel5 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR5_SHIFT (23U)
/*! ovr5 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL6_MASK (0x7000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL6_SHIFT (24U)
/*! sel6 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR6_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR6_SHIFT (27U)
/*! ovr6 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL7_MASK (0x70000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL7_SHIFT (28U)
/*! sel7 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_SEL7_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR7_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR7_SHIFT (31U)
/*! ovr7 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_1_OVR7_MASK)
/*! @} */

/*! @name IOMUX_GPIO_CTRL_2 - IOMUX GPIO selection / override control register #2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL0_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL0_SHIFT (0U)
/*! sel0 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR0_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR0_SHIFT (3U)
/*! ovr0 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL1_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL1_SHIFT (4U)
/*! sel1 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR1_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR1_SHIFT (7U)
/*! ovr1 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL2_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL2_SHIFT (8U)
/*! sel2 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR2_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR2_SHIFT (11U)
/*! ovr2 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL3_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL3_SHIFT (12U)
/*! sel3 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR3_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR3_SHIFT (15U)
/*! ovr3 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL4_MASK (0x70000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL4_SHIFT (16U)
/*! sel4 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR4_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR4_SHIFT (19U)
/*! ovr4 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL5_MASK (0x700000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL5_SHIFT (20U)
/*! sel5 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR5_SHIFT (23U)
/*! ovr5 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL6_MASK (0x7000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL6_SHIFT (24U)
/*! sel6 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR6_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR6_SHIFT (27U)
/*! ovr6 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL7_MASK (0x70000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL7_SHIFT (28U)
/*! sel7 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_SEL7_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR7_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR7_SHIFT (31U)
/*! ovr7 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_2_OVR7_MASK)
/*! @} */

/*! @name IOMUX_GPIO_CTRL_3 - IOMUX GPIO selection / override control register #3 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL0_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL0_SHIFT (0U)
/*! sel0 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR0_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR0_SHIFT (3U)
/*! ovr0 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL1_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL1_SHIFT (4U)
/*! sel1 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR1_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR1_SHIFT (7U)
/*! ovr1 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL2_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL2_SHIFT (8U)
/*! sel2 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR2_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR2_SHIFT (11U)
/*! ovr2 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL3_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL3_SHIFT (12U)
/*! sel3 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR3_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR3_SHIFT (15U)
/*! ovr3 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL4_MASK (0x70000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL4_SHIFT (16U)
/*! sel4 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR4_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR4_SHIFT (19U)
/*! ovr4 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL5_MASK (0x700000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL5_SHIFT (20U)
/*! sel5 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR5_SHIFT (23U)
/*! ovr5 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL6_MASK (0x7000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL6_SHIFT (24U)
/*! sel6 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR6_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR6_SHIFT (27U)
/*! ovr6 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL7_MASK (0x70000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL7_SHIFT (28U)
/*! sel7 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_SEL7_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR7_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR7_SHIFT (31U)
/*! ovr7 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_3_OVR7_MASK)
/*! @} */

/*! @name IOMUX_GPIO_CTRL_4 - IOMUX GPIO selection / override control register #4 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL0_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL0_SHIFT (0U)
/*! sel0 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR0_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR0_SHIFT (3U)
/*! ovr0 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL1_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL1_SHIFT (4U)
/*! sel1 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR1_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR1_SHIFT (7U)
/*! ovr1 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL2_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL2_SHIFT (8U)
/*! sel2 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR2_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR2_SHIFT (11U)
/*! ovr2 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL3_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL3_SHIFT (12U)
/*! sel3 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR3_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR3_SHIFT (15U)
/*! ovr3 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL4_MASK (0x70000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL4_SHIFT (16U)
/*! sel4 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR4_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR4_SHIFT (19U)
/*! ovr4 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL5_MASK (0x700000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL5_SHIFT (20U)
/*! sel5 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR5_SHIFT (23U)
/*! ovr5 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL6_MASK (0x7000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL6_SHIFT (24U)
/*! sel6 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR6_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR6_SHIFT (27U)
/*! ovr6 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL7_MASK (0x70000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL7_SHIFT (28U)
/*! sel7 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_SEL7_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR7_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR7_SHIFT (31U)
/*! ovr7 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_4_OVR7_MASK)
/*! @} */

/*! @name IOMUX_GPIO_CTRL_5 - IOMUX GPIO selection / override control register #5 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL0_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL0_SHIFT (0U)
/*! sel0 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR0_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR0_SHIFT (3U)
/*! ovr0 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR0_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR0_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL1_MASK (0x70U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL1_SHIFT (4U)
/*! sel1 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR1_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR1_SHIFT (7U)
/*! ovr1 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR1_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL2_MASK (0x700U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL2_SHIFT (8U)
/*! sel2 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR2_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR2_SHIFT (11U)
/*! ovr2 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL3_MASK (0x7000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL3_SHIFT (12U)
/*! sel3 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR3_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR3_SHIFT (15U)
/*! ovr3 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR3_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL4_MASK (0x70000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL4_SHIFT (16U)
/*! sel4 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR4_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR4_SHIFT (19U)
/*! ovr4 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR4_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL5_MASK (0x700000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL5_SHIFT (20U)
/*! sel5 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR5_SHIFT (23U)
/*! ovr5 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR5_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL6_MASK (0x7000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL6_SHIFT (24U)
/*! sel6 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR6_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR6_SHIFT (27U)
/*! ovr6 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR6_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL7_MASK (0x70000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL7_SHIFT (28U)
/*! sel7 - GPIO IOMUX selection */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_SEL7_MASK)

#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR7_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR7_SHIFT (31U)
/*! ovr7 - GPIO IOMUX selection override */
#define BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IOMUX_GPIO_CTRL_5_OVR7_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_WAKEUPMIX_Register_Masks */


/* BLK_CTRL_WAKEUPMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_WAKEUPMIX base address */
#define BLK_CTRL_WAKEUPMIX_BASE          (0x42420000u)
/** Peripheral BLK_CTRL_WAKEUPMIX base pointer */
#define BLK_CTRL_WAKEUPMIX               ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX_BASE)
/** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
#define BLK_CTRL_WAKEUPMIX_BASE_ADDRS            { BLK_CTRL_WAKEUPMIX_BASE }
/** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
#define BLK_CTRL_WAKEUPMIX_BASE_PTRS             { BLK_CTRL_WAKEUPMIX }

/*!
 * @}
 */ /* end of group BLK_CTRL_WAKEUPMIX_Peripheral_Access_Layer */

#endif  /* #if !defined(mx94_BLK_CTRL_WAKEUPMIX_H_) */
