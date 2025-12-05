/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_DEF_H
#define FSL_DEF_H

#include <limits.h>

/*!
 * @addtogroup ksdk_common
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! Macro to define unsigned char max value */
#define U8_MAX         255U

/*! Macro to define signed short max value */
#define I16_MAX        32767

/*! Macro to define 64-bit 2-gigabyte int */
#define I64_2GB        2147483647LL

/*! Macro to define 32-bit 2-gigabyte unsigned */
#define U32_2GB        2147483647UL

/*! Macro to define MAX shift range of U64 */
#define UINT64_MAX_SHIFT 63U

/*! Macro to convert to a U8 */
#define U8(X)          ((uint8_t)((X) & 0xFFU))

/*! Macro to convert to a U16 */
#define U16(X)         ((uint16_t)((X) & 0xFFFFU))

/*! Macro to convert to a U32 */
#define U32(X)         ((uint32_t)((X) & 0xFFFFFFFFU))

/*! Macro to convert to a U64 */
#define U64(X)         ((uint64_t)(X))

/*! Macro to convert a U64 to a U32 */
#define U64_U32(X)     ((uint32_t)(((uint64_t) (X)) & 0xFFFFFFFFULL))

/*! Macro to convert a U64 to a U8 */
#define U64_U8(X)      ((uint8_t)(((uint64_t) (X)) & 0xFFULL))

/*! Macro to convert a I64 to a I32 */
#define I64_I32(X)     ((int32_t)(((int64_t) (X)) & 0x7FFFFFFFLL))

/*! Macro to convert a I64 to a I16 */
#define I64_I16(X)     ((int16_t)(((int64_t) (X)) & 0x7FFFLL))

/*! Macro to convert a U32 to a U16 */
#define U32_U16(X)     ((uint16_t)(((uint64_t) (X)) & 0xFFFFUL))

/*! Macro to convert a U32 to a U8 */
#define U32_U8(X)      ((uint8_t)(((uint32_t) (X)) & 0xFFUL))

/*! Macro to convert a U32 to a I32 */
#define U32_I32(X)     ((int32_t)(((uint32_t) (X)) & 0x7FFFFFFFUL))

/*! Macro to get upper 32 bits of an unsigned 64-bit value */
#define UINT64_H(X)    ((uint32_t)((((uint64_t) (X)) >> 32U) & 0xFFFFFFFFULL))

/*! Macro to get lower 32 bits of an unsigned 64-bit value */
#define UINT64_L(X)    ((uint32_t)(((uint64_t) (X)) & 0xFFFFFFFFULL))

/*! Macro to get upper 32 bits of a signed 64-bit value */
#define INT64_H(X)     ((int32_t)((((uint64_t) (X)) >> 32U) & 0xFFFFFFFFULL))

/*! Macro to get lower 32 bits of a signed 64-bit value */
#define INT64_L(X)     ((int32_t)(((uint64_t) (X)) & 0xFFFFFFFFULL))

/*! Macro to check the sign of long long int value is negative */
#define CHECK_I64_POSITIVE(X)  ((int64_t)(X) >= 0)

/*! Macro to check the sign of int value is positive */
#define CHECK_I32_POSITIVE(X)  ((int32_t)(X) >= 0)

/*! Macro to check the short int variable in int range */
#define CHECK_I64_FIT_I16(X)   ((int64_t)(X) <= I16_MAX)

/*! Macro to check the uint variable in int range */
#define CHECK_U32_FIT_I32(X)   ((uint32_t)(X) <= U32_2GB)

/*! Macro to check the uint variable in uint8_t range */
#define CHECK_U32_FIT_U8(X)   ((uint32_t)(X) <= U8_MAX)

/*! Macro to check the long long int variable in int range */
#define CHECK_I64_FIT_I32(X)   ((int64_t)(X) <= I64_2GB)

/*! Macro to check if all bits in X are covered by mask Y */
#define BITS_FIT_IN_MASK(X, Y) ((((X) &~(Y)) == 0U) ? 1U : 0U)

/*! @} */

#endif /* FSL_DEF_H */

