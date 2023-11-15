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
 * @file MIMX95_BLK_CTRL_NS_AONMIX.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for MIMX95_BLK_CTRL_NS_AONMIX
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_BLK_CTRL_NS_AONMIX_H_)  /* Check if memory map has not been already included */
#define MIMX95_BLK_CTRL_NS_AONMIX_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_NS_AONMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NS_AONMIX_Peripheral_Access_Layer BLK_CTRL_NS_AONMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_NS_AONMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t GPC_CFG;                           /**< GPC CORE SLEEP Request Select, offset: 0x0 */
  __IO uint32_t UPPER_ADDR;                        /**< UPPER ADDR BITS[35:32], offset: 0x4 */
  __IO uint32_t IPG_DEBUG_CM33;                    /**< IPG DEBUG MASK BIT for cm33, offset: 0x8 */
  __IO uint32_t IPG_DEBUG_CA55C0;                  /**< IPG DEBUG MASK BIT CA55 CORE0, offset: 0xC */
  __IO uint32_t IPG_DEBUG_CA55C1;                  /**< IPG DEBUG MASK BIT CA55 CORE1, offset: 0x10 */
  __IO uint32_t IPG_DEBUG_CA55C2;                  /**< IPG DEBUG MASK BIT CA55 CORE2, offset: 0x14 */
  __IO uint32_t IPG_DEBUG_CA55C3;                  /**< IPG DEBUG MASK BIT CA55 CORE3, offset: 0x18 */
  __IO uint32_t IPG_DEBUG_CA55C4;                  /**< IPG DEBUG MASK BIT CA55 CORE4, offset: 0x1C */
  __IO uint32_t IPG_DEBUG_CA55C5;                  /**< IPG DEBUG MASK BIT CA55 CORE5, offset: 0x20 */
  __IO uint32_t IPG_DEBUG_CM7;                     /**< IPG DEBUG MASK BIT for cm7, offset: 0x24 */
  __I  uint32_t FUSE_ACC_DIS;                      /**< Read-only version of the OCOTP fuse-access-disable bit, offset: 0x28 */
       uint8_t RESERVED_0[4];
  __I  uint32_t OCOTP_FUSE_DATA0;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_0, offset: 0x30 */
  __I  uint32_t OCOTP_FUSE_DATA1;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_1, offset: 0x34 */
  __I  uint32_t OCOTP_FUSE_DATA2;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_2, offset: 0x38 */
  __I  uint32_t OCOTP_FUSE_DATA3;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_3, offset: 0x3C */
  __I  uint32_t OCOTP_FUSE_DATA4;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_4, offset: 0x40 */
  __I  uint32_t OCOTP_FUSE_DATA5;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_5, offset: 0x44 */
  __I  uint32_t OCOTP_FUSE_DATA6;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_6, offset: 0x48 */
  __I  uint32_t OCOTP_FUSE_DATA7;                  /**< Read-only version of OCOTP fusedata_mtr_cfg_7, offset: 0x4C */
  __I  uint32_t OCOTP_FUSE_DATA8;                  /**< Read-only version of OCOTP fusedata_mem_trim_cfg0, offset: 0x50 */
  __I  uint32_t OCOTP_FUSE_DATA9;                  /**< Read-only version of OCOTP fusedata_mem_trim_cfg1, offset: 0x54 */
  __I  uint32_t OCOTP_FUSE_DATA10;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg2, offset: 0x58 */
  __I  uint32_t OCOTP_FUSE_DATA11;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg3, offset: 0x5C */
  __I  uint32_t OCOTP_FUSE_DATA12;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg4, offset: 0x60 */
  __I  uint32_t OCOTP_FUSE_DATA13;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg5, offset: 0x64 */
  __I  uint32_t OCOTP_FUSE_DATA14;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg6, offset: 0x68 */
  __I  uint32_t OCOTP_FUSE_DATA15;                 /**< Read-only version of OCOTP fusedata_mem_trim_cfg7, offset: 0x6C */
  __IO uint32_t I3C1_WAKEUP;                       /**< I3C1 WAKEUPX CLR, offset: 0x70 */
  __I  uint32_t OCOTP_STATUS;                      /**< OCOTP status register, offset: 0x74 */
  __IO uint32_t PDM_CLK_SEL;                       /**< PDM clock selection register, offset: 0x78 */
  __IO uint32_t I3C1_SDA_IRQ;                      /**< I3C1 SDA IRQ, offset: 0x7C */
  __IO uint32_t SSI;                               /**< SSI master low power mode control, offset: 0x80 */
  __I  uint32_t FASTBOOT_ENABLE;                   /**< fastboot enable, offset: 0x84 */
  __IO uint32_t MQS_SETTINGS;                      /**< MQS settings, offset: 0x88 */
  __I  uint32_t SENTINEL_FW_PRESENT;               /**< Read only bit for fuse SENTINEL_FW_PRESENT, offset: 0x8C */
  __I  uint32_t AOMIX_SPARE_FUSE;                  /**< Spare fuse register, offset: 0x90 */
  __IO uint32_t IPG_STOP_CTL;                      /**< IPG_STOP Control Register, offset: 0x94 */
  __I  uint32_t IPG_STOP_ACK_STATUS;               /**< IPG_STOP_ACK Status Register, offset: 0x98 */
  __IO uint32_t IPG_DOZE_CTL;                      /**< IPG_DOZE_CTL Control Register, offset: 0x9C */
  __IO uint32_t QREQ_N;                            /**< QREQ_N Control Register, offset: 0xA0 */
  __IO uint32_t SAI_MCLK;                          /**< SAI1 MCLK Control Register, offset: 0xA4 */
  __I  uint32_t QACTIVE;                           /**< QACTIVE Status Register, offset: 0xA8 */
  __I  uint32_t QDENY;                             /**< QDENY Status Register, offset: 0xAC */
  __I  uint32_t QACCEPT_N;                         /**< QACCEPT_N Status Register, offset: 0xB0 */
} BLK_CTRL_NS_AONMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_NS_AONMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NS_AONMIX_Register_Masks BLK_CTRL_NS_AONMIX Register Masks
 * @{
 */

/*! @name GPC_CFG - GPC CORE SLEEP Request Select */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_SHIFT (0U)
/*! M33_SLEEP_SEL - M33 SLEEP Request Select
 *  0b0..Select SLEEPING as request source
 *  0b1..Select SLEEPDEEP as request source
 */
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_SHIFT)) & BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_MASK)

