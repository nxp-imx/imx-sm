/* ------------------------------------------------------------------------- */
/*  @file:    rom_MIMX95_cm33.s                                              */
/*  @purpose: CMSIS Cortex-M33 Core Device Startup File                      */
/*                                                                           */
/*  @version:                                                                */
/*  @date:                                                                   */
/*  @build:                                                                  */
/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright 2023 NXP                                                        */
/*                                                                           */
/* SPDX-License-Identifier: BSD-3-Clause                                     */
/*****************************************************************************/
/* Version: GCC for ARM Embedded Processors                                  */
/*****************************************************************************/
    .syntax unified
    .arch armv8-m.main

     .section .rom, "ax"
    .align 2
    .globl __rom_vector
__rom_vector:
    .long   0x2003F000                	/* Top of Stack */
    .long   RomReset_Handler            /* Reset Handler */
    .long   RomDefaultISR               /* NMI Handler*/
    .long   RomDefaultISR               /* Hard Fault Handler*/
    .long   RomDefaultISR               /* MPU Fault Handler*/
    .long   RomDefaultISR               /* Bus Fault Handler*/
    .long   RomDefaultISR               /* Usage Fault Handler*/
    .long   RomDefaultISR               /* Secure Fault Handler*/
    .long   RomDefaultISR               /* Reserved*/
    .long   RomDefaultISR               /* Reserved*/
    .long   RomDefaultISR               /* Reserved*/
    .long   RomDefaultISR               /* SVCall Handler*/
    .long   RomDefaultISR               /* Debug Monitor Handler*/
    .long   RomDefaultISR               /* Reserved*/
    .long   RomDefaultISR               /* PendSV Handler*/
    .long   RomDefaultISR               /* SysTick Handler*/

    .thumb_func
    .align 2
    .globl   RomReset_Handler

