/**
*   @file    sBase_MemMap.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF SafetyBase - Memory mapping specification.
*   @details This document specifies mechanisms for the mapping of code and data to specific
*            memory sections via memory mapping file. For many ECUs and microcontroller platforms
*            it is of utmost necessity to be able to map code, variables and constants module
*            wise to specific memory sections.
*            This file contains sample code only. It is not part of the production code deliverables
*   @addtogroup SAFETY_BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : MIMX_SAF
*   Platform             : CORTEXM
*
*   SW Version           : 0.4.0
*   Build Version        : MIMX9X_SAF_0_4_0
*
*   Copyright 2011-2016 Freescale Semiconductor, Inc.
*   Copyright 2017-2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2012 violations
* @section sBase_MemMap_h_REF_1
* Violates MISRA 2012 Advisory Rule 20.5, #undef shall not be used.
* This is due to #undef MEMMAP_ERROR and #undef <section_type> and cannot be removed as it is
* required by Autosar Specification - Specification of Memory Mapping.
* @section sBase_MemMap_h_REF_2
* Violates MISRA 2012 Required Rule 4.10, Precautions shall be taken in order to prevent the
* contents of a header being included more than once.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
* @section sBase_MemMap_h_REF_3
* Violates MISRA 2012 Advisory Rule 20.1, #include directives should only be preceded by
* preprocessor directives or comments.
* This comes from the order of includes in the .c. MemMap is required by AutoSAR to be included in
* the middle of the source file(s).
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, Identifiers (internal and external) shall not rely  on the significance of more than 31 characters. All compilers used support more than 31 chars for identifiers.
* @section [global]
* Violates MISRA 2012 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character significance and case  sensitivity are supported for external identifiers. This violation is due to the naming convention for the memory ssections.
* @section [global]
* Violates MISRA 2012 Required Rule 3.4, All uses of the pragma directive shall be documented and explained. The pragma directives are used MemMap.h file to define memory sections.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref sBase_MemMap_h_REF_2
* @violates @ref sBase_MemMap_h_REF_3
*/
#include "MIMX_SAF_Version.h"
#include "CompilerDefinition.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @brief Parameters that shall be published within the memory map header file and also in the
*       module's description file
*/
#define SBASE_MEMMAP_SW_MAJOR_VERSION             0
#define SBASE_MEMMAP_SW_MINOR_VERSION             4
#define SBASE_MEMMAP_SW_PATCH_VERSION             0
/**@}*/
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((SBASE_MEMMAP_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (SBASE_MEMMAP_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (SBASE_MEMMAP_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
#error "Software Version Numbers of sBase_MemMap.h and MIMX_SAF version are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#pragma GCC diagnostic ignored "-Wunknown-pragmas"

/**
* @brief Symbol used for checking correctness of the includes
*/
#define MEMMAP_ERROR

/**************************************************************************************************/
/********************************************* GREENHILLS *****************************************/
/**************************************************************************************************/
#ifdef _GREENHILLS_C_MIMX95XX_
/**************************************** SBASE *******************************/
#ifdef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_flash_0"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_flash_1"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_flash_2"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_flash_3"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_flash_4"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_flash_5"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".mimx_saf_text"
#endif

#ifdef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".ramcode"
    #pragma ghs inlineprologue
    #pragma ghs callmode=far
#endif

#ifdef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
    #pragma ghs callmode=default
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".ramcode_no_cacheable"
    #pragma ghs inlineprologue
    #pragma ghs callmode=far
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
    #pragma ghs callmode=default
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".ramcode_no_cacheable_128"
    #pragma ghs inlineprologue
    #pragma ghs callmode=far
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
    #pragma ghs callmode=default
#endif

#ifdef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".acsbase_code_rom"
    #pragma ghs inlineprologue
#endif

#ifdef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_full_access"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_64k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_64k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_exec_16k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_exec_16k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_exec_8k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_exec_8k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_exec_8k_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_exec_8k_3"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_shared_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_persist_reset"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_scheck_faults_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_scheck_requests_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_tcm_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_tcm_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_tcm_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_3"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_4"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_5"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_6"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_7"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_8"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_9"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_10"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_11"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_12"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_13"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_14"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_15"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_16"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_17"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_18"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_19"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_20"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_21"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_22"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_23"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_24"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_25"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_26"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_27"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_sram_28"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_dram_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif
/**************************************************************************************************/
/********************************************* DIAB ***********************************************/
/**************************************************************************************************/
#elif defined(_DIABDATA_C_MIMX95XX_)
/**************************************** SBASE *******************************/
#ifdef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_flash_0"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_flash_1"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_flash_2"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_flash_3"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_flash_4"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_flash_5"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section text=".mimx_saf_text"
#endif

#ifdef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section text=""
#endif

#ifdef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section text=".ramcode"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #pragma clang section text=""
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section text=".ramcode_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #pragma clang section text=""
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section text=".ramcode_no_cacheable_128"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #pragma clang section text=""
#endif

#ifdef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* use code relative addressing mode to ensure Position-independent Code (PIC) */
    #pragma clang section text=".acsbase_code_rom"
#endif

#ifdef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #pragma clang section text=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_full_access"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_64k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_64k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_exec_16k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_exec_16k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_exec_8k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_exec_8k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_exec_8k_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_exec_8k_3"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_shared_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_persist_reset"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_scheck_faults_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_scheck_requests_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_tcm_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_tcm_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_tcm_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_3"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_4"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_5"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_6"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_7"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_8"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_9"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_10"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_11"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_12"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_13"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_14"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_15"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_16"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_17"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_18"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_19"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_20"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_21"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_22"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_23"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_24"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_25"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_26"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_27"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_sram_28"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_dram_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif
/**************************************************************************************************/
/********************************************* CODEWARRIOR ****************************************/
/**************************************************************************************************/
#elif defined(_CODEWARRIOR_C_MIMX95XX_)
/**************************************** SBASE *******************************/
#ifdef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_cfg
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_cfg
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_cfg
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_cfg
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const
#endif

#ifdef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const
#endif

#ifdef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const
#endif

#ifdef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const
#endif

#ifdef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_flash_0
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_flash_1
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_flash_2
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_flash_3
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_flash_4
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_flash_5
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG mimx_saf_text
#endif

#ifdef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG ramcode
#endif

#ifdef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG ramcode_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG ramcode_no_cacheable_128
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG acsbase_code_rom
#endif

#ifdef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_full_access
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_64k_0
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_64k_1
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data_exec_16k_0
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data_exec_16k_1
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data_exec_8k_0
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data_exec_8k_1
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data_exec_8k_2
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data_exec_8k_3
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_shared_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_persist_reset
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_scheck_faults_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_scheck_requests_no_cacheable
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_tcm_0
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_tcm_1
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_tcm_2
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_0
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_1
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_2
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_3
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_4
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_5
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_6
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_7
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_8
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_9
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_10
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_11
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_12
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_13
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_14
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_15
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_16
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_17
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_18
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_19
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_20
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_21
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_22
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_23
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_24
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_25
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_26
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_27
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_sram_28
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_dram_0
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif
/**************************************************************************************************/
/********************************************* COSMIC *********************************************/
/**************************************************************************************************/
#elif defined(_COSMIC_C_MIMX95XX_)
/**************************************** SBASE *******************************/
#ifdef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const_cfg}
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const_cfg}
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const_cfg}
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const_cfg}
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const}
#endif

