/*
** ###################################################################
**
**     Copyright 2025-2026 NXP
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
    uint32_t addr;   /* Address of control */
    uint32_t mask;   /* Mask of control */
    uint32_t words;  /* Number of full words */
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
    [DEV_SM_CTRL_MQS2_SETTINGS] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x10U,
        .mask = 0x0000FF0EU,
    },
    [DEV_SM_CTRL_SAI1_MCLK] =
    {
        .addr = BLK_CTRL_NS_AONMIX_BASE + 0xA4U,
        .mask = 0x00000007U,
    },
    [DEV_SM_CTRL_SAI2_MCLK] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x1CU,
        .mask = 0x000001FFU,
    },
    [DEV_SM_CTRL_SAI3_MCLK] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x1CU,
        .mask = 0x0003FE00U,
    },
    [DEV_SM_CTRL_SAI4_MCLK] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x1CU,
        .mask = 0x07FC0000U,
    },
    [DEV_SM_CTRL_ADC_TEST] =
    {
        .addr = BLK_CTRL_BBSMMIX_BASE + 0x4U,
        .mask = 0x00000080U,
    },
    [DEV_SM_CTRL_GPT_MUX] =
    {
        .addr = BLK_CTRL_NS_AONMIX_BASE + 0x2CU,
        .mask = 0x001FFFFFU,
    },
    [DEV_SM_CTRL_XBAR_DIR_CTRL] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x270U,
        .words = 2U,
    },
    [DEV_SM_CTRL_XBAR_TRIG_SYNC] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x254U,
        .words = 4U,
    },
    [DEV_SM_CTRL_ADC_TRIGGER] =
    {
        .addr = BLK_CTRL_NS_AONMIX_BASE + 0xB4U,
        .mask = 0x0000000FU,
    },
    [DEV_SM_CTRL_HPF1_SYNC_SRC_CFG1] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x210U,
        .mask = 0x1FFFFFFFU,
    },
    [DEV_SM_CTRL_HPF1_SYNC_SRC_CFG2] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x214U,
        .mask = 0x000001FFU,
    },
    [DEV_SM_CTRL_HPF2_SYNC_SRC_CFG1] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x218U,
        .mask = 0x1FFFFFFFU,
    },
    [DEV_SM_CTRL_HPF2_SYNC_SRC_CFG2] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x21CU,
        .mask = 0x000001FFU,
    },
    [DEV_SM_CTRL_HPF1_INTR_CTRL] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x220U,
        .mask = 0x000001FFU,
    },
    [DEV_SM_CTRL_HPF2_INTR_CTRL] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x224U,
        .mask = 0x000001FFU,
    },
    [DEV_SM_CTRL_ENDAT3_STATUS] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x22CU,
        .mask = 0x000000FFU,
    },
    [DEV_SM_CTRL_ENC_DIAG_MUX_SEL] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x244U,
        .mask = 0x00000033U,
    },
    [DEV_SM_CTRL_HPF_SYNC_OUT_CTL] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x2A8U,
        .mask = 0x00000003U,
    },
    [DEV_SM_CTRL_ENDAT_STRETCH_CTRL] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x2ECU,
        .mask = 0x001FFFFFU,
    },
    [DEV_SM_CTRL_BISS1_PULSE_STR_CTL] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x308U,
        .mask = 0x0000007FU,
    },
    [DEV_SM_CTRL_XBAR_TRIG_SYNC_2] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x258U,
        .mask = 0x0000FFFFU,
    },
    [DEV_SM_CTRL_XBAR_TRIG_SYNC_3] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x25CU,
        .mask = 0xFFFFFFFFU,
    },
    [DEV_SM_CTRL_XBAR_TRIG_SYNC_4] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x260U,
        .mask = 0xFFFFFFFFU,
    },
    [DEV_SM_CTRL_XBAR_DIR_CTRL_2] =
    {
        .addr = BLK_CTRL_WAKEUPMIX_BASE + 0x274U,
        .mask = 0x1FFFFU,
    }
};

/*--------------------------------------------------------------------------*/
/* Get control attributes                                                   */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ControlAttributes(uint32_t ctrlId, bool *get, bool *set,
    bool *extGet, bool *extSet, bool *action, bool *notify)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check control */
    if (ctrlId < DEV_SM_NUM_CTRL)
    {
        *get = true;
        *set = true;
        *extGet = false;
        *extSet = false;
        *action = false;
        *notify = false;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

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
        uint32_t words = s_control[ctrlId].words;

        if (words == 0U)
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
            if (numVal == words)
            {
                /* Loop over all words */
                for (uint32_t idx = 0U; idx < words; idx++)
                {
                    Write32(s_control[ctrlId].addr + (idx * 4U),
                        val[idx]);
                }
            }
            else
            {
                status = SM_ERR_INVALID_PARAMETERS;
            }
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
        uint32_t words = s_control[ctrlId].words;

        if (words == 0U)
        {
            *numRtn = 1U;
            rtn[0] = (Read32(s_control[ctrlId].addr)
                & s_control[ctrlId].mask);
        }
        else
        {
            *numRtn = words;

            /* Loop over all words */
            for (uint32_t idx = 0U; idx < words; idx++)
            {
                rtn[idx] = Read32(s_control[ctrlId].addr + (idx * 4U));
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
/* Set an extended control value                                            */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ControlExtSet(uint32_t ctrlId, uint32_t addr,
    uint32_t numVal, const uint32_t *val)
{
    int32_t status;

    /* Check control */
    if (ctrlId < DEV_SM_NUM_CTRL)
    {
        status = SM_ERR_NOT_SUPPORTED;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get an extended control value                                            */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ControlExtGet(uint32_t ctrlId, uint32_t addr,
    uint32_t numRtn, uint32_t *rtn)
{
    int32_t status;

    /* Check control */
    if (ctrlId < DEV_SM_NUM_CTRL)
    {
        status = SM_ERR_NOT_SUPPORTED;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    if (numRtn > 0U)
    {
        /* Nothing to return */
        *rtn = 0U;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Do a control action                                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_ControlAction(uint32_t ctrlId, uint32_t action,
    /* coverity[misra_c_2012_rule_8_13_violation] */
    uint32_t numArg, const uint32_t *arg, uint32_t *numRtn, uint32_t *rtn)
{
    int32_t status;

    /* Check control */
    if (ctrlId < DEV_SM_NUM_CTRL)
    {
        status = SM_ERR_NOT_SUPPORTED;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

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
    int32_t status;

    /* Check control */
    if (ctrlId < DEV_SM_NUM_CTRL)
    {
        status = SM_ERR_NOT_SUPPORTED;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

