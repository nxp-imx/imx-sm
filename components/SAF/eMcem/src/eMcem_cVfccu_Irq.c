/**
*   @file    eMcem_cVfccu_Irq.c
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - VFCCU ISRs implementation
*   @details This file implements interrupt handlers for the VFCCU IP of the eMcem module.
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
*   Copyright 2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_cVfccu_Irq_c_REF_0103
* Violates MISRA 2012 Required Rule 1.3, There shall be no occurrence of undefined behavior.
* This is not an undefined behavior.
*
* @section eMcem_cVfccu_Irq_c_REF_0407
* Violates MISRA 2012 Required Rule 4.7, If a function returns error information, then that error information shall be tested.
* This information is not relevant here.
*
* @section eMcem_cVfccu_Irq_c_REF_0410
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.

* @section eMcem_cVfccu_Irq_c_REF_0807
* Violates MISRA 2012 Advisory Rule 8.7, Functions should not be defined with external linkage.
* This is an API-like handler which shall be accessible externally.
*
* @section eMcem_cVfccu_Irq_c_REF_1008
* Violates MISRA 2012 Required Rule 10.8, A value of a composite expression shall not be cast to a different
* essential type category or a wider essential type.
* Unavoidable when addressing memory mapped registers.
*
* @section eMcem_cVfccu_Irq_c_REF_1104
* Violates MISRA 2012 Advisory Rule 11.4, A conversions should not be performed between a pointer to
* object and an integer type.
* Unavoidable when addressing memory mapped registers
*
* @section eMcem_cVfccu_Irq_c_REF_1106
* Violates MISRA 2012 Required Rule 11.6, A cast shall not be performed between pointer to void
* and an arithmetic type.
* Unavoidable when addressing memory mapped registers.
*
* @section eMcem_cVfccu_Irq_c_REF_1707
* Violates MISRA 2012 Required Rule 17.7, The value returned by a function having non-void return type shall be used.
* This information is not relevant here.
*
* @section eMcem_cVfccu_Irq_c_REF_2001
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
#include "eMcem.h"
#include "SafetyBase.h"
#include "eMcem_Vfccu.h"
#include "eMcem_ExtDiagApi.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define eMcem_cVfccu_Irq_SW_MAJOR_VERSION_C               0
#define eMcem_cVfccu_Irq_SW_MINOR_VERSION_C               4
#define eMcem_cVfccu_Irq_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((eMcem_cVfccu_Irq_SW_MAJOR_VERSION_C != MIMX_SAF_SW_MAJOR_VERSION) || \
     (eMcem_cVfccu_Irq_SW_MINOR_VERSION_C != MIMX_SAF_SW_MINOR_VERSION) || \
     (eMcem_cVfccu_Irq_SW_PATCH_VERSION_C != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_cVfccu_Irq.c and MIMX_SAF version are different"
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
/* @violates @ref eMcem_cVfccu_Irq_c_REF_0410 */
/* @violates @ref eMcem_cVfccu_Irq_c_REF_2001 */
#include "eMcem_MemMap.h"

