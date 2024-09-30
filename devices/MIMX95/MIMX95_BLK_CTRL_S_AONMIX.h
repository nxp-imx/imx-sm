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
 * @file MIMX95_BLK_CTRL_S_AONMIX.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for MIMX95_BLK_CTRL_S_AONMIX
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_BLK_CTRL_S_AONMIX_H_)  /* Check if memory map has not been already included */
#define MIMX95_BLK_CTRL_S_AONMIX_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_S_AONMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_S_AONMIX_Peripheral_Access_Layer BLK_CTRL_S_AONMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_S_AONMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CM33_IRQ_MASK0;                    /**< CM33_IRQ_MASK0, offset: 0x0 */
  __IO uint32_t CM33_IRQ_MASK1;                    /**< CM33_IRQ_MASK1, offset: 0x4 */
  __IO uint32_t CM33_IRQ_MASK2;                    /**< CM33_IRQ_MASK2, offset: 0x8 */
  __IO uint32_t CM33_IRQ_MASK3;                    /**< CM33_IRQ_MASK3, offset: 0xC */
  __IO uint32_t CM33_IRQ_MASK4;                    /**< CM33_IRQ_MASK4, offset: 0x10 */
  __IO uint32_t CM33_IRQ_MASK5;                    /**< CM33_IRQ_MASK5, offset: 0x14 */
  __IO uint32_t CM33_IRQ_MASK6;                    /**< CM33_IRQ_MASK6, offset: 0x18 */
  __IO uint32_t CM33_IRQ_MASK7;                    /**< CM33_IRQ_MASK7, offset: 0x1C */
  __IO uint32_t CM33_IRQ_MASK8;                    /**< CM33_IRQ_MASK8, offset: 0x20 */
  __IO uint32_t CM33_IRQ_MASK9;                    /**< CM33_IRQ_MASK9, offset: 0x24 */
  __IO uint32_t CM33_IRQ_MASK10;                   /**< CM33_IRQ_MASK10, offset: 0x28 */
  __IO uint32_t CM33_IRQ_MASK11;                   /**< CM33_IRQ_MASK11, offset: 0x2C */
       uint8_t RESERVED_0[16];
  __IO uint32_t CA55_IRQ_MASK0;                    /**< CA55_IRQ_MASK0, offset: 0x40 */
  __IO uint32_t CA55_IRQ_MASK1;                    /**< CA55_IRQ_MASK1, offset: 0x44 */
  __IO uint32_t CA55_IRQ_MASK2;                    /**< CA55_IRQ_MASK2, offset: 0x48 */
  __IO uint32_t CA55_IRQ_MASK3;                    /**< CA55_IRQ_MASK3, offset: 0x4C */
  __IO uint32_t CA55_IRQ_MASK4;                    /**< CA55_IRQ_MASK4, offset: 0x50 */
  __IO uint32_t CA55_IRQ_MASK5;                    /**< CA55_IRQ_MASK5, offset: 0x54 */
  __IO uint32_t CA55_IRQ_MASK6;                    /**< CA55_IRQ_MASK6, offset: 0x58 */
  __IO uint32_t CA55_IRQ_MASK7;                    /**< CA55_IRQ_MASK7, offset: 0x5C */
  __IO uint32_t CA55_IRQ_MASK8;                    /**< CA55_IRQ_MASK8, offset: 0x60 */
  __IO uint32_t CA55_IRQ_MASK9;                    /**< CA55_IRQ_MASK9, offset: 0x64 */
  __IO uint32_t CA55_IRQ_MASK10;                   /**< CA55_IRQ_MASK10, offset: 0x68 */
  __IO uint32_t CA55_IRQ_MASK11;                   /**< CA55_IRQ_MASK11, offset: 0x6C */
       uint8_t RESERVED_1[16];
  __IO uint32_t CM7_IRQ_MASK0;                     /**< CM7_IRQ_MASK0, offset: 0x80 */
  __IO uint32_t CM7_IRQ_MASK1;                     /**< CM7_IRQ_MASK1, offset: 0x84 */
  __IO uint32_t CM7_IRQ_MASK2;                     /**< CM7_IRQ_MASK2, offset: 0x88 */
  __IO uint32_t CM7_IRQ_MASK3;                     /**< CM7_IRQ_MASK3, offset: 0x8C */
  __IO uint32_t CM7_IRQ_MASK4;                     /**< CM7_IRQ_MASK4, offset: 0x90 */
  __IO uint32_t CM7_IRQ_MASK5;                     /**< CM7_IRQ_MASK5, offset: 0x94 */
  __IO uint32_t CM7_IRQ_MASK6;                     /**< CM7_IRQ_MASK6, offset: 0x98 */
  __IO uint32_t CM7_IRQ_MASK7;                     /**< CM7_IRQ_MASK7, offset: 0x9C */
  __IO uint32_t CM7_IRQ_MASK8;                     /**< CM7_IRQ_MASK8, offset: 0xA0 */
  __IO uint32_t CM7_IRQ_MASK9;                     /**< CM7_IRQ_MASK9, offset: 0xA4 */
  __IO uint32_t CM7_IRQ_MASK10;                    /**< CM7_IRQ_MASK10, offset: 0xA8 */
  __IO uint32_t CM7_IRQ_MASK11;                    /**< CM7_IRQ_MASK11, offset: 0xAC */
       uint8_t RESERVED_2[80];
  __IO uint32_t INITSVTOR;                         /**< M33 restart secure address, offset: 0x100 */
  __IO uint32_t INITNSVTOR;                        /**< M33 restart non-secure address, offset: 0x104 */
  __IO uint32_t INITVTOR;                          /**< M7restart address, offset: 0x108 */
       uint8_t RESERVED_3[20];
  __IO uint32_t M33_CFG;                           /**< M33 Configure Register, offset: 0x120 */
  __IO uint32_t M7_CFG;                            /**< M7 Configure Register, offset: 0x124 */
       uint8_t RESERVED_4[8];
  __IO uint32_t AXBS_AON_CTRL;                     /**< AXBS_AON_CTRL, offset: 0x130 */
  __IO uint32_t DAP_ACCESS_STKYBIT;                /**< Dap Access Sticky Bit, offset: 0x134 */
  __IO uint32_t LP_HANDSHAKE_ELE;                  /**< Low Power Handshake for ELE Register, offset: 0x138 */
  __IO uint32_t LP_HANDSHAKE2_ELE;                 /**< Low Power Handshake 2 for ELE Register, offset: 0x13C */
  __IO uint32_t LP_HANDSHAKE3_ELE;                 /**< Low Power Handshake 3 for ELE Register, offset: 0x140 */
  __IO uint32_t LP_HANDSHAKE_SM;                   /**< Low Power Handshake for System Manager, offset: 0x144 */
  __IO uint32_t LP_HANDSHAKE2_SM;                  /**< Low Power Handshake 2 for System Manager, offset: 0x148 */
  __IO uint32_t LP_HANDSHAKE3_SM;                  /**< Low Power Handshake 3 for System Manager, offset: 0x14C */
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
  __IO uint32_t S401_IRQ_MASK;                     /**< Mask bits of S401 interrupt, offset: 0x1A0 */
  __IO uint32_t S401_RESET_REQ_MASK;               /**< Mask bits of S401 reset, offset: 0x1A4 */
  __IO uint32_t S401_HALT_STATUS;                  /**< S401 halt status register, offset: 0x1A8 */
  __IO uint32_t CA55_MODE;                         /**< Control the boot mode of two ca55 cores, offset: 0x1AC */
  __IO uint32_t NMI_MASK;                          /**< NMI MASK bits, offset: 0x1B0 */
  __IO uint32_t NMI_CLR;                           /**< NMI clear bit, offset: 0x1B4 */
  __IO uint32_t WDOG_ANY_MASK;                     /**< Wdog any mask, offset: 0x1B8 */
       uint8_t RESERVED_7[4];
  __IO uint32_t MISC_CFG;                          /**< Miscellaneous Configure Register, offset: 0x1C0 */
  __IO uint32_t SW_FAULTS;                         /**< Software Generated Fault Register, offset: 0x1C4 */
  __I  uint32_t S401_GPO_STATUS;                   /**< S401 gpo status register, offset: 0x1C8 */
  __I  uint32_t ELE_RST_REQ_STAT;                  /**< ELE reset request status, offset: 0x1CC */
  __I  uint32_t ELE_IRQ_REQ_STAT;                  /**< ELE IRQ request status, offset: 0x1D0 */
} BLK_CTRL_S_AONMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_S_AONMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_S_AONMIX_Register_Masks BLK_CTRL_S_AONMIX Register Masks
 * @{
 */

/*! @name CM33_IRQ_MASK0 - CM33_IRQ_MASK0 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK0_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK0_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK0_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK0_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK0_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK1 - CM33_IRQ_MASK1 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK1_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK1_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK1_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK1_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK1_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK2 - CM33_IRQ_MASK2 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK2_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK2_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK2_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK2_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK2_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK3 - CM33_IRQ_MASK3 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK3_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK3_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK3_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK3_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK3_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK4 - CM33_IRQ_MASK4 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK4_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK4_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK4_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK4_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK4_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK5 - CM33_IRQ_MASK5 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK5_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK5_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK5_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK5_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK5_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK6 - CM33_IRQ_MASK6 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK6_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK6_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK6_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK6_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK6_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK7 - CM33_IRQ_MASK7 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK7_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK7_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK7_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK7_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK7_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK8 - CM33_IRQ_MASK8 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK9 - CM33_IRQ_MASK9 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK10 - CM33_IRQ_MASK10 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK11 - CM33_IRQ_MASK11 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_M_SHIFT (0U)
/*! m - CM33 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK0 - CA55_IRQ_MASK0 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK0_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK0_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK0_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK0_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK0_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK1 - CA55_IRQ_MASK1 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK1_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK1_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK1_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK1_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK1_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK2 - CA55_IRQ_MASK2 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK2_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK2_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK2_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK2_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK2_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK3 - CA55_IRQ_MASK3 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK3_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK3_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK3_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK3_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK3_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK4 - CA55_IRQ_MASK4 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK4_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK4_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK4_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK4_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK4_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK5 - CA55_IRQ_MASK5 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK5_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK5_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK5_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK5_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK5_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK6 - CA55_IRQ_MASK6 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK7 - CA55_IRQ_MASK7 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK8 - CA55_IRQ_MASK8 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK9 - CA55_IRQ_MASK9 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK10 - CA55_IRQ_MASK10 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK11 - CA55_IRQ_MASK11 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_M_SHIFT (0U)
/*! m - CA55 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK0 - CM7_IRQ_MASK0 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK0_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK0_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK0_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK0_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK0_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK1 - CM7_IRQ_MASK1 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK1_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK1_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK1_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK1_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK1_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK2 - CM7_IRQ_MASK2 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK2_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK2_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK2_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK2_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK2_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK3 - CM7_IRQ_MASK3 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK3_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK3_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK3_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK3_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK3_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK4 - CM7_IRQ_MASK4 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK4_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK4_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK4_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK4_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK4_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK5 - CM7_IRQ_MASK5 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK5_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK5_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK5_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK5_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK5_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK6 - CM7_IRQ_MASK6 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK6_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK6_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK6_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK6_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK6_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK7 - CM7_IRQ_MASK7 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK7_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK7_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK7_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK7_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK7_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK8 - CM7_IRQ_MASK8 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK9 - CM7_IRQ_MASK9 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK10 - CM7_IRQ_MASK10 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK11 - CM7_IRQ_MASK11 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_M_SHIFT (0U)
/*! m - CM7 IRQ MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_M(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_M_MASK)
/*! @} */

/*! @name INITSVTOR - M33 restart secure address */
/*! @{ */

#define BLK_CTRL_S_AONMIX_INITSVTOR_M33_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_INITSVTOR_M33_SHIFT (0U)
/*! m33 - INITSVTOR */
#define BLK_CTRL_S_AONMIX_INITSVTOR_M33(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_INITSVTOR_M33_SHIFT)) & BLK_CTRL_S_AONMIX_INITSVTOR_M33_MASK)
/*! @} */

/*! @name INITNSVTOR - M33 restart non-secure address */
/*! @{ */

#define BLK_CTRL_S_AONMIX_INITNSVTOR_M33_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_INITNSVTOR_M33_SHIFT (0U)
/*! m33 - INITSVTOR */
#define BLK_CTRL_S_AONMIX_INITNSVTOR_M33(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_INITNSVTOR_M33_SHIFT)) & BLK_CTRL_S_AONMIX_INITNSVTOR_M33_MASK)
/*! @} */

/*! @name INITVTOR - M7restart address */
/*! @{ */

#define BLK_CTRL_S_AONMIX_INITVTOR_M7_MASK   (0xFFFFFF80U)
#define BLK_CTRL_S_AONMIX_INITVTOR_M7_SHIFT  (7U)
/*! M7 - INITVTOR */
#define BLK_CTRL_S_AONMIX_INITVTOR_M7(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_INITVTOR_M7_SHIFT)) & BLK_CTRL_S_AONMIX_INITVTOR_M7_MASK)
/*! @} */

/*! @name M33_CFG - M33 Configure Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK  (0x4U)
#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT_SHIFT (2U)
/*! WAIT - M33 CPU WAIT */
#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_CFG_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_MASK (0x18U)
#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_SHIFT (3U)
/*! TCM_SIZE - M33 TCM SIZE
 *  0b11..Reserved
 *  0b10..Double Sys TCM, 512KB Sys TCM
 *  0b01..Double Code TCM, 512KB Code TCM
 *  0b00..Regular TCM, 256KB Code TCM and 256KB Sys TCM
 */
#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_SHIFT)) & BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_MASK)
/*! @} */

/*! @name M7_CFG - M7 Configure Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_MASK (0x7U)
#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_SHIFT (0U)
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
#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_MASK)

#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT_MASK   (0x10U)
#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT_SHIFT  (4U)
/*! WAIT - M7 CPUWAIT */
#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_WAIT_MASK)

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
 *  0b1..High priority
 *  0b0..Default priority
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

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M5_HIGH_PRIORITY_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M5_HIGH_PRIORITY_SHIFT (6U)
/*! M5_HIGH_PRIORITY - M5 High Priority Control Bit
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M5_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M5_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M5_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M6_HIGH_PRIORITY_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M6_HIGH_PRIORITY_SHIFT (7U)
/*! M6_HIGH_PRIORITY - M6 High Priority Control Bit
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M6_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M6_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M6_HIGH_PRIORITY_MASK)
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
 *  0b1..A55 core can be accessed by DAP
 *  0b0..A55 core cannot be accessed by DAP
 */
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_SHIFT)) & BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_MASK)
/*! @} */

