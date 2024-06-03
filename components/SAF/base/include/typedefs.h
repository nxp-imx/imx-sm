/**
*   @file    typedefs.h
*   @version 0.4.0
*
*   @brief MIMX_SAF Demo - Typedefs file.
*   @details This file defines all of the data types for the Motorola header file.
*
*   This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup DEMO_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : MIMX_SAF
*   Platform             : CORTEXM
*
*   SW Version           : 0.4.0
*   Build Version        : MIMX9X_SAF_0_4_0
*
*   Copyright 2003 MOTOROLA
*   Copyright 2019-2021, 2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#if defined(__MWERKS__) || /* Metrowerk CodeWarrior */ \
    defined(__GNUC__) || \
    defined(__ghs__)
    #include <stdint.h>

    /* Standard typedefs used by header files, based on ISO C standard */
    typedef volatile int8_t vint8_t;
    typedef volatile uint8_t vuint8_t;

    typedef volatile int16_t vint16_t;
    typedef volatile uint16_t vuint16_t;

    typedef volatile int32_t vint32_t;
    typedef volatile uint32_t vuint32_t;

    typedef volatile int64_t vint64_t;
    typedef volatile uint64_t vuint64_t;

#else

    /* This is needed for compilers that don't have a stdint.h file */
    typedef signed char int8_t;
    typedef unsigned char uint8_t;
    typedef volatile signed char vint8_t;
    typedef volatile unsigned char vuint8_t;

    typedef signed short int16_t;
    typedef unsigned short uint16_t;
    typedef volatile signed short vint16_t;
    typedef volatile unsigned short vuint16_t;

    typedef signed int int32_t;
    typedef unsigned int uint32_t;
    typedef volatile signed int vint32_t;
    typedef volatile unsigned int vuint32_t;
    typedef volatile signed long long vint64_t;
    typedef volatile unsigned long long vuint64_t;

#endif

#endif
