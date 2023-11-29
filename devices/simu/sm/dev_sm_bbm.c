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
/* File containing the implementation of the device battery-backed module.  */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint32_t s_bbmGpr[DEV_SM_NUM_GPR];
static uint64_t s_ticks = 0ULL;
static uint64_t s_alarm = 0ULL;
static bool s_alarmEnable = false;
static bool s_rolloverEnable = false;
static bool s_button = false;

/*--------------------------------------------------------------------------*/
/* Init BBM                                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmInit(void)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return BBM status found at boot                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmGetBootStatus(uint32_t *flags)
{
    int32_t status = SM_ERR_SUCCESS;

    /* No conditions */
    *flags = 0U;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set BBM GPR                                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmGprSet(uint32_t index, uint32_t value)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check GPR */
    if (index < DEV_SM_NUM_GPR)
    {
        s_bbmGpr[index] = value;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get BBM GPR                                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmGprGet(uint32_t index, uint32_t *value)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check GPR */
    if (index < DEV_SM_NUM_GPR)
    {
        *value = s_bbmGpr[index];
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return RTC name                                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmRtcNameGet(uint32_t rtcId, string *rtcNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_RTC] =
    {
        [DEV_SM_RTC_BBM] = "bbm"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_RTC);

    /* Check RTC */
    if (rtcId >= DEV_SM_NUM_RTC)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *rtcNameAddr = s_name[rtcId];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return RTC info                                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmRtcDescribe(uint32_t rtcId, uint32_t *secWidth,
    uint32_t *tickWidth, uint32_t *ticksPerSec)
{
    /* Return RTC info */
    *secWidth = 32U;
    *tickWidth = 47U;
    *ticksPerSec = 32768U;

    /* Return status */
    return SM_ERR_SUCCESS;
}

/*--------------------------------------------------------------------------*/
/* Set BBM RTC time                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmRtcTimeSet(uint32_t rtcId, uint64_t val, bool ticks)
{
    int32_t status = SM_ERR_SUCCESS;

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

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get BBM RTC time                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmRtcTimeGet(uint32_t rtcId, uint64_t *val, bool ticks)
{
    int32_t status = SM_ERR_SUCCESS;

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

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set BBM RTC alarm                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmRtcAlarmSet(uint32_t rtcId, bool enable, uint64_t val)
{
    int32_t status = SM_ERR_SUCCESS;

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

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Enable BBM RTC rollover interrupt                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmRtcRollover(uint32_t rtcId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Enable */
    s_rolloverEnable = true;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set Get BBM button state                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmButtonGet(bool *buttonAsserted)
{
    int32_t status = SM_ERR_SUCCESS;

    *buttonAsserted = s_button;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Tick handler (one second)                                                */
/*--------------------------------------------------------------------------*/
void DEV_SM_BbmHandler(void)
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
            LMM_BbmRtcRolloverEvent(DEV_SM_RTC_BBM);
        }
    }

    /* Check alarm */
    if (s_alarmEnable && (s_ticks >= s_alarm))
    {
        LMM_BbmRtcAlarmEvent(DEV_SM_RTC_BBM);
    }

    /* Toggle button */
    s_button = !s_button;
    if (s_button)
    {
        LMM_BbmButtonEvent();
    }
}