#ifdef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const}
#endif

#ifdef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const}
#endif

#ifdef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const}
#endif

#ifdef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const}
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const_flash_0}
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const_flash_1}
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const_flash_2}
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const_flash_3}
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const_flash_4}
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const_flash_5}
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section (mimx_saf_text)
#endif

#ifdef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section (ramcode)
#endif

#ifdef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section (ramcode_no_cacheable)
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section (ramcode_no_cacheable_128)
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section (acsbase_code_rom)
#endif

#ifdef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_full_access]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_64k_0]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_64k_1]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data_exec_16k_0}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data_exec_16k_1}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data_exec_8k_0}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data_exec_8k_1}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data_exec_8k_2}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data_exec_8k_3}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_no_cacheable]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_no_cacheable]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_no_cacheable]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_no_cacheable]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_no_cacheable]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data_no_cacheable}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data_no_cacheable}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data_no_cacheable}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data_no_cacheable}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data_no_cacheable}
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_shared_no_cacheable]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_persist_reset]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_scheck_faults_no_cacheable]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_scheck_requests_no_cacheable]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_tcm_0]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_tcm_1]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_tcm_2]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_0]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_1]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_2]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_3]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_4]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_5]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_6]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_7]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_8]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_9]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_10]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_11]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_12]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_13]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_14]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_15]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_16]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_17]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_18]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_19]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_20]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_21]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_22]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_23]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_24]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_25]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_26]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_27]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_sram_28]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_dram_0]
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif
/**************************************************************************************************/
/********************************************* HighTec ********************************************/
/**************************************************************************************************/
#elif defined(_HITECH_C_MIMX95XX_)
/**************************************** SBASE *******************************/
#ifdef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_cfg" a
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_cfg" a
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_cfg" a
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_cfg" a
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const" a
#endif

#ifdef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const" a
#endif

#ifdef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const" a
#endif

#ifdef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const" a
#endif

#ifdef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const" a
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_flash_0" a
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_flash_1" a
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_flash_2" a
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_flash_3" a
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_flash_4" a
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_flash_5" a
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_text" avx
#endif

#ifdef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".ramcode" avx
#endif

#ifdef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".ramcode_no_cacheable" avx
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".ramcode_no_cacheable_128" avx
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".acsbase_code_rom" avx
#endif

