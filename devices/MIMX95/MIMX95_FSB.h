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
 * @file MIMX95_FSB.h
 * @version
 * @date
 * @brief CMSIS Peripheral Access Layer for MIMX95_FSB
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_FSB_H_)  /* Check if memory map has not been already included */
#define MIMX95_FSB_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- FSB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSB_Peripheral_Access_Layer FSB Peripheral Access Layer
 * @{
 */

/** FSB - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[0x8000];
  __IO uint32_t FUSE[8192];                     /**< Fuse Value Registers, offset: 0x8000 */
} FSB_Type;

/* ----------------------------------------------------------------------------
   -- FSB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSB_Register_Masks FSB Register Masks
 * @{
 */

#define FSB_FUSE_HW_CFG0_MARKET_SEGMENT_MASK    (0x3000U)
#define FSB_FUSE_HW_CFG0_MARKET_SEGMENT_SHIFT   (12U)
#define FSB_FUSE_HW_CFG0_MARKET_SEGMENT(x)      (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_HW_CFG0_MARKET_SEGMENT_SHIFT)) & FSB_FUSE_HW_CFG0_MARKET_SEGMENT_MASK)

#define FSB_FUSE_HW_CFG2_PCIE1_DISABLE_MASK     (0x40U)
#define FSB_FUSE_HW_CFG2_PCIE1_DISABLE_SHIFT    (6U)
#define FSB_FUSE_HW_CFG2_PCIE1_DISABLE(x)       (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_HW_CFG2_PCIE1_DISABLE_SHIFT)) & FSB_FUSE_HW_CFG2_PCIE1_DISABLE_MASK)

#define FSB_FUSE_HW_CFG2_PCIE2_DISABLE_MASK     (0x80U)
#define FSB_FUSE_HW_CFG2_PCIE2_DISABLE_SHIFT    (7U)
#define FSB_FUSE_HW_CFG2_PCIE2_DISABLE(x)       (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_HW_CFG2_PCIE2_DISABLE_SHIFT)) & FSB_FUSE_HW_CFG2_PCIE2_DISABLE_MASK)

/*!
 * @}
 */ /* end of group FSB_Register_Masks */

#define FSB_FUSE_HW_CFG0                        17U
#define FSB_FUSE_HW_CFG1                        18U
#define FSB_FUSE_HW_CFG2                        19U
#define FSB_FUSE_ANA_CFG0                       38U
#define FSB_FUSE_ANA_CFG1                       39U
#define FSB_FUSE_ANA_CFG2                       40U
#define FSB_FUSE_ANA_CFG3                       41U

/* FSB - Peripheral instance base addresses */
/** Peripheral FSB base address */
#define FSB_BASE                                (0x47510000u)
/** Peripheral FSB base pointer */
#define FSB                                     ((FSB_Type *)FSB_BASE)
/** Array initializer of FSB peripheral base addresses */
#define FSB_BASE_ADDRS                          { FSB_BASE }
/** Array initializer of FSB peripheral base pointers */
#define FSB_BASE_PTRS                           { FSB }

/*!
 * @}
 */ /* end of group FSB_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_FSB_H_) */
