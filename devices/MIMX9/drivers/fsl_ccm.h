/*
 * Copyright 2023-2024 NXP
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

#ifndef _FSL_CCM_H_
#define _FSL_CCM_H_

/*!
 * @addtogroup CCM_driver
 * @{
 */

/*! @file */

/* Includes */
#include "fsl_common.h"

/* Defines */

/* Types */

/* Functions */
bool CCM_RootGetEnable(uint32_t rootIdx);
bool CCM_RootSetEnable(uint32_t rootIdx, bool enable);
uint64_t CCM_RootGetRate(uint32_t rootIdx);
bool CCM_RootSetRate(uint32_t rootIdx, uint64_t rate, uint32_t roundRule);
bool CCM_RootMuxNumInputsGet(uint32_t rootIdx, uint32_t *numMuxInputs);
bool CCM_RootMuxInputGet(uint32_t rootIdx, uint32_t muxIdx,
    uint32_t *muxInput);
bool CCM_RootGetParent(uint32_t rootIdx, uint32_t *sourceIdx);
bool CCM_RootSetParent(uint32_t rootIdx, uint32_t sourceIdx);
bool CCM_RootGetDiv(uint32_t rootIdx, uint32_t *divider);
bool CCM_RootSetDiv(uint32_t rootIdx, uint32_t divider);
bool CCM_GprSelGetEnable(uint32_t gprSelIdx);
uint64_t CCM_GprSelExtGetRate(void);
uint64_t CCM_GprSelGetRate(uint32_t gprSelIdx);
bool CCM_GprSelMuxNumInputsGet(uint32_t gprSelIdx, uint32_t *numMuxInputs);
bool CCM_GprSelMuxInputGet(uint32_t gprSelIdx, uint32_t muxIdx,
    uint32_t *muxInput);
bool CCM_GprSelGetParent(uint32_t gprSelIdx, uint32_t *clkIdx);
bool CCM_GprSelSetParent(uint32_t gprSelIdx, uint32_t clkIdx);
bool CCM_GprValSet(uint32_t gprIdx, uint32_t gprMask, uint32_t gprVal);
bool CCM_LpcgLpmSet(uint32_t lpcgIdx, uint32_t cpuIdx, uint32_t cpuLpmSetting);
bool CCM_LpcgLpmGet(uint32_t lpcgIdx, uint32_t cpuIdx, uint32_t *cpuLpmSetting);

/* Externs */

#endif /* _FSL_CCM_H_ */

/** @} */
