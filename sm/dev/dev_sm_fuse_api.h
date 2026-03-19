/*
** ###################################################################
**
**     Copyright 2024-2026 NXP
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
 * @addtogroup DEV_SM_FUSE_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device fuses.
 */
/*==========================================================================*/

#ifndef DEV_SM_FUSE_API_H
#define DEV_SM_FUSE_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Initialize the Fuse array.
 */
void DEV_SM_FuseInit(void);

/*!
 * Get fuse info.
 *
 * @param[in]     fuseWord  Index of word
 * @param[out]    addr      Pointer to return address of fuse word
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if fuseWord is not valid.
 */
int32_t DEV_SM_FuseInfoGet(uint32_t fuseWord, uint32_t *addr);

/*!
 * Get fuse state.
 *
 * @param[in]     fuseId      Id of fuse to read
 *
 * @return Returns the fuse value.
 */
uint32_t DEV_SM_FuseGet(uint32_t fuseId);

/*!
 * Get fuse state of a power domain.
 *
 *@param[in]  domainId    Id of the power domain
 *
 * @return    Returns true if the power domain is disabled, else false.
 */
bool DEV_SM_FusePdDisabled(uint32_t domainId);

/*!
 * Get fuse state of a CPU ID.
 *
 *@param[in]  cpuId    Id of the CPU
 *
 * @return    Returns true if the CPU is disabled, else false.
 */
bool DEV_SM_FuseCpuDisabled(uint32_t cpuId);

#endif /* DEV_SM_FUSE_API_H */

/** @} */

