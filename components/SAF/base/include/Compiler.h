/**
*   @file           Compiler.h
*   @implements     Compiler.h_Artifact
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
*   Peripheral           : IMX95XXM33
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 0.4.0
*   Build Version        : IMX95_SAF_0_4_0_CD01_20231113
*
*   Copyright 2006-2016 Freescale Semiconductor, Inc.
*   Copyright 2017-2020, 2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section Compiler_h_REF_4_9
* Violates MISRA 2012 Advisory Rule 4.9, A function should be used in preference to a function-like
* macro. This is the compiler abstraction specified in AutoSar Specification of Compiler Abstraction.
*
* @section Compiler_h_REF_20_7
* Violates MISRA 2012 Required Rule 20.7, Expressions resulting from the expansion of macro parameters shall
* be enclosed in parentheses. This is used to abstract compiler specific encapsulation of definitions and declarations.
*
*/

/**
* @file         Compiler.h
* @requirements COMPILER047
*/
#ifndef COMPILER_H
#define COMPILER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CompilerDefinition.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the compiler abstraction header file and also in
          the module's description file.
@{
*/
#define COMPILER_VENDOR_ID                      43

#define COMPILER_AR_RELEASE_MAJOR_VERSION       4
#define COMPILER_AR_RELEASE_MINOR_VERSION       7
#define COMPILER_AR_RELEASE_REVISION_VERSION    0
#define COMPILER_SW_MAJOR_VERSION               0
#define COMPILER_SW_MINOR_VERSION               4
#define COMPILER_SW_PATCH_VERSION               0
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

/**
* @brief The memory class AUTOMATIC shall be provided as empty definition, used for the declaration
*        of local pointers.
*/
#define AUTOMATIC

/**
* @brief The memory class TYPEDEF shall be provided as empty definition. This memory class shall be
*        used within type definitions, where no memory qualifier can be specified. This can be
*        necessary for defining pointer types, with e.g. P2VAR, where the macros require two
*        parameters. First parameter can be specified in the type definition (distance to the memory
*        location referenced by the pointer), but the second one (memory allocation of the pointer
*        itself) cannot be defined at this time. Hence memory class TYPEDEF shall be applied.
*/
#define TYPEDEF

/**
* @brief The compiler abstraction shall provide the NULL_PTR define with a void pointer to zero
*        definition.
*/
#define NULL_PTR ((void *)0)

/**************************************** Green Hills *********************************************/
#ifdef _GREENHILLS_C_MIMX95XX_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
    #define INLINE              __inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
    #define LOCAL_INLINE            static __inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
    #define INTERRUPT_FUNC      __interrupt
#endif /* #ifdef _GREENHILLS_C_MIMX95XX_ */

/**************************************** Wind River Diab *****************************************/
#ifdef _DIABDATA_C_MIMX95XX_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
    #define INLINE              __inline__

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
    #define LOCAL_INLINE            static __inline__

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
    #if 5967 == __VERSION_NUMBER__
        #define INTERRUPT_FUNC      __interrupt__
    #else
        #define INTERRUPT_FUNC      __attribute__((interrupt))
    #endif
#endif /* #ifdef _DIABDATA_C_MIMX95XX_ */

/*************************************** CodeWarrior **********************************************/
#ifdef _CODEWARRIOR_C_MIMX95XX_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
    #define INLINE              inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
    #define LOCAL_INLINE            static inline

     /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
    #define INTERRUPT_FUNC      __declspec(interrupt nowarn)
 #endif /* #ifdef _CODEWARRIOR_C_MIMX95XX_ */

/*************************************** Cosmic ***************************************************/
#ifdef _COSMIC_C_MIMX95XX_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
    #define INLINE @inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
    #define LOCAL_INLINE            static @inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
    #define INTERRUPT_FUNC @interrupt
#endif /* #ifdef _COSMIC_C_MIMX95XX_ */
/*************************************** HighTec **********************************************/
#ifdef _HITECH_C_MIMX95XX_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
    #define INLINE              __inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
    #define LOCAL_INLINE            static __inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
    #define INTERRUPT_FUNC      __attribute__((interrupt));
#endif /* #ifdef _HITECH_C_MIMX95XX_ */

/**************************************** Linaro *********************************************/
#ifdef _LINARO_C_MIMX95XX_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
    #define INLINE                  inline __attribute__((always_inline))

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
    #define LOCAL_INLINE            static inline __attribute__((always_inline))

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
    #define INTERRUPT_FUNC
#endif /* #ifdef _LINARO_C_MIMX95XX_ */
/**************************************** DS5 *************************************************/
#ifdef _ARM_DS5_C_MIMX95XX_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
    #define INLINE              __inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
    #define LOCAL_INLINE            static __inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
    #define INTERRUPT_FUNC
#endif /* #ifdef _ARM_DS5_C_MIMX95XX_ */

/**************************************** IAR *************************************************/
#ifdef _IAR_C_MIMX95XX_
    /* Prototypes for intrinsic functions */
    /**
    * @brief The compiler abstraction shall provide the INLINE define for abstraction of the keyword
    *        inline.
    */
    #define INLINE              inline

    /**
    * @brief The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the
    *       keyword inline in functions with "static" scope
    */
    #define LOCAL_INLINE            static inline

    /**
    * @brief Compiler abstraction for specifying an interrupt handler.
    */
    #define INTERRUPT_FUNC
#endif /* #ifdef _IAR_C_MIMX95XX_ */


/**
* @brief The compiler abstraction shall define the FUNC macro for the declaration and definition of
*        functions, that ensures correct syntax of function declarations as required by a specific
*        compiler.
*/
/*
* @violates @ref Compiler_h_REF_4_9 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_20_7 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define FUNC(rettype, memclass) rettype

/**
* @brief The compiler abstraction shall define the P2VAR macro for the declaration and definition of
*        pointers in RAM, pointing to variables.
*/
/*
* @violates @ref Compiler_h_REF_4_9 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_20_7 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

/**
* @brief The compiler abstraction shall define the P2CONST macro for the declaration and definition
*        of pointers in RAM pointing to constants.
*/
/*
* @violates @ref Compiler_h_REF_4_9 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_20_7 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *

/**
* @brief The compiler abstraction shall define the CONSTP2VAR macro for the declaration and
*        definition of constant pointers accessing variables.
*/
/*
* @violates @ref Compiler_h_REF_4_9 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_20_7 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

/**
* @brief The compiler abstraction shall define the CONSTP2CONST macro for the declaration and
*        definition of constant pointers accessing constants.
*/
/*
* @violates @ref Compiler_h_REF_4_9 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_20_7 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

/**
* @brief The compiler abstraction shall define the P2FUNC macro for the type definition of pointers
*        to functions.
*/
/*
* @violates @ref Compiler_h_REF_4_9 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_20_7 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)

/**
* @brief The compiler abstraction shall define the CONST macro for the declaration and definition of
*        constants.
*/
/*
* @violates @ref Compiler_h_REF_4_9 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_20_7 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define CONST(consttype, memclass) const consttype

/**
* @brief The compiler abstraction shall define the VAR macro for the declaration and definition of
*        variables.
*/
/*
* @violates @ref Compiler_h_REF_4_9 A function should be used in
* preference to a function-like macro.
*/
/*
* @violates @ref Compiler_h_REF_20_7 In the definition of a function-like macro each instance of a
*  parameter shall be enclosed in parentheses
*/
#define VAR(vartype, memclass) vartype


/**
* @brief The compiler abstraction for const pointer to function.
*/
/*
* @violates @ref Compiler_h_REF_4_9 A function should be used in preference to a function-like macro.
* @violates @ref Compiler_h_REF_20_7 In the definition of a function-like macro each instance of a parameter shall be enclosed in parentheses
*/
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname)


/**
* @brief The compiler abstraction shall define the FUNC_P2CONST macro for the declaration and
* definition of functions returning a pointer to a constant
*/
/*
* @violates @ref Compiler_h_REF_4_9 A function should be used in preference to a function-like macro.
* @violates @ref Compiler_h_REF_20_7 In the definition of a function-like macro each instance of a parameter shall be enclosed in parentheses
*/
#define FUNC_P2CONST(rettype, ptrclass, memclass) const ptrclass rettype * memclass

/**
* @brief The compiler abstraction shall define the FUNC_P2VAR macro for the declaration and
* definition of functions returning a pointer to a variable.
*/
/*
* @violates @ref Compiler_h_REF_4_9 A function should be used in preference to a function-like macro.
* @violates @ref Compiler_h_REF_20_7 In the definition of a function-like macro each instance of a parameter shall be enclosed in parentheses
*/
#define FUNC_P2VAR(rettype, ptrclass, memclass) ptrclass rettype * memclass

/*==================================================================================================
*                                             ENUMS
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

#endif /* #ifndef COMPILER_H */

/** @} */
