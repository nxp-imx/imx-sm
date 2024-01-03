/**
*   @file    eMcem_Lib_MIMX95XX.c
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - IP wrapper specific source.
*   @details This file implements eMcem IP wrapper specific functions.
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
* @section eMcem_Lib_MIMX95XX_c_REF_0103
* Violates MISRA 2012 Required Rule 1.3, Taking address of near auto variable is safe operation
* on the target platform.
*
* @section eMcem_Lib_MIMX95XX_c_REF_0410
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_Lib_MIMX95XX_c_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Lib_MIMX95XX_c_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Lib_MIMX95XX_c_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Lib_MIMX95XX_c_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Lib_MIMX95XX_c_REF_1104
* Violates MISRA 2012 Advisory Rule 11.4, A conversions should not be performed between a pointer to
* object and an integer type.
* Unavoidable when addressing memory mapped registers
*
* @section eMcem_Lib_MIMX95XX_c_REF_1106
* Violates MISRA 2012 Required Rule 11.6, A cast shall not be performed between pointer to void
* and an arithmetic type.
* Unavoidable when addressing memory mapped registers.
*
* @section eMcem_Lib_MIMX95XX_c_REF_2001
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
#include "SafetyBase.h"
#include "SafetyBase_StdRegMacros.h"
#include "eMcem_Cfg.h"
#include "eMcem_Vfccu.h"
#include "eMcem_Lib_Ext.h"
#include "eMcem_ExtDiagApi.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0501 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0502 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0504 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0505 */
#define EMCEM_LIB_MIMX95XX_SW_MAJOR_VERSION_C               0
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0501 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0502 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0504 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0505 */
#define EMCEM_LIB_MIMX95XX_SW_MINOR_VERSION_C               4
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0501 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0502 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0504 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0505 */
#define EMCEM_LIB_MIMX95XX_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_LIB_MIMX95XX_SW_MAJOR_VERSION_C != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_LIB_MIMX95XX_SW_MINOR_VERSION_C != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_LIB_MIMX95XX_SW_PATCH_VERSION_C != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Lib_MIMX95XX.c and MIMX_SAF version are different"
#endif

#if defined(SAFETY_BASE_MIMX95XX)
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define EMCEM_START_SEC_CONST_UNSPECIFIED
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0410 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_2001 */
#include "eMcem_MemMap.h"

#define EMCEM_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0410 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_2001 */
#include "eMcem_MemMap.h"

#define EMCEM_START_SEC_CONST_8
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0410 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_2001 */
#include "eMcem_MemMap.h"

#define EMCEM_STOP_SEC_CONST_8
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0410 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_2001 */
#include "eMcem_MemMap.h"


#define EMCEM_START_SEC_CONST_16
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0410 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_2001 */
#include "eMcem_MemMap.h"

#define EMCEM_STOP_SEC_CONST_16
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0410 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_2001 */
#include "eMcem_MemMap.h"

#define EMCEM_START_SEC_CONST_32
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0410 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_2001 */
#include "eMcem_MemMap.h"

#define EMCEM_STOP_SEC_CONST_32
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_0410 */
/* @violates @ref eMcem_Lib_MIMX95XX_c_REF_2001 */
#include "eMcem_MemMap.h"


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


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Check if fault ID is valid
* @details    Function to check if fault ID is within range and if the fault is enabled
*
* @param[in]  nFaultId     The ID of the fault to be validated
*
* @return     boolean
*                   TRUE    Fault ID is valid (in range and enabled)
*                   FALSE   Fault ID is not valid (out of range or disabled)
*
* @pre        nFaultId is valid
*
*/
boolean eMcem_CheckValidFault_Int( eMcem_FaultType nFaultId )
{
    boolean bReturnValue = (boolean)FALSE;

    /* Check if faultId is in VFCCU range */
    if( EMCEM_FAULT_IN_VFCCU_RANGE( nFaultId ) )
    {
        bReturnValue = (boolean)TRUE;
    }
    else
    {
        /* No action needed */
        /* Log extended diagnostic data */
        EMCEM_DIAG_STORE_FAILURE_POINT( EMCEM_E_NOT_OK, EMCEM_FP_CHECK_FAULT_ID_INT, 0U )
        EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( EMCEM_E_NOT_OK, (uint32)nFaultId )
    }

    return bReturnValue;
}

/**
* @brief      VFCCU init function
* @details    Function initializing VFCCU using IPs config structures.
*
* @param[in,out] pConfigPtr   Pointer to driver configuration structure.
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      Driver has been initialized correctly and checked using readback.
* @retval           EMCEM_E_NOT_OK  Driver has not been initialized correctly, readback failed.
*
*/
Std_ReturnType eMcem_Vfccu_Init_Int( const eMcem_ConfigType *pConfigPtr )
{
    Std_ReturnType nReturnValue = EMCEM_E_NOT_OK;

    /* Init the VFCCUs */
    nReturnValue = eMcem_Vfccu_Init( pConfigPtr );

#if( STD_ON == EMCEM_EXT_DIAG_ENABLED )
    /* Log extended diagnostic data */
    eMcem_StoreFailurePoint( nReturnValue, EMCEM_FP_INIT_INT, 0U );
#endif

    return nReturnValue;
}

