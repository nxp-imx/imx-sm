/*
** ###################################################################
**     Processors:          MIMX95_cm33
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX95RM, Internal, November. 2021
**     Version:             rev. 1.0, 2021-11-16
**     Build:               b220818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX95_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-11-16)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MIMX95_M33_CACHE_MCM.h
 * @version 1.0
 * @date 2021-11-16
 * @brief CMSIS Peripheral Access Layer for MIMX95_M33_CACHE_MCM
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_M33_CACHE_MCM_H_)  /* Check if memory map has not been already included */
#define MIMX95_M33_CACHE_MCM_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- M33_CACHE_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup M33_CACHE_MCM_Peripheral_Access_Layer M33_CACHE_MCM Peripheral Access Layer
 * @{
 */

/** M33_CACHE_MCM - Register Layout Typedef */
typedef struct
{
    __IO uint32_t CACHE_ECCR; /**< CACHE ECC Control Register, offset: 0x0 */
    uint8_t RESERVED_0[28];
    __IO uint32_t INT_STATUS;  /**< Interrupt Status Register, offset: 0x20 */
    __IO uint32_t INT_STAT_EN; /**< Interrupt Status Enable Register, offset: 0x24 */
    __IO uint32_t INT_SIG_EN;  /**< Interrupt Enable Register, offset: 0x28 */
    uint8_t RESERVED_1[48];
    __I uint32_t
        CODE_CACHE_ECC_SINGLE_ERROR_INFO; /**< CODE CACHE single bit ECC Error Information Register, offset: 0x5C */
    __I uint32_t
        CODE_CACHE_ECC_SINGLE_ERROR_ADDR; /**< CODE_CACHE single-bit ECC Error Address Register, offset: 0x60 */
    uint8_t RESERVED_2[4];
    __I uint32_t
        CODE_CACHE_ECC_MULTI_ERROR_INFO; /**< CODE CACHE multi-bit ECC Error Information Register, offset: 0x68 */
    uint8_t RESERVED_3[8];
    __I uint32_t
        SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO; /**< SYSTEM CACHE single bit ECC Error Information Register, offset: 0x74 */
    __I uint32_t
        SYSTEM_CACHE_ECC_SINGLE_ERROR_ADDR; /**< SYSTEM_CACHE single-bit ECC Error Address Register, offset: 0x78 */
    uint8_t RESERVED_4[4];
    __I uint32_t
        SYSTEM_CACHE_ECC_MULTI_ERROR_INFO; /**< SYSTEM CACHE multi-bit ECC Error Information Register, offset: 0x80 */
    __I uint32_t SYSTEM_CACHE_ECC_MULTI_ERROR_DATA; /**< SYSTEM CACHE multi-bit ECC Error Data Register, offset: 0x84 */
    uint8_t RESERVED_5[4];
    __IO uint32_t CODE_CACHE_TAG0_ECC_ERROR_INJEC;  /**< CODE CACHE TAG0 ECC Error Injection Register, offset: 0x8C */
    __IO uint32_t CODE_CACHE_TAG1_ECC_ERROR_INJEC;  /**< CODE CACHE TAG0 ECC Error Injection Register, offset: 0x90 */
    __IO uint32_t CODE_CACHE_DATA0_ECC_ERROR_INJEC; /**< CODE CACHE DATA0 ECC Error Injection Register, offset: 0x94 */
    __IO uint32_t CODE_CACHE_DATA1_ECC_ERROR_INJEC; /**< CODE CACHE DATA1 ECC Error Injection Register, offset: 0x98 */
    __IO uint32_t SYTEM_CACHE_TAG0_ECC_ERROR_INJEC; /**< SYSTEM CACHE TAG0 ECC Error Injection Register, offset: 0x9C */
    __IO uint32_t
        SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC; /**< SYSTEM CACHE TAG0 ECC Error Injection Register, offset: 0xA0 */
    __IO uint32_t
        SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC; /**< SYSTEM CACHE DATA0 ECC Error Injection Register, offset: 0xA4 */
    __IO uint32_t
        STSTEM_CACHE_DATA1_ECC_ERROR_INJEC; /**< SYSTEM CACHE DATA1 ECC Error Injection Register, offset: 0xA8 */
} M33_CACHE_MCM_Type;

/* ----------------------------------------------------------------------------
   -- M33_CACHE_MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup M33_CACHE_MCM_Register_Masks M33_CACHE_MCM Register Masks
 * @{
 */

/*! @name CACHE_ECCR - CACHE ECC Control Register */
/*! @{ */

#define M33_CACHE_MCM_CACHE_ECCR_WECC_DIS_MASK  (0x1U)
#define M33_CACHE_MCM_CACHE_ECCR_WECC_DIS_SHIFT (0U)
/*! WECC_DIS - Disable CACHE ECC Write Generation
 *  0b1..Disable ECC generation on CACHE write data
 *  0b0..Enable ECC generation on CACHE write data
 */
#define M33_CACHE_MCM_CACHE_ECCR_WECC_DIS(x) \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CACHE_ECCR_WECC_DIS_SHIFT)) & M33_CACHE_MCM_CACHE_ECCR_WECC_DIS_MASK)

#define M33_CACHE_MCM_CACHE_ECCR_RECC_DIS_MASK  (0x2U)
#define M33_CACHE_MCM_CACHE_ECCR_RECC_DIS_SHIFT (1U)
/*! RECC_DIS - Disable Cache ECC Read Check
 *  0b1..Disable ECC check on CACHE read data
 *  0b0..Enable ECC check on CACHE read data
 */
#define M33_CACHE_MCM_CACHE_ECCR_RECC_DIS(x) \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CACHE_ECCR_RECC_DIS_SHIFT)) & M33_CACHE_MCM_CACHE_ECCR_RECC_DIS_MASK)
/*! @} */

/*! @name INT_STATUS - Interrupt Status Register */
/*! @{ */

#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRM_INT_MASK  (0x100U)
#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRM_INT_SHIFT (8U)
/*! CODE_CACHE_ECC_ERRM_INT - CODE CACHE Access multi-bit ECC Error Interrupt Status
 *  0b0..CODE CACHE multi-bit ECC error does not happen
 *  0b1..CODE CACHE multi-bit ECC error happens.
 */
#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRM_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRM_INT_SHIFT)) & \
     M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRM_INT_MASK)