static void eMcem_Vfccu_ClearCvfccuFhidFault( eMcem_FaultType nFaultId );
static uint8 eMcem_Vfccu_GetMaxBitPosition( uint8 u8RegIdx );
static Std_ReturnType eMcem_Vfccu_ProcessFhid( uint8 u8VfccuIdx );
static Std_ReturnType eMcem_Vfccu_ProcessFhidFault( eMcem_FaultType nFaultId, uint8 u8VfccuIdx );
static eMcem_ErrRecoveryType eMcem_CallAlarmHandler( eMcem_FaultType nFaultId, uint8 u8VfccuIdx );
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Call alarm handler
* @details    Checks if driver is initialized and if Alarm Interrupt for specific fault is enabled.
*             If these checks pass, calls test handler (if applicable) and/or user alarm handler.
*
* @param[in]  nFaultId         VFCCU fault ID
* @param[in]  u8VfccuIdx       VFCCU Index (should be always 0 in case of i.MX95)
*
* @return     eMcem_ErrRecoveryType
* @retval     EMCEM_ERR_RECOVERED - FCCU error has been recovered
* @retval     EMCEM_ERR_NOT_RECOVERED - FCCU error has not been recovered
*
*/
static eMcem_ErrRecoveryType eMcem_CallAlarmHandler( eMcem_FaultType nFaultId, uint8 u8VfccuIdx)
{
    eMcem_ErrRecoveryType nReturnValue = EMCEM_ERR_NOT_RECOVERED;
    uint8 u8LocalFaultId;

    /* Get local fault ID (within VFCCU) */
    u8LocalFaultId = (uint8)( nFaultId - EMCEM_VFCCU_FAULT_LINE_OFFSET );

    if( EMCEM_C_VFCCU_IDX == u8VfccuIdx )
    {
        /* SysMan will have CVFCCU config */
        if( NULL_PTR != eMcem_pConfigPtr->eMcem_CVfccuCfg )
        {
            nReturnValue = eMcem_pConfigPtr->eMcem_CVfccuCfg->eMcem_FhidCfg.eMcem_AlarmHandler[u8LocalFaultId]( nFaultId );
        }
    }
    else /* the code should not be reached here, because of u8VfccuIdx=0 */
    {
        /* Log extended diagnostic data */
        EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_CALL_ALARM_HANDLER, 0U )
        EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( EMCEM_E_NOT_OK, (uint32)nFaultId )

    }

    return nReturnValue;
}

/**
* @brief      Check Max Bit position for given VFCCU and Register ID
* @details    Function checks if given VFCCU and Register ID have all bit mapped to fault, or if some are reserved
*
* @param[in]  u8VfccuIdx       The ID of the VFCCU to get Max Bit position (should be always 0 in case of i.MX95)
* @param[in]  u8RegIdx         Register ID of VFCCU for which to check Max Bit position
*
* @return     Max Bit position
*
*/
static uint8 eMcem_Vfccu_GetMaxBitPosition( uint8 u8RegIdx )
{
    /* Set Default value to be all the bits */
    uint8 u8ReturnValue = EMCEM_VFCCU_REG_SIZE_U8;
    uint16 u16NumberOfFaults;

    /* Get faults line count by getting SW faults offset minus faults line offset */
    u16NumberOfFaults = EMCEM_VFCCU_SW_FAULT_LINE_OFFSET - EMCEM_VFCCU_FAULT_LINE_OFFSET;

    /* Check if we hit u8RegIdx, if yes, it means register is not full -> supply remainder as max bit position.
     * u8RegIdx will always give us number of register for faults given. Edge cases:
     *  - 31 faults, u8RegIdx supplied = 0, 31/32 = 0, true, supply remainder of 31
     *  - 32 faults, u8RegIdx supplied = 0, 32/32 = 1, not true, return EMCEM_VFCCU_REG_SIZE_U8
     *  - 33 faults, u8RegIdx supplied = 1, 33/32 = 1, true, supply remainder of 1 */
    if( u8RegIdx == (uint8)( u16NumberOfFaults / 32U ) )
    {
        u8ReturnValue = (uint8)( u16NumberOfFaults % 32U );
    }

    return u8ReturnValue;

}

