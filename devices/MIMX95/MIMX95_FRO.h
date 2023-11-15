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
 * @file MIMX95_FRO.h
 * @version
 * @date
 * @brief CMSIS Peripheral Access Layer for MIMX95_FRO
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_FRO_H_)  /* Check if memory map has not been already included */
#define MIMX95_FRO_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- FRO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRO_Peripheral_Access_Layer FRO Peripheral Access Layer
 * @{
 */

/** FRO - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[512];
  struct {                                         /* offset: 0x200 */
    __IO uint32_t RW;                                /**< Control Status, offset: 0x200 */
    __IO uint32_t SET;                               /**< Control Status, offset: 0x204 */
    __IO uint32_t CLR;                               /**< Control Status, offset: 0x208 */
    __IO uint32_t TOG;                               /**< Control Status, offset: 0x20C */
  } CSR;
  struct {                                         /* offset: 0x210 */
    __IO uint32_t RW;                                /**< Trim Configuration 1, offset: 0x210 */
    __IO uint32_t SET;                               /**< Trim Configuration 1, offset: 0x214 */
    __IO uint32_t CLR;                               /**< Trim Configuration 1, offset: 0x218 */
    __IO uint32_t TOG;                               /**< Trim Configuration 1, offset: 0x21C */
  } CNFG1;
  struct {                                         /* offset: 0x220 */
    __IO uint32_t RW;                                /**< Trim Configuration 2, offset: 0x220 */
    __IO uint32_t SET;                               /**< Trim Configuration 2, offset: 0x224 */
    __IO uint32_t CLR;                               /**< Trim Configuration 2, offset: 0x228 */
    __IO uint32_t TOG;                               /**< Trim Configuration 2, offset: 0x22C */
  } CNFG2;
  struct {                                         /* offset: 0x230 */
    __IO uint32_t RW;                                /**< FRO Trim, offset: 0x230 */
    __IO uint32_t SET;                               /**< FRO Trim, offset: 0x234 */
    __IO uint32_t CLR;                               /**< FRO Trim, offset: 0x238 */
    __IO uint32_t TOG;                               /**< FRO Trim, offset: 0x23C */
  } FROTRIM;
  struct {                                         /* offset: 0x240 */
    __IO uint32_t RW;                                /**< FRO Expected Trim Count, offset: 0x240 */
    __IO uint32_t SET;                               /**< FRO Expected Trim Count, offset: 0x244 */
    __IO uint32_t CLR;                               /**< FRO Expected Trim Count, offset: 0x248 */
    __IO uint32_t TOG;                               /**< FRO Expected Trim Count, offset: 0x24C */
  } TEXPCNT;
  struct {                                         /* offset: 0x250 */
    __I  uint32_t RW;                                /**< FRO Auto Tune Trim, offset: 0x250 */
    __I  uint32_t SET;                               /**< FRO Auto Tune Trim, offset: 0x254 */
    __I  uint32_t CLR;                               /**< FRO Auto Tune Trim, offset: 0x258 */
    __I  uint32_t TOG;                               /**< FRO Auto Tune Trim, offset: 0x25C */
  } AUTOTRIM;
  struct {                                         /* offset: 0x260 */
    __I  uint32_t RW;                                /**< FRO Trim Count, offset: 0x260 */
    __I  uint32_t SET;                               /**< FRO Trim Count, offset: 0x264 */
    __I  uint32_t CLR;                               /**< FRO Trim Count, offset: 0x268 */
    __I  uint32_t TOG;                               /**< FRO Trim Count, offset: 0x26C */
  } TRIMCNT;
} FRO_Type;

/* ----------------------------------------------------------------------------
   -- FRO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRO_Register_Masks FRO Register Masks
 * @{
 */

/*! @name CSR - Control Status */
/*! @{ */

