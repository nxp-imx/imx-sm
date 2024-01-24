/**
*   @file    eMcem_Vfccu.c
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - VFCCU IP source.
*   @details This file implements VVFCCU IP functions for eMcem module.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_Vfccu_c_REF_0103
* Violates MISRA 2012 Required Rule 1.3, Taking address of near auto variable is safe operation on the target platform.
*
* @section eMcem_Vfccu_c_REF_0202
* Violates MISRA 2012 Required Rule 2.2, This is a non-null statement. Function resumes the interrupts.
*
* @section eMcem_Vfccu_c_REF_0410
* Violates MISRA 2012 Required Rule 4.10, This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_Vfccu_c_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Vfccu_c_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Vfccu_c_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Vfccu_c_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Vfccu_c_REF_0807
* Violates MISRA 2012 Advisory Rule 8.7, This function/object shall be accessible externally.
*
* @section eMcem_Vfccu_c_REF_1003
* Violates MISRA 2012 Required Rule 10.3, Unavoidable when addressing memory mapped registers.
* Stored values are always within the range of the register field.
*
* @section eMcem_Vfccu_c_REF_1104
* Violates MISRA 2012 Advisory Rule 11.4, Unavoidable when addressing memory mapped registers.
*
* @section eMcem_Vfccu_c_REF_1106
* Violates MISRA 2012 Required Rule 11.6, Unavoidable when addressing memory mapped registers.
*
* @section eMcem_Vfccu_c_REF_1403
* Violates MISRA 2012 Required Rule 14.3, Condition does not always evaluate to False as the variable is being set
* in a subfunction before the if condition.
*
* @section eMcem_Vfccu_c_REF_2001
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
#include "MIMX_SAF_Version.h"
#include "eMcem_Types_Ext.h"
#include "eMcem.h"
#include "eMcem_Vfccu.h"
#include "eMcem_Cfg.h"
#include "eMcem_ExtDiagApi.h"
#include "eMcem_VfccuFaultList_MIMX95XX.h"
#include "SafetyBase.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMCEM_VFCCU_SW_MAJOR_VERSION_C               0
#define EMCEM_VFCCU_SW_MINOR_VERSION_C               4
#define EMCEM_VFCCU_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_VFCCU_SW_MAJOR_VERSION_C != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_VFCCU_SW_MINOR_VERSION_C != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_VFCCU_SW_PATCH_VERSION_C != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Vfccu.c and MIMX_SAF version are different"
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
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define EMCEM_START_SEC_CODE
/* @violates @ref eMcem_Vfccu_c_REF_0410 */
#include "eMcem_MemMap.h"

static Std_ReturnType eMcem_Vfccu_InitCVfccu( const eMcem_CVfccuInstanceCfgType *pVfccuCfg );
static void eMcem_Vfccu_GetRegBitPosition( eMcem_FaultType nFaultId, uint8 *pu8RegIdx, uint8 *pu8BitIdx );
static boolean eMcem_Vfccu_SWRecovery( eMcem_FaultType nFaultId, uint32 u32RegVal );
static boolean eMcem_Vfccu_AccessToCVfccuFhid( void );
Std_ReturnType eMcem_Vfccu_ClearCVfccuFaults( eMcem_FaultType nFaultId, uint32 u32RegVal );

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Get register and bit position
* @details    Function calculates and returns global register and bit position for given fault.
*             Used for storing fault info into fault container (GetErrors functions)
*
* @param[in]  nFaultId    Fault ID for calculation of register and bit position
* @param[out]  pu8RegIdx  Register index
* @param[out]  pu8BitIdx  Bit index
*
*/
static void eMcem_Vfccu_GetRegBitPosition( eMcem_FaultType nFaultId, uint8 *pu8RegIdx, uint8 *pu8BitIdx )
{
    /* Calculate register index for given fault (global register offset + local register offset) */
    *pu8RegIdx = (uint8)(nFaultId / EMCEM_REG_SIZE);
    /* Calculate fault (status bit) index within register */
    *pu8BitIdx = (uint8)(nFaultId % EMCEM_REG_SIZE);
}

