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
**         CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
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
 * @file BLK_CTRL_S_AONMIX.h
 * @version 1.0
 * @date 2026-01-10
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
 */

#if !defined(BLK_CTRL_S_AONMIX_H_)
#define BLK_CTRL_S_AONMIX_H_                     /**< Symbol preventing repeated inclusion */

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
   -- BLK_CTRL_S_AONMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_S_AONMIX_Peripheral_Access_Layer BLK_CTRL_S_AONMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_S_AONMIX - Size of Registers Arrays */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_COUNT          8u
#define BLK_CTRL_S_AONMIX_CA55_IRQ_COUNT          6u
#define BLK_CTRL_S_AONMIX_CM7_IRQ_COUNT           8u

/** BLK_CTRL_S_AONMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CM33_IRQ_MASK[BLK_CTRL_S_AONMIX_CM33_IRQ_COUNT]; /**< CM33_IRQ_MASK0..CM33_IRQ_MASK7, array offset: 0x0, array step: 0x4 */
  __IO uint32_t CM33_IRQ_MASK8;                    /**< CM33_IRQ_MASK8, offset: 0x20 */
  __IO uint32_t CM33_IRQ_MASK9;                    /**< CM33_IRQ_MASK9, offset: 0x24 */
  __IO uint32_t CM33_IRQ_MASK10;                   /**< CM33_IRQ_MASK10, offset: 0x28 */
  __IO uint32_t CM33_IRQ_MASK11;                   /**< CM33_IRQ_MASK11, offset: 0x2C */
  __IO uint32_t CM33_IRQ_MASK12;                   /**< CM33_IRQ_MASK12, offset: 0x30 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CA55_IRQ_MASK[BLK_CTRL_S_AONMIX_CA55_IRQ_COUNT]; /**< CA55_IRQ_MASK0..CA55_IRQ_MASK5, array offset: 0x40, array step: 0x4 */
  __IO uint32_t CA55_IRQ_MASK6;                    /**< CA55_IRQ_MASK6, offset: 0x58 */
  __IO uint32_t CA55_IRQ_MASK7;                    /**< CA55_IRQ_MASK7, offset: 0x5C */
  __IO uint32_t CA55_IRQ_MASK8;                    /**< CA55_IRQ_MASK8, offset: 0x60 */
  __IO uint32_t CA55_IRQ_MASK9;                    /**< CA55_IRQ_MASK9, offset: 0x64 */
  __IO uint32_t CA55_IRQ_MASK10;                   /**< CA55_IRQ_MASK10, offset: 0x68 */
  __IO uint32_t CA55_IRQ_MASK11;                   /**< CA55_IRQ_MASK11, offset: 0x6C */
  __IO uint32_t CA55_IRQ_MASK12;                   /**< CA55_IRQ_MASK12, offset: 0x70 */
       uint8_t RESERVED_1[12];
  __IO uint32_t CM7_IRQ_MASK[BLK_CTRL_S_AONMIX_CM7_IRQ_COUNT]; /**< CM7_IRQ_MASK0..CM7_IRQ_MASK7, array offset: 0x80, array step: 0x4 */
  __IO uint32_t CM7_IRQ_MASK8;                     /**< CM7_IRQ_MASK8, offset: 0xA0 */
  __IO uint32_t CM7_IRQ_MASK9;                     /**< CM7_IRQ_MASK9, offset: 0xA4 */
  __IO uint32_t CM7_IRQ_MASK10;                    /**< CM7_IRQ_MASK10, offset: 0xA8 */
  __IO uint32_t CM7_IRQ_MASK11;                    /**< CM7_IRQ_MASK11, offset: 0xAC */
  __IO uint32_t CM7_IRQ_MASK12;                    /**< CM7_IRQ_MASK12, offset: 0xB0 */
       uint8_t RESERVED_2[76];
  __IO uint32_t INITSVTOR;                         /**< M33 restart secure address, offset: 0x100 */
  __IO uint32_t INITNSVTOR;                        /**< M33 restart non-secure address, offset: 0x104 */
  __IO uint32_t INITVTOR;                          /**< M7 restart address, offset: 0x108 */
       uint8_t RESERVED_3[20];
  __IO uint32_t M33_CFG;                           /**< M33 Configure Register, offset: 0x120 */
  __IO uint32_t M7_CFG;                            /**< M7 Configure Register, offset: 0x124 */
       uint8_t RESERVED_4[8];
  __IO uint32_t AXBS_AON_CTRL;                     /**< AXBS_AON_CTRL, offset: 0x130 */
  __IO uint32_t DAP_ACCESS_STKYBIT;                /**< Dap Access Sticky Bit, offset: 0x134 */
  __IO uint32_t LP_HANDSHAKE_ELE;                  /**< Low Power Handshake for ELE Register, offset: 0x138 */
  __IO uint32_t LP_HANDSHAKE2_ELE;                 /**< Low Power Handshake 2 for ELE Register, offset: 0x13C */
       uint32_t LP_HANDSHAKE3_ELE;                 /**< Low Power Handshake 3 for ELE Register, offset: 0x140 */
  __IO uint32_t LP_HANDSHAKE_SM;                   /**< Low Power Handshake for System Manager, offset: 0x144 */
  __IO uint32_t LP_HANDSHAKE2_SM;                  /**< Low Power Handshake 2 for System Manager, offset: 0x148 */
       uint32_t LP_HANDSHAKE3_SM;                  /**< Low Power Handshake 3 for System Manager, offset: 0x14C */
  __IO uint32_t SM_LP_HANDSHAKE_STATUS;            /**< Register interface for system manager to react for the lp_handshake, offset: 0x150 */
       uint8_t RESERVED_5[12];
  __IO uint32_t CA55_CPUWAIT;                      /**< CPUWAIT settings for CA55 CPU, offset: 0x160 */
  __IO uint32_t CA55_RVBARADDR0_L;                 /**< CA55_RVBARADDR0_L, offset: 0x164 */
  __IO uint32_t CA55_RVBARADDR0_H;                 /**< CA55_RVBARADDR0_H, offset: 0x168 */
  __IO uint32_t CA55_RVBARADDR1_L;                 /**< CA55_RVBARADDR1_L, offset: 0x16C */
  __IO uint32_t CA55_RVBARADDR1_H;                 /**< CA55_RVBARADDR1_H, offset: 0x170 */
  __IO uint32_t CA55_RVBARADDR2_L;                 /**< CA55_RVBARADDR2_L, offset: 0x174 */
  __IO uint32_t CA55_RVBARADDR2_H;                 /**< CA55_RVBARADDR2_H, offset: 0x178 */
  __IO uint32_t CA55_RVBARADDR3_L;                 /**< CA55_RVBARADDR3_L, offset: 0x17C */
  __IO uint32_t CA55_RVBARADDR3_H;                 /**< CA55_RVBARADDR3_H, offset: 0x180 */
  __IO uint32_t CA55_RVBARADDR4_L;                 /**< CA55_RVBARADDR4_L, offset: 0x184 */
  __IO uint32_t CA55_RVBARADDR4_H;                 /**< CA55_RVBARADDR4_H, offset: 0x188 */
  __IO uint32_t CA55_RVBARADDR5_L;                 /**< CA55_RVBARADDR5_L, offset: 0x18C */
  __IO uint32_t CA55_RVBARADDR5_H;                 /**< CA55_RVBARADDR5_H, offset: 0x190 */
       uint8_t RESERVED_6[12];
  __IO uint32_t ELE_IRQ_MASK;                      /**< Mask bits of ELE interrupt, offset: 0x1A0 */
  __IO uint32_t ELE_RESET_REQ_MASK;                /**< Mask bits of ELE reset, offset: 0x1A4 */
  __IO uint32_t ELE_HALT_STATUS;                   /**< ELE Halt Status Register, offset: 0x1A8 */
  __IO uint32_t CA55_MODE;                         /**< Control the boot mode of two ca55 cores, offset: 0x1AC */
  __IO uint32_t NMI_MASK;                          /**< NMI MASK bits, offset: 0x1B0 */
  __IO uint32_t NMI_CLR;                           /**< NMI clear bit, offset: 0x1B4 */
  __IO uint32_t WDOG_ANY_MASK;                     /**< Wdog any mask, offset: 0x1B8 */
       uint8_t RESERVED_7[4];
  __IO uint32_t MISC_CFG;                          /**< Miscellaneous Configure Register, offset: 0x1C0 */
       uint8_t RESERVED_8[4];
  __I  uint32_t ELE_GPO_STATUS;                    /**< ELE gpo status register, offset: 0x1C8 */
  __I  uint32_t ELE_RST_REQ_STAT;                  /**< ELE Reset Request Status Register, offset: 0x1CC */
  __I  uint32_t ELE_IRQ_REQ_STAT;                  /**< ELE IRQ Request Status Register, offset: 0x1D0 */
} BLK_CTRL_S_AONMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_S_AONMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_S_AONMIX_Register_Masks BLK_CTRL_S_AONMIX Register Masks
 * @{
 */

/*! @name CM33_IRQ_MASK - CM33_IRQ_MASK0..CM33_IRQ_MASK7 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_m_MASK   (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_m_SHIFT  (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_m(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_m_MASK)
/*! @} */

/* The count of BLK_CTRL_S_AONMIX_CM33_IRQ_MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_COUNT    (8U)

/*! @name CM33_IRQ_MASK8 - CM33_IRQ_MASK8 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_m_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_m_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_m(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_m_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK9 - CM33_IRQ_MASK9 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_m_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_m_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_m(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_m_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK10 - CM33_IRQ_MASK10 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_m_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_m_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_m(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_m_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK11 - CM33_IRQ_MASK11 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_m_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_m_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_m(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_m_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK12 - CM33_IRQ_MASK12 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK12_m_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK12_m_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK12_m(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK12_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK12_m_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK - CA55_IRQ_MASK0..CA55_IRQ_MASK5 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_m_MASK   (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_m_SHIFT  (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_m(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_m_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_m_MASK)
/*! @} */

/* The count of BLK_CTRL_S_AONMIX_CA55_IRQ_MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_COUNT    (6U)

/*! @name CA55_IRQ_MASK6 - CA55_IRQ_MASK6 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_m_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_m_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_m(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_m_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_m_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK7 - CA55_IRQ_MASK7 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_m_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_m_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_m(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_m_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_m_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK8 - CA55_IRQ_MASK8 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_m_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_m_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_m(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_m_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_m_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK9 - CA55_IRQ_MASK9 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_m_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_m_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_m(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_m_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_m_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK10 - CA55_IRQ_MASK10 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_m_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_m_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_m(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_m_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_m_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK11 - CA55_IRQ_MASK11 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_m_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_m_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_m(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_m_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_m_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK12 - CA55_IRQ_MASK12 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK12_m_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK12_m_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK12_m(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK12_m_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK12_m_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK - CM7_IRQ_MASK0..CM7_IRQ_MASK7 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_m_MASK    (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_m_SHIFT   (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_m(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_m_MASK)
/*! @} */

/* The count of BLK_CTRL_S_AONMIX_CM7_IRQ_MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_COUNT     (8U)

/*! @name CM7_IRQ_MASK8 - CM7_IRQ_MASK8 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_m_MASK   (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_m_SHIFT  (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_m(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_m_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK9 - CM7_IRQ_MASK9 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_m_MASK   (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_m_SHIFT  (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_m(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_m_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK10 - CM7_IRQ_MASK10 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_m_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_m_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_m(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_m_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK11 - CM7_IRQ_MASK11 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_m_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_m_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_m(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_m_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK12 - CM7_IRQ_MASK12 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK12_m_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK12_m_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK12_m(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK12_m_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK12_m_MASK)
/*! @} */

/*! @name INITSVTOR - M33 restart secure address */
/*! @{ */

#define BLK_CTRL_S_AONMIX_INITSVTOR_m33_MASK     (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_INITSVTOR_m33_SHIFT    (0U)
/*! m33 - INITSVTOR */
#define BLK_CTRL_S_AONMIX_INITSVTOR_m33(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_INITSVTOR_m33_SHIFT)) & BLK_CTRL_S_AONMIX_INITSVTOR_m33_MASK)
/*! @} */

/*! @name INITNSVTOR - M33 restart non-secure address */
/*! @{ */

#define BLK_CTRL_S_AONMIX_INITNSVTOR_m33_MASK    (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_INITNSVTOR_m33_SHIFT   (0U)
/*! m33 - INITSVTOR */
#define BLK_CTRL_S_AONMIX_INITNSVTOR_m33(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_INITNSVTOR_m33_SHIFT)) & BLK_CTRL_S_AONMIX_INITNSVTOR_m33_MASK)
/*! @} */

/*! @name INITVTOR - M7 restart address */
/*! @{ */

#define BLK_CTRL_S_AONMIX_INITVTOR_M7_MASK       (0xFFFFFF80U)
#define BLK_CTRL_S_AONMIX_INITVTOR_M7_SHIFT      (7U)
/*! M7 - INITVTOR */
#define BLK_CTRL_S_AONMIX_INITVTOR_M7(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_INITVTOR_M7_SHIFT)) & BLK_CTRL_S_AONMIX_INITVTOR_M7_MASK)
/*! @} */

/*! @name M33_CFG - M33 Configure Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK      (0x4U)
#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT_SHIFT     (2U)
/*! WAIT - M33 CPU WAIT */
#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_CFG_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_MASK  (0x18U)
#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_SHIFT (3U)
/*! TCM_SIZE - M33 TCM SIZE
 *  0b00..Regular TCM, 256KB Code TCM and 256KB Sys TCM
 *  0b01..Double Code TCM, 512KB Code TCM
 *  0b10..Double Sys TCM, 512KB Sys TCM
 *  0b11..Reserved
 */
#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_SHIFT)) & BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_MASK)
/*! @} */

/*! @name M7_CFG - M7 Configure Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_MASK   (0x7U)
#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_SHIFT  (0U)
/*! TCM_SIZE - M7 TCM SIZE
 *  0b000..Regular TCM, 256KB ITCM, and 256KB DTCM
 *  0b001..Double ITCM, 512KB ITCM
 *  0b010..Double DTCM, 512KB DTCM
 *  0b011..Reserved
 *  0b100..HALF ITCM, 128KB ITCM, and 384KB DTCM
 *  0b101..HALF DTCM, 384KB ITCM, and 128KB DTCM
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_MASK)

#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT_MASK       (0x10U)
#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT_SHIFT      (4U)
/*! WAIT - M7 CPUWAIT */
#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_SHIFT (5U)
/*! CORECLK_FORCE_ON - Force CM7 core clock on
 *  0b0..CM7 core clock is off when CM7 is sleeping
 *  0b1..CM7 core clock is on when CM7 is sleeping
 */
#define BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_MASK)

#define BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_SHIFT (6U)
/*! HCLK_FORCE_ON - CM7 platform AHB clock enable
 *  0b0..AHB clock is not running (gated) when CM7 is sleeping and TCM is not accessible.
 *  0b1..AHB clock is running (enabled) when CM7 is sleeping and TCM is accessible.
 */
#define BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_MASK)
/*! @} */

/*! @name AXBS_AON_CTRL - AXBS_AON_CTRL */
/*! @{ */

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_SHIFT (0U)
/*! FORCE_ROUND_ROBIN - AXBS_AON FORCE_ROUND_ROBIN
 *  0b0..Enable force round robin (default)
 *  0b1..Disable force round robin
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_SHIFT (1U)
/*! M0_HIGH_PRIORITY - M0 High Priority Control Bit
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_SHIFT (2U)
/*! M1_HIGH_PRIORITY - M1 High Priority Control Bit
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_SHIFT (3U)
/*! M2_HIGH_PRIORITY - M2 High Priority Control Bit
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_SHIFT (4U)
/*! M3_HIGH_PRIORITY - M3 High Priority Control Bit
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_SHIFT (5U)
/*! M4_HIGH_PRIORITY - M4 High Priority Control Bit
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_MASK)
/*! @} */

/*! @name DAP_ACCESS_STKYBIT - Dap Access Sticky Bit */
/*! @{ */

#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_SHIFT (0U)
/*! M33 - M33 DAP_ACCESS_STKYBIT
 *  0b0..M33 core cannot be accessed by DAP
 *  0b1..M33 core can be accessed by DAP
 */
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_SHIFT)) & BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_MASK)