#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRS_INT_MASK  (0x200U)
#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRS_INT_SHIFT (9U)
/*! CODE_CACHE_ECC_ERRS_INT - CODE CACHE access single-bit ECC Error Interrupt Status
 *  0b0..CODE CACHE single-bit ECC error does not happen
 *  0b1..CODE CACHE single-bit ECC error happens.
 */
#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRS_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRS_INT_SHIFT)) & \
     M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRS_INT_MASK)

#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRM_OVER_INT_MASK  (0x400U)
#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRM_OVER_INT_SHIFT (10U)
/*! CODE_CACHE_ECC_ERRM_OVER_INT - CODE CACHE access more than one multi-bit ECC Error Interrupt Status
 *  0b0..CODE CACHE more than one multi-bit ECC error does not happen
 *  0b1..CODE CACHE more than one multi-bit ECC error happens.
 */
#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRM_OVER_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRM_OVER_INT_SHIFT)) & \
     M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRM_OVER_INT_MASK)

#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRS_OVER_INT_MASK  (0x800U)
#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRS_OVER_INT_SHIFT (11U)
/*! CODE_CACHE_ECC_ERRS_OVER_INT - CODE CACHE access more than one single-bit ECC Error Interrupt Status
 *  0b0..CODE CACHE more than one single-bit ECC error does not happen
 *  0b1..CODE CACHE more than one single-bit ECC error happens.
 */
#define M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRS_OVER_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRS_OVER_INT_SHIFT)) & \
     M33_CACHE_MCM_INT_STATUS_CODE_CACHE_ECC_ERRS_OVER_INT_MASK)

#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRM_INT_MASK  (0x1000U)
#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRM_INT_SHIFT (12U)
/*! SYSTEM_CACHE_ECC_ERRM_INT - SYSTEM CACHE access multi-bit ECC Error Interrupt Status
 *  0b0..SYSTEM CACHE multi-bit ECC error does not happen
 *  0b1..SYSTEM CACHE multi-bit ECC error happens.
 */
#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRM_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRM_INT_SHIFT)) & \
     M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRM_INT_MASK)

#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRS_INT_MASK  (0x2000U)
#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRS_INT_SHIFT (13U)
/*! SYSTEM_CACHE_ECC_ERRS_INT - SYSTEM CACHE access single-bit ECC Error Interrupt Status
 *  0b0..SYSTEM CACHE single-bit ECC error does not happen
 *  0b1..SYSTEM CACHE single-bit ECC error happens.
 */
#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRS_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRS_INT_SHIFT)) & \
     M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRS_INT_MASK)

#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRM_OVER_INT_MASK  (0x4000U)
#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRM_OVER_INT_SHIFT (14U)
/*! SYSTEM_CACHE_ECC_ERRM_OVER_INT - SYSTEM CACHE access more than one multi-bit ECC Error Interrupt Status
 *  0b0..SYSTEM CACHE more than one multi-bit ECC error does not happen
 *  0b1..SYSTEM CACHE more than one multi-bit ECC error happens.
 */
#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRM_OVER_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRM_OVER_INT_SHIFT)) & \
     M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRM_OVER_INT_MASK)

#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRS_OVER_INT_MASK  (0x8000U)
#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRS_OVER_INT_SHIFT (15U)
/*! SYSTEM_CACHE_ECC_ERRS_OVER_INT - SYSTEM CACHE access more than one multi-bit ECC Error Interrupt Status
 *  0b0..SYSTEM CACHE more than single-bit ECC error does not happen
 *  0b1..SYSTEM CACHE more than single-bit ECC error happens.
 */
#define M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRS_OVER_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRS_OVER_INT_SHIFT)) & \
     M33_CACHE_MCM_INT_STATUS_SYSTEM_CACHE_ECC_ERRS_OVER_INT_MASK)
/*! @} */

/*! @name INT_STAT_EN - Interrupt Status Enable Register */
/*! @{ */

