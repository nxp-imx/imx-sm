/*
** ###################################################################
**
**     Copyright 2023-2024 NXP
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

/* Local variables */

static bool s_tempSensorA55Enabled = false;
static fracpll_context_t s_pllContextHsio;
static fracpll_context_t s_pllContextLdb;
static fracpll_context_t s_pllContextDdr;
static bool s_pllContextValidHsio = false;
static bool s_pllContextValidLdb = false;
static bool s_pllContextValidDdr = false;

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Load camera power domain configuration                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CameraConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_CAMERA_CONFIG;

    /* Load TRDC C config */
    status = DEV_SM_RdcLoad(DEV_SM_TRDC_C);

    /* Load device config */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load(NULL, s_configData);
    }

#ifdef SM_CAMERA_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_CAMERA_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

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
        if (DEV_SM_SensorPowerUp(DEV_SM_SENSOR_TEMP_A55) == SM_ERR_SUCCESS)
        {
            s_tempSensorA55Enabled = true;
        }
    }

    /* Process perpheral low-power interfaces */
    (void) CPU_PerLpiProcess(DEV_SM_CPU_A55P, CPU_SLEEP_MODE_RUN);

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load A55C0 power domain configuration                                    */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_A55c0ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_A55C0_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_A55C0_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_A55C0_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load A55C1 power domain configuration                                    */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_A55c1ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_A55C1_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_A55C1_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_A55C1_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load A55C2 power domain configuration                                    */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_A55c2ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_A55C2_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_A55C2_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_A55C2_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load A55C3 power domain configuration                                    */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_A55c3ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_A55C3_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_A55C3_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_A55C3_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load A55C4 power domain configuration                                    */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_A55c4ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_A55C4_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_A55C4_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_A55C4_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load A55C5 power domain configuration                                    */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_A55c5ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_A55C5_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_A55C5_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_A55C5_CONFIG_FUNC();
    }
#endif

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
    if (status == SM_ERR_SUCCESS)
    {
        if (s_pllContextValidDdr)
        {
            if (!FRACTPLL_SetContext(CLOCK_PLL_DRAM, &s_pllContextDdr))
            {
                status = SM_ERR_HARDWARE_ERROR;
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
    if (status == SM_ERR_SUCCESS)
    {
        if (s_pllContextValidLdb)
        {
            if (!FRACTPLL_SetContext(CLOCK_PLL_LDB, &s_pllContextLdb))
            {
                status = SM_ERR_HARDWARE_ERROR;
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load GPU power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_GpuConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_GPU_CONFIG;

    /* Load TRDC G config */
    status = DEV_SM_RdcLoad(DEV_SM_TRDC_G);

    /* Load device config */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load(NULL, s_configData);
    }

#ifdef SM_GPU_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_GPU_CONFIG_FUNC();
    }
#endif

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

    /* Restore PLL context */
    if (status == SM_ERR_SUCCESS)
    {
        if (s_pllContextValidHsio)
        {
            if (!FRACTPLL_SetContext(CLOCK_PLL_HSIO, &s_pllContextHsio))
            {
                status = SM_ERR_HARDWARE_ERROR;
            }
        }
    }

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

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load M7 power domain configuration                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_M7ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_M7_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_M7_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_M7_CONFIG_FUNC();
    }
#endif

    /* Process perpheral low-power interfaces */
    (void) CPU_PerLpiProcess(DEV_SM_CPU_M7P, CPU_SLEEP_MODE_RUN);

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

    /* Load device config */
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

    /* Load TRDC N config */
    status = DEV_SM_RdcLoad(DEV_SM_TRDC_N);

    /* Load device config */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load(NULL, s_configData);
    }

#if (defined(FSL_FEATURE_BLK_CTRL_NOC_HAS_ERRATA_52127) && FSL_FEATURE_BLK_CTRL_NOC_HAS_ERRATA_52127)
    /* Issue read access to force sync of default values */
    BLK_CTRL_NOCMIX->TIE_VALUE;
#endif

#ifdef SM_NOC_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_NOC_CONFIG_FUNC();
    }
#endif

    /* Path to configure A55 temp sensor dependends on NOC and WAKEUP MIXes */
    if ((!s_tempSensorA55Enabled) &&
        (SRC_MixIsPwrReady(PWR_MIX_SLICE_IDX_A55P)) &&
        (SRC_MixIsPwrReady(PWR_MIX_SLICE_IDX_WAKEUP)))
    {
        /* Power on temp sensor */
        if (DEV_SM_SensorPowerUp(DEV_SM_SENSOR_TEMP_A55) == SM_ERR_SUCCESS)
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
/* Load VPU power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_VpuConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_VPU_CONFIG;

    /* Load TRDC V config */
    status = DEV_SM_RdcLoad(DEV_SM_TRDC_V);

    /* Load device config */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load(NULL, s_configData);
    }

#ifdef SM_VPU_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_VPU_CONFIG_FUNC();
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

    /* Load TRDC W config */
    status = DEV_SM_RdcLoad(DEV_SM_TRDC_W);

    /* Load TRDC M config */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_RdcLoad(DEV_SM_TRDC_M);
    }

    /* Load WKUP block control config */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load((const uint32_t*) BLK_CTRL_WAKEUPMIX_BASE,
            s_blkData);
    }

    /* Load device config */
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load(NULL, s_configData);
    }