#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_SHIFT (1U)
/*! A55 - A55 DAP_ACCESS_STKYBIT
 *  0b0..A55 core cannot be accessed by DAP
 *  0b1..A55 core can be accessed by DAP
 */
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_SHIFT)) & BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_MASK)
/*! @} */

/*! @name LP_HANDSHAKE_ELE - Low Power Handshake for ELE Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_aonmix_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_aonmix_SHIFT (1U)
/*! aonmix - AON domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_aonmix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_aonmix_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_aonmix_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_platform_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_platform_SHIFT (2U)
/*! M33_platform - CM33 platform cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_platform(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_platform_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_platform_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_SHIFT (3U)
/*! ELE - ELE cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_Cameramix_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_Cameramix_SHIFT (5U)
/*! Cameramix - Camera domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_Cameramix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_Cameramix_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_Cameramix_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu0_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu0_SHIFT (7U)
/*! A55_cpu0 - CA55_CPU0 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu1_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu1_SHIFT (8U)
/*! A55_cpu1 - CA55_CPU1 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu2_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu2_SHIFT (9U)
/*! A55_cpu2 - CA55_CPU2 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu3_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu3_SHIFT (10U)
/*! A55_cpu3 - CA55_CPU3 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_cpu3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_platform_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_platform_SHIFT (11U)
/*! A55_platform - CA55_Platform cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_platform(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_platform_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_platform_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ddrmix_top_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ddrmix_top_SHIFT (12U)
/*! ddrmix_top - DDR domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ddrmix_top(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ddrmix_top_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ddrmix_top_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ddr_phy_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ddr_phy_SHIFT (13U)
/*! ddr_phy - DDR PHY cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ddr_phy(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ddr_phy_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ddr_phy_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_display_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_display_SHIFT (14U)
/*! display - Display domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_display(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_display_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_display_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_gpu_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_gpu_SHIFT (15U)
/*! gpu - GPU domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_gpu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_gpu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_gpu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_hsio_top_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_hsio_top_SHIFT (16U)
/*! hsio_top - HSIO domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_hsio_top(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_hsio_top_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_hsio_top_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_hsio_aon_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_hsio_aon_SHIFT (17U)
/*! hsio_aon - HSIO_AON cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_hsio_aon(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_hsio_aon_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_hsio_aon_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_m7mix_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_m7mix_SHIFT (18U)
/*! m7mix - M7 domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_m7mix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_m7mix_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_m7mix_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_netc_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_netc_SHIFT (19U)
/*! netc - NETC domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_netc(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_netc_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_netc_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_noc_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_noc_SHIFT (20U)
/*! noc - NOC cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_noc(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_noc_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_noc_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_npu_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_npu_SHIFT (21U)
/*! npu - NPU cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_npu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_npu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_npu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_vpu_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_vpu_SHIFT (22U)
/*! vpu - VPU cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_vpu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_vpu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_vpu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_top_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_top_SHIFT (23U)
/*! wakeupmix_top - wakeupmix_top cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_top(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_top_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_top_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_jtag_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_jtag_SHIFT (24U)
/*! wakeupmix_jtag - wakeupmix_jtag cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_jtag(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_jtag_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_jtag_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_wdog_3_4_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_wdog_3_4_SHIFT (25U)
/*! wakeupmix_wdog_3_4 - wakeupmix_wdog_3_4 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_wdog_3_4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_wdog_3_4_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_wdog_3_4_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_wdog5_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_wdog5_SHIFT (26U)
/*! wakeupmix_wdog5 - wakeupmix_wdog5 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_wdog5_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_wakeupmix_wdog5_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_aonmix_power_MASK (0x40000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_aonmix_power_SHIFT (30U)
/*! aonmix_power - AON domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_aonmix_power(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_aonmix_power_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_aonmix_power_MASK)
/*! @} */

