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
 * @addtogroup LMM_CPU
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager CPUs.
 */
/*==========================================================================*/

#ifndef LMM_CPU_H
#define LMM_CPU_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Initialize LMM CPU management.
 *
 * Loads initial boot vectors from ROM.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_CpuInit(void);

/*!
 * Get a CPU name.
 *
 * @param[in]     lmId         LM call is for
 * @param[in]     cpuId        CPU name to get
 * @param[out]    cpuNameAddr  Return pointer to name
 * @param[out]    len          Return max length of all CPU names
 *
 * This function allows the caller to get the name of a CPU.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the name is returned.
 * - others returned by ::SM_CPUNAMEGET
 */
int32_t LMM_CpuNameGet(uint32_t lmId, uint32_t cpuId, string *cpuNameAddr,
    int32_t *len);

/*!
 * Check a CPU boot vector.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     cpuId    Identifier for the CPU
 *
 * Checks to see if a CPU has a boot vector.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_CpuBootCheck(uint32_t lmId, uint32_t cpuId);

/*!
 * Start a CPU.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     cpuId    Identifier for the CPU
 *
 * This function allows the calling agent to start a CPU. This function
 * implicitly powers up the domain containing the CPU. The reset vector is
 * latched on power up and must be set using LMM_CpuResetVectorSet()
 * before calling this function.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the CPU is started
 * - ::SM_ERR_NOT_FOUND: if the CPU is invalid
 * - ::SM_ERR_MISSING_PARAMETERS: if no valid reset vector
 * - others returned by ::SM_CPUSTART
 */
int32_t LMM_CpuStart(uint32_t lmId, uint32_t cpuId);

/*!
 * Hold a CPU.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     cpuId    Identifier for the CPU
 *
 * This function allows the caller to power up a CPU and leave in the hold
 * state. This function implicitly powers up the domain containing the CPU.
 * The reset vector is latched on power up and must be set using
 * LMM_CpuResetVectorSet() before calling this function.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the CPU is held
 * - ::SM_ERR_NOT_FOUND: if the CPU is invalid
 * - ::SM_ERR_MISSING_PARAMETERS: if no valid reset vector
 * - others returned by ::SM_CPUHOLD
 */
int32_t LMM_CpuHold(uint32_t lmId, uint32_t cpuId);

/*!
 * Stop a CPU.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     cpuId    Identifier for the CPU
 *
 * This function stops a CPU.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the CPU is stopped
 * - others returned by ::SM_CPUSTOP
 */
int32_t LMM_CpuStop(uint32_t lmId, uint32_t cpuId);

/*!
 * Set reset vector.
 *
 * @param[in]     lmId         LM call is for
 * @param[in]     cpuId        Identifier for the CPU
 * @param[in]     resetVector  Physical address where the CPU should
 *                             execute from on reset.
 * @param[in]     boot         True to update the boot address
 * @param[in]     start        True to update the start address
 * @param[in]     resume       True to update the resume address
 * @param[in]     table        True if the address is a vector table base
 *
 * Note some CPUs allow the reset vector (the address where the CPU will start
 * execution) to be configured. Other CPUs instead allow the base address of
 * the vector table to be configured.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the reset vector is set
 * - others returned by ::SM_CPURESETVECTORCHECK and ::SM_CPURESETVECTORSET
 */
int32_t LMM_CpuResetVectorSet(uint32_t lmId, uint32_t cpuId,
    uint64_t resetVector, bool boot, bool start, bool resume, bool table);

/*!
 * Reload the start vector for a CPU from the boot vector.
 *
 * @param[in]     lmId         LM call is for
 * @param[in]     cpuId        Identifier for the CPU
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the reset vector is set
 * - ::SM_ERR_NOT_FOUND: if the CPU is invalid
 */
int32_t LMM_CpuResetVectorReset(uint32_t lmId, uint32_t cpuId);

/*!
 * Set a CPU sleep target mode.
 *
 * @param[in]     lmId       LM call is for
 * @param[in]     cpuId      Identifier for the CPU
 * @param[in]     sleepMode  Target sleep mode
 * @param[in]     sleepFlags Sleep mode flags
 *
 * This function sets the sleep mode of a CPU. The CPU will transition to
 * this mode on its next WFI.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the sleep mode is set.
 * - others returned by ::SM_CPUSLEEPMODESET
 */
int32_t LMM_CpuSleepModeSet(uint32_t lmId, uint32_t cpuId,
    uint32_t sleepMode, uint32_t sleepFlags);

/*!
 * Set a CPU IRQ wake mask.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     cpuId    Identifier for the CPU
 * @param[in]     maskIdx  Index of mask to set
 * @param[in]     maskVal  Mask data to set
 *
 * This function sets a mask for CPU IRQ wake sources.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the mask is set.
 * - others returned by ::SM_CPUIRQWAKESET
 */
int32_t LMM_CpuIrqWakeSet(uint32_t lmId, uint32_t cpuId, uint32_t maskIdx,
    uint32_t maskVal);

/*!
 * Set a CPU non-IRQ wake mask.
 *
 * @param[in]     lmId     LM call is for
 * @param[in]     cpuId    Identifier for the CPU
 * @param[in]     maskIdx  Index of mask to set
 * @param[in]     maskVal  Mask data to set
 *
 * This function sets a mask for CPU non-IRQ wake sources.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the mask is set.
 * - others returned by ::SM_CPUNONIRQWAKESET
 */
int32_t LMM_CpuNonIrqWakeSet(uint32_t lmId, uint32_t cpuId, uint32_t maskIdx,
    uint32_t maskVal);

/*!
 * Set a CPU LPM config for a power domain.
 *
 * @param[in]     lmId        LM call is for
 * @param[in]     cpuId       Identifier for the CPU
 * @param[in]     domainId    Power domain
 * @param[in]     lpmSetting  LPM setting
 * @param[in]     retMask     Retention mask
 *
 * This function configures the LPM setting and retention mask for an
 * automatic power domains applied when a CPU enters a sleep mode. The LPM
 * setting determines which range of CPU sleep modes will leave the power
 * domain on. Note each CPU can have different settings and the hardware
 * aggregates these settings to determine the domain power state. The
 * retention mask is specific to a power domain and a SoC.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the setting is applied.
 * - others returned by ::SM_CPUPDLPMCONFIGSET
 */
int32_t LMM_CpuPdLpmConfigSet(uint32_t lmId, uint32_t cpuId,
    uint32_t domainId, uint32_t lpmSetting, uint32_t retMask);

/*!
 * Set a CPU LPM config for a clock.
 *
 * @param[in]     lmId        LM call is for
 * @param[in]     cpuId       Identifier for the CPU
 * @param[in]     clockId     clock ID
 * @param[in]     lpmSetting  LPM setting
 *
 * This function configures the LPM setting a clock applied when a CPU
 * enters a sleep mode. The LPM setting determines which range of CPU
 * sleep modes will leave the clock on. Note each CPU can have different
 * settings and the hardware aggregates these settings to determine the
 * domain state.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the setting is applied.
 * - others returned by ::SM_CPUCLKLPMCONFIGSET
 */
int32_t LMM_CpuClkLpmConfigSet(uint32_t lmId, uint32_t cpuId,
    uint32_t clockId, uint32_t lpmSetting);

#endif /* LMM_CPU_H */

/** @} */

