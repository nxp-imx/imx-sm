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
/* File containing the implementation of the device foundation functions.   */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "fsl_device_registers.h"
#include "fsl_ele.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Init device                                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_Init(uint32_t bootPerfLevel, uint32_t runPerfLevel)
{
    int32_t status;
    const rom_passover_t *romPassover = NULL;

    /* Init the system */
    status = DEV_SM_SystemInit();

    /* Init fault handling */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_FaultInit();
    }

    /* Init ELE */
    ELE_Init(MU_ELE0);

#ifndef RDC
    /* Disable RDC conditional loading */
    CONFIG_Condition(false);
#endif

    /* Initialize performance domains */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_PerfInit(bootPerfLevel, runPerfLevel);
    }

    /* Initialize power domains */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_PowerInit();
    }

    /* Release M7 */
    if ((status == SM_ERR_SUCCESS) && (SRC_MixIsPwrSwitchOn(DEV_SM_PD_M7)))
    {
        /* Release M7 */
        ELE_EnableAuxRequest(0xBU);
        status = g_eleStatus;
    }

    /* Init ROM data */
    DEV_SM_RomInit();

    /* Initialize CPU domains */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_CpuInit();
    }

    /* Initialize sensors */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_SensorInit();
    }

    /* Get ROM passover data */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_RomPassoverGet(&romPassover);
    }

    /* Init RDC */
    if ((status == SM_ERR_SUCCESS)
        && (romPassover->bootDevType != DEV_SM_ROM_BD_PRELOAD))
    {
        status = DEV_SM_RdcInit();
    }
    else
    {
        /* Check for emulation case (no ROM) */
        if (status == SM_ERR_NOT_SUPPORTED)
        {
            /* Allow boot to continue */
            status = SM_ERR_SUCCESS;
        }

        /* No FW loaded, assume ELE is in an aborted state */
        ELE_Abort();
    }

    /* Loop over powered domains and load state (BLK_CTRL, RDC, etc.) */
    if (status == SM_ERR_SUCCESS)
    {
        for (uint32_t domainId = 0U; domainId < DEV_SM_NUM_POWER;
            domainId++)
        {
            uint8_t powerState;

            /* Get power state */
            status = DEV_SM_PowerStateGet(domainId, &powerState);

            /* Powered? */
            if (powerState != DEV_SM_POWER_STATE_OFF)
            {
                status = DEV_SM_PowerUpPost(domainId);
            }

            /* Error? */
            if (status != SM_ERR_SUCCESS)
            {
                break;
            }
        }
    }

    /* Configure BBM */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_BbmInit();
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get default resource state for LM0 (SM)                                  */
/*--------------------------------------------------------------------------*/
void DEV_SM_LmmInitGet(uint32_t *numClock, const uint32_t **clockList)
{
    /* List of clocks used by SM to be kept on */
    static const uint32_t clocks[] =
    {
    };

    /* Return list */
    *numClock = ARRAY_SIZE(clocks);
    *clockList = clocks;
}

/*--------------------------------------------------------------------------*/
/* Power domain postamble for power-up                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerUpPost(uint32_t domainId)
{
    int32_t status = SM_ERR_SUCCESS;

    switch (domainId)
    {
        case DEV_SM_PD_CAMERA:
            status = DEV_SM_CameraConfigLoad();
            break;
        case DEV_SM_PD_A55P:
            status = DEV_SM_A55pConfigLoad();
            break;
        case DEV_SM_PD_A55C0:
            status = DEV_SM_A55c0ConfigLoad();
            break;
        case DEV_SM_PD_A55C1:
            status = DEV_SM_A55c1ConfigLoad();
            break;
        case DEV_SM_PD_A55C2:
            status = DEV_SM_A55c2ConfigLoad();
            break;
        case DEV_SM_PD_A55C3:
            status = DEV_SM_A55c3ConfigLoad();
            break;
        case DEV_SM_PD_A55C4:
            status = DEV_SM_A55c4ConfigLoad();
            break;
        case DEV_SM_PD_A55C5:
            status = DEV_SM_A55c5ConfigLoad();
            break;
        case DEV_SM_PD_DDR:
            status = DEV_SM_DdrConfigLoad();
            break;
        case DEV_SM_PD_DISPLAY:
            status = DEV_SM_DisplayConfigLoad();
            break;
        case DEV_SM_PD_GPU:
            status = DEV_SM_GpuConfigLoad();
            break;
        case DEV_SM_PD_HSIO_TOP:
            status = DEV_SM_HsioTopConfigLoad();
            break;
        case DEV_SM_PD_HSIO_WAON:
            status = DEV_SM_HsioWaonConfigLoad();
            break;
        case DEV_SM_PD_M7:
            status = DEV_SM_M7ConfigLoad();
            break;
        case DEV_SM_PD_NETC:
            status = DEV_SM_NetcConfigLoad();
            break;
        case DEV_SM_PD_NOC:
            status = DEV_SM_NocConfigLoad();
            break;
        case DEV_SM_PD_NPU:
            status = DEV_SM_NpuConfigLoad();
            break;
        case DEV_SM_PD_VPU:
            status = DEV_SM_VpuConfigLoad();
            break;
        case DEV_SM_PD_WAKEUP:
            status = DEV_SM_WkupConfigLoad();
            break;
        case DEV_SM_PD_ANA:
            status = DEV_SM_AnaConfigLoad();
            break;
        case DEV_SM_PD_AON:
            status = DEV_SM_AonConfigLoad();
            break;
        case DEV_SM_PD_BBSM:
            status = DEV_SM_BbsmConfigLoad();
            break;
        case DEV_SM_PD_CCMSRCGPC:
            status = DEV_SM_CcmsrcgpcConfigLoad();
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Power domain preamble for power-down                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerDownPre(uint32_t domainId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Call power-down preable if domain is currently powered */
    if (SRC_MixIsPwrSwitchOn(domainId))
    {
        switch (domainId)
        {
            case DEV_SM_PD_A55P:
                status = DEV_SM_A55pPowerDownPre();
                break;
            case DEV_SM_PD_DISPLAY:
                status = DEV_SM_DisplayPowerDownPre();
                break;
            case DEV_SM_PD_HSIO_TOP:
                status = DEV_SM_HsioTopPowerDownPre();
                break;
            case DEV_SM_PD_M7:
                status = DEV_SM_M7PowerDownPre();
                break;
            default:
                /* Only return error if domain out of range */
                if (domainId >= DEV_SM_NUM_POWER)
                {
                    status = SM_ERR_NOT_FOUND;
                }
                break;
        }
    }

    /* Return status */
    return status;
}

