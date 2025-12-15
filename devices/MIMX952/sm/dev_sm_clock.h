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

#ifndef DEV_SM_CLOCK_H
#define DEV_SM_CLOCK_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX952_CLOCK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device clocks.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "fsl_ccm.h"
#include "fsl_clock.h"

/* Defines */

/*! Number of device clocks */
#define DEV_SM_NUM_CLOCK  (CLOCK_NUM_SRC + CLOCK_NUM_ROOT \
    + CLOCK_NUM_GPR_SEL + CLOCK_NUM_CGC)

/*! Number of device clocks not including CGCs */
#define DEV_SM_NUM_NONCGC_CLOCK  (DEV_SM_NUM_CLOCK - CLOCK_NUM_CGC)

/*!
 * @name Device clock domain indexes
 *
 * See the Clock Control Module (CCM) section of the i.MX952 RM.
 */
/** @{ */
#define DEV_SM_CLK_EXT                  CLOCK_SRC_EXT                                /*!< 0: EXT source */
#define DEV_SM_CLK_OSC32K               CLOCK_SRC_OSC32K                             /*!< 1: OSC32K source */
#define DEV_SM_CLK_OSC24M               CLOCK_SRC_OSC24M                             /*!< 2: OSC24M source */
#define DEV_SM_CLK_FRO                  CLOCK_SRC_FRO                                /*!< 3: FRO source */
#define DEV_SM_CLK_SYSPLL1_VCO          CLOCK_SRC_SYSPLL1_VCO                        /*!< 4: SYSPLL1 VCO source */
#define DEV_SM_CLK_SYSPLL1_PFD0_UNGATED CLOCK_SRC_SYSPLL1_PFD0_UNGATED               /*!< 5: SYSPLL1 PFD0 UNGATED source */
#define DEV_SM_CLK_SYSPLL1_PFD0         CLOCK_SRC_SYSPLL1_PFD0                       /*!< 6: SYSPLL1 PFD0 source */
#define DEV_SM_CLK_SYSPLL1_PFD0_DIV2    CLOCK_SRC_SYSPLL1_PFD0_DIV2                  /*!< 7: SYSPLL1 PFD0 DIV2 source */
#define DEV_SM_CLK_SYSPLL1_PFD1_UNGATED CLOCK_SRC_SYSPLL1_PFD1_UNGATED               /*!< 8: SYSPLL1 PFD1 UNGATED source */
#define DEV_SM_CLK_SYSPLL1_PFD1         CLOCK_SRC_SYSPLL1_PFD1                       /*!< 9: SYSPLL1 PFD1 source */
#define DEV_SM_CLK_SYSPLL1_PFD1_DIV2    CLOCK_SRC_SYSPLL1_PFD1_DIV2                  /*!< 10: SYSPLL1 PFD1 DIV2 source */
#define DEV_SM_CLK_SYSPLL1_PFD2_UNGATED CLOCK_SRC_SYSPLL1_PFD2_UNGATED               /*!< 11: SYSPLL1 PFD2 UNGATED source */
#define DEV_SM_CLK_SYSPLL1_PFD2         CLOCK_SRC_SYSPLL1_PFD2                       /*!< 12: SYSPLL1 PFD2 source */
#define DEV_SM_CLK_SYSPLL1_PFD2_DIV2    CLOCK_SRC_SYSPLL1_PFD2_DIV2                  /*!< 13: SYSPLL1 PFD2 DIV2 source */
#define DEV_SM_CLK_AUDIOPLL1_VCO        CLOCK_SRC_AUDIOPLL1_VCO                      /*!< 14: AUDIOPLL1 VCO source */
#define DEV_SM_CLK_AUDIOPLL1            CLOCK_SRC_AUDIOPLL1                          /*!< 15: AUDIOPLL1 source */
#define DEV_SM_CLK_AUDIOPLL2_VCO        CLOCK_SRC_AUDIOPLL2_VCO                      /*!< 16: AUDIOPLL2 VCO source */
#define DEV_SM_CLK_AUDIOPLL2            CLOCK_SRC_AUDIOPLL2                          /*!< 17: AUDIOPLL2 source */
#define DEV_SM_CLK_VIDEOPLL1_VCO        CLOCK_SRC_VIDEOPLL1_VCO                      /*!< 18: VIDEOPLL1 VCO source */
#define DEV_SM_CLK_VIDEOPLL1            CLOCK_SRC_VIDEOPLL1                          /*!< 19: VIDEOPLL1 source */
#define DEV_SM_CLK_RESERVED20           CLOCK_SRC_RESERVED20                         /*!< 20: RESERVED20 source */
#define DEV_SM_CLK_SYSPLL1_PFD3_UNGATED CLOCK_SRC_SYSPLL1_PFD3_UNGATED               /*!< 21: SYSPLL1 PFD3 UNGATED source */
#define DEV_SM_CLK_SYSPLL1_PFD3         CLOCK_SRC_SYSPLL1_PFD3                       /*!< 22: SYSPLL1 PFD3 source */
#define DEV_SM_CLK_SYSPLL1_PFD3_DIV2    CLOCK_SRC_SYSPLL1_PFD3_DIV2                  /*!< 23: SYSPLL1 PFD3 DIV2 source */
#define DEV_SM_CLK_ARMPLL_VCO           CLOCK_SRC_ARMPLL_VCO                         /*!< 24: ARMPLL VCO source */
#define DEV_SM_CLK_ARMPLL_PFD0_UNGATED  CLOCK_SRC_ARMPLL_PFD0_UNGATED                /*!< 25: ARMPLL PFD0 UNGATED source */
#define DEV_SM_CLK_ARMPLL_PFD0          CLOCK_SRC_ARMPLL_PFD0                        /*!< 26: ARMPLL PFD0 source */
#define DEV_SM_CLK_ARMPLL_PFD1_UNGATED  CLOCK_SRC_ARMPLL_PFD1_UNGATED                /*!< 27: ARMPLL PFD1 UNGATED source */
#define DEV_SM_CLK_ARMPLL_PFD1          CLOCK_SRC_ARMPLL_PFD1                        /*!< 28: ARMPLL PFD1 source */
#define DEV_SM_CLK_ARMPLL_PFD2_UNGATED  CLOCK_SRC_ARMPLL_PFD2_UNGATED                /*!< 29: ARMPLL PFD2 UNGATED source */
#define DEV_SM_CLK_ARMPLL_PFD2          CLOCK_SRC_ARMPLL_PFD2                        /*!< 30: ARMPLL PFD2 source */
#define DEV_SM_CLK_ARMPLL_PFD3_UNGATED  CLOCK_SRC_ARMPLL_PFD3_UNGATED                /*!< 31: ARMPLL PFD3 UNGATED source */
#define DEV_SM_CLK_ARMPLL_PFD3          CLOCK_SRC_ARMPLL_PFD3                        /*!< 32: ARMPLL PFD3 source */
#define DEV_SM_CLK_DRAMPLL_VCO          CLOCK_SRC_DRAMPLL_VCO                        /*!< 33: DRAMPLL VCO source */
#define DEV_SM_CLK_DRAMPLL              CLOCK_SRC_DRAMPLL                            /*!< 34: DRAMPLL source */
#define DEV_SM_CLK_HSIOPLL_VCO          CLOCK_SRC_HSIOPLL_VCO                        /*!< 35: HSIOPLL VCO source */
#define DEV_SM_CLK_HSIOPLL              CLOCK_SRC_HSIOPLL                            /*!< 36: HSIOPLL source */
#define DEV_SM_CLK_LDBPLL_VCO           CLOCK_SRC_LDBPLL_VCO                         /*!< 37: LDBPLL VCO source */
#define DEV_SM_CLK_LDBPLL               CLOCK_SRC_LDBPLL                             /*!< 38: LDBPLL source */
#define DEV_SM_CLK_EXT1                 CLOCK_SRC_EXT1                               /*!< 39: EXT1 source */
#define DEV_SM_CLK_EXT2                 CLOCK_SRC_EXT2                               /*!< 40: EXT2 source */