/**
* @brief      Process FHID of VFCCU
* @details    Function processes FHID of specific VFCCU and finds Fault/Faults if present
*
* @param[in]  u8VfccuIdx            The ID of the VFCCU to process its FHID (should be always 0 in case of i.MX95)
*
* @return     Std_ReturnType
* @retval     EMCEM_E_OK      All faults successfully resolved and cleared/NMI triggered by fault
* @retval     EMCEM_E_NOT_OK  All faults were not successfully resolved and cleared/NMI not triggered by fault
*
*/
static Std_ReturnType eMcem_Vfccu_ProcessFhid( uint8 u8VfccuIdx )
{
    Std_ReturnType nReturnValue = EMCEM_E_NOT_OK;
    uint8 u8BitPosition;
    uint8 u8RegIdx;
    uint8 u8BitPositionMax;
    uint32 u32IEMask;
    uint32 u32FaultRegStatus;
    eMcem_FaultType nFaultId;
    uint32 u32FaultEnableReg;

    for( u8RegIdx = 0U; u8RegIdx < EMCEM_VFCCU_FAULT_STATUS_REG_COUNT; u8RegIdx++ )
    {
        if (u8RegIdx == 0)
        {
                u32FaultRegStatus = AON__FCCU.FHFLTS0_0.R;
                u32FaultEnableReg = AON__FCCU.FHFLTENC0_0.R;
        }
        else if (u8RegIdx == 1)
        {
                u32FaultRegStatus = AON__FCCU.FHFLTS0_1.R;
                u32FaultEnableReg = AON__FCCU.FHFLTENC0_1.R;
        }
        else if (u8RegIdx == 2)
        {
                u32FaultRegStatus = AON__FCCU.FHFLTS0_2.R;
                u32FaultEnableReg = AON__FCCU.FHFLTENC0_2.R;
        }

        /* get max bits to check (like masking out reserved bits) */
        u8BitPositionMax = eMcem_Vfccu_GetMaxBitPosition( u8RegIdx );

        if( u32FaultRegStatus > 0UL )
        {
            for( u8BitPosition = 0U; ( u8BitPosition < u8BitPositionMax ); u8BitPosition++ )
            {
                /* Get IE bit position mask */
                u32IEMask = (uint32)(1UL << u8BitPosition);

                /* Check if specific Fault Status flag is set */
                if( 0UL < ( u32FaultRegStatus & u32IEMask & u32FaultEnableReg) )
                {
                    /* Calculate local nFaultId */
                    nFaultId = ( ( u8RegIdx ) * (uint8)EMCEM_VFCCU_REG_SIZE_U8 ) + u8BitPosition;

                    /* Calculate global nFaultId */
                    nFaultId += EMCEM_VFCCU_FAULT_LINE_OFFSET;

		            nReturnValue |= eMcem_Vfccu_ProcessFhidFault( nFaultId, u8VfccuIdx );
                }
            }
        }
    }

    return nReturnValue;
}

/**
* @brief      Process specific Fault in FHID
* @details    This function handles specific fault in FHID either for CVFCCU. It calls AlarmHandler
*             and also clears the fault if error is recovered. At the end we store last recovered fault.
*
* @param[in]  nFaultId              VFCCU fault ID
* @param[in]  u8VfccuIdx            VFCCU Index
*
* @return     Std_ReturnType
* @retval     EMCEM_E_OK      Fault was successfully cleared and resolved/NMI triggered beacuse of fault
* @retval     EMCEM_E_NOT_OK  Fault was not successfully cleared and resolved/NMI was not triggered beacuse of fault
*
*/
static Std_ReturnType eMcem_Vfccu_ProcessFhidFault( eMcem_FaultType nFaultId, uint8 u8VfccuIdx )
{
    Std_ReturnType nReturnValue = EMCEM_E_NOT_OK;

    {
        if( EMCEM_ERR_RECOVERED == eMcem_CallAlarmHandler( nFaultId, u8VfccuIdx ) )
        {
            /* Clear Faults */
            nReturnValue = eMcem_Vfccu_ClearFaults( nFaultId );

#if( STD_ON == EMCEM_FAULT_STATISTICS_ENABLED )
            /* Provide fault ID to the mSel module for its statistics */
            mSel_AddFaultIntoStatisticalBuffer( nFaultId );
#endif
            /* Should go here only for CVFCCU. This will handle any CVFCCU fault not cleared by EENV */
            if( ( EMCEM_E_NOT_OK == nReturnValue ) && ( EMCEM_C_VFCCU_IDX == u8VfccuIdx ) )
            {
                /* No need to move fault to local Fault ID since only do this for CVFCCU */
                eMcem_Vfccu_ClearCvfccuFhidFault( nFaultId );
            }
        }
    }

    return nReturnValue;
}

