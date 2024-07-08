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
/* File containing the implementation of the Logical Machine Manager        */
/* power domains.                                                           */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Return power domain name                                                 */
/*--------------------------------------------------------------------------*/
int32_t LMM_PowerDomainNameGet(uint32_t lmId, uint32_t domainId,
    string *domainNameAddr, int32_t *len)
{
    /* Just passthru to board/device */
    return SM_POWERDOMAINNAMEGET(domainId, domainNameAddr, len);
}

/*--------------------------------------------------------------------------*/
/* Return power state name                                                  */
/*--------------------------------------------------------------------------*/
int32_t LMM_PowerStateNameGet(uint32_t lmId, uint32_t powerState,
    string *stateNameAddr, int32_t *len)
{
    /* Just passthru to board/device */
    return SM_POWERSTATENAMEGET(powerState, stateNameAddr, len);
}

/*--------------------------------------------------------------------------*/
/* Set power domain state                                                   */
/*--------------------------------------------------------------------------*/
int32_t LMM_PowerStateSet(uint32_t lmId, uint32_t domainId,
    uint8_t powerState)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check parameters */
    if (lmId >= SM_NUM_LM)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Check parameters */
    if ((status == SM_ERR_SUCCESS) && (domainId >= SM_NUM_POWER))
    {
        status = SM_ERR_NOT_FOUND;
    }

    if (status == SM_ERR_SUCCESS)
    {
        static uint8_t s_powerState[SM_NUM_POWER][SM_NUM_LM];
        uint8_t newPowerState = 0U;

        /* Record new state */
        s_powerState[domainId][lmId] = (uint8_t) (powerState & 0xFFU);

        /* Aggregate power state */
        for (uint32_t lm = 0U; lm < SM_NUM_LM; lm++)
        {
            newPowerState = MAX(newPowerState, s_powerState[domainId][lm]);
        }

        /* Inform device of power state, device will check if changed */
        status = SM_POWERSTATESET(domainId, newPowerState);
    }

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get power domain state                                                   */
/*--------------------------------------------------------------------------*/
int32_t LMM_PowerStateGet(uint32_t lmId, uint32_t domainId,
    uint8_t *powerState)
{
    /* Just passthru to board/device */
    return SM_POWERSTATEGET(domainId, powerState);
}

