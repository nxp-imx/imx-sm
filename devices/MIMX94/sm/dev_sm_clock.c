/*
** ###################################################################
**
**     Copyright 2025-2026 NXP
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
/* File containing the implementation of the device clocks.                 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Return clock name                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockNameGet(uint32_t clockId, string *clockNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_NOT_FOUND;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_CLOCK] =
    {
        [DEV_SM_CLK_EXT] =                  "ext",
        [DEV_SM_CLK_OSC32K] =               "osc32k",
        [DEV_SM_CLK_OSC24M] =               "osc24m",
        [DEV_SM_CLK_FRO] =                  "fro",
        [DEV_SM_CLK_SYSPLL1_VCO] =          "syspll1_vco",
        [DEV_SM_CLK_SYSPLL1_PFD0_UNGATED] = "syspll1_pfd0_ungated",
        [DEV_SM_CLK_SYSPLL1_PFD0] =         "syspll1_pfd0",
        [DEV_SM_CLK_SYSPLL1_PFD0_DIV2] =    "syspll1_pfd0_div2",
        [DEV_SM_CLK_SYSPLL1_PFD1_UNGATED] = "syspll1_pfd1_ungated",
        [DEV_SM_CLK_SYSPLL1_PFD1] =         "syspll1_pfd1",
        [DEV_SM_CLK_SYSPLL1_PFD1_DIV2] =    "syspll1_pfd1_div2",
        [DEV_SM_CLK_SYSPLL1_PFD2_UNGATED] = "syspll1_pfd2_ungated",
        [DEV_SM_CLK_SYSPLL1_PFD2] =         "syspll1_pfd2",
        [DEV_SM_CLK_SYSPLL1_PFD2_DIV2] =    "syspll1_pfd2_div2",
        [DEV_SM_CLK_AUDIOPLL1_VCO] =        "audiopll1_vco",
        [DEV_SM_CLK_AUDIOPLL1] =            "audiopll1",
        [DEV_SM_CLK_AUDIOPLL2_VCO] =        "audiopll2_vco",
        [DEV_SM_CLK_AUDIOPLL2] =            "audiopll2",
        [DEV_SM_CLK_ENCPLL_VCO] =           "encpll_vco",
        [DEV_SM_CLK_ENCPLL_PFD0_UNGATED] =  "encpll_pfd0_ungated",
        [DEV_SM_CLK_ENCPLL_PFD0] =          "encpll_pfd0",
        [DEV_SM_CLK_ENCPLL_PFD1_UNGATED] =  "encpll_pfd1_ungated",
        [DEV_SM_CLK_ENCPLL_PFD1] =          "encpll_pfd1",
        [DEV_SM_CLK_ARMPLL_VCO] =           "armpll_vco",
        [DEV_SM_CLK_ARMPLL_PFD0_UNGATED] =  "armpll_pfd0_ungated",
        [DEV_SM_CLK_ARMPLL_PFD0] =          "armpll_pfd0",
        [DEV_SM_CLK_ARMPLL_PFD1_UNGATED] =  "armpll_pfd1_ungated",
        [DEV_SM_CLK_ARMPLL_PFD1] =          "armpll_pfd1",
        [DEV_SM_CLK_ARMPLL_PFD2_UNGATED] =  "armpll_pfd2_ungated",
        [DEV_SM_CLK_ARMPLL_PFD2] =          "armpll_pfd2",
        [DEV_SM_CLK_ARMPLL_PFD3_UNGATED] =  "armpll_pfd3_ungated",
        [DEV_SM_CLK_ARMPLL_PFD3] =          "armpll_pfd3",
        [DEV_SM_CLK_DRAMPLL_VCO] =          "drampll_vco",
        [DEV_SM_CLK_DRAMPLL] =              "drampll",
        [DEV_SM_CLK_HSIOPLL_VCO] =          "hsiopll_vco",
        [DEV_SM_CLK_HSIOPLL] =              "hsiopll",
        [DEV_SM_CLK_LDBPLL_VCO] =           "ldbpll_vco",
        [DEV_SM_CLK_LDBPLL] =               "ldbpll",
        [DEV_SM_CLK_EXT1] =                 "ext1",
        [DEV_SM_CLK_EXT2] =                 "ext2",

        [DEV_SM_CLK_ADC] =                  "adc",
        [DEV_SM_CLK_BUSAON] =               "busaon",
        [DEV_SM_CLK_CAN1] =                 "can1",
        [DEV_SM_CLK_GLITCHFILTER] =         "glitchfilter",
        [DEV_SM_CLK_GPT1] =                 "gpt1",
        [DEV_SM_CLK_I3C1SLOW] =             "i3c1slow",
        [DEV_SM_CLK_LPI2C1] =               "lpi2c1",
        [DEV_SM_CLK_LPI2C2] =               "lpi2c2",
        [DEV_SM_CLK_LPSPI1] =               "lpspi1",
        [DEV_SM_CLK_LPSPI2] =               "lpspi2",
        [DEV_SM_CLK_LPTMR1] =               "lptmr1",
        [DEV_SM_CLK_LPUART1] =              "lpuart1",
        [DEV_SM_CLK_LPUART2] =              "lpuart2",
        [DEV_SM_CLK_M33] =                  "m33",
        [DEV_SM_CLK_M33SYSTICK] =           "m33systick",
        [DEV_SM_CLK_PDM] =                  "pdm",
        [DEV_SM_CLK_SAI1] =                 "sai1",
        [DEV_SM_CLK_TPM2] =                 "tpm2",
        [DEV_SM_CLK_A55] =                  "a55",
        [DEV_SM_CLK_A55MTRBUS] =            "a55mtrbus",
        [DEV_SM_CLK_A55PERIPH] =            "a55periph",
        [DEV_SM_CLK_DRAMALT] =              "dramalt",
        [DEV_SM_CLK_DRAMAPB] =              "dramapb",
        [DEV_SM_CLK_DISPAPB] =              "dispapb",
        [DEV_SM_CLK_DISPAXI] =              "dispaxi",
        [DEV_SM_CLK_DISPPIX] =              "disppix",
        [DEV_SM_CLK_HSIOACSCAN480M] =       "hsioacscan480m",
        [DEV_SM_CLK_HSIOACSCAN80M] =        "hsioacscan80m",
        [DEV_SM_CLK_HSIO] =                 "hsio",
        [DEV_SM_CLK_HSIOPCIEAUX] =          "hsiopcieaux",
        [DEV_SM_CLK_HSIOPCIETEST160M] =     "hsiopcietest160m",
        [DEV_SM_CLK_HSIOPCIETEST400M] =     "hsiopcietest400m",
        [DEV_SM_CLK_HSIOPCIETEST500M] =     "hsiopcietest500m",
        [DEV_SM_CLK_HSIOPCIETEST50M] =      "hsiopcietest50m",
        [DEV_SM_CLK_HSIOUSBTEST60M] =       "hsiousbtest60m",
        [DEV_SM_CLK_BUSM70] =               "busm70",
        [DEV_SM_CLK_M70] =                  "m70",
        [DEV_SM_CLK_M70SYSTICK] =           "m70systick",
        [DEV_SM_CLK_BUSM71] =               "busm71",
        [DEV_SM_CLK_M71] =                  "m71",
        [DEV_SM_CLK_M71SYSTICK] =           "m71systick",
        [DEV_SM_CLK_BUSNETCMIX] =           "busnetcmix",
        [DEV_SM_CLK_ECAT] =                 "ecat",
        [DEV_SM_CLK_ENET] =                 "enet",
        [DEV_SM_CLK_ENETPHYTEST200M] =      "enetphytest200m",
        [DEV_SM_CLK_ENETPHYTEST500M] =      "enetphytest500m",
        [DEV_SM_CLK_ENETPHYTEST667M] =      "enetphytest667m",
        [DEV_SM_CLK_ENETREF] =              "enetref",
        [DEV_SM_CLK_ENETTIMER1] =           "enettimer1",
        [DEV_SM_CLK_ENETTIMER2] =           "enettimer2",
        [DEV_SM_CLK_ENETTIMER3] =           "enettimer3",
        [DEV_SM_CLK_FLEXIO3] =              "flexio3",
        [DEV_SM_CLK_FLEXIO4] =              "flexio4",
        [DEV_SM_CLK_M33SYNC] =              "m33sync",
        [DEV_SM_CLK_M33SYNCSYSTICK] =       "m33syncsystick",
        [DEV_SM_CLK_MAC0] =                 "mac0",
        [DEV_SM_CLK_MAC1] =                 "mac1",
        [DEV_SM_CLK_MAC2] =                 "mac2",
        [DEV_SM_CLK_MAC3] =                 "mac3",
        [DEV_SM_CLK_MAC4] =                 "mac4",
        [DEV_SM_CLK_MAC5] =                 "mac5",
        [DEV_SM_CLK_NOCAPB] =               "nocapb",
        [DEV_SM_CLK_NOC] =                  "noc",
        [DEV_SM_CLK_NPUAPB] =               "npuapb",
        [DEV_SM_CLK_NPU] =                  "npu",
        [DEV_SM_CLK_CCMCKO1] =              "ccmcko1",
        [DEV_SM_CLK_CCMCKO2] =              "ccmcko2",
        [DEV_SM_CLK_CCMCKO3] =              "ccmcko3",
        [DEV_SM_CLK_CCMCKO4] =              "ccmcko4",
        [DEV_SM_CLK_BISS] =                 "biss",
        [DEV_SM_CLK_BUSWAKEUP] =            "buswakeup",
        [DEV_SM_CLK_CAN2] =                 "can2",
        [DEV_SM_CLK_CAN3] =                 "can3",
        [DEV_SM_CLK_CAN4] =                 "can4",
        [DEV_SM_CLK_CAN5] =                 "can5",
        [DEV_SM_CLK_ENDAT21] =              "endat21",
        [DEV_SM_CLK_ENDAT22] =              "endat22",
        [DEV_SM_CLK_ENDAT31FAST] =          "endat31fast",
        [DEV_SM_CLK_ENDAT31SLOW] =          "endat31slow",
        [DEV_SM_CLK_FLEXIO1] =              "flexio1",
        [DEV_SM_CLK_FLEXIO2] =              "flexio2",
        [DEV_SM_CLK_GPT2] =                 "gpt2",
        [DEV_SM_CLK_GPT3] =                 "gpt3",
        [DEV_SM_CLK_GPT4] =                 "gpt4",
        [DEV_SM_CLK_HIPERFACE1] =           "hiperface1",
        [DEV_SM_CLK_HIPERFACE1SYNC] =       "hiperface1sync",
        [DEV_SM_CLK_HIPERFACE2] =           "hiperface2",
        [DEV_SM_CLK_HIPERFACE2SYNC] =       "hiperface2sync",
        [DEV_SM_CLK_I3C2SLOW] =             "i3c2slow",
        [DEV_SM_CLK_LPI2C3] =               "lpi2c3",
        [DEV_SM_CLK_LPI2C4] =               "lpi2c4",
        [DEV_SM_CLK_LPI2C5] =               "lpi2c5",
        [DEV_SM_CLK_LPI2C6] =               "lpi2c6",
        [DEV_SM_CLK_LPI2C7] =               "lpi2c7",
        [DEV_SM_CLK_LPI2C8] =               "lpi2c8",
        [DEV_SM_CLK_LPSPI3] =               "lpspi3",
        [DEV_SM_CLK_LPSPI4] =               "lpspi4",
        [DEV_SM_CLK_LPSPI5] =               "lpspi5",
        [DEV_SM_CLK_LPSPI6] =               "lpspi6",
        [DEV_SM_CLK_LPSPI7] =               "lpspi7",
        [DEV_SM_CLK_LPSPI8] =               "lpspi8",
        [DEV_SM_CLK_LPTMR2] =               "lptmr2",
        [DEV_SM_CLK_LPUART10] =             "lpuart10",
        [DEV_SM_CLK_LPUART11] =             "lpuart11",
        [DEV_SM_CLK_LPUART12] =             "lpuart12",
        [DEV_SM_CLK_LPUART3] =              "lpuart3",
        [DEV_SM_CLK_LPUART4] =              "lpuart4",
        [DEV_SM_CLK_LPUART5] =              "lpuart5",
        [DEV_SM_CLK_LPUART6] =              "lpuart6",
        [DEV_SM_CLK_LPUART7] =              "lpuart7",
        [DEV_SM_CLK_LPUART8] =              "lpuart8",
        [DEV_SM_CLK_LPUART9] =              "lpuart9",
        [DEV_SM_CLK_SAI2] =                 "sai2",
        [DEV_SM_CLK_SAI3] =                 "sai3",
        [DEV_SM_CLK_SAI4] =                 "sai4",
        [DEV_SM_CLK_SWOTRACE] =             "swotrace",
        [DEV_SM_CLK_TPM4] =                 "tpm4",
        [DEV_SM_CLK_TPM5] =                 "tpm5",
        [DEV_SM_CLK_TPM6] =                 "tpm6",
        [DEV_SM_CLK_USBPHYBURUNIN] =        "usbphyburunin",
        [DEV_SM_CLK_USDHC1] =               "usdhc1",
        [DEV_SM_CLK_USDHC2] =               "usdhc2",
        [DEV_SM_CLK_USDHC3] =               "usdhc3",
        [DEV_SM_CLK_V2XPK] =                "v2xpk",
        [DEV_SM_CLK_WAKEUPAXI] =            "wakeupaxi",
        [DEV_SM_CLK_XSPISLVROOT] =          "xspislvroot",
        [DEV_SM_CLK_XSPI1] =                "xspi1",
        [DEV_SM_CLK_XSPI2] =                "xspi2",
        [DEV_SM_CLK_EXT_GPR_SEL] =          "ext_gpr_sel",
        [DEV_SM_CLK_A55C0_GPR_SEL] =        "a55c0_gpr_sel",
        [DEV_SM_CLK_A55C1_GPR_SEL] =        "a55c1_gpr_sel",
        [DEV_SM_CLK_A55C2_GPR_SEL] =        "a55c2_gpr_sel",
        [DEV_SM_CLK_A55C3_GPR_SEL] =        "a55c3_gpr_sel",
        [DEV_SM_CLK_A55P_GPR_SEL] =         "a55p_gpr_sel",
        [DEV_SM_CLK_DRAM_GPR_SEL] =         "dram_gpr_sel",
        [DEV_SM_CLK_TEMPSENSE_GPR_SEL] =    "temp_gpr_sel",

        [DEV_SM_CLK_NPU_CGC] =              "npu_cgc"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_CLOCK);

    /* Check clock */
    if (!DEV_SM_ClockIsReserved(clockId))
    {
        /* Return pointer to name */
        *clockNameAddr = s_name[clockId];

        status = SM_ERR_SUCCESS;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return supported clock range                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockDescribe(uint32_t clockId,
    dev_sm_clock_range_t *range)
{
    int32_t status = SM_ERR_NOT_FOUND;

    static uint64_t const s_highestRateHz[DEV_SM_NUM_CLOCK] =
    {
        [DEV_SM_CLK_EXT] =                  ES_MAX_HZ_EXT1,
        [DEV_SM_CLK_OSC32K] =               ES_MAX_HZ_OSC32K,
        [DEV_SM_CLK_OSC24M] =               ES_MAX_HZ_OSC24M,
        [DEV_SM_CLK_FRO] =                  ES_MAX_HZ_FRO,
        [DEV_SM_CLK_SYSPLL1_VCO] =          ES_MAX_HZ_PLLVCO,
        [DEV_SM_CLK_SYSPLL1_PFD0_UNGATED] = ES_MAX_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD0] =         ES_MAX_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD0_DIV2] =    ES_MAX_HZ_PFD / 2U,
        [DEV_SM_CLK_SYSPLL1_PFD1_UNGATED] = ES_MAX_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD1] =         ES_MAX_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD1_DIV2] =    ES_MAX_HZ_PFD / 2U,
        [DEV_SM_CLK_SYSPLL1_PFD2_UNGATED] = ES_MAX_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD2] =         ES_MAX_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD2_DIV2] =    ES_MAX_HZ_PFD / 2U,
        [DEV_SM_CLK_AUDIOPLL1_VCO] =        ES_MAX_HZ_PLLVCO,
        [DEV_SM_CLK_AUDIOPLL1] =            ES_MAX_HZ_AUDIOPLL,
        [DEV_SM_CLK_AUDIOPLL2_VCO] =        ES_MAX_HZ_PLLVCO,
        [DEV_SM_CLK_AUDIOPLL2] =            ES_MAX_HZ_AUDIOPLL,
        [DEV_SM_CLK_ENCPLL_VCO] =           ES_MAX_HZ_PLLVCO,
        [DEV_SM_CLK_ENCPLL_PFD0_UNGATED] =  ES_MAX_HZ_PFD,
        [DEV_SM_CLK_ENCPLL_PFD0] =          ES_MAX_HZ_PFD,
        [DEV_SM_CLK_ENCPLL_PFD1_UNGATED] =  ES_MAX_HZ_PFD,
        [DEV_SM_CLK_ENCPLL_PFD1] =          ES_MAX_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_VCO] =           ES_MAX_HZ_PLLVCO,
        [DEV_SM_CLK_ARMPLL_PFD0_UNGATED] =  ES_MAX_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD0] =          ES_MAX_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD1_UNGATED] =  ES_MAX_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD1] =          ES_MAX_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD2_UNGATED] =  ES_MAX_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD2] =          ES_MAX_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD3_UNGATED] =  ES_MAX_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD3] =          ES_MAX_HZ_PFD,
        [DEV_SM_CLK_DRAMPLL_VCO] =          ES_MAX_HZ_PLLVCO,
        [DEV_SM_CLK_DRAMPLL] =              ES_MAX_HZ_DRAMPLL,
        [DEV_SM_CLK_HSIOPLL_VCO] =          ES_MAX_HZ_PLLVCO,
        [DEV_SM_CLK_HSIOPLL] =              ES_MAX_HZ_HSIOPLL,
        [DEV_SM_CLK_LDBPLL_VCO] =           ES_MAX_HZ_PLLVCO,
        [DEV_SM_CLK_LDBPLL] =               ES_MAX_HZ_LDBPLL,
        [DEV_SM_CLK_EXT1] =                 ES_MAX_HZ_EXT1,
        [DEV_SM_CLK_EXT2] =                 ES_MAX_HZ_GND,

        [DEV_SM_CLK_ADC] =                  ES_MAX_HZ_ADC,
        [DEV_SM_CLK_BUSAON] =               ES_MAX_HZ_BUSAON,
        [DEV_SM_CLK_CAN1] =                 ES_MAX_HZ_CAN1,
        [DEV_SM_CLK_GLITCHFILTER] =         ES_MAX_HZ_GLITCHFILTER,
        [DEV_SM_CLK_I3C1SLOW] =             ES_MAX_HZ_I3C1SLOW,
        [DEV_SM_CLK_LPI2C1] =               ES_MAX_HZ_LPI2C1,
        [DEV_SM_CLK_LPI2C2] =               ES_MAX_HZ_LPI2C2,
        [DEV_SM_CLK_LPSPI1] =               ES_MAX_HZ_LPSPI1,
        [DEV_SM_CLK_LPSPI2] =               ES_MAX_HZ_LPSPI2,
        [DEV_SM_CLK_LPTMR1] =               ES_MAX_HZ_LPTMR1,
        [DEV_SM_CLK_LPUART1] =              ES_MAX_HZ_LPUART1,
        [DEV_SM_CLK_LPUART2] =              ES_MAX_HZ_LPUART2,
        [DEV_SM_CLK_M33] =                  ES_MAX_HZ_M33,
        [DEV_SM_CLK_M33SYSTICK] =           ES_MAX_HZ_M33SYSTICK,
        [DEV_SM_CLK_PDM] =                  ES_MAX_HZ_PDM,
        [DEV_SM_CLK_SAI1] =                 ES_MAX_HZ_SAI1,
        [DEV_SM_CLK_TPM2] =                 ES_MAX_HZ_TPM2,
        [DEV_SM_CLK_A55] =                  ES_MAX_HZ_A55,
        [DEV_SM_CLK_A55MTRBUS] =            ES_MAX_HZ_A55MTRBUS,
        [DEV_SM_CLK_A55PERIPH] =            ES_MAX_HZ_A55PERIPH,
        [DEV_SM_CLK_DRAMALT] =              ES_MAX_HZ_DRAMALT,
        [DEV_SM_CLK_DRAMAPB] =              ES_MAX_HZ_DRAMAPB,
        [DEV_SM_CLK_DISPAPB] =              ES_MAX_HZ_DISPAPB,
        [DEV_SM_CLK_DISPAXI] =              ES_MAX_HZ_DISPAXI,
        [DEV_SM_CLK_DISPPIX] =              ES_MAX_HZ_DISPPIX,
        [DEV_SM_CLK_HSIOACSCAN480M] =       ES_MAX_HZ_HSIOACSCAN480M,
        [DEV_SM_CLK_HSIOACSCAN80M] =        ES_MAX_HZ_HSIOACSCAN80M,
        [DEV_SM_CLK_HSIO] =                 ES_MAX_HZ_HSIO,
        [DEV_SM_CLK_HSIOPCIEAUX] =          ES_MAX_HZ_HSIOPCIEAUX,
        [DEV_SM_CLK_HSIOPCIETEST160M] =     ES_MAX_HZ_HSIOPCIETEST160M,
        [DEV_SM_CLK_HSIOPCIETEST400M] =     ES_MAX_HZ_HSIOPCIETEST400M,
        [DEV_SM_CLK_HSIOPCIETEST500M] =     ES_MAX_HZ_HSIOPCIETEST500M,
        [DEV_SM_CLK_HSIOUSBTEST60M] =       ES_MAX_HZ_HSIOUSBTEST60M,
        [DEV_SM_CLK_BUSM70] =               ES_MAX_HZ_BUSM7,
        [DEV_SM_CLK_M70] =                  ES_MAX_HZ_M7,
        [DEV_SM_CLK_M70SYSTICK] =           ES_MAX_HZ_M7SYSTICK,
        [DEV_SM_CLK_BUSM71] =               ES_MAX_HZ_BUSM7,
        [DEV_SM_CLK_M71] =                  ES_MAX_HZ_M7,
        [DEV_SM_CLK_M71SYSTICK] =           ES_MAX_HZ_M7SYSTICK,
        [DEV_SM_CLK_BUSNETCMIX] =           ES_MAX_HZ_BUSNETCMIX,
        [DEV_SM_CLK_ECAT] =                 ES_MAX_HZ_ECAT,
        [DEV_SM_CLK_ENET] =                 ES_MAX_HZ_ENET,
        [DEV_SM_CLK_ENETPHYTEST200M] =      ES_MAX_HZ_ENETPHYTEST200M,
        [DEV_SM_CLK_ENETPHYTEST500M] =      ES_MAX_HZ_ENETPHYTEST500M,
        [DEV_SM_CLK_ENETPHYTEST667M] =      ES_MAX_HZ_ENETPHYTEST667M,
        [DEV_SM_CLK_ENETREF] =              ES_MAX_HZ_ENETREF,
        [DEV_SM_CLK_ENETTIMER1] =           ES_MAX_HZ_ENETTIMER1,
        [DEV_SM_CLK_ENETTIMER2] =           ES_MAX_HZ_ENETTIMER2,
        [DEV_SM_CLK_ENETTIMER3] =           ES_MAX_HZ_ENETTIMER3,
        [DEV_SM_CLK_FLEXIO3] =              ES_MAX_HZ_FLEXIO3,
        [DEV_SM_CLK_FLEXIO4] =              ES_MAX_HZ_FLEXIO4,
        [DEV_SM_CLK_M33SYNC] =              ES_MAX_HZ_M33SYNC,
        [DEV_SM_CLK_M33SYNCSYSTICK] =       ES_MAX_HZ_M33SYNCSYSTICK,
        [DEV_SM_CLK_MAC0] =                 ES_MAX_HZ_MAC0,
        [DEV_SM_CLK_MAC1] =                 ES_MAX_HZ_MAC1,
        [DEV_SM_CLK_MAC2] =                 ES_MAX_HZ_MAC2,
        [DEV_SM_CLK_MAC3] =                 ES_MAX_HZ_MAC3,
        [DEV_SM_CLK_MAC4] =                 ES_MAX_HZ_MAC4,
        [DEV_SM_CLK_MAC5] =                 ES_MAX_HZ_MAC5,
        [DEV_SM_CLK_NOCAPB] =               ES_MAX_HZ_NOCAPB,
        [DEV_SM_CLK_NOC] =                  ES_MAX_HZ_NOC,
        [DEV_SM_CLK_NPUAPB] =               ES_MAX_HZ_NPUAPB,
        [DEV_SM_CLK_NPU] =                  ES_MAX_HZ_NPU,
        [DEV_SM_CLK_CCMCKO1] =              ES_MAX_HZ_CCMCKO1,
        [DEV_SM_CLK_CCMCKO2] =              ES_MAX_HZ_CCMCKO2,
        [DEV_SM_CLK_CCMCKO3] =              ES_MAX_HZ_CCMCKO3,
        [DEV_SM_CLK_CCMCKO4] =              ES_MAX_HZ_CCMCKO4,
        [DEV_SM_CLK_BISS] =                 ES_MAX_HZ_CCMWAKEUPMIXBISS,
        [DEV_SM_CLK_BUSWAKEUP] =            ES_MAX_HZ_BUSWAKEUP,
        [DEV_SM_CLK_CAN2] =                 ES_MAX_HZ_CAN2,
        [DEV_SM_CLK_CAN3] =                 ES_MAX_HZ_CAN3,
        [DEV_SM_CLK_CAN4] =                 ES_MAX_HZ_CAN4,
        [DEV_SM_CLK_CAN5] =                 ES_MAX_HZ_CAN5,
        [DEV_SM_CLK_ENDAT21] =              ES_MAX_HZ_ENDAT21,
        [DEV_SM_CLK_ENDAT22] =              ES_MAX_HZ_ENDAT22,
        [DEV_SM_CLK_ENDAT31FAST] =          ES_MAX_HZ_ENDAT31FAST,
        [DEV_SM_CLK_ENDAT31SLOW] =          ES_MAX_HZ_ENDAT31SLOW,
        [DEV_SM_CLK_FLEXIO1] =              ES_MAX_HZ_FLEXIO1,
        [DEV_SM_CLK_FLEXIO2] =              ES_MAX_HZ_FLEXIO2,
        [DEV_SM_CLK_GPT2] =                 ES_MAX_HZ_GPT2,
        [DEV_SM_CLK_GPT3] =                 ES_MAX_HZ_GPT3,
        [DEV_SM_CLK_GPT4] =                 ES_MAX_HZ_GPT4,
        [DEV_SM_CLK_HIPERFACE1] =           ES_MAX_HZ_HIPERFACE1,
        [DEV_SM_CLK_HIPERFACE1SYNC] =       ES_MAX_HZ_HIPERFACE1SYNC,
        [DEV_SM_CLK_HIPERFACE2] =           ES_MAX_HZ_HIPERFACE2,
        [DEV_SM_CLK_HIPERFACE2SYNC] =       ES_MAX_HZ_HIPERFACE2SYNC,
        [DEV_SM_CLK_I3C2SLOW] =             ES_MAX_HZ_I3C2SLOW,
        [DEV_SM_CLK_LPI2C3] =               ES_MAX_HZ_LPI2C3,
        [DEV_SM_CLK_LPI2C4] =               ES_MAX_HZ_LPI2C4,
        [DEV_SM_CLK_LPI2C5] =               ES_MAX_HZ_LPI2C5,
        [DEV_SM_CLK_LPI2C6] =               ES_MAX_HZ_LPI2C6,
        [DEV_SM_CLK_LPI2C7] =               ES_MAX_HZ_LPI2C7,
        [DEV_SM_CLK_LPI2C8] =               ES_MAX_HZ_LPI2C8,
        [DEV_SM_CLK_LPSPI3] =               ES_MAX_HZ_LPSPI3,
        [DEV_SM_CLK_LPSPI4] =               ES_MAX_HZ_LPSPI4,
        [DEV_SM_CLK_LPSPI5] =               ES_MAX_HZ_LPSPI5,
        [DEV_SM_CLK_LPSPI6] =               ES_MAX_HZ_LPSPI6,
        [DEV_SM_CLK_LPSPI7] =               ES_MAX_HZ_LPSPI7,
        [DEV_SM_CLK_LPSPI8] =               ES_MAX_HZ_LPSPI8,
        [DEV_SM_CLK_LPTMR2] =               ES_MAX_HZ_LPTMR2,
        [DEV_SM_CLK_LPUART10] =             ES_MAX_HZ_LPUART10,
        [DEV_SM_CLK_LPUART11] =             ES_MAX_HZ_LPUART11,
        [DEV_SM_CLK_LPUART12] =             ES_MAX_HZ_LPUART12,
        [DEV_SM_CLK_LPUART3] =              ES_MAX_HZ_LPUART3,
        [DEV_SM_CLK_LPUART4] =              ES_MAX_HZ_LPUART4,
        [DEV_SM_CLK_LPUART5] =              ES_MAX_HZ_LPUART5,
        [DEV_SM_CLK_LPUART6] =              ES_MAX_HZ_LPUART6,
        [DEV_SM_CLK_LPUART7] =              ES_MAX_HZ_LPUART7,
        [DEV_SM_CLK_LPUART8] =              ES_MAX_HZ_LPUART8,
        [DEV_SM_CLK_LPUART9] =              ES_MAX_HZ_LPUART9,
        [DEV_SM_CLK_SAI2] =                 ES_MAX_HZ_SAI2,
        [DEV_SM_CLK_SAI3] =                 ES_MAX_HZ_SAI3,
        [DEV_SM_CLK_SAI4] =                 ES_MAX_HZ_SAI4,
        [DEV_SM_CLK_SWOTRACE] =             ES_MAX_HZ_SWOTRACE,
        [DEV_SM_CLK_TPM4] =                 ES_MAX_HZ_TPM4,
        [DEV_SM_CLK_TPM5] =                 ES_MAX_HZ_TPM5,
        [DEV_SM_CLK_TPM6] =                 ES_MAX_HZ_TPM6,
        [DEV_SM_CLK_USBPHYBURUNIN] =        ES_MAX_HZ_USBPHYBURUNIN,
        [DEV_SM_CLK_USDHC1] =               ES_MAX_HZ_USDHC1,
        [DEV_SM_CLK_USDHC2] =               ES_MAX_HZ_USDHC2,
        [DEV_SM_CLK_USDHC3] =               ES_MAX_HZ_USDHC3,
        [DEV_SM_CLK_V2XPK] =                ES_MAX_HZ_V2XPK,
        [DEV_SM_CLK_WAKEUPAXI] =            ES_MAX_HZ_WAKEUPAXI,
        [DEV_SM_CLK_XSPISLVROOT] =          ES_MAX_HZ_XSPISLVROOT,
        [DEV_SM_CLK_XSPI1] =                ES_MAX_HZ_XSPI1,
        [DEV_SM_CLK_XSPI2] =                ES_MAX_HZ_XSPI2,

        [DEV_SM_CLK_EXT_GPR_SEL] =          ES_MAX_HZ_EXT1,
        [DEV_SM_CLK_A55C0_GPR_SEL] =        ES_MAX_HZ_PFD,
        [DEV_SM_CLK_A55C1_GPR_SEL] =        ES_MAX_HZ_PFD,
        [DEV_SM_CLK_A55C2_GPR_SEL] =        ES_MAX_HZ_PFD,
        [DEV_SM_CLK_A55C3_GPR_SEL] =        ES_MAX_HZ_PFD,
        [DEV_SM_CLK_A55P_GPR_SEL] =         ES_MAX_HZ_PFD,
        [DEV_SM_CLK_DRAM_GPR_SEL] =         ES_MAX_HZ_DRAMPLL,
        [DEV_SM_CLK_TEMPSENSE_GPR_SEL] =    ES_MAX_HZ_FRO,

        [DEV_SM_CLK_NPU_CGC] =              ES_MAX_HZ_NPU
    };

    static uint64_t const s_lowestRateHz[DEV_SM_NUM_CLOCK] =
    {
        [DEV_SM_CLK_EXT] =                  ES_MIN_HZ_EXT1,
        [DEV_SM_CLK_OSC32K] =               ES_MIN_HZ_OSC32K,
        [DEV_SM_CLK_OSC24M] =               ES_MIN_HZ_OSC24M,
        [DEV_SM_CLK_FRO] =                  ES_MIN_HZ_FRO,
        [DEV_SM_CLK_SYSPLL1_VCO] =          ES_MIN_HZ_PLLVCO,
        [DEV_SM_CLK_SYSPLL1_PFD0_UNGATED] = ES_MIN_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD0] =         ES_MIN_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD0_DIV2] =    ES_MIN_HZ_PFD / 2U,
        [DEV_SM_CLK_SYSPLL1_PFD1_UNGATED] = ES_MIN_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD1] =         ES_MIN_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD1_DIV2] =    ES_MIN_HZ_PFD / 2U,
        [DEV_SM_CLK_SYSPLL1_PFD2_UNGATED] = ES_MIN_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD2] =         ES_MIN_HZ_PFD,
        [DEV_SM_CLK_SYSPLL1_PFD2_DIV2] =    ES_MIN_HZ_PFD / 2U,
        [DEV_SM_CLK_AUDIOPLL1_VCO] =        ES_MIN_HZ_PLLVCO,
        [DEV_SM_CLK_AUDIOPLL1] =            ES_MIN_HZ_AUDIOPLL,
        [DEV_SM_CLK_AUDIOPLL2_VCO] =        ES_MIN_HZ_PLLVCO,
        [DEV_SM_CLK_AUDIOPLL2] =            ES_MIN_HZ_AUDIOPLL,
        [DEV_SM_CLK_ENCPLL_VCO] =           ES_MIN_HZ_PLLVCO,
        [DEV_SM_CLK_ENCPLL_PFD0_UNGATED] =  ES_MIN_HZ_PFD,
        [DEV_SM_CLK_ENCPLL_PFD0] =          ES_MIN_HZ_PFD,
        [DEV_SM_CLK_ENCPLL_PFD1_UNGATED] =  ES_MIN_HZ_PFD,
        [DEV_SM_CLK_ENCPLL_PFD1] =          ES_MIN_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_VCO] =           ES_MIN_HZ_PLLVCO,
        [DEV_SM_CLK_ARMPLL_PFD0_UNGATED] =  ES_MIN_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD0] =          ES_MIN_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD1_UNGATED] =  ES_MIN_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD1] =          ES_MIN_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD2_UNGATED] =  ES_MIN_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD2] =          ES_MIN_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD3_UNGATED] =  ES_MIN_HZ_PFD,
        [DEV_SM_CLK_ARMPLL_PFD3] =          ES_MIN_HZ_PFD,
        [DEV_SM_CLK_DRAMPLL_VCO] =          ES_MIN_HZ_PLLVCO,
        [DEV_SM_CLK_DRAMPLL] =              ES_MIN_HZ_DRAMPLL,
        [DEV_SM_CLK_HSIOPLL_VCO] =          ES_MIN_HZ_PLLVCO,
        [DEV_SM_CLK_HSIOPLL] =              ES_MIN_HZ_HSIOPLL,
        [DEV_SM_CLK_LDBPLL_VCO] =           ES_MIN_HZ_PLLVCO,
        [DEV_SM_CLK_LDBPLL] =               ES_MIN_HZ_LDBPLL,
        [DEV_SM_CLK_EXT1] =                 ES_MIN_HZ_EXT1,
        [DEV_SM_CLK_EXT2] =                 ES_MIN_HZ_GND,

        [DEV_SM_CLK_ADC] =                  ES_MIN_HZ_ADC,
        [DEV_SM_CLK_BUSAON] =               ES_MIN_HZ_BUSAON,
        [DEV_SM_CLK_CAN1] =                 ES_MIN_HZ_CAN1,
        [DEV_SM_CLK_GLITCHFILTER] =         ES_MIN_HZ_GLITCHFILTER,
        [DEV_SM_CLK_I3C1SLOW] =             ES_MIN_HZ_I3C1SLOW,
        [DEV_SM_CLK_LPI2C1] =               ES_MIN_HZ_LPI2C1,
        [DEV_SM_CLK_LPI2C2] =               ES_MIN_HZ_LPI2C2,
        [DEV_SM_CLK_LPSPI1] =               ES_MIN_HZ_LPSPI1,
        [DEV_SM_CLK_LPSPI2] =               ES_MIN_HZ_LPSPI2,
        [DEV_SM_CLK_LPTMR1] =               ES_MIN_HZ_LPTMR1,
        [DEV_SM_CLK_LPUART1] =              ES_MIN_HZ_LPUART1,
        [DEV_SM_CLK_LPUART2] =              ES_MIN_HZ_LPUART2,
        [DEV_SM_CLK_M33] =                  ES_MIN_HZ_M33,
        [DEV_SM_CLK_M33SYSTICK] =           ES_MIN_HZ_M33SYSTICK,
        [DEV_SM_CLK_PDM] =                  ES_MIN_HZ_PDM,
        [DEV_SM_CLK_SAI1] =                 ES_MIN_HZ_SAI1,
        [DEV_SM_CLK_TPM2] =                 ES_MIN_HZ_TPM2,
        [DEV_SM_CLK_A55] =                  ES_MIN_HZ_A55,
        [DEV_SM_CLK_A55MTRBUS] =            ES_MIN_HZ_A55MTRBUS,
        [DEV_SM_CLK_A55PERIPH] =            ES_MIN_HZ_A55PERIPH,
        [DEV_SM_CLK_DRAMALT] =              ES_MIN_HZ_DRAMALT,
        [DEV_SM_CLK_DRAMAPB] =              ES_MIN_HZ_DRAMAPB,
        [DEV_SM_CLK_DISPAPB] =              ES_MIN_HZ_DISPAPB,
        [DEV_SM_CLK_DISPAXI] =              ES_MIN_HZ_DISPAXI,
        [DEV_SM_CLK_DISPPIX] =              ES_MIN_HZ_DISPPIX,
        [DEV_SM_CLK_HSIOACSCAN480M] =       ES_MIN_HZ_HSIOACSCAN480M,
        [DEV_SM_CLK_HSIOACSCAN80M] =        ES_MIN_HZ_HSIOACSCAN80M,
        [DEV_SM_CLK_HSIO] =                 ES_MIN_HZ_HSIO,
        [DEV_SM_CLK_HSIOPCIEAUX] =          ES_MIN_HZ_HSIOPCIEAUX,
        [DEV_SM_CLK_HSIOPCIETEST160M] =     ES_MIN_HZ_HSIOPCIETEST160M,
        [DEV_SM_CLK_HSIOPCIETEST400M] =     ES_MIN_HZ_HSIOPCIETEST400M,
        [DEV_SM_CLK_HSIOPCIETEST500M] =     ES_MIN_HZ_HSIOPCIETEST500M,
        [DEV_SM_CLK_HSIOPCIETEST50M] =      ES_MIN_HZ_HSIOPCIETEST50M,
        [DEV_SM_CLK_HSIOUSBTEST60M] =       ES_MIN_HZ_HSIOUSBTEST60M,
        [DEV_SM_CLK_BUSM70] =               ES_MIN_HZ_BUSM7,
        [DEV_SM_CLK_M70] =                  ES_MIN_HZ_M7,
        [DEV_SM_CLK_M70SYSTICK] =           ES_MIN_HZ_M7SYSTICK,
        [DEV_SM_CLK_BUSM71] =               ES_MIN_HZ_BUSM7,
        [DEV_SM_CLK_M71] =                  ES_MIN_HZ_M7,
        [DEV_SM_CLK_M71SYSTICK] =           ES_MIN_HZ_M7SYSTICK,
        [DEV_SM_CLK_BUSNETCMIX] =           ES_MIN_HZ_BUSNETCMIX,
        [DEV_SM_CLK_ECAT] =                 ES_MIN_HZ_ECAT,
        [DEV_SM_CLK_ENET] =                 ES_MIN_HZ_ENET,
        [DEV_SM_CLK_ENETPHYTEST200M] =      ES_MIN_HZ_ENETPHYTEST200M,
        [DEV_SM_CLK_ENETPHYTEST500M] =      ES_MIN_HZ_ENETPHYTEST500M,
        [DEV_SM_CLK_ENETPHYTEST667M] =      ES_MIN_HZ_ENETPHYTEST667M,
        [DEV_SM_CLK_ENETREF] =              ES_MIN_HZ_ENETREF,
        [DEV_SM_CLK_ENETTIMER1] =           ES_MIN_HZ_ENETTIMER1,
        [DEV_SM_CLK_ENETTIMER2] =           ES_MIN_HZ_ENETTIMER2,
        [DEV_SM_CLK_ENETTIMER3] =           ES_MIN_HZ_ENETTIMER3,
        [DEV_SM_CLK_FLEXIO3] =              ES_MIN_HZ_FLEXIO3,
        [DEV_SM_CLK_FLEXIO4] =              ES_MIN_HZ_FLEXIO4,
        [DEV_SM_CLK_M33SYNC] =              ES_MIN_HZ_M33SYNC,
        [DEV_SM_CLK_M33SYNCSYSTICK] =       ES_MIN_HZ_M33SYNCSYSTICK,
        [DEV_SM_CLK_MAC0] =                 ES_MIN_HZ_MAC0,
        [DEV_SM_CLK_MAC1] =                 ES_MIN_HZ_MAC1,
        [DEV_SM_CLK_MAC2] =                 ES_MIN_HZ_MAC2,
        [DEV_SM_CLK_MAC3] =                 ES_MIN_HZ_MAC3,
        [DEV_SM_CLK_MAC4] =                 ES_MIN_HZ_MAC4,
        [DEV_SM_CLK_MAC5] =                 ES_MIN_HZ_MAC5,
        [DEV_SM_CLK_NOCAPB] =               ES_MIN_HZ_NOCAPB,
        [DEV_SM_CLK_NOC] =                  ES_MIN_HZ_NOC,
        [DEV_SM_CLK_NPUAPB] =               ES_MIN_HZ_NPUAPB,
        [DEV_SM_CLK_NPU] =                  ES_MIN_HZ_NPU,
        [DEV_SM_CLK_CCMCKO1] =              ES_MIN_HZ_CCMCKO1,
        [DEV_SM_CLK_CCMCKO2] =              ES_MIN_HZ_CCMCKO2,
        [DEV_SM_CLK_CCMCKO3] =              ES_MIN_HZ_CCMCKO3,
        [DEV_SM_CLK_CCMCKO4] =              ES_MIN_HZ_CCMCKO4,
        [DEV_SM_CLK_BISS] =                 ES_MIN_HZ_CCMWAKEUPMIXBISS,
        [DEV_SM_CLK_BUSWAKEUP] =            ES_MIN_HZ_BUSWAKEUP,
        [DEV_SM_CLK_CAN2] =                 ES_MIN_HZ_CAN2,
        [DEV_SM_CLK_CAN3] =                 ES_MIN_HZ_CAN3,
        [DEV_SM_CLK_CAN4] =                 ES_MIN_HZ_CAN4,
        [DEV_SM_CLK_CAN5] =                 ES_MIN_HZ_CAN5,
        [DEV_SM_CLK_ENDAT21] =              ES_MIN_HZ_ENDAT21,
        [DEV_SM_CLK_ENDAT22] =              ES_MIN_HZ_ENDAT22,
        [DEV_SM_CLK_ENDAT31FAST] =          ES_MIN_HZ_ENDAT31FAST,
        [DEV_SM_CLK_ENDAT31SLOW] =          ES_MIN_HZ_ENDAT31SLOW,
        [DEV_SM_CLK_FLEXIO1] =              ES_MIN_HZ_FLEXIO1,
        [DEV_SM_CLK_FLEXIO2] =              ES_MIN_HZ_FLEXIO2,
        [DEV_SM_CLK_GPT2] =                 ES_MIN_HZ_GPT2,
        [DEV_SM_CLK_GPT3] =                 ES_MIN_HZ_GPT3,
        [DEV_SM_CLK_GPT4] =                 ES_MIN_HZ_GPT4,
        [DEV_SM_CLK_HIPERFACE1] =           ES_MIN_HZ_HIPERFACE1,
        [DEV_SM_CLK_HIPERFACE1SYNC] =       ES_MIN_HZ_HIPERFACE1SYNC,
        [DEV_SM_CLK_HIPERFACE2] =           ES_MIN_HZ_HIPERFACE2,
        [DEV_SM_CLK_HIPERFACE2SYNC] =       ES_MIN_HZ_HIPERFACE2SYNC,
        [DEV_SM_CLK_I3C2SLOW] =             ES_MIN_HZ_I3C2SLOW,
        [DEV_SM_CLK_LPI2C3] =               ES_MIN_HZ_LPI2C3,
        [DEV_SM_CLK_LPI2C4] =               ES_MIN_HZ_LPI2C4,
        [DEV_SM_CLK_LPI2C5] =               ES_MIN_HZ_LPI2C5,
        [DEV_SM_CLK_LPI2C6] =               ES_MIN_HZ_LPI2C6,
        [DEV_SM_CLK_LPI2C7] =               ES_MIN_HZ_LPI2C7,
        [DEV_SM_CLK_LPI2C8] =               ES_MIN_HZ_LPI2C8,
        [DEV_SM_CLK_LPSPI3] =               ES_MIN_HZ_LPSPI3,
        [DEV_SM_CLK_LPSPI4] =               ES_MIN_HZ_LPSPI4,
        [DEV_SM_CLK_LPSPI5] =               ES_MIN_HZ_LPSPI5,
        [DEV_SM_CLK_LPSPI6] =               ES_MIN_HZ_LPSPI6,
        [DEV_SM_CLK_LPSPI7] =               ES_MIN_HZ_LPSPI7,
        [DEV_SM_CLK_LPSPI8] =               ES_MIN_HZ_LPSPI8,
        [DEV_SM_CLK_LPTMR2] =               ES_MIN_HZ_LPTMR2,
        [DEV_SM_CLK_LPUART10] =             ES_MIN_HZ_LPUART10,
        [DEV_SM_CLK_LPUART11] =             ES_MIN_HZ_LPUART11,
        [DEV_SM_CLK_LPUART12] =             ES_MIN_HZ_LPUART12,
        [DEV_SM_CLK_LPUART3] =              ES_MIN_HZ_LPUART3,
        [DEV_SM_CLK_LPUART4] =              ES_MIN_HZ_LPUART4,
        [DEV_SM_CLK_LPUART5] =              ES_MIN_HZ_LPUART5,
        [DEV_SM_CLK_LPUART6] =              ES_MIN_HZ_LPUART6,
        [DEV_SM_CLK_LPUART7] =              ES_MIN_HZ_LPUART7,
        [DEV_SM_CLK_LPUART8] =              ES_MIN_HZ_LPUART8,
        [DEV_SM_CLK_LPUART9] =              ES_MIN_HZ_LPUART9,
        [DEV_SM_CLK_SAI2] =                 ES_MIN_HZ_SAI2,
        [DEV_SM_CLK_SAI3] =                 ES_MIN_HZ_SAI3,
        [DEV_SM_CLK_SAI4] =                 ES_MIN_HZ_SAI4,
        [DEV_SM_CLK_SWOTRACE] =             ES_MIN_HZ_SWOTRACE,
        [DEV_SM_CLK_TPM4] =                 ES_MIN_HZ_TPM4,
        [DEV_SM_CLK_TPM5] =                 ES_MIN_HZ_TPM5,
        [DEV_SM_CLK_TPM6] =                 ES_MIN_HZ_TPM6,
        [DEV_SM_CLK_USBPHYBURUNIN] =        ES_MIN_HZ_USBPHYBURUNIN,
        [DEV_SM_CLK_USDHC1] =               ES_MIN_HZ_USDHC1,
        [DEV_SM_CLK_USDHC2] =               ES_MIN_HZ_USDHC2,
        [DEV_SM_CLK_USDHC3] =               ES_MIN_HZ_USDHC3,
        [DEV_SM_CLK_V2XPK] =                ES_MIN_HZ_V2XPK,
        [DEV_SM_CLK_WAKEUPAXI] =            ES_MIN_HZ_WAKEUPAXI,
        [DEV_SM_CLK_XSPISLVROOT] =          ES_MIN_HZ_XSPISLVROOT,
        [DEV_SM_CLK_XSPI1] =                ES_MIN_HZ_XSPI1,
        [DEV_SM_CLK_XSPI2] =                ES_MIN_HZ_XSPI2,

        [DEV_SM_CLK_EXT_GPR_SEL] =          ES_MIN_HZ_EXT1,
        [DEV_SM_CLK_A55C0_GPR_SEL] =        ES_MIN_HZ_ROOT,
        [DEV_SM_CLK_A55C1_GPR_SEL] =        ES_MIN_HZ_ROOT,
        [DEV_SM_CLK_A55C2_GPR_SEL] =        ES_MIN_HZ_ROOT,
        [DEV_SM_CLK_A55C3_GPR_SEL] =        ES_MIN_HZ_ROOT,
        [DEV_SM_CLK_A55P_GPR_SEL] =         ES_MIN_HZ_ROOT,
        [DEV_SM_CLK_DRAM_GPR_SEL] =         ES_MIN_HZ_ROOT,
        [DEV_SM_CLK_TEMPSENSE_GPR_SEL] =    ES_MIN_HZ_OSC24M,

        [DEV_SM_CLK_NPU_CGC] =              ES_MIN_HZ_NPU
    };

    /* Check clock */
    if (!DEV_SM_ClockIsReserved(clockId))
    {
        /* Return range */
        range->lowestRate = s_lowestRateHz[clockId];
        range->highestRate = s_highestRateHz[clockId];
        range->stepSize = 1UL;

        status = SM_ERR_SUCCESS;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return clock parent info                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockParentDescribe(uint32_t clockId, uint32_t sel,
    uint32_t *parentId, uint32_t *numParents)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else if (clockId < CLOCK_NUM_SRC)
    {
        /* Query if clock source has a parent */
        if (CLOCK_SourceGetParent(clockId, parentId))
        {
            /* Clock sources have at most a single parent */
            if (sel >= 1U)
            {
                status = SM_ERR_OUT_OF_RANGE;
            }
            else
            {
                *numParents = 1U;
            }
        }
        else
        {
            status = SM_ERR_NOT_SUPPORTED;
        }
    }
    else
    {
        uint32_t clockIndex = clockId - CLOCK_NUM_SRC;

        if (clockIndex < CLOCK_NUM_ROOT)
        {
            /* Query number of parents */
            /*
             * The clockIndex parameter is already validated
             * against CLOCK_NUM_ROOT, so this function will
             * never return an error
             */
            /* gcov_excl_multiline 5 */
            if (!CCM_RootMuxNumInputsGet(clockIndex, numParents))
            {
                status = SM_ERR_NOT_FOUND;
            }
            else
            {
                /* Check if sel exceeds number of parents */
                if (sel >= *numParents)
                {
                    status = SM_ERR_OUT_OF_RANGE;
                }
                else
                {
                    /* Query specified parent */
                    /* gcov_excl_ntbr_nextline */
                    if (!CCM_RootMuxInputGet(clockIndex, sel, parentId))
                    {
                        status = SM_ERR_NOT_FOUND;  /* gcov_excl_line */
                    }
                }
            }
        }
        else
        {
            clockIndex = clockIndex - CLOCK_NUM_ROOT;

            if (clockIndex < CLOCK_NUM_GPR_SEL)
            {
                /* Query number of parents */
                /*
                 * The clockIndex parameter is already validated
                 * against NUM_GPR_CLOCK, so this function will
                 * never return an error
                 */
                /* gcov_excl_multiline 5 */
                if (!CCM_GprSelMuxNumInputsGet(clockIndex, numParents))
                {
                    status = SM_ERR_NOT_FOUND;
                }
                else
                {
                    /* Check if sel exceeds number of parents */
                    if (sel >= *numParents)
                    {
                        status = SM_ERR_OUT_OF_RANGE;
                    }
                    else
                    {
                        /* Query specified parent */
                        /*
                         * The funtion parameters are already validated
                         * against the max values, so this condition will
                         * never hit
                         */
                        /* gcov_excl_multiline 5 */
                        if (!CCM_GprSelMuxInputGet(clockIndex, sel,
                            parentId))
                        {
                            status = SM_ERR_NOT_FOUND;
                        }
                    }
                }
            }
            else
            {
                clockIndex = clockIndex - CLOCK_NUM_GPR_SEL;

                /*
                 * The clockIndex parameter is already validated
                 * against NUM_GPR_CLOCK, so this function will
                 * never return an error
                 */
                /* gcov_excl_ntbr_nextline */
                if (clockIndex < CLOCK_NUM_CGC)
                {
                    /* Query if CGC has a parent */
                    uint32_t rootIdx;

                    /*
                     * The clockIndex parameter is already validated
                     * against CLOCK_NUM_CGC, so this statement will
                     * never execute
                     */
                    /* gcov_excl_ntbr_nextline */
                    if (CCM_CgcGetParent(clockIndex, &rootIdx))
                    {
                        /* CGCs have at most a single parent */
                        if (sel >= 1U)
                        {
                            status = SM_ERR_OUT_OF_RANGE;
                        }
                        else
                        {
                            *parentId = rootIdx + CLOCK_NUM_SRC;
                            *numParents = 1U;
                        }
                    }
                    else
                    {
                        status = SM_ERR_NOT_FOUND; /* gcov_excl_line  */
                    }
                }
                else
                {
                    status = SM_ERR_NOT_FOUND; /* gcov_excl_line  */
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set clock rate                                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockRateSet(uint32_t clockId, uint64_t rate,
    uint32_t roundSel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else if (clockId < CLOCK_NUM_SRC)
    {
        switch (roundSel)
        {
            case DEV_SM_CLOCK_ROUND_DOWN:
                if (!CLOCK_SourceSetRate(clockId, rate,
                    CLOCK_ROUND_RULE_CEILING))
                {
                    status = SM_ERR_INVALID_PARAMETERS;
                }
                break;

            case DEV_SM_CLOCK_ROUND_UP:
                if (!CLOCK_SourceSetRate(clockId, rate,
                    CLOCK_ROUND_RULE_FLOOR))
                {
                    status = SM_ERR_INVALID_PARAMETERS;
                }
                break;

            case DEV_SM_CLOCK_ROUND_AUTO:
                if (!CLOCK_SourceSetRate(clockId, rate,
                    CLOCK_ROUND_RULE_CLOSEST))
                {
                    status = SM_ERR_INVALID_PARAMETERS;
                }
                break;

            default:
                status = SM_ERR_INVALID_PARAMETERS;
                break;
        }
    }
    else
    {
        uint32_t clockIndex = clockId - CLOCK_NUM_SRC;

        if (clockIndex < CLOCK_NUM_ROOT)
        {
            switch (roundSel)
            {
                case DEV_SM_CLOCK_ROUND_DOWN:
                    if (!CCM_RootSetRate(clockIndex, rate,
                        CLOCK_ROUND_RULE_CEILING))
                    {
                        status = SM_ERR_INVALID_PARAMETERS;
                    }
                    break;

                case DEV_SM_CLOCK_ROUND_UP:
                    if (!CCM_RootSetRate(clockIndex, rate,
                        CLOCK_ROUND_RULE_FLOOR))
                    {
                        status = SM_ERR_INVALID_PARAMETERS;
                    }
                    break;

                case DEV_SM_CLOCK_ROUND_AUTO:
                    if (!CCM_RootSetRate(clockIndex, rate,
                        CLOCK_ROUND_RULE_CLOSEST))
                    {
                        status = SM_ERR_INVALID_PARAMETERS;
                    }
                    break;

                default:
                    status = SM_ERR_INVALID_PARAMETERS;
                    break;
            }
        }
        else
        {
            clockIndex = clockIndex - CLOCK_NUM_ROOT;

            if (clockIndex < CLOCK_NUM_GPR_SEL)
            {
                status = SM_ERR_INVALID_PARAMETERS;
            }
            else
            {
                clockIndex = clockIndex - CLOCK_NUM_GPR_SEL;

                /*
                 * The condition for the MAX clock index has already
                 * been validated.
                 */
                /* gcov_excl_ntbr_nextline */
                if (clockIndex < CLOCK_NUM_CGC)
                {
                    status = SM_ERR_INVALID_PARAMETERS;
                }
                else
                {
                    status = SM_ERR_NOT_FOUND; /* gcov_excl_line  */
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get clock rate                                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockRateGet(uint32_t clockId, uint64_t *rate)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else if (clockId < CLOCK_NUM_SRC)
    {
        *rate = CLOCK_SourceGetRate(clockId);
    }
    else
    {
        uint32_t clockIndex = clockId - CLOCK_NUM_SRC;

        if (clockIndex < CLOCK_NUM_ROOT)
        {
            *rate = CCM_RootGetRate(clockIndex);
        }
        else
        {
            clockIndex = clockIndex - CLOCK_NUM_ROOT;

            if (clockIndex < CLOCK_NUM_GPR_SEL)
            {
                *rate = CCM_GprSelGetRate(clockIndex);
            }
            else
            {
                clockIndex = clockIndex - CLOCK_NUM_GPR_SEL;

                /*
                 * The condition for the MAX clock index has already
                 * been validated.
                 */
                /* gcov_excl_ntbr_nextline */
                if (clockIndex < CLOCK_NUM_CGC)
                {
                    *rate = CCM_CgcGetRate(clockIndex);
                }
                else
                {
                    status = SM_ERR_NOT_FOUND; /* gcov_excl_line  */
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable clock                                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockEnable(uint32_t clockId, bool enable)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else if (clockId < CLOCK_NUM_SRC)
    {
        /* Disable bypass when enabling clock source */
        if (enable)
        {
            /*
             * Returning false from the underlying driver function
             * is not feasible because the clock index has already
             * been validated against the maximum available clock sources.
             */
            /* gcov_excl_ntbr_nextline */
            if (!CLOCK_SourceSetBypass(clockId, false))
            {
                status = SM_ERR_INVALID_PARAMETERS; /* gcov_excl_line */
            }
        }
        if (status == SM_ERR_SUCCESS)
        {
            /*
             * Returning false from the underlying driver function
             * is not feasible because the clock index has already
             * been validated against the maximum available clock sources.
             */
            /* gcov_excl_ntbr_nextline */
            if (!CLOCK_SourceSetEnable(clockId, enable))
            {
                status = SM_ERR_INVALID_PARAMETERS; /* gcov_excl_line */
            }
        }
        /* Enable bypass when disabling clock source */
        /* gcov_excl_ntbr_nextline */
        if ((status == SM_ERR_SUCCESS) && !enable)
        {
            /*
             * Returning false from the underlying driver function
             * is not feasible because the clock index has already
             * been validated against the maximum available clock sources.
             */
            /* gcov_excl_ntbr_nextline */
            if (!CLOCK_SourceSetBypass(clockId, true))
            {
                status = SM_ERR_INVALID_PARAMETERS; /* gcov_excl_line */
            }
        }
    }
    else
    {
        uint32_t clockIndex = clockId - CLOCK_NUM_SRC;

        if (clockIndex < CLOCK_NUM_ROOT)
        {
            /* Reject clock disable if associated LPI active */
            if (!enable && CLOCK_RootLpiIsActive(clockIndex))
            {
                status = SM_ERR_HARDWARE_ERROR;
            }
            else
            {
                /*
                 * Returning false from the underlying driver function
                 * is not feasible because the clock index has already
                 * been validated against the maximum clock roots.
                 */
                /* gcov_excl_ntbr_nextline */
                if (!CCM_RootSetEnable(clockIndex, enable))
                {
                    status = SM_ERR_INVALID_PARAMETERS; /* gcov_excl_line */
                }
            }
        }
        else
        {
            clockIndex = clockIndex - CLOCK_NUM_ROOT;

            /*
             * Returning false from the underlying driver function
             * is not feasible because the clock index has already
             * been validated against the maximum GPR sel.
             */
            /* gcov_excl_ntbr_nextline */
            if (clockIndex < CLOCK_NUM_GPR_SEL)
            {
                status = SM_ERR_INVALID_PARAMETERS; /* gcov_excl_line */
            }
            else
            {
                clockIndex = clockIndex - CLOCK_NUM_GPR_SEL;

                /*
                 * Returning false from the underlying driver function
                 * is not feasible because the clock index has already
                 * been validated against the maximum cgc clocks.
                 */
                /* gcov_excl_multiline 11 */
                if (clockIndex < CLOCK_NUM_CGC)
                {
                    if (!CCM_CgcSetEnable(clockIndex, enable))
                    {
                        status = SM_ERR_INVALID_PARAMETERS;
                    }
                }
                else
                {
                    status = SM_ERR_NOT_FOUND;
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return clock enable status                                               */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockIsEnabled(uint32_t clockId, bool *enabled)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else if (clockId < CLOCK_NUM_SRC)
    {
        *enabled = CLOCK_SourceGetEnable(clockId);
    }
    else
    {
        uint32_t clockIndex = clockId - CLOCK_NUM_SRC;

        if (clockIndex < CLOCK_NUM_ROOT)
        {
            *enabled = CCM_RootGetEnable(clockIndex);
        }
        else
        {
            clockIndex = clockIndex - CLOCK_NUM_ROOT;

            if (clockIndex < CLOCK_NUM_GPR_SEL)
            {
                *enabled = CCM_GprSelGetEnable(clockIndex);
            }
            else
            {
                clockIndex = clockIndex - CLOCK_NUM_GPR_SEL;

                /*
                 * The condition for the MAX clock index has already
                 * been validated.
                 */
                /* gcov_excl_ntbr_nextline */
                if (clockIndex < CLOCK_NUM_CGC)
                {
                    *enabled = CCM_CgcGetEnable(clockIndex);
                }
                else
                {
                    status = SM_ERR_NOT_FOUND; /* gcov_excl_line */
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set clock parent                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockParentSet(uint32_t clockId, uint32_t parent)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else if (clockId < CLOCK_NUM_SRC)
    {
        if (!CLOCK_SourceSetParent(clockId, parent))
        {
            status = SM_ERR_INVALID_PARAMETERS;
        }
    }
    else
    {
        uint32_t clockIndex = clockId - CLOCK_NUM_SRC;

        if (clockIndex < CLOCK_NUM_ROOT)
        {
            if (!CCM_RootSetParent(clockIndex, parent))
            {
                status = SM_ERR_INVALID_PARAMETERS;
            }
        }
        else
        {
            clockIndex = clockIndex - CLOCK_NUM_ROOT;

            if (clockIndex < CLOCK_NUM_GPR_SEL)
            {
                if (!CCM_GprSelSetParent(clockIndex, parent))
                {
                    status = SM_ERR_INVALID_PARAMETERS;
                }
            }
            else
            {
                clockIndex = clockIndex - CLOCK_NUM_GPR_SEL;

                /*
                 * The condition for the MAX clock index has already
                 * been validated.
                 */
                /* gcov_excl_ntbr_nextline */
                if (clockIndex < CLOCK_NUM_CGC)
                {
                    uint32_t rootIdx = parent - CLOCK_NUM_SRC;

                    if (!CCM_CgcSetParent(clockIndex, rootIdx))
                    {
                        status = SM_ERR_INVALID_PARAMETERS;
                    }
                }
                else
                {
                    status = SM_ERR_NOT_FOUND; /* gcov_excl_line */
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get clock parent                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockParentGet(uint32_t clockId, uint32_t *parent)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else if (clockId < CLOCK_NUM_SRC)
    {
        if (!CLOCK_SourceGetParent(clockId, parent))
        {
            status = SM_ERR_INVALID_PARAMETERS;
        }
    }
    else
    {
        uint32_t clockIndex = clockId - CLOCK_NUM_SRC;

        if (clockIndex < CLOCK_NUM_ROOT)
        {
            /*
             * The clockIndex parameter is already validated
             * against CLOCK_NUM_ROOT, so this function will
             * never return an error
             */
            /* gcov_excl_ntbr_nextline */
            if (!CCM_RootGetParent(clockIndex, parent))
            {
                /* gcov_excl_nextline */
                status = SM_ERR_INVALID_PARAMETERS;
            }
        }
        else
        {
            clockIndex = clockIndex - CLOCK_NUM_ROOT;

            if (clockIndex < CLOCK_NUM_GPR_SEL)
            {
                /*
                 * The clockIndex parameter is already validated
                 * against CLOCK_NUM_GPR_SEL, so this function will
                 * never return an error
                 */
                /* gcov_excl_ntbr_nextline */
                if (!CCM_GprSelGetParent(clockIndex, parent))
                {
                    status = SM_ERR_INVALID_PARAMETERS; /* gcov_excl_line  */
                }
            }
            else
            {
                clockIndex = clockIndex - CLOCK_NUM_GPR_SEL;

                /*
                 * The clockIndex parameter is already validated
                 * against CLOCK_NUM_CGC, so this statement will
                 * never execute
                 */
                /* gcov_excl_ntbr_nextline */
                if (clockIndex < CLOCK_NUM_CGC)
                {
                    uint32_t rootIdx;

                    /* gcov_excl_ntbr_nextline */
                    if (CCM_CgcGetParent(clockIndex, &rootIdx))
                    {
                        *parent = rootIdx + CLOCK_NUM_SRC;
                    }
                    else
                    {
                        /* gcov_excl_nextline */
                        status = SM_ERR_INVALID_PARAMETERS;
                    }
                }
                else
                {
                    status = SM_ERR_NOT_FOUND; /* gcov_excl_line  */
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get extended clock info                                                  */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockExtendedInfo(uint32_t clockId, bool *supported)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        uint32_t spreadPercent = 0U;
        uint32_t modFreq = 0U;
        uint32_t enable = 0U;

        /* Check if SCC is supported */
        *supported = CLOCK_SourceGetSsc(clockId, &spreadPercent, &modFreq,
            &enable);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set a device extended clock data value                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockExtendedSet(uint32_t clockId, uint32_t extId,
    uint32_t extConfigValue)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        switch (extId)
        {
            /* Spread spectrum */
            case DEV_SM_CLOCK_EXT_SSC:
                {
                    /* Parse extended configuration
                     *
                     * extConfigValue[7:0]   - spread percentage (%)
                     * extConfigValue[23:8]  - Modulation Frequency (KHz)
                     * extConfigValue[24]    - Enable/Disable
                     * extConfigValue[31:25] - Reserved
                     *
                     */

                    /* Get spread percentage Bit[7:0] from extended config */
                    uint32_t spreadPercent =  (extConfigValue &
                        DEV_SM_CLOCK_EXT_SSC_PERCENTAGE_MASK) >>
                        DEV_SM_CLOCK_EXT_SSC_PERCENTAGE_SHIFT;

                    /* Get modulation freq Bit[23:8] from extended config */
                    uint32_t modFreq = (extConfigValue &
                        DEV_SM_CLOCK_EXT_SSC_MOD_FREQ_MASK) >>
                        DEV_SM_CLOCK_EXT_SSC_MOD_FREQ_SHIFT;

                    /* Get enable field Bit[24] from extended config */
                    uint32_t enable = (extConfigValue &
                        DEV_SM_CLOCK_EXT_SSC_ENABLE_MASK)
                        >> DEV_SM_CLOCK_EXT_SSC_ENABLE_SHIFT;

                    if (!CLOCK_SourceSetSsc(clockId, spreadPercent, modFreq,
                        enable))
                    {
                        status = SM_ERR_INVALID_PARAMETERS;
                    }
                }
                break;

            default:
                status = SM_ERR_NOT_FOUND;
                break;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set a device extended clock data value                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockExtendedGet(uint32_t clockId, uint32_t extId,
    uint32_t *extConfigValue)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        switch (extId)
        {
            /* Spread spectrum */
            case DEV_SM_CLOCK_EXT_SSC:
                {
                    uint32_t spreadPercent = 0U;
                    uint32_t modFreq = 0U;
                    uint32_t enable = 0U;

                    if (!CLOCK_SourceGetSsc(clockId, &spreadPercent,
                        &modFreq, &enable))
                    {
                        status = SM_ERR_INVALID_PARAMETERS;
                    }
                    else
                    {
                        *extConfigValue =
                            DEV_SM_CLOCK_EXT_SSC_PERCENTAGE(spreadPercent)
                            | DEV_SM_CLOCK_EXT_SSC_MOD_FREQ(modFreq)
                            | DEV_SM_CLOCK_EXT_SSC_ENABLE(enable);
                    }
                }
                break;

            default:
                status = SM_ERR_NOT_FOUND;
                break;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Check if clock domain is reserved                                        */
/*--------------------------------------------------------------------------*/
bool DEV_SM_ClockIsReserved(uint32_t clockId)
{
    bool rc = false;
    uint32_t pwrDomainId = DEV_SM_NUM_POWER;

    static bool const s_clockIsReserved[DEV_SM_NUM_CLOCK] =
    {
        [DEV_SM_CLK_RESERVED18] = true,
        [DEV_SM_CLK_RESERVED19] = true,
        [DEV_SM_CLK_RESERVED20] = true,
        [DEV_SM_CLK_RESERVED21] = true,
        [DEV_SM_CLK_RESERVED22] = true,
        [DEV_SM_CLK_RESERVED23] = true
    };

    switch (clockId)
    {
        case DEV_SM_CLK_A55C1_GPR_SEL:
            pwrDomainId = DEV_SM_PD_A55C1;
            break;

        case DEV_SM_CLK_A55C2_GPR_SEL:
            pwrDomainId = DEV_SM_PD_A55C2;
            break;

        case DEV_SM_CLK_A55C3_GPR_SEL:
            pwrDomainId = DEV_SM_PD_A55C3;
            break;

        case DEV_SM_CLK_M70:
        case DEV_SM_CLK_BUSM70:
        case DEV_SM_CLK_M70SYSTICK:
            pwrDomainId = DEV_SM_PD_M70;
            break;

        case DEV_SM_CLK_M71:
        case DEV_SM_CLK_BUSM71:
        case DEV_SM_CLK_M71SYSTICK:
            pwrDomainId = DEV_SM_PD_M71;
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    if (clockId >= DEV_SM_NUM_CLOCK)
    {
        rc = true;
    }
    else
    {
        if (pwrDomainId < DEV_SM_NUM_POWER)
        {
            /* Check fuse state of power domain */
            /* gcov_excl_ntbr_nextline - configtool enforces */
            if (DEV_SM_FusePdDisabled(pwrDomainId))
            {
                rc = true; /* gcov_excl_line  */
            }
        }
        else
        {
            rc = s_clockIsReserved[clockId];
        }
    }

    /* Return status */
    return rc;
}

