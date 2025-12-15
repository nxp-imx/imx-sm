/**
*   @file    eMcem_EimChannels_MIMX952X.c
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - Specific EIM channels source.
*   @details Contains specific EIM error channels data for eMcem module.
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
* @section eMcem_EimChannels_MIMX952X_c_REF_0410
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_EimChannels_MIMX952X_c_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_EimChannels_MIMX952X_c_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_EimChannels_MIMX952X_c_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_EimChannels_MIMX952X_c_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_EimChannels_MIMX952X_c_REF_1104
* Violates MISRA 2012 Advisory Rule 11.4, A conversions should not be performed between a pointer to
* object and an integer type.
* Unavoidable when addressing memory mapped registers.
*
* @section eMcem_EimChannels_MIMX952X_c_REF_1106
* Violates MISRA 2012 Required Rule 11.6, A cast shall not be performed between pointer to void
* and an arithmetic type.
* Unavoidable when addressing memory mapped registers.
*
* @section eMcem_EimChannels_MIMX952X_c_REF_2001
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
#include "eMcem_EimChannels_MIMX952X.h"
#include "eMcem_Eim_Types.h"
#include "SafetyBase.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0501 */
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0502 */
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0504 */
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0505 */
#define EMCEM_EIMCHANNELS_MIMX952X_SW_MAJOR_VERSION_C               0
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0501 */
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0502 */
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0504 */
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0505 */
#define EMCEM_EIMCHANNELS_MIMX952X_SW_MINOR_VERSION_C               8
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0501 */
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0502 */
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0504 */
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0505 */
#define EMCEM_EIMCHANNELS_MIMX952X_SW_PATCH_VERSION_C               4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same software version */
#if ((EMCEM_EIMCHANNELS_MIMX952X_SW_MAJOR_VERSION_C != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_EIMCHANNELS_MIMX952X_SW_MINOR_VERSION_C != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_EIMCHANNELS_MIMX952X_SW_PATCH_VERSION_C != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_EimChannels_MIMX952X.c and MIMX9XX_SAF version are different"
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
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0410 */
#include "eMcem_MemMap.h"

/* Channel count per each instance */
const uint8 au8EimChannelsPerInstance[EMCEM_EIM_INSTANCE_COUNT] =
{
    13U,  /* AON Domain */
    8U,   /* Wakeup Domain */
    3U,   /* NOC Domain */
    9U,   /* CM7_0 Domain */
    2U    /* NPU Domain */
};

#define EMCEM_STOP_SEC_CONST_8
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0410 */
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_2001 */
#include "eMcem_MemMap.h"

#define EMCEM_START_SEC_CONST_UNSPECIFIED
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0410 */
#include "eMcem_MemMap.h"

/* EIM channels descriptors. Contains EIM instance address and CHKBIT, DATA bit widths */
const eMcem_Eim_DescriptorType eMcem_Eim_arrDescriptors[EMCEM_EIM_INSTANCE_COUNT] =
{
    /* AON Domain */
    {
        /* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_1104 */
        /* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_1106 */
        &AON_EIMA,
        {
           36U,  36U,  36U,  36U,  32U,  32U,  32U,  32U,
           32U,  32U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U
        },
        {
            8U,   8U,   8U,   8U,   7U,   7U,   7U,   7U,
            7U,   7U,   2U,   5U,   7U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U
        }
    },
    /* Wakeup Domain */
    {
        /* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_1104 */
        /* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_1106 */
        &WAKEUP_EIMW,
        {
           64U,   0U,   0U,   0U,  32U,   0U,   0U,  64U,
            0U,  64U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U
        },
        {
            8U,   5U,   0U,   0U,   0U,   0U,   7U,   8U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U
        }
    },
    /* NOC Domain */
    {
        /* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_1104 */
        /* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_1106 */
        &NOC_EIMN,
        {
            5U,   0U,  32U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U
        },
        {
            0U,  12U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U
        }
    },
    /* CM7 Domain */
    {
        /* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_1104 */
        /* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_1106 */
        &M7_EIM,
        {
           44U, 128U, 104U, 128U, 128U,  32U,  32U,  64U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U
        },
        {
           14U,  16U,  28U,  28U,  28U,   7U,   7U,   8U,
            2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U
        }
    },
    /* NPU Domain */
    {
        /* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_1104 */
        /* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_1106 */
        &NPU_EIM_NPUMIX,
        {
          128U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U
        },
        {
            9U,   1U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
            0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U
        }
    }
};

#define EMCEM_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_0410 */
/* @violates @ref eMcem_EimChannels_MIMX952X_c_REF_2001 */
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
