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
/* File containing the implementation of the Logical Machine Manager        */
/* sensors.                                                                 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Return sensor name                                                       */
/*--------------------------------------------------------------------------*/
int32_t LMM_SensorNameGet(uint32_t lmId, uint32_t sensorId,
    string *sensorNameAddr, int32_t *len)
{
    /* Just passthru to board/device */
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
    /* Just passthru to board/device */
    return SM_SENSORREADINGGET(sensorId, sensorValue, sensorTimestamp);
}

/*--------------------------------------------------------------------------*/
/* Set sensor trippoint                                                     */
/*--------------------------------------------------------------------------*/
int32_t LMM_SensorTripPointSet(uint32_t lmId, uint32_t sensorId,
    uint8_t tripPoint, int64_t value, uint8_t eventControl)
{
    /* Just passthru to board/device */
    return SM_SENSORTRIPPOINTSET(sensorId, tripPoint, value,
        eventControl);
}

/*--------------------------------------------------------------------------*/
/* Enable/disable sensor                                                    */
/*--------------------------------------------------------------------------*/
int32_t LMM_SensorEnable(uint32_t lmId, uint32_t sensorId, bool enable,
    bool timestampReporting)
{
    /* Just passthru to board/device */
    return SM_SENSORENABLE(sensorId, enable, timestampReporting);
}

/*--------------------------------------------------------------------------*/
/* Return sensor enable status                                              */
/*------------------------------------------------------------------------*/
int32_t LMM_SensorIsEnabled(uint32_t lmId, uint32_t sensorId,
    bool *enabled, bool *timestampReporting)
{
    /* Just passthru to board/device */
    return SM_SENSORISENABLED(sensorId, enabled, timestampReporting);
}

/*--------------------------------------------------------------------------*/
/* Report sensor event                                                      */
/*--------------------------------------------------------------------------*/
void LMM_SensorEvent(uint32_t sensorId, uint8_t tripPoint, uint8_t dir)
{
    /* Dispatch for all LM */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
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

