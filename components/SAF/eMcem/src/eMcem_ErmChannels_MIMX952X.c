/**
*   @file    eMcem_ErmChannels_MIMX952X.c
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - Specific ERM channels source.
*   @details Contains specific ERM error channels data for eMcem module.
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
*   Copyright 2026 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_ErmChannels_MIMX952X_c_REF_0410
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_ErmChannels_MIMX952X_c_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ErmChannels_MIMX952X_c_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ErmChannels_MIMX952X_c_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ErmChannels_MIMX952X_c_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ErmChannels_MIMX952X_c_REF_2001
* Violates MISRA 2012 Advisory Rule 20.1, #include statements are not preceded only by
* preprocessor directives and comments because it otherwise would not work.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX9XX_SAF_Version.h"
#include "eMcem_ErmChannels_Ext.h"
#include "SafetyBase.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0501 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0502 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0504 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0505 */
#define EMCEM_ERMCHANNELS_MIMX952X_SW_MAJOR_VERSION_C               0
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0501 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0502 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0504 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0505 */
#define EMCEM_ERMCHANNELS_MIMX952X_SW_MINOR_VERSION_C               8
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0501 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0502 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0504 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0505 */
#define EMCEM_ERMCHANNELS_MIMX952X_SW_PATCH_VERSION_C               4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same software version */
#if ((EMCEM_ERMCHANNELS_MIMX952X_SW_MAJOR_VERSION_C != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_ERMCHANNELS_MIMX952X_SW_MINOR_VERSION_C != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_ERMCHANNELS_MIMX952X_SW_PATCH_VERSION_C != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_ErmChannels_MIMX952X.c and MIMX9XX_SAF version are different"
#endif

#if SAFETY_BASE_MIMX952X
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define EMCEM_START_SEC_CONST_8
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0410 */
#include "eMcem_MemMap.h"

/* Channel count per each instance */
const uint8 au8ChannelsPerInstance[EMCEM_ERM_INSTANCE_COUNT] =
{
    10U,  /* AON */
    8U,   /* Wakeup */
    8U,   /* CM7 */
    2U    /* NPU */
};

#define EMCEM_STOP_SEC_CONST_8
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0410 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_2001 */
#include "eMcem_MemMap.h"

#define EMCEM_START_SEC_CONST_32
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0410 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_2001 */
#include "eMcem_MemMap.h"

/* Array of ERM instance base addresses */
const uint32 au32InstanceBaseAddr[EMCEM_ERM_INSTANCE_COUNT] = {
    0x44560000UL, /* AON */
    0x423B0000UL, /* Wakeup */
    0x4A070000UL, /* CM7 */
    0x4A870000UL  /* NPU */
};

/* Arrays of provided info per channel */
const uint32 au32SCStatusProvidedMask[EMCEM_ERM_MASK_SIZE] = {
    0x0FBE07FFUL
};

const uint32 au32NCStatusProvidedMask[EMCEM_ERM_MASK_SIZE] = {
    0x0FBE07FFUL
};

const uint32 au32AddrProvidedMask[EMCEM_ERM_MASK_SIZE] = {
    0x0F8207FFUL
};

const uint32 au32SynProvidedMask[EMCEM_ERM_MASK_SIZE] = {
    0x0F8207FFUL
};

#define EMCEM_STOP_SEC_CONST_32
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_0410 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_c_REF_2001 */
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#endif /* SAFETY_BASE_MIMX952X */

#ifdef __cplusplus
}
#endif

/** @} */
