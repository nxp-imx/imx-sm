/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_TMPSNS_H
#define FSL_TMPSNS_H

#include "fsl_common.h"

/*!
 * @addtogroup tmpsns
 * @{
 * @file
 * @brief
 *
 * Header file containing the API for the temp sensor.
 */

/******************************************************************************
 * Definitions
 *****************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief TMPSNS driver version. */
#define FSL_TMPSNS_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*@}*/

/*! @brief TMPSNS configuration structure. */
typedef struct
{
    uint32_t clkDiv;      /*!< Clock divider */
    uint32_t pud;         /*!< Power up delay */
    uint32_t resolution;  /*!< Resolution mode */
    uint32_t measMode;    /*!< Measurement mode */
    uint32_t nFilt;       /*!< Filter delay */
    uint32_t measFreq;    /*!< Measurement frequency */
    uint32_t trim1;       /*!< First trim value */
    uint32_t trim2;       /*!< Second trim value */
} tmpsns_config_t;

/*!
 * @brief TMPSNS status flags.
 */
enum tmpsns_status_flags
{
    kTMPSNS_Idle = TMPSNS_STAT1_IDLE(1U),           /*!< Conversion/idle */
    kTMPSNS_DRrdy1If = TMPSNS_STAT1_DRDY1_IF(1U),   /*!< Data event */

    kTMPSNS_Thr0Stat = TMPSNS_STAT0_THR0_STAT(1U),  /*!< THR0 status */
    kTMPSNS_Thr1Stat = TMPSNS_STAT0_THR1_STAT(1U),  /*!< THR1 status */
    kTMPSNS_Thr2Stat = TMPSNS_STAT0_THR2_STAT(1U),  /*!< THR2 status */

    kTMPSNS_Thr0If = TMPSNS_STAT0_THR0_IF(1U),      /*!< THR0 event */
    kTMPSNS_Thr1If = TMPSNS_STAT0_THR1_IF(1U),      /*!< THR1 event */
    kTMPSNS_Thr2If = TMPSNS_STAT0_THR2_IF(1U),      /*!< THR2 event */
};

/*!
 * @brief TMPSNS interrupt source to enable.
 */
enum tmpsns_interrupt_enable
{
    kTMPSNS_Thr0IE = TMPSNS_CTRL0_THR0_IE(1U),      /*!< THR0 interrupt */
    kTMPSNS_Thr1IE = TMPSNS_CTRL0_THR1_IE(1U),      /*!< THR1 interrupt */
    kTMPSNS_Thr2IE = TMPSNS_CTRL0_THR2_IE(1U),      /*!< THR2 interrupt */
};

/*!
 * @brief TMPSNS threshold modes.
 */
enum tmpsns_thr_modes
{
    kTMPSNS_ThrModeLow = 0U,          /*!< Less than or equal to threshold */
    kTMPSNS_ThrModeHigh = 1U,         /*!< Greater than threshold */
    kTMPSNS_ThrModeFallingEdge = 2U,  /*!< Temperature data transition is from
                                           high to low at threshold */
    kTMPSNS_ThrModeRisingEdge = 3U,   /*!< Temperature data transition is from
                                           low to high at threshold */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name TMPSNS initialization.
 * @{
 */

/*!
 * @brief Initializes the secure section of a TMPSNS module.
 *
 * @param base TMPSNS peripheral base address.
 * @param config Pointer to a configuration structure.
 */
void TMPSNS_Init(TMPSNS_Type *base, const tmpsns_config_t *config);

/*!
 * @brief Initializes the nonsecure section of a TMPSNS module.
 *
 * @param base TMPSNS peripheral base address.
 * @param config Pointer to a configuration structure.
 */
void TMPSNS_InitNs(TMPSNS_Type *base, const tmpsns_config_t *config);

/*!
 * @brief De-initializes the TMPSNS module.
 *
 * @param base TMPSNS peripheral base address.
 */
void TMPSNS_Deinit(TMPSNS_Type *base);

/*!
 * @brief Gets the default configuration structure.
 *
 * @param config Pointer to a configuration structure.
 */
void TMPSNS_GetDefaultConfig(tmpsns_config_t *config);

/** @} */

/*!
 * @brief Gets the TMPSNS status flags.
 *
 * This function returns a bit mask of the TMPSNS status flags.
 * See #tmpsns_status_flags.
 *
 * @param base    TMPSNS peripheral base address.
 *
 * @return Bit mask of the TMPSNS status flags, see #tmpsns_status_flags.
 */
uint32_t TMPSNS_GetStatusFlags(const TMPSNS_Type *base);

/*!
 * @brief Clears the specific TMPSNS status flags.
 *
 * This function clears the specific TMPSNS status flags. The flags to clear should
 * be passed in as bit mask. See #tmpsns_status_flags.
 *
 * @param base TMPSNS peripheral base address.
 * @param flags Bit mask of the TMPSNS status flags. See #tmpsns_status_flags. Only the
 * following flags can be cleared by software, other flags are cleared by hardware:
 * - #kTMPSNS_Thr0If
 * - #kTMPSNS_Thr1If
 * - #kTMPSNS_Thr2If
 */
void TMPSNS_ClearStatusFlags(TMPSNS_Type *base, uint32_t flags);

/*!
 * @brief Enables the specific TMPSNS interrupts.
 *
 * This function enables the specific TMPSNS interrupts. The interrupts to enable
 * should be passed in as a bit mask. See #tmpsns_interrupt_enable.
 *
 * @param base TMPSNS peripheral base address.
 * @param interrupts  Bit mask of the TMPSNS interrupts. See #tmpsns_interrupt_enable.
 */
void TMPSNS_EnableInterrupts(TMPSNS_Type *base, uint32_t interrupts);

/*!
 * @brief Disables the specific TMPSNS interrupts.
 *
 * This function disables the specific TMPSNS interrupts. The interrupts to disable
 * should be passed in as a bit mask. See #tmpsns_interrupt_enable.
 *
 * @param base TMPSNS peripheral base address.
 * @param interrupts  Bit mask of the TMPSNS interrupts. See #tmpsns_interrupt_enable.
 */
void TMPSNS_DisableInterrupts(TMPSNS_Type *base, uint32_t interrupts);

/*!
 * @brief Read temp data.
 *
 * This function reads the TMPSNS data and returns.
 *
 * @param base TMPSNS peripheral base address.
 *
 * @return Temp data read from sensor.
 */
int16_t TMPSNS_GetDataNonBlocking(const TMPSNS_Type *base);

/*!
 * @brief Set TMPSNS threshold.
 *
 * This function sets the threshold value and direction to trigger an
 * interrupt.
 *
 * @param base TMPSNS peripheral base address.
 * @param thresholdIdx Index into the thresholds.
 * @param value Compare value (signed, 1/64 degree).
 * @param mode Trigger direction. See #tmpsns_thr_modes.
 */
void TMPSNS_SetThreshold(TMPSNS_Type *base, uint8_t thresholdIdx,
    int16_t value, uint8_t mode);

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/** @} */

#endif /* FSL_TMPSNS_H */

