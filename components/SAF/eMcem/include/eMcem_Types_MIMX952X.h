/**
*   @file    eMcem_Types_MIMX943X.h
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - Types specific header.
*   @details Contains declarations of the eMcem specific types.
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
*   Copyright 2024-2026 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_TYPES_MIMX943X_H
#define EMCEM_TYPES_MIMX943X_H

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
#include "MIMX9XX_SAF_Version.h"
#include "SafetyBase_Cfg.h"
#include "eMcem_MemErr_Types_Ext.h"
#include "eMcem_ErmChannels_Ext.h"
#include "eMcem_Vfccu_Types.h"
#include "eMcem_VfccuFaultList_MIMX952X.h"
#include "eMcem_DdrcChannels_MIMX9.h"
#include "eMcem_EimChannels_MIMX952X.h"
#include "eMcem_SramcChannels_MIMX9.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*!
 * @name EMCEM MIMX952X-specific data type definitions SW version
 */
/** @{ */

/*!
* @brief    eMCEM MIMX952X-specific data type definitions - SW major version
*/
#define EMCEM_TYPES_MIMX952X_SW_MAJOR_VERSION             0
/*!
* @brief    eMCEM MIMX952X-specific data type definitions - SW minor version
*/
#define EMCEM_TYPES_MIMX952X_SW_MINOR_VERSION             8
/*!
* @brief    eMCEM MIMX952X-specific data type definitions - SW patch version
*/
#define EMCEM_TYPES_MIMX952X_SW_PATCH_VERSION             4
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX9XX_SAF version header file are of the same software version */
#if ((EMCEM_TYPES_MIMX952X_SW_MAJOR_VERSION != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_TYPES_MIMX952X_SW_MINOR_VERSION != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_TYPES_MIMX952X_SW_PATCH_VERSION != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Types_MIMX952X.h and MIMX9XX_SAF version are different"
#endif

#if SAFETY_BASE_MIMX952X
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*!
* @brief   Fault status register counts per VFCCU instance.
*/
#define EMCEM_VFCCU_FAULT_STATUS_REG_COUNT      (4U)

/*!
* @brief   Fault line offsets per VFCCU instance.
*/
#define EMCEM_VFCCU_FAULT_LINE_OFFSET           (EMCEM_FCCU_FLT_TEMP_HIGH)

/*!
* @brief   First SW fault line offset for VFCCU instance.
*/
#define EMCEM_VFCCU_SW_FAULT_LINE_OFFSET        (EMCEM_FCCU_FLT_SWNCF00)

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
#define EMCEM_VFCCU_ERROR_CONTAINER_SIZE        ( ( ( EMCEM_VFCCU_FAULT_LINES_COUNT - 1U ) / 32U ) + 1U )

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
#define EMCEM_CVFCCU_MAX_FAULTS                 (100U)

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
#define EMCEM_CVFCCU_REACTION_SET_REG_COUNT     (25U)

/*!
* @brief   Number of CVFCCU fault enable registers.
*/
#define EMCEM_CVFCCU_FAULT_ENABLE_REG_COUNT     (4U)

/*!
* @brief   Number of CVFCCU fault recovery registers.
*/
#define EMCEM_CVFCCU_FAULT_RECOVERY_REG_COUNT   (4U)

/*!
* @brief   Number of SW fault lines per MIX.
*/
#define EMCEM_VFCCU_SW_FAULT_COUNT              (6U)

/*!
* @brief   Number of fault status registers through all VFCCU instances.
*/
#define EMCEM_VFCCU_FHFLTS_REG_COUNT            (4U)

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
#define EMCEM_EOUT_GEOUTPNC_MASK                (0xFFFF0531UL)

/*!
* @brief  EOUT GEOUTMC register masks.
*/
#define EMCEM_EOUT_GEOUTMC_MASK                 (0x0000000FUL)

/* SRAM end addresses */
#define EMCEM_OCRAM_END_ADDR                    (OCRAM_BASE_ADDR + OCRAM_SIZE)

