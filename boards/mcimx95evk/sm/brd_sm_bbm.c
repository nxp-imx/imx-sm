/*
** ###################################################################
**
** Copyright 2024 NXP
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
/* File containing the implementation of the PCA2131 RTC.                   */
/*==========================================================================*/

/* Note this code is an example. The conversion functions between date and
   seconds have not been fully tested to match The PCA2131 and calling
   agents. */

/* Includes */

#include "sm.h"
#include "brd_sm.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void days2date(uint32_t days, uint32_t *year, uint32_t *month,
    uint32_t *day, uint32_t *weekday);
static void date2days(uint32_t year, uint32_t month, uint32_t day,
    uint32_t *days);

/*--------------------------------------------------------------------------*/
/* Write RTC raw data                                                       */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcWrite(uint32_t addr, uint32_t numVal,
    const uint32_t *val)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check read size */
    if (numVal > 24U)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }
    else
    {
        uint8_t buf[24];

        /* Copy buffer (convert to 8-bit) */
        for (uint32_t idx = 0U; idx < numVal; idx++)
        {
            buf[idx] = (uint8_t) val[idx];
        }

        /* Write data */
        if (!PCA2131_RtcWrite(&pca2131Dev, (uint8_t) addr,
            (uint8_t) numVal, buf))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Read RTC raw data                                                        */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BbmRtcRead(uint32_t addr, uint32_t numVal, uint32_t *val)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check read size */
    if (numVal > 24U)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }
    else
    {
        uint8_t buf[24] = { 0 };

        /* Read data */
        if (PCA2131_RtcRead(&pca2131Dev, (uint8_t) addr,
            (uint8_t) numVal, buf))
        {
            /* Copy buffer (convert to 32-bit) */
            for (uint32_t idx = 0U; idx < numVal; idx++)
            {
                val[idx] = (uint32_t) buf[idx];
            }
        }
        else
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    /* Return status */
    return status;
}

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
        "pca2131"
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
        *tickWidth = 39U;
        *ticksPerSec = 100U;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set RTC time                                                             */
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
        uint32_t year, month, day, hour, min, sec, hun, weekday;
        uint32_t days, hours, mins, secs;

        /* Convert to hundreths of seconds */
        if (ticks)
        {
            uint64_t sec64, hun64;

            sec64 = val / 100U;
            hun64 = val - (sec64 * 100U);

            secs = (uint32_t) sec64;
            hun = (uint32_t) hun64;
        }
        else
        {
            hun = 0U;
            secs = (uint32_t) val;
        }

        /* Calculate totals */
        mins = secs / 60U;
        hours = secs / 3600U;
        days = secs / 86400U;

        /* Calculate time */
        sec = secs % 60U;
        min = mins % 60U;
        hour = hours % 24U;

        /* Convert to date */
        days2date((uint32_t) days, &year, &month, &day, &weekday);

        /* Covert year */
        year %= 100U;

        /* Write RTC */
        if (!PCA2131_RtcSet(&pca2131Dev, year, month, day, hour, min, sec,
            hun, weekday))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Enable battery */
        (void) PCA2131_PowerModeSet(&pca2131Dev, 0U);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get RTC time                                                             */
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
        uint32_t year, month, day, hour, min, sec, hun, weekday;

        /* Read RTC */
        if (PCA2131_RtcGet(&pca2131Dev, &year, &month, &day, &hour, &min,
            &sec, &hun, &weekday))
        {
            uint32_t days, secs;

            /* Covert year */
            if (year >= 70U)
            {
                year = year + 1900U;
            }
            else
            {
                year = year + 2000U;
            }

            /* Convert to days */
            date2days(year, month, day, &days);

            /* Calculate seconds */
            secs = sec + (min * 60U) + (hour * 3600U);
            secs += (days * 86400U);

            /* Check time format */
            if (ticks)
            {
                *val = (((uint64_t) secs) * 100U) + hun;
            }
            else
            {
                *val = ((uint64_t) secs);
            }
        }
        else
        {
            status = SM_ERR_HARDWARE_ERROR;
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
        bool st;

        /* Default state */
        *state = 0U;

        /* Enable battery */
        (void) PCA2131_PowerModeSet(&pca2131Dev, 0U);

        /* Get battery state */
        if (PCA2131_TimeStatusGet(&pca2131Dev, &st))
        {
            if (st)
            {
                *state |= LMM_BBM_STATE_RESET;
            }
        }
        else
        {
            status = SM_ERR_HARDWARE_ERROR;
        }

        /* Get battery state */
        if (PCA2131_BattStatusGet(&pca2131Dev, &st))
        {
            if (st)
            {
                *state |= LMM_BBM_STATE_BATT_LOW;
            }
        }
        else
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set RTC alarm                                                            */
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
            uint32_t year, month, day, hour, min, sec, weekday;
            uint32_t days, hours, mins, secs;

            /* Convert to seconds */
            secs = (uint32_t) val;

            /* Calculate totals */
            mins = secs / 60U;
            hours = secs / 3600U;
            days = secs / 86400U;

            /* Calculate time */
            sec = secs % 60U;
            min = mins % 60U;
            hour = hours % 24U;

            /* Convert to date */
            days2date((uint32_t) days, &year, &month, &day, &weekday);

            /* Covert year */
            year %= 100U;

            /* Write to RTC */
            if (PCA2131_AlarmSet(&pca2131Dev, day, hour, min, sec,
                weekday))
            {
                /* Enable interrupt */
                if (PCA2131_IntEnable(&pca2131Dev, true))
                {
                    /* Enable bus expander interrupt */
                    status = BRD_SM_BusExpMaskSet(0U, BIT8(6));
                }
                else
                {
                    status = SM_ERR_HARDWARE_ERROR;
                }
            }
            else
            {
                status = SM_ERR_HARDWARE_ERROR;
            }

            /* Track if enabled for PCA2131 use */
            if (status == SM_ERR_SUCCESS)
            {
                pca2131Used = true;
            }
        }
        else
        {
            /* Disable interrupt */
            if (PCA2131_IntEnable(&pca2131Dev, false))
            {
                /* Disable bus expander interrupt */
                status = BRD_SM_BusExpMaskSet(BIT8(6), BIT8(6));
            }
            else
            {
                status = SM_ERR_HARDWARE_ERROR;
            }
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* PCA2131 interrupt handler                                                */
/*--------------------------------------------------------------------------*/
void BRD_SM_BbmHandler(void)
{
    /* Handle alarm */
    LMM_BbmRtcAlarmEvent(BRD_SM_RTC_PCA2131);

    /* Clear status flags */
    (void) PCA2131_IntClear(&pca2131Dev);
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Convert days since 1-1-1970 to date/time                                 */
/*--------------------------------------------------------------------------*/
static void days2date(uint32_t days, uint32_t *year, uint32_t *month,
    uint32_t *day, uint32_t *weekday)
{
    uint32_t newDays;
    uint32_t era;
    uint32_t doe;
    uint32_t yoe;
    uint32_t doy;
    uint32_t moy;

    /* Adjust to 1-1-1970) */
    newDays = days + 719468U;

    /* Calculate the era */
    era = newDays / 146097U;

    /* Calculate the day in the era */
    doe = newDays - (era * 146097U);

    /* Calculate the year of era */
    yoe = (doe - (doe / 1460U) + (doe / 36524U) - (doe / 146096U)) / 365U;

    /* Calculate year */
    *year = yoe + (era * 400U);

    /* Calculate day of the year */
    doy = doe - ((365U * yoe) + (yoe / 4U) - (yoe / 100U));

    /* Calculate month of year */
    moy = ((5U * doy) + 2U) / 153U;

    /* Calculate day */
    *day = doy - (((153U * moy) + 2U) / 5U) + 1U;

    /* Calculate month */
    *month= (moy < 10U) ? (moy + 3U) : (moy - 9U);

    /* Calculate day of the week */
    *weekday = (days + 4U) % 7U;

    /* Adjust year */
    *year += (*month <= 2U) ? 1U : 0U;
}

/*--------------------------------------------------------------------------*/
/* Convert date/time to days since 1-1-1970                                 */
/*--------------------------------------------------------------------------*/
static void date2days(uint32_t year, uint32_t month, uint32_t day,
    uint32_t *days)
{
    uint32_t newYear;
    uint32_t era;
    uint32_t doe;
    uint32_t yoe;
    uint32_t doy;
    uint32_t moy;

    /* Adjust year */
    newYear = year - ((month <= 2U) ? 1U : 0U);

    /* Calculate era */
    era = newYear / 400U;

    /* Calculate the year of era */
    yoe = newYear - (era * 400U);

    /* Calculate month of year */
    moy = (month > 2U) ? (month - 3U) : (month + 9U);

    /* Calculate day of the year */
    doy = (((153U * moy) + 2U) / 5U) + (day - 1U);

    /* Calculate the day in the era */
    doe = (yoe * 365U) + (yoe / 4U) - (yoe / 100U) + doy;

    /* Calculate days */
    *days = (era * 146097U) + doe - 719468U;
}

