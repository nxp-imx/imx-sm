/**
*   @file    SafetyBase_StdRegMacros.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF SafetyBase - Register access macros for MIMX_SAF.
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
*   Copyright 2011-2016 Freescale Semiconductor, Inc.
*   Copyright 2017-2020, 2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section SafetyBase_StdRegMacros_h_REF_4_9
*     Violates MISRA 2012 Advisory Rule 4.9, A function should be used in preference to a function-like
*     macro.
*     This violation is due to function like macros defined for register operations. Function like
*     macros are used to reduce code complexity.
*/

#ifndef SAFETYBASE_STDREGMACROS_H
#define SAFETYBASE_STDREGMACROS_H

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
#include "Platform_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAFETYBASE_STDREGMACROS_SW_MAJOR_VERSION             0
#define SAFETYBASE_STDREGMACROS_SW_MINOR_VERSION             4
#define SAFETYBASE_STDREGMACROS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF configuration header file are of the same software version */
#if ((SAFETYBASE_STDREGMACROS_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (SAFETYBASE_STDREGMACROS_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (SAFETYBASE_STDREGMACROS_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
#error "Software Version Numbers of SafetyBase_StdRegMacros.h and MIMX_SAF version are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

#ifndef SAFETYBASE_BIT31
    #define SAFETYBASE_BIT31   ((uint32)0x80000000UL)
#else
      #if (SAFETYBASE_BIT31 != 0x80000000UL)
             #error "SAFETYBASE_BIT31 is defined outside SAF and it is value is not 0x80000000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT30
    #define SAFETYBASE_BIT30   ((uint32)0x40000000UL)
#else
      #if (SAFETYBASE_BIT30 != 0x40000000UL)
             #error "SAFETYBASE_BIT30 is defined outside SAF and it is value is not 0x40000000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT29
    #define SAFETYBASE_BIT29   ((uint32)0x20000000UL)
#else
      #if (SAFETYBASE_BIT29 != 0x20000000UL)
             #error "SAFETYBASE_BIT29 is defined outside SAF and it is value is not 0x20000000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT28
    #define SAFETYBASE_BIT28   ((uint32)0x10000000UL)
#else
      #if (SAFETYBASE_BIT28 != 0x10000000UL)
             #error "SAFETYBASE_BIT28 is defined outside SAF and it is value is not 0x10000000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT27
    #define SAFETYBASE_BIT27   ((uint32)0x08000000UL)
#else
      #if (SAFETYBASE_BIT27 != 0x08000000UL)
             #error "SAFETYBASE_BIT27 is defined outside SAF and it is value is not 0x08000000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT26
    #define SAFETYBASE_BIT26   ((uint32)0x04000000UL)
#else
      #if (SAFETYBASE_BIT26 != 0x04000000UL)
             #error "SAFETYBASE_BIT26 is defined outside SAF and it is value is not 0x04000000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT25
    #define SAFETYBASE_BIT25   ((uint32)0x02000000UL)
#else
      #if (SAFETYBASE_BIT25 != 0x02000000UL)
             #error "SAFETYBASE_BIT25 is defined outside SAF and it is value is not 0x02000000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT24
    #define SAFETYBASE_BIT24   ((uint32)0x01000000UL)
#else
      #if (SAFETYBASE_BIT24 != 0x01000000UL)
             #error "SAFETYBASE_BIT24 is defined outside SAF and it is value is not 0x01000000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT23
    #define SAFETYBASE_BIT23   ((uint32)0x00800000UL)
#else
      #if (SAFETYBASE_BIT23 != 0x00800000UL)
             #error "SAFETYBASE_BIT23 is defined outside SAF and it is value is not 0x00800000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT22
    #define SAFETYBASE_BIT22   ((uint32)0x00400000UL)
#else
      #if (SAFETYBASE_BIT22 != 0x00400000UL)
             #error "SAFETYBASE_BIT22 is defined outside SAF and it is value is not 0x00400000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT21
    #define SAFETYBASE_BIT21   ((uint32)0x00200000UL)
#else
      #if (SAFETYBASE_BIT21 != 0x00200000UL)
             #error "SAFETYBASE_BIT21 is defined outside SAF and it is value is not 0x00200000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT20
    #define SAFETYBASE_BIT20   ((uint32)0x00100000UL)
#else
      #if (SAFETYBASE_BIT20 != 0x00100000UL)
             #error "SAFETYBASE_BIT20 is defined outside SAF and it is value is not 0x00100000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT19
    #define SAFETYBASE_BIT19   ((uint32)0x00080000UL)
#else
      #if (SAFETYBASE_BIT19 != 0x00080000UL)
             #error "SAFETYBASE_BIT19 is defined outside SAF and it is value is not 0x00080000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT18
    #define SAFETYBASE_BIT18   ((uint32)0x00040000UL)
