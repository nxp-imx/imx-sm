/*
** ###################################################################
**
** Copyright 2024 NXP
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
/* Unit test for the LMM fault API.                                         */
/*==========================================================================*/

/* LM_00010 */

/* Include Config */

/* Includes */

#include "test.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test LMM fault                                                           */
/*--------------------------------------------------------------------------*/
void TEST_LmmFault(void)
{
    /* LMM tests */
    printf("**** LMM Fault API Tests ***\n\n");

#ifdef SIMU
    /* FaultReactionGet */
    {
        dev_sm_rst_rec_t resetRec = { 0 };

        resetRec.errId = DEV_SM_FAULT_0;
        uint32_t reaction = 0;
        uint32_t lm = 0;

        printf("LMM_FaultReactionGet()\n");
        CHECK(LMM_FaultReactionGet(resetRec, &reaction, &lm));
        printf("reaction: %u lm: %u\n", reaction, lm);

        resetRec.errId = DEV_SM_FAULT_1;

        CHECK(LMM_FaultReactionGet(resetRec, &reaction, &lm));
        printf("reaction: %u lm: %u\n", reaction, lm);

        resetRec.errId = DEV_SM_FAULT_2;

        CHECK(LMM_FaultReactionGet(resetRec, &reaction, &lm));
        printf("reaction: %u lm: %u\n", reaction, lm);

        resetRec.errId = DEV_SM_FAULT_3;

        CHECK(LMM_FaultReactionGet(resetRec, &reaction, &lm));
        printf("reaction: %u lm: %u\n", reaction, lm);

        resetRec.errId = DEV_SM_FAULT_4;

        CHECK(LMM_FaultReactionGet(resetRec, &reaction, &lm));
        printf("reaction: %u lm: %u\n", reaction, lm);

        resetRec.errId = DEV_SM_FAULT_5;

        CHECK(LMM_FaultReactionGet(resetRec, &reaction, &lm));
        printf("reaction: %u lm: %u\n", reaction, lm);

        resetRec.errId = DEV_SM_FAULT_6;

        CHECK(LMM_FaultReactionGet(resetRec, &reaction, &lm));
        printf("reaction: %u lm: %u\n", reaction, lm);

        resetRec.errId = DEV_SM_FAULT_7;

        CHECK(LMM_FaultReactionGet(resetRec, &reaction, &lm));
        printf("reaction: %u lm: %u\n", reaction, lm);
    }
#endif

    printf("\n");
}

