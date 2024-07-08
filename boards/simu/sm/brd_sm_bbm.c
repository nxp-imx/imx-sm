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
/* File containing the implementation of the board RTC.                     */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "brd_sm.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint64_t s_ticks = 0ULL;
static uint64_t s_alarm = 0ULL;
static bool s_alarmEnable = false;
static bool s_rolloverEnable = false;

/*--------------------------------------------------------------------------*/
/* Return RTC name                                                          */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcNameGet(uint32_t rtcId, string *rtcNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[BRD_SM_NUM_RTC] =
    {
        "pmic"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, BRD_SM_NUM_RTC);

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcNameGet(rtcId, rtcNameAddr, len);
    }
    else
    {
        /* Return pointer to name */
        *rtcNameAddr = s_name[rtcId - DEV_SM_NUM_RTC];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return RTC info                                                          */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcDescribe(uint32_t rtcId, uint32_t *secWidth,
    uint32_t *tickWidth, uint32_t *ticksPerSec)
{
    int32_t status = SM_ERR_SUCCESS;

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcDescribe(rtcId, secWidth, tickWidth,
            ticksPerSec);
    }
    else
    {
        /* Return RTC info */
        *secWidth = 32U;
        *tickWidth = 47U;
        *ticksPerSec = 32768U;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set BBM RTC time                                                         */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcTimeSet(uint32_t rtcId, uint64_t val, bool ticks)
{
    int32_t status = SM_ERR_SUCCESS;

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcTimeSet(rtcId, val, ticks);
    }
    else
    {
        /* Check time format */
        if (ticks)
        {
            /* Get ticks */
            s_ticks = val;
        }
        else
        {
            /* Get seconds */
            s_ticks = val << 15U;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get BBM RTC time                                                         */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcTimeGet(uint32_t rtcId, uint64_t *val, bool ticks)
{
    int32_t status = SM_ERR_SUCCESS;

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcTimeGet(rtcId, val, ticks);
    }
    else
    {
        /* Check time format */
        if (ticks)
        {
            /* Get ticks */
            *val = s_ticks;
        }
        else
        {
            /* Get seconds */
            *val = s_ticks >> 15U;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get BBM RTC state                                                        */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcStateGet(uint32_t rtcId, uint32_t *state)
{
    int32_t status = SM_ERR_SUCCESS;

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcStateGet(rtcId, state);
    }
    else
    {
        /* Test state */
        *state = LMM_BBM_STATE_RESET | LMM_BBM_STATE_BATT_LOW;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set BBM RTC alarm                                                        */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcAlarmSet(uint32_t rtcId, bool enable, uint64_t val)
{
    int32_t status = SM_ERR_SUCCESS;

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcAlarmSet(rtcId, enable, val);
    }
    else
    {
        /* Enable? */
        if (enable)
        {
            uint64_t ticks = val << 15U;

            /* Check if valid time */
            if (ticks <= s_ticks)
            {
                status = SM_ERR_INVALID_PARAMETERS;
            }
            else
            {
                /* Save alarm */
                s_alarm = ticks;

                /* Enable */
                s_alarmEnable = true;
            }
        }
        else
        {
            /* Disable alarm interrupt */
            s_alarmEnable = false;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Enable BBM RTC rollover interrupt                                        */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcRollover(uint32_t rtcId)
{
    int32_t status = SM_ERR_SUCCESS;

    if (rtcId < DEV_SM_NUM_RTC)
    {
        status = DEV_SM_BbmRtcRollover(rtcId);
    }
    else
    {
        /* Enable */
        s_rolloverEnable = true;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Tick handler (one second)                                                */
/*--------------------------------------------------------------------------*/
void BRD_SM_BbmHandler(void)
{
    /* Increment time by 1 second */
    s_ticks += (1ULL << 15U);

    /* Roll over */
    if (s_ticks > (0xFFFFFFFFULL << 15U))
    {
        s_ticks = 0ULL;

        /* Check rollover */
        if (s_rolloverEnable)
        {
            s_rolloverEnable = false;
            LMM_BbmRtcRolloverEvent(BRD_SM_RTC_PMIC);
        }
    }

    /* Check alarm */
    if (s_alarmEnable && (s_ticks >= s_alarm))
    {
        LMM_BbmRtcAlarmEvent(BRD_SM_RTC_PMIC);
    }
}

