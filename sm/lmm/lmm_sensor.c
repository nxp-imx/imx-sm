/*
** ###################################################################
**
** Copyright 2023-2026 NXP
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
/* File containing the implementation of the Logical Machine Manager        */
/* sensors.                                                                 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Sensor owner info */
typedef struct
{
    uint32_t lmId;
    uint32_t tp;
} sensor_owner_t;

/* Local variables */

static bool s_sensorState[SM_NUM_SENSOR][SM_NUM_LM];
static sensor_owner_t s_sensorOwner[SM_NUM_SENSOR];

/*--------------------------------------------------------------------------*/
/* Return sensor name                                                       */
/*--------------------------------------------------------------------------*/
int32_t LMM_SensorNameGet(uint32_t lmId, uint32_t sensorId,
    string *sensorNameAddr, int32_t *len)
{
    /* Just passthru to board/device */
    /*
     * False Positive: The sensorId value of zero is associated with the
     * device layer function. Its handling is correctly implemented within
     * the underrun end function (BRD_SM_SensorNameGet), ensuring
     * appropriate processing of sensorId value zero.
     */
    /* coverity[cert_arr30_c_violation:FALSE] */
    /* coverity[cert_str31_c_violation:FALSE] */
    return SM_SENSORNAMEGET(sensorId, sensorNameAddr, len);
}

/*--------------------------------------------------------------------------*/
/* Return sensor description                                                */
/*--------------------------------------------------------------------------*/
int32_t LMM_SensorDescribe(uint32_t lmId, uint32_t sensorId,
    dev_sm_sensor_desc_t *desc)
{
    /* Just passthru to board/device */
    return SM_SENSORDESCRIBE(sensorId, desc);
}