#define BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_SHIFT (1U)
/*! M7_SLEEP_SEL - M7 SLEEP Request Select
 *  0b1..Select SLEEPDEEP as request source
 *  0b0..Select SLEEPING as request source
 */
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_SHIFT)) & BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_MASK)
/*! @} */

/*! @name UPPER_ADDR - UPPER ADDR BITS[35:32] */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_UPPER_ADDR_SENTINEL_MASK (0xFU)
#define BLK_CTRL_NS_AONMIX_UPPER_ADDR_SENTINEL_SHIFT (0U)
/*! sentinel - address bit [35:32] for sentinel */
#define BLK_CTRL_NS_AONMIX_UPPER_ADDR_SENTINEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_UPPER_ADDR_SENTINEL_SHIFT)) & BLK_CTRL_NS_AONMIX_UPPER_ADDR_SENTINEL_MASK)

#define BLK_CTRL_NS_AONMIX_UPPER_ADDR_EDMA1_MASK (0xF0U)
#define BLK_CTRL_NS_AONMIX_UPPER_ADDR_EDMA1_SHIFT (4U)
/*! edma1 - address bit [35:32] for edma1 */
#define BLK_CTRL_NS_AONMIX_UPPER_ADDR_EDMA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_UPPER_ADDR_EDMA1_SHIFT)) & BLK_CTRL_NS_AONMIX_UPPER_ADDR_EDMA1_MASK)

