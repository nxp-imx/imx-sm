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
 * @addtogroup MX95_CLOCK_driver
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the MX95 Clock Driver.
 */
/*==========================================================================*/

#ifndef FSL_CLOCK_H
#define FSL_CLOCK_H

/* Includes */

#include "fsl_common.h"

/* Defines */

#ifndef DOXYGEN

#define CLOCK_OSC32K_HZ                     32768ULL
#define CLOCK_OSC24M_HZ                     24000000ULL
#define CLOCK_FRO_HZ                        256000000ULL
#define CLOCK_PLL_FREF_HZ                   CLOCK_OSC24M_HZ
#define CLOCK_M_HZ                          1000000ULL
#define CLOCK_K_HZ                          1000ULL

#define CLOCK_PLL_CALC_ACCURACY_HZ          1000U
#define CLOCK_PLL_MFD                       (CLOCK_PLL_FREF_HZ/CLOCK_PLL_CALC_ACCURACY_HZ)

#define CLOCK_NUM_PLL                       8U

#define CLOCK_PLL_SYS1                      0U
#define CLOCK_PLL_AUDIO1                    1U
#define CLOCK_PLL_AUDIO2                    2U
#define CLOCK_PLL_VIDEO1                    3U
#define CLOCK_PLL_ARM                       4U
#define CLOCK_PLL_DRAM                      5U
#define CLOCK_PLL_HSIO                      6U
#define CLOCK_PLL_LDB                       7U

#define CLOCK_NUM_SRC                       41UL

#define CLOCK_SRC_EXT                       0U
#define CLOCK_SRC_OSC32K                    1U
#define CLOCK_SRC_OSC24M                    2U
#define CLOCK_SRC_FRO                       3U
#define CLOCK_SRC_SYSPLL1_VCO               4U
#define CLOCK_SRC_SYSPLL1_PFD0_UNGATED      5U
#define CLOCK_SRC_SYSPLL1_PFD0              6U
#define CLOCK_SRC_SYSPLL1_PFD0_DIV2         7U
#define CLOCK_SRC_SYSPLL1_PFD1_UNGATED      8U
#define CLOCK_SRC_SYSPLL1_PFD1              9U
#define CLOCK_SRC_SYSPLL1_PFD1_DIV2         10U
#define CLOCK_SRC_SYSPLL1_PFD2_UNGATED      11U
#define CLOCK_SRC_SYSPLL1_PFD2              12U
#define CLOCK_SRC_SYSPLL1_PFD2_DIV2         13U
#define CLOCK_SRC_AUDIOPLL1_VCO             14U
#define CLOCK_SRC_AUDIOPLL1                 15U
#define CLOCK_SRC_AUDIOPLL2_VCO             16U
#define CLOCK_SRC_AUDIOPLL2                 17U
#define CLOCK_SRC_VIDEOPLL1_VCO             18U
#define CLOCK_SRC_VIDEOPLL1                 19U
#define CLOCK_SRC_RESERVED20                20U
#define CLOCK_SRC_RESERVED21                21U
#define CLOCK_SRC_RESERVED22                22U
#define CLOCK_SRC_RESERVED23                23U
#define CLOCK_SRC_ARMPLL_VCO                24U
#define CLOCK_SRC_ARMPLL_PFD0_UNGATED       25U
#define CLOCK_SRC_ARMPLL_PFD0               26U
#define CLOCK_SRC_ARMPLL_PFD1_UNGATED       27U
#define CLOCK_SRC_ARMPLL_PFD1               28U
#define CLOCK_SRC_ARMPLL_PFD2_UNGATED       29U
#define CLOCK_SRC_ARMPLL_PFD2               30U
#define CLOCK_SRC_ARMPLL_PFD3_UNGATED       31U
#define CLOCK_SRC_ARMPLL_PFD3               32U
#define CLOCK_SRC_DRAMPLL_VCO               33U
#define CLOCK_SRC_DRAMPLL                   34U
#define CLOCK_SRC_HSIOPLL_VCO               35U
#define CLOCK_SRC_HSIOPLL                   36U
#define CLOCK_SRC_LDBPLL_VCO                37U
#define CLOCK_SRC_LDBPLL                    38U
#define CLOCK_SRC_EXT1                      39U
#define CLOCK_SRC_EXT2                      40U

#define CLOCK_NUM_ROOT                      123UL
#define CLOCK_NUM_ROOT_MUX_SEL              4U

