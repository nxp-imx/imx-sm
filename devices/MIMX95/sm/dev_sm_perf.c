/*
** ###################################################################
**
**     Copyright 2023-2025 NXP
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
/* File containing the implementation of the device performance domains.    */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "brd_sm.h"
#include "fsl_ele.h"
#include "fsl_fract_pll.h"

/* Local defines */

/* Number of voltage setpoints */
#define DEV_SM_NUM_PERF_LVL_SOC     4U
#define DEV_SM_NUM_PERF_LVL_ARM     5U
#define DEV_SM_NUM_PERF_SLEEP       10U
#define DEV_SM_PERF_LAST            (DEV_SM_NUM_PERF - 1U)
#define DEV_SM_A55_GPR_SEL_IDX      1U
#define DEV_SM_A55_GPR_SEL_MASK     0x7FU

/* SYSPLL PFD fixed-rate mappings */
#define DEV_SM_PERF_PARENT_1000MHZ  DEV_SM_CLK_SYSPLL1_PFD0
#define DEV_SM_PERF_PARENT_800MHZ   DEV_SM_CLK_SYSPLL1_PFD1
#define DEV_SM_PERF_PARENT_667MHZ   DEV_SM_CLK_SYSPLL1_PFD2
#define DEV_SM_PERF_PARENT_500MHZ   DEV_SM_CLK_SYSPLL1_PFD0_DIV2
#define DEV_SM_PERF_PARENT_400MHZ   DEV_SM_CLK_SYSPLL1_PFD1_DIV2
#define DEV_SM_PERF_PARENT_333MHZ   DEV_SM_CLK_SYSPLL1_PFD2_DIV2

#define VCO_MFD         ((uint32_t)(CLOCK_PLL_MFD & 0xFFFFFFFFU))

#define DEV_SM_PERF_NUM_BUS_CLK     11U

/* Worst-case transition latency reported by PERFORMANCE_DESCRIBE_LEVELS
 *
 * Considerations for reported latency value:
 *  - Number of outstanding SCMI agent requests
 *  - Latency of outstanding agent requests
 *  - Latency of outstanding SM periodic servicing
 *  - Latency of performance level transition
 */
#define DEV_SM_PERF_LATENCY_USEC    5000U   /* 5 msec */

/* Local types */

/* Setpoint clock root configuration */
typedef struct
{
    uint32_t parent;
    uint32_t rootDiv;
} dev_sm_perf_root_cfg_t;

/* Setpoint PLL configuration */
typedef struct
{
    uint32_t mfi;
    uint32_t mfn;
    uint32_t odiv;
} dev_sm_perf_pll_cfg_t;

/* Setpoint PFD configuration */
typedef struct
{
    uint32_t mfi;
    uint32_t mfn;
} dev_sm_perf_pfd_cfg_t;

/* Setpoint CCM GPR configuration */
typedef struct
{
    uint32_t gprRegIdx;
    uint32_t gprMask;
    uint32_t gprVal;
} dev_sm_perf_gpr_cfg_t;

/* Power supply configuration */
typedef struct
{
    uint32_t psIdx;
    uint32_t idStart;
    uint32_t idEnd;
    int32_t const *dvsTable;
} dev_sm_perf_ps_cfg_t;

/* Overall performance setpoint configuration */
typedef struct
{
    uint32_t rootClk;
    uint32_t srcMixIdx;
    dev_sm_perf_ps_cfg_t const *psCfg;
    dev_sm_perf_desc_t const *desc;
    dev_sm_perf_root_cfg_t const *rootCfg;
} dev_sm_perf_cfg_t;

/* Local variables */

/* Current performance level per domain */
static uint32_t s_perfLevelCurrent[DEV_SM_NUM_PERF] =
{
    [DEV_SM_PERF_ELE] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_M33] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_WAKEUP] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_M7] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_DRAM] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_HSIO] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_NPU] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_NOC] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_A55] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_GPU] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_VPU] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_CAM] = DEV_SM_PERF_LVL_PRK,
    [DEV_SM_PERF_DISP] = DEV_SM_PERF_LVL_PRK
};

/* List of performance domains managed during sleep modes */
static uint32_t const s_perfSleepDomain[DEV_SM_NUM_PERF_SLEEP] =
{
    [0] = DEV_SM_PERF_ELE,
    [1] = DEV_SM_PERF_WAKEUP,
    [2] = DEV_SM_PERF_NOC,
    [3] = DEV_SM_PERF_M7,
    [4] = DEV_SM_PERF_HSIO,
    [5] = DEV_SM_PERF_NPU,
    [6] = DEV_SM_PERF_GPU,
    [7] = DEV_SM_PERF_VPU,
    [8] = DEV_SM_PERF_CAM,
    [9] = DEV_SM_PERF_DISP
};

/* Voltage setpoints for VDD_SOC */
static int32_t const s_perfDvsTableSoc[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] = ES_LOW_UV_VDD_SOC,
    [DEV_SM_PERF_LVL_LOW] = ES_LOW_UV_VDD_SOC,
    [DEV_SM_PERF_LVL_NOM] = ES_NOM_UV_VDD_SOC,
    [DEV_SM_PERF_LVL_ODV] = ES_ODV_UV_VDD_SOC
};

/* Power supply configuration for VDD_SOC */
static dev_sm_perf_ps_cfg_t const s_psCfgSoc =
{
    .psIdx = PS_VDD_SOC,
    .idStart = 0U,
    .idEnd = DEV_SM_PERF_LAST,
    .dvsTable = s_perfDvsTableSoc
};

/* Voltage setpoints for VDD_ARM */
static int32_t const s_perfDvsTableArm[DEV_SM_NUM_PERF_LVL_ARM] =
{
    [DEV_SM_PERF_LVL_PRK] = ES_LOW_UV_VDD_ARM,
    [DEV_SM_PERF_LVL_LOW] = ES_LOW_UV_VDD_ARM,
    [DEV_SM_PERF_LVL_NOM] = ES_NOM_UV_VDD_ARM,
    [DEV_SM_PERF_LVL_ODV] = ES_ODV_UV_VDD_ARM,
    [DEV_SM_PERF_LVL_SOD] = ES_SOD_UV_VDD_ARM
};

/* Power supply configuration for VDD_ARM */
static dev_sm_perf_ps_cfg_t const s_psCfgArm =
{
    .psIdx = PS_VDD_ARM,
    .idStart = DEV_SM_PERF_A55,
    .idEnd = DEV_SM_PERF_A55,
    .dvsTable = s_perfDvsTableArm
};

/* Setpoint clock root configuration for ELE */
static dev_sm_perf_root_cfg_t const s_perfRootCfgEle[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_400MHZ,    /* root parent */
        .rootDiv = 3U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 5U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 4U,                          /* root divider */
    }
};

/* Setpoint descriptions for ELE */
static dev_sm_perf_desc_t const s_perfDescEle[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_ELE,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_ELE,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_ELE,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for M33 */
static dev_sm_perf_root_cfg_t const s_perfRootCfgM33[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 6U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 4U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 3U,                          /* root divider */
    }
};

/* Setpoint descriptions for M33 */
static dev_sm_perf_desc_t const s_perfDescM33[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_M33,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_M33,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_M33,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for WAKEUP */
static dev_sm_perf_root_cfg_t const s_perfRootCfgWakeup[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 5U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 3U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 2U,                          /* root divider */
    }
};

/* Setpoint clock root configuration for V2X */
/* coverity[misra_c_2012_rule_8_9_violation] */
static dev_sm_perf_root_cfg_t const s_perfRootCfgWakeupV2X[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_667MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    }
};

/* Setpoint descriptions for WAKEUP */
static dev_sm_perf_desc_t const s_perfDescWakeup[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_WAKEUP,                 /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_WAKEUP,                 /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_WAKEUP,                 /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for M7 */
static dev_sm_perf_root_cfg_t const s_perfRootCfgM7[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_667MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    }
};

/* Setpoint descriptions for M7 */
static dev_sm_perf_desc_t const s_perfDescM7[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_M7,                     /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_M7,                     /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_M7,                     /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for DRAM */
static dev_sm_perf_root_cfg_t const s_perfRootCfgDram =
{
    .parent = DEV_SM_CLK_OSC24M,            /* root parent */
    .rootDiv = 1U,                          /* root divider */
};

/* Setpoint PLL configuration for DRAM (LP5 19x19 default) */
static dev_sm_perf_pll_cfg_t s_perfPllCfgDram[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_LOW] =
    {
        /*
         * PLL_VCO = 24MHz * (133+1/3) = 3200MHz
         * PLL_OUT = PLL_VCO / 8 = 400MHz
         * 400MHz * 8 = 3200 MTs
         */
        .mfi = 133U,                            /* VCO MFI */
        .mfn = VCO_MFD / 3U,                    /* VCO MFN */
        .odiv = 8U,                             /* ODIV */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        /*
         * PLL_VCO = 24MHz * (200) = 4800MHz
         * PLL_OUT = PLL_VCO / 8 = 600MHz
         * 600MHz * 8 = 4800 MTs
         */
        .mfi = 200U,                            /* VCO MFI */
        .mfn = 0U,                              /* VCO MFN */
        .odiv = 8U                              /* ODIV */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        /*
         * PLL_VCO = 24MHz * (200) = 4800MHz
         * PLL_OUT = PLL_VCO / 6 = 800MHz
         * 800MHz * 8 = 6400 MTs
         */
        .mfi = 200U,                            /* VCO MFI */
        .mfn = 0U,                              /* VCO MFN */
        .odiv = 6U                              /* ODIV */
    }
};

