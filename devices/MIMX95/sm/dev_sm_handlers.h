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
/*!
 * @addtogroup DEV_SM_MX95_HANDLERS
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM device interrupt handlers.
 */
/*==========================================================================*/

#ifndef DEV_SM_HANDLERS_H
#define DEV_SM_HANDLERS_H

/* Includes */

#include "board.h"

/* Types */

/*! Dynamic IRQ priority structure */
typedef struct
{
    /*! IRQ number */
    IRQn_Type irqId;
    /*! IRQ counter */
    uint32_t irqCntr;
    /*! IRQ base priority */
    uint32_t basePrio;
    /*! Dynamic priority enable */
    bool dynPrioEn;
} irq_prio_info_t;

/* Functions */

/*!
 * @name Device interrupt handlers
 * @{
 */

/*!
 * NMI interrupt handler.
 *
 * @param[in]  sp  Stack pointer
 */
void NMI_Handler(const uint32_t *sp);

/*!
 * Hard fault interrupt handler.
 *
 * @param[in]  sp  Stack pointer
 */
void HardFault_Handler(const uint32_t *sp);

/*!
 * MPU interrupt handler.
 *
 * @param[in]  sp  Stack pointer
 */
void MemManage_Handler(const uint32_t *sp);

/*!
 * Bus fault interrupt handler.
 *
 * @param[in]  sp  Stack pointer
 */
void BusFault_Handler(const uint32_t *sp);

/*!
 * Usage fault interrupt handler.
 *
 * @param[in]  sp  Stack pointer
 */
void UsageFault_Handler(const uint32_t *sp);

/*!
 * SYSTICK interrupt handler.
 */
void SysTick_Handler(void);

/*!
 * GPIO 1 interrupt 0 handler.
 */
void GPIO1_0_IRQHandler(void);

/*!
 * SM watchdog interrupt handler.
 *
 * @param[in]  sp  Stack pointer
 */
void WDOG1_IRQHandler(const uint32_t *sp);

/*!
 * WDOG2 interrupt handler.
 *
 * @param[in]  sp  Stack pointer
 */
void WDOG2_IRQHandler(const uint32_t *sp);

/*!
 * BBNSM interrupt handler.
 */
void BBNSM_IRQHandler(void);

/*!
 * WDOG3 interrupt handler.
 */
void WDOG3_IRQHandler(void);

/*!
 * WDOG4 interrupt handler.
 */
void WDOG4_IRQHandler(void);

/*!
 * WDOG5 interrupt handler.
 */
void WDOG5_IRQHandler(void);

/*!
 * ANAMIX TMPSNS Threshold 1 IRQ handler.
 */
void TMPSNS_ANA_1_IRQHandler(void);

/*!
 * ANAMIX TMPSNS Threshold 2 IRQ handler.
 */
void TMPSNS_ANA_2_IRQHandler(void);

/*!
 * CORTEXAMIX TMPSNS Threshold 1 IRQ handler.
 */
void TMPSNS_CORTEXA_1_IRQHandler(void);

/*!
 * CORTEXAMIX TMPSNS Threshold 1 IRQ handler.
 */
void TMPSNS_CORTEXA_2_IRQHandler(void);

/*!
 * Software interrupt handler.
 */
void Reserved110_IRQHandler(void);

/*!
 * ELE group 1 handler.
 *
 * @param[in]  sp  Stack pointer
 */
void ELE_Group1_IRQHandler(const uint32_t *sp);

/*!
 * ELE group 2 handler.
 *
 * @param[in]  sp  Stack pointer
 */
void ELE_Group2_IRQHandler(const uint32_t *sp);

/*!
 * ELE group 3 handler.
 *
 * @param[in]  sp  Stack pointer
 */
void ELE_Group3_IRQHandler(const uint32_t *sp);

/*!
 * CM7 SYSRESETREQ IRQ handler.
 */
void CM7_SYSRESETREQ_IRQHandler(void);

/*!
 * CM7 LOCKUP IRQ handler.
 */
void CM7_LOCKUP_IRQHandler(void);

/*!
 * MU1 side A interrupt handler.
 */
void MU1_A_IRQHandler(void);

/*!
 * MU1 side B interrupt handler.
 */
void MU1_B_IRQHandler(void);

/*!
 * MU2 side A interrupt handler.
 */
void MU2_A_IRQHandler(void);

/*!
 * MU2 side B interrupt handler.
 */
void MU2_B_IRQHandler(void);

/*!
 * MU3 side A interrupt handler.
 */
void MU3_A_IRQHandler(void);

/*!
 * MU3 side B interrupt handler.
 */
void MU3_B_IRQHandler(void);

/*!
 * MU4 side A interrupt handler.
 */
void MU4_A_IRQHandler(void);

/*!
 * MU4 side B interrupt handler.
 */
void MU4_B_IRQHandler(void);

/*!
 * MU5 side A interrupt handler.
 */
void MU5_A_IRQHandler(void);

/*!
 * MU5 side B interrupt handler.
 */
void MU5_B_IRQHandler(void);

/*!
 * MU6 side A interrupt handler.
 */
void MU6_A_IRQHandler(void);

/*!
 * MU6 side B interrupt handler.
 */
void MU6_B_IRQHandler(void);

/*!
 * FCCU Interrupt Reaction 0 IRQ handler.
 */
void FCCU_INT0_IRQHandler(void);

/*!
 * GPC SM Request IRQ handler.
 */
void GPC_SM_REQ_IRQHandler(void);

/** @} */

/*!
 * Trigger software interrupt.
 */
void SWI_Trigger(void);

/*!
 * Read timer.
 *
 * @return Returns the time in milliseconds.
 */
uint64_t DEV_SM_GetTimerMsec(void);

/*!
 * Update dynamic IRQ base priority.
 *
 * @param[in]     irq      IRQ index
 * @param[in]     basePrio Base IRQ priority
 *
 * This function updates the base priority for an IRQ participating
 * in dynamic prioritization.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if IRQ is not valid.
 */
int32_t DEV_SM_IrqPrioBaseSet(IRQn_Type irq, uint32_t basePrio);

/*!
 * Get dynamic IRQ base priority.
 *
 * @param[in]     irq      IRQ index
 * @param[out]    basePrio Base IRQ priority
 *
 * This function gets the base priority for an IRQ participating
 * in dynamic prioritization.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if IRQ is not valid.
 */
int32_t DEV_SM_IrqPrioBaseGet(IRQn_Type irq, uint32_t *basePrio);

/*!
 * Update dynamic IRQ occurrence counter.
 *
 * @param[in]     irq      IRQ index
 * @param[in]     irqCntr  Value for IRQ counter
 *
 * This function updates the occurrence counter for an IRQ participating
 * in dynamic prioritization.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if IRQ is not valid.
 */
int32_t DEV_SM_IrqPrioCntrSet(IRQn_Type irq, uint32_t irqCntr);

/*!
 * Get dynamic IRQ occurrence counter.
 *
 * @param[in]     irq      IRQ index
 * @param[out]    irqCntr  Value for IRQ counter
 *
 * This function gets the occurrence counter for an IRQ participating
 * in dynamic prioritization.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if IRQ is not valid.
 */
int32_t DEV_SM_IrqPrioCntrGet(IRQn_Type irq, uint32_t *irqCntr);

/*!
 * Update dynamic priority of active IRQ.
 *
 * This function updates the priority for an IRQ participating
 * in dynamic prioritization.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if IRQ is not valid.
 */
int32_t DEV_SM_IrqPrioUpdate(void);


#endif /* DEV_SM_HANDLERS_H */

/** @} */

