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
/* File containing the implementation of the device battery-backed module.  */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "lmm.h"
#include "fsl_bbnsm.h"

/* Local defines */

/* Local types */

/* Local variables */

static bool s_cleared = false;
static uint32_t s_statusFlags = 0U;

/*--------------------------------------------------------------------------*/
/* Init BBM                                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmInit(void)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t flags;

    /* Read status flags */
    flags = BBNSM_GetStatusFlags(BBNSM);

    /* Save flags if not already */
    if (s_statusFlags == 0U)
    {
        s_statusFlags = flags;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Clear BBM                                                                */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmClear(void)
{
    int32_t status = SM_ERR_SUCCESS;

    if (!s_cleared)
    {
        /* Disable interrupts */
        BBNSM_DisableInterrupts(BBNSM,
            ((uint32_t) kBBNSM_RTC_AlarmInterrupt)
            | ((uint32_t) kBBNSM_RTC_RolloverInterrupt));

        /* Clear pending alarm */
        (void) BBNSM_RTC_SetAlarm(BBNSM, (uint32_t) -1);

        /* Clear status flags */
        BBNSM_ClearStatusFlags(BBNSM, s_statusFlags);

        /* Mark as cleared */
        s_cleared = true;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return BBM status found at boot                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmGetBootStatus(uint32_t *flags)
{
    int32_t status = SM_ERR_SUCCESS;

    if (s_statusFlags != 0U)
    {
        *flags = 0U;

        /* Handle off */
        if ((s_statusFlags & ((uint32_t) kBBNSM_EMG_OFF_InterruptFlag))
            != 0U)
        {
            *flags |= DEV_SM_BBM_BOOT_OFF;
        }

        /* Handle button */
        if ((s_statusFlags & ((uint32_t) kBBNSM_PWR_ON_InterruptFlag))
            != 0U)
        {
            *flags |= DEV_SM_BBM_BOOT_BUTTON;
        }

        /* Handle alarm */
        if ((s_statusFlags & ((uint32_t) kBBNSM_RTC_AlarmInterruptFlag))
            != 0U)
        {
            *flags |= DEV_SM_BBM_BOOT_ALARM;
        }

        /* Handle rollover */
        if ((s_statusFlags & ((uint32_t) kBBNSM_RTC_RolloverInterruptFlag))
            != 0U)
        {
            *flags |= DEV_SM_BBM_BOOT_ROLLOVER;
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
/* Set BBM GPR                                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmGprSet(uint32_t index, uint32_t value)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check GPR */
    if (index >= DEV_SM_NUM_GPR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Set GPR and translate error */
        if (!BBNSM_GprSetValue(BBNSM, (uint8_t) index, value))
        {
            status = SM_ERR_INVALID_PARAMETERS;
        }
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
    if (index >= DEV_SM_NUM_GPR)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Get GPR and translate error */
        if (!BBNSM_GprGetValue(BBNSM, (uint8_t) index, value))
        {
            status = SM_ERR_INVALID_PARAMETERS;
        }
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
        [DEV_SM_RTC_BBNSM] = "bbnsm"
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
    /* Check time format */
    if (ticks)
    {
        /* Set ticks */
        BBNSM_RTC_SetTicks(BBNSM, val);
    }
    else
    {
        /* Set seconds */
        BBNSM_RTC_SetSeconds(BBNSM, SM_UINT64_L(val));
    }

    /* Return status */
    return SM_ERR_SUCCESS;
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
        *val = BBNSM_RTC_GetTicks(BBNSM);
    }
    else
    {
        /* Get seconds */
        *val = (uint64_t) BBNSM_RTC_GetSeconds(BBNSM);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get BBM RTC state                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmRtcStateGet(uint32_t rtcId, uint32_t *state)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Default state */
    *state = 0U;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set BBM RTC alarm                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmRtcAlarmSet(uint32_t rtcId, bool enable, uint64_t val)
{
    int32_t status;

    /* Clear before allowing alarm set */
    status = DEV_SM_BbmClear();

    /* Enable? */
    if (enable)
    {
        status_t kstat;

        /* Set alarm, enable, and enable interrupt */
        kstat = BBNSM_RTC_SetAlarm(BBNSM, SM_UINT64_L(val));

        /* Check driver error */
        if (kstat != kStatus_Success)
        {
            status = SM_ERR_INVALID_PARAMETERS;
        }
    }
    else
    {
        /* Disable alarm interrupt */
        BBNSM_DisableInterrupts(BBNSM, ((uint32_t)
            kBBNSM_RTC_AlarmInterrupt));

        /* Clear pending alarm */
        (void) BBNSM_RTC_SetAlarm(BBNSM, (uint32_t) -1);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Enable BBM RTC rollover interrupt                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmRtcRollover(uint32_t rtcId)
{
    int32_t status;

    /* Clear before allowing alarm enable */
    status = DEV_SM_BbmClear();

    /* Enable RTC rollover interrupt */
    BBNSM_EnableInterrupts(BBNSM, ((uint32_t) kBBNSM_RTC_RolloverInterrupt));

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set Get BBM button state                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_BbmButtonGet(bool *buttonAsserted)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t flags;

    /* Read BBM events */
    flags = BBNSM_GetStatusFlags(BBNSM);

    /* Check button status */
    *buttonAsserted = (flags & 0x80U) != 0U;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* BBM handler                                                              */
/*--------------------------------------------------------------------------*/
void DEV_SM_BbmHandler(void)
{
    uint32_t flags;

    /* Read status flags */
    flags = BBNSM_GetStatusFlags(BBNSM);

    if (s_cleared)
    {
        /* Handle alarm */
        if ((flags & ((uint32_t) kBBNSM_RTC_AlarmInterruptFlag)) != 0U)
        {
            LMM_BbmRtcAlarmEvent(DEV_SM_RTC_BBNSM);
        }

        /* Handle rollover */
        if ((flags & ((uint32_t) kBBNSM_RTC_RolloverInterruptFlag)) != 0U)
        {
            BBNSM_DisableInterrupts(BBNSM, ((uint32_t)
                kBBNSM_RTC_RolloverInterrupt));
            LMM_BbmRtcRolloverEvent(DEV_SM_RTC_BBNSM);
        }

        /* Handle button */
        if ((flags & ((uint32_t) kBBNSM_PWR_OFF_InterruptFlag)) != 0U)
        {
            LMM_BbmButtonEvent();
        }
    }

    /* Clear status flags */
    BBNSM_ClearStatusFlags(BBNSM, flags);

    /* Save flags if not already */
    if (s_statusFlags == 0U)
    {
        s_statusFlags = flags;
    }
}

