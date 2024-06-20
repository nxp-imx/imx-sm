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
/* battery-backed module.                                                   */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "lmm.h"
#include "dev_sm_api.h"

/* Local defines */

/* Local types */

typedef struct
{
    uint64_t alarmTime[SM_NUM_LM];
    uint64_t updateTime;
    bool alarmEnable[SM_NUM_LM];
} lm_rtc_info_t;

/* Local variables */

static lm_rtc_info_t s_rtcInfo[SM_NUM_RTC];

/* Local functions */

static int32_t LMM_BbmRtcAlarmUpdate(uint32_t rtcId);

/*--------------------------------------------------------------------------*/
/* Set BBM GPR                                                              */
/*--------------------------------------------------------------------------*/
int32_t LMM_BbmGprSet(uint32_t lmId, uint32_t index, uint32_t value)
{
    /* Just passthru to board/device */
    return SM_BBMGPRSET(index, value);
}

/*--------------------------------------------------------------------------*/
/* Get BBM GPR                                                              */
/*--------------------------------------------------------------------------*/
int32_t LMM_BbmGprGet(uint32_t lmId, uint32_t index, uint32_t *value)
{
    /* Just passthru to board/device */
    return SM_BBMGPRGET(index, value);
}

/*--------------------------------------------------------------------------*/
/* Return RTC name                                                          */
/*--------------------------------------------------------------------------*/
int32_t LMM_BbmRtcNameGet(uint32_t lmId, uint32_t rtcId, string *rtcNameAddr,
    int32_t *len)
{
    /* Just passthru to device */
    return SM_BBMRTCNAMEGET(rtcId, rtcNameAddr, len);
}

/*--------------------------------------------------------------------------*/
/* Return RTC info                                                          */
/*--------------------------------------------------------------------------*/
int32_t LMM_BbmRtcDescribe(uint32_t lmId, uint32_t rtcId, uint32_t *secWidth,
    uint32_t *tickWidth, uint32_t *ticksPerSec)
{
    /* Just passthru to device */
    return SM_BBMRTCDESCRIBE(rtcId, secWidth, tickWidth, ticksPerSec);
}

