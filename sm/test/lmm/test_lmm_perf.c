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
/* Unit test for the device SM Perf API.                                    */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test.h"
#include "lmm.h"
#include "dev_sm_api.h"
#include "sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test device SM Perf                                                      */
/*--------------------------------------------------------------------------*/
void TEST_LmmPerf(void)
{

    /* LM tests */
    printf("**** LMM Perf API Tests ***\n\n");

    uint32_t lmId = 1U;
    uint32_t perfLevel = 0U;

    /* Check Level Get and Set for all domains */
    for (uint32_t domainId = 0U; domainId < SM_NUM_PERF; domainId++)
    {
        /* Get the Level */
        printf("LMM_PerfLevelGet(%u, %u)\n", lmId, domainId);
        CHECK(LMM_PerfLevelGet(lmId, domainId, &perfLevel));

        /* Set the Level */
        printf("LMM_PerfLevelSet(%u, %u)\n", lmId, domainId);
        CHECK(LMM_PerfLevelSet(lmId, domainId, perfLevel));
    }

    /* Test API bounds */
    printf("\n**** LMM Perf API Err Tests ***\n\n");

    /* INVALID PARAMS -- lmId */
    printf("LMM_PerfLevelSet(%u, %u)\n", SM_NUM_LM, 0U);
    NECHECK(LMM_PerfLevelSet(SM_NUM_LM, 0U, perfLevel),
        SM_ERR_INVALID_PARAMETERS);

    /* NOT FOUND -- domainId */
    printf("LMM_PerfLevelSet(%u, %u)\n", lmId, SM_NUM_PERF);
    NECHECK(LMM_PerfLevelSet(lmId, SM_NUM_PERF, perfLevel),
        SM_ERR_NOT_FOUND);

    /* INVALID PARAMS -- numLevels */
    uint32_t numLevels = 0U;
    printf("DEV_SM_PerfNumLevelsGet()\n");
    CHECK(DEV_SM_PerfNumLevelsGet(0U, &numLevels));

    printf("LMM_PerfLevelSet(%u, %u)\n", lmId, 0U);
    NECHECK(LMM_PerfLevelSet(lmId, 0U, numLevels),
        SM_ERR_INVALID_PARAMETERS);

    printf("\n");
}

