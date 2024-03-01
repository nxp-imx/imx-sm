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
#define DEV_SM_NUM_SLEEP_ROOTS  3U

/* Local types */

/* Local variables */

static uint32_t s_powerMode = 0U;
static dev_sm_rst_rec_t s_shutdownRecord = { 0 };
static dev_sm_sys_sleep_rec_t s_sysSleepRecord;

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

#if 0
    /* TODO:  Enable GPC-to-ELE handshake */
    GPC_GLOBAL->GPC_SENTINEL_HDSK_CTRL = 1U;

    /* TODO:  Use DEEPSLEEP output of M33 to reflect GPC sleep request */
    BLK_CTRL_NS_AONMIX->GPC_CFG |=
        BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_MASK;
#endif

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
        [DEV_SM_REASON_SM_ERR] =      "sm_err",
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
    (void) DEV_SM_SystemRstComp(resetRec);
}

/*--------------------------------------------------------------------------*/
/* Sleep the system                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SystemSleep(uint32_t sleepMode)
{
    static const uint32_t s_clkRootSleepList[DEV_SM_NUM_SLEEP_ROOTS] =
    {
        [0] = CLOCK_ROOT_SENTINEL,
        [1] = CLOCK_ROOT_BUSAON,
        [2] = CLOCK_ROOT_M33
    };
    static const uint32_t s_pllVcoList[CLOCK_NUM_PLL] =
    {
        [CLOCK_PLL_SYS1] = CLOCK_SRC_SYSPLL1_VCO,
        [CLOCK_PLL_AUDIO1] = CLOCK_SRC_AUDIOPLL1_VCO,
        [CLOCK_PLL_AUDIO2] = CLOCK_SRC_AUDIOPLL2_VCO,
        [CLOCK_PLL_VIDEO1] = CLOCK_SRC_VIDEOPLL1_VCO,
        [CLOCK_PLL_ARM] = CLOCK_SRC_ARMPLL_VCO,
        [CLOCK_PLL_DRAM] = CLOCK_SRC_DRAMPLL_VCO,
        [CLOCK_PLL_HSIO] = CLOCK_SRC_HSIOPLL_VCO,
        [CLOCK_PLL_LDB] = CLOCK_SRC_LDBPLL_VCO
    };
    static src_mem_slice_t *const s_srcMemPtrs[] = SRC_MEM_BASE_PTRS;

    int32_t status = SM_ERR_SUCCESS;
    uint32_t s_clkRootCtrl[DEV_SM_NUM_SLEEP_ROOTS];
    uint32_t cpuWakeMask[CPU_NUM_IDX][GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT];
    uint32_t sysWakeMask[GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT];
    uint32_t nvicISER[GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT];

    /* Capture start of sleep entry */
    uint64_t sleepEntryStart = DEV_SM_Usec64Get();
    uint64_t sleepExitStart = sleepEntryStart;

    /* Reset wake source of sleep record */
    s_sysSleepRecord.wakeSource = 0U;

    /* Capture power status of MIXes */
    s_sysSleepRecord.mixPwrStat = 0U;
    for (uint32_t mixIdx = 0U; mixIdx < PWR_NUM_MIX_SLICE; mixIdx++)
    {
        if (SRC_MixIsPwrSwitchOn(mixIdx))
        {
            s_sysSleepRecord.mixPwrStat |= (1UL << mixIdx);
        }
    }

    /* Capture power status of memories */
    s_sysSleepRecord.memPwrStat = 0U;
    for (uint32_t memIdx = 0U; memIdx < PWR_NUM_MEM_SLICE; memIdx++)
    {
        const src_mem_slice_t *srcMem = s_srcMemPtrs[memIdx];
        if ((srcMem->MEM_CTRL & SRC_MEM_MEM_CTRL_MEM_LP_MODE_MASK) != 0U)
        {
            s_sysSleepRecord.memPwrStat |= (1UL << memIdx);
        }
    }

    /* Capture power status of PLLs */
    s_sysSleepRecord.pllPwrStat = 0U;
    for (uint32_t pllIdx = 0U; pllIdx < CLOCK_NUM_PLL; pllIdx++)
    {
        uint32_t sourceIdx = s_pllVcoList[pllIdx];
        if (CLOCK_SourceGetEnable(sourceIdx))
        {
            s_sysSleepRecord.pllPwrStat |= (1UL << pllIdx);
        }
    }

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
                        if (CPU_IrqWakeGet(cpuIdx, wakeIdx, &wakeVal))
                        {
                            cpuWakeMask[cpuIdx][wakeIdx] = wakeVal;
                            sysWakeMask[wakeIdx] &= wakeVal;
                            (void) CPU_IrqWakeSet(cpuIdx, wakeIdx, 0xFFFFFFFFU);
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
            /* Board-level sleep prepare */
            BOARD_SystemSleepPrepare(sleepMode);

            /* If NOCMIX powered down during SUSPEND, force power down */
            if (lpmSettingNoc <= sleepMode)
            {
                if (DEV_SM_PowerStateSet(DEV_SM_PD_NOC, DEV_SM_POWER_STATE_OFF)
                    == SM_ERR_SUCCESS)
                {
                    s_sysSleepRecord.mixPwrStat &=
                        (~(1UL << PWR_MIX_SLICE_IDX_NOC));
                }
            }

            /* If WAKEUPMIX powered down during SUSPEND, force power down */
            if ((lpmSettingWakeup <= sleepMode) &&
                ((CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk) == 0x0U))
            {
                if (DEV_SM_PowerStateSet(DEV_SM_PD_WAKEUP, DEV_SM_POWER_STATE_OFF)
                    == SM_ERR_SUCCESS)
                {
                    s_sysSleepRecord.mixPwrStat &=
                        (~(1UL << PWR_MIX_SLICE_IDX_WAKEUP));
                }
            }

            /* Inhibit all GPC LP handshakes during SUSPEND */
            uint32_t lpHsSm = BLK_CTRL_S_AONMIX->LP_HANDSHAKE_SM;
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE_SM = 0U;
            uint32_t lpHs2Sm = BLK_CTRL_S_AONMIX->LP_HANDSHAKE2_SM;
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE2_SM = 0U;
            uint32_t lpHsEle = BLK_CTRL_S_AONMIX->LP_HANDSHAKE_SENTINEL;
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE_SENTINEL = 0U;
            uint32_t lpHs2Ele = BLK_CTRL_S_AONMIX->LP_HANDSHAKE2_SENTINEL;
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE2_SENTINEL = 0U;

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
                (void) CPU_IrqWakeSet(CPU_IDX_M33P, wakeIdx, maskVal);

                /* Update NVIC wake mask */
                NVIC->ICER[wakeIdx] = 0xFFFFFFFFU;
                NVIC->ISER[wakeIdx] = ~maskVal;
            }

            /* Configure M33P to wake from GPC */
            (void) CPU_WakeMuxSet(CPU_IDX_M33P, false);

            /* Set target M33P sleep mode */
            (void) CPU_SleepModeSet(CPU_IDX_M33P, sleepMode);

            /* TODO:  Apply configuration based on
             *      SCMI system power mode flags
             */

            /* Shut off OSC_24M during system sleep */
            GPC_GLOBAL->GPC_ROSC_CTRL =
                GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_MASK;

            /* Enable GPC PMIC standby control */
            GPC_GLOBAL->GPC_PMIC_CTRL =
                GPC_GLOBAL_GPC_PMIC_CTRL_PMIC_STBY_EN_MASK;

            /* Power down eFUSE */
            GPC_GLOBAL->GPC_EFUSE_CTRL =
                GPC_GLOBAL_GPC_EFUSE_CTRL_EFUSE_PD_EN_MASK;

            /* Move ELE and SM clock roots to OSC_24M to allow SysPLL to be
             * powered down.  OSC_24M may be gated by hardware during final phases
             * of system SUSPEND entry.
             */
            for (uint32_t sleepRootIdx = 0U;
                sleepRootIdx < DEV_SM_NUM_SLEEP_ROOTS;
                sleepRootIdx++)
            {
                uint32_t rootIdx = s_clkRootSleepList[sleepRootIdx];

                /* Save clock root context */
                s_clkRootCtrl[sleepRootIdx] =
                    CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW;

                /* Set MUX = 0 (OSC_24M) */
                CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.CLR =
                    CCM_CLOCK_ROOT_MUX_MASK;

                /* Set DIV = 0 (/1) */
                CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.CLR =
                    CCM_CLOCK_ROOT_DIV_MASK;
            }

            /* Power down SYSPLL clock nodes */
            uint32_t clkSrcIdx = CLOCK_SRC_SYSPLL1_PFD2_DIV2;
            while(clkSrcIdx >= CLOCK_SRC_SYSPLL1_VCO)
            {
                (void) CLOCK_SourceSetEnable(clkSrcIdx, false);
                clkSrcIdx--;
            }
            s_sysSleepRecord.pllPwrStat &= (~(1UL << CLOCK_PLL_SYS1));

            /* Board-level sleep entry */
            BOARD_SystemSleepEnter(sleepMode);

            /* Process SM LPIs for sleep entry */
            (void) CPU_PerLpiProcess(CPU_IDX_M33P, sleepMode);

            /* Power down FRO */
            FRO->CSR.CLR = FRO_CSR_FROEN_MASK;

            /* Capture sleep entry latency */
            s_sysSleepRecord.sleepEntryUsec =
               UINT64_L(DEV_SM_Usec64Get() - sleepEntryStart);

            /* Enter WFI to trigger sleep entry */
            __DSB();
            __WFI();
            __ISB();

            /* Capture start of sleep exit */
            sleepExitStart = DEV_SM_Usec64Get();

            /* Power up FRO */
            FRO->CSR.SET = FRO_CSR_FROEN_MASK;

            /* Capture wake source */
            s_sysSleepRecord.wakeSource =
                (SCB->ICSR & SCB_ICSR_VECTPENDING_Msk)
                >> SCB_ICSR_VECTPENDING_Pos;

            /* Process SM LPIs for sleep exit */
            (void) CPU_PerLpiProcess(CPU_IDX_M33P, CPU_SLEEP_MODE_RUN);

            /* Board-level sleep exit */
            BOARD_SystemSleepExit(sleepMode);

            /* Power up SYSPLL clock nodes */
            clkSrcIdx = CLOCK_SRC_SYSPLL1_VCO;
            while(clkSrcIdx <= CLOCK_SRC_SYSPLL1_PFD2_DIV2)
            {
                (void) CLOCK_SourceSetEnable(clkSrcIdx, true);
                clkSrcIdx++;
            }

            /* Restore ELE and SM clock roots */
            for (uint32_t sleepRootIdx = 0U;
                sleepRootIdx < DEV_SM_NUM_SLEEP_ROOTS;
                sleepRootIdx++)
            {
                uint32_t rootIdx = s_clkRootSleepList[sleepRootIdx];

                /* Restore DIV */
                CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.SET =
                    s_clkRootCtrl[sleepRootIdx] & CCM_CLOCK_ROOT_DIV_MASK;

                /* Restore MUX */
                CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.SET =
                    s_clkRootCtrl[sleepRootIdx] & CCM_CLOCK_ROOT_MUX_MASK;
            }

            /* TODO:  Apply configuration based on
             *      SCMI system power mode flags
             */

            /* Power up eFUSE */
            GPC_GLOBAL->GPC_EFUSE_CTRL = 0U;

            /* Restore GPC LP handshakes */
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE_SM = lpHsSm;
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE2_SM = lpHs2Sm;
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE_SENTINEL = lpHsEle;
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE2_SENTINEL = lpHs2Ele;

            /* If WAKEUPMIX powered down during SUSPEND, force power up */
            if (lpmSettingWakeup <= sleepMode)
            {
                (void) DEV_SM_PowerStateSet(DEV_SM_PD_WAKEUP, DEV_SM_POWER_STATE_ON);
            }

            /* If NOCMIX powered down during SUSPEND, force power up */
            if (lpmSettingNoc <= sleepMode)
            {
                (void) DEV_SM_PowerStateSet(DEV_SM_PD_NOC, DEV_SM_POWER_STATE_ON);
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

    /* Check if system did not sleep */
    if (s_sysSleepRecord.wakeSource == 0U)
    {
        sleepExitStart = DEV_SM_Usec64Get();
        s_sysSleepRecord.sleepEntryUsec =
           UINT64_L(sleepExitStart - sleepEntryStart);
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
                        (void) CPU_IrqWakeSet(cpuIdx, wakeIdx,
                            cpuWakeMask[cpuIdx][wakeIdx]);
                    }
                }
            }
        }
    }

    s_sysSleepRecord.sleepExitUsec =
       UINT64_L(DEV_SM_Usec64Get() - sleepExitStart);

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
            printf("-Sleep (wake vector = %u)\n", s_sysSleepRecord.wakeSource);

            printf("MIX power status = 0x%08X\n", s_sysSleepRecord.mixPwrStat);
            printf("MEM power status = 0x%08X\n", s_sysSleepRecord.memPwrStat);
            printf("PLL power status = 0x%08X\n", s_sysSleepRecord.pllPwrStat);
            printf("Sleep latency = %u usec\n", s_sysSleepRecord.sleepEntryUsec);
            printf("Wake latency = %u usec\n", s_sysSleepRecord.sleepExitUsec);
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

/*--------------------------------------------------------------------------*/
/* Return system sleep record                                               */
/*--------------------------------------------------------------------------*/
void DEV_SM_SystemSleepRecGet(dev_sm_sys_sleep_rec_t *sysSleepRecord)
{
    /* Copy out system sleep record */
    *sysSleepRecord = s_sysSleepRecord;
}
