/**
*   @file    eMcem_cVfccu_Irq.c
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - VFCCU ISRs implementation
*   @details This file implements interrupt handlers for the VFCCU IP of the eMcem module.
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
*   Copyright 2023-2025 NXP
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
#include "MIMX9XX_SAF_Version.h"
#include "eMcem.h"
#if( STD_ON == EMCEM_TEST_API_AVAILABLE )
#include "eMcem_TestApi.h"
#endif
#include "SafetyBase.h"
#include "eMcem_Vfccu.h"
#include "eMcem_ExtDiagApi.h"
#if( STD_ON == EMCEM_FAULT_STATISTICS_ENABLED )
  #include "mSel.h"
  #include "mSel_InternalApi.h"
#endif
#include "Reg_eSys_Vfccu_MIMX9.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define eMcem_cVfccu_Irq_SW_MAJOR_VERSION_C               0
#define eMcem_cVfccu_Irq_SW_MINOR_VERSION_C               8
#define eMcem_cVfccu_Irq_SW_PATCH_VERSION_C               4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same software version */
#if ((eMcem_cVfccu_Irq_SW_MAJOR_VERSION_C != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (eMcem_cVfccu_Irq_SW_MINOR_VERSION_C != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (eMcem_cVfccu_Irq_SW_PATCH_VERSION_C != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_cVfccu_Irq.c and MIMX9XX_SAF version are different"
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

#if( STD_ON == EMCEM_TEST_API_AVAILABLE )
static boolean eMcem_CallTestHandler( uint8 u8FaultID);
#endif
static uint8 eMcem_Vfccu_GetMaxBitPosition( uint8 u8RegIdx );
static Std_ReturnType eMcem_Vfccu_ProcessFhid( uint8 u8VfccuIdx );
static Std_ReturnType eMcem_Vfccu_ProcessFhidFault( eMcem_FaultType nFaultId, uint8 u8VfccuIdx );
static eMcem_ErrRecoveryType eMcem_CallAlarmHandler( eMcem_FaultType nFaultId, uint8 u8VfccuIdx );
Std_ReturnType eMcem_Vfccu_ProcessFaults( uint8 u8VfccuIdx );

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if( STD_ON == EMCEM_TEST_API_AVAILABLE )
/**
* @brief      Call test handler
* @details    Calls test handler (if applicable). If the test handler is not set or returned
*             EMCEM_ERR_NOT_RECOVERED, returns FALSE, which leads to calling of user alarm handler.
*
* @return     boolean
*                   TRUE   Test handler processed properly
*                   FALSE  Test handler failed/not set
*
*/
static boolean eMcem_CallTestHandler( uint8 u8FaultID)
{
    boolean bReturnValue = (boolean)TRUE;

    /* Check if test handler is set */
    if( (u8FaultID < EMCEM_VFCCU_FAULT_LINES_COUNT) && (NULL_PTR != eMcem_TestHandlers[u8FaultID]) )
    {
        /* Test handler is set. Call handler and check if error has been recovered */
        if( EMCEM_ERR_NOT_RECOVERED == eMcem_TestHandlers[u8FaultID]( u8FaultID ) )
        {
            /* Test handler failed. Call user alarm handler */
            bReturnValue = (boolean)FALSE;
        }
    }
    /* Test handler is not set */
    else
    {
        /* Call user alarm handler */
        bReturnValue = (boolean)FALSE;
    }

    return bReturnValue;
}
#endif

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
#if(STD_ON == EMCEM_FAULT_STATISTICS_ENABLED)
    uint32 u32Cnt;
    uint32 u32EccUncorrectableAddress;