/*! @name LP_HANDSHAKE2_ELE - Low Power Handshake 2 for ELE Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_cameramix_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_cameramix_SHIFT (0U)
/*! cameramix - Camera domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_cameramix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_cameramix_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_cameramix_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu0_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu0_SHIFT (2U)
/*! A55_cpu0 - CA55_CPU0 low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu1_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu1_SHIFT (3U)
/*! A55_cpu1 - CA55_CPU1 low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu2_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu2_SHIFT (4U)
/*! A55_cpu2 - CA55_CPU2 low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu3_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu3_SHIFT (5U)
/*! A55_cpu3 - CA55_CPU3 low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_cpu3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_platform_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_platform_SHIFT (6U)
/*! A55_platform - CA55_Platform low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_platform(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_platform_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_platform_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_ddr_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_ddr_SHIFT (7U)
/*! ddr - DDR domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_ddr(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_ddr_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_ddr_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_display_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_display_SHIFT (8U)
/*! display - Display domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_display(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_display_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_display_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_gpu_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_gpu_SHIFT (9U)
/*! gpu - GPU domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_gpu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_gpu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_gpu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_hsio_top_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_hsio_top_SHIFT (10U)
/*! hsio_top - HSIO domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_hsio_top(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_hsio_top_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_hsio_top_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_hsio_aon_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_hsio_aon_SHIFT (11U)
/*! hsio_aon - HSIO_AON low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_hsio_aon(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_hsio_aon_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_hsio_aon_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_m7_platform_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_m7_platform_SHIFT (12U)
/*! m7_platform - M7 Platform low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_m7_platform(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_m7_platform_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_m7_platform_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_netc_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_netc_SHIFT (13U)
/*! netc - NETC domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_netc(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_netc_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_netc_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_noc_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_noc_SHIFT (14U)
/*! noc - NOC low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_noc(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_noc_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_noc_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_npu_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_npu_SHIFT (15U)
/*! npu - NPU low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_npu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_npu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_npu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_vpu_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_vpu_SHIFT (16U)
/*! vpu - VPU low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_vpu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_vpu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_vpu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_wakeup_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_wakeup_SHIFT (17U)
/*! wakeup - WAKEUP low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_wakeup(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_wakeup_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_wakeup_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_osc24mhz_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_osc24mhz_SHIFT (20U)
/*! osc24mhz - OSC 24MHz low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_osc24mhz(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_osc24mhz_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_osc24mhz_MASK)
/*! @} */