#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRM_INT_EN_MASK  (0x100U)
#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRM_INT_EN_SHIFT (8U)
/*! CODE_CACHE_ERRM_INT_EN - CODE CACHE Access multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRM_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRM_INT_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRM_INT_EN_MASK)

#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRS_INT_EN_MASK  (0x200U)
#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRS_INT_EN_SHIFT (9U)
/*! CODE_CACHE_ERRS_INT_EN - CODE CACHE Access single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRS_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRS_INT_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRS_INT_EN_MASK)

#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRM_OVER_INT_EN_MASK  (0x400U)
#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRM_OVER_INT_EN_SHIFT (10U)
/*! CODE_CACHE_ERRM_OVER_INT_EN - CODE CACHE Access more than multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRM_OVER_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRM_OVER_INT_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRM_OVER_INT_EN_MASK)

#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRS_OVER_INT_EN_MASK  (0x800U)
#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRS_OVER_INT_EN_SHIFT (11U)
/*! CODE_CACHE_ERRS_OVER_INT_EN - CODE CACHE Access more than single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRS_OVER_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRS_OVER_INT_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_STAT_EN_CODE_CACHE_ERRS_OVER_INT_EN_MASK)

#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRM_INT_EN_MASK  (0x1000U)
#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRM_INT_EN_SHIFT (12U)
/*! SYSTEM_CACHE_ECC_ERRM_INT_EN - SYSTEM CACHE Access multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRM_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRM_INT_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRM_INT_EN_MASK)

#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRS_INT_EN_MASK  (0x2000U)
#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRS_INT_EN_SHIFT (13U)
/*! SYSTEM_CACHE_ECC_ERRS_INT_EN - SYSTEM CACHE Access single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRS_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRS_INT_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRS_INT_EN_MASK)

#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRM_OVER_INT_EN_MASK  (0x4000U)
#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRM_OVER_INT_EN_SHIFT (14U)
/*! SYSTEM_CACHE_ECC_ERRM_OVER_INT_EN - SYSTEM CACHE Access more than one multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRM_OVER_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRM_OVER_INT_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRM_OVER_INT_EN_MASK)

#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRS_OVER_INT_EN_MASK  (0x8000U)
#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRS_OVER_INT_EN_SHIFT (15U)
/*! SYSTEM_CACHE_ECC_ERRS_OVER_INT_EN - SYSTEM CACHE Access more than one single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRS_OVER_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRS_OVER_INT_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_STAT_EN_SYSTEM_CACHE_ECC_ERRS_OVER_INT_EN_MASK)
/*! @} */

/*! @name INT_SIG_EN - Interrupt Enable Register */
/*! @{ */

#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRM_INT_SIG_EN_MASK  (0x100U)
#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRM_INT_SIG_EN_SHIFT (8U)
/*! CODE_CACHE_ERRM_INT_SIG_EN - CODE CACHE Access multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRM_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRM_INT_SIG_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRM_INT_SIG_EN_MASK)

#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRS_INT_SIG_EN_MASK  (0x200U)
#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRS_INT_SIG_EN_SHIFT (9U)
/*! CODE_CACHE_ERRS_INT_SIG_EN - CODE CACHE Access single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRS_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRS_INT_SIG_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRS_INT_SIG_EN_MASK)

#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRM_OVER_INT_SIG_EN_MASK  (0x400U)
#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRM_OVER_INT_SIG_EN_SHIFT (10U)
/*! CODE_CACHE_ERRM_OVER_INT_SIG_EN - CODE CACHE Access more than one multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRM_OVER_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRM_OVER_INT_SIG_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRM_OVER_INT_SIG_EN_MASK)

#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRS_OVER_INT_SIG_EN_MASK  (0x800U)
#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRS_OVER_INT_SIG_EN_SHIFT (11U)
/*! CODE_CACHE_ERRS_OVER_INT_SIG_EN - CODE CACHE Access more than one single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRS_OVER_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRS_OVER_INT_SIG_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_SIG_EN_CODE_CACHE_ERRS_OVER_INT_SIG_EN_MASK)

#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRM_INT_SIG_EN_MASK  (0x1000U)
#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRM_INT_SIG_EN_SHIFT (12U)
/*! SYSTEM_CACHE_ERRM_INT_SIG_EN - SYSTEM CACHE Access multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRM_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRM_INT_SIG_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRM_INT_SIG_EN_MASK)

#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRS_INT_SIG_EN_MASK  (0x2000U)
#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRS_INT_SIG_EN_SHIFT (13U)
/*! SYSTEM_CACHE_ERRS_INT_SIG_EN - SYSTEM CACHE Access single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRS_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRS_INT_SIG_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRS_INT_SIG_EN_MASK)

#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRM_OVER_INT_SIG_EN_MASK  (0x4000U)
#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRM_OVER_INT_SIG_EN_SHIFT (14U)
/*! SYSTEM_CACHE_ERRM_OVER_INT_SIG_EN - SYSTEM CACHE Access more than one multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRM_OVER_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRM_OVER_INT_SIG_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRM_OVER_INT_SIG_EN_MASK)

#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRS_OVER_INT_SIG_EN_MASK  (0x8000U)
#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRS_OVER_INT_SIG_EN_SHIFT (15U)
/*! SYSTEM_CACHE_ERRS_OVER_INT_SIG_EN - SYSTEM CACHE Access single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRS_OVER_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRS_OVER_INT_SIG_EN_SHIFT)) & \
     M33_CACHE_MCM_INT_SIG_EN_SYSTEM_CACHE_ERRS_OVER_INT_SIG_EN_MASK)
/*! @} */

/*! @name CODE_CACHE_ECC_SINGLE_ERROR_INFO - CODE CACHE single bit ECC Error Information Register */
/*! @{ */

