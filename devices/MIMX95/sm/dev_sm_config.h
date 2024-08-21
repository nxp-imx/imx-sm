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
 * @addtogroup DEV_SM_MX95_CONFIG
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the device configuration loading functions.
 */
/*==========================================================================*/

#ifndef DEV_SM_CONFIG_H
#define DEV_SM_CONFIG_H

/* Includes */

#include "sm.h"
#include "dev_sm_cpu.h"

/* Defines */

/* Types */

/*!
 * Device config structure
 *
 * See @ref CONFIG_STRUCT for more info.
 */
typedef struct
{
    uint32_t cpuSemaAddr[DEV_SM_NUM_CPU];  /*!< CPU semaphore address */
} dev_config_t;

/* Global constant data */

/*! Device config */
extern const dev_config_t g_devConfig;

/* Functions */

/*!
 * Load the camera power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_CameraConfigLoad(void);

/*!
 * Load the A55 power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_A55pConfigLoad(void);

/*!
 * Load the DDR power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_DdrConfigLoad(void);

/*!
 * Load the display power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_DisplayConfigLoad(void);

/*!
 * Load the GPU power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_GpuConfigLoad(void);

/*!
 * Load the HSIO TOP power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_HsioTopConfigLoad(void);

/*!
 * Load the HSIO WAON power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_HsioWaonConfigLoad(void);

/*!
 * Load the M7 power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_M7ConfigLoad(void);

/*!
 * Load the NETC power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_NetcConfigLoad(void);

/*!
 * Load the NOC power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_NocConfigLoad(void);

/*!
 * Load the NPU power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_NpuConfigLoad(void);

/*!
 * Load the VPU power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_VpuConfigLoad(void);

/*!
 * Load the wakeup power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_WkupConfigLoad(void);

/*!
 * Load the analog power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_AnaConfigLoad(void);

/*!
 * Load the DDR power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_AonConfigLoad(void);

/*!
 * Load the BBSM power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_BbsmConfigLoad(void);

/*!
 * Load the CCM/SRC/GPC power domain configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_CcmsrcgpcConfigLoad(void);

/*!
 * Configure the A55 domain for power down.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_A55pPowerDownPre(void);

/*!
 * Configure the DDR domain for power down.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_DdrPowerDownPre(void);

/*!
 * Configure the display domain for power down.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_DisplayPowerDownPre(void);

/*!
 * Configure the HSIO TOP domain for power down.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_HsioTopPowerDownPre(void);

/*!
 * Configure the M7 domain for power down.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_M7PowerDownPre(void);

#endif /* DEV_SM_CONFIG_H */

/** @} */

