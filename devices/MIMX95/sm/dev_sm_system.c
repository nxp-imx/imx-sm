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

    /* Default to keep M7 clocks running during sleep modes */
    BLK_CTRL_S_AONMIX->M7_CFG |=
        (BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_MASK |
        BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_MASK);

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

    /* Request warm reset */
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
        /* Request warm reset */
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
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_REASON] =
    {
        [DEV_SM_REASON_CM33_LOCKUP] = "cm33_lockup",
        [DEV_SM_REASON_CM33_SWREQ] =  "cm33_swreq",
        [DEV_SM_REASON_CM7_LOCKUP] =  "cm7_lockup",
        [DEV_SM_REASON_CM7_SWREQ] =   "cm7_swreq",
        [DEV_SM_REASON_FCCU] =        "fccu",
        [DEV_SM_REASON_JTAG_SW] =     "jtag_sw",
        [DEV_SM_REASON_ELE] =         "ele",
        [DEV_SM_REASON_TEMPSENSE] =   "tempsense",
        [DEV_SM_REASON_WDOG1] =       "wdog1",
        [DEV_SM_REASON_WDOG2] =       "wdog2",
        [DEV_SM_REASON_WDOG3] =       "wdog3",
        [DEV_SM_REASON_WDOG4] =       "wdog4",
        [DEV_SM_REASON_WDOG5] =       "wdog5",
        [DEV_SM_REASON_JTAG] =        "jtag",
        [DEV_SM_REASON_CM33_EXC] =    "cm33_exc",
        [DEV_SM_REASON_BBM] =         "bbm",
        [DEV_SM_REASON_SW] =          "sw",
        [DEV_SM_REASON_UNUSED2] =     "unused2",
        [DEV_SM_REASON_UNUSED3] =     "unused3",
        [DEV_SM_REASON_UNUSED4] =     "unused4",
        [DEV_SM_REASON_UNUSED5] =     "unused5",
        [DEV_SM_REASON_UNUSED6] =     "unused6",
        [DEV_SM_REASON_UNUSED7] =     "unused7",
        [DEV_SM_REASON_UNUSED8] =     "unused8",
        [DEV_SM_REASON_UNUSED9] =     "unused9",
        [DEV_SM_REASON_UNUSED10] =    "unused10",
        [DEV_SM_REASON_UNUSED11] =    "unused11",
        [DEV_SM_REASON_UNUSED12] =    "unused12",
        [DEV_SM_REASON_UNUSED13] =    "unused13",
        [DEV_SM_REASON_UNUSED14] =    "unused14",
        [DEV_SM_REASON_UNUSED15] =    "unused15",
        [DEV_SM_REASON_POR] =         "por"
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
/* Complete system reset processing                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemRstComp(dev_sm_rst_rec_t resetRec)
{
    return SM_SYSTEMRSTCOMP(resetRec);
}

