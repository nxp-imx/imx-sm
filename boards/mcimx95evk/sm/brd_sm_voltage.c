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
/* File containing the implementation of the board voltages.                */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "brd_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Return voltage name                                                      */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageNameGet(uint32_t domainId, string *voltNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[BRD_SM_NUM_VOLT] =
    {
        "vdd_gpio_3p3",
        "vdd_ana_0p8",
        "vdd_gpio_1p8",
        "vddq_ddr",
        "vdd2_ddr",
        "sd_card",
        "nvcc_sd2"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, BRD_SM_NUM_VOLT);

    /* Check to see if domain is within bounds*/
    if (domainId < SM_NUM_VOLT)
    {
        /* Check if device or board */
        if (domainId < DEV_SM_NUM_VOLT)
        {
            status = DEV_SM_VoltageNameGet(domainId, voltNameAddr, len);
        }
        else
        {
            /* Return pointer to name */
            *voltNameAddr = s_name[domainId - DEV_SM_NUM_VOLT];
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
/* Return supported voltage range                                           */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageDescribe(uint32_t domainId,
    dev_sm_voltage_range_t *range)
{
    int32_t status = SM_ERR_HARDWARE_ERROR;
    bool rc = false;
    PF09_RegInfo info;

    /* Get voltage range/info */
    switch (domainId)
    {
        case DEV_SM_VOLT_SOC:
            status = DEV_SM_VoltageDescribe(domainId, range);
            break;
        case DEV_SM_VOLT_ARM:
            status = DEV_SM_VoltageDescribe(domainId, range);
            break;
        case BRD_SM_VOLT_VDD_GPIO_3P3:
            rc = PF09_RegulatorInfoGet(PF09_REG_SW1, &info);
            break;
        case BRD_SM_VOLT_VDD_ANA_0P8:
            rc = PF09_RegulatorInfoGet(PF09_REG_SW2, &info);
            break;
        case BRD_SM_VOLT_VDD_GPIO_1P8:
            rc = PF09_RegulatorInfoGet(PF09_REG_SW3, &info);
            break;
        case BRD_SM_VOLT_VDDQ_DDR:
            rc = PF09_RegulatorInfoGet(PF09_REG_SW4, &info);
            break;
        case BRD_SM_VOLT_VDD2_DDR:
            rc = PF09_RegulatorInfoGet(PF09_REG_SW5, &info);
            break;
        case BRD_SM_VOLT_SD_CARD:
            rc = PF09_RegulatorInfoGet(PF09_REG_LDO1, &info);
            break;
        case BRD_SM_VOLT_NVCC_SD2:
            rc = PF09_RegulatorInfoGet(PF09_REG_LDO2, &info);
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return results */
    if ((status != SM_ERR_SUCCESS) && rc)
    {
        range->highestVolt = (int32_t) info.maxV;
        range->lowestVolt = (int32_t) info.minV;
        range->stepSize= (int32_t) info.stepV;
        status = SM_ERR_SUCCESS;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set voltage mode                                                         */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageModeSet(uint32_t domainId, uint8_t voltMode)
{
    int32_t status = SM_ERR_SUCCESS;
    bool enable = (voltMode == DEV_SM_VOLT_MODE_ON);
    uint8_t mode = ((voltMode == DEV_SM_VOLT_MODE_OFF)
        ? PF09_SW_MODE_OFF : PF09_SW_MODE_PWM);
    bool rc;

    /* Set mode */
    switch (domainId)
    {
        case DEV_SM_VOLT_SOC:
            mode = ((voltMode == DEV_SM_VOLT_MODE_OFF)
                ? PF53_SW_MODE_OFF : PF53_SW_MODE_PWM);
            rc = PF53_SwModeSet(&pf5302Dev, PF53_REG_SW1, PF53_STATE_VRUN,
                mode);
            break;
        case DEV_SM_VOLT_ARM:
            mode = ((voltMode == DEV_SM_VOLT_MODE_OFF)
                ? PF53_SW_MODE_OFF : PF53_SW_MODE_PWM);
            rc = PF53_SwModeSet(&pf5301Dev, PF53_REG_SW1, PF53_STATE_VRUN,
                mode);
            break;
        case BRD_SM_VOLT_VDD_GPIO_3P3:
            rc = PF09_SwModeSet(&pf09Dev, PF09_REG_SW1, PF09_STATE_VRUN,
                mode);
            break;
        case BRD_SM_VOLT_VDD_ANA_0P8:
            rc = PF09_SwModeSet(&pf09Dev, PF09_REG_SW2, PF09_STATE_VRUN,
                mode);
            break;
        case BRD_SM_VOLT_VDD_GPIO_1P8:
            rc = PF09_SwModeSet(&pf09Dev, PF09_REG_SW3, PF09_STATE_VRUN,
                mode);
            break;
        case BRD_SM_VOLT_VDDQ_DDR:
            rc = PF09_SwModeSet(&pf09Dev, PF09_REG_SW4, PF09_STATE_VRUN,
                mode);
            break;
        case BRD_SM_VOLT_VDD2_DDR:
            rc = PF09_SwModeSet(&pf09Dev, PF09_REG_SW5, PF09_STATE_VRUN,
                mode);
            break;
        case BRD_SM_VOLT_SD_CARD:
            rc = PF09_LdoEnable(&pf09Dev, PF09_REG_LDO1, PF09_STATE_VRUN,
                enable);
            break;
        case BRD_SM_VOLT_NVCC_SD2:
            rc = PF09_LdoEnable(&pf09Dev, PF09_REG_LDO2, PF09_STATE_VRUN,
                enable);
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Translate error */
    if ((status == SM_ERR_SUCCESS) && !rc)
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get voltage mode                                                         */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageModeGet(uint32_t domainId, uint8_t *voltMode)
{
    int32_t status = SM_ERR_SUCCESS;
    bool enable;
    uint8_t mode;
    bool rc;

    /* Get mode */
    switch (domainId)
    {
        case DEV_SM_VOLT_SOC:
            rc = PF53_SwModeGet(&pf5302Dev, PF53_REG_SW1, PF53_STATE_VRUN,
                &mode);
            enable = (mode != PF53_SW_MODE_OFF);
            break;
        case DEV_SM_VOLT_ARM:
            rc = PF53_SwModeGet(&pf5301Dev, PF53_REG_SW1, PF53_STATE_VRUN,
                &mode);
            enable = (mode != PF53_SW_MODE_OFF);
            break;
        case BRD_SM_VOLT_VDD_GPIO_3P3:
            rc = PF09_SwModeGet(&pf09Dev, PF09_REG_SW1, PF09_STATE_VRUN,
                &mode);
            enable = (mode != PF09_SW_MODE_OFF);
            break;
        case BRD_SM_VOLT_VDD_ANA_0P8:
            rc = PF09_SwModeGet(&pf09Dev, PF09_REG_SW2, PF09_STATE_VRUN,
                &mode);
            enable = (mode != PF09_SW_MODE_OFF);
            break;
        case BRD_SM_VOLT_VDD_GPIO_1P8:
            rc = PF09_SwModeGet(&pf09Dev, PF09_REG_SW3, PF09_STATE_VRUN,
                &mode);
            enable = (mode != PF09_SW_MODE_OFF);
            break;
        case BRD_SM_VOLT_VDDQ_DDR:
            rc = PF09_SwModeGet(&pf09Dev, PF09_REG_SW4, PF09_STATE_VRUN,
                &mode);
            enable = (mode != PF09_SW_MODE_OFF);
            break;
        case BRD_SM_VOLT_VDD2_DDR:
            rc = PF09_SwModeGet(&pf09Dev, PF09_REG_SW5, PF09_STATE_VRUN,
                &mode);
            enable = (mode != PF09_SW_MODE_OFF);
            break;
        case BRD_SM_VOLT_SD_CARD:
            rc = PF09_LdoIsEnabled(&pf09Dev, PF09_REG_LDO1, PF09_STATE_VRUN,
                &enable);
            break;
        case BRD_SM_VOLT_NVCC_SD2:
            rc = PF09_LdoIsEnabled(&pf09Dev, PF09_REG_LDO2, PF09_STATE_VRUN,
                &enable);
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return result */
    if ((status == SM_ERR_SUCCESS) && rc)
    {
        *voltMode = enable ? DEV_SM_VOLT_MODE_ON : DEV_SM_VOLT_MODE_OFF;
    }

    /* Translate error */
    if ((status == SM_ERR_SUCCESS) && !rc)
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set voltage level                                                        */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageLevelSet(uint32_t domainId, int32_t voltageLevel)
{
    int32_t status = SM_ERR_SUCCESS;
    bool rc;
    uint32_t level = (uint32_t) voltageLevel;

    /* Set level */
    switch (domainId)
    {
        case DEV_SM_VOLT_SOC:
            rc = PF53_VoltageSet(&pf5302Dev, PF53_REG_SW1, PF53_STATE_VRUN,
                level);
            break;
        case DEV_SM_VOLT_ARM:
            rc = PF53_VoltageSet(&pf5301Dev, PF53_REG_SW1, PF53_STATE_VRUN,
                level);
            break;
        case BRD_SM_VOLT_VDD_GPIO_3P3:
            rc = PF09_VoltageSet(&pf09Dev, PF09_REG_SW1, PF09_STATE_VRUN,
                level);
            break;
        case BRD_SM_VOLT_VDD_ANA_0P8:
            rc = PF09_VoltageSet(&pf09Dev, PF09_REG_SW2, PF09_STATE_VRUN,
                level);
            break;
        case BRD_SM_VOLT_VDD_GPIO_1P8:
            rc = PF09_VoltageSet(&pf09Dev, PF09_REG_SW3, PF09_STATE_VRUN,
                level);
            break;
        case BRD_SM_VOLT_VDDQ_DDR:
            rc = PF09_VoltageSet(&pf09Dev, PF09_REG_SW4, PF09_STATE_VRUN,
                level);
            break;
        case BRD_SM_VOLT_VDD2_DDR:
            rc = PF09_VoltageSet(&pf09Dev, PF09_REG_SW5, PF09_STATE_VRUN,
                level);
            break;
        case BRD_SM_VOLT_SD_CARD:
            rc = PF09_VoltageSet(&pf09Dev, PF09_REG_LDO1, PF09_STATE_VRUN,
                level);
            break;
        case BRD_SM_VOLT_NVCC_SD2:
            rc = PF09_VoltageSet(&pf09Dev, PF09_REG_LDO2, PF09_STATE_VRUN,
                level);
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Translate error */
    if ((status == SM_ERR_SUCCESS) && !rc)
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get voltage level                                                        */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_VoltageLevelGet(uint32_t domainId, int32_t *voltageLevel)
{
    int32_t status = SM_ERR_SUCCESS;
    bool rc;
    uint32_t level;

    /* Get level */
    switch (domainId)
    {
        case DEV_SM_VOLT_SOC:
            rc = PF53_VoltageGet(&pf5302Dev, PF53_REG_SW1, PF53_STATE_VRUN,
                &level);
            break;
        case DEV_SM_VOLT_ARM:
            rc = PF53_VoltageGet(&pf5301Dev, PF53_REG_SW1, PF53_STATE_VRUN,
                &level);
            break;
        case BRD_SM_VOLT_VDD_GPIO_3P3:
            rc = PF09_VoltageGet(&pf09Dev, PF09_REG_SW1, PF09_STATE_VRUN,
                &level);
            break;
        case BRD_SM_VOLT_VDD_ANA_0P8:
            rc = PF09_VoltageGet(&pf09Dev, PF09_REG_SW2, PF09_STATE_VRUN,
                &level);
            break;
        case BRD_SM_VOLT_VDD_GPIO_1P8:
            rc = PF09_VoltageGet(&pf09Dev, PF09_REG_SW3, PF09_STATE_VRUN,
                &level);
            break;
        case BRD_SM_VOLT_VDDQ_DDR:
            rc = PF09_VoltageGet(&pf09Dev, PF09_REG_SW4, PF09_STATE_VRUN,
                &level);
            break;
        case BRD_SM_VOLT_VDD2_DDR:
            rc = PF09_VoltageGet(&pf09Dev, PF09_REG_SW5, PF09_STATE_VRUN,
                &level);
            break;
        case BRD_SM_VOLT_SD_CARD:
            rc = PF09_VoltageGet(&pf09Dev, PF09_REG_LDO1, PF09_STATE_VRUN,
                &level);
            break;
        case BRD_SM_VOLT_NVCC_SD2:
            rc = PF09_VoltageGet(&pf09Dev, PF09_REG_LDO2, PF09_STATE_VRUN,
                &level);
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return result */
    if ((status == SM_ERR_SUCCESS) && rc)
    {
        *voltageLevel = (int32_t) level;
    }

    /* Translate error */
    if ((status == SM_ERR_SUCCESS) && !rc)
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

