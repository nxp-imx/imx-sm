/*
** ###################################################################
**
**     Copyright 2025-2026 NXP
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
/* File containing the implementation of the SM device configuration        */
/* loading functions.                                                       */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "config_dev.h"
#include "config_bctrl.h"
#include "fsl_fract_pll.h"

/* Local defines */

/* Local types */

typedef struct
{
    bool valid;
    bool freqUpdate;
    uint32_t perfLevel;
} mix_pdn_context;

/* Local variables */

static bool s_tempSensorA55Enabled = false;
static fracpll_context_t s_pllContextHsio;
static fracpll_context_t s_pllContextLdb;
static fracpll_context_t s_pllContextDdr;
static bool s_pllContextValidHsio = false;
static bool s_pllContextValidLdb = false;
static bool s_pllContextValidDdr = false;
static mix_pdn_context s_mixPdnContext55 =
{
    .valid = false
};
static bool s_cpuWaitContextValidM33S = false;
static bool s_cpuWaitContextM33S;

static uint32_t wkupGpioCtrl0 = 0U;
static uint32_t wkupGpioCtrl1 = 0U;

/* Global constant data */

/* Partial init suported for this array */
/* coverity[misra_c_2012_rule_9_3_violation] */
const dev_config_t g_devConfig = SM_DEV_CONFIG_DATA;

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Load A55P power domain configuration                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_A55pConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_A55P_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_A55P_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_A55P_CONFIG_FUNC();
    }
#endif

    /* Path to configure A55 temp sensor dependends on NOC and WAKEUP MIXes */
    if ((!s_tempSensorA55Enabled) &&
        (SRC_MixIsPwrReady(PWR_MIX_SLICE_IDX_NOC)) &&
        (SRC_MixIsPwrReady(PWR_MIX_SLICE_IDX_WAKEUP)))
    {
        /* Power on temp sensor */
        if (DEV_SM_SensorConfigStart(DEV_SM_SENSOR_TEMP_A55, true)
            == SM_ERR_SUCCESS)
        {
            s_tempSensorA55Enabled = true;
        }
    }

    /* Check if A55 resuming with saved power-down context */
    if ((status == SM_ERR_SUCCESS) && (s_mixPdnContext55.valid))
    {
        uint32_t perfLevel = s_mixPdnContext55.perfLevel;

        if (s_mixPdnContext55.freqUpdate)
        {
            /* A55 resume requires clocking restore */
            status = DEV_SM_PerfFreqSet(DEV_SM_PERF_A55, perfLevel);
        }
        else
        {
            /* A55 resume requires performance level restore */
            status = DEV_SM_PerfLevelSet(DEV_SM_PERF_A55, perfLevel);
        }

        /* Clear A55 power down context */
        s_mixPdnContext55.valid = false;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load DDR power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_DdrConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_DDR_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_DDR_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_DDR_CONFIG_FUNC();
    }
#endif

    /* Restore PLL context */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        if (s_pllContextValidDdr)
        {
            /*
             * Driver always returns true because a hard coded valid
             * PLL is used.
             */
            /* gcov_excl_ntbr_nextline */
            if (!FRACTPLL_SetContext(CLOCK_PLL_DRAM, &s_pllContextDdr))
            {
                status = SM_ERR_HARDWARE_ERROR; /* gcov_excl_line  */
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load display power domain configuration                                  */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_DisplayConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_DISPLAY_CONFIG;

    /* Load TRDC D config */
    status = DEV_SM_RdcLoad(DEV_SM_TRDC_D);

    /* Load device config */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load(NULL, s_configData);
    }

#ifdef SM_DISPLAY_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_DISPLAY_CONFIG_FUNC();
    }
#endif

    /* Restore PLL context */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        if (s_pllContextValidLdb)
        {
            /*
             * Driver always returns true because a hard coded valid
             * PLL is used.
             */
            /* gcov_excl_ntbr_nextline */
            if (!FRACTPLL_SetContext(CLOCK_PLL_LDB, &s_pllContextLdb))
            {
                status = SM_ERR_HARDWARE_ERROR; /* gcov_excl_line  */
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load HSIO TOP power domain configuration                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_HsioTopConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_HSIO_TOP_CONFIG;

    /* Load TRDC H config */
    status = DEV_SM_RdcLoad(DEV_SM_TRDC_H);

    /* Load device config */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load(NULL, s_configData);
    }

#ifdef SM_HSIO_TOP_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_HSIO_TOP_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load HSIO WAON power domain configuration                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_HsioWaonConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_HSIO_WAON_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_HSIO_WAON_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_HSIO_WAON_CONFIG_FUNC();
    }
