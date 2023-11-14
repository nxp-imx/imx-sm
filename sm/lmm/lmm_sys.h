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
 * @addtogroup LMM_SYS
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager system.
 */
/*==========================================================================*/

#ifndef LMM_SYS_H
#define LMM_SYS_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/*!
 * @name LMM RPC trigger parameters
 *
 * LM notification type parameter. Stored in parm[0] of the trigger reported
 * via LMM_RpcNotificationTrigger(). Used by protocols to distinguish types
 * of LM notification events.
 */
/** @{ */
#define LMM_TRIGGER_PARM_LM_SHUTDOWN    0x00000000U  /*!< LM shutdown event */
#define LMM_TRIGGER_PARM_LM_COLD_RESET  0x00000001U  /*!< LM cold reset event */
#define LMM_TRIGGER_PARM_LM_WARM_RESET  0x00000002U  /*!< LM warm reset event */
#define LMM_TRIGGER_PARM_LM_BOOT        0x00000003U  /*!< LM boot event */
#define LMM_TRIGGER_PARM_LM_SUSPEND     0x00000004U  /*!< LM suspend (sleep) event */
#define LMM_TRIGGER_PARM_LM_WAKE        0x80000000U  /*!< LM wake (resume) event */
#define LMM_TRIGGER_PARM_SHUTDOWN       0x80000001U  /*!< LM full shutdown event */
#define LMM_TRIGGER_PARM_RESET          0x80000002U  /*!< LM full reset event */
#define LMM_TRIGGER_PARM_SUSPEND        0x80000003U  /*!< LM full suspend (sleep) event */
#define LMM_TRIGGER_PARM_WAKE           0x80000004U  /*!< LM full wake (resume) event */
/** @} */

/*!
 * @name LM states
 *
 * State of the LM. Returned by LM_SystemLmStatus().
 */
/** @{ */
#define LMM_STATE_LM_OFF      0x0U  /*!< LM off (shutdown) */
#define LMM_STATE_LM_ON       0x1U  /*!< LM on (booted/running) */
#define LMM_STATE_LM_SUSPEND  0x2U  /*!< LM suspend (asleep) */
/** @} */

/*!
 * @name LMM reaction configurations
 */
/** @{ */
#define LMM_REACT_SYS_RESET     0U  /*!< System reset */
#define LMM_REACT_SYS_SHUTDOWN  1U  /*!< System shutdown */
#define LMM_REACT_LM_RESET      2U  /*!< LM reset */
#define LMM_REACT_LM_SHUTDOWN   3U  /*!< LM shutdown */
#define LMM_REACT_BOARD         4U  /*!< Custom board handling */
#define LMM_REACT_FUSA          5U  /*!< FuSa notifications only */
#define LMM_REACT_NONE          6U  /*!< No reaction */
/** @} */

/* Types */

/*! LM reset record type */
typedef dev_sm_rst_rec_t lmm_rst_rec_t;

/* Global variables */

/*! Generic SW-initiated reset record */
extern const lmm_rst_rec_t g_swReason;

/* Functions */

/*!
 * Initialize LMM system management.
 *
 * Defaults all LM boot/shutdown reasons to that of the system.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_SystemInit(void);

/*!
 * Sets the mSel mode.
 *
 * @param[in]     mSel            mSel mode
 *
 * This mode is used to determine which set of LM start/stop sequences
 * will be used.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_INVALID_PARAMETERS if \a mSel is not valid
 */
int32_t LMM_SystemModeSelSet(uint32_t mSel);

/*!
 * Get a reset reason name.
 *
 * @param[in]     lmId            LM call is for
 * @param[in]     resetReason     Reason name to get
 * @param[out]    reasonNameAddr  Return pointer to name
 * @param[out]    len             Return max length of all reason names
 *
 * This function allows the caller to get the name of a
 * boot/shutdown/reset reason.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_SUCCESS: if the name is returned.
 * - others returned by ::SM_SYSTEMREASONNAMEGET
 */
