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
/* File containing the implementation of the device controls.               */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Device control map structure */
typedef struct
{
    uint32_t addr;  /* Address of control */
    uint32_t mask;  /* Mask of control */
} dev_sm_ctrl_t;

/* Local variables */

static const dev_sm_ctrl_t s_control[DEV_SM_NUM_CTRL] =
{
    [DEV_SM_CTRL_PDM_CLK_SEL] =
    {
        .addr = BLK_CTRL_NS_AONMIX_BASE + 0x78U,
        .mask = 0x00000001U,
    },
    [DEV_SM_CTRL_MQS1_SETTINGS] =
    {
        .addr = BLK_CTRL_NS_AONMIX_BASE + 0x88U,
        .mask = 0x0000FF0EU,
    },
    [DEV_SM_CTRL_SAI1_MCLK] =
    {
        .addr = BLK_CTRL_NS_AONMIX_BASE + 0xA4U,
        .mask = 0x00000007U,
    },
    [DEV_SM_CTRL_SAI3_MCLK] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x1CU,
        .mask = 0x000001FFU,
    },
    [DEV_SM_CTRL_SAI4_MCLK] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x1CU,
        .mask = 0x0003FE00U,
    },
    [DEV_SM_CTRL_SAI5_MCLK] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x1CU,
        .mask = 0x07FC0000U,
    },
    [DEV_SM_CTRL_ADC_TEST] =
    {
        .addr = BLK_CTRL_BBSMMIX_BBSMMIX1_BASE + 0x4U,
        .mask = 0x00000080U,
    }
};

/*--------------------------------------------------------------------------*/
/* Set a control value                                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ControlSet(uint32_t ctrlId, uint32_t numVal,
    const uint32_t *val)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check control */
    if (ctrlId < DEV_SM_NUM_CTRL)
    {
        if (numVal == 1U)
        {
            uint32_t temp = Read32(s_control[ctrlId].addr);

            /* Clear fields */
            temp &= ~s_control[ctrlId].mask;

            /* Update fields */
            temp |= (val[0] & s_control[ctrlId].mask);

            /* Write value */
            Write32(s_control[ctrlId].addr, temp);
        }
        else
        {
            status = SM_ERR_INVALID_PARAMETERS;
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
/* Get a control value                                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ControlGet(uint32_t ctrlId, uint32_t *numRtn, uint32_t *rtn)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check control */
    if (ctrlId < DEV_SM_NUM_CTRL)
    {
        *numRtn = 1U;
        rtn[0] = (Read32(s_control[ctrlId].addr)
            & s_control[ctrlId].mask);
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
/* Set an extended control value                                            */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ControlExtSet(uint32_t ctrlId, uint32_t addr,
    uint32_t numVal, const uint32_t *val)
{
    return SM_ERR_NOT_SUPPORTED;
}

/*--------------------------------------------------------------------------*/
/* Get an extended control value                                            */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ControlExtGet(uint32_t ctrlId, uint32_t addr,
    uint32_t numRtn, uint32_t *rtn)
{
    if (numRtn > 0U)
    {
        *rtn = 0U;
    }

    return SM_ERR_NOT_SUPPORTED;
}

/*--------------------------------------------------------------------------*/
/* Do a control action                                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ControlAction(uint32_t ctrlId, uint32_t action,
    // coverity[misra_c_2012_rule_8_13_violation:FALSE]
    uint32_t numArg, const uint32_t *arg, uint32_t *numRtn, uint32_t *rtn)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Nothing to return */
    *numRtn = 0U;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Configure notification flags                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ControlFlagsSet(uint32_t ctrlId, uint32_t flags)
{
    return SM_ERR_NOT_SUPPORTED;
}

