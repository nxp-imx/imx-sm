/**
*   @file    eMcem_Cfg.c
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - Configuration Source.
*   @details This file implements eMcem configuration.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_Cfg_c_REF_0409
* Violates MISRA 2012 Advisory Rule 4.9, Function-like macros for shifting of configuration values.
*
* @section eMcem_Cfg_c_REF_0410
* Violates MISRA 2012 Required Rule 4.10, This is not a violation since all header files are protected
* against multiple inclusions.
*
* @section eMcem_Cfg_c_REF_2001
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
#include "sm.h"
#include "dev_sm.h"
#include "MIMX_SAF_Version.h"
#include "eMcem_Cfg.h"
#include "eMcem.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMCEM_CFG_SW_MAJOR_VERSION_C               0
#define EMCEM_CFG_SW_MINOR_VERSION_C               4
#define EMCEM_CFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same Software version */
#if ((EMCEM_CFG_SW_MAJOR_VERSION_C != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_CFG_SW_MINOR_VERSION_C != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_CFG_SW_PATCH_VERSION_C != MIMX_SAF_SW_PATCH_VERSION))
#error "Software Version Numbers of eMcem_Cfg.c and MIMX_SAF version are different"
#endif


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
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define EMCEM_START_SEC_CONST_32
/* @violates @ref eMcem_Cfg_c_REF_0410 */
/* @violates @ref eMcem_Cfg_c_REF_2001 */
#include "eMcem_MemMap.h"

const uint32 eMcem_au32StaticFaultMasks[3U] =
{
    0xFFFFFFFFU,
    0xFFFFFFFFU,
    0x0000FFFFU
};

#define EMCEM_STOP_SEC_CONST_32
/* @violates @ref eMcem_Cfg_c_REF_0410 */
/* @violates @ref eMcem_Cfg_c_REF_2001 */
#include "eMcem_MemMap.h"

const eMcem_CVfccuInstanceCfgType CVfccuCfg =
{
    FALSE, /* bDebugEnabled */
    TRUE, /* bConfigEnabled */
    14000000UL, /* u32GlobalReactionTimerPeriod */
    42000000UL, /* u32MinEoutDuration */
    { /* EOUT Cfg */
        (uint32)3UL, /* EoutTimerDisable */
        { /* EOUT Pin Regs */
            (uint32)0x00000000UL,
            (uint32)0x00000001UL
        },
        { /* EOUT Operating Mode Regs */
            (uint32)0x00000000UL,
            (uint32)0x00000009UL
        },
    },
    /* Fault Lines Cfg */
    /* Fault Recovery cfg */
    {
        (uint32)0xFFFFFFFFUL,
        (uint32)0xFFFFFFFFUL,
        (uint32)0x0000FFFFUL
    },
    /* CVfccuFhidCfgs */
    {
        0U,       /* u8FaultHandlerId */
        TRUE,     /* bEnabled */
        TRUE,     /* bWriteAccessEnabled */
        { /* ImmReactionRegs */
            (uint32)0x004UL,    /* Assert FCCU IRQ 0 */
            (uint32)0x008UL,    /* Assert FCCU IRQ 1 */
            (uint32)0x010UL,    /* Assert FCCU IRQ 2 */
            (uint32)0x004UL,    /* Assert FCCU IRQ 0 */
            (uint32)0x008UL,    /* Assert FCCU IRQ 1 */
            (uint32)0x010UL,    /* Assert FCCU IRQ 2 */
            (uint32)0x000UL,    /* None */
            (uint32)0x002UL,    /* PMIC reset (assert EOUT1) */
        },

        { /* DelReactionRegs */
            (uint32)0x002UL,    /* PMIC reset (assert EOUT1) */
            (uint32)0x002UL,    /* PMIC reset (assert EOUT1) */
            (uint32)0x002UL,    /* PMIC reset (assert EOUT1) */
            (uint32)0x100UL,    /* SRC reset */
            (uint32)0x100UL,    /* SRC reset */
            (uint32)0x100UL,    /* SRC reset */
            (uint32)0x002UL,    /* PMIC reset (assert EOUT1) */
            (uint32)0x002UL     /* PMIC reset (assert EOUT1) */
        },
        /* Fault List */
        { /* Fault Enabled */
            (uint32)0xFFFC0003UL,
            (uint32)0x00000003UL,
            (uint32)0x00000000UL
        },
        { /* Fault Reaction Set Cfg */
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00060000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL
        },
        { /* Fault Handlers */
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler,
            &eMcemCVfccuAlarmHandler
        }
    }
};

const eMcem_ConfigType eMcem_Config =
{
    &CVfccuCfg,
};

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
eMcem_ErrRecoveryType eMcemCVfccuAlarmHandler( eMcem_FaultType nFaultId )
{
    int32_t status;
    dev_sm_rst_rec_t resetRec =
    {
        .reason = DEV_SM_REASON_FCCU,
        .errId = (uint32_t) nFaultId,
        .validErr = true,
        .valid = true
    };
    eMcem_ErrRecoveryType nReturnValue = EMCEM_ERR_RECOVERED;

    /* Finalize fault flow */
    status = DEV_SM_FaultComplete(resetRec);

    /* Translate error */
    if (status != SM_ERR_SUCCESS)
    {
        nReturnValue = EMCEM_ERR_NOT_RECOVERED;
    }

    return nReturnValue;
}

#ifdef __cplusplus
}
#endif

/** @} */

