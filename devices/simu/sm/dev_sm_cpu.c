/*
** ###################################################################
**
**     Copyright 2023-2026 NXP
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
/* File containing the implementation of the device CPUs.                   */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint32_t s_cpuWakeListA55 = 0U;
static bool cpuRunning[DEV_SM_NUM_CPU] =
{
    [DEV_SM_CPU_0] = true
};

/*--------------------------------------------------------------------------*/
/* Return CPU name                                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuNameGet(uint32_t cpuId, string *cpuNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_CPU] =
    {
        [DEV_SM_CPU_0] = "cpu0",
        [DEV_SM_CPU_1] = "cpu1",
        [DEV_SM_CPU_2] = "cpu2",
        [DEV_SM_CPU_3] = "cpu3",
        [DEV_SM_CPU_4] = "cpu4",
        [DEV_SM_CPU_5] = "cpu5",
        [DEV_SM_CPU_6] = "cpu6",
        [DEV_SM_CPU_7] = "cpu7",
        [DEV_SM_CPU_8] = "cpu8"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_CPU);

    /* Check CPU */
    if (DEV_SM_CpuIsReserved(cpuId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *cpuNameAddr = s_name[cpuId];
    }

    /* Return status */
    return status;
}


/*--------------------------------------------------------------------------*/
/* Get CPU info                                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuInfoGet(uint32_t cpuId, uint32_t *runMode,
    uint32_t *sleepMode, uint64_t *vector)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check CPU */
    if (cpuId >= DEV_SM_NUM_CPU)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }
    else
    {
        *runMode = 0U;
        *sleepMode = 0U;
        *vector = 0ULL;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Check if a CPU is active or suspended                                    */
/*--------------------------------------------------------------------------*/
bool DEV_SM_CpuIsActive(uint32_t cpuId)
{
    bool rc = cpuRunning[cpuId];

    /* Return state */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* CPU start                                                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuStart(uint32_t cpuId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check CPU */
    if (DEV_SM_CpuIsReserved(cpuId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        cpuRunning[cpuId] = true;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* CPU hold                                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuHold(uint32_t cpuId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check fuse state */
    if (DEV_SM_CpuIsReserved(cpuId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        cpuRunning[cpuId] = false;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* CPU stop                                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuStop(uint32_t cpuId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check fuse state */
    if (DEV_SM_CpuIsReserved(cpuId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        cpuRunning[cpuId] = false;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Check reset vector                                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuResetVectorCheck(uint32_t cpuId, uint64_t resetVector,
    bool table)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check CPU */
    if (DEV_SM_CpuIsReserved(cpuId))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set reset vector                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuResetVectorSet(uint32_t cpuId, uint64_t resetVector)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check CPU */
    if (DEV_SM_CpuIsReserved(cpuId))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set CPU sleep mode                                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuSleepModeSet(uint32_t cpuId, uint32_t sleepMode,
    uint32_t sleepFlags)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check CPU */
    if (DEV_SM_CpuIsReserved(cpuId))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check sleep mode */
    if ((status == SM_ERR_SUCCESS) && (sleepMode > 4U))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set CPU IRQ wake mask                                                    */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuIrqWakeSet(uint32_t cpuId, uint32_t maskIdx,
    uint32_t maskVal)
{
    int32_t status = SM_ERR_SUCCESS;

    if (maskIdx >= 12U /*GPC_CPU_CTRL_CMC_IRQ_WAKEUP_MASK_COUNT*/)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }
    else
    {
        /* Check CPU */
        if (DEV_SM_CpuIsReserved(cpuId))
        {
            status = SM_ERR_NOT_FOUND;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set CPU non-IRQ wake mask                                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuNonIrqWakeSet(uint32_t cpuId, uint32_t maskIdx,
    uint32_t maskVal)
{
    int32_t status = SM_ERR_SUCCESS;

    if (maskIdx >= 1U)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }
    else
    {
        /* Check CPU */
        if (DEV_SM_CpuIsReserved(cpuId))
        {
            status = SM_ERR_NOT_FOUND;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set CPU power domain LPM config                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuPdLpmConfigSet(uint32_t cpuId, uint32_t domainId,
    uint32_t lpmSetting, uint32_t retMask)
{
    int32_t status = SM_ERR_SUCCESS;
    bool cpuDisabled = DEV_SM_CpuIsReserved(cpuId);
    bool pdDisabled = DEV_SM_PdIsReserved(domainId);

    /* Check fuse state */
    if (pdDisabled || cpuDisabled)
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set CPU peripheral LPM config                                            */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuPerLpmConfigSet(uint32_t cpuId, uint32_t perId,
    uint32_t lpmSetting)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check CPU */
    if (DEV_SM_CpuIsReserved(cpuId))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get the wake list for a CPU                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuWakeListGet(uint32_t cpuId, uint32_t *cpuWakeList)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check CPU */
    if (cpuId == 8U)
    {
        *cpuWakeList = s_cpuWakeListA55;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set the wake list for a CPU                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_CpuWakeListSet(uint32_t cpuId, uint32_t cpuWakeList)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check CPU */
    if (cpuId == 8U)
    {
        s_cpuWakeListA55 = cpuWakeList;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Check if CPU is disabled in fuses                                        */
/*--------------------------------------------------------------------------*/
bool DEV_SM_CpuIsReserved(uint32_t cpuId)
{
    bool rc = false;

    /* Check fuse state of power domain */
    if (DEV_SM_FuseCpuDisabled(cpuId))
    {
        rc = true;
    }

    /* Return status */
    return rc;
}

