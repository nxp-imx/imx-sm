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

/*==========================================================================*/
/* File containing the implementation of the device reset domains.          */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "fsl_src.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Return reset domain name                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ResetDomainNameGet(uint32_t domainId, string *domainNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_RESET] =
    {
        [RST_LINE_A55C0_NCPUPORESET] =   "a55c0_ncpuporeset",
        [RST_LINE_A55C0_NCORERESET] =    "a55c0_ncorereset",
        [RST_LINE_A55C1_NCPUPORESET] =   "a55c1_ncpuporeset",
        [RST_LINE_A55C1_NCORERESET] =    "a55c1_ncorereset",
        [RST_LINE_A55C2_NCPUPORESET] =   "a55c2_ncpuporeset",
        [RST_LINE_A55C2_NCORERESET] =    "a55c2_ncorereset",
        [RST_LINE_A55C3_NCPUPORESET] =   "a55c3_ncpuporeset",
        [RST_LINE_A55C3_NCORERESET] =    "a55c3_ncorereset",
        [RST_LINE_A55C4_NCPUPORESET] =   "a55c4_ncpuporeset",
        [RST_LINE_A55C4_NCORERESET] =    "a55c4_ncorereset",
        [RST_LINE_A55C5_NCPUPORESET] =   "a55c5_ncpuporeset",
        [RST_LINE_A55C5_NCORERESET] =    "a55c5_ncorereset",
        [RST_LINE_A55P_NPRESET] =        "a55p_npreset",
        [RST_LINE_A55P_NSPORESET] =      "a55p_nsporeset",
        [RST_LINE_A55P_NSRESET] =        "a55p_nsreset",
        [RST_LINE_A55P_NATRESET] =       "a55p_natreset",
        [RST_LINE_A55P_NGICRESET] =      "a55p_ngicreset",
        [RST_LINE_A55P_NPERIPHRESET] =   "a55p_nperiphreset",
        [RST_LINE_DDRPHY_PRESETN] =      "ddrphy_presetn",
        [RST_LINE_DDRPHY_RESETN] =       "ddrphy_resetn",
        [RST_LINE_DISP0_RESETN] =        "disp0_resetn",
        [RST_LINE_DISP1_RESETN] =        "disp1_resetn",
        [RST_LINE_LVDS_RESETN] =         "lvds_resetn",
        [RST_LINE_USB1PHY_RESETN] =      "usb1phy_resetn",
        [RST_LINE_USB2PHY_RESETN] =      "usb2phy_resetn",
        [RST_LINE_PCIE1PHY_RESETN] =     "pcie1phy_resetn",
        [RST_LINE_PCIE2PHY_RESETN] =     "pcie2phy_resetn",
        [RST_LINE_ENETPHY_PCS_RESETN] =  "enetphy_pcs_resetn",
        [RST_LINE_V2X_RESETB] =          "v2x_resetb",

        [RST_LINE_ANAMIX] =              "anamix",
        [RST_LINE_AONMIX_TOP] =          "aonmix_top",
        [RST_LINE_AONMIX_M33] =          "aonmix_m33",
        [RST_LINE_AONMIX_ELE] =          "aonmix_ele",
        [RST_LINE_BBSMMIX] =             "bbsmmix",
        [RST_LINE_CAMERAMIX] =           "cameramix",
        [RST_LINE_CCMSRCGPCMIX] =        "ccmsrcgpcmix",
        [RST_LINE_CORTEXAMIX_CORE0] =    "cortexamix_core0",
        [RST_LINE_CORTEXAMIX_CORE1] =    "cortexamix_core1",
        [RST_LINE_CORTEXAMIX_CORE2] =    "cortexamix_core2",
        [RST_LINE_CORTEXAMIX_CORE3] =    "cortexamix_core3",
        [RST_LINE_CORTEXAMIX_CORE4] =    "cortexamix_core4",
        [RST_LINE_CORTEXAMIX_CORE5] =    "cortexamix_core5",
        [RST_LINE_CORTEXAMIX_PLATFORM] = "cortexamix_platform",
        [RST_LINE_DDRMIX_TOP] =          "ddrmix_top",
        [RST_LINE_DDRMIX_PHY] =          "ddrmix_phy",
        [RST_LINE_DISPLAYMIX] =          "displaymix",
        [RST_LINE_GPUMIX] =              "gpumix",
        [RST_LINE_HSIOMIX_TOP] =         "hsiomix_top",
        [RST_LINE_HSIOMIX_WAON] =        "hsiomix_waon",
        [RST_LINE_M7MIX] =               "m7mix",
        [RST_LINE_NETCMIX] =             "netcmix",
        [RST_LINE_NOCMIX] =              "nocmix",
        [RST_LINE_NPUMIX] =              "npumix",
        [RST_LINE_VPUMIX] =              "vpumix",
        [RST_LINE_WAKEUPMIX_TOP] =       "wakeupmix_top",
        [RST_LINE_WAKEUPMIX_JTAG] =      "wakeupmix_jtag",
        [RST_LINE_WAKEUPMIX_WDOG_3_4] =  "wakeupmix_wdog_3_4",
        [RST_LINE_WAKEUPMIX_WDOG_5] =    "wakeupmix_wdog_5"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_RESET);

    /* Check reset */
    if (domainId >= DEV_SM_NUM_RESET)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *domainNameAddr = s_name[domainId];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset domain                                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ResetDomain(uint32_t domainId, uint32_t resetState,
    bool toggle, bool assertNegate)
{
    int32_t status = SM_ERR_SUCCESS;

    /* resetState determines type of reset, SCMI only defines COLD, others
       are implementation defined, higher number less context lost */

    /* if toggle = true then call results in assert+negate,
       usable after */

    /* if toggle = false, then assertNegate = true to assert the reset,
       false to negate */

    uint32_t resetType = RST_LINE_CTRL_DEASSERT;

    if (toggle)
    {
        resetType = RST_LINE_CTRL_TOGGLE;
    }
    else
    {
        if (assertNegate)
        {
            resetType = RST_LINE_CTRL_ASSERT;
        }
    }

    /* Perform requested reset action */
    if (!SRC_MixSetResetLine(domainId, resetType))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

