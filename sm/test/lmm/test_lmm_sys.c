/*
** ###################################################################
**
** Copyright 2023-2026 NXP
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
/* coverity[misra_c_2012_rule_17_11_violation] */
void TEST_LmmSys(void)
{
    /* LM_00010 LM tests */
    printf("**** LMM Sys API Tests ***\n\n");

    /* Test API bounds */
    printf("\n**** LMM Sys API Err Tests ***\n\n");

    /* System Model SelSet */
    {
        printf("LMM_SystemModeSelSet(SM_LM_NUM_MSEL)\n");
        NECHECK(LMM_SystemModeSelSet(SM_LM_NUM_MSEL), \
            SM_ERR_INVALID_PARAMETERS);
    }

    /* Invalid LmId: Sleep Mode Set */
    {
        uint32_t sleepMode = 0U;
        uint32_t sleepFlags = 0U;

        printf("LMM_SystemSleepModeSet(SM_NUM_LM)\n");
        NECHECK(LMM_SystemSleepModeSet(SM_NUM_LM, sleepMode, sleepFlags),
            SM_ERR_NOT_FOUND);
    }

    /* Invalid LmId: Lm status */
    {
        uint32_t stateLm = SM_NUM_LM, state = 0U;
        int32_t errStatus = 0;
        printf("LM_SystemLmStatus(%d)\n", SM_NUM_LM);
        NECHECK(LM_SystemLmStatus(SM_NUM_LM, stateLm, &state, &errStatus),
            SM_ERR_NOT_FOUND);
    }

    /* Invalid LmId: Shutdown LM */
    {
        uint32_t agentId = 0U, shutdownLm = SM_NUM_LM;
        lmm_rst_rec_t shutdownRec = { 0 };

        printf("LMM_SystemLmShutdown(%d)\n", SM_NUM_LM);
        NECHECK(LMM_SystemLmShutdown(SM_NUM_LM, agentId, shutdownLm, \
            true /*graceful*/, &shutdownRec), \
            SM_ERR_NOT_FOUND);
    }

    /* Invalid LmId: Reset LM */
    {
        uint32_t agentId = 0U, resetLm = SM_NUM_LM;
        lmm_rst_rec_t resetRec = { 0 };

        printf("LMM_SystemLmReset(%d)\n", SM_NUM_LM);
        NECHECK(LMM_SystemLmReset(SM_NUM_LM, agentId, resetLm, \
            true /*warm*/, true  /*graceful*/, &resetRec), \
            SM_ERR_NOT_FOUND);
    }

    /* LM_SystemReason */
    {
        lmm_rst_rec_t shutdownRec = { 0 }, bootRec = { 0 };

        printf("LM_SystemReason(LmId: 0)\n");
        SM_TestModeSet(SM_TEST_MODE_EXEC_LVL1);
        LM_SystemReason(0U, &bootRec, &shutdownRec);
        SM_TestModeSet(SM_TEST_MODE_OFF);
    }

    /* Check the LM CPU state */
    {
        uint32_t lmId = SM_LM_DEFAULT;
        uint32_t cpuId = DEV_SM_CPU_TEST;

        printf("LM_CpuCheck(%u %u)\n", lmId, cpuId);
        bool rc = LM_CpuCheck(lmId, cpuId);
        if (rc != true)
        {
            SM_Error(SM_ERR_INVALID_PARAMETERS);
        }
    }

    /* Change the cpu run state */
    {
        LMM_SystemCpuModeChanged(1U);
        LMM_SystemCpuModeChanged(1U);
    }

#ifdef SIMU
    /* SystemRstComp */
    {
        lmm_rst_rec_t rst_rec_t = { 0 };
        printf("LMM_SystemRstComp\n");
        CHECK(LMM_SystemRstComp(&rst_rec_t));
    }

    /* SystemLmCheck */
    {
        printf("LMM_SystemLmCheck\n");
        CHECK(LMM_SystemLmCheck(1));

        SM_TestModeSet(SM_TEST_MODE_LMM_LVL1);
        NECHECK(LMM_SystemLmCheck(1), SM_ERR_TEST);
        SM_TestModeSet(SM_TEST_MODE_OFF);
    }

    /* Test converage: change cpu run state */
    {
        SM_TestModeSet(SM_TEST_MODE_EXEC_LVL1);
        LMM_SystemCpuModeChanged(1U);
        SM_TestModeSet(SM_TEST_MODE_OFF);
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
        lmm_rst_rec_t bootRec = { 0 };
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

