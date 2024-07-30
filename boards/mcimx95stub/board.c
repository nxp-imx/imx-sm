/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sm.h"
#include "board.h"
#include "fsl_lpuart.h"
#include "fsl_ccm.h"
#include "fsl_clock.h"
#include "fsl_bbnsm.h"
#include "fsl_reset.h"
#include "fsl_sysctr.h"
#include "fsl_systick.h"
#include "fsl_wdog32.h"
#include "fsl_cache.h"
#include "fsl_iomuxc.h"
#include "fsl_fro.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* External board-level clock rates */
#define BOARD_EXT_CLK_RATE          25000000UL  /* 25MHz */

/* ADC clck rate */
#define BOARD_ADC_CLK_RATE          80000000UL  /* 80MHz */

/* SM SysTick parameters */
#define BOARD_SYSTICK_CLKSRC    0U                      /* 0 = external ref  */
#define BOARD_SYSTICK_CLK_ROOT  CLOCK_ROOT_M33SYSTICK   /* Dedicated CCM root */

/* SM WDOG */
#define BOARD_WDOG_BASE_PTR         WDOG2
#define BOARD_WDOG_IRQn             WDOG2_IRQn
#define BOARD_WDOG_CLK_SRC          kWDOG32_ClockSource1  /* lpo_clk @ 32K */
#define BOARD_WDOG_TIMEOUT          0xFFFFU  /* 65535 ticks @ 32K = 2 sec */
#define BOARD_WDOG_SRMASK           (1UL << RST_REASON_WDOG2)
#define BOARD_WDOG_ANY_INIT         ~(BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_MASK)
#define BOARD_WDOG_ANY_MASK         BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_MASK
#define BOARD_WDOG_IPG_DEBUG        BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_WDOG2_MASK

/* Board UART */
#ifdef INC_LIBC
#define BOARD_UART                  BOARD_DEBUG_UART_INSTANCE
#else
#define BOARD_UART                  0U
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
static wdog32_config_t s_wdogConfig;

/* Debug UART base pointer list */
static LPUART_Type *const s_uartBases[] = LPUART_BASE_PTRS;

/* Debug UART base pointer list */
static IRQn_Type const s_uartIrqs[] = LPUART_RX_TX_IRQS;

/* Debug UART clock list */
static uint32_t const s_uartClks[] =
{
    0U,
    CLOCK_ROOT_LPUART1,
    CLOCK_ROOT_LPUART2,
    CLOCK_ROOT_LPUART3,
    CLOCK_ROOT_LPUART4,
    CLOCK_ROOT_LPUART5,
    CLOCK_ROOT_LPUART6,
    CLOCK_ROOT_LPUART7,
    CLOCK_ROOT_LPUART8
};

/* Debug UART peripheral LPI list */
static uint32_t const s_uartPerLpi[] =
{
    0U,
    CPU_PER_LPI_IDX_LPUART1,
    CPU_PER_LPI_IDX_LPUART2,
    CPU_PER_LPI_IDX_LPUART3,
    CPU_PER_LPI_IDX_LPUART4,
    CPU_PER_LPI_IDX_LPUART5,
    CPU_PER_LPI_IDX_LPUART6,
    CPU_PER_LPI_IDX_LPUART7,
    CPU_PER_LPI_IDX_LPUART8
};

/* Debug UART configuration info */
static board_uart_config_t const s_uartConfig =
{
    .base = s_uartBases[BOARD_UART],
    .irq = s_uartIrqs[BOARD_UART],
    .clockId = s_uartClks[BOARD_UART],
    .perLpiId = s_uartPerLpi[BOARD_UART],
    .baud = BOARD_DEBUG_UART_BAUDRATE,
    .inst = BOARD_UART
};

/*******************************************************************************
 * Code
 ******************************************************************************/