#endif

    /* Get local fault ID (within VFCCU) */
    u8LocalFaultId = (uint8)( nFaultId - EMCEM_VFCCU_FAULT_LINE_OFFSET );

    if( EMCEM_C_VFCCU_IDX == u8VfccuIdx )
    {
#if( STD_ON == EMCEM_TEST_API_AVAILABLE )
        /* Call test handler. If the test handler is not set or returned EMCEM_ERR_NOT_RECOVERED, call user alarm handler */
        if( (boolean)FALSE == eMcem_CallTestHandler( u8LocalFaultId) )
        {
#endif

#if(STD_ON == EMCEM_FAULT_STATISTICS_ENABLED)
            /* Process only those faults related to ECC memory uncorrectable error */
            for ( u32Cnt = 0; u32Cnt < MSEL_ECC_FAULTS_NUM; u32Cnt++ )
            {
                /* Check if currently pending VFCCU fault is ECC memory uncorrectable error */
                if( nFaultId == (eMcem_FaultType)mSel_au32SramEccErrorIndexes[u32Cnt] )
                {
                    /* Get ECC uncorrectable memory address for given fault Id from corresponding reporting channel */
                    u32EccUncorrectableAddress = mSel_GetEccUncorrectableAddress( nFaultId );

                    /* Preserve ECC uncorrectable memory address since content of related diagnostic IP can't survive functional reset. */
                    mSel_StoreEccUncorrectableAddress( u32EccUncorrectableAddress );
                }
            }

            /* Provide fault ID to the mSel module for its statistics */
            mSel_AddFaultIntoStatisticalBuffer( nFaultId );

#if(STD_ON == EMCEM_FAULT_NVM_BACKUP_ENABLED )
            /* Preserve mSel fault data in NVM to survive functional reset */
            (void)mSel_ShutDown();
#endif /* EMCEM_FAULT_NVM_BACKUP_ENABLED  */
#endif /* EMCEM_FAULT_STATISTICS_ENABLED */

            /* SysMan will have CVFCCU config */
            if( (u8LocalFaultId < EMCEM_CVFCCU_MAX_FAULTS) && (NULL_PTR != eMcem_pConfigPtr->eMcem_CVfccuCfg->eMcem_FhidCfg.eMcem_AlarmHandler[u8LocalFaultId]) )
            {
                nReturnValue = eMcem_pConfigPtr->eMcem_CVfccuCfg->eMcem_FhidCfg.eMcem_AlarmHandler[u8LocalFaultId]( nFaultId );

                if( EMCEM_ERR_RECOVERED == nReturnValue )
                {
                    /* Clear Faults
                     * Return value is not used on purpose */
                    (void)eMcem_Vfccu_ClearFaults( nFaultId );
                }
            }
            else
            {
                /* Log extended diagnostic data */
                EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_ERR_NOT_RECOVERED, EMCEM_FP_VFCCU_ALARM_ISR_HANDLER_PTR, 0U )

                /* Call User Handler for not recovered Severity 1 fault */
                eMcem_FailedSvr1FaultHandler( nFaultId );

                /* Wait for escalation to Severity 3 */
                while((boolean)TRUE) {};
            }
#if( STD_ON == EMCEM_TEST_API_AVAILABLE )
        }
        else
        {
            nReturnValue = EMCEM_ERR_RECOVERED;
        }
#endif
    }

    return nReturnValue;
}

