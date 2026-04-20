/*
** ###################################################################
**
** Copyright 2026 NXP
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

/* Includes */

#include "lmm.h"
#include "sm_test_mode.h"

/* External real functions */

extern int32_t __real_LMM_SystemShutdown(uint32_t lmId, uint32_t agentId,
    bool graceful, const lmm_rst_rec_t *shutdownRec);
extern int32_t __real_LMM_SystemSuspend(uint32_t lmId, uint32_t agentId);
extern int32_t __real_LMM_SystemWake(uint32_t lmId, uint32_t agentId);
extern int32_t __real_LMM_SystemSleepModeSet(uint32_t lmId,
    uint32_t sleepMode, uint32_t sleepFlags);
extern int32_t __real_LM_SystemLmStatus(uint32_t lmId, uint32_t stateLm,
    uint32_t *state, int32_t *errStatus);
extern int32_t __real_LMM_SystemLmCheck(uint32_t bootLm);
extern int32_t __real_LMM_SystemLmPowerOn(uint32_t lmId, uint32_t agentId,
    uint32_t pwrLm);
extern int32_t __real_LMM_SystemLmBoot(uint32_t lmId, uint32_t agentId,
    uint32_t bootLm, const lmm_rst_rec_t *bootRec);
extern int32_t __real_LMM_SystemLmShutdown(uint32_t lmId, uint32_t agentId,
    uint32_t shutdownLm, bool graceful, const lmm_rst_rec_t *shutdownRec);
extern int32_t __real_LMM_SystemLmReset(uint32_t lmId, uint32_t agentId,
    uint32_t resetLm, bool warm, bool graceful,
    const lmm_rst_rec_t *resetRec);
extern int32_t __real_LMM_SystemLmSuspend(uint32_t lmId, uint32_t agentId,
    uint32_t suspendLm);
extern int32_t __real_LMM_SystemLmWake(uint32_t lmId, uint32_t agentId,
    uint32_t wakeLm);
extern int32_t __real_LM_SystemLmReason(uint32_t lmId, uint32_t reasonLm,
    lmm_rst_rec_t *bootRec, lmm_rst_rec_t *shutdownRec);
extern int32_t __real_LMM_SystemGrpBoot(uint32_t lmId, uint32_t agentId,
    const lmm_rst_rec_t *bootRec, uint8_t group);
extern int32_t __real_LMM_SystemGrpShutdown(uint32_t lmId, uint32_t agentId,
    bool graceful, const lmm_rst_rec_t *shutdownRec, uint8_t group,
    bool *noReturn);
extern int32_t __real_LMM_SystemGrpReset(uint32_t lmId, uint32_t agentId,
    bool graceful, const lmm_rst_rec_t *resetRec, uint8_t group,
    bool *noReturn);

/*--------------------------------------------------------------------------*/
/* Full system shutdown                                                     */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemShutdown(uint32_t lmId, uint32_t agentId,
    bool graceful, const lmm_rst_rec_t *shutdownRec)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemShutdown(lmId, agentId, graceful,
        shutdownRec);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Full system suspend                                                      */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemSuspend(uint32_t lmId, uint32_t agentId)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemSuspend(lmId, agentId);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Full system wake                                                         */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemWake(uint32_t lmId, uint32_t agentId)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemWake(lmId, agentId);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set system sleep mode                                                    */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemSleepModeSet(uint32_t lmId, uint32_t sleepMode,
    uint32_t sleepFlags)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemSleepModeSet(lmId, sleepMode, sleepFlags);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return LM status                                                         */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LM_SystemLmStatus(uint32_t lmId, uint32_t stateLm,
    uint32_t *state, int32_t *errStatus)
{
    int32_t status;

    /* Call original function */
    status = __real_LM_SystemLmStatus(lmId, stateLm, state, errStatus);

    SM_TEST_MODE_EXEC(SM_TEST_MODE_LMM_ALT1, *errStatus = SM_ERR_TEST)
    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Check if an LM can be booted                                             */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemLmCheck(uint32_t bootLm)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemLmCheck(bootLm);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Power on LM                                                              */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemLmPowerOn(uint32_t lmId, uint32_t agentId,
    uint32_t pwrLm)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemLmPowerOn(lmId, agentId, pwrLm);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Boot LM                                                                  */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemLmBoot(uint32_t lmId, uint32_t agentId,
    uint32_t bootLm, const lmm_rst_rec_t *bootRec)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemLmBoot(lmId, agentId, bootLm, bootRec);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Shutdown LM                                                              */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemLmShutdown(uint32_t lmId, uint32_t agentId,
    uint32_t shutdownLm, bool graceful, const lmm_rst_rec_t *shutdownRec)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemLmShutdown(lmId, agentId, shutdownLm,
        graceful, shutdownRec);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset LM                                                                 */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemLmReset(uint32_t lmId, uint32_t agentId,
    uint32_t resetLm, bool warm, bool graceful, const lmm_rst_rec_t *resetRec)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Call original function */
    status = __real_LMM_SystemLmReset(lmId, agentId, resetLm, warm,
        graceful, resetRec);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Suspend LM                                                               */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemLmSuspend(uint32_t lmId, uint32_t agentId,
    uint32_t suspendLm)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemLmSuspend(lmId, agentId, suspendLm);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Wake (resume) LM                                                         */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemLmWake(uint32_t lmId, uint32_t agentId,
    uint32_t wakeLm)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemLmWake(lmId, agentId, wakeLm);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return LM reset (shutdown/boot) reason                                   */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LM_SystemLmReason(uint32_t lmId, uint32_t reasonLm,
    lmm_rst_rec_t *bootRec, lmm_rst_rec_t *shutdownRec)
{
    int32_t status;

    /* Call original function */
    status = __real_LM_SystemLmReason(lmId, reasonLm, bootRec, shutdownRec);

    SM_TEST_MODE_EXEC(SM_TEST_MODE_LMM_ALT1, shutdownRec->errId = \
        bootRec->errId + 1U)
    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Group boot                                                               */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemGrpBoot(uint32_t lmId, uint32_t agentId,
    const lmm_rst_rec_t *bootRec, uint8_t group)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemGrpBoot(lmId, agentId, bootRec, group);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Group shutdown                                                           */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemGrpShutdown(uint32_t lmId, uint32_t agentId,
    bool graceful, const lmm_rst_rec_t *shutdownRec, uint8_t group,
    bool *noReturn)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemGrpShutdown(lmId, agentId, graceful,
        shutdownRec, group, noReturn);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Group reset                                                              */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_SystemGrpReset(uint32_t lmId, uint32_t agentId,
    bool graceful, const lmm_rst_rec_t *resetRec, uint8_t group,
    bool *noReturn)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_SystemGrpReset(lmId, agentId, graceful, resetRec,
        group, noReturn);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