#define BLK_CTRL_NS_AONMIX_UPPER_ADDR_MTR_MASTER_MASK (0xF00U)
#define BLK_CTRL_NS_AONMIX_UPPER_ADDR_MTR_MASTER_SHIFT (8U)
/*! mtr_master - address bit [35:32] for mtr_master */
#define BLK_CTRL_NS_AONMIX_UPPER_ADDR_MTR_MASTER(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_UPPER_ADDR_MTR_MASTER_SHIFT)) & BLK_CTRL_NS_AONMIX_UPPER_ADDR_MTR_MASTER_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM33 - IPG DEBUG MASK BIT for cm33 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_CAN1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_CAN1_SHIFT (0U)
/*! can1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_CAN1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_CAN1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_CAN1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_EDMA1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_EDMA1_SHIFT (1U)
/*! edma1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_EDMA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_EDMA1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_EDMA1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPI2C1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPI2C1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPI2C2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPI2C2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPIT1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPIT1_SHIFT (4U)
/*! lpit1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPIT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPIT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPIT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPSPI1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPSPI1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPSPI2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPSPI2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPTMR1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPTMR1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPTMR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_LPTMR1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_SAI1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_SAI1_SHIFT (8U)
/*! sai1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_SAI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_SAI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_TPM1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_TPM1_SHIFT (9U)
/*! tpm1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_TPM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_TPM1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_TPM1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_TPM2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_TPM2_SHIFT (10U)
/*! tpm2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_TPM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_TPM2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_TPM2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_WDOG1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_WDOG1_SHIFT (11U)
/*! wdog1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_WDOG1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_WDOG1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_WDOG2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_WDOG2_SHIFT (12U)
/*! wdog2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_WDOG2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_WDOG2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_I3C1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_I3C1_SHIFT (13U)
/*! i3c1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_I3C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_I3C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_I3C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_PDM_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_PDM_SHIFT (14U)
/*! pdm - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_PDM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_PDM_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_PDM_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_SYS_CTR1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_SYS_CTR1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_SYS_CTR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_SYS_CTR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_SYS_CTR1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C0 - IPG DEBUG MASK BIT CA55 CORE0 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_CAN1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_CAN1_SHIFT (0U)
/*! can1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_CAN1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_CAN1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_CAN1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_EDMA1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_EDMA1_SHIFT (1U)
/*! edma1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_EDMA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_EDMA1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_EDMA1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPIT1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPIT1_SHIFT (4U)
/*! lpit1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPIT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPIT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPIT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPTMR1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPTMR1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPTMR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_LPTMR1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SAI1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SAI1_SHIFT (8U)
/*! sai1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SAI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SAI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM1_SHIFT (9U)
/*! tpm1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM2_SHIFT (10U)
/*! tpm2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_TPM2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG1_SHIFT (11U)
/*! wdog1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG2_SHIFT (12U)
/*! wdog2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_WDOG2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_I3C1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_I3C1_SHIFT (13U)
/*! i3c1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_I3C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_I3C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_I3C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_PDM_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_PDM_SHIFT (14U)
/*! pdm - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_PDM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_PDM_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_PDM_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SYS_CTR1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SYS_CTR1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SYS_CTR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SYS_CTR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_SYS_CTR1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C1 - IPG DEBUG MASK BIT CA55 CORE1 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_CAN1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_CAN1_SHIFT (0U)
/*! can1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_CAN1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_CAN1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_CAN1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_EDMA1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_EDMA1_SHIFT (1U)
/*! edma1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_EDMA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_EDMA1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_EDMA1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPI2C1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPI2C1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPI2C2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPI2C2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPIT1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPIT1_SHIFT (4U)
/*! lpit1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPIT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPIT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPIT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPSPI1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPSPI1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPSPI2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPSPI2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPTMR1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPTMR1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPTMR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_LPTMR1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_SAI1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_SAI1_SHIFT (8U)
/*! sai1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_SAI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_SAI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_TPM1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_TPM1_SHIFT (9U)
/*! tpm1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_TPM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_TPM1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_TPM1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_TPM2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_TPM2_SHIFT (10U)
/*! tpm2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_TPM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_TPM2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_TPM2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_WDOG1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_WDOG1_SHIFT (11U)
/*! wdog1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_WDOG1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_WDOG1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_WDOG2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_WDOG2_SHIFT (12U)
/*! wdog2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_WDOG2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_WDOG2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_I3C1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_I3C1_SHIFT (13U)
/*! i3c1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_I3C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_I3C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_I3C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_PDM_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_PDM_SHIFT (14U)
/*! pdm - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_PDM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_PDM_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_PDM_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_SYS_CTR1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_SYS_CTR1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_SYS_CTR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_SYS_CTR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_SYS_CTR1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C2 - IPG DEBUG MASK BIT CA55 CORE2 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_CAN1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_CAN1_SHIFT (0U)
/*! can1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_CAN1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_CAN1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_CAN1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_EDMA1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_EDMA1_SHIFT (1U)
/*! edma1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_EDMA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_EDMA1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_EDMA1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPI2C1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPI2C1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPI2C2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPI2C2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPIT1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPIT1_SHIFT (4U)
/*! lpit1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPIT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPIT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPIT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPSPI1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPSPI1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPSPI2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPSPI2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPTMR1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPTMR1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPTMR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_LPTMR1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_SAI1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_SAI1_SHIFT (8U)
/*! sai1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_SAI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_SAI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_TPM1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_TPM1_SHIFT (9U)
/*! tpm1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_TPM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_TPM1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_TPM1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_TPM2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_TPM2_SHIFT (10U)
/*! tpm2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_TPM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_TPM2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_TPM2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_WDOG1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_WDOG1_SHIFT (11U)
/*! wdog1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_WDOG1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_WDOG1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_WDOG2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_WDOG2_SHIFT (12U)
/*! wdog2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_WDOG2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_WDOG2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_I3C1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_I3C1_SHIFT (13U)
/*! i3c1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_I3C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_I3C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_I3C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_PDM_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_PDM_SHIFT (14U)
/*! pdm - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_PDM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_PDM_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_PDM_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_SYS_CTR1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_SYS_CTR1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_SYS_CTR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_SYS_CTR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_SYS_CTR1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C3 - IPG DEBUG MASK BIT CA55 CORE3 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_CAN1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_CAN1_SHIFT (0U)
/*! can1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_CAN1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_CAN1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_CAN1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_EDMA1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_EDMA1_SHIFT (1U)
/*! edma1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_EDMA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_EDMA1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_EDMA1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPI2C1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPI2C1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPI2C2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPI2C2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPIT1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPIT1_SHIFT (4U)
/*! lpit1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPIT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPIT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPIT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPSPI1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPSPI1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPSPI2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPSPI2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPTMR1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPTMR1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPTMR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_LPTMR1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_SAI1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_SAI1_SHIFT (8U)
/*! sai1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_SAI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_SAI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_TPM1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_TPM1_SHIFT (9U)
/*! tpm1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_TPM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_TPM1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_TPM1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_TPM2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_TPM2_SHIFT (10U)
/*! tpm2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_TPM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_TPM2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_TPM2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_WDOG1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_WDOG1_SHIFT (11U)
/*! wdog1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_WDOG1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_WDOG1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_WDOG2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_WDOG2_SHIFT (12U)
/*! wdog2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_WDOG2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_WDOG2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_I3C1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_I3C1_SHIFT (13U)
/*! i3c1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_I3C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_I3C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_I3C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_PDM_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_PDM_SHIFT (14U)
/*! pdm - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_PDM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_PDM_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_PDM_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_SYS_CTR1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_SYS_CTR1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_SYS_CTR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_SYS_CTR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_SYS_CTR1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C4 - IPG DEBUG MASK BIT CA55 CORE4 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_CAN1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_CAN1_SHIFT (0U)
/*! can1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_CAN1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_CAN1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_CAN1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_EDMA1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_EDMA1_SHIFT (1U)
/*! edma1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_EDMA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_EDMA1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_EDMA1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPI2C1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPI2C1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPI2C2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPI2C2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPIT1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPIT1_SHIFT (4U)
/*! lpit1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPIT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPIT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPIT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPSPI1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPSPI1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPSPI2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPSPI2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPTMR1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPTMR1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPTMR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_LPTMR1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_SAI1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_SAI1_SHIFT (8U)
/*! sai1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_SAI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_SAI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_TPM1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_TPM1_SHIFT (9U)
/*! tpm1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_TPM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_TPM1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_TPM1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_TPM2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_TPM2_SHIFT (10U)
/*! tpm2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_TPM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_TPM2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_TPM2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_WDOG1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_WDOG1_SHIFT (11U)
/*! wdog1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_WDOG1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_WDOG1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_WDOG2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_WDOG2_SHIFT (12U)
/*! wdog2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_WDOG2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_WDOG2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_I3C1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_I3C1_SHIFT (13U)
/*! i3c1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_I3C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_I3C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_I3C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_PDM_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_PDM_SHIFT (14U)
/*! pdm - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_PDM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_PDM_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_PDM_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_SYS_CTR1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_SYS_CTR1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_SYS_CTR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_SYS_CTR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C4_SYS_CTR1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C5 - IPG DEBUG MASK BIT CA55 CORE5 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_CAN1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_CAN1_SHIFT (0U)
/*! can1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_CAN1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_CAN1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_CAN1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_EDMA1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_EDMA1_SHIFT (1U)
/*! edma1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_EDMA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_EDMA1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_EDMA1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPI2C1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPI2C1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPI2C2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPI2C2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPIT1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPIT1_SHIFT (4U)
/*! lpit1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPIT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPIT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPIT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPSPI1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPSPI1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPSPI2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPSPI2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPTMR1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPTMR1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPTMR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_LPTMR1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_SAI1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_SAI1_SHIFT (8U)
/*! sai1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_SAI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_SAI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_TPM1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_TPM1_SHIFT (9U)
/*! tpm1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_TPM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_TPM1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_TPM1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_TPM2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_TPM2_SHIFT (10U)
/*! tpm2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_TPM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_TPM2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_TPM2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_WDOG1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_WDOG1_SHIFT (11U)
/*! wdog1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_WDOG1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_WDOG1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_WDOG2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_WDOG2_SHIFT (12U)
/*! wdog2 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_WDOG2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_WDOG2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_I3C1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_I3C1_SHIFT (13U)
/*! i3c1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_I3C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_I3C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_I3C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_PDM_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_PDM_SHIFT (14U)
/*! pdm - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_PDM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_PDM_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_PDM_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_SYS_CTR1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_SYS_CTR1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_SYS_CTR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_SYS_CTR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C5_SYS_CTR1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM7 - IPG DEBUG MASK BIT for cm7 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_CAN1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_CAN1_SHIFT (0U)
/*! can1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_CAN1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_CAN1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_CAN1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_EDMA1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_EDMA1_SHIFT (1U)
/*! edma1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_EDMA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_EDMA1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_EDMA1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPI2C1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPI2C1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPI2C2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPI2C2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPIT1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPIT1_SHIFT (4U)
/*! lpit1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPIT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPIT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPIT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPSPI1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPSPI1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPSPI2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPSPI2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPTMR1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPTMR1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPTMR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_LPTMR1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_SAI1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_SAI1_SHIFT (8U)
/*! sai1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_SAI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_SAI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_TPM1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_TPM1_SHIFT (9U)
/*! tpm1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_TPM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_TPM1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_TPM1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_TPM2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_TPM2_SHIFT (10U)
/*! tpm2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_TPM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_TPM2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_TPM2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_WDOG1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_WDOG1_SHIFT (11U)
/*! wdog1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_WDOG1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_WDOG1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_WDOG2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_WDOG2_SHIFT (12U)
/*! wdog2 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_WDOG2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_WDOG2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_I3C1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_I3C1_SHIFT (13U)
/*! i3c1 - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_I3C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_I3C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_I3C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_PDM_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_PDM_SHIFT (14U)
/*! pdm - Mask bit for debug halted mode
 *  0b0..Block does not enter debug halted mode with CA55
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_PDM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_PDM_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_PDM_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_SYS_CTR1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_SYS_CTR1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug halted mode
 *  0b1..Block enters debug halted mode when CA55 is debug halted
 *  0b0..Block does not enter debug halted mode with CA55
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_SYS_CTR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_SYS_CTR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_SYS_CTR1_MASK)
/*! @} */

