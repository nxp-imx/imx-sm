/* ------------------------------------------------------------------------- */
/*  @file:    startup_MIMX9494_cm33_core0.s                                  */
/*  @purpose: CMSIS Cortex-M33 Core Device Startup File                      */
/*            MIMX9494_cm33_core0                                            */
/*  @version: 1.0                                                            */
/*  @date:    2023-11-1                                                      */
/*  @build:   b240315                                                        */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright 2025 NXP                                                        */
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
    .long   Reserved24_IRQHandler                           /* CTI trigger outputs from CM7_1 platform*/
    .long   Reserved25_IRQHandler                           /* CTI trigger outputs from CM33_sync platform*/
    .long   CAN1_IRQHandler                                 /* CAN1 interrupt*/
    .long   CAN1_ERROR_IRQHandler                           /* CAN1 error interrupt*/
    .long   GPIO1_INT0_IRQHandler                           /* General Purpose Input/Output 1 interrupt 0*/
    .long   GPIO1_INT1_IRQHandler                           /* General Purpose Input/Output 1 interrupt 1*/
    .long   I3C1_IRQHandler                                 /* Improved Inter-Integrated Circuit 1 interrupt*/
    .long   LPI2C1_IRQHandler                               /* Low Power Inter-Integrated Circuit module 1*/
    .long   LPI2C2_IRQHandler                               /* Low Power Inter-Integrated Circuit module 2*/
    .long   LPIT1_IRQHandler                                /* Low Power Periodic Interrupt Timer 1*/
    .long   LPSPI1_IRQHandler                               /* Low Power Serial Peripheral Interface 1*/
    .long   LPSPI2_IRQHandler                               /* Low Power Serial Peripheral Interface 2*/
    .long   LPTMR1_IRQHandler                               /* Low Power Timer 1*/
    .long   LPUART1_IRQHandler                              /* Low Power UART 1*/
    .long   LPUART2_IRQHandler                              /* Low Power UART 2*/
    .long   Reserved39_IRQHandler                           /* AONMIX ELE MU0 SideA interrupt*/
    .long   Reserved40_IRQHandler                           /* AONMIX ELE MU1 SideA interrupt*/
    .long   Reserved41_IRQHandler                           /* AONMIX ELE MU2 SideA interrupt*/
    .long   Reserved42_IRQHandler                           /* AONMIX ELE MU3 SideA interrupt*/
    .long   Reserved43_IRQHandler                           /* AONMIX ELE MU4 SideA interrupt*/
    .long   Reserved44_IRQHandler                           /* AONMIX ELE MU5 SideA interrupt*/
    .long   Reserved45_IRQHandler                           /* AONMIX ELE MU6 SideA interrupt*/
    .long   Reserved46_IRQHandler                           /* AONMIX ELE MU7 SideA interrupt*/
    .long   Reserved47_IRQHandler                           /* AONMIX ELE MU8 SideA interrupt*/
    .long   V2X_FH_APCH0_IRQHandler                         /* V2X-FH MU APCH0 (APP0) interrupt*/
    .long   V2X_FH_APHSM1_IRQHandler                        /* V2X-FH MU APHSM1 (HSM1) interrupt*/
    .long   TPM1_IRQHandler                                 /* Timer PWM module 1*/
    .long   TPM2_IRQHandler                                 /* Timer PWM module 2*/
    .long   WDOG1_IRQHandler_Shim                           /* Watchdog 1 Interrupt*/
    .long   WDOG2_IRQHandler_Shim                           /* Watchdog 2 Interrupt*/
    .long   SAI1_IRQHandler                                 /* Serial Audio Interface 1*/
    .long   GPT1_IRQHandler                                 /* AONMIX GPT1*/
    .long   CAN2_IRQHandler                                 /* WAKEUPMIX CAN2 interrupt*/
    .long   CAN2_ERROR_IRQHandler                           /* WAKEUPMIX CAN2 error interrupt*/
    .long   CAN3_IRQHandler                                 /* WAKEUPMIX CAN3 interrupt*/
    .long   CAN3_ERROR_IRQHandler                           /* WAKEUPMIX CAN3 error interrupt*/
    .long   CAN4_IRQHandler                                 /* WAKEUPMIX CAN4 interrupt*/
    .long   CAN4_ERROR_IRQHandler                           /* WAKEUPMIX CAN4 error interrupt*/
    .long   CAN5_IRQHandler                                 /* WAKEUPMIX CAN5 interrupt*/
    .long   CAN5_ERROR_IRQHandler                           /* WAKEUPMIX CAN5 error interrupt*/
    .long   FLEXIO1_IRQHandler                              /* WAKEUPMIX Flexible IO 1 interrupt*/
    .long   FLEXIO2_IRQHandler                              /* WAKEUPMIX Flexible IO 2 interrupt*/
    .long   FLEXIO3_IRQHandler                              /* NETCMIX Flexible IO 3 interrupt*/
    .long   FLEXIO4_IRQHandler                              /* NETCMIX Flexible IO 4 interrupt*/
    .long   Reserved68_IRQHandler                           /* Earlier assigned for WAKEUPMIX XSPI1 interrupt*/
    .long   Reserved69_IRQHandler                           /* Earlier assigned for WAKEUPMIX XSPI2 interrupt*/
    .long   GPIO2_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 2 interrupt 0*/
    .long   GPIO2_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 2 interrupt 1*/
    .long   GPIO3_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 3 interrupt 0*/
    .long   GPIO3_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 3 interrupt 1*/
    .long   GPIO4_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 4 interrupt 0*/
    .long   GPIO4_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 4 interrupt 1*/
    .long   GPIO5_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 5 interrupt 0*/
    .long   GPIO5_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 5 interrupt 1*/
    .long   GPIO6_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 6 interrupt 0*/
    .long   GPIO6_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 6 interrupt 1*/
    .long   GPIO7_INT0_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 7 interrupt 0*/
    .long   GPIO7_INT1_IRQHandler                           /* WAKEUPMIX General Purpose Input/Output 7 interrupt 1*/
    .long   I3C2_IRQHandler                                 /* WAKEUPMIX Improved Inter-Integrated Circuit 2 interrupt*/
    .long   LPI2C3_IRQHandler                               /* WAKEUPMIX Low Power Inter-Integrated Circuit module 3*/
    .long   LPI2C4_IRQHandler                               /* WAKEUPMIX Low Power Inter-Integrated Circuit module 4*/
    .long   LPIT2_IRQHandler                                /* WAKEUPMIX Low Power Periodic Interrupt Timer 2*/
    .long   LPIT3_IRQHandler                                /* WAKEUPMIX Low Power Periodic Interrupt Timer 3*/
    .long   LPSPI3_IRQHandler                               /* WAKEUPMIX Low Power Serial Peripheral Interface 3*/
    .long   LPSPI4_IRQHandler                               /* WAKEUPMIX Low Power Serial Peripheral Interface 4*/
    .long   LPTMR2_IRQHandler                               /* WAKEUPMIX Low Power Timer 2*/
    .long   LPUART3_IRQHandler                              /* WAKEUPMIX Low Power UART 3*/
    .long   LPUART4_IRQHandler                              /* WAKEUPMIX Low Power UART 4*/
    .long   LPUART5_IRQHandler                              /* WAKEUPMIX Low Power UART 5*/
    .long   LPUART6_IRQHandler                              /* WAKEUPMIX Low Power UART 6*/
    .long   LPUART7_IRQHandler                              /* WAKEUPMIX Low Power UART 7*/
    .long   LPUART8_IRQHandler                              /* WAKEUPMIX Low Power UART 8*/
    .long   LPUART9_IRQHandler                              /* WAKEUPMIX Low Power UART 9*/
    .long   LPUART10_IRQHandler                             /* WAKEUPMIX Low Power UART 10*/
    .long   LPUART11_IRQHandler                             /* WAKEUPMIX Low Power UART 11*/
    .long   LPUART12_IRQHandler                             /* WAKEUPMIX Low Power UART 12*/
    .long   BBNSM_IRQHandler                                /* BBNSM Non-Secure interrupt*/
    .long   SYSCTR1_IRQHandler                              /* AONMIX System Counter compare interrupt*/
    .long   TPM3_IRQHandler                                 /* WAKEUPMIX Timer PWM module 3*/
    .long   TPM4_IRQHandler                                 /* WAKEUPMIX Timer PWM module 4*/
    .long   TPM5_IRQHandler                                 /* WAKEUPMIX Timer PWM module 5*/
    .long   TPM6_IRQHandler                                 /* WAKEUPMIX Timer PWM module 6*/
    .long   WDOG3_IRQHandler                                /* WAKEUPMIX Watchdog 3 Interrupt*/
    .long   WDOG4_IRQHandler                                /* WAKEUPMIX Watchdog 4 Interrupt*/
    .long   WDOG5_IRQHandler                                /* WAKEUPMIX Watchdog 5 Interrupt*/
    .long   WDOG6_IRQHandler                                /* WAKEUPMIX Watchdog 6 Interrupt*/
    .long   WDOG7_IRQHandler                                /* NETCMIX Watchdog 7 Interrupt*/
    .long   WDOG8_IRQHandler                                /* NETCMIX Watchdog 8 Interrupt*/
    .long   USDHC1_IRQHandler                               /* MEGAMIX uSDHC1 Enhanced SDHC Interrupt Request*/
    .long   USDHC2_IRQHandler                               /* MEGAMIX uSDHC2 Enhanced SDHC Interrupt Request*/
    .long   EDMA2_ERROR_IRQHandler                          /* WAKEUPMIX EDMA2 error interrupt*/
    .long   Reserved115_IRQHandler                          /* JTAGSW DAP MDM-AP SRC reset source*/
    .long   Reserved116_IRQHandler                          /* JTAGC SRC reset source (the JTAGC used for boundary scan, not JTAGC used for password authentication)*/
    .long   SAI2_IRQHandler                                 /* WAKEUPMIX SAI2 interrupt*/
    .long   SAI3_IRQHandler                                 /* WAKEUPMIX SAI3 interrupt*/
    .long   SAI4_IRQHandler                                 /* WAKEUPMIX SAI4 interrupt*/
    .long   LPSPI5_IRQHandler                               /* WAKEUPMIX LPSPI5 interrupt*/
    .long   LPSPI6_IRQHandler                               /* WAKEUPMIX LPSPI6 interrupt*/
    .long   LPSPI7_IRQHandler                               /* WAKEUPMIX LPSPI7 interrupt*/
    .long   LPSPI8_IRQHandler                               /* WAKEUPMIX LPSPI8 interrupt*/
    .long   LPI2C5_IRQHandler                               /* WAKEUPMIX LPI2C5 interrupt*/
    .long   LPI2C6_IRQHandler                               /* WAKEUPMIX LPI2C6 interrupt*/
    .long   LPI2C7_IRQHandler                               /* WAKEUPMIX LPI2C7 interrupt*/
    .long   LPI2C8_IRQHandler                               /* WAKEUPMIX LPI2C8 interrupt*/
    .long   PDM_HWVAD_ERROR_IRQHandler                      /* WAKEUPMIX PDM interrupt(hwvad err)*/
    .long   PDM_HWVAD_EVENT_IRQHandler                      /* WAKEUPMIX PDM interrupt(hwvad event)*/
    .long   PDM_ERROR_IRQHandler                            /* WAKEUPMIX PDM interrupt(mic err)*/
    .long   PDM_IRQHandler                                  /* WAKEUPMIX PDM interrupt(mic event)*/
    .long   USDHC3_IRQHandler                               /* MEGAMIX uSDHC3 Enhanced SDHC Interrupt Request*/
    .long   Reserved133_IRQHandler                          /* WAKEUPMIX ADC1 interrupt(er)*/
    .long   Reserved134_IRQHandler                          /* WAKEUPMIX ADC1 interrupt(wd)*/
    .long   Reserved135_IRQHandler                          /* WAKEUPMIX ADC1 interrupt(eoc)*/
    .long   Reserved136_IRQHandler                          /* I3C1 wakeup irq after double sync*/
    .long   Reserved137_IRQHandler                          /* I3C2 wakeup irq after double sync*/
    .long   MU5_A_IRQHandler                                /* AONMIX MU5 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU6_A_IRQHandler                                /* AONMIX MU6 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU7_A_IRQHandler                                /* AONMIX MU7 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU10_B_IRQHandler                               /* WAKEUPMIX MU10 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU11_B_IRQHandler                               /* WAKEUPMIX MU11 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU12_A_IRQHandler                               /* WAKEUPMIX MU12 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU13_A_IRQHandler                               /* WAKEUPMIX MU13 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU18_A_IRQHandler                               /* WAKEUPMIX MU18 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU18_B_IRQHandler                               /* WAKEUPMIX MU18 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU_E1_A_IRQHandler                              /* NETCMIX MU E1 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_E2_A_IRQHandler                              /* NETCMIX MU E2 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_E3_A_IRQHandler                              /* NETCMIX MU E3 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU_E4_A_IRQHandler                              /* NETCMIX MU E4 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   XSPI_SLV_IRQHandler                             /* WAKEUPMIX XSPI Responder*/
    .long   FCCU_INT0_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 0*/
    .long   FCCU_INT1_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 1*/
    .long   FCCU_INT2_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 2*/
    .long   FCCU_INT3_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 3(new interrupt for CM33_sync)*/
    .long   FCCU_INT4_IRQHandler                            /* AONMIX FCCU Interrupt Reaction 4(new interrupt for CM7_1)*/
    .long   STCU_IRQHandler                                 /* AONMIX STCU Selftest end Interrupt*/
    .long   Reserved158_IRQHandler                          /* XBAR1 interrupt 0 and 1*/
    .long   Reserved159_IRQHandler                          /* XBAR1 interrupt 2 and 3*/
    .long   GPT2_IRQHandler                                 /* WAKEUPMIX GPT2 interrupt*/
    .long   GPT3_IRQHandler                                 /* WAKEUPMIX GPT3 interrupt*/
    .long   GPT4_IRQHandler                                 /* WAKEUPMIX GPT4 interrupt*/
    .long   Reserved163_IRQHandler                          /* Endat2_1 interrupt/Hiperface1-DSL interrupt for safe events logged in EVENT_S register/Endat3 interrupt for background communication*/
    .long   Reserved164_IRQHandler                          /* Hiperface1-DSL interrupt for events logged in EVENT_H or EVENT_L register/Endat3 interrupt*/
    .long   Reserved165_IRQHandler                          /* Endat2_2  interrupt/Hiperface2-DSL interrupt for safe events logged in EVENT_S register/Biss interrupt for start of frame transmission*/
    .long   Reserved166_IRQHandler                          /* Hiperface2-DSL interrupt for events logged in EVENT_H or EVENT_L register/Biss interrupt for end of frame transmission*/
    .long   Reserved167_IRQHandler                          /* Flexpwm1(reload error, fault condition)*/
    .long   Reserved168_IRQHandler                          /* Flexpwm1(capt0, comp0, reload0)*/
    .long   Reserved169_IRQHandler                          /* Flexpwm1(capt1, comp1, reload1)*/
    .long   Reserved170_IRQHandler                          /* Flexpwm1(capt2, comp2, reload2)*/
    .long   Reserved171_IRQHandler                          /* Flexpwm1(capt3, comp3, reload3)*/
    .long   Reserved172_IRQHandler                          /* Flexpwm2(reload error, fault condition)*/
    .long   Reserved173_IRQHandler                          /* Flexpwm2(capt0, comp0, reload0)*/
    .long   Reserved174_IRQHandler                          /* Flexpwm2(capt1, comp1, reload1)*/
    .long   Reserved175_IRQHandler                          /* Flexpwm2(capt2, comp2, reload2)*/
    .long   Reserved176_IRQHandler                          /* Flexpwm2(capt3, comp3, reload3)*/
    .long   Reserved177_IRQHandler                          /* Flexpwm3(reload error, fault condition)*/
    .long   Reserved178_IRQHandler                          /* Flexpwm3(capt0, comp0, reload0)*/
    .long   Reserved179_IRQHandler                          /* Flexpwm3(capt1, comp1, reload1)*/
    .long   Reserved180_IRQHandler                          /* Flexpwm3(capt2, comp2, reload2)*/
    .long   Reserved181_IRQHandler                          /* Flexpwm3(capt3, comp3, reload3)*/
    .long   Reserved182_IRQHandler                          /* Flexpwm4(reload error, fault condition)*/
    .long   Reserved183_IRQHandler                          /* Flexpwm4(capt0, comp0, reload0)*/
    .long   Reserved184_IRQHandler                          /* Flexpwm4(capt1, comp1, reload1)*/
    .long   Reserved185_IRQHandler                          /* Flexpwm4(capt2, comp2, reload2)*/
    .long   Reserved186_IRQHandler                          /* Flexpwm4(capt3, comp3, reload3)*/
    .long   ENC1_IRQHandler                                 /* Quad dec1 interrupt*/
    .long   ENC2_IRQHandler                                 /* Quad dec2 interrupt*/
    .long   ENC3_IRQHandler                                 /* Quad dec3 interrupt*/
    .long   ENC4_IRQHandler                                 /* Quad dec4 interrupt*/
    .long   EWM_IRQHandler                                  /* Ewm out interrupt*/
    .long   Reserved192_IRQHandler                          /* Ethercat interrupt(PDI_OPB)*/
    .long   Reserved193_IRQHandler                          /* Ethercat interrupt(RESET_OUT)*/
    .long   Reserved194_IRQHandler                          /* Ethercat interrupt(SYNC_OUT0)*/
    .long   Reserved195_IRQHandler                          /* Ethercat interrupt(SYNC_OUT1)*/
    .long   USB1_IRQHandler                                 /* USB-1(USB 3.0 Controller) interrupt*/
    .long   USB2_IRQHandler                                 /* USB-2(USB 2.0 Controller) interrupt*/
    .long   SINC1_CH0_IRQHandler                            /* SINC Filter1(sinc filter glue1) Channel 0 interrupt*/
    .long   SINC1_CH1_IRQHandler                            /* SINC Filter1(sinc filter glue1) Channel 1 interrupt*/
    .long   SINC1_CH2_IRQHandler                            /* SINC Filter1(sinc filter glue1) Channel 2 interrupt*/
    .long   SINC1_CH3_IRQHandler                            /* SINC Filter1(sinc filter glue1) Channel 3 interrupt*/
    .long   SINC2_CH0_IRQHandler                            /* SINC Filter2(sinc filter glue2) Channel 0 interrupt*/
    .long   SINC2_CH1_IRQHandler                            /* SINC Filter2(sinc filter glue2) Channel 1 interrupt*/
    .long   SINC2_CH2_IRQHandler                            /* SINC Filter2(sinc filter glue2) Channel 2 interrupt*/
    .long   SINC2_CH3_IRQHandler                            /* SINC Filter2(sinc filter glue2) Channel 3 interrupt*/
    .long   SINC3_CH0_IRQHandler                            /* SINC Filter3(sinc filter glue3 Channel 0 interrupt*/
    .long   SINC3_CH1_IRQHandler                            /* SINC Filter3(sinc filter glue3) Channel 1 interrupt*/
    .long   SINC3_CH2_IRQHandler                            /* SINC Filter3(sinc filter glue3) Channel 2 interrupt*/
    .long   SINC3_CH3_IRQHandler                            /* SINC Filter3(sinc filter glue3) Channel 3 interrupt*/
    .long   SINC4_CH0_IRQHandler                            /* SINC Filter4(sinc filter glue4 Channel 0 interrupt*/
    .long   SINC4_CH1_IRQHandler                            /* SINC Filter4(sinc filter glue4) Channel 1 interrupt*/
    .long   SINC4_CH2_IRQHandler                            /* SINC Filter4(sinc filter glue4) Channel 2 interrupt*/
    .long   SINC4_CH3_IRQHandler                            /* SINC Filter4(sinc filter glue4) Channel 3 interrupt*/
    .long   QTIMER1_IRQHandler                              /* QTIMER1 interrupt*/
    .long   QTIMER2_IRQHandler                              /* QTIMER2 interrupt*/
    .long   QTIMER3_IRQHandler                              /* QTIMER3 interrupt*/
    .long   QTIMER4_IRQHandler                              /* QTIMER4 interrupt*/
    .long   QTIMER5_IRQHandler                              /* QTIMER5 interrupt*/
    .long   QTIMER6_IRQHandler                              /* QTIMER6 interrupt*/
    .long   QTIMER7_IRQHandler                              /* QTIMER7 interrupt*/
    .long   QTIMER8_IRQHandler                              /* QTIMER8 interrupt*/
    .long   EDMA4_ERROR_IRQHandler                          /* EDMA4 error interrupt*/
    .long   Reserved223_IRQHandler                          /* Anamix Gllitch Detector output (da_ip_voltage_glitch_detector_cln16ffc). It's a latch signal. It can be cleared.*/
    .long   Reserved224_IRQHandler                          /* Anamix VDET output (da_ip_vdetect_c16ffc). Detects high threshold on Core supply. It's a latch signal. It can be cleared.*/
    .long   Reserved225_IRQHandler                          /* Anamix VDET output (da_ip_vdetect_c16ffc). Detects Low threshold on Core supply. It's a latch signal. It can be cleared*/
    .long   Reserved226_IRQHandler                          /* LPCG Timeout interrupt generated by CCGR (CCM)*/
    .long   Reserved227_IRQHandler                          /* Reserved227*/
    .long   Reserved228_IRQHandler                          /* Reserved228*/
    .long   Reserved229_IRQHandler                          /* Reserved229*/
    .long   Reserved230_IRQHandler                          /* Reserved230*/
    .long   Reserved231_IRQHandler                          /* Reserved231*/
    .long   Reserved232_IRQHandler                          /* Reserved232*/
    .long   Reserved233_IRQHandler                          /* Reserved233*/
    .long   Reserved234_IRQHandler                          /* Reserved234*/
    .long   Reserved235_IRQHandler                          /* Reserved235*/
    .long   Reserved236_IRQHandler                          /* Reserved236*/
    .long   Reserved237_IRQHandler                          /* Reserved237*/
    .long   Reserved238_IRQHandler                          /* Reserved238*/
    .long   Reserved239_IRQHandler                          /* Reserved239*/
    .long   EDMA2_CH0_31_IRQHandler                         /* WAKEUPMIX EDMA2 channel 0~31 interrupt*/
    .long   EDMA2_CH32_63_IRQHandler                        /* WAKEUPMIX EDMA2 channel 32~63 interrupt*/
    .long   EDMA4_CH0_31_IRQHandler                         /* WAKEUPMIX EDMA4 channel 0~31 interrupt*/
    .long   EDMA4_CH32_63_IRQHandler                        /* WAKEUPMIX EDMA4 channel 32~63 interrupt*/
    .long   EDMA3_CH0_31_IRQHandler                         /* WAKEUPMIX ACP EDMA3 channel 0~31 interrupt*/
    .long   EDMA3_CH32_63_IRQHandler                        /* WAKEUPMIX ACP EDMA3 channel 32~63 interrupt*/
    .long   EDMA1_CH0_IRQHandler                            /* WAKEUPMIX EDMA1 channel 0 interrupt*/
    .long   EDMA1_CH1_IRQHandler                            /* WAKEUPMIX EDMA1 channel 1 interrupt*/
    .long   EDMA1_CH2_IRQHandler                            /* WAKEUPMIX EDMA1 channel 2 interrupt*/
    .long   EDMA1_CH3_IRQHandler                            /* WAKEUPMIX EDMA1 channel 3 interrupt*/
    .long   EDMA1_CH4_IRQHandler                            /* WAKEUPMIX EDMA1 channel 4 interrupt*/
    .long   EDMA1_CH5_IRQHandler                            /* WAKEUPMIX EDMA1 channel 5 interrupt*/
    .long   EDMA1_CH6_IRQHandler                            /* WAKEUPMIX EDMA1 channel 6 interrupt*/
    .long   EDMA1_CH7_IRQHandler                            /* WAKEUPMIX EDMA1 channel 7 interrupt*/
    .long   EDMA1_CH8_IRQHandler                            /* WAKEUPMIX EDMA1 channel 8 interrupt*/
    .long   EDMA1_CH9_IRQHandler                            /* WAKEUPMIX EDMA1 channel 9 interrupt*/
    .long   EDMA1_CH10_IRQHandler                           /* WAKEUPMIX EDMA1 channel 10 interrupt*/
    .long   EDMA1_CH11_IRQHandler                           /* WAKEUPMIX EDMA1 channel 11 interrupt*/
    .long   EDMA1_CH12_IRQHandler                           /* WAKEUPMIX EDMA1 channel 12 interrupt*/
    .long   EDMA1_CH13_IRQHandler                           /* WAKEUPMIX EDMA1 channel 13 interrupt*/
    .long   EDMA1_CH14_IRQHandler                           /* WAKEUPMIX EDMA1 channel 14 interrupt*/
    .long   EDMA1_CH15_IRQHandler                           /* WAKEUPMIX EDMA1 channel 15 interrupt*/
    .long   EDMA1_CH16_IRQHandler                           /* WAKEUPMIX EDMA1 channel 16 interrupt*/
    .long   EDMA1_CH17_IRQHandler                           /* WAKEUPMIX EDMA1 channel 17 interrupt*/
    .long   EDMA1_CH18_IRQHandler                           /* WAKEUPMIX EDMA1 channel 18 interrupt*/
    .long   EDMA1_CH19_IRQHandler                           /* WAKEUPMIX EDMA1 channel 19 interrupt*/
    .long   EDMA1_CH20_IRQHandler                           /* WAKEUPMIX EDMA1 channel 20 interrupt*/
    .long   EDMA1_CH21_IRQHandler                           /* WAKEUPMIX EDMA1 channel 21 interrupt*/
    .long   EDMA1_CH22_IRQHandler                           /* WAKEUPMIX EDMA1 channel 22 interrupt*/
    .long   EDMA1_CH23_IRQHandler                           /* WAKEUPMIX EDMA1 channel 23 interrupt*/
    .long   EDMA1_CH24_IRQHandler                           /* WAKEUPMIX EDMA1 channel 24 interrupt*/
    .long   EDMA1_CH25_IRQHandler                           /* WAKEUPMIX EDMA1 channel 25 interrupt*/
    .long   EDMA1_CH26_IRQHandler                           /* WAKEUPMIX EDMA1 channel 26 interrupt*/
    .long   EDMA1_CH27_IRQHandler                           /* WAKEUPMIX EDMA1 channel 27 interrupt*/
    .long   EDMA1_CH28_IRQHandler                           /* WAKEUPMIX EDMA1 channel 28 interrupt*/
    .long   EDMA1_CH29_IRQHandler                           /* WAKEUPMIX EDMA1 channel 29 interrupt*/
    .long   EDMA1_CH30_IRQHandler                           /* WAKEUPMIX EDMA1 channel 30 interrupt*/
    .long   EDMA1_CH31_IRQHandler                           /* WAKEUPMIX EDMA1 channel 31 interrupt*/
    .long   MU1_A_IRQHandler                                /* AONMIX MU1 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU1_B_IRQHandler                                /* AONMIX MU1 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU2_A_IRQHandler                                /* AONMIX MU2 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU2_B_IRQHandler                                /* AONMIX MU2 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU3_A_IRQHandler                                /* AONMIX MU3 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU3_B_IRQHandler                                /* AONMIX MU3 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU4_A_IRQHandler                                /* AONMIX MU4 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU4_B_IRQHandler                                /* AONMIX MU4 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU5_B_IRQHandler                                /* AONMIX MU5 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU6_B_IRQHandler                                /* AONMIX MU6 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU7_B_IRQHandler                                /* AONMIX MU7 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU8_A_IRQHandler                                /* AONMIX MU8 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU8_B_IRQHandler                                /* AONMIX MU8 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU9_A_IRQHandler                                /* AONMIX MU9 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU9_B_IRQHandler                                /* AONMIX MU9 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU10_A_IRQHandler                               /* WAKEUPMIX MU10 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU11_A_IRQHandler                               /* WAKEUPMIX MU11 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU12_B_IRQHandler                               /* WAKEUPMIX MU12 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU13_B_IRQHandler                               /* WAKEUPMIX MU13 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU14_A_IRQHandler                               /* WAKEUPMIX MU14 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU14_B_IRQHandler                               /* WAKEUPMIX MU14 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU15_A_IRQHandler                               /* WAKEUPMIX MU15 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU15_B_IRQHandler                               /* WAKEUPMIX MU15 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU16_A_IRQHandler                               /* WAKEUPMIX MU16 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU16_B_IRQHandler                               /* WAKEUPMIX MU16 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU17_A_IRQHandler                               /* WAKEUPMIX MU17 Ored of all (tx,rx,gp,core,murip) interrupt to MUA*/
    .long   MU17_B_IRQHandler                               /* WAKEUPMIX MU17 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU_E1_B_IRQHandler                              /* NETCMIX MU E1 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU_E2_B_IRQHandler                              /* NETCMIX MU E2 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU_E3_B_IRQHandler                              /* NETCMIX MU E3 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MU_E4_B_IRQHandler                              /* NETCMIX MU E4 Ored of all (tx,rx,gp,core,murip) interrupt to MUB*/
    .long   MSGINTR1_IRQHandler                             /* MSGINTR Instance 1 Interrupt*/
    .long   MSGINTR2_IRQHandler                             /* MSGINTR Instance 2 Interrupt*/
    .long   MSGINTR3_IRQHandler                             /* MSGINTR Instance 3 Interrupt*/
    .long   MSGINTR4_IRQHandler                             /* MSGINTR Instance 4 Interrupt*/
    .long   MSGINTR5_IRQHandler                             /* MSGINTR Instance 5 Interrupt*/
    .long   MSGINTR6_IRQHandler                             /* MSGINTR Instance 6 Interrupt*/
    .long   MSGINTR7_IRQHandler                             /* MSGINTR Instance 7 Interrupt*/
    .long   MSGINTR8_IRQHandler                             /* MSGINTR Instance 8 Interrupt*/
    .long   V2X_FH_MU_APCH1_IRQHandler                      /* V2X-FH MU APCH1 (APP1) interrupt*/
    .long   V2X_FH_MU_APHSM2_IRQHandler                     /* V2X-FH MU APHSM2 (HSM2) interrupt*/
    .long   ELE_Group1_IRQHandler_Shim                      /* ELE Group 1 reset source if no s500 reference clock is detected.  Output synchronized to 32khz clk. New signal name for i.MX94 is s4v1_fdet0_tclk_err_irq. (Cause Reset)*/
    .long   ELE_Group2_IRQHandler_Shim                      /* ELE Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk the S500 clock. New signal name for i.MX94 is s4v1_fdet2_tclk_err_irq.  (Reset Request in CM33 domain)*/
    .long   ELE_Group3_IRQHandler_Shim                      /* ELE Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk. New signal name for i.MX94 is s4v1_fdet3_tclk_err_irq*/
    .long   Reserved322_IRQHandler                          /* ELE Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to S500 clock domain. New signal name for i.MX94 is s4v1_fdet1_tclk_err_irq*/
    .long   Reserved323_IRQHandler                          /* s500 glue logic IRQ*/
    .long   GPC_SM_REQ_IRQHandler                           /* SRC/GPC Low Power Handshake Gasket interrupt request for system management*/
    .long   EDMA1_ERROR_IRQHandler                          /* AONMIX EDMA1 error interrupt*/
    .long   Reserved326_IRQHandler                          /* AONMIX TRDC transfer error interrupt*/
    .long   Reserved327_IRQHandler                          /* WAKEUPMIX TRDC-MGR1 transfer error interrupt*/
    .long   Reserved328_IRQHandler                          /* MEGAMIX TRDC transfer error interrupt*/
    .long   Reserved329_IRQHandler                          /* NOCMIX TRDC transfer error interrupt*/
    .long   Reserved330_IRQHandler                          /* DISPLAYMIX TRDC transfer error interrupt*/
    .long   Reserved331_IRQHandler                          /* NETCMIX TRDC/NET_M33_Sync Platform transfer error interrupt*/
    .long   Reserved332_IRQHandler                          /* HSIOMIX TRDC transfer error interrupt*/
    .long   Reserved333_IRQHandler                          /* WAKEUPMIX TRDC-MGR2 transfer error interrupt*/
    .long   Reserved334_IRQHandler                          /* AONMIX ERM Single bit corrected ECC error*/
    .long   Reserved335_IRQHandler                          /* M7MIX0 ERM Single bit corrected ECC error*/
    .long   Reserved336_IRQHandler                          /* M7MIX1 ERM Single bit corrected ECC error*/
    .long   Reserved337_IRQHandler                          /* WAKEUPMIX ERM Single bit corrected ECC error*/
    .long   Reserved338_IRQHandler                          /* NPUMIX ERM Single bit corrected ECC error*/
    .long   Reserved339_IRQHandler                          /* NETCMIX ERM Single bit corrected ECC error*/
    .long   Reserved340_IRQHandler                          /* OCRAM ECC multi bit error*/
    .long   Reserved341_IRQHandler                          /* AONMIX MTR Master error interrupt*/
    .long   EDMA3_ERROR_IRQHandler                          /* EDMA3 DMA error interrupt*/
    .long   Reserved343_IRQHandler                          /* AONMIX M33 PS Tag/Data parity error*/
    .long   M33_TCM_ERROR_IRQHandler                        /* AONMIX M33 TCM error interrupt*/
    .long   Reserved345_IRQHandler                          /* M7MIX ECC multi bit error*/
    .long   Reserved346_IRQHandler                          /* NETCMIX M33 PS Tag/Data parity error*/
    .long   M33_SYNC_TCM_ERROR_IRQHandler                   /* NETCMIX M33 TCM error interrupt*/
    .long   ONE_POINT_FIVE_MB_OCRAM_ERROR_IRQHandler        /* NETCMIX 1.5MB OCSRAM Error interrupt*/
    .long   Reserved349_IRQHandler                          /* M7MIX1 ECC Multi-bit error*/
    .long   GIC700_FAULT_IRQHandler                         /* GIC700 Fault(Uncorrectable ECC errors)*/
    .long   M33_MCM_IRQHandler                              /* CM33 MCM interrupt*/
    .long   M33_SYNC_MCM_IRQHandler                         /* CM33_sync MCM interrupt*/
    .long   ONE_POINT_FIVE_MB_SRAM_MCM_IRQHandler           /* NETCMIX 1.5MB SRAM MCM interrupt*/
    .long   M7MIX0_MCM_IRQHandler                           /* M7MIX0 MCM interrupt*/
    .long   M7MIX1_MCM_IRQHandler                           /* M7MIX1 MCM interrupt*/
    .long   OCRAM_ECC_SINGLE_BIT_ERROR_IRQHandler           /* OCRAM ECC single bit error*/
    .long   GIC700_ERROR_IRQHandler                         /* GIC700 Error(Correctable ECC errors)*/
    .long   SFA_IRQHandler                                  /* ANAMIX SFA(Signal Frequency Analyzer) interrupt*/
    .long   TMPSNS_ANA_1_IRQHandler                         /* ANAMIX TempSensor non-secure interrupt from Threshold 1*/
    .long   TMPSNS_ANA_2_IRQHandler                         /* ANAMIX TempSensor non-secure interrupt from Threshold 2*/
    .long   Reserved361_IRQHandler                          /* ANAMIX TempSensor non-secure data ready interrupt*/
    .long   TMPSNS_CORTEXA_1_IRQHandler                     /* CORTEXAMIX TempSensor non-secure interrupt from Threshold 1*/
    .long   TMPSNS_CORTEXA_2_IRQHandler                     /* CORTEXAMIX TempSensor non-secure interrupt from Threshold 2*/
    .long   Reserved364_IRQHandler                          /* CORTEXAMIX TempSensor non-secure data ready interrupt*/
    .long   CM33_0_SYSRESETREQ_IRQHandler                   /* AONMIX CM33 SYSREQRST SRC reset source*/
    .long   CM33_0_LOCKUP_IRQHandler                        /* AONMIX CM33 LOCKUP SRC reset source*/
    .long   CM7_0_SYSRESETREQ_IRQHandler                    /* CM7_0 SYSREQRST SRC reset source*/
    .long   CM7_0_LOCKUP_IRQHandler                         /* CM7_0 LOCKUP SRC reset source*/
    .long   CM33_1_SYSRESETREQ_IRQHandler                   /* NETCMIX CM33_sync SYSREQRST SRC reset source*/
    .long   CM33_1_LOCKUP_IRQHandler                        /* NETCMIX CM33_sync LOCKUP SRC reset source*/
    .long   CM7_1_SYSRESETREQ_IRQHandler                    /* CM7_1 SYSREQRST SRC reset source*/
    .long   CM7_1_LOCKUP_IRQHandler                         /* CM7_1 LOCKUP SRC reset source*/
    .long   SOC_RESET_WO_NETC_IRQHandler                    /* SoC reset without netc interrupt*/
    .long   Reserved374_IRQHandler                          /* NETC iEPRC PCI INT (one per each of two RC-EC, first one)*/
    .long   Reserved375_IRQHandler                          /* NETC iEPRC PCI INT (one per each of two RC-EC, second one)*/
    .long   PCIE1_INTA_IRQHandler                           /* PCIe Controller 1 INTA*/
    .long   PCIE1_INTB_IRQHandler                           /* PCIe Controller 1 INTB*/
    .long   PCIE1_INTC_IRQHandler                           /* PCIe Controller 1 INTC*/
    .long   PCIE1_INTD_IRQHandler                           /* PCIe Controller 1 INTD*/
    .long   Reserved380_IRQHandler                          /* PCIe 1 miscellaneous interrupts/PCIe MSI reception interrupt for RC mode/PCIe Link reset request interrupt*/
    .long   Reserved381_IRQHandler                          /* PCIe Controller 1 EDMA channel interrupt*/
    .long   PCIE2_INTA_IRQHandler                           /* PCIe Controller 2 INTA*/
    .long   PCIE2_INTB_IRQHandler                           /* PCIe Controller 2 INTB*/
    .long   PCIE2_INTC_IRQHandler                           /* PCIe Controller 2 INTC*/
    .long   PCIE2_INTD_IRQHandler                           /* PCIe Controller 2 INTD*/
    .long   Reserved386_IRQHandler                          /* PCIe 2 miscellaneous interrupts/PCIe MSI reception interrupt for RC mode/PCIe Link reset request interrupt*/
    .long   Reserved387_IRQHandler                          /* PCIe Controller 2 EDMA channel interrupt*/
    .long   Reserved388_IRQHandler                          /* NPUMIX Wakeup interrupt from CLKREQ#, WAKEUP#, BEACON_DET*/
    .long   NPUMIX_FUNC_IRQHandler                          /* NPUMIX Functional interrupt*/
    .long   Reserved390_IRQHandler                          /* DRAM controller Performance Monitor Interrupt*/
    .long   Reserved391_IRQHandler                          /* DRAM controller Critical Interrupt*/
    .long   Reserved392_IRQHandler                          /* DRAM Phy Critical Interrupt 0~15*/
    .long   Reserved393_IRQHandler                          /* DISPLAYMIX DCIF: Interrupt output for CPU domain0 (Controlled by common registers group)*/
    .long   Reserved394_IRQHandler                          /* DISPLAYMIX DCIF: Interrupt output for CPU domain1 (Controlled by background layer registers group)*/
    .long   Reserved395_IRQHandler                          /* DISPLAYMIX DCIF: Interrupt output for CPU domain2 (Controlled by foreground layer registers group)*/
    .long   Reserved396_IRQHandler                          /* Reserved*/
    .long   Reserved397_IRQHandler                          /* Reserved*/
    .long   Reserved398_IRQHandler                          /* DISPLAYMIX PXP interrupt 0*/
    .long   Reserved399_IRQHandler                          /* DISPLAYMIX PXP interrupt 1*/
    .long   Reserved400_IRQHandler                          /* V2X-FH MU APSHE (SHE) A_TX/A_RX interrupt*/
    .long   Reserved401_IRQHandler                          /* V2X-FH MU SCU/APDEBUG (DEBUG) B_TX/B_RX interrupt*/
    .long   Reserved402_IRQHandler                          /* USB-1 (USB 3.0) Wake-up Interrupt*/
    .long   Reserved403_IRQHandler                          /* USB-2 (USB 2.0) Wake-up Interrupt*/
    .long   Reserved404_IRQHandler                          /* GIC700 PMU Counter Overflow*/
    .long   Reserved405_IRQHandler                          /* Reserved*/
    .long   Reserved406_IRQHandler                          /* xspi1 all interrupts ORed output for EENV0 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV0/xspi1 arbitration win interrupt for EENV0/xspi1 FlashA error interrupt for EENV0*/
    .long   Reserved407_IRQHandler                          /* xspi1 all interrupts ORed output for EENV1 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV1/xspi1 arbitration lock timeout interrupt for EENV1/xspi1 arbitration win interrupt for EENV1/xspi1 FlashA error interrupt for EENV1*/
    .long   Reserved408_IRQHandler                          /* xspi1 all interrupts ORed output for EENV2 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV2/        xspi1 arbitration win interrupt for EENV2/xspi1 FlashA error interrupt for EENV2*/
    .long   Reserved409_IRQHandler                          /* xspi1 all interrupts ORed output for EENV3 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV3/xspi1 arbitration win interrupt for EENV3/xspi1 FlashA error interrupt for EENV3*/
    .long   Reserved410_IRQHandler                          /* xspi1 all interrupts ORed output for EENV4 (MEENV)/xspi1 arbitration lock timeout interrupt for EENV4/xspi1 arbitration win interrupt for EENV4/xspi1 FlashA error interrupt for EENV4*/
    .long   Reserved411_IRQHandler                          /* xspi2 all interrupts ORed output for EENV0 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV0/xspi2 arbitration lock timeout interrupt for EENV0/xspi2 arbitration win interrupt for EENV0/xspi2 FlashA error interrupt for EENV0*/
    .long   Reserved412_IRQHandler                          /* xspi2 all interrupts ORed output for EENV1 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV1/xspi2 arbitration lock timeout interrupt for EENV1/xspi2 arbitration win interrupt for EENV1/xspi2 FlashA error interrupt for EENV1*/
    .long   Reserved413_IRQHandler                          /* xspi2 all interrupts ORed output for EENV2 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV2/xspi2 arbitration win interrupt for EENV2/xspi2 FlashA error interrupt for EENV2*/
    .long   Reserved414_IRQHandler                          /* xspi2 all interrupts ORed output for EENV3 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV3/xspi2 arbitration win interrupt for EENV3/xspi2 FlashA error interrupt for EENV3*/
    .long   Reserved415_IRQHandler                          /* xspi2 all interrupts ORed output for EENV4 (MEENV)/xspi2 arbitration lock timeout interrupt for EENV4/xspi2 arbitration win interrupt for EENV4/xspi2 FlashA error interrupt for EENV4*/
    .long   Reserved416_IRQHandler                          /* Reserved*/
    .long   Reserved417_IRQHandler                          /* Reserved*/
    .long   Reserved418_IRQHandler                          /* Reserved*/
    .long   Reserved419_IRQHandler                          /* Reserved*/
    .long   Reserved420_IRQHandler                          /* Reserved*/
    .long   Reserved421_IRQHandler                          /* Reserved*/

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
    ldr r1, =0xFD
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

    /* Add stack / heap initialization */
    movs    r0, 0
    ldr     r1, =__HeapBase
    ldr     r2, =__HeapLimit