#define DEV_SM_CLK_ADC                  (CLOCK_ROOT_ADC + CLOCK_NUM_SRC)             /*!< 41: ADC root */
#define DEV_SM_CLK_RESERVED42           (CLOCK_ROOT_RESERVED1 + CLOCK_NUM_SRC)       /*!< 42: RESERVED42 root */
#define DEV_SM_CLK_BUSAON               (CLOCK_ROOT_BUSAON + CLOCK_NUM_SRC)          /*!< 43: BUSAON root */
#define DEV_SM_CLK_CAN1                 (CLOCK_ROOT_CAN1 + CLOCK_NUM_SRC)            /*!< 44: CAN1 root */
#define DEV_SM_CLK_RESERVED45           (CLOCK_ROOT_RESERVED4 + CLOCK_NUM_SRC)       /*!< 45: RESERVED45 root */
#define DEV_SM_CLK_I3C1SLOW             (CLOCK_ROOT_I3C1SLOW + CLOCK_NUM_SRC)        /*!< 46: I3C1SLOW root */
#define DEV_SM_CLK_LPI2C1               (CLOCK_ROOT_LPI2C1 + CLOCK_NUM_SRC)          /*!< 47: LPI2C1 root */
#define DEV_SM_CLK_LPI2C2               (CLOCK_ROOT_LPI2C2 + CLOCK_NUM_SRC)          /*!< 48: LPI2C2 root */
#define DEV_SM_CLK_LPSPI1               (CLOCK_ROOT_LPSPI1 + CLOCK_NUM_SRC)          /*!< 49: LPSPI1 root */
#define DEV_SM_CLK_LPSPI2               (CLOCK_ROOT_LPSPI2 + CLOCK_NUM_SRC)          /*!< 50: LPSPI2 root */
#define DEV_SM_CLK_LPTMR1               (CLOCK_ROOT_LPTMR1 + CLOCK_NUM_SRC)          /*!< 51: LPTMR1 root */
#define DEV_SM_CLK_LPUART1              (CLOCK_ROOT_LPUART1 + CLOCK_NUM_SRC)         /*!< 52: LPUART1 root */
#define DEV_SM_CLK_LPUART2              (CLOCK_ROOT_LPUART2 + CLOCK_NUM_SRC)         /*!< 53: LPUART2 root */
#define DEV_SM_CLK_M33                  (CLOCK_ROOT_M33 + CLOCK_NUM_SRC)             /*!< 54: M33 root */
#define DEV_SM_CLK_M33SYSTICK           (CLOCK_ROOT_M33SYSTICK + CLOCK_NUM_SRC)      /*!< 55: M33SYSTICK root */
#define DEV_SM_CLK_RESERVED56           (CLOCK_ROOT_RESERVED15 + CLOCK_NUM_SRC)      /*!< 56: RESERVED56 root */
#define DEV_SM_CLK_PDM                  (CLOCK_ROOT_PDM + CLOCK_NUM_SRC)             /*!< 57: PDM root */
#define DEV_SM_CLK_SAI1                 (CLOCK_ROOT_SAI1 + CLOCK_NUM_SRC)            /*!< 58: SAI1 root */
#define DEV_SM_CLK_RESERVED59           (CLOCK_ROOT_RESERVED18 + CLOCK_NUM_SRC)      /*!< 59: RESERVED59 root */
#define DEV_SM_CLK_TPM2                 (CLOCK_ROOT_TPM2 + CLOCK_NUM_SRC)            /*!< 60: TPM2 root */
#define DEV_SM_CLK_RESERVED61           (CLOCK_ROOT_RESERVED20 + CLOCK_NUM_SRC)      /*!< 61: RESERVED61 root */
#define DEV_SM_CLK_CAMAPB               (CLOCK_ROOT_CAMAPB + CLOCK_NUM_SRC)          /*!< 62: CAMAPB root */
#define DEV_SM_CLK_CAMAXI               (CLOCK_ROOT_CAMAXI + CLOCK_NUM_SRC)          /*!< 63: CAMAXI root */
#define DEV_SM_CLK_CAMCM0               (CLOCK_ROOT_CAMCM0 + CLOCK_NUM_SRC)          /*!< 64: CAMCM0 root */
#define DEV_SM_CLK_CAMISI               (CLOCK_ROOT_CAMISI + CLOCK_NUM_SRC)          /*!< 65: CAMISI root */
#define DEV_SM_CLK_CAMPHYCFG            (CLOCK_ROOT_CAMPHYCFG + CLOCK_NUM_SRC)       /*!< 66: CAMPHYCFG root */
#define DEV_SM_CLK_MIPIPHYPLLBYPASS     (CLOCK_ROOT_MIPIPHYPLLBYPASS + CLOCK_NUM_SRC) /*!< 67: MIPIPHYPLLBYPASS root */
#define DEV_SM_CLK_RESERVED68           (CLOCK_ROOT_RESERVED27 + CLOCK_NUM_SRC)      /*!< 68: RESERVED68 root */
#define DEV_SM_CLK_MIPITESTBYTE         (CLOCK_ROOT_MIPITESTBYTE + CLOCK_NUM_SRC)    /*!< 69: MIPITESTBYTE root */
#define DEV_SM_CLK_A55                  (CLOCK_ROOT_A55 + CLOCK_NUM_SRC)             /*!< 70: A55 root */
#define DEV_SM_CLK_A55MTRBUS            (CLOCK_ROOT_A55MTRBUS + CLOCK_NUM_SRC)       /*!< 71: A55MTRBUS root */
#define DEV_SM_CLK_A55PERIPH            (CLOCK_ROOT_A55PERIPH + CLOCK_NUM_SRC)       /*!< 72: A55PERIPH root */
#define DEV_SM_CLK_DRAMALT              (CLOCK_ROOT_DRAMALT + CLOCK_NUM_SRC)         /*!< 73: DRAMALT root */
#define DEV_SM_CLK_DRAMAPB              (CLOCK_ROOT_DRAMAPB + CLOCK_NUM_SRC)         /*!< 74: DRAMAPB root */
#define DEV_SM_CLK_DISPAPB              (CLOCK_ROOT_DISPAPB + CLOCK_NUM_SRC)         /*!< 75: DISPAPB root */
#define DEV_SM_CLK_DISPAXI              (CLOCK_ROOT_DISPAXI + CLOCK_NUM_SRC)         /*!< 76: DISPAXI root */
#define DEV_SM_CLK_DISPLPSPI            (CLOCK_ROOT_DISPLPSPI + CLOCK_NUM_SRC)       /*!< 77: DISPLPSPI root */
#define DEV_SM_CLK_DISPOCRAM            (CLOCK_ROOT_DISPOCRAM + CLOCK_NUM_SRC)       /*!< 78: DISPOCRAM root */
#define DEV_SM_CLK_DISPPHYCFG           (CLOCK_ROOT_DISPPHYCFG + CLOCK_NUM_SRC)      /*!< 79: DISPPHYCFG root */
#define DEV_SM_CLK_DISP1PIX             (CLOCK_ROOT_DISP1PIX + CLOCK_NUM_SRC)        /*!< 80: DISP1PIX root */
#define DEV_SM_CLK_DISPCDPHYAPB         (CLOCK_ROOT_DISPCDPHYAPB + CLOCK_NUM_SRC)    /*!< 81: DISPCDPHYAPB root */
#define DEV_SM_CLK_RESERVED82           (CLOCK_ROOT_RESERVED41 + CLOCK_NUM_SRC)      /*!< 82: RESERVED82 root */
#define DEV_SM_CLK_GPUAPB               (CLOCK_ROOT_GPUAPB + CLOCK_NUM_SRC)          /*!< 83: GPUAPB root */
#define DEV_SM_CLK_GPU                  (CLOCK_ROOT_GPU + CLOCK_NUM_SRC)             /*!< 84: GPU root */
#define DEV_SM_CLK_HSIOACSCAN480M       (CLOCK_ROOT_HSIOACSCAN480M + CLOCK_NUM_SRC)  /*!< 85: HSIOACSCAN480M root */
#define DEV_SM_CLK_HSIOACSCAN80M        (CLOCK_ROOT_HSIOACSCAN80M + CLOCK_NUM_SRC)   /*!< 86: HSIOACSCAN80M root */
#define DEV_SM_CLK_HSIO                 (CLOCK_ROOT_HSIO + CLOCK_NUM_SRC)            /*!< 87: HSIO root */
#define DEV_SM_CLK_HSIOPCIEAUX          (CLOCK_ROOT_HSIOPCIEAUX + CLOCK_NUM_SRC)     /*!< 88: HSIOPCIEAUX root */
#define DEV_SM_CLK_HSIOPCIETEST160M     (CLOCK_ROOT_HSIOPCIETEST160M + CLOCK_NUM_SRC) /*!< 89: HSIOPCIETEST160M root */
#define DEV_SM_CLK_HSIOPCIETEST400M     (CLOCK_ROOT_HSIOPCIETEST400M + CLOCK_NUM_SRC) /*!< 90: HSIOPCIETEST400M root */
#define DEV_SM_CLK_HSIOPCIETEST500M     (CLOCK_ROOT_HSIOPCIETEST500M + CLOCK_NUM_SRC) /*!< 91: HSIOPCIETEST500M root */
#define DEV_SM_CLK_HSIOUSBTEST50M       (CLOCK_ROOT_HSIOUSBTEST50M + CLOCK_NUM_SRC)  /*!< 92: HSIOUSBTEST50M root */
#define DEV_SM_CLK_HSIOUSBTEST60M       (CLOCK_ROOT_HSIOUSBTEST60M + CLOCK_NUM_SRC)  /*!< 93: HSIOUSBTEST60M root */
#define DEV_SM_CLK_BUSM7                (CLOCK_ROOT_BUSM7 + CLOCK_NUM_SRC)           /*!< 94: BUSM7 root */
#define DEV_SM_CLK_M7                   (CLOCK_ROOT_M7 + CLOCK_NUM_SRC)              /*!< 95: M7 root */
#define DEV_SM_CLK_M7SYSTICK            (CLOCK_ROOT_M7SYSTICK + CLOCK_NUM_SRC)       /*!< 96: M7SYSTICK root */
#define DEV_SM_CLK_BUSNETCMIX           (CLOCK_ROOT_BUSNETCMIX + CLOCK_NUM_SRC)      /*!< 97: BUSNETCMIX root */
#define DEV_SM_CLK_ENET                 (CLOCK_ROOT_ENET + CLOCK_NUM_SRC)            /*!< 98: ENET root */
#define DEV_SM_CLK_ENETPHYTEST200M      (CLOCK_ROOT_ENETPHYTEST200M + CLOCK_NUM_SRC) /*!< 99: ENETPHYTEST200M root */
#define DEV_SM_CLK_ENETPHYTEST500M      (CLOCK_ROOT_ENETPHYTEST500M + CLOCK_NUM_SRC) /*!< 100: ENETPHYTEST500M root */
#define DEV_SM_CLK_ENETPHYTEST667M      (CLOCK_ROOT_ENETPHYTEST667M + CLOCK_NUM_SRC) /*!< 101: ENETPHYTEST667M root */
#define DEV_SM_CLK_ENETREF              (CLOCK_ROOT_ENETREF + CLOCK_NUM_SRC)         /*!< 102: ENETREF root */
#define DEV_SM_CLK_ENETTIMER1           (CLOCK_ROOT_ENETTIMER1 + CLOCK_NUM_SRC)      /*!< 103: ENETTIMER1 root */
#define DEV_SM_CLK_RESERVED104          (CLOCK_ROOT_RESERVED63 + CLOCK_NUM_SRC)      /*!< 104: RESERVED104 root */
#define DEV_SM_CLK_SAI2                 (CLOCK_ROOT_SAI2 + CLOCK_NUM_SRC)            /*!< 105: SAI2 root */
#define DEV_SM_CLK_NOCAPB               (CLOCK_ROOT_NOCAPB + CLOCK_NUM_SRC)          /*!< 106: NOCAPB root */
#define DEV_SM_CLK_NOC                  (CLOCK_ROOT_NOC + CLOCK_NUM_SRC)             /*!< 107: NOC root */
#define DEV_SM_CLK_NPUAPB               (CLOCK_ROOT_NPUAPB + CLOCK_NUM_SRC)          /*!< 108: NPUAPB root */
#define DEV_SM_CLK_NPU                  (CLOCK_ROOT_NPU + CLOCK_NUM_SRC)             /*!< 109: NPU root */
#define DEV_SM_CLK_CCMCKO1              (CLOCK_ROOT_CCMCKO1 + CLOCK_NUM_SRC)         /*!< 110: CCMCKO1 root */
#define DEV_SM_CLK_CCMCKO2              (CLOCK_ROOT_CCMCKO2 + CLOCK_NUM_SRC)         /*!< 111: CCMCKO2 root */
#define DEV_SM_CLK_CCMCKO3              (CLOCK_ROOT_CCMCKO3 + CLOCK_NUM_SRC)         /*!< 112: CCMCKO3 root */
#define DEV_SM_CLK_CCMCKO4              (CLOCK_ROOT_CCMCKO4 + CLOCK_NUM_SRC)         /*!< 113: CCMCKO4 root */
#define DEV_SM_CLK_VPUAPB               (CLOCK_ROOT_VPUAPB + CLOCK_NUM_SRC)          /*!< 114: VPUAPB root */
#define DEV_SM_CLK_VPU                  (CLOCK_ROOT_VPU + CLOCK_NUM_SRC)             /*!< 115: VPU root */
#define DEV_SM_CLK_RESERVED116          (CLOCK_ROOT_RESERVED75 + CLOCK_NUM_SRC)      /*!< 116: RESERVED116 root */
#define DEV_SM_CLK_RESERVED117          (CLOCK_ROOT_RESERVED76 + CLOCK_NUM_SRC)      /*!< 117: RESERVED117 root */
#define DEV_SM_CLK_AUDIOXCVR            (CLOCK_ROOT_AUDIOXCVR + CLOCK_NUM_SRC)       /*!< 118: AUDIOXCVR root */
#define DEV_SM_CLK_BUSWAKEUP            (CLOCK_ROOT_BUSWAKEUP + CLOCK_NUM_SRC)       /*!< 119: BUSWAKEUP root */
#define DEV_SM_CLK_CAN2                 (CLOCK_ROOT_CAN2 + CLOCK_NUM_SRC)            /*!< 120: CAN2 root */
#define DEV_SM_CLK_CAN3                 (CLOCK_ROOT_CAN3 + CLOCK_NUM_SRC)            /*!< 121: CAN3 root */
#define DEV_SM_CLK_CAN4                 (CLOCK_ROOT_CAN4 + CLOCK_NUM_SRC)            /*!< 122: CAN4 root */
#define DEV_SM_CLK_CAN5                 (CLOCK_ROOT_CAN5 + CLOCK_NUM_SRC)            /*!< 123: CAN5 root */
#define DEV_SM_CLK_FLEXIO1              (CLOCK_ROOT_FLEXIO1 + CLOCK_NUM_SRC)         /*!< 124: FLEXIO1 root */
#define DEV_SM_CLK_FLEXIO2              (CLOCK_ROOT_FLEXIO2 + CLOCK_NUM_SRC)         /*!< 125: FLEXIO2 root */
#define DEV_SM_CLK_XSPI1                (CLOCK_ROOT_XSPI1 + CLOCK_NUM_SRC)           /*!< 126: XSPI1 root */
#define DEV_SM_CLK_RESERVED127          (CLOCK_ROOT_RESERVED86 + CLOCK_NUM_SRC)      /*!< 127: RESERVED127 root */
#define DEV_SM_CLK_I3C2SLOW             (CLOCK_ROOT_I3C2SLOW + CLOCK_NUM_SRC)        /*!< 128: I3C2SLOW root */
#define DEV_SM_CLK_LPI2C3               (CLOCK_ROOT_LPI2C3 + CLOCK_NUM_SRC)          /*!< 129: LPI2C3 root */
#define DEV_SM_CLK_LPI2C4               (CLOCK_ROOT_LPI2C4 + CLOCK_NUM_SRC)          /*!< 130: LPI2C4 root */
#define DEV_SM_CLK_LPI2C5               (CLOCK_ROOT_LPI2C5 + CLOCK_NUM_SRC)          /*!< 131: LPI2C5 root */
#define DEV_SM_CLK_LPI2C6               (CLOCK_ROOT_LPI2C6 + CLOCK_NUM_SRC)          /*!< 132: LPI2C6 root */
#define DEV_SM_CLK_LPI2C7               (CLOCK_ROOT_LPI2C7 + CLOCK_NUM_SRC)          /*!< 133: LPI2C7 root */
#define DEV_SM_CLK_LPI2C8               (CLOCK_ROOT_LPI2C8 + CLOCK_NUM_SRC)          /*!< 134: LPI2C8 root */
#define DEV_SM_CLK_LPSPI3               (CLOCK_ROOT_LPSPI3 + CLOCK_NUM_SRC)          /*!< 135: LPSPI3 root */
#define DEV_SM_CLK_LPSPI4               (CLOCK_ROOT_LPSPI4 + CLOCK_NUM_SRC)          /*!< 136: LPSPI4 root */
#define DEV_SM_CLK_LPSPI5               (CLOCK_ROOT_LPSPI5 + CLOCK_NUM_SRC)          /*!< 137: LPSPI5 root */
#define DEV_SM_CLK_LPSPI6               (CLOCK_ROOT_LPSPI6 + CLOCK_NUM_SRC)          /*!< 138: LPSPI6 root */
#define DEV_SM_CLK_LPSPI7               (CLOCK_ROOT_LPSPI7 + CLOCK_NUM_SRC)          /*!< 139: LPSPI7 root */
#define DEV_SM_CLK_LPSPI8               (CLOCK_ROOT_LPSPI8 + CLOCK_NUM_SRC)          /*!< 140: LPSPI8 root */
#define DEV_SM_CLK_LPTMR2               (CLOCK_ROOT_LPTMR2 + CLOCK_NUM_SRC)          /*!< 141: LPTMR2 root */
#define DEV_SM_CLK_LPUART3              (CLOCK_ROOT_LPUART3 + CLOCK_NUM_SRC)         /*!< 142: LPUART3 root */
#define DEV_SM_CLK_LPUART4              (CLOCK_ROOT_LPUART4 + CLOCK_NUM_SRC)         /*!< 143: LPUART4 root */
#define DEV_SM_CLK_LPUART5              (CLOCK_ROOT_LPUART5 + CLOCK_NUM_SRC)         /*!< 144: LPUART5 root */
#define DEV_SM_CLK_LPUART6              (CLOCK_ROOT_LPUART6 + CLOCK_NUM_SRC)         /*!< 145: LPUART6 root */
#define DEV_SM_CLK_LPUART7              (CLOCK_ROOT_LPUART7 + CLOCK_NUM_SRC)         /*!< 146: LPUART7 root */
#define DEV_SM_CLK_LPUART8              (CLOCK_ROOT_LPUART8 + CLOCK_NUM_SRC)         /*!< 147: LPUART8 root */
#define DEV_SM_CLK_SAI3                 (CLOCK_ROOT_SAI3 + CLOCK_NUM_SRC)            /*!< 148: SAI3 root */
#define DEV_SM_CLK_SAI4                 (CLOCK_ROOT_SAI4 + CLOCK_NUM_SRC)            /*!< 149: SAI4 root */
#define DEV_SM_CLK_SAI5                 (CLOCK_ROOT_SAI5 + CLOCK_NUM_SRC)            /*!< 150: SAI5 root */
#define DEV_SM_CLK_SPDIF                (CLOCK_ROOT_SPDIF + CLOCK_NUM_SRC)           /*!< 151: SPDIF root */
#define DEV_SM_CLK_SWOTRACE             (CLOCK_ROOT_SWOTRACE + CLOCK_NUM_SRC)        /*!< 152: SWOTRACE root */
#define DEV_SM_CLK_TPM4                 (CLOCK_ROOT_TPM4 + CLOCK_NUM_SRC)            /*!< 153: TPM4 root */
#define DEV_SM_CLK_TPM5                 (CLOCK_ROOT_TPM5 + CLOCK_NUM_SRC)            /*!< 154: TPM5 root */
#define DEV_SM_CLK_TPM6                 (CLOCK_ROOT_TPM6 + CLOCK_NUM_SRC)            /*!< 155: TPM6 root */
#define DEV_SM_CLK_MIPIPHYDFT400        (CLOCK_ROOT_MIPIPHYDFT400 + CLOCK_NUM_SRC)   /*!< 156: MIPIPHYDFT400 root */
#define DEV_SM_CLK_MIPIPHYDFT540        (CLOCK_ROOT_MIPIPHYDFT540 + CLOCK_NUM_SRC)   /*!< 157: MIPIPHYDFT540 root */
#define DEV_SM_CLK_USDHC1               (CLOCK_ROOT_USDHC1 + CLOCK_NUM_SRC)          /*!< 158: USDHC1 root */
#define DEV_SM_CLK_USDHC2               (CLOCK_ROOT_USDHC2 + CLOCK_NUM_SRC)          /*!< 159: USDHC2 root */
#define DEV_SM_CLK_USDHC3               (CLOCK_ROOT_USDHC3 + CLOCK_NUM_SRC)          /*!< 160: USDHC3 root */
#define DEV_SM_CLK_V2XPK                (CLOCK_ROOT_V2XPK + CLOCK_NUM_SRC)           /*!< 161: V2XPK root */
#define DEV_SM_CLK_WAKEUPAXI            (CLOCK_ROOT_WAKEUPAXI + CLOCK_NUM_SRC)       /*!< 162: WAKEUPAXI root */
#define DEV_SM_CLK_XSPISLVROOT          (CLOCK_ROOT_XSPISLVROOT + CLOCK_NUM_SRC)     /*!< 163: XSPISLVROOT root */
#define DEV_SM_CLK_AUDMIX1              (CLOCK_ROOT_AUDMIX1 + CLOCK_NUM_SRC)         /*!< 164: AUDMIX1 root */
#define DEV_SM_CLK_ASRC1                (CLOCK_ROOT_ASRC1 + CLOCK_NUM_SRC)           /*!< 165: ASRC1 root */
#define DEV_SM_CLK_ASRC2                (CLOCK_ROOT_ASRC2 + CLOCK_NUM_SRC)           /*!< 166: ASRC2 root */
#define DEV_SM_CLK_GPT2                 (CLOCK_ROOT_GPT2 + CLOCK_NUM_SRC)            /*!< 167: GPT2 root */
#define DEV_SM_CLK_GPT3                 (CLOCK_ROOT_GPT3 + CLOCK_NUM_SRC)            /*!< 168: GPT3 root */
#define DEV_SM_CLK_GPT4                 (CLOCK_ROOT_GPT4 + CLOCK_NUM_SRC)            /*!< 169: GPT4 root */
#define DEV_SM_CLK_GPT5                 (CLOCK_ROOT_GPT5 + CLOCK_NUM_SRC)            /*!< 170: GPT5 root */