/*! @name FUSE_ACC_DIS - Read-only version of the OCOTP fuse-access-disable bit */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_SHIFT (0U)
/*! OSCCA_FUSE_READ_DIS - Fuse read disable bit
 *  0b1..SoC is not allowed to access the OCOTP
 *  0b0..SoC is allowed to access the OCOTP registers
 */
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_SHIFT)) & BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA0 - Read-only version of OCOTP fusedata_mtr_cfg_0 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_SHIFT (0U)
/*! OCOTP_FUSE_DATA0 - OCOTP_FUSE_DATA0 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA1 - Read-only version of OCOTP fusedata_mtr_cfg_1 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_SHIFT (0U)
/*! OCOTP_FUSE_DATA1 - OCOTP_FUSE_DATA1 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA2 - Read-only version of OCOTP fusedata_mtr_cfg_2 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_SHIFT (0U)
/*! OCOTP_FUSE_DATA2 - OCOTP_FUSE_DATA2 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA3 - Read-only version of OCOTP fusedata_mtr_cfg_3 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_SHIFT (0U)
/*! OCOTP_FUSE_DATA3 - OCOTP_FUSE_DATA3 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA4 - Read-only version of OCOTP fusedata_mtr_cfg_4 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_SHIFT (0U)
/*! OCOTP_FUSE_DATA4 - OCOTP_FUSE_DATA4 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA5 - Read-only version of OCOTP fusedata_mtr_cfg_5 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_SHIFT (0U)
/*! OCOTP_FUSE_DATA5 - OCOTP_FUSE_DATA5 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA6 - Read-only version of OCOTP fusedata_mtr_cfg_6 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_SHIFT (0U)
/*! OCOTP_FUSE_DATA6 - OCOTP_FUSE_DATA6 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA7 - Read-only version of OCOTP fusedata_mtr_cfg_7 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_SHIFT (0U)
/*! OCOTP_FUSE_DATA7 - OCOTP_FUSE_DATA7 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA8 - Read-only version of OCOTP fusedata_mem_trim_cfg0 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_SHIFT (0U)
/*! OCOTP_FUSE_DATA8 - OCOTP_FUSE_DATA8 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA9 - Read-only version of OCOTP fusedata_mem_trim_cfg1 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_SHIFT (0U)
/*! OCOTP_FUSE_DATA9 - OCOTP_FUSE_DATA9 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA10 - Read-only version of OCOTP fusedata_mem_trim_cfg2 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_SHIFT (0U)
/*! OCOTP_FUSE_DATA10 - OCOTP_FUSE_DATA10 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA11 - Read-only version of OCOTP fusedata_mem_trim_cfg3 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_SHIFT (0U)
/*! OCOTP_FUSE_DATA11 - OCOTP_FUSE_DATA12 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA12 - Read-only version of OCOTP fusedata_mem_trim_cfg4 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_SHIFT (0U)
/*! OCOTP_FUSE_DATA12 - OCOTP_FUSE_DATA13 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA13 - Read-only version of OCOTP fusedata_mem_trim_cfg5 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_SHIFT (0U)
/*! OCOTP_FUSE_DATA13 - OCOTP_FUSE_DATA13 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA14 - Read-only version of OCOTP fusedata_mem_trim_cfg6 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_SHIFT (0U)
/*! OCOTP_FUSE_DATA14 - OCOTP_FUSE_DATA14 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA15 - Read-only version of OCOTP fusedata_mem_trim_cfg7 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_SHIFT (0U)
/*! OCOTP_FUSE_DATA15 - OCOTP_FUSE_DATA15 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_MASK)
/*! @} */

