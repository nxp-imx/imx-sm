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
/* Unit test for the SM device CCM.                                         */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include <stdio.h>
#include "dev_sm.h"
#include "fsl_sysctr.h"
#include "fsl_systick.h"
#include "board.h"

/* Local defines */
#define CLK_IDX_SM_CORE     DEV_SM_CLK_M33
#define CLK_IDX_SM_BUS      DEV_SM_CLK_BUSAON

/* Local types */

/* Local variables */
static uint64_t s_clkRates[DEV_SM_NUM_CLOCK];
static bool s_clkEnables[DEV_SM_NUM_CLOCK];
static uint32_t s_clkParents[DEV_SM_NUM_CLOCK];


/* Local functions */
static void print_error(string prnMsg, int32_t err, uint32_t clkIdx)
{
    string clkName;

    printf("%s failed with err = %d for index = %u", prnMsg, err, clkIdx);

    if (DEV_SM_ClockNameGet(clkIdx, &clkName, NULL) == SM_ERR_SUCCESS)
    {
        printf(" (%s)\n", clkName);
    }
    else
    {
        printf(" (UNKNOWN)\n");
    }
}

static void print_mismatch(string prnMsg, uint32_t clkIdx,
    uint64_t v1, uint64_t v2)
{
    string clkName;

    printf("%s mismatch for index = %u", prnMsg, clkIdx);

    if (DEV_SM_ClockNameGet(clkIdx, &clkName, NULL) == SM_ERR_SUCCESS)
    {
        printf(" (%s)\n", clkName);
    }
    else
    {
        printf(" (UNKNOWN)\n");
    }

    /* If rate print requires 64-bit, use hex */
    if ((SM_UINT64_H(v1) != 0U) || (SM_UINT64_H(v2) != 0U))
    {
        printf("Expected = 0x%08X_0x%08X, Actual = 0x%08X_0x%08X\n",
            SM_UINT64_H(v1), SM_UINT64_L(v1),
            SM_UINT64_H(v2), SM_UINT64_L(v2));
    }
    else
    {
        printf("Expected = %u, Actual = %u\n", (uint32_t) v1, (uint32_t) v2);
    }
}

