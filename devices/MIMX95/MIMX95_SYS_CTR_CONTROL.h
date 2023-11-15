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
 * @file MIMX95_SYS_CTR_CONTROL.h
 * @version 1.0
 * @date 2021-11-16
 * @brief CMSIS Peripheral Access Layer for MIMX95_SYS_CTR_CONTROL
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_SYS_CTR_CONTROL_H_)  /* Check if memory map has not been already included */
#define MIMX95_SYS_CTR_CONTROL_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SYS_CTR_CONTROL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_CONTROL_Peripheral_Access_Layer SYS_CTR_CONTROL Peripheral Access Layer
 * @{
 */

/** SYS_CTR_CONTROL - Register Layout Typedef */
typedef struct
{
    __IO uint32_t CNTCR;  /**< Counter Control Register, offset: 0x0 */
    __I uint32_t CNTSR;   /**< Counter Status Register, offset: 0x4 */
    __IO uint32_t CNTCV0; /**< Counter Count Value Low Register, offset: 0x8 */
    __IO uint32_t CNTCV1; /**< Counter Count Value High Register, offset: 0xC */
    uint8_t RESERVED_0[16];
    __I uint32_t CNTFID0; /**< Frequency Modes Table 0 Register, offset: 0x20 */
    __I uint32_t CNTFID1; /**< Frequency Modes Table 1 Register, offset: 0x24 */
    __I uint32_t CNTFID2; /**< Frequency Modes Table 2 Register, offset: 0x28 */
    uint8_t RESERVED_1[4004];
    __I uint32_t CNTID0; /**< Counter ID Register, offset: 0xFD0 */
} SYS_CTR_CONTROL_Type;

/* ----------------------------------------------------------------------------
   -- SYS_CTR_CONTROL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_CONTROL_Register_Masks SYS_CTR_CONTROL Register Masks
 * @{
 */

/*! @name CNTCR - Counter Control Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCR_EN_MASK  (0x1U)
#define SYS_CTR_CONTROL_CNTCR_EN_SHIFT (0U)
/*! EN - Enable Counting
 *  0b0..Counter disabled
 *  0b1..Counter enabled
 */
#define SYS_CTR_CONTROL_CNTCR_EN(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_EN_SHIFT)) & SYS_CTR_CONTROL_CNTCR_EN_MASK)

#define SYS_CTR_CONTROL_CNTCR_HDBG_MASK  (0x2U)
#define SYS_CTR_CONTROL_CNTCR_HDBG_SHIFT (1U)
/*! HDBG - Enable Debug
 *  0b0..The assertion of the debug input is ignored.
 *  0b1..The assertion of the debug input causes the System Counter to halt.
 */
#define SYS_CTR_CONTROL_CNTCR_HDBG(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_HDBG_SHIFT)) & SYS_CTR_CONTROL_CNTCR_HDBG_MASK)

#define SYS_CTR_CONTROL_CNTCR_FCR0_MASK  (0x100U)
#define SYS_CTR_CONTROL_CNTCR_FCR0_SHIFT (8U)
/*! FCR0 - Frequency Change Request, ID 0
 *  0b0..No change.
 *  0b1..Select frequency modes table entry 0, the base frequency.
 */
#define SYS_CTR_CONTROL_CNTCR_FCR0(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_FCR0_SHIFT)) & SYS_CTR_CONTROL_CNTCR_FCR0_MASK)

#define SYS_CTR_CONTROL_CNTCR_FCR1_MASK  (0x200U)
#define SYS_CTR_CONTROL_CNTCR_FCR1_SHIFT (9U)
/*! FCR1 - Frequency Change Request, ID 1
 *  0b0..No change.
 *  0b1..Select frequency modes table entry 1, the base frequency.
 */
#define SYS_CTR_CONTROL_CNTCR_FCR1(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_FCR1_SHIFT)) & SYS_CTR_CONTROL_CNTCR_FCR1_MASK)
/*! @} */

/*! @name CNTSR - Counter Status Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTSR_DBGH_MASK  (0x1U)
#define SYS_CTR_CONTROL_CNTSR_DBGH_SHIFT (0U)
/*! DBGH - Debug Halt
 *  0b0..Counter is not halted by debug.
 *  0b1..Counter is halted by debug.
 */
#define SYS_CTR_CONTROL_CNTSR_DBGH(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_DBGH_SHIFT)) & SYS_CTR_CONTROL_CNTSR_DBGH_MASK)

#define SYS_CTR_CONTROL_CNTSR_FCA0_MASK  (0x100U)
#define SYS_CTR_CONTROL_CNTSR_FCA0_SHIFT (8U)
/*! FCA0 - Frequency Change Acknowledge, ID 0
 *  0b0..Base frequency is not selected.
 *  0b1..Base frequency is selected.
 */
#define SYS_CTR_CONTROL_CNTSR_FCA0(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_FCA0_SHIFT)) & SYS_CTR_CONTROL_CNTSR_FCA0_MASK)

#define SYS_CTR_CONTROL_CNTSR_FCA1_MASK  (0x200U)
#define SYS_CTR_CONTROL_CNTSR_FCA1_SHIFT (9U)
/*! FCA1 - Frequency Change Acknowledge, ID 1
 *  0b0..Base frequency is not selected.
 *  0b1..Base frequency is selected.
 */
#define SYS_CTR_CONTROL_CNTSR_FCA1(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_FCA1_SHIFT)) & SYS_CTR_CONTROL_CNTSR_FCA1_MASK)
/*! @} */

/*! @name CNTCV0 - Counter Count Value Low Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCV0_CNTCV0_MASK  (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTCV0_CNTCV0_SHIFT (0U)
/*! CNTCV0 - Counter Count Value bits [31:0]
 */
#define SYS_CTR_CONTROL_CNTCV0_CNTCV0(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCV0_CNTCV0_SHIFT)) & SYS_CTR_CONTROL_CNTCV0_CNTCV0_MASK)
/*! @} */

/*! @name CNTCV1 - Counter Count Value High Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCV1_CNTCV1_MASK  (0xFFFFFFU)
#define SYS_CTR_CONTROL_CNTCV1_CNTCV1_SHIFT (0U)
/*! CNTCV1 - Counter Count Value bits [55:32]
 */
#define SYS_CTR_CONTROL_CNTCV1_CNTCV1(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCV1_CNTCV1_SHIFT)) & SYS_CTR_CONTROL_CNTCV1_CNTCV1_MASK)
/*! @} */

/*! @name CNTFID0 - Frequency Modes Table 0 Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID0_CNTFID0_MASK  (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID0_CNTFID0_SHIFT (0U)
/*! CNTFID0 - Counter Frequency ID 0
 */
#define SYS_CTR_CONTROL_CNTFID0_CNTFID0(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID0_CNTFID0_SHIFT)) & SYS_CTR_CONTROL_CNTFID0_CNTFID0_MASK)
/*! @} */

/*! @name CNTFID1 - Frequency Modes Table 1 Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID1_CNTFID1_MASK  (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID1_CNTFID1_SHIFT (0U)
/*! CNTFID1 - Counter Frequency ID 1
 */
#define SYS_CTR_CONTROL_CNTFID1_CNTFID1(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID1_CNTFID1_SHIFT)) & SYS_CTR_CONTROL_CNTFID1_CNTFID1_MASK)
/*! @} */

/*! @name CNTFID2 - Frequency Modes Table 2 Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID2_CNTFID2_MASK  (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID2_CNTFID2_SHIFT (0U)
/*! CNTFID2 - Counter Frequency ID 2
 */
#define SYS_CTR_CONTROL_CNTFID2_CNTFID2(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID2_CNTFID2_SHIFT)) & SYS_CTR_CONTROL_CNTFID2_CNTFID2_MASK)
/*! @} */

/*! @name CNTID0 - Counter ID Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTID0_CNTID_MASK  (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTID0_CNTID_SHIFT (0U)
/*! CNTID - Counter Identification
 */
#define SYS_CTR_CONTROL_CNTID0_CNTID(x) \
    (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTID0_CNTID_SHIFT)) & SYS_CTR_CONTROL_CNTID0_CNTID_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SYS_CTR_CONTROL_Register_Masks */

