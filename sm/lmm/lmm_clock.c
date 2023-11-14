/*
** ###################################################################
**
** Copyright 2023 NXP
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
/* clocks.                                                                  */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

/* Local variables */

static bool s_clockState[SM_NUM_CLOCK][SM_NUM_LM];
static uint32_t s_clockParent[DEV_SM_NUM_CLOCK];
static uint64_t s_clockFreq[DEV_SM_NUM_CLOCK];

/*--------------------------------------------------------------------------*/
/* Init LMM clock management                                                */
/*--------------------------------------------------------------------------*/
int32_t LMM_ClockInit(uint32_t numClock, const uint32_t *clockList)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Init LM0 clock state */
    for (uint32_t idx = 0U; idx < numClock; idx++)
    {
        s_clockState[clockList[idx]][0U] = true;
    }

    /* Loop over clocks */
    for (uint32_t clockId = 0U; clockId < SM_NUM_CLOCK; clockId++)
    {
        /* Save parent */
        (void) LMM_ClockParentGet(0U, clockId, &s_clockParent[clockId]);

        /* Save clock rate */
        (void) LMM_ClockRateGet(0U, clockId, &s_clockFreq[clockId]);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return clock name                                                        */
/*--------------------------------------------------------------------------*/
int32_t LMM_ClockNameGet(uint32_t lmId, uint32_t clockId,
    string *clockNameAddr, int32_t *len)
{
    /* Just passthru to device */
    return SM_CLOCKNAMEGET(clockId, clockNameAddr, len);
}

/*--------------------------------------------------------------------------*/
/* Return supported clock range                                             */
/*--------------------------------------------------------------------------*/
int32_t LMM_ClockDescribe(uint32_t lmId, uint32_t clockId,
    dev_sm_clock_range_t *range)
{
    /* Just passthru to device */
    return SM_CLOCKDESCRIBE(clockId, range);
}

/*--------------------------------------------------------------------------*/
/* Return supported clock mux                                               */
/*--------------------------------------------------------------------------*/
int32_t LMM_ClockMuxGet(uint32_t lmId, uint32_t clockId, uint32_t idx,
    uint32_t *mux, uint32_t *numMuxes)
{
    /* Not shared, just passthru to device */
    return SM_CLOCKMUXGET(clockId, idx, mux, numMuxes);
}

/*--------------------------------------------------------------------------*/
/* Set clock rate                                                           */
/*--------------------------------------------------------------------------*/
int32_t LMM_ClockRateSet(uint32_t lmId, uint32_t clockId, uint64_t rate,
    uint32_t roundSel)
{
    /* Not shared, just passthru to device */
    return SM_CLOCKRATESET(clockId, rate, roundSel);
}

/*--------------------------------------------------------------------------*/
/* Get clock rate                                                           */
/*--------------------------------------------------------------------------*/
int32_t LMM_ClockRateGet(uint32_t lmId, uint32_t clockId,
    uint64_t *rate)
{
    /* Just passthru to device */
    return SM_CLOCKRATEGET(clockId, rate);
}

/*--------------------------------------------------------------------------*/
/* Reset clock parent and rate                                              */
/*--------------------------------------------------------------------------*/
int32_t LMM_ClockReset(uint32_t lmId, uint32_t clockId)
{
    int32_t status;
    bool enabled;

    /* Get enable state */
    status = LMM_ClockIsEnabled(lmId, clockId, &enabled);

    if (status == SM_ERR_SUCCESS)
    {
        /* Is enabled? */
        if (enabled)
        {
            status = SM_ERR_BUSY;
        }
        else
        {
            /* Restore parent */
            (void) LMM_ClockParentSet(lmId, clockId,
                s_clockParent[clockId]);

            /* Restore clock rate */
            (void) LMM_ClockRateSet(lmId, clockId, s_clockFreq[clockId],
                DEV_SM_CLOCK_ROUND_DOWN);
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable clock                                                     */
/*--------------------------------------------------------------------------*/
int32_t LMM_ClockEnable(uint32_t lmId, uint32_t clockId, bool enable)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check parameters */
    if (lmId >= SM_NUM_LM)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Check parameters */
    if ((status == SM_ERR_SUCCESS) && (clockId >= SM_NUM_CLOCK))
    {
        status = SM_ERR_NOT_FOUND;
    }

    if (status == SM_ERR_SUCCESS)
    {
        bool newEnable = false;

        /* Record new state */
        s_clockState[clockId][lmId] = enable;

        /* Aggregate clock enable */
        for (uint32_t lm = 0U; lm < SM_NUM_LM; lm++)
        {
            if (s_clockState[clockId][lm])
            {
                newEnable = true;
            }
        }

        /* Inform device of clock state, device will check if changed */
        status = SM_CLOCKENABLE(clockId, newEnable);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return clock enable status                                               */
/*--------------------------------------------------------------------------*/
int32_t LMM_ClockIsEnabled(uint32_t lmId, uint32_t clockId, bool *enabled)
{
    /* Just passthru to device */
    return SM_CLOCKISENABLED(clockId, enabled);
}

/*--------------------------------------------------------------------------*/
/* Set clock parent                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_ClockParentSet(uint32_t lmId, uint32_t clockId, uint32_t parent)
{
    /* Not shared, just passthru to device */
    return SM_CLOCKPARENTSET(clockId, parent);
}

/*--------------------------------------------------------------------------*/
/* Set clock parent                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_ClockParentGet(uint32_t lmId, uint32_t clockId, uint32_t *parent)
{
    /* Not shared, just passthru to device */
    return SM_CLOCKPARENTGET(clockId, parent);
}

