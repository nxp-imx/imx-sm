/*
** ###################################################################
**
** Copyright 2024-2026 NXP
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
/* Unit test for the device SM fault API.                                   */
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
/* Test device SM fault                                                     */
/*--------------------------------------------------------------------------*/
void TEST_DevSmFault(void)
{
    /* Device tests */
    printf("**** Device SM Fault API Tests ***\n\n");

#ifdef SIMU
    {
        uint32_t lmId = 0;
        uint32_t faultId  = DEV_SM_FAULT_1;

        printf("DEV_SM_FaultSet faultId:(%u)\n", faultId);
        CHECK(DEV_SM_FaultSet(lmId, faultId, true));

        faultId  = DEV_SM_FAULT_2;

        printf("DEV_SM_FaultSet faultId:(%u)\n", faultId);
        CHECK(DEV_SM_FaultSet(lmId, faultId, true));

        faultId  = DEV_SM_FAULT_3;

        printf("DEV_SM_FaultSet faultId:(%u)\n", faultId);
        CHECK(DEV_SM_FaultSet(lmId, faultId, true));

        faultId  = DEV_SM_FAULT_4;

        printf("DEV_SM_FaultSet faultId:(%u)\n", faultId);
        CHECK(DEV_SM_FaultSet(lmId, faultId, true));

        faultId  = DEV_SM_FAULT_5;

        printf("DEV_SM_FaultSet faultId:(%u)\n", faultId);
        CHECK(DEV_SM_FaultSet(lmId, faultId, true));

        faultId  = DEV_SM_FAULT_6;

        printf("DEV_SM_FaultSet faultId:(%u)\n", faultId);
        NECHECK(DEV_SM_FaultSet(lmId, faultId, true), SM_ERR_GENERIC_ERROR);

        faultId  = DEV_SM_FAULT_7;

        printf("DEV_SM_FaultSet faultId:(%u)\n", faultId);
        CHECK(DEV_SM_FaultSet(lmId, faultId, true));

        faultId  = DEV_SM_FAULT_8;

        printf("DEV_SM_FaultSet faultId:(%u)\n", faultId);
        CHECK(DEV_SM_FaultSet(lmId, faultId, true));

        faultId  = DEV_SM_FAULT_9;

        printf("DEV_SM_FaultSet faultId:(%u)\n", faultId);
        CHECK(DEV_SM_FaultSet(lmId, faultId, true));

        faultId  = DEV_SM_FAULT_10;

        printf("DEV_SM_FaultSet faultId:(%u)\n", faultId);
        CHECK(DEV_SM_FaultSet(lmId, faultId, true));
    }
#endif

    /* Test API bounds */

    {
        uint32_t lmId = 0;
        uint32_t faultId = DEV_SM_NUM_FAULT;

        printf("DEV_SM_FaultSet Invalid faultId:(%u)\n", faultId);
        NECHECK(DEV_SM_FaultSet(lmId, faultId, false), SM_ERR_OUT_OF_RANGE);
    }

    /* Get a fault state */
    {
        uint32_t faultId = 18U /*DEV_SM_FAULT_WDOG2*/;
        bool state = false;

        printf("DEV_SM_FaultGet faultId:(%u)\n", faultId);
        CHECK(DEV_SM_FaultGet(faultId, &state));
        printf("DEV_SM_FaultGet fault(%u) state: %s\n", 18U /*DEV_SM_FAULT_WDOG2*/,
            state ? "true" : "false");
    }
#ifdef DEV_SM_FAULT_ID
    /*Set: Invalid fault state */
    {
        uint32_t lmId = 0U;
        uint32_t faultId = DEV_SM_FAULT_ID;
        bool state = true;

        printf("DEV_SM_FaultSet faultId:(%u)\n", faultId);
        NECHECK(DEV_SM_FaultSet(lmId, faultId, state),
            SM_ERR_INVALID_PARAMETERS);
    }
#endif
    printf("\n");
}