/* Setpoint descriptions for DRAM (LP5 19x19 default) */
static dev_sm_perf_desc_t s_perfDescDram[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_DRAM_LP5_19X19,         /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_DRAM_LP5_19X19,         /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_DRAM_LP5_19X19,         /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for HSIO */
static dev_sm_perf_root_cfg_t const s_perfRootCfgHsio[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 4U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 2U,                          /* root divider */
    }
};

/* Setpoint descriptions for HSIO */
static dev_sm_perf_desc_t const s_perfDescHsio[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_HSIO,                   /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_HSIO,                   /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_HSIO,                   /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for NPU */
static dev_sm_perf_root_cfg_t const s_perfRootCfgNpu[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 1U,                          /* root divider */
    }
};

/* Setpoint descriptions for NPU */
static dev_sm_perf_desc_t const s_perfDescNpu[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_NPU,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_NPU,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_NPU,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for NOC */
static dev_sm_perf_root_cfg_t const s_perfRootCfgNoc[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_667MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    }
};

/* Setpoint descriptions for NOC */
static dev_sm_perf_desc_t const s_perfDescNoc[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_NOC,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_NOC,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_NOC,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for GPU */
static dev_sm_perf_root_cfg_t const s_perfRootCfgGpu[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 1U,                          /* root divider */
    }
};

/* Setpoint descriptions for GPU */
static dev_sm_perf_desc_t const s_perfDescGpu[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_GPU,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_GPU,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_GPU,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for VPU */
static dev_sm_perf_root_cfg_t const s_perfRootCfgVpu[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 3U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_667MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    }
};

/* Setpoint clock root configuration for VPUJPEG */
/* coverity[misra_c_2012_rule_8_9_violation] */
static dev_sm_perf_root_cfg_t const s_perfRootCfgVpuJpeg[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 4U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 2U,                          /* root divider */
    }
};

/* Setpoint descriptions for VPU */
static dev_sm_perf_desc_t const s_perfDescVpu[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_VPU,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_VPU,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_VPU,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for CAM */
static dev_sm_perf_root_cfg_t const s_perfRootCfgCam[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_667MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    }
};

/* Setpoint clock root configuration for CAM ISI */
/* coverity[misra_c_2012_rule_8_9_violation] */
static dev_sm_perf_root_cfg_t const s_perfRootCfgCamIsi[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 3U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_667MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    }
};

/* Setpoint clock root configuration for CAM CM0 */
/* coverity[misra_c_2012_rule_8_9_violation] */
static dev_sm_perf_root_cfg_t const s_perfRootCfgCamCm0[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 5U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 3U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 2U,                          /* root divider */
    }
};

/* Setpoint descriptions for CAM */
static dev_sm_perf_desc_t const s_perfDescCam[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_CAM,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_CAM,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_CAM,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for DISP */
static dev_sm_perf_root_cfg_t const s_perfRootCfgDisp[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_667MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 1U,                          /* root divider */
    }
};

/* Setpoint clock root configuration for DISP OCRAM */
/* coverity[misra_c_2012_rule_8_9_violation] */
static dev_sm_perf_root_cfg_t const s_perfRootCfgDispOcram[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_CLK_OSC24M,            /* root parent */
        .rootDiv = 1U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 5U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 3U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 2U,                          /* root divider */
    }
};

/* Setpoint descriptions for DISP */
static dev_sm_perf_desc_t const s_perfDescDisp[DEV_SM_NUM_PERF_LVL_SOC] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_24000KHZ,                       /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_DISP,                   /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_DISP,                   /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_DISP,                   /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for A55 */
static dev_sm_perf_root_cfg_t const s_perfRootCfgA55 =
{
    .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
    .rootDiv = 2U                           /* root divider */
};

/* Setpoint PLL configuration for A55 */
/* coverity[misra_c_2012_rule_8_9_violation] */
static dev_sm_perf_pll_cfg_t s_perfPllCfgA55[DEV_SM_NUM_PERF_LVL_ARM] =
{
    [DEV_SM_PERF_LVL_LOW] =
    {
        /*
         * PLL_VCO = 24MHz * 150 = 3600MHz
         */
        .mfi = 150U,                            /* VCO MFI */
        .mfn = 0U,                              /* VCO MFN */
        .odiv = 0U,                             /* ODIV */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        /*
         * PLL_VCO = 24MHz * 117 = 2808MHz
         */
        .mfi = 117U,                            /* VCO MFI */
        .mfn = 0U,                              /* VCO MFN */
        .odiv = 0U                              /* ODIV */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        /*
         * PLL_VCO = 24MHz * 150 = 3600MHz
         */
        .mfi = 150U,                            /* VCO MFI */
        .mfn = 0U,                              /* VCO MFN */
        .odiv = 0U,                             /* ODIV */
    },
    [DEV_SM_PERF_LVL_SOD] =
    {
        /*
         * PLL_VCO = 24MHz * 167 = 4008MHz
         */
        .mfi = 167U,                            /* VCO MFI */
        .mfn = 0U,                              /* VCO MFN */
        .odiv = 0U,                             /* ODIV */
    }
};

/* Setpoint PFD configuration for A55 cores */
/* coverity[misra_c_2012_rule_8_9_violation] */
static dev_sm_perf_pfd_cfg_t s_perfPfdCfgA55C[DEV_SM_NUM_PERF_LVL_ARM] =
{
    [DEV_SM_PERF_LVL_LOW] =
    {
        .mfi = 4U,
        .mfn = 0U,
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .mfi = 2U,
        .mfn = 0U,
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .mfi = 2U,
        .mfn = 0U,
    },
    [DEV_SM_PERF_LVL_SOD] =
    {
        .mfi = 2U,
        .mfn = 0U,
    }
};

/* Setpoint PFD configuration for A55P */
/* coverity[misra_c_2012_rule_8_9_violation] */
static dev_sm_perf_pfd_cfg_t s_perfPfdCfgA55P[DEV_SM_NUM_PERF_LVL_ARM] =
{
    [DEV_SM_PERF_LVL_LOW] =
    {
        .mfi = 4U,
        .mfn = 4U,
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .mfi = 2U,
        .mfn = 2U,
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .mfi = 2U,
        .mfn = 2U,
    },
    [DEV_SM_PERF_LVL_SOD] =
    {
        .mfi = 2U,
        .mfn = 2U,
    }
};

/* Setpoint descriptions for A55 */
static dev_sm_perf_desc_t s_perfDescA55[DEV_SM_NUM_PERF_LVL_ARM] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .value = ES_500000KHZ,                      /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .value = ES_LOW_KHZ_A55,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .value = ES_NOM_KHZ_A55,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .value = ES_ODV_KHZ_A55,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    },
    [DEV_SM_PERF_LVL_SOD] =
    {
        .value = ES_SOD_KHZ_A55,                    /* KHz */
        .powerCost = 0U,                            /* mW */
        .latency = DEV_SM_PERF_LATENCY_USEC,        /* uS */
    }
};

/* Setpoint clock root configuration for A55PER */
/* coverity[misra_c_2012_rule_8_9_violation] */
static dev_sm_perf_root_cfg_t const s_perfRootCfgA55Per[DEV_SM_NUM_PERF_LVL_ARM] =
{
    [DEV_SM_PERF_LVL_PRK] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 5U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_LOW] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 5U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_NOM] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 3U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_ODV] =
    {
        .parent = DEV_SM_PERF_PARENT_800MHZ,    /* root parent */
        .rootDiv = 2U,                          /* root divider */
    },
    [DEV_SM_PERF_LVL_SOD] =
    {
        .parent = DEV_SM_PERF_PARENT_1000MHZ,   /* root parent */
        .rootDiv = 2U,                          /* root divider */
    }
};

/* Max performance level */
static uint32_t s_perfNumLevels[PS_NUM_SUPPLY];

/* Current power supply setting */
static int32_t s_perfPsVoltCurrent[PS_NUM_SUPPLY];

/* Tracks ELE performance update notifications */
static bool s_perfEleUpdating = false;

