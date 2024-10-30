/*
 * Copyright 2023-2024 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*==========================================================================*/
/*!
 * @addtogroup MX9_FRACTPLL_driver
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the Fractional PLL driver.
 */
/*==========================================================================*/

#ifndef FSL_FRACT_PLL_H
#define FSL_FRACT_PLL_H

/* Includes */

#include "fsl_common.h"

/* Defines */

/* Types */

/*!
 * PLL context structure
 *
 * Structure containing all the parameters required to hold a pll context. This
 * structure is used to save a PLL context and restore it later.
 */
typedef struct {
    uint32_t CTRL;              /*!< PLL control register */
    uint32_t SPREAD_SPECTRUM;   /*!< PLL spread spectrum */
    uint32_t NUMERATOR;         /*!< PLL numerator */
    uint32_t DENOMINATOR;       /*!< PLL denominator */
    uint32_t DIV;               /*!< PLL divider */
} fracpll_context_t;

/*!
 * PLL spread spectrum structure
 *
 * Structure containing all the parameters of a client call to configure spread
 * spectrum.
 */
typedef struct {
    uint32_t modFreq;       /*!< Modulation Frequency */
    uint32_t spreadPercent; /*!< Spread percentage */
    uint32_t enable;        /*!< Spread enable */
} fracpll_ssc_t;

/* Functions */

/*!
 * @name FRACTPLL driver functions
 * @{
 */

/*!
 * Get PLL enable status
 *
 * @param[in]   pllIdx     PLL identifier
 * @param[in]   enMask     Enable mask
 *
 * This function allows the caller to get PLL control status field (POWERUP or
 * CLKMUX_EN) for the given \a enMask.
 *
 * @return Returns true if the \a enMask is set in PLL control register,
 *         otherwise false.
 */
bool FRACTPLL_GetEnable(uint32_t pllIdx, uint32_t enMask);

/*!
 * Set PLL enable
 *
 * @param[in]   pllIdx     PLL identifier
 * @param[in]   enMask     Enable mask
 * @param[in]   enable     Enable flag (1=enabled, 0=disabled)
 *
 * This function allows caller to update PLL control fields (POWERUP or
 * CLKMUX_EN) for the given \a enMask . Other PLL features (CLKMUX_BYPASS or
 * spread spectrum enablement) are also updated accordingly.
 *
 * @return Returns true if the \a enMask is updated in PLL control register,
 *         otherwise false.
 */
bool FRACTPLL_SetEnable(uint32_t pllIdx, uint32_t enMask, bool enable);

/*!
 * Get PLL clock rate
 *
 * @param[in]   pllIdx      PLL identifier
 * @param[in]   vcoOp       True to get VCO rate
 *
 * This function returns PLL VCO or PLL output clock rate in Hertz.
 *
 * @return PLL rate in Hertz.
 */
uint64_t FRACTPLL_GetRate(uint32_t pllIdx, bool vcoOp);

/*!
 * Update PLL clock rate
 *
 * @param[in]   pllIdx      PLL identifier
 * @param[in]   mfi         Integer portion of loop divider
 * @param[in]   mfn         Numerator of fractional loop divider
 * @param[in]   odiv        Output frequency divider for clock output
 * @param[in]   forceActive Set true to force PLL enabled with rate update
 *
 * This function allows caller to program mfi, mfn and odiv to update PLL
 * (integer or fractional) rate.
 *
 * @return Return true if PLL rate is updated.
 */
bool FRACTPLL_UpdateRate(uint32_t pllIdx, uint32_t mfi, uint32_t mfn,
    uint32_t odiv, bool forceActive);

/*!
 * Set PLL clock rate
 *
 * @param[in]   pllIdx      PLL identifier
 * @param[in]   vcoOp       True to set PLL VCO rate
 * @param[in]   rate        PLL rate in hertz.
 *
 * This function updates the PLL VCO or PLL output to the rate specified in
 * Hertz.
 *
 * @return Returns true if PLL rate is set successfully.
 */
bool FRACTPLL_SetRate(uint32_t pllIdx, bool vcoOp, uint64_t rate);

/*!
 * Get DFS enable status
 *
 * @param[in]   pllIdx      PLL identifier
 * @param[in]   dfsIdx      DFS identifier
 * @param[in]   enMask      Enable mask
 *
 * This function allows caller to get PLL's DFS enable status.
 *
 * @return Returns true if the \a enMask is successfully read from the PLL's
 *         DFS control register, otherwise false.
 */
bool FRACTPLL_GetDfsEnable(uint32_t pllIdx, uint8_t dfsIdx, uint32_t enMask);

/*!
 * Set DFS enable status
 *
 * @param[in]   pllIdx     PLL identifier
 * @param[in]   dfsIdx     DFS identifier
 * @param[in]   enMask     Enable mask
 * @param[in]   enable     Enable flag (1=enabled, 0=disabled)
 *
 * This function allows caller to update PLL's DFS control fields
 * (ENABLE/CLKOUT_EN/CLKOUT_DIVBY2_EN) for the given \a enMask.
 *
 * @return Returns true if the PLL's DFS control register is updated for given
 *         \a enMask, otherwise false.
 */