static bool skip_clk(uint32_t clkIdx)
{
    bool rc = false;

    if (clkIdx >= CLOCK_NUM_SRC)
    {
        clkIdx = clkIdx - CLOCK_NUM_SRC;

        if (clkIdx < CLOCK_NUM_ROOT)
        {
            if ((clkIdx == BOARD_DEBUG_UART_CLOCK_ROOT) ||
                (clkIdx == BOARD_I2C_CLK_ROOT) ||
                (clkIdx == BOARD_SYSTICK_CLK_ROOT))
            {
                rc = true;
            }
        }
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Test SM device CLOCK interface                                           */
/*--------------------------------------------------------------------------*/
void TEST_DevClock(void)
{
    /* Tests related to ARM PLL require A55P to be powered */
    uint8_t powerStateA55P = DEV_SM_POWER_STATE_OFF;
    (void) DEV_SM_PowerStateGet(DEV_SM_PD_A55P, &powerStateA55P);
    (void) DEV_SM_PowerStateSet(DEV_SM_PD_A55P, DEV_SM_POWER_STATE_ON);

    printf("Testing Enable/Disable...\n");
    for (uint32_t clkIdx = 0U; clkIdx < DEV_SM_NUM_CLOCK; clkIdx++)
    {
        if (skip_clk(clkIdx))
        {
            continue;
        }

        int32_t rc = DEV_SM_ClockIsEnabled(clkIdx, &s_clkEnables[clkIdx]);
        if (rc == SM_ERR_SUCCESS)
        {
            rc = DEV_SM_ClockEnable(clkIdx, s_clkEnables[clkIdx]);
            if (rc == SM_ERR_SUCCESS)
            {
                bool enable;

                rc = DEV_SM_ClockIsEnabled(clkIdx, &enable);
                if (rc == SM_ERR_SUCCESS)
                {
                    if (enable != s_clkEnables[clkIdx])
                    {
                        print_mismatch("Enable mismatch", clkIdx,
                            s_clkEnables[clkIdx], enable);
                    }
                }
                else
                {
                    print_error("DEV_SM_ClockEnable", rc, clkIdx);
                }
            }
            else
            {
                /* Skip printing error for INVALID_PARAMETERS since this is
                 * returned for nodes that are not settable.
                 */
                if (rc != SM_ERR_INVALID_PARAMETERS)
                {
                    print_error("DEV_SM_ClockEnable", rc, clkIdx);
                }
            }
        }
        else
        {
            print_error("DEV_SM_ClockIsEnabled", rc, clkIdx);
        }
    }

    printf("Testing Get/Set Rate...\n");
    for (uint32_t clkIdx = 0U; clkIdx < DEV_SM_NUM_CLOCK; clkIdx++)
    {
        if (skip_clk(clkIdx))
        {
            continue;
        }

        int32_t rc = DEV_SM_ClockRateGet(clkIdx, &s_clkRates[clkIdx]);
        if (rc == SM_ERR_SUCCESS)
        {
            rc = DEV_SM_ClockRateSet(clkIdx, s_clkRates[clkIdx],
                DEV_SM_CLOCK_ROUND_DOWN);

            /* Assume SM_ERR_INVALID_PARAMETERS imples node not setable */
            if (rc == SM_ERR_SUCCESS)
            {
                uint64_t rate;

                rc = DEV_SM_ClockRateGet(clkIdx, &rate);
                if (rc == SM_ERR_SUCCESS)
                {
                    if (rate != s_clkRates[clkIdx])
                    {
                        print_mismatch("Rate mismatch", clkIdx,
                            s_clkRates[clkIdx], rate);
                    }
                }
                else
                {
                    print_error("DEV_SM_ClockRateGet", rc, clkIdx);
                }
            }
            /* Skip printing error for INVALID_PARAMETERS since this is
             * returned for nodes that are not settable.
             */
            else
            {
                if (rc != SM_ERR_INVALID_PARAMETERS)
                {
                    print_error("DEV_SM_ClockRateSet", rc, clkIdx);
                }
            }
        }
        else
        {
            print_error("DEV_SM_ClockRateGet", rc, clkIdx);
        }

    }

    printf("Testing Get/Set Parent...\n");
    for (uint32_t clkIdx = 0U; clkIdx < DEV_SM_NUM_CLOCK; clkIdx++)
    {
        if (skip_clk(clkIdx))
        {
            continue;
        }

        int32_t rc = DEV_SM_ClockParentGet(clkIdx, &s_clkParents[clkIdx]);
        if (rc == SM_ERR_SUCCESS)
        {
            rc = DEV_SM_ClockParentSet(clkIdx, s_clkParents[clkIdx]);
            if (rc == SM_ERR_SUCCESS)
            {
                uint32_t parent;

                rc = DEV_SM_ClockParentGet(clkIdx, &parent);
                if (rc == SM_ERR_SUCCESS)
                {
                    if (parent != s_clkParents[clkIdx])
                    {
                        print_mismatch("Parent mismatch", clkIdx,
                            s_clkParents[clkIdx], parent);
                    }
                }
                else
                {
                    print_error("DEV_SM_ClockParentGet", rc, clkIdx);
                }
            }
            else
            {
                /* Skip printing error for INVALID_PARAMETERS since this is
                 * returned for nodes that are not settable.
                 */
                if (rc != SM_ERR_INVALID_PARAMETERS)
                {
                    print_error("DEV_SM_ClockParentSet", rc, clkIdx);
                }
            }
        }
        else
        {
            /* Skip printing error for INVALID_PARAMETERS since this is
             * returned for nodes that do not have a parent.
             */
            if (rc != SM_ERR_INVALID_PARAMETERS)
            {
                print_error("DEV_SM_ClockParentGet", rc, clkIdx);
            }
        }
    }

    printf("Testing Set Lowest/Highest Rate...\n");
    for (uint32_t clkIdx = 0U; clkIdx < DEV_SM_NUM_CLOCK; clkIdx++)
    {
        if (skip_clk(clkIdx))
        {
            continue;
        }

        dev_sm_clock_range_t range;
        int32_t rc = DEV_SM_ClockDescribe(clkIdx, &range);
        if (rc == SM_ERR_SUCCESS)
        {
            /* Set parent as 24M for lowest rate testing */
            (void) DEV_SM_ClockParentSet(clkIdx, DEV_SM_CLK_OSC24M);

            rc = DEV_SM_ClockRateSet(clkIdx, range.lowestRate,
                DEV_SM_CLOCK_ROUND_DOWN);
            if (rc == SM_ERR_SUCCESS)
            {
                uint64_t rate;

                rc = DEV_SM_ClockRateGet(clkIdx, &rate);
                if (rc == SM_ERR_SUCCESS)
                {
                    /* SCMI rate descriptions specified in kHz, ignore sub-kHz
                     * differences in rate
                     */
                    if ((rate > range.lowestRate) ||
                        ((range.lowestRate - rate) > 1000U))
                    {
                        print_mismatch("Lowest rate mismatch", clkIdx,
                            range.lowestRate, rate);
                    }
                }
                else
                {
                    print_error("DEV_SM_ClockRateGet", rc, clkIdx);
                }
            }
            else
            {
                /* Skip printing error for INVALID_PARAMETERS since this is
                 * returned for nodes that are not settable.
                 */
                if (rc != SM_ERR_INVALID_PARAMETERS)
                {
                    print_error("DEV_SM_ClockRateSet", rc, clkIdx);
                }
            }
        }
        else
        {
            print_error("DEV_SM_ClockDescribe", rc, clkIdx);
        }
    }

    /* Restore clock configuration */
    for (uint32_t clkIdx = 0U; clkIdx < DEV_SM_NUM_CLOCK; clkIdx++)
    {
        if (skip_clk(clkIdx))
        {
            continue;
        }

        DEV_SM_ClockParentSet(clkIdx, s_clkParents[clkIdx]);
        DEV_SM_ClockRateSet(clkIdx, s_clkRates[clkIdx],
            DEV_SM_CLOCK_ROUND_DOWN);
        DEV_SM_ClockEnable(clkIdx, s_clkEnables[clkIdx]);
    }

    /* Restore A55P power state */
    (void) DEV_SM_PowerStateSet(DEV_SM_PD_A55P, powerStateA55P);

    printf("\n");
}

