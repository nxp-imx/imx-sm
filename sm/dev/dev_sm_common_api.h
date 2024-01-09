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
 * @addtogroup DEV_SM_COMMON_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the common device.
 */
/*==========================================================================*/

#ifndef DEV_SM_COMMON_API_H
#define DEV_SM_COMMON_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Get silicon info.
 *
 * @param[out]    deviceId    Pointer to return device ID
 * @param[out]    siRev       Pointer to return silicon revision
 * @param[out]    partNum     Pointer to return part number
 * @param[out]    siNameAddr  Pointer to return silicon name
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_SiInfoGet(uint32_t *deviceId, uint32_t *siRev,
    uint32_t *partNum, string *siNameAddr);

/*!
 * Get 64-bit timestamp in microseconds.
 *
 * @return Returns the time in uS.
 */
uint64_t DEV_SM_Usec64Get(void);

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
 * Dump device error info.
 */
void DEV_SM_ErrorDump(void);

/*!
 * Get the max length of all strings in an array.
 *
 * @param[in,out] len     Returned max length of all strings
 * @param[in,out] maxLen  Cached max length of all strings
 * @param[in]     name    Array of strings
 * @param[in]     sz      Number of strings in the array
 *
 * This function allows the caller to get the max length of all strings
 * in an array. If \a len is NULL then does nothing. If \a maxLen is
 * not 0 then returns that in \a len.
 */
void DEV_SM_MaxStringGet(int32_t *len, int32_t *maxLen,
    string const *name, uint32_t sz);

/*!
 * Get length of a string.
 *
 * @param[in]     str     String to get length for
 *
 * @return Length of \a str.
 */
int32_t DEV_SM_StrLen(string str);

#endif /* DEV_SM_COMMON_API_H */

/** @} */

