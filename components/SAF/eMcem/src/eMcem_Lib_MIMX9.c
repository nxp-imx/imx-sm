/**
*   @file    eMcem_Lib_MIMX9.c
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - IP wrapper specific source.
*   @details This file implements eMcem IP wrapper specific functions.
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
*   Copyright 2024-2025 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_Lib_MIMX9_c_REF_0103
* Violates MISRA 2012 Required Rule 1.3, Taking address of near auto variable is safe operation
* on the target platform.
*
* @section eMcem_Lib_MIMX9_c_REF_0410
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_Lib_MIMX9_c_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Lib_MIMX9_c_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Lib_MIMX9_c_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Lib_MIMX9_c_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_Lib_MIMX9_c_REF_1104
* Violates MISRA 2012 Advisory Rule 11.4, A conversions should not be performed between a pointer to
* object and an integer type.
* Unavoidable when addressing memory mapped registers
*
* @section eMcem_Lib_MIMX9_c_REF_1106
* Violates MISRA 2012 Required Rule 11.6, A cast shall not be performed between pointer to void
* and an arithmetic type.
* Unavoidable when addressing memory mapped registers.
*
* @section eMcem_Lib_MIMX9_c_REF_2001
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
#include "SafetyBase.h"
#include "SafetyBase_StdRegMacros.h"
#include "eMcem_Cfg.h"
#include "eMcem_Vfccu.h"
#include "eMcem_Lib_Ext.h"
#include "eMcem_SramcAddrCalc_MIMX9.h"
#include "eMcem_ExtDiagApi.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0501 */
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0502 */
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0504 */
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0505 */
#define EMCEM_LIB_MIMX9_SW_MAJOR_VERSION_C               0
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0501 */
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0502 */
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0504 */
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0505 */
#define EMCEM_LIB_MIMX9_SW_MINOR_VERSION_C               8
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0501 */
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0502 */
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0504 */
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0505 */
#define EMCEM_LIB_MIMX9_SW_PATCH_VERSION_C               4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same software version */
#if ((EMCEM_LIB_MIMX9_SW_MAJOR_VERSION_C != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_LIB_MIMX9_SW_MINOR_VERSION_C != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_LIB_MIMX9_SW_PATCH_VERSION_C != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Lib_MIMX9.c and MIMX9XX_SAF version are different"
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
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0410 */
#include "eMcem_MemMap.h"
static void eMcem_ValidateSramAddr( eMcem_ChannelType nChannelId, eMcem_MemErrInfoType *pInfo );

static Std_ReturnType eMcem_GetErmErrorInfo( eMcem_ChannelType nChannelId, eMcem_MemErrInfoType *pInfo );

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Validate error address
* @details    Function checks if the retrieved error address is within defined boundaries.
*             Copies previously retrieved address from errAddrRaw into errAddrValid field of pInfo if so.
*
* @param[in]  u32StartAddr    Specific SRAM start address
* @param[in]  u32EndAddr      Specific SRAM end address
* @param[in/out] pInfo        Structure with type, raw address data, validated address (if available), and syndrome of the last memory error.
*
* @return     void
*/
static void eMcem_ValidateSramAddr( eMcem_ChannelType nChannelId, eMcem_MemErrInfoType *pInfo )
{
    uint32 u32StartAddr = eMcem_tSramcChannelAddress[nChannelId].u32StartAddr;
    uint32 u32EndAddr = eMcem_tSramcChannelAddress[nChannelId].u32EndAddr;
    /* Validate if the address is within proper range */
    if( ( pInfo->errAddrRaw >= u32StartAddr ) && ( pInfo->errAddrRaw < u32EndAddr ) )
    {
        pInfo->errAddrValid = pInfo->errAddrRaw;
    }
}

