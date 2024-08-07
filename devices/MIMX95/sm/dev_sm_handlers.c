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
/* File containing the implementation of the device exception/IRQ handlers. */
/*==========================================================================*/

/* Includes */

#include "dev_sm.h"
#include "dev_sm_handlers.h"
#include "brd_sm.h"
#include "mb_mu.h"
#include "config_mb_mu.h"
#include "lmm.h"
#include "eMcem_Vfccu.h"

/* Local defines */

/* Dynamic IRQ priority definitions */
#define DEV_SM_NUM_IRQ_PRIO_IDX                 20U

#define DEV_SM_IRQ_PRIO_IDX_SYSTICK             0U
#define DEV_SM_IRQ_PRIO_IDX_BBNSM               1U
#define DEV_SM_IRQ_PRIO_IDX_WDOG3               2U
#define DEV_SM_IRQ_PRIO_IDX_WDOG4               3U
#define DEV_SM_IRQ_PRIO_IDX_WDOG5               4U
#define DEV_SM_IRQ_PRIO_IDX_TMPSNS_ANA_1        5U
#define DEV_SM_IRQ_PRIO_IDX_TMPSNS_ANA_2        6U
#define DEV_SM_IRQ_PRIO_IDX_TMPSNS_CORTEXA_1    7U
#define DEV_SM_IRQ_PRIO_IDX_TMPSNS_CORTEXA_2    8U
#define DEV_SM_IRQ_PRIO_IDX_BOARD_SWI           9U
#define DEV_SM_IRQ_PRIO_IDX_CM7_SYSRESETREQ     10U
#define DEV_SM_IRQ_PRIO_IDX_CM7_LOCKUP          11U
#define DEV_SM_IRQ_PRIO_IDX_FCCU0               12U
#define DEV_SM_IRQ_PRIO_IDX_MU1_B               13U
#define DEV_SM_IRQ_PRIO_IDX_MU2_B               14U
#define DEV_SM_IRQ_PRIO_IDX_MU3_B               15U
#define DEV_SM_IRQ_PRIO_IDX_MU4_B               16U
#define DEV_SM_IRQ_PRIO_IDX_MU5_B               17U
#define DEV_SM_IRQ_PRIO_IDX_MU6_B               18U
#define DEV_SM_IRQ_PRIO_IDX_GPC_SM_REQ          19U

/* Local types */

/* Local variables */

static uint64_t s_smTimeMsec = 0ULL;

static irq_prio_info_t s_irqPrioInfo[DEV_SM_NUM_IRQ_PRIO_IDX] =
{
    [DEV_SM_IRQ_PRIO_IDX_SYSTICK] =
    {
        .irqId = SysTick_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_BBNSM] =
    {
        .irqId = BBNSM_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_WDOG3] =
    {
        .irqId = WDOG3_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_WDOG4] =
    {
        .irqId = WDOG4_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_WDOG5] =
    {
        .irqId = WDOG5_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_TMPSNS_ANA_1] =
    {
        .irqId = TMPSNS_ANA_1_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_TMPSNS_ANA_2] =
    {
        .irqId = TMPSNS_ANA_2_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_TMPSNS_CORTEXA_1] =
    {
        .irqId = TMPSNS_CORTEXA_1_IRQ,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_TMPSNS_CORTEXA_2] =
    {
        .irqId = TMPSNS_CORTEXA_2_IRQ,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_BOARD_SWI] =
    {
        .irqId = BOARD_SWI_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_CM7_SYSRESETREQ] =
    {
        .irqId = CM7_SYSRESETREQ_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_CM7_LOCKUP] =
    {
        .irqId = CM7_LOCKUP_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_FCCU0] =
    {
        .irqId = FCCU_INT0_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_MU1_B] =
    {
        .irqId = MU1_B_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_MU2_B] =
    {
        .irqId = MU2_B_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_MU3_B] =
    {
        .irqId = MU3_B_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_MU4_B] =
    {
        .irqId = MU4_B_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_MU5_B] =
    {
        .irqId = MU5_B_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_MU6_B] =
    {
        .irqId = MU6_B_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    },

    [DEV_SM_IRQ_PRIO_IDX_GPC_SM_REQ] =
    {
        .irqId = GPC_SM_REQ_IRQn,
        .irqCntr = 0U,
        .basePrio = 0U,
        .dynPrioEn = false
    }
};

/* Local functions */

