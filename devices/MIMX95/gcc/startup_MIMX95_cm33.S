/* ------------------------------------------------------------------------- */
/*  @file:    startup_MIMX95_cm33.s                                          */
/*  @purpose: CMSIS Cortex-M33 Core Device Startup File                      */
/*            MIMX95_cm33                                                    */
/*  @version: 1.0                                                            */
/*  @date:    2023-1-10                                                      */
/*  @build:   b230228                                                        */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright 1997-2016 Freescale Semiconductor, Inc.                         */
/* Copyright 2016-2024 NXP                                                   */
/* All rights reserved.                                                      */
/*                                                                           */
/* SPDX-License-Identifier: BSD-3-Clause                                     */
/*****************************************************************************/
/* Version: GCC for ARM Embedded Processors                                  */
/*****************************************************************************/
    .syntax unified
    .arch armv8-m.main

    .section .isr_vector, "a"
    .align 2
    .globl __isr_vector
__isr_vector:
    .long   __StackTop                                      /* Top of Stack */
    .long   Reset_Handler                                   /* Reset Handler */
    .long   NMI_Handler_Shim                                /* NMI Handler*/
    .long   HardFault_Handler_Shim                          /* Hard Fault Handler*/
    .long   MemManage_Handler_Shim                          /* MPU Fault Handler*/
    .long   BusFault_Handler_Shim                           /* Bus Fault Handler*/
    .long   UsageFault_Handler_Shim                         /* Usage Fault Handler*/
    .long   SecureFault_Handler_Shim                        /* Secure Fault Handler*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   SVC_Handler                                     /* SVCall Handler*/
    .long   DebugMon_Handler                                /* Debug Monitor Handler*/
    .long   0                                               /* Reserved*/
    .long   PendSV_Handler                                  /* PendSV Handler*/
    .long   SysTick_Handler                                 /* SysTick Handler*/

                                                            /* External Interrupts*/
    .long   Reserved16_IRQHandler                           /* Reserved interrupt*/
    .long   Reserved17_IRQHandler                           /* DAP interrupt*/
    .long   Reserved18_IRQHandler                           /* CTI trigger outputs from CM7 platform*/
    .long   Reserved19_IRQHandler                           /* CTI trigger outputs from CM33 platform*/
    .long   Reserved20_IRQHandler                           /* CTI trigger outputs from CA55 platform*/
    .long   Reserved21_IRQHandler                           /* Performance Unit Interrupts from CA55 platform*/
    .long   Reserved22_IRQHandler                           /* ECC error from CA55 platform cache*/
    .long   Reserved23_IRQHandler                           /* 1-bit or 2-bit ECC or Parity error from CA55 platform cache*/
    .long   CAN1_IRQHandler                                 /* CAN1 interrupt*/
    .long   CAN1_ERROR_IRQHandler                           /* CAN1 error interrupt*/
    .long   GPIO1_0_IRQHandler                              /* General Purpose Input/Output 1 interrupt 0*/
    .long   Reserved27_IRQHandler                           /* General Purpose Input/Output 1 interrupt 1*/
    .long   I3C1_IRQHandler                                 /* Improved Inter-Integrated Circuit 1 interrupt*/
    .long   LPI2C1_IRQHandler                               /* Low Power Inter-Integrated Circuit module 1*/
    .long   LPI2C2_IRQHandler                               /* Low Power Inter-Integrated Circuit module 2*/
    .long   LPIT1_IRQHandler                                /* Low Power Periodic Interrupt Timer 1*/
    .long   LPSPI1_IRQHandler                               /* Low Power Serial Peripheral Interface 1*/
    .long   LPSPI2_IRQHandler                               /* Low Power Serial Peripheral Interface 2*/
    .long   LPTMR1_IRQHandler                               /* Low Power Timer 1*/
    .long   LPUART1_IRQHandler                              /* Low Power UART 1*/
    .long   LPUART2_IRQHandler                              /* Low Power UART 2*/
    .long   Reserved37_IRQHandler                           /* AONMIX ELE MU0 SideA interrupt*/
    .long   Reserved38_IRQHandler                           /* AONMIX ELE MU1 SideA interrupt*/
    .long   Reserved39_IRQHandler                           /* AONMIX ELE MU2 SideA interrupt*/
    .long   Reserved40_IRQHandler                           /* AONMIX ELE MU3 SideA interrupt*/
    .long   Reserved41_IRQHandler                           /* AONMIX ELE MU4 SideA interrupt*/
    .long   Reserved42_IRQHandler                           /* AONMIX ELE MU5 SideA interrupt*/
    .long   V2X_FH_APCH0_IRQHandler                         /* V2X-FH MU APCH0 (APP0) interrupt*/
    .long   V2X_FH_APHSM1_IRQHandler                        /* V2X-FH MU APHSM1 (HSM1) interrupt*/
    .long   TPM1_IRQHandler                                 /* Timer PWM module 1*/
    .long   TPM2_IRQHandler                                 /* Timer PWM module 2*/
    .long   WDOG1_IRQHandler_Shim                           /* Watchdog 1 Interrupt*/
    .long   WDOG2_IRQHandler_Shim                           /* Watchdog 2 Interrupt*/
    .long   TRDC_MGR_A_IRQHandler                           /* AONMIX TRDC transfer error interrupt*/
    .long   SAI1_IRQHandler                                 /* Serial Audio Interface 1*/
    .long   Reserved51_IRQHandler                           /* AONMIX M33 PS Error*/
    .long   Reserved52_IRQHandler                           /* AONMIX M33 TCM Error interrupt*/
    .long   Reserved53_IRQHandler                           /* M7MIX ECC Multi-bit error*/
    .long   CAN2_IRQHandler                                 /* CAN2 interrupt*/
    .long   CAN2_ERROR_IRQHandler                           /* CAN2 error interrupt*/
    .long   CAN3_IRQHandler                                 /* CAN3 interrupt*/
    .long   CAN3_ERROR_IRQHandler                           /* CAN3 error interrupt*/
    .long   CAN4_IRQHandler                                 /* CAN4 interrupt*/
    .long   CAN4_ERROR_IRQHandler                           /* CAN4 error interrupt*/
    .long   CAN5_IRQHandler                                 /* CAN5 interrupt*/
    .long   CAN5_ERROR_IRQHandler                           /* CAN5 error interrupt*/
    .long   FLEXIO1_IRQHandler                              /* Flexible IO 1 interrupt*/
    .long   FLEXIO2_IRQHandler                              /* Flexible IO 2 interrupt*/
    .long   FlexSPI1_IRQHandler                             /* FlexSPI controller interface interrupt 1*/
    .long   Reserved65_IRQHandler                           /* General Purpose Input/Output 2 interrupt 0*/
    .long   Reserved66_IRQHandler                           /* General Purpose Input/Output 2 interrupt 1*/
    .long   Reserved67_IRQHandler                           /* General Purpose Input/Output 3 interrupt 0*/
    .long   Reserved68_IRQHandler                           /* General Purpose Input/Output 3 interrupt 1*/
    .long   Reserved69_IRQHandler                           /* General Purpose Input/Output 4 interrupt 0*/
    .long   Reserved70_IRQHandler                           /* General Purpose Input/Output 4 interrupt 1*/
    .long   Reserved71_IRQHandler                           /* General Purpose Input/Output 5 interrupt 0*/
    .long   Reserved72_IRQHandler                           /* General Purpose Input/Output 5 interrupt 1*/
    .long   I3C2_IRQHandler                                 /* Improved Inter-Integrated Circuit 2 interrupt*/
    .long   LPI2C3_IRQHandler                               /* Low Power Inter-Integrated Circuit module 3*/
    .long   LPI2C4_IRQHandler                               /* Low Power Inter-Integrated Circuit module 4*/
    .long   LPIT2_IRQHandler                                /* Low Power Periodic Interrupt Timer 2*/
    .long   LPSPI3_IRQHandler                               /* Low Power Serial Peripheral Interface 3*/
    .long   LPSPI4_IRQHandler                               /* Low Power Serial Peripheral Interface 4*/
    .long   LPTMR2_IRQHandler                               /* Low Power Timer 2*/
    .long   LPUART3_IRQHandler                              /* Low Power UART 3*/
    .long   LPUART4_IRQHandler                              /* Low Power UART 4*/
    .long   LPUART5_IRQHandler                              /* Low Power UART 5*/
    .long   LPUART6_IRQHandler                              /* Low Power UART 6*/
    .long   LPUART7_IRQHandler                              /* Low Power UART 7*/
    .long   LPUART8_IRQHandler                              /* Low Power UART 8*/
    .long   Reserved86_IRQHandler                           /* MTR Master error interrupt*/
    .long   BBNSM_IRQHandler                                /* BBNSM Non-Secure interrupt*/
    .long   Reserved88_IRQHandler                           /* System Counter compare interrupt*/
    .long   TPM3_IRQHandler                                 /* Timer PWM module 3*/
    .long   TPM4_IRQHandler                                 /* Timer PWM module 4*/
    .long   TPM5_IRQHandler                                 /* Timer PWM module 5*/
    .long   TPM6_IRQHandler                                 /* Timer PWM module 6*/
    .long   WDOG3_IRQHandler                                /* Watchdog 3 Interrupt*/
    .long   WDOG4_IRQHandler                                /* Watchdog 4 Interrupt*/
    .long   WDOG5_IRQHandler                                /* Watchdog 5 Interrupt*/
    .long   TMPSNS_ANA_1_IRQHandler                         /* ANAMIX TempSensor non-secure interrupt from Threshold 1*/
    .long   TMPSNS_ANA_2_IRQHandler                         /* ANAMIX TempSensor non-secure interrupt from Threshold 2*/
    .long   Reserved98_IRQHandler                           /* ANAMIX TempSensor non-secure data ready interrupt*/
    .long   TMPSNS_CORTEXA_1_IRQHandler                     /* CORTEXAMIX TempSensor non-secure interrupt from Threshold 1*/
    .long   TMPSNS_CORTEXA_2_IRQHandler                     /* CORTEXAMIX TempSensor non-secure interrupt from Threshold 2*/
    .long   Reserved101_IRQHandler                          /* CORTEXAMIX TempSensor non-secure data ready interrupt*/
    .long   uSDHC1_IRQHandler                               /* ultra Secure Digital Host Controller interrupt 1*/
    .long   uSDHC2_IRQHandler                               /* ultra Secure Digital Host Controller interrupt 2*/
    .long   Reserved104_IRQHandler                          /* MEGAMIX TRDC transfer error interrupt*/
    .long   Reserved105_IRQHandler                          /* NIC_WRAPPER TRDC transfer error interrupt*/
    .long   Reserved106_IRQHandler                          /* NOCMIX TRDC transfer error interrupt*/
    .long   Reserved107_IRQHandler                          /* DRAM controller Performance Monitor Interrupt*/
    .long   Reserved108_IRQHandler                          /* DRAM controller Critical Interrupt*/
    .long   Reserved109_IRQHandler                          /* DRAM Phy Critical Interrupt*/
    .long   Reserved110_IRQHandler                          /* Reserved*/
    .long   DMA3_ERROR_IRQHandler                           /* eDMA1 error interrupt*/
    .long   DMA3_0_IRQHandler                               /* eDMA1 channel 0 interrupt*/
    .long   DMA3_1_IRQHandler                               /* eDMA1 channel 1 interrupt*/
    .long   DMA3_2_IRQHandler                               /* eDMA1 channel 2 interrupt*/
    .long   DMA3_3_IRQHandler                               /* eDMA1 channel 3 interrupt*/
    .long   DMA3_4_IRQHandler                               /* eDMA1 channel 4 interrupt*/
    .long   DMA3_5_IRQHandler                               /* eDMA1 channel 5 interrupt*/
    .long   DMA3_6_IRQHandler                               /* eDMA1 channel 6 interrupt*/
    .long   DMA3_7_IRQHandler                               /* eDMA1 channel 7 interrupt*/
    .long   DMA3_8_IRQHandler                               /* eDMA1 channel 8 interrupt*/
    .long   DMA3_9_IRQHandler                               /* eDMA1 channel 9 interrupt*/
    .long   DMA3_10_IRQHandler                              /* eDMA1 channel 10 interrupt*/
    .long   DMA3_11_IRQHandler                              /* eDMA1 channel 11 interrupt*/
    .long   DMA3_12_IRQHandler                              /* eDMA1 channel 12 interrupt*/
    .long   DMA3_13_IRQHandler                              /* eDMA1 channel 13 interrupt*/
    .long   DMA3_14_IRQHandler                              /* eDMA1 channel 14 interrupt*/
    .long   DMA3_15_IRQHandler                              /* eDMA1 channel 15 interrupt*/
    .long   DMA3_16_IRQHandler                              /* eDMA1 channel 16 interrupt*/
    .long   DMA3_17_IRQHandler                              /* eDMA1 channel 17 interrupt*/
    .long   DMA3_18_IRQHandler                              /* eDMA1 channel 18 interrupt*/
    .long   DMA3_19_IRQHandler                              /* eDMA1 channel 19 interrupt*/
    .long   DMA3_20_IRQHandler                              /* eDMA1 channel 20 interrupt*/
    .long   DMA3_21_IRQHandler                              /* eDMA1 channel 21 interrupt*/
    .long   DMA3_22_IRQHandler                              /* eDMA1 channel 22 interrupt*/
    .long   DMA3_23_IRQHandler                              /* eDMA1 channel 23 interrupt*/
    .long   DMA3_24_IRQHandler                              /* eDMA1 channel 24 interrupt*/
    .long   DMA3_25_IRQHandler                              /* eDMA1 channel 25 interrupt*/
    .long   DMA3_26_IRQHandler                              /* eDMA1 channel 26 interrupt*/
    .long   DMA3_27_IRQHandler                              /* eDMA1 channel 27 interrupt*/
    .long   DMA3_28_IRQHandler                              /* eDMA1 channel 28 interrupt*/
    .long   DMA3_29_IRQHandler                              /* eDMA1 channel 29 interrupt*/
    .long   DMA3_30_IRQHandler                              /* eDMA1 channel 30 interrupt*/
    .long   DMA4_ERROR_IRQHandler                           /* eDMA2 error interrupt*/
    .long   DMA4_0_1_IRQHandler                             /* eDMA2 channel 0/1 interrupt*/
    .long   DMA4_2_3_IRQHandler                             /* eDMA2 channel 2/3 interrupt*/
    .long   DMA4_4_5_IRQHandler                             /* eDMA2 channel 4/5 interrupt*/
    .long   DMA4_6_7_IRQHandler                             /* eDMA2 channel 6/7 interrupt*/
    .long   DMA4_8_9_IRQHandler                             /* eDMA2 channel 8/9 interrupt*/
    .long   DMA4_10_11_IRQHandler                           /* eDMA2 channel 10/11 interrupt*/
    .long   DMA4_12_13_IRQHandler                           /* eDMA2 channel 12/13 interrupt*/
    .long   DMA4_14_15_IRQHandler                           /* eDMA2 channel 14/15 interrupt*/
    .long   DMA4_16_17_IRQHandler                           /* eDMA2 channel 16/17 interrupt*/
    .long   DMA4_18_19_IRQHandler                           /* eDMA2 channel 18/19 interrupt*/
    .long   DMA4_20_21_IRQHandler                           /* eDMA2 channel 20/21 interrupt*/
    .long   DMA4_22_23_IRQHandler                           /* eDMA2 channel 22/23 interrupt*/
    .long   DMA4_24_25_IRQHandler                           /* eDMA2 channel 24/25 interrupt*/
    .long   DMA4_26_27_IRQHandler                           /* eDMA2 channel 26/27 interrupt*/
    .long   DMA4_28_29_IRQHandler                           /* eDMA2 channel 28/29 interrupt*/
    .long   DMA4_30_31_IRQHandler                           /* eDMA2 channel 30/31 interrupt*/
    .long   DMA4_32_33_IRQHandler                           /* eDMA2 channel 32/33 interrupt*/
    .long   DMA4_34_35_IRQHandler                           /* eDMA2 channel 34/35 interrupt*/
    .long   DMA4_36_37_IRQHandler                           /* eDMA2 channel 36/37 interrupt*/
    .long   DMA4_38_39_IRQHandler                           /* eDMA2 channel 38/39 interrupt*/
    .long   DMA4_40_41_IRQHandler                           /* eDMA2 channel 40/41 interrupt*/
    .long   DMA4_42_43_IRQHandler                           /* eDMA2 channel 42/43 interrupt*/
    .long   DMA4_44_45_IRQHandler                           /* eDMA2 channel 44/45 interrupt*/
    .long   DMA4_46_47_IRQHandler                           /* eDMA2 channel 46/47 interrupt*/
    .long   DMA4_48_49_IRQHandler                           /* eDMA2 channel 48/49 interrupt*/
    .long   DMA4_50_51_IRQHandler                           /* eDMA2 channel 50/51 interrupt*/
    .long   DMA4_52_53_IRQHandler                           /* eDMA2 channel 52/53 interrupt*/
    .long   DMA4_54_55_IRQHandler                           /* eDMA2 channel 54/55 interrupt*/
    .long   DMA4_56_57_IRQHandler                           /* eDMA2 channel 56/57 interrupt*/
    .long   DMA4_58_59_IRQHandler                           /* eDMA2 channel 58/59 interrupt*/
    .long   DMA4_60_61_IRQHandler                           /* eDMA2 channel 60/61 interrupt*/
    .long   DMA4_62_63_IRQHandler                           /* eDMA2 channel 62/63 interrupt*/
    .long   ELE_Group1_IRQHandler_Shim                      /* ELE Group 1 reset source if no s500 reference clock is detected. Output synchronized to 32khz clk.*/
    .long   ELE_Group2_IRQHandler_Shim                      /* ELE Group 2 reset source s500 reference clock is not detected or too slow. Output synchronized to ref1_clk.*/
    .long   ELE_Group3_IRQHandler_Shim                      /* ELE Group 2 reset source s500 reference clock is not detected or too slow. Output synchronized to ref1_clk.*/
    .long   Reserved179_IRQHandler                          /* JTAGSW DAP MDM-AP SRC reset source*/
    .long   Reserved180_IRQHandler                          /* JTAGC SRC reset source*/
    .long   Reserved181_IRQHandler                          /* CM33 SYSREQRST SRC reset source*/
    .long   Reserved182_IRQHandler                          /* CM33 LOCKUP SRC reset source*/
    .long   CM7_SYSRESETREQ_IRQHandler                      /* CM7 SYSREQRST SRC reset source*/
    .long   CM7_LOCKUP_IRQHandler                           /* CM7 LOCKUP SRC reset source*/
    .long   SAI2_IRQHandler                                 /* Serial Audio Interface 2*/
    .long   SAI3_IRQHandler                                 /* Serial Audio Interface 3*/
    .long   SAI4_IRQHandler                                 /* Serial Audio Interface 4*/
    .long   SAI5_IRQHandler                                 /* Serial Audio Interface 5*/
    .long   Reserved189_IRQHandler                          /* USB-1 Wake-up Interrupt*/
    .long   Reserved190_IRQHandler                          /* USB-2 Wake-up Interrupt*/
    .long   USB1_IRQHandler                                 /* USB-1 Interrupt*/
    .long   USB2_IRQHandler                                 /* USB-2 Interrupt*/
    .long   LPSPI5_IRQHandler                               /* Low Power Serial Peripheral Interface 5*/
    .long   LPSPI6_IRQHandler                               /* Low Power Serial Peripheral Interface 6*/
    .long   LPSPI7_IRQHandler                               /* Low Power Serial Peripheral Interface 7*/
    .long   LPSPI8_IRQHandler                               /* Low Power Serial Peripheral Interface 8*/
    .long   LPI2C5_IRQHandler                               /* Low Power Inter-Integrated Circuit module 5*/
    .long   LPI2C6_IRQHandler                               /* Low Power Inter-Integrated Circuit module 6*/
    .long   LPI2C7_IRQHandler                               /* Low Power Inter-Integrated Circuit module 7*/
    .long   LPI2C8_IRQHandler                               /* Low Power Inter-Integrated Circuit module 8*/
    .long   PDM_HWVAD_ERROR_IRQHandler                      /* PDM interrupt*/
    .long   PDM_HWVAD_EVENT_IRQHandler                      /* PDM interrupt*/
    .long   PDM_ERROR_IRQHandler                            /* PDM interrupt*/
    .long   PDM_EVENT_IRQHandler                            /* PDM interrupt*/
    .long   Reserved205_IRQHandler                          /* AUDIO XCVR interrupt*/
    .long   Reserved206_IRQHandler                          /* AUDIO XCVR interrupt*/
    .long   uSDHC3_IRQHandler                               /* ultra Secure Digital Host Controller interrupt 3*/
    .long   Reserved208_IRQHandler                          /* OCRAM MECC interrupt*/
    .long   Reserved209_IRQHandler                          /* OCRAM MECC interrupt*/
    .long   Reserved210_IRQHandler                          /* CM33 MCM interrupt*/
    .long   Reserved211_IRQHandler                          /* ANAMIX SFA interrupt*/
    .long   Reserved212_IRQHandler                          /* GIC700 Fault*/
    .long   Reserved213_IRQHandler                          /* GIC700 Error*/
    .long   Reserved214_IRQHandler                          /* GIC700 PMU Counter Overflow*/
    .long   Reserved215_IRQHandler                          /* ADC interrupt*/
    .long   Reserved216_IRQHandler                          /* ADC interrupt*/
    .long   Reserved217_IRQHandler                          /* ADC interrupt*/
    .long   Reserved218_IRQHandler                          /* s500 glue logic IRQ*/
    .long   Reserved219_IRQHandler                          /* I3C1 wakeup irq after double sync*/
    .long   Reserved220_IRQHandler                          /* I3C2 wakeup irq after double sync*/
    .long   MU5_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU6_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU7_B_IRQHandler                                /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU8_B_IRQHandler                                /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   Reserved225_IRQHandler                          /* WAKEUPMIX XSPI Responder*/
    .long   FCCU_INT0_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 0*/
    .long   FCCU_INT1_IRQHandler                                /* AONMIX FCCU Interrupt Reaction 1*/
    .long   FCCU_INT2_IRQHandler                                /* AONMIX FCCU Interrupt Reaction 2*/
    .long   Reserved229_IRQHandler                          /* AONMIX STCU Selftest end Interrupt*/
    .long   DISP_IRQSTEER0_IRQHandler                       /* DISPLAYMIX IRQSTEER 0*/
    .long   DISP_IRQSTEER1_IRQHandler                       /* DISPLAYMIX IRQSTEER 1*/
    .long   DISP_IRQSTEER2_IRQHandler                       /* DISPLAYMIX IRQSTEER 2*/
    .long   DISP_IRQSTEER3_IRQHandler                       /* DISPLAYMIX IRQSTEER 3*/
    .long   DISP_IRQSTEER4_IRQHandler                       /* DISPLAYMIX IRQSTEER 4*/
    .long   DISP_IRQSTEER7_IRQHandler                       /* DISPLAYMIX IRQSTEER 7*/
    .long   Reserved236_IRQHandler                          /* CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   Reserved237_IRQHandler                          /* CAMERAMIX ISI interrupt Channel 0*/
    .long   Reserved238_IRQHandler                          /* ISP Processing Interrupt - Context 0*/
    .long   Reserved239_IRQHandler                          /* M7MIX MCM interrupt*/
    .long   MU1_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU1_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU2_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU2_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU3_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU3_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU4_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU4_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU5_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU6_B_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU7_A_IRQHandler                                /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU8_A_IRQHandler                                /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   Reserved252_IRQHandler                          /* MSGINTR Instance 1, Interrupt*/
    .long   Reserved253_IRQHandler                          /* MSGINTR Instance 2, Interrupts*/
    .long   Reserved254_IRQHandler                          /* V2X-FH MU APCH1 (APP1) interrupt*/
    .long   Reserved255_IRQHandler                          /* V2X-FH MU APHSM2 (HSM2) interrupt*/
    .long   Reserved256_IRQHandler                          /* CAMERAMIX TRDC transfer error interrupt*/
    .long   Reserved257_IRQHandler                          /* DISPLAYMIX TRDC transfer error interrupt*/
    .long   Reserved258_IRQHandler                          /* NETCMIX TRDC transfer error interrupt*/
    .long   Reserved259_IRQHandler                          /* GPUMIX TRDC transfer error interrupt*/
    .long   Reserved260_IRQHandler                          /* HSIOMIX TRDC transfer error interrupt*/
    .long   Reserved261_IRQHandler                          /* VPUMIX TRDC transfer error interrupt*/
    .long   Reserved262_IRQHandler                          /* AONMIX ERM Single bit corrected ECC Error*/
    .long   Reserved263_IRQHandler                          /* M7MIX ERM Single bit corrected ECC Error*/
    .long   Reserved264_IRQHandler                          /* WAKEUPMIX ERM Single bit corrected ECC Error*/
    .long   Reserved265_IRQHandler                          /* NPUMIX ERM Single bit corrected ECC Error*/
    .long   Reserved266_IRQHandler                          /* WAKEUPMIX ACP EDMA error interrupt*/
    .long   Reserved267_IRQHandler                          /* OCRAM_C ECC multiple bit or address error*/
    .long   Reserved268_IRQHandler                          /* CAMERAMIX Cortex-M0+ Cache write-buffer error*/
    .long   Reserved269_IRQHandler                          /* CAMERAMIX Cortex-M0+ Cache data parity error*/
    .long   Reserved270_IRQHandler                          /* V2X-FH MU APSHE (SHE) interrupt*/
    .long   Reserved271_IRQHandler                          /* V2X-FH MU SCU/APDEBUG (DEBUG) interrupt*/
    .long   DMA5_0_1_IRQHandler                             /* eDMA3 channel 0/1 interrupt*/
    .long   DMA5_2_3_IRQHandler                             /* eDMA3 channel 2/3 interrupt*/
    .long   DMA5_4_5_IRQHandler                             /* eDMA3 channel 4/5 interrupt*/
    .long   DMA5_6_7_IRQHandler                             /* eDMA3 channel 6/7 interrupt*/
    .long   DMA5_8_9_IRQHandler                             /* eDMA3 channel 8/9 interrupt*/
    .long   DMA5_10_11_IRQHandler                           /* eDMA3 channel 10/11 interrupt*/
    .long   DMA5_12_13_IRQHandler                           /* eDMA3 channel 12/13 interrupt*/
    .long   DMA5_14_15_IRQHandler                           /* eDMA3 channel 14/15 interrupt*/
    .long   DMA5_16_17_IRQHandler                           /* eDMA3 channel 16/17 interrupt*/
    .long   DMA5_18_19_IRQHandler                           /* eDMA3 channel 18/19 interrupt*/
    .long   DMA5_20_21_IRQHandler                           /* eDMA3 channel 20/21 interrupt*/
    .long   DMA5_22_23_IRQHandler                           /* eDMA3 channel 22/23 interrupt*/
    .long   DMA5_24_25_IRQHandler                           /* eDMA3 channel 24/25 interrupt*/
    .long   DMA5_26_27_IRQHandler                           /* eDMA3 channel 26/27 interrupt*/
    .long   DMA5_28_29_IRQHandler                           /* eDMA3 channel 28/29 interrupt*/
    .long   DMA5_30_31_IRQHandler                           /* eDMA3 channel 30/31 interrupt*/
    .long   DMA5_32_33_IRQHandler                           /* eDMA3 channel 32/33 interrupt*/
    .long   DMA5_34_35_IRQHandler                           /* eDMA3 channel 34/35 interrupt*/
    .long   DMA5_36_37_IRQHandler                           /* eDMA3 channel 36/37 interrupt*/
    .long   DMA5_38_39_IRQHandler                           /* eDMA3 channel 38/39 interrupt*/
    .long   DMA5_40_41_IRQHandler                           /* eDMA3 channel 40/41 interrupt*/
    .long   DMA5_42_43_IRQHandler                           /* eDMA3 channel 42/43 interrupt*/
    .long   DMA5_44_45_IRQHandler                           /* eDMA3 channel 44/45 interrupt*/
    .long   DMA5_46_47_IRQHandler                           /* eDMA3 channel 46/47 interrupt*/
    .long   DMA5_48_49_IRQHandler                           /* eDMA3 channel 48/49 interrupt*/
    .long   DMA5_50_51_IRQHandler                           /* eDMA3 channel 50/51 interrupt*/
    .long   DMA5_52_53_IRQHandler                           /* eDMA3 channel 52/53 interrupt*/
    .long   DMA5_54_55_IRQHandler                           /* eDMA3 channel 54/55 interrupt*/
    .long   DMA5_56_57_IRQHandler                           /* eDMA3 channel 56/57 interrupt*/
    .long   DMA5_58_59_IRQHandler                           /* eDMA3 channel 58/59 interrupt*/
    .long   DMA5_60_61_IRQHandler                           /* eDMA3 channel 60/61 interrupt*/
    .long   DMA5_62_63_IRQHandler                           /* eDMA3 channel 62/63 interrupt*/
    .long   Reserved304_IRQHandler                          /* GPUMIX GPU Interrupt*/
    .long   Reserved305_IRQHandler                          /* GPUMIX Job Interrupt*/
    .long   Reserved306_IRQHandler                          /* GPUMIX MMU Interrupt*/
    .long   Reserved307_IRQHandler                          /* Reserved INTERRUPT*/
    .long   Reserved308_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved309_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved310_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved311_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved312_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved313_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved314_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved315_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved316_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved317_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved318_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved319_IRQHandler                          /* Reserved interrupt*/
    .long   Reserved320_IRQHandler                          /* NETC iEPRC PCI INT*/
    .long   Reserved321_IRQHandler                          /* NETC iEPRC PCI INT*/
    .long   Reserved322_IRQHandler                          /* PCIe Controller 1 INTA*/
    .long   Reserved323_IRQHandler                          /* PCIe Controller 1 INTB*/
    .long   Reserved324_IRQHandler                          /* PCIe Controller 1 INTC*/
    .long   Reserved325_IRQHandler                          /* PCIe Controller 1 INTD*/
    .long   Reserved326_IRQHandler                          /* PCIe interrupts*/
    .long   Reserved327_IRQHandler                          /* PCIe Controller EDMA channel interrupt*/
    .long   Reserved328_IRQHandler                          /* PCIe Controller 1 INTA*/
    .long   Reserved329_IRQHandler                          /* PCIe Controller 1 INTB*/
    .long   Reserved330_IRQHandler                          /* PCIe Controller 1 INTC*/
    .long   Reserved331_IRQHandler                          /* PCIe Controller 1 INTD*/
    .long   Reserved332_IRQHandler                          /* PCIe miscellaneous interrupts*/
    .long   Reserved333_IRQHandler                          /* PCIe Controller EDMA channel interrupt*/
    .long   Reserved334_IRQHandler                          /* Wakeup interrupt from CLKREQ#, WAKEUP#, BEACON_DET*/
    .long   Reserved335_IRQHandler                          /* NPUMIX Functional interrupt*/
    .long   Reserved336_IRQHandler                          /* DISPLAYMIX Real-time traffic TBU: Fault Handling RAS Interrupt for a contained error*/
    .long   Reserved337_IRQHandler                          /* DISPLAYMIX Real-time traffic TBU: Error Handling RAS Interrupt for an uncontained error*/
    .long   Reserved338_IRQHandler                          /* DISPLAYMIX Real-time traffic TBU: Critical Error Interrupt for an uncontainable error*/
    .long   Reserved339_IRQHandler                          /* DISPLAYMIX Real-time traffic TBU: PMU Interrupt*/
    .long   Reserved340_IRQHandler                          /* TCU Event queue, secure interrupt*/
    .long   Reserved341_IRQHandler                          /* TCU Event queue, non-secure interrupt*/
    .long   Reserved342_IRQHandler                          /* TCU SYNC complete, non-secure interrupt*/
    .long   Reserved343_IRQHandler                          /* TCU SYNC complete, secure interrupt*/
    .long   Reserved344_IRQHandler                          /* TCU global non-secure interrupt*/
    .long   Reserved345_IRQHandler                          /* TCU global secure interrupt*/
    .long   Reserved346_IRQHandler                          /* TCU fault handling RAS interrupt for a contained error*/
    .long   Reserved347_IRQHandler                          /* TCU error recovery RAS interrupt for an uncontained error*/
    .long   Reserved348_IRQHandler                          /* TCU critical error interrupt, for an uncontainable uncorrected error*/
    .long   Reserved349_IRQHandler                          /* TCU PMU interrupt*/
    .long   Reserved350_IRQHandler                          /* TCU Page Request Interface*/
    .long   GPC_SM_REQ_IRQHandler                           /* SRC GPC Low Power Handshake Gasket interrupt request for system management*/
    .long   Reserved352_IRQHandler                          /* CAMERAMIX MU Ored of all*/
    .long   Reserved353_IRQHandler                          /* CAMERAMIX MU Ored of all*/
    .long   Reserved354_IRQHandler                          /* CAMERAMIX MU Ored of all*/
    .long   Reserved355_IRQHandler                          /* CAMERAMIX MU Ored of all*/
    .long   Reserved356_IRQHandler                          /* CAMERAMIX MU Ored of all*/
    .long   Reserved357_IRQHandler                          /* CAMERAMIX MU Ored of all*/
    .long   Reserved358_IRQHandler                          /* CAMERAMIX MU Ored of all*/
    .long   Reserved359_IRQHandler                          /* CAMERAMIX MU Ored of all*/
    .long   Reserved360_IRQHandler                          /* CAMERAMIX ISI interrupt Channel 1*/
    .long   Reserved361_IRQHandler                          /* CAMERAMIX ISI interrupt Channel 2*/
    .long   Reserved362_IRQHandler                          /* CAMERAMIX ISI interrupt Channel 3*/
    .long   Reserved363_IRQHandler                          /* CAMERAMIX ISI interrupt Channel 4*/
    .long   Reserved364_IRQHandler                          /* CAMERAMIX ISI interrupt Channel 5*/
    .long   Reserved365_IRQHandler                          /* CAMERAMIX ISI interrupt Channel 6*/
    .long   Reserved366_IRQHandler                          /* CAMERAMIX ISI interrupt Channel 7*/
    .long   Reserved367_IRQHandler                          /* CAMERAMIX EDMA error interrupt*/
    .long   Reserved368_IRQHandler                          /* CAMERAMIX EDMA channel 0 interrupt*/
    .long   Reserved369_IRQHandler                          /* CAMERAMIX EDMA channel 2 interrupt*/
    .long   Reserved370_IRQHandler                          /* CAMERAMIX EDMA channel 4 interrupt*/
    .long   Reserved371_IRQHandler                          /* CAMERAMIX EDMA channel 6 interrupt*/
    .long   Reserved372_IRQHandler                          /* CAMERAMIX EDMA channel 8 interrupt*/
    .long   Reserved373_IRQHandler                          /* CAMERAMIX EDMA channel 10 interrupt*/
    .long   Reserved374_IRQHandler                          /* CAMERAMIX EDMA channel 12 interrupt*/
    .long   Reserved375_IRQHandler                          /* CAMERAMIX EDMA channel 14 interrupt*/
    .long   Reserved376_IRQHandler                          /* CAMERAMIX EDMA channel 16 interrupt*/
    .long   Reserved377_IRQHandler                          /* CAMERAMIX EDMA channel 18 interrupt*/
    .long   Reserved378_IRQHandler                          /* CAMERAMIX EDMA channel 20 interrupt*/
    .long   Reserved379_IRQHandler                          /* CAMERAMIX EDMA channel 22 interrupt*/
    .long   Reserved380_IRQHandler                          /* CAMERAMIX EDMA channel 24 interrupt*/
    .long   Reserved381_IRQHandler                          /* CAMERAMIX EDMA channel 26 interrupt*/
    .long   Reserved382_IRQHandler                          /* CAMERAMIX EDMA channel 28 interrupt*/
    .long   Reserved383_IRQHandler                          /* CAMERAMIX EDMA channel 30 interrupt*/
    .long   Reserved384_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 1: Buffer overflow*/
    .long   Reserved385_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 1: Interlaced Error*/
    .long   Reserved386_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 1: Pixel Data Type Error*/
    .long   Reserved387_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 2: Buffer overflow*/
    .long   Reserved388_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 2: Interlaced Error*/
    .long   Reserved389_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 2: Pixel Data Type Error*/
    .long   Reserved390_IRQHandler                          /* CAMERAMIX CSI1*/
    .long   Reserved391_IRQHandler                          /* CAMERAMIX CSI2*/

    .size   __isr_vector, . - __isr_vector

    .text
    .thumb

