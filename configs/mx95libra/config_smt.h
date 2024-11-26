/*
** ###################################################################
**
** Copyright 2023-2024 NXP
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
 * @addtogroup CONFIG_MX95LIBRA
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing coniguration info for the SMT.
 */
/*==========================================================================*/

#ifndef CONFIG_SMT_H
#define CONFIG_SMT_H

/* Includes */

#include "rpc_smt_config.h"

/* Defines */

/*--------------------------------------------------------------------------*/
/* LM0 SMT Config (SM)                                                      */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* LM1 SMT Config (M7)                                                      */
/*--------------------------------------------------------------------------*/

/*! Config for SMT channel 0 */
#define SM_SMT_CHN0_CONFIG \
    { \
        .rpcType = SM_RPC_SCMI, \
        .rpcChannel = 0U, \
        .mbType = SM_MB_MU, \
        .mbInst = 0U, \
        .mbDoorbell = 0U, \
        .crc = SM_SMT_CRC_CRC32, \
    }

/*! Config for SMT channel 1 */
#define SM_SMT_CHN1_CONFIG \
    { \
        .rpcType = SM_RPC_SCMI, \
        .rpcChannel = 1U, \
        .mbType = SM_MB_MU, \
        .mbInst = 0U, \
        .mbDoorbell = 1U, \
        .crc = SM_SMT_CRC_CRC32, \
    }

/*! Config for SMT channel 2 */
#define SM_SMT_CHN2_CONFIG \
    { \
        .rpcType = SM_RPC_SCMI, \
        .rpcChannel = 2U, \
        .mbType = SM_MB_MU, \
        .mbInst = 0U, \
        .mbDoorbell = 2U, \
        .crc = SM_SMT_CRC_CRC32, \
    }

/*--------------------------------------------------------------------------*/
/* LM2 SMT Config (AP)                                                      */
/*--------------------------------------------------------------------------*/

/*! Config for SMT channel 3 */
#define SM_SMT_CHN3_CONFIG \
    { \
        .rpcType = SM_RPC_SCMI, \
        .rpcChannel = 3U, \
        .mbType = SM_MB_MU, \
        .mbInst = 1U, \
        .mbDoorbell = 0U, \
    }

/*! Config for SMT channel 4 */
#define SM_SMT_CHN4_CONFIG \
    { \
        .rpcType = SM_RPC_SCMI, \
        .rpcChannel = 4U, \
        .mbType = SM_MB_MU, \
        .mbInst = 1U, \
        .mbDoorbell = 1U, \
    }

/*! Config for SMT channel 5 */
#define SM_SMT_CHN5_CONFIG \
    { \
        .rpcType = SM_RPC_SCMI, \
        .rpcChannel = 5U, \
        .mbType = SM_MB_MU, \
        .mbInst = 2U, \
        .mbDoorbell = 0U, \
    }

/*! Config for SMT channel 6 */
#define SM_SMT_CHN6_CONFIG \
    { \
        .rpcType = SM_RPC_SCMI, \
        .rpcChannel = 6U, \
        .mbType = SM_MB_MU, \
        .mbInst = 2U, \
        .mbDoorbell = 1U, \
    }

/*--------------------------------------------------------------------------*/
/* SMT Config                                                               */
/*--------------------------------------------------------------------------*/

/*! Config for number of SMT channels */
#define SM_NUM_SMT_CHN  7U

/*! Config data array for SMT channels */
#define SM_SMT_CHN_CONFIG_DATA \
    SM_SMT_CHN0_CONFIG, \
    SM_SMT_CHN1_CONFIG, \
    SM_SMT_CHN2_CONFIG, \
    SM_SMT_CHN3_CONFIG, \
    SM_SMT_CHN4_CONFIG, \
    SM_SMT_CHN5_CONFIG, \
    SM_SMT_CHN6_CONFIG

/* Mailbox and CRC types to support */
/*! Config for MB_MU USE */
#define USES_MB_MU
/*! Config for CRC32 CRC USE */
#define USES_CRC_CRC32

#endif /* CONFIG_SMT_H */

/** @} */

