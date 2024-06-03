/**
*   @file    eMcem_Vfccu_MIMX943X.c
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - Specific VFCCU IP source.
*   @details This file implements specific VFCCU IP functions eMcem module.
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
*   Copyright 2024 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX_SAF_Version.h"
#include "eMcem_Types_Ext.h"
#include "SafetyBase.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0501 */
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0502 */
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0504 */
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0505 */
#define EMCEM_VFCCU_MIMX95XX_SW_MAJOR_VERSION_C               0
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0501 */
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0502 */
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0504 */
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0505 */
#define EMCEM_VFCCU_MIMX95XX_SW_MINOR_VERSION_C               4
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0501 */
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0502 */
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0504 */
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0505 */
#define EMCEM_VFCCU_MIMX95XX_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_VFCCU_MIMX95XX_SW_MAJOR_VERSION_C != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_VFCCU_MIMX95XX_SW_MINOR_VERSION_C != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_VFCCU_MIMX95XX_SW_PATCH_VERSION_C != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Vfccu_MIMX95XX.c and MIMX_SAF version are different"
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
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0410 */
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Assert software VFCCU fault.
* @details    Sets reaction line for software fault.
*
* @param[in]  u8SWRegIdx   ID of the SW faults register.
* @param[in]  u8BitIdx     Bit position in SW fault register.
*
* @return     void
*
*/
void eMcem_Vfccu_Specific_AssertSWFault( uint8 u8SWRegIdx, uint8 u8BitIdx )
{
    /* Assert SW fault according to its register and bit position */
    if( u8SWRegIdx == 0U )
    {
        /* Assert SW fault in AON M33 */
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
* @param[in]  u8SWRegIdx   ID of the SW faults register.
* @param[in]  u8BitIdx     Bit position in SW fault register.
*
* @return     void
*
*/
void eMcem_Vfccu_Specific_DeassertSWFault( uint8 u8SWRegIdx, uint8 u8BitIdx )
{
    /* Deassert SW fault according to its register and bit position */
    if( u8SWRegIdx == 0U )
    {
        /* Deassert SW fault in AON M33 */
        AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM.FCCU_SW_FAULTS.R &= ~( 1UL << u8BitIdx );
    }
    else
    {
        /* Deassert SW fault in M7 */
        M7__A7_MCM.FCCU_SW_FAULTS.R &= ~( 1UL << u8BitIdx );
    }
}

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_0410 */
/* @violates @ref eMcem_Vfccu_MIMX95XX_c_REF_2001 */
#include "eMcem_MemMap.h"

#endif /* defined(SAFETY_BASE_MIMX95XX) */

#ifdef __cplusplus
}
#endif

/** @} */
