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
/* Unit test for the SMT driver.                                            */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test.h"
#include "rpc_smt.h"
#include "smt.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test SMT driver                                                          */
/*--------------------------------------------------------------------------*/
void TEST_Smt(void)
{
    printf("**** SMT Tests ***\n\n");

    /* Invalid parameter */
    NECHECK(SMT_ChannelConfig(5000U, 0U, 0U, 0U),
        SM_ERR_INVALID_PARAMETERS);

    /* Init out of range */
    NECHECK(RPC_SMT_Init(SM_NUM_SMT_CHN, false, 0U),
        SM_ERR_OUT_OF_RANGE);

    /* Abort out of range */
    NECHECK(RPC_SMT_IsAborted(SM_NUM_SMT_CHN),
        SM_ERR_OUT_OF_RANGE);

    /* Tx out of range */
    NECHECK(RPC_SMT_Tx(SM_NUM_SMT_CHN, 0U, false, false),
        SM_ERR_GENERIC_ERROR);
    NECHECK(RPC_SMT_Tx(0U, 5000U, false, false),
        SM_ERR_PROTOCOL_ERROR);

    /* Rx out of range */
    void *msgRx = NULL;
    uint32_t len = 0U;
    NECHECK(RPC_SMT_Rx(SM_NUM_SMT_CHN, &msgRx, &len, false),
        SM_ERR_GENERIC_ERROR);
    NECHECK(RPC_SMT_Rx(0U, &msgRx, &len, false),
        SM_ERR_PROTOCOL_ERROR);

    /* Doorbell out of range */
    (void) RPC_SMT_DoorbellState(0U);
    (void) RPC_SMT_DoorbellState(SM_NUM_SMT_CHN);

    printf("\n");
}