/*! @name LP_HANDSHAKE_SM - Low Power Handshake for System Manager */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_aonmix_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_aonmix_SHIFT (1U)
/*! aonmix - AON domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_aonmix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_aonmix_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_aonmix_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_platform_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_platform_SHIFT (2U)
/*! M33_platform - CM33 platform cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_platform(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_platform_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_platform_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_SHIFT (3U)
/*! ELE - ELE cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_Cameramix_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_Cameramix_SHIFT (5U)
/*! Cameramix - Camera domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_Cameramix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_Cameramix_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_Cameramix_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu0_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu0_SHIFT (7U)
/*! A55_cpu0 - CA55_CPU0 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu1_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu1_SHIFT (8U)
/*! A55_cpu1 - CA55_CPU1 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu2_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu2_SHIFT (9U)
/*! A55_cpu2 - CA55_CPU2 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu3_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu3_SHIFT (10U)
/*! A55_cpu3 - CA55_CPU3 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_cpu3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_platform_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_platform_SHIFT (11U)
/*! A55_platform - CA55_Platform cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_platform(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_platform_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_platform_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ddrmix_top_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ddrmix_top_SHIFT (12U)
/*! ddrmix_top - DDR domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ddrmix_top(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ddrmix_top_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ddrmix_top_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ddr_phy_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ddr_phy_SHIFT (13U)
/*! ddr_phy - DDR PHY cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ddr_phy(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ddr_phy_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ddr_phy_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_display_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_display_SHIFT (14U)
/*! display - Display domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_display(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_display_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_display_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_gpu_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_gpu_SHIFT (15U)
/*! gpu - GPU domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_gpu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_gpu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_gpu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_hsio_top_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_hsio_top_SHIFT (16U)
/*! hsio_top - HSIO domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_hsio_top(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_hsio_top_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_hsio_top_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_hsio_aon_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_hsio_aon_SHIFT (17U)
/*! hsio_aon - HSIO_AON cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_hsio_aon(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_hsio_aon_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_hsio_aon_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_m7mix_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_m7mix_SHIFT (18U)
/*! m7mix - M7 domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_m7mix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_m7mix_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_m7mix_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_netc_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_netc_SHIFT (19U)
/*! netc - NETC domain cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_netc(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_netc_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_netc_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_noc_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_noc_SHIFT (20U)
/*! noc - NOC cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_noc(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_noc_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_noc_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_npu_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_npu_SHIFT (21U)
/*! npu - NPU cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_npu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_npu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_npu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_vpu_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_vpu_SHIFT (22U)
/*! vpu - VPU cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_vpu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_vpu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_vpu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_top_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_top_SHIFT (23U)
/*! wakeupmix_top - wakeupmix_top cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_top(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_top_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_top_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_jtag_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_jtag_SHIFT (24U)
/*! wakeupmix_jtag - wakeupmix_jtag cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_jtag(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_jtag_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_jtag_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_wdog_3_4_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_wdog_3_4_SHIFT (25U)
/*! wakeupmix_wdog_3_4 - wakeupmix_wdog_3_4 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_wdog_3_4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_wdog_3_4_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_wdog_3_4_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_wdog5_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_wdog5_SHIFT (26U)
/*! wakeupmix_wdog5 - wakeupmix_wdog5 cold reset handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_wdog5_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_wakeupmix_wdog5_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_aonmix_power_MASK (0x40000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_aonmix_power_SHIFT (30U)
/*! aonmix_power - AON domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_aonmix_power(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_aonmix_power_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_aonmix_power_MASK)
/*! @} */