/*--------------------------------------------------------------------------*/
/* Configure CM33 MPU and XCACHE controller                                 */
/*--------------------------------------------------------------------------*/
void BOARD_ConfigMPU(void)
{
    uint8_t attr;

    /* Disable code cache(ICache) and system cache(DCache) */
    XCACHE_DisableCache(LPCAC_PC);
    XCACHE_DisableCache(LPCAC_PS);

    /* NOTE: All TCRAM is non-cacheable regardless of MPU setting. */

    /*
     * default cache policy(default memory access behavior) after enable
     * mpu on cortex-m33(according to RM of cortex-m33):
     * 0x00000000-0x1FFFFFFF Normal memory, Non-shareable, Write-Through,
     *                       not Write Allocate
     * 0x20000000-0x3FFFFFFF Normal memory, Non-shareable, Write-Back,
     *                       Write Allocate
     * 0x40000000-0x5FFFFFFF Device, Shareable
     * 0x60000000-0x7FFFFFFF Normal memory, Non-shareable, Write-Back,
     *                       Write Allocate
     * 0x80000000-0x9FFFFFFF Normal memory, Non-shareable, Write-Through,
     *                       not Write Allocate
     * 0xA0000000-0xDFFFFFFF Device, Shareable
     * 0xE0000000-0xE003FFFF Device, Shareable
     * 0xE0040000-0xE0043FFF Device, Shareable
     * 0xE0044000-0xE00EFFFF Device, Shareable
     * 0xF0000000-0xFFFFFFFF Device, Shareable
     */
    /* Disable MPU */
    ARM_MPU_Disable();

    /* Attr0: Device-nGnRnE */
    // coverity[misra_c_2012_rule_14_3_violation:FALSE]
    ARM_MPU_SetMemAttr(0U, ARM_MPU_ATTR(ARM_MPU_ATTR_DEVICE,
        ARM_MPU_ATTR_DEVICE));

    /* Attr1: Normal memory, Outer non-cacheable, Inner non-cacheable */
    // coverity[misra_c_2012_rule_14_3_violation:FALSE]
    ARM_MPU_SetMemAttr(1U, ARM_MPU_ATTR(ARM_MPU_ATTR_NON_CACHEABLE,
        ARM_MPU_ATTR_NON_CACHEABLE));

    /* Attr2: Normal memory, Inner write-through transient, read allocate.
     * Inner write-through transient, read allocate
     */
    attr = ARM_MPU_ATTR_MEMORY_(0U, 0U, 1U, 0U);
    ARM_MPU_SetMemAttr(2U, ARM_MPU_ATTR(attr, attr));

    /* Attr3: Normal memory, Outer write-back transient, read/write allocate.
     * Inner write-back transient, read/write
     * allocate */
    attr = ARM_MPU_ATTR_MEMORY_(0U, 1U, 1U, 1U);
    ARM_MPU_SetMemAttr(3U, ARM_MPU_ATTR(attr, attr));

    /*
     * Change macro definitions as follows when choose cache policy
     * as non-cacheable:
     * #define DDR_NONCACHEABLE (1U)
     * #define DDR_WRITE_THROUGH (0U)
     * #define DDR_WRITE_BACK (0U)
     *
     *
     * Change macro definitions as follows when choose cache policy
     * as Write-Through:
     * #define DDR_NONCACHEABLE (0U)
     * #define DDR_WRITE_THROUGH (1U)
     * #define DDR_WRITE_BACK (0U)
     *
     *
     * Change macro definitions as follows when choose cache policy
     * as Write-Back:
     * #define DDR_NONCACHEABLE (0U)
     * #define DDR_WRITE_THROUGH (0U)
     * #define DDR_WRITE_BACK (1U)
     */
#define DDR_NONCACHEABLE  (1U)
#define DDR_WRITE_THROUGH (0U)
#define DDR_WRITE_BACK    (0U)
#if DDR_NONCACHEABLE
    /* NOTE: DDR is used as shared memory for A/M core communication,
     * set it to non-cacheable. */
    /* Region 0: [0x80000000, 0xDFFFFFFF](DRAM), outer shareable,
     * read/write, any privileged, executable. Attr 1 (non-cacheable). */
    ARM_MPU_SetRegion(0U, ARM_MPU_RBAR(0x80000000U, ARM_MPU_SH_OUTER, 0U,
        1U, 0U), ARM_MPU_RLAR(0xDFFFFFFFU, 1U));
#elif DDR_WRITE_THROUGH
    /* Region 0: [0x80000000, 0xDFFFFFFF](DRAM), outer shareable, read/write,
     * any privileged, executable. Attr 2
     * (Normal memory, Inner write-through transient, read allocate. Inner
     * write-through transient, read allocate). */
    ARM_MPU_SetRegion(0U, ARM_MPU_RBAR(0x80000000U, ARM_MPU_SH_OUTER, 0U,
        1U, 0U), ARM_MPU_RLAR(0xDFFFFFFFU, 2U));
#elif DDR_WRITE_BACK
    /* Region 0: [0x80000000, 0xDFFFFFFF](DRAM), outer shareable, read/write,
     * any privileged, executable. Attr 3
     * (Normal memory, Outer write-back transient, read/write allocate. Inner
     * write-back transient, read/write allocate). */
    ARM_MPU_SetRegion(0U, ARM_MPU_RBAR(0x80000000U, ARM_MPU_SH_OUTER, 0U,
        1U, 0U), ARM_MPU_RLAR(0xDFFFFFFFU, 3U));
#endif

#define OCRAM_NONCACHEABLE  (1U)
#define OCRAM_WRITE_THROUGH (0U)
#define OCRAM_WRITE_BACK    (0U)
#if OCRAM_NONCACHEABLE
    /* Region 1: [0x20480000, 0x2051FFFF](OCRAM), outer shareable, read/write,
     * any privileged, executable. Attr 1 (non-cacheable). */
    ARM_MPU_SetRegion(1U, ARM_MPU_RBAR(0x20480000U, ARM_MPU_SH_OUTER, 0U,
        1U, 0U), ARM_MPU_RLAR(0x2051FFFFU, 1U));
#elif OCRAM_WRITE_THROUGH
    /* Region 1: [0x20480000, 0x2051FFFF](OCRAM), outer shareable,
     * read/write, any privileged, executable. Attr 2 (Normal memory, Inner
     * write-through transient, read allocate. Inner write-through transient,
     * read allocate). */
    ARM_MPU_SetRegion(1U, ARM_MPU_RBAR(0x20480000U, ARM_MPU_SH_OUTER, 0U,
        1U, 0U), ARM_MPU_RLAR(0x2051FFFFU, 2U));
#elif OCRAM_WRITE_BACK
    /* Region 1: [0x20480000, 0x2051FFFF](OCRAM), outer shareable,
     * read/write, any privileged, executable. Attr 3 (Normal memory,
     * Outer write-back transient, read/write allocate. Inner write-back
     * transient, read/write allocate). */
    ARM_MPU_SetRegion(1U, ARM_MPU_RBAR(0x20480000U, ARM_MPU_SH_OUTER, 0U,
        1U, 0U), ARM_MPU_RLAR(0x2051FFFFU, 3U));
#endif

    /* Enable MPU(use default memory map when access the memory within
     * region) */
    ARM_MPU_Enable(MPU_CTRL_PRIVDEFENA_Msk);

    /* Enable ICache and DCache */
    XCACHE_EnableCache(LPCAC_PC);
    XCACHE_EnableCache(LPCAC_PS);
}

