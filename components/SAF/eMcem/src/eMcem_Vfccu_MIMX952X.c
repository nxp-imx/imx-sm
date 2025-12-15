/**
*   @file    eMcem_Vfccu_MIMX943X.c
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - Specific VFCCU IP source.
*   @details This file implements specific VFCCU IP functions eMcem module.
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
*   Copyright 2026 NXP
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
#include "MIMX9XX_SAF_Version.h"
#include "eMcem_Types_Ext.h"
#include "SafetyBase.h"
#include "eMcem_Vfccu_MIMX9.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0501 */
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0502 */
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0504 */
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0505 */
#define EMCEM_VFCCU_MIMX952X_SW_MAJOR_VERSION_C               0
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0501 */
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0502 */
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0504 */
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0505 */
#define EMCEM_VFCCU_MIMX952X_SW_MINOR_VERSION_C               8
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0501 */
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0502 */
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0504 */
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0505 */
#define EMCEM_VFCCU_MIMX952X_SW_PATCH_VERSION_C               4

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_VFCCU_MIMX952X_SW_MAJOR_VERSION_C != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_VFCCU_MIMX952X_SW_MINOR_VERSION_C != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_VFCCU_MIMX952X_SW_PATCH_VERSION_C != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Vfccu_MIMX952X.c and MIMX9XX_SAF version are different"
#endif

#if SAFETY_BASE_MIMX952X
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
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0410 */
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
        M7__A7_APB_MCM1.FCCU_SW_FAULTS.R |= ( 1UL << u8BitIdx );
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
        M7__A7_APB_MCM1.FCCU_SW_FAULTS.R &= ~( 1UL << u8BitIdx );
    }
}

#define EMCEM_STOP_SEC_CODE
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_0410 */
/* @violates @ref eMcem_Vfccu_MIMX952X_c_REF_2001 */
#include "eMcem_MemMap.h"

#endif /* SAFETY_BASE_MIMX952X */

#ifdef __cplusplus
}
#endif

/** @} */