#define DEV_SM_CLK_EXT_GPR_SEL          (CLOCK_GPR_SEL_EXT + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT)                                                                /*!< 171: EXT GPR SEL mux */
#define DEV_SM_CLK_A55C0_GPR_SEL        (CLOCK_GPR_SEL_A55C0 + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT)                                                                /*!< 172: A55C0 GPR SEL mux */
#define DEV_SM_CLK_A55C1_GPR_SEL        (CLOCK_GPR_SEL_A55C1 + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT)                                                                /*!< 173: A55C2 GPR SEL mux */
#define DEV_SM_CLK_A55C2_GPR_SEL        (CLOCK_GPR_SEL_A55C2 + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT)                                                                /*!< 174: A55C3 GPR SEL mux */
#define DEV_SM_CLK_A55C3_GPR_SEL        (CLOCK_GPR_SEL_A55C3 + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT)                                                                /*!< 175: A55C4 GPR SEL mux */
#define DEV_SM_CLK_A55P_GPR_SEL         (CLOCK_GPR_SEL_A55P + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT)                                                                /*!< 176: A55P GPR SEL mux */
#define DEV_SM_CLK_DRAM_GPR_SEL         (CLOCK_GPR_SEL_DRAM + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT)                                                                /*!< 177: DRAM GPR SEL mux */
#define DEV_SM_CLK_TEMPSENSE_GPR_SEL    (CLOCK_GPR_SEL_TEMPSENSE + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT)                                                                /*!< 178: TEMPSENSE GPR SEL mux */

