/*
** ###################################################################
**     Processors:          MIMX95_cm33
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX9592_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**
** ###################################################################
*/

/*!
 * @file MIMX95_COMMON.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for MIMX95_cm33
 *
 * CMSIS Peripheral Access Layer for MIMX95_cm33
 */

#ifndef _MIMX95_COMMON_H_
#define _MIMX95_COMMON_H_                        /**< Symbol preventing repeated inclusion */

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
#define NUMBER_OF_INT_VECTORS 392 /**< Number of interrupts in the Vector table */

typedef enum IRQn
{
    /* Auxiliary constants */
    NotAvail_IRQn = -128, /**< Not available device specific interrupt */

    /* Core interrupts */
    NonMaskableInt_IRQn   = -14, /**< Non Maskable Interrupt */
    HardFault_IRQn        = -13, /**< Cortex-M33 SV Hard Fault Interrupt */
    MemoryManagement_IRQn = -12, /**< Cortex-M33 Memory Management Interrupt */
    BusFault_IRQn         = -11, /**< Cortex-M33 Bus Fault Interrupt */
    UsageFault_IRQn       = -10, /**< Cortex-M33 Usage Fault Interrupt */
    SecureFault_IRQn      = -9,  /**< Cortex-M33 Secure Fault Interrupt */
    SVCall_IRQn           = -5,  /**< Cortex-M33 SV Call Interrupt */
    DebugMonitor_IRQn     = -4,  /**< Cortex-M33 Debug Monitor Interrupt */
    PendSV_IRQn           = -2,  /**< Cortex-M33 Pend SV Interrupt */
    SysTick_IRQn          = -1,  /**< Cortex-M33 System Tick Interrupt */

    /* Device specific interrupts */
    Reserved16_IRQn    = 0,   /**< Reserved interrupt */
    Reserved17_IRQn    = 1,   /**< DAP interrupt */
    Reserved18_IRQn    = 2,   /**< CTI trigger outputs from CM7 platform */
    Reserved19_IRQn    = 3,   /**< CTI trigger outputs from CM33 platform */
    Reserved20_IRQn    = 4,   /**< CTI trigger outputs from CA55 platform */
    Reserved21_IRQn    = 5,   /**< Performance Unit Interrupts from CA55 platform */
    Reserved22_IRQn    = 6,   /**< ECC error from CA55 platform cache */
    Reserved23_IRQn    = 7,   /**< 1-bit or 2-bit ECC or Parity error from CA55 platform cache */
    CAN1_IRQn          = 8,   /**< CAN1 interrupt */
    CAN1_ERROR_IRQn    = 9,   /**< CAN1 error interrupt */
    GPIO1_0_IRQn       = 10,  /**< General Purpose Input/Output 1 interrupt 0 */
    Reserved27_IRQn    = 11,  /**< General Purpose Input/Output 1 interrupt 1 */
    I3C1_IRQn          = 12,  /**< Improved Inter-Integrated Circuit 1 interrupt */
    LPI2C1_IRQn        = 13,  /**< Low Power Inter-Integrated Circuit module 1 */
    LPI2C2_IRQn        = 14,  /**< Low Power Inter-Integrated Circuit module 2 */
    LPIT1_IRQn         = 15,  /**< Low Power Periodic Interrupt Timer 1 */
    LPSPI1_IRQn        = 16,  /**< Low Power Serial Peripheral Interface 1 */
    LPSPI2_IRQn        = 17,  /**< Low Power Serial Peripheral Interface 2 */
    LPTMR1_IRQn        = 18,  /**< Low Power Timer 1 */
    LPUART1_IRQn       = 19,  /**< Low Power UART 1 */
    LPUART2_IRQn       = 20,  /**< Low Power UART 2 */
    Reserved37_IRQn    = 21,  /**< AONMIX Sentinel MU0 SideA interrupt */
    Reserved38_IRQn    = 22,  /**< AONMIX Sentinel MU1 SideA interrupt */
    Reserved39_IRQn    = 23,  /**< AONMIX Sentinel MU2 SideA interrupt */
    Reserved40_IRQn    = 24,  /**< AONMIX Sentinel MU3 SideA interrupt */
    Reserved41_IRQn    = 25,  /**< AONMIX Sentinel MU4 SideA interrupt */
    Reserved42_IRQn    = 26,  /**< AONMIX Sentinel MU5 SideA interrupt */
    V2X_FH_APCH0_IRQn  = 27,  /**< V2X-FH MU APCH0 (APP0) interrupt */
    V2X_FH_APHSM1_IRQn = 28,  /**< V2X-FH MU APHSM1 (HSM1) interrupt */
    TPM1_IRQn          = 29,  /**< Timer PWM module 1 */
    TPM2_IRQn          = 30,  /**< Timer PWM module 2 */
    WDOG1_IRQn         = 31,  /**< Watchdog 1 Interrupt */
    WDOG2_IRQn         = 32,  /**< Watchdog 2 Interrupt */
    TRDC_MGR_A_IRQn    = 33,  /**< AONMIX TRDC transfer error interrupt */
    SAI1_IRQn          = 34,  /**< Serial Audio Interface 1 */
    Reserved51_IRQn    = 35,  /**< AONMIX M33 PS Error */
    Reserved52_IRQn    = 36,  /**< AONMIX M33 TCM Error interrupt */
    Reserved53_IRQn    = 37,  /**< M7MIX ECC Multi-bit error */
    CAN2_IRQn          = 38,  /**< CAN2 interrupt */
    CAN2_ERROR_IRQn    = 39,  /**< CAN2 error interrupt */
    CAN3_IRQn          = 40,  /**< CAN3 interrupt */
    CAN3_ERROR_IRQn    = 41,  /**< CAN3 error interrupt */
    CAN4_IRQn          = 42,  /**< CAN4 interrupt */
    CAN4_ERROR_IRQn    = 43,  /**< CAN4 error interrupt */
    CAN5_IRQn          = 44,  /**< CAN5 interrupt */
    CAN5_ERROR_IRQn    = 45,  /**< CAN5 error interrupt */
    FLEXIO1_IRQn       = 46,  /**< Flexible IO 1 interrupt */
    FLEXIO2_IRQn       = 47,  /**< Flexible IO 2 interrupt */
    FlexSPI1_IRQn      = 48,  /**< FlexSPI controller interface interrupt 1 */
    Reserved65_IRQn    = 49,  /**< General Purpose Input/Output 2 interrupt 0 */
    Reserved66_IRQn    = 50,  /**< General Purpose Input/Output 2 interrupt 1 */
    Reserved67_IRQn    = 51,  /**< General Purpose Input/Output 3 interrupt 0 */
    Reserved68_IRQn    = 52,  /**< General Purpose Input/Output 3 interrupt 1 */
    Reserved69_IRQn    = 53,  /**< General Purpose Input/Output 4 interrupt 0 */
    Reserved70_IRQn    = 54,  /**< General Purpose Input/Output 4 interrupt 1 */
    Reserved71_IRQn    = 55,  /**< General Purpose Input/Output 5 interrupt 0 */
    Reserved72_IRQn    = 56,  /**< General Purpose Input/Output 5 interrupt 1 */
    I3C2_IRQn          = 57,  /**< Improved Inter-Integrated Circuit 2 interrupt */
    LPI2C3_IRQn        = 58,  /**< Low Power Inter-Integrated Circuit module 3 */
    LPI2C4_IRQn        = 59,  /**< Low Power Inter-Integrated Circuit module 4 */
    LPIT2_IRQn         = 60,  /**< Low Power Periodic Interrupt Timer 2 */
    LPSPI3_IRQn        = 61,  /**< Low Power Serial Peripheral Interface 3 */
    LPSPI4_IRQn        = 62,  /**< Low Power Serial Peripheral Interface 4 */
    LPTMR2_IRQn        = 63,  /**< Low Power Timer 2 */
    LPUART3_IRQn       = 64,  /**< Low Power UART 3 */
    LPUART4_IRQn       = 65,  /**< Low Power UART 4 */
    LPUART5_IRQn       = 66,  /**< Low Power UART 5 */
    LPUART6_IRQn       = 67,  /**< Low Power UART 6 */
    LPUART7_IRQn       = 68,  /**< Low Power UART 7 */
    LPUART8_IRQn       = 69,  /**< Low Power UART 8 */
    Reserved86_IRQn    = 70,  /**< MTR Master error interrupt */
    BBNSM_IRQn         = 71,  /**< BBNSM Non-Secure interrupt */
    Reserved88_IRQn    = 72,  /**< System Counter compare interrupt */
    TPM3_IRQn          = 73,  /**< Timer PWM module 3 */
    TPM4_IRQn          = 74,  /**< Timer PWM module 4 */
    TPM5_IRQn          = 75,  /**< Timer PWM module 5 */
    TPM6_IRQn          = 76,  /**< Timer PWM module 6 */
    WDOG3_IRQn         = 77,  /**< Watchdog 3 Interrupt */
    WDOG4_IRQn         = 78,  /**< Watchdog 4 Interrupt */
    WDOG5_IRQn         = 79,  /**< Watchdog 5 Interrupt */
    TMPSNS_ANA_1_IRQn  = 80,  /**< ANAMIX TempSensor non-secure interrupt from Threshold 1 */
    TMPSNS_ANA_2_IRQn  = 81,  /**< ANAMIX TempSensor non-secure interrupt from Threshold 2 */
    Reserved98_IRQn    = 82,  /**< ANAMIX TempSensor non-secure data ready interrupt */
    TMPSNS_CORTEXA_1_IRQ = 83,  /**< CORTEXAMIX TempSensor non-secure interrupt from Threshold 1 */
    TMPSNS_CORTEXA_2_IRQ = 84,  /**< CORTEXAMIX TempSensor non-secure interrupt from Threshold 2 */
    Reserved101_IRQn   = 85,  /**< CORTEXAMIX TempSensor non-secure data ready interrupt */
    uSDHC1_IRQn        = 86,  /**< ultra Secure Digital Host Controller interrupt 1 */
    uSDHC2_IRQn        = 87,  /**< ultra Secure Digital Host Controller interrupt 2 */
    Reserved104_IRQn   = 88,  /**< MEGAMIX TRDC transfer error interrupt */
    Reserved105_IRQn   = 89,  /**< NIC_WRAPPER TRDC transfer error interrupt */
    Reserved106_IRQn   = 90,  /**< NOCMIX TRDC transfer error interrupt */
    Reserved107_IRQn   = 91,  /**< DRAM controller Performance Monitor Interrupt */
    Reserved108_IRQn   = 92,  /**< DRAM controller Critical Interrupt */
    Reserved109_IRQn   = 93,  /**< DRAM Phy Critical Interrupt */
    Reserved110_IRQn   = 94,  /**< Reserved */
    DMA3_ERROR_IRQn    = 95,  /**< eDMA1 error interrupt */
    DMA3_0_IRQn        = 96,  /**< eDMA1 channel 0 interrupt */
    DMA3_1_IRQn        = 97,  /**< eDMA1 channel 1 interrupt */
    DMA3_2_IRQn        = 98,  /**< eDMA1 channel 2 interrupt */
    DMA3_3_IRQn        = 99,  /**< eDMA1 channel 3 interrupt */
    DMA3_4_IRQn        = 100, /**< eDMA1 channel 4 interrupt */
    DMA3_5_IRQn        = 101, /**< eDMA1 channel 5 interrupt */
    DMA3_6_IRQn        = 102, /**< eDMA1 channel 6 interrupt */
    DMA3_7_IRQn        = 103, /**< eDMA1 channel 7 interrupt */
    DMA3_8_IRQn        = 104, /**< eDMA1 channel 8 interrupt */
    DMA3_9_IRQn        = 105, /**< eDMA1 channel 9 interrupt */
    DMA3_10_IRQn       = 106, /**< eDMA1 channel 10 interrupt */
    DMA3_11_IRQn       = 107, /**< eDMA1 channel 11 interrupt */
    DMA3_12_IRQn       = 108, /**< eDMA1 channel 12 interrupt */
    DMA3_13_IRQn       = 109, /**< eDMA1 channel 13 interrupt */
    DMA3_14_IRQn       = 110, /**< eDMA1 channel 14 interrupt */
    DMA3_15_IRQn       = 111, /**< eDMA1 channel 15 interrupt */
    DMA3_16_IRQn       = 112, /**< eDMA1 channel 16 interrupt */
    DMA3_17_IRQn       = 113, /**< eDMA1 channel 17 interrupt */
    DMA3_18_IRQn       = 114, /**< eDMA1 channel 18 interrupt */
    DMA3_19_IRQn       = 115, /**< eDMA1 channel 19 interrupt */
    DMA3_20_IRQn       = 116, /**< eDMA1 channel 20 interrupt */
    DMA3_21_IRQn       = 117, /**< eDMA1 channel 21 interrupt */
    DMA3_22_IRQn       = 118, /**< eDMA1 channel 22 interrupt */
    DMA3_23_IRQn       = 119, /**< eDMA1 channel 23 interrupt */
    DMA3_24_IRQn       = 120, /**< eDMA1 channel 24 interrupt */
    DMA3_25_IRQn       = 121, /**< eDMA1 channel 25 interrupt */
    DMA3_26_IRQn       = 122, /**< eDMA1 channel 26 interrupt */
    DMA3_27_IRQn       = 123, /**< eDMA1 channel 27 interrupt */
    DMA3_28_IRQn       = 124, /**< eDMA1 channel 28 interrupt */
    DMA3_29_IRQn       = 125, /**< eDMA1 channel 29 interrupt */
    DMA3_30_IRQn       = 126, /**< eDMA1 channel 30 interrupt */
    DMA4_ERROR_IRQn    = 127, /**< eDMA2 error interrupt */
    DMA4_0_1_IRQn      = 128, /**< eDMA2 channel 0/1 interrupt */
    DMA4_2_3_IRQn      = 129, /**< eDMA2 channel 2/3 interrupt */
    DMA4_4_5_IRQn      = 130, /**< eDMA2 channel 4/5 interrupt */
    DMA4_6_7_IRQn      = 131, /**< eDMA2 channel 6/7 interrupt */
    DMA4_8_9_IRQn      = 132, /**< eDMA2 channel 8/9 interrupt */
    DMA4_10_11_IRQn    = 133, /**< eDMA2 channel 10/11 interrupt */
    DMA4_12_13_IRQn    = 134, /**< eDMA2 channel 12/13 interrupt */
    DMA4_14_15_IRQn    = 135, /**< eDMA2 channel 14/15 interrupt */
    DMA4_16_17_IRQn    = 136, /**< eDMA2 channel 16/17 interrupt */
    DMA4_18_19_IRQn    = 137, /**< eDMA2 channel 18/19 interrupt */
    DMA4_20_21_IRQn    = 138, /**< eDMA2 channel 20/21 interrupt */
    DMA4_22_23_IRQn    = 139, /**< eDMA2 channel 22/23 interrupt */
    DMA4_24_25_IRQn    = 140, /**< eDMA2 channel 24/25 interrupt */
    DMA4_26_27_IRQn    = 141, /**< eDMA2 channel 26/27 interrupt */
    DMA4_28_29_IRQn    = 142, /**< eDMA2 channel 28/29 interrupt */
    DMA4_30_31_IRQn    = 143, /**< eDMA2 channel 30/31 interrupt */
    DMA4_32_33_IRQn    = 144, /**< eDMA2 channel 32/33 interrupt */
    DMA4_34_35_IRQn    = 145, /**< eDMA2 channel 34/35 interrupt */
    DMA4_36_37_IRQn    = 146, /**< eDMA2 channel 36/37 interrupt */
    DMA4_38_39_IRQn    = 147, /**< eDMA2 channel 38/39 interrupt */
    DMA4_40_41_IRQn    = 148, /**< eDMA2 channel 40/41 interrupt */
    DMA4_42_43_IRQn    = 149, /**< eDMA2 channel 42/43 interrupt */
    DMA4_44_45_IRQn    = 150, /**< eDMA2 channel 44/45 interrupt */
    DMA4_46_47_IRQn    = 151, /**< eDMA2 channel 46/47 interrupt */
    DMA4_48_49_IRQn    = 152, /**< eDMA2 channel 48/49 interrupt */
    DMA4_50_51_IRQn    = 153, /**< eDMA2 channel 50/51 interrupt */
    DMA4_52_53_IRQn    = 154, /**< eDMA2 channel 52/53 interrupt */
    DMA4_54_55_IRQn    = 155, /**< eDMA2 channel 54/55 interrupt */
    DMA4_56_57_IRQn    = 156, /**< eDMA2 channel 56/57 interrupt */
    DMA4_58_59_IRQn    = 157, /**< eDMA2 channel 58/59 interrupt */
    DMA4_60_61_IRQn    = 158, /**< eDMA2 channel 60/61 interrupt */
    DMA4_62_63_IRQn    = 159, /**< eDMA2 channel 62/63 interrupt */
    ELE_Group1_IRQn    = 160, /**< Sentinel Group 1 reset source if no s500 reference clock is detected. Output
                                 synchronized to 32khz clk. */
    ELE_Group2_IRQn    = 161, /**< Sentinel Group 2 reset source s500 reference clock is not detected or too slow. Output
                               synchronized to ref1_clk. */
    ELE_Group3_IRQn    = 162, /**< Sentinel Group 2 reset source s500 reference clock is not detected or too slow. Output
                               synchronized to ref1_clk. */
    Reserved179_IRQn     = 163, /**< JTAGSW DAP MDM-AP SRC reset source */
    Reserved180_IRQn     = 164, /**< JTAGC SRC reset source */
    Reserved181_IRQn     = 165, /**< CM33 SYSREQRST SRC reset source */
    Reserved182_IRQn     = 166, /**< CM33 LOCKUP SRC reset source */
    CM7_SYSRESETREQ_IRQn = 167, /**< CM7 SYSREQRST SRC reset source */
    CM7_LOCKUP_IRQn      = 168, /**< CM7 LOCKUP SRC reset source */
    SAI2_IRQn            = 169, /**< Serial Audio Interface 2 */
    SAI3_IRQn            = 170, /**< Serial Audio Interface 3 */
    SAI4_IRQn            = 171, /**< Serial Audio Interface 4 */
    SAI5_IRQn            = 172, /**< Serial Audio Interface 5 */
    Reserved189_IRQn     = 173, /**< USB-1 Wake-up Interrupt */
    Reserved190_IRQn     = 174, /**< USB-2 Wake-up Interrupt */
    USB1_IRQn            = 175, /**< USB-1 Interrupt */
    USB2_IRQn            = 176, /**< USB-2 Interrupt */
    LPSPI5_IRQn          = 177, /**< Low Power Serial Peripheral Interface 5 */
    LPSPI6_IRQn          = 178, /**< Low Power Serial Peripheral Interface 6 */
    LPSPI7_IRQn          = 179, /**< Low Power Serial Peripheral Interface 7 */
    LPSPI8_IRQn          = 180, /**< Low Power Serial Peripheral Interface 8 */
    LPI2C5_IRQn          = 181, /**< Low Power Inter-Integrated Circuit module 5 */
    LPI2C6_IRQn          = 182, /**< Low Power Inter-Integrated Circuit module 6 */
    LPI2C7_IRQn          = 183, /**< Low Power Inter-Integrated Circuit module 7 */
    LPI2C8_IRQn          = 184, /**< Low Power Inter-Integrated Circuit module 8 */
    PDM_HWVAD_ERROR_IRQn = 185, /**< PDM interrupt */
    PDM_HWVAD_EVENT_IRQn = 186, /**< PDM interrupt */
    PDM_ERROR_IRQn       = 187, /**< PDM interrupt */
    PDM_EVENT_IRQn       = 188, /**< PDM interrupt */
    Reserved205_IRQn     = 189, /**< AUDIO XCVR interrupt */
    Reserved206_IRQn     = 190, /**< AUDIO XCVR interrupt */
    uSDHC3_IRQn          = 191, /**< ultra Secure Digital Host Controller interrupt 3 */
    Reserved208_IRQn     = 192, /**< OCRAM MECC interrupt */
    Reserved209_IRQn     = 193, /**< OCRAM MECC interrupt */
    Reserved210_IRQn     = 194, /**< CM33 MCM interrupt */
    Reserved211_IRQn     = 195, /**< ANAMIX SFA interrupt */
    Reserved212_IRQn     = 196, /**< GIC700 Fault */
    Reserved213_IRQn     = 197, /**< GIC700 Error */
    Reserved214_IRQn     = 198, /**< GIC700 PMU Counter Overflow */
    Reserved215_IRQn     = 199, /**< ADC interrupt */
    Reserved216_IRQn     = 200, /**< ADC interrupt */
    Reserved217_IRQn     = 201, /**< ADC interrupt */
    Reserved218_IRQn     = 202, /**< s500 glue logic IRQ */
    Reserved219_IRQn     = 203, /**< I3C1 wakeup irq after double sync */
    Reserved220_IRQn     = 204, /**< I3C2 wakeup irq after double sync */
    MU5_A_IRQn           = 205, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
    MU6_A_IRQn           = 206, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
    MU7_B_IRQn           = 207, /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
    MU8_B_IRQn           = 208, /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
    Reserved225_IRQn     = 209, /**< WAKEUPMIX XSPI Responder */
    FCCU_INT0_IRQn       = 210, /**< AONMIX FCCU Interrupt Reaction 0 */
    FCCU_INT1_IRQn       = 211, /**< AONMIX FCCU Interrupt Reaction 1 */
    FCCU_INT2_IRQn       = 212, /**< AONMIX FCCU Interrupt Reaction 2 */
    Reserved229_IRQn     = 213, /**< AONMIX STCU Selftest end Interrupt */
    DISP_IRQSTEER0_IRQn  = 214, /**< DISPLAYMIX IRQSTEER 0 */
    DISP_IRQSTEER1_IRQn  = 215, /**< DISPLAYMIX IRQSTEER 1 */
    DISP_IRQSTEER2_IRQn  = 216, /**< DISPLAYMIX IRQSTEER 2 */
    DISP_IRQSTEER3_IRQn  = 217, /**< DISPLAYMIX IRQSTEER 3 */
    DISP_IRQSTEER4_IRQn  = 218, /**< DISPLAYMIX IRQSTEER 4 */
    DISP_IRQSTEER7_IRQn  = 219, /**< DISPLAYMIX IRQSTEER 7 */
    Reserved236_IRQn     = 220, /**< CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
    Reserved237_IRQn     = 221, /**< CAMERAMIX ISI interrupt Channel 0 */
    Reserved238_IRQn     = 222, /**< ISP Processing Interrupt - Context 0 */
    Reserved239_IRQn     = 223, /**< M7MIX MCM interrupt */
    MU1_A_IRQn           = 224, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
    MU1_B_IRQn           = 225, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
    MU2_A_IRQn           = 226, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
    MU2_B_IRQn           = 227, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
    MU3_A_IRQn           = 228, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
    MU3_B_IRQn           = 229, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
    MU4_A_IRQn           = 230, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
    MU4_B_IRQn           = 231, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
    MU5_B_IRQn           = 232, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
    MU6_B_IRQn           = 233, /**< AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB */
    MU7_A_IRQn           = 234, /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
    MU8_A_IRQn           = 235, /**< WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA */
    Reserved252_IRQn     = 236, /**< MSGINTR Instance 1, Interrupt */
    Reserved253_IRQn     = 237, /**< MSGINTR Instance 2, Interrupts */
    Reserved254_IRQn     = 238, /**< V2X-FH MU APCH1 (APP1) interrupt */
    Reserved255_IRQn     = 239, /**< V2X-FH MU APHSM2 (HSM2) interrupt */
    Reserved256_IRQn     = 240, /**< CAMERAMIX TRDC transfer error interrupt */
    Reserved257_IRQn     = 241, /**< DISPLAYMIX TRDC transfer error interrupt */
    Reserved258_IRQn     = 242, /**< NETCMIX TRDC transfer error interrupt */
    Reserved259_IRQn     = 243, /**< GPUMIX TRDC transfer error interrupt */
    Reserved260_IRQn     = 244, /**< HSIOMIX TRDC transfer error interrupt */
    Reserved261_IRQn     = 245, /**< VPUMIX TRDC transfer error interrupt */
    Reserved262_IRQn     = 246, /**< AONMIX ERM Single bit corrected ECC Error */
    Reserved263_IRQn     = 247, /**< M7MIX ERM Single bit corrected ECC Error */
    Reserved264_IRQn     = 248, /**< WAKEUPMIX ERM Single bit corrected ECC Error */
    Reserved265_IRQn     = 249, /**< NPUMIX ERM Single bit corrected ECC Error */
    Reserved266_IRQn     = 250, /**< WAKEUPMIX ACP EDMA error interrupt */
    Reserved267_IRQn     = 251, /**< OCRAM_C ECC multiple bit or address error */
    Reserved268_IRQn     = 252, /**< CAMERAMIX Cortex-M0+ Cache write-buffer error */
    Reserved269_IRQn     = 253, /**< CAMERAMIX Cortex-M0+ Cache data parity error */
    Reserved270_IRQn     = 254, /**< V2X-FH MU APSHE (SHE) interrupt */
    Reserved271_IRQn     = 255, /**< V2X-FH MU SCU/APDEBUG (DEBUG) interrupt */
    DMA5_0_1_IRQn        = 256, /**< eDMA3 channel 0/1 interrupt */
    DMA5_2_3_IRQn        = 257, /**< eDMA3 channel 2/3 interrupt */
    DMA5_4_5_IRQn        = 258, /**< eDMA3 channel 4/5 interrupt */
    DMA5_6_7_IRQn        = 259, /**< eDMA3 channel 6/7 interrupt */
    DMA5_8_9_IRQn        = 260, /**< eDMA3 channel 8/9 interrupt */
    DMA5_10_11_IRQn      = 261, /**< eDMA3 channel 10/11 interrupt */
    DMA5_12_13_IRQn      = 262, /**< eDMA3 channel 12/13 interrupt */
    DMA5_14_15_IRQn      = 263, /**< eDMA3 channel 14/15 interrupt */
    DMA5_16_17_IRQn      = 264, /**< eDMA3 channel 16/17 interrupt */
    DMA5_18_19_IRQn      = 265, /**< eDMA3 channel 18/19 interrupt */
    DMA5_20_21_IRQn      = 266, /**< eDMA3 channel 20/21 interrupt */
    DMA5_22_23_IRQn      = 267, /**< eDMA3 channel 22/23 interrupt */
    DMA5_24_25_IRQn      = 268, /**< eDMA3 channel 24/25 interrupt */
    DMA5_26_27_IRQn      = 269, /**< eDMA3 channel 26/27 interrupt */
    DMA5_28_29_IRQn      = 270, /**< eDMA3 channel 28/29 interrupt */
    DMA5_30_31_IRQn      = 271, /**< eDMA3 channel 30/31 interrupt */
    DMA5_32_33_IRQn      = 272, /**< eDMA3 channel 32/33 interrupt */
    DMA5_34_35_IRQn      = 273, /**< eDMA3 channel 34/35 interrupt */
    DMA5_36_37_IRQn      = 274, /**< eDMA3 channel 36/37 interrupt */
    DMA5_38_39_IRQn      = 275, /**< eDMA3 channel 38/39 interrupt */
    DMA5_40_41_IRQn      = 276, /**< eDMA3 channel 40/41 interrupt */
    DMA5_42_43_IRQn      = 277, /**< eDMA3 channel 42/43 interrupt */
    DMA5_44_45_IRQn      = 278, /**< eDMA3 channel 44/45 interrupt */
    DMA5_46_47_IRQn      = 279, /**< eDMA3 channel 46/47 interrupt */
    DMA5_48_49_IRQn      = 280, /**< eDMA3 channel 48/49 interrupt */
    DMA5_50_51_IRQn      = 281, /**< eDMA3 channel 50/51 interrupt */
    DMA5_52_53_IRQn      = 282, /**< eDMA3 channel 52/53 interrupt */
    DMA5_54_55_IRQn      = 283, /**< eDMA3 channel 54/55 interrupt */
    DMA5_56_57_IRQn      = 284, /**< eDMA3 channel 56/57 interrupt */
    DMA5_58_59_IRQn      = 285, /**< eDMA3 channel 58/59 interrupt */
    DMA5_60_61_IRQn      = 286, /**< eDMA3 channel 60/61 interrupt */
    DMA5_62_63_IRQn      = 287, /**< eDMA3 channel 62/63 interrupt */
    Reserved304_IRQn     = 288, /**< GPUMIX GPU Interrupt */
    Reserved305_IRQn     = 289, /**< GPUMIX Job Interrupt */
    Reserved306_IRQn     = 290, /**< GPUMIX MMU Interrupt */
    Reserved307_IRQn     = 291, /**< Reserved INTERRUPT */
    Reserved308_IRQn     = 292, /**< Reserved interrupt */
    Reserved309_IRQn     = 293, /**< Reserved interrupt */
    Reserved310_IRQn     = 294, /**< Reserved interrupt */
    Reserved311_IRQn     = 295, /**< Reserved interrupt */
    Reserved312_IRQn     = 296, /**< Reserved interrupt */
    Reserved313_IRQn     = 297, /**< Reserved interrupt */
    Reserved314_IRQn     = 298, /**< Reserved interrupt */
    Reserved315_IRQn     = 299, /**< Reserved interrupt */
    Reserved316_IRQn     = 300, /**< Reserved interrupt */
    Reserved317_IRQn     = 301, /**< Reserved interrupt */
    Reserved318_IRQn     = 302, /**< Reserved interrupt */
    Reserved319_IRQn     = 303, /**< Reserved interrupt */
    Reserved320_IRQn     = 304, /**< NETC iEPRC PCI INT */
    Reserved321_IRQn     = 305, /**< NETC iEPRC PCI INT */
    Reserved322_IRQn     = 306, /**< PCIe Controller 1 INTA */
    Reserved323_IRQn     = 307, /**< PCIe Controller 1 INTB */
    Reserved324_IRQn     = 308, /**< PCIe Controller 1 INTC */
    Reserved325_IRQn     = 309, /**< PCIe Controller 1 INTD */
    Reserved326_IRQn     = 310, /**< PCIe interrupts */
    Reserved327_IRQn     = 311, /**< PCIe Controller EDMA channel interrupt */
    Reserved328_IRQn     = 312, /**< PCIe Controller 1 INTA */
    Reserved329_IRQn     = 313, /**< PCIe Controller 1 INTB */
    Reserved330_IRQn     = 314, /**< PCIe Controller 1 INTC */
    Reserved331_IRQn     = 315, /**< PCIe Controller 1 INTD */
    Reserved332_IRQn     = 316, /**< PCIe miscellaneous interrupts */
    Reserved333_IRQn     = 317, /**< PCIe Controller EDMA channel interrupt */
    Reserved334_IRQn     = 318, /**< Wakeup interrupt from CLKREQ#, WAKEUP#, BEACON_DET */
    Reserved335_IRQn     = 319, /**< NPUMIX Functional interrupt */
    Reserved336_IRQn = 320, /**< DISPLAYMIX Real-time traffic TBU: Fault Handling RAS Interrupt for a contained error */
    Reserved337_IRQn =
        321, /**< DISPLAYMIX Real-time traffic TBU: Error Handling RAS Interrupt for an uncontained error */
    Reserved338_IRQn =
        322, /**< DISPLAYMIX Real-time traffic TBU: Critical Error Interrupt for an uncontainable error */
    Reserved339_IRQn = 323, /**< DISPLAYMIX Real-time traffic TBU: PMU Interrupt */
    Reserved340_IRQn = 324, /**< TCU Event queue, secure interrupt */
    Reserved341_IRQn = 325, /**< TCU Event queue, non-secure interrupt */
    Reserved342_IRQn = 326, /**< TCU SYNC complete, non-secure interrupt */
    Reserved343_IRQn = 327, /**< TCU SYNC complete, secure interrupt */
    Reserved344_IRQn = 328, /**< TCU global non-secure interrupt */
    Reserved345_IRQn = 329, /**< TCU global secure interrupt */
    Reserved346_IRQn = 330, /**< TCU fault handling RAS interrupt for a contained error */
    Reserved347_IRQn = 331, /**< TCU error recovery RAS interrupt for an uncontained error */
    Reserved348_IRQn = 332, /**< TCU critical error interrupt, for an uncontainable uncorrected error */
    Reserved349_IRQn = 333, /**< TCU PMU interrupt */
    Reserved350_IRQn = 334, /**< TCU Page Request Interface */
    GPC_SM_REQ_IRQn = 335, /**< SRC GPC Low Power Handshake Gasket interrupt request for system management */
    Reserved352_IRQn = 336, /**< CAMERAMIX MU Ored of all */
    Reserved353_IRQn = 337, /**< CAMERAMIX MU Ored of all */
    Reserved354_IRQn = 338, /**< CAMERAMIX MU Ored of all */
    Reserved355_IRQn = 339, /**< CAMERAMIX MU Ored of all */
    Reserved356_IRQn = 340, /**< CAMERAMIX MU Ored of all */
    Reserved357_IRQn = 341, /**< CAMERAMIX MU Ored of all */
    Reserved358_IRQn = 342, /**< CAMERAMIX MU Ored of all */
    Reserved359_IRQn = 343, /**< CAMERAMIX MU Ored of all */
    Reserved360_IRQn = 344, /**< CAMERAMIX ISI interrupt Channel 1 */
    Reserved361_IRQn = 345, /**< CAMERAMIX ISI interrupt Channel 2 */
    Reserved362_IRQn = 346, /**< CAMERAMIX ISI interrupt Channel 3 */
    Reserved363_IRQn = 347, /**< CAMERAMIX ISI interrupt Channel 4 */
    Reserved364_IRQn = 348, /**< CAMERAMIX ISI interrupt Channel 5 */
    Reserved365_IRQn = 349, /**< CAMERAMIX ISI interrupt Channel 6 */
    Reserved366_IRQn = 350, /**< CAMERAMIX ISI interrupt Channel 7 */
    Reserved367_IRQn = 351, /**< CAMERAMIX EDMA error interrupt */
    Reserved368_IRQn = 352, /**< CAMERAMIX EDMA channel 0 interrupt */
    Reserved369_IRQn = 353, /**< CAMERAMIX EDMA channel 2 interrupt */
    Reserved370_IRQn = 354, /**< CAMERAMIX EDMA channel 4 interrupt */
    Reserved371_IRQn = 355, /**< CAMERAMIX EDMA channel 6 interrupt */
    Reserved372_IRQn = 356, /**< CAMERAMIX EDMA channel 8 interrupt */
    Reserved373_IRQn = 357, /**< CAMERAMIX EDMA channel 10 interrupt */
    Reserved374_IRQn = 358, /**< CAMERAMIX EDMA channel 12 interrupt */
    Reserved375_IRQn = 359, /**< CAMERAMIX EDMA channel 14 interrupt */
    Reserved376_IRQn = 360, /**< CAMERAMIX EDMA channel 16 interrupt */
    Reserved377_IRQn = 361, /**< CAMERAMIX EDMA channel 18 interrupt */
    Reserved378_IRQn = 362, /**< CAMERAMIX EDMA channel 20 interrupt */
    Reserved379_IRQn = 363, /**< CAMERAMIX EDMA channel 22 interrupt */
    Reserved380_IRQn = 364, /**< CAMERAMIX EDMA channel 24 interrupt */
    Reserved381_IRQn = 365, /**< CAMERAMIX EDMA channel 26 interrupt */
    Reserved382_IRQn = 366, /**< CAMERAMIX EDMA channel 28 interrupt */
    Reserved383_IRQn = 367, /**< CAMERAMIX EDMA channel 30 interrupt */
    Reserved384_IRQn = 368, /**< CAMERAMIX CSI Formatting Unit 1: Buffer overflow */
    Reserved385_IRQn = 369, /**< CAMERAMIX CSI Formatting Unit 1: Interlaced Error */
    Reserved386_IRQn = 370, /**< CAMERAMIX CSI Formatting Unit 1: Pixel Data Type Error */
    Reserved387_IRQn = 371, /**< CAMERAMIX CSI Formatting Unit 2: Buffer overflow */
    Reserved388_IRQn = 372, /**< CAMERAMIX CSI Formatting Unit 2: Interlaced Error */
    Reserved389_IRQn = 373, /**< CAMERAMIX CSI Formatting Unit 2: Pixel Data Type Error */
    Reserved390_IRQn = 374, /**< CAMERAMIX CSI1 */
    Reserved391_IRQn = 375  /**< CAMERAMIX CSI2 */
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

#define __MPU_PRESENT          1 /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS       4 /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig 0 /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT          1 /**< Defines if an FPU is present or not */
#define __DSP_PRESENT          1 /**< Defines if Armv8-M Mainline core supports DSP instructions */

#include "core_cm33.h"            /* Core Peripheral Access Layer */
#include "system_MIMX95_cm33.h" /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup edma_request
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the DMA3 hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum _dma3_request_source
{
    kDma3RequestMuxCAN1                 = 1U,  /**< CAN1 */
    kDma3RequestMuxGPIO1Request0        = 3U,  /**< GPIO1 channel 0 */
    kDma3RequestMuxGPIO1Request1        = 4U,  /**< GPIO1 channel 1 */
    kDma3RequestMuxI3C1ToBusRequest     = 5U,  /**< I3C1 To-bus Request */
    kDma3RequestMuxI3C1FromBusRequest   = 6U,  /**< I3C1 From-bus Request */
    kDma3RequestMuxLPI2C1Tx             = 7U,  /**< LPI2C1 */
    kDma3RequestMuxLPI2C1Rx             = 8U,  /**< LPI2C1 */
    kDma3RequestMuxLPI2C2Tx             = 9U,  /**< LPI2C2 */
    kDma3RequestMuxLPI2C2Rx             = 10U, /**< LPI2C2 */
    kDma3RequestMuxLPSPI1Tx             = 11U, /**< LPSPI1 Transmit */
    kDma3RequestMuxLPSPI1Rx             = 12U, /**< LPSPI1 Receive */
    kDma3RequestMuxLPSPI2Tx             = 13U, /**< LPSPI2 Transmit */
    kDma3RequestMuxLPSPI2Rx             = 14U, /**< LPSPI2 Receive */
    kDma3RequestMuxLPTMR1Request        = 15U, /**< LPTMR1 Request */
    kDma3RequestMuxLPUART1Tx            = 16U, /**< LPUART1 Transmit */
    kDma3RequestMuxLPUART1Rx            = 17U, /**< LPUART1 Receive */
    kDma3RequestMuxLPUART2Tx            = 18U, /**< LPUART2 Transmit */
    kDma3RequestMuxLPUART2Rx            = 19U, /**< LPUART2 Receive */
    kDma3RequestMuxEdgelockRequest      = 20U, /**< Edgelock enclave DMA Request */
    kDma3RequestMuxSai1Tx               = 21U, /**< SAI1 Transmit */
    kDma3RequestMuxSai1Rx               = 22U, /**< SAI1 Receive */
    kDma3RequestMuxTPM1Request0Request2 = 23U, /**< TPM1 request 0 and request 2 */
    kDma3RequestMuxTPM1Request1Request3 = 24U, /**< TPM1 request 1 and request 3 */
    kDma3RequestMuxTPM1OverflowRequest  = 25U, /**< TPM1 Overflow request */
    kDma3RequestMuxTPM2Request0Request2 = 26U, /**< TPM2 request 0 and request 2 */
    kDma3RequestMuxTPM2Request1Request3 = 27U, /**< TPM2 request 1 and request 3 */
    kDma3RequestMuxTPM2OverflowRequest  = 28U, /**< TPM2 Overflow request */
    kDma3RequestMuxPDMRequest           = 29U, /**< PDM */
    kDma3RequestMuxADC1Request          = 30U, /**< ADC1 */
} dma3_request_source_t;

/* @} */

/*!
 * @addtogroup edma_request
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the DMA4 hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum _dma4_request_source
{
    kDma4RequestMuxCAN2                 = 1U,  /**< CAN2 */
    kDma4RequestMuxGPIO2Request0        = 2U,  /**< GPIO2 channel 0 */
    kDma4RequestMuxGPIO2Request1        = 3U,  /**< GPIO2 channel 1 */
    kDma4RequestMuxGPIO3Request0        = 4U,  /**< GPIO3 channel 0 */
    kDma4RequestMuxGPIO3Request1        = 5U,  /**< GPIO3 channel 1 */
    kDma4RequestMuxI3C2ToBusRequest     = 6U,  /**< I3C2 To-bus Request */
    kDma4RequestMuxI3C2FromBusRequest   = 7U,  /**< I3C2 From-bus Request */
    kDma4RequestMuxLPI2C3Tx             = 8U,  /**< LPI2C3 */
    kDma4RequestMuxLPI2C3Rx             = 9U,  /**< LPI2C3 */
    kDma4RequestMuxLPI2C4Tx             = 10U, /**< LPI2C4 */
    kDma4RequestMuxLPI2C4Rx             = 11U, /**< LPI2C4 */
    kDma4RequestMuxLPSPI3Tx             = 12U, /**< LPSPI3 Transmit */
    kDma4RequestMuxLPSPI3Rx             = 13U, /**< LPSPI3 Receive */
    kDma4RequestMuxLPSPI4Tx             = 14U, /**< LPSPI4 Transmit */
    kDma4RequestMuxLPSPI4Rx             = 15U, /**< LPSPI4 Receive */
    kDma4RequestMuxLPTMR2Request        = 16U, /**< LPTMR2 Request */
    kDma4RequestMuxLPUART3Tx            = 17U, /**< LPUART3 Transmit */
    kDma4RequestMuxLPUART3Rx            = 18U, /**< LPUART3 Receive */
    kDma4RequestMuxLPUART4Tx            = 19U, /**< LPUART4 Transmit */
    kDma4RequestMuxLPUART4Rx            = 20U, /**< LPUART4 Receive */
    kDma4RequestMuxLPUART5Tx            = 21U, /**< LPUART5 Transmit */
    kDma4RequestMuxLPUART5Rx            = 22U, /**< LPUART5 Receive */
    kDma4RequestMuxLPUART6Tx            = 23U, /**< LPUART6 Transmit */
    kDma4RequestMuxLPUART6Rx            = 24U, /**< LPUART6 Receive */
    kDma4RequestMuxTPM3Request0Request2 = 25U, /**< TPM3 request 0 and request 2 */
    kDma4RequestMuxTPM3Request1Request3 = 26U, /**< TPM3 request 1 and request 3 */
    kDma4RequestMuxTPM3OverflowRequest  = 27U, /**< TPM3 Overflow request */
    kDma4RequestMuxTPM4Request0Request2 = 28U, /**< TPM4 request 0 and request 2 */
    kDma4RequestMuxTPM4Request1Request3 = 29U, /**< TPM4 request 1 and request 3 */
    kDma4RequestMuxTPM4OverflowRequest  = 30U, /**< TPM4 Overflow request */
    kDma4RequestMuxTPM5Request0Request2 = 31U, /**< TPM5 request 0 and request 2 */
    kDma4RequestMuxTPM5Request1Request3 = 32U, /**< TPM5 request 1 and request 3 */
    kDma4RequestMuxTPM5OverflowRequest  = 33U, /**< TPM5 Overflow request */
    kDma4RequestMuxTPM6Request0Request2 = 34U, /**< TPM6 request 0 and request 2 */
    kDma4RequestMuxTPM6Request1Request3 = 35U, /**< TPM6 request 1 and request 3 */
    kDma4RequestMuxTPM6OverflowRequest  = 36U, /**< TPM6 Overflow request */
    kDma4RequestMuxFlexIO1Request0      = 37U, /**< FlexIO1 Request0 */
    kDma4RequestMuxFlexIO1Request1      = 38U, /**< FlexIO1 Request1 */
    kDma4RequestMuxFlexIO1Request2      = 39U, /**< FlexIO1 Request2 */
    kDma4RequestMuxFlexIO1Request3      = 40U, /**< FlexIO1 Request3 */
    kDma4RequestMuxFlexIO1Request4      = 41U, /**< FlexIO1 Request4 */
    kDma4RequestMuxFlexIO1Request5      = 42U, /**< FlexIO1 Request5 */
    kDma4RequestMuxFlexIO1Request6      = 43U, /**< FlexIO1 Request6 */
    kDma4RequestMuxFlexIO1Request7      = 44U, /**< FlexIO1 Request7 */
    kDma4RequestMuxFlexIO2Request0      = 45U, /**< FlexIO2 Request0 */
    kDma4RequestMuxFlexIO2Request1      = 46U, /**< FlexIO2 Request1 */
    kDma4RequestMuxFlexIO2Request2      = 47U, /**< FlexIO2 Request2 */
    kDma4RequestMuxFlexIO2Request3      = 48U, /**< FlexIO2 Request3 */
    kDma4RequestMuxFlexIO2Request4      = 49U, /**< FlexIO2 Request4 */
    kDma4RequestMuxFlexIO2Request5      = 50U, /**< FlexIO2 Request5 */
    kDma4RequestMuxFlexIO2Request6      = 51U, /**< FlexIO2 Request6 */
    kDma4RequestMuxFlexIO2Request7      = 52U, /**< FlexIO2 Request7 */
    kDma4RequestMuxFlexSPI1Tx           = 53U, /**< FlexSPI1 Transmit */
    kDma4RequestMuxSai2Tx               = 58U, /**< SAI2 Transmit */
    kDma4RequestMuxSai2Rx               = 59U, /**< SAI2 Receive */
    kDma4RequestMuxSai3Tx               = 60U, /**< SAI3 Transmit */
    kDma4RequestMuxSai3Rx               = 61U, /**< SAI3 Receive */
    kDma4RequestMuxGPIO4Request0        = 62U, /**< GPIO4 channel 0 */
    kDma4RequestMuxGPIO4Request1        = 63U, /**< GPIO4 channel 1 */
    kDma4RequestMuxSPDIFRequest         = 65U, /**< SPDIF */
    kDma4RequestMuxSPDIFRequest1        = 66U, /**< SPDIF */
    kDma4RequestMuxENETRequest          = 67U, /**< ENET */
    kDma4RequestMuxENETRequest1         = 68U, /**< ENET */
    kDma4RequestMuxENETRequest2         = 69U, /**< ENET */
    kDma4RequestMuxENETRequest3         = 70U, /**< ENET */
    kDma4RequestMuxLPI2C5Tx             = 71U, /**< LPI2C5 */
    kDma4RequestMuxLPI2C5Rx             = 72U, /**< LPI2C5 */
    kDma4RequestMuxLPI2C6Tx             = 73U, /**< LPI2C6 */
    kDma4RequestMuxLPI2C6Rx             = 74U, /**< LPI2C6 */
    kDma4RequestMuxLPI2C7Tx             = 75U, /**< LPI2C7 */
    kDma4RequestMuxLPI2C7Rx             = 76U, /**< LPI2C7 */
    kDma4RequestMuxLPI2C8Tx             = 77U, /**< LPI2C8 */
    kDma4RequestMuxLPI2C8Rx             = 78U, /**< LPI2C8 */
    kDma4RequestMuxLPSPI5Tx             = 79U, /**< LPSPI5 Transmit */
    kDma4RequestMuxLPSPI5Rx             = 80U, /**< LPSPI5 Receive */
    kDma4RequestMuxLPSPI6Tx             = 81U, /**< LPSPI6 Transmit */
    kDma4RequestMuxLPSPI6Rx             = 82U, /**< LPSPI6 Receive */
    kDma4RequestMuxLPSPI7Tx             = 83U, /**< LPSPI7 Transmit */
    kDma4RequestMuxLPSPI7Rx             = 84U, /**< LPSPI7 Receive */
    kDma4RequestMuxLPSPI8Tx             = 85U, /**< LPSPI8 Transmit */
    kDma4RequestMuxLPSPI8Rx             = 86U, /**< LPSPI8 Receive */
    kDma4RequestMuxLPUART7Tx            = 87U, /**< LPUART7 Transmit */
    kDma4RequestMuxLPUART7Rx            = 88U, /**< LPUART7 Receive */
    kDma4RequestMuxLPUART8Tx            = 89U, /**< LPUART8 Transmit */
    kDma4RequestMuxLPUART8Rx            = 90U, /**< LPUART8 Receive */
    kDma4RequestMuxENET_QOSRequest      = 91U, /**< ENET_QOS */
    kDma4RequestMuxENET_QOSRequest1     = 92U, /**< ENET_QOS */
    kDma4RequestMuxENET_QOSRequest2     = 93U, /**< ENET_QOS */
    kDma4RequestMuxENET_QOSRequest3     = 94U, /**< ENET_QOS */
} dma4_request_source_t;

/* @} */

/*!
 * @}
 */ /* end of group Mapping_Information */

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
#define NXP_VAL2FLD(field, value) (((value) << (field##_SHIFT)) & (field##_MASK))
/**
 * @brief Mask and right-shift a register value to extract a bit field value.
 * @param field Name of the register bit field.
 * @param value Value of the register.
 * @return Masked and shifted bit field value.
 */
#define NXP_FLD2VAL(field, value) (((value) & (field##_MASK)) >> (field##_SHIFT))

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

#endif  /* _MIMX95_COMMON_H_ */
