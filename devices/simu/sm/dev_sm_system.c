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
/* File containing the implementation of the device system.                 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint32_t s_powerMode = 0U;
static dev_sm_rst_rec_t s_shutdownRecord = { 0 };

/*--------------------------------------------------------------------------*/
/* Initialize system functions                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemInit(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Save power mode                                                          */
/*--------------------------------------------------------------------------*/
void DEV_SM_SystemPowerModeSet(uint32_t powerMode)
{
    s_powerMode = powerMode;
}

/*--------------------------------------------------------------------------*/
/* get power mode                                                           */
/*--------------------------------------------------------------------------*/
void DEV_SM_SystemPowerModeGet(uint32_t *powerMode)
{
    *powerMode = s_powerMode;
}

/*--------------------------------------------------------------------------*/
/* Reset device                                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemReset(void)
{
    int32_t status = SM_ERR_SUCCESS;

    printf("DEV_SM_SystemReset()\n");

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset device to a specific stage                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemStageReset(uint32_t stage, uint32_t container)
{
    int32_t status;

    /* Configure stage */
    status = DEV_SM_RomStageSet(stage);

    /* Configure container */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_RomContainerSet(container);
    }

    if (status == SM_ERR_SUCCESS)
    {
        printf("DEV_SM_SystemStageReset(%u, %u)\n", stage, container);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Shutdown device                                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemShutdown(void)
{
    int32_t status = SM_ERR_SUCCESS;

    printf("DEV_SM_SystemShutdown()\n");

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Save shutdown reason                                                     */
/*--------------------------------------------------------------------------*/
void DEV_SM_SystemShutdownRecSet(dev_sm_rst_rec_t shutdownRec)
{
    /* Save shutdown record */
    s_shutdownRecord = shutdownRec;

    /* Print shutdown record */
    if (s_shutdownRecord.reset)
    {
        BRD_SM_ResetRecordPrint("\nReset request:", shutdownRec);
    }
    else
    {
        BRD_SM_ResetRecordPrint("\nShutdown request:", shutdownRec);
    }
}

/*--------------------------------------------------------------------------*/
/* Return shutdown reason                                                   */
/*--------------------------------------------------------------------------*/
void DEV_SM_SystemShutdownRecGet(dev_sm_rst_rec_t *shutdownRec)
{
    /* Copy out shutdown record */
    *shutdownRec = s_shutdownRecord;
}

/*--------------------------------------------------------------------------*/
/* Return reset reason name                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemReasonNameGet(uint32_t resetReason,
    string *reasonNameAddr, int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_REASON] =
    {
        [DEV_SM_REASON_POR] =        "por",
        [DEV_SM_REASON_FAULT] =      "fault",
        [DEV_SM_REASON_BBM] =        "bbm",
        [DEV_SM_REASON_SW] =         "sw",
        [DEV_SM_REASON_SM_ERR] =     "sm_err",
        [DEV_SM_REASON_FUSA_SRECO] = "fusa_sreco"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_REASON);

    /* Check reason */
    if (resetReason >= DEV_SM_NUM_REASON)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *reasonNameAddr = s_name[resetReason];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Post-boot clean-up                                                       */
/*                                                                          */
/* Run any clean-up required after starting all LM                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemPostBoot(uint32_t mSel, uint32_t initFlags)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Complete system reset processing                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemRstComp(const dev_sm_rst_rec_t *resetRec)
{
    return SM_SYSTEMRSTCOMP(resetRec);
}

/*--------------------------------------------------------------------------*/
/* Report SM error to log and reset                                         */
/*--------------------------------------------------------------------------*/
void DEV_SM_SystemError(int32_t status, uint32_t pc)
{
    dev_sm_rst_rec_t resetRec =
    {
        .reason = DEV_SM_REASON_SM_ERR,
        .errId = (uint32_t) status,
        .validErr = true,
        .valid = true
    };

    /* Record PC */
    if (pc != 0U)
    {
        resetRec.extInfo[0] = pc;
        resetRec.extLen = 1U;
    }

    /* Finalize system reset flow */
    (void) DEV_SM_SystemRstComp(&resetRec);
}

/*--------------------------------------------------------------------------*/
/* Idle the system                                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemIdle(void)
{
    return SM_ERR_SUCCESS;
}