#define FRO_CSR_FROEN_MASK                (0x1U)
#define FRO_CSR_FROEN_SHIFT               (0U)
/*! FROEN - FRO Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CSR_FROEN(x)                  (((uint32_t)(((uint32_t)(x)) << FRO_CSR_FROEN_SHIFT)) & FRO_CSR_FROEN_MASK)

#define FRO_CSR_SMODE_MASK                (0x2U)
#define FRO_CSR_SMODE_SHIFT               (1U)
/*! SMODE - Suspend Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CSR_SMODE(x)                  (((uint32_t)(((uint32_t)(x)) << FRO_CSR_SMODE_SHIFT)) & FRO_CSR_SMODE_MASK)

#define FRO_CSR_TREN_MASK                 (0x10U)
#define FRO_CSR_TREN_SHIFT                (4U)
/*! TREN - FRO Trim Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CSR_TREN(x)                   (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TREN_SHIFT)) & FRO_CSR_TREN_MASK)

#define FRO_CSR_TRUPEN_MASK               (0x20U)
#define FRO_CSR_TRUPEN_SHIFT              (5U)
/*! TRUPEN - FRO Autotrim Update Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CSR_TRUPEN(x)                 (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TRUPEN_SHIFT)) & FRO_CSR_TRUPEN_MASK)

#define FRO_CSR_COARSEN_MASK              (0x40U)
#define FRO_CSR_COARSEN_SHIFT             (6U)
/*! COARSEN - Coarse Trim Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CSR_COARSEN(x)                (((uint32_t)(((uint32_t)(x)) << FRO_CSR_COARSEN_SHIFT)) & FRO_CSR_COARSEN_MASK)

#define FRO_CSR_TUNEONCE_MASK             (0x80U)
#define FRO_CSR_TUNEONCE_SHIFT            (7U)
/*! TUNEONCE - Tune Once Control */
#define FRO_CSR_TUNEONCE(x)               (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TUNEONCE_SHIFT)) & FRO_CSR_TUNEONCE_MASK)

#define FRO_CSR_CLKGATE_MASK              (0x1F00U)
#define FRO_CSR_CLKGATE_SHIFT             (8U)
/*! CLKGATE - FRO Clock Gate Enable
 *  0b00000..Disable
 *  0b00001..Enable
 */
#define FRO_CSR_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << FRO_CSR_CLKGATE_SHIFT)) & FRO_CSR_CLKGATE_MASK)

#define FRO_CSR_LOL_ERR_MASK              (0x10000U)
#define FRO_CSR_LOL_ERR_SHIFT             (16U)
/*! LOL_ERR - Loss-of-Lock Error Flag
 *  0b0..Not detected
 *  0b1..Detected
 */
#define FRO_CSR_LOL_ERR(x)                (((uint32_t)(((uint32_t)(x)) << FRO_CSR_LOL_ERR_SHIFT)) & FRO_CSR_LOL_ERR_MASK)

#define FRO_CSR_TUNE_ERR_MASK             (0x20000U)
#define FRO_CSR_TUNE_ERR_SHIFT            (17U)
/*! TUNE_ERR - Tune Error Flag
 *  0b0..Not detected
 *  0b1..Detected
 */
#define FRO_CSR_TUNE_ERR(x)               (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TUNE_ERR_SHIFT)) & FRO_CSR_TUNE_ERR_MASK)

#define FRO_CSR_TRUPREQ_MASK              (0x40000U)
#define FRO_CSR_TRUPREQ_SHIFT             (18U)
/*! TRUPREQ - Trim Update Request Flag
 *  0b0..Not detected
 *  0b1..Detected
 */
#define FRO_CSR_TRUPREQ(x)                (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TRUPREQ_SHIFT)) & FRO_CSR_TRUPREQ_MASK)

#define FRO_CSR_TRIM_LOCK_MASK            (0x1000000U)
#define FRO_CSR_TRIM_LOCK_SHIFT           (24U)
/*! TRIM_LOCK - FRO Trim Lock Flag
 *  0b0..Locked
 *  0b1..Not locked
 */
#define FRO_CSR_TRIM_LOCK(x)              (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TRIM_LOCK_SHIFT)) & FRO_CSR_TRIM_LOCK_MASK)

#define FRO_CSR_TUNEONCE_DONE_MASK        (0x2000000U)
#define FRO_CSR_TUNEONCE_DONE_SHIFT       (25U)
/*! TUNEONCE_DONE - FRO Tune Once Done Flag
 *  0b0..Not complete
 *  0b1..Complete
 */
