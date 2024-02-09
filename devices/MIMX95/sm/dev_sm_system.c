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
static dev_sm_rst_rec_t s_shutdownRecord = { 0 };

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

    /* Shut off OSC_24M during system sleep */
    GPC_GLOBAL->GPC_ROSC_CTRL = GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_MASK;

    /* Enable GPC PMIC standby control */
    GPC_GLOBAL->GPC_PMIC_CTRL = GPC_GLOBAL_GPC_PMIC_CTRL_PMIC_STBY_EN_MASK;

    /* TODO:  Enable GPC-to-ELE handshake */
    /* GPC_GLOBAL->GPC_SENTINEL_HDSK_CTRL = 1U; */

    /* TODO:  Use DEEPSLEEP output of M33 to reflect GPC sleep request */
    /* BLK_CTRL_NS_AONMIX->GPC_CFG |= BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_MASK; */

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
/* Post-boot clean-up                                                       */
/*                                                                          */
/* Run any clean-up required after starting all LM                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemPostBoot(uint32_t mSel, uint32_t initFlags)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t priMask;

    /* Disable interrupts */
    priMask = DisableGlobalIRQ();

    /* Check AP platform */
    if (!SRC_MixIsPwrSwitchOn(PWR_MIX_SLICE_IDX_A55P))
    {
        /* Turn off AP power supply */
        status = BRD_SM_SupplyModeSet(PS_VDD_ARM, DEV_SM_VOLT_MODE_OFF);
    }

    /* Restore interrupts */
    EnableGlobalIRQ(priMask);

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