#ifdef SM_WKUP_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_WKUP_CONFIG_FUNC();
    }
#endif

    /* Path to configure A55 temp sensor dependends on NOC and WAKEUP MIXes */
    if ((!s_tempSensorA55Enabled) &&
        (SRC_MixIsPwrReady(PWR_MIX_SLICE_IDX_A55P)) &&
        (SRC_MixIsPwrReady(PWR_MIX_SLICE_IDX_NOC)))
    {
        /* Power on temp sensor */
        if (DEV_SM_SensorPowerUp(DEV_SM_SENSOR_TEMP_A55) == SM_ERR_SUCCESS)
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
    if (status == SM_ERR_SUCCESS)
    {
        status = CONFIG_Load((const uint32_t*) BLK_CTRL_NS_AONMIX_BASE,
            s_blkData);
    }

    /* Load device config */
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
    /* Reflect that A55 temp sensor is going down */
    s_tempSensorA55Enabled = false;

    /* Process perpheral low-power interfaces */
    uint32_t sleepMode;
    if (CPU_SleepModeGet(DEV_SM_CPU_A55P, &sleepMode))
    {
        (void) CPU_PerLpiProcess(DEV_SM_CPU_A55P, sleepMode);
    }

    /* Move A55 perf level to a setpoint that does not require ARM_PLL */
    return DEV_SM_PerfLevelSet(DEV_SM_PERF_A55, DEV_SM_PERF_LVL_PRK);
}

/*--------------------------------------------------------------------------*/
/* DDR power domain power down configuration                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_DdrPowerDownPre(void)
{
    int32_t status;

    if (FRACTPLL_GetContext(CLOCK_PLL_DRAM, &s_pllContextDdr))
    {
        s_pllContextValidDdr = true;
        status = SM_ERR_SUCCESS;
    }
    else
    {
        s_pllContextValidDdr = false;
        status = SM_ERR_HARDWARE_ERROR;
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Display power domain power down configuration                            */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_DisplayPowerDownPre(void)
{
    int32_t status;

    if (FRACTPLL_GetContext(CLOCK_PLL_LDB, &s_pllContextLdb))
    {
        s_pllContextValidLdb = true;
        status = SM_ERR_SUCCESS;
    }
    else
    {
        s_pllContextValidLdb = false;
        status = SM_ERR_HARDWARE_ERROR;
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* HSIO TOP power domain power down configuration                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_HsioTopPowerDownPre(void)
{
    int32_t status;

    if (FRACTPLL_GetContext(CLOCK_PLL_HSIO, &s_pllContextHsio))
    {
        s_pllContextValidHsio = true;
        status = SM_ERR_SUCCESS;
    }
    else
    {
        s_pllContextValidHsio = false;
        status = SM_ERR_HARDWARE_ERROR;
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* M7 power domain power down configuration                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_M7PowerDownPre(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Process perpheral low-power interfaces */
    uint32_t sleepMode;
    if (CPU_SleepModeGet(DEV_SM_CPU_M7P, &sleepMode))
    {
        (void) CPU_PerLpiProcess(DEV_SM_CPU_M7P, sleepMode);
    }

    return status;
}

