/*
** ###################################################################
**
** Copyright 2025-2026 NXP
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
/* Unit test for the MB_MU driver.                                          */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test.h"
#include "mb_mu.h"
#include "config_mb_mu.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

void TEST_MbMu(void)
{
    printf("**** MB MU Tests ***\n\n");

    /* Init out of range */
    NECHECK(MB_MU_Init(SM_NUM_MB_MU, 0U, false, 0U),
        SM_ERR_OUT_OF_RANGE);
    NECHECK(MB_MU_Init(0U, SM_NUM_MB_MU_DB, false, 0U),
        SM_ERR_OUT_OF_RANGE);

    /* Ring out of range */
    NECHECK(MB_MU_DoorbellRing(SM_NUM_MB_MU, 0U),
        SM_ERR_OUT_OF_RANGE);
    NECHECK(MB_MU_DoorbellRing(0U, SM_NUM_MB_MU_DB),
        SM_ERR_OUT_OF_RANGE);

    /* Abort out of range */
    NECHECK(MB_MU_IsAborted(SM_NUM_MB_MU, 0U),
        SM_ERR_OUT_OF_RANGE);
    NECHECK(MB_MU_IsAborted(0U, SM_NUM_MB_MU_DB),
        SM_ERR_OUT_OF_RANGE);

    /* Get doorbell state */
    (void) MB_MU_DoorbellState(0U, 0U);
    (void) MB_MU_DoorbellState(SM_NUM_MB_MU, 0U);
    (void) MB_MU_DoorbellState(0U, 100U);

    printf("\n");
}