/*! @name LP_HANDSHAKE_ELE - Low Power Handshake for ELE Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_SHIFT (1U)
/*! aonmix - AON domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_PLATFORM_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_PLATFORM_SHIFT (2U)
/*! M33_platform - CM33 platform cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_SHIFT (3U)
/*! ELE - ELE cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CAMERAMIX_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CAMERAMIX_SHIFT (5U)
/*! Cameramix - Camera domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CAMERAMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CAMERAMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CAMERAMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU0_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU0_SHIFT (7U)
/*! A55_cpu0 - CA55_CPU0 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU1_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU1_SHIFT (8U)
/*! A55_cpu1 - CA55_CPU1 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU2_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU2_SHIFT (9U)
/*! A55_cpu2 - CA55_CPU2 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU3_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU3_SHIFT (10U)
/*! A55_cpu3 - CA55_CPU3 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU4_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU4_SHIFT (11U)
/*! A55_cpu4 - CA55_CPU4 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU4_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU4_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU5_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU5_SHIFT (12U)
/*! A55_cpu5 - CA55_CPU5 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU5_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU5_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_PLATFORM_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_PLATFORM_SHIFT (13U)
/*! A55_platform - CA55_Platform cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDRMIX_TOP_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDRMIX_TOP_SHIFT (14U)
/*! ddrmix_top - DDR domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDRMIX_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDRMIX_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDRMIX_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDR_PHY_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDR_PHY_SHIFT (15U)
/*! ddr_phy - DDR PHY cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDR_PHY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDR_PHY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDR_PHY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DISPLAY_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DISPLAY_SHIFT (16U)
/*! display - Display domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DISPLAY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DISPLAY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DISPLAY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_GPU_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_GPU_SHIFT (17U)
/*! gpu - GPU domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_GPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_GPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_GPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_TOP_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_TOP_SHIFT (18U)
/*! hsio_top - HSIO domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_AON_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_AON_SHIFT (19U)
/*! hsio_aon - HSIO_AON cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_AON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_AON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M7MIX_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M7MIX_SHIFT (20U)
/*! m7mix - M7 domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M7MIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M7MIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M7MIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NETC_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NETC_SHIFT (21U)
/*! netc - NETC domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NETC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NETC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NETC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NOC_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NOC_SHIFT (22U)
/*! noc - NOC cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NOC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NOC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NOC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NPU_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NPU_SHIFT (23U)
/*! npu - NPU cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_VPU_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_VPU_SHIFT (24U)
/*! vpu - VPU cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_VPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_VPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_VPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_TOP_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_TOP_SHIFT (25U)
/*! wakeupmix_top - wakeupmix_top cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_JTAG_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_JTAG_SHIFT (26U)
/*! wakeupmix_jtag - wakeupmix_jtag cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_JTAG(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_JTAG_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_JTAG_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG_3_4_MASK (0x8000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG_3_4_SHIFT (27U)
/*! wakeupmix_wdog_3_4 - wakeupmix_wdog_3_4 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG_3_4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG_3_4_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG_3_4_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG5_MASK (0x10000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG5_SHIFT (28U)
/*! wakeupmix_wdog5 - wakeupmix_wdog5 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG5_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG5_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_POWER_MASK (0x40000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_POWER_SHIFT (30U)
/*! aonmix_power - AON domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_POWER(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_POWER_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_POWER_MASK)
/*! @} */

