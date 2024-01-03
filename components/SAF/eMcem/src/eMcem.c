/**
*   @file    eMcem.c
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - API source.
*   @details This file implements eMcem API.
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
*   Copyright 2012-2016 Freescale
*   Copyright 2016-2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_c_REF_0410
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_c_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_c_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_c_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_c_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_c_REF_0807
* Violates MISRA 2012 Advisory Rule 8.7, Functions should not be defined with external linkage.
* This is an API function.
*
* @section eMcem_c_REF_2001
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
#include "Platform_Types.h"
#include "eMcem.h"
#include "eMcem_Lib_Ext.h"
#include "SafetyBase.h"
#include "eMcem_ExtDiagApi.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMCEM_SW_MAJOR_VERSION_C           0
#define EMCEM_SW_MINOR_VERSION_C           4
#define EMCEM_SW_PATCH_VERSION_C           0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_SW_MAJOR_VERSION_C != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_SW_MINOR_VERSION_C != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_SW_PATCH_VERSION_C != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem.c and MIMX_SAF version are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/**
* @brief Service ID for eMcem_Init function.
* @details Used when checking the driver state.
* */
#define EMCEM_INIT_ID                   0U
/**
* @brief Service ID for eMcem_InjectFault function.
* @details Used when checking the driver state.
* */
#define EMCEM_INJECT_FAULT_ID           1U

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
#define EMCEM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* @violates @ref eMcem_c_REF_0410 */
/* @violates @ref eMcem_c_REF_2001 */
#include "eMcem_MemMap.h"

/**
* @brief          Driver state.
* @details        The eMCEM driver changes state during start-up or runtime from EMCEM_S_UINIT to EMCEM_S_INITIALIZED.
*/
eMcem_StateType eMcem_DriverState = EMCEM_S_UNINIT;

#define EMCEM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* @violates @ref eMcem_c_REF_0410 */
/* @violates @ref eMcem_c_REF_2001 */
#include "eMcem_MemMap.h"

/* @violates @ref eMcem_c_REF_0501 */
/* @violates @ref eMcem_c_REF_0502 */
/* @violates @ref eMcem_c_REF_0504 */
/* @violates @ref eMcem_c_REF_0505 */
#define EMCEM_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/* @violates @ref eMcem_c_REF_0410 */
/* @violates @ref eMcem_c_REF_2001 */
#include "eMcem_MemMap.h"

/**
* @brief          Latest Configuration pointer.
* @details        When the eMCEM driver is initialized, the initialization pointer is stored to be used later.
*/
const eMcem_ConfigType *eMcem_pConfigPtr;

/* @violates @ref eMcem_c_REF_0501 */
/* @violates @ref eMcem_c_REF_0502 */
/* @violates @ref eMcem_c_REF_0504 */
/* @violates @ref eMcem_c_REF_0505 */
#define EMCEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/* @violates @ref eMcem_c_REF_0410 */
/* @violates @ref eMcem_c_REF_2001 */
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define EMCEM_START_SEC_CODE
/* @violates @ref eMcem_c_REF_0410 */
/* @violates @ref eMcem_c_REF_2001 */
#include "eMcem_MemMap.h"

static Std_ReturnType eMcem_ValidateInitPtr( const eMcem_ConfigType *pConfigPtr );
static Std_ReturnType eMcem_ValidateErrorPtr( const eMcem_FaultContainerType *pFaultsContainer );
static Std_ReturnType eMcem_ValidateFaultId( eMcem_FaultType nFaultId );
static Std_ReturnType eMcem_CheckState( uint8 u8FuncId );

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Validate Init Pointer
* @details    When initializing, a pointer to the init structure is used.
*
* @param[in]  pConfigPtr      Configuration pointer to be validated.
*
* @return     Std_ReturnType
* @retval           E_OK for valid pointer
* @retval           E_NOT_OK otherwise
*
*/
static Std_ReturnType eMcem_ValidateInitPtr( const eMcem_ConfigType *pConfigPtr )
{
    Std_ReturnType nReturnValue = (Std_ReturnType)E_NOT_OK;

    if( NULL_PTR != pConfigPtr )
    {
        nReturnValue = (Std_ReturnType)E_OK;
    }

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_VALIDATE_INIT_PTR, 0U )

    return nReturnValue;
}

