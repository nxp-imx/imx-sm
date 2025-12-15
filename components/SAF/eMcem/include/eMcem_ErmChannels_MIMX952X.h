/**
*   @file    eMcem_ErmChannels_MIMX952X.h
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - Specific ERM channels header.
*   @details Contains declarations of specific ERM channels for eMcem module.
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

#ifndef EMCEM_ERMCHANNELS_MIMX952X_H
#define EMCEM_ERMCHANNELS_MIMX952X_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_ErmChannels_MIMX952X_h_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ErmChannels_MIMX952X_h_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ErmChannels_MIMX952X_h_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ErmChannels_MIMX952X_h_REF_0505
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
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0501 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0502 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0504 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0505 */
#define EMCEM_ERMCHANNELS_MIMX952X_SW_MAJOR_VERSION             0
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0501 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0502 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0504 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0505 */
#define EMCEM_ERMCHANNELS_MIMX952X_SW_MINOR_VERSION             8
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0501 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0502 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0504 */
/* @violates @ref eMcem_ErmChannels_MIMX952X_h_REF_0505 */
#define EMCEM_ERMCHANNELS_MIMX952X_SW_PATCH_VERSION             4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same software version */
#if ((EMCEM_ERMCHANNELS_MIMX952X_SW_MAJOR_VERSION != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_ERMCHANNELS_MIMX952X_SW_MINOR_VERSION != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_ERMCHANNELS_MIMX952X_SW_PATCH_VERSION != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_ErmChannels_MIMX952X.h and MIMX9XX_SAF version are different"
#endif

#if SAFETY_BASE_MIMX952X
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* ERM channels base offset. Channels are aligned after SRAMC channels.
   Offset is a sum of VFCCU fault count, EIM channel count, SRAMC channel count and DDRC channel count.

   All memory and fault channels are aligned after each other to not overlap.
   The alignment of channels is following: VFCCU, EIM, SRAMC, DDRC, ERM,
   - the reason of aligning all channels is that SRAMC channels are used for both injection and detection functions
   - the IPs for which the injection is possible (VFCCU, EIM, SRAMC, DDRC) are at the beginning
     - different order would affect the eMcem_au32StaticFaultMasks variable (the mask would be longer as extra zeros would need to be placed there)
*/
#define EMCEM_ERM_CHANNELS_OFFSET                 ((100U) + (35U) + (1U) + (3U))

/* ERM Channels */
/* AON ERM */
#define EMCEM_ERM_AON_CH_0                        (0U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_AON_CH_1                        (1U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_AON_CH_2                        (2U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_AON_CH_3                        (3U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_AON_CH_4                        (4U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_AON_CH_5                        (5U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_AON_CH_6                        (6U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_AON_CH_7                        (7U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_AON_CH_8                        (8U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_AON_CH_9                        (9U + EMCEM_ERM_CHANNELS_OFFSET)

/* Wakeup ERM */
#define EMCEM_ERM_WAKEUP_CH_0                     (10U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_WAKEUP_CH_1_RESERVED            (11U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_WAKEUP_CH_2_RESERVED            (12U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_WAKEUP_CH_3_RESERVED            (13U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_WAKEUP_CH_4_RESERVED            (14U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_WAKEUP_CH_5_RESERVED            (15U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_WAKEUP_CH_6_RESERVED            (16U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_WAKEUP_CH_7                     (17U + EMCEM_ERM_CHANNELS_OFFSET)

/* CM7 ERM */
#define EMCEM_ERM_CM7_CH_0                        (18U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_CM7_CH_1                        (19U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_CM7_CH_2                        (20U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_CM7_CH_3                        (21U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_CM7_CH_4_RESERVED               (22U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_CM7_CH_5                        (23U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_CM7_CH_6                        (24U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_CM7_CH_7                        (25U + EMCEM_ERM_CHANNELS_OFFSET)

/* NPU ERM */
#define EMCEM_ERM_NPU_CH_0                        (26U + EMCEM_ERM_CHANNELS_OFFSET)
#define EMCEM_ERM_NPU_CH_1                        (27U + EMCEM_ERM_CHANNELS_OFFSET)

/* ERM Channels count */
#define EMCEM_ERM_CHANNEL_COUNT                   (28U)

/* ERM Instance count (AON, Wakeup, CM7, NPU) */
#define EMCEM_ERM_INSTANCE_COUNT                  (4U)

/* Mask size for ERM channel arrays */
#define EMCEM_ERM_MASK_SIZE                       ( ( ( EMCEM_ERM_CHANNEL_COUNT - 1U ) / 32U ) + 1U )

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


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* SAFETY_BASE_MIMX952X */

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_ERMCHANNELS_MIMX952X_H */

/** @} */
