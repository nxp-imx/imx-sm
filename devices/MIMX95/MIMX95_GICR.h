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
 * @file MIMX95_GICR.h
 * @version
 * @date
 * @brief CMSIS Peripheral Access Layer for MIMX95_GICR
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_GICR_H_)  /* Check if memory map has not been already included */
#define MIMX95_GICR_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- GICR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GICR_Peripheral_Access_Layer GICR Peripheral Access Layer
 * @{
 */

/** GICR - Register Layout Typedef */
typedef struct {
    __IO uint32_t GICR_CTLR;                        /**< GICR_CTLR, offset: 0x0 */
    __I  uint32_t GICR_IIDR;                        /**< GICR_IIDR, offset: 0x4 */
    __I  uint64_t GICR_TYPER;                       /**< GICR_TYPER, offset: 0x8 */
    __I  uint32_t GICR_STATUSR;                     /**< GICR_STATUSR, offset: 0x10 */
    __IO uint32_t GICR_WAKER;                       /**< GICR_WAKER, offset: 0x14 */
    __I  uint32_t GICR_MPAMIDR;                     /**< GICR_MPAMIDR, offset: 0x18 */
    __IO uint32_t GICR_PARTIDR;                     /**< GICR_PARTIDR, offset: 0x1C */
    __IO uint32_t GICR_FCTLR;                       /**< GICR_FCTLR, offset: 0x20 */
    __IO uint32_t GICR_PWRR;                        /**< GICR_PWRR, offset: 0x24 */
    __IO uint32_t GICR_CLASS;                       /**< GICR_CLASS, offset: 0x28 */
} GICR_Type;

/* ----------------------------------------------------------------------------
   -- GICR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GICR_Register_Masks GICR Register Masks
 * @{
 */

/*! @name GICR_CTLR - GICR_CTLR */
/*! @{ */

#define GICR_CTLR_ENABLELPIS_MASK  (0x1U)
#define GICR_CTLR_ENABLELPIS_SHIFT (0U)
/*! EnableLPIs - EnableLPIs */
#define GICR_CTLR_ENABLELPIS(x)    (((uint32_t)(((uint32_t)(x)) << GICR_CTLR_ENABLELPIS_SHIFT)) & GICR_CTLR_ENABLELPIS_MASK)

#define GICR_CTLR_CES_MASK         (0x2U)
#define GICR_CTLR_CES_SHIFT        (1U)
/*! CES - CES */
#define GICR_CTLR_CES(x)           (((uint32_t)(((uint32_t)(x)) << GICR_CTLR_CES_SHIFT)) & GICR_CTLR_CES_MASK)

#define GICR_CTLR_IR_MASK          (0x4U)
#define GICR_CTLR_IR_SHIFT         (2U)
/*! IR - IR */
#define GICR_CTLR_IR(x)            (((uint32_t)(((uint32_t)(x)) << GICR_CTLR_IR_SHIFT)) & GICR_CTLR_IR_MASK)

#define GICR_CTLR_RWP_MASK         (0x8U)
#define GICR_CTLR_RWP_SHIFT        (3U)
/*! RWP - RWP */
#define GICR_CTLR_RWP(x)           (((uint32_t)(((uint32_t)(x)) << GICR_CTLR_RWP_SHIFT)) & GICR_CTLR_RWP_MASK)

#define GICR_CTLR_RESERVED1_MASK   (0xFFFFF0U)
#define GICR_CTLR_RESERVED1_SHIFT  (4U)
/*! RESERVED1 - RESERVED1 */
#define GICR_CTLR_RESERVED1(x)     (((uint32_t)(((uint32_t)(x)) << GICR_CTLR_RESERVED1_SHIFT)) & GICR_CTLR_RESERVED1_MASK)

#define GICR_CTLR_DPG0_MASK        (0x1000000U)
#define GICR_CTLR_DPG0_SHIFT       (24U)
/*! DPG0 - DPG0 */
#define GICR_CTLR_DPG0(x)          (((uint32_t)(((uint32_t)(x)) << GICR_CTLR_DPG0_SHIFT)) & GICR_CTLR_DPG0_MASK)

#define GICR_CTLR_DPG1NS_MASK      (0x2000000U)
#define GICR_CTLR_DPG1NS_SHIFT     (25U)
/*! DPG1NS - DPG1NS */
#define GICR_CTLR_DPG1NS(x)        (((uint32_t)(((uint32_t)(x)) << GICR_CTLR_DPG1NS_SHIFT)) & GICR_CTLR_DPG1NS_MASK)

#define GICR_CTLR_DPG1S_MASK       (0x4000000U)
#define GICR_CTLR_DPG1S_SHIFT      (26U)
/*! DPG1S - DPG1S */
#define GICR_CTLR_DPG1S(x)         (((uint32_t)(((uint32_t)(x)) << GICR_CTLR_DPG1S_SHIFT)) & GICR_CTLR_DPG1S_MASK)

#define GICR_CTLR_RESERVED2_MASK   (0x78000000U)
#define GICR_CTLR_RESERVED2_SHIFT  (27U)
/*! RESERVED2 - RESERVED2 */
#define GICR_CTLR_RESERVED2(x)     (((uint32_t)(((uint32_t)(x)) << GICR_CTLR_RESERVED2_SHIFT)) & GICR_CTLR_RESERVED2_MASK)

#define GICR_CTLR_UWP_MASK         (0x80000000U)
#define GICR_CTLR_UWP_SHIFT        (31U)
/*! UWP - UWP */
#define GICR_CTLR_UWP(x)           (((uint32_t)(((uint32_t)(x)) << GICR_CTLR_UWP_SHIFT)) & GICR_CTLR_UWP_MASK)
/*! @} */

/*! @name GICR_IIDR - GICR_IIDR */
/*! @{ */

#define GICR_IIDR_IMPLEMENTER_MASK (0xFFFU)
#define GICR_IIDR_IMPLEMENTER_SHIFT (0U)
/*! Implementer - Implementer */
#define GICR_IIDR_IMPLEMENTER(x)   (((uint32_t)(((uint32_t)(x)) << GICR_IIDR_IMPLEMENTER_SHIFT)) & GICR_IIDR_IMPLEMENTER_MASK)

#define GICR_IIDR_REVISION_MASK    (0xF000U)
#define GICR_IIDR_REVISION_SHIFT   (12U)
/*! Revision - Revision */
#define GICR_IIDR_REVISION(x)      (((uint32_t)(((uint32_t)(x)) << GICR_IIDR_REVISION_SHIFT)) & GICR_IIDR_REVISION_MASK)

#define GICR_IIDR_VARIANT_MASK     (0xF0000U)
#define GICR_IIDR_VARIANT_SHIFT    (16U)
/*! Variant - Variant */
#define GICR_IIDR_VARIANT(x)       (((uint32_t)(((uint32_t)(x)) << GICR_IIDR_VARIANT_SHIFT)) & GICR_IIDR_VARIANT_MASK)

#define GICR_IIDR_RESERVED0_MASK   (0xF00000U)
#define GICR_IIDR_RESERVED0_SHIFT  (20U)
/*! RESERVED0 - RESERVED0 */
#define GICR_IIDR_RESERVED0(x)     (((uint32_t)(((uint32_t)(x)) << GICR_IIDR_RESERVED0_SHIFT)) & GICR_IIDR_RESERVED0_MASK)

#define GICR_IIDR_PRODUCTID_MASK   (0xFF000000U)
#define GICR_IIDR_PRODUCTID_SHIFT  (24U)
/*! ProductID - ProductID */
#define GICR_IIDR_PRODUCTID(x)     (((uint32_t)(((uint32_t)(x)) << GICR_IIDR_PRODUCTID_SHIFT)) & GICR_IIDR_PRODUCTID_MASK)
/*! @} */

/*! @name GICR_TYPER - GICR_TYPER */
/*! @{ */

#define GICR_TYPER_PLPIS_MASK      (0x1U)
#define GICR_TYPER_PLPIS_SHIFT     (0U)
/*! PLPIS - PLPIS */
#define GICR_TYPER_PLPIS(x)        (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_PLPIS_SHIFT)) & GICR_TYPER_PLPIS_MASK)

#define GICR_TYPER_VLPIS_MASK      (0x2U)
#define GICR_TYPER_VLPIS_SHIFT     (1U)
/*! VLPIS - VLPIS */
#define GICR_TYPER_VLPIS(x)        (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_VLPIS_SHIFT)) & GICR_TYPER_VLPIS_MASK)

#define GICR_TYPER_DIRTY_MASK      (0x4U)
#define GICR_TYPER_DIRTY_SHIFT     (2U)
/*! Dirty - Dirty */
#define GICR_TYPER_DIRTY(x)        (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_DIRTY_SHIFT)) & GICR_TYPER_DIRTY_MASK)

#define GICR_TYPER_DIRECTLPI_MASK  (0x8U)
#define GICR_TYPER_DIRECTLPI_SHIFT (3U)
/*! DirectLPI - DirectLPI */
#define GICR_TYPER_DIRECTLPI(x)    (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_DIRECTLPI_SHIFT)) & GICR_TYPER_DIRECTLPI_MASK)

#define GICR_TYPER_LAST_MASK       (0x10U)
#define GICR_TYPER_LAST_SHIFT      (4U)
/*! Last - Last */
#define GICR_TYPER_LAST(x)         (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_LAST_SHIFT)) & GICR_TYPER_LAST_MASK)

#define GICR_TYPER_DPGS_MASK       (0x20U)
#define GICR_TYPER_DPGS_SHIFT      (5U)
/*! DPGS - DPGS */
#define GICR_TYPER_DPGS(x)         (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_DPGS_SHIFT)) & GICR_TYPER_DPGS_MASK)

#define GICR_TYPER_MPAM_MASK       (0x40U)
#define GICR_TYPER_MPAM_SHIFT      (6U)
/*! MPAM - MPAM */
#define GICR_TYPER_MPAM(x)         (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_MPAM_SHIFT)) & GICR_TYPER_MPAM_MASK)

#define GICR_TYPER_RVPEID_MASK     (0x80U)
#define GICR_TYPER_RVPEID_SHIFT    (7U)
/*! RVPEID - RVPEID */
#define GICR_TYPER_RVPEID(x)       (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_RVPEID_SHIFT)) & GICR_TYPER_RVPEID_MASK)

#define GICR_TYPER_PROCESSORNUMBER_MASK (0xFFFF00U)
#define GICR_TYPER_PROCESSORNUMBER_SHIFT (8U)
/*! ProcessorNumber - ProcessorNumber */
#define GICR_TYPER_PROCESSORNUMBER(x) (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_PROCESSORNUMBER_SHIFT)) & GICR_TYPER_PROCESSORNUMBER_MASK)

#define GICR_TYPER_COMMONLPIAFF_MASK (0x3000000U)
#define GICR_TYPER_COMMONLPIAFF_SHIFT (24U)
/*! CommonLPIAff - CommonLPIAff */
#define GICR_TYPER_COMMONLPIAFF(x) (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_COMMONLPIAFF_SHIFT)) & GICR_TYPER_COMMONLPIAFF_MASK)

#define GICR_TYPER_VSGI_MASK       (0x4000000U)
#define GICR_TYPER_VSGI_SHIFT      (26U)
/*! VSGI - VSGI */
#define GICR_TYPER_VSGI(x)         (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_VSGI_SHIFT)) & GICR_TYPER_VSGI_MASK)

#define GICR_TYPER_PPINUM_MASK     (0xF8000000U)
#define GICR_TYPER_PPINUM_SHIFT    (27U)
/*! PPInum - PPInum */
#define GICR_TYPER_PPINUM(x)       (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_PPINUM_SHIFT)) & GICR_TYPER_PPINUM_MASK)

#define GICR_TYPER_AFFINITYVALUE_MASK (0xFFFFFFFF00000000U)
#define GICR_TYPER_AFFINITYVALUE_SHIFT (32U)
/*! AffinityValue - AffinityValue */
#define GICR_TYPER_AFFINITYVALUE(x) (((uint64_t)(((uint64_t)(x)) << GICR_TYPER_AFFINITYVALUE_SHIFT)) & GICR_TYPER_AFFINITYVALUE_MASK)
/*! @} */

/*! @name GICR_STATUSR - GICR_STATUSR */
/*! @{ */

#define GICR_STATUSR_RESERVED_MASK (0xFFFFFFFFU)
#define GICR_STATUSR_RESERVED_SHIFT (0U)
/*! RESERVED - RESERVED */
#define GICR_STATUSR_RESERVED(x)   (((uint32_t)(((uint32_t)(x)) << GICR_STATUSR_RESERVED_SHIFT)) & GICR_STATUSR_RESERVED_MASK)
/*! @} */

/*! @name GICR_WAKER - GICR_WAKER */
/*! @{ */

#define GICR_WAKER_SLEEP_MASK      (0x1U)
#define GICR_WAKER_SLEEP_SHIFT     (0U)
/*! Sleep - Sleep */
#define GICR_WAKER_SLEEP(x)        (((uint32_t)(((uint32_t)(x)) << GICR_WAKER_SLEEP_SHIFT)) & GICR_WAKER_SLEEP_MASK)

#define GICR_WAKER_PROCESSORSLEEP_MASK (0x2U)
#define GICR_WAKER_PROCESSORSLEEP_SHIFT (1U)
/*! ProcessorSleep - ProcessorSleep */
#define GICR_WAKER_PROCESSORSLEEP(x) (((uint32_t)(((uint32_t)(x)) << GICR_WAKER_PROCESSORSLEEP_SHIFT)) & GICR_WAKER_PROCESSORSLEEP_MASK)

#define GICR_WAKER_CHILDRENASLEEP_MASK (0x4U)
#define GICR_WAKER_CHILDRENASLEEP_SHIFT (2U)
/*! ChildrenAsleep - ChildrenAsleep */
#define GICR_WAKER_CHILDRENASLEEP(x) (((uint32_t)(((uint32_t)(x)) << GICR_WAKER_CHILDRENASLEEP_SHIFT)) & GICR_WAKER_CHILDRENASLEEP_MASK)

#define GICR_WAKER_RESERVED0_MASK  (0x7FFFFFF8U)
#define GICR_WAKER_RESERVED0_SHIFT (3U)
/*! RESERVED0 - RESERVED0 */
#define GICR_WAKER_RESERVED0(x)    (((uint32_t)(((uint32_t)(x)) << GICR_WAKER_RESERVED0_SHIFT)) & GICR_WAKER_RESERVED0_MASK)

#define GICR_WAKER_QUIESCENT_MASK  (0x80000000U)
#define GICR_WAKER_QUIESCENT_SHIFT (31U)
/*! Quiescent - Quiescent */
#define GICR_WAKER_QUIESCENT(x)    (((uint32_t)(((uint32_t)(x)) << GICR_WAKER_QUIESCENT_SHIFT)) & GICR_WAKER_QUIESCENT_MASK)
/*! @} */

/*! @name GICR_MPAMIDR - GICR_MPAMIDR */
/*! @{ */

#define GICR_MPAMIDR_PARTID_MAX_MASK (0x1FFU)
#define GICR_MPAMIDR_PARTID_MAX_SHIFT (0U)
/*! PARTID_MAX - PARTID_MAX */
#define GICR_MPAMIDR_PARTID_MAX(x) (((uint32_t)(((uint32_t)(x)) << GICR_MPAMIDR_PARTID_MAX_SHIFT)) & GICR_MPAMIDR_PARTID_MAX_MASK)

#define GICR_MPAMIDR_RESERVED0_MASK (0xFE00U)
#define GICR_MPAMIDR_RESERVED0_SHIFT (9U)
/*! RESERVED0 - RESERVED0 */
#define GICR_MPAMIDR_RESERVED0(x)  (((uint32_t)(((uint32_t)(x)) << GICR_MPAMIDR_RESERVED0_SHIFT)) & GICR_MPAMIDR_RESERVED0_MASK)

#define GICR_MPAMIDR_PMG_MAX_MASK  (0x10000U)
#define GICR_MPAMIDR_PMG_MAX_SHIFT (16U)
/*! PMG_MAX - PMG_MAX */
#define GICR_MPAMIDR_PMG_MAX(x)    (((uint32_t)(((uint32_t)(x)) << GICR_MPAMIDR_PMG_MAX_SHIFT)) & GICR_MPAMIDR_PMG_MAX_MASK)

#define GICR_MPAMIDR_RESERVED1_MASK (0xFFFE0000U)
#define GICR_MPAMIDR_RESERVED1_SHIFT (17U)
/*! RESERVED1 - RESERVED1 */
#define GICR_MPAMIDR_RESERVED1(x)  (((uint32_t)(((uint32_t)(x)) << GICR_MPAMIDR_RESERVED1_SHIFT)) & GICR_MPAMIDR_RESERVED1_MASK)
/*! @} */

/*! @name GICR_PARTIDR - GICR_PARTIDR */
/*! @{ */

#define GICR_PARTIDR_PARTID_MASK   (0x1FFU)
#define GICR_PARTIDR_PARTID_SHIFT  (0U)
/*! PARTID - PARTID */
#define GICR_PARTIDR_PARTID(x)     (((uint32_t)(((uint32_t)(x)) << GICR_PARTIDR_PARTID_SHIFT)) & GICR_PARTIDR_PARTID_MASK)

#define GICR_PARTIDR_RESERVED0_MASK (0xFE00U)
#define GICR_PARTIDR_RESERVED0_SHIFT (9U)
/*! RESERVED0 - RESERVED0 */
#define GICR_PARTIDR_RESERVED0(x)  (((uint32_t)(((uint32_t)(x)) << GICR_PARTIDR_RESERVED0_SHIFT)) & GICR_PARTIDR_RESERVED0_MASK)

#define GICR_PARTIDR_PMG_MASK      (0x10000U)
#define GICR_PARTIDR_PMG_SHIFT     (16U)
/*! PMG - PMG */
#define GICR_PARTIDR_PMG(x)        (((uint32_t)(((uint32_t)(x)) << GICR_PARTIDR_PMG_SHIFT)) & GICR_PARTIDR_PMG_MASK)

#define GICR_PARTIDR_RESERVED1_MASK (0xFFFE0000U)
#define GICR_PARTIDR_RESERVED1_SHIFT (17U)
/*! RESERVED1 - RESERVED1 */
#define GICR_PARTIDR_RESERVED1(x)  (((uint32_t)(((uint32_t)(x)) << GICR_PARTIDR_RESERVED1_SHIFT)) & GICR_PARTIDR_RESERVED1_MASK)
/*! @} */

/*! @name GICR_FCTLR - GICR_FCTLR */
/*! @{ */

#define GICR_FCTLR_SIP_MASK        (0x1U)
#define GICR_FCTLR_SIP_SHIFT       (0U)
/*! SIP - SIP */
#define GICR_FCTLR_SIP(x)          (((uint32_t)(((uint32_t)(x)) << GICR_FCTLR_SIP_SHIFT)) & GICR_FCTLR_SIP_MASK)

#define GICR_FCTLR_QDENY_MASK      (0x2U)
#define GICR_FCTLR_QDENY_SHIFT     (1U)
/*! QDeny - QDeny */
#define GICR_FCTLR_QDENY(x)        (((uint32_t)(((uint32_t)(x)) << GICR_FCTLR_QDENY_SHIFT)) & GICR_FCTLR_QDENY_MASK)

#define GICR_FCTLR_CGO_MASK        (0x1CU)
#define GICR_FCTLR_CGO_SHIFT       (2U)
/*! CGO - CGO */
#define GICR_FCTLR_CGO(x)          (((uint32_t)(((uint32_t)(x)) << GICR_FCTLR_CGO_SHIFT)) & GICR_FCTLR_CGO_MASK)

#define GICR_FCTLR_RESERVED0_MASK  (0x3E0U)
#define GICR_FCTLR_RESERVED0_SHIFT (5U)
/*! RESERVED0 - RESERVED0 */
#define GICR_FCTLR_RESERVED0(x)    (((uint32_t)(((uint32_t)(x)) << GICR_FCTLR_RESERVED0_SHIFT)) & GICR_FCTLR_RESERVED0_MASK)

#define GICR_FCTLR_RESERVED1_MASK  (0xFFFFFC00U)
#define GICR_FCTLR_RESERVED1_SHIFT (10U)
/*! RESERVED1 - RESERVED1 */
#define GICR_FCTLR_RESERVED1(x)    (((uint32_t)(((uint32_t)(x)) << GICR_FCTLR_RESERVED1_SHIFT)) & GICR_FCTLR_RESERVED1_MASK)
/*! @} */

/*! @name GICR_PWRR - GICR_PWRR */
/*! @{ */

#define GICR_PWRR_RDPD_MASK        (0x1U)
#define GICR_PWRR_RDPD_SHIFT       (0U)
/*! RDPD - RDPD */
#define GICR_PWRR_RDPD(x)          (((uint32_t)(((uint32_t)(x)) << GICR_PWRR_RDPD_SHIFT)) & GICR_PWRR_RDPD_MASK)

#define GICR_PWRR_RDAG_MASK        (0x2U)
#define GICR_PWRR_RDAG_SHIFT       (1U)
/*! RDAG - RDAG */
#define GICR_PWRR_RDAG(x)          (((uint32_t)(((uint32_t)(x)) << GICR_PWRR_RDAG_SHIFT)) & GICR_PWRR_RDAG_MASK)

#define GICR_PWRR_RDGPD_MASK       (0x4U)
#define GICR_PWRR_RDGPD_SHIFT      (2U)
/*! RDGPD - RDGPD */
#define GICR_PWRR_RDGPD(x)         (((uint32_t)(((uint32_t)(x)) << GICR_PWRR_RDGPD_SHIFT)) & GICR_PWRR_RDGPD_MASK)

#define GICR_PWRR_RDGPO_MASK       (0x8U)
#define GICR_PWRR_RDGPO_SHIFT      (3U)
/*! RDGPO - RDGPO */
#define GICR_PWRR_RDGPO(x)         (((uint32_t)(((uint32_t)(x)) << GICR_PWRR_RDGPO_SHIFT)) & GICR_PWRR_RDGPO_MASK)

#define GICR_PWRR_RESERVED0_MASK   (0xF0U)
#define GICR_PWRR_RESERVED0_SHIFT  (4U)
/*! RESERVED0 - RESERVED0 */
#define GICR_PWRR_RESERVED0(x)     (((uint32_t)(((uint32_t)(x)) << GICR_PWRR_RESERVED0_SHIFT)) & GICR_PWRR_RESERVED0_MASK)

#define GICR_PWRR_RDGO_MASK        (0x7F00U)
#define GICR_PWRR_RDGO_SHIFT       (8U)
/*! RDGO - RDGO */
#define GICR_PWRR_RDGO(x)          (((uint32_t)(((uint32_t)(x)) << GICR_PWRR_RDGO_SHIFT)) & GICR_PWRR_RDGO_MASK)

#define GICR_PWRR_RDG_MASK         (0xFF8000U)
#define GICR_PWRR_RDG_SHIFT        (15U)
/*! RDG - RDG */
#define GICR_PWRR_RDG(x)           (((uint32_t)(((uint32_t)(x)) << GICR_PWRR_RDG_SHIFT)) & GICR_PWRR_RDG_MASK)

#define GICR_PWRR_RESERVED1_MASK   (0xFF000000U)
#define GICR_PWRR_RESERVED1_SHIFT  (24U)
/*! RESERVED1 - RESERVED1 */
#define GICR_PWRR_RESERVED1(x)     (((uint32_t)(((uint32_t)(x)) << GICR_PWRR_RESERVED1_SHIFT)) & GICR_PWRR_RESERVED1_MASK)
/*! @} */

/*! @name GICR_CLASS - GICR_CLASS */
/*! @{ */

#define GICR_CLASS_CLASS_MASK      (0x1U)
#define GICR_CLASS_CLASS_SHIFT     (0U)
/*! Class - Class */
#define GICR_CLASS_CLASS(x)        (((uint32_t)(((uint32_t)(x)) << GICR_CLASS_CLASS_SHIFT)) & GICR_CLASS_CLASS_MASK)

#define GICR_CLASS_RESERVED0_MASK  (0xFFFFFFFEU)
#define GICR_CLASS_RESERVED0_SHIFT (1U)
/*! RESERVED0 - RESERVED0 */
#define GICR_CLASS_RESERVED0(x)    (((uint32_t)(((uint32_t)(x)) << GICR_CLASS_RESERVED0_SHIFT)) & GICR_CLASS_RESERVED0_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group GICR_Register_Masks */

/* GICR - Peripheral instance base addresses */
/** Peripheral GICR0 base address */
#define GICR0_BASE                                  (0x48060000u)
/** Peripheral GICR0 base pointer */
#define GICR0                                       ((GICR_Type *)GICR0_BASE)

/** Peripheral GICR1 base address */
#define GICR1_BASE                                  (0x48080000u)
/** Peripheral GICR1 base pointer */
#define GICR1                                       ((GICR_Type *)GICR1_BASE)

/** Peripheral GICR2 base address */
#define GICR2_BASE                                  (0x480A0000u)
/** Peripheral GICR2 base pointer */
#define GICR2                                       ((GICR_Type *)GICR2_BASE)

/** Peripheral GICR3 base address */
#define GICR3_BASE                                  (0x480C0000u)
/** Peripheral GICR3 base pointer */
#define GICR3                                       ((GICR_Type *)GICR3_BASE)

/** Peripheral GICR4 base address */
#define GICR4_BASE                                  (0x480E0000u)
/** Peripheral GICR4 base pointer */
#define GICR4                                       ((GICR_Type *)GICR4_BASE)

/** Peripheral GICR5 base address */
#define GICR5_BASE                                  (0x48100000u)
/** Peripheral GICR5 base pointer */
#define GICR5                                       ((GICR_Type *)GICR5_BASE)

/** Array initializer of NOC_GICRLPI0 peripheral base addresses */
#define GICR_BASE_ADDRS                             { GICR0_BASE, GICR1_BASE, GICR2_BASE, GICR3_BASE, GICR4_BASE, GICR5_BASE}
/** Array initializer of NOC_GICRLPI0 peripheral base pointers */
#define GICR_BASE_PTRS                              { GICR0, GICR1, GICR2, GICR3, GICR4, GICR5 }

/*!
 * @}
 */ /* end of group GICR_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_GICR_H_) */
