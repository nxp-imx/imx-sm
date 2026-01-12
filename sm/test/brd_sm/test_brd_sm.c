/*
** ###################################################################
**
** Copyright 2024, 2026 NXP
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
        dev_sm_rst_rec_t resetRec = { 0 };
        uint32_t reaction = 0U;
        uint32_t LmId = 0U;
        uint8_t voltMode;
        int32_t microVolt;

        CHECK(BRD_SM_Custom(argc, &argv[0]));

        /* Branch coverage */
        CHECK(BRD_SM_Custom(0, &argv[0]));

        /* BRD_SM_CustomFaultt  coverage */
        CHECK(BRD_SM_CustomFault(resetRec, LmId));

        /* BRD_SM_FaultReactionGet: Invalid reason */
        resetRec.reason = DEV_SM_NUM_REASON;
        resetRec.valid = true;
        reaction = LMM_REACT_GRP_RESET;
        CHECK(BRD_SM_FaultReactionGet(resetRec, &reaction, &LmId));

        /* BRD_SM_FaultReactionGet: Invalid reaction */
        reaction = LMM_REACT_NONE + 1U;
        NECHECK(BRD_SM_FaultReactionGet(resetRec, &reaction, &LmId),
            SM_ERR_INVALID_PARAMETERS);

        /* BRD_SM_SupplyModeSet: Invalid domain Id */
        NECHECK(BRD_SM_SupplyModeSet(SM_NUM_VOLT, 0U),
            SM_ERR_NOT_FOUND);

        /* BRD_SM_SupplyModeGet: Invalid domain Id */
        NECHECK(BRD_SM_SupplyModeGet(SM_NUM_VOLT, &voltMode),
            SM_ERR_NOT_FOUND);

        /* BRD_SM_SupplyLevelSet: Invalid domain Id */
        NECHECK(BRD_SM_SupplyLevelSet(SM_NUM_VOLT, 0),
            SM_ERR_NOT_FOUND);

        /* BRD_SM_SupplyLevelGet: Invalid domain Id */
        NECHECK(BRD_SM_SupplyLevelGet(SM_NUM_VOLT, &microVolt),
            SM_ERR_NOT_FOUND);
    }

    /* Save/Load BRD_SM_ShutdownRecord */
    {
        dev_sm_rst_rec_t shutdownRec =
        {
            .reason = DEV_SM_REASON_SW,
            .errId = DEV_SM_FAULT_SM_ERR,
            .validErr = true,
            .extInfo[0] = 0xFFFFFFFFU,
            .extLen = 1U,
            .valid = true
        };

        /* BRD_SM_ShutdownRecordSave */
        BRD_SM_ShutdownRecordSave(shutdownRec);

        /* BRD_SM_ShutdownRecordLoad */
        BRD_SM_ShutdownRecordLoad(&shutdownRec);
    }
}