#endif

    /* Restore PLL context */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        if (s_pllContextValidHsio)
        {
            /*
             * Driver always returns true because a hard coded valid
             * PLL is used.
             */
            /* gcov_excl_ntbr_nextline */
            if (!FRACTPLL_SetContext(CLOCK_PLL_HSIO, &s_pllContextHsio))
            {
                status = SM_ERR_HARDWARE_ERROR; /* gcov_excl_line  */
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load M7_0 power domain configuration                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_M70ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_M7_0_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_M7_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_M7_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load M7_1 power domain configuration                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_M71ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_M7_1_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_M7_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_M7_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load NETC power domain configuration                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_NetcConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_NETC_CONFIG;

    /* Load TRDC E config */
    status = DEV_SM_RdcLoad(DEV_SM_TRDC_E);

    /* Load TRDC_S config */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_RdcLoad(DEV_SM_TRDC_S);
    }

    /* Load device config */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load(NULL, s_configData);
    }

#ifdef SM_NETC_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_NETC_CONFIG_FUNC();
    }
#endif

    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        /* Check if M33S CPUWAIT context was saved during NETCMIX power down */
        if (s_cpuWaitContextValidM33S)
        {
            /* Use SW wakeup to align M33S GPC with NETCMIX power state */
            (void) CPU_SwWakeup(CPU_IDX_M33P_S);

            /* Restore M33S CPUWAIT context */
            (void) CPU_WaitSet(CPU_IDX_M33P_S, s_cpuWaitContextM33S);
            s_cpuWaitContextValidM33S = false;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load NOC power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_NocConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_NOC_CONFIG;
    static const uint32_t s_blkData[] = SM_BCTRL_N_CONFIG;
    static const uint32_t s_timeoutData[] =
    {
        SM_CFG_FN(0x000000c0U, 10U), 0x7U,
        SM_CFG_FN(0x000000c0U, 10U), 0x8007U,
        SM_CFG_END
    };

    /* Load TRDC N config */
    status = DEV_SM_RdcLoad(DEV_SM_TRDC_N);

    /* Load NOC block control config */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load((const uint32_t*) BLK_CTRL_NOCMIX_BASE,
            s_blkData);
    }

    /* Load device config */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load(NULL, s_configData);
    }

    /* Initialize the NIU timeout registers to maximum value. */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load((const uint32_t*) BLK_CTRL_NOCMIX_BASE,
            s_timeoutData);
    }

#ifdef SM_NOC_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_NOC_CONFIG_FUNC();
    }
#endif

    /* Path to configure A55 temp sensor dependends on NOC and WAKEUP MIXes */
    /*
     * It needs modifying the the boot sequence of mix power domains
     */
    /* gcov_excl_multiline 10 - Boot sequence dependent */
    if ((!s_tempSensorA55Enabled) &&
        (SRC_MixIsPwrReady(PWR_MIX_SLICE_IDX_A55P)) &&
        (SRC_MixIsPwrReady(PWR_MIX_SLICE_IDX_WAKEUP)))
    {
        /* Power on temp sensor */
        if (DEV_SM_SensorConfigStart(DEV_SM_SENSOR_TEMP_A55, true)
            == SM_ERR_SUCCESS)
        {
            s_tempSensorA55Enabled = true;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load NPU power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_NpuConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_NPU_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_NPU_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_NPU_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load wakeup power domain configuration                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_WkupConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_WKUP_CONFIG;
    static const uint32_t s_blkData[] = SM_BCTRL_W_CONFIG;
    static const uint32_t s_timeoutData[] =
    {
        SM_CFG_FN(0x00000090U, 16U), 0x7U,
        SM_CFG_FN(0x00000090U, 16U), 0x8007U,
        SM_CFG_END
    };

    /* Load TRDC W config */
    status = DEV_SM_RdcLoad(DEV_SM_TRDC_W);

    /* Load TRDC X config */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_RdcLoad(DEV_SM_TRDC_X);
    }

    /* Load TRDC M config */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_RdcLoad(DEV_SM_TRDC_M);
    }

    /* Load WKUP block control config */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load((const uint32_t*) BLK_CTRL_WAKEUPMIX_BASE,
            s_blkData);
    }

    /* Load saved block control */
    BLK_CTRL_WAKEUPMIX->IOMUX_GPIO_CTRL_0 = wkupGpioCtrl0;
    BLK_CTRL_WAKEUPMIX->IOMUX_GPIO_CTRL_1 = wkupGpioCtrl1;

    /* Load device config */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load(NULL, s_configData);
    }

    /* Initialize the NIU timeout registers to maximum value. */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load((const uint32_t*) BLK_CTRL_WAKEUPMIX_BASE,
            s_timeoutData);
    }

