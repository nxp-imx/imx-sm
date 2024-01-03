/**
*   @file    eMcem_ExtDiagApi.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - Extended diagnostics API header.
*   @details Contains declarations of functions for eMcem extended diagnostics.
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
*   Copyright 2019-2020, 2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_EXTDIAGAPI_H
#define EMCEM_EXTDIAGAPI_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_ExtDiagApi_h_REF_0410
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_ExtDiagApi_h_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ExtDiagApi_h_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ExtDiagApi_h_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ExtDiagApi_h_REF_0505
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
#include "eMcem_FailurePointList_Ext.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_ExtDiagApi_h_REF_0501 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0502 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0504 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0505 */
#define EMCEM_EXTDIAGAPI_SW_MAJOR_VERSION             0
/* @violates @ref eMcem_ExtDiagApi_h_REF_0501 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0502 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0504 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0505 */
#define EMCEM_EXTDIAGAPI_SW_MINOR_VERSION             4
/* @violates @ref eMcem_ExtDiagApi_h_REF_0501 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0502 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0504 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0505 */
#define EMCEM_EXTDIAGAPI_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_EXTDIAGAPI_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_EXTDIAGAPI_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_EXTDIAGAPI_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_ExtDiagApi.h and MIMX_SAF version are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#if( STD_ON == EMCEM_EXT_DIAG_ENABLED )
/* Log extended diagnostic data */
#define EMCEM_DIAG_STORE_FAILURE_POINT( retVal, fpId, loopId ) \
    eMcem_StoreFailurePoint( retVal, fpId, loopId );
#define EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( retVal, regVal ) \
    eMcem_StoreFailurePointRegisterData( retVal, regVal );
#define EMCEM_DIAG_CLEAR_DATA() \
    eMcem_ClearExtDiagData();
#else
#define EMCEM_DIAG_STORE_FAILURE_POINT( retVal, fpId, loopId )
#define EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( retVal, regVal )
#define EMCEM_DIAG_CLEAR_DATA()
#endif

#if( STD_ON == EMCEM_EXT_DIAG_ENABLED )
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* @violates @ref eMcem_ExtDiagApi_h_REF_0501 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0502 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0504 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0505 */
#define EMCEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref eMcem_ExtDiagApi_h_REF_0410 */
#include "eMcem_MemMap.h"

extern eMcem_ExtDiagDataType eMcem_ExtDiagData;

/* @violates @ref eMcem_ExtDiagApi_h_REF_0501 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0502 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0504 */
/* @violates @ref eMcem_ExtDiagApi_h_REF_0505 */
#define EMCEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref eMcem_ExtDiagApi_h_REF_0410 */
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define EMCEM_START_SEC_CODE
/* @violates @ref eMcem_ExtDiagApi_h_REF_0410 */
#include "eMcem_MemMap.h"

void eMcem_StoreFailurePoint( Std_ReturnType retVal, eMcem_FailurePointType fpId, uint8 loopId );

void eMcem_StoreFailurePointRegisterData( Std_ReturnType retVal, uint32 regVal );

void eMcem_ClearExtDiagData( void );

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_ExtDiagApi_h_REF_0410 */
#include "eMcem_MemMap.h"

#endif /* ( STD_ON == EMCEM_EXT_DIAG_ENABLED ) */

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_EXTDIAGAPI_H */

/** @} */