/*! @name LP_HANDSHAKE2_SM - Low Power Handshake 2 for System Manager */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_cameramix_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_cameramix_SHIFT (0U)
/*! cameramix - Camera domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_cameramix(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_cameramix_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_cameramix_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu0_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu0_SHIFT (2U)
/*! A55_cpu0 - CA55_CPU0 low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu1_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu1_SHIFT (3U)
/*! A55_cpu1 - CA55_CPU1 low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu2_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu2_SHIFT (4U)
/*! A55_cpu2 - CA55_CPU2 low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu3_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu3_SHIFT (5U)
/*! A55_cpu3 - CA55_CPU3 low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_cpu3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_platform_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_platform_SHIFT (6U)
/*! A55_platform - CA55_Platform low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_platform(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_platform_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_platform_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_ddr_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_ddr_SHIFT (7U)
/*! ddr - DDR domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_ddr(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_ddr_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_ddr_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_display_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_display_SHIFT (8U)
/*! display - Display domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_display(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_display_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_display_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_gpu_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_gpu_SHIFT (9U)
/*! gpu - GPU domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_gpu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_gpu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_gpu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_hsio_top_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_hsio_top_SHIFT (10U)
/*! hsio_top - HSIO domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_hsio_top(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_hsio_top_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_hsio_top_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_hsio_aon_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_hsio_aon_SHIFT (11U)
/*! hsio_aon - HSIO_AON low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_hsio_aon(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_hsio_aon_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_hsio_aon_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_m7_platform_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_m7_platform_SHIFT (12U)
/*! m7_platform - M7 Platform low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_m7_platform(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_m7_platform_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_m7_platform_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_netc_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_netc_SHIFT (13U)
/*! netc - NETC domain low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_netc(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_netc_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_netc_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_noc_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_noc_SHIFT (14U)
/*! noc - NOC low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_noc(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_noc_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_noc_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_npu_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_npu_SHIFT (15U)
/*! npu - NPU low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_npu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_npu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_npu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_vpu_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_vpu_SHIFT (16U)
/*! vpu - VPU low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_vpu(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_vpu_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_vpu_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_wakeup_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_wakeup_SHIFT (17U)
/*! wakeup - WAKEUP low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_wakeup(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_wakeup_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_wakeup_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_osc24mhz_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_osc24mhz_SHIFT (20U)
/*! osc24mhz - OSC 24MHz low power handshake enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_osc24mhz(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_osc24mhz_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_osc24mhz_MASK)
/*! @} */

/*! @name SM_LP_HANDSHAKE_STATUS - Register interface for system manager to react for the lp_handshake */
/*! @{ */

#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK_SHIFT (0U)
/*! ack - Acknowledge for the lp request
 *  0b0..No acknowledge
 *  0b1..Acknowledge
 */
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK_SHIFT)) & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK_MASK)

#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT_SHIFT (1U)
/*! stat - Status for clock/reset/power
 *  0b0..Off
 *  0b1..On
 */
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_stat(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_stat_SHIFT)) & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_stat_MASK)

#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_MASK (0x1FCU)
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_SHIFT (2U)
/*! idx - ID of the active lp request */
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_idx(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_SHIFT)) & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_MASK)