/**
* @brief      Initialize CVFCCU
* @details    Function configures CVFCCU registers using user generated config file.
*
* @param[in]  pVfccuCfg       CVFCCU configuration structure
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      Configuration of VFCCU was successful
* @retval           EMCEM_E_NOT_OK  Configuration of VFCCU was not successful
*
*/
static Std_ReturnType eMcem_Vfccu_InitCVfccu( const eMcem_CVfccuInstanceCfgType *pVfccuCfg )
{
    Std_ReturnType nReturnValue = EMCEM_E_OK;
    uint32 u32RegVal = 0UL;
    uint8 u8i = 0U;

    /* Check if configuration of the global VFCCU parameters is enabled */
    if( EMCEM_TRUE == pVfccuCfg->bConfigEnabled )
    {
        /* Configure Fault Line Recovery */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON__FCCU.GFLTRC_C0.R = pVfccuCfg->au32Recovery[0];

        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON__FCCU.GFLTRC_C1.R = pVfccuCfg->au32Recovery[1];

        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON__FCCU.GFLTRC_C2.R = pVfccuCfg->au32Recovery[2];

	    /* Go through all EOUT pins and configure them */
        for( u8i = 0U; u8i < EMCEM_EOUT_PIN_COUNT; u8i++ )
        {
	        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.GLB_EOUT[u8i].GEOUTPNC.R = ( (uint32)pVfccuCfg->eMcem_EoutCfg.u32EoutPin[u8i] & EMCEM_EOUT_GEOUTPNC_MASK );
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.GLB_EOUT[u8i].GEOUTMC.R = ( (uint32)pVfccuCfg->eMcem_EoutCfg.u8EoutOperatingMode[u8i] & EMCEM_EOUT_GEOUTMC_MASK );
        }
        /* Configure Global Reaction Timer */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON__FCCU.GRKNTIMC[0].R  = pVfccuCfg->u32GlobalReactionTimerPeriod;
        /* Configure Minimum EOUT Duration */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON__FCCU.GMEOUTDC.R = pVfccuCfg->u32MinEoutDuration;
        /* Global EOUT Timer Disable */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON__FCCU.GEOUTTCT.R = (uint32)pVfccuCfg->eMcem_EoutCfg.u8EoutTimerDisabled;
    }

    /* Configure local VFCCU parameters (FHIDs)
       Check if configuration of the VFCCU FHID parameters is enabled */
    if( EMCEM_TRUE == pVfccuCfg->eMcem_FhidCfg.bWriteAccessEnabled )
    {
        /* Need to clear status flags and disable FH to be able to reconfigure it */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON__FCCU.FHFLTS0_0.R = 0xFFFFFFFFUL;

	    /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON__FCCU.FHFLTS0_1.R = 0xFFFFFFFFUL;
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON__FCCU.FHFLTS0_2.R = 0xFFFFFFFFUL;

        /* Prepare one variable to check for any fault present */
        u32RegVal |= AON__FCCU.FHFLTS0_0.R;
        u32RegVal |= AON__FCCU.FHFLTS0_1.R;
        u32RegVal |= AON__FCCU.FHFLTS0_2.R;

        /* Check if Fault Lines were cleared, if not return EMCEM_E_NOT_OK */
        if( 0UL < u32RegVal )
        {
	        nReturnValue = EMCEM_E_NOT_OK;
        }
        else
        {
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHCFG0.B.FHIDEN = 0U;

            /* Enable faults */
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTENC0_0.R = pVfccuCfg->eMcem_FhidCfg.u32FaultEnabled[0];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTENC0_1.R = pVfccuCfg->eMcem_FhidCfg.u32FaultEnabled[1];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTENC0_2.R = pVfccuCfg->eMcem_FhidCfg.u32FaultEnabled[2];

            /* Configure reaction sets */
            /* TODO: Improvement: Fill the registers using loop */
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_0.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[0];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_1.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[1];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_2.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[2];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_3.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[3];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_4.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[4];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_5.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[5];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_6.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[6];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_7.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[7];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_8.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[8];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_9.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[9];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_10.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[10];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_11.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[11];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_12.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[12];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_13.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[13];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_14.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[14];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_15.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[15];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_16.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[16];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_17.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[17];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_18.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[18];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHFLTRKC0_19.R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[19];

            /* Configure immediate and delayed reactions */
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHIMRKC0_00.R = pVfccuCfg->eMcem_FhidCfg.u32ImmReaction[0];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHIMRKC0_10.R = pVfccuCfg->eMcem_FhidCfg.u32ImmReaction[1];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHIMRKC0_20.R = pVfccuCfg->eMcem_FhidCfg.u32ImmReaction[2];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHIMRKC0_30.R = pVfccuCfg->eMcem_FhidCfg.u32ImmReaction[3];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_VfENDccu_c_REF_1106 */
            AON__FCCU.FHIMRKC0_40.R = pVfccuCfg->eMcem_FhidCfg.u32ImmReaction[4];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHIMRKC0_50.R = pVfccuCfg->eMcem_FhidCfg.u32ImmReaction[5];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHIMRKC0_60.R = pVfccuCfg->eMcem_FhidCfg.u32ImmReaction[6];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHIMRKC0_70.R = pVfccuCfg->eMcem_FhidCfg.u32ImmReaction[7];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHDLRKC0_00.R = pVfccuCfg->eMcem_FhidCfg.u32DelReaction[0];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHDLRKC0_10.R = pVfccuCfg->eMcem_FhidCfg.u32DelReaction[1];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHDLRKC0_20.R = pVfccuCfg->eMcem_FhidCfg.u32DelReaction[2];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHDLRKC0_30.R = pVfccuCfg->eMcem_FhidCfg.u32DelReaction[3];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHDLRKC0_40.R = pVfccuCfg->eMcem_FhidCfg.u32DelReaction[4];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHDLRKC0_50.R = pVfccuCfg->eMcem_FhidCfg.u32DelReaction[5];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHDLRKC0_60.R = pVfccuCfg->eMcem_FhidCfg.u32DelReaction[6];
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON__FCCU.FHDLRKC0_70.R = pVfccuCfg->eMcem_FhidCfg.u32DelReaction[7];
	    }
    }

    /* Check if configuration of the global VFCCU parameters is enabled */
    if( ( EMCEM_TRUE == pVfccuCfg->bConfigEnabled ) && ( EMCEM_E_OK == nReturnValue ) )
    {
        /* Configure Global Debug */
        /* @violates @ref eMcem_Vfccu_c_REF_1003 */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON__FCCU.GDBGCFG.B.FRZ = (uint32)(pVfccuCfg->bDebugEnabled);
    }

    /* Check if configuration of the VFCCU FHID parameters is enabled */
    if( (EMCEM_TRUE == pVfccuCfg->eMcem_FhidCfg.bWriteAccessEnabled ) && ( EMCEM_E_OK == nReturnValue) )
    {
        /* Enable/disable FHID */
        /* @violates @ref eMcem_Vfccu_c_REF_1003 */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON__FCCU.FHCFG0.B.FHIDEN = (uint32)(pVfccuCfg->eMcem_FhidCfg.bEnabled);
    }

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_VFCCU_INIT_CVFCCU, 0U )

    return nReturnValue;
}

