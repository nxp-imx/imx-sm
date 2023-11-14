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
 * @addtogroup RPC_SMT
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the configuration structures for the Shared
 * Memory Transport (SMT).
 */
/*==========================================================================*/

#ifndef RPC_SMT_CONFIG_H
#define RPC_SMT_CONFIG_H

/* Includes */

#include "sm.h"

/* Defines */

/*!
 * @name SMT CRC types
 *
 * Types of CRC algorithms that can be configured for a channel (see
 * rpc_smt_chn_config_t).
 */
/** @{ */
/*! No CRC */
#define SM_SMT_CRC_NONE    0U
/*! Simple and fast 32-bit exclusive-OR sum */
#define SM_SMT_CRC_XOR     1U
/*! J1850 standard CRC */
#define SM_SMT_CRC_J1850   2U
/*! CRC32 standard CRC */
#define SM_SMT_CRC_CRC32   3U
/** @} */

/* Types */

/*!
 * SMT channel config structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    uint8_t rpcType;     /*!< RPC type to link */
    uint8_t rpcChannel;  /*!< RPC channel to link */
    uint8_t mbType;      /*!< Mailbox type to link */
    uint8_t mbInst;      /*!< Mailbox instance to link */
    uint8_t mbDoorbell;  /*!< Mailbox doorbell to link */
    uint8_t crc;         /*!< CRC algorithm to use for this channel */
} rpc_smt_chn_config_t;

#endif /* RPC_SMT_CONFIG_H */

/** @} */