#else
      #if (SAFETYBASE_BIT18 != 0x00040000UL)
             #error "SAFETYBASE_BIT18 is defined outside SAF and it is value is not 0x00040000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT17
    #define SAFETYBASE_BIT17   ((uint32)0x00020000UL)
#else
      #if (SAFETYBASE_BIT17 != 0x00020000UL)
             #error "SAFETYBASE_BIT17 is defined outside SAF and it is value is not 0x00020000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT16
    #define SAFETYBASE_BIT16   ((uint32)0x00010000UL)
#else
      #if (SAFETYBASE_BIT16 != 0x00010000UL)
             #error "SAFETYBASE_BIT16 is defined outside SAF and it is value is not 0x00010000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT15
    #define SAFETYBASE_BIT15   ((uint32)0x00008000UL)
#else
      #if (SAFETYBASE_BIT15 != 0x00008000UL)
             #error "SAFETYBASE_BIT15 is defined outside SAF and it is value is not 0x00008000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT14
    #define SAFETYBASE_BIT14   ((uint32)0x00004000UL)
#else
      #if (SAFETYBASE_BIT14 != 0x00004000UL)
             #error "SAFETYBASE_BIT14 is defined outside SAF and it is value is not 0x00004000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT13
    #define SAFETYBASE_BIT13   ((uint32)0x00002000UL)
#else
      #if (SAFETYBASE_BIT13 != 0x00002000UL)
             #error "SAFETYBASE_BIT13 is defined outside SAF and it is value is not 0x00002000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT12
    #define SAFETYBASE_BIT12   ((uint32)0x00001000UL)
#else
      #if (SAFETYBASE_BIT12 != 0x00001000UL)
             #error "SAFETYBASE_BIT12 is defined outside SAF and it is value is not 0x00001000UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT11
    #define SAFETYBASE_BIT11   ((uint32)0x00000800UL)
#else
      #if (SAFETYBASE_BIT11 != 0x00000800UL)
             #error "SAFETYBASE_BIT11 is defined outside SAF and it is value is not 0x00000800UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT10
    #define SAFETYBASE_BIT10   ((uint32)0x00000400UL)
#else
      #if (SAFETYBASE_BIT10 != 0x00000400UL)
             #error "SAFETYBASE_BIT10 is defined outside SAF and it is value is not 0x00000400UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT9
    #define SAFETYBASE_BIT9    ((uint32)0x00000200UL)
#else
      #if (SAFETYBASE_BIT9 != 0x00000200UL)
             #error "SAFETYBASE_BIT9 is defined outside SAF and it is value is not 0x00000200UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT8
    #define SAFETYBASE_BIT8    ((uint32)0x00000100UL)
#else
      #if (SAFETYBASE_BIT8 != 0x00000100UL)
             #error "SAFETYBASE_BIT8 is defined outside SAF and it is value is not 0x00000100UL ".
       #endif
#endif

#ifndef SAFETYBASE_BIT7
    #define SAFETYBASE_BIT7    ((uint32)0x00000080UL)
#else
      #if (SAFETYBASE_BIT7 != 0x00000080UL)
             #error "SAFETYBASE_BIT7 is defined outside SAF and it is value is not 0x00000080UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT6
    #define SAFETYBASE_BIT6    ((uint32)0x00000040UL)
#else
      #if (SAFETYBASE_BIT6 != 0x00000040UL)
             #error "SAFETYBASE_BIT6 is defined outside SAF and it is value is not 0x00000040UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT5
    #define SAFETYBASE_BIT5    ((uint32)0x00000020UL)
#else
      #if (SAFETYBASE_BIT5 != 0x00000020UL)
             #error "SAFETYBASE_BIT5 is defined outside SAF and it is value is not 0x00000020UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT4
    #define SAFETYBASE_BIT4    ((uint32)0x00000010UL)
#else
      #if (SAFETYBASE_BIT4 != 0x00000010UL)
             #error "SAFETYBASE_BIT4 is defined outside SAF and it is value is not 0x00000010UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT3
    #define SAFETYBASE_BIT3    ((uint32)0x00000008UL)
#else
      #if (SAFETYBASE_BIT3 != 0x00000008UL)
             #error "SAFETYBASE_BIT3 is defined outside SAF and it is value is not 0x00000008UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT2
    #define SAFETYBASE_BIT2    ((uint32)0x00000004UL)
#else
      #if (SAFETYBASE_BIT2 != 0x00000004UL)
             #error "SAFETYBASE_BIT2 is defined outside SAF and it is value is not 0x00000004UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT1
    #define SAFETYBASE_BIT1    ((uint32)0x00000002UL)
#else
      #if (SAFETYBASE_BIT1 != 0x00000002UL)
             #error "SAFETYBASE_BIT1 is defined outside SAF and it is value is not 0x00000002UL".
       #endif
#endif

