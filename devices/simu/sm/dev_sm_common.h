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

#ifndef DEV_SM_COMMON_H
#define DEV_SM_COMMON_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_SIMU
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the common device.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Max number of device agents */
#define DEV_SM_NUM_AGENT   3U
/*! Number of devices */
#define DEV_SM_NUM_DEVICE  1U
/*! Number of device bases */
#define DEV_SM_NUM_BASE    (DEV_SM_NUM_AGENT + DEV_SM_NUM_DEVICE)

/*!
 * @name Base agent indexes
 */
/** @{ */
#define DEV_SM_BASE_AGENT_0  0U  /*!< Agent 0 */
#define DEV_SM_BASE_AGENT_1  1U  /*!< Agent 1 */
#define DEV_SM_BASE_AGENT_2  2U  /*!< Agent 2 */
/** @} */

/*!
 * @name Base device indexes
 */
/** @{ */
#define DEV_SM_BASE_DEV_TEST  (DEV_SM_NUM_AGENT + 0U)  /*!< Test */
/** @} */

/* Types */

/* Functions */

/*!
 * Trigger software interrupt.
 */
void SWI_Trigger(void);

/** @} */

/* Include SM device API */

// coverity[misra_c_2012_rule_20_1_violation:FALSE]
#include "dev_sm_common_api.h"

#endif /* DEV_SM_COMMON_H */