/**
* @brief      Get memory error info from ERM (or SRAMC)
* @details    Function retrieves error type, address, and syndrome values for given memory channel.
*
* @param[in]  nChannelId             Global ID of ERM channel
* @param[in]  u32InstanceId          ID of ERM instance to which the channel belongs
* @param[in]  u32InstanceChannelId   Local ID of ERM channel (within the instance)
* @param[in/out] pInfo               Structure with type, raw address data, validated address (if available), and syndrome of the last memory error
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK             Error was not detected for given channel.
* @retval           EMCEM_E_NOT_OK         Error was detected for given channel.
*
*/
static Std_ReturnType eMcem_GetErmErrorInfo( eMcem_ChannelType nChannelId, eMcem_MemErrInfoType *pInfo )
{
    Std_ReturnType nReturnValue = EMCEM_E_OK;
    uint32 u32InstanceId = 0UL;
    uint32 u32InstanceChannelId = 0UL;
    eMcem_ChannelType ermChannelId = (eMcem_ChannelType)( nChannelId - EMCEM_ERM_CHANNELS_OFFSET );

    /* Get instance ID and instance channel ID (ID within instance) */
    /* @violates @ref eMcem_Lib_MIMX9_c_REF_0103 */
    eMcem_Erm_GetInstanceAndChannel( ermChannelId, &u32InstanceId, &u32InstanceChannelId );

    /* Get error type */
    nReturnValue = eMcem_Erm_GetErrType( ermChannelId, u32InstanceId, u32InstanceChannelId, pInfo );

    /* Check if an error was detected */
    if( EMCEM_E_NOT_OK == nReturnValue )
    {
        /* Check if address info is provided and read it if so */
        if( EMCEM_TRUE == eMcem_Erm_IsAddrProvided( ermChannelId ) )
        {
            eMcem_Erm_GetErrAddr( u32InstanceId, u32InstanceChannelId, pInfo );
        }

        /* Check if syndrome info is provided and read it if so */
        if( EMCEM_TRUE == eMcem_Erm_IsSynProvided( ermChannelId ) )
        {
            eMcem_Erm_GetErrSyndrome( u32InstanceId, u32InstanceChannelId, pInfo );
        }
        TODO_MESSAGE("nxf85804-11Mar2024: Check if any ERM channels are related to SRAM validates its retrieved address if so")

        /* ERM or SRAM error was detected and retrieved (from ERM or SRAMC). Clear ERM channel status flag */
        eMcem_Erm_ClrErrType( u32InstanceId, u32InstanceChannelId, pInfo );
    }

    return nReturnValue;
}

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

    /* Check if faultId is in range */
    if( EMCEM_FAULT_IN_RANGE( nFaultId ) )
    {
        bReturnValue = (boolean)TRUE;
    }
    else
    {
        /* No action needed */
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
    eMcem_Erm_Init( pConfigPtr );

    /* Init the SRAMC */
    eMcem_Sramc_Init(pConfigPtr);

    /* Init the DDRC */
    eMcem_Ddrc_Init( pConfigPtr );
}

/**
* @brief      Function to inject fake faults
* @details    Function is used to inject fake faults in order to test the reaction for each fault.
*
* @param[in]  nFaultId     The ID of the fault to be injected
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      Fault has been injected.
* @retval           EMCEM_E_NOT_OK  Fault has not been injected.
*
* @pre        nFaultId is valid
*
*/
Std_ReturnType eMcem_InjectFault_Int( eMcem_FaultType nFaultId )
{
    Std_ReturnType nReturnValue = EMCEM_E_NOT_OK;

    /* Check if faultId is in EIM range */
    if( EMCEM_FAULT_IN_EIM_RANGE( nFaultId ) )
    {
        nReturnValue = eMcem_Eim_InjectFault( nFaultId - (uint16)EMCEM_EIM_CHANNELS_OFFSET );
    }
    /* Check if faultId is in SRAMC range */
    else if( EMCEM_FAULT_IN_SRAMC_RANGE( nFaultId ) )
    {
        nReturnValue = eMcem_Sramc_InjectFault( nFaultId - (uint16)EMCEM_SRAMC_CHANNELS_OFFSET );
    }
    else if( EMCEM_FAULT_IN_DDRC_RANGE( nFaultId ) )
    {
        nReturnValue = eMcem_Ddrc_InjectFault( nFaultId - (uint16)EMCEM_DDRC_CHANNELS_OFFSET );
    }
    else
    {
        /* No action needed */
    }

    return nReturnValue;
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
#if ( SAFETY_BASE_MIMX95XX || SAFETY_BASE_MIMX952X )
        eMcem_Vfccu_AssertSWFault( (uint8)nFaultId - EMCEM_FCCU_FLT_SWNCF00 );
#elif SAFETY_BASE_MIMX943X
        if(nFaultId < EMCEM_FCCU_FLT_SWNCF12 )
        {
            eMcem_Vfccu_AssertSWFault( (uint8)nFaultId - EMCEM_FCCU_FLT_SWNCF00 );
        }
        else
        {
            eMcem_Vfccu_AssertSWFault( (uint8)nFaultId - EMCEM_FCCU_FLT_M33_SYNC_DBG );
        }
#else
#error "Wrong platform defined."
#endif /* SAFETY_BASE_MIMX9XXX */

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
#if ( SAFETY_BASE_MIMX95XX || SAFETY_BASE_MIMX952X )
        eMcem_Vfccu_DeassertSWFault( (uint8)nFaultId - EMCEM_FCCU_FLT_SWNCF00 );
#elif SAFETY_BASE_MIMX943X
        if(nFaultId < EMCEM_FCCU_FLT_SWNCF12 )
        {
            eMcem_Vfccu_DeassertSWFault( (uint8)nFaultId - EMCEM_FCCU_FLT_SWNCF00 );
        }
        else
        {
            eMcem_Vfccu_DeassertSWFault( (uint8)nFaultId - EMCEM_FCCU_FLT_M33_SYNC_DBG );
        }
#else
#error "Wrong platform defined."
#endif /* SAFETY_BASE_MIMX9XXX */

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
    /* Check if faultId is in EIM range */
    else if( EMCEM_FAULT_IN_EIM_RANGE( nFaultId ) )
    {
        nReturnValue = eMcem_Eim_ClearFault( nFaultId - (uint16)EMCEM_EIM_CHANNELS_OFFSET );
    }
    /* Check if faultId is in SRAMC range */
    else if( EMCEM_FAULT_IN_SRAMC_RANGE( nFaultId ) )
    {
        nReturnValue = eMcem_Sramc_ClearFault( nFaultId - (uint16)EMCEM_SRAMC_CHANNELS_OFFSET );
    }
    /* Check if faultId is in DDRC range */
    else if( EMCEM_FAULT_IN_DDRC_RANGE( nFaultId ) )
    {
        nReturnValue = eMcem_Ddrc_ClearFault( nFaultId - (uint16)EMCEM_DDRC_CHANNELS_OFFSET );
    }
    else
    {
        /* No action needed */
    }

    return nReturnValue;
}

