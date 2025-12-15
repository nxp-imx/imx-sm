/**
*   @file    eMcem_VfccuFaultList_MIMX952X.h
*   @version 0.8.4
*
*   @brief   MIMX9XX_SAF eMcem - Specific VFCCU fault list header.
*   @details Contains list of specific VFCCU fault lines for eMcem module.
*
*   @addtogroup EMCEM_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : MIMX9XX_SAF
*   Platform             : CORTEXM
*
*   SW Version           : 0.8.4
*   Build Version        : MIMX9_SAF_0_8_4_20250110
*
*   Copyright 2026 NXP
*   Detailed license terms of software usage can be found in the license.txt
*   file located in the root folder of this package.
==================================================================================================*/

#ifndef EMCEM_VFCCUFAULTLIST_MIMX952X_H
#define EMCEM_VFCCUFAULTLIST_MIMX952X_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section eMcem_VfccuFaultList_MIMX952X_h_REF_0501
* Violates MISRA 2012 Required Rule 5.1, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_VfccuFaultList_MIMX952X_h_REF_0502
* Violates MISRA 2012 Required Rule 5.2, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_VfccuFaultList_MIMX952X_h_REF_0504
* Violates MISRA 2012 Required Rule 5.4, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
* @section eMcem_VfccuFaultList_MIMX952X_h_REF_0505
* Violates MISRA 2012 Required Rule 5.5, Supported compilers don't enforce maximum symbol length to be less than 32 characters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MIMX9XX_SAF_Version.h"
#include "SafetyBase_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*!
 * @name EMCEM VFCCU fault list definition SW version
 */
/** @{ */

