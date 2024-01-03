/**
*   @file    Rte_MemMap.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF Base - Memory mapping specification.
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
*   Build Version        : IMX95_SAF_0_4_0_CD01_20231113
*
*   Copyright 2011-2016 Freescale Semiconductor, Inc.
*   Copyright 2017-2020, 2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2012 violations
* @section Rte_MemMap_h_REF_1
* Violates MISRA 2012 Required Rule 19.6, #undef shall not be used.
* This is due to #undef MEMMAP_ERROR and #undef <section_type> and cannot be removed as it is
* required by Autosar Specification - Specification of Memory Mapping.
* @section Rte_MemMap_h_REF_2
* Violates MISRA 2012 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
* @section Rte_MemMap_h_REF_3
* Violates MISRA 2012 Advisory Rule 19.1, #include statements in a file should only be preceded by
* other preprocessor directives or comments.
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
* @violates @ref Rte_MemMap_h_REF_2 Precautions shall be taken in order
* to prevent the contents of a header being included twice.
*/
/* @violates @ref Rte_MemMap_h_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
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
#define RTE_MEMMAP_SW_MAJOR_VERSION             0
#define RTE_MEMMAP_SW_MINOR_VERSION             4
#define RTE_MEMMAP_SW_PATCH_VERSION             0
/**@}*/
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((RTE_MEMMAP_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (RTE_MEMMAP_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (RTE_MEMMAP_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
#error "Software Version Numbers of Rte_MemMap.h and MIMX_SAF version are different"
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/**
* @brief Symbol used for checking correctness of the includes
*/
#define MEMMAP_ERROR

#ifndef AUTOSAR_OS_NOT_USED
        #include "Os_memmap.h"
#endif
/**************************************************************************************************/
/********************************************* GREENHILLS *****************************************/
/**************************************************************************************************/
#ifdef _GREENHILLS_C_MIMX95XX_
/**************************************** RTE *******************************/
#ifdef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".mimx_saf_text"
#endif

#ifdef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".ramcode"
    #pragma ghs inlineprologue
    #pragma ghs callmode=far
#endif

#ifdef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
    #pragma ghs callmode=default
#endif

#ifdef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".acrte_code_rom"
    #pragma ghs inlineprologue
#endif

#ifdef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif


#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_monitor_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_scheck_faults_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_scheck_requests_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mimx_saf_bss_persist_reset"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif
/**************************************************************************************************/
/********************************************* DIAB ***********************************************/
/**************************************************************************************************/
#elif defined(_DIABDATA_C_MIMX95XX_)
/**************************************** RTE *******************************/
#ifdef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section rodata=""
#endif

#ifdef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section text=".mimx_saf_text"
#endif

#ifdef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section text=""
#endif

#ifdef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section text=".ramcode" data=".ramcode"
#endif

#ifdef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #pragma clang section text="" data=""
#endif

#ifdef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* use code relative addressing mode to ensure Position-independent Code (PIC) */
    #pragma clang section text=".acrte_code_rom"

#endif

#ifdef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #pragma clang section text=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif


#ifdef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif


#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif


#ifdef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section data=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_monitor_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_scheck_faults_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_scheck_requests_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=".mimx_saf_bss_persist_reset"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma clang section bss=""
#endif
/**************************************************************************************************/
/********************************************* CODEWARRIOR ****************************************/
/**************************************************************************************************/
#elif defined(_CODEWARRIOR_C_MIMX95XX_)
/**************************************** RTE *******************************/
#ifdef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_cfg
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_cfg
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_cfg
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const_cfg
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const
#endif

#ifdef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const
#endif

#ifdef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const
#endif

#ifdef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const
#endif

#ifdef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mimx_saf_const
#endif

#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG mimx_saf_text
#endif

#ifdef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG ramcode
#endif

#ifdef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG acrte_code_rom
#endif

#ifdef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif


#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_data
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_monitor_no_cacheable
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_scheck_faults_no_cacheable
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_scheck_requests_no_cacheable
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mimx_saf_bss_persist_reset
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif
/**************************************************************************************************/
/********************************************* COSMIC *********************************************/
/**************************************************************************************************/
#elif defined(_COSMIC_C_MIMX95XX_)
/**************************************** RTE *******************************/
#ifdef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_safconstcfg}
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_safconstcfg}
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_safconstcfg}
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_safconstcfg}
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const}
#endif