/*! @name I3C1_WAKEUP - I3C1 WAKEUPX CLR */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_IRQ_CLR_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_IRQ_CLR_SHIFT (0U)
/*! irq_clr - I3C1 interrupt request clear */
#define BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_IRQ_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_IRQ_CLR_SHIFT)) & BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_IRQ_CLR_MASK)
/*! @} */

/*! @name OCOTP_STATUS - OCOTP status register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_STATUS_BUSY_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_OCOTP_STATUS_BUSY_SHIFT (0U)
/*! busy - OCOTP controller busy bit
 *  0b1..Busy
 *  0b0..Idle
 */
#define BLK_CTRL_NS_AONMIX_OCOTP_STATUS_BUSY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_STATUS_BUSY_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_STATUS_BUSY_MASK)
/*! @} */

/*! @name PDM_CLK_SEL - PDM clock selection register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_SEL_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_SEL_SHIFT (0U)
/*! sel - select source for pdm clock
 *  0b1..SAI1_MCLK
 *  0b0..PDM root clock
 */
#define BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_SEL_SHIFT)) & BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_SEL_MASK)
/*! @} */

/*! @name I3C1_SDA_IRQ - I3C1 SDA IRQ */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_ENABLE_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_ENABLE_SHIFT (0U)
/*! enable - IRQ enable bit
 *  0b0..I3C1 SDA IRQ disable
 *  0b1..I3C1 SDA IRQ enable
 */
#define BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_ENABLE_SHIFT)) & BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_ENABLE_MASK)
/*! @} */

/*! @name SSI - SSI master low power mode control */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_SHIFT (0U)
/*! PAUSE_MODE - AONMIX SSI master pause mode
 *  0b0..AONMIX SSI master is not in pause mode
 *  0b1..AONMIX SSI master is not in pause mode
 */
#define BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_SHIFT)) & BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_MASK)

#define BLK_CTRL_NS_AONMIX_SSI_BLKHOLE_MODE_B_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_SSI_BLKHOLE_MODE_B_SHIFT (1U)
/*! BLKHOLE_MODE_B - AONMIX SSI master blackhole mode
 *  0b1..AONMIX SSI master will exit from blackhole mode
 *  0b0..AONMIX SSI master will enter into blackhole mode
 */
#define BLK_CTRL_NS_AONMIX_SSI_BLKHOLE_MODE_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_SSI_BLKHOLE_MODE_B_SHIFT)) & BLK_CTRL_NS_AONMIX_SSI_BLKHOLE_MODE_B_MASK)
/*! @} */

/*! @name FASTBOOT_ENABLE - fastboot enable */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_MASK (0x3U)
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_SHIFT (0U)
/*! FASTBOOT_ENABLE - FASTBOOT_ENABLE bits */
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_SHIFT)) & BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_MASK)

#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_MASK (0xCU)
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_SHIFT (2U)
/*! BP_FASTBOOT_ENABLE - BP_FASTBOOT_ENABLE bits */
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_SHIFT)) & BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_MASK)
/*! @} */

/*! @name MQS_SETTINGS - MQS settings */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_SHIFT (1U)
/*! MQS_EN - MQS Enable
 *  0b1..Enable MQS
 *  0b0..Disable MQS
 */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_MASK)

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_SHIFT (2U)
/*! SOFT_RESET - Software Reset
 *  0b0..Exit software reset for MQS
 *  0b1..Enable software reset for MQS
 */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_MASK)

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_SHIFT (3U)
/*! OVERSAMPLE - Oversample rate
 *  0b0..64
 *  0b1..32
 */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_MASK)

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_MASK (0xFF00U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_SHIFT (8U)
/*! CLK_DIVIDE - Clock divide factor configuration */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_MASK)
/*! @} */

/*! @name SENTINEL_FW_PRESENT - Read only bit for fuse SENTINEL_FW_PRESENT */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_SENTINEL_FW_PRESENT_SENTINEL_FW_PRESENT_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_SENTINEL_FW_PRESENT_SENTINEL_FW_PRESENT_SHIFT (0U)
/*! sentinel_fw_present - Read-only bit for Sentinel FW present */
#define BLK_CTRL_NS_AONMIX_SENTINEL_FW_PRESENT_SENTINEL_FW_PRESENT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_SENTINEL_FW_PRESENT_SENTINEL_FW_PRESENT_SHIFT)) & BLK_CTRL_NS_AONMIX_SENTINEL_FW_PRESENT_SENTINEL_FW_PRESENT_MASK)
/*! @} */

