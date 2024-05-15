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
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_POWER] =
    {
        [DEV_SM_PD_ANA] =       "ana",
        [DEV_SM_PD_AON] =       "aon",
        [DEV_SM_PD_BBSM] =      "bbsm",
        [DEV_SM_PD_CAMERA] =    "camera",
        [DEV_SM_PD_CCMSRCGPC] = "ccmsrcgpc",
        [DEV_SM_PD_A55C0] =     "a55c0",
        [DEV_SM_PD_A55C1] =     "a55c1",
        [DEV_SM_PD_A55C2] =     "a55c2",
        [DEV_SM_PD_A55C3] =     "a55c3",
        [DEV_SM_PD_A55C4] =     "a55c4",
        [DEV_SM_PD_A55C5] =     "a55c5",
        [DEV_SM_PD_A55P] =      "a55p",
        [DEV_SM_PD_DDR] =       "ddr",
        [DEV_SM_PD_DISPLAY] =   "display",
        [DEV_SM_PD_GPU] =       "gpu",
        [DEV_SM_PD_HSIO_TOP] =  "hsio_top",
        [DEV_SM_PD_HSIO_WAON] = "hsio_waon",
        [DEV_SM_PD_M7] =        "m7",
        [DEV_SM_PD_NETC] =      "netc",
        [DEV_SM_PD_NOC] =       "noc",
        [DEV_SM_PD_NPU] =       "npu",
        [DEV_SM_PD_VPU] =       "vpu",
        [DEV_SM_PD_WAKEUP] =    "wakeup"
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
        switch (powerState)
        {
            case DEV_SM_POWER_STATE_ON:
                if (PWR_IsParentPowered(domainId))
                {
                    if (SRC_MixSoftPowerUp(domainId))
                    {
                        status = DEV_SM_PowerUpPost(domainId);
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
                    if (DEV_SM_PowerDownPre(domainId) == SM_ERR_SUCCESS)
                    {
                        SRC_MixSoftPowerDown(domainId);
                    }
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
/* Set power domain retention mode                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerRetModeSet(uint32_t domainId, uint32_t memRetMask)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check domain */
    if (!(SRC_MemRetentionModeSet(domainId, memRetMask)))
    {
        status = SM_ERR_NOT_FOUND;
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