/*! @name LP_HANDSHAKE2_ELE - Low Power Handshake 2 for ELE Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_CAMERAMIX_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_CAMERAMIX_SHIFT (0U)
/*! cameramix - Camera domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_CAMERAMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_CAMERAMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_CAMERAMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU0_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU0_SHIFT (2U)
/*! A55_cpu0 - CA55_CPU0 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU1_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU1_SHIFT (3U)
/*! A55_cpu1 - CA55_CPU1 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU2_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU2_SHIFT (4U)
/*! A55_cpu2 - CA55_CPU2 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU3_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU3_SHIFT (5U)
/*! A55_cpu3 - CA55_CPU3 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU4_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU4_SHIFT (6U)
/*! A55_cpu4 - CA55_CPU4 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU4_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU4_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU5_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU5_SHIFT (7U)
/*! A55_cpu5 - CA55_CPU5 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU5_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU5_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_PLATFORM_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_PLATFORM_SHIFT (8U)
/*! A55_platform - CA55_Platform low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DDR_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DDR_SHIFT (9U)
/*! ddr - DDR domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DDR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DDR_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DDR_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DISPLAY_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DISPLAY_SHIFT (10U)
/*! display - Display domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DISPLAY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DISPLAY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DISPLAY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_GPU_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_GPU_SHIFT (11U)
/*! gpu - GPU domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_GPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_GPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_GPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_TOP_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_TOP_SHIFT (12U)
/*! hsio_top - HSIO domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_AON_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_AON_SHIFT (13U)
/*! hsio_aon - HSIO_AON low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_AON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_AON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_M7_PLATFORM_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_M7_PLATFORM_SHIFT (14U)
/*! m7_platform - M7 Platform low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_M7_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_M7_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_M7_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NETC_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NETC_SHIFT (15U)
/*! netc - NETC domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NETC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NETC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NETC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NOC_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NOC_SHIFT (16U)
/*! noc - NOC low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NOC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NOC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NOC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NPU_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NPU_SHIFT (17U)
/*! npu - NPU low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_VPU_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_VPU_SHIFT (18U)
/*! vpu - VPU low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_VPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_VPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_VPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_WAKEUP_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_WAKEUP_SHIFT (19U)
/*! wakeup - WAKEUP low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_WAKEUP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_WAKEUP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_OSC24MHZ_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_OSC24MHZ_SHIFT (20U)
/*! osc24mhz - OSC 24MHz low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_OSC24MHZ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_OSC24MHZ_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_OSC24MHZ_MASK)
/*! @} */

