/*
** ###################################################################
**
**     Copyright 2026 NXP
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
        "vddq_ddr",
        "vdd_3p3",
        "vdd_1p8",
        "vdd2_ddr",
        "vdd_ana_0p8",
        "nvcc_sd2_low",
        "nvcc_sd2_high"
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
    PCA9451_RegInfo info;

    /* Get voltage range/info */
    switch (domainId)
    {
        case DEV_SM_VOLT_SOC:
            status = DEV_SM_VoltageDescribe(domainId, range);
            break;
        case BRD_SM_VOLT_VDDQ_DDR:
            rc = PCA9451_RegulatorInfoGet(PCA9451_REG_SW2, &info);
            break;
        case BRD_SM_VOLT_VDD_3P3:
            rc = PCA9451_RegulatorInfoGet(PCA9451_REG_SW4, &info);
            break;
        case BRD_SM_VOLT_VDD_1P8:
            rc = PCA9451_RegulatorInfoGet(PCA9451_REG_SW5, &info);
            break;
        case BRD_SM_VOLT_VDD2_DDR:
            rc = PCA9451_RegulatorInfoGet(PCA9451_REG_SW6, &info);
            break;
        case BRD_SM_VOLT_VDD_ANA_0P8:
            rc = PCA9451_RegulatorInfoGet(PCA9451_REG_LDO3, &info);
            break;
        case BRD_SM_VOLT_NVCC_SD2_LOW:
            rc = PCA9451_RegulatorInfoGet(PCA9451_REG_LDO5_L, &info);
            break;
        case BRD_SM_VOLT_NVCC_SD2_HIGH:
            rc = PCA9451_RegulatorInfoGet(PCA9451_REG_LDO5_H, &info);
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return results */
    if (rc)
    {
        /* Set the status if parameters are out of range */
        status = SM_ERR_INVALID_PARAMETERS;

        /* Validate the parameters values are with in int32 range */
        if (CHECK_U32_FIT_I32(info.maxV) &&
            CHECK_U32_FIT_I32(info.minV) &&
            CHECK_U32_FIT_I32(info.stepV))
        {
            range->highestVolt = (int32_t) info.maxV;
            range->lowestVolt = (int32_t) info.minV;
            range->stepSize = (int32_t) info.stepV;
            status = SM_ERR_SUCCESS;
        }
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
    uint8_t mode = ((voltMode == DEV_SM_VOLT_MODE_OFF)
        ? PCA9451_SW_MODE_OFF : PCA9451_SW_MODE_ON);
    bool rc;

    /* Set mode */
    switch (domainId)
    {
        case DEV_SM_VOLT_SOC:
            rc = PCA9451_SWModeSet(&g_pca9451Dev, PCA9451_REG_SW1, mode);
            break;
        case BRD_SM_VOLT_VDDQ_DDR:
            rc = PCA9451_SWModeSet(&g_pca9451Dev, PCA9451_REG_SW2, mode);
            break;
        case BRD_SM_VOLT_VDD_3P3:
            rc = PCA9451_SWModeSet(&g_pca9451Dev, PCA9451_REG_SW4, mode);
            break;
        case BRD_SM_VOLT_VDD_1P8:
            rc = PCA9451_SWModeSet(&g_pca9451Dev, PCA9451_REG_SW5, mode);
            break;
        case BRD_SM_VOLT_VDD2_DDR:
            rc = PCA9451_SWModeSet(&g_pca9451Dev, PCA9451_REG_SW6, mode);
            break;
        case BRD_SM_VOLT_VDD_ANA_0P8:
            rc = PCA9451_LdoEnable(&g_pca9451Dev, PCA9451_REG_LDO3, mode);
            break;
        case BRD_SM_VOLT_NVCC_SD2_LOW:
            rc = PCA9451_LdoEnable(&g_pca9451Dev, PCA9451_REG_LDO5_L, mode);
            break;
        case BRD_SM_VOLT_NVCC_SD2_HIGH:
            rc = PCA9451_LdoEnable(&g_pca9451Dev, PCA9451_REG_LDO5_H, mode);
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
    uint8_t mode;
    bool rc;

    /* Get mode */
    switch (domainId)
    {
        case DEV_SM_VOLT_SOC:
            rc = PCA9451_SWModeGet(&g_pca9451Dev, PCA9451_REG_SW1, &mode);
            break;
        case BRD_SM_VOLT_VDDQ_DDR:
            rc = PCA9451_SWModeGet(&g_pca9451Dev, PCA9451_REG_SW2, &mode);
            break;
        case BRD_SM_VOLT_VDD_3P3:
            rc = PCA9451_SWModeGet(&g_pca9451Dev, PCA9451_REG_SW4, &mode);
            break;
        case BRD_SM_VOLT_VDD_1P8:
            rc = PCA9451_SWModeGet(&g_pca9451Dev, PCA9451_REG_SW5, &mode);
            break;
        case BRD_SM_VOLT_VDD2_DDR:
            rc = PCA9451_SWModeGet(&g_pca9451Dev, PCA9451_REG_SW6, &mode);
            break;
        case BRD_SM_VOLT_VDD_ANA_0P8:
            rc = PCA9451_LdoIsEnabled(&g_pca9451Dev, PCA9451_REG_LDO3, &mode);
            break;
        case BRD_SM_VOLT_NVCC_SD2_LOW:
            rc = PCA9451_LdoIsEnabled(&g_pca9451Dev, PCA9451_REG_LDO5_L, &mode);
            break;
        case BRD_SM_VOLT_NVCC_SD2_HIGH:
            rc = PCA9451_LdoIsEnabled(&g_pca9451Dev, PCA9451_REG_LDO5_H, &mode);
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return result and translate error */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_ERR_HARDWARE_ERROR;
        if (rc)
        {
            *voltMode = (mode != 0U) ? PCA9451_SW_MODE_ON : PCA9451_SW_MODE_OFF;
            status = SM_ERR_SUCCESS;
        }
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

    /* Check voltageLevel is positive */
    if (CHECK_I32_POSITIVE(voltageLevel))
    {
        bool rc;
        uint32_t level = (uint32_t) voltageLevel;

        /* Set level */
        switch (domainId)
        {
            case DEV_SM_VOLT_SOC:
                rc = PCA9451_VoltageSet(&g_pca9451Dev, PCA9451_REG_SW1,
                    PCA9451_STATE_RUN, level);
                break;
            case BRD_SM_VOLT_VDDQ_DDR:
                rc = PCA9451_VoltageSet(&g_pca9451Dev, PCA9451_REG_SW2,
                    PCA9451_STATE_RUN, level);
                break;
            case BRD_SM_VOLT_VDD_3P3:
                rc = PCA9451_VoltageSet(&g_pca9451Dev, PCA9451_REG_SW4,
                    PCA9451_STATE_RUN, level);
                break;
            case BRD_SM_VOLT_VDD_1P8:
                rc = PCA9451_VoltageSet(&g_pca9451Dev, PCA9451_REG_SW5,
                    PCA9451_STATE_RUN, level);
                break;
            case BRD_SM_VOLT_VDD2_DDR:
                rc = PCA9451_VoltageSet(&g_pca9451Dev, PCA9451_REG_SW6,
                    PCA9451_STATE_RUN, level);
                break;
            case BRD_SM_VOLT_VDD_ANA_0P8:
                /* Fixed voltage regulator to enable/disable VDD_ANA_0P8 */
                rc = true;
                break;
            case BRD_SM_VOLT_NVCC_SD2_LOW:
                rc = PCA9451_VoltageSet(&g_pca9451Dev, PCA9451_REG_LDO5_L,
                    PCA9451_STATE_RUN, level);
                break;
            case BRD_SM_VOLT_NVCC_SD2_HIGH:
                rc = PCA9451_VoltageSet(&g_pca9451Dev, PCA9451_REG_LDO5_H,
                    PCA9451_STATE_RUN, level);
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
    }
    else
    {
        /* Set the status if voltageLevel is negative */
        status = SM_ERR_INVALID_PARAMETERS;
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
    uint32_t level = 0U;

    /* Get level */
    switch (domainId)
    {
        case DEV_SM_VOLT_SOC:
            rc = PCA9451_VoltageGet(&g_pca9451Dev, PCA9451_REG_SW1,
                PCA9451_STATE_RUN, &level);
            break;
        case BRD_SM_VOLT_VDDQ_DDR:
            rc = PCA9451_VoltageGet(&g_pca9451Dev, PCA9451_REG_SW2,
                PCA9451_STATE_RUN, &level);
            break;
        case BRD_SM_VOLT_VDD_3P3:
            rc = PCA9451_VoltageGet(&g_pca9451Dev, PCA9451_REG_SW4,
                PCA9451_STATE_RUN, &level);
            break;
        case BRD_SM_VOLT_VDD_1P8:
            rc = PCA9451_VoltageGet(&g_pca9451Dev, PCA9451_REG_SW5,
                PCA9451_STATE_RUN, &level);
            break;
        case BRD_SM_VOLT_VDD2_DDR:
            rc = PCA9451_VoltageGet(&g_pca9451Dev, PCA9451_REG_SW6,
                PCA9451_STATE_RUN, &level);
            break;
        case BRD_SM_VOLT_VDD_ANA_0P8:
            /* LDO3 is connected as enabled signal to VDD_ANA_0P8 */
            level = 837500U;
            rc = true;
            break;
        case BRD_SM_VOLT_NVCC_SD2_LOW:
            rc = PCA9451_VoltageGet(&g_pca9451Dev, PCA9451_REG_LDO5_L,
                PCA9451_STATE_RUN, &level);
            break;
        case BRD_SM_VOLT_NVCC_SD2_HIGH:
            rc = PCA9451_VoltageGet(&g_pca9451Dev, PCA9451_REG_LDO5_H,
                PCA9451_STATE_RUN, &level);
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return result */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_ERR_HARDWARE_ERROR;

        if (rc)
        {
            /* Set the status if parameters are out of range */
            status = SM_ERR_INVALID_PARAMETERS;

            /* Check level value within int32_t range */
            if (CHECK_U32_FIT_I32(level))
            {
                *voltageLevel = (int32_t) level;
                status = SM_ERR_SUCCESS;
            }
        }
    }

    /* Return status */
    return status;
}

