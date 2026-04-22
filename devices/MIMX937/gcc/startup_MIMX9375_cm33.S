/* ------------------------------------------------------------------------- */
/*  @file:    startup_MIMX9375_cm33.s                                        */
/*  @purpose: CMSIS Cortex-M33 Core Device Startup File                      */
/*            MIMX9375_cm33                                                  */
/*  @version: 1.0                                                            */
/*  @date:    2026-4-9                                                       */
/*  @build:   b260522                                                        */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright 1997-2016 Freescale Semiconductor, Inc.                         */
/* Copyright 2016-2026 NXP                                                   */
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
    .long   RESERVED16_IRQHandler                           /* Reserved interrupt*/
    .long   RESERVED17_IRQHandler                           /* DAP Interrupt*/
    .long   RESERVED18_IRQHandler                           /* CTI trigger outputs from CM7 platform  (internal: CTIIRQ[0])*/
    .long   RESERVED19_IRQHandler                           /* CTI trigger outputs from CM33 platform  (internal: CTIIRQ[0])*/
    .long   RESERVED20_IRQHandler                           /* CTI trigger outputs from CA55 platform  (internal: nCTIIRQ[0])*/
    .long   RESERVED21_IRQHandler                           /* Performance Unit Interrupts from CA55 platform (interrnally:  PMUIRQ[0])*/
    .long   RESERVED22_IRQHandler                           /* ECC error with potential data corruption or loss of coherency from CA55 platform L3 Cache*/
    .long   RESERVED23_IRQHandler                           /* 1-bit or 2-bit ECC or Parity error from CA55 platform L3 Cache*/
    .long   CAN1_IRQHandler                                 /* AONMIX CAN-FD Interrupt from busoff*/
    .long   CAN1_ERROR_IRQHandler                           /* AONMIX CAN-FD Correctable error interrupt*/
    .long   GPIO1_0_IRQHandler                              /* AONMIX GPIO interrupt request 0*/
    .long   GPIO1_1_IRQHandler                              /* AONMIX GPIO interrupt request 1*/
    .long   I3C1_IRQHandler                                 /* AONMIX I3C interrupt request*/
    .long   LPI2C1_IRQHandler                               /* AONMIX LPI2C Master interrupt*/
    .long   LPI2C2_IRQHandler                               /* AONMIX LPI2C Master interrupt*/
    .long   LPIT1_IRQHandler                                /* AONMIX LPIT global interrupt*/
    .long   LPSPI1_IRQHandler                               /* AONMIX LPSPI interrupt*/
    .long   LPSPI2_IRQHandler                               /* AONMIX LPSPI interrupt*/
    .long   LPTMR1_IRQHandler                               /* AONMIX LPTMR async interrupt*/
    .long   LPUART1_IRQHandler                              /* AONMIX LPUART TX interrupt*/
    .long   LPUART2_IRQHandler                              /* AONMIX LPUART TX interrupt*/
    .long   RESERVED37_IRQHandler                           /* AONMIX Sentinel MU0 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX*/
    .long   RESERVED38_IRQHandler                           /* AONMIX Sentinel MU1 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX*/
    .long   RESERVED39_IRQHandler                           /* AONMIX Sentinel MU2 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX*/
    .long   RESERVED40_IRQHandler                           /* AONMIX Sentinel MU3 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX*/
    .long   RESERVED41_IRQHandler                           /* AONMIX Sentinel MU4 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX*/
    .long   RESERVED42_IRQHandler                           /* AONMIX Sentinel MU5 SideA RX full interrupt, masked by BLK_CTRL_S_AONMIX*/
    .long   RESERVED43_IRQHandler                           /* V2X-FH MU APCH0 (APP0) A_TX interrupt*/
    .long   RESERVED44_IRQHandler                           /* V2X-FH MU APHSM1 (HSM1) A_TX interrupt*/
    .long   TPM1_IRQHandler                                 /* AONMIX LPTPM global interrupt*/
    .long   TPM2_IRQHandler                                 /* AONMIX LPTPM global interrupt*/
    .long   WDOG1_IRQHandler_Shim                           /* AONMIX Watchdog interrupt request.  SRC reset source.*/
    .long   WDOG2_IRQHandler_Shim                           /* AONMIX Watchdog interrupt request.  SRC reset source.*/
    .long   TRDC_MGR_A_IRQHandler                           /* AONMIX TRDC transfer error interrupt*/
    .long   SAI1_IRQHandler                                 /* AONMIX SAI TX interrupt*/
    .long   RESERVED51_IRQHandler                           /* AONMIX M33 PS Tag Parity Error*/
    .long   CM33_ECC_MCM_IRQHandler                         /* AONMIX M33 TCM Error interrupt*/
    .long   RESERVED53_IRQHandler                           /* M7MIX ECC Multi-bit error*/
    .long   CAN2_IRQHandler                                 /* WAKEUPMIX CAN-FD Interrupt from busoff*/
    .long   CAN2_ERROR_IRQHandler                           /* WAKEUPMIX CAN-FD Correctable error interrupt*/
    .long   CAN3_IRQHandler                                 /* WAKEUPMIX CAN-FD Interrupt from busoff*/
    .long   CAN3_ERROR_IRQHandler                           /* WAKEUPMIX CAN-FD Correctable error interrupt*/
    .long   WDOG6_IRQHandler                                /* DISPLAYMIX Watchdog interrupt request. SRC reset source.*/
    .long   RESERVED59_IRQHandler                           /* Additional inverted version of Interrupt added for s500_scm_halt_ack_irq. Which could be uzseful for Sentinel Wakeup*/
    .long   RESERVED60_IRQHandler                           /* s500.sentinel_irq_glue_s500_irq_req4 is connected with ocotp_cont_edc_err*/
    .long   DISPLAY_MIX_IRQHandler                          /* Local Dimming Interrupt*/
    .long   FLEXIO1_IRQHandler                              /* WAKEUPMIX FLEXIO interrupt*/
    .long   FLEXIO2_IRQHandler                              /* WAKEUPMIX FLEXIO interrupt*/
    .long   Reserved64_IRQHandler                           /* Reserved*/
    .long   GPIO2_0_IRQHandler                              /* WAKEUPMIX GPIO interrupt request 0*/
    .long   GPIO2_1_IRQHandler                              /* WAKEUPMIX GPIO interrupt request 1*/
    .long   GPIO3_0_IRQHandler                              /* WAKEUPMIX GPIO interrupt request 0*/
    .long   GPIO3_1_IRQHandler                              /* WAKEUPMIX GPIO interrupt request 1*/
    .long   GPIO4_0_IRQHandler                              /* WAKEUPMIX GPIO interrupt request 0*/
    .long   GPIO4_1_IRQHandler                              /* WAKEUPMIX GPIO interrupt request 1*/
    .long   GPIO5_0_IRQHandler                              /* WAKEUPMIX GPIO interrupt request 0*/
    .long   GPIO5_1_IRQHandler                              /* WAKEUPMIX GPIO interrupt request 1*/
    .long   I3C2_IRQHandler                                 /* WAKEUPMIX I3C interrupt request*/
    .long   LPI2C3_IRQHandler                               /* WAKEUPMIX LPI2C Master interrupt*/
    .long   LPI2C4_IRQHandler                               /* WAKEUPMIX LPI2C Master interrupt*/
    .long   LPIT2_IRQHandler                                /* WAKEUPMIX LPIT global interrupt*/
    .long   LPSPI3_IRQHandler                               /* WAKEUPMIX LPSPI interrupt*/
    .long   LPSPI4_IRQHandler                               /* WAKEUPMIX LPSPI interrupt*/
    .long   LPTMR2_IRQHandler                               /* WAKEUPMIX LPTMR async interrupt*/
    .long   LPUART3_IRQHandler                              /* WAKEUPMIX LPUART TX interrupt*/
    .long   LPUART4_IRQHandler                              /* WAKEUPMIX LPUART TX interrupt*/
    .long   LPUART5_IRQHandler                              /* WAKEUPMIX LPUART TX interrupt*/
    .long   LPUART6_IRQHandler                              /* WAKEUPMIX LPUART TX interrupt*/
    .long   LPUART7_IRQHandler                              /* WAKEUPMIX LPUART TX interrupt*/
    .long   LPUART8_IRQHandler                              /* WAKEUPMIX LPUART TX interrupt*/
    .long   MTR_MSTR_IRQHandler                             /* AONMIX MTR Master error interrupt*/
    .long   BBNSM_IRQHandler                                /* BBNSM Non-Secure external wakeup alarm*/
    .long   SYS_CTR1_IRQHandler                             /* WAKEUPMIX System Counter compare interrupt 0*/
    .long   TPM3_IRQHandler                                 /* WAKEUPMIX LPTPM global interrupt*/
    .long   TPM4_IRQHandler                                 /* WAKEUPMIX LPTPM global interrupt*/
    .long   TPM5_IRQHandler                                 /* WAKEUPMIX LPTPM async interrupt*/
    .long   TPM6_IRQHandler                                 /* WAKEUPMIX LPTPM async interrupt*/
    .long   WDOG3_IRQHandler                                /* WAKEUPMIX Watchdog interrupt request. SRC reset source.*/
    .long   WDOG4_IRQHandler                                /* WAKEUPMIX Watchdog interrupt request. SRC reset source.*/
    .long   WDOG5_IRQHandler                                /* WAKEUPMIX Watchdog interrupt request. SRC reset source.*/
    .long   TMPSNS_ANA_1_IRQHandler                         /* ANAMIX TempSensor non-secure interrupt from Threshold 1*/
    .long   TMPSNS_ANA_2_IRQHandler                         /* ANAMIX TempSensor non-secure interrupt from Threshold 2*/
    .long   TMPSNS1_DRDY_IRQHandler                         /* ANAMIX TempSensor non-secure data ready interrupt*/
    .long   TMPSNS_CORTEXA_1_IRQHandler                     /* CORTEXAMIX TempSensor non-secure interrupt from Threshold 1*/
    .long   TMPSNS_CORTEXA_2_IRQHandler                     /* CORTEXAMIX TempSensor non-secure interrupt from Threshold 2*/
    .long   TMPSNS2_DRDY_IRQHandler                         /* CORTEXAMIX TempSensor non-secure data ready interrupt*/
    .long   USDHC1_IRQHandler                               /* MEGAMIX uSDHC Enhanced SDHC Interrupt Request*/
    .long   USDHC2_IRQHandler                               /* MEGAMIX uSDHC Enhanced SDHC Interrupt Request*/
    .long   TRDC_MGR_W1_IRQHandler                          /* WAKEUPMIX TRDC transfer error interrupt*/
    .long   TRDC_MGR_W2_IRQHandler                          /* WAKEUPMIX TRDC transfer error interrupt*/
    .long   TRDC_MGR_N_IRQHandler                           /* NOCMIX TRDC transfer error interrupt*/
    .long   RESERVED107_IRQHandler                          /* DRAM controller Performance Monitor Interrupt*/
    .long   RESERVED108_IRQHandler                          /* DRAM controller Critical Interrupt*/
    .long   RESERVED109_IRQHandler                          /* DRAM Phy Critical Interrupt 0*/
    .long   INTG_BOOTROM_DEBUG_CTRL_IRQHandler              /* Cortex-A Cluster Debug Wakeup Request*/
    .long   DMA3_ERROR_IRQHandler                           /* AONMIX EDMA error interrupt*/
    .long   DMA3_0_IRQHandler                               /* AONMIX EDMA channel 0 interrupt*/
    .long   DMA3_1_IRQHandler                               /* AONMIX EDMA channel 1 interrupt*/
    .long   DMA3_2_IRQHandler                               /* AONMIX EDMA channel 2 interrupt*/
    .long   DMA3_3_IRQHandler                               /* AONMIX EDMA channel 3 interrupt*/
    .long   DMA3_4_IRQHandler                               /* AONMIX EDMA channel 4 interrupt*/
    .long   DMA3_5_IRQHandler                               /* AONMIX EDMA channel 5 interrupt*/
    .long   DMA3_6_IRQHandler                               /* AONMIX EDMA channel 6 interrupt*/
    .long   DMA3_7_IRQHandler                               /* AONMIX EDMA channel 7 interrupt*/
    .long   DMA3_8_IRQHandler                               /* AONMIX EDMA channel 8 interrupt*/
    .long   DMA3_9_IRQHandler                               /* AONMIX EDMA channel 9 interrupt*/
    .long   DMA3_10_IRQHandler                              /* AONMIX EDMA channel 10 interrupt*/
    .long   DMA3_11_IRQHandler                              /* AONMIX EDMA channel 11 interrupt*/
    .long   DMA3_12_IRQHandler                              /* AONMIX EDMA channel 12 interrupt*/
    .long   DMA3_13_IRQHandler                              /* AONMIX EDMA channel 13 interrupt*/
    .long   DMA3_14_IRQHandler                              /* AONMIX EDMA channel 14 interrupt*/
    .long   DMA3_15_IRQHandler                              /* AONMIX EDMA channel 15 interrupt*/
    .long   DMA3_16_IRQHandler                              /* AONMIX EDMA channel 16 interrupt*/
    .long   DMA3_17_IRQHandler                              /* AONMIX EDMA channel 17 interrupt*/
    .long   DMA3_18_IRQHandler                              /* AONMIX EDMA channel 18 interrupt*/
    .long   DMA3_19_IRQHandler                              /* AONMIX EDMA channel 19 interrupt*/
    .long   DMA3_20_IRQHandler                              /* AONMIX EDMA channel 20 interrupt*/
    .long   DMA3_21_IRQHandler                              /* AONMIX EDMA channel 21 interrupt*/
    .long   DMA3_22_IRQHandler                              /* AONMIX EDMA channel 22 interrupt*/
    .long   DMA3_23_IRQHandler                              /* AONMIX EDMA channel 23 interrupt*/
    .long   DMA3_24_IRQHandler                              /* AONMIX EDMA channel 24 interrupt*/
    .long   DMA3_25_IRQHandler                              /* AONMIX EDMA channel 25 interrupt*/
    .long   DMA3_26_IRQHandler                              /* AONMIX EDMA channel 26 interrupt*/
    .long   DMA3_27_IRQHandler                              /* AONMIX EDMA channel 27 interrupt*/
    .long   DMA3_28_IRQHandler                              /* AONMIX EDMA channel 28 interrupt*/
    .long   DMA3_29_IRQHandler                              /* AONMIX EDMA channel 29 interrupt*/
    .long   DMA3_30_IRQHandler                              /* AONMIX EDMA channel 30 interrupt*/
    .long   DMA5_2_ERROR_IRQHandler                         /* WAKEUPMIX EDMA error interrupt*/
    .long   DMA5_2_0_1_IRQHandler                           /* WAKEUPMIX EDMA channel 0 interrupt*/
    .long   DMA5_2_2_3_IRQHandler                           /* WAKEUPMIX EDMA channel 2 interrupt*/
    .long   DMA5_2_4_5_IRQHandler                           /* WAKEUPMIX EDMA channel 4 interrupt*/
    .long   DMA5_2_6_7_IRQHandler                           /* WAKEUPMIX EDMA channel 6 interrupt*/
    .long   DMA5_2_8_9_IRQHandler                           /* WAKEUPMIX EDMA channel 8 interrupt*/
    .long   DMA5_2_10_11_IRQHandler                         /* WAKEUPMIX EDMA channel 10 interrupt*/
    .long   DMA5_2_12_13_IRQHandler                         /* WAKEUPMIX EDMA channel 12 interrupt*/
    .long   DMA5_2_14_15_IRQHandler                         /* WAKEUPMIX EDMA channel 14 interrupt*/
    .long   DMA5_2_16_17_IRQHandler                         /* WAKEUPMIX EDMA channel 16 interrupt*/
    .long   DMA5_2_18_19_IRQHandler                         /* WAKEUPMIX EDMA channel 18 interrupt*/
    .long   DMA5_2_20_21_IRQHandler                         /* WAKEUPMIX EDMA channel 20 interrupt*/
    .long   DMA5_2_22_23_IRQHandler                         /* WAKEUPMIX EDMA channel 22 interrupt*/
    .long   DMA5_2_24_25_IRQHandler                         /* WAKEUPMIX EDMA channel 24 interrupt*/
    .long   DMA5_2_26_27_IRQHandler                         /* WAKEUPMIX EDMA channel 26 interrupt*/
    .long   DMA5_2_28_29_IRQHandler                         /* WAKEUPMIX EDMA channel 28 interrupt*/
    .long   DMA5_2_30_31_IRQHandler                         /* WAKEUPMIX EDMA channel 30 interrupt*/
    .long   DMA5_2_32_33_IRQHandler                         /* WAKEUPMIX EDMA channel 32 interrupt*/
    .long   DMA5_2_34_35_IRQHandler                         /* WAKEUPMIX EDMA channel 34 interrupt*/
    .long   DMA5_2_36_37_IRQHandler                         /* WAKEUPMIX EDMA channel 36 interrupt*/
    .long   DMA5_2_38_39_IRQHandler                         /* WAKEUPMIX EDMA channel 38 interrupt*/
    .long   DMA5_2_40_41_IRQHandler                         /* WAKEUPMIX EDMA channel 40 interrupt*/
    .long   DMA5_2_42_43_IRQHandler                         /* WAKEUPMIX EDMA channel 42 interrupt*/
    .long   DMA5_2_44_45_IRQHandler                         /* WAKEUPMIX EDMA channel 44 interrupt*/
    .long   DMA5_2_46_47_IRQHandler                         /* WAKEUPMIX EDMA channel 46 interrupt*/
    .long   DMA5_2_48_49_IRQHandler                         /* WAKEUPMIX EDMA channel 48 interrupt*/
    .long   DMA5_2_50_51_IRQHandler                         /* WAKEUPMIX EDMA channel 50 interrupt*/
    .long   DMA5_2_52_53_IRQHandler                         /* WAKEUPMIX EDMA channel 52 interrupt*/
    .long   DMA5_2_54_55_IRQHandler                         /* WAKEUPMIX EDMA channel 54 interrupt*/
    .long   DMA5_2_56_57_IRQHandler                         /* WAKEUPMIX EDMA channel 56 interrupt*/
    .long   DMA5_2_58_59_IRQHandler                         /* WAKEUPMIX EDMA channel 58 interrupt*/
    .long   DMA5_2_60_61_IRQHandler                         /* WAKEUPMIX EDMA channel 60 interrupt*/
    .long   DMA5_2_62_63_IRQHandler                         /* WAKEUPMIX EDMA channel 62 interrupt*/
    .long   ELE_Group1_IRQHandler_Shim                      /* Sentinel Group 1 reset source if no s500 reference clock is detected.  Output synchronized to 32khz clk.*/
    .long   ELE_Group2_IRQHandler_Shim                      /* Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk.*/
    .long   ELE_Group3_IRQHandler_Shim                      /* Sentinel Group 3 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk.*/
    .long   DBG_TRACE_IRQHandler                            /* JTAGSW DAP MDM-AP SRC reset source*/
    .long   JTAGC_IRQHandler                                /* JTAGC SRC reset source (the JTAGC used for boundary scan, not JTAGC used for password authentication)*/
    .long   SYSREQRST_CM33_IRQHandler                       /* CM33 SYSREQRST SRC reset source*/
    .long   LOCKUP_CM33_IRQHandler                          /* CM33 LOCKUP SRC reset source*/
    .long   CM7_SYSRESETREQ_IRQHandler                      /* CM7 SYSREQRST SRC reset source*/
    .long   CM7_LOCKUP_IRQHandler                           /* CM7 LOCKUP SRC reset source*/
    .long   SAI2_IRQHandler                                 /* NETCMIX SAI TX interrupt*/
    .long   SAI3_IRQHandler                                 /* WAKEUPMIX SAI TX interrupt*/
    .long   SAI4_IRQHandler                                 /* WAKEUPMIX SAI TX interrupt*/
    .long   SAI5_IRQHandler                                 /* WAKEUPMIX SAI TX interrupt*/
    .long   USB1_WAKEUP_IRQHandler                          /* USB-1 (USB 2.0) Wake-up Interrupt*/
    .long   USB2_WAKEUP_IRQHandler                          /* USB-2 (USB 2.0) Wake-up Interrupt*/
    .long   USB1_IRQHandler                                 /* USB-1 (USB 2.0 Controller) Interrupt*/
    .long   USB2_IRQHandler                                 /* USB-2 (USB 2.0 Controller) Interrupt*/
    .long   LPSPI5_IRQHandler                               /* WAKEUPMIX LPSPI interrupt*/
    .long   LPSPI6_IRQHandler                               /* WAKEUPMIX LPSPI interrupt*/
    .long   LPSPI7_IRQHandler                               /* WAKEUPMIX LPSPI interrupt*/
    .long   LPSPI8_IRQHandler                               /* WAKEUPMIX LPSPI interrupt*/
    .long   LPI2C5_IRQHandler                               /* WAKEUPMIX LPI2C Master interrupt*/
    .long   LPI2C6_IRQHandler                               /* WAKEUPMIX LPI2C Master interrupt*/
    .long   LPI2C7_IRQHandler                               /* WAKEUPMIX LPI2C Master interrupt*/
    .long   LPI2C8_IRQHandler                               /* WAKEUPMIX LPI2C Master interrupt*/
    .long   PDM_HWVAD_ERROR_IRQHandler                      /* AONMIXMIX PDM interrupt*/
    .long   PDM_HWVAD_EVENT_IRQHandler                      /* AONMIXMIX PDM interrupt*/
    .long   PDM_ERROR_IRQHandler                            /* AONMIXMIX PDM interrupt*/
    .long   PDM_EVENT_IRQHandler                            /* AONMIXMIX PDM interrupt*/
    .long   RESERVED205_IRQHandler                          /* WAKEUPMIX AUDIO XCVR interrupt*/
    .long   RESERVED206_IRQHandler                          /* WAKEUPMIX AUDIO XCVR interrupt*/
    .long   USDHC3_IRQHandler                               /* MEGAMIX uSDHC Enhanced SDHC Interrupt Request*/
    .long   RESERVED208_IRQHandler                          /* OCRAM ECC single bit error*/
    .long   RESERVED209_IRQHandler                          /* OCRAM ECC multi bit error*/
    .long   RESERVED210_IRQHandler                          /* CM33 MCM interrupt*/
    .long   RESERVED211_IRQHandler                          /* ANAMIX SFA interrupt*/
    .long   RESERVED212_IRQHandler                          /* GIC700 Fault*/
    .long   RESERVED213_IRQHandler                          /* GIC700 Error*/
    .long   RESERVED214_IRQHandler                          /* GIC700 PMU Counter Overflow*/
    .long   ADC_ER_IRQHandler                               /* ADC interrupt*/
    .long   ADC_WD_IRQHandler                               /* ADC interrupt*/
    .long   ADC_EOC_IRQHandler                              /* ADC interrupt*/
    .long   RESERVED218_IRQHandler                          /* s500 glue logic IRQ*/
    .long   I3C1_RAW_IRQ_GLUE_IRQHandler                    /* I3C1 wakeup irq after double sync*/
    .long   I3C2_RAW_IRQ_GLUE_IRQHandler                    /* I3C2 wakeup irq after double sync*/
    .long   MU5_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU6_A_IRQHandler                                /* AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU7_B_IRQHandler                                /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU8_B_IRQHandler                                /* WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   XSPI_SLV_IRQHandler                             /* WAKEUPMIX XSPI Responder*/
    .long   FCCU_INT0_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 0*/
    .long   FCCU_INT1_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 1*/
    .long   FCCU_INT2_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 2*/
    .long   STCU_IRQHandler                                 /* AONMIX STCU Selftest end Interrupt*/
    .long   DISP_IRQSTEER0_IRQHandler                       /* DISPLAYMIX IRQSTEER 0: Common Control*/
    .long   DISP_IRQSTEER1_IRQHandler                       /* DISPLAYMIX IRQSTEER 1: Display 0 Domain 0*/
    .long   DISP_IRQSTEER2_IRQHandler                       /* DISPLAYMIX IRQSTEER 2: Display 0 Domain 1*/
    .long   DISP_IRQSTEER3_IRQHandler                       /* DISPLAYMIX IRQSTEER 3: Display 1 Domain 0*/
    .long   DISP_IRQSTEER4_IRQHandler                       /* DISPLAYMIX IRQSTEER 4: Display 1 Domain 1*/
    .long   DISP_IRQSTEER7_IRQHandler                       /* DISPLAYMIX IRQSTEER 7: Blitter*/
    .long   MU_C1_IRQHandler                                /* CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   ISI_0_IRQHandler                                /* CAMERAMIX ISI interrupt Channel 0*/
    .long   ISP_IRQHandler                                  /* ISP Processing Interrupt - Context 0*/
    .long   M7MIX_IRQHandler                                /* M7MIX MCM interrupt*/
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
    .long   MSGINTR1_IRQHandler                             /* MSGINTR Instance 1, Interrupt 1*/
    .long   MSGINTR2_IRQHandler                             /* MSGINTR Instance 2, Interrupt 1*/
    .long   RESERVED254_IRQHandler                          /* V2X-FH MU APCH1 (APP1) A_TX interrupt*/
    .long   RESERVED255_IRQHandler                          /* V2X-FH MU APHSM2 (HSM2) A_TX interrupt*/
    .long   TRDC_MGR_C_IRQHandler                           /* CAMERAMIX TRDC transfer error interrupt*/
    .long   TRDC_MGR_D_IRQHandler                           /* DISPLAYMIX TRDC transfer error interrupt*/
    .long   TRDC_MGR_E_IRQHandler                           /* NETCMIX TRDC transfer error interrupt*/
    .long   TRDC_MGR_G_IRQHandler                           /* GPUMIX TRDC transfer error interrupt*/
    .long   TRDC_MGR_H_IRQHandler                           /* HSIOMIX TRDC transfer error interrupt*/
    .long   TRDC_MGR_V_IRQHandler                           /* VPUMIX TRDC transfer error interrupt*/
    .long   ERM_A_IRQHandler                                /* AONMIX ERM Single bit corrected ECC Error*/
    .long   RESERVED263_IRQHandler                          /* M7MIX ERM Single bit corrected ECC Error*/
    .long   ERM_W_IRQHandler                                /* WAKEUPMIX ERM Single bit corrected ECC Error*/
    .long   ERM_ML_IRQHandler                               /* NPUMIX ERM Single bit corrected ECC Error*/
    .long   DMA5_3_ERROR_IRQHandler                         /* WAKEUPMIX ACP EDMA error interrupt*/
    .long   OCRAM_C_IRQHandler                              /* OCRAM_C ECC multiple bit or address error*/
    .long   RESERVED268_IRQHandler                          /* CAMERAMIX Cortex-M0+ Cache write-buffer error*/
    .long   RESERVED269_IRQHandler                          /* CAMERAMIX Cortex-M0+ Cache data parity error*/
    .long   RESERVED270_IRQHandler                          /* V2X-FH MU APSHE (SHE) A_TX interrupt*/
    .long   RESERVED271_IRQHandler                          /* V2X-FH MU SCU/APDEBUG (DEBUG) B_TX interrupt*/
    .long   DMA5_3_0_1_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 0 interrupt*/
    .long   DMA5_3_2_3_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 2 interrupt*/
    .long   DMA5_3_4_5_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 4 interrupt*/
    .long   DMA5_3_6_7_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 6 interrupt*/
    .long   DMA5_3_8_9_IRQHandler                           /* WAKEUPMIX ACP EDMA channel 8 interrupt*/
    .long   DMA5_3_10_11_IRQHandler                         /* WAKEUPMIX ACP EDMA channel 10 interrupt*/
    .long   DMA5_3_12_13_IRQHandler                         /* WAKEUPMIX ACP EDMA channel 12 interrupt*/
    .long   DMA5_3_14_15_IRQHandler                         /* WAKEUPMIX ACP EDMA channel 14 interrupt*/
    .long   DMA5_3_16_17_IRQHandler                         /* WAKEUPMIX ACP EDMA channel 16 interrupt*/
    .long   DMA5_3_18_19_IRQHandler                         /* WAKEUPMIX ACP EDMA channel 18 interrupt*/
    .long   DMA5_3_20_21_IRQHandler                         /* WAKEUPMIX ACP EDMA channel 20 interrupt*/
    .long   DMA5_3_22_23_IRQHandler                         /* WAKEUPMIX ACP EDMA channel 22 interrupt*/
    .long   DMA5_3_24_25_IRQHandler                         /* WAKEUPMIX ACP EDMA channel 24 interrupt*/
    .long   DMA5_3_26_27_IRQHandler                         /* WAKEUPMIX ACP EDMA channel 26 interrupt*/
    .long   DMA5_3_28_29_IRQHandler                         /* WAKEUPMIX ACP EDMA channel 28 interrupt*/
    .long   DMA5_3_30_31_IRQHandler                         /* WAKEUPMIX ACP EDMA channel 30 interrupt*/
    .long   DMA5_3_32_33_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 32 interrupt*/
    .long   DMA5_3_34_35_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 34 interrupt*/
    .long   DMA5_3_36_37_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 36 interrupt*/
    .long   DMA5_3_38_39_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 38 interrupt*/
    .long   DMA5_3_40_41_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 40 interrupt*/
    .long   DMA5_3_42_43_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 42 interrupt*/
    .long   DMA5_3_44_45_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 44 interrupt*/
    .long   DMA5_3_46_47_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 46 interrupt*/
    .long   DMA5_3_48_49_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 48 interrupt*/
    .long   DMA5_3_50_51_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 50 interrupt*/
    .long   DMA5_3_52_53_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 52 interrupt*/
    .long   DMA5_3_54_55_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 54 interrupt*/
    .long   DMA5_3_56_57_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 56 interrupt*/
    .long   DMA5_3_58_59_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 58 interrupt*/
    .long   DMA5_3_60_61_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 60 interrupt*/
    .long   DMA5_3_62_63_IRQHandler                         /*  WAKEUPMIX ACP EDMA channel 62 interrupt*/
    .long   RESERVED304_IRQHandler                          /* GPUMIX GPU Interrupt*/
    .long   RESERVED305_IRQHandler                          /* GPUMIX Job Interrupt*/
    .long   RESERVED306_IRQHandler                          /* GPUMIX MMU Interrupt*/
    .long   RESERVED307_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED308_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED309_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED310_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED311_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED312_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED313_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED314_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED315_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED316_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED317_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED318_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED319_IRQHandler                          /* CODA980 VPU Encoder*/
    .long   RESERVED320_IRQHandler                          /* NETC iEPRC PCI INT (one per each of two RC-EC)*/
    .long   RESERVED321_IRQHandler                          /* NETC iEPRC PCI INT (one per each of two RC-EC)*/
    .long   RESERVED322_IRQHandler                          /* PCIe Controller 1 INTA*/
    .long   RESERVED323_IRQHandler                          /* PCIe Controller 1 INTB*/
    .long   RESERVED324_IRQHandler                          /* PCIe Controller 1 INTC*/
    .long   RESERVED325_IRQHandler                          /* PCIe Controller 1 INTD*/
    .long   RESERVED326_IRQHandler                          /* PCIe miscellaneous interrupts*/
    .long   RESERVED327_IRQHandler                          /* PCIe Controller EDMA channel interrupt*/
    .long   RESERVED328_IRQHandler                          /* Reserved*/
    .long   RESERVED329_IRQHandler                          /* Reserved*/
    .long   RESERVED330_IRQHandler                          /* Reserved*/
    .long   RESERVED331_IRQHandler                          /* Reserved*/
    .long   RESERVED332_IRQHandler                          /* Reserved*/
    .long   RESERVED333_IRQHandler                          /* Reserved*/
    .long   RESERVED334_IRQHandler                          /* NPU Functional interrupt*/
    .long   RESERVED335_IRQHandler                          /* NPU Fault interrupt*/
    .long   RESERVED336_IRQHandler                          /* Reserved*/
    .long   RESERVED337_IRQHandler                          /* Reserved*/
    .long   RESERVED338_IRQHandler                          /* Reserved*/
    .long   RESERVED339_IRQHandler                          /* Reserved*/
    .long   RESERVED340_IRQHandler                          /* Reserved*/
    .long   RESERVED341_IRQHandler                          /* Reserved*/
    .long   RESERVED342_IRQHandler                          /* Reserved*/
    .long   RESERVED343_IRQHandler                          /* Reserved*/
    .long   RESERVED344_IRQHandler                          /* Reserved*/
    .long   RESERVED345_IRQHandler                          /* Reserved*/
    .long   RESERVED346_IRQHandler                          /* Reserved*/
    .long   RESERVED347_IRQHandler                          /* Reserved*/
    .long   RESERVED348_IRQHandler                          /* Reserved*/
    .long   RESERVED349_IRQHandler                          /* Reserved*/
    .long   RESERVED350_IRQHandler                          /* Reserved*/
    .long   GPC_SM_REQ_IRQHandler                           /* SRC/GPC Low Power Handshake Gasket interrupt request for system management*/
    .long   MU_C2_IRQHandler                                /* CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_C3_IRQHandler                                /* CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_C4_IRQHandler                                /* CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_C5_IRQHandler                                /* CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_C6_IRQHandler                                /* CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_C7_IRQHandler                                /* CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_C8_IRQHandler                                /* CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_C9_IRQHandler                                /* CAMERAMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   ISI_1_IRQHandler                                /* CAMERAMIX ISI interrupt Channel 1*/
    .long   ISI_2_IRQHandler                                /* CAMERAMIX ISI interrupt Channel 2*/
    .long   ISI_3_IRQHandler                                /* CAMERAMIX ISI interrupt Channel 3*/
    .long   ISI_4_IRQHandler                                /* CAMERAMIX ISI interrupt Channel 4*/
    .long   ISI_5_IRQHandler                                /* CAMERAMIX ISI interrupt Channel 5*/
    .long   ISI_6_IRQHandler                                /* CAMERAMIX ISI interrupt Channel 6*/
    .long   ISI_7_IRQHandler                                /* CAMERAMIX ISI interrupt Channel 7*/
    .long   DMA5_4_ERROR_IRQHandler                         /* CAMERAMIX EDMA error interrupt*/
    .long   DMA5_4_0_1_IRQHandler                           /* CAMERAMIX EDMA channel 0 interrupt*/
    .long   DMA5_4_2_3_IRQHandler                           /* CAMERAMIX EDMA channel 2 interrupt*/
    .long   DMA5_4_4_5_IRQHandler                           /* CAMERAMIX EDMA channel 4 interrupt*/
    .long   DMA5_4_6_7_IRQHandler                           /* CAMERAMIX EDMA channel 6 interrupt*/
    .long   DMA5_4_8_9_IRQHandler                           /* CAMERAMIX EDMA channel 8 interrupt*/
    .long   DMA5_4_10_11_IRQHandler                         /* CAMERAMIX EDMA channel 10 interrupt*/
    .long   DMA5_4_12_13_IRQHandler                         /* CAMERAMIX EDMA channel 12 interrupt*/
    .long   DMA5_4_14_15_IRQHandler                         /* CAMERAMIX EDMA channel 14 interrupt*/
    .long   DMA5_4_16_17_IRQHandler                         /* CAMERAMIX EDMA channel 16 interrupt*/
    .long   DMA5_4_18_19_IRQHandler                         /* CAMERAMIX EDMA channel 18 interrupt*/
    .long   DMA5_4_20_21_IRQHandler                         /* CAMERAMIX EDMA channel 20 interrupt*/
    .long   DMA5_4_22_23_IRQHandler                         /* CAMERAMIX EDMA channel 22 interrupt*/
    .long   DMA5_4_24_25_IRQHandler                         /* CAMERAMIX EDMA channel 24 interrupt*/
    .long   DMA5_4_26_27_IRQHandler                         /* CAMERAMIX EDMA channel 26 interrupt*/
    .long   DMA5_4_28_29_IRQHandler                         /* CAMERAMIX EDMA channel 28 interrupt*/
    .long   DMA5_4_30_31_IRQHandler                         /* CAMERAMIX EDMA channel 30 interrupt*/
    .long   RESERVED384_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 1: Buffer overflow*/
    .long   RESERVED385_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 1: Interlaced Error*/
    .long   RESERVED386_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 1: Pixel Data Type Error*/
    .long   RESERVED387_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 2: Buffer overflow*/
    .long   RESERVED388_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 2: Interlaced Error*/
    .long   RESERVED389_IRQHandler                          /* CAMERAMIX CSI Formatting Unit 2: Pixel Data Type Error*/
    .long   CSI1_IRQHandler                                 /* CAMERAMIX CSI1 (Standalone MIPI-CSI) interrupt*/
    .long   CSI2_IRQHandler                                 /* CAMERAMIX CSI2 (Combo MIPI-CSI/DSI) interrupt*/
    .long   ASRC1_IRQHandler                                /* mirq_asrc1_b*/
    .long   RESERVED393_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED394_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED395_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED396_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED397_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED398_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED399_IRQHandler                          /* Reserved*/
    .long   ASRC2_IRQHandler                                /* mirq_asrc2_b*/
    .long   RESERVED401_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED402_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED403_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED404_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED405_IRQHandler                          /* Reserved interrupt*/
    .long   RESERVED406_IRQHandler                          /* Reserved interrupt*/
    .long   NOC_VPU_IRQHandler                              /* Reserved interrupt*/
    .long   NOC_DISPLAY_IRQHandler                          /* Reserved interrupt*/
    .long   NOC_CAMERA_IRQHandler                           /* Reserved interrupt*/
    .long   NOC_HSIO_IRQHandler                             /* Reserved interrupt*/
    .long   NOC_WAKEUP_IRQHandler                           /* Reserved interrupt*/
    .long   NOC_CENTRAL_IRQHandler                          /* Reserved interrupt*/
    .long   ERM_DISPLAY_IRQHandler                          /* DISPLAYMIX ERM Single bit corrected ECC Error*/
    .long   RESERVED414_IRQHandler                          /* Reserved*/
    .long   SAI6_IRQHandler                                 /* WAKEUPMIX SAI TX interrupt*/
    .long   XSPI1_0_IRQHandler                              /* xspi1 all interrupts ORed output for EENV0 (MEENV)*/
    .long   XSPI1_1_IRQHandler                              /* xspi1 all interrupts ORed output for EENV1 (MEENV)*/
    .long   XSPI1_2_IRQHandler                              /* xspi1 all interrupts ORed output for EENV2 (MEENV)*/
    .long   XSPI1_3_IRQHandler                              /* xspi1 all interrupts ORed output for EENV3 (MEENV)*/
    .long   XSPI1_4_IRQHandler                              /* xspi1 all interrupts ORed output for EENV4 (MEENV)*/
    .long   RESERVED421_IRQHandler                          /* Anamix Gllitch Detector output (da_ip_voltage_glitch_detector_cln16ffc). It's a latch signal. It can be cleared.  Positive polarity i.e interrupt is generated when 0-->1*/
    .long   RESERVED422_IRQHandler                          /* Anamix VDET output (da_ip_vdetect_c16ffc). Detects high threshold on Core supply. It's a latch signal. It can be cleared.  Positive polarity i.e interrupt is generated when 0-->1*/
    .long   CCM_IRQHandler                                  /* LPCG Timeout interrupt generated by CCGR (CCM)*/
    .long   MU_D1_IRQHandler                                /* DISPLAYMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_D2_IRQHandler                                /* DISPLAYMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   GPT2_IRQHandler                                 /* WAKEUPMIX GPT2 interrupt*/
    .long   GPT3_IRQHandler                                 /* WAKEUPMIX GPT2 interrupt*/
    .long   GPT4_IRQHandler                                 /* WAKEUPMIX GPT2 interrupt*/
    .long   GPT5_IRQHandler                                 /* WAKEUPMIX GPT2 interrupt*/
    .long   LPSPI9_IRQHandler                               /* DISPLAYMIX LPSPI interrupt*/

    .size   __isr_vector, . - __isr_vector

    .text
    .thumb

