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
/* File containing the implementation of the board controls.                */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "brd_sm.h"
#include "lmm.h"

/* Local defines */

/* PCAL6408A input signals */
#define PCAL6408A_INPUT_SD3_WAKE     0U
#define PCAL6408A_INPUT_PCIE1_WAKE   4U
#define PCAL6408A_INPUT_BT_WAKE      5U
#define PCAL6408A_INPUT_PCIE2_WAKE   6U
#define PCAL6408A_INPUT_BUTTON       7U

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Get a control value                                                      */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_ControlGet(uint32_t ctrlId, uint32_t *numRtn, uint32_t *rtn)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check to see if ctrlId is within bounds*/
    if (ctrlId < SM_NUM_CTRL)
    {
        /* Check if device or board */
        if (ctrlId < DEV_SM_NUM_CTRL)
        {
            status = DEV_SM_ControlGet(ctrlId, numRtn, rtn);
        }
        else
        {
            uint8_t data;

            /* Read expander data input */
            if (PCAL6408A_InputGet(&pcal6408aDev, &data))
            {
                uint32_t shift = ctrlId - DEV_SM_NUM_CTRL;

                /* Adjust bit position */
                if (shift > 0U)
                {
                    shift += 3U;
                }

                *numRtn = 1U;
                rtn[0] = (((uint32_t) data) >> shift) & 0x1UL;
            }
            else
            {
                status = SM_ERR_HARDWARE_ERROR;
            }
        }
    }
    else
    {
        *numRtn = 0U;
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure notification flags                                             */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_ControlFlagsSet(uint32_t ctrlId, uint32_t flags)
{
    int32_t status = SM_ERR_SUCCESS;
    uint8_t mask;
    uint32_t val;

    switch (ctrlId)
    {
        case BRD_SM_CTRL_SD3_WAKE:
            mask = BIT8(PCAL6408A_INPUT_SD3_WAKE);
            val = (flags & 0x1U) << PCAL6408A_INPUT_SD3_WAKE;
            break;
        case BRD_SM_CTRL_PCIE1_WAKE:
            mask = BIT8(PCAL6408A_INPUT_PCIE1_WAKE);
            val = (flags & 0x1U) << PCAL6408A_INPUT_PCIE1_WAKE;
            break;
        case BRD_SM_CTRL_BT_WAKE:
            mask = BIT8(PCAL6408A_INPUT_BT_WAKE);
            val = (flags & 0x1U) << PCAL6408A_INPUT_BT_WAKE;
            break;
        case BRD_SM_CTRL_PCIE2_WAKE:
            mask = BIT8(PCAL6408A_INPUT_PCIE2_WAKE);
            val = (flags & 0x1U) << PCAL6408A_INPUT_PCIE2_WAKE;
            break;
        case BRD_SM_CTRL_BUTTON:
            mask = BIT8(PCAL6408A_INPUT_BUTTON);
            val = (flags & 0x1U) << PCAL6408A_INPUT_BUTTON;
            break;
        default:
            status = SM_ERR_NOT_SUPPORTED;
            break;
    }

    if (status == SM_ERR_SUCCESS)
    {
        static uint8_t cachedMask = PCAL6408A_INITIAL_MASK;
        uint8_t newMask = (cachedMask & ~mask) | ((uint8_t) val);

        /* Mask changed? */
        if (cachedMask != newMask)
        {
            if (PCAL6408A_IntMaskSet(&pcal6408aDev, newMask))
            {
                cachedMask = newMask;
            }
            else
            {
                status = SM_ERR_HARDWARE_ERROR;
            }
        }
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Control handler                                                          */
/*--------------------------------------------------------------------------*/
void BRD_SM_ControlHandler(uint8_t status, uint8_t val)
{
    uint32_t data = (uint32_t) val;

    /* Handle SD3 wake */
    if ((status & BIT8(PCAL6408A_INPUT_SD3_WAKE)) != 0U)
    {
        LMM_MiscControlEvent(BRD_SM_CTRL_SD3_WAKE,
            (data >> PCAL6408A_INPUT_SD3_WAKE) & 0x1U);
    }

    /* Handle PCIe1 wake */
    if ((status & BIT8(PCAL6408A_INPUT_PCIE1_WAKE)) != 0U)
    {
        LMM_MiscControlEvent(BRD_SM_CTRL_PCIE1_WAKE,
            (data >> PCAL6408A_INPUT_PCIE1_WAKE) & 0x1U);
    }

    /* Handle BT wake */
    if ((status & BIT8(PCAL6408A_INPUT_BT_WAKE)) != 0U)
    {
        LMM_MiscControlEvent(BRD_SM_CTRL_BT_WAKE,
            (data >> PCAL6408A_INPUT_BT_WAKE) & 0x1U);
    }

    /* Handle PCIe2 wake */
    if ((status & BIT8(PCAL6408A_INPUT_PCIE2_WAKE)) != 0U)
    {
        LMM_MiscControlEvent(BRD_SM_CTRL_PCIE2_WAKE,
            (data >> PCAL6408A_INPUT_PCIE2_WAKE) & 0x1U);
    }

    /* Handle button */
    if ((status & BIT8(PCAL6408A_INPUT_BUTTON)) != 0U)
    {
        LMM_MiscControlEvent(BRD_SM_CTRL_BUTTON,
            (data >> PCAL6408A_INPUT_BUTTON) & 0x1U);
    }
}

