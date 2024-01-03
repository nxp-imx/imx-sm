/**
*   @file    eMcem_Vfccu.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - VFCCU IP header.
*   @details Contains declarations of VFCCU IP functions for eMcem module.
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
*   Copyright 2022-2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_VFCCU_H
#define EMCEM_VFCCU_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_Vfccu_h_REF_0410
* Violates MISRA 2012 Required Rule 4.10, This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_Vfccu_h_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Vfccu_h_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Vfccu_h_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Vfccu_h_REF_0505
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
#include "eMcem_Vfccu_Types.h"
#include "eMcem_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMCEM_VFCCU_SW_MAJOR_VERSION             0
#define EMCEM_VFCCU_SW_MINOR_VERSION             4
#define EMCEM_VFCCU_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_VFCCU_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_VFCCU_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_VFCCU_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Vfccu.h and MIMX_SAF version are different"
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
#define EMCEM_START_SEC_CONST_UNSPECIFIED
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"

#define EMCEM_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"

#define EMCEM_START_SEC_CONST_8
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"

#define EMCEM_STOP_SEC_CONST_8
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"

#define EMCEM_START_SEC_CONST_16
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"

#define EMCEM_STOP_SEC_CONST_16
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"

#define EMCEM_START_SEC_CONST_32
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"

#define EMCEM_STOP_SEC_CONST_32
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define EMCEM_START_SEC_CODE
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"

Std_ReturnType eMcem_Vfccu_Init( const eMcem_ConfigType *pConfigPtr );

void eMcem_Vfccu_GetSWFaults( uint32 pFaultContainer[], uint32 *pFaultAccumulator, eMcem_FaultType nFaultId );

void eMcem_Vfccu_GetErrors( uint32 pFaultContainer[], uint32 *pFaultAccumulator );

Std_ReturnType eMcem_Vfccu_ClearFaults( eMcem_FaultType nFaultId );

boolean eMcem_Vfccu_AccessToCVfccu( void );

void eMcem_Vfccu_AssertSWFault( uint8 u8SwFaultId );

void eMcem_Vfccu_DeassertSWFault( uint8 u8SwFaultId );

Std_ReturnType eMcem_Vfccu_ProcessFaults( uint8 u8VfccuIdx );

void VFCCU_ALARM_ISR( void );

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_VFCCU_H */

/** @} */