#if defined (__cplusplus)
#ifdef __REDLIB__
#error Redlib does not support C++
#endif
#endif
/* Reset Handler */
    .equ _AON_BLK_CTRL_NS_BASE, 0x44210000
    .equ _IPG_DEBUG_CM33, 0x8
    .equ _AON_BLK_CTRL_S_BASE, 0x444F0000
    .equ _WDOGANY,  0x1B8
    .equ _WDOG_UNLOCK_KEY, 0xD928C520
    .equ _WDOGBASE, 0x442E0000
    .equ _WDOGCS,   0x0
    .equ _WDOGCNT,  0x4
    .equ _WDOGTOVAL,0x8

    .thumb_func
    .align 2
    .globl   Reset_Handler
    .weak    Reset_Handler
    .type    Reset_Handler, %function
Reset_Handler:
    /* Configure WDOGs to halt on debug */
    ldr r0, =_AON_BLK_CTRL_NS_BASE
    ldr r1, =0x1800U
    str r1, [r0, #_IPG_DEBUG_CM33]
    /* Configure WDOG to drive WDOG_ANY */
    ldr r0, =_AON_BLK_CTRL_S_BASE
    ldr r1, =0x1D
    str r1, [r0, #_WDOGANY]
    ldr r0, =_WDOGBASE
    /* Unlock the WDOG */
    ldr r1, =_WDOG_UNLOCK_KEY
    str r1, [r0, #_WDOGCNT]

    /* Write to TOVAL is required before write of configuration register
     *
     *  TOVAL = timeout * clock rate
     *        = 1000 msec * 32768 Hz
     *        = 32768
     *        = 32768
     */
    ldr r1, =32768
    str r1, [r0, #_WDOGTOVAL]

    /* Enable the WDOG
     *
     * Update configuration register (WDOGCS) as follows:
     *
     *  WDGW = window mode disabled     = (0 << 15) = 0x0000
     *  CMD32 = enable 32-bit commands  = (1 << 13) = 0x2000
     *  PRES = disable 256 prescalar    = (0 << 12) = 0x0000
     *  CLK = LPOCLK as clock source    = (1 << 8)  = 0x0100
     *  EN = enable watchdog            = (1 << 7)  = 0x0080
     *  INT = enable early interrupt    = (1 << 6)  = 0x0040
     *  UPDATE = allow WDGCS updates    = (1 << 5)  = 0x0020
     *  TST = test mode disabled        = (0 << 3)  = 0x0000
     *  DBG = disable watchdog in debug = (0 << 2)  = 0x0000
     *  WAIT = enable watchdog in wait  = (1 << 1)  = 0x0002
     *  STOP = disable watchdog in stop = (0 << 0)  = 0x0000
     *                                              --------
     *                                                0x21E2
     */
    ldr r1, =0x21E2
    str r1, [r0, #_WDOGCS]
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
    def_irq_handler    RESERVED16_IRQHandler
    def_irq_handler    RESERVED17_IRQHandler
    def_irq_handler    RESERVED18_IRQHandler
    def_irq_handler    RESERVED19_IRQHandler
    def_irq_handler    RESERVED20_IRQHandler
    def_irq_handler    RESERVED21_IRQHandler
    def_irq_handler    RESERVED22_IRQHandler
    def_irq_handler    RESERVED23_IRQHandler
    def_irq_handler    CAN1_IRQHandler
    def_irq_handler    CAN1_ERROR_IRQHandler
    def_irq_handler    GPIO1_0_IRQHandler
    def_irq_handler    GPIO1_1_IRQHandler
    def_irq_handler    I3C1_IRQHandler
    def_irq_handler    LPI2C1_IRQHandler
    def_irq_handler    LPI2C2_IRQHandler
    def_irq_handler    LPIT1_IRQHandler
    def_irq_handler    LPSPI1_IRQHandler
    def_irq_handler    LPSPI2_IRQHandler
    def_irq_handler    LPTMR1_IRQHandler
    def_irq_handler    LPUART1_IRQHandler
    def_irq_handler    LPUART2_IRQHandler
    def_irq_handler    RESERVED37_IRQHandler
    def_irq_handler    RESERVED38_IRQHandler
    def_irq_handler    RESERVED39_IRQHandler
    def_irq_handler    RESERVED40_IRQHandler
    def_irq_handler    RESERVED41_IRQHandler
    def_irq_handler    RESERVED42_IRQHandler
    def_irq_handler    RESERVED43_IRQHandler
    def_irq_handler    RESERVED44_IRQHandler
    def_irq_handler    TPM1_IRQHandler
    def_irq_handler    TPM2_IRQHandler
    def_irq_handler    WDOG1_IRQHandler
    def_irq_handler    WDOG2_IRQHandler
    def_irq_handler    TRDC_MGR_A_IRQHandler
    def_irq_handler    SAI1_IRQHandler
    def_irq_handler    RESERVED51_IRQHandler
    def_irq_handler    CM33_ECC_MCM_IRQHandler
    def_irq_handler    RESERVED53_IRQHandler
    def_irq_handler    CAN2_IRQHandler
    def_irq_handler    CAN2_ERROR_IRQHandler
    def_irq_handler    CAN3_IRQHandler
    def_irq_handler    CAN3_ERROR_IRQHandler
    def_irq_handler    WDOG6_IRQHandler
    def_irq_handler    RESERVED59_IRQHandler
    def_irq_handler    RESERVED60_IRQHandler
    def_irq_handler    DISPLAY_MIX_IRQHandler
    def_irq_handler    FLEXIO1_IRQHandler
    def_irq_handler    FLEXIO2_IRQHandler
    def_irq_handler    Reserved64_IRQHandler
    def_irq_handler    GPIO2_0_IRQHandler
    def_irq_handler    GPIO2_1_IRQHandler
    def_irq_handler    GPIO3_0_IRQHandler
    def_irq_handler    GPIO3_1_IRQHandler
    def_irq_handler    GPIO4_0_IRQHandler
    def_irq_handler    GPIO4_1_IRQHandler
    def_irq_handler    GPIO5_0_IRQHandler
    def_irq_handler    GPIO5_1_IRQHandler
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
    def_irq_handler    MTR_MSTR_IRQHandler
    def_irq_handler    BBNSM_IRQHandler
    def_irq_handler    SYS_CTR1_IRQHandler
    def_irq_handler    TPM3_IRQHandler
    def_irq_handler    TPM4_IRQHandler
    def_irq_handler    TPM5_IRQHandler
    def_irq_handler    TPM6_IRQHandler
    def_irq_handler    WDOG3_IRQHandler
    def_irq_handler    WDOG4_IRQHandler
    def_irq_handler    WDOG5_IRQHandler
    def_irq_handler    TMPSNS_ANA_1_IRQHandler
    def_irq_handler    TMPSNS_ANA_2_IRQHandler
    def_irq_handler    TMPSNS1_DRDY_IRQHandler
    def_irq_handler    TMPSNS_CORTEXA_1_IRQHandler
    def_irq_handler    TMPSNS_CORTEXA_2_IRQHandler
    def_irq_handler    TMPSNS2_DRDY_IRQHandler
    def_irq_handler    USDHC1_IRQHandler
    def_irq_handler    USDHC2_IRQHandler
    def_irq_handler    TRDC_MGR_W1_IRQHandler
    def_irq_handler    TRDC_MGR_W2_IRQHandler
    def_irq_handler    TRDC_MGR_N_IRQHandler
    def_irq_handler    RESERVED107_IRQHandler
    def_irq_handler    RESERVED108_IRQHandler
    def_irq_handler    RESERVED109_IRQHandler
    def_irq_handler    INTG_BOOTROM_DEBUG_CTRL_IRQHandler
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
    def_irq_handler    DMA5_2_ERROR_IRQHandler
    def_irq_handler    DMA5_2_0_1_IRQHandler
    def_irq_handler    DMA5_2_2_3_IRQHandler
    def_irq_handler    DMA5_2_4_5_IRQHandler
    def_irq_handler    DMA5_2_6_7_IRQHandler
    def_irq_handler    DMA5_2_8_9_IRQHandler
    def_irq_handler    DMA5_2_10_11_IRQHandler
    def_irq_handler    DMA5_2_12_13_IRQHandler
    def_irq_handler    DMA5_2_14_15_IRQHandler
    def_irq_handler    DMA5_2_16_17_IRQHandler
    def_irq_handler    DMA5_2_18_19_IRQHandler
    def_irq_handler    DMA5_2_20_21_IRQHandler
    def_irq_handler    DMA5_2_22_23_IRQHandler
    def_irq_handler    DMA5_2_24_25_IRQHandler
    def_irq_handler    DMA5_2_26_27_IRQHandler
    def_irq_handler    DMA5_2_28_29_IRQHandler
    def_irq_handler    DMA5_2_30_31_IRQHandler
    def_irq_handler    DMA5_2_32_33_IRQHandler
    def_irq_handler    DMA5_2_34_35_IRQHandler
    def_irq_handler    DMA5_2_36_37_IRQHandler
    def_irq_handler    DMA5_2_38_39_IRQHandler
    def_irq_handler    DMA5_2_40_41_IRQHandler
    def_irq_handler    DMA5_2_42_43_IRQHandler
    def_irq_handler    DMA5_2_44_45_IRQHandler
    def_irq_handler    DMA5_2_46_47_IRQHandler
    def_irq_handler    DMA5_2_48_49_IRQHandler
    def_irq_handler    DMA5_2_50_51_IRQHandler
    def_irq_handler    DMA5_2_52_53_IRQHandler
    def_irq_handler    DMA5_2_54_55_IRQHandler
    def_irq_handler    DMA5_2_56_57_IRQHandler
    def_irq_handler    DMA5_2_58_59_IRQHandler
    def_irq_handler    DMA5_2_60_61_IRQHandler
    def_irq_handler    DMA5_2_62_63_IRQHandler
    def_irq_handler    ELE_GROUP1_IRQHandler
    def_irq_handler    ELE_GROUP2_IRQHandler
    def_irq_handler    ELE_GROUP3_IRQHandler
    def_irq_handler    DBG_TRACE_IRQHandler
    def_irq_handler    JTAGC_IRQHandler
    def_irq_handler    SYSREQRST_CM33_IRQHandler
    def_irq_handler    LOCKUP_CM33_IRQHandler
    def_irq_handler    CM7_SYSRESETREQ_IRQHandler
    def_irq_handler    CM7_LOCKUP_IRQHandler
    def_irq_handler    SAI2_IRQHandler
    def_irq_handler    SAI3_IRQHandler
    def_irq_handler    SAI4_IRQHandler
    def_irq_handler    SAI5_IRQHandler
    def_irq_handler    USB1_WAKEUP_IRQHandler
    def_irq_handler    USB2_WAKEUP_IRQHandler
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
    def_irq_handler    RESERVED205_IRQHandler
    def_irq_handler    RESERVED206_IRQHandler
    def_irq_handler    USDHC3_IRQHandler
    def_irq_handler    RESERVED208_IRQHandler
    def_irq_handler    RESERVED209_IRQHandler
    def_irq_handler    RESERVED210_IRQHandler
    def_irq_handler    RESERVED211_IRQHandler
    def_irq_handler    RESERVED212_IRQHandler
    def_irq_handler    RESERVED213_IRQHandler
    def_irq_handler    RESERVED214_IRQHandler
    def_irq_handler    ADC_ER_IRQHandler
    def_irq_handler    ADC_WD_IRQHandler
    def_irq_handler    ADC_EOC_IRQHandler
    def_irq_handler    RESERVED218_IRQHandler
    def_irq_handler    I3C1_RAW_IRQ_GLUE_IRQHandler
    def_irq_handler    I3C2_RAW_IRQ_GLUE_IRQHandler
    def_irq_handler    MU5_A_IRQHandler
    def_irq_handler    MU6_A_IRQHandler
    def_irq_handler    MU7_B_IRQHandler
    def_irq_handler    MU8_B_IRQHandler
    def_irq_handler    XSPI_SLV_IRQHandler
    def_irq_handler    FCCU_INT0_IRQHandler
    def_irq_handler    FCCU_INT1_IRQHandler
    def_irq_handler    FCCU_INT2_IRQHandler
    def_irq_handler    STCU_IRQHandler
    def_irq_handler    DISP_IRQSTEER0_IRQHandler
    def_irq_handler    DISP_IRQSTEER1_IRQHandler
    def_irq_handler    DISP_IRQSTEER2_IRQHandler
    def_irq_handler    DISP_IRQSTEER3_IRQHandler
    def_irq_handler    DISP_IRQSTEER4_IRQHandler
    def_irq_handler    DISP_IRQSTEER7_IRQHandler
    def_irq_handler    MU_C1_IRQHandler
    def_irq_handler    ISI_0_IRQHandler
    def_irq_handler    ISP_IRQHandler
    def_irq_handler    M7MIX_IRQHandler
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
    def_irq_handler    MSGINTR1_IRQHandler
    def_irq_handler    MSGINTR2_IRQHandler
    def_irq_handler    RESERVED254_IRQHandler
    def_irq_handler    RESERVED255_IRQHandler
    def_irq_handler    TRDC_MGR_C_IRQHandler
    def_irq_handler    TRDC_MGR_D_IRQHandler
    def_irq_handler    TRDC_MGR_E_IRQHandler
    def_irq_handler    TRDC_MGR_G_IRQHandler
    def_irq_handler    TRDC_MGR_H_IRQHandler
    def_irq_handler    TRDC_MGR_V_IRQHandler
    def_irq_handler    ERM_A_IRQHandler
    def_irq_handler    RESERVED263_IRQHandler
    def_irq_handler    ERM_W_IRQHandler
    def_irq_handler    ERM_ML_IRQHandler
    def_irq_handler    DMA5_3_ERROR_IRQHandler
    def_irq_handler    OCRAM_C_IRQHandler
    def_irq_handler    RESERVED268_IRQHandler
    def_irq_handler    RESERVED269_IRQHandler
    def_irq_handler    RESERVED270_IRQHandler
    def_irq_handler    RESERVED271_IRQHandler
    def_irq_handler    DMA5_3_0_1_IRQHandler
    def_irq_handler    DMA5_3_2_3_IRQHandler
    def_irq_handler    DMA5_3_4_5_IRQHandler
    def_irq_handler    DMA5_3_6_7_IRQHandler
    def_irq_handler    DMA5_3_8_9_IRQHandler
    def_irq_handler    DMA5_3_10_11_IRQHandler
    def_irq_handler    DMA5_3_12_13_IRQHandler
    def_irq_handler    DMA5_3_14_15_IRQHandler
    def_irq_handler    DMA5_3_16_17_IRQHandler
    def_irq_handler    DMA5_3_18_19_IRQHandler
    def_irq_handler    DMA5_3_20_21_IRQHandler
    def_irq_handler    DMA5_3_22_23_IRQHandler
    def_irq_handler    DMA5_3_24_25_IRQHandler
    def_irq_handler    DMA5_3_26_27_IRQHandler
    def_irq_handler    DMA5_3_28_29_IRQHandler
    def_irq_handler    DMA5_3_30_31_IRQHandler
    def_irq_handler    DMA5_3_32_33_IRQHandler
    def_irq_handler    DMA5_3_34_35_IRQHandler
    def_irq_handler    DMA5_3_36_37_IRQHandler
    def_irq_handler    DMA5_3_38_39_IRQHandler
    def_irq_handler    DMA5_3_40_41_IRQHandler
    def_irq_handler    DMA5_3_42_43_IRQHandler
    def_irq_handler    DMA5_3_44_45_IRQHandler
    def_irq_handler    DMA5_3_46_47_IRQHandler
    def_irq_handler    DMA5_3_48_49_IRQHandler
    def_irq_handler    DMA5_3_50_51_IRQHandler
    def_irq_handler    DMA5_3_52_53_IRQHandler
    def_irq_handler    DMA5_3_54_55_IRQHandler
    def_irq_handler    DMA5_3_56_57_IRQHandler
    def_irq_handler    DMA5_3_58_59_IRQHandler
    def_irq_handler    DMA5_3_60_61_IRQHandler
    def_irq_handler    DMA5_3_62_63_IRQHandler
    def_irq_handler    RESERVED304_IRQHandler
    def_irq_handler    RESERVED305_IRQHandler
    def_irq_handler    RESERVED306_IRQHandler
    def_irq_handler    RESERVED307_IRQHandler
    def_irq_handler    RESERVED308_IRQHandler
    def_irq_handler    RESERVED309_IRQHandler
    def_irq_handler    RESERVED310_IRQHandler
    def_irq_handler    RESERVED311_IRQHandler
    def_irq_handler    RESERVED312_IRQHandler
    def_irq_handler    RESERVED313_IRQHandler
    def_irq_handler    RESERVED314_IRQHandler
    def_irq_handler    RESERVED315_IRQHandler
    def_irq_handler    RESERVED316_IRQHandler
    def_irq_handler    RESERVED317_IRQHandler
    def_irq_handler    RESERVED318_IRQHandler
    def_irq_handler    RESERVED319_IRQHandler
    def_irq_handler    RESERVED320_IRQHandler
    def_irq_handler    RESERVED321_IRQHandler
    def_irq_handler    RESERVED322_IRQHandler
    def_irq_handler    RESERVED323_IRQHandler
    def_irq_handler    RESERVED324_IRQHandler
    def_irq_handler    RESERVED325_IRQHandler
    def_irq_handler    RESERVED326_IRQHandler
    def_irq_handler    RESERVED327_IRQHandler
    def_irq_handler    RESERVED328_IRQHandler
    def_irq_handler    RESERVED329_IRQHandler
    def_irq_handler    RESERVED330_IRQHandler
    def_irq_handler    RESERVED331_IRQHandler
    def_irq_handler    RESERVED332_IRQHandler
    def_irq_handler    RESERVED333_IRQHandler
    def_irq_handler    RESERVED334_IRQHandler
    def_irq_handler    RESERVED335_IRQHandler
    def_irq_handler    RESERVED336_IRQHandler
    def_irq_handler    RESERVED337_IRQHandler
    def_irq_handler    RESERVED338_IRQHandler
    def_irq_handler    RESERVED339_IRQHandler
    def_irq_handler    RESERVED340_IRQHandler
    def_irq_handler    RESERVED341_IRQHandler
    def_irq_handler    RESERVED342_IRQHandler
    def_irq_handler    RESERVED343_IRQHandler
    def_irq_handler    RESERVED344_IRQHandler
    def_irq_handler    RESERVED345_IRQHandler
    def_irq_handler    RESERVED346_IRQHandler
    def_irq_handler    RESERVED347_IRQHandler
    def_irq_handler    RESERVED348_IRQHandler
    def_irq_handler    RESERVED349_IRQHandler
    def_irq_handler    RESERVED350_IRQHandler
    def_irq_handler    GPC_SM_REQ_IRQHandler
    def_irq_handler    MU_C2_IRQHandler
    def_irq_handler    MU_C3_IRQHandler
    def_irq_handler    MU_C4_IRQHandler
    def_irq_handler    MU_C5_IRQHandler
    def_irq_handler    MU_C6_IRQHandler
    def_irq_handler    MU_C7_IRQHandler
    def_irq_handler    MU_C8_IRQHandler
    def_irq_handler    MU_C9_IRQHandler
    def_irq_handler    ISI_1_IRQHandler
    def_irq_handler    ISI_2_IRQHandler
    def_irq_handler    ISI_3_IRQHandler
    def_irq_handler    ISI_4_IRQHandler
    def_irq_handler    ISI_5_IRQHandler
    def_irq_handler    ISI_6_IRQHandler
    def_irq_handler    ISI_7_IRQHandler
    def_irq_handler    DMA5_4_ERROR_IRQHandler
    def_irq_handler    DMA5_4_0_1_IRQHandler
    def_irq_handler    DMA5_4_2_3_IRQHandler
    def_irq_handler    DMA5_4_4_5_IRQHandler
    def_irq_handler    DMA5_4_6_7_IRQHandler
    def_irq_handler    DMA5_4_8_9_IRQHandler
    def_irq_handler    DMA5_4_10_11_IRQHandler
    def_irq_handler    DMA5_4_12_13_IRQHandler
    def_irq_handler    DMA5_4_14_15_IRQHandler
    def_irq_handler    DMA5_4_16_17_IRQHandler
    def_irq_handler    DMA5_4_18_19_IRQHandler
    def_irq_handler    DMA5_4_20_21_IRQHandler
    def_irq_handler    DMA5_4_22_23_IRQHandler
    def_irq_handler    DMA5_4_24_25_IRQHandler
    def_irq_handler    DMA5_4_26_27_IRQHandler
    def_irq_handler    DMA5_4_28_29_IRQHandler
    def_irq_handler    DMA5_4_30_31_IRQHandler
    def_irq_handler    RESERVED384_IRQHandler
    def_irq_handler    RESERVED385_IRQHandler
    def_irq_handler    RESERVED386_IRQHandler
    def_irq_handler    RESERVED387_IRQHandler
    def_irq_handler    RESERVED388_IRQHandler
    def_irq_handler    RESERVED389_IRQHandler
    def_irq_handler    CSI1_IRQHandler
    def_irq_handler    CSI2_IRQHandler
    def_irq_handler    ASRC1_IRQHandler
    def_irq_handler    RESERVED393_IRQHandler
    def_irq_handler    RESERVED394_IRQHandler
    def_irq_handler    RESERVED395_IRQHandler
    def_irq_handler    RESERVED396_IRQHandler
    def_irq_handler    RESERVED397_IRQHandler
    def_irq_handler    RESERVED398_IRQHandler
    def_irq_handler    RESERVED399_IRQHandler
    def_irq_handler    ASRC2_IRQHandler
    def_irq_handler    RESERVED401_IRQHandler
    def_irq_handler    RESERVED402_IRQHandler
    def_irq_handler    RESERVED403_IRQHandler
    def_irq_handler    RESERVED404_IRQHandler
    def_irq_handler    RESERVED405_IRQHandler
    def_irq_handler    RESERVED406_IRQHandler
    def_irq_handler    NOC_VPU_IRQHandler
    def_irq_handler    NOC_DISPLAY_IRQHandler
    def_irq_handler    NOC_CAMERA_IRQHandler
    def_irq_handler    NOC_HSIO_IRQHandler
    def_irq_handler    NOC_WAKEUP_IRQHandler
    def_irq_handler    NOC_CENTRAL_IRQHandler
    def_irq_handler    ERM_DISPLAY_IRQHandler
    def_irq_handler    RESERVED414_IRQHandler
    def_irq_handler    SAI6_IRQHandler
    def_irq_handler    XSPI1_0_IRQHandler
    def_irq_handler    XSPI1_1_IRQHandler
    def_irq_handler    XSPI1_2_IRQHandler
    def_irq_handler    XSPI1_3_IRQHandler
    def_irq_handler    XSPI1_4_IRQHandler
    def_irq_handler    RESERVED421_IRQHandler
    def_irq_handler    RESERVED422_IRQHandler
    def_irq_handler    CCM_IRQHandler
    def_irq_handler    MU_D1_IRQHandler
    def_irq_handler    MU_D2_IRQHandler
    def_irq_handler    GPT2_IRQHandler
    def_irq_handler    GPT3_IRQHandler
    def_irq_handler    GPT4_IRQHandler
    def_irq_handler    GPT5_IRQHandler
    def_irq_handler    LPSPI9_IRQHandler

    .end
