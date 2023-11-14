/*
** ###################################################################
**
** Copyright 2023 NXP
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** o Redistributions of source code must retain the above copyright notice, this list
**   of conditions and the following disclaimer.
**
** o Redistributions in binary form must reproduce the above copyright notice, this
**   list of conditions and the following disclaimer in the documentation and/or
**   other materials provided with the distribution.
**
** o Neither the name of the copyright holder nor the names of its
**   contributors may be used to endorse or promote products derived from this
**   software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
** ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
** ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/* File containing the implementation of the board sensors.                 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "brd_sm.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

static bool sensorEnb[BRD_SM_NUM_SENSOR];

/*--------------------------------------------------------------------------*/
/* Return sensor name                                                       */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SensorNameGet(uint32_t sensorId, string *sensorNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[BRD_SM_NUM_SENSOR] =
    {
        "TEMP_PF09",
        "TEMP_PF53_SOC",
        "TEMP_PF53_ARM"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, BRD_SM_NUM_SENSOR);

    /* Check to see if sensorId is within bounds*/
    if(sensorId < SM_NUM_SENSOR)
    {
        /* Check if device or board */
        if (sensorId < DEV_SM_NUM_SENSOR)
        {
            status = DEV_SM_SensorNameGet(sensorId, sensorNameAddr, len);
        }
        else
        {
            uint32_t brdSensorId = sensorId - DEV_SM_NUM_SENSOR;

            /* Return pointer to name */
            *sensorNameAddr = s_name[brdSensorId];
        }
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return sensor description                                                */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SensorDescribe(uint32_t sensorId,
    dev_sm_sensor_desc_t *desc)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check to see if sensorId is within bounds*/
    if(sensorId < SM_NUM_SENSOR)
    {
        /* Check if device or board */
        if (sensorId < DEV_SM_NUM_SENSOR)
        {
            status = DEV_SM_SensorDescribe(sensorId, desc);
        }
        else
        {
            desc->sensorType = 2U;
            desc->sensorExponent = 0;
            desc->numTripPoints = 0U;
            desc->timestampSupport = false;
            desc->timestampExponent = 0;

            /* PF09? */
            if (sensorId == BRD_SM_SENSOR_TEMP_PF09)
            {
                desc->numTripPoints = 1U;
            }
        }
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get sensor reading                                                       */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SensorReadingGet(uint32_t sensorId, int64_t *sensorValue,
    uint64_t *sensorTimestamp)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check to see if sensorId is within bounds*/
    if(sensorId < SM_NUM_SENSOR)
    {
        /* Check if device or board */
        if (sensorId < DEV_SM_NUM_SENSOR)
        {
            status = DEV_SM_SensorReadingGet(sensorId, sensorValue,
                sensorTimestamp);
        }
        else
        {
            uint32_t brdSensorId = sensorId - DEV_SM_NUM_SENSOR;

            /* Check if enabled */
            if (sensorEnb[brdSensorId])
            {
                int32_t temp;
                bool rc = false;

                /* Read sensor */
                switch (sensorId)
                {
                    case BRD_SM_SENSOR_TEMP_PF09:
                        rc = PF09_TempGet(&pf09Dev, &temp);
                        break;
                    case BRD_SM_SENSOR_TEMP_PF5301:
                        rc = PF53_TempGet(&pf5301Dev, &temp);
                        break;
                    default:
                        rc = PF53_TempGet(&pf5302Dev, &temp);
                        break;
                }

                if (rc)
                {
                    *sensorValue = (int64_t) temp;
                    *sensorTimestamp = 0ULL;
                }
                else
                {
                    status = SM_ERR_HARDWARE_ERROR;
                }
            }
            else
            {
                status = SM_ERR_NOT_SUPPORTED;
            }
        }
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set sensor trippoint                                                     */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SensorTripPointSet(uint32_t sensorId, uint8_t tripPoint,
    int64_t value, uint8_t eventControl)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check to see if sensorId is within bounds*/
    if(sensorId < SM_NUM_SENSOR)
    {
        /* Check if device or board */
        if (sensorId < DEV_SM_NUM_SENSOR)
        {
            status = DEV_SM_SensorTripPointSet(sensorId, tripPoint,
                value, eventControl);
        }
        else
        {
            uint32_t brdSensorId = sensorId - DEV_SM_NUM_SENSOR;

            /* Check if enabled */
            if ((sensorId == BRD_SM_SENSOR_TEMP_PF09)
                && sensorEnb[brdSensorId])
            {
                /* Check trip point */
                if (tripPoint == 0U)
                {
                    if (eventControl == DEV_SM_SENSOR_TP_NONE)
                    {
                        if (!PF09_TempAlarmSet(&pf09Dev, 500))
                        {
                            status = SM_ERR_HARDWARE_ERROR;
                        }
                    }
                    else if (eventControl == DEV_SM_SENSOR_TP_RISING)
                    {
                        int32_t temp = (int32_t) value;

                        if (!PF09_TempAlarmSet(&pf09Dev, temp))
                        {
                            status = SM_ERR_HARDWARE_ERROR;
                        }
                    }
                    else
                    {
                        status = SM_ERR_INVALID_PARAMETERS;
                    }
                }
                else
                {
                    status = SM_ERR_INVALID_PARAMETERS;
                }
            }
            else
            {
                status = SM_ERR_NOT_SUPPORTED;
            }
        }
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable sensor                                                    */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SensorEnable(uint32_t sensorId, bool enable,
    bool timestampReporting)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check to see if sensorId is within bounds*/
    if(sensorId < SM_NUM_SENSOR)
    {
        /* Check if device or board */
        if (sensorId < DEV_SM_NUM_SENSOR)
        {
            status = DEV_SM_SensorEnable(sensorId, enable,
                timestampReporting);
        }
        else
        {
            uint32_t brdSensorId = sensorId - DEV_SM_NUM_SENSOR;

            /* Timestamp not supported */
            if (timestampReporting)
            {
                status = SM_ERR_NOT_SUPPORTED;
            }
            else
            {
                /* Record sensor enable */
                sensorEnb[brdSensorId] = enable;

                /* Disable alarm */
                if ((sensorId == BRD_SM_SENSOR_TEMP_PF09)
                    && !sensorEnb[brdSensorId])
                {
                    if (!PF09_TempAlarmSet(&pf09Dev, 500))
                    {
                        status = SM_ERR_HARDWARE_ERROR;
                    }
                }
            }
        }
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return sensor enable status                                              */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SensorIsEnabled(uint32_t sensorId, bool *enabled,
    bool *timestampReporting)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check to see if sensorId is within bounds*/
    if(sensorId < SM_NUM_SENSOR)
    {
        uint32_t brdSensorId = sensorId - DEV_SM_NUM_SENSOR;

        /* Check if device or board */
        if (sensorId < DEV_SM_NUM_SENSOR)
        {
            status = DEV_SM_SensorIsEnabled(sensorId, enabled,
                timestampReporting);
        }
        else
        {
            /* Return sensor enable */
            *enabled = sensorEnb[brdSensorId];
            *timestampReporting = false;
        }
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* PMIC sensor handler                                                      */
/*--------------------------------------------------------------------------*/
void BRD_SM_SensorHandler(void)
{
    /* Send sensor event */
    LMM_SensorEvent(BRD_SM_SENSOR_TEMP_PF09, 0U, 1U);
}

