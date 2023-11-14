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
 * @addtogroup LMM_CONFIG
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the configuration structures for Logical
 * Machine Manager.
 */
/*==========================================================================*/

#ifndef LMM_CONFIG_H
#define LMM_CONFIG_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/*! Max number of start/stop arguments */
#define LMM_MAX_ARG  2U

/*!
 * @name LMM safety classifications
 */
/** @{ */
#define LMM_SAFE_TYPE_NSEENV  0U  /*!< Non-safe agent (NS-EENV) */
#define LMM_SAFE_TYPE_FEENV   1U  /*!< Foundation agent (F-EENV) */
#define LMM_SAFE_TYPE_SEENV   2U  /*!< Safe agent (S-EENV) */
/** @} */

/*!
 * @name LMM Start/stop IDs
 */
/** @{ */
#define LMM_SS_PD    0U  /*!< Power command */
#define LMM_SS_PERF  1U  /*!< Performance command */
#define LMM_SS_CLK   2U  /*!< Clock command */
#define LMM_SS_CPU   3U  /*!< CPU command */
/** @} */

/* Types */

/*!
 * LMM config structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    uint32_t start;                    /*!< Start index */
    uint32_t stop;                     /*!< Stop index */
    uint32_t rtime;                    /*!< Relative start time */
    string name;                       /*!< Name of LM */
    uint8_t rpcType;                   /*!< RPC type */
    uint8_t rpcInst;                   /*!< RPC instance */
    uint8_t safeType;                  /*!< Safety classification */
    uint8_t boot[SM_LM_NUM_MSEL];      /*!< Boot order of LM */
    uint8_t bootSkip[SM_LM_NUM_MSEL];  /*!< Skip boot in no image */
} lmm_config_t;

/*!
 * LMM start structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    uint64_t arg[LMM_MAX_ARG];  /*!< Arguments */
    uint32_t rsrc;              /*!< Resource */
    uint8_t lmId;               /*!< LM ID */
    uint8_t mSel;               /*!< Associated mode select */
    uint8_t ss;                 /*!< Start command */
    uint8_t numArg;             /*!< Argument count */
} lmm_start_t;

/*!
 * LMM stop structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    uint32_t rsrc;  /*!< Resource */
    uint8_t lmId;   /*!< LM ID */
    uint8_t mSel;   /*!< Associated mode select */
    uint8_t ss;     /*!< Stop command */
} lmm_stop_t;

/*!
 * LMM fault structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    uint32_t reaction;  /*!< Fault reaction */
    uint32_t lm;        /*!< Target LM */
} lmm_fault_t;

/* Global constant data */

/*! LM config */
extern const lmm_config_t g_lmmConfig[];

#endif /* LMM_CONFIG_H */

/** @} */