/* Reset Handler */

    .thumb_func
    .align 2
    .globl   Reset_Handler
    .weak    Reset_Handler
    .type    Reset_Handler, %function
Reset_Handler:
    cpsid   i               /* Mask interrupts */
    .equ    VTOR, 0xE000ED08
    ldr     r0, =VTOR
    ldr     r1, =__isr_vector
    str     r1, [r0]
    ldr     r2, [r1]
    msr     msp, r2

    ldr r1, =__StackLimit
    ldr r2, =__StackTop
    movs    r0, 0
.stack_init:
    cmp     r1, r2
    itt    lt
    strlt   r0, [r1], #4
    blt    .stack_init

    ldr r1, =__HeapBase
    ldr r2, =__HeapLimit
    movs    r0, 0
.heap_init:
    cmp     r1, r2
    itt    lt
    strlt   r0, [r1], #4
    blt    .heap_init

#ifndef __NO_SYSTEM_INIT
    ldr   r0,=SystemInit
    blx   r0
#endif
/*     Loop to copy data from read only memory to RAM. The ranges
 *      of copy from/to are specified by following symbols evaluated in
 *      linker script.
 *      __etext: End of code section, i.e., begin of data sections to copy from.
 *      __data_start__/__data_end__: RAM address range that data should be
 *      copied to. Both must be aligned to 4 bytes boundary.  */

    ldr    r1, =__etext
    ldr    r2, =__data_start__
    ldr    r3, =__data_end__

