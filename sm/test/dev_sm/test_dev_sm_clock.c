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
/* Unit test for the device SM Clock  API.                                  */
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

void TEST_DevSmClock(void)
{
    string name;
    int32_t len = 0;
    dev_sm_clock_range_t clockRange;
    uint64_t rate = 0U;
    bool enabled = false;

#ifdef SIMU
    uint32_t parent = 0U;
    uint32_t mux = 0U;
    uint32_t numMuxes = 0U;
#endif

    /* Device tests */
    printf("**** Device SM Clock API Tests ***\n\n");

    for (uint32_t clockId = 0U; clockId < DEV_SM_NUM_CLOCK; clockId++)
    {
        printf("DEV_SM_ClockNameGet(%u)\n", clockId);
        CHECK(DEV_SM_ClockNameGet(clockId, &name, &len));
        printf("  name=%s\n",  name);
        printf("  len=%d\n",  len);

        printf("DEV_SM_ClockDescribe(%u)\n", clockId);
        CHECK(DEV_SM_ClockDescribe(clockId, &clockRange));

        if (SM_UINT64_H(clockRange.lowestRate) == 0U)
        {
            printf("  lowestRate=%u\n",
                SM_UINT64_L(clockRange.lowestRate));
        }
        else
        {
            printf("  lowestRate=>4GHz\n");
        }
        if (SM_UINT64_H(clockRange.highestRate) == 0U)
        {
            printf("  highestRate=%u\n",
                SM_UINT64_L(clockRange.highestRate));
        }
        else
        {
            printf("  highestRate=>4GHz\n");
        }
        printf("  stepSize=%u\n",
            SM_UINT64_L(clockRange.stepSize));

#ifdef SIMU
        {
            /* Set clock to arbitrary number */
            CHECK(DEV_SM_ClockRateSet(clockId, 80U, 0U));

            /* Make sure clock is set to number  */
            CHECK(DEV_SM_ClockRateGet(clockId, &rate));

            /* Enable clock */
            CHECK(DEV_SM_ClockEnable(clockId, true));

            /* Check to see if enabled */
            printf("DEV_SM_ClockIsEnabled(%u)\n", clockId);
            CHECK(DEV_SM_ClockIsEnabled(clockId, &enabled));
            printf("  enabled=%d\n",  enabled);

            /* Pass RateSet ain invalid argument*/
            NECHECK(DEV_SM_ClockRateSet(clockId, 0U, 3U),
                SM_ERR_INVALID_PARAMETERS);

            /* Make sure clockId is not clock 0*/
            if (clockId == DEV_SM_CLK_0)
            {
                /* If it is throw err, and print number of muxes*/
                printf("DEV_SM_ClockMuxGet(%u)\n", clockId);
                NECHECK(DEV_SM_ClockMuxGet(clockId, 0U, &mux, &numMuxes),
                    SM_ERR_NOT_SUPPORTED);
                printf("  numMuxes=%d\n",  numMuxes);
            }
            else
            {
                /* If not do MuxGet test and print mux and numMuxes*/
                printf("DEV_SM_ClockMuxGet(%u)\n", clockId);
                CHECK(DEV_SM_ClockMuxGet(clockId, 0U, &mux, &numMuxes));
                printf("  mux=%d\n", mux);
                printf("  numMuxes=%d\n",  numMuxes);

                /* Pass invalid argument for idx*/
                NECHECK(DEV_SM_ClockMuxGet(clockId, 1U, &mux, &numMuxes),
                    SM_ERR_OUT_OF_RANGE);
            }
        }
#endif

        printf("DEV_SM_ClockRateGet(%u)\n", clockId);
        CHECK(DEV_SM_ClockRateGet(clockId, &rate));
        printf("  rate=%u\n", SM_UINT64_L(rate));

#ifdef SIMU
        CHECK(DEV_SM_ClockParentGet(clockId, &parent));
        CHECK(DEV_SM_ClockParentSet(clockId, parent));
        CHECK(DEV_SM_ClockEnable(clockId, false));
        CHECK(DEV_SM_ClockIsEnabled(clockId, &enabled));
#endif
    }

    /* Test API bounds */
    NECHECK(DEV_SM_ClockNameGet(DEV_SM_NUM_CLOCK, &name, &len),
        SM_ERR_NOT_FOUND);
    NECHECK(DEV_SM_ClockDescribe(DEV_SM_NUM_CLOCK, &clockRange),
        SM_ERR_NOT_FOUND);

#ifdef SIMU
    NECHECK(DEV_SM_ClockMuxGet(DEV_SM_NUM_CLOCK, 0U, &mux, &numMuxes),
        SM_ERR_NOT_FOUND);
#endif

    NECHECK(DEV_SM_ClockRateSet(DEV_SM_NUM_CLOCK, 0U, 0U),
        SM_ERR_NOT_FOUND);
    NECHECK(DEV_SM_ClockRateGet(DEV_SM_NUM_CLOCK, &rate), SM_ERR_NOT_FOUND);
    NECHECK(DEV_SM_ClockEnable(DEV_SM_NUM_CLOCK, true), SM_ERR_NOT_FOUND);
    NECHECK(DEV_SM_ClockIsEnabled(DEV_SM_NUM_CLOCK, &enabled),
        SM_ERR_NOT_FOUND);

#ifdef SIMU
    NECHECK(DEV_SM_ClockParentSet(DEV_SM_NUM_CLOCK, 0U),
        SM_ERR_NOT_FOUND);
    NECHECK(DEV_SM_ClockParentGet(DEV_SM_NUM_CLOCK, &parent),
        SM_ERR_NOT_FOUND);
#endif

    printf("\n");
}

