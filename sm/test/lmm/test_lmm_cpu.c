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
/* Unit test for the device SM CPU API.                                     */
/*==========================================================================*/

/* LM_00010 */

/* Include Config */

/* Includes */

#include "test.h"
#include "dev_sm_api.h"
#include "sm.h"
#include "lmm_cpu.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test device SM CPU                                                       */
/*--------------------------------------------------------------------------*/
void TEST_LmmCpu(void)
{
    /* LM tests */
    printf("**** LMM CPU API Tests ***\n\n");

    uint32_t LmId = 0U, CpuId = DEV_SM_CPU_TEST;

    /* CPU Reset Vector set */
    {
        uint64_t resetvector = TEST_RESET_VECTOR_VAL;
        CHECK(LMM_CpuResetVectorSet(LmId, CpuId, resetvector, \
            false, true, false, true))

#if (DEV_SM_CPU_TEST == 0U)
        /* CPU Hold */
        CHECK(LMM_CpuHold(LmId, CpuId));
#endif

        /* CPU Vector Reset */
        CHECK(LMM_CpuResetVectorReset(LmId, CpuId, false));

#if (DEV_SM_CPU_TEST == 0U)
        /* CPU Stop */
        CHECK(LMM_CpuStop(LmId, CpuId));
#endif
    }

    /* Test API bounds */
    printf("\n**** LMM CPU API Err Tests ***\n\n");

    /* CPU Hold Invalid CpuId */
    {
        CpuId = DEV_SM_NUM_CPU;
        NECHECK(LMM_CpuHold(LmId, CpuId), SM_ERR_NOT_FOUND);
    }

    /* CPU Start Invalid CpuId */
    {
        NECHECK(LMM_CpuStart(LmId, CpuId), SM_ERR_NOT_FOUND);
    }

    /* CPU Start CPU Start flag not valid */
    {
        NECHECK(LMM_CpuStart(LmId, (DEV_SM_PLAT_TEST)), SM_ERR_MISSING_PARAMETERS);
    }

    /* CPU Hold test CPU start flag not set */
    {
        CpuId = 0U;
        NECHECK(LMM_CpuHold(LmId, CpuId), SM_ERR_MISSING_PARAMETERS);
    }

    /* CPU Boot address check */
    {
        CpuId = 0U;
        NECHECK(LMM_CpuHold(LmId, CpuId), SM_ERR_MISSING_PARAMETERS);
    }

    /* CPU Stop: Invalid CPU NUM */
    {
        NECHECK(LMM_CpuHold(LmId, DEV_SM_NUM_CPU), SM_ERR_NOT_FOUND);
    }

    /* Reset Vector Reset: Invalid CPU NUM */
    {
        NECHECK(LMM_CpuResetVectorReset(LmId, DEV_SM_NUM_CPU, false),
            SM_ERR_NOT_FOUND);
    }

    /* pdLPMConfigSet: Invalid CPU NUM */
    {
        NECHECK(LMM_CpuPdLpmConfigSet(LmId, DEV_SM_NUM_CPU, 0U, 0U, 0U),
            SM_ERR_INVALID_PARAMETERS);
    }

    /* LMM_CpuBootCheck: Invalid */
    {
#if (DEV_SM_CPU_TEST != 0U)
        CpuId = DEV_SM_CPU_TEST + 1U;
#else
        CpuId = DEV_SM_CPU_3;
#endif
        NECHECK(LMM_CpuBootCheck(LmId, CpuId), SM_ERR_MISSING_PARAMETERS);
    }

    /* pdLPMConfigSet: Valid NUM */
    {
#if (DEV_SM_CPU_TEST != 0U)
        CpuId = DEV_SM_CPU_TEST;
#else
        CpuId = DEV_SM_CPU_3;
#endif
        uint32_t DomainId = DEV_SM_TEST_SRC_MIX;
        CHECK(LMM_CpuPdLpmConfigSet(LmId, CpuId, DomainId, 0U,
            (1UL << CpuId)));
    }

    /* pdLPMConfigSet: InValid NUM */
    {
        CpuId = 3U;
        NECHECK(LMM_CpuPdLpmConfigSet(LmId, CpuId, 3U, 0U, (1UL << 2U)),
            SM_ERR_INVALID_PARAMETERS);
    }

#if (DEV_SM_CPU_TEST == 0U)
    /* CPU Stop: valid CPU NUM */
    {
        CpuId = 3U;
        CHECK(LMM_CpuStop(LmId, CpuId));
    }
#endif

    /* CPU Stop: Invalid CPU NUM */
    {
        LmId = 0U;
        NECHECK(LMM_CpuStop(LmId, DEV_SM_NUM_CPU), SM_ERR_NOT_FOUND);
    }

    printf("\n");
}