#ifdef __PERFORMANCE_IMPLEMENTATION
/* Here are two copies of loop implementations. First one favors performance
 * and the second one favors code size. Default uses the second one.
 * Define macro "__PERFORMANCE_IMPLEMENTATION" in project to use the first one */
    subs    r3, r2
    ble    .LC1
.LC0:
    subs    r3, #4
    ldr    r0, [r1, r3]
    str    r0, [r2, r3]
    bgt    .LC0
.LC1:
#else  /* code size implementation */
.LC0:
    cmp     r2, r3
    ittt    lt
    ldrlt   r0, [r1], #4
    strlt   r0, [r2], #4
    blt    .LC0
#endif

#ifdef __STARTUP_CLEAR_BSS
/*     This part of work usually is done in C library startup code. Otherwise,
 *     define this macro to enable it in this startup.
 *
 *     Loop to zero out BSS section, which uses following symbols
 *     in linker script:
 *      __bss_start__: start of BSS section. Must align to 4
 *      __bss_end__: end of BSS section. Must align to 4
 */
    ldr r1, =__bss_start__
    ldr r2, =__bss_end__

    movs    r0, 0
.LC2:
    cmp     r1, r2
    itt    lt
    strlt   r0, [r1], #4
    blt    .LC2
#endif /* __STARTUP_CLEAR_BSS */

    cpsie   i               /* Unmask interrupts */