/**
* @brief      Checks Access to CVFCCU FHID
* @details    Returns if this EENV has full access to CVFCCU FHID
*
* @return     boolean
* @retval           EMCEM_E_TRUE    EENV has access to CVFCCU Fhid
* @retval           EMCEM_E_FALSE   EENV doesn't have access to CVFCCU Fhid
*
*/
static boolean eMcem_Vfccu_AccessToCVfccuFhid( void )
{
    boolean bReturnValue = EMCEM_FALSE;

    if( NULL_PTR != eMcem_pConfigPtr->eMcem_CVfccuCfg )
    {
        /* Check if write access to FH is enabled */
        if( EMCEM_TRUE == eMcem_pConfigPtr->eMcem_CVfccuCfg->eMcem_FhidCfg.bWriteAccessEnabled )
        {
            bReturnValue = EMCEM_TRUE;
        }
        else
        {
            /* no write access to CVFCCU, use IPC */
            /* Log extended diagnostic data */
            EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ACCESS_TO_CVFCCU_FHID_1, 0U )
            EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( EMCEM_E_NOT_OK, (uint32)u8Fhid )
        }
    }
    else
    {
        /* no CVFCCU in config, use IPC */
        /* Log extended diagnostic data */
        EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ACCESS_TO_CVFCCU_FHID_2, 0U )
        EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( EMCEM_E_NOT_OK, (uint32)u8Fhid )
    }

    return bReturnValue;
}

