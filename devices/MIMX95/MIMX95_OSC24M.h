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
 * @file MIMX95_OSC24M.h
 * @version
 * @date
 * @brief CMSIS Peripheral Access Layer for MIMX95_OSC24M
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_OSC24M_H_)  /* Check if memory map has not been already included */
#define MIMX95_OSC24M_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- OSC24M Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC24M_Peripheral_Access_Layer OSC24M Peripheral Access Layer
 * @{
 */

/** OSC24M - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2048];
  __I  uint32_t DIGPROG_DEVICE_ID;                 /**< Device ID, offset: 0x800 */
} OSC24M_Type;

/* ----------------------------------------------------------------------------
   -- OSC24M Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC24M_Register_Masks OSC24M Register Masks
 * @{
 */

/*! @name DIGPROG_DEVICE_ID - Device ID */
/*! @{ */

#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR_MASK (0xFFU)
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR_SHIFT (0U)
/*! DIGPROG_MINOR - Bit[3:0] is the metal layer revision. Bit[7:4] is the base layer revision. */
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR(x) (((uint32_t)(((uint32_t)(x)) << OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR_SHIFT)) & OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR_MASK)

#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_MASK (0xFF00U)
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_SHIFT (8U)
/*! DIGPROG_MAJOR_LOWER - DIGPROG_MAJOR_LOWER */
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER(x) (((uint32_t)(((uint32_t)(x)) << OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_SHIFT)) & OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_MASK)

#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_MASK (0xFF0000U)
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_SHIFT (16U)
/*! DIGPROG_MAJOR_UPPER - DIGPROG_MAJOR_UPPER */
#define OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER(x) (((uint32_t)(((uint32_t)(x)) << OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_SHIFT)) & OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OSC24M_Register_Masks */


/* OSC24M - Peripheral instance base addresses */
/** Peripheral OSC24M base address */
#define OSC24M_BASE                         (0x44480000u)
/** Peripheral OSC24M base pointer */
#define OSC24M                              ((OSC24M_Type *)OSC24M_BASE)
/** Array initializer of OSC24M peripheral base addresses */
#define OSC24M_BASE_ADDRS                   { OSC24M_BASE }
/** Array initializer of OSC24M peripheral base pointers */
#define OSC24M_BASE_PTRS                    { OSC24M }

/*!
 * @}
 */ /* end of group OSC24M_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_OSC24M_H_) */

