/*
** ###################################################################
**
**     Copyright 2023 NXP
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

/*==========================================================================*/
/* File containing the implementation of the device pins.                   */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

uint32_t s_pinMux[DEV_SM_NUM_PIN];
uint32_t s_pinConfig[DEV_SM_NUM_PIN];
uint32_t s_pinDaisy[DEV_SM_NUM_DAISY];

/*--------------------------------------------------------------------------*/
/* Return pin name                                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PinNameGet(uint32_t identifier, string *pinNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_PIN] =
    {
        [DEV_SM_PIN_0] = "pin0",
        [DEV_SM_PIN_1] = "pin1",
        [DEV_SM_PIN_2] = "pin2",
        [DEV_SM_PIN_3] = "pin3"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_PIN);

    /* Check domain */
    if (identifier >= DEV_SM_NUM_PIN)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *pinNameAddr = s_name[identifier];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set pin config                                                           */
/*--------------------------------------------------------------------------*/
void DEV_SM_PinConfigSet(uint32_t type, uint32_t identifier, uint32_t value)
{
    /* Handle Mux */
    if (type == DEV_SM_PIN_TYPE_MUX)
    {
        if (identifier < DEV_SM_NUM_PIN)
        {
            s_pinMux[identifier] = value;
        }
    }

    /* Handle Config */
    else if (type == DEV_SM_PIN_TYPE_CONFIG)
    {
        if (identifier < DEV_SM_NUM_PIN)
        {
            s_pinConfig[identifier] = value;
        }
    }

    /* Handle Daisy */
    else if (type == DEV_SM_PIN_TYPE_DAISY)
    {
        if (identifier < DEV_SM_NUM_DAISY)
        {
            s_pinDaisy[identifier] = value;
        }
    }

    /* Else */
    else
    {
        ; /* Intentional empty else */
    }
}

/*--------------------------------------------------------------------------*/
/* Get pin config                                                           */
/*--------------------------------------------------------------------------*/
void DEV_SM_PinConfigGet(uint32_t type, uint32_t identifier, uint32_t *value)
{
    /* Handle Mux */
    if (type == DEV_SM_PIN_TYPE_MUX)
    {
        if (identifier < DEV_SM_NUM_PIN)
        {
            *value = s_pinMux[identifier];
        }
    }

    /* Handle Config */
    else if (type == DEV_SM_PIN_TYPE_CONFIG)
    {
        if (identifier < DEV_SM_NUM_PIN)
        {
            *value = s_pinConfig[identifier];
        }
    }

    /* Handle Daisy */
    else if (type == DEV_SM_PIN_TYPE_DAISY)
    {
        if (identifier < DEV_SM_NUM_DAISY)
        {
            *value = s_pinDaisy[identifier];
        }
    }

    /* Else */
    else
    {
        ; /* Intentional empty else */
    }
}