/**
* @brief      Check if Fault is SW Recoverable
* @details    Function check if Fault is SW or HW Recoverable
*
* @param[in]  nFaultId         The ID of the fault that shall be cleared
* @param[in]  u32RegVal        Value that specifies multi fault check
*                               - single CVFCCU fault, it is set to 1U
*                               - when multiple, even one SW is enough to return SW recoverable
*
* @return     boolean
* @retVal           TRUE    Fault is SW Recoverable
* @retVal           FALSE   Fault is HW Recoverable
*
*/
static boolean eMcem_Vfccu_SWRecovery( eMcem_FaultType nFaultId, uint32 u32RegVal )
{
    boolean bReturnValue = EMCEM_FALSE;
    uint8 u8RegIdx = (uint8)( nFaultId / EMCEM_REG_SIZE );
    uint8 u8BitPosition = (uint8)( nFaultId % EMCEM_REG_SIZE );

    if( (( 0UL != ( AON__FCCU.GFLTRC_C0.R & ( u32RegVal << u8BitPosition ) ) ) && (u8RegIdx == 0U) ) ||
        (( 0UL != ( AON__FCCU.GFLTRC_C1.R & ( u32RegVal << u8BitPosition ) ) ) && (u8RegIdx == 1U) ) ||
        (( 0UL != ( AON__FCCU.GFLTRC_C2.R & ( u32RegVal << u8BitPosition ) ) ) && (u8RegIdx == 2U) ) )
    {
        bReturnValue = EMCEM_TRUE;
    }

    return bReturnValue;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Checks Access to CVFCCU
* @details    Returns if this EENV has full access to CVFCCU global registers
*
* @return     boolean
* @retval           EMCEM_E_TRUE    EENV has access to CVFCCU
* @retval           EMCEM_E_FALSE   EENV doesn't have access to CVFCCU
*
*/
boolean eMcem_Vfccu_AccessToCVfccu( void )
{
    boolean bReturnValue = EMCEM_FALSE;

    if( eMcem_pConfigPtr->eMcem_CVfccuCfg != NULL_PTR )
    {
        /* Check if write access to FH is enabled */
        if( EMCEM_TRUE == eMcem_pConfigPtr->eMcem_CVfccuCfg->bConfigEnabled )
        {
            bReturnValue = EMCEM_TRUE;
        }
        else
        {
            /* no write access to CVFCCU, use IPC */
            /* Log extended diagnostic data */
            EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ACCESS_TO_CVFCCU_1, 0U )
        }
    }
    else
    {
        /* no CVFCCU in config, use IPC */
        /* Log extended diagnostic data */
        EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ACCESS_TO_CVFCCU_2, 0U )
    }

    return bReturnValue;
}

