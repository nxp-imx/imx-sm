/*
** ###################################################################
**
**     Copyright 2025-2026 NXP
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
 * @addtogroup DEV_SM_MX94_FAULT
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
#define DEV_SM_NUM_FAULT  113U

/*!
 * @name Device fault indexes
 */
/** @{ */
#define DEV_SM_FAULT_TEMP_HIGH            0U    /*!< Temperature sensor over-temperature */
#define DEV_SM_FAULT_TEMP2_HIGH           1U    /*!< Temperature sensor over-temperature (CORTEXA) */
#define DEV_SM_FAULT_DDRC                 2U    /*!< DRAM controller internal fault */
#define DEV_SM_FAULT_DDR_MBE              3U    /*!< External DRAM array multi-bit uncorrected error */
#define DEV_SM_FAULT_OCRAM_MBE            4U    /*!< Always-ON OCRAM Multi-Bit Uncorrected Error */
#define DEV_SM_FAULT_NPUSRAM_MBE          5U    /*!< NPU SRAM Multi-Bit Uncorrected Error */
#define DEV_SM_FAULT_M33TCM_MBE           6U    /*!< M33 TCM Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_M33CACHE_MBE         7U    /*!< M33 Cache Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_M7TCM_MBE            8U    /*!< M7 TCM Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_M7CACHE_MBE          9U    /*!< M7 Cache Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_RESV10               10U   /*!< Reserved */
#define DEV_SM_FAULT_EDMA2TCD_MBE         11U   /*!< eDMA2 SRAM TCD Multi-Bit Uncorrected Error */
#define DEV_SM_FAULT_OCRAM_CTRL_ALARM     12U   /*!< SRAM Controller Safety Alarm */
#define DEV_SM_FAULT_RESV13               13U   /*!< Reserved */
#define DEV_SM_FAULT_DEBUG_EN             14U   /*!< Debug mode activation */
#define DEV_SM_FAULT_TEST_EN              15U   /*!< Unintended Test mode activation */
#define DEV_SM_FAULT_MTR_EN               16U   /*!< Unintended MTR activation */
#define DEV_SM_FAULT_STCU_EN              17U   /*!< Unintended STCU activation */
#define DEV_SM_FAULT_WDOG2                18U   /*!< WDOG2 timeout */
#define DEV_SM_FAULT_WDOG3                19U   /*!< WDOG3 timeout */
#define DEV_SM_FAULT_WDOG4                20U   /*!< WDOG4 timeout */
#define DEV_SM_FAULT_WDOG5                21U   /*!< WDOG5 timeout */
#define DEV_SM_FAULT_SWNCF00              22U   /*!< Software Generated Fault 0 (Group 0, Fault 0) */
#define DEV_SM_FAULT_SWNCF01              23U   /*!< Software Generated Fault 1 (Group 0, Fault 1) */
#define DEV_SM_FAULT_SWNCF02              24U   /*!< Software Generated Fault 2 (Group 0, Fault 2) */
#define DEV_SM_FAULT_SWNCF03              25U   /*!< Software Generated Fault 3 (Group 0, Fault 3) */
#define DEV_SM_FAULT_SWNCF04              26U   /*!< Software Generated Fault 4 (Group 0, Fault 4) */
#define DEV_SM_FAULT_SWNCF05              27U   /*!< Software Generated Fault 5 (Group 0, Fault 5) */
#define DEV_SM_FAULT_SWNCF06              28U   /*!< Software Generated Fault 6 (Group 1, Fault 0) */
#define DEV_SM_FAULT_SWNCF07              29U   /*!< Software Generated Fault 7 (Group 1, Fault 1) */
#define DEV_SM_FAULT_SWNCF08              30U   /*!< Software Generated Fault 8 (Group 1, Fault 2) */
#define DEV_SM_FAULT_SWNCF09              31U   /*!< Software Generated Fault 9 (Group 1, Fault 3) */
#define DEV_SM_FAULT_SWNCF10              32U   /*!< Software Generated Fault 10 (Group 1, Fault 4) */
#define DEV_SM_FAULT_SWNCF11              33U   /*!< Software Generated Fault 11 (Group 1, Fault 5) */
#define DEV_SM_FAULT_M33_LOCKUP           34U   /*!< M33 Lockup Error */
#define DEV_SM_FAULT_M33_RST              35U   /*!< Unintended M33 Reset assertion */
#define DEV_SM_FAULT_M33_DBG              36U   /*!< Unintended M33 Debug activation */
#define DEV_SM_FAULT_RESV37               37U   /*!< Reserved */
#define DEV_SM_FAULT_M7_LOCKUP            38U   /*!< M7 Lockup Error */
#define DEV_SM_FAULT_M7_RST               39U   /*!< Unintended M7 Reset assertion */
#define DEV_SM_FAULT_M7_DBG               40U   /*!< Unintended M7 Debug activation */
#define DEV_SM_FAULT_SECURITY_CRRM_AWDT   41U   /*!< Security CRRM AWDT expiry notification before reset */
#define DEV_SM_FAULT_SECURITY             42U   /*!< Security Fault */
#define DEV_SM_FAULT_OCOTP_FUSE_ERROR     43U   /*!< OCOTP Uncorrectable error from Fuse read */
#define DEV_SM_FAULT_CMU_ANA_LOSS_LOW     44U   /*!< Frequency loss or too low fault from an ANAMIX CMU */
#define DEV_SM_FAULT_CMU_ANA_HIGH         45U   /*!< Frequency too high from an ANAMIX CMU */
#define DEV_SM_FAULT_CMU_AON_LOSS_LOW     46U   /*!< Frequency loss or too low fault from an AONMIX CMU */
#define DEV_SM_FAULT_CMU_AON_HIGH         47U   /*!< Frequency too high from an AONMIX CMU */
#define DEV_SM_FAULT_CMU_WAKEUP_LOSS_LOW  48U   /*!< Frequency loss or too low fault from a WAKEUPMIX CMU */
#define DEV_SM_FAULT_CMU_WAKEUP_HIGH      49U   /*!< Frequency too high from a WAKEUPMIX CMU */
#define DEV_SM_FAULT_CMU_M7_0_LOSS_LOW    50U   /*!< Frequency loss or too low fault from a M7MIX0 CMU */
#define DEV_SM_FAULT_CMU_M7_0_HIGH        51U   /*!< Frequency too high from a M7MIX0 CMU */
#define DEV_SM_FAULT_CMU_DDR_LOSS_LOW     52U   /*!< Frequency loss or too low fault from a DDRMIX CMU */
#define DEV_SM_FAULT_CMU_DDR_HIGH         53U   /*!< Frequency too high from a DDRMIX CMU */
#define DEV_SM_FAULT_CMU_NOC_LOSS_LOW     54U   /*!< Frequency loss or too low fault from a NOCMIX CMU */
#define DEV_SM_FAULT_CMU_NOC_HIGH         55U   /*!< Frequency too high from a NOCMIX CMU */
#define DEV_SM_FAULT_VDET_LVD             56U   /*!< Voltage detector (VDET) low voltage detected */
#define DEV_SM_FAULT_VDET_HVD             57U   /*!< Voltage detector (VDET) high voltage detected */
#define DEV_SM_FAULT_NOC_MAIN             58U   /*!< FlexNOC Main Mission Fault */
#define DEV_SM_FAULT_RESV59               59U   /*!< Reserved */
#define DEV_SM_FAULT_NOC_CENTRAL          60U   /*!< FlexNOC Central Mission Fault */
#define DEV_SM_FAULT_PARITY_AXBS_M33      61U   /*!< Parity fault from parity checkers around AXBS_M33_0 */
#define DEV_SM_FAULT_PARITY_AXBS_AON      62U   /*!< Parity fault from parity checkers around AXBS AON */
#define DEV_SM_FAULT_INTM                 63U   /*!< INTM Interrupt Monitor Fault */
#define DEV_SM_FAULT_PARITY_AONMIX        64U   /*!< Parity fault from all parity gaskets in AONMIX */
#define DEV_SM_FAULT_PARITY_WAKEUPMIX     65U   /*!< Parity fault from all parity gaskets in WAKEUPMIX */
#define DEV_SM_FAULT_PARITY_NOCMIX        66U   /*!< Parity fault from all parity gaskets in NOCMIX */
#define DEV_SM_FAULT_PARITY_M7MIX0        67U   /*!< Parity fault from all parity gaskets in M7MIX0 */
#define DEV_SM_FAULT_PARITY_DDRMIX        68U   /*!< Parity fault from all parity gaskets in DDRMIX */
#define DEV_SM_FAULT_PARITY_NPUMIX        69U   /*!< Parity fault from all parity gaskets in NPUMIX */
#define DEV_SM_FAULT_RCCU_ATU_A           70U   /*!< ATU_A lock-step error */
#define DEV_SM_FAULT_RCCU_ATU_M7_0        71U   /*!< ATU_M7_0 lock-step error */
#define DEV_SM_FAULT_M7_1TCM_MBE          72U   /*!< M7 TCM Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_M7_1CACHE_MBE        73U   /*!< M7 Cache (instruction/data, data/tag) Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_M7_1_LOCKUP          74U   /*!< M7 Lockup Error */
#define DEV_SM_FAULT_M7_1_RST             75U   /*!< Unintended M7 Reset assertion */
#define DEV_SM_FAULT_M7_1_DBG             76U   /*!< Unintended M7 Debug activation */
#define DEV_SM_FAULT_CMU_M7_1_LOSS_LOW    77U   /*!< Frequency loss or too low fault from a M7MIX1 CMU */
#define DEV_SM_FAULT_CMU_M7_1_HIGH        78U   /*!< Frequency too high from a M7MIX1 CMU */
#define DEV_SM_FAULT_PARITY_M7MIX1        79U   /*!< Parity fault from all parity gaskets in M7MIX1 */
#define DEV_SM_FAULT_M33_SYNCTCM_MBE      80U   /*!< M33_Sync TCM Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_M33_SYNCCACHE_MBE    81U   /*!< M33_Sync Cache Uncorrected Multi Bit Error */
#define DEV_SM_FAULT_RESV82               82U   /*!< Reserved */
#define DEV_SM_FAULT_RESV83               83U   /*!< Reserved */
#define DEV_SM_FAULT_WDOG6                84U   /*!< WDOG6 timeout */
#define DEV_SM_FAULT_WDOG7                85U   /*!< WDOG7 timeout */
#define DEV_SM_FAULT_WDOG8                86U   /*!< WDOG8 timeout */
#define DEV_SM_FAULT_M33_SYNC_LOCKUP      87U   /*!< M33_Sync Lockup Error */
#define DEV_SM_FAULT_M33_SYNC_RST         88U   /*!< Unintended M33_Sync Reset assertion */
#define DEV_SM_FAULT_M33_SYNC_DBG         89U   /*!< Unintended M33_Sync Debug activation */
#define DEV_SM_FAULT_CMU_NETC_LOSS_LOW    90U   /*!< Frequency loss or too low fault from a NETCMIX CMU */
#define DEV_SM_FAULT_CMU_NETC_HIGH        91U   /*!< Frequency too high from a NETCMIX CMU */
#define DEV_SM_FAULT_PARITY_AXBS_M33_SYNC 92U   /*!< Parity fault from parity checkers around AXBS_M33_Sync */
#define DEV_SM_FAULT_PARITY_AXBS_NETC     93U   /*!< Parity fault from parity checkers around AXBS_NETC */
#define DEV_SM_FAULT_PARITY_NETCMIX       94U   /*!< Parity fault from all parity gaskets in NETCMIX */
#define DEV_SM_FAULT_RCCU_ATU_M33S        95U   /*!< ATU_M33S lock-step error */
#define DEV_SM_FAULT_NETC_OCSRAM_MBE      96U   /*!< 1.5MB OCSRAM Multi-Bit Uncorrected Error */
#define DEV_SM_FAULT_RESV97               97U   /*!< Reserved */
#define DEV_SM_FAULT_RESV98               98U   /*!< Reserved */
#define DEV_SM_FAULT_EDMA4TCD_MBE         99U   /*!< eDMA4 SRAM TCD Multi-Bit Uncorrected Error */
#define DEV_SM_FAULT_RCCU_ATU_M7_1        100U  /*!< ATU_M7_1 lock-step error */
#define DEV_SM_FAULT_SWNCF12              101U  /*!< Software Generated Fault 12 (Group 2, Fault 0) */
#define DEV_SM_FAULT_SWNCF13              102U  /*!< Software Generated Fault 13 (Group 2, Fault 1) */
#define DEV_SM_FAULT_SWNCF14              103U  /*!< Software Generated Fault 14 (Group 2, Fault 2) */
#define DEV_SM_FAULT_SWNCF15              104U  /*!< Software Generated Fault 15 (Group 2, Fault 3) */
#define DEV_SM_FAULT_SWNCF16              105U  /*!< Software Generated Fault 16 (Group 2, Fault 4) */
#define DEV_SM_FAULT_SWNCF17              106U  /*!< Software Generated Fault 17 (Group 2, Fault 5) */
#define DEV_SM_FAULT_SWNCF18              107U  /*!< Software Generated Fault 18 (Group 3, Fault 0) */
#define DEV_SM_FAULT_SWNCF19              108U  /*!< Software Generated Fault 19 (Group 3, Fault 1) */
#define DEV_SM_FAULT_SWNCF20              109U  /*!< Software Generated Fault 20 (Group 3, Fault 2) */
#define DEV_SM_FAULT_SWNCF21              110U  /*!< Software Generated Fault 21 (Group 3, Fault 3) */
#define DEV_SM_FAULT_SWNCF22              111U  /*!< Software Generated Fault 22 (Group 3, Fault 4) */
#define DEV_SM_FAULT_SWNCF23              112U  /*!< Software Generated Fault 23 (Group 3, Fault 5) */
/** @} */

/*! SW fault for internal SM error */
#define DEV_SM_FAULT_SM_ERR  DEV_SM_FAULT_SWNCF05

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

