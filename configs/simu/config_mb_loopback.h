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
 * @addtogroup CONFIG_SIMU
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing configuration info for the MB_LOOPBACK.
 */
/*==========================================================================*/

#ifndef CONFIG_MB_LOOPBACK_H
#define CONFIG_MB_LOOPBACK_H

/* Includes */

#include "config_user.h"
#include "mb_loopback_config.h"

/* Defines */

/*--------------------------------------------------------------------------*/
/* LM0 MB_LOOPBACK Config (SM)                                              */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* LM1 MB_LOOPBACK Config (M7)                                              */
/*--------------------------------------------------------------------------*/

/*! Config for LOOPBACK0 MB */
#define SM_MB_LOOPBACK0_CONFIG \
    { \
        .xportType[0] = SM_XPORT_SMT, \
        .xportChannel[0] = 0U, \
        .xportType[1] = SM_XPORT_SMT, \
        .xportChannel[1] = 1U, \
        .xportType[2] = SM_XPORT_SMT, \
        .xportChannel[2] = 2U, \
    }

/*--------------------------------------------------------------------------*/
/* LM2 MB_LOOPBACK Config (AP)                                              */
/*--------------------------------------------------------------------------*/

/*! Config for LOOPBACK1 MB */
#define SM_MB_LOOPBACK1_CONFIG \
    { \
        .xportType[0] = SM_XPORT_SMT, \
        .xportChannel[0] = 3U, \
        .xportType[1] = SM_XPORT_SMT, \
        .xportChannel[1] = 4U, \
    }

/*! Config for LOOPBACK2 MB */
#define SM_MB_LOOPBACK2_CONFIG \
    { \
        .xportType[0] = SM_XPORT_SMT, \
        .xportChannel[0] = 5U, \
        .xportType[1] = SM_XPORT_SMT, \
        .xportChannel[1] = 6U, \
    }

/*--------------------------------------------------------------------------*/
/* LM3 MB_LOOPBACK Config (TEST)                                            */
/*--------------------------------------------------------------------------*/

/*! Config for LOOPBACK3 MB */
#define SM_MB_LOOPBACK3_CONFIG \
    { \
        .xportType[0] = SM_XPORT_SMT, \
        .xportChannel[0] = 7U, \
        .xportType[1] = SM_XPORT_SMT, \
        .xportChannel[1] = 8U, \
    }

/*--------------------------------------------------------------------------*/
/* MB LOOPBACK Config                                                       */
/*--------------------------------------------------------------------------*/

/*! Config for number of LOOPBACK MB */
#define SM_NUM_MB_LOOPBACK  4U

/*! Config data array for LOOPBACK MB */
#define SM_MB_LOOPBACK_CONFIG_DATA \
    SM_MB_LOOPBACK0_CONFIG, \
    SM_MB_LOOPBACK1_CONFIG, \
    SM_MB_LOOPBACK2_CONFIG, \
    SM_MB_LOOPBACK3_CONFIG

#endif /* CONFIG_MB_LOOPBACK_H */

/** @} */

