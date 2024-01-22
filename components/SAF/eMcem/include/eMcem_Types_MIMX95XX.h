/**
*   @file    eMcem_Types_MIMX95XX.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - Types specific header.
*   @details Contains declarations of the eMcem specific types.
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
*   Copyright 2023-2024 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_TYPES_MIMX95XX_H
#define EMCEM_TYPES_MIMX95XX_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX_SAF_Version.h"
#include "SafetyBase_Cfg.h"
#include "eMcem_Vfccu_Types.h"
#include "eMcem_VfccuFaultList_MIMX95XX.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* Defines */

/*!
 * @name EMCEM config software version
 */
/** @{ */

/*!
* @brief    eMCEM TYPES MIMX95XX SW major version
*/
#define EMCEM_TYPES_MIMX95XX_SW_MAJOR_VERSION             0
/*!
* @brief   eMCEM TYPES MIMX95XX SW minor version.
*/
#define EMCEM_TYPES_MIMX95XX_SW_MINOR_VERSION             4
/*!
* @brief    eMCEM TYPES MIMX95XX SW patch version.
*/
#define EMCEM_TYPES_MIMX95XX_SW_PATCH_VERSION             0
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/*!< Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_TYPES_MIMX95XX_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_TYPES_MIMX95XX_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_TYPES_MIMX95XX_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Types_MIMX95XX.h and MIMX_SAF version are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*!
* @brief   Fault status register counts per VFCCU instance.
*/
#define EMCEM_VFCCU_FAULT_STATUS_REG_COUNT      (3U)

/*!
* @brief   Fault line offsets per VFCCU instance.
*/
#define EMCEM_VFCCU_FAULT_LINE_OFFSET           (EMCEM_FCCU_FLT_TEMP_HIGH)

/*!
* @brief   SW fault line offsets per VFCCU instance.
*/
#define EMCEM_VFCCU_SW_FAULT_LINE_OFFSET        (66U)

/*!
* @brief Shift used to access fault container slot
* 1 word per slot ~ 32bits = 2^5
*/
#define EMCEM_FAULT_CONTAINER_SHIFT             (5U)

/*!
* @brief Mask used to access fault container slot
* 1 word per slot ~ 32bits = 2^5
*/
#define EMCEM_FAULT_CONTAINER_MASK              ( ( 1U << EMCEM_FAULT_CONTAINER_SHIFT ) - 1U )

/*!
* @brief   SW fault line offsets per VFCCU instance.
*/
#define EMCEM_VFCCU_ERROR_CONTAINER_SIZE        ( ( ( EMCEM_CVFCCU_FAULT_LINES_COUNT - 1U ) / 32U ) + 1U )

/*!
* @brief   Width of FCCU registers (bits), and corresponding shift and mask.
*/
#define EMCEM_VFCCU_REG_SIZE_U8                 (32U)

/*!
* @brief   Register size.
*/
#define EMCEM_REG_SIZE                          (32U)

/*!
* @brief   Number of EOUT pins.
*/
#define EMCEM_EOUT_PIN_COUNT                    (2U)

/*!
* @brief   Number of CVFCCU fault lines.
*/
#define EMCEM_CVFCCU_MAX_FAULTS                 (80U)

/*!
* @brief   Number of CVFCCU FHID cores.
*/
#define EMCEM_CVFCCU_MAX_FHID_CORES             (1U)

/*!
* @brief   Number of VFCCU instances.
*/
#define EMCEM_VFCCU_INSTANCE_COUNT              (1U)

/*!
* @brief   Number of VFCCU reaction sets.
*/
#define EMCEM_REACTION_SET_COUNT                (8U)

/*!
* @brief   Number of CVFCCU reaction set registers.
*/
#define EMCEM_CVFCCU_REACTION_SET_REG_COUNT     (20U)

/*!
* @brief   Number of CVFCCU fault enable registers.
*/
#define EMCEM_CVFCCU_FAULT_ENABLE_REG_COUNT     (3U)

/*!
* @brief   Number of CVFCCU fault recovery registers.
*/
#define EMCEM_CVFCCU_FAULT_RECOVERY_REG_COUNT   (3U)

/*!
* @brief   Number of SW fault lines per VFCCU.
*/
#define EMCEM_VFCCU_SW_FAULT_COUNT              (6U)

/*!
* @brief   Number of fault status registers through all VFCCU instances.
*/
#define EMCEM_VFCCU_FHFLTS_REG_COUNT            (3U)

/*!
* @brief   Number of fields in Fault Reaction Set Configuration (FHFLTRKC) register.
*/
#define EMCEM_VFCCU_FHFLTRKC_FIELDS_COUNT       (20U)

/*!
* @brief  FHFLTRKC bit offset between fields.
*/
#define EMCEM_VFCCU_FHFLTRKC_FIELDS_OFFSET      (4U)

/*!
* @brief  FHFLTRKC one field bit mask.
*/
#define EMCEM_VFCCU_FHFLTRKC_FIELD_MASK         (7U)

/*!
* @brief  1 bit in 32-bit wide register.
*/
#define EMCEM_VFCCU_SHIFT_BIT_U32               (1UL)

/*!
* @brief  Indexes of VFCCU instances.
*/
#define EMCEM_C_VFCCU_IDX                       (0U)

/*!
* @brief  EOUT GEOUTPNC register masks.
*/
#define EMCEM_EOUT_GEOUTPNC_MASK                (0x00000531UL)

/*!
* @brief  EOUT GEOUTMC register masks.
*/
#define EMCEM_EOUT_GEOUTMC_MASK                 (0x0000000FUL)

/*!
* @brief  Check whether fault ID is in the proper range (VFCCU).
*/
#define EMCEM_FAULT_IN_VFCCU_RANGE(nFaultId)    ( (nFaultId) < EMCEM_CVFCCU_MAX_FAULTS )

/*!
* @brief  Check whether fault ID is in the proper range (EIM or SRAMC).
*/
#define EMCEM_FAULT_IN_RANGE(nFaultId)          ( ( EMCEM_FAULT_IN_VFCCU_RANGE( (nFaultId) ) ) )

/*!
* @brief  Check if faultID is within SW faults range.
*/
#define EMCEM_FAULT_IN_SW_FAULT_RANGE(nFaultId) ( ( (nFaultId) >= (EMCEM_FCCU_FLT_SWNCF00) ) && \
                                                  ( (nFaultId) <= (EMCEM_FCCU_FLT_SWNCF11) ) \
                                                )

/*!
* @brief  Number of SW faults registers.
*/
#define EMCEM_SW_FAULT_REG_COUNT                (2U)

/*!
* @brief  Offset between AON and M7 SW Faults.
*/
#define EMCEM_SW_FAULT_OFFSET                   (6U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
* @brief  An array containing unified faults reported by VFCCU.
*/
typedef uint32 eMcem_FaultArrayContainerType[EMCEM_VFCCU_ERROR_CONTAINER_SIZE];

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_TYPES_MIMX95XX_H */

/** @} */
