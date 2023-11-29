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
/* File containing the implementation of the device voltages.               */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "brd_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Voltage descriptions */
static const dev_sm_voltage_range_t s_voltDesc[DEV_SM_NUM_VOLT] =
{
    [DEV_SM_VOLT_SOC] =
    {
        .lowestVolt = (int32_t) ES_SUSPEND_UV_VDD_SOC,
        .highestVolt = (int32_t) ES_ODV_UV_VDD_SOC,
        .stepSize = 50000
    },
    [DEV_SM_VOLT_ARM] =
    {
        .lowestVolt = (int32_t) ES_LOW_UV_VDD_ARM,
        .highestVolt = (int32_t) ES_ODV_UV_VDD_ARM,
        .stepSize = 50000
    }
};

/*--------------------------------------------------------------------------*/
/* Return voltage name                                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_VoltageNameGet(uint32_t domainId, string *voltNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_VOLT] =
    {
        [DEV_SM_VOLT_SOC] = "soc",
        [DEV_SM_VOLT_ARM] = "arm",
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_VOLT);

    /* Check domain */
    if (domainId >= DEV_SM_NUM_VOLT)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *voltNameAddr = s_name[domainId];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return voltage mode name                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_VoltageModeNameGet(uint32_t voltMode, string *modeNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_VOLT_MODE] =
    {
        [DEV_SM_VOLT_MODE_OFF] = "off",
        [DEV_SM_VOLT_MODE_ON] =  "on"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_VOLT_MODE);

    /* Check mode */
    if (voltMode >= DEV_SM_NUM_VOLT_MODE)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *modeNameAddr = s_name[voltMode];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return supported voltage range                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_VoltageDescribe(uint32_t domainId,
    dev_sm_voltage_range_t *range)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check domain */
    if (domainId < DEV_SM_NUM_VOLT)
    {
        *range = s_voltDesc[domainId];
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set voltage mode                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_VoltageModeSet(uint32_t domainId, uint8_t voltMode)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check domain */
    if (domainId < DEV_SM_NUM_VOLT)
    {
        /* Set level */
        status = BRD_SM_SupplyModeSet(domainId, voltMode);
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
int32_t DEV_SM_VoltageModeGet(uint32_t domainId, uint8_t *voltMode)
{
    int32_t status = SM_ERR_SUCCESS;
    uint8_t mode = 0U;

    /* Check domain */
    if (domainId < DEV_SM_NUM_VOLT)
    {
        /* Get level */
        status = BRD_SM_SupplyModeGet(domainId, &mode);
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return voltage */
    if (status == SM_ERR_SUCCESS)
    {
        *voltMode = mode;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set voltage level                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_VoltageLevelSet(uint32_t domainId, int32_t voltageLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check domain */
    if (domainId < DEV_SM_NUM_VOLT)
    {
        const dev_sm_voltage_range_t *range
            = &s_voltDesc[domainId];

        /* Check voltage range */
        if ((voltageLevel >= range->lowestVolt)
            && (voltageLevel <= range->highestVolt))
        {
            /* Change level */
            status = BRD_SM_SupplyLevelSet(domainId,
                (uint32_t) voltageLevel);
        }
        else
        {
            status = SM_ERR_INVALID_PARAMETERS;
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
/* Get voltage level                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_VoltageLevelGet(uint32_t domainId, int32_t *voltageLevel)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t microVolt = 0U;

    /* Check domain */
    if (domainId < DEV_SM_NUM_VOLT)
    {
        /* Get level */
        status = BRD_SM_SupplyLevelGet(domainId, &microVolt);
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return voltage */
    if (status == SM_ERR_SUCCESS)
    {
        *voltageLevel = (int32_t) microVolt;
    }

    /* Return status */
    return status;
}

