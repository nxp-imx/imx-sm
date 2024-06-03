/**
*   @file    SafetyBase.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF SafetyBase - SWS Compiler abstraction specific for MIMX_SAF.
*   @details The file SafetyBase.h provides MIMX_SAF specific macros used for compiler abstraction.
*
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

#ifndef SBASE_H
#define SBASE_H

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
#include "SafetyBase_Cfg.h"
#include "CompilerDefinition.h"
#include "Std_Types.h"
#include "SafetyBase_StdRegMacros.h"
#include "SafetyBase_PmicWrapper.h"
#include "SafetyBase_HseWrapper.h"

/* Include platform header file */
#include "MIMX_SAF_Version.h"
#include "SafetyBase_MIMX95XX_SAF.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SBASE_SW_MAJOR_VERSION             0
#define SBASE_SW_MINOR_VERSION             4
#define SBASE_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((SBASE_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (SBASE_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (SBASE_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
#error "Software Version Numbers of SafetyBase.h and MIMX_SAF version are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**************************************** Green Hills *********************************************/
#ifdef _GREENHILLS_C_MIMX95XX_
    /**
    * @brief Compiler abstraction for the asm keyword.
    */
    #define SBASE_ASM_KEYWORD  __asm

   /**
    * @brief Compiler abstraction for the naked qualifier
    */
    #define SBASE_NAKED

    /**
    * @brief Compiler abstraction for MIMX_SAF Fault Injection tests
    */
    #ifdef SBASE_ENABLE_FAULT_INJECTION
    #define SBASE_PUT_IN_QUOTES(x) #x
    #define SBASE_FAULT_INJECTION_POINT(label) SBASE_ASM_KEYWORD(SBASE_PUT_IN_QUOTES(label::\n))
    #else
    #define SBASE_FAULT_INJECTION_POINT(label)
    #endif

#endif /* #ifdef _GREENHILLS_C_MIMX95XX_ */

/**************************************** Wind River Diab *****************************************/
#ifdef _DIABDATA_C_MIMX95XX_
    /**
    * @brief Compiler abstraction for the asm keyword.
    */
    #define SBASE_ASM_KEYWORD  __asm

   /**
    * @brief Compiler abstraction for the naked qualifier
    */
    #define SBASE_NAKED __attribute__((naked))

    /**
     * @brief Compiler abstraction for MIMX_SAF Fault Injection tests
    */
    #ifdef SBASE_ENABLE_FAULT_INJECTION
    #define SBASE_PUT_IN_QUOTES(x) #x
    #define SBASE_FAULT_INJECTION_POINT(label) SBASE_ASM_KEYWORD(SBASE_PUT_IN_QUOTES(label:\n))
    #else
    #define SBASE_FAULT_INJECTION_POINT(label)
    #endif

#endif /* #ifdef _DIABDATA_C_MIMX95XX_ */

/**************************************** Linaro **************************************************/
#ifdef _LINARO_C_MIMX95XX_
    /**
    * @brief Compiler abstraction for the asm keyword.
    */
    #define SBASE_ASM_KEYWORD  __asm

   /**
    * @brief Compiler abstraction for the naked qualifier
    */
#if (SAFETY_BASE_PLATFORM_ARM == SAFETY_BASE_ARMV8_AARCH64)
    #define SBASE_NAKED
#else
    #define SBASE_NAKED __attribute__((naked))
#endif

    /**
     * @brief Compiler abstraction for MIMX_SAF Fault Injection tests
    */
    #ifdef SBASE_ENABLE_FAULT_INJECTION
    #define SBASE_PUT_IN_QUOTES(x) #x
    #define SBASE_FAULT_INJECTION_POINT(label) SBASE_ASM_KEYWORD(SBASE_PUT_IN_QUOTES(label:\n))
    #else
    #define SBASE_FAULT_INJECTION_POINT(label)
    #endif

#endif /* #ifdef _LINARO_C_MIMX95XX_ */