#ifndef SAFETYBASE_BIT0
    #define SAFETYBASE_BIT0    ((uint32)0x00000001UL)
#else
      #if (SAFETYBASE_BIT0 != 0x00000001UL)
             #error "SAFETYBASE_BIT0 is defined outside SAF and it is value is not 0x00000001UL".
       #endif
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief 8 bits memory write macro
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_WRITE8(address, value)        ((*(volatile uint8*)(address))=  (value))
/**
* @brief 16 bits memory write macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_WRITE16(address, value)       ((*(volatile uint16*)(address))= (value))
/**
* @brief 32 bits memory write macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_WRITE32(address, value)       ((*(volatile uint32*)(address))= (value))


/**
* @brief 8 bits memory read macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_READ8(address)                (*(volatile uint8*)(address))
/**
* @brief 16 bits memory read macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_READ16(address)               (*(volatile uint16*)(address))
/**
* @brief 32 bits memory read macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_READ32(address)               (*(volatile uint32*)(address))

/**
* @brief 8 bits indexed memory write macro. Index i must have the data type uint32.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_AWRITE8(address, i, value)     (SAFETYBASE_REG_WRITE8 ((address)+(i), (value)))
/**
* @brief 16 bits indexed memory write macro. Index i must have the data type uint32.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_AWRITE16(address, i, value)    (SAFETYBASE_REG_WRITE16((address)+((uint32)((i)<<1U)), (value)))
/**
* @brief 32 bits indexed memory write macro. Index i must have the data type uint32.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_AWRITE32(address, i, value)    (SAFETYBASE_REG_WRITE32((address)+((uint32)((i)<<2U)), (value)))


/**
* @brief 8 bits indexed memory read macro. Index i must have the data type uint32.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_AREAD8(address, i )            (SAFETYBASE_REG_READ8 ((address)+(i)))
/**
* @brief 16 bits indexed memory read macro. Index i must have the data type uint32.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_AREAD16(address, i)            (SAFETYBASE_REG_READ16((address)+((uint32)((i)<<1U))))
/**
* @brief 32 bits indexed memory read macro. Index i must have the data type uint32.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_AREAD32(address, i)            (SAFETYBASE_REG_READ32((address)+((uint32)((i)<<2U))))


/**
* @brief 8 bits bits clearing macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_BIT_CLEAR8(address, mask)     ((*(volatile uint8*)(address))&= (~(mask)))
/**
* @brief 16 bits bits clearing macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_BIT_CLEAR16(address, mask)    ((*(volatile uint16*)(address))&= (~(mask)))
/**
* @brief 32 bits bits clearing macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32*)(address))&= (~(mask)))


/**
* @brief 8 bits bits getting macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_BIT_GET8(address, mask)       ((*(volatile uint8*)(address))& (mask))
/**
* @brief 16 bits bits getting macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_BIT_GET16(address, mask)      ((*(volatile uint16*)(address))& (mask))
/**
* @brief 32 bits bits getting macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_BIT_GET32(address, mask)      ((*(volatile uint32*)(address))& (mask))


/**
* @brief 8 bits bits setting macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_BIT_SET8(address, mask)       ((*(volatile uint8*)(address))|= (mask))
/**
* @brief 16 bits bits setting macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_BIT_SET16(address, mask)      ((*(volatile uint16*)(address))|= (mask))
/**
* @brief 32 bits bits setting macro.
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_BIT_SET32(address, mask)      ((*(volatile uint32*)(address))|= (mask))


/**
* @brief 8 bit clear bits and set with new value
* @note In the current implementation, it is caller's (user's) responsability to make sure that
*       value has only "mask" bits set - (value&~mask)==0
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_RMW8(address, mask, value)    (SAFETYBASE_REG_WRITE8((address), ((SAFETYBASE_REG_READ8(address)& ((uint8)~(mask)))| (value))))
/**
* @brief 16 bit clear bits and set with new value
* @note In the current implementation, it is caller's (user's) responsability to make sure that
*       value has only "mask" bits set - (value&~mask)==0
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_RMW16(address, mask, value)   (SAFETYBASE_REG_WRITE16((address), ((SAFETYBASE_REG_READ16(address)& ((uint16)~(mask)))| (value))))
/**
* @brief 32 bit clear bits and set with new value
* @note In the current implementation, it is caller's (user's) responsability to make sure that
*       value has only "mask" bits set - (value&~mask)==0
* @violates @ref SafetyBase_StdRegMacros_h_REF_4_9 MISRA 2012 Advisory Rule 19.7, A function should be used in
* preference to a function-like macro.
*/
#define SAFETYBASE_REG_RMW32(address, mask, value)   (SAFETYBASE_REG_WRITE32((address), ((SAFETYBASE_REG_READ32(address)& ((uint32)~(mask)))| (value))))


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* #ifndef SAFETYBASE_STDREGMACROS_H */

/** @} */
