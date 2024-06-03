/**
*   @file    Std_Types.h
*   @implements     Std_Types.h_Artifact
*   @version 0.4.0
*
*   @brief   AUTOSAR Base - Standard types definition.
*   @details AUTOSAR standard types header file. It contains all types that are used across several
*            modules of the basic software and that are platform and compiler independent
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : MIMX_SAF
*   Platform             : CORTEXM
*   Peripheral           : MIMX9XXM33
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 0.4.0
*   Build Version        : MIMX9X_SAF_0_4_0
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc.
*   Copyright 2017-2019, 2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

/**
* @page misra_violations MISRA-C:2012 violations
*
*
* @section Std_Types_h_REF_4_1
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Platform_Types.h"
/**
* @brief Include compiler abstraction
* @violates @ref Std_Types_h_REF_4_1 MISRA 2012 Required Rule 19.15, Precautions shall be taken in
* order to prevent the contents of a header being included twice.
*/
#include "Compiler.h"
#include "MIMX_SAF_Version.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the standard types header file and also in the
*        module's description file
*/
#define STD_VENDOR_ID                     43
#define STD_AR_RELEASE_MAJOR_VERSION      4
#define STD_AR_RELEASE_MINOR_VERSION      7
#define STD_AR_RELEASE_REVISION_VERSION   0
#define STD_SW_MAJOR_VERSION              0
#define STD_SW_MINOR_VERSION              4
#define STD_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((STD_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (STD_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (STD_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
#error "Software Version Numbers of Std_types.h and MIMX_SAF version are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
/**
* @brief Physical state 5V or 3.3V
* @implements SymbolDefinitions_enumeration
*/
#define STD_HIGH    0x01

/**
* @brief Physical state 0V.
* @implements SymbolDefinitions_enumeration
*/
#define STD_LOW     0x00

/**
* @brief Logical state active.
* @implements SymbolDefinitions_enumeration
*/
#define STD_ACTIVE  0x01

/**
* @brief Logical state idle.
* @implements SymbolDefinitions_enumeration
*/
#define STD_IDLE    0x00

/**
* @brief ON State.
* @implements SymbolDefinitions_enumeration
*/
#define STD_ON      0x01

/**
* @brief OFF state.
* @implements SymbolDefinitions_enumeration
*/
#define STD_OFF     0x00

/**
* @brief Return code for failure/error.
* @implements SymbolDefinitions_enumeration
*/
#define E_NOT_OK    0x01

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief Because E_OK is already defined within OSEK, the symbol E_OK has to be shared. To avoid
*        name clashes and redefinition problems, the symbols have to be defined in the following way
*       (approved within implementation).
*/
#ifndef STATUSTYPEDEFINED
    #define STATUSTYPEDEFINED
    /**
    * @brief Success return code
    */
    #define E_OK      0x00
    /**
    * @brief This type is defined for OSEK compliance.
    */
    typedef unsigned char StatusType;
#endif

/**
* @brief This type can be used as standard API return type which is shared between the RTE and the
*        BSW modules.
* @implements Std_ReturnType_type
*/
typedef uint8 Std_ReturnType;

/**
* @brief This type shall be used to request the version of a BSW module using the
*       "ModuleName"_GetVersionInfo() function.
* @implements Std_VersionInfoType_structure
*/
typedef struct
{
    uint16  vendorID;               /**< @brief vendor ID */
    uint16  moduleID;               /**< @brief BSW module ID */
    uint8   sw_major_version;       /**< @brief BSW module software major version */
    uint8   sw_minor_version;       /**< @brief BSW module software minor version */
    uint8   sw_patch_version;       /**< @brief BSW module software patch version */
} Std_VersionInfoType;

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* #ifndef STD_TYPES_H */

/** @} */
