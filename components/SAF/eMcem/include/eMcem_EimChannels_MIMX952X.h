/**
*   @file    eMcem_EimChannels_MIMX952X.h
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - Specific EIM channels header.
*   @details Contains declarations of specific EIM channels for eMcem module.
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

#ifndef EMCEM_EIMCHANNELS_MIMX952X_H
#define EMCEM_EIMCHANNELS_MIMX952X_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_EimChannels_MIMX952X_h_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_EimChannels_MIMX952X_h_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_EimChannels_MIMX952X_h_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_EimChannels_MIMX952X_h_REF_0505
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
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0501 */
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0502 */
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0504 */
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0505 */
#define EMCEM_EIMCHANNELS_MIMX952X_SW_MAJOR_VERSION             0
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0501 */
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0502 */
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0504 */
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0505 */
#define EMCEM_EIMCHANNELS_MIMX952X_SW_MINOR_VERSION             8
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0501 */
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0502 */
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0504 */
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0505 */
#define EMCEM_EIMCHANNELS_MIMX952X_SW_PATCH_VERSION             4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same software version */
#if ((EMCEM_EIMCHANNELS_MIMX952X_SW_MAJOR_VERSION != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_EIMCHANNELS_MIMX952X_SW_MINOR_VERSION != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_EIMCHANNELS_MIMX952X_SW_PATCH_VERSION != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_EimChannels_MIMX952X.h and MIMX9XX_SAF version are different"
#endif

#if SAFETY_BASE_MIMX952X
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* EIM channels base offset. Channels are aligned after VFCCU faults */
#define EMCEM_EIM_CHANNELS_OFFSET          (100U)

/* EIM Channels */
/* AON EIM */
#define EMCEM_EIM_AON_CH_0                 (0U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_1                 (1U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_2                 (2U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_3                 (3U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_4                 (4U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_5                 (5U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_6                 (6U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_7                 (7U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_8                 (8U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_9                 (9U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_10                (10U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_11                (11U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_AON_CH_12                (12U + EMCEM_EIM_CHANNELS_OFFSET)

/* Wakeup EIM */
#define EMCEM_EIM_WAKEUP_CH_0              (13U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_WAKEUP_CH_1              (14U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_WAKEUP_CH_2_RESERVED     (15U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_WAKEUP_CH_3_RESERVED     (16U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_WAKEUP_CH_4              (17U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_WAKEUP_CH_5_RESERVED     (18U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_WAKEUP_CH_6              (19U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_WAKEUP_CH_7              (20U + EMCEM_EIM_CHANNELS_OFFSET)

/* NOC EIM */
#define EMCEM_EIM_NOC_CH_0                 (21U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_NOC_CH_1                 (22U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_NOC_CH_2                 (23U + EMCEM_EIM_CHANNELS_OFFSET)

/* CM7 EIM */
#define EMCEM_EIM_CM7_CH_0                 (24U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_CM7_CH_1                 (25U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_CM7_CH_2                 (26U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_CM7_CH_3                 (27U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_CM7_CH_4                 (28U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_CM7_CH_5                 (29U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_CM7_CH_6                 (30U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_CM7_CH_7                 (31U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_CM7_CH_8                 (32U + EMCEM_EIM_CHANNELS_OFFSET)

/* NPU EIM */
#define EMCEM_EIM_NPU_CH_0                 (33U + EMCEM_EIM_CHANNELS_OFFSET)
#define EMCEM_EIM_NPU_CH_1                 (34U + EMCEM_EIM_CHANNELS_OFFSET)

/* EIM Channels count */
#define EMCEM_EIM_CHANNEL_COUNT            (35U)

/* EIM Instance count */
#define EMCEM_EIM_INSTANCE_COUNT           (5U)

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
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0410 */
#include "eMcem_MemMap.h"

extern const uint8 au8EimChannelsPerInstance[EMCEM_EIM_INSTANCE_COUNT];

#define EMCEM_STOP_SEC_CONST_8
/* @violates @ref eMcem_EimChannels_MIMX952X_h_REF_0410 */
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* SAFETY_BASE_MIMX952X */

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_EIMCHANNELS_MIMX952X_H */

/** @} */
