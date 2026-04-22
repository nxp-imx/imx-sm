/*
 * Copyright 2026 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Includes */

#include "fsl_clock.h"
#include "sm_test_mode.h"

/* External real functions */

extern bool __real_CPU_RunModeSet(uint32_t cpuIdx, uint32_t runMode);
extern bool __real_CPU_RunModeGet(uint32_t cpuIdx, uint32_t *runMode);
extern bool __real_CPU_SleepModeSet(uint32_t cpuIdx, uint32_t sleepMode);
extern bool __real_CPU_IrqWakeSet(uint32_t cpuIdx, uint32_t maskIdx,
    uint32_t maskVal);
extern bool __real_CPU_NonIrqWakeSet(uint32_t cpuIdx, uint32_t maskVal);
extern bool __real_CPU_LpmConfigSet(uint32_t cpuIdx, uint32_t srcMixIdx,
    uint32_t lpmSetting, uint32_t retMask);
extern bool __real_CPU_PerLpiConfigSet(uint32_t cpuIdx, uint32_t perLpiIdx,
    uint32_t lpmSetting);
extern bool __real_CPU_ResetVectorSet(uint32_t cpuIdx, uint64_t vector);

/*--------------------------------------------------------------------------*/
/* Set CPU run mode                                                         */
/*--------------------------------------------------------------------------*/
bool __wrap_CPU_RunModeSet(uint32_t cpuIdx, uint32_t runMode)
{
    bool rc;

    /* Call original function */
    rc = __real_CPU_RunModeSet(cpuIdx, runMode);

    SM_TEST_MODE_EXEC(SM_TEST_MODE_EXEC_LVL1, rc = false)

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get CPU run mode                                                         */
/*--------------------------------------------------------------------------*/
bool __wrap_CPU_RunModeGet(uint32_t cpuIdx, uint32_t *runMode)
{
    bool rc;

    /* Call original function */
    rc = __real_CPU_RunModeGet(cpuIdx, runMode);

    SM_TEST_MODE_EXEC(SM_TEST_MODE_EXEC_LVL1, rc = true)

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU sleep mode                                                       */
/*--------------------------------------------------------------------------*/
bool __wrap_CPU_SleepModeSet(uint32_t cpuIdx, uint32_t sleepMode)
{
    bool rc;

    /* Call original function */
    rc = __real_CPU_SleepModeSet(cpuIdx, sleepMode);

    SM_TEST_MODE_EXEC(SM_TEST_MODE_EXEC_LVL1, rc = false)

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set GPC IRQ wake mask                                                    */
/*--------------------------------------------------------------------------*/
bool __wrap_CPU_IrqWakeSet(uint32_t cpuIdx, uint32_t maskIdx,
    uint32_t maskVal)
{
    bool rc;

    /* Call original function */
    rc = __real_CPU_IrqWakeSet(cpuIdx, maskIdx, maskVal);

    SM_TEST_MODE_EXEC(SM_TEST_MODE_EXEC_LVL1, rc = false)

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set GPC non-IRQ wake mask                                                */
/*--------------------------------------------------------------------------*/
bool __wrap_CPU_NonIrqWakeSet(uint32_t cpuIdx, uint32_t maskVal)
{
    bool rc;

    /* Call original function */
    rc = __real_CPU_NonIrqWakeSet(cpuIdx, maskVal);

    SM_TEST_MODE_EXEC(SM_TEST_MODE_EXEC_LVL1, rc = false)

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU power domain LPM config                                          */
/*--------------------------------------------------------------------------*/
bool __wrap_CPU_LpmConfigSet(uint32_t cpuIdx, uint32_t srcMixIdx,
    uint32_t lpmSetting, uint32_t retMask)
{
    bool rc;

    /* Call original function */
    rc = __real_CPU_LpmConfigSet(cpuIdx, srcMixIdx, lpmSetting, retMask);

    SM_TEST_MODE_EXEC(SM_TEST_MODE_EXEC_LVL1, rc = false)

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU peripheral low-power interface config                            */
/*--------------------------------------------------------------------------*/
bool __wrap_CPU_PerLpiConfigSet(uint32_t cpuIdx, uint32_t perLpiIdx,
    uint32_t lpmSetting)
{
    bool rc;

    /* Call original function */
    rc = __real_CPU_PerLpiConfigSet(cpuIdx, perLpiIdx, lpmSetting);

    SM_TEST_MODE_EXEC(SM_TEST_MODE_EXEC_LVL1, rc = false)

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set CPU reset vector                                                     */
/*--------------------------------------------------------------------------*/
bool __wrap_CPU_ResetVectorSet(uint32_t cpuIdx, uint64_t vector)
{
    bool rc;

    /* Call original function */
    rc = __real_CPU_ResetVectorSet(cpuIdx, vector);

    SM_TEST_MODE_EXEC(SM_TEST_MODE_EXEC_LVL1, rc = false)

    /* Return status */
    return rc;
}

