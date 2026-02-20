/*
** ###################################################################
**
** Copyright 2025 NXP
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

#ifndef BRD_SM_HANDLERS_H
#define BRD_SM_HANDLERS_H

/*==========================================================================*/
/*!
 * @addtogroup BRD_SM_MX94EVK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the implementation of interrupt handlers for the
 * board.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "fsl_pcal6416a.h"
#include "fsl_pf09.h"
#include "fsl_pf53.h"
#include "fsl_pca2131.h"

/* Defines */

/*! Initial PCAL6416A interrupt mask */
#define PCAL6416A_INITIAL_MASK  0xFFFBU

/*! Number of board IRQs participating dynamic prioritization */
#define BOARD_NUM_IRQ_PRIO_IDX                 1U

/*! Dynamic IRQ priority table index for GPIO1 */
#define BOARD_IRQ_PRIO_IDX_GPIO1_0             0U

/* Types */

/* External variables */

/*! Handle to access PCAL6416A */
extern PCAL6416A_Type g_pcal6416aDev;

/*! Handle to access PF09 */
extern PF09_Type g_pf09Dev;

/*! Handle to access PF5302 */
extern PF53_Type g_pf5302Dev;

/*! Handle to access PCA2131 */
extern PCA2131_Type g_pca2131Dev;

/*! Array of dynamic priority info for board IRQs */
extern irq_prio_info_t g_brdIrqPrioInfo[BOARD_NUM_IRQ_PRIO_IDX];

/*! Fault flags from the PMICs */
extern uint32_t g_pmicFaultFlags;

/* Functions */

/*!
 * Init serial devices.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t BRD_SM_SerialDevicesInit(void);

/*!
 * Enable/disable bus expander interrupts.
 *
 * @param[in]     val      Value to write
 * @param[in]     mask     Mask of bits to modify
 *
 * This function allows a caller to configure the bus expander.
 * interrupts.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t BRD_SM_BusExpMaskSet(uint16_t val, uint16_t mask);

/*!
 * GPIO 1 interrupt 0 handler.
 */
void GPIO1_INT0_IRQHandler(void);

/** @} */

#endif /* BRD_SM_HANDLERS_H */