#ifdef SM_WKUP_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_WKUP_CONFIG_FUNC();
    }
#endif

    /* Path to configure A55 temp sensor dependends on NOC and WAKEUP MIXes */
    /*
     * It needs modifying the the boot sequence of mix power domains
     */
    /* gcov_excl_multiline 10 - Boot sequence dependent */
    if ((!s_tempSensorA55Enabled) &&
        (SRC_MixIsPwrReady(PWR_MIX_SLICE_IDX_A55P)) &&
        (SRC_MixIsPwrReady(PWR_MIX_SLICE_IDX_NOC)))
    {
        /* Power on temp sensor */
        if (DEV_SM_SensorConfigStart(DEV_SM_SENSOR_TEMP_A55, true)
            == SM_ERR_SUCCESS)
        {
            s_tempSensorA55Enabled = true;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load ANA power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_AnaConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_ANA_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_ANA_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_ANA_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load AON power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_AonConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_AON_CONFIG;
    static const uint32_t s_blkData[] = SM_BCTRL_A_CONFIG;

    /* Load TRDC A config */
    status = DEV_SM_RdcLoad(DEV_SM_TRDC_A);

    /* Load AON NS block control config */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load((const uint32_t*) BLK_CTRL_NS_AONMIX_BASE,
            s_blkData);
    }

    /* Load device config */
    /* gcov_excl_ntbr_nextline - configtool enforces */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load(NULL, s_configData);
    }

