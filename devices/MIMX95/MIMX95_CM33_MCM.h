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
 * @file MIMX95_CM33_MCM.h
 * @version 1.0
 * @date 2021-11-16
 * @brief CMSIS Peripheral Access Layer for MIMX95_CM33_MCM
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_CM33_MCM_H_)  /* Check if memory map has not been already included */
#define MIMX95_CM33_MCM_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CM33_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CM33_MCM_Peripheral_Access_Layer CM33_MCM Peripheral Access Layer
 * @{
 */

/** CM33_MCM - Register Layout Typedef */
typedef struct
{
    __IO uint32_t ITCMECCR; /**< ITCM ECC Control Register, offset: 0x0 */
    __IO uint32_t TCMECCR;  /**< TCM ECC Control Register, offset: 0x4 */
    uint8_t RESERVED_0[24];
    __IO uint32_t INT_STATUS;  /**< Interrupt Status Register, offset: 0x20 */
    __IO uint32_t INT_STAT_EN; /**< Interrupt Status Enable Register, offset: 0x24 */
    __IO uint32_t INT_SIG_EN;  /**< Interrupt Enable Register, offset: 0x28 */
    uint8_t RESERVED_1[16];
    __I uint32_t ITCM_ECC_SINGLE_ERROR_INFO;     /**< ITCM single-bit ECC Error Information, offset: 0x3C */
    __I uint32_t ITCM_ECC_SINGLE_ERROR_ADDR;     /**< ITCM single-bit ECC Error Address Register, offset: 0x40 */
    __I uint32_t ITCM_ECC_SINGLE_ERROR_DATA_LSB; /**< ITCM single-bit ECC Error Data Register, offset: 0x44 */
    __I uint32_t ITCM_ECC_SINGLE_ERROR_DATA_MSB; /**< ITCM single-bit ECC Error Data Register, offset: 0x48 */
    __I uint32_t ITCM_ECC_MULTI_ERROR_INFO;      /**< ITCM multi-bit ECC Error Information Register, offset: 0x4C */
    __I uint32_t ITCM_ECC_MULTI_ERROR_ADDR;      /**< ITCM multi-bit ECC Error Address Register, offset: 0x50 */
    __I uint32_t ITCM_ECC_MULTI_ERROR_DATA_LSB;  /**< ITCM multi-bit ECC Error Data Register, offset: 0x54 */
    __I uint32_t ITCM_ECC_MULTI_ERROR_DATA_MSB;  /**< ITCM multi-bit ECC Error Data Register, offset: 0x58 */
    __I uint32_t
        CODE_TCM_ECC_SINGLE_ERROR_INFO; /**< CODE_TCM single-bit ECC Error Information Register, offset: 0x5C */
    __I uint32_t CODE_TCM_ECC_SINGLE_ERROR_ADDR; /**< CODE_TCM single-bit ECC Error Address Register, offset: 0x60 */
    __I uint32_t CODE_TCM_ECC_SINGLE_ERROR_DATA; /**< CODE_TCM single-bit ECC Error Data Register, offset: 0x64 */
    __I uint32_t CODE_TCM_ECC_MULTI_ERROR_INFO;  /**< CODE_TCM multi-bit ECC Error Information Register, offset: 0x68 */
    __I uint32_t CODE_TCM_ECC_MULTI_ERROR_ADDR;  /**< CODE_TCM multi-bit ECC Error Address Register, offset: 0x6C */
    __I uint32_t CODE_TCM_ECC_MULTI_ERROR_DATA;  /**< CODE_TCM multi-bit ECC Error Data Register, offset: 0x70 */
    __I uint32_t SYS_TCM_ECC_SINGLE_ERROR_INFO;  /**< SYS_TCM single-bit ECC Error Information Register, offset: 0x74 */
    __I uint32_t SYS_TCM_ECC_SINGLE_ERROR_ADDR;  /**< SYS_TCM single-bit ECC Error Address Register, offset: 0x78 */
    __I uint32_t SYS_TCM_ECC_SINGLE_ERROR_DATA;  /**< SYS_TCM single-bit ECC Error Data Register, offset: 0x7C */
    __I uint32_t SYS_TCM_ECC_MULTI_ERROR_INFO;   /**< SYS_TCM multi-bit ECC Error Information Register, offset: 0x80 */
    __I uint32_t SYS_TCM_ECC_MULTI_ERROR_ADDR;   /**< SYS_TCM multi-bit ECC Error Address Register, offset: 0x84 */
    __I uint32_t SYS_TCM_ECC_MULTI_ERROR_DATA;   /**< SYS_TCM multi-bit ECC Error Data Register, offset: 0x88 */
    uint8_t RESERVED_2[4];
    __IO uint32_t ITCM_ECC_ERROR_INJEC;     /**< ITCM ECC Error Injection Register, offset: 0x90 */
    __IO uint32_t CODE_TCM_ECC_ERROR_INJEC; /**< CODE_TCM ECC Error Injection Register, offset: 0x94 */
    __IO uint32_t SYS_TCM_ECC_ERROR_INJEC;  /**< SYS_TCM ECC Error Injection Register, offset: 0x98 */
} CM33_MCM_Type;

/* ----------------------------------------------------------------------------
   -- CM33_MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CM33_MCM_Register_Masks CM33_MCM Register Masks
 * @{
 */

/*! @name ITCMECCR - ITCM ECC Control Register */
/*! @{ */

#define CM33_MCM_ITCMECCR_WECC_DIS_MASK  (0x1U)
#define CM33_MCM_ITCMECCR_WECC_DIS_SHIFT (0U)
/*! WECC_DIS - Disable ITCM ECC Write Generation
 *  0b1..Disable ECC generation on ITCM write data
 *  0b0..Enable ECC generation on ITCM write data
 */
#define CM33_MCM_ITCMECCR_WECC_DIS(x) \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCMECCR_WECC_DIS_SHIFT)) & CM33_MCM_ITCMECCR_WECC_DIS_MASK)

#define CM33_MCM_ITCMECCR_RECC_DIS_MASK  (0x2U)
#define CM33_MCM_ITCMECCR_RECC_DIS_SHIFT (1U)
/*! RECC_DIS - Disable ITCM ECC Read Check
 *  0b1..Disable ECC check on ITCM read data
 *  0b0..Enable ECC check on ITCM read data
 */
#define CM33_MCM_ITCMECCR_RECC_DIS(x) \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCMECCR_RECC_DIS_SHIFT)) & CM33_MCM_ITCMECCR_RECC_DIS_MASK)
/*! @} */

/*! @name TCMECCR - TCM ECC Control Register */
/*! @{ */

#define CM33_MCM_TCMECCR_WECC_DIS_MASK  (0x1U)
#define CM33_MCM_TCMECCR_WECC_DIS_SHIFT (0U)
/*! WECC_DIS - Disable TCM ECC Write Generation
 *  0b1..Disable ECC generation on TCM write data
 *  0b0..Enable ECC generation on TCM write data
 */
#define CM33_MCM_TCMECCR_WECC_DIS(x) \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_TCMECCR_WECC_DIS_SHIFT)) & CM33_MCM_TCMECCR_WECC_DIS_MASK)

#define CM33_MCM_TCMECCR_RECC_DIS_MASK  (0x2U)
#define CM33_MCM_TCMECCR_RECC_DIS_SHIFT (1U)
/*! RECC_DIS - Disable TCM ECC Read Check
 *  0b1..Disable ECC check on TCM read data
 *  0b0..Enable ECC check on TCM read data
 */
#define CM33_MCM_TCMECCR_RECC_DIS(x) \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_TCMECCR_RECC_DIS_SHIFT)) & CM33_MCM_TCMECCR_RECC_DIS_MASK)
/*! @} */

/*! @name INT_STATUS - Interrupt Status Register */
/*! @{ */

#define CM33_MCM_INT_STATUS_Reserved0_MASK  (0xFFU)
#define CM33_MCM_INT_STATUS_Reserved0_SHIFT (0U)
/*! Reserved0 - Reserved
 */
#define CM33_MCM_INT_STATUS_Reserved0(x) \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STATUS_Reserved0_SHIFT)) & CM33_MCM_INT_STATUS_Reserved0_MASK)

#define CM33_MCM_INT_STATUS_ITCM_ECC_ERRM_INT_MASK  (0x100U)
#define CM33_MCM_INT_STATUS_ITCM_ECC_ERRM_INT_SHIFT (8U)
/*! ITCM_ECC_ERRM_INT - ITCM Access multi-bit ECC Error Interrupt Status
 *  0b0..ITCM multi-bit ECC error does not happen
 *  0b1..ITCM multi-bit ECC error happens.
 */
#define CM33_MCM_INT_STATUS_ITCM_ECC_ERRM_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STATUS_ITCM_ECC_ERRM_INT_SHIFT)) & \
     CM33_MCM_INT_STATUS_ITCM_ECC_ERRM_INT_MASK)

