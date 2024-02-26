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

#ifndef DEV_SM_FAULT_H
#define DEV_SM_FAULT_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX95_FAULT
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
#define DEV_SM_NUM_FAULT  72U

/*!
 * @name Device fault indexes
 */
/** @{ */
#define DEV_SM_FAULT_TMP_ANA        0U   /*!< Temperature sensor over-temperature (ANA) */
#define DEV_SM_FAULT_TMP_A55        1U   /*!< Temperature sensor over-temperature (CORTEX-A) */
#define DEV_SM_FAULT_DRC            2U   /*!< DRAM controller internal fault */
#define DEV_SM_FAULT_DRAM           3U   /*!< External DRAM array multi-bit uncorrected error */
#define DEV_SM_FAULT_AON_ECC        4U   /*!< Always-ON OCRAM Multi-Bit Uncorrected Error */
#define DEV_SM_FAULT_NPU_ECC        5U   /*!< NPU SRAM Multi-Bit Uncorrected Error */
#define DEV_SM_FAULT_M33_TCM_ECC    6U   /*!< M33 TCM Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_M33_CACHE_ECC  7U   /*!< M33 Cache Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_M7_TCM_ECC     8U   /*!< M7 TCM Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_M7_CACHE_ECC   9U   /*!< M7 Cache Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_RESV10         10U  /*!< Reserved */
#define DEV_SM_FAULT_DMA2_ECC       11U  /*!< eDMA2 SRAM TCD Multi-Bit Uncorrected Error */
#define DEV_SM_FAULT_SRAM           12U  /*!< SRAM Controller Safety Alarm */
#define DEV_SM_FAULT_RESV13         13U  /*!< Reserved */
#define DEV_SM_FAULT_DEBUG          14U  /*!< Debug mode activation */
#define DEV_SM_FAULT_TEST           15U  /*!< Unintended Test mode activation */
#define DEV_SM_FAULT_MTR            16U  /*!< Unintended MTR activation */
#define DEV_SM_FAULT_STCU           17U  /*!< Unintended STCU activation */
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
#define DEV_SM_FAULT_M33_DEBUG      36U  /*!< Unintended M33 Debug activation */
#define DEV_SM_FAULT_RESV37         37U  /*!< Reserved */
#define DEV_SM_FAULT_M7_LOCKUP      38U  /*!< M7 Lockup Error */
#define DEV_SM_FAULT_M7_RESET       39U  /*!< Unintended M7 Reset assertion */
#define DEV_SM_FAULT_M7_DEBUG       40U  /*!< Unintended M7 Debug activation */
#define DEV_SM_FAULT_RESV41         41U  /*!< Reserved */
#define DEV_SM_FAULT_RESV42         42U  /*!< Reserved */
#define DEV_SM_FAULT_RESV43         43U  /*!< Reserved */
#define DEV_SM_FAULT_ANA_FREQ_L     44U  /*!< Frequency loss or too low fault from ANAMIX CMU */
#define DEV_SM_FAULT_ANA_FREQ_H     45U  /*!< Frequency too high from ANA domain CMU */
#define DEV_SM_FAULT_AON_FREQ_L     46U  /*!< Frequency loss or too low fault from AON CMU */
#define DEV_SM_FAULT_AON_FREQ_H     47U  /*!< Frequency too high from  AON CMU */
#define DEV_SM_FAULT_WAKE_FREQ_L    48U  /*!< Frequency loss or too low fault from Wakeup CMU */
#define DEV_SM_FAULT_WAKE_FREQ_H    49U  /*!< Frequency too high from Wakeup CMU */
#define DEV_SM_FAULT_M7_FREQ_L      50U  /*!< Frequency loss or too low fault from M7 CMU */
#define DEV_SM_FAULT_M7_FREQ_H      51U  /*!< Frequency too high from M7 CMU */
#define DEV_SM_FAULT_DDR_FREQ_L     52U  /*!< Frequency loss or too low fault from DDR CMU */
#define DEV_SM_FAULT_DDR_FREQ_H     53U  /*!< Frequency too high from DDR CMU */
#define DEV_SM_FAULT_NOC_FREQ_L     54U  /*!< Frequency loss or too low fault from NOC CMU */
#define DEV_SM_FAULT_NOC_FREQ_H     55U  /*!< Frequency too high from NOC CMU */
#define DEV_SM_FAULT_RESV56         56U  /*!< Reserved */
#define DEV_SM_FAULT_RESV57         57U  /*!< Reserved */
#define DEV_SM_FAULT_MAIN_NOC       58U  /*!< FlexNOC_Main Mission Fault */
#define DEV_SM_FAULT_MEGA_NOC       59U  /*!< FlexNOC_Mega Mission Fault */
#define DEV_SM_FAULT_CENTRAL_NOC    60U  /*!< FlexNOC_Central Mission Fault */
#define DEV_SM_FAULT_M33_AXBS       61U  /*!< Parity fault from AXBS_M33 */
#define DEV_SM_FAULT_AON_AXBS       62U  /*!< Parity fault from AXBS AON */
#define DEV_SM_FAULT_INTM           63U  /*!< INTM Interrupt Monitor Fault */
#define DEV_SM_FAULT_AON_SSI        64U  /*!< Parity fault from SSIs in AON */
#define DEV_SM_FAULT_WAKE_SSI       65U  /*!< Parity fault from SSIs in Wakeup */
#define DEV_SM_FAULT_NOC_SSI        66U  /*!< Parity fault from SSIs in NOC */
#define DEV_SM_FAULT_M7_SSI         67U  /*!< Parity fault from SSIs in Cortex-M7 */
#define DEV_SM_FAULT_DDR_SSI        68U  /*!< Parity fault from SSIs in DDR */
#define DEV_SM_FAULT_NPU_SSI        69U  /*!< Parity fault from SSIs in NPU */
#define DEV_SM_FAULT_ATU_A          70U  /*!< ATU_A lock-step error */
#define DEV_SM_FAULT_ATU_M          71U  /*!< ATU_M lock-step error */
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

/** @} */

/* Include SM device API */

#include "dev_sm_fault_api.h"

#endif /* DEV_SM_FAULT_H */