/*--------------------------------------------------------------------------*/
/* Initialize clocking                                                      */
/*--------------------------------------------------------------------------*/
void BOARD_InitClocks(void)
{
    uint32_t fuseTrim = FSB->FUSE[FSB_FUSE_ANA_CFG4];

    if (fuseTrim == 0U)
    {
        /* Enable the FRO clock with default value */
        (void)FRO_SetEnable(true);
    }
    else
    {
        /* Set the Trim value read from the fuses */
        bool status = FRO_SetTrim(fuseTrim);

        if (status)
        {
            /* Enable the FRO clock with default value */
            (void) FRO_SetEnable(true);
        }
    }

    /* Configure default EXT_CLK1 rate tied to XTAL_OUT/EXT_CLK pin */
    (void) CLOCK_SourceSetRate(CLOCK_SRC_EXT1, BOARD_EXT_CLK_RATE, 0U);

    /* Configure ADC clock */
    (void) CCM_RootSetParent(CLOCK_ROOT_ADC, CLOCK_SRC_SYSPLL1_PFD1_DIV2);
    (void) CCM_RootSetRate(CLOCK_ROOT_ADC, BOARD_ADC_CLK_RATE,
        CLOCK_ROUND_RULE_CEILING);
}

/*--------------------------------------------------------------------------*/
/* Return the debug UART info                                               */
/*--------------------------------------------------------------------------*/
const board_uart_config_t *BOARD_GetDebugUart(void)
{
    return &s_uartConfig;
}