/*! @name LP_HANDSHAKE_SM - Low Power Handshake for System Manager */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_SHIFT (1U)
/*! aonmix - AON domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_PLATFORM_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_PLATFORM_SHIFT (2U)
/*! M33_platform - CM33 platform cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_SHIFT (3U)
/*! ELE - ELE cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_CAMERAMIX_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_CAMERAMIX_SHIFT (5U)
/*! Cameramix - Camera domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_CAMERAMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_CAMERAMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_CAMERAMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU0_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU0_SHIFT (7U)
/*! A55_cpu0 - CA55_CPU0 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU1_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU1_SHIFT (8U)
/*! A55_cpu1 - CA55_CPU1 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU2_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU2_SHIFT (9U)
/*! A55_cpu2 - CA55_CPU2 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU3_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU3_SHIFT (10U)
/*! A55_cpu3 - CA55_CPU3 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU4_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU4_SHIFT (11U)
/*! A55_cpu4 - CA55_CPU4 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU4_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU4_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU5_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU5_SHIFT (12U)
/*! A55_cpu5 - CA55_CPU5 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU5_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU5_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_PLATFORM_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_PLATFORM_SHIFT (13U)
/*! A55_platform - CA55_Platform cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDRMIX_TOP_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDRMIX_TOP_SHIFT (14U)
/*! ddrmix_top - DDR domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDRMIX_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDRMIX_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDRMIX_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDR_PHY_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDR_PHY_SHIFT (15U)
/*! ddr_phy - DDR PHY cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDR_PHY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDR_PHY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDR_PHY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DISPLAY_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DISPLAY_SHIFT (16U)
/*! display - Display domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DISPLAY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DISPLAY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DISPLAY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_GPU_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_GPU_SHIFT (17U)
/*! gpu - GPU domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_GPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_GPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_GPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_TOP_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_TOP_SHIFT (18U)
/*! hsio_top - HSIO domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_AON_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_AON_SHIFT (19U)
/*! hsio_aon - HSIO_AON cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_AON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_AON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M7MIX_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M7MIX_SHIFT (20U)
/*! m7mix - M7 domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M7MIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M7MIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M7MIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NETC_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NETC_SHIFT (21U)
/*! netc - NETC domain cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NETC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NETC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NETC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NOC_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NOC_SHIFT (22U)
/*! noc - NOC cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NOC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NOC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NOC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NPU_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NPU_SHIFT (23U)
/*! npu - NPU cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_VPU_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_VPU_SHIFT (24U)
/*! vpu - VPU cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_VPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_VPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_VPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_TOP_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_TOP_SHIFT (25U)
/*! wakeupmix_top - wakeupmix_top cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_JTAG_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_JTAG_SHIFT (26U)
/*! wakeupmix_jtag - wakeupmix_jtag cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_JTAG(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_JTAG_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_JTAG_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG_3_4_MASK (0x8000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG_3_4_SHIFT (27U)
/*! wakeupmix_wdog_3_4 - wakeupmix_wdog_3_4 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG_3_4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG_3_4_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG_3_4_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG5_MASK (0x10000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG5_SHIFT (28U)
/*! wakeupmix_wdog5 - wakeupmix_wdog5 cold reset handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG5_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG5_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_POWER_MASK (0x40000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_POWER_SHIFT (30U)
/*! aonmix_power - AON domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_POWER(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_POWER_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_POWER_MASK)
/*! @} */