/*! @name AOMIX_SPARE_FUSE - Spare fuse register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_AOMIX_SPARE_FUSE_SPARE_FUSE_MASK (0x3U)
#define BLK_CTRL_NS_AONMIX_AOMIX_SPARE_FUSE_SPARE_FUSE_SHIFT (0U)
/*! Spare_fuse - Read-only bit for Spare fuse */
#define BLK_CTRL_NS_AONMIX_AOMIX_SPARE_FUSE_SPARE_FUSE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_AOMIX_SPARE_FUSE_SPARE_FUSE_SHIFT)) & BLK_CTRL_NS_AONMIX_AOMIX_SPARE_FUSE_SPARE_FUSE_MASK)
/*! @} */

/*! @name IPG_STOP_CTL - IPG_STOP Control Register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_CAN1_STOP_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_CAN1_STOP_SHIFT (0U)
/*! can1_stop - CAN1 ipg_stop control
 *  0b1..Enable stop
 *  0b0..Disable stop
 */
#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_CAN1_STOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_CAN1_STOP_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_CAN1_STOP_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_EDMA1_STOP_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_EDMA1_STOP_SHIFT (1U)
/*! edma1_stop - EDMA1 ipg_stop control
 *  0b1..Enable stop
 *  0b0..Disable stop
 */
#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_EDMA1_STOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_EDMA1_STOP_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_EDMA1_STOP_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_PDM_STOP_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_PDM_STOP_SHIFT (9U)
/*! pdm_stop - PDM ipg_stop control
 *  0b0..Disable stop
 *  0b1..Enable stop
 */
#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_PDM_STOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_PDM_STOP_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_PDM_STOP_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_TPM1_STOP_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_TPM1_STOP_SHIFT (11U)
/*! tpm1_stop - TPM1 ipg_stop control
 *  0b0..Disable stop
 *  0b1..Enable stop
 */
#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_TPM1_STOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_TPM1_STOP_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_TPM1_STOP_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_TPM2_STOP_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_TPM2_STOP_SHIFT (12U)
/*! tpm2_stop - TPM2 ipg_stop control
 *  0b0..Disable stop
 *  0b1..Enable stop
 */
#define BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_TPM2_STOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_TPM2_STOP_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_STOP_CTL_TPM2_STOP_MASK)
/*! @} */

/*! @name IPG_STOP_ACK_STATUS - IPG_STOP_ACK Status Register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_STOP_ACK_STATUS_CAN1_STOP_ACK_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_STOP_ACK_STATUS_CAN1_STOP_ACK_SHIFT (0U)
/*! can1_stop_ack - CAN1 ipg_stop_ack status
 *  0b0..No stop acknowledge
 *  0b1..Stop acknowledge
 */
#define BLK_CTRL_NS_AONMIX_IPG_STOP_ACK_STATUS_CAN1_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_STOP_ACK_STATUS_CAN1_STOP_ACK_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_STOP_ACK_STATUS_CAN1_STOP_ACK_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_STOP_ACK_STATUS_PDM_STOP_ACK_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_STOP_ACK_STATUS_PDM_STOP_ACK_SHIFT (9U)
/*! pdm_stop_ack - PDM ipg_stop_ack status
 *  0b1..Stop acknowledge
 *  0b0..No stop acknowledge
 */
#define BLK_CTRL_NS_AONMIX_IPG_STOP_ACK_STATUS_PDM_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_STOP_ACK_STATUS_PDM_STOP_ACK_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_STOP_ACK_STATUS_PDM_STOP_ACK_MASK)
/*! @} */

/*! @name IPG_DOZE_CTL - IPG_DOZE_CTL Control Register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_CAN1_DOZE_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_CAN1_DOZE_SHIFT (0U)
/*! can1_doze - CAN1 doze control
 *  0b1..Enable doze
 *  0b0..Disable doze
 */
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_CAN1_DOZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_CAN1_DOZE_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_CAN1_DOZE_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPI2C1_DOZE_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPI2C1_DOZE_SHIFT (2U)
/*! lpi2c1_doze - LPI2C1 doze control
 *  0b1..Enable doze
 *  0b0..Disable doze
 */
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPI2C1_DOZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPI2C1_DOZE_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPI2C1_DOZE_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPI2C2_DOZE_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPI2C2_DOZE_SHIFT (3U)
/*! lpi2c2_doze - LPI2C2 doze control
 *  0b1..Enable doze
 *  0b0..Disable doze
 */
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPI2C2_DOZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPI2C2_DOZE_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPI2C2_DOZE_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPIT1_DOZE_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPIT1_DOZE_SHIFT (4U)
/*! lpit1_doze - LPIT1 doze control
 *  0b1..Enable doze
 *  0b0..Disable doze
 */
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPIT1_DOZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPIT1_DOZE_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPIT1_DOZE_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPSPI1_DOZE_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPSPI1_DOZE_SHIFT (5U)
/*! lpspi1_doze - LPSPI1 doze control
 *  0b1..Enable doze
 *  0b0..Disable doze
 */
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPSPI1_DOZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPSPI1_DOZE_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPSPI1_DOZE_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPSPI2_DOZE_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPSPI2_DOZE_SHIFT (6U)
/*! lpspi2_doze - LPSPI2 doze control
 *  0b1..Enable doze
 *  0b0..Disable doze
 */
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPSPI2_DOZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPSPI2_DOZE_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPSPI2_DOZE_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPUART1_DOZE_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPUART1_DOZE_SHIFT (7U)
/*! lpuart1_doze - LPUART1 doze control
 *  0b1..Enable doze
 *  0b0..Disable doze
 */
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPUART1_DOZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPUART1_DOZE_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPUART1_DOZE_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPUART2_DOZE_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPUART2_DOZE_SHIFT (8U)
/*! lpuart2_doze - LPUART2 doze control
 *  0b1..Enable doze
 *  0b0..Disable doze
 */
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPUART2_DOZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPUART2_DOZE_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_LPUART2_DOZE_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_PDM_DOZE_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_PDM_DOZE_SHIFT (9U)
/*! pdm_doze - PDM doze control
 *  0b1..Enable doze
 *  0b0..Disable doze
 */
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_PDM_DOZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_PDM_DOZE_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_PDM_DOZE_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_TPM1_DOZE_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_TPM1_DOZE_SHIFT (11U)
/*! tpm1_doze - TPM1 doze control
 *  0b1..Enable doze
 *  0b0..Disable doze
 */
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_TPM1_DOZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_TPM1_DOZE_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_TPM1_DOZE_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_TPM2_DOZE_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_TPM2_DOZE_SHIFT (12U)
/*! tpm2_doze - TPM2 doze control
 *  0b1..Enable doze
 *  0b0..Disable doze
 */