static void ExceptionHandler(IRQn_Type excId, const uint32_t *sp,
    uint32_t faultStatus, uint32_t faultAddr);
static void FaultHandler(uint32_t faultId);
static irq_prio_info_t *IrqPrioMap(IRQn_Type irq);
static void IrqPrioBoost(irq_prio_info_t const * pInfo,uint32_t relPrio);
static void IrqPrioUpdateRelative(irq_prio_info_t const *pInfo,
    uint32_t relPrio);
static void IrqPrioUpdate(irq_prio_info_t *pInfo);

/*--------------------------------------------------------------------------*/
/* NMI exception handler                                                    */
/*--------------------------------------------------------------------------*/
void NMI_Handler(const uint32_t *sp)
{
    dev_sm_rst_rec_t resetRec =
    {
        .reason = DEV_SM_REASON_FCCU,
        .errId = DEV_SM_FAULT_WDOG2,
        .validErr = true,
        .extInfo[0] = sp[6],
        .extLen = 1U,
        .reset = true,
        .valid = true
    };

    /* Save reset reason info */
    DEV_SM_SystemShutdownRecSet(resetRec);

    /* Wait for delayed FCCU reaction (PMIC reset) */
    // coverity[infinite_loop:FALSE]
    while (true)
    {
        ; /* Intentional empty while */
    }
}

/*--------------------------------------------------------------------------*/
/* Hard fault exception handler                                             */
/*--------------------------------------------------------------------------*/
void HardFault_Handler(const uint32_t *sp)
{
    ExceptionHandler(HardFault_IRQn, sp, SCB->HFSR, 0U);
}

/*--------------------------------------------------------------------------*/
/* Memory manager fault exception handler                                   */
/*--------------------------------------------------------------------------*/
void MemManage_Handler(const uint32_t *sp)
{
    uint32_t cfsr = SCB->CFSR;

    /* Grab memory management fault address register (MMFAR) */
    uint32_t mmfar = 0U;
    if ((cfsr & SCB_CFSR_MMARVALID_Msk) != 0U)
    {
        mmfar = SCB->MMFAR;
    }

    ExceptionHandler(MemoryManagement_IRQn, sp, cfsr, mmfar);
}

/*--------------------------------------------------------------------------*/
/* Bus fault exception handler                                              */
/*--------------------------------------------------------------------------*/
void BusFault_Handler(const uint32_t *sp)
{
    uint32_t cfsr = SCB->CFSR;

    /* Grab bus fault address register (BFAR) */
    uint32_t bfar = 0U;
    if ((cfsr & SCB_CFSR_BFARVALID_Msk) != 0U)
    {
        bfar = SCB->BFAR;
    }

    /* Call common handler */
    ExceptionHandler(BusFault_IRQn, sp, cfsr, bfar);
}

/*--------------------------------------------------------------------------*/
/* Usage fault exception handler                                            */
/*--------------------------------------------------------------------------*/
void UsageFault_Handler(const uint32_t *sp)
{
    /* Call common handler */
    ExceptionHandler(UsageFault_IRQn, sp, SCB->CFSR, 0U);
}

/*--------------------------------------------------------------------------*/
/* SysTick handler                                                          */
/*--------------------------------------------------------------------------*/
void SysTick_Handler(void)
{
    /* Call board tick */
    BRD_SM_TimerTick(BOARD_TICK_PERIOD_MSEC);

    s_smTimeMsec += BOARD_TICK_PERIOD_MSEC;
}

/*--------------------------------------------------------------------------*/
/* WDOG1 handler                                                            */
/*--------------------------------------------------------------------------*/
void WDOG1_IRQHandler(const uint32_t *sp)
{
    ExceptionHandler(WDOG1_IRQn, sp, 0U, 0U);
}

/*--------------------------------------------------------------------------*/
/* WDOG2 handler                                                            */
/*--------------------------------------------------------------------------*/
void WDOG2_IRQHandler(const uint32_t *sp)
{
    ExceptionHandler(WDOG2_IRQn, sp, 0U, 0U);
}

/*--------------------------------------------------------------------------*/
/* Handler for BBNSM                                                        */
/*--------------------------------------------------------------------------*/
void BBNSM_IRQHandler(void)
{
    /* BBM handler will service BBNSM IRQs*/
    DEV_SM_BbmHandler();
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_BBNSM]);
}