#ifndef __START
#define __START _start
#endif
#ifndef __ATOLLIC__
    ldr   r0,=__START
    blx   r0
#else
#if defined(INC_LIBC)
    ldr   r0,=__libc_init_array
    blx   r0
#endif
    ldr   r0,=main
    bx    r0
#endif
    .pool
    .size Reset_Handler, . - Reset_Handler

    .align  1
    .thumb_func
    .weak DefaultISR
    .type DefaultISR, %function
DefaultISR:
    b DefaultISR
    .size DefaultISR, . - DefaultISR

    .thumb_func
    .align 2
    .globl   NMI_Handler_Shim
    .weak    NMI_Handler_Shim
    .type    NMI_Handler_Shim, %function
NMI_Handler_Shim:
    tst lr, #0x4                        /* test EXC_RETURN number in LR bit 2 */
    ite eq                              /* if zero (equal) then */
    mrseq r0, MSP                       /* Main Stack was used, put MSP in R1 */
    mrsne r0, PSP                       /* else, Process Stack was used, put PSP in R1 */
    b   NMI_Handler

    .thumb_func
    .align 2
    .globl   HardFault_Handler_Shim
    .weak    HardFault_Handler_Shim
    .type    HardFault_Handler_Shim, %function
HardFault_Handler_Shim:
    tst lr, #0x4                        /* test EXC_RETURN number in LR bit 2 */
    ite eq                              /* if zero (equal) then */
    mrseq r0, MSP                       /* Main Stack was used, put MSP in R1 */
    mrsne r0, PSP                       /* else, Process Stack was used, put PSP in R1 */
    b   HardFault_Handler

    .thumb_func
    .align 2
    .globl   MemManage_Handler_Shim
    .weak    MemManage_Handler_Shim
    .type    MemManage_Handler_Shim, %function
