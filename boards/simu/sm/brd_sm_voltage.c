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

/*==========================================================================*/
/* File containing the implementation of the board voltages.                */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "brd_sm.h"

/* Local defines */

/* Local types */

/* Local variables */
static int32_t s_voltLevel[SM_NUM_VOLT];
static uint8_t s_voltMode[SM_NUM_VOLT];

/*--------------------------------------------------------------------------*/
/* Return voltage name                                                      */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageNameGet(uint32_t domainId, string *voltNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[BRD_SM_NUM_VOLT] =
    {
        "brd_volt0",
        "brd_volt1",
        "brd_volt2"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, BRD_SM_NUM_VOLT);

    /* Check to see if domain is within bounds*/
    if (domainId < SM_NUM_VOLT)
    {
        /* Check if device or board */
        if (domainId < DEV_SM_NUM_VOLT)
        {
            status = DEV_SM_VoltageNameGet(domainId, voltNameAddr, len);
        }
        else
        {
            /* Return pointer to name */
            *voltNameAddr = s_name[domainId - DEV_SM_NUM_VOLT];
        }
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return supported voltage range                                           */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageDescribe(uint32_t domainId,
    dev_sm_voltage_range_t *range)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Get voltage range/info */
    switch (domainId)
    {
        case DEV_SM_VOLT_0:
        case DEV_SM_VOLT_1:
        case DEV_SM_VOLT_2:
            status = DEV_SM_VoltageDescribe(domainId, range);
            break;
        case BRD_SM_VOLT_0:
        case BRD_SM_VOLT_1:
        case BRD_SM_VOLT_2:
            range->lowestVolt = 1000000;
            range->highestVolt = 5000000;
            range->stepSize = 1000;
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set voltage mode                                                         */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageModeSet(uint32_t domainId, uint8_t voltMode)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Load for tests */
    if (domainId < SM_NUM_VOLT)
    {
        s_voltMode[domainId] = voltMode;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get voltage mode                                                         */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageModeGet(uint32_t domainId, uint8_t *voltMode)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Load for tests */
    if (domainId < SM_NUM_VOLT)
    {
        *voltMode = s_voltMode[domainId];
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set voltage level                                                        */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageLevelSet(uint32_t domainId, int32_t voltageLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check voltageLevel is positive */
    if (CHECK_I32_POSITIVE(voltageLevel))
    {
        /* Load for tests */
        if (domainId < SM_NUM_VOLT)
        {
            s_voltLevel[domainId] = voltageLevel;
        }
        else
        {
            status = SM_ERR_NOT_FOUND;
        }
    }
    else
    {
        /* Set the status if voltageLevel is negative */
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get voltage level                                                        */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageLevelGet(uint32_t domainId, int32_t *voltageLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Load for tests */
    if (domainId < SM_NUM_VOLT)
    {
        *voltageLevel = s_voltLevel[domainId];
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