#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_SHIFT (9U)
/*! autoack - Auto acknowledge enable bit
 *  0b0..Auto acknowledge disabled
 *  0b1..Auto acknowledge enabled
 */
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_SHIFT)) & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_MASK)
/*! @} */

/*! @name CA55_CPUWAIT - CPUWAIT settings for CA55 CPU */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_SHIFT (0U)
/*! CPU0_WAIT - Configure CPU0 in CPU WAIT mode
 *  0b0..Core works normally
 *  0b1..Core stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_SHIFT (1U)
/*! CPU1_WAIT - Configure CPU1 in CPU WAIT mode
 *  0b0..Core works normally
 *  0b1..Core stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_SHIFT (2U)
/*! CPU2_WAIT - Configure CPU2 in CPU WAIT mode
 *  0b0..Core works normally
 *  0b1..Core stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_SHIFT (3U)
/*! CPU3_WAIT - Configure CPU3 in CPU WAIT mode
 *  0b0..Core works normally
 *  0b1..Core stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU4_WAIT_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU4_WAIT_SHIFT (4U)
/*! CPU4_WAIT - Configure CPU4 in CPU WAIT mode
 *  0b0..Core works normally
 *  0b1..Core stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU4_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU4_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU4_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU5_WAIT_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU5_WAIT_SHIFT (5U)
/*! CPU5_WAIT - Configure CPU5 in CPU WAIT mode
 *  0b0..Core works normally
 *  0b1..Core stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU5_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU5_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU5_WAIT_MASK)
/*! @} */

/*! @name CA55_RVBARADDR0_L - CA55_RVBARADDR0_L */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_SHIFT (0U)
/*! ADDR0_L - CA55_RVBARADDR0_L */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR0_H - CA55_RVBARADDR0_H */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_SHIFT (0U)
/*! ADDR0_H - Higher 6 bits of the boot address of CA55 core0 in 64-bit mode */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_MASK)
/*! @} */

/*! @name CA55_RVBARADDR1_L - CA55_RVBARADDR1_L */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_SHIFT (0U)
/*! ADDR1_L - CA55_RVBARADDR1_L */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR1_H - CA55_RVBARADDR1_H */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_SHIFT (0U)
/*! ADDR1_H - CA55_RVBARADDR1_H */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_MASK)
/*! @} */

/*! @name CA55_RVBARADDR2_L - CA55_RVBARADDR2_L */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_L_ADDR2_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_L_ADDR2_L_SHIFT (0U)
/*! ADDR2_L - CA55_RVBARADDR2_L */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_L_ADDR2_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_L_ADDR2_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_L_ADDR2_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR2_H - CA55_RVBARADDR2_H */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_H_ADDR2_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_H_ADDR2_H_SHIFT (0U)
/*! ADDR2_H - CA55_RVBARADDR2_H */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_H_ADDR2_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_H_ADDR2_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_H_ADDR2_H_MASK)
/*! @} */

/*! @name CA55_RVBARADDR3_L - CA55_RVBARADDR3_L */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_L_ADDR3_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_L_ADDR3_L_SHIFT (0U)
/*! ADDR3_L - CA55_RVBARADDR3_L */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_L_ADDR3_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_L_ADDR3_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_L_ADDR3_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR3_H - CA55_RVBARADDR3_H */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_H_ADDR3_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_H_ADDR3_H_SHIFT (0U)
/*! ADDR3_H - CA55_RVBARADDR3_H */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_H_ADDR3_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_H_ADDR3_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_H_ADDR3_H_MASK)
/*! @} */

/*! @name CA55_RVBARADDR4_L - CA55_RVBARADDR4_L */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR4_L_ADDR4_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR4_L_ADDR4_L_SHIFT (0U)
/*! ADDR4_L - CA55_RVBARADDR4_L */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR4_L_ADDR4_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR4_L_ADDR4_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR4_L_ADDR4_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR4_H - CA55_RVBARADDR4_H */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR4_H_ADDR4_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR4_H_ADDR4_H_SHIFT (0U)
/*! ADDR4_H - CA55_RVBARADDR4_H */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR4_H_ADDR4_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR4_H_ADDR4_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR4_H_ADDR4_H_MASK)
/*! @} */

/*! @name CA55_RVBARADDR5_L - CA55_RVBARADDR5_L */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR5_L_ADDR5_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR5_L_ADDR5_L_SHIFT (0U)
/*! ADDR5_L - CA55_RVBARADDR5_L */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR5_L_ADDR5_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR5_L_ADDR5_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR5_L_ADDR5_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR5_H - CA55_RVBARADDR5_H */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR5_H_ADDR5_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR5_H_ADDR5_H_SHIFT (0U)
/*! ADDR5_H - CA55_RVBARADDR5_H */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR5_H_ADDR5_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR5_H_ADDR5_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR5_H_ADDR5_H_MASK)
/*! @} */

