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
/* Unit test for the device SM performance API.                             */
/*==========================================================================*/

/* DEV_00010 */

/* Include Config */

/* Includes */

#include "test.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test device SM performance                                               */
/*--------------------------------------------------------------------------*/
void TEST_DevSmPerf(void)
{
    string name;
    int32_t len = 0;

    /* Device tests */
    printf("**** Device SM Performance API Tests ***\n\n");

    /* Test API correct calls per domain */
    for (uint32_t domainId = 0U; domainId < DEV_SM_NUM_PERF; domainId++)
    {
        printf("DEV_SM_PerfNameGet(%u)\n", domainId);
        CHECK(DEV_SM_PerfNameGet(domainId, &name, &len));
        printf("  name=%s\n",  name);
        printf("  len=%d\n",  len);
    }

    /* Test API correct level set calls */
    {
        uint32_t numLevels = 0U;

        printf("DEV_SM_PerfNumLevelsGet(%u)\n", 0U);
        CHECK(DEV_SM_PerfNumLevelsGet(0U, &numLevels));
        printf("   numLevels=%u", numLevels);

        dev_sm_perf_desc_t desc = { 0 };

        /* Test all performance levels */
        for (uint32_t perfLevel = 0U; perfLevel < numLevels; perfLevel++)
        {
            printf("DEV_SM_PerfDescribe(%u)\n", 0U);
            CHECK(DEV_SM_PerfDescribe(0U, perfLevel, &desc));
            printf("   latency=%u", desc.latency);
            printf("   powerCost=%u", desc.powerCost);
            printf("   value=%u\n", desc.value);
        }
    }

    /* Test API bounds */
    printf("\n**** Device SM Performance API Err Tests ***\n\n");

    /* Test API invalid domainId */
    {
        printf("DEV_SM_PerfNameGet(%u)\n", DEV_SM_NUM_PERF);
        NECHECK(DEV_SM_PerfNameGet(DEV_SM_NUM_PERF, &name, &len),
            SM_ERR_NOT_FOUND);

        uint32_t perfLevel = 0U;

        printf("DEV_SM_PerfLevelSet(%u)\n", DEV_SM_NUM_PERF);
        NECHECK(DEV_SM_PerfLevelSet(DEV_SM_NUM_PERF, perfLevel),
            SM_ERR_NOT_FOUND);

        printf("DEV_SM_PerfLevelGet(%u)\n", DEV_SM_NUM_PERF);
        NECHECK(DEV_SM_PerfLevelGet(DEV_SM_NUM_PERF, &perfLevel),
            SM_ERR_NOT_FOUND);
    }

    /* Test API for exceeding array bounds */
    {
        uint32_t numLevels = 0U;

        printf("DEV_SM_PerfNumLevelsGet(%u)\n", 0U);
        CHECK(DEV_SM_PerfNumLevelsGet(0U, &numLevels));
        printf("   numLevels=%u", numLevels);

        dev_sm_perf_desc_t desc = { 0 };

        printf("DEV_SM_PerfDescribe(%u)\n", 0U);
        NECHECK(DEV_SM_PerfDescribe(0U, numLevels, &desc),
            SM_ERR_OUT_OF_RANGE);
    }

    printf("\n");
}

