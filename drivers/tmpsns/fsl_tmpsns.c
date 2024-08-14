/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_tmpsns.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.tmpsns"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/******************************************************************************
 * Code
 *****************************************************************************/

/*!
 * Initializes the secure section of a TMPSNS module.
 */
void TMPSNS_Init(TMPSNS_Type *base, const tmpsns_config_t *config)
{
    /* Clear CTRL1[ENABLE] */
    base->CTRL1_CLR= TMPSNS_CTRL1_ENABLE(1U);

    /* Configure REF_DIV[DIV] to divide MODULE_CLK to generate CONV_CLK */
    base->REF_DIV = TMPSNS_REF_DIV_DIV(config->clkDiv);

    /* Set REF_DIV[DE] */
    base->REF_DIV |= TMPSNS_REF_DIV_DE(1U);

    /* Configure PUD_ST_CTRL[PUD] to set the PUD */
    base->PUD_ST_CTRL = TMPSNS_PUD_ST_CTRL_PUD(config->pud);

    /* Configure CTRL1[RESOLUTION] as per required conversion time */
    base->CTRL1_CLR = TMPSNS_CTRL1_RESOLUTION(3U);
    base->CTRL1_SET = TMPSNS_CTRL1_RESOLUTION(config->resolution);

    /* Configure PERIOD_CTRL[MEAS_FREQ] as per required interval */
    base->PERIOD_CTRL = TMPSNS_PERIOD_CTRL_CLR_MEAS_FREQ(config->measFreq);

    /* Configure CTRL1[N_FILT_1] */
    base->CTRL1_CLR = TMPSNS_CTRL1_N_FILT_1(0xF);
    base->CTRL1_SET = TMPSNS_CTRL1_N_FILT_1(config->nFilt);

    /* Configure CTRL1[MEAS_MODE] */
    base->CTRL1_CLR = TMPSNS_CTRL1_MEAS_MODE(3U);
    base->CTRL1_SET = TMPSNS_CTRL1_MEAS_MODE(config->measMode);

    /* Configure TRIM */
    base->TRIM1 = config->trim1;
    base->TRIM2 = config->trim2;

    /* Enable and Start */
    TMPSNS_Enable(base);
}

/*!
 * Initializes the nonsecure section of a TMPSNS module.
 */
void TMPSNS_InitNs(TMPSNS_Type *base, const tmpsns_config_t *config)
{
    /* Configure CTRL0[N_FILT_0] */
    base->CTRL0_CLR = TMPSNS_CTRL0_N_FILT_0(0xF);
    base->CTRL0_SET = TMPSNS_CTRL0_N_FILT_0(config->nFilt);
}

/*!
 * De-initializes the secure section of a TMPSNS module.
 */
void TMPSNS_Deinit(TMPSNS_Type *base)
{
    /* Set CTRL1[STOP]. */
    base->CTRL1_SET = TMPSNS_CTRL1_STOP(1U);

    /* Clear CTRL1[ENABLE] */
    base->CTRL1_CLR= TMPSNS_CTRL1_ENABLE(1U);
}

/*!
 * Enable and start an already configured TMPSNS module.
 */
void TMPSNS_Enable(TMPSNS_Type *base)
{
    /* Set CTRL1[ENABLE] */
    base->CTRL1_SET = TMPSNS_CTRL1_ENABLE(1U);

    /* Set CTRL1[START]. */
    base->CTRL1_SET = TMPSNS_CTRL1_START(1U);
}

/*!
 * Gets the default configuration structure.
 */
void TMPSNS_GetDefaultConfig(tmpsns_config_t *config)
{
    config->clkDiv = 5U;       /* Divide by 6, 24MHz to 4MHz */
    config->pud = 100U;        /* 100 clocks at 4MHz = 25uS */
    config->resolution = 1U;   /* 1.1mS conversion time */
    config->measMode = 0U;     /* Single one-shot */
    config->nFilt = 3U;        /* Delay filter by 4 samples */
    config->measFreq = 40000U; /* 4MHz */
    config->trim1 = 0xB561BC2DU;
    config->trim2 = 0x65D4U;
}

