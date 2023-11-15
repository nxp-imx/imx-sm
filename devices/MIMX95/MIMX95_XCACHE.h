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
 * @file MIMX95_XCACHE.h
 * @version 1.0
 * @date 2021-11-16
 * @brief CMSIS Peripheral Access Layer for MIMX95_XCACHE
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_XCACHE_H_)  /* Check if memory map has not been already included */
#define MIMX95_XCACHE_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- XCACHE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCACHE_Peripheral_Access_Layer XCACHE Peripheral Access Layer
 * @{
 */

/** XCACHE - Register Layout Typedef */
typedef struct
{
    __IO uint32_t CCR;  /**< Cache control register, offset: 0x0 */
    __IO uint32_t CLCR; /**< Cache line control register, offset: 0x4 */
    __IO uint32_t CSAR; /**< Cache search address register, offset: 0x8 */
    __IO uint32_t CCVR; /**< Cache read/write value register, offset: 0xC */
    __IO uint32_t CSRR; /**< Cache soft reset register, offset: 0x10 */
} XCACHE_Type;

/* ----------------------------------------------------------------------------
   -- XCACHE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCACHE_Register_Masks XCACHE Register Masks
 * @{
 */

/*! @name CCR - Cache control register */
/*! @{ */

#define XCACHE_CCR_ENCACHE_MASK  (0x1U)
#define XCACHE_CCR_ENCACHE_SHIFT (0U)
/*! ENCACHE - Cache enable
 *  0b0..Cache disabled
 *  0b1..Cache enabled
 */
#define XCACHE_CCR_ENCACHE(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_ENCACHE_SHIFT)) & XCACHE_CCR_ENCACHE_MASK)

#define XCACHE_CCR_INVW0_MASK  (0x1000000U)
#define XCACHE_CCR_INVW0_SHIFT (24U)
/*! INVW0 - Invalidate Way 0
 *  0b0..No operation
 *  0b1..When setting the GO bit, invalidate all lines in way 0.
 */
#define XCACHE_CCR_INVW0(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_INVW0_SHIFT)) & XCACHE_CCR_INVW0_MASK)

#define XCACHE_CCR_PUSHW0_MASK  (0x2000000U)
#define XCACHE_CCR_PUSHW0_SHIFT (25U)
/*! PUSHW0 - Push Way 0
 *  0b0..No operation
 *  0b1..When setting the GO bit, push all modified lines in way 0
 */
#define XCACHE_CCR_PUSHW0(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_PUSHW0_SHIFT)) & XCACHE_CCR_PUSHW0_MASK)

#define XCACHE_CCR_INVW1_MASK  (0x4000000U)
#define XCACHE_CCR_INVW1_SHIFT (26U)
/*! INVW1 - Invalidate Way 1
 *  0b0..No operation
 *  0b1..When setting the GO bit, invalidate all lines in way 1
 */
#define XCACHE_CCR_INVW1(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_INVW1_SHIFT)) & XCACHE_CCR_INVW1_MASK)

#define XCACHE_CCR_PUSHW1_MASK  (0x8000000U)
#define XCACHE_CCR_PUSHW1_SHIFT (27U)
/*! PUSHW1 - Push Way 1
 *  0b0..No operation
 *  0b1..When setting the GO bit, push all modified lines in way 1
 */
#define XCACHE_CCR_PUSHW1(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_PUSHW1_SHIFT)) & XCACHE_CCR_PUSHW1_MASK)

#define XCACHE_CCR_GO_MASK  (0x80000000U)
#define XCACHE_CCR_GO_SHIFT (31U)
/*! GO - Initiate Cache Command
 *  0b0..Write: no effect. Read: no cache command active.
 *  0b1..Write: initiate command indicated by bits 27-24. Read: cache command active.
 */
#define XCACHE_CCR_GO(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CCR_GO_SHIFT)) & XCACHE_CCR_GO_MASK)
/*! @} */

/*! @name CLCR - Cache line control register */
/*! @{ */

#define XCACHE_CLCR_LGO_MASK  (0x1U)
#define XCACHE_CLCR_LGO_SHIFT (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command indicated by bits 27-24. Read: line command active.
 */
#define XCACHE_CLCR_LGO(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LGO_SHIFT)) & XCACHE_CLCR_LGO_MASK)

#define XCACHE_CLCR_CACHEADDR_MASK  (0x3FFCU)
#define XCACHE_CLCR_CACHEADDR_SHIFT (2U)
/*! CACHEADDR - Cache address
 */
#define XCACHE_CLCR_CACHEADDR(x) \
    (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_CACHEADDR_SHIFT)) & XCACHE_CLCR_CACHEADDR_MASK)

