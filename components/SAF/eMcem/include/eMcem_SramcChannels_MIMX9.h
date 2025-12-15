/**
*   @file    eMcem_SramcChannels_MIMX9.h
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - Specific SRAMC channels header.
*   @details Contains declarations of specific SRAMC channels for eMcem module.
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
*   Copyright 2024-2025 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_SRAMCCHANNELS_MIMX9_H
#define EMCEM_SRAMCCHANNELS_MIMX9_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_SramcChannels_MIMX9_h_REF_0410
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_SramcChannels_MIMX9_h_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_SramcChannels_MIMX9_h_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_SramcChannels_MIMX9_h_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_SramcChannels_MIMX9_h_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX9XX_SAF_Version.h"
#include "SafetyBase_Cfg.h"
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0501 */
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0502 */
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0504 */
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0505 */
#define EMCEM_SRAMCCHANNELS_MIMX9_SW_MAJOR_VERSION             0
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0501 */
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0502 */
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0504 */
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0505 */
#define EMCEM_SRAMCCHANNELS_MIMX9_SW_MINOR_VERSION             8
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0501 */
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0502 */
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0504 */
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0505 */
#define EMCEM_SRAMCCHANNELS_MIMX9_SW_PATCH_VERSION             4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same software version */
#if ((EMCEM_SRAMCCHANNELS_MIMX9_SW_MAJOR_VERSION != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_SRAMCCHANNELS_MIMX9_SW_MINOR_VERSION != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_SRAMCCHANNELS_MIMX9_SW_PATCH_VERSION != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_SramcChannels_MIMX9.h and MIMX9XX_SAF version are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* SRAMC channels base offset. Channels are aligned after EIM channels.
   Offset is a sum of VFCCU fault count and EIM channel count.

   All memory and fault channels are aligned after each other to not overlap.
   The alignment of channels is following: VFCCU, EIM, SRAMC, DDRC, ERM
   - the reason of aligning all channels is that SRAMC channels are used for both injection and detection functions
   - the IPs for which the injection is possible (VFCCU, EIM, SRAMC, DDRC) are at the beginning
     - different order would affect the eMcem_au32StaticFaultMasks variable (the mask would be longer as extra zeros would need to be placed there)
*/
#if SAFETY_BASE_MIMX95XX
#define EMCEM_SRAMC_CHANNELS_OFFSET                             ((80U) + (37U))
#elif SAFETY_BASE_MIMX943X
#define EMCEM_SRAMC_CHANNELS_OFFSET                             ((128U) + (61U))
#elif SAFETY_BASE_MIMX952X
#define EMCEM_SRAMC_CHANNELS_OFFSET                             ((100U) + (35U))
#else
#error "Wrong platform defined."
#endif /* SAFETY_BASE_MIMX95XX */


/* NOC SRAMC channels */
#define EMCEM_SRAMC_NOC_CH_0                                    (0U + EMCEM_SRAMC_CHANNELS_OFFSET)

/* SRAMC channel count */
#define EMCEM_SRAMC_CHANNEL_COUNT                               (1U)

/* SRAMC instances */
#define EMCEM_SRAMC_NOC_INSTANCE                                (0U)

/* SRAMC instance count */
#define EMCEM_SRAMC_INSTANCE_COUNT                              (1U)

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
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0410 */
#include "eMcem_MemMap.h"

extern const uint8 eMcem_au8SramcChannelsPerInstance[EMCEM_SRAMC_INSTANCE_COUNT];

#define EMCEM_STOP_SEC_CONST_8
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0410 */
#include "eMcem_MemMap.h"

#define EMCEM_START_SEC_CONST_32
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0410 */
#include "eMcem_MemMap.h"

extern const uint32 eMcem_u32SramcBaseAddress[EMCEM_SRAMC_INSTANCE_COUNT];

#define EMCEM_STOP_SEC_CONST_32
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0410 */
#include "eMcem_MemMap.h"

#define EMCEM_START_SEC_CONST_UNSPECIFIED
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0410 */
#include "eMcem_MemMap.h"

extern volatile struct SRAMCTL_tag * const eMcem_SramcBaseAddress[EMCEM_SRAMC_CHANNEL_COUNT];

#define EMCEM_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref eMcem_SramcChannels_MIMX9_h_REF_0410 */
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_SRAMCCHANNELS_MIMX9_H */

/** @} */
