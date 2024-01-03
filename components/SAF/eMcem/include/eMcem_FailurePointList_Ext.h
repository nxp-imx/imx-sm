/**
*   @file    eMcem_FailurePointList_Ext.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - Extended diagnostics types.
*   @details Contains declarations of types for eMcem extended diagnostics.
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
*   Copyright 2019-2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_FAILUREPOINTLIST_EXT_H
#define EMCEM_FAILUREPOINTLIST_EXT_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_FailurePointList_Ext_h_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_FailurePointList_Ext_h_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_FailurePointList_Ext_h_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_FailurePointList_Ext_h_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX_SAF_Version.h"
#include "eMcem_FailurePointList_MIMX95XX.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_FailurePointList_Ext_h_REF_0501 */
/* @violates @ref eMcem_FailurePointList_Ext_h_REF_0502 */
/* @violates @ref eMcem_FailurePointList_Ext_h_REF_0504 */
/* @violates @ref eMcem_FailurePointList_Ext_h_REF_0505 */
#define EMCEM_FAILUREPOINTLIST_EXT_SW_MAJOR_VERSION             0
/* @violates @ref eMcem_FailurePointList_Ext_h_REF_0501 */
/* @violates @ref eMcem_FailurePointList_Ext_h_REF_0502 */
/* @violates @ref eMcem_FailurePointList_Ext_h_REF_0504 */
/* @violates @ref eMcem_FailurePointList_Ext_h_REF_0505 */
#define EMCEM_FAILUREPOINTLIST_EXT_SW_MINOR_VERSION             4
#define EMCEM_FAILUREPOINTLIST_EXT_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_FAILUREPOINTLIST_EXT_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_FAILUREPOINTLIST_EXT_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_FAILUREPOINTLIST_EXT_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_FailurePointList_Ext.h and MIMX_SAF version are different"
#endif

#if( STD_ON == EMCEM_EXT_DIAG_ENABLED )
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Extended diagnostic data (logged call tree) length */
#define EMCEM_EXT_DIAG_DATA_MAX_LENGTH    4U

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Extended diagnostics struct type.
* @details        Container for storing diagnostic data of last called API function.
*/
typedef struct
{
    eMcem_FailurePointType aFpId[EMCEM_EXT_DIAG_DATA_MAX_LENGTH]; /* Failure point ID */
    uint8 au8FailingLoopId[EMCEM_EXT_DIAG_DATA_MAX_LENGTH];   /* ID of failing iteration */
    uint32 u32RegisterValue;        /* Register value clarifying the failure point */
    uint8 u8ItemsCount;             /* Logged failure points count (length of the call tree) */
} eMcem_ExtDiagDataType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* ( STD_ON == EMCEM_EXT_DIAG_ENABLED ) */

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_FAILUREPOINTLIST_EXT_H */

/** @} */
