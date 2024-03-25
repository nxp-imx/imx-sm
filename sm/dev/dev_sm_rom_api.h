/*
** ###################################################################
**
**     Copyright 2023 NXP
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
 * @addtogroup DEV_SM_ROM_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device ROM.
 */
/*==========================================================================*/

#ifndef DEV_SM_ROM_API_H
#define DEV_SM_ROM_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Initialize the ROM data interface.
 */
void DEV_SM_RomInit(void);

/*!
 * Get handover data from ROM.
 *
 * @param[out]    handover Pointer to return handover pointer
 *
 * This function allows a caller to obtain a pointer to the ROM
 * handover data.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_SUPPORTED: if the data is not available.
 */
int32_t DEV_SM_RomHandoverGet(const rom_handover_t **handover);

/*!
 * Get passover data from ROM.
 *
 * @param[out]    passover Pointer to return passover pointer
 *
 * This function allows a caller to obtain a pointer to the ROM
 * passover data.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_SUPPORTED: if the data is not available.
 */
int32_t DEV_SM_RomPassoverGet(const rom_passover_t **passover);

/*!
 * Get first matching image in the image list.
 *
 * @param[in]     type   Type of image
 * @param[out]    cpuId  CPU ID for image
 * @param[out]    addr   Boot address for image
 * @param[out]    mSel   mSel value
 * @param[out]    flags  misc. flags
 *
 * This function searches the ROM image array for the first
 * matching and returns the data.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_SUPPORTED: if the ROM data is not available.
 * - ::SM_ERR_NOT_FOUND: if image type not found.
 */
int32_t DEV_SM_RomBootImg1Get(uint32_t type, uint32_t *cpuId,
    uint64_t *addr, uint32_t *mSel, uint32_t *flags);

/*!
 * Get the next matching image in the image list.
 *
 * @param[in]     type   Type of image
 * @param[out]    cpuId  CPU ID for image
 * @param[out]    addr   Boot address for image
 * @param[out]    mSel   mSel value
 * @param[out]    flags  misc. flags
 *
 * This function searches the ROM image array for the next
 * matching and returns the data.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_SUPPORTED: if the ROM data is not available.
 * - ::SM_ERR_NOT_FOUND: if no more images of the type.
 */
int32_t DEV_SM_RomBootImgNGet(uint32_t type, uint32_t *cpuId,
    uint64_t *addr, uint32_t *mSel, uint32_t *flags);

/*!
 * Get the boot info for a CPU.
 *
 * @param[in]     cpuId        CPU ID to find
 * @param[out]    resetVector  Boot address for the CPU
 * @param[out]    mSel         mSel value
 * @param[out]    flags  misc. flags
 *
 * This function searches the ROM image array for a record
 * matching \a cpuId and returns the reset vector.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_SUPPORTED: if the ROM data is not available.
 * - ::SM_ERR_NOT_FOUND: if the CPU is not found.
 */
int32_t DEV_SM_RomBootCpuGet(uint32_t cpuId, uint64_t *resetVector,
    uint32_t *mSel, uint32_t *flags);

/*!
 * Set the ROM boot stage.
 *
 * @param[in]     stage        Boot stage
 *
 * This function stores the stage for the ROM to read on the next
 * warm reset. See DEV_SM_ROM_BS_PRIMARY.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_RomStageSet(uint32_t stage);

/*!
 * Set the ROM boot container.
 *
 * @param[in]     container    Boot container (0, 1)
 *
 * This function stores the stage for the ROM to read on the next
 * warm reset.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_RomContainerSet(uint32_t container);

#endif /* DEV_SM_ROM_API_H */

/** @} */

