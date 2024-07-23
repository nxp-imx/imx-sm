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
/* Unit test for the board SM control API.                                  */
/*==========================================================================*/


/* Include Config */

/* Includes */

#include "test.h"

#ifdef SIMU
#include "brd_sm_control.h"
#endif

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test device SM control                                                   */
/*--------------------------------------------------------------------------*/
void TEST_BrdSmControl(void)
{
#ifdef SIMU
    printf("**** Board SM Control API Tests ***\n\n");
    {
        uint32_t numRtn = 0U;
        uint32_t rtn[1] = { 1 };

        printf("BRD_SM_ControlGet(BRD_SM_CTRL_0)\n");
        CHECK(BRD_SM_ControlGet(BRD_SM_CTRL_0, &numRtn, rtn));
        printf("numRtn: %u rtn: %u\n", numRtn, rtn[0]);

        numRtn = 1U;
        printf("BRD_SM_ControlSet(BRD_SM_CTRL_0)\n");
        CHECK(BRD_SM_ControlSet(BRD_SM_CTRL_0, numRtn, rtn));
    }

    /* Test API bounds */
    printf("\n**** Board SM Control API Err Tests ***\n\n");

    /* Test invalid ctrlId */
    {
        uint32_t numRtn = 0U;
        uint32_t rtn[1] = { 0 };

        printf("BRD_SM_ControlGet(SM_NUM_CTRL)\n");
        NECHECK(BRD_SM_ControlGet(SM_NUM_CTRL, &numRtn, rtn),
            SM_ERR_NOT_FOUND);

        printf("BRD_SM_ControlGet(BRD_SM_CTRL_TEST)\n");
        NECHECK(BRD_SM_ControlGet(BRD_SM_CTRL_TEST, &numRtn, rtn),
            SM_ERR_NOT_SUPPORTED);

        numRtn = 0U;
        printf("BRD_SM_ControlSet(BRD_SM_CTRL_0)\n");
        NECHECK(BRD_SM_ControlSet(BRD_SM_CTRL_0, numRtn, rtn),
            SM_ERR_INVALID_PARAMETERS);

        printf("BRD_SM_ControlSet(SM_NUM_CTRL)\n");
        NECHECK(BRD_SM_ControlSet(SM_NUM_CTRL, numRtn, rtn),
            SM_ERR_NOT_FOUND);
    }

    printf("\n");
#endif
}