/* SYS_CTR_CONTROL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** Peripheral SYS_CTR_CONTROL base address */
#define SYS_CTR_CONTROL_BASE (0x54290000u)
/** Peripheral SYS_CTR_CONTROL base address */
#define SYS_CTR_CONTROL_BASE_NS (0x44290000u)
/** Peripheral SYS_CTR_CONTROL base pointer */
#define SYS_CTR_CONTROL ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE)
/** Peripheral SYS_CTR_CONTROL base pointer */
#define SYS_CTR_CONTROL_NS ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE_NS)
/** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
#define SYS_CTR_CONTROL_BASE_ADDRS \
    {                              \
        SYS_CTR_CONTROL_BASE       \
    }
/** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
#define SYS_CTR_CONTROL_BASE_PTRS \
    {                             \
        SYS_CTR_CONTROL           \
    }
/** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
#define SYS_CTR_CONTROL_BASE_ADDRS_NS \
    {                                 \
        SYS_CTR_CONTROL_BASE_NS       \
    }
/** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
#define SYS_CTR_CONTROL_BASE_PTRS_NS \
    {                                \
        SYS_CTR_CONTROL_NS           \
    }
#else
/** Peripheral SYS_CTR_CONTROL base address */
#define SYS_CTR_CONTROL_BASE (0x44290000u)
/** Peripheral SYS_CTR_CONTROL base pointer */
#define SYS_CTR_CONTROL      ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE)
/** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
#define SYS_CTR_CONTROL_BASE_ADDRS \
    {                              \
        SYS_CTR_CONTROL_BASE       \
    }
/** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
#define SYS_CTR_CONTROL_BASE_PTRS \
    {                             \
        SYS_CTR_CONTROL           \
    }
#endif

/*!
 * @}
 */ /* end of group SYS_CTR_CONTROL_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_SYS_CTR_CONTROL_H_) */
