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

/* Includes */

#include "sm.h"
#include "fsl_cpu.h"
#include "fsl_power.h"
#include "fsl_src.h"
#include "fsl_device_registers.h"
#if (defined(FSL_FEATURE_LP_HANDSHAKE_SM_HAS_ERRATA_52232) && FSL_FEATURE_LP_HANDSHAKE_SM_HAS_ERRATA_52232)
#include "fsl_ccm.h"
#include "fsl_clock.h"
#endif

/* Local Defines */

#define WHITELIST_VAL(cpuId)    (WHITELIST_MASK(CPU_IDX_M33P) | WHITELIST_MASK(cpuId))
#define WHITELIST_ALL           (WHITELIST_MASK(CPU_IDX_M33P) | WHITELIST_MASK(CPU_IDX_M7P) | WHITELIST_MASK(CPU_IDX_A55P))

#define AUTHENCTRL_SW           SRC_XSPR_AUTHEN_CTRL_WHITE_LIST(WHITELIST_ALL) | \
                                SRC_XSPR_AUTHEN_CTRL_LPM_MODE(0U)
#define AUTHENCTRL_HW           SRC_XSPR_AUTHEN_CTRL_WHITE_LIST(WHITELIST_ALL) | \
                                SRC_XSPR_AUTHEN_CTRL_LPM_MODE(1U)
#define AUTHENCTRL_CPU(cpuId)    SRC_XSPR_AUTHEN_CTRL_WHITE_LIST(WHITELIST_VAL(cpuId)) | \
                                    SRC_XSPR_AUTHEN_CTRL_LPM_MODE(1U)


#define LPMSETTING(cpuId)       LPMSETTING_DOM(cpuId, CPU_PD_LPM_ON_RUN_WAIT_STOP)
#define LPMSETTING_SWCTRL       0x4444444444444444ULL
#define LPMSETTING_CPU(cpuId)   (LPMSETTING(cpuId))
#define LPMSETTING_ALLCPUS      (LPMSETTING(CPU_IDX_M33P) | LPMSETTING(CPU_IDX_A55P) | LPMSETTING(CPU_IDX_M7P))

/* Local Types */

/* Local Functions */

/* Local Variables */

/* Global Variables */