/**
* @brief      Clear CVFCCU faults function
* @details    Function clears fault line flags in CVFCCU
*
* @param[in]  nFaultId         The ID of the fault that shall be cleared
* @param[in]  u32RegVal        The value to clear the status registers with. For clearing of:
*                               - single CVFCCU fault, it is set to 1U
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      Faults were cleared successfully
* @retval           EMCEM_E_NOT_OK  Faults were not cleared
*
*/
Std_ReturnType eMcem_Vfccu_ClearCVfccuFaults( eMcem_FaultType nFaultId, uint32 u32RegVal )
{
    Std_ReturnType nReturnValue = EMCEM_E_OK;
    boolean bClearFault;
    uint8 u8RegIdx = (uint8)(nFaultId / EMCEM_REG_SIZE);
    uint8 u8BitIdx = (uint8)(nFaultId % EMCEM_REG_SIZE);

    /* Check if fault is SW recoverable */
    bClearFault = eMcem_Vfccu_SWRecovery( nFaultId, u32RegVal );

    /* Check access to CVFCCU */
    bClearFault = bClearFault && eMcem_Vfccu_AccessToCVfccuFhid();

    if( EMCEM_TRUE == bClearFault )
    {
        /* Check if any fault was detected in fault handler */
        if( 0UL < AON__FCCU.FHSRVDS0.B.AGGFLTS )
        {
            if (u8RegIdx == 0U)
            {
                AON__FCCU.FHFLTS0_0.R |= ( u32RegVal << u8BitIdx );
            }
            else if (u8RegIdx == 1U)
            {
                AON__FCCU.FHFLTS0_1.R |= ( u32RegVal << u8BitIdx );
            }
            else
            {
                AON__FCCU.FHFLTS0_2.R |= ( u32RegVal << u8BitIdx );
            }
        }
        else
        {
            /* no faults present - do nothing */
        }
    }
    else
    {
        /* no access to CVFCCU, this will trigger IPC communication, but do it once loop is done,
            * to avoid unnecessary IPC calls to SysMan - do nothing */
    }

    /* Report EMCEM_E_NOT_OK when not all fault were cleared */
    if((( 0UL != ( AON__FCCU.FHFLTS0_0.R & ( u32RegVal << u8BitIdx ) ) ) && (u8RegIdx == 0U)) ||
       (( 0UL != ( AON__FCCU.FHFLTS0_1.R & ( u32RegVal << u8BitIdx ) ) ) && (u8RegIdx == 1U)) ||
       (( 0UL != ( AON__FCCU.FHFLTS0_2.R & ( u32RegVal << u8BitIdx ) ) ) && (u8RegIdx == 2U)))
    {
        nReturnValue |= EMCEM_E_NOT_OK;
    }
    else
    {
        /* report EMCEM_E_OK, which is set as default - do nothing */
    }

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_VFCCU_CLEAR_CVFCCU_FAULTS, 0U )
    EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( nReturnValue, (uint32)nLocalFaultId )

    return nReturnValue;
}

/**
* @brief      VFCCU Init function
* @details    Initialization function for the VFCCU IP
*
* @param[in]  pConfigPtr  Configuration pointer used for initialization
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      Initialization was executed correctly
* @retval           EMCEM_E_NOT_OK  Initialization was not executed correctly
*
*/
Std_ReturnType eMcem_Vfccu_Init( const eMcem_ConfigType *pConfigPtr )
{
    volatile Std_ReturnType nReturnValue = EMCEM_E_OK;

    /* Configure CVFCCU */
    if( pConfigPtr->eMcem_CVfccuCfg != NULL_PTR )
    {
        nReturnValue = eMcem_Vfccu_InitCVfccu( pConfigPtr->eMcem_CVfccuCfg );
    }

    return nReturnValue;
}