/**************************************** IAR *****************************************************/
#ifdef _IAR_C_MIMX95XX_
    /**
    * @brief Compiler abstraction for the asm keyword.
    */
    #define SBASE_ASM_KEYWORD  __asm

   /**
    * @brief Compiler abstraction for the naked qualifier
    */
    #define SBASE_NAKED __attribute__((naked))

    /**
     * @brief Compiler abstraction for MIMX_SAF Fault Injection tests
    */
    #ifdef SBASE_ENABLE_FAULT_INJECTION
    #define SBASE_PUT_IN_QUOTES(x) #x
    #define SBASE_FAULT_INJECTION_POINT(label) SBASE_ASM_KEYWORD(SBASE_PUT_IN_QUOTES(label::\n))
    #else
    #define SBASE_FAULT_INJECTION_POINT(label)
    #endif

#endif /* #ifdef _IAR_C_MIMX95XX_ */

/* check that the compiler used is supported (otherwise some defines might not exist) */
#ifndef _GREENHILLS_C_MIMX95XX_
  #ifndef _DIABDATA_C_MIMX95XX_
    #ifndef _LINARO_C_MIMX95XX_
      #ifndef _IAR_C_MIMX95XX_
        #error "Unsupported compiler. Compiler abstraction needs to be updated to use this compiler."

        /**
         * @brief Compiler abstraction for MIMX_SAF Fault Injection tests
        */
        #ifdef SBASE_ENABLE_FAULT_INJECTION
        #define SBASE_PUT_IN_QUOTES(x) #x
        #define SBASE_FAULT_INJECTION_POINT(label) SBASE_ASM_KEYWORD(SBASE_PUT_IN_QUOTES(label:\n))
        #else
        #define SBASE_FAULT_INJECTION_POINT(label)
        #endif

      #endif
    #endif
  #endif
#endif

#define AUTOSAR_OS_NOT_USED 1
#if defined(AUTOSAR_OS_NOT_USED)
    #if defined (USE_SW_VECTOR_MODE)
        /**
        * @brief Compiler abstraction for creating an interrupt handler if no OS is present.
        */
        #define SBASE_ISR(IsrName)       void IsrName(void)
    #else
        /**
        * @brief Compiler abstraction for creating an interrupt handler if no OS is present.
        */
        #define SBASE_ISR(IsrName)       INTERRUPT_FUNC void IsrName(void)

    #endif /*USE_SW_VECTOR_MODE*/

    /**
    * @brief Compiler abstraction for returning from an ISR if no OS is present.
    */
    #define SBASE_EXIT_INTERRUPT()

    #if (SAFETY_BASE_PLATFORM_ARM == SAFETY_BASE_ARMV8_AARCH64)
        /* for AARCH64 bit */
        #define sBase_SuspendAllInterrupts() SBASE_ASM_KEYWORD(" msr DAIFSet,#0xf")
        /* for AARCH64 bit */
        #define sBase_ResumeAllInterrupts() SBASE_ASM_KEYWORD(" msr DAIFClr,#0xf")
    #else
        /* for AARCH32 bit ARM/THUMB instructions */
        #define sBase_SuspendAllInterrupts() SBASE_ASM_KEYWORD(" cpsid i")

        /* for AARCH32 bit ARM/THUMB instructions */
        #define sBase_ResumeAllInterrupts() SBASE_ASM_KEYWORD(" cpsie i")
    #endif
#else
    #include "Os.h"

    /**
    * @brief Compiler abstraction for creating an interrupt handler if OS is present.
    */
    #define SBASE_ISR                   ISR

    /**
    * @brief Compiler abstraction for returning from an ISR if OS is present.
    */
    #define SBASE_EXIT_INTERRUPT()

    /* Suspend interrupts */
    #define sBase_SuspendAllInterrupts() SuspendAllInterrupts()

    /* Resume interrupts */
    #define sBase_ResumeAllInterrupts() ResumeAllInterrupts()
#endif


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (SAFETY_BASE_CPU_TYPE == CPU_TYPE_64)
       /**
       * @brief size of pointer type. on CPU_TYPE_64, the size is 64bits.
       */
       typedef uint64 sBase_PointerSizeType;
#elif (SAFETY_BASE_CPU_TYPE == CPU_TYPE_32)
       /**
       * @brief size of pointer type. on CPU_TYPE_32, the size is 32bits.
       */
       typedef uint32 sBase_PointerSizeType;
#elif (SAFETY_BASE_CPU_TYPE == CPU_TYPE_16)
       /**
       * @brief size of pointer type. on CPU_TYPE_16, the size is 32bits.
       */
       typedef uint32 sBase_PointerSizeType;
#endif

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*SBASE_H*/

/** @} */
