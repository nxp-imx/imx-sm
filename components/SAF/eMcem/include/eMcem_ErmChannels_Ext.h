/**
*   @file    eMcem_ErmChannels_Ext.h
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - ERM channels header.
*   @details Contains declarations of ERM channels arrays for eMcem module.
*
*   @addtogroup EMCEM_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : MIMX9XX_SAF
*   Platform             : CORTEXM
*
*   SW Version           : 0.8.4
*   Build Version        : MIMX9_SAF_0_8_4_20250110
*
*   Copyright 2018-2025 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_ERMCHANNELS_EXT_H
#define EMCEM_ERMCHANNELS_EXT_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_ErmChannels_Ext_h_REF_0410
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_ErmChannels_Ext_h_REF_0809
* Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block scope.
* Variable definition is device specific and is being used in a generic file. Thus cannot be defined at block scope.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX9XX_SAF_Version.h"
#include "Std_Types.h"
#include "SafetyBase_Cfg.h"
#if SAFETY_BASE_MIMX95XX
#include "eMcem_ErmChannels_MIMX95XX.h"
#include "eMcem_VfccuFaultList_MIMX95XX.h"
#elif SAFETY_BASE_MIMX943X
#include "eMcem_ErmChannels_MIMX943X.h"
#include "eMcem_VfccuFaultList_MIMX943X.h"
#elif SAFETY_BASE_MIMX952X
#include "eMcem_ErmChannels_MIMX952X.h"
#include "eMcem_VfccuFaultList_MIMX952X.h"
#endif /* SAFETY_BASE_MIMX9XXX */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMCEM_ERMCHANNELS_EXT_SW_MAJOR_VERSION             0
#define EMCEM_ERMCHANNELS_EXT_SW_MINOR_VERSION             8
#define EMCEM_ERMCHANNELS_EXT_SW_PATCH_VERSION             4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same software version */
#if ((EMCEM_ERMCHANNELS_EXT_SW_MAJOR_VERSION != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_ERMCHANNELS_EXT_SW_MINOR_VERSION != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_ERMCHANNELS_EXT_SW_PATCH_VERSION != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_ErmChannels_Ext.h and MIMX9XX_SAF version are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
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
#define EMCEM_START_SEC_CONST_8
/* @violates @ref eMcem_ErmChannels_Ext_h_REF_0410 */
#include "eMcem_MemMap.h"

extern const uint8 au8ChannelsPerInstance[EMCEM_ERM_INSTANCE_COUNT];

#define EMCEM_STOP_SEC_CONST_8
/* @violates @ref eMcem_ErmChannels_Ext_h_REF_0410 */
#include "eMcem_MemMap.h"

#define EMCEM_START_SEC_CONST_32
/* @violates @ref eMcem_ErmChannels_Ext_h_REF_0410 */
#include "eMcem_MemMap.h"

/* Array of ERM instance base addresses */
extern const uint32 au32InstanceBaseAddr[EMCEM_ERM_INSTANCE_COUNT];

/* Arrays of provided info per channel */
/* @violates @ref eMcem_ErmChannels_Ext_h_REF_0809 */
extern const uint32 au32SCStatusProvidedMask[EMCEM_ERM_MASK_SIZE];
/* @violates @ref eMcem_ErmChannels_Ext_h_REF_0809 */
extern const uint32 au32NCStatusProvidedMask[EMCEM_ERM_MASK_SIZE];
/* @violates @ref eMcem_ErmChannels_Ext_h_REF_0809 */
extern const uint32 au32AddrProvidedMask[EMCEM_ERM_MASK_SIZE];
/* @violates @ref eMcem_ErmChannels_Ext_h_REF_0809 */
extern const uint32 au32SynProvidedMask[EMCEM_ERM_MASK_SIZE];

#define EMCEM_STOP_SEC_CONST_32
/* @violates @ref eMcem_ErmChannels_Ext_h_REF_0410 */
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_ERMCHANNELS_EXT_H */

/** @} */