/**
* @brief      Get SW faults function
* @details    Function gets status of SW faults and stores this info in the error container.
*             Some calculations have to Be made to align the SW faults after the status of the rest of VFCCU instance faults
*
* @param[out] pFaultContainer    Error container where the errors will be stored
* @param[out] pFaultAccumulator  Accumulator where all fault bits are aggregated
* @param[in]  nFaultId           ID of the first SW fault for the given VFCCU
*
* @return     void
*
*/
void eMcem_Vfccu_GetSWFaults( uint32 pFaultContainer[], uint32 *pFaultAccumulator, eMcem_FaultType nFaultId )
{
    uint8 u8RegIdx = 0U;
    uint8 u8BitIdx = 0U;
    uint8 u8MaxBitPos = (uint8)(EMCEM_REG_SIZE - EMCEM_SW_FAULT_OFFSET);
    uint8 u8SWRegIdx = 0U;
    uint32 u32RegVal[EMCEM_SW_FAULT_REG_COUNT];

    /* Calculate register and bit indexes out of nFaultId (as there is no offsetting per whole register - SW faults
       are aligned after the rest of VFCCU faults) */
    eMcem_Vfccu_GetRegBitPosition( nFaultId, &u8RegIdx, &u8BitIdx );

    /* Read SW fault status registers */
    for( u8SWRegIdx = 0U; u8SWRegIdx < EMCEM_SW_FAULT_REG_COUNT; u8SWRegIdx++ )
    {
        if (u8SWRegIdx == 0U)
        {
            u32RegVal[u8SWRegIdx] = ( AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM.FCCU_SW_FAULTS.R );
        }
        else
        {
            /* TODO: Enable CM7 FCCU clock firstly */
            /* u32RegVal[u8SWRegIdx] = ( M7__A7_MCM.FCCU_SW_FAULTS.R ); */
	        u32RegVal[u8SWRegIdx] = 0UL;
        }
    }

    /* Go through FCCU SW faults registers.
       Shift the value to the left properly to be able to append the SW fault status to the fault container */
    for( u8SWRegIdx = 0U; u8SWRegIdx < EMCEM_SW_FAULT_REG_COUNT; u8SWRegIdx++ )
    {
        /* Check if all SW fault status bits of current SW fault register can fit into current fault container register */
        if( u8BitIdx <= u8MaxBitPos )
        {
            /* Shift retrieved fault status by SW fault bit position */
            u32RegVal[u8SWRegIdx] <<= u8BitIdx;

            /* Update fault container with SW faults */
            pFaultContainer[u8RegIdx] |= u32RegVal[u8SWRegIdx];

            /* Accumulate SW faults */
            *pFaultAccumulator |= u32RegVal[u8SWRegIdx];

            /* Update Fault register and bit */
            nFaultId += EMCEM_SW_FAULT_OFFSET;
            eMcem_Vfccu_GetRegBitPosition( nFaultId, &u8RegIdx, &u8BitIdx );
        }
        else
        {
            /* Mask out the status bits not applicable for the current fault container register */
            pFaultContainer[u8RegIdx] |= ( u32RegVal[u8SWRegIdx] & ( 0xFFFFFFFFUL >> u8BitIdx ) ) << u8BitIdx;

            /* Accumulate SW faults */
            *pFaultAccumulator |= pFaultContainer[u8RegIdx];

            /* Update fault bit index */
            u8BitIdx = ( ( u8BitIdx + EMCEM_SW_FAULT_OFFSET ) % EMCEM_REG_SIZE );

            /* The rest of status bits shall be shifted and stored in the next fault container register */
            u32RegVal[u8SWRegIdx] >>= ( EMCEM_SW_FAULT_OFFSET - u8BitIdx );

            /* Update register index */
            u8RegIdx++;

            /* Update fault container with SW faults */
            pFaultContainer[u8RegIdx] |= u32RegVal[u8SWRegIdx];

            /* Accumulate SW faults */
            *pFaultAccumulator |= u32RegVal[u8SWRegIdx];

            /* Update Fault register and bit */
            nFaultId += EMCEM_SW_FAULT_OFFSET;
            eMcem_Vfccu_GetRegBitPosition( nFaultId, &u8RegIdx, &u8BitIdx );
        }
    }
}