#define DEV_SM_CLK_NPU_CGC              (CLOCK_CGC_NPU + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 179: NPU CGC */
#define DEV_SM_CLK_GPU_CGC              (CLOCK_CGC_GPU + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 180: GPU CGC */
#define DEV_SM_CLK_CAMISI_CGC           (CLOCK_CGC_CAMISI + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 181: CAMISI CGC */
#define DEV_SM_CLK_CAMISP_CGC           (CLOCK_CGC_CAMISP + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 182: CAMISP CGC */
#define DEV_SM_CLK_CAMCSI0_CGC          (CLOCK_CGC_CAMCSI0 + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 183: CAMCSI0 CGC */
#define DEV_SM_CLK_CAMCSI1_CGC          (CLOCK_CGC_CAMCSI1 + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 184: CAMCSI1 CGC */
#define DEV_SM_CLK_CAMOCRAM_CGC         (CLOCK_CGC_CAMOCRAM + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 185: CAMOCRAM CGC */
#define DEV_SM_CLK_HSIOUSB_CGC          (CLOCK_CGC_HSIOUSB + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 186: HSIOUSB CGC */
#define DEV_SM_CLK_HSIOPCIE_CGC         (CLOCK_CGC_HSIOPCIE + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 187: HSIOPCIE CGC */
#define DEV_SM_CLK_DISPOCRAM_CGC       (CLOCK_CGC_DISPOCRAM + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 188: DISPOCRAM CGC */
#define DEV_SM_CLK_DISPSEERIS_CGC       (CLOCK_CGC_DISPSEERIS + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 189: DISPSEERIS CGC */
#define DEV_SM_CLK_DISPDSI_CGC          (CLOCK_CGC_DISPDSI + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 190: DISPDSI CGC */
#define DEV_SM_CLK_NOCGIC_CGC           (CLOCK_CGC_NOCGIC + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 191: NOCGIC CGC */
#define DEV_SM_CLK_NOCOCRAM_CGC         (CLOCK_CGC_NOCOCRAM + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 192: NOCOCRAM CGC */
#define DEV_SM_CLK_NETC_CGC             (CLOCK_CGC_NETC + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 193: NETC CGC */
#define DEV_SM_CLK_VPUENC_CGC           (CLOCK_CGC_VPUENC + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 194: VPUENC CGC */
#define DEV_SM_CLK_VPUJPEGENC_CGC       (CLOCK_CGC_VPUJPEGENC + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 195: VPUJPEGENC CGC */
#define DEV_SM_CLK_VPUJPEGDEC_CGC       (CLOCK_CGC_VPUJPEGDEC + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 196: VPUJPEGDEC CGC */
#define DEV_SM_CLK_VPUDEC_CGC           (CLOCK_CGC_VPUDEC + CLOCK_NUM_SRC \
    + CLOCK_NUM_ROOT + CLOCK_NUM_GPR_SEL)                                            /*!< 197: VPUDEC CGC */
