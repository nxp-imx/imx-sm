/*
** ###################################################################
**
** Copyright 2023 NXP
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
/* File containing the implementation of the loopback mailbox (MB_LOOPBACK) */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "mb_loopback.h"
#include "config_mb_loopback.h"
#include "rpc_smt.h"

/* Local defines */

/* Local types */

static bool s_abortState[SM_NUM_MB_LOOPBACK];

/* Local variables */

static const mb_lb_config_t s_mbLbConfig[SM_NUM_MB_LOOPBACK] =
{
    SM_MB_LOOPBACK_CONFIG_DATA
};

/* Local functions */

/*--------------------------------------------------------------------------*/
/* MB Init                                                                  */
/*--------------------------------------------------------------------------*/
int32_t MB_LOOPBACK_Init(uint8_t inst, uint8_t db, bool noIrq,
    uint32_t initCount)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check inst and db */
    if ((inst >= SM_NUM_MB_LOOPBACK) || (db >= SM_NUM_MB_LB_DB))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get mailbox buffer address                                               */
/*--------------------------------------------------------------------------*/
uint32_t *MB_LOOPBACK_SmaGet(uint8_t inst, uint8_t db)
{
    static uint32_t s_smtBuffer[SM_NUM_MB_LOOPBACK][SM_NUM_MB_LB_DB]
    [SM_MB_LB_BUF_SIZE/4];

    return s_smtBuffer[inst][db];
}

/*--------------------------------------------------------------------------*/
/* Ring mailbox doorbell                                                    */
/*--------------------------------------------------------------------------*/
int32_t MB_LOOPBACK_DoorbellRing(uint8_t inst, uint8_t db)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check inst and db */
    if ((inst >= SM_NUM_MB_LOOPBACK) || (db >= SM_NUM_MB_LB_DB))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    switch (s_mbLbConfig[inst].xportType[db])
    {
        case SM_XPORT_SMT:
            RPC_SMT_Dispatch(s_mbLbConfig[inst].xportChannel[db]);
            break;
        default:
            ; /* Intentional empty default */
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set abort status                                                         */
/*--------------------------------------------------------------------------*/
int32_t MB_LOOPBACK_AbortSet(uint8_t inst, bool abort)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check inst */
    if (inst >= SM_NUM_MB_LOOPBACK)
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Ssave abort state */
    if (status == SM_ERR_SUCCESS)
    {
        s_abortState[inst] = abort;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get doorbell state and clear                                             */
/*--------------------------------------------------------------------------*/
bool MB_LOOPBACK_DoorbellState(uint8_t inst, uint8_t db)
{
    return false;
}

/*--------------------------------------------------------------------------*/
/* Get abort status                                                         */
/*--------------------------------------------------------------------------*/
int32_t MB_LOOPBACK_IsAborted(uint8_t inst, uint8_t db)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check inst and db */
    if ((inst >= SM_NUM_MB_LOOPBACK) || (db >= SM_NUM_MB_LB_DB))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Aborted? */
    if (s_abortState[inst])
    {
        status = SM_ERR_ABORT_ERROR;
    }

    /* Return status */
    return status;
}