#define FRO_CSR_TUNEONCE_DONE(x)          (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TUNEONCE_DONE_SHIFT)) & FRO_CSR_TUNEONCE_DONE_MASK)
/*! @} */

/*! @name CNFG1 - Trim Configuration 1 */
/*! @{ */

#define FRO_CNFG1_REFDIV_MASK             (0x7FFU)
#define FRO_CNFG1_REFDIV_SHIFT            (0U)
/*! REFDIV - OSC Reference Clock Divider */
#define FRO_CNFG1_REFDIV(x)               (((uint32_t)(((uint32_t)(x)) << FRO_CNFG1_REFDIV_SHIFT)) & FRO_CNFG1_REFDIV_MASK)

#define FRO_CNFG1_LOL_ERR_IE_MASK         (0x1000U)
#define FRO_CNFG1_LOL_ERR_IE_SHIFT        (12U)
/*! LOL_ERR_IE - Loss-of-Lock Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CNFG1_LOL_ERR_IE(x)           (((uint32_t)(((uint32_t)(x)) << FRO_CNFG1_LOL_ERR_IE_SHIFT)) & FRO_CNFG1_LOL_ERR_IE_MASK)

#define FRO_CNFG1_TUNE_ERR_IE_MASK        (0x2000U)
#define FRO_CNFG1_TUNE_ERR_IE_SHIFT       (13U)
/*! TUNE_ERR_IE - Tune Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CNFG1_TUNE_ERR_IE(x)          (((uint32_t)(((uint32_t)(x)) << FRO_CNFG1_TUNE_ERR_IE_SHIFT)) & FRO_CNFG1_TUNE_ERR_IE_MASK)

#define FRO_CNFG1_TRUPREQ_IE_MASK         (0x4000U)
#define FRO_CNFG1_TRUPREQ_IE_SHIFT        (14U)
/*! TRUPREQ_IE - Trim Update Request Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CNFG1_TRUPREQ_IE(x)           (((uint32_t)(((uint32_t)(x)) << FRO_CNFG1_TRUPREQ_IE_SHIFT)) & FRO_CNFG1_TRUPREQ_IE_MASK)

#define FRO_CNFG1_RFCLKCNT_MASK           (0xFFFF0000U)
#define FRO_CNFG1_RFCLKCNT_SHIFT          (16U)
/*! RFCLKCNT - Reference Clock Counter */
#define FRO_CNFG1_RFCLKCNT(x)             (((uint32_t)(((uint32_t)(x)) << FRO_CNFG1_RFCLKCNT_SHIFT)) & FRO_CNFG1_RFCLKCNT_MASK)
/*! @} */

/*! @name CNFG2 - Trim Configuration 2 */
/*! @{ */

#define FRO_CNFG2_FRODIV_MASK             (0x7U)
#define FRO_CNFG2_FRODIV_SHIFT            (0U)
/*! FRODIV - FRO Clock Divider */
#define FRO_CNFG2_FRODIV(x)               (((uint32_t)(((uint32_t)(x)) << FRO_CNFG2_FRODIV_SHIFT)) & FRO_CNFG2_FRODIV_MASK)

#define FRO_CNFG2_CLKGATE_MASK            (0x10U)
#define FRO_CNFG2_CLKGATE_SHIFT           (4U)
/*! CLKGATE - FRO 8M Clock Gate Enable */
#define FRO_CNFG2_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << FRO_CNFG2_CLKGATE_SHIFT)) & FRO_CNFG2_CLKGATE_MASK)

#define FRO_CNFG2_TRIM1_DELAY_MASK        (0xFFF0000U)
#define FRO_CNFG2_TRIM1_DELAY_SHIFT       (16U)
/*! TRIM1_DELAY - Trim 1 Delay Register */
#define FRO_CNFG2_TRIM1_DELAY(x)          (((uint32_t)(((uint32_t)(x)) << FRO_CNFG2_TRIM1_DELAY_SHIFT)) & FRO_CNFG2_TRIM1_DELAY_MASK)
/*! @} */

/*! @name FROTRIM - FRO Trim */
/*! @{ */

