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
        [RST_LINE_A55C0_NCPUPORESET] = "A55C0_NCPUPORESET",
        [RST_LINE_A55C0_NCORERESET] = "A55C0_NCORERESET",
        [RST_LINE_A55C1_NCPUPORESET] = "A55C1_NCPUPORESET",
        [RST_LINE_A55C1_NCORERESET] = "A55C1_NCORERESET",
        [RST_LINE_A55C2_NCPUPORESET] = "A55C2_NCPUPORESET",
        [RST_LINE_A55C2_NCORERESET] = "A55C2_NCORERESET",
        [RST_LINE_A55C3_NCPUPORESET] = "A55C3_NCPUPORESET",
        [RST_LINE_A55C3_NCORERESET] = "A55C3_NCORERESET",
        [RST_LINE_A55C4_NCPUPORESET] = "A55C4_NCPUPORESET",
        [RST_LINE_A55C4_NCORERESET] = "A55C4_NCORERESET",
        [RST_LINE_A55C5_NCPUPORESET] = "A55C5_NCPUPORESET",
        [RST_LINE_A55C5_NCORERESET] = "A55C5_NCORERESET",
        [RST_LINE_A55P_NPRESET] = "A55P_NPRESET",
        [RST_LINE_A55P_NSPORESET] = "A55P_NSPORESET",
        [RST_LINE_A55P_NSRESET] = "A55P_NSRESET",
        [RST_LINE_A55P_NATRESET] = "A55P_NATRESET",
        [RST_LINE_A55P_NGICRESET] = "A55P_NGICRESET",
        [RST_LINE_A55P_NPERIPHRESET] = "A55P_NPERIPHRESET",
        [RST_LINE_DDRPHY_PRESETN] = "DDRPHY_PRESETN",
        [RST_LINE_DDRPHY_RESETN] = "DDRPHY_RESETN",
        [RST_LINE_DISP0_RESETN] = "DISP0_RESETN",
        [RST_LINE_DISP1_RESETN] = "DISP1_RESETN",
        [RST_LINE_LVDS_RESETN] = "LVDS_RESETN",
        [RST_LINE_USB1PHY_RESETN] = "USB1PHY_RESETN",
        [RST_LINE_USB2PHY_RESETN] = "USB2PHY_RESETN",
        [RST_LINE_PCIE1PHY_RESETN] = "PCIE1PHY_RESETN",
        [RST_LINE_PCIE2PHY_RESETN] = "PCIE2PHY_RESETN",
        [RST_LINE_ENETPHY_PCS_RESETN] = "ENETPHY_PCS_RESETN",
        [RST_LINE_V2X_RESETB] = "V2X_RESETB",

        [RST_LINE_ANAMIX] = "ANAMIX",
        [RST_LINE_AONMIX_TOP] = "AONMIX_TOP",
        [RST_LINE_AONMIX_M33] = "AONMIX_M33",
        [RST_LINE_AONMIX_SENTINEL] = "AONMIX_ELE",
        [RST_LINE_BBSMMIX] = "BBSMMIX",
        [RST_LINE_CAMERAMIX] = "CAMERAMIX",
        [RST_LINE_CCMSRCGPCMIX] = "CCMSRCGPCMIX",
        [RST_LINE_CORTEXAMIX_CORE0] = "CORTEXAMIX_CORE0",
        [RST_LINE_CORTEXAMIX_CORE1] = "CORTEXAMIX_CORE1",
        [RST_LINE_CORTEXAMIX_CORE2] = "CORTEXAMIX_CORE2",
        [RST_LINE_CORTEXAMIX_CORE3] = "CORTEXAMIX_CORE3",
        [RST_LINE_CORTEXAMIX_CORE4] = "CORTEXAMIX_CORE4",
        [RST_LINE_CORTEXAMIX_CORE5] = "CORTEXAMIX_CORE5",
        [RST_LINE_CORTEXAMIX_PLATFORM] = "CORTEXAMIX_PLATFORM",
        [RST_LINE_DDRMIX_TOP] = "DDRMIX_TOP",
        [RST_LINE_DDRMIX_PHY] = "DDRMIX_PHY",
        [RST_LINE_DISPLAYMIX] = "DISPLAYMIX",
        [RST_LINE_GPUMIX] = "GPUMIX",
        [RST_LINE_HSIOMIX_TOP] = "HSIOMIX_TOP",
        [RST_LINE_HSIOMIX_WAON] = "HSIOMIX_WAON",
        [RST_LINE_M7MIX] = "M7MIX",
        [RST_LINE_NETCMIX] = "NETCMIX",
        [RST_LINE_NOCMIX] = "NOCMIX",
        [RST_LINE_NPUMIX] = "NPUMIX",
        [RST_LINE_VPUMIX] = "VPUMIX",
        [RST_LINE_WAKEUPMIX_TOP] = "WAKEUPMIX_TOP",
        [RST_LINE_WAKEUPMIX_JTAG] = "WAKEUPMIX_JTAG",
        [RST_LINE_WAKEUPMIX_WDOG_3_4] = "WAKEUPMIX_WDOG_3_4",
        [RST_LINE_WAKEUPMIX_WDOG_5] = "WAKEUPMIX_WDOG_5"
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

