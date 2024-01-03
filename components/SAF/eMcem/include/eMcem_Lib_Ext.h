/**
*   @file    eMcem_Lib_Ext.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - IP wrapper header.
*   @details Contains declarations of the eMcem IP wrapper functions.
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
*   Copyright 2012, 2013, 2015 Freescale
*   Copyright 2017-2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_LIB_EXT_H
#define EMCEM_LIB_EXT_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_Lib_Ext_h_REF_0410
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_Lib_Ext_h_REF_1403
* Violates MISRA 2012 Required Rule 14.3, Controlling expression shall not be invariant.
* Condition in this macro is just to secure that no other value than the test mode will
* be entered (e.g. other type-casted value).
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX_SAF_Version.h"
#include "eMcem_Lib_MIMX95XX.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMCEM_LIB_EXT_SW_MAJOR_VERSION             0
#define EMCEM_LIB_EXT_SW_MINOR_VERSION             4
#define EMCEM_LIB_EXT_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_LIB_EXT_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_LIB_EXT_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_LIB_EXT_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Lib_Ext.h and MIMX_SAF version are different"
#endif

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
#define EMCEM_START_SEC_CODE
/* @violates @ref eMcem_Lib_Ext_h_REF_0410 */
#include "eMcem_MemMap.h"

void eMcem_Init_Int( const eMcem_ConfigType *pConfigPtr );

Std_ReturnType eMcem_Vfccu_Init_Int( const eMcem_ConfigType *pConfigPtr );

boolean eMcem_CheckValidFault_Int( eMcem_FaultType nFaultId );

Std_ReturnType eMcem_GetErrors_Int( eMcem_FaultContainerType *pErrorContainer );

Std_ReturnType eMcem_ClearFaults_Int( eMcem_FaultType nFaultId );

Std_ReturnType eMcem_AssertSWFault_Int( eMcem_FaultType nFaultId );

Std_ReturnType eMcem_DeassertSWFault_Int( eMcem_FaultType nFaultId );

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_Lib_Ext_h_REF_0410 */
#include "eMcem_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_LIB_EXT_H */

/** @} */
