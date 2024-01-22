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
/* File containing the implementation of the device sensors.                */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "lmm.h"
#include "fsl_tmpsns.h"

/* Local defines */

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
    uint16_t fuseTrim1;      /* Fuse word for trim 1 */
    uint16_t fuseTrim2;      /* Fuse word for trim 1 */
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
        .fuseTrim1 = FSB_FUSE_ANA_CFG0,
        .fuseTrim2 = FSB_FUSE_ANA_CFG1
    },
    [DEV_SM_SENSOR_TEMP_A55] =
    {
        .idx = 1U,
        .pd = PWR_MIX_SLICE_IDX_A55P,
        .numThresholds = 2U,
        .firstThreshold = 1U,
        .panicThreshold = 0U,
        .fuseTrim1 = FSB_FUSE_ANA_CFG2,
        .fuseTrim2 = FSB_FUSE_ANA_CFG3
    }
};

/* Panic temps */
static const int64_t s_panicTemp[4] =
{
    9700,   /* 00 - Consumer 0C to 95C */
    10700,  /* 01 - Ext. Consumer -20C to 105C */
    10700,  /* 10 - Industrial -40C to 105C */
    12700   /* 11 - Automotive -40C to 125C */
};

static TMPSNS_Type *const s_tmpsnsBases[] = TMPSNS_BASE_PTRS;
static bool s_tmpsnsEnb[DEV_SM_NUM_SENSOR];
static uint8_t s_tmpsnsDir[DEV_SM_NUM_SENSOR];

/* Local functions */

static int32_t TMPSNS_ThresholdSet(uint32_t sensorId, uint8_t threshold,
    int64_t value, uint8_t eventControl);

/*--------------------------------------------------------------------------*/
/* Initialize sensors                                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorInit(void)
{
    int32_t status;
    uint32_t sensorId = DEV_SM_SENSOR_TEMP_ANA;
    TMPSNS_Type *base = s_tmpsnsBases[s_tmpsns[sensorId].idx];
    tmpsns_config_t config;
    uint32_t hwCfg0 = FSB->FUSE[FSB_FUSE_HW_CFG0];
    uint32_t mktSeg;

    /* Get default confg */
    TMPSNS_GetDefaultConfig(&config);
    config.measMode = 1U;

    /* Apply trim */
    if (FSB->FUSE[s_tmpsns[sensorId].fuseTrim1] != 0U)
    {
        config.trim1 = FSB->FUSE[s_tmpsns[sensorId].fuseTrim1];
        config.trim2 = FSB->FUSE[s_tmpsns[sensorId].fuseTrim2];
    }

    /* Init sensor */
    TMPSNS_Init(base, &config);

    /* Configure ANA panic */
    mktSeg = (hwCfg0 & FSB_FUSE_HW_CFG0_MARKET_SEGMENT_MASK)
        >> FSB_FUSE_HW_CFG0_MARKET_SEGMENT_SHIFT;
    status = TMPSNS_ThresholdSet(sensorId,
        s_tmpsns[sensorId].panicThreshold, s_panicTemp[mktSeg],
        DEV_SM_SENSOR_TP_HIGH);

    /* Enable interrupts */
    NVIC_EnableIRQ(TMPSNS_ANA_1_IRQn);
    NVIC_EnableIRQ(TMPSNS_ANA_2_IRQn);
    NVIC_EnableIRQ(TMPSNS_CORTEXA_1_IRQ);
    NVIC_EnableIRQ(TMPSNS_CORTEXA_2_IRQ);

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Power up sensor                                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorPowerUp(uint32_t sensorId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check domain */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        TMPSNS_Type *base = s_tmpsnsBases[s_tmpsns[sensorId].idx];
        tmpsns_config_t config;
        uint32_t hwCfg0 = FSB->FUSE[FSB_FUSE_HW_CFG0];
        uint32_t mktSeg;

        /* Get default confg */
        TMPSNS_GetDefaultConfig(&config);

        /* Config for periodic one-shot */
        config.measMode = 1U;

        /* Apply trim */
        if (FSB->FUSE[s_tmpsns[sensorId].fuseTrim1] != 0U)
        {
            config.trim1 = FSB->FUSE[s_tmpsns[sensorId].fuseTrim1];
            config.trim2 = FSB->FUSE[s_tmpsns[sensorId].fuseTrim2];
        }

        /* Init sensor */
        TMPSNS_Init(base, &config);

        /* Configure panic */
        mktSeg = (hwCfg0 & FSB_FUSE_HW_CFG0_MARKET_SEGMENT_MASK)
            >> FSB_FUSE_HW_CFG0_MARKET_SEGMENT_SHIFT;
        status = TMPSNS_ThresholdSet(sensorId,
            s_tmpsns[sensorId].panicThreshold, s_panicTemp[mktSeg],
            DEV_SM_SENSOR_TP_HIGH);
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

    /* Check domain */
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

    /* Check domain */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Check if PD is on */
        if (!SRC_MixIsPwrSwitchOn(s_tmpsns[sensorId].pd))
        {
            s_tmpsnsEnb[sensorId] = false;
        }

        /* Check if enabled */
        if (s_tmpsnsEnb[sensorId])
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

    /* Check domain */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Check if PD is on */
        if (!SRC_MixIsPwrSwitchOn(s_tmpsns[sensorId].pd))
        {
            s_tmpsnsEnb[sensorId] = false;
        }

        /* Check if enabled */
        if (s_tmpsnsEnb[sensorId])
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
                TMPSNS_ThresholdSet(sensorId, threshold, value,
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

    /* Check domain */
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
            if (SRC_MixIsPwrSwitchOn(s_tmpsns[sensorId].pd))
            {
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

    /* Check domain */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Check if PD is on */
        if (!SRC_MixIsPwrSwitchOn(s_tmpsns[sensorId].pd))
        {
            s_tmpsnsEnb[sensorId] = false;
        }

        /* Return sensor enable */
        *enabled = s_tmpsnsEnb[sensorId];
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
    uint8_t tripPoint = threshold - s_tmpsns[idx].firstThreshold;

    /* Workaround ERR052128 */
    SystemTimeDelay(1U);

    /* Clear interrupt */
    TMPSNS_ClearStatusFlags(base, ((uint32_t) kTMPSNS_Thr0If)
            << threshold);

    /* Send sensor event */
    LMM_SensorEvent(idx, tripPoint, s_tmpsnsDir[idx]);
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Set sensor threshold                                                     */
/*--------------------------------------------------------------------------*/
static int32_t TMPSNS_ThresholdSet(uint32_t sensorId, uint8_t threshold,
    int64_t value, uint8_t eventControl)
{
    int32_t status = SM_ERR_SUCCESS;
    int64_t raw64 = (value * 64) / 100;
    int16_t raw16 = (int16_t) raw64;
    TMPSNS_Type *base = s_tmpsnsBases[s_tmpsns[sensorId].idx];

    if (eventControl == DEV_SM_SENSOR_TP_NONE)
    {
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

            /* Enable interrupt */
            TMPSNS_EnableInterrupts(base, ((uint32_t) kTMPSNS_Thr0IE)
                    << threshold);
        }
    }

    /* Return status */
    return status;
}

