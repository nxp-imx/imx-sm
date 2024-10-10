/*
** ###################################################################
**
**     Copyright 2023 NXP
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

#ifndef DEV_SM_RST_H
#define DEV_SM_RST_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX95_RESET
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device reset domains.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "fsl_reset.h"

/* Defines */

/*! Number of device reset domains */
#define DEV_SM_NUM_RESET  RST_NUM_LINE

/*!
 * @name Device reset domain indexes
 */
/** @{ */
#define DEV_SM_RST_A55C0_NCPUPORESET   RST_LINE_A55C0_NCPUPORESET   /*!< 0: A55C0 NCPUPORESET */
#define DEV_SM_RST_A55C0_NCORERESET    RST_LINE_A55C0_NCORERESET    /*!< 1: A55C0 NCORERESET */
#define DEV_SM_RST_A55C1_NCPUPORESET   RST_LINE_A55C1_NCPUPORESET   /*!< 2: A55C1 NCPUPORESET */
#define DEV_SM_RST_A55C1_NCORERESET    RST_LINE_A55C1_NCORERESET    /*!< 3: A55C1 NCORERESET */
#define DEV_SM_RST_A55C2_NCPUPORESET   RST_LINE_A55C2_NCPUPORESET   /*!< 4: A55C2 NCPUPORESET */
#define DEV_SM_RST_A55C2_NCORERESET    RST_LINE_A55C2_NCORERESET    /*!< 5: A55C2 NCORERESET */
#define DEV_SM_RST_A55C3_NCPUPORESET   RST_LINE_A55C3_NCPUPORESET   /*!< 6: A55C3 NCPUPORESET */
#define DEV_SM_RST_A55C3_NCORERESET    RST_LINE_A55C3_NCORERESET    /*!< 7: A55C3 NCORERESET */
#define DEV_SM_RST_A55C4_NCPUPORESET   RST_LINE_A55C4_NCPUPORESET   /*!< 8: A55C4 NCPUPORESET */
#define DEV_SM_RST_A55C4_NCORERESET    RST_LINE_A55C4_NCORERESET    /*!< 9: A55C4 NCORERESET */
#define DEV_SM_RST_A55C5_NCPUPORESET   RST_LINE_A55C5_NCPUPORESET   /*!< 10: A55C5 NCPUPORESET */
#define DEV_SM_RST_A55C5_NCORERESET    RST_LINE_A55C5_NCORERESET    /*!< 11: A55C5 NCORERESET */
#define DEV_SM_RST_A55P_NPRESET        RST_LINE_A55P_NPRESET        /*!< 12: A55P NPRESET */
#define DEV_SM_RST_A55P_NSPORESET      RST_LINE_A55P_NSPORESET      /*!< 13: A55P NSPORESET */
#define DEV_SM_RST_A55P_NSRESET        RST_LINE_A55P_NSRESET        /*!< 14: A55P NSRESET */
#define DEV_SM_RST_A55P_NATRESET       RST_LINE_A55P_NATRESET       /*!< 15: A55P NATRESET */
#define DEV_SM_RST_A55P_NGICRESET      RST_LINE_A55P_NGICRESET      /*!< 16: A55P NGICRESET */
#define DEV_SM_RST_A55P_NPERIPHRESET   RST_LINE_A55P_NPERIPHRESET   /*!< 17: A55P NPERIPHRESET */
#define DEV_SM_RST_DDRPHY_PRESETN      RST_LINE_DDRPHY_PRESETN      /*!< 18: DDRPHY PRESETN */
#define DEV_SM_RST_DDRPHY_RESETN       RST_LINE_DDRPHY_RESETN       /*!< 19: DDRPHY RESETN */
#define DEV_SM_RST_DISP0_RESETN        RST_LINE_DISP0_RESETN        /*!< 20: DISP0 RESETN */
#define DEV_SM_RST_DISP1_RESETN        RST_LINE_DISP1_RESETN        /*!< 21: DISP1 RESETN */
#define DEV_SM_RST_LVDS_RESETN         RST_LINE_LVDS_RESETN         /*!< 22: LVDS RESETN */
#define DEV_SM_RST_USB1PHY_RESETN      RST_LINE_USB1PHY_RESETN      /*!< 23: USB1PHY RESETN */
#define DEV_SM_RST_USB2PHY_RESETN      RST_LINE_USB2PHY_RESETN      /*!< 24: USB2PHY RESETN */
#define DEV_SM_RST_PCIE1PHY_RESETN     RST_LINE_PCIE1PHY_RESETN     /*!< 25: PCIE1PHY RESETN */
#define DEV_SM_RST_PCIE2PHY_RESETN     RST_LINE_PCIE2PHY_RESETN     /*!< 26: PCIE2PHY RESETN */
#define DEV_SM_RST_ENETPHY_PCS_RESETN  RST_LINE_ENETPHY_PCS_RESETN  /*!< 27: ENETPHY PCS RESETN */
#define DEV_SM_RST_V2X_RESETB          RST_LINE_V2X_RESETB          /*!< 28: V2X RESETB */
/** @} */

/*!
 * @name Device reset domain states
 */
/** @{ */
#define DEV_SM_RST_COLD  0U  /*!< Cold reset - no retention */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

// coverity[misra_c_2012_rule_20_1_violation:FALSE]
#include "dev_sm_reset_api.h"

#endif /* DEV_SM_RST_H */

