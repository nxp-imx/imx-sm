/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 1.0, 206
**     Build:               b241030
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OSC24M
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file OSC24M.h
 * @version 1.0
 * @date 2026-01-10
 * @brief CMSIS Peripheral Access Layer for OSC24M
 *
 * CMSIS Peripheral Access Layer for OSC24M
 */

#if !defined(OSC24M_H_)
#define OSC24M_H_                                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

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


/*!
 * @}
 */ /* end of group OSC24M_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* OSC24M_H_ */

