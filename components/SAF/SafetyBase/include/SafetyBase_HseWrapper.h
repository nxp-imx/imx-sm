/**
*   @file    SafetyBase_HseWrapper.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF SafetyBase - HSE wrapper.
*   @details This file provides wrapper functions to access HSE driver.
*
*   @addtogroup SAFETY_BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : MIMX_SAF
*   Platform             : CORTEXM
*
*   SW Version           : 0.4.0
*   Build Version        : IMX95_SAF_0_4_0_CD01_20231113
*
*   Copyright 2020, 2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef SBASE_HSE_WRAPPER_H
#define SBASE_HSE_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section safetybase_hse_wrapper_h_REF0410
 * Violates MISRA 2012 Required Rule 4.10, Inclusion of "sBase_MemMap.h" is required here because
 * of its functionality.
 */


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX_SAF_Version.h"
#include "SafetyBase_Cfg.h"
#include "Std_Types.h"
#if (STD_ON == SAFETY_BASE_HSE_WRAPPER_SUPPORT)
#include "hse_interface.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SBASE_HSE_SW_MAJOR_VERSION             0
#define SBASE_HSE_SW_MINOR_VERSION             4
#define SBASE_HSE_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((SBASE_HSE_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (SBASE_HSE_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (SBASE_HSE_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
#error "Software Version Numbers of SafetyBase_HseWrapper.h and MIMX_SAF version are different"
#endif

#if (STD_ON == SAFETY_BASE_HSE_WRAPPER_SUPPORT)
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SBASE_START_SEC_CODE
/* @violates @ref safetybase_hse_wrapper_h_REF0410 */
#include "sBase_MemMap.h"

/**
 * @brief Send synchronous request to the HSE over the specified MU
 *
 * @param[out]  u8MuId      Messaging Unit ID
 * @param[out]  pHseMsg     Pointer to the HSE service request structure to be forwarded to the HSE
 *
 * @return HSE service response status
 */
hseSrvResponse_t sBase_HseSrv_Request(uint8 u8MuId, hseSrvDescriptor_t * pHseMsg);

#define SBASE_STOP_SEC_CODE
/* @violates @ref safetybase_hse_wrapper_h_REF0410 */
#include "sBase_MemMap.h"

#endif /* (STD_ON == SAFETY_BASE_HSE_WRAPPER_SUPPORT) */

#ifdef __cplusplus
}
#endif

#endif /*SBASE_HSE_WRAPPER_H*/

/** @} */
