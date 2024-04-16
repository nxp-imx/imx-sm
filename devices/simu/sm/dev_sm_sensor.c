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

/* Local defines */

/* Local types */

/* Local variables */

static bool sensorEnb[DEV_SM_NUM_SENSOR];
static bool tsEnb[DEV_SM_NUM_SENSOR];

static uint32_t s_sensorId = 0U;
static uint8_t s_eventControl = 0U;

/*--------------------------------------------------------------------------*/
/* Initialize sensors                                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorInit(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Power up sensor                                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SensorConfigStart(uint32_t sensorId)
{
    int32_t status = SM_ERR_SUCCESS;

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
        [DEV_SM_SENSOR_0] = "temp0",
        [DEV_SM_SENSOR_1] = "temp1",
        [DEV_SM_SENSOR_2] = "temp2"
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
        desc->numTripPoints = 2U;
        desc->timestampSupport = false;
        desc->timestampExponent = 0;

        if(sensorId == DEV_SM_SENSOR_1)
        {
            desc->timestampSupport = true;
            desc->timestampExponent = -3;
        }
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
    int16_t raw0 = (int16_t) 0x0650;
    int16_t raw1 = (int16_t) 0xF9B0;

    /* Check domain */
    if (sensorId >= DEV_SM_NUM_SENSOR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Check if enabled */
        if (sensorEnb[sensorId])
        {
            if (sensorId == DEV_SM_SENSOR_0)
            {
                *sensorValue = (((int64_t) raw0) * 100LL) / 64LL;
            }
            else if (sensorId == DEV_SM_SENSOR_1)
            {
                *sensorValue = (((int64_t) raw1) * 100LL) / 64LL;
            }
            else
            {
                *sensorValue = 2530LL;
            }

            /* No timestamp support */
            *sensorTimestamp = 0ULL;
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
        /* Check if enabled */
        if (sensorEnb[sensorId])
        {
            s_eventControl = eventControl;
            s_sensorId = sensorId;
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
            if(sensorId != DEV_SM_SENSOR_1)
            {
                status = SM_ERR_NOT_SUPPORTED;
            }
            else
            {
                tsEnb[sensorId] = timestampReporting;
            }
        }

        if(status == SM_ERR_SUCCESS)
        {
            /* Record sensor enable */
            sensorEnb[sensorId] = enable;
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
        /* Return sensor enable */
        *enabled = sensorEnb[sensorId];
        *timestampReporting = tsEnb[sensorId];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Tick handler (one second)                                                */
/*--------------------------------------------------------------------------*/
void DEV_SM_SensorHandler(uint32_t idx, uint8_t threshold)
{

    static bool s_sensor = false;

    s_sensor = !s_sensor;
    if(s_sensor)
    {
        if((s_eventControl == DEV_SM_SENSOR_TP_BOTH)
            || (s_eventControl == DEV_SM_SENSOR_TP_RISING))
        {
            LMM_SensorEvent(s_sensorId, 0U, 1U);
        }
    }
    else
    {
        if((s_eventControl == DEV_SM_SENSOR_TP_BOTH)
            || (s_eventControl == DEV_SM_SENSOR_TP_FALLING))
        {
            LMM_SensorEvent(s_sensorId, 0U, 0U);
        }
    }
}