#define CM33_MCM_INT_STATUS_ITCM_ECC_ERRS_INT_MASK  (0x200U)
#define CM33_MCM_INT_STATUS_ITCM_ECC_ERRS_INT_SHIFT (9U)
/*! ITCM_ECC_ERRS_INT - ITCM access single-bit ECC Error Interrupt Status
 *  0b0..ITCM single-bit ECC error does not happen
 *  0b1..ITCM single-bit ECC error happens.
 */
#define CM33_MCM_INT_STATUS_ITCM_ECC_ERRS_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STATUS_ITCM_ECC_ERRS_INT_SHIFT)) & \
     CM33_MCM_INT_STATUS_ITCM_ECC_ERRS_INT_MASK)

#define CM33_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_MASK  (0x400U)
#define CM33_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_SHIFT (10U)
/*! CODE_TCM_ECC_ERRM_INT - CODE_TCM access multi-bit ECC Error Interrupt Status
 *  0b0..CODE_TCM multi-bit ECC error does not happen
 *  0b1..CODE_TCM multi-bit ECC error happens.
 */
#define CM33_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_SHIFT)) & \
     CM33_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_MASK)

#define CM33_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_MASK  (0x800U)
#define CM33_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_SHIFT (11U)
/*! CODE_TCM_ECC_ERRS_INT - CODE_TCM access single-bit ECC Error Interrupt Status
 *  0b0..CODE_TCM single-bit ECC error does not happen
 *  0b1..CODE_TCM single-bit ECC error happens.
 */