/*--------------------------------------------------------------------------*/
/* Sleep the system                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemSleep(uint32_t sleepMode)
{
    static uint32_t s_clkRootCtrl[CLOCK_NUM_ROOT];
    int32_t status = SM_ERR_SUCCESS;
    uint32_t cpuWakeMask[CPU_NUM_IDX][GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT];
    uint32_t sysWakeMask[GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT];
    uint32_t nvicISER[GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT];

    /* Initalize wake masks */
    for (uint32_t wakeIdx = 0;
        wakeIdx < GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT;
        wakeIdx++)
    {
        sysWakeMask[wakeIdx] = 0xFFFFFFFFU;

        for (uint32_t cpuIdx = 0U; cpuIdx < CPU_NUM_IDX; cpuIdx++)
        {
            cpuWakeMask[cpuIdx][wakeIdx] = 0xFFFFFFFFU;
        }
   }

    /* Initialize NOC/WAKEUP MIX dependencies */
    uint32_t lpmSettingNoc = CPU_PD_LPM_ON_NEVER;
    uint32_t lpmSettingWakeup = CPU_PD_LPM_ON_NEVER;
    SRC_MixCpuLpmGet(PWR_MIX_SLICE_IDX_NOC, CPU_IDX_M33P, &lpmSettingNoc);
    SRC_MixCpuLpmGet(PWR_MIX_SLICE_IDX_WAKEUP, CPU_IDX_M33P, &lpmSettingWakeup);

    /* Scan CPUs, update GPC wake masks, assess NOC/WAKEUP MIX dependencies */
    for (uint32_t cpuIdx = 0U; cpuIdx < CPU_NUM_IDX; cpuIdx++)
    {
        if (cpuIdx != CPU_IDX_M33P)
        {
            /* Check if sleep is forced for the CPU */
            bool sleepForce;
            if (CPU_SleepForceGet(cpuIdx, &sleepForce))
            {
                /* If sleep is not forced, manage GPC masks */
                if (!sleepForce)
                {
                    /* IRQs enabled at NVIC level become GPC wake sources */
                    for (uint32_t wakeIdx = 0;
                        wakeIdx < GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT;
                        wakeIdx++)
                    {
                        uint32_t wakeVal;
                        CPU_IrqWakeGet(cpuIdx, wakeIdx, &wakeVal);
                        cpuWakeMask[cpuIdx][wakeIdx] = wakeVal;
                        sysWakeMask[wakeIdx] &= wakeVal;
                        CPU_IrqWakeSet(cpuIdx, wakeIdx, 0xFFFFFFFFU);
                    }
                }

                /* Update NOCMIX dependency */
                uint32_t lpmSetting;
                if (SRC_MixCpuLpmGet(PWR_MIX_SLICE_IDX_NOC, cpuIdx, &lpmSetting))
                {
                    if (lpmSetting > lpmSettingNoc)
                    {
                        lpmSettingNoc = lpmSetting;
                    }
                }

                /* Update WAKEUPMIX dependency */
                if (SRC_MixCpuLpmGet(PWR_MIX_SLICE_IDX_WAKEUP, cpuIdx, &lpmSetting))
                {
                    if (lpmSetting > lpmSettingWakeup)
                    {
                        lpmSettingWakeup = lpmSetting;
                    }
                }
            }
        }
    }

    /* Check system sleep status after clearing GPC masks */
    uint32_t sysSleepStat;
    if (CPU_SystemSleepStatusGet(&sysSleepStat))
    {
        /* If system can sleep after clearing GPC masks, SUSPEND
         * processing has reached point of coherency.  Agent CPUs
         * cannot wake without SM completion of SUSPEND entry/exit
         * sequence below.
         */
        if (sysSleepStat == CPU_SLEEP_MODE_SUSPEND)
        {
            uint32_t clkSrcIdx, rootIdx;

            /* Board-level sleep prepare */
            BOARD_SystemSleepPrepare(sleepMode);

            /* Inhibit GPC LP handshakes for NOCMIX if powering down */
            if (lpmSettingNoc <= sleepMode)
            {
                PWR_LpHandshakeMaskSet(PWR_MIX_SLICE_IDX_NOC, false);
            }

            /* Inhibit GPC LP handshakes for NOCMIX if powering down */
            if (lpmSettingWakeup <= sleepMode)
            {
                PWR_LpHandshakeMaskSet(PWR_MIX_SLICE_IDX_WAKEUP, false);
            }

            /* Configure SM GPC_CTRL and NVIC for system-level wake events */
            for (uint32_t wakeIdx = 0;
                wakeIdx < GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT;
                wakeIdx++)
            {
                /* Save contex of SM IRQs enabled at NVIC level */
                nvicISER[wakeIdx] = NVIC->ISER[wakeIdx];

                /* Clear unused system-level IRQs */
                uint32_t maskVal = ~nvicISER[wakeIdx];
                NVIC->ICPR[wakeIdx] = 0xFFFFFFFFU & maskVal;

                /* Add system-level wake events */
                maskVal &= sysWakeMask[wakeIdx];

                /* Update GPC wake mask */
                CPU_IrqWakeSet(CPU_IDX_M33P, wakeIdx, maskVal);

                /* Update NVIC wake mask */
                NVIC->ICER[wakeIdx] = 0xFFFFFFFFU;
                NVIC->ISER[wakeIdx] = ~maskVal;
            }

            /* Configure M33P to wake from GPC */
            CPU_WakeMuxSet(CPU_IDX_M33P, false);

            /* Set target M33P sleep mode */
            CPU_SleepModeSet(CPU_IDX_M33P, sleepMode);

            /* For all clock roots not being sourced from FRO, switch clock source
             * to OSC_24M to allow PLLs to be powered down.  OSC_24M will be gated
             * during STANDBY.
             */
            for (rootIdx = 0U; rootIdx < CLOCK_NUM_ROOT; rootIdx++)
            {
                /* Save clock root context */
                s_clkRootCtrl[rootIdx] = CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW;

                /* Extract clock root mux setting */
                uint32_t rootMux = (s_clkRootCtrl[rootIdx] & CCM_CLOCK_ROOT_MUX_MASK)
                    >> CCM_CLOCK_ROOT_MUX_SHIFT;

                /* Switch all roots not sourced from FRO to OSC_24M / 1*/
                if (g_clockRootMux[rootIdx][rootMux] != CLOCK_SRC_FRO)
                {
                    /* Set MUX = 0 (OSC_24M) */
                    CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.CLR =
                        CCM_CLOCK_ROOT_MUX_MASK;

                    /* Set DIV = 0 (/1) */
                    CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.CLR =
                        CCM_CLOCK_ROOT_DIV_MASK;
                }
            }

            /* Power down SYSPLL clock nodes */
            clkSrcIdx = CLOCK_SRC_SYSPLL1_PFD2_DIV2;
            while(clkSrcIdx >= CLOCK_SRC_SYSPLL1_VCO)
            {
                CLOCK_SourceSetEnable(clkSrcIdx, false);
                clkSrcIdx--;
            }

            /* Board-level sleep entry */
            BOARD_SystemSleepEnter(sleepMode);

            /* Process SM LPIs for sleep entry */
            CPU_PerLpiProcess(CPU_IDX_M33P, sleepMode);

            /* Enter WFI to trigger sleep entry */
            __DSB();
            __WFI();
            __ISB();

            /* Process SM LPIs for sleep exit */
            CPU_PerLpiProcess(CPU_IDX_M33P, CPU_SLEEP_MODE_RUN);

            /* Board-level sleep exit */
            BOARD_SystemSleepExit(sleepMode);

            /* Power up SYSPLL clock nodes */
            clkSrcIdx = CLOCK_SRC_SYSPLL1_VCO;
            while(clkSrcIdx <= CLOCK_SRC_SYSPLL1_PFD2_DIV2)
            {
                CLOCK_SourceSetEnable(clkSrcIdx, true);
                clkSrcIdx++;
            }

            /* Restore clock roots */
            for (rootIdx = 0U; rootIdx < CLOCK_NUM_ROOT; rootIdx++)
            {
                /* Restore DIV */
                CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.SET =
                    s_clkRootCtrl[rootIdx] & CCM_CLOCK_ROOT_DIV_MASK;

                /* Restore MUX = 0 */
                CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.SET =
                    s_clkRootCtrl[rootIdx] & CCM_CLOCK_ROOT_MUX_MASK;
            }

            /* If WAKEUPMIX powered down during SUSPEND, reenable handshake and
             * force power up processing
             */
            if (lpmSettingWakeup <= sleepMode)
            {
                PWR_LpHandshakeMaskSet(PWR_MIX_SLICE_IDX_WAKEUP, true);
                DEV_SM_PowerUpPost(DEV_SM_PD_WAKEUP);
            }

            /* If NOCMIX powered down during SUSPEND, reenable handshake and
             * force power up processing
             */
            if (lpmSettingNoc <= sleepMode)
            {
                PWR_LpHandshakeMaskSet(PWR_MIX_SLICE_IDX_WAKEUP, true);
                DEV_SM_PowerUpPost(DEV_SM_PD_NOC);
            }

            /* Restore SM NVIC */
            for (uint32_t wakeIdx = 0;
                wakeIdx < GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT;
                wakeIdx++)
            {
                NVIC->ICER[wakeIdx] = 0xFFFFFFFFU;
                NVIC->ISER[wakeIdx] = nvicISER[wakeIdx];
            }

            /* Board-level sleep unprepare */
            BOARD_SystemSleepUnprepare(sleepMode);
        }
    }

    /* Restore GPC wake masks for sleeping CPUs */
    for (uint32_t cpuIdx = 0U; cpuIdx < CPU_NUM_IDX; cpuIdx++)
    {
        if (cpuIdx != CPU_IDX_M33P)
        {
            /* Check if sleep is forced for the CPU */
            bool sleepForce;
            if (CPU_SleepForceGet(cpuIdx, &sleepForce))
            {
                /* If sleep is not forced, manage GPC masks */
                if (!sleepForce)
                {
                    /* IRQs enabled at NVIC level become GPC wake sources */
                    for (uint32_t wakeIdx = 0;
                        wakeIdx < GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT;
                        wakeIdx++)
                    {
                        CPU_IrqWakeSet(cpuIdx, wakeIdx,
                            cpuWakeMask[cpuIdx][wakeIdx]);
                    }
                }
            }
        }
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Idle the system                                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemIdle(void)
{
    int32_t status = SM_ERR_SUCCESS;

    __disable_irq();

    /* Check if conditions allow system sleep */
    uint32_t sysSleepStat;
    if (CPU_SystemSleepStatusGet(&sysSleepStat))
    {
        if (sysSleepStat == CPU_SLEEP_MODE_SUSPEND)
        {
            printf("+Sleep\n");
            status = DEV_SM_SystemSleep(CPU_SLEEP_MODE_SUSPEND);
            printf("-Sleep\n");
        }
        /* Otherwise stay in RUN mode and enter WFI */
        else
        {
            (void) CPU_SleepModeSet(CPU_IDX_M33P, CPU_SLEEP_MODE_RUN);
            __DSB();
            __WFI();
            __ISB();
        }
    }
    __enable_irq();

    return status;
}