#define BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_TPM2_DOZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_TPM2_DOZE_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DOZE_CTL_TPM2_DOZE_MASK)
/*! @} */

/*! @name QREQ_N - QREQ_N Control Register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_QREQ_N_LPI2C1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPI2C1_SHIFT (1U)
/*! lpi2c1 - lpi2c1 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPI2C1(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_LPI2C2_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPI2C2_SHIFT (2U)
/*! lpi2c2 - lpi2c2 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPI2C2(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_LPSPI1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPSPI1_SHIFT (4U)
/*! lpspi1 - lpspi1 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPSPI1(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_LPSPI2_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPSPI2_SHIFT (5U)
/*! lpspi2 - lpspi2 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPSPI2(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_LPUART1_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPUART1_SHIFT (6U)
/*! lpuart1 - lpuart1 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPUART1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_LPUART1_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_LPUART1_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_LPUART2_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPUART2_SHIFT (7U)
/*! lpuart2 - lpuart2 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_LPUART2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_LPUART2_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_LPUART2_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPI2C1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPI2C1_SHIFT (8U)
/*! ips_lpi2c1 - ips_lpi2c1 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPI2C2_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPI2C2_SHIFT (9U)
/*! ips_lpi2c2 - ips_lpi2c2 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_AHB_GPIO_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_AHB_GPIO_SHIFT (10U)
/*! ahb_gpio - ahb_gpio */
#define BLK_CTRL_NS_AONMIX_QREQ_N_AHB_GPIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_AHB_GPIO_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_AHB_GPIO_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPSPI1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPSPI1_SHIFT (11U)
/*! ips_lpspi1 - ips_lpspi1 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPSPI2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPSPI2_SHIFT (12U)
/*! ips_lpspi2 - ips_lpspi2 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_IPS_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_APB_LPUART1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_APB_LPUART1_SHIFT (13U)
/*! apb_lpuart1 - apb_lpuart1 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_APB_LPUART1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_APB_LPUART1_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_APB_LPUART1_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_APB_LPUART2_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_APB_LPUART2_SHIFT (14U)
/*! apb_lpuart2 - apb_lpuart2 */
#define BLK_CTRL_NS_AONMIX_QREQ_N_APB_LPUART2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_APB_LPUART2_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_APB_LPUART2_MASK)

#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_SAI_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_SAI_SHIFT (15U)
/*! ips_sai - ips_sai */
#define BLK_CTRL_NS_AONMIX_QREQ_N_IPS_SAI(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QREQ_N_IPS_SAI_SHIFT)) & BLK_CTRL_NS_AONMIX_QREQ_N_IPS_SAI_MASK)
/*! @} */

/*! @name SAI_MCLK - SAI1 MCLK Control Register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_MCLK_REQ_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_MCLK_REQ_SHIFT (0U)
/*! sai_mclk_req - SAI MCLK request */
#define BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_MCLK_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_MCLK_REQ_SHIFT)) & BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_MCLK_REQ_MASK)

#define BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_MCLK_ACK_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_MCLK_ACK_SHIFT (1U)
/*! sai_mclk_ack - SAI MCLK ack */
#define BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_MCLK_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_MCLK_ACK_SHIFT)) & BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_MCLK_ACK_MASK)

#define BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_QACTIVE_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_QACTIVE_SHIFT (2U)
/*! sai_qactive - SAI qactive */
#define BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_QACTIVE_SHIFT)) & BLK_CTRL_NS_AONMIX_SAI_MCLK_SAI_QACTIVE_MASK)
/*! @} */

/*! @name QACTIVE - QACTIVE Status Register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_QACTIVE_LPI2C1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPI2C1_SHIFT (1U)
/*! lpi2c1 - lpi2c1 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_LPI2C2_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPI2C2_SHIFT (2U)
/*! lpi2c2 - lpi2c2 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_LPSPI1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPSPI1_SHIFT (4U)
/*! lpspi1 - lpspi1 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_LPSPI2_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPSPI2_SHIFT (5U)
/*! lpspi2 - lpspi2 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_LPUART1_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPUART1_SHIFT (6U)
/*! lpuart1 - lpuart1 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPUART1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_LPUART1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_LPUART1_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_LPUART2_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPUART2_SHIFT (7U)
/*! lpuart2 - lpuart2 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_LPUART2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_LPUART2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_LPUART2_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPI2C1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPI2C1_SHIFT (8U)
/*! ips_lpi2c1 - ips_lpi2c1 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPI2C2_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPI2C2_SHIFT (9U)
/*! ips_lpi2c2 - ips_lpi2c2 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_AHB_GPIO_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_AHB_GPIO_SHIFT (10U)
/*! ahb_gpio - ahb_gpio */
#define BLK_CTRL_NS_AONMIX_QACTIVE_AHB_GPIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_AHB_GPIO_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_AHB_GPIO_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPSPI1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPSPI1_SHIFT (11U)
/*! ips_lpspi1 - ips_lpspi1 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPSPI2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPSPI2_SHIFT (12U)
/*! ips_lpspi2 - ips_lpspi2 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_IPS_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_APB_LPUART1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_APB_LPUART1_SHIFT (13U)
/*! apb_lpuart1 - apb_lpuart1 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_APB_LPUART1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_APB_LPUART1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_APB_LPUART1_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_APB_LPUART2_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_APB_LPUART2_SHIFT (14U)
/*! apb_lpuart2 - apb_lpuart2 */
#define BLK_CTRL_NS_AONMIX_QACTIVE_APB_LPUART2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_APB_LPUART2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_APB_LPUART2_MASK)

