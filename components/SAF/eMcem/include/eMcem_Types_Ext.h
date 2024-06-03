/**
*   @file    eMcem_Types_Ext.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - Types header.
*   @details Contains declarations of the eMcem types.
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
*   Copyright 2012-2016 Freescale
*   Copyright 2016, 2018-2024 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_TYPES_EXT_H
#define EMCEM_TYPES_EXT_H

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
#include "eMcem_Types_MIMX95XX.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*!
* @name eMCEM common type definition SW version
*/
/** @{ */

/*!
* @brief    eMCEM common type definition - SW major version
*/
#define EMCEM_TYPES_EXT_SW_MAJOR_VERSION             0
/*!
* @brief    eMCEM common type definition - SW minor version
*/
#define EMCEM_TYPES_EXT_SW_MINOR_VERSION             4
/*!
* @brief    eMCEM common type definition - SW patch version
*/
#define EMCEM_TYPES_EXT_SW_PATCH_VERSION             0

/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_TYPES_EXT_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_TYPES_EXT_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_TYPES_EXT_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_Types_Ext.h and MIMX_SAF version are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*!< Additional value indicating pending fault when returning from eMcem_Geterrors() */
/*!
* @brief    eMCEM  OK
*/
#define EMCEM_E_OK                ((Std_ReturnType)E_OK)
/*!
* @brief    eMCEM  NOT OK
*/
#define EMCEM_E_NOT_OK            ((Std_ReturnType)E_NOT_OK)
/*!
* @brief    eMCEM fault detected
*/
#define EMCEM_E_FAULT_DETECTED    ((Std_ReturnType)2U)
/*!
* @brief    eMCEM pending fault false
*/
#define EMCEM_FALSE               ((boolean)FALSE)
/*!
* @brief    eMCEM pending fault true
*/
#define EMCEM_TRUE                ((boolean)TRUE)
/*!
* @brief    eMCEM fault detected
*/
#define E_FAULT_DETECTED          ((Std_ReturnType)2)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief      eMCEM Driver State Enum.
* @details    Enumeration covering possible states of the driver.
*/
typedef enum
{
    EMCEM_S_UNINIT      = 0, /**< @brief eMCEM module has not been initialized. */
    EMCEM_S_INITIALIZED = 1, /**< @brief eMCEM module has been initialized without locking. */
} eMcem_StateType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief     Typedef of notification function which does not have input parameters.
 * @details   Used for Configuration Timeout Notification function where the user can handle
 *            the situation in which the FCCU leaves CONFIG state because of the configuration
 *            timeout.
 */
typedef void (*eMcem_NotifyVoidType)(void);

/**
* @brief      Fault container struct type.
* @details    Container for storing errors.
*/
typedef struct
{
    Std_ReturnType                nErrorStatus; /**< @brief Stored return value of eMcem_GetErrors(). */
    eMcem_FaultArrayContainerType au32Faults;   /**< @brief Aggregated fault status container. */
} eMcem_FaultContainerType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_TYPES_EXT_H */

/** @} */