/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0501 */
/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0502 */
/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0504 */
/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0505 */
/*!
* @brief    eMCEM VFCCU fault list for MIMX952X - SW major version
*/
#define EMCEM_VFCCUFAULTLIST_MIMX952X_SW_MAJOR_VERSION             0
/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0501 */
/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0502 */
/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0504 */
/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0505 */
/*!
* @brief    eMCEM VFCCU fault list for MIMX952X - SW minor version
*/
#define EMCEM_VFCCUFAULTLIST_MIMX952X_SW_MINOR_VERSION             8
/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0501 */
/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0502 */
/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0504 */
/* @violates @ref eMcem_VfccuFaultList_MIMX952X_h_REF_0505 */
/*!
* @brief    eMCEM VFCCU fault list for MIMX952X - SW patch version
*/
#define EMCEM_VFCCUFAULTLIST_MIMX952X_SW_PATCH_VERSION             4


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MIMX_SAF version header file are of the same software version */
#if ((EMCEM_VFCCUFAULTLIST_MIMX952X_SW_MAJOR_VERSION != MIMX9XX_SAF_SW_MAJOR_VERSION) || \
     (EMCEM_VFCCUFAULTLIST_MIMX952X_SW_MINOR_VERSION != MIMX9XX_SAF_SW_MINOR_VERSION) || \
     (EMCEM_VFCCUFAULTLIST_MIMX952X_SW_PATCH_VERSION != MIMX9XX_SAF_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMcem_VfccuFaultList_MIMX952X.h and MIMX9XX_SAF version are different"
#endif

#if SAFETY_BASE_MIMX952X
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*!
 * @name C_VFCCU fault lines
 */
/** @{ */

/*!
* @brief    NCF[0] Temperature sensor critical over-temperature (ANA)
*/
#define EMCEM_FCCU_FLT_TEMP_HIGH                         (0U)
/*!
* @brief    NCF[1] Temperature sensor critical over-temperature (CORTEXA)
*/
#define EMCEM_FCCU_FLT_TEMP2_HIGH                        (1U)
/*!
* @brief    NCF[2] DRAM controller internal fault
*/
#define EMCEM_FCCU_FLT_DDRC                              (2U)
/*!
* @brief    NCF[3] External DRAM array multi-bit uncorrected error
*/
#define EMCEM_FCCU_FLT_DDR_MBE                           (3U)
/*!
* @brief    NCF[4] Always-ON OCRAM Multi-Bit Uncorrected Error
*/
#define EMCEM_FCCU_FLT_OCRAM_MBE                         (4U)
/*!
* @brief    NCF[5] NPU SRAM Multi-Bit Uncorrected Error
*/
#define EMCEM_FCCU_FLT_NPUSRAM_MBE                       (5U)
/*!
* @brief    NCF[6] M33 TCM Uncorrected Multi Bit Error
*/
#define EMCEM_FCCU_FLT_M33TCM_MBE                        (6U)
/*!
* @brief    NCF[7] M33 Cache (system/code, data/tag) Uncorrected Multi Bit Error
*/
#define EMCEM_FCCU_FLT_M33CACHE_MBE                      (7U)
/*!
* @brief    NCF[8] M7 TCM Uncorrected Multi Bit Error
*/
#define EMCEM_FCCU_FLT_M7TCM_MBE                         (8U)
/*!
* @brief    NCF[9] M7 Cache (instruction/data, data/tag) Uncorrected Multi Bit Error
*/
#define EMCEM_FCCU_FLT_M7CACHE_MBE                       (9U)
/*!
* @brief    NCF[10] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_10                       (10U)
/*!
* @brief   NCF[11] eDMA2 SRAM TCD Multi-Bit Uncorrected Error
*/
#define EMCEM_FCCU_FLT_EDMA2TCD_MBE                      (11U)
/*!
* @brief   NCF[12] SRAM Controller Safety Alarm
*/
#define EMCEM_FCCU_FLT_OCRAM_CTRL_ALARM                  (12U)
/*!
* @brief   NCF[13] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_13                       (13U)
/*!
* @brief   NCF[14] Debug mode activation
*/
#define EMCEM_FCCU_FLT_DEBUG_EN                          (14U)
/*!
* @brief   NCF[15] Unintended Test mode activation
*/
#define EMCEM_FCCU_FLT_TEST_EN                           (15U)
/*!
* @brief   NCF[16] Unintended MTR activation
*/
#define EMCEM_FCCU_FLT_MTR_EN                            (16U)
/*!
* @brief   NCF[17] Unintended STCU activation
*/
#define EMCEM_FCCU_FLT_STCU_EN                           (17U)
/*!
* @brief   NCF[18] WDOG2 timeout (Watchdog reset request)
*/
#define EMCEM_FCCU_FLT_WDOG2                             (18U)
/*!
* @brief   NCF[19] WDOG3 timeout (Watchdog reset request)
*/
#define EMCEM_FCCU_FLT_WDOG3                             (19U)
/*!
* @brief   NCF[20] WDOG4 timeout (Watchdog reset request)
*/
#define EMCEM_FCCU_FLT_WDOG4                             (20U)
/*!
* @brief   NCF[21] WDOG5 timeout (Watchdog reset request)
*/
#define EMCEM_FCCU_FLT_WDOG5                             (21U)
/*!
* @brief   NCF[22] Software Generated Fault 0 (Group 0, Fault 0)
*/
#define EMCEM_FCCU_FLT_SWNCF00                           (22U)
/*!
* @brief   NCF[23] Software Generated Fault 1 (Group 0, Fault 1)
*/
#define EMCEM_FCCU_FLT_SWNCF01                           (23U)
/*!
* @brief    NCF[24] Software Generated Fault 2 (Group 0, Fault 2)
*/
#define EMCEM_FCCU_FLT_SWNCF02                           (24U)
/*!
* @brief   NCF[25] Software Generated Fault 3 (Group 0, Fault 3)
*/
#define EMCEM_FCCU_FLT_SWNCF03                           (25U)
/*!
* @brief   NCF[26] Software Generated Fault 4 (Group 0, Fault 4)
*/
#define EMCEM_FCCU_FLT_SWNCF04                           (26U)
/*!
* @brief   NCF[27] Software Generated Fault 5 (Group 0, Fault 5)
*/
#define EMCEM_FCCU_FLT_SWNCF05                           (27U)
/*!
* @brief   NCF[28] Software Generated Fault 6 (Group 1, Fault 0)
*/
#define EMCEM_FCCU_FLT_SWNCF06                           (28U)
/*!
* @brief   NCF[29] Software Generated Fault 7 (Group 1, Fault 1)
*/
#define EMCEM_FCCU_FLT_SWNCF07                           (29U)
/*!
* @brief   NCF[30] Software Generated Fault 8 (Group 1, Fault 2)
*/
#define EMCEM_FCCU_FLT_SWNCF08                           (30U)
/*!
* @brief   NCF[31] Software Generated Fault 9 (Group 1, Fault 3)
*/
#define EMCEM_FCCU_FLT_SWNCF09                           (31U)
/*!
* @brief   NCF[32] Software Generated Fault 10 (Group 1, Fault 4)
*/
#define EMCEM_FCCU_FLT_SWNCF10                           (32U)
/*!
* @brief   NCF[33] Software Generated Fault 11 (Group 1, Fault 5)
*/
#define EMCEM_FCCU_FLT_SWNCF11                           (33U)
/*!
* @brief   NCF[34] M33 Lockup Error
*/
#define EMCEM_FCCU_FLT_M33_LOCKUP                        (34U)
/*!
* @brief   NCF[35] Unintended M33 Reset assertion
*/
#define EMCEM_FCCU_FLT_M33_RST                           (35U)
/*!
* @brief   NCF[36] Unintended M33 Debug activation
*/
#define EMCEM_FCCU_FLT_M33_DBG                           (36U)
/*!
* @brief   NCF[37] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_37                       (37U)
/*!
* @brief   NCF[38] M7 Lockup Error
*/
#define EMCEM_FCCU_FLT_M7_LOCKUP                         (38U)
/*!
* @brief   NCF[39] Unintended M7 Reset assertion
*/
#define EMCEM_FCCU_FLT_M7_RST                            (39U)
/*!
* @brief   NCF[40] Unintended M7 Debug activation
*/
#define EMCEM_FCCU_FLT_M7_DBG                            (40U)
/*!
* @brief   NCF[41] Security CRRM AWDT expiry notification before reset
*/
#define EMCEM_FCCU_FLT_SECURITY_CRRM_AWDT                (41U)
/*!
* @brief   NCF[42] Security Fault (s4v1_lmda_sys_fail)
*/
#define EMCEM_FCCU_FLT_SECURITY                          (42U)
/*!
* @brief   NCF[43] OCOTP Uncorrectable error from Fuse read
*/
#define EMCEM_FCCU_FLT_OCOTP_FUSE_ERROR                  (43U)
/*!
* @brief    NCF[44] Frequency loss or too low fault from an ANAMIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_ANA_LOSS_LOW                  (44U)
/*!
* @brief   NCF[45] Frequency too high from an ANAMIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_ANA_HIGH                      (45U)
/*!
* @brief   NCF[46] Frequency loss or too low fault from an AONMIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_AON_LOSS_LOW                  (46U)/*  */
/*!
* @brief   NCF[47] Frequency too high from an AONMIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_AON_HIGH                      (47U)
/*!
* @brief   NCF[48] Frequency loss or too low fault from a WAKEUPMIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_WAKEUP_LOSS_LOW               (48U)
/*!
* @brief   NCF[49] Frequency too high from a WAKEUPMIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_WAKEUP_HIGH                   (49U)
/*!
* @brief   NCF[50] Frequency loss or too low fault from a M7MIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_M7_LOSS_LOW                   (50U)
/*!
* @brief   NCF[51] Frequency too high from a M7MIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_M7_HIGH                       (51U)
/*!
* @brief   NCF[52] Frequency loss or too low fault from a DDRMIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_DDR_LOSS_LOW                  (52U)
/*!
* @brief   NCF[53] Frequency too high from a DDRMIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_DDR_HIGH                      (53U)
/*!
* @brief   NCF[54] Frequency loss or too low fault from a NOCMIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_NOC_LOSS_LOW                  (54U)
/*!
* @brief   NCF[55] Frequency too high from a NOCMIX CMU
*/
#define EMCEM_FCCU_FLT_CMU_NOC_HIGH                      (55U)
/*!
* @brief   NCF[56] Voltage detector (VDET) low voltage detected
*/
#define EMCEM_FCCU_FLT_VDET_LVD                          (56U)
/*!
* @brief   NCF[57] Voltage detector (VDET) high voltage detected
*/
#define EMCEM_FCCU_FLT_VDET_HVD                          (57U)
/*!
* @brief   NCF[58] FlexNOC_Wakeup Mission Fault
*/
#define EMCEM_FCCU_FLT_NOC_WAKEUP                        (58U)
/*!
* @brief   NCF[59] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_59                       (59U)
/*!
* @brief   NCF[60] FlexNOC_Central Mission Fault
*/
#define EMCEM_FCCU_FLT_NOC_CENTRAL                       (60U)
/*!
* @brief   NCF[61] Parity fault from parity checkers around AXBS_M33_0
*/
#define EMCEM_FCCU_FLT_PARITY_AXBS_M33                   (61U)
/*!
* @brief   NCF[62] Parity fault from parity checkers around AXBS AONU
*/
#define EMCEM_FCCU_FLT_PARITY_AXBS_AON                   (62U)
/*!
* @brief   NCF[63] INTM Interrupt Monitor Fault
*/
#define EMCEM_FCCU_FLT_INTM                              (63U)
/*!
* @brief   NCF[64] Parity fault from all parity gaskets and Safety relevant SSIs in AONMIX (except parity gaskets around AXMB_M33_0 and AXBS_AON)
*/
#define EMCEM_FCCU_FLT_PARITY_AONMIX                     (64U)
/*!
* @brief   NCF[65] Parity fault from all parity gaskets and Safety relevant SSIs in WAKEUPMIX
*/
#define EMCEM_FCCU_FLT_PARITY_WAKEUPMIX                  (65U)
/*!
* @brief   NCF[66] Parity fault from all parity gaskets and Safety relevant SSIs in NOCMIX
*/
#define EMCEM_FCCU_FLT_PARITY_NOCMIX                     (66U)
/*!
* @brief   NCF[67] Parity fault from all parity gaskets and Safety relevant SSIs in M7MIX
*/
#define EMCEM_FCCU_FLT_PARITY_M7MIX                      (67U)
/*!
* @brief   NCF[68] Parity fault from all parity gaskets and Safety relevant SSIs in DDRMIX
*/
#define EMCEM_FCCU_FLT_PARITY_DDRMIX                     (68U)
/*!
* @brief   NCF[69] Parity fault from all parity gaskets and Safety relevant SSIs in NPUMIX
*/
#define EMCEM_FCCU_FLT_PARITY_NPUMIX                     (69U)
/*!
* @brief   NCF[70] ATU_A lock-step error
*/
#define EMCEM_FCCU_FLT_RCCU_ATU_A                        (70U)
/*!
* @brief   NCF[71] ATU_M7 lock-step error
*/
#define EMCEM_FCCU_FLT_RCCU_ATU_M7                       (71U)
/*!
* @brief    NCF[72] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_72                       (72U)
/*!
* @brief    NCF[73] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_73                       (73U)
/*!
* @brief    NCF[74] Display domain OCRAM_D ECC Multi Bit error
*/
#define EMCEM_FCCU_FLT_OCRAM_D_MBE                       (74U)
/*!
* @brief   NCF[75] OCRAM_D SRAM Controller Safety Alarm
*/
#define EMCEM_FCCU_FLT_OCRAM_D_CTRL_ALARM                (75U)
/*!
* @brief   NCF[76] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_76                       (76U)
/*!
* @brief    NCF[77] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_77                       (77U)
/*!
* @brief    NCF[78] Display controller generated fault from its internal checks
*/
#define EMCEM_FCCU_FLT_DISPLAY_CONTROLLER                (78U)
/*!
* @brief    NCF[79] Display domain MIPI DSI Command Even and Odd FIFO memory ECC Multi Bit error
*/
#define EMCEM_FCCU_FLT_MIPI_DSI_COMMAND_FIFO_MBE         (79U)
/*!
* @brief    NCF[80] Display domain MIPI DSI Payload Even and Odd FIFO memory ECC Multi Bit error
*/
#define EMCEM_FCCU_FLT_MIPI_DSI_PAYLOAD_FIFO_MBE         (80U)
/*!
* @brief    NCF[81] Display domain MIPI DSI Pixel Even and Odd FIFO memory ECC Multi Bit error
*/
#define EMCEM_FCCU_FLT_MIPI_DSI_PIXEL_FIFO_MBE           (81U)
/*!
* @brief    NCF[82] Frequency loss or too low fault from a Display domain CMU
*/
#define EMCEM_FCCU_FLT_CMU_DISP_LOSS_LOW                 (82U)
/*!
* @brief    NCF[83] Frequency too high from a Display domain CMU
*/
#define EMCEM_FCCU_FLT_CMU_DISP_HIGH                     (83U)
/*!
* @brief    NCF[84] Parity fault from parity checkers before DSI Host controller
*/
#define EMCEM_FCCU_FLT_PARITY_DSI_PL                     (84U)
/*!
* @brief    NCF[85] MIPI DSI controller error status - packet header ECC - data CRC error - other errors reported by the MIPI DSI controller
*/
#define EMCEM_FCCU_FLT_MIPI_DSI_PACKET_ERROR             (85U)
/*!
* @brief    NCF[86] WDOG6 timeout (Watchdog reset request)
*/
#define EMCEM_FCCU_FLT_WDOG6                             (86U)
/*!
* @brief    NCF[87] Parity fault from parity checkers before Pixel Mapper
*/
#define EMCEM_FCCU_FLT_PARITY_PIXEL                      (87U)
/*!
* @brief    NCF[88] eDMA3 SRAM TCD Multi-Bit Uncorrected Error
*/
#define EMCEM_FCCU_FLT_EDMA3TCD_MBE                      (88U)
/*!
* @brief    NCF[89] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_89                       (89U)
/*!
* @brief    NCF[90] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_90                       (90U)
/*!
* @brief    NCF[91] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_91                       (91U)
/*!
* @brief    NCF[92] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_92                       (92U)
/*!
* @brief    NCF[93] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_93                       (93U)
/*!
* @brief    NCF[94] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_94                       (94U)
/*!
* @brief    NCF[95] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_95                       (95U)
/*!
* @brief    NCF[96] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_96                       (96U)
/*!
* @brief    NCF[97] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_97                       (97U)
/*!
* @brief    NCF[98] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_98                       (98U)
/*!
* @brief    NCF[99] Reserved
*/
#define EMCEM_FCCU_FLT_RESERVED_99                       (99U)

/*!
* @brief   Total VFCCU fault lines count
*/
#define EMCEM_VFCCU_FAULT_LINES_COUNT                   (100U)
/** @} */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* SAFETY_BASE_MIMX952X */

#ifdef __cplusplus
}
#endif

#endif /* EMCEM_VFCCUFAULTLIST_MIMX952X_H */

/** @} */
