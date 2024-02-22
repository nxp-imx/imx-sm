/*
** ###################################################################
**
** Copyright 2023 NXP
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** o Redistributions of source code must retain the above copyright notice, this list
**   of conditions and the following disclaimer.
**
** o Redistributions in binary form must reproduce the above copyright notice, this
**   list of conditions and the following disclaimer in the documentation and/or
**   other materials provided with the distribution.
**
** o Neither the name of the copyright holder nor the names of its
**   contributors may be used to endorse or promote products derived from this
**   software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
** ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
** ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/*!
 * @addtogroup BOOT
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the boot code including main().
 */
/*==========================================================================*/

#ifndef SM_H
#define SM_H

/* Includes */

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "build_info.h"

/* Defines */

/*!
 * @anchor STATUS
 * @name SM error codes
 */
/** @{ */
#define SM_ERR_SUCCESS             (0)     /*!< Successful completion of the command. */
#define SM_ERR_NOT_SUPPORTED       (-1)    /*!< The command or feature is not supported
                                                or is supported but not within the calling
                                                agents view of the platform. */
#define SM_ERR_INVALID_PARAMETERS  (-2)    /*!< One or more parameters passed to the command
                                                are invalid or beyond legal limits. */
#define SM_ERR_DENIED              (-3)    /*!< The caller is not permitted to perform the
                                                specific action, such as accessing a resource
                                                or feature that it is not allowed to use. */
#define SM_ERR_NOT_FOUND           (-4)    /*!< The entity that is being accessed does not exist. */
#define SM_ERR_OUT_OF_RANGE        (-5)    /*!< Requested settings are outside the legal range */
#define SM_ERR_BUSY                (-6)    /*!< The platform is out of resources and thus unable
                                                to process a command. */
#define SM_ERR_COMMS_ERROR         (-7)    /*!< The message could not be correctly transmitted. */
#define SM_ERR_GENERIC_ERROR       (-8)    /*!< The command failed to be processed owing to an
                                                unspecified fault within the platform. */
#define SM_ERR_HARDWARE_ERROR      (-9)    /*!< A hardware error occurred in a platform
                                                component during execution of a command. */
#define SM_ERR_PROTOCOL_ERROR      (-10)   /*!< Returned when the receiver detects that the
                                                caller has violated the protocol specification. */
#define SM_ERR_IN_USE              (-11)   /*!< The resource is currently in use by the platform
                                                or another agent and cannot be operated upon. */
#define SM_ERR_ABORT_ERROR         (-128)  /*!< The message was aborted. */
#define SM_ERR_CRC_ERROR           (-129)  /*!< The received message failed a CRC check. */
#define SM_ERR_MISSING_PARAMETERS  (-130)  /*!< One or more parameters is missing. */
#define SM_ERR_POWER               (-131)  /*!< Power domain dependency violation. */
#define SM_ERR_TEST                (-132)  /*!< Test error. Generally lack of an expected error. */
#define SM_ERR_SEQ_ERROR           (-133)  /*!< Sequence error. The message sent or recv. did not
                                                include the required sequence number. */
#define SM_ERR_LAST                (-134)  /*!< Temp error beyond all valid error codes. */
/** @} */

/*!
 * @name SM mailbox types
 */
/** @{ */
#define SM_MB_NONE      0U      /*!< None */
#define SM_MB_LOOPBACK  1U      /*!< Loopback */
#define SM_MB_MU        2U      /*!< MU */
/** @} */

/*!
 * @name SM transport types
 */
/** @{ */
#define SM_XPORT_NONE  0U  /*!< None */
#define SM_XPORT_SMT   1U  /*!< SMT */
/** @} */

/*!
 * @name SM RPC types
 */
/** @{ */
#define SM_RPC_NONE  0U  /*!< None */
#define SM_RPC_SCMI  1U  /*!< SCMI */
/** @} */

/*!
 * @name SM boot times
 */
/** @{ */
#define SM_BT_START  0U  /*!< Start time */
#define SM_BT_SUB    1U  /*!< Time to subtract */
/** @} */

