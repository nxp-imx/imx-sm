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
 * @addtogroup MB_MU
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the configuration structures for the MU-based
 * Mailbox (MB_MU).
 */
/*==========================================================================*/

#ifndef MB_MU_CONFIG_H
#define MB_MU_CONFIG_H

/* Includes */

#include "sm.h"

/* Defines */

/*! Size of transport shared memory per channel */
#define SM_MB_MU_BUF_SIZE  128U

/*! Number of general purpose interrupts for doorbells */
#define SM_NUM_MB_MU_DB    4U

/*!
 * Mailbox-MU config structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    uint32_t mu;                            /*!< Index to MU SDK driver */
    uint32_t sma;                           /*!< Shared memory address */
    uint8_t xportType[SM_NUM_MB_MU_DB];     /*!< Linked transport types */
    uint8_t xportChannel[SM_NUM_MB_MU_DB];  /*!< Linked transport channels */
} mb_mu_config_t;

#endif /* MB_MU_CONFIG_H */

/** @} */

