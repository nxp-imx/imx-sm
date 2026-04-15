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
/* File containing the implementation of the device clocks.                 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint64_t s_clockFreq[DEV_SM_NUM_CLOCK];
static uint32_t s_clockParent[DEV_SM_NUM_CLOCK];
static uint32_t s_clockSscConfig[DEV_SM_NUM_CLOCK];
static bool s_clockState[DEV_SM_NUM_CLOCK] =
{
    [CLOCK_SRC_0]  = true,
    [CLOCK_SRC_1]  = true,
    [CLOCK_SRC_2]  = true,
    [CLOCK_SRC_3]  = true,
    [CLOCK_SRC_4]  = true,
    [CLOCK_SRC_5]  = true,
    [CLOCK_ROOT_0] = true,
    [CLOCK_ROOT_1] = true,
    [CLOCK_ROOT_2] = true,
    [CLOCK_ROOT_3] = true,
    [CLOCK_ROOT_4] = true,
    [CLOCK_ROOT_5] = true,
    [CLOCK_ROOT_6] = true,
    [CLOCK_ROOT_7] = true,
    [CLOCK_ROOT_8] = true,
    [CLOCK_ROOT_9] = true,
    [CLOCK_GPR_0]  = true,
    [CLOCK_GPR_1]  = true,
    [CLOCK_CGM_0]  = true
};

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
        [CLOCK_SRC_0]  = "clk0",
        [CLOCK_SRC_1]  = "clk1",
        [CLOCK_SRC_2]  = "clk2",
        [CLOCK_SRC_3]  = "clk3",
        [CLOCK_SRC_4]  = "clk4",
        [CLOCK_SRC_5]  = "clk5",
        [CLOCK_ROOT_0] = "clk_root0",
        [CLOCK_ROOT_1] = "clk_root1",
        [CLOCK_ROOT_2] = "clk_root2",
        [CLOCK_ROOT_3] = "clk_root3",
        [CLOCK_ROOT_4] = "clk_root4",
        [CLOCK_ROOT_5] = "clk_root5",
        [CLOCK_ROOT_6] = "clk_root6",
        [CLOCK_ROOT_7] = "clk_root7",
        [CLOCK_ROOT_8] = "clk_root8",
        [CLOCK_ROOT_9] = "clk_root9",
        [CLOCK_GPR_0]  = "clk_gpr0",
        [CLOCK_GPR_1]  = "clk_gpr1",
        [CLOCK_CGM_0]  = "clk_cgm0"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_CLOCK);

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *clockNameAddr = s_name[clockId];
    }

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
    if (DEV_SM_ClockIsReserved(clockId))
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
/* Return clock parent info                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockParentDescribe(uint32_t clockId, uint32_t sel,
    uint32_t *parentId, uint32_t *numParents)
{
    int32_t status = SM_ERR_SUCCESS;

    static const uint8_t s_clockGprSel
    [CLOCK_NUM_GPR_SEL][CLOCK_NUM_GPR_MUX_SEL] =
    {
        [DEV_SM_GPR_SEL_0] = { DEV_SM_CLK_SRC_0, DEV_SM_CLK_SRC_1 },
        [DEV_SM_GPR_SEL_1] = { DEV_SM_CLK_SRC_2, DEV_SM_CLK_SRC_3 }
    };

    static const uint8_t s_clockSourceNumInputs[CLOCK_NUM_SRC] =
    {
        [DEV_SM_CLK_SRC_0] = 1U,
        [DEV_SM_CLK_SRC_2] = 1U,
        [DEV_SM_CLK_SRC_3] = 1U,
        [DEV_SM_CLK_SRC_5] = 1U
    };

    static const uint8_t s_clockRootMux
    [CLOCK_NUM_ROOT][CLOCK_NUM_ROOT_MUX_SEL] =
    {
        { DEV_SM_CLK_SRC_0, DEV_SM_CLK_SRC_1,
          DEV_SM_CLK_SRC_2, DEV_SM_CLK_SRC_4 },

        { DEV_SM_CLK_SRC_0, DEV_SM_CLK_SRC_1,
          DEV_SM_CLK_SRC_2, DEV_SM_CLK_SRC_4 },

        { DEV_SM_CLK_SRC_0, DEV_SM_CLK_SRC_1,
          DEV_SM_CLK_SRC_2, DEV_SM_CLK_SRC_4 },

        { DEV_SM_CLK_SRC_0, DEV_SM_CLK_SRC_1,
          DEV_SM_CLK_SRC_2, DEV_SM_CLK_SRC_4 },

        { DEV_SM_CLK_SRC_0, DEV_SM_CLK_SRC_1,
          DEV_SM_CLK_SRC_2, DEV_SM_CLK_SRC_4 },

        { DEV_SM_CLK_SRC_0, DEV_SM_CLK_SRC_1,
          DEV_SM_CLK_SRC_2, DEV_SM_CLK_SRC_4 },

        { DEV_SM_CLK_SRC_0, DEV_SM_CLK_SRC_1,
          DEV_SM_CLK_SRC_2, DEV_SM_CLK_SRC_4 },

        { DEV_SM_CLK_SRC_0, DEV_SM_CLK_SRC_1,
          DEV_SM_CLK_SRC_2, DEV_SM_CLK_SRC_4 },

        { DEV_SM_CLK_SRC_0, DEV_SM_CLK_SRC_1,
          DEV_SM_CLK_SRC_2, DEV_SM_CLK_SRC_3 },

        { DEV_SM_CLK_SRC_0, DEV_SM_CLK_SRC_1,
          DEV_SM_CLK_SRC_2, DEV_SM_CLK_SRC_5 }
    };

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else if (clockId < CLOCK_NUM_SRC)
    {
        /* Query if clock source has a parent */
        if (s_clockSourceNumInputs[clockId] != 0U)
        {
            *parentId = s_clockSourceNumInputs[clockId];

            /* Clock sources have at most a single parent */
            if (sel >= 1U)
            {
                status = SM_ERR_OUT_OF_RANGE;
            }
            else
            {
                *numParents = 1U;
            }
        }
        else
        {
            status = SM_ERR_NOT_SUPPORTED;
        }
    }
    else
    {
        uint32_t clockIndex = clockId - CLOCK_NUM_SRC;
        if (clockIndex < CLOCK_NUM_ROOT)
        {
            *numParents = CLOCK_NUM_ROOT_MUX_SEL;
            if (sel >= *numParents)
            {
                status = SM_ERR_OUT_OF_RANGE;
            }
            else
            {
                *parentId = s_clockRootMux[clockIndex][sel];
            }
        }
        else
        {
            clockIndex = clockIndex - CLOCK_NUM_ROOT;
            if (clockIndex < CLOCK_NUM_GPR_SEL)
            {
                *numParents = CLOCK_NUM_GPR_MUX_SEL;
                if (sel >= *numParents)
                {
                    status = SM_ERR_OUT_OF_RANGE;
                }
                else
                {
                    *parentId = s_clockGprSel[clockIndex][sel];
                }
            }
            else
            {
                clockIndex = clockIndex - CLOCK_NUM_GPR_SEL;
                if (clockIndex < CLOCK_NUM_CGC)
                {
                    if (sel >= 1U)
                    {
                        status = SM_ERR_OUT_OF_RANGE;
                    }
                    else
                    {
                        *parentId = 1U;
                        *numParents = 1U;
                    }
                }
                else
                {
                    status = SM_ERR_NOT_FOUND;
                }
            }
        }
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
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
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
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        *rate = s_clockFreq[clockId];
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
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        s_clockState[clockId] = enable;
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
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        *enabled = s_clockState[clockId];
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
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else if (clockId == DEV_SM_CLK_0)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }
    else
    {
        s_clockParent[clockId] = parent;
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
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else if (clockId == DEV_SM_CLK_0)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }
    else
    {
        *parent = s_clockParent[clockId];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get extended clock info                                                  */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockExtendedInfo(uint32_t clockId, bool *supported)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Check if SCC is supported */
        *supported = (clockId < DEV_SM_NUM_CLOCK);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set a device extended clock data value                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockExtendedSet(uint32_t clockId, uint32_t extId,
    uint32_t extConfigValue)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        switch (extId)
        {
            case DEV_SM_CLOCK_EXT_SSC:
                if (clockId < CLOCK_NUM_SRC)
                {
                    /* Latch SSC configuration */
                    s_clockSscConfig[clockId] = extConfigValue;
                }
                else
                {
                    status = SM_ERR_INVALID_PARAMETERS;
                }
                break;

            default:
                status = SM_ERR_NOT_FOUND;
                break;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set a device extended clock data value                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ClockExtendedGet(uint32_t clockId, uint32_t extId,
    uint32_t *extConfigValue)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check clock */
    if (DEV_SM_ClockIsReserved(clockId))
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        switch (extId)
        {
            /* Spread spectrum */
            case DEV_SM_CLOCK_EXT_SSC:
                /* Get latched SSC configuration */
                *extConfigValue = s_clockSscConfig[clockId];
                break;

            default:
                status = SM_ERR_NOT_FOUND;
                break;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Check if clock domain is reserved                                        */
/*--------------------------------------------------------------------------*/
bool DEV_SM_ClockIsReserved(uint32_t clockId)
{
    bool rc = false;
    static bool const s_clockIsReserved[DEV_SM_NUM_CLOCK] =
    {
        [DEV_SM_CLK_4] = true
    };

    if (clockId >= DEV_SM_NUM_CLOCK)
    {
        rc = true;
    }
    else
    {
        rc = s_clockIsReserved[clockId];
    }

    return rc;
}

