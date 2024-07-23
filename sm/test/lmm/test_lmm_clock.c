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
/* Unit test for the LM Clock API.                                          */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

void TEST_LmmClock(void)
{
    string name;
    int32_t len = 0;
    uint32_t lmId = 1U;
    dev_sm_clock_range_t clockRange;
#ifdef SIMU
    uint32_t mux = 0U;
    uint32_t numMuxes = 0U;
    uint32_t parent = 0U;
    bool enable = true;
#endif
    uint64_t rate = 0U;
    bool enabled = false;

    /* LM_00010 LM_00030 LM tests */
    printf("**** LMM Clock API Tests ***\n\n");

    for (uint32_t clockId = 0U; clockId < (SM_NUM_CLOCK - 1U); clockId++)
    {
        printf("LMM_ClockNameGet(%u, %u)\n",lmId, clockId);
        CHECK(LMM_ClockNameGet(lmId, clockId, &name, &len));
        printf("  name=%s\n",  name);
        printf("  len=%d\n",  len);

        printf("LMM_ClockDescribe(%u, %u)\n", lmId, clockId);
        CHECK(LMM_ClockDescribe(lmId, clockId, &clockRange));

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
        /* Set clock to arbitrary number */
        printf("LMM_ClockRateSet(%u, %u)\n", lmId, clockId);
        CHECK(LMM_ClockRateSet(lmId, clockId, 80U, 0U));

        /* Make sure clock is set to number  */
        printf("LMM_ClockRateGet(%u, %u)\n", lmId, clockId);
        CHECK(LMM_ClockRateGet(lmId, clockId, &rate));

        /* Enable clock */
        printf("LMM_ClockEnable(%u, %u)\n", lmId, clockId);
        CHECK(LMM_ClockEnable(lmId, clockId, enable));

        /* Check to see if enabled */
        printf("LMM_ClockIsEnabled(%u, %u)\n", lmId, clockId);
        CHECK(LMM_ClockIsEnabled(lmId, clockId, &enabled));
        printf("  enabled=%d\n",  enabled);

        /* Make sure clockId not clock 0*/
        if (clockId == DEV_SM_CLK_0)
        {
            /* If it is throw err, and print number of muxes*/
            printf("LMM_ClockMuxGet(%u, %u)\n", lmId, clockId);
            NECHECK(LMM_ClockMuxGet(lmId, clockId, 0U, &mux, &numMuxes),
                SM_ERR_NOT_SUPPORTED);
            printf("  numMuxes=%d\n",  numMuxes);
        }
        else
        {
            /* If not do MuxGet test and print mux and numMuxes*/
            printf("LMM_ClockMuxGet(%u, %u)\n", lmId, clockId);
            CHECK(LMM_ClockMuxGet(lmId, clockId, 0U, &mux, &numMuxes));
            printf("  mux=%d\n", mux);
            printf("  numMuxes=%d\n",  numMuxes);
        }
#endif
        printf("LMM_ClockRateGet(%u, %u)\n", lmId, clockId);
        CHECK(LMM_ClockRateGet(lmId, clockId, &rate));
        printf("  rate=%u\n", SM_UINT64_L(rate));

#ifdef SIMU
        /* Get parent*/
        printf("LMM_ClockParentGet(%u, %u)\n", lmId, clockId);
        CHECK(LMM_ClockParentGet(lmId, clockId, &parent));

        printf("LMM_ClockParentSet(%u, %u)\n", lmId, clockId);
        CHECK(LMM_ClockParentSet(lmId, clockId, parent));

        printf("LMM_ClockReset(%u, %u)\n", lmId, clockId);
        NECHECK(LMM_ClockReset(lmId, clockId), SM_ERR_BUSY);

        /* Disable clock */
        printf("LMM_ClockEnable(%u, %u)\n", lmId, clockId);
        CHECK(LMM_ClockEnable(lmId, clockId, !enable));

        /* Check to see if disabled */
        printf("LMM_ClockIsEnabled(%u, %u)\n", lmId, clockId);
        CHECK(LMM_ClockIsEnabled(lmId, clockId, &enabled));
        printf("  enabled=%u\n", enabled);

        printf("LMM_ClockReset(%u, %u)\n", lmId, clockId);
        CHECK(LMM_ClockReset(lmId, clockId));

        /* Branch -- Invalid Channel */
        NECHECK(LMM_ClockReset(lmId, SM_NUM_CLOCK), SM_ERR_NOT_FOUND);
#endif
    }

    /* Test error bounds */
    printf("\n**** LMM Clock API Err Tests ***\n\n");

    printf("LMM_ClockEnable(%u, %u)\n", SM_NUM_LM, lmId);
    NECHECK(LMM_ClockEnable(SM_NUM_LM, SM_NUM_CLOCK, enabled),
        SM_ERR_INVALID_PARAMETERS);

    printf("LMM_ClockEnable(%lu, %u)\n", SM_NUM_CLOCK, lmId);
    NECHECK(LMM_ClockEnable(lmId, SM_NUM_CLOCK, enabled),
        SM_ERR_NOT_FOUND);

    printf("LMM_ClockExtendedSet(%lu, %u)\n",SM_NUM_CLOCK, lmId);
    NECHECK(LMM_ClockExtendedSet(lmId, SM_NUM_CLOCK, 0U, 0U),
        SM_ERR_NOT_FOUND);

    uint32_t extCfgValue = 0U;
    printf("LMM_ClockExtendedGet(%lu, %u)\n",SM_NUM_CLOCK, lmId);
    NECHECK(LMM_ClockExtendedGet(lmId, SM_NUM_CLOCK, 0U, &extCfgValue),
        SM_ERR_NOT_FOUND);

    printf("\n");
}

