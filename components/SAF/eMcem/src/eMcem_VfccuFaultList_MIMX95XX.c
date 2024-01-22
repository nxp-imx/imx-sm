/**
*   @file    eMcem_VfccuFaultList_MIMX95XX.c
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - Specific ERM channels source.
*   @details Contains specific ERM error channels data for eMcem module.
*
*   @addtogroup EMCEM_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : MIMX_SAF
*   Platform             : CORTEXM
*
*   SW Version           : 0.4.0
*   Build Version        : IMX95_SAF_0_4_0_CD01_20231113
*
*   Copyright 2021-2024 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_VfccuFaultList_MIMX95XX_c_REF_0410
* Violates MISRA 2012 Required Rule 4.10, This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_VfccuFaultList_MIMX95XX_c_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_VfccuFaultList_MIMX95XX_c_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_VfccuFaultList_MIMX95XX_c_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_VfccuFaultList_MIMX95XX_c_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_VfccuFaultList_MIMX95XX_c_REF_2001
* Violates MISRA 2012 Advisory Rule 20.1, #include statements are not preceded only by
* preprocessor directives and comments because it otherwise would not work.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX_SAF_Version.h"
#include "eMcem_VfccuFaultList_MIMX95XX.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0501 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0502 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0504 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0505 */
#define EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_MAJOR_VERSION_C               0
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0501 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0502 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0504 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0505 */
#define EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_MINOR_VERSION_C               4
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0501 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0502 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0504 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0505 */
#define EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_MAJOR_VERSION_C != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_MINOR_VERSION_C != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_PATCH_VERSION_C != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_VfccuFaultList_MIMX95XX.c and MIMX_SAF version are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#if SAFETY_BASE_MIMX95XX

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define EMCEM_START_SEC_CONST_32
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0410 */
#include "eMcem_MemMap.h"

#define EMCEM_STOP_SEC_CONST_32
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_0410 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_c_REF_2001 */
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#endif /* SAFETY_BASE_MIMX95XX */

#ifdef __cplusplus
}
#endif

/** @} */
