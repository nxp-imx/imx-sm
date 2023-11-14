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
/* File containing the implementation of the MU-based mailbox (MB_MU).      */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "fsl_device_registers.h"
#include "mb_mu.h"
#include "config_mb_mu.h"
#include "rpc_smt.h"
#include "fsl_mu.h"

/* Local defines */

/* Local types */

/* Local variables */

static const mb_mu_config_t s_mbMuConfig[SM_NUM_MB_MU] =
{
    SM_MB_MU_CONFIG_DATA
};

static MU_Type *const s_muBases[] = MU_BASE_PTRS;

/* Local functions */

/*--------------------------------------------------------------------------*/
/* MU Init                                                                  */
/*--------------------------------------------------------------------------*/
int32_t MB_MU_Init(uint8_t inst, uint8_t db, bool noIrq, uint32_t initCount)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check mu and gi */
    if ((inst >= SM_NUM_MB_MU) || (db >= SM_NUM_MB_MU_DB))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Init MU */
    if ((status == SM_ERR_SUCCESS) && (initCount == 0U))
    {
        static IRQn_Type const s_muIrqs[] = MU_IRQS;
        MU_Type *base = s_muBases[s_mbMuConfig[inst].mu];
        IRQn_Type irq = s_muIrqs[s_mbMuConfig[inst].mu];

        /* Init MU */
        MU_ResetBothSides(base);
        MU_Init(base);
        NVIC_EnableIRQ(irq);
    }

    /* Enable interrupts */
    if ((status == SM_ERR_SUCCESS) && !noIrq)
    {
        MU_Type *base = s_muBases[s_mbMuConfig[inst].mu];

        /* Enable GI interrupt */
        MU_EnableInterrupts(base, ((uint32_t) kMU_GenInt0InterruptEnable)
                << db);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get mailbox buffer address                                               */
/*--------------------------------------------------------------------------*/
uint32_t *MB_MU_SmaGet(uint8_t inst, uint8_t db)
{
    uint32_t sma = s_mbMuConfig[inst].sma;

    /* Allow use of internal MU SRAM */
    if (sma == 0U)
    {
        sma = ((uint32_t) s_muBases[s_mbMuConfig[inst].mu]) + 0x1000U;
    }

    /* Apply channel spacing */
    sma += ((uint32_t) db) * SM_MB_MU_BUF_SIZE;

    return (uint32_t*) sma;
}

/*--------------------------------------------------------------------------*/
/* Ring mailbox doorbell                                                    */
/*--------------------------------------------------------------------------*/
int32_t MB_MU_DoorbellRing(uint8_t inst, uint8_t db)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check mu and gi */
    if ((inst >= SM_NUM_MB_MU) || (db >= SM_NUM_MB_MU_DB))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Interrupt if no error */
    if (status == SM_ERR_SUCCESS)
    {
        MU_Type *base = s_muBases[s_mbMuConfig[inst].mu];

        /* Trigger GI interrupt */
        MU_TriggerInterrupts(base, ((uint32_t) kMU_GenInt0InterruptTrigger)
                << db);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get doorbell state and clear                                             */
/*--------------------------------------------------------------------------*/
bool MB_MU_DoorbellState(uint8_t inst, uint8_t db)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t flags = 0U;

    /* Check mu and gi */
    if ((inst >= SM_NUM_MB_MU) || (db >= SM_NUM_MB_MU_DB))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Read status and clear */
    if (status == SM_ERR_SUCCESS)
    {
        MU_Type *base = s_muBases[s_mbMuConfig[inst].mu];
        uint32_t mask = ((uint32_t) kMU_GenInt0Flag) << db;

        /* Get interrupt status flag for this db */
        flags = (MU_GetStatusFlags(base) & mask);

        /* Clear interrupt for this db */
        MU_ClearStatusFlags(base, flags);
    }

    /* Return status */
    return (flags != 0U);
}

/*--------------------------------------------------------------------------*/
/* Get abort status                                                         */
/*--------------------------------------------------------------------------*/
int32_t MB_MU_IsAborted(uint8_t inst, uint8_t db)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check mu and gi */
    if ((inst >= SM_NUM_MB_MU) || (db >= SM_NUM_MB_MU_DB))
    {
        status = SM_ERR_OUT_OF_RANGE;
    }

    /* Read MU flags */
    if (status == SM_ERR_SUCCESS)
    {
        MU_Type *base = s_muBases[s_mbMuConfig[inst].mu];
        uint32_t flags;

        /* Get MU flags */
        flags = MU_GetFlags(base);

        /* Check F0 (bit 0 of flags) */
        if ((flags & 1U) != 0U)
        {
            status = SM_ERR_ABORT_ERROR;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Common MU IRQ handler                                                    */
/*--------------------------------------------------------------------------*/
void MB_MU_Handler(uint32_t mu)
{
    MU_Type *base = s_muBases[mu];
    uint32_t flags;
    uint32_t mb;

    /* Get interrupt status flags */
    flags = MU_GetStatusFlags(base);

    /* Clear interrupts */
    MU_ClearStatusFlags(base, flags);

    /* Find mailbox */
    for (mb = 0U; mb < SM_NUM_MB_MU; mb++)
    {
        /* MU found? */
        if (s_mbMuConfig[mb].mu == mu)
        {
            /* Loop over pending GI */
            for (uint32_t gi = 0U; gi < SM_NUM_MB_MU_DB; gi++)
            {
                uint32_t mask = ((uint32_t) kMU_GenInt0Flag) << gi;

                if ((flags & mask) != 0U)
                {
                    /* Call transport */
                    switch (s_mbMuConfig[mb].xportType[gi])
                    {
                        case SM_XPORT_SMT:
                            RPC_SMT_Dispatch(
                                s_mbMuConfig[mb].xportChannel[gi]);
                            break;
                        default:
                            ; /* Intentional empty default */
                            break;
                    }
                }
            }
        }
    }
}