#define CM33_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_SHIFT)) & \
     CM33_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_MASK)

#define CM33_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_MASK  (0x1000U)
#define CM33_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_SHIFT (12U)
/*! SYS_TCM_ECC_ERRM_INT - SYS_TCM access multi-bit ECC Error Interrupt Status
 *  0b0..SYS_TCM multi-bit ECC error does not happen
 *  0b1..SYS_TCM multi-bit ECC error happens.
 */
#define CM33_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_SHIFT)) & \
     CM33_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_MASK)

#define CM33_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_MASK  (0x2000U)
#define CM33_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_SHIFT (13U)
/*! SYS_TCM_ECC_ERRS_INT - SYS_TCM access single-bit ECC Error Interrupt Status
 *  0b0..SYS_TCM single-bit ECC error does not happen
 *  0b1..SYS_TCM single-bit ECC error happens.
 */
#define CM33_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_SHIFT)) & \
     CM33_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_MASK)

#define CM33_MCM_INT_STATUS_Reserved_MASK  (0xFFFFC000U)
#define CM33_MCM_INT_STATUS_Reserved_SHIFT (14U)
/*! Reserved - Reserved
 */
#define CM33_MCM_INT_STATUS_Reserved(x) \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STATUS_Reserved_SHIFT)) & CM33_MCM_INT_STATUS_Reserved_MASK)
/*! @} */

/*! @name INT_STAT_EN - Interrupt Status Enable Register */
/*! @{ */

#define CM33_MCM_INT_STAT_EN_Reserved0_MASK  (0xFFU)
#define CM33_MCM_INT_STAT_EN_Reserved0_SHIFT (0U)
/*! Reserved0 - Reserved
 */
#define CM33_MCM_INT_STAT_EN_Reserved0(x) \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STAT_EN_Reserved0_SHIFT)) & CM33_MCM_INT_STAT_EN_Reserved0_MASK)

#define CM33_MCM_INT_STAT_EN_ITCM_ERRM_INT_EN_MASK  (0x100U)
#define CM33_MCM_INT_STAT_EN_ITCM_ERRM_INT_EN_SHIFT (8U)
/*! ITCM_ERRM_INT_EN - ITCM Access multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_STAT_EN_ITCM_ERRM_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STAT_EN_ITCM_ERRM_INT_EN_SHIFT)) & \
     CM33_MCM_INT_STAT_EN_ITCM_ERRM_INT_EN_MASK)

#define CM33_MCM_INT_STAT_EN_ITCM_ERRS_INT_EN_MASK  (0x200U)
#define CM33_MCM_INT_STAT_EN_ITCM_ERRS_INT_EN_SHIFT (9U)
/*! ITCM_ERRS_INT_EN - ITCM Access single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_STAT_EN_ITCM_ERRS_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STAT_EN_ITCM_ERRS_INT_EN_SHIFT)) & \
     CM33_MCM_INT_STAT_EN_ITCM_ERRS_INT_EN_MASK)

#define CM33_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_MASK  (0x400U)
#define CM33_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_SHIFT (10U)
/*! CODE_TCM_ERRM_INT_EN - CODE_TCM Access multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_SHIFT)) & \
     CM33_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_MASK)

#define CM33_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_MASK  (0x800U)
#define CM33_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_SHIFT (11U)
/*! CODE_TCM_ERRS_INT_EN - CODE_TCM Access single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_SHIFT)) & \
     CM33_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_MASK)

#define CM33_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_MASK  (0x1000U)
#define CM33_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_SHIFT (12U)
/*! SYS_TCM_ERRM_INT_EN - SYS_TCM Access multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_SHIFT)) & \
     CM33_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_MASK)

#define CM33_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_MASK  (0x2000U)
#define CM33_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_SHIFT (13U)
/*! SYS_TCM_ERRS_INT_EN - SYS_TCM Access single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_SHIFT)) & \
     CM33_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_MASK)

#define CM33_MCM_INT_STAT_EN_Reserved1_MASK  (0xFFFFC000U)
#define CM33_MCM_INT_STAT_EN_Reserved1_SHIFT (14U)
/*! Reserved1 - Reserved
 */