/**
* @brief      Clear fault function
* @details    Function shall clear error flag for a specified fault.
*
* @param[in]  nFaultId              The ID of the fault that shall be cleared
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      Fault was cleared successfully
* @retval           EMCEM_E_NOT_OK  Fault was not cleared
*
* @implements DD_eMcem_ClearFaults_seq
*
*/
Std_ReturnType eMcem_Vfccu_ClearFaults( eMcem_FaultType nFaultId )
{
    Std_ReturnType nReturnValue = EMCEM_E_NOT_OK;

    nReturnValue = eMcem_Vfccu_ClearCVfccuFaults( nFaultId, 1UL );

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_VFCCU_CLEAR_FAULTS_1, 0U )
    EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( nReturnValue, (uint32)nLocalFaultId)

    return nReturnValue;
}

/**
* @brief      Get errors function
* @details    Function gets logged errors from the VFCCU IP and stores them in the error container
*
* @param[out] pFaultContainer    Error container where the errors will be stored
* @param[out] pFaultAccumulator  Accumulator where all fault bits are aggregated
*
* @return     void
*
*/
void eMcem_Vfccu_GetErrors( uint32 pFaultContainer[], uint32 *pFaultAccumulator )
{
    uint8 u8RegIdx;

    /* Check if any fault was detected in fault handler */
    if( 0UL < AON__FCCU.FHSRVDS0.B.AGGFLTS )
    {
        /* Go through fault status registers of CVFCCU */
        for( u8RegIdx = 0U; u8RegIdx < EMCEM_VFCCU_ERROR_CONTAINER_SIZE; u8RegIdx++ )
        {
            /* Read fault status register and OR it with current values in the fault container.
               Values for all Fault containers are ORed together */
            if (u8RegIdx == 0U)
            {
                pFaultContainer[u8RegIdx] |= AON__FCCU.FHFLTS0_0.R;
            }
            else if (u8RegIdx == 1U)
            {
                pFaultContainer[u8RegIdx] |= AON__FCCU.FHFLTS0_1.R;
            }
            else
            {
                pFaultContainer[u8RegIdx] |= AON__FCCU.FHFLTS0_2.R;
            }
            /* Accumulate all faults */
            *pFaultAccumulator |= pFaultContainer[u8RegIdx];
        }
    }
}

/**
* @brief      Assert software VFCCU fault.
* @details    Sets reaction line for software fault.
*
* @param[in]  nFaultId      ID of the SW fault that shall be asserted.
*
* @return     void
*
*/
void eMcem_Vfccu_AssertSWFault( uint8 u8SwFaultId )
{
    uint8 u8BitIdx = u8SwFaultId % EMCEM_VFCCU_SW_FAULT_COUNT;

    /* Check if fault is in AON(CM33) range */
    if( u8SwFaultId < EMCEM_SW_FAULT_OFFSET )
    {
        /* Assert SW fault in M33 */
        AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM.FCCU_SW_FAULTS.R |= ( 1UL << u8BitIdx );
    }
    else
    {
        /* Assert SW fault in M7 */
        M7__A7_MCM.FCCU_SW_FAULTS.R |= ( 1UL << u8BitIdx );
    }
}

/**
* @brief      Deassert software VFCCU fault.
* @details    Clears the software fault on the corresponding reaction line.
*
* @param[in]  nFaultId      ID of the SW fault that shall be deasserted.
*
* @return     void
*
*/
void eMcem_Vfccu_DeassertSWFault( uint8 u8SwFaultId )
{
    uint8 u8BitIdx = u8SwFaultId % EMCEM_VFCCU_SW_FAULT_COUNT;

    /* Check if fault is in AON(CM33) range */
    if( u8SwFaultId < EMCEM_SW_FAULT_OFFSET )
    {
        /* Deassert SW fault in M33 */
        AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM.FCCU_SW_FAULTS.R &= ~( 1UL << u8BitIdx );
    }
    else
    {
        /* Deassert SW fault in M7 */
        M7__A7_MCM.FCCU_SW_FAULTS.R &= ~( 1UL << u8BitIdx );
    }
}

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_Vfccu_c_REF_0410 */
/* @violates @ref eMcem_Vfccu_c_REF_2001 */
#include "eMcem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
