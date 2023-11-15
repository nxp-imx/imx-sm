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
 * @file MIMX95_SYS_CTR_COMPARE.h
 * @version 1.0
 * @date 2021-11-16
 * @brief CMSIS Peripheral Access Layer for MIMX95_SYS_CTR_COMPARE
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_SYS_CTR_COMPARE_H_)  /* Check if memory map has not been already included */
#define MIMX95_SYS_CTR_COMPARE_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SYS_CTR_COMPARE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_COMPARE_Peripheral_Access_Layer SYS_CTR_COMPARE Peripheral Access Layer
 * @{
 */

/** SYS_CTR_COMPARE - Register Layout Typedef */
typedef struct
{
    uint8_t RESERVED_0[32];
    __IO uint32_t CMPCVL0; /**< Compare Count Value Low Register, offset: 0x20 */
    __IO uint32_t CMPCVH0; /**< Compare Count Value High Register, offset: 0x24 */
    uint8_t RESERVED_1[4];
    __IO uint32_t CMPCR0; /**< Compare Control Register, offset: 0x2C */
    uint8_t RESERVED_2[240];
    __IO uint32_t CMPCVL1; /**< Compare Count Value Low Register, offset: 0x120 */
    __IO uint32_t CMPCVH1; /**< Compare Count Value High Register, offset: 0x124 */
    uint8_t RESERVED_3[4];
    __IO uint32_t CMPCR1; /**< Compare Control Register, offset: 0x12C */
    uint8_t RESERVED_4[3744];
    __I uint32_t CNTID0; /**< Counter ID Register, offset: 0xFD0 */
} SYS_CTR_COMPARE_Type;

/* ----------------------------------------------------------------------------
   -- SYS_CTR_COMPARE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_COMPARE_Register_Masks SYS_CTR_COMPARE Register Masks
 * @{
 */

/*! @name CMPCVL0 - Compare Count Value Low Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0_MASK  (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0_SHIFT (0U)
/*! CMPCV0 - Compare Count Value bits [31:0]
 */
#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVL0_CMPCV0_SHIFT)) & SYS_CTR_COMPARE_CMPCVL0_CMPCV0_MASK)
/*! @} */

/*! @name CMPCVH0 - Compare Count Value High Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1_MASK  (0xFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1_SHIFT (0U)
/*! CMPCV1 - Compare Count Value bits [55:32]
 */
#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVH0_CMPCV1_SHIFT)) & SYS_CTR_COMPARE_CMPCVH0_CMPCV1_MASK)
/*! @} */

/*! @name CMPCR0 - Compare Control Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCR0_EN_MASK  (0x1U)
#define SYS_CTR_COMPARE_CMPCR0_EN_SHIFT (0U)
/*! EN - Enable
 *  0b0..Compare disabled
 *  0b1..Compare enabled
 */
#define SYS_CTR_COMPARE_CMPCR0_EN(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_EN_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_EN_MASK)

#define SYS_CTR_COMPARE_CMPCR0_IMASK_MASK  (0x2U)
#define SYS_CTR_COMPARE_CMPCR0_IMASK_SHIFT (1U)
/*! IMASK - Interrupt Request Mask
 *  0b0..Interrupt output signal is not masked.
 *  0b1..Interrupt output signal is masked.
 */
#define SYS_CTR_COMPARE_CMPCR0_IMASK(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_IMASK_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_IMASK_MASK)

#define SYS_CTR_COMPARE_CMPCR0_ISTAT_MASK  (0x4U)
#define SYS_CTR_COMPARE_CMPCR0_ISTAT_SHIFT (2U)
/*! ISTAT - Interrupt Status
 *  0b0..Counter value is less than the compare value or compare is disabled.
 *  0b1..Counter value is greater than or equal to the compare value and compare is enabled.
 */
#define SYS_CTR_COMPARE_CMPCR0_ISTAT(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_ISTAT_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_ISTAT_MASK)
/*! @} */

/*! @name CMPCVL1 - Compare Count Value Low Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0_MASK  (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0_SHIFT (0U)
/*! CMPCV0 - Compare Count Value bits [31:0]
 */
#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVL1_CMPCV0_SHIFT)) & SYS_CTR_COMPARE_CMPCVL1_CMPCV0_MASK)
/*! @} */

/*! @name CMPCVH1 - Compare Count Value High Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1_MASK  (0xFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1_SHIFT (0U)
/*! CMPCV1 - Compare Count Value bits [55:32]
 */
#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVH1_CMPCV1_SHIFT)) & SYS_CTR_COMPARE_CMPCVH1_CMPCV1_MASK)
/*! @} */

/*! @name CMPCR1 - Compare Control Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCR1_EN_MASK  (0x1U)
#define SYS_CTR_COMPARE_CMPCR1_EN_SHIFT (0U)
/*! EN - Enable
 *  0b0..Compare disabled
 *  0b1..Compare enabled
 */
#define SYS_CTR_COMPARE_CMPCR1_EN(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR1_EN_SHIFT)) & SYS_CTR_COMPARE_CMPCR1_EN_MASK)

#define SYS_CTR_COMPARE_CMPCR1_IMASK_MASK  (0x2U)
#define SYS_CTR_COMPARE_CMPCR1_IMASK_SHIFT (1U)
/*! IMASK - Interrupt Request Mask
 *  0b0..Interrupt output signal is not masked.
 *  0b1..Interrupt output signal is masked.
 */
#define SYS_CTR_COMPARE_CMPCR1_IMASK(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR1_IMASK_SHIFT)) & SYS_CTR_COMPARE_CMPCR1_IMASK_MASK)

#define SYS_CTR_COMPARE_CMPCR1_ISTAT_MASK  (0x4U)
#define SYS_CTR_COMPARE_CMPCR1_ISTAT_SHIFT (2U)
/*! ISTAT - Interrupt Status
 *  0b0..Counter value is less than the compare value or compare is disabled.
 *  0b1..Counter value is greater than or equal to the compare value and compare is enabled.
 */
#define SYS_CTR_COMPARE_CMPCR1_ISTAT(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR1_ISTAT_SHIFT)) & SYS_CTR_COMPARE_CMPCR1_ISTAT_MASK)
/*! @} */

/*! @name CNTID0 - Counter ID Register */
/*! @{ */

#define SYS_CTR_COMPARE_CNTID0_CNTID_MASK  (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CNTID0_CNTID_SHIFT (0U)
/*! CNTID - Counter Identification
 */
#define SYS_CTR_COMPARE_CNTID0_CNTID(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CNTID0_CNTID_SHIFT)) & SYS_CTR_COMPARE_CNTID0_CNTID_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SYS_CTR_COMPARE_Register_Masks */

/* SYS_CTR_COMPARE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** Peripheral SYS_CTR_COMPARE base address */
#define SYS_CTR_COMPARE_BASE (0x542A0000u)
/** Peripheral SYS_CTR_COMPARE base address */
#define SYS_CTR_COMPARE_BASE_NS (0x442A0000u)
/** Peripheral SYS_CTR_COMPARE base pointer */
#define SYS_CTR_COMPARE ((SYS_CTR_COMPARE_Type *)SYS_CTR_COMPARE_BASE)
/** Peripheral SYS_CTR_COMPARE base pointer */
#define SYS_CTR_COMPARE_NS ((SYS_CTR_COMPARE_Type *)SYS_CTR_COMPARE_BASE_NS)
/** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
#define SYS_CTR_COMPARE_BASE_ADDRS \
    {                              \
        SYS_CTR_COMPARE_BASE       \
    }
/** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
#define SYS_CTR_COMPARE_BASE_PTRS \
    {                             \
        SYS_CTR_COMPARE           \
    }
/** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
#define SYS_CTR_COMPARE_BASE_ADDRS_NS \
    {                                 \
        SYS_CTR_COMPARE_BASE_NS       \
    }
/** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
#define SYS_CTR_COMPARE_BASE_PTRS_NS \
    {                                \
        SYS_CTR_COMPARE_NS           \
    }
#else
/** Peripheral SYS_CTR_COMPARE base address */
#define SYS_CTR_COMPARE_BASE (0x442A0000u)
/** Peripheral SYS_CTR_COMPARE base pointer */
#define SYS_CTR_COMPARE      ((SYS_CTR_COMPARE_Type *)SYS_CTR_COMPARE_BASE)
/** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
#define SYS_CTR_COMPARE_BASE_ADDRS \
    {                              \
        SYS_CTR_COMPARE_BASE       \
    }
/** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
#define SYS_CTR_COMPARE_BASE_PTRS \
    {                             \
        SYS_CTR_COMPARE           \
    }
#endif

/*!
 * @}
 */ /* end of group SYS_CTR_COMPARE_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_SYS_CTR_COMPARE_H_) */
