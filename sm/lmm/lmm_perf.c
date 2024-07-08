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
/* performance domains.                                                     */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Return performance domain name                                           */
/*--------------------------------------------------------------------------*/
int32_t LMM_PerfNameGet(uint32_t lmId, uint32_t domainId,
    string *perfNameAddr, int32_t *len)
{
    /* Just passthru to board/device */
    return SM_PERFNAMEGET(domainId, perfNameAddr, len);
}

/*--------------------------------------------------------------------------*/
/* Return performance domain info                                           */
/*--------------------------------------------------------------------------*/
int32_t LMM_PerfInfoGet(uint32_t lmId, uint32_t domainId,
    dev_sm_perf_info_t *info)
{
    /* Just passthru to board/device */
    return SM_PERFINFOGET(domainId, info);
}

/*--------------------------------------------------------------------------*/
/* Return number of performance levels                                      */
/*--------------------------------------------------------------------------*/
int32_t LMM_PerfNumLevelsGet(uint32_t lmId, uint32_t domainId,
    uint32_t *numLevels)
{
    /* Just passthru to board/device */
    return SM_PERFNUMLEVELSGET(domainId, numLevels);
}

/*--------------------------------------------------------------------------*/
/* Return info about a performance level                                    */
/*--------------------------------------------------------------------------*/
int32_t LMM_PerfDescribe(uint32_t lmId, uint32_t domainId,
    uint32_t levelIndex, dev_sm_perf_desc_t *desc)
{
    /* Just passthru to board/device */
    return SM_PERFDESCRIBE(domainId, levelIndex, desc);
}

/*--------------------------------------------------------------------------*/
/* Set performance domain level                                             */
/*--------------------------------------------------------------------------*/
int32_t LMM_PerfLevelSet(uint32_t lmId, uint32_t domainId,
    uint32_t performanceLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check LM ID */
    if (lmId >= SM_NUM_LM)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Check domain ID */
    if ((status == SM_ERR_SUCCESS) && (domainId >= SM_NUM_PERF))
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Check level */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t numLevels = 0U;

        /* Get number of levels */
        status = DEV_SM_PerfNumLevelsGet(domainId, &numLevels);

        /* Check number */
        if ((status == SM_ERR_SUCCESS)
            && (performanceLevel >= numLevels))
        {
            status = SM_ERR_INVALID_PARAMETERS;
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        static uint32_t s_perfLevel[SM_NUM_PERF][SM_NUM_LM];
        uint8_t newPerfLevel = 0U;

        /* Record new level */
        s_perfLevel[domainId][lmId] = performanceLevel;

        /* Aggregate perf level */
        for (uint32_t lm = 0U; lm < SM_NUM_LM; lm++)
        {
            newPerfLevel = (uint8_t) MAX(newPerfLevel,
                s_perfLevel[domainId][lm]);
        }

        /* Inform device of power state, device will check if changed */
        status = SM_PERFLEVELSET(domainId, newPerfLevel);
    }

    SM_TEST_MODE_ERR(SM_TEST_MODE_LMM_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get performance domain level                                             */
/*--------------------------------------------------------------------------*/
int32_t LMM_PerfLevelGet(uint32_t lmId, uint32_t domainId,
    uint32_t *performanceLevel)
{
    /* Just passthru to board/device */
    return SM_PERFLEVELGET(domainId, performanceLevel);
}