/*!
 * Check if enabled.
 */
bool TMPSNS_Enabled(const TMPSNS_Type *base)
{
    return (base->CTRL1 & TMPSNS_CTRL1_ENABLE_MASK) != 0U;
}

/*
 * Gets the TMPSNS status flags.
 */
uint32_t TMPSNS_GetStatusFlags(const TMPSNS_Type *base)
{
    return base->STAT0;
}

/*
 * Clear TMPSNS status flags.
 */
void TMPSNS_ClearStatusFlags(TMPSNS_Type *base, uint32_t flags)
{
    base->STAT0_CLR = flags;
}

/*
 * Enabled interrupts.
 */
void TMPSNS_EnableInterrupts(TMPSNS_Type *base, uint32_t interrupts)
{
    base->CTRL0_SET = interrupts;
}

/*
 * Disable interrupts.
 */
void TMPSNS_DisableInterrupts(TMPSNS_Type *base, uint32_t interrupts)
{
    base->CTRL0_CLR = interrupts;
}

/*
 * Read temp data.
 */
int16_t TMPSNS_GetDataNonBlocking(const TMPSNS_Type *base)
{
    uint16_t value = (uint16_t) (base->DATA0 & 0xFFFFU);

    return (int16_t) value;
}

/*
 * Configure a threshold.
 */
void TMPSNS_SetThreshold(TMPSNS_Type *base, uint8_t thresholdIdx,
    int16_t value, uint8_t mode)
{
    uint16_t uval = (uint16_t) value;

    if (thresholdIdx == 0U)
    {
        /* Clear filter */
        base->CTRL0_SET = TMPSNS_CTRL0_FILT0_CNT_CLR(1U);

        /* Update threshold */
        base->THR_CTRL01_CLR =
            TMPSNS_THR_CTRL01_CLR_TEMPERATURE_THRESHOLD0(0xFFFFU);
        base->THR_CTRL01_SET =
            TMPSNS_THR_CTRL01_CLR_TEMPERATURE_THRESHOLD0(uval);

        /* Update mode */
        base->CTRL0_CLR = TMPSNS_CTRL0_THR0_MODE(3U);
        base->CTRL0_SET = TMPSNS_CTRL0_THR0_MODE(mode);

        /* Clear filter */
        base->CTRL0_SET = TMPSNS_CTRL0_FILT0_CNT_CLR(1U);
    }
    else if (thresholdIdx == 1U)
    {
        /* Clear filter */
        base->CTRL0_SET = TMPSNS_CTRL0_FILT1_CNT_CLR(1U);

        /* Update threshold */
        base->THR_CTRL01_CLR =
            TMPSNS_THR_CTRL01_CLR_TEMPERATURE_THRESHOLD1(0xFFFFU);
        base->THR_CTRL01_SET =
            TMPSNS_THR_CTRL01_CLR_TEMPERATURE_THRESHOLD1(uval);

        /* Update mode */
        base->CTRL0_CLR = TMPSNS_CTRL0_THR1_MODE(3U);
        base->CTRL0_SET = TMPSNS_CTRL0_THR1_MODE(mode);

        /* Clear filter */
        base->CTRL0_SET = TMPSNS_CTRL0_FILT1_CNT_CLR(1U);
    }
    else
    {
        /* Clear filter */
        base->CTRL0_SET = TMPSNS_CTRL0_FILT2_CNT_CLR(1U);

        /* Update threshold */
        base->THR_CTRL23_CLR =
            TMPSNS_THR_CTRL23_CLR_TEMPERATURE_THRESHOLD2(0xFFFFU);
        base->THR_CTRL23_SET =
            TMPSNS_THR_CTRL23_CLR_TEMPERATURE_THRESHOLD2(uval);

        /* Update mode */
        base->CTRL0_CLR = TMPSNS_CTRL0_THR2_MODE(3U);
        base->CTRL0_SET = TMPSNS_CTRL0_THR2_MODE(mode);

        /* Clear filter */
        base->CTRL0_SET = TMPSNS_CTRL0_FILT2_CNT_CLR(1U);
    }
}