#define CM33_MCM_INT_STAT_EN_Reserved1(x) \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_STAT_EN_Reserved1_SHIFT)) & CM33_MCM_INT_STAT_EN_Reserved1_MASK)
/*! @} */

/*! @name INT_SIG_EN - Interrupt Enable Register */
/*! @{ */

#define CM33_MCM_INT_SIG_EN_Reserved0_MASK  (0xFFU)
#define CM33_MCM_INT_SIG_EN_Reserved0_SHIFT (0U)
/*! Reserved0 - Reserved
 */
#define CM33_MCM_INT_SIG_EN_Reserved0(x) \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_SIG_EN_Reserved0_SHIFT)) & CM33_MCM_INT_SIG_EN_Reserved0_MASK)

#define CM33_MCM_INT_SIG_EN_ITCM_ERRM_INT_SIG_EN_MASK  (0x100U)
#define CM33_MCM_INT_SIG_EN_ITCM_ERRM_INT_SIG_EN_SHIFT (8U)
/*! ITCM_ERRM_INT_SIG_EN - ITCM Access multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_SIG_EN_ITCM_ERRM_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_SIG_EN_ITCM_ERRM_INT_SIG_EN_SHIFT)) & \
     CM33_MCM_INT_SIG_EN_ITCM_ERRM_INT_SIG_EN_MASK)

#define CM33_MCM_INT_SIG_EN_ITCM_ERRS_INT_SIG_EN_MASK  (0x200U)
#define CM33_MCM_INT_SIG_EN_ITCM_ERRS_INT_SIG_EN_SHIFT (9U)
/*! ITCM_ERRS_INT_SIG_EN - ITCM Access single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_SIG_EN_ITCM_ERRS_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_SIG_EN_ITCM_ERRS_INT_SIG_EN_SHIFT)) & \
     CM33_MCM_INT_SIG_EN_ITCM_ERRS_INT_SIG_EN_MASK)

#define CM33_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_MASK  (0x400U)
#define CM33_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_SHIFT (10U)
/*! CODE_TCM_ERRM_INT_SIG_EN - CODE_TCM Access multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_SHIFT)) & \
     CM33_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_MASK)

#define CM33_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_MASK  (0x800U)
#define CM33_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_SHIFT (11U)
/*! CODE_TCM_ERRS_INT_SIG_EN - CODE_TCM Access single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_SHIFT)) & \
     CM33_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_MASK)

#define CM33_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_MASK  (0x1000U)
#define CM33_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_SHIFT (12U)
/*! SYS_TCM_ERRM_INT_SIG_EN - SYS_TCM Access multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_SHIFT)) & \
     CM33_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_MASK)

#define CM33_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_MASK  (0x2000U)
#define CM33_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_SHIFT (13U)
/*! SYS_TCM_ERRS_INT_SIG_EN - SYS_TCM Access single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define CM33_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_SHIFT)) & \
     CM33_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_MASK)

#define CM33_MCM_INT_SIG_EN_Reserved1_MASK  (0xFFFFC000U)
#define CM33_MCM_INT_SIG_EN_Reserved1_SHIFT (14U)
/*! Reserved1 - Reserved
 */
#define CM33_MCM_INT_SIG_EN_Reserved1(x) \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_INT_SIG_EN_Reserved1_SHIFT)) & CM33_MCM_INT_SIG_EN_Reserved1_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_INFO - ITCM single-bit ECC Error Information */
/*! @{ */

#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_MASK  (0x1U)
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_SHIFT (0U)
/*! ITCM_ECCS_EFW - Read or write of the access
 *  0b0..Read
 *  0b1..Write
 */
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_SHIFT)) & \
     CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_MASK)

#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_MASK  (0xEU)
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_SHIFT (1U)
/*! ITCM_ECCS_EFSIZ - Size of the access
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100-0b111..
 */
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_SHIFT)) & \
     CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_MASK)

#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_MASK  (0xF0U)
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_SHIFT (4U)
/*! ITCM_ECCS_EFMST - Encodes the requestor of the access
 *  0b0000..Instruction fetch.
 *  0b0001..Data access.
 *  0b0010..Vector fetch on automated exception entry.
 *  0b0011..AHB slave access.
 *  0b0100..Debugger access.
 *  0b0101..MBIST access.
 *  0b1001..Software data access from store queue.
 *  0b1011..AHB slave access from store queue.
 *  0b1100..Debugger access from store queue.
 *  0b0110..
 *  0b0111..
 *  0b1000..
 *  0b1010..
 *  0b1101..
 *  0b1110..
 *  0b1111..
 */
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_SHIFT)) & \
     CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_MASK)

#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_MASK  (0xF00U)
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_SHIFT (8U)
/*! ITCM_ECCS_EFPRT - Privilege level of access
 *  0b0000..User
 *  0b0010..Privileged
 *  0b0001..
 *  0b0011-0b1111..
 */
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_SHIFT)) & \
     CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_MASK)