/**
* @brief      Faults Container pointer validator.
* @details    When getting the errors, application provides a pointer to a structure where the driver
*             shall store the errors. This function checks that the pointer is not NULL.
*
* @param[in]  pFaultsContainer Pointer to be validated.
*
* @return     Std_ReturnType
* @retval           E_OK      Pointer is valid
* @retval           E_NOT_OK  Otherwise
*
*/
static Std_ReturnType eMcem_ValidateErrorPtr( const eMcem_FaultContainerType *pFaultsContainer )
{
    Std_ReturnType nReturnValue = (Std_ReturnType)E_NOT_OK;

    if( NULL_PTR != pFaultsContainer )
    {
        nReturnValue = (Std_ReturnType)E_OK;
    }

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_VALIDATE_ERROR_PTR, 0U )

    return nReturnValue;
}

/**
* @brief      Function to validate if fault is in acceptable range and enabled.
* @details    Before a parameter is used, it shall be checked for plausibility.
*
* @param[in]  nFaultId        Fault ID to be validated.
*
* @return     Std_ReturnType
* @retval           E_OK      for valid fault ID
* @retval           E_NOT_OK  otherwise
*
*/
static Std_ReturnType eMcem_ValidateFaultId( eMcem_FaultType nFaultId )
{
    Std_ReturnType nReturnValue = (Std_ReturnType)E_NOT_OK;
    uint8 u8RegisterPosition    = (uint8)( nFaultId >> EMCEM_FAULT_CONTAINER_SHIFT );
    uint8 u8BitPosition         = (uint8)( nFaultId &  EMCEM_FAULT_CONTAINER_MASK );
    boolean bValidFault;

    bValidFault = eMcem_CheckValidFault_Int( nFaultId );

    /* Check if nFaultId is valid */
    if( (boolean)TRUE == bValidFault )
    {
        /* Check if nFaultId is not a reserved signal */
        if( 0UL < ( eMcem_au32StaticFaultMasks[u8RegisterPosition] & ( 1UL << u8BitPosition ) ) )
        {
            nReturnValue = (Std_ReturnType)E_OK;
        }
        else
        {
            /* Log extended diagnostic data */
            EMCEM_DIAG_STORE_FAILURE_POINT( (Std_ReturnType)E_NOT_OK, EMCEM_FP_VALIDATE_FAULT_ID_2, 0U )
            EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( (Std_ReturnType)E_NOT_OK, (uint32)nFaultId )
        }
    }
    else
    {
        /* Log extended diagnostic data */
        EMCEM_DIAG_STORE_FAILURE_POINT( (Std_ReturnType)E_NOT_OK, EMCEM_FP_VALIDATE_FAULT_ID_1, 0U )
    }

    return nReturnValue;
}