/*--------------------------------------------------------------------------*/
/* Initialize debug console                                                 */
/*--------------------------------------------------------------------------*/
void BOARD_InitDebugConsole(void)
{
    if (s_uartConfig.base != NULL)
    {
        uint64_t rate = CCM_RootGetRate(s_uartConfig.clockId);

        /* Configure debug UART */
        lpuart_config_t lpuart_config;
        LPUART_GetDefaultConfig(&lpuart_config);
        lpuart_config.baudRate_Bps = s_uartConfig.baud;
        lpuart_config.rxFifoWatermark = ((uint8_t)
            FSL_FEATURE_LPUART_FIFO_SIZEn(s_uartConfig.base)) - 1U;
        lpuart_config.txFifoWatermark = ((uint8_t)
            FSL_FEATURE_LPUART_FIFO_SIZEn(s_uartConfig.base)) - 1U;
        lpuart_config.enableTx = true;
        lpuart_config.enableRx = true;
        (void) LPUART_Init(s_uartConfig.base, &lpuart_config,
            (uint32_t) rate & 0xFFFFFFFFU);
    }
}

/*--------------------------------------------------------------------------*/
/* Initialize IRQ handlers                                                  */
/*--------------------------------------------------------------------------*/
void BOARD_InitHandlers(void)
{
    /* Configure default priority of exceptions and IRQs */
    for (int32_t irq = ((int32_t) SVCall_IRQn); irq < ((int32_t)
        NUMBER_OF_INT_VECTORS); irq++)
    {
        // coverity[misra_c_2012_rule_10_5_violation:FALSE]
        NVIC_SetPriority((IRQn_Type) irq, IRQ_PRIO_NOPREEMPT_NORMAL);
    }

    /* Configure SWI handler */
    NVIC_EnableIRQ(BOARD_SWI_IRQn);

    /* Enable BBNSM handler */
    NVIC_EnableIRQ(BBNSM_IRQn);

    /* Enable GPC SM handler */
    NVIC_SetPriority(GPC_SM_REQ_IRQn, IRQ_PRIO_NOPREEMPT_VERY_HIGH);
    NVIC_EnableIRQ(GPC_SM_REQ_IRQn);

    /* Enable ELE Group IRQ handlers */
    NVIC_EnableIRQ(ELE_Group1_IRQn);
    NVIC_EnableIRQ(ELE_Group2_IRQn);
    NVIC_EnableIRQ(ELE_Group3_IRQn);

    /* Enable FCCU handler */
    NVIC_SetPriority(FCCU_INT0_IRQn, IRQ_PRIO_NOPREEMPT_CRITICAL);
    NVIC_EnableIRQ(FCCU_INT0_IRQn);
}

