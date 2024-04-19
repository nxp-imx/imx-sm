/*
 * Copyright 2023 NXP
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

#ifndef DRV_RST_H
#define DRV_RST_H

/*!
 * @addtogroup RST_driver
 * @{
 */

/*! @file */

/* Includes */

#include "fsl_common.h"

/* Defines */

#define RST_NUM_REASONS                 32UL

#define RST_REASON_CM33_LOCKUP          0U
#define RST_REASON_CM33_SWREQ           1U
#define RST_REASON_CM7_LOCKUP           2U
#define RST_REASON_CM7_SWREQ            3U
#define RST_REASON_FCCU                 4U
#define RST_REASON_JTAG_SW              5U
#define RST_REASON_SENTINEL             6U
#define RST_REASON_TEMPSENSE            7U
#define RST_REASON_WDOG1                8U
#define RST_REASON_WDOG2                9U
#define RST_REASON_WDOG3                10U
#define RST_REASON_WDOG4                11U
#define RST_REASON_WDOG5                12U
#define RST_REASON_JTAG                 13U
#define RST_REASON_CM33_EXC             14U
#define RST_REASON_UNUSED0              15U
#define RST_REASON_UNUSED1              16U
#define RST_REASON_UNUSED2              17U
#define RST_REASON_UNUSED3              18U
#define RST_REASON_UNUSED4              19U
#define RST_REASON_UNUSED5              20U
#define RST_REASON_UNUSED6              21U
#define RST_REASON_UNUSED7              22U
#define RST_REASON_UNUSED8              23U
#define RST_REASON_UNUSED9              24U
#define RST_REASON_UNUSED10             25U
#define RST_REASON_UNUSED11             26U
#define RST_REASON_UNUSED12             27U
#define RST_REASON_UNUSED13             28U
#define RST_REASON_UNUSED14             29U
#define RST_REASON_UNUSED15             30U
#define RST_REASON_POR                  31U

#define RST_LINE_CTRL_DEASSERT          0U
#define RST_LINE_CTRL_ASSERT            1U
#define RST_LINE_CTRL_TOGGLE            2U
#define RST_LINE_CTRL_UNKNOWN           3U

#define RST_NUM_LINE                    58U

/* Individual resets (IRST) */
#define RST_LINE_A55C0_NCPUPORESET      0U
#define RST_LINE_A55C0_NCORERESET       1U
#define RST_LINE_A55C1_NCPUPORESET      2U
#define RST_LINE_A55C1_NCORERESET       3U
#define RST_LINE_A55C2_NCPUPORESET      4U
#define RST_LINE_A55C2_NCORERESET       5U
#define RST_LINE_A55C3_NCPUPORESET      6U
#define RST_LINE_A55C3_NCORERESET       7U
#define RST_LINE_A55C4_NCPUPORESET      8U
#define RST_LINE_A55C4_NCORERESET       9U
#define RST_LINE_A55C5_NCPUPORESET      10U
#define RST_LINE_A55C5_NCORERESET       11U
#define RST_LINE_A55P_NPRESET           12U
#define RST_LINE_A55P_NSPORESET         13U
#define RST_LINE_A55P_NSRESET           14U
#define RST_LINE_A55P_NATRESET          15U
#define RST_LINE_A55P_NGICRESET         16U
#define RST_LINE_A55P_NPERIPHRESET      17U
#define RST_LINE_DDRPHY_PRESETN         18U
#define RST_LINE_DDRPHY_RESETN          19U
#define RST_LINE_DISP0_RESETN           20U
#define RST_LINE_DISP1_RESETN           21U
#define RST_LINE_LVDS_RESETN            22U
#define RST_LINE_USB1PHY_RESETN         23U
#define RST_LINE_USB2PHY_RESETN         24U
#define RST_LINE_PCIE1PHY_RESETN        25U
#define RST_LINE_PCIE2PHY_RESETN        26U
#define RST_LINE_ENETPHY_PCS_RESETN     27U
#define RST_LINE_V2X_RESETB             28U