/**
* @brief      Check State Mechanism.
* @details    Function preventing injection of a fault into uninitialized eMCEM
*
* @param[in]  u8FuncId        Function ID.
*
* @return     Std_ReturnType
* @retval           E_OK for  Valid state
* @retval           E_NOT_OK  Otherwise
*
*/
static Std_ReturnType eMcem_CheckState( uint8 u8FuncId )
{
    Std_ReturnType nReturnValue = (Std_ReturnType)E_OK;

    if( EMCEM_INJECT_FAULT_ID == u8FuncId )
    {
        if( EMCEM_S_UNINIT == eMcem_DriverState )
        {
            nReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_CHECK_STATE, 0U )
    EMCEM_DIAG_STORE_FAILURE_POINT_REGISTER_DATA( nReturnValue, (uint32)eMcem_DriverState )

    return nReturnValue;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Initialize the eMCEM driver.
* @details    The function initializes the eMCEM driver according to the configuration passed
*             as parameter (post-build) or according to the static one (pre-compile).
*
* @param[in]  pConfigPtr      Configuration pointer referring to the configuration structure.
*
* @return     Std_ReturnType
* @retval           E_OK      Initialization of the driver succeeded. The driver is functional and
*                             its state is EMCEM_S_INITIALIZED.
* @retval           E_NOT_OK  Initialization of the driver did not succeed. Configuration timeout expired, or the
*                             register configuration failed. Driver state is EMCEM_S_UNINIT.
*
* @api        The object is an API and must be documented in the user manual.
*
* @implements DD_eMcem_Init, DD_eMcem_Init_seq
*
* @violates @ref eMcem_c_REF_0807
*
*/
Std_ReturnType eMcem_Init( const eMcem_ConfigType *pConfigPtr )
{
    Std_ReturnType nReturnValue = (Std_ReturnType)E_NOT_OK;

    /* Clear extended diagnostic data */
    EMCEM_DIAG_CLEAR_DATA()

    /* Validate parameter */
    if( (Std_ReturnType)E_OK == eMcem_ValidateInitPtr( pConfigPtr ) )
    {
        /* Validate state */
        if( (Std_ReturnType)E_OK == eMcem_CheckState( EMCEM_INIT_ID ) )
        {
            /* Save the cfg address */
            eMcem_pConfigPtr = pConfigPtr;

            /* Initialize the VFCCU */
            nReturnValue = eMcem_Vfccu_Init_Int( pConfigPtr );

            if( (Std_ReturnType)E_OK == nReturnValue )
            {
                /* Set the driver state to INITIALIZED */
                eMcem_DriverState = EMCEM_S_INITIALIZED;
            }
            else /* (Std_ReturnType)E_OK != nReturnValue */
            {
                /* Initialization was not successful. Change driver state back to UNINIT to prevent executing other functions */
                eMcem_DriverState = EMCEM_S_UNINIT;
            }
        }

        /* Initialization of IPs */
        eMcem_Init_Int( pConfigPtr );

    }

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_INIT, 0U )

    /* Fault injection testing point */
    SBASE_FAULT_INJECTION_POINT( EMCEM_FIP_RETURN_INIT_0 );

    return nReturnValue;
}

/**
* @brief      Return logged error status.
* @details    Function stores status of each NCF into a container provided by the application.
*
* @param[out] pErrorContainer         Error container pointer.
*
* @return     Std_ReturnType
* @retval           E_OK              No fault is pending.
* @retval           E_FAULT_DETECTED  There is at least one logged fault.
* @retval           E_NOT_OK          Otherwise (error container pointer is not valid).
*
* @api        The object is an API and must be documented in the user manual.
*
* @implements DD_eMcem_GetErrors
*
* @violates @ref eMcem_c_REF_0807
*
*/
Std_ReturnType eMcem_GetErrors( eMcem_FaultContainerType *pErrorContainer )
{
    Std_ReturnType nReturnValue = (Std_ReturnType)E_NOT_OK;

    /* Clear extended diagnostic data */
    EMCEM_DIAG_CLEAR_DATA()

    if( (Std_ReturnType)E_OK == eMcem_ValidateErrorPtr( pErrorContainer ) )
    {
        nReturnValue = eMcem_GetErrors_Int( pErrorContainer );
    }

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_GET_ERRORS, 0U )

    return nReturnValue;
}

/**
* @brief      Clear software recoverable fault.
* @details    When a software recoverable fault occurs, a software routine shall remove the fault
*             cause and then it shall clear the fault status using this function.
*
* @param[in]  nFaultId        ID of the fault that shall be cleared. If the fault is not marked as software
*                             recoverable, the request is ignored.
*
* @return     Std_ReturnType
* @retval           E_OK      Fault was cleared successfully.
* @retval           E_NOT_OK  Fault was not cleared.
*
* @api        The object is an API and must be documented in the user manual.
*
* @implements DD_eMcem_ClearFaults
*
* @violates @ref eMcem_c_REF_0807
*
*/
Std_ReturnType eMcem_ClearFaults( eMcem_FaultType nFaultId )
{
    Std_ReturnType nReturnValue = (Std_ReturnType)E_NOT_OK;

    /* Clear extended diagnostic data */
    EMCEM_DIAG_CLEAR_DATA()

    if( (Std_ReturnType)E_OK == eMcem_ValidateFaultId( nFaultId ) )
    {
        nReturnValue = eMcem_ClearFaults_Int( nFaultId );
    }

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_CLEAR_FAULTS, 0U )

    return nReturnValue;
}