/*--------------------------------------------------------------------------*/
/* Initialize timers                                                        */
/*--------------------------------------------------------------------------*/
void BOARD_InitTimers(void)
{
    /* Configure and enable the BBNSM RTC */
    bbnsm_rtc_config_t rtcConfig;
    BBNSM_RTC_GetDefaultConfig(&rtcConfig);
    BBNSM_RTC_Init(BBNSM, &rtcConfig);

    /* Configure and enable system counter */
    SYSCTR_Init();

    /* Configure and enable M33 SysTick */
    uint64_t rate = CCM_RootGetRate(BOARD_SYSTICK_CLK_ROOT);
    uint32_t reloadVal = (uint32_t) (rate & 0xFFFFFFFFU);
    reloadVal = ((reloadVal * BOARD_TICK_PERIOD_MSEC) + 999U) / 1000U;
    SYSTICK_Init(1U, BOARD_SYSTICK_CLKSRC, (uint32_t) (rate & 0xFFFFFFFFU),
        reloadVal);
    NVIC_EnableIRQ(SysTick_IRQn);

    /* Configure and enable the WDOG */
    WDOG32_GetDefaultConfig(&s_wdogConfig);
    s_wdogConfig.clockSource = BOARD_WDOG_CLK_SRC;
    s_wdogConfig.timeoutValue = BOARD_WDOG_TIMEOUT;
    s_wdogConfig.enableInterrupt = true;
    WDOG32_Init(BOARD_WDOG_BASE_PTR, &s_wdogConfig);
    NVIC_SetPriority(BOARD_WDOG_IRQn, IRQ_PRIO_PREEMPT_CRITICAL);

    /* Configure to just non-FCCU SM watchdogs */
    BLK_CTRL_S_AONMIX->WDOG_ANY_MASK = BOARD_WDOG_ANY_INIT;

    /* Switch WDOG to COLD mode */
    BOARD_WdogModeSet(BOARD_WDOG_MODE_COLD);

    /* Halt SM WDOG on M33 debug entry */
    BLK_CTRL_NS_AONMIX->IPG_DEBUG_CM33 = (BOARD_WDOG_IPG_DEBUG);

    /* Halt CM7 WDOG on CM7 debug entry */
    BLK_CTRL_WAKEUPMIX->IPG_DEBUG_CM7 =
        BLK_CTRL_WAKEUPMIX_IPG_DEBUG_CM7_WDOG5_MASK;
}

/*--------------------------------------------------------------------------*/
/* Set watchdog mode                                                        */
/*--------------------------------------------------------------------------*/
void BOARD_WdogModeSet(uint32_t mode)
{
    switch (mode)
    {
        case BOARD_WDOG_MODE_WARM: /* warm */
            /* Allow WDOG to generate internal warm reset */
            SRC_GEN->SRMASK &= (~BOARD_WDOG_SRMASK);

            /* Enable WDOG interrupt */
            NVIC_EnableIRQ(BOARD_WDOG_IRQn);

            /* Disable WDOG_ANY */
            BLK_CTRL_S_AONMIX->WDOG_ANY_MASK |= BOARD_WDOG_ANY_MASK;

            /* Drive WDOG_ANY from WDOG */
            IOMUXC_SetPinMux(IOMUXC_PAD_WDOG_ANY__WDOG_ANY, 0U);
            break;
        case BOARD_WDOG_MODE_COLD: /* cold */
            /* Allow WDOG to generate internal warm reset */
            SRC_GEN->SRMASK &= (~BOARD_WDOG_SRMASK);

            /* Enable WDOG interrupt */
            NVIC_EnableIRQ(BOARD_WDOG_IRQn);

            /* Enable WDOG_ANY */
            BLK_CTRL_S_AONMIX->WDOG_ANY_MASK &= ~BOARD_WDOG_ANY_MASK;

            /* Drive WDOG_ANY from WDOG */
            IOMUXC_SetPinMux(IOMUXC_PAD_WDOG_ANY__WDOG_ANY, 0U);
            break;
        case BOARD_WDOG_MODE_IRQ: /* irq */
            /* Enable WDOG interrupt */
            NVIC_EnableIRQ(BOARD_WDOG_IRQn);

            /* Disallow WDOG to generate internal warm reset */
            SRC_GEN->SRMASK |= BOARD_WDOG_SRMASK;

            /* Disable WDOG_ANY */
            BLK_CTRL_S_AONMIX->WDOG_ANY_MASK |= BOARD_WDOG_ANY_MASK;

            /* Drive WDOG_ANY from WDOG */
            IOMUXC_SetPinMux(IOMUXC_PAD_WDOG_ANY__WDOG_ANY, 0U);
            break;
        case BOARD_WDOG_MODE_OFF:  /* off */
            s_wdogConfig.enableWdog32 = false;
            WDOG32_Deinit(BOARD_WDOG_BASE_PTR);
            break;
        case BOARD_WDOG_MODE_TRIGGER: /* trigger */
            BOARD_WDOG_BASE_PTR->CNT = 0U;
            break;
        case BOARD_WDOG_MODE_FCCU: /* fccu */
            /* Drive WDOG_ANY from FCCU */
            IOMUXC_SetPinMux(IOMUXC_PAD_WDOG_ANY__FCCU_EOUT1, 0U);

            /* Disallow WDOG to generate internal warm reset */
            SRC_GEN->SRMASK |= BOARD_WDOG_SRMASK;

            /* Disable WDOG interrupt */
            NVIC_DisableIRQ(BOARD_WDOG_IRQn);
            break;
        default:
            ; /* Intentional empty default */
            break;
    }
}

