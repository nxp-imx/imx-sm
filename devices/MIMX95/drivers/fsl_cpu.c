/*
 * Copyright 2023 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Includes */
#include "sm.h"
#include "fsl_cpu.h"
#include "fsl_mu.h"
#include "fsl_power.h"
#include "fsl_reset.h"
#include "fsl_src.h"
#include "fsl_device_registers.h"

/* Local Defines */

/* Local Types */

/* Local Functions */
static bool CPU_SwWakeup(uint32_t cpuIdx);
static bool CPU_SwMultiWakeup(uint32_t cpuIdx);
static bool CPU_SleepModeMultiSet(uint32_t cpuIdx, uint32_t sleepMode);
static bool CPU_WdogReset(uint32_t cpuIdx);
static bool CPU_MuReset(uint32_t cpuIdx);
static bool CPU_MiscCtrlSet(uint32_t cpuIdx, uint32_t mask, uint32_t val);
static bool CPU_MiscCtrlGet(uint32_t cpuIdx, uint32_t mask, uint32_t *val);
static bool CPU_LpmMixDependSet(uint32_t cpuIdx, uint32_t lpmSetting);

/* Local Variables */
static GPC_CPU_CTRL_Type *const s_gpcCpuCtrlPtrs[] = GPC_CPU_CTRL_BASE_PTRS;
static GICR_Type *const s_gicrPtrs[] = GICR_BASE_PTRS;

static uint32_t s_cpuDdrMixDependMask;
static uint32_t s_cpuNocMixDependMask;
static uint32_t s_cpuWakeMixDependMask;

static cpu_wdog_info_t const s_cpuWdogInfoM7P =
{
    .secIrq = NotAvail_IRQn,
    .nonsecIrq = WDOG5_IRQn,
    .rstLine = RST_LINE_WAKEUPMIX_WDOG_5
};

static cpu_wdog_info_t const s_cpuWdogInfoA55 =
{
    .secIrq = WDOG3_IRQn,
    .nonsecIrq = WDOG4_IRQn,
    .rstLine = RST_LINE_WAKEUPMIX_WDOG_3_4
};

static cpu_mgmt_info_t const s_cpuMgmtInfo[CPU_NUM_IDX] =
{
    [CPU_IDX_M33P] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_AON,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->M33_CFG,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = NULL,
        .vectorRegHigh = NULL,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->INITSVTOR,
        .vectorShift = 0U,
        .cmcSysSleepCtrl = GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK
    },

    [CPU_IDX_M7P] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_M7,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->M7_CFG,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_M7_CFG_WAIT_MASK,
        .rstReqIrq = CM7_SYSRESETREQ_IRQn,
        .lockupIrq = CM7_LOCKUP_IRQn,
        .wdogInfo = &s_cpuWdogInfoM7P,
        .vectorRegHigh = NULL,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->INITVTOR,
        .vectorShift = 0U,
        .cmcSysSleepCtrl = GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK
    },

    [CPU_IDX_A55C0] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55C0,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->CA55_CPUWAIT,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR0_H,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR0_L,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = 0U,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    },

    [CPU_IDX_A55C1] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55C1,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->CA55_CPUWAIT,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR1_H,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR1_L,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = 0U,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    },

    [CPU_IDX_A55C2] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55C2,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->CA55_CPUWAIT,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR2_H,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR2_L,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = 0U,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    },

    [CPU_IDX_A55C3] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55C3,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->CA55_CPUWAIT,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR3_H,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR3_L,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = 0U,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    },

    [CPU_IDX_A55C4] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55C4,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->CA55_CPUWAIT,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU4_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR4_H,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR4_L,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = 0U,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    },

    [CPU_IDX_A55C5] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55C5,
        .cpuWaitReg = &BLK_CTRL_S_AONMIX->CA55_CPUWAIT,
        .cpuWaitMask = BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU5_WAIT_MASK,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR5_H,
        .vectorRegLow = &BLK_CTRL_S_AONMIX->CA55_RVBARADDR5_L,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = 0U,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    },

    [CPU_IDX_A55P] =
    {
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55P,
        .cpuWaitReg = NULL,
        .cpuWaitMask = 0U,
        .rstReqIrq = NotAvail_IRQn,
        .lockupIrq = NotAvail_IRQn,
        .wdogInfo = &s_cpuWdogInfoA55,
        .vectorRegHigh = NULL,
        .vectorRegLow = NULL,
        .vectorShift = 2U,
        .cmcSysSleepCtrl = GPC_CPU_CTRL_CMC_SYS_SLEEP_CTRL_SS_SUSPEND_MASK,
        .cmcMisc = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK
    }
};

/* Global Variables */

extern void GPC_SM_REQ_IRQHandler(void);