#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_TAG_MASK  (0x1U)
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_TAG_SHIFT (0U)
/*! CODE_CACHE_ECCS_TAG - CODE CACHE single bit ecc error
 *  0b0..tag
 *  0b1..data
 */
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_TAG(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_TAG_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_TAG_MASK)

#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_CMD_MASK  (0x2U)
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_CMD_SHIFT (1U)
/*! CODE_CACHE_ECCS_CMD - CODE CACHE single bit ECC error on cache command
 */
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_CMD(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_CMD_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_CMD_MASK)

#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFMST_MASK  (0xF0U)
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFMST_SHIFT (4U)
/*! CODE_CACHE_ECCS_EFMST - CODE CACHE single bit ECC error master number
 */
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFMST(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFMST_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFMST_MASK)

#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFPRT_MASK  (0x3F00U)
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFPRT_SHIFT (8U)
/*! CODE_CACHE_ECCS_EFPRT - CODE CACHE single bit ECC error prot field
 */
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFPRT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFPRT_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFPRT_MASK)

#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFSYN_MASK  (0x7F0000U)
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFSYN_SHIFT (16U)
/*! CODE_CACHE_ECCS_EFSYN - CODE CACHE single bit ECC error corresponding syndrome
 */
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFSYN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFSYN_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_INFO_CODE_CACHE_ECCS_EFSYN_MASK)
/*! @} */

/*! @name CODE_CACHE_ECC_SINGLE_ERROR_ADDR - CODE_CACHE single-bit ECC Error Address Register */
/*! @{ */

#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_ADDR_CODE_CACHE_ECCS_ERRED_ADDR_MASK  (0xFFFFFFFFU)
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_ADDR_CODE_CACHE_ECCS_ERRED_ADDR_SHIFT (0U)
/*! CODE_CACHE_ECCS_ERRED_ADDR - CODE CACHE single-bit ECC error address
 */
