/**
*   @file    eMcem_Vfccu_Types.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - VFCCU IP Types
*   @details Internal types used in the VFCCU IP layer of the eMcem module.
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
*   Copyright 2022-2024 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_VFCCU_TYPES_H
#define EMCEM_VFCCU_TYPES_H

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
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* Defines */
/*!
 * @name EMCEM config software version
 */
/** @{ */

/*!
* @brief    eMCEM VFCCU TYPES SW major version
*/
#define EMCEM_VFCCU_TYPES_SW_MAJOR_VERSION             0
/*!
* @brief    eMCEM VFCCU TYPES SW minor version
*/
#define EMCEM_VFCCU_TYPES_SW_MINOR_VERSION             4
/*!
* @brief    eMCEM VFCCU TYPES SW patch version
*/
#define EMCEM_VFCCU_TYPES_SW_PATCH_VERSION             0
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/*!< Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_VFCCU_TYPES_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_VFCCU_TYPES_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_VFCCU_TYPES_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Vfccu_Types.h and MIMX_SAF version are different"
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
/*!
* @brief      Fault Status type
* @details    VFCCU Fault status
*/
typedef enum
{
    FCCU_FAULT_NOT_AVAILABLE          = 0x00,
    FCCU_FAULT_NOT_ASSERTED           = 0x55,
    FCCU_FAULT_ASSERTED               = 0xAA
} eMcem_Fccu_FaultStatusType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
* @brief      eMCEM Fault type.
* @details    eMCEM Fault type.
*/
typedef uint16 eMcem_FaultType;

/*!
* @brief      eMCEM VFCCU Error Recovery State Enum.
* @details    Enumeration covering possible VFCCU error recovery states.
*/
typedef enum
{
    EMCEM_ERR_RECOVERED     = 0,    /**< @brief VFCCU error has been recovered. */
    EMCEM_ERR_NOT_RECOVERED = 1     /**< @brief VFCCU error has not been recovered. */
} eMcem_ErrRecoveryType;

/*!
* @brief      eMCEM FCCU EOUT Signal Enum.
* @details    Enumeration covering possible FCCU EOUT Signals to control.
*/
typedef enum
{
    EMCEM_FCCU_EOUT0 = 0,   /**< @brief FCCU EOUT0 Signal. */
    EMCEM_FCCU_EOUT1 = 1,   /**< @brief FCCU EOUT1 Signal. */
} eMcem_ErrorOutputType;

/*!
* @brief      eMCEM FCCU EOUT Pin Mode Enum.
* @details    Enumeration covering possible FCCU EOUT Pin Modes.
*/
typedef enum
{
    EMCEM_FCCU_EOUT_INPUT_ONLY          = 0,   /**< @brief FCCU EOUT Input Only Pin Mode. */
    EMCEM_FCCU_EOUT_OUTPUT_PUSH_PULL    = 1,   /**< @brief FCCU EOUT Push-Pull Pin Mode. */
    EMCEM_FCCU_EOUT_OPEN_DRAIN          = 2,   /**< @brief FCCU EOUT Open-Drain Pin Mode. */
    EMCEM_FCCU_EOUT_OPEN_COLLECTOR      = 3,   /**< @brief FCCU EOUT Open-Collector Pin Mode. */
    EMCEM_FCCU_EOUT_BI_STABLE           = 4,   /**< @brief FCCU EOUT Bi-Stable Pin Mode. */
    EMCEM_FCCU_EOUT_FAULT_TOGGLE        = 5    /**< @brief FCCU EOUT Fault-Toggle Pin Mode. */
} eMcem_EOUTPinModeType;

/*!
* @brief      eMCEM FCCU EOUT Signaling State Enum.
* @details    Enumeration covering possible signaling states of FCCU EOUT pins.
*/
typedef enum
{
    EMCEM_FCCU_EOUT_DEACTIVATE = 0,   /**< @brief FCCU EOUT signals not active. */
    EMCEM_FCCU_EOUT_ACTIVATE   = 1    /**< @brief FCCU EOUT signals active. */
} eMcem_EOUTStateType;

/*!
* @brief      eMCEM FCCU EOUT Controlling Mode Enum.
* @details    Enumeration covering possible controlling modes of FCCU EOUT pins.
*/
typedef enum
{
    EMCEM_FCCU_EOUT_FSM  = 0,   /**< @brief Signals driven by FCCU's FSM. */
    EMCEM_FCCU_EOUT_LOW  = 1,   /**< @brief Signals always low. */
    EMCEM_FCCU_EOUT_HIGH = 3    /**< @brief Signals high until a fault occurs; thereafter controlled by FSM. */
} eMcem_EOUTModeType;

/*!
* @brief      eMCEM VFCCU FSM States
* @details    Enumeration covering possible FSM states
*/
typedef enum
{
    EMCEM_VFCCU_FSM_IDLE                = 0,    /**< @brief Idle state of FSM. */
    EMCEM_VFCCU_FSM_IMMEDIATE_REACTION  = 1,    /**< @brief Alarm state - Immediate reaction of FSM. */
    EMCEM_VFCCU_FSM_DELAYED_REACTION    = 2,    /**< @brief Fault state - Delayed reaction of FSM */
} eMcem_FsmStateType;

/*!
* @brief     Prototype of VFCCU fault alarm handler function
* @details   Function takes one argument which is ID of fault that is being handled and returns eMcem_ErrRecoveryType telling the result of fault recovery.
*
*/
typedef eMcem_ErrRecoveryType (*eMcem_FccuHandlerType)( eMcem_FaultType nFaultId );

/*!
* @brief     Prototype of VFCCU Successful Recovery notification function
* @details   Function takes one argument which is ID of fault that is being handled.
*
*/
typedef void (*eMcem_SuccessRecNotificationType)( eMcem_FaultType nFaultId );

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_VFCCU_TYPES_H */

/** @} */