/**
* @brief      Clear specific Fault in specific CVFCCU FHID
* @details    This function can clear one Fault in specific FHID
*
* @param[in]  nFaultId         VFCCU fault ID
*
* @return     void
*
*/
static void eMcem_Vfccu_ClearCvfccuFhidFault( eMcem_FaultType nFaultId )
{
    const uint8 u8RegIdx = (uint8)(nFaultId / EMCEM_REG_SIZE);
    const uint8 u8BitIdx = (uint8)(nFaultId % EMCEM_REG_SIZE);

    /* Check if write access to FH is enabled */
    if( EMCEM_TRUE == eMcem_pConfigPtr->eMcem_CVfccuCfg->eMcem_FhidCfg.bWriteAccessEnabled )
    {
        if (u8RegIdx == 0)
        {
            AON__FCCU.FHFLTS0_0.R |= ( 1U << u8BitIdx );
        }
        else if (u8RegIdx == 1)
        {
            AON__FCCU.FHFLTS0_1.R |= ( 1U << u8BitIdx );
        }
        else if (u8RegIdx == 2)
        {
            AON__FCCU.FHFLTS0_2.R |= ( 1U << u8BitIdx );
        }
    }
    	/* No need to call MRU since this should be called only in SysMan which has access to CVFCCU */
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Processing VFCCU Faults
* @details    Function processes faults upon receiving VFCCU interrupt call
*
* @param[in]  u8VfccuIdx       The ID of the VFCCU to process Fault
*                               - function is recursive, but entry is always CVFCCU
*                               - recursion is in this case allowed as benefits outweigh the drawbacks
*
* @return     Std_ReturnType
* @retval     E_OK        NMI has originated in FCCU
* @retval     E_NOT_OK    NMI has not originated in FCCU
*
*/
Std_ReturnType eMcem_Vfccu_ProcessFaults( uint8 u8VfccuIdx )
{
    Std_ReturnType nReturnValue = EMCEM_E_NOT_OK;

    /* Check for regular Fault */
    if( 1U == AON__FCCU.GINTOVFS.B.FLTSERV )
    {
        /* Returns EMCEM_E_OK for that specific FHID when clean. */
        nReturnValue = eMcem_Vfccu_ProcessFhid( u8VfccuIdx );
    }

    return nReturnValue;
}

/**
* @brief      VFCCU Alarm Interrupt routine.
* @details    An ALARM Interrupt is generated when a properly configured fault generates a transition
*             to the ALARM state. The status (fault triggering interrupt) can be obtained
*             through frozen status registers.
*
* @implements DD_eMcem_VFCCU_ALARM_ISR
*
* @violates @ref eMcem_cVfccu_Irq_c_REF_0807
*
*/
void VFCCU_ALARM_ISR( void )
{
    /* Check if driver was initialized */
    if( EMCEM_S_UNINIT != eMcem_DriverState )
    {
        if( EMCEM_VFCCU_FSM_IDLE != AON__FCCU.GINTOVFS.B.FSMSTATE )
        {
            (void) eMcem_Vfccu_ProcessFaults( EMCEM_C_VFCCU_IDX );
        }
        else
        {
            /* Log extended diagnostic data */
            EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ALARM_ISR_1, 0U )
        }
    }
    else
    {
        /* Log extended diagnostic data */
        EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ALARM_ISR_2, 0U )
    }

}

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_cVfccu_Irq_c_REF_0410 */
/* @violates @ref eMcem_cVfccu_Irq_c_REF_2001 */
#include "eMcem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
