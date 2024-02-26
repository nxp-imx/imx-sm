/*
** ###################################################################
**
** Copyright 2023-024 NXP
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
 * @addtogroup LMM
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager.
 */
/*==========================================================================*/


#ifndef LMM_H
#define LMM_H

/* Includes */

#include "sm.h"
#include "config_lmm.h"
#include "lmm_config.h"
#include "lmm_power.h"
#include "lmm_sys.h"
#include "lmm_perf.h"
#include "lmm_clock.h"
#include "lmm_sensor.h"
#include "lmm_reset.h"
#include "lmm_voltage.h"
#include "lmm_bbm.h"
#include "lmm_cpu.h"
#include "lmm_misc.h"
#include "lmm_fault.h"
#ifdef USES_FUSA
#include "lmm_fusa.h"
#endif

/* Defines */

/*!
 * @name LMM init flags
 */
/** @{ */
#define LM_INIT_FLAGS_BOOT  BIT32(0U)  /*!< Boot LMs */
/** @} */

/*!
 * @name LMM RPC trigger events
 */
/** @{ */
#define LMM_TRIGGER_SYSTEM      0x0U  /*!< System event */
#define LMM_TRIGGER_SENSOR      0x1U  /*!< Sensor event */
#define LMM_TRIGGER_LM          0x2U  /*!< LMM event */
#define LMM_TRIGGER_RTC         0x3U  /*!< RTC event */
#define LMM_TRIGGER_BUTTON      0x4U  /*!< Button event */
#define LMM_TRIGGER_FUSA_FEENV  0x5U  /*!< FuSa F-EENV event */
#define LMM_TRIGGER_FUSA_SEENV  0x6U  /*!< FuSa S-EENV event */
#define LMM_TRIGGER_FUSA_FAULT  0x7U  /*!< FuSa fault event */
#define LMM_TRIGGER_CTRL        0x8U  /*!< Control event */
/** @} */

/* Types */

/*!
 * LMM RPC trigger structure
 *
 * Type to pass arguments to RPC to trigger a notification.
 */
typedef struct
{
    uint32_t rpcInst;  /*!< RPC instance */
    uint32_t event;    /*!< Trigger event */
    uint32_t parm[4];  /*!< Parameters for specific event type */
} lmm_rpc_trigger_t;

/* Functions */

/*!
 * @name LMM module functions
 * @{
 */

/*!
 * LMM initialization.
 *
 * @param[in,out] mSel          Boot mode selection
 *
 * This function initializes the various LMM submodules such as the LMM
 * clock function via LMM_ClockInit(). It then loops over the LMs and
 * initializes the associated RPC (e.g. RPC_SCMI_Init()).
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_Init(uint32_t *mSel);

/*!
 * LMM boot.
 *
 * @param[in]     mSel          Boot mode selection
 * @param[in]     lmmInitFlags  Init flags from makefile
 *
 * Boots all the LM as specified in the LMM configuration structure.
 * (lmm_config_t ::g_lmmConfig[]). The *boot* member indicates the boot order
 * with a value of 0 indicating not to boot. This function loops  through
 * the array in boot order and calls LMM_SystemLmBoot() for each LM.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_Boot(uint32_t mSel, uint32_t lmmInitFlags);

/*!
 * LMM post-boot complete.
 *
 * @param[in]     mSel          Boot mode selection
 * @param[in]     lmmInitFlags  Init flags from makefile
 *
 * Do any housekeeping after booting all LM.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_PostBoot(uint32_t mSel, uint32_t lmmInitFlags);

/*!
 * Get LM name.
 *
 * @param[in]     lmId          Calling LM
 * @param[in]     lm            LM name to get
 * @param[out]    lmNameAddr    Return pointer to name
 * @param[out]    len           Return max length of all LM names
 *
 * Returns the LM name as specified in the LMM configuration structure.
 * (lmm_config_t ::g_lmmConfig[]). The *name* member contains the name
 * string.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_LmNameGet(uint32_t lmId, uint32_t lm, string *lmNameAddr,
    int32_t *len);

/*!
 * Reset LM RPC.
 *
 * @param[in]     lmId          LM RPC to reset
 *
 * Reset the RPC linked to the LM specified with \a lmId. Called when the
 * LM is reset or powered off.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_RpcReset(uint32_t lmId);

/*!
 * Trigger a notification event for an LM.
 *
 * @param[in]     lmId          LM to trigger
 * @param[in]     trigger       Structure with trigger info
 *
 * Just calls the trigger function for the RPC linked to the \a lmId LM.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_RpcNotificationTrigger(uint32_t lmId,
    const lmm_rpc_trigger_t *trigger);

/*!
 * Dump LMM errors.
 *
 * Dump all logged error info for LMs and associated RPC and device.
 */
void LMM_ErrorDump(void);

/*!
 * LMM handler.
 *
 * Handler for SWI to do LM boot.
 */
void LMM_Handler(void);

/*!
 * Get time LM was booted.
 *
 * @param[in]     lmId          LM to trigger
 *
 * @return Returns the time in uS the LM last booted.
 */
uint64_t LMM_BootTimeGet(uint32_t lmId);

/** @} */

#endif /* LMM_H */

/** @} */

