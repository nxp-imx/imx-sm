/*
** ###################################################################
**
**     Copyright 2026 NXP
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

#ifndef DEV_SM_FAULT_H
#define DEV_SM_FAULT_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX937_FAULT
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device faults.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device faults */
#define DEV_SM_NUM_FAULT  89U

/*!
 * @name Device fault indexes
 */
/** @{ */
#define DEV_SM_FAULT_TMP_ANA        0U   /*!< Temperature sensor over-temperature (ANA) */
#define DEV_SM_FAULT_TMP_A55        1U   /*!< Temperature sensor over-temperature (CORTEX-A) */
#define DEV_SM_FAULT_DRAM           3U   /*!< External DRAM array multi-bit uncorrected error */
#define DEV_SM_FAULT_WDOG2          18U  /*!< WDOG2 timeout (Watchdog reset request) */
#define DEV_SM_FAULT_WDOG3          19U  /*!< WDOG3 timeout (Watchdog reset request) */
#define DEV_SM_FAULT_WDOG4          20U  /*!< WDOG4 timeout (Watchdog reset request) */
#define DEV_SM_FAULT_WDOG5          21U  /*!< WDOG5 timeout (Watchdog reset request) */
#define DEV_SM_FAULT_SW0            22U  /*!< Software Generated Fault 0 (Group 0, Fault 0) */
#define DEV_SM_FAULT_SW1            23U  /*!< Software Generated Fault 1 (Group 0, Fault 1) */
#define DEV_SM_FAULT_SW2            24U  /*!< Software Generated Fault 2 (Group 0, Fault 2) */
#define DEV_SM_FAULT_SW3            25U  /*!< Software Generated Fault 3 (Group 0, Fault 3) */
#define DEV_SM_FAULT_SW4            26U  /*!< Software Generated Fault 4 (Group 0, Fault 4) */
#define DEV_SM_FAULT_SW5            27U  /*!< Software Generated Fault 5 (Group 0, Fault 5) */
#define DEV_SM_FAULT_SW6            28U  /*!< Software Generated Fault 6 (Group 1, Fault 0) */
#define DEV_SM_FAULT_SW7            29U  /*!< Software Generated Fault 7 (Group 1, Fault 1) */
#define DEV_SM_FAULT_SW8            30U  /*!< Software Generated Fault 8 (Group 1, Fault 2) */
#define DEV_SM_FAULT_SW9            31U  /*!< Software Generated Fault 9 (Group 1, Fault 3) */
#define DEV_SM_FAULT_SW10           32U  /*!< Software Generated Fault 10 (Group 1, Fault 4) */
#define DEV_SM_FAULT_SW11           33U  /*!< Software Generated Fault 11 (Group 1, Fault 5) */
#define DEV_SM_FAULT_M33_LOCKUP     34U  /*!< M33 Lockup Error */
#define DEV_SM_FAULT_M33_RESET      35U  /*!< Unintended M33 Reset assertion */
#define DEV_SM_FAULT_M7_LOCKUP      38U  /*!< M7 Lockup Error */
#define DEV_SM_FAULT_M7_RESET       39U  /*!< Unintended M7 Reset assertion */
/** @} */

/*! SW fault for internal SM error */
#define DEV_SM_FAULT_SM_ERR  DEV_SM_FAULT_SW5

/*! Default init for fault record */
#define DEV_SM_FAULT_REC_INIT(X) \
    { \
        .valid = true, \
        .reason = DEV_SM_REASON_FCCU, \
        .errId = (X), \
        .validErr = true \
    }

/* Types */

/* Functions */

/*!
 * Initialize the device fault handling.
 *
 * This function initializes the HW like the FCCU.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_FaultInit(void);

/** @} */

/* Include SM device API */

/* coverity[misra_c_2012_rule_20_1_violation] */
#include "dev_sm_fault_api.h"

#endif /* DEV_SM_FAULT_H */

