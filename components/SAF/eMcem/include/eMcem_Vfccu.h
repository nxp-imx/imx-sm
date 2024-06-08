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
*   Build Version        : MIMX9X_SAF_0_4_0
*
*   Copyright 2022-2024 NXP
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
/*!
 * @name eMCEM VFCCU internal function definitions SW version
 */
/** @{ */

/*!
* @brief    eMCEM VFCCU internal function definitions - SW major version
*/
#define EMCEM_VFCCU_SW_MAJOR_VERSION             0
/*!
* @brief    eMCEM VFCCU internal function definitions - SW minor version
*/
#define EMCEM_VFCCU_SW_MINOR_VERSION             4
/*!
* @brief    eMCEM VFCCU internal function definitions - SW patch version
*/
#define EMCEM_VFCCU_SW_PATCH_VERSION             0
/** @} */

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


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/*!
* @brief    Macro marking the beginnning of CODE section. The memory section for code.
*/
#define EMCEM_START_SEC_CODE
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"

/*!
* @brief      VFCCU Init function
* @details    Initialization function for the VFCCU IP
*
* @param[in]  pConfigPtr  Configuration pointer used for initialization
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      Initialization was executed correctly
* @retval           EMCEM_E_NOT_OK  Initialization was not executed correctly
*
*/
Std_ReturnType eMcem_Vfccu_Init( const eMcem_ConfigType *pConfigPtr );

/*!
* @brief      Get errors function
* @details    Function gets logged errors from the VFCCU IP and stores them in the error container
*
* @param[out] pFaultContainer    Error container where the errors will be stored
* @param[out] pFaultAccumulator  Accumulator where all fault bits are aggregated
*
*/
void eMcem_Vfccu_GetErrors( uint32 pFaultContainer[], uint32 *pFaultAccumulator );

/*!
* @brief      Clear fault function
* @details    Function shall clear error flag for a specified fault.
*
* @param[in]  nFaultId              The ID of the fault that shall be cleared
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      Fault was cleared successfully
* @retval           EMCEM_E_NOT_OK  Fault was not cleared
*
* @implements DD_eMcem_ClearFaults_seq
*
*/
Std_ReturnType eMcem_Vfccu_ClearFaults( eMcem_FaultType nFaultId );

/*!
* @brief      Checks Access to CVFCCU
* @details    Returns if this EENV has full access to CVFCCU global registers
*
* @return     boolean
* @retval           EMCEM_E_TRUE    EENV has access to CVFCCU
* @retval           EMCEM_E_FALSE   EENV doesn't have access to CVFCCU
*
*/
boolean eMcem_Vfccu_AccessToCVfccu( void );

/*!
* @brief      Assert software VFCCU fault.
* @details    Sets reaction line for software fault.
*
* @param[in]  u8SwFaultId      ID of the SW fault that shall be asserted.
*
*/
void eMcem_Vfccu_AssertSWFault( uint8 u8SwFaultId );

/*!
* @brief      Deassert software VFCCU fault.
* @details    Clears the software fault on the corresponding reaction line.
*
* @param[in]  u8SwFaultId      ID of the SW fault that shall be deasserted.
*
*/
void eMcem_Vfccu_DeassertSWFault( uint8 u8SwFaultId );

/*!
* @brief      VFCCU Alarm Interrupt routine.
* @details    An ALARM Interrupt is generated when a properly configured fault generates a transition
*             to the ALARM state. The status (fault triggering interrupt) can be obtained
*             through frozen status registers.
*
* @implements DD_eMcem_VFCCU_ALARM_ISR
*
* @violates @ref eMcem_cVfccu_Irq_c_REF_0807
*
*/
void VFCCU_ALARM_ISR( void );

/*!
* @brief    Macro marking the end of CODE section.
*/
#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_Vfccu_h_REF_0410 */
#include "eMcem_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_VFCCU_H */

/** @} */
