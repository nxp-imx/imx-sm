/*
** ###################################################################
**
** Copyright 2023-2024 NXP
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
/* Unit test for the board SM BBM API.                                      */
/*==========================================================================*/

/* Includes */

#include "test.h"
#include "brd_sm.h"

/*--------------------------------------------------------------------------*/
/* Test board SM sensor                                                     */
/*--------------------------------------------------------------------------*/
void TEST_BrdSmSensor(void)
{
    /* Board tests */
    printf("**** Board SM Sensor API Tests ***\n\n");

#ifdef BRD_SM_NUM_SENSOR
    string name;
    int32_t len = 0;
    dev_sm_sensor_desc_t sensor;
    int64_t sensorValue = 0;
    uint64_t sensorTimestamp = 0U;
    bool enable = true;
    bool enabled = false;

    /* Test API correct calls per sensor */
    for (uint32_t sensorId = 0U; sensorId < SM_NUM_SENSOR; sensorId++)
    {
        bool timestampReporting = false;
        printf("BRD_SM_SensorNameGet(%u)\n", sensorId);
        CHECK(BRD_SM_SensorNameGet(sensorId, &name, &len));
        printf("  name=%s\n",  name);
        printf("  len=%d\n",  len);

        printf("BRD_SM_SensorDescribe(%u)\n", sensorId);
        CHECK(BRD_SM_SensorDescribe(sensorId, &sensor));

        printf("  sensorType=%u\n", sensor.sensorType);
        printf("  sensorExponent=%u\n", sensor.sensorExponent);
        printf("  numTripPoints=%u\n", sensor.numTripPoints);
        printf("  timestampSupport=%u\n", sensor.timestampSupport);
        printf("  timestampExponent=%u\n",
            sensor.timestampExponent);

        /* Enable sensor*/
        printf("  timestampReporting=%u\n", timestampReporting);
        printf("BRD_SM_SensorEnable(%u)\n", sensorId);
        CHECK(BRD_SM_SensorEnable(sensorId, enable, timestampReporting));

        /* Check to see if sensor got enabled*/
        printf("BRD_SM_SensorIsEnabled(%u)\n", sensorId);
        CHECK(BRD_SM_SensorIsEnabled(sensorId, &enabled,
            &timestampReporting));
        printf("  enable=%u\n",  enabled);
        printf("  timestampReporting=%u\n",  timestampReporting);


        printf("BRD_SM_SensorReadingGet(%u)\n", sensorId);
        CHECK(BRD_SM_SensorReadingGet(sensorId, &sensorValue,
            &sensorTimestamp));

        /* Turn off sensor*/
        printf("BRD_SM_SensorEnable(%u)\n", sensorId);
        CHECK(BRD_SM_SensorEnable(sensorId, !enable, timestampReporting));

        /* Check to see if sensor is off*/
        printf("BRD_SM_SensorIsEnabled(%u)\n", sensorId);
        CHECK(BRD_SM_SensorIsEnabled(sensorId, &enabled,
            &timestampReporting));
        printf("  enable=%u\n",  enabled);
        printf("  timestampReporting=%u\n",  timestampReporting);

        /* Run ReadingGet with sensor disabled to make sure it returns
           error*/
        printf("BRD_SM_SensorReadingGet(%u)\n", sensorId);
        NECHECK(BRD_SM_SensorReadingGet(sensorId, &sensorValue,
            &sensorTimestamp), SM_ERR_NOT_SUPPORTED);

        /* Check if timestampSupport is on and then return error or does
           timestamping */
        if (!sensor.timestampSupport)
        {
            printf("BRD_SM_SensorEnable(%u)\n", sensorId);
            NECHECK(BRD_SM_SensorEnable(
                sensorId, !enable, true), SM_ERR_NOT_SUPPORTED);
        }
        else
        {
            printf("BRD_SM_SensorEnable(%u)\n", sensorId);
            CHECK(BRD_SM_SensorEnable(
                sensorId, !enable, true));
        }

        /* Incorrect parameters for trippointset*/
        printf("BRD_SM_SensorTripPointSet(%u)\n", sensorId);
        NECHECK(BRD_SM_SensorTripPointSet(sensorId, 0U, 0, 0U),
            SM_ERR_NOT_SUPPORTED);
    }

    /* Test API bounds */
    bool timestampReporting = false;

    printf("\n**** Board SM Sensor API Err Tests ***\n\n");

    printf("BRD_SM_SensorNameGet(%lu)\n", SM_NUM_SENSOR);
    NECHECK(BRD_SM_SensorNameGet(SM_NUM_SENSOR, &name, &len),
        SM_ERR_NOT_FOUND);

    printf("BRD_SM_SensorDescribe(%lu)\n", SM_NUM_SENSOR);
    NECHECK(BRD_SM_SensorDescribe(SM_NUM_SENSOR, &sensor),
        SM_ERR_NOT_FOUND);

    printf("BRD_SM_SensorReadingGet(%lu)\n", SM_NUM_SENSOR);
    NECHECK(BRD_SM_SensorReadingGet(SM_NUM_SENSOR, &sensorValue,
        &sensorTimestamp), SM_ERR_NOT_FOUND);

    printf("BRD_SM_SensorEnable(%lu)\n", SM_NUM_SENSOR);
    NECHECK(BRD_SM_SensorEnable(SM_NUM_SENSOR, enable,
        timestampReporting), SM_ERR_NOT_FOUND);

    printf("BRD_SM_SensorIsEnabled(%lu)\n", SM_NUM_SENSOR);
    NECHECK(BRD_SM_SensorIsEnabled(SM_NUM_SENSOR,
        &enabled, &timestampReporting), SM_ERR_NOT_FOUND);

    printf("BRD_SM_SensorTripPointSet(%lu)\n", SM_NUM_SENSOR);
    NECHECK(BRD_SM_SensorTripPointSet(SM_NUM_SENSOR,
        0U, 0, 0U), SM_ERR_NOT_FOUND);
#else
    printf("Skipped.\n");
#endif

    printf("\n");
}

