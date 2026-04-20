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
/* Unit test for the device SM API.                                         */
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
/* Test device SM fuse                                                      */
/*--------------------------------------------------------------------------*/
void TEST_DevSmFuse(void)
{
    printf("**** Device SM Fuse Tests ***\n\n");

#ifdef HAS_FUSE_GET_SPEED
    printf("DEV_SM_FuseSpeedGet() freq: %u\n", DEV_SM_FuseSpeedGet());
    uint32_t val = DEV_SM_FuseGet(DEV_SM_FUSE_SPEED_GRADING);
    DEV_SM_FuseSet(DEV_SM_FUSE_SPEED_GRADING, 0U);
    (void) DEV_SM_FuseSpeedGet();
    DEV_SM_FuseSet(DEV_SM_FUSE_SPEED_GRADING, 1U);
    (void) DEV_SM_FuseSpeedGet();
    DEV_SM_FuseSet(DEV_SM_FUSE_SPEED_GRADING, val);
#endif

#ifndef SIMU
    /* Max number of fuses */
    NECHECK(DEV_SM_FuseInfoGet(DEV_SM_NUM_OTP, NULL), SM_ERR_NOT_FOUND);
#endif

#ifdef DEV_SM_PD_A55C0
    (void) DEV_SM_FusePdDisabled(DEV_SM_PD_A55C0);
#endif
#ifdef DEV_SM_FUSE_A55_CORE0_DISABLE
    (void) DEV_SM_FuseCpuDisabled(DEV_SM_FUSE_A55_CORE0_DISABLE);
#endif

    printf("\n");
}

