/*
 * Copyright 2024 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FSL_FRO_H
#define FSL_FRO_H

/* Includes */

#include "fsl_common.h"

/* Defines */

/* Types */

/*!
 * @brief FRO operation mode.
 */
typedef enum
{
    OPEN_LOOP    = 1U,
    CLOSED_LOOP  = 2U
} FRO_mode;

/*!
 * @brief FRO configuration info.
 */
typedef struct {
    uint32_t outputFreq;
    FRO_mode mode;
    uint32_t trimVal;
} FRO_config_info_t;

/* Functions */

bool FRO_SetDefaultConfig(const FRO_config_info_t defConfig);
bool FRO_GetDefaultConfig(FRO_config_info_t *config);
bool FRO_SetMode(FRO_mode mode);
bool FRO_GetMode(FRO_mode *mode);
bool FRO_SetTrim(uint32_t trim);
bool FRO_GetTrim(uint32_t *trim);
bool FRO_SetRate(uint32_t rate);
bool FRO_GetRate(uint32_t *rate);
bool FRO_SetEnable(bool enable);
bool FRO_GetEnable(void);

#endif /* FSL_FRO_H */