#define FRO_FROTRIM_FINE_TRIM_MASK        (0x7FU)
#define FRO_FROTRIM_FINE_TRIM_SHIFT       (0U)
/*! FINE_TRIM - Fine Trim */
#define FRO_FROTRIM_FINE_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << FRO_FROTRIM_FINE_TRIM_SHIFT)) & FRO_FROTRIM_FINE_TRIM_MASK)

#define FRO_FROTRIM_COARSE_TRIM_MASK      (0xF80U)
#define FRO_FROTRIM_COARSE_TRIM_SHIFT     (7U)
/*! COARSE_TRIM - Coarse Trim */
#define FRO_FROTRIM_COARSE_TRIM(x)        (((uint32_t)(((uint32_t)(x)) << FRO_FROTRIM_COARSE_TRIM_SHIFT)) & FRO_FROTRIM_COARSE_TRIM_MASK)

#define FRO_FROTRIM_TRIMTEMP_MASK         (0x3F0000U)
#define FRO_FROTRIM_TRIMTEMP_SHIFT        (16U)
/*! TRIMTEMP - Trim Temperature */
#define FRO_FROTRIM_TRIMTEMP(x)           (((uint32_t)(((uint32_t)(x)) << FRO_FROTRIM_TRIMTEMP_SHIFT)) & FRO_FROTRIM_TRIMTEMP_MASK)
/*! @} */

/*! @name TEXPCNT - FRO Expected Trim Count */
/*! @{ */

#define FRO_TEXPCNT_TEXPCNT_MASK          (0xFFFFU)
#define FRO_TEXPCNT_TEXPCNT_SHIFT         (0U)
/*! TEXPCNT - Trim Expected Count */
#define FRO_TEXPCNT_TEXPCNT(x)            (((uint32_t)(((uint32_t)(x)) << FRO_TEXPCNT_TEXPCNT_SHIFT)) & FRO_TEXPCNT_TEXPCNT_MASK)

#define FRO_TEXPCNT_TEXPCNT_RANGE_MASK    (0xFF0000U)
#define FRO_TEXPCNT_TEXPCNT_RANGE_SHIFT   (16U)
/*! TEXPCNT_RANGE - Trim Expected Count Range */
#define FRO_TEXPCNT_TEXPCNT_RANGE(x)      (((uint32_t)(((uint32_t)(x)) << FRO_TEXPCNT_TEXPCNT_RANGE_SHIFT)) & FRO_TEXPCNT_TEXPCNT_RANGE_MASK)
/*! @} */

/*! @name AUTOTRIM - FRO Auto Tune Trim */
/*! @{ */

#define FRO_AUTOTRIM_AUTOTRIM_MASK        (0xFFFU)
#define FRO_AUTOTRIM_AUTOTRIM_SHIFT       (0U)
/*! AUTOTRIM - Auto Tune Trim Value */
#define FRO_AUTOTRIM_AUTOTRIM(x)          (((uint32_t)(((uint32_t)(x)) << FRO_AUTOTRIM_AUTOTRIM_SHIFT)) & FRO_AUTOTRIM_AUTOTRIM_MASK)
/*! @} */

/*! @name TRIMCNT - FRO Trim Count */
/*! @{ */

#define FRO_TRIMCNT_TRIMCNT_MASK          (0xFFFFFFFFU)
#define FRO_TRIMCNT_TRIMCNT_SHIFT         (0U)
/*! TRIMCNT - Trim Expected Count */
#define FRO_TRIMCNT_TRIMCNT(x)            (((uint32_t)(((uint32_t)(x)) << FRO_TRIMCNT_TRIMCNT_SHIFT)) & FRO_TRIMCNT_TRIMCNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FRO_Register_Masks */


/* FRO - Peripheral instance base addresses */
/** Peripheral FRO base address */
#define FRO_BASE                         (0x44485000u)
/** Peripheral FRO base pointer */
#define FRO                              ((FRO_Type *)FRO_BASE)
/** Array initializer of FRO peripheral base addresses */
#define FRO_BASE_ADDRS                    { FRO_BASE }
/** Array initializer of FRO peripheral base pointers */
#define FRO_BASE_PTRS                     { FRO }

/*!
 * @}
 */ /* end of group FRO_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_FRO_H_) */