/**
* @brief      Get memory error info
* @details    Function retrieves the type, address and ECC syndrome of the last memory error. If available for any channel, provides
*             validated address (in defined address range), otherwise provides only raw data read from error address register.
*
* @param[in]  nChannelId      Global ID of ERM channel
* @param[out] pInfo           Structure with type, raw address data, validated address (if available), and syndrome of the last memory error
*
* @return     Std_ReturnType
* @retval           EMCEM_E_OK      No error occurred
* @retval           EMCEM_E_NOT_OK  An error occurred (correctable, non-correctable or both flags are set)
*
*/
Std_ReturnType eMcem_GetMemErrInfo_Int( eMcem_ChannelType nChannelId, eMcem_MemErrInfoType *pInfo )
{
    Std_ReturnType nReturnValue = EMCEM_E_OK;

    /* Clear info structure before filling it */
    pInfo->errAddrRaw = 0UL;
    pInfo->errAddrValid = 0UL;
    pInfo->u8ErrSyndrome = 0U;
    pInfo->errType = EMCEM_MEM_NO_ERR;

    /* Check if nChannelId is in ERM range */
    if( EMCEM_CHANNEL_IN_ERM_RANGE( nChannelId ) )
    {
        nReturnValue = eMcem_GetErmErrorInfo( nChannelId, pInfo );
    }
    /* Check if nChannelId is in SRAMC range */
    else if( EMCEM_CHANNEL_IN_SRAMC_RANGE( nChannelId ) )
    {
        nReturnValue = eMcem_Sramc_GetErrorInfo( (eMcem_ChannelType)( nChannelId - EMCEM_SRAMC_CHANNELS_OFFSET ), pInfo );

        eMcem_ValidateSramAddr( (eMcem_ChannelType)( nChannelId - EMCEM_SRAMC_CHANNELS_OFFSET ), pInfo );
    }
    /* Check if nChannelId is in DDRC range */
    else if( EMCEM_CHANNEL_IN_DDRC_RANGE( nChannelId ) )
    {
        nReturnValue = eMcem_Ddrc_GetErrorInfo( nChannelId, pInfo );
    }
    else
    {
        /* No action needed */
    }

    return nReturnValue;
}

/**
* @brief      Correct correctable error
* @details    Function corrects (reads and writes the value) the correctable error of ERM or SRAMC channel
*
* @param[in]  u32Addr    The address at which the error should be corrected
*
* @return     void
*
*/
void eMcem_CorrectCorrErr( uint32 u32Addr )
{
    uint32 u32Value;

    /* Read value specified by error address */
    /* @violates @ref eMcem_Erm_c_REF_1104 */
    /* @violates @ref eMcem_Erm_c_REF_1106 */
    u32Value = SAFETYBASE_REG_READ32( (sBase_PointerSizeType)u32Addr );

    /* Write value back */
    /* @violates @ref eMcem_Erm_c_REF_1104 */
    /* @violates @ref eMcem_Erm_c_REF_1106 */
    SAFETYBASE_REG_WRITE32( (sBase_PointerSizeType)u32Addr, u32Value );
}

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_Lib_MIMX9_c_REF_0410 */
/* @violates @ref eMcem_Lib_MIMX9_c_REF_2001 */
#include "eMcem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