int32_t LMM_SystemReasonNameGet(uint32_t lmId, uint32_t resetReason,
    string *reasonNameAddr, int32_t *len);

/*!
 * Complete a reset.
 *
 * @param[in]     resetRec  Reset record to store
 *
 * Used to report a need for a reset. Calls LMM_SystemReset() to send
 * all the required notifications, save the reset record, and reset the
 * system.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by LMM_SystemReset()
 */
int32_t LMM_SystemRstComp(lmm_rst_rec_t resetRec);

/*!
 * @name LMM full system functions
 * @{
 */

/*!
 * Shutdown (turn off) the system.
 *
 * @param[in]     lmId        Requesting LM
 * @param[in]     agentId     Requesting agent (LM view)
 * @param[in]     graceful    Graceful request if true
 * @param[in]     shutdownRec Shutdown record to store
 *
 * Function to do a full system shutdown. Sends all the required
 * notifications, saves the shutdown record, and shuts down
 * the system.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by ::SM_SYSTEMSHUTDOWN
 */
int32_t LMM_SystemShutdown(uint32_t lmId, uint32_t agentId,
    bool graceful, const lmm_rst_rec_t *shutdownRec);

/*!
 * Reset the system.
 *
 * @param[in]     lmId      Requesting LM
 * @param[in]     agentId   Requesting agent (LM view)
 * @param[in]     graceful  Graceful request if true
 * @param[in]     resetRec  Reset record to store
 *
 * Function to do a full system reset. Sends all the required
 * notifications, saves the reset record, and resets the system.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by ::SM_SYSTEMRESET
 */
int32_t LMM_SystemReset(uint32_t lmId, uint32_t agentId, bool graceful,
    const lmm_rst_rec_t *resetRec);

/*!
 * Request a graceful suspend of the system.
 *
 * @param[in]     lmId      Requesting LM
 * @param[in]     agentId   Requesting agent (LM view)
 *
 * Function to request a full system suspend. Sends all the
 * required notifications.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 */
int32_t LMM_SystemSuspend(uint32_t lmId, uint32_t agentId);

/*!
 * Request a wake of the system.
 *
 * @param[in]     lmId      Requesting LM
 * @param[in]     agentId   Requesting agent (LM view)
 *
 * Function to request a full system wake. Sends all the
 * required notifications.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 */
int32_t LMM_SystemWake(uint32_t lmId, uint32_t agentId);

/*!
 * Returns the boot and shutdown records for the system.
 *
 * @param[in]     lmId         Requesting LM
 * @param[out]    bootRec      Boot record
 * @param[out]    shutdownRec  Shutdown record
 *
 * Returns the reason info for the current boot and last shutdown.
 * The boot reason comes from the BBM and the shutdown reason from
 * the saved record.
 */
void LM_SystemReason(uint32_t lmId, lmm_rst_rec_t *bootRec,
    lmm_rst_rec_t *shutdownRec);

/*!
 * Store the power mode.
 *
 * @param[in]     lmId       Requesting LM
 * @param[in]     powerMode  Mode to store
 *
 * This function stores the power mode for the LM. The aggregation
 * policy is to OR the words for all LM and pass to the device layer.

 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 */
int32_t LMM_SystemPowerModeSet(uint32_t lmId, uint32_t powerMode);

/** @} */

/*!
 * @name LMM logical machine functions
 * @{
 */