/*--------------------------------------------------------------------------*/
/* Initialize CMC/GPC interfaces for the CPU                                */
/*--------------------------------------------------------------------------*/
bool CPU_Init(uint32_t cpuIdx)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Configure system-level sleep control default */
        uint32_t sysSleepCtrl = s_cpuMgmtInfo[cpuIdx].cmcSysSleepCtrl;
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_SYS_SLEEP_CTRL = sysSleepCtrl;

        /* Configure IRQ_MUX and SLEEPHOLD default */
        uint32_t cmcMisc = s_cpuMgmtInfo[cpuIdx].cmcMisc;
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MISC = cmcMisc;

        /* CPUs supporting SLEEPHOLD should not enable A55 handshake */
        if ((cmcMisc & GPC_CPU_CTRL_CMC_MISC_SLEEP_HOLD_EN_MASK) != 0U)
        {
            s_gpcCpuCtrlPtrs[cpuIdx]->CMC_SLEEP_A55_HDSK_CTRL |= 
                GPC_CPU_CTRL_CMC_SLEEP_A55_HDSK_CTRL_DISABLE_MASK;

            s_gpcCpuCtrlPtrs[cpuIdx]->CMC_WAKEUP_A55_HDSK_CTRL |= 
                GPC_CPU_CTRL_CMC_WAKEUP_A55_HDSK_CTRL_DISABLE_MASK;
        }

        /* Apply GPC domain assignment */
        GPC_GLOBAL->GPC_CPU_DOMAIN_ASSIGNMENT[cpuIdx] = CPU2GPC(cpuIdx);

        /* Unforce sleep mode at GPC level  */
        rc = CPU_SleepForceSet(cpuIdx, false);
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPUWAIT signal                                                       */
/*--------------------------------------------------------------------------*/
bool CPU_WaitSet(uint32_t cpuIdx, bool enableCpuWait)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (s_cpuMgmtInfo[cpuIdx].cpuWaitReg != NULL)
        {
            __IO uint32_t *cpuWaitReg = s_cpuMgmtInfo[cpuIdx].cpuWaitReg;

            uint32_t cpuWaitVal = *cpuWaitReg;

            if (enableCpuWait)
            {
                cpuWaitVal |= s_cpuMgmtInfo[cpuIdx].cpuWaitMask;
            }
            else
            {
                cpuWaitVal &= ~s_cpuMgmtInfo[cpuIdx].cpuWaitMask;
            }

            *cpuWaitReg = cpuWaitVal;

            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPUWAIT signal                                                       */
/*--------------------------------------------------------------------------*/
bool CPU_WaitGet(uint32_t cpuIdx, bool *cpuWait)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (s_cpuMgmtInfo[cpuIdx].cpuWaitReg != NULL)
        {
            __IO const uint32_t *cpuWaitReg = s_cpuMgmtInfo[cpuIdx].cpuWaitReg;

            if ((*cpuWaitReg & s_cpuMgmtInfo[cpuIdx].cpuWaitMask) == 0U)
            {
                *cpuWait = false;
            }
            else
            {
                *cpuWait = true;
            }

            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Generate SW_WAKEUP event                                                 */
/*--------------------------------------------------------------------------*/
static bool CPU_SwWakeup(uint32_t cpuIdx)
{
    bool rc = false;

    /* Assert SW_WAKEUP */
    rc = CPU_MiscCtrlSet(cpuIdx,
        GPC_CPU_CTRL_CMC_MISC_SW_WAKEUP_MASK,
        GPC_CPU_CTRL_CMC_MISC_SW_WAKEUP_MASK);

    /* Wait for CPU to wake */
    if (rc)
    {
        uint32_t fsmStat;
        do
        {
            rc = CPU_FsmStateGet(cpuIdx, &fsmStat);
        } while (rc && (fsmStat == CPU_FSM_STATE_IDLE_SLEEP));
    }

    /* Deassert SW_WAKEUP */
    if (rc)
    {
        rc = CPU_MiscCtrlSet(cpuIdx,
            GPC_CPU_CTRL_CMC_MISC_SW_WAKEUP_MASK,
            0);
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Generate SW_WAKEUP event for multiple CPUs                               */
/*--------------------------------------------------------------------------*/
static bool CPU_SwMultiWakeup(uint32_t cpuIdx)
{
    bool rc = false;

    uint32_t cpuIdxCur = cpuIdx;
    uint32_t cpuIdxEnd = cpuIdx;
    if (cpuIdx == CPU_IDX_A55P)
    {
        cpuIdxCur = CPU_IDX_A55C0;
        cpuIdxEnd = CPU_IDX_A55P;
    }
    do
    {
        /* Wake each CPU */
        rc = CPU_SwWakeup(cpuIdxCur);
        ++cpuIdxCur;
    } while (rc && (cpuIdxCur <= cpuIdxEnd));

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Reset CPU WDOG modules                                                   */
/*--------------------------------------------------------------------------*/
static bool CPU_WdogReset(uint32_t cpuIdx)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        cpu_wdog_info_t const *wdogInfo = s_cpuMgmtInfo[cpuIdx].wdogInfo;

        if (wdogInfo != NULL)
        {
            /* Assert WDOG module reset */
            uint32_t rstline = wdogInfo->rstLine;
            rc = SRC_MixSetResetLine(rstline, RST_LINE_CTRL_ASSERT);
            
            /* Wait for reset assertion to complete */
            uint32_t resetType = RST_LINE_CTRL_UNKNOWN;
            while (rc && (resetType != RST_LINE_CTRL_ASSERT))
            {
                rc = SRC_MixGetResetLine(rstline, &resetType);
            }
            
            /* Deassert WDOG module reset */
            if (rc)
            {
                rc = SRC_MixSetResetLine(rstline, RST_LINE_CTRL_DEASSERT);
            }
            
            /* Wait for reset deassertion to complete */
            resetType = RST_LINE_CTRL_UNKNOWN;
            while (rc && (resetType != RST_LINE_CTRL_DEASSERT))
            {
                rc = SRC_MixGetResetLine(rstline, &resetType);
            }
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Reset CPU MU modules                                                     */
/*--------------------------------------------------------------------------*/
static bool CPU_MuReset(uint32_t cpuIdx)
{
    bool rc = false;

    switch(cpuIdx)
    {
        case CPU_IDX_M7P:
            MU_ResetBothSides(AON__MUI_A5__MUB);
            rc = true;
            break;

        case CPU_IDX_A55P:
            MU_ResetBothSides(AON__MUI_A1__MUB);
            MU_ResetBothSides(AON__MUI_A2__MUB);
            MU_ResetBothSides(AON__MUI_A3__MUB);
            MU_ResetBothSides(AON__MUI_A4__MUB);
            rc = true;
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable CPU IRQs                                                  */
/*--------------------------------------------------------------------------*/
bool CPU_IrqSet(uint32_t cpuIdx, bool enableCpuIrq)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        IRQn_Type rstReqIrq = s_cpuMgmtInfo[cpuIdx].rstReqIrq;
        if (rstReqIrq != NotAvail_IRQn)
        {
            if (enableCpuIrq)
            {
                /* Configure CPU SYSRESETREQ handler */
                NVIC_EnableIRQ(rstReqIrq);
            }
            else
            {
                NVIC_DisableIRQ(rstReqIrq);
            }
        }

        IRQn_Type lockupIrq = s_cpuMgmtInfo[cpuIdx].lockupIrq;
        if (lockupIrq != NotAvail_IRQn)
        {
            if (enableCpuIrq)
            {
                /* Configure CPU LOCKUP handler */
                NVIC_EnableIRQ(lockupIrq);
            }
            else
            {
                NVIC_DisableIRQ(lockupIrq);
                NVIC_ClearPendingIRQ(lockupIrq);
            }
        }
        
        IRQn_Type secWdogIrq = NotAvail_IRQn;
        IRQn_Type nonsecWdogIrq = NotAvail_IRQn;
        cpu_wdog_info_t const *wdogInfo = s_cpuMgmtInfo[cpuIdx].wdogInfo;
        if (wdogInfo != NULL)
        {
            secWdogIrq = wdogInfo->secIrq;
            nonsecWdogIrq = wdogInfo->nonsecIrq;
        }

        if (secWdogIrq != NotAvail_IRQn)
        {
            if (enableCpuIrq)
            {
                /* Only configure once per cluster */
                if (NVIC_GetEnableIRQ(secWdogIrq) == 0U)
                {
                    /* Configure secure WDOG handler */
                    NVIC_EnableIRQ(secWdogIrq);
                }
            }
            else
            {
                NVIC_DisableIRQ(secWdogIrq);
            }
        }

        if (nonsecWdogIrq != NotAvail_IRQn)
        {
            if (enableCpuIrq)
            {
                /* Only configure once per cluster */
                if (NVIC_GetEnableIRQ(nonsecWdogIrq) == 0U)
                {
                    /* Configure secure WDOG handler */
                    NVIC_EnableIRQ(nonsecWdogIrq);
                }
            }
            else
            {
                NVIC_DisableIRQ(nonsecWdogIrq);
            }
        }
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set GPC shandshakes associated with CPU                                  */
/*--------------------------------------------------------------------------*/
bool CPU_GpcHandshakeSet(uint32_t cpuIdx,bool enableHandshake)
{
    bool rc = false;

    switch(cpuIdx)
    {
        case CPU_IDX_M7P:
            PWR_LpHandshakeMaskSet(PWR_MIX_SLICE_IDX_M7, enableHandshake);
            rc = true;
            break;

        case CPU_IDX_A55P:
            {
                PWR_LpHandshakeMaskSet(PWR_MIX_SLICE_IDX_A55P, enableHandshake);
                uint32_t srcMixIdx = PWR_MIX_SLICE_IDX_A55C0;
                while (srcMixIdx <= PWR_MIX_SLICE_IDX_A55C_LAST)
                {
                    PWR_LpHandshakeMaskSet(srcMixIdx, enableHandshake);
                    srcMixIdx++;
                }
            }
            rc = true;
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU reset signal                                                     */
/*--------------------------------------------------------------------------*/
bool CPU_ResetSet(uint32_t cpuIdx, uint32_t resetType)
{
    bool rc = false;

    switch(cpuIdx)
    {
        case CPU_IDX_M7P:
            rc = SRC_MixSetResetLine(RST_LINE_M7MIX, resetType);
            if (rc && (resetType == RST_LINE_CTRL_ASSERT))
            {
                rc = CPU_WaitSet(CPU_IDX_M7P, true);
            }
            break;

        case CPU_IDX_A55P:
            {
                /* Prior to reset of A55, quiese the GIC interfaces */
                if (resetType == RST_LINE_CTRL_ASSERT)
                {
                    uint32_t gicdIdxLast = CPU_IDX_A55C_LAST - CPU_IDX_A55C0;
                    for (uint32_t gicdIdx = 0U; gicdIdx <= gicdIdxLast; gicdIdx++)
                    {
                        GICR_Type *GICR = s_gicrPtrs[gicdIdx];

                        /* Set ProcessorSleep to quiesce GIC redistributor instance */
                        GICR->GICR_WAKER |= GICR_WAKER_PROCESSORSLEEP_MASK;

                        /* Wait for ChildrenAsleep */
                        while ((GICR->GICR_WAKER & GICR_WAKER_CHILDRENASLEEP_MASK) == 0U)
                        {
                            ; /* Intentional empty while */
                        }
                    }
                }

                /* Apply reset to A55 cluster */
                rc = SRC_MixSetResetLine(RST_LINE_CORTEXAMIX_PLATFORM, resetType);

                /* Apply reset to all A55 CPUs */
                uint32_t lineIdx = RST_LINE_CORTEXAMIX_CORE0;
                uint32_t lineIdxEnd = RST_LINE_CORTEXAMIX_CORE0 + 
                                      CPU_IDX_A55C_LAST - CPU_IDX_A55C0;
                uint32_t cpuIdxA55 = CPU_IDX_A55C0;
                while(rc  && (lineIdx <= lineIdxEnd))
                {
                    uint32_t srcMixIdx = s_cpuMgmtInfo[cpuIdxA55].srcMixIdx;
                    /* Skip unpowered A55 CPUs */                    
                    if (SRC_MixIsPwrSwitchOn(srcMixIdx))
                    {
                        rc = SRC_MixSetResetLine(lineIdx, resetType);
                        if (rc && (resetType == RST_LINE_CTRL_ASSERT))
                        {
                            rc = CPU_WaitSet(cpuIdxA55, true);
                        }
                    }
                    ++lineIdx;
                    ++cpuIdxA55;
                }
            }
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU reset signal                                                     */
/*--------------------------------------------------------------------------*/
bool CPU_ResetGet(uint32_t cpuIdx, uint32_t *resetType)
{
    bool rc = false;

    switch(cpuIdx)
    {
        case CPU_IDX_M7P:
            rc = SRC_MixGetResetLine(RST_LINE_M7MIX, resetType);
            break;

        case CPU_IDX_A55P:
            {
                /* Get reset status of A55 cluster */
                rc = SRC_MixGetResetLine(RST_LINE_CORTEXAMIX_PLATFORM, 
                                         resetType);

                /* Check if reset status of A55 CPUs matches cluster  */
                uint32_t lineIdx = RST_LINE_CORTEXAMIX_CORE0;
                uint32_t lineIdxEnd = RST_LINE_CORTEXAMIX_CORE0 + 
                                      CPU_IDX_A55C_LAST - CPU_IDX_A55C0;
                uint32_t cpuIdxA55 = CPU_IDX_A55C0;
                while(rc  && (lineIdx <= lineIdxEnd) && 
                      (*resetType != RST_LINE_CTRL_UNKNOWN))
                {
                    uint32_t srcMixIdx = s_cpuMgmtInfo[cpuIdxA55].srcMixIdx;
                    /* Skip unpowered A55 CPUs */                    
                    if (SRC_MixIsPwrSwitchOn(srcMixIdx))
                    {
                        uint32_t resetTypeA55;
                        rc = SRC_MixGetResetLine(lineIdx, &resetTypeA55);
                        if (rc && (resetTypeA55 != *resetType))
                        {
                            *resetType = RST_LINE_CTRL_UNKNOWN;
                        }
                    }
                    ++lineIdx;
                    ++cpuIdxA55;
                }
            }
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU FSM state                                                        */
/*--------------------------------------------------------------------------*/
bool CPU_FsmStateGet(uint32_t cpuIdx, uint32_t *fsmState)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t modeStat = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MODE_STAT;
        *fsmState = (modeStat & GPC_CPU_CTRL_CMC_MODE_STAT_FSM_STATE_MASK) >>
            GPC_CPU_CTRL_CMC_MODE_STAT_FSM_STATE_SHIFT;

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU run mode                                                         */
/*--------------------------------------------------------------------------*/
bool CPU_RunModeSet(uint32_t cpuIdx, uint32_t runMode)
{
    bool rc = false;
    uint32_t curRunMode;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (CPU_RunModeGet(cpuIdx, &curRunMode))
        {
            switch(runMode)
            {
                case CPU_RUN_MODE_START:
                    /* if CPU stopped, power up respective mix and release */
                    if (curRunMode == CPU_RUN_MODE_STOP)
                    {
                        /* Make sure MIX of CPU is powered */
                        (void) SRC_MixSoftPowerUp(s_cpuMgmtInfo[cpuIdx].srcMixIdx);

                        /* Include CPU in HW-controlled MIX voting logic */
                        rc = CPU_LpmConfigInit(cpuIdx);

                        /* Release CPUWAIT */
                        if (rc)
                        {
                            rc = CPU_WaitSet(cpuIdx, false);
                        }

                        /* Enable SM IRQs associated with this CPU */
                        if (rc)
                        {
                            rc = CPU_IrqSet(cpuIdx, true);
                        }
                    }
                    /* If CPU sleeping, use SW_WAKEUP */
                    else if (curRunMode == CPU_RUN_MODE_SLEEP)
                    {
                        /* Perform SW wakeup */
                        rc = CPU_SwWakeup(cpuIdx);
                    }
                    /* If CPU in hold, release */
                    else if (curRunMode == CPU_RUN_MODE_HOLD)
                    {
                        /* Include CPU in HW-controlled MIX voting logic
                         *
                         * NOTE:  Current RUN mode for CPU started by ROM
                         *        will be HOLD.  Ensure LPM configuration
                         *        is done here even though it may be 
                         *        redundant for OFF -> HOLD -> START
                         */
                        rc = CPU_LpmConfigInit(cpuIdx);

                        /* Release CPUWAIT */
                        if (rc)
                        {
                            rc = CPU_WaitSet(cpuIdx, false);
                        }

                        /* Enable SM IRQs associated with this CPU */
                        if (rc)
                        {
                            rc = CPU_IrqSet(cpuIdx, true);
                        }
                    }
                    /* other current states should result in error */
                    else
                    {
                        ; /* Intentional empty else */
                    }
                    break;

                case CPU_RUN_MODE_HOLD:
                    /* if CPU stopped, power up respective mix and hold */
                    if (curRunMode == CPU_RUN_MODE_STOP)
                    {
                        /* Make sure MIX of CPU is powered */
                        (void) SRC_MixSoftPowerUp(s_cpuMgmtInfo[cpuIdx].srcMixIdx);

                        /* Include CPU in HW-controlled MIX voting logic */
                        rc = CPU_LpmConfigInit(cpuIdx);
                    }
                    /* other current states should result in error */
                    break;

                case CPU_RUN_MODE_STOP:
                    /* If CPU not already stopped, reset CPU and hold */
                    if (curRunMode != CPU_RUN_MODE_STOP)
                    {
                        /* Force MIX voting logic to request ON during reset */
                        rc = CPU_LpmConfigDeInit(cpuIdx, CPU_PD_LPM_ON_ALWAYS);

                        /* Reset CPU sleep mode */
                        if (rc)
                        {
                            rc = CPU_SleepModeMultiSet(cpuIdx, CPU_SLEEP_MODE_RUN);
                        }

                        /* Wake all sleeping CPUs */
                        if (rc)
                        {
                            /* Perform SW wakeup */
                            rc = CPU_SwMultiWakeup(cpuIdx);
                        }                        
                        
                        if (rc)
                        {
                            /* Process MIX handshakes until CPU MIX is ready */
                            while (!SRC_MixIsPwrReady(s_cpuMgmtInfo[cpuIdx].srcMixIdx))
                            {
                                if (NVIC_GetPendingIRQ(GPC_SM_REQ_IRQn) == 1U)
                                {
                                    GPC_SM_REQ_IRQHandler();
                                    NVIC_ClearPendingIRQ(GPC_SM_REQ_IRQn);
                                }
                            }

                            /* Inhibit GPC LP handshake during CPU reset */
                            rc = CPU_GpcHandshakeSet(cpuIdx, false);
                        }

                        /* Assert CPU platform reset to force stoppage */
                        if (rc)
                        {
                            rc = CPU_ResetSet(cpuIdx, RST_LINE_CTRL_ASSERT);
                        }

                        /* Wait for reset assertion to complete */
                        uint32_t resetType = RST_LINE_CTRL_UNKNOWN;
                        while (rc && (resetType != RST_LINE_CTRL_ASSERT))
                        {
                            rc = CPU_ResetGet(cpuIdx, &resetType);
                        }

                        /* Reset WDOGs for this CPU
                         *
                         * NOTE:  WDOGs associated with this CPU will be
                         *  reset to prevent NVIC of CPU being stoppped from 
                         *  latching a new occurrence of the WDOG IRQ after 
                         *  release of CPU reset.
                         */
                        if (rc)
                        {
                            rc = CPU_WdogReset(cpuIdx);
                        }

                        /* Deassert CPU platform reset */
                        if (rc)
                        {
                            rc = CPU_ResetSet(cpuIdx, RST_LINE_CTRL_DEASSERT);
                        }

                        /* Wait for reset deassertion to complete */
                        resetType = RST_LINE_CTRL_UNKNOWN;
                        while (rc && (resetType != RST_LINE_CTRL_DEASSERT))
                        {
                            rc = CPU_ResetGet(cpuIdx, &resetType);
                        }

                        /* Reset MUs associated with this CPU */
                        if (rc)
                        {
                            rc = CPU_MuReset(cpuIdx);
                        }

                        /* Disable SM IRQs associated with this CPU */
                        if (rc)
                        {
                            rc = CPU_IrqSet(cpuIdx, false);
                        }

                        /* Remove CPU from HW-controlled MIX voting logic */
                        if (rc)
                        {
                            rc = CPU_LpmConfigDeInit(cpuIdx, CPU_PD_LPM_ON_NEVER);
                        }

                        /* Restore GPC LP handshake */
                        if (rc)
                        {
                            rc = CPU_GpcHandshakeSet(cpuIdx, true);
                        }
                    }
                    /* other current states should result in error */
                    break;

                default:
                    ; /* Intentional empty default */
                    break;
            }
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU run mode                                                         */
/*--------------------------------------------------------------------------*/
bool CPU_RunModeGet(uint32_t cpuIdx, uint32_t *runMode)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (SRC_MixIsPwrReady(s_cpuMgmtInfo[cpuIdx].srcMixIdx))
        {
            uint32_t cpuIdxCur = cpuIdx;
            uint32_t cpuIdxEnd = cpuIdx;
            if (cpuIdx == CPU_IDX_A55P)
            {
                cpuIdxCur = CPU_IDX_A55C0;
                cpuIdxEnd = CPU_IDX_A55C_LAST;
            }
            do
            {
                bool cpuWait;
                rc = CPU_WaitGet(cpuIdxCur, &cpuWait);
                if (rc)
                {
                    if (cpuWait)
                    {
                        *runMode = CPU_RUN_MODE_HOLD;
                    }
                    else
                    {
                        *runMode = CPU_RUN_MODE_START;
                    }
                }
                ++cpuIdxCur;
            } while (rc && (cpuIdxCur <= cpuIdxEnd) && 
                    (*runMode == CPU_RUN_MODE_HOLD));
        }
        else
        {
            /* Check if CPU power gated as a result of entering SLEEP */
            uint32_t fsmState;
            rc = CPU_FsmStateGet(cpuIdx, &fsmState);
            if (rc)
            {
                if (fsmState != CPU_FSM_STATE_IDLE_RUN)
                {
                    *runMode = CPU_RUN_MODE_SLEEP;
                }
                else
                {
                    *runMode = CPU_RUN_MODE_STOP;
                }
            }
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU sleep mode                                                       */
/*--------------------------------------------------------------------------*/
bool CPU_SleepModeSet(uint32_t cpuIdx, uint32_t sleepMode)
{
    bool rc = false;

    if ((cpuIdx < CPU_NUM_IDX) && (sleepMode <= CPU_NUM_SLEEP_MODES))
    {
        uint32_t cmcModeCtrl = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MODE_CTRL;
        cmcModeCtrl &= (~GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET_MASK);
        cmcModeCtrl |= GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET(sleepMode);
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MODE_CTRL = cmcModeCtrl;

        /* All targeted sleep modes other than RUN need GPC-controlled LPM */
        uint32_t srcMixIdx = s_cpuMgmtInfo[cpuIdx].srcMixIdx;
        if ((g_pwrMixMgmtInfo[srcMixIdx].authenCtrl &
            AUTHEN_CTRL_LPM_MODE_MASK) != 0U)
        {
            rc = SRC_MixLpmModeSet(srcMixIdx, sleepMode != CPU_SLEEP_MODE_RUN);
        }
        else
        {
            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU sleep mode for multiple CPUs                                     */
/*--------------------------------------------------------------------------*/
static bool CPU_SleepModeMultiSet(uint32_t cpuIdx, uint32_t sleepMode)
{
    bool rc = false;

    if ((cpuIdx < CPU_NUM_IDX) && (sleepMode <= CPU_NUM_SLEEP_MODES))
    {
        uint32_t cpuIdxCur = cpuIdx;
        uint32_t cpuIdxEnd = cpuIdx;
        if (cpuIdx == CPU_IDX_A55P)
        {
            cpuIdxCur = CPU_IDX_A55C0;
            cpuIdxEnd = CPU_IDX_A55P;
        }
        do
        {
            /* Set sleep mode for each CPU */
            rc = CPU_SleepModeSet(cpuIdxCur, sleepMode);
            ++cpuIdxCur;
        } while (rc && (cpuIdxCur <= cpuIdxEnd));
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU sleep mode                                                       */
/*--------------------------------------------------------------------------*/
bool CPU_SleepModeGet(uint32_t cpuIdx, uint32_t *sleepMode)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        *sleepMode = (s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MODE_CTRL & 
            GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET_MASK) >> 
            GPC_CPU_CTRL_CMC_MODE_CTRL_CPU_MODE_TARGET_SHIFT;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU sleep force control                                              */
/*--------------------------------------------------------------------------*/
bool CPU_SleepForceSet(uint32_t cpuIdx, bool sleepForce)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t sleepForceReg = GPC_GLOBAL->GPC_SYS_SLEEP;
        uint32_t sleepMask =
            1UL << (cpuIdx + GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU_DISABLE_SHIFT);

        if (sleepForce)
        {
            sleepForceReg |= sleepMask;
        }
        else
        {
            sleepForceReg &= ~sleepMask;
        }

        GPC_GLOBAL->GPC_SYS_SLEEP = sleepForceReg;

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU sleep force control                                              */
/*--------------------------------------------------------------------------*/
bool CPU_SleepForceGet(uint32_t cpuIdx, bool *sleepForce)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t sleepForceReg = GPC_GLOBAL->GPC_SYS_SLEEP;
        uint32_t sleepMask =
            1UL << (cpuIdx + GPC_GLOBAL_GPC_SYS_SLEEP_FORCE_CPU_DISABLE_SHIFT);

        if ((sleepForceReg & sleepMask) != 0U)
        {
            *sleepForce = true;
        }
        else
        {
            *sleepForce = false;
        }

        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set system-level sleep control                                           */
/*--------------------------------------------------------------------------*/
bool CPU_SystemSleepSet(uint32_t cpuIdx, uint32_t sysSleep)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_SYS_SLEEP_CTRL = sysSleep;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get system-level sleep control                                           */
/*--------------------------------------------------------------------------*/
bool CPU_SystemSleepGet(uint32_t cpuIdx, uint32_t *sysSleep)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        *sysSleep = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_SYS_SLEEP_CTRL;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set misc CPU controls                                                    */
/*--------------------------------------------------------------------------*/
static bool CPU_MiscCtrlSet(uint32_t cpuIdx, uint32_t mask, uint32_t val)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t cmcMisc = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MISC;
        cmcMisc &= ~mask;
        cmcMisc |= val;
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MISC = cmcMisc;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get misc CPU controls                                                    */
/*--------------------------------------------------------------------------*/
static bool CPU_MiscCtrlGet(uint32_t cpuIdx, uint32_t mask, uint32_t *val)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        uint32_t cmcMisc = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_MISC;
        *val = cmcMisc & mask;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set wake mux (GPC/GIC)                                                   */
/*--------------------------------------------------------------------------*/
bool CPU_WakeMuxSet(uint32_t cpuIdx, bool gicWake)
{
    uint32_t val = 0U;

    if (gicWake)
    {
        val = GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK;
    }

    return CPU_MiscCtrlSet(cpuIdx, GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK, val);
}

/*--------------------------------------------------------------------------*/
/* Set wake mux (GPC/GIC)                                                   */
/*--------------------------------------------------------------------------*/
bool CPU_WakeMuxGet(uint32_t cpuIdx, bool *gicWake)
{
    uint32_t val = 0U;

    bool rc = CPU_MiscCtrlGet(cpuIdx, GPC_CPU_CTRL_CMC_MISC_IRQ_MUX_MASK, &val);

    if (rc)
    {
        if (val != 0U)
        {
            *gicWake = true;
        }
        else
        {
            *gicWake = false;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set GPC IRQ wake mask                                                    */
/*--------------------------------------------------------------------------*/
bool CPU_IrqWakeSet(uint32_t cpuIdx, uint32_t maskIdx, uint32_t maskVal)
{
    bool rc = false;

    if ((cpuIdx < CPU_NUM_IDX) && 
        (maskIdx < GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT))
    {
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_IRQ_WAKEUP_MASK[maskIdx] = maskVal;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get GPC IRQ wake mask                                                    */
/*--------------------------------------------------------------------------*/
bool CPU_IrqWakeGet(uint32_t cpuIdx, uint32_t maskIdx, uint32_t *maskVal)
{
    bool rc = false;

    if ((cpuIdx < CPU_NUM_IDX) && 
        (maskIdx < GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT))
    {
        *maskVal = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_IRQ_WAKEUP_MASK[maskIdx];
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set GPC non-IRQ wake mask                                                */
/*--------------------------------------------------------------------------*/
bool CPU_NonIrqWakeSet(uint32_t cpuIdx, uint32_t maskVal)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        s_gpcCpuCtrlPtrs[cpuIdx]->CMC_NON_IRQ_WAKEUP_MASK = maskVal;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get GPC IRQ wake mask                                                    */
/*--------------------------------------------------------------------------*/
bool CPU_NonIrqWakeGet(uint32_t cpuIdx, uint32_t *maskVal)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        *maskVal = s_gpcCpuCtrlPtrs[cpuIdx]->CMC_NON_IRQ_WAKEUP_MASK;
        rc = true;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU power domain LPM config                                          */
/*--------------------------------------------------------------------------*/
bool CPU_LpmConfigSet(uint32_t cpuIdx, uint32_t srcMixIdx,
    uint32_t lpmSetting, uint32_t retMask)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        if (lpmSetting < CPU_NUM_PD_LPM)
        {
             rc = SRC_MixCpuLpmSet(srcMixIdx, cpuIdx, lpmSetting);
        }

        if (rc == true)
        {
            rc = SRC_MemRetentionModeSet(srcMixIdx, retMask);
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU MIX-level LPM dependencies                                       */
/*--------------------------------------------------------------------------*/
static bool CPU_LpmMixDependSet(uint32_t cpuIdx, uint32_t lpmSetting)
{    
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Initialize LPM response for CPU MIX */
        uint32_t srcMixIdx = s_cpuMgmtInfo[cpuIdx].srcMixIdx;
        rc = SRC_MixCpuLpmSet(srcMixIdx, cpuIdx, lpmSetting);

        /* Initialize LPM response for dependent MIXes */
        if (rc)
        {
            rc = SRC_MixCpuLpmSet(PWR_MIX_SLICE_IDX_DDR, cpuIdx, 
                lpmSetting);
        }
        
        if (rc)
        {
            rc = SRC_MixCpuLpmSet(PWR_MIX_SLICE_IDX_NOC, cpuIdx, 
                lpmSetting);
        }
        
        if (rc)
        {
            rc = SRC_MixCpuLpmSet(PWR_MIX_SLICE_IDX_WAKEUP, cpuIdx, 
                lpmSetting);
        }
    }

    return rc;   
}

/*--------------------------------------------------------------------------*/
/* Initialize CPU power domain LPM config                                   */
/*--------------------------------------------------------------------------*/
bool CPU_LpmConfigInit(uint32_t cpuIdx)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Clear MIX dependency flags */
        uint32_t cpuMask = (1UL << cpuIdx);
        s_cpuDdrMixDependMask &= (~cpuMask);
        s_cpuNocMixDependMask &= (~cpuMask);
        s_cpuWakeMixDependMask &= (~cpuMask);

        /* Initialize CPU LPM MIX dependencies */
        rc = CPU_LpmMixDependSet(cpuIdx, CPU_PD_LPM_ON_RUN_WAIT_STOP);

        if (rc)
        {
            /* Check if starting an A55 CPU */
            if ((cpuIdx >= CPU_IDX_A55C0) && (cpuIdx <= CPU_IDX_A55C_LAST))
            {
                /* Check if first CPU of A55P being started */
                if (PWR_NumChildPowered(PWR_MIX_SLICE_IDX_A55P) == 1U)
                {
                    /* Initialize A55P LPM MIX dependencies */
                    rc = CPU_LpmMixDependSet(CPU_IDX_A55P, CPU_PD_LPM_ON_RUN_WAIT_STOP);
                }
            }
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Deinitialize CPU power domain LPM config                                 */
/*--------------------------------------------------------------------------*/
bool CPU_LpmConfigDeInit(uint32_t cpuIdx, uint32_t lpmSetting)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Clear MIX dependency flags */
        uint32_t cpuMask = (1UL << cpuIdx);
        s_cpuDdrMixDependMask &= (~cpuMask);
        s_cpuNocMixDependMask &= (~cpuMask);
        s_cpuWakeMixDependMask &= (~cpuMask);

        uint32_t cpuIdxCur = cpuIdx;
        uint32_t cpuIdxEnd = cpuIdx;
        if (cpuIdx == CPU_IDX_A55P)
        {
            cpuIdxCur = CPU_IDX_A55C0;
            cpuIdxEnd = CPU_IDX_A55P;
        }
        do
        {
            /* Remove CPU LPM MIX dependencies */
            rc = CPU_LpmMixDependSet(cpuIdxCur, lpmSetting);
            ++cpuIdxCur;
        } while (rc && (cpuIdxCur <= cpuIdxEnd));
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Handle notification of MIX power up                                      */
/*--------------------------------------------------------------------------*/
void CPU_MixPowerUpNotify(uint32_t srcMixIdx)
{
    uint32_t cpuMixDependMask = 0U;

    switch(srcMixIdx)
    {
        case PWR_MIX_SLICE_IDX_DDR:
            cpuMixDependMask = s_cpuDdrMixDependMask;
            cpuMixDependMask &= (~s_cpuNocMixDependMask);
            cpuMixDependMask &= (~s_cpuWakeMixDependMask);
            s_cpuDdrMixDependMask = 0U;
            break;

        case PWR_MIX_SLICE_IDX_NOC:
            cpuMixDependMask = s_cpuNocMixDependMask;
            cpuMixDependMask &= (~s_cpuDdrMixDependMask);
            cpuMixDependMask &= (~s_cpuWakeMixDependMask);
            s_cpuNocMixDependMask = 0U;
            break;

        case PWR_MIX_SLICE_IDX_WAKEUP:
            cpuMixDependMask = s_cpuWakeMixDependMask;
            cpuMixDependMask &= (~s_cpuDdrMixDependMask);
            cpuMixDependMask &= (~s_cpuNocMixDependMask);
            s_cpuWakeMixDependMask = 0U;
            break;

        default:
            ; /* Intentional empty default */
            break;
    }
    
    /* Release CPUs with all dependencies done */
    while (cpuMixDependMask != 0U)
    {
        /* Convert mask into index */
        uint8_t cpuIdx = 31U - __CLZ(cpuMixDependMask);
    
        (void) CPU_WaitSet(cpuIdx, false);
        printf("Release CPU%u from MIX%u PowerUpPost\n", cpuIdx, srcMixIdx);
    
        /* Clear CPU mask bit to mark done */
        cpuMixDependMask &= (~(1UL << (cpuIdx)));
    }
}

/*--------------------------------------------------------------------------*/
/* Handle notification of MIX power down                                    */
/*--------------------------------------------------------------------------*/
void CPU_MixPowerDownNotify(uint32_t srcMixIdx)
{
    uint32_t *cpuMixDependMask = NULL;

    switch(srcMixIdx)
    {
        case PWR_MIX_SLICE_IDX_DDR:
            cpuMixDependMask = &s_cpuDdrMixDependMask;
            break;

        case PWR_MIX_SLICE_IDX_NOC:
            cpuMixDependMask = &s_cpuNocMixDependMask;
            break;

        case PWR_MIX_SLICE_IDX_WAKEUP:
            cpuMixDependMask = &s_cpuWakeMixDependMask;
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    if (cpuMixDependMask != NULL)
    {
        uint32_t lpmSetting = 0U;
        uint32_t cpuMask = (1UL << CPU_IDX_M7P);

        if (SRC_MixCpuLpmGet(srcMixIdx, CPU_IDX_M7P, &lpmSetting))
        {
            /* If CPU has MIX dependency, set global flag and assert CPUWAIT */
            if (lpmSetting != CPU_PD_LPM_ON_NEVER)
            {
                *cpuMixDependMask |= cpuMask;
                (void) CPU_WaitSet(CPU_IDX_M7P, true);
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Set reset vector                                                         */
/*--------------------------------------------------------------------------*/
bool CPU_ResetVectorSet(uint32_t cpuIdx, uint64_t vector)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Get vector attributes */
        uint32_t vectorShift = s_cpuMgmtInfo[cpuIdx].vectorShift;
        __IO uint32_t *vectorRegLow = s_cpuMgmtInfo[cpuIdx].vectorRegLow;
        __IO uint32_t *vectorRegHigh = s_cpuMgmtInfo[cpuIdx].vectorRegHigh;

        /* Check if CPU has vector */
        if (vectorRegLow != NULL)
        {
            /* Set lower 32-bit vector */
            *vectorRegLow = (uint32_t) ((vector & 0xFFFFFFFFULL) >> vectorShift);

            /* Check if CPU has 64-bit vector */
            if (vectorRegHigh != NULL)
            {
                /* Set upper 32-bit vector */
                *vectorRegHigh = (uint32_t) (vector >> (32U + vectorShift));
            }

            rc = true;
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get reset vector                                                         */
/*--------------------------------------------------------------------------*/
bool CPU_ResetVectorGet(uint32_t cpuIdx, uint64_t *vector)
{
    bool rc = false;

    if (cpuIdx < CPU_NUM_IDX)
    {
        /* Get vector attributes */
        uint32_t vectorShift = s_cpuMgmtInfo[cpuIdx].vectorShift;
        __IO const uint32_t *vectorRegLow = s_cpuMgmtInfo[cpuIdx].vectorRegLow;
        __IO const uint32_t *vectorRegHigh = s_cpuMgmtInfo[cpuIdx].vectorRegHigh;

        /* Check if CPU has vector */
        if (vectorRegLow != NULL)
        {
            /* Check if CPU has 64-bit vector */
            if (vectorRegHigh != NULL)
            {
                /* Get 64-bit vector */
                *vector = (((uint64_t) *vectorRegHigh) << (32U + vectorShift))
                    | (((uint64_t) *vectorRegLow) << vectorShift);
            }
            else
            {
                /* Get 32-bit vector */
                *vector = ((uint64_t) *vectorRegLow) << vectorShift;
            }

            rc = true;
        }
    }

    return rc;
}
