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
 * @file MIMX95_IOMUXC_GPR.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for MIMX95_IOMUXC_GPR
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_IOMUXC_GPR_H_)  /* Check if memory map has not been already included */
#define MIMX95_IOMUXC_GPR_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- IOMUXC_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_GPR_Peripheral_Access_Layer IOMUXC_GPR Peripheral Access Layer
 * @{
 */

/** IOMUXC_GPR - Register Layout Typedef */
typedef struct {
  __IO uint32_t GPR0;                              /**< GPR0 General Purpose Register, offset: 0x0 */
} IOMUXC_GPR_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_GPR_Register_Masks IOMUXC_GPR Register Masks
 * @{
 */

/*! @name GPR0 - GPR0 General Purpose Register */
/*! @{ */

#define IOMUXC_GPR_GPR0_GPR_MASK                 (0xFFFFFFFFU)
#define IOMUXC_GPR_GPR0_GPR_SHIFT                (0U)
/*! GPR - General purpose bits */
#define IOMUXC_GPR_GPR0_GPR(x)                   (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_GPR0_GPR_SHIFT)) & IOMUXC_GPR_GPR0_GPR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC_GPR_Register_Masks */


/* IOMUXC_GPR - Peripheral instance base addresses */
/** Peripheral IOMUXC_GPR base address */
#define IOMUXC_GPR_BASE                             (0x443D0000u)
/** Peripheral IOMUXC_GPR base pointer */
#define IOMUXC_GPR                                  ((IOMUXC_GPR_Type *)IOMUXC_GPR_BASE)
/** Array initializer of IOMUXC_GPR peripheral base addresses */
#define IOMUXC_GPR_BASE_ADDRS                       { IOMUXC_GPR_BASE }
/** Array initializer of IOMUXC_GPR peripheral base pointers */
#define IOMUXC_GPR_BASE_PTRS                        { IOMUXC_GPR }

/*!
 * @}
 */ /* end of group IOMUXC_GPR_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_IOMUXC_GPR_H_) */
