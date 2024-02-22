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
/* Unit test for the SCMI sensor protocol.                                  */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test_scmi.h"
#include "lmm.h"
#include "rpc_scmi_sensor.h"

/* Local defines */

/* Local types */

/* Local variables */

static scmi_sensor_desc_t s_desc[20];

/* Local functions */

static void TEST_ScmiSensorNotify(bool pass, uint32_t channel,
    uint32_t sensorId);
static void TEST_ScmiSensorSet(bool pass, uint32_t channel,
    uint32_t sensorId);
static void TEST_ScmiSensorExclusive(bool pass, uint32_t channel,
    uint32_t sensorId, uint32_t lmId);
static void TEST_ScmiSensorNone(uint32_t channel,
    uint32_t sensorId);

/*--------------------------------------------------------------------------*/
/* Test SCMI sensor protocol                                                */
/*--------------------------------------------------------------------------*/
void TEST_ScmiSensor(void)
{
    int32_t status = 0;
    uint32_t agentId, channel, sensorId, lmId;
    uint32_t numSensors;

    /* RPC_00010 RPC_00110 RPC_00160 Sensor tests */
    printf("**** Sensor Protocol Tests ***\n\n");

    /* Test protocol version */
    {
        uint32_t ver = 0U;

        printf("SCMI_SensorProtocolVersion(%u)\n", SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_SensorProtocolVersion(SM_TEST_DEFAULT_CHN, &ver));
        printf("  ver=0x%08X\n", ver);

        BCHECK(ver == SCMI_SENSOR_PROT_VER);
    }

    /* Test protocol attributes */
    {
        uint32_t attributes = 0U;
        uint32_t sensorRegAddressLow = 1U;
        uint32_t sensorRegAddressHigh = 1U;
        uint32_t sensorRegLen = 1U;

        printf("SCMISensorProtocolAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_SensorProtocolAttributes(SM_TEST_DEFAULT_CHN,
            &attributes, NULL, NULL, NULL));

        numSensors = SCMI_SENSOR_PROTO_ATTR_NUM_SENSORS(attributes);

        printf("  numSensors=%u\n", numSensors);
        printf("  maxPending=%u\n",
            SCMI_SENSOR_PROTO_ATTR_MAX_PENDING(attributes));

        printf("SCMISensorProtocolAttributes(%u)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_SensorProtocolAttributes(SM_TEST_DEFAULT_CHN,
            &attributes, &sensorRegAddressLow, &sensorRegAddressHigh,
            &sensorRegLen));

        CHECK(SCMI_SensorProtocolAttributes(SM_TEST_DEFAULT_CHN,
            NULL, &sensorRegAddressLow, &sensorRegAddressHigh,
            &sensorRegLen));

        NECHECK(SCMI_SensorProtocolAttributes(SM_SCMI_NUM_CHN,
            NULL, &sensorRegAddressLow, &sensorRegAddressHigh,
            &sensorRegLen), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Test message attributes */
    {
        printf("SCMI_SensorProtocolMessageAttributes(%u, CONFIG_SET)\n",
            SM_TEST_DEFAULT_CHN);
        CHECK(SCMI_SensorProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            SCMI_MSG_SENSOR_CONFIG_SET, NULL));

        printf("SCMI_SensorProtocolMessageAttributes(%u, 30)\n",
            SM_TEST_DEFAULT_CHN);
        NCHECK(SCMI_SensorProtocolMessageAttributes(SM_TEST_DEFAULT_CHN,
            30U, NULL));
    }

    /* Test coverage of exceeding max amount of sensors in
        SensorTripPointNotify */
    {
        uint32_t sensorEventControl = SCMI_SENSOR_EV_CTRL_ENABLE(1U);

        printf("SCMI_SensorTripPointNotify(%u, %u, %u)\n",
            SM_TEST_DEFAULT_CHN, numSensors, sensorEventControl);
        NCHECK(SCMI_SensorTripPointNotify(SM_TEST_DEFAULT_CHN,numSensors,
            sensorEventControl));
    }

    /* Test coverage of exceeding max amount of sensors in
        SensorTripPointConfig */
    {
        uint32_t sensorEventControl = SCMI_SENSOR_TP_EV_CTRL(3U);

        printf("SCMI_SensorTripPointConfig(%u, %u, %u, %d, %d)\n",
            SM_TEST_DEFAULT_CHN, numSensors, sensorEventControl, 0, 0);
        NCHECK(SCMI_SensorTripPointConfig(SM_TEST_DEFAULT_CHN, numSensors,
            sensorEventControl, 0, 0));
    }

    /* Test coverage of exceeding max amount of sensors in
       SensorReadingGet */
    {
        printf("SCMI_SensorTripPointConfig(%u, %u, %u, %d, %d)\n",
            SM_TEST_DEFAULT_CHN, numSensors, SCMI_SENSOR_TP_EV_CTRL(3U),
            0, 0);
        NCHECK(SCMI_SensorReadingGet(SM_TEST_DEFAULT_CHN, numSensors,
            0, NULL));

        NECHECK(SCMI_SensorReadingGet(SM_SCMI_NUM_CHN, numSensors,
            0, NULL), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Test coverage of exceeding max amount of sensors in
        SensorDescriptionGet */
    {
        scmi_sensor_desc_t desc[SCMI_SENSOR_MAX_DESC];
        uint32_t flags = 0;

        printf("SCMI_SensorDescriptionGet(%u, %u)\n",
            SM_TEST_DEFAULT_CHN, numSensors);
        NCHECK(SCMI_SensorDescriptionGet(SM_TEST_DEFAULT_CHN, numSensors,
            &flags, desc));

        NECHECK(SCMI_SensorDescriptionGet(SM_SCMI_NUM_CHN,
            numSensors, &flags, desc), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Test coverage of exceeding max amount of sensors in
        SensorConfigSet */
    {
        uint32_t sensorConfig = SCMI_SENSOR_CONFIG_SET_ENABLE(0U);
        printf("SCMI_SensorConfigSet(%u, %u)\n",
            SM_TEST_DEFAULT_CHN, numSensors);
        NCHECK(SCMI_SensorConfigSet(SM_TEST_DEFAULT_CHN, numSensors,
            sensorConfig));

        NECHECK(SCMI_SensorConfigSet(SM_SCMI_NUM_CHN, numSensors,
            sensorConfig), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Test coverage of exceeding max amount of sensors in
        SensorConfigGet */
    {
        uint32_t sensorConfig = SCMI_SENSOR_CONFIG_GET_ENABLED(0U);
        printf("SCMI_SensorConfigGet(%u, %u)\n",
            SM_TEST_DEFAULT_CHN, numSensors);
        NCHECK(SCMI_SensorConfigGet(SM_TEST_DEFAULT_CHN, numSensors,
            &sensorConfig));

        NECHECK(SCMI_SensorConfigGet(SM_SCMI_NUM_CHN, numSensors,
            &sensorConfig), SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Invalid channel */
    {
        uint32_t numSensorFlags = 0U;
        uint32_t descIndex = 0U;

        NECHECK(SCMI_SensorDescriptionGet(SM_SCMI_NUM_CHN, descIndex,
            &numSensorFlags, &s_desc[descIndex]),
            SCMI_ERR_INVALID_PARAMETERS);
    }

    /* Test running past end of descriptors */
    {
        uint32_t numSensorFlags = 0U;
        uint32_t descIndex = 0U;

        printf("SCMI_SensorDescriptionGet(%u, %u, %u)\n",
            SM_TEST_DEFAULT_CHN, numSensors - 1U, numSensorFlags);
        CHECK(SCMI_SensorDescriptionGet(SM_TEST_DEFAULT_CHN, numSensors
            - 1U, &numSensorFlags, &s_desc[descIndex]));

        printf(" remaining data= %u\n",
            SCMI_SENSOR_NUM_SENSOR_FLAGS_REMAINING_DESCS
                (numSensorFlags));

        printf(" numData=%u\n",
            SCMI_SENSOR_NUM_SENSOR_FLAGS_NUM_DESCS(numSensorFlags));
    }

    /* Testing functionality of SensorDescriptionGet */
    {
        uint32_t numSensorFlags = 0U;
        uint32_t descIndex = 0U;

        CHECK(SCMI_SensorDescriptionGet(SM_TEST_DEFAULT_CHN,
            descIndex, NULL, NULL));

        do
        {
            printf("SCMI_SensorDescriptionGet(%u, %u, %u)\n",
                SM_TEST_DEFAULT_CHN, descIndex, numSensorFlags);
            CHECK(SCMI_SensorDescriptionGet(SM_TEST_DEFAULT_CHN, descIndex,
                &numSensorFlags, &s_desc[descIndex]));

            printf(" remaining data= %u\n",
                SCMI_SENSOR_NUM_SENSOR_FLAGS_REMAINING_DESCS
                    (numSensorFlags));

            uint32_t numData =
                SCMI_SENSOR_NUM_SENSOR_FLAGS_NUM_DESCS(numSensorFlags);
            printf(" numData=%u\n", numData);

            for(uint16_t loopIndex = 0U; loopIndex<numData; loopIndex++)
            {
                printf(" upper 32 data[%u]= %u\n lower 32 data[%u]= %u\n",
                    loopIndex + descIndex,
                    s_desc[loopIndex + descIndex].sensorAttributesHigh,
                    loopIndex + descIndex,
                    s_desc[loopIndex + descIndex].sensorAttributesLow);
            }
            descIndex += numData;
        }
        while(SCMI_SENSOR_NUM_SENSOR_FLAGS_REMAINING_DESCS(numSensorFlags)
            > 0U);
    }

    /* Invalid notification */
    {
        scmi_msg_id_t msgId =
        {
            .protocolId = 0xFFU,
            .messageId = 0xFFU
        };
        lmm_rpc_trigger_t trigger = { 0 };

        printf("RPC_SCMI_SensorDispatchNotification()\n");
        RPC_SCMI_SensorDispatchNotification(msgId, &trigger);
    }

    /* Loop over sensor tests */
    status = TEST_ConfigFirstGet(TEST_SENSOR, &agentId,
        &channel, &sensorId, &lmId);
    while (status == SM_ERR_SUCCESS)
    {
        uint8_t perm = g_scmiAgentConfig[agentId].sensorPerms[sensorId];

        /* Test functions with NONE perm required */
        TEST_ScmiSensorNone(channel, sensorId);

        /* RPC_00170 Test functions with NOTIFY perm required */
        TEST_ScmiSensorNotify(perm >= SM_SCMI_PERM_NOTIFY, channel,
            sensorId);

        /* Test functions with SET perm required */
        TEST_ScmiSensorSet(perm >= SM_SCMI_PERM_SET, channel, sensorId);

        /* Test functions with EXCLUSIVE perm required */
        TEST_ScmiSensorExclusive(perm >= SM_SCMI_PERM_EXCLUSIVE,
            channel, sensorId, lmId);

        /* Get next test case */
        status = TEST_ConfigNextGet(TEST_SENSOR, &agentId,
            &channel, &sensorId, &lmId);
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Test SCMI sensor functions with NONE access                              */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiSensorNone(uint32_t channel,
    uint32_t sensorId)
{
    /* Test config get */
    {
        uint32_t sensorConfigGet = 0U;

        printf("SCMI_SensorConfigGet(%u, %u)\n", channel, sensorId);
        CHECK(SCMI_SensorConfigGet(channel, sensorId,
            &sensorConfigGet));

        printf("  enabled=%u\n",
            SCMI_SENSOR_CONFIG_GET_ENABLED(sensorConfigGet));
        printf("  timestampReporting=%u\n",
            SCMI_SENSOR_CONFIG_GET_TS_ENABLED(sensorConfigGet));

        CHECK(SCMI_SensorConfigGet(channel, sensorId,
            NULL));
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI sensor functions with NOTIFY access                            */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiSensorNotify(bool pass, uint32_t channel,
    uint32_t sensorId)
{
    /* Test sensor notify with notification enabled */
    {
        uint32_t sensorEventControl = SCMI_SENSOR_EV_CTRL_ENABLE(1U);
        printf("SCMI_SensorTripPointNotify(%u, %u, %u)\n", channel,
            sensorId,sensorEventControl);
        XCHECK(pass, SCMI_SensorTripPointNotify(channel, sensorId,
            sensorEventControl));
    }

    /* Test sensor notify without notification enabled */
    {
        uint32_t sensorEventControl = SCMI_SENSOR_EV_CTRL_ENABLE(0U);
        printf("SCMI_SensorTripPointNotify(%u, %u, %u)\n", channel,
            sensorId,sensorEventControl);
        XCHECK(pass, SCMI_SensorTripPointNotify(channel, sensorId,
            sensorEventControl));
    }

    {
        uint32_t sensorEventControl = SCMI_SENSOR_EV_CTRL_ENABLE(0U);

        NECHECK(SCMI_SensorTripPointNotify(SM_SCMI_NUM_CHN, sensorId,
            sensorEventControl), SCMI_ERR_INVALID_PARAMETERS);
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI sensor functions with SET access                               */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiSensorSet(bool pass, uint32_t channel,
    uint32_t sensorId)
{
    uint32_t descIndex = 0U;

    /* Find sensor descriptor */
    while(sensorId != s_desc[descIndex].sensorId)
    {
        descIndex++;
    }

    /* Test sensor config set */
    {
        uint32_t sensorConfig = SCMI_SENSOR_CONFIG_SET_ENABLE(1U);

        printf("SCMI_SensorConfigSet(%u, %u, 0x%08X)\n",
            channel, sensorId, sensorConfig);
        XCHECK(pass, SCMI_SensorConfigSet(channel, sensorId,
            sensorConfig));
    }

    /* After enabling sensor, check to get reading */
    if (pass)
    {
        uint32_t flags = SCMI_SENSOR_READ_FLAGS_ASYNC(0U);
        scmi_sensor_reading_t readings[SCMI_SENSOR_MAX_READINGS]
            = { 0 };

        printf("SCMI_SensorReadingGet(%u, %u)\n", channel, sensorId);
        CHECK(SCMI_SensorReadingGet(channel, sensorId,
            flags, readings));

        printf(" Sensor_value_low = %d\n" " Timestap_value_low = %d\n"
            " Sensor_value_high = %d\n" " Timestap_value_high = %d\n",
            readings[0].sensorValueLow, readings[0].timestampLow,
            readings[0].sensorValueHigh, readings[0].timestampHigh);

        CHECK(SCMI_SensorReadingGet(channel, sensorId,
            flags, NULL));
    }

    /* Test config set with sensor timestamp disabled */
    {
        uint32_t sensorConfig = SCMI_SENSOR_CONFIG_SET_ENABLE(1U)
            | SCMI_SENSOR_CONFIG_SET_TS_ENABLE(0U);

        printf("SCMI_SensorConfigSet(%u, %u, 0x%08X)\n",
            channel, sensorId, sensorConfig);
        XCHECK(pass, SCMI_SensorConfigSet(channel, sensorId,
            sensorConfig));
    }

    /* Test for error for an async call in SensorReadingGet */
    {
        scmi_sensor_reading_t readings[SCMI_SENSOR_MAX_READINGS]
            = { 0 };
        uint32_t flags = SCMI_SENSOR_READ_FLAGS_ASYNC(1U);

        printf("SCMI_SensorReadingGet(%u, %u)\n",
            SM_TEST_DEFAULT_CHN, sensorId);
        NCHECK(SCMI_SensorReadingGet(channel, sensorId,
            flags,readings));
    }

    /* Should fail with an error after trying to use protocol
       wihtout sensor enabled */
    {
        uint32_t sensorConfig = SCMI_SENSOR_CONFIG_SET_ENABLE(0U);
        XCHECK(pass, SCMI_SensorConfigSet(channel, sensorId,
            sensorConfig));

        if (pass)
        {
            uint32_t flags = SCMI_SENSOR_READ_FLAGS_ASYNC(0U);
            scmi_sensor_reading_t readings[SCMI_SENSOR_MAX_READINGS]
                = { 0 };
            printf("SCMI_SensorReadingGet(%u, %u)\n", channel, sensorId);
            NECHECK(SCMI_SensorReadingGet(channel, sensorId,
                flags, readings), SCMI_ERR_PROTOCOL_ERROR);
        }
    }

    /* Checking to see if timestamp is able to be called and read when
       sensor has permissions */
    if (pass)
    {
        if (SCMI_SENSOR_ATTR_LOW_TIME_SUPPORT(
            s_desc[descIndex].sensorAttributesLow) == 1U)
        {
            uint32_t sensorConfig = SCMI_SENSOR_CONFIG_SET_ENABLE(1U)
                | SCMI_SENSOR_CONFIG_SET_TS_ENABLE(1U);

            CHECK(SCMI_SensorConfigSet(channel, sensorId,
                sensorConfig));

            /* Test config get */
            {
                uint32_t sensorConfigGet = 0U;

                printf("SCMI_SensorConfigGet(%u, %u)\n", channel, sensorId);
                CHECK(SCMI_SensorConfigGet(channel, sensorId,
                    &sensorConfigGet));

                printf("  enabled=%u\n",
                    SCMI_SENSOR_CONFIG_GET_ENABLED(sensorConfigGet));
                printf("  timestampReporting=%u\n",
                    SCMI_SENSOR_CONFIG_GET_TS_ENABLED(sensorConfigGet));

                BCHECK(SCMI_SENSOR_CONFIG_GET_TS_ENABLED(
                    sensorConfigGet) == 1U);
            }
        }
        else
        {
            uint32_t sensorConfigGet = 0U;

            printf("SCMI_SensorConfigGet(%u, %u)\n", channel, sensorId);
            CHECK(SCMI_SensorConfigGet(channel, sensorId,
                &sensorConfigGet));

            printf("  enabled=%u\n",
                SCMI_SENSOR_CONFIG_GET_ENABLED(sensorConfigGet));
            printf("  timestampReporting=%u\n",
                SCMI_SENSOR_CONFIG_GET_TS_ENABLED(sensorConfigGet));
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Test SCMI sensor functions with EXCLUSIVE access                         */
/*--------------------------------------------------------------------------*/
static void TEST_ScmiSensorExclusive(bool pass, uint32_t channel,
    uint32_t sensorId, uint32_t lmId)
{
    /* Enable notification to test sensor trip point config */
    if (pass)
    {
        uint32_t sensorConfig = SCMI_SENSOR_CONFIG_SET_ENABLE(1U);
        CHECK(SCMI_SensorConfigSet(channel, sensorId,
            sensorConfig));
    }

    /* Test sensor config pos */
    {
        uint32_t tripPointEvCtrl
            = SCMI_SENSOR_TP_EV_CTRL(SCMI_SENSOR_TP_POS)
            | SCMI_SENSOR_TP_EV_CTRL_TRIP_ID(0U);
        int64_t tp = 2525;

        printf("SCMI_SensorTripPointConfig(%u, %u)\n",
            channel, sensorId);
        XCHECK(pass, SCMI_SensorTripPointConfig(channel, sensorId,
            tripPointEvCtrl, SM_INT64_L(tp), SM_INT64_H(tp)));

        NECHECK(SCMI_SensorTripPointConfig(SM_SCMI_NUM_CHN, sensorId,
            tripPointEvCtrl, SM_INT64_L(tp), SM_INT64_H(tp)),
            SCMI_ERR_INVALID_PARAMETERS);

    }

    /* Enabling notifications and receiving notification only in simu */
    if (pass)
    {
        /* Enable notify */
        uint32_t sensorEventControl = SCMI_SENSOR_EV_CTRL_ENABLE(1U);
        printf("SCMI_SensorTripPointNotify(%u, %u, %u)\n", channel,
            sensorId,sensorEventControl);
        CHECK(SCMI_SensorTripPointNotify(channel, sensorId,
            sensorEventControl));

#ifdef SIMU
        uint32_t agent = 0U;
        uint32_t sensorIdNotify = 0U;
        uint32_t tripPointDesc = 0U;

        /* Trip point event*/
        printf("SCMI_SensorTripPointEvent(%u)\n", channel + 1U);
        CHECK(SCMI_SensorTripPointEvent(channel + 1U, &agent,
            &sensorIdNotify, &tripPointDesc));

        BCHECK(agent == 0U);
        BCHECK(sensorIdNotify == sensorId);
        BCHECK(SCMI_SENSOR_EVENT_DIRECTION(tripPointDesc)
            == SCMI_SENSOR_TP_POS);
        BCHECK(SCMI_SENSOR_EVENT_TP_ID(tripPointDesc)
            == 0U);
        NECHECK(SCMI_SensorTripPointEvent(SM_SCMI_NUM_CHN, &agent,
            &sensorIdNotify, &tripPointDesc), SCMI_ERR_INVALID_PARAMETERS);
#endif

        /* Testing passing in NULL for parameters for TripPointEvent */
        /* Enable notify */
        sensorEventControl = SCMI_SENSOR_EV_CTRL_ENABLE(1U);
        printf("SCMI_SensorTripPointNotify(%u, %u, %u)\n", channel,
            sensorId,sensorEventControl);
        CHECK(SCMI_SensorTripPointNotify(channel, sensorId,
            sensorEventControl));

#ifdef SIMU

        /* Trip point event*/
        printf("SCMI_SensorTripPointEvent(%u)\n", channel + 1U);
        CHECK(SCMI_SensorTripPointEvent(channel + 1U, NULL,
            NULL, NULL));
#endif
    }

    /* Test sensor config neg */
    {
        uint32_t tripPointEvCtrl
            = SCMI_SENSOR_TP_EV_CTRL(SCMI_SENSOR_TP_NEG)
            | SCMI_SENSOR_TP_EV_CTRL_TRIP_ID(0U);
        int64_t tp = -2525;
        printf("SCMI_SensorTripPointConfig(%u, %u)\n",
            channel, sensorId);
        XCHECK(pass, SCMI_SensorTripPointConfig(channel, sensorId,
            tripPointEvCtrl, SM_INT64_L(tp), SM_INT64_H(tp)));
    }

    if (pass)
    {
        /* Enable notify */
        uint32_t sensorEventControl = SCMI_SENSOR_EV_CTRL_ENABLE(1U);
        printf("SCMI_SensorTripPointNotify(%u, %u, %u)\n", channel,
            sensorId,sensorEventControl);
        CHECK(SCMI_SensorTripPointNotify(channel, sensorId,
            sensorEventControl));

#ifdef SIMU
        uint32_t agent = 0U;
        uint32_t sensorIdNotify = 0U;
        uint32_t tripPointDesc = 0U;

        /* Trip point event*/
        printf("SCMI_SensorTripPointEvent(%u)\n", channel + 1U);
        CHECK(SCMI_SensorTripPointEvent(channel + 1U, &agent,
            &sensorIdNotify, &tripPointDesc));

        BCHECK(agent == 0U);
        BCHECK(sensorIdNotify == sensorId);
        BCHECK(SCMI_SENSOR_EVENT_TP_ID(tripPointDesc)
            == 0U);
#endif
        /* Disable notifications after previous notifications */
        sensorEventControl = SCMI_SENSOR_EV_CTRL_ENABLE(0U);
        CHECK(SCMI_SensorTripPointNotify(channel, sensorId,
            sensorEventControl));
    }

    /* Reset Config */
#ifdef SIMU
    if (pass)
    {
        /* Reset */
        uint32_t sysManager = 0U;
        printf("LMM_SystemLmShutdown(%u, %u)\n", sysManager, lmId);
        CHECK(LMM_SystemLmShutdown(sysManager, 0U, lmId, false, &g_swReason));
    }
#endif
}