#define XCACHE_CLCR_WSEL_MASK  (0x4000U)
#define XCACHE_CLCR_WSEL_SHIFT (14U)
/*! WSEL - Way select
 *  0b0..Way 0
 *  0b1..Way 1
 */
#define XCACHE_CLCR_WSEL(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_WSEL_SHIFT)) & XCACHE_CLCR_WSEL_MASK)

#define XCACHE_CLCR_TDSEL_MASK  (0x10000U)
#define XCACHE_CLCR_TDSEL_SHIFT (16U)
/*! TDSEL - Tag/Data Select
 *  0b0..Data
 *  0b1..Tag
 */
#define XCACHE_CLCR_TDSEL(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_TDSEL_SHIFT)) & XCACHE_CLCR_TDSEL_MASK)

#define XCACHE_CLCR_LCIVB_MASK  (0x100000U)
#define XCACHE_CLCR_LCIVB_SHIFT (20U)
/*! LCIVB - Line Command Initial Valid Bit
 */
#define XCACHE_CLCR_LCIVB(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCIVB_SHIFT)) & XCACHE_CLCR_LCIVB_MASK)

#define XCACHE_CLCR_LCIMB_MASK  (0x200000U)
#define XCACHE_CLCR_LCIMB_SHIFT (21U)
/*! LCIMB - Line Command Initial Modified Bit
 */
#define XCACHE_CLCR_LCIMB(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCIMB_SHIFT)) & XCACHE_CLCR_LCIMB_MASK)

#define XCACHE_CLCR_LCWAY_MASK  (0x400000U)
#define XCACHE_CLCR_LCWAY_SHIFT (22U)
/*! LCWAY - Line Command Way
 */
#define XCACHE_CLCR_LCWAY(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCWAY_SHIFT)) & XCACHE_CLCR_LCWAY_MASK)

#define XCACHE_CLCR_LCMD_MASK  (0x3000000U)
#define XCACHE_CLCR_LCMD_SHIFT (24U)
/*! LCMD - Line Command
 *  0b00..Search and read or write
 *  0b01..Invalidate
 *  0b10..Push
 *  0b11..Clear
 */
#define XCACHE_CLCR_LCMD(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LCMD_SHIFT)) & XCACHE_CLCR_LCMD_MASK)

#define XCACHE_CLCR_LADSEL_MASK  (0x4000000U)
#define XCACHE_CLCR_LADSEL_SHIFT (26U)
/*! LADSEL - Line Address Select
 *  0b0..Cache address
 *  0b1..Physical address
 */
#define XCACHE_CLCR_LADSEL(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LADSEL_SHIFT)) & XCACHE_CLCR_LADSEL_MASK)

#define XCACHE_CLCR_LACC_MASK  (0x8000000U)
#define XCACHE_CLCR_LACC_SHIFT (27U)
/*! LACC - Line access type
 *  0b0..Read
 *  0b1..Write
 */
#define XCACHE_CLCR_LACC(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CLCR_LACC_SHIFT)) & XCACHE_CLCR_LACC_MASK)
/*! @} */

/*! @name CSAR - Cache search address register */
/*! @{ */

#define XCACHE_CSAR_LGO_MASK  (0x1U)
#define XCACHE_CSAR_LGO_SHIFT (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command indicated by bits CLCR[27:24]. Read: line command active.
 */
#define XCACHE_CSAR_LGO(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CSAR_LGO_SHIFT)) & XCACHE_CSAR_LGO_MASK)

#define XCACHE_CSAR_PHYADDR_MASK  (0xFFFFFFFCU)
#define XCACHE_CSAR_PHYADDR_SHIFT (2U)
/*! PHYADDR - Physical Address
 */
#define XCACHE_CSAR_PHYADDR(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CSAR_PHYADDR_SHIFT)) & XCACHE_CSAR_PHYADDR_MASK)
/*! @} */

/*! @name CCVR - Cache read/write value register */
/*! @{ */

#define XCACHE_CCVR_DATA_MASK  (0xFFFFFFFFU)
#define XCACHE_CCVR_DATA_SHIFT (0U)
/*! DATA - Cache read/write Data
 */