/*! @name ELE_IRQ_MASK - Mask bits of ELE interrupt */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet0_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet0_SHIFT (0U)
/*! noclk_fdet0 - Missing ELE clock reset request.
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet0_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet0_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet1_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet1_SHIFT (1U)
/*! noclk_fdet1 - Missing reference clock reset request.
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet1_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet1_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet2_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet2_SHIFT (2U)
/*! noclk_fdet2 - Missing ELE clock reset request.
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet2_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet2_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet3_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet3_SHIFT (3U)
/*! noclk_fdet3 - Missing reference clock reset request.
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet3_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_noclk_fdet3_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_reset_req_32k_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_reset_req_32k_SHIFT (4U)
/*! reset_req_32k - Reset request for missing reference clock.
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_reset_req_32k(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_reset_req_32k_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_reset_req_32k_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_reset_req_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_reset_req_SHIFT (5U)
/*! reset_req - Edgelock enclave reset request, active low
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_reset_req(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_reset_req_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_reset_req_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_sys_fail_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_sys_fail_SHIFT (6U)
/*! sys_fail - System failure, reset chip
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_sys_fail(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_sys_fail_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_sys_fail_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_lc_bricked_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_lc_bricked_SHIFT (7U)
/*! lc_bricked - Lifecycle is in bricked state
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_lc_bricked(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_lc_bricked_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_lc_bricked_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_wdg_reset_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_wdg_reset_SHIFT (9U)
/*! wdg_reset - WDOG reset
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_wdg_reset(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_wdg_reset_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_wdg_reset_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu0a_int_rx_full_mask_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu0a_int_rx_full_mask_SHIFT (16U)
/*! mu0a_int_rx_full_mask - MU0A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu0a_int_rx_full_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu0a_int_rx_full_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu0a_int_rx_full_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu0a_int_tx_empty_mask_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu0a_int_tx_empty_mask_SHIFT (17U)
/*! mu0a_int_tx_empty_mask - MU0A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu0a_int_tx_empty_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu0a_int_tx_empty_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu0a_int_tx_empty_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu1a_int_rx_full_mask_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu1a_int_rx_full_mask_SHIFT (18U)
/*! mu1a_int_rx_full_mask - MU1A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu1a_int_rx_full_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu1a_int_rx_full_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu1a_int_rx_full_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu1a_int_tx_empty_mask_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu1a_int_tx_empty_mask_SHIFT (19U)
/*! mu1a_int_tx_empty_mask - MU1A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu1a_int_tx_empty_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu1a_int_tx_empty_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu1a_int_tx_empty_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu2a_int_rx_full_mask_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu2a_int_rx_full_mask_SHIFT (20U)
/*! mu2a_int_rx_full_mask - MU2A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu2a_int_rx_full_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu2a_int_rx_full_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu2a_int_rx_full_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu2a_int_tx_empty_mask_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu2a_int_tx_empty_mask_SHIFT (21U)
/*! mu2a_int_tx_empty_mask - MU2A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu2a_int_tx_empty_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu2a_int_tx_empty_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu2a_int_tx_empty_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu3a_int_rx_full_mask_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu3a_int_rx_full_mask_SHIFT (22U)
/*! mu3a_int_rx_full_mask - MU3A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu3a_int_rx_full_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu3a_int_rx_full_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu3a_int_rx_full_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu3a_int_tx_empty_mask_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu3a_int_tx_empty_mask_SHIFT (23U)
/*! mu3a_int_tx_empty_mask - MU3A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu3a_int_tx_empty_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu3a_int_tx_empty_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu3a_int_tx_empty_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu4a_int_rx_full_mask_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu4a_int_rx_full_mask_SHIFT (24U)
/*! mu4a_int_rx_full_mask - MU4A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu4a_int_rx_full_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu4a_int_rx_full_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu4a_int_rx_full_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu4a_int_tx_empty_mask_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu4a_int_tx_empty_mask_SHIFT (25U)
/*! mu4a_int_tx_empty_mask - MU4A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu4a_int_tx_empty_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu4a_int_tx_empty_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu4a_int_tx_empty_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu5a_int_rx_full_mask_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu5a_int_rx_full_mask_SHIFT (26U)
/*! mu5a_int_rx_full_mask - MU5A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu5a_int_rx_full_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu5a_int_rx_full_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu5a_int_rx_full_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu5a_int_tx_empty_mask_MASK (0x8000000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu5a_int_tx_empty_mask_SHIFT (27U)
/*! mu5a_int_tx_empty_mask - MU5A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu5a_int_tx_empty_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu5a_int_tx_empty_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_mu5a_int_tx_empty_mask_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_event_sys_mask_MASK (0x10000000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_event_sys_mask_SHIFT (28U)
/*! event_sys_mask - EVENT_SYS reset
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_event_sys_mask(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_event_sys_mask_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_event_sys_mask_MASK)
/*! @} */

/*! @name ELE_RESET_REQ_MASK - Mask bits of ELE reset */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet0_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet0_SHIFT (0U)
/*! noclk_fdet0 - Missing ELE clock reset request.
 *  0b0..Unmask reset request
 *  0b1..Mask reset request
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet0_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet0_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet1_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet1_SHIFT (1U)
/*! noclk_fdet1 - Missing reference clock reset request.
 *  0b0..Unmask reset request
 *  0b1..Mask reset request
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet1_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet1_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet2_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet2_SHIFT (2U)
/*! noclk_fdet2 - Missing ELE clock reset request.
 *  0b0..Unmask reset request
 *  0b1..Mask reset request
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet2_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet2_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet3_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet3_SHIFT (3U)
/*! noclk_fdet3 - Missing reference clock reset request.
 *  0b0..Unmask reset request
 *  0b1..Mask reset request
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet3_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_noclk_fdet3_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_sys_reset_req_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_sys_reset_req_SHIFT (4U)
/*! sys_reset_req - System reset request
 *  0b0..Unmask reset request
 *  0b1..Mask reset request
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_sys_reset_req(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_sys_reset_req_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_sys_reset_req_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_reset_req_32k_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_reset_req_32k_SHIFT (5U)
/*! reset_req_32k - Reset request for missing reference clock.
 *  0b0..Unmask reset request
 *  0b1..Mask reset request
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_reset_req_32k(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_reset_req_32k_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_reset_req_32k_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_reset_req_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_reset_req_SHIFT (6U)
/*! reset_req - Edgelock enclave reset request
 *  0b0..Unmask reset request
 *  0b1..Mask reset request
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_reset_req(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_reset_req_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_reset_req_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_sys_fail_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_sys_fail_SHIFT (7U)
/*! sys_fail - System failure, reset chip
 *  0b0..Unmask reset request
 *  0b1..Mask reset request
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_sys_fail(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_sys_fail_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_sys_fail_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_lc_bricked_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_lc_bricked_SHIFT (8U)
/*! lc_bricked - Lifecycle is bricked state
 *  0b0..Unmask reset request
 *  0b1..Mask reset request
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_lc_bricked(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_lc_bricked_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_lc_bricked_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_wdg_reset_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_wdg_reset_SHIFT (10U)
/*! wdg_reset - Watchdog reset request
 *  0b0..Unmask reset request
 *  0b1..Mask reset request
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_wdg_reset(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_wdg_reset_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_wdg_reset_MASK)
/*! @} */

