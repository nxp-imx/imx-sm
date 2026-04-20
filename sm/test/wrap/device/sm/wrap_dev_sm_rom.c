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

extern int32_t __real_DEV_SM_RomHandoverGet(const rom_handover_t **handover);
extern int32_t __real_DEV_SM_RomPassoverGet(const rom_passover_t **passover);
extern int32_t __real_DEV_SM_RomStageSet(uint32_t stage);
extern int32_t __real_DEV_SM_RomContainerSet(uint32_t container);

/*--------------------------------------------------------------------------*/
/* Return handover data                                                     */
/*--------------------------------------------------------------------------*/
int32_t __wrap_DEV_SM_RomHandoverGet(const rom_handover_t **handover)
{
    int32_t status;

    /* Call original function */
    status = __real_DEV_SM_RomHandoverGet(handover);

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return passover data                                                     */
/*--------------------------------------------------------------------------*/
int32_t __wrap_DEV_SM_RomPassoverGet(const rom_passover_t **passover)
{
    int32_t status;

    /* Call original function */
    status = __real_DEV_SM_RomPassoverGet(passover);

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set boot stage                                                           */
/*--------------------------------------------------------------------------*/
int32_t __wrap_DEV_SM_RomStageSet(uint32_t stage)
{
    int32_t status;

    /* Call original function */
    status = __real_DEV_SM_RomStageSet(stage);

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set boot container                                                       */
/*--------------------------------------------------------------------------*/
int32_t __wrap_DEV_SM_RomContainerSet(uint32_t container)
{
    int32_t status;

    /* Call original function */
    status = __real_DEV_SM_RomContainerSet(container);

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL2, SM_ERR_TEST)

    /* Return status */
    return status;
}

