/**
*   @file    SafetyBase_Cfg.h
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF SafetyBase - Module configuration interface for MIMX9XX_SAF.
*   @details Contains the module configuration interface for MIMX9XX_SAF.
*
*   @addtogroup SAFETY_BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : MIMX9XX_SAF
*   Platform             : CORTEXM
*
*   SW Version           : 0.8.4
*   Build Version        : MIMX9_SAF_0_8_4_20250110
*
*   Copyright 2025 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef SAFETY_BASE_CFG_H
#define SAFETY_BASE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2012 violations
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX9XX_SAF_Version.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAFETY_BASE_CFG_SW_MAJOR_VERSION          0
#define SAFETY_BASE_CFG_SW_MINOR_VERSION          8
#define SAFETY_BASE_CFG_SW_PATCH_VERSION          4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same software version */
#if ((SAFETY_BASE_CFG_SW_MAJOR_VERSION != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (SAFETY_BASE_CFG_SW_MINOR_VERSION != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (SAFETY_BASE_CFG_SW_PATCH_VERSION != MIMX9XX_SAF_SW_PATCH_VERSION))
#error "Software Version Numbers of SafetyBase_Cfg.h and MIMX9XX_SAF version are different"
#endif

/*==================================================================================================
*                                         CONSTANTS
==================================================================================================*/
#define SAFETY_BASE_ARMV7_MARCH      (8)   /* for ARM M7 Thumb2      */
#define SAFETY_BASE_ARMV8_MARCH      (16)  /* for ARM M33 Thumb2      */
#define SAFETY_BASE_ARMV8_AARCH32    (32)  /* for ARM ARCH32         */
#define SAFETY_BASE_ARMV8_AARCH64    (64)  /* for ARM ARCH64         */
#define SAFETY_BASE_ARMV8_RARCH      (52)  /* for ARM R platform     */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief           Specifies the target platform.
*/
#define SAFETY_BASE_MIMX9486                1

/**
 * @brief Specifies PMIC type used together with the device.
 */
#define SAFETY_BASE_PMIC_PF09               1

#ifndef SAFETY_BASE_PMIC_PF09
#define SAFETY_BASE_PMIC_PF09               0
#endif

#ifndef SAFETY_BASE_MIMX9596
#define SAFETY_BASE_MIMX9596                0
#endif

#ifndef SAFETY_BASE_MIMX9486
#define SAFETY_BASE_MIMX9486                0
#endif

#ifndef SAFETY_BASE_MIMX9529
#define SAFETY_BASE_MIMX9529                0
#endif

#define SAFETY_BASE_MIMX95XX               (SAFETY_BASE_MIMX9596 != 0)

#define SAFETY_BASE_MIMX943X               (SAFETY_BASE_MIMX9486 != 0)

#define SAFETY_BASE_MIMX952X               (SAFETY_BASE_MIMX9529 != 0)

#define SAFETY_BASE_MIMX9                 ((SAFETY_BASE_MIMX9596 != 0) || \
                                           (SAFETY_BASE_MIMX9486 != 0) || \
                                           (SAFETY_BASE_MIMX9529 != 0))

/**
* @brief Define to specify the ARM architecture
*/
#define SAFETY_BASE_PLATFORM_ARM           (SAFETY_BASE_ARMV8_MARCH)

/**
* @brief           Processor type
*/
#define SAFETY_BASE_CPU_TYPE               (CPU_TYPE_32)

/**
* @brief           Index of currently used CPU core representing the respective EENV.
*/
#define SAFETY_BASE_CORE_ID                 (0UL)

/**
 * @brief          Specifies availability of the HSE wrapper interface
 */
#define SAFETY_BASE_HSE_WRAPPER_SUPPORT     (STD_OFF)

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

#ifdef __cplusplus
}
#endif

#endif /* SAFETY_BASE_CFG_H */

/** @} */


