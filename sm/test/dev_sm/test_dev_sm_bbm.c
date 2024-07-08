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
/* Unit test for the device SM BBM API.                                     */
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
/* Test device SM BBM                                                       */
/*--------------------------------------------------------------------------*/
void TEST_DevSmBbm(void)
{
    string name;
    int32_t len = 0;

    printf("**** Device SM BBM API Tests ***\n\n");

    /* Test API correct calls per domain */
    for (uint32_t domainId = 0U; domainId < DEV_SM_NUM_BUTTON; domainId++)
    {
        printf("DEV_SM_BbmRtcNameGet(%u)\n", domainId);
        CHECK(DEV_SM_BbmRtcNameGet(domainId, &name, &len));
        printf("  name=%s\n",  name);
        printf("  len=%d\n",  len);
#ifdef SIMU
        CHECK(DEV_SM_BbmRtcRollover(domainId));
        DEV_SM_BbmHandler();
#endif
    }

    /* Check Boot Status */
    {
        uint32_t flags = 0U;

        printf("DEV_SM_BbmGetBootStatus\n");
        CHECK(DEV_SM_BbmGetBootStatus(&flags));
        printf("   flags=(%u)\n", flags);

        BCHECK(flags == 0U);
    }

    /* BBM RTC State Get */
    {
        uint32_t rtcId = 0U, state = 0U;
        CHECK(DEV_SM_BbmRtcStateGet(rtcId, &state));
    }

    /* Test API Bounds */
    printf("\n**** Device SM BBM API Err Tests ***\n\n");
    {
        printf("DEV_SM_BbmGprSet(%lu, %u)\n", DEV_SM_NUM_GPR, 0U);
        NECHECK(DEV_SM_BbmGprSet(DEV_SM_NUM_GPR, 0U), SM_ERR_NOT_FOUND);

        uint32_t value = 0U;

        printf("DEV_SM_BbmGprGet(%lu, %u)\n", DEV_SM_NUM_GPR, 0U);
        NECHECK(DEV_SM_BbmGprGet(DEV_SM_NUM_GPR, &value), SM_ERR_NOT_FOUND);

        printf("DEV_SM_BbmRtcNameGet(%lu)\n", DEV_SM_NUM_RTC);
        NECHECK(DEV_SM_BbmRtcNameGet(DEV_SM_NUM_RTC, &name, &len),
            SM_ERR_NOT_FOUND);
    }

    printf("\n");
}

