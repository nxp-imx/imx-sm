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
*   Build Version        : MIMX9X_SAF_0_4_0
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
#include "eMcem_Vfccu_MIMX95XX.h"
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
static boolean eMcem_Vfccu_SWRecovery( eMcem_FaultType nFaultId, uint32 u32RegVal );
static boolean eMcem_Vfccu_AccessToCVfccuFhid( void );
Std_ReturnType eMcem_Vfccu_ClearCVfccuFaults( eMcem_FaultType nFaultId, uint32 u32RegVal );

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
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
    if( (boolean)TRUE == pVfccuCfg->bConfigEnabled )
    {
        /* Configure Fault Line Recovery */
        for( u8i = 0U; u8i < EMCEM_CVFCCU_FAULT_RECOVERY_REG_COUNT; u8i++ )
        {
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON_VFCCU.GFLTRC[u8i].R = pVfccuCfg->au32Recovery[u8i];
        }

        /* Go through all EOUT pins and configure them */
        for( u8i = 0U; u8i < EMCEM_EOUT_PIN_COUNT; u8i++ )
        {
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON_VFCCU.GLB_EOUT[u8i].GEOUTPNC.R = ( (uint32)pVfccuCfg->eMcem_EoutCfg.u32EoutPin[u8i] & EMCEM_EOUT_GEOUTPNC_MASK );
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON_VFCCU.GLB_EOUT[u8i].GEOUTMC.R = ( (uint32)pVfccuCfg->eMcem_EoutCfg.u32EoutOperatingMode[u8i] & EMCEM_EOUT_GEOUTMC_MASK );
        }
        /* Configure Global Reaction Timer */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON_VFCCU.GRKNTIMC[0].R  = pVfccuCfg->u32GlobalReactionTimerPeriod;
        /* Configure Minimum EOUT Duration */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON_VFCCU.GMEOUTDC.R = pVfccuCfg->u32MinEoutDuration;
        /* Global EOUT Timer Disable */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON_VFCCU.GEOUTTCT.R = (uint32)pVfccuCfg->eMcem_EoutCfg.u32EoutTimerDisabled;
    }

    /* Configure local VFCCU parameters (FHIDs)
       Check if configuration of the VFCCU FHID parameters is enabled */
    if( (boolean)TRUE == pVfccuCfg->eMcem_FhidCfg.bWriteAccessEnabled )
    {
        for( u8i = 0U; u8i < EMCEM_VFCCU_FHFLTS_REG_COUNT; u8i++ )
        {
            /* Need to clear status flags and disable FH to be able to reconfigure it */
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON_VFCCU.FHFLTS[u8i].R = 0xFFFFFFFFUL;

            /* Prepare one variable to check for any fault present */
            u32RegVal |= AON_VFCCU.FHFLTS[u8i].R;
        }

        /* Check if Fault Lines were cleared, if not return EMCEM_E_NOT_OK */
        if( 0UL < u32RegVal )
        {
            nReturnValue = EMCEM_E_NOT_OK;
        }
        else
        {
            /* @violates @ref eMcem_Vfccu_c_REF_1104 */
            /* @violates @ref eMcem_Vfccu_c_REF_1106 */
            AON_VFCCU.FHCFG0.B.FHIDEN = 0U;

            /* Enable faults */
            for( u8i = 0U; u8i < EMCEM_CVFCCU_FAULT_ENABLE_REG_COUNT; u8i++ )
            {
                /* @violates @ref eMcem_Vfccu_c_REF_1104 */
                /* @violates @ref eMcem_Vfccu_c_REF_1106 */
                AON_VFCCU.FHFLTENC[u8i].R = pVfccuCfg->eMcem_FhidCfg.u32FaultEnabled[0];
            }

            /* Configure reaction sets */
            for( u8i = 0U; u8i < EMCEM_CVFCCU_REACTION_SET_REG_COUNT; u8i++ )
            {
                /* @violates @ref eMcem_Vfccu_c_REF_1104 */
                /* @violates @ref eMcem_Vfccu_c_REF_1106 */
                AON_VFCCU.FHFLTRKC[u8i].R = (uint32)pVfccuCfg->eMcem_FhidCfg.u32FaultReactionSet[u8i];
            }

            /* Configure immediate and delayed reactions */
            for( u8i = 0U; u8i < EMCEM_REACTION_SET_COUNT; u8i++ )
            {
                /* @violates @ref eMcem_Vfccu_c_REF_1104 */
                /* @violates @ref eMcem_Vfccu_c_REF_1106 */
                AON_VFCCU.FHRKC[u8i].FHIMRKC.R = pVfccuCfg->eMcem_FhidCfg.u32ImmReaction[u8i];

                /* @violates @ref eMcem_Vfccu_c_REF_1104 */
                /* @violates @ref eMcem_Vfccu_c_REF_1106 */
                AON_VFCCU.FHRKC[u8i].FHDLRKC.R = pVfccuCfg->eMcem_FhidCfg.u32DelReaction[u8i];
            }
        }
    }

    /* Check if configuration of the global VFCCU parameters is enabled */
    if( ( (boolean)TRUE == pVfccuCfg->bConfigEnabled ) && ( EMCEM_E_OK == nReturnValue ) )
    {
        /* Configure Global Debug */
        /* @violates @ref eMcem_Vfccu_c_REF_1003 */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON_VFCCU.GDBGCFG.B.FRZ = (pVfccuCfg->bDebugEnabled == TRUE) ? 1U : 0U;
    }

    /* Check if configuration of the VFCCU FHID parameters is enabled */
    if( ((boolean)TRUE == pVfccuCfg->eMcem_FhidCfg.bWriteAccessEnabled ) && ( EMCEM_E_OK == nReturnValue) )
    {
        /* Enable/disable FHID */
        /* @violates @ref eMcem_Vfccu_c_REF_1003 */
        /* @violates @ref eMcem_Vfccu_c_REF_1104 */
        /* @violates @ref eMcem_Vfccu_c_REF_1106 */
        AON_VFCCU.FHCFG0.B.FHIDEN = (pVfccuCfg->eMcem_FhidCfg.bEnabled == TRUE) ? 1U : 0U;
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
    boolean bReturnValue = (boolean)FALSE;

    if( NULL_PTR != eMcem_pConfigPtr->eMcem_CVfccuCfg )
    {
        /* Check if write access to FH is enabled */
        if( (boolean)TRUE == eMcem_pConfigPtr->eMcem_CVfccuCfg->eMcem_FhidCfg.bWriteAccessEnabled )
        {
            bReturnValue = (boolean)TRUE;
        }
        else
        {
            /* Log extended diagnostic data */
            EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ACCESS_TO_CVFCCU_FHID_1, 0U )
        }
    }
    else
    {
        /* Log extended diagnostic data */
        EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ACCESS_TO_CVFCCU_FHID_2, 0U )
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
    boolean bReturnValue = (boolean)FALSE;
    uint8 u8RegIdx = (uint8)( nFaultId / EMCEM_REG_SIZE );
    uint8 u8BitPosition = (uint8)( nFaultId % EMCEM_REG_SIZE );

    if( 0UL != ( AON_VFCCU.GFLTRC[u8RegIdx].R & ( u32RegVal << u8BitPosition ) ) )
    {
        bReturnValue = (boolean)TRUE;
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
    boolean bReturnValue = (boolean)FALSE;

    if( eMcem_pConfigPtr->eMcem_CVfccuCfg != NULL_PTR )
    {
        /* Check if write access to FH is enabled */
        if( (boolean)TRUE == eMcem_pConfigPtr->eMcem_CVfccuCfg->bConfigEnabled )
        {
            bReturnValue = (boolean)TRUE;
        }
        else
        {
            /* Log extended diagnostic data */
            EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ACCESS_TO_CVFCCU_1, 0U )
        }
    }
    else
    {
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

    if( (boolean)TRUE == bClearFault )
    {
        /* Check if any fault was detected in fault handler */
        if( 0UL < AON_VFCCU.FHSRVDS0.B.AGGFLTS )
        {
            AON_VFCCU.FHFLTS[u8RegIdx].R |= ( u32RegVal << u8BitIdx );
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
    if( 0UL != ( AON_VFCCU.FHFLTS[u8RegIdx].R & ( u32RegVal << u8BitIdx ) ) )
    {
        nReturnValue = EMCEM_E_NOT_OK;
    }
    else
    {
        /* report EMCEM_E_OK, which is set as default - do nothing */
    }

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_VFCCU_CLEAR_CVFCCU_FAULTS, 0U )
    EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( nReturnValue, (uint32)nFaultId )

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
    EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( nReturnValue, (uint32)nFaultId)

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
    if( 0UL < AON_VFCCU.FHSRVDS0.B.AGGFLTS )
    {
        /* Go through fault status registers of CVFCCU */
        for( u8RegIdx = 0U; u8RegIdx < EMCEM_VFCCU_ERROR_CONTAINER_SIZE; u8RegIdx++ )
        {
            /* Read fault status register and OR it with current values in the fault container.
               Values for all Fault containers are ORed together */
            pFaultContainer[u8RegIdx] |= AON_VFCCU.FHFLTS[u8RegIdx].R;

            /* Accumulate all faults */
            *pFaultAccumulator |= pFaultContainer[u8RegIdx];
        }
    }
}

/**
* @brief      Assert software VFCCU fault.
* @details    Sets reaction line for software fault.
*
* @param[in]  u8SwFaultId      ID of the SW fault that shall be asserted.
*
* @return     void
*
*/
void eMcem_Vfccu_AssertSWFault( uint8 u8SwFaultId )
{
    /* Get SW fault register and bit position in SW fault register */
    uint8 u8BitIdx = u8SwFaultId % EMCEM_VFCCU_SW_FAULT_COUNT;
    uint8 u8SWRegIdx = u8SwFaultId / EMCEM_VFCCU_SW_FAULT_COUNT;

    eMcem_Vfccu_Specific_AssertSWFault( u8SWRegIdx, u8BitIdx );
}

/**
* @brief      Deassert software VFCCU fault.
* @details    Clears the software fault on the corresponding reaction line.
*
* @param[in]  u8SwFaultId      ID of the SW fault that shall be deasserted.
*
* @return     void
*
*/
void eMcem_Vfccu_DeassertSWFault( uint8 u8SwFaultId )
{
    /* Get SW fault register and bit position in SW fault register */
    uint8 u8BitIdx = u8SwFaultId % EMCEM_VFCCU_SW_FAULT_COUNT;
    uint8 u8SWRegIdx = u8SwFaultId / EMCEM_VFCCU_SW_FAULT_COUNT;

    eMcem_Vfccu_Specific_DeassertSWFault( u8SWRegIdx, u8BitIdx );
}

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_Vfccu_c_REF_0410 */
/* @violates @ref eMcem_Vfccu_c_REF_2001 */
#include "eMcem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
