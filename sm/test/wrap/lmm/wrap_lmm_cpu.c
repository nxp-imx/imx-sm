/*
** ###################################################################
**
** Copyright 2026 NXP
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

/* Includes */

#include "lmm.h"
#include "sm_test_mode.h"

/* External real functions */

extern int32_t __real_LMM_CpuBootCheck(uint32_t lmId, uint32_t cpuId);
extern int32_t __real_LMM_CpuStart(uint32_t lmId, uint32_t cpuId);
extern int32_t __real_LMM_CpuHold(uint32_t lmId, uint32_t cpuId);
extern int32_t __real_LMM_CpuStop(uint32_t lmId, uint32_t cpuId);
extern int32_t __real_LMM_CpuResetVectorSet(uint32_t lmId, uint32_t cpuId,
    uint64_t re__real_setVector, bool boot, bool start, bool resume,
    bool table);
extern int32_t __real_LMM_CpuPdLpmConfigSet(uint32_t lmId, uint32_t cpuId,
    uint32_t domainId, uint32_t lpmSetting, uint32_t retMask);

/*--------------------------------------------------------------------------*/
/* Check CPU boot address                                                   */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_CpuBootCheck(uint32_t lmId, uint32_t cpuId)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_CpuBootCheck(lmId, cpuId);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* CPU start                                                                */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_CpuStart(uint32_t lmId, uint32_t cpuId)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_CpuStart(lmId, cpuId);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* CPU hold                                                                 */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_CpuHold(uint32_t lmId, uint32_t cpuId)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_CpuHold(lmId, cpuId);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* CPU stop                                                                 */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_CpuStop(uint32_t lmId, uint32_t cpuId)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_CpuStop(lmId, cpuId);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set reset vector                                                         */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_CpuResetVectorSet(uint32_t lmId, uint32_t cpuId,
    uint64_t resetVector, bool boot, bool start, bool resume, bool table)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_CpuResetVectorSet(lmId, cpuId, resetVector,
        boot, start, resume, table);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set CPU power domain LPM config                                          */
/*--------------------------------------------------------------------------*/
int32_t __wrap_LMM_CpuPdLpmConfigSet(uint32_t lmId, uint32_t cpuId,
    uint32_t domainId, uint32_t lpmSetting, uint32_t retMask)
{
    int32_t status;

    /* Call original function */
    status = __real_LMM_CpuPdLpmConfigSet(lmId, cpuId, domainId, lpmSetting,
        retMask);

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