/** @} */

/*!
 * @name Device round parameters
 */
/** @{ */
#define DEV_SM_CLOCK_ROUND_DOWN  0x0U   /*!< Round rate down */
#define DEV_SM_CLOCK_ROUND_UP    0x1U   /*!< Round rate up */
#define DEV_SM_CLOCK_ROUND_AUTO  0x2U   /*!< Automatically select closest rate */
/** @} */

/*!
 * @addtogroup DEV_SM_CLOCK_Ext_Configuration DEV_SM_CLOCK Extended Configuration
 * @{
 */

/*! Number of extended clock attributes */
#define DEV_SM_NUM_CLOCK_EXT        2U

/*!
 * @name Device extended clock configuration type
 */
/** @{ */
#define DEV_SM_CLOCK_EXT_SSC        0x80U   /*!< Spread spectrum extended clock type */
#define DEV_SM_CLOCK_EXT_SRCPRE     0x81U   /*!< Clock source prepare extended attribute */
/** @} */

/*!
 * @name Device extended clock configuration SSC (spread spectrum)
 */
/** @{ */
#define DEV_SM_CLOCK_EXT_SSC_PERCENTAGE_MASK   (0xFFU) /*!< SSC Percentage Mask */
#define DEV_SM_CLOCK_EXT_SSC_PERCENTAGE_SHIFT  (0U) /*!< SSC Percentage Shift */
#define DEV_SM_CLOCK_EXT_SSC_PERCENTAGE(x)     (((uint32_t)(((uint32_t)(x)) << DEV_SM_CLOCK_EXT_SSC_PERCENTAGE_SHIFT)) & DEV_SM_CLOCK_EXT_SSC_PERCENTAGE_MASK) /*!< SSC Percentage */