.heap_init:
    cmp     r1, r2
    itt     lt
    strlt   r0, [r1], #4
    blt     .heap_init

    ldr     r1, =__StackLimit
    ldr     r2, =__StackTop
.stack_init:
    cmp     r1, r2
    itt     lt
    strlt   r0, [r1], #4
    blt     .stack_init
    /*End of stack / heap initialization */

#ifndef __NO_SYSTEM_INIT
    ldr   r0,=SystemInit
    blx   r0
#endif
/*     Loop to copy data from read only memory to RAM. The ranges
 *      of copy from/to are specified by following symbols evaluated in
 *      linker script.
 *      __etext: End of code section, i.e., begin of data sections to copy from.
 *      __data_start__/__data_end__: RAM address range that data should be
 *      __noncachedata_start__/__noncachedata_end__ : none cachable region
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
#ifdef __STARTUP_INITIALIZE_NONCACHEDATA
    ldr    r2, =__noncachedata_start__
    ldr    r3, =__noncachedata_init_end__
#ifdef __PERFORMANCE_IMPLEMENTATION
/* Here are two copies of loop implementations. First one favors performance
 * and the second one favors code size. Default uses the second one.
 * Define macro "__PERFORMANCE_IMPLEMENTATION" in project to use the first one */
    subs    r3, r2
    ble    .LC3
