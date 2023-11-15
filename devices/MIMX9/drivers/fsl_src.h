/*
 * Copyright 2023 NXP
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

#ifndef _FSL_SRC_H_
#define _FSL_SRC_H_

/*!
 * @addtogroup SRC_driver
 * @{
 */

/*! @file */

/* Includes */
#include "fsl_common.h"


/* Defines */
#define SRC_MIX_A55_HDSK_ACK_IGNORE         0x2U
#define SRC_MIX_A55_HDSK_ACK_WAIT           0x0U


/* Types */

/* Functions */
bool SRC_MixInit(uint32_t srcMixIdx);
bool SRC_MixLpmModeSet(uint32_t srcMixIdx, bool gpcLpmCtrl);
bool SRC_MixCpuLpmSet(uint32_t srcMixIdx, uint32_t cpuIdx,
    uint32_t cpuLpmSetting);
bool SRC_MixCpuLpmGet(uint32_t srcMixIdx, uint32_t cpuIdx,
    uint32_t *cpuLpmSetting);
bool SRC_MemRetentionModeSet(uint32_t srcMixIdx, uint32_t memRetMask);
bool SRC_MemMaskGet(uint32_t srcMixIdx, uint32_t *retMask);
void SRC_MixSoftPowerDown(uint32_t srcMixIdx);
bool SRC_MixSoftPowerUp(uint32_t srcMixIdx);
bool SRC_MixIsPwrSwitchOn(uint32_t srcMixIdx);
bool SRC_MixIsPwrReady(uint32_t srcMixIdx);
bool SRC_MixSetResetLine(uint32_t lineIdx, uint32_t resetType);
bool SRC_MixGetResetLine(uint32_t lineIdx, uint32_t *resetType);
void SRC_MixIsolationSetup(uint32_t isoMask, bool enable);

/* Externs */

#endif /* _FSL_SRC_H_ */

/** @} */
