/*
** ###################################################################
**
**     Copyright 2023-2026 NXP
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
/* File containing the implementation of the device sensors.                */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "lmm.h"
#include "fsl_tmpsns.h"

/* Local defines */

#define SM_NUM_THRESHOLDS  3U

/* Local types */

/* Device sensor map structure */
typedef struct
{
    bool secure;             /* Secure section of sensor */
    uint32_t pd;             /* power domain */
    uint8_t idx;             /* SDK base index */
    uint8_t numThresholds;   /* Number of thresholds */
    uint8_t firstThreshold;  /* First threshold */
    uint8_t panicThreshold;  /* Panic threshold */
    uint32_t fuseTrim1;      /* Fuse index for trim 1 */
    uint32_t fuseTrim2;      /* Fuse index for trim 2 */
} dev_sm_sensor_t;

/* Local variables */

/* Sensor configuration */
static const dev_sm_sensor_t s_tmpsns[DEV_SM_NUM_SENSOR] =
{
    [DEV_SM_SENSOR_TEMP_ANA] =
    {
        .idx = 0U,
        .pd = PWR_MIX_SLICE_IDX_ANA,
        .numThresholds = 2U,
        .firstThreshold = 1U,
        .panicThreshold = 0U,
        .fuseTrim1 = DEV_SM_FUSE_TSENSOR0_TRIM1,
        .fuseTrim2 = DEV_SM_FUSE_TSENSOR0_TRIM2
    },
    [DEV_SM_SENSOR_TEMP_A55] =
    {
        .idx = 1U,
        .pd = PWR_MIX_SLICE_IDX_A55P,
        .numThresholds = 2U,
        .firstThreshold = 1U,
        .panicThreshold = 0U,
        .fuseTrim1 = DEV_SM_FUSE_TSENSOR1_TRIM1,
        .fuseTrim2 = DEV_SM_FUSE_TSENSOR1_TRIM2
    }
};

static TMPSNS_Type *const s_tmpsnsBases[] = TMPSNS_BASE_PTRS;
static bool s_tmpsnsOwn[DEV_SM_NUM_SENSOR];
static bool s_tmpsnsEnb[DEV_SM_NUM_SENSOR];
static uint8_t s_tmpsnsDir[DEV_SM_NUM_SENSOR];
static uint32_t s_thresholdEnb[DEV_SM_NUM_SENSOR];
static int16_t s_thresholdVal[DEV_SM_NUM_SENSOR][SM_NUM_THRESHOLDS];
static uint8_t s_thresholdMode[DEV_SM_NUM_SENSOR][SM_NUM_THRESHOLDS];

/* Local functions */

static int32_t DEV_SM_SensorThresholdSet(uint32_t sensorId, uint8_t threshold,
    int64_t value, uint8_t eventControl);

