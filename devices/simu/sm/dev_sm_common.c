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
/* File containing the implementation of the common access functions.       */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "lmm.h"
#include <sys/time.h>

/* Local defines */

/* Local types */

/* Local variables */

/* Global variables */

dev_sm_syslog_t g_syslog;

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Get silicon info                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SiInfoGet(uint32_t *deviceId, uint32_t *siRev,
    uint32_t *partNum, string *siNameAddr, string *pnNameAddr)
{
    int32_t status = SM_ERR_SUCCESS;
    static string siName = "Simulation";
    static string pnName = "SimPn";

    /* Return device ID */
    if (deviceId != NULL)
    {
        *deviceId = 0U;
    }

    /* Return silicon rev */
    if (siRev != NULL)
    {
        *siRev = 0U;
    }

    /* Return part number */
    if (partNum != NULL)
    {
        *partNum = 0U;
    }

    /* Return name */
    if (siNameAddr != NULL)
    {
        *siNameAddr = siName;
    }

    /* Return name */
    if (pnNameAddr != NULL)
    {
        *pnNameAddr = pnName;
    }

    /* Return result */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get silicon version                                                      */
/*--------------------------------------------------------------------------*/
uint32_t DEV_SM_SiVerGet(void)
{
    /* Return version */
    return 0U;
}

/*--------------------------------------------------------------------------*/
/* Get the syslog                                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SyslogGet(uint32_t flags, const dev_sm_syslog_t **syslog,
    uint32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return data */
    *syslog = &g_syslog;
    *len = sizeof(dev_sm_syslog_t);

    /* Return result */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Dump the syslog                                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SyslogDump(uint32_t flags)
{
    int32_t status;
    const dev_sm_syslog_t *syslog;
    uint32_t len;

    /* Get data */
    status = DEV_SM_SyslogGet(flags, &syslog, &len);

    if (status == SM_ERR_SUCCESS)
    {
        printf("Sys sleep mode  = %u\n", syslog->sysSleepMode);
        printf("Sys sleep flags = 0x%08X\n", syslog->sysSleepFlags);
        printf("Device err log  = 0x%08X\n", syslog->devErrLog);
    }

    /* Return result */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get time in microseconds                                                 */
/*--------------------------------------------------------------------------*/
uint64_t DEV_SM_Usec64Get(void)
{
    struct timeval tv = { 0 };
    int64_t tm = 0LL;

    /* Get time */
    (void) gettimeofday(&tv, NULL);

    /* Convert to microseconds */
    tm = (tv.tv_sec * 1000000LL) + tv.tv_usec;

    /* Check for signed bit of the tm */
    if (!CHECK_I64_POSITIVE(tm))
    {
        tm = 0LL;
    }

    return (uint64_t) tm;
}

/*--------------------------------------------------------------------------*/
/* Log device errors                                                        */
/*--------------------------------------------------------------------------*/
void DEV_SM_ErrorLog(uint32_t err)
{
    g_syslog.devErrLog |= err;
}

/*--------------------------------------------------------------------------*/
/* Dump device errors                                                       */
/*--------------------------------------------------------------------------*/
void DEV_SM_ErrorDump(void)
{
    if (g_syslog.devErrLog != 0U)
    {
        printf("DEV init err: 0x%08X\n", g_syslog.devErrLog);
    }
}

/*--------------------------------------------------------------------------*/
/* Get max string length in array                                           */
/*--------------------------------------------------------------------------*/
void DEV_SM_MaxStringGet(int32_t *len, int32_t *maxLen,
    string const *name, uint32_t sz)
{
    /* Length requested? */
    if (len != NULL)
    {
        /* Already known? */
        if (*maxLen == 0)
        {
            /* Loop over array */
            for (uint32_t idx = 0U; idx < sz; idx++)
            {
                /* Get max len */
                *maxLen = MAX(*maxLen, (int32_t) DEV_SM_StrLen(name[idx]));
            }
        }

        /* Return result */
        *len = MAX(*len, *maxLen);
    }
}

/*--------------------------------------------------------------------------*/
/* Trigger software interrupt                                               */
/*--------------------------------------------------------------------------*/
void SWI_Trigger(void)
{
    LMM_Handler();
}

/*--------------------------------------------------------------------------*/
/* Get length of a string                                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_StrLen(string str)
{
    const char *p = str;
    int32_t len = 0;

    /* Loop over string */
    while ((p != NULL) && (*p != '\0'))
    {
        /* Check for wrap */
        if (len <= (INT32_MAX - 1))
        {
            len++;
            p++;
        }
        else
        {
            break;
        }
    }

    /* Return result */
    return len;
}

