/*
 * Copyright 2026 NXP
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
 * @addtogroup MX952_RST_driver
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the MX952 Reset Driver.
 */
/*==========================================================================*/

#ifndef DRV_RST_H
#define DRV_RST_H

/* Includes */

#include "fsl_common.h"

/* Defines */

#ifndef DOXYGEN

#define RST_NUM_REASONS                 32UL

#define RST_REASON_CM33_LOCKUP          0U
#define RST_REASON_CM33_SWREQ           1U
#define RST_REASON_CM7_LOCKUP           2U
#define RST_REASON_CM7_SWREQ            3U
#define RST_REASON_FCCU                 4U
#define RST_REASON_JTAG_SW              5U
#define RST_REASON_ELE                  6U
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

#define RST_NUM_LINE                    52U

/* Individual resets (IRST) */
#define RST_LINE_A55C0_NCPUPORESET      0U
#define RST_LINE_A55C0_NCORERESET       1U
#define RST_LINE_A55C1_NCPUPORESET      2U
#define RST_LINE_A55C1_NCORERESET       3U
#define RST_LINE_A55C2_NCPUPORESET      4U
#define RST_LINE_A55C2_NCORERESET       5U
#define RST_LINE_A55C3_NCPUPORESET      6U
#define RST_LINE_A55C3_NCORERESET       7U
#define RST_LINE_A55P_NPRESET           8U
#define RST_LINE_A55P_NSPORESET         9U
#define RST_LINE_A55P_NSRESET           10U
#define RST_LINE_A55P_NATRESET          11U
#define RST_LINE_A55P_NGICRESET         12U
#define RST_LINE_A55P_NPERIPHRESET      13U
#define RST_LINE_DDRPHY_PRESETN         14U
#define RST_LINE_DDRPHY_RESETN          15U
#define RST_LINE_DISP0_RESETN           16U
#define RST_LINE_DISP1_RESETN           17U
#define RST_LINE_LVDS_RESETN            18U
#define RST_LINE_USB1PHY_RESETN         19U
#define RST_LINE_USB2PHY_RESETN         20U
#define RST_LINE_PCIE1PHY_RESETN        21U
#define RST_LINE_ENETPHY_PCS_RESETN     22U
#define RST_LINE_GIC_RESET              23U
#define RST_LINE_V2X_RESETB             24U

/* Regional resets (RSTR) */
#define RST_LINE_ANAMIX                 25U
#define RST_LINE_AONMIX_TOP             26U
#define RST_LINE_AONMIX_M33             27U
#define RST_LINE_AONMIX_ELE             28U
#define RST_LINE_BBSMMIX                29U
#define RST_LINE_CAMERAMIX              30U
#define RST_LINE_CCMSRCGPCMIX           31U
#define RST_LINE_CORTEXAMIX_CORE0       32U
#define RST_LINE_CORTEXAMIX_CORE1       33U
#define RST_LINE_CORTEXAMIX_CORE2       34U
#define RST_LINE_CORTEXAMIX_CORE3       35U
#define RST_LINE_CORTEXAMIX_PLATFORM    36U
#define RST_LINE_DDRMIX_TOP             37U
#define RST_LINE_DDRMIX_PHY             38U
#define RST_LINE_DISPLAYMIX             39U
#define RST_LINE_GPUMIX                 40U
#define RST_LINE_HSIOMIX_TOP            41U
#define RST_LINE_HSIOMIX_WAON           42U
#define RST_LINE_M7MIX                  43U
#define RST_LINE_NETCMIX                44U
#define RST_LINE_NOCMIX                 45U
#define RST_LINE_NPUMIX                 46U
#define RST_LINE_VPUMIX                 47U
#define RST_LINE_WAKEUPMIX_TOP          48U
#define RST_LINE_WAKEUPMIX_JTAG         49U
#define RST_LINE_WAKEUPMIX_WDOG_3_4     50U
#define RST_LINE_WAKEUPMIX_WDOG_5       51U

#define SRC_MIX_BASE_PTRS               SRC_XSPR_BASE_PTRS
#define A55_HDSK_ACK_CTRL_CNT_MODE_MASK SRC_XSPR_A55_HDSK_ACK_CTRL_CNT_MODE_MASK
#define A55_HDSK_ACK_CTRL_CNT_MODE      SRC_XSPR_A55_HDSK_ACK_CTRL_CNT_MODE
#define FUNC_STAT_PSW_STAT_MASK         SRC_XSPR_FUNC_STAT_PSW_STAT_MASK
#define FUNC_STAT_MEM_STAT_MASK         SRC_XSPR_FUNC_STAT_MEM_STAT_MASK
#define AUTHEN_CTRL_LPM_MODE_MASK       SRC_XSPR_AUTHEN_CTRL_LPM_MODE_MASK
#define AUTHEN_CTRL_WHITELIST_SHIFT     SRC_XSPR_AUTHEN_CTRL_WHITE_LIST_SHIFT
#define SLICE_SW_CTRL_PDN_SOFT_MASK     SRC_XSPR_SLICE_SW_CTRL_PDN_SOFT_MASK

/* Reset line flags */
#define RST_LINE_FLAG_RESTRICTED        (1U << 0U)  /* Reset line usage is restricted */

#endif

/* Types */

/*! SRC power region mix slice register structure */
typedef SRC_XSPR_Type src_mix_slice_t;

/*! SRC power region memory slice register structure */
typedef SRC_MEM_Type src_mem_slice_t;

/*! SRC general register structure */
typedef SRC_GEN_Type src_generic_t;

/*! Structure for reset line details */
typedef struct
{
    uint32_t flags;         /*!< Reset line flags */
    uint32_t lineMask;      /*!< Reset line control mask register */
    __IO uint32_t *lineReg; /*!< Reset line control register */
    uint32_t statMask;      /*!< Reset line status mask */
    __I uint32_t *statReg;  /*!< Reset line status register */
    bool assertLow;         /*!< Assert signal (low/high) */
    uint32_t toggleUsec;    /*!< Delay during reset toggle */
} rst_line_info_t;

/* Functions */

/*!
 * Get system reset reason
 *
 * This function allows caller to get reset reason from SRESR (SRC recent event
 * status register).
 *
 * @return Returns system reset reason captured by SRES (SRC Reset Events
 *         Status) register. Defaults to reset reason as POR if SRES bits are
 *         cleared.
 */
uint32_t RST_SystemGetResetReason(void);

/*!
 * Clear system reset reason
 *
 * @param[in]       resetReason       Reset reason identifier
 *
 * This function allows caller to clear given \a resetReason in SRESR (SRC
 * recent event status register).
 */
void RST_SystemClearResetReason(uint32_t resetReason);

/*!
 * Query if reset line management is restricted.
 *
 * @param[in]   lineIdx     Reset line identifier
 *
 * This function queries if the management of the specified reset line is
 * restricted to protect the operation of the system manager.
 *
 * @return Returns true if the management of the reset line is restricted.
 */
bool RST_ResetLineRestricted(uint32_t lineIdx);

/*!
 * Request system reset
 *
 * This function allows caller to request system reset.
 */
void RST_SystemRequestReset(void);

/* Externs */

/*! Reset line information */
extern rst_line_info_t const g_rstLineInfo[];

#endif /* DRV_RST_H */

/** @} */

