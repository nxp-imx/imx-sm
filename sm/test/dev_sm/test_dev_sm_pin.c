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
/* Unit test for the device SM Pin API.                                     */
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
/* Test device SM Pin                                                       */
/*--------------------------------------------------------------------------*/
void TEST_DevSmPin(void)
{

    /* Device tests */
    printf("**** Device SM Pin API Tests ***\n\n");

    /* Test API bounds */
    printf("\n**** Device SM Pin API Err Tests ***\n\n");

    uint32_t value = 0U;
    const char *name[15];
    int32_t len = 0;

    /* Branch Testing */

    /* Case 1: type=MUX identifier=DEV_SM_NUM_PIN */
    printf("DEV_SM_PinConfigGet(DEV_SM_PIN_TYPE_MUX, SM (0U))\n");
    DEV_SM_PinConfigGet(DEV_SM_PIN_TYPE_MUX, 0U, &value);

    /* Invalid Identifiers */
    DEV_SM_PinConfigSet(DEV_SM_PIN_TYPE_MUX, DEV_SM_NUM_PIN, value);
    DEV_SM_PinConfigGet(DEV_SM_PIN_TYPE_MUX, DEV_SM_NUM_PIN, &value);

    /* Case 2: type=CONFIG identifier=DEV_SM_NUM_PIN */
    printf("DEV_SM_PinConfigGet(DEV_SM_PIN_TYPE_CONFIG, SM (0U))\n");
    DEV_SM_PinConfigGet(DEV_SM_PIN_TYPE_CONFIG, 0U, &value);

    /* Invalid Identifiers */
    DEV_SM_PinConfigSet(DEV_SM_PIN_TYPE_CONFIG, DEV_SM_NUM_PIN, value);
    DEV_SM_PinConfigGet(DEV_SM_PIN_TYPE_CONFIG, DEV_SM_NUM_PIN, &value);

    /* Case 3: type=DAISY identifier=DEV_SM_NUM_PIN */
    printf("DEV_SM_PinConfigGet(DEV_SM_PIN_TYPE_DAISY, SM (0U))\n");
    DEV_SM_PinConfigGet(DEV_SM_PIN_TYPE_DAISY, 0U, &value);

    /* Invalid Identifiers */
    DEV_SM_PinConfigSet(DEV_SM_PIN_TYPE_DAISY, DEV_SM_NUM_PIN, value);
    DEV_SM_PinConfigGet(DEV_SM_PIN_TYPE_DAISY, DEV_SM_NUM_PIN, &value);

    /* Case 4: type=invalid */
    DEV_SM_PinConfigSet(8U, DEV_SM_NUM_PIN, value);
    DEV_SM_PinConfigGet(8U, DEV_SM_NUM_PIN, &value);

    /* Invalid PIN Identifier */
    NECHECK(DEV_SM_PinNameGet(DEV_SM_NUM_PIN, &name[0], &len),
        SM_ERR_NOT_FOUND);

    printf("\n");
}