/* Power MIX management info */
pwrmix_mgmt_info_t const g_pwrMixMgmtInfo[PWR_NUM_MIX_SLICE] =
{
    [PWR_MIX_SLICE_IDX_ANA] =
    {
        .flags = 0U,
        .memMask = 0U,
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = 0U,
        .gpcReqMaskRst = 0U,
        .gpcReqMaskPwr = 0U,
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_AON] =
    {
        .flags = 0U,
        .memMask = (1U << PWR_MEM_SLICE_IDX_AON),
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = 0U,
        .gpcReqMaskRst = 0U,
        .gpcReqMaskPwr = 0U,
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_BBSM] =
    {
        .flags = 0U,
        .memMask = 0U,
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = 0U,
        .gpcReqMaskRst = 0U,
        .gpcReqMaskPwr = 0U,
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_CAMERA] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE,
        .memMask = (1U << PWR_MEM_SLICE_IDX_CAMERA),
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_0_MASK, /* MIPI, MPLL */
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_CAMERA),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_CAMERA),
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_CCMSRCGPC] =
    {
        .flags = 0U,
        .memMask = 0U,
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = 0U,
        .gpcReqMaskRst = 0U,
        .gpcReqMaskPwr = 0U,
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_A55C0] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE | PWR_MIX_FLAG_LPMSET,
        .memMask = (1U << PWR_MEM_SLICE_IDX_A55C0),
        .retainMask = 0U,
        .cpuMask = (1U << CPU_IDX_A55C0),
        .ipIsoMask = 0U,
        .gpcReqMaskRst = 0U,
        .gpcReqMaskPwr = 0U,
        .authenCtrl = AUTHENCTRL_CPU(CPU_IDX_A55C0),
        .lpmSetting = LPMSETTING_CPU(CPU_IDX_A55C0),
    },

    [PWR_MIX_SLICE_IDX_A55C1] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE | PWR_MIX_FLAG_LPMSET,
        .memMask = (1U << PWR_MEM_SLICE_IDX_A55C1),
        .retainMask = 0U,
        .cpuMask = (1U << CPU_IDX_A55C1),
        .ipIsoMask = 0U,
        .gpcReqMaskRst = 0U,
        .gpcReqMaskPwr = 0U,
        .authenCtrl = AUTHENCTRL_CPU(CPU_IDX_A55C1),
        .lpmSetting = LPMSETTING_CPU(CPU_IDX_A55C1),
    },

    [PWR_MIX_SLICE_IDX_A55C2] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE | PWR_MIX_FLAG_LPMSET,
        .memMask = (1U << PWR_MEM_SLICE_IDX_A55C2),
        .retainMask = 0U,
        .cpuMask = (1U << CPU_IDX_A55C2),
        .ipIsoMask = 0U,
        .gpcReqMaskRst = 0U,
        .gpcReqMaskPwr = 0U,
        .authenCtrl = AUTHENCTRL_CPU(CPU_IDX_A55C2),
        .lpmSetting = LPMSETTING_CPU(CPU_IDX_A55C2),
    },

    [PWR_MIX_SLICE_IDX_A55C3] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE | PWR_MIX_FLAG_LPMSET,
        .memMask = (1U << PWR_MEM_SLICE_IDX_A55C3),
        .retainMask = 0U,
        .cpuMask = (1U << CPU_IDX_A55C3),
        .ipIsoMask = 0U,
        .gpcReqMaskRst = 0U,
        .gpcReqMaskPwr = 0U,
        .authenCtrl = AUTHENCTRL_CPU(CPU_IDX_A55C3),
        .lpmSetting = LPMSETTING_CPU(CPU_IDX_A55C3),
    },

    [PWR_MIX_SLICE_IDX_A55C4] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE | PWR_MIX_FLAG_LPMSET,
        .memMask = (1U << PWR_MEM_SLICE_IDX_A55C4),
        .retainMask = 0U,
        .cpuMask = (1U << CPU_IDX_A55C4),
        .ipIsoMask = 0U,
        .gpcReqMaskRst = 0U,
        .gpcReqMaskPwr = 0U,
        .authenCtrl = AUTHENCTRL_CPU(CPU_IDX_A55C4),
        .lpmSetting = LPMSETTING_CPU(CPU_IDX_A55C4),
    },

    [PWR_MIX_SLICE_IDX_A55C5] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE | PWR_MIX_FLAG_LPMSET,
        .memMask = (1U << PWR_MEM_SLICE_IDX_A55C5),
        .retainMask = 0U,
        .cpuMask = (1U << CPU_IDX_A55C5),
        .ipIsoMask = 0U,
        .gpcReqMaskRst = 0U,
        .gpcReqMaskPwr = 0U,
        .authenCtrl = AUTHENCTRL_CPU(CPU_IDX_A55C5),
        .lpmSetting = LPMSETTING_CPU(CPU_IDX_A55C5),
    },

    [PWR_MIX_SLICE_IDX_A55P] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE | PWR_MIX_FLAG_LPMSET | PWR_MIX_FLAG_SSI_TIMEOUT,
        .memMask = (1U << PWR_MEM_SLICE_IDX_A55P) |
                   (1U << PWR_MEM_SLICE_IDX_A55L3),
        .retainMask = 0U,
        .cpuMask = (1U << CPU_IDX_A55P),
        .ipIsoMask = SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_0_MASK, /* ARM PLL */
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_A55P),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_A55P),
        .authenCtrl = AUTHENCTRL_CPU(CPU_IDX_A55P),
        .lpmSetting = LPMSETTING_CPU(CPU_IDX_A55P),
        .ssiLpcgIdx = 1U,
    },

    [PWR_MIX_SLICE_IDX_DDR] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE | PWR_MIX_FLAG_LPMSET,
        .memMask = (1U << PWR_MEM_SLICE_IDX_DDR),
        .retainMask = (1U << PWR_MEM_SLICE_IDX_DDR),
        .cpuMask = 0U,
        .ipIsoMask = SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_0_MASK | /* DDR complex */
                     SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_1_MASK,  /* DDR complex */
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_DDR) |
                         (1U << PWR_GPC_HS_RST_DDRPHY),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_DDR),
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_DISPLAY] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE,
        .memMask = (1U << PWR_MEM_SLICE_IDX_DISPLAY),
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_0_MASK, /* LVDS */
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_DISPLAY),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_DISPLAY),
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_GPU] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE,
        .memMask = (1U << PWR_MEM_SLICE_IDX_GPU),
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = 0U,
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_GPU),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_GPU),
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_HSIO_TOP] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE,
        .memMask = (1U << PWR_MEM_SLICE_IDX_HSIO),
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_2_MASK | /* HSIO PLL */
                     SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_3_MASK | /* USB1 */
                     SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_4_MASK | /* USB1 */
                     SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_5_MASK | /* USB2 */
                     SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_6_MASK,  /* USB2 */
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_HSIO),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_HSIO),
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_HSIO_WAON] =
    {
        .flags = 0U,
        .memMask = 0U,
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = 0U,
        .gpcReqMaskRst = 0U,
        .gpcReqMaskPwr = 0U,
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_M7] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE | PWR_MIX_FLAG_LPMSET,
        .memMask = (1U << PWR_MEM_SLICE_IDX_M7),
        .retainMask = (1U << PWR_MEM_SLICE_IDX_M7),
        .cpuMask = (1U << CPU_IDX_M7P),
        .ipIsoMask = 0U,
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_M7),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_M7),
        .authenCtrl = AUTHENCTRL_CPU(CPU_IDX_M7P),
        .lpmSetting = LPMSETTING_CPU(CPU_IDX_M7P),
    },

    [PWR_MIX_SLICE_IDX_NETC] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE,
        .memMask = (1U << PWR_MEM_SLICE_IDX_NETC),
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_0_MASK | /* unused */
                     SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_1_MASK,  /* GPIO */
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_NETC),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_NETC),
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_NOC] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE | PWR_MIX_FLAG_LPMSET,
        .memMask = (1U << PWR_MEM_SLICE_IDX_NOC1) |
                   (1U << PWR_MEM_SLICE_IDX_NOC2),
        .retainMask = (1U << PWR_MEM_SLICE_IDX_NOC1),
        .cpuMask = 0U,
        .ipIsoMask = 0U,
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_NOC),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_NOC),
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_NPU] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE,
        .memMask = (1U << PWR_MEM_SLICE_IDX_NPU),
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = 0U,
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_NPU),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_NPU),
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },
        
    [PWR_MIX_SLICE_IDX_VPU] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE,
        .memMask = (1U << PWR_MEM_SLICE_IDX_VPU),
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = 0U,
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_VPU),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_VPU),
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    },

    [PWR_MIX_SLICE_IDX_WAKEUP] =
    {
        .flags = PWR_MIX_FLAG_SWITCHABLE | PWR_MIX_FLAG_LPMSET,
        .memMask = (1U << PWR_MEM_SLICE_IDX_WAKEUP),
        .retainMask = 0U,
        .cpuMask = 0U,
        .ipIsoMask = SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_0_MASK | /* EARC */
                     SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_1_MASK,  /* GPIO */
        .gpcReqMaskRst = (1U << PWR_GPC_HS_RST_WAKEUP),
        .gpcReqMaskPwr = (1U << PWR_GPC_HS_PWR_WAKEUP),
        .authenCtrl = AUTHENCTRL_SW,
        .lpmSetting = LPMSETTING_SWCTRL,
    }
};

