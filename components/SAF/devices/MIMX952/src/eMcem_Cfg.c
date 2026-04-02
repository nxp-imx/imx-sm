/**
*   @file    eMcem_Cfg.c
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - Configuration Source.
*   @details This file implements eMcem configuration.
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
*   Copyright 2023-2026 NXP
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
#include "MIMX9XX_SAF_Version.h"
#include "eMcem_Cfg.h"
#include "eMcem.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMCEM_CFG_SW_MAJOR_VERSION_C               0
#define EMCEM_CFG_SW_MINOR_VERSION_C               8
#define EMCEM_CFG_SW_PATCH_VERSION_C               4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same Software version */
#if ((EMCEM_CFG_SW_MAJOR_VERSION_C != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_CFG_SW_MINOR_VERSION_C != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_CFG_SW_PATCH_VERSION_C != MIMX9XX_SAF_SW_PATCH_VERSION))
#error "Software Version Numbers of eMcem_Cfg.c and MIMX9XX_SAF version are different"
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

const uint32 eMcem_au32StaticFaultMasks[EMCEM_FAULT_MASK_ARRAY_SIZE] =
{
    0xFFFFDBFFU,
    0xF7FFFFDFU,
    0x01FFCCFFU,
    0xFFAEFFF0U,
    0x000007FFU
};

#define EMCEM_STOP_SEC_CONST_32
/* @violates @ref eMcem_Cfg_c_REF_0410 */
/* @violates @ref eMcem_Cfg_c_REF_2001 */
#include "eMcem_MemMap.h"


#define EMCEM_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref eMcem_Cfg_c_REF_0410 */
/* @violates @ref eMcem_Cfg_c_REF_2001 */
#include "eMcem_MemMap.h"

/**
* @brief    eMCEM FCCU Instance configuration struct type.
* @details  eMCEM Driver configuration structure type.
*/
const eMcem_CVfccuInstanceCfgType CVfccuCfg =
{
    /* ---------------------------------------- */
    /*                 General                  */
    /* ---------------------------------------- */
    (boolean)FALSE,  /*!< bDebugEnabled */
    14000000UL,     /*!< u32GlobalReactionTimerPeriod */
    42000000UL,     /*!< u32MinEoutDuration */

    /* ---------------------------------------- */
    /*            EOUT Configuration            */
    /* ---------------------------------------- */
    {
        (uint32)0x00000003UL, /*!< EoutTimerDisable */
        { /*!< EOUT Pin Regs */
            (uint32)0x00000000UL,
            (uint32)0x00000001UL
        },
        { /*!< EOUT Operating Mode Regs */
            (uint32)0x00000000UL,
            (uint32)0x00000009UL
        },
    },

    /* ---------------------------------------- */
    /*               Fault Lines                */
    /* ---------------------------------------- */
    { /*!< Fault Recovery Cfg */
        (uint32)0xFFFFFFFFUL,
        (uint32)0xFFFFFFFFUL,
        (uint32)0xFFFFFFFFUL,
        (uint32)0x0000000FUL
    },

    /* ---------------------------------------- */
    /*         VFCCU FHID Configuration         */
    /* ---------------------------------------- */
    {
        /* -------------------- */
        /*       General        */
        /* -------------------- */
        0U,             /*!< u8FaultHandlerId */
        (boolean)TRUE,  /*!< bEnabled */

        /* -------------------- */
        /*     Reaction Set     */
        /* -------------------- */
        { /*!< Immediate Reaction Set */
            (uint32)0x004UL,    /*!< Assert FCCU IRQ 0 */
            (uint32)0x008UL,    /*!< Assert FCCU IRQ 1 */
            (uint32)0x010UL,    /*!< Assert FCCU IRQ 2 */
            (uint32)0x004UL,    /*!< Assert FCCU IRQ 0 */
            (uint32)0x008UL,    /*!< Assert FCCU IRQ 1 */
            (uint32)0x010UL,    /*!< Assert FCCU IRQ 2 */
            (uint32)0x000UL,    /*!< None */
            (uint32)0x002UL,    /*!< PMIC reset (assert EOUT1) */
        },
        { /*!< Delayed Reaction Set */
            (uint32)0x002UL,    /*!< PMIC reset (assert EOUT1) */
            (uint32)0x002UL,    /*!< PMIC reset (assert EOUT1) */
            (uint32)0x002UL,    /*!< PMIC reset (assert EOUT1) */
            (uint32)0x100UL,    /*!< SRC reset */
            (uint32)0x100UL,    /*!< SRC reset */
            (uint32)0x100UL,    /*!< SRC reset */
            (uint32)0x002UL,    /*!< PMIC reset (assert EOUT1) */
            (uint32)0x002UL     /*!< PMIC reset (assert EOUT1) */
        },

        /* -------------------- */
        /*      Fault List      */
        /* -------------------- */
        { /*!< Faults Enabled */
            (uint32)0xFFFC000BUL,
            (uint32)0x60000003UL,
            (uint32)0x0000003FUL,
            (uint32)0x00000000UL
        },
        { /*!< Reaction Set ID's */
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
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL,
            (uint32)0x00000000UL
        },
        { /*!< Alarm Handler Names */
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

/*!
* @brief          eMcem Config.
* @details        The eMCEM driver configuration type.
*/
const eMcem_ConfigType eMcem_Config =
{
    /* ---------------------------------------- */
    /*                 General                  */
    /* ---------------------------------------- */
    (uint32)0x00000001UL,   /*!< u32ControlledEimInstances */
    (uint32)0x00000001UL,   /*!< u32ControlledSramcInstances */
    (uint32)0x00000000UL,   /*!< u32ControlledDdrcInstances */
    (uint32)0x00000001UL,   /*!< u32ControlledErmInstances */
    /* ---------------------------------------- */
    /*         Vfccu Configuration List         */
    /* ---------------------------------------- */
    &CVfccuCfg,
};

#define EMCEM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref eMcem_Cfg_c_REF_0410 */
/* @violates @ref eMcem_Cfg_c_REF_2001 */
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
* @brief      Set VFCCU alarm handler.
* @details    Complete fault processing and Reset if fault handling failed.
*
* @param[in]  nFaultId        ID of the fault that shall be recovered.
*
* @return     eMcem_ErrRecoveryType
* @retval           EMCEM_ERR_RECOVERED      Fault has been recovered.
* @retval           EMCEM_ERR_NOT_RECOVERED  Fault has not been recovered.
*/

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

    /*!< Finalize fault flow */
    status = DEV_SM_FaultComplete(resetRec);

    /*!< Reset if fault handling failed */
    if (status != SM_ERR_SUCCESS)
    {
        nReturnValue = EMCEM_ERR_MASK_VFCCU_ISR;
    }

    return nReturnValue;
}
/** @} */

#ifdef __cplusplus
}
#endif
/** @} */