#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSYN_MASK  (0xFF000U)
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSYN_SHIFT (12U)
/*! ITCM_ECCS_EFSYN - ECC syndrome
 */
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSYN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSYN_SHIFT)) & \
     CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSYN_MASK)

#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK  (0xFFF00000U)
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT (20U)
/*! Reserved - Reserved
 */
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT)) & \
     CM33_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_ADDR - ITCM single-bit ECC Error Address Register */
/*! @{ */

#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_MASK  (0xFFFFFFFFU)
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! ITCM_ECCS_ERRED_ADDR - ITCM single-bit ECC error address
 */
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_SHIFT)) & \
     CM33_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_DATA_LSB - ITCM single-bit ECC Error Data Register */
/*! @{ */

#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_MASK  (0xFFFFFFFFU)
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_SHIFT (0U)
/*! ITCM_ECCS_ERRED_DATA_LSB - ITCM single-bit ECC error data [31:0]
 */
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_SHIFT)) & \
     CM33_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_DATA_MSB - ITCM single-bit ECC Error Data Register */
/*! @{ */

#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_MASK  (0xFFFFFFFFU)
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_SHIFT (0U)
/*! ITCM_ECCS_ERRED_DATA_MSB - ITCM single-bit ECC error data [63:32]
 */
#define CM33_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_SHIFT)) & \
     CM33_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_INFO - ITCM multi-bit ECC Error Information Register */
/*! @{ */

#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_MASK  (0x1U)
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_SHIFT (0U)
/*! ITCM_ECCM_EFW - ITCM multi-bit ECC error corresponding tcm_wr value
 */
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_SHIFT)) & \
     CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_MASK)

#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_MASK  (0xEU)
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_SHIFT (1U)
/*! ITCM_ECCM_EFSIZ - ITCM multi-bit ECC error corresponding tcm access size
 */
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_SHIFT)) & \
     CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_MASK)

#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_MASK  (0xF0U)
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_SHIFT (4U)
/*! ITCM_ECCM_EFMST - ITCM multi-bit ECC error corresponding tcm_master
 */
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_SHIFT)) & \
     CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_MASK)

#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_MASK  (0xF00U)
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_SHIFT (8U)
/*! ITCM_ECCM_EFPRT - ITCM multi-bit ECC error corresponding tcm_priv
 */
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_SHIFT)) & \
     CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_MASK)

#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSYN_MASK  (0xFF000U)
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSYN_SHIFT (12U)
/*! ITCM_ECCM_EFSYN - ITCM multi-bit ECC error corresponding syndrome
 */
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSYN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSYN_SHIFT)) & \
     CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSYN_MASK)

#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_MASK  (0xFFF00000U)
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT (20U)
/*! Reserved - Reserved
 */
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT)) & \
     CM33_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_ADDR - ITCM multi-bit ECC Error Address Register */
/*! @{ */

#define CM33_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_MASK  (0xFFFFFFFFU)
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! ITCM_ECCM_ERRED_ADDR - ITCM multi-bit ECC error address
 */
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_SHIFT)) & \
     CM33_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_DATA_LSB - ITCM multi-bit ECC Error Data Register */
/*! @{ */

#define CM33_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_MASK  (0xFFFFFFFFU)
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_SHIFT (0U)
/*! ITCM_ECCM_ERRED_DATA_LSB - ITCM multi-bit ECC error data [31:0]
 */
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_SHIFT)) & \
     CM33_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_DATA_MSB - ITCM multi-bit ECC Error Data Register */
/*! @{ */

#define CM33_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_MASK  (0xFFFFFFFFU)
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_SHIFT (0U)
/*! ITCM_ECCM_ERRED_DATA_MSB - ITCM multi-bit ECC error data [63:32]
 */
#define CM33_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_SHIFT)) & \
     CM33_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_SINGLE_ERROR_INFO - CODE_TCM single-bit ECC Error Information Register */
/*! @{ */

#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFW_MASK  (0x1U)
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFW_SHIFT (0U)
/*! CODE_TCM_ECCS_EFW - CODE_TCM single-bit ECC error corresponding tcm_wr value
 */
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFW(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFW_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFW_MASK)

#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_MASK  (0xEU)
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_SHIFT (1U)
/*! CODE_TCM_ECCS_EFSIZ - CODE_TCM single-bit ECC error corresponding tcm access size
 */
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_MASK)

#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_MASK  (0xF0U)
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_SHIFT (4U)
/*! CODE_TCM_ECCS_EFMST - CODE_TCM single-bit ECC error corresponding tcm_master
 */
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_MASK)

#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_MASK  (0xF00U)
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_SHIFT (8U)
/*! CODE_TCM_ECCS_EFPRT - CODE_TCM single-bit ECC error corresponding tcm_priv
 */
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_MASK)

