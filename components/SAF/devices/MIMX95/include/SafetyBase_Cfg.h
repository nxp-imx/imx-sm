/**
*   @file    SafetyBase_Cfg.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF SafetyBase - Module configuration interface for MIMX_SAF.
*   @details Contains the module configuration interface for MIMX_SAF.
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
*   Copyright 2017-2023 NXP
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
#include "MIMX_SAF_Version.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAFETY_BASE_CFG_SW_MAJOR_VERSION          0
#define SAFETY_BASE_CFG_SW_MINOR_VERSION          4
#define SAFETY_BASE_CFG_SW_PATCH_VERSION          0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((SAFETY_BASE_CFG_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (SAFETY_BASE_CFG_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (SAFETY_BASE_CFG_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
#error "Software Version Numbers of SafetyBase_Cfg.h and MIMX_SAF version are different"
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
#define SAFETY_BASE_MIMX9596                1

/**
 * @brief Specifies PMIC type used together with the device.
 */
#define SAFETY_BASE_PMIC_PF09		         1

#ifndef SAFETY_BASE_PMIC_VR55XX
#define SAFETY_BASE_PMIC_VR55XX             0
#endif

#ifndef SAFETY_BASE_PMIC_FS8X
#define SAFETY_BASE_PMIC_FS8X               0
#endif

#ifndef SAFETY_BASE_PMIC_FS86
#define SAFETY_BASE_PMIC_FS86               0
#endif

#ifndef SAFETY_BASE_PMIC_FS26XX
#define SAFETY_BASE_PMIC_FS26XX             0
#endif

#ifndef SAFETY_BASE_PMIC_PF09
#define SAFETY_BASE_PMIC_PF09               0
#endif

#ifndef SAFETY_BASE_MIMX9596
#define SAFETY_BASE_MIMX9596                0
#endif

#define SAFETY_BASE_MIMX95XX                (SAFETY_BASE_MIMX9596 != 0)


/**
* @brief Define to specify the ARM architecture
*/
#define SAFETY_BASE_PLATFORM_ARM            (SAFETY_BASE_ARMV8_MARCH) 

/**
* @brief           Processor type
*/
#define SAFETY_BASE_CPU_TYPE                (CPU_TYPE_32)      

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