/*! @name LP_HANDSHAKE2_SM - Low Power Handshake 2 for System Manager */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_CAMERAMIX_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_CAMERAMIX_SHIFT (0U)
/*! cameramix - Camera domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_CAMERAMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_CAMERAMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_CAMERAMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU0_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU0_SHIFT (2U)
/*! A55_cpu0 - CA55_CPU0 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU1_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU1_SHIFT (3U)
/*! A55_cpu1 - CA55_CPU1 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU2_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU2_SHIFT (4U)
/*! A55_cpu2 - CA55_CPU2 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU3_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU3_SHIFT (5U)
/*! A55_cpu3 - CA55_CPU3 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU4_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU4_SHIFT (6U)
/*! A55_cpu4 - CA55_CPU4 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU4_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU4_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU5_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU5_SHIFT (7U)
/*! A55_cpu5 - CA55_CPU5 low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU5_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU5_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_PLATFORM_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_PLATFORM_SHIFT (8U)
/*! A55_platform - CA55_Platform low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DDR_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DDR_SHIFT (9U)
/*! ddr - DDR domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DDR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DDR_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DDR_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DISPLAY_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DISPLAY_SHIFT (10U)
/*! display - Display domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DISPLAY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DISPLAY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DISPLAY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_GPU_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_GPU_SHIFT (11U)
/*! gpu - GPU domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_GPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_GPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_GPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_TOP_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_TOP_SHIFT (12U)
/*! hsio_top - HSIO domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_AON_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_AON_SHIFT (13U)
/*! hsio_aon - HSIO_AON low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_AON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_AON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_M7_PLATFORM_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_M7_PLATFORM_SHIFT (14U)
/*! m7_platform - M7 Platform low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_M7_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_M7_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_M7_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NETC_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NETC_SHIFT (15U)
/*! netc - NETC domain low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NETC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NETC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NETC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NOC_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NOC_SHIFT (16U)
/*! noc - NOC low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NOC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NOC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NOC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NPU_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NPU_SHIFT (17U)
/*! npu - NPU low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_VPU_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_VPU_SHIFT (18U)
/*! vpu - VPU low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_VPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_VPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_VPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_WAKEUP_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_WAKEUP_SHIFT (19U)
/*! wakeup - WAKEUP low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_WAKEUP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_WAKEUP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_OSC24MHZ_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_OSC24MHZ_SHIFT (20U)
/*! osc24mhz - OSC 24MHz low power handshake enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_OSC24MHZ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_OSC24MHZ_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_OSC24MHZ_MASK)
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
 *  0b1..On
 *  0b0..Off
 */
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT_SHIFT)) & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT_MASK)

#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_MASK (0x1FCU)
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_SHIFT (2U)
/*! idx - ID of the active lp request */
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_SHIFT)) & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_MASK)

#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_SHIFT (9U)
/*! autoack - Auto acknowledge enable bit
 *  0b1..Auto acknowledge enabled
 *  0b0..Auto acknowledge disabled
 */
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_SHIFT)) & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_MASK)
/*! @} */

