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
/* File containing the implementation of the device system.                 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "lmm.h"
#include "fsl_power.h"
#include "fsl_reset.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint32_t s_powerMode = 0U;
static dev_sm_rst_rec_t s_shutdownRecord = {};

/*--------------------------------------------------------------------------*/
/* Initialize system functions                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemInit(void)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t srcResetReason = 0U;

    /* Get reset reason from SRC */
    srcResetReason = RST_SystemGetResetReason();
    RST_SystemClearResetReason(srcResetReason);

    /* Load fault record from previous boot */
    BRD_SM_ShutdownRecordLoad(&s_shutdownRecord);

    /* Update if reason available from SRC */
    if ((srcResetReason != RST_REASON_POR) && !s_shutdownRecord.valid)
    {
        s_shutdownRecord.reason = srcResetReason;
        s_shutdownRecord.valid = true;
    }

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

    /* Request reset */
    RST_SystemRequestReset();

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset device to a specific stage and container                           */
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
        /* TODO: Need to do a warm reset */
        /* Request reset */
        RST_SystemRequestReset();
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

    /* Request shutdown */
    PWR_SystemPowerDown();

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Save shutdown reason                                                     */
/*--------------------------------------------------------------------------*/
void DEV_SM_SystemShutdownRecSet(dev_sm_rst_rec_t shutdownRec)
{
    /* Store shutdown record */
    BRD_SM_ShutdownRecordSave(shutdownRec);
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
    static int32_t maxLen = 0;

    static string const name[DEV_SM_NUM_REASON] =
    {
        [DEV_SM_REASON_CM33_LOCKUP] = "CM33_LOCKUP",
        [DEV_SM_REASON_CM33_SWREQ] = "CM33_SWREQ",
        [DEV_SM_REASON_CM7_LOCKUP] = "CM7_LOCKUP",
        [DEV_SM_REASON_CM7_SWREQ] = "CM7_SWREQ",
        [DEV_SM_REASON_FCCU] = "FCCU",
        [DEV_SM_REASON_JTAG_SW] = "JTAG_SW",
        [DEV_SM_REASON_ELE] = "ELE",
        [DEV_SM_REASON_TEMPSENSE] = "TEMPSENSE",
        [DEV_SM_REASON_WDOG1] = "WDOG1",
        [DEV_SM_REASON_WDOG2] = "WDOG2",
        [DEV_SM_REASON_WDOG3] = "WDOG3",
        [DEV_SM_REASON_WDOG4] = "WDOG4",
        [DEV_SM_REASON_WDOG5] = "WDOG5",
        [DEV_SM_REASON_JTAG] = "JTAG",
        [DEV_SM_REASON_CM33_EXC] = "CM33_EXC",
        [DEV_SM_REASON_BBM] = "BBM",
        [DEV_SM_REASON_SW] = "SW",
        [DEV_SM_REASON_UNUSED2] = "UNUSED2",
        [DEV_SM_REASON_UNUSED3] = "UNUSED3",
        [DEV_SM_REASON_UNUSED4] = "UNUSED4",
        [DEV_SM_REASON_UNUSED5] = "UNUSED5",
        [DEV_SM_REASON_UNUSED6] = "UNUSED6",
        [DEV_SM_REASON_UNUSED7] = "UNUSED7",
        [DEV_SM_REASON_UNUSED8] = "UNUSED8",
        [DEV_SM_REASON_UNUSED9] = "UNUSED9",
        [DEV_SM_REASON_UNUSED10] = "UNUSED10",
        [DEV_SM_REASON_UNUSED11] = "UNUSED11",
        [DEV_SM_REASON_UNUSED12] = "UNUSED12",
        [DEV_SM_REASON_UNUSED13] = "UNUSED13",
        [DEV_SM_REASON_UNUSED14] = "UNUSED14",
        [DEV_SM_REASON_UNUSED15] = "UNUSED15",
        [DEV_SM_REASON_POR] = "POR"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &maxLen, name, DEV_SM_NUM_REASON);

    /* Check reason */
    if (resetReason >= DEV_SM_NUM_REASON)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *reasonNameAddr = name[resetReason];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Complete system reset processing                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemRstComp(dev_sm_rst_rec_t resetRec)
{
    return SM_SYSTEMRSTCOMP(resetRec);
}

