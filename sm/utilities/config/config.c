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
/* File containing the implementation of the configuration functions        */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "config.h"

/* Local defines */

/* Local types */

/* Local variables */

static bool s_cond = true;

/* Local functions */

static int32_t DEV_SM_ExecOp(uint32_t *addr, const uint32_t *pc,
    const uint32_t **rtn);

/*--------------------------------------------------------------------------*/
/* Set condition                                                            */
/*--------------------------------------------------------------------------*/
void CONFIG_Condition(bool cond)
{
    /* Record condition */
    s_cond = cond;
}

/*--------------------------------------------------------------------------*/
/* Load configuration                                                       */
/*--------------------------------------------------------------------------*/
int32_t CONFIG_Load(const uint32_t *base, const uint32_t *config)
{
    int32_t status = SM_ERR_SUCCESS;
    const uint32_t *pc = config;
    const uint32_t *repeat = NULL;

    while ((status == SM_ERR_SUCCESS) && (*pc != SM_CFG_END))
    {
        uint32_t op;
        uint32_t oc;
        uint32_t ot;
        uint32_t *addr;

        /* Read and parse op */
        op = *pc;
        ot = (op & SM_CFG_OT_MASK) >> SM_CFG_OT_SHIFT;

        if (ot == SM_CFG_OT_BASE)
        {
            oc = (op & SM_CFG_OC_MASK) >> SM_CFG_OC_SHIFT;
            addr = (uint32_t*) ((((uint32_t) base) & 0xFFFF0000U)
                + (op & SM_CFG_OPA_MASK));
        }
        else
        {
            oc = SM_CFG_OC_WRITE;
            addr = (uint32_t*) (op & ~SM_CFG_OT_MASK);
        }

        if (oc != SM_CFG_OC_REPEAT)
        {
            repeat = pc;
            status = DEV_SM_ExecOp(addr, pc, &pc);
        }
        else
        {
            if (repeat != NULL)
            {
                status = DEV_SM_ExecOp(addr, repeat, NULL);
                pc++;
            }
            else
            {
                status = SM_ERR_INVALID_PARAMETERS;
            }
        }
    }

    return status;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Execute an operation                                                     */
/*--------------------------------------------------------------------------*/
static int32_t DEV_SM_ExecOp(uint32_t *addr, const uint32_t *pc,
    const uint32_t **rtn)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t *new_addr = addr;
    const uint32_t *new_pc = pc;
    uint32_t op;
    uint32_t ot;
    uint32_t oc;
    uint32_t len;
    uint32_t fill;

    /* Read op and advance pc */
    op = *new_pc;
    new_pc++;

    /* Parse op */
    ot = (op & SM_CFG_OT_MASK) >> SM_CFG_OT_SHIFT;
    if (ot == SM_CFG_OT_BASE)
    {
        oc = (op & SM_CFG_OC_MASK) >> SM_CFG_OC_SHIFT;
        len = (op & SM_CFG_OPL_MASK) >> SM_CFG_OPL_SHIFT;
    }
    else
    {
        oc = SM_CFG_OC_WRITE;
        len = 1U;
    }

    switch (oc)
    {
        case SM_CFG_OC_WRITE:
            while (len > 0U)
            {
                *new_addr = *new_pc;
                new_addr++;
                new_pc++;
                len--;
            }
            break;
        case SM_CFG_OC_CWRITE:
            while (len > 0U)
            {
                if (s_cond)
                {
                    *new_addr = *new_pc;
                }
                new_addr++;
                new_pc++;
                len--;
            }
            break;
        case SM_CFG_OC_FILL:
            fill = *new_pc;
            new_pc++;
            while (len > 0U)
            {
                *new_addr = fill;
                new_addr++;
                len--;
            }
            break;
        case SM_CFG_OC_ZERO:
            while (len > 0U)
            {
                *new_addr = 0U;
                new_addr++;
                len--;
            }
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return pc */
    if (rtn != NULL)
    {
        *rtn = new_pc;
    }

    return status;
}