/*! @name ELE_HALT_STATUS - ELE Halt Status Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_ELE_HALT_ACK_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_ELE_HALT_ACK_SHIFT (0U)
/*! ELE_HALT_ACK - EdgeLock halt and clock status
 *  0b0..Clear EdgeLock halt exit interrupt
 *  0b1..Remove the clear signal. This bit is not self-clearing and need SW to clear.
 */
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_ELE_HALT_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_ELE_HALT_ACK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_ELE_HALT_ACK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_ELE_HALT_EXIT_IRQ_CLR_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_ELE_HALT_EXIT_IRQ_CLR_SHIFT (8U)
/*! ELE_HALT_EXIT_IRQ_CLR - EdgeLock halt exit interrupt clear
 *  0b0..EdgeLock is not fully halted and its clocks must be enabled
 *  0b1..EdgeLock is fully halted indicating clocks may be removed
 */
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_ELE_HALT_EXIT_IRQ_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_ELE_HALT_EXIT_IRQ_CLR_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_ELE_HALT_EXIT_IRQ_CLR_MASK)
/*! @} */

/*! @name CA55_MODE - Control the boot mode of two ca55 cores */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64nAA32_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64nAA32_SHIFT (0U)
/*! AA64nAA32 - core0 initial mode control bit
 *  0b000000..State after reset is AARCH32
 *  0b000001..State after reset is AARCH64
 */
#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64nAA32(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_MODE_AA64nAA32_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_MODE_AA64nAA32_MASK)
/*! @} */

/*! @name NMI_MASK - NMI MASK bits */
/*! @{ */

#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33_MASK     (0x1U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33_SHIFT    (0U)
/*! CM33 - CM33 NMI mask bit
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_CM33_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_CM33_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_CM7_MASK      (0x2U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM7_SHIFT     (1U)
/*! CM7 - CM7 NMI mask
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM7(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_CM7_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_CM7_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_SHIFT (2U)
/*! NMI_PIN_MASK - NMI PIN mask bit
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_SHIFT (3U)
/*! WDG1_NMI_MASK - WDG1 NMI mask bit
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_SHIFT (4U)
/*! WDG2_NMI_MASK - WDG2 NMI mask bit
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_SHIFT (5U)
/*! WDG3_NMI_MASK - WDG3 NMI mask bit
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_SHIFT (6U)
/*! WDG4_NMI_MASK - WDG4 NMI mask bit
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_SHIFT (7U)
/*! WDG5_NMI_MASK - WDG5 NMI mask bit
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_MASK)
/*! @} */

/*! @name NMI_CLR - NMI clear bit */
/*! @{ */

#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33_MASK      (0x1U)
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33_SHIFT     (0U)
/*! CM33 - CM33 NMI clear */
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_CLR_CM33_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_CLR_CM33_MASK)

#define BLK_CTRL_S_AONMIX_NMI_CLR_CM7_MASK       (0x2U)
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM7_SHIFT      (1U)
/*! CM7 - CM7 NMI clear */
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM7(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_CLR_CM7_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_CLR_CM7_MASK)
/*! @} */

/*! @name WDOG_ANY_MASK - Wdog any mask */
/*! @{ */

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog1_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog1_SHIFT (0U)
/*! wdog1 - wdog1 to wdog_any mask bit
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog1_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog1_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_MASK (0X2U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_SHIFT (1U)
/*! wdog2 - wdog2 to wdog_any mask bit
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog3_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog3_SHIFT (2U)
/*! wdog3 - wdog3 to wdog_any mask bit
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog3_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog3_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog4_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog4_SHIFT (3U)
/*! wdog4 - wdog4 to wdog_any mask bit
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog4_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog4_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog5_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog5_SHIFT (4U)
/*! wdog5 - wdog5 to wdog_any mask bit
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog5_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_wdog5_MASK)
/*! @} */

/*! @name MISC_CFG - Miscellaneous Configure Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_MISC_CFG_netc_cfg_ierb_lock_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_MISC_CFG_netc_cfg_ierb_lock_SHIFT (0U)
/*! netc_cfg_ierb_lock - netc.cfg_ierb_lock bit */
#define BLK_CTRL_S_AONMIX_MISC_CFG_netc_cfg_ierb_lock(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_MISC_CFG_netc_cfg_ierb_lock_SHIFT)) & BLK_CTRL_S_AONMIX_MISC_CFG_netc_cfg_ierb_lock_MASK)
/*! @} */

/*! @name ELE_GPO_STATUS - ELE gpo status register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_GPO_STATUS_ELE_GPO_8_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_GPO_STATUS_ELE_GPO_8_SHIFT (0U)
/*! ELE_GPO_8 - ELE GPO status */
#define BLK_CTRL_S_AONMIX_ELE_GPO_STATUS_ELE_GPO_8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_GPO_STATUS_ELE_GPO_8_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_GPO_STATUS_ELE_GPO_8_MASK)
/*! @} */

/*! @name ELE_RST_REQ_STAT - ELE Reset Request Status Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_A_MASK (0xFFFFU)
#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_A_SHIFT (0U)
/*! GROUP_A - Group A CSSI events */
#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_A(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_A_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_A_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_B_MASK (0xFFFF0000U)
#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_B_SHIFT (16U)
/*! GROUP_B - Group B RST events */
#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_B_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_B_MASK)
/*! @} */

/*! @name ELE_IRQ_REQ_STAT - ELE IRQ Request Status Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_MASK (0xFFFFU)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_SHIFT (0U)
/*! GROUP_C - Group C IRQ events */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_S_AONMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_S_AONMIX_Peripheral_Access_Layer */


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


#endif  /* BLK_CTRL_S_AONMIX_H_ */