/* Regional resets (RSTR) */      
#define RST_LINE_ANAMIX                 29U
#define RST_LINE_AONMIX_TOP             30U
#define RST_LINE_AONMIX_M33             31U
#define RST_LINE_AONMIX_SENTINEL        32U
#define RST_LINE_BBSMMIX                33U
#define RST_LINE_CAMERAMIX              34U
#define RST_LINE_CCMSRCGPCMIX           35U
#define RST_LINE_CORTEXAMIX_CORE0       36U
#define RST_LINE_CORTEXAMIX_CORE1       37U
#define RST_LINE_CORTEXAMIX_CORE2       38U
#define RST_LINE_CORTEXAMIX_CORE3       39U
#define RST_LINE_CORTEXAMIX_CORE4       40U
#define RST_LINE_CORTEXAMIX_CORE5       41U
#define RST_LINE_CORTEXAMIX_PLATFORM    42U
#define RST_LINE_DDRMIX_TOP             43U
#define RST_LINE_DDRMIX_PHY             44U
#define RST_LINE_DISPLAYMIX             45U
#define RST_LINE_GPUMIX                 46U
#define RST_LINE_HSIOMIX_TOP            47U
#define RST_LINE_HSIOMIX_WAON           48U
#define RST_LINE_M7MIX                  49U
#define RST_LINE_NETCMIX                50U
#define RST_LINE_NOCMIX                 51U
#define RST_LINE_NPUMIX                 52U
#define RST_LINE_VPUMIX                 53U
#define RST_LINE_WAKEUPMIX_TOP          54U
#define RST_LINE_WAKEUPMIX_JTAG         55U
#define RST_LINE_WAKEUPMIX_WDOG_3_4     56U
#define RST_LINE_WAKEUPMIX_WDOG_5       57U

#define SRC_MIX_BASE_PTRS               SRC_XSPR_BASE_PTRS
#define A55_HDSK_ACK_CTRL_CNT_MODE_MASK SRC_XSPR_A55_HDSK_ACK_CTRL_CNT_MODE_MASK
#define A55_HDSK_ACK_CTRL_CNT_MODE_MASK SRC_XSPR_A55_HDSK_ACK_CTRL_CNT_MODE_MASK
#define A55_HDSK_ACK_CTRL_CNT_MODE      SRC_XSPR_A55_HDSK_ACK_CTRL_CNT_MODE
#define FUNC_STAT_PSW_STAT_MASK         SRC_XSPR_FUNC_STAT_PSW_STAT_MASK
#define FUNC_STAT_MEM_STAT_MASK         SRC_XSPR_FUNC_STAT_MEM_STAT_MASK
#define AUTHEN_CTRL_LPM_MODE_MASK       SRC_XSPR_AUTHEN_CTRL_LPM_MODE_MASK
#define AUTHEN_CTRL_WHITELIST_SHIFT     SRC_XSPR_AUTHEN_CTRL_WHITE_LIST_SHIFT
#define SLICE_SW_CTRL_PDN_SOFT_MASK     SRC_XSPR_SLICE_SW_CTRL_PDN_SOFT_MASK


/* Types */

typedef SRC_XSPR_Type src_mix_slice_t;
typedef SRC_MEM_Type src_mem_slice_t;
typedef SRC_GEN_Type src_generic_t;

typedef struct
{
    uint32_t lineMask;
    __IO uint32_t *lineReg;
    uint32_t statMask;
    __I uint32_t *statReg;
    bool assertLow;
    uint32_t toggleUsec;
} rst_line_info_t;

/* Functions */

uint32_t RST_SystemGetResetReason(void);
void RST_SystemClearResetReason(uint32_t resetReason);
void RST_SystemRequestReset(void);

/* Externs */

extern rst_line_info_t const g_rstLineInfo[];

#endif /* DRV_RST_H */

/** @} */