MemManage_Handler_Shim:
    tst lr, #0x4                        /* test EXC_RETURN number in LR bit 2 */
    ite eq                              /* if zero (equal) then */
    mrseq r0, MSP                       /* Main Stack was used, put MSP in R1 */
    mrsne r0, PSP                       /* else, Process Stack was used, put PSP in R1 */
    b   MemManage_Handler

    .thumb_func
    .align 2
    .globl   BusFault_Handler_Shim
    .weak    BusFault_Handler_Shim
    .type    BusFault_Handler_Shim, %function
BusFault_Handler_Shim:
    tst lr, #0x4                        /* test EXC_RETURN number in LR bit 2 */
    ite eq                              /* if zero (equal) then */
    mrseq r0, MSP                       /* Main Stack was used, put MSP in R1 */
    mrsne r0, PSP                       /* else, Process Stack was used, put PSP in R1 */
    b   BusFault_Handler

    .thumb_func
    .align 2
    .globl   UsageFault_Handler_Shim
    .weak    UsageFault_Handler_Shim
    .type    UsageFault_Handler_Shim, %function
UsageFault_Handler_Shim:
    tst lr, #0x4                        /* test EXC_RETURN number in LR bit 2 */
    ite eq                              /* if zero (equal) then */
    mrseq r0, MSP                       /* Main Stack was used, put MSP in R1 */
    mrsne r0, PSP                       /* else, Process Stack was used, put PSP in R1 */
    b   UsageFault_Handler

    .thumb_func
    .align 2
    .globl   SecureFault_Handler_Shim
    .weak    SecureFault_Handler_Shim
    .type    SecureFault_Handler_Shim, %function
