/*
** ###################################################################
**
**     Copyright 2024-2026 NXP
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
/* File containing the implementation of the fuse access functions.         */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Init fuses                                                               */
/*--------------------------------------------------------------------------*/
void DEV_SM_FuseInit(void)
{
}

/*--------------------------------------------------------------------------*/
/* Get address of a fuse word                                               */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_FuseInfoGet(uint32_t fuseWord, uint32_t *addr)
{
    int32_t status = SM_ERR_SUCCESS;

    if (fuseWord != 50U)
    {
        uint32_t val = 0x80008000U + (fuseWord * 4U);
        *addr = val;
    }
    else
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Return result */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Read a fuse field                                                        */
/*--------------------------------------------------------------------------*/
uint32_t DEV_SM_FuseGet(uint32_t fuseId)
{
    uint32_t rtn = 0U;

    /* PD7 disabled */
    if (fuseId == 7U)
    {
        rtn = 1U;
    }

    /* Return result */
    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Get the fuse state of a power domain                                     */
/*--------------------------------------------------------------------------*/
bool DEV_SM_FusePdDisabled(uint32_t domainId)
{
    bool pdDisabled = false;

    if (domainId >= DEV_SM_NUM_POWER)
    {
        pdDisabled = true;
    }
    else
    {
        if (DEV_SM_FuseGet(domainId) != 0U)
        {
            pdDisabled = true;
        }
    }

    /* Return state */
    return pdDisabled;
}

/*--------------------------------------------------------------------------*/
/* Get the fuse state of a CPU ID                                           */
/*--------------------------------------------------------------------------*/
bool DEV_SM_FuseCpuDisabled(uint32_t cpuId)
{
    bool cpuDisabled = false;

    if (cpuId >= DEV_SM_NUM_POWER)
    {
        cpuDisabled = true;
    }

    /* Return state */
    return cpuDisabled;
}