#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_MASK  (0x7F000U)
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_SHIFT (12U)
/*! CODE_TCM_ECCS_EFSYN - CODE_TCM single-bit ECC error corresponding syndrome
 */
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_MASK)

#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK  (0xFFF80000U)
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved
 */
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_Reserved(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_SINGLE_ERROR_ADDR - CODE_TCM single-bit ECC Error Address Register */
/*! @{ */

#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_MASK  (0xFFFFFFFFU)
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! CODE_TCM_ECCS_ERRED_ADDR - CODE_TCM single-bit ECC error address
 */
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_SINGLE_ERROR_DATA - CODE_TCM single-bit ECC Error Data Register */
/*! @{ */

#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_DATA_CODE_TCM_ECCS_ERRED_DATA_MASK  (0xFFFFFFFFU)
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_DATA_CODE_TCM_ECCS_ERRED_DATA_SHIFT (0U)
/*! CODE_TCM_ECCS_ERRED_DATA - CODE_TCM single-bit ECC error data
 */
#define CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_DATA_CODE_TCM_ECCS_ERRED_DATA(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_DATA_CODE_TCM_ECCS_ERRED_DATA_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_SINGLE_ERROR_DATA_CODE_TCM_ECCS_ERRED_DATA_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_MULTI_ERROR_INFO - CODE_TCM multi-bit ECC Error Information Register */
/*! @{ */

#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFW_MASK  (0x1U)
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFW_SHIFT (0U)
/*! CODE_TCM_ECCM_EFW - CODE_TCM multi-bit ECC error corresponding tcm_wr value
 */
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFW(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFW_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFW_MASK)

#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_MASK  (0xEU)
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_SHIFT (1U)
/*! CODE_TCM_ECCM_EFSIZ - CODE_TCM multi-bit ECC error corresponding tcm access size
 */
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_MASK)

#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_MASK  (0xF0U)
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_SHIFT (4U)
/*! CODE_TCM_ECCM_EFMST - CODE_TCM multi-bit ECC error corresponding tcm_master
 */
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_MASK)

#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_MASK  (0xF00U)
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_SHIFT (8U)
/*! CODE_TCM_ECCM_EFPRT - CODE_TCM multi-bit ECC error corresponding tcm_priv
 */
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_MASK)

#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_MASK  (0x7F000U)
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_SHIFT (12U)
/*! CODE_TCM_ECCM_EFSYN - CODE_TCM multi-bit ECC error corresponding syndrome
 */
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_MASK)

#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK  (0xFFF80000U)
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved
 */
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_Reserved(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_MULTI_ERROR_ADDR - CODE_TCM multi-bit ECC Error Address Register */
/*! @{ */

#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_MASK  (0xFFFFFFFFU)
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! CODE_TCM_ECCM_ERRED_ADDR - CODE_TCM multi-bit ECC error address
 */
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_MULTI_ERROR_DATA - CODE_TCM multi-bit ECC Error Data Register */
/*! @{ */

#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_DATA_CODE_TCM_ECCM_ERRED_DATA_MASK  (0xFFFFFFFFU)
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_DATA_CODE_TCM_ECCM_ERRED_DATA_SHIFT (0U)
/*! CODE_TCM_ECCM_ERRED_DATA - CODE_TCM multi-bit ECC error data
 */
#define CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_DATA_CODE_TCM_ECCM_ERRED_DATA(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_DATA_CODE_TCM_ECCM_ERRED_DATA_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_MULTI_ERROR_DATA_CODE_TCM_ECCM_ERRED_DATA_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_SINGLE_ERROR_INFO - SYS_TCM single-bit ECC Error Information Register */
/*! @{ */

#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFW_MASK  (0x1U)
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFW_SHIFT (0U)
/*! SYS_TCM_ECCS_EFW - SYS_TCM single-bit ECC error corresponding tcm_wr value
 */
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFW(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFW_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFW_MASK)

#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_MASK  (0xEU)
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_SHIFT (1U)
/*! SYS_TCM_ECCS_EFSIZ - SYS_TCM single-bit ECC error corresponding tcm access size
 */
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_MASK)

#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_MASK  (0xF0U)
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_SHIFT (4U)
/*! SYS_TCM_ECCS_EFMST - SYS_TCM single-bit ECC error corresponding tcm_master
 */
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_MASK)

#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_MASK  (0xF00U)
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_SHIFT (8U)
/*! SYS_TCM_ECCS_EFPRT - SYS_TCM single-bit ECC error corresponding tcm_priv
 */
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_MASK)

#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_MASK  (0x7F000U)
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_SHIFT (12U)
/*! SYS_TCM_ECCS_EFSYN - SYS_TCM single-bit ECC error corresponding syndrome
 */
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_MASK)