#define CLOCK_ROOT_ADC                      0U
#define CLOCK_ROOT_TMU                      1U
#define CLOCK_ROOT_BUSAON                   2U
#define CLOCK_ROOT_CAN1                     3U
#define CLOCK_ROOT_I3C1                     4U
#define CLOCK_ROOT_I3C1SLOW                 5U
#define CLOCK_ROOT_LPI2C1                   6U
#define CLOCK_ROOT_LPI2C2                   7U
#define CLOCK_ROOT_LPSPI1                   8U
#define CLOCK_ROOT_LPSPI2                   9U
#define CLOCK_ROOT_LPTMR1                   10U
#define CLOCK_ROOT_LPUART1                  11U
#define CLOCK_ROOT_LPUART2                  12U
#define CLOCK_ROOT_M33                      13U
#define CLOCK_ROOT_M33SYSTICK               14U
#define CLOCK_ROOT_MQS1                     15U
#define CLOCK_ROOT_PDM                      16U
#define CLOCK_ROOT_SAI1                     17U
#define CLOCK_ROOT_SENTINEL                 18U
#define CLOCK_ROOT_TPM2                     19U
#define CLOCK_ROOT_TSTMR1                   20U
#define CLOCK_ROOT_CAMAPB                   21U
#define CLOCK_ROOT_CAMAXI                   22U
#define CLOCK_ROOT_CAMCM0                   23U
#define CLOCK_ROOT_CAMISI                   24U
#define CLOCK_ROOT_MIPIPHYCFG               25U
#define CLOCK_ROOT_MIPIPHYPLLBYPASS         26U
#define CLOCK_ROOT_MIPIPHYPLLREF            27U
#define CLOCK_ROOT_MIPITESTBYTE             28U
#define CLOCK_ROOT_A55                      29U
#define CLOCK_ROOT_A55MTRBUS                30U
#define CLOCK_ROOT_A55PERIPH                31U
#define CLOCK_ROOT_DRAMALT                  32U
#define CLOCK_ROOT_DRAMAPB                  33U
#define CLOCK_ROOT_DISPAPB                  34U
#define CLOCK_ROOT_DISPAXI                  35U
#define CLOCK_ROOT_RESERVED36               36U
#define CLOCK_ROOT_DISPOCRAM                37U
#define CLOCK_ROOT_RESERVED38               38U
#define CLOCK_ROOT_DISP1PIX                 39U
#define CLOCK_ROOT_DISP2PIX                 40U
#define CLOCK_ROOT_DISP3PIX                 41U
#define CLOCK_ROOT_GPUAPB                   42U
#define CLOCK_ROOT_GPU                      43U
#define CLOCK_ROOT_HSIOACSCAN480M           44U
#define CLOCK_ROOT_HSIOACSCAN80M            45U
#define CLOCK_ROOT_HSIO                     46U
#define CLOCK_ROOT_HSIOPCIEAUX              47U
#define CLOCK_ROOT_HSIOPCIETEST160M         48U
#define CLOCK_ROOT_HSIOPCIETEST400M         49U
#define CLOCK_ROOT_HSIOPCIETEST500M         50U
#define CLOCK_ROOT_HSIOUSBTEST50M           51U
#define CLOCK_ROOT_HSIOUSBTEST60M           52U
#define CLOCK_ROOT_BUSM7                    53U
#define CLOCK_ROOT_M7                       54U
#define CLOCK_ROOT_M7SYSTICK                55U
#define CLOCK_ROOT_BUSNETCMIX               56U
#define CLOCK_ROOT_ENET                     57U
#define CLOCK_ROOT_ENETPHYTEST200M          58U
#define CLOCK_ROOT_ENETPHYTEST500M          59U
#define CLOCK_ROOT_ENETPHYTEST667M          60U
#define CLOCK_ROOT_ENETREF                  61U
#define CLOCK_ROOT_ENETTIMER1               62U
#define CLOCK_ROOT_MQS2                     63U
#define CLOCK_ROOT_SAI2                     64U
#define CLOCK_ROOT_NOCAPB                   65U
#define CLOCK_ROOT_NOC                      66U
#define CLOCK_ROOT_NPUAPB                   67U
#define CLOCK_ROOT_NPU                      68U
#define CLOCK_ROOT_CCMCKO1                  69U
#define CLOCK_ROOT_CCMCKO2                  70U
#define CLOCK_ROOT_CCMCKO3                  71U
#define CLOCK_ROOT_CCMCKO4                  72U
#define CLOCK_ROOT_VPUAPB                   73U
#define CLOCK_ROOT_VPU                      74U
#define CLOCK_ROOT_VPUDSP                   75U
#define CLOCK_ROOT_VPUJPEG                  76U
#define CLOCK_ROOT_AUDIOXCVR                77U
#define CLOCK_ROOT_BUSWAKEUP                78U
#define CLOCK_ROOT_CAN2                     79U
#define CLOCK_ROOT_CAN3                     80U
#define CLOCK_ROOT_CAN4                     81U
#define CLOCK_ROOT_CAN5                     82U
#define CLOCK_ROOT_FLEXIO1                  83U
#define CLOCK_ROOT_FLEXIO2                  84U
#define CLOCK_ROOT_FLEXSPI1                 85U
#define CLOCK_ROOT_I3C2                     86U
#define CLOCK_ROOT_I3C2SLOW                 87U
#define CLOCK_ROOT_LPI2C3                   88U
#define CLOCK_ROOT_LPI2C4                   89U
#define CLOCK_ROOT_LPI2C5                   90U
#define CLOCK_ROOT_LPI2C6                   91U
#define CLOCK_ROOT_LPI2C7                   92U
#define CLOCK_ROOT_LPI2C8                   93U
#define CLOCK_ROOT_LPSPI3                   94U
#define CLOCK_ROOT_LPSPI4                   95U
#define CLOCK_ROOT_LPSPI5                   96U
#define CLOCK_ROOT_LPSPI6                   97U
#define CLOCK_ROOT_LPSPI7                   98U
#define CLOCK_ROOT_LPSPI8                   99U
#define CLOCK_ROOT_LPTMR2                   100U
#define CLOCK_ROOT_LPUART3                  101U
#define CLOCK_ROOT_LPUART4                  102U
#define CLOCK_ROOT_LPUART5                  103U
#define CLOCK_ROOT_LPUART6                  104U
#define CLOCK_ROOT_LPUART7                  105U
#define CLOCK_ROOT_LPUART8                  106U
#define CLOCK_ROOT_SAI3                     107U
#define CLOCK_ROOT_SAI4                     108U
#define CLOCK_ROOT_SAI5                     109U
#define CLOCK_ROOT_SPDIF                    110U
#define CLOCK_ROOT_SWOTRACE                 111U
#define CLOCK_ROOT_TPM4                     112U
#define CLOCK_ROOT_TPM5                     113U
#define CLOCK_ROOT_TPM6                     114U
#define CLOCK_ROOT_TSTMR2                   115U
#define CLOCK_ROOT_USBPHYBURUNIN            116U
#define CLOCK_ROOT_USDHC1                   117U
#define CLOCK_ROOT_USDHC2                   118U
#define CLOCK_ROOT_USDHC3                   119U
#define CLOCK_ROOT_V2XPK                    120U
#define CLOCK_ROOT_WAKEUPAXI                121U
#define CLOCK_ROOT_XSPISLVROOT              122U

