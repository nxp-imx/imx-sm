/*
** ###################################################################
**
**     Copyright 2026 NXP
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/* Includes */

#include "dev_sm.h"
#include "sm_test_mode.h"

/* External real functions */

extern int32_t __real_DEV_SM_ClockNameGet(uint32_t clockId,
    string *clockNameAddr, int32_t *len);
extern int32_t __real_DEV_SM_ClockDescribe(uint32_t clockId,
    dev_sm_clock_range_t *range);
extern int32_t __real_DEV_SM_ClockParentGet(uint32_t clockId,
    uint32_t *parent);

/*--------------------------------------------------------------------------*/
/* Return clock name                                                        */
/*--------------------------------------------------------------------------*/
int32_t __wrap_DEV_SM_ClockNameGet(uint32_t clockId, string *clockNameAddr,
    int32_t *len)
{
    int32_t status;

    /* Call original function */
    status = __real_DEV_SM_ClockNameGet(clockId, clockNameAddr, len);

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return supported clock range                                             */
/*--------------------------------------------------------------------------*/
int32_t __wrap_DEV_SM_ClockDescribe(uint32_t clockId,
    dev_sm_clock_range_t *range)
{
    int32_t status;

    /* Call original function */
    status = __real_DEV_SM_ClockDescribe(clockId, range);

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL2, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get clock parent                                                         */
/*--------------------------------------------------------------------------*/
int32_t __wrap_DEV_SM_ClockParentGet(uint32_t clockId, uint32_t *parent)
{
    int32_t status;

    /* Call original function */
    status = __real_DEV_SM_ClockParentGet(clockId, parent);

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL2, SM_ERR_TEST)

    /* Return status */
    return status;
}

