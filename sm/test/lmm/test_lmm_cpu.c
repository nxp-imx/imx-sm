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

#ifdef SIMU
    uint32_t LmId = 0U, CpuId = 0U;

    /* CPU Reset Vector set */
    {
        uint64_t resetvector = 0x123456789U;
        CHECK(LMM_CpuResetVectorSet(LmId, CpuId, resetvector,
            false, true, false, true))

        /* CPU Hold */
        CHECK(LMM_CpuHold(LmId, CpuId));

        /* CPU Vector Reset */
        CHECK(LMM_CpuResetVectorReset(LmId, CpuId));

        /* CPU Stop */
        CHECK(LMM_CpuStop(LmId, CpuId));
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
        NECHECK(LMM_CpuStart(LmId, (CpuId - 1U)), SM_ERR_MISSING_PARAMETERS);
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
        CpuId = 0U;
        NECHECK(LMM_CpuHold(LmId, DEV_SM_NUM_CPU), SM_ERR_NOT_FOUND);
    }

    /* Reset Vector Reset: Invalid CPU NUM */
    {
        CpuId = 0U;
        NECHECK(LMM_CpuResetVectorReset(LmId, DEV_SM_NUM_CPU),
            SM_ERR_NOT_FOUND);
    }

    /* pdLPMConfigSet: Invalid CPU NUM */
    {
        CpuId = 0U;
        NECHECK(LMM_CpuPdLpmConfigSet(LmId, DEV_SM_NUM_CPU, 0U, 0U, 0U),
            SM_ERR_INVALID_PARAMETERS);
    }

    /* LMM_CpuBootCheck: Invalid */
    {
        CpuId = 0U;
        NECHECK(LMM_CpuBootCheck(LmId, CpuId), SM_ERR_MISSING_PARAMETERS);
    }
    printf("\n");

#endif
}

