/*
** ###################################################################
**
**     Copyright 2025-2026 NXP
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
 * @addtogroup DEV_SM_MEM_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device memory.
 */
/*==========================================================================*/

#ifndef DEV_SM_MEM_API_H
#define DEV_SM_MEM_API_H

/* Includes */

#include "sm.h"

/* Defines */

/*!
 * @name Type of device DDR
 */
/** @{ */
#define DEV_SM_DDR_TYPE_LPDDR5   0  /*!< LPDDR5 */
#define DEV_SM_DDR_TYPE_LPDDR5X  1  /*!< LPDDR5X */
#define DEV_SM_DDR_TYPE_LPDDR4   2  /*!< LPDDR4 */
#define DEV_SM_DDR_TYPE_LPDDR4X  3  /*!< LPDDR4X */
/** @} */

/* Types */

/* Functions */

/*!
 * Get device DDR memory region info.
 *
 * @param[in]     ddrRgdId  Region call is for
 * @param[out]    numRgd    Pointer to return the number of regions
 * @param[out]    ddrType   Pointer to return the DDR type
 * @param[out]    ddrWidth  Pointer to return the DDR width
 * @param[out]    eccEnb    Pointer to return the ECC enable state
 * @param[out]    mts       Pointer to return MTS
 * @param[out]    startAddr Pointer to return the start address
 * @param[out]    endAddr   Pointer to return the end address
 *
 * This function allows a caller to get DDR memory region info.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if info is returned.
 * - ::SM_ERR_NOT_FOUND: if \a ddrRgdId is invalid.
 * - ::SM_ERR_POWER: if the DDR controller is not powered/configured.
 */
int32_t DEV_SM_MemDdrInfoGet(uint32_t ddrRgdId, uint32_t *numRgd,
    uint32_t *ddrType, uint32_t *ddrWidth, bool *eccEnb, uint32_t *mts,
    uint64_t *startAddr, uint64_t *endAddr);

#endif /* DEV_SM_MEM_API_H */

/** @} */