SecureFault_Handler_Shim:
    tst lr, #0x4                        /* test EXC_RETURN number in LR bit 2 */
    ite eq                              /* if zero (equal) then */
    mrseq r0, MSP                       /* Main Stack was used, put MSP in R1 */
    mrsne r0, PSP                       /* else, Process Stack was used, put PSP in R1 */
    b   SecureFault_Handler

    .align 2
    .thumb_func
    .globl   WDOG1_IRQHandler_Shim
    .weak    WDOG1_IRQHandler_Shim
    .type    WDOG1_IRQHandler_Shim, %function
WDOG1_IRQHandler_Shim:
    tst lr, #0x4                        /* test EXC_RETURN number in LR bit 2 */
    ite eq                              /* if zero (equal) then */
    mrseq r0, MSP                       /* Main Stack was used, put MSP in R1 */
    mrsne r0, PSP                       /* else, Process Stack was used, put PSP in R1 */
    b   WDOG1_IRQHandler

    .align 2
    .thumb_func
    .globl   WDOG2_IRQHandler_Shim
    .weak    WDOG2_IRQHandler_Shim
    .type    WDOG2_IRQHandler_Shim, %function
WDOG2_IRQHandler_Shim:
    tst lr, #0x4                        /* test EXC_RETURN number in LR bit 2 */
    ite eq                              /* if zero (equal) then */
    mrseq r0, MSP                       /* Main Stack was used, put MSP in R1 */
    mrsne r0, PSP                       /* else, Process Stack was used, put PSP in R1 */
    b   WDOG2_IRQHandler

    .align 2
    .thumb_func
    .globl   ELE_Group1_IRQHandler_Shim
    .weak    ELE_Group1_IRQHandler_Shim
    .type    ELE_Group1_IRQHandler_Shim, %function
ELE_Group1_IRQHandler_Shim:
    tst lr, #0x4                        /* test EXC_RETURN number in LR bit 2 */
    ite eq                              /* if zero (equal) then */
    mrseq r0, MSP                       /* Main Stack was used, put MSP in R1 */
    mrsne r0, PSP                       /* else, Process Stack was used, put PSP in R1 */
    b   ELE_Group1_IRQHandler

    .align 2
    .thumb_func
    .globl   ELE_Group2_IRQHandler_Shim
    .weak    ELE_Group2_IRQHandler_Shim
    .type    ELE_Group2_IRQHandler_Shim, %function
ELE_Group2_IRQHandler_Shim:
    tst lr, #0x4                        /* test EXC_RETURN number in LR bit 2 */
    ite eq                              /* if zero (equal) then */
    mrseq r0, MSP                       /* Main Stack was used, put MSP in R1 */
    mrsne r0, PSP                       /* else, Process Stack was used, put PSP in R1 */
    b   ELE_Group2_IRQHandler

    .align 2
    .thumb_func
    .globl   ELE_Group3_IRQHandler_Shim
    .weak    ELE_Group3_IRQHandler_Shim
    .type    ELE_Group3_IRQHandler_Shim, %function
ELE_Group3_IRQHandler_Shim:
    tst lr, #0x4                        /* test EXC_RETURN number in LR bit 2 */
    ite eq                              /* if zero (equal) then */
    mrseq r0, MSP                       /* Main Stack was used, put MSP in R1 */
    mrsne r0, PSP                       /* else, Process Stack was used, put PSP in R1 */
    b   ELE_Group3_IRQHandler

    .align 1
    .thumb_func
    .weak SVC_Handler
    .type SVC_Handler, %function
SVC_Handler:
    ldr   r0,=SVC_Handler
    bx    r0
    .size SVC_Handler, . - SVC_Handler

    .align 1
    .thumb_func
    .weak PendSV_Handler
    .type PendSV_Handler, %function
PendSV_Handler:
    ldr   r0,=PendSV_Handler
    bx    r0
    .size PendSV_Handler, . - PendSV_Handler

    .align 1
    .thumb_func
    .weak SysTick_Handler
    .type SysTick_Handler, %function
SysTick_Handler:
    ldr   r0,=SysTick_Handler
    bx    r0
    .size SysTick_Handler, . - SysTick_Handler

/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
    .macro def_irq_handler  handler_name
    .weak \handler_name
    .set  \handler_name, DefaultISR
    .endm