/**
* @brief      Init function
* @details    Function initializing IPs using IPs config structures.
*
* @param[in,out] pConfigPtr   Pointer to driver configuration structure.
*
* @return     void
*
*/
void eMcem_Init_Int( const eMcem_ConfigType *pConfigPtr )
{
    (void)pConfigPtr;
    /* Init the ERM */
    /*eMcem_Erm_Init( pConfigPtr );*/

    /* Init the SRAMC */
    /*eMcem_Sramc_Init();*/
}

/**
* @brief      eMcem_AssertSWFault_Int
* @details    Asserts SW fault triggering to FCCU if the faultID is correct (in proper range)
*
* @param[in]  nFaultId   The ID of SW fault to assert
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      SW fault has been asserted successfully.
* @retval           EMCEM_E_NOT_OK  SW fault has not been asserted.
*
*/
Std_ReturnType eMcem_AssertSWFault_Int( eMcem_FaultType nFaultId )
{
    Std_ReturnType nReturnValue = EMCEM_E_NOT_OK;

    /* Check if faultId is in VFCCU SW faults range */
    if( EMCEM_FAULT_IN_SW_FAULT_RANGE( nFaultId ) )
    {
        eMcem_Vfccu_AssertSWFault( (uint8)nFaultId - EMCEM_FCCU_FLT_SWNCF00 );

        nReturnValue = EMCEM_E_OK;
    }

    return nReturnValue;
}

/**
* @brief      eMcem_DeassertSWFault_Int
* @details    Deasserts SW fault triggering to FCCU if the faultID is correct (in proper range)
*
* @param[in]  nFaultId   The ID of SW fault to deassert
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      SW fault has been asserted successfully.
* @retval           EMCEM_E_NOT_OK  SW fault has not been asserted.
*
*/
Std_ReturnType eMcem_DeassertSWFault_Int( eMcem_FaultType nFaultId )
{
    Std_ReturnType nReturnValue = EMCEM_E_NOT_OK;

    /* Check if faultId is in VFCCU SW faults range */
    if( EMCEM_FAULT_IN_SW_FAULT_RANGE( nFaultId ) )
    {
        eMcem_Vfccu_DeassertSWFault( (uint8)nFaultId - EMCEM_FCCU_FLT_SWNCF00 );

        nReturnValue = EMCEM_E_OK;
    }

    return nReturnValue;
}

/**
* @brief      Get errors function
* @details    Function gets logged errors from the VFCCU IP and stores them in the error container
*
* @param[in,out] pErrorContainer  Error container where the errors shall be stored.
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK               No fault is pending.
* @retval           EMCEM_E_FAULT_DETECTED   There is at least one logged fault.
*
*/
Std_ReturnType eMcem_GetErrors_Int( eMcem_FaultContainerType *pErrorContainer )
{
    Std_ReturnType nReturnValue = EMCEM_E_OK;

    /* Initialized temporary flag */
    uint32 eMcem_u32FaultAccumulator = 0UL;
    uint8 u8RegIdx;

    /* Initialize Fault containers to zeros since it is being ORed later on */
    for( u8RegIdx = 0U; u8RegIdx < EMCEM_VFCCU_ERROR_CONTAINER_SIZE; u8RegIdx++ )
    {
        pErrorContainer->au32Faults[u8RegIdx] = 0UL;
    }

    /* Retrieve status of VFCCU faults */
    eMcem_Vfccu_GetErrors( &(pErrorContainer->au32Faults[0]), &eMcem_u32FaultAccumulator );

    /* Retrieve status of VFCCU SW faults */
    eMcem_Vfccu_GetSWFaults( &(pErrorContainer->au32Faults[0]), &eMcem_u32FaultAccumulator, EMCEM_FCCU_FLT_SWNCF00 );

    /* In case error status has been retrieved properly, handle global error flag */
    if( 0UL != eMcem_u32FaultAccumulator )
    {
        /* At least one bit has been set */
        nReturnValue = EMCEM_E_FAULT_DETECTED;
    }

    /* Store the resulting status */
    pErrorContainer->nErrorStatus = nReturnValue;

    return nReturnValue;
}

/**
* @brief      Clear fault function
* @details    The function shall clear the specified fault. The fault can be cleared only if the fault
*             cause is eliminated and the fault is marked as software recoverable.
*
* @param[in]  nFaultId        The ID of the fault that shall be cleared
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      The fault has been successfully cleared
* @retval           EMCEM_E_NOT_OK  The fault has not been successfully cleared. Possible causes:
*                                   - the fault source has not been eliminated
*                                   - the fault occurred again
*
* @pre        nFaultId is valid
*
*/
Std_ReturnType eMcem_ClearFaults_Int( eMcem_FaultType nFaultId )
{
    Std_ReturnType nReturnValue = EMCEM_E_NOT_OK;

    /* Check if faultId is in VFCCU range */
    if( EMCEM_FAULT_IN_VFCCU_RANGE( nFaultId ) )
    {
        nReturnValue = eMcem_Vfccu_ClearFaults( nFaultId );
    }

    return nReturnValue;
}

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_Lib_MIMX95XXXX_c_REF_0410 */
/* @violates @ref eMcem_Lib_MIMX95XXXX_c_REF_2001 */
#include "eMcem_MemMap.h"


#endif /* defined(SAFETY_BASE_MIMX95XX) */

#ifdef __cplusplus
}
#endif

/** @} */
