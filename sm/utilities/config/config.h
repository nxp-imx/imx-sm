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
 * @addtogroup UTIL
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the configuration utility functions.
 */
/*==========================================================================*/

#ifndef CONFIG_H
#define CONFIG_H

/* Includes */

#include "sm.h"

/* Defines */

/*!
 * @name Config sequence bitfield macros
 */
/** @{ */
#define SM_CFG_OT_SHIFT     0U           /*!< Shift for type */
#define SM_CFG_OT_MASK      0x00000003U  /*!< Mask for type */
#define SM_CFG_OC_SHIFT     28U          /*!< Shift for code */
#define SM_CFG_OC_MASK      0xF0000000U  /*!< Mask for code */
#define SM_CFG_OPL_SHIFT    20U          /*!< Shift for literal */
#define SM_CFG_OPL_MASK     0x0FF00000U  /*!< Mask for literal */
#define SM_CFG_OPA_MASK     0x000FFFFCU  /*!< Mask for address */
/** @} */

/*!
 * @name Config sequence types
 */
/** @{ */
#define SM_CFG_OT_BASE     0x0UL      /*!< Base type */
#define SM_CFG_OT_ABS      0x1UL      /*!< Absolute type */
/** @} */

/*!
 * @name Config sequence opcodes
 */
/** @{ */
/*! End of sequence */
#define SM_CFG_OC_END       0x0UL
/*! Write operation */
#define SM_CFG_OC_WRITE     0x1UL
/*! Conditional write operation */
#define SM_CFG_OC_CWRITE    0x2UL
/*! Fill operation */
#define SM_CFG_OC_FILL      0x3UL
/*! Zero operation */
#define SM_CFG_OC_ZERO      0x4UL
/*! Repeat operation */
#define SM_CFG_OC_REPEAT    0x5UL
/** @} */

/*! End of sequence */
#define SM_CFG_END          (SM_CFG_OC_END << SM_CFG_OC_SHIFT)

/*! Repeat previous sequence */
#define SM_CFG_RP(A)        (SM_CFG_OC_REPEAT << SM_CFG_OC_SHIFT) \
    | (((A) &SM_CFG_OPA_MASK))

/*! Write a 32-bit to an absolute address */
#define SM_CFG_WA(A)        (SM_CFG_OT_ABS << SM_CFG_OT_SHIFT) \
    | (((A) &~SM_CFG_OT_MASK))

/*! Write multiple 32-bit values */
#define SM_CFG_WN(A, L)     (SM_CFG_OC_WRITE << SM_CFG_OC_SHIFT) \
    | ((L) << SM_CFG_OPL_SHIFT) | (((A) &SM_CFG_OPA_MASK))

/*! Write a 32-bit */
#define SM_CFG_W1(A)        (SM_CFG_OC_WRITE << SM_CFG_OC_SHIFT) \
    | (1U << SM_CFG_OPL_SHIFT) | (((A) &SM_CFG_OPA_MASK))

/*! Conditionly write multiple 32-bit values */
#define SM_CFG_CN(A, L)     (SM_CFG_OC_CWRITE << SM_CFG_OC_SHIFT) \
    | ((L) << SM_CFG_OPL_SHIFT) | (((A) &SM_CFG_OPA_MASK))

/*! Conditionly write a 32-bit value */
#define SM_CFG_C1(A)        (SM_CFG_OC_CWRITE << SM_CFG_OC_SHIFT) \
    | (1U << SM_CFG_OPL_SHIFT) | (((A) &SM_CFG_OPA_MASK))

/*! Fill multiple words with a 32-bit */
#define SM_CFG_FN(A, L)     (SM_CFG_OC_FILL << SM_CFG_OC_SHIFT) \
    | ((L) << SM_CFG_OPL_SHIFT) | (((A) &SM_CFG_OPA_MASK))

/*! Zero multiple 32-bit words */
#define SM_CFG_ZN(A, L)     (SM_CFG_OC_ZERO << SM_CFG_OC_SHIFT) \
    | ((L) << SM_CFG_OPL_SHIFT) | (((A) &SM_CFG_OPA_MASK))

/*! Zero one 32-bit word */
#define SM_CFG_Z1(A)        (SM_CFG_OC_ZERO << SM_CFG_OC_SHIFT) \
    | (1U << SM_CFG_OPL_SHIFT) | (((A) &SM_CFG_OPA_MASK))

/* Types */

/* Global variables */

/* Functions */

/*!
 * @name Config functions
 * @{
 */

/*!
 * Set config conditional flag.
 *
 * @param[in]     cond      False to skip conditional commands
 *
 * This function sets the conditional flag. True will cause conditional
 * commands to be executed, flash will skip them.
 */
void CONFIG_Condition(bool cond);

/*!
 * Load a configuration array.
 *
 * @param[in]     base      Base pointer
 * @param[in]     config    Pointer to command array
 *
 * This function will process and load an array of configuration
 * commands. The \a base address is used for all relative (base) command
 * types.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if array completely loaded without error.
 * - ::SM_ERR_NOT_FOUND: if a command code is invalid.
 * - ::SM_ERR_INVALID_PARAMETERS: if a command parameter is invalid.
 */
int32_t CONFIG_Load(const uint32_t *base, const uint32_t *config);

/** @} */

#endif /* CONFIG_H */

/** @} */