#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK  (0xFFF80000U)
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved
 */
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_Reserved(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_SINGLE_ERROR_ADDR - SYS_TCM single-bit ECC Error Address Register */
/*! @{ */

#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_MASK  (0xFFFFFFFFU)
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! SYS_TCM_ECCS_ERRED_ADDR - SYS_TCM single-bit ECC error address
 */
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_SINGLE_ERROR_DATA - SYS_TCM single-bit ECC Error Data Register */
/*! @{ */

#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_DATA_SYS_TCM_ECCS_ERRED_DATA_MASK  (0xFFFFFFFFU)
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_DATA_SYS_TCM_ECCS_ERRED_DATA_SHIFT (0U)
/*! SYS_TCM_ECCS_ERRED_DATA - SYS_TCM single-bit ECC error data
 */
#define CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_DATA_SYS_TCM_ECCS_ERRED_DATA(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_DATA_SYS_TCM_ECCS_ERRED_DATA_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_SINGLE_ERROR_DATA_SYS_TCM_ECCS_ERRED_DATA_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_MULTI_ERROR_INFO - SYS_TCM multi-bit ECC Error Information Register */
/*! @{ */

#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFW_MASK  (0x1U)
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFW_SHIFT (0U)
/*! SYS_TCM_ECCM_EFW - SYS_TCM multi-bit ECC error corresponding tcm_wr value
 */
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFW(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFW_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFW_MASK)

#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_MASK  (0xEU)
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_SHIFT (1U)
/*! SYS_TCM_ECCM_EFSIZ - SYS_TCM multi-bit ECC error corresponding tcm access size
 */
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_MASK)

#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_MASK  (0xF0U)
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_SHIFT (4U)
/*! SYS_TCM_ECCM_EFMST - SYS_TCM multi-bit ECC error corresponding tcm_master
 */
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_MASK)

#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_MASK  (0xF00U)
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_SHIFT (8U)
/*! SYS_TCM_ECCM_EFPRT - SYS_TCM multi-bit ECC error corresponding tcm_priv
 */
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_MASK)

#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_MASK  (0x7F000U)
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_SHIFT (12U)
/*! SYS_TCM_ECCM_EFSYN - SYS_TCM multi-bit ECC error corresponding syndrome
 */
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_MASK)

#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK  (0xFFF80000U)
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved
 */
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_Reserved(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_MULTI_ERROR_ADDR - SYS_TCM multi-bit ECC Error Address Register */
/*! @{ */

#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_MASK  (0xFFFFFFFFU)
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! SYS_TCM_ECCM_ERRED_ADDR - SYS_TCM multi-bit ECC error address
 */
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_MULTI_ERROR_DATA - SYS_TCM multi-bit ECC Error Data Register */
/*! @{ */

#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_DATA_SYS_TCM_ECCM_ERRED_DATA_MASK  (0xFFFFFFFFU)
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_DATA_SYS_TCM_ECCM_ERRED_DATA_SHIFT (0U)
/*! SYS_TCM_ECCM_ERRED_DATA - SYS_TCM multi-bit ECC error data
 */
#define CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_DATA_SYS_TCM_ECCM_ERRED_DATA(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_DATA_SYS_TCM_ECCM_ERRED_DATA_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_MULTI_ERROR_DATA_SYS_TCM_ECCM_ERRED_DATA_MASK)
/*! @} */

/*! @name ITCM_ECC_ERROR_INJEC - ITCM ECC Error Injection Register */
/*! @{ */

#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR1BIT_MASK  (0xFFU)
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR1BIT_SHIFT (0U)
/*! ITCM_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC Error
 * injection.
 */
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR1BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR1BIT_SHIFT)) & \
     CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR1BIT_MASK)

#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR2BIT_MASK  (0xFF00U)
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR2BIT_SHIFT (8U)
/*! ITCM_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error.
 */
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR2BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR2BIT_SHIFT)) & \
     CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR2BIT_MASK)

#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR11BI_MASK  (0x10000U)
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR11BI_SHIFT (16U)
/*! ITCM_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on ITCM write access
 */
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR11BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR11BI_SHIFT)) & \
     CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR11BI_MASK)

#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR1NCI_MASK  (0x20000U)
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR1NCI_SHIFT (17U)
/*! ITCM_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on ITCM write access
 */
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR1NCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR1NCI_SHIFT)) & \
     CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR1NCI_MASK)

#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRC1BI_MASK  (0x40000U)
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRC1BI_SHIFT (18U)
/*! ITCM_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on ITCM write access
 */
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRC1BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRC1BI_SHIFT)) & \
     CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRC1BI_MASK)

#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRCNCI_MASK  (0x80000U)
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRCNCI_SHIFT (19U)
/*! ITCM_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on ITCM write access
 */
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRCNCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRCNCI_SHIFT)) & \
     CM33_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRCNCI_MASK)

#define CM33_MCM_ITCM_ECC_ERROR_INJEC_Reserved_MASK  (0xFFF00000U)
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_Reserved_SHIFT (20U)
/*! Reserved - Reserved
 */
