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

#include "fsl_src.h"
#include "fsl_power.h"
#include "sm_test_mode.h"

/* External real functions */

extern bool __real_SRC_MemRetentionModeSet(uint32_t srcMixIdx,
    uint32_t memRetMask);
extern bool __real_SRC_MixIsPwrSwitchOn(uint32_t srcMixIdx);

/*--------------------------------------------------------------------------*/
/* Configure retention mode of MEM slice                                    */
/*--------------------------------------------------------------------------*/
bool __wrap_SRC_MemRetentionModeSet(uint32_t srcMixIdx, uint32_t memRetMask)
{
    bool status;

    /* Call original function */
    status = __real_SRC_MemRetentionModeSet(srcMixIdx, memRetMask);

    SM_TEST_MODE_ERR(SM_TEST_MODE_EXEC_LVL1, false)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Check if MIX slice is powered                                            */
/*--------------------------------------------------------------------------*/
bool __wrap_SRC_MixIsPwrSwitchOn(uint32_t srcMixIdx)
{
    bool status;

    /* Call original function */
    status = __real_SRC_MixIsPwrSwitchOn(srcMixIdx);

    SM_TEST_MODE_ERR(SM_TEST_MODE_EXEC_LVL1, false)

    /* Return status */
    return status;
}

