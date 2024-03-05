/*
** ###################################################################
**
** Copyright 2023-2024 NXP
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
 * @addtogroup LMM_FUSA
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Logical Machine Manager FuSa.
 */
/*==========================================================================*/

#ifndef LMM_FUSA_H
#define LMM_FUSA_H

/* Includes */

#include "sm.h"
#include "dev_sm_api.h"

/* Defines */

/*!
 * @name LMM FuSa F-EENV states
 */
/** @{ */
/*! Initial state during boot up */
#define LMM_FUSA_FEENV_STATE_INIT             0U
/*! Waiting for all S-EENVs to be safety ready */
#define LMM_FUSA_FEENV_STATE_PRE_SAFETY       1U
/*! Running in normal safety context */
#define LMM_FUSA_FEENV_STATE_SAFETY_RUNTIME   2U
/*! Before SoC reset or shutdown transitions */
#define LMM_FUSA_FEENV_STATE_SOC_TERMINATING  3U
/** @} */

/*!
 * @name LMM FuSa S-EENV states
 */
/** @{ */
/*! S-EENV is disabled */
#define LMM_FUSA_SEENV_STATE_DISABLED        0U
/*! Initial S-EENV state */
#define LMM_FUSA_SEENV_STATE_INIT            1U
/*! S-EENV is ready to transition to the RUNTIME state */
#define LMM_FUSA_SEENV_STATE_SAFETY_READY    2U
/*! Running in normal safety context */
#define LMM_FUSA_SEENV_STATE_SAFETY_RUNTIME  3U
/*! Transitioned to a terminal state */
#define LMM_FUSA_SEENV_STATE_TERMINAL        4U
/** @} */

/* Types */

/*!
 * LMM FuSA caller ID structure
 */
typedef struct
{
    uint32_t seenvId;  /*!< Caller S-EENV ID */
    uint32_t lmId;     /*!< Caller LM ID */
} lmm_fusa_id_t;

/* Functions */

/*!
 * Initialize the FuSa system.
 *
 * @param[in,out] mSel          Boot mode selection
 *
 * This function initializes the functional safety system.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_FusaInit(uint32_t *mSel);

/*!
 * Return number of S-EENV LM.
 *
 * @param[out]    num           Number of S-EENV LM
 */
void LMM_SsenvLmNumGet(uint32_t *num);

/*!
 * Get current FuSa system state.
 *
 * @param[in]     caller      Caller requesting
 * @param[out]    feenvState  Parameter identifying the safety state of the
 *                            F-EENV
 * @param[out]    mselMode    Mode selector value as returned by SAF
 *
 * This function is used to get the current FuSa system state and operation
 * mode selected by the SAF mSel.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_FusaFeenvStateGet(const lmm_fusa_id_t *caller,
    uint32_t *feenvState, uint32_t *mselMode);

/*!
 * Get S-EENV state.
 *
 * @param[in]     caller      Caller requesting
 * @param[in]     target      Identifier of the S-EENV whose state is
 *                            requested.
 * @param[out]    seenvState  Parameter identifying the safety state of the
 *                            S-EENV
 *
 * This function is used by any S-EENV to retrieve information about itself as
 * it is recorded in the F-EENV internal memory.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_FusaSeenvStateGet(const lmm_fusa_id_t *caller,
    const lmm_fusa_id_t *target, uint32_t *seenvState);

/*!
 * Set S-EENV state.
 *
 * @param[in]     caller      Caller requesting
 * @param[in]     seenvState  Parameter to set the safety state of the S-EENV
 * @param[in]     pingCookie  Cookie value last sent by the F-EENV
 *
 * This function is used by the S-EENVs to inform SM about transition to a new
 * state. The SM accepts this transition and records the S-EENV state
 * internally. Collecting the state information from all S-EENVs is important
 * for SM to transition between various F-EENV states.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_FusaSeenvStateSet(const lmm_fusa_id_t *caller,
    uint32_t seenvState, uint32_t pingCookie);

/*!
 * Get the state of a fault.
 *
 * @param[in]     caller        Caller requesting
 * @param[in]     faultId       Fault ID
 * @param[out]    state         State, true if asserted
 *
 * Gets the state of a fault.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by LMM_FaultGet()
 */
