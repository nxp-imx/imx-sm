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
/* Unit test for the device SM system API.                                  */
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
/* Test device SM system                                                    */
/*--------------------------------------------------------------------------*/
/* coverity[misra_c_2012_rule_17_11_violation] */
void TEST_DevSmSystem(void)
{
    printf("**** Device SM System API Tests ***\n\n");

    /* Reason Name Get: Invalid Reason */
    {
        const char *name[15];
        int32_t len = 0;

        NECHECK(DEV_SM_SystemReasonNameGet(DEV_SM_NUM_REASON,
            &name[0], &len), SM_ERR_NOT_FOUND);
    }

#ifdef SIMU
    /* Reset Coverage */
    {
        /* Call for a reset */
        printf("DEV_SM_SystemReset(%u, %u)\n", 1U, 1U);
        CHECK(DEV_SM_SystemReset());
    }

    /* Shutdown and Stage Reset Coverage */
    {
        printf("DEV_SM_SystemStageReset()\n");

        /* DEV_SM_ROM_BS_PRIMARY */
        CHECK(DEV_SM_SystemStageReset(DEV_SM_ROM_BS_PRIMARY, 0U));

        /* DEV_SM_ROM_BS_SECONDARY */
        CHECK(DEV_SM_SystemStageReset(DEV_SM_ROM_BS_SECONDARY, 0U));

        /* DEV_SM_ROM_BS_RECOVERY */
        CHECK(DEV_SM_SystemStageReset(DEV_SM_ROM_BS_RECOVERY, 0U));

        /* DEV_SM_ROM_BS_SERIAL */
        CHECK(DEV_SM_SystemStageReset(DEV_SM_ROM_BS_SERIAL, 0U));

        /* Default */
        CHECK(DEV_SM_SystemStageReset(0U, 0U));

        /* Error Condition */
        {

            SM_TestModeSet(SM_TEST_MODE_DEV_LVL1);
            NECHECK(DEV_SM_SystemStageReset(DEV_SM_ROM_BS_SERIAL, 0U),
                SM_ERR_TEST);
            SM_TestModeSet(SM_TEST_MODE_OFF);
        }

        printf("DEV_SM_SystemShutdown()\n");
        CHECK(DEV_SM_SystemShutdown());
    }

    /* SystemShutdownRecSet Coverage */
    {
        dev_sm_rst_rec_t shutdownRec = { 0 };

        printf("DEV_SM_SystemShutdownRecSet()\n");
        DEV_SM_SystemShutdownRecSet(shutdownRec);
    }

    /* Complete System Reset Processing Coverage */
    {
        dev_sm_rst_rec_t rst = { 0 };

        printf("DEV_SM_SystemRstComp()\n");
        CHECK(DEV_SM_SystemRstComp(&rst));
    }

    /* System Error Coverage */
    {
        int32_t status = 0;
        uint32_t pc = 0x800U;

        printf("DEV_SM_System()\n");
        DEV_SM_SystemError(status, pc);

        /* PC = 0U */
        DEV_SM_SystemError(status, 0U);
    }

    /* System Idle Coverage */
    {
        printf("DEV_SM_System()\n");
        CHECK(DEV_SM_SystemIdle());
    }

    /* Syslog Dump Coverage */
    {
        uint32_t flags = 0x0U;
        printf("DEV_SM_SyslogDump()\n");
        CHECK(DEV_SM_SyslogDump(flags));

        /*Branch coverage */
        SM_TestModeSet(SM_TEST_MODE_DEV_LVL1);
        NECHECK((DEV_SM_SyslogDump(flags)),
            SM_ERR_TEST);
        SM_TestModeSet(SM_TEST_MODE_OFF);
    }


    /* Fuse Word Address Get Coverage */
    {
        uint32_t fuseWord = 0x0U, addr = 0x0U;
        printf("DEV_SM_FuseInfoGet()\n");
        CHECK(DEV_SM_FuseInfoGet(fuseWord, &addr));
        printf("  addr=0x%08X\n",  addr);
    }

    /* Trigger Software Interrupt Test */
    {
        SWI_Trigger();
    }

    /* Branch coverage: DEV_SM_RomHandoverGet */
    {
        const rom_handover_t *handover = NULL;
        SM_TestModeSet(SM_TEST_MODE_DEV_LVL1);
        NECHECK(DEV_SM_RomHandoverGet(&handover),
            SM_ERR_TEST);
        SM_TestModeSet(SM_TEST_MODE_OFF);
    }

    /* Branch coverage: DEV_SM_RomBootImgNGet */
    {
        uint32_t type = 0U, cpuId = 0U, mSel = 0U, flags = 0U;
        uint64_t addr = 0U;

        SM_TestModeSet(SM_TEST_MODE_DEV_LVL1);
        NECHECK(DEV_SM_RomBootImgNGet(type, &cpuId, &addr, &mSel, &flags),
            SM_ERR_NOT_FOUND);
        SM_TestModeSet(SM_TEST_MODE_OFF);
    }

    /* Function coverage: DEV_SM_SystemHalt (simu only) */
    {
        /* Intentional: Test code */
        /* coverity[misra_c_2012_rule_2_2_violation] */
        DEV_SM_SystemHalt();
    }
#endif

    /* Dump the error log */
    {
        /* Intentional: Test code */
        /* coverity[misra_c_2012_rule_2_2_violation] */
        DEV_SM_ErrorDump();
        DEV_SM_ErrorLog(1U);
        /* Intentional: Test code */
        /* coverity[misra_c_2012_rule_2_2_violation] */
        DEV_SM_ErrorDump();
    }

    /* DEV_SM_SiInfoGet Test */
    {
        uint32_t deviceId = 0U, siRev = 0U, partNum = 0U;
        const char *siName = NULL;
        const char *pnName = NULL;

        CHECK(DEV_SM_SiInfoGet(&deviceId, &siRev, &partNum, &siName, &pnName));
        CHECK(DEV_SM_SiInfoGet(NULL, NULL, NULL, NULL, NULL));

        SM_TestModeSet(SM_TEST_MODE_DEV_LVL1);
        NECHECK(DEV_SM_SiInfoGet(&deviceId, &siRev, &partNum, &siName, &pnName),
            SM_ERR_TEST);
        (void) DEV_SM_SiVerGet();
        SM_TestModeSet(SM_TEST_MODE_OFF);
    }

    /* dev_sm stage reset coverage */
    {
#ifdef SIMU
        (void) DEV_SM_RomStageGet();
        (void) DEV_SM_RomContainerGet();
#else
        uint32_t curr_stage = DEV_SM_RomStageGet();
        uint32_t current_container = DEV_SM_RomContainerGet();

        printf("current stage: %u current container: %u\n", curr_stage, current_container);

        /* Set the test mode */
        SM_TestModeSet(SM_TEST_MODE_DEV_LVL2);

        /* Container 0 */
        NECHECK(DEV_SM_SystemStageReset(curr_stage, 0U), SM_ERR_TEST);

        /* Set the test mode */
        SM_TestModeSet(SM_TEST_MODE_DEV_LVL1);

        /* Container 1 */
        NECHECK(DEV_SM_SystemStageReset(curr_stage, 1U), SM_ERR_TEST);

        /* Container Invalid container */
        NECHECK(DEV_SM_SystemStageReset(curr_stage, 3U), SM_ERR_TEST);

        /* Restore to original*/
        if (current_container == ROM_CONTAINER_1)
        {
            NECHECK(DEV_SM_SystemStageReset(curr_stage, 0U), SM_ERR_TEST);
        }
        else if (current_container == ROM_CONTAINER_2)
        {
            NECHECK(DEV_SM_SystemStageReset(curr_stage, 1U), SM_ERR_TEST);
        }
        else
        {
            NECHECK(DEV_SM_SystemStageReset(curr_stage, 0U), SM_ERR_TEST);
            SRC_GEN->GPR15 = current_container;
        }

        /* Set the test mode */
        SM_TestModeSet(SM_TEST_MODE_DRV_LVL1);

        /* System stage coverage */
        (void) DEV_SM_SystemStageReset(curr_stage, 0U);

        /* Reset the test mode */
        SM_TestModeSet(SM_TEST_MODE_OFF);
#endif
    }

#ifndef SIMU
    {
        /* Set the test mode */
        SM_TestModeSet(SM_TEST_MODE_DEV_LVL1);

        dev_sm_rst_rec_t shutdownRec = { 0 };
        /* DEV_SM_SystemShutdownRecSet coverage */
        DEV_SM_SystemShutdownRecSet(shutdownRec);

        /* DEV_SM_SystemRstComp coverage */
        NECHECK(DEV_SM_SystemRstComp(NULL), SM_ERR_TEST);

        /* DEV_SM_SystemError coverage */
        DEV_SM_SystemError(0, 0U);

        /* DEV_SM_SystemError coverage */
        DEV_SM_SystemError(0, 4U);

        /* Set the test mode */
        SM_TestModeSet(SM_TEST_MODE_DRV_LVL1);

        /* DEV_SM_SystemShutdown coverage */
        (void) DEV_SM_SystemShutdown();

        /* System reset coverage */
        (void) DEV_SM_SystemReset();

        /* Reset the test mode */
        SM_TestModeSet(SM_TEST_MODE_OFF);
    }

    /* SystemShutdownRecSet Coverage */
    {
        dev_sm_rst_rec_t shutdownRec = { 0 };
        shutdownRec.reason = DEV_SM_TEST_REASON_UNUSED;
        shutdownRec.errId = 17U;

        printf("DEV_SM_SystemShutdownRecSet()\n");
        DEV_SM_SystemShutdownRecSet(shutdownRec);
    }

    {
        /* Get the Silicon version */
#ifdef INC_LIBC
        uint32_t siRev = DEV_SM_SiVerGet();
        printf("silicon rev: %u\n", siRev);
#else
        (void) DEV_SM_SiVerGet();
#endif
    }
#endif

    printf("\n");
}

