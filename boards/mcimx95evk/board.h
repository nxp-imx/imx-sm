/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef BOARD_H
#define BOARD_H

#include "fsl_common.h"
#include "config_board.h"
#include "dev_sm.h"

/*!
 * @addtogroup BRD_SM_MX95EVK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the board API.
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @name Board general parameters
 */
/** @{ */
#define BOARD_TICK_PERIOD_MSEC  10U               /*!< Tick period */
#define BOARD_SWI_IRQn          Reserved110_IRQn  /*!< SWI IRQ */
#define BOARD_HAS_WDOG                            /*!< Has a watchdog */
#define BOARD_HAS_PMIC                            /*!< Has a PMIC */
/** @} */

/*!
 * @name Watchdog modes
 */
/** @{ */
#define BOARD_WDOG_MODE_WARM     0U  /*!< Wdog generate warm reset */
#define BOARD_WDOG_MODE_COLD     1U  /*!< Wdog generate cold reset */
#define BOARD_WDOG_MODE_IRQ      2U  /*!< Wdog generate IRQ only */
#define BOARD_WDOG_MODE_OFF      3U  /*!< Wdog disabled */
#define BOARD_WDOG_MODE_TRIGGER  4U  /*!< Trigger wdog */
#define BOARD_WDOG_MODE_FCCU     5U  /*!< Wdog generate FCCU fault */
/** @} */

/*******************************************************************************
 * Types
 ******************************************************************************/

/*!
 * Debug UART configuration info
 */
typedef struct
{
    LPUART_Type *const base;  /*!< LPUART base pointer */
    IRQn_Type irq;            /*!< Interrupt number */
    uint32_t clockId;         /*!< Clock ID */
    uint32_t perLpiId;        /*!< Peripheral LPI ID */
    uint32_t baud;            /*!< Baud rate */
    uint8_t inst;             /*!< Instance number */
} board_uart_config_t;

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * API
 ******************************************************************************/

/*! Configure the M33 MPU */
void BOARD_ConfigMPU(void);

/*! Init hardware */
void BOARD_InitHardware(void);

/*! Init clocks */
void BOARD_InitClocks(void);

/*!
 * Get a device clock debug UART info.
 *
 * This function returns the UART info for the UART used for SM
 * debug.
 *
 * @return Returns the debug UART config info.
 */
const board_uart_config_t *BOARD_GetDebugUart(void);

/*! Init the debug UART */
void BOARD_InitDebugConsole(void);

/*! Init interrupt handlers */
void BOARD_InitHandlers(void);

/*! Init timers */
void BOARD_InitTimers(void);

/*! Init serial buses */
void BOARD_InitSerialBus(void);

/*!
 * Board-level prepare for system sleep entry
 *
 * @param sleepMode  Sleep mode being entered.
 * @param sleepFlags Sleep flag options.
 */
void BOARD_SystemSleepPrepare(uint32_t sleepMode, uint32_t sleepFlags);

/*!
 * Board-level system sleep entry
 *
 * @param sleepMode  Sleep mode being entered.
 * @param sleepFlags Sleep flag options.
 */
void BOARD_SystemSleepEnter(uint32_t sleepMode, uint32_t sleepFlags);

/*!
 * Board-level system sleep exit
 *
 * @param sleepMode  Sleep mode being exited.
 * @param sleepFlags Sleep flag options.
 */
void BOARD_SystemSleepExit(uint32_t sleepMode, uint32_t sleepFlags);

/*!
 * Board-level unprepare for system sleep entry
 *
 * @param sleepMode  Sleep mode being entered.
 * @param sleepFlags Sleep flag options.
 */
void BOARD_SystemSleepUnprepare(uint32_t sleepMode, uint32_t sleepFlags);

/*!
 * Set the watchdog mode
 *
 * @param mode Mode to set.
 */
void BOARD_WdogModeSet(uint32_t mode);

/*! Service the watchdog */
void BOARD_WdogRefresh(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/** @} */

#endif /* BOARD_H */