#define CM33_MCM_ITCM_ECC_ERROR_INJEC_Reserved(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_ITCM_ECC_ERROR_INJEC_Reserved_SHIFT)) & \
     CM33_MCM_ITCM_ECC_ERROR_INJEC_Reserved_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_ERROR_INJEC - CODE_TCM ECC Error Injection Register */
/*! @{ */

#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_MASK  (0xFFU)
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_SHIFT (0U)
/*! CODE_TCM_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC Error
 * injection.
 */
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_MASK)

#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_MASK  (0xFF00U)
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_SHIFT (8U)
/*! CODE_TCM_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error
 */
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_MASK)

#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_MASK  (0x10000U)
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_SHIFT (16U)
/*! CODE_TCM_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on CODE_TCM write access
 */
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_MASK)

#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_MASK  (0x20000U)
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_SHIFT (17U)
/*! CODE_TCM_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on CODE_TCM write access
 */
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_MASK)

#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_MASK  (0x40000U)
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_SHIFT (18U)
/*! CODE_TCM_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on CODE_TCM write access
 */
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_MASK)

#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_MASK  (0x80000U)
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_SHIFT (19U)
/*! CODE_TCM_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on CODE_TCM write access
 */
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_MASK)

#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_Reserved_MASK  (0xFFF00000U)
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_Reserved_SHIFT (20U)
/*! Reserved - Reserved
 */
#define CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_Reserved(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_Reserved_SHIFT)) & \
     CM33_MCM_CODE_TCM_ECC_ERROR_INJEC_Reserved_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_ERROR_INJEC - SYS_TCM ECC Error Injection Register */
/*! @{ */

#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_MASK  (0xFFU)
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_SHIFT (0U)
/*! SYS_TCM_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC Error
 * injection
 */
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_MASK)

#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_MASK  (0xFF00U)
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_SHIFT (8U)
/*! SYS_TCM_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error
 */
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_MASK)

#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_MASK  (0x10000U)
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_SHIFT (16U)
/*! SYS_TCM_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on SYS_TCM write access
 */
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_MASK)

#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_MASK  (0x20000U)
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_SHIFT (17U)
/*! SYS_TCM_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on SYS_TCM write access
 */
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_MASK)

#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_MASK  (0x40000U)
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_SHIFT (18U)
/*! SYS_TCM_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on SYS_TCM write access
 */
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_MASK)

#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_MASK  (0x80000U)
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_SHIFT (19U)
/*! SYS_TCM_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on SYS_TCM write access
 */
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_MASK)

#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_Reserved_MASK  (0xFFF00000U)
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_Reserved_SHIFT (20U)
/*! Reserved - Reserved
 */
#define CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_Reserved(x)                                    \
    (((uint32_t)(((uint32_t)(x)) << CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_Reserved_SHIFT)) & \
     CM33_MCM_SYS_TCM_ECC_ERROR_INJEC_Reserved_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CM33_MCM_Register_Masks */

/* CM33_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** Peripheral CM33_MCM base address */
#define CM33_MCM_BASE (0x54420000u)
/** Peripheral CM33_MCM base address */
#define CM33_MCM_BASE_NS (0x44420000u)
/** Peripheral CM33_MCM base pointer */
#define CM33_MCM ((CM33_MCM_Type *)CM33_MCM_BASE)
/** Peripheral CM33_MCM base pointer */
#define CM33_MCM_NS ((CM33_MCM_Type *)CM33_MCM_BASE_NS)
/** Array initializer of CM33_MCM peripheral base addresses */
#define CM33_MCM_BASE_ADDRS \
    {                       \
        CM33_MCM_BASE       \
    }
/** Array initializer of CM33_MCM peripheral base pointers */
#define CM33_MCM_BASE_PTRS \
    {                      \
        CM33_MCM           \
    }
/** Array initializer of CM33_MCM peripheral base addresses */
#define CM33_MCM_BASE_ADDRS_NS \
    {                          \
        CM33_MCM_BASE_NS       \
    }
/** Array initializer of CM33_MCM peripheral base pointers */
#define CM33_MCM_BASE_PTRS_NS \
    {                         \
        CM33_MCM_NS           \
    }
#else
/** Peripheral CM33_MCM base address */
#define CM33_MCM_BASE (0x44420000u)
/** Peripheral CM33_MCM base pointer */
#define CM33_MCM      ((CM33_MCM_Type *)CM33_MCM_BASE)
/** Array initializer of CM33_MCM peripheral base addresses */
#define CM33_MCM_BASE_ADDRS \
    {                       \
        CM33_MCM_BASE       \
    }
/** Array initializer of CM33_MCM peripheral base pointers */
#define CM33_MCM_BASE_PTRS \
    {                      \
        CM33_MCM           \
    }
#endif

/*!
 * @}
 */ /* end of group CM33_MCM_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_CM33_MCM_H_) */
