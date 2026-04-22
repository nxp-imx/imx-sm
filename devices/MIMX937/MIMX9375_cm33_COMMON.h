/*
** ###################################################################
**     Processors:          MIMX9375xxVTx_cm33
**                          MIMX9375xxVZx_cm33
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    iMX937RM Rev. 1 Draft A
**     Version:             rev. 1.0, 2026-04-09
**     Build:               b260522
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX9375_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026-04-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MIMX9375_cm33_COMMON.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for MIMX9375_cm33
 *
 * CMSIS Peripheral Access Layer for MIMX9375_cm33
 */

#if !defined(MIMX9375_CM33_COMMON_H_)
#define MIMX9375_CM33_COMMON_H_                  /**< Symbol preventing repeated inclusion */

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0000U


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 431                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M33 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M33 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M33 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M33 Usage Fault Interrupt */
  SecureFault_IRQn             = -9,               /**< Cortex-M33 Secure Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M33 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M33 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M33 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M33 System Tick Interrupt */

  /* Device specific interrupts */
  RESERVED16_IRQn              = 0,                /**< Reserved interrupt */
  RESERVED17_IRQn              = 1,                /**< DAP Interrupt */
  RESERVED18_IRQn              = 2,                /**< CTI trigger outputs from CM7 platform  (internal: CTIIRQ[0]) */
  RESERVED19_IRQn              = 3,                /**< CTI trigger outputs from CM33 platform  (internal: CTIIRQ[0]) */
  RESERVED20_IRQn              = 4,                /**< CTI trigger outputs from CA55 platform  (internal: nCTIIRQ[0]) */
  RESERVED21_IRQn              = 5,                /**< Performance Unit Interrupts from CA55 platform (interrnally:  PMUIRQ[0]) */
  RESERVED22_IRQn              = 6,                /**< ECC error with potential data corruption or loss of coherency from CA55 platform L3 Cache */
  RESERVED23_IRQn              = 7,                /**< 1-bit or 2-bit ECC or Parity error from CA55 platform L3 Cache */
  CAN1_IRQn                    = 8,                /**< AONMIX CAN-FD Interrupt from busoff */
  CAN1_ERROR_IRQn              = 9,                /**< AONMIX CAN-FD Correctable error interrupt */
  GPIO1_0_IRQn                 = 10,               /**< AONMIX GPIO interrupt request 0 */
  GPIO1_1_IRQn                 = 11,               /**< AONMIX GPIO interrupt request 1 */
  I3C1_IRQn                    = 12,               /**< AONMIX I3C interrupt request */
  LPI2C1_IRQn                  = 13,               /**< AONMIX LPI2C Master interrupt */
  LPI2C2_IRQn                  = 14,               /**< AONMIX LPI2C Master interrupt */
  LPIT1_IRQn                   = 15,               /**< AONMIX LPIT global interrupt */
  LPSPI1_IRQn                  = 16,               /**< AONMIX LPSPI interrupt */
  LPSPI2_IRQn                  = 17,               /**< AONMIX LPSPI interrupt */
  LPTMR1_IRQn                  = 18,               /**< AONMIX LPTMR async interrupt */
  LPUART1_IRQn                 = 19,               /**< AONMIX LPUART TX interrupt */
  LPUART2_IRQn                 = 20,               /**< AONMIX LPUART TX interrupt */
  RESERVED37_IRQn              = 21,               /**< AONMIX Sentinel MU0 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED38_IRQn              = 22,               /**< AONMIX Sentinel MU1 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED39_IRQn              = 23,               /**< AONMIX Sentinel MU2 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED40_IRQn              = 24,               /**< AONMIX Sentinel MU3 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED41_IRQn              = 25,               /**< AONMIX Sentinel MU4 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED42_IRQn              = 26,               /**< AONMIX Sentinel MU5 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX */
  RESERVED43_IRQn              = 27,               /**< V2X-FH MU APCH0 (APP0) A_TX interrupt */
  RESERVED44_IRQn              = 28,               /**< V2X-FH MU APHSM1 (HSM1) A_TX interrupt */
  TPM1_IRQn                    = 29,               /**< AONMIX LPTPM global interrupt */
  TPM2_IRQn                    = 30,               /**< AONMIX LPTPM global interrupt */
  WDOG1_IRQn                   = 31,               /**< AONMIX Watchdog interrupt request.  SRC reset source. */
  WDOG2_IRQn                   = 32,               /**< AONMIX Watchdog interrupt request.  SRC reset source. */
  TRDC_MGR_A_IRQn              = 33,               /**< AONMIX TRDC transfer error interrupt */
  SAI1_IRQn                    = 34,               /**< AONMIX SAI TX interrupt */
  RESERVED51_IRQn              = 35,               /**< AONMIX M33 PS Tag Parity Error */
  CM33_ECC_MCM_IRQn            = 36,               /**< AONMIX M33 TCM Error interrupt */
  RESERVED53_IRQn              = 37,               /**< M7MIX ECC Multi-bit error */
  CAN2_IRQn                    = 38,               /**< WAKEUPMIX CAN-FD Interrupt from busoff */
  CAN2_ERROR_IRQn              = 39,               /**< WAKEUPMIX CAN-FD Correctable error interrupt */
  CAN3_IRQn                    = 40,               /**< WAKEUPMIX CAN-FD Interrupt from busoff */
  CAN3_ERROR_IRQn              = 41,               /**< WAKEUPMIX CAN-FD Correctable error interrupt */
  WDOG6_IRQn                   = 42,               /**< DISPLAYMIX Watchdog interrupt request. SRC reset source. */
  RESERVED59_IRQn              = 43,               /**< Additional inverted version of Interrupt added for s500_scm_halt_ack_irq. Which could be uzseful for Sentinel Wakeup */
  RESERVED60_IRQn              = 44,               /**< s500.sentinel_irq_glue_s500_irq_req4 is connected with ocotp_cont_edc_err */
  DISPLAY_MIX_IRQn             = 45,               /**< Local Dimming Interrupt */
  FLEXIO1_IRQn                 = 46,               /**< WAKEUPMIX FLEXIO interrupt */
  FLEXIO2_IRQn                 = 47,               /**< WAKEUPMIX FLEXIO interrupt */
  RESERVED64_IRQn              = 48,               /**< Reserved */
  GPIO2_0_IRQn                 = 49,               /**< WAKEUPMIX GPIO interrupt request 0 */
  GPIO2_1_IRQn                 = 50,               /**< WAKEUPMIX GPIO interrupt request 1 */
  GPIO3_0_IRQn                 = 51,               /**< WAKEUPMIX GPIO interrupt request 0 */
  GPIO3_1_IRQn                 = 52,               /**< WAKEUPMIX GPIO interrupt request 1 */
  GPIO4_0_IRQn                 = 53,               /**< WAKEUPMIX GPIO interrupt request 0 */
  GPIO4_1_IRQn                 = 54,               /**< WAKEUPMIX GPIO interrupt request 1 */
  GPIO5_0_IRQn                 = 55,               /**< WAKEUPMIX GPIO interrupt request 0 */
  GPIO5_1_IRQn                 = 56,               /**< WAKEUPMIX GPIO interrupt request 1 */
  I3C2_IRQn                    = 57,               /**< WAKEUPMIX I3C interrupt request */
  LPI2C3_IRQn                  = 58,               /**< WAKEUPMIX LPI2C Master interrupt */
  LPI2C4_IRQn                  = 59,               /**< WAKEUPMIX LPI2C Master interrupt */
  LPIT2_IRQn                   = 60,               /**< WAKEUPMIX LPIT global interrupt */
  LPSPI3_IRQn                  = 61,               /**< WAKEUPMIX LPSPI interrupt */
  LPSPI4_IRQn                  = 62,               /**< WAKEUPMIX LPSPI interrupt */
  LPTMR2_IRQn                  = 63,               /**< WAKEUPMIX LPTMR async interrupt */
  LPUART3_IRQn                 = 64,               /**< WAKEUPMIX LPUART TX interrupt */
  LPUART4_IRQn                 = 65,               /**< WAKEUPMIX LPUART TX interrupt */
  LPUART5_IRQn                 = 66,               /**< WAKEUPMIX LPUART TX interrupt */
  LPUART6_IRQn                 = 67,               /**< WAKEUPMIX LPUART TX interrupt */
  LPUART7_IRQn                 = 68,               /**< WAKEUPMIX LPUART TX interrupt */
  LPUART8_IRQn                 = 69,               /**< WAKEUPMIX LPUART TX interrupt */
  MTR_MSTR_IRQn                = 70,               /**< AONMIX MTR Master error interrupt */
  BBNSM_IRQn                   = 71,               /**< BBNSM Non-Secure external wakeup alarm */
  SYS_CTR1_IRQn                = 72,               /**< WAKEUPMIX System Counter compare interrupt 0 */
  TPM3_IRQn                    = 73,               /**< WAKEUPMIX LPTPM global interrupt */
  TPM4_IRQn                    = 74,               /**< WAKEUPMIX LPTPM global interrupt */
  TPM5_IRQn                    = 75,               /**< WAKEUPMIX LPTPM async interrupt */
  TPM6_IRQn                    = 76,               /**< WAKEUPMIX LPTPM async interrupt */
  WDOG3_IRQn                   = 77,               /**< WAKEUPMIX Watchdog interrupt request. SRC reset source. */
  WDOG4_IRQn                   = 78,               /**< WAKEUPMIX Watchdog interrupt request. SRC reset source. */
  WDOG5_IRQn                   = 79,               /**< WAKEUPMIX Watchdog interrupt request. SRC reset source. */
  TMPSNS1_THR1_IRQn            = 80,               /**< ANAMIX TempSensor non-secure interrupt from Threshold 1 */
  TMPSNS1_THR2_IRQn            = 81,               /**< ANAMIX TempSensor non-secure interrupt from Threshold 2 */
  TMPSNS1_DRDY_IRQn            = 82,               /**< ANAMIX TempSensor non-secure data ready interrupt */
  TMPSNS2_THR1_IRQn            = 83,               /**< CORTEXAMIX TempSensor non-secure interrupt from Threshold 1 */
  TMPSNS2_THR2_IRQn            = 84,               /**< CORTEXAMIX TempSensor non-secure interrupt from Threshold 2 */
  TMPSNS2_DRDY_IRQn            = 85,               /**< CORTEXAMIX TempSensor non-secure data ready interrupt */
  USDHC1_IRQn                  = 86,               /**< MEGAMIX uSDHC Enhanced SDHC Interrupt Request */
  USDHC2_IRQn                  = 87,               /**< MEGAMIX uSDHC Enhanced SDHC Interrupt Request */
  TRDC_MGR_W1_IRQn             = 88,               /**< WAKEUPMIX TRDC transfer error interrupt */
  TRDC_MGR_W2_IRQn             = 89,               /**< WAKEUPMIX TRDC transfer error interrupt */
  TRDC_MGR_N_IRQn              = 90,               /**< NOCMIX TRDC transfer error interrupt */
  RESERVED107_IRQn             = 91,               /**< DRAM controller Performance Monitor Interrupt */
  RESERVED108_IRQn             = 92,               /**< DRAM controller Critical Interrupt */
  RESERVED109_IRQn             = 93,               /**< DRAM Phy Critical Interrupt 0 */
  INTG_BOOTROM_DEBUG_CTRL_IRQn = 94,               /**< Cortex-A Cluster Debug Wakeup Request */
  DMA3_ERROR_IRQn              = 95,               /**< AONMIX EDMA error interrupt */
  DMA3_0_IRQn                  = 96,               /**< AONMIX EDMA channel 0 interrupt */
  DMA3_1_IRQn                  = 97,               /**< AONMIX EDMA channel 1 interrupt */
  DMA3_2_IRQn                  = 98,               /**< AONMIX EDMA channel 2 interrupt */
  DMA3_3_IRQn                  = 99,               /**< AONMIX EDMA channel 3 interrupt */
  DMA3_4_IRQn                  = 100,              /**< AONMIX EDMA channel 4 interrupt */
  DMA3_5_IRQn                  = 101,              /**< AONMIX EDMA channel 5 interrupt */
  DMA3_6_IRQn                  = 102,              /**< AONMIX EDMA channel 6 interrupt */
  DMA3_7_IRQn                  = 103,              /**< AONMIX EDMA channel 7 interrupt */
  DMA3_8_IRQn                  = 104,              /**< AONMIX EDMA channel 8 interrupt */
  DMA3_9_IRQn                  = 105,              /**< AONMIX EDMA channel 9 interrupt */
  DMA3_10_IRQn                 = 106,              /**< AONMIX EDMA channel 10 interrupt */
  DMA3_11_IRQn                 = 107,              /**< AONMIX EDMA channel 11 interrupt */
  DMA3_12_IRQn                 = 108,              /**< AONMIX EDMA channel 12 interrupt */
  DMA3_13_IRQn                 = 109,              /**< AONMIX EDMA channel 13 interrupt */
  DMA3_14_IRQn                 = 110,              /**< AONMIX EDMA channel 14 interrupt */
  DMA3_15_IRQn                 = 111,              /**< AONMIX EDMA channel 15 interrupt */
  DMA3_16_IRQn                 = 112,              /**< AONMIX EDMA channel 16 interrupt */
  DMA3_17_IRQn                 = 113,              /**< AONMIX EDMA channel 17 interrupt */
  DMA3_18_IRQn                 = 114,              /**< AONMIX EDMA channel 18 interrupt */
  DMA3_19_IRQn                 = 115,              /**< AONMIX EDMA channel 19 interrupt */
  DMA3_20_IRQn                 = 116,              /**< AONMIX EDMA channel 20 interrupt */
  DMA3_21_IRQn                 = 117,              /**< AONMIX EDMA channel 21 interrupt */
  DMA3_22_IRQn                 = 118,              /**< AONMIX EDMA channel 22 interrupt */
  DMA3_23_IRQn                 = 119,              /**< AONMIX EDMA channel 23 interrupt */
  DMA3_24_IRQn                 = 120,              /**< AONMIX EDMA channel 24 interrupt */
  DMA3_25_IRQn                 = 121,              /**< AONMIX EDMA channel 25 interrupt */
  DMA3_26_IRQn                 = 122,              /**< AONMIX EDMA channel 26 interrupt */
  DMA3_27_IRQn                 = 123,              /**< AONMIX EDMA channel 27 interrupt */
  DMA3_28_IRQn                 = 124,              /**< AONMIX EDMA channel 28 interrupt */
  DMA3_29_IRQn                 = 125,              /**< AONMIX EDMA channel 29 interrupt */
  DMA3_30_IRQn                 = 126,              /**< AONMIX EDMA channel 30 interrupt */
  DMA5_2_ERROR_IRQn            = 127,              /**< WAKEUPMIX EDMA error interrupt */
  DMA5_2_0_1_IRQn              = 128,              /**< WAKEUPMIX EDMA channel 0 interrupt */
  DMA5_2_2_3_IRQn              = 129,              /**< WAKEUPMIX EDMA channel 2 interrupt */
  DMA5_2_4_5_IRQn              = 130,              /**< WAKEUPMIX EDMA channel 4 interrupt */
  DMA5_2_6_7_IRQn              = 131,              /**< WAKEUPMIX EDMA channel 6 interrupt */
  DMA5_2_8_9_IRQn              = 132,              /**< WAKEUPMIX EDMA channel 8 interrupt */
  DMA5_2_10_11_IRQn            = 133,              /**< WAKEUPMIX EDMA channel 10 interrupt */
  DMA5_2_12_13_IRQn            = 134,              /**< WAKEUPMIX EDMA channel 12 interrupt */
  DMA5_2_14_15_IRQn            = 135,              /**< WAKEUPMIX EDMA channel 14 interrupt */
  DMA5_2_16_17_IRQn            = 136,              /**< WAKEUPMIX EDMA channel 16 interrupt */
  DMA5_2_18_19_IRQn            = 137,              /**< WAKEUPMIX EDMA channel 18 interrupt */
  DMA5_2_20_21_IRQn            = 138,              /**< WAKEUPMIX EDMA channel 20 interrupt */
  DMA5_2_22_23_IRQn            = 139,              /**< WAKEUPMIX EDMA channel 22 interrupt */
  DMA5_2_24_25_IRQn            = 140,              /**< WAKEUPMIX EDMA channel 24 interrupt */
  DMA5_2_26_27_IRQn            = 141,              /**< WAKEUPMIX EDMA channel 26 interrupt */
  DMA5_2_28_29_IRQn            = 142,              /**< WAKEUPMIX EDMA channel 28 interrupt */
  DMA5_2_30_31_IRQn            = 143,              /**< WAKEUPMIX EDMA channel 30 interrupt */
  DMA5_2_32_33_IRQn            = 144,              /**< WAKEUPMIX EDMA channel 32 interrupt */
  DMA5_2_34_35_IRQn            = 145,              /**< WAKEUPMIX EDMA channel 34 interrupt */
  DMA5_2_36_37_IRQn            = 146,              /**< WAKEUPMIX EDMA channel 36 interrupt */
  DMA5_2_38_39_IRQn            = 147,              /**< WAKEUPMIX EDMA channel 38 interrupt */
  DMA5_2_40_41_IRQn            = 148,              /**< WAKEUPMIX EDMA channel 40 interrupt */
  DMA5_2_42_43_IRQn            = 149,              /**< WAKEUPMIX EDMA channel 42 interrupt */
  DMA5_2_44_45_IRQn            = 150,              /**< WAKEUPMIX EDMA channel 44 interrupt */
  DMA5_2_46_47_IRQn            = 151,              /**< WAKEUPMIX EDMA channel 46 interrupt */
  DMA5_2_48_49_IRQn            = 152,              /**< WAKEUPMIX EDMA channel 48 interrupt */
  DMA5_2_50_51_IRQn            = 153,              /**< WAKEUPMIX EDMA channel 50 interrupt */
  DMA5_2_52_53_IRQn            = 154,              /**< WAKEUPMIX EDMA channel 52 interrupt */
  DMA5_2_54_55_IRQn            = 155,              /**< WAKEUPMIX EDMA channel 54 interrupt */
  DMA5_2_56_57_IRQn            = 156,              /**< WAKEUPMIX EDMA channel 56 interrupt */
  DMA5_2_58_59_IRQn            = 157,              /**< WAKEUPMIX EDMA channel 58 interrupt */
  DMA5_2_60_61_IRQn            = 158,              /**< WAKEUPMIX EDMA channel 60 interrupt */
  DMA5_2_62_63_IRQn            = 159,              /**< WAKEUPMIX EDMA channel 62 interrupt */
  ELE_GROUP1_IRQn              = 160,              /**< Sentinel Group 1 reset source if no s500 reference clock is detected.  Output synchronized to 32khz clk. */
  ELE_GROUP2_IRQn              = 161,              /**< Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk. */
  ELE_GROUP3_IRQn              = 162,              /**< Sentinel Group 3 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk. */
  DBG_TRACE_IRQn               = 163,              /**< JTAGSW DAP MDM-AP SRC reset source */
  JTAGC_IRQn                   = 164,              /**< JTAGC SRC reset source (the JTAGC used for boundary scan, not JTAGC used for password authentication) */
  SYSREQRST_CM33_IRQn          = 165,              /**< CM33 SYSREQRST SRC reset source */
  LOCKUP_CM33_IRQn             = 166,              /**< CM33 LOCKUP SRC reset source */
  SYSREQRST_CM7_IRQn           = 167,              /**< CM7 SYSREQRST SRC reset source */
  LOCKUP_CM7_IRQn              = 168,              /**< CM7 LOCKUP SRC reset source */
  SAI2_IRQn                    = 169,              /**< NETCMIX SAI TX interrupt */
  SAI3_IRQn                    = 170,              /**< WAKEUPMIX SAI TX interrupt */
  SAI4_IRQn                    = 171,              /**< WAKEUPMIX SAI TX interrupt */
  SAI5_IRQn                    = 172,              /**< WAKEUPMIX SAI TX interrupt */
  USB1_WAKEUP_IRQn             = 173,              /**< USB-1 (USB 2.0) Wake-up Interrupt */
  USB2_WAKEUP_IRQn             = 174,              /**< USB-2 (USB 2.0) Wake-up Interrupt */
  USB1_IRQn                    = 175,              /**< USB-1 (USB 2.0 Controller) Interrupt */
  USB2_IRQn                    = 176,              /**< USB-2 (USB 2.0 Controller) Interrupt */
  LPSPI5_IRQn                  = 177,              /**< WAKEUPMIX LPSPI interrupt */
  LPSPI6_IRQn                  = 178,              /**< WAKEUPMIX LPSPI interrupt */
  LPSPI7_IRQn                  = 179,              /**< WAKEUPMIX LPSPI interrupt */
  LPSPI8_IRQn                  = 180,              /**< WAKEUPMIX LPSPI interrupt */
  LPI2C5_IRQn                  = 181,              /**< WAKEUPMIX LPI2C Master interrupt */
  LPI2C6_IRQn                  = 182,              /**< WAKEUPMIX LPI2C Master interrupt */
  LPI2C7_IRQn                  = 183,              /**< WAKEUPMIX LPI2C Master interrupt */
  LPI2C8_IRQn                  = 184,              /**< WAKEUPMIX LPI2C Master interrupt */
  PDM_HWVAD_ERROR_IRQn         = 185,              /**< AONMIXMIX PDM interrupt */
  PDM_HWVAD_EVENT_IRQn         = 186,              /**< AONMIXMIX PDM interrupt */
  PDM_ERROR_IRQn               = 187,              /**< AONMIXMIX PDM interrupt */
  PDM_EVENT_IRQn               = 188,              /**< AONMIXMIX PDM interrupt */
  RESERVED205_IRQn             = 189,              /**< WAKEUPMIX AUDIO XCVR interrupt */
  RESERVED206_IRQn             = 190,              /**< WAKEUPMIX AUDIO XCVR interrupt */
  USDHC3_IRQn                  = 191,              /**< MEGAMIX uSDHC Enhanced SDHC Interrupt Request */
  RESERVED208_IRQn             = 192,              /**< OCRAM ECC single bit error */
  RESERVED209_IRQn             = 193,              /**< OCRAM ECC multi bit error */
  RESERVED210_IRQn             = 194,              /**< CM33 MCM interrupt */
  RESERVED211_IRQn             = 195,              /**< ANAMIX SFA interrupt */
  RESERVED212_IRQn             = 196,              /**< GIC700 Fault */
  RESERVED213_IRQn             = 197,              /**< GIC700 Error */
  RESERVED214_IRQn             = 198,              /**< GIC700 PMU Counter Overflow */
  ADC_ER_IRQn                  = 199,              /**< ADC interrupt */
  ADC_WD_IRQn                  = 200,              /**< ADC interrupt */
  ADC_EOC_IRQn                 = 201,              /**< ADC interrupt */
  RESERVED218_IRQn             = 202,              /**< s500 glue logic IRQ */
  I3C1_RAW_IRQ_GLUE_IRQn       = 203,              /**< I3C1 wakeup irq after double sync */
  I3C2_RAW_IRQ_GLUE_IRQn       = 204,              /**< I3C2 wakeup irq after double sync */
  MU5_A_IRQn                   = 205,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU6_A_IRQn                   = 206,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU7_B_IRQn                   = 207,              /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU8_B_IRQn                   = 208,              /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  XSPI_SLV_IRQn                = 209,              /**< WAKEUPMIX XSPI Responder */
  FCCU0_IRQn                   = 210,              /**< AONMIX FCCU Interrupt Reaction 0 */
  FCCU1_IRQn                   = 211,              /**< AONMIX FCCU Interrupt Reaction 1 */
  FCCU2_IRQn                   = 212,              /**< AONMIX FCCU Interrupt Reaction 2 */
  STCU_IRQn                    = 213,              /**< AONMIX STCU Selftest end Interrupt */
  DISP_IRQSTEER0_IRQn          = 214,              /**< DISPLAYMIX IRQSTEER 0: Common Control */
  DISP_IRQSTEER1_IRQn          = 215,              /**< DISPLAYMIX IRQSTEER 1: Display 0 Domain 0 */
  DISP_IRQSTEER2_IRQn          = 216,              /**< DISPLAYMIX IRQSTEER 2: Display 0 Domain 1 */
  DISP_IRQSTEER3_IRQn          = 217,              /**< DISPLAYMIX IRQSTEER 3: Display 1 Domain 0 */
  DISP_IRQSTEER4_IRQn          = 218,              /**< DISPLAYMIX IRQSTEER 4: Display 1 Domain 1 */
  DISP_IRQSTEER7_IRQn          = 219,              /**< DISPLAYMIX IRQSTEER 7: Blitter */
  MU_C1_IRQn                   = 220,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  ISI_0_IRQn                   = 221,              /**< CAMERAMIX ISI interrupt Channel 0 */
  ISP_IRQn                     = 222,              /**< ISP Processing Interrupt - Context 0 */
  M7MIX_IRQn                   = 223,              /**< M7MIX MCM interrupt */
  MU1_A_IRQn                   = 224,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU1_B_IRQn                   = 225,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU2_A_IRQn                   = 226,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU2_B_IRQn                   = 227,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU3_A_IRQn                   = 228,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU3_B_IRQn                   = 229,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU4_A_IRQn                   = 230,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU4_B_IRQn                   = 231,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU5_B_IRQn                   = 232,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU6_B_IRQn                   = 233,              /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
  MU7_A_IRQn                   = 234,              /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU8_A_IRQn                   = 235,              /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MSGINTR1_IRQn                = 236,              /**< MSGINTR Instance 1, Interrupt 1 */
  MSGINTR2_IRQn                = 237,              /**< MSGINTR Instance 2, Interrupt 1 */
  RESERVED254_IRQn             = 238,              /**< V2X-FH MU APCH1 (APP1) A_TX interrupt */
  RESERVED255_IRQn             = 239,              /**< V2X-FH MU APHSM2 (HSM2) A_TX interrupt */
  TRDC_MGR_C_IRQn              = 240,              /**< CAMERAMIX TRDC transfer error interrupt */
  TRDC_MGR_D_IRQn              = 241,              /**< DISPLAYMIX TRDC transfer error interrupt */
  TRDC_MGR_E_IRQn              = 242,              /**< NETCMIX TRDC transfer error interrupt */
  TRDC_MGR_G_IRQn              = 243,              /**< GPUMIX TRDC transfer error interrupt */
  TRDC_MGR_H_IRQn              = 244,              /**< HSIOMIX TRDC transfer error interrupt */
  TRDC_MGR_V_IRQn              = 245,              /**< VPUMIX TRDC transfer error interrupt */
  ERM_A_IRQn                   = 246,              /**< AONMIX ERM Single bit corrected ECC Error */
  RESERVED263_IRQn             = 247,              /**< M7MIX ERM Single bit corrected ECC Error */
  ERM_W_IRQn                   = 248,              /**< WAKEUPMIX ERM Single bit corrected ECC Error */
  ERM_ML_IRQn                  = 249,              /**< NPUMIX ERM Single bit corrected ECC Error */
  DMA5_3_ERROR_IRQn            = 250,              /**< WAKEUPMIX ACP EDMA error interrupt */
  OCRAM_C_IRQn                 = 251,              /**< OCRAM_C ECC multiple bit or address error */
  RESERVED268_IRQn             = 252,              /**< CAMERAMIX Cortex-M0+ Cache write-buffer error */
  RESERVED269_IRQn             = 253,              /**< CAMERAMIX Cortex-M0+ Cache data parity error */
  RESERVED270_IRQn             = 254,              /**< V2X-FH MU APSHE (SHE) A_TX interrupt */
  RESERVED271_IRQn             = 255,              /**< V2X-FH MU SCU/APDEBUG (DEBUG) B_TX interrupt */
  DMA5_3_0_1_IRQn              = 256,              /**< WAKEUPMIX ACP EDMA channel 0 interrupt */
  DMA5_3_2_3_IRQn              = 257,              /**< WAKEUPMIX ACP EDMA channel 2 interrupt */
  DMA5_3_4_5_IRQn              = 258,              /**< WAKEUPMIX ACP EDMA channel 4 interrupt */
  DMA5_3_6_7_IRQn              = 259,              /**< WAKEUPMIX ACP EDMA channel 6 interrupt */
  DMA5_3_8_9_IRQn              = 260,              /**< WAKEUPMIX ACP EDMA channel 8 interrupt */
  DMA5_3_10_11_IRQn            = 261,              /**< WAKEUPMIX ACP EDMA channel 10 interrupt */
  DMA5_3_12_13_IRQn            = 262,              /**< WAKEUPMIX ACP EDMA channel 12 interrupt */
  DMA5_3_14_15_IRQn            = 263,              /**< WAKEUPMIX ACP EDMA channel 14 interrupt */
  DMA5_3_16_17_IRQn            = 264,              /**< WAKEUPMIX ACP EDMA channel 16 interrupt */
  DMA5_3_18_19_IRQn            = 265,              /**< WAKEUPMIX ACP EDMA channel 18 interrupt */
  DMA5_3_20_21_IRQn            = 266,              /**< WAKEUPMIX ACP EDMA channel 20 interrupt */
  DMA5_3_22_23_IRQn            = 267,              /**< WAKEUPMIX ACP EDMA channel 22 interrupt */
  DMA5_3_24_25_IRQn            = 268,              /**< WAKEUPMIX ACP EDMA channel 24 interrupt */
  DMA5_3_26_27_IRQn            = 269,              /**< WAKEUPMIX ACP EDMA channel 26 interrupt */
  DMA5_3_28_29_IRQn            = 270,              /**< WAKEUPMIX ACP EDMA channel 28 interrupt */
  DMA5_3_30_31_IRQn            = 271,              /**< WAKEUPMIX ACP EDMA channel 30 interrupt */
  DMA5_3_32_33_IRQn            = 272,              /**<  WAKEUPMIX ACP EDMA channel 32 interrupt */
  DMA5_3_34_35_IRQn            = 273,              /**<  WAKEUPMIX ACP EDMA channel 34 interrupt */
  DMA5_3_36_37_IRQn            = 274,              /**<  WAKEUPMIX ACP EDMA channel 36 interrupt */
  DMA5_3_38_39_IRQn            = 275,              /**<  WAKEUPMIX ACP EDMA channel 38 interrupt */
  DMA5_3_40_41_IRQn            = 276,              /**<  WAKEUPMIX ACP EDMA channel 40 interrupt */
  DMA5_3_42_43_IRQn            = 277,              /**<  WAKEUPMIX ACP EDMA channel 42 interrupt */
  DMA5_3_44_45_IRQn            = 278,              /**<  WAKEUPMIX ACP EDMA channel 44 interrupt */
  DMA5_3_46_47_IRQn            = 279,              /**<  WAKEUPMIX ACP EDMA channel 46 interrupt */
  DMA5_3_48_49_IRQn            = 280,              /**<  WAKEUPMIX ACP EDMA channel 48 interrupt */
  DMA5_3_50_51_IRQn            = 281,              /**<  WAKEUPMIX ACP EDMA channel 50 interrupt */
  DMA5_3_52_53_IRQn            = 282,              /**<  WAKEUPMIX ACP EDMA channel 52 interrupt */
  DMA5_3_54_55_IRQn            = 283,              /**<  WAKEUPMIX ACP EDMA channel 54 interrupt */
  DMA5_3_56_57_IRQn            = 284,              /**<  WAKEUPMIX ACP EDMA channel 56 interrupt */
  DMA5_3_58_59_IRQn            = 285,              /**<  WAKEUPMIX ACP EDMA channel 58 interrupt */
  DMA5_3_60_61_IRQn            = 286,              /**<  WAKEUPMIX ACP EDMA channel 60 interrupt */
  DMA5_3_62_63_IRQn            = 287,              /**<  WAKEUPMIX ACP EDMA channel 62 interrupt */
  RESERVED304_IRQn             = 288,              /**< GPUMIX GPU Interrupt */
  RESERVED305_IRQn             = 289,              /**< GPUMIX Job Interrupt */
  RESERVED306_IRQn             = 290,              /**< GPUMIX MMU Interrupt */
  RESERVED307_IRQn             = 291,              /**< Reserved interrupt */
  RESERVED308_IRQn             = 292,              /**< Reserved interrupt */
  RESERVED309_IRQn             = 293,              /**< Reserved interrupt */
  RESERVED310_IRQn             = 294,              /**< Reserved interrupt */
  RESERVED311_IRQn             = 295,              /**< Reserved interrupt */
  RESERVED312_IRQn             = 296,              /**< Reserved interrupt */
  RESERVED313_IRQn             = 297,              /**< Reserved interrupt */
  RESERVED314_IRQn             = 298,              /**< Reserved interrupt */
  RESERVED315_IRQn             = 299,              /**< Reserved interrupt */
  RESERVED316_IRQn             = 300,              /**< Reserved interrupt */
  RESERVED317_IRQn             = 301,              /**< Reserved interrupt */
  RESERVED318_IRQn             = 302,              /**< Reserved interrupt */
  RESERVED319_IRQn             = 303,              /**< CODA980 VPU Encoder */
  RESERVED320_IRQn             = 304,              /**< NETC iEPRC PCI INT (one per each of two RC-EC) */
  RESERVED321_IRQn             = 305,              /**< NETC iEPRC PCI INT (one per each of two RC-EC) */
  RESERVED322_IRQn             = 306,              /**< PCIe Controller 1 INTA */
  RESERVED323_IRQn             = 307,              /**< PCIe Controller 1 INTB */
  RESERVED324_IRQn             = 308,              /**< PCIe Controller 1 INTC */
  RESERVED325_IRQn             = 309,              /**< PCIe Controller 1 INTD */
  RESERVED326_IRQn             = 310,              /**< PCIe miscellaneous interrupts */
  RESERVED327_IRQn             = 311,              /**< PCIe Controller EDMA channel interrupt */
  RESERVED328_IRQn             = 312,              /**< Reserved */
  RESERVED329_IRQn             = 313,              /**< Reserved */
  RESERVED330_IRQn             = 314,              /**< Reserved */
  RESERVED331_IRQn             = 315,              /**< Reserved */
  RESERVED332_IRQn             = 316,              /**< Reserved */
  RESERVED333_IRQn             = 317,              /**< Reserved */
  RESERVED334_IRQn             = 318,              /**< NPU Functional interrupt */
  RESERVED335_IRQn             = 319,              /**< NPU Fault interrupt */
  RESERVED336_IRQn             = 320,              /**< Reserved */
  RESERVED337_IRQn             = 321,              /**< Reserved */
  RESERVED338_IRQn             = 322,              /**< Reserved */
  RESERVED339_IRQn             = 323,              /**< Reserved */
  RESERVED340_IRQn             = 324,              /**< Reserved */
  RESERVED341_IRQn             = 325,              /**< Reserved */
  RESERVED342_IRQn             = 326,              /**< Reserved */
  RESERVED343_IRQn             = 327,              /**< Reserved */
  RESERVED344_IRQn             = 328,              /**< Reserved */
  RESERVED345_IRQn             = 329,              /**< Reserved */
  RESERVED346_IRQn             = 330,              /**< Reserved */
  RESERVED347_IRQn             = 331,              /**< Reserved */
  RESERVED348_IRQn             = 332,              /**< Reserved */
  RESERVED349_IRQn             = 333,              /**< Reserved */
  RESERVED350_IRQn             = 334,              /**< Reserved */
  LP_HDSK_GSKT_IRQn            = 335,              /**< SRC/GPC Low Power Handshake Gasket interrupt request for system management */
  MU_C2_IRQn                   = 336,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C3_IRQn                   = 337,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C4_IRQn                   = 338,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C5_IRQn                   = 339,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C6_IRQn                   = 340,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C7_IRQn                   = 341,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C8_IRQn                   = 342,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_C9_IRQn                   = 343,              /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  ISI_1_IRQn                   = 344,              /**< CAMERAMIX ISI interrupt Channel 1 */
  ISI_2_IRQn                   = 345,              /**< CAMERAMIX ISI interrupt Channel 2 */
  ISI_3_IRQn                   = 346,              /**< CAMERAMIX ISI interrupt Channel 3 */
  ISI_4_IRQn                   = 347,              /**< CAMERAMIX ISI interrupt Channel 4 */
  ISI_5_IRQn                   = 348,              /**< CAMERAMIX ISI interrupt Channel 5 */
  ISI_6_IRQn                   = 349,              /**< CAMERAMIX ISI interrupt Channel 6 */
  ISI_7_IRQn                   = 350,              /**< CAMERAMIX ISI interrupt Channel 7 */
  DMA5_4_ERROR_IRQn            = 351,              /**< CAMERAMIX EDMA error interrupt */
  DMA5_4_0_1_IRQn              = 352,              /**< CAMERAMIX EDMA channel 0 interrupt */
  DMA5_4_2_3_IRQn              = 353,              /**< CAMERAMIX EDMA channel 2 interrupt */
  DMA5_4_4_5_IRQn              = 354,              /**< CAMERAMIX EDMA channel 4 interrupt */
  DMA5_4_6_7_IRQn              = 355,              /**< CAMERAMIX EDMA channel 6 interrupt */
  DMA5_4_8_9_IRQn              = 356,              /**< CAMERAMIX EDMA channel 8 interrupt */
  DMA5_4_10_11_IRQn            = 357,              /**< CAMERAMIX EDMA channel 10 interrupt */
  DMA5_4_12_13_IRQn            = 358,              /**< CAMERAMIX EDMA channel 12 interrupt */
  DMA5_4_14_15_IRQn            = 359,              /**< CAMERAMIX EDMA channel 14 interrupt */
  DMA5_4_16_17_IRQn            = 360,              /**< CAMERAMIX EDMA channel 16 interrupt */
  DMA5_4_18_19_IRQn            = 361,              /**< CAMERAMIX EDMA channel 18 interrupt */
  DMA5_4_20_21_IRQn            = 362,              /**< CAMERAMIX EDMA channel 20 interrupt */
  DMA5_4_22_23_IRQn            = 363,              /**< CAMERAMIX EDMA channel 22 interrupt */
  DMA5_4_24_25_IRQn            = 364,              /**< CAMERAMIX EDMA channel 24 interrupt */
  DMA5_4_26_27_IRQn            = 365,              /**< CAMERAMIX EDMA channel 26 interrupt */
  DMA5_4_28_29_IRQn            = 366,              /**< CAMERAMIX EDMA channel 28 interrupt */
  DMA5_4_30_31_IRQn            = 367,              /**< CAMERAMIX EDMA channel 30 interrupt */
  RESERVED384_IRQn             = 368,              /**< CAMERAMIX CSI Formatting Unit 1: Buffer overflow */
  RESERVED385_IRQn             = 369,              /**< CAMERAMIX CSI Formatting Unit 1: Interlaced Error */
  RESERVED386_IRQn             = 370,              /**< CAMERAMIX CSI Formatting Unit 1: Pixel Data Type Error */
  RESERVED387_IRQn             = 371,              /**< CAMERAMIX CSI Formatting Unit 2: Buffer overflow */
  RESERVED388_IRQn             = 372,              /**< CAMERAMIX CSI Formatting Unit 2: Interlaced Error */
  RESERVED389_IRQn             = 373,              /**< CAMERAMIX CSI Formatting Unit 2: Pixel Data Type Error */
  CSI1_IRQn                    = 374,              /**< CAMERAMIX CSI1 (Standalone MIPI-CSI) interrupt */
  CSI2_IRQn                    = 375,              /**< CAMERAMIX CSI2 (Combo MIPI-CSI/DSI) interrupt */
  ASRC1_IRQn                   = 376,              /**< mirq_asrc1_b */
  RESERVED393_IRQn             = 377,              /**< Reserved interrupt */
  RESERVED394_IRQn             = 378,              /**< Reserved interrupt */
  RESERVED395_IRQn             = 379,              /**< Reserved interrupt */
  RESERVED396_IRQn             = 380,              /**< Reserved interrupt */
  RESERVED397_IRQn             = 381,              /**< Reserved interrupt */
  RESERVED398_IRQn             = 382,              /**< Reserved interrupt */
  RESERVED399_IRQn             = 383,              /**< Reserved */
  ASRC2_IRQn                   = 384,              /**< mirq_asrc2_b */
  RESERVED401_IRQn             = 385,              /**< Reserved interrupt */
  RESERVED402_IRQn             = 386,              /**< Reserved interrupt */
  RESERVED403_IRQn             = 387,              /**< Reserved interrupt */
  RESERVED404_IRQn             = 388,              /**< Reserved interrupt */
  RESERVED405_IRQn             = 389,              /**< Reserved interrupt */
  RESERVED406_IRQn             = 390,              /**< Reserved interrupt */
  NOC_VPU_IRQn                 = 391,              /**< Reserved interrupt */
  NOC_DISPLAY_IRQn             = 392,              /**< Reserved interrupt */
  NOC_CAMERA_IRQn              = 393,              /**< Reserved interrupt */
  NOC_HSIO_IRQn                = 394,              /**< Reserved interrupt */
  NOC_WAKEUP_IRQn              = 395,              /**< Reserved interrupt */
  NOC_CENTRAL_IRQn             = 396,              /**< Reserved interrupt */
  ERM_DISPLAY_IRQn             = 397,              /**< DISPLAYMIX ERM Single bit corrected ECC Error */
  RESERVED414_IRQn             = 398,              /**< Reserved */
  SAI6_IRQn                    = 399,              /**< WAKEUPMIX SAI TX interrupt */
  XSPI1_0_IRQn                 = 400,              /**< xspi1 all interrupts ORed output for EENV0 (MEENV) */
  XSPI1_1_IRQn                 = 401,              /**< xspi1 all interrupts ORed output for EENV1 (MEENV) */
  XSPI1_2_IRQn                 = 402,              /**< xspi1 all interrupts ORed output for EENV2 (MEENV) */
  XSPI1_3_IRQn                 = 403,              /**< xspi1 all interrupts ORed output for EENV3 (MEENV) */
  XSPI1_4_IRQn                 = 404,              /**< xspi1 all interrupts ORed output for EENV4 (MEENV) */
  RESERVED421_IRQn             = 405,              /**< Anamix Gllitch Detector output (da_ip_voltage_glitch_detector_cln16ffc). It's a latch signal. It can be cleared.  Positive polarity i.e interrupt is generated when 0-->1 */
  RESERVED422_IRQn             = 406,              /**< Anamix VDET output (da_ip_vdetect_c16ffc). Detects high threshold on Core supply. It's a latch signal. It can be cleared.  Positive polarity i.e interrupt is generated when 0-->1 */
  CCM_IRQn                     = 407,              /**< LPCG Timeout interrupt generated by CCGR (CCM) */
  MU_D1_IRQn                   = 408,              /**< DISPLAYMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  MU_D2_IRQn                   = 409,              /**< DISPLAYMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
  GPT2_IRQn                    = 410,              /**< WAKEUPMIX GPT2 interrupt */
  GPT3_IRQn                    = 411,              /**< WAKEUPMIX GPT2 interrupt */
  GPT4_IRQn                    = 412,              /**< WAKEUPMIX GPT2 interrupt */
  GPT5_IRQn                    = 413,              /**< WAKEUPMIX GPT2 interrupt */
  LPSPI9_IRQn                  = 414               /**< DISPLAYMIX LPSPI interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M33 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M33 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */
#define __DSP_PRESENT                  1         /**< Defines if Armv8-M Mainline core supports DSP instructions */
#define __SAUREGION_PRESENT            1         /**< Defines if an SAU is present or not */

#include "core_cm33.h"                 /* Core Peripheral Access Layer */
#include "system_MIMX9375_cm33.h"      /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


#ifndef MIMX9375_cm33_SERIES
#define MIMX9375_cm33_SERIES
#endif
/* CPU specific feature definitions */
#include "MIMX9375_cm33_features.h"

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup asrc_clock_source_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief The ASRC clock source
 */
typedef enum _asrc_clock_source
{
    kASRC_ClockSourceNotAvalible    = -1,          /**< not avalible */
    kASRC_ClockSourceBitClock0_AUD_PLL_DIV_CLK0 = 0U, /**< AUD PLL DIV CLK0 */
    kASRC_ClockSourceBitClock1_AUD_PLL_DIV_CLK1 = 1U, /**< AUD PLL DIV CLK1 */
    kASRC_ClockSourceBitClock2_MCLKOUT_0 = 2U,     /**< MCLKOUT 0 */
    kASRC_ClockSourceBitClock3_MCLKOUT_1 = 3U,     /**< MCLKOUT 1 */
    kASRC_ClockSourceBitClock4_SAI1_RX = 4U,       /**< SAI1 RX */
    kASRC_ClockSourceBitClock5_SAI1_TX = 5U,       /**< SAI1 TX */
    kASRC_ClockSourceBitClock6_SAI2_RX = 6U,       /**< SAI2 RX */
    kASRC_ClockSourceBitClock7_SAI2_TX = 7U,       /**< SAI2 TX */
    kASRC_ClockSourceBitClock8_SAI3_RX = 8U,       /**< SAI3 RX */
    kASRC_ClockSourceBitClock9_SAI3_TX = 9U,       /**< SAI3 TX */
    kASRC_ClockSourceBitClocka_SAI4_RX = 10U,      /**< SAI4 RX */
    kASRC_ClockSourceBitClockb_SAI4_TX = 11U,      /**< SAI4 TX */
    kASRC_ClockSourceBitClockc_SAI5_RX = 12U,      /**< SAI5 RX */
    kASRC_ClockSourceBitClockd_SAI5_TX = 13U,      /**< SAI5 TX */
    kASRC_ClockSourceMax            = 13U,         /**< max value */
} asrc_clock_source_t;

/* @} */


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ADC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ADC base address */
  #define ADC_BASE                                 (0x54530000u)
  /** Peripheral ADC base address */
  #define ADC_BASE_NS                              (0x44530000u)
  /** Peripheral ADC base pointer */
  #define ADC                                      ((ADC_Type *)ADC_BASE)
  /** Peripheral ADC base pointer */
  #define ADC_NS                                   ((ADC_Type *)ADC_BASE_NS)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC }
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS_NS                        { ADC_BASE_NS }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS_NS                         { ADC_NS }
#else
  /** Peripheral ADC base address */
  #define ADC_BASE                                 (0x44530000u)
  /** Peripheral ADC base pointer */
  #define ADC                                      ((ADC_Type *)ADC_BASE)
  /** Array initializer of ADC peripheral base addresses */
  #define ADC_BASE_ADDRS                           { ADC_BASE }
  /** Array initializer of ADC peripheral base pointers */
  #define ADC_BASE_PTRS                            { ADC }
#endif

/* AHBRM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__AHBRM1 base address */
  #define WAKEUP__AHBRM1_BASE                      (0x52400800u)
  /** Peripheral WAKEUP__AHBRM1 base address */
  #define WAKEUP__AHBRM1_BASE_NS                   (0x42400800u)
  /** Peripheral WAKEUP__AHBRM1 base pointer */
  #define WAKEUP__AHBRM1                           ((AHBRM_Type *)WAKEUP__AHBRM1_BASE)
  /** Peripheral WAKEUP__AHBRM1 base pointer */
  #define WAKEUP__AHBRM1_NS                        ((AHBRM_Type *)WAKEUP__AHBRM1_BASE_NS)
  /** Array initializer of AHBRM peripheral base addresses */
  #define AHBRM_BASE_ADDRS                         { WAKEUP__AHBRM1_BASE }
  /** Array initializer of AHBRM peripheral base pointers */
  #define AHBRM_BASE_PTRS                          { WAKEUP__AHBRM1 }
  /** Array initializer of AHBRM peripheral base addresses */
  #define AHBRM_BASE_ADDRS_NS                      { WAKEUP__AHBRM1_BASE_NS }
  /** Array initializer of AHBRM peripheral base pointers */
  #define AHBRM_BASE_PTRS_NS                       { WAKEUP__AHBRM1_NS }
#else
  /** Peripheral WAKEUP__AHBRM1 base address */
  #define WAKEUP__AHBRM1_BASE                      (0x42400800u)
  /** Peripheral WAKEUP__AHBRM1 base pointer */
  #define WAKEUP__AHBRM1                           ((AHBRM_Type *)WAKEUP__AHBRM1_BASE)
  /** Array initializer of AHBRM peripheral base addresses */
  #define AHBRM_BASE_ADDRS                         { WAKEUP__AHBRM1_BASE }
  /** Array initializer of AHBRM peripheral base pointers */
  #define AHBRM_BASE_PTRS                          { WAKEUP__AHBRM1 }
#endif

/* AON_CMU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__CMUA2 base address */
  #define AON__CMUA2_BASE                          (0x54650000u)
  /** Peripheral AON__CMUA2 base address */
  #define AON__CMUA2_BASE_NS                       (0x44650000u)
  /** Peripheral AON__CMUA2 base pointer */
  #define AON__CMUA2                               ((AON_CMU_Type *)AON__CMUA2_BASE)
  /** Peripheral AON__CMUA2 base pointer */
  #define AON__CMUA2_NS                            ((AON_CMU_Type *)AON__CMUA2_BASE_NS)
  /** Array initializer of AON_CMU peripheral base addresses */
  #define AON_CMU_BASE_ADDRS                       { AON__CMUA2_BASE }
  /** Array initializer of AON_CMU peripheral base pointers */
  #define AON_CMU_BASE_PTRS                        { AON__CMUA2 }
  /** Array initializer of AON_CMU peripheral base addresses */
  #define AON_CMU_BASE_ADDRS_NS                    { AON__CMUA2_BASE_NS }
  /** Array initializer of AON_CMU peripheral base pointers */
  #define AON_CMU_BASE_PTRS_NS                     { AON__CMUA2_NS }
#else
  /** Peripheral AON__CMUA2 base address */
  #define AON__CMUA2_BASE                          (0x44650000u)
  /** Peripheral AON__CMUA2 base pointer */
  #define AON__CMUA2                               ((AON_CMU_Type *)AON__CMUA2_BASE)
  /** Array initializer of AON_CMU peripheral base addresses */
  #define AON_CMU_BASE_ADDRS                       { AON__CMUA2_BASE }
  /** Array initializer of AON_CMU peripheral base pointers */
  #define AON_CMU_BASE_PTRS                        { AON__CMUA2 }
#endif

/* ARDB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__XSPI1__ARDB base address */
  #define WAKEUP__XSPI1__ARDB_BASE                 (0x57420000u)
  /** Peripheral WAKEUP__XSPI1__ARDB base address */
  #define WAKEUP__XSPI1__ARDB_BASE_NS              (0x47420000u)
  /** Peripheral WAKEUP__XSPI1__ARDB base pointer */
  #define WAKEUP__XSPI1__ARDB                      ((ARDB_Type *)WAKEUP__XSPI1__ARDB_BASE)
  /** Peripheral WAKEUP__XSPI1__ARDB base pointer */
  #define WAKEUP__XSPI1__ARDB_NS                   ((ARDB_Type *)WAKEUP__XSPI1__ARDB_BASE_NS)
  /** Array initializer of ARDB peripheral base addresses */
  #define ARDB_BASE_ADDRS                          { WAKEUP__XSPI1__ARDB_BASE }
  /** Array initializer of ARDB peripheral base pointers */
  #define ARDB_BASE_PTRS                           { WAKEUP__XSPI1__ARDB }
  /** Array initializer of ARDB peripheral base addresses */
  #define ARDB_BASE_ADDRS_NS                       { WAKEUP__XSPI1__ARDB_BASE_NS }
  /** Array initializer of ARDB peripheral base pointers */
  #define ARDB_BASE_PTRS_NS                        { WAKEUP__XSPI1__ARDB_NS }
#else
  /** Peripheral WAKEUP__XSPI1__ARDB base address */
  #define WAKEUP__XSPI1__ARDB_BASE                 (0x47420000u)
  /** Peripheral WAKEUP__XSPI1__ARDB base pointer */
  #define WAKEUP__XSPI1__ARDB                      ((ARDB_Type *)WAKEUP__XSPI1__ARDB_BASE)
  /** Array initializer of ARDB peripheral base addresses */
  #define ARDB_BASE_ADDRS                          { WAKEUP__XSPI1__ARDB_BASE }
  /** Array initializer of ARDB peripheral base pointers */
  #define ARDB_BASE_PTRS                           { WAKEUP__XSPI1__ARDB }
#endif

/* ASRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ASRC1 base address */
  #define ASRC1_BASE                               (0x53000000u)
  /** Peripheral ASRC1 base address */
  #define ASRC1_BASE_NS                            (0x43000000u)
  /** Peripheral ASRC1 base pointer */
  #define ASRC1                                    ((ASRC_Type *)ASRC1_BASE)
  /** Peripheral ASRC1 base pointer */
  #define ASRC1_NS                                 ((ASRC_Type *)ASRC1_BASE_NS)
  /** Peripheral ASRC2 base address */
  #define ASRC2_BASE                               (0x530F0000u)
  /** Peripheral ASRC2 base address */
  #define ASRC2_BASE_NS                            (0x430F0000u)
  /** Peripheral ASRC2 base pointer */
  #define ASRC2                                    ((ASRC_Type *)ASRC2_BASE)
  /** Peripheral ASRC2 base pointer */
  #define ASRC2_NS                                 ((ASRC_Type *)ASRC2_BASE_NS)
  /** Array initializer of ASRC peripheral base addresses */
  #define ASRC_BASE_ADDRS                          { ASRC1_BASE, ASRC2_BASE }
  /** Array initializer of ASRC peripheral base pointers */
  #define ASRC_BASE_PTRS                           { ASRC1, ASRC2 }
  /** Array initializer of ASRC peripheral base addresses */
  #define ASRC_BASE_ADDRS_NS                       { ASRC1_BASE_NS, ASRC2_BASE_NS }
  /** Array initializer of ASRC peripheral base pointers */
  #define ASRC_BASE_PTRS_NS                        { ASRC1_NS, ASRC2_NS }
#else
  /** Peripheral ASRC1 base address */
  #define ASRC1_BASE                               (0x43000000u)
  /** Peripheral ASRC1 base pointer */
  #define ASRC1                                    ((ASRC_Type *)ASRC1_BASE)
  /** Peripheral ASRC2 base address */
  #define ASRC2_BASE                               (0x430F0000u)
  /** Peripheral ASRC2 base pointer */
  #define ASRC2                                    ((ASRC_Type *)ASRC2_BASE)
  /** Array initializer of ASRC peripheral base addresses */
  #define ASRC_BASE_ADDRS                          { ASRC1_BASE, ASRC2_BASE }
  /** Array initializer of ASRC peripheral base pointers */
  #define ASRC_BASE_PTRS                           { ASRC1, ASRC2 }
#endif
/** Interrupt vectors for the ASRC peripheral type */
#define ASRC_IRQS                                { ASRC1_IRQn, ASRC2_IRQn }

/* ATU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__ATU base address */
  #define HSIO__ATU_BASE                           (0x5C070000u)
  /** Peripheral HSIO__ATU base address */
  #define HSIO__ATU_BASE_NS                        (0x4C070000u)
  /** Peripheral HSIO__ATU base pointer */
  #define HSIO__ATU                                ((ATU_Type *)HSIO__ATU_BASE)
  /** Peripheral HSIO__ATU base pointer */
  #define HSIO__ATU_NS                             ((ATU_Type *)HSIO__ATU_BASE_NS)
  /** Peripheral NOC__ATU0 base address */
  #define NOC__ATU0_BASE                           (0x590C0000u)
  /** Peripheral NOC__ATU0 base address */
  #define NOC__ATU0_BASE_NS                        (0x490C0000u)
  /** Peripheral NOC__ATU0 base pointer */
  #define NOC__ATU0                                ((ATU_Type *)NOC__ATU0_BASE)
  /** Peripheral NOC__ATU0 base pointer */
  #define NOC__ATU0_NS                             ((ATU_Type *)NOC__ATU0_BASE_NS)
  /** Peripheral NOC__ATU1 base address */
  #define NOC__ATU1_BASE                           (0x590C0000u)
  /** Peripheral NOC__ATU1 base address */
  #define NOC__ATU1_BASE_NS                        (0x490C0000u)
  /** Peripheral NOC__ATU1 base pointer */
  #define NOC__ATU1                                ((ATU_Type *)NOC__ATU1_BASE)
  /** Peripheral NOC__ATU1 base pointer */
  #define NOC__ATU1_NS                             ((ATU_Type *)NOC__ATU1_BASE_NS)
  /** Peripheral VPU__ATU_CODA_PRIM base address */
  #define VPU__ATU_CODA_PRIM_BASE                  (0x5C610000u)
  /** Peripheral VPU__ATU_CODA_PRIM base address */
  #define VPU__ATU_CODA_PRIM_BASE_NS               (0x4C610000u)
  /** Peripheral VPU__ATU_CODA_PRIM base pointer */
  #define VPU__ATU_CODA_PRIM                       ((ATU_Type *)VPU__ATU_CODA_PRIM_BASE)
  /** Peripheral VPU__ATU_CODA_PRIM base pointer */
  #define VPU__ATU_CODA_PRIM_NS                    ((ATU_Type *)VPU__ATU_CODA_PRIM_BASE_NS)
  /** Peripheral VPU__ATU_CODA_SEC base address */
  #define VPU__ATU_CODA_SEC_BASE                   (0x5C620000u)
  /** Peripheral VPU__ATU_CODA_SEC base address */
  #define VPU__ATU_CODA_SEC_BASE_NS                (0x4C620000u)
  /** Peripheral VPU__ATU_CODA_SEC base pointer */
  #define VPU__ATU_CODA_SEC                        ((ATU_Type *)VPU__ATU_CODA_SEC_BASE)
  /** Peripheral VPU__ATU_CODA_SEC base pointer */
  #define VPU__ATU_CODA_SEC_NS                     ((ATU_Type *)VPU__ATU_CODA_SEC_BASE_NS)
  /** Peripheral VPU__ATU_JPEG_DEC base address */
  #define VPU__ATU_JPEG_DEC_BASE                   (0x5C640000u)
  /** Peripheral VPU__ATU_JPEG_DEC base address */
  #define VPU__ATU_JPEG_DEC_BASE_NS                (0x4C640000u)
  /** Peripheral VPU__ATU_JPEG_DEC base pointer */
  #define VPU__ATU_JPEG_DEC                        ((ATU_Type *)VPU__ATU_JPEG_DEC_BASE)
  /** Peripheral VPU__ATU_JPEG_DEC base pointer */
  #define VPU__ATU_JPEG_DEC_NS                     ((ATU_Type *)VPU__ATU_JPEG_DEC_BASE_NS)
  /** Peripheral VPU__ATU_JPEG_ENC base address */
  #define VPU__ATU_JPEG_ENC_BASE                   (0x5C630000u)
  /** Peripheral VPU__ATU_JPEG_ENC base address */
  #define VPU__ATU_JPEG_ENC_BASE_NS                (0x4C630000u)
  /** Peripheral VPU__ATU_JPEG_ENC base pointer */
  #define VPU__ATU_JPEG_ENC                        ((ATU_Type *)VPU__ATU_JPEG_ENC_BASE)
  /** Peripheral VPU__ATU_JPEG_ENC base pointer */
  #define VPU__ATU_JPEG_ENC_NS                     ((ATU_Type *)VPU__ATU_JPEG_ENC_BASE_NS)
  /** Peripheral WAKEUP__ATUA base address */
  #define WAKEUP__ATUA_BASE                        (0x52C70000u)
  /** Peripheral WAKEUP__ATUA base address */
  #define WAKEUP__ATUA_BASE_NS                     (0x42C70000u)
  /** Peripheral WAKEUP__ATUA base pointer */
  #define WAKEUP__ATUA                             ((ATU_Type *)WAKEUP__ATUA_BASE)
  /** Peripheral WAKEUP__ATUA base pointer */
  #define WAKEUP__ATUA_NS                          ((ATU_Type *)WAKEUP__ATUA_BASE_NS)
  /** Peripheral WAKEUP__ATUAHBAP base address */
  #define WAKEUP__ATUAHBAP_BASE                    (0x52CD0000u)
  /** Peripheral WAKEUP__ATUAHBAP base address */
  #define WAKEUP__ATUAHBAP_BASE_NS                 (0x42CD0000u)
  /** Peripheral WAKEUP__ATUAHBAP base pointer */
  #define WAKEUP__ATUAHBAP                         ((ATU_Type *)WAKEUP__ATUAHBAP_BASE)
  /** Peripheral WAKEUP__ATUAHBAP base pointer */
  #define WAKEUP__ATUAHBAP_NS                      ((ATU_Type *)WAKEUP__ATUAHBAP_BASE_NS)
  /** Peripheral WAKEUP__ATUA_LOCK base address */
  #define WAKEUP__ATUA_LOCK_BASE                   (0x52C70000u)
  /** Peripheral WAKEUP__ATUA_LOCK base address */
  #define WAKEUP__ATUA_LOCK_BASE_NS                (0x42C70000u)
  /** Peripheral WAKEUP__ATUA_LOCK base pointer */
  #define WAKEUP__ATUA_LOCK                        ((ATU_Type *)WAKEUP__ATUA_LOCK_BASE)
  /** Peripheral WAKEUP__ATUA_LOCK base pointer */
  #define WAKEUP__ATUA_LOCK_NS                     ((ATU_Type *)WAKEUP__ATUA_LOCK_BASE_NS)
  /** Peripheral WAKEUP__ATUSDHC1 base address */
  #define WAKEUP__ATUSDHC1_BASE                    (0x52C90000u)
  /** Peripheral WAKEUP__ATUSDHC1 base address */
  #define WAKEUP__ATUSDHC1_BASE_NS                 (0x42C90000u)
  /** Peripheral WAKEUP__ATUSDHC1 base pointer */
  #define WAKEUP__ATUSDHC1                         ((ATU_Type *)WAKEUP__ATUSDHC1_BASE)
  /** Peripheral WAKEUP__ATUSDHC1 base pointer */
  #define WAKEUP__ATUSDHC1_NS                      ((ATU_Type *)WAKEUP__ATUSDHC1_BASE_NS)
  /** Peripheral WAKEUP__ATUSDHC2 base address */
  #define WAKEUP__ATUSDHC2_BASE                    (0x52CA0000u)
  /** Peripheral WAKEUP__ATUSDHC2 base address */
  #define WAKEUP__ATUSDHC2_BASE_NS                 (0x42CA0000u)
  /** Peripheral WAKEUP__ATUSDHC2 base pointer */
  #define WAKEUP__ATUSDHC2                         ((ATU_Type *)WAKEUP__ATUSDHC2_BASE)
  /** Peripheral WAKEUP__ATUSDHC2 base pointer */
  #define WAKEUP__ATUSDHC2_NS                      ((ATU_Type *)WAKEUP__ATUSDHC2_BASE_NS)
  /** Peripheral WAKEUP__ATUSDHC3 base address */
  #define WAKEUP__ATUSDHC3_BASE                    (0x52CB0000u)
  /** Peripheral WAKEUP__ATUSDHC3 base address */
  #define WAKEUP__ATUSDHC3_BASE_NS                 (0x42CB0000u)
  /** Peripheral WAKEUP__ATUSDHC3 base pointer */
  #define WAKEUP__ATUSDHC3                         ((ATU_Type *)WAKEUP__ATUSDHC3_BASE)
  /** Peripheral WAKEUP__ATUSDHC3 base pointer */
  #define WAKEUP__ATUSDHC3_NS                      ((ATU_Type *)WAKEUP__ATUSDHC3_BASE_NS)
  /** Peripheral WAKEUP__ATUV2X base address */
  #define WAKEUP__ATUV2X_BASE                      (0x52C80000u)
  /** Peripheral WAKEUP__ATUV2X base address */
  #define WAKEUP__ATUV2X_BASE_NS                   (0x42C80000u)
  /** Peripheral WAKEUP__ATUV2X base pointer */
  #define WAKEUP__ATUV2X                           ((ATU_Type *)WAKEUP__ATUV2X_BASE)
  /** Peripheral WAKEUP__ATUV2X base pointer */
  #define WAKEUP__ATUV2X_NS                        ((ATU_Type *)WAKEUP__ATUV2X_BASE_NS)
  /** Peripheral WAKEUP__ATUXSPI base address */
  #define WAKEUP__ATUXSPI_BASE                     (0x52CC0000u)
  /** Peripheral WAKEUP__ATUXSPI base address */
  #define WAKEUP__ATUXSPI_BASE_NS                  (0x42CC0000u)
  /** Peripheral WAKEUP__ATUXSPI base pointer */
  #define WAKEUP__ATUXSPI                          ((ATU_Type *)WAKEUP__ATUXSPI_BASE)
  /** Peripheral WAKEUP__ATUXSPI base pointer */
  #define WAKEUP__ATUXSPI_NS                       ((ATU_Type *)WAKEUP__ATUXSPI_BASE_NS)
  /** Array initializer of ATU peripheral base addresses */
  #define ATU_BASE_ADDRS                           { HSIO__ATU_BASE, NOC__ATU0_BASE, NOC__ATU1_BASE, VPU__ATU_CODA_PRIM_BASE, VPU__ATU_CODA_SEC_BASE, VPU__ATU_JPEG_DEC_BASE, VPU__ATU_JPEG_ENC_BASE, WAKEUP__ATUA_BASE, WAKEUP__ATUAHBAP_BASE, WAKEUP__ATUA_LOCK_BASE, WAKEUP__ATUSDHC1_BASE, WAKEUP__ATUSDHC2_BASE, WAKEUP__ATUSDHC3_BASE, WAKEUP__ATUV2X_BASE, WAKEUP__ATUXSPI_BASE }
  /** Array initializer of ATU peripheral base pointers */
  #define ATU_BASE_PTRS                            { HSIO__ATU, NOC__ATU0, NOC__ATU1, VPU__ATU_CODA_PRIM, VPU__ATU_CODA_SEC, VPU__ATU_JPEG_DEC, VPU__ATU_JPEG_ENC, WAKEUP__ATUA, WAKEUP__ATUAHBAP, WAKEUP__ATUA_LOCK, WAKEUP__ATUSDHC1, WAKEUP__ATUSDHC2, WAKEUP__ATUSDHC3, WAKEUP__ATUV2X, WAKEUP__ATUXSPI }
  /** Array initializer of ATU peripheral base addresses */
  #define ATU_BASE_ADDRS_NS                        { HSIO__ATU_BASE_NS, NOC__ATU0_BASE_NS, NOC__ATU1_BASE_NS, VPU__ATU_CODA_PRIM_BASE_NS, VPU__ATU_CODA_SEC_BASE_NS, VPU__ATU_JPEG_DEC_BASE_NS, VPU__ATU_JPEG_ENC_BASE_NS, WAKEUP__ATUA_BASE_NS, WAKEUP__ATUAHBAP_BASE_NS, WAKEUP__ATUA_LOCK_BASE_NS, WAKEUP__ATUSDHC1_BASE_NS, WAKEUP__ATUSDHC2_BASE_NS, WAKEUP__ATUSDHC3_BASE_NS, WAKEUP__ATUV2X_BASE_NS, WAKEUP__ATUXSPI_BASE_NS }
  /** Array initializer of ATU peripheral base pointers */
  #define ATU_BASE_PTRS_NS                         { HSIO__ATU_NS, NOC__ATU0_NS, NOC__ATU1_NS, VPU__ATU_CODA_PRIM_NS, VPU__ATU_CODA_SEC_NS, VPU__ATU_JPEG_DEC_NS, VPU__ATU_JPEG_ENC_NS, WAKEUP__ATUA_NS, WAKEUP__ATUAHBAP_NS, WAKEUP__ATUA_LOCK_NS, WAKEUP__ATUSDHC1_NS, WAKEUP__ATUSDHC2_NS, WAKEUP__ATUSDHC3_NS, WAKEUP__ATUV2X_NS, WAKEUP__ATUXSPI_NS }
#else
  /** Peripheral HSIO__ATU base address */
  #define HSIO__ATU_BASE                           (0x4C070000u)
  /** Peripheral HSIO__ATU base pointer */
  #define HSIO__ATU                                ((ATU_Type *)HSIO__ATU_BASE)
  /** Peripheral NOC__ATU0 base address */
  #define NOC__ATU0_BASE                           (0x490C0000u)
  /** Peripheral NOC__ATU0 base pointer */
  #define NOC__ATU0                                ((ATU_Type *)NOC__ATU0_BASE)
  /** Peripheral NOC__ATU1 base address */
  #define NOC__ATU1_BASE                           (0x490C0000u)
  /** Peripheral NOC__ATU1 base pointer */
  #define NOC__ATU1                                ((ATU_Type *)NOC__ATU1_BASE)
  /** Peripheral VPU__ATU_CODA_PRIM base address */
  #define VPU__ATU_CODA_PRIM_BASE                  (0x4C610000u)
  /** Peripheral VPU__ATU_CODA_PRIM base pointer */
  #define VPU__ATU_CODA_PRIM                       ((ATU_Type *)VPU__ATU_CODA_PRIM_BASE)
  /** Peripheral VPU__ATU_CODA_SEC base address */
  #define VPU__ATU_CODA_SEC_BASE                   (0x4C620000u)
  /** Peripheral VPU__ATU_CODA_SEC base pointer */
  #define VPU__ATU_CODA_SEC                        ((ATU_Type *)VPU__ATU_CODA_SEC_BASE)
  /** Peripheral VPU__ATU_JPEG_DEC base address */
  #define VPU__ATU_JPEG_DEC_BASE                   (0x4C640000u)
  /** Peripheral VPU__ATU_JPEG_DEC base pointer */
  #define VPU__ATU_JPEG_DEC                        ((ATU_Type *)VPU__ATU_JPEG_DEC_BASE)
  /** Peripheral VPU__ATU_JPEG_ENC base address */
  #define VPU__ATU_JPEG_ENC_BASE                   (0x4C630000u)
  /** Peripheral VPU__ATU_JPEG_ENC base pointer */
  #define VPU__ATU_JPEG_ENC                        ((ATU_Type *)VPU__ATU_JPEG_ENC_BASE)
  /** Peripheral WAKEUP__ATUA base address */
  #define WAKEUP__ATUA_BASE                        (0x42C70000u)
  /** Peripheral WAKEUP__ATUA base pointer */
  #define WAKEUP__ATUA                             ((ATU_Type *)WAKEUP__ATUA_BASE)
  /** Peripheral WAKEUP__ATUAHBAP base address */
  #define WAKEUP__ATUAHBAP_BASE                    (0x42CD0000u)
  /** Peripheral WAKEUP__ATUAHBAP base pointer */
  #define WAKEUP__ATUAHBAP                         ((ATU_Type *)WAKEUP__ATUAHBAP_BASE)
  /** Peripheral WAKEUP__ATUA_LOCK base address */
  #define WAKEUP__ATUA_LOCK_BASE                   (0x42C70000u)
  /** Peripheral WAKEUP__ATUA_LOCK base pointer */
  #define WAKEUP__ATUA_LOCK                        ((ATU_Type *)WAKEUP__ATUA_LOCK_BASE)
  /** Peripheral WAKEUP__ATUSDHC1 base address */
  #define WAKEUP__ATUSDHC1_BASE                    (0x42C90000u)
  /** Peripheral WAKEUP__ATUSDHC1 base pointer */
  #define WAKEUP__ATUSDHC1                         ((ATU_Type *)WAKEUP__ATUSDHC1_BASE)
  /** Peripheral WAKEUP__ATUSDHC2 base address */
  #define WAKEUP__ATUSDHC2_BASE                    (0x42CA0000u)
  /** Peripheral WAKEUP__ATUSDHC2 base pointer */
  #define WAKEUP__ATUSDHC2                         ((ATU_Type *)WAKEUP__ATUSDHC2_BASE)
  /** Peripheral WAKEUP__ATUSDHC3 base address */
  #define WAKEUP__ATUSDHC3_BASE                    (0x42CB0000u)
  /** Peripheral WAKEUP__ATUSDHC3 base pointer */
  #define WAKEUP__ATUSDHC3                         ((ATU_Type *)WAKEUP__ATUSDHC3_BASE)
  /** Peripheral WAKEUP__ATUV2X base address */
  #define WAKEUP__ATUV2X_BASE                      (0x42C80000u)
  /** Peripheral WAKEUP__ATUV2X base pointer */
  #define WAKEUP__ATUV2X                           ((ATU_Type *)WAKEUP__ATUV2X_BASE)
  /** Peripheral WAKEUP__ATUXSPI base address */
  #define WAKEUP__ATUXSPI_BASE                     (0x42CC0000u)
  /** Peripheral WAKEUP__ATUXSPI base pointer */
  #define WAKEUP__ATUXSPI                          ((ATU_Type *)WAKEUP__ATUXSPI_BASE)
  /** Array initializer of ATU peripheral base addresses */
  #define ATU_BASE_ADDRS                           { HSIO__ATU_BASE, NOC__ATU0_BASE, NOC__ATU1_BASE, VPU__ATU_CODA_PRIM_BASE, VPU__ATU_CODA_SEC_BASE, VPU__ATU_JPEG_DEC_BASE, VPU__ATU_JPEG_ENC_BASE, WAKEUP__ATUA_BASE, WAKEUP__ATUAHBAP_BASE, WAKEUP__ATUA_LOCK_BASE, WAKEUP__ATUSDHC1_BASE, WAKEUP__ATUSDHC2_BASE, WAKEUP__ATUSDHC3_BASE, WAKEUP__ATUV2X_BASE, WAKEUP__ATUXSPI_BASE }
  /** Array initializer of ATU peripheral base pointers */
  #define ATU_BASE_PTRS                            { HSIO__ATU, NOC__ATU0, NOC__ATU1, VPU__ATU_CODA_PRIM, VPU__ATU_CODA_SEC, VPU__ATU_JPEG_DEC, VPU__ATU_JPEG_ENC, WAKEUP__ATUA, WAKEUP__ATUAHBAP, WAKEUP__ATUA_LOCK, WAKEUP__ATUSDHC1, WAKEUP__ATUSDHC2, WAKEUP__ATUSDHC3, WAKEUP__ATUV2X, WAKEUP__ATUXSPI }
#endif

/* AUDMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__AUDMIX1 base address */
  #define WAKEUP__AUDMIX1_BASE                     (0x531F0000u)
  /** Peripheral WAKEUP__AUDMIX1 base address */
  #define WAKEUP__AUDMIX1_BASE_NS                  (0x431F0000u)
  /** Peripheral WAKEUP__AUDMIX1 base pointer */
  #define WAKEUP__AUDMIX1                          ((AUDMIX_Type *)WAKEUP__AUDMIX1_BASE)
  /** Peripheral WAKEUP__AUDMIX1 base pointer */
  #define WAKEUP__AUDMIX1_NS                       ((AUDMIX_Type *)WAKEUP__AUDMIX1_BASE_NS)
  /** Array initializer of AUDMIX peripheral base addresses */
  #define AUDMIX_BASE_ADDRS                        { WAKEUP__AUDMIX1_BASE }
  /** Array initializer of AUDMIX peripheral base pointers */
  #define AUDMIX_BASE_PTRS                         { WAKEUP__AUDMIX1 }
  /** Array initializer of AUDMIX peripheral base addresses */
  #define AUDMIX_BASE_ADDRS_NS                     { WAKEUP__AUDMIX1_BASE_NS }
  /** Array initializer of AUDMIX peripheral base pointers */
  #define AUDMIX_BASE_PTRS_NS                      { WAKEUP__AUDMIX1_NS }
#else
  /** Peripheral WAKEUP__AUDMIX1 base address */
  #define WAKEUP__AUDMIX1_BASE                     (0x431F0000u)
  /** Peripheral WAKEUP__AUDMIX1 base pointer */
  #define WAKEUP__AUDMIX1                          ((AUDMIX_Type *)WAKEUP__AUDMIX1_BASE)
  /** Array initializer of AUDMIX peripheral base addresses */
  #define AUDMIX_BASE_ADDRS                        { WAKEUP__AUDMIX1_BASE }
  /** Array initializer of AUDMIX peripheral base pointers */
  #define AUDMIX_BASE_PTRS                         { WAKEUP__AUDMIX1 }
#endif

/* BBNSM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE                               (0x54440000u)
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE_NS                            (0x44440000u)
  /** Peripheral BBNSM base pointer */
  #define BBNSM                                    ((BBNSM_Type *)BBNSM_BASE)
  /** Peripheral BBNSM base pointer */
  #define BBNSM_NS                                 ((BBNSM_Type *)BBNSM_BASE_NS)
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS                         { BBNSM_BASE }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS                          { BBNSM }
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS_NS                      { BBNSM_BASE_NS }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS_NS                       { BBNSM_NS }
#else
  /** Peripheral BBNSM base address */
  #define BBNSM_BASE                               (0x44440000u)
  /** Peripheral BBNSM base pointer */
  #define BBNSM                                    ((BBNSM_Type *)BBNSM_BASE)
  /** Array initializer of BBNSM peripheral base addresses */
  #define BBNSM_BASE_ADDRS                         { BBNSM_BASE }
  /** Array initializer of BBNSM peripheral base pointers */
  #define BBNSM_BASE_PTRS                          { BBNSM }
#endif

/* BBSM_BLK_CTRL_BBSMMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_BBSMMIX base address */
  #define BLK_CTRL_BBSMMIX_BASE     (0x54410000u)
  /** Peripheral BLK_CTRL_BBSMMIX base address */
  #define BLK_CTRL_BBSMMIX_BASE_NS  (0x44410000u)
  /** Peripheral BLK_CTRL_BBSMMIX base pointer */
  #define BLK_CTRL_BBSMMIX          ((BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BASE)
  /** Peripheral BLK_CTRL_BBSMMIX base pointer */
  #define BLK_CTRL_BBSMMIX_NS       ((BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base addresses */
  #define BLK_CTRL_BBSMMIX_BASE_ADDRS         { BLK_CTRL_BBSMMIX_BASE }
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base pointers */
  #define BLK_CTRL_BBSMMIX_BASE_PTRS          { BLK_CTRL_BBSMMIX }
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base addresses */
  #define BLK_CTRL_BBSMMIX_BASE_ADDRS_NS      { BLK_CTRL_BBSMMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base pointers */
  #define BLK_CTRL_BBSMMIX_BASE_PTRS_NS       { BLK_CTRL_BBSMMIX_NS }
#else
  /** Peripheral BLK_CTRL_BBSMMIX base address */
  #define BLK_CTRL_BBSMMIX_BASE     (0x44410000u)
  /** Peripheral BLK_CTRL_BBSMMIX base pointer */
  #define BLK_CTRL_BBSMMIX          ((BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BASE)
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base addresses */
  #define BLK_CTRL_BBSMMIX_BASE_ADDRS         { BLK_CTRL_BBSMMIX_BASE }
  /** Array initializer of BLK_CTRL_BBSMMIX peripheral base pointers */
  #define BLK_CTRL_BBSMMIX_BASE_PTRS          { BLK_CTRL_BBSMMIX }
#endif

/* BLK_CTRL_CAMERAMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_CAMERAMIX base address */
  #define BLK_CTRL_CAMERAMIX_BASE                  (0x5AC10000u)
  /** Peripheral BLK_CTRL_CAMERAMIX base address */
  #define BLK_CTRL_CAMERAMIX_BASE_NS               (0x4AC10000u)
  /** Peripheral BLK_CTRL_CAMERAMIX base pointer */
  #define BLK_CTRL_CAMERAMIX                       ((BLK_CTRL_CAMERAMIX_Type *)BLK_CTRL_CAMERAMIX_BASE)
  /** Peripheral BLK_CTRL_CAMERAMIX base pointer */
  #define BLK_CTRL_CAMERAMIX_NS                    ((BLK_CTRL_CAMERAMIX_Type *)BLK_CTRL_CAMERAMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_CAMERAMIX peripheral base addresses */
  #define BLK_CTRL_CAMERAMIX_BASE_ADDRS            { BLK_CTRL_CAMERAMIX_BASE }
  /** Array initializer of BLK_CTRL_CAMERAMIX peripheral base pointers */
  #define BLK_CTRL_CAMERAMIX_BASE_PTRS             { BLK_CTRL_CAMERAMIX }
  /** Array initializer of BLK_CTRL_CAMERAMIX peripheral base addresses */
  #define BLK_CTRL_CAMERAMIX_BASE_ADDRS_NS         { BLK_CTRL_CAMERAMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_CAMERAMIX peripheral base pointers */
  #define BLK_CTRL_CAMERAMIX_BASE_PTRS_NS          { BLK_CTRL_CAMERAMIX_NS }
#else
  /** Peripheral BLK_CTRL_CAMERAMIX base address */
  #define BLK_CTRL_CAMERAMIX_BASE                  (0x4AC10000u)
  /** Peripheral BLK_CTRL_CAMERAMIX base pointer */
  #define BLK_CTRL_CAMERAMIX                       ((BLK_CTRL_CAMERAMIX_Type *)BLK_CTRL_CAMERAMIX_BASE)
  /** Array initializer of BLK_CTRL_CAMERAMIX peripheral base addresses */
  #define BLK_CTRL_CAMERAMIX_BASE_ADDRS            { BLK_CTRL_CAMERAMIX_BASE }
  /** Array initializer of BLK_CTRL_CAMERAMIX peripheral base pointers */
  #define BLK_CTRL_CAMERAMIX_BASE_PTRS             { BLK_CTRL_CAMERAMIX }
#endif

/* BLK_CTRL_NETCMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_NETCMIX base address */
  #define BLK_CTRL_NETCMIX_BASE                    (0x5C810000u)
  /** Peripheral BLK_CTRL_NETCMIX base address */
  #define BLK_CTRL_NETCMIX_BASE_NS                 (0x4C810000u)
  /** Peripheral BLK_CTRL_NETCMIX base pointer */
  #define BLK_CTRL_NETCMIX                         ((BLK_CTRL_NETCMIX_Type *)BLK_CTRL_NETCMIX_BASE)
  /** Peripheral BLK_CTRL_NETCMIX base pointer */
  #define BLK_CTRL_NETCMIX_NS                      ((BLK_CTRL_NETCMIX_Type *)BLK_CTRL_NETCMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base addresses */
  #define BLK_CTRL_NETCMIX_BASE_ADDRS              { BLK_CTRL_NETCMIX_BASE }
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base pointers */
  #define BLK_CTRL_NETCMIX_BASE_PTRS               { BLK_CTRL_NETCMIX }
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base addresses */
  #define BLK_CTRL_NETCMIX_BASE_ADDRS_NS           { BLK_CTRL_NETCMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base pointers */
  #define BLK_CTRL_NETCMIX_BASE_PTRS_NS            { BLK_CTRL_NETCMIX_NS }
#else
  /** Peripheral BLK_CTRL_NETCMIX base address */
  #define BLK_CTRL_NETCMIX_BASE                    (0x4C810000u)
  /** Peripheral BLK_CTRL_NETCMIX base pointer */
  #define BLK_CTRL_NETCMIX                         ((BLK_CTRL_NETCMIX_Type *)BLK_CTRL_NETCMIX_BASE)
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base addresses */
  #define BLK_CTRL_NETCMIX_BASE_ADDRS              { BLK_CTRL_NETCMIX_BASE }
  /** Array initializer of BLK_CTRL_NETCMIX peripheral base pointers */
  #define BLK_CTRL_NETCMIX_BASE_PTRS               { BLK_CTRL_NETCMIX }
#endif

/* BLK_CTRL_NS_AONMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_NS_AONMIX base address */
  #define BLK_CTRL_NS_AONMIX_BASE                  (0x54210000u)
  /** Peripheral BLK_CTRL_NS_AONMIX base address */
  #define BLK_CTRL_NS_AONMIX_BASE_NS               (0x44210000u)
  /** Peripheral BLK_CTRL_NS_AONMIX base pointer */
  #define BLK_CTRL_NS_AONMIX                       ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX_BASE)
  /** Peripheral BLK_CTRL_NS_AONMIX base pointer */
  #define BLK_CTRL_NS_AONMIX_NS                    ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
  #define BLK_CTRL_NS_AONMIX_BASE_ADDRS            { BLK_CTRL_NS_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
  #define BLK_CTRL_NS_AONMIX_BASE_PTRS             { BLK_CTRL_NS_AONMIX }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
  #define BLK_CTRL_NS_AONMIX_BASE_ADDRS_NS         { BLK_CTRL_NS_AONMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
  #define BLK_CTRL_NS_AONMIX_BASE_PTRS_NS          { BLK_CTRL_NS_AONMIX_NS }
#else
  /** Peripheral BLK_CTRL_NS_AONMIX base address */
  #define BLK_CTRL_NS_AONMIX_BASE                  (0x44210000u)
  /** Peripheral BLK_CTRL_NS_AONMIX base pointer */
  #define BLK_CTRL_NS_AONMIX                       ((BLK_CTRL_NS_AONMIX_Type *)BLK_CTRL_NS_AONMIX_BASE)
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base addresses */
  #define BLK_CTRL_NS_AONMIX_BASE_ADDRS            { BLK_CTRL_NS_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_NS_AONMIX peripheral base pointers */
  #define BLK_CTRL_NS_AONMIX_BASE_PTRS             { BLK_CTRL_NS_AONMIX }
#endif

/* BLK_CTRL_S_AONMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_S_AONMIX base address */
  #define BLK_CTRL_S_AONMIX_BASE                   (0x544F0000u)
  /** Peripheral BLK_CTRL_S_AONMIX base address */
  #define BLK_CTRL_S_AONMIX_BASE_NS                (0x444F0000u)
  /** Peripheral BLK_CTRL_S_AONMIX base pointer */
  #define BLK_CTRL_S_AONMIX                        ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX_BASE)
  /** Peripheral BLK_CTRL_S_AONMIX base pointer */
  #define BLK_CTRL_S_AONMIX_NS                     ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
  #define BLK_CTRL_S_AONMIX_BASE_ADDRS             { BLK_CTRL_S_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
  #define BLK_CTRL_S_AONMIX_BASE_PTRS              { BLK_CTRL_S_AONMIX }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
  #define BLK_CTRL_S_AONMIX_BASE_ADDRS_NS          { BLK_CTRL_S_AONMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
  #define BLK_CTRL_S_AONMIX_BASE_PTRS_NS           { BLK_CTRL_S_AONMIX_NS }
#else
  /** Peripheral BLK_CTRL_S_AONMIX base address */
  #define BLK_CTRL_S_AONMIX_BASE                   (0x444F0000u)
  /** Peripheral BLK_CTRL_S_AONMIX base pointer */
  #define BLK_CTRL_S_AONMIX                        ((BLK_CTRL_S_AONMIX_Type *)BLK_CTRL_S_AONMIX_BASE)
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base addresses */
  #define BLK_CTRL_S_AONMIX_BASE_ADDRS             { BLK_CTRL_S_AONMIX_BASE }
  /** Array initializer of BLK_CTRL_S_AONMIX peripheral base pointers */
  #define BLK_CTRL_S_AONMIX_BASE_PTRS              { BLK_CTRL_S_AONMIX }
#endif

/* BLK_CTRL_WAKEUPMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral BLK_CTRL_WAKEUPMIX base address */
  #define BLK_CTRL_WAKEUPMIX_BASE                  (0x52040000u)
  /** Peripheral BLK_CTRL_WAKEUPMIX base address */
  #define BLK_CTRL_WAKEUPMIX_BASE_NS               (0x42040000u)
  /** Peripheral BLK_CTRL_WAKEUPMIX base pointer */
  #define BLK_CTRL_WAKEUPMIX                       ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX_BASE)
  /** Peripheral BLK_CTRL_WAKEUPMIX base pointer */
  #define BLK_CTRL_WAKEUPMIX_NS                    ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX_BASE_NS)
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
  #define BLK_CTRL_WAKEUPMIX_BASE_ADDRS            { BLK_CTRL_WAKEUPMIX_BASE }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
  #define BLK_CTRL_WAKEUPMIX_BASE_PTRS             { BLK_CTRL_WAKEUPMIX }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
  #define BLK_CTRL_WAKEUPMIX_BASE_ADDRS_NS         { BLK_CTRL_WAKEUPMIX_BASE_NS }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
  #define BLK_CTRL_WAKEUPMIX_BASE_PTRS_NS          { BLK_CTRL_WAKEUPMIX_NS }
#else
  /** Peripheral BLK_CTRL_WAKEUPMIX base address */
  #define BLK_CTRL_WAKEUPMIX_BASE                  (0x42040000u)
  /** Peripheral BLK_CTRL_WAKEUPMIX base pointer */
  #define BLK_CTRL_WAKEUPMIX                       ((BLK_CTRL_WAKEUPMIX_Type *)BLK_CTRL_WAKEUPMIX_BASE)
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base addresses */
  #define BLK_CTRL_WAKEUPMIX_BASE_ADDRS            { BLK_CTRL_WAKEUPMIX_BASE }
  /** Array initializer of BLK_CTRL_WAKEUPMIX peripheral base pointers */
  #define BLK_CTRL_WAKEUPMIX_BASE_PTRS             { BLK_CTRL_WAKEUPMIX }
#endif

/* CACHE_ECC_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base address */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE (0x54401000u)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base address */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE_NS (0x44401000u)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base pointer */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM ((CACHE_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base pointer */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_NS ((CACHE_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE_NS)
  /** Array initializer of CACHE_ECC_MCM peripheral base addresses */
  #define CACHE_ECC_MCM_BASE_ADDRS                 { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE }
  /** Array initializer of CACHE_ECC_MCM peripheral base pointers */
  #define CACHE_ECC_MCM_BASE_PTRS                  { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM }
  /** Array initializer of CACHE_ECC_MCM peripheral base addresses */
  #define CACHE_ECC_MCM_BASE_ADDRS_NS              { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE_NS }
  /** Array initializer of CACHE_ECC_MCM peripheral base pointers */
  #define CACHE_ECC_MCM_BASE_PTRS_NS               { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_NS }
#else
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base address */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE (0x44401000u)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM base pointer */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM ((CACHE_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE)
  /** Array initializer of CACHE_ECC_MCM peripheral base addresses */
  #define CACHE_ECC_MCM_BASE_ADDRS                 { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM_BASE }
  /** Array initializer of CACHE_ECC_MCM peripheral base pointers */
  #define CACHE_ECC_MCM_BASE_PTRS                  { AON__M33_CACHE_CTRL_ECC0__CM33_CACHE_ECC_MCM }
#endif

/* CAMERA_PHY_CSR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CAMERA__PHY_CSR base address */
  #define CAMERA__PHY_CSR_BASE                     (0x5AD20000u)
  /** Peripheral CAMERA__PHY_CSR base address */
  #define CAMERA__PHY_CSR_BASE_NS                  (0x4AD20000u)
  /** Peripheral CAMERA__PHY_CSR base pointer */
  #define CAMERA__PHY_CSR                          ((CAMERA_PHY_CSR_Type *)CAMERA__PHY_CSR_BASE)
  /** Peripheral CAMERA__PHY_CSR base pointer */
  #define CAMERA__PHY_CSR_NS                       ((CAMERA_PHY_CSR_Type *)CAMERA__PHY_CSR_BASE_NS)
  /** Array initializer of CAMERA_PHY_CSR peripheral base addresses */
  #define CAMERA_PHY_CSR_BASE_ADDRS                { CAMERA__PHY_CSR_BASE }
  /** Array initializer of CAMERA_PHY_CSR peripheral base pointers */
  #define CAMERA_PHY_CSR_BASE_PTRS                 { CAMERA__PHY_CSR }
  /** Array initializer of CAMERA_PHY_CSR peripheral base addresses */
  #define CAMERA_PHY_CSR_BASE_ADDRS_NS             { CAMERA__PHY_CSR_BASE_NS }
  /** Array initializer of CAMERA_PHY_CSR peripheral base pointers */
  #define CAMERA_PHY_CSR_BASE_PTRS_NS              { CAMERA__PHY_CSR_NS }
#else
  /** Peripheral CAMERA__PHY_CSR base address */
  #define CAMERA__PHY_CSR_BASE                     (0x4AD20000u)
  /** Peripheral CAMERA__PHY_CSR base pointer */
  #define CAMERA__PHY_CSR                          ((CAMERA_PHY_CSR_Type *)CAMERA__PHY_CSR_BASE)
  /** Array initializer of CAMERA_PHY_CSR peripheral base addresses */
  #define CAMERA_PHY_CSR_BASE_ADDRS                { CAMERA__PHY_CSR_BASE }
  /** Array initializer of CAMERA_PHY_CSR peripheral base pointers */
  #define CAMERA_PHY_CSR_BASE_PTRS                 { CAMERA__PHY_CSR }
#endif

/* CAN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CAN1 base address */
  #define CAN1_BASE                                (0x543A0000u)
  /** Peripheral CAN1 base address */
  #define CAN1_BASE_NS                             (0x443A0000u)
  /** Peripheral CAN1 base pointer */
  #define CAN1                                     ((CAN_Type *)CAN1_BASE)
  /** Peripheral CAN1 base pointer */
  #define CAN1_NS                                  ((CAN_Type *)CAN1_BASE_NS)
  /** Peripheral CAN2 base address */
  #define CAN2_BASE                                (0x521D0000u)
  /** Peripheral CAN2 base address */
  #define CAN2_BASE_NS                             (0x421D0000u)
  /** Peripheral CAN2 base pointer */
  #define CAN2                                     ((CAN_Type *)CAN2_BASE)
  /** Peripheral CAN2 base pointer */
  #define CAN2_NS                                  ((CAN_Type *)CAN2_BASE_NS)
  /** Peripheral CAN3 base address */
  #define CAN3_BASE                                (0x52220000u)
  /** Peripheral CAN3 base address */
  #define CAN3_BASE_NS                             (0x42220000u)
  /** Peripheral CAN3 base pointer */
  #define CAN3                                     ((CAN_Type *)CAN3_BASE)
  /** Peripheral CAN3 base pointer */
  #define CAN3_NS                                  ((CAN_Type *)CAN3_BASE_NS)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { 0u, CAN1_BASE, CAN2_BASE, CAN3_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { (CAN_Type *)0u, CAN1, CAN2, CAN3 }
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS_NS                        { 0u, CAN1_BASE_NS, CAN2_BASE_NS, CAN3_BASE_NS }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS_NS                         { (CAN_Type *)0u, CAN1_NS, CAN2_NS, CAN3_NS }
#else
  /** Peripheral CAN1 base address */
  #define CAN1_BASE                                (0x443A0000u)
  /** Peripheral CAN1 base pointer */
  #define CAN1                                     ((CAN_Type *)CAN1_BASE)
  /** Peripheral CAN2 base address */
  #define CAN2_BASE                                (0x421D0000u)
  /** Peripheral CAN2 base pointer */
  #define CAN2                                     ((CAN_Type *)CAN2_BASE)
  /** Peripheral CAN3 base address */
  #define CAN3_BASE                                (0x42220000u)
  /** Peripheral CAN3 base pointer */
  #define CAN3                                     ((CAN_Type *)CAN3_BASE)
  /** Array initializer of CAN peripheral base addresses */
  #define CAN_BASE_ADDRS                           { 0u, CAN1_BASE, CAN2_BASE, CAN3_BASE }
  /** Array initializer of CAN peripheral base pointers */
  #define CAN_BASE_PTRS                            { (CAN_Type *)0u, CAN1, CAN2, CAN3 }
#endif
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }
#define CAN_Tx_Warning_IRQS                      { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }
#define CAN_Wake_Up_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }
#define CAN_Error_IRQS                           { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }
#define CAN_Bus_Off_IRQS                         { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { NotAvail_IRQn, CAN1_IRQn, CAN2_IRQn, CAN3_IRQn }

/* CCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE                            (0x54450000u)
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE_NS                         (0x44450000u)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL                                 ((CCM_Type *)CCM_CTRL_BASE)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL_NS                              ((CCM_Type *)CCM_CTRL_BASE_NS)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { CCM_CTRL_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { CCM_CTRL }
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS_NS                        { CCM_CTRL_BASE_NS }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS_NS                         { CCM_CTRL_NS }
#else
  /** Peripheral CCM_CTRL base address */
  #define CCM_CTRL_BASE                            (0x44450000u)
  /** Peripheral CCM_CTRL base pointer */
  #define CCM_CTRL                                 ((CCM_Type *)CCM_CTRL_BASE)
  /** Array initializer of CCM peripheral base addresses */
  #define CCM_BASE_ADDRS                           { CCM_CTRL_BASE }
  /** Array initializer of CCM peripheral base pointers */
  #define CCM_BASE_PTRS                            { CCM_CTRL }
#endif

/* CONSTFR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CONSTFR base address */
  #define DISPLAY__SEERIS__CONSTFR_BASE            (0x5B4F0000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR base address */
  #define DISPLAY__SEERIS__CONSTFR_BASE_NS         (0x4B4F0000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR base pointer */
  #define DISPLAY__SEERIS__CONSTFR                 ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR_BASE)
  /** Peripheral DISPLAY__SEERIS__CONSTFR base pointer */
  #define DISPLAY__SEERIS__CONSTFR_NS              ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__CONSTFR1 base address */
  #define DISPLAY__SEERIS__CONSTFR1_BASE           (0x5B500000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR1 base address */
  #define DISPLAY__SEERIS__CONSTFR1_BASE_NS        (0x4B500000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR1 base pointer */
  #define DISPLAY__SEERIS__CONSTFR1                ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR1_BASE)
  /** Peripheral DISPLAY__SEERIS__CONSTFR1 base pointer */
  #define DISPLAY__SEERIS__CONSTFR1_NS             ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR1_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__CONSTFR2 base address */
  #define DISPLAY__SEERIS__CONSTFR2_BASE           (0x5B530000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR2 base address */
  #define DISPLAY__SEERIS__CONSTFR2_BASE_NS        (0x4B530000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR2 base pointer */
  #define DISPLAY__SEERIS__CONSTFR2                ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR2_BASE)
  /** Peripheral DISPLAY__SEERIS__CONSTFR2 base pointer */
  #define DISPLAY__SEERIS__CONSTFR2_NS             ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR2_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__CONSTFR3 base address */
  #define DISPLAY__SEERIS__CONSTFR3_BASE           (0x5B540000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR3 base address */
  #define DISPLAY__SEERIS__CONSTFR3_BASE_NS        (0x4B540000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR3 base pointer */
  #define DISPLAY__SEERIS__CONSTFR3                ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR3_BASE)
  /** Peripheral DISPLAY__SEERIS__CONSTFR3 base pointer */
  #define DISPLAY__SEERIS__CONSTFR3_NS             ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR3_BASE_NS)
  /** Array initializer of CONSTFR peripheral base addresses */
  #define CONSTFR_BASE_ADDRS                       { DISPLAY__SEERIS__CONSTFR_BASE, DISPLAY__SEERIS__CONSTFR1_BASE, DISPLAY__SEERIS__CONSTFR2_BASE, DISPLAY__SEERIS__CONSTFR3_BASE }
  /** Array initializer of CONSTFR peripheral base pointers */
  #define CONSTFR_BASE_PTRS                        { DISPLAY__SEERIS__CONSTFR, DISPLAY__SEERIS__CONSTFR1, DISPLAY__SEERIS__CONSTFR2, DISPLAY__SEERIS__CONSTFR3 }
  /** Array initializer of CONSTFR peripheral base addresses */
  #define CONSTFR_BASE_ADDRS_NS                    { DISPLAY__SEERIS__CONSTFR_BASE_NS, DISPLAY__SEERIS__CONSTFR1_BASE_NS, DISPLAY__SEERIS__CONSTFR2_BASE_NS, DISPLAY__SEERIS__CONSTFR3_BASE_NS }
  /** Array initializer of CONSTFR peripheral base pointers */
  #define CONSTFR_BASE_PTRS_NS                     { DISPLAY__SEERIS__CONSTFR_NS, DISPLAY__SEERIS__CONSTFR1_NS, DISPLAY__SEERIS__CONSTFR2_NS, DISPLAY__SEERIS__CONSTFR3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CONSTFR base address */
  #define DISPLAY__SEERIS__CONSTFR_BASE            (0x4B4F0000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR base pointer */
  #define DISPLAY__SEERIS__CONSTFR                 ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR_BASE)
  /** Peripheral DISPLAY__SEERIS__CONSTFR1 base address */
  #define DISPLAY__SEERIS__CONSTFR1_BASE           (0x4B500000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR1 base pointer */
  #define DISPLAY__SEERIS__CONSTFR1                ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR1_BASE)
  /** Peripheral DISPLAY__SEERIS__CONSTFR2 base address */
  #define DISPLAY__SEERIS__CONSTFR2_BASE           (0x4B530000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR2 base pointer */
  #define DISPLAY__SEERIS__CONSTFR2                ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR2_BASE)
  /** Peripheral DISPLAY__SEERIS__CONSTFR3 base address */
  #define DISPLAY__SEERIS__CONSTFR3_BASE           (0x4B540000u)
  /** Peripheral DISPLAY__SEERIS__CONSTFR3 base pointer */
  #define DISPLAY__SEERIS__CONSTFR3                ((CONSTFR_Type *)DISPLAY__SEERIS__CONSTFR3_BASE)
  /** Array initializer of CONSTFR peripheral base addresses */
  #define CONSTFR_BASE_ADDRS                       { DISPLAY__SEERIS__CONSTFR_BASE, DISPLAY__SEERIS__CONSTFR1_BASE, DISPLAY__SEERIS__CONSTFR2_BASE, DISPLAY__SEERIS__CONSTFR3_BASE }
  /** Array initializer of CONSTFR peripheral base pointers */
  #define CONSTFR_BASE_PTRS                        { DISPLAY__SEERIS__CONSTFR, DISPLAY__SEERIS__CONSTFR1, DISPLAY__SEERIS__CONSTFR2, DISPLAY__SEERIS__CONSTFR3 }
#endif

/* CORTEXA_BLK_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CORTEXA__BLK_CTRL_CORTEXAMIX base address */
  #define CORTEXA__BLK_CTRL_CORTEXAMIX_BASE        (0x5A410000u)
  /** Peripheral CORTEXA__BLK_CTRL_CORTEXAMIX base address */
  #define CORTEXA__BLK_CTRL_CORTEXAMIX_BASE_NS     (0x4A410000u)
  /** Peripheral CORTEXA__BLK_CTRL_CORTEXAMIX base pointer */
  #define CORTEXA__BLK_CTRL_CORTEXAMIX             ((CORTEXA_BLK_CTRL_Type *)CORTEXA__BLK_CTRL_CORTEXAMIX_BASE)
  /** Peripheral CORTEXA__BLK_CTRL_CORTEXAMIX base pointer */
  #define CORTEXA__BLK_CTRL_CORTEXAMIX_NS          ((CORTEXA_BLK_CTRL_Type *)CORTEXA__BLK_CTRL_CORTEXAMIX_BASE_NS)
  /** Array initializer of CORTEXA_BLK_CTRL peripheral base addresses */
  #define CORTEXA_BLK_CTRL_BASE_ADDRS              { CORTEXA__BLK_CTRL_CORTEXAMIX_BASE }
  /** Array initializer of CORTEXA_BLK_CTRL peripheral base pointers */
  #define CORTEXA_BLK_CTRL_BASE_PTRS               { CORTEXA__BLK_CTRL_CORTEXAMIX }
  /** Array initializer of CORTEXA_BLK_CTRL peripheral base addresses */
  #define CORTEXA_BLK_CTRL_BASE_ADDRS_NS           { CORTEXA__BLK_CTRL_CORTEXAMIX_BASE_NS }
  /** Array initializer of CORTEXA_BLK_CTRL peripheral base pointers */
  #define CORTEXA_BLK_CTRL_BASE_PTRS_NS            { CORTEXA__BLK_CTRL_CORTEXAMIX_NS }
#else
  /** Peripheral CORTEXA__BLK_CTRL_CORTEXAMIX base address */
  #define CORTEXA__BLK_CTRL_CORTEXAMIX_BASE        (0x4A410000u)
  /** Peripheral CORTEXA__BLK_CTRL_CORTEXAMIX base pointer */
  #define CORTEXA__BLK_CTRL_CORTEXAMIX             ((CORTEXA_BLK_CTRL_Type *)CORTEXA__BLK_CTRL_CORTEXAMIX_BASE)
  /** Array initializer of CORTEXA_BLK_CTRL peripheral base addresses */
  #define CORTEXA_BLK_CTRL_BASE_ADDRS              { CORTEXA__BLK_CTRL_CORTEXAMIX_BASE }
  /** Array initializer of CORTEXA_BLK_CTRL peripheral base pointers */
  #define CORTEXA_BLK_CTRL_BASE_PTRS               { CORTEXA__BLK_CTRL_CORTEXAMIX }
#endif

/* CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__CRCA base address */
  #define AON__CRCA_BASE                           (0x54660000u)
  /** Peripheral AON__CRCA base address */
  #define AON__CRCA_BASE_NS                        (0x44660000u)
  /** Peripheral AON__CRCA base pointer */
  #define CRC                                      ((CRC_Type *)AON__CRCA_BASE)
  /** Peripheral AON__CRCA base pointer */
  #define CRC_NS                                   ((CRC_Type *)AON__CRCA_BASE_NS)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { AON__CRCA_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC }
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS_NS                        { AON__CRCA_BASE_NS }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS_NS                         { CRC_NS }
#else
  /** Peripheral AON__CRCA base address */
  #define AON__CRCA_BASE                           (0x44660000u)
  /** Peripheral AON__CRCA base pointer */
  #define CRC                                      ((CRC_Type *)AON__CRCA_BASE)
  /** Array initializer of CRC peripheral base addresses */
  #define CRC_BASE_ADDRS                           { AON__CRCA_BASE }
  /** Array initializer of CRC peripheral base pointers */
  #define CRC_BASE_PTRS                            { CRC }
#endif

/* CSI2_CONTROLLER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER base address */
  #define CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE (0x5AD30000u)
  /** Peripheral CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER base address */
  #define CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE_NS (0x4AD30000u)
  /** Peripheral CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER base pointer */
  #define CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER ((CSI2_CONTROLLER_Type *)CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE)
  /** Peripheral CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER base pointer */
  #define CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_NS ((CSI2_CONTROLLER_Type *)CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE_NS)
  /** Peripheral CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER base address */
  #define CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE (0x5AD40000u)
  /** Peripheral CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER base address */
  #define CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE_NS (0x4AD40000u)
  /** Peripheral CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER base pointer */
  #define CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER ((CSI2_CONTROLLER_Type *)CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE)
  /** Peripheral CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER base pointer */
  #define CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_NS ((CSI2_CONTROLLER_Type *)CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE_NS)
  /** Array initializer of CSI2_CONTROLLER peripheral base addresses */
  #define CSI2_CONTROLLER_BASE_ADDRS               { CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE, CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE }
  /** Array initializer of CSI2_CONTROLLER peripheral base pointers */
  #define CSI2_CONTROLLER_BASE_PTRS                { CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER, CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER }
  /** Array initializer of CSI2_CONTROLLER peripheral base addresses */
  #define CSI2_CONTROLLER_BASE_ADDRS_NS            { CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE_NS, CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE_NS }
  /** Array initializer of CSI2_CONTROLLER peripheral base pointers */
  #define CSI2_CONTROLLER_BASE_PTRS_NS             { CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_NS, CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_NS }
#else
  /** Peripheral CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER base address */
  #define CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE (0x4AD30000u)
  /** Peripheral CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER base pointer */
  #define CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER ((CSI2_CONTROLLER_Type *)CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE)
  /** Peripheral CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER base address */
  #define CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE (0x4AD40000u)
  /** Peripheral CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER base pointer */
  #define CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER ((CSI2_CONTROLLER_Type *)CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE)
  /** Array initializer of CSI2_CONTROLLER peripheral base addresses */
  #define CSI2_CONTROLLER_BASE_ADDRS               { CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER_BASE, CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER_BASE }
  /** Array initializer of CSI2_CONTROLLER peripheral base pointers */
  #define CSI2_CONTROLLER_BASE_PTRS                { CAMERA__CSI_COMPLEX__PRIMARY_CSI2_CONTROLLER, CAMERA__CSI_COMPLEX__SECONDARY_CSI2_CONTROLLER }
#endif

/* DDRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DDRC base address */
  #define DDRC_BASE                                (0x5E080000u)
  /** Peripheral DDRC base address */
  #define DDRC_BASE_NS                             (0x4E080000u)
  /** Peripheral DDRC base pointer */
  #define DDRC                                     ((DDRC_Type *)DDRC_BASE)
  /** Peripheral DDRC base pointer */
  #define DDRC_NS                                  ((DDRC_Type *)DDRC_BASE_NS)
  /** Array initializer of DDRC peripheral base addresses */
  #define DDRC_BASE_ADDRS                          { DDRC_BASE }
  /** Array initializer of DDRC peripheral base pointers */
  #define DDRC_BASE_PTRS                           { DDRC }
  /** Array initializer of DDRC peripheral base addresses */
  #define DDRC_BASE_ADDRS_NS                       { DDRC_BASE_NS }
  /** Array initializer of DDRC peripheral base pointers */
  #define DDRC_BASE_PTRS_NS                        { DDRC_NS }
#else
  /** Peripheral DDRC base address */
  #define DDRC_BASE                                (0x4E080000u)
  /** Peripheral DDRC base pointer */
  #define DDRC                                     ((DDRC_Type *)DDRC_BASE)
  /** Array initializer of DDRC peripheral base addresses */
  #define DDRC_BASE_ADDRS                          { DDRC_BASE }
  /** Array initializer of DDRC peripheral base pointers */
  #define DDRC_BASE_PTRS                           { DDRC }
#endif

/* DDR_BLK_CTRL_DDRMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DDRC__BLK_CTRL_DDRMIX base address */
  #define BLK_CTRL_DDRMIX_BASE               (0x5E010000u)
  /** Peripheral DDRC__BLK_CTRL_DDRMIX base address */
  #define BLK_CTRL_DDRMIX_BASE_NS            (0x4E010000u)
  /** Peripheral DDRC__BLK_CTRL_DDRMIX base pointer */
  #define BLK_CTRL_DDRMIX                    ((BLK_CTRL_DDRMIX_Type *)BLK_CTRL_DDRMIX_BASE)
  /** Peripheral DDRC__BLK_CTRL_DDRMIX base pointer */
  #define BLK_CTRL_DDRMIX_NS                 ((BLK_CTRL_DDRMIX_Type *)BLK_CTRL_DDRMIX_BASE_NS)
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base addresses */
  #define BLK_CTRL_DDRMIX_BASE_ADDRS           { BLK_CTRL_DDRMIX_BASE }
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base pointers */
  #define BLK_CTRL_DDRMIX_BASE_PTRS            { BLK_CTRL_DDRMIX }
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base addresses */
  #define BLK_CTRL_DDRMIX_BASE_ADDRS_NS        { BLK_CTRL_DDRMIX_BASE_NS }
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base pointers */
  #define BLK_CTRL_DDRMIX_BASE_PTRS_NS         { BLK_CTRL_DDRMIX_NS }
#else
  /** Peripheral DDRC__BLK_CTRL_DDRMIX base address */
  #define BLK_CTRL_DDRMIX_BASE               (0x4E010000u)
  /** Peripheral DDRC__BLK_CTRL_DDRMIX base pointer */
  #define BLK_CTRL_DDRMIX                    ((BLK_CTRL_DDRMIX_Type *)BLK_CTRL_DDRMIX_BASE)
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base addresses */
  #define BLK_CTRL_DDRMIX_BASE_ADDRS           { BLK_CTRL_DDRMIX_BASE }
  /** Array initializer of DDR_BLK_CTRL_DDRMIX peripheral base pointers */
  #define BLK_CTRL_DDRMIX_BASE_PTRS            { BLK_CTRL_DDRMIX }
#endif

/* DISPLAY_BLK_CTRL_DISPLAYMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__BLK_CTRL_DISPLAYMIX base address */
  #define DISPLAY__BLK_CTRL_DISPLAYMIX_BASE        (0x5B010000u)
  /** Peripheral DISPLAY__BLK_CTRL_DISPLAYMIX base address */
  #define DISPLAY__BLK_CTRL_DISPLAYMIX_BASE_NS     (0x4B010000u)
  /** Peripheral DISPLAY__BLK_CTRL_DISPLAYMIX base pointer */
  #define DISPLAY__BLK_CTRL_DISPLAYMIX             ((DISPLAY_BLK_CTRL_DISPLAYMIX_Type *)DISPLAY__BLK_CTRL_DISPLAYMIX_BASE)
  /** Peripheral DISPLAY__BLK_CTRL_DISPLAYMIX base pointer */
  #define DISPLAY__BLK_CTRL_DISPLAYMIX_NS          ((DISPLAY_BLK_CTRL_DISPLAYMIX_Type *)DISPLAY__BLK_CTRL_DISPLAYMIX_BASE_NS)
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base addresses */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_ADDRS   { DISPLAY__BLK_CTRL_DISPLAYMIX_BASE }
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base pointers */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_PTRS    { DISPLAY__BLK_CTRL_DISPLAYMIX }
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base addresses */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_ADDRS_NS { DISPLAY__BLK_CTRL_DISPLAYMIX_BASE_NS }
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base pointers */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_PTRS_NS { DISPLAY__BLK_CTRL_DISPLAYMIX_NS }
#else
  /** Peripheral DISPLAY__BLK_CTRL_DISPLAYMIX base address */
  #define DISPLAY__BLK_CTRL_DISPLAYMIX_BASE        (0x4B010000u)
  /** Peripheral DISPLAY__BLK_CTRL_DISPLAYMIX base pointer */
  #define DISPLAY__BLK_CTRL_DISPLAYMIX             ((DISPLAY_BLK_CTRL_DISPLAYMIX_Type *)DISPLAY__BLK_CTRL_DISPLAYMIX_BASE)
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base addresses */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_ADDRS   { DISPLAY__BLK_CTRL_DISPLAYMIX_BASE }
  /** Array initializer of DISPLAY_BLK_CTRL_DISPLAYMIX peripheral base pointers */
  #define DISPLAY_BLK_CTRL_DISPLAYMIX_BASE_PTRS    { DISPLAY__BLK_CTRL_DISPLAYMIX }
#endif

/* DISPLAY_DSI_CSR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__DSI_CSR base address */
  #define DISPLAY__DSI_CSR_BASE                    (0x5B0A0000u)
  /** Peripheral DISPLAY__DSI_CSR base address */
  #define DISPLAY__DSI_CSR_BASE_NS                 (0x4B0A0000u)
  /** Peripheral DISPLAY__DSI_CSR base pointer */
  #define DISPLAY__DSI_CSR                         ((DISPLAY_DSI_CSR_Type *)DISPLAY__DSI_CSR_BASE)
  /** Peripheral DISPLAY__DSI_CSR base pointer */
  #define DISPLAY__DSI_CSR_NS                      ((DISPLAY_DSI_CSR_Type *)DISPLAY__DSI_CSR_BASE_NS)
  /** Array initializer of DISPLAY_DSI_CSR peripheral base addresses */
  #define DISPLAY_DSI_CSR_BASE_ADDRS               { DISPLAY__DSI_CSR_BASE }
  /** Array initializer of DISPLAY_DSI_CSR peripheral base pointers */
  #define DISPLAY_DSI_CSR_BASE_PTRS                { DISPLAY__DSI_CSR }
  /** Array initializer of DISPLAY_DSI_CSR peripheral base addresses */
  #define DISPLAY_DSI_CSR_BASE_ADDRS_NS            { DISPLAY__DSI_CSR_BASE_NS }
  /** Array initializer of DISPLAY_DSI_CSR peripheral base pointers */
  #define DISPLAY_DSI_CSR_BASE_PTRS_NS             { DISPLAY__DSI_CSR_NS }
#else
  /** Peripheral DISPLAY__DSI_CSR base address */
  #define DISPLAY__DSI_CSR_BASE                    (0x4B0A0000u)
  /** Peripheral DISPLAY__DSI_CSR base pointer */
  #define DISPLAY__DSI_CSR                         ((DISPLAY_DSI_CSR_Type *)DISPLAY__DSI_CSR_BASE)
  /** Array initializer of DISPLAY_DSI_CSR peripheral base addresses */
  #define DISPLAY_DSI_CSR_BASE_ADDRS               { DISPLAY__DSI_CSR_BASE }
  /** Array initializer of DISPLAY_DSI_CSR peripheral base pointers */
  #define DISPLAY_DSI_CSR_BASE_PTRS                { DISPLAY__DSI_CSR }
#endif

/* DISPLAY_MIPI_DSI_PHY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__MIPI_DSI_PHY base address */
  #define DISPLAY__MIPI_DSI_PHY_BASE               (0x5B110000u)
  /** Peripheral DISPLAY__MIPI_DSI_PHY base address */
  #define DISPLAY__MIPI_DSI_PHY_BASE_NS            (0x4B110000u)
  /** Peripheral DISPLAY__MIPI_DSI_PHY base pointer */
  #define DISPLAY__MIPI_DSI_PHY                    ((DISPLAY_MIPI_DSI_PHY_Type *)DISPLAY__MIPI_DSI_PHY_BASE)
  /** Peripheral DISPLAY__MIPI_DSI_PHY base pointer */
  #define DISPLAY__MIPI_DSI_PHY_NS                 ((DISPLAY_MIPI_DSI_PHY_Type *)DISPLAY__MIPI_DSI_PHY_BASE_NS)
  /** Array initializer of DISPLAY_MIPI_DSI_PHY peripheral base addresses */
  #define DISPLAY_MIPI_DSI_PHY_BASE_ADDRS          { DISPLAY__MIPI_DSI_PHY_BASE }
  /** Array initializer of DISPLAY_MIPI_DSI_PHY peripheral base pointers */
  #define DISPLAY_MIPI_DSI_PHY_BASE_PTRS           { DISPLAY__MIPI_DSI_PHY }
  /** Array initializer of DISPLAY_MIPI_DSI_PHY peripheral base addresses */
  #define DISPLAY_MIPI_DSI_PHY_BASE_ADDRS_NS       { DISPLAY__MIPI_DSI_PHY_BASE_NS }
  /** Array initializer of DISPLAY_MIPI_DSI_PHY peripheral base pointers */
  #define DISPLAY_MIPI_DSI_PHY_BASE_PTRS_NS        { DISPLAY__MIPI_DSI_PHY_NS }
#else
  /** Peripheral DISPLAY__MIPI_DSI_PHY base address */
  #define DISPLAY__MIPI_DSI_PHY_BASE               (0x4B110000u)
  /** Peripheral DISPLAY__MIPI_DSI_PHY base pointer */
  #define DISPLAY__MIPI_DSI_PHY                    ((DISPLAY_MIPI_DSI_PHY_Type *)DISPLAY__MIPI_DSI_PHY_BASE)
  /** Array initializer of DISPLAY_MIPI_DSI_PHY peripheral base addresses */
  #define DISPLAY_MIPI_DSI_PHY_BASE_ADDRS          { DISPLAY__MIPI_DSI_PHY_BASE }
  /** Array initializer of DISPLAY_MIPI_DSI_PHY peripheral base pointers */
  #define DISPLAY_MIPI_DSI_PHY_BASE_PTRS           { DISPLAY__MIPI_DSI_PHY }
#endif

/* DISPLAY_OCRAM_MECC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__OCRAM_MECC base address */
  #define DISPLAY__OCRAM_MECC_BASE                 (0x5B0F0000u)
  /** Peripheral DISPLAY__OCRAM_MECC base address */
  #define DISPLAY__OCRAM_MECC_BASE_NS              (0x4B0F0000u)
  /** Peripheral DISPLAY__OCRAM_MECC base pointer */
  #define DISPLAY__OCRAM_MECC                      ((DISPLAY_OCRAM_MECC_Type *)DISPLAY__OCRAM_MECC_BASE)
  /** Peripheral DISPLAY__OCRAM_MECC base pointer */
  #define DISPLAY__OCRAM_MECC_NS                   ((DISPLAY_OCRAM_MECC_Type *)DISPLAY__OCRAM_MECC_BASE_NS)
  /** Array initializer of DISPLAY_OCRAM_MECC peripheral base addresses */
  #define DISPLAY_OCRAM_MECC_BASE_ADDRS            { DISPLAY__OCRAM_MECC_BASE }
  /** Array initializer of DISPLAY_OCRAM_MECC peripheral base pointers */
  #define DISPLAY_OCRAM_MECC_BASE_PTRS             { DISPLAY__OCRAM_MECC }
  /** Array initializer of DISPLAY_OCRAM_MECC peripheral base addresses */
  #define DISPLAY_OCRAM_MECC_BASE_ADDRS_NS         { DISPLAY__OCRAM_MECC_BASE_NS }
  /** Array initializer of DISPLAY_OCRAM_MECC peripheral base pointers */
  #define DISPLAY_OCRAM_MECC_BASE_PTRS_NS          { DISPLAY__OCRAM_MECC_NS }
#else
  /** Peripheral DISPLAY__OCRAM_MECC base address */
  #define DISPLAY__OCRAM_MECC_BASE                 (0x4B0F0000u)
  /** Peripheral DISPLAY__OCRAM_MECC base pointer */
  #define DISPLAY__OCRAM_MECC                      ((DISPLAY_OCRAM_MECC_Type *)DISPLAY__OCRAM_MECC_BASE)
  /** Array initializer of DISPLAY_OCRAM_MECC peripheral base addresses */
  #define DISPLAY_OCRAM_MECC_BASE_ADDRS            { DISPLAY__OCRAM_MECC_BASE }
  /** Array initializer of DISPLAY_OCRAM_MECC peripheral base pointers */
  #define DISPLAY_OCRAM_MECC_BASE_PTRS             { DISPLAY__OCRAM_MECC }
#endif

/* DISPLAY_PIXEL_INTERLEAVER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__PIXEL_INTERLEAVER base address */
  #define DISPLAY__PIXEL_INTERLEAVER_BASE          (0x5B0D0000u)
  /** Peripheral DISPLAY__PIXEL_INTERLEAVER base address */
  #define DISPLAY__PIXEL_INTERLEAVER_BASE_NS       (0x4B0D0000u)
  /** Peripheral DISPLAY__PIXEL_INTERLEAVER base pointer */
  #define DISPLAY__PIXEL_INTERLEAVER               ((DISPLAY_PIXEL_INTERLEAVER_Type *)DISPLAY__PIXEL_INTERLEAVER_BASE)
  /** Peripheral DISPLAY__PIXEL_INTERLEAVER base pointer */
  #define DISPLAY__PIXEL_INTERLEAVER_NS            ((DISPLAY_PIXEL_INTERLEAVER_Type *)DISPLAY__PIXEL_INTERLEAVER_BASE_NS)
  /** Array initializer of DISPLAY_PIXEL_INTERLEAVER peripheral base addresses */
  #define DISPLAY_PIXEL_INTERLEAVER_BASE_ADDRS     { DISPLAY__PIXEL_INTERLEAVER_BASE }
  /** Array initializer of DISPLAY_PIXEL_INTERLEAVER peripheral base pointers */
  #define DISPLAY_PIXEL_INTERLEAVER_BASE_PTRS      { DISPLAY__PIXEL_INTERLEAVER }
  /** Array initializer of DISPLAY_PIXEL_INTERLEAVER peripheral base addresses */
  #define DISPLAY_PIXEL_INTERLEAVER_BASE_ADDRS_NS  { DISPLAY__PIXEL_INTERLEAVER_BASE_NS }
  /** Array initializer of DISPLAY_PIXEL_INTERLEAVER peripheral base pointers */
  #define DISPLAY_PIXEL_INTERLEAVER_BASE_PTRS_NS   { DISPLAY__PIXEL_INTERLEAVER_NS }
#else
  /** Peripheral DISPLAY__PIXEL_INTERLEAVER base address */
  #define DISPLAY__PIXEL_INTERLEAVER_BASE          (0x4B0D0000u)
  /** Peripheral DISPLAY__PIXEL_INTERLEAVER base pointer */
  #define DISPLAY__PIXEL_INTERLEAVER               ((DISPLAY_PIXEL_INTERLEAVER_Type *)DISPLAY__PIXEL_INTERLEAVER_BASE)
  /** Array initializer of DISPLAY_PIXEL_INTERLEAVER peripheral base addresses */
  #define DISPLAY_PIXEL_INTERLEAVER_BASE_ADDRS     { DISPLAY__PIXEL_INTERLEAVER_BASE }
  /** Array initializer of DISPLAY_PIXEL_INTERLEAVER peripheral base pointers */
  #define DISPLAY_PIXEL_INTERLEAVER_BASE_PTRS      { DISPLAY__PIXEL_INTERLEAVER }
#endif

/* DISPLAY_SEERIS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY_SEERIS base address */
  #define DISPLAY_SEERIS_BASE                      (0x5B400000u)
  /** Peripheral DISPLAY_SEERIS base address */
  #define DISPLAY_SEERIS_BASE_NS                   (0x4B400000u)
  /** Peripheral DISPLAY_SEERIS base pointer */
  #define DISPLAY_SEERIS                           ((DISPLAY_SEERIS_Type *)DISPLAY_SEERIS_BASE)
  /** Peripheral DISPLAY_SEERIS base pointer */
  #define DISPLAY_SEERIS_NS                        ((DISPLAY_SEERIS_Type *)DISPLAY_SEERIS_BASE_NS)
  /** Array initializer of DISPLAY_SEERIS peripheral base addresses */
  #define DISPLAY_SEERIS_BASE_ADDRS                { DISPLAY_SEERIS_BASE }
  /** Array initializer of DISPLAY_SEERIS peripheral base pointers */
  #define DISPLAY_SEERIS_BASE_PTRS                 { DISPLAY_SEERIS }
  /** Array initializer of DISPLAY_SEERIS peripheral base addresses */
  #define DISPLAY_SEERIS_BASE_ADDRS_NS             { DISPLAY_SEERIS_BASE_NS }
  /** Array initializer of DISPLAY_SEERIS peripheral base pointers */
  #define DISPLAY_SEERIS_BASE_PTRS_NS              { DISPLAY_SEERIS_NS }
#else
  /** Peripheral DISPLAY_SEERIS base address */
  #define DISPLAY_SEERIS_BASE                      (0x4B400000u)
  /** Peripheral DISPLAY_SEERIS base pointer */
  #define DISPLAY_SEERIS                           ((DISPLAY_SEERIS_Type *)DISPLAY_SEERIS_BASE)
  /** Array initializer of DISPLAY_SEERIS peripheral base addresses */
  #define DISPLAY_SEERIS_BASE_ADDRS                { DISPLAY_SEERIS_BASE }
  /** Array initializer of DISPLAY_SEERIS peripheral base pointers */
  #define DISPLAY_SEERIS_BASE_PTRS                 { DISPLAY_SEERIS }
#endif

/* DITHER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__DITHER base address */
  #define DISPLAY__SEERIS__DITHER_BASE             (0x5B6F0000u)
  /** Peripheral DISPLAY__SEERIS__DITHER base address */
  #define DISPLAY__SEERIS__DITHER_BASE_NS          (0x4B6F0000u)
  /** Peripheral DISPLAY__SEERIS__DITHER base pointer */
  #define DISPLAY__SEERIS__DITHER                  ((DITHER_Type *)DISPLAY__SEERIS__DITHER_BASE)
  /** Peripheral DISPLAY__SEERIS__DITHER base pointer */
  #define DISPLAY__SEERIS__DITHER_NS               ((DITHER_Type *)DISPLAY__SEERIS__DITHER_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__DITHER1 base address */
  #define DISPLAY__SEERIS__DITHER1_BASE            (0x5B780000u)
  /** Peripheral DISPLAY__SEERIS__DITHER1 base address */
  #define DISPLAY__SEERIS__DITHER1_BASE_NS         (0x4B780000u)
  /** Peripheral DISPLAY__SEERIS__DITHER1 base pointer */
  #define DISPLAY__SEERIS__DITHER1                 ((DITHER_Type *)DISPLAY__SEERIS__DITHER1_BASE)
  /** Peripheral DISPLAY__SEERIS__DITHER1 base pointer */
  #define DISPLAY__SEERIS__DITHER1_NS              ((DITHER_Type *)DISPLAY__SEERIS__DITHER1_BASE_NS)
  /** Array initializer of DITHER peripheral base addresses */
  #define DITHER_BASE_ADDRS                        { DISPLAY__SEERIS__DITHER_BASE, DISPLAY__SEERIS__DITHER1_BASE }
  /** Array initializer of DITHER peripheral base pointers */
  #define DITHER_BASE_PTRS                         { DISPLAY__SEERIS__DITHER, DISPLAY__SEERIS__DITHER1 }
  /** Array initializer of DITHER peripheral base addresses */
  #define DITHER_BASE_ADDRS_NS                     { DISPLAY__SEERIS__DITHER_BASE_NS, DISPLAY__SEERIS__DITHER1_BASE_NS }
  /** Array initializer of DITHER peripheral base pointers */
  #define DITHER_BASE_PTRS_NS                      { DISPLAY__SEERIS__DITHER_NS, DISPLAY__SEERIS__DITHER1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__DITHER base address */
  #define DISPLAY__SEERIS__DITHER_BASE             (0x4B6F0000u)
  /** Peripheral DISPLAY__SEERIS__DITHER base pointer */
  #define DISPLAY__SEERIS__DITHER                  ((DITHER_Type *)DISPLAY__SEERIS__DITHER_BASE)
  /** Peripheral DISPLAY__SEERIS__DITHER1 base address */
  #define DISPLAY__SEERIS__DITHER1_BASE            (0x4B780000u)
  /** Peripheral DISPLAY__SEERIS__DITHER1 base pointer */
  #define DISPLAY__SEERIS__DITHER1                 ((DITHER_Type *)DISPLAY__SEERIS__DITHER1_BASE)
  /** Array initializer of DITHER peripheral base addresses */
  #define DITHER_BASE_ADDRS                        { DISPLAY__SEERIS__DITHER_BASE, DISPLAY__SEERIS__DITHER1_BASE }
  /** Array initializer of DITHER peripheral base pointers */
  #define DITHER_BASE_PTRS                         { DISPLAY__SEERIS__DITHER, DISPLAY__SEERIS__DITHER1 }
#endif

/* DMA - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DMA3 base address */
  #define DMA3_BASE                                (0x54000000u)
  /** Peripheral DMA3 base address */
  #define DMA3_BASE_NS                             (0x44000000u)
  /** Peripheral DMA3 base pointer */
  #define DMA3                                     ((DMA_Type *)DMA3_BASE)
  /** Peripheral DMA3 base pointer */
  #define DMA3_NS                                  ((DMA_Type *)DMA3_BASE_NS)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA3_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA3 }
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS_NS                        { DMA3_BASE_NS }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS_NS                         { DMA3_NS }
#else
  /** Peripheral DMA3 base address */
  #define DMA3_BASE                                (0x44000000u)
  /** Peripheral DMA3 base pointer */
  #define DMA3                                     ((DMA_Type *)DMA3_BASE)
  /** Array initializer of DMA peripheral base addresses */
  #define DMA_BASE_ADDRS                           { DMA3_BASE }
  /** Array initializer of DMA peripheral base pointers */
  #define DMA_BASE_PTRS                            { DMA3 }
#endif
/** Interrupt vectors for the DMA peripheral type */
#define DMA_IRQS                                 { { DMA3_0_IRQn, DMA3_1_IRQn, DMA3_2_IRQn, DMA3_3_IRQn, DMA3_4_IRQn, DMA3_5_IRQn, DMA3_6_IRQn, DMA3_7_IRQn, DMA3_8_IRQn, DMA3_9_IRQn, DMA3_10_IRQn, DMA3_11_IRQn, DMA3_12_IRQn, DMA3_13_IRQn, DMA3_14_IRQn, DMA3_15_IRQn, DMA3_16_IRQn, DMA3_17_IRQn, DMA3_18_IRQn, DMA3_19_IRQn, DMA3_20_IRQn, DMA3_21_IRQn, DMA3_22_IRQn, DMA3_23_IRQn, DMA3_24_IRQn, DMA3_25_IRQn, DMA3_26_IRQn, DMA3_27_IRQn, DMA3_28_IRQn, DMA3_29_IRQn, DMA3_30_IRQn } }
#define DMA_ERROR_IRQS                           { { DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn, DMA3_ERROR_IRQn } }

/* DMA5 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral EDMA5_2 base address */
  #define EDMA5_2_BASE                             (0x52800000u)
  /** Peripheral EDMA5_2 base address */
  #define EDMA5_2_BASE_NS                          (0x42800000u)
  /** Peripheral EDMA5_2 base pointer */
  #define EDMA5_2                                  ((DMA5_Type *)EDMA5_2_BASE)
  /** Peripheral EDMA5_2 base pointer */
  #define EDMA5_2_NS                               ((DMA5_Type *)EDMA5_2_BASE_NS)
  /** Peripheral EDMA5_3 base address */
  #define EDMA5_3_BASE                             (0x52A10000u)
  /** Peripheral EDMA5_3 base address */
  #define EDMA5_3_BASE_NS                          (0x42A10000u)
  /** Peripheral EDMA5_3 base pointer */
  #define EDMA5_3                                  ((DMA5_Type *)EDMA5_3_BASE)
  /** Peripheral EDMA5_3 base pointer */
  #define EDMA5_3_NS                               ((DMA5_Type *)EDMA5_3_BASE_NS)
  /** Array initializer of DMA5 peripheral base addresses */
  #define DMA5_BASE_ADDRS                          { 0u, 0u, EDMA5_2_BASE, EDMA5_3_BASE }
  /** Array initializer of DMA5 peripheral base pointers */
  #define DMA5_BASE_PTRS                           { (DMA5_Type *)0u, (DMA5_Type *)0u, EDMA5_2, EDMA5_3 }
  /** Array initializer of DMA5 peripheral base addresses */
  #define DMA5_BASE_ADDRS_NS                       { 0u, 0u, EDMA5_2_BASE_NS, EDMA5_3_BASE_NS }
  /** Array initializer of DMA5 peripheral base pointers */
  #define DMA5_BASE_PTRS_NS                        { (DMA5_Type *)0u, (DMA5_Type *)0u, EDMA5_2_NS, EDMA5_3_NS }
#else
  /** Peripheral EDMA5_2 base address */
  #define EDMA5_2_BASE                             (0x42800000u)
  /** Peripheral EDMA5_2 base pointer */
  #define EDMA5_2                                  ((DMA5_Type *)EDMA5_2_BASE)
  /** Peripheral EDMA5_3 base address */
  #define EDMA5_3_BASE                             (0x42A10000u)
  /** Peripheral EDMA5_3 base pointer */
  #define EDMA5_3                                  ((DMA5_Type *)EDMA5_3_BASE)
  /** Array initializer of DMA5 peripheral base addresses */
  #define DMA5_BASE_ADDRS                          { 0u, 0u, EDMA5_2_BASE, EDMA5_3_BASE }
  /** Array initializer of DMA5 peripheral base pointers */
  #define DMA5_BASE_PTRS                           { (DMA5_Type *)0u, (DMA5_Type *)0u, EDMA5_2, EDMA5_3 }
#endif

/* DMA_CRC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__DMA_CRC2 base address */
  #define WAKEUP__DMA_CRC2_BASE                    (0x523D0000u)
  /** Peripheral WAKEUP__DMA_CRC2 base address */
  #define WAKEUP__DMA_CRC2_BASE_NS                 (0x423D0000u)
  /** Peripheral WAKEUP__DMA_CRC2 base pointer */
  #define WAKEUP__DMA_CRC2                         ((DMA_CRC_Type *)WAKEUP__DMA_CRC2_BASE)
  /** Peripheral WAKEUP__DMA_CRC2 base pointer */
  #define WAKEUP__DMA_CRC2_NS                      ((DMA_CRC_Type *)WAKEUP__DMA_CRC2_BASE_NS)
  /** Peripheral WAKEUP__DMA_CRC3 base address */
  #define WAKEUP__DMA_CRC3_BASE                    (0x524F0000u)
  /** Peripheral WAKEUP__DMA_CRC3 base address */
  #define WAKEUP__DMA_CRC3_BASE_NS                 (0x424F0000u)
  /** Peripheral WAKEUP__DMA_CRC3 base pointer */
  #define WAKEUP__DMA_CRC3                         ((DMA_CRC_Type *)WAKEUP__DMA_CRC3_BASE)
  /** Peripheral WAKEUP__DMA_CRC3 base pointer */
  #define WAKEUP__DMA_CRC3_NS                      ((DMA_CRC_Type *)WAKEUP__DMA_CRC3_BASE_NS)
  /** Array initializer of DMA_CRC peripheral base addresses */
  #define DMA_CRC_BASE_ADDRS                       { WAKEUP__DMA_CRC2_BASE, WAKEUP__DMA_CRC3_BASE }
  /** Array initializer of DMA_CRC peripheral base pointers */
  #define DMA_CRC_BASE_PTRS                        { WAKEUP__DMA_CRC2, WAKEUP__DMA_CRC3 }
  /** Array initializer of DMA_CRC peripheral base addresses */
  #define DMA_CRC_BASE_ADDRS_NS                    { WAKEUP__DMA_CRC2_BASE_NS, WAKEUP__DMA_CRC3_BASE_NS }
  /** Array initializer of DMA_CRC peripheral base pointers */
  #define DMA_CRC_BASE_PTRS_NS                     { WAKEUP__DMA_CRC2_NS, WAKEUP__DMA_CRC3_NS }
#else
  /** Peripheral WAKEUP__DMA_CRC2 base address */
  #define WAKEUP__DMA_CRC2_BASE                    (0x423D0000u)
  /** Peripheral WAKEUP__DMA_CRC2 base pointer */
  #define WAKEUP__DMA_CRC2                         ((DMA_CRC_Type *)WAKEUP__DMA_CRC2_BASE)
  /** Peripheral WAKEUP__DMA_CRC3 base address */
  #define WAKEUP__DMA_CRC3_BASE                    (0x424F0000u)
  /** Peripheral WAKEUP__DMA_CRC3 base pointer */
  #define WAKEUP__DMA_CRC3                         ((DMA_CRC_Type *)WAKEUP__DMA_CRC3_BASE)
  /** Array initializer of DMA_CRC peripheral base addresses */
  #define DMA_CRC_BASE_ADDRS                       { WAKEUP__DMA_CRC2_BASE, WAKEUP__DMA_CRC3_BASE }
  /** Array initializer of DMA_CRC peripheral base pointers */
  #define DMA_CRC_BASE_PTRS                        { WAKEUP__DMA_CRC2, WAKEUP__DMA_CRC3 }
#endif

/* DOMAINB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__DOMAINB1 base address */
  #define DISPLAY__SEERIS__DOMAINB1_BASE           (0x5B730000u)
  /** Peripheral DISPLAY__SEERIS__DOMAINB1 base address */
  #define DISPLAY__SEERIS__DOMAINB1_BASE_NS        (0x4B730000u)
  /** Peripheral DISPLAY__SEERIS__DOMAINB1 base pointer */
  #define DISPLAY__SEERIS__DOMAINB1                ((DOMAINB_Type *)DISPLAY__SEERIS__DOMAINB1_BASE)
  /** Peripheral DISPLAY__SEERIS__DOMAINB1 base pointer */
  #define DISPLAY__SEERIS__DOMAINB1_NS             ((DOMAINB_Type *)DISPLAY__SEERIS__DOMAINB1_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__DOMAINBL base address */
  #define DISPLAY__SEERIS__DOMAINBL_BASE           (0x5B6A0000u)
  /** Peripheral DISPLAY__SEERIS__DOMAINBL base address */
  #define DISPLAY__SEERIS__DOMAINBL_BASE_NS        (0x4B6A0000u)
  /** Peripheral DISPLAY__SEERIS__DOMAINBL base pointer */
  #define DISPLAY__SEERIS__DOMAINBL                ((DOMAINB_Type *)DISPLAY__SEERIS__DOMAINBL_BASE)
  /** Peripheral DISPLAY__SEERIS__DOMAINBL base pointer */
  #define DISPLAY__SEERIS__DOMAINBL_NS             ((DOMAINB_Type *)DISPLAY__SEERIS__DOMAINBL_BASE_NS)
  /** Array initializer of DOMAINB peripheral base addresses */
  #define DOMAINB_BASE_ADDRS                       { DISPLAY__SEERIS__DOMAINB1_BASE, DISPLAY__SEERIS__DOMAINBL_BASE }
  /** Array initializer of DOMAINB peripheral base pointers */
  #define DOMAINB_BASE_PTRS                        { DISPLAY__SEERIS__DOMAINB1, DISPLAY__SEERIS__DOMAINBL }
  /** Array initializer of DOMAINB peripheral base addresses */
  #define DOMAINB_BASE_ADDRS_NS                    { DISPLAY__SEERIS__DOMAINB1_BASE_NS, DISPLAY__SEERIS__DOMAINBL_BASE_NS }
  /** Array initializer of DOMAINB peripheral base pointers */
  #define DOMAINB_BASE_PTRS_NS                     { DISPLAY__SEERIS__DOMAINB1_NS, DISPLAY__SEERIS__DOMAINBL_NS }
#else
  /** Peripheral DISPLAY__SEERIS__DOMAINB1 base address */
  #define DISPLAY__SEERIS__DOMAINB1_BASE           (0x4B730000u)
  /** Peripheral DISPLAY__SEERIS__DOMAINB1 base pointer */
  #define DISPLAY__SEERIS__DOMAINB1                ((DOMAINB_Type *)DISPLAY__SEERIS__DOMAINB1_BASE)
  /** Peripheral DISPLAY__SEERIS__DOMAINBL base address */
  #define DISPLAY__SEERIS__DOMAINBL_BASE           (0x4B6A0000u)
  /** Peripheral DISPLAY__SEERIS__DOMAINBL base pointer */
  #define DISPLAY__SEERIS__DOMAINBL                ((DOMAINB_Type *)DISPLAY__SEERIS__DOMAINBL_BASE)
  /** Array initializer of DOMAINB peripheral base addresses */
  #define DOMAINB_BASE_ADDRS                       { DISPLAY__SEERIS__DOMAINB1_BASE, DISPLAY__SEERIS__DOMAINBL_BASE }
  /** Array initializer of DOMAINB peripheral base pointers */
  #define DOMAINB_BASE_PTRS                        { DISPLAY__SEERIS__DOMAINB1, DISPLAY__SEERIS__DOMAINBL }
#endif

/* DOORBELLS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPU__REG__DOORBELLS base address */
  #define GPU__REG__DOORBELLS_BASE                 (0x5D980000u)
  /** Peripheral GPU__REG__DOORBELLS base address */
  #define GPU__REG__DOORBELLS_BASE_NS              (0x4D980000u)
  /** Peripheral GPU__REG__DOORBELLS base pointer */
  #define GPU__REG__DOORBELLS                      ((DOORBELLS_Type *)GPU__REG__DOORBELLS_BASE)
  /** Peripheral GPU__REG__DOORBELLS base pointer */
  #define GPU__REG__DOORBELLS_NS                   ((DOORBELLS_Type *)GPU__REG__DOORBELLS_BASE_NS)
  /** Array initializer of DOORBELLS peripheral base addresses */
  #define DOORBELLS_BASE_ADDRS                     { GPU__REG__DOORBELLS_BASE }
  /** Array initializer of DOORBELLS peripheral base pointers */
  #define DOORBELLS_BASE_PTRS                      { GPU__REG__DOORBELLS }
  /** Array initializer of DOORBELLS peripheral base addresses */
  #define DOORBELLS_BASE_ADDRS_NS                  { GPU__REG__DOORBELLS_BASE_NS }
  /** Array initializer of DOORBELLS peripheral base pointers */
  #define DOORBELLS_BASE_PTRS_NS                   { GPU__REG__DOORBELLS_NS }
#else
  /** Peripheral GPU__REG__DOORBELLS base address */
  #define GPU__REG__DOORBELLS_BASE                 (0x4D980000u)
  /** Peripheral GPU__REG__DOORBELLS base pointer */
  #define GPU__REG__DOORBELLS                      ((DOORBELLS_Type *)GPU__REG__DOORBELLS_BASE)
  /** Array initializer of DOORBELLS peripheral base addresses */
  #define DOORBELLS_BASE_ADDRS                     { GPU__REG__DOORBELLS_BASE }
  /** Array initializer of DOORBELLS peripheral base pointers */
  #define DOORBELLS_BASE_PTRS                      { GPU__REG__DOORBELLS }
#endif

/* DPU_IRQSTEER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DPU_IRQSTEER base address */
  #define DPU_IRQSTEER_BASE                        (0x5B0B0000u)
  /** Peripheral DPU_IRQSTEER base address */
  #define DPU_IRQSTEER_BASE_NS                     (0x4B0B0000u)
  /** Peripheral DPU_IRQSTEER base pointer */
  #define DPU_IRQSTEER                             ((DPU_IRQSTEER_Type *)DPU_IRQSTEER_BASE)
  /** Peripheral DPU_IRQSTEER base pointer */
  #define DPU_IRQSTEER_NS                          ((DPU_IRQSTEER_Type *)DPU_IRQSTEER_BASE_NS)
  /** Array initializer of DPU_IRQSTEER peripheral base addresses */
  #define DPU_IRQSTEER_BASE_ADDRS                  { DPU_IRQSTEER_BASE }
  /** Array initializer of DPU_IRQSTEER peripheral base pointers */
  #define DPU_IRQSTEER_BASE_PTRS                   { DPU_IRQSTEER }
  /** Array initializer of DPU_IRQSTEER peripheral base addresses */
  #define DPU_IRQSTEER_BASE_ADDRS_NS               { DPU_IRQSTEER_BASE_NS }
  /** Array initializer of DPU_IRQSTEER peripheral base pointers */
  #define DPU_IRQSTEER_BASE_PTRS_NS                { DPU_IRQSTEER_NS }
#else
  /** Peripheral DPU_IRQSTEER base address */
  #define DPU_IRQSTEER_BASE                        (0x4B0B0000u)
  /** Peripheral DPU_IRQSTEER base pointer */
  #define DPU_IRQSTEER                             ((DPU_IRQSTEER_Type *)DPU_IRQSTEER_BASE)
  /** Array initializer of DPU_IRQSTEER peripheral base addresses */
  #define DPU_IRQSTEER_BASE_ADDRS                  { DPU_IRQSTEER_BASE }
  /** Array initializer of DPU_IRQSTEER peripheral base pointers */
  #define DPU_IRQSTEER_BASE_PTRS                   { DPU_IRQSTEER }
#endif

/* DSI_V2_HOST_DSI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE (0x5B060200u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE_NS (0x4B060200u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI  ((DSI_V2_HOST_DSI_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_NS ((DSI_V2_HOST_DSI_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE_NS)
  /** Array initializer of DSI_V2_HOST_DSI peripheral base addresses */
  #define DSI_V2_HOST_DSI_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE }
  /** Array initializer of DSI_V2_HOST_DSI peripheral base pointers */
  #define DSI_V2_HOST_DSI_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI }
  /** Array initializer of DSI_V2_HOST_DSI peripheral base addresses */
  #define DSI_V2_HOST_DSI_BASE_ADDRS_NS            { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE_NS }
  /** Array initializer of DSI_V2_HOST_DSI peripheral base pointers */
  #define DSI_V2_HOST_DSI_BASE_PTRS_NS             { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_NS }
#else
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE (0x4B060200u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI  ((DSI_V2_HOST_DSI_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE)
  /** Array initializer of DSI_V2_HOST_DSI peripheral base addresses */
  #define DSI_V2_HOST_DSI_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI_BASE }
  /** Array initializer of DSI_V2_HOST_DSI peripheral base pointers */
  #define DSI_V2_HOST_DSI_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_DSI }
#endif

/* DSI_V2_HOST_INT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE (0x5B060400u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE_NS (0x4B060400u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT  ((DSI_V2_HOST_INT_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_NS ((DSI_V2_HOST_INT_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE_NS)
  /** Array initializer of DSI_V2_HOST_INT peripheral base addresses */
  #define DSI_V2_HOST_INT_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE }
  /** Array initializer of DSI_V2_HOST_INT peripheral base pointers */
  #define DSI_V2_HOST_INT_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT }
  /** Array initializer of DSI_V2_HOST_INT peripheral base addresses */
  #define DSI_V2_HOST_INT_BASE_ADDRS_NS            { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE_NS }
  /** Array initializer of DSI_V2_HOST_INT peripheral base pointers */
  #define DSI_V2_HOST_INT_BASE_PTRS_NS             { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_NS }
#else
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE (0x4B060400u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT  ((DSI_V2_HOST_INT_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE)
  /** Array initializer of DSI_V2_HOST_INT peripheral base addresses */
  #define DSI_V2_HOST_INT_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT_BASE }
  /** Array initializer of DSI_V2_HOST_INT peripheral base pointers */
  #define DSI_V2_HOST_INT_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_INT }
#endif

/* DSI_V2_HOST_IPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE (0x5B060300u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE_NS (0x4B060300u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI  ((DSI_V2_HOST_IPI_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_NS ((DSI_V2_HOST_IPI_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE_NS)
  /** Array initializer of DSI_V2_HOST_IPI peripheral base addresses */
  #define DSI_V2_HOST_IPI_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE }
  /** Array initializer of DSI_V2_HOST_IPI peripheral base pointers */
  #define DSI_V2_HOST_IPI_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI }
  /** Array initializer of DSI_V2_HOST_IPI peripheral base addresses */
  #define DSI_V2_HOST_IPI_BASE_ADDRS_NS            { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE_NS }
  /** Array initializer of DSI_V2_HOST_IPI peripheral base pointers */
  #define DSI_V2_HOST_IPI_BASE_PTRS_NS             { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_NS }
#else
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE (0x4B060300u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI  ((DSI_V2_HOST_IPI_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE)
  /** Array initializer of DSI_V2_HOST_IPI peripheral base addresses */
  #define DSI_V2_HOST_IPI_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI_BASE }
  /** Array initializer of DSI_V2_HOST_IPI peripheral base pointers */
  #define DSI_V2_HOST_IPI_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_IPI }
#endif

/* DSI_V2_HOST_MAIN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE (0x5B060000u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE_NS (0x4B060000u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN ((DSI_V2_HOST_MAIN_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_NS ((DSI_V2_HOST_MAIN_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE_NS)
  /** Array initializer of DSI_V2_HOST_MAIN peripheral base addresses */
  #define DSI_V2_HOST_MAIN_BASE_ADDRS              { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE }
  /** Array initializer of DSI_V2_HOST_MAIN peripheral base pointers */
  #define DSI_V2_HOST_MAIN_BASE_PTRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN }
  /** Array initializer of DSI_V2_HOST_MAIN peripheral base addresses */
  #define DSI_V2_HOST_MAIN_BASE_ADDRS_NS           { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE_NS }
  /** Array initializer of DSI_V2_HOST_MAIN peripheral base pointers */
  #define DSI_V2_HOST_MAIN_BASE_PTRS_NS            { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_NS }
#else
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE (0x4B060000u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN ((DSI_V2_HOST_MAIN_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE)
  /** Array initializer of DSI_V2_HOST_MAIN peripheral base addresses */
  #define DSI_V2_HOST_MAIN_BASE_ADDRS              { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN_BASE }
  /** Array initializer of DSI_V2_HOST_MAIN peripheral base pointers */
  #define DSI_V2_HOST_MAIN_BASE_PTRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_MAIN }
#endif

/* DSI_V2_HOST_PHY - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE (0x5B060100u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE_NS (0x4B060100u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY  ((DSI_V2_HOST_PHY_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_NS ((DSI_V2_HOST_PHY_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE_NS)
  /** Array initializer of DSI_V2_HOST_PHY peripheral base addresses */
  #define DSI_V2_HOST_PHY_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE }
  /** Array initializer of DSI_V2_HOST_PHY peripheral base pointers */
  #define DSI_V2_HOST_PHY_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY }
  /** Array initializer of DSI_V2_HOST_PHY peripheral base addresses */
  #define DSI_V2_HOST_PHY_BASE_ADDRS_NS            { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE_NS }
  /** Array initializer of DSI_V2_HOST_PHY peripheral base pointers */
  #define DSI_V2_HOST_PHY_BASE_PTRS_NS             { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_NS }
#else
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY base address */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE (0x4B060100u)
  /** Peripheral DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY base pointer */
  #define DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY  ((DSI_V2_HOST_PHY_Type *)DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE)
  /** Array initializer of DSI_V2_HOST_PHY peripheral base addresses */
  #define DSI_V2_HOST_PHY_BASE_ADDRS               { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY_BASE }
  /** Array initializer of DSI_V2_HOST_PHY peripheral base pointers */
  #define DSI_V2_HOST_PHY_BASE_PTRS                { DISPLAY__MIPI_DSI_HOST__DSI_V2_HOST_PHY }
#endif

/* EMDIO_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__EMDIO_GLOBAL base address */
  #define NETC__NETC__EMDIO_GLOBAL_BASE            (0x5CCB0000u)
  /** Peripheral NETC__NETC__EMDIO_GLOBAL base address */
  #define NETC__NETC__EMDIO_GLOBAL_BASE_NS         (0x4CCB0000u)
  /** Peripheral NETC__NETC__EMDIO_GLOBAL base pointer */
  #define NETC__NETC__EMDIO_GLOBAL                 ((EMDIO_GLOBAL_Type *)NETC__NETC__EMDIO_GLOBAL_BASE)
  /** Peripheral NETC__NETC__EMDIO_GLOBAL base pointer */
  #define NETC__NETC__EMDIO_GLOBAL_NS              ((EMDIO_GLOBAL_Type *)NETC__NETC__EMDIO_GLOBAL_BASE_NS)
  /** Array initializer of EMDIO_GLOBAL peripheral base addresses */
  #define EMDIO_GLOBAL_BASE_ADDRS                  { NETC__NETC__EMDIO_GLOBAL_BASE }
  /** Array initializer of EMDIO_GLOBAL peripheral base pointers */
  #define EMDIO_GLOBAL_BASE_PTRS                   { NETC__NETC__EMDIO_GLOBAL }
  /** Array initializer of EMDIO_GLOBAL peripheral base addresses */
  #define EMDIO_GLOBAL_BASE_ADDRS_NS               { NETC__NETC__EMDIO_GLOBAL_BASE_NS }
  /** Array initializer of EMDIO_GLOBAL peripheral base pointers */
  #define EMDIO_GLOBAL_BASE_PTRS_NS                { NETC__NETC__EMDIO_GLOBAL_NS }
#else
  /** Peripheral NETC__NETC__EMDIO_GLOBAL base address */
  #define NETC__NETC__EMDIO_GLOBAL_BASE            (0x4CCB0000u)
  /** Peripheral NETC__NETC__EMDIO_GLOBAL base pointer */
  #define NETC__NETC__EMDIO_GLOBAL                 ((EMDIO_GLOBAL_Type *)NETC__NETC__EMDIO_GLOBAL_BASE)
  /** Array initializer of EMDIO_GLOBAL peripheral base addresses */
  #define EMDIO_GLOBAL_BASE_ADDRS                  { NETC__NETC__EMDIO_GLOBAL_BASE }
  /** Array initializer of EMDIO_GLOBAL peripheral base pointers */
  #define EMDIO_GLOBAL_BASE_PTRS                   { NETC__NETC__EMDIO_GLOBAL }
#endif

/* EMDIO_PCI_HDR_TYPE0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__EMDIO0_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__EMDIO0_PCI_HDR_TYPE0_BASE    (0x5CA02000u)
  /** Peripheral NETC__NETC__EMDIO0_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__EMDIO0_PCI_HDR_TYPE0_BASE_NS (0x4CA02000u)
  /** Peripheral NETC__NETC__EMDIO0_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__EMDIO0_PCI_HDR_TYPE0         ((EMDIO_PCI_HDR_TYPE0_Type *)NETC__NETC__EMDIO0_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__NETC__EMDIO0_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__EMDIO0_PCI_HDR_TYPE0_NS      ((EMDIO_PCI_HDR_TYPE0_Type *)NETC__NETC__EMDIO0_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of EMDIO_PCI_HDR_TYPE0 peripheral base addresses */
  #define EMDIO_PCI_HDR_TYPE0_BASE_ADDRS           { NETC__NETC__EMDIO0_PCI_HDR_TYPE0_BASE }
  /** Array initializer of EMDIO_PCI_HDR_TYPE0 peripheral base pointers */
  #define EMDIO_PCI_HDR_TYPE0_BASE_PTRS            { NETC__NETC__EMDIO0_PCI_HDR_TYPE0 }
  /** Array initializer of EMDIO_PCI_HDR_TYPE0 peripheral base addresses */
  #define EMDIO_PCI_HDR_TYPE0_BASE_ADDRS_NS        { NETC__NETC__EMDIO0_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of EMDIO_PCI_HDR_TYPE0 peripheral base pointers */
  #define EMDIO_PCI_HDR_TYPE0_BASE_PTRS_NS         { NETC__NETC__EMDIO0_PCI_HDR_TYPE0_NS }
#else
  /** Peripheral NETC__NETC__EMDIO0_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__EMDIO0_PCI_HDR_TYPE0_BASE    (0x4CA02000u)
  /** Peripheral NETC__NETC__EMDIO0_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__EMDIO0_PCI_HDR_TYPE0         ((EMDIO_PCI_HDR_TYPE0_Type *)NETC__NETC__EMDIO0_PCI_HDR_TYPE0_BASE)
  /** Array initializer of EMDIO_PCI_HDR_TYPE0 peripheral base addresses */
  #define EMDIO_PCI_HDR_TYPE0_BASE_ADDRS           { NETC__NETC__EMDIO0_PCI_HDR_TYPE0_BASE }
  /** Array initializer of EMDIO_PCI_HDR_TYPE0 peripheral base pointers */
  #define EMDIO_PCI_HDR_TYPE0_BASE_PTRS            { NETC__NETC__EMDIO0_PCI_HDR_TYPE0 }
#endif

/* ENETC_BASE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__ENETC0_BASE base address */
  #define NETC__NETC__ENETC0_BASE_BASE             (0x5CC10000u)
  /** Peripheral NETC__NETC__ENETC0_BASE base address */
  #define NETC__NETC__ENETC0_BASE_BASE_NS          (0x4CC10000u)
  /** Peripheral NETC__NETC__ENETC0_BASE base pointer */
  #define NETC__NETC__ENETC0_BASE                  ((ENETC_BASE_Type *)NETC__NETC__ENETC0_BASE_BASE)
  /** Peripheral NETC__NETC__ENETC0_BASE base pointer */
  #define NETC__NETC__ENETC0_BASE_NS               ((ENETC_BASE_Type *)NETC__NETC__ENETC0_BASE_BASE_NS)
  /** Peripheral NETC__NETC__ENETC1_BASE base address */
  #define NETC__NETC__ENETC1_BASE_BASE             (0x5CC50000u)
  /** Peripheral NETC__NETC__ENETC1_BASE base address */
  #define NETC__NETC__ENETC1_BASE_BASE_NS          (0x4CC50000u)
  /** Peripheral NETC__NETC__ENETC1_BASE base pointer */
  #define NETC__NETC__ENETC1_BASE                  ((ENETC_BASE_Type *)NETC__NETC__ENETC1_BASE_BASE)
  /** Peripheral NETC__NETC__ENETC1_BASE base pointer */
  #define NETC__NETC__ENETC1_BASE_NS               ((ENETC_BASE_Type *)NETC__NETC__ENETC1_BASE_BASE_NS)
  /** Array initializer of ENETC_BASE peripheral base addresses */
  #define ENETC_BASE_BASE_ADDRS                    { NETC__NETC__ENETC0_BASE_BASE, NETC__NETC__ENETC1_BASE_BASE }
  /** Array initializer of ENETC_BASE peripheral base pointers */
  #define ENETC_BASE_BASE_PTRS                     { NETC__NETC__ENETC0_BASE, NETC__NETC__ENETC1_BASE }
  /** Array initializer of ENETC_BASE peripheral base addresses */
  #define ENETC_BASE_BASE_ADDRS_NS                 { NETC__NETC__ENETC0_BASE_BASE_NS, NETC__NETC__ENETC1_BASE_BASE_NS }
  /** Array initializer of ENETC_BASE peripheral base pointers */
  #define ENETC_BASE_BASE_PTRS_NS                  { NETC__NETC__ENETC0_BASE_NS, NETC__NETC__ENETC1_BASE_NS }
#else
  /** Peripheral NETC__NETC__ENETC0_BASE base address */
  #define NETC__NETC__ENETC0_BASE_BASE             (0x4CC10000u)
  /** Peripheral NETC__NETC__ENETC0_BASE base pointer */
  #define NETC__NETC__ENETC0_BASE                  ((ENETC_BASE_Type *)NETC__NETC__ENETC0_BASE_BASE)
  /** Peripheral NETC__NETC__ENETC1_BASE base address */
  #define NETC__NETC__ENETC1_BASE_BASE             (0x4CC50000u)
  /** Peripheral NETC__NETC__ENETC1_BASE base pointer */
  #define NETC__NETC__ENETC1_BASE                  ((ENETC_BASE_Type *)NETC__NETC__ENETC1_BASE_BASE)
  /** Array initializer of ENETC_BASE peripheral base addresses */
  #define ENETC_BASE_BASE_ADDRS                    { NETC__NETC__ENETC0_BASE_BASE, NETC__NETC__ENETC1_BASE_BASE }
  /** Array initializer of ENETC_BASE peripheral base pointers */
  #define ENETC_BASE_BASE_PTRS                     { NETC__NETC__ENETC0_BASE, NETC__NETC__ENETC1_BASE }
#endif

/* ENETC_COMMON - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__ENETC0_COMMON base address */
  #define NETC__NETC__ENETC0_COMMON_BASE           (0x5CC11000u)
  /** Peripheral NETC__NETC__ENETC0_COMMON base address */
  #define NETC__NETC__ENETC0_COMMON_BASE_NS        (0x4CC11000u)
  /** Peripheral NETC__NETC__ENETC0_COMMON base pointer */
  #define NETC__NETC__ENETC0_COMMON                ((ENETC_COMMON_Type *)NETC__NETC__ENETC0_COMMON_BASE)
  /** Peripheral NETC__NETC__ENETC0_COMMON base pointer */
  #define NETC__NETC__ENETC0_COMMON_NS             ((ENETC_COMMON_Type *)NETC__NETC__ENETC0_COMMON_BASE_NS)
  /** Peripheral NETC__NETC__ENETC1_COMMON base address */
  #define NETC__NETC__ENETC1_COMMON_BASE           (0x5CC51000u)
  /** Peripheral NETC__NETC__ENETC1_COMMON base address */
  #define NETC__NETC__ENETC1_COMMON_BASE_NS        (0x4CC51000u)
  /** Peripheral NETC__NETC__ENETC1_COMMON base pointer */
  #define NETC__NETC__ENETC1_COMMON                ((ENETC_COMMON_Type *)NETC__NETC__ENETC1_COMMON_BASE)
  /** Peripheral NETC__NETC__ENETC1_COMMON base pointer */
  #define NETC__NETC__ENETC1_COMMON_NS             ((ENETC_COMMON_Type *)NETC__NETC__ENETC1_COMMON_BASE_NS)
  /** Array initializer of ENETC_COMMON peripheral base addresses */
  #define ENETC_COMMON_BASE_ADDRS                  { NETC__NETC__ENETC0_COMMON_BASE, NETC__NETC__ENETC1_COMMON_BASE }
  /** Array initializer of ENETC_COMMON peripheral base pointers */
  #define ENETC_COMMON_BASE_PTRS                   { NETC__NETC__ENETC0_COMMON, NETC__NETC__ENETC1_COMMON }
  /** Array initializer of ENETC_COMMON peripheral base addresses */
  #define ENETC_COMMON_BASE_ADDRS_NS               { NETC__NETC__ENETC0_COMMON_BASE_NS, NETC__NETC__ENETC1_COMMON_BASE_NS }
  /** Array initializer of ENETC_COMMON peripheral base pointers */
  #define ENETC_COMMON_BASE_PTRS_NS                { NETC__NETC__ENETC0_COMMON_NS, NETC__NETC__ENETC1_COMMON_NS }
#else
  /** Peripheral NETC__NETC__ENETC0_COMMON base address */
  #define NETC__NETC__ENETC0_COMMON_BASE           (0x4CC11000u)
  /** Peripheral NETC__NETC__ENETC0_COMMON base pointer */
  #define NETC__NETC__ENETC0_COMMON                ((ENETC_COMMON_Type *)NETC__NETC__ENETC0_COMMON_BASE)
  /** Peripheral NETC__NETC__ENETC1_COMMON base address */
  #define NETC__NETC__ENETC1_COMMON_BASE           (0x4CC51000u)
  /** Peripheral NETC__NETC__ENETC1_COMMON base pointer */
  #define NETC__NETC__ENETC1_COMMON                ((ENETC_COMMON_Type *)NETC__NETC__ENETC1_COMMON_BASE)
  /** Array initializer of ENETC_COMMON peripheral base addresses */
  #define ENETC_COMMON_BASE_ADDRS                  { NETC__NETC__ENETC0_COMMON_BASE, NETC__NETC__ENETC1_COMMON_BASE }
  /** Array initializer of ENETC_COMMON peripheral base pointers */
  #define ENETC_COMMON_BASE_PTRS                   { NETC__NETC__ENETC0_COMMON, NETC__NETC__ENETC1_COMMON }
#endif

/* ENETC_ETH_MAC_PORT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__ENETC0_ETH_MAC_PORT base address */
  #define NETC__NETC__ENETC0_ETH_MAC_PORT_BASE     (0x5CC15000u)
  /** Peripheral NETC__NETC__ENETC0_ETH_MAC_PORT base address */
  #define NETC__NETC__ENETC0_ETH_MAC_PORT_BASE_NS  (0x4CC15000u)
  /** Peripheral NETC__NETC__ENETC0_ETH_MAC_PORT base pointer */
  #define NETC__NETC__ENETC0_ETH_MAC_PORT          ((ENETC_ETH_MAC_PORT_Type *)NETC__NETC__ENETC0_ETH_MAC_PORT_BASE)
  /** Peripheral NETC__NETC__ENETC0_ETH_MAC_PORT base pointer */
  #define NETC__NETC__ENETC0_ETH_MAC_PORT_NS       ((ENETC_ETH_MAC_PORT_Type *)NETC__NETC__ENETC0_ETH_MAC_PORT_BASE_NS)
  /** Peripheral NETC__NETC__ENETC1_ETH_MAC_PORT base address */
  #define NETC__NETC__ENETC1_ETH_MAC_PORT_BASE     (0x5CC55000u)
  /** Peripheral NETC__NETC__ENETC1_ETH_MAC_PORT base address */
  #define NETC__NETC__ENETC1_ETH_MAC_PORT_BASE_NS  (0x4CC55000u)
  /** Peripheral NETC__NETC__ENETC1_ETH_MAC_PORT base pointer */
  #define NETC__NETC__ENETC1_ETH_MAC_PORT          ((ENETC_ETH_MAC_PORT_Type *)NETC__NETC__ENETC1_ETH_MAC_PORT_BASE)
  /** Peripheral NETC__NETC__ENETC1_ETH_MAC_PORT base pointer */
  #define NETC__NETC__ENETC1_ETH_MAC_PORT_NS       ((ENETC_ETH_MAC_PORT_Type *)NETC__NETC__ENETC1_ETH_MAC_PORT_BASE_NS)
  /** Array initializer of ENETC_ETH_MAC_PORT peripheral base addresses */
  #define ENETC_ETH_MAC_PORT_BASE_ADDRS            { NETC__NETC__ENETC0_ETH_MAC_PORT_BASE, NETC__NETC__ENETC1_ETH_MAC_PORT_BASE }
  /** Array initializer of ENETC_ETH_MAC_PORT peripheral base pointers */
  #define ENETC_ETH_MAC_PORT_BASE_PTRS             { NETC__NETC__ENETC0_ETH_MAC_PORT, NETC__NETC__ENETC1_ETH_MAC_PORT }
  /** Array initializer of ENETC_ETH_MAC_PORT peripheral base addresses */
  #define ENETC_ETH_MAC_PORT_BASE_ADDRS_NS         { NETC__NETC__ENETC0_ETH_MAC_PORT_BASE_NS, NETC__NETC__ENETC1_ETH_MAC_PORT_BASE_NS }
  /** Array initializer of ENETC_ETH_MAC_PORT peripheral base pointers */
  #define ENETC_ETH_MAC_PORT_BASE_PTRS_NS          { NETC__NETC__ENETC0_ETH_MAC_PORT_NS, NETC__NETC__ENETC1_ETH_MAC_PORT_NS }
#else
  /** Peripheral NETC__NETC__ENETC0_ETH_MAC_PORT base address */
  #define NETC__NETC__ENETC0_ETH_MAC_PORT_BASE     (0x4CC15000u)
  /** Peripheral NETC__NETC__ENETC0_ETH_MAC_PORT base pointer */
  #define NETC__NETC__ENETC0_ETH_MAC_PORT          ((ENETC_ETH_MAC_PORT_Type *)NETC__NETC__ENETC0_ETH_MAC_PORT_BASE)
  /** Peripheral NETC__NETC__ENETC1_ETH_MAC_PORT base address */
  #define NETC__NETC__ENETC1_ETH_MAC_PORT_BASE     (0x4CC55000u)
  /** Peripheral NETC__NETC__ENETC1_ETH_MAC_PORT base pointer */
  #define NETC__NETC__ENETC1_ETH_MAC_PORT          ((ENETC_ETH_MAC_PORT_Type *)NETC__NETC__ENETC1_ETH_MAC_PORT_BASE)
  /** Array initializer of ENETC_ETH_MAC_PORT peripheral base addresses */
  #define ENETC_ETH_MAC_PORT_BASE_ADDRS            { NETC__NETC__ENETC0_ETH_MAC_PORT_BASE, NETC__NETC__ENETC1_ETH_MAC_PORT_BASE }
  /** Array initializer of ENETC_ETH_MAC_PORT peripheral base pointers */
  #define ENETC_ETH_MAC_PORT_BASE_PTRS             { NETC__NETC__ENETC0_ETH_MAC_PORT, NETC__NETC__ENETC1_ETH_MAC_PORT }
#endif

/* ENETC_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__ENETC0_GLOBAL base address */
  #define NETC__NETC__ENETC0_GLOBAL_BASE           (0x5CC20000u)
  /** Peripheral NETC__NETC__ENETC0_GLOBAL base address */
  #define NETC__NETC__ENETC0_GLOBAL_BASE_NS        (0x4CC20000u)
  /** Peripheral NETC__NETC__ENETC0_GLOBAL base pointer */
  #define NETC__NETC__ENETC0_GLOBAL                ((ENETC_GLOBAL_Type *)NETC__NETC__ENETC0_GLOBAL_BASE)
  /** Peripheral NETC__NETC__ENETC0_GLOBAL base pointer */
  #define NETC__NETC__ENETC0_GLOBAL_NS             ((ENETC_GLOBAL_Type *)NETC__NETC__ENETC0_GLOBAL_BASE_NS)
  /** Peripheral NETC__NETC__ENETC1_GLOBAL base address */
  #define NETC__NETC__ENETC1_GLOBAL_BASE           (0x5CC60000u)
  /** Peripheral NETC__NETC__ENETC1_GLOBAL base address */
  #define NETC__NETC__ENETC1_GLOBAL_BASE_NS        (0x4CC60000u)
  /** Peripheral NETC__NETC__ENETC1_GLOBAL base pointer */
  #define NETC__NETC__ENETC1_GLOBAL                ((ENETC_GLOBAL_Type *)NETC__NETC__ENETC1_GLOBAL_BASE)
  /** Peripheral NETC__NETC__ENETC1_GLOBAL base pointer */
  #define NETC__NETC__ENETC1_GLOBAL_NS             ((ENETC_GLOBAL_Type *)NETC__NETC__ENETC1_GLOBAL_BASE_NS)
  /** Array initializer of ENETC_GLOBAL peripheral base addresses */
  #define ENETC_GLOBAL_BASE_ADDRS                  { NETC__NETC__ENETC0_GLOBAL_BASE, NETC__NETC__ENETC1_GLOBAL_BASE }
  /** Array initializer of ENETC_GLOBAL peripheral base pointers */
  #define ENETC_GLOBAL_BASE_PTRS                   { NETC__NETC__ENETC0_GLOBAL, NETC__NETC__ENETC1_GLOBAL }
  /** Array initializer of ENETC_GLOBAL peripheral base addresses */
  #define ENETC_GLOBAL_BASE_ADDRS_NS               { NETC__NETC__ENETC0_GLOBAL_BASE_NS, NETC__NETC__ENETC1_GLOBAL_BASE_NS }
  /** Array initializer of ENETC_GLOBAL peripheral base pointers */
  #define ENETC_GLOBAL_BASE_PTRS_NS                { NETC__NETC__ENETC0_GLOBAL_NS, NETC__NETC__ENETC1_GLOBAL_NS }
#else
  /** Peripheral NETC__NETC__ENETC0_GLOBAL base address */
  #define NETC__NETC__ENETC0_GLOBAL_BASE           (0x4CC20000u)
  /** Peripheral NETC__NETC__ENETC0_GLOBAL base pointer */
  #define NETC__NETC__ENETC0_GLOBAL                ((ENETC_GLOBAL_Type *)NETC__NETC__ENETC0_GLOBAL_BASE)
  /** Peripheral NETC__NETC__ENETC1_GLOBAL base address */
  #define NETC__NETC__ENETC1_GLOBAL_BASE           (0x4CC60000u)
  /** Peripheral NETC__NETC__ENETC1_GLOBAL base pointer */
  #define NETC__NETC__ENETC1_GLOBAL                ((ENETC_GLOBAL_Type *)NETC__NETC__ENETC1_GLOBAL_BASE)
  /** Array initializer of ENETC_GLOBAL peripheral base addresses */
  #define ENETC_GLOBAL_BASE_ADDRS                  { NETC__NETC__ENETC0_GLOBAL_BASE, NETC__NETC__ENETC1_GLOBAL_BASE }
  /** Array initializer of ENETC_GLOBAL peripheral base pointers */
  #define ENETC_GLOBAL_BASE_PTRS                   { NETC__NETC__ENETC0_GLOBAL, NETC__NETC__ENETC1_GLOBAL }
#endif

/* ENETC_PCI_HDR_TYPE0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__ENETC0_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__ENETC0_PCI_HDR_TYPE0_BASE    (0x5CA00000u)
  /** Peripheral NETC__NETC__ENETC0_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__ENETC0_PCI_HDR_TYPE0_BASE_NS (0x4CA00000u)
  /** Peripheral NETC__NETC__ENETC0_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__ENETC0_PCI_HDR_TYPE0         ((ENETC_PCI_HDR_TYPE0_Type *)NETC__NETC__ENETC0_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__NETC__ENETC0_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__ENETC0_PCI_HDR_TYPE0_NS      ((ENETC_PCI_HDR_TYPE0_Type *)NETC__NETC__ENETC0_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral NETC__NETC__ENETC1_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__ENETC1_PCI_HDR_TYPE0_BASE    (0x5CB00000u)
  /** Peripheral NETC__NETC__ENETC1_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__ENETC1_PCI_HDR_TYPE0_BASE_NS (0x4CB00000u)
  /** Peripheral NETC__NETC__ENETC1_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__ENETC1_PCI_HDR_TYPE0         ((ENETC_PCI_HDR_TYPE0_Type *)NETC__NETC__ENETC1_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__NETC__ENETC1_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__ENETC1_PCI_HDR_TYPE0_NS      ((ENETC_PCI_HDR_TYPE0_Type *)NETC__NETC__ENETC1_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of ENETC_PCI_HDR_TYPE0 peripheral base addresses */
  #define ENETC_PCI_HDR_TYPE0_BASE_ADDRS           { NETC__NETC__ENETC0_PCI_HDR_TYPE0_BASE, NETC__NETC__ENETC1_PCI_HDR_TYPE0_BASE }
  /** Array initializer of ENETC_PCI_HDR_TYPE0 peripheral base pointers */
  #define ENETC_PCI_HDR_TYPE0_BASE_PTRS            { NETC__NETC__ENETC0_PCI_HDR_TYPE0, NETC__NETC__ENETC1_PCI_HDR_TYPE0 }
  /** Array initializer of ENETC_PCI_HDR_TYPE0 peripheral base addresses */
  #define ENETC_PCI_HDR_TYPE0_BASE_ADDRS_NS        { NETC__NETC__ENETC0_PCI_HDR_TYPE0_BASE_NS, NETC__NETC__ENETC1_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of ENETC_PCI_HDR_TYPE0 peripheral base pointers */
  #define ENETC_PCI_HDR_TYPE0_BASE_PTRS_NS         { NETC__NETC__ENETC0_PCI_HDR_TYPE0_NS, NETC__NETC__ENETC1_PCI_HDR_TYPE0_NS }
#else
  /** Peripheral NETC__NETC__ENETC0_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__ENETC0_PCI_HDR_TYPE0_BASE    (0x4CA00000u)
  /** Peripheral NETC__NETC__ENETC0_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__ENETC0_PCI_HDR_TYPE0         ((ENETC_PCI_HDR_TYPE0_Type *)NETC__NETC__ENETC0_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__NETC__ENETC1_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__ENETC1_PCI_HDR_TYPE0_BASE    (0x4CB00000u)
  /** Peripheral NETC__NETC__ENETC1_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__ENETC1_PCI_HDR_TYPE0         ((ENETC_PCI_HDR_TYPE0_Type *)NETC__NETC__ENETC1_PCI_HDR_TYPE0_BASE)
  /** Array initializer of ENETC_PCI_HDR_TYPE0 peripheral base addresses */
  #define ENETC_PCI_HDR_TYPE0_BASE_ADDRS           { NETC__NETC__ENETC0_PCI_HDR_TYPE0_BASE, NETC__NETC__ENETC1_PCI_HDR_TYPE0_BASE }
  /** Array initializer of ENETC_PCI_HDR_TYPE0 peripheral base pointers */
  #define ENETC_PCI_HDR_TYPE0_BASE_PTRS            { NETC__NETC__ENETC0_PCI_HDR_TYPE0, NETC__NETC__ENETC1_PCI_HDR_TYPE0 }
#endif

/* ENETC_PORT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__ENETC0_PORT base address */
  #define NETC__NETC__ENETC0_PORT_BASE             (0x5CC14000u)
  /** Peripheral NETC__NETC__ENETC0_PORT base address */
  #define NETC__NETC__ENETC0_PORT_BASE_NS          (0x4CC14000u)
  /** Peripheral NETC__NETC__ENETC0_PORT base pointer */
  #define NETC__NETC__ENETC0_PORT                  ((ENETC_PORT_Type *)NETC__NETC__ENETC0_PORT_BASE)
  /** Peripheral NETC__NETC__ENETC0_PORT base pointer */
  #define NETC__NETC__ENETC0_PORT_NS               ((ENETC_PORT_Type *)NETC__NETC__ENETC0_PORT_BASE_NS)
  /** Peripheral NETC__NETC__ENETC1_PORT base address */
  #define NETC__NETC__ENETC1_PORT_BASE             (0x5CC54000u)
  /** Peripheral NETC__NETC__ENETC1_PORT base address */
  #define NETC__NETC__ENETC1_PORT_BASE_NS          (0x4CC54000u)
  /** Peripheral NETC__NETC__ENETC1_PORT base pointer */
  #define NETC__NETC__ENETC1_PORT                  ((ENETC_PORT_Type *)NETC__NETC__ENETC1_PORT_BASE)
  /** Peripheral NETC__NETC__ENETC1_PORT base pointer */
  #define NETC__NETC__ENETC1_PORT_NS               ((ENETC_PORT_Type *)NETC__NETC__ENETC1_PORT_BASE_NS)
  /** Array initializer of ENETC_PORT peripheral base addresses */
  #define ENETC_PORT_BASE_ADDRS                    { NETC__NETC__ENETC0_PORT_BASE, NETC__NETC__ENETC1_PORT_BASE }
  /** Array initializer of ENETC_PORT peripheral base pointers */
  #define ENETC_PORT_BASE_PTRS                     { NETC__NETC__ENETC0_PORT, NETC__NETC__ENETC1_PORT }
  /** Array initializer of ENETC_PORT peripheral base addresses */
  #define ENETC_PORT_BASE_ADDRS_NS                 { NETC__NETC__ENETC0_PORT_BASE_NS, NETC__NETC__ENETC1_PORT_BASE_NS }
  /** Array initializer of ENETC_PORT peripheral base pointers */
  #define ENETC_PORT_BASE_PTRS_NS                  { NETC__NETC__ENETC0_PORT_NS, NETC__NETC__ENETC1_PORT_NS }
#else
  /** Peripheral NETC__NETC__ENETC0_PORT base address */
  #define NETC__NETC__ENETC0_PORT_BASE             (0x4CC14000u)
  /** Peripheral NETC__NETC__ENETC0_PORT base pointer */
  #define NETC__NETC__ENETC0_PORT                  ((ENETC_PORT_Type *)NETC__NETC__ENETC0_PORT_BASE)
  /** Peripheral NETC__NETC__ENETC1_PORT base address */
  #define NETC__NETC__ENETC1_PORT_BASE             (0x4CC54000u)
  /** Peripheral NETC__NETC__ENETC1_PORT base pointer */
  #define NETC__NETC__ENETC1_PORT                  ((ENETC_PORT_Type *)NETC__NETC__ENETC1_PORT_BASE)
  /** Array initializer of ENETC_PORT peripheral base addresses */
  #define ENETC_PORT_BASE_ADDRS                    { NETC__NETC__ENETC0_PORT_BASE, NETC__NETC__ENETC1_PORT_BASE }
  /** Array initializer of ENETC_PORT peripheral base pointers */
  #define ENETC_PORT_BASE_PTRS                     { NETC__NETC__ENETC0_PORT, NETC__NETC__ENETC1_PORT }
#endif

/* ENETC_PSI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__ENETC0_PSI base address */
  #define NETC__NETC__ENETC0_PSI_BASE              (0x5CC00000u)
  /** Peripheral NETC__NETC__ENETC0_PSI base address */
  #define NETC__NETC__ENETC0_PSI_BASE_NS           (0x4CC00000u)
  /** Peripheral NETC__NETC__ENETC0_PSI base pointer */
  #define NETC__NETC__ENETC0_PSI                   ((ENETC_PSI_Type *)NETC__NETC__ENETC0_PSI_BASE)
  /** Peripheral NETC__NETC__ENETC0_PSI base pointer */
  #define NETC__NETC__ENETC0_PSI_NS                ((ENETC_PSI_Type *)NETC__NETC__ENETC0_PSI_BASE_NS)
  /** Peripheral NETC__NETC__ENETC1_PSI base address */
  #define NETC__NETC__ENETC1_PSI_BASE              (0x5CC40000u)
  /** Peripheral NETC__NETC__ENETC1_PSI base address */
  #define NETC__NETC__ENETC1_PSI_BASE_NS           (0x4CC40000u)
  /** Peripheral NETC__NETC__ENETC1_PSI base pointer */
  #define NETC__NETC__ENETC1_PSI                   ((ENETC_PSI_Type *)NETC__NETC__ENETC1_PSI_BASE)
  /** Peripheral NETC__NETC__ENETC1_PSI base pointer */
  #define NETC__NETC__ENETC1_PSI_NS                ((ENETC_PSI_Type *)NETC__NETC__ENETC1_PSI_BASE_NS)
  /** Array initializer of ENETC_PSI peripheral base addresses */
  #define ENETC_PSI_BASE_ADDRS                     { NETC__NETC__ENETC0_PSI_BASE, NETC__NETC__ENETC1_PSI_BASE }
  /** Array initializer of ENETC_PSI peripheral base pointers */
  #define ENETC_PSI_BASE_PTRS                      { NETC__NETC__ENETC0_PSI, NETC__NETC__ENETC1_PSI }
  /** Array initializer of ENETC_PSI peripheral base addresses */
  #define ENETC_PSI_BASE_ADDRS_NS                  { NETC__NETC__ENETC0_PSI_BASE_NS, NETC__NETC__ENETC1_PSI_BASE_NS }
  /** Array initializer of ENETC_PSI peripheral base pointers */
  #define ENETC_PSI_BASE_PTRS_NS                   { NETC__NETC__ENETC0_PSI_NS, NETC__NETC__ENETC1_PSI_NS }
#else
  /** Peripheral NETC__NETC__ENETC0_PSI base address */
  #define NETC__NETC__ENETC0_PSI_BASE              (0x4CC00000u)
  /** Peripheral NETC__NETC__ENETC0_PSI base pointer */
  #define NETC__NETC__ENETC0_PSI                   ((ENETC_PSI_Type *)NETC__NETC__ENETC0_PSI_BASE)
  /** Peripheral NETC__NETC__ENETC1_PSI base address */
  #define NETC__NETC__ENETC1_PSI_BASE              (0x4CC40000u)
  /** Peripheral NETC__NETC__ENETC1_PSI base pointer */
  #define NETC__NETC__ENETC1_PSI                   ((ENETC_PSI_Type *)NETC__NETC__ENETC1_PSI_BASE)
  /** Array initializer of ENETC_PSI peripheral base addresses */
  #define ENETC_PSI_BASE_ADDRS                     { NETC__NETC__ENETC0_PSI_BASE, NETC__NETC__ENETC1_PSI_BASE }
  /** Array initializer of ENETC_PSI peripheral base pointers */
  #define ENETC_PSI_BASE_PTRS                      { NETC__NETC__ENETC0_PSI, NETC__NETC__ENETC1_PSI }
#endif

/* ENETC_VSI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__ENETC_VSI0 base address */
  #define NETC__NETC__ENETC_VSI0_BASE              (0x5CCE0000u)
  /** Peripheral NETC__NETC__ENETC_VSI0 base address */
  #define NETC__NETC__ENETC_VSI0_BASE_NS           (0x4CCE0000u)
  /** Peripheral NETC__NETC__ENETC_VSI0 base pointer */
  #define NETC__NETC__ENETC_VSI0                   ((ENETC_VSI_Type *)NETC__NETC__ENETC_VSI0_BASE)
  /** Peripheral NETC__NETC__ENETC_VSI0 base pointer */
  #define NETC__NETC__ENETC_VSI0_NS                ((ENETC_VSI_Type *)NETC__NETC__ENETC_VSI0_BASE_NS)
  /** Peripheral NETC__NETC__ENETC_VSI1 base address */
  #define NETC__NETC__ENETC_VSI1_BASE              (0x5CCF0000u)
  /** Peripheral NETC__NETC__ENETC_VSI1 base address */
  #define NETC__NETC__ENETC_VSI1_BASE_NS           (0x4CCF0000u)
  /** Peripheral NETC__NETC__ENETC_VSI1 base pointer */
  #define NETC__NETC__ENETC_VSI1                   ((ENETC_VSI_Type *)NETC__NETC__ENETC_VSI1_BASE)
  /** Peripheral NETC__NETC__ENETC_VSI1 base pointer */
  #define NETC__NETC__ENETC_VSI1_NS                ((ENETC_VSI_Type *)NETC__NETC__ENETC_VSI1_BASE_NS)
  /** Array initializer of ENETC_VSI peripheral base addresses */
  #define ENETC_VSI_BASE_ADDRS                     { NETC__NETC__ENETC_VSI0_BASE, NETC__NETC__ENETC_VSI1_BASE }
  /** Array initializer of ENETC_VSI peripheral base pointers */
  #define ENETC_VSI_BASE_PTRS                      { NETC__NETC__ENETC_VSI0, NETC__NETC__ENETC_VSI1 }
  /** Array initializer of ENETC_VSI peripheral base addresses */
  #define ENETC_VSI_BASE_ADDRS_NS                  { NETC__NETC__ENETC_VSI0_BASE_NS, NETC__NETC__ENETC_VSI1_BASE_NS }
  /** Array initializer of ENETC_VSI peripheral base pointers */
  #define ENETC_VSI_BASE_PTRS_NS                   { NETC__NETC__ENETC_VSI0_NS, NETC__NETC__ENETC_VSI1_NS }
#else
  /** Peripheral NETC__NETC__ENETC_VSI0 base address */
  #define NETC__NETC__ENETC_VSI0_BASE              (0x4CCE0000u)
  /** Peripheral NETC__NETC__ENETC_VSI0 base pointer */
  #define NETC__NETC__ENETC_VSI0                   ((ENETC_VSI_Type *)NETC__NETC__ENETC_VSI0_BASE)
  /** Peripheral NETC__NETC__ENETC_VSI1 base address */
  #define NETC__NETC__ENETC_VSI1_BASE              (0x4CCF0000u)
  /** Peripheral NETC__NETC__ENETC_VSI1 base pointer */
  #define NETC__NETC__ENETC_VSI1                   ((ENETC_VSI_Type *)NETC__NETC__ENETC_VSI1_BASE)
  /** Array initializer of ENETC_VSI peripheral base addresses */
  #define ENETC_VSI_BASE_ADDRS                     { NETC__NETC__ENETC_VSI0_BASE, NETC__NETC__ENETC_VSI1_BASE }
  /** Array initializer of ENETC_VSI peripheral base pointers */
  #define ENETC_VSI_BASE_PTRS                      { NETC__NETC__ENETC_VSI0, NETC__NETC__ENETC_VSI1 }
#endif

/* EXTDST - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__EXTDST base address */
  #define DISPLAY__SEERIS__EXTDST_BASE             (0x5B510000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST base address */
  #define DISPLAY__SEERIS__EXTDST_BASE_NS          (0x4B510000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST base pointer */
  #define DISPLAY__SEERIS__EXTDST                  ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST_BASE)
  /** Peripheral DISPLAY__SEERIS__EXTDST base pointer */
  #define DISPLAY__SEERIS__EXTDST_NS               ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__EXTDST1 base address */
  #define DISPLAY__SEERIS__EXTDST1_BASE            (0x5B520000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST1 base address */
  #define DISPLAY__SEERIS__EXTDST1_BASE_NS         (0x4B520000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST1 base pointer */
  #define DISPLAY__SEERIS__EXTDST1                 ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST1_BASE)
  /** Peripheral DISPLAY__SEERIS__EXTDST1 base pointer */
  #define DISPLAY__SEERIS__EXTDST1_NS              ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST1_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__EXTDST2 base address */
  #define DISPLAY__SEERIS__EXTDST2_BASE            (0x5B550000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST2 base address */
  #define DISPLAY__SEERIS__EXTDST2_BASE_NS         (0x4B550000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST2 base pointer */
  #define DISPLAY__SEERIS__EXTDST2                 ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST2_BASE)
  /** Peripheral DISPLAY__SEERIS__EXTDST2 base pointer */
  #define DISPLAY__SEERIS__EXTDST2_NS              ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST2_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__EXTDST3 base address */
  #define DISPLAY__SEERIS__EXTDST3_BASE            (0x5B560000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST3 base address */
  #define DISPLAY__SEERIS__EXTDST3_BASE_NS         (0x4B560000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST3 base pointer */
  #define DISPLAY__SEERIS__EXTDST3                 ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST3_BASE)
  /** Peripheral DISPLAY__SEERIS__EXTDST3 base pointer */
  #define DISPLAY__SEERIS__EXTDST3_NS              ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST3_BASE_NS)
  /** Array initializer of EXTDST peripheral base addresses */
  #define EXTDST_BASE_ADDRS                        { DISPLAY__SEERIS__EXTDST_BASE, DISPLAY__SEERIS__EXTDST1_BASE, DISPLAY__SEERIS__EXTDST2_BASE, DISPLAY__SEERIS__EXTDST3_BASE }
  /** Array initializer of EXTDST peripheral base pointers */
  #define EXTDST_BASE_PTRS                         { DISPLAY__SEERIS__EXTDST, DISPLAY__SEERIS__EXTDST1, DISPLAY__SEERIS__EXTDST2, DISPLAY__SEERIS__EXTDST3 }
  /** Array initializer of EXTDST peripheral base addresses */
  #define EXTDST_BASE_ADDRS_NS                     { DISPLAY__SEERIS__EXTDST_BASE_NS, DISPLAY__SEERIS__EXTDST1_BASE_NS, DISPLAY__SEERIS__EXTDST2_BASE_NS, DISPLAY__SEERIS__EXTDST3_BASE_NS }
  /** Array initializer of EXTDST peripheral base pointers */
  #define EXTDST_BASE_PTRS_NS                      { DISPLAY__SEERIS__EXTDST_NS, DISPLAY__SEERIS__EXTDST1_NS, DISPLAY__SEERIS__EXTDST2_NS, DISPLAY__SEERIS__EXTDST3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__EXTDST base address */
  #define DISPLAY__SEERIS__EXTDST_BASE             (0x4B510000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST base pointer */
  #define DISPLAY__SEERIS__EXTDST                  ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST_BASE)
  /** Peripheral DISPLAY__SEERIS__EXTDST1 base address */
  #define DISPLAY__SEERIS__EXTDST1_BASE            (0x4B520000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST1 base pointer */
  #define DISPLAY__SEERIS__EXTDST1                 ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST1_BASE)
  /** Peripheral DISPLAY__SEERIS__EXTDST2 base address */
  #define DISPLAY__SEERIS__EXTDST2_BASE            (0x4B550000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST2 base pointer */
  #define DISPLAY__SEERIS__EXTDST2                 ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST2_BASE)
  /** Peripheral DISPLAY__SEERIS__EXTDST3 base address */
  #define DISPLAY__SEERIS__EXTDST3_BASE            (0x4B560000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST3 base pointer */
  #define DISPLAY__SEERIS__EXTDST3                 ((EXTDST_Type *)DISPLAY__SEERIS__EXTDST3_BASE)
  /** Array initializer of EXTDST peripheral base addresses */
  #define EXTDST_BASE_ADDRS                        { DISPLAY__SEERIS__EXTDST_BASE, DISPLAY__SEERIS__EXTDST1_BASE, DISPLAY__SEERIS__EXTDST2_BASE, DISPLAY__SEERIS__EXTDST3_BASE }
  /** Array initializer of EXTDST peripheral base pointers */
  #define EXTDST_BASE_PTRS                         { DISPLAY__SEERIS__EXTDST, DISPLAY__SEERIS__EXTDST1, DISPLAY__SEERIS__EXTDST2, DISPLAY__SEERIS__EXTDST3 }
#endif

/* FLEXIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FLEXIO1 base address */
  #define FLEXIO1_BASE                             (0x521E0000u)
  /** Peripheral FLEXIO1 base address */
  #define FLEXIO1_BASE_NS                          (0x421E0000u)
  /** Peripheral FLEXIO1 base pointer */
  #define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
  /** Peripheral FLEXIO1 base pointer */
  #define FLEXIO1_NS                               ((FLEXIO_Type *)FLEXIO1_BASE_NS)
  /** Peripheral FLEXIO2 base address */
  #define FLEXIO2_BASE                             (0x521F0000u)
  /** Peripheral FLEXIO2 base address */
  #define FLEXIO2_BASE_NS                          (0x421F0000u)
  /** Peripheral FLEXIO2 base pointer */
  #define FLEXIO2                                  ((FLEXIO_Type *)FLEXIO2_BASE)
  /** Peripheral FLEXIO2 base pointer */
  #define FLEXIO2_NS                               ((FLEXIO_Type *)FLEXIO2_BASE_NS)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE, FLEXIO2_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1, FLEXIO2 }
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS_NS                     { 0u, FLEXIO1_BASE_NS, FLEXIO2_BASE_NS }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS_NS                      { (FLEXIO_Type *)0u, FLEXIO1_NS, FLEXIO2_NS }
#else
  /** Peripheral FLEXIO1 base address */
  #define FLEXIO1_BASE                             (0x421E0000u)
  /** Peripheral FLEXIO1 base pointer */
  #define FLEXIO1                                  ((FLEXIO_Type *)FLEXIO1_BASE)
  /** Peripheral FLEXIO2 base address */
  #define FLEXIO2_BASE                             (0x421F0000u)
  /** Peripheral FLEXIO2 base pointer */
  #define FLEXIO2                                  ((FLEXIO_Type *)FLEXIO2_BASE)
  /** Array initializer of FLEXIO peripheral base addresses */
  #define FLEXIO_BASE_ADDRS                        { 0u, FLEXIO1_BASE, FLEXIO2_BASE }
  /** Array initializer of FLEXIO peripheral base pointers */
  #define FLEXIO_BASE_PTRS                         { (FLEXIO_Type *)0u, FLEXIO1, FLEXIO2 }
#endif
/** Interrupt vectors for the FLEXIO peripheral type */
#define FLEXIO_IRQS                              { NotAvail_IRQn, FLEXIO1_IRQn, FLEXIO2_IRQn }

/* FLEXSPI_SLV - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__XSPI_RESPONDER base address */
  #define WAKEUP__XSPI_RESPONDER_BASE              (0x52C50000u)
  /** Peripheral WAKEUP__XSPI_RESPONDER base address */
  #define WAKEUP__XSPI_RESPONDER_BASE_NS           (0x42C50000u)
  /** Peripheral WAKEUP__XSPI_RESPONDER base pointer */
  #define WAKEUP__XSPI_RESPONDER                   ((FLEXSPI_SLV_Type *)WAKEUP__XSPI_RESPONDER_BASE)
  /** Peripheral WAKEUP__XSPI_RESPONDER base pointer */
  #define WAKEUP__XSPI_RESPONDER_NS                ((FLEXSPI_SLV_Type *)WAKEUP__XSPI_RESPONDER_BASE_NS)
  /** Array initializer of FLEXSPI_SLV peripheral base addresses */
  #define FLEXSPI_SLV_BASE_ADDRS                   { WAKEUP__XSPI_RESPONDER_BASE }
  /** Array initializer of FLEXSPI_SLV peripheral base pointers */
  #define FLEXSPI_SLV_BASE_PTRS                    { WAKEUP__XSPI_RESPONDER }
  /** Array initializer of FLEXSPI_SLV peripheral base addresses */
  #define FLEXSPI_SLV_BASE_ADDRS_NS                { WAKEUP__XSPI_RESPONDER_BASE_NS }
  /** Array initializer of FLEXSPI_SLV peripheral base pointers */
  #define FLEXSPI_SLV_BASE_PTRS_NS                 { WAKEUP__XSPI_RESPONDER_NS }
#else
  /** Peripheral WAKEUP__XSPI_RESPONDER base address */
  #define WAKEUP__XSPI_RESPONDER_BASE              (0x42C50000u)
  /** Peripheral WAKEUP__XSPI_RESPONDER base pointer */
  #define WAKEUP__XSPI_RESPONDER                   ((FLEXSPI_SLV_Type *)WAKEUP__XSPI_RESPONDER_BASE)
  /** Array initializer of FLEXSPI_SLV peripheral base addresses */
  #define FLEXSPI_SLV_BASE_ADDRS                   { WAKEUP__XSPI_RESPONDER_BASE }
  /** Array initializer of FLEXSPI_SLV peripheral base pointers */
  #define FLEXSPI_SLV_BASE_PTRS                    { WAKEUP__XSPI_RESPONDER }
#endif

/* FRAMEGEN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FRAMEGE1 base address */
  #define DISPLAY__SEERIS__FRAMEGE1_BASE           (0x5B740000u)
  /** Peripheral DISPLAY__SEERIS__FRAMEGE1 base address */
  #define DISPLAY__SEERIS__FRAMEGE1_BASE_NS        (0x4B740000u)
  /** Peripheral DISPLAY__SEERIS__FRAMEGE1 base pointer */
  #define DISPLAY__SEERIS__FRAMEGE1                ((FRAMEGEN_Type *)DISPLAY__SEERIS__FRAMEGE1_BASE)
  /** Peripheral DISPLAY__SEERIS__FRAMEGE1 base pointer */
  #define DISPLAY__SEERIS__FRAMEGE1_NS             ((FRAMEGEN_Type *)DISPLAY__SEERIS__FRAMEGE1_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__FRAMEGEN base address */
  #define DISPLAY__SEERIS__FRAMEGEN_BASE           (0x5B6B0000u)
  /** Peripheral DISPLAY__SEERIS__FRAMEGEN base address */
  #define DISPLAY__SEERIS__FRAMEGEN_BASE_NS        (0x4B6B0000u)
  /** Peripheral DISPLAY__SEERIS__FRAMEGEN base pointer */
  #define DISPLAY__SEERIS__FRAMEGEN                ((FRAMEGEN_Type *)DISPLAY__SEERIS__FRAMEGEN_BASE)
  /** Peripheral DISPLAY__SEERIS__FRAMEGEN base pointer */
  #define DISPLAY__SEERIS__FRAMEGEN_NS             ((FRAMEGEN_Type *)DISPLAY__SEERIS__FRAMEGEN_BASE_NS)
  /** Array initializer of FRAMEGEN peripheral base addresses */
  #define FRAMEGEN_BASE_ADDRS                      { DISPLAY__SEERIS__FRAMEGE1_BASE, DISPLAY__SEERIS__FRAMEGEN_BASE }
  /** Array initializer of FRAMEGEN peripheral base pointers */
  #define FRAMEGEN_BASE_PTRS                       { DISPLAY__SEERIS__FRAMEGE1, DISPLAY__SEERIS__FRAMEGEN }
  /** Array initializer of FRAMEGEN peripheral base addresses */
  #define FRAMEGEN_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FRAMEGE1_BASE_NS, DISPLAY__SEERIS__FRAMEGEN_BASE_NS }
  /** Array initializer of FRAMEGEN peripheral base pointers */
  #define FRAMEGEN_BASE_PTRS_NS                    { DISPLAY__SEERIS__FRAMEGE1_NS, DISPLAY__SEERIS__FRAMEGEN_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FRAMEGE1 base address */
  #define DISPLAY__SEERIS__FRAMEGE1_BASE           (0x4B740000u)
  /** Peripheral DISPLAY__SEERIS__FRAMEGE1 base pointer */
  #define DISPLAY__SEERIS__FRAMEGE1                ((FRAMEGEN_Type *)DISPLAY__SEERIS__FRAMEGE1_BASE)
  /** Peripheral DISPLAY__SEERIS__FRAMEGEN base address */
  #define DISPLAY__SEERIS__FRAMEGEN_BASE           (0x4B6B0000u)
  /** Peripheral DISPLAY__SEERIS__FRAMEGEN base pointer */
  #define DISPLAY__SEERIS__FRAMEGEN                ((FRAMEGEN_Type *)DISPLAY__SEERIS__FRAMEGEN_BASE)
  /** Array initializer of FRAMEGEN peripheral base addresses */
  #define FRAMEGEN_BASE_ADDRS                      { DISPLAY__SEERIS__FRAMEGE1_BASE, DISPLAY__SEERIS__FRAMEGEN_BASE }
  /** Array initializer of FRAMEGEN peripheral base pointers */
  #define FRAMEGEN_BASE_PTRS                       { DISPLAY__SEERIS__FRAMEGE1, DISPLAY__SEERIS__FRAMEGEN }
#endif

/* FRO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral FRO base address */
  #define FRO_BASE                                 (0x54485000u)
  /** Peripheral FRO base address */
  #define FRO_BASE_NS                              (0x44485000u)
  /** Peripheral FRO base pointer */
  #define FRO                                      ((FRO_Type *)FRO_BASE)
  /** Peripheral FRO base pointer */
  #define FRO_NS                                   ((FRO_Type *)FRO_BASE_NS)
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS                           { FRO_BASE }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS                            { FRO }
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS_NS                        { FRO_BASE_NS }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS_NS                         { FRO_NS }
#else
  /** Peripheral FRO base address */
  #define FRO_BASE                                 (0x44485000u)
  /** Peripheral FRO base pointer */
  #define FRO                                      ((FRO_Type *)FRO_BASE)
  /** Array initializer of FRO peripheral base addresses */
  #define FRO_BASE_ADDRS                           { FRO_BASE }
  /** Array initializer of FRO peripheral base pointers */
  #define FRO_BASE_PTRS                            { FRO }
#endif

/* GPC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPC_CTRL_CM33 base address */
  #define GPC_CTRL_CM33_BASE                       (0x54470000u)
  /** Peripheral GPC_CTRL_CM33 base address */
  #define GPC_CTRL_CM33_BASE_NS                    (0x44470000u)
  /** Peripheral GPC_CTRL_CM33 base pointer */
  #define GPC_CTRL_CM33                            ((GPC_CPU_CTRL_Type *)GPC_CTRL_CM33_BASE)
  /** Peripheral GPC_CTRL_CM33 base pointer */
  #define GPC_CTRL_CM33_NS                         ((GPC_CPU_CTRL_Type *)GPC_CTRL_CM33_BASE_NS)
  /** Peripheral GPC_CTRL_CM7 base address */
  #define GPC_CTRL_CM7_BASE                        (0x54470800u)
  /** Peripheral GPC_CTRL_CM7 base address */
  #define GPC_CTRL_CM7_BASE_NS                     (0x44470800u)
  /** Peripheral GPC_CTRL_CM7 base pointer */
  #define GPC_CTRL_CM7                             ((GPC_CPU_CTRL_Type *)GPC_CTRL_CM7_BASE)
  /** Peripheral GPC_CTRL_CM7 base pointer */
  #define GPC_CTRL_CM7_NS                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CM7_BASE_NS)
  /** Peripheral GPC_CTRL_CA55_0 base address */
  #define GPC_CTRL_CA55_0_BASE                     (0x54471000u)
  /** Peripheral GPC_CTRL_CA55_0 base address */
  #define GPC_CTRL_CA55_0_BASE_NS                  (0x44471000u)
  /** Peripheral GPC_CTRL_CA55_0 base pointer */
  #define GPC_CTRL_CA55_0                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_0_BASE)
  /** Peripheral GPC_CTRL_CA55_0 base pointer */
  #define GPC_CTRL_CA55_0_NS                       ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_0_BASE_NS)
  /** Peripheral GPC_CTRL_CA55_1 base address */
  #define GPC_CTRL_CA55_1_BASE                     (0x54471800u)
  /** Peripheral GPC_CTRL_CA55_1 base address */
  #define GPC_CTRL_CA55_1_BASE_NS                  (0x44471800u)
  /** Peripheral GPC_CTRL_CA55_1 base pointer */
  #define GPC_CTRL_CA55_1                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_1_BASE)
  /** Peripheral GPC_CTRL_CA55_1 base pointer */
  #define GPC_CTRL_CA55_1_NS                       ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_1_BASE_NS)
  /** Peripheral GPC_CTRL_CA55_2 base address */
  #define GPC_CTRL_CA55_2_BASE                     (0x54472000u)
  /** Peripheral GPC_CTRL_CA55_2 base address */
  #define GPC_CTRL_CA55_2_BASE_NS                  (0x44472000u)
  /** Peripheral GPC_CTRL_CA55_2 base pointer */
  #define GPC_CTRL_CA55_2                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_2_BASE)
  /** Peripheral GPC_CTRL_CA55_2 base pointer */
  #define GPC_CTRL_CA55_2_NS                       ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_2_BASE_NS)
  /** Peripheral GPC_CTRL_CA55_3 base address */
  #define GPC_CTRL_CA55_3_BASE                     (0x54472800u)
  /** Peripheral GPC_CTRL_CA55_3 base address */
  #define GPC_CTRL_CA55_3_BASE_NS                  (0x44472800u)
  /** Peripheral GPC_CTRL_CA55_3 base pointer */
  #define GPC_CTRL_CA55_3                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_3_BASE)
  /** Peripheral GPC_CTRL_CA55_3 base pointer */
  #define GPC_CTRL_CA55_3_NS                       ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_3_BASE_NS)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base address */
  #define GPC_CTRL_CA55_CLUSTER_BASE               (0x54473000u)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base address */
  #define GPC_CTRL_CA55_CLUSTER_BASE_NS            (0x44473000u)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base pointer */
  #define GPC_CTRL_CA55_CLUSTER                    ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_CLUSTER_BASE)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base pointer */
  #define GPC_CTRL_CA55_CLUSTER_NS                 ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_CLUSTER_BASE_NS)
  /** Array initializer of GPC peripheral base addresses */
  #define GPC_BASE_ADDRS                           { GPC_CTRL_CM33_BASE, GPC_CTRL_CM7_BASE, GPC_CTRL_CA55_0_BASE, GPC_CTRL_CA55_1_BASE, GPC_CTRL_CA55_2_BASE, GPC_CTRL_CA55_3_BASE, 0u, 0u, GPC_CTRL_CA55_CLUSTER_BASE }
  /** Array initializer of GPC peripheral base pointers */
  #define GPC_CPU_CTRL_BASE_PTRS                   { GPC_CTRL_CM33, GPC_CTRL_CM7, GPC_CTRL_CA55_0, GPC_CTRL_CA55_1, GPC_CTRL_CA55_2, GPC_CTRL_CA55_3, GPC_CTRL_CA55_CLUSTER }
  /** Array initializer of GPC peripheral base addresses */
  #define GPC_BASE_ADDRS_NS                        { GPC_CTRL_CM33_BASE_NS, GPC_CTRL_CM7_BASE_NS, GPC_CTRL_CA55_0_BASE_NS, GPC_CTRL_CA55_1_BASE_NS, GPC_CTRL_CA55_2_BASE_NS, GPC_CTRL_CA55_3_BASE_NS, 0u, 0u, GPC_CTRL_CA55_CLUSTER_BASE_NS }
  /** Array initializer of GPC peripheral base pointers */
  #define GPC_BASE_PTRS_NS                         { GPC_CTRL_CM33_NS, GPC_CTRL_CM7_NS, GPC_CTRL_CA55_0_NS, GPC_CTRL_CA55_1_NS, GPC_CTRL_CA55_2_NS, GPC_CTRL_CA55_3_NS, GPC_CTRL_CA55_CLUSTER_NS }
#else
  /** Peripheral GPC_CTRL_CM33 base address */
  #define GPC_CTRL_CM33_BASE                       (0x44470000u)
  /** Peripheral GPC_CTRL_CM33 base pointer */
  #define GPC_CTRL_CM33                            ((GPC_CPU_CTRL_Type *)GPC_CTRL_CM33_BASE)
  /** Peripheral GPC_CTRL_CM7 base address */
  #define GPC_CTRL_CM7_BASE                        (0x44470800u)
  /** Peripheral GPC_CTRL_CM7 base pointer */
  #define GPC_CTRL_CM7                             ((GPC_CPU_CTRL_Type *)GPC_CTRL_CM7_BASE)
  /** Peripheral GPC_CTRL_CA55_0 base address */
  #define GPC_CTRL_CA55_0_BASE                     (0x44471000u)
  /** Peripheral GPC_CTRL_CA55_0 base pointer */
  #define GPC_CTRL_CA55_0                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_0_BASE)
  /** Peripheral GPC_CTRL_CA55_1 base address */
  #define GPC_CTRL_CA55_1_BASE                     (0x44471800u)
  /** Peripheral GPC_CTRL_CA55_1 base pointer */
  #define GPC_CTRL_CA55_1                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_1_BASE)
  /** Peripheral GPC_CTRL_CA55_2 base address */
  #define GPC_CTRL_CA55_2_BASE                     (0x44472000u)
  /** Peripheral GPC_CTRL_CA55_2 base pointer */
  #define GPC_CTRL_CA55_2                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_2_BASE)
  /** Peripheral GPC_CTRL_CA55_3 base address */
  #define GPC_CTRL_CA55_3_BASE                     (0x44472800u)
  /** Peripheral GPC_CTRL_CA55_3 base pointer */
  #define GPC_CTRL_CA55_3                          ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_3_BASE)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base address */
  #define GPC_CTRL_CA55_CLUSTER_BASE               (0x44473000u)
  /** Peripheral GPC_CTRL_CA55_CLUSTER base pointer */
  #define GPC_CTRL_CA55_CLUSTER                    ((GPC_CPU_CTRL_Type *)GPC_CTRL_CA55_CLUSTER_BASE)
  /** Array initializer of GPC peripheral base addresses */
  #define GPC_BASE_ADDRS                           { GPC_CTRL_CM33_BASE, GPC_CTRL_CM7_BASE, GPC_CTRL_CA55_0_BASE, GPC_CTRL_CA55_1_BASE, GPC_CTRL_CA55_2_BASE, GPC_CTRL_CA55_3_BASE, GPC_CTRL_CA55_CLUSTER_BASE }
  /** Array initializer of GPC peripheral base pointers */
  #define GPC_CPU_CTRL_BASE_PTRS                   { GPC_CTRL_CM33, GPC_CTRL_CM7, GPC_CTRL_CA55_0, GPC_CTRL_CA55_1, GPC_CTRL_CA55_2, GPC_CTRL_CA55_3, GPC_CTRL_CA55_CLUSTER }
#endif

/* GPC_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPC_GLOBAL base address */
  #define GPC_GLOBAL_BASE                          (0x54473800u)
  /** Peripheral GPC_GLOBAL base address */
  #define GPC_GLOBAL_BASE_NS                       (0x44473800u)
  /** Peripheral GPC_GLOBAL base pointer */
  #define GPC_GLOBAL                               ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE)
  /** Peripheral GPC_GLOBAL base pointer */
  #define GPC_GLOBAL_NS                            ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE_NS)
  /** Array initializer of GPC_GLOBAL peripheral base addresses */
  #define GPC_GLOBAL_BASE_ADDRS                    { GPC_GLOBAL_BASE }
  /** Array initializer of GPC_GLOBAL peripheral base pointers */
  #define GPC_GLOBAL_BASE_PTRS                     { GPC_GLOBAL }
  /** Array initializer of GPC_GLOBAL peripheral base addresses */
  #define GPC_GLOBAL_BASE_ADDRS_NS                 { GPC_GLOBAL_BASE_NS }
  /** Array initializer of GPC_GLOBAL peripheral base pointers */
  #define GPC_GLOBAL_BASE_PTRS_NS                  { GPC_GLOBAL_NS }
#else
  /** Peripheral GPC_GLOBAL base address */
  #define GPC_GLOBAL_BASE                          (0x44473800u)
  /** Peripheral GPC_GLOBAL base pointer */
  #define GPC_GLOBAL                               ((GPC_GLOBAL_Type *)GPC_GLOBAL_BASE)
  /** Array initializer of GPC_GLOBAL peripheral base addresses */
  #define GPC_GLOBAL_BASE_ADDRS                    { GPC_GLOBAL_BASE }
  /** Array initializer of GPC_GLOBAL peripheral base pointers */
  #define GPC_GLOBAL_BASE_PTRS                     { GPC_GLOBAL }
#endif

/* GPT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__GPT2 base address */
  #define WAKEUP__GPT2_BASE                        (0x535D0000u)
  /** Peripheral WAKEUP__GPT2 base address */
  #define WAKEUP__GPT2_BASE_NS                     (0x435D0000u)
  /** Peripheral WAKEUP__GPT2 base pointer */
  #define WAKEUP__GPT2                             ((GPT_Type *)WAKEUP__GPT2_BASE)
  /** Peripheral WAKEUP__GPT2 base pointer */
  #define WAKEUP__GPT2_NS                          ((GPT_Type *)WAKEUP__GPT2_BASE_NS)
  /** Peripheral WAKEUP__GPT3 base address */
  #define WAKEUP__GPT3_BASE                        (0x535E0000u)
  /** Peripheral WAKEUP__GPT3 base address */
  #define WAKEUP__GPT3_BASE_NS                     (0x435E0000u)
  /** Peripheral WAKEUP__GPT3 base pointer */
  #define WAKEUP__GPT3                             ((GPT_Type *)WAKEUP__GPT3_BASE)
  /** Peripheral WAKEUP__GPT3 base pointer */
  #define WAKEUP__GPT3_NS                          ((GPT_Type *)WAKEUP__GPT3_BASE_NS)
  /** Peripheral WAKEUP__GPT4 base address */
  #define WAKEUP__GPT4_BASE                        (0x535F0000u)
  /** Peripheral WAKEUP__GPT4 base address */
  #define WAKEUP__GPT4_BASE_NS                     (0x435F0000u)
  /** Peripheral WAKEUP__GPT4 base pointer */
  #define WAKEUP__GPT4                             ((GPT_Type *)WAKEUP__GPT4_BASE)
  /** Peripheral WAKEUP__GPT4 base pointer */
  #define WAKEUP__GPT4_NS                          ((GPT_Type *)WAKEUP__GPT4_BASE_NS)
  /** Peripheral WAKEUP__GPT5 base address */
  #define WAKEUP__GPT5_BASE                        (0x53600000u)
  /** Peripheral WAKEUP__GPT5 base address */
  #define WAKEUP__GPT5_BASE_NS                     (0x43600000u)
  /** Peripheral WAKEUP__GPT5 base pointer */
  #define WAKEUP__GPT5                             ((GPT_Type *)WAKEUP__GPT5_BASE)
  /** Peripheral WAKEUP__GPT5 base pointer */
  #define WAKEUP__GPT5_NS                          ((GPT_Type *)WAKEUP__GPT5_BASE_NS)
  /** Array initializer of GPT peripheral base addresses */
  #define GPT_BASE_ADDRS                           { 0u, 0u, WAKEUP__GPT2_BASE, WAKEUP__GPT3_BASE, WAKEUP__GPT4_BASE, WAKEUP__GPT5_BASE }
  /** Array initializer of GPT peripheral base pointers */
  #define GPT_BASE_PTRS                            { (GPT_Type *)0u, (GPT_Type *)0u, WAKEUP__GPT2, WAKEUP__GPT3, WAKEUP__GPT4, WAKEUP__GPT5 }
  /** Array initializer of GPT peripheral base addresses */
  #define GPT_BASE_ADDRS_NS                        { 0u, 0u, WAKEUP__GPT2_BASE_NS, WAKEUP__GPT3_BASE_NS, WAKEUP__GPT4_BASE_NS, WAKEUP__GPT5_BASE_NS }
  /** Array initializer of GPT peripheral base pointers */
  #define GPT_BASE_PTRS_NS                         { (GPT_Type *)0u, (GPT_Type *)0u, WAKEUP__GPT2_NS, WAKEUP__GPT3_NS, WAKEUP__GPT4_NS, WAKEUP__GPT5_NS }
#else
  /** Peripheral WAKEUP__GPT2 base address */
  #define WAKEUP__GPT2_BASE                        (0x435D0000u)
  /** Peripheral WAKEUP__GPT2 base pointer */
  #define WAKEUP__GPT2                             ((GPT_Type *)WAKEUP__GPT2_BASE)
  /** Peripheral WAKEUP__GPT3 base address */
  #define WAKEUP__GPT3_BASE                        (0x435E0000u)
  /** Peripheral WAKEUP__GPT3 base pointer */
  #define WAKEUP__GPT3                             ((GPT_Type *)WAKEUP__GPT3_BASE)
  /** Peripheral WAKEUP__GPT4 base address */
  #define WAKEUP__GPT4_BASE                        (0x435F0000u)
  /** Peripheral WAKEUP__GPT4 base pointer */
  #define WAKEUP__GPT4                             ((GPT_Type *)WAKEUP__GPT4_BASE)
  /** Peripheral WAKEUP__GPT5 base address */
  #define WAKEUP__GPT5_BASE                        (0x43600000u)
  /** Peripheral WAKEUP__GPT5 base pointer */
  #define WAKEUP__GPT5                             ((GPT_Type *)WAKEUP__GPT5_BASE)
  /** Array initializer of GPT peripheral base addresses */
  #define GPT_BASE_ADDRS                           { 0u, 0u, WAKEUP__GPT2_BASE, WAKEUP__GPT3_BASE, WAKEUP__GPT4_BASE, WAKEUP__GPT5_BASE }
  /** Array initializer of GPT peripheral base pointers */
  #define GPT_BASE_PTRS                            { (GPT_Type *)0u, (GPT_Type *)0u, WAKEUP__GPT2, WAKEUP__GPT3, WAKEUP__GPT4, WAKEUP__GPT5 }
#endif

/* GPU_BLK_CTRL_GPUMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPU__BLK_CTRL_GPUMIX base address */
  #define GPU__BLK_CTRL_GPUMIX_BASE                (0x5D810000u)
  /** Peripheral GPU__BLK_CTRL_GPUMIX base address */
  #define GPU__BLK_CTRL_GPUMIX_BASE_NS             (0x4D810000u)
  /** Peripheral GPU__BLK_CTRL_GPUMIX base pointer */
  #define GPU__BLK_CTRL_GPUMIX                     ((GPU_BLK_CTRL_GPUMIX_Type *)GPU__BLK_CTRL_GPUMIX_BASE)
  /** Peripheral GPU__BLK_CTRL_GPUMIX base pointer */
  #define GPU__BLK_CTRL_GPUMIX_NS                  ((GPU_BLK_CTRL_GPUMIX_Type *)GPU__BLK_CTRL_GPUMIX_BASE_NS)
  /** Array initializer of GPU_BLK_CTRL_GPUMIX peripheral base addresses */
  #define GPU_BLK_CTRL_GPUMIX_BASE_ADDRS           { GPU__BLK_CTRL_GPUMIX_BASE }
  /** Array initializer of GPU_BLK_CTRL_GPUMIX peripheral base pointers */
  #define GPU_BLK_CTRL_GPUMIX_BASE_PTRS            { GPU__BLK_CTRL_GPUMIX }
  /** Array initializer of GPU_BLK_CTRL_GPUMIX peripheral base addresses */
  #define GPU_BLK_CTRL_GPUMIX_BASE_ADDRS_NS        { GPU__BLK_CTRL_GPUMIX_BASE_NS }
  /** Array initializer of GPU_BLK_CTRL_GPUMIX peripheral base pointers */
  #define GPU_BLK_CTRL_GPUMIX_BASE_PTRS_NS         { GPU__BLK_CTRL_GPUMIX_NS }
#else
  /** Peripheral GPU__BLK_CTRL_GPUMIX base address */
  #define GPU__BLK_CTRL_GPUMIX_BASE                (0x4D810000u)
  /** Peripheral GPU__BLK_CTRL_GPUMIX base pointer */
  #define GPU__BLK_CTRL_GPUMIX                     ((GPU_BLK_CTRL_GPUMIX_Type *)GPU__BLK_CTRL_GPUMIX_BASE)
  /** Array initializer of GPU_BLK_CTRL_GPUMIX peripheral base addresses */
  #define GPU_BLK_CTRL_GPUMIX_BASE_ADDRS           { GPU__BLK_CTRL_GPUMIX_BASE }
  /** Array initializer of GPU_BLK_CTRL_GPUMIX peripheral base pointers */
  #define GPU_BLK_CTRL_GPUMIX_BASE_PTRS            { GPU__BLK_CTRL_GPUMIX }
#endif

/* GPU_REGISTERS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPU__REG__GPU_REGISTERS base address */
  #define GPU__REG__GPU_REGISTERS_BASE             (0x5D900000u)
  /** Peripheral GPU__REG__GPU_REGISTERS base address */
  #define GPU__REG__GPU_REGISTERS_BASE_NS          (0x4D900000u)
  /** Peripheral GPU__REG__GPU_REGISTERS base pointer */
  #define GPU__REG__GPU_REGISTERS                  ((GPU_REGISTERS_Type *)GPU__REG__GPU_REGISTERS_BASE)
  /** Peripheral GPU__REG__GPU_REGISTERS base pointer */
  #define GPU__REG__GPU_REGISTERS_NS               ((GPU_REGISTERS_Type *)GPU__REG__GPU_REGISTERS_BASE_NS)
  /** Array initializer of GPU_REGISTERS peripheral base addresses */
  #define GPU_REGISTERS_BASE_ADDRS                 { GPU__REG__GPU_REGISTERS_BASE }
  /** Array initializer of GPU_REGISTERS peripheral base pointers */
  #define GPU_REGISTERS_BASE_PTRS                  { GPU__REG__GPU_REGISTERS }
  /** Array initializer of GPU_REGISTERS peripheral base addresses */
  #define GPU_REGISTERS_BASE_ADDRS_NS              { GPU__REG__GPU_REGISTERS_BASE_NS }
  /** Array initializer of GPU_REGISTERS peripheral base pointers */
  #define GPU_REGISTERS_BASE_PTRS_NS               { GPU__REG__GPU_REGISTERS_NS }
#else
  /** Peripheral GPU__REG__GPU_REGISTERS base address */
  #define GPU__REG__GPU_REGISTERS_BASE             (0x4D900000u)
  /** Peripheral GPU__REG__GPU_REGISTERS base pointer */
  #define GPU__REG__GPU_REGISTERS                  ((GPU_REGISTERS_Type *)GPU__REG__GPU_REGISTERS_BASE)
  /** Array initializer of GPU_REGISTERS peripheral base addresses */
  #define GPU_REGISTERS_BASE_ADDRS                 { GPU__REG__GPU_REGISTERS_BASE }
  /** Array initializer of GPU_REGISTERS peripheral base pointers */
  #define GPU_REGISTERS_BASE_PTRS                  { GPU__REG__GPU_REGISTERS }
#endif

/* HSIO_BLK_CTRL_HSIOMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__BLK_CTRL_HSIOMIX base address */
  #define HSIO__BLK_CTRL_HSIOMIX_BASE              (0x5C010000u)
  /** Peripheral HSIO__BLK_CTRL_HSIOMIX base address */
  #define HSIO__BLK_CTRL_HSIOMIX_BASE_NS           (0x4C010000u)
  /** Peripheral HSIO__BLK_CTRL_HSIOMIX base pointer */
  #define HSIO__BLK_CTRL_HSIOMIX                   ((HSIO_BLK_CTRL_HSIOMIX_Type *)HSIO__BLK_CTRL_HSIOMIX_BASE)
  /** Peripheral HSIO__BLK_CTRL_HSIOMIX base pointer */
  #define HSIO__BLK_CTRL_HSIOMIX_NS                ((HSIO_BLK_CTRL_HSIOMIX_Type *)HSIO__BLK_CTRL_HSIOMIX_BASE_NS)
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base addresses */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_ADDRS         { HSIO__BLK_CTRL_HSIOMIX_BASE }
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base pointers */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_PTRS          { HSIO__BLK_CTRL_HSIOMIX }
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base addresses */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_ADDRS_NS      { HSIO__BLK_CTRL_HSIOMIX_BASE_NS }
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base pointers */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_PTRS_NS       { HSIO__BLK_CTRL_HSIOMIX_NS }
#else
  /** Peripheral HSIO__BLK_CTRL_HSIOMIX base address */
  #define HSIO__BLK_CTRL_HSIOMIX_BASE              (0x4C010000u)
  /** Peripheral HSIO__BLK_CTRL_HSIOMIX base pointer */
  #define HSIO__BLK_CTRL_HSIOMIX                   ((HSIO_BLK_CTRL_HSIOMIX_Type *)HSIO__BLK_CTRL_HSIOMIX_BASE)
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base addresses */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_ADDRS         { HSIO__BLK_CTRL_HSIOMIX_BASE }
  /** Array initializer of HSIO_BLK_CTRL_HSIOMIX peripheral base pointers */
  #define HSIO_BLK_CTRL_HSIOMIX_BASE_PTRS          { HSIO__BLK_CTRL_HSIOMIX }
#endif

/* HSIO_GHZ_LN_PLL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__GHZ_LN_PLL base address */
  #define HSIO__GHZ_LN_PLL_BASE                    (0x54481800u)
  /** Peripheral HSIO__GHZ_LN_PLL base address */
  #define HSIO__GHZ_LN_PLL_BASE_NS                 (0x44481800u)
  /** Peripheral HSIO__GHZ_LN_PLL base pointer */
  #define HSIO__GHZ_LN_PLL                         ((HSIO_GHZ_LN_PLL_Type *)HSIO__GHZ_LN_PLL_BASE)
  /** Peripheral HSIO__GHZ_LN_PLL base pointer */
  #define HSIO__GHZ_LN_PLL_NS                      ((HSIO_GHZ_LN_PLL_Type *)HSIO__GHZ_LN_PLL_BASE_NS)
  /** Array initializer of HSIO_GHZ_LN_PLL peripheral base addresses */
  #define HSIO_GHZ_LN_PLL_BASE_ADDRS               { HSIO__GHZ_LN_PLL_BASE }
  /** Array initializer of HSIO_GHZ_LN_PLL peripheral base pointers */
  #define HSIO_GHZ_LN_PLL_BASE_PTRS                { HSIO__GHZ_LN_PLL }
  /** Array initializer of HSIO_GHZ_LN_PLL peripheral base addresses */
  #define HSIO_GHZ_LN_PLL_BASE_ADDRS_NS            { HSIO__GHZ_LN_PLL_BASE_NS }
  /** Array initializer of HSIO_GHZ_LN_PLL peripheral base pointers */
  #define HSIO_GHZ_LN_PLL_BASE_PTRS_NS             { HSIO__GHZ_LN_PLL_NS }
#else
  /** Peripheral HSIO__GHZ_LN_PLL base address */
  #define HSIO__GHZ_LN_PLL_BASE                    (0x44481800u)
  /** Peripheral HSIO__GHZ_LN_PLL base pointer */
  #define HSIO__GHZ_LN_PLL                         ((HSIO_GHZ_LN_PLL_Type *)HSIO__GHZ_LN_PLL_BASE)
  /** Array initializer of HSIO_GHZ_LN_PLL peripheral base addresses */
  #define HSIO_GHZ_LN_PLL_BASE_ADDRS               { HSIO__GHZ_LN_PLL_BASE }
  /** Array initializer of HSIO_GHZ_LN_PLL peripheral base pointers */
  #define HSIO_GHZ_LN_PLL_BASE_PTRS                { HSIO__GHZ_LN_PLL }
#endif

/* I2S - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SAI1 base address */
  #define SAI1_BASE                                (0x543B0000u)
  /** Peripheral SAI1 base address */
  #define SAI1_BASE_NS                             (0x443B0000u)
  /** Peripheral SAI1 base pointer */
  #define SAI1                                     ((I2S_Type *)SAI1_BASE)
  /** Peripheral SAI1 base pointer */
  #define SAI1_NS                                  ((I2S_Type *)SAI1_BASE_NS)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE                                (0x5C880000u)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE_NS                             (0x4C880000u)
  /** Peripheral SAI2 base pointer */
  #define SAI2                                     ((I2S_Type *)SAI2_BASE)
  /** Peripheral SAI2 base pointer */
  #define SAI2_NS                                  ((I2S_Type *)SAI2_BASE_NS)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE                                (0x533E0000u)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE_NS                             (0x433E0000u)
  /** Peripheral SAI3 base pointer */
  #define SAI3                                     ((I2S_Type *)SAI3_BASE)
  /** Peripheral SAI3 base pointer */
  #define SAI3_NS                                  ((I2S_Type *)SAI3_BASE_NS)
  /** Peripheral SAI4 base address */
  #define SAI4_BASE                                (0x533F0000u)
  /** Peripheral SAI4 base address */
  #define SAI4_BASE_NS                             (0x433F0000u)
  /** Peripheral SAI4 base pointer */
  #define SAI4                                     ((I2S_Type *)SAI4_BASE)
  /** Peripheral SAI4 base pointer */
  #define SAI4_NS                                  ((I2S_Type *)SAI4_BASE_NS)
  /** Peripheral SAI5 base address */
  #define SAI5_BASE                                (0x53400000u)
  /** Peripheral SAI5 base address */
  #define SAI5_BASE_NS                             (0x43400000u)
  /** Peripheral SAI5 base pointer */
  #define SAI5                                     ((I2S_Type *)SAI5_BASE)
  /** Peripheral SAI5 base pointer */
  #define SAI5_NS                                  ((I2S_Type *)SAI5_BASE_NS)
  /** Peripheral SAI6 base address */
  #define SAI6_BASE                                (0x53410000u)
  /** Peripheral SAI6 base address */
  #define SAI6_BASE_NS                             (0x43410000u)
  /** Peripheral SAI6 base pointer */
  #define SAI6                                     ((I2S_Type *)SAI6_BASE)
  /** Peripheral SAI6 base pointer */
  #define SAI6_NS                                  ((I2S_Type *)SAI6_BASE_NS)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, SAI2_BASE, SAI3_BASE, SAI4_BASE, SAI5_BASE, SAI6_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, SAI2, SAI3, SAI4, SAI5, SAI6 }
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS_NS                        { 0u, SAI1_BASE_NS, SAI2_BASE_NS, SAI3_BASE_NS, SAI4_BASE_NS, SAI5_BASE_NS, SAI6_BASE_NS }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS_NS                         { (I2S_Type *)0u, SAI1_NS, SAI2_NS, SAI3_NS, SAI4_NS, SAI5_NS, SAI6_NS }
#else
  /** Peripheral SAI1 base address */
  #define SAI1_BASE                                (0x443B0000u)
  /** Peripheral SAI1 base pointer */
  #define SAI1                                     ((I2S_Type *)SAI1_BASE)
  /** Peripheral SAI2 base address */
  #define SAI2_BASE                                (0x4C880000u)
  /** Peripheral SAI2 base pointer */
  #define SAI2                                     ((I2S_Type *)SAI2_BASE)
  /** Peripheral SAI3 base address */
  #define SAI3_BASE                                (0x433E0000u)
  /** Peripheral SAI3 base pointer */
  #define SAI3                                     ((I2S_Type *)SAI3_BASE)
  /** Peripheral SAI4 base address */
  #define SAI4_BASE                                (0x433F0000u)
  /** Peripheral SAI4 base pointer */
  #define SAI4                                     ((I2S_Type *)SAI4_BASE)
  /** Peripheral SAI5 base address */
  #define SAI5_BASE                                (0x43400000u)
  /** Peripheral SAI5 base pointer */
  #define SAI5                                     ((I2S_Type *)SAI5_BASE)
  /** Peripheral SAI6 base address */
  #define SAI6_BASE                                (0x43410000u)
  /** Peripheral SAI6 base pointer */
  #define SAI6                                     ((I2S_Type *)SAI6_BASE)
  /** Array initializer of I2S peripheral base addresses */
  #define I2S_BASE_ADDRS                           { 0u, SAI1_BASE, SAI2_BASE, SAI3_BASE, SAI4_BASE, SAI5_BASE, SAI6_BASE }
  /** Array initializer of I2S peripheral base pointers */
  #define I2S_BASE_PTRS                            { (I2S_Type *)0u, SAI1, SAI2, SAI3, SAI4, SAI5, SAI6 }
#endif
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn, SAI4_IRQn, SAI5_IRQn, SAI6_IRQn }
#define I2S_TX_IRQS                              { NotAvail_IRQn, SAI1_IRQn, SAI2_IRQn, SAI3_IRQn, SAI4_IRQn, SAI5_IRQn, SAI6_IRQn }

/* I3C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x54330000u)
  /** Peripheral I3C1 base address */
  #define I3C1_BASE_NS                             (0x44330000u)
  /** Peripheral I3C1 base pointer */
  #define I3C1                                     ((I3C_Type *)I3C1_BASE)
  /** Peripheral I3C1 base pointer */
  #define I3C1_NS                                  ((I3C_Type *)I3C1_BASE_NS)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE                                (0x52140000u)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE_NS                             (0x42140000u)
  /** Peripheral I3C2 base pointer */
  #define I3C2                                     ((I3C_Type *)I3C2_BASE)
  /** Peripheral I3C2 base pointer */
  #define I3C2_NS                                  ((I3C_Type *)I3C2_BASE_NS)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { 0u, I3C1_BASE, I3C2_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { (I3C_Type *)0u, I3C1, I3C2 }
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS_NS                        { 0u, I3C1_BASE_NS, I3C2_BASE_NS }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS_NS                         { (I3C_Type *)0u, I3C1_NS, I3C2_NS }
#else
  /** Peripheral I3C1 base address */
  #define I3C1_BASE                                (0x44330000u)
  /** Peripheral I3C1 base pointer */
  #define I3C1                                     ((I3C_Type *)I3C1_BASE)
  /** Peripheral I3C2 base address */
  #define I3C2_BASE                                (0x42140000u)
  /** Peripheral I3C2 base pointer */
  #define I3C2                                     ((I3C_Type *)I3C2_BASE)
  /** Array initializer of I3C peripheral base addresses */
  #define I3C_BASE_ADDRS                           { 0u, I3C1_BASE, I3C2_BASE }
  /** Array initializer of I3C peripheral base pointers */
  #define I3C_BASE_PTRS                            { (I3C_Type *)0u, I3C1, I3C2 }
#endif
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { NotAvail_IRQn, I3C1_IRQn, I3C2_IRQn }

/* INTM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__INTM base address */
  #define AON__INTM_BASE                           (0x54580000u)
  /** Peripheral AON__INTM base address */
  #define AON__INTM_BASE_NS                        (0x44580000u)
  /** Peripheral AON__INTM base pointer */
  #define AON__INTM                                ((INTM_Type *)AON__INTM_BASE)
  /** Peripheral AON__INTM base pointer */
  #define AON__INTM_NS                             ((INTM_Type *)AON__INTM_BASE_NS)
  /** Array initializer of INTM peripheral base addresses */
  #define INTM_BASE_ADDRS                          { AON__INTM_BASE }
  /** Array initializer of INTM peripheral base pointers */
  #define INTM_BASE_PTRS                           { AON__INTM }
  /** Array initializer of INTM peripheral base addresses */
  #define INTM_BASE_ADDRS_NS                       { AON__INTM_BASE_NS }
  /** Array initializer of INTM peripheral base pointers */
  #define INTM_BASE_PTRS_NS                        { AON__INTM_NS }
#else
  /** Peripheral AON__INTM base address */
  #define AON__INTM_BASE                           (0x44580000u)
  /** Peripheral AON__INTM base pointer */
  #define AON__INTM                                ((INTM_Type *)AON__INTM_BASE)
  /** Array initializer of INTM peripheral base addresses */
  #define INTM_BASE_ADDRS                          { AON__INTM_BASE }
  /** Array initializer of INTM peripheral base pointers */
  #define INTM_BASE_PTRS                           { AON__INTM }
#endif

/* IOMUXC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IOMUXC base address */
  #define IOMUXC_BASE                              (0x543C0000u)
  /** Peripheral IOMUXC base address */
  #define IOMUXC_BASE_NS                           (0x443C0000u)
  /** Peripheral IOMUXC base pointer */
  #define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
  /** Peripheral IOMUXC base pointer */
  #define IOMUXC_NS                                ((IOMUXC_Type *)IOMUXC_BASE_NS)
  /** Array initializer of IOMUXC peripheral base addresses */
  #define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
  /** Array initializer of IOMUXC peripheral base pointers */
  #define IOMUXC_BASE_PTRS                         { IOMUXC }
  /** Array initializer of IOMUXC peripheral base addresses */
  #define IOMUXC_BASE_ADDRS_NS                     { IOMUXC_BASE_NS }
  /** Array initializer of IOMUXC peripheral base pointers */
  #define IOMUXC_BASE_PTRS_NS                      { IOMUXC_NS }
#else
  /** Peripheral IOMUXC base address */
  #define IOMUXC_BASE                              (0x443C0000u)
  /** Peripheral IOMUXC base pointer */
  #define IOMUXC                                   ((IOMUXC_Type *)IOMUXC_BASE)
  /** Array initializer of IOMUXC peripheral base addresses */
  #define IOMUXC_BASE_ADDRS                        { IOMUXC_BASE }
  /** Array initializer of IOMUXC peripheral base pointers */
  #define IOMUXC_BASE_PTRS                         { IOMUXC }
#endif

/* IOMUXC_GPR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__IOMUXC0__IOMUXC_GPR base address */
  #define AON__IOMUXC0__IOMUXC_GPR_BASE            (0x543D0000u)
  /** Peripheral AON__IOMUXC0__IOMUXC_GPR base address */
  #define AON__IOMUXC0__IOMUXC_GPR_BASE_NS         (0x443D0000u)
  /** Peripheral AON__IOMUXC0__IOMUXC_GPR base pointer */
  #define AON__IOMUXC0__IOMUXC_GPR                 ((IOMUXC_GPR_Type *)AON__IOMUXC0__IOMUXC_GPR_BASE)
  /** Peripheral AON__IOMUXC0__IOMUXC_GPR base pointer */
  #define AON__IOMUXC0__IOMUXC_GPR_NS              ((IOMUXC_GPR_Type *)AON__IOMUXC0__IOMUXC_GPR_BASE_NS)
  /** Array initializer of IOMUXC_GPR peripheral base addresses */
  #define IOMUXC_GPR_BASE_ADDRS                    { AON__IOMUXC0__IOMUXC_GPR_BASE }
  /** Array initializer of IOMUXC_GPR peripheral base pointers */
  #define IOMUXC_GPR_BASE_PTRS                     { AON__IOMUXC0__IOMUXC_GPR }
  /** Array initializer of IOMUXC_GPR peripheral base addresses */
  #define IOMUXC_GPR_BASE_ADDRS_NS                 { AON__IOMUXC0__IOMUXC_GPR_BASE_NS }
  /** Array initializer of IOMUXC_GPR peripheral base pointers */
  #define IOMUXC_GPR_BASE_PTRS_NS                  { AON__IOMUXC0__IOMUXC_GPR_NS }
#else
  /** Peripheral AON__IOMUXC0__IOMUXC_GPR base address */
  #define AON__IOMUXC0__IOMUXC_GPR_BASE            (0x443D0000u)
  /** Peripheral AON__IOMUXC0__IOMUXC_GPR base pointer */
  #define AON__IOMUXC0__IOMUXC_GPR                 ((IOMUXC_GPR_Type *)AON__IOMUXC0__IOMUXC_GPR_BASE)
  /** Array initializer of IOMUXC_GPR peripheral base addresses */
  #define IOMUXC_GPR_BASE_ADDRS                    { AON__IOMUXC0__IOMUXC_GPR_BASE }
  /** Array initializer of IOMUXC_GPR peripheral base pointers */
  #define IOMUXC_GPR_BASE_PTRS                     { AON__IOMUXC0__IOMUXC_GPR }
#endif

/* IPA_CONTROL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPU__REG__IPA_CONTROL base address */
  #define GPU__REG__IPA_CONTROL_BASE               (0x5D940000u)
  /** Peripheral GPU__REG__IPA_CONTROL base address */
  #define GPU__REG__IPA_CONTROL_BASE_NS            (0x4D940000u)
  /** Peripheral GPU__REG__IPA_CONTROL base pointer */
  #define GPU__REG__IPA_CONTROL                    ((IPA_CONTROL_Type *)GPU__REG__IPA_CONTROL_BASE)
  /** Peripheral GPU__REG__IPA_CONTROL base pointer */
  #define GPU__REG__IPA_CONTROL_NS                 ((IPA_CONTROL_Type *)GPU__REG__IPA_CONTROL_BASE_NS)
  /** Array initializer of IPA_CONTROL peripheral base addresses */
  #define IPA_CONTROL_BASE_ADDRS                   { GPU__REG__IPA_CONTROL_BASE }
  /** Array initializer of IPA_CONTROL peripheral base pointers */
  #define IPA_CONTROL_BASE_PTRS                    { GPU__REG__IPA_CONTROL }
  /** Array initializer of IPA_CONTROL peripheral base addresses */
  #define IPA_CONTROL_BASE_ADDRS_NS                { GPU__REG__IPA_CONTROL_BASE_NS }
  /** Array initializer of IPA_CONTROL peripheral base pointers */
  #define IPA_CONTROL_BASE_PTRS_NS                 { GPU__REG__IPA_CONTROL_NS }
#else
  /** Peripheral GPU__REG__IPA_CONTROL base address */
  #define GPU__REG__IPA_CONTROL_BASE               (0x4D940000u)
  /** Peripheral GPU__REG__IPA_CONTROL base pointer */
  #define GPU__REG__IPA_CONTROL                    ((IPA_CONTROL_Type *)GPU__REG__IPA_CONTROL_BASE)
  /** Array initializer of IPA_CONTROL peripheral base addresses */
  #define IPA_CONTROL_BASE_ADDRS                   { GPU__REG__IPA_CONTROL_BASE }
  /** Array initializer of IPA_CONTROL peripheral base pointers */
  #define IPA_CONTROL_BASE_PTRS                    { GPU__REG__IPA_CONTROL }
#endif

/* IRQ - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__IRQ base address */
  #define DISPLAY__SEERIS__IRQ_BASE                (0x5B401000u)
  /** Peripheral DISPLAY__SEERIS__IRQ base address */
  #define DISPLAY__SEERIS__IRQ_BASE_NS             (0x4B401000u)
  /** Peripheral DISPLAY__SEERIS__IRQ base pointer */
  #define DISPLAY__SEERIS__IRQ                     ((IRQ_Type *)DISPLAY__SEERIS__IRQ_BASE)
  /** Peripheral DISPLAY__SEERIS__IRQ base pointer */
  #define DISPLAY__SEERIS__IRQ_NS                  ((IRQ_Type *)DISPLAY__SEERIS__IRQ_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__IRQ1 base address */
  #define DISPLAY__SEERIS__IRQ1_BASE               (0x5B431000u)
  /** Peripheral DISPLAY__SEERIS__IRQ1 base address */
  #define DISPLAY__SEERIS__IRQ1_BASE_NS            (0x4B431000u)
  /** Peripheral DISPLAY__SEERIS__IRQ1 base pointer */
  #define DISPLAY__SEERIS__IRQ1                    ((IRQ_Type *)DISPLAY__SEERIS__IRQ1_BASE)
  /** Peripheral DISPLAY__SEERIS__IRQ1 base pointer */
  #define DISPLAY__SEERIS__IRQ1_NS                 ((IRQ_Type *)DISPLAY__SEERIS__IRQ1_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__IRQ2 base address */
  #define DISPLAY__SEERIS__IRQ2_BASE               (0x5B7C1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ2 base address */
  #define DISPLAY__SEERIS__IRQ2_BASE_NS            (0x4B7C1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ2 base pointer */
  #define DISPLAY__SEERIS__IRQ2                    ((IRQ_Type *)DISPLAY__SEERIS__IRQ2_BASE)
  /** Peripheral DISPLAY__SEERIS__IRQ2 base pointer */
  #define DISPLAY__SEERIS__IRQ2_NS                 ((IRQ_Type *)DISPLAY__SEERIS__IRQ2_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__IRQ3 base address */
  #define DISPLAY__SEERIS__IRQ3_BASE               (0x5B7D1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ3 base address */
  #define DISPLAY__SEERIS__IRQ3_BASE_NS            (0x4B7D1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ3 base pointer */
  #define DISPLAY__SEERIS__IRQ3                    ((IRQ_Type *)DISPLAY__SEERIS__IRQ3_BASE)
  /** Peripheral DISPLAY__SEERIS__IRQ3 base pointer */
  #define DISPLAY__SEERIS__IRQ3_NS                 ((IRQ_Type *)DISPLAY__SEERIS__IRQ3_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__IRQ4 base address */
  #define DISPLAY__SEERIS__IRQ4_BASE               (0x5B7E1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ4 base address */
  #define DISPLAY__SEERIS__IRQ4_BASE_NS            (0x4B7E1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ4 base pointer */
  #define DISPLAY__SEERIS__IRQ4                    ((IRQ_Type *)DISPLAY__SEERIS__IRQ4_BASE)
  /** Peripheral DISPLAY__SEERIS__IRQ4 base pointer */
  #define DISPLAY__SEERIS__IRQ4_NS                 ((IRQ_Type *)DISPLAY__SEERIS__IRQ4_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__IRQ5 base address */
  #define DISPLAY__SEERIS__IRQ5_BASE               (0x5B7F1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ5 base address */
  #define DISPLAY__SEERIS__IRQ5_BASE_NS            (0x4B7F1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ5 base pointer */
  #define DISPLAY__SEERIS__IRQ5                    ((IRQ_Type *)DISPLAY__SEERIS__IRQ5_BASE)
  /** Peripheral DISPLAY__SEERIS__IRQ5 base pointer */
  #define DISPLAY__SEERIS__IRQ5_NS                 ((IRQ_Type *)DISPLAY__SEERIS__IRQ5_BASE_NS)
  /** Array initializer of IRQ peripheral base addresses */
  #define IRQ_BASE_ADDRS                           { DISPLAY__SEERIS__IRQ_BASE, DISPLAY__SEERIS__IRQ1_BASE, DISPLAY__SEERIS__IRQ2_BASE, DISPLAY__SEERIS__IRQ3_BASE, DISPLAY__SEERIS__IRQ4_BASE, DISPLAY__SEERIS__IRQ5_BASE }
  /** Array initializer of IRQ peripheral base pointers */
  #define IRQ_BASE_PTRS                            { DISPLAY__SEERIS__IRQ, DISPLAY__SEERIS__IRQ1, DISPLAY__SEERIS__IRQ2, DISPLAY__SEERIS__IRQ3, DISPLAY__SEERIS__IRQ4, DISPLAY__SEERIS__IRQ5 }
  /** Array initializer of IRQ peripheral base addresses */
  #define IRQ_BASE_ADDRS_NS                        { DISPLAY__SEERIS__IRQ_BASE_NS, DISPLAY__SEERIS__IRQ1_BASE_NS, DISPLAY__SEERIS__IRQ2_BASE_NS, DISPLAY__SEERIS__IRQ3_BASE_NS, DISPLAY__SEERIS__IRQ4_BASE_NS, DISPLAY__SEERIS__IRQ5_BASE_NS }
  /** Array initializer of IRQ peripheral base pointers */
  #define IRQ_BASE_PTRS_NS                         { DISPLAY__SEERIS__IRQ_NS, DISPLAY__SEERIS__IRQ1_NS, DISPLAY__SEERIS__IRQ2_NS, DISPLAY__SEERIS__IRQ3_NS, DISPLAY__SEERIS__IRQ4_NS, DISPLAY__SEERIS__IRQ5_NS }
#else
  /** Peripheral DISPLAY__SEERIS__IRQ base address */
  #define DISPLAY__SEERIS__IRQ_BASE                (0x4B401000u)
  /** Peripheral DISPLAY__SEERIS__IRQ base pointer */
  #define DISPLAY__SEERIS__IRQ                     ((IRQ_Type *)DISPLAY__SEERIS__IRQ_BASE)
  /** Peripheral DISPLAY__SEERIS__IRQ1 base address */
  #define DISPLAY__SEERIS__IRQ1_BASE               (0x4B431000u)
  /** Peripheral DISPLAY__SEERIS__IRQ1 base pointer */
  #define DISPLAY__SEERIS__IRQ1                    ((IRQ_Type *)DISPLAY__SEERIS__IRQ1_BASE)
  /** Peripheral DISPLAY__SEERIS__IRQ2 base address */
  #define DISPLAY__SEERIS__IRQ2_BASE               (0x4B7C1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ2 base pointer */
  #define DISPLAY__SEERIS__IRQ2                    ((IRQ_Type *)DISPLAY__SEERIS__IRQ2_BASE)
  /** Peripheral DISPLAY__SEERIS__IRQ3 base address */
  #define DISPLAY__SEERIS__IRQ3_BASE               (0x4B7D1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ3 base pointer */
  #define DISPLAY__SEERIS__IRQ3                    ((IRQ_Type *)DISPLAY__SEERIS__IRQ3_BASE)
  /** Peripheral DISPLAY__SEERIS__IRQ4 base address */
  #define DISPLAY__SEERIS__IRQ4_BASE               (0x4B7E1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ4 base pointer */
  #define DISPLAY__SEERIS__IRQ4                    ((IRQ_Type *)DISPLAY__SEERIS__IRQ4_BASE)
  /** Peripheral DISPLAY__SEERIS__IRQ5 base address */
  #define DISPLAY__SEERIS__IRQ5_BASE               (0x4B7F1000u)
  /** Peripheral DISPLAY__SEERIS__IRQ5 base pointer */
  #define DISPLAY__SEERIS__IRQ5                    ((IRQ_Type *)DISPLAY__SEERIS__IRQ5_BASE)
  /** Array initializer of IRQ peripheral base addresses */
  #define IRQ_BASE_ADDRS                           { DISPLAY__SEERIS__IRQ_BASE, DISPLAY__SEERIS__IRQ1_BASE, DISPLAY__SEERIS__IRQ2_BASE, DISPLAY__SEERIS__IRQ3_BASE, DISPLAY__SEERIS__IRQ4_BASE, DISPLAY__SEERIS__IRQ5_BASE }
  /** Array initializer of IRQ peripheral base pointers */
  #define IRQ_BASE_PTRS                            { DISPLAY__SEERIS__IRQ, DISPLAY__SEERIS__IRQ1, DISPLAY__SEERIS__IRQ2, DISPLAY__SEERIS__IRQ3, DISPLAY__SEERIS__IRQ4, DISPLAY__SEERIS__IRQ5 }
#endif

/* IRQSTEER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral IRQSTEER base address */
  #define IRQSTEER_BASE                            (0x54680000u)
  /** Peripheral IRQSTEER base address */
  #define IRQSTEER_BASE_NS                         (0x44680000u)
  /** Peripheral IRQSTEER base pointer */
  #define IRQSTEER                                 ((IRQSTEER_Type *)IRQSTEER_BASE)
  /** Peripheral IRQSTEER base pointer */
  #define IRQSTEER_NS                              ((IRQSTEER_Type *)IRQSTEER_BASE_NS)
  /** Array initializer of IRQSTEER peripheral base addresses */
  #define IRQSTEER_BASE_ADDRS                      { IRQSTEER_BASE }
  /** Array initializer of IRQSTEER peripheral base pointers */
  #define IRQSTEER_BASE_PTRS                       { IRQSTEER }
  /** Array initializer of IRQSTEER peripheral base addresses */
  #define IRQSTEER_BASE_ADDRS_NS                   { IRQSTEER_BASE_NS }
  /** Array initializer of IRQSTEER peripheral base pointers */
  #define IRQSTEER_BASE_PTRS_NS                    { IRQSTEER_NS }
#else
  /** Peripheral IRQSTEER base address */
  #define IRQSTEER_BASE                            (0x44680000u)
  /** Peripheral IRQSTEER base pointer */
  #define IRQSTEER                                 ((IRQSTEER_Type *)IRQSTEER_BASE)
  /** Array initializer of IRQSTEER peripheral base addresses */
  #define IRQSTEER_BASE_ADDRS                      { IRQSTEER_BASE }
  /** Array initializer of IRQSTEER peripheral base pointers */
  #define IRQSTEER_BASE_PTRS                       { IRQSTEER }
#endif

/* ISI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CAMERA__ISI base address */
  #define CAMERA__ISI_BASE                         (0x5AD50000u)
  /** Peripheral CAMERA__ISI base address */
  #define CAMERA__ISI_BASE_NS                      (0x4AD50000u)
  /** Peripheral CAMERA__ISI base pointer */
  #define CAMERA__ISI                              ((ISI_Type *)CAMERA__ISI_BASE)
  /** Peripheral CAMERA__ISI base pointer */
  #define CAMERA__ISI_NS                           ((ISI_Type *)CAMERA__ISI_BASE_NS)
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS                           { CAMERA__ISI_BASE }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS                            { CAMERA__ISI }
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS_NS                        { CAMERA__ISI_BASE_NS }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS_NS                         { CAMERA__ISI_NS }
#else
  /** Peripheral CAMERA__ISI base address */
  #define CAMERA__ISI_BASE                         (0x4AD50000u)
  /** Peripheral CAMERA__ISI base pointer */
  #define CAMERA__ISI                              ((ISI_Type *)CAMERA__ISI_BASE)
  /** Array initializer of ISI peripheral base addresses */
  #define ISI_BASE_ADDRS                           { CAMERA__ISI_BASE }
  /** Array initializer of ISI peripheral base pointers */
  #define ISI_BASE_PTRS                            { CAMERA__ISI }
#endif

/* JPEG_DEC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VPU__JPEG_DEC1 base address */
  #define VPU__JPEG_DEC1_BASE                      (0x5C500100u)
  /** Peripheral VPU__JPEG_DEC1 base address */
  #define VPU__JPEG_DEC1_BASE_NS                   (0x4C500100u)
  /** Peripheral VPU__JPEG_DEC1 base pointer */
  #define VPU__JPEG_DEC1                           ((JPEG_DEC_Type *)VPU__JPEG_DEC1_BASE)
  /** Peripheral VPU__JPEG_DEC1 base pointer */
  #define VPU__JPEG_DEC1_NS                        ((JPEG_DEC_Type *)VPU__JPEG_DEC1_BASE_NS)
  /** Array initializer of JPEG_DEC peripheral base addresses */
  #define JPEG_DEC_BASE_ADDRS                      { VPU__JPEG_DEC1_BASE }
  /** Array initializer of JPEG_DEC peripheral base pointers */
  #define JPEG_DEC_BASE_PTRS                       { VPU__JPEG_DEC1 }
  /** Array initializer of JPEG_DEC peripheral base addresses */
  #define JPEG_DEC_BASE_ADDRS_NS                   { VPU__JPEG_DEC1_BASE_NS }
  /** Array initializer of JPEG_DEC peripheral base pointers */
  #define JPEG_DEC_BASE_PTRS_NS                    { VPU__JPEG_DEC1_NS }
#else
  /** Peripheral VPU__JPEG_DEC1 base address */
  #define VPU__JPEG_DEC1_BASE                      (0x4C500100u)
  /** Peripheral VPU__JPEG_DEC1 base pointer */
  #define VPU__JPEG_DEC1                           ((JPEG_DEC_Type *)VPU__JPEG_DEC1_BASE)
  /** Array initializer of JPEG_DEC peripheral base addresses */
  #define JPEG_DEC_BASE_ADDRS                      { VPU__JPEG_DEC1_BASE }
  /** Array initializer of JPEG_DEC peripheral base pointers */
  #define JPEG_DEC_BASE_PTRS                       { VPU__JPEG_DEC1 }
#endif

/* JPEG_DEC_WRAP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VPU__JPEG_DEC_WRAP0 base address */
  #define VPU__JPEG_DEC_WRAP0_BASE                 (0x5C500000u)
  /** Peripheral VPU__JPEG_DEC_WRAP0 base address */
  #define VPU__JPEG_DEC_WRAP0_BASE_NS              (0x4C500000u)
  /** Peripheral VPU__JPEG_DEC_WRAP0 base pointer */
  #define VPU__JPEG_DEC_WRAP0                      ((JPEG_DEC_WRAP_Type *)VPU__JPEG_DEC_WRAP0_BASE)
  /** Peripheral VPU__JPEG_DEC_WRAP0 base pointer */
  #define VPU__JPEG_DEC_WRAP0_NS                   ((JPEG_DEC_WRAP_Type *)VPU__JPEG_DEC_WRAP0_BASE_NS)
  /** Array initializer of JPEG_DEC_WRAP peripheral base addresses */
  #define JPEG_DEC_WRAP_BASE_ADDRS                 { VPU__JPEG_DEC_WRAP0_BASE }
  /** Array initializer of JPEG_DEC_WRAP peripheral base pointers */
  #define JPEG_DEC_WRAP_BASE_PTRS                  { VPU__JPEG_DEC_WRAP0 }
  /** Array initializer of JPEG_DEC_WRAP peripheral base addresses */
  #define JPEG_DEC_WRAP_BASE_ADDRS_NS              { VPU__JPEG_DEC_WRAP0_BASE_NS }
  /** Array initializer of JPEG_DEC_WRAP peripheral base pointers */
  #define JPEG_DEC_WRAP_BASE_PTRS_NS               { VPU__JPEG_DEC_WRAP0_NS }
#else
  /** Peripheral VPU__JPEG_DEC_WRAP0 base address */
  #define VPU__JPEG_DEC_WRAP0_BASE                 (0x4C500000u)
  /** Peripheral VPU__JPEG_DEC_WRAP0 base pointer */
  #define VPU__JPEG_DEC_WRAP0                      ((JPEG_DEC_WRAP_Type *)VPU__JPEG_DEC_WRAP0_BASE)
  /** Array initializer of JPEG_DEC_WRAP peripheral base addresses */
  #define JPEG_DEC_WRAP_BASE_ADDRS                 { VPU__JPEG_DEC_WRAP0_BASE }
  /** Array initializer of JPEG_DEC_WRAP peripheral base pointers */
  #define JPEG_DEC_WRAP_BASE_PTRS                  { VPU__JPEG_DEC_WRAP0 }
#endif

/* LAYERBL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__LAYERBL1 base address */
  #define DISPLAY__SEERIS__LAYERBL1_BASE           (0x5B580000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL1 base address */
  #define DISPLAY__SEERIS__LAYERBL1_BASE_NS        (0x4B580000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL1 base pointer */
  #define DISPLAY__SEERIS__LAYERBL1                ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL1_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERBL1 base pointer */
  #define DISPLAY__SEERIS__LAYERBL1_NS             ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL1_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__LAYERBL2 base address */
  #define DISPLAY__SEERIS__LAYERBL2_BASE           (0x5B590000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL2 base address */
  #define DISPLAY__SEERIS__LAYERBL2_BASE_NS        (0x4B590000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL2 base pointer */
  #define DISPLAY__SEERIS__LAYERBL2                ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL2_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERBL2 base pointer */
  #define DISPLAY__SEERIS__LAYERBL2_NS             ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL2_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__LAYERBL3 base address */
  #define DISPLAY__SEERIS__LAYERBL3_BASE           (0x5B5A0000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL3 base address */
  #define DISPLAY__SEERIS__LAYERBL3_BASE_NS        (0x4B5A0000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL3 base pointer */
  #define DISPLAY__SEERIS__LAYERBL3                ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL3_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERBL3 base pointer */
  #define DISPLAY__SEERIS__LAYERBL3_NS             ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL3_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__LAYERBL4 base address */
  #define DISPLAY__SEERIS__LAYERBL4_BASE           (0x5B5B0000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL4 base address */
  #define DISPLAY__SEERIS__LAYERBL4_BASE_NS        (0x4B5B0000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL4 base pointer */
  #define DISPLAY__SEERIS__LAYERBL4                ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL4_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERBL4 base pointer */
  #define DISPLAY__SEERIS__LAYERBL4_NS             ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL4_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__LAYERBLE base address */
  #define DISPLAY__SEERIS__LAYERBLE_BASE           (0x5B570000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBLE base address */
  #define DISPLAY__SEERIS__LAYERBLE_BASE_NS        (0x4B570000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBLE base pointer */
  #define DISPLAY__SEERIS__LAYERBLE                ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBLE_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERBLE base pointer */
  #define DISPLAY__SEERIS__LAYERBLE_NS             ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBLE_BASE_NS)
  /** Array initializer of LAYERBL peripheral base addresses */
  #define LAYERBL_BASE_ADDRS                       { DISPLAY__SEERIS__LAYERBL1_BASE, DISPLAY__SEERIS__LAYERBL2_BASE, DISPLAY__SEERIS__LAYERBL3_BASE, DISPLAY__SEERIS__LAYERBL4_BASE, DISPLAY__SEERIS__LAYERBLE_BASE }
  /** Array initializer of LAYERBL peripheral base pointers */
  #define LAYERBL_BASE_PTRS                        { DISPLAY__SEERIS__LAYERBL1, DISPLAY__SEERIS__LAYERBL2, DISPLAY__SEERIS__LAYERBL3, DISPLAY__SEERIS__LAYERBL4, DISPLAY__SEERIS__LAYERBLE }
  /** Array initializer of LAYERBL peripheral base addresses */
  #define LAYERBL_BASE_ADDRS_NS                    { DISPLAY__SEERIS__LAYERBL1_BASE_NS, DISPLAY__SEERIS__LAYERBL2_BASE_NS, DISPLAY__SEERIS__LAYERBL3_BASE_NS, DISPLAY__SEERIS__LAYERBL4_BASE_NS, DISPLAY__SEERIS__LAYERBLE_BASE_NS }
  /** Array initializer of LAYERBL peripheral base pointers */
  #define LAYERBL_BASE_PTRS_NS                     { DISPLAY__SEERIS__LAYERBL1_NS, DISPLAY__SEERIS__LAYERBL2_NS, DISPLAY__SEERIS__LAYERBL3_NS, DISPLAY__SEERIS__LAYERBL4_NS, DISPLAY__SEERIS__LAYERBLE_NS }
#else
  /** Peripheral DISPLAY__SEERIS__LAYERBL1 base address */
  #define DISPLAY__SEERIS__LAYERBL1_BASE           (0x4B580000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL1 base pointer */
  #define DISPLAY__SEERIS__LAYERBL1                ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL1_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERBL2 base address */
  #define DISPLAY__SEERIS__LAYERBL2_BASE           (0x4B590000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL2 base pointer */
  #define DISPLAY__SEERIS__LAYERBL2                ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL2_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERBL3 base address */
  #define DISPLAY__SEERIS__LAYERBL3_BASE           (0x4B5A0000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL3 base pointer */
  #define DISPLAY__SEERIS__LAYERBL3                ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL3_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERBL4 base address */
  #define DISPLAY__SEERIS__LAYERBL4_BASE           (0x4B5B0000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBL4 base pointer */
  #define DISPLAY__SEERIS__LAYERBL4                ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBL4_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERBLE base address */
  #define DISPLAY__SEERIS__LAYERBLE_BASE           (0x4B570000u)
  /** Peripheral DISPLAY__SEERIS__LAYERBLE base pointer */
  #define DISPLAY__SEERIS__LAYERBLE                ((LAYERBL_Type *)DISPLAY__SEERIS__LAYERBLE_BASE)
  /** Array initializer of LAYERBL peripheral base addresses */
  #define LAYERBL_BASE_ADDRS                       { DISPLAY__SEERIS__LAYERBL1_BASE, DISPLAY__SEERIS__LAYERBL2_BASE, DISPLAY__SEERIS__LAYERBL3_BASE, DISPLAY__SEERIS__LAYERBL4_BASE, DISPLAY__SEERIS__LAYERBLE_BASE }
  /** Array initializer of LAYERBL peripheral base pointers */
  #define LAYERBL_BASE_PTRS                        { DISPLAY__SEERIS__LAYERBL1, DISPLAY__SEERIS__LAYERBL2, DISPLAY__SEERIS__LAYERBL3, DISPLAY__SEERIS__LAYERBL4, DISPLAY__SEERIS__LAYERBLE }
#endif

/* LDB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LVDS base address */
  #define LVDS_BASE                                (0x5B0C0000u)
  /** Peripheral LVDS base address */
  #define LVDS_BASE_NS                             (0x4B0C0000u)
  /** Peripheral LVDS base pointer */
  #define LVDS                                     ((LDB_Type *)LVDS_BASE)
  /** Peripheral LVDS base pointer */
  #define LVDS_NS                                  ((LDB_Type *)LVDS_BASE_NS)
  /** Array initializer of LDB peripheral base addresses */
  #define LDB_BASE_ADDRS                           { LVDS_BASE }
  /** Array initializer of LDB peripheral base pointers */
  #define LDB_BASE_PTRS                            { LVDS }
  /** Array initializer of LDB peripheral base addresses */
  #define LDB_BASE_ADDRS_NS                        { LVDS_BASE_NS }
  /** Array initializer of LDB peripheral base pointers */
  #define LDB_BASE_PTRS_NS                         { LVDS_NS }
#else
  /** Peripheral LVDS base address */
  #define LVDS_BASE                                (0x4B0C0000u)
  /** Peripheral LVDS base pointer */
  #define LVDS                                     ((LDB_Type *)LVDS_BASE)
  /** Array initializer of LDB peripheral base addresses */
  #define LDB_BASE_ADDRS                           { LVDS_BASE }
  /** Array initializer of LDB peripheral base pointers */
  #define LDB_BASE_PTRS                            { LVDS }
#endif

/* LPI2C - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x54340000u)
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE_NS                           (0x44340000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1_NS                                ((LPI2C_Type *)LPI2C1_BASE_NS)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE                              (0x54350000u)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE_NS                           (0x44350000u)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2_NS                                ((LPI2C_Type *)LPI2C2_BASE_NS)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE                              (0x52150000u)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE_NS                           (0x42150000u)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3_NS                                ((LPI2C_Type *)LPI2C3_BASE_NS)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE                              (0x52160000u)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE_NS                           (0x42160000u)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4_NS                                ((LPI2C_Type *)LPI2C4_BASE_NS)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE                              (0x522D0000u)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE_NS                           (0x422D0000u)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5_NS                                ((LPI2C_Type *)LPI2C5_BASE_NS)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE                              (0x522E0000u)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE_NS                           (0x422E0000u)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6_NS                                ((LPI2C_Type *)LPI2C6_BASE_NS)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE                              (0x522F0000u)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE_NS                           (0x422F0000u)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7_NS                                ((LPI2C_Type *)LPI2C7_BASE_NS)
  /** Peripheral LPI2C8 base address */
  #define LPI2C8_BASE                              (0x52300000u)
  /** Peripheral LPI2C8 base address */
  #define LPI2C8_BASE_NS                           (0x42300000u)
  /** Peripheral LPI2C8 base pointer */
  #define LPI2C8                                   ((LPI2C_Type *)LPI2C8_BASE)
  /** Peripheral LPI2C8 base pointer */
  #define LPI2C8_NS                                ((LPI2C_Type *)LPI2C8_BASE_NS)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE, LPI2C8_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7, LPI2C8 }
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS_NS                      { 0u, LPI2C1_BASE_NS, LPI2C2_BASE_NS, LPI2C3_BASE_NS, LPI2C4_BASE_NS, LPI2C5_BASE_NS, LPI2C6_BASE_NS, LPI2C7_BASE_NS, LPI2C8_BASE_NS }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS_NS                       { (LPI2C_Type *)0u, LPI2C1_NS, LPI2C2_NS, LPI2C3_NS, LPI2C4_NS, LPI2C5_NS, LPI2C6_NS, LPI2C7_NS, LPI2C8_NS }
#else
  /** Peripheral LPI2C1 base address */
  #define LPI2C1_BASE                              (0x44340000u)
  /** Peripheral LPI2C1 base pointer */
  #define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
  /** Peripheral LPI2C2 base address */
  #define LPI2C2_BASE                              (0x44350000u)
  /** Peripheral LPI2C2 base pointer */
  #define LPI2C2                                   ((LPI2C_Type *)LPI2C2_BASE)
  /** Peripheral LPI2C3 base address */
  #define LPI2C3_BASE                              (0x42150000u)
  /** Peripheral LPI2C3 base pointer */
  #define LPI2C3                                   ((LPI2C_Type *)LPI2C3_BASE)
  /** Peripheral LPI2C4 base address */
  #define LPI2C4_BASE                              (0x42160000u)
  /** Peripheral LPI2C4 base pointer */
  #define LPI2C4                                   ((LPI2C_Type *)LPI2C4_BASE)
  /** Peripheral LPI2C5 base address */
  #define LPI2C5_BASE                              (0x422D0000u)
  /** Peripheral LPI2C5 base pointer */
  #define LPI2C5                                   ((LPI2C_Type *)LPI2C5_BASE)
  /** Peripheral LPI2C6 base address */
  #define LPI2C6_BASE                              (0x422E0000u)
  /** Peripheral LPI2C6 base pointer */
  #define LPI2C6                                   ((LPI2C_Type *)LPI2C6_BASE)
  /** Peripheral LPI2C7 base address */
  #define LPI2C7_BASE                              (0x422F0000u)
  /** Peripheral LPI2C7 base pointer */
  #define LPI2C7                                   ((LPI2C_Type *)LPI2C7_BASE)
  /** Peripheral LPI2C8 base address */
  #define LPI2C8_BASE                              (0x42300000u)
  /** Peripheral LPI2C8 base pointer */
  #define LPI2C8                                   ((LPI2C_Type *)LPI2C8_BASE)
  /** Array initializer of LPI2C peripheral base addresses */
  #define LPI2C_BASE_ADDRS                         { 0u, LPI2C1_BASE, LPI2C2_BASE, LPI2C3_BASE, LPI2C4_BASE, LPI2C5_BASE, LPI2C6_BASE, LPI2C7_BASE, LPI2C8_BASE }
  /** Array initializer of LPI2C peripheral base pointers */
  #define LPI2C_BASE_PTRS                          { (LPI2C_Type *)0u, LPI2C1, LPI2C2, LPI2C3, LPI2C4, LPI2C5, LPI2C6, LPI2C7, LPI2C8 }
#endif
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { NotAvail_IRQn, LPI2C1_IRQn, LPI2C2_IRQn, LPI2C3_IRQn, LPI2C4_IRQn, LPI2C5_IRQn, LPI2C6_IRQn, LPI2C7_IRQn, LPI2C8_IRQn }

/* LPIT - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPIT1 base address */
  #define LPIT1_BASE                               (0x542F0000u)
  /** Peripheral LPIT1 base address */
  #define LPIT1_BASE_NS                            (0x442F0000u)
  /** Peripheral LPIT1 base pointer */
  #define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
  /** Peripheral LPIT1 base pointer */
  #define LPIT1_NS                                 ((LPIT_Type *)LPIT1_BASE_NS)
  /** Peripheral LPIT2 base address */
  #define LPIT2_BASE                               (0x520E0000u)
  /** Peripheral LPIT2 base address */
  #define LPIT2_BASE_NS                            (0x420E0000u)
  /** Peripheral LPIT2 base pointer */
  #define LPIT2                                    ((LPIT_Type *)LPIT2_BASE)
  /** Peripheral LPIT2 base pointer */
  #define LPIT2_NS                                 ((LPIT_Type *)LPIT2_BASE_NS)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { 0u, LPIT1_BASE, LPIT2_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { (LPIT_Type *)0u, LPIT1, LPIT2 }
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS_NS                       { 0u, LPIT1_BASE_NS, LPIT2_BASE_NS }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS_NS                        { (LPIT_Type *)0u, LPIT1_NS, LPIT2_NS }
#else
  /** Peripheral LPIT1 base address */
  #define LPIT1_BASE                               (0x442F0000u)
  /** Peripheral LPIT1 base pointer */
  #define LPIT1                                    ((LPIT_Type *)LPIT1_BASE)
  /** Peripheral LPIT2 base address */
  #define LPIT2_BASE                               (0x420E0000u)
  /** Peripheral LPIT2 base pointer */
  #define LPIT2                                    ((LPIT_Type *)LPIT2_BASE)
  /** Array initializer of LPIT peripheral base addresses */
  #define LPIT_BASE_ADDRS                          { 0u, LPIT1_BASE, LPIT2_BASE }
  /** Array initializer of LPIT peripheral base pointers */
  #define LPIT_BASE_PTRS                           { (LPIT_Type *)0u, LPIT1, LPIT2 }
#endif

/* LPSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x54360000u)
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE_NS                           (0x44360000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1_NS                                ((LPSPI_Type *)LPSPI1_BASE_NS)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE                              (0x54370000u)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE_NS                           (0x44370000u)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2_NS                                ((LPSPI_Type *)LPSPI2_BASE_NS)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE                              (0x52170000u)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE_NS                           (0x42170000u)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3_NS                                ((LPSPI_Type *)LPSPI3_BASE_NS)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE                              (0x52180000u)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE_NS                           (0x42180000u)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4_NS                                ((LPSPI_Type *)LPSPI4_BASE_NS)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE                              (0x52310000u)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE_NS                           (0x42310000u)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5_NS                                ((LPSPI_Type *)LPSPI5_BASE_NS)
  /** Peripheral LPSPI6 base address */
  #define LPSPI6_BASE                              (0x52320000u)
  /** Peripheral LPSPI6 base address */
  #define LPSPI6_BASE_NS                           (0x42320000u)
  /** Peripheral LPSPI6 base pointer */
  #define LPSPI6                                   ((LPSPI_Type *)LPSPI6_BASE)
  /** Peripheral LPSPI6 base pointer */
  #define LPSPI6_NS                                ((LPSPI_Type *)LPSPI6_BASE_NS)
  /** Peripheral LPSPI7 base address */
  #define LPSPI7_BASE                              (0x52330000u)
  /** Peripheral LPSPI7 base address */
  #define LPSPI7_BASE_NS                           (0x42330000u)
  /** Peripheral LPSPI7 base pointer */
  #define LPSPI7                                   ((LPSPI_Type *)LPSPI7_BASE)
  /** Peripheral LPSPI7 base pointer */
  #define LPSPI7_NS                                ((LPSPI_Type *)LPSPI7_BASE_NS)
  /** Peripheral LPSPI8 base address */
  #define LPSPI8_BASE                              (0x52340000u)
  /** Peripheral LPSPI8 base address */
  #define LPSPI8_BASE_NS                           (0x42340000u)
  /** Peripheral LPSPI8 base pointer */
  #define LPSPI8                                   ((LPSPI_Type *)LPSPI8_BASE)
  /** Peripheral LPSPI8 base pointer */
  #define LPSPI8_NS                                ((LPSPI_Type *)LPSPI8_BASE_NS)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE, LPSPI6_BASE, LPSPI7_BASE, LPSPI8_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5, LPSPI6, LPSPI7, LPSPI8 }
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS_NS                      { 0u, LPSPI1_BASE_NS, LPSPI2_BASE_NS, LPSPI3_BASE_NS, LPSPI4_BASE_NS, LPSPI5_BASE_NS, LPSPI6_BASE_NS, LPSPI7_BASE_NS, LPSPI8_BASE_NS }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS_NS                       { (LPSPI_Type *)0u, LPSPI1_NS, LPSPI2_NS, LPSPI3_NS, LPSPI4_NS, LPSPI5_NS, LPSPI6_NS, LPSPI7_NS, LPSPI8_NS }
#else
  /** Peripheral LPSPI1 base address */
  #define LPSPI1_BASE                              (0x44360000u)
  /** Peripheral LPSPI1 base pointer */
  #define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
  /** Peripheral LPSPI2 base address */
  #define LPSPI2_BASE                              (0x44370000u)
  /** Peripheral LPSPI2 base pointer */
  #define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
  /** Peripheral LPSPI3 base address */
  #define LPSPI3_BASE                              (0x42170000u)
  /** Peripheral LPSPI3 base pointer */
  #define LPSPI3                                   ((LPSPI_Type *)LPSPI3_BASE)
  /** Peripheral LPSPI4 base address */
  #define LPSPI4_BASE                              (0x42180000u)
  /** Peripheral LPSPI4 base pointer */
  #define LPSPI4                                   ((LPSPI_Type *)LPSPI4_BASE)
  /** Peripheral LPSPI5 base address */
  #define LPSPI5_BASE                              (0x42310000u)
  /** Peripheral LPSPI5 base pointer */
  #define LPSPI5                                   ((LPSPI_Type *)LPSPI5_BASE)
  /** Peripheral LPSPI6 base address */
  #define LPSPI6_BASE                              (0x42320000u)
  /** Peripheral LPSPI6 base pointer */
  #define LPSPI6                                   ((LPSPI_Type *)LPSPI6_BASE)
  /** Peripheral LPSPI7 base address */
  #define LPSPI7_BASE                              (0x42330000u)
  /** Peripheral LPSPI7 base pointer */
  #define LPSPI7                                   ((LPSPI_Type *)LPSPI7_BASE)
  /** Peripheral LPSPI8 base address */
  #define LPSPI8_BASE                              (0x42340000u)
  /** Peripheral LPSPI8 base pointer */
  #define LPSPI8                                   ((LPSPI_Type *)LPSPI8_BASE)
  /** Array initializer of LPSPI peripheral base addresses */
  #define LPSPI_BASE_ADDRS                         { 0u, LPSPI1_BASE, LPSPI2_BASE, LPSPI3_BASE, LPSPI4_BASE, LPSPI5_BASE, LPSPI6_BASE, LPSPI7_BASE, LPSPI8_BASE }
  /** Array initializer of LPSPI peripheral base pointers */
  #define LPSPI_BASE_PTRS                          { (LPSPI_Type *)0u, LPSPI1, LPSPI2, LPSPI3, LPSPI4, LPSPI5, LPSPI6, LPSPI7, LPSPI8 }
#endif
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { NotAvail_IRQn, LPSPI1_IRQn, LPSPI2_IRQn, LPSPI3_IRQn, LPSPI4_IRQn, LPSPI5_IRQn, LPSPI6_IRQn, LPSPI7_IRQn, LPSPI8_IRQn }

/* LPTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE                              (0x54300000u)
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE_NS                           (0x44300000u)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1_NS                                ((LPTMR_Type *)LPTMR1_BASE_NS)
  /** Peripheral LPTMR2 base address */
  #define LPTMR2_BASE                              (0x520F0000u)
  /** Peripheral LPTMR2 base address */
  #define LPTMR2_BASE_NS                           (0x420F0000u)
  /** Peripheral LPTMR2 base pointer */
  #define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
  /** Peripheral LPTMR2 base pointer */
  #define LPTMR2_NS                                ((LPTMR_Type *)LPTMR2_BASE_NS)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { 0u, LPTMR1_BASE, LPTMR2_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { (LPTMR_Type *)0u, LPTMR1, LPTMR2 }
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS_NS                      { 0u, LPTMR1_BASE_NS, LPTMR2_BASE_NS }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS_NS                       { (LPTMR_Type *)0u, LPTMR1_NS, LPTMR2_NS }
#else
  /** Peripheral LPTMR1 base address */
  #define LPTMR1_BASE                              (0x44300000u)
  /** Peripheral LPTMR1 base pointer */
  #define LPTMR1                                   ((LPTMR_Type *)LPTMR1_BASE)
  /** Peripheral LPTMR2 base address */
  #define LPTMR2_BASE                              (0x420F0000u)
  /** Peripheral LPTMR2 base pointer */
  #define LPTMR2                                   ((LPTMR_Type *)LPTMR2_BASE)
  /** Array initializer of LPTMR peripheral base addresses */
  #define LPTMR_BASE_ADDRS                         { 0u, LPTMR1_BASE, LPTMR2_BASE }
  /** Array initializer of LPTMR peripheral base pointers */
  #define LPTMR_BASE_PTRS                          { (LPTMR_Type *)0u, LPTMR1, LPTMR2 }
#endif
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { NotAvail_IRQn, LPTMR1_IRQn, LPTMR2_IRQn }

/* LPUART - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x54380000u)
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE_NS                          (0x44380000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1_NS                               ((LPUART_Type *)LPUART1_BASE_NS)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE                             (0x54390000u)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE_NS                          (0x44390000u)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2_NS                               ((LPUART_Type *)LPUART2_BASE_NS)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE                             (0x52190000u)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE_NS                          (0x42190000u)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3_NS                               ((LPUART_Type *)LPUART3_BASE_NS)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE                             (0x521A0000u)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE_NS                          (0x421A0000u)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4_NS                               ((LPUART_Type *)LPUART4_BASE_NS)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE                             (0x521B0000u)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE_NS                          (0x421B0000u)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5_NS                               ((LPUART_Type *)LPUART5_BASE_NS)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE                             (0x521C0000u)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE_NS                          (0x421C0000u)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6_NS                               ((LPUART_Type *)LPUART6_BASE_NS)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE                             (0x522B0000u)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE_NS                          (0x422B0000u)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7_NS                               ((LPUART_Type *)LPUART7_BASE_NS)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE                             (0x522C0000u)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE_NS                          (0x422C0000u)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8_NS                               ((LPUART_Type *)LPUART8_BASE_NS)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8 }
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS_NS                     { 0u, LPUART1_BASE_NS, LPUART2_BASE_NS, LPUART3_BASE_NS, LPUART4_BASE_NS, LPUART5_BASE_NS, LPUART6_BASE_NS, LPUART7_BASE_NS, LPUART8_BASE_NS }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS_NS                      { (LPUART_Type *)0u, LPUART1_NS, LPUART2_NS, LPUART3_NS, LPUART4_NS, LPUART5_NS, LPUART6_NS, LPUART7_NS, LPUART8_NS }
#else
  /** Peripheral LPUART1 base address */
  #define LPUART1_BASE                             (0x44380000u)
  /** Peripheral LPUART1 base pointer */
  #define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
  /** Peripheral LPUART2 base address */
  #define LPUART2_BASE                             (0x44390000u)
  /** Peripheral LPUART2 base pointer */
  #define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
  /** Peripheral LPUART3 base address */
  #define LPUART3_BASE                             (0x42190000u)
  /** Peripheral LPUART3 base pointer */
  #define LPUART3                                  ((LPUART_Type *)LPUART3_BASE)
  /** Peripheral LPUART4 base address */
  #define LPUART4_BASE                             (0x421A0000u)
  /** Peripheral LPUART4 base pointer */
  #define LPUART4                                  ((LPUART_Type *)LPUART4_BASE)
  /** Peripheral LPUART5 base address */
  #define LPUART5_BASE                             (0x421B0000u)
  /** Peripheral LPUART5 base pointer */
  #define LPUART5                                  ((LPUART_Type *)LPUART5_BASE)
  /** Peripheral LPUART6 base address */
  #define LPUART6_BASE                             (0x421C0000u)
  /** Peripheral LPUART6 base pointer */
  #define LPUART6                                  ((LPUART_Type *)LPUART6_BASE)
  /** Peripheral LPUART7 base address */
  #define LPUART7_BASE                             (0x422B0000u)
  /** Peripheral LPUART7 base pointer */
  #define LPUART7                                  ((LPUART_Type *)LPUART7_BASE)
  /** Peripheral LPUART8 base address */
  #define LPUART8_BASE                             (0x422C0000u)
  /** Peripheral LPUART8 base pointer */
  #define LPUART8                                  ((LPUART_Type *)LPUART8_BASE)
  /** Array initializer of LPUART peripheral base addresses */
  #define LPUART_BASE_ADDRS                        { 0u, LPUART1_BASE, LPUART2_BASE, LPUART3_BASE, LPUART4_BASE, LPUART5_BASE, LPUART6_BASE, LPUART7_BASE, LPUART8_BASE }
  /** Array initializer of LPUART peripheral base pointers */
  #define LPUART_BASE_PTRS                         { (LPUART_Type *)0u, LPUART1, LPUART2, LPUART3, LPUART4, LPUART5, LPUART6, LPUART7, LPUART8 }
#endif
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { NotAvail_IRQn, LPUART1_IRQn, LPUART2_IRQn, LPUART3_IRQn, LPUART4_IRQn, LPUART5_IRQn, LPUART6_IRQn, LPUART7_IRQn, LPUART8_IRQn }

/* M7_A7_APB_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral M7__A7_APB_MCM1 base address */
  #define M7__A7_APB_MCM1_BASE                     (0x5A0A0000u)
  /** Peripheral M7__A7_APB_MCM1 base address */
  #define M7__A7_APB_MCM1_BASE_NS                  (0x4A0A0000u)
  /** Peripheral M7__A7_APB_MCM1 base pointer */
  #define M7__A7_APB_MCM1                          ((M7_A7_APB_MCM_Type *)M7__A7_APB_MCM1_BASE)
  /** Peripheral M7__A7_APB_MCM1 base pointer */
  #define M7__A7_APB_MCM1_NS                       ((M7_A7_APB_MCM_Type *)M7__A7_APB_MCM1_BASE_NS)
  /** Array initializer of M7_A7_APB_MCM peripheral base addresses */
  #define M7_A7_APB_MCM_BASE_ADDRS                 { M7__A7_APB_MCM1_BASE }
  /** Array initializer of M7_A7_APB_MCM peripheral base pointers */
  #define M7_A7_APB_MCM_BASE_PTRS                  { M7__A7_APB_MCM1 }
  /** Array initializer of M7_A7_APB_MCM peripheral base addresses */
  #define M7_A7_APB_MCM_BASE_ADDRS_NS              { M7__A7_APB_MCM1_BASE_NS }
  /** Array initializer of M7_A7_APB_MCM peripheral base pointers */
  #define M7_A7_APB_MCM_BASE_PTRS_NS               { M7__A7_APB_MCM1_NS }
#else
  /** Peripheral M7__A7_APB_MCM1 base address */
  #define M7__A7_APB_MCM1_BASE                     (0x4A0A0000u)
  /** Peripheral M7__A7_APB_MCM1 base pointer */
  #define M7__A7_APB_MCM1                          ((M7_A7_APB_MCM_Type *)M7__A7_APB_MCM1_BASE)
  /** Array initializer of M7_A7_APB_MCM peripheral base addresses */
  #define M7_A7_APB_MCM_BASE_ADDRS                 { M7__A7_APB_MCM1_BASE }
  /** Array initializer of M7_A7_APB_MCM peripheral base pointers */
  #define M7_A7_APB_MCM_BASE_PTRS                  { M7__A7_APB_MCM1 }
#endif

/* MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__MCM base address */
  #define AON__MCM_BASE                            (0xF0080000u)
  /** Peripheral AON__MCM base address */
  #define AON__MCM_BASE_NS                         (0xE0080000u)
  /** Peripheral AON__MCM base pointer */
  #define AON__MCM                                 ((MCM_Type *)AON__MCM_BASE)
  /** Peripheral AON__MCM base pointer */
  #define AON__MCM_NS                              ((MCM_Type *)AON__MCM_BASE_NS)
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS                           { AON__MCM_BASE }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS                            { AON__MCM }
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS_NS                        { AON__MCM_BASE_NS }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS_NS                         { AON__MCM_NS }
#else
  /** Peripheral AON__MCM base address */
  #define AON__MCM_BASE                            (0xE0080000u)
  /** Peripheral AON__MCM base pointer */
  #define AON__MCM                                 ((MCM_Type *)AON__MCM_BASE)
  /** Array initializer of MCM peripheral base addresses */
  #define MCM_BASE_ADDRS                           { AON__MCM_BASE }
  /** Array initializer of MCM peripheral base pointers */
  #define MCM_BASE_PTRS                            { AON__MCM }
#endif

/* MSGINTR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MSGINTR1 base address */
  #define MSGINTR1_BASE                            (0x54690000u)
  /** Peripheral MSGINTR1 base address */
  #define MSGINTR1_BASE_NS                         (0x44690000u)
  /** Peripheral MSGINTR1 base pointer */
  #define MSGINTR1                                 ((MSGINTR_Type *)MSGINTR1_BASE)
  /** Peripheral MSGINTR1 base pointer */
  #define MSGINTR1_NS                              ((MSGINTR_Type *)MSGINTR1_BASE_NS)
  /** Peripheral MSGINTR2 base address */
  #define MSGINTR2_BASE                            (0x546A0000u)
  /** Peripheral MSGINTR2 base address */
  #define MSGINTR2_BASE_NS                         (0x446A0000u)
  /** Peripheral MSGINTR2 base pointer */
  #define MSGINTR2                                 ((MSGINTR_Type *)MSGINTR2_BASE)
  /** Peripheral MSGINTR2 base pointer */
  #define MSGINTR2_NS                              ((MSGINTR_Type *)MSGINTR2_BASE_NS)
  /** Array initializer of MSGINTR peripheral base addresses */
  #define MSGINTR_BASE_ADDRS                       { 0u, MSGINTR1_BASE, MSGINTR2_BASE }
  /** Array initializer of MSGINTR peripheral base pointers */
  #define MSGINTR_BASE_PTRS                        { (MSGINTR_Type *)0u, MSGINTR1, MSGINTR2 }
  /** Array initializer of MSGINTR peripheral base addresses */
  #define MSGINTR_BASE_ADDRS_NS                    { 0u, MSGINTR1_BASE_NS, MSGINTR2_BASE_NS }
  /** Array initializer of MSGINTR peripheral base pointers */
  #define MSGINTR_BASE_PTRS_NS                     { (MSGINTR_Type *)0u, MSGINTR1_NS, MSGINTR2_NS }
#else
  /** Peripheral MSGINTR1 base address */
  #define MSGINTR1_BASE                            (0x44690000u)
  /** Peripheral MSGINTR1 base pointer */
  #define MSGINTR1                                 ((MSGINTR_Type *)MSGINTR1_BASE)
  /** Peripheral MSGINTR2 base address */
  #define MSGINTR2_BASE                            (0x446A0000u)
  /** Peripheral MSGINTR2 base pointer */
  #define MSGINTR2                                 ((MSGINTR_Type *)MSGINTR2_BASE)
  /** Array initializer of MSGINTR peripheral base addresses */
  #define MSGINTR_BASE_ADDRS                       { 0u, MSGINTR1_BASE, MSGINTR2_BASE }
  /** Array initializer of MSGINTR peripheral base pointers */
  #define MSGINTR_BASE_PTRS                        { (MSGINTR_Type *)0u, MSGINTR1, MSGINTR2 }
#endif
/** Interrupt vectors for the MSGINTR peripheral type */
#define MSGINTR_IRQS                             { NotAvail_IRQn, MSGINTR1_IRQn, MSGINTR2_IRQn }

/* MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE                             (0x54220000u)
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE_NS                          (0x44220000u)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA_NS                               ((MU_Type *)MU1_MUA_BASE_NS)
  /** Peripheral MU1_MUB base address */
  #define MU1_MUB_BASE                             (0x54230000u)
  /** Peripheral MU1_MUB base address */
  #define MU1_MUB_BASE_NS                          (0x44230000u)
  /** Peripheral MU1_MUB base pointer */
  #define MU1_MUB                                  ((MU_Type *)MU1_MUB_BASE)
  /** Peripheral MU1_MUB base pointer */
  #define MU1_MUB_NS                               ((MU_Type *)MU1_MUB_BASE_NS)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE                             (0x545B0000u)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE_NS                          (0x445B0000u)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA                                  ((MU_Type *)MU2_MUA_BASE)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA_NS                               ((MU_Type *)MU2_MUA_BASE_NS)
  /** Peripheral MU2_MUB base address */
  #define MU2_MUB_BASE                             (0x545C0000u)
  /** Peripheral MU2_MUB base address */
  #define MU2_MUB_BASE_NS                          (0x445C0000u)
  /** Peripheral MU2_MUB base pointer */
  #define MU2_MUB                                  ((MU_Type *)MU2_MUB_BASE)
  /** Peripheral MU2_MUB base pointer */
  #define MU2_MUB_NS                               ((MU_Type *)MU2_MUB_BASE_NS)
  /** Peripheral MU3_MUA base address */
  #define MU3_MUA_BASE                             (0x545D0000u)
  /** Peripheral MU3_MUA base address */
  #define MU3_MUA_BASE_NS                          (0x445D0000u)
  /** Peripheral MU3_MUA base pointer */
  #define MU3_MUA                                  ((MU_Type *)MU3_MUA_BASE)
  /** Peripheral MU3_MUA base pointer */
  #define MU3_MUA_NS                               ((MU_Type *)MU3_MUA_BASE_NS)
  /** Peripheral MU3_MUB base address */
  #define MU3_MUB_BASE                             (0x545E0000u)
  /** Peripheral MU3_MUB base address */
  #define MU3_MUB_BASE_NS                          (0x445E0000u)
  /** Peripheral MU3_MUB base pointer */
  #define MU3_MUB                                  ((MU_Type *)MU3_MUB_BASE)
  /** Peripheral MU3_MUB base pointer */
  #define MU3_MUB_NS                               ((MU_Type *)MU3_MUB_BASE_NS)
  /** Peripheral MU4_MUA base address */
  #define MU4_MUA_BASE                             (0x545F0000u)
  /** Peripheral MU4_MUA base address */
  #define MU4_MUA_BASE_NS                          (0x445F0000u)
  /** Peripheral MU4_MUA base pointer */
  #define MU4_MUA                                  ((MU_Type *)MU4_MUA_BASE)
  /** Peripheral MU4_MUA base pointer */
  #define MU4_MUA_NS                               ((MU_Type *)MU4_MUA_BASE_NS)
  /** Peripheral MU4_MUB base address */
  #define MU4_MUB_BASE                             (0x54600000u)
  /** Peripheral MU4_MUB base address */
  #define MU4_MUB_BASE_NS                          (0x44600000u)
  /** Peripheral MU4_MUB base pointer */
  #define MU4_MUB                                  ((MU_Type *)MU4_MUB_BASE)
  /** Peripheral MU4_MUB base pointer */
  #define MU4_MUB_NS                               ((MU_Type *)MU4_MUB_BASE_NS)
  /** Peripheral MU5_MUA base address */
  #define MU5_MUA_BASE                             (0x54610000u)
  /** Peripheral MU5_MUA base address */
  #define MU5_MUA_BASE_NS                          (0x44610000u)
  /** Peripheral MU5_MUA base pointer */
  #define MU5_MUA                                  ((MU_Type *)MU5_MUA_BASE)
  /** Peripheral MU5_MUA base pointer */
  #define MU5_MUA_NS                               ((MU_Type *)MU5_MUA_BASE_NS)
  /** Peripheral MU5_MUB base address */
  #define MU5_MUB_BASE                             (0x54620000u)
  /** Peripheral MU5_MUB base address */
  #define MU5_MUB_BASE_NS                          (0x44620000u)
  /** Peripheral MU5_MUB base pointer */
  #define MU5_MUB                                  ((MU_Type *)MU5_MUB_BASE)
  /** Peripheral MU5_MUB base pointer */
  #define MU5_MUB_NS                               ((MU_Type *)MU5_MUB_BASE_NS)
  /** Peripheral MU6_MUA base address */
  #define MU6_MUA_BASE                             (0x54630000u)
  /** Peripheral MU6_MUA base address */
  #define MU6_MUA_BASE_NS                          (0x44630000u)
  /** Peripheral MU6_MUA base pointer */
  #define MU6_MUA                                  ((MU_Type *)MU6_MUA_BASE)
  /** Peripheral MU6_MUA base pointer */
  #define MU6_MUA_NS                               ((MU_Type *)MU6_MUA_BASE_NS)
  /** Peripheral MU6_MUB base address */
  #define MU6_MUB_BASE                             (0x54640000u)
  /** Peripheral MU6_MUB base address */
  #define MU6_MUB_BASE_NS                          (0x44640000u)
  /** Peripheral MU6_MUB base pointer */
  #define MU6_MUB                                  ((MU_Type *)MU6_MUB_BASE)
  /** Peripheral MU6_MUB base pointer */
  #define MU6_MUB_NS                               ((MU_Type *)MU6_MUB_BASE_NS)
  /** Peripheral MU7_MUA base address */
  #define MU7_MUA_BASE                             (0x52050000u)
  /** Peripheral MU7_MUA base address */
  #define MU7_MUA_BASE_NS                          (0x42050000u)
  /** Peripheral MU7_MUA base pointer */
  #define MU7_MUA                                  ((MU_Type *)MU7_MUA_BASE)
  /** Peripheral MU7_MUA base pointer */
  #define MU7_MUA_NS                               ((MU_Type *)MU7_MUA_BASE_NS)
  /** Peripheral MU7_MUB base address */
  #define MU7_MUB_BASE                             (0x52060000u)
  /** Peripheral MU7_MUB base address */
  #define MU7_MUB_BASE_NS                          (0x42060000u)
  /** Peripheral MU7_MUB base pointer */
  #define MU7_MUB                                  ((MU_Type *)MU7_MUB_BASE)
  /** Peripheral MU7_MUB base pointer */
  #define MU7_MUB_NS                               ((MU_Type *)MU7_MUB_BASE_NS)
  /** Peripheral MU8_MUA base address */
  #define MU8_MUA_BASE                             (0x52350000u)
  /** Peripheral MU8_MUA base address */
  #define MU8_MUA_BASE_NS                          (0x42350000u)
  /** Peripheral MU8_MUA base pointer */
  #define MU8_MUA                                  ((MU_Type *)MU8_MUA_BASE)
  /** Peripheral MU8_MUA base pointer */
  #define MU8_MUA_NS                               ((MU_Type *)MU8_MUA_BASE_NS)
  /** Peripheral MU8_MUB base address */
  #define MU8_MUB_BASE                             (0x52360000u)
  /** Peripheral MU8_MUB base address */
  #define MU8_MUB_BASE_NS                          (0x42360000u)
  /** Peripheral MU8_MUB base pointer */
  #define MU8_MUB                                  ((MU_Type *)MU8_MUB_BASE)
  /** Peripheral MU8_MUB base pointer */
  #define MU8_MUB_NS                               ((MU_Type *)MU8_MUB_BASE_NS)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU1_MUA_BASE, MU1_MUB_BASE, MU2_MUA_BASE, MU2_MUB_BASE, MU3_MUA_BASE, MU3_MUB_BASE, MU4_MUA_BASE, MU4_MUB_BASE, MU5_MUA_BASE, MU5_MUB_BASE, MU6_MUA_BASE, MU6_MUB_BASE, MU7_MUA_BASE, MU7_MUB_BASE, MU8_MUA_BASE, MU8_MUB_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU1_MUA, MU1_MUB, MU2_MUA, MU2_MUB, MU3_MUA, MU3_MUB, MU4_MUA, MU4_MUB, MU5_MUA, MU5_MUB, MU6_MUA, MU6_MUB, MU7_MUA, MU7_MUB, MU8_MUA, MU8_MUB }
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS_NS                         { MU1_MUA_BASE_NS, MU1_MUB_BASE_NS, MU2_MUA_BASE_NS, MU2_MUB_BASE_NS, MU3_MUA_BASE_NS, MU3_MUB_BASE_NS, MU4_MUA_BASE_NS, MU4_MUB_BASE_NS, MU5_MUA_BASE_NS, MU5_MUB_BASE_NS, MU6_MUA_BASE_NS, MU6_MUB_BASE_NS, MU7_MUA_BASE_NS, MU7_MUB_BASE_NS, MU8_MUA_BASE_NS, MU8_MUB_BASE_NS }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS_NS                          { MU1_MUA_NS, MU1_MUB_NS, MU2_MUA_NS, MU2_MUB_NS, MU3_MUA_NS, MU3_MUB_NS, MU4_MUA_NS, MU4_MUB_NS, MU5_MUA_NS, MU5_MUB_NS, MU6_MUA_NS, MU6_MUB_NS, MU7_MUA_NS, MU7_MUB_NS, MU8_MUA_NS, MU8_MUB_NS }
#else
  /** Peripheral MU1_MUA base address */
  #define MU1_MUA_BASE                             (0x44220000u)
  /** Peripheral MU1_MUA base pointer */
  #define MU1_MUA                                  ((MU_Type *)MU1_MUA_BASE)
  /** Peripheral MU1_MUB base address */
  #define MU1_MUB_BASE                             (0x44230000u)
  /** Peripheral MU1_MUB base pointer */
  #define MU1_MUB                                  ((MU_Type *)MU1_MUB_BASE)
  /** Peripheral MU2_MUA base address */
  #define MU2_MUA_BASE                             (0x445B0000u)
  /** Peripheral MU2_MUA base pointer */
  #define MU2_MUA                                  ((MU_Type *)MU2_MUA_BASE)
  /** Peripheral MU2_MUB base address */
  #define MU2_MUB_BASE                             (0x445C0000u)
  /** Peripheral MU2_MUB base pointer */
  #define MU2_MUB                                  ((MU_Type *)MU2_MUB_BASE)
  /** Peripheral MU3_MUA base address */
  #define MU3_MUA_BASE                             (0x445D0000u)
  /** Peripheral MU3_MUA base pointer */
  #define MU3_MUA                                  ((MU_Type *)MU3_MUA_BASE)
  /** Peripheral MU3_MUB base address */
  #define MU3_MUB_BASE                             (0x445E0000u)
  /** Peripheral MU3_MUB base pointer */
  #define MU3_MUB                                  ((MU_Type *)MU3_MUB_BASE)
  /** Peripheral MU4_MUA base address */
  #define MU4_MUA_BASE                             (0x445F0000u)
  /** Peripheral MU4_MUA base pointer */
  #define MU4_MUA                                  ((MU_Type *)MU4_MUA_BASE)
  /** Peripheral MU4_MUB base address */
  #define MU4_MUB_BASE                             (0x44600000u)
  /** Peripheral MU4_MUB base pointer */
  #define MU4_MUB                                  ((MU_Type *)MU4_MUB_BASE)
  /** Peripheral MU5_MUA base address */
  #define MU5_MUA_BASE                             (0x44610000u)
  /** Peripheral MU5_MUA base pointer */
  #define MU5_MUA                                  ((MU_Type *)MU5_MUA_BASE)
  /** Peripheral MU5_MUB base address */
  #define MU5_MUB_BASE                             (0x44620000u)
  /** Peripheral MU5_MUB base pointer */
  #define MU5_MUB                                  ((MU_Type *)MU5_MUB_BASE)
  /** Peripheral MU6_MUA base address */
  #define MU6_MUA_BASE                             (0x44630000u)
  /** Peripheral MU6_MUA base pointer */
  #define MU6_MUA                                  ((MU_Type *)MU6_MUA_BASE)
  /** Peripheral MU6_MUB base address */
  #define MU6_MUB_BASE                             (0x44640000u)
  /** Peripheral MU6_MUB base pointer */
  #define MU6_MUB                                  ((MU_Type *)MU6_MUB_BASE)
  /** Peripheral MU7_MUA base address */
  #define MU7_MUA_BASE                             (0x42050000u)
  /** Peripheral MU7_MUA base pointer */
  #define MU7_MUA                                  ((MU_Type *)MU7_MUA_BASE)
  /** Peripheral MU7_MUB base address */
  #define MU7_MUB_BASE                             (0x42060000u)
  /** Peripheral MU7_MUB base pointer */
  #define MU7_MUB                                  ((MU_Type *)MU7_MUB_BASE)
  /** Peripheral MU8_MUA base address */
  #define MU8_MUA_BASE                             (0x42350000u)
  /** Peripheral MU8_MUA base pointer */
  #define MU8_MUA                                  ((MU_Type *)MU8_MUA_BASE)
  /** Peripheral MU8_MUB base address */
  #define MU8_MUB_BASE                             (0x42360000u)
  /** Peripheral MU8_MUB base pointer */
  #define MU8_MUB                                  ((MU_Type *)MU8_MUB_BASE)
  /** Array initializer of MU peripheral base addresses */
  #define MU_BASE_ADDRS                            { MU1_MUA_BASE, MU1_MUB_BASE, MU2_MUA_BASE, MU2_MUB_BASE, MU3_MUA_BASE, MU3_MUB_BASE, MU4_MUA_BASE, MU4_MUB_BASE, MU5_MUA_BASE, MU5_MUB_BASE, MU6_MUA_BASE, MU6_MUB_BASE, MU7_MUA_BASE, MU7_MUB_BASE, MU8_MUA_BASE, MU8_MUB_BASE }
  /** Array initializer of MU peripheral base pointers */
  #define MU_BASE_PTRS                             { MU1_MUA, MU1_MUB, MU2_MUA, MU2_MUB, MU3_MUA, MU3_MUB, MU4_MUA, MU4_MUB, MU5_MUA, MU5_MUB, MU6_MUA, MU6_MUB, MU7_MUA, MU7_MUB, MU8_MUA, MU8_MUB }
#endif
/** Interrupt vectors for the MU peripheral type */
#define MU_IRQS                                  { MU1_A_IRQn, MU1_B_IRQn, MU2_A_IRQn, MU2_B_IRQn, MU3_A_IRQn, MU3_B_IRQn, MU4_A_IRQn, MU4_B_IRQn, MU5_A_IRQn, MU5_B_IRQn, MU6_A_IRQn, MU6_B_IRQn, MU7_A_IRQn, MU7_B_IRQn, MU8_A_IRQn, MU8_B_IRQn }
/*!
 * @brief Core boot mode.
 */
// typedef enum _mu_core_boot_mode
// {
//     kMU_CoreBootFromAddr0 = 0x00U, /*!< Boot from 0x00.      */
//     kMU_CoreBootFromFlash = 0x01U, /*!< Boot from Flash base. */
//     kMU_CoreBootFromItcm  = 0x02U, /*!< Boot from ITCM base. */
// } mu_core_boot_mode_t;


/* NETC_EMDIO_BASE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__EMDIO_BASE base address */
  #define NETC__NETC__EMDIO_BASE_BASE              (0x5CCA0000u)
  /** Peripheral NETC__NETC__EMDIO_BASE base address */
  #define NETC__NETC__EMDIO_BASE_BASE_NS           (0x4CCA0000u)
  /** Peripheral NETC__NETC__EMDIO_BASE base pointer */
  #define NETC__NETC__EMDIO_BASE                   ((NETC_EMDIO_BASE_Type *)NETC__NETC__EMDIO_BASE_BASE)
  /** Peripheral NETC__NETC__EMDIO_BASE base pointer */
  #define NETC__NETC__EMDIO_BASE_NS                ((NETC_EMDIO_BASE_Type *)NETC__NETC__EMDIO_BASE_BASE_NS)
  /** Array initializer of NETC_EMDIO_BASE peripheral base addresses */
  #define NETC_EMDIO_BASE_BASE_ADDRS               { NETC__NETC__EMDIO_BASE_BASE }
  /** Array initializer of NETC_EMDIO_BASE peripheral base pointers */
  #define NETC_EMDIO_BASE_BASE_PTRS                { NETC__NETC__EMDIO_BASE }
  /** Array initializer of NETC_EMDIO_BASE peripheral base addresses */
  #define NETC_EMDIO_BASE_BASE_ADDRS_NS            { NETC__NETC__EMDIO_BASE_BASE_NS }
  /** Array initializer of NETC_EMDIO_BASE peripheral base pointers */
  #define NETC_EMDIO_BASE_BASE_PTRS_NS             { NETC__NETC__EMDIO_BASE_NS }
#else
  /** Peripheral NETC__NETC__EMDIO_BASE base address */
  #define NETC__NETC__EMDIO_BASE_BASE              (0x4CCA0000u)
  /** Peripheral NETC__NETC__EMDIO_BASE base pointer */
  #define NETC__NETC__EMDIO_BASE                   ((NETC_EMDIO_BASE_Type *)NETC__NETC__EMDIO_BASE_BASE)
  /** Array initializer of NETC_EMDIO_BASE peripheral base addresses */
  #define NETC_EMDIO_BASE_BASE_ADDRS               { NETC__NETC__EMDIO_BASE_BASE }
  /** Array initializer of NETC_EMDIO_BASE peripheral base pointers */
  #define NETC_EMDIO_BASE_BASE_PTRS                { NETC__NETC__EMDIO_BASE }
#endif

/* NETC_IERB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__NETC_IERB base address */
  #define NETC__NETC__NETC_IERB_BASE               (0x5CD20000u)
  /** Peripheral NETC__NETC__NETC_IERB base address */
  #define NETC__NETC__NETC_IERB_BASE_NS            (0x4CD20000u)
  /** Peripheral NETC__NETC__NETC_IERB base pointer */
  #define NETC__NETC__NETC_IERB                    ((NETC_IERB_Type *)NETC__NETC__NETC_IERB_BASE)
  /** Peripheral NETC__NETC__NETC_IERB base pointer */
  #define NETC__NETC__NETC_IERB_NS                 ((NETC_IERB_Type *)NETC__NETC__NETC_IERB_BASE_NS)
  /** Array initializer of NETC_IERB peripheral base addresses */
  #define NETC_IERB_BASE_ADDRS                     { NETC__NETC__NETC_IERB_BASE }
  /** Array initializer of NETC_IERB peripheral base pointers */
  #define NETC_IERB_BASE_PTRS                      { NETC__NETC__NETC_IERB }
  /** Array initializer of NETC_IERB peripheral base addresses */
  #define NETC_IERB_BASE_ADDRS_NS                  { NETC__NETC__NETC_IERB_BASE_NS }
  /** Array initializer of NETC_IERB peripheral base pointers */
  #define NETC_IERB_BASE_PTRS_NS                   { NETC__NETC__NETC_IERB_NS }
#else
  /** Peripheral NETC__NETC__NETC_IERB base address */
  #define NETC__NETC__NETC_IERB_BASE               (0x4CD20000u)
  /** Peripheral NETC__NETC__NETC_IERB base pointer */
  #define NETC__NETC__NETC_IERB                    ((NETC_IERB_Type *)NETC__NETC__NETC_IERB_BASE)
  /** Array initializer of NETC_IERB peripheral base addresses */
  #define NETC_IERB_BASE_ADDRS                     { NETC__NETC__NETC_IERB_BASE }
  /** Array initializer of NETC_IERB peripheral base pointers */
  #define NETC_IERB_BASE_PTRS                      { NETC__NETC__NETC_IERB }
#endif

/* NETC_PRIV - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__NETC_PRIV base address */
  #define NETC__NETC__NETC_PRIV_BASE               (0x5CD30000u)
  /** Peripheral NETC__NETC__NETC_PRIV base address */
  #define NETC__NETC__NETC_PRIV_BASE_NS            (0x4CD30000u)
  /** Peripheral NETC__NETC__NETC_PRIV base pointer */
  #define NETC__NETC__NETC_PRIV                    ((NETC_PRIV_Type *)NETC__NETC__NETC_PRIV_BASE)
  /** Peripheral NETC__NETC__NETC_PRIV base pointer */
  #define NETC__NETC__NETC_PRIV_NS                 ((NETC_PRIV_Type *)NETC__NETC__NETC_PRIV_BASE_NS)
  /** Array initializer of NETC_PRIV peripheral base addresses */
  #define NETC_PRIV_BASE_ADDRS                     { NETC__NETC__NETC_PRIV_BASE }
  /** Array initializer of NETC_PRIV peripheral base pointers */
  #define NETC_PRIV_BASE_PTRS                      { NETC__NETC__NETC_PRIV }
  /** Array initializer of NETC_PRIV peripheral base addresses */
  #define NETC_PRIV_BASE_ADDRS_NS                  { NETC__NETC__NETC_PRIV_BASE_NS }
  /** Array initializer of NETC_PRIV peripheral base pointers */
  #define NETC_PRIV_BASE_PTRS_NS                   { NETC__NETC__NETC_PRIV_NS }
#else
  /** Peripheral NETC__NETC__NETC_PRIV base address */
  #define NETC__NETC__NETC_PRIV_BASE               (0x4CD30000u)
  /** Peripheral NETC__NETC__NETC_PRIV base pointer */
  #define NETC__NETC__NETC_PRIV                    ((NETC_PRIV_Type *)NETC__NETC__NETC_PRIV_BASE)
  /** Array initializer of NETC_PRIV peripheral base addresses */
  #define NETC_PRIV_BASE_ADDRS                     { NETC__NETC__NETC_PRIV_BASE }
  /** Array initializer of NETC_PRIV peripheral base pointers */
  #define NETC_PRIV_BASE_PTRS                      { NETC__NETC__NETC_PRIV }
#endif

/* NETC_TMR_BASE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__TMR0_BASE base address */
  #define NETC__NETC__TMR0_BASE_BASE               (0x5CC80000u)
  /** Peripheral NETC__NETC__TMR0_BASE base address */
  #define NETC__NETC__TMR0_BASE_BASE_NS            (0x4CC80000u)
  /** Peripheral NETC__NETC__TMR0_BASE base pointer */
  #define NETC__NETC__TMR0_BASE                    ((NETC_TMR_BASE_Type *)NETC__NETC__TMR0_BASE_BASE)
  /** Peripheral NETC__NETC__TMR0_BASE base pointer */
  #define NETC__NETC__TMR0_BASE_NS                 ((NETC_TMR_BASE_Type *)NETC__NETC__TMR0_BASE_BASE_NS)
  /** Array initializer of NETC_TMR_BASE peripheral base addresses */
  #define NETC_TMR_BASE_BASE_ADDRS                 { NETC__NETC__TMR0_BASE_BASE }
  /** Array initializer of NETC_TMR_BASE peripheral base pointers */
  #define NETC_TMR_BASE_BASE_PTRS                  { NETC__NETC__TMR0_BASE }
  /** Array initializer of NETC_TMR_BASE peripheral base addresses */
  #define NETC_TMR_BASE_BASE_ADDRS_NS              { NETC__NETC__TMR0_BASE_BASE_NS }
  /** Array initializer of NETC_TMR_BASE peripheral base pointers */
  #define NETC_TMR_BASE_BASE_PTRS_NS               { NETC__NETC__TMR0_BASE_NS }
#else
  /** Peripheral NETC__NETC__TMR0_BASE base address */
  #define NETC__NETC__TMR0_BASE_BASE               (0x4CC80000u)
  /** Peripheral NETC__NETC__TMR0_BASE base pointer */
  #define NETC__NETC__TMR0_BASE                    ((NETC_TMR_BASE_Type *)NETC__NETC__TMR0_BASE_BASE)
  /** Array initializer of NETC_TMR_BASE peripheral base addresses */
  #define NETC_TMR_BASE_BASE_ADDRS                 { NETC__NETC__TMR0_BASE_BASE }
  /** Array initializer of NETC_TMR_BASE peripheral base pointers */
  #define NETC_TMR_BASE_BASE_PTRS                  { NETC__NETC__TMR0_BASE }
#endif

/* NETC_VF_PCI_HDR_TYPE0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__VF1_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__VF1_PCI_HDR_TYPE0_BASE       (0x5CA40000u)
  /** Peripheral NETC__NETC__VF1_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__VF1_PCI_HDR_TYPE0_BASE_NS    (0x4CA40000u)
  /** Peripheral NETC__NETC__VF1_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__VF1_PCI_HDR_TYPE0            ((NETC_VF_PCI_HDR_TYPE0_Type *)NETC__NETC__VF1_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__NETC__VF1_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__VF1_PCI_HDR_TYPE0_NS         ((NETC_VF_PCI_HDR_TYPE0_Type *)NETC__NETC__VF1_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral NETC__NETC__VF2_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__VF2_PCI_HDR_TYPE0_BASE       (0x5CB40000u)
  /** Peripheral NETC__NETC__VF2_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__VF2_PCI_HDR_TYPE0_BASE_NS    (0x4CB40000u)
  /** Peripheral NETC__NETC__VF2_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__VF2_PCI_HDR_TYPE0            ((NETC_VF_PCI_HDR_TYPE0_Type *)NETC__NETC__VF2_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__NETC__VF2_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__VF2_PCI_HDR_TYPE0_NS         ((NETC_VF_PCI_HDR_TYPE0_Type *)NETC__NETC__VF2_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of NETC_VF_PCI_HDR_TYPE0 peripheral base addresses */
  #define NETC_VF_PCI_HDR_TYPE0_BASE_ADDRS         { NETC__NETC__VF1_PCI_HDR_TYPE0_BASE, NETC__NETC__VF2_PCI_HDR_TYPE0_BASE }
  /** Array initializer of NETC_VF_PCI_HDR_TYPE0 peripheral base pointers */
  #define NETC_VF_PCI_HDR_TYPE0_BASE_PTRS          { NETC__NETC__VF1_PCI_HDR_TYPE0, NETC__NETC__VF2_PCI_HDR_TYPE0 }
  /** Array initializer of NETC_VF_PCI_HDR_TYPE0 peripheral base addresses */
  #define NETC_VF_PCI_HDR_TYPE0_BASE_ADDRS_NS      { NETC__NETC__VF1_PCI_HDR_TYPE0_BASE_NS, NETC__NETC__VF2_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of NETC_VF_PCI_HDR_TYPE0 peripheral base pointers */
  #define NETC_VF_PCI_HDR_TYPE0_BASE_PTRS_NS       { NETC__NETC__VF1_PCI_HDR_TYPE0_NS, NETC__NETC__VF2_PCI_HDR_TYPE0_NS }
#else
  /** Peripheral NETC__NETC__VF1_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__VF1_PCI_HDR_TYPE0_BASE       (0x4CA40000u)
  /** Peripheral NETC__NETC__VF1_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__VF1_PCI_HDR_TYPE0            ((NETC_VF_PCI_HDR_TYPE0_Type *)NETC__NETC__VF1_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__NETC__VF2_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__VF2_PCI_HDR_TYPE0_BASE       (0x4CB40000u)
  /** Peripheral NETC__NETC__VF2_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__VF2_PCI_HDR_TYPE0            ((NETC_VF_PCI_HDR_TYPE0_Type *)NETC__NETC__VF2_PCI_HDR_TYPE0_BASE)
  /** Array initializer of NETC_VF_PCI_HDR_TYPE0 peripheral base addresses */
  #define NETC_VF_PCI_HDR_TYPE0_BASE_ADDRS         { NETC__NETC__VF1_PCI_HDR_TYPE0_BASE, NETC__NETC__VF2_PCI_HDR_TYPE0_BASE }
  /** Array initializer of NETC_VF_PCI_HDR_TYPE0 peripheral base pointers */
  #define NETC_VF_PCI_HDR_TYPE0_BASE_PTRS          { NETC__NETC__VF1_PCI_HDR_TYPE0, NETC__NETC__VF2_PCI_HDR_TYPE0 }
#endif

/* NOC_BLK_CTRL_NOCMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__BLK_CTRL_NOCMIX base address */
  #define NOC__BLK_CTRL_NOCMIX_BASE                (0x59000000u)
  /** Peripheral NOC__BLK_CTRL_NOCMIX base address */
  #define NOC__BLK_CTRL_NOCMIX_BASE_NS             (0x49000000u)
  /** Peripheral NOC__BLK_CTRL_NOCMIX base pointer */
  #define NOC__BLK_CTRL_NOCMIX                     ((NOC_BLK_CTRL_NOCMIX_Type *)NOC__BLK_CTRL_NOCMIX_BASE)
  /** Peripheral NOC__BLK_CTRL_NOCMIX base pointer */
  #define NOC__BLK_CTRL_NOCMIX_NS                  ((NOC_BLK_CTRL_NOCMIX_Type *)NOC__BLK_CTRL_NOCMIX_BASE_NS)
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base addresses */
  #define NOC_BLK_CTRL_NOCMIX_BASE_ADDRS           { NOC__BLK_CTRL_NOCMIX_BASE }
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base pointers */
  #define NOC_BLK_CTRL_NOCMIX_BASE_PTRS            { NOC__BLK_CTRL_NOCMIX }
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base addresses */
  #define NOC_BLK_CTRL_NOCMIX_BASE_ADDRS_NS        { NOC__BLK_CTRL_NOCMIX_BASE_NS }
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base pointers */
  #define NOC_BLK_CTRL_NOCMIX_BASE_PTRS_NS         { NOC__BLK_CTRL_NOCMIX_NS }
#else
  /** Peripheral NOC__BLK_CTRL_NOCMIX base address */
  #define NOC__BLK_CTRL_NOCMIX_BASE                (0x49000000u)
  /** Peripheral NOC__BLK_CTRL_NOCMIX base pointer */
  #define NOC__BLK_CTRL_NOCMIX                     ((NOC_BLK_CTRL_NOCMIX_Type *)NOC__BLK_CTRL_NOCMIX_BASE)
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base addresses */
  #define NOC_BLK_CTRL_NOCMIX_BASE_ADDRS           { NOC__BLK_CTRL_NOCMIX_BASE }
  /** Array initializer of NOC_BLK_CTRL_NOCMIX peripheral base pointers */
  #define NOC_BLK_CTRL_NOCMIX_BASE_PTRS            { NOC__BLK_CTRL_NOCMIX }
#endif

/* NOC_SRAMCTL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NOC__SRAMCTL base address */
  #define NOC__SRAMCTL_BASE                        (0x590A0000u)
  /** Peripheral NOC__SRAMCTL base address */
  #define NOC__SRAMCTL_BASE_NS                     (0x490A0000u)
  /** Peripheral NOC__SRAMCTL base pointer */
  #define NOC__SRAMCTL                             ((NOC_SRAMCTL_Type *)NOC__SRAMCTL_BASE)
  /** Peripheral NOC__SRAMCTL base pointer */
  #define NOC__SRAMCTL_NS                          ((NOC_SRAMCTL_Type *)NOC__SRAMCTL_BASE_NS)
  /** Array initializer of NOC_SRAMCTL peripheral base addresses */
  #define NOC_SRAMCTL_BASE_ADDRS                   { NOC__SRAMCTL_BASE }
  /** Array initializer of NOC_SRAMCTL peripheral base pointers */
  #define NOC_SRAMCTL_BASE_PTRS                    { NOC__SRAMCTL }
  /** Array initializer of NOC_SRAMCTL peripheral base addresses */
  #define NOC_SRAMCTL_BASE_ADDRS_NS                { NOC__SRAMCTL_BASE_NS }
  /** Array initializer of NOC_SRAMCTL peripheral base pointers */
  #define NOC_SRAMCTL_BASE_PTRS_NS                 { NOC__SRAMCTL_NS }
#else
  /** Peripheral NOC__SRAMCTL base address */
  #define NOC__SRAMCTL_BASE                        (0x490A0000u)
  /** Peripheral NOC__SRAMCTL base pointer */
  #define NOC__SRAMCTL                             ((NOC_SRAMCTL_Type *)NOC__SRAMCTL_BASE)
  /** Array initializer of NOC_SRAMCTL peripheral base addresses */
  #define NOC_SRAMCTL_BASE_ADDRS                   { NOC__SRAMCTL_BASE }
  /** Array initializer of NOC_SRAMCTL peripheral base pointers */
  #define NOC_SRAMCTL_BASE_PTRS                    { NOC__SRAMCTL }
#endif

/* NPU_BLK_CTRL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NPU__BLK_CTRL_NPUMIX base address */
  #define NPU__BLK_CTRL_NPUMIX_BASE                (0x5A810000u)
  /** Peripheral NPU__BLK_CTRL_NPUMIX base address */
  #define NPU__BLK_CTRL_NPUMIX_BASE_NS             (0x4A810000u)
  /** Peripheral NPU__BLK_CTRL_NPUMIX base pointer */
  #define NPU__BLK_CTRL_NPUMIX                     ((NPU_BLK_CTRL_Type *)NPU__BLK_CTRL_NPUMIX_BASE)
  /** Peripheral NPU__BLK_CTRL_NPUMIX base pointer */
  #define NPU__BLK_CTRL_NPUMIX_NS                  ((NPU_BLK_CTRL_Type *)NPU__BLK_CTRL_NPUMIX_BASE_NS)
  /** Array initializer of NPU_BLK_CTRL peripheral base addresses */
  #define NPU_BLK_CTRL_BASE_ADDRS                  { NPU__BLK_CTRL_NPUMIX_BASE }
  /** Array initializer of NPU_BLK_CTRL peripheral base pointers */
  #define NPU_BLK_CTRL_BASE_PTRS                   { NPU__BLK_CTRL_NPUMIX }
  /** Array initializer of NPU_BLK_CTRL peripheral base addresses */
  #define NPU_BLK_CTRL_BASE_ADDRS_NS               { NPU__BLK_CTRL_NPUMIX_BASE_NS }
  /** Array initializer of NPU_BLK_CTRL peripheral base pointers */
  #define NPU_BLK_CTRL_BASE_PTRS_NS                { NPU__BLK_CTRL_NPUMIX_NS }
#else
  /** Peripheral NPU__BLK_CTRL_NPUMIX base address */
  #define NPU__BLK_CTRL_NPUMIX_BASE                (0x4A810000u)
  /** Peripheral NPU__BLK_CTRL_NPUMIX base pointer */
  #define NPU__BLK_CTRL_NPUMIX                     ((NPU_BLK_CTRL_Type *)NPU__BLK_CTRL_NPUMIX_BASE)
  /** Array initializer of NPU_BLK_CTRL peripheral base addresses */
  #define NPU_BLK_CTRL_BASE_ADDRS                  { NPU__BLK_CTRL_NPUMIX_BASE }
  /** Array initializer of NPU_BLK_CTRL peripheral base pointers */
  #define NPU_BLK_CTRL_BASE_PTRS                   { NPU__BLK_CTRL_NPUMIX }
#endif

/* OSC24M - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral OSC24M base address */
  #define OSC24M_BASE                              (0x54480000u)
  /** Peripheral OSC24M base address */
  #define OSC24M_BASE_NS                           (0x44480000u)
  /** Peripheral OSC24M base pointer */
  #define OSC24M                                   ((OSC24M_Type *)OSC24M_BASE)
  /** Peripheral OSC24M base pointer */
  #define OSC24M_NS                                ((OSC24M_Type *)OSC24M_BASE_NS)
  /** Array initializer of OSC24M peripheral base addresses */
  #define OSC24M_BASE_ADDRS                        { OSC24M_BASE }
  /** Array initializer of OSC24M peripheral base pointers */
  #define OSC24M_BASE_PTRS                         { OSC24M }
  /** Array initializer of OSC24M peripheral base addresses */
  #define OSC24M_BASE_ADDRS_NS                     { OSC24M_BASE_NS }
  /** Array initializer of OSC24M peripheral base pointers */
  #define OSC24M_BASE_PTRS_NS                      { OSC24M_NS }
#else
  /** Peripheral OSC24M base address */
  #define OSC24M_BASE                              (0x44480000u)
  /** Peripheral OSC24M base pointer */
  #define OSC24M                                   ((OSC24M_Type *)OSC24M_BASE)
  /** Array initializer of OSC24M peripheral base addresses */
  #define OSC24M_BASE_ADDRS                        { OSC24M_BASE }
  /** Array initializer of OSC24M peripheral base pointers */
  #define OSC24M_BASE_PTRS                         { OSC24M }
#endif

/* PCIE_DMA_IATU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE (0x5C360000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE_NS (0x4C360000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU ((PCIE_DMA_IATU_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_NS ((PCIE_DMA_IATU_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE_NS)
  /** Array initializer of PCIE_DMA_IATU peripheral base addresses */
  #define PCIE_DMA_IATU_BASE_ADDRS                 { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE }
  /** Array initializer of PCIE_DMA_IATU peripheral base pointers */
  #define PCIE_DMA_IATU_BASE_PTRS                  { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU }
  /** Array initializer of PCIE_DMA_IATU peripheral base addresses */
  #define PCIE_DMA_IATU_BASE_ADDRS_NS              { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE_NS }
  /** Array initializer of PCIE_DMA_IATU peripheral base pointers */
  #define PCIE_DMA_IATU_BASE_PTRS_NS               { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_NS }
#else
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE (0x4C360000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU ((PCIE_DMA_IATU_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE)
  /** Array initializer of PCIE_DMA_IATU peripheral base addresses */
  #define PCIE_DMA_IATU_BASE_ADDRS                 { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU_BASE }
  /** Array initializer of PCIE_DMA_IATU peripheral base pointers */
  #define PCIE_DMA_IATU_BASE_PTRS                  { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_DMA_IATU }
#endif

/* PCIE_EP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE (0x5C300000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE_NS (0x4C300000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP ((PCIE_EP_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_NS ((PCIE_EP_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE_NS)
  /** Array initializer of PCIE_EP peripheral base addresses */
  #define PCIE_EP_BASE_ADDRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE }
  /** Array initializer of PCIE_EP peripheral base pointers */
  #define PCIE_EP_BASE_PTRS                        { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP }
  /** Array initializer of PCIE_EP peripheral base addresses */
  #define PCIE_EP_BASE_ADDRS_NS                    { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE_NS }
  /** Array initializer of PCIE_EP peripheral base pointers */
  #define PCIE_EP_BASE_PTRS_NS                     { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_NS }
#else
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE (0x4C300000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP ((PCIE_EP_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE)
  /** Array initializer of PCIE_EP peripheral base addresses */
  #define PCIE_EP_BASE_ADDRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP_BASE }
  /** Array initializer of PCIE_EP peripheral base pointers */
  #define PCIE_EP_BASE_PTRS                        { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_EP }
#endif

/* PCIE_RC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE (0x5C300000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE_NS (0x4C300000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC ((PCIE_RC_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_NS ((PCIE_RC_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE_NS)
  /** Array initializer of PCIE_RC peripheral base addresses */
  #define PCIE_RC_BASE_ADDRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE }
  /** Array initializer of PCIE_RC peripheral base pointers */
  #define PCIE_RC_BASE_PTRS                        { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC }
  /** Array initializer of PCIE_RC peripheral base addresses */
  #define PCIE_RC_BASE_ADDRS_NS                    { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE_NS }
  /** Array initializer of PCIE_RC peripheral base pointers */
  #define PCIE_RC_BASE_PTRS_NS                     { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_NS }
#else
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE (0x4C300000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC ((PCIE_RC_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE)
  /** Array initializer of PCIE_RC peripheral base addresses */
  #define PCIE_RC_BASE_ADDRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC_BASE }
  /** Array initializer of PCIE_RC peripheral base pointers */
  #define PCIE_RC_BASE_PTRS                        { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_RC }
#endif

/* PCIE_SHADOW_EP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE (0x5C320000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE_NS (0x4C320000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP ((PCIE_SHADOW_EP_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_NS ((PCIE_SHADOW_EP_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE_NS)
  /** Array initializer of PCIE_SHADOW_EP peripheral base addresses */
  #define PCIE_SHADOW_EP_BASE_ADDRS                { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE }
  /** Array initializer of PCIE_SHADOW_EP peripheral base pointers */
  #define PCIE_SHADOW_EP_BASE_PTRS                 { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP }
  /** Array initializer of PCIE_SHADOW_EP peripheral base addresses */
  #define PCIE_SHADOW_EP_BASE_ADDRS_NS             { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE_NS }
  /** Array initializer of PCIE_SHADOW_EP peripheral base pointers */
  #define PCIE_SHADOW_EP_BASE_PTRS_NS              { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_NS }
#else
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE (0x4C320000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP ((PCIE_SHADOW_EP_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE)
  /** Array initializer of PCIE_SHADOW_EP peripheral base addresses */
  #define PCIE_SHADOW_EP_BASE_ADDRS                { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP_BASE }
  /** Array initializer of PCIE_SHADOW_EP peripheral base pointers */
  #define PCIE_SHADOW_EP_BASE_PTRS                 { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PCIE_SHADOW_EP }
#endif

/* PDM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral PDM base address */
  #define PDM_BASE                                 (0x54520000u)
  /** Peripheral PDM base address */
  #define PDM_BASE_NS                              (0x44520000u)
  /** Peripheral PDM base pointer */
  #define PDM                                      ((PDM_Type *)PDM_BASE)
  /** Peripheral PDM base pointer */
  #define PDM_NS                                   ((PDM_Type *)PDM_BASE_NS)
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS                           { PDM_BASE }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS                            { PDM }
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS_NS                        { PDM_BASE_NS }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS_NS                         { PDM_NS }
#else
  /** Peripheral PDM base address */
  #define PDM_BASE                                 (0x44520000u)
  /** Peripheral PDM base pointer */
  #define PDM                                      ((PDM_Type *)PDM_BASE)
  /** Array initializer of PDM peripheral base addresses */
  #define PDM_BASE_ADDRS                           { PDM_BASE }
  /** Array initializer of PDM peripheral base pointers */
  #define PDM_BASE_PTRS                            { PDM }
#endif
/** Interrupt vectors for the PDM peripheral type */
#define PDM_HWVAD_Event_IRQS                     { PDM_HWVAD_EVENT_IRQn }
#define PDM_HWVAD_Error_IRQS                     { PDM_HWVAD_ERROR_IRQn }
#define PDM_Event_IRQS                           { PDM_EVENT_IRQn }
#define PDM_Error_IRQS                           { PDM_ERROR_IRQn }

/* PHY_CTRL_EX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE (0x5CF00000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE_NS (0x4CF00000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX ((PHY_CTRL_EX_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_NS ((PHY_CTRL_EX_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE_NS)
  /** Array initializer of PHY_CTRL_EX peripheral base addresses */
  #define PHY_CTRL_EX_BASE_ADDRS                   { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE }
  /** Array initializer of PHY_CTRL_EX peripheral base pointers */
  #define PHY_CTRL_EX_BASE_PTRS                    { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX }
  /** Array initializer of PHY_CTRL_EX peripheral base addresses */
  #define PHY_CTRL_EX_BASE_ADDRS_NS                { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE_NS }
  /** Array initializer of PHY_CTRL_EX peripheral base pointers */
  #define PHY_CTRL_EX_BASE_PTRS_NS                 { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_NS }
#else
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE (0x4CF00000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX ((PHY_CTRL_EX_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE)
  /** Array initializer of PHY_CTRL_EX peripheral base addresses */
  #define PHY_CTRL_EX_BASE_ADDRS                   { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX_BASE }
  /** Array initializer of PHY_CTRL_EX peripheral base pointers */
  #define PHY_CTRL_EX_BASE_PTRS                    { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_CTRL_EX }
#endif

/* PHY_ENET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE (0x5CF00000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE_NS (0x4CF00000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET ((PHY_ENET_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_NS ((PHY_ENET_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE_NS)
  /** Array initializer of PHY_ENET peripheral base addresses */
  #define PHY_ENET_BASE_ADDRS                      { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE }
  /** Array initializer of PHY_ENET peripheral base pointers */
  #define PHY_ENET_BASE_PTRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET }
  /** Array initializer of PHY_ENET peripheral base addresses */
  #define PHY_ENET_BASE_ADDRS_NS                   { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE_NS }
  /** Array initializer of PHY_ENET peripheral base pointers */
  #define PHY_ENET_BASE_PTRS_NS                    { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_NS }
#else
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE (0x4CF00000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET ((PHY_ENET_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE)
  /** Array initializer of PHY_ENET peripheral base addresses */
  #define PHY_ENET_BASE_ADDRS                      { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET_BASE }
  /** Array initializer of PHY_ENET peripheral base pointers */
  #define PHY_ENET_BASE_PTRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__PHY_ENET }
#endif

/* PLL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYS_PLL1 base address */
  #define SYS_PLL1_BASE              (0x54481000u)
  /** Peripheral SYS_PLL1 base address */
  #define SYS_PLL1_BASE_NS           (0x44481000u)
  /** Peripheral SYS_PLL1 base pointer */
  #define SYS_PLL1                   ((PLL_Type *)SYS_PLL1_BASE)
  /** Peripheral SYS_PLL1 base pointer */
  #define SYS_PLL1_NS                ((PLL_Type *)SYS_PLL1_BASE_NS)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL1 base address */
  #define ANALOG__AUDIO_FRACT_PLL1_BASE            (0x54481100u)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL1 base address */
  #define ANALOG__AUDIO_FRACT_PLL1_BASE_NS         (0x44481100u)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL1 base pointer */
  #define ANALOG__AUDIO_FRACT_PLL1                 ((PLL_Type *)ANALOG__AUDIO_FRACT_PLL1_BASE)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL1 base pointer */
  #define ANALOG__AUDIO_FRACT_PLL1_NS              ((PLL_Type *)ANALOG__AUDIO_FRACT_PLL1_BASE_NS)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL2 base address */
  #define ANALOG__AUDIO_FRACT_PLL2_BASE            (0x54481200u)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL2 base address */
  #define ANALOG__AUDIO_FRACT_PLL2_BASE_NS         (0x44481200u)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL2 base pointer */
  #define ANALOG__AUDIO_FRACT_PLL2                 ((PLL_Type *)ANALOG__AUDIO_FRACT_PLL2_BASE)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL2 base pointer */
  #define ANALOG__AUDIO_FRACT_PLL2_NS              ((PLL_Type *)ANALOG__AUDIO_FRACT_PLL2_BASE_NS)
  /** Peripheral ANALOG__VIDEO_FRACT_PLL1 base address */
  #define ANALOG__VIDEO_FRACT_PLL1_BASE            (0x54481300u)
  /** Peripheral ANALOG__VIDEO_FRACT_PLL1 base address */
  #define ANALOG__VIDEO_FRACT_PLL1_BASE_NS         (0x44481300u)
  /** Peripheral ANALOG__VIDEO_FRACT_PLL1 base pointer */
  #define ANALOG__VIDEO_FRACT_PLL1                 ((PLL_Type *)ANALOG__VIDEO_FRACT_PLL1_BASE)
  /** Peripheral ANALOG__VIDEO_FRACT_PLL1 base pointer */
  #define ANALOG__VIDEO_FRACT_PLL1_NS              ((PLL_Type *)ANALOG__VIDEO_FRACT_PLL1_BASE_NS)
  /** Peripheral CORTEXA__FRACT_PLL_ARMPLL base address */
  #define CORTEXA__FRACT_PLL_ARMPLL_BASE           (0x54481600u)
  /** Peripheral CORTEXA__FRACT_PLL_ARMPLL base address */
  #define CORTEXA__FRACT_PLL_ARMPLL_BASE_NS        (0x44481600u)
  /** Peripheral CORTEXA__FRACT_PLL_ARMPLL base pointer */
  #define CORTEXA__FRACT_PLL_ARMPLL                ((PLL_Type *)CORTEXA__FRACT_PLL_ARMPLL_BASE)
  /** Peripheral CORTEXA__FRACT_PLL_ARMPLL base pointer */
  #define CORTEXA__FRACT_PLL_ARMPLL_NS             ((PLL_Type *)CORTEXA__FRACT_PLL_ARMPLL_BASE_NS)
  /** Peripheral DDRC__FRACT_PLL base address */
  #define DDRC__FRACT_PLL_BASE                     (0x54481700u)
  /** Peripheral DDRC__FRACT_PLL base address */
  #define DDRC__FRACT_PLL_BASE_NS                  (0x44481700u)
  /** Peripheral DDRC__FRACT_PLL base pointer */
  #define DDRC__FRACT_PLL                          ((PLL_Type *)DDRC__FRACT_PLL_BASE)
  /** Peripheral DDRC__FRACT_PLL base pointer */
  #define DDRC__FRACT_PLL_NS                       ((PLL_Type *)DDRC__FRACT_PLL_BASE_NS)
  /** Peripheral DISPLAY__FRACT_PLL base address */
  #define DISPLAY__FRACT_PLL_BASE                  (0x54481900u)
  /** Peripheral DISPLAY__FRACT_PLL base address */
  #define DISPLAY__FRACT_PLL_BASE_NS               (0x44481900u)
  /** Peripheral DISPLAY__FRACT_PLL base pointer */
  #define DISPLAY__FRACT_PLL                       ((PLL_Type *)DISPLAY__FRACT_PLL_BASE)
  /** Peripheral DISPLAY__FRACT_PLL base pointer */
  #define DISPLAY__FRACT_PLL_NS                    ((PLL_Type *)DISPLAY__FRACT_PLL_BASE_NS)
  /** Array initializer of PLL peripheral base addresses */
  #define PLL_BASE_ADDRS                           { SYS_PLL1_BASE, ANALOG__AUDIO_FRACT_PLL1_BASE, ANALOG__AUDIO_FRACT_PLL2_BASE, ANALOG__VIDEO_FRACT_PLL1_BASE, CORTEXA__FRACT_PLL_ARMPLL_BASE, DDRC__FRACT_PLL_BASE, DISPLAY__FRACT_PLL_BASE }
  /** Array initializer of PLL peripheral base pointers */
  #define PLL_BASE_PTRS                            { SYS_PLL1, ANALOG__AUDIO_FRACT_PLL1, ANALOG__AUDIO_FRACT_PLL2, ANALOG__VIDEO_FRACT_PLL1, CORTEXA__FRACT_PLL_ARMPLL, DDRC__FRACT_PLL, HSIO__GHZ_LN_PLL, DISPLAY__FRACT_PLL }
  /** Array initializer of PLL peripheral base addresses */
  #define PLL_BASE_ADDRS_NS                        { SYS_PLL1_BASE_NS, ANALOG__AUDIO_FRACT_PLL1_BASE_NS, ANALOG__AUDIO_FRACT_PLL2_BASE_NS, ANALOG__VIDEO_FRACT_PLL1_BASE_NS, CORTEXA__FRACT_PLL_ARMPLL_BASE_NS, DDRC__FRACT_PLL_BASE_NS, HSIO__GHZ_LN_PLL_BASE_NS, DISPLAY__FRACT_PLL_BASE_NS }
  /** Array initializer of PLL peripheral base pointers */
  #define PLL_BASE_PTRS_NS                         { SYS_PLL1_NS, ANALOG__AUDIO_FRACT_PLL1_NS, ANALOG__AUDIO_FRACT_PLL2_NS, ANALOG__VIDEO_FRACT_PLL1_NS, CORTEXA__FRACT_PLL_ARMPLL_NS, DDRC__FRACT_PLL_NS, HSIO__GHZ_LN_PLL_NS, DISPLAY__FRACT_PLL_NS }
#else
  /** Peripheral SYS_PLL1 base address */
  #define SYS_PLL1_BASE              (0x44481000u)
  /** Peripheral SYS_PLL1 base pointer */
  #define SYS_PLL1                   ((PLL_Type *)SYS_PLL1_BASE)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL1 base address */
  #define ANALOG__AUDIO_FRACT_PLL1_BASE            (0x44481100u)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL1 base pointer */
  #define ANALOG__AUDIO_FRACT_PLL1                 ((PLL_Type *)ANALOG__AUDIO_FRACT_PLL1_BASE)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL2 base address */
  #define ANALOG__AUDIO_FRACT_PLL2_BASE            (0x44481200u)
  /** Peripheral ANALOG__AUDIO_FRACT_PLL2 base pointer */
  #define ANALOG__AUDIO_FRACT_PLL2                 ((PLL_Type *)ANALOG__AUDIO_FRACT_PLL2_BASE)
  /** Peripheral ANALOG__VIDEO_FRACT_PLL1 base address */
  #define ANALOG__VIDEO_FRACT_PLL1_BASE            (0x44481300u)
  /** Peripheral ANALOG__VIDEO_FRACT_PLL1 base pointer */
  #define ANALOG__VIDEO_FRACT_PLL1                 ((PLL_Type *)ANALOG__VIDEO_FRACT_PLL1_BASE)
  /** Peripheral CORTEXA__FRACT_PLL_ARMPLL base address */
  #define CORTEXA__FRACT_PLL_ARMPLL_BASE           (0x44481600u)
  /** Peripheral CORTEXA__FRACT_PLL_ARMPLL base pointer */
  #define CORTEXA__FRACT_PLL_ARMPLL                ((PLL_Type *)CORTEXA__FRACT_PLL_ARMPLL_BASE)
  /** Peripheral DDRC__FRACT_PLL base address */
  #define DDRC__FRACT_PLL_BASE                     (0x44481700u)
  /** Peripheral DDRC__FRACT_PLL base pointer */
  #define DDRC__FRACT_PLL                          ((PLL_Type *)DDRC__FRACT_PLL_BASE)
  /** Peripheral DISPLAY__FRACT_PLL base address */
  #define DISPLAY__FRACT_PLL_BASE                  (0x44481900u)
  /** Peripheral DISPLAY__FRACT_PLL base pointer */
  #define DISPLAY__FRACT_PLL                       ((PLL_Type *)DISPLAY__FRACT_PLL_BASE)
  /** Array initializer of PLL peripheral base addresses */
  #define PLL_BASE_ADDRS                           { SYS_PLL1_BASE, ANALOG__AUDIO_FRACT_PLL1_BASE, ANALOG__AUDIO_FRACT_PLL2_BASE, ANALOG__VIDEO_FRACT_PLL1_BASE, CORTEXA__FRACT_PLL_ARMPLL_BASE, DDRC__FRACT_PLL_BASE, HSIO__GHZ_LN_PLL_BASE, DISPLAY__FRACT_PLL_BASE }
  /** Array initializer of PLL peripheral base pointers */
  #define PLL_BASE_PTRS                            { SYS_PLL1, ANALOG__AUDIO_FRACT_PLL1, ANALOG__AUDIO_FRACT_PLL2, ANALOG__VIDEO_FRACT_PLL1, CORTEXA__FRACT_PLL_ARMPLL, DDRC__FRACT_PLL, HSIO__GHZ_LN_PLL, DISPLAY__FRACT_PLL }
#endif

/* RGPIO - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE                               (0x57400000u)
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE_NS                            (0x47400000u)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1                                    ((RGPIO_Type *)GPIO1_BASE)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1_NS                                 ((RGPIO_Type *)GPIO1_BASE_NS)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE                               (0x53810000u)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE_NS                            (0x43810000u)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2                                    ((RGPIO_Type *)GPIO2_BASE)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2_NS                                 ((RGPIO_Type *)GPIO2_BASE_NS)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE                               (0x53820000u)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE_NS                            (0x43820000u)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3                                    ((RGPIO_Type *)GPIO3_BASE)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3_NS                                 ((RGPIO_Type *)GPIO3_BASE_NS)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE                               (0x53840000u)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE_NS                            (0x43840000u)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4                                    ((RGPIO_Type *)GPIO4_BASE)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4_NS                                 ((RGPIO_Type *)GPIO4_BASE_NS)
  /** Peripheral GPIO5 base address */
  #define GPIO5_BASE                               (0x53850000u)
  /** Peripheral GPIO5 base address */
  #define GPIO5_BASE_NS                            (0x43850000u)
  /** Peripheral GPIO5 base pointer */
  #define GPIO5                                    ((RGPIO_Type *)GPIO5_BASE)
  /** Peripheral GPIO5 base pointer */
  #define GPIO5_NS                                 ((RGPIO_Type *)GPIO5_BASE_NS)
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS                         { 0u, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS                          { (RGPIO_Type *)0u, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5 }
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS_NS                      { 0u, GPIO1_BASE_NS, GPIO2_BASE_NS, GPIO3_BASE_NS, GPIO4_BASE_NS, GPIO5_BASE_NS }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS_NS                       { (RGPIO_Type *)0u, GPIO1_NS, GPIO2_NS, GPIO3_NS, GPIO4_NS, GPIO5_NS }
#else
  /** Peripheral GPIO1 base address */
  #define GPIO1_BASE                               (0x47400000u)
  /** Peripheral GPIO1 base pointer */
  #define GPIO1                                    ((RGPIO_Type *)GPIO1_BASE)
  /** Peripheral GPIO2 base address */
  #define GPIO2_BASE                               (0x43810000u)
  /** Peripheral GPIO2 base pointer */
  #define GPIO2                                    ((RGPIO_Type *)GPIO2_BASE)
  /** Peripheral GPIO3 base address */
  #define GPIO3_BASE                               (0x43820000u)
  /** Peripheral GPIO3 base pointer */
  #define GPIO3                                    ((RGPIO_Type *)GPIO3_BASE)
  /** Peripheral GPIO4 base address */
  #define GPIO4_BASE                               (0x43840000u)
  /** Peripheral GPIO4 base pointer */
  #define GPIO4                                    ((RGPIO_Type *)GPIO4_BASE)
  /** Peripheral GPIO5 base address */
  #define GPIO5_BASE                               (0x43850000u)
  /** Peripheral GPIO5 base pointer */
  #define GPIO5                                    ((RGPIO_Type *)GPIO5_BASE)
  /** Array initializer of RGPIO peripheral base addresses */
  #define RGPIO_BASE_ADDRS                         { 0u, GPIO1_BASE, GPIO2_BASE, GPIO3_BASE, GPIO4_BASE, GPIO5_BASE }
  /** Array initializer of RGPIO peripheral base pointers */
  #define RGPIO_BASE_PTRS                          { (RGPIO_Type *)0u, GPIO1, GPIO2, GPIO3, GPIO4, GPIO5 }
#endif
/** Interrupt vectors for the RGPIO peripheral type */
#define RGPIO_IRQS                               { NotAvail_IRQn, GPIO1_0_IRQn, GPIO2_0_IRQn, GPIO3_0_IRQn, GPIO4_0_IRQn, GPIO5_0_IRQn }

/* S3MU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ELE_MU0_MUA base address */
  #define ELE_MU0_MUA_BASE                         (0x57520000u)
  /** Peripheral ELE_MU0_MUA base address */
  #define ELE_MU0_MUA_BASE_NS                      (0x47520000u)
  /** Peripheral ELE_MU0_MUA base pointer */
  #define ELE_MU0_MUA                              ((S3MU_Type *)ELE_MU0_MUA_BASE)
  /** Peripheral ELE_MU0_MUA base pointer */
  #define ELE_MU0_MUA_NS                           ((S3MU_Type *)ELE_MU0_MUA_BASE_NS)
  /** Peripheral ELE_MU1_MUA base address */
  #define ELE_MU1_MUA_BASE                         (0x57530000u)
  /** Peripheral ELE_MU1_MUA base address */
  #define ELE_MU1_MUA_BASE_NS                      (0x47530000u)
  /** Peripheral ELE_MU1_MUA base pointer */
  #define ELE_MU1_MUA                              ((S3MU_Type *)ELE_MU1_MUA_BASE)
  /** Peripheral ELE_MU1_MUA base pointer */
  #define ELE_MU1_MUA_NS                           ((S3MU_Type *)ELE_MU1_MUA_BASE_NS)
  /** Peripheral ELE_MU2_MUA base address */
  #define ELE_MU2_MUA_BASE                         (0x57540000u)
  /** Peripheral ELE_MU2_MUA base address */
  #define ELE_MU2_MUA_BASE_NS                      (0x47540000u)
  /** Peripheral ELE_MU2_MUA base pointer */
  #define ELE_MU2_MUA                              ((S3MU_Type *)ELE_MU2_MUA_BASE)
  /** Peripheral ELE_MU2_MUA base pointer */
  #define ELE_MU2_MUA_NS                           ((S3MU_Type *)ELE_MU2_MUA_BASE_NS)
  /** Peripheral ELE_MU3_MUA base address */
  #define ELE_MU3_MUA_BASE                         (0x57550000u)
  /** Peripheral ELE_MU3_MUA base address */
  #define ELE_MU3_MUA_BASE_NS                      (0x47550000u)
  /** Peripheral ELE_MU3_MUA base pointer */
  #define ELE_MU3_MUA                              ((S3MU_Type *)ELE_MU3_MUA_BASE)
  /** Peripheral ELE_MU3_MUA base pointer */
  #define ELE_MU3_MUA_NS                           ((S3MU_Type *)ELE_MU3_MUA_BASE_NS)
  /** Peripheral ELE_MU4_MUA base address */
  #define ELE_MU4_MUA_BASE                         (0x57560000u)
  /** Peripheral ELE_MU4_MUA base address */
  #define ELE_MU4_MUA_BASE_NS                      (0x47560000u)
  /** Peripheral ELE_MU4_MUA base pointer */
  #define ELE_MU4_MUA                              ((S3MU_Type *)ELE_MU4_MUA_BASE)
  /** Peripheral ELE_MU4_MUA base pointer */
  #define ELE_MU4_MUA_NS                           ((S3MU_Type *)ELE_MU4_MUA_BASE_NS)
  /** Peripheral ELE_MU5_MUA base address */
  #define ELE_MU5_MUA_BASE                         (0x57570000u)
  /** Peripheral ELE_MU5_MUA base address */
  #define ELE_MU5_MUA_BASE_NS                      (0x47570000u)
  /** Peripheral ELE_MU5_MUA base pointer */
  #define ELE_MU5_MUA                              ((S3MU_Type *)ELE_MU5_MUA_BASE)
  /** Peripheral ELE_MU5_MUA base pointer */
  #define ELE_MU5_MUA_NS                           ((S3MU_Type *)ELE_MU5_MUA_BASE_NS)
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS                          { ELE_MU0_MUA_BASE, ELE_MU1_MUA_BASE, ELE_MU2_MUA_BASE, ELE_MU3_MUA_BASE, ELE_MU4_MUA_BASE, ELE_MU5_MUA_BASE }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS                           { ELE_MU0_MUA, ELE_MU1_MUA, ELE_MU2_MUA, ELE_MU3_MUA, ELE_MU4_MUA, ELE_MU5_MUA }
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS_NS                       { ELE_MU0_MUA_BASE_NS, ELE_MU1_MUA_BASE_NS, ELE_MU2_MUA_BASE_NS, ELE_MU3_MUA_BASE_NS, ELE_MU4_MUA_BASE_NS, ELE_MU5_MUA_BASE_NS }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS_NS                        { ELE_MU0_MUA_NS, ELE_MU1_MUA_NS, ELE_MU2_MUA_NS, ELE_MU3_MUA_NS, ELE_MU4_MUA_NS, ELE_MU5_MUA_NS }
#else
  /** Peripheral ELE_MU0_MUA base address */
  #define ELE_MU0_MUA_BASE                         (0x47520000u)
  /** Peripheral ELE_MU0_MUA base pointer */
  #define ELE_MU0_MUA                              ((S3MU_Type *)ELE_MU0_MUA_BASE)
  /** Peripheral ELE_MU1_MUA base address */
  #define ELE_MU1_MUA_BASE                         (0x47530000u)
  /** Peripheral ELE_MU1_MUA base pointer */
  #define ELE_MU1_MUA                              ((S3MU_Type *)ELE_MU1_MUA_BASE)
  /** Peripheral ELE_MU2_MUA base address */
  #define ELE_MU2_MUA_BASE                         (0x47540000u)
  /** Peripheral ELE_MU2_MUA base pointer */
  #define ELE_MU2_MUA                              ((S3MU_Type *)ELE_MU2_MUA_BASE)
  /** Peripheral ELE_MU3_MUA base address */
  #define ELE_MU3_MUA_BASE                         (0x47550000u)
  /** Peripheral ELE_MU3_MUA base pointer */
  #define ELE_MU3_MUA                              ((S3MU_Type *)ELE_MU3_MUA_BASE)
  /** Peripheral ELE_MU4_MUA base address */
  #define ELE_MU4_MUA_BASE                         (0x47560000u)
  /** Peripheral ELE_MU4_MUA base pointer */
  #define ELE_MU4_MUA                              ((S3MU_Type *)ELE_MU4_MUA_BASE)
  /** Peripheral ELE_MU5_MUA base address */
  #define ELE_MU5_MUA_BASE                         (0x47570000u)
  /** Peripheral ELE_MU5_MUA base pointer */
  #define ELE_MU5_MUA                              ((S3MU_Type *)ELE_MU5_MUA_BASE)
  /** Array initializer of S3MU peripheral base addresses */
  #define S3MU_BASE_ADDRS                          { ELE_MU0_MUA_BASE, ELE_MU1_MUA_BASE, ELE_MU2_MUA_BASE, ELE_MU3_MUA_BASE, ELE_MU4_MUA_BASE, ELE_MU5_MUA_BASE }
  /** Array initializer of S3MU peripheral base pointers */
  #define S3MU_BASE_PTRS                           { ELE_MU0_MUA, ELE_MU1_MUA, ELE_MU2_MUA, ELE_MU3_MUA, ELE_MU4_MUA, ELE_MU5_MUA }
#endif

/* SCALER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__HSCALER base address */
  #define DISPLAY__SEERIS__HSCALER_BASE            (0x5B4B0000u)
  /** Peripheral DISPLAY__SEERIS__HSCALER base address */
  #define DISPLAY__SEERIS__HSCALER_BASE_NS         (0x4B4B0000u)
  /** Peripheral DISPLAY__SEERIS__HSCALER base pointer */
  #define DISPLAY__SEERIS__HSCALER                 ((SCALER_Type *)DISPLAY__SEERIS__HSCALER_BASE)
  /** Peripheral DISPLAY__SEERIS__HSCALER base pointer */
  #define DISPLAY__SEERIS__HSCALER_NS              ((SCALER_Type *)DISPLAY__SEERIS__HSCALER_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__HSCALER1 base address */
  #define DISPLAY__SEERIS__HSCALER1_BASE           (0x5B640000u)
  /** Peripheral DISPLAY__SEERIS__HSCALER1 base address */
  #define DISPLAY__SEERIS__HSCALER1_BASE_NS        (0x4B640000u)
  /** Peripheral DISPLAY__SEERIS__HSCALER1 base pointer */
  #define DISPLAY__SEERIS__HSCALER1                ((SCALER_Type *)DISPLAY__SEERIS__HSCALER1_BASE)
  /** Peripheral DISPLAY__SEERIS__HSCALER1 base pointer */
  #define DISPLAY__SEERIS__HSCALER1_NS             ((SCALER_Type *)DISPLAY__SEERIS__HSCALER1_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__VSCALER base address */
  #define DISPLAY__SEERIS__VSCALER_BASE            (0x5B4C0000u)
  /** Peripheral DISPLAY__SEERIS__VSCALER base address */
  #define DISPLAY__SEERIS__VSCALER_BASE_NS         (0x4B4C0000u)
  /** Peripheral DISPLAY__SEERIS__VSCALER base pointer */
  #define DISPLAY__SEERIS__VSCALER                 ((SCALER_Type *)DISPLAY__SEERIS__VSCALER_BASE)
  /** Peripheral DISPLAY__SEERIS__VSCALER base pointer */
  #define DISPLAY__SEERIS__VSCALER_NS              ((SCALER_Type *)DISPLAY__SEERIS__VSCALER_BASE_NS)
  /** Peripheral DISPLAY__SEERIS__VSCALER1 base address */
  #define DISPLAY__SEERIS__VSCALER1_BASE           (0x5B650000u)
  /** Peripheral DISPLAY__SEERIS__VSCALER1 base address */
  #define DISPLAY__SEERIS__VSCALER1_BASE_NS        (0x4B650000u)
  /** Peripheral DISPLAY__SEERIS__VSCALER1 base pointer */
  #define DISPLAY__SEERIS__VSCALER1                ((SCALER_Type *)DISPLAY__SEERIS__VSCALER1_BASE)
  /** Peripheral DISPLAY__SEERIS__VSCALER1 base pointer */
  #define DISPLAY__SEERIS__VSCALER1_NS             ((SCALER_Type *)DISPLAY__SEERIS__VSCALER1_BASE_NS)
  /** Array initializer of SCALER peripheral base addresses */
  #define SCALER_BASE_ADDRS                        { DISPLAY__SEERIS__HSCALER_BASE, DISPLAY__SEERIS__HSCALER1_BASE, DISPLAY__SEERIS__VSCALER_BASE, DISPLAY__SEERIS__VSCALER1_BASE }
  /** Array initializer of SCALER peripheral base pointers */
  #define SCALER_BASE_PTRS                         { DISPLAY__SEERIS__HSCALER, DISPLAY__SEERIS__HSCALER1, DISPLAY__SEERIS__VSCALER, DISPLAY__SEERIS__VSCALER1 }
  /** Array initializer of SCALER peripheral base addresses */
  #define SCALER_BASE_ADDRS_NS                     { DISPLAY__SEERIS__HSCALER_BASE_NS, DISPLAY__SEERIS__HSCALER1_BASE_NS, DISPLAY__SEERIS__VSCALER_BASE_NS, DISPLAY__SEERIS__VSCALER1_BASE_NS }
  /** Array initializer of SCALER peripheral base pointers */
  #define SCALER_BASE_PTRS_NS                      { DISPLAY__SEERIS__HSCALER_NS, DISPLAY__SEERIS__HSCALER1_NS, DISPLAY__SEERIS__VSCALER_NS, DISPLAY__SEERIS__VSCALER1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__HSCALER base address */
  #define DISPLAY__SEERIS__HSCALER_BASE            (0x4B4B0000u)
  /** Peripheral DISPLAY__SEERIS__HSCALER base pointer */
  #define DISPLAY__SEERIS__HSCALER                 ((SCALER_Type *)DISPLAY__SEERIS__HSCALER_BASE)
  /** Peripheral DISPLAY__SEERIS__HSCALER1 base address */
  #define DISPLAY__SEERIS__HSCALER1_BASE           (0x4B640000u)
  /** Peripheral DISPLAY__SEERIS__HSCALER1 base pointer */
  #define DISPLAY__SEERIS__HSCALER1                ((SCALER_Type *)DISPLAY__SEERIS__HSCALER1_BASE)
  /** Peripheral DISPLAY__SEERIS__VSCALER base address */
  #define DISPLAY__SEERIS__VSCALER_BASE            (0x4B4C0000u)
  /** Peripheral DISPLAY__SEERIS__VSCALER base pointer */
  #define DISPLAY__SEERIS__VSCALER                 ((SCALER_Type *)DISPLAY__SEERIS__VSCALER_BASE)
  /** Peripheral DISPLAY__SEERIS__VSCALER1 base address */
  #define DISPLAY__SEERIS__VSCALER1_BASE           (0x4B650000u)
  /** Peripheral DISPLAY__SEERIS__VSCALER1 base pointer */
  #define DISPLAY__SEERIS__VSCALER1                ((SCALER_Type *)DISPLAY__SEERIS__VSCALER1_BASE)
  /** Array initializer of SCALER peripheral base addresses */
  #define SCALER_BASE_ADDRS                        { DISPLAY__SEERIS__HSCALER_BASE, DISPLAY__SEERIS__HSCALER1_BASE, DISPLAY__SEERIS__VSCALER_BASE, DISPLAY__SEERIS__VSCALER1_BASE }
  /** Array initializer of SCALER peripheral base pointers */
  #define SCALER_BASE_PTRS                         { DISPLAY__SEERIS__HSCALER, DISPLAY__SEERIS__HSCALER1, DISPLAY__SEERIS__VSCALER, DISPLAY__SEERIS__VSCALER1 }
#endif

/* SEMA42 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SEMA42_1 base address */
  #define SEMA42_1_BASE                            (0x54260000u)
  /** Peripheral SEMA42_1 base address */
  #define SEMA42_1_BASE_NS                         (0x44260000u)
  /** Peripheral SEMA42_1 base pointer */
  #define SEMA42_1                                 ((SEMA42_Type *)SEMA42_1_BASE)
  /** Peripheral SEMA42_1 base pointer */
  #define SEMA42_1_NS                              ((SEMA42_Type *)SEMA42_1_BASE_NS)
  /** Peripheral SEMA42_2 base address */
  #define SEMA42_2_BASE                            (0x52070000u)
  /** Peripheral SEMA42_2 base address */
  #define SEMA42_2_BASE_NS                         (0x42070000u)
  /** Peripheral SEMA42_2 base pointer */
  #define SEMA42_2                                 ((SEMA42_Type *)SEMA42_2_BASE)
  /** Peripheral SEMA42_2 base pointer */
  #define SEMA42_2_NS                              ((SEMA42_Type *)SEMA42_2_BASE_NS)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { 0u, SEMA42_1_BASE, SEMA42_2_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { (SEMA42_Type *)0u, SEMA42_1, SEMA42_2 }
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS_NS                     { 0u, SEMA42_1_BASE_NS, SEMA42_2_BASE_NS }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS_NS                      { (SEMA42_Type *)0u, SEMA42_1_NS, SEMA42_2_NS }
#else
  /** Peripheral SEMA42_1 base address */
  #define SEMA42_1_BASE                            (0x44260000u)
  /** Peripheral SEMA42_1 base pointer */
  #define SEMA42_1                                 ((SEMA42_Type *)SEMA42_1_BASE)
  /** Peripheral SEMA42_2 base address */
  #define SEMA42_2_BASE                            (0x42070000u)
  /** Peripheral SEMA42_2 base pointer */
  #define SEMA42_2                                 ((SEMA42_Type *)SEMA42_2_BASE)
  /** Array initializer of SEMA42 peripheral base addresses */
  #define SEMA42_BASE_ADDRS                        { 0u, SEMA42_1_BASE, SEMA42_2_BASE }
  /** Array initializer of SEMA42 peripheral base pointers */
  #define SEMA42_BASE_PTRS                         { (SEMA42_Type *)0u, SEMA42_1, SEMA42_2 }
#endif

/* SRC_GEN - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SRC_GEN base address */
  #define SRC_GEN_BASE                             (0x54460000u)
  /** Peripheral SRC_GEN base address */
  #define SRC_GEN_BASE_NS                          (0x44460000u)
  /** Peripheral SRC_GEN base pointer */
  #define SRC_GEN                                  ((SRC_GEN_Type *)SRC_GEN_BASE)
  /** Peripheral SRC_GEN base pointer */
  #define SRC_GEN_NS                               ((SRC_GEN_Type *)SRC_GEN_BASE_NS)
  /** Array initializer of SRC_GEN peripheral base addresses */
  #define SRC_GEN_BASE_ADDRS                       { SRC_GEN_BASE }
  /** Array initializer of SRC_GEN peripheral base pointers */
  #define SRC_GEN_BASE_PTRS                        { SRC_GEN }
  /** Array initializer of SRC_GEN peripheral base addresses */
  #define SRC_GEN_BASE_ADDRS_NS                    { SRC_GEN_BASE_NS }
  /** Array initializer of SRC_GEN peripheral base pointers */
  #define SRC_GEN_BASE_PTRS_NS                     { SRC_GEN_NS }
#else
  /** Peripheral SRC_GEN base address */
  #define SRC_GEN_BASE                             (0x44460000u)
  /** Peripheral SRC_GEN base pointer */
  #define SRC_GEN                                  ((SRC_GEN_Type *)SRC_GEN_BASE)
  /** Array initializer of SRC_GEN peripheral base addresses */
  #define SRC_GEN_BASE_ADDRS                       { SRC_GEN_BASE }
  /** Array initializer of SRC_GEN peripheral base pointers */
  #define SRC_GEN_BASE_PTRS                        { SRC_GEN }
#endif

/* SRC_MEM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE     (0x54460900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE_NS  (0x44460900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_AONMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_AONMIX_MEM_NS       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE  (0x54461100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE_NS (0x44461100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_NS    ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE (0x54461900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE_NS (0x44461900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE (0x54461D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE_NS (0x44461D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE (0x54462100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE_NS (0x44462100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE (0x54462500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE_NS (0x44462500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE (0x54462900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE_NS (0x44462900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE (0x54462920u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE_NS (0x44462920u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_NS ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE     (0x54462D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE_NS  (0x44462D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_NS       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE (0x54463100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE_NS (0x44463100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_NS   ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_GPUMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE     (0x54463500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_GPUMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE_NS  (0x44463500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_GPUMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_GPUMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_GPUMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_NS       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE    (0x54463900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE_NS (0x44463900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_NS      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE      (0x54464100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE_NS   (0x44464100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_M7MIX_MEM           ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_M7MIX_MEM_NS        ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE    (0x54464500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE_NS (0x44464500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_NS      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base address */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE    (0x54464900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base address */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE_NS (0x44464900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base pointer */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base pointer */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_NS      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base address */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE    (0x54464920u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base address */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE_NS (0x44464920u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base pointer */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base pointer */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_NS      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE     (0x54464D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE_NS  (0x44464D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_NS       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_VPUMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE     (0x54465100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_VPUMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE_NS  (0x44465100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_VPUMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_VPUMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_VPUMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_NS       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE_NS)
  /** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE  (0x54465500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE_NS (0x44465500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_NS    ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE_NS)
  /** Array initializer of SRC_MEM peripheral base addresses */
  #define SRC_MEM_BASE_ADDRS                       { CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE }
  /** Array initializer of SRC_MEM peripheral base pointers */
  #define SRC_MEM_BASE_PTRS                        { CCMSRCGPC__SRC__XSPR_AONMIX_MEM, CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM, CCMSRCGPC__SRC__XSPR_GPUMIX_MEM, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM, CCMSRCGPC__SRC__XSPR_M7MIX_MEM, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM, CCMSRCGPC__SRC__XSPR_VPUMIX_MEM, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM }
  /** Array initializer of SRC_MEM peripheral base addresses */
  #define SRC_MEM_BASE_ADDRS_NS                    { CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE_NS, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE_NS, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE_NS, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE_NS, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE_NS }
  /** Array initializer of SRC_MEM peripheral base pointers */
  #define SRC_MEM_BASE_PTRS_NS                     { CCMSRCGPC__SRC__XSPR_AONMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_NS, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_NS, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_M7MIX_MEM_NS, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_NS, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_NS, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_NS, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_NS }
#else
  /** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE     (0x44460900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_AONMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_AONMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE  (0x44461100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE (0x44461900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE (0x44461D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE (0x44462100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE (0x44462500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE (0x44462900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0 ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base address */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE (0x44462920u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 base pointer */
  #define CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1 ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE     (0x44462D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DDRMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_DDRMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE (0x44463100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM      ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_GPUMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE     (0x44463500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_GPUMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_GPUMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE    (0x44463900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE      (0x44464100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_M7MIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_M7MIX_MEM           ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE    (0x44464500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NETCMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_NETCMIX_MEM         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base address */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE    (0x44464900u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0 base pointer */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base address */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE    (0x44464920u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1 base pointer */
  #define CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1         ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE     (0x44464D00u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_NPUMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_NPUMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_VPUMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE     (0x44465100u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_VPUMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_VPUMIX_MEM          ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE)
  /** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base address */
  #define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE  (0x44465500u)
  /** Peripheral CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM base pointer */
  #define CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM       ((SRC_MEM_Type *)CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE)
  /** Array initializer of SRC_MEM peripheral base addresses */
  #define SRC_MEM_BASE_ADDRS                       { CCMSRCGPC__SRC__XSPR_AONMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0_BASE, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1_BASE, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_GPUMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_M7MIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0_BASE, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1_BASE, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_VPUMIX_MEM_BASE, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM_BASE }
  /** Array initializer of SRC_MEM peripheral base pointers */
  #define SRC_MEM_BASE_PTRS                        { CCMSRCGPC__SRC__XSPR_AONMIX_MEM, CCMSRCGPC__SRC__XSPR_CAMERAMIX_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE0_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE1_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE2_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_CORE3_MEM, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM0, CCMSRCGPC__SRC__XSPR_CORTEXMIX_PLATFORM_MEM1, CCMSRCGPC__SRC__XSPR_DDRMIX_MEM, CCMSRCGPC__SRC__XSPR_DISPLAYMIX_MEM, CCMSRCGPC__SRC__XSPR_GPUMIX_MEM, CCMSRCGPC__SRC__XSPR_HSIOMIX_MEM, CCMSRCGPC__SRC__XSPR_M7MIX_MEM, CCMSRCGPC__SRC__XSPR_NETCMIX_MEM, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM0, CCMSRCGPC__SRC__XSPR_NOCMIX_MEM1, CCMSRCGPC__SRC__XSPR_NPUMIX_MEM, CCMSRCGPC__SRC__XSPR_VPUMIX_MEM, CCMSRCGPC__SRC__XSPR_WAKEUPMIX_MEM }
#endif

/* SRC_XSPR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SRC_XSPR_ANAMIX base address */
  #define SRC_XSPR_ANAMIX_BASE         (0x54460400u)
  /** Peripheral SRC_XSPR_ANAMIX base address */
  #define SRC_XSPR_ANAMIX_BASE_NS      (0x44460400u)
  /** Peripheral SRC_XSPR_ANAMIX base pointer */
  #define SRC_XSPR_ANAMIX              ((SRC_XSPR_Type *)SRC_XSPR_ANAMIX_BASE)
  /** Peripheral SRC_XSPR_ANAMIX base pointer */
  #define SRC_XSPR_ANAMIX_NS           ((SRC_XSPR_Type *)SRC_XSPR_ANAMIX_BASE_NS)
  /** Peripheral SRC_XSPR_AONMIX base address */
  #define SRC_XSPR_AONMIX_BASE         (0x54460800u)
  /** Peripheral SRC_XSPR_AONMIX base address */
  #define SRC_XSPR_AONMIX_BASE_NS      (0x44460800u)
  /** Peripheral SRC_XSPR_AONMIX base pointer */
  #define SRC_XSPR_AONMIX              ((SRC_XSPR_Type *)SRC_XSPR_AONMIX_BASE)
  /** Peripheral SRC_XSPR_AONMIX base pointer */
  #define SRC_XSPR_AONMIX_NS           ((SRC_XSPR_Type *)SRC_XSPR_AONMIX_BASE_NS)
  /** Peripheral SRC_XSPR_BBSMMIX base address */
  #define SRC_XSPR_BBSMMIX_BASE        (0x54460C00u)
  /** Peripheral SRC_XSPR_BBSMMIX base address */
  #define SRC_XSPR_BBSMMIX_BASE_NS     (0x44460C00u)
  /** Peripheral SRC_XSPR_BBSMMIX base pointer */
  #define SRC_XSPR_BBSMMIX             ((SRC_XSPR_Type *)SRC_XSPR_BBSMMIX_BASE)
  /** Peripheral SRC_XSPR_BBSMMIX base pointer */
  #define SRC_XSPR_BBSMMIX_NS          ((SRC_XSPR_Type *)SRC_XSPR_BBSMMIX_BASE_NS)
  /** Peripheral SRC_XSPR_CAMERAMIX base address */
  #define SRC_XSPR_CAMERAMIX_BASE      (0x54461000u)
  /** Peripheral SRC_XSPR_CAMERAMIX base address */
  #define SRC_XSPR_CAMERAMIX_BASE_NS   (0x44461000u)
  /** Peripheral SRC_XSPR_CAMERAMIX base pointer */
  #define SRC_XSPR_CAMERAMIX           ((SRC_XSPR_Type *)SRC_XSPR_CAMERAMIX_BASE)
  /** Peripheral SRC_XSPR_CAMERAMIX base pointer */
  #define SRC_XSPR_CAMERAMIX_NS        ((SRC_XSPR_Type *)SRC_XSPR_CAMERAMIX_BASE_NS)
  /** Peripheral SRC_XSPR_CCMSRCGPCMIX base address */
  #define SRC_XSPR_CCMSRCGPCMIX_BASE   (0x54461400u)
  /** Peripheral SRC_XSPR_CCMSRCGPCMIX base address */
  #define SRC_XSPR_CCMSRCGPCMIX_BASE_NS (0x44461400u)
  /** Peripheral SRC_XSPR_CCMSRCGPCMIX base pointer */
  #define SRC_XSPR_CCMSRCGPCMIX        ((SRC_XSPR_Type *)SRC_XSPR_CCMSRCGPCMIX_BASE)
  /** Peripheral SRC_XSPR_CCMSRCGPCMIX base pointer */
  #define SRC_XSPR_CCMSRCGPCMIX_NS     ((SRC_XSPR_Type *)SRC_XSPR_CCMSRCGPCMIX_BASE_NS)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base address */
  #define SRC_XSPR_CORTEXMIX_CORE0_BASE (0x54461800u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base address */
  #define SRC_XSPR_CORTEXMIX_CORE0_BASE_NS (0x44461800u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE0     ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE0_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE0_NS  ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE0_BASE_NS)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base address */
  #define SRC_XSPR_CORTEXMIX_CORE1_BASE (0x54461C00u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base address */
  #define SRC_XSPR_CORTEXMIX_CORE1_BASE_NS (0x44461C00u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE1     ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE1_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE1_NS  ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE1_BASE_NS)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base address */
  #define SRC_XSPR_CORTEXMIX_CORE2_BASE (0x54462000u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base address */
  #define SRC_XSPR_CORTEXMIX_CORE2_BASE_NS (0x44462000u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE2     ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE2_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE2_NS  ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE2_BASE_NS)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base address */
  #define SRC_XSPR_CORTEXMIX_CORE3_BASE (0x54462400u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base address */
  #define SRC_XSPR_CORTEXMIX_CORE3_BASE_NS (0x44462400u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE3     ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE3_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE3_NS  ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE3_BASE_NS)
  /** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base address */
  #define SRC_XSPR_CORTEXMIX_PLATFORM_BASE (0x54462800u)
  /** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base address */
  #define SRC_XSPR_CORTEXMIX_PLATFORM_BASE_NS (0x44462800u)
  /** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base pointer */
  #define SRC_XSPR_CORTEXMIX_PLATFORM  ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_PLATFORM_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base pointer */
  #define SRC_XSPR_CORTEXMIX_PLATFORM_NS ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_PLATFORM_BASE_NS)
  /** Peripheral SRC_XSPR_DDRMIX base address */
  #define SRC_XSPR_DDRMIX_BASE         (0x54462C00u)
  /** Peripheral SRC_XSPR_DDRMIX base address */
  #define SRC_XSPR_DDRMIX_BASE_NS      (0x44462C00u)
  /** Peripheral SRC_XSPR_DDRMIX base pointer */
  #define SRC_XSPR_DDRMIX              ((SRC_XSPR_Type *)SRC_XSPR_DDRMIX_BASE)
  /** Peripheral SRC_XSPR_DDRMIX base pointer */
  #define SRC_XSPR_DDRMIX_NS           ((SRC_XSPR_Type *)SRC_XSPR_DDRMIX_BASE_NS)
  /** Peripheral SRC_XSPR_DISPLAYMIX base address */
  #define SRC_XSPR_DISPLAYMIX_BASE     (0x54463000u)
  /** Peripheral SRC_XSPR_DISPLAYMIX base address */
  #define SRC_XSPR_DISPLAYMIX_BASE_NS  (0x44463000u)
  /** Peripheral SRC_XSPR_DISPLAYMIX base pointer */
  #define SRC_XSPR_DISPLAYMIX          ((SRC_XSPR_Type *)SRC_XSPR_DISPLAYMIX_BASE)
  /** Peripheral SRC_XSPR_DISPLAYMIX base pointer */
  #define SRC_XSPR_DISPLAYMIX_NS       ((SRC_XSPR_Type *)SRC_XSPR_DISPLAYMIX_BASE_NS)
  /** Peripheral SRC_XSPR_GPUMIX base address */
  #define SRC_XSPR_GPUMIX_BASE         (0x54463400u)
  /** Peripheral SRC_XSPR_GPUMIX base address */
  #define SRC_XSPR_GPUMIX_BASE_NS      (0x44463400u)
  /** Peripheral SRC_XSPR_GPUMIX base pointer */
  #define SRC_XSPR_GPUMIX              ((SRC_XSPR_Type *)SRC_XSPR_GPUMIX_BASE)
  /** Peripheral SRC_XSPR_GPUMIX base pointer */
  #define SRC_XSPR_GPUMIX_NS           ((SRC_XSPR_Type *)SRC_XSPR_GPUMIX_BASE_NS)
  /** Peripheral SRC_XSPR_HSIOMIX_TOP base address */
  #define SRC_XSPR_HSIOMIX_TOP_BASE    (0x54463800u)
  /** Peripheral SRC_XSPR_HSIOMIX_TOP base address */
  #define SRC_XSPR_HSIOMIX_TOP_BASE_NS (0x44463800u)
  /** Peripheral SRC_XSPR_HSIOMIX_TOP base pointer */
  #define SRC_XSPR_HSIOMIX_TOP         ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_TOP_BASE)
  /** Peripheral SRC_XSPR_HSIOMIX_TOP base pointer */
  #define SRC_XSPR_HSIOMIX_TOP_NS      ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_TOP_BASE_NS)
  /** Peripheral SRC_XSPR_HSIOMIX_WAON base address */
  #define SRC_XSPR_HSIOMIX_WAON_BASE   (0x54463C00u)
  /** Peripheral SRC_XSPR_HSIOMIX_WAON base address */
  #define SRC_XSPR_HSIOMIX_WAON_BASE_NS (0x44463C00u)
  /** Peripheral SRC_XSPR_HSIOMIX_WAON base pointer */
  #define SRC_XSPR_HSIOMIX_WAON        ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_WAON_BASE)
  /** Peripheral SRC_XSPR_HSIOMIX_WAON base pointer */
  #define SRC_XSPR_HSIOMIX_WAON_NS     ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_WAON_BASE_NS)
  /** Peripheral SRC_XSPR_M7MIX base address */
  #define SRC_XSPR_M7MIX_BASE          (0x54464000u)
  /** Peripheral SRC_XSPR_M7MIX base address */
  #define SRC_XSPR_M7MIX_BASE_NS       (0x44464000u)
  /** Peripheral SRC_XSPR_M7MIX base pointer */
  #define SRC_XSPR_M7MIX               ((SRC_XSPR_Type *)SRC_XSPR_M7MIX_BASE)
  /** Peripheral SRC_XSPR_M7MIX base pointer */
  #define SRC_XSPR_M7MIX_NS            ((SRC_XSPR_Type *)SRC_XSPR_M7MIX_BASE_NS)
  /** Peripheral SRC_XSPR_NETCMIX base address */
  #define SRC_XSPR_NETCMIX_BASE        (0x54464400u)
  /** Peripheral SRC_XSPR_NETCMIX base address */
  #define SRC_XSPR_NETCMIX_BASE_NS     (0x44464400u)
  /** Peripheral SRC_XSPR_NETCMIX base pointer */
  #define SRC_XSPR_NETCMIX             ((SRC_XSPR_Type *)SRC_XSPR_NETCMIX_BASE)
  /** Peripheral SRC_XSPR_NETCMIX base pointer */
  #define SRC_XSPR_NETCMIX_NS          ((SRC_XSPR_Type *)SRC_XSPR_NETCMIX_BASE_NS)
  /** Peripheral SRC_XSPR_NOCMIX base address */
  #define SRC_XSPR_NOCMIX_BASE         (0x54464800u)
  /** Peripheral SRC_XSPR_NOCMIX base address */
  #define SRC_XSPR_NOCMIX_BASE_NS      (0x44464800u)
  /** Peripheral SRC_XSPR_NOCMIX base pointer */
  #define SRC_XSPR_NOCMIX              ((SRC_XSPR_Type *)SRC_XSPR_NOCMIX_BASE)
  /** Peripheral SRC_XSPR_NOCMIX base pointer */
  #define SRC_XSPR_NOCMIX_NS           ((SRC_XSPR_Type *)SRC_XSPR_NOCMIX_BASE_NS)
  /** Peripheral SRC_XSPR_NPUMIX base address */
  #define SRC_XSPR_NPUMIX_BASE         (0x54464C00u)
  /** Peripheral SRC_XSPR_NPUMIX base address */
  #define SRC_XSPR_NPUMIX_BASE_NS      (0x44464C00u)
  /** Peripheral SRC_XSPR_NPUMIX base pointer */
  #define SRC_XSPR_NPUMIX              ((SRC_XSPR_Type *)SRC_XSPR_NPUMIX_BASE)
  /** Peripheral SRC_XSPR_NPUMIX base pointer */
  #define SRC_XSPR_NPUMIX_NS           ((SRC_XSPR_Type *)SRC_XSPR_NPUMIX_BASE_NS)
  /** Peripheral SRC_XSPR_VPUMIX base address */
  #define SRC_XSPR_VPUMIX_BASE         (0x54465000u)
  /** Peripheral SRC_XSPR_VPUMIX base address */
  #define SRC_XSPR_VPUMIX_BASE_NS      (0x44465000u)
  /** Peripheral SRC_XSPR_VPUMIX base pointer */
  #define SRC_XSPR_VPUMIX              ((SRC_XSPR_Type *)SRC_XSPR_VPUMIX_BASE)
  /** Peripheral SRC_XSPR_VPUMIX base pointer */
  #define SRC_XSPR_VPUMIX_NS           ((SRC_XSPR_Type *)SRC_XSPR_VPUMIX_BASE_NS)
  /** Peripheral SRC_XSPR_WAKEUPMIX base address */
  #define SRC_XSPR_WAKEUPMIX_BASE      (0x54465400u)
  /** Peripheral SRC_XSPR_WAKEUPMIX base address */
  #define SRC_XSPR_WAKEUPMIX_BASE_NS   (0x44465400u)
  /** Peripheral SRC_XSPR_WAKEUPMIX base pointer */
  #define SRC_XSPR_WAKEUPMIX           ((SRC_XSPR_Type *)SRC_XSPR_WAKEUPMIX_BASE)
  /** Peripheral SRC_XSPR_WAKEUPMIX base pointer */
  #define SRC_XSPR_WAKEUPMIX_NS        ((SRC_XSPR_Type *)SRC_XSPR_WAKEUPMIX_BASE_NS)
  /** Array initializer of SRC_XSPR peripheral base addresses */
  #define SRC_XSPR_BASE_ADDRS                      { SRC_XSPR_ANAMIX_BASE, SRC_XSPR_AONMIX_BASE, SRC_XSPR_BBSMMIX_BASE, SRC_XSPR_CAMERAMIX_BASE, SRC_XSPR_CCMSRCGPCMIX_BASE, SRC_XSPR_CORTEXMIX_CORE0_BASE, SRC_XSPR_CORTEXMIX_CORE1_BASE, SRC_XSPR_CORTEXMIX_CORE2_BASE, SRC_XSPR_CORTEXMIX_CORE3_BASE, SRC_XSPR_CORTEXMIX_PLATFORM_BASE, SRC_XSPR_DDRMIX_BASE, SRC_XSPR_DISPLAYMIX_BASE, SRC_XSPR_GPUMIX_BASE, SRC_XSPR_HSIOMIX_TOP_BASE, SRC_XSPR_HSIOMIX_WAON_BASE, SRC_XSPR_M7MIX_BASE, SRC_XSPR_NETCMIX_BASE, SRC_XSPR_NOCMIX_BASE, SRC_XSPR_NPUMIX_BASE, SRC_XSPR_VPUMIX_BASE, SRC_XSPR_WAKEUPMIX_BASE }
  /** Array initializer of SRC_XSPR peripheral base pointers */
  #define SRC_XSPR_BASE_PTRS                       { SRC_XSPR_ANAMIX, SRC_XSPR_AONMIX, SRC_XSPR_BBSMMIX, SRC_XSPR_CAMERAMIX, SRC_XSPR_CCMSRCGPCMIX, SRC_XSPR_CORTEXMIX_CORE0, SRC_XSPR_CORTEXMIX_CORE1, SRC_XSPR_CORTEXMIX_CORE2, SRC_XSPR_CORTEXMIX_CORE3, SRC_XSPR_CORTEXMIX_PLATFORM, SRC_XSPR_DDRMIX, SRC_XSPR_DISPLAYMIX, SRC_XSPR_GPUMIX, SRC_XSPR_HSIOMIX_TOP, SRC_XSPR_HSIOMIX_WAON, SRC_XSPR_M7MIX, SRC_XSPR_NETCMIX, SRC_XSPR_NOCMIX, SRC_XSPR_NPUMIX, SRC_XSPR_VPUMIX, SRC_XSPR_WAKEUPMIX }
  /** Array initializer of SRC_XSPR peripheral base addresses */
  #define SRC_XSPR_BASE_ADDRS_NS                   { SRC_XSPR_ANAMIX_BASE_NS, SRC_XSPR_AONMIX_BASE_NS, SRC_XSPR_BBSMMIX_BASE_NS, SRC_XSPR_CAMERAMIX_BASE_NS, SRC_XSPR_CCMSRCGPCMIX_BASE_NS, SRC_XSPR_CORTEXMIX_CORE0_BASE_NS, SRC_XSPR_CORTEXMIX_CORE1_BASE_NS, SRC_XSPR_CORTEXMIX_CORE2_BASE_NS, SRC_XSPR_CORTEXMIX_CORE3_BASE_NS, SRC_XSPR_CORTEXMIX_PLATFORM_BASE_NS, SRC_XSPR_DDRMIX_BASE_NS, SRC_XSPR_DISPLAYMIX_BASE_NS, SRC_XSPR_GPUMIX_BASE_NS, SRC_XSPR_HSIOMIX_TOP_BASE_NS, SRC_XSPR_HSIOMIX_WAON_BASE_NS, SRC_XSPR_M7MIX_BASE_NS, SRC_XSPR_NETCMIX_BASE_NS, SRC_XSPR_NOCMIX_BASE_NS, SRC_XSPR_NPUMIX_BASE_NS, SRC_XSPR_VPUMIX_BASE_NS, SRC_XSPR_WAKEUPMIX_BASE_NS }
  /** Array initializer of SRC_XSPR peripheral base pointers */
  #define SRC_XSPR_BASE_PTRS_NS                    { SRC_XSPR_ANAMIX_NS, SRC_XSPR_AONMIX_NS, SRC_XSPR_BBSMMIX_NS, SRC_XSPR_CAMERAMIX_NS, SRC_XSPR_CCMSRCGPCMIX_NS, SRC_XSPR_CORTEXMIX_CORE0_NS, SRC_XSPR_CORTEXMIX_CORE1_NS, SRC_XSPR_CORTEXMIX_CORE2_NS, SRC_XSPR_CORTEXMIX_CORE3_NS, SRC_XSPR_CORTEXMIX_PLATFORM_NS, SRC_XSPR_DDRMIX_NS, SRC_XSPR_DISPLAYMIX_NS, SRC_XSPR_GPUMIX_NS, SRC_XSPR_HSIOMIX_TOP_NS, SRC_XSPR_HSIOMIX_WAON_NS, SRC_XSPR_M7MIX_NS, SRC_XSPR_NETCMIX_NS, SRC_XSPR_NOCMIX_NS, SRC_XSPR_NPUMIX_NS, SRC_XSPR_VPUMIX_NS, SRC_XSPR_WAKEUPMIX_NS }
#else
  /** Peripheral SRC_XSPR_ANAMIX base address */
  #define SRC_XSPR_ANAMIX_BASE         (0x44460400u)
  /** Peripheral SRC_XSPR_ANAMIX base pointer */
  #define SRC_XSPR_ANAMIX              ((SRC_XSPR_Type *)SRC_XSPR_ANAMIX_BASE)
  /** Peripheral SRC_XSPR_AONMIX base address */
  #define SRC_XSPR_AONMIX_BASE         (0x44460800u)
  /** Peripheral SRC_XSPR_AONMIX base pointer */
  #define SRC_XSPR_AONMIX              ((SRC_XSPR_Type *)SRC_XSPR_AONMIX_BASE)
  /** Peripheral SRC_XSPR_BBSMMIX base address */
  #define SRC_XSPR_BBSMMIX_BASE        (0x44460C00u)
  /** Peripheral SRC_XSPR_BBSMMIX base pointer */
  #define SRC_XSPR_BBSMMIX             ((SRC_XSPR_Type *)SRC_XSPR_BBSMMIX_BASE)
  /** Peripheral SRC_XSPR_CAMERAMIX base address */
  #define SRC_XSPR_CAMERAMIX_BASE      (0x44461000u)
  /** Peripheral SRC_XSPR_CAMERAMIX base pointer */
  #define SRC_XSPR_CAMERAMIX           ((SRC_XSPR_Type *)SRC_XSPR_CAMERAMIX_BASE)
  /** Peripheral SRC_XSPR_CCMSRCGPCMIX base address */
  #define SRC_XSPR_CCMSRCGPCMIX_BASE   (0x44461400u)
  /** Peripheral SRC_XSPR_CCMSRCGPCMIX base pointer */
  #define SRC_XSPR_CCMSRCGPCMIX        ((SRC_XSPR_Type *)SRC_XSPR_CCMSRCGPCMIX_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base address */
  #define SRC_XSPR_CORTEXMIX_CORE0_BASE (0x44461800u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE0 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE0     ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE0_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base address */
  #define SRC_XSPR_CORTEXMIX_CORE1_BASE (0x44461C00u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE1 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE1     ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE1_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base address */
  #define SRC_XSPR_CORTEXMIX_CORE2_BASE (0x44462000u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE2 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE2     ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE2_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base address */
  #define SRC_XSPR_CORTEXMIX_CORE3_BASE (0x44462400u)
  /** Peripheral SRC_XSPR_CORTEXMIX_CORE3 base pointer */
  #define SRC_XSPR_CORTEXMIX_CORE3     ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_CORE3_BASE)
  /** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base address */
  #define SRC_XSPR_CORTEXMIX_PLATFORM_BASE (0x44462800u)
  /** Peripheral SRC_XSPR_CORTEXMIX_PLATFORM base pointer */
  #define SRC_XSPR_CORTEXMIX_PLATFORM  ((SRC_XSPR_Type *)SRC_XSPR_CORTEXMIX_PLATFORM_BASE)
  /** Peripheral SRC_XSPR_DDRMIX base address */
  #define SRC_XSPR_DDRMIX_BASE         (0x44462C00u)
  /** Peripheral SRC_XSPR_DDRMIX base pointer */
  #define SRC_XSPR_DDRMIX              ((SRC_XSPR_Type *)SRC_XSPR_DDRMIX_BASE)
  /** Peripheral SRC_XSPR_DISPLAYMIX base address */
  #define SRC_XSPR_DISPLAYMIX_BASE     (0x44463000u)
  /** Peripheral SRC_XSPR_DISPLAYMIX base pointer */
  #define SRC_XSPR_DISPLAYMIX          ((SRC_XSPR_Type *)SRC_XSPR_DISPLAYMIX_BASE)
  /** Peripheral SRC_XSPR_GPUMIX base address */
  #define SRC_XSPR_GPUMIX_BASE         (0x44463400u)
  /** Peripheral SRC_XSPR_GPUMIX base pointer */
  #define SRC_XSPR_GPUMIX              ((SRC_XSPR_Type *)SRC_XSPR_GPUMIX_BASE)
  /** Peripheral SRC_XSPR_HSIOMIX_TOP base address */
  #define SRC_XSPR_HSIOMIX_TOP_BASE    (0x44463800u)
  /** Peripheral SRC_XSPR_HSIOMIX_TOP base pointer */
  #define SRC_XSPR_HSIOMIX_TOP         ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_TOP_BASE)
  /** Peripheral SRC_XSPR_HSIOMIX_WAON base address */
  #define SRC_XSPR_HSIOMIX_WAON_BASE   (0x44463C00u)
  /** Peripheral SRC_XSPR_HSIOMIX_WAON base pointer */
  #define SRC_XSPR_HSIOMIX_WAON        ((SRC_XSPR_Type *)SRC_XSPR_HSIOMIX_WAON_BASE)
  /** Peripheral SRC_XSPR_M7MIX base address */
  #define SRC_XSPR_M7MIX_BASE          (0x44464000u)
  /** Peripheral SRC_XSPR_M7MIX base pointer */
  #define SRC_XSPR_M7MIX               ((SRC_XSPR_Type *)SRC_XSPR_M7MIX_BASE)
  /** Peripheral SRC_XSPR_NETCMIX base address */
  #define SRC_XSPR_NETCMIX_BASE        (0x44464400u)
  /** Peripheral SRC_XSPR_NETCMIX base pointer */
  #define SRC_XSPR_NETCMIX             ((SRC_XSPR_Type *)SRC_XSPR_NETCMIX_BASE)
  /** Peripheral SRC_XSPR_NOCMIX base address */
  #define SRC_XSPR_NOCMIX_BASE         (0x44464800u)
  /** Peripheral SRC_XSPR_NOCMIX base pointer */
  #define SRC_XSPR_NOCMIX              ((SRC_XSPR_Type *)SRC_XSPR_NOCMIX_BASE)
  /** Peripheral SRC_XSPR_NPUMIX base address */
  #define SRC_XSPR_NPUMIX_BASE         (0x44464C00u)
  /** Peripheral SRC_XSPR_NPUMIX base pointer */
  #define SRC_XSPR_NPUMIX              ((SRC_XSPR_Type *)SRC_XSPR_NPUMIX_BASE)
  /** Peripheral SRC_XSPR_VPUMIX base address */
  #define SRC_XSPR_VPUMIX_BASE         (0x44465000u)
  /** Peripheral SRC_XSPR_VPUMIX base pointer */
  #define SRC_XSPR_VPUMIX              ((SRC_XSPR_Type *)SRC_XSPR_VPUMIX_BASE)
  /** Peripheral SRC_XSPR_WAKEUPMIX base address */
  #define SRC_XSPR_WAKEUPMIX_BASE      (0x44465400u)
  /** Peripheral SRC_XSPR_WAKEUPMIX base pointer */
  #define SRC_XSPR_WAKEUPMIX           ((SRC_XSPR_Type *)SRC_XSPR_WAKEUPMIX_BASE)
  /** Array initializer of SRC_XSPR peripheral base addresses */
  #define SRC_XSPR_BASE_ADDRS                      { SRC_XSPR_ANAMIX_BASE, SRC_XSPR_AONMIX_BASE, SRC_XSPR_BBSMMIX_BASE, SRC_XSPR_CAMERAMIX_BASE, SRC_XSPR_CCMSRCGPCMIX_BASE, SRC_XSPR_CORTEXMIX_CORE0_BASE, SRC_XSPR_CORTEXMIX_CORE1_BASE, SRC_XSPR_CORTEXMIX_CORE2_BASE, SRC_XSPR_CORTEXMIX_CORE3_BASE, SRC_XSPR_CORTEXMIX_PLATFORM_BASE, SRC_XSPR_DDRMIX_BASE, SRC_XSPR_DISPLAYMIX_BASE, SRC_XSPR_GPUMIX_BASE, SRC_XSPR_HSIOMIX_TOP_BASE, SRC_XSPR_HSIOMIX_WAON_BASE, SRC_XSPR_M7MIX_BASE, SRC_XSPR_NETCMIX_BASE, SRC_XSPR_NOCMIX_BASE, SRC_XSPR_NPUMIX_BASE, SRC_XSPR_VPUMIX_BASE, SRC_XSPR_WAKEUPMIX_BASE }
  /** Array initializer of SRC_XSPR peripheral base pointers */
  #define SRC_XSPR_BASE_PTRS                       { SRC_XSPR_ANAMIX, SRC_XSPR_AONMIX, SRC_XSPR_BBSMMIX, SRC_XSPR_CAMERAMIX, SRC_XSPR_CCMSRCGPCMIX, SRC_XSPR_CORTEXMIX_CORE0, SRC_XSPR_CORTEXMIX_CORE1, SRC_XSPR_CORTEXMIX_CORE2, SRC_XSPR_CORTEXMIX_CORE3, SRC_XSPR_CORTEXMIX_PLATFORM, SRC_XSPR_DDRMIX, SRC_XSPR_DISPLAYMIX, SRC_XSPR_GPUMIX, SRC_XSPR_HSIOMIX_TOP, SRC_XSPR_HSIOMIX_WAON, SRC_XSPR_M7MIX, SRC_XSPR_NETCMIX, SRC_XSPR_NOCMIX, SRC_XSPR_NPUMIX, SRC_XSPR_VPUMIX, SRC_XSPR_WAKEUPMIX }
#endif

/* SYSPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__M33_PCF1 base address */
  #define AON__M33_PCF1_BASE                       (0x543E0000u)
  /** Peripheral AON__M33_PCF1 base address */
  #define AON__M33_PCF1_BASE_NS                    (0x443E0000u)
  /** Peripheral AON__M33_PCF1 base pointer */
  #define AON__M33_PCF1                            ((SYSPM_Type *)AON__M33_PCF1_BASE)
  /** Peripheral AON__M33_PCF1 base pointer */
  #define AON__M33_PCF1_NS                         ((SYSPM_Type *)AON__M33_PCF1_BASE_NS)
  /** Peripheral AON__M33_PSF2 base address */
  #define AON__M33_PSF2_BASE                       (0x543F0000u)
  /** Peripheral AON__M33_PSF2 base address */
  #define AON__M33_PSF2_BASE_NS                    (0x443F0000u)
  /** Peripheral AON__M33_PSF2 base pointer */
  #define AON__M33_PSF2                            ((SYSPM_Type *)AON__M33_PSF2_BASE)
  /** Peripheral AON__M33_PSF2 base pointer */
  #define AON__M33_PSF2_NS                         ((SYSPM_Type *)AON__M33_PSF2_BASE_NS)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { AON__M33_PCF1_BASE, AON__M33_PSF2_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { AON__M33_PCF1, AON__M33_PSF2 }
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS_NS                      { AON__M33_PCF1_BASE_NS, AON__M33_PSF2_BASE_NS }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS_NS                       { AON__M33_PCF1_NS, AON__M33_PSF2_NS }
#else
  /** Peripheral AON__M33_PCF1 base address */
  #define AON__M33_PCF1_BASE                       (0x443E0000u)
  /** Peripheral AON__M33_PCF1 base pointer */
  #define AON__M33_PCF1                            ((SYSPM_Type *)AON__M33_PCF1_BASE)
  /** Peripheral AON__M33_PSF2 base address */
  #define AON__M33_PSF2_BASE                       (0x443F0000u)
  /** Peripheral AON__M33_PSF2 base pointer */
  #define AON__M33_PSF2                            ((SYSPM_Type *)AON__M33_PSF2_BASE)
  /** Array initializer of SYSPM peripheral base addresses */
  #define SYSPM_BASE_ADDRS                         { AON__M33_PCF1_BASE, AON__M33_PSF2_BASE }
  /** Array initializer of SYSPM peripheral base pointers */
  #define SYSPM_BASE_PTRS                          { AON__M33_PCF1, AON__M33_PSF2 }
#endif

/* SYS_CTR_COMPARE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base address */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE_BASE      (0x542A0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base address */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE_BASE_NS   (0x442A0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base pointer */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE           ((SYS_CTR_COMPARE_Type *)AON__SYS_CTR1__SYS_CTR_COMPARE_BASE)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base pointer */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE_NS        ((SYS_CTR_COMPARE_Type *)AON__SYS_CTR1__SYS_CTR_COMPARE_BASE_NS)
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS               { AON__SYS_CTR1__SYS_CTR_COMPARE_BASE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS                { AON__SYS_CTR1__SYS_CTR_COMPARE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS_NS            { AON__SYS_CTR1__SYS_CTR_COMPARE_BASE_NS }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS_NS             { AON__SYS_CTR1__SYS_CTR_COMPARE_NS }
#else
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base address */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE_BASE      (0x442A0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_COMPARE base pointer */
  #define AON__SYS_CTR1__SYS_CTR_COMPARE           ((SYS_CTR_COMPARE_Type *)AON__SYS_CTR1__SYS_CTR_COMPARE_BASE)
  /** Array initializer of SYS_CTR_COMPARE peripheral base addresses */
  #define SYS_CTR_COMPARE_BASE_ADDRS               { AON__SYS_CTR1__SYS_CTR_COMPARE_BASE }
  /** Array initializer of SYS_CTR_COMPARE peripheral base pointers */
  #define SYS_CTR_COMPARE_BASE_PTRS                { AON__SYS_CTR1__SYS_CTR_COMPARE }
#endif

/* SYS_CTR_CONTROL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral SYS_CTR_CONTROL base address */
  #define SYS_CTR_CONTROL_BASE                     (0x54290000u)
  /** Peripheral SYS_CTR_CONTROL base address */
  #define SYS_CTR_CONTROL_BASE_NS                  (0x44290000u)
  /** Peripheral SYS_CTR_CONTROL base pointer */
  #define SYS_CTR_CONTROL                          ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE)
  /** Peripheral SYS_CTR_CONTROL base pointer */
  #define SYS_CTR_CONTROL_NS                       ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE_NS)
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS               { SYS_CTR_CONTROL_BASE }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS                { SYS_CTR_CONTROL }
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS_NS            { SYS_CTR_CONTROL_BASE_NS }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS_NS             { SYS_CTR_CONTROL_NS }
#else
  /** Peripheral SYS_CTR_CONTROL base address */
  #define SYS_CTR_CONTROL_BASE                     (0x44290000u)
  /** Peripheral SYS_CTR_CONTROL base pointer */
  #define SYS_CTR_CONTROL                          ((SYS_CTR_CONTROL_Type *)SYS_CTR_CONTROL_BASE)
  /** Array initializer of SYS_CTR_CONTROL peripheral base addresses */
  #define SYS_CTR_CONTROL_BASE_ADDRS               { SYS_CTR_CONTROL_BASE }
  /** Array initializer of SYS_CTR_CONTROL peripheral base pointers */
  #define SYS_CTR_CONTROL_BASE_PTRS                { SYS_CTR_CONTROL }
#endif

/* SYS_CTR_READ - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base address */
  #define AON__SYS_CTR1__SYS_CTR_READ_BASE         (0x542B0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base address */
  #define AON__SYS_CTR1__SYS_CTR_READ_BASE_NS      (0x442B0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base pointer */
  #define AON__SYS_CTR1__SYS_CTR_READ              ((SYS_CTR_READ_Type *)AON__SYS_CTR1__SYS_CTR_READ_BASE)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base pointer */
  #define AON__SYS_CTR1__SYS_CTR_READ_NS           ((SYS_CTR_READ_Type *)AON__SYS_CTR1__SYS_CTR_READ_BASE_NS)
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS                  { AON__SYS_CTR1__SYS_CTR_READ_BASE }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS                   { AON__SYS_CTR1__SYS_CTR_READ }
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS_NS               { AON__SYS_CTR1__SYS_CTR_READ_BASE_NS }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS_NS                { AON__SYS_CTR1__SYS_CTR_READ_NS }
#else
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base address */
  #define AON__SYS_CTR1__SYS_CTR_READ_BASE         (0x442B0000u)
  /** Peripheral AON__SYS_CTR1__SYS_CTR_READ base pointer */
  #define AON__SYS_CTR1__SYS_CTR_READ              ((SYS_CTR_READ_Type *)AON__SYS_CTR1__SYS_CTR_READ_BASE)
  /** Array initializer of SYS_CTR_READ peripheral base addresses */
  #define SYS_CTR_READ_BASE_ADDRS                  { AON__SYS_CTR1__SYS_CTR_READ_BASE }
  /** Array initializer of SYS_CTR_READ peripheral base pointers */
  #define SYS_CTR_READ_BASE_PTRS                   { AON__SYS_CTR1__SYS_CTR_READ }
#endif

/* SerDes_SS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE (0x5C340000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE_NS (0x4C340000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS ((SerDes_SS_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_NS ((SerDes_SS_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE_NS)
  /** Array initializer of SerDes_SS peripheral base addresses */
  #define SerDes_SS_BASE_ADDRS                     { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE }
  /** Array initializer of SerDes_SS peripheral base pointers */
  #define SerDes_SS_BASE_PTRS                      { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS }
  /** Array initializer of SerDes_SS peripheral base addresses */
  #define SerDes_SS_BASE_ADDRS_NS                  { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE_NS }
  /** Array initializer of SerDes_SS peripheral base pointers */
  #define SerDes_SS_BASE_PTRS_NS                   { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_NS }
#else
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE (0x4C340000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS ((SerDes_SS_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE)
  /** Array initializer of SerDes_SS peripheral base addresses */
  #define SerDes_SS_BASE_ADDRS                     { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS_BASE }
  /** Array initializer of SerDes_SS peripheral base pointers */
  #define SerDes_SS_BASE_PTRS                      { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__SERDES_SS }
#endif

/* TCM_ECC_MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base address */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE (0x54420000u)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base address */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE_NS (0x44420000u)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base pointer */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM   ((TCM_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base pointer */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_NS ((TCM_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE_NS)
  /** Array initializer of TCM_ECC_MCM peripheral base addresses */
  #define TCM_ECC_MCM_BASE_ADDRS                   { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE }
  /** Array initializer of TCM_ECC_MCM peripheral base pointers */
  #define TCM_ECC_MCM_BASE_PTRS                    { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM }
  /** Array initializer of TCM_ECC_MCM peripheral base addresses */
  #define TCM_ECC_MCM_BASE_ADDRS_NS                { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE_NS }
  /** Array initializer of TCM_ECC_MCM peripheral base pointers */
  #define TCM_ECC_MCM_BASE_PTRS_NS                 { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_NS }
#else
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base address */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE (0x44420000u)
  /** Peripheral AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM base pointer */
  #define AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM   ((TCM_ECC_MCM_Type *)AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE)
  /** Array initializer of TCM_ECC_MCM peripheral base addresses */
  #define TCM_ECC_MCM_BASE_ADDRS                   { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM_BASE }
  /** Array initializer of TCM_ECC_MCM peripheral base pointers */
  #define TCM_ECC_MCM_BASE_PTRS                    { AON__M33_CACHE_CTRL_ECC0__CM33_TCM_MCM }
#endif

/* TMPSNS - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TMPSNS1 base address */
  #define TMPSNS1_BASE                             (0x54482000u)
  /** Peripheral TMPSNS1 base address */
  #define TMPSNS1_BASE_NS                          (0x44482000u)
  /** Peripheral TMPSNS1 base pointer */
  #define TMPSNS1                                  ((TMPSNS_Type *)TMPSNS1_BASE)
  /** Peripheral TMPSNS1 base pointer */
  #define TMPSNS1_NS                               ((TMPSNS_Type *)TMPSNS1_BASE_NS)
  /** Peripheral TMPSNS2 base address */
  #define TMPSNS2_BASE                             (0x5A440000u)
  /** Peripheral TMPSNS2 base address */
  #define TMPSNS2_BASE_NS                          (0x4A440000u)
  /** Peripheral TMPSNS2 base pointer */
  #define TMPSNS2                                  ((TMPSNS_Type *)TMPSNS2_BASE)
  /** Peripheral TMPSNS2 base pointer */
  #define TMPSNS2_NS                               ((TMPSNS_Type *)TMPSNS2_BASE_NS)
  /** Array initializer of TMPSNS peripheral base addresses */
  #define TMPSNS_BASE_ADDRS                        { TMPSNS1_BASE, TMPSNS2_BASE }
  /** Array initializer of TMPSNS peripheral base pointers */
  #define TMPSNS_BASE_PTRS                         { TMPSNS1, TMPSNS2 }
  /** Array initializer of TMPSNS peripheral base addresses */
  #define TMPSNS_BASE_ADDRS_NS                     { TMPSNS1_BASE_NS, TMPSNS2_BASE_NS }
  /** Array initializer of TMPSNS peripheral base pointers */
  #define TMPSNS_BASE_PTRS_NS                      { TMPSNS1_NS, TMPSNS2_NS }
#else
  /** Peripheral TMPSNS1 base address */
  #define TMPSNS1_BASE                             (0x44482000u)
  /** Peripheral TMPSNS1 base pointer */
  #define TMPSNS1                                  ((TMPSNS_Type *)TMPSNS1_BASE)
  /** Peripheral TMPSNS2 base address */
  #define TMPSNS2_BASE                             (0x4A440000u)
  /** Peripheral TMPSNS2 base pointer */
  #define TMPSNS2                                  ((TMPSNS_Type *)TMPSNS2_BASE)
  /** Array initializer of TMPSNS peripheral base addresses */
  #define TMPSNS_BASE_ADDRS                        { TMPSNS1_BASE, TMPSNS2_BASE }
  /** Array initializer of TMPSNS peripheral base pointers */
  #define TMPSNS_BASE_PTRS                         { TMPSNS1, TMPSNS2 }
#endif

/* TMR_GLOBAL - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__TMR0_GLOBAL base address */
  #define NETC__NETC__TMR0_GLOBAL_BASE             (0x5CC90000u)
  /** Peripheral NETC__NETC__TMR0_GLOBAL base address */
  #define NETC__NETC__TMR0_GLOBAL_BASE_NS          (0x4CC90000u)
  /** Peripheral NETC__NETC__TMR0_GLOBAL base pointer */
  #define NETC__NETC__TMR0_GLOBAL                  ((TMR_GLOBAL_Type *)NETC__NETC__TMR0_GLOBAL_BASE)
  /** Peripheral NETC__NETC__TMR0_GLOBAL base pointer */
  #define NETC__NETC__TMR0_GLOBAL_NS               ((TMR_GLOBAL_Type *)NETC__NETC__TMR0_GLOBAL_BASE_NS)
  /** Array initializer of TMR_GLOBAL peripheral base addresses */
  #define TMR_GLOBAL_BASE_ADDRS                    { NETC__NETC__TMR0_GLOBAL_BASE }
  /** Array initializer of TMR_GLOBAL peripheral base pointers */
  #define TMR_GLOBAL_BASE_PTRS                     { NETC__NETC__TMR0_GLOBAL }
  /** Array initializer of TMR_GLOBAL peripheral base addresses */
  #define TMR_GLOBAL_BASE_ADDRS_NS                 { NETC__NETC__TMR0_GLOBAL_BASE_NS }
  /** Array initializer of TMR_GLOBAL peripheral base pointers */
  #define TMR_GLOBAL_BASE_PTRS_NS                  { NETC__NETC__TMR0_GLOBAL_NS }
#else
  /** Peripheral NETC__NETC__TMR0_GLOBAL base address */
  #define NETC__NETC__TMR0_GLOBAL_BASE             (0x4CC90000u)
  /** Peripheral NETC__NETC__TMR0_GLOBAL base pointer */
  #define NETC__NETC__TMR0_GLOBAL                  ((TMR_GLOBAL_Type *)NETC__NETC__TMR0_GLOBAL_BASE)
  /** Array initializer of TMR_GLOBAL peripheral base addresses */
  #define TMR_GLOBAL_BASE_ADDRS                    { NETC__NETC__TMR0_GLOBAL_BASE }
  /** Array initializer of TMR_GLOBAL peripheral base pointers */
  #define TMR_GLOBAL_BASE_PTRS                     { NETC__NETC__TMR0_GLOBAL }
#endif

/* TMR_PCI_HDR_TYPE0 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__NETC__TMR0_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__TMR0_PCI_HDR_TYPE0_BASE      (0x5CA01000u)
  /** Peripheral NETC__NETC__TMR0_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__TMR0_PCI_HDR_TYPE0_BASE_NS   (0x4CA01000u)
  /** Peripheral NETC__NETC__TMR0_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__TMR0_PCI_HDR_TYPE0           ((TMR_PCI_HDR_TYPE0_Type *)NETC__NETC__TMR0_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__NETC__TMR0_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__TMR0_PCI_HDR_TYPE0_NS        ((TMR_PCI_HDR_TYPE0_Type *)NETC__NETC__TMR0_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base addresses */
  #define TMR_PCI_HDR_TYPE0_BASE_ADDRS             { NETC__NETC__TMR0_PCI_HDR_TYPE0_BASE }
  /** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base pointers */
  #define TMR_PCI_HDR_TYPE0_BASE_PTRS              { NETC__NETC__TMR0_PCI_HDR_TYPE0 }
  /** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base addresses */
  #define TMR_PCI_HDR_TYPE0_BASE_ADDRS_NS          { NETC__NETC__TMR0_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base pointers */
  #define TMR_PCI_HDR_TYPE0_BASE_PTRS_NS           { NETC__NETC__TMR0_PCI_HDR_TYPE0_NS }
#else
  /** Peripheral NETC__NETC__TMR0_PCI_HDR_TYPE0 base address */
  #define NETC__NETC__TMR0_PCI_HDR_TYPE0_BASE      (0x4CA01000u)
  /** Peripheral NETC__NETC__TMR0_PCI_HDR_TYPE0 base pointer */
  #define NETC__NETC__TMR0_PCI_HDR_TYPE0           ((TMR_PCI_HDR_TYPE0_Type *)NETC__NETC__TMR0_PCI_HDR_TYPE0_BASE)
  /** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base addresses */
  #define TMR_PCI_HDR_TYPE0_BASE_ADDRS             { NETC__NETC__TMR0_PCI_HDR_TYPE0_BASE }
  /** Array initializer of TMR_PCI_HDR_TYPE0 peripheral base pointers */
  #define TMR_PCI_HDR_TYPE0_BASE_PTRS              { NETC__NETC__TMR0_PCI_HDR_TYPE0 }
#endif

/* TPM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TPM1 base address */
  #define TPM1_BASE                                (0x54310000u)
  /** Peripheral TPM1 base address */
  #define TPM1_BASE_NS                             (0x44310000u)
  /** Peripheral TPM1 base pointer */
  #define TPM1                                     ((TPM_Type *)TPM1_BASE)
  /** Peripheral TPM1 base pointer */
  #define TPM1_NS                                  ((TPM_Type *)TPM1_BASE_NS)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE                                (0x54320000u)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE_NS                             (0x44320000u)
  /** Peripheral TPM2 base pointer */
  #define TPM2                                     ((TPM_Type *)TPM2_BASE)
  /** Peripheral TPM2 base pointer */
  #define TPM2_NS                                  ((TPM_Type *)TPM2_BASE_NS)
  /** Peripheral TPM3 base address */
  #define TPM3_BASE                                (0x52100000u)
  /** Peripheral TPM3 base address */
  #define TPM3_BASE_NS                             (0x42100000u)
  /** Peripheral TPM3 base pointer */
  #define TPM3                                     ((TPM_Type *)TPM3_BASE)
  /** Peripheral TPM3 base pointer */
  #define TPM3_NS                                  ((TPM_Type *)TPM3_BASE_NS)
  /** Peripheral TPM4 base address */
  #define TPM4_BASE                                (0x52110000u)
  /** Peripheral TPM4 base address */
  #define TPM4_BASE_NS                             (0x42110000u)
  /** Peripheral TPM4 base pointer */
  #define TPM4                                     ((TPM_Type *)TPM4_BASE)
  /** Peripheral TPM4 base pointer */
  #define TPM4_NS                                  ((TPM_Type *)TPM4_BASE_NS)
  /** Peripheral TPM5 base address */
  #define TPM5_BASE                                (0x52120000u)
  /** Peripheral TPM5 base address */
  #define TPM5_BASE_NS                             (0x42120000u)
  /** Peripheral TPM5 base pointer */
  #define TPM5                                     ((TPM_Type *)TPM5_BASE)
  /** Peripheral TPM5 base pointer */
  #define TPM5_NS                                  ((TPM_Type *)TPM5_BASE_NS)
  /** Peripheral TPM6 base address */
  #define TPM6_BASE                                (0x52130000u)
  /** Peripheral TPM6 base address */
  #define TPM6_BASE_NS                             (0x42130000u)
  /** Peripheral TPM6 base pointer */
  #define TPM6                                     ((TPM_Type *)TPM6_BASE)
  /** Peripheral TPM6 base pointer */
  #define TPM6_NS                                  ((TPM_Type *)TPM6_BASE_NS)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { 0u, TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { (TPM_Type *)0u, TPM1, TPM2, TPM3, TPM4, TPM5, TPM6 }
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS_NS                        { 0u, TPM1_BASE_NS, TPM2_BASE_NS, TPM3_BASE_NS, TPM4_BASE_NS, TPM5_BASE_NS, TPM6_BASE_NS }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS_NS                         { (TPM_Type *)0u, TPM1_NS, TPM2_NS, TPM3_NS, TPM4_NS, TPM5_NS, TPM6_NS }
#else
  /** Peripheral TPM1 base address */
  #define TPM1_BASE                                (0x44310000u)
  /** Peripheral TPM1 base pointer */
  #define TPM1                                     ((TPM_Type *)TPM1_BASE)
  /** Peripheral TPM2 base address */
  #define TPM2_BASE                                (0x44320000u)
  /** Peripheral TPM2 base pointer */
  #define TPM2                                     ((TPM_Type *)TPM2_BASE)
  /** Peripheral TPM3 base address */
  #define TPM3_BASE                                (0x42100000u)
  /** Peripheral TPM3 base pointer */
  #define TPM3                                     ((TPM_Type *)TPM3_BASE)
  /** Peripheral TPM4 base address */
  #define TPM4_BASE                                (0x42110000u)
  /** Peripheral TPM4 base pointer */
  #define TPM4                                     ((TPM_Type *)TPM4_BASE)
  /** Peripheral TPM5 base address */
  #define TPM5_BASE                                (0x42120000u)
  /** Peripheral TPM5 base pointer */
  #define TPM5                                     ((TPM_Type *)TPM5_BASE)
  /** Peripheral TPM6 base address */
  #define TPM6_BASE                                (0x42130000u)
  /** Peripheral TPM6 base pointer */
  #define TPM6                                     ((TPM_Type *)TPM6_BASE)
  /** Array initializer of TPM peripheral base addresses */
  #define TPM_BASE_ADDRS                           { 0u, TPM1_BASE, TPM2_BASE, TPM3_BASE, TPM4_BASE, TPM5_BASE, TPM6_BASE }
  /** Array initializer of TPM peripheral base pointers */
  #define TPM_BASE_PTRS                            { (TPM_Type *)0u, TPM1, TPM2, TPM3, TPM4, TPM5, TPM6 }
#endif
/** Interrupt vectors for the TPM peripheral type */
#define TPM_IRQS                                 { NotAvail_IRQn, TPM1_IRQn, TPM2_IRQn, TPM3_IRQn, TPM4_IRQn, TPM5_IRQn, TPM6_IRQn }

/* TRDC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WAKEUP__TRDC_MGR1 base address */
  #define WAKEUP__TRDC_MGR1_BASE                   (0x52080000u)
  /** Peripheral WAKEUP__TRDC_MGR1 base address */
  #define WAKEUP__TRDC_MGR1_BASE_NS                (0x42080000u)
  /** Peripheral WAKEUP__TRDC_MGR1 base pointer */
  #define WAKEUP__TRDC_MGR1                        ((TRDC_Type *)WAKEUP__TRDC_MGR1_BASE)
  /** Peripheral WAKEUP__TRDC_MGR1 base pointer */
  #define WAKEUP__TRDC_MGR1_NS                     ((TRDC_Type *)WAKEUP__TRDC_MGR1_BASE_NS)
  /** Peripheral WAKEUP__TRDC_MGR2 base address */
  #define WAKEUP__TRDC_MGR2_BASE                   (0x524C0000u)
  /** Peripheral WAKEUP__TRDC_MGR2 base address */
  #define WAKEUP__TRDC_MGR2_BASE_NS                (0x424C0000u)
  /** Peripheral WAKEUP__TRDC_MGR2 base pointer */
  #define WAKEUP__TRDC_MGR2                        ((TRDC_Type *)WAKEUP__TRDC_MGR2_BASE)
  /** Peripheral WAKEUP__TRDC_MGR2 base pointer */
  #define WAKEUP__TRDC_MGR2_NS                     ((TRDC_Type *)WAKEUP__TRDC_MGR2_BASE_NS)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { WAKEUP__TRDC_MGR1_BASE, WAKEUP__TRDC_MGR2_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { WAKEUP__TRDC_MGR1, WAKEUP__TRDC_MGR2 }
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS_NS                       { WAKEUP__TRDC_MGR1_BASE_NS, WAKEUP__TRDC_MGR2_BASE_NS }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS_NS                        { WAKEUP__TRDC_MGR1_NS, WAKEUP__TRDC_MGR2_NS }
#else
  /** Peripheral WAKEUP__TRDC_MGR1 base address */
  #define WAKEUP__TRDC_MGR1_BASE                   (0x42080000u)
  /** Peripheral WAKEUP__TRDC_MGR1 base pointer */
  #define WAKEUP__TRDC_MGR1                        ((TRDC_Type *)WAKEUP__TRDC_MGR1_BASE)
  /** Peripheral WAKEUP__TRDC_MGR2 base address */
  #define WAKEUP__TRDC_MGR2_BASE                   (0x424C0000u)
  /** Peripheral WAKEUP__TRDC_MGR2 base pointer */
  #define WAKEUP__TRDC_MGR2                        ((TRDC_Type *)WAKEUP__TRDC_MGR2_BASE)
  /** Array initializer of TRDC peripheral base addresses */
  #define TRDC_BASE_ADDRS                          { WAKEUP__TRDC_MGR1_BASE, WAKEUP__TRDC_MGR2_BASE }
  /** Array initializer of TRDC peripheral base pointers */
  #define TRDC_BASE_PTRS                           { WAKEUP__TRDC_MGR1, WAKEUP__TRDC_MGR2 }
#endif
#define MBC0_MEMORY_CFG_WORD_COUNT {1,2,4,1}
#define MBC1_MEMORY_CFG_WORD_COUNT {1,1,1,1}
#define MBC2_MEMORY_CFG_WORD_COUNT {9,6,1,1}
#define MBC3_MEMORY_CFG_WORD_COUNT {3,0,0,0}
#define MBC_MEMORY_CFG_WORD_COUNT {MBC0_MEMORY_CFG_WORD_COUNT , MBC1_MEMORY_CFG_WORD_COUNT, MBC2_MEMORY_CFG_WORD_COUNT, MBC3_MEMORY_CFG_WORD_COUNT}
#define MBC0_MEMORY_NSE_WORD_COUNT {1,1,1,1}
#define MBC1_MEMORY_NSE_WORD_COUNT {1,1,1,1}
#define MBC2_MEMORY_NSE_WORD_COUNT {3,2,1,1}
#define MBC3_MEMORY_NSE_WORD_COUNT {1,0,0,0}
#define MBC_MEMORY_NSE_WORD_COUNT {MBC0_MEMORY_NSE_WORD_COUNT , MBC1_MEMORY_NSE_WORD_COUNT, MBC2_MEMORY_NSE_WORD_COUNT, MBC3_MEMORY_NSE_WORD_COUNT}


/* TRGMUX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANALOG__TRGMUX base address */
  #define ANALOG__TRGMUX_BASE                      (0x54531000u)
  /** Peripheral ANALOG__TRGMUX base address */
  #define ANALOG__TRGMUX_BASE_NS                   (0x44531000u)
  /** Peripheral ANALOG__TRGMUX base pointer */
  #define ANALOG__TRGMUX                           ((TRGMUX_Type *)ANALOG__TRGMUX_BASE)
  /** Peripheral ANALOG__TRGMUX base pointer */
  #define ANALOG__TRGMUX_NS                        ((TRGMUX_Type *)ANALOG__TRGMUX_BASE_NS)
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS                        { ANALOG__TRGMUX_BASE }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS                         { ANALOG__TRGMUX }
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS_NS                     { ANALOG__TRGMUX_BASE_NS }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS_NS                      { ANALOG__TRGMUX_NS }
#else
  /** Peripheral ANALOG__TRGMUX base address */
  #define ANALOG__TRGMUX_BASE                      (0x44531000u)
  /** Peripheral ANALOG__TRGMUX base pointer */
  #define ANALOG__TRGMUX                           ((TRGMUX_Type *)ANALOG__TRGMUX_BASE)
  /** Array initializer of TRGMUX peripheral base addresses */
  #define TRGMUX_BASE_ADDRS                        { ANALOG__TRGMUX_BASE }
  /** Array initializer of TRGMUX peripheral base pointers */
  #define TRGMUX_BASE_PTRS                         { ANALOG__TRGMUX }
#endif

/* TSTMR - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral TSTMR1 base address */
  #define TSTMR1_BASE                              (0x542C0000u)
  /** Peripheral TSTMR1 base address */
  #define TSTMR1_BASE_NS                           (0x442C0000u)
  /** Peripheral TSTMR1 base pointer */
  #define TSTMR1                                   ((TSTMR_Type *)TSTMR1_BASE)
  /** Peripheral TSTMR1 base pointer */
  #define TSTMR1_NS                                ((TSTMR_Type *)TSTMR1_BASE_NS)
  /** Peripheral TSTMR2 base address */
  #define TSTMR2_BASE                              (0x520A0000u)
  /** Peripheral TSTMR2 base address */
  #define TSTMR2_BASE_NS                           (0x420A0000u)
  /** Peripheral TSTMR2 base pointer */
  #define TSTMR2                                   ((TSTMR_Type *)TSTMR2_BASE)
  /** Peripheral TSTMR2 base pointer */
  #define TSTMR2_NS                                ((TSTMR_Type *)TSTMR2_BASE_NS)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { 0u, TSTMR1_BASE, TSTMR2_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { (TSTMR_Type *)0u, TSTMR1, TSTMR2 }
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS_NS                      { 0u, TSTMR1_BASE_NS, TSTMR2_BASE_NS }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS_NS                       { (TSTMR_Type *)0u, TSTMR1_NS, TSTMR2_NS }
#else
  /** Peripheral TSTMR1 base address */
  #define TSTMR1_BASE                              (0x442C0000u)
  /** Peripheral TSTMR1 base pointer */
  #define TSTMR1                                   ((TSTMR_Type *)TSTMR1_BASE)
  /** Peripheral TSTMR2 base address */
  #define TSTMR2_BASE                              (0x420A0000u)
  /** Peripheral TSTMR2 base pointer */
  #define TSTMR2                                   ((TSTMR_Type *)TSTMR2_BASE)
  /** Array initializer of TSTMR peripheral base addresses */
  #define TSTMR_BASE_ADDRS                         { 0u, TSTMR1_BASE, TSTMR2_BASE }
  /** Array initializer of TSTMR peripheral base pointers */
  #define TSTMR_BASE_PTRS                          { (TSTMR_Type *)0u, TSTMR1, TSTMR2 }
#endif
/* Extra definition */
#define TSTMR_CLOCK_FREQUENCY_MHZ                (24U)


/* USB - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USB_OTG1 base address */
  #define USB_OTG1_BASE                            (0x5C100000u)
  /** Peripheral USB_OTG1 base address */
  #define USB_OTG1_BASE_NS                         (0x4C100000u)
  /** Peripheral USB_OTG1 base pointer */
  #define USB_OTG1                                 ((USB_Type *)USB_OTG1_BASE)
  /** Peripheral USB_OTG1 base pointer */
  #define USB_OTG1_NS                              ((USB_Type *)USB_OTG1_BASE_NS)
  /** Peripheral USB_OTG2 base address */
  #define USB_OTG2_BASE                            (0x5C200000u)
  /** Peripheral USB_OTG2 base address */
  #define USB_OTG2_BASE_NS                         (0x4C200000u)
  /** Peripheral USB_OTG2 base pointer */
  #define USB_OTG2                                 ((USB_Type *)USB_OTG2_BASE)
  /** Peripheral USB_OTG2 base pointer */
  #define USB_OTG2_NS                              ((USB_Type *)USB_OTG2_BASE_NS)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { 0u, USB_OTG1_BASE, USB_OTG2_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { (USB_Type *)0u, USB_OTG1, USB_OTG2 }
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS_NS                        { 0u, USB_OTG1_BASE_NS, USB_OTG2_BASE_NS }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS_NS                         { (USB_Type *)0u, USB_OTG1_NS, USB_OTG2_NS }
#else
  /** Peripheral USB_OTG1 base address */
  #define USB_OTG1_BASE                            (0x4C100000u)
  /** Peripheral USB_OTG1 base pointer */
  #define USB_OTG1                                 ((USB_Type *)USB_OTG1_BASE)
  /** Peripheral USB_OTG2 base address */
  #define USB_OTG2_BASE                            (0x4C200000u)
  /** Peripheral USB_OTG2 base pointer */
  #define USB_OTG2                                 ((USB_Type *)USB_OTG2_BASE)
  /** Array initializer of USB peripheral base addresses */
  #define USB_BASE_ADDRS                           { 0u, USB_OTG1_BASE, USB_OTG2_BASE }
  /** Array initializer of USB peripheral base pointers */
  #define USB_BASE_PTRS                            { (USB_Type *)0u, USB_OTG1, USB_OTG2 }
#endif

/* USBNC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral USBNC_OTG1 base address */
  #define USBNC_OTG1_BASE                          (0x5C100200u)
  /** Peripheral USBNC_OTG1 base address */
  #define USBNC_OTG1_BASE_NS                       (0x4C100200u)
  /** Peripheral USBNC_OTG1 base pointer */
  #define USBNC_OTG1                               ((USBNC_Type *)USBNC_OTG1_BASE)
  /** Peripheral USBNC_OTG1 base pointer */
  #define USBNC_OTG1_NS                            ((USBNC_Type *)USBNC_OTG1_BASE_NS)
  /** Peripheral USBNC_OTG2 base address */
  #define USBNC_OTG2_BASE                          (0x5C200200u)
  /** Peripheral USBNC_OTG2 base address */
  #define USBNC_OTG2_BASE_NS                       (0x4C200200u)
  /** Peripheral USBNC_OTG2 base pointer */
  #define USBNC_OTG2                               ((USBNC_Type *)USBNC_OTG2_BASE)
  /** Peripheral USBNC_OTG2 base pointer */
  #define USBNC_OTG2_NS                            ((USBNC_Type *)USBNC_OTG2_BASE_NS)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { USBNC_OTG1_BASE, USBNC_OTG2_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { USBNC_OTG1, USBNC_OTG2 }
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS_NS                      { USBNC_OTG1_BASE_NS, USBNC_OTG2_BASE_NS }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS_NS                       { USBNC_OTG1_NS, USBNC_OTG2_NS }
#else
  /** Peripheral USBNC_OTG1 base address */
  #define USBNC_OTG1_BASE                          (0x4C100200u)
  /** Peripheral USBNC_OTG1 base pointer */
  #define USBNC_OTG1                               ((USBNC_Type *)USBNC_OTG1_BASE)
  /** Peripheral USBNC_OTG2 base address */
  #define USBNC_OTG2_BASE                          (0x4C200200u)
  /** Peripheral USBNC_OTG2 base pointer */
  #define USBNC_OTG2                               ((USBNC_Type *)USBNC_OTG2_BASE)
  /** Array initializer of USBNC peripheral base addresses */
  #define USBNC_BASE_ADDRS                         { USBNC_OTG1_BASE, USBNC_OTG2_BASE }
  /** Array initializer of USBNC peripheral base pointers */
  #define USBNC_BASE_PTRS                          { USBNC_OTG1, USBNC_OTG2 }
#endif

/* USDHC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral uSDHC1 base address */
  #define uSDHC1_BASE                              (0x52C20000u)
  /** Peripheral uSDHC1 base address */
  #define uSDHC1_BASE_NS                           (0x42C20000u)
  /** Peripheral uSDHC1 base pointer */
  #define uSDHC1                                   ((USDHC_Type *)uSDHC1_BASE)
  /** Peripheral uSDHC1 base pointer */
  #define uSDHC1_NS                                ((USDHC_Type *)uSDHC1_BASE_NS)
  /** Peripheral uSDHC2 base address */
  #define uSDHC2_BASE                              (0x52C30000u)
  /** Peripheral uSDHC2 base address */
  #define uSDHC2_BASE_NS                           (0x42C30000u)
  /** Peripheral uSDHC2 base pointer */
  #define uSDHC2                                   ((USDHC_Type *)uSDHC2_BASE)
  /** Peripheral uSDHC2 base pointer */
  #define uSDHC2_NS                                ((USDHC_Type *)uSDHC2_BASE_NS)
  /** Peripheral uSDHC3 base address */
  #define uSDHC3_BASE                              (0x52C40000u)
  /** Peripheral uSDHC3 base address */
  #define uSDHC3_BASE_NS                           (0x42C40000u)
  /** Peripheral uSDHC3 base pointer */
  #define uSDHC3                                   ((USDHC_Type *)uSDHC3_BASE)
  /** Peripheral uSDHC3 base pointer */
  #define uSDHC3_NS                                ((USDHC_Type *)uSDHC3_BASE_NS)
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS                         { 0u, uSDHC1_BASE, uSDHC2_BASE, uSDHC3_BASE }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS                          { (USDHC_Type *)0u, uSDHC1, uSDHC2, uSDHC3 }
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS_NS                      { 0u, uSDHC1_BASE_NS, uSDHC2_BASE_NS, uSDHC3_BASE_NS }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS_NS                       { (USDHC_Type *)0u, uSDHC1_NS, uSDHC2_NS, uSDHC3_NS }
#else
  /** Peripheral uSDHC1 base address */
  #define uSDHC1_BASE                              (0x42C20000u)
  /** Peripheral uSDHC1 base pointer */
  #define uSDHC1                                   ((USDHC_Type *)uSDHC1_BASE)
  /** Peripheral uSDHC2 base address */
  #define uSDHC2_BASE                              (0x42C30000u)
  /** Peripheral uSDHC2 base pointer */
  #define uSDHC2                                   ((USDHC_Type *)uSDHC2_BASE)
  /** Peripheral uSDHC3 base address */
  #define uSDHC3_BASE                              (0x42C40000u)
  /** Peripheral uSDHC3 base pointer */
  #define uSDHC3                                   ((USDHC_Type *)uSDHC3_BASE)
  /** Array initializer of USDHC peripheral base addresses */
  #define USDHC_BASE_ADDRS                         { 0u, uSDHC1_BASE, uSDHC2_BASE, uSDHC3_BASE }
  /** Array initializer of USDHC peripheral base pointers */
  #define USDHC_BASE_PTRS                          { (USDHC_Type *)0u, uSDHC1, uSDHC2, uSDHC3 }
#endif

/* USER - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral GPU__REG__USER base address */
  #define GPU__REG__USER_BASE                      (0x5D910000u)
  /** Peripheral GPU__REG__USER base address */
  #define GPU__REG__USER_BASE_NS                   (0x4D910000u)
  /** Peripheral GPU__REG__USER base pointer */
  #define GPU__REG__USER                           ((USER_Type *)GPU__REG__USER_BASE)
  /** Peripheral GPU__REG__USER base pointer */
  #define GPU__REG__USER_NS                        ((USER_Type *)GPU__REG__USER_BASE_NS)
  /** Array initializer of USER peripheral base addresses */
  #define USER_BASE_ADDRS                          { GPU__REG__USER_BASE }
  /** Array initializer of USER peripheral base pointers */
  #define USER_BASE_PTRS                           { GPU__REG__USER }
  /** Array initializer of USER peripheral base addresses */
  #define USER_BASE_ADDRS_NS                       { GPU__REG__USER_BASE_NS }
  /** Array initializer of USER peripheral base pointers */
  #define USER_BASE_PTRS_NS                        { GPU__REG__USER_NS }
#else
  /** Peripheral GPU__REG__USER base address */
  #define GPU__REG__USER_BASE                      (0x4D910000u)
  /** Peripheral GPU__REG__USER base pointer */
  #define GPU__REG__USER                           ((USER_Type *)GPU__REG__USER_BASE)
  /** Array initializer of USER peripheral base addresses */
  #define USER_BASE_ADDRS                          { GPU__REG__USER_BASE }
  /** Array initializer of USER peripheral base pointers */
  #define USER_BASE_PTRS                           { GPU__REG__USER }
#endif

/* VDET - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral ANALOG__VDET base address */
  #define ANALOG__VDET_BASE                        (0x54486000u)
  /** Peripheral ANALOG__VDET base address */
  #define ANALOG__VDET_BASE_NS                     (0x44486000u)
  /** Peripheral ANALOG__VDET base pointer */
  #define ANALOG__VDET                             ((VDET_Type *)ANALOG__VDET_BASE)
  /** Peripheral ANALOG__VDET base pointer */
  #define ANALOG__VDET_NS                          ((VDET_Type *)ANALOG__VDET_BASE_NS)
  /** Array initializer of VDET peripheral base addresses */
  #define VDET_BASE_ADDRS                          { ANALOG__VDET_BASE }
  /** Array initializer of VDET peripheral base pointers */
  #define VDET_BASE_PTRS                           { ANALOG__VDET }
  /** Array initializer of VDET peripheral base addresses */
  #define VDET_BASE_ADDRS_NS                       { ANALOG__VDET_BASE_NS }
  /** Array initializer of VDET peripheral base pointers */
  #define VDET_BASE_PTRS_NS                        { ANALOG__VDET_NS }
#else
  /** Peripheral ANALOG__VDET base address */
  #define ANALOG__VDET_BASE                        (0x44486000u)
  /** Peripheral ANALOG__VDET base pointer */
  #define ANALOG__VDET                             ((VDET_Type *)ANALOG__VDET_BASE)
  /** Array initializer of VDET peripheral base addresses */
  #define VDET_BASE_ADDRS                          { ANALOG__VDET_BASE }
  /** Array initializer of VDET peripheral base pointers */
  #define VDET_BASE_PTRS                           { ANALOG__VDET }
#endif

/* VFCCU - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral AON__FCCU base address */
  #define AON__FCCU_BASE                           (0x54570000u)
  /** Peripheral AON__FCCU base address */
  #define AON__FCCU_BASE_NS                        (0x44570000u)
  /** Peripheral AON__FCCU base pointer */
  #define AON__FCCU                                ((VFCCU_Type *)AON__FCCU_BASE)
  /** Peripheral AON__FCCU base pointer */
  #define AON__FCCU_NS                             ((VFCCU_Type *)AON__FCCU_BASE_NS)
  /** Array initializer of VFCCU peripheral base addresses */
  #define VFCCU_BASE_ADDRS                         { AON__FCCU_BASE }
  /** Array initializer of VFCCU peripheral base pointers */
  #define VFCCU_BASE_PTRS                          { AON__FCCU }
  /** Array initializer of VFCCU peripheral base addresses */
  #define VFCCU_BASE_ADDRS_NS                      { AON__FCCU_BASE_NS }
  /** Array initializer of VFCCU peripheral base pointers */
  #define VFCCU_BASE_PTRS_NS                       { AON__FCCU_NS }
#else
  /** Peripheral AON__FCCU base address */
  #define AON__FCCU_BASE                           (0x44570000u)
  /** Peripheral AON__FCCU base pointer */
  #define AON__FCCU                                ((VFCCU_Type *)AON__FCCU_BASE)
  /** Array initializer of VFCCU peripheral base addresses */
  #define VFCCU_BASE_ADDRS                         { AON__FCCU_BASE }
  /** Array initializer of VFCCU peripheral base pointers */
  #define VFCCU_BASE_PTRS                          { AON__FCCU }
#endif

/* VPU_BLK_CTRL_VPUMIX - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VPU__BLK_CTRL_VPUMIX base address */
  #define VPU__BLK_CTRL_VPUMIX_BASE                (0x5C410000u)
  /** Peripheral VPU__BLK_CTRL_VPUMIX base address */
  #define VPU__BLK_CTRL_VPUMIX_BASE_NS             (0x4C410000u)
  /** Peripheral VPU__BLK_CTRL_VPUMIX base pointer */
  #define VPU__BLK_CTRL_VPUMIX                     ((VPU_BLK_CTRL_VPUMIX_Type *)VPU__BLK_CTRL_VPUMIX_BASE)
  /** Peripheral VPU__BLK_CTRL_VPUMIX base pointer */
  #define VPU__BLK_CTRL_VPUMIX_NS                  ((VPU_BLK_CTRL_VPUMIX_Type *)VPU__BLK_CTRL_VPUMIX_BASE_NS)
  /** Array initializer of VPU_BLK_CTRL_VPUMIX peripheral base addresses */
  #define VPU_BLK_CTRL_VPUMIX_BASE_ADDRS           { VPU__BLK_CTRL_VPUMIX_BASE }
  /** Array initializer of VPU_BLK_CTRL_VPUMIX peripheral base pointers */
  #define VPU_BLK_CTRL_VPUMIX_BASE_PTRS            { VPU__BLK_CTRL_VPUMIX }
  /** Array initializer of VPU_BLK_CTRL_VPUMIX peripheral base addresses */
  #define VPU_BLK_CTRL_VPUMIX_BASE_ADDRS_NS        { VPU__BLK_CTRL_VPUMIX_BASE_NS }
  /** Array initializer of VPU_BLK_CTRL_VPUMIX peripheral base pointers */
  #define VPU_BLK_CTRL_VPUMIX_BASE_PTRS_NS         { VPU__BLK_CTRL_VPUMIX_NS }
#else
  /** Peripheral VPU__BLK_CTRL_VPUMIX base address */
  #define VPU__BLK_CTRL_VPUMIX_BASE                (0x4C410000u)
  /** Peripheral VPU__BLK_CTRL_VPUMIX base pointer */
  #define VPU__BLK_CTRL_VPUMIX                     ((VPU_BLK_CTRL_VPUMIX_Type *)VPU__BLK_CTRL_VPUMIX_BASE)
  /** Array initializer of VPU_BLK_CTRL_VPUMIX peripheral base addresses */
  #define VPU_BLK_CTRL_VPUMIX_BASE_ADDRS           { VPU__BLK_CTRL_VPUMIX_BASE }
  /** Array initializer of VPU_BLK_CTRL_VPUMIX peripheral base pointers */
  #define VPU_BLK_CTRL_VPUMIX_BASE_PTRS            { VPU__BLK_CTRL_VPUMIX }
#endif

/* VPU_JPEG_ENC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VPU__JPEG_ENC base address */
  #define VPU__JPEG_ENC_BASE                       (0x5C550100u)
  /** Peripheral VPU__JPEG_ENC base address */
  #define VPU__JPEG_ENC_BASE_NS                    (0x4C550100u)
  /** Peripheral VPU__JPEG_ENC base pointer */
  #define VPU__JPEG_ENC                            ((VPU_JPEG_ENC_Type *)VPU__JPEG_ENC_BASE)
  /** Peripheral VPU__JPEG_ENC base pointer */
  #define VPU__JPEG_ENC_NS                         ((VPU_JPEG_ENC_Type *)VPU__JPEG_ENC_BASE_NS)
  /** Array initializer of VPU_JPEG_ENC peripheral base addresses */
  #define VPU_JPEG_ENC_BASE_ADDRS                  { VPU__JPEG_ENC_BASE }
  /** Array initializer of VPU_JPEG_ENC peripheral base pointers */
  #define VPU_JPEG_ENC_BASE_PTRS                   { VPU__JPEG_ENC }
  /** Array initializer of VPU_JPEG_ENC peripheral base addresses */
  #define VPU_JPEG_ENC_BASE_ADDRS_NS               { VPU__JPEG_ENC_BASE_NS }
  /** Array initializer of VPU_JPEG_ENC peripheral base pointers */
  #define VPU_JPEG_ENC_BASE_PTRS_NS                { VPU__JPEG_ENC_NS }
#else
  /** Peripheral VPU__JPEG_ENC base address */
  #define VPU__JPEG_ENC_BASE                       (0x4C550100u)
  /** Peripheral VPU__JPEG_ENC base pointer */
  #define VPU__JPEG_ENC                            ((VPU_JPEG_ENC_Type *)VPU__JPEG_ENC_BASE)
  /** Array initializer of VPU_JPEG_ENC peripheral base addresses */
  #define VPU_JPEG_ENC_BASE_ADDRS                  { VPU__JPEG_ENC_BASE }
  /** Array initializer of VPU_JPEG_ENC peripheral base pointers */
  #define VPU_JPEG_ENC_BASE_PTRS                   { VPU__JPEG_ENC }
#endif

/* VPU_JPEG_ENC_WRAP - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VPU__JPEG_ENC_WRAP base address */
  #define VPU__JPEG_ENC_WRAP_BASE                  (0x5C550000u)
  /** Peripheral VPU__JPEG_ENC_WRAP base address */
  #define VPU__JPEG_ENC_WRAP_BASE_NS               (0x4C550000u)
  /** Peripheral VPU__JPEG_ENC_WRAP base pointer */
  #define VPU__JPEG_ENC_WRAP                       ((VPU_JPEG_ENC_WRAP_Type *)VPU__JPEG_ENC_WRAP_BASE)
  /** Peripheral VPU__JPEG_ENC_WRAP base pointer */
  #define VPU__JPEG_ENC_WRAP_NS                    ((VPU_JPEG_ENC_WRAP_Type *)VPU__JPEG_ENC_WRAP_BASE_NS)
  /** Array initializer of VPU_JPEG_ENC_WRAP peripheral base addresses */
  #define VPU_JPEG_ENC_WRAP_BASE_ADDRS             { VPU__JPEG_ENC_WRAP_BASE }
  /** Array initializer of VPU_JPEG_ENC_WRAP peripheral base pointers */
  #define VPU_JPEG_ENC_WRAP_BASE_PTRS              { VPU__JPEG_ENC_WRAP }
  /** Array initializer of VPU_JPEG_ENC_WRAP peripheral base addresses */
  #define VPU_JPEG_ENC_WRAP_BASE_ADDRS_NS          { VPU__JPEG_ENC_WRAP_BASE_NS }
  /** Array initializer of VPU_JPEG_ENC_WRAP peripheral base pointers */
  #define VPU_JPEG_ENC_WRAP_BASE_PTRS_NS           { VPU__JPEG_ENC_WRAP_NS }
#else
  /** Peripheral VPU__JPEG_ENC_WRAP base address */
  #define VPU__JPEG_ENC_WRAP_BASE                  (0x4C550000u)
  /** Peripheral VPU__JPEG_ENC_WRAP base pointer */
  #define VPU__JPEG_ENC_WRAP                       ((VPU_JPEG_ENC_WRAP_Type *)VPU__JPEG_ENC_WRAP_BASE)
  /** Array initializer of VPU_JPEG_ENC_WRAP peripheral base addresses */
  #define VPU_JPEG_ENC_WRAP_BASE_ADDRS             { VPU__JPEG_ENC_WRAP_BASE }
  /** Array initializer of VPU_JPEG_ENC_WRAP peripheral base pointers */
  #define VPU_JPEG_ENC_WRAP_BASE_PTRS              { VPU__JPEG_ENC_WRAP }
#endif

/* VPU_VPU_DEC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VPU__VPU_DEC base address */
  #define VPU__VPU_DEC_BASE                        (0x5C4B0000u)
  /** Peripheral VPU__VPU_DEC base address */
  #define VPU__VPU_DEC_BASE_NS                     (0x4C4B0000u)
  /** Peripheral VPU__VPU_DEC base pointer */
  #define VPU__VPU_DEC                             ((VPU_VPU_DEC_Type *)VPU__VPU_DEC_BASE)
  /** Peripheral VPU__VPU_DEC base pointer */
  #define VPU__VPU_DEC_NS                          ((VPU_VPU_DEC_Type *)VPU__VPU_DEC_BASE_NS)
  /** Array initializer of VPU_VPU_DEC peripheral base addresses */
  #define VPU_VPU_DEC_BASE_ADDRS                   { VPU__VPU_DEC_BASE }
  /** Array initializer of VPU_VPU_DEC peripheral base pointers */
  #define VPU_VPU_DEC_BASE_PTRS                    { VPU__VPU_DEC }
  /** Array initializer of VPU_VPU_DEC peripheral base addresses */
  #define VPU_VPU_DEC_BASE_ADDRS_NS                { VPU__VPU_DEC_BASE_NS }
  /** Array initializer of VPU_VPU_DEC peripheral base pointers */
  #define VPU_VPU_DEC_BASE_PTRS_NS                 { VPU__VPU_DEC_NS }
#else
  /** Peripheral VPU__VPU_DEC base address */
  #define VPU__VPU_DEC_BASE                        (0x4C4B0000u)
  /** Peripheral VPU__VPU_DEC base pointer */
  #define VPU__VPU_DEC                             ((VPU_VPU_DEC_Type *)VPU__VPU_DEC_BASE)
  /** Array initializer of VPU_VPU_DEC peripheral base addresses */
  #define VPU_VPU_DEC_BASE_ADDRS                   { VPU__VPU_DEC_BASE }
  /** Array initializer of VPU_VPU_DEC peripheral base pointers */
  #define VPU_VPU_DEC_BASE_PTRS                    { VPU__VPU_DEC }
#endif

/* VPU_VPU_ENC - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral VPU__VPU_ENC base address */
  #define VPU__VPU_ENC_BASE                        (0x5C460000u)
  /** Peripheral VPU__VPU_ENC base address */
  #define VPU__VPU_ENC_BASE_NS                     (0x4C460000u)
  /** Peripheral VPU__VPU_ENC base pointer */
  #define VPU__VPU_ENC                             ((VPU_VPU_ENC_Type *)VPU__VPU_ENC_BASE)
  /** Peripheral VPU__VPU_ENC base pointer */
  #define VPU__VPU_ENC_NS                          ((VPU_VPU_ENC_Type *)VPU__VPU_ENC_BASE_NS)
  /** Array initializer of VPU_VPU_ENC peripheral base addresses */
  #define VPU_VPU_ENC_BASE_ADDRS                   { VPU__VPU_ENC_BASE }
  /** Array initializer of VPU_VPU_ENC peripheral base pointers */
  #define VPU_VPU_ENC_BASE_PTRS                    { VPU__VPU_ENC }
  /** Array initializer of VPU_VPU_ENC peripheral base addresses */
  #define VPU_VPU_ENC_BASE_ADDRS_NS                { VPU__VPU_ENC_BASE_NS }
  /** Array initializer of VPU_VPU_ENC peripheral base pointers */
  #define VPU_VPU_ENC_BASE_PTRS_NS                 { VPU__VPU_ENC_NS }
#else
  /** Peripheral VPU__VPU_ENC base address */
  #define VPU__VPU_ENC_BASE                        (0x4C460000u)
  /** Peripheral VPU__VPU_ENC base pointer */
  #define VPU__VPU_ENC                             ((VPU_VPU_ENC_Type *)VPU__VPU_ENC_BASE)
  /** Array initializer of VPU_VPU_ENC peripheral base addresses */
  #define VPU_VPU_ENC_BASE_ADDRS                   { VPU__VPU_ENC_BASE }
  /** Array initializer of VPU_VPU_ENC peripheral base pointers */
  #define VPU_VPU_ENC_BASE_PTRS                    { VPU__VPU_ENC }
#endif

/* VS_MII_MMD - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE (0x5CEE0000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE_NS (0x4CEE0000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD ((VS_MII_MMD_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_NS ((VS_MII_MMD_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE_NS)
  /** Array initializer of VS_MII_MMD peripheral base addresses */
  #define VS_MII_MMD_BASE_ADDRS                    { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE }
  /** Array initializer of VS_MII_MMD peripheral base pointers */
  #define VS_MII_MMD_BASE_PTRS                     { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD }
  /** Array initializer of VS_MII_MMD peripheral base addresses */
  #define VS_MII_MMD_BASE_ADDRS_NS                 { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE_NS }
  /** Array initializer of VS_MII_MMD peripheral base pointers */
  #define VS_MII_MMD_BASE_PTRS_NS                  { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_NS }
#else
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE (0x4CEE0000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD ((VS_MII_MMD_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE)
  /** Array initializer of VS_MII_MMD peripheral base addresses */
  #define VS_MII_MMD_BASE_ADDRS                    { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD_BASE }
  /** Array initializer of VS_MII_MMD peripheral base pointers */
  #define VS_MII_MMD_BASE_PTRS                     { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MII_MMD }
#endif

/* VS_MMD1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE (0x5CEC0000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE_NS (0x4CEC0000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 ((VS_MMD1_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_NS ((VS_MMD1_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE_NS)
  /** Array initializer of VS_MMD1 peripheral base addresses */
  #define VS_MMD1_BASE_ADDRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE }
  /** Array initializer of VS_MMD1 peripheral base pointers */
  #define VS_MMD1_BASE_PTRS                        { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 }
  /** Array initializer of VS_MMD1 peripheral base addresses */
  #define VS_MMD1_BASE_ADDRS_NS                    { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE_NS }
  /** Array initializer of VS_MMD1 peripheral base pointers */
  #define VS_MMD1_BASE_PTRS_NS                     { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_NS }
#else
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 base address */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE (0x4CEC0000u)
  /** Peripheral HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 base pointer */
  #define HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 ((VS_MMD1_Type *)HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE)
  /** Array initializer of VS_MMD1 peripheral base addresses */
  #define VS_MMD1_BASE_ADDRS                       { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1_BASE }
  /** Array initializer of VS_MMD1 peripheral base pointers */
  #define VS_MMD1_BASE_PTRS                        { HSIO__PCIE_ENET1__PCIE_ENET_SERDES__VS_MMD1 }
#endif

/* WDOG - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE                               (0x542D0000u)
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE_NS                            (0x442D0000u)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1_NS                                 ((WDOG_Type *)WDOG1_BASE_NS)
  /** Peripheral WDOG2 base address */
  #define WDOG2_BASE                               (0x542E0000u)
  /** Peripheral WDOG2 base address */
  #define WDOG2_BASE_NS                            (0x442E0000u)
  /** Peripheral WDOG2 base pointer */
  #define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
  /** Peripheral WDOG2 base pointer */
  #define WDOG2_NS                                 ((WDOG_Type *)WDOG2_BASE_NS)
  /** Peripheral WDOG3 base address */
  #define WDOG3_BASE                               (0x520B0000u)
  /** Peripheral WDOG3 base address */
  #define WDOG3_BASE_NS                            (0x420B0000u)
  /** Peripheral WDOG3 base pointer */
  #define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
  /** Peripheral WDOG3 base pointer */
  #define WDOG3_NS                                 ((WDOG_Type *)WDOG3_BASE_NS)
  /** Peripheral WDOG4 base address */
  #define WDOG4_BASE                               (0x520C0000u)
  /** Peripheral WDOG4 base address */
  #define WDOG4_BASE_NS                            (0x420C0000u)
  /** Peripheral WDOG4 base pointer */
  #define WDOG4                                    ((WDOG_Type *)WDOG4_BASE)
  /** Peripheral WDOG4 base pointer */
  #define WDOG4_NS                                 ((WDOG_Type *)WDOG4_BASE_NS)
  /** Peripheral WDOG5 base address */
  #define WDOG5_BASE                               (0x520D0000u)
  /** Peripheral WDOG5 base address */
  #define WDOG5_BASE_NS                            (0x420D0000u)
  /** Peripheral WDOG5 base pointer */
  #define WDOG5                                    ((WDOG_Type *)WDOG5_BASE)
  /** Peripheral WDOG5 base pointer */
  #define WDOG5_NS                                 ((WDOG_Type *)WDOG5_BASE_NS)
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS                          { WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS                           { WDOG1, WDOG2, WDOG3, WDOG4, WDOG5 }
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS_NS                       { WDOG1_BASE_NS, WDOG2_BASE_NS, WDOG3_BASE_NS, WDOG4_BASE_NS, WDOG5_BASE_NS }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS_NS                        { WDOG1_NS, WDOG2_NS, WDOG3_NS, WDOG4_NS, WDOG5_NS }
#else
  /** Peripheral WDOG1 base address */
  #define WDOG1_BASE                               (0x442D0000u)
  /** Peripheral WDOG1 base pointer */
  #define WDOG1                                    ((WDOG_Type *)WDOG1_BASE)
  /** Peripheral WDOG2 base address */
  #define WDOG2_BASE                               (0x442E0000u)
  /** Peripheral WDOG2 base pointer */
  #define WDOG2                                    ((WDOG_Type *)WDOG2_BASE)
  /** Peripheral WDOG3 base address */
  #define WDOG3_BASE                               (0x420B0000u)
  /** Peripheral WDOG3 base pointer */
  #define WDOG3                                    ((WDOG_Type *)WDOG3_BASE)
  /** Peripheral WDOG4 base address */
  #define WDOG4_BASE                               (0x420C0000u)
  /** Peripheral WDOG4 base pointer */
  #define WDOG4                                    ((WDOG_Type *)WDOG4_BASE)
  /** Peripheral WDOG5 base address */
  #define WDOG5_BASE                               (0x420D0000u)
  /** Peripheral WDOG5 base pointer */
  #define WDOG5                                    ((WDOG_Type *)WDOG5_BASE)
  /** Array initializer of WDOG peripheral base addresses */
  #define WDOG_BASE_ADDRS                          { WDOG1_BASE, WDOG2_BASE, WDOG3_BASE, WDOG4_BASE, WDOG5_BASE }
  /** Array initializer of WDOG peripheral base pointers */
  #define WDOG_BASE_PTRS                           { WDOG1, WDOG2, WDOG3, WDOG4, WDOG5 }
#endif
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { WDOG1_IRQn, WDOG2_IRQn, WDOG3_IRQn, WDOG4_IRQn, WDOG5_IRQn }
/* Extra definition */
#define WDOG_UPDATE_KEY                          (0xD928C520U)
#define WDOG_REFRESH_KEY                         (0xB480A602U)


/* XCACHE - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral M33_CACHE_CTRLPC base address */
  #define M33_CACHE_CTRLPC_BASE                    (0x54400000u)
  /** Peripheral M33_CACHE_CTRLPC base address */
  #define M33_CACHE_CTRLPC_BASE_NS                 (0x44400000u)
  /** Peripheral M33_CACHE_CTRLPC base pointer */
  #define M33_CACHE_CTRLPC                         ((XCACHE_Type *)M33_CACHE_CTRLPC_BASE)
  /** Peripheral M33_CACHE_CTRLPC base pointer */
  #define M33_CACHE_CTRLPC_NS                      ((XCACHE_Type *)M33_CACHE_CTRLPC_BASE_NS)
  /** Peripheral M33_CACHE_CTRLPS base address */
  #define M33_CACHE_CTRLPS_BASE                    (0x54400800u)
  /** Peripheral M33_CACHE_CTRLPS base address */
  #define M33_CACHE_CTRLPS_BASE_NS                 (0x44400800u)
  /** Peripheral M33_CACHE_CTRLPS base pointer */
  #define M33_CACHE_CTRLPS                         ((XCACHE_Type *)M33_CACHE_CTRLPS_BASE)
  /** Peripheral M33_CACHE_CTRLPS base pointer */
  #define M33_CACHE_CTRLPS_NS                      ((XCACHE_Type *)M33_CACHE_CTRLPS_BASE_NS)
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS                        { M33_CACHE_CTRLPC_BASE, M33_CACHE_CTRLPS_BASE }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS                         { M33_CACHE_CTRLPC, M33_CACHE_CTRLPS }
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS_NS                     { M33_CACHE_CTRLPC_BASE_NS, M33_CACHE_CTRLPS_BASE_NS }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS_NS                      { M33_CACHE_CTRLPC_NS, M33_CACHE_CTRLPS_NS }
#else
  /** Peripheral M33_CACHE_CTRLPC base address */
  #define M33_CACHE_CTRLPC_BASE                    (0x44400000u)
  /** Peripheral M33_CACHE_CTRLPC base pointer */
  #define M33_CACHE_CTRLPC                         ((XCACHE_Type *)M33_CACHE_CTRLPC_BASE)
  /** Peripheral M33_CACHE_CTRLPS base address */
  #define M33_CACHE_CTRLPS_BASE                    (0x44400800u)
  /** Peripheral M33_CACHE_CTRLPS base pointer */
  #define M33_CACHE_CTRLPS                         ((XCACHE_Type *)M33_CACHE_CTRLPS_BASE)
  /** Array initializer of XCACHE peripheral base addresses */
  #define XCACHE_BASE_ADDRS                        { M33_CACHE_CTRLPC_BASE, M33_CACHE_CTRLPS_BASE }
  /** Array initializer of XCACHE peripheral base pointers */
  #define XCACHE_BASE_PTRS                         { M33_CACHE_CTRLPC, M33_CACHE_CTRLPS }
#endif
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** XCACHE physical memory base address */
  #define XCACHE_PHYMEM_BASES                { 0x1FFC0000u, 0x38000000u }
  /** XCACHE physical memory size */
  #define XCACHE_PHYMEM_SIZES                { 0x00040000u, 0x08000000u }
  /** XCACHE physical memory base address */
  #define XCACHE_PHYMEM_BASES_NS             { 0x0FFC0000u, 0x28000000u }
  /** XCACHE physical memory size */
  #define XCACHE_PHYMEM_SIZES_NS             { 0x00040000u, 0x08000000u }
#else
  /** XCACHE physical memory base address */
  #define XCACHE_PHYMEM_BASES                { 0x0FFC0000u, 0x28000000u }
  /** XCACHE physical memory size */
  #define XCACHE_PHYMEM_SIZES                { 0x00040000u, 0x08000000u }
#endif


/* XSPI - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral XSPI1 base address */
  #define XSPI1_BASE                               (0x52400000u)
  /** Peripheral XSPI1 base address */
  #define XSPI1_BASE_NS                            (0x42400000u)
  /** Peripheral XSPI1 base pointer */
  #define XSPI1                                    ((XSPI_Type *)XSPI1_BASE)
  /** Peripheral XSPI1 base pointer */
  #define XSPI1_NS                                 ((XSPI_Type *)XSPI1_BASE_NS)
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS                          { 0u, XSPI1_BASE }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS                           { (XSPI_Type *)0u, XSPI1 }
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS_NS                       { 0u, XSPI1_BASE_NS }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS_NS                        { (XSPI_Type *)0u, XSPI1_NS }
#else
  /** Peripheral XSPI1 base address */
  #define XSPI1_BASE                               (0x42400000u)
  /** Peripheral XSPI1 base pointer */
  #define XSPI1                                    ((XSPI_Type *)XSPI1_BASE)
  /** Array initializer of XSPI peripheral base addresses */
  #define XSPI_BASE_ADDRS                          { 0u, XSPI1_BASE }
  /** Array initializer of XSPI peripheral base pointers */
  #define XSPI_BASE_PTRS                           { (XSPI_Type *)0u, XSPI1 }
#endif
/** Interrupt vectors for the XSPI peripheral type */
#define XSPI_IRQS                                { { NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn, NotAvail_IRQn }, { XSPI1_0_IRQn, XSPI1_1_IRQn, XSPI1_2_IRQn, XSPI1_3_IRQn, XSPI1_4_IRQn } }
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /* XSPI AMBA address. */
  #define XSPI1_AMBA_BASE      (0x38000000u)
  #define XSPI1_AMBA_BASE_NS   (0x28000000u)
  #define XSPI_AMBA_BASES      {0x00000000u, 0x38000000u}
  #define XSPI_AMBA_BASES_NS   {0x00000000u, 0x28000000u}
#else
  /* XSPI AMBA address. */
  #define XSPI1_AMBA_BASE      (0x28000000u)
  #define XSPI_AMBA_BASES      {0x00000000u, 0x28000000u}
#endif


/* blitb9cf - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__BLITB9CF base address */
  #define DISPLAY__SEERIS__BLITB9CF_BASE           (0x5B471000u)
  /** Peripheral DISPLAY__SEERIS__BLITB9CF base address */
  #define DISPLAY__SEERIS__BLITB9CF_BASE_NS        (0x4B471000u)
  /** Peripheral DISPLAY__SEERIS__BLITB9CF base pointer */
  #define DISPLAY__SEERIS__BLITB9CF                ((blitb9cf_Type *)DISPLAY__SEERIS__BLITB9CF_BASE)
  /** Peripheral DISPLAY__SEERIS__BLITB9CF base pointer */
  #define DISPLAY__SEERIS__BLITB9CF_NS             ((blitb9cf_Type *)DISPLAY__SEERIS__BLITB9CF_BASE_NS)
  /** Array initializer of blitb9cf peripheral base addresses */
  #define blitb9cf_BASE_ADDRS                      { DISPLAY__SEERIS__BLITB9CF_BASE }
  /** Array initializer of blitb9cf peripheral base pointers */
  #define blitb9cf_BASE_PTRS                       { DISPLAY__SEERIS__BLITB9CF }
  /** Array initializer of blitb9cf peripheral base addresses */
  #define blitb9cf_BASE_ADDRS_NS                   { DISPLAY__SEERIS__BLITB9CF_BASE_NS }
  /** Array initializer of blitb9cf peripheral base pointers */
  #define blitb9cf_BASE_PTRS_NS                    { DISPLAY__SEERIS__BLITB9CF_NS }
#else
  /** Peripheral DISPLAY__SEERIS__BLITB9CF base address */
  #define DISPLAY__SEERIS__BLITB9CF_BASE           (0x4B471000u)
  /** Peripheral DISPLAY__SEERIS__BLITB9CF base pointer */
  #define DISPLAY__SEERIS__BLITB9CF                ((blitb9cf_Type *)DISPLAY__SEERIS__BLITB9CF_BASE)
  /** Array initializer of blitb9cf peripheral base addresses */
  #define blitb9cf_BASE_ADDRS                      { DISPLAY__SEERIS__BLITB9CF_BASE }
  /** Array initializer of blitb9cf peripheral base pointers */
  #define blitb9cf_BASE_PTRS                       { DISPLAY__SEERIS__BLITB9CF }
#endif

/* blitbld - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__BLITBLD base address */
  #define DISPLAY__SEERIS__BLITBLD_BASE            (0x5B470000u)
  /** Peripheral DISPLAY__SEERIS__BLITBLD base address */
  #define DISPLAY__SEERIS__BLITBLD_BASE_NS         (0x4B470000u)
  /** Peripheral DISPLAY__SEERIS__BLITBLD base pointer */
  #define DISPLAY__SEERIS__BLITBLD                 ((blitbld_Type *)DISPLAY__SEERIS__BLITBLD_BASE)
  /** Peripheral DISPLAY__SEERIS__BLITBLD base pointer */
  #define DISPLAY__SEERIS__BLITBLD_NS              ((blitbld_Type *)DISPLAY__SEERIS__BLITBLD_BASE_NS)
  /** Array initializer of blitbld peripheral base addresses */
  #define blitbld_BASE_ADDRS                       { DISPLAY__SEERIS__BLITBLD_BASE }
  /** Array initializer of blitbld peripheral base pointers */
  #define blitbld_BASE_PTRS                        { DISPLAY__SEERIS__BLITBLD }
  /** Array initializer of blitbld peripheral base addresses */
  #define blitbld_BASE_ADDRS_NS                    { DISPLAY__SEERIS__BLITBLD_BASE_NS }
  /** Array initializer of blitbld peripheral base pointers */
  #define blitbld_BASE_PTRS_NS                     { DISPLAY__SEERIS__BLITBLD_NS }
#else
  /** Peripheral DISPLAY__SEERIS__BLITBLD base address */
  #define DISPLAY__SEERIS__BLITBLD_BASE            (0x4B470000u)
  /** Peripheral DISPLAY__SEERIS__BLITBLD base pointer */
  #define DISPLAY__SEERIS__BLITBLD                 ((blitbld_Type *)DISPLAY__SEERIS__BLITBLD_BASE)
  /** Array initializer of blitbld peripheral base addresses */
  #define blitbld_BASE_ADDRS                       { DISPLAY__SEERIS__BLITBLD_BASE }
  /** Array initializer of blitbld peripheral base pointers */
  #define blitbld_BASE_PTRS                        { DISPLAY__SEERIS__BLITBLD }
#endif

/* clut - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CLUT base address */
  #define DISPLAY__SEERIS__CLUT_BASE               (0x5B450000u)
  /** Peripheral DISPLAY__SEERIS__CLUT base address */
  #define DISPLAY__SEERIS__CLUT_BASE_NS            (0x4B450000u)
  /** Peripheral DISPLAY__SEERIS__CLUT base pointer */
  #define DISPLAY__SEERIS__CLUT                    ((clut_Type *)DISPLAY__SEERIS__CLUT_BASE)
  /** Peripheral DISPLAY__SEERIS__CLUT base pointer */
  #define DISPLAY__SEERIS__CLUT_NS                 ((clut_Type *)DISPLAY__SEERIS__CLUT_BASE_NS)
  /** Array initializer of clut peripheral base addresses */
  #define clut_BASE_ADDRS                          { DISPLAY__SEERIS__CLUT_BASE }
  /** Array initializer of clut peripheral base pointers */
  #define clut_BASE_PTRS                           { DISPLAY__SEERIS__CLUT }
  /** Array initializer of clut peripheral base addresses */
  #define clut_BASE_ADDRS_NS                       { DISPLAY__SEERIS__CLUT_BASE_NS }
  /** Array initializer of clut peripheral base pointers */
  #define clut_BASE_PTRS_NS                        { DISPLAY__SEERIS__CLUT_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CLUT base address */
  #define DISPLAY__SEERIS__CLUT_BASE               (0x4B450000u)
  /** Peripheral DISPLAY__SEERIS__CLUT base pointer */
  #define DISPLAY__SEERIS__CLUT                    ((clut_Type *)DISPLAY__SEERIS__CLUT_BASE)
  /** Array initializer of clut peripheral base addresses */
  #define clut_BASE_ADDRS                          { DISPLAY__SEERIS__CLUT_BASE }
  /** Array initializer of clut peripheral base pointers */
  #define clut_BASE_PTRS                           { DISPLAY__SEERIS__CLUT }
#endif

/* clut1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CLUT1 base address */
  #define DISPLAY__SEERIS__CLUT1_BASE              (0x5B450400u)
  /** Peripheral DISPLAY__SEERIS__CLUT1 base address */
  #define DISPLAY__SEERIS__CLUT1_BASE_NS           (0x4B450400u)
  /** Peripheral DISPLAY__SEERIS__CLUT1 base pointer */
  #define DISPLAY__SEERIS__CLUT1                   ((clut1_Type *)DISPLAY__SEERIS__CLUT1_BASE)
  /** Peripheral DISPLAY__SEERIS__CLUT1 base pointer */
  #define DISPLAY__SEERIS__CLUT1_NS                ((clut1_Type *)DISPLAY__SEERIS__CLUT1_BASE_NS)
  /** Array initializer of clut1 peripheral base addresses */
  #define clut1_BASE_ADDRS                         { DISPLAY__SEERIS__CLUT1_BASE }
  /** Array initializer of clut1 peripheral base pointers */
  #define clut1_BASE_PTRS                          { DISPLAY__SEERIS__CLUT1 }
  /** Array initializer of clut1 peripheral base addresses */
  #define clut1_BASE_ADDRS_NS                      { DISPLAY__SEERIS__CLUT1_BASE_NS }
  /** Array initializer of clut1 peripheral base pointers */
  #define clut1_BASE_PTRS_NS                       { DISPLAY__SEERIS__CLUT1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CLUT1 base address */
  #define DISPLAY__SEERIS__CLUT1_BASE              (0x4B450400u)
  /** Peripheral DISPLAY__SEERIS__CLUT1 base pointer */
  #define DISPLAY__SEERIS__CLUT1                   ((clut1_Type *)DISPLAY__SEERIS__CLUT1_BASE)
  /** Array initializer of clut1 peripheral base addresses */
  #define clut1_BASE_ADDRS                         { DISPLAY__SEERIS__CLUT1_BASE }
  /** Array initializer of clut1 peripheral base pointers */
  #define clut1_BASE_PTRS                          { DISPLAY__SEERIS__CLUT1 }
#endif

/* clut9cfg - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CLUT9CFG base address */
  #define DISPLAY__SEERIS__CLUT9CFG_BASE           (0x5B451000u)
  /** Peripheral DISPLAY__SEERIS__CLUT9CFG base address */
  #define DISPLAY__SEERIS__CLUT9CFG_BASE_NS        (0x4B451000u)
  /** Peripheral DISPLAY__SEERIS__CLUT9CFG base pointer */
  #define DISPLAY__SEERIS__CLUT9CFG                ((clut9cfg_Type *)DISPLAY__SEERIS__CLUT9CFG_BASE)
  /** Peripheral DISPLAY__SEERIS__CLUT9CFG base pointer */
  #define DISPLAY__SEERIS__CLUT9CFG_NS             ((clut9cfg_Type *)DISPLAY__SEERIS__CLUT9CFG_BASE_NS)
  /** Array initializer of clut9cfg peripheral base addresses */
  #define clut9cfg_BASE_ADDRS                      { DISPLAY__SEERIS__CLUT9CFG_BASE }
  /** Array initializer of clut9cfg peripheral base pointers */
  #define clut9cfg_BASE_PTRS                       { DISPLAY__SEERIS__CLUT9CFG }
  /** Array initializer of clut9cfg peripheral base addresses */
  #define clut9cfg_BASE_ADDRS_NS                   { DISPLAY__SEERIS__CLUT9CFG_BASE_NS }
  /** Array initializer of clut9cfg peripheral base pointers */
  #define clut9cfg_BASE_PTRS_NS                    { DISPLAY__SEERIS__CLUT9CFG_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CLUT9CFG base address */
  #define DISPLAY__SEERIS__CLUT9CFG_BASE           (0x4B451000u)
  /** Peripheral DISPLAY__SEERIS__CLUT9CFG base pointer */
  #define DISPLAY__SEERIS__CLUT9CFG                ((clut9cfg_Type *)DISPLAY__SEERIS__CLUT9CFG_BASE)
  /** Array initializer of clut9cfg peripheral base addresses */
  #define clut9cfg_BASE_ADDRS                      { DISPLAY__SEERIS__CLUT9CFG_BASE }
  /** Array initializer of clut9cfg peripheral base pointers */
  #define clut9cfg_BASE_PTRS                       { DISPLAY__SEERIS__CLUT9CFG }
#endif

/* cmdseq - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CMDSEQ base address */
  #define DISPLAY__SEERIS__CMDSEQ_BASE             (0x5B410000u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ base address */
  #define DISPLAY__SEERIS__CMDSEQ_BASE_NS          (0x4B410000u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ base pointer */
  #define DISPLAY__SEERIS__CMDSEQ                  ((cmdseq_Type *)DISPLAY__SEERIS__CMDSEQ_BASE)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ base pointer */
  #define DISPLAY__SEERIS__CMDSEQ_NS               ((cmdseq_Type *)DISPLAY__SEERIS__CMDSEQ_BASE_NS)
  /** Array initializer of cmdseq peripheral base addresses */
  #define cmdseq_BASE_ADDRS                        { DISPLAY__SEERIS__CMDSEQ_BASE }
  /** Array initializer of cmdseq peripheral base pointers */
  #define cmdseq_BASE_PTRS                         { DISPLAY__SEERIS__CMDSEQ }
  /** Array initializer of cmdseq peripheral base addresses */
  #define cmdseq_BASE_ADDRS_NS                     { DISPLAY__SEERIS__CMDSEQ_BASE_NS }
  /** Array initializer of cmdseq peripheral base pointers */
  #define cmdseq_BASE_PTRS_NS                      { DISPLAY__SEERIS__CMDSEQ_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CMDSEQ base address */
  #define DISPLAY__SEERIS__CMDSEQ_BASE             (0x4B410000u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ base pointer */
  #define DISPLAY__SEERIS__CMDSEQ                  ((cmdseq_Type *)DISPLAY__SEERIS__CMDSEQ_BASE)
  /** Array initializer of cmdseq peripheral base addresses */
  #define cmdseq_BASE_ADDRS                        { DISPLAY__SEERIS__CMDSEQ_BASE }
  /** Array initializer of cmdseq peripheral base pointers */
  #define cmdseq_BASE_PTRS                         { DISPLAY__SEERIS__CMDSEQ }
#endif

/* cmdseq1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CMDSEQ1 base address */
  #define DISPLAY__SEERIS__CMDSEQ1_BASE            (0x5B410100u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ1 base address */
  #define DISPLAY__SEERIS__CMDSEQ1_BASE_NS         (0x4B410100u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ1 base pointer */
  #define DISPLAY__SEERIS__CMDSEQ1                 ((cmdseq1_Type *)DISPLAY__SEERIS__CMDSEQ1_BASE)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ1 base pointer */
  #define DISPLAY__SEERIS__CMDSEQ1_NS              ((cmdseq1_Type *)DISPLAY__SEERIS__CMDSEQ1_BASE_NS)
  /** Array initializer of cmdseq1 peripheral base addresses */
  #define cmdseq1_BASE_ADDRS                       { DISPLAY__SEERIS__CMDSEQ1_BASE }
  /** Array initializer of cmdseq1 peripheral base pointers */
  #define cmdseq1_BASE_PTRS                        { DISPLAY__SEERIS__CMDSEQ1 }
  /** Array initializer of cmdseq1 peripheral base addresses */
  #define cmdseq1_BASE_ADDRS_NS                    { DISPLAY__SEERIS__CMDSEQ1_BASE_NS }
  /** Array initializer of cmdseq1 peripheral base pointers */
  #define cmdseq1_BASE_PTRS_NS                     { DISPLAY__SEERIS__CMDSEQ1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CMDSEQ1 base address */
  #define DISPLAY__SEERIS__CMDSEQ1_BASE            (0x4B410100u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ1 base pointer */
  #define DISPLAY__SEERIS__CMDSEQ1                 ((cmdseq1_Type *)DISPLAY__SEERIS__CMDSEQ1_BASE)
  /** Array initializer of cmdseq1 peripheral base addresses */
  #define cmdseq1_BASE_ADDRS                       { DISPLAY__SEERIS__CMDSEQ1_BASE }
  /** Array initializer of cmdseq1 peripheral base pointers */
  #define cmdseq1_BASE_PTRS                        { DISPLAY__SEERIS__CMDSEQ1 }
#endif

/* cmdseq2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CMDSEQ2 base address */
  #define DISPLAY__SEERIS__CMDSEQ2_BASE            (0x5B410180u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ2 base address */
  #define DISPLAY__SEERIS__CMDSEQ2_BASE_NS         (0x4B410180u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ2 base pointer */
  #define DISPLAY__SEERIS__CMDSEQ2                 ((cmdseq2_Type *)DISPLAY__SEERIS__CMDSEQ2_BASE)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ2 base pointer */
  #define DISPLAY__SEERIS__CMDSEQ2_NS              ((cmdseq2_Type *)DISPLAY__SEERIS__CMDSEQ2_BASE_NS)
  /** Array initializer of cmdseq2 peripheral base addresses */
  #define cmdseq2_BASE_ADDRS                       { DISPLAY__SEERIS__CMDSEQ2_BASE }
  /** Array initializer of cmdseq2 peripheral base pointers */
  #define cmdseq2_BASE_PTRS                        { DISPLAY__SEERIS__CMDSEQ2 }
  /** Array initializer of cmdseq2 peripheral base addresses */
  #define cmdseq2_BASE_ADDRS_NS                    { DISPLAY__SEERIS__CMDSEQ2_BASE_NS }
  /** Array initializer of cmdseq2 peripheral base pointers */
  #define cmdseq2_BASE_PTRS_NS                     { DISPLAY__SEERIS__CMDSEQ2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CMDSEQ2 base address */
  #define DISPLAY__SEERIS__CMDSEQ2_BASE            (0x4B410180u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQ2 base pointer */
  #define DISPLAY__SEERIS__CMDSEQ2                 ((cmdseq2_Type *)DISPLAY__SEERIS__CMDSEQ2_BASE)
  /** Array initializer of cmdseq2 peripheral base addresses */
  #define cmdseq2_BASE_ADDRS                       { DISPLAY__SEERIS__CMDSEQ2_BASE }
  /** Array initializer of cmdseq2 peripheral base pointers */
  #define cmdseq2_BASE_PTRS                        { DISPLAY__SEERIS__CMDSEQ2 }
#endif

/* cmdseqir - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CMDSEQIR base address */
  #define DISPLAY__SEERIS__CMDSEQIR_BASE           (0x5B411000u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQIR base address */
  #define DISPLAY__SEERIS__CMDSEQIR_BASE_NS        (0x4B411000u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQIR base pointer */
  #define DISPLAY__SEERIS__CMDSEQIR                ((cmdseqir_Type *)DISPLAY__SEERIS__CMDSEQIR_BASE)
  /** Peripheral DISPLAY__SEERIS__CMDSEQIR base pointer */
  #define DISPLAY__SEERIS__CMDSEQIR_NS             ((cmdseqir_Type *)DISPLAY__SEERIS__CMDSEQIR_BASE_NS)
  /** Array initializer of cmdseqir peripheral base addresses */
  #define cmdseqir_BASE_ADDRS                      { DISPLAY__SEERIS__CMDSEQIR_BASE }
  /** Array initializer of cmdseqir peripheral base pointers */
  #define cmdseqir_BASE_PTRS                       { DISPLAY__SEERIS__CMDSEQIR }
  /** Array initializer of cmdseqir peripheral base addresses */
  #define cmdseqir_BASE_ADDRS_NS                   { DISPLAY__SEERIS__CMDSEQIR_BASE_NS }
  /** Array initializer of cmdseqir peripheral base pointers */
  #define cmdseqir_BASE_PTRS_NS                    { DISPLAY__SEERIS__CMDSEQIR_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CMDSEQIR base address */
  #define DISPLAY__SEERIS__CMDSEQIR_BASE           (0x4B411000u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQIR base pointer */
  #define DISPLAY__SEERIS__CMDSEQIR                ((cmdseqir_Type *)DISPLAY__SEERIS__CMDSEQIR_BASE)
  /** Array initializer of cmdseqir peripheral base addresses */
  #define cmdseqir_BASE_ADDRS                      { DISPLAY__SEERIS__CMDSEQIR_BASE }
  /** Array initializer of cmdseqir peripheral base pointers */
  #define cmdseqir_BASE_PTRS                       { DISPLAY__SEERIS__CMDSEQIR }
#endif

/* cmdseqma - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CMDSEQMA base address */
  #define DISPLAY__SEERIS__CMDSEQMA_BASE           (0x5B403000u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQMA base address */
  #define DISPLAY__SEERIS__CMDSEQMA_BASE_NS        (0x4B403000u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQMA base pointer */
  #define DISPLAY__SEERIS__CMDSEQMA                ((cmdseqma_Type *)DISPLAY__SEERIS__CMDSEQMA_BASE)
  /** Peripheral DISPLAY__SEERIS__CMDSEQMA base pointer */
  #define DISPLAY__SEERIS__CMDSEQMA_NS             ((cmdseqma_Type *)DISPLAY__SEERIS__CMDSEQMA_BASE_NS)
  /** Array initializer of cmdseqma peripheral base addresses */
  #define cmdseqma_BASE_ADDRS                      { DISPLAY__SEERIS__CMDSEQMA_BASE }
  /** Array initializer of cmdseqma peripheral base pointers */
  #define cmdseqma_BASE_PTRS                       { DISPLAY__SEERIS__CMDSEQMA }
  /** Array initializer of cmdseqma peripheral base addresses */
  #define cmdseqma_BASE_ADDRS_NS                   { DISPLAY__SEERIS__CMDSEQMA_BASE_NS }
  /** Array initializer of cmdseqma peripheral base pointers */
  #define cmdseqma_BASE_PTRS_NS                    { DISPLAY__SEERIS__CMDSEQMA_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CMDSEQMA base address */
  #define DISPLAY__SEERIS__CMDSEQMA_BASE           (0x4B403000u)
  /** Peripheral DISPLAY__SEERIS__CMDSEQMA base pointer */
  #define DISPLAY__SEERIS__CMDSEQMA                ((cmdseqma_Type *)DISPLAY__SEERIS__CMDSEQMA_BASE)
  /** Array initializer of cmdseqma peripheral base addresses */
  #define cmdseqma_BASE_ADDRS                      { DISPLAY__SEERIS__CMDSEQMA_BASE }
  /** Array initializer of cmdseqma peripheral base pointers */
  #define cmdseqma_BASE_PTRS                       { DISPLAY__SEERIS__CMDSEQMA }
#endif

/* constf0c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CONSTF0C base address */
  #define DISPLAY__SEERIS__CONSTF0C_BASE           (0x5B4F1000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF0C base address */
  #define DISPLAY__SEERIS__CONSTF0C_BASE_NS        (0x4B4F1000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF0C base pointer */
  #define DISPLAY__SEERIS__CONSTF0C                ((constf0c_Type *)DISPLAY__SEERIS__CONSTF0C_BASE)
  /** Peripheral DISPLAY__SEERIS__CONSTF0C base pointer */
  #define DISPLAY__SEERIS__CONSTF0C_NS             ((constf0c_Type *)DISPLAY__SEERIS__CONSTF0C_BASE_NS)
  /** Array initializer of constf0c peripheral base addresses */
  #define constf0c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF0C_BASE }
  /** Array initializer of constf0c peripheral base pointers */
  #define constf0c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF0C }
  /** Array initializer of constf0c peripheral base addresses */
  #define constf0c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__CONSTF0C_BASE_NS }
  /** Array initializer of constf0c peripheral base pointers */
  #define constf0c_BASE_PTRS_NS                    { DISPLAY__SEERIS__CONSTF0C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CONSTF0C base address */
  #define DISPLAY__SEERIS__CONSTF0C_BASE           (0x4B4F1000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF0C base pointer */
  #define DISPLAY__SEERIS__CONSTF0C                ((constf0c_Type *)DISPLAY__SEERIS__CONSTF0C_BASE)
  /** Array initializer of constf0c peripheral base addresses */
  #define constf0c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF0C_BASE }
  /** Array initializer of constf0c peripheral base pointers */
  #define constf0c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF0C }
#endif

/* constf1c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CONSTF1C base address */
  #define DISPLAY__SEERIS__CONSTF1C_BASE           (0x5B531000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF1C base address */
  #define DISPLAY__SEERIS__CONSTF1C_BASE_NS        (0x4B531000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF1C base pointer */
  #define DISPLAY__SEERIS__CONSTF1C                ((constf1c_Type *)DISPLAY__SEERIS__CONSTF1C_BASE)
  /** Peripheral DISPLAY__SEERIS__CONSTF1C base pointer */
  #define DISPLAY__SEERIS__CONSTF1C_NS             ((constf1c_Type *)DISPLAY__SEERIS__CONSTF1C_BASE_NS)
  /** Array initializer of constf1c peripheral base addresses */
  #define constf1c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF1C_BASE }
  /** Array initializer of constf1c peripheral base pointers */
  #define constf1c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF1C }
  /** Array initializer of constf1c peripheral base addresses */
  #define constf1c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__CONSTF1C_BASE_NS }
  /** Array initializer of constf1c peripheral base pointers */
  #define constf1c_BASE_PTRS_NS                    { DISPLAY__SEERIS__CONSTF1C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CONSTF1C base address */
  #define DISPLAY__SEERIS__CONSTF1C_BASE           (0x4B531000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF1C base pointer */
  #define DISPLAY__SEERIS__CONSTF1C                ((constf1c_Type *)DISPLAY__SEERIS__CONSTF1C_BASE)
  /** Array initializer of constf1c peripheral base addresses */
  #define constf1c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF1C_BASE }
  /** Array initializer of constf1c peripheral base pointers */
  #define constf1c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF1C }
#endif

/* constf4c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CONSTF4C base address */
  #define DISPLAY__SEERIS__CONSTF4C_BASE           (0x5B501000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF4C base address */
  #define DISPLAY__SEERIS__CONSTF4C_BASE_NS        (0x4B501000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF4C base pointer */
  #define DISPLAY__SEERIS__CONSTF4C                ((constf4c_Type *)DISPLAY__SEERIS__CONSTF4C_BASE)
  /** Peripheral DISPLAY__SEERIS__CONSTF4C base pointer */
  #define DISPLAY__SEERIS__CONSTF4C_NS             ((constf4c_Type *)DISPLAY__SEERIS__CONSTF4C_BASE_NS)
  /** Array initializer of constf4c peripheral base addresses */
  #define constf4c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF4C_BASE }
  /** Array initializer of constf4c peripheral base pointers */
  #define constf4c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF4C }
  /** Array initializer of constf4c peripheral base addresses */
  #define constf4c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__CONSTF4C_BASE_NS }
  /** Array initializer of constf4c peripheral base pointers */
  #define constf4c_BASE_PTRS_NS                    { DISPLAY__SEERIS__CONSTF4C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CONSTF4C base address */
  #define DISPLAY__SEERIS__CONSTF4C_BASE           (0x4B501000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF4C base pointer */
  #define DISPLAY__SEERIS__CONSTF4C                ((constf4c_Type *)DISPLAY__SEERIS__CONSTF4C_BASE)
  /** Array initializer of constf4c peripheral base addresses */
  #define constf4c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF4C_BASE }
  /** Array initializer of constf4c peripheral base pointers */
  #define constf4c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF4C }
#endif

/* constf5c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__CONSTF5C base address */
  #define DISPLAY__SEERIS__CONSTF5C_BASE           (0x5B541000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF5C base address */
  #define DISPLAY__SEERIS__CONSTF5C_BASE_NS        (0x4B541000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF5C base pointer */
  #define DISPLAY__SEERIS__CONSTF5C                ((constf5c_Type *)DISPLAY__SEERIS__CONSTF5C_BASE)
  /** Peripheral DISPLAY__SEERIS__CONSTF5C base pointer */
  #define DISPLAY__SEERIS__CONSTF5C_NS             ((constf5c_Type *)DISPLAY__SEERIS__CONSTF5C_BASE_NS)
  /** Array initializer of constf5c peripheral base addresses */
  #define constf5c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF5C_BASE }
  /** Array initializer of constf5c peripheral base pointers */
  #define constf5c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF5C }
  /** Array initializer of constf5c peripheral base addresses */
  #define constf5c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__CONSTF5C_BASE_NS }
  /** Array initializer of constf5c peripheral base pointers */
  #define constf5c_BASE_PTRS_NS                    { DISPLAY__SEERIS__CONSTF5C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__CONSTF5C base address */
  #define DISPLAY__SEERIS__CONSTF5C_BASE           (0x4B541000u)
  /** Peripheral DISPLAY__SEERIS__CONSTF5C base pointer */
  #define DISPLAY__SEERIS__CONSTF5C                ((constf5c_Type *)DISPLAY__SEERIS__CONSTF5C_BASE)
  /** Array initializer of constf5c peripheral base addresses */
  #define constf5c_BASE_ADDRS                      { DISPLAY__SEERIS__CONSTF5C_BASE }
  /** Array initializer of constf5c peripheral base pointers */
  #define constf5c_BASE_PTRS                       { DISPLAY__SEERIS__CONSTF5C }
#endif

/* displa0c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__DISPLA0C base address */
  #define DISPLAY__SEERIS__DISPLA0C_BASE           (0x5B6F1000u)
  /** Peripheral DISPLAY__SEERIS__DISPLA0C base address */
  #define DISPLAY__SEERIS__DISPLA0C_BASE_NS        (0x4B6F1000u)
  /** Peripheral DISPLAY__SEERIS__DISPLA0C base pointer */
  #define DISPLAY__SEERIS__DISPLA0C                ((displa0c_Type *)DISPLAY__SEERIS__DISPLA0C_BASE)
  /** Peripheral DISPLAY__SEERIS__DISPLA0C base pointer */
  #define DISPLAY__SEERIS__DISPLA0C_NS             ((displa0c_Type *)DISPLAY__SEERIS__DISPLA0C_BASE_NS)
  /** Array initializer of displa0c peripheral base addresses */
  #define displa0c_BASE_ADDRS                      { DISPLAY__SEERIS__DISPLA0C_BASE }
  /** Array initializer of displa0c peripheral base pointers */
  #define displa0c_BASE_PTRS                       { DISPLAY__SEERIS__DISPLA0C }
  /** Array initializer of displa0c peripheral base addresses */
  #define displa0c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__DISPLA0C_BASE_NS }
  /** Array initializer of displa0c peripheral base pointers */
  #define displa0c_BASE_PTRS_NS                    { DISPLAY__SEERIS__DISPLA0C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__DISPLA0C base address */
  #define DISPLAY__SEERIS__DISPLA0C_BASE           (0x4B6F1000u)
  /** Peripheral DISPLAY__SEERIS__DISPLA0C base pointer */
  #define DISPLAY__SEERIS__DISPLA0C                ((displa0c_Type *)DISPLAY__SEERIS__DISPLA0C_BASE)
  /** Array initializer of displa0c peripheral base addresses */
  #define displa0c_BASE_ADDRS                      { DISPLAY__SEERIS__DISPLA0C_BASE }
  /** Array initializer of displa0c peripheral base pointers */
  #define displa0c_BASE_PTRS                       { DISPLAY__SEERIS__DISPLA0C }
#endif

/* displa1c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__DISPLA1C base address */
  #define DISPLAY__SEERIS__DISPLA1C_BASE           (0x5B781000u)
  /** Peripheral DISPLAY__SEERIS__DISPLA1C base address */
  #define DISPLAY__SEERIS__DISPLA1C_BASE_NS        (0x4B781000u)
  /** Peripheral DISPLAY__SEERIS__DISPLA1C base pointer */
  #define DISPLAY__SEERIS__DISPLA1C                ((displa1c_Type *)DISPLAY__SEERIS__DISPLA1C_BASE)
  /** Peripheral DISPLAY__SEERIS__DISPLA1C base pointer */
  #define DISPLAY__SEERIS__DISPLA1C_NS             ((displa1c_Type *)DISPLAY__SEERIS__DISPLA1C_BASE_NS)
  /** Array initializer of displa1c peripheral base addresses */
  #define displa1c_BASE_ADDRS                      { DISPLAY__SEERIS__DISPLA1C_BASE }
  /** Array initializer of displa1c peripheral base pointers */
  #define displa1c_BASE_PTRS                       { DISPLAY__SEERIS__DISPLA1C }
  /** Array initializer of displa1c peripheral base addresses */
  #define displa1c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__DISPLA1C_BASE_NS }
  /** Array initializer of displa1c peripheral base pointers */
  #define displa1c_BASE_PTRS_NS                    { DISPLAY__SEERIS__DISPLA1C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__DISPLA1C base address */
  #define DISPLAY__SEERIS__DISPLA1C_BASE           (0x4B781000u)
  /** Peripheral DISPLAY__SEERIS__DISPLA1C base pointer */
  #define DISPLAY__SEERIS__DISPLA1C                ((displa1c_Type *)DISPLAY__SEERIS__DISPLA1C_BASE)
  /** Array initializer of displa1c peripheral base addresses */
  #define displa1c_BASE_ADDRS                      { DISPLAY__SEERIS__DISPLA1C_BASE }
  /** Array initializer of displa1c peripheral base pointers */
  #define displa1c_BASE_PTRS                       { DISPLAY__SEERIS__DISPLA1C }
#endif

/* domainma - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__DOMAINMA base address */
  #define DISPLAY__SEERIS__DOMAINMA_BASE           (0x5B402000u)
  /** Peripheral DISPLAY__SEERIS__DOMAINMA base address */
  #define DISPLAY__SEERIS__DOMAINMA_BASE_NS        (0x4B402000u)
  /** Peripheral DISPLAY__SEERIS__DOMAINMA base pointer */
  #define DISPLAY__SEERIS__DOMAINMA                ((domainma_Type *)DISPLAY__SEERIS__DOMAINMA_BASE)
  /** Peripheral DISPLAY__SEERIS__DOMAINMA base pointer */
  #define DISPLAY__SEERIS__DOMAINMA_NS             ((domainma_Type *)DISPLAY__SEERIS__DOMAINMA_BASE_NS)
  /** Array initializer of domainma peripheral base addresses */
  #define domainma_BASE_ADDRS                      { DISPLAY__SEERIS__DOMAINMA_BASE }
  /** Array initializer of domainma peripheral base pointers */
  #define domainma_BASE_PTRS                       { DISPLAY__SEERIS__DOMAINMA }
  /** Array initializer of domainma peripheral base addresses */
  #define domainma_BASE_ADDRS_NS                   { DISPLAY__SEERIS__DOMAINMA_BASE_NS }
  /** Array initializer of domainma peripheral base pointers */
  #define domainma_BASE_PTRS_NS                    { DISPLAY__SEERIS__DOMAINMA_NS }
#else
  /** Peripheral DISPLAY__SEERIS__DOMAINMA base address */
  #define DISPLAY__SEERIS__DOMAINMA_BASE           (0x4B402000u)
  /** Peripheral DISPLAY__SEERIS__DOMAINMA base pointer */
  #define DISPLAY__SEERIS__DOMAINMA                ((domainma_Type *)DISPLAY__SEERIS__DOMAINMA_BASE)
  /** Array initializer of domainma peripheral base addresses */
  #define domainma_BASE_ADDRS                      { DISPLAY__SEERIS__DOMAINMA_BASE }
  /** Array initializer of domainma peripheral base pointers */
  #define domainma_BASE_PTRS                       { DISPLAY__SEERIS__DOMAINMA }
#endif

/* extdst0c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__EXTDST0C base address */
  #define DISPLAY__SEERIS__EXTDST0C_BASE           (0x5B511000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST0C base address */
  #define DISPLAY__SEERIS__EXTDST0C_BASE_NS        (0x4B511000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST0C base pointer */
  #define DISPLAY__SEERIS__EXTDST0C                ((extdst0c_Type *)DISPLAY__SEERIS__EXTDST0C_BASE)
  /** Peripheral DISPLAY__SEERIS__EXTDST0C base pointer */
  #define DISPLAY__SEERIS__EXTDST0C_NS             ((extdst0c_Type *)DISPLAY__SEERIS__EXTDST0C_BASE_NS)
  /** Array initializer of extdst0c peripheral base addresses */
  #define extdst0c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST0C_BASE }
  /** Array initializer of extdst0c peripheral base pointers */
  #define extdst0c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST0C }
  /** Array initializer of extdst0c peripheral base addresses */
  #define extdst0c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__EXTDST0C_BASE_NS }
  /** Array initializer of extdst0c peripheral base pointers */
  #define extdst0c_BASE_PTRS_NS                    { DISPLAY__SEERIS__EXTDST0C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__EXTDST0C base address */
  #define DISPLAY__SEERIS__EXTDST0C_BASE           (0x4B511000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST0C base pointer */
  #define DISPLAY__SEERIS__EXTDST0C                ((extdst0c_Type *)DISPLAY__SEERIS__EXTDST0C_BASE)
  /** Array initializer of extdst0c peripheral base addresses */
  #define extdst0c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST0C_BASE }
  /** Array initializer of extdst0c peripheral base pointers */
  #define extdst0c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST0C }
#endif

/* extdst1c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__EXTDST1C base address */
  #define DISPLAY__SEERIS__EXTDST1C_BASE           (0x5B551000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST1C base address */
  #define DISPLAY__SEERIS__EXTDST1C_BASE_NS        (0x4B551000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST1C base pointer */
  #define DISPLAY__SEERIS__EXTDST1C                ((extdst1c_Type *)DISPLAY__SEERIS__EXTDST1C_BASE)
  /** Peripheral DISPLAY__SEERIS__EXTDST1C base pointer */
  #define DISPLAY__SEERIS__EXTDST1C_NS             ((extdst1c_Type *)DISPLAY__SEERIS__EXTDST1C_BASE_NS)
  /** Array initializer of extdst1c peripheral base addresses */
  #define extdst1c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST1C_BASE }
  /** Array initializer of extdst1c peripheral base pointers */
  #define extdst1c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST1C }
  /** Array initializer of extdst1c peripheral base addresses */
  #define extdst1c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__EXTDST1C_BASE_NS }
  /** Array initializer of extdst1c peripheral base pointers */
  #define extdst1c_BASE_PTRS_NS                    { DISPLAY__SEERIS__EXTDST1C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__EXTDST1C base address */
  #define DISPLAY__SEERIS__EXTDST1C_BASE           (0x4B551000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST1C base pointer */
  #define DISPLAY__SEERIS__EXTDST1C                ((extdst1c_Type *)DISPLAY__SEERIS__EXTDST1C_BASE)
  /** Array initializer of extdst1c peripheral base addresses */
  #define extdst1c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST1C_BASE }
  /** Array initializer of extdst1c peripheral base pointers */
  #define extdst1c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST1C }
#endif

/* extdst4c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__EXTDST4C base address */
  #define DISPLAY__SEERIS__EXTDST4C_BASE           (0x5B521000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST4C base address */
  #define DISPLAY__SEERIS__EXTDST4C_BASE_NS        (0x4B521000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST4C base pointer */
  #define DISPLAY__SEERIS__EXTDST4C                ((extdst4c_Type *)DISPLAY__SEERIS__EXTDST4C_BASE)
  /** Peripheral DISPLAY__SEERIS__EXTDST4C base pointer */
  #define DISPLAY__SEERIS__EXTDST4C_NS             ((extdst4c_Type *)DISPLAY__SEERIS__EXTDST4C_BASE_NS)
  /** Array initializer of extdst4c peripheral base addresses */
  #define extdst4c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST4C_BASE }
  /** Array initializer of extdst4c peripheral base pointers */
  #define extdst4c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST4C }
  /** Array initializer of extdst4c peripheral base addresses */
  #define extdst4c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__EXTDST4C_BASE_NS }
  /** Array initializer of extdst4c peripheral base pointers */
  #define extdst4c_BASE_PTRS_NS                    { DISPLAY__SEERIS__EXTDST4C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__EXTDST4C base address */
  #define DISPLAY__SEERIS__EXTDST4C_BASE           (0x4B521000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST4C base pointer */
  #define DISPLAY__SEERIS__EXTDST4C                ((extdst4c_Type *)DISPLAY__SEERIS__EXTDST4C_BASE)
  /** Array initializer of extdst4c peripheral base addresses */
  #define extdst4c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST4C_BASE }
  /** Array initializer of extdst4c peripheral base pointers */
  #define extdst4c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST4C }
#endif

/* extdst5c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__EXTDST5C base address */
  #define DISPLAY__SEERIS__EXTDST5C_BASE           (0x5B561000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST5C base address */
  #define DISPLAY__SEERIS__EXTDST5C_BASE_NS        (0x4B561000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST5C base pointer */
  #define DISPLAY__SEERIS__EXTDST5C                ((extdst5c_Type *)DISPLAY__SEERIS__EXTDST5C_BASE)
  /** Peripheral DISPLAY__SEERIS__EXTDST5C base pointer */
  #define DISPLAY__SEERIS__EXTDST5C_NS             ((extdst5c_Type *)DISPLAY__SEERIS__EXTDST5C_BASE_NS)
  /** Array initializer of extdst5c peripheral base addresses */
  #define extdst5c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST5C_BASE }
  /** Array initializer of extdst5c peripheral base pointers */
  #define extdst5c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST5C }
  /** Array initializer of extdst5c peripheral base addresses */
  #define extdst5c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__EXTDST5C_BASE_NS }
  /** Array initializer of extdst5c peripheral base pointers */
  #define extdst5c_BASE_PTRS_NS                    { DISPLAY__SEERIS__EXTDST5C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__EXTDST5C base address */
  #define DISPLAY__SEERIS__EXTDST5C_BASE           (0x4B561000u)
  /** Peripheral DISPLAY__SEERIS__EXTDST5C base pointer */
  #define DISPLAY__SEERIS__EXTDST5C                ((extdst5c_Type *)DISPLAY__SEERIS__EXTDST5C_BASE)
  /** Array initializer of extdst5c peripheral base addresses */
  #define extdst5c_BASE_ADDRS                      { DISPLAY__SEERIS__EXTDST5C_BASE }
  /** Array initializer of extdst5c peripheral base pointers */
  #define extdst5c_BASE_PTRS                       { DISPLAY__SEERIS__EXTDST5C }
#endif

/* fetchd9c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHD9C base address */
  #define DISPLAY__SEERIS__FETCHD9C_BASE           (0x5B491000u)
  /** Peripheral DISPLAY__SEERIS__FETCHD9C base address */
  #define DISPLAY__SEERIS__FETCHD9C_BASE_NS        (0x4B491000u)
  /** Peripheral DISPLAY__SEERIS__FETCHD9C base pointer */
  #define DISPLAY__SEERIS__FETCHD9C                ((fetchd9c_Type *)DISPLAY__SEERIS__FETCHD9C_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHD9C base pointer */
  #define DISPLAY__SEERIS__FETCHD9C_NS             ((fetchd9c_Type *)DISPLAY__SEERIS__FETCHD9C_BASE_NS)
  /** Array initializer of fetchd9c peripheral base addresses */
  #define fetchd9c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHD9C_BASE }
  /** Array initializer of fetchd9c peripheral base pointers */
  #define fetchd9c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHD9C }
  /** Array initializer of fetchd9c peripheral base addresses */
  #define fetchd9c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHD9C_BASE_NS }
  /** Array initializer of fetchd9c peripheral base pointers */
  #define fetchd9c_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHD9C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHD9C base address */
  #define DISPLAY__SEERIS__FETCHD9C_BASE           (0x4B491000u)
  /** Peripheral DISPLAY__SEERIS__FETCHD9C base pointer */
  #define DISPLAY__SEERIS__FETCHD9C                ((fetchd9c_Type *)DISPLAY__SEERIS__FETCHD9C_BASE)
  /** Array initializer of fetchd9c peripheral base addresses */
  #define fetchd9c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHD9C_BASE }
  /** Array initializer of fetchd9c peripheral base pointers */
  #define fetchd9c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHD9C }
#endif

/* fetchde1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHDE1 base address */
  #define DISPLAY__SEERIS__FETCHDE1_BASE           (0x5B490028u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE1 base address */
  #define DISPLAY__SEERIS__FETCHDE1_BASE_NS        (0x4B490028u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE1 base pointer */
  #define DISPLAY__SEERIS__FETCHDE1                ((fetchde1_Type *)DISPLAY__SEERIS__FETCHDE1_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHDE1 base pointer */
  #define DISPLAY__SEERIS__FETCHDE1_NS             ((fetchde1_Type *)DISPLAY__SEERIS__FETCHDE1_BASE_NS)
  /** Array initializer of fetchde1 peripheral base addresses */
  #define fetchde1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE1_BASE }
  /** Array initializer of fetchde1 peripheral base pointers */
  #define fetchde1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE1 }
  /** Array initializer of fetchde1 peripheral base addresses */
  #define fetchde1_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHDE1_BASE_NS }
  /** Array initializer of fetchde1 peripheral base pointers */
  #define fetchde1_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHDE1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHDE1 base address */
  #define DISPLAY__SEERIS__FETCHDE1_BASE           (0x4B490028u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE1 base pointer */
  #define DISPLAY__SEERIS__FETCHDE1                ((fetchde1_Type *)DISPLAY__SEERIS__FETCHDE1_BASE)
  /** Array initializer of fetchde1 peripheral base addresses */
  #define fetchde1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE1_BASE }
  /** Array initializer of fetchde1 peripheral base pointers */
  #define fetchde1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE1 }
#endif

/* fetchde2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHDE2 base address */
  #define DISPLAY__SEERIS__FETCHDE2_BASE           (0x5B490060u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE2 base address */
  #define DISPLAY__SEERIS__FETCHDE2_BASE_NS        (0x4B490060u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE2 base pointer */
  #define DISPLAY__SEERIS__FETCHDE2                ((fetchde2_Type *)DISPLAY__SEERIS__FETCHDE2_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHDE2 base pointer */
  #define DISPLAY__SEERIS__FETCHDE2_NS             ((fetchde2_Type *)DISPLAY__SEERIS__FETCHDE2_BASE_NS)
  /** Array initializer of fetchde2 peripheral base addresses */
  #define fetchde2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE2_BASE }
  /** Array initializer of fetchde2 peripheral base pointers */
  #define fetchde2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE2 }
  /** Array initializer of fetchde2 peripheral base addresses */
  #define fetchde2_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHDE2_BASE_NS }
  /** Array initializer of fetchde2 peripheral base pointers */
  #define fetchde2_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHDE2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHDE2 base address */
  #define DISPLAY__SEERIS__FETCHDE2_BASE           (0x4B490060u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE2 base pointer */
  #define DISPLAY__SEERIS__FETCHDE2                ((fetchde2_Type *)DISPLAY__SEERIS__FETCHDE2_BASE)
  /** Array initializer of fetchde2 peripheral base addresses */
  #define fetchde2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE2_BASE }
  /** Array initializer of fetchde2 peripheral base pointers */
  #define fetchde2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE2 }
#endif

/* fetchde3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHDE3 base address */
  #define DISPLAY__SEERIS__FETCHDE3_BASE           (0x5B490088u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE3 base address */
  #define DISPLAY__SEERIS__FETCHDE3_BASE_NS        (0x4B490088u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE3 base pointer */
  #define DISPLAY__SEERIS__FETCHDE3                ((fetchde3_Type *)DISPLAY__SEERIS__FETCHDE3_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHDE3 base pointer */
  #define DISPLAY__SEERIS__FETCHDE3_NS             ((fetchde3_Type *)DISPLAY__SEERIS__FETCHDE3_BASE_NS)
  /** Array initializer of fetchde3 peripheral base addresses */
  #define fetchde3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE3_BASE }
  /** Array initializer of fetchde3 peripheral base pointers */
  #define fetchde3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE3 }
  /** Array initializer of fetchde3 peripheral base addresses */
  #define fetchde3_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHDE3_BASE_NS }
  /** Array initializer of fetchde3 peripheral base pointers */
  #define fetchde3_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHDE3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHDE3 base address */
  #define DISPLAY__SEERIS__FETCHDE3_BASE           (0x4B490088u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE3 base pointer */
  #define DISPLAY__SEERIS__FETCHDE3                ((fetchde3_Type *)DISPLAY__SEERIS__FETCHDE3_BASE)
  /** Array initializer of fetchde3 peripheral base addresses */
  #define fetchde3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE3_BASE }
  /** Array initializer of fetchde3 peripheral base pointers */
  #define fetchde3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE3 }
#endif

/* fetchde4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHDE4 base address */
  #define DISPLAY__SEERIS__FETCHDE4_BASE           (0x5B490098u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE4 base address */
  #define DISPLAY__SEERIS__FETCHDE4_BASE_NS        (0x4B490098u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE4 base pointer */
  #define DISPLAY__SEERIS__FETCHDE4                ((fetchde4_Type *)DISPLAY__SEERIS__FETCHDE4_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHDE4 base pointer */
  #define DISPLAY__SEERIS__FETCHDE4_NS             ((fetchde4_Type *)DISPLAY__SEERIS__FETCHDE4_BASE_NS)
  /** Array initializer of fetchde4 peripheral base addresses */
  #define fetchde4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE4_BASE }
  /** Array initializer of fetchde4 peripheral base pointers */
  #define fetchde4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE4 }
  /** Array initializer of fetchde4 peripheral base addresses */
  #define fetchde4_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHDE4_BASE_NS }
  /** Array initializer of fetchde4 peripheral base pointers */
  #define fetchde4_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHDE4_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHDE4 base address */
  #define DISPLAY__SEERIS__FETCHDE4_BASE           (0x4B490098u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE4 base pointer */
  #define DISPLAY__SEERIS__FETCHDE4                ((fetchde4_Type *)DISPLAY__SEERIS__FETCHDE4_BASE)
  /** Array initializer of fetchde4 peripheral base addresses */
  #define fetchde4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE4_BASE }
  /** Array initializer of fetchde4 peripheral base pointers */
  #define fetchde4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE4 }
#endif

/* fetchde5 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHDE5 base address */
  #define DISPLAY__SEERIS__FETCHDE5_BASE           (0x5B490400u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE5 base address */
  #define DISPLAY__SEERIS__FETCHDE5_BASE_NS        (0x4B490400u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE5 base pointer */
  #define DISPLAY__SEERIS__FETCHDE5                ((fetchde5_Type *)DISPLAY__SEERIS__FETCHDE5_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHDE5 base pointer */
  #define DISPLAY__SEERIS__FETCHDE5_NS             ((fetchde5_Type *)DISPLAY__SEERIS__FETCHDE5_BASE_NS)
  /** Array initializer of fetchde5 peripheral base addresses */
  #define fetchde5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE5_BASE }
  /** Array initializer of fetchde5 peripheral base pointers */
  #define fetchde5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE5 }
  /** Array initializer of fetchde5 peripheral base addresses */
  #define fetchde5_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHDE5_BASE_NS }
  /** Array initializer of fetchde5 peripheral base pointers */
  #define fetchde5_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHDE5_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHDE5 base address */
  #define DISPLAY__SEERIS__FETCHDE5_BASE           (0x4B490400u)
  /** Peripheral DISPLAY__SEERIS__FETCHDE5 base pointer */
  #define DISPLAY__SEERIS__FETCHDE5                ((fetchde5_Type *)DISPLAY__SEERIS__FETCHDE5_BASE)
  /** Array initializer of fetchde5 peripheral base addresses */
  #define fetchde5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDE5_BASE }
  /** Array initializer of fetchde5 peripheral base pointers */
  #define fetchde5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDE5 }
#endif

/* fetchdec - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHDEC base address */
  #define DISPLAY__SEERIS__FETCHDEC_BASE           (0x5B490000u)
  /** Peripheral DISPLAY__SEERIS__FETCHDEC base address */
  #define DISPLAY__SEERIS__FETCHDEC_BASE_NS        (0x4B490000u)
  /** Peripheral DISPLAY__SEERIS__FETCHDEC base pointer */
  #define DISPLAY__SEERIS__FETCHDEC                ((fetchdec_Type *)DISPLAY__SEERIS__FETCHDEC_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHDEC base pointer */
  #define DISPLAY__SEERIS__FETCHDEC_NS             ((fetchdec_Type *)DISPLAY__SEERIS__FETCHDEC_BASE_NS)
  /** Array initializer of fetchdec peripheral base addresses */
  #define fetchdec_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDEC_BASE }
  /** Array initializer of fetchdec peripheral base pointers */
  #define fetchdec_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDEC }
  /** Array initializer of fetchdec peripheral base addresses */
  #define fetchdec_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHDEC_BASE_NS }
  /** Array initializer of fetchdec peripheral base pointers */
  #define fetchdec_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHDEC_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHDEC base address */
  #define DISPLAY__SEERIS__FETCHDEC_BASE           (0x4B490000u)
  /** Peripheral DISPLAY__SEERIS__FETCHDEC base pointer */
  #define DISPLAY__SEERIS__FETCHDEC                ((fetchdec_Type *)DISPLAY__SEERIS__FETCHDEC_BASE)
  /** Array initializer of fetchdec peripheral base addresses */
  #define fetchdec_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHDEC_BASE }
  /** Array initializer of fetchdec peripheral base pointers */
  #define fetchdec_BASE_PTRS                       { DISPLAY__SEERIS__FETCHDEC }
#endif

/* fetche0c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHE0C base address */
  #define DISPLAY__SEERIS__FETCHE0C_BASE           (0x5B601000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE0C base address */
  #define DISPLAY__SEERIS__FETCHE0C_BASE_NS        (0x4B601000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE0C base pointer */
  #define DISPLAY__SEERIS__FETCHE0C                ((fetche0c_Type *)DISPLAY__SEERIS__FETCHE0C_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHE0C base pointer */
  #define DISPLAY__SEERIS__FETCHE0C_NS             ((fetche0c_Type *)DISPLAY__SEERIS__FETCHE0C_BASE_NS)
  /** Array initializer of fetche0c peripheral base addresses */
  #define fetche0c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE0C_BASE }
  /** Array initializer of fetche0c peripheral base pointers */
  #define fetche0c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE0C }
  /** Array initializer of fetche0c peripheral base addresses */
  #define fetche0c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHE0C_BASE_NS }
  /** Array initializer of fetche0c peripheral base pointers */
  #define fetche0c_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHE0C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHE0C base address */
  #define DISPLAY__SEERIS__FETCHE0C_BASE           (0x4B601000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE0C base pointer */
  #define DISPLAY__SEERIS__FETCHE0C                ((fetche0c_Type *)DISPLAY__SEERIS__FETCHE0C_BASE)
  /** Array initializer of fetche0c peripheral base addresses */
  #define fetche0c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE0C_BASE }
  /** Array initializer of fetche0c peripheral base pointers */
  #define fetche0c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE0C }
#endif

/* fetche10 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHE10 base address */
  #define DISPLAY__SEERIS__FETCHE10_BASE           (0x5B620000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE10 base address */
  #define DISPLAY__SEERIS__FETCHE10_BASE_NS        (0x4B620000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE10 base pointer */
  #define DISPLAY__SEERIS__FETCHE10                ((fetche10_Type *)DISPLAY__SEERIS__FETCHE10_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHE10 base pointer */
  #define DISPLAY__SEERIS__FETCHE10_NS             ((fetche10_Type *)DISPLAY__SEERIS__FETCHE10_BASE_NS)
  /** Array initializer of fetche10 peripheral base addresses */
  #define fetche10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE10_BASE }
  /** Array initializer of fetche10 peripheral base pointers */
  #define fetche10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE10 }
  /** Array initializer of fetche10 peripheral base addresses */
  #define fetche10_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHE10_BASE_NS }
  /** Array initializer of fetche10 peripheral base pointers */
  #define fetche10_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHE10_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHE10 base address */
  #define DISPLAY__SEERIS__FETCHE10_BASE           (0x4B620000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE10 base pointer */
  #define DISPLAY__SEERIS__FETCHE10                ((fetche10_Type *)DISPLAY__SEERIS__FETCHE10_BASE)
  /** Array initializer of fetche10 peripheral base addresses */
  #define fetche10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE10_BASE }
  /** Array initializer of fetche10 peripheral base pointers */
  #define fetche10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE10 }
#endif

/* fetche11 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHE11 base address */
  #define DISPLAY__SEERIS__FETCHE11_BASE           (0x5B620010u)
  /** Peripheral DISPLAY__SEERIS__FETCHE11 base address */
  #define DISPLAY__SEERIS__FETCHE11_BASE_NS        (0x4B620010u)
  /** Peripheral DISPLAY__SEERIS__FETCHE11 base pointer */
  #define DISPLAY__SEERIS__FETCHE11                ((fetche11_Type *)DISPLAY__SEERIS__FETCHE11_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHE11 base pointer */
  #define DISPLAY__SEERIS__FETCHE11_NS             ((fetche11_Type *)DISPLAY__SEERIS__FETCHE11_BASE_NS)
  /** Array initializer of fetche11 peripheral base addresses */
  #define fetche11_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE11_BASE }
  /** Array initializer of fetche11 peripheral base pointers */
  #define fetche11_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE11 }
  /** Array initializer of fetche11 peripheral base addresses */
  #define fetche11_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHE11_BASE_NS }
  /** Array initializer of fetche11 peripheral base pointers */
  #define fetche11_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHE11_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHE11 base address */
  #define DISPLAY__SEERIS__FETCHE11_BASE           (0x4B620010u)
  /** Peripheral DISPLAY__SEERIS__FETCHE11 base pointer */
  #define DISPLAY__SEERIS__FETCHE11                ((fetche11_Type *)DISPLAY__SEERIS__FETCHE11_BASE)
  /** Array initializer of fetche11 peripheral base addresses */
  #define fetche11_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE11_BASE }
  /** Array initializer of fetche11 peripheral base pointers */
  #define fetche11_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE11 }
#endif

/* fetche12 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHE12 base address */
  #define DISPLAY__SEERIS__FETCHE12_BASE           (0x5B620048u)
  /** Peripheral DISPLAY__SEERIS__FETCHE12 base address */
  #define DISPLAY__SEERIS__FETCHE12_BASE_NS        (0x4B620048u)
  /** Peripheral DISPLAY__SEERIS__FETCHE12 base pointer */
  #define DISPLAY__SEERIS__FETCHE12                ((fetche12_Type *)DISPLAY__SEERIS__FETCHE12_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHE12 base pointer */
  #define DISPLAY__SEERIS__FETCHE12_NS             ((fetche12_Type *)DISPLAY__SEERIS__FETCHE12_BASE_NS)
  /** Array initializer of fetche12 peripheral base addresses */
  #define fetche12_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE12_BASE }
  /** Array initializer of fetche12 peripheral base pointers */
  #define fetche12_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE12 }
  /** Array initializer of fetche12 peripheral base addresses */
  #define fetche12_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHE12_BASE_NS }
  /** Array initializer of fetche12 peripheral base pointers */
  #define fetche12_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHE12_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHE12 base address */
  #define DISPLAY__SEERIS__FETCHE12_BASE           (0x4B620048u)
  /** Peripheral DISPLAY__SEERIS__FETCHE12 base pointer */
  #define DISPLAY__SEERIS__FETCHE12                ((fetche12_Type *)DISPLAY__SEERIS__FETCHE12_BASE)
  /** Array initializer of fetche12 peripheral base addresses */
  #define fetche12_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE12_BASE }
  /** Array initializer of fetche12 peripheral base pointers */
  #define fetche12_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE12 }
#endif

/* fetche13 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHE13 base address */
  #define DISPLAY__SEERIS__FETCHE13_BASE           (0x5B620060u)
  /** Peripheral DISPLAY__SEERIS__FETCHE13 base address */
  #define DISPLAY__SEERIS__FETCHE13_BASE_NS        (0x4B620060u)
  /** Peripheral DISPLAY__SEERIS__FETCHE13 base pointer */
  #define DISPLAY__SEERIS__FETCHE13                ((fetche13_Type *)DISPLAY__SEERIS__FETCHE13_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHE13 base pointer */
  #define DISPLAY__SEERIS__FETCHE13_NS             ((fetche13_Type *)DISPLAY__SEERIS__FETCHE13_BASE_NS)
  /** Array initializer of fetche13 peripheral base addresses */
  #define fetche13_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE13_BASE }
  /** Array initializer of fetche13 peripheral base pointers */
  #define fetche13_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE13 }
  /** Array initializer of fetche13 peripheral base addresses */
  #define fetche13_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHE13_BASE_NS }
  /** Array initializer of fetche13 peripheral base pointers */
  #define fetche13_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHE13_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHE13 base address */
  #define DISPLAY__SEERIS__FETCHE13_BASE           (0x4B620060u)
  /** Peripheral DISPLAY__SEERIS__FETCHE13 base pointer */
  #define DISPLAY__SEERIS__FETCHE13                ((fetche13_Type *)DISPLAY__SEERIS__FETCHE13_BASE)
  /** Array initializer of fetche13 peripheral base addresses */
  #define fetche13_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE13_BASE }
  /** Array initializer of fetche13 peripheral base pointers */
  #define fetche13_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE13 }
#endif

/* fetche14 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHE14 base address */
  #define DISPLAY__SEERIS__FETCHE14_BASE           (0x5B620068u)
  /** Peripheral DISPLAY__SEERIS__FETCHE14 base address */
  #define DISPLAY__SEERIS__FETCHE14_BASE_NS        (0x4B620068u)
  /** Peripheral DISPLAY__SEERIS__FETCHE14 base pointer */
  #define DISPLAY__SEERIS__FETCHE14                ((fetche14_Type *)DISPLAY__SEERIS__FETCHE14_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHE14 base pointer */
  #define DISPLAY__SEERIS__FETCHE14_NS             ((fetche14_Type *)DISPLAY__SEERIS__FETCHE14_BASE_NS)
  /** Array initializer of fetche14 peripheral base addresses */
  #define fetche14_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE14_BASE }
  /** Array initializer of fetche14 peripheral base pointers */
  #define fetche14_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE14 }
  /** Array initializer of fetche14 peripheral base addresses */
  #define fetche14_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHE14_BASE_NS }
  /** Array initializer of fetche14 peripheral base pointers */
  #define fetche14_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHE14_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHE14 base address */
  #define DISPLAY__SEERIS__FETCHE14_BASE           (0x4B620068u)
  /** Peripheral DISPLAY__SEERIS__FETCHE14 base pointer */
  #define DISPLAY__SEERIS__FETCHE14                ((fetche14_Type *)DISPLAY__SEERIS__FETCHE14_BASE)
  /** Array initializer of fetche14 peripheral base addresses */
  #define fetche14_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE14_BASE }
  /** Array initializer of fetche14 peripheral base pointers */
  #define fetche14_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE14 }
#endif

/* fetche1c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHE1C base address */
  #define DISPLAY__SEERIS__FETCHE1C_BASE           (0x5B621000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE1C base address */
  #define DISPLAY__SEERIS__FETCHE1C_BASE_NS        (0x4B621000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE1C base pointer */
  #define DISPLAY__SEERIS__FETCHE1C                ((fetche1c_Type *)DISPLAY__SEERIS__FETCHE1C_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHE1C base pointer */
  #define DISPLAY__SEERIS__FETCHE1C_NS             ((fetche1c_Type *)DISPLAY__SEERIS__FETCHE1C_BASE_NS)
  /** Array initializer of fetche1c peripheral base addresses */
  #define fetche1c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE1C_BASE }
  /** Array initializer of fetche1c peripheral base pointers */
  #define fetche1c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE1C }
  /** Array initializer of fetche1c peripheral base addresses */
  #define fetche1c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHE1C_BASE_NS }
  /** Array initializer of fetche1c peripheral base pointers */
  #define fetche1c_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHE1C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHE1C base address */
  #define DISPLAY__SEERIS__FETCHE1C_BASE           (0x4B621000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE1C base pointer */
  #define DISPLAY__SEERIS__FETCHE1C                ((fetche1c_Type *)DISPLAY__SEERIS__FETCHE1C_BASE)
  /** Array initializer of fetche1c peripheral base addresses */
  #define fetche1c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE1C_BASE }
  /** Array initializer of fetche1c peripheral base pointers */
  #define fetche1c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE1C }
#endif

/* fetche9c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHE9C base address */
  #define DISPLAY__SEERIS__FETCHE9C_BASE           (0x5B4A1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE9C base address */
  #define DISPLAY__SEERIS__FETCHE9C_BASE_NS        (0x4B4A1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE9C base pointer */
  #define DISPLAY__SEERIS__FETCHE9C                ((fetche9c_Type *)DISPLAY__SEERIS__FETCHE9C_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHE9C base pointer */
  #define DISPLAY__SEERIS__FETCHE9C_NS             ((fetche9c_Type *)DISPLAY__SEERIS__FETCHE9C_BASE_NS)
  /** Array initializer of fetche9c peripheral base addresses */
  #define fetche9c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE9C_BASE }
  /** Array initializer of fetche9c peripheral base pointers */
  #define fetche9c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE9C }
  /** Array initializer of fetche9c peripheral base addresses */
  #define fetche9c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHE9C_BASE_NS }
  /** Array initializer of fetche9c peripheral base pointers */
  #define fetche9c_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHE9C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHE9C base address */
  #define DISPLAY__SEERIS__FETCHE9C_BASE           (0x4B4A1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHE9C base pointer */
  #define DISPLAY__SEERIS__FETCHE9C                ((fetche9c_Type *)DISPLAY__SEERIS__FETCHE9C_BASE)
  /** Array initializer of fetche9c peripheral base addresses */
  #define fetche9c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHE9C_BASE }
  /** Array initializer of fetche9c peripheral base pointers */
  #define fetche9c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHE9C }
#endif

/* fetchec1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHEC1 base address */
  #define DISPLAY__SEERIS__FETCHEC1_BASE           (0x5B4A0010u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC1 base address */
  #define DISPLAY__SEERIS__FETCHEC1_BASE_NS        (0x4B4A0010u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC1 base pointer */
  #define DISPLAY__SEERIS__FETCHEC1                ((fetchec1_Type *)DISPLAY__SEERIS__FETCHEC1_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHEC1 base pointer */
  #define DISPLAY__SEERIS__FETCHEC1_NS             ((fetchec1_Type *)DISPLAY__SEERIS__FETCHEC1_BASE_NS)
  /** Array initializer of fetchec1 peripheral base addresses */
  #define fetchec1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC1_BASE }
  /** Array initializer of fetchec1 peripheral base pointers */
  #define fetchec1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC1 }
  /** Array initializer of fetchec1 peripheral base addresses */
  #define fetchec1_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHEC1_BASE_NS }
  /** Array initializer of fetchec1 peripheral base pointers */
  #define fetchec1_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHEC1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHEC1 base address */
  #define DISPLAY__SEERIS__FETCHEC1_BASE           (0x4B4A0010u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC1 base pointer */
  #define DISPLAY__SEERIS__FETCHEC1                ((fetchec1_Type *)DISPLAY__SEERIS__FETCHEC1_BASE)
  /** Array initializer of fetchec1 peripheral base addresses */
  #define fetchec1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC1_BASE }
  /** Array initializer of fetchec1 peripheral base pointers */
  #define fetchec1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC1 }
#endif

/* fetchec2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHEC2 base address */
  #define DISPLAY__SEERIS__FETCHEC2_BASE           (0x5B4A0048u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC2 base address */
  #define DISPLAY__SEERIS__FETCHEC2_BASE_NS        (0x4B4A0048u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC2 base pointer */
  #define DISPLAY__SEERIS__FETCHEC2                ((fetchec2_Type *)DISPLAY__SEERIS__FETCHEC2_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHEC2 base pointer */
  #define DISPLAY__SEERIS__FETCHEC2_NS             ((fetchec2_Type *)DISPLAY__SEERIS__FETCHEC2_BASE_NS)
  /** Array initializer of fetchec2 peripheral base addresses */
  #define fetchec2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC2_BASE }
  /** Array initializer of fetchec2 peripheral base pointers */
  #define fetchec2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC2 }
  /** Array initializer of fetchec2 peripheral base addresses */
  #define fetchec2_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHEC2_BASE_NS }
  /** Array initializer of fetchec2 peripheral base pointers */
  #define fetchec2_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHEC2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHEC2 base address */
  #define DISPLAY__SEERIS__FETCHEC2_BASE           (0x4B4A0048u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC2 base pointer */
  #define DISPLAY__SEERIS__FETCHEC2                ((fetchec2_Type *)DISPLAY__SEERIS__FETCHEC2_BASE)
  /** Array initializer of fetchec2 peripheral base addresses */
  #define fetchec2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC2_BASE }
  /** Array initializer of fetchec2 peripheral base pointers */
  #define fetchec2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC2 }
#endif

/* fetchec3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHEC3 base address */
  #define DISPLAY__SEERIS__FETCHEC3_BASE           (0x5B4A0060u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC3 base address */
  #define DISPLAY__SEERIS__FETCHEC3_BASE_NS        (0x4B4A0060u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC3 base pointer */
  #define DISPLAY__SEERIS__FETCHEC3                ((fetchec3_Type *)DISPLAY__SEERIS__FETCHEC3_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHEC3 base pointer */
  #define DISPLAY__SEERIS__FETCHEC3_NS             ((fetchec3_Type *)DISPLAY__SEERIS__FETCHEC3_BASE_NS)
  /** Array initializer of fetchec3 peripheral base addresses */
  #define fetchec3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC3_BASE }
  /** Array initializer of fetchec3 peripheral base pointers */
  #define fetchec3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC3 }
  /** Array initializer of fetchec3 peripheral base addresses */
  #define fetchec3_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHEC3_BASE_NS }
  /** Array initializer of fetchec3 peripheral base pointers */
  #define fetchec3_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHEC3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHEC3 base address */
  #define DISPLAY__SEERIS__FETCHEC3_BASE           (0x4B4A0060u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC3 base pointer */
  #define DISPLAY__SEERIS__FETCHEC3                ((fetchec3_Type *)DISPLAY__SEERIS__FETCHEC3_BASE)
  /** Array initializer of fetchec3 peripheral base addresses */
  #define fetchec3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC3_BASE }
  /** Array initializer of fetchec3 peripheral base pointers */
  #define fetchec3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC3 }
#endif

/* fetchec4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHEC4 base address */
  #define DISPLAY__SEERIS__FETCHEC4_BASE           (0x5B4A0068u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC4 base address */
  #define DISPLAY__SEERIS__FETCHEC4_BASE_NS        (0x4B4A0068u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC4 base pointer */
  #define DISPLAY__SEERIS__FETCHEC4                ((fetchec4_Type *)DISPLAY__SEERIS__FETCHEC4_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHEC4 base pointer */
  #define DISPLAY__SEERIS__FETCHEC4_NS             ((fetchec4_Type *)DISPLAY__SEERIS__FETCHEC4_BASE_NS)
  /** Array initializer of fetchec4 peripheral base addresses */
  #define fetchec4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC4_BASE }
  /** Array initializer of fetchec4 peripheral base pointers */
  #define fetchec4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC4 }
  /** Array initializer of fetchec4 peripheral base addresses */
  #define fetchec4_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHEC4_BASE_NS }
  /** Array initializer of fetchec4 peripheral base pointers */
  #define fetchec4_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHEC4_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHEC4 base address */
  #define DISPLAY__SEERIS__FETCHEC4_BASE           (0x4B4A0068u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC4 base pointer */
  #define DISPLAY__SEERIS__FETCHEC4                ((fetchec4_Type *)DISPLAY__SEERIS__FETCHEC4_BASE)
  /** Array initializer of fetchec4 peripheral base addresses */
  #define fetchec4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC4_BASE }
  /** Array initializer of fetchec4 peripheral base pointers */
  #define fetchec4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC4 }
#endif

/* fetchec5 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHEC5 base address */
  #define DISPLAY__SEERIS__FETCHEC5_BASE           (0x5B600000u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC5 base address */
  #define DISPLAY__SEERIS__FETCHEC5_BASE_NS        (0x4B600000u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC5 base pointer */
  #define DISPLAY__SEERIS__FETCHEC5                ((fetchec5_Type *)DISPLAY__SEERIS__FETCHEC5_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHEC5 base pointer */
  #define DISPLAY__SEERIS__FETCHEC5_NS             ((fetchec5_Type *)DISPLAY__SEERIS__FETCHEC5_BASE_NS)
  /** Array initializer of fetchec5 peripheral base addresses */
  #define fetchec5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC5_BASE }
  /** Array initializer of fetchec5 peripheral base pointers */
  #define fetchec5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC5 }
  /** Array initializer of fetchec5 peripheral base addresses */
  #define fetchec5_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHEC5_BASE_NS }
  /** Array initializer of fetchec5 peripheral base pointers */
  #define fetchec5_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHEC5_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHEC5 base address */
  #define DISPLAY__SEERIS__FETCHEC5_BASE           (0x4B600000u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC5 base pointer */
  #define DISPLAY__SEERIS__FETCHEC5                ((fetchec5_Type *)DISPLAY__SEERIS__FETCHEC5_BASE)
  /** Array initializer of fetchec5 peripheral base addresses */
  #define fetchec5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC5_BASE }
  /** Array initializer of fetchec5 peripheral base pointers */
  #define fetchec5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC5 }
#endif

/* fetchec6 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHEC6 base address */
  #define DISPLAY__SEERIS__FETCHEC6_BASE           (0x5B600010u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC6 base address */
  #define DISPLAY__SEERIS__FETCHEC6_BASE_NS        (0x4B600010u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC6 base pointer */
  #define DISPLAY__SEERIS__FETCHEC6                ((fetchec6_Type *)DISPLAY__SEERIS__FETCHEC6_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHEC6 base pointer */
  #define DISPLAY__SEERIS__FETCHEC6_NS             ((fetchec6_Type *)DISPLAY__SEERIS__FETCHEC6_BASE_NS)
  /** Array initializer of fetchec6 peripheral base addresses */
  #define fetchec6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC6_BASE }
  /** Array initializer of fetchec6 peripheral base pointers */
  #define fetchec6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC6 }
  /** Array initializer of fetchec6 peripheral base addresses */
  #define fetchec6_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHEC6_BASE_NS }
  /** Array initializer of fetchec6 peripheral base pointers */
  #define fetchec6_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHEC6_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHEC6 base address */
  #define DISPLAY__SEERIS__FETCHEC6_BASE           (0x4B600010u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC6 base pointer */
  #define DISPLAY__SEERIS__FETCHEC6                ((fetchec6_Type *)DISPLAY__SEERIS__FETCHEC6_BASE)
  /** Array initializer of fetchec6 peripheral base addresses */
  #define fetchec6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC6_BASE }
  /** Array initializer of fetchec6 peripheral base pointers */
  #define fetchec6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC6 }
#endif

/* fetchec7 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHEC7 base address */
  #define DISPLAY__SEERIS__FETCHEC7_BASE           (0x5B600048u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC7 base address */
  #define DISPLAY__SEERIS__FETCHEC7_BASE_NS        (0x4B600048u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC7 base pointer */
  #define DISPLAY__SEERIS__FETCHEC7                ((fetchec7_Type *)DISPLAY__SEERIS__FETCHEC7_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHEC7 base pointer */
  #define DISPLAY__SEERIS__FETCHEC7_NS             ((fetchec7_Type *)DISPLAY__SEERIS__FETCHEC7_BASE_NS)
  /** Array initializer of fetchec7 peripheral base addresses */
  #define fetchec7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC7_BASE }
  /** Array initializer of fetchec7 peripheral base pointers */
  #define fetchec7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC7 }
  /** Array initializer of fetchec7 peripheral base addresses */
  #define fetchec7_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHEC7_BASE_NS }
  /** Array initializer of fetchec7 peripheral base pointers */
  #define fetchec7_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHEC7_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHEC7 base address */
  #define DISPLAY__SEERIS__FETCHEC7_BASE           (0x4B600048u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC7 base pointer */
  #define DISPLAY__SEERIS__FETCHEC7                ((fetchec7_Type *)DISPLAY__SEERIS__FETCHEC7_BASE)
  /** Array initializer of fetchec7 peripheral base addresses */
  #define fetchec7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC7_BASE }
  /** Array initializer of fetchec7 peripheral base pointers */
  #define fetchec7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC7 }
#endif

/* fetchec8 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHEC8 base address */
  #define DISPLAY__SEERIS__FETCHEC8_BASE           (0x5B600060u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC8 base address */
  #define DISPLAY__SEERIS__FETCHEC8_BASE_NS        (0x4B600060u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC8 base pointer */
  #define DISPLAY__SEERIS__FETCHEC8                ((fetchec8_Type *)DISPLAY__SEERIS__FETCHEC8_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHEC8 base pointer */
  #define DISPLAY__SEERIS__FETCHEC8_NS             ((fetchec8_Type *)DISPLAY__SEERIS__FETCHEC8_BASE_NS)
  /** Array initializer of fetchec8 peripheral base addresses */
  #define fetchec8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC8_BASE }
  /** Array initializer of fetchec8 peripheral base pointers */
  #define fetchec8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC8 }
  /** Array initializer of fetchec8 peripheral base addresses */
  #define fetchec8_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHEC8_BASE_NS }
  /** Array initializer of fetchec8 peripheral base pointers */
  #define fetchec8_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHEC8_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHEC8 base address */
  #define DISPLAY__SEERIS__FETCHEC8_BASE           (0x4B600060u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC8 base pointer */
  #define DISPLAY__SEERIS__FETCHEC8                ((fetchec8_Type *)DISPLAY__SEERIS__FETCHEC8_BASE)
  /** Array initializer of fetchec8 peripheral base addresses */
  #define fetchec8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC8_BASE }
  /** Array initializer of fetchec8 peripheral base pointers */
  #define fetchec8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC8 }
#endif

/* fetchec9 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHEC9 base address */
  #define DISPLAY__SEERIS__FETCHEC9_BASE           (0x5B600068u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC9 base address */
  #define DISPLAY__SEERIS__FETCHEC9_BASE_NS        (0x4B600068u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC9 base pointer */
  #define DISPLAY__SEERIS__FETCHEC9                ((fetchec9_Type *)DISPLAY__SEERIS__FETCHEC9_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHEC9 base pointer */
  #define DISPLAY__SEERIS__FETCHEC9_NS             ((fetchec9_Type *)DISPLAY__SEERIS__FETCHEC9_BASE_NS)
  /** Array initializer of fetchec9 peripheral base addresses */
  #define fetchec9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC9_BASE }
  /** Array initializer of fetchec9 peripheral base pointers */
  #define fetchec9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC9 }
  /** Array initializer of fetchec9 peripheral base addresses */
  #define fetchec9_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHEC9_BASE_NS }
  /** Array initializer of fetchec9 peripheral base pointers */
  #define fetchec9_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHEC9_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHEC9 base address */
  #define DISPLAY__SEERIS__FETCHEC9_BASE           (0x4B600068u)
  /** Peripheral DISPLAY__SEERIS__FETCHEC9 base pointer */
  #define DISPLAY__SEERIS__FETCHEC9                ((fetchec9_Type *)DISPLAY__SEERIS__FETCHEC9_BASE)
  /** Array initializer of fetchec9 peripheral base addresses */
  #define fetchec9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHEC9_BASE }
  /** Array initializer of fetchec9 peripheral base pointers */
  #define fetchec9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHEC9 }
#endif

/* fetcheco - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHECO base address */
  #define DISPLAY__SEERIS__FETCHECO_BASE           (0x5B4A0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHECO base address */
  #define DISPLAY__SEERIS__FETCHECO_BASE_NS        (0x4B4A0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHECO base pointer */
  #define DISPLAY__SEERIS__FETCHECO                ((fetcheco_Type *)DISPLAY__SEERIS__FETCHECO_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHECO base pointer */
  #define DISPLAY__SEERIS__FETCHECO_NS             ((fetcheco_Type *)DISPLAY__SEERIS__FETCHECO_BASE_NS)
  /** Array initializer of fetcheco peripheral base addresses */
  #define fetcheco_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHECO_BASE }
  /** Array initializer of fetcheco peripheral base pointers */
  #define fetcheco_BASE_PTRS                       { DISPLAY__SEERIS__FETCHECO }
  /** Array initializer of fetcheco peripheral base addresses */
  #define fetcheco_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHECO_BASE_NS }
  /** Array initializer of fetcheco peripheral base pointers */
  #define fetcheco_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHECO_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHECO base address */
  #define DISPLAY__SEERIS__FETCHECO_BASE           (0x4B4A0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHECO base pointer */
  #define DISPLAY__SEERIS__FETCHECO                ((fetcheco_Type *)DISPLAY__SEERIS__FETCHECO_BASE)
  /** Array initializer of fetcheco peripheral base addresses */
  #define fetcheco_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHECO_BASE }
  /** Array initializer of fetcheco peripheral base pointers */
  #define fetcheco_BASE_PTRS                       { DISPLAY__SEERIS__FETCHECO }
#endif

/* fetchl0c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL0C base address */
  #define DISPLAY__SEERIS__FETCHL0C_BASE           (0x5B5C1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHL0C base address */
  #define DISPLAY__SEERIS__FETCHL0C_BASE_NS        (0x4B5C1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHL0C base pointer */
  #define DISPLAY__SEERIS__FETCHL0C                ((fetchl0c_Type *)DISPLAY__SEERIS__FETCHL0C_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL0C base pointer */
  #define DISPLAY__SEERIS__FETCHL0C_NS             ((fetchl0c_Type *)DISPLAY__SEERIS__FETCHL0C_BASE_NS)
  /** Array initializer of fetchl0c peripheral base addresses */
  #define fetchl0c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL0C_BASE }
  /** Array initializer of fetchl0c peripheral base pointers */
  #define fetchl0c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL0C }
  /** Array initializer of fetchl0c peripheral base addresses */
  #define fetchl0c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL0C_BASE_NS }
  /** Array initializer of fetchl0c peripheral base pointers */
  #define fetchl0c_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL0C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL0C base address */
  #define DISPLAY__SEERIS__FETCHL0C_BASE           (0x4B5C1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHL0C base pointer */
  #define DISPLAY__SEERIS__FETCHL0C                ((fetchl0c_Type *)DISPLAY__SEERIS__FETCHL0C_BASE)
  /** Array initializer of fetchl0c peripheral base addresses */
  #define fetchl0c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL0C_BASE }
  /** Array initializer of fetchl0c peripheral base pointers */
  #define fetchl0c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL0C }
#endif

/* fetchl10 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL10 base address */
  #define DISPLAY__SEERIS__FETCHL10_BASE           (0x5B5C01F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL10 base address */
  #define DISPLAY__SEERIS__FETCHL10_BASE_NS        (0x4B5C01F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL10 base pointer */
  #define DISPLAY__SEERIS__FETCHL10                ((fetchl10_Type *)DISPLAY__SEERIS__FETCHL10_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL10 base pointer */
  #define DISPLAY__SEERIS__FETCHL10_NS             ((fetchl10_Type *)DISPLAY__SEERIS__FETCHL10_BASE_NS)
  /** Array initializer of fetchl10 peripheral base addresses */
  #define fetchl10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL10_BASE }
  /** Array initializer of fetchl10 peripheral base pointers */
  #define fetchl10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL10 }
  /** Array initializer of fetchl10 peripheral base addresses */
  #define fetchl10_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL10_BASE_NS }
  /** Array initializer of fetchl10 peripheral base pointers */
  #define fetchl10_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL10_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL10 base address */
  #define DISPLAY__SEERIS__FETCHL10_BASE           (0x4B5C01F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL10 base pointer */
  #define DISPLAY__SEERIS__FETCHL10                ((fetchl10_Type *)DISPLAY__SEERIS__FETCHL10_BASE)
  /** Array initializer of fetchl10 peripheral base addresses */
  #define fetchl10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL10_BASE }
  /** Array initializer of fetchl10 peripheral base pointers */
  #define fetchl10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL10 }
#endif

/* fetchl11 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL11 base address */
  #define DISPLAY__SEERIS__FETCHL11_BASE           (0x5B5C0200u)
  /** Peripheral DISPLAY__SEERIS__FETCHL11 base address */
  #define DISPLAY__SEERIS__FETCHL11_BASE_NS        (0x4B5C0200u)
  /** Peripheral DISPLAY__SEERIS__FETCHL11 base pointer */
  #define DISPLAY__SEERIS__FETCHL11                ((fetchl11_Type *)DISPLAY__SEERIS__FETCHL11_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL11 base pointer */
  #define DISPLAY__SEERIS__FETCHL11_NS             ((fetchl11_Type *)DISPLAY__SEERIS__FETCHL11_BASE_NS)
  /** Array initializer of fetchl11 peripheral base addresses */
  #define fetchl11_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL11_BASE }
  /** Array initializer of fetchl11 peripheral base pointers */
  #define fetchl11_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL11 }
  /** Array initializer of fetchl11 peripheral base addresses */
  #define fetchl11_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL11_BASE_NS }
  /** Array initializer of fetchl11 peripheral base pointers */
  #define fetchl11_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL11_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL11 base address */
  #define DISPLAY__SEERIS__FETCHL11_BASE           (0x4B5C0200u)
  /** Peripheral DISPLAY__SEERIS__FETCHL11 base pointer */
  #define DISPLAY__SEERIS__FETCHL11                ((fetchl11_Type *)DISPLAY__SEERIS__FETCHL11_BASE)
  /** Array initializer of fetchl11 peripheral base addresses */
  #define fetchl11_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL11_BASE }
  /** Array initializer of fetchl11 peripheral base pointers */
  #define fetchl11_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL11 }
#endif

/* fetchl12 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL12 base address */
  #define DISPLAY__SEERIS__FETCHL12_BASE           (0x5B5C0400u)
  /** Peripheral DISPLAY__SEERIS__FETCHL12 base address */
  #define DISPLAY__SEERIS__FETCHL12_BASE_NS        (0x4B5C0400u)
  /** Peripheral DISPLAY__SEERIS__FETCHL12 base pointer */
  #define DISPLAY__SEERIS__FETCHL12                ((fetchl12_Type *)DISPLAY__SEERIS__FETCHL12_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL12 base pointer */
  #define DISPLAY__SEERIS__FETCHL12_NS             ((fetchl12_Type *)DISPLAY__SEERIS__FETCHL12_BASE_NS)
  /** Array initializer of fetchl12 peripheral base addresses */
  #define fetchl12_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL12_BASE }
  /** Array initializer of fetchl12 peripheral base pointers */
  #define fetchl12_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL12 }
  /** Array initializer of fetchl12 peripheral base addresses */
  #define fetchl12_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL12_BASE_NS }
  /** Array initializer of fetchl12 peripheral base pointers */
  #define fetchl12_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL12_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL12 base address */
  #define DISPLAY__SEERIS__FETCHL12_BASE           (0x4B5C0400u)
  /** Peripheral DISPLAY__SEERIS__FETCHL12 base pointer */
  #define DISPLAY__SEERIS__FETCHL12                ((fetchl12_Type *)DISPLAY__SEERIS__FETCHL12_BASE)
  /** Array initializer of fetchl12 peripheral base addresses */
  #define fetchl12_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL12_BASE }
  /** Array initializer of fetchl12 peripheral base pointers */
  #define fetchl12_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL12 }
#endif

/* fetchl13 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL13 base address */
  #define DISPLAY__SEERIS__FETCHL13_BASE           (0x5B5D0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHL13 base address */
  #define DISPLAY__SEERIS__FETCHL13_BASE_NS        (0x4B5D0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHL13 base pointer */
  #define DISPLAY__SEERIS__FETCHL13                ((fetchl13_Type *)DISPLAY__SEERIS__FETCHL13_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL13 base pointer */
  #define DISPLAY__SEERIS__FETCHL13_NS             ((fetchl13_Type *)DISPLAY__SEERIS__FETCHL13_BASE_NS)
  /** Array initializer of fetchl13 peripheral base addresses */
  #define fetchl13_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL13_BASE }
  /** Array initializer of fetchl13 peripheral base pointers */
  #define fetchl13_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL13 }
  /** Array initializer of fetchl13 peripheral base addresses */
  #define fetchl13_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL13_BASE_NS }
  /** Array initializer of fetchl13 peripheral base pointers */
  #define fetchl13_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL13_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL13 base address */
  #define DISPLAY__SEERIS__FETCHL13_BASE           (0x4B5D0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHL13 base pointer */
  #define DISPLAY__SEERIS__FETCHL13                ((fetchl13_Type *)DISPLAY__SEERIS__FETCHL13_BASE)
  /** Array initializer of fetchl13 peripheral base addresses */
  #define fetchl13_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL13_BASE }
  /** Array initializer of fetchl13 peripheral base pointers */
  #define fetchl13_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL13 }
#endif

/* fetchl14 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL14 base address */
  #define DISPLAY__SEERIS__FETCHL14_BASE           (0x5B5D0018u)
  /** Peripheral DISPLAY__SEERIS__FETCHL14 base address */
  #define DISPLAY__SEERIS__FETCHL14_BASE_NS        (0x4B5D0018u)
  /** Peripheral DISPLAY__SEERIS__FETCHL14 base pointer */
  #define DISPLAY__SEERIS__FETCHL14                ((fetchl14_Type *)DISPLAY__SEERIS__FETCHL14_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL14 base pointer */
  #define DISPLAY__SEERIS__FETCHL14_NS             ((fetchl14_Type *)DISPLAY__SEERIS__FETCHL14_BASE_NS)
  /** Array initializer of fetchl14 peripheral base addresses */
  #define fetchl14_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL14_BASE }
  /** Array initializer of fetchl14 peripheral base pointers */
  #define fetchl14_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL14 }
  /** Array initializer of fetchl14 peripheral base addresses */
  #define fetchl14_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL14_BASE_NS }
  /** Array initializer of fetchl14 peripheral base pointers */
  #define fetchl14_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL14_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL14 base address */
  #define DISPLAY__SEERIS__FETCHL14_BASE           (0x4B5D0018u)
  /** Peripheral DISPLAY__SEERIS__FETCHL14 base pointer */
  #define DISPLAY__SEERIS__FETCHL14                ((fetchl14_Type *)DISPLAY__SEERIS__FETCHL14_BASE)
  /** Array initializer of fetchl14 peripheral base addresses */
  #define fetchl14_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL14_BASE }
  /** Array initializer of fetchl14 peripheral base pointers */
  #define fetchl14_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL14 }
#endif

/* fetchl15 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL15 base address */
  #define DISPLAY__SEERIS__FETCHL15_BASE           (0x5B5D0050u)
  /** Peripheral DISPLAY__SEERIS__FETCHL15 base address */
  #define DISPLAY__SEERIS__FETCHL15_BASE_NS        (0x4B5D0050u)
  /** Peripheral DISPLAY__SEERIS__FETCHL15 base pointer */
  #define DISPLAY__SEERIS__FETCHL15                ((fetchl15_Type *)DISPLAY__SEERIS__FETCHL15_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL15 base pointer */
  #define DISPLAY__SEERIS__FETCHL15_NS             ((fetchl15_Type *)DISPLAY__SEERIS__FETCHL15_BASE_NS)
  /** Array initializer of fetchl15 peripheral base addresses */
  #define fetchl15_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL15_BASE }
  /** Array initializer of fetchl15 peripheral base pointers */
  #define fetchl15_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL15 }
  /** Array initializer of fetchl15 peripheral base addresses */
  #define fetchl15_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL15_BASE_NS }
  /** Array initializer of fetchl15 peripheral base pointers */
  #define fetchl15_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL15_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL15 base address */
  #define DISPLAY__SEERIS__FETCHL15_BASE           (0x4B5D0050u)
  /** Peripheral DISPLAY__SEERIS__FETCHL15 base pointer */
  #define DISPLAY__SEERIS__FETCHL15                ((fetchl15_Type *)DISPLAY__SEERIS__FETCHL15_BASE)
  /** Array initializer of fetchl15 peripheral base addresses */
  #define fetchl15_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL15_BASE }
  /** Array initializer of fetchl15 peripheral base pointers */
  #define fetchl15_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL15 }
#endif

/* fetchl16 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL16 base address */
  #define DISPLAY__SEERIS__FETCHL16_BASE           (0x5B5D0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHL16 base address */
  #define DISPLAY__SEERIS__FETCHL16_BASE_NS        (0x4B5D0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHL16 base pointer */
  #define DISPLAY__SEERIS__FETCHL16                ((fetchl16_Type *)DISPLAY__SEERIS__FETCHL16_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL16 base pointer */
  #define DISPLAY__SEERIS__FETCHL16_NS             ((fetchl16_Type *)DISPLAY__SEERIS__FETCHL16_BASE_NS)
  /** Array initializer of fetchl16 peripheral base addresses */
  #define fetchl16_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL16_BASE }
  /** Array initializer of fetchl16 peripheral base pointers */
  #define fetchl16_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL16 }
  /** Array initializer of fetchl16 peripheral base addresses */
  #define fetchl16_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL16_BASE_NS }
  /** Array initializer of fetchl16 peripheral base pointers */
  #define fetchl16_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL16_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL16 base address */
  #define DISPLAY__SEERIS__FETCHL16_BASE           (0x4B5D0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHL16 base pointer */
  #define DISPLAY__SEERIS__FETCHL16                ((fetchl16_Type *)DISPLAY__SEERIS__FETCHL16_BASE)
  /** Array initializer of fetchl16 peripheral base addresses */
  #define fetchl16_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL16_BASE }
  /** Array initializer of fetchl16 peripheral base pointers */
  #define fetchl16_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL16 }
#endif

/* fetchl17 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL17 base address */
  #define DISPLAY__SEERIS__FETCHL17_BASE           (0x5B5D00C0u)
  /** Peripheral DISPLAY__SEERIS__FETCHL17 base address */
  #define DISPLAY__SEERIS__FETCHL17_BASE_NS        (0x4B5D00C0u)
  /** Peripheral DISPLAY__SEERIS__FETCHL17 base pointer */
  #define DISPLAY__SEERIS__FETCHL17                ((fetchl17_Type *)DISPLAY__SEERIS__FETCHL17_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL17 base pointer */
  #define DISPLAY__SEERIS__FETCHL17_NS             ((fetchl17_Type *)DISPLAY__SEERIS__FETCHL17_BASE_NS)
  /** Array initializer of fetchl17 peripheral base addresses */
  #define fetchl17_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL17_BASE }
  /** Array initializer of fetchl17 peripheral base pointers */
  #define fetchl17_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL17 }
  /** Array initializer of fetchl17 peripheral base addresses */
  #define fetchl17_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL17_BASE_NS }
  /** Array initializer of fetchl17 peripheral base pointers */
  #define fetchl17_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL17_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL17 base address */
  #define DISPLAY__SEERIS__FETCHL17_BASE           (0x4B5D00C0u)
  /** Peripheral DISPLAY__SEERIS__FETCHL17 base pointer */
  #define DISPLAY__SEERIS__FETCHL17                ((fetchl17_Type *)DISPLAY__SEERIS__FETCHL17_BASE)
  /** Array initializer of fetchl17 peripheral base addresses */
  #define fetchl17_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL17_BASE }
  /** Array initializer of fetchl17 peripheral base pointers */
  #define fetchl17_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL17 }
#endif

/* fetchl18 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL18 base address */
  #define DISPLAY__SEERIS__FETCHL18_BASE           (0x5B5D00F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL18 base address */
  #define DISPLAY__SEERIS__FETCHL18_BASE_NS        (0x4B5D00F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL18 base pointer */
  #define DISPLAY__SEERIS__FETCHL18                ((fetchl18_Type *)DISPLAY__SEERIS__FETCHL18_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL18 base pointer */
  #define DISPLAY__SEERIS__FETCHL18_NS             ((fetchl18_Type *)DISPLAY__SEERIS__FETCHL18_BASE_NS)
  /** Array initializer of fetchl18 peripheral base addresses */
  #define fetchl18_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL18_BASE }
  /** Array initializer of fetchl18 peripheral base pointers */
  #define fetchl18_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL18 }
  /** Array initializer of fetchl18 peripheral base addresses */
  #define fetchl18_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL18_BASE_NS }
  /** Array initializer of fetchl18 peripheral base pointers */
  #define fetchl18_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL18_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL18 base address */
  #define DISPLAY__SEERIS__FETCHL18_BASE           (0x4B5D00F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL18 base pointer */
  #define DISPLAY__SEERIS__FETCHL18                ((fetchl18_Type *)DISPLAY__SEERIS__FETCHL18_BASE)
  /** Array initializer of fetchl18 peripheral base addresses */
  #define fetchl18_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL18_BASE }
  /** Array initializer of fetchl18 peripheral base pointers */
  #define fetchl18_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL18 }
#endif

/* fetchl19 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL19 base address */
  #define DISPLAY__SEERIS__FETCHL19_BASE           (0x5B5D0130u)
  /** Peripheral DISPLAY__SEERIS__FETCHL19 base address */
  #define DISPLAY__SEERIS__FETCHL19_BASE_NS        (0x4B5D0130u)
  /** Peripheral DISPLAY__SEERIS__FETCHL19 base pointer */
  #define DISPLAY__SEERIS__FETCHL19                ((fetchl19_Type *)DISPLAY__SEERIS__FETCHL19_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL19 base pointer */
  #define DISPLAY__SEERIS__FETCHL19_NS             ((fetchl19_Type *)DISPLAY__SEERIS__FETCHL19_BASE_NS)
  /** Array initializer of fetchl19 peripheral base addresses */
  #define fetchl19_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL19_BASE }
  /** Array initializer of fetchl19 peripheral base pointers */
  #define fetchl19_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL19 }
  /** Array initializer of fetchl19 peripheral base addresses */
  #define fetchl19_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL19_BASE_NS }
  /** Array initializer of fetchl19 peripheral base pointers */
  #define fetchl19_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL19_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL19 base address */
  #define DISPLAY__SEERIS__FETCHL19_BASE           (0x4B5D0130u)
  /** Peripheral DISPLAY__SEERIS__FETCHL19 base pointer */
  #define DISPLAY__SEERIS__FETCHL19                ((fetchl19_Type *)DISPLAY__SEERIS__FETCHL19_BASE)
  /** Array initializer of fetchl19 peripheral base addresses */
  #define fetchl19_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL19_BASE }
  /** Array initializer of fetchl19 peripheral base pointers */
  #define fetchl19_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL19 }
#endif

/* fetchl1c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL1C base address */
  #define DISPLAY__SEERIS__FETCHL1C_BASE           (0x5B5D1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHL1C base address */
  #define DISPLAY__SEERIS__FETCHL1C_BASE_NS        (0x4B5D1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHL1C base pointer */
  #define DISPLAY__SEERIS__FETCHL1C                ((fetchl1c_Type *)DISPLAY__SEERIS__FETCHL1C_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL1C base pointer */
  #define DISPLAY__SEERIS__FETCHL1C_NS             ((fetchl1c_Type *)DISPLAY__SEERIS__FETCHL1C_BASE_NS)
  /** Array initializer of fetchl1c peripheral base addresses */
  #define fetchl1c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL1C_BASE }
  /** Array initializer of fetchl1c peripheral base pointers */
  #define fetchl1c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL1C }
  /** Array initializer of fetchl1c peripheral base addresses */
  #define fetchl1c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL1C_BASE_NS }
  /** Array initializer of fetchl1c peripheral base pointers */
  #define fetchl1c_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL1C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL1C base address */
  #define DISPLAY__SEERIS__FETCHL1C_BASE           (0x4B5D1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHL1C base pointer */
  #define DISPLAY__SEERIS__FETCHL1C                ((fetchl1c_Type *)DISPLAY__SEERIS__FETCHL1C_BASE)
  /** Array initializer of fetchl1c peripheral base addresses */
  #define fetchl1c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL1C_BASE }
  /** Array initializer of fetchl1c peripheral base pointers */
  #define fetchl1c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL1C }
#endif

/* fetchl20 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL20 base address */
  #define DISPLAY__SEERIS__FETCHL20_BASE           (0x5B5D0168u)
  /** Peripheral DISPLAY__SEERIS__FETCHL20 base address */
  #define DISPLAY__SEERIS__FETCHL20_BASE_NS        (0x4B5D0168u)
  /** Peripheral DISPLAY__SEERIS__FETCHL20 base pointer */
  #define DISPLAY__SEERIS__FETCHL20                ((fetchl20_Type *)DISPLAY__SEERIS__FETCHL20_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL20 base pointer */
  #define DISPLAY__SEERIS__FETCHL20_NS             ((fetchl20_Type *)DISPLAY__SEERIS__FETCHL20_BASE_NS)
  /** Array initializer of fetchl20 peripheral base addresses */
  #define fetchl20_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL20_BASE }
  /** Array initializer of fetchl20 peripheral base pointers */
  #define fetchl20_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL20 }
  /** Array initializer of fetchl20 peripheral base addresses */
  #define fetchl20_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL20_BASE_NS }
  /** Array initializer of fetchl20 peripheral base pointers */
  #define fetchl20_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL20_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL20 base address */
  #define DISPLAY__SEERIS__FETCHL20_BASE           (0x4B5D0168u)
  /** Peripheral DISPLAY__SEERIS__FETCHL20 base pointer */
  #define DISPLAY__SEERIS__FETCHL20                ((fetchl20_Type *)DISPLAY__SEERIS__FETCHL20_BASE)
  /** Array initializer of fetchl20 peripheral base addresses */
  #define fetchl20_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL20_BASE }
  /** Array initializer of fetchl20 peripheral base pointers */
  #define fetchl20_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL20 }
#endif

/* fetchl21 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL21 base address */
  #define DISPLAY__SEERIS__FETCHL21_BASE           (0x5B5D01A0u)
  /** Peripheral DISPLAY__SEERIS__FETCHL21 base address */
  #define DISPLAY__SEERIS__FETCHL21_BASE_NS        (0x4B5D01A0u)
  /** Peripheral DISPLAY__SEERIS__FETCHL21 base pointer */
  #define DISPLAY__SEERIS__FETCHL21                ((fetchl21_Type *)DISPLAY__SEERIS__FETCHL21_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL21 base pointer */
  #define DISPLAY__SEERIS__FETCHL21_NS             ((fetchl21_Type *)DISPLAY__SEERIS__FETCHL21_BASE_NS)
  /** Array initializer of fetchl21 peripheral base addresses */
  #define fetchl21_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL21_BASE }
  /** Array initializer of fetchl21 peripheral base pointers */
  #define fetchl21_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL21 }
  /** Array initializer of fetchl21 peripheral base addresses */
  #define fetchl21_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL21_BASE_NS }
  /** Array initializer of fetchl21 peripheral base pointers */
  #define fetchl21_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL21_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL21 base address */
  #define DISPLAY__SEERIS__FETCHL21_BASE           (0x4B5D01A0u)
  /** Peripheral DISPLAY__SEERIS__FETCHL21 base pointer */
  #define DISPLAY__SEERIS__FETCHL21                ((fetchl21_Type *)DISPLAY__SEERIS__FETCHL21_BASE)
  /** Array initializer of fetchl21 peripheral base addresses */
  #define fetchl21_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL21_BASE }
  /** Array initializer of fetchl21 peripheral base pointers */
  #define fetchl21_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL21 }
#endif

/* fetchl22 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL22 base address */
  #define DISPLAY__SEERIS__FETCHL22_BASE           (0x5B5D01D8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL22 base address */
  #define DISPLAY__SEERIS__FETCHL22_BASE_NS        (0x4B5D01D8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL22 base pointer */
  #define DISPLAY__SEERIS__FETCHL22                ((fetchl22_Type *)DISPLAY__SEERIS__FETCHL22_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL22 base pointer */
  #define DISPLAY__SEERIS__FETCHL22_NS             ((fetchl22_Type *)DISPLAY__SEERIS__FETCHL22_BASE_NS)
  /** Array initializer of fetchl22 peripheral base addresses */
  #define fetchl22_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL22_BASE }
  /** Array initializer of fetchl22 peripheral base pointers */
  #define fetchl22_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL22 }
  /** Array initializer of fetchl22 peripheral base addresses */
  #define fetchl22_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL22_BASE_NS }
  /** Array initializer of fetchl22 peripheral base pointers */
  #define fetchl22_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL22_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL22 base address */
  #define DISPLAY__SEERIS__FETCHL22_BASE           (0x4B5D01D8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL22 base pointer */
  #define DISPLAY__SEERIS__FETCHL22                ((fetchl22_Type *)DISPLAY__SEERIS__FETCHL22_BASE)
  /** Array initializer of fetchl22 peripheral base addresses */
  #define fetchl22_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL22_BASE }
  /** Array initializer of fetchl22 peripheral base pointers */
  #define fetchl22_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL22 }
#endif

/* fetchl23 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL23 base address */
  #define DISPLAY__SEERIS__FETCHL23_BASE           (0x5B5D01F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL23 base address */
  #define DISPLAY__SEERIS__FETCHL23_BASE_NS        (0x4B5D01F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL23 base pointer */
  #define DISPLAY__SEERIS__FETCHL23                ((fetchl23_Type *)DISPLAY__SEERIS__FETCHL23_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL23 base pointer */
  #define DISPLAY__SEERIS__FETCHL23_NS             ((fetchl23_Type *)DISPLAY__SEERIS__FETCHL23_BASE_NS)
  /** Array initializer of fetchl23 peripheral base addresses */
  #define fetchl23_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL23_BASE }
  /** Array initializer of fetchl23 peripheral base pointers */
  #define fetchl23_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL23 }
  /** Array initializer of fetchl23 peripheral base addresses */
  #define fetchl23_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL23_BASE_NS }
  /** Array initializer of fetchl23 peripheral base pointers */
  #define fetchl23_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL23_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL23 base address */
  #define DISPLAY__SEERIS__FETCHL23_BASE           (0x4B5D01F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHL23 base pointer */
  #define DISPLAY__SEERIS__FETCHL23                ((fetchl23_Type *)DISPLAY__SEERIS__FETCHL23_BASE)
  /** Array initializer of fetchl23 peripheral base addresses */
  #define fetchl23_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL23_BASE }
  /** Array initializer of fetchl23 peripheral base pointers */
  #define fetchl23_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL23 }
#endif

/* fetchl24 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL24 base address */
  #define DISPLAY__SEERIS__FETCHL24_BASE           (0x5B5D0200u)
  /** Peripheral DISPLAY__SEERIS__FETCHL24 base address */
  #define DISPLAY__SEERIS__FETCHL24_BASE_NS        (0x4B5D0200u)
  /** Peripheral DISPLAY__SEERIS__FETCHL24 base pointer */
  #define DISPLAY__SEERIS__FETCHL24                ((fetchl24_Type *)DISPLAY__SEERIS__FETCHL24_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL24 base pointer */
  #define DISPLAY__SEERIS__FETCHL24_NS             ((fetchl24_Type *)DISPLAY__SEERIS__FETCHL24_BASE_NS)
  /** Array initializer of fetchl24 peripheral base addresses */
  #define fetchl24_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL24_BASE }
  /** Array initializer of fetchl24 peripheral base pointers */
  #define fetchl24_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL24 }
  /** Array initializer of fetchl24 peripheral base addresses */
  #define fetchl24_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL24_BASE_NS }
  /** Array initializer of fetchl24 peripheral base pointers */
  #define fetchl24_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL24_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL24 base address */
  #define DISPLAY__SEERIS__FETCHL24_BASE           (0x4B5D0200u)
  /** Peripheral DISPLAY__SEERIS__FETCHL24 base pointer */
  #define DISPLAY__SEERIS__FETCHL24                ((fetchl24_Type *)DISPLAY__SEERIS__FETCHL24_BASE)
  /** Array initializer of fetchl24 peripheral base addresses */
  #define fetchl24_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL24_BASE }
  /** Array initializer of fetchl24 peripheral base pointers */
  #define fetchl24_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL24 }
#endif

/* fetchl25 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHL25 base address */
  #define DISPLAY__SEERIS__FETCHL25_BASE           (0x5B5D0400u)
  /** Peripheral DISPLAY__SEERIS__FETCHL25 base address */
  #define DISPLAY__SEERIS__FETCHL25_BASE_NS        (0x4B5D0400u)
  /** Peripheral DISPLAY__SEERIS__FETCHL25 base pointer */
  #define DISPLAY__SEERIS__FETCHL25                ((fetchl25_Type *)DISPLAY__SEERIS__FETCHL25_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHL25 base pointer */
  #define DISPLAY__SEERIS__FETCHL25_NS             ((fetchl25_Type *)DISPLAY__SEERIS__FETCHL25_BASE_NS)
  /** Array initializer of fetchl25 peripheral base addresses */
  #define fetchl25_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL25_BASE }
  /** Array initializer of fetchl25 peripheral base pointers */
  #define fetchl25_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL25 }
  /** Array initializer of fetchl25 peripheral base addresses */
  #define fetchl25_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHL25_BASE_NS }
  /** Array initializer of fetchl25 peripheral base pointers */
  #define fetchl25_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHL25_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHL25 base address */
  #define DISPLAY__SEERIS__FETCHL25_BASE           (0x4B5D0400u)
  /** Peripheral DISPLAY__SEERIS__FETCHL25 base pointer */
  #define DISPLAY__SEERIS__FETCHL25                ((fetchl25_Type *)DISPLAY__SEERIS__FETCHL25_BASE)
  /** Array initializer of fetchl25 peripheral base addresses */
  #define fetchl25_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHL25_BASE }
  /** Array initializer of fetchl25 peripheral base pointers */
  #define fetchl25_BASE_PTRS                       { DISPLAY__SEERIS__FETCHL25 }
#endif

/* fetchla1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHLA1 base address */
  #define DISPLAY__SEERIS__FETCHLA1_BASE           (0x5B5C0018u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA1 base address */
  #define DISPLAY__SEERIS__FETCHLA1_BASE_NS        (0x4B5C0018u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA1 base pointer */
  #define DISPLAY__SEERIS__FETCHLA1                ((fetchla1_Type *)DISPLAY__SEERIS__FETCHLA1_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHLA1 base pointer */
  #define DISPLAY__SEERIS__FETCHLA1_NS             ((fetchla1_Type *)DISPLAY__SEERIS__FETCHLA1_BASE_NS)
  /** Array initializer of fetchla1 peripheral base addresses */
  #define fetchla1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA1_BASE }
  /** Array initializer of fetchla1 peripheral base pointers */
  #define fetchla1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA1 }
  /** Array initializer of fetchla1 peripheral base addresses */
  #define fetchla1_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHLA1_BASE_NS }
  /** Array initializer of fetchla1 peripheral base pointers */
  #define fetchla1_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHLA1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHLA1 base address */
  #define DISPLAY__SEERIS__FETCHLA1_BASE           (0x4B5C0018u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA1 base pointer */
  #define DISPLAY__SEERIS__FETCHLA1                ((fetchla1_Type *)DISPLAY__SEERIS__FETCHLA1_BASE)
  /** Array initializer of fetchla1 peripheral base addresses */
  #define fetchla1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA1_BASE }
  /** Array initializer of fetchla1 peripheral base pointers */
  #define fetchla1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA1 }
#endif

/* fetchla2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHLA2 base address */
  #define DISPLAY__SEERIS__FETCHLA2_BASE           (0x5B5C0050u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA2 base address */
  #define DISPLAY__SEERIS__FETCHLA2_BASE_NS        (0x4B5C0050u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA2 base pointer */
  #define DISPLAY__SEERIS__FETCHLA2                ((fetchla2_Type *)DISPLAY__SEERIS__FETCHLA2_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHLA2 base pointer */
  #define DISPLAY__SEERIS__FETCHLA2_NS             ((fetchla2_Type *)DISPLAY__SEERIS__FETCHLA2_BASE_NS)
  /** Array initializer of fetchla2 peripheral base addresses */
  #define fetchla2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA2_BASE }
  /** Array initializer of fetchla2 peripheral base pointers */
  #define fetchla2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA2 }
  /** Array initializer of fetchla2 peripheral base addresses */
  #define fetchla2_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHLA2_BASE_NS }
  /** Array initializer of fetchla2 peripheral base pointers */
  #define fetchla2_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHLA2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHLA2 base address */
  #define DISPLAY__SEERIS__FETCHLA2_BASE           (0x4B5C0050u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA2 base pointer */
  #define DISPLAY__SEERIS__FETCHLA2                ((fetchla2_Type *)DISPLAY__SEERIS__FETCHLA2_BASE)
  /** Array initializer of fetchla2 peripheral base addresses */
  #define fetchla2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA2_BASE }
  /** Array initializer of fetchla2 peripheral base pointers */
  #define fetchla2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA2 }
#endif

/* fetchla3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHLA3 base address */
  #define DISPLAY__SEERIS__FETCHLA3_BASE           (0x5B5C0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA3 base address */
  #define DISPLAY__SEERIS__FETCHLA3_BASE_NS        (0x4B5C0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA3 base pointer */
  #define DISPLAY__SEERIS__FETCHLA3                ((fetchla3_Type *)DISPLAY__SEERIS__FETCHLA3_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHLA3 base pointer */
  #define DISPLAY__SEERIS__FETCHLA3_NS             ((fetchla3_Type *)DISPLAY__SEERIS__FETCHLA3_BASE_NS)
  /** Array initializer of fetchla3 peripheral base addresses */
  #define fetchla3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA3_BASE }
  /** Array initializer of fetchla3 peripheral base pointers */
  #define fetchla3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA3 }
  /** Array initializer of fetchla3 peripheral base addresses */
  #define fetchla3_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHLA3_BASE_NS }
  /** Array initializer of fetchla3 peripheral base pointers */
  #define fetchla3_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHLA3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHLA3 base address */
  #define DISPLAY__SEERIS__FETCHLA3_BASE           (0x4B5C0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA3 base pointer */
  #define DISPLAY__SEERIS__FETCHLA3                ((fetchla3_Type *)DISPLAY__SEERIS__FETCHLA3_BASE)
  /** Array initializer of fetchla3 peripheral base addresses */
  #define fetchla3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA3_BASE }
  /** Array initializer of fetchla3 peripheral base pointers */
  #define fetchla3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA3 }
#endif

/* fetchla4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHLA4 base address */
  #define DISPLAY__SEERIS__FETCHLA4_BASE           (0x5B5C00C0u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA4 base address */
  #define DISPLAY__SEERIS__FETCHLA4_BASE_NS        (0x4B5C00C0u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA4 base pointer */
  #define DISPLAY__SEERIS__FETCHLA4                ((fetchla4_Type *)DISPLAY__SEERIS__FETCHLA4_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHLA4 base pointer */
  #define DISPLAY__SEERIS__FETCHLA4_NS             ((fetchla4_Type *)DISPLAY__SEERIS__FETCHLA4_BASE_NS)
  /** Array initializer of fetchla4 peripheral base addresses */
  #define fetchla4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA4_BASE }
  /** Array initializer of fetchla4 peripheral base pointers */
  #define fetchla4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA4 }
  /** Array initializer of fetchla4 peripheral base addresses */
  #define fetchla4_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHLA4_BASE_NS }
  /** Array initializer of fetchla4 peripheral base pointers */
  #define fetchla4_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHLA4_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHLA4 base address */
  #define DISPLAY__SEERIS__FETCHLA4_BASE           (0x4B5C00C0u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA4 base pointer */
  #define DISPLAY__SEERIS__FETCHLA4                ((fetchla4_Type *)DISPLAY__SEERIS__FETCHLA4_BASE)
  /** Array initializer of fetchla4 peripheral base addresses */
  #define fetchla4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA4_BASE }
  /** Array initializer of fetchla4 peripheral base pointers */
  #define fetchla4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA4 }
#endif

/* fetchla5 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHLA5 base address */
  #define DISPLAY__SEERIS__FETCHLA5_BASE           (0x5B5C00F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA5 base address */
  #define DISPLAY__SEERIS__FETCHLA5_BASE_NS        (0x4B5C00F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA5 base pointer */
  #define DISPLAY__SEERIS__FETCHLA5                ((fetchla5_Type *)DISPLAY__SEERIS__FETCHLA5_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHLA5 base pointer */
  #define DISPLAY__SEERIS__FETCHLA5_NS             ((fetchla5_Type *)DISPLAY__SEERIS__FETCHLA5_BASE_NS)
  /** Array initializer of fetchla5 peripheral base addresses */
  #define fetchla5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA5_BASE }
  /** Array initializer of fetchla5 peripheral base pointers */
  #define fetchla5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA5 }
  /** Array initializer of fetchla5 peripheral base addresses */
  #define fetchla5_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHLA5_BASE_NS }
  /** Array initializer of fetchla5 peripheral base pointers */
  #define fetchla5_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHLA5_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHLA5 base address */
  #define DISPLAY__SEERIS__FETCHLA5_BASE           (0x4B5C00F8u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA5 base pointer */
  #define DISPLAY__SEERIS__FETCHLA5                ((fetchla5_Type *)DISPLAY__SEERIS__FETCHLA5_BASE)
  /** Array initializer of fetchla5 peripheral base addresses */
  #define fetchla5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA5_BASE }
  /** Array initializer of fetchla5 peripheral base pointers */
  #define fetchla5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA5 }
#endif

/* fetchla6 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHLA6 base address */
  #define DISPLAY__SEERIS__FETCHLA6_BASE           (0x5B5C0130u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA6 base address */
  #define DISPLAY__SEERIS__FETCHLA6_BASE_NS        (0x4B5C0130u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA6 base pointer */
  #define DISPLAY__SEERIS__FETCHLA6                ((fetchla6_Type *)DISPLAY__SEERIS__FETCHLA6_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHLA6 base pointer */
  #define DISPLAY__SEERIS__FETCHLA6_NS             ((fetchla6_Type *)DISPLAY__SEERIS__FETCHLA6_BASE_NS)
  /** Array initializer of fetchla6 peripheral base addresses */
  #define fetchla6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA6_BASE }
  /** Array initializer of fetchla6 peripheral base pointers */
  #define fetchla6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA6 }
  /** Array initializer of fetchla6 peripheral base addresses */
  #define fetchla6_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHLA6_BASE_NS }
  /** Array initializer of fetchla6 peripheral base pointers */
  #define fetchla6_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHLA6_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHLA6 base address */
  #define DISPLAY__SEERIS__FETCHLA6_BASE           (0x4B5C0130u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA6 base pointer */
  #define DISPLAY__SEERIS__FETCHLA6                ((fetchla6_Type *)DISPLAY__SEERIS__FETCHLA6_BASE)
  /** Array initializer of fetchla6 peripheral base addresses */
  #define fetchla6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA6_BASE }
  /** Array initializer of fetchla6 peripheral base pointers */
  #define fetchla6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA6 }
#endif

/* fetchla7 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHLA7 base address */
  #define DISPLAY__SEERIS__FETCHLA7_BASE           (0x5B5C0168u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA7 base address */
  #define DISPLAY__SEERIS__FETCHLA7_BASE_NS        (0x4B5C0168u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA7 base pointer */
  #define DISPLAY__SEERIS__FETCHLA7                ((fetchla7_Type *)DISPLAY__SEERIS__FETCHLA7_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHLA7 base pointer */
  #define DISPLAY__SEERIS__FETCHLA7_NS             ((fetchla7_Type *)DISPLAY__SEERIS__FETCHLA7_BASE_NS)
  /** Array initializer of fetchla7 peripheral base addresses */
  #define fetchla7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA7_BASE }
  /** Array initializer of fetchla7 peripheral base pointers */
  #define fetchla7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA7 }
  /** Array initializer of fetchla7 peripheral base addresses */
  #define fetchla7_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHLA7_BASE_NS }
  /** Array initializer of fetchla7 peripheral base pointers */
  #define fetchla7_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHLA7_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHLA7 base address */
  #define DISPLAY__SEERIS__FETCHLA7_BASE           (0x4B5C0168u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA7 base pointer */
  #define DISPLAY__SEERIS__FETCHLA7                ((fetchla7_Type *)DISPLAY__SEERIS__FETCHLA7_BASE)
  /** Array initializer of fetchla7 peripheral base addresses */
  #define fetchla7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA7_BASE }
  /** Array initializer of fetchla7 peripheral base pointers */
  #define fetchla7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA7 }
#endif

/* fetchla8 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHLA8 base address */
  #define DISPLAY__SEERIS__FETCHLA8_BASE           (0x5B5C01A0u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA8 base address */
  #define DISPLAY__SEERIS__FETCHLA8_BASE_NS        (0x4B5C01A0u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA8 base pointer */
  #define DISPLAY__SEERIS__FETCHLA8                ((fetchla8_Type *)DISPLAY__SEERIS__FETCHLA8_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHLA8 base pointer */
  #define DISPLAY__SEERIS__FETCHLA8_NS             ((fetchla8_Type *)DISPLAY__SEERIS__FETCHLA8_BASE_NS)
  /** Array initializer of fetchla8 peripheral base addresses */
  #define fetchla8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA8_BASE }
  /** Array initializer of fetchla8 peripheral base pointers */
  #define fetchla8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA8 }
  /** Array initializer of fetchla8 peripheral base addresses */
  #define fetchla8_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHLA8_BASE_NS }
  /** Array initializer of fetchla8 peripheral base pointers */
  #define fetchla8_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHLA8_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHLA8 base address */
  #define DISPLAY__SEERIS__FETCHLA8_BASE           (0x4B5C01A0u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA8 base pointer */
  #define DISPLAY__SEERIS__FETCHLA8                ((fetchla8_Type *)DISPLAY__SEERIS__FETCHLA8_BASE)
  /** Array initializer of fetchla8 peripheral base addresses */
  #define fetchla8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA8_BASE }
  /** Array initializer of fetchla8 peripheral base pointers */
  #define fetchla8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA8 }
#endif

/* fetchla9 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHLA9 base address */
  #define DISPLAY__SEERIS__FETCHLA9_BASE           (0x5B5C01D8u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA9 base address */
  #define DISPLAY__SEERIS__FETCHLA9_BASE_NS        (0x4B5C01D8u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA9 base pointer */
  #define DISPLAY__SEERIS__FETCHLA9                ((fetchla9_Type *)DISPLAY__SEERIS__FETCHLA9_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHLA9 base pointer */
  #define DISPLAY__SEERIS__FETCHLA9_NS             ((fetchla9_Type *)DISPLAY__SEERIS__FETCHLA9_BASE_NS)
  /** Array initializer of fetchla9 peripheral base addresses */
  #define fetchla9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA9_BASE }
  /** Array initializer of fetchla9 peripheral base pointers */
  #define fetchla9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA9 }
  /** Array initializer of fetchla9 peripheral base addresses */
  #define fetchla9_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHLA9_BASE_NS }
  /** Array initializer of fetchla9 peripheral base pointers */
  #define fetchla9_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHLA9_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHLA9 base address */
  #define DISPLAY__SEERIS__FETCHLA9_BASE           (0x4B5C01D8u)
  /** Peripheral DISPLAY__SEERIS__FETCHLA9 base pointer */
  #define DISPLAY__SEERIS__FETCHLA9                ((fetchla9_Type *)DISPLAY__SEERIS__FETCHLA9_BASE)
  /** Array initializer of fetchla9 peripheral base addresses */
  #define fetchla9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLA9_BASE }
  /** Array initializer of fetchla9 peripheral base pointers */
  #define fetchla9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLA9 }
#endif

/* fetchlay - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHLAY base address */
  #define DISPLAY__SEERIS__FETCHLAY_BASE           (0x5B5C0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHLAY base address */
  #define DISPLAY__SEERIS__FETCHLAY_BASE_NS        (0x4B5C0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHLAY base pointer */
  #define DISPLAY__SEERIS__FETCHLAY                ((fetchlay_Type *)DISPLAY__SEERIS__FETCHLAY_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHLAY base pointer */
  #define DISPLAY__SEERIS__FETCHLAY_NS             ((fetchlay_Type *)DISPLAY__SEERIS__FETCHLAY_BASE_NS)
  /** Array initializer of fetchlay peripheral base addresses */
  #define fetchlay_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLAY_BASE }
  /** Array initializer of fetchlay peripheral base pointers */
  #define fetchlay_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLAY }
  /** Array initializer of fetchlay peripheral base addresses */
  #define fetchlay_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHLAY_BASE_NS }
  /** Array initializer of fetchlay peripheral base pointers */
  #define fetchlay_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHLAY_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHLAY base address */
  #define DISPLAY__SEERIS__FETCHLAY_BASE           (0x4B5C0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHLAY base pointer */
  #define DISPLAY__SEERIS__FETCHLAY                ((fetchlay_Type *)DISPLAY__SEERIS__FETCHLAY_BASE)
  /** Array initializer of fetchlay peripheral base addresses */
  #define fetchlay_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHLAY_BASE }
  /** Array initializer of fetchlay peripheral base pointers */
  #define fetchlay_BASE_PTRS                       { DISPLAY__SEERIS__FETCHLAY }
#endif

/* fetchr10 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHR10 base address */
  #define DISPLAY__SEERIS__FETCHR10_BASE           (0x5B484000u)
  /** Peripheral DISPLAY__SEERIS__FETCHR10 base address */
  #define DISPLAY__SEERIS__FETCHR10_BASE_NS        (0x4B484000u)
  /** Peripheral DISPLAY__SEERIS__FETCHR10 base pointer */
  #define DISPLAY__SEERIS__FETCHR10                ((fetchr10_Type *)DISPLAY__SEERIS__FETCHR10_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHR10 base pointer */
  #define DISPLAY__SEERIS__FETCHR10_NS             ((fetchr10_Type *)DISPLAY__SEERIS__FETCHR10_BASE_NS)
  /** Array initializer of fetchr10 peripheral base addresses */
  #define fetchr10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHR10_BASE }
  /** Array initializer of fetchr10 peripheral base pointers */
  #define fetchr10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHR10 }
  /** Array initializer of fetchr10 peripheral base addresses */
  #define fetchr10_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHR10_BASE_NS }
  /** Array initializer of fetchr10 peripheral base pointers */
  #define fetchr10_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHR10_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHR10 base address */
  #define DISPLAY__SEERIS__FETCHR10_BASE           (0x4B484000u)
  /** Peripheral DISPLAY__SEERIS__FETCHR10 base pointer */
  #define DISPLAY__SEERIS__FETCHR10                ((fetchr10_Type *)DISPLAY__SEERIS__FETCHR10_BASE)
  /** Array initializer of fetchr10 peripheral base addresses */
  #define fetchr10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHR10_BASE }
  /** Array initializer of fetchr10 peripheral base pointers */
  #define fetchr10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHR10 }
#endif

/* fetchr9c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHR9C base address */
  #define DISPLAY__SEERIS__FETCHR9C_BASE           (0x5B486000u)
  /** Peripheral DISPLAY__SEERIS__FETCHR9C base address */
  #define DISPLAY__SEERIS__FETCHR9C_BASE_NS        (0x4B486000u)
  /** Peripheral DISPLAY__SEERIS__FETCHR9C base pointer */
  #define DISPLAY__SEERIS__FETCHR9C                ((fetchr9c_Type *)DISPLAY__SEERIS__FETCHR9C_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHR9C base pointer */
  #define DISPLAY__SEERIS__FETCHR9C_NS             ((fetchr9c_Type *)DISPLAY__SEERIS__FETCHR9C_BASE_NS)
  /** Array initializer of fetchr9c peripheral base addresses */
  #define fetchr9c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHR9C_BASE }
  /** Array initializer of fetchr9c peripheral base pointers */
  #define fetchr9c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHR9C }
  /** Array initializer of fetchr9c peripheral base addresses */
  #define fetchr9c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHR9C_BASE_NS }
  /** Array initializer of fetchr9c peripheral base pointers */
  #define fetchr9c_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHR9C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHR9C base address */
  #define DISPLAY__SEERIS__FETCHR9C_BASE           (0x4B486000u)
  /** Peripheral DISPLAY__SEERIS__FETCHR9C base pointer */
  #define DISPLAY__SEERIS__FETCHR9C                ((fetchr9c_Type *)DISPLAY__SEERIS__FETCHR9C_BASE)
  /** Array initializer of fetchr9c peripheral base addresses */
  #define fetchr9c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHR9C_BASE }
  /** Array initializer of fetchr9c peripheral base pointers */
  #define fetchr9c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHR9C }
#endif

/* fetchro1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHRO1 base address */
  #define DISPLAY__SEERIS__FETCHRO1_BASE           (0x5B480020u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO1 base address */
  #define DISPLAY__SEERIS__FETCHRO1_BASE_NS        (0x4B480020u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO1 base pointer */
  #define DISPLAY__SEERIS__FETCHRO1                ((fetchro1_Type *)DISPLAY__SEERIS__FETCHRO1_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHRO1 base pointer */
  #define DISPLAY__SEERIS__FETCHRO1_NS             ((fetchro1_Type *)DISPLAY__SEERIS__FETCHRO1_BASE_NS)
  /** Array initializer of fetchro1 peripheral base addresses */
  #define fetchro1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO1_BASE }
  /** Array initializer of fetchro1 peripheral base pointers */
  #define fetchro1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO1 }
  /** Array initializer of fetchro1 peripheral base addresses */
  #define fetchro1_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHRO1_BASE_NS }
  /** Array initializer of fetchro1 peripheral base pointers */
  #define fetchro1_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHRO1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHRO1 base address */
  #define DISPLAY__SEERIS__FETCHRO1_BASE           (0x4B480020u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO1 base pointer */
  #define DISPLAY__SEERIS__FETCHRO1                ((fetchro1_Type *)DISPLAY__SEERIS__FETCHRO1_BASE)
  /** Array initializer of fetchro1 peripheral base addresses */
  #define fetchro1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO1_BASE }
  /** Array initializer of fetchro1 peripheral base pointers */
  #define fetchro1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO1 }
#endif

/* fetchro2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHRO2 base address */
  #define DISPLAY__SEERIS__FETCHRO2_BASE           (0x5B480058u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO2 base address */
  #define DISPLAY__SEERIS__FETCHRO2_BASE_NS        (0x4B480058u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO2 base pointer */
  #define DISPLAY__SEERIS__FETCHRO2                ((fetchro2_Type *)DISPLAY__SEERIS__FETCHRO2_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHRO2 base pointer */
  #define DISPLAY__SEERIS__FETCHRO2_NS             ((fetchro2_Type *)DISPLAY__SEERIS__FETCHRO2_BASE_NS)
  /** Array initializer of fetchro2 peripheral base addresses */
  #define fetchro2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO2_BASE }
  /** Array initializer of fetchro2 peripheral base pointers */
  #define fetchro2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO2 }
  /** Array initializer of fetchro2 peripheral base addresses */
  #define fetchro2_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHRO2_BASE_NS }
  /** Array initializer of fetchro2 peripheral base pointers */
  #define fetchro2_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHRO2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHRO2 base address */
  #define DISPLAY__SEERIS__FETCHRO2_BASE           (0x4B480058u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO2 base pointer */
  #define DISPLAY__SEERIS__FETCHRO2                ((fetchro2_Type *)DISPLAY__SEERIS__FETCHRO2_BASE)
  /** Array initializer of fetchro2 peripheral base addresses */
  #define fetchro2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO2_BASE }
  /** Array initializer of fetchro2 peripheral base pointers */
  #define fetchro2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO2 }
#endif

/* fetchro3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHRO3 base address */
  #define DISPLAY__SEERIS__FETCHRO3_BASE           (0x5B4800A0u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO3 base address */
  #define DISPLAY__SEERIS__FETCHRO3_BASE_NS        (0x4B4800A0u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO3 base pointer */
  #define DISPLAY__SEERIS__FETCHRO3                ((fetchro3_Type *)DISPLAY__SEERIS__FETCHRO3_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHRO3 base pointer */
  #define DISPLAY__SEERIS__FETCHRO3_NS             ((fetchro3_Type *)DISPLAY__SEERIS__FETCHRO3_BASE_NS)
  /** Array initializer of fetchro3 peripheral base addresses */
  #define fetchro3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO3_BASE }
  /** Array initializer of fetchro3 peripheral base pointers */
  #define fetchro3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO3 }
  /** Array initializer of fetchro3 peripheral base addresses */
  #define fetchro3_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHRO3_BASE_NS }
  /** Array initializer of fetchro3 peripheral base pointers */
  #define fetchro3_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHRO3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHRO3 base address */
  #define DISPLAY__SEERIS__FETCHRO3_BASE           (0x4B4800A0u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO3 base pointer */
  #define DISPLAY__SEERIS__FETCHRO3                ((fetchro3_Type *)DISPLAY__SEERIS__FETCHRO3_BASE)
  /** Array initializer of fetchro3 peripheral base addresses */
  #define fetchro3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO3_BASE }
  /** Array initializer of fetchro3 peripheral base pointers */
  #define fetchro3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO3 }
#endif

/* fetchro4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHRO4 base address */
  #define DISPLAY__SEERIS__FETCHRO4_BASE           (0x5B4800B0u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO4 base address */
  #define DISPLAY__SEERIS__FETCHRO4_BASE_NS        (0x4B4800B0u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO4 base pointer */
  #define DISPLAY__SEERIS__FETCHRO4                ((fetchro4_Type *)DISPLAY__SEERIS__FETCHRO4_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHRO4 base pointer */
  #define DISPLAY__SEERIS__FETCHRO4_NS             ((fetchro4_Type *)DISPLAY__SEERIS__FETCHRO4_BASE_NS)
  /** Array initializer of fetchro4 peripheral base addresses */
  #define fetchro4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO4_BASE }
  /** Array initializer of fetchro4 peripheral base pointers */
  #define fetchro4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO4 }
  /** Array initializer of fetchro4 peripheral base addresses */
  #define fetchro4_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHRO4_BASE_NS }
  /** Array initializer of fetchro4 peripheral base pointers */
  #define fetchro4_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHRO4_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHRO4 base address */
  #define DISPLAY__SEERIS__FETCHRO4_BASE           (0x4B4800B0u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO4 base pointer */
  #define DISPLAY__SEERIS__FETCHRO4                ((fetchro4_Type *)DISPLAY__SEERIS__FETCHRO4_BASE)
  /** Array initializer of fetchro4 peripheral base addresses */
  #define fetchro4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO4_BASE }
  /** Array initializer of fetchro4 peripheral base pointers */
  #define fetchro4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO4 }
#endif

/* fetchro5 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHRO5 base address */
  #define DISPLAY__SEERIS__FETCHRO5_BASE           (0x5B480100u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO5 base address */
  #define DISPLAY__SEERIS__FETCHRO5_BASE_NS        (0x4B480100u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO5 base pointer */
  #define DISPLAY__SEERIS__FETCHRO5                ((fetchro5_Type *)DISPLAY__SEERIS__FETCHRO5_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHRO5 base pointer */
  #define DISPLAY__SEERIS__FETCHRO5_NS             ((fetchro5_Type *)DISPLAY__SEERIS__FETCHRO5_BASE_NS)
  /** Array initializer of fetchro5 peripheral base addresses */
  #define fetchro5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO5_BASE }
  /** Array initializer of fetchro5 peripheral base pointers */
  #define fetchro5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO5 }
  /** Array initializer of fetchro5 peripheral base addresses */
  #define fetchro5_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHRO5_BASE_NS }
  /** Array initializer of fetchro5 peripheral base pointers */
  #define fetchro5_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHRO5_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHRO5 base address */
  #define DISPLAY__SEERIS__FETCHRO5_BASE           (0x4B480100u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO5 base pointer */
  #define DISPLAY__SEERIS__FETCHRO5                ((fetchro5_Type *)DISPLAY__SEERIS__FETCHRO5_BASE)
  /** Array initializer of fetchro5 peripheral base addresses */
  #define fetchro5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO5_BASE }
  /** Array initializer of fetchro5 peripheral base pointers */
  #define fetchro5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO5 }
#endif

/* fetchro6 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHRO6 base address */
  #define DISPLAY__SEERIS__FETCHRO6_BASE           (0x5B480200u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO6 base address */
  #define DISPLAY__SEERIS__FETCHRO6_BASE_NS        (0x4B480200u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO6 base pointer */
  #define DISPLAY__SEERIS__FETCHRO6                ((fetchro6_Type *)DISPLAY__SEERIS__FETCHRO6_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHRO6 base pointer */
  #define DISPLAY__SEERIS__FETCHRO6_NS             ((fetchro6_Type *)DISPLAY__SEERIS__FETCHRO6_BASE_NS)
  /** Array initializer of fetchro6 peripheral base addresses */
  #define fetchro6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO6_BASE }
  /** Array initializer of fetchro6 peripheral base pointers */
  #define fetchro6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO6 }
  /** Array initializer of fetchro6 peripheral base addresses */
  #define fetchro6_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHRO6_BASE_NS }
  /** Array initializer of fetchro6 peripheral base pointers */
  #define fetchro6_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHRO6_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHRO6 base address */
  #define DISPLAY__SEERIS__FETCHRO6_BASE           (0x4B480200u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO6 base pointer */
  #define DISPLAY__SEERIS__FETCHRO6                ((fetchro6_Type *)DISPLAY__SEERIS__FETCHRO6_BASE)
  /** Array initializer of fetchro6 peripheral base addresses */
  #define fetchro6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO6_BASE }
  /** Array initializer of fetchro6 peripheral base pointers */
  #define fetchro6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO6 }
#endif

/* fetchro7 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHRO7 base address */
  #define DISPLAY__SEERIS__FETCHRO7_BASE           (0x5B480400u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO7 base address */
  #define DISPLAY__SEERIS__FETCHRO7_BASE_NS        (0x4B480400u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO7 base pointer */
  #define DISPLAY__SEERIS__FETCHRO7                ((fetchro7_Type *)DISPLAY__SEERIS__FETCHRO7_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHRO7 base pointer */
  #define DISPLAY__SEERIS__FETCHRO7_NS             ((fetchro7_Type *)DISPLAY__SEERIS__FETCHRO7_BASE_NS)
  /** Array initializer of fetchro7 peripheral base addresses */
  #define fetchro7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO7_BASE }
  /** Array initializer of fetchro7 peripheral base pointers */
  #define fetchro7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO7 }
  /** Array initializer of fetchro7 peripheral base addresses */
  #define fetchro7_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHRO7_BASE_NS }
  /** Array initializer of fetchro7 peripheral base pointers */
  #define fetchro7_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHRO7_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHRO7 base address */
  #define DISPLAY__SEERIS__FETCHRO7_BASE           (0x4B480400u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO7 base pointer */
  #define DISPLAY__SEERIS__FETCHRO7                ((fetchro7_Type *)DISPLAY__SEERIS__FETCHRO7_BASE)
  /** Array initializer of fetchro7 peripheral base addresses */
  #define fetchro7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO7_BASE }
  /** Array initializer of fetchro7 peripheral base pointers */
  #define fetchro7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO7 }
#endif

/* fetchro8 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHRO8 base address */
  #define DISPLAY__SEERIS__FETCHRO8_BASE           (0x5B480600u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO8 base address */
  #define DISPLAY__SEERIS__FETCHRO8_BASE_NS        (0x4B480600u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO8 base pointer */
  #define DISPLAY__SEERIS__FETCHRO8                ((fetchro8_Type *)DISPLAY__SEERIS__FETCHRO8_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHRO8 base pointer */
  #define DISPLAY__SEERIS__FETCHRO8_NS             ((fetchro8_Type *)DISPLAY__SEERIS__FETCHRO8_BASE_NS)
  /** Array initializer of fetchro8 peripheral base addresses */
  #define fetchro8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO8_BASE }
  /** Array initializer of fetchro8 peripheral base pointers */
  #define fetchro8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO8 }
  /** Array initializer of fetchro8 peripheral base addresses */
  #define fetchro8_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHRO8_BASE_NS }
  /** Array initializer of fetchro8 peripheral base pointers */
  #define fetchro8_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHRO8_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHRO8 base address */
  #define DISPLAY__SEERIS__FETCHRO8_BASE           (0x4B480600u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO8 base pointer */
  #define DISPLAY__SEERIS__FETCHRO8                ((fetchro8_Type *)DISPLAY__SEERIS__FETCHRO8_BASE)
  /** Array initializer of fetchro8 peripheral base addresses */
  #define fetchro8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO8_BASE }
  /** Array initializer of fetchro8 peripheral base pointers */
  #define fetchro8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO8 }
#endif

/* fetchro9 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHRO9 base address */
  #define DISPLAY__SEERIS__FETCHRO9_BASE           (0x5B482000u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO9 base address */
  #define DISPLAY__SEERIS__FETCHRO9_BASE_NS        (0x4B482000u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO9 base pointer */
  #define DISPLAY__SEERIS__FETCHRO9                ((fetchro9_Type *)DISPLAY__SEERIS__FETCHRO9_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHRO9 base pointer */
  #define DISPLAY__SEERIS__FETCHRO9_NS             ((fetchro9_Type *)DISPLAY__SEERIS__FETCHRO9_BASE_NS)
  /** Array initializer of fetchro9 peripheral base addresses */
  #define fetchro9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO9_BASE }
  /** Array initializer of fetchro9 peripheral base pointers */
  #define fetchro9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO9 }
  /** Array initializer of fetchro9 peripheral base addresses */
  #define fetchro9_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHRO9_BASE_NS }
  /** Array initializer of fetchro9 peripheral base pointers */
  #define fetchro9_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHRO9_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHRO9 base address */
  #define DISPLAY__SEERIS__FETCHRO9_BASE           (0x4B482000u)
  /** Peripheral DISPLAY__SEERIS__FETCHRO9 base pointer */
  #define DISPLAY__SEERIS__FETCHRO9                ((fetchro9_Type *)DISPLAY__SEERIS__FETCHRO9_BASE)
  /** Array initializer of fetchro9 peripheral base addresses */
  #define fetchro9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHRO9_BASE }
  /** Array initializer of fetchro9 peripheral base pointers */
  #define fetchro9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHRO9 }
#endif

/* fetchrot - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHROT base address */
  #define DISPLAY__SEERIS__FETCHROT_BASE           (0x5B480000u)
  /** Peripheral DISPLAY__SEERIS__FETCHROT base address */
  #define DISPLAY__SEERIS__FETCHROT_BASE_NS        (0x4B480000u)
  /** Peripheral DISPLAY__SEERIS__FETCHROT base pointer */
  #define DISPLAY__SEERIS__FETCHROT                ((fetchrot_Type *)DISPLAY__SEERIS__FETCHROT_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHROT base pointer */
  #define DISPLAY__SEERIS__FETCHROT_NS             ((fetchrot_Type *)DISPLAY__SEERIS__FETCHROT_BASE_NS)
  /** Array initializer of fetchrot peripheral base addresses */
  #define fetchrot_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHROT_BASE }
  /** Array initializer of fetchrot peripheral base pointers */
  #define fetchrot_BASE_PTRS                       { DISPLAY__SEERIS__FETCHROT }
  /** Array initializer of fetchrot peripheral base addresses */
  #define fetchrot_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHROT_BASE_NS }
  /** Array initializer of fetchrot peripheral base pointers */
  #define fetchrot_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHROT_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHROT base address */
  #define DISPLAY__SEERIS__FETCHROT_BASE           (0x4B480000u)
  /** Peripheral DISPLAY__SEERIS__FETCHROT base pointer */
  #define DISPLAY__SEERIS__FETCHROT                ((fetchrot_Type *)DISPLAY__SEERIS__FETCHROT_BASE)
  /** Array initializer of fetchrot peripheral base addresses */
  #define fetchrot_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHROT_BASE }
  /** Array initializer of fetchrot peripheral base pointers */
  #define fetchrot_BASE_PTRS                       { DISPLAY__SEERIS__FETCHROT }
#endif

/* fetchy0c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHY0C base address */
  #define DISPLAY__SEERIS__FETCHY0C_BASE           (0x5B5F1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY0C base address */
  #define DISPLAY__SEERIS__FETCHY0C_BASE_NS        (0x4B5F1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY0C base pointer */
  #define DISPLAY__SEERIS__FETCHY0C                ((fetchy0c_Type *)DISPLAY__SEERIS__FETCHY0C_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHY0C base pointer */
  #define DISPLAY__SEERIS__FETCHY0C_NS             ((fetchy0c_Type *)DISPLAY__SEERIS__FETCHY0C_BASE_NS)
  /** Array initializer of fetchy0c peripheral base addresses */
  #define fetchy0c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY0C_BASE }
  /** Array initializer of fetchy0c peripheral base pointers */
  #define fetchy0c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY0C }
  /** Array initializer of fetchy0c peripheral base addresses */
  #define fetchy0c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHY0C_BASE_NS }
  /** Array initializer of fetchy0c peripheral base pointers */
  #define fetchy0c_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHY0C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHY0C base address */
  #define DISPLAY__SEERIS__FETCHY0C_BASE           (0x4B5F1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY0C base pointer */
  #define DISPLAY__SEERIS__FETCHY0C                ((fetchy0c_Type *)DISPLAY__SEERIS__FETCHY0C_BASE)
  /** Array initializer of fetchy0c peripheral base addresses */
  #define fetchy0c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY0C_BASE }
  /** Array initializer of fetchy0c peripheral base pointers */
  #define fetchy0c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY0C }
#endif

/* fetchy10 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHY10 base address */
  #define DISPLAY__SEERIS__FETCHY10_BASE           (0x5B610000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY10 base address */
  #define DISPLAY__SEERIS__FETCHY10_BASE_NS        (0x4B610000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY10 base pointer */
  #define DISPLAY__SEERIS__FETCHY10                ((fetchy10_Type *)DISPLAY__SEERIS__FETCHY10_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHY10 base pointer */
  #define DISPLAY__SEERIS__FETCHY10_NS             ((fetchy10_Type *)DISPLAY__SEERIS__FETCHY10_BASE_NS)
  /** Array initializer of fetchy10 peripheral base addresses */
  #define fetchy10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY10_BASE }
  /** Array initializer of fetchy10 peripheral base pointers */
  #define fetchy10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY10 }
  /** Array initializer of fetchy10 peripheral base addresses */
  #define fetchy10_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHY10_BASE_NS }
  /** Array initializer of fetchy10 peripheral base pointers */
  #define fetchy10_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHY10_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHY10 base address */
  #define DISPLAY__SEERIS__FETCHY10_BASE           (0x4B610000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY10 base pointer */
  #define DISPLAY__SEERIS__FETCHY10                ((fetchy10_Type *)DISPLAY__SEERIS__FETCHY10_BASE)
  /** Array initializer of fetchy10 peripheral base addresses */
  #define fetchy10_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY10_BASE }
  /** Array initializer of fetchy10 peripheral base pointers */
  #define fetchy10_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY10 }
#endif

/* fetchy11 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHY11 base address */
  #define DISPLAY__SEERIS__FETCHY11_BASE           (0x5B610028u)
  /** Peripheral DISPLAY__SEERIS__FETCHY11 base address */
  #define DISPLAY__SEERIS__FETCHY11_BASE_NS        (0x4B610028u)
  /** Peripheral DISPLAY__SEERIS__FETCHY11 base pointer */
  #define DISPLAY__SEERIS__FETCHY11                ((fetchy11_Type *)DISPLAY__SEERIS__FETCHY11_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHY11 base pointer */
  #define DISPLAY__SEERIS__FETCHY11_NS             ((fetchy11_Type *)DISPLAY__SEERIS__FETCHY11_BASE_NS)
  /** Array initializer of fetchy11 peripheral base addresses */
  #define fetchy11_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY11_BASE }
  /** Array initializer of fetchy11 peripheral base pointers */
  #define fetchy11_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY11 }
  /** Array initializer of fetchy11 peripheral base addresses */
  #define fetchy11_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHY11_BASE_NS }
  /** Array initializer of fetchy11 peripheral base pointers */
  #define fetchy11_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHY11_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHY11 base address */
  #define DISPLAY__SEERIS__FETCHY11_BASE           (0x4B610028u)
  /** Peripheral DISPLAY__SEERIS__FETCHY11 base pointer */
  #define DISPLAY__SEERIS__FETCHY11                ((fetchy11_Type *)DISPLAY__SEERIS__FETCHY11_BASE)
  /** Array initializer of fetchy11 peripheral base addresses */
  #define fetchy11_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY11_BASE }
  /** Array initializer of fetchy11 peripheral base pointers */
  #define fetchy11_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY11 }
#endif

/* fetchy12 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHY12 base address */
  #define DISPLAY__SEERIS__FETCHY12_BASE           (0x5B610060u)
  /** Peripheral DISPLAY__SEERIS__FETCHY12 base address */
  #define DISPLAY__SEERIS__FETCHY12_BASE_NS        (0x4B610060u)
  /** Peripheral DISPLAY__SEERIS__FETCHY12 base pointer */
  #define DISPLAY__SEERIS__FETCHY12                ((fetchy12_Type *)DISPLAY__SEERIS__FETCHY12_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHY12 base pointer */
  #define DISPLAY__SEERIS__FETCHY12_NS             ((fetchy12_Type *)DISPLAY__SEERIS__FETCHY12_BASE_NS)
  /** Array initializer of fetchy12 peripheral base addresses */
  #define fetchy12_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY12_BASE }
  /** Array initializer of fetchy12 peripheral base pointers */
  #define fetchy12_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY12 }
  /** Array initializer of fetchy12 peripheral base addresses */
  #define fetchy12_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHY12_BASE_NS }
  /** Array initializer of fetchy12 peripheral base pointers */
  #define fetchy12_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHY12_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHY12 base address */
  #define DISPLAY__SEERIS__FETCHY12_BASE           (0x4B610060u)
  /** Peripheral DISPLAY__SEERIS__FETCHY12 base pointer */
  #define DISPLAY__SEERIS__FETCHY12                ((fetchy12_Type *)DISPLAY__SEERIS__FETCHY12_BASE)
  /** Array initializer of fetchy12 peripheral base addresses */
  #define fetchy12_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY12_BASE }
  /** Array initializer of fetchy12 peripheral base pointers */
  #define fetchy12_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY12 }
#endif

/* fetchy13 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHY13 base address */
  #define DISPLAY__SEERIS__FETCHY13_BASE           (0x5B610078u)
  /** Peripheral DISPLAY__SEERIS__FETCHY13 base address */
  #define DISPLAY__SEERIS__FETCHY13_BASE_NS        (0x4B610078u)
  /** Peripheral DISPLAY__SEERIS__FETCHY13 base pointer */
  #define DISPLAY__SEERIS__FETCHY13                ((fetchy13_Type *)DISPLAY__SEERIS__FETCHY13_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHY13 base pointer */
  #define DISPLAY__SEERIS__FETCHY13_NS             ((fetchy13_Type *)DISPLAY__SEERIS__FETCHY13_BASE_NS)
  /** Array initializer of fetchy13 peripheral base addresses */
  #define fetchy13_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY13_BASE }
  /** Array initializer of fetchy13 peripheral base pointers */
  #define fetchy13_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY13 }
  /** Array initializer of fetchy13 peripheral base addresses */
  #define fetchy13_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHY13_BASE_NS }
  /** Array initializer of fetchy13 peripheral base pointers */
  #define fetchy13_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHY13_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHY13 base address */
  #define DISPLAY__SEERIS__FETCHY13_BASE           (0x4B610078u)
  /** Peripheral DISPLAY__SEERIS__FETCHY13 base pointer */
  #define DISPLAY__SEERIS__FETCHY13                ((fetchy13_Type *)DISPLAY__SEERIS__FETCHY13_BASE)
  /** Array initializer of fetchy13 peripheral base addresses */
  #define fetchy13_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY13_BASE }
  /** Array initializer of fetchy13 peripheral base pointers */
  #define fetchy13_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY13 }
#endif

/* fetchy14 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHY14 base address */
  #define DISPLAY__SEERIS__FETCHY14_BASE           (0x5B610088u)
  /** Peripheral DISPLAY__SEERIS__FETCHY14 base address */
  #define DISPLAY__SEERIS__FETCHY14_BASE_NS        (0x4B610088u)
  /** Peripheral DISPLAY__SEERIS__FETCHY14 base pointer */
  #define DISPLAY__SEERIS__FETCHY14                ((fetchy14_Type *)DISPLAY__SEERIS__FETCHY14_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHY14 base pointer */
  #define DISPLAY__SEERIS__FETCHY14_NS             ((fetchy14_Type *)DISPLAY__SEERIS__FETCHY14_BASE_NS)
  /** Array initializer of fetchy14 peripheral base addresses */
  #define fetchy14_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY14_BASE }
  /** Array initializer of fetchy14 peripheral base pointers */
  #define fetchy14_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY14 }
  /** Array initializer of fetchy14 peripheral base addresses */
  #define fetchy14_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHY14_BASE_NS }
  /** Array initializer of fetchy14 peripheral base pointers */
  #define fetchy14_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHY14_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHY14 base address */
  #define DISPLAY__SEERIS__FETCHY14_BASE           (0x4B610088u)
  /** Peripheral DISPLAY__SEERIS__FETCHY14 base pointer */
  #define DISPLAY__SEERIS__FETCHY14                ((fetchy14_Type *)DISPLAY__SEERIS__FETCHY14_BASE)
  /** Array initializer of fetchy14 peripheral base addresses */
  #define fetchy14_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY14_BASE }
  /** Array initializer of fetchy14 peripheral base pointers */
  #define fetchy14_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY14 }
#endif

/* fetchy1c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHY1C base address */
  #define DISPLAY__SEERIS__FETCHY1C_BASE           (0x5B611000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY1C base address */
  #define DISPLAY__SEERIS__FETCHY1C_BASE_NS        (0x4B611000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY1C base pointer */
  #define DISPLAY__SEERIS__FETCHY1C                ((fetchy1c_Type *)DISPLAY__SEERIS__FETCHY1C_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHY1C base pointer */
  #define DISPLAY__SEERIS__FETCHY1C_NS             ((fetchy1c_Type *)DISPLAY__SEERIS__FETCHY1C_BASE_NS)
  /** Array initializer of fetchy1c peripheral base addresses */
  #define fetchy1c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY1C_BASE }
  /** Array initializer of fetchy1c peripheral base pointers */
  #define fetchy1c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY1C }
  /** Array initializer of fetchy1c peripheral base addresses */
  #define fetchy1c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHY1C_BASE_NS }
  /** Array initializer of fetchy1c peripheral base pointers */
  #define fetchy1c_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHY1C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHY1C base address */
  #define DISPLAY__SEERIS__FETCHY1C_BASE           (0x4B611000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY1C base pointer */
  #define DISPLAY__SEERIS__FETCHY1C                ((fetchy1c_Type *)DISPLAY__SEERIS__FETCHY1C_BASE)
  /** Array initializer of fetchy1c peripheral base addresses */
  #define fetchy1c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY1C_BASE }
  /** Array initializer of fetchy1c peripheral base pointers */
  #define fetchy1c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY1C }
#endif

/* fetchy3c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHY3C base address */
  #define DISPLAY__SEERIS__FETCHY3C_BASE           (0x5B5E1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY3C base address */
  #define DISPLAY__SEERIS__FETCHY3C_BASE_NS        (0x4B5E1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY3C base pointer */
  #define DISPLAY__SEERIS__FETCHY3C                ((fetchy3c_Type *)DISPLAY__SEERIS__FETCHY3C_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHY3C base pointer */
  #define DISPLAY__SEERIS__FETCHY3C_NS             ((fetchy3c_Type *)DISPLAY__SEERIS__FETCHY3C_BASE_NS)
  /** Array initializer of fetchy3c peripheral base addresses */
  #define fetchy3c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY3C_BASE }
  /** Array initializer of fetchy3c peripheral base pointers */
  #define fetchy3c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY3C }
  /** Array initializer of fetchy3c peripheral base addresses */
  #define fetchy3c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHY3C_BASE_NS }
  /** Array initializer of fetchy3c peripheral base pointers */
  #define fetchy3c_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHY3C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHY3C base address */
  #define DISPLAY__SEERIS__FETCHY3C_BASE           (0x4B5E1000u)
  /** Peripheral DISPLAY__SEERIS__FETCHY3C base pointer */
  #define DISPLAY__SEERIS__FETCHY3C                ((fetchy3c_Type *)DISPLAY__SEERIS__FETCHY3C_BASE)
  /** Array initializer of fetchy3c peripheral base addresses */
  #define fetchy3c_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHY3C_BASE }
  /** Array initializer of fetchy3c peripheral base pointers */
  #define fetchy3c_BASE_PTRS                       { DISPLAY__SEERIS__FETCHY3C }
#endif

/* fetchyu1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHYU1 base address */
  #define DISPLAY__SEERIS__FETCHYU1_BASE           (0x5B5E0028u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU1 base address */
  #define DISPLAY__SEERIS__FETCHYU1_BASE_NS        (0x4B5E0028u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU1 base pointer */
  #define DISPLAY__SEERIS__FETCHYU1                ((fetchyu1_Type *)DISPLAY__SEERIS__FETCHYU1_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHYU1 base pointer */
  #define DISPLAY__SEERIS__FETCHYU1_NS             ((fetchyu1_Type *)DISPLAY__SEERIS__FETCHYU1_BASE_NS)
  /** Array initializer of fetchyu1 peripheral base addresses */
  #define fetchyu1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU1_BASE }
  /** Array initializer of fetchyu1 peripheral base pointers */
  #define fetchyu1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU1 }
  /** Array initializer of fetchyu1 peripheral base addresses */
  #define fetchyu1_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHYU1_BASE_NS }
  /** Array initializer of fetchyu1 peripheral base pointers */
  #define fetchyu1_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHYU1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHYU1 base address */
  #define DISPLAY__SEERIS__FETCHYU1_BASE           (0x4B5E0028u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU1 base pointer */
  #define DISPLAY__SEERIS__FETCHYU1                ((fetchyu1_Type *)DISPLAY__SEERIS__FETCHYU1_BASE)
  /** Array initializer of fetchyu1 peripheral base addresses */
  #define fetchyu1_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU1_BASE }
  /** Array initializer of fetchyu1 peripheral base pointers */
  #define fetchyu1_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU1 }
#endif

/* fetchyu2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHYU2 base address */
  #define DISPLAY__SEERIS__FETCHYU2_BASE           (0x5B5E0060u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU2 base address */
  #define DISPLAY__SEERIS__FETCHYU2_BASE_NS        (0x4B5E0060u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU2 base pointer */
  #define DISPLAY__SEERIS__FETCHYU2                ((fetchyu2_Type *)DISPLAY__SEERIS__FETCHYU2_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHYU2 base pointer */
  #define DISPLAY__SEERIS__FETCHYU2_NS             ((fetchyu2_Type *)DISPLAY__SEERIS__FETCHYU2_BASE_NS)
  /** Array initializer of fetchyu2 peripheral base addresses */
  #define fetchyu2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU2_BASE }
  /** Array initializer of fetchyu2 peripheral base pointers */
  #define fetchyu2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU2 }
  /** Array initializer of fetchyu2 peripheral base addresses */
  #define fetchyu2_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHYU2_BASE_NS }
  /** Array initializer of fetchyu2 peripheral base pointers */
  #define fetchyu2_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHYU2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHYU2 base address */
  #define DISPLAY__SEERIS__FETCHYU2_BASE           (0x4B5E0060u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU2 base pointer */
  #define DISPLAY__SEERIS__FETCHYU2                ((fetchyu2_Type *)DISPLAY__SEERIS__FETCHYU2_BASE)
  /** Array initializer of fetchyu2 peripheral base addresses */
  #define fetchyu2_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU2_BASE }
  /** Array initializer of fetchyu2 peripheral base pointers */
  #define fetchyu2_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU2 }
#endif

/* fetchyu3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHYU3 base address */
  #define DISPLAY__SEERIS__FETCHYU3_BASE           (0x5B5E0078u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU3 base address */
  #define DISPLAY__SEERIS__FETCHYU3_BASE_NS        (0x4B5E0078u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU3 base pointer */
  #define DISPLAY__SEERIS__FETCHYU3                ((fetchyu3_Type *)DISPLAY__SEERIS__FETCHYU3_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHYU3 base pointer */
  #define DISPLAY__SEERIS__FETCHYU3_NS             ((fetchyu3_Type *)DISPLAY__SEERIS__FETCHYU3_BASE_NS)
  /** Array initializer of fetchyu3 peripheral base addresses */
  #define fetchyu3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU3_BASE }
  /** Array initializer of fetchyu3 peripheral base pointers */
  #define fetchyu3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU3 }
  /** Array initializer of fetchyu3 peripheral base addresses */
  #define fetchyu3_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHYU3_BASE_NS }
  /** Array initializer of fetchyu3 peripheral base pointers */
  #define fetchyu3_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHYU3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHYU3 base address */
  #define DISPLAY__SEERIS__FETCHYU3_BASE           (0x4B5E0078u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU3 base pointer */
  #define DISPLAY__SEERIS__FETCHYU3                ((fetchyu3_Type *)DISPLAY__SEERIS__FETCHYU3_BASE)
  /** Array initializer of fetchyu3 peripheral base addresses */
  #define fetchyu3_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU3_BASE }
  /** Array initializer of fetchyu3 peripheral base pointers */
  #define fetchyu3_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU3 }
#endif

/* fetchyu4 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHYU4 base address */
  #define DISPLAY__SEERIS__FETCHYU4_BASE           (0x5B5E0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU4 base address */
  #define DISPLAY__SEERIS__FETCHYU4_BASE_NS        (0x4B5E0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU4 base pointer */
  #define DISPLAY__SEERIS__FETCHYU4                ((fetchyu4_Type *)DISPLAY__SEERIS__FETCHYU4_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHYU4 base pointer */
  #define DISPLAY__SEERIS__FETCHYU4_NS             ((fetchyu4_Type *)DISPLAY__SEERIS__FETCHYU4_BASE_NS)
  /** Array initializer of fetchyu4 peripheral base addresses */
  #define fetchyu4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU4_BASE }
  /** Array initializer of fetchyu4 peripheral base pointers */
  #define fetchyu4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU4 }
  /** Array initializer of fetchyu4 peripheral base addresses */
  #define fetchyu4_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHYU4_BASE_NS }
  /** Array initializer of fetchyu4 peripheral base pointers */
  #define fetchyu4_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHYU4_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHYU4 base address */
  #define DISPLAY__SEERIS__FETCHYU4_BASE           (0x4B5E0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU4 base pointer */
  #define DISPLAY__SEERIS__FETCHYU4                ((fetchyu4_Type *)DISPLAY__SEERIS__FETCHYU4_BASE)
  /** Array initializer of fetchyu4 peripheral base addresses */
  #define fetchyu4_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU4_BASE }
  /** Array initializer of fetchyu4 peripheral base pointers */
  #define fetchyu4_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU4 }
#endif

/* fetchyu5 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHYU5 base address */
  #define DISPLAY__SEERIS__FETCHYU5_BASE           (0x5B5F0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU5 base address */
  #define DISPLAY__SEERIS__FETCHYU5_BASE_NS        (0x4B5F0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU5 base pointer */
  #define DISPLAY__SEERIS__FETCHYU5                ((fetchyu5_Type *)DISPLAY__SEERIS__FETCHYU5_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHYU5 base pointer */
  #define DISPLAY__SEERIS__FETCHYU5_NS             ((fetchyu5_Type *)DISPLAY__SEERIS__FETCHYU5_BASE_NS)
  /** Array initializer of fetchyu5 peripheral base addresses */
  #define fetchyu5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU5_BASE }
  /** Array initializer of fetchyu5 peripheral base pointers */
  #define fetchyu5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU5 }
  /** Array initializer of fetchyu5 peripheral base addresses */
  #define fetchyu5_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHYU5_BASE_NS }
  /** Array initializer of fetchyu5 peripheral base pointers */
  #define fetchyu5_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHYU5_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHYU5 base address */
  #define DISPLAY__SEERIS__FETCHYU5_BASE           (0x4B5F0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU5 base pointer */
  #define DISPLAY__SEERIS__FETCHYU5                ((fetchyu5_Type *)DISPLAY__SEERIS__FETCHYU5_BASE)
  /** Array initializer of fetchyu5 peripheral base addresses */
  #define fetchyu5_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU5_BASE }
  /** Array initializer of fetchyu5 peripheral base pointers */
  #define fetchyu5_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU5 }
#endif

/* fetchyu6 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHYU6 base address */
  #define DISPLAY__SEERIS__FETCHYU6_BASE           (0x5B5F0028u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU6 base address */
  #define DISPLAY__SEERIS__FETCHYU6_BASE_NS        (0x4B5F0028u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU6 base pointer */
  #define DISPLAY__SEERIS__FETCHYU6                ((fetchyu6_Type *)DISPLAY__SEERIS__FETCHYU6_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHYU6 base pointer */
  #define DISPLAY__SEERIS__FETCHYU6_NS             ((fetchyu6_Type *)DISPLAY__SEERIS__FETCHYU6_BASE_NS)
  /** Array initializer of fetchyu6 peripheral base addresses */
  #define fetchyu6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU6_BASE }
  /** Array initializer of fetchyu6 peripheral base pointers */
  #define fetchyu6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU6 }
  /** Array initializer of fetchyu6 peripheral base addresses */
  #define fetchyu6_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHYU6_BASE_NS }
  /** Array initializer of fetchyu6 peripheral base pointers */
  #define fetchyu6_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHYU6_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHYU6 base address */
  #define DISPLAY__SEERIS__FETCHYU6_BASE           (0x4B5F0028u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU6 base pointer */
  #define DISPLAY__SEERIS__FETCHYU6                ((fetchyu6_Type *)DISPLAY__SEERIS__FETCHYU6_BASE)
  /** Array initializer of fetchyu6 peripheral base addresses */
  #define fetchyu6_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU6_BASE }
  /** Array initializer of fetchyu6 peripheral base pointers */
  #define fetchyu6_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU6 }
#endif

/* fetchyu7 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHYU7 base address */
  #define DISPLAY__SEERIS__FETCHYU7_BASE           (0x5B5F0060u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU7 base address */
  #define DISPLAY__SEERIS__FETCHYU7_BASE_NS        (0x4B5F0060u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU7 base pointer */
  #define DISPLAY__SEERIS__FETCHYU7                ((fetchyu7_Type *)DISPLAY__SEERIS__FETCHYU7_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHYU7 base pointer */
  #define DISPLAY__SEERIS__FETCHYU7_NS             ((fetchyu7_Type *)DISPLAY__SEERIS__FETCHYU7_BASE_NS)
  /** Array initializer of fetchyu7 peripheral base addresses */
  #define fetchyu7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU7_BASE }
  /** Array initializer of fetchyu7 peripheral base pointers */
  #define fetchyu7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU7 }
  /** Array initializer of fetchyu7 peripheral base addresses */
  #define fetchyu7_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHYU7_BASE_NS }
  /** Array initializer of fetchyu7 peripheral base pointers */
  #define fetchyu7_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHYU7_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHYU7 base address */
  #define DISPLAY__SEERIS__FETCHYU7_BASE           (0x4B5F0060u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU7 base pointer */
  #define DISPLAY__SEERIS__FETCHYU7                ((fetchyu7_Type *)DISPLAY__SEERIS__FETCHYU7_BASE)
  /** Array initializer of fetchyu7 peripheral base addresses */
  #define fetchyu7_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU7_BASE }
  /** Array initializer of fetchyu7 peripheral base pointers */
  #define fetchyu7_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU7 }
#endif

/* fetchyu8 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHYU8 base address */
  #define DISPLAY__SEERIS__FETCHYU8_BASE           (0x5B5F0078u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU8 base address */
  #define DISPLAY__SEERIS__FETCHYU8_BASE_NS        (0x4B5F0078u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU8 base pointer */
  #define DISPLAY__SEERIS__FETCHYU8                ((fetchyu8_Type *)DISPLAY__SEERIS__FETCHYU8_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHYU8 base pointer */
  #define DISPLAY__SEERIS__FETCHYU8_NS             ((fetchyu8_Type *)DISPLAY__SEERIS__FETCHYU8_BASE_NS)
  /** Array initializer of fetchyu8 peripheral base addresses */
  #define fetchyu8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU8_BASE }
  /** Array initializer of fetchyu8 peripheral base pointers */
  #define fetchyu8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU8 }
  /** Array initializer of fetchyu8 peripheral base addresses */
  #define fetchyu8_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHYU8_BASE_NS }
  /** Array initializer of fetchyu8 peripheral base pointers */
  #define fetchyu8_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHYU8_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHYU8 base address */
  #define DISPLAY__SEERIS__FETCHYU8_BASE           (0x4B5F0078u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU8 base pointer */
  #define DISPLAY__SEERIS__FETCHYU8                ((fetchyu8_Type *)DISPLAY__SEERIS__FETCHYU8_BASE)
  /** Array initializer of fetchyu8 peripheral base addresses */
  #define fetchyu8_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU8_BASE }
  /** Array initializer of fetchyu8 peripheral base pointers */
  #define fetchyu8_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU8 }
#endif

/* fetchyu9 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHYU9 base address */
  #define DISPLAY__SEERIS__FETCHYU9_BASE           (0x5B5F0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU9 base address */
  #define DISPLAY__SEERIS__FETCHYU9_BASE_NS        (0x4B5F0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU9 base pointer */
  #define DISPLAY__SEERIS__FETCHYU9                ((fetchyu9_Type *)DISPLAY__SEERIS__FETCHYU9_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHYU9 base pointer */
  #define DISPLAY__SEERIS__FETCHYU9_NS             ((fetchyu9_Type *)DISPLAY__SEERIS__FETCHYU9_BASE_NS)
  /** Array initializer of fetchyu9 peripheral base addresses */
  #define fetchyu9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU9_BASE }
  /** Array initializer of fetchyu9 peripheral base pointers */
  #define fetchyu9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU9 }
  /** Array initializer of fetchyu9 peripheral base addresses */
  #define fetchyu9_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHYU9_BASE_NS }
  /** Array initializer of fetchyu9 peripheral base pointers */
  #define fetchyu9_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHYU9_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHYU9 base address */
  #define DISPLAY__SEERIS__FETCHYU9_BASE           (0x4B5F0088u)
  /** Peripheral DISPLAY__SEERIS__FETCHYU9 base pointer */
  #define DISPLAY__SEERIS__FETCHYU9                ((fetchyu9_Type *)DISPLAY__SEERIS__FETCHYU9_BASE)
  /** Array initializer of fetchyu9 peripheral base addresses */
  #define fetchyu9_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYU9_BASE }
  /** Array initializer of fetchyu9 peripheral base pointers */
  #define fetchyu9_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYU9 }
#endif

/* fetchyuv - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FETCHYUV base address */
  #define DISPLAY__SEERIS__FETCHYUV_BASE           (0x5B5E0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHYUV base address */
  #define DISPLAY__SEERIS__FETCHYUV_BASE_NS        (0x4B5E0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHYUV base pointer */
  #define DISPLAY__SEERIS__FETCHYUV                ((fetchyuv_Type *)DISPLAY__SEERIS__FETCHYUV_BASE)
  /** Peripheral DISPLAY__SEERIS__FETCHYUV base pointer */
  #define DISPLAY__SEERIS__FETCHYUV_NS             ((fetchyuv_Type *)DISPLAY__SEERIS__FETCHYUV_BASE_NS)
  /** Array initializer of fetchyuv peripheral base addresses */
  #define fetchyuv_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYUV_BASE }
  /** Array initializer of fetchyuv peripheral base pointers */
  #define fetchyuv_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYUV }
  /** Array initializer of fetchyuv peripheral base addresses */
  #define fetchyuv_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FETCHYUV_BASE_NS }
  /** Array initializer of fetchyuv peripheral base pointers */
  #define fetchyuv_BASE_PTRS_NS                    { DISPLAY__SEERIS__FETCHYUV_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FETCHYUV base address */
  #define DISPLAY__SEERIS__FETCHYUV_BASE           (0x4B5E0000u)
  /** Peripheral DISPLAY__SEERIS__FETCHYUV base pointer */
  #define DISPLAY__SEERIS__FETCHYUV                ((fetchyuv_Type *)DISPLAY__SEERIS__FETCHYUV_BASE)
  /** Array initializer of fetchyuv peripheral base addresses */
  #define fetchyuv_BASE_ADDRS                      { DISPLAY__SEERIS__FETCHYUV_BASE }
  /** Array initializer of fetchyuv peripheral base pointers */
  #define fetchyuv_BASE_PTRS                       { DISPLAY__SEERIS__FETCHYUV }
#endif

/* filter - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FILTER base address */
  #define DISPLAY__SEERIS__FILTER_BASE             (0x5B4D0000u)
  /** Peripheral DISPLAY__SEERIS__FILTER base address */
  #define DISPLAY__SEERIS__FILTER_BASE_NS          (0x4B4D0000u)
  /** Peripheral DISPLAY__SEERIS__FILTER base pointer */
  #define DISPLAY__SEERIS__FILTER                  ((filter_Type *)DISPLAY__SEERIS__FILTER_BASE)
  /** Peripheral DISPLAY__SEERIS__FILTER base pointer */
  #define DISPLAY__SEERIS__FILTER_NS               ((filter_Type *)DISPLAY__SEERIS__FILTER_BASE_NS)
  /** Array initializer of filter peripheral base addresses */
  #define filter_BASE_ADDRS                        { DISPLAY__SEERIS__FILTER_BASE }
  /** Array initializer of filter peripheral base pointers */
  #define filter_BASE_PTRS                         { DISPLAY__SEERIS__FILTER }
  /** Array initializer of filter peripheral base addresses */
  #define filter_BASE_ADDRS_NS                     { DISPLAY__SEERIS__FILTER_BASE_NS }
  /** Array initializer of filter peripheral base pointers */
  #define filter_BASE_PTRS_NS                      { DISPLAY__SEERIS__FILTER_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FILTER base address */
  #define DISPLAY__SEERIS__FILTER_BASE             (0x4B4D0000u)
  /** Peripheral DISPLAY__SEERIS__FILTER base pointer */
  #define DISPLAY__SEERIS__FILTER                  ((filter_Type *)DISPLAY__SEERIS__FILTER_BASE)
  /** Array initializer of filter peripheral base addresses */
  #define filter_BASE_ADDRS                        { DISPLAY__SEERIS__FILTER_BASE }
  /** Array initializer of filter peripheral base pointers */
  #define filter_BASE_PTRS                         { DISPLAY__SEERIS__FILTER }
#endif

/* filter9c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__FILTER9C base address */
  #define DISPLAY__SEERIS__FILTER9C_BASE           (0x5B4D1000u)
  /** Peripheral DISPLAY__SEERIS__FILTER9C base address */
  #define DISPLAY__SEERIS__FILTER9C_BASE_NS        (0x4B4D1000u)
  /** Peripheral DISPLAY__SEERIS__FILTER9C base pointer */
  #define DISPLAY__SEERIS__FILTER9C                ((filter9c_Type *)DISPLAY__SEERIS__FILTER9C_BASE)
  /** Peripheral DISPLAY__SEERIS__FILTER9C base pointer */
  #define DISPLAY__SEERIS__FILTER9C_NS             ((filter9c_Type *)DISPLAY__SEERIS__FILTER9C_BASE_NS)
  /** Array initializer of filter9c peripheral base addresses */
  #define filter9c_BASE_ADDRS                      { DISPLAY__SEERIS__FILTER9C_BASE }
  /** Array initializer of filter9c peripheral base pointers */
  #define filter9c_BASE_PTRS                       { DISPLAY__SEERIS__FILTER9C }
  /** Array initializer of filter9c peripheral base addresses */
  #define filter9c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__FILTER9C_BASE_NS }
  /** Array initializer of filter9c peripheral base pointers */
  #define filter9c_BASE_PTRS_NS                    { DISPLAY__SEERIS__FILTER9C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__FILTER9C base address */
  #define DISPLAY__SEERIS__FILTER9C_BASE           (0x4B4D1000u)
  /** Peripheral DISPLAY__SEERIS__FILTER9C base pointer */
  #define DISPLAY__SEERIS__FILTER9C                ((filter9c_Type *)DISPLAY__SEERIS__FILTER9C_BASE)
  /** Array initializer of filter9c peripheral base addresses */
  #define filter9c_BASE_ADDRS                      { DISPLAY__SEERIS__FILTER9C_BASE }
  /** Array initializer of filter9c peripheral base pointers */
  #define filter9c_BASE_PTRS                       { DISPLAY__SEERIS__FILTER9C }
#endif

/* gammaco1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__GAMMACO1 base address */
  #define DISPLAY__SEERIS__GAMMACO1_BASE           (0x5B6E0800u)
  /** Peripheral DISPLAY__SEERIS__GAMMACO1 base address */
  #define DISPLAY__SEERIS__GAMMACO1_BASE_NS        (0x4B6E0800u)
  /** Peripheral DISPLAY__SEERIS__GAMMACO1 base pointer */
  #define DISPLAY__SEERIS__GAMMACO1                ((gammaco1_Type *)DISPLAY__SEERIS__GAMMACO1_BASE)
  /** Peripheral DISPLAY__SEERIS__GAMMACO1 base pointer */
  #define DISPLAY__SEERIS__GAMMACO1_NS             ((gammaco1_Type *)DISPLAY__SEERIS__GAMMACO1_BASE_NS)
  /** Array initializer of gammaco1 peripheral base addresses */
  #define gammaco1_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACO1_BASE }
  /** Array initializer of gammaco1 peripheral base pointers */
  #define gammaco1_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACO1 }
  /** Array initializer of gammaco1 peripheral base addresses */
  #define gammaco1_BASE_ADDRS_NS                   { DISPLAY__SEERIS__GAMMACO1_BASE_NS }
  /** Array initializer of gammaco1 peripheral base pointers */
  #define gammaco1_BASE_PTRS_NS                    { DISPLAY__SEERIS__GAMMACO1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__GAMMACO1 base address */
  #define DISPLAY__SEERIS__GAMMACO1_BASE           (0x4B6E0800u)
  /** Peripheral DISPLAY__SEERIS__GAMMACO1 base pointer */
  #define DISPLAY__SEERIS__GAMMACO1                ((gammaco1_Type *)DISPLAY__SEERIS__GAMMACO1_BASE)
  /** Array initializer of gammaco1 peripheral base addresses */
  #define gammaco1_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACO1_BASE }
  /** Array initializer of gammaco1 peripheral base pointers */
  #define gammaco1_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACO1 }
#endif

/* gammaco2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__GAMMACO2 base address */
  #define DISPLAY__SEERIS__GAMMACO2_BASE           (0x5B770000u)
  /** Peripheral DISPLAY__SEERIS__GAMMACO2 base address */
  #define DISPLAY__SEERIS__GAMMACO2_BASE_NS        (0x4B770000u)
  /** Peripheral DISPLAY__SEERIS__GAMMACO2 base pointer */
  #define DISPLAY__SEERIS__GAMMACO2                ((gammaco2_Type *)DISPLAY__SEERIS__GAMMACO2_BASE)
  /** Peripheral DISPLAY__SEERIS__GAMMACO2 base pointer */
  #define DISPLAY__SEERIS__GAMMACO2_NS             ((gammaco2_Type *)DISPLAY__SEERIS__GAMMACO2_BASE_NS)
  /** Array initializer of gammaco2 peripheral base addresses */
  #define gammaco2_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACO2_BASE }
  /** Array initializer of gammaco2 peripheral base pointers */
  #define gammaco2_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACO2 }
  /** Array initializer of gammaco2 peripheral base addresses */
  #define gammaco2_BASE_ADDRS_NS                   { DISPLAY__SEERIS__GAMMACO2_BASE_NS }
  /** Array initializer of gammaco2 peripheral base pointers */
  #define gammaco2_BASE_PTRS_NS                    { DISPLAY__SEERIS__GAMMACO2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__GAMMACO2 base address */
  #define DISPLAY__SEERIS__GAMMACO2_BASE           (0x4B770000u)
  /** Peripheral DISPLAY__SEERIS__GAMMACO2 base pointer */
  #define DISPLAY__SEERIS__GAMMACO2                ((gammaco2_Type *)DISPLAY__SEERIS__GAMMACO2_BASE)
  /** Array initializer of gammaco2 peripheral base addresses */
  #define gammaco2_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACO2_BASE }
  /** Array initializer of gammaco2 peripheral base pointers */
  #define gammaco2_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACO2 }
#endif

/* gammaco3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__GAMMACO3 base address */
  #define DISPLAY__SEERIS__GAMMACO3_BASE           (0x5B770800u)
  /** Peripheral DISPLAY__SEERIS__GAMMACO3 base address */
  #define DISPLAY__SEERIS__GAMMACO3_BASE_NS        (0x4B770800u)
  /** Peripheral DISPLAY__SEERIS__GAMMACO3 base pointer */
  #define DISPLAY__SEERIS__GAMMACO3                ((gammaco3_Type *)DISPLAY__SEERIS__GAMMACO3_BASE)
  /** Peripheral DISPLAY__SEERIS__GAMMACO3 base pointer */
  #define DISPLAY__SEERIS__GAMMACO3_NS             ((gammaco3_Type *)DISPLAY__SEERIS__GAMMACO3_BASE_NS)
  /** Array initializer of gammaco3 peripheral base addresses */
  #define gammaco3_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACO3_BASE }
  /** Array initializer of gammaco3 peripheral base pointers */
  #define gammaco3_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACO3 }
  /** Array initializer of gammaco3 peripheral base addresses */
  #define gammaco3_BASE_ADDRS_NS                   { DISPLAY__SEERIS__GAMMACO3_BASE_NS }
  /** Array initializer of gammaco3 peripheral base pointers */
  #define gammaco3_BASE_PTRS_NS                    { DISPLAY__SEERIS__GAMMACO3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__GAMMACO3 base address */
  #define DISPLAY__SEERIS__GAMMACO3_BASE           (0x4B770800u)
  /** Peripheral DISPLAY__SEERIS__GAMMACO3 base pointer */
  #define DISPLAY__SEERIS__GAMMACO3                ((gammaco3_Type *)DISPLAY__SEERIS__GAMMACO3_BASE)
  /** Array initializer of gammaco3 peripheral base addresses */
  #define gammaco3_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACO3_BASE }
  /** Array initializer of gammaco3 peripheral base pointers */
  #define gammaco3_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACO3 }
#endif

/* gammacor - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__GAMMACOR base address */
  #define DISPLAY__SEERIS__GAMMACOR_BASE           (0x5B6E0000u)
  /** Peripheral DISPLAY__SEERIS__GAMMACOR base address */
  #define DISPLAY__SEERIS__GAMMACOR_BASE_NS        (0x4B6E0000u)
  /** Peripheral DISPLAY__SEERIS__GAMMACOR base pointer */
  #define DISPLAY__SEERIS__GAMMACOR                ((gammacor_Type *)DISPLAY__SEERIS__GAMMACOR_BASE)
  /** Peripheral DISPLAY__SEERIS__GAMMACOR base pointer */
  #define DISPLAY__SEERIS__GAMMACOR_NS             ((gammacor_Type *)DISPLAY__SEERIS__GAMMACOR_BASE_NS)
  /** Array initializer of gammacor peripheral base addresses */
  #define gammacor_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACOR_BASE }
  /** Array initializer of gammacor peripheral base pointers */
  #define gammacor_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACOR }
  /** Array initializer of gammacor peripheral base addresses */
  #define gammacor_BASE_ADDRS_NS                   { DISPLAY__SEERIS__GAMMACOR_BASE_NS }
  /** Array initializer of gammacor peripheral base pointers */
  #define gammacor_BASE_PTRS_NS                    { DISPLAY__SEERIS__GAMMACOR_NS }
#else
  /** Peripheral DISPLAY__SEERIS__GAMMACOR base address */
  #define DISPLAY__SEERIS__GAMMACOR_BASE           (0x4B6E0000u)
  /** Peripheral DISPLAY__SEERIS__GAMMACOR base pointer */
  #define DISPLAY__SEERIS__GAMMACOR                ((gammacor_Type *)DISPLAY__SEERIS__GAMMACOR_BASE)
  /** Array initializer of gammacor peripheral base addresses */
  #define gammacor_BASE_ADDRS                      { DISPLAY__SEERIS__GAMMACOR_BASE }
  /** Array initializer of gammacor peripheral base pointers */
  #define gammacor_BASE_PTRS                       { DISPLAY__SEERIS__GAMMACOR }
#endif

/* generalp - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__GENERALP base address */
  #define DISPLAY__SEERIS__GENERALP_BASE           (0x5B412000u)
  /** Peripheral DISPLAY__SEERIS__GENERALP base address */
  #define DISPLAY__SEERIS__GENERALP_BASE_NS        (0x4B412000u)
  /** Peripheral DISPLAY__SEERIS__GENERALP base pointer */
  #define DISPLAY__SEERIS__GENERALP                ((generalp_Type *)DISPLAY__SEERIS__GENERALP_BASE)
  /** Peripheral DISPLAY__SEERIS__GENERALP base pointer */
  #define DISPLAY__SEERIS__GENERALP_NS             ((generalp_Type *)DISPLAY__SEERIS__GENERALP_BASE_NS)
  /** Array initializer of generalp peripheral base addresses */
  #define generalp_BASE_ADDRS                      { DISPLAY__SEERIS__GENERALP_BASE }
  /** Array initializer of generalp peripheral base pointers */
  #define generalp_BASE_PTRS                       { DISPLAY__SEERIS__GENERALP }
  /** Array initializer of generalp peripheral base addresses */
  #define generalp_BASE_ADDRS_NS                   { DISPLAY__SEERIS__GENERALP_BASE_NS }
  /** Array initializer of generalp peripheral base pointers */
  #define generalp_BASE_PTRS_NS                    { DISPLAY__SEERIS__GENERALP_NS }
#else
  /** Peripheral DISPLAY__SEERIS__GENERALP base address */
  #define DISPLAY__SEERIS__GENERALP_BASE           (0x4B412000u)
  /** Peripheral DISPLAY__SEERIS__GENERALP base pointer */
  #define DISPLAY__SEERIS__GENERALP                ((generalp_Type *)DISPLAY__SEERIS__GENERALP_BASE)
  /** Array initializer of generalp peripheral base addresses */
  #define generalp_BASE_ADDRS                      { DISPLAY__SEERIS__GENERALP_BASE }
  /** Array initializer of generalp peripheral base pointers */
  #define generalp_BASE_PTRS                       { DISPLAY__SEERIS__GENERALP }
#endif

/* hscale4c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__HSCALE4C base address */
  #define DISPLAY__SEERIS__HSCALE4C_BASE           (0x5B641000u)
  /** Peripheral DISPLAY__SEERIS__HSCALE4C base address */
  #define DISPLAY__SEERIS__HSCALE4C_BASE_NS        (0x4B641000u)
  /** Peripheral DISPLAY__SEERIS__HSCALE4C base pointer */
  #define DISPLAY__SEERIS__HSCALE4C                ((hscale4c_Type *)DISPLAY__SEERIS__HSCALE4C_BASE)
  /** Peripheral DISPLAY__SEERIS__HSCALE4C base pointer */
  #define DISPLAY__SEERIS__HSCALE4C_NS             ((hscale4c_Type *)DISPLAY__SEERIS__HSCALE4C_BASE_NS)
  /** Array initializer of hscale4c peripheral base addresses */
  #define hscale4c_BASE_ADDRS                      { DISPLAY__SEERIS__HSCALE4C_BASE }
  /** Array initializer of hscale4c peripheral base pointers */
  #define hscale4c_BASE_PTRS                       { DISPLAY__SEERIS__HSCALE4C }
  /** Array initializer of hscale4c peripheral base addresses */
  #define hscale4c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__HSCALE4C_BASE_NS }
  /** Array initializer of hscale4c peripheral base pointers */
  #define hscale4c_BASE_PTRS_NS                    { DISPLAY__SEERIS__HSCALE4C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__HSCALE4C base address */
  #define DISPLAY__SEERIS__HSCALE4C_BASE           (0x4B641000u)
  /** Peripheral DISPLAY__SEERIS__HSCALE4C base pointer */
  #define DISPLAY__SEERIS__HSCALE4C                ((hscale4c_Type *)DISPLAY__SEERIS__HSCALE4C_BASE)
  /** Array initializer of hscale4c peripheral base addresses */
  #define hscale4c_BASE_ADDRS                      { DISPLAY__SEERIS__HSCALE4C_BASE }
  /** Array initializer of hscale4c peripheral base pointers */
  #define hscale4c_BASE_PTRS                       { DISPLAY__SEERIS__HSCALE4C }
#endif

/* hscale9c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__HSCALE9C base address */
  #define DISPLAY__SEERIS__HSCALE9C_BASE           (0x5B4B1000u)
  /** Peripheral DISPLAY__SEERIS__HSCALE9C base address */
  #define DISPLAY__SEERIS__HSCALE9C_BASE_NS        (0x4B4B1000u)
  /** Peripheral DISPLAY__SEERIS__HSCALE9C base pointer */
  #define DISPLAY__SEERIS__HSCALE9C                ((hscale9c_Type *)DISPLAY__SEERIS__HSCALE9C_BASE)
  /** Peripheral DISPLAY__SEERIS__HSCALE9C base pointer */
  #define DISPLAY__SEERIS__HSCALE9C_NS             ((hscale9c_Type *)DISPLAY__SEERIS__HSCALE9C_BASE_NS)
  /** Array initializer of hscale9c peripheral base addresses */
  #define hscale9c_BASE_ADDRS                      { DISPLAY__SEERIS__HSCALE9C_BASE }
  /** Array initializer of hscale9c peripheral base pointers */
  #define hscale9c_BASE_PTRS                       { DISPLAY__SEERIS__HSCALE9C }
  /** Array initializer of hscale9c peripheral base addresses */
  #define hscale9c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__HSCALE9C_BASE_NS }
  /** Array initializer of hscale9c peripheral base pointers */
  #define hscale9c_BASE_PTRS_NS                    { DISPLAY__SEERIS__HSCALE9C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__HSCALE9C base address */
  #define DISPLAY__SEERIS__HSCALE9C_BASE           (0x4B4B1000u)
  /** Peripheral DISPLAY__SEERIS__HSCALE9C base pointer */
  #define DISPLAY__SEERIS__HSCALE9C                ((hscale9c_Type *)DISPLAY__SEERIS__HSCALE9C_BASE)
  /** Array initializer of hscale9c peripheral base addresses */
  #define hscale9c_BASE_ADDRS                      { DISPLAY__SEERIS__HSCALE9C_BASE }
  /** Array initializer of hscale9c peripheral base pointers */
  #define hscale9c_BASE_PTRS                       { DISPLAY__SEERIS__HSCALE9C }
#endif

/* idhash - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__IDHASH base address */
  #define DISPLAY__SEERIS__IDHASH_BASE             (0x5B700000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH base address */
  #define DISPLAY__SEERIS__IDHASH_BASE_NS          (0x4B700000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH base pointer */
  #define DISPLAY__SEERIS__IDHASH                  ((idhash_Type *)DISPLAY__SEERIS__IDHASH_BASE)
  /** Peripheral DISPLAY__SEERIS__IDHASH base pointer */
  #define DISPLAY__SEERIS__IDHASH_NS               ((idhash_Type *)DISPLAY__SEERIS__IDHASH_BASE_NS)
  /** Array initializer of idhash peripheral base addresses */
  #define idhash_BASE_ADDRS                        { DISPLAY__SEERIS__IDHASH_BASE }
  /** Array initializer of idhash peripheral base pointers */
  #define idhash_BASE_PTRS                         { DISPLAY__SEERIS__IDHASH }
  /** Array initializer of idhash peripheral base addresses */
  #define idhash_BASE_ADDRS_NS                     { DISPLAY__SEERIS__IDHASH_BASE_NS }
  /** Array initializer of idhash peripheral base pointers */
  #define idhash_BASE_PTRS_NS                      { DISPLAY__SEERIS__IDHASH_NS }
#else
  /** Peripheral DISPLAY__SEERIS__IDHASH base address */
  #define DISPLAY__SEERIS__IDHASH_BASE             (0x4B700000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH base pointer */
  #define DISPLAY__SEERIS__IDHASH                  ((idhash_Type *)DISPLAY__SEERIS__IDHASH_BASE)
  /** Array initializer of idhash peripheral base addresses */
  #define idhash_BASE_ADDRS                        { DISPLAY__SEERIS__IDHASH_BASE }
  /** Array initializer of idhash peripheral base pointers */
  #define idhash_BASE_PTRS                         { DISPLAY__SEERIS__IDHASH }
#endif

/* idhash0c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__IDHASH0C base address */
  #define DISPLAY__SEERIS__IDHASH0C_BASE           (0x5B703000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH0C base address */
  #define DISPLAY__SEERIS__IDHASH0C_BASE_NS        (0x4B703000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH0C base pointer */
  #define DISPLAY__SEERIS__IDHASH0C                ((idhash0c_Type *)DISPLAY__SEERIS__IDHASH0C_BASE)
  /** Peripheral DISPLAY__SEERIS__IDHASH0C base pointer */
  #define DISPLAY__SEERIS__IDHASH0C_NS             ((idhash0c_Type *)DISPLAY__SEERIS__IDHASH0C_BASE_NS)
  /** Array initializer of idhash0c peripheral base addresses */
  #define idhash0c_BASE_ADDRS                      { DISPLAY__SEERIS__IDHASH0C_BASE }
  /** Array initializer of idhash0c peripheral base pointers */
  #define idhash0c_BASE_PTRS                       { DISPLAY__SEERIS__IDHASH0C }
  /** Array initializer of idhash0c peripheral base addresses */
  #define idhash0c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__IDHASH0C_BASE_NS }
  /** Array initializer of idhash0c peripheral base pointers */
  #define idhash0c_BASE_PTRS_NS                    { DISPLAY__SEERIS__IDHASH0C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__IDHASH0C base address */
  #define DISPLAY__SEERIS__IDHASH0C_BASE           (0x4B703000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH0C base pointer */
  #define DISPLAY__SEERIS__IDHASH0C                ((idhash0c_Type *)DISPLAY__SEERIS__IDHASH0C_BASE)
  /** Array initializer of idhash0c peripheral base addresses */
  #define idhash0c_BASE_ADDRS                      { DISPLAY__SEERIS__IDHASH0C_BASE }
  /** Array initializer of idhash0c peripheral base pointers */
  #define idhash0c_BASE_PTRS                       { DISPLAY__SEERIS__IDHASH0C }
#endif

/* idhash1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__IDHASH1 base address */
  #define DISPLAY__SEERIS__IDHASH1_BASE            (0x5B701000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH1 base address */
  #define DISPLAY__SEERIS__IDHASH1_BASE_NS         (0x4B701000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH1 base pointer */
  #define DISPLAY__SEERIS__IDHASH1                 ((idhash1_Type *)DISPLAY__SEERIS__IDHASH1_BASE)
  /** Peripheral DISPLAY__SEERIS__IDHASH1 base pointer */
  #define DISPLAY__SEERIS__IDHASH1_NS              ((idhash1_Type *)DISPLAY__SEERIS__IDHASH1_BASE_NS)
  /** Array initializer of idhash1 peripheral base addresses */
  #define idhash1_BASE_ADDRS                       { DISPLAY__SEERIS__IDHASH1_BASE }
  /** Array initializer of idhash1 peripheral base pointers */
  #define idhash1_BASE_PTRS                        { DISPLAY__SEERIS__IDHASH1 }
  /** Array initializer of idhash1 peripheral base addresses */
  #define idhash1_BASE_ADDRS_NS                    { DISPLAY__SEERIS__IDHASH1_BASE_NS }
  /** Array initializer of idhash1 peripheral base pointers */
  #define idhash1_BASE_PTRS_NS                     { DISPLAY__SEERIS__IDHASH1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__IDHASH1 base address */
  #define DISPLAY__SEERIS__IDHASH1_BASE            (0x4B701000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH1 base pointer */
  #define DISPLAY__SEERIS__IDHASH1                 ((idhash1_Type *)DISPLAY__SEERIS__IDHASH1_BASE)
  /** Array initializer of idhash1 peripheral base addresses */
  #define idhash1_BASE_ADDRS                       { DISPLAY__SEERIS__IDHASH1_BASE }
  /** Array initializer of idhash1 peripheral base pointers */
  #define idhash1_BASE_PTRS                        { DISPLAY__SEERIS__IDHASH1 }
#endif

/* idhash1c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__IDHASH1C base address */
  #define DISPLAY__SEERIS__IDHASH1C_BASE           (0x5B793000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH1C base address */
  #define DISPLAY__SEERIS__IDHASH1C_BASE_NS        (0x4B793000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH1C base pointer */
  #define DISPLAY__SEERIS__IDHASH1C                ((idhash1c_Type *)DISPLAY__SEERIS__IDHASH1C_BASE)
  /** Peripheral DISPLAY__SEERIS__IDHASH1C base pointer */
  #define DISPLAY__SEERIS__IDHASH1C_NS             ((idhash1c_Type *)DISPLAY__SEERIS__IDHASH1C_BASE_NS)
  /** Array initializer of idhash1c peripheral base addresses */
  #define idhash1c_BASE_ADDRS                      { DISPLAY__SEERIS__IDHASH1C_BASE }
  /** Array initializer of idhash1c peripheral base pointers */
  #define idhash1c_BASE_PTRS                       { DISPLAY__SEERIS__IDHASH1C }
  /** Array initializer of idhash1c peripheral base addresses */
  #define idhash1c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__IDHASH1C_BASE_NS }
  /** Array initializer of idhash1c peripheral base pointers */
  #define idhash1c_BASE_PTRS_NS                    { DISPLAY__SEERIS__IDHASH1C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__IDHASH1C base address */
  #define DISPLAY__SEERIS__IDHASH1C_BASE           (0x4B793000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH1C base pointer */
  #define DISPLAY__SEERIS__IDHASH1C                ((idhash1c_Type *)DISPLAY__SEERIS__IDHASH1C_BASE)
  /** Array initializer of idhash1c peripheral base addresses */
  #define idhash1c_BASE_ADDRS                      { DISPLAY__SEERIS__IDHASH1C_BASE }
  /** Array initializer of idhash1c peripheral base pointers */
  #define idhash1c_BASE_PTRS                       { DISPLAY__SEERIS__IDHASH1C }
#endif

/* idhash2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__IDHASH2 base address */
  #define DISPLAY__SEERIS__IDHASH2_BASE            (0x5B790000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH2 base address */
  #define DISPLAY__SEERIS__IDHASH2_BASE_NS         (0x4B790000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH2 base pointer */
  #define DISPLAY__SEERIS__IDHASH2                 ((idhash2_Type *)DISPLAY__SEERIS__IDHASH2_BASE)
  /** Peripheral DISPLAY__SEERIS__IDHASH2 base pointer */
  #define DISPLAY__SEERIS__IDHASH2_NS              ((idhash2_Type *)DISPLAY__SEERIS__IDHASH2_BASE_NS)
  /** Array initializer of idhash2 peripheral base addresses */
  #define idhash2_BASE_ADDRS                       { DISPLAY__SEERIS__IDHASH2_BASE }
  /** Array initializer of idhash2 peripheral base pointers */
  #define idhash2_BASE_PTRS                        { DISPLAY__SEERIS__IDHASH2 }
  /** Array initializer of idhash2 peripheral base addresses */
  #define idhash2_BASE_ADDRS_NS                    { DISPLAY__SEERIS__IDHASH2_BASE_NS }
  /** Array initializer of idhash2 peripheral base pointers */
  #define idhash2_BASE_PTRS_NS                     { DISPLAY__SEERIS__IDHASH2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__IDHASH2 base address */
  #define DISPLAY__SEERIS__IDHASH2_BASE            (0x4B790000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH2 base pointer */
  #define DISPLAY__SEERIS__IDHASH2                 ((idhash2_Type *)DISPLAY__SEERIS__IDHASH2_BASE)
  /** Array initializer of idhash2 peripheral base addresses */
  #define idhash2_BASE_ADDRS                       { DISPLAY__SEERIS__IDHASH2_BASE }
  /** Array initializer of idhash2 peripheral base pointers */
  #define idhash2_BASE_PTRS                        { DISPLAY__SEERIS__IDHASH2 }
#endif

/* idhash3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__IDHASH3 base address */
  #define DISPLAY__SEERIS__IDHASH3_BASE            (0x5B791000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH3 base address */
  #define DISPLAY__SEERIS__IDHASH3_BASE_NS         (0x4B791000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH3 base pointer */
  #define DISPLAY__SEERIS__IDHASH3                 ((idhash3_Type *)DISPLAY__SEERIS__IDHASH3_BASE)
  /** Peripheral DISPLAY__SEERIS__IDHASH3 base pointer */
  #define DISPLAY__SEERIS__IDHASH3_NS              ((idhash3_Type *)DISPLAY__SEERIS__IDHASH3_BASE_NS)
  /** Array initializer of idhash3 peripheral base addresses */
  #define idhash3_BASE_ADDRS                       { DISPLAY__SEERIS__IDHASH3_BASE }
  /** Array initializer of idhash3 peripheral base pointers */
  #define idhash3_BASE_PTRS                        { DISPLAY__SEERIS__IDHASH3 }
  /** Array initializer of idhash3 peripheral base addresses */
  #define idhash3_BASE_ADDRS_NS                    { DISPLAY__SEERIS__IDHASH3_BASE_NS }
  /** Array initializer of idhash3 peripheral base pointers */
  #define idhash3_BASE_PTRS_NS                     { DISPLAY__SEERIS__IDHASH3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__IDHASH3 base address */
  #define DISPLAY__SEERIS__IDHASH3_BASE            (0x4B791000u)
  /** Peripheral DISPLAY__SEERIS__IDHASH3 base pointer */
  #define DISPLAY__SEERIS__IDHASH3                 ((idhash3_Type *)DISPLAY__SEERIS__IDHASH3_BASE)
  /** Array initializer of idhash3 peripheral base addresses */
  #define idhash3_BASE_ADDRS                       { DISPLAY__SEERIS__IDHASH3_BASE }
  /** Array initializer of idhash3 peripheral base pointers */
  #define idhash3_BASE_PTRS                        { DISPLAY__SEERIS__IDHASH3 }
#endif

/* ieprc_ierb - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base address */
  #define NETC__IEPRC_1__IEPRC_IERB_BASE           (0x5C8A0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base address */
  #define NETC__IEPRC_1__IEPRC_IERB_BASE_NS        (0x4C8A0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base pointer */
  #define NETC__IEPRC_1__IEPRC_IERB                ((ieprc_ierb_Type *)NETC__IEPRC_1__IEPRC_IERB_BASE)
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base pointer */
  #define NETC__IEPRC_1__IEPRC_IERB_NS             ((ieprc_ierb_Type *)NETC__IEPRC_1__IEPRC_IERB_BASE_NS)
  /** Array initializer of ieprc_ierb peripheral base addresses */
  #define ieprc_ierb_BASE_ADDRS                    { NETC__IEPRC_1__IEPRC_IERB_BASE }
  /** Array initializer of ieprc_ierb peripheral base pointers */
  #define ieprc_ierb_BASE_PTRS                     { NETC__IEPRC_1__IEPRC_IERB }
  /** Array initializer of ieprc_ierb peripheral base addresses */
  #define ieprc_ierb_BASE_ADDRS_NS                 { NETC__IEPRC_1__IEPRC_IERB_BASE_NS }
  /** Array initializer of ieprc_ierb peripheral base pointers */
  #define ieprc_ierb_BASE_PTRS_NS                  { NETC__IEPRC_1__IEPRC_IERB_NS }
#else
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base address */
  #define NETC__IEPRC_1__IEPRC_IERB_BASE           (0x4C8A0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_IERB base pointer */
  #define NETC__IEPRC_1__IEPRC_IERB                ((ieprc_ierb_Type *)NETC__IEPRC_1__IEPRC_IERB_BASE)
  /** Array initializer of ieprc_ierb peripheral base addresses */
  #define ieprc_ierb_BASE_ADDRS                    { NETC__IEPRC_1__IEPRC_IERB_BASE }
  /** Array initializer of ieprc_ierb peripheral base pointers */
  #define ieprc_ierb_BASE_PTRS                     { NETC__IEPRC_1__IEPRC_IERB }
#endif

/* ieprc_pci - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base address */
  #define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE (0x5CA08000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base address */
  #define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE_NS (0x4CA08000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_NS ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE_NS)
  /** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base address */
  #define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE (0x5CB08000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base address */
  #define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE_NS (0x4CB08000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_NS ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE_NS)
  /** Array initializer of ieprc_pci peripheral base addresses */
  #define ieprc_pci_BASE_ADDRS                     { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE }
  /** Array initializer of ieprc_pci peripheral base pointers */
  #define ieprc_pci_BASE_PTRS                      { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 }
  /** Array initializer of ieprc_pci peripheral base addresses */
  #define ieprc_pci_BASE_ADDRS_NS                  { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE_NS, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE_NS }
  /** Array initializer of ieprc_pci peripheral base pointers */
  #define ieprc_pci_BASE_PTRS_NS                   { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_NS, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_NS }
#else
  /** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base address */
  #define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE (0x4CA08000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0 ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE)
  /** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base address */
  #define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE (0x4CB08000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 base pointer */
  #define NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 ((ieprc_pci_Type *)NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE)
  /** Array initializer of ieprc_pci peripheral base addresses */
  #define ieprc_pci_BASE_ADDRS                     { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0_BASE, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0_BASE }
  /** Array initializer of ieprc_pci peripheral base pointers */
  #define ieprc_pci_BASE_PTRS                      { NETC__IEPRC_1__IEPRC_B0_EC_F0_PCI_HDR_TYPE0, NETC__IEPRC_1__IEPRC_B1_EC_F0_PCI_HDR_TYPE0 }
#endif

/* ieprc_prb - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base address */
  #define NETC__IEPRC_1__IEPRC_PRB_BASE            (0x5C8B0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base address */
  #define NETC__IEPRC_1__IEPRC_PRB_BASE_NS         (0x4C8B0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base pointer */
  #define NETC__IEPRC_1__IEPRC_PRB                 ((ieprc_prb_Type *)NETC__IEPRC_1__IEPRC_PRB_BASE)
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base pointer */
  #define NETC__IEPRC_1__IEPRC_PRB_NS              ((ieprc_prb_Type *)NETC__IEPRC_1__IEPRC_PRB_BASE_NS)
  /** Array initializer of ieprc_prb peripheral base addresses */
  #define ieprc_prb_BASE_ADDRS                     { NETC__IEPRC_1__IEPRC_PRB_BASE }
  /** Array initializer of ieprc_prb peripheral base pointers */
  #define ieprc_prb_BASE_PTRS                      { NETC__IEPRC_1__IEPRC_PRB }
  /** Array initializer of ieprc_prb peripheral base addresses */
  #define ieprc_prb_BASE_ADDRS_NS                  { NETC__IEPRC_1__IEPRC_PRB_BASE_NS }
  /** Array initializer of ieprc_prb peripheral base pointers */
  #define ieprc_prb_BASE_PTRS_NS                   { NETC__IEPRC_1__IEPRC_PRB_NS }
#else
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base address */
  #define NETC__IEPRC_1__IEPRC_PRB_BASE            (0x4C8B0000u)
  /** Peripheral NETC__IEPRC_1__IEPRC_PRB base pointer */
  #define NETC__IEPRC_1__IEPRC_PRB                 ((ieprc_prb_Type *)NETC__IEPRC_1__IEPRC_PRB_BASE)
  /** Array initializer of ieprc_prb peripheral base addresses */
  #define ieprc_prb_BASE_ADDRS                     { NETC__IEPRC_1__IEPRC_PRB_BASE }
  /** Array initializer of ieprc_prb peripheral base pointers */
  #define ieprc_prb_BASE_PTRS                      { NETC__IEPRC_1__IEPRC_PRB }
#endif

/* layerb1c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__LAYERB1C base address */
  #define DISPLAY__SEERIS__LAYERB1C_BASE           (0x5B571000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB1C base address */
  #define DISPLAY__SEERIS__LAYERB1C_BASE_NS        (0x4B571000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB1C base pointer */
  #define DISPLAY__SEERIS__LAYERB1C                ((layerb1c_Type *)DISPLAY__SEERIS__LAYERB1C_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERB1C base pointer */
  #define DISPLAY__SEERIS__LAYERB1C_NS             ((layerb1c_Type *)DISPLAY__SEERIS__LAYERB1C_BASE_NS)
  /** Array initializer of layerb1c peripheral base addresses */
  #define layerb1c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB1C_BASE }
  /** Array initializer of layerb1c peripheral base pointers */
  #define layerb1c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB1C }
  /** Array initializer of layerb1c peripheral base addresses */
  #define layerb1c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__LAYERB1C_BASE_NS }
  /** Array initializer of layerb1c peripheral base pointers */
  #define layerb1c_BASE_PTRS_NS                    { DISPLAY__SEERIS__LAYERB1C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__LAYERB1C base address */
  #define DISPLAY__SEERIS__LAYERB1C_BASE           (0x4B571000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB1C base pointer */
  #define DISPLAY__SEERIS__LAYERB1C                ((layerb1c_Type *)DISPLAY__SEERIS__LAYERB1C_BASE)
  /** Array initializer of layerb1c peripheral base addresses */
  #define layerb1c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB1C_BASE }
  /** Array initializer of layerb1c peripheral base pointers */
  #define layerb1c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB1C }
#endif

/* layerb2c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__LAYERB2C base address */
  #define DISPLAY__SEERIS__LAYERB2C_BASE           (0x5B581000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB2C base address */
  #define DISPLAY__SEERIS__LAYERB2C_BASE_NS        (0x4B581000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB2C base pointer */
  #define DISPLAY__SEERIS__LAYERB2C                ((layerb2c_Type *)DISPLAY__SEERIS__LAYERB2C_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERB2C base pointer */
  #define DISPLAY__SEERIS__LAYERB2C_NS             ((layerb2c_Type *)DISPLAY__SEERIS__LAYERB2C_BASE_NS)
  /** Array initializer of layerb2c peripheral base addresses */
  #define layerb2c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB2C_BASE }
  /** Array initializer of layerb2c peripheral base pointers */
  #define layerb2c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB2C }
  /** Array initializer of layerb2c peripheral base addresses */
  #define layerb2c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__LAYERB2C_BASE_NS }
  /** Array initializer of layerb2c peripheral base pointers */
  #define layerb2c_BASE_PTRS_NS                    { DISPLAY__SEERIS__LAYERB2C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__LAYERB2C base address */
  #define DISPLAY__SEERIS__LAYERB2C_BASE           (0x4B581000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB2C base pointer */
  #define DISPLAY__SEERIS__LAYERB2C                ((layerb2c_Type *)DISPLAY__SEERIS__LAYERB2C_BASE)
  /** Array initializer of layerb2c peripheral base addresses */
  #define layerb2c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB2C_BASE }
  /** Array initializer of layerb2c peripheral base pointers */
  #define layerb2c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB2C }
#endif

/* layerb3c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__LAYERB3C base address */
  #define DISPLAY__SEERIS__LAYERB3C_BASE           (0x5B591000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB3C base address */
  #define DISPLAY__SEERIS__LAYERB3C_BASE_NS        (0x4B591000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB3C base pointer */
  #define DISPLAY__SEERIS__LAYERB3C                ((layerb3c_Type *)DISPLAY__SEERIS__LAYERB3C_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERB3C base pointer */
  #define DISPLAY__SEERIS__LAYERB3C_NS             ((layerb3c_Type *)DISPLAY__SEERIS__LAYERB3C_BASE_NS)
  /** Array initializer of layerb3c peripheral base addresses */
  #define layerb3c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB3C_BASE }
  /** Array initializer of layerb3c peripheral base pointers */
  #define layerb3c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB3C }
  /** Array initializer of layerb3c peripheral base addresses */
  #define layerb3c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__LAYERB3C_BASE_NS }
  /** Array initializer of layerb3c peripheral base pointers */
  #define layerb3c_BASE_PTRS_NS                    { DISPLAY__SEERIS__LAYERB3C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__LAYERB3C base address */
  #define DISPLAY__SEERIS__LAYERB3C_BASE           (0x4B591000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB3C base pointer */
  #define DISPLAY__SEERIS__LAYERB3C                ((layerb3c_Type *)DISPLAY__SEERIS__LAYERB3C_BASE)
  /** Array initializer of layerb3c peripheral base addresses */
  #define layerb3c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB3C_BASE }
  /** Array initializer of layerb3c peripheral base pointers */
  #define layerb3c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB3C }
#endif

/* layerb4c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__LAYERB4C base address */
  #define DISPLAY__SEERIS__LAYERB4C_BASE           (0x5B5A1000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB4C base address */
  #define DISPLAY__SEERIS__LAYERB4C_BASE_NS        (0x4B5A1000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB4C base pointer */
  #define DISPLAY__SEERIS__LAYERB4C                ((layerb4c_Type *)DISPLAY__SEERIS__LAYERB4C_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERB4C base pointer */
  #define DISPLAY__SEERIS__LAYERB4C_NS             ((layerb4c_Type *)DISPLAY__SEERIS__LAYERB4C_BASE_NS)
  /** Array initializer of layerb4c peripheral base addresses */
  #define layerb4c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB4C_BASE }
  /** Array initializer of layerb4c peripheral base pointers */
  #define layerb4c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB4C }
  /** Array initializer of layerb4c peripheral base addresses */
  #define layerb4c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__LAYERB4C_BASE_NS }
  /** Array initializer of layerb4c peripheral base pointers */
  #define layerb4c_BASE_PTRS_NS                    { DISPLAY__SEERIS__LAYERB4C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__LAYERB4C base address */
  #define DISPLAY__SEERIS__LAYERB4C_BASE           (0x4B5A1000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB4C base pointer */
  #define DISPLAY__SEERIS__LAYERB4C                ((layerb4c_Type *)DISPLAY__SEERIS__LAYERB4C_BASE)
  /** Array initializer of layerb4c peripheral base addresses */
  #define layerb4c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB4C_BASE }
  /** Array initializer of layerb4c peripheral base pointers */
  #define layerb4c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB4C }
#endif

/* layerb5c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__LAYERB5C base address */
  #define DISPLAY__SEERIS__LAYERB5C_BASE           (0x5B5B1000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB5C base address */
  #define DISPLAY__SEERIS__LAYERB5C_BASE_NS        (0x4B5B1000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB5C base pointer */
  #define DISPLAY__SEERIS__LAYERB5C                ((layerb5c_Type *)DISPLAY__SEERIS__LAYERB5C_BASE)
  /** Peripheral DISPLAY__SEERIS__LAYERB5C base pointer */
  #define DISPLAY__SEERIS__LAYERB5C_NS             ((layerb5c_Type *)DISPLAY__SEERIS__LAYERB5C_BASE_NS)
  /** Array initializer of layerb5c peripheral base addresses */
  #define layerb5c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB5C_BASE }
  /** Array initializer of layerb5c peripheral base pointers */
  #define layerb5c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB5C }
  /** Array initializer of layerb5c peripheral base addresses */
  #define layerb5c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__LAYERB5C_BASE_NS }
  /** Array initializer of layerb5c peripheral base pointers */
  #define layerb5c_BASE_PTRS_NS                    { DISPLAY__SEERIS__LAYERB5C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__LAYERB5C base address */
  #define DISPLAY__SEERIS__LAYERB5C_BASE           (0x4B5B1000u)
  /** Peripheral DISPLAY__SEERIS__LAYERB5C base pointer */
  #define DISPLAY__SEERIS__LAYERB5C                ((layerb5c_Type *)DISPLAY__SEERIS__LAYERB5C_BASE)
  /** Array initializer of layerb5c peripheral base addresses */
  #define layerb5c_BASE_ADDRS                      { DISPLAY__SEERIS__LAYERB5C_BASE }
  /** Array initializer of layerb5c peripheral base pointers */
  #define layerb5c_BASE_PTRS                       { DISPLAY__SEERIS__LAYERB5C }
#endif

/* lut3d - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__LUT3D base address */
  #define DISPLAY__SEERIS__LUT3D_BASE              (0x5B6D0000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D base address */
  #define DISPLAY__SEERIS__LUT3D_BASE_NS           (0x4B6D0000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D base pointer */
  #define DISPLAY__SEERIS__LUT3D                   ((lut3d_Type *)DISPLAY__SEERIS__LUT3D_BASE)
  /** Peripheral DISPLAY__SEERIS__LUT3D base pointer */
  #define DISPLAY__SEERIS__LUT3D_NS                ((lut3d_Type *)DISPLAY__SEERIS__LUT3D_BASE_NS)
  /** Array initializer of lut3d peripheral base addresses */
  #define lut3d_BASE_ADDRS                         { DISPLAY__SEERIS__LUT3D_BASE }
  /** Array initializer of lut3d peripheral base pointers */
  #define lut3d_BASE_PTRS                          { DISPLAY__SEERIS__LUT3D }
  /** Array initializer of lut3d peripheral base addresses */
  #define lut3d_BASE_ADDRS_NS                      { DISPLAY__SEERIS__LUT3D_BASE_NS }
  /** Array initializer of lut3d peripheral base pointers */
  #define lut3d_BASE_PTRS_NS                       { DISPLAY__SEERIS__LUT3D_NS }
#else
  /** Peripheral DISPLAY__SEERIS__LUT3D base address */
  #define DISPLAY__SEERIS__LUT3D_BASE              (0x4B6D0000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D base pointer */
  #define DISPLAY__SEERIS__LUT3D                   ((lut3d_Type *)DISPLAY__SEERIS__LUT3D_BASE)
  /** Array initializer of lut3d peripheral base addresses */
  #define lut3d_BASE_ADDRS                         { DISPLAY__SEERIS__LUT3D_BASE }
  /** Array initializer of lut3d peripheral base pointers */
  #define lut3d_BASE_PTRS                          { DISPLAY__SEERIS__LUT3D }
#endif

/* lut3d1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__LUT3D1 base address */
  #define DISPLAY__SEERIS__LUT3D1_BASE             (0x5B6D2000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D1 base address */
  #define DISPLAY__SEERIS__LUT3D1_BASE_NS          (0x4B6D2000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D1 base pointer */
  #define DISPLAY__SEERIS__LUT3D1                  ((lut3d1_Type *)DISPLAY__SEERIS__LUT3D1_BASE)
  /** Peripheral DISPLAY__SEERIS__LUT3D1 base pointer */
  #define DISPLAY__SEERIS__LUT3D1_NS               ((lut3d1_Type *)DISPLAY__SEERIS__LUT3D1_BASE_NS)
  /** Array initializer of lut3d1 peripheral base addresses */
  #define lut3d1_BASE_ADDRS                        { DISPLAY__SEERIS__LUT3D1_BASE }
  /** Array initializer of lut3d1 peripheral base pointers */
  #define lut3d1_BASE_PTRS                         { DISPLAY__SEERIS__LUT3D1 }
  /** Array initializer of lut3d1 peripheral base addresses */
  #define lut3d1_BASE_ADDRS_NS                     { DISPLAY__SEERIS__LUT3D1_BASE_NS }
  /** Array initializer of lut3d1 peripheral base pointers */
  #define lut3d1_BASE_PTRS_NS                      { DISPLAY__SEERIS__LUT3D1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__LUT3D1 base address */
  #define DISPLAY__SEERIS__LUT3D1_BASE             (0x4B6D2000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D1 base pointer */
  #define DISPLAY__SEERIS__LUT3D1                  ((lut3d1_Type *)DISPLAY__SEERIS__LUT3D1_BASE)
  /** Array initializer of lut3d1 peripheral base addresses */
  #define lut3d1_BASE_ADDRS                        { DISPLAY__SEERIS__LUT3D1_BASE }
  /** Array initializer of lut3d1 peripheral base pointers */
  #define lut3d1_BASE_PTRS                         { DISPLAY__SEERIS__LUT3D1 }
#endif

/* lut3d2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__LUT3D2 base address */
  #define DISPLAY__SEERIS__LUT3D2_BASE             (0x5B760000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D2 base address */
  #define DISPLAY__SEERIS__LUT3D2_BASE_NS          (0x4B760000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D2 base pointer */
  #define DISPLAY__SEERIS__LUT3D2                  ((lut3d2_Type *)DISPLAY__SEERIS__LUT3D2_BASE)
  /** Peripheral DISPLAY__SEERIS__LUT3D2 base pointer */
  #define DISPLAY__SEERIS__LUT3D2_NS               ((lut3d2_Type *)DISPLAY__SEERIS__LUT3D2_BASE_NS)
  /** Array initializer of lut3d2 peripheral base addresses */
  #define lut3d2_BASE_ADDRS                        { DISPLAY__SEERIS__LUT3D2_BASE }
  /** Array initializer of lut3d2 peripheral base pointers */
  #define lut3d2_BASE_PTRS                         { DISPLAY__SEERIS__LUT3D2 }
  /** Array initializer of lut3d2 peripheral base addresses */
  #define lut3d2_BASE_ADDRS_NS                     { DISPLAY__SEERIS__LUT3D2_BASE_NS }
  /** Array initializer of lut3d2 peripheral base pointers */
  #define lut3d2_BASE_PTRS_NS                      { DISPLAY__SEERIS__LUT3D2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__LUT3D2 base address */
  #define DISPLAY__SEERIS__LUT3D2_BASE             (0x4B760000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D2 base pointer */
  #define DISPLAY__SEERIS__LUT3D2                  ((lut3d2_Type *)DISPLAY__SEERIS__LUT3D2_BASE)
  /** Array initializer of lut3d2 peripheral base addresses */
  #define lut3d2_BASE_ADDRS                        { DISPLAY__SEERIS__LUT3D2_BASE }
  /** Array initializer of lut3d2 peripheral base pointers */
  #define lut3d2_BASE_PTRS                         { DISPLAY__SEERIS__LUT3D2 }
#endif

/* lut3d3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__LUT3D3 base address */
  #define DISPLAY__SEERIS__LUT3D3_BASE             (0x5B762000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D3 base address */
  #define DISPLAY__SEERIS__LUT3D3_BASE_NS          (0x4B762000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D3 base pointer */
  #define DISPLAY__SEERIS__LUT3D3                  ((lut3d3_Type *)DISPLAY__SEERIS__LUT3D3_BASE)
  /** Peripheral DISPLAY__SEERIS__LUT3D3 base pointer */
  #define DISPLAY__SEERIS__LUT3D3_NS               ((lut3d3_Type *)DISPLAY__SEERIS__LUT3D3_BASE_NS)
  /** Array initializer of lut3d3 peripheral base addresses */
  #define lut3d3_BASE_ADDRS                        { DISPLAY__SEERIS__LUT3D3_BASE }
  /** Array initializer of lut3d3 peripheral base pointers */
  #define lut3d3_BASE_PTRS                         { DISPLAY__SEERIS__LUT3D3 }
  /** Array initializer of lut3d3 peripheral base addresses */
  #define lut3d3_BASE_ADDRS_NS                     { DISPLAY__SEERIS__LUT3D3_BASE_NS }
  /** Array initializer of lut3d3 peripheral base pointers */
  #define lut3d3_BASE_PTRS_NS                      { DISPLAY__SEERIS__LUT3D3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__LUT3D3 base address */
  #define DISPLAY__SEERIS__LUT3D3_BASE             (0x4B762000u)
  /** Peripheral DISPLAY__SEERIS__LUT3D3 base pointer */
  #define DISPLAY__SEERIS__LUT3D3                  ((lut3d3_Type *)DISPLAY__SEERIS__LUT3D3_BASE)
  /** Array initializer of lut3d3 peripheral base addresses */
  #define lut3d3_BASE_ADDRS                        { DISPLAY__SEERIS__LUT3D3_BASE }
  /** Array initializer of lut3d3 peripheral base pointers */
  #define lut3d3_BASE_PTRS                         { DISPLAY__SEERIS__LUT3D3 }
#endif

/* matrix - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__MATRIX base address */
  #define DISPLAY__SEERIS__MATRIX_BASE             (0x5B460000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX base address */
  #define DISPLAY__SEERIS__MATRIX_BASE_NS          (0x4B460000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX base pointer */
  #define DISPLAY__SEERIS__MATRIX                  ((matrix_Type *)DISPLAY__SEERIS__MATRIX_BASE)
  /** Peripheral DISPLAY__SEERIS__MATRIX base pointer */
  #define DISPLAY__SEERIS__MATRIX_NS               ((matrix_Type *)DISPLAY__SEERIS__MATRIX_BASE_NS)
  /** Array initializer of matrix peripheral base addresses */
  #define matrix_BASE_ADDRS                        { DISPLAY__SEERIS__MATRIX_BASE }
  /** Array initializer of matrix peripheral base pointers */
  #define matrix_BASE_PTRS                         { DISPLAY__SEERIS__MATRIX }
  /** Array initializer of matrix peripheral base addresses */
  #define matrix_BASE_ADDRS_NS                     { DISPLAY__SEERIS__MATRIX_BASE_NS }
  /** Array initializer of matrix peripheral base pointers */
  #define matrix_BASE_PTRS_NS                      { DISPLAY__SEERIS__MATRIX_NS }
#else
  /** Peripheral DISPLAY__SEERIS__MATRIX base address */
  #define DISPLAY__SEERIS__MATRIX_BASE             (0x4B460000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX base pointer */
  #define DISPLAY__SEERIS__MATRIX                  ((matrix_Type *)DISPLAY__SEERIS__MATRIX_BASE)
  /** Array initializer of matrix peripheral base addresses */
  #define matrix_BASE_ADDRS                        { DISPLAY__SEERIS__MATRIX_BASE }
  /** Array initializer of matrix peripheral base pointers */
  #define matrix_BASE_PTRS                         { DISPLAY__SEERIS__MATRIX }
#endif

/* matrix1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__MATRIX1 base address */
  #define DISPLAY__SEERIS__MATRIX1_BASE            (0x5B460030u)
  /** Peripheral DISPLAY__SEERIS__MATRIX1 base address */
  #define DISPLAY__SEERIS__MATRIX1_BASE_NS         (0x4B460030u)
  /** Peripheral DISPLAY__SEERIS__MATRIX1 base pointer */
  #define DISPLAY__SEERIS__MATRIX1                 ((matrix1_Type *)DISPLAY__SEERIS__MATRIX1_BASE)
  /** Peripheral DISPLAY__SEERIS__MATRIX1 base pointer */
  #define DISPLAY__SEERIS__MATRIX1_NS              ((matrix1_Type *)DISPLAY__SEERIS__MATRIX1_BASE_NS)
  /** Array initializer of matrix1 peripheral base addresses */
  #define matrix1_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIX1_BASE }
  /** Array initializer of matrix1 peripheral base pointers */
  #define matrix1_BASE_PTRS                        { DISPLAY__SEERIS__MATRIX1 }
  /** Array initializer of matrix1 peripheral base addresses */
  #define matrix1_BASE_ADDRS_NS                    { DISPLAY__SEERIS__MATRIX1_BASE_NS }
  /** Array initializer of matrix1 peripheral base pointers */
  #define matrix1_BASE_PTRS_NS                     { DISPLAY__SEERIS__MATRIX1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__MATRIX1 base address */
  #define DISPLAY__SEERIS__MATRIX1_BASE            (0x4B460030u)
  /** Peripheral DISPLAY__SEERIS__MATRIX1 base pointer */
  #define DISPLAY__SEERIS__MATRIX1                 ((matrix1_Type *)DISPLAY__SEERIS__MATRIX1_BASE)
  /** Array initializer of matrix1 peripheral base addresses */
  #define matrix1_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIX1_BASE }
  /** Array initializer of matrix1 peripheral base pointers */
  #define matrix1_BASE_PTRS                        { DISPLAY__SEERIS__MATRIX1 }
#endif

/* matrix2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__MATRIX2 base address */
  #define DISPLAY__SEERIS__MATRIX2_BASE            (0x5B630000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX2 base address */
  #define DISPLAY__SEERIS__MATRIX2_BASE_NS         (0x4B630000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX2 base pointer */
  #define DISPLAY__SEERIS__MATRIX2                 ((matrix2_Type *)DISPLAY__SEERIS__MATRIX2_BASE)
  /** Peripheral DISPLAY__SEERIS__MATRIX2 base pointer */
  #define DISPLAY__SEERIS__MATRIX2_NS              ((matrix2_Type *)DISPLAY__SEERIS__MATRIX2_BASE_NS)
  /** Array initializer of matrix2 peripheral base addresses */
  #define matrix2_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIX2_BASE }
  /** Array initializer of matrix2 peripheral base pointers */
  #define matrix2_BASE_PTRS                        { DISPLAY__SEERIS__MATRIX2 }
  /** Array initializer of matrix2 peripheral base addresses */
  #define matrix2_BASE_ADDRS_NS                    { DISPLAY__SEERIS__MATRIX2_BASE_NS }
  /** Array initializer of matrix2 peripheral base pointers */
  #define matrix2_BASE_PTRS_NS                     { DISPLAY__SEERIS__MATRIX2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__MATRIX2 base address */
  #define DISPLAY__SEERIS__MATRIX2_BASE            (0x4B630000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX2 base pointer */
  #define DISPLAY__SEERIS__MATRIX2                 ((matrix2_Type *)DISPLAY__SEERIS__MATRIX2_BASE)
  /** Array initializer of matrix2 peripheral base addresses */
  #define matrix2_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIX2_BASE }
  /** Array initializer of matrix2 peripheral base pointers */
  #define matrix2_BASE_PTRS                        { DISPLAY__SEERIS__MATRIX2 }
#endif

/* matrix3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__MATRIX3 base address */
  #define DISPLAY__SEERIS__MATRIX3_BASE            (0x5B630030u)
  /** Peripheral DISPLAY__SEERIS__MATRIX3 base address */
  #define DISPLAY__SEERIS__MATRIX3_BASE_NS         (0x4B630030u)
  /** Peripheral DISPLAY__SEERIS__MATRIX3 base pointer */
  #define DISPLAY__SEERIS__MATRIX3                 ((matrix3_Type *)DISPLAY__SEERIS__MATRIX3_BASE)
  /** Peripheral DISPLAY__SEERIS__MATRIX3 base pointer */
  #define DISPLAY__SEERIS__MATRIX3_NS              ((matrix3_Type *)DISPLAY__SEERIS__MATRIX3_BASE_NS)
  /** Array initializer of matrix3 peripheral base addresses */
  #define matrix3_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIX3_BASE }
  /** Array initializer of matrix3 peripheral base pointers */
  #define matrix3_BASE_PTRS                        { DISPLAY__SEERIS__MATRIX3 }
  /** Array initializer of matrix3 peripheral base addresses */
  #define matrix3_BASE_ADDRS_NS                    { DISPLAY__SEERIS__MATRIX3_BASE_NS }
  /** Array initializer of matrix3 peripheral base pointers */
  #define matrix3_BASE_PTRS_NS                     { DISPLAY__SEERIS__MATRIX3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__MATRIX3 base address */
  #define DISPLAY__SEERIS__MATRIX3_BASE            (0x4B630030u)
  /** Peripheral DISPLAY__SEERIS__MATRIX3 base pointer */
  #define DISPLAY__SEERIS__MATRIX3                 ((matrix3_Type *)DISPLAY__SEERIS__MATRIX3_BASE)
  /** Array initializer of matrix3 peripheral base addresses */
  #define matrix3_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIX3_BASE }
  /** Array initializer of matrix3 peripheral base pointers */
  #define matrix3_BASE_PTRS                        { DISPLAY__SEERIS__MATRIX3 }
#endif

/* matrix4c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__MATRIX4C base address */
  #define DISPLAY__SEERIS__MATRIX4C_BASE           (0x5B631000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX4C base address */
  #define DISPLAY__SEERIS__MATRIX4C_BASE_NS        (0x4B631000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX4C base pointer */
  #define DISPLAY__SEERIS__MATRIX4C                ((matrix4c_Type *)DISPLAY__SEERIS__MATRIX4C_BASE)
  /** Peripheral DISPLAY__SEERIS__MATRIX4C base pointer */
  #define DISPLAY__SEERIS__MATRIX4C_NS             ((matrix4c_Type *)DISPLAY__SEERIS__MATRIX4C_BASE_NS)
  /** Array initializer of matrix4c peripheral base addresses */
  #define matrix4c_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIX4C_BASE }
  /** Array initializer of matrix4c peripheral base pointers */
  #define matrix4c_BASE_PTRS                       { DISPLAY__SEERIS__MATRIX4C }
  /** Array initializer of matrix4c peripheral base addresses */
  #define matrix4c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__MATRIX4C_BASE_NS }
  /** Array initializer of matrix4c peripheral base pointers */
  #define matrix4c_BASE_PTRS_NS                    { DISPLAY__SEERIS__MATRIX4C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__MATRIX4C base address */
  #define DISPLAY__SEERIS__MATRIX4C_BASE           (0x4B631000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX4C base pointer */
  #define DISPLAY__SEERIS__MATRIX4C                ((matrix4c_Type *)DISPLAY__SEERIS__MATRIX4C_BASE)
  /** Array initializer of matrix4c peripheral base addresses */
  #define matrix4c_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIX4C_BASE }
  /** Array initializer of matrix4c peripheral base pointers */
  #define matrix4c_BASE_PTRS                       { DISPLAY__SEERIS__MATRIX4C }
#endif

/* matrix9c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__MATRIX9C base address */
  #define DISPLAY__SEERIS__MATRIX9C_BASE           (0x5B461000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX9C base address */
  #define DISPLAY__SEERIS__MATRIX9C_BASE_NS        (0x4B461000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX9C base pointer */
  #define DISPLAY__SEERIS__MATRIX9C                ((matrix9c_Type *)DISPLAY__SEERIS__MATRIX9C_BASE)
  /** Peripheral DISPLAY__SEERIS__MATRIX9C base pointer */
  #define DISPLAY__SEERIS__MATRIX9C_NS             ((matrix9c_Type *)DISPLAY__SEERIS__MATRIX9C_BASE_NS)
  /** Array initializer of matrix9c peripheral base addresses */
  #define matrix9c_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIX9C_BASE }
  /** Array initializer of matrix9c peripheral base pointers */
  #define matrix9c_BASE_PTRS                       { DISPLAY__SEERIS__MATRIX9C }
  /** Array initializer of matrix9c peripheral base addresses */
  #define matrix9c_BASE_ADDRS_NS                   { DISPLAY__SEERIS__MATRIX9C_BASE_NS }
  /** Array initializer of matrix9c peripheral base pointers */
  #define matrix9c_BASE_PTRS_NS                    { DISPLAY__SEERIS__MATRIX9C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__MATRIX9C base address */
  #define DISPLAY__SEERIS__MATRIX9C_BASE           (0x4B461000u)
  /** Peripheral DISPLAY__SEERIS__MATRIX9C base pointer */
  #define DISPLAY__SEERIS__MATRIX9C                ((matrix9c_Type *)DISPLAY__SEERIS__MATRIX9C_BASE)
  /** Array initializer of matrix9c peripheral base addresses */
  #define matrix9c_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIX9C_BASE }
  /** Array initializer of matrix9c peripheral base pointers */
  #define matrix9c_BASE_PTRS                       { DISPLAY__SEERIS__MATRIX9C }
#endif

/* matrixl - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__MATRIXL base address */
  #define DISPLAY__SEERIS__MATRIXL_BASE            (0x5B6C0000u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL base address */
  #define DISPLAY__SEERIS__MATRIXL_BASE_NS         (0x4B6C0000u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL base pointer */
  #define DISPLAY__SEERIS__MATRIXL                 ((matrixl_Type *)DISPLAY__SEERIS__MATRIXL_BASE)
  /** Peripheral DISPLAY__SEERIS__MATRIXL base pointer */
  #define DISPLAY__SEERIS__MATRIXL_NS              ((matrixl_Type *)DISPLAY__SEERIS__MATRIXL_BASE_NS)
  /** Array initializer of matrixl peripheral base addresses */
  #define matrixl_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIXL_BASE }
  /** Array initializer of matrixl peripheral base pointers */
  #define matrixl_BASE_PTRS                        { DISPLAY__SEERIS__MATRIXL }
  /** Array initializer of matrixl peripheral base addresses */
  #define matrixl_BASE_ADDRS_NS                    { DISPLAY__SEERIS__MATRIXL_BASE_NS }
  /** Array initializer of matrixl peripheral base pointers */
  #define matrixl_BASE_PTRS_NS                     { DISPLAY__SEERIS__MATRIXL_NS }
#else
  /** Peripheral DISPLAY__SEERIS__MATRIXL base address */
  #define DISPLAY__SEERIS__MATRIXL_BASE            (0x4B6C0000u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL base pointer */
  #define DISPLAY__SEERIS__MATRIXL                 ((matrixl_Type *)DISPLAY__SEERIS__MATRIXL_BASE)
  /** Array initializer of matrixl peripheral base addresses */
  #define matrixl_BASE_ADDRS                       { DISPLAY__SEERIS__MATRIXL_BASE }
  /** Array initializer of matrixl peripheral base pointers */
  #define matrixl_BASE_PTRS                        { DISPLAY__SEERIS__MATRIXL }
#endif

/* matrixl1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__MATRIXL1 base address */
  #define DISPLAY__SEERIS__MATRIXL1_BASE           (0x5B6C0030u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL1 base address */
  #define DISPLAY__SEERIS__MATRIXL1_BASE_NS        (0x4B6C0030u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL1 base pointer */
  #define DISPLAY__SEERIS__MATRIXL1                ((matrixl1_Type *)DISPLAY__SEERIS__MATRIXL1_BASE)
  /** Peripheral DISPLAY__SEERIS__MATRIXL1 base pointer */
  #define DISPLAY__SEERIS__MATRIXL1_NS             ((matrixl1_Type *)DISPLAY__SEERIS__MATRIXL1_BASE_NS)
  /** Array initializer of matrixl1 peripheral base addresses */
  #define matrixl1_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIXL1_BASE }
  /** Array initializer of matrixl1 peripheral base pointers */
  #define matrixl1_BASE_PTRS                       { DISPLAY__SEERIS__MATRIXL1 }
  /** Array initializer of matrixl1 peripheral base addresses */
  #define matrixl1_BASE_ADDRS_NS                   { DISPLAY__SEERIS__MATRIXL1_BASE_NS }
  /** Array initializer of matrixl1 peripheral base pointers */
  #define matrixl1_BASE_PTRS_NS                    { DISPLAY__SEERIS__MATRIXL1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__MATRIXL1 base address */
  #define DISPLAY__SEERIS__MATRIXL1_BASE           (0x4B6C0030u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL1 base pointer */
  #define DISPLAY__SEERIS__MATRIXL1                ((matrixl1_Type *)DISPLAY__SEERIS__MATRIXL1_BASE)
  /** Array initializer of matrixl1 peripheral base addresses */
  #define matrixl1_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIXL1_BASE }
  /** Array initializer of matrixl1 peripheral base pointers */
  #define matrixl1_BASE_PTRS                       { DISPLAY__SEERIS__MATRIXL1 }
#endif

/* matrixl2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__MATRIXL2 base address */
  #define DISPLAY__SEERIS__MATRIXL2_BASE           (0x5B750000u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL2 base address */
  #define DISPLAY__SEERIS__MATRIXL2_BASE_NS        (0x4B750000u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL2 base pointer */
  #define DISPLAY__SEERIS__MATRIXL2                ((matrixl2_Type *)DISPLAY__SEERIS__MATRIXL2_BASE)
  /** Peripheral DISPLAY__SEERIS__MATRIXL2 base pointer */
  #define DISPLAY__SEERIS__MATRIXL2_NS             ((matrixl2_Type *)DISPLAY__SEERIS__MATRIXL2_BASE_NS)
  /** Array initializer of matrixl2 peripheral base addresses */
  #define matrixl2_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIXL2_BASE }
  /** Array initializer of matrixl2 peripheral base pointers */
  #define matrixl2_BASE_PTRS                       { DISPLAY__SEERIS__MATRIXL2 }
  /** Array initializer of matrixl2 peripheral base addresses */
  #define matrixl2_BASE_ADDRS_NS                   { DISPLAY__SEERIS__MATRIXL2_BASE_NS }
  /** Array initializer of matrixl2 peripheral base pointers */
  #define matrixl2_BASE_PTRS_NS                    { DISPLAY__SEERIS__MATRIXL2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__MATRIXL2 base address */
  #define DISPLAY__SEERIS__MATRIXL2_BASE           (0x4B750000u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL2 base pointer */
  #define DISPLAY__SEERIS__MATRIXL2                ((matrixl2_Type *)DISPLAY__SEERIS__MATRIXL2_BASE)
  /** Array initializer of matrixl2 peripheral base addresses */
  #define matrixl2_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIXL2_BASE }
  /** Array initializer of matrixl2 peripheral base pointers */
  #define matrixl2_BASE_PTRS                       { DISPLAY__SEERIS__MATRIXL2 }
#endif

/* matrixl3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__MATRIXL3 base address */
  #define DISPLAY__SEERIS__MATRIXL3_BASE           (0x5B750030u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL3 base address */
  #define DISPLAY__SEERIS__MATRIXL3_BASE_NS        (0x4B750030u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL3 base pointer */
  #define DISPLAY__SEERIS__MATRIXL3                ((matrixl3_Type *)DISPLAY__SEERIS__MATRIXL3_BASE)
  /** Peripheral DISPLAY__SEERIS__MATRIXL3 base pointer */
  #define DISPLAY__SEERIS__MATRIXL3_NS             ((matrixl3_Type *)DISPLAY__SEERIS__MATRIXL3_BASE_NS)
  /** Array initializer of matrixl3 peripheral base addresses */
  #define matrixl3_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIXL3_BASE }
  /** Array initializer of matrixl3 peripheral base pointers */
  #define matrixl3_BASE_PTRS                       { DISPLAY__SEERIS__MATRIXL3 }
  /** Array initializer of matrixl3 peripheral base addresses */
  #define matrixl3_BASE_ADDRS_NS                   { DISPLAY__SEERIS__MATRIXL3_BASE_NS }
  /** Array initializer of matrixl3 peripheral base pointers */
  #define matrixl3_BASE_PTRS_NS                    { DISPLAY__SEERIS__MATRIXL3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__MATRIXL3 base address */
  #define DISPLAY__SEERIS__MATRIXL3_BASE           (0x4B750030u)
  /** Peripheral DISPLAY__SEERIS__MATRIXL3 base pointer */
  #define DISPLAY__SEERIS__MATRIXL3                ((matrixl3_Type *)DISPLAY__SEERIS__MATRIXL3_BASE)
  /** Array initializer of matrixl3 peripheral base addresses */
  #define matrixl3_BASE_ADDRS                      { DISPLAY__SEERIS__MATRIXL3_BASE }
  /** Array initializer of matrixl3 peripheral base pointers */
  #define matrixl3_BASE_PTRS                       { DISPLAY__SEERIS__MATRIXL3 }
#endif

/* rop - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__ROP base address */
  #define DISPLAY__SEERIS__ROP_BASE                (0x5B440000u)
  /** Peripheral DISPLAY__SEERIS__ROP base address */
  #define DISPLAY__SEERIS__ROP_BASE_NS             (0x4B440000u)
  /** Peripheral DISPLAY__SEERIS__ROP base pointer */
  #define DISPLAY__SEERIS__ROP                     ((rop_Type *)DISPLAY__SEERIS__ROP_BASE)
  /** Peripheral DISPLAY__SEERIS__ROP base pointer */
  #define DISPLAY__SEERIS__ROP_NS                  ((rop_Type *)DISPLAY__SEERIS__ROP_BASE_NS)
  /** Array initializer of rop peripheral base addresses */
  #define rop_BASE_ADDRS                           { DISPLAY__SEERIS__ROP_BASE }
  /** Array initializer of rop peripheral base pointers */
  #define rop_BASE_PTRS                            { DISPLAY__SEERIS__ROP }
  /** Array initializer of rop peripheral base addresses */
  #define rop_BASE_ADDRS_NS                        { DISPLAY__SEERIS__ROP_BASE_NS }
  /** Array initializer of rop peripheral base pointers */
  #define rop_BASE_PTRS_NS                         { DISPLAY__SEERIS__ROP_NS }
#else
  /** Peripheral DISPLAY__SEERIS__ROP base address */
  #define DISPLAY__SEERIS__ROP_BASE                (0x4B440000u)
  /** Peripheral DISPLAY__SEERIS__ROP base pointer */
  #define DISPLAY__SEERIS__ROP                     ((rop_Type *)DISPLAY__SEERIS__ROP_BASE)
  /** Array initializer of rop peripheral base addresses */
  #define rop_BASE_ADDRS                           { DISPLAY__SEERIS__ROP_BASE }
  /** Array initializer of rop peripheral base pointers */
  #define rop_BASE_PTRS                            { DISPLAY__SEERIS__ROP }
#endif

/* rop9cfg - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__ROP9CFG base address */
  #define DISPLAY__SEERIS__ROP9CFG_BASE            (0x5B441000u)
  /** Peripheral DISPLAY__SEERIS__ROP9CFG base address */
  #define DISPLAY__SEERIS__ROP9CFG_BASE_NS         (0x4B441000u)
  /** Peripheral DISPLAY__SEERIS__ROP9CFG base pointer */
  #define DISPLAY__SEERIS__ROP9CFG                 ((rop9cfg_Type *)DISPLAY__SEERIS__ROP9CFG_BASE)
  /** Peripheral DISPLAY__SEERIS__ROP9CFG base pointer */
  #define DISPLAY__SEERIS__ROP9CFG_NS              ((rop9cfg_Type *)DISPLAY__SEERIS__ROP9CFG_BASE_NS)
  /** Array initializer of rop9cfg peripheral base addresses */
  #define rop9cfg_BASE_ADDRS                       { DISPLAY__SEERIS__ROP9CFG_BASE }
  /** Array initializer of rop9cfg peripheral base pointers */
  #define rop9cfg_BASE_PTRS                        { DISPLAY__SEERIS__ROP9CFG }
  /** Array initializer of rop9cfg peripheral base addresses */
  #define rop9cfg_BASE_ADDRS_NS                    { DISPLAY__SEERIS__ROP9CFG_BASE_NS }
  /** Array initializer of rop9cfg peripheral base pointers */
  #define rop9cfg_BASE_PTRS_NS                     { DISPLAY__SEERIS__ROP9CFG_NS }
#else
  /** Peripheral DISPLAY__SEERIS__ROP9CFG base address */
  #define DISPLAY__SEERIS__ROP9CFG_BASE            (0x4B441000u)
  /** Peripheral DISPLAY__SEERIS__ROP9CFG base pointer */
  #define DISPLAY__SEERIS__ROP9CFG                 ((rop9cfg_Type *)DISPLAY__SEERIS__ROP9CFG_BASE)
  /** Array initializer of rop9cfg peripheral base addresses */
  #define rop9cfg_BASE_ADDRS                       { DISPLAY__SEERIS__ROP9CFG_BASE }
  /** Array initializer of rop9cfg peripheral base pointers */
  #define rop9cfg_BASE_PTRS                        { DISPLAY__SEERIS__ROP9CFG }
#endif

/* sig - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__SIG base address */
  #define DISPLAY__SEERIS__SIG_BASE                (0x5B710000u)
  /** Peripheral DISPLAY__SEERIS__SIG base address */
  #define DISPLAY__SEERIS__SIG_BASE_NS             (0x4B710000u)
  /** Peripheral DISPLAY__SEERIS__SIG base pointer */
  #define DISPLAY__SEERIS__SIG                     ((sig_Type *)DISPLAY__SEERIS__SIG_BASE)
  /** Peripheral DISPLAY__SEERIS__SIG base pointer */
  #define DISPLAY__SEERIS__SIG_NS                  ((sig_Type *)DISPLAY__SEERIS__SIG_BASE_NS)
  /** Array initializer of sig peripheral base addresses */
  #define sig_BASE_ADDRS                           { DISPLAY__SEERIS__SIG_BASE }
  /** Array initializer of sig peripheral base pointers */
  #define sig_BASE_PTRS                            { DISPLAY__SEERIS__SIG }
  /** Array initializer of sig peripheral base addresses */
  #define sig_BASE_ADDRS_NS                        { DISPLAY__SEERIS__SIG_BASE_NS }
  /** Array initializer of sig peripheral base pointers */
  #define sig_BASE_PTRS_NS                         { DISPLAY__SEERIS__SIG_NS }
#else
  /** Peripheral DISPLAY__SEERIS__SIG base address */
  #define DISPLAY__SEERIS__SIG_BASE                (0x4B710000u)
  /** Peripheral DISPLAY__SEERIS__SIG base pointer */
  #define DISPLAY__SEERIS__SIG                     ((sig_Type *)DISPLAY__SEERIS__SIG_BASE)
  /** Array initializer of sig peripheral base addresses */
  #define sig_BASE_ADDRS                           { DISPLAY__SEERIS__SIG_BASE }
  /** Array initializer of sig peripheral base pointers */
  #define sig_BASE_PTRS                            { DISPLAY__SEERIS__SIG }
#endif

/* sig0cfg - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__SIG0CFG base address */
  #define DISPLAY__SEERIS__SIG0CFG_BASE            (0x5B711000u)
  /** Peripheral DISPLAY__SEERIS__SIG0CFG base address */
  #define DISPLAY__SEERIS__SIG0CFG_BASE_NS         (0x4B711000u)
  /** Peripheral DISPLAY__SEERIS__SIG0CFG base pointer */
  #define DISPLAY__SEERIS__SIG0CFG                 ((sig0cfg_Type *)DISPLAY__SEERIS__SIG0CFG_BASE)
  /** Peripheral DISPLAY__SEERIS__SIG0CFG base pointer */
  #define DISPLAY__SEERIS__SIG0CFG_NS              ((sig0cfg_Type *)DISPLAY__SEERIS__SIG0CFG_BASE_NS)
  /** Array initializer of sig0cfg peripheral base addresses */
  #define sig0cfg_BASE_ADDRS                       { DISPLAY__SEERIS__SIG0CFG_BASE }
  /** Array initializer of sig0cfg peripheral base pointers */
  #define sig0cfg_BASE_PTRS                        { DISPLAY__SEERIS__SIG0CFG }
  /** Array initializer of sig0cfg peripheral base addresses */
  #define sig0cfg_BASE_ADDRS_NS                    { DISPLAY__SEERIS__SIG0CFG_BASE_NS }
  /** Array initializer of sig0cfg peripheral base pointers */
  #define sig0cfg_BASE_PTRS_NS                     { DISPLAY__SEERIS__SIG0CFG_NS }
#else
  /** Peripheral DISPLAY__SEERIS__SIG0CFG base address */
  #define DISPLAY__SEERIS__SIG0CFG_BASE            (0x4B711000u)
  /** Peripheral DISPLAY__SEERIS__SIG0CFG base pointer */
  #define DISPLAY__SEERIS__SIG0CFG                 ((sig0cfg_Type *)DISPLAY__SEERIS__SIG0CFG_BASE)
  /** Array initializer of sig0cfg peripheral base addresses */
  #define sig0cfg_BASE_ADDRS                       { DISPLAY__SEERIS__SIG0CFG_BASE }
  /** Array initializer of sig0cfg peripheral base pointers */
  #define sig0cfg_BASE_PTRS                        { DISPLAY__SEERIS__SIG0CFG }
#endif

/* sig1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__SIG1 base address */
  #define DISPLAY__SEERIS__SIG1_BASE               (0x5B710400u)
  /** Peripheral DISPLAY__SEERIS__SIG1 base address */
  #define DISPLAY__SEERIS__SIG1_BASE_NS            (0x4B710400u)
  /** Peripheral DISPLAY__SEERIS__SIG1 base pointer */
  #define DISPLAY__SEERIS__SIG1                    ((sig1_Type *)DISPLAY__SEERIS__SIG1_BASE)
  /** Peripheral DISPLAY__SEERIS__SIG1 base pointer */
  #define DISPLAY__SEERIS__SIG1_NS                 ((sig1_Type *)DISPLAY__SEERIS__SIG1_BASE_NS)
  /** Array initializer of sig1 peripheral base addresses */
  #define sig1_BASE_ADDRS                          { DISPLAY__SEERIS__SIG1_BASE }
  /** Array initializer of sig1 peripheral base pointers */
  #define sig1_BASE_PTRS                           { DISPLAY__SEERIS__SIG1 }
  /** Array initializer of sig1 peripheral base addresses */
  #define sig1_BASE_ADDRS_NS                       { DISPLAY__SEERIS__SIG1_BASE_NS }
  /** Array initializer of sig1 peripheral base pointers */
  #define sig1_BASE_PTRS_NS                        { DISPLAY__SEERIS__SIG1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__SIG1 base address */
  #define DISPLAY__SEERIS__SIG1_BASE               (0x4B710400u)
  /** Peripheral DISPLAY__SEERIS__SIG1 base pointer */
  #define DISPLAY__SEERIS__SIG1                    ((sig1_Type *)DISPLAY__SEERIS__SIG1_BASE)
  /** Array initializer of sig1 peripheral base addresses */
  #define sig1_BASE_ADDRS                          { DISPLAY__SEERIS__SIG1_BASE }
  /** Array initializer of sig1 peripheral base pointers */
  #define sig1_BASE_PTRS                           { DISPLAY__SEERIS__SIG1 }
#endif

/* sig1cfg - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__SIG1CFG base address */
  #define DISPLAY__SEERIS__SIG1CFG_BASE            (0x5B7A1000u)
  /** Peripheral DISPLAY__SEERIS__SIG1CFG base address */
  #define DISPLAY__SEERIS__SIG1CFG_BASE_NS         (0x4B7A1000u)
  /** Peripheral DISPLAY__SEERIS__SIG1CFG base pointer */
  #define DISPLAY__SEERIS__SIG1CFG                 ((sig1cfg_Type *)DISPLAY__SEERIS__SIG1CFG_BASE)
  /** Peripheral DISPLAY__SEERIS__SIG1CFG base pointer */
  #define DISPLAY__SEERIS__SIG1CFG_NS              ((sig1cfg_Type *)DISPLAY__SEERIS__SIG1CFG_BASE_NS)
  /** Array initializer of sig1cfg peripheral base addresses */
  #define sig1cfg_BASE_ADDRS                       { DISPLAY__SEERIS__SIG1CFG_BASE }
  /** Array initializer of sig1cfg peripheral base pointers */
  #define sig1cfg_BASE_PTRS                        { DISPLAY__SEERIS__SIG1CFG }
  /** Array initializer of sig1cfg peripheral base addresses */
  #define sig1cfg_BASE_ADDRS_NS                    { DISPLAY__SEERIS__SIG1CFG_BASE_NS }
  /** Array initializer of sig1cfg peripheral base pointers */
  #define sig1cfg_BASE_PTRS_NS                     { DISPLAY__SEERIS__SIG1CFG_NS }
#else
  /** Peripheral DISPLAY__SEERIS__SIG1CFG base address */
  #define DISPLAY__SEERIS__SIG1CFG_BASE            (0x4B7A1000u)
  /** Peripheral DISPLAY__SEERIS__SIG1CFG base pointer */
  #define DISPLAY__SEERIS__SIG1CFG                 ((sig1cfg_Type *)DISPLAY__SEERIS__SIG1CFG_BASE)
  /** Array initializer of sig1cfg peripheral base addresses */
  #define sig1cfg_BASE_ADDRS                       { DISPLAY__SEERIS__SIG1CFG_BASE }
  /** Array initializer of sig1cfg peripheral base pointers */
  #define sig1cfg_BASE_PTRS                        { DISPLAY__SEERIS__SIG1CFG }
#endif

/* sig2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__SIG2 base address */
  #define DISPLAY__SEERIS__SIG2_BASE               (0x5B7A0000u)
  /** Peripheral DISPLAY__SEERIS__SIG2 base address */
  #define DISPLAY__SEERIS__SIG2_BASE_NS            (0x4B7A0000u)
  /** Peripheral DISPLAY__SEERIS__SIG2 base pointer */
  #define DISPLAY__SEERIS__SIG2                    ((sig2_Type *)DISPLAY__SEERIS__SIG2_BASE)
  /** Peripheral DISPLAY__SEERIS__SIG2 base pointer */
  #define DISPLAY__SEERIS__SIG2_NS                 ((sig2_Type *)DISPLAY__SEERIS__SIG2_BASE_NS)
  /** Array initializer of sig2 peripheral base addresses */
  #define sig2_BASE_ADDRS                          { DISPLAY__SEERIS__SIG2_BASE }
  /** Array initializer of sig2 peripheral base pointers */
  #define sig2_BASE_PTRS                           { DISPLAY__SEERIS__SIG2 }
  /** Array initializer of sig2 peripheral base addresses */
  #define sig2_BASE_ADDRS_NS                       { DISPLAY__SEERIS__SIG2_BASE_NS }
  /** Array initializer of sig2 peripheral base pointers */
  #define sig2_BASE_PTRS_NS                        { DISPLAY__SEERIS__SIG2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__SIG2 base address */
  #define DISPLAY__SEERIS__SIG2_BASE               (0x4B7A0000u)
  /** Peripheral DISPLAY__SEERIS__SIG2 base pointer */
  #define DISPLAY__SEERIS__SIG2                    ((sig2_Type *)DISPLAY__SEERIS__SIG2_BASE)
  /** Array initializer of sig2 peripheral base addresses */
  #define sig2_BASE_ADDRS                          { DISPLAY__SEERIS__SIG2_BASE }
  /** Array initializer of sig2 peripheral base pointers */
  #define sig2_BASE_PTRS                           { DISPLAY__SEERIS__SIG2 }
#endif

/* sig3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__SIG3 base address */
  #define DISPLAY__SEERIS__SIG3_BASE               (0x5B7A0400u)
  /** Peripheral DISPLAY__SEERIS__SIG3 base address */
  #define DISPLAY__SEERIS__SIG3_BASE_NS            (0x4B7A0400u)
  /** Peripheral DISPLAY__SEERIS__SIG3 base pointer */
  #define DISPLAY__SEERIS__SIG3                    ((sig3_Type *)DISPLAY__SEERIS__SIG3_BASE)
  /** Peripheral DISPLAY__SEERIS__SIG3 base pointer */
  #define DISPLAY__SEERIS__SIG3_NS                 ((sig3_Type *)DISPLAY__SEERIS__SIG3_BASE_NS)
  /** Array initializer of sig3 peripheral base addresses */
  #define sig3_BASE_ADDRS                          { DISPLAY__SEERIS__SIG3_BASE }
  /** Array initializer of sig3 peripheral base pointers */
  #define sig3_BASE_PTRS                           { DISPLAY__SEERIS__SIG3 }
  /** Array initializer of sig3 peripheral base addresses */
  #define sig3_BASE_ADDRS_NS                       { DISPLAY__SEERIS__SIG3_BASE_NS }
  /** Array initializer of sig3 peripheral base pointers */
  #define sig3_BASE_PTRS_NS                        { DISPLAY__SEERIS__SIG3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__SIG3 base address */
  #define DISPLAY__SEERIS__SIG3_BASE               (0x4B7A0400u)
  /** Peripheral DISPLAY__SEERIS__SIG3 base pointer */
  #define DISPLAY__SEERIS__SIG3                    ((sig3_Type *)DISPLAY__SEERIS__SIG3_BASE)
  /** Array initializer of sig3 peripheral base addresses */
  #define sig3_BASE_ADDRS                          { DISPLAY__SEERIS__SIG3_BASE }
  /** Array initializer of sig3 peripheral base pointers */
  #define sig3_BASE_PTRS                           { DISPLAY__SEERIS__SIG3 }
#endif

/* splanar - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__SPLANAR base address */
  #define DISPLAY__SEERIS__SPLANAR_BASE            (0x5B4E0000u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR base address */
  #define DISPLAY__SEERIS__SPLANAR_BASE_NS         (0x4B4E0000u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR base pointer */
  #define DISPLAY__SEERIS__SPLANAR                 ((splanar_Type *)DISPLAY__SEERIS__SPLANAR_BASE)
  /** Peripheral DISPLAY__SEERIS__SPLANAR base pointer */
  #define DISPLAY__SEERIS__SPLANAR_NS              ((splanar_Type *)DISPLAY__SEERIS__SPLANAR_BASE_NS)
  /** Array initializer of splanar peripheral base addresses */
  #define splanar_BASE_ADDRS                       { DISPLAY__SEERIS__SPLANAR_BASE }
  /** Array initializer of splanar peripheral base pointers */
  #define splanar_BASE_PTRS                        { DISPLAY__SEERIS__SPLANAR }
  /** Array initializer of splanar peripheral base addresses */
  #define splanar_BASE_ADDRS_NS                    { DISPLAY__SEERIS__SPLANAR_BASE_NS }
  /** Array initializer of splanar peripheral base pointers */
  #define splanar_BASE_PTRS_NS                     { DISPLAY__SEERIS__SPLANAR_NS }
#else
  /** Peripheral DISPLAY__SEERIS__SPLANAR base address */
  #define DISPLAY__SEERIS__SPLANAR_BASE            (0x4B4E0000u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR base pointer */
  #define DISPLAY__SEERIS__SPLANAR                 ((splanar_Type *)DISPLAY__SEERIS__SPLANAR_BASE)
  /** Array initializer of splanar peripheral base addresses */
  #define splanar_BASE_ADDRS                       { DISPLAY__SEERIS__SPLANAR_BASE }
  /** Array initializer of splanar peripheral base pointers */
  #define splanar_BASE_PTRS                        { DISPLAY__SEERIS__SPLANAR }
#endif

/* splanar1 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__SPLANAR1 base address */
  #define DISPLAY__SEERIS__SPLANAR1_BASE           (0x5B4E0038u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR1 base address */
  #define DISPLAY__SEERIS__SPLANAR1_BASE_NS        (0x4B4E0038u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR1 base pointer */
  #define DISPLAY__SEERIS__SPLANAR1                ((splanar1_Type *)DISPLAY__SEERIS__SPLANAR1_BASE)
  /** Peripheral DISPLAY__SEERIS__SPLANAR1 base pointer */
  #define DISPLAY__SEERIS__SPLANAR1_NS             ((splanar1_Type *)DISPLAY__SEERIS__SPLANAR1_BASE_NS)
  /** Array initializer of splanar1 peripheral base addresses */
  #define splanar1_BASE_ADDRS                      { DISPLAY__SEERIS__SPLANAR1_BASE }
  /** Array initializer of splanar1 peripheral base pointers */
  #define splanar1_BASE_PTRS                       { DISPLAY__SEERIS__SPLANAR1 }
  /** Array initializer of splanar1 peripheral base addresses */
  #define splanar1_BASE_ADDRS_NS                   { DISPLAY__SEERIS__SPLANAR1_BASE_NS }
  /** Array initializer of splanar1 peripheral base pointers */
  #define splanar1_BASE_PTRS_NS                    { DISPLAY__SEERIS__SPLANAR1_NS }
#else
  /** Peripheral DISPLAY__SEERIS__SPLANAR1 base address */
  #define DISPLAY__SEERIS__SPLANAR1_BASE           (0x4B4E0038u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR1 base pointer */
  #define DISPLAY__SEERIS__SPLANAR1                ((splanar1_Type *)DISPLAY__SEERIS__SPLANAR1_BASE)
  /** Array initializer of splanar1 peripheral base addresses */
  #define splanar1_BASE_ADDRS                      { DISPLAY__SEERIS__SPLANAR1_BASE }
  /** Array initializer of splanar1 peripheral base pointers */
  #define splanar1_BASE_PTRS                       { DISPLAY__SEERIS__SPLANAR1 }
#endif

/* splanar2 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__SPLANAR2 base address */
  #define DISPLAY__SEERIS__SPLANAR2_BASE           (0x5B4E0048u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR2 base address */
  #define DISPLAY__SEERIS__SPLANAR2_BASE_NS        (0x4B4E0048u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR2 base pointer */
  #define DISPLAY__SEERIS__SPLANAR2                ((splanar2_Type *)DISPLAY__SEERIS__SPLANAR2_BASE)
  /** Peripheral DISPLAY__SEERIS__SPLANAR2 base pointer */
  #define DISPLAY__SEERIS__SPLANAR2_NS             ((splanar2_Type *)DISPLAY__SEERIS__SPLANAR2_BASE_NS)
  /** Array initializer of splanar2 peripheral base addresses */
  #define splanar2_BASE_ADDRS                      { DISPLAY__SEERIS__SPLANAR2_BASE }
  /** Array initializer of splanar2 peripheral base pointers */
  #define splanar2_BASE_PTRS                       { DISPLAY__SEERIS__SPLANAR2 }
  /** Array initializer of splanar2 peripheral base addresses */
  #define splanar2_BASE_ADDRS_NS                   { DISPLAY__SEERIS__SPLANAR2_BASE_NS }
  /** Array initializer of splanar2 peripheral base pointers */
  #define splanar2_BASE_PTRS_NS                    { DISPLAY__SEERIS__SPLANAR2_NS }
#else
  /** Peripheral DISPLAY__SEERIS__SPLANAR2 base address */
  #define DISPLAY__SEERIS__SPLANAR2_BASE           (0x4B4E0048u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR2 base pointer */
  #define DISPLAY__SEERIS__SPLANAR2                ((splanar2_Type *)DISPLAY__SEERIS__SPLANAR2_BASE)
  /** Array initializer of splanar2 peripheral base addresses */
  #define splanar2_BASE_ADDRS                      { DISPLAY__SEERIS__SPLANAR2_BASE }
  /** Array initializer of splanar2 peripheral base pointers */
  #define splanar2_BASE_PTRS                       { DISPLAY__SEERIS__SPLANAR2 }
#endif

/* splanar3 - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__SPLANAR3 base address */
  #define DISPLAY__SEERIS__SPLANAR3_BASE           (0x5B4E0070u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR3 base address */
  #define DISPLAY__SEERIS__SPLANAR3_BASE_NS        (0x4B4E0070u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR3 base pointer */
  #define DISPLAY__SEERIS__SPLANAR3                ((splanar3_Type *)DISPLAY__SEERIS__SPLANAR3_BASE)
  /** Peripheral DISPLAY__SEERIS__SPLANAR3 base pointer */
  #define DISPLAY__SEERIS__SPLANAR3_NS             ((splanar3_Type *)DISPLAY__SEERIS__SPLANAR3_BASE_NS)
  /** Array initializer of splanar3 peripheral base addresses */
  #define splanar3_BASE_ADDRS                      { DISPLAY__SEERIS__SPLANAR3_BASE }
  /** Array initializer of splanar3 peripheral base pointers */
  #define splanar3_BASE_PTRS                       { DISPLAY__SEERIS__SPLANAR3 }
  /** Array initializer of splanar3 peripheral base addresses */
  #define splanar3_BASE_ADDRS_NS                   { DISPLAY__SEERIS__SPLANAR3_BASE_NS }
  /** Array initializer of splanar3 peripheral base pointers */
  #define splanar3_BASE_PTRS_NS                    { DISPLAY__SEERIS__SPLANAR3_NS }
#else
  /** Peripheral DISPLAY__SEERIS__SPLANAR3 base address */
  #define DISPLAY__SEERIS__SPLANAR3_BASE           (0x4B4E0070u)
  /** Peripheral DISPLAY__SEERIS__SPLANAR3 base pointer */
  #define DISPLAY__SEERIS__SPLANAR3                ((splanar3_Type *)DISPLAY__SEERIS__SPLANAR3_BASE)
  /** Array initializer of splanar3 peripheral base addresses */
  #define splanar3_BASE_ADDRS                      { DISPLAY__SEERIS__SPLANAR3_BASE }
  /** Array initializer of splanar3 peripheral base pointers */
  #define splanar3_BASE_PTRS                       { DISPLAY__SEERIS__SPLANAR3 }
#endif

/* store9c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__STORE9C base address */
  #define DISPLAY__SEERIS__STORE9C_BASE            (0x5B4E1000u)
  /** Peripheral DISPLAY__SEERIS__STORE9C base address */
  #define DISPLAY__SEERIS__STORE9C_BASE_NS         (0x4B4E1000u)
  /** Peripheral DISPLAY__SEERIS__STORE9C base pointer */
  #define DISPLAY__SEERIS__STORE9C                 ((store9c_Type *)DISPLAY__SEERIS__STORE9C_BASE)
  /** Peripheral DISPLAY__SEERIS__STORE9C base pointer */
  #define DISPLAY__SEERIS__STORE9C_NS              ((store9c_Type *)DISPLAY__SEERIS__STORE9C_BASE_NS)
  /** Array initializer of store9c peripheral base addresses */
  #define store9c_BASE_ADDRS                       { DISPLAY__SEERIS__STORE9C_BASE }
  /** Array initializer of store9c peripheral base pointers */
  #define store9c_BASE_PTRS                        { DISPLAY__SEERIS__STORE9C }
  /** Array initializer of store9c peripheral base addresses */
  #define store9c_BASE_ADDRS_NS                    { DISPLAY__SEERIS__STORE9C_BASE_NS }
  /** Array initializer of store9c peripheral base pointers */
  #define store9c_BASE_PTRS_NS                     { DISPLAY__SEERIS__STORE9C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__STORE9C base address */
  #define DISPLAY__SEERIS__STORE9C_BASE            (0x4B4E1000u)
  /** Peripheral DISPLAY__SEERIS__STORE9C base pointer */
  #define DISPLAY__SEERIS__STORE9C                 ((store9c_Type *)DISPLAY__SEERIS__STORE9C_BASE)
  /** Array initializer of store9c peripheral base addresses */
  #define store9c_BASE_ADDRS                       { DISPLAY__SEERIS__STORE9C_BASE }
  /** Array initializer of store9c peripheral base pointers */
  #define store9c_BASE_PTRS                        { DISPLAY__SEERIS__STORE9C }
#endif

/* vsclr4c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__VSCLR4C base address */
  #define DISPLAY__SEERIS__VSCLR4C_BASE            (0x5B4C1000u)
  /** Peripheral DISPLAY__SEERIS__VSCLR4C base address */
  #define DISPLAY__SEERIS__VSCLR4C_BASE_NS         (0x4B4C1000u)
  /** Peripheral DISPLAY__SEERIS__VSCLR4C base pointer */
  #define DISPLAY__SEERIS__VSCLR4C                 ((vsclr4c_Type *)DISPLAY__SEERIS__VSCLR4C_BASE)
  /** Peripheral DISPLAY__SEERIS__VSCLR4C base pointer */
  #define DISPLAY__SEERIS__VSCLR4C_NS              ((vsclr4c_Type *)DISPLAY__SEERIS__VSCLR4C_BASE_NS)
  /** Array initializer of vsclr4c peripheral base addresses */
  #define vsclr4c_BASE_ADDRS                       { DISPLAY__SEERIS__VSCLR4C_BASE }
  /** Array initializer of vsclr4c peripheral base pointers */
  #define vsclr4c_BASE_PTRS                        { DISPLAY__SEERIS__VSCLR4C }
  /** Array initializer of vsclr4c peripheral base addresses */
  #define vsclr4c_BASE_ADDRS_NS                    { DISPLAY__SEERIS__VSCLR4C_BASE_NS }
  /** Array initializer of vsclr4c peripheral base pointers */
  #define vsclr4c_BASE_PTRS_NS                     { DISPLAY__SEERIS__VSCLR4C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__VSCLR4C base address */
  #define DISPLAY__SEERIS__VSCLR4C_BASE            (0x4B4C1000u)
  /** Peripheral DISPLAY__SEERIS__VSCLR4C base pointer */
  #define DISPLAY__SEERIS__VSCLR4C                 ((vsclr4c_Type *)DISPLAY__SEERIS__VSCLR4C_BASE)
  /** Array initializer of vsclr4c peripheral base addresses */
  #define vsclr4c_BASE_ADDRS                       { DISPLAY__SEERIS__VSCLR4C_BASE }
  /** Array initializer of vsclr4c peripheral base pointers */
  #define vsclr4c_BASE_PTRS                        { DISPLAY__SEERIS__VSCLR4C }
#endif

/* vsclr9c - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__VSCLR9C base address */
  #define DISPLAY__SEERIS__VSCLR9C_BASE            (0x5B651000u)
  /** Peripheral DISPLAY__SEERIS__VSCLR9C base address */
  #define DISPLAY__SEERIS__VSCLR9C_BASE_NS         (0x4B651000u)
  /** Peripheral DISPLAY__SEERIS__VSCLR9C base pointer */
  #define DISPLAY__SEERIS__VSCLR9C                 ((vsclr9c_Type *)DISPLAY__SEERIS__VSCLR9C_BASE)
  /** Peripheral DISPLAY__SEERIS__VSCLR9C base pointer */
  #define DISPLAY__SEERIS__VSCLR9C_NS              ((vsclr9c_Type *)DISPLAY__SEERIS__VSCLR9C_BASE_NS)
  /** Array initializer of vsclr9c peripheral base addresses */
  #define vsclr9c_BASE_ADDRS                       { DISPLAY__SEERIS__VSCLR9C_BASE }
  /** Array initializer of vsclr9c peripheral base pointers */
  #define vsclr9c_BASE_PTRS                        { DISPLAY__SEERIS__VSCLR9C }
  /** Array initializer of vsclr9c peripheral base addresses */
  #define vsclr9c_BASE_ADDRS_NS                    { DISPLAY__SEERIS__VSCLR9C_BASE_NS }
  /** Array initializer of vsclr9c peripheral base pointers */
  #define vsclr9c_BASE_PTRS_NS                     { DISPLAY__SEERIS__VSCLR9C_NS }
#else
  /** Peripheral DISPLAY__SEERIS__VSCLR9C base address */
  #define DISPLAY__SEERIS__VSCLR9C_BASE            (0x4B651000u)
  /** Peripheral DISPLAY__SEERIS__VSCLR9C base pointer */
  #define DISPLAY__SEERIS__VSCLR9C                 ((vsclr9c_Type *)DISPLAY__SEERIS__VSCLR9C_BASE)
  /** Array initializer of vsclr9c peripheral base addresses */
  #define vsclr9c_BASE_ADDRS                       { DISPLAY__SEERIS__VSCLR9C_BASE }
  /** Array initializer of vsclr9c peripheral base pointers */
  #define vsclr9c_BASE_PTRS                        { DISPLAY__SEERIS__VSCLR9C }
#endif

/* xpc - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
  /** Peripheral DISPLAY__SEERIS__XPC base address */
  #define DISPLAY__SEERIS__XPC_BASE                (0x5B420000u)
  /** Peripheral DISPLAY__SEERIS__XPC base address */
  #define DISPLAY__SEERIS__XPC_BASE_NS             (0x4B420000u)
  /** Peripheral DISPLAY__SEERIS__XPC base pointer */
  #define DISPLAY__SEERIS__XPC                     ((xpc_Type *)DISPLAY__SEERIS__XPC_BASE)
  /** Peripheral DISPLAY__SEERIS__XPC base pointer */
  #define DISPLAY__SEERIS__XPC_NS                  ((xpc_Type *)DISPLAY__SEERIS__XPC_BASE_NS)
  /** Array initializer of xpc peripheral base addresses */
  #define xpc_BASE_ADDRS                           { DISPLAY__SEERIS__XPC_BASE }
  /** Array initializer of xpc peripheral base pointers */
  #define xpc_BASE_PTRS                            { DISPLAY__SEERIS__XPC }
  /** Array initializer of xpc peripheral base addresses */
  #define xpc_BASE_ADDRS_NS                        { DISPLAY__SEERIS__XPC_BASE_NS }
  /** Array initializer of xpc peripheral base pointers */
  #define xpc_BASE_PTRS_NS                         { DISPLAY__SEERIS__XPC_NS }
#else
  /** Peripheral DISPLAY__SEERIS__XPC base address */
  #define DISPLAY__SEERIS__XPC_BASE                (0x4B420000u)
  /** Peripheral DISPLAY__SEERIS__XPC base pointer */
  #define DISPLAY__SEERIS__XPC                     ((xpc_Type *)DISPLAY__SEERIS__XPC_BASE)
  /** Array initializer of xpc peripheral base addresses */
  #define xpc_BASE_ADDRS                           { DISPLAY__SEERIS__XPC_BASE }
  /** Array initializer of xpc peripheral base pointers */
  #define xpc_BASE_PTRS                            { DISPLAY__SEERIS__XPC }
#endif

/* ----------------------------------------------------------------------------
   -- Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Bit_Field_Generic_Macros Macros for use with bit field definitions (xxx_SHIFT, xxx_MASK).
 * @{
 */

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang system_header
  #endif
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma system_include
#endif

/**
 * @brief Mask and left-shift a bit field value for use in a register bit range.
 * @param field Name of the register bit field.
 * @param value Value of the bit field.
 * @return Masked and shifted value.
 */
#define NXP_VAL2FLD(field, value)    (((value) << (field ## _SHIFT)) & (field ## _MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value)    (((value) & (field ## _MASK)) >> (field ## _SHIFT))

/*!
 * @}
 */ /* end of group Bit_Field_Generic_Macros */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* MIMX9375_CM33_COMMON_H_ */