#define DEV_SM_CLOCK_EXT_SSC_MOD_FREQ_MASK     (0xFFFF00U) /*!< SSC Modulation Frequency Mask */
#define DEV_SM_CLOCK_EXT_SSC_MOD_FREQ_SHIFT    (8U) /*!< SSC Modulation Frequency Shift */
#define DEV_SM_CLOCK_EXT_SSC_MOD_FREQ(x)       (((uint32_t)(((uint32_t)(x)) << DEV_SM_CLOCK_EXT_SSC_MOD_FREQ_SHIFT)) & DEV_SM_CLOCK_EXT_SSC_MOD_FREQ_MASK) /*!< SSC Modulation Frequency */

#define DEV_SM_CLOCK_EXT_SSC_ENABLE_MASK       (0x1000000U) /*!< SSC Enable Mask */
#define DEV_SM_CLOCK_EXT_SSC_ENABLE_SHIFT      (24U) /*!< SSC Enable Shift */
#define DEV_SM_CLOCK_EXT_SSC_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << DEV_SM_CLOCK_EXT_SSC_ENABLE_SHIFT)) & DEV_SM_CLOCK_EXT_SSC_ENABLE_MASK) /*!< SSC Enable */
/** @} */

/*!
 * @}
 */ /* end of group DEV_SM_CLOCK_Ext_Configuration */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

/* coverity[misra_c_2012_rule_20_1_violation] */
#include "dev_sm_clock_api.h"

#endif /* DEV_SM_CLOCK_H */

