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
*   Build Version        : MIMX9X_SAF_0_4_0
*
*   Copyright 2012, 2013, 2015 Freescale
*   Copyright 2017-2024 NXP
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
/*!
 * @name eMCEM Lib ext software version
 */
/** @{ */
/**
* @brief    eMCEM LIB extended software major version.
*/
#define EMCEM_LIB_EXT_SW_MAJOR_VERSION             0
/**
* @brief    eMCEM LIB extended software minor version.
*/
#define EMCEM_LIB_EXT_SW_MINOR_VERSION             4
/**
* @brief    eMCEM LIB extended software patch version.
*/
#define EMCEM_LIB_EXT_SW_PATCH_VERSION             0
/** @} */

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
/*!
* @brief    Macro marking the beginnning of CODE section. This is memory section for code.
 */
#define EMCEM_START_SEC_CODE
/* @violates @ref eMcem_Lib_Ext_h_REF_0410 */
#include "eMcem_MemMap.h"

/*!
 * @name eMCEM Lib Ext module functions
 * @{
 */
/*!
* @brief      eMCEM Init functions.
* @details    Function initializing IPs using IPs config structures.
*
* @param[in]  pConfigPtr       Pointer to driver configuration structure.
*
*/
void eMcem_Init_Int( const eMcem_ConfigType *pConfigPtr );

/*!
* @brief      VFCCU init function.
* @details    Function initializing VFCCU using IPs config structures.
*
* @param[in,out] pConfigPtr   Pointer to driver configuration structure.
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      Driver has been initialized correctly and checked using readback.
* @retval           EMCEM_E_NOT_OK  Driver has not been initialized correctly, readback failed.
*
*/
Std_ReturnType eMcem_Vfccu_Init_Int( const eMcem_ConfigType *pConfigPtr );
/**
* @brief      Check if fault ID is valid
* @details    Function to check if fault ID is within range and if the fault is enabled
*
* @param[in]  nFaultId     The ID of the fault to be validated
*
* @return     boolean
*                   TRUE    Fault ID is valid (in range and enabled)
*                   FALSE   Fault ID is not valid (out of range or disabled)
*
* @pre        nFaultId is valid
*
*/
boolean eMcem_CheckValidFault_Int( eMcem_FaultType nFaultId );

/*!
* @brief      Get errors function
* @details    Function gets logged errors from the VFCCU IP and stores them in the error container
*
* @param[in,out] pErrorContainer  Error container where the errors shall be stored.
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK               No fault is pending.
* @retval           EMCEM_E_FAULT_DETECTED   There is at least one logged fault.
*
*/
Std_ReturnType eMcem_GetErrors_Int( eMcem_FaultContainerType *pErrorContainer );

/**
* @brief      Clear fault function
* @details    The function shall clear the specified fault. The fault can be cleared only if the fault
*             cause is eliminated and the fault is marked as software recoverable.
*
* @param[in]  nFaultId        The ID of the fault that shall be cleared
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      The fault has been successfully cleared
* @retval           EMCEM_E_NOT_OK  The fault has not been successfully cleared. Possible causes:
*                                   - the fault source has not been eliminated
*                                   - the fault occurred again
*
* @pre        nFaultId is valid
*
*/
Std_ReturnType eMcem_ClearFaults_Int( eMcem_FaultType nFaultId );

/**
* @brief      eMcem_AssertSWFault_Int
* @details    Asserts SW fault triggering to FCCU if the faultID is correct (in proper range)
*
* @param[in]  nFaultId   The ID of SW fault to assert
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      SW fault has been asserted successfully.
* @retval           EMCEM_E_NOT_OK  SW fault has not been asserted.
*
*/
Std_ReturnType eMcem_AssertSWFault_Int( eMcem_FaultType nFaultId );

/**
* @brief      eMcem_DeassertSWFault_Int
* @details    Deasserts SW fault triggering to FCCU if the faultID is correct (in proper range)
*
* @param[in]  nFaultId   The ID of SW fault to deassert
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      SW fault has been asserted successfully.
* @retval           EMCEM_E_NOT_OK  SW fault has not been asserted.
*
*/
Std_ReturnType eMcem_DeassertSWFault_Int( eMcem_FaultType nFaultId );


/**
* @brief    Macro marking the end of CODE section.
*/
#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_Lib_Ext_h_REF_0410 */
#include "eMcem_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_LIB_EXT_H */

/** @} */
