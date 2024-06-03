/**
*   @file           CompilerDefinition.h
*   @version 0.4.0
*
*   @brief   AUTOSAR Base - SWS Compiler abstraction
*   @details The file Compiler.h provides macros for the encapsulation of definitions and
*            declarations.
*            This file contains sample code only. It is not part of the production code deliverables
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
*/

#ifndef COMPILERDEFINITION_H
#define COMPILERDEFINITION_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the compiler abstraction header file and also in
          the module's description file.
@{
*/
#define COMPILERDEFINITION_VENDOR_ID                      43
#define COMPILERDEFINITION_AR_RELEASE_MAJOR_VERSION       4
#define COMPILERDEFINITION_AR_RELEASE_MINOR_VERSION       7
#define COMPILERDEFINITION_AR_RELEASE_REVISION_VERSION    0
#define COMPILERDEFINITION_SW_MAJOR_VERSION               0
#define COMPILERDEFINITION_SW_MINOR_VERSION               4
#define COMPILERDEFINITION_SW_PATCH_VERSION               0
/**@}*/
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

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
    #define _GREENHILLS_C_MIMX95XX_
#endif
#ifdef __DCC__
    /**
    * @brief Symbol required to be defined when Diab compiler is used.
    */
    #define _DIABDATA_C_MIMX95XX_
#endif
#ifdef __MWERKS__
    /**
    * @brief Symbol required to be defined when Codewarrior compiler is used.
    */
    #define _CODEWARRIOR_C_MIMX95XX_
#endif
#ifdef __CSMC__
    /**
    * @brief Symbol required to be defined when Cosmic compiler is used.
    */
  #define _COSMIC_C_MIMX95XX_
#endif
#if (defined(__GNUC__) && !defined(__DCC__)) /* is GCC only when it does not have DIAB specific macro */
                  /**
            * @brief Symbol required to be defined when Linaro ARM compiler is used.
            */
            #define _LINARO_C_MIMX95XX_
      #endif
#ifdef __CC_ARM
        /**
        * @brief Symbol required to be defined when DS5 ARM compiler is used.
        */
        #define _ARM_DS5_C_MIMX95XX_
#endif
#ifdef __ICCARM__
        /**
        * @brief Symbol required to be defined when IAR compiler is used.
        */
        #define _IAR_C_MIMX95XX_
#endif

#ifdef __cplusplus
}
#endif

#endif /* #ifndef COMPILERDEFINITION_H */

/** @} */