/*! @name CA55_CPUWAIT - CPUWAIT settings for CA55 CPU */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_SHIFT (0U)
/*! CPU0_WAIT - Configure CPU0 in CPU WAIT mode
 *  0b1..Core stops working
 *  0b0..Core works normally
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_SHIFT (1U)
/*! CPU1_WAIT - Configure CPU1 in CPU WAIT mode
 *  0b1..Core stops working
 *  0b0..Core works normally
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_SHIFT (2U)
/*! CPU2_WAIT - Configure CPU2 in CPU WAIT mode
 *  0b1..Core stops working
 *  0b0..Core works normally
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_SHIFT (3U)
/*! CPU3_WAIT - Configure CPU3 in CPU WAIT mode
 *  0b1..Core stops working
 *  0b0..Core works normally
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU4_WAIT_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU4_WAIT_SHIFT (4U)
/*! CPU4_WAIT - Configure CPU4 in CPU WAIT mode
 *  0b1..Core stops working
 *  0b0..Core works normally
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

/*! @name S401_IRQ_MASK - Mask bits of S401 interrupt */
/*! @{ */

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET0_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET0_SHIFT (0U)
/*! noclk_fdet0 - No clock for FDET0
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET0_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET0_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET1_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET1_SHIFT (1U)
/*! noclk_fdet1 - No clock for FDET1
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET1_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET1_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET2_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET2_SHIFT (2U)
/*! noclk_fdet2 - No clock for FDET2
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET2_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET2_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET3_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET3_SHIFT (3U)
/*! noclk_fdet3 - No clock for FDET3
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET3_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_NOCLK_FDET3_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_32K_RESET_REQ_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_32K_RESET_REQ_SHIFT (4U)
/*! lmda_32k_reset_req - Request Edgelock reset from 32 KHz clock domain
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_32K_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_32K_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_32K_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_RESET_REQ_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_RESET_REQ_SHIFT (5U)
/*! lmda_reset_req - Request Edgelock reset, active low
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_SYS_FAIL_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_SYS_FAIL_SHIFT (6U)
/*! lmda_sys_fail - System failure, reset chip or Edgelock
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_SYS_FAIL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_SYS_FAIL_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LMDA_SYS_FAIL_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LC_BRICKED_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LC_BRICKED_SHIFT (7U)
/*! lc_bricked - LMDA lifecycle is in bricked state
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LC_BRICKED(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LC_BRICKED_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_LC_BRICKED_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_PUF_RESET_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_PUF_RESET_SHIFT (8U)
/*! puf_reset - PUF reset
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_PUF_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_PUF_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_PUF_RESET_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_WDG_RESET_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_WDG_RESET_SHIFT (9U)
/*! wdg_reset - WDOG reset
 *  0b1..Mask interrupt
 *  0b0..Unmask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_WDG_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_WDG_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_WDG_RESET_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU0A_INT_RX_FULL_MASK_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU0A_INT_RX_FULL_MASK_SHIFT (16U)
/*! mu0a_int_rx_full_mask - MU0A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU0A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU0A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU0A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU0A_INT_TX_EMPTY_MASK_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU0A_INT_TX_EMPTY_MASK_SHIFT (17U)
/*! mu0a_int_tx_empty_mask - MU0A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU0A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU0A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU0A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU1A_INT_RX_FULL_MASK_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU1A_INT_RX_FULL_MASK_SHIFT (18U)
/*! mu1a_int_rx_full_mask - MU1A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU1A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU1A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU1A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU1A_INT_TX_EMPTY_MASK_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU1A_INT_TX_EMPTY_MASK_SHIFT (19U)
/*! mu1a_int_tx_empty_mask - MU1A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU1A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU1A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU1A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU2A_INT_RX_FULL_MASK_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU2A_INT_RX_FULL_MASK_SHIFT (20U)
/*! mu2a_int_rx_full_mask - MU2A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU2A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU2A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU2A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU2A_INT_TX_EMPTY_MASK_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU2A_INT_TX_EMPTY_MASK_SHIFT (21U)
/*! mu2a_int_tx_empty_mask - MU2A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU2A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU2A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU2A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU3A_INT_RX_FULL_MASK_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU3A_INT_RX_FULL_MASK_SHIFT (22U)
/*! mu3a_int_rx_full_mask - MU3A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU3A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU3A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU3A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU3A_INT_TX_EMPTY_MASK_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU3A_INT_TX_EMPTY_MASK_SHIFT (23U)
/*! mu3a_int_tx_empty_mask - MU3A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU3A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU3A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU3A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU4A_INT_RX_FULL_MASK_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU4A_INT_RX_FULL_MASK_SHIFT (24U)
/*! mu4a_int_rx_full_mask - MU4A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU4A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU4A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU4A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU4A_INT_TX_EMPTY_MASK_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU4A_INT_TX_EMPTY_MASK_SHIFT (25U)
/*! mu4a_int_tx_empty_mask - MU4A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU4A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU4A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU4A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU5A_INT_RX_FULL_MASK_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU5A_INT_RX_FULL_MASK_SHIFT (26U)
/*! mu5a_int_rx_full_mask - MU5A interrupt Rx full
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU5A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU5A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU5A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU5A_INT_TX_EMPTY_MASK_MASK (0x8000000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU5A_INT_TX_EMPTY_MASK_SHIFT (27U)
/*! mu5a_int_tx_empty_mask - MU5A interrupt Tx empty
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU5A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU5A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_MU5A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_EVENT_SYS_MASK_MASK (0x10000000U)
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_EVENT_SYS_MASK_SHIFT (28U)
/*! event_sys_mask - EVENT_SYS reset
 *  0b0..Unmask interrupt
 *  0b1..Mask interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_IRQ_MASK_EVENT_SYS_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_IRQ_MASK_EVENT_SYS_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_IRQ_MASK_EVENT_SYS_MASK_MASK)
/*! @} */