/*--------------------------------------------------------------------------*/
/* Set BBM RTC time                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_BbmRtcTimeSet(uint32_t lmId, uint32_t rtcId, uint64_t val,
    bool ticks)
{
    int32_t status;

    /* Just passthru to board/device */
    status =  SM_BBMRTCTIMESET(rtcId, val, ticks);

    /* Notify updated */
    if (status == SM_ERR_SUCCESS)
    {
        LMM_BbmRtcUpdateEvent(rtcId);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get BBM RTC time                                                         */
/*--------------------------------------------------------------------------*/
int32_t LMM_BbmRtcTimeGet(uint32_t lmId, uint32_t rtcId, uint64_t *val,
    bool ticks)
{
    /* Just passthru to board/device */
    return SM_BBMRTCTIMEGET(rtcId, val, ticks);
}

/*--------------------------------------------------------------------------*/
/* Get BBM RTC state                                                        */
/*--------------------------------------------------------------------------*/
int32_t LMM_BbmRtcStateGet(uint32_t lmId, uint32_t rtcId, uint32_t *state)
{
    /* Just passthru to board/device */
    return SM_BBMRTCSTATEGET(rtcId, state);
}

/*--------------------------------------------------------------------------*/
/* Set BBM RTC alarm                                                        */
/*--------------------------------------------------------------------------*/
int32_t LMM_BbmRtcAlarmSet(uint32_t lmId, uint32_t rtcId, bool enable,
    uint64_t val)
{
    /* Save alarm for LM */
    s_rtcInfo[rtcId].alarmTime[lmId] = val;
    s_rtcInfo[rtcId].alarmEnable[lmId] = enable;

    /* Update alarm */
    return LMM_BbmRtcAlarmUpdate(rtcId);
}

/*--------------------------------------------------------------------------*/
/* Enable BBM RTC rollover event                                            */
/*--------------------------------------------------------------------------*/
int32_t LMM_BbmRtcRollover(uint32_t lmId, uint32_t rtcId)
{
    /* Just passthru to board/device */
    return SM_BBMRTCROLLOVER(rtcId);
}

/*--------------------------------------------------------------------------*/
/* Set Get BBM button state                                                 */
/*--------------------------------------------------------------------------*/
int32_t LMM_BbmButtonGet(uint32_t lmId, bool *buttonAsserted)
{
    /* Just passthru to board/device */
    return SM_BBMBUTTONGET(buttonAsserted);
}

/*--------------------------------------------------------------------------*/
/* Report RTC alarm                                                         */
/*--------------------------------------------------------------------------*/
void LMM_BbmRtcAlarmEvent(uint32_t rtcId)
{
    /* Dispatch for all expired LM */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        /* Is enabled? */
        if (s_rtcInfo[rtcId].alarmEnable[dstLm])
        {
            /* Is alarm state pending? */
            if (s_rtcInfo[rtcId].alarmTime[dstLm]
                <= s_rtcInfo[rtcId].updateTime)
            {
                lmm_rpc_trigger_t trigger =
                {
                    .event = LMM_TRIGGER_RTC,
                    .parm[0] = rtcId,
                    .parm[1] = LMM_TRIGGER_PARM_RTC_ALARM
                };

                /* Boot LM */
                if ((g_lmmConfig[dstLm].autoBoot == LMM_AUTO_RTC)
                    || (g_lmmConfig[dstLm].autoBoot == LMM_AUTO_BOTH))
                {
                    lmm_rst_rec_t bootRec = DEV_SM_RST_REC_BBM;

                    /* Reason is BBM RTC */
                    bootRec.errId = DEV_SM_BBM_BOOT_ALARM;
                    bootRec.validErr = true;

                    (void) LMM_SystemLmBoot(0U, 0U, dstLm, &bootRec);
                }

                s_rtcInfo[rtcId].alarmEnable[dstLm] = false;
                (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
            }
        }
    }

    /* Update alarm */
    (void) LMM_BbmRtcAlarmUpdate(rtcId);
}

/*--------------------------------------------------------------------------*/
/* Report RTC rollover                                                      */
/*--------------------------------------------------------------------------*/
void LMM_BbmRtcRolloverEvent(uint32_t rtcId)
{
    /* Dispatch for all LM */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        lmm_rpc_trigger_t trigger =
        {
            .event = LMM_TRIGGER_RTC,
            .parm[0] = rtcId,
            .parm[1] = LMM_TRIGGER_PARM_RTC_ROLLOVER
        };

        (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
    }
}

/*--------------------------------------------------------------------------*/
/* Report RTC update                                                        */
/*--------------------------------------------------------------------------*/
void LMM_BbmRtcUpdateEvent(uint32_t rtcId)
{
    /* Dispatch for all LM */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        lmm_rpc_trigger_t trigger =
        {
            .event = LMM_TRIGGER_RTC,
            .parm[0] = rtcId,
            .parm[1] = LMM_TRIGGER_PARM_RTC_UPDATE
        };

        (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
    }
}

/*--------------------------------------------------------------------------*/
/* Report button event                                                      */
/*--------------------------------------------------------------------------*/
void LMM_BbmButtonEvent(void)
{
    /* Dispatch for all LM */
    for (uint32_t dstLm = 0U; dstLm < SM_NUM_LM; dstLm++)
    {
        lmm_rpc_trigger_t trigger =
        {
            .event = LMM_TRIGGER_BUTTON,
        };

        /* Boot LM */
        if ((g_lmmConfig[dstLm].autoBoot == LMM_AUTO_BUTTON)
            || (g_lmmConfig[dstLm].autoBoot == LMM_AUTO_BOTH))
        {
            lmm_rst_rec_t bootRec = DEV_SM_RST_REC_BBM;

            /* Reason is BBM button */
            bootRec.errId = DEV_SM_BBM_BOOT_BUTTON;
            bootRec.validErr = true;

            (void) LMM_SystemLmBoot(0U, 0U, dstLm, &bootRec);
        }

        /* Send notification */
        (void) LMM_RpcNotificationTrigger(dstLm, &trigger);
    }
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Update RTC alarm                                                         */
/*--------------------------------------------------------------------------*/
static int32_t LMM_BbmRtcAlarmUpdate(uint32_t rtcId)
{
    bool updateEnable = false;

    /* Find next nearest alarm */
    s_rtcInfo[rtcId].updateTime = (uint64_t) -1;
    for (uint32_t lm = 0U; lm < SM_NUM_LM; lm++)
    {
        /* Is enabled? */
        if (s_rtcInfo[rtcId].alarmEnable[lm])
        {
            /* Is earlier? */
            if (s_rtcInfo[rtcId].alarmTime[lm]
                < s_rtcInfo[rtcId].updateTime)
            {
                s_rtcInfo[rtcId].updateTime
                    = s_rtcInfo[rtcId].alarmTime[lm];
                updateEnable = s_rtcInfo[rtcId].alarmEnable[lm];
            }
        }
    }

    /* Inform board/device of new alarm */
    return SM_BBMRTCALARMSET(rtcId, updateEnable,
        s_rtcInfo[rtcId].updateTime);
}