#define CLOCK_NUM_GPR                       3U
#define CLOCK_NUM_GPR_SEL                   10UL
#define CLOCK_NUM_GPR_MUX_SEL               2U

#define CLOCK_GPR_SEL_EXT                   0U
#define CLOCK_GPR_SEL_A55C0                 1U
#define CLOCK_GPR_SEL_A55C1                 2U
#define CLOCK_GPR_SEL_A55C2                 3U
#define CLOCK_GPR_SEL_A55C3                 4U
#define CLOCK_GPR_SEL_A55C4                 5U
#define CLOCK_GPR_SEL_A55C5                 6U
#define CLOCK_GPR_SEL_A55P                  7U
#define CLOCK_GPR_SEL_DRAM                  8U
#define CLOCK_GPR_SEL_TEMPSENSE             9U

#define CLOCK_ROUND_RULE_CEILING            0U
#define CLOCK_ROUND_RULE_FLOOR              1U
#define CLOCK_ROUND_RULE_CLOSEST            2U

#endif

/* Types */

/*!
 * PLL attribute structure
 *
 * Structure containing parameters to represent PLL attributes.
 */
typedef struct
{
    bool isFrac;        /*!< Integer/Fractional PLL */
    uint8_t numDFS;     /*!< PLL's number of DFS outputs */
} pll_attr_t;

/*!
 * Structure for CCM GPR-selected clock attributes
 *
 * Structure for CCM GPR-selected clocks, which can be clock sources or clock
 * roots.
 */