/*--------------------------------------------------------------------------*/
/* WDOG3 handler                                                            */
/*--------------------------------------------------------------------------*/
void WDOG3_IRQHandler(void)
{
    FaultHandler(DEV_SM_FAULT_WDOG3);
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_WDOG3]);
}

/*--------------------------------------------------------------------------*/
/* WDOG4 handler                                                            */
/*--------------------------------------------------------------------------*/
void WDOG4_IRQHandler(void)
{
    FaultHandler(DEV_SM_FAULT_WDOG4);
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_WDOG4]);
}

/*--------------------------------------------------------------------------*/
/* WDOG5 handler                                                            */
/*--------------------------------------------------------------------------*/
void WDOG5_IRQHandler(void)
{
    FaultHandler(DEV_SM_FAULT_WDOG5);
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_WDOG5]);
}

/*--------------------------------------------------------------------------*/
/* ANAMIX TMPSNS Threshold 1 IRQ handler                                    */
/*--------------------------------------------------------------------------*/
void TMPSNS_ANA_1_IRQHandler(void)
{
    DEV_SM_SensorHandler(0U, 1U);
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_TMPSNS_ANA_1]);
}

/*--------------------------------------------------------------------------*/
/* ANAMIX TMPSNS Threshold 2 IRQ handler                                    */
/*--------------------------------------------------------------------------*/
void TMPSNS_ANA_2_IRQHandler(void)
{
    DEV_SM_SensorHandler(0U, 2U);
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_TMPSNS_ANA_2]);
}

/*--------------------------------------------------------------------------*/
/* CORTEXAMIX TMPSNS Threshold 1 IRQ handler                                */
/*--------------------------------------------------------------------------*/
void TMPSNS_CORTEXA_1_IRQHandler(void)
{
    DEV_SM_SensorHandler(1U, 1U);
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_TMPSNS_CORTEXA_1]);
}

/*--------------------------------------------------------------------------*/
/* CORTEXAMIX TMPSNS Threshold 2 IRQ handler                                */
/*--------------------------------------------------------------------------*/
void TMPSNS_CORTEXA_2_IRQHandler(void)
{
    DEV_SM_SensorHandler(1U, 2U);
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_TMPSNS_CORTEXA_2]);
}

/*--------------------------------------------------------------------------*/
/* Handler for SWI                                                          */
/*--------------------------------------------------------------------------*/
void Reserved110_IRQHandler(void)
{
    LMM_Handler();
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_BOARD_SWI]);
}

/*--------------------------------------------------------------------------*/
/* ELE Group #1 IRQ exception handler                                       */
/*--------------------------------------------------------------------------*/
void ELE_Group1_IRQHandler(const uint32_t *sp)
{
    /* Call common handler */
    ExceptionHandler(ELE_Group1_IRQn, sp,
        BLK_CTRL_S_AONMIX->SENTINEL_RST_REQ_STAT,
        BLK_CTRL_S_AONMIX->SENTINEL_IRQ_REQ_STAT);
}

/*--------------------------------------------------------------------------*/
/* ELE Group #2 IRQ exception handler                                       */
/*--------------------------------------------------------------------------*/
void ELE_Group2_IRQHandler(const uint32_t *sp)
{
    /* Call common handler */
    ExceptionHandler(ELE_Group2_IRQn, sp,
        BLK_CTRL_S_AONMIX->SENTINEL_RST_REQ_STAT,
        BLK_CTRL_S_AONMIX->SENTINEL_IRQ_REQ_STAT);
}

/*--------------------------------------------------------------------------*/
/* ELE Group #3 IRQ exception handler                                       */
/*--------------------------------------------------------------------------*/
void ELE_Group3_IRQHandler(const uint32_t *sp)
{
    /* Call common handler */
    ExceptionHandler(ELE_Group3_IRQn, sp,
        BLK_CTRL_S_AONMIX->SENTINEL_RST_REQ_STAT,
        BLK_CTRL_S_AONMIX->SENTINEL_IRQ_REQ_STAT);
}

/*--------------------------------------------------------------------------*/
/* CM7 SYSRESETREQ handler                                                  */
/*--------------------------------------------------------------------------*/
void CM7_SYSRESETREQ_IRQHandler(void)
{
    FaultHandler(DEV_SM_FAULT_M7_RESET);
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_CM7_SYSRESETREQ]);
}

/*--------------------------------------------------------------------------*/
/* CM7 LOCKUP handler                                                       */
/*--------------------------------------------------------------------------*/
void CM7_LOCKUP_IRQHandler(void)
{
    FaultHandler(DEV_SM_FAULT_M7_LOCKUP);
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_CM7_LOCKUP]);
}

