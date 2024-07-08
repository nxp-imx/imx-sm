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
/* Unit test for the device SM power API.                                   */
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
/* Test device SM power                                                     */
/*--------------------------------------------------------------------------*/
void TEST_DevSmPower(void)
{
    string name;
    int32_t len = 0;
    uint32_t retMask = 0U;
    uint8_t powerState = 0U;

    /* Device tests */
    printf("**** Device SM Power API Tests ***\n\n");

    /* Test API correct calls per domain */
    for (uint32_t domainId = 0U; domainId < DEV_SM_NUM_POWER; domainId++)
    {
        printf("DEV_SM_PowerDomainNameGet(%u)\n", domainId);
        CHECK(DEV_SM_PowerDomainNameGet(domainId, &name, &len));
        printf("  name=%s\n",  name);
        printf("  len=%d\n",  len);

        printf("DEV_SM_PowerStateGet(%u)\n", domainId);
        CHECK(DEV_SM_PowerStateGet(domainId, &powerState));
        printf("  powerState=%u\n", powerState);

        CHECK(DEV_SM_PowerStateSet(domainId, powerState));

#ifdef SIMU
        CHECK(DEV_SM_PowerRetModeSet(domainId, retMask));
#endif

        /* Ret Mask Get */
        CHECK(DEV_SM_PowerRetMaskGet(domainId, &retMask));
        printf("   retMask=%u\n", retMask);
    }

    /* Test API correct calls per power state */
    for (powerState = 0U; powerState < DEV_SM_NUM_POWER_STATE;
        powerState++)
    {
        printf("DEV_SM_PowerStateNameGet(%u)\n", powerState);
        CHECK(DEV_SM_PowerStateNameGet((uint32_t) powerState, &name,
            &len));
        printf("  name=%s\n", name);
        printf("  len=%d\n", len);
    }

    printf("\n**** Device SM Power API Err Tests ***\n\n");

    /* Test API bounds */
    NECHECK(DEV_SM_PowerDomainNameGet(DEV_SM_NUM_POWER, &name, &len),
        SM_ERR_NOT_FOUND);
    NECHECK(DEV_SM_PowerStateGet(DEV_SM_NUM_POWER, &powerState),
        SM_ERR_NOT_FOUND);
    NECHECK(DEV_SM_PowerStateSet(DEV_SM_NUM_POWER, powerState),
        SM_ERR_NOT_FOUND);
    NECHECK(DEV_SM_PowerStateNameGet(DEV_SM_NUM_POWER_STATE, &name,
        &len), SM_ERR_NOT_FOUND);
    NECHECK(DEV_SM_PowerRetMaskGet(DEV_SM_NUM_POWER, &retMask),
        SM_ERR_NOT_FOUND);

    printf("\n");
}