static dev_sm_perf_cfg_t const s_perfCfg[DEV_SM_NUM_PERF] =
{
    [DEV_SM_PERF_ELE] =
    {
        .rootClk = CLOCK_ROOT_ELE,
        .srcMixIdx = PWR_MIX_SLICE_IDX_AON,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescEle,
        .rootCfg = s_perfRootCfgEle,
    },

    [DEV_SM_PERF_M33] =
    {
        .rootClk = CLOCK_ROOT_M33,
        .srcMixIdx = PWR_MIX_SLICE_IDX_AON,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescM33,
        .rootCfg = s_perfRootCfgM33,
    },

    [DEV_SM_PERF_WAKEUP] =
    {
        .rootClk = CLOCK_ROOT_WAKEUPAXI,
        .srcMixIdx = PWR_MIX_SLICE_IDX_WAKEUP,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescWakeup,
        .rootCfg = s_perfRootCfgWakeup,
    },

    [DEV_SM_PERF_M7] =
    {
        .rootClk = CLOCK_ROOT_M7,
        .srcMixIdx = PWR_MIX_SLICE_IDX_M7,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescM7,
        .rootCfg = s_perfRootCfgM7,
    },

    [DEV_SM_PERF_DRAM] =
    {
        .rootClk = CLOCK_ROOT_DRAMALT,
        .srcMixIdx = PWR_MIX_SLICE_IDX_DDR,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescDram,
        .rootCfg = &s_perfRootCfgDram,
    },

    [DEV_SM_PERF_HSIO] =
    {
        .rootClk = CLOCK_ROOT_HSIO,
        .srcMixIdx = PWR_MIX_SLICE_IDX_HSIO_TOP,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescHsio,
        .rootCfg = s_perfRootCfgHsio,
    },

    [DEV_SM_PERF_NPU] =
    {
        .rootClk = CLOCK_ROOT_NPU,
        .srcMixIdx = PWR_MIX_SLICE_IDX_NPU,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescNpu,
        .rootCfg = s_perfRootCfgNpu,
    },

    [DEV_SM_PERF_NOC] =
    {
        .rootClk = CLOCK_ROOT_NOC,
        .srcMixIdx = PWR_MIX_SLICE_IDX_NOC,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescNoc,
        .rootCfg = s_perfRootCfgNoc,
    },

    [DEV_SM_PERF_GPU] =
    {
        .rootClk = CLOCK_ROOT_GPU,
        .srcMixIdx = PWR_MIX_SLICE_IDX_GPU,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescGpu,
        .rootCfg = s_perfRootCfgGpu,
    },

    [DEV_SM_PERF_VPU] =
    {
        .rootClk = CLOCK_ROOT_VPU,
        .srcMixIdx = PWR_MIX_SLICE_IDX_VPU,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescVpu,
        .rootCfg = s_perfRootCfgVpu,
    },

    [DEV_SM_PERF_CAM] =
    {
        .rootClk = CLOCK_ROOT_CAMAXI,
        .srcMixIdx = PWR_MIX_SLICE_IDX_CAMERA,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescCam,
        .rootCfg = s_perfRootCfgCam,
    },

    [DEV_SM_PERF_DISP] =
    {
        .rootClk = CLOCK_ROOT_DISPAXI,
        .srcMixIdx = PWR_MIX_SLICE_IDX_DISPLAY,
        .psCfg = &s_psCfgSoc,
        .desc = s_perfDescDisp,
        .rootCfg = s_perfRootCfgDisp,
    },

    [DEV_SM_PERF_A55] =
    {
        .rootClk = CLOCK_ROOT_A55,
        .srcMixIdx = PWR_MIX_SLICE_IDX_A55P,
        .psCfg = &s_psCfgArm,
        .desc = s_perfDescA55,
        .rootCfg = &s_perfRootCfgA55,
    }
};

/* Local functions */

static int32_t DEV_SM_PerfPowerCheck(uint32_t perfLevel, uint32_t srcMixIdx);
static int32_t DEV_SM_PerfMaxScan(uint32_t domainId, uint32_t *maxPerfLevel);
static uint32_t DEV_SM_PerfSystemSleepScan(void);
static int32_t DEV_SM_PerfRootFreqUpdate(uint32_t rootClk,
    dev_sm_perf_root_cfg_t const * rootCfg);
static int32_t DEV_SM_PerfPllFreqUpdate(uint32_t pllIdx,
    dev_sm_perf_pll_cfg_t const * pllCfg);
static int32_t DEV_SM_PerfPfdFreqUpdate(uint32_t pllIdx, uint8_t pfdIdx,
    dev_sm_perf_pfd_cfg_t const * pfdUpdate);
static int32_t DEV_SM_PerfBusFreqSet(bool parkedLevel);
static int32_t DEV_SM_PerfWakeupFreqUpdate(uint32_t perfLevel);
static int32_t DEV_SM_PerfVpuFreqUpdate(uint32_t perfLevel);
static int32_t DEV_SM_PerfCamFreqUpdate(uint32_t perfLevel);
static int32_t DEV_SM_PerfDispFreqUpdate(uint32_t perfLevel);
static int32_t DEV_SM_PerfDramFreqUpdate(uint32_t perfLevel);
static int32_t DEV_SM_PerfA55FreqUpdate(uint32_t perfLevel);
static int32_t DEV_SM_PerfSupplyUpdate(dev_sm_perf_ps_cfg_t const *psCfg,
    uint32_t perfLevel);
static int32_t DEV_SM_PerfFreqUpdate(uint32_t domainId, uint32_t perfLevel);
static int32_t DEV_SM_PerfCurrentUpdate(uint32_t domainId, uint32_t perfLevel);
static int32_t DEV_SM_PerfCurrentGet(uint32_t domainId, uint32_t * perfLevel);
static uint32_t DEV_SM_PerfDramTypeGet(void);
static uint32_t DEV_SM_PerfSocPkgTypeGet(void);
static void DEV_SM_PerfCfgInit(void);
static void DEV_SM_PerfEleUpdateAll(uint32_t perfLevel, bool initMode);
static void DEV_SM_PerfEleUpdate(uint32_t domainId, uint32_t perfLevel,
    uint32_t supplyPerfLevel);
static void DEV_SM_PerfEleDone(bool abortUpdate);

