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
/* voltages.                                                                */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Init LMM voltage management                                              */
/*--------------------------------------------------------------------------*/
int32_t LMM_VoltageInit(void)
{
    /* Return status */
    return SM_ERR_SUCCESS;
}

/*--------------------------------------------------------------------------*/
/* Return voltage name                                                      */
/*--------------------------------------------------------------------------*/
int32_t LMM_VoltageNameGet(uint32_t lmId, uint32_t domainId,
    string *voltNameAddr, int32_t *len)
{
    /* Just passthru to device */
    return SM_VOLTAGENAMEGET(domainId, voltNameAddr, len);
}

/*--------------------------------------------------------------------------*/
/* Return voltage mode name                                                 */
/*--------------------------------------------------------------------------*/
int32_t LMM_VoltageModeNameGet(uint32_t lmId, uint32_t voltMode,
    string *modeNameAddr, int32_t *len)
{
    /* Just passthru to board/device */
    return SM_VOLTAGEMODENAMEGET(voltMode, modeNameAddr, len);
}

/*--------------------------------------------------------------------------*/
/* Return supported voltage range                                           */
/*--------------------------------------------------------------------------*/
int32_t LMM_VoltageDescribe(uint32_t lmId, uint32_t domainId,
    dev_sm_voltage_range_t *range)
{
    /* Just passthru to device */
    return SM_VOLTAGEDESCRIBE(domainId, range);
}

/*--------------------------------------------------------------------------*/
/* Set voltage mode                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_VoltageModeSet(uint32_t lmId, uint32_t domainId,
    uint8_t voltMode)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check parameters */
    if ((lmId >= SM_NUM_LM) || (domainId >= SM_NUM_VOLT))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    if (status == SM_ERR_SUCCESS)
    {
        static uint8_t s_voltMode[SM_NUM_VOLT][SM_NUM_LM];
        uint8_t newVoltMode = DEV_SM_VOLT_MODE_OFF;

        /* Record new state */
        s_voltMode[domainId][lmId] = voltMode;

        /* Aggregate voltage mode */
        for (uint32_t lm = 0U; lm < SM_NUM_LM; lm++)
        {
            newVoltMode = MAX(newVoltMode, s_voltMode[domainId][lm]);
        }

        /* Inform device of voltage mode, device will check if changed */
        status = SM_VOLTAGEMODESET(domainId, newVoltMode);
    }

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get voltage mode                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_VoltageModeGet(uint32_t lmId, uint32_t domainId,
    uint8_t *voltMode)
{
    /* Just passthru to device */
    return SM_VOLTAGEMODEGET(domainId, voltMode);
}

/*--------------------------------------------------------------------------*/
/* Set voltage level                                                        */
/*--------------------------------------------------------------------------*/
int32_t LMM_VoltageLevelSet(uint32_t lmId, uint32_t domainId,
    int32_t voltageLevel)
{
    /* Not shared, just passthru to device */
    return SM_VOLTAGELEVELSET(domainId, voltageLevel);
}

/*--------------------------------------------------------------------------*/
/* Get voltage level                                                        */
/*--------------------------------------------------------------------------*/
int32_t LMM_VoltageLevelGet(uint32_t lmId, uint32_t domainId,
    int32_t *voltageLevel)
{
    /* Just passthru to device */
    return SM_VOLTAGELEVELGET(domainId, voltageLevel);
}