/**
* @brief      Assert FCCU software fault.
* @details    Set SW_NCF register bit to trigger a software fault into FCCU.
*
* @param[in]  nFaultId        ID of the SW fault that shall be asserted.
*
* @return     Std_ReturnType
* @retval           E_OK      SW fault has been asserted successfully.
* @retval           E_NOT_OK  SW fault has not been asserted.
*
* @api        The object is an API and must be documented in the user manual.
*
* @implements DD_eMcem_AssertSWFault
*
* @violates @ref eMcem_c_REF_0807
*
*/
Std_ReturnType eMcem_AssertSWFault( eMcem_FaultType nFaultId )
{
    Std_ReturnType nReturnValue = (Std_ReturnType)E_NOT_OK;

    /* Clear extended diagnostic data */
    EMCEM_DIAG_CLEAR_DATA()

    nReturnValue = eMcem_AssertSWFault_Int( nFaultId );

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_ASSERT_SW_FAULT, 0U )

    return nReturnValue;
}

/**
* @brief      Deassert FCCU software fault.
* @details    Clear SW_NCF register bit to stop the triggering of software fault into FCCU.
*
* @param[in]  nFaultId        ID of the SW fault that shall be deasserted.
*
* @return     Std_ReturnType
* @retval           E_OK      SW fault has been deasserted successfully.
* @retval           E_NOT_OK  SW fault has not been deasserted.
*
* @api        The object is an API and must be documented in the user manual.
*
* @implements DD_eMcem_DeassertSWFault
*
* @violates @ref eMcem_c_REF_0807
*
*/
Std_ReturnType eMcem_DeassertSWFault( eMcem_FaultType nFaultId )
{
    Std_ReturnType nReturnValue = (Std_ReturnType)E_NOT_OK;

    /* Clear extended diagnostic data */
    EMCEM_DIAG_CLEAR_DATA()

    nReturnValue = eMcem_DeassertSWFault_Int( nFaultId );

    /* Log extended diagnostic data */
    EMCEM_DIAG_STORE_FAILURE_POINT( nReturnValue, EMCEM_FP_DEASSERT_SW_FAULT, 0U )

    return nReturnValue;
}

#if( STD_ON == EMCEM_EXT_DIAG_ENABLED )
/**
* @brief      Get extended diagnostic data.
* @details    A function to retrieve last API call error diagnostic data.
*
* @param[out] pExtDiagData   Structure with diagnostic data
*
* @pre        pExtDiagData pointer shall not be null.
*
* @api        The object is an API and must be documented in the user manual.
*
* @implements DD_eMcem_GetExtDiagData
*
* @violates @ref eMcem_c_REF_0807
*
*/
void eMcem_GetExtDiagData( eMcem_ExtDiagDataType *pExtDiagData )
{
    uint8 i;

    if( NULL_PTR != pExtDiagData )
    {
        for( i = 0U; i < EMCEM_EXT_DIAG_DATA_MAX_LENGTH; i++ )
        {
            pExtDiagData->aFpId[i] = eMcem_ExtDiagData.aFpId[i];
            pExtDiagData->au8FailingLoopId[i] = eMcem_ExtDiagData.au8FailingLoopId[i];
        }
        pExtDiagData->u32RegisterValue = eMcem_ExtDiagData.u32RegisterValue;
        pExtDiagData->u8ItemsCount = eMcem_ExtDiagData.u8ItemsCount;
    }
}
#endif


#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_c_REF_0410 */
/* @violates @ref eMcem_c_REF_2001 */
#include "eMcem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
