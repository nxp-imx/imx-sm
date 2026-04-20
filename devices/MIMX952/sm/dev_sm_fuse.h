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

#ifndef DEV_SM_FUSE_H
#define DEV_SM_FUSE_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX952_FUSE
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device fuses.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device fuses */
#define DEV_SM_NUM_FUSE  27U

/*! Size of OTP */
#define DEV_SM_NUM_OTP  610U

/*!
 * @name Device fuse indexes
 */
/** @{ */
#define DEV_SM_FUSE_SI_REV             0U   /*!< Silicon revision */
#define DEV_SM_FUSE_PART_NUM           1U   /*!< Part number */
#define DEV_SM_FUSE_MARKET_SEGMENT     2U   /*!< Market segment */
#define DEV_SM_FUSE_SPEED_GRADING      3U   /*!< Speed grading */
#define DEV_SM_FUSE_NPU_DISABLE        4U   /*!< NPU disable */
#define DEV_SM_FUSE_A55_CORE_DISABLE   5U   /*!< A55 cores disable */
#define DEV_SM_FUSE_A55_CORE0_DISABLE  6U   /*!< A55 core 0 disable */
#define DEV_SM_FUSE_A55_CORE1_DISABLE  7U   /*!< A55 core 1 disable */
#define DEV_SM_FUSE_A55_CORE2_DISABLE  8U   /*!< A55 core 2 disable */
#define DEV_SM_FUSE_A55_CORE3_DISABLE  9U   /*!< A55 core 3 disable */
#define DEV_SM_FUSE_DCSS_DISABLE       10U  /*!< Display controller disable */
#define DEV_SM_FUSE_ISP_DISABLE        11U  /*!< ISP disable */
#define DEV_SM_FUSE_PCIE1_DISABLE      12U  /*!< PCIe1 disable */
#define DEV_SM_FUSE_GPU3D_DISABLE      13U  /*!< GPU disable */
#define DEV_SM_FUSE_VPU_DISABLE        14U  /*!< VPU disable */
#define DEV_SM_FUSE_TSENSOR0_TRIM1     15U  /*!< ANA sensor trim 1 */
#define DEV_SM_FUSE_TSENSOR0_TRIM2     16U  /*!< ANA sensor trim 2 */
#define DEV_SM_FUSE_TSENSOR1_TRIM1     17U  /*!< A55 sensor trim 1 */
#define DEV_SM_FUSE_TSENSOR1_TRIM2     18U  /*!< A55 sensor trim 2 */
#define DEV_SM_FUSE_FRO_TRIM           19U  /*!< FRO trim */
#define DEV_SM_FUSE_M33_ROM_PATCH_VER  20U  /*!< M33 ROM patch version */
#define DEV_SM_FUSE_ECID3              21U  /*!< ECID 3 */
#define DEV_SM_FUSE_ECID2              22U  /*!< ECID 2 */
#define DEV_SM_FUSE_ECID1              23U  /*!< ECID 1 */
#define DEV_SM_FUSE_ECID0              24U  /*!< ECID 0 */
#define DEV_SM_FUSE_PMRO               25U  /*!< PMRO */
#define DEV_SM_FUSE_DIMMING            26U  /*!< Local dimming */
/** @} */

/*! Extract PN package */
#define DEV_SM_PN_PKG(X)   (((X) >> 6U) & 0x3U)
/*! Extract PN segment */
#define DEV_SM_PN_SEG(X)   (((X) >> 2U) & 0xFU)
/*! Extract PN core count */
#define DEV_SM_PN_CORE(X)  ((X) & 0x3U)

/*!
 * @name PN packages
 */
/** @{ */
#define DEV_SM_PN_PKG_VT  1U  /*!< 15x15 no lid */
#define DEV_SM_PN_PKG_VY  2U  /*!< 19x19 lidded */
#define DEV_SM_PN_PKG_VZ  3U  /*!< 19x19 no lid */
/** @} */

/*!
 * @name PN core count
 */
/** @{ */
#define DEV_SM_PN_CORE_2  1U  /*!< 2 cores */
#define DEV_SM_PN_CORE_4  2U  /*!< 4 cores */
#define DEV_SM_PN_CORE_6  3U  /*!< 6 cores */
/** @} */

/*!
 * @name PN letter arrays
 */
/** @{ */
/*! Letters for PN package */
#define DEV_SM_PN_LTR_PKG   "XTYZ"
/*! Letters for PN segment */
#define DEV_SM_PN_LTR_SEG   "0123456789TVGCIN"
/*! Letters for PN core count */
#define DEV_SM_PN_LTR_CORE  "1246"
/*! Letters for market segment/temp */
#define DEV_SM_LTR_MKT     "DXCA"
/*! Letters for local dimming */
#define DEV_SM_LTR_LD      "BA"
/** @} */

/* Types */

/* Functions */

/*!
 * Set fuse state (cached).
 *
 * @param[in]     fuseId      Id of fuse to read
 * @param[in]     fuseVal     Value to set
 *
 */
void DEV_SM_FuseSet(uint32_t fuseId, uint32_t fuseVal);

/*!
 * Get speed grade frequency.
 *
 * @return Returns the speed grade frequency in Hz.
 */
uint32_t DEV_SM_FuseSpeedGet(void);

/** @} */

/* Include SM device API */

/* coverity[misra_c_2012_rule_20_1_violation] */
#include "dev_sm_fuse_api.h"

#endif /* DEV_SM_FUSE_H */