typedef struct
{
    uint32_t selIdx;                        /*!< GPR select identifier */
    uint32_t selMask;                       /*!< GPR select mask */
    uint32_t selShift;                      /*!< GPR select shift */
    uint32_t selMux[CLOCK_NUM_GPR_MUX_SEL]; /*!< GPR select mux configuration */
} ccm_gpr_sel_attr_t;

/* Functions */

/*!
 * @name Clock Driver functions
 * @{
 */

/*!
 * Get clock source enable status
 *
 * @param[in]       sourceIdx       Clock source identifier
 *
 * This function allows caller to get the enable status of given clock source.
 * For the PLL clock sources, it queries the status from Fractional PLL driver
 * API calls.
 *
 * @return Returns true if clock source is enabled and it's enable status is
 * retrieved successfully, otherwise false.
 */
bool CLOCK_SourceGetEnable(uint32_t sourceIdx);

/*!
 * Set clock source enable status
 *
 * @param[in]       sourceIdx       Clock source identifier
 * @param[in]       enable          Enable flag (1=enable, 0=disable)
 *
 * This function allows caller to set the enable status of given clock source.
 * For the PLL clock sources, it calls Fractional PLL driver APIs to set
 * enable flag.
 *
 * @return Returns true if enable flag is set successfully for given clock
 * source, otherwise false.
 */
bool CLOCK_SourceSetEnable(uint32_t sourceIdx, bool enable);

/*!
 * Get clock source rate
 *
 * @param[in]       sourceIdx       Clock source identifier
 *
 * This function allows caller to get rate for the given clock source. For
 * board-specific EXT clocks, previously stored rate via set rate calls is
 * returned.
 *
 * @return Returns true if the rate is get successfully, otherwise false.
 */
uint64_t CLOCK_SourceGetRate(uint32_t sourceIdx);

/*!
 * Set clock source rate
 *
 * @param[in]       sourceIdx       Clock source identifier
 * @param[in]       rate            Clock rate in hertz.
 * @param[in]       roundRule       Round rule (CEIL/FLOOR/CLOSEST)
 *
 * This function allows caller to set rate for the given clock source. For
 * board-specific EXT clocks, rate is stored and returned in subsequent
 * get rate calls.
 *
 * @return Returns true if the rate is set successfully, otherwise false.
 */
bool CLOCK_SourceSetRate(uint32_t sourceIdx, uint64_t rate, uint32_t roundRule);

/*!
 * Set clock source spread spectrum configuration
 *
 * @param[in]       sourceIdx       Clock source identifier
 * @param[in]       spreadPercent   Spread percentage
 * @param[in]       modFreq         Modulation frequency
 * @param[in]       enable          Enable flag (1=enable, 0=disable)
 *
 * This function allows caller to set spread spectrum configuration for the
 * given clock source. Given \a sourceIdx represents VCO PLL to which the
 * spread spectrum is applied and gets applied to all its derivative clocks.
 * Saved spread spectrum configuration for the PLL is applied on next
 * CLOCK_RATE_SET command.
 *
 * @return Returns true if spread spectrum configuration is set successfully,
 * otherwise false.
 */
bool CLOCK_SourceSetSsc(uint32_t sourceIdx, uint32_t spreadPercent,
    uint32_t modFreq, uint32_t enable);

/*!
 * Get clock source spread spectrum configuration
 *
 * @param[in]       sourceIdx       Clock source identifier
 * @param[out]      spreadPercent   Spread percentage
 * @param[out]      modFreq         Modulation frequency
 * @param[out]      enable          Enable flag (1=enable, 0=disable)
 *
 * This function allows caller to get spread spectrum configuration for the
 * given clock source. Given \a sourceIdx represents VCO PLL to which the
 * spread spectrum is applied and gets applied to all its derivative clocks.
 *
 * @return Returns true if spread spectrum configuration is retrieved
 * successfully, otherwise false.
 */
bool CLOCK_SourceGetSsc(uint32_t sourceIdx, uint32_t *spreadPercent,
    uint32_t *modFreq, uint32_t *enable);

/** @} */

/* Externs */

/*! Board-specific EXT clock */
extern uint64_t g_clockExt1Rate;

/*! PLL attributes */
extern const pll_attr_t g_pllAttrs[];

/*! Clock root mux select (parent clock source for the clock root)*/
extern const uint8_t g_clockRootMux[][CLOCK_NUM_ROOT_MUX_SEL];

/*! GPR-selected clocks (clock source/clock root) */
extern const ccm_gpr_sel_attr_t g_clockGprSel[CLOCK_NUM_GPR_SEL];

#endif /* FSL_CLOCK_H */

/** @} */

