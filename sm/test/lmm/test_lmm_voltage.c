/*
** ###################################################################
**
** Copyright 2023 NXP
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
/* Unit test for the device SM System API.                                  */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test.h"
#include "lmm.h"
#include "sm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test device SM Sys                                                       */
/*--------------------------------------------------------------------------*/
void TEST_LmmVoltage(void)
{
    printf("\n**** LMM Voltage API Tests ***\n\n");

    printf("\n**** LMM Voltage API Tests ***\n\n");

    /* Branch -- Invalid Params ------------------------------------ */

    /* Case 1: Invalid lmId */
    NECHECK(LMM_VoltageModeSet(SM_NUM_LM, 0U, 0U),
        SM_ERR_INVALID_PARAMETERS);
    /* Case 2: Invalid domainId */
    NECHECK(LMM_VoltageModeSet(0U, SM_NUM_VOLT, 0U),
        SM_ERR_INVALID_PARAMETERS);
    /* Case 3: Invalid lmId && domainId */
    NECHECK(LMM_VoltageModeSet(SM_NUM_LM, SM_NUM_VOLT, 0U),
        SM_ERR_INVALID_PARAMETERS);
}