/*--------------------------------------------------------------------------*/
/* Initialize MIX slice power configuration                                 */
/*--------------------------------------------------------------------------*/
bool PWR_Init(uint32_t srcMixIdx)
{
    bool rc = false;

    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        PWR_EleLpHandshakeMaskSet(srcMixIdx, true);
        PWR_LpHandshakeMaskSet(srcMixIdx, true);
        rc = SRC_MixInit(srcMixIdx);
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Check if parent of MIX slice powered                                     */
/*--------------------------------------------------------------------------*/
bool PWR_IsParentPowered(uint32_t srcMixIdx)
{
    bool isParentPowered = true;

    if ((srcMixIdx >= PWR_MIX_SLICE_IDX_A55C0) && 
        (srcMixIdx <= PWR_MIX_SLICE_IDX_A55C_LAST))
    {
        isParentPowered = SRC_MixIsPwrSwitchOn(PWR_MIX_SLICE_IDX_A55P);
    }

    return isParentPowered;
}

/*--------------------------------------------------------------------------*/
/* Check if any child of MIX slice powered                                  */
/*--------------------------------------------------------------------------*/
bool PWR_AnyChildPowered(uint32_t srcMixIdx)
{
    bool anyChildPowered = false;

    if (srcMixIdx == PWR_MIX_SLICE_IDX_A55P)
    {
        uint32_t idx = PWR_MIX_SLICE_IDX_A55C0;
        while ((idx <= PWR_MIX_SLICE_IDX_A55C_LAST) && !anyChildPowered)
        {
            if (SRC_MixIsPwrSwitchOn(idx))
            {
                anyChildPowered = true;
            }
            idx++;
        }
    }

    return anyChildPowered;
}

/*--------------------------------------------------------------------------*/
/* Find number of children domains powered                                  */
/*--------------------------------------------------------------------------*/
uint32_t PWR_NumChildPowered(uint32_t srcMixIdx)
{

    uint32_t numChildPowered = 0U;

    if (srcMixIdx == PWR_MIX_SLICE_IDX_A55P)
    {
        uint32_t idx = PWR_MIX_SLICE_IDX_A55C0;
        while (idx <= PWR_MIX_SLICE_IDX_A55C_LAST)
        {
            if (SRC_MixIsPwrSwitchOn(idx))
            {
                ++numChildPowered;
            }
            idx++;
        }
    }

    return numChildPowered;
}

/*--------------------------------------------------------------------------*/
/* Request system power down                                                */
/*--------------------------------------------------------------------------*/
void PWR_SystemPowerDown(void)
{
    BBNSM->BBNSM_CTRL |= BBNSM_BBNSM_CTRL_TOSP(0x1U);
}

/*--------------------------------------------------------------------------*/
/* Configure SM LP handshake mask                                           */
/*--------------------------------------------------------------------------*/
void PWR_LpHandshakeMaskSet(uint32_t srcMixIdx, bool enableHandshake)
{
    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        uint32_t gpcReqMaskRst = g_pwrMixMgmtInfo[srcMixIdx].gpcReqMaskRst;

        if (gpcReqMaskRst != 0U)
        {
            uint32_t hs = BLK_CTRL_S_AONMIX->LP_HANDSHAKE_SM;

            if (enableHandshake)
            {
                hs |= gpcReqMaskRst;
            }
            else
            {
                hs &= (~gpcReqMaskRst);
            }
            
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE_SM = hs;
        }

        uint32_t gpcReqMaskPwr = g_pwrMixMgmtInfo[srcMixIdx].gpcReqMaskPwr;
        if (gpcReqMaskPwr != 0U)
        {
            uint32_t hs = BLK_CTRL_S_AONMIX->LP_HANDSHAKE2_SM;
        
            if (enableHandshake)
            {
                hs |= gpcReqMaskPwr;
            }
            else
            {
                hs &= (~gpcReqMaskPwr);
            }
            
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE2_SM = hs;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Configure ELE LP handshake mask                                          */
/*--------------------------------------------------------------------------*/
void PWR_EleLpHandshakeMaskSet(uint32_t srcMixIdx, bool enableHandshake)
{
    if (srcMixIdx < PWR_NUM_MIX_SLICE)
    {
        uint32_t gpcReqMaskRst = g_pwrMixMgmtInfo[srcMixIdx].gpcReqMaskRst;

        if (gpcReqMaskRst != 0U)
        {
            uint32_t hs = BLK_CTRL_S_AONMIX->LP_HANDSHAKE_ELE;

            if (enableHandshake)
            {
                hs |= gpcReqMaskRst;
            }
            else
            {
                hs &= (~gpcReqMaskRst);
            }
            
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE_ELE = hs;
        }

        uint32_t gpcReqMaskPwr = g_pwrMixMgmtInfo[srcMixIdx].gpcReqMaskPwr;
        if (gpcReqMaskPwr != 0U)
        {
            uint32_t hs = BLK_CTRL_S_AONMIX->LP_HANDSHAKE2_ELE;
        
            if (enableHandshake)
            {
                hs |= gpcReqMaskPwr;
            }
            else
            {
                hs &= (~gpcReqMaskPwr);
            }
            
            BLK_CTRL_S_AONMIX->LP_HANDSHAKE2_ELE = hs;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Query mode of LP handshake                                               */
/*--------------------------------------------------------------------------*/
void PWR_LpHandshakeModeGet(pwr_lp_hs_mode *lpHsMode)
{
    /* Map MIX ID from handshake status to SoC PD */
    static uint32_t const s_gpcReqMixId2Pd[16U] =
    {
        [PWR_GPC_REQ_MIX_ID_M7] = PWR_MIX_SLICE_IDX_M7,
        [PWR_GPC_REQ_MIX_ID_S500] = PWR_MIX_SLICE_IDX_AON,
        [PWR_GPC_REQ_MIX_ID_NPU] = PWR_MIX_SLICE_IDX_NPU,
        [PWR_GPC_REQ_MIX_ID_A55] = PWR_MIX_SLICE_IDX_A55P,
        [PWR_GPC_REQ_MIX_ID_M33] = PWR_MIX_SLICE_IDX_AON,
        [PWR_GPC_REQ_MIX_ID_AON] = PWR_MIX_SLICE_IDX_AON,
        [PWR_GPC_REQ_MIX_ID_DDR] = PWR_MIX_SLICE_IDX_DDR,
        [PWR_GPC_REQ_MIX_ID_WAKEUP] = PWR_MIX_SLICE_IDX_WAKEUP,
        [PWR_GPC_REQ_MIX_ID_NOC] = PWR_MIX_SLICE_IDX_NOC,
        [PWR_GPC_REQ_MIX_ID_CAMERA] = PWR_MIX_SLICE_IDX_CAMERA,
        [PWR_GPC_REQ_MIX_ID_HSIO] = PWR_MIX_SLICE_IDX_HSIO_TOP,
        [PWR_GPC_REQ_MIX_ID_RSVD] = 0U,
        [PWR_GPC_REQ_MIX_ID_NETC] = PWR_MIX_SLICE_IDX_NETC,
        [PWR_GPC_REQ_MIX_ID_DISPLAY] = PWR_MIX_SLICE_IDX_DISPLAY,
        [PWR_GPC_REQ_MIX_ID_VPU] = PWR_MIX_SLICE_IDX_VPU,
        [PWR_GPC_REQ_MIX_ID_GPU] = PWR_MIX_SLICE_IDX_GPU
    };

    uint32_t lpStat = BLK_CTRL_S_AONMIX->SM_LP_HANDSHAKE_STATUS;
    uint32_t lpIdx = (lpStat 
        & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_MASK) 
        >> BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_SHIFT;

    /* Translate LP handshake mix into SRC mix */
    uint32_t lpMix = (lpIdx & 0x78U) >> 3U;
    lpHsMode->srcMixIdx = s_gpcReqMixId2Pd[lpMix];

    /* Extract LP request */
    lpHsMode->req = lpIdx & 0x7U;

    /* Extract LP status */
    lpHsMode->stat = (lpStat 
        & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT_MASK) 
        >> BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT_SHIFT;

#ifdef DEBUG_LP_HS
    printf("SM_LP_HS:  PD = %u, REQ = %u, STAT = %u\n", 
        lpHsMode->srcMixIdx, lpHsMode->req, lpHsMode->stat);
#endif
}

/*--------------------------------------------------------------------------*/
/* Acknowledge LP handshake                                                 */
/*--------------------------------------------------------------------------*/
void PWR_LpHandshakeAck(void)
{
#if (defined(FSL_FEATURE_LP_HANDSHAKE_SM_HAS_ERRATA_52232) && FSL_FEATURE_LP_HANDSHAKE_SM_HAS_ERRATA_52232)
    /* Query clock root divider for LP_HANDSHAKE module */
    uint32_t oldDiv;
    bool rc = CCM_RootGetDiv(CLOCK_ROOT_M33, &oldDiv);

    /* Increase clock root divider for LP_HANDSHAKE module during ACK */
    if (rc)
    {
        rc = CCM_RootSetDiv(CLOCK_ROOT_M33, oldDiv << 2U);
    }
#endif

    BLK_CTRL_S_AONMIX->SM_LP_HANDSHAKE_STATUS = 
                BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK(0U) |
                BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK(1U);

    /* Ack requires a pulse of 2-3 clocks @ 24MHz = 125ns */
    SystemTimeDelay(1U);

    BLK_CTRL_S_AONMIX->SM_LP_HANDSHAKE_STATUS = 
                 BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK(0U) |
                 BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK(0U);

#if (defined(FSL_FEATURE_LP_HANDSHAKE_SM_HAS_ERRATA_52232) && FSL_FEATURE_LP_HANDSHAKE_SM_HAS_ERRATA_52232)
    /* Restore clock root divider for LP_HANDSHAKE module */
    if (rc)
    {
        (void) CCM_RootSetDiv(CLOCK_ROOT_M33, oldDiv);
    }
#endif
}

