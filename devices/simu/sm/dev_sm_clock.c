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
/* File containing the implementation of the device clocks.                 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

static bool s_clockState[DEV_SM_NUM_CLOCK];
static uint64_t s_clockFreq[DEV_SM_NUM_CLOCK];
static uint32_t s_clockParent[DEV_SM_NUM_CLOCK];
static uint32_t s_clockSscConfig[DEV_SM_NUM_CLOCK];

/*--------------------------------------------------------------------------*/
/* Return clock name                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockNameGet(uint32_t clockId, string *clockNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_CLOCK] =
    {
        [DEV_SM_CLK_0] = "clk0",
        [DEV_SM_CLK_1] = "clk1",
        [DEV_SM_CLK_2] = "clk2",
        [DEV_SM_CLK_3] = "clk3"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_CLOCK);

    /* Check clock */
    if (clockId >= DEV_SM_NUM_CLOCK)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *clockNameAddr = s_name[clockId];
    }

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return supported clock range                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockDescribe(uint32_t clockId,
    dev_sm_clock_range_t *range)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (clockId >= DEV_SM_NUM_CLOCK)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return range */
        range->lowestRate = 625000000U;
        range->highestRate = 1200000000U;
        range->stepSize = 1U;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return supported clock mux                                               */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockMuxGet(uint32_t clockId, uint32_t idx, uint32_t *mux,
    uint32_t *numMuxes)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (clockId == DEV_SM_CLK_0)
    {
        /* Return mux input and max number */
        status = SM_ERR_NOT_SUPPORTED;
        *numMuxes = 0U;
    }
    else if (clockId < DEV_SM_NUM_CLOCK)
    {
        /* Return mux input and max number */
        if (idx == 0U)
        {
            *mux = DEV_SM_CLK_0;
            *numMuxes = 1U;
        }
        else
        {
            status = SM_ERR_OUT_OF_RANGE;
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
/* Set clock rate                                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockRateSet(uint32_t clockId, uint64_t rate,
    uint32_t roundSel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (clockId < DEV_SM_NUM_CLOCK)
    {
        if (roundSel <= 2U)
        {
            s_clockFreq[clockId] = rate;
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
/* Get clock rate                                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockRateGet(uint32_t clockId, uint64_t *rate)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (clockId < DEV_SM_NUM_CLOCK)
    {
        *rate = s_clockFreq[clockId];
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable clock                                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockEnable(uint32_t clockId, bool enable)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (clockId < DEV_SM_NUM_CLOCK)
    {
        s_clockState[clockId] = enable;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return clock enable status                                               */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockIsEnabled(uint32_t clockId, bool *enabled)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (clockId < DEV_SM_NUM_CLOCK)
    {
        *enabled = s_clockState[clockId];
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set clock parent                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockParentSet(uint32_t clockId, uint32_t parent)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (clockId < DEV_SM_NUM_CLOCK)
    {
        s_clockParent[clockId] = parent;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get clock parent                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockParentGet(uint32_t clockId, uint32_t *parent)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (clockId < DEV_SM_NUM_CLOCK)
    {
        *parent = s_clockParent[clockId];
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set a device extended clock data value                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockExtendedSet(uint32_t clockId, uint32_t extId,
    uint32_t extConfigvalue)
{
    int32_t status = SM_ERR_SUCCESS;

    switch (extId)
    {
        case DEV_SM_CLOCK_EXT_SSC:
            if (clockId < DEV_SM_NUM_CLOCK)
            {
                /* Latch SSC configuration */
                s_clockSscConfig[clockId] = extConfigvalue;
            }
            else
            {
                status = SM_ERR_NOT_FOUND;
            }
            break;

        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set a device extended clock data value                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockExtendedGet(uint32_t clockId, uint32_t extId,
    uint32_t *extConfigvalue)
{
    int32_t status = SM_ERR_SUCCESS;

    switch (extId)
    {
        case DEV_SM_CLOCK_EXT_SSC:
            if (clockId < DEV_SM_NUM_CLOCK)
            {
                /* Get latched SSC configuration */
                *extConfigvalue = s_clockSscConfig[clockId];
            }
            else
            {
                status = SM_ERR_NOT_FOUND;
            }
            break;

        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return status */
    return status;
}

