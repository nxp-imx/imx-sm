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
/* File containing the implementation of the device performance domains.    */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint32_t s_perfLevel[DEV_SM_NUM_PERF];

static const dev_sm_perf_desc_t s_perfLevels[4] =
{
    {
        .value = 1000000U,  /* KHz */
        .powerCost = 200U,  /* mW */
        .latency = 500U     /* uS */
    },
    {
        .value = 1500000U,  /* KHz */
        .powerCost = 300U,  /* mW */
        .latency = 500U     /* uS */
    },
    {
        .value = 2000000U,  /* KHz */
        .powerCost = 400U,  /* mW */
        .latency = 500U     /* uS */
    },
    {
        .value = 2500000U,  /* KHz */
        .powerCost = 500U,  /* mW */
        .latency = 500U     /* uS */
    }
};

/*--------------------------------------------------------------------------*/
/* Return performance domain name                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfNameGet(uint32_t domainId, string *perfNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_PERF] =
    {
        [DEV_SM_PERF_0] = "perf0",
        [DEV_SM_PERF_1] = "perf1"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_PERF);

    /* Check domain */
    if (domainId >= DEV_SM_NUM_PERF)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *perfNameAddr = s_name[domainId];
    }

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return performance domain info                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfInfoGet(uint32_t domainId, dev_sm_perf_info_t *info)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return dummy info */
    info->rateLimit = 0U;
    info->sustainedFreq = 2000000U;          /* KHz */
    info->sustainedPerfLevel = 2000000U;     /* KHz */

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return number of performance levels                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfNumLevelsGet(uint32_t domainId, uint32_t *numLevels)
{
    int32_t status = SM_ERR_SUCCESS;

    *numLevels = sizeof(s_perfLevels) / sizeof(dev_sm_perf_desc_t);

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return supported performance level                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfDescribe(uint32_t domainId, uint32_t levelIndex,
    dev_sm_perf_desc_t *desc)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check array bounds */
    if (levelIndex >= (sizeof(s_perfLevels) / sizeof(dev_sm_perf_desc_t)))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Copy result */
    if (status == SM_ERR_SUCCESS)
    {
        *desc = s_perfLevels[levelIndex];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set performance domain level                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfLevelSet(uint32_t domainId, uint32_t perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (domainId >= DEV_SM_NUM_PERF)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        s_perfLevel[domainId] = perfLevel;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get performance domain level                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PerfLevelGet(uint32_t domainId, uint32_t *perfLevel)
{
    int32_t status = SM_ERR_SUCCESS;

    if (domainId >= DEV_SM_NUM_PERF)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        *perfLevel = s_perfLevel[domainId];
    }

    /* Return status */
    return status;
}

