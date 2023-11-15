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
/* File containing the implementation of the device reset domains.          */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Return reset domain name                                                 */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ResetDomainNameGet(uint32_t domainId, string *domainNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_RESET] =
    {
        [DEV_SM_RST_0] = "RST0",
        [DEV_SM_RST_1] = "RST1",
        [DEV_SM_RST_2] = "RST2",
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_RESET);

    /* Check reset */
    if (domainId >= DEV_SM_NUM_RESET)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *domainNameAddr = s_name[domainId];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Reset domain                                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ResetDomain(uint32_t domainId, uint32_t resetState,
    bool toggle, bool assertNegate)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

