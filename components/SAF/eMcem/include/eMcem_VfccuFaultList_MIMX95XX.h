/**
*   @file    eMcem_VfccuFaultList_MIMX95XX.h
*   @version 0.4.0
*
*   @brief   MIMX_SAF eMcem - Specific VFCCU fault list header.
*   @details Contains list of specific VFCCU fault lines for eMcem module.
*
*   @addtogroup EMCEM_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : MIMX_SAF
*   Platform             : CORTEXM
*
*   SW Version           : 0.4.0
*   Build Version        : IMX95_SAF_0_4_0_CD01_20231113
*
*   Copyright 2018-2023 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_VFCCUFAULTLIST_MIMX95XX_H
#define EMCEM_VFCCUFAULTLIST_MIMX95XX_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_VfccuFaultList_MIMX95XX_h_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_VfccuFaultList_MIMX95XX_h_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_VfccuFaultList_MIMX95XX_h_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_VfccuFaultList_MIMX95XX_h_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX_SAF_Version.h"
#include "SafetyBase_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0501 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0502 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0504 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0505 */
#define EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_MAJOR_VERSION             0
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0501 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0502 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0504 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0505 */
#define EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_MINOR_VERSION             4
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0501 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0502 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0504 */
/* @violates @ref eMcem_VfccuFaultList_MIMX95XX_h_REF_0505 */
#define EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_MAJOR_VERSION != MIMX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_MINOR_VERSION != MIMX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_VFCCUFAULTLIST_MIMX95XX_SW_PATCH_VERSION != MIMX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_VfccuFaultList_MIMX95XX.h and MIMX_SAF version are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* C_VFCCU fault lines */
/* NCF[0] Temperature sensor critical over-temperature (ANA) */
#define EMCEM_FCCU_FLT_TEMP_HIGH                         (0U)
/* NCF[1] Temperature sensor critical over-temperature (CORTEXA) */
#define EMCEM_FCCU_FLT_TEMP2_HIGH                        (1U)
/* NCF[2] DRAM controller internal fault */
#define EMCEM_FCCU_FLT_DDRC                              (2U)
/* NCF[3] External DRAM array multi-bit uncorrected error */
#define EMCEM_FCCU_FLT_DDR_MBE                           (3U)
/* NCF[4] Always-ON OCRAM Multi-Bit Uncorrected Error */
#define EMCEM_FCCU_FLT_OCRAM_MBE                         (4U)
/* NCF[5] NPU SRAM Multi-Bit Uncorrected Error */
#define EMCEM_FCCU_FLT_NPUSRAM_MBE                       (5U)
/* NCF[6] M33 TCM Uncorrected Multi Bit Error */
#define EMCEM_FCCU_FLT_M33TCM_MBE                        (6U)
/* NCF[7] M33 Cache (system/code, data/tag) Uncorrected Multi Bit Error */
#define EMCEM_FCCU_FLT_M33CACHE_MBE                      (7U)
/* NCF[8] M7 TCM Uncorrected Multi Bit Error */
#define EMCEM_FCCU_FLT_M7TCM_MBE                         (8U)
/* NCF[9] M7 Cache (instruction/data, data/tag) Uncorrected Multi Bit Error */
#define EMCEM_FCCU_FLT_M7CACHE_MBE                       (9U)
/* NCF[10] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_10                       (10U)
/* NCF[11] eDMA2 SRAM TCD Multi-Bit Uncorrected Error */
#define EMCEM_FCCU_FLT_EDMA2TCD_MBE                      (11U)
/* NCF[12] SRAM Controller Safety Alarm */
#define EMCEM_FCCU_FLT_OCRAM_CTRL_ALARM                  (12U)
/* NCF[13] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_13                       (13U)
/* NCF[14] Debug mode activation */
#define EMCEM_FCCU_FLT_DEBUG_EN                          (14U)
/* NCF[15] Unintended Test mode activation */
#define EMCEM_FCCU_FLT_TEST_EN                           (15U)
/* NCF[16] Unintended MTR activation */
#define EMCEM_FCCU_FLT_MTR_EN                            (16U)
/* NCF[17] Unintended STCU activation */
#define EMCEM_FCCU_FLT_STCU_EN                           (17U)
/* NCF[18] WDOG2 timeout (Watchdog reset request) */
#define EMCEM_FCCU_FLT_WDOG2                             (18U)
/* NCF[19] WDOG3 timeout (Watchdog reset request) */
#define EMCEM_FCCU_FLT_WDOG3                             (19U)
/* NCF[20] WDOG4 timeout (Watchdog reset request) */
#define EMCEM_FCCU_FLT_WDOG4                             (20U)
/* NCF[21] WDOG5 timeout (Watchdog reset request) */
#define EMCEM_FCCU_FLT_WDOG5                             (21U)
/* NCF[22] Software Generated Fault 0 (Group 0, Fault 0) */
#define EMCEM_FCCU_FLT_SWNCF00                           (22U)
/* NCF[23] Software Generated Fault 1 (Group 0, Fault 1) */
#define EMCEM_FCCU_FLT_SWNCF01                           (23U)
/* NCF[24] Software Generated Fault 2 (Group 0, Fault 2) */
#define EMCEM_FCCU_FLT_SWNCF02                           (24U)
/* NCF[25] Software Generated Fault 3 (Group 0, Fault 3) */
#define EMCEM_FCCU_FLT_SWNCF03                           (25U)
/* NCF[26] Software Generated Fault 4 (Group 0, Fault 4) */
#define EMCEM_FCCU_FLT_SWNCF04                           (26U)
/* NCF[27] Software Generated Fault 5 (Group 0, Fault 5) */
#define EMCEM_FCCU_FLT_SWNCF05                           (27U)
/* NCF[28] Software Generated Fault 6 (Group 1, Fault 0) */
#define EMCEM_FCCU_FLT_SWNCF06                           (28U)
/* NCF[29] Software Generated Fault 7 (Group 1, Fault 1) */
#define EMCEM_FCCU_FLT_SWNCF07                           (29U)
/* NCF[30] Software Generated Fault 8 (Group 1, Fault 2) */
#define EMCEM_FCCU_FLT_SWNCF08                           (30U)
/* NCF[31] Software Generated Fault 9 (Group 1, Fault 3) */
#define EMCEM_FCCU_FLT_SWNCF09                           (31U)
/* NCF[32] Software Generated Fault 10 (Group 1, Fault 4) */
#define EMCEM_FCCU_FLT_SWNCF10                           (32U)
/* NCF[33] Software Generated Fault 11 (Group 1, Fault 5) */
#define EMCEM_FCCU_FLT_SWNCF11                           (33U)
/* NCF[34] M33 Lockup Error */
#define EMCEM_FCCU_FLT_M33_LOCKUP                        (34U)
/* NCF[35] Unintended M33 Reset assertion */
#define EMCEM_FCCU_FLT_M33_RST                           (35U)
/* NCF[36] Unintended M33 Debug activation */
#define EMCEM_FCCU_FLT_M33_DBG                           (36U)
/* NCF[37] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_37                       (37U)
/* NCF[38] M7 Lockup Error */
#define EMCEM_FCCU_FLT_M7_LOCKUP                         (38U)
/* NCF[39] Unintended M7 Reset assertion */
#define EMCEM_FCCU_FLT_M7_RST                            (39U)
/* NCF[40] Unintended M7 Debug activation */
#define EMCEM_FCCU_FLT_M7_DBG                            (40U)
/* NCF[41] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_41                       (41U)
/* NCF[42] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_42                       (42U)
/* NCF[43] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_43                       (43U)
/* NCF[44] Frequency loss or too low fault from an ANAMIX CMU */
#define EMCEM_FCCU_FLT_CMU_ANA_LOSS_LOW                  (44U)
/* NCF[45] Frequency too high from an ANAMIX CMU */
#define EMCEM_FCCU_FLT_CMU_ANA_HIGH                      (45U)
/* NCF[46] Frequency loss or too low fault from an AONMIX CMU */
#define EMCEM_FCCU_FLT_CMU_AON_LOSS_LOW                  (46U)
/* NCF[47] Frequency too high from an AONMIX CMU */
#define EMCEM_FCCU_FLT_CMU_AON_HIGH                      (47U)
/* NCF[48] Frequency loss or too low fault from a WAKEUPMIX CMU */
#define EMCEM_FCCU_FLT_CMU_WAKEUP_LOSS_LOW               (48U)
/* NCF[49] Frequency too high from a WAKEUPMIX CMU */
#define EMCEM_FCCU_FLT_CMU_WAKEUP_HIGH                   (49U)
/* NCF[50] Frequency loss or too low fault from a M7MIX CMU */
#define EMCEM_FCCU_FLT_CMU_M7_LOSS_LOW                   (50U)
/* NCF[51] Frequency too high from a M7MIX CMU */
#define EMCEM_FCCU_FLT_CMU_M7_HIGH                       (51U)
/* NCF[52] Frequency loss or too low fault from a DDRMIX CMU */
#define EMCEM_FCCU_FLT_CMU_DDR_LOSS_LOW                  (52U)
/* NCF[53] Frequency too high from a DDRMIX CMU */
#define EMCEM_FCCU_FLT_CMU_DDR_HIGH                      (53U)
/* NCF[54] Frequency loss or too low fault from a NOCMIX CMU */
#define EMCEM_FCCU_FLT_CMU_NOC_LOSS_LOW                  (54U)
/* NCF[55] Frequency too high from a NOCMIX CMU */
#define EMCEM_FCCU_FLT_CMU_NOC_HIGH                      (55U)
/* NCF[56] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_56                       (56U)
/* NCF[57] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_57                       (57U)
/* NCF[58] FlexNOC_Main Mission Fault */
#define EMCEM_FCCU_FLT_NOC_MAIN                          (58U)
/* NCF[59] FlexNOC_Mega Mission Fault */
#define EMCEM_FCCU_FLT_NOC_MEGA                          (59U)
/* NCF[60] FlexNOC_Central Mission Fault */
#define EMCEM_FCCU_FLT_NOC_CENTRAL                       (60U)
/* NCF[61] Parity fault from parity checkers around AXBS_M33_0 */
#define EMCEM_FCCU_FLT_PARITY_AXBS_M33                   (61U)
/* NCF[62] Parity fault from parity checkers around AXBS AON */
#define EMCEM_FCCU_FLT_PARITY_AXBS_AON                   (62U)
/* NCF[63] INTM Interrupt Monitor Fault */
#define EMCEM_FCCU_FLT_INTM                              (63U)
/* NCF[64] Parity fault from all parity gaskets and Safety relevant SSIs in AONMIX (except parity gaskets around AXMB_M33_0 and AXBS_AON) */
#define EMCEM_FCCU_FLT_PARITY_AONMIX                     (64U)
/* NCF[65] Parity fault from all parity gaskets and Safety relevant SSIs in WAKEUPMIX */
#define EMCEM_FCCU_FLT_PARITY_WAKEUPMIX                  (65U)
/* NCF[66] Parity fault from all parity gaskets and Safety relevant SSIs in NOCMIX */
#define EMCEM_FCCU_FLT_PARITY_NOCMIX                     (66U)
/* NCF[67] Parity fault from all parity gaskets and Safety relevant SSIs in M7MIX */
#define EMCEM_FCCU_FLT_PARITY_M7MIX                      (67U)
/* NCF[68] Parity fault from all parity gaskets and Safety relevant SSIs in DDRMIX */
#define EMCEM_FCCU_FLT_PARITY_DDRMIX                     (68U)
/* NCF[69] Parity fault from all parity gaskets and Safety relevant SSIs in NPUMIX */
#define EMCEM_FCCU_FLT_PARITY_NPUMIX                     (69U)
/* NCF[70] ATU_A lock-step error */
#define EMCEM_FCCU_FLT_RCCU_ATU_A                        (70U)
/* NCF[71] ATU_M lock-step error */
#define EMCEM_FCCU_FLT_RCCU_ATU_M                        (71U)
/* NCF[72] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_72                       (72U)
/* NCF[73] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_73                       (73U)
/* NCF[74] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_74                       (74U)
/* NCF[75] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_75                       (75U)
/* NCF[76] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_76                       (76U)
/* NCF[77] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_77                       (77U)
/* NCF[78] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_78                       (78U)
/* NCF[79] Reserved */
#define EMCEM_FCCU_FLT_RESERVED_79                       (79U)

/* Total VFCCU fault lines count */
#define EMCEM_CVFCCU_FAULT_LINES_COUNT                   (80U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define EMCEM_START_SEC_CONST_32
#include "eMcem_MemMap.h"

#define EMCEM_STOP_SEC_CONST_32
#include "eMcem_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_VFCCUFAULTLIST_MIMX95XX_H */

/** @} */
