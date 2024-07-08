/*
** ###################################################################
**
** Copyright 2024 NXP
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
/* Unit test for the board SM BBM API.                                      */
/*==========================================================================*/

/* Includes */

#include "test.h"
#include "brd_sm.h"
#include "lmm_sys.h"

/*--------------------------------------------------------------------------*/
/* Test board SM sensor                                                     */
/*--------------------------------------------------------------------------*/
void TEST_BrdSm(void)
{
    /* Board tests */
    printf("**** Board SM API Tests ***\n\n");

    {
        int32_t argc = 1;
        const char status[5] = "0";
        const char * const argv[1] = {status};
        dev_sm_rst_rec_t resetRec = {0};
        uint32_t reaction = LMM_REACT_NONE + 1U;
        uint32_t LmId = 0U;

        CHECK(BRD_SM_Custom(argc, &argv[0]));

        /* Branch coverage */
        CHECK(BRD_SM_Custom(0U, &argv[0]));
        NECHECK(BRD_SM_FaultReactionGet(resetRec, &reaction, &LmId),
            SM_ERR_INVALID_PARAMETERS);

        /* BRD_SM_SupplyModeSet: Invalid domain Id */
        NECHECK(BRD_SM_SupplyModeSet(DEV_SM_NUM_VOLT, 0U),
            SM_ERR_HARDWARE_ERROR);

        /* BRD_SM_SupplyModeGet: Invalid domain Id */
        NECHECK(BRD_SM_SupplyModeGet(DEV_SM_NUM_VOLT, NULL),
            SM_ERR_HARDWARE_ERROR);

        /* BRD_SM_SupplyLevelSet: Invalid domain Id */
        NECHECK(BRD_SM_SupplyLevelSet(DEV_SM_NUM_VOLT, 0U),
            SM_ERR_HARDWARE_ERROR);

        /* BRD_SM_SupplyLevelGet: Invalid domain Id */
        NECHECK(BRD_SM_SupplyLevelGet(DEV_SM_NUM_VOLT, NULL),
            SM_ERR_HARDWARE_ERROR);
    }
}