/*--------------------------------------------------------------------------*/
/* MU1A IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU1_A_IRQHandler(void)
{
#ifdef SM_MB_MU0_CONFIG
    MB_MU_Handler(0U);
#endif
}

/*--------------------------------------------------------------------------*/
/* MU1B IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU1_B_IRQHandler(void)
{
#ifdef SM_MB_MU1_CONFIG
    MB_MU_Handler(1U);
#endif
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_MU1_B]);
}

/*--------------------------------------------------------------------------*/
/* MU2A IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU2_A_IRQHandler(void)
{
#ifdef SM_MB_MU2_CONFIG
    MB_MU_Handler(2U);
#endif
}

/*--------------------------------------------------------------------------*/
/* MU2B IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU2_B_IRQHandler(void)
{
#ifdef SM_MB_MU3_CONFIG
    MB_MU_Handler(3U);
#endif
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_MU2_B]);
}

/*--------------------------------------------------------------------------*/
/* MU3A IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU3_A_IRQHandler(void)
{
#ifdef SM_MB_MU4_CONFIG
    MB_MU_Handler(4U);
#endif
}

/*--------------------------------------------------------------------------*/
/* MU3B IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU3_B_IRQHandler(void)
{
#ifdef SM_MB_MU5_CONFIG
    MB_MU_Handler(5U);
#endif
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_MU3_B]);
}

/*--------------------------------------------------------------------------*/
/* MU4A IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU4_A_IRQHandler(void)
{
#ifdef SM_MB_MU6_CONFIG
    MB_MU_Handler(6U);
#endif
}

/*--------------------------------------------------------------------------*/
/* MU4B IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU4_B_IRQHandler(void)
{
#ifdef SM_MB_MU7_CONFIG
    MB_MU_Handler(7U);
#endif
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_MU4_B]);
}

/*--------------------------------------------------------------------------*/
/* MU5A IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU5_A_IRQHandler(void)
{
#ifdef SM_MB_MU8_CONFIG
    MB_MU_Handler(8U);
#endif
}

/*--------------------------------------------------------------------------*/
/* MU5B IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU5_B_IRQHandler(void)
{
#ifdef SM_MB_MU9_CONFIG
    MB_MU_Handler(9U);
#endif
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_MU5_B]);
}

/*--------------------------------------------------------------------------*/
/* MU6A IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU6_A_IRQHandler(void)
{
#ifdef SM_MB_MU10_CONFIG
    MB_MU_Handler(10U);
#endif
}

/*--------------------------------------------------------------------------*/
/* MU6B IRQ handler                                                         */
/*--------------------------------------------------------------------------*/
void MU6_B_IRQHandler(void)
{
#ifdef SM_MB_MU11_CONFIG
    MB_MU_Handler(11U);
#endif
    IrqPrioUpdate(&s_irqPrioInfo[DEV_SM_IRQ_PRIO_IDX_MU6_B]);
}

/*--------------------------------------------------------------------------*/
/* FCCU Interrupt Reaction 0 IRQ handler                                    */
/*--------------------------------------------------------------------------*/
void FCCU_INT0_IRQHandler(void)
{
    VFCCU_ALARM_ISR();
}

/*--------------------------------------------------------------------------*/
/* GPC SM REQ IRQ handler                                                   */
/*--------------------------------------------------------------------------*/
void GPC_SM_REQ_IRQHandler(void)
{
    pwr_lp_hs_mode lpHsMode;

    PWR_LpHandshakeModeGet(&lpHsMode);

    /* Check if powering up or deasserting reset */
    if (lpHsMode.stat == 1U)
    {
        (void) DEV_SM_PowerUpPost(lpHsMode.srcMixIdx);
        CPU_MixPowerUpNotify(lpHsMode.srcMixIdx);
        PWR_LpHandshakeAck();
        (void) DEV_SM_PowerUpAckComplete(lpHsMode.srcMixIdx);
    }
    /* Else powering down or asserting reset */
    else
    {
        (void) DEV_SM_PowerDownPre(lpHsMode.srcMixIdx);
        CPU_MixPowerDownNotify(lpHsMode.srcMixIdx);
        PWR_LpHandshakeAck();
    }
}

