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

/*==========================================================================*/
/*!
 * @addtogroup MX9_SRC_driver
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the SRC (System Reset Controller) driver.
 */
/*==========================================================================*/

#ifndef FSL_SRC_H
#define FSL_SRC_H

/* Includes */
#include "fsl_common.h"


/* Defines */

/*! Ignore A55 ack, raise a55_hdsk done to GPC when counter is reached */
#define SRC_MIX_A55_HDSK_ACK_IGNORE         0x2U

/*! Not use counter, raise a55_hdsk done to GPC once get A55 ack */
#define SRC_MIX_A55_HDSK_ACK_WAIT           0x0U

/* Types */

/* Functions */

/*!
 * @name SRC (System Reset Controller) driver functions
 * @{
 */

/*!
 * Initialize SRC MIX LPM configuration and ISOs
 *
 * @param[in]   srcMixIdx   SRC MIX identifier
 *
 * This function performs initial configuration (AUTHEN_CTRL, LPM, ISO,
 * Retention etc.) for SRC MIX.
 *
 * @return Returns true if the configuration is applied successfully,
 *         otherwise false.
 */
bool SRC_MixInit(uint32_t srcMixIdx);

/*!
 * Configure SRC MIX LPM mode (SW vs HW/GPC control)
 *
 * @param[in]   srcMixIdx   SRC MIX identifier
 * @param[in]   gpcLpmCtrl  Flag for MIX LPM mode (0=SW, 1=HW)
 *
 * This function sets SRC MIX LPM mode (SW vs HW).
 *
 * @return Returns true if the LPM mode is set successfully, otherwise false.
 */
bool SRC_MixLpmModeSet(uint32_t srcMixIdx, bool gpcLpmCtrl);

/*!
 * Configure CPU LPM response for specified power domain
 *
 * @param[in]   srcMixIdx       SRC MIX identifier
 * @param[in]   cpuIdx          CPU identified
 * @param[in]   cpuLpmSetting   CPU LPM setting
 *
 * This function sets CPU LPM setting if the given \a srcMixIdx supports LPM
 * mode.
 *
 * @return Returns true if the LPM setting for CPU is set successfully,
 * otherwise false.
 */
bool SRC_MixCpuLpmSet(uint32_t srcMixIdx, uint32_t cpuIdx,
    uint32_t cpuLpmSetting);

/*!
 * Get CPU LPM response for specified power domain
 *
 * @param[in]   srcMixIdx       SRC MIX identifier
 * @param[in]   cpuIdx          CPU identified
 * @param[out]  cpuLpmSetting   CPU LPM setting
 *
 * This function gets LPM setting for the given CPU from SRC MIX slice.
 *
 * @return Returns true if the LPM setting for CPU is retrieved,
 * otherwise false.
 */
bool SRC_MixCpuLpmGet(uint32_t srcMixIdx, uint32_t cpuIdx,
    uint32_t *cpuLpmSetting);

/*!
 * Configure retention mode of MEM slice
 *
 * @param[in]   srcMixIdx       SRC MIX identifier
 * @param[in]   memRetMask      MEM slices retention mask
 *
 * This function iterates through MEM slices within a MIX (skipping memory
 * slices that are always retained) set in memRetMask and configures their LPM
 * mode to retention mode.
 *
 * @return Returns true if the MEM slices retention mode is set successfully,
 * otherwise false.
 */
bool SRC_MemRetentionModeSet(uint32_t srcMixIdx, uint32_t memRetMask);

/*!
 * Get mask reflecting memory slices within the MIX
 *
 * @param[in]   srcMixIdx       SRC MIX identifier
 * @param[out]  retMask         MEM slices retention mask
 *
 * This function queries the bitmask representing the MEM slice instances
 * within the specified MIX.
 *
 * @return Returns true if the MEM slice bitmask could be queried, otherwise
 *         false.
 */
bool SRC_MemMaskGet(uint32_t srcMixIdx, uint32_t *retMask);

/*!
 * Software-controlled power down of MIX slice
 *
 * @param[in]   srcMixIdx       SRC MIX identifier
 *
 * This function allows caller to execute software controlled power-down
 * sequence using MIX's SLICE_SW_CTRL register. It takes care of setting MIX's
 * LPM mode and various handshakes required to perform software controlled
 * power-down of MIX.
 */
void SRC_MixSoftPowerDown(uint32_t srcMixIdx);

/*!
 * Software-controlled power up of MIX slice
 *
 * @param[in]   srcMixIdx       SRC MIX identifier
 *
 * This function allows caller to execute software controlled power-up
 * sequence using MIX's SLICE_SW_CTRL register. It takes care of setting MIX's
 * LPM mode and various handshakes required to perform software controlled
 * power-up of the MIX.
 *
 * @return Returns true if software controlled power-up executed successfully,
 * otherwise false.
 */
bool SRC_MixSoftPowerUp(uint32_t srcMixIdx);

/*!
 * Check MIX slice power switch status
 *
 * @param[in]   srcMixIdx       SRC MIX identifier
 *
 * This function allows caller to get power switch status of the MIX.
 *
 * @return Returns true if MIX is powered, otherwise false.
 */
bool SRC_MixIsPwrSwitchOn(uint32_t srcMixIdx);

/*!
 * Check if MIX power up sequence is complete
 *
 * @param[in]   srcMixIdx       SRC MIX identifier
 *
 * This function allows caller to get power up sequence completion status of
 * MIX.
 *
 * @return Returns true if MIX power up sequence is completed, otherwise false.
 */
bool SRC_MixIsPwrReady(uint32_t srcMixIdx);

/*!
 * Configure reset signal of MIX slice
 *
 * @param[in]   lineIdx         Reset line identifier
 * @param[in]   resetType       Reset type
 *
 * This function allows caller to configure reset signal of the MIX slice to
 * given \a resetType (DEASSERT/ASSERT/TOGGLE).
 *
 * @return Returns true if reset signal is configured successfully, otherwise
 * false.
 */
bool SRC_MixSetResetLine(uint32_t lineIdx, uint32_t resetType);

/*!
 * Read reset signal of MIX slice
 *
 * @param[in]   lineIdx     Reset line identifier
 * @param[out]  resetType   Reset type
 *
 * This function allows caller to get reset signal of the MIX slice
 * (ASSERTED/DEASSERTED) based on the assert direction of signal.
 *
 * @return Returns true if reset signal if MIX slice is read successfully,
 * otherwise false.
 */
bool SRC_MixGetResetLine(uint32_t lineIdx, uint32_t *resetType);
#ifdef SRC_GEN_SP_ISO_CTRL_COUNT

/*!
 * Update isolation for certain PHYs in MIXes
 *
 * @param[in]   isoMask     ISO mask
 * @param[in]   enable      Enable flag (1 = Set isoMask, 0 = Clear isoMask)
 *
 * This function allows caller to update SRC ISO control.
 */
void SRC_MixIsolationSetup(uint32_t isoMask, bool enable);
#endif

/** @} */

/* Externs */

#endif /* FSL_SRC_H */

/** @} */
