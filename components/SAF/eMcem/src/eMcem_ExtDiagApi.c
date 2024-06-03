/**
*   @file    eMcem_ExtDiagApi.c
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - Extended diagnostics API source.
*   @details This file implements functions for eMcem extended diagnostics.
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
*   Copyright 2019-2020, 2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_ExtDiagApi_c_REF_0410
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section eMcem_ExtDiagApi_c_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ExtDiagApi_c_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ExtDiagApi_c_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ExtDiagApi_c_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_ExtDiagApi_c_REF_2001
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
#include "eMcem_ExtDiagApi.h"
#include "eMcem_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_ExtDiagApi_c_REF_0501 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0502 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0504 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0505 */
#define EMCEM_EXTDIAGAPI_SW_MAJOR_VERSION_C           0
/* @violates @ref eMcem_ExtDiagApi_c_REF_0501 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0502 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0504 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0505 */
#define EMCEM_EXTDIAGAPI_SW_MINOR_VERSION_C           4
/* @violates @ref eMcem_ExtDiagApi_c_REF_0501 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0502 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0504 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0505 */
#define EMCEM_EXTDIAGAPI_SW_PATCH_VERSION_C           0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_EXTDIAGAPI_SW_MAJOR_VERSION_C != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_EXTDIAGAPI_SW_MINOR_VERSION_C != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_EXTDIAGAPI_SW_PATCH_VERSION_C != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_ExtDiagApi.c and MIMX_SAF version are different"
#endif

#if( STD_ON == EMCEM_EXT_DIAG_ENABLED )
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
/* @violates @ref eMcem_ExtDiagApi_c_REF_0501 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0502 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0504 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0505 */
#define EMCEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref eMcem_ExtDiagApi_c_REF_0410 */
#include "eMcem_MemMap.h"

/**
* @brief  eMCEM extended diagnostic data.
*/
eMcem_ExtDiagDataType eMcem_ExtDiagData;

/* @violates @ref eMcem_ExtDiagApi_c_REF_0501 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0502 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0504 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_0505 */
#define EMCEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref eMcem_ExtDiagApi_c_REF_0410 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_2001 */
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define EMCEM_START_SEC_CODE
/* @violates @ref eMcem_ExtDiagApi_c_REF_0410 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_2001 */
#include "eMcem_MemMap.h"

/**
* @brief        Store failure point
* @details      If last called function return value was E_NOT_OK and layer level is not over maximum,
*               store failure point and loop iteration ID (if available). Increment layer level too.
*
* @param[in]    retVal      Preceding function return value
* @param[in]    fpId        Failure point ID
* @param[in]    loopId      ID of loop iteration, where the failure occurred
*
* @return       void
*
*/
void eMcem_StoreFailurePoint( Std_ReturnType retVal, eMcem_FailurePointType fpId, uint8 loopId )
{
    if( (Std_ReturnType)E_NOT_OK == retVal )
    {
        /* Check if maximum API call tree depth was not reached */
        if( eMcem_ExtDiagData.u8ItemsCount < EMCEM_EXT_DIAG_DATA_MAX_LENGTH )
        {
            /* Log failure point ID and loop ID if available */
            eMcem_ExtDiagData.aFpId[eMcem_ExtDiagData.u8ItemsCount] = fpId;
            eMcem_ExtDiagData.au8FailingLoopId[eMcem_ExtDiagData.u8ItemsCount] = loopId;
            eMcem_ExtDiagData.u8ItemsCount++;
        }
    }
}

/**
* @brief        Backup register data
* @details      Store register data clarifying the failure point.
*
* @param[in]    retVal      Preceding function return value
* @param[in]    regVal      Register value
*
* @return       void
*
*/
void eMcem_StoreFailurePointRegisterData( Std_ReturnType retVal, uint32 regVal )
{
    if( (Std_ReturnType)E_NOT_OK == retVal )
    {
        eMcem_ExtDiagData.u32RegisterValue = regVal;
    }
}

/**
* @brief        Clear extended diagnostic data struct
* @details      Zero all the data in the diagnostics struct
*
* @return       void
*
*/
void eMcem_ClearExtDiagData( void )
{
    uint8 i;
    /* Clear whole array of failure point IDs and loop IDs */
    for( i = 0U; i < EMCEM_EXT_DIAG_DATA_MAX_LENGTH; i++ )
    {
        eMcem_ExtDiagData.aFpId[i] = EMCEM_FP_EMPTY;
        eMcem_ExtDiagData.au8FailingLoopId[i] = 0U;
    }

    /* Clear tree depth counter */
    eMcem_ExtDiagData.u8ItemsCount = 0U;

    /* Clear backed-up register value */
    eMcem_ExtDiagData.u32RegisterValue = 0UL;
}

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_ExtDiagApi_c_REF_0410 */
/* @violates @ref eMcem_ExtDiagApi_c_REF_2001 */
#include "eMcem_MemMap.h"

#endif /* ( STD_ON == EMCEM_EXT_DIAG_ENABLED ) */

#ifdef __cplusplus
}
#endif

/** @} */