#ifdef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_full_access" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_64k_0" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_64k_1" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data_exec_16k_0" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data_exec_16k_1" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data_exec_8k_0" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data_exec_8k_1" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data_exec_8k_2" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data_exec_8k_3" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_no_cacheable" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_no_cacheable" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_no_cacheable" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_no_cacheable" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_no_cacheable" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data_no_cacheable" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data_no_cacheable" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data_no_cacheable" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data_no_cacheable" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data_no_cacheable" aws
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_shared_no_cacheable" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_persist_reset" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_scheck_faults_no_cacheable" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_scheck_requests_no_cacheable" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_tcm_0" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_tcm_1" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_tcm_2" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_0" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_1" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_2" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_3" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_4" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_5" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_6" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_7" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_8" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_9" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_10" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_11" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_12" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_13" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_14" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_15" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_16" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_17" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_18" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_19" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_20" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_21" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_22" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_23" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_24" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_25" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_26" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_27" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_sram_28" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_dram_0" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif
/**************************************************************************************************/
/********************************************* Linaro *********************************************/
/**************************************************************************************************/
#elif defined(_LINARO_C_MIMX95XX_)
/**************************************** SBASE *******************************/
#ifdef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_flash_0"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_flash_1"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_flash_2"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_flash_3"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_flash_4"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_flash_5"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text ".mimx_saf_text"
#endif

#ifdef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text "default"
#endif

#ifdef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text ".ramcode"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text "default"
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text ".ramcode_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text "default"
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text ".ramcode_no_cacheable_128"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text "default"
#endif

#ifdef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text ".acsbase_code_rom"
#endif

#ifdef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_full_access"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_64k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_64k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_exec_16k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_exec_16k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_exec_8k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_exec_8k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_exec_8k_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_exec_8k_3"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_shared_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_persist_reset"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_scheck_faults_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_scheck_requests_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_tcm_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_tcm_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_tcm_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_3"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_4"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_5"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_6"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_7"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_8"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_9"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_10"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_11"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_12"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_13"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_14"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_15"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_16"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_17"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_18"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_19"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_20"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_21"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_22"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_23"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_24"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_25"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_26"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_27"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_sram_28"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_dram_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR

#endif
/**************************************************************************************************/
/********************************************* DS5 ************************************************/
/**************************************************************************************************/
#elif defined(_ARM_DS5_C_MIMX95XX_)
/**************************************** SBASE *******************************/
#ifdef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_flash_0"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_flash_1"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_flash_2"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_flash_3"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_flash_4"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_flash_5"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section code=".mimx_saf_text"
#endif

#ifdef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section code=".ramcode"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section code=".ramcode_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section code=".ramcode_no_cacheable_128"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section code=".acsbase_code_rom"
#endif

#ifdef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_full_access"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_64k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_64k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data_exec_16k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data_exec_16k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data_exec_8k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data_exec_8k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data_exec_8k_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data_exec_8k_3"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_shared_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_persist_reset"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_scheck_faults_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_scheck_requests_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_tcm_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_tcm_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_tcm_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_3"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_4"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_5"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_6"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_7"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_8"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_9"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_10"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_11"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_12"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_13"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_14"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_15"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_16"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_17"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_18"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_19"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_20"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_21"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_22"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_23"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_24"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_25"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_26"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_27"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_sram_28"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_dram_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif
/**************************************************************************************************/
/********************************************* IAR ************************************************/
/**************************************************************************************************/
#elif defined(_IAR_C_MIMX95XX_)
/**************************************** SBASE *******************************/
#ifdef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_cfg"
#endif

#ifdef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_flash_0"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_flash_1"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_flash_2"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_flash_3"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_flash_4"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_flash_5"
#endif

#ifdef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CONST_UNSPECIFIED_FLASH_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".mimx_saf_text"
#endif

#ifdef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =
#endif

#ifdef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".ramcode"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".ramcode_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =
#endif

#ifdef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".ramcode_no_cacheable_128"
#endif

#ifdef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_RAMCODE_NO_CACHEABLE_128
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =
#endif

#ifdef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".acsbase_code_rom"
#endif

#ifdef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_CODE_AC
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_full_access"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_FULL_ACCESS
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_64k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_64k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_65536_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_exec_16k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_exec_16k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16384_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_exec_8k_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_exec_8k_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_exec_8k_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_exec_8k_3"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8192_EXEC_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_shared_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_SHARED_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_persist_reset"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_scheck_faults_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_scheck_requests_no_cacheable"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_tcm_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_tcm_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_tcm_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_TCM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_1"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_1
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_2"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_2
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_3"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_3
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_4"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_4
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_5"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_5
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_6"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_6
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_7"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_7
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_8"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_9"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_9
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_10"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_10
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_11"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_11
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_12"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_12
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_13"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_13
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_14"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_14
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_15"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_15
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_16"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_17"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_17
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_18"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_18
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_19"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_19
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_20"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_20
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_21"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_21
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_22"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_22
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_23"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_23
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_24"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_24
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_25"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_25
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_26"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_26
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_27"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_27
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_sram_28"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_SRAM_28
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_dram_0"
#endif

#ifdef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_DRAM_0
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_BOOLEAN
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_8
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_16
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_32
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef SBASE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    /**
    * @file sBase_MemMap.h
    * @violates @ref sBase_MemMap_h_REF_1
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif
#endif
/**************************************************************************************************/
/****************************************** Report error ******************************************/
/**************************************************************************************************/
#ifdef MEMMAP_ERROR
    #error "sBase_MemMap.h, no valid memory mapping symbol defined."
#endif

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