/*--------------------------------------------------------------------------*/
/* Initialize performance domains                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfInit(uint32_t bootPerfLevel, uint32_t runPerfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Initialize fixed SoC BUS clocks not configured by ROM */
    (void) DEV_SM_PerfBusFreqSet(false);

    /* NETCMIX configured separately (does not support frequency scaling) */
    (void) CCM_RootSetDiv(CLOCK_ROOT_ENET, 1U);
    (void) CCM_RootSetParent(CLOCK_ROOT_ENET, CLOCK_SRC_SYSPLL1_PFD2);

    /* Configure SYSPLL for software control (ROM sets hardware control) */
    SYS_PLL1->CTRL.CLR = PLL_CTRL_HW_CTRL_SEL_MASK;
    SYS_PLL1->DFS[0].DFS_CTRL.CLR = PLL_DFS_HW_CTRL_SEL_MASK;
    SYS_PLL1->DFS[1].DFS_CTRL.CLR = PLL_DFS_HW_CTRL_SEL_MASK;
    SYS_PLL1->DFS[2].DFS_CTRL.CLR = PLL_DFS_HW_CTRL_SEL_MASK;

    /* Set number of perf levels */
    s_perfNumLevels[PS_VDD_SOC] = DEV_SM_NUM_PERF_LVL_SOC;

    /* Initialize dynamically assigned performance configurations */
    DEV_SM_PerfCfgInit();

    if ((bootPerfLevel >= DEV_SM_NUM_PERF_LVL_SOC) ||
        (runPerfLevel >= DEV_SM_NUM_PERF_LVL_SOC))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* Track power supply voltage */
        s_perfPsVoltCurrent[PS_VDD_SOC] = s_perfDvsTableSoc[bootPerfLevel];
        s_perfPsVoltCurrent[PS_VDD_ARM] = s_perfDvsTableArm[bootPerfLevel];

        /* Security-relevant update start */
        DEV_SM_PerfEleUpdateAll(runPerfLevel, true);

        /* If raising performance level, increase voltage first */
        if (bootPerfLevel < runPerfLevel)
        {
            /* Update VDD_SOC setpoint */
            status = DEV_SM_PerfSupplyUpdate(&s_psCfgSoc, runPerfLevel);
        }

        /* Synchronize perf setpoints */
        uint32_t domainId = 0U;
        while ((status == SM_ERR_SUCCESS) &&
            (domainId <= DEV_SM_PERF_LAST))
        {
            /* Perf domains with MIX power dependency will be
             * initialized to default setpoint.  Others
             * will be set to level passed in.
             */
            uint32_t perfLevel = DEV_SM_PERF_LVL_PRK;

            if (DEV_SM_PerfIsReserved(domainId))
            {
                domainId++;
                continue;
            }

            /* Clamp level based on MIX power dependency */
            if (DEV_SM_PerfPowerCheck(runPerfLevel, s_perfCfg[domainId].srcMixIdx)
                == SM_ERR_SUCCESS)
            {
                perfLevel = runPerfLevel;
            }

            if ((domainId == DEV_SM_PERF_DRAM) && (perfLevel != DEV_SM_PERF_LVL_PRK))
            {
                /* Adapt to DRAM setpoint established during OEI phase */
                status = DEV_SM_PerfCurrentGet(DEV_SM_PERF_DRAM, &perfLevel);
            }
            else
            {
                /* Sync to defined performance level */
                status = DEV_SM_PerfFreqUpdate(domainId, perfLevel);
            }

            /* Update current setpoint upon success */
            if (status == SM_ERR_SUCCESS)
            {
                status = DEV_SM_PerfCurrentUpdate(domainId, perfLevel);
            }
            domainId++;
        }

        /* If lowering performance level, decrease voltage last */
        if (bootPerfLevel > runPerfLevel)
        {
            /* Update VDD_SOC setpoint */
            status = DEV_SM_PerfSupplyUpdate(&s_psCfgSoc, runPerfLevel);
        }

        /* Security-relevant update done */
        bool abortUpdate = status != SM_ERR_SUCCESS;
        DEV_SM_PerfEleDone(abortUpdate);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return performance domain name                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfNameGet(uint32_t domainId, string *perfNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_PERF] =
    {
        [DEV_SM_PERF_ELE] =    "ele",
        [DEV_SM_PERF_M33] =    "m33",
        [DEV_SM_PERF_WAKEUP] = "wakeup",
        [DEV_SM_PERF_M7] =     "m7",
        [DEV_SM_PERF_DRAM] =   "dram",
        [DEV_SM_PERF_HSIO] =   "hsio",
        [DEV_SM_PERF_NPU] =    "npu",
        [DEV_SM_PERF_NOC] =    "noc",
        [DEV_SM_PERF_A55] =    "a55",
        [DEV_SM_PERF_GPU] =    "gpu",
        [DEV_SM_PERF_VPU] =    "vpu",
        [DEV_SM_PERF_CAM] =    "cam",
        [DEV_SM_PERF_DISP] =   "disp"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_PERF);

    /* Check domain */
    if (DEV_SM_PerfIsReserved(domainId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *perfNameAddr = s_name[domainId];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return performance domain info                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfInfoGet(uint32_t domainId, dev_sm_perf_info_t *info)
{
    int32_t status = SM_ERR_SUCCESS;

    if (DEV_SM_PerfIsReserved(domainId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        info->rateLimit = 0U;   /* rate limiting not supported */

        /* Assume highest level frequency can be sustained.  Performance
         * level value is same as max sustained frequency.
         */
        uint32_t psIdx = s_perfCfg[domainId].psCfg->psIdx;
        uint32_t levelIdx = 0U;

        /* Check the value doesn't wrap */
        if (s_perfNumLevels[psIdx] >= 1U)
        {
            levelIdx = s_perfNumLevels[psIdx] - 1U;
        }

        info->sustainedFreq = s_perfCfg[domainId].desc[levelIdx].value;
        info->sustainedPerfLevel = levelIdx;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return number of performance levels                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfNumLevelsGet(uint32_t domainId, uint32_t *numLevels)
{
    int32_t status = SM_ERR_SUCCESS;

    if (DEV_SM_PerfIsReserved(domainId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        uint32_t psIdx = s_perfCfg[domainId].psCfg->psIdx;
        *numLevels =  s_perfNumLevels[psIdx];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return supported performance level                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfDescribe(uint32_t domainId, uint32_t levelIndex,
    dev_sm_perf_desc_t *desc)
{
    int32_t status = SM_ERR_SUCCESS;

    if (DEV_SM_PerfIsReserved(domainId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Check array bounds */
        uint32_t psIdx = s_perfCfg[domainId].psCfg->psIdx;
        if (levelIndex >= s_perfNumLevels[psIdx])
        {
            status = SM_ERR_OUT_OF_RANGE;
        }
        else
        {
            *desc = s_perfCfg[domainId].desc[levelIndex];
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set performance domain level                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfLevelSet(uint32_t domainId, uint32_t perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (DEV_SM_PerfIsReserved(domainId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        dev_sm_perf_ps_cfg_t const *psCfg = s_perfCfg[domainId].psCfg;

        /* Check array bounds */
        if (perfLevel >= s_perfNumLevels[psCfg->psIdx])
        {
            status = SM_ERR_OUT_OF_RANGE;
        }
        else
        {
            /* Check for setpoint power domain dependency (i.e. local PLL) */
            uint32_t srcMixIdx = s_perfCfg[domainId].srcMixIdx;
            status = DEV_SM_PerfPowerCheck(perfLevel, srcMixIdx);

            /* Default supply perf level to new requested level */
            uint32_t supplyPerfLevel = perfLevel;

            if (status == SM_ERR_SUCCESS)
            {
                /* Scan for highest perf level of respective power supply */
                status = DEV_SM_PerfMaxScan(domainId, &supplyPerfLevel);
            }

            if (status == SM_ERR_SUCCESS)
            {
                /* Security-relevant update start */
                DEV_SM_PerfEleUpdate(domainId, perfLevel, supplyPerfLevel);

                /* If lowering perf level, adjust frequency first */
                if (perfLevel < s_perfLevelCurrent[domainId])
                {
                    status = DEV_SM_PerfFreqUpdate(domainId, perfLevel);
                }
            }

            if (status == SM_ERR_SUCCESS)
            {
                /* Adjust voltage setpoint based on max scanned perf level */
                status = DEV_SM_PerfSupplyUpdate(psCfg, supplyPerfLevel);
            }

            if (status == SM_ERR_SUCCESS)
            {
                /* If raising perf level, adjust frequency last */
                if (perfLevel > s_perfLevelCurrent[domainId])
                {
                    status = DEV_SM_PerfFreqUpdate(domainId, perfLevel);
                }
            }

            /* Security-relevant update done */
            bool abortUpdate = status != SM_ERR_SUCCESS;
            DEV_SM_PerfEleDone(abortUpdate);
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Update current setpoint upon success */
        status = DEV_SM_PerfCurrentUpdate(domainId, perfLevel);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get performance domain level                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfLevelGet(uint32_t domainId, uint32_t *perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (DEV_SM_PerfIsReserved(domainId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        *perfLevel = s_perfLevelCurrent[domainId];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set frequency of performance domain                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfFreqSet(uint32_t domainId, uint32_t perfLevel)
{
    return DEV_SM_PerfFreqUpdate(domainId, perfLevel);
}

/*--------------------------------------------------------------------------*/
/* Configure performance level for system sleep                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfSystemSleep(uint32_t perfLevelSleep)
{
    int32_t status = SM_ERR_SUCCESS;

    if (perfLevelSleep >= DEV_SM_NUM_PERF_LVL_SOC)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }
    else
    {
        /* Find wake performance level */
        uint32_t perfLevelWake = DEV_SM_PerfSystemSleepScan();

        /* Security-relevant update start */
        DEV_SM_PerfEleUpdateAll(perfLevelSleep, false);

        /* Raise VDD_SOC setpoint if sleep perf level higher than max
         * among sleep domains
         */
        if (perfLevelSleep > perfLevelWake)
        {
            status = DEV_SM_PerfSupplyUpdate(&s_psCfgSoc, perfLevelSleep);
        }

        /* Update levels for perf domains in sleep list */
        uint32_t slpIdx = DEV_SM_NUM_PERF_SLEEP;

        while ((status == SM_ERR_SUCCESS) &&
            (slpIdx > 0U))
        {
            slpIdx--;

            uint32_t domainId = s_perfSleepDomain[slpIdx];

            if (perfLevelSleep < s_perfLevelCurrent[domainId])
            {
                status = DEV_SM_PerfFreqUpdate(domainId, perfLevelSleep);
            }
        }

        if (status == SM_ERR_SUCCESS)
        {
            /* If moving to parked level, update MIX-level bus clocks */
            if (perfLevelSleep == DEV_SM_PERF_LVL_PRK)
            {
                status = DEV_SM_PerfBusFreqSet(true);
            }
        }

        /* Update SM sleep performance level */
        if (status == SM_ERR_SUCCESS)
        {
            /* Update SM sleep performance level */
            if (perfLevelSleep < s_perfLevelCurrent[DEV_SM_PERF_M33])
            {
                status = DEV_SM_PerfFreqUpdate(DEV_SM_PERF_M33,
                    perfLevelSleep);
            }
        }

        if (status == SM_ERR_SUCCESS)
        {
            /* Lower VDD_SOC setpoint if sleep perf level lower than max
             * among sleep domains
             */
            if (perfLevelSleep < perfLevelWake)
            {
                /* Lower VDD_SOC setpoint for sleep perf level */
                status = DEV_SM_PerfSupplyUpdate(&s_psCfgSoc, perfLevelSleep);
            }
        }

        /* Security-relevant update done */
        bool abortUpdate = status != SM_ERR_SUCCESS;
        DEV_SM_PerfEleDone(abortUpdate);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set performance level for system wake                                    */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfSystemWake(uint32_t perfLevelSleep)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Note: s_perfLevelCurrent maintains perf rates to restore upon wake */

    /* Find wake performance level */
    uint32_t perfLevelWake = DEV_SM_PerfSystemSleepScan();

    /* Security-relevant update start */
    DEV_SM_PerfEleUpdateAll(perfLevelWake, false);

    /* Raise VDD_SOC setpoint if wake perf level higher than sleep level */
    if (perfLevelWake > perfLevelSleep)
    {
        /* Raise VDD_SOC setpoint for wake perf level */
        status = DEV_SM_PerfSupplyUpdate(&s_psCfgSoc, perfLevelWake);
    }

    /* Restore SM sleep performance level */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_PerfFreqUpdate(DEV_SM_PERF_M33,
            s_perfLevelCurrent[DEV_SM_PERF_M33]);
    }

    /* Unpark MIX-level bus clocks */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_PerfBusFreqSet(false);
    }

    /* Restore levels for perf domains in sleep list */
    uint32_t slpIdx = 0U;

    while ((status == SM_ERR_SUCCESS) &&
        (slpIdx < DEV_SM_NUM_PERF_SLEEP))
    {
        uint32_t perfIdx = s_perfSleepDomain[slpIdx];

        status = DEV_SM_PerfFreqUpdate(perfIdx,
            s_perfLevelCurrent[perfIdx]);
        slpIdx++;
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Lower VDD_SOC setpoint if wake perf lower than sleep level */
        if (perfLevelWake < perfLevelSleep)
        {
            /* Lower VDD_SOC setpoint for wake perf level */
            status = DEV_SM_PerfSupplyUpdate(&s_psCfgSoc, perfLevelWake);
        }
    }

    /* Security-relevant update done */
    bool abortUpdate = status != SM_ERR_SUCCESS;
    DEV_SM_PerfEleDone(abortUpdate);

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Check if PD/CPU is disabled in fuses                                     */
/*--------------------------------------------------------------------------*/
bool DEV_SM_PerfIsReserved(uint32_t domainId)
{
    bool rc = false;
    uint32_t pwrDomainId = DEV_SM_NUM_POWER;

    switch (domainId)
    {
        case DEV_SM_PERF_M7:
            pwrDomainId = DEV_SM_PD_M7;
            break;

        case DEV_SM_PERF_GPU:
            pwrDomainId = DEV_SM_PD_GPU;
            break;

        case DEV_SM_PERF_VPU:
            pwrDomainId = DEV_SM_PD_VPU;
            break;

        case DEV_SM_PERF_DISP:
            pwrDomainId = DEV_SM_PD_DISPLAY;
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    if (domainId >= DEV_SM_NUM_PERF)
    {
        rc = true;
    }
    else
    {
        /* Check fuse state of power domain */
        if (pwrDomainId < DEV_SM_NUM_POWER)
        {
            if (DEV_SM_FusePdDisabled(pwrDomainId))
            {
                rc = true;
            }
        }
    }

    /* Return status */
    return rc;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Check for performance level clocking power dependency                    */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfPowerCheck(uint32_t perfLevel, uint32_t srcMixIdx)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check if perfLevel needs local PLL */
    if (perfLevel > DEV_SM_PERF_LVL_PRK)
    {
        switch (srcMixIdx)
        {
            /* DDR PLL is local to DDRMIX */
            case PWR_MIX_SLICE_IDX_DDR:
                if (!SRC_MixIsPwrSwitchOn(PWR_MIX_SLICE_IDX_DDR))
                {
                    status = SM_ERR_POWER;
                }
                break;

            /* ARM PLL is local to CORTEXAMIX */
            case PWR_MIX_SLICE_IDX_A55C0:
            case PWR_MIX_SLICE_IDX_A55C1:
            case PWR_MIX_SLICE_IDX_A55C2:
            case PWR_MIX_SLICE_IDX_A55C3:
            case PWR_MIX_SLICE_IDX_A55C4:
            case PWR_MIX_SLICE_IDX_A55C5:
            case PWR_MIX_SLICE_IDX_A55P:
                if (!SRC_MixIsPwrSwitchOn(PWR_MIX_SLICE_IDX_A55P))
                {
                    status = SM_ERR_POWER;
                }
                break;

            default:
                ; /* Intentional empty default */
                break;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Scan for maximum performance level                                       */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfMaxScan(uint32_t domainId, uint32_t *maxPerfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (DEV_SM_PerfIsReserved(domainId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* A55 does not require scan of A55 performance subdomains */
        if (domainId != DEV_SM_PERF_A55)
        {
            dev_sm_perf_ps_cfg_t const *psCfg = s_perfCfg[domainId].psCfg;

            /* Scan other domains on same power supply  */
            for (uint32_t id = psCfg->idStart; id <= psCfg->idEnd; id++)
            {
                if (id != domainId)
                {
                    if (s_perfCfg[id].psCfg->psIdx == psCfg->psIdx)
                    {
                        if (s_perfLevelCurrent[id] > *maxPerfLevel)
                        {
                            *maxPerfLevel = s_perfLevelCurrent[id];
                        }
                    }
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Scan for maximum performance level among system sleep domains            */
/*--------------------------------------------------------------------------*/
static uint32_t DEV_SM_PerfSystemSleepScan(void)
{
    uint32_t maxPerfLevel = DEV_SM_PERF_LVL_PRK;

    /* Find max perf level among system sleep domains */
    for (uint32_t slpIdx = 0U; slpIdx < DEV_SM_NUM_PERF_SLEEP; slpIdx++)
    {
        uint32_t perfIdx = s_perfSleepDomain[slpIdx];
        if (s_perfLevelCurrent[perfIdx] > maxPerfLevel)
        {
            maxPerfLevel = s_perfLevelCurrent[perfIdx];
        }
    }

    if (s_perfLevelCurrent[DEV_SM_PERF_M33] > maxPerfLevel)
    {
        maxPerfLevel = s_perfLevelCurrent[DEV_SM_PERF_M33];
    }

    return maxPerfLevel;
}

/*--------------------------------------------------------------------------*/
/* Update clock root frequency of performance level                         */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfRootFreqUpdate(uint32_t rootClk,
    dev_sm_perf_root_cfg_t const *rootCfg)
{
    int32_t status = SM_ERR_SUCCESS;

    uint32_t oldDiv;
    if (!CCM_RootGetDiv(rootClk, &oldDiv))
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    uint32_t oldParent;
    if (status == SM_ERR_SUCCESS)
    {
        if (!CCM_RootGetParent(rootClk, &oldParent))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    uint32_t newDiv = rootCfg->rootDiv;
    uint32_t newParent = rootCfg->parent;

    if (status == SM_ERR_SUCCESS)
    {
        /* if new divider is larger, apply first */
        if (newDiv > oldDiv)
        {
            if (!CCM_RootSetDiv(rootClk, newDiv))
            {
                status = SM_ERR_HARDWARE_ERROR;
            }
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        if (newParent != oldParent)
        {
            if (!CCM_RootSetParent(rootClk, newParent))
            {
                status = SM_ERR_HARDWARE_ERROR;
            }
        }
        if (status == SM_ERR_SUCCESS)
        {
            if (newDiv < oldDiv)
            {
                if (!CCM_RootSetDiv(rootClk, newDiv))
                {
                    status = SM_ERR_HARDWARE_ERROR;
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Update PLL frequency of performance level                                */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfPllFreqUpdate(uint32_t pllIdx,
    dev_sm_perf_pll_cfg_t const *pllCfg)
{
    int32_t status = SM_ERR_SUCCESS;

    if (!FRACTPLL_UpdateRate(pllIdx,
        pllCfg->mfi,
        pllCfg->mfn,
        pllCfg->odiv,
        true))
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Update PFD frequency of performance level                                */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfPfdFreqUpdate(uint32_t pllIdx, uint8_t pfdIdx,
    dev_sm_perf_pfd_cfg_t const *pfdUpdate)
{
    int32_t status = SM_ERR_SUCCESS;

    if (!FRACTPLL_UpdateDfsRate(pllIdx,
        pfdIdx,
        pfdUpdate->mfi,
        pfdUpdate->mfn,
        true))
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Update MIX-level bus frequencies                                         */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfBusFreqSet(bool parkedLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    static const uint32_t s_busClkRoot[DEV_SM_PERF_NUM_BUS_CLK] =
    {
        [0] = CLOCK_ROOT_CAMAPB,
        [1] = CLOCK_ROOT_A55MTRBUS,
        [2] = CLOCK_ROOT_DRAMAPB,
        [3] = CLOCK_ROOT_DISPAPB,
        [4] = CLOCK_ROOT_GPUAPB,
        [5] = CLOCK_ROOT_BUSM7,
        [6] = CLOCK_ROOT_BUSNETCMIX,
        [7] = CLOCK_ROOT_NOCAPB,
        [8] = CLOCK_ROOT_NPUAPB,
        [9] = CLOCK_ROOT_VPUAPB,
        [10] = CLOCK_ROOT_BUSWAKEUP
    };

    static const uint8_t s_busClkSrcSel[DEV_SM_PERF_NUM_BUS_CLK] =
    {
        [0] = 2U,
        [1] = 2U,
        [2] = 2U,
        [3] = 2U,
        [4] = 2U,
        [5] = 2U,
        [6] = 2U,
        [7] = 2U,
        [8] = 2U,
        [9] = 2U,
        [10] = 2U
    };

    static const uint8_t s_busClkDiv[DEV_SM_PERF_NUM_BUS_CLK] =
    {
        [0] = 2U,
        [1] = 2U,
        [2] = 2U,
        [3] = 2U,
        [4] = 2U,
        [5] = 2U,
        [6] = 2U,
        [7] = 2U,
        [8] = 2U,
        [9] = 2U,
        [10] = 2U
    };

    /* Parked level moves bus clock source to OSC24M / 1 */
    if (parkedLevel)
    {
        /* Update MIX-level bus clocks not scaled by perf levels  */
        for (uint32_t clkIdx = 0U; clkIdx < DEV_SM_PERF_NUM_BUS_CLK; clkIdx++)
        {
            uint32_t rootIdx = s_busClkRoot[clkIdx];

            /* Set MUX = 0 (OSC_24M) */
            CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.CLR =
                CCM_CLOCK_ROOT_MUX_MASK;

            /* Set DIV = 0 (/1) */
            CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.CLR =
                CCM_CLOCK_ROOT_DIV_MASK;
        }

        /* Update BUSAON clock last */
        CCM_CTRL->CLOCK_ROOT[CLOCK_ROOT_BUSAON].CLOCK_ROOT_CONTROL.CLR =
            CCM_CLOCK_ROOT_MUX_MASK;
        CCM_CTRL->CLOCK_ROOT[CLOCK_ROOT_BUSAON].CLOCK_ROOT_CONTROL.CLR =
            CCM_CLOCK_ROOT_DIV_MASK;
    }
    else
    {
        uint32_t cr;

        /* Update BUSAON clock first */
        cr = CCM_CTRL->CLOCK_ROOT[CLOCK_ROOT_BUSAON].CLOCK_ROOT_CONTROL.RW;
        cr &= (~(CCM_CLOCK_ROOT_DIV_MASK));
        cr |= CCM_CLOCK_ROOT_DIV(0x2U);
        CCM_CTRL->CLOCK_ROOT[CLOCK_ROOT_BUSAON].CLOCK_ROOT_CONTROL.RW = cr;

        cr = CCM_CTRL->CLOCK_ROOT[CLOCK_ROOT_BUSAON].CLOCK_ROOT_CONTROL.RW;
        cr &= (~(CCM_CLOCK_ROOT_MUX_MASK));
        cr |= CCM_CLOCK_ROOT_MUX(0x2U);
        CCM_CTRL->CLOCK_ROOT[CLOCK_ROOT_BUSAON].CLOCK_ROOT_CONTROL.RW = cr;

        /* Update MIX-level bus clocks not scaled by perf levels  */
        for (uint32_t clkIdx = 0U; clkIdx < DEV_SM_PERF_NUM_BUS_CLK; clkIdx++)
        {
            uint32_t rootIdx = s_busClkRoot[clkIdx];
            uint8_t rootSrcSel = s_busClkSrcSel[clkIdx];
            uint8_t rootDiv = s_busClkDiv[clkIdx];

            /* Set DIV = 2 (/3) */
            cr = CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW;
            cr &= (~(CCM_CLOCK_ROOT_DIV_MASK));
            cr |= CCM_CLOCK_ROOT_DIV(rootDiv);
            CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW = cr;

            /* Set MUX = 2 */
            cr = CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW;
            cr &= (~(CCM_CLOCK_ROOT_MUX_MASK));
            cr |= CCM_CLOCK_ROOT_MUX(rootSrcSel);
            CCM_CTRL->CLOCK_ROOT[rootIdx].CLOCK_ROOT_CONTROL.RW = cr;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Update WAKEUP frequency of performance level                             */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfWakeupFreqUpdate(uint32_t perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (perfLevel >= DEV_SM_NUM_PERF_LVL_SOC)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }
    else
    {
        status = DEV_SM_PerfRootFreqUpdate(
            s_perfCfg[DEV_SM_PERF_WAKEUP].rootClk,
            &s_perfCfg[DEV_SM_PERF_WAKEUP].rootCfg[perfLevel]);

        if (status == SM_ERR_SUCCESS)
        {
            status = DEV_SM_PerfRootFreqUpdate(CLOCK_ROOT_V2XPK,
                &s_perfRootCfgWakeupV2X[perfLevel]);
        }
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Update VPU frequency of performance level                                */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfVpuFreqUpdate(uint32_t perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (perfLevel >= DEV_SM_NUM_PERF_LVL_SOC)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }
    else
    {
        status = DEV_SM_PerfRootFreqUpdate(
            s_perfCfg[DEV_SM_PERF_VPU].rootClk,
            &s_perfCfg[DEV_SM_PERF_VPU].rootCfg[perfLevel]);

        if (status == SM_ERR_SUCCESS)
        {
            status = DEV_SM_PerfRootFreqUpdate(CLOCK_ROOT_VPUJPEG,
                &s_perfRootCfgVpuJpeg[perfLevel]);
        }
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Update CAM frequency of performance level                                */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfCamFreqUpdate(uint32_t perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (perfLevel >= DEV_SM_NUM_PERF_LVL_SOC)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }
    else
    {
        status = DEV_SM_PerfRootFreqUpdate(
            s_perfCfg[DEV_SM_PERF_CAM].rootClk,
            &s_perfCfg[DEV_SM_PERF_CAM].rootCfg[perfLevel]);

        if (status == SM_ERR_SUCCESS)
        {
            status = DEV_SM_PerfRootFreqUpdate(CLOCK_ROOT_CAMISI,
                &s_perfRootCfgCamIsi[perfLevel]);
        }

        if (status == SM_ERR_SUCCESS)
        {
            status = DEV_SM_PerfRootFreqUpdate(CLOCK_ROOT_CAMCM0,
                &s_perfRootCfgCamCm0[perfLevel]);
        }
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Update DISP frequency of performance level                               */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfDispFreqUpdate(uint32_t perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (perfLevel >= DEV_SM_NUM_PERF_LVL_SOC)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }
    else
    {
        status = DEV_SM_PerfRootFreqUpdate(
            s_perfCfg[DEV_SM_PERF_DISP].rootClk,
            &s_perfCfg[DEV_SM_PERF_DISP].rootCfg[perfLevel]);

        if (status == SM_ERR_SUCCESS)
        {
            status = DEV_SM_PerfRootFreqUpdate(CLOCK_ROOT_DISPOCRAM,
                &s_perfRootCfgDispOcram[perfLevel]);
        }
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Update DRAM frequency of performance level                               */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfDramFreqUpdate(uint32_t perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (perfLevel >= DEV_SM_NUM_PERF_LVL_SOC)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_PerfRootFreqUpdate(CLOCK_ROOT_DRAMALT,
            &s_perfRootCfgDram);
    }

    uint32_t selIdx = g_clockGprSel[CLOCK_GPR_SEL_DRAM].selIdx;
    uint32_t selMask = g_clockGprSel[CLOCK_GPR_SEL_DRAM].selMask;

    if (status == SM_ERR_SUCCESS)
    {
        if (!CCM_GprValSet(selIdx, selMask, selMask))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }
    if (status == SM_ERR_SUCCESS)
    {
        if (perfLevel > DEV_SM_PERF_LVL_PRK)
        {
            status = DEV_SM_PerfPllFreqUpdate(CLOCK_PLL_DRAM,
                &s_perfPllCfgDram[perfLevel]);

            if (status == SM_ERR_SUCCESS)
            {
                if (!CCM_GprValSet(selIdx, selMask, 0U))
                {
                    status = SM_ERR_HARDWARE_ERROR;
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Update A55 frequency of performance level                                */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfA55FreqUpdate(uint32_t perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (perfLevel >= s_perfNumLevels[PS_VDD_ARM])
    {
        status = SM_ERR_OUT_OF_RANGE;
    }
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_PerfRootFreqUpdate(CLOCK_ROOT_A55, &s_perfRootCfgA55);
    }

    uint32_t selIdx = DEV_SM_A55_GPR_SEL_IDX;
    uint32_t selMask = DEV_SM_A55_GPR_SEL_MASK;

    if (status == SM_ERR_SUCCESS)
    {
        if (!CCM_GprValSet(selIdx, selMask, 0U))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_PerfRootFreqUpdate(CLOCK_ROOT_A55PERIPH,
            &s_perfRootCfgA55Per[perfLevel]);
    }
    if (status == SM_ERR_SUCCESS)
    {
        if (perfLevel > DEV_SM_PERF_LVL_PRK)
        {
            status = DEV_SM_PerfPllFreqUpdate(CLOCK_PLL_ARM,
                // cppcheck-suppress arrayIndexOutOfBoundsCond
                &s_perfPllCfgA55[perfLevel]);
            if (status == SM_ERR_SUCCESS)
            {
                status = DEV_SM_PerfPfdFreqUpdate(CLOCK_PLL_ARM, 0U,
                    &s_perfPfdCfgA55C[perfLevel]);
            }
            if (status == SM_ERR_SUCCESS)
            {
                status = DEV_SM_PerfPfdFreqUpdate(CLOCK_PLL_ARM, 1U,
                    &s_perfPfdCfgA55C[perfLevel]);
            }
            if (status == SM_ERR_SUCCESS)
            {
                status = DEV_SM_PerfPfdFreqUpdate(CLOCK_PLL_ARM, 2U,
                    &s_perfPfdCfgA55C[perfLevel]);
            }
            if (status == SM_ERR_SUCCESS)
            {
                status = DEV_SM_PerfPfdFreqUpdate(CLOCK_PLL_ARM, 3U,
                    &s_perfPfdCfgA55P[perfLevel]);
            }
            if (status == SM_ERR_SUCCESS)
            {
                if (!CCM_GprValSet(selIdx, selMask, selMask))
                {
                    status = SM_ERR_HARDWARE_ERROR;
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Update power supply supply of performance level                          */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfSupplyUpdate(dev_sm_perf_ps_cfg_t const *psCfg,
    uint32_t perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (psCfg == NULL)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }
    else
    {
        /* Update supply level as needed based on tracked level */
        if (s_perfPsVoltCurrent[psCfg->psIdx] != psCfg->dvsTable[perfLevel])
        {
            /* Adjust voltage setpoint based on max scanned perf level */
            status = BRD_SM_SupplyLevelSet(psCfg->psIdx,
                psCfg->dvsTable[perfLevel]);

            /* Track supply level */
            s_perfPsVoltCurrent[psCfg->psIdx] = psCfg->dvsTable[perfLevel];
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Update frequency of performance level                                    */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfFreqUpdate(uint32_t domainId, uint32_t perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (DEV_SM_PerfIsReserved(domainId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        switch (domainId)
        {
            case DEV_SM_PERF_WAKEUP:
                status = DEV_SM_PerfWakeupFreqUpdate(perfLevel);
                break;

            case DEV_SM_PERF_DRAM:
                status = DEV_SM_PerfDramFreqUpdate(perfLevel);
                break;

            case DEV_SM_PERF_A55:
                status = DEV_SM_PerfA55FreqUpdate(perfLevel);
                break;

            case DEV_SM_PERF_VPU:
                status = DEV_SM_PerfVpuFreqUpdate(perfLevel);
                break;

            case DEV_SM_PERF_CAM:
                status = DEV_SM_PerfCamFreqUpdate(perfLevel);
                break;

            case DEV_SM_PERF_DISP:
                status = DEV_SM_PerfDispFreqUpdate(perfLevel);
                break;

            default:
                /* Other valid domains default to a clock root update */
                if (perfLevel >= DEV_SM_NUM_PERF_LVL_SOC)
                {
                    status = SM_ERR_OUT_OF_RANGE;
                }
                else
                {
                    status = DEV_SM_PerfRootFreqUpdate(
                        s_perfCfg[domainId].rootClk,
                        &s_perfCfg[domainId].rootCfg[perfLevel]);
                }
                break;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Update current performance level                                         */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfCurrentUpdate(uint32_t domainId, uint32_t perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    switch (domainId)
    {
        case DEV_SM_PERF_A55:
            {
                s_perfLevelCurrent[DEV_SM_PERF_A55] = perfLevel;

                dev_sm_perf_ps_cfg_t const *psCfg =
                    s_perfCfg[DEV_SM_PERF_A55].psCfg;

                /* Update all subdomains */
                for (uint32_t id = psCfg->idStart; id <= psCfg->idEnd; id++)
                {
                    s_perfLevelCurrent[id] = perfLevel;
                }
            }
            break;
        default:
            if (DEV_SM_PerfIsReserved(domainId))
            {
                status = SM_ERR_NOT_FOUND;
            }
            else
            {
                s_perfLevelCurrent[domainId] = perfLevel;
            }
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Query current performance level                                          */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_PerfCurrentGet(uint32_t domainId, uint32_t *perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t clockId;
    dev_sm_perf_desc_t const *perfDesc;

    switch (domainId)
    {
        case DEV_SM_PERF_DRAM:
            clockId = DEV_SM_CLK_DRAM_GPR_SEL;
            perfDesc = s_perfDescDram;
            break;

        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Get rate of clock associated with PERF domain*/
        uint64_t rate;
        status = DEV_SM_ClockRateGet(clockId, &rate);

        if (status == SM_ERR_SUCCESS)
        {
            uint32_t psIdx = s_perfCfg[domainId].psCfg->psIdx;
            uint32_t numLevels = s_perfNumLevels[psIdx];

            /* Convert rate to KHz */
            uint32_t rateKHz =  UINT64_L(rate / 1000ULL);

            /* Default to highest level to handle overclocking case */
            if (numLevels > 0U)
            {
                *perfLevel = numLevels - 1U;
            }

            /* Map current rate to PERF level */
            uint32_t level = 0U;
            bool bSearch = true;
            while (bSearch && (level < numLevels))
            {
                /* Rate in KHz for level stored in value field of PERF description */
                if (perfDesc[level].value >= rateKHz)
                {
                    bSearch = false;
                    *perfLevel = level;
                }
                else
                {
                    ++level;
                }
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Query DRAM memory type                                                   */
/*--------------------------------------------------------------------------*/
static uint32_t DEV_SM_PerfDramTypeGet(void)
{
    static uint32_t s_perfDramType = 0U;  /* Tracks DDRC SDRAM_TYPE field */

    /* Check if DRAM type is unknown */
    if (s_perfDramType == 0U)
    {
        /* Check if we can access the DDRC */
        if (SRC_MixIsPwrReady(PWR_MIX_SLICE_IDX_DDR))
        {
            /* Query DRAM type */
            s_perfDramType = (DDRC->DDR_SDRAM_CFG
                & DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_MASK)
                >>  DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_SHIFT;
        }
    }

    return s_perfDramType;
}

/*--------------------------------------------------------------------------*/
/* Query SoC package type                                                   */
/*--------------------------------------------------------------------------*/
static uint32_t DEV_SM_PerfSocPkgTypeGet(void)
{
    static uint32_t s_perfPkgType = 0U;

    /* Check if DRAM type is unknown */
    if (s_perfPkgType == 0U)
    {
        uint32_t partNum = DEV_SM_FuseGet(DEV_SM_FUSE_PART_NUM);
        s_perfPkgType = DEV_SM_PN_PKG(partNum);
    }

    return s_perfPkgType;
}

/*--------------------------------------------------------------------------*/
/* Update performance table entries based on SoC attributes                 */
/*--------------------------------------------------------------------------*/
static void DEV_SM_PerfCfgInit(void)
{
    /* Query A55 speed grade from fuses */
    uint32_t speedGrade = DEV_SM_FuseSpeedGet();

    /* Check for 2+GHz device */
    if (speedGrade >= 2000000000U)
    {
        /* 2+GHz devices support PRK, LOW, NOM, ODV, SOD setpoints */
        s_perfNumLevels[PS_VDD_ARM] = DEV_SM_NUM_PERF_LVL_ARM;
    }
    /* Check for 1GHz device */
    else if (speedGrade == 1000000000U)
    {
        /* 1GHz devices support PRK, LOW, NOM setpoints */
        s_perfNumLevels[PS_VDD_ARM] = DEV_SM_NUM_PERF_LVL_ARM - 2U;

        /* 1GHz devices require updated PERF table entries for NOM setpoint */
        s_perfDescA55[DEV_SM_PERF_LVL_NOM].value = ES_1000000KHZ;

        /*
         * PLL_VCO = 24MHz * 150 = 3600MHz
         */
        s_perfPllCfgA55[DEV_SM_PERF_LVL_NOM].mfi = 150U;
        s_perfPllCfgA55[DEV_SM_PERF_LVL_NOM].mfn = 0U;
        s_perfPllCfgA55[DEV_SM_PERF_LVL_NOM].odiv = 0U;

        /*
         * PLL_PFD = 3600MHz / (3 + 3/5) = 1000MHz
         */
        s_perfPfdCfgA55C[DEV_SM_PERF_LVL_NOM].mfi = 3U;
        s_perfPfdCfgA55C[DEV_SM_PERF_LVL_NOM].mfn = 3U;
        s_perfPfdCfgA55P[DEV_SM_PERF_LVL_NOM].mfi = 3U;
        s_perfPfdCfgA55P[DEV_SM_PERF_LVL_NOM].mfn = 3U;
    }
    else
    {
        /* All other devices support PRK, LOW, NOM, ODV setpoints */
        s_perfNumLevels[PS_VDD_ARM] = DEV_SM_NUM_PERF_LVL_ARM - 1U;
    }

    /* Check for LPDDR4X */
    if (DEV_SM_PerfDramTypeGet() == 4U)
    {
        /* Check for 15x15 package */
        if (DEV_SM_PerfSocPkgTypeGet() == DEV_SM_PN_PKG_VT)
        {
            s_perfDescDram[DEV_SM_PERF_LVL_LOW].value =
                ES_LOW_KHZ_DRAM_LP4X_15X15;
            /*
             * PLL_VCO = 24MHz * (155+1/2) = 3732MHz
             * PLL_OUT = PLL_VCO / 16 = 233.25MHz
             * 233.25MHz * 8 = 1866 MTs
             */
            s_perfPllCfgDram[DEV_SM_PERF_LVL_LOW].mfi = 155U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_LOW].mfn = VCO_MFD / 2U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_LOW].odiv = 16U;

            s_perfDescDram[DEV_SM_PERF_LVL_NOM].value =
                ES_NOM_KHZ_DRAM_LP4X_15X15;
            /*
             * PLL_VCO = 24MHz * (175) = 4200MHz
             * PLL_OUT = PLL_VCO / 12 = 350MHz
             * 350MHz * 8 = 2800 MTs
             */
            s_perfPllCfgDram[DEV_SM_PERF_LVL_NOM].mfi = 175U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_NOM].mfn = 0U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_NOM].odiv = 12U;

            s_perfDescDram[DEV_SM_PERF_LVL_ODV].value =
                ES_ODV_KHZ_DRAM_LP4X_15X15;
            /*
             * PLL_VCO = 24MHz * (166+2/3) = 4000MHz
             * PLL_OUT = PLL_VCO / 8 = 500MHz
             * 500MHz * 8 = 4000 MTs
             */
            s_perfPllCfgDram[DEV_SM_PERF_LVL_ODV].mfi = 166U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_ODV].mfn = VCO_MFD * 2U / 3U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_ODV].odiv = 8U;
        }
        /* Else 19x19 package */
        else
        {
            s_perfDescDram[DEV_SM_PERF_LVL_LOW].value =
                ES_LOW_KHZ_DRAM_LP4X_19X19;
            /*
             * PLL_VCO = 24MHz * (155+1/2) = 3732MHz
             * PLL_OUT = PLL_VCO / 16 = 233.25MHz
             * 233.25MHz * 8 = 1866 MTs
             */
            s_perfPllCfgDram[DEV_SM_PERF_LVL_LOW].mfi = 155U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_LOW].mfn = VCO_MFD / 2U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_LOW].odiv = 16U;

            s_perfDescDram[DEV_SM_PERF_LVL_NOM].value =
                ES_NOM_KHZ_DRAM_LP4X_19X19;
            /*
             * PLL_VCO = 24MHz * (180) = 4320MHz
             * PLL_OUT = PLL_VCO / 12 = 360MHz
             * 360MHz * 8 = 2880 MTs
             */
            s_perfPllCfgDram[DEV_SM_PERF_LVL_NOM].mfi = 180U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_NOM].mfn = 0U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_NOM].odiv = 12U;

            s_perfDescDram[DEV_SM_PERF_LVL_ODV].value =
                ES_ODV_KHZ_DRAM_LP4X_19X19;
            /*
             * PLL_VCO = 24MHz * (133+5/16) = 3199.5MHz
             * PLL_OUT = PLL_VCO / 6 = 533.25MHz
             * 533.25MHz * 8 = 4266 MTs
             */
            s_perfPllCfgDram[DEV_SM_PERF_LVL_ODV].mfi = 133U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_ODV].mfn = VCO_MFD * 5U / 16U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_ODV].odiv = 6U;
        }
    }
    /* Else LPDDR5 */
    else
    {
        /* Check for 15x15 package */
        if (DEV_SM_PerfSocPkgTypeGet() == DEV_SM_PN_PKG_VT)
        {
            s_perfDescDram[DEV_SM_PERF_LVL_LOW].value =
                ES_LOW_KHZ_DRAM_LP5_15X15;
            /*
             * PLL_VCO = 24MHz * (155+1/2) = 3732MHz
             * PLL_OUT = PLL_VCO / 16 = 233.25MHz
             * 233.25MHz * 8 = 1866 MTs
             */
            s_perfPllCfgDram[DEV_SM_PERF_LVL_LOW].mfi = 155U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_LOW].mfn = VCO_MFD / 2U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_LOW].odiv = 16U;

            s_perfDescDram[DEV_SM_PERF_LVL_NOM].value =
                ES_NOM_KHZ_DRAM_LP5_15X15;
            /*
             * PLL_VCO = 24MHz * (133+1/3) = 3200MHz
             * PLL_OUT = PLL_VCO / 8 = 400MHz
             * 400MHz * 8 = 3200 MTs
             */
            s_perfPllCfgDram[DEV_SM_PERF_LVL_NOM].mfi = 133U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_NOM].mfn = VCO_MFD / 3U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_NOM].odiv = 8U;

            s_perfDescDram[DEV_SM_PERF_LVL_ODV].value =
                ES_ODV_KHZ_DRAM_LP5_15X15;
            /*
             * PLL_VCO = 24MHz * (133+5/16) = 3199.5MHz
             * PLL_OUT = PLL_VCO / 6 = 533.25MHz
             * 533.25MHz * 8 = 4266 MTs
             */
            s_perfPllCfgDram[DEV_SM_PERF_LVL_ODV].mfi = 133U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_ODV].mfn = VCO_MFD * 5U / 16U;
            s_perfPllCfgDram[DEV_SM_PERF_LVL_ODV].odiv = 6U;
        }

        /* Else keep default configuration (LP5 19x19) */
    }
}

/*--------------------------------------------------------------------------*/
/* Start ELE notification of all security-relevant domains                  */
/*--------------------------------------------------------------------------*/
static void DEV_SM_PerfEleUpdateAll(uint32_t perfLevel, bool initMode)
{
    uint32_t flags = 0U;
    uint32_t mode = 0U;
    uint32_t eleMhz = 0U;
    uint32_t m33Mhz = 0U;

    if (perfLevel < DEV_SM_NUM_PERF_LVL_SOC)
    {
        /* Notify ELE of CLOCK_ROOT_ELE change */
        flags |= ELE_DVFS_FLAG_UPDATE_FREQ_ELE;
        eleMhz =
            s_perfCfg[DEV_SM_PERF_ELE].desc[perfLevel].value / 1000U;

        /* Notify ELE of CLOCK_ROOT_M33 change */
        flags |= ELE_DVFS_FLAG_UPDATE_FREQ_M33;
        m33Mhz =
            s_perfCfg[DEV_SM_PERF_M33].desc[perfLevel].value / 1000U;

        /* Check if security-relevant supply will be updated */
        int32_t psVolt = s_perfDvsTableSoc[perfLevel];
        if (initMode || (s_perfPsVoltCurrent[PS_VDD_SOC] != psVolt))
        {
            /* Notify ELE of voltage update */
            flags |= ELE_DVFS_FLAG_UPDATE_VLT;

            /* Map supply update to ELE DVS mode */
            if (psVolt >= ES_ODV_UV_VDD_SOC)
            {
                mode = ELE_DVFS_MODE_OD;
            }
            else if (psVolt >= ES_NOM_UV_VDD_SOC)
            {
                mode = ELE_DVFS_MODE_NM;
            }
            else
            {
                mode = ELE_DVFS_MODE_UD;
            }
        }

        /* Notify ELE of any security-relevalant change */
        ELE_StartDvfsChange(flags, mode, eleMhz, m33Mhz);
        s_perfEleUpdating = true;
    }
}

/*--------------------------------------------------------------------------*/
/* Start ELE notification of a single security-relevant domain              */
/*--------------------------------------------------------------------------*/
static void DEV_SM_PerfEleUpdate(uint32_t domainId, uint32_t perfLevel,
    uint32_t supplyPerfLevel)
{
    uint32_t flags = 0U;
    uint32_t mode = 0U;
    uint32_t eleMhz = 0U;
    uint32_t m33Mhz = 0U;

    if (perfLevel < DEV_SM_NUM_PERF_LVL_SOC)
    {
        /* Check for security relevant performance domain update */
        switch (domainId)
        {
            case DEV_SM_PERF_ELE:
                /* Notify ELE of CLOCK_ROOT_ELE change */
                flags |= ELE_DVFS_FLAG_UPDATE_FREQ_ELE;
                eleMhz =
                    s_perfCfg[DEV_SM_PERF_ELE].desc[perfLevel].value / 1000U;
                break;

            case DEV_SM_PERF_M33:
                /* Notify ELE of CLOCK_ROOT_M33 change */
                flags |= ELE_DVFS_FLAG_UPDATE_FREQ_M33;
                m33Mhz =
                    s_perfCfg[DEV_SM_PERF_M33].desc[perfLevel].value / 1000U;
                break;

            default:
                ; /* Intentional empty default */
                break;
        }
    }

    if (supplyPerfLevel < DEV_SM_NUM_PERF_LVL_SOC)
    {
        /* Check for security-relevant power supply update */
        if (s_perfCfg[domainId].psCfg->psIdx == PS_VDD_SOC)
        {
            /* Check if security-relevant supply will be updated */
            int32_t psVolt = s_perfDvsTableSoc[supplyPerfLevel];
            if (s_perfPsVoltCurrent[PS_VDD_SOC] != psVolt)
            {
                /* Notify ELE of voltage update */
                flags |= ELE_DVFS_FLAG_UPDATE_VLT;

                /* Map supply update to ELE DVS mode */
                if (psVolt >= ES_ODV_UV_VDD_SOC)
                {
                    mode = ELE_DVFS_MODE_OD;
                }
                else if (psVolt >= ES_NOM_UV_VDD_SOC)
                {
                    mode = ELE_DVFS_MODE_NM;
                }
                else
                {
                    mode = ELE_DVFS_MODE_UD;
                }
            }
        }
    }

    /* Notify ELE of any security-relevalant change */
    if (flags != 0U)
    {
        ELE_StartDvfsChange(flags, mode, eleMhz, m33Mhz);
        s_perfEleUpdating = true;
    }
}

/*--------------------------------------------------------------------------*/
/* Notify ELE that security-relevant update is done                         */
/*--------------------------------------------------------------------------*/
static void DEV_SM_PerfEleDone(bool abortUpdate)
{
    if (s_perfEleUpdating)
    {
        /* Send abort if update unsuccessful */
        if (abortUpdate)
        {
            ELE_StartDvfsChange(0U, 0U, 0U, 0U);
        }

        /* Send stop message */
        ELE_StopDvfsChange();
        s_perfEleUpdating = false;
    }
}