/**
* @brief      Check Max Bit position for given VFCCU and Register ID
* @details    Function checks if given VFCCU and Register ID have all bit mapped to fault, or if some are reserved
*
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

    /* Get faults line count by getting all faults  */
    u16NumberOfFaults = EMCEM_CVFCCU_MAX_FAULTS;

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
    Std_ReturnType nReturnValue = EMCEM_E_OK;
    uint8 u8BitPosition;
    uint8 u8RegIdx;
    uint8 u8BitPositionMax;
    uint32 u32IEMask;
    uint32 u32FaultRegStatus;
    eMcem_FaultType nFaultId;
    uint32 u32FaultEnableReg;
    uint32 u32BitPosition3b;
    uint32 u32ReactionSet3b;
    boolean irqReactionSet = (boolean)FALSE;

    for( u8RegIdx = 0U; u8RegIdx < EMCEM_VFCCU_FAULT_STATUS_REG_COUNT; u8RegIdx++ )
    {
        u32FaultRegStatus = AON_VFCCU.FHFLTS[u8RegIdx].R;
        u32FaultEnableReg = AON_VFCCU.FHFLTENC[u8RegIdx].R;

        /* get max bits to check (like masking out reserved bits) */
        u8BitPositionMax = eMcem_Vfccu_GetMaxBitPosition( u8RegIdx );

        for( u8BitPosition = 0U; (u8BitPosition < u8BitPositionMax) && (u32FaultRegStatus > 0UL); u8BitPosition++ )
        {
            /* Get IE bit position mask */
            u32IEMask = (uint32)(1UL << u8BitPosition);

            /* Check if specific Fault Status flag is set */
            if( 0UL < ( u32FaultRegStatus & u32IEMask & u32FaultEnableReg) )
            {
                /* Calculate local nFaultId */
                nFaultId = (uint16)(( (uint16)u8RegIdx * (uint16)EMCEM_VFCCU_REG_SIZE_U8 ) + (uint16)u8BitPosition);

                /* Calculate global nFaultId */
                nFaultId += EMCEM_VFCCU_FAULT_LINE_OFFSET;

                /* Get the reaction set ID for this fault line */
                u32BitPosition3b = ((uint32)nFaultId % FCCU_REACTION_SETS_PER_REG) * FCCU_SHIFT_REACTION_SET_IN_REG;
                u32ReactionSet3b = (SAFETYBASE_REG_READ32( FCCU_FHFLTRKC0_ADDR32( (uint32)nFaultId >> FCCU_REG_SHIFT_U3 ) ) ) & ( FCCU_REG_MASK_U3 << u32BitPosition3b );
                u32ReactionSet3b = u32ReactionSet3b >> u32BitPosition3b;

                /* Check if IRQ immediate or delayed reaction is enabled for this particular fault */
                TODO_MESSAGE("nxf85804-11122024: Check whether Delayed Interrupt reaction condition is safe.")
                if ( ( 0UL < (SAFETYBASE_REG_READ32( FCCU_FHIMRKC0_ADDR32( u32ReactionSet3b )) & FCCU_IRQ0_3_REACT_MASK) ) ||
                     ( 0UL < (SAFETYBASE_REG_READ32( FCCU_FHDLRKC0_ADDR32( u32ReactionSet3b )) & FCCU_IRQ0_3_REACT_MASK) ) )
                {
                    nReturnValue |= eMcem_Vfccu_ProcessFhidFault( nFaultId, u8VfccuIdx );
                    irqReactionSet = (boolean)TRUE;
                }
            }
        }
    }

    /* Was immediate IRQ reaction enabled for at least one regular VFCCU fault? */
    if (irqReactionSet == (boolean)FALSE)
    {
        /* Call spurious IRQ handler */
        sBase_SpuriousIRQHandler();

        /* Log extended diagnostic data */
        EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ALARM_ISR_IRQ_REACT, 0U )
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
* @retval     EMCEM_E_OK      Fault was successfully cleared and resolved/NMI triggered because of fault
* @retval     EMCEM_E_NOT_OK  Fault was not successfully cleared and resolved/NMI was not triggered because of fault
*
*/
static Std_ReturnType eMcem_Vfccu_ProcessFhidFault( eMcem_FaultType nFaultId, uint8 u8VfccuIdx )
{
    Std_ReturnType nReturnValue = EMCEM_E_NOT_OK;
    eMcem_ErrRecoveryType nReturnAlarmHandlerValue = EMCEM_ERR_NOT_RECOVERED;

    nReturnAlarmHandlerValue = eMcem_CallAlarmHandler( nFaultId, u8VfccuIdx );

    if( EMCEM_ERR_RECOVERED == nReturnAlarmHandlerValue )
    {
        nReturnValue = EMCEM_E_OK;
    }
    else if( EMCEM_ERR_MASK_VFCCU_ISR == nReturnAlarmHandlerValue )
    {
        /* Disable VFCCU IRQ */
        sBase_DisableFccuIRQ();
    }
    else
    {
        /* Call User Handler for not recovered Severity 1 fault */
        eMcem_FailedSvr1FaultHandler( nFaultId );

        /* Wait for escalation to Severity 3 */
        while((boolean)TRUE) {};
    }

    return nReturnValue;
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
    if( 1U == AON_VFCCU.GINTOVFS.B.FLTSERV )
    {
        /* Returns EMCEM_E_OK for that specific FHID when clean. */
        nReturnValue = eMcem_Vfccu_ProcessFhid( u8VfccuIdx );
    }
    else
    {
        /* Call spurious IRQ handler */
        sBase_SpuriousIRQHandler();

        /* Log extended diagnostic data */
        EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ALARM_ISR_REG_FAULT, 0U )
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
    /* Clear extended diagnostic data */
    EMCEM_DIAG_CLEAR_DATA()

    /* Check if driver was initialized */
    if( EMCEM_S_UNINIT != eMcem_DriverState )
    {
        if( (uint32)EMCEM_VFCCU_FSM_IDLE != AON_VFCCU.GINTOVFS.B.FSMSTATE )
        {
            (void) eMcem_Vfccu_ProcessFaults( EMCEM_C_VFCCU_IDX );
        }
        else
        {
            /* Call spurious IRQ handler */
            sBase_SpuriousIRQHandler();

            /* Log extended diagnostic data */
            EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ALARM_ISR_VFCCU_STATE, 0U )
        }
    }
    else
    {
        /* Log extended diagnostic data */
        EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_VFCCU_ALARM_ISR_DRV_STATE, 0U )
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