#ifdef SM_AON_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_AON_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load BBSM power domain configuration                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbsmConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_BBSM_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_BBSM_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_BBSM_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load CCMSRCGPC power domain configuration                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CcmsrcgpcConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_CCMSRCGPC_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_CCMSRCGPC_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_CCMSRCGPC_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* A55P power domain power down configuration                               */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_A55pPowerDownPre(void)
{
    int32_t status;

    /* Reflect that A55 temp sensor is going down */
    s_tempSensorA55Enabled = false;

    /* Disable sensor */
    (void) DEV_SM_SensorPowerDown(DEV_SM_SENSOR_TEMP_A55);

    /* Query A55 sleep mode target */
    uint32_t sleepMode = CPU_SLEEP_MODE_RUN;
    (void) CPU_SleepModeGet(CPU_IDX_A55P, &sleepMode);

    /* Save A55 power down context based on sleep mode target */
    switch (sleepMode)
    {
        case CPU_SLEEP_MODE_WAIT:
            status = DEV_SM_PerfLevelGet(DEV_SM_PERF_A55,
                &s_mixPdnContext55.perfLevel);

            if (status == SM_ERR_SUCCESS)
            {
                /* WAIT mode updates A55 clocking context */
                status = DEV_SM_PerfFreqSet(DEV_SM_PERF_A55,
                    DEV_SM_PERF_LVL_PRK);

                /* Performance context restored if not already parked */
                if ((status == SM_ERR_SUCCESS) &&
                    (s_mixPdnContext55.perfLevel != DEV_SM_PERF_LVL_PRK))
                {
                    /* Restore A55 clocking during resume */
                    s_mixPdnContext55.freqUpdate = true;
                    s_mixPdnContext55.valid = true;
                }
            }
            break;

        case CPU_SLEEP_MODE_STOP:
        case CPU_SLEEP_MODE_SUSPEND:
            status = DEV_SM_PerfLevelGet(DEV_SM_PERF_A55,
                &s_mixPdnContext55.perfLevel);

            if (status == SM_ERR_SUCCESS)
            {
                /* STOP/SUSPEND mode updates A55 performance level */
                status = DEV_SM_PerfLevelSet(DEV_SM_PERF_A55,
                    DEV_SM_PERF_LVL_PRK);

                /* Performance context restored if not already parked */
                if ((status == SM_ERR_SUCCESS) &&
                    (s_mixPdnContext55.perfLevel != DEV_SM_PERF_LVL_PRK))
                {
                    /* Restore performance level during resume */
                    s_mixPdnContext55.freqUpdate = false;
                    s_mixPdnContext55.valid = true;
                }
            }
            break;

        default:
            /* Move to parked performance level */
            status = DEV_SM_PerfLevelSet(DEV_SM_PERF_A55,
                DEV_SM_PERF_LVL_PRK);
            break;
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* DDR power domain power down configuration                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_DdrPowerDownPre(void)
{
    int32_t status;

    /*
     * Driver always returns true because a hard‑coded valid
     * PLL is used.
     */
    /* gcov_excl_ntbr_nextline */
    if (FRACTPLL_GetContext(CLOCK_PLL_DRAM, &s_pllContextDdr))
    {
        s_pllContextValidDdr = true;
        status = SM_ERR_SUCCESS;
    }
    else
    {
        /* gcov_excl_multiline 3 */
        s_pllContextValidDdr = false;
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Display power domain power down configuration                            */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_DisplayPowerDownPre(void)
{
    int32_t status;

    /*
     * Driver always returns true because a hard‑coded valid
     * PLL is used.
     */
    /* gcov_excl_ntbr_nextline */
    if (FRACTPLL_GetContext(CLOCK_PLL_LDB, &s_pllContextLdb))
    {
        s_pllContextValidLdb = true;
        status = SM_ERR_SUCCESS;
    }
    else
    {
        /* gcov_excl_multiline 3 */
        s_pllContextValidLdb = false;
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* HSIO TOP power domain power down configuration                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_HsioTopPowerDownPre(void)
{
    int32_t status;

    /*
     * Driver always returns true because a hard‑coded valid
     * PLL is used.
     */
    /* gcov_excl_ntbr_nextline */
    if (FRACTPLL_GetContext(CLOCK_PLL_HSIO, &s_pllContextHsio))
    {
        s_pllContextValidHsio = true;
        status = SM_ERR_SUCCESS;
    }
    else
    {
        /* gcov_excl_multiline 3 */
        s_pllContextValidHsio = false;
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Wakeup power domain power down configuration                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_WkupPowerDownPre(void)
{
    wkupGpioCtrl0 = BLK_CTRL_WAKEUPMIX->IOMUX_GPIO_CTRL_0;
    wkupGpioCtrl1 = BLK_CTRL_WAKEUPMIX->IOMUX_GPIO_CTRL_1;

    /* Return status */
    return SM_ERR_SUCCESS;
}

/*--------------------------------------------------------------------------*/
/* NETC power domain power down configuration                               */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_NetcPowerDownPre(void)
{
    /* Query M33S sleep mode target */
    uint32_t sleepMode = CPU_SLEEP_MODE_RUN;
    (void) CPU_SleepModeGet(CPU_IDX_M33P_S, &sleepMode);

    /* Save M33S CPUWAIT context based on sleep mode target */
    switch (sleepMode)
    {
        case CPU_SLEEP_MODE_STOP:
        case CPU_SLEEP_MODE_SUSPEND:
            if (CPU_WaitGet(CPU_IDX_M33P_S, &s_cpuWaitContextM33S))
            {
                s_cpuWaitContextValidM33S = true;
                (void) CPU_WaitSet(CPU_IDX_M33P_S, true);
            }
            break;

        default:
            ; /* Intentional empty default */
            break;
    }

    /* Return status */
    return SM_ERR_SUCCESS;
}