#define M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_ADDR_CODE_CACHE_ECCS_ERRED_ADDR(x)                            \
    (((uint32_t)(                                                                                               \
         ((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_ADDR_CODE_CACHE_ECCS_ERRED_ADDR_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_ECC_SINGLE_ERROR_ADDR_CODE_CACHE_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name CODE_CACHE_ECC_MULTI_ERROR_INFO - CODE CACHE multi-bit ECC Error Information Register */
/*! @{ */

#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_TAG_MASK  (0x1U)
#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_TAG_SHIFT (0U)
/*! CODE_CACHE_ECCM_TAG - CODE CACHE multiple bit ecc error
 *  0b0..tag
 *  0b1..data
 */
#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_TAG(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_TAG_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_TAG_MASK)

#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_CMD_MASK  (0x2U)
#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_CMD_SHIFT (1U)
/*! CODE_CACHE_ECCM_CMD - CODE CACHE multiple bit ECC error on code cache command
 */
#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_CMD(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_CMD_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_CMD_MASK)

#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFMST_MASK  (0xF0U)
#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFMST_SHIFT (4U)
/*! CODE_CACHE_ECCM_EFMST - CODE CACHE multi-bit ECC error master number
 */
#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFMST(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFMST_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFMST_MASK)

#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFPRT_MASK  (0x3F00U)
#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFPRT_SHIFT (8U)
/*! CODE_CACHE_ECCM_EFPRT - CODE CACHE multi-bit ECC error prot field
 */
#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFPRT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFPRT_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFPRT_MASK)

#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFSYN_MASK  (0x7F0000U)
#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFSYN_SHIFT (16U)
/*! CODE_CACHE_ECCM_EFSYN - CODE CACHE multi-bit ECC error corresponding syndrome
 */
#define M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFSYN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFSYN_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_ECC_MULTI_ERROR_INFO_CODE_CACHE_ECCM_EFSYN_MASK)
/*! @} */

/*! @name SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO - SYSTEM CACHE single bit ECC Error Information Register */
/*! @{ */

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_TAG_MASK  (0x1U)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_TAG_SHIFT (0U)
/*! SYSTEM_CACHE_ECCS_TAG - SYSTEM CACHE single bit ecc error
 *  0b0..tag
 *  0b1..data
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_TAG(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_TAG_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_TAG_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_CMD_MASK  (0x2U)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_CMD_SHIFT (1U)
/*! SYSTEM_CACHE_ECCS_CMD - SYSTEM CACHE single bit ECC error on cache command
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_CMD(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_CMD_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_CMD_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFMST_MASK  (0xF0U)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFMST_SHIFT (4U)
/*! SYSTEM_CACHE_ECCS_EFMST - SYSTEM CACHE single bit ECC error master number
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFMST(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFMST_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFMST_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFPRT_MASK  (0x3F00U)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFPRT_SHIFT (8U)
/*! SYSTEM_CACHE_ECCS_EFPRT - SYSTEM CACHE single bit ECC error prot field
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFPRT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFPRT_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFPRT_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFSYN_MASK  (0x7F0000U)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFSYN_SHIFT (16U)
/*! SYSTEM_CACHE_ECCS_EFSYN - SYSTEM CACHE single bit ECC error corresponding syndrome
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFSYN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFSYN_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_INFO_SYSTEM_CACHE_ECCS_EFSYN_MASK)
/*! @} */

/*! @name SYSTEM_CACHE_ECC_SINGLE_ERROR_ADDR - SYSTEM_CACHE single-bit ECC Error Address Register */
/*! @{ */

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_ADDR_SYSTEM_CACHE_ECCS_ERRED_ADDR_MASK  (0xFFFFFFFFU)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_ADDR_SYSTEM_CACHE_ECCS_ERRED_ADDR_SHIFT (0U)
/*! SYSTEM_CACHE_ECCS_ERRED_ADDR - SYSTEM CACHE single-bit ECC error address
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_ADDR_SYSTEM_CACHE_ECCS_ERRED_ADDR(x)                            \
    (((uint32_t)(                                                                                                   \
         ((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_ADDR_SYSTEM_CACHE_ECCS_ERRED_ADDR_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_SINGLE_ERROR_ADDR_SYSTEM_CACHE_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name SYSTEM_CACHE_ECC_MULTI_ERROR_INFO - SYSTEM CACHE multi-bit ECC Error Information Register */
/*! @{ */

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_TAG_MASK  (0x1U)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_TAG_SHIFT (0U)
/*! SYSTEM_CACHE_ECCM_TAG - SYSTEM CACHE multiple bit ecc error
 *  0b0..tag
 *  0b1..data
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_TAG(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_TAG_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_TAG_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_CMD_MASK  (0x2U)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_CMD_SHIFT (1U)
/*! SYSTEM_CACHE_ECCM_CMD - SYSTEM CACHE multiple bit ECC error on SYSTEM CACHE command
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_CMD(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_CMD_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_CMD_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFMST_MASK  (0xF0U)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFMST_SHIFT (4U)
/*! SYSTEM_CACHE_ECCM_EFMST - SYSTEM CACHE multi-bit ECC error master number
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFMST(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFMST_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFMST_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFPRT_MASK  (0x3F00U)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFPRT_SHIFT (8U)
/*! SYSTEM_CACHE_ECCM_EFPRT - SYSTEM CACHE multi-bit ECC error prot field
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFPRT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFPRT_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFPRT_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFSYN_MASK  (0x7F0000U)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFSYN_SHIFT (16U)
/*! SYSTEM_CACHE_ECCM_EFSYN - SYSTEM CACHE multi-bit ECC error corresponding syndrome
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFSYN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFSYN_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_INFO_SYSTEM_CACHE_ECCM_EFSYN_MASK)
/*! @} */

/*! @name SYSTEM_CACHE_ECC_MULTI_ERROR_DATA - SYSTEM CACHE multi-bit ECC Error Data Register */
/*! @{ */

#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_DATA_SYSTEM_CACHE_ECCM_ERRED_DATA_MASK  (0xFFFFFFFFU)
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_DATA_SYSTEM_CACHE_ECCM_ERRED_DATA_SHIFT (0U)
/*! SYSTEM_CACHE_ECCM_ERRED_DATA - SYSTEM CACHE multi-bit ECC error data
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_DATA_SYSTEM_CACHE_ECCM_ERRED_DATA(x)                            \
    (((uint32_t)(                                                                                                  \
         ((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_DATA_SYSTEM_CACHE_ECCM_ERRED_DATA_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_ECC_MULTI_ERROR_DATA_SYSTEM_CACHE_ECCM_ERRED_DATA_MASK)
/*! @} */

/*! @name CODE_CACHE_TAG0_ECC_ERROR_INJEC - CODE CACHE TAG0 ECC Error Injection Register */
/*! @{ */

#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_ERR1BIT_MASK  (0x7FU)
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_ERR1BIT_SHIFT (0U)
/*! CODE_CACHE_TAG0_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC
 * Error injection.
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_ERR1BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_ERR1BIT_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_ERR1BIT_MASK)

#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_ERR2BIT_MASK  (0x7F00U)
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_ERR2BIT_SHIFT (8U)
/*! CODE_CACHE_TAG0_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error.
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_ERR2BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_ERR2BIT_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_ERR2BIT_MASK)

#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FR11BI_MASK  (0x10000U)
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FR11BI_SHIFT (16U)
/*! CODE_CACHE_TAG0_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on CODE CACHE TAG0 write access
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FR11BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FR11BI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FR11BI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FR1NCI_MASK  (0x20000U)
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FR1NCI_SHIFT (17U)
/*! CODE_CACHE_TAG0_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on CODE CACHE TAG0 write
 * access
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FR1NCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FR1NCI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FR1NCI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FRC1BI_MASK  (0x40000U)
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FRC1BI_SHIFT (18U)
/*! CODE_CACHE_TAG0_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on CODE CACHE TAG0 write
 * access
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FRC1BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FRC1BI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FRC1BI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FRCNCI_MASK  (0x80000U)
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FRCNCI_SHIFT (19U)
/*! CODE_CACHE_TAG0_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on CODE CACHE TAG0
 * write access
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FRCNCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FRCNCI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG0_ECC_ERROR_INJEC_CODE_CACHE_TAG0_FRCNCI_MASK)
/*! @} */

/*! @name CODE_CACHE_TAG1_ECC_ERROR_INJEC - CODE CACHE TAG0 ECC Error Injection Register */
/*! @{ */

#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_ERR1BIT_MASK  (0x7FU)
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_ERR1BIT_SHIFT (0U)
/*! CODE_CACHE_TAG1_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC
 * Error injection.
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_ERR1BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_ERR1BIT_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_ERR1BIT_MASK)

#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_ERR2BIT_MASK  (0x7F00U)
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_ERR2BIT_SHIFT (8U)
/*! CODE_CACHE_TAG1_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error.
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_ERR2BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_ERR2BIT_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_ERR2BIT_MASK)

#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FR11BI_MASK  (0x10000U)
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FR11BI_SHIFT (16U)
/*! CODE_CACHE_TAG1_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on CODE CACHE TAG1 write access
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FR11BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FR11BI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FR11BI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FR1NCI_MASK  (0x20000U)
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FR1NCI_SHIFT (17U)
/*! CODE_CACHE_TAG1_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on CODE CACHE TAG1 write
 * access
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FR1NCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FR1NCI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FR1NCI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FRC1BI_MASK  (0x40000U)
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FRC1BI_SHIFT (18U)
/*! CODE_CACHE_TAG1_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on CODE_CACHE_TAG1 write
 * access
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FRC1BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FRC1BI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FRC1BI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FRCNCI_MASK  (0x80000U)
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FRCNCI_SHIFT (19U)
/*! CODE_CACHE_TAG1_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on CODE CACHE TAG1
 * write access
 */
#define M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FRCNCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FRCNCI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_TAG1_ECC_ERROR_INJEC_CODE_CACHE_TAG1_FRCNCI_MASK)
/*! @} */

/*! @name CODE_CACHE_DATA0_ECC_ERROR_INJEC - CODE CACHE DATA0 ECC Error Injection Register */
/*! @{ */

#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_ERR1BIT_MASK  (0x7FU)
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_ERR1BIT_SHIFT (0U)
/*! CODE_CACHE_DATA0_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC
 * Error injection.
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_ERR1BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_ERR1BIT_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_ERR1BIT_MASK)

#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_ERR2BIT_MASK  (0x7F00U)
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_ERR2BIT_SHIFT (8U)
/*! CODE_CACHE_DATA0_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_ERR2BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_ERR2BIT_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_ERR2BIT_MASK)

#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FR11BI_MASK  (0x10000U)
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FR11BI_SHIFT (16U)
/*! CODE_CACHE_DATA0_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on CODE CACHE DATA0 write access
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FR11BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FR11BI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FR11BI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FR1NCI_MASK  (0x20000U)
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FR1NCI_SHIFT (17U)
/*! CODE_CACHE_DATA0_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on CODE CACHE DATA0 write
 * access
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FR1NCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FR1NCI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FR1NCI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FRC1BI_MASK  (0x40000U)
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FRC1BI_SHIFT (18U)
/*! CODE_CACHE_DATA0_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on CODE CACHE DATA0 write
 * access
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FRC1BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FRC1BI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FRC1BI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FRCNCI_MASK  (0x80000U)
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FRCNCI_SHIFT (19U)
/*! CODE_CACHE_DATA0_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on CODE_CACHE_DATA0
 * write access
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FRCNCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FRCNCI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA0_ECC_ERROR_INJEC_CODE_CACHE_DATA0_FRCNCI_MASK)
/*! @} */

/*! @name CODE_CACHE_DATA1_ECC_ERROR_INJEC - CODE CACHE DATA1 ECC Error Injection Register */
/*! @{ */

#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_ERR1BIT_MASK  (0x7FU)
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_ERR1BIT_SHIFT (0U)
/*! CODE_CACHE_DATA1_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC
 * Error injection
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_ERR1BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_ERR1BIT_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_ERR1BIT_MASK)

#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_ERR2BIT_MASK  (0x7F00U)
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_ERR2BIT_SHIFT (8U)
/*! CODE_CACHE_DATA1_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_ERR2BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_ERR2BIT_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_ERR2BIT_MASK)

#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FR11BI_MASK  (0x10000U)
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FR11BI_SHIFT (16U)
/*! CODE_CACHE_DATA1_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on CODE CACHE DATA1 write access
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FR11BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FR11BI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FR11BI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FR1NCI_MASK  (0x20000U)
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FR1NCI_SHIFT (17U)
/*! CODE_CACHE_DATA1_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on CODE CACHE DATA1 write
 * access
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FR1NCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FR1NCI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FR1NCI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FRC1BI_MASK  (0x40000U)
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FRC1BI_SHIFT (18U)
/*! CODE_CACHE_DATA1_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on CODE CACHE DATA1 write
 * access
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FRC1BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FRC1BI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FRC1BI_MASK)

#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FRCNCI_MASK  (0x80000U)
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FRCNCI_SHIFT (19U)
/*! CODE_CACHE_DATA1_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on CODE CACHE DATA1
 * write access
 */
#define M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FRCNCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FRCNCI_SHIFT)) & \
     M33_CACHE_MCM_CODE_CACHE_DATA1_ECC_ERROR_INJEC_CODE_CACHE_DATA1_FRCNCI_MASK)
/*! @} */

/*! @name SYTEM_CACHE_TAG0_ECC_ERROR_INJEC - SYSTEM CACHE TAG0 ECC Error Injection Register */
/*! @{ */

#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_ERR1BIT_MASK  (0x7FU)
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_ERR1BIT_SHIFT (0U)
/*! SYSTEM_CACHE_TAG0_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit
 * ECC Error injection.
 */
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_ERR1BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_ERR1BIT_SHIFT)) & \
     M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_ERR1BIT_MASK)

#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_ERR2BIT_MASK  (0x7F00U)
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_ERR2BIT_SHIFT (8U)
/*! SYSTEM_CACHE_TAG0_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error.
 */
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_ERR2BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_ERR2BIT_SHIFT)) & \
     M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_ERR2BIT_MASK)