RomReset_Handler:

    /* Enable SYSCTR */
    .equ SYS_CTR_CONTROL_BASE, 0x44290000U
    .equ SYS_CTR_CONTROL_CNTCR, 0x0U
    .equ SYS_CTR_CONTROL_CNTCR_EN_MASK, 0x1U
    .equ SYS_CTR_CONTROL_CNTCR_HDBG_MASK, 0x2U

    ldr r0, =SYS_CTR_CONTROL_BASE
    ldr r1, =(SYS_CTR_CONTROL_CNTCR_HDBG_MASK | SYS_CTR_CONTROL_CNTCR_EN_MASK)
    str r1, [r0, #SYS_CTR_CONTROL_CNTCR]

    /* Setup ROM handover */
    .equ HANDOVER_BASE, 0x2003DC00U
    .equ HANDOVER_W0, 0xC0FFEE16U       /* Tag */
    .equ HANDOVER_W1, 0x01000002U       /* Size/ver */
    .equ HANDOVER_W2, 0x00000002U       /* Num images */
    .equ HANDOVER_W3, 0x00000000U       /* Flags */
    .equ HANDOVER_W4, 0x00000000U       /* Low address */
    .equ HANDOVER_W5, 0x00000000U       /* High address */
    .equ HANDOVER_W6, 0x00000000U       /* ROM CPU */
    .equ HANDOVER_W7, 0x00000001U       /* SM CPU */
    .equ HANDOVER_W8, 0x20480000U       /* Low address */
    .equ HANDOVER_W9, 0x00000000U       /* High address */
    .equ HANDOVER_W10, 0x00000000U      /* ROM CPU */
    .equ HANDOVER_W11, 0x00000002U      /* SM CPU */
    ldr r0, =HANDOVER_BASE
    ldr r1, =HANDOVER_W0
    str r1, [r0, #0]
    ldr r1, =HANDOVER_W1
    str r1, [r0, #4]
    ldr r1, =HANDOVER_W2
    str r1, [r0, #8]
    ldr r1, =HANDOVER_W3
    str r1, [r0, #12]
    ldr r1, =HANDOVER_W4
    str r1, [r0, #16]
    ldr r1, =HANDOVER_W5
    str r1, [r0, #20]
    ldr r1, =HANDOVER_W6
    str r1, [r0, #24]
    ldr r1, =HANDOVER_W7
    str r1, [r0, #28]
    ldr r1, =HANDOVER_W8
    str r1, [r0, #32]
    ldr r1, =HANDOVER_W9
    str r1, [r0, #36]
    ldr r1, =HANDOVER_W10
    str r1, [r0, #40]
    ldr r1, =HANDOVER_W11
    str r1, [r0, #44]

    /* Setup ROM passover */
    .equ PASSOVER_BASE, 0x2003DE00U
    .equ PASSOVER_W0, 0x0280504fU       /* Ver/size/tag */
    ldr r0, =PASSOVER_BASE
    ldr r1, =PASSOVER_W0
    str r1, [r0, #0]
    ldr r1, =0x0
    str r1, [r0, #4]
    str r1, [r0, #8]
    str r1, [r0, #12]
    str r1, [r0, #16]
    str r1, [r0, #20]
    str r1, [r0, #24]
    str r1, [r0, #28]
    str r1, [r0, #32]
    str r1, [r0, #36]
    str r1, [r0, #40]
    str r1, [r0, #44]
    str r1, [r0, #48]
    str r1, [r0, #52]

    /**** Setup clocking ****/
    .equ SYS_PLL1_BASE, 0x44481000U

    .equ PLL_CTRL_RW, 0x0U
    .equ PLL_CTRL_SET, 0x4U
    .equ PLL_CTRL_CLR, 0x8U
    .equ PLL_SPREAD_SPECTRUM_CLR, 0x38U
    .equ PLL_NUMERATOR_RW, 0x40U
    .equ PLL_DENOMINATOR_RW, 0x50U
    .equ PLL_DIV_RW, 0x60U

    .equ PLL_DFS_CTRL_0_RW, 0x70
    .equ PLL_DFS_CTRL_0_SET, 0x74
    .equ PLL_DFS_CTRL_0_CLR, 0x78
    .equ PLL_DFS_DIV_0_RW, 0x80

    .equ PLL_DFS_CTRL_1_RW, 0x90
    .equ PLL_DFS_CTRL_1_SET, 0x94
    .equ PLL_DFS_CTRL_1_CLR, 0x98
    .equ PLL_DFS_DIV_1_RW, 0xA0

    .equ PLL_DFS_CTRL_2_RW, 0xB0
    .equ PLL_DFS_CTRL_2_SET, 0xB4
    .equ PLL_DFS_CTRL_2_CLR, 0xB8
    .equ PLL_DFS_DIV_2_RW, 0xC0

    .equ PLL_CTRL_CLKMUX_BYPASS_MASK, 0x4U
    .equ PLL_CTRL_CLKMUX_EN_MASK, 0x2U
    .equ PLL_CTRL_POWERUP_MASK, 0x1U
    .equ PLL_SPREAD_SPECTRUM_ENABLE_MASK, 0x8000U
    .equ PLL_NO_OF_DFS_BYPASS_EN_MASK, 0x800000U
    .equ PLL_NO_OF_DFS_CLKOUT_EN_MASK, 0x40000000U
    .equ PLL_NO_OF_DFS_ENABLE_MASK, 0x80000000U

    .equ CCM_BASE, 0x44450000U

    .equ CCM_CLOCK_ROOT2_CONTROL_RW, 0x100U
    .equ CCM_CLOCK_ROOT2_CONTROL_SET, 0x104U
    .equ CCM_CLOCK_ROOT13_CONTROL_RW, 0x680U
    .equ CCM_CLOCK_ROOT13_CONTROL_SET, 0x684U
    .equ CCM_CLOCK_ROOT66_CONTROL_RW, 0x2100U
    .equ CCM_CLOCK_ROOT66_CONTROL_SET, 0x2104U
    .equ CCM_CLOCK_ROOT67_CONTROL_RW, 0x2180U
    .equ CCM_CLOCK_ROOT67_CONTROL_SET, 0x2184U
    .equ CCM_CLOCK_ROOT78_CONTROL_RW, 0x2700U
    .equ CCM_CLOCK_ROOT78_CONTROL_SET, 0x2704U
    .equ CCM_CLOCK_ROOT121_CONTROL_RW, 0x3C80U
    .equ CCM_CLOCK_ROOT121_CONTROL_SET, 0x3C84U

    /**** Setup SYS PLL ****/
    ldr r0, =SYS_PLL1_BASE

    /* Bypass PLL */
    /* pll->CTRL.SET = PLL_CTRL_CLKMUX_BYPASS_MASK; */
    ldr r1, =(PLL_CTRL_CLKMUX_BYPASS_MASK)
    str r1, [r0, #PLL_CTRL_SET]

    /* Disable output and PLL */
    /* pll->CTRL.CLR = PLL_CTRL_CLKMUX_EN_MASK | PLL_CTRL_POWERUP_MASK; */
    ldr r1, =(PLL_CTRL_CLKMUX_EN_MASK | PLL_CTRL_POWERUP_MASK)
    str r1, [r0, #PLL_CTRL_CLR]

    /* Set rdiv, mfi, and odiv */
    /* pll->DIV.RW = PLL_DIV_MFI(mfi) | PLL_DIV_RDIV(0U) | PLL_DIV_ODIV(odiv); */
    ldr r1, =(0x00A60004U)
    str r1, [r0, #PLL_DIV_RW]

    /* Disable spread spectrum modulation */
    /* pll->SPREAD_SPECTRUM.CLR = PLL_SPREAD_SPECTRUM_ENABLE_MASK; */
    ldr r1, =(PLL_SPREAD_SPECTRUM_ENABLE_MASK)
    str r1, [r0, #PLL_SPREAD_SPECTRUM_CLR]

    /* Set mfn and mfd */
    /* pll->NUMERATOR.RW   = PLL_NUMERATOR_MFN(mfn); */
    /* pll->DENOMINATOR.RW = PLL_DENOMINATOR_MFD(CLOCK_PLL_MFD); */
    ldr r1, =(8U)
    str r1, [r0, #PLL_NUMERATOR_RW]
    ldr r1, =(3U)
    str r1, [r0, #PLL_DENOMINATOR_RW]

    /* Power up for locking */
    /* pll->CTRL.SET = PLL_CTRL_POWERUP_MASK; */
    /* while ((pll->PLL_STATUS & PLL_PLL_STATUS_PLL_LOCK_MASK) == 0U) */
    ldr r1, =(PLL_CTRL_POWERUP_MASK)
    str r1, [r0, #PLL_CTRL_SET]

    /* Enable PLL and clean bypass */
    /* pll->CTRL.SET = PLL_CTRL_CLKMUX_EN_MASK; */
    /* pll->CTRL.CLR = PLL_CTRL_CLKMUX_BYPASS_MASK; */
    ldr r1, =(PLL_CTRL_CLKMUX_EN_MASK)
    str r1, [r0, #PLL_CTRL_SET]
    ldr r1, =(PLL_CTRL_CLKMUX_BYPASS_MASK)
    str r1, [r0, #PLL_CTRL_CLR]

    /**** Setput SYS PLL PFDs ****/

    /* Bypass DFS*/
    /* pll->NO_OF_DFS[dfsIdx].DFS_CTRL.SET = PLL_NO_OF_DFS_BYPASS_EN_MASK; */
    ldr r1, =(PLL_NO_OF_DFS_BYPASS_EN_MASK)
    str r1, [r0, #PLL_DFS_CTRL_0_SET]
    str r1, [r0, #PLL_DFS_CTRL_1_SET]
    str r1, [r0, #PLL_DFS_CTRL_2_SET]

    /* Disable output and DFS */
    /* pll->NO_OF_DFS[dfsIdx].DFS_CTRL.CLR = PLL_NO_OF_DFS_CLKOUT_EN_MASK | PLL_NO_OF_DFS_ENABLE_MASK; */
    ldr r1, =(PLL_NO_OF_DFS_CLKOUT_EN_MASK | PLL_NO_OF_DFS_ENABLE_MASK)
    str r1, [r0, #PLL_DFS_CTRL_0_CLR]
    str r1, [r0, #PLL_DFS_CTRL_1_CLR]
    str r1, [r0, #PLL_DFS_CTRL_2_CLR]

    /* Set mfi and mfn */
    /* pll->NO_OF_DFS[dfsIdx].DFS_DIV.RW = PLL_NO_OF_DFS_MFI(mfi) | PLL_NO_OF_DFS_MFN(mfn); */
    ldr r1, =(0x00000400U)
    str r1, [r0, #PLL_DFS_DIV_0_RW]

    ldr r1, =(0x00000500U)
    str r1, [r0, #PLL_DFS_DIV_1_RW]

    ldr r1, =(0x00000600U)
    str r1, [r0, #PLL_DFS_DIV_2_RW]

    /* Enable output and DFS */
    /* pll->NO_OF_DFS[dfsIdx].DFS_CTRL.SET = PLL_NO_OF_DFS_CLKOUT_EN_MASK; */
    ldr r1, =(PLL_NO_OF_DFS_CLKOUT_EN_MASK)
    str r1, [r0, #PLL_DFS_CTRL_0_SET]
    str r1, [r0, #PLL_DFS_CTRL_1_SET]
    str r1, [r0, #PLL_DFS_CTRL_2_SET]

    /* Enable DFS for locking*/
    /* pll->NO_OF_DFS[dfsIdx].DFS_CTRL.SET = PLL_NO_OF_DFS_ENABLE_MASK; */
    /* while (((pll->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK) & (1U << dfsIdx)) == 0U) */
    ldr r1, =(PLL_NO_OF_DFS_ENABLE_MASK)
    str r1, [r0, #PLL_DFS_CTRL_0_SET]
    str r1, [r0, #PLL_DFS_CTRL_1_SET]
    str r1, [r0, #PLL_DFS_CTRL_2_SET]

    /* Clean bypass */
    /* pll->NO_OF_DFS[dfsIdx].DFS_CTRL.CLR = PLL_NO_OF_DFS_BYPASS_EN_MASK; */
    ldr r1, =(PLL_NO_OF_DFS_BYPASS_EN_MASK)
    str r1, [r0, #PLL_DFS_CTRL_0_CLR]
    str r1, [r0, #PLL_DFS_CTRL_1_CLR]
    str r1, [r0, #PLL_DFS_CTRL_2_CLR]

    /* Clean bypass */
    /* pll->NO_OF_DFS[dfsIdx].DFS_CTRL.CLR = PLL_NO_OF_DFS_BYPASS_EN_MASK; */
    ldr r1, =(PLL_NO_OF_DFS_BYPASS_EN_MASK)
    str r1, [r0, #PLL_DFS_CTRL_0_CLR]
    str r1, [r0, #PLL_DFS_CTRL_1_CLR]
    str r1, [r0, #PLL_DFS_CTRL_2_CLR]

    /**** Setup Clock Roots ****/

    /**** Setup M33_CLK_ROOT to 1000 MHz / 3 = 333 MHz ****/
    ldr r0, =(CCM_BASE+CCM_CLOCK_ROOT13_CONTROL_SET)

    /* Update M33_CLK_ROOT divider to /3 */
    ldr r1, =(2U)
    str r1, [r0]

    /* Update M33_CLK_ROOT source to SYSPLL1_PFD0 (1000 MHz) */
    ldr r1, =(1U<<8U)
    str r1, [r0]

    /**** Setup BUS_AON_CLK_ROOT to 400 MHz / 3 = 133 MHz ****/
    ldr r0, =(CCM_BASE+CCM_CLOCK_ROOT2_CONTROL_SET)

    /* Update BUS_AON_CLK_ROOT divider to /3 */
    ldr r1, =(2U)
    str r1, [r0]

    /* Update BUS_AON_CLK_ROOT source to SYSPLL1_PFD1_DIV2 (400 MHz) */
    ldr r1, =(2U<<8U)
    str r1, [r0]

    /**** Setup BUS_WAKEUP_CLK_ROOT to 400 MHz / 3 = 133 MHz ****/
    ldr r0, =(CCM_BASE+CCM_CLOCK_ROOT78_CONTROL_SET)

    /* Update BUS_WAKEUP_CLK_ROOT divider to /3 */
    ldr r1, =(2U)
    str r1, [r0]

    /* Update BUS_WAKEUP_CLK_ROOT source to SYSPLL1_PFD1_DIV2 (400 MHz) */
    ldr r1, =(2U<<8U)
    str r1, [r0]

    /**** Setup WAKEAXI_CLK_ROOT to 800 MHz / 2 = 400 MHz ****/
    ldr r0, =(CCM_BASE+CCM_CLOCK_ROOT121_CONTROL_SET)

    /* Update WAKEAXI_CLK_ROOT divider to /2 */
    ldr r1, =(1U)
    str r1, [r0]

    /* Update WAKEAXI_CLK_ROOT source to SYSPLL1_PFD1 (800 MHz) */
    ldr r1, =(2U<<8U)
    str r1, [r0]

    /**** Setup NOC_CLK_ROOT to 800 MHz ****/
    ldr r0, =(CCM_BASE+CCM_CLOCK_ROOT66_CONTROL_SET)

    /* Update NOC_CLK_ROOT source to SYSPLL1_PFD1 (800 MHz) */
    ldr r1, =(2U<<8U)
    str r1, [r0]

    /**** Setup NOC_APB_CLK_ROOT to 400 MHz / 3 = 133 MHz ****/
    ldr r0, =(CCM_BASE+CCM_CLOCK_ROOT67_CONTROL_SET)

    /* Update NOC_APB_CLK_ROOT divider to /3 */
    ldr r1, =(2U)
    str r1, [r0]

    /* Update NOC_APB_CLK_ROOT source to SYSPLL1_PFD1_DIV2 (400 MHz) */
    ldr r1, =(2U<<8U)
    str r1, [r0]


    /* Load PC and SP */
    ldr r0, =0x1FFC0000
    ldr r13, [r0, #0]
    ldr r1,  [r0, #4]
    bx  r1
    nop
    nop
    nop

    .align  2
    .thumb_func
    .weak RomDefaultISR
    .type RomDefaultISR, %function
RomDefaultISR:
    b   RomDefaultISR
    .size RomDefaultISR, . - RomDefaultISR


    .end