int32_t LMM_FusaFaultGet(const lmm_fusa_id_t *caller, uint32_t faultId,
    bool *state);

/*!
 * Set the state of a fault.
 *
 * @param[in]     caller        Caller requesting
 * @param[in]     faultId       Fault ID
 * @param[in]     set           True to set, false to clear
 *
 * Sets the state of a fault. If \a set is true, will assert the fault
 * if possible. This is the case for SCP SW faults. May be true for
 * faults that can be triggered with fault injection. If \a set is false,
 * will deassert the fault if manually set. Will clear a fault if the
 * state is latched.
 *
 * Sends fault notifications on fault clear.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - others returned by LMM_FaultSet()
 */
int32_t LMM_FusaFaultSet(const lmm_fusa_id_t *caller, uint32_t faultId,
    bool set);

/*!
 * Temporarily disable fault handling.
 *
 * @param[in]     caller        Caller requesting
 *
 * This function is used by the S-EENV during sCheck event processing to
 * temporarily disable user handling of faults being tested. This is used
 * whenever an S-EENV sCheck is about to inject faults for testing purposes and
 * needs to pause normal SM fault processing. In this mode, the injected faults
 * are handled internally by SAF.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_FusaScheckEvntrig(const lmm_fusa_id_t *caller);

/*!
 * Request manually-triggered execution of sCheck test.
 *
 * @param[in]     caller        Caller requesting
 * @param[in]     targetTestId  Identifier of sCheck target test to be executed
 *
 * This function is used by the S-EENV to request manually-triggered execution
 * of sCheck test. The target test is identified using the \a targetTestId
 * parameter. The test identifiers are assigned during SAF sCheck user
 * configuration.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t LMM_FusaScheckTestExec(const lmm_fusa_id_t *caller,
    uint32_t targetTestId);

/*!
 * Report a fault was set (asserted) to FuSa.
 *
 * @param[in]     faultId       Fault ID
 * @param[in,out] reaction      Pointer to reaction
 * @param[in,out] lm            Pointer to LM
 *
 * Sends fault notifications indicating a fault was set. Allows
 * FuSa to override the fault reaction and LM. These default to
 * the the reaction specified in the SM config.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 */
int32_t LMM_FusaFaultRecover(uint32_t faultId, uint32_t *reaction,
    uint32_t *lm);

/*!
 * Report a fault was cleared (deasserted) to FuSa.
 *
 * @param[in]     faultId       Fault ID
 *
 * Sends fault notifications indicating a fault was cleared.
 */
void LMM_FusaFaultCleared(uint32_t faultId);

/*!
 * Report a full (system) shutdown event.
 *
 * @param[in]     shutdownRec Shutdown record to store
 *
 * Called from LMM_SystemShutdown() and LMM_SystemReset() to report
 * a shutdown event. Used to flush data to FuSa persistent storage.
 */
void LMM_FusaExit(const lmm_rst_rec_t *shutdownRec);

/*!
 * Request global error recovery.
 *
 * @param[in]     shutdownRec Shutdown record to store
 *
 * Use to report an internal FuSa error condition. Results in a full
 * system reset with a ::DEV_SM_REASON_FUSA_SRECO reset reason.
 */
void LMM_FusaGlobalRecovery(uint32_t status);

/*!
 * Report a full (system) reset event due to an SCP exception.
 *
 * @param[in]     resetRec    Exception information
 *
 * Called from the handlers ExceptionHandler() function to report
 * a reset event due to an SCP exception.
 */
void LMM_FuSaExceptionHandler(const dev_sm_rst_rec_t *resetRec);

/*!
 * Report assertion error.
 *
 * @param[in]     status        Error status
 */
void LMM_FuSaAssertionFailure(int32_t status);

#endif /* LMM_FUSA_H */

/** @} */

