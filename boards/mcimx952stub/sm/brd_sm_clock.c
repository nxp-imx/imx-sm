/*
** ###################################################################
**
**     Copyright 2026 NXP
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/* File containing the implementation of the device clock overrides.        */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "brd_sm.h"
#include "fsl_fract_pll.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void BRD_SM_ClockSourcePrepare(uint32_t clockId, uint64_t clockRate,
    uint32_t pllIdx, uint32_t *roundParm);
static uint64_t BRD_SM_SourceCalcVcoRate(uint64_t clockRate);

/*--------------------------------------------------------------------------*/
/* Init board clock override                                                */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_ClockInit(void)
{
    int32_t status;

    /* Default to enable LDB PLL override */
    status = DEV_SM_ClockExtendedSet(DEV_SM_CLK_LDBPLL,
        DEV_SM_CLOCK_EXT_SRCPRE, 1U);

    if (status == SM_ERR_SUCCESS)
    {
        /* Default to enable DISP clock override */
        status = DEV_SM_ClockExtendedSet(DEV_SM_CLK_DISP1PIX,
            DEV_SM_CLOCK_EXT_SRCPRE, 1U);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set clock rate                                                           */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_ClockRateSet(uint32_t clockId, uint64_t rate,
    uint32_t roundSel)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t roundParm = roundSel;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId)) {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        if (clockId == DEV_SM_CLK_DISP1PIX) {
            uint32_t extConfigValue = 0U;

            /* Get DISP clock override */
            status = DEV_SM_ClockExtendedGet(clockId,
                DEV_SM_CLOCK_EXT_SRCPRE, &extConfigValue);

            if ((status == SM_ERR_SUCCESS) && (extConfigValue != 0U))
            {
                /* Configuration clock sources for root set rate */
                BRD_SM_ClockSourcePrepare(clockId, rate,
                    CLOCK_PLL_VIDEO1, &roundParm);
            }
        }

        if (clockId == DEV_SM_CLK_LDBPLL) {
            uint32_t extConfigValue = 0U;

            /* Get LDBPLL override */
            status = DEV_SM_ClockExtendedGet(clockId,
                DEV_SM_CLOCK_EXT_SRCPRE, &extConfigValue);

            if ((status == SM_ERR_SUCCESS) && (extConfigValue != 0U))
            {
                /* Force clocks to round nearest */
                roundParm = DEV_SM_CLOCK_ROUND_AUTO;

                /* Set rate of parent VCO */
                status = DEV_SM_ClockRateSet(DEV_SM_CLK_LDBPLL_VCO,
                    BRD_SM_SourceCalcVcoRate(rate), roundParm);
            }
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Update target clock */
        status = DEV_SM_ClockRateSet(clockId, rate, roundParm);
    }

    /* Return status */
    return status;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Prepare clock sources for CCM root rate set                              */
/*--------------------------------------------------------------------------*/
static void BRD_SM_ClockSourcePrepare(uint32_t clockId, uint64_t clockRate,
    uint32_t pllIdx, uint32_t *roundParm)
{
    bool rateMatch;
    uint32_t mfi;
    uint32_t mfn;
    uint32_t odiv;

    switch (clockRate) {
        case 297000000UL:
        case 296703000UL:
        case 148500000UL:
        case 148352000UL:
        case  74250000UL:
        case  74176000UL:
            /* VCO = 24MHz * (111 + 3/8) = 2673000000Hz
             * PLL_OUT = VCO / 9 = 297000000Hz
             */
            mfi = 111U;
            mfn = ((((uint32_t)(CLOCK_PLL_MFD & 0xFFFFFFFFU)) * 3U)
                / 8U);
            odiv = 9U;
            rateMatch = true;
            break;

        case 241500000UL:
            /* VCO = 24MHz * (120 + 4/5) = 2899200000Hz
             * PLL_OUT = VCO / 12 = 241600000Hz
             */
            mfi = 120U;
            mfn = ((((uint32_t)(CLOCK_PLL_MFD & 0xFFFFFFFFU)) * 4U)
                / 5U);
            odiv = 12U;
            rateMatch = true;
            break;

        case 108108000UL:
        case 108000000UL:
        case  27027000UL:
        case  27000000UL:
            /* VCO = 24MHz * (126) = 3024000000Hz
             * PLL_OUT = VCO / 14 = 216000000Hz
             */
            mfi = 126U;
            mfn = 0U;
            odiv = 14U;
            rateMatch = true;
            break;

        case 71000000UL:
            /* VCO = 24MHz * (130 + 1/6) = 3124000000Hz
             * PLL_OUT = VCO / 11 = 284000000Hz
             */
            mfi = 130U;
            mfn = ((((uint32_t)(CLOCK_PLL_MFD & 0xFFFFFFFFU)) * 1U)
                / 6U);
            odiv = 11U;
            rateMatch = true;
            break;

        case 65000000UL:
            /* VCO = 24MHz * (130) = 3120000000Hz
             * PLL_OUT = VCO / 12 = 260000000Hz
             */
            mfi = 130U;
            mfn = 0U;
            odiv = 12U;
            rateMatch = true;
            break;

        case 54054000UL:
        case 54000000UL:
            /* VCO = 24MHz * (135) = 3240000000Hz
             * PLL_OUT = VCO / 12 = 270000000Hz
             */
            mfi = 135U;
            mfn = 0U;
            odiv = 12U;
            rateMatch = true;
            break;

        case 40000000UL:
            /* VCO = 24MHz * (130) = 3120000000Hz
             * PLL_OUT = VCO / 13 = 240000000Hz
             */
            mfi = 130U;
            mfn = 0U;
            odiv = 13U;
            rateMatch = true;
            break;

        case 25200000UL:
            /* VCO = 24MHz * (126) = 3024000000Hz
             * PLL_OUT = VCO / 15 = 201600000Hz
             */
            mfi = 126U;
            mfn = 0U;
            odiv = 15U;
            rateMatch = true;
            break;

        case 25175000UL:
            /* VCO = 24MHz * (113 + 1/4) = 271800000000Hz
             * PLL_OUT = VCO / 12 = 226500000Hz
             */
            mfi = 113U;
            mfn = ((((uint32_t)(CLOCK_PLL_MFD & 0xFFFFFFFFU)) * 1U)
                / 4U);
            odiv = 12U;
            rateMatch = true;
            break;

        default:
            rateMatch = false;
            break;
    };

    /* Check if rate match found */
    if (rateMatch) {
        /* Configure PLL based on requested rate */
        (void)FRACTPLL_UpdateRate(pllIdx, mfi, mfn, odiv,
            false);

        /* Force rounding rule auto/closest */
        *roundParm = DEV_SM_CLOCK_ROUND_AUTO;
    }
}

/*--------------------------------------------------------------------------*/
/* Calculate a VCO for the LDB PLL                                          */
/*--------------------------------------------------------------------------*/
static uint64_t BRD_SM_SourceCalcVcoRate(uint64_t clockRate)
{
    uint64_t pllVcoRate;

    if (clockRate < 9882353UL)
    {
        /*  Set to PLL mimimum output:
         *  2520000000 Hz / 255 = 9882353 Hz
         */
        pllVcoRate = 25200000UL;
    }
    else if (clockRate < 12000000UL)
    {
        pllVcoRate = clockRate * 255UL;
    }
    else if (clockRate < 22000000UL)
    {
        pllVcoRate = clockRate * 220UL;
    }
    else if (clockRate < 42000000UL)
    {
        pllVcoRate = clockRate * 112UL;
    }
    else if (clockRate < 80000000UL)
    {
        pllVcoRate = clockRate * 60UL;
    }
    else if (clockRate < 140000000UL)
    {
        pllVcoRate = clockRate * 32UL;
    }
    else if (clockRate < 252000000UL)
    {
        pllVcoRate = clockRate * 18UL;
    }
    else if (clockRate < 420000000UL)
    {
        pllVcoRate = clockRate * 10UL;
    }
    else if (clockRate < 800000000UL)
    {
        pllVcoRate = clockRate * 6UL;
    }
    else if (clockRate < 1200000000UL)
    {
        pllVcoRate = clockRate * 4UL;
    }
    else if (clockRate < 1260000000UL)
    {
        pllVcoRate = clockRate * 3UL;
    }
    else if (clockRate < 2496000000UL)
    {
        pllVcoRate = clockRate * 2UL;
    }
    else
    {
        /*  Set to PLL maximum output:
         *  4992000000 Hz / 2 = 2496000000 Hz
         */
        pllVcoRate = 2496000000UL;
    }

    /* Return rate */
    return pllVcoRate;
}

