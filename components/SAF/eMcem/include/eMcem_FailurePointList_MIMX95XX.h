/**
*   @file    eMcem_FailurePointList_MIMX95XX.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - Extended diagnostics specific failure point list header.
*   @details Contains list of specific failure points within eMcem module.
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
*   Copyright 2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_FAILUREPOINTLIST_MIMX95XX_H
#define EMCEM_FAILUREPOINTLIST_MIMX95XX_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_FailurePointList_MIMX95XX_h_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_FailurePointList_MIMX95XX_h_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_FailurePointList_MIMX95XX_h_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_FailurePointList_MIMX95XX_h_REF_0505
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
#include "Std_Types.h"
#include "eMcem_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0501 */
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0502 */
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0504 */
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0505 */
#define EMCEM_FAILUREPOINTLIST_MIMX95XX_SW_MAJOR_VERSION             0
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0501 */
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0502 */
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0504 */
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0505 */
#define EMCEM_FAILUREPOINTLIST_MIMX95XX_SW_MINOR_VERSION             4
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0501 */
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0502 */
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0504 */
/* @violates @ref eMcem_FailurePointList_MIMX95XX_h_REF_0505 */
#define EMCEM_FAILUREPOINTLIST_MIMX95XX_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_FAILUREPOINTLIST_MIMX95XX_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_FAILUREPOINTLIST_MIMX95XX_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_FAILUREPOINTLIST_MIMX95XX_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_FailurePointList_MIMX95XX.h and MIMX_SAF version are different"
#endif

#if defined(SAFETY_BASE_MIMX95XX)
#if( STD_ON == EMCEM_EXT_DIAG_ENABLED )
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          eMCEM Driver Extended Diagnostics Failure Point Enum.
* @details        List of failure points within driver where the execution can fail.
*/
typedef enum
{
    EMCEM_FP_EMPTY = 0U,
    EMCEM_FP_INIT,
    EMCEM_FP_INJECT_FAULT,
    EMCEM_FP_GET_ERRORS,
    EMCEM_FP_CLEAR_FAULTS,
    EMCEM_FP_ASSERT_SW_FAULT,
    EMCEM_FP_DEASSERT_SW_FAULT,
    EMCEM_FP_SET_EOUT_SIGNALING,
    EMCEM_FP_SET_EOUT_CONTROL_MODE,
    EMCEM_FP_SETUP_INJECTION_CHANNEL,
    EMCEM_FP_VALIDATE_INIT_PTR,
    EMCEM_FP_VALIDATE_ERROR_PTR,
    EMCEM_FP_VALIDATE_FAULT_ID_1,
    EMCEM_FP_VALIDATE_FAULT_ID_2,
    EMCEM_FP_CHECK_STATE,
    EMCEM_FP_INIT_INT,
    EMCEM_FP_INJECT_FAULT_INT,
    EMCEM_FP_CHECK_FAULT_ID_INT,
    EMCEM_FP_EIM_SETUP_INJECTION_CHANNEL,
    EMCEM_FP_VFCCU_INIT_CVFCCU,
    EMCEM_FP_VFCCU_ACCESS_TO_CVFCCU_FHID_1,
    EMCEM_FP_VFCCU_ACCESS_TO_CVFCCU_FHID_2,
    EMCEM_FP_VFCCU_ACCESS_TO_CVFCCU_1,
    EMCEM_FP_VFCCU_ACCESS_TO_CVFCCU_2,
    EMCEM_FP_VFCCU_CLEAR_CVFCCU_FAULTS,
    EMCEM_FP_VFCCU_INIT_1,
    EMCEM_FP_VFCCU_INIT_2,
    EMCEM_FP_VFCCU_INIT_3,
    EMCEM_FP_VFCCU_CLEAR_FAULTS_1,
    EMCEM_FP_VFCCU_CLEAR_FAULTS_2,
    EMCEM_FP_VFCCU_CLEAR_FAULTS_3,
    EMCEM_FP_VFCCU_WRITE_ERROR_OUTPUT,
    EMCEM_FP_VFCCU_SET_EOUT_SIGNALING,
    EMCEM_FP_VFCCU_SET_EOUT_CONTROL_MODE,
    EMCEM_FP_VFCCU_SET_EOUT_PIN_CONTROL_MODE,
    EMCEM_FP_VFCCU_SET_FAULT_ENABLE_FHID_1,
    EMCEM_FP_VFCCU_SET_FAULT_ENABLE_FHID_2,
    EMCEM_FP_VFCCU_SET_FAULT_ENABLE_1,
    EMCEM_FP_VFCCU_SET_FAULT_ENABLE_2,
    EMCEM_FP_VFCCU_GET_FAULT_ENABLE_1,
    EMCEM_FP_VFCCU_GET_FAULT_ENABLE_2,
    EMCEM_FP_VFCCU_ACCESS_TO_VFCCU,
    EMCEM_FP_VFCCU_CALL_ALARM_HANDLER,
    EMCEM_FP_VFCCU_IS_FHID_ENABLED,
    EMCEM_FP_VFCCU_ALARM_ISR_1,
    EMCEM_FP_VFCCU_ALARM_ISR_2,
    EMCEM_FP_IPC_PROCESS_MESSAGE,
    EMCEM_FP_IPC_TRANSMIT_ACK,
    EMCEM_FP_IPC_VALIDATE_MESSAGE_STRUCT_1,
    EMCEM_FP_IPC_VALIDATE_MESSAGE_STRUCT_2,
    EMCEM_FP_IPC_INITIATE_TRANSMIT,
    EMCEM_FP_IPC_IS_IDLE,
    EMCEM_FP_IPC_IS_SLAVE,
    EMCEM_FP_IPC_VALIDATE_RX_MESSAGE,
    EMCEM_FP_IPC_TRANSMIT_MESSAGE,
    EMCEM_FP_IPC_RX_CALLBACK_1,
    EMCEM_FP_IPC_RX_CALLBACK_2,
    EMCEM_FP_IPC_INIT
} eMcem_FailurePointType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* ( STD_ON == EMCEM_EXT_DIAG_ENABLED ) */
#endif /* defined(SAFETY_BASE_MIMX95XX) */

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_FAILUREPOINTLIST_MIMX95XX_H */

/** @} */