#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FR11BI_MASK  (0x10000U)
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FR11BI_SHIFT (16U)
/*! SYSTEM_CACHE_TAG0_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on SYSTEM CACHE TAG0 write access
 */
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FR11BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FR11BI_SHIFT)) & \
     M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FR11BI_MASK)

#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FR1NCI_MASK  (0x20000U)
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FR1NCI_SHIFT (17U)
/*! SYSTEM_CACHE_TAG0_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on SYSTEM CACHE TAG0 write
 * access
 */
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FR1NCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FR1NCI_SHIFT)) & \
     M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FR1NCI_MASK)

#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FRC1BI_MASK  (0x40000U)
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FRC1BI_SHIFT (18U)
/*! SYSTEM_CACHE_TAG0_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on CODE CACHE TAG0 write
 * access
 */
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FRC1BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FRC1BI_SHIFT)) & \
     M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FRC1BI_MASK)

#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FRCNCI_MASK  (0x80000U)
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FRCNCI_SHIFT (19U)
/*! SYSTEM_CACHE_TAG0_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on CODE CACHE TAG0
 * write access
 */
#define M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FRCNCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FRCNCI_SHIFT)) & \
     M33_CACHE_MCM_SYTEM_CACHE_TAG0_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG0_FRCNCI_MASK)
