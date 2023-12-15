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
/* File containing the implementation of the device exception/IRQ handlers. */
/*==========================================================================*/

/* Includes */
#include "dev_sm.h"
#include "dev_sm_handlers.h"
#include "board.h"
#include "mb_mu.h"
#include "config_mb_mu.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint64_t s_smTimeMsec = 0ULL;

/* Local functions */

static void ExceptionHandler(IRQn_Type excId, const uint32_t *sp,
    uint32_t faultStatus, uint32_t faultAddr);
static void FaultHandler(uint32_t faultId);

/*--------------------------------------------------------------------------*/
/* NMI exception handler                                                    */
/*--------------------------------------------------------------------------*/
void NMI_Handler(const uint32_t *sp)
{
    ExceptionHandler(NonMaskableInt_IRQn, sp, 0U, 0U);
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
/* GPIO 1 interrupt 0                                                       */
/*--------------------------------------------------------------------------*/
void GPIO1_0_IRQHandler(void)
{
#ifdef BOARD_HAS_GPIO1_0
    BRD_SM_Gpio1Handler();
#endif
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
}

/*--------------------------------------------------------------------------*/
/* WDOG3 handler                                                            */
/*--------------------------------------------------------------------------*/
void WDOG3_IRQHandler(void)
{
    FaultHandler(DEV_SM_FAULT_WDOG3);
}

/*--------------------------------------------------------------------------*/
/* WDOG4 handler                                                            */
/*--------------------------------------------------------------------------*/
void WDOG4_IRQHandler(void)
{
    FaultHandler(DEV_SM_FAULT_WDOG4);
}

/*--------------------------------------------------------------------------*/
/* WDOG5 handler                                                            */
/*--------------------------------------------------------------------------*/
void WDOG5_IRQHandler(void)
{
    FaultHandler(DEV_SM_FAULT_WDOG5);
}

/*--------------------------------------------------------------------------*/
/* ANAMIX TMPSNS Threshold 1 IRQ handler                                    */
/*--------------------------------------------------------------------------*/
void TMPSNS_ANA_1_IRQHandler(void)
{
    DEV_SM_SensorHandler(0U, 1U);
}

/*--------------------------------------------------------------------------*/
/* ANAMIX TMPSNS Threshold 2 IRQ handler                                    */
/*--------------------------------------------------------------------------*/
void TMPSNS_ANA_2_IRQHandler(void)
{
    DEV_SM_SensorHandler(0U, 2U);
}

/*--------------------------------------------------------------------------*/
/* CORTEXAMIX TMPSNS Threshold 1 IRQ handler                                */
/*--------------------------------------------------------------------------*/
void TMPSNS_CORTEXA_1_IRQHandler(void)
{
    DEV_SM_SensorHandler(1U, 1U);
}

/*--------------------------------------------------------------------------*/
/* CORTEXAMIX TMPSNS Threshold 2 IRQ handler                                */
/*--------------------------------------------------------------------------*/
void TMPSNS_CORTEXA_2_IRQHandler(void)
{
    DEV_SM_SensorHandler(1U, 2U);
}

/*--------------------------------------------------------------------------*/
/* Handler for SWI                                                          */
/*--------------------------------------------------------------------------*/
void Reserved110_IRQHandler(void)
{
    LMM_Handler();
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
}

/*--------------------------------------------------------------------------*/
/* CM7 LOCKUP handler                                                       */
/*--------------------------------------------------------------------------*/
void CM7_LOCKUP_IRQHandler(void)
{
    FaultHandler(DEV_SM_FAULT_M7_LOCKUP);
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
        DEV_SM_PowerUpPost(lpHsMode.srcMixIdx);
        CPU_MixPowerUpNotify(lpHsMode.srcMixIdx);
    }
    /* Else powering down or asserting reset */
    else
    {
        DEV_SM_PowerDownPre(lpHsMode.srcMixIdx);
        CPU_MixPowerDownNotify(lpHsMode.srcMixIdx);
    }

    PWR_LpHandshakeAck();
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
    return s_smTimeMsec;
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

    /* Finalize system reset flow */
    DEV_SM_SystemRstComp(resetRec);
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
        DEV_SM_SystemRstComp(resetRec);
    }
}