#ifdef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const}
#endif

#ifdef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const}
#endif

#ifdef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const}
#endif

#ifdef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mimx_saf_const}
#endif

#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section (mimx_saf_text)
#endif

#ifdef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section (ramcode)
#endif

#ifdef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section (acrtecode)
#endif

#ifdef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif


#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mimx_saf_data}
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_monitor_no_cacheable]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_scheck_faults_no_cacheable]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_scheck_requests_no_cacheable]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mimx_saf_bss_persist_reset]
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif
/**************************************************************************************************/
/********************************************* HighTec *********************************************/
/**************************************************************************************************/
#elif defined(_HITECH_C_MIMX95XX_)
/**************************************** RTE *******************************/
#ifdef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_cfg" a
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_cfg" a
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_cfg" a
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const_cfg" a
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const" a
#endif

#ifdef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const" a
#endif

#ifdef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const" a
#endif

#ifdef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const" a
#endif

#ifdef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_const" a
#endif

#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_text" avx
#endif

#ifdef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".ramcode" avx
#endif

#ifdef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma  section
#endif

#ifdef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".acrte_code_rom" avx
#endif

#ifdef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma  section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss" awsB
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_no_cacheable" awsB
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif
#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data" aws
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data" aws
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data" aws
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data" aws
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_data" aws
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_monitor_no_cacheable" awsB
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_scheck_faults_no_cacheable" awsB
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_scheck_requests_no_cacheable" awsB
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mimx_saf_bss_persist_reset" awsB
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif
/**************************************************************************************************/
/********************************************* Linaro *********************************************/
/**************************************************************************************************/
#elif defined(_LINARO_C_MIMX95XX_)
/**************************************** RTE *******************************/
#ifdef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata "default"
#endif

#ifdef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text ".mimx_saf_text"
#endif

#ifdef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text "default"
#endif

#ifdef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text ".ramcode"
#endif

#ifdef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text "default"
#endif

#ifdef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text ".acsboot_code_rom"
#endif

#ifdef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif


#ifdef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif


#ifdef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_monitor_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_scheck_faults_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_scheck_requests_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mimx_saf_bss_persist_reset"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss "default"
#endif
/**************************************************************************************************/
/********************************************* DS5 ************************************************/
/**************************************************************************************************/
#elif defined(_ARM_DS5_C_MIMX95XX_)
/**************************************** RTE *******************************/
#ifdef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section code=".mimx_saf_text"
#endif

#ifdef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section code=".ramcode"
#endif

#ifdef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section code=".acrte_code_rom"
#endif

#ifdef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif
/**************************************************************************************************/
/********************************************* IAR ************************************************/
/**************************************************************************************************/
#elif defined(_IAR_C_MIMX95XX_)
/**************************************** RTE *******************************/
#ifdef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const_cfg"
#endif

#ifdef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_const"
#endif

#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".mimx_saf_text"
#endif

#ifdef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =
#endif

#ifdef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".ramcode"

#endif

#ifdef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_RAMCODE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =

#endif

#ifdef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".acrte_code_rom"

#endif

#ifdef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_CODE_AC
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =

#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif


#ifdef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mimx_saf_data_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_monitor_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_MONITOR_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_scheck_faults_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_FAULTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_scheck_requests_no_cacheable"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_REQUESTS_NO_CACHEABLE
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_START_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mimx_saf_bss_persist_reset"
#endif

#ifdef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef RTE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_PERSIST_RESET
    /**
    * @file Rte_MemMap.h
    * @violates @ref Rte_MemMap_h_REF_1 MISRA 2012 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif
#endif
/**************************************************************************************************/
/****************************************** Report error ******************************************/
/**************************************************************************************************/
#ifdef MEMMAP_ERROR
    #error "Rte_MemMap.h, no valid memory mapping symbol defined."
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