#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_SAI_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_SAI_SHIFT (15U)
/*! ips_sai - ips_sai */
#define BLK_CTRL_NS_AONMIX_QACTIVE_IPS_SAI(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACTIVE_IPS_SAI_SHIFT)) & BLK_CTRL_NS_AONMIX_QACTIVE_IPS_SAI_MASK)
/*! @} */

/*! @name QDENY - QDENY Status Register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_QDENY_LPI2C1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_QDENY_LPI2C1_SHIFT (1U)
/*! lpi2c1 - lpi2c1 */
#define BLK_CTRL_NS_AONMIX_QDENY_LPI2C1(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QDENY_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_QDENY_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_QDENY_LPI2C2_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_QDENY_LPI2C2_SHIFT (2U)
/*! lpi2c2 - lpi2c2 */
#define BLK_CTRL_NS_AONMIX_QDENY_LPI2C2(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QDENY_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_QDENY_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_QDENY_LPSPI1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_QDENY_LPSPI1_SHIFT (4U)
/*! lpspi1 - lpspi1 */
#define BLK_CTRL_NS_AONMIX_QDENY_LPSPI1(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QDENY_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_QDENY_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_QDENY_LPSPI2_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_QDENY_LPSPI2_SHIFT (5U)
/*! lpspi2 - lpspi2 */
#define BLK_CTRL_NS_AONMIX_QDENY_LPSPI2(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QDENY_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_QDENY_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_QDENY_LPUART1_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_QDENY_LPUART1_SHIFT (6U)
/*! lpuart1 - lpuart1 */
#define BLK_CTRL_NS_AONMIX_QDENY_LPUART1(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QDENY_LPUART1_SHIFT)) & BLK_CTRL_NS_AONMIX_QDENY_LPUART1_MASK)

#define BLK_CTRL_NS_AONMIX_QDENY_LPUART2_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_QDENY_LPUART2_SHIFT (7U)
/*! lpuart2 - lpuart2 */
#define BLK_CTRL_NS_AONMIX_QDENY_LPUART2(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QDENY_LPUART2_SHIFT)) & BLK_CTRL_NS_AONMIX_QDENY_LPUART2_MASK)
/*! @} */

/*! @name QACCEPT_N - QACCEPT_N Status Register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPI2C1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPI2C1_SHIFT (1U)
/*! lpi2c1 - lpi2c1 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPI2C2_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPI2C2_SHIFT (2U)
/*! lpi2c2 - lpi2c2 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPSPI1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPSPI1_SHIFT (4U)
/*! lpspi1 - lpspi1 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPSPI2_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPSPI2_SHIFT (5U)
/*! lpspi2 - lpspi2 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPUART1_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPUART1_SHIFT (6U)
/*! lpuart1 - lpuart1 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPUART1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_LPUART1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_LPUART1_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPUART2_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPUART2_SHIFT (7U)
/*! lpuart2 - lpuart2 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_LPUART2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_LPUART2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_LPUART2_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPI2C1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPI2C1_SHIFT (8U)
/*! ips_lpi2c1 - ips_lpi2c1 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPI2C2_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPI2C2_SHIFT (9U)
/*! ips_lpi2c2 - ips_lpi2c2 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_AHB_GPIO_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_AHB_GPIO_SHIFT (10U)
/*! ahb_gpio - ahb_gpio */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_AHB_GPIO(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_AHB_GPIO_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_AHB_GPIO_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPSPI1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPSPI1_SHIFT (11U)
/*! ips_lpspi1 - ips_lpspi1 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPSPI2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPSPI2_SHIFT (12U)
/*! ips_lpspi2 - ips_lpspi2 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_APB_LPUART1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_APB_LPUART1_SHIFT (13U)
/*! apb_lpuart1 - apb_lpuart1 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_APB_LPUART1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_APB_LPUART1_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_APB_LPUART1_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_APB_LPUART2_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_APB_LPUART2_SHIFT (14U)
/*! apb_lpuart2 - apb_lpuart2 */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_APB_LPUART2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_APB_LPUART2_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_APB_LPUART2_MASK)

#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_SAI_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_SAI_SHIFT (15U)
/*! ips_sai - ips_sai */
#define BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_SAI(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_SAI_SHIFT)) & BLK_CTRL_NS_AONMIX_QACCEPT_N_IPS_SAI_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_NS_AONMIX_Register_Masks */


/* BLK_CTRL_NS_AONMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_NS_AONMIX base address */
#define BLK_CTRL_NS_AONMIX_BASE                 (0x44210000u)
/** Peripheral BLK_CTRL_NS_AONMIX base pointer */
#define BLK_CTRL_NS_AONMIX                      ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX_BASE)
/** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
#define BLK_CTRL_NS_AONMIX_BASE_ADDRS           { BLK_CTRL_NS_AONMIX_BASE }
/** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
#define BLK_CTRL_NS_AONMIX_BASE_PTRS            { BLK_CTRL_NS_AONMIX }

/*!
 * @}
 */ /* end of group BLK_CTRL_NS_AONMIX_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_BLK_CTRL_NS_AONMIX_H_) */
