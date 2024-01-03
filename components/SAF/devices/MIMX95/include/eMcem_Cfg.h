/**
*   @file    eMcem_Cfg.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - Configuration Header.
*   @details Contains declarations of the eMcem configuration.
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
*   Copyright 2023-2024 NXP
*   Detailed license terms of software usage can be found in the license.txt 
*   file located in the root folder of this package. 
==================================================================================================*/

#ifndef EMCEM_CFG_H
#define EMCEM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_Cfg_h_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers do not enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Cfg_h_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers do not enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Cfg_h_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers do not enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Cfg_h_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers do not enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Cfg_h_REF_0809
* Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block scope.
* This variable cannot be defined at block scope as it is being generated by configuration tool.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX_SAF_Version.h"
#include "eMcem_Types_Ext.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMCEM_CFG_SW_MAJOR_VERSION             0
#define EMCEM_CFG_SW_MINOR_VERSION             4
#define EMCEM_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_CFG_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_CFG_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_CFG_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Cfg.h and MIMX_SAF version are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
/**
* @brief    Availability of test API for sCheck module. sCheck module needs to be present in configuration to enable this option.
*/
#define EMCEM_TEST_API_AVAILABLE        (STD_OFF)

/**
* @brief    Enable/Disable fault statistics. Mode Selector module needs to be present in configuration to allow enabling of this option. 
*/
#define EMCEM_FAULT_STATISTICS_ENABLED  (STD_OFF)

/**
* @brief    Enable/Disable extended diagnostics.
*/
#define EMCEM_EXT_DIAG_ENABLED          (STD_OFF)

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/
typedef struct
{
    const uint8                             u8FaultHandlerId;
    const boolean                           bEnabled;
    const boolean                           bWriteAccessEnabled;
    const uint32                            u32ImmReaction[EMCEM_REACTION_SET_COUNT];
    const uint32                            u32DelReaction[EMCEM_REACTION_SET_COUNT];
    const uint32                            u32FaultEnabled[EMCEM_CVFCCU_FAULT_ENABLE_REG_COUNT];
    const uint32                            u32FaultReactionSet[EMCEM_CVFCCU_REACTION_SET_REG_COUNT];
    const eMcem_FccuHandlerType             eMcem_AlarmHandler[EMCEM_CVFCCU_MAX_FAULTS];
} eMcem_CVfccuFhidCfgType;

typedef struct
{
    const uint32                            u8EoutTimerDisabled;
    const uint32                            u32EoutPin[EMCEM_EOUT_PIN_COUNT]; /* Control mode, InvertInput, InputBufferEnabled, OutputBufferEnableValid */
    const uint32                            u8EoutOperatingMode[EMCEM_EOUT_PIN_COUNT]; /* Invert EOUT signaling, operating mode */
} eMcem_EoutCfgType;

typedef struct
{
    /* General cfg */
    const boolean                           bDebugEnabled;
    const boolean                           bConfigEnabled;
    const uint32                            u32GlobalReactionTimerPeriod;
    const uint32                            u32MinEoutDuration;
    /* EOUT cfg */
    const eMcem_EoutCfgType                 eMcem_EoutCfg;
    /* Fault lines cfg */
    const uint32                            au32Recovery[EMCEM_CVFCCU_FAULT_RECOVERY_REG_COUNT];
    /* FHID cfg */
    const eMcem_CVfccuFhidCfgType           eMcem_FhidCfg;
} eMcem_CVfccuInstanceCfgType;

/**
* @brief    Configuration struct type.
* @details  eMCEM Driver configuration structure type.
*/
typedef struct
{
    const eMcem_CVfccuInstanceCfgType       *eMcem_CVfccuCfg;
} eMcem_ConfigType;

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/
#define EMCEM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "eMcem_MemMap.h"

/**
* @brief      eMCEM configuration structures.
*/
/* @violates @ref eMcem_Cfg_h_REF_0809 */
extern const eMcem_ConfigType eMcem_Config;

#define EMCEM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "eMcem_MemMap.h"

/* @violates @ref eMcem_Cfg_h_REF_0501 */
/* @violates @ref eMcem_Cfg_h_REF_0502 */
/* @violates @ref eMcem_Cfg_h_REF_0504 */
/* @violates @ref eMcem_Cfg_h_REF_0505 */
#define EMCEM_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#include "eMcem_MemMap.h"

#define EMCEM_START_SEC_CONST_32
#include "eMcem_MemMap.h"

/**
* @brief      Array for masking out FCCU reserved faults.
*/
/* @violates @ref eMcem_Cfg_h_REF_0809 */
extern const uint32 eMcem_au32StaticFaultMasks[3U];

#define EMCEM_STOP_SEC_CONST_32
#include "eMcem_MemMap.h"

/* @violates @ref eMcem_Cfg_h_REF_0501 */
/* @violates @ref eMcem_Cfg_h_REF_0502 */
/* @violates @ref eMcem_Cfg_h_REF_0504 */
/* @violates @ref eMcem_Cfg_h_REF_0505 */
#define EMCEM_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#include "eMcem_MemMap.h"

/**
* @brief      eMCEM pointer to configuration structure.
*/
extern const eMcem_ConfigType *eMcem_pConfigPtr;

/* @violates @ref eMcem_Cfg_h_REF_0501 */
/* @violates @ref eMcem_Cfg_h_REF_0502 */
/* @violates @ref eMcem_Cfg_h_REF_0504 */
/* @violates @ref eMcem_Cfg_h_REF_0505 */
#define EMCEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define EMCEM_START_SEC_CODE
/* @violates @ref eMcem_Cfg_c_REF_0410 */
#include "eMcem_MemMap.h"

/* Default Alarm Handler function */
extern eMcem_ErrRecoveryType eMcemCVfccuAlarmHandler( eMcem_FaultType nFaultId );

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_Cfg_c_REF_0410 */
/* @violates @ref eMcem_Cfg_c_REF_2001 */
#include "eMcem_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* EMCEM_CFG_H */

/** @} */