bool FRACTPLL_SetDfsEnable(uint32_t pllIdx, uint8_t dfsIdx, uint32_t enMask,
    bool enable);

/*!
 * Get PLL DFS rate
 *
 * @param[in]   pllIdx      PLL identifier
 * @param[in]   dfsIdx      DFS identifier
 * @param[in]   div2        True to get DFS/2 rate
 *
 * This function returns PLL DFS clock rate in Hertz.
 *
 * @return PLL DFS rate in Hertz.
 */
uint64_t FRACTPLL_GetDfsRate(uint32_t pllIdx, uint8_t dfsIdx, bool div2);

/*!
 * Update PLL DFS rate
 *
 * @param[in]   pllIdx      PLL identifier
 * @param[in]   dfsIdx      DFS identifier
 * @param[in]   mfi         Integer portion of loop divider
 * @param[in]   mfn         Numerator of fractional loop divider
 * @param[in]   forceActive Set true to force DFS enabled with rate update
 *
 * This function allows caller to program mfi and mfn to update PLL's
 * (integer or fractional) DFS rate.
 *
 * @return Returns true if PLL DFS rate is updated.
 */
bool FRACTPLL_UpdateDfsRate(uint32_t pllIdx, uint8_t dfsIdx, uint32_t mfi,
    uint32_t mfn, bool forceActive);

/*!
 * Set PLL DFS rate
 *
 * @param[in]   pllIdx      PLL identifier
 * @param[in]   dfsIdx      DFS identifier
 * @param[in]   rate        DFS rate in hertz
 *
 * This function allows caller to set PLL's DFS rate.
 *
 * @return Returns true if PLL DFS rate is set successfully, otherwise false.
 */
bool FRACTPLL_SetDfsRate(uint32_t pllIdx, uint8_t dfsIdx, uint64_t rate);

/*!
 * Set PLL context
 *
 * @param[in]   pllIdx      PLL identifier
 * @param[in]   pllContext  PLL context
 *
 * This function allows caller to program PLL using a saved pllContext.
 *
 * @return Returns true if PLL context is set successfully, otherwise false.
 */
bool FRACTPLL_SetContext(uint32_t pllIdx, const fracpll_context_t *pllContext);

/*!
 * Get PLL context
 *
 * @param[in]   pllIdx      PLL identifier
 * @param[out]  pllContext  PLL context
 *
 * This function allows caller to latch PLL context in  pllContext structure.
 *
 * @return Returns true if PLL context is saved successfully, otherwise false.
 */
bool FRACTPLL_GetContext(uint32_t pllIdx, fracpll_context_t *pllContext);

/*!
 * Set PLL SSC config
 *
 * @param[in]   pllIdx          PLL identifier
 * @param[in]   spreadPercent   Spread percentage
 * @param[in]   modFreq         Modulation frequency
 * @param[in]   enable          Enable flag (1=enabled, 0=disabled)
 *
 * This function allows caller to save/latch spread spectrum configuration for
 * the given \a pllIdx. Spread spectrum is controller through the SCMI 3.2
 * extended clock configuration (or via LMM_ClockExtendedSet() or
 * DEV_SM_ClockExtendedSet()).
 *
 * Saved spread spectrum configuration for the PLL is applied on next
 * CLOCK_RATE_SET command. Spread spectrum is applied to PLL's VCO frequency
 * and gets applied to all its derivative clocks.
 *
 * @return Returns true if PLL SSC's configuration is saved successfully,
 *         otherwise false.
 */
bool FRACTPLL_SetSscConfig(uint32_t pllIdx, uint32_t spreadPercent,
    uint32_t modFreq, uint32_t enable);

/*!
 * Get PLL SSC config
 *
 * @param[in]       pllIdx          PLL identifier
 * @param[out]      spreadPercent   Spread percentage
 * @param[out]      modFreq         Modulation frequency
 * @param[out]      enable          Enable flag (1=enabled, 0=disabled)
 *
 * This function allows caller to get saved/latched spread spectrum
 * configuration for the given \a pllIdx.
 *
 * @return Returns true if PLL's SSC configuration is read successfully,
 *         otherwise false.
 */
bool FRACTPLL_GetSscConfig(uint32_t pllIdx, uint32_t *spreadPercent,
    uint32_t *modFreq, uint32_t *enable);

/*!
 * Calculate PLL SSC parameters
 *
 * @param[in]       pllSsc      PLL spread spectrum configuration
 * @param[in]       rate        PLL VCO rate
 * @param[out]      stop        SPREAD_SPECTRUM[STOP] parameter for programming
 *                              modulation and spread frequency.
 * @param[out]      step        SPREAD_SPECTRUM[STEP] parameter for programming
 *                              modulation and spread frequency.
 *
 * This function allows caller to calculate spread spectrum parameters (stop &
 * step) for the given \a pllSsc (spread spectrum configuration) and \a rate
 * (PLL VCO rate).
 *
 * @return Returns true if all the checks required to calculate spread spectrum
 *         parameters are passed, otherwise false.
 */
bool FRACTPLL_CalcSscParams(const fracpll_ssc_t *pllSsc, uint64_t rate,
    uint32_t *stop, uint32_t *step);

/** @} */

/* Externs */

#endif /* FSL_FRACT_PLL_H */

/** @} */