/*! @name S401_RESET_REQ_MASK - Mask bits of S401 reset */
/*! @{ */

#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET0_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET0_SHIFT (0U)
/*! noclk_fdet0 - No clock FDET0
 *  0b0..Unmask reset request
 *  0b1..Mask reset request
 */
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET0_SHIFT)) & BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET0_MASK)

#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET1_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET1_SHIFT (1U)
/*! noclk_fdet1 - No clock FDET1
 *  0b1..Mask reset request
 *  0b0..Unmask reset request
 */
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET1_SHIFT)) & BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET1_MASK)

#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET2_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET2_SHIFT (2U)
/*! noclk_fdet2 - No clock FDET2
 *  0b1..Mask reset request
 *  0b0..Unmask reset request
 */
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET2_SHIFT)) & BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET2_MASK)

#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET3_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET3_SHIFT (3U)
/*! noclk_fdet3 - No clock FDET3
 *  0b1..Mask reset request
 *  0b0..Unmask reset request
 */
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET3_SHIFT)) & BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_NOCLK_FDET3_MASK)

#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_SYS_RESET_REQ_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_SYS_RESET_REQ_SHIFT (4U)
/*! sys_reset_req - System reset request
 *  0b1..Mask reset request
 *  0b0..Unmask reset request
 */
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_SYS_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_SYS_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_SYS_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_32K_RESET_REQ_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_32K_RESET_REQ_SHIFT (5U)
/*! lmda_32k_reset_req - Request Edgelock reset from 32 KHz clock domain, active low, interrupt request
 *  0b1..Mask reset request
 *  0b0..Unmask reset request
 */
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_32K_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_32K_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_32K_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_RESET_REQ_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_RESET_REQ_SHIFT (6U)
/*! lmda_reset_req - Request Edgelock reset, active low, interrupt request
 *  0b1..Mask reset request
 *  0b0..Unmask reset request
 */
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_SYS_FAIL_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_SYS_FAIL_SHIFT (7U)
/*! lmda_sys_fail - System failure, reset chip or Edgelock
 *  0b1..Mask reset request
 *  0b0..Unmask reset request
 */
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_SYS_FAIL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_SYS_FAIL_SHIFT)) & BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LMDA_SYS_FAIL_MASK)

#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LC_BRICKED_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LC_BRICKED_SHIFT (8U)
/*! lc_bricked - LMDA lifecycle is bricked state
 *  0b1..Mask reset request
 *  0b0..Unmask reset request
 */
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LC_BRICKED(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LC_BRICKED_SHIFT)) & BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_LC_BRICKED_MASK)

#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_PUF_RESET_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_PUF_RESET_SHIFT (9U)
/*! puf_reset - PUF reset request
 *  0b1..Mask reset request
 *  0b0..Unmask reset request
 */
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_PUF_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_PUF_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_PUF_RESET_MASK)

#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_WDG_RESET_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_WDG_RESET_SHIFT (10U)
/*! wdg_reset - Watchdog reset request
 *  0b1..Mask reset request
 *  0b0..Unmask reset request
 */
#define BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_WDG_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_WDG_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_S401_RESET_REQ_MASK_WDG_RESET_MASK)
/*! @} */

/*! @name S401_HALT_STATUS - S401 halt status register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_S401_HALT_STATUS_S401_HALT_ACK_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_S401_HALT_STATUS_S401_HALT_ACK_SHIFT (0U)
/*! S401_HALT_ACK - EdgeLock halt and clock status
 *  0b1..Remove the clear signal. This bit is not self-clearing and need SW to clear.
 *  0b0..Clear EdgeLock halt exit interrupt
 */
#define BLK_CTRL_S_AONMIX_S401_HALT_STATUS_S401_HALT_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_HALT_STATUS_S401_HALT_ACK_SHIFT)) & BLK_CTRL_S_AONMIX_S401_HALT_STATUS_S401_HALT_ACK_MASK)

#define BLK_CTRL_S_AONMIX_S401_HALT_STATUS_S401_HALT_EXIT_IRQ_CLR_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_S401_HALT_STATUS_S401_HALT_EXIT_IRQ_CLR_SHIFT (8U)
/*! S401_HALT_EXIT_IRQ_CLR - EdgeLock halt exit interrupt clear
 *  0b0..EdgeLock is not fully halted and its clocks must be enabled
 *  0b1..EdgeLock is fully halted indicating clocks may be removed
 */
#define BLK_CTRL_S_AONMIX_S401_HALT_STATUS_S401_HALT_EXIT_IRQ_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_HALT_STATUS_S401_HALT_EXIT_IRQ_CLR_SHIFT)) & BLK_CTRL_S_AONMIX_S401_HALT_STATUS_S401_HALT_EXIT_IRQ_CLR_MASK)
/*! @} */

/*! @name CA55_MODE - Control the boot mode of two ca55 cores */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_SHIFT (0U)
/*! AA64nAA32 - core0 initial mode control bit
 *  0b000000..State after reset is AARCH32
 *  0b000001..State after reset is AARCH64
 */
#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_MASK)
/*! @} */

/*! @name NMI_MASK - NMI MASK bits */
/*! @{ */

