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
 * @addtogroup TEST
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing common API items for SCMI unit tests.
 */
/*==========================================================================*/

#ifndef TEST_SCMI_H
#define TEST_SCMI_H

/* Includes */

#include <stdlib.h>
#include "test.h"
#include "test_config.h"
#include "config_test.h"
#include "scmi.h"

/* Defines */

/*! SCMI base protocol version */
#define SCMI_BASE_PROT_VER      0x20001U
/*! SCMI power protocol version */
#define SCMI_POWER_PROT_VER     0x30001U
/*! SCMI system protocol version */
#define SCMI_SYSTEM_PROT_VER    0x20001U
/*! SCMI performance protocol version */
#define SCMI_PERF_PROT_VER      0x40000U
/*! SCMI clock protocol version */
#define SCMI_CLOCK_PROT_VER     0x30000U
/*! SCMI sensor protocol version */
#define SCMI_SENSOR_PROT_VER    0x30001U
/*! SCMI reset protocol version */
#define SCMI_RESET_PROT_VER     0x30001U
/*! SCMI voltage protocol version */
#define SCMI_VOLT_PROT_VER      0x20001U
/*! SCMI pin control protocol version */
#define SCMI_PINCTRL_PROT_VER   0x10000U
/*! SCMI LMM protocol version */
#define SCMI_LMM_PROT_VER       0x10000U
/*! SCMI BBM protocol version */
#define SCMI_BBM_PROT_VER       0x10000U
/*! SCMI CPU protocol version */
#define SCMI_CPU_PROT_VER       0x10000U
/*! SCMI FuSa protocol version */
#define SCMI_FUSA_PROT_VER      0x10000U
/*! SCMI misc protocol version */
#define SCMI_MISC_PROT_VER      0x10000U

/* Types */

/* Functions */

#endif /* TEST_SCMI_H */

/** @} */

