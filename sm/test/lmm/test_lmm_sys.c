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
/* Unit test for the device SM System API.                                  */
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
/* Test device SM Sys                                                       */
/*--------------------------------------------------------------------------*/
void TEST_LmmSys(void)
{
    /* LM_00010 LM tests */
    printf("**** LMM Sys API Tests ***\n\n");

    /* Test API bounds */
    printf("\n**** LMM Sys API Err Tests ***\n\n");

    /* System Model SelSet */
    {
        printf("LMM_SystemModeSelSet(SM_LM_NUM_MSEL)\n");
        NECHECK(LMM_SystemModeSelSet(SM_LM_NUM_MSEL),
            SM_ERR_INVALID_PARAMETERS);
    }

#ifdef SIMU
    /* SystemRstComp */
    {
        lmm_rst_rec_t rst_rec_t = {0};
        printf("LMM_SystemRstComp\n");
        CHECK(LMM_SystemRstComp(&rst_rec_t));
    }

    /* SystemLmCheck */
    {
        printf("LMM_SystemLmCheck\n");
        CHECK(LMM_SystemLmCheck(1));
    }

    /* SystemLmWake */
    {
        uint32_t lmId = 1, agentId = 1, wakeLm = 2;
        printf("LMM_SystemLmWake\n");
        CHECK(LMM_SystemLmWake(lmId, agentId, wakeLm));
    }

    /* SystemGrpBoot */
    {
        uint32_t lmId = 1, agentId = 1;
        lmm_rst_rec_t bootRec = {0};
        uint8_t group = 1;
        printf("LMM_SystemGrpBoot\n");
        CHECK(LMM_SystemGrpBoot(lmId, agentId, &bootRec, group));
    }

    /* SystemSuspend Branch coverage */
    {
        NECHECK(LMM_SystemLmSuspend(0U, 0U, SM_NUM_LM), SM_ERR_NOT_FOUND);
    }

    /* SystemLmWake Branch coverage */
    {
        NECHECK(LMM_SystemLmWake(0U, 0U, SM_NUM_LM), SM_ERR_NOT_FOUND);
    }

    /* SystemLmReason Branch coverage */
    {
        NECHECK(LM_SystemLmReason(0U, SM_NUM_LM, NULL, NULL),
            SM_ERR_NOT_FOUND);
    }
#endif

    printf("\n");
}

