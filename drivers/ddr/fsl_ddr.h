/*
 ** ###################################################################
 **
 **     Copyright 2024 NXP
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

#ifndef DEV_SM_DDR_H
#define DEV_SM_DDR_H

/*==========================================================================*/
/*!
 * @addtogroup ddr_driver
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the DDR retention functions.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/*! DDR controller info. */
struct ddrc {
    /*! drc register offset */
    uint32_t reg;
    /*! value of the drc reg */
    uint32_t val;
};

/*! DDR phy info. */
struct ddrphy {
    /*! ddr phy register offset */
    uint32_t reg;
    /*! value of the drc phy reg */
    uint16_t val;
};

/*! DDR controller pstate info. */
struct ddrc_pstate {
    /*! drc pstate config */
    struct ddrc *cfg;
    /*! number of pstate specific drc config */
    uint32_t cfg_num;
};

/*! DDR config info. */
struct ddr_info {
    /*! ddrc config */
    struct ddrc *ddrc_cfg;
    /*! ddrc number of regs */
    uint32_t ddrc_cfg_num;
    /*! ddrc pstate config */
    struct ddrc_pstate *pstate;
    /*! number of pstates */
    uint32_t pstate_num;
    /*! ddr phy trained CSR */
    struct ddrphy *trained_csr;
    /*! ddr phy number of trained regs */
    uint32_t ddrphy_trained_csr_num;
    /*! pstate freq table */
    uint32_t pstate_freq[4];
    /*! ZQ calibration PU */
    uint32_t ZQCalCodePU;
    /*! ZQ calibration PD */
    uint32_t ZQCalCodePD;
};

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * Set the DRAM into retention for low power mode
 *
 * @param[in]     ddrp    DDR config info.
 *
 * @return True if successful.
 */
bool DDR_EnterRetention(const struct ddr_info *ddrp);

/*!
 * Exit DRAM retention
 *
 * @param[in]     ddrp    DDR config info.
 *
 * @return True if successful.
 */
bool DDR_ExitRetention(const struct ddr_info *ddrp);

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/** @} */
#endif /* DEV_SM_DDR_H */

