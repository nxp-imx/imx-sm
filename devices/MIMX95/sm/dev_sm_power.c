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
/* File containing the implementation of the device power domains.          */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Initialize CPU domains                                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerInit(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Init power states */
    for (uint32_t pwrId = 0U; pwrId < DEV_SM_NUM_POWER; pwrId++)
    {
        /* Initialize PWR interfaces */
        if (!PWR_Init(pwrId))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    /* Disable AutoAck of SM LP handshakes */
    BLK_CTRL_S_AONMIX->SM_LP_HANDSHAKE_STATUS =
        BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK(0U);

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return power domain name                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerDomainNameGet(uint32_t domainId, string *domainNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t maxLen = 0;

    static string const name[DEV_SM_NUM_POWER] =
    {
        [DEV_SM_PD_ANA] =       "ANA",
        [DEV_SM_PD_AON] =       "AON",
        [DEV_SM_PD_BBSM] =      "BBSM",
        [DEV_SM_PD_CAMERA] =    "CAMERA",
        [DEV_SM_PD_CCMSRCGPC] = "CCMSRCGPC",
        [DEV_SM_PD_A55C0] =     "A55C0",
        [DEV_SM_PD_A55C1] =     "A55C1",
        [DEV_SM_PD_A55C2] =     "A55C2",
        [DEV_SM_PD_A55C3] =     "A55C3",
        [DEV_SM_PD_A55C4] =     "A55C4",
        [DEV_SM_PD_A55C5] =     "A55C5",
        [DEV_SM_PD_A55P] =      "A55P",
        [DEV_SM_PD_DDR] =       "DDR",
        [DEV_SM_PD_DISPLAY] =   "DISPLAY",
        [DEV_SM_PD_GPU] =       "GPU",
        [DEV_SM_PD_HSIO_TOP] =  "HSIO_TOP",
        [DEV_SM_PD_HSIO_WAON] = "HSIO_WAON",
        [DEV_SM_PD_M7] =        "M7",
        [DEV_SM_PD_NETC] =      "NETC",
        [DEV_SM_PD_NOC] =       "NOC",
        [DEV_SM_PD_NPU] =       "NPU",
        [DEV_SM_PD_VPU] =       "VPU",
        [DEV_SM_PD_WAKEUP] =    "WAKEUP"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &maxLen, name, DEV_SM_NUM_POWER);

    /* Check domain */
    if (domainId >= DEV_SM_NUM_POWER)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *domainNameAddr = name[domainId];
    }

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
    static int32_t maxLen = 0;

    static string const name[DEV_SM_NUM_POWER_STATE] =
    {
        [DEV_SM_POWER_STATE_OFF] = "off",
        [DEV_SM_POWER_STATE_ON] =  "on"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &maxLen, name, DEV_SM_NUM_POWER_STATE);

    /* Check state */
    if (powerState >= DEV_SM_NUM_POWER_STATE)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *stateNameAddr = name[powerState];
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
        switch(powerState)
        {
            case DEV_SM_POWER_STATE_ON:
                if (PWR_IsParentPowered(domainId))
                {
                    if (SRC_MixSoftPowerUp(domainId))
                    {
                        DEV_SM_PowerUpPost(domainId);
                    }
                }
                else
                {
                    status = SM_ERR_POWER;
                }
                break;
            case DEV_SM_POWER_STATE_OFF:
                if (!PWR_AnyChildPowered(domainId))
                {
                    DEV_SM_PowerDownPre(domainId);
                    SRC_MixSoftPowerDown(domainId);
                }
                else
                {
                    status = SM_ERR_POWER;
                }
                break;
            default:
                status = SM_ERR_INVALID_PARAMETERS;
                break;
        }
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
        if (SRC_MixIsPwrReady(domainId))
        {
            *powerState = DEV_SM_POWER_STATE_ON;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get power domain retention mask                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerRetMaskGet(uint32_t domainId, uint32_t *retMask)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check domain */
    if (!(SRC_MemMaskGet(domainId, retMask)))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

