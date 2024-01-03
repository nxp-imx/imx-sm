/**
*   @file    SafetyBase_CompilerDefinition.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF SafetyBase - Compiler-specific defines
*   @details The file SafetyBase_CompilerDefinition.h provides macros for the encapsulation of definitions and
*            declarations.
*            This file contains sample code only. It is not part of the production code deliverables
*
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
*   Copyright 2006-2016 Freescale Semiconductor, Inc.
*   Copyright 2017-2019, 2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section SafetyBase_CompilerDefinition_h_REF_1
* Violates MISRA 2012 Required Rule 20.2, The names of standard library macros, objects and
* functions shall not be reused. Symbol required to be defined when one compiler is used.
* Requested by AutoSAR (Req. COMPILER010).
*
*/

#ifndef SAFETYBASE_COMPILERDEFINITION_H
#define SAFETYBASE_COMPILERDEFINITION_H

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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAFETYBASE_COMPILERDEFINITION_SW_MAJOR_VERSION             0
#define SAFETYBASE_COMPILERDEFINITION_SW_MINOR_VERSION             4
#define SAFETYBASE_COMPILERDEFINITION_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF configuration header file are of the same software version */
#if ((SAFETYBASE_COMPILERDEFINITION_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (SAFETYBASE_COMPILERDEFINITION_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (SAFETYBASE_COMPILERDEFINITION_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
#error "Software Version Numbers of SafetyBase_CompilerDefinition.h and MIMX_SAF version are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef __ghs__
    /**
    * @brief Symbol required to be defined when GreenHills compiler is used.
    */
  /*
    * @violates @ref SafetyBase_CompilerDefinition_h_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _GREENHILLS_C_MIMX95XX_
#endif
#ifdef __DCC__
    /**
    * @brief Symbol required to be defined when Diab compiler is used.
    */
  /*
    * @violates @ref SafetyBase_CompilerDefinition_h_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _DIABDATA_C_MIMX95XX_
#endif
#ifdef __MWERKS__
    /**
    * @brief Symbol required to be defined when Codewarrior compiler is used.
    */
  /*
    * @violates @ref SafetyBase_CompilerDefinition_h_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _CODEWARRIOR_C_MIMX95XX_
#endif
#ifdef __CSMC__
    /**
    * @brief Symbol required to be defined when Cosmic compiler is used.
    */
  /*
    * @violates @ref SafetyBase_CompilerDefinition_h_REF_1 The names of standard library
    * macros, objects and functions shall not be reused.
    */
  #define _COSMIC_C_MIMX95XX_
#endif
#if (defined(__GNUC__) && !defined(__DCC__)) /* is GCC only when it does not have DIAB specific macro */
                  /**
            * @brief Symbol required to be defined when Linaro ARM compiler is used.
            */
            /* @violates @ref SafetyBase_CompilerDefinition_h_REF_1 MISRA 2012 Required Rule 21.1, macro for compiler name.*/
            #define _LINARO_C_MIMX95XX_
      #endif
#ifdef __CC_ARM
        /**
        * @brief Symbol required to be defined when DS5 ARM compiler is used.
        */
        /*
        * @violates @ref SafetyBase_CompilerDefinition_h_REF_1 The names of standard library
        * macros, objects and functions shall not be reused.
        */
        #define _ARM_DS5_C_MIMX95XX_
#endif
#ifdef __ICCARM__
        /**
        * @brief Symbol required to be defined when IAR compiler is used.
        */
        /*
        * @violates @ref SafetyBase_CompilerDefinition_h_REF_1 The names of standard library
        * macros, objects and functions shall not be reused.
        */
        #define _IAR_C_MIMX95XX_
#endif

#ifdef __cplusplus
}
#endif

#endif /* #ifndef SAFETYBASE_COMPILERDEFINITION_H */

/** @} */