/*!
 * Returns the status of an LM.
 *
 * @param[in]     lmId       Requesting LM
 * @param[in]     stateLm    LM to get state of
 * @param[out]    state      Pointer to return state
 * @param[out]    errStatus  Pointer to return error status
 *
 * Returns the state of an LM. An example state is ::LMM_STATE_LM_OFF.
 * Note the ::LMM_STATE_LM_SUSPEND state will only be returned on
 * SoC that notify the SM of suspend/wake transitions.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LM_SystemLmStatus(uint32_t lmId, uint32_t stateLm, uint32_t *state,
    int32_t *errStatus);

/*!
 * Check if an LM has at least one CPU that can boot.
 *
 * @param[in]     bootLm     LM to check
 *
 * Returns ::SM_ERR_SUCCESS if a CPU can boot.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_SystemLmCheck(uint32_t bootLm);

/*!
 * Boot (turn on) an LM.
 *
 * @param[in]     lmId         Requesting LM
 * @param[in]     agentId      Requesting agent (LM view)
 * @param[in]     bootLm       LM to boot
 * @param[in]     bootRec      Boot record to store
 *
 * Function to boot an LM. Sends all the required notifications, saves
 * the boot record, and boots the LM. Executes the configured start sequence.
 * If an error occurs, the LM state will not transition and the error saved.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_SUPPORTED: if bad start sequence
 * - ::SM_ERR_MISSING_PARAMETERS: if no valid reset vector
 */
int32_t LMM_SystemLmBoot(uint32_t lmId, uint32_t agentId, uint32_t bootLm,
    const lmm_rst_rec_t *bootRec);

/*!
 * Shutdown (turn off) an LM.
 *
 * @param[in]     lmId         Requesting LM
 * @param[in]     agentId      Requesting agent (LM view)
 * @param[in]     shutdownLm   LM to shut down
 * @param[in]     graceful     Graceful request if true
 * @param[in]     shutdownRec  Shutdown record to store
 *
 * Function to shutdown an LM. Sends all the required notifications, saves
 * the shutdown record, and shuts down the LM. Executes the configured stop
 * sequence. If an error occurs, the LM state will not transition and the
 * error saved.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_SystemLmShutdown(uint32_t lmId, uint32_t agentId,
    uint32_t shutdownLm, bool graceful, const lmm_rst_rec_t *shutdownRec);

/*!
 * Reset an LM.
 *
 * @param[in]     lmId      Requesting LM
 * @param[in]     agentId   Requesting agent (LM view)
 * @param[in]     resetLm   LM to reset
 * @param[in]     warm      Warm reset if true
 * @param[in]     graceful  Graceful request if true
 * @param[in]     resetRec  Reset record to store
 *
 * Function to reset an LM. Sends all the required notifications,
 * saves the reset record, and resets the LM. Executes the configured
 * stop and start sequence. If an error occurs, the LM state will not
 * transition and the error saved.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_SystemLmReset(uint32_t lmId, uint32_t agentId, uint32_t resetLm,
    bool warm, bool graceful, const lmm_rst_rec_t *resetRec);

/*!
 * Request a graceful suspend (sleep) of an LM.
 *
 * @param[in]     lmId       Requesting LM
 * @param[in]     agentId    Requesting agent (LM view)
 * @param[in]     suspendLm  LM to suspend
 *
 * Function to request a suspend on an LM. Sends all the required
 * notifications.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_SystemLmSuspend(uint32_t lmId, uint32_t agentId,
    uint32_t suspendLm);

/*!
 * Request an LM wake up (resume).
 *
 * @param[in]     lmId     Requesting LM
 * @param[in]     agentId  Requesting agent (LM view)
 * @param[in]     wakeLm   LM to wake up
 *
 * Function to request an LM wake up. Sends all the required notifications.
 * Note it will only do so if the LM has enabled wake notifications and
 * configured the notification channel mailbox as a wake source.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_SystemLmWake(uint32_t lmId, uint32_t agentId, uint32_t wakeLm);

/*!
 * Returns the boot and shutdown records for an LM.
 *
 * @param[in]     lmId         Requesting LM
 * @param[in]     reasonLm     LM to get reason for
 * @param[out]    bootRec      Boot record
 * @param[out]    shutdownRec  Shutdown record
 *
 * Returns the reason info for the current boot and last shutdown
 * of an LM.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND if \a reasonLm is invalid
 */
int32_t LM_SystemLmReason(uint32_t lmId, uint32_t reasonLm,
    lmm_rst_rec_t *bootRec, lmm_rst_rec_t *shutdownRec);

/** @} */

#endif /* LMM_SYS_H */

/** @} */