/* Exception Handlers */
    def_irq_handler    NMI_Handler
    def_irq_handler    HardFault_Handler
    def_irq_handler    MemManage_Handler
    def_irq_handler    BusFault_Handler
    def_irq_handler    UsageFault_Handler
    def_irq_handler    SecureFault_Handler
    def_irq_handler    DebugMon_Handler
    def_irq_handler    Reserved16_IRQHandler
    def_irq_handler    Reserved17_IRQHandler
    def_irq_handler    Reserved18_IRQHandler
    def_irq_handler    Reserved19_IRQHandler
    def_irq_handler    Reserved20_IRQHandler
    def_irq_handler    Reserved21_IRQHandler
    def_irq_handler    Reserved22_IRQHandler
    def_irq_handler    Reserved23_IRQHandler
    def_irq_handler    CAN1_IRQHandler
    def_irq_handler    CAN1_ERROR_IRQHandler
    def_irq_handler    GPIO1_0_IRQHandler
    def_irq_handler    Reserved27_IRQHandler
    def_irq_handler    I3C1_IRQHandler
    def_irq_handler    LPI2C1_IRQHandler
    def_irq_handler    LPI2C2_IRQHandler
    def_irq_handler    LPIT1_IRQHandler
    def_irq_handler    LPSPI1_IRQHandler
    def_irq_handler    LPSPI2_IRQHandler
    def_irq_handler    LPTMR1_IRQHandler
    def_irq_handler    LPUART1_IRQHandler
    def_irq_handler    LPUART2_IRQHandler
    def_irq_handler    Reserved37_IRQHandler
    def_irq_handler    Reserved38_IRQHandler
    def_irq_handler    Reserved39_IRQHandler
    def_irq_handler    Reserved40_IRQHandler
    def_irq_handler    Reserved41_IRQHandler
    def_irq_handler    Reserved42_IRQHandler
    def_irq_handler    V2X_FH_APCH0_IRQHandler
    def_irq_handler    V2X_FH_APHSM1_IRQHandler
    def_irq_handler    TPM1_IRQHandler
    def_irq_handler    TPM2_IRQHandler
    def_irq_handler    WDOG1_IRQHandler
    def_irq_handler    WDOG2_IRQHandler
    def_irq_handler    TRDC_MGR_A_IRQHandler
    def_irq_handler    SAI1_IRQHandler
    def_irq_handler    Reserved51_IRQHandler
    def_irq_handler    Reserved52_IRQHandler
    def_irq_handler    Reserved53_IRQHandler
    def_irq_handler    CAN2_IRQHandler
    def_irq_handler    CAN2_ERROR_IRQHandler
    def_irq_handler    CAN3_IRQHandler
    def_irq_handler    CAN3_ERROR_IRQHandler
    def_irq_handler    CAN4_IRQHandler
    def_irq_handler    CAN4_ERROR_IRQHandler
    def_irq_handler    CAN5_IRQHandler
    def_irq_handler    CAN5_ERROR_IRQHandler
    def_irq_handler    FLEXIO1_IRQHandler
    def_irq_handler    FLEXIO2_IRQHandler
    def_irq_handler    FlexSPI1_IRQHandler
    def_irq_handler    Reserved65_IRQHandler
    def_irq_handler    Reserved66_IRQHandler
    def_irq_handler    Reserved67_IRQHandler
    def_irq_handler    Reserved68_IRQHandler
    def_irq_handler    Reserved69_IRQHandler
    def_irq_handler    Reserved70_IRQHandler
    def_irq_handler    Reserved71_IRQHandler
    def_irq_handler    Reserved72_IRQHandler
    def_irq_handler    I3C2_IRQHandler
    def_irq_handler    LPI2C3_IRQHandler
    def_irq_handler    LPI2C4_IRQHandler
    def_irq_handler    LPIT2_IRQHandler
    def_irq_handler    LPSPI3_IRQHandler
    def_irq_handler    LPSPI4_IRQHandler
    def_irq_handler    LPTMR2_IRQHandler
    def_irq_handler    LPUART3_IRQHandler
    def_irq_handler    LPUART4_IRQHandler
    def_irq_handler    LPUART5_IRQHandler
    def_irq_handler    LPUART6_IRQHandler
    def_irq_handler    LPUART7_IRQHandler
    def_irq_handler    LPUART8_IRQHandler
    def_irq_handler    Reserved86_IRQHandler
    def_irq_handler    BBNSM_IRQHandler
    def_irq_handler    Reserved88_IRQHandler
    def_irq_handler    TPM3_IRQHandler
    def_irq_handler    TPM4_IRQHandler
    def_irq_handler    TPM5_IRQHandler
    def_irq_handler    TPM6_IRQHandler
    def_irq_handler    WDOG3_IRQHandler
    def_irq_handler    WDOG4_IRQHandler
    def_irq_handler    WDOG5_IRQHandler
    def_irq_handler    TMPSNS_ANA_1_IRQHandler
    def_irq_handler    TMPSNS_ANA_2_IRQHandler
    def_irq_handler    Reserved98_IRQHandler
    def_irq_handler    TMPSNS_CORTEXA_1_IRQHandler
    def_irq_handler    TMPSNS_CORTEXA_2_IRQHandler
    def_irq_handler    Reserved101_IRQHandler
    def_irq_handler    uSDHC1_IRQHandler
    def_irq_handler    uSDHC2_IRQHandler
    def_irq_handler    Reserved104_IRQHandler
    def_irq_handler    Reserved105_IRQHandler
    def_irq_handler    Reserved106_IRQHandler
    def_irq_handler    Reserved107_IRQHandler
    def_irq_handler    Reserved108_IRQHandler
    def_irq_handler    Reserved109_IRQHandler
    def_irq_handler    Reserved110_IRQHandler
    def_irq_handler    DMA3_ERROR_IRQHandler
    def_irq_handler    DMA3_0_IRQHandler
    def_irq_handler    DMA3_1_IRQHandler
    def_irq_handler    DMA3_2_IRQHandler
    def_irq_handler    DMA3_3_IRQHandler
    def_irq_handler    DMA3_4_IRQHandler
    def_irq_handler    DMA3_5_IRQHandler
    def_irq_handler    DMA3_6_IRQHandler
    def_irq_handler    DMA3_7_IRQHandler
    def_irq_handler    DMA3_8_IRQHandler
    def_irq_handler    DMA3_9_IRQHandler
    def_irq_handler    DMA3_10_IRQHandler
    def_irq_handler    DMA3_11_IRQHandler
    def_irq_handler    DMA3_12_IRQHandler
    def_irq_handler    DMA3_13_IRQHandler
    def_irq_handler    DMA3_14_IRQHandler
    def_irq_handler    DMA3_15_IRQHandler
    def_irq_handler    DMA3_16_IRQHandler
    def_irq_handler    DMA3_17_IRQHandler
    def_irq_handler    DMA3_18_IRQHandler
    def_irq_handler    DMA3_19_IRQHandler
    def_irq_handler    DMA3_20_IRQHandler
    def_irq_handler    DMA3_21_IRQHandler
    def_irq_handler    DMA3_22_IRQHandler
    def_irq_handler    DMA3_23_IRQHandler
    def_irq_handler    DMA3_24_IRQHandler
    def_irq_handler    DMA3_25_IRQHandler
    def_irq_handler    DMA3_26_IRQHandler
    def_irq_handler    DMA3_27_IRQHandler
    def_irq_handler    DMA3_28_IRQHandler
    def_irq_handler    DMA3_29_IRQHandler
    def_irq_handler    DMA3_30_IRQHandler
    def_irq_handler    DMA4_ERROR_IRQHandler
    def_irq_handler    DMA4_0_1_IRQHandler
    def_irq_handler    DMA4_2_3_IRQHandler
    def_irq_handler    DMA4_4_5_IRQHandler
    def_irq_handler    DMA4_6_7_IRQHandler
    def_irq_handler    DMA4_8_9_IRQHandler
    def_irq_handler    DMA4_10_11_IRQHandler
    def_irq_handler    DMA4_12_13_IRQHandler
    def_irq_handler    DMA4_14_15_IRQHandler
    def_irq_handler    DMA4_16_17_IRQHandler
    def_irq_handler    DMA4_18_19_IRQHandler
    def_irq_handler    DMA4_20_21_IRQHandler
    def_irq_handler    DMA4_22_23_IRQHandler
    def_irq_handler    DMA4_24_25_IRQHandler
    def_irq_handler    DMA4_26_27_IRQHandler
    def_irq_handler    DMA4_28_29_IRQHandler
    def_irq_handler    DMA4_30_31_IRQHandler
    def_irq_handler    DMA4_32_33_IRQHandler
    def_irq_handler    DMA4_34_35_IRQHandler
    def_irq_handler    DMA4_36_37_IRQHandler
    def_irq_handler    DMA4_38_39_IRQHandler
    def_irq_handler    DMA4_40_41_IRQHandler
    def_irq_handler    DMA4_42_43_IRQHandler
    def_irq_handler    DMA4_44_45_IRQHandler
    def_irq_handler    DMA4_46_47_IRQHandler
    def_irq_handler    DMA4_48_49_IRQHandler
    def_irq_handler    DMA4_50_51_IRQHandler
    def_irq_handler    DMA4_52_53_IRQHandler
    def_irq_handler    DMA4_54_55_IRQHandler
    def_irq_handler    DMA4_56_57_IRQHandler
    def_irq_handler    DMA4_58_59_IRQHandler
    def_irq_handler    DMA4_60_61_IRQHandler
    def_irq_handler    DMA4_62_63_IRQHandler
    def_irq_handler    ELE_Group1_IRQHandler
    def_irq_handler    ELE_Group2_IRQHandler
    def_irq_handler    ELE_Group3_IRQHandler
    def_irq_handler    Reserved179_IRQHandler
    def_irq_handler    Reserved180_IRQHandler
    def_irq_handler    Reserved181_IRQHandler
    def_irq_handler    Reserved182_IRQHandler
    def_irq_handler    CM7_SYSRESETREQ_IRQHandler
    def_irq_handler    CM7_LOCKUP_IRQHandler
    def_irq_handler    SAI2_IRQHandler
    def_irq_handler    SAI3_IRQHandler
    def_irq_handler    SAI4_IRQHandler
    def_irq_handler    SAI5_IRQHandler
    def_irq_handler    Reserved189_IRQHandler
    def_irq_handler    Reserved190_IRQHandler
    def_irq_handler    USB1_IRQHandler
    def_irq_handler    USB2_IRQHandler
    def_irq_handler    LPSPI5_IRQHandler
    def_irq_handler    LPSPI6_IRQHandler
    def_irq_handler    LPSPI7_IRQHandler
    def_irq_handler    LPSPI8_IRQHandler
    def_irq_handler    LPI2C5_IRQHandler
    def_irq_handler    LPI2C6_IRQHandler
    def_irq_handler    LPI2C7_IRQHandler
    def_irq_handler    LPI2C8_IRQHandler
    def_irq_handler    PDM_HWVAD_ERROR_IRQHandler
    def_irq_handler    PDM_HWVAD_EVENT_IRQHandler
    def_irq_handler    PDM_ERROR_IRQHandler
    def_irq_handler    PDM_EVENT_IRQHandler
    def_irq_handler    Reserved205_IRQHandler
    def_irq_handler    Reserved206_IRQHandler
    def_irq_handler    uSDHC3_IRQHandler
    def_irq_handler    Reserved208_IRQHandler
    def_irq_handler    Reserved209_IRQHandler
    def_irq_handler    Reserved210_IRQHandler
    def_irq_handler    Reserved211_IRQHandler
    def_irq_handler    Reserved212_IRQHandler
    def_irq_handler    Reserved213_IRQHandler
    def_irq_handler    Reserved214_IRQHandler
    def_irq_handler    Reserved215_IRQHandler
    def_irq_handler    Reserved216_IRQHandler
    def_irq_handler    Reserved217_IRQHandler
    def_irq_handler    Reserved218_IRQHandler
    def_irq_handler    Reserved219_IRQHandler
    def_irq_handler    Reserved220_IRQHandler
    def_irq_handler    MU5_A_IRQHandler
    def_irq_handler    MU6_A_IRQHandler
    def_irq_handler    MU7_B_IRQHandler
    def_irq_handler    MU8_B_IRQHandler
    def_irq_handler    Reserved225_IRQHandler
    def_irq_handler    FCCU_INT0_IRQHandler
    def_irq_handler    FCCU_INT1_IRQHandler
    def_irq_handler    FCCU_INT2_IRQHandler
    def_irq_handler    Reserved229_IRQHandler
    def_irq_handler    DISP_IRQSTEER0_IRQHandler
    def_irq_handler    DISP_IRQSTEER1_IRQHandler
    def_irq_handler    DISP_IRQSTEER2_IRQHandler
    def_irq_handler    DISP_IRQSTEER3_IRQHandler
    def_irq_handler    DISP_IRQSTEER4_IRQHandler
    def_irq_handler    DISP_IRQSTEER7_IRQHandler
    def_irq_handler    Reserved236_IRQHandler
    def_irq_handler    Reserved237_IRQHandler
    def_irq_handler    Reserved238_IRQHandler
    def_irq_handler    Reserved239_IRQHandler
    def_irq_handler    MU1_A_IRQHandler
    def_irq_handler    MU1_B_IRQHandler
    def_irq_handler    MU2_A_IRQHandler
    def_irq_handler    MU2_B_IRQHandler
    def_irq_handler    MU3_A_IRQHandler
    def_irq_handler    MU3_B_IRQHandler
    def_irq_handler    MU4_A_IRQHandler
    def_irq_handler    MU4_B_IRQHandler
    def_irq_handler    MU5_B_IRQHandler
    def_irq_handler    MU6_B_IRQHandler
    def_irq_handler    MU7_A_IRQHandler
    def_irq_handler    MU8_A_IRQHandler
    def_irq_handler    Reserved252_IRQHandler
    def_irq_handler    Reserved253_IRQHandler
    def_irq_handler    Reserved254_IRQHandler
    def_irq_handler    Reserved255_IRQHandler
    def_irq_handler    Reserved256_IRQHandler
    def_irq_handler    Reserved257_IRQHandler
    def_irq_handler    Reserved258_IRQHandler
    def_irq_handler    Reserved259_IRQHandler
    def_irq_handler    Reserved260_IRQHandler
    def_irq_handler    Reserved261_IRQHandler
    def_irq_handler    Reserved262_IRQHandler
    def_irq_handler    Reserved263_IRQHandler
    def_irq_handler    Reserved264_IRQHandler
    def_irq_handler    Reserved265_IRQHandler
    def_irq_handler    Reserved266_IRQHandler
    def_irq_handler    Reserved267_IRQHandler
    def_irq_handler    Reserved268_IRQHandler
    def_irq_handler    Reserved269_IRQHandler
    def_irq_handler    Reserved270_IRQHandler
    def_irq_handler    Reserved271_IRQHandler
    def_irq_handler    DMA5_0_1_IRQHandler
    def_irq_handler    DMA5_2_3_IRQHandler
    def_irq_handler    DMA5_4_5_IRQHandler
    def_irq_handler    DMA5_6_7_IRQHandler
    def_irq_handler    DMA5_8_9_IRQHandler
    def_irq_handler    DMA5_10_11_IRQHandler
    def_irq_handler    DMA5_12_13_IRQHandler
    def_irq_handler    DMA5_14_15_IRQHandler
    def_irq_handler    DMA5_16_17_IRQHandler
    def_irq_handler    DMA5_18_19_IRQHandler
    def_irq_handler    DMA5_20_21_IRQHandler
    def_irq_handler    DMA5_22_23_IRQHandler
    def_irq_handler    DMA5_24_25_IRQHandler
    def_irq_handler    DMA5_26_27_IRQHandler
    def_irq_handler    DMA5_28_29_IRQHandler
    def_irq_handler    DMA5_30_31_IRQHandler
    def_irq_handler    DMA5_32_33_IRQHandler
    def_irq_handler    DMA5_34_35_IRQHandler
    def_irq_handler    DMA5_36_37_IRQHandler
    def_irq_handler    DMA5_38_39_IRQHandler
    def_irq_handler    DMA5_40_41_IRQHandler
    def_irq_handler    DMA5_42_43_IRQHandler
    def_irq_handler    DMA5_44_45_IRQHandler
    def_irq_handler    DMA5_46_47_IRQHandler
    def_irq_handler    DMA5_48_49_IRQHandler
    def_irq_handler    DMA5_50_51_IRQHandler
    def_irq_handler    DMA5_52_53_IRQHandler
    def_irq_handler    DMA5_54_55_IRQHandler
    def_irq_handler    DMA5_56_57_IRQHandler
    def_irq_handler    DMA5_58_59_IRQHandler
    def_irq_handler    DMA5_60_61_IRQHandler
    def_irq_handler    DMA5_62_63_IRQHandler
    def_irq_handler    Reserved304_IRQHandler
    def_irq_handler    Reserved305_IRQHandler
    def_irq_handler    Reserved306_IRQHandler
    def_irq_handler    Reserved307_IRQHandler
    def_irq_handler    Reserved308_IRQHandler
    def_irq_handler    Reserved309_IRQHandler
    def_irq_handler    Reserved310_IRQHandler
    def_irq_handler    Reserved311_IRQHandler
    def_irq_handler    Reserved312_IRQHandler
    def_irq_handler    Reserved313_IRQHandler
    def_irq_handler    Reserved314_IRQHandler
    def_irq_handler    Reserved315_IRQHandler
    def_irq_handler    Reserved316_IRQHandler
    def_irq_handler    Reserved317_IRQHandler
    def_irq_handler    Reserved318_IRQHandler
    def_irq_handler    Reserved319_IRQHandler
    def_irq_handler    Reserved320_IRQHandler
    def_irq_handler    Reserved321_IRQHandler
    def_irq_handler    Reserved322_IRQHandler
    def_irq_handler    Reserved323_IRQHandler
    def_irq_handler    Reserved324_IRQHandler
    def_irq_handler    Reserved325_IRQHandler
    def_irq_handler    Reserved326_IRQHandler
    def_irq_handler    Reserved327_IRQHandler
    def_irq_handler    Reserved328_IRQHandler
    def_irq_handler    Reserved329_IRQHandler
    def_irq_handler    Reserved330_IRQHandler
    def_irq_handler    Reserved331_IRQHandler
    def_irq_handler    Reserved332_IRQHandler
    def_irq_handler    Reserved333_IRQHandler
    def_irq_handler    Reserved334_IRQHandler
    def_irq_handler    Reserved335_IRQHandler
    def_irq_handler    Reserved336_IRQHandler
    def_irq_handler    Reserved337_IRQHandler
    def_irq_handler    Reserved338_IRQHandler
    def_irq_handler    Reserved339_IRQHandler
    def_irq_handler    Reserved340_IRQHandler
    def_irq_handler    Reserved341_IRQHandler
    def_irq_handler    Reserved342_IRQHandler
    def_irq_handler    Reserved343_IRQHandler
    def_irq_handler    Reserved344_IRQHandler
    def_irq_handler    Reserved345_IRQHandler
    def_irq_handler    Reserved346_IRQHandler
    def_irq_handler    Reserved347_IRQHandler
    def_irq_handler    Reserved348_IRQHandler
    def_irq_handler    Reserved349_IRQHandler
    def_irq_handler    Reserved350_IRQHandler
    def_irq_handler    GPC_SM_REQ_IRQHandler
    def_irq_handler    Reserved352_IRQHandler
    def_irq_handler    Reserved353_IRQHandler
    def_irq_handler    Reserved354_IRQHandler
    def_irq_handler    Reserved355_IRQHandler
    def_irq_handler    Reserved356_IRQHandler
    def_irq_handler    Reserved357_IRQHandler
    def_irq_handler    Reserved358_IRQHandler
    def_irq_handler    Reserved359_IRQHandler
    def_irq_handler    Reserved360_IRQHandler
    def_irq_handler    Reserved361_IRQHandler
    def_irq_handler    Reserved362_IRQHandler
    def_irq_handler    Reserved363_IRQHandler
    def_irq_handler    Reserved364_IRQHandler
    def_irq_handler    Reserved365_IRQHandler
    def_irq_handler    Reserved366_IRQHandler
    def_irq_handler    Reserved367_IRQHandler
    def_irq_handler    Reserved368_IRQHandler
    def_irq_handler    Reserved369_IRQHandler
    def_irq_handler    Reserved370_IRQHandler
    def_irq_handler    Reserved371_IRQHandler
    def_irq_handler    Reserved372_IRQHandler
    def_irq_handler    Reserved373_IRQHandler
    def_irq_handler    Reserved374_IRQHandler
    def_irq_handler    Reserved375_IRQHandler
    def_irq_handler    Reserved376_IRQHandler
    def_irq_handler    Reserved377_IRQHandler
    def_irq_handler    Reserved378_IRQHandler
    def_irq_handler    Reserved379_IRQHandler
    def_irq_handler    Reserved380_IRQHandler
    def_irq_handler    Reserved381_IRQHandler
    def_irq_handler    Reserved382_IRQHandler
    def_irq_handler    Reserved383_IRQHandler
    def_irq_handler    Reserved384_IRQHandler
    def_irq_handler    Reserved385_IRQHandler
    def_irq_handler    Reserved386_IRQHandler
    def_irq_handler    Reserved387_IRQHandler
    def_irq_handler    Reserved388_IRQHandler
    def_irq_handler    Reserved389_IRQHandler
    def_irq_handler    Reserved390_IRQHandler
    def_irq_handler    Reserved391_IRQHandler

    .end