/*--------------------------------------------------------------------------*/
/* Trigger software interrupt                                               */
/*--------------------------------------------------------------------------*/
void SWI_Trigger(void)
{
    /* Trigger SWI handler */
    NVIC_SetPendingIRQ(BOARD_SWI_IRQn);
}

/*--------------------------------------------------------------------------*/
/* Get time elapsed in msec                                                 */
/*--------------------------------------------------------------------------*/
uint64_t DEV_SM_GetTimerMsec(void)
{
    /* Return milliseconds */
    return s_smTimeMsec;
}

/*--------------------------------------------------------------------------*/
/* Update base priority for an IRQ supporting dynamic prioritization        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_IrqPrioBaseSet(IRQn_Type irq, uint32_t basePrio)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Map IRQ to entry in dynamic priority table */
    irq_prio_info_t *pInfo = IrqPrioMap(irq);

    if (pInfo != NULL)
    {
        /* Range check requested base priority */
        if (basePrio < (1U << __NVIC_PRIO_BITS))
        {
            /* Update current NVIC priority for this IRQ */
            NVIC_SetPriority(irq, basePrio);

            /* Update table entry for this IRQ */
            pInfo->basePrio = basePrio;
        }
        else
        {
            status = SM_ERR_OUT_OF_RANGE;
        }
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get base priority for an IRQ supporting dynamic prioritization           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_IrqPrioBaseGet(IRQn_Type irq, uint32_t *basePrio)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Map IRQ to entry in dynamic priority table */
    irq_prio_info_t const *pInfo = IrqPrioMap(irq);

    if (pInfo != NULL)
    {
        /* Get base priority from table entry */
        *basePrio = pInfo->basePrio;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Update counter for an IRQ supporting dynamic prioritization              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_IrqPrioCntrSet(IRQn_Type irq, uint32_t irqCntr)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Map IRQ to entry in dynamic priority table */
    irq_prio_info_t *pInfo = IrqPrioMap(irq);

    if (pInfo != NULL)
    {
        /* Update table entry for this IRQ */
        pInfo->irqCntr = irqCntr;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get counter for an IRQ supporting dynamic prioritization                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_IrqPrioCntrGet(IRQn_Type irq, uint32_t *irqCntr)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Map IRQ to entry in dynamic priority table */
    irq_prio_info_t const *pInfo = IrqPrioMap(irq);

    if (pInfo != NULL)
    {
        /* Get counter from table entry */
        *irqCntr = pInfo->irqCntr;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Update dynamic priority of active IRQ                                    */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_IrqPrioUpdate(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Get active IRQ from SCB */
    uint32_t vectActive = (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk)
        >> SCB_ICSR_VECTACTIVE_Pos;

    /* Convert to CMSIS IRQ value */
    int32_t irq = (int32_t) vectActive;
    irq -= 16;

    /* Map IRQ to entry in dynamic priority table */
    // coverity[misra_c_2012_rule_10_5_violation:FALSE]
    irq_prio_info_t *pInfo = IrqPrioMap((IRQn_Type) irq);

    if (pInfo != NULL)
    {
        /* Adjust dynamic IRQ priority */
        IrqPrioUpdate(pInfo);
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Common exception handler                                                 */
/*--------------------------------------------------------------------------*/
static void ExceptionHandler(IRQn_Type excId, const uint32_t *sp,
    uint32_t faultStatus, uint32_t faultAddr)
{
    dev_sm_rst_rec_t resetRec =
    {
        .reason = DEV_SM_REASON_CM33_EXC,
        .errId = (uint32_t) excId,
        .validErr = true,
        .extInfo[0] = sp[6],
        .extInfo[1] = faultStatus,
        .extInfo[2] = faultAddr,
        .extLen = 3U,
        .valid = true
    };

#ifdef USES_FUSA
    /* Report to FuSa */
    LMM_FuSaExceptionHandler(&resetRec);
#endif

    /* Finalize system reset flow */
    (void) DEV_SM_SystemRstComp(&resetRec);
}

/*--------------------------------------------------------------------------*/
/* Common fault handler                                                     */
/*--------------------------------------------------------------------------*/
static void FaultHandler(uint32_t faultId)
{
    int32_t status;
    dev_sm_rst_rec_t resetRec =
    {
        .reason = DEV_SM_REASON_FCCU,
        .errId = faultId,
        .validErr = true,
        .valid = true
    };

    /* Finalize fault flow */
    status = DEV_SM_FaultComplete(resetRec);

    /* Reset if fault handling failed */
    if (status != SM_ERR_SUCCESS)
    {
        /* Finalize system reset flow */
        (void) DEV_SM_SystemRstComp(&resetRec);
    }
}

/*--------------------------------------------------------------------------*/
/* Map IRQ to dynamic priority table entry                                  */
/*--------------------------------------------------------------------------*/
static irq_prio_info_t *IrqPrioMap(IRQn_Type irq)
{
    uint32_t idx = 0U;
    irq_prio_info_t *pInfo = NULL;

#ifdef BOARD_NUM_IRQ_PRIO_IDX
    /* Loop over board-defined IRQ table entries */
    while ((pInfo == NULL) && (idx < BOARD_NUM_IRQ_PRIO_IDX))
    {
        if (s_brdIrqPrioInfo[idx].irqId == irq)
        {
            pInfo = &s_brdIrqPrioInfo[idx];
        }

        idx++;
    }
#endif

    /* Loop over compulsory IRQ table entries */
    idx = 0U;
    while ((pInfo == NULL) && (idx < DEV_SM_NUM_IRQ_PRIO_IDX))
    {
        if (s_irqPrioInfo[idx].irqId == irq)
        {
            pInfo = &s_irqPrioInfo[idx];
        }

        idx++;
    }

    return pInfo;
}

/*--------------------------------------------------------------------------*/
/* Boost dynamic priority of IRQ                                            */
/*--------------------------------------------------------------------------*/
static void IrqPrioBoost(irq_prio_info_t const *pInfo, uint32_t relPrio)
{
    if (pInfo != NULL)
    {
        /* Check if dynamic priority is enabled for this IRQ */
        if (pInfo->dynPrioEn)
        {
            /* Get current priorty */
            IRQn_Type irqId = pInfo->irqId;
            uint32_t irqPrio = NVIC_GetPriority(irqId);

            /* Check if priority at same relative level */
            if (irqPrio == relPrio)
            {
                /* raise active priority */
                irqPrio--;
                NVIC_SetPriority(irqId, irqPrio);
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Adjust dynamic IRQ priority by raising priority of non-active IRQs       */
/*--------------------------------------------------------------------------*/
static void IrqPrioUpdateRelative(irq_prio_info_t const *pInfo,
    uint32_t relPrio)
{
    if (pInfo != NULL)
    {
        uint32_t idx;

#ifdef BOARD_NUM_IRQ_PRIO_IDX
        /* Loop over board-defined table entries */
        idx = 0U;
        while (idx < BOARD_NUM_IRQ_PRIO_IDX)
        {
            /* Get table entry */
            irq_prio_info_t const *pInfoRel = &s_brdIrqPrioInfo[idx];

            /* Check if table entry is active IRQ */
            if (pInfo != pInfoRel)
            {
                /* Boost priority of non-active IRQ */
                IrqPrioBoost(pInfoRel, relPrio);
            }

            idx++;
        }
#endif

        /* Loop over compulsory table entries */
        idx = 0U;
        while (idx < DEV_SM_NUM_IRQ_PRIO_IDX)
        {
            /* Get table entry */
            irq_prio_info_t const *pInfoRel = &s_irqPrioInfo[idx];

            /* Check if table entry is active IRQ */
            if (pInfo != pInfoRel)
            {
                /* Boost priority of non-active IRQ */
                IrqPrioBoost(pInfoRel, relPrio);
            }

            idx++;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Update dynamic priority of IRQ using priority info table index           */
/*--------------------------------------------------------------------------*/
static void IrqPrioUpdate(irq_prio_info_t *pInfo)
{
    if (pInfo != NULL)
    {
        /* Update IRQ counter */
        ++pInfo->irqCntr;

        /* Get current priorty */
        IRQn_Type irqId = pInfo->irqId;
        uint32_t irqPrio = NVIC_GetPriority(irqId);

        /* Check for first dynamic priority update for this IRQ */
        if (!pInfo->dynPrioEn)
        {
            /* Indicate IRQ participating in dynamic priority */
            pInfo->dynPrioEn = true;

            /* Capture base priority */
            pInfo->basePrio = irqPrio;
        }

        /* Check if IRQ at base priority */
        if (irqPrio == pInfo->basePrio)
        {
            /* Lower active priority */
            irqPrio++;
            NVIC_SetPriority(irqId, irqPrio);
        }
        /* Else lower relative IRQ priority */
        else
        {
            IrqPrioUpdateRelative(pInfo, irqPrio);
        }
    }
}

