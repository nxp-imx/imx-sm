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
 * @addtogroup RPC_SCMI
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the configuration structures for the System
 * Control and Management Interface (SCMI) clock protocol.
 */
/*==========================================================================*/

#ifndef RPC_SCMI_CONFIG_H
#define RPC_SCMI_CONFIG_H

/* Includes */

#include "sm.h"
#include "config_lmm.h"
#include "dev_sm_api.h"

/* Defines */

/*!
 * @name SCMI channel types
 */
/** @{ */
#define SM_SCMI_CHN_A2P           0U  /*!< A2P channel */
#define SM_SCMI_CHN_A2P_FAST      1U  /*!< A2P fast channel */
#define SM_SCMI_CHN_P2A           2U  /*!< P2A channel */
#define SM_SCMI_CHN_P2A_NOTIFY    3U  /*!< P2A channel for notifications */
#define SM_SCMI_CHN_P2A_PRIORITY  4U  /*!< P2A channel for priotiy
                                           notifications */
/** @} */

/*!
 * @name SCMI sequence ordering
 */
/** @{ */
#define SM_SCMI_SEQ_NONE   0U    /*!< No sequence required */
#define SM_SCMI_SEQ_TOKEN  1U    /*!< Sequence required in token */
/** @} */

/*!
 * @name SCMI permission attributes
 */
/** @{ */
#define SM_SCMI_PERM_NONE       0U    /*!< No access */
#define SM_SCMI_PERM_GET        1U    /*!< Allow to read */
#define SM_SCMI_PERM_NOTIFY     2U    /*!< Allow to request notifications */
#define SM_SCMI_PERM_SET        3U    /*!< Allow to set (aggregated) */
#define SM_SCMI_PERM_PRIV       4U    /*!< Privileged access (one per LM) */
#define SM_SCMI_PERM_EXCLUSIVE  5U    /*!< Exclusive access (system) */
#define SM_SCMI_PERM_ALL        255U  /*!< Full access */
/** @} */

/* Types */

/*!
 * SCMI channel config structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    uint8_t agentId;      /*!< Agent ID */
    uint8_t type;         /*!< Type, A2P, P2A, P2A_NOTIFY */
    uint8_t xportType;    /*!< Transport type */
    uint8_t xportChannel; /*!< Transport channel */
    uint8_t sequence;     /*!< Sequence type */
} scmi_chn_config_t;

/*!
 * SCMI agent config structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    string name;                         /*!< Agent name */
    uint8_t domId;                       /*!< Domain ID */
    uint8_t secure;                      /*!< Security state */
    uint8_t scmiInst;                    /*!< SCMI instance */
    uint8_t basePerms[SM_NUM_BASE];      /*!< Base protocol permissions */
    uint8_t pdPerms[SM_NUM_POWER];       /*!< Power protocol permissions */
    uint8_t sysPerms;                    /*!< System protocol permission */
    uint8_t perfPerms[SM_NUM_PERF];      /*!< Perf protocol permissions */
    uint8_t clkPerms[SM_NUM_CLOCK];      /*!< Clock protocol permissions */
    uint8_t sensorPerms[SM_NUM_SENSOR];  /*!< Sensor protocol permissions */
    uint8_t rstPerms[SM_NUM_RESET];      /*!< Reset protocol permissions */
    uint8_t voltPerms[SM_NUM_VOLT];      /*!< Voltage protocol permissions */
    uint8_t lmmPerms[SM_NUM_LM];         /*!< LMM protocol permissions */
    uint8_t gprPerms[SM_NUM_GPR];        /*!< BBM protocol GPR permissions */
    uint8_t rtcPerms[SM_NUM_RTC];        /*!< BBM protocol RTC permissions */
    uint8_t buttonPerms[SM_NUM_BUTTON];  /*!< BBM protocol button permissions */
    uint8_t cpuPerms[SM_NUM_CPU];        /*!< CPU protocol permissions */
    uint8_t perlpiPerms[SM_NUM_PERLPI];  /*!< CPU protocol peripheral permissions */
    uint8_t pinPerms[SM_NUM_PIN];        /*!< Pin control protocol permissions */
    uint8_t daisyPerms[SM_NUM_DAISY];    /*!< Pin control protocol daisy permissions */
    uint8_t ctrlPerms[SM_NUM_CTRL];      /*!< Control protocol permissions */
    uint8_t faultPerms[SM_NUM_FAULT];    /*!< FuSa protocol fault permissions */
    uint8_t crcPerms[SM_NUM_CRC];        /*!< FuSa protocol CRC permissions */
    uint8_t fusaPerms;                   /*!< FuSa protocol permission */
} scmi_agnt_config_t;

/*!
 * SCMI instance config structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    uint32_t lmId;       /*!< Logical machine ID */
    uint8_t numAgents;   /*!< Number of agents */
    uint8_t firstAgent;  /*!< First agent in agent array */
} scmi_config_t;

/* Global constant data */

/*! SCMI channel config */
extern const scmi_chn_config_t g_scmiChannelConfig[];

/*! SCMI agent config */
extern const scmi_agnt_config_t g_scmiAgentConfig[];

/*! SCMI instance config */
extern const scmi_config_t g_scmiConfig[];

#endif /* RPC_SCMI_CONFIG_H */

/** @} */

