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
/* Unit test for the LMM Power API.                                         */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

void TEST_LmmPower(void)
{
    string name;
    int32_t len = 0;
    uint8_t powerState = 0U;
    uint32_t lmId = 1U;

    /* LMM tests */
    printf("**** Lmm Power API Tests ***\n\n");

    /* Test API correct calls per domain */
    for (uint32_t domainId = 0U; domainId < SM_NUM_POWER; domainId++)
    {
        printf("LMM_PowerDomainNameGet(%u, %u)\n", lmId, domainId);
        CHECK(LMM_PowerDomainNameGet(lmId, domainId, &name, &len));
        printf("  name=%s\n",  name);
        printf("  len=%d\n",  len);

        printf("LMM_PowerStateGet(%u, %u)\n", lmId, domainId);
        CHECK(LMM_PowerStateGet(lmId, domainId, &powerState));
        printf("  powerState=%u\n", powerState);

        printf("LMM_PowerStateSet(%u, %u, %u)\n", lmId, domainId,
            powerState);
        CHECK(LMM_PowerStateSet(lmId, domainId, powerState));
    }

    /* Test API correct calls per power state */
    for (powerState = 0U; powerState < SM_NUM_POWER_STATE;
        powerState++)
    {
        printf("LMM_PowerStateNameGet(%u)\n", powerState);
        CHECK(LMM_PowerStateNameGet(lmId, (uint32_t) powerState, &name,
            &len));
        printf("  name=%s\n", name);
        printf("  len=%d\n", len);
    }

    /* Test API bounds */
    printf("\n**** LMM Power API Error Tests ***\n\n");

    printf("LMM_PowerStateSet(%u, %lu)\n", lmId, SM_NUM_POWER);
    NECHECK(LMM_PowerStateSet(SM_NUM_LM, SM_NUM_POWER, powerState),
        SM_ERR_INVALID_PARAMETERS);

    printf("LMM_PowerStateSet(%u, %lu)\n", lmId, SM_NUM_POWER);
    NECHECK(LMM_PowerStateSet(lmId, SM_NUM_POWER, powerState),
        SM_ERR_NOT_FOUND);

    printf("\n");
}