/*! @} */

/*! @name SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC - SYSTEM CACHE TAG0 ECC Error Injection Register */
/*! @{ */

#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_ERR1BIT_MASK  (0x7FU)
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_ERR1BIT_SHIFT (0U)
/*! SYSTEM_CACHE_TAG1_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit
 * ECC Error injection.
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_ERR1BIT(x)                            \
    (((uint32_t)(                                                                                               \
         ((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_ERR1BIT_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_ERR1BIT_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEMCACHE_TAG1_ERR2BIT_MASK  (0x7F00U)
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEMCACHE_TAG1_ERR2BIT_SHIFT (8U)
/*! SYSTEMCACHE_TAG1_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error.
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEMCACHE_TAG1_ERR2BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEMCACHE_TAG1_ERR2BIT_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEMCACHE_TAG1_ERR2BIT_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FR11BI_MASK  (0x10000U)
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FR11BI_SHIFT (16U)
/*! SYSTEM_CACHE_TAG1_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on SYSTEM CACHE TAG1 write access
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FR11BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FR11BI_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FR11BI_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FR1NCI_MASK  (0x20000U)
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FR1NCI_SHIFT (17U)
/*! SYSTEM_CACHE_TAG1_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on SYSTEM CACHE TAG1 write
 * access
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FR1NCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FR1NCI_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FR1NCI_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FRC1BI_MASK  (0x40000U)
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FRC1BI_SHIFT (18U)
/*! SYSTEM_CACHE_TAG1_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on SYSTEM_CACHE_TAG1 write
 * access
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FRC1BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FRC1BI_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FRC1BI_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FRCNCI_MASK  (0x80000U)
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FRCNCI_SHIFT (19U)
/*! SYSTEM_CACHE_TAG1_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on SYSTEM CACHE
 * TAG1 write access
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FRCNCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FRCNCI_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_TAG1_ECC_ERROR_INJEC_SYSTEM_CACHE_TAG1_FRCNCI_MASK)
/*! @} */

/*! @name SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC - SYSTEM CACHE DATA0 ECC Error Injection Register */
/*! @{ */

#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_ERR1BIT_MASK  (0x7FU)
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_ERR1BIT_SHIFT (0U)
/*! SYSTEM_CACHE_DATA0_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit
 * ECC Error injection.
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_ERR1BIT(x)                            \
    (((uint32_t)(                                                                                                 \
         ((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_ERR1BIT_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_ERR1BIT_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_ERR2BIT_MASK  (0x7F00U)
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_ERR2BIT_SHIFT (8U)
/*! SYSTEM_CACHE_DATA0_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_ERR2BIT(x)                            \
    (((uint32_t)(                                                                                                 \
         ((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_ERR2BIT_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_ERR2BIT_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FR11BI_MASK  (0x10000U)
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FR11BI_SHIFT (16U)
/*! SYSTEM_CACHE_DATA0_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on SYSTEM CACHE DATA0 write access
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FR11BI(x)                            \
    (((uint32_t)(                                                                                                \
         ((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FR11BI_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FR11BI_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FR1NCI_MASK  (0x20000U)
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FR1NCI_SHIFT (17U)
/*! SYSTEM_CACHE_DATA0_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on SYSTEM CACHE DATA0 write
 * access
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FR1NCI(x)                            \
    (((uint32_t)(                                                                                                \
         ((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FR1NCI_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FR1NCI_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FRC1BI_MASK  (0x40000U)
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FRC1BI_SHIFT (18U)
/*! SYSTEM_CACHE_DATA0_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on SYSTEM CACHE DATA0
 * write access
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FRC1BI(x)                            \
    (((uint32_t)(                                                                                                \
         ((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FRC1BI_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FRC1BI_MASK)

#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FRCNCI_MASK  (0x80000U)
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FRCNCI_SHIFT (19U)
/*! SYSTEM_CACHE_DATA0_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on SYSTEM CACHE
 * DATA0 write access
 */