#define XCACHE_CCVR_DATA(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CCVR_DATA_SHIFT)) & XCACHE_CCVR_DATA_MASK)
/*! @} */

/*! @name CSRR - Cache soft reset register */
/*! @{ */

#define XCACHE_CSRR_RESET_MASK  (0x3U)
#define XCACHE_CSRR_RESET_SHIFT (0U)
/*! RESET - Issue soft reset
 */
#define XCACHE_CSRR_RESET(x) (((uint32_t)(((uint32_t)(x)) << XCACHE_CSRR_RESET_SHIFT)) & XCACHE_CSRR_RESET_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group XCACHE_Register_Masks */

/* XCACHE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** Peripheral LPCAC_PC base address */
#define LPCAC_PC_BASE (0x54400000u)
/** Peripheral LPCAC_PC base address */
#define LPCAC_PC_BASE_NS (0x44400000u)
/** Peripheral LPCAC_PC base pointer */
#define LPCAC_PC ((XCACHE_Type *)LPCAC_PC_BASE)
/** Peripheral LPCAC_PC base pointer */
#define LPCAC_PC_NS ((XCACHE_Type *)LPCAC_PC_BASE_NS)
/** Peripheral LPCAC_PS base address */
#define LPCAC_PS_BASE (0x54400800u)
/** Peripheral LPCAC_PS base address */
#define LPCAC_PS_BASE_NS (0x44400800u)
/** Peripheral LPCAC_PS base pointer */
#define LPCAC_PS ((XCACHE_Type *)LPCAC_PS_BASE)
/** Peripheral LPCAC_PS base pointer */
#define LPCAC_PS_NS ((XCACHE_Type *)LPCAC_PS_BASE_NS)
/** Array initializer of XCACHE peripheral base addresses */
#define XCACHE_BASE_ADDRS            \
    {                                \
        LPCAC_PC_BASE, LPCAC_PS_BASE \
    }
/** Array initializer of XCACHE peripheral base pointers */
#define XCACHE_BASE_PTRS   \
    {                      \
        LPCAC_PC, LPCAC_PS \
    }
/** Array initializer of XCACHE peripheral base addresses */
#define XCACHE_BASE_ADDRS_NS               \
    {                                      \
        LPCAC_PC_BASE_NS, LPCAC_PS_BASE_NS \
    }
/** Array initializer of XCACHE peripheral base pointers */
#define XCACHE_BASE_PTRS_NS      \
    {                            \
        LPCAC_PC_NS, LPCAC_PS_NS \
    }
#else
/** Peripheral LPCAC_PC base address */
#define LPCAC_PC_BASE (0x44400000u)
/** Peripheral LPCAC_PC base pointer */
#define LPCAC_PC      ((XCACHE_Type *)LPCAC_PC_BASE)
/** Peripheral LPCAC_PS base address */
#define LPCAC_PS_BASE (0x44400800u)
/** Peripheral LPCAC_PS base pointer */
#define LPCAC_PS      ((XCACHE_Type *)LPCAC_PS_BASE)
/** Array initializer of XCACHE peripheral base addresses */
#define XCACHE_BASE_ADDRS            \
    {                                \
        LPCAC_PC_BASE, LPCAC_PS_BASE \
    }
/** Array initializer of XCACHE peripheral base pointers */
#define XCACHE_BASE_PTRS   \
    {                      \
        LPCAC_PC, LPCAC_PS \
    }
#endif
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** XCACHE physical memory base address */
#define XCACHE_PHYMEM_BASES      \
    {                            \
        0x38000000u, 0x90000000u \
    }
/** XCACHE physical memory size */
#define XCACHE_PHYMEM_SIZES      \
    {                            \
        0x08000000u, 0x50000000u \
    }
/** XCACHE physical memory base address */
#define XCACHE_PHYMEM_BASES_NS   \
    {                            \
        0x28000000u, 0x80000000u \
    }
/** XCACHE physical memory size */
#define XCACHE_PHYMEM_SIZES_NS   \
    {                            \
        0x08000000u, 0x50000000u \
    }
#else
/** XCACHE physical memory base address */
#define XCACHE_PHYMEM_BASES      \
    {                            \
        0x28000000u, 0x80000000u \
    }
/** XCACHE physical memory size */
#define XCACHE_PHYMEM_SIZES      \
    {                            \
        0x08000000u, 0x50000000u \
    }
#endif

/*!
 * @}
 */ /* end of group XCACHE_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_XCACHE_H_) */
