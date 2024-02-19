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
/* Unit test for the device SM voltage API.                                 */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test device SM voltage                                                   */
/*--------------------------------------------------------------------------*/
void TEST_DevSmVoltage(void)
{
    string name;
    int32_t len = 0;

    /* Device tests */
    printf("**** Device SM Voltage API Tests ***\n\n");

    /* Test API correct calls per domain */
    for (uint32_t domainId = 0U; domainId < DEV_SM_NUM_VOLT; domainId++)
    {
        printf("DEV_SM_VoltageNameGet(%u)\n", domainId);
        CHECK(DEV_SM_VoltageNameGet(domainId, &name, &len));
        printf("  name=%s\n",  name);
        printf("  len=%d\n",  len);

        printf("DEV_SM_VoltageModeNameGet(%u)\n", domainId);
        CHECK(DEV_SM_VoltageModeNameGet(domainId, &name, &len));
        printf("  name=%s\n",  name);
        printf("  len=%d\n",  len);
    }

    /* Test API correct calls per voltage mode */
#ifdef SIMU
    for (uint8_t voltMode = 0U; voltMode < DEV_SM_NUM_VOLT_MODE; voltMode++)
    {
        uint8_t tempMode = 0U;

        /* Set the Volt Mode */
        printf("DEV_SM_VoltageModeSet(%u)\n", voltMode);
        CHECK(DEV_SM_VoltageModeSet(0U, voltMode));
        printf("  name=%s\n", name);
        printf("  len=%d\n", len);

        /* Get the Volt Mode */
        printf("DEV_SM_VoltageModeGet(%u)\n", voltMode);
        CHECK(DEV_SM_VoltageModeGet(0U, &tempMode));
        printf("  name=%s\n", name);
        printf("  len=%d\n", len);

        /* Ensure Correctness */
        BCHECK(tempMode == voltMode);
    }

    /* Test All Voltage Levels */
    {
        dev_sm_voltage_range_t range;

        printf("DEV_SM_VoltageDescribe\n");
        CHECK(DEV_SM_VoltageDescribe(0U, &range));

        int32_t max = range.highestVolt;
        int32_t min = range.lowestVolt;
        int32_t step = range.stepSize;

        printf("   maxLevel=%u\n", max);
        printf("   minLevel=%u\n", min);
        printf("   stepSize=%u\n", step);

        /* Loop through and test all voltage levels for domain 0 */
        for (int32_t level = min; level < max; level += step)
        {
            int32_t tempLevel = 0U;

            /* Set the Level */
            CHECK(DEV_SM_VoltageLevelSet(0U, level));

            /* Get the Level */
            CHECK(DEV_SM_VoltageLevelGet(0U, &tempLevel));

            /* Ensure Correctness */
            BCHECK(tempLevel == level);
        }
        printf("Level tests completed\n");
    }
#endif

    /* Test API bounds */
    printf("\n**** Device SM Voltage API Err Tests ***\n\n");

    /* Test API invalid domainId */
    {
        printf("DEV_SM_VoltageNameGet(%lu)\n", DEV_SM_NUM_VOLT);
        NECHECK(DEV_SM_VoltageNameGet(DEV_SM_NUM_VOLT, &name, &len),
            SM_ERR_NOT_FOUND);

        printf("DEV_SM_VoltageModeNameGet(%u)\n", DEV_SM_NUM_VOLT_MODE);
        NECHECK(DEV_SM_VoltageModeNameGet(DEV_SM_NUM_VOLT_MODE, &name, &len),
            SM_ERR_NOT_FOUND);
    }

    printf("\n");
}