/*--------------------------------------------------------------------------*/
/* Kick the watchdog timer                                                  */
/*--------------------------------------------------------------------------*/
void BOARD_WdogRefresh(void)
{
    WDOG32_Refresh(BOARD_WDOG_BASE_PTR);
}

/*--------------------------------------------------------------------------*/
/* Initialize serial bus for external devices                               */
/*--------------------------------------------------------------------------*/
void BOARD_InitSerialBus(void)
{
}

/*--------------------------------------------------------------------------*/
/* System sleep prepare                                                     */
/*--------------------------------------------------------------------------*/
void BOARD_SystemSleepPrepare(uint32_t sleepMode, uint32_t sleepFlags)
{
    /* Configure SM LPUART for wakeup */
    if (s_uartConfig.base != NULL)
    {
        /* Enable edge-detect IRQ */
        (void) LPUART_ClearStatusFlags(s_uartConfig.base,
            (uint32_t)kLPUART_RxActiveEdgeFlag);
        LPUART_EnableInterrupts(s_uartConfig.base,
            (uint32_t)kLPUART_RxActiveEdgeInterruptEnable);
        NVIC_EnableIRQ(s_uartConfig.irq);

        /* Configure LPI of SM LPUART */
        (void) CPU_PerLpiConfigSet(CPU_IDX_M33P, s_uartConfig.perLpiId,
            CPU_PER_LPI_ON_RUN_WAIT_STOP);
    }
}

/*--------------------------------------------------------------------------*/
/* System sleep entry                                                       */
/*--------------------------------------------------------------------------*/
void BOARD_SystemSleepEnter(uint32_t sleepMode, uint32_t sleepFlags)
{
    /* Disable SysTick */
    uint32_t sysTickMask = SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
    SysTick->CTRL &= (~sysTickMask);

    /* Clear pending SysTick exception */
    SCB->ICSR = SCB_ICSR_PENDSTCLR_Msk;

    if (s_wdogConfig.enableWdog32)
    {
        /* Disable WDOG */
        WDOG32_Deinit(BOARD_WDOG_BASE_PTR);

        /* Waits until for new configuration to take effect. */
        while (0U == ((BOARD_WDOG_BASE_PTR->CS) & WDOG_CS_RCS_MASK))
        {
            ;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* System sleep exit                                                        */
/*--------------------------------------------------------------------------*/
void BOARD_SystemSleepExit(uint32_t sleepMode, uint32_t sleepFlags)
{
    if (s_wdogConfig.enableWdog32)
    {
        /* Enable WDOG */
        WDOG32_Init(BOARD_WDOG_BASE_PTR, &s_wdogConfig);
    }

    /* Enable SysTick */
    uint32_t sysTickMask = SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
    SysTick->VAL   = 0U;
    SysTick->CTRL |= (sysTickMask);
}

/*--------------------------------------------------------------------------*/
/* System sleep unprepare                                                   */
/*--------------------------------------------------------------------------*/
void BOARD_SystemSleepUnprepare(uint32_t sleepMode, uint32_t sleepFlags)
{
    /* Service SM LPUART wakeup events */
    if (s_uartConfig.base != NULL)
    {
        (void) LPUART_ClearStatusFlags(s_uartConfig.base,
            (uint32_t)kLPUART_RxActiveEdgeFlag);
        LPUART_DisableInterrupts(s_uartConfig.base,
            (uint32_t)kLPUART_RxActiveEdgeInterruptEnable);

        NVIC_DisableIRQ(s_uartConfig.irq);
        NVIC_ClearPendingIRQ(s_uartConfig.irq);
    }
}