/*--------------------------------------------------------------------------*/
/* Get sensor reading                                                       */
/*--------------------------------------------------------------------------*/
int32_t LMM_SensorReadingGet(uint32_t lmId, uint32_t sensorId,
    int64_t *sensorValue, uint64_t *sensorTimestamp)
{
    int32_t status = SM_ERR_NOT_SUPPORTED;

    /* Check sensorId and lmId are within allowed range  */
    if ((sensorId < SM_NUM_SENSOR) && (lmId < SM_NUM_LM))
    {
        /* Sensor is enabled ? */
        if (s_sensorState[sensorId][lmId])
        {
            /*
             * False Positive: The sensorId value of zero is associated with
             * the device layer function. Its handling is correctly implemented
             * within the underrun end function (BRD_SM_SensorReadingGet),
             * ensuring appropriate processing of sensorId value zero.
             */
            /* coverity[cert_arr30_c_violation:FALSE] */
            /* coverity[cert_str31_c_violation:FALSE] */
            status = SM_SENSORREADINGGET(sensorId, sensorValue,
                sensorTimestamp);
        }
    }
    else
    {
        /* Set the status if out of range */
        status = SM_ERR_NOT_FOUND;
    }

    /* Return Status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set sensor trippoint                                                     */
/*--------------------------------------------------------------------------*/
int32_t LMM_SensorTripPointSet(uint32_t lmId, uint32_t sensorId,
    uint8_t tripPoint, int64_t value, uint8_t eventControl)
{
    int32_t status = SM_ERR_NOT_SUPPORTED;

    /* Check sensorId and lmId are within allowed range  */
    if ((sensorId < SM_NUM_SENSOR) && (lmId < SM_NUM_LM))
    {
        /* Sensor is enabled ? */
        if (s_sensorState[sensorId][lmId])
        {
            /*
             * False Positive: The sensorId value of zero is associated with
             * the device layer function. Its handling is correctly implemented
             * within the underrun end function (BRD_SM_SensorTripPointSet),
             * ensuring appropriate processing of sensorId value zero.
             */
            /* coverity[cert_arr30_c_violation:FALSE] */
            /* coverity[cert_str31_c_violation:FALSE] */
            status = SM_SENSORTRIPPOINTSET(sensorId, tripPoint, value,
                eventControl);
        }

        if ((status == SM_ERR_SUCCESS)
            && (eventControl != DEV_SM_SENSOR_TP_NONE))
        {
            /* Record the sensor owner */
            s_sensorOwner[sensorId].lmId = lmId;
            s_sensorOwner[sensorId].tp |= (uint32_t)(1UL << tripPoint);
        }
    }
    else
    {
        /* Set the status if out of range */
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable sensor                                                    */
/*--------------------------------------------------------------------------*/
int32_t LMM_SensorEnable(uint32_t lmId, uint32_t sensorId, bool enable,
    bool timestampReporting)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check parameters */
    if (lmId >= SM_NUM_LM)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Check parameters */
    if ((status == SM_ERR_SUCCESS) && (sensorId >= SM_NUM_SENSOR))
    {
        status = SM_ERR_NOT_FOUND;
    }

    if (status == SM_ERR_SUCCESS)
    {
        bool newEnable = false;

        /* Record new state */
        s_sensorState[sensorId][lmId] = enable;

        if (!enable && (s_sensorOwner[sensorId].lmId == lmId))
        {
            uint32_t tp = s_sensorOwner[sensorId].tp;
            uint8_t count = 0U;
            int64_t tripPoint = 0;

            /* Loop over owner trip points */
            while (tp != 0U)
            {
                if ((tp & 1U) != 0U)
                {
                    /* Clear the theshold point */
                    (void)LMM_SensorTripPointSet(lmId, sensorId, count,
                        tripPoint, DEV_SM_SENSOR_TP_NONE);
                }

                /* Shift to next trip point */
                tp >>= 1U;

                /*
                 * False positive: The count value increments only up to
                 * a maximum of 32.
                 */
                /* coverity[cert_int31_c_violation] */
                /* coverity[cert_int30_c_violation] */
                count++;
            }
        }

        /* Aggregate sensor enable */
        for (uint32_t lm = 0U; lm < SM_NUM_LM; lm++)
        {
            if (s_sensorState[sensorId][lm])
            {
                newEnable = true;
            }
        }

        /* Inform device of sensor state, device will check if changed */
        /*
         * False Positive: The sensorId value of zero is associated with the
         * device layer function. Its handling is correctly implemented within
         * the underrun end function (BRD_SM_SensorEnable), ensuring
         * appropriate processing of sensorId value zero.
         */
        /* coverity[cert_arr30_c_violation:FALSE] */
        /* coverity[cert_str31_c_violation:FALSE] */
        status = SM_SENSORENABLE(sensorId, newEnable, timestampReporting);

        if (status != SM_ERR_SUCCESS)
        {
            /* Revert to previous sensor state in case of failure */
            s_sensorState[sensorId][lmId] = !enable;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return sensor enable status                                              */
/*------------------------------------------------------------------------*/
int32_t LMM_SensorIsEnabled(uint32_t lmId, uint32_t sensorId,
    bool *enabled, bool *timestampReporting)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check sensorId and lmId are within allowed range  */
    if ((sensorId < SM_NUM_SENSOR) && (lmId < SM_NUM_LM))
    {
        /* Sensor is enabled ? */
        if (s_sensorState[sensorId][lmId])
        {
            /*
             * False Positive: The sensorId value of zero is associated with
             * the device layer function. Its handling is correctly implemented
             * within the underrun end function (BRD_SM_SensorIsEnabled),
             * ensuring appropriate processing of sensorId value zero.
             */
            /* coverity[cert_arr30_c_violation:FALSE] */
            /* coverity[cert_str31_c_violation:FALSE] */
            status = SM_SENSORISENABLED(sensorId, enabled, timestampReporting);
        }
        else
        {
            *enabled = false;
            *timestampReporting = false;
        }
    }
    else
    {
        /* Set the status if out of range */
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Report sensor event                                                      */
/*--------------------------------------------------------------------------*/
void LMM_SensorEvent(uint32_t sensorId, uint8_t tripPoint, uint8_t dir)
{
    /* Dispatch for all LM */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        /* Partial init suported for this array */
        /* coverity[misra_c_2012_rule_9_3_violation] */
        lmm_rpc_trigger_t trigger =
        {
            .event = LMM_TRIGGER_SENSOR,
            .parm[0] = sensorId,
            .parm[1] = (uint32_t) tripPoint,
            .parm[2] = (uint32_t) dir
        };

        (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
    }
}