.LC2:
    subs    r3, #4
    ldr    r0, [r1, r3]
    str    r0, [r2, r3]
    bgt    .LC2
.LC3:
#else  /* code size implementation */
.LC2:
    cmp     r2, r3
    ittt    lt
    ldrlt   r0, [r1], #4
    strlt   r0, [r2], #4
    blt    .LC2
#endif
/* zero inited ncache section initialization */
    ldr r3, =__noncachedata_end__
    movs    r0,0
.LC4:
    cmp    r2,r3
    itt    lt
    strlt   r0,[r2],#4
    blt    .LC4
#endif /* __STARTUP_INITIALIZE_NONCACHEDATA */

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
.LC5:
    cmp     r1, r2
    itt    lt
    strlt   r0, [r1], #4
    blt    .LC5
#endif /* __STARTUP_CLEAR_BSS */

    cpsie   i               /* Unmask interrupts */
#ifndef __START
#ifdef __REDLIB__
#define __START __main
#else
#define __START _start
#endif
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
    def_irq_handler    Reserved24_IRQHandler
    def_irq_handler    Reserved25_IRQHandler
    def_irq_handler    CAN1_IRQHandler
    def_irq_handler    CAN1_ERROR_IRQHandler
    def_irq_handler    GPIO1_INT0_IRQHandler
    def_irq_handler    GPIO1_INT1_IRQHandler
    def_irq_handler    I3C1_IRQHandler
    def_irq_handler    LPI2C1_IRQHandler
    def_irq_handler    LPI2C2_IRQHandler
    def_irq_handler    LPIT1_IRQHandler
    def_irq_handler    LPSPI1_IRQHandler
    def_irq_handler    LPSPI2_IRQHandler
    def_irq_handler    LPTMR1_IRQHandler
    def_irq_handler    LPUART1_IRQHandler
    def_irq_handler    LPUART2_IRQHandler
    def_irq_handler    Reserved39_IRQHandler
    def_irq_handler    Reserved40_IRQHandler
    def_irq_handler    Reserved41_IRQHandler
    def_irq_handler    Reserved42_IRQHandler
    def_irq_handler    Reserved43_IRQHandler
    def_irq_handler    Reserved44_IRQHandler
    def_irq_handler    Reserved45_IRQHandler
    def_irq_handler    Reserved46_IRQHandler
    def_irq_handler    Reserved47_IRQHandler
    def_irq_handler    V2X_FH_APCH0_IRQHandler
    def_irq_handler    V2X_FH_APHSM1_IRQHandler
    def_irq_handler    TPM1_IRQHandler
    def_irq_handler    TPM2_IRQHandler
    def_irq_handler    WDOG1_IRQHandler
    def_irq_handler    WDOG2_IRQHandler
    def_irq_handler    SAI1_IRQHandler
    def_irq_handler    GPT1_IRQHandler
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
    def_irq_handler    FLEXIO3_IRQHandler
    def_irq_handler    FLEXIO4_IRQHandler
    def_irq_handler    Reserved68_IRQHandler
    def_irq_handler    Reserved69_IRQHandler
    def_irq_handler    GPIO2_INT0_IRQHandler
    def_irq_handler    GPIO2_INT1_IRQHandler
    def_irq_handler    GPIO3_INT0_IRQHandler
    def_irq_handler    GPIO3_INT1_IRQHandler
    def_irq_handler    GPIO4_INT0_IRQHandler
    def_irq_handler    GPIO4_INT1_IRQHandler
    def_irq_handler    GPIO5_INT0_IRQHandler
    def_irq_handler    GPIO5_INT1_IRQHandler
    def_irq_handler    GPIO6_INT0_IRQHandler
    def_irq_handler    GPIO6_INT1_IRQHandler
    def_irq_handler    GPIO7_INT0_IRQHandler
    def_irq_handler    GPIO7_INT1_IRQHandler
    def_irq_handler    I3C2_IRQHandler
    def_irq_handler    LPI2C3_IRQHandler
    def_irq_handler    LPI2C4_IRQHandler
    def_irq_handler    LPIT2_IRQHandler
    def_irq_handler    LPIT3_IRQHandler
    def_irq_handler    LPSPI3_IRQHandler
    def_irq_handler    LPSPI4_IRQHandler
    def_irq_handler    LPTMR2_IRQHandler
    def_irq_handler    LPUART3_IRQHandler
    def_irq_handler    LPUART4_IRQHandler
    def_irq_handler    LPUART5_IRQHandler
    def_irq_handler    LPUART6_IRQHandler
    def_irq_handler    LPUART7_IRQHandler
    def_irq_handler    LPUART8_IRQHandler
    def_irq_handler    LPUART9_IRQHandler
    def_irq_handler    LPUART10_IRQHandler
    def_irq_handler    LPUART11_IRQHandler
    def_irq_handler    LPUART12_IRQHandler
    def_irq_handler    BBNSM_IRQHandler
    def_irq_handler    SYSCTR1_IRQHandler
    def_irq_handler    TPM3_IRQHandler
    def_irq_handler    TPM4_IRQHandler
    def_irq_handler    TPM5_IRQHandler
    def_irq_handler    TPM6_IRQHandler
    def_irq_handler    WDOG3_IRQHandler
    def_irq_handler    WDOG4_IRQHandler
    def_irq_handler    WDOG5_IRQHandler
    def_irq_handler    WDOG6_IRQHandler
    def_irq_handler    WDOG7_IRQHandler
    def_irq_handler    WDOG8_IRQHandler
    def_irq_handler    USDHC1_IRQHandler
    def_irq_handler    USDHC2_IRQHandler
    def_irq_handler    EDMA2_ERROR_IRQHandler
    def_irq_handler    Reserved115_IRQHandler
    def_irq_handler    Reserved116_IRQHandler
    def_irq_handler    SAI2_IRQHandler
    def_irq_handler    SAI3_IRQHandler
    def_irq_handler    SAI4_IRQHandler
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
    def_irq_handler    PDM_IRQHandler
    def_irq_handler    USDHC3_IRQHandler
    def_irq_handler    Reserved133_IRQHandler
    def_irq_handler    Reserved134_IRQHandler
    def_irq_handler    Reserved135_IRQHandler
    def_irq_handler    Reserved136_IRQHandler
    def_irq_handler    Reserved137_IRQHandler
    def_irq_handler    MU5_A_IRQHandler
    def_irq_handler    MU6_A_IRQHandler
    def_irq_handler    MU7_A_IRQHandler
    def_irq_handler    MU10_B_IRQHandler
    def_irq_handler    MU11_B_IRQHandler
    def_irq_handler    MU12_A_IRQHandler
    def_irq_handler    MU13_A_IRQHandler
    def_irq_handler    MU18_A_IRQHandler
    def_irq_handler    MU18_B_IRQHandler
    def_irq_handler    MU_E1_A_IRQHandler
    def_irq_handler    MU_E2_A_IRQHandler
    def_irq_handler    MU_E3_A_IRQHandler
    def_irq_handler    MU_E4_A_IRQHandler
    def_irq_handler    XSPI_SLV_IRQHandler
    def_irq_handler    FCCU_INT0_IRQHandler
    def_irq_handler    FCCU_INT1_IRQHandler
    def_irq_handler    FCCU_INT2_IRQHandler
    def_irq_handler    FCCU_INT3_IRQHandler
    def_irq_handler    FCCU_INT4_IRQHandler
    def_irq_handler    STCU_IRQHandler
    def_irq_handler    Reserved158_IRQHandler
    def_irq_handler    Reserved159_IRQHandler
    def_irq_handler    GPT2_IRQHandler
    def_irq_handler    GPT3_IRQHandler
    def_irq_handler    GPT4_IRQHandler
    def_irq_handler    Reserved163_IRQHandler
    def_irq_handler    Reserved164_IRQHandler
    def_irq_handler    Reserved165_IRQHandler
    def_irq_handler    Reserved166_IRQHandler
    def_irq_handler    Reserved167_IRQHandler
    def_irq_handler    Reserved168_IRQHandler
    def_irq_handler    Reserved169_IRQHandler
    def_irq_handler    Reserved170_IRQHandler
    def_irq_handler    Reserved171_IRQHandler
    def_irq_handler    Reserved172_IRQHandler
    def_irq_handler    Reserved173_IRQHandler
    def_irq_handler    Reserved174_IRQHandler
    def_irq_handler    Reserved175_IRQHandler
    def_irq_handler    Reserved176_IRQHandler
    def_irq_handler    Reserved177_IRQHandler
    def_irq_handler    Reserved178_IRQHandler
    def_irq_handler    Reserved179_IRQHandler
    def_irq_handler    Reserved180_IRQHandler
    def_irq_handler    Reserved181_IRQHandler
    def_irq_handler    Reserved182_IRQHandler
    def_irq_handler    Reserved183_IRQHandler
    def_irq_handler    Reserved184_IRQHandler
    def_irq_handler    Reserved185_IRQHandler
    def_irq_handler    Reserved186_IRQHandler
    def_irq_handler    ENC1_IRQHandler
    def_irq_handler    ENC2_IRQHandler
    def_irq_handler    ENC3_IRQHandler
    def_irq_handler    ENC4_IRQHandler
    def_irq_handler    EWM_IRQHandler
    def_irq_handler    Reserved192_IRQHandler
    def_irq_handler    Reserved193_IRQHandler
    def_irq_handler    Reserved194_IRQHandler
    def_irq_handler    Reserved195_IRQHandler
    def_irq_handler    USB1_IRQHandler
    def_irq_handler    USB2_IRQHandler
    def_irq_handler    SINC1_CH0_IRQHandler
    def_irq_handler    SINC1_CH1_IRQHandler
    def_irq_handler    SINC1_CH2_IRQHandler
    def_irq_handler    SINC1_CH3_IRQHandler
    def_irq_handler    SINC2_CH0_IRQHandler
    def_irq_handler    SINC2_CH1_IRQHandler
    def_irq_handler    SINC2_CH2_IRQHandler
    def_irq_handler    SINC2_CH3_IRQHandler
    def_irq_handler    SINC3_CH0_IRQHandler
    def_irq_handler    SINC3_CH1_IRQHandler
    def_irq_handler    SINC3_CH2_IRQHandler
    def_irq_handler    SINC3_CH3_IRQHandler
    def_irq_handler    SINC4_CH0_IRQHandler
    def_irq_handler    SINC4_CH1_IRQHandler
    def_irq_handler    SINC4_CH2_IRQHandler
    def_irq_handler    SINC4_CH3_IRQHandler
    def_irq_handler    QTIMER1_IRQHandler
    def_irq_handler    QTIMER2_IRQHandler
    def_irq_handler    QTIMER3_IRQHandler
    def_irq_handler    QTIMER4_IRQHandler
    def_irq_handler    QTIMER5_IRQHandler
    def_irq_handler    QTIMER6_IRQHandler
    def_irq_handler    QTIMER7_IRQHandler
    def_irq_handler    QTIMER8_IRQHandler
    def_irq_handler    EDMA4_ERROR_IRQHandler
    def_irq_handler    Reserved223_IRQHandler
    def_irq_handler    Reserved224_IRQHandler
    def_irq_handler    Reserved225_IRQHandler
    def_irq_handler    Reserved226_IRQHandler
    def_irq_handler    Reserved227_IRQHandler
    def_irq_handler    Reserved228_IRQHandler
    def_irq_handler    Reserved229_IRQHandler
    def_irq_handler    Reserved230_IRQHandler
    def_irq_handler    Reserved231_IRQHandler
    def_irq_handler    Reserved232_IRQHandler
    def_irq_handler    Reserved233_IRQHandler
    def_irq_handler    Reserved234_IRQHandler
    def_irq_handler    Reserved235_IRQHandler
    def_irq_handler    Reserved236_IRQHandler
    def_irq_handler    Reserved237_IRQHandler
    def_irq_handler    Reserved238_IRQHandler
    def_irq_handler    Reserved239_IRQHandler
    def_irq_handler    EDMA2_CH0_31_IRQHandler
    def_irq_handler    EDMA2_CH32_63_IRQHandler
    def_irq_handler    EDMA4_CH0_31_IRQHandler
    def_irq_handler    EDMA4_CH32_63_IRQHandler
    def_irq_handler    EDMA3_CH0_31_IRQHandler
    def_irq_handler    EDMA3_CH32_63_IRQHandler
    def_irq_handler    EDMA1_CH0_IRQHandler
    def_irq_handler    EDMA1_CH1_IRQHandler
    def_irq_handler    EDMA1_CH2_IRQHandler
    def_irq_handler    EDMA1_CH3_IRQHandler
    def_irq_handler    EDMA1_CH4_IRQHandler
    def_irq_handler    EDMA1_CH5_IRQHandler
    def_irq_handler    EDMA1_CH6_IRQHandler
    def_irq_handler    EDMA1_CH7_IRQHandler
    def_irq_handler    EDMA1_CH8_IRQHandler
    def_irq_handler    EDMA1_CH9_IRQHandler
    def_irq_handler    EDMA1_CH10_IRQHandler
    def_irq_handler    EDMA1_CH11_IRQHandler
    def_irq_handler    EDMA1_CH12_IRQHandler
    def_irq_handler    EDMA1_CH13_IRQHandler
    def_irq_handler    EDMA1_CH14_IRQHandler
    def_irq_handler    EDMA1_CH15_IRQHandler
    def_irq_handler    EDMA1_CH16_IRQHandler
    def_irq_handler    EDMA1_CH17_IRQHandler
    def_irq_handler    EDMA1_CH18_IRQHandler
    def_irq_handler    EDMA1_CH19_IRQHandler
    def_irq_handler    EDMA1_CH20_IRQHandler
    def_irq_handler    EDMA1_CH21_IRQHandler
    def_irq_handler    EDMA1_CH22_IRQHandler
    def_irq_handler    EDMA1_CH23_IRQHandler
    def_irq_handler    EDMA1_CH24_IRQHandler
    def_irq_handler    EDMA1_CH25_IRQHandler
    def_irq_handler    EDMA1_CH26_IRQHandler
    def_irq_handler    EDMA1_CH27_IRQHandler
    def_irq_handler    EDMA1_CH28_IRQHandler
    def_irq_handler    EDMA1_CH29_IRQHandler
    def_irq_handler    EDMA1_CH30_IRQHandler
    def_irq_handler    EDMA1_CH31_IRQHandler
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
    def_irq_handler    MU7_B_IRQHandler
    def_irq_handler    MU8_A_IRQHandler
    def_irq_handler    MU8_B_IRQHandler
    def_irq_handler    MU9_A_IRQHandler
    def_irq_handler    MU9_B_IRQHandler
    def_irq_handler    MU10_A_IRQHandler
    def_irq_handler    MU11_A_IRQHandler
    def_irq_handler    MU12_B_IRQHandler
    def_irq_handler    MU13_B_IRQHandler
    def_irq_handler    MU14_A_IRQHandler
    def_irq_handler    MU14_B_IRQHandler
    def_irq_handler    MU15_A_IRQHandler
    def_irq_handler    MU15_B_IRQHandler
    def_irq_handler    MU16_A_IRQHandler
    def_irq_handler    MU16_B_IRQHandler
    def_irq_handler    MU17_A_IRQHandler
    def_irq_handler    MU17_B_IRQHandler
    def_irq_handler    MU_E1_B_IRQHandler
    def_irq_handler    MU_E2_B_IRQHandler
    def_irq_handler    MU_E3_B_IRQHandler
    def_irq_handler    MU_E4_B_IRQHandler
    def_irq_handler    MSGINTR1_IRQHandler
    def_irq_handler    MSGINTR2_IRQHandler
    def_irq_handler    MSGINTR3_IRQHandler
    def_irq_handler    MSGINTR4_IRQHandler
    def_irq_handler    MSGINTR5_IRQHandler
    def_irq_handler    MSGINTR6_IRQHandler
    def_irq_handler    MSGINTR7_IRQHandler
    def_irq_handler    MSGINTR8_IRQHandler
    def_irq_handler    V2X_FH_MU_APCH1_IRQHandler
    def_irq_handler    V2X_FH_MU_APHSM2_IRQHandler
    def_irq_handler    ELE_Group1_IRQHandler
    def_irq_handler    ELE_Group2_IRQHandler
    def_irq_handler    ELE_Group3_IRQHandler
    def_irq_handler    Reserved322_IRQHandler
    def_irq_handler    Reserved323_IRQHandler
    def_irq_handler    GPC_SM_REQ_IRQHandler
    def_irq_handler    EDMA1_ERROR_IRQHandler
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
    def_irq_handler    EDMA3_ERROR_IRQHandler
    def_irq_handler    Reserved343_IRQHandler
    def_irq_handler    M33_TCM_ERROR_IRQHandler
    def_irq_handler    Reserved345_IRQHandler
    def_irq_handler    Reserved346_IRQHandler
    def_irq_handler    M33_SYNC_TCM_ERROR_IRQHandler
    def_irq_handler    ONE_POINT_FIVE_MB_OCRAM_ERROR_IRQHandler
    def_irq_handler    Reserved349_IRQHandler
    def_irq_handler    GIC700_FAULT_IRQHandler
    def_irq_handler    M33_MCM_IRQHandler
    def_irq_handler    M33_SYNC_MCM_IRQHandler
    def_irq_handler    ONE_POINT_FIVE_MB_SRAM_MCM_IRQHandler
    def_irq_handler    M7MIX0_MCM_IRQHandler
    def_irq_handler    M7MIX1_MCM_IRQHandler
    def_irq_handler    OCRAM_ECC_SINGLE_BIT_ERROR_IRQHandler
    def_irq_handler    GIC700_ERROR_IRQHandler
    def_irq_handler    SFA_IRQHandler
    def_irq_handler    TMPSNS_ANA_1_IRQHandler
    def_irq_handler    TMPSNS_ANA_2_IRQHandler
    def_irq_handler    Reserved361_IRQHandler
    def_irq_handler    TMPSNS_CORTEXA_1_IRQHandler
    def_irq_handler    TMPSNS_CORTEXA_2_IRQHandler
    def_irq_handler    Reserved364_IRQHandler
    def_irq_handler    CM33_0_SYSRESETREQ_IRQHandler
    def_irq_handler    CM33_0_LOCKUP_IRQHandler
    def_irq_handler    CM7_0_SYSRESETREQ_IRQHandler
    def_irq_handler    CM7_0_LOCKUP_IRQHandler
    def_irq_handler    CM33_1_SYSRESETREQ_IRQHandler
    def_irq_handler    CM33_1_LOCKUP_IRQHandler
    def_irq_handler    CM7_1_SYSRESETREQ_IRQHandler
    def_irq_handler    CM7_1_LOCKUP_IRQHandler
    def_irq_handler    SOC_RESET_WO_NETC_IRQHandler
    def_irq_handler    Reserved374_IRQHandler
    def_irq_handler    Reserved375_IRQHandler
    def_irq_handler    PCIE1_INTA_IRQHandler
    def_irq_handler    PCIE1_INTB_IRQHandler
    def_irq_handler    PCIE1_INTC_IRQHandler
    def_irq_handler    PCIE1_INTD_IRQHandler
    def_irq_handler    Reserved380_IRQHandler
    def_irq_handler    Reserved381_IRQHandler
    def_irq_handler    PCIE2_INTA_IRQHandler
    def_irq_handler    PCIE2_INTB_IRQHandler
    def_irq_handler    PCIE2_INTC_IRQHandler
    def_irq_handler    PCIE2_INTD_IRQHandler
    def_irq_handler    Reserved386_IRQHandler
    def_irq_handler    Reserved387_IRQHandler
    def_irq_handler    Reserved388_IRQHandler
    def_irq_handler    NPUMIX_FUNC_IRQHandler
    def_irq_handler    Reserved390_IRQHandler
    def_irq_handler    Reserved391_IRQHandler
    def_irq_handler    Reserved392_IRQHandler
    def_irq_handler    Reserved393_IRQHandler
    def_irq_handler    Reserved394_IRQHandler
    def_irq_handler    Reserved395_IRQHandler
    def_irq_handler    Reserved396_IRQHandler
    def_irq_handler    Reserved397_IRQHandler
    def_irq_handler    Reserved398_IRQHandler
    def_irq_handler    Reserved399_IRQHandler
    def_irq_handler    Reserved400_IRQHandler
    def_irq_handler    Reserved401_IRQHandler
    def_irq_handler    Reserved402_IRQHandler
    def_irq_handler    Reserved403_IRQHandler
    def_irq_handler    Reserved404_IRQHandler
    def_irq_handler    Reserved405_IRQHandler
    def_irq_handler    Reserved406_IRQHandler
    def_irq_handler    Reserved407_IRQHandler
    def_irq_handler    Reserved408_IRQHandler
    def_irq_handler    Reserved409_IRQHandler
    def_irq_handler    Reserved410_IRQHandler
    def_irq_handler    Reserved411_IRQHandler
    def_irq_handler    Reserved412_IRQHandler
    def_irq_handler    Reserved413_IRQHandler
    def_irq_handler    Reserved414_IRQHandler
    def_irq_handler    Reserved415_IRQHandler
    def_irq_handler    Reserved416_IRQHandler
    def_irq_handler    Reserved417_IRQHandler
    def_irq_handler    Reserved418_IRQHandler
    def_irq_handler    Reserved419_IRQHandler
    def_irq_handler    Reserved420_IRQHandler
    def_irq_handler    Reserved421_IRQHandler

    .end
