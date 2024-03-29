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
/* File containing the implementation of the common access functions.       */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "fsl_sysctr.h"

/* Local defines */

#define BASE(X)         (((X) >> 4U) & 0xFU)
#define METAL(X)        (((X) >> 0U) & 0xFU)

#define MINOR_BASE(X)   (((X) & 0xFU) << 4U)
#define MINOR_METAL(X)  (((X) & 0xFU) << 0U)

#define REV_BASE(X)     (((X) >> 2U) & 0x3U)
#define REV_METAL(X)    (((X) >> 0U) & 0x3U)

#define PN_DESIG(X)     (((X) >> 4U) & 0xFU)
#define PN_CORES(X)     (((X) >> 0U) & 0xFU)

/* Local types */

/* Local variables */

/* Local functions */

static void DEV_SM_StrCpy(char *dst, const char *src, uint32_t maxLen);

/*--------------------------------------------------------------------------*/
/* Get silicon info                                                         */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_SiInfoGet(uint32_t *deviceId, uint32_t *siRev,
    uint32_t *partNum, string *siNameAddr)
{
    int32_t status = SM_ERR_SUCCESS;
    static char s_siName[16];
    static bool s_updated = false;

    /* Return initial data */
    *deviceId = OSC24M->DIGPROG_DEVICE_ID;
    *siRev = (FSB->FUSE[FSB_FUSE_HW_CFG0] & FSB_FUSE_HW_CFG0_SI_REV_MASK)
        >> FSB_FUSE_HW_CFG0_SI_REV_SHIFT;
    *partNum = (FSB->FUSE[FSB_FUSE_HW_CFG0] & FSB_FUSE_HW_CFG0_PART_NUM_MASK)
        >> FSB_FUSE_HW_CFG0_PART_NUM_SHIFT;

    if (!s_updated)
    {
        uint32_t tmpMinor;
        uint32_t fuseMinor;

        /* Copy name */
        DEV_SM_StrCpy(s_siName, "i.MX9596 A0", 15U);

        /* Update minor version */
        tmpMinor = (*deviceId & OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR_MASK)
            >> OSC24M_DIGPROG_DEVICE_ID_DIGPROG_MINOR_SHIFT;
        tmpMinor -= MINOR_BASE(1U);
        fuseMinor = MINOR_BASE(REV_BASE(*siRev))
            | MINOR_METAL(REV_METAL(*siRev));
        tmpMinor = MAX(tmpMinor, fuseMinor);

        /* Update name */
        s_siName[9] = 'A' + (char) BASE(tmpMinor);
        s_siName[10] = '0' + (char) METAL(tmpMinor);

        /* Update part num */
        if (*partNum != 0U)
        {
            s_siName[6] = '0' + (char) PN_DESIG(*partNum);
            s_siName[7] = '0' + (char) PN_CORES(*partNum);
        }

        /* Mark updated */
        s_updated = true;
    }

    /* Return name */
    *siNameAddr = s_siName;

    return status;
}

/*--------------------------------------------------------------------------*/
/* Get time in microseconds                                                 */
/*--------------------------------------------------------------------------*/
uint64_t DEV_SM_Usec64Get(void)
{
    return SYSCTR_GetUsec64();
}

/*--------------------------------------------------------------------------*/
/* Get address of a fuse word                                               */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_FuseInfoGet(uint32_t fuseWord, uint32_t *addr)
{
    int32_t status = SM_ERR_SUCCESS;

    if (fuseWord < 610U)
    {
        *addr = FSB_BASE + 0x8000U + (fuseWord * 4U);
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Dump device errors                                                       */
/*--------------------------------------------------------------------------*/
void DEV_SM_ErrorDump(void)
{
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
/* Get length of a string                                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_StrLen(string str)
{
    const char *p = str;
    int32_t len = 0;

    /* Loop over string */
    while (*p != '\0')
    {
        len++;
        p++;
    }

    /* Return result */
    return len;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Bounded string copy                                                      */
/*--------------------------------------------------------------------------*/
static void DEV_SM_StrCpy(char *dst, const char *src, uint32_t maxLen)
{
    char *pDst = dst;
    const char *pSrc = src;
    uint8_t len = 1U;

    while ((len < maxLen) && (*pSrc != '\0'))
    {
        *pDst = *pSrc;
        pDst++;
        pSrc++;
        len++;
    }
    *pDst = '\0';
}