#define M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FRCNCI(x)                            \
    (((uint32_t)(                                                                                                \
         ((uint32_t)(x)) << M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FRCNCI_SHIFT)) & \
     M33_CACHE_MCM_SYSTEM_CACHE_DATA0_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA0_FRCNCI_MASK)
/*! @} */

/*! @name STSTEM_CACHE_DATA1_ECC_ERROR_INJEC - SYSTEM CACHE DATA1 ECC Error Injection Register */
/*! @{ */

#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_ERR1BIT_MASK  (0x7FU)
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_ERR1BIT_SHIFT (0U)
/*! SYSTEM_CACHE_DATA1_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit
 * ECC Error injection
 */
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_ERR1BIT(x)                            \
    (((uint32_t)(                                                                                                 \
         ((uint32_t)(x)) << M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_ERR1BIT_SHIFT)) & \
     M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_ERR1BIT_MASK)

#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_ERR2BIT_MASK  (0x7F00U)
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_ERR2BIT_SHIFT (8U)
/*! SYSTEM_CACHE_DATA1_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error
 */
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_ERR2BIT(x)                            \
    (((uint32_t)(                                                                                                 \
         ((uint32_t)(x)) << M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_ERR2BIT_SHIFT)) & \
     M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_ERR2BIT_MASK)

#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FR11BI_MASK  (0x10000U)
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FR11BI_SHIFT (16U)
/*! SYSTEM_CACHE_DATA1_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on SYSTEM CACHE DATA1 write access
 */
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FR11BI(x)                            \
    (((uint32_t)(                                                                                                \
         ((uint32_t)(x)) << M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FR11BI_SHIFT)) & \
     M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FR11BI_MASK)

#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FR1NCI_MASK  (0x20000U)
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FR1NCI_SHIFT (17U)
/*! SYSTEM_CACHE_DATA1_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on SYSTEM CACHE DATA1 write
 * access
 */
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FR1NCI(x)                            \
    (((uint32_t)(                                                                                                \
         ((uint32_t)(x)) << M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FR1NCI_SHIFT)) & \
     M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FR1NCI_MASK)

#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FRC1BI_MASK  (0x40000U)
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FRC1BI_SHIFT (18U)
/*! SYSTEM_CACHE_DATA1_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on SYSTEM CACHE DATA1
 * write access
 */
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FRC1BI(x)                            \
    (((uint32_t)(                                                                                                \
         ((uint32_t)(x)) << M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FRC1BI_SHIFT)) & \
     M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FRC1BI_MASK)

#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FRCNCI_MASK  (0x80000U)
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FRCNCI_SHIFT (19U)
/*! SYSTEM_CACHE_DATA1_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on SYSTEM CACHE
 * DATA1 write access
 */
#define M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FRCNCI(x)                            \
    (((uint32_t)(                                                                                                \
         ((uint32_t)(x)) << M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FRCNCI_SHIFT)) & \
     M33_CACHE_MCM_STSTEM_CACHE_DATA1_ECC_ERROR_INJEC_SYSTEM_CACHE_DATA1_FRCNCI_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group M33_CACHE_MCM_Register_Masks */

/* M33_CACHE_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** Peripheral M33_CACHE_MCM base address */
#define M33_CACHE_MCM_BASE (0x54401000u)
/** Peripheral M33_CACHE_MCM base address */
#define M33_CACHE_MCM_BASE_NS (0x44401000u)
/** Peripheral M33_CACHE_MCM base pointer */
#define M33_CACHE_MCM ((M33_CACHE_MCM_Type *)M33_CACHE_MCM_BASE)
/** Peripheral M33_CACHE_MCM base pointer */
#define M33_CACHE_MCM_NS ((M33_CACHE_MCM_Type *)M33_CACHE_MCM_BASE_NS)
/** Array initializer of M33_CACHE_MCM peripheral base addresses */
#define M33_CACHE_MCM_BASE_ADDRS \
    {                            \
        M33_CACHE_MCM_BASE       \
    }
/** Array initializer of M33_CACHE_MCM peripheral base pointers */
#define M33_CACHE_MCM_BASE_PTRS \
    {                           \
        M33_CACHE_MCM           \
    }
/** Array initializer of M33_CACHE_MCM peripheral base addresses */
#define M33_CACHE_MCM_BASE_ADDRS_NS \
    {                               \
        M33_CACHE_MCM_BASE_NS       \
    }
/** Array initializer of M33_CACHE_MCM peripheral base pointers */
#define M33_CACHE_MCM_BASE_PTRS_NS \
    {                              \
        M33_CACHE_MCM_NS           \
    }
#else
/** Peripheral M33_CACHE_MCM base address */
#define M33_CACHE_MCM_BASE (0x44401000u)
/** Peripheral M33_CACHE_MCM base pointer */
#define M33_CACHE_MCM      ((M33_CACHE_MCM_Type *)M33_CACHE_MCM_BASE)
/** Array initializer of M33_CACHE_MCM peripheral base addresses */
#define M33_CACHE_MCM_BASE_ADDRS \
    {                            \
        M33_CACHE_MCM_BASE       \
    }
/** Array initializer of M33_CACHE_MCM peripheral base pointers */
#define M33_CACHE_MCM_BASE_PTRS \
    {                           \
        M33_CACHE_MCM           \
    }
#endif

/*!
 * @}
 */ /* end of group M33_CACHE_MCM_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_M33_CACHE_MCM_H_) */
