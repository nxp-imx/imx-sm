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
 * @file MIMX95_SYS_CTR_READ.h
 * @version 1.0
 * @date 2021-11-16
 * @brief CMSIS Peripheral Access Layer for MIMX95_SYS_CTR_READ
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_SYS_CTR_READ_H_)  /* Check if memory map has not been already included */
#define MIMX95_SYS_CTR_READ_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SYS_CTR_READ Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_READ_Peripheral_Access_Layer SYS_CTR_READ Peripheral Access Layer
 * @{
 */

/** SYS_CTR_READ - Register Layout Typedef */
typedef struct
{
    uint8_t RESERVED_0[8];
    __I uint32_t CNTCV0; /**< Counter Count Value Low Register, offset: 0x8 */
    __I uint32_t CNTCV1; /**< Counter Count Value High Register, offset: 0xC */
    uint8_t RESERVED_1[4032];
    __I uint32_t CNTID0; /**< Counter ID Register, offset: 0xFD0 */
} SYS_CTR_READ_Type;

/* ----------------------------------------------------------------------------
   -- SYS_CTR_READ Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_READ_Register_Masks SYS_CTR_READ Register Masks
 * @{
 */

/*! @name CNTCV0 - Counter Count Value Low Register */
/*! @{ */

#define SYS_CTR_READ_CNTCV0_CNTCV0_MASK  (0xFFFFFFFFU)
#define SYS_CTR_READ_CNTCV0_CNTCV0_SHIFT (0U)
/*! CNTCV0 - Counter Count Value bits [31:0]
 */
#define SYS_CTR_READ_CNTCV0_CNTCV0(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_READ_CNTCV0_CNTCV0_SHIFT)) & SYS_CTR_READ_CNTCV0_CNTCV0_MASK)
/*! @} */

/*! @name CNTCV1 - Counter Count Value High Register */
/*! @{ */

#define SYS_CTR_READ_CNTCV1_CNTCV1_MASK  (0xFFFFFFU)
#define SYS_CTR_READ_CNTCV1_CNTCV1_SHIFT (0U)
/*! CNTCV1 - Counter Count Value bits [55:32]
 */
#define SYS_CTR_READ_CNTCV1_CNTCV1(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_READ_CNTCV1_CNTCV1_SHIFT)) & SYS_CTR_READ_CNTCV1_CNTCV1_MASK)
/*! @} */

/*! @name CNTID0 - Counter ID Register */
/*! @{ */

#define SYS_CTR_READ_CNTID0_CNTID_MASK  (0xFFFFFFFFU)
#define SYS_CTR_READ_CNTID0_CNTID_SHIFT (0U)
/*! CNTID - Counter Identification
 */
#define SYS_CTR_READ_CNTID0_CNTID(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_READ_CNTID0_CNTID_SHIFT)) & SYS_CTR_READ_CNTID0_CNTID_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SYS_CTR_READ_Register_Masks */

/* SYS_CTR_READ - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** Peripheral SYS_CTR_READ base address */
#define SYS_CTR_READ_BASE (0x542B0000u)
/** Peripheral SYS_CTR_READ base address */
#define SYS_CTR_READ_BASE_NS (0x442B0000u)
/** Peripheral SYS_CTR_READ base pointer */
#define SYS_CTR_READ ((SYS_CTR_READ_Type *)SYS_CTR_READ_BASE)
/** Peripheral SYS_CTR_READ base pointer */
#define SYS_CTR_READ_NS ((SYS_CTR_READ_Type *)SYS_CTR_READ_BASE_NS)
/** Array initializer of SYS_CTR_READ peripheral base addresses */
#define SYS_CTR_READ_BASE_ADDRS \
    {                           \
        SYS_CTR_READ_BASE       \
    }
/** Array initializer of SYS_CTR_READ peripheral base pointers */
#define SYS_CTR_READ_BASE_PTRS \
    {                          \
        SYS_CTR_READ           \
    }
/** Array initializer of SYS_CTR_READ peripheral base addresses */
#define SYS_CTR_READ_BASE_ADDRS_NS \
    {                              \
        SYS_CTR_READ_BASE_NS       \
    }
/** Array initializer of SYS_CTR_READ peripheral base pointers */
#define SYS_CTR_READ_BASE_PTRS_NS \
    {                             \
        SYS_CTR_READ_NS           \
    }
#else
/** Peripheral SYS_CTR_READ base address */
#define SYS_CTR_READ_BASE (0x442B0000u)
/** Peripheral SYS_CTR_READ base pointer */
#define SYS_CTR_READ      ((SYS_CTR_READ_Type *)SYS_CTR_READ_BASE)
/** Array initializer of SYS_CTR_READ peripheral base addresses */
#define SYS_CTR_READ_BASE_ADDRS \
    {                           \
        SYS_CTR_READ_BASE       \
    }
/** Array initializer of SYS_CTR_READ peripheral base pointers */
#define SYS_CTR_READ_BASE_PTRS \
    {                          \
        SYS_CTR_READ           \
    }
#endif

/*!
 * @}
 */ /* end of group SYS_CTR_READ_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_SYS_CTR_READ_H_) */