#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33_SHIFT (0U)
/*! CM33 - CM33 NMI mask bit
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_CM33_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_CM33_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_CM7_MASK  (0x2U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM7_SHIFT (1U)
/*! CM7 - CM7 NMI mask
 *  0b1..NMI is masked
 *  0b0..NMI is usable
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM7(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_CM7_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_CM7_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_SHIFT (2U)
/*! NMI_PIN_MASK - NMI PIN mask bit
 *  0b1..NMI is masked
 *  0b0..NMI is usable
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_SHIFT (3U)
/*! WDG1_NMI_MASK - WDG1 NMI mask bit
 *  0b1..NMI is masked
 *  0b0..NMI is usable
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_SHIFT (4U)
/*! WDG2_NMI_MASK - WDG2 NMI mask bit
 *  0b1..NMI is masked
 *  0b0..NMI is usable
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_SHIFT (5U)
/*! WDG3_NMI_MASK - WDG3 NMI mask bit
 *  0b1..NMI is masked
 *  0b0..NMI is usable
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_SHIFT (6U)
/*! WDG4_NMI_MASK - WDG4 NMI mask bit
 *  0b1..NMI is masked
 *  0b0..NMI is usable
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_SHIFT (7U)
/*! WDG5_NMI_MASK - WDG5 NMI mask bit
 *  0b1..NMI is masked
 *  0b0..NMI is usable
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_MASK)
/*! @} */

/*! @name NMI_CLR - NMI clear bit */
/*! @{ */

#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33_MASK  (0x1U)
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33_SHIFT (0U)
/*! CM33 - CM33 NMI clear */
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_CLR_CM33_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_CLR_CM33_MASK)

#define BLK_CTRL_S_AONMIX_NMI_CLR_CM7_MASK   (0x2U)
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM7_SHIFT  (1U)
/*! CM7 - CM7 NMI clear */
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM7(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_CLR_CM7_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_CLR_CM7_MASK)
/*! @} */

/*! @name WDOG_ANY_MASK - Wdog any mask */
/*! @{ */

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_SHIFT (0U)
/*! wdog1 - wdog1 to wdog_any mask bit
 *  0b1..Mask
 *  0b0..Unmask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_SHIFT (1U)
/*! wdog2 - wdog2 to wdog_any mask bit
 *  0b1..Mask
 *  0b0..Unmask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_SHIFT (2U)
/*! wdog3 - wdog3 to wdog_any mask bit
 *  0b1..Mask
 *  0b0..Unmask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_SHIFT (3U)
/*! wdog4 - wdog4 to wdog_any mask bit
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_SHIFT (4U)
/*! wdog5 - wdog5 to wdog_any mask bit
 *  0b1..Mask
 *  0b0..Unmask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_MASK)
/*! @} */

/*! @name MISC_CFG - Miscellaneous Configure Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_MISC_CFG_NETC_CFG_IERB_LOCK_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_MISC_CFG_NETC_CFG_IERB_LOCK_SHIFT (0U)
/*! netc_cfg_ierb_lock - netc.cfg_ierb_lock bit */
#define BLK_CTRL_S_AONMIX_MISC_CFG_NETC_CFG_IERB_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_MISC_CFG_NETC_CFG_IERB_LOCK_SHIFT)) & BLK_CTRL_S_AONMIX_MISC_CFG_NETC_CFG_IERB_LOCK_MASK)
/*! @} */

/*! @name SW_FAULTS - Software Generated Fault Register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_SW_FAULTS_FCCU_FLT_SWNCF_MASK (0xFFFU)
#define BLK_CTRL_S_AONMIX_SW_FAULTS_FCCU_FLT_SWNCF_SHIFT (0U)
/*! FCCU_FLT_SWNCF - FCCU_FLT_SWNCF bits */
#define BLK_CTRL_S_AONMIX_SW_FAULTS_FCCU_FLT_SWNCF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SW_FAULTS_FCCU_FLT_SWNCF_SHIFT)) & BLK_CTRL_S_AONMIX_SW_FAULTS_FCCU_FLT_SWNCF_MASK)
/*! @} */

/*! @name S401_GPO_STATUS - S401 gpo status register */
/*! @{ */

#define BLK_CTRL_S_AONMIX_S401_GPO_STATUS_S401_GPO_8_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_S401_GPO_STATUS_S401_GPO_8_SHIFT (0U)
/*! S401_GPO_8 - S401 GPO status */
#define BLK_CTRL_S_AONMIX_S401_GPO_STATUS_S401_GPO_8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_S401_GPO_STATUS_S401_GPO_8_SHIFT)) & BLK_CTRL_S_AONMIX_S401_GPO_STATUS_S401_GPO_8_MASK)
/*! @} */

/*! @name ELE_RST_REQ_STAT - ELE reset request status */
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

/*! @name ELE_IRQ_REQ_STAT - ELE IRQ request status */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_MASK (0xFFFFU)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_SHIFT (0U)
/*! GROUP_C - Group C IRQ events */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_S_AONMIX_Register_Masks */


/* BLK_CTRL_S_AONMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_S_AONMIX base address */
#define BLK_CTRL_S_AONMIX_BASE             (0x444F0000u)
/** Peripheral BLK_CTRL_S_AONMIX base pointer */
#define BLK_CTRL_S_AONMIX                  ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX_BASE)
/** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
#define BLK_CTRL_S_AONMIX_BASE_ADDRS         { BLK_CTRL_S_AONMIX_BASE }
/** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
#define BLK_CTRL_S_AONMIX_BASE_PTRS          { BLK_CTRL_S_AONMIX }

/*!
 * @}
 */ /* end of group BLK_CTRL_S_AONMIX_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_BLK_CTRL_S_AONMIX_H_) */
