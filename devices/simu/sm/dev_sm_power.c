/*
** ###################################################################
**
**     Copyright 2023-2024 NXP
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
/* File containing the implementation of the device power domains.          */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint8_t s_powerState[DEV_SM_NUM_POWER];

/*--------------------------------------------------------------------------*/
/* Return power domain name                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerDomainNameGet(uint32_t domainId, string *domainNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_POWER] =
    {
        [DEV_SM_PD_0] = "pd0",
        [DEV_SM_PD_1] = "pd1",
        [DEV_SM_PD_2] = "pd2",
        [DEV_SM_PD_3] = "pd3",
        [DEV_SM_PD_4] = "pd4",
        [DEV_SM_PD_5] = "pd5",
        [DEV_SM_PD_6] = "pd6"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_POWER);

    /* Check domain */
    if (domainId >= DEV_SM_NUM_POWER)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *domainNameAddr = s_name[domainId];
    }

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return power state name                                                  */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerStateNameGet(uint32_t powerState, string *stateNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_POWER_STATE] =
    {
        [DEV_SM_POWER_STATE_OFF] = "off",
        [DEV_SM_POWER_STATE_P1] =  "p1",
        [DEV_SM_POWER_STATE_P2] =  "p2",
        [DEV_SM_POWER_STATE_ON] =  "on"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_POWER_STATE);

    /* Check state */
    if (powerState >= DEV_SM_NUM_POWER_STATE)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *stateNameAddr = s_name[powerState];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set power domain state                                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerStateSet(uint32_t domainId, uint8_t powerState)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check domain */
    if (domainId >= DEV_SM_NUM_POWER)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Handle post power on loads */
        if ((s_powerState[domainId] == DEV_SM_POWER_STATE_OFF)
            && (powerState != DEV_SM_POWER_STATE_OFF))
        {
            status = DEV_SM_PowerUpPost(domainId);
        }

        /* Handle pre power down tasks */
        if ((s_powerState[domainId] != DEV_SM_POWER_STATE_OFF)
            && (powerState == DEV_SM_POWER_STATE_OFF))
        {
            status = DEV_SM_PowerDownPre(domainId);
        }

        s_powerState[domainId] = powerState;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get power domain state                                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerStateGet(uint32_t domainId, uint8_t *powerState)
{
    int32_t status = SM_ERR_SUCCESS;
    *powerState = DEV_SM_POWER_STATE_OFF;

    /* Check domain */
    if (domainId >= DEV_SM_NUM_POWER)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        *powerState = s_powerState[domainId];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set power domain retention mode                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerRetModeSet(uint32_t domainId, uint32_t memRetMask)
{
    /* Return status */
    return SM_ERR_SUCCESS;
}

/*--------------------------------------------------------------------------*/
/* Get power domain retention mask                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerRetMaskGet(uint32_t domainId, uint32_t *retMask)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check domain */
    if (domainId >= DEV_SM_NUM_POWER)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        *retMask = 1UL << domainId;
    }

    /* Return status */
    return status;
}

