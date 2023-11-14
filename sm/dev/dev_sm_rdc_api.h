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
 * @addtogroup DEV_SM_RDC_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device RDC.
 */
/*==========================================================================*/

#ifndef DEV_SM_RDC_API_H
#define DEV_SM_RDC_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Initialize the RDC.
 *
 * This function initializes the RDC (e.g. TRDC, XRDC). This include asking
 * for control of these from the ELE.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_RdcInit(void);

/*!
 * Get info about an RDC.
 *
 * @param[in]     rdcId        Identifier for the RDC
 * @param[out]    rdcNameAddr  Pointer to return the name
 * @param[out]    rdcLabel     Pointer to return the char label
 * @param[out]    rdcBase      Pointer to return the base address
 *
 * This function will return info about an RDC.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a rdcId is invalid.
 * - ::SM_ERR_POWER: if the RDC is not powered on.
 */
int32_t DEV_SM_RdcInfoGet(uint32_t rdcId, string *rdcNameAddr,
    char *rdcLabel, uint32_t *rdcBase);

/*!
 * Load an RDC configuration.
 *
 * @param[in]     rdcId        Identifier for the RDC
 *
 * This function will load an RDC after it is powered on.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if \a rdcId is invalid.
 * - others returned by CONFIG_Load().
 */
int32_t DEV_SM_RdcLoad(uint32_t rdcId);

/*!
 * Set RDC access based on a device ID.
 *
 * @param[in]     deviceId  Identifier for the device
 * @param[in]     allow     True to allow access, false to block
 * @param[in]     domId     DID to configure access for
 * @param[in]     secure    Security state to configure access
 *                          for
 *
 * RDC configuration is usually static and loaded when an RDC is
 * powered on. For select cases, it may be required for clients to
 * change access rights dynamically. The SCMI_BaseSetDevicePermissions()
 * function allows this by calling this function.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).

 */
int32_t DEV_SM_RdcAccessSet(uint32_t deviceId, bool allow, uint8_t domId,
    bool secure);

#endif /* DEV_SM_RDC_API_H */

/** @} */

