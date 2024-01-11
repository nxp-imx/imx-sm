/*
** ###################################################################
**
**     Copyright 2023-2024 NXP
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_CPU_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device CPUs.
 */
/*==========================================================================*/

#ifndef DEV_SM_CPU_API_H
#define DEV_SM_CPU_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Initialize the CPUs.
 *
 * This function initializes the CPUs.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_HARDWARE_ERROR: if init of a CPU fails.
 */
int32_t DEV_SM_CpuInit(void);

/*!
 * Get a CPU name.
 *
 * @param[in]     cpuId        CPU name to get
 * @param[out]    cpuNameAddr  Return pointer to name
 * @param[out]    len          Return max length of all CPU names
 *
 * This function allows the caller to get the name of a CPU.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a cpuId is invalid.
 */
int32_t DEV_SM_CpuNameGet(uint32_t cpuId, string *cpuNameAddr,
    int32_t *len);

/*!
 * Get CPU info.
 *
 * @param[in]     cpuId        CPU name to get
 * @param[out]    runMode      Return pointer to run mode
 * @param[out]    sleepMode    Return pointer to sleep mode
 * @param[out]    vector       Return pointer to vector
 *
 * This function allows the caller to get misc. CPU info.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a cpuId is invalid.
 */
int32_t DEV_SM_CpuInfoGet(uint32_t cpuId, uint32_t *runMode,
    uint32_t *sleepMode, uint64_t *vector);

/*!
 * Start a CPU.
 *
 * @param[in]     cpuId    Identifier for the CPU
 *
 * This function allows the caller to start a CPU. This function
 * implicitly powers up the domain containing the CPU. The reset vector is
 * latched on power up and must be set using DEV_SM_CpuResetVectorSet()
 * before calling this function.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a cpuId does not point to a valid CPU.
 *   CPU.
 */
int32_t DEV_SM_CpuStart(uint32_t cpuId);

/*!
 * Hold a CPU.
 *
 * @param[in]     cpuId    Identifier for the CPU
 *
 * This function allows the caller to power up a CPU and leave in the hold
 * state. This function implicitly powers up the domain containing the CPU.
 * The reset vector is latched on power up and must be set using
 * DEV_SM_CpuResetVectorSet() before calling this function.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a cpuId does not point to a valid CPU.
 *   CPU.
 */
int32_t DEV_SM_CpuHold(uint32_t cpuId);

/*!
 * Stop a CPU.
 *
 * @param[in]     cpuId    Identifier for the CPU
 *
 * This function stops a CPU.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a cpuId does not point to a valid CPU.
 *   CPU.
 */
int32_t DEV_SM_CpuStop(uint32_t cpuId);

/*!
 * Check reset vector.
 *
 * @param[in]     cpuId        Identifier for the CPU
 * @param[in]     resetVector  Physical address where the CPU should
 *                             execute from or base address of vector table
 *                             reset
 * @param[in]     table        True if the address is a vector table base
 *
 * Checks the reset vector to see if valid.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a cpuId does not point to a valid CPU.
 * - ::SM_ERR_INVALID_PARAMETERS: \a if resetVector is invalid
 */
int32_t DEV_SM_CpuResetVectorCheck(uint32_t cpuId, uint64_t resetVector,
    bool table);

/*!
 * Set reset vector.
 *
 * @param[in]     cpuId            Identifier for the CPU
 * @param[in]     resetVector      Physical address where the CPU should
 *                                 execute from on reset.
 *
 * Note some CPUs allow the reset vector (the address where the CPU will start
 * execution) to be configured. Other CPUs instead allow the base address of
 * the vector table to be configured.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a cpuId does not point to a valid CPU.
 * - ::SM_ERR_INVALID_PARAMETERS: \a if resetVector is invalid
 */
int32_t DEV_SM_CpuResetVectorSet(uint32_t cpuId, uint64_t resetVector);

/*!
 * Set a CPU sleep target mode.
 *
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
 * - ::SM_ERR_NOT_FOUND: if \a cpuId does not point to a valid CPU.
 * - ::SM_ERR_INVALID_PARAMETERS: if \a sleepMode is invalid.
 */
int32_t DEV_SM_CpuSleepModeSet(uint32_t cpuId, uint32_t sleepMode,
    uint32_t sleepFlags);

/*!
 * Set a CPU IRQ wake mask.
 *
 * @param[in]     cpuId    Identifier for the CPU
 * @param[in]     maskIdx  Index of mask to set
 * @param[in]     maskVal  Mask data to set
 *
 * This function sets a mask for CPU IRQ wake sources.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a cpuId does not point to a valid CPU.
 * - ::SM_ERR_INVALID_PARAMETERS: if \a maskIdx is invalid.
 */
int32_t DEV_SM_CpuIrqWakeSet(uint32_t cpuId, uint32_t maskIdx,
    uint32_t maskVal);

/*!
 * Set a CPU non-IRQ wake mask.
 *
 * @param[in]     cpuId    Identifier for the CPU
 * @param[in]     maskIdx  Index of mask to set
 * @param[in]     maskVal  Mask data to set
 *
 * This function sets a mask for CPU non-IRQ wake sources.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a cpuId does not point to a valid CPU.
 * - ::SM_ERR_INVALID_PARAMETERS: if \a maskIdx is invalid.
 */
int32_t DEV_SM_CpuNonIrqWakeSet(uint32_t cpuId, uint32_t maskIdx,
    uint32_t maskVal);

/*!
 * Set a CPU LPM config for a power domain.
 *
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
 * - ::SM_ERR_NOT_FOUND: if \a cpuId or \a domain do not exist.
 */
int32_t DEV_SM_CpuPdLpmConfigSet(uint32_t cpuId, uint32_t domainId,
    uint32_t lpmSetting, uint32_t retMask);

/*!
 * Set a CPU LPM config for a clock.
 *
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
 * - ::SM_ERR_NOT_FOUND: if \a cpuId or \a clockId do not exist.
 */
int32_t DEV_SM_CpuPerLpmConfigSet(uint32_t cpuId, uint32_t clockId,
    uint32_t lpmSetting);

/*!
 * Get the wake list for a CPU.
 *
 * @param[in]     cpuId        CPU name to get
 * @param[out]    cpuWakeList  Return pointer to CPU wake list
 *
 * This function allows the caller to get the wake list for a CPU.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a cpuId is invalid.
 */
int32_t DEV_SM_CpuWakeListGet(uint32_t cpuId, uint32_t *cpuWakeList);

/*!
 * Set the wake list for a CPU.
 *
 * @param[in]     cpuId        CPU name to get
 * @param[in]     cpuWakeList  CPU wake list
 *
 * This function allows the caller to set the wake list for a CPU.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a cpuId is invalid.
 */
int32_t DEV_SM_CpuWakeListSet(uint32_t cpuId, uint32_t cpuWakeList);

#endif /* DEV_SM_CPU_API_H */

/** @} */