/*!
* @brief  Check whether fault ID is in the proper range (VFCCU, EIM, SRAMC or DDRC).
*/
#define EMCEM_FAULT_IN_VFCCU_RANGE(nFaultId)    ( (nFaultId) <= EMCEM_CVFCCU_MAX_FAULTS )

/*!
* @brief  Check whether fault ID is in the proper range (EIM or SRAMC).
*/
#define EMCEM_FAULT_IN_EIM_RANGE(nFaultId)      ( ( (nFaultId) >= EMCEM_EIM_CHANNELS_OFFSET ) && \
                                                  ( (nFaultId) <  EMCEM_SRAMC_CHANNELS_OFFSET ) \
                                                )

#define EMCEM_FAULT_IN_SRAMC_RANGE(nFaultId)    ( ( (nFaultId) >= EMCEM_SRAMC_CHANNELS_OFFSET ) && \
                                                  ( (nFaultId) <  EMCEM_DDRC_CHANNELS_OFFSET ) \
                                                )

#define EMCEM_FAULT_IN_DDRC_RANGE(nFaultId)      ( ( (nFaultId) >= EMCEM_DDRC_CHANNELS_OFFSET ) && \
                                                  ( (nFaultId) <  (EMCEM_DDRC_CHANNELS_OFFSET + EMCEM_DDRC_CHANNEL_COUNT) ) \
                                                )

#define EMCEM_FAULT_IN_RANGE(nFaultId)          ( ( EMCEM_FAULT_IN_VFCCU_RANGE( (nFaultId) ) ) || \
                                                  ( EMCEM_FAULT_IN_EIM_RANGE( (nFaultId) ) ) || \
                                                  ( EMCEM_FAULT_IN_SRAMC_RANGE( (nFaultId) ) ) || \
                                                  ( EMCEM_FAULT_IN_DDRC_RANGE( (nFaultId) ) ) \
                                                )

/*!
* @brief  Check if faultID is within SW faults range.
*/
#define EMCEM_FAULT_IN_SW_FAULT_RANGE(nFaultId) ( ( ( (nFaultId) >= (EMCEM_FCCU_FLT_SWNCF00) ) && \
                                                  ( (nFaultId) <= (EMCEM_FCCU_FLT_SWNCF11) ) ) \
                                                )

/* Range checks for memory channels. Used to detect which memory channel is being processed - ERM, SRAMC or DDRC */
#define EMCEM_CHANNEL_IN_SRAMC_RANGE(nChannelId)            ( ( (nChannelId) >= EMCEM_SRAMC_CHANNELS_OFFSET ) && \
                                                              ( (nChannelId) <  EMCEM_DDRC_CHANNELS_OFFSET ) \
                                                            )

#define EMCEM_CHANNEL_IN_DDRC_RANGE(nChannelId)              ( ( (nChannelId) >= EMCEM_DDRC_CHANNELS_OFFSET ) && \
                                                              ( (nChannelId) <  EMCEM_ERM_CHANNELS_OFFSET ) \
                                                            )

#define EMCEM_CHANNEL_IN_ERM_RANGE(nChannelId)              ( ( (nChannelId) >= EMCEM_ERM_CHANNELS_OFFSET ) && \
                                                              ( (nChannelId) <  ( EMCEM_ERM_CHANNELS_OFFSET + EMCEM_ERM_CHANNEL_COUNT ) ) \
                                                            )

#define EMCEM_CHANNEL_IN_RANGE(nChannelId)                  ( EMCEM_CHANNEL_IN_SRAMC_RANGE( (nChannelId) ) || \
                                                              EMCEM_CHANNEL_IN_DDRC_RANGE( (nChannelId) ) || \
                                                              EMCEM_CHANNEL_IN_ERM_RANGE( (nChannelId) ) \
                                                            )

/*!
* @brief  Number of SW faults registers.
*/
#define EMCEM_SW_FAULT_REG_COUNT                (2U)

/*!
* @brief  Offset between AON and M7 SW Faults or NETC and M7_1 SW Faults.
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

#endif /* SAFETY_BASE_MIMX952X */

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_TYPES_MIMX943X_H */

/** @} */