/*! Macro to get upper 32 bits of an unsigned 64-bit value */
#define SM_UINT64_H(X)  ((uint32_t)((((uint64_t) (X)) >> 32U) & 0x0FFFFFFFFULL))

/*! Macro to get lower 32 bits of an unsigned 64-bit value */
#define SM_UINT64_L(X)  ((uint32_t)(((uint64_t) (X)) & 0x0FFFFFFFFULL))

/*! Macro to get upper 32 bits of a signed 64-bit value */
#define SM_INT64_H(X)  ((int32_t)((((uint64_t) (X)) >> 32U) & 0x0FFFFFFFFULL))

/*! Macro to get lower 32 bits of a signed 64-bit value */
#define SM_INT64_L(X)  ((int32_t)(((uint64_t) (X)) & 0x0FFFFFFFFULL))

/*! Macro to create bit field */
#define BIT8(X)   (((uint8_t) 1U) << (((uint32_t) (X)) % 8UL))

/*! Macro to create bit field */
#define BIT16(X)  (((uint16_t) 1U) << (((uint32_t) (X)) % 16UL))

/*! Macro to create bit field */
#define BIT32(X)  (((uint32_t) 1U) << (((uint32_t) (X)) % 32UL))

/*! Macro to create bit field */
#define BIT64(X)  (((uint64_t) 1U) << (((uint32_t) (X)) % 64UL))

/*! Macro to create word index */
#define WORD8(X)  (((uint32_t) (X)) / 32UL)

/*! Macro for bit array size */
#define BITARRAY_SIZE(X)    ((((X) - 1U) / 8U) + 1U)

/*! Macro to declare a bit array */
#define BITARRAY_DEC(X, Y)  uint8_t (X)[BITARRAY_SIZE(Y)]

/*! Macro to set a bit in a bit array */
#define BITARRAY_SET(X, Y)  (X)[WORD8(Y)] |= BIT8(Y)

/*! Macro to clear a bit in a bit array */
#define BITARRAY_CLR(X, Y)  (X)[WORD8(Y)] &= ~BIT8(Y)

/*! Macro to get a bit in a bit array */
#define BITARRAY_GET(X, Y)  ((X)[WORD8(Y)] & BIT8(Y))

/*! @brief Computes the number of elements in an array. */
#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif

/*!
 * @name Min/max macros
 * @{
 */
#if !defined(MIN)
/*! Macro to find the min of two values */
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#if !defined(MAX)
/*! Macro to find the max of two values */
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif
/** @} */

/*! Magic macro to do a compile time check */
#define COMPILE_ASSERT(X) ((void)sizeof(char[1 - (2 * (!(X)))]))

#if !defined(MONITOR) && !defined(RUN_TEST)
/*! Eliminate printf */
#define printf(...)
#endif

#if defined(MONITOR) || defined(RUN_TEST)
/*! Define PRINTF to print */
#define PRINTF (void) printf
#else
/*! Define PRINTF to void */
#define PRINTF(...)
#endif

/*!
 * @name Register accecss macros
 * @{
 */
/*! Macros for reading register values */
#define Read32(a)     (*(volatile uint32_t *)(a))

/*! Macro for writing register value */
#define Write32(a,v)  (*(volatile uint32_t *)(a) = (v))
/** @} */

/* Types */

/*!
 * This type is used to contain a string of constant characters.
 */
typedef const char *string;

/* Global variables */

/*! Boot times */
extern uint64_t g_bootTime[SM_BT_SUB + 1U];

/* Functions */

/*!
 * Main entry.
 *
 * @param[in]     argc        Number of arguments
 * @param[in]     argv        Array of arguments
 *
 * This function contains the main entry into the SM. It is called from the
 * device specific startup_<device>.S. It initializes the board via
 * BRD_SM_Init(), the LMM via LMM_Init(), and then boots all requested LMs
 * via LMM_Boot().
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int main(int argc, const char * const argv[]);

/*!
 * Report error.
 *
 * @param[in]     status      Status code
 *
 * This function reports an error to the board exit code. That code will
 * record the error information and reset the system.
 */
void SM_Error(int32_t status);

#endif /* SM_H */

/** @} */

