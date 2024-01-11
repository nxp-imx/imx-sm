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
/* CPUs.                                                                    */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint64_t s_bootVector[SM_NUM_CPU];
static uint64_t s_startVector[SM_NUM_CPU];
static bool s_bootFlags[SM_NUM_CPU];
static bool s_startFlags[SM_NUM_CPU];

/*--------------------------------------------------------------------------*/
/* Init LMM CPU management                                                  */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuInit(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Loop over CPUs */
    for (uint32_t cpuId = 0U; cpuId < SM_NUM_CPU; cpuId++)
    {
        uint32_t mSel;
        uint32_t flags;

        /* Get boot data */
        if (DEV_SM_RomBootCpuGet(cpuId, &s_bootVector[cpuId], &mSel,
            &flags) == SM_ERR_SUCCESS)
        {
            /* Save ROM provided vector */
            s_bootFlags[cpuId] = true;
        }
        else
        {
            s_bootFlags[cpuId] = false;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return CPU name                                                          */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuNameGet(uint32_t lmId, uint32_t cpuId, string *cpuNameAddr,
    int32_t *len)
{
    /* Just passthru to board/device */
    return SM_CPUNAMEGET(cpuId, cpuNameAddr, len);
}

/*--------------------------------------------------------------------------*/
/* Check CPU boot address                                                   */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuBootCheck(uint32_t lmId, uint32_t cpuId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check if CPU has a valid reset vector */
    if (!s_bootFlags[cpuId])
    {
        status = SM_ERR_MISSING_PARAMETERS;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* CPU start                                                                */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuStart(uint32_t lmId, uint32_t cpuId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check CPU */
    if (cpuId >= DEV_SM_NUM_CPU)
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check if CPU has a valid reset vector */
    if ((status == SM_ERR_SUCCESS) && (!s_startFlags[cpuId]))
    {
        status = SM_ERR_MISSING_PARAMETERS;
    }

    /* Set reset vector */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_CPURESETVECTORSET(cpuId, s_startVector[cpuId]);
    }

    /* Start CPU */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_CPUSTART(cpuId);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* CPU hold                                                                 */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuHold(uint32_t lmId, uint32_t cpuId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check CPU */
    if (cpuId >= DEV_SM_NUM_CPU)
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check if CPU has a valid reset vector */
    if ((status == SM_ERR_SUCCESS) && (!s_startFlags[cpuId]))
    {
        status = SM_ERR_MISSING_PARAMETERS;
    }

    /* Set reset vector */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_CPURESETVECTORSET(cpuId, s_startVector[cpuId]);
    }

    /* Hold CPU */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_CPUHOLD(cpuId);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* CPU stop                                                                 */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuStop(uint32_t lmId, uint32_t cpuId)
{
    /* Just passthru to board/device */
    return SM_CPUSTOP(cpuId);
}

/*--------------------------------------------------------------------------*/
/* Set reset vector                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuResetVectorSet(uint32_t lmId, uint32_t cpuId,
    uint64_t resetVector, bool boot, bool start, bool resume, bool table)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check address and address type */
    status = SM_CPURESETVECTORCHECK(cpuId, resetVector, table);

    if (status == SM_ERR_SUCCESS)
    {
        /* Save boot address */
        if (boot)
        {
            s_bootVector[cpuId] = resetVector;
            s_bootFlags[cpuId] = true;
        }

        /* Save boot address */
        if (start)
        {
            s_startVector[cpuId] = resetVector;
            s_startFlags[cpuId] = true;
        }

        /* Set resume address */
        if (resume)
        {
            status = SM_CPURESETVECTORSET(cpuId, resetVector);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load reset vector from boot vector                                       */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuResetVectorReset(uint32_t lmId, uint32_t cpuId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check CPU */
    if (cpuId < DEV_SM_NUM_CPU)
    {
        /* Set start to boot */
        s_startVector[cpuId] = s_bootVector[cpuId];
        s_startFlags[cpuId] = s_bootFlags[cpuId];
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set CPU sleep mode                                                       */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuSleepModeSet(uint32_t lmId, uint32_t cpuId,
    uint32_t sleepMode, uint32_t sleepFlags)
{
    return SM_CPUSLEEPMODESET(cpuId, sleepMode, sleepFlags);
}

/*--------------------------------------------------------------------------*/
/* Set CPU IRQ wake mask                                                    */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuIrqWakeSet(uint32_t lmId, uint32_t cpuId, uint32_t maskIdx,
    uint32_t maskVal)
{
    return SM_CPUIRQWAKESET(cpuId, maskIdx, maskVal);
}

/*--------------------------------------------------------------------------*/
/* Set CPU non-IRQ wake mask                                                */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuNonIrqWakeSet(uint32_t lmId, uint32_t cpuId, uint32_t maskIdx,
    uint32_t maskVal)
{
    return SM_CPUNONIRQWAKESET(cpuId, maskIdx, maskVal);
}

/*--------------------------------------------------------------------------*/
/* Set CPU power domain LPM config                                          */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuPdLpmConfigSet(uint32_t lmId, uint32_t cpuId,
    uint32_t domainId, uint32_t lpmSetting, uint32_t retMask)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t pdMask;

    /* Check parameters */
    if ((cpuId >= SM_NUM_CPU) || (domainId >= SM_NUM_POWER))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Get power domain retention mask */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_POWERRETMASKGET(domainId, &pdMask);
    }

    /* Check the retention mask */
    if ((status == SM_ERR_SUCCESS) && ((retMask & ~pdMask) != 0U))
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    if (status == SM_ERR_SUCCESS)
    {
        static uint32_t s_cpuRetMask[SM_NUM_CPU];
        uint32_t newRetMask = 0U;

        /* Record new state */
        s_cpuRetMask[cpuId] = (s_cpuRetMask[cpuId] & ~pdMask) | retMask;

        /* Aggregate CPU retention masks */
        for (uint32_t cpu = 0U; cpu < SM_NUM_CPU; cpu++)
        {
            newRetMask |= s_cpuRetMask[cpu];
        }

        /* Inform device of config, device will check if changed */
        status = SM_CPUPDLPMCONFIGSET(cpuId, domainId, lpmSetting,
            newRetMask & pdMask);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set CPU peripheral LPM config                                            */
/*--------------------------------------------------------------------------*/
int32_t LMM_CpuPerLpmConfigSet(uint32_t lmId, uint32_t cpuId,
    uint32_t perId, uint32_t lpmSetting)
{
    return SM_CPUPERLPMCONFIGSET(cpuId, perId, lpmSetting);
}