/*--------------------------------------------------------------------------*/
/* Initialize sensors                                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorInit(void)
{
    int32_t status;

    /* Power on ANA sensor */
    status = DEV_SM_SensorConfigStart(DEV_SM_SENSOR_TEMP_ANA, false);

    /* Enable interrupts */
    NVIC_EnableIRQ(TMPSNS_ANA_1_IRQn);
    NVIC_EnableIRQ(TMPSNS_ANA_2_IRQn);
    NVIC_EnableIRQ(TMPSNS_CORTEXA_1_IRQ);
    NVIC_EnableIRQ(TMPSNS_CORTEXA_2_IRQ);

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure and start a sensor                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorConfigStart(uint32_t sensorId, bool secAccess)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check sensor */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        TMPSNS_Type *base = s_tmpsnsBases[s_tmpsns[sensorId].idx];
        tmpsns_config_t config;
        uint32_t mask = s_thresholdEnb[sensorId];

        /* Panic temps */
        const int64_t panicTemp[4] =
        {
            9700,   /* 00 - Commercial 0C to 95C */
            12700,  /* 01 - Ext. Industrial -40C to 125C */
            10700,  /* 10 - Industrial -40C to 105C */
            12700   /* 11 - Automotive -40C to 125C */
        };

        /* Get default confg */
        TMPSNS_GetDefaultConfig(&config);

        /* Config for periodic one-shot */
        config.measMode = 2U;
        config.measFreq = 100000U;
        config.pud = 236U;
        config.nFilt = 5U;

        /* Apply trim */
        uint32_t trim1 = DEV_SM_FuseGet(s_tmpsns[sensorId].fuseTrim1);
        if (trim1 != 0U)
        {
            config.trim1 = trim1;
            config.trim2 = DEV_SM_FuseGet(s_tmpsns[sensorId].fuseTrim2);
        }

        /* Check if ELE enabled */
        if (secAccess && !TMPSNS_Enabled(base))
        {
            /* Note we enabled */
            s_tmpsnsOwn[sensorId] = true;

            /* Init secure section of sensor */
            TMPSNS_Init(base, &config);
        }

        /* Init NS section of sensor */
        TMPSNS_InitNs(base, &config);

        /* Loop over thresholds */
        for (uint8_t threshold = 0U; threshold < SM_NUM_THRESHOLDS;
            threshold++)
        {
            if ((mask & BIT32(threshold)) != 0U)
            {
                /* Restore thresholds */
                TMPSNS_SetThreshold(base, threshold,
                    s_thresholdVal[sensorId][threshold],
                    s_thresholdMode[sensorId][threshold]);
            }
        }

        /* Configure panic */
        uint32_t mktSeg = DEV_SM_FuseGet(DEV_SM_FUSE_MARKET_SEGMENT);
        status = DEV_SM_SensorThresholdSet(sensorId,
            s_tmpsns[sensorId].panicThreshold, panicTemp[mktSeg],
            DEV_SM_SENSOR_TP_HIGH);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Power up a sensor                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorPowerUp(uint32_t sensorId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check sensor */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Do we own the secure section? */
        if (s_tmpsnsOwn[sensorId])
        {
            TMPSNS_Type *base = s_tmpsnsBases[s_tmpsns[sensorId].idx];

            /* Enable and start */
            TMPSNS_Enable(base);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Power down sensor                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorPowerDown(uint32_t sensorId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check sensor */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        TMPSNS_Type *base = s_tmpsnsBases[s_tmpsns[sensorId].idx];
        uint32_t mask = s_thresholdEnb[sensorId];

        /* Loop over thresholds */
        for (uint8_t threshold = 0U; threshold < SM_NUM_THRESHOLDS;
            threshold++)
        {
            if ((mask & BIT32(threshold)) != 0U)
            {
                /* Record the NS thresholds */
                TMPSNS_GetThreshold(base, threshold,
                    &s_thresholdVal[sensorId][threshold],
                    &s_thresholdMode[sensorId][threshold]);
            }
        }

        /* Do we own the secure section? */
        if (s_tmpsnsOwn[sensorId])
        {
            /* Stop and disable */
            TMPSNS_Deinit(base);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return sensor name                                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorNameGet(uint32_t sensorId, string *sensorNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_SENSOR] =
    {
        [DEV_SM_SENSOR_TEMP_ANA] = "temp_ana",
        [DEV_SM_SENSOR_TEMP_A55] = "temp_a55"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_SENSOR);

    /* Check sensor */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *sensorNameAddr = s_name[sensorId];
    }

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return sensor description                                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorDescribe(uint32_t sensorId,
    dev_sm_sensor_desc_t *desc)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check sensor */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        desc->sensorType = 2U;
        desc->sensorExponent = -2;
        desc->numTripPoints = s_tmpsns[sensorId].numThresholds;
        desc->timestampSupport = false;
        desc->timestampExponent = 0;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get sensor reading                                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorReadingGet(uint32_t sensorId, int64_t *sensorValue,
    uint64_t *sensorTimestamp)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check sensor */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Check if enabled and power on */
        if (s_tmpsnsEnb[sensorId]
            && SRC_MixIsPwrReady(s_tmpsns[sensorId].pd))
        {
            static int64_t s_tmpsnsValue[DEV_SM_NUM_SENSOR];
            static bool s_tmpsnsValid[DEV_SM_NUM_SENSOR];
            const TMPSNS_Type *base = s_tmpsnsBases[s_tmpsns[sensorId].idx];
            uint32_t flags = TMPSNS_GetStatusFlags(base);

            /* Update data if available */
            if ((flags & ((uint32_t) kTMPSNS_DRrdy1If)) != 0U)
            {
                int16_t raw;

                /* Read sensor */
                raw = TMPSNS_GetDataNonBlocking(base);

                /* Convert value */
                s_tmpsnsValue[sensorId] = (((int64_t) raw) * 100LL)
                    / 64LL;

                /* Note we have a value */
                s_tmpsnsValid[sensorId] = true;
            }

            /* Do we have a value to return? */
            if (s_tmpsnsValid[sensorId])
            {
                /* Return value */
                *sensorValue = s_tmpsnsValue[sensorId];

                /* No timestamp support */
                *sensorTimestamp = 0ULL;
            }
            else
            {
                status = SM_ERR_BUSY;
            }
        }
        else
        {
            status = SM_ERR_NOT_SUPPORTED;
        }
    }

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL2, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set sensor trippoint                                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorTripPointSet(uint32_t sensorId, uint8_t tripPoint,
    int64_t value, uint8_t eventControl)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check sensor */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Check if enabled and power on */
        if (s_tmpsnsEnb[sensorId]
            && SRC_MixIsPwrReady(s_tmpsns[sensorId].pd))
        {
            /* Check trip point */
            if (tripPoint >= (uint32_t) s_tmpsns[sensorId].numThresholds)
            {
                status = SM_ERR_INVALID_PARAMETERS;
            }
            else
            {
                uint8_t threshold = s_tmpsns[sensorId].firstThreshold
                    + (uint8_t) tripPoint;

                /* Configure sensor threshold */
                status = DEV_SM_SensorThresholdSet(sensorId, threshold, value,
                    eventControl);
            }
        }
        else
        {
            status = SM_ERR_NOT_SUPPORTED;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable sensor                                                    */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorEnable(uint32_t sensorId, bool enable,
    bool timestampReporting)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check sensor */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Timestamp not supported */
        if (timestampReporting)
        {
            status = SM_ERR_NOT_SUPPORTED;
        }
        else
        {
            /* Check if A55 power is on */
            if (SRC_MixIsPwrSwitchOn(s_tmpsns[sensorId].pd) || !enable)
            {
                /* Record sensor enable */
                s_tmpsnsEnb[sensorId] = enable;
            }
            else
            {
                status = SM_ERR_POWER;
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return sensor enable status                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorIsEnabled(uint32_t sensorId, bool *enabled,
    bool *timestampReporting)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check sensor */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return sensor enable */
        *enabled = s_tmpsnsEnb[sensorId]
            && SRC_MixIsPwrReady(s_tmpsns[sensorId].pd);
        *timestampReporting = false;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Common TMPSNS IRQ handler                                                */
/*--------------------------------------------------------------------------*/
void DEV_SM_SensorHandler(uint32_t idx, uint8_t threshold)
{
    TMPSNS_Type *base = s_tmpsnsBases[s_tmpsns[idx].idx];

    /* Check if PD is on */
    if (SRC_MixIsPwrReady(s_tmpsns[idx].pd))
    {
        /* Workaround ERR052128 */
        SystemTimeDelay(1U);

        /* Clear interrupt */
        TMPSNS_ClearStatusFlags(base, ((uint32_t) kTMPSNS_Thr0If)
                << threshold);

        /* Check trip point will not underflow */
        if (threshold >= s_tmpsns[idx].firstThreshold)
        {
            /* Send sensor event */
            LMM_SensorEvent(idx, threshold - s_tmpsns[idx].firstThreshold,
                s_tmpsnsDir[idx]);
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Sensor timer tick                                                        */
/*--------------------------------------------------------------------------*/
void DEV_SM_SensorTick(uint32_t msec)
{
    /* Loop over sensors */
    for (uint32_t sensorId = 0U; sensorId < DEV_SM_NUM_SENSOR; sensorId++)
    {
        /* Check if PD is on */
        if (SRC_MixIsPwrReady(s_tmpsns[sensorId].pd))
        {
            TMPSNS_Type *base = s_tmpsnsBases[s_tmpsns[sensorId].idx];
            uint32_t filt = TMPSNS_GetFilterBusy(base);
            uint32_t mask = s_thresholdEnb[sensorId] & ~filt;

            /* Loop over thresholds */
            for (uint8_t threshold = 0U; threshold < SM_NUM_THRESHOLDS;
                threshold++)
            {
                /* Threshold enabled and filter clear? */
                if ((mask & BIT32(threshold)) != 0U)
                {
                    /* Clear interrupt */
                    TMPSNS_ClearStatusFlags(base, ((uint32_t) kTMPSNS_Thr0If)
                            << threshold);

                    TMPSNS_EnableInterrupts(base, ((uint32_t) kTMPSNS_Thr0IE)
                            << threshold);
                }
            }
        }
    }
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Set sensor threshold                                                     */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_SensorThresholdSet(uint32_t sensorId, uint8_t threshold,
    int64_t value, uint8_t eventControl)
{
    int32_t status = SM_ERR_SUCCESS;
    int64_t raw64;
    TMPSNS_Type *base = s_tmpsnsBases[s_tmpsns[sensorId].idx];

    if ((value <= (INT64_MAX / 64)) && (value >= (INT64_MIN / 64)))
    {
        raw64 = (value * 64) / 100;
    }
    else
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Check raw64 fit in int16_t */
    if ((status == SM_ERR_SUCCESS) && (CHECK_I64_FIT_I16(raw64)))
    {
        int16_t raw16 = (int16_t) raw64;
        uint32_t mask = BIT32(threshold);

        if (eventControl == DEV_SM_SENSOR_TP_NONE)
        {
            s_thresholdEnb[sensorId] &= ~mask;

            /* Disable interrupt */
            TMPSNS_DisableInterrupts(base, ((uint32_t) kTMPSNS_Thr0IE)
                    << threshold);
        }
        else
        {
            uint8_t mode;

            /* Convert event control to mode */
            switch (eventControl)
            {
                case DEV_SM_SENSOR_TP_RISING:
                    mode = (uint8_t) kTMPSNS_ThrModeRisingEdge;
                    s_tmpsnsDir[sensorId] = 1U;
                    break;
                case DEV_SM_SENSOR_TP_FALLING:
                    mode = (uint8_t) kTMPSNS_ThrModeFallingEdge;
                    s_tmpsnsDir[sensorId] = 0U;
                    break;
                case DEV_SM_SENSOR_TP_HIGH:
                    mode = (uint8_t) kTMPSNS_ThrModeHigh;
                    s_tmpsnsDir[sensorId] = 1U;
                    break;
                case DEV_SM_SENSOR_TP_LOW:
                    mode = (uint8_t) kTMPSNS_ThrModeLow;
                    s_tmpsnsDir[sensorId] = 0U;
                    break;
                default:
                    status = SM_ERR_INVALID_PARAMETERS;
                    break;
            }

            /* Valid mode? */
            if (status == SM_ERR_SUCCESS)
            {
                /* Disable interrupt */
                TMPSNS_DisableInterrupts(base, ((uint32_t) kTMPSNS_Thr0IE)
                        << threshold);

                /* Configure sensor threshold */
                TMPSNS_SetThreshold(base, threshold, raw16, mode);

                /* Enable interrupt (delayed) */
                s_thresholdEnb[sensorId] |= mask;
            }
        }
    }
    else
    {
        /* Set the status if value is greater than int16_t max range */
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Return status */
    return status;
}

