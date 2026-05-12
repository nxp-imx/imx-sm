/*
 * Copyright 2022, 2026 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Includes */
#include "fsl_pca9451.h"

/* Local Defines */

#define PCA9451_CHIP_ID                0x90U

/* STATUS1 thermal bits */
#define PCA9451_STATUS1_THERM_105S_MASK  0x02U
#define PCA9451_STATUS1_THERM_125S_MASK  0x01U

/* BUCKxCTRL ENMODE bits [1:0] */
#define PCA9451_BUCKCTRL_ENMODE_MASK   0x03U
#define PCA9451_BUCKCTRL_ENMODE_SHIFT  0U

/* BUCKxCTRL DVS_CTRL bit [4] */
#define PCA9451_BUCKCTRL_DVSCTRL_MASK  0x10U
#define PCA9451_BUCKCTRL_DVSCTRL_SHIFT 4U

/* LDOxCTRL ENMODE bits [7:6] */
#define PCA9451_LDOCTRL_ENMODE_MASK    0xC0U
#define PCA9451_LDOCTRL_ENMODE_SHIFT   6U

/* LDSWCTRL ENMODE bits [1:0] */
#define PCA9451_LDSWCTRL_ENMODE_MASK   0x03U
#define PCA9451_LDSWCTRL_ENMODE_SHIFT  0U

/* BUCK1/2/3 DVS output voltage bits [6:0] */
#define PCA9451_BUCKDVS_VOUT_MASK      0x7FU

/* BUCK4/5/6 output voltage bits [6:0] */
#define PCA9451_BUCK456_VOUT_MASK      0x7FU

/* BUCK1/2/3_OUT output limit bits [6:0] */
#define PCA9451_BUCK123_OUT_LIMIT_MASK 0x7FU

/* LDO1 voltage bits [2:0] */
#define PCA9451_LDO1_VOUT_MASK         0x07U

/* LDO3 voltage bits [4:0] */
#define PCA9451_LDO3_VOUT_MASK         0x1FU

/* LDO4 voltage bits [4:0] */
#define PCA9451_LDO4_VOUT_MASK         0x1FU

/* LDO5 voltage bits [3:0] (both L and H registers) */
#define PCA9451_LDO5_VOUT_MASK         0x0FU

/* Field macros */
#define PCA9451_RESET_CTRL_WDOG_B_CFG_MASK   (0xC0U)
#define PCA9451_RESET_CTRL_WDOG_B_CFG_SHIFT  (6U)
#define PCA9451_RESET_CTRL_WDOG_B_CFG(x)     \
    (((uint8_t)(((uint8_t)(x)) << PCA9451_RESET_CTRL_WDOG_B_CFG_SHIFT)) \
    & PCA9451_RESET_CTRL_WDOG_B_CFG_MASK)

#define PCA9451_CONFIG2_I2C_LT_EN_MASK   (0x03U)
#define PCA9451_CONFIG2_I2C_LT_EN_SHIFT  (0U)
#define PCA9451_CONFIG2_I2C_LT_EN(x)     \
    (((uint8_t)(((uint8_t)(x)) << PCA9451_CONFIG2_I2C_LT_EN_SHIFT)) \
    & PCA9451_CONFIG2_I2C_LT_EN_MASK)

#define PCA9451_BUCK123_DVS_PRESET_EN_MASK   (0x80U)
#define PCA9451_BUCK123_DVS_PRESET_EN_SHIFT  (7U)
#define PCA9451_BUCK123_DVS_PRESET_EN(x)     \
    (((uint8_t)(((uint8_t)(x)) << PCA9451_BUCK123_DVS_PRESET_EN_SHIFT)) \
    & PCA9451_BUCK123_DVS_PRESET_EN_MASK)

#define PCA9451_BUCK123_B3_DVS_PRESET_MASK   (0x60U)
#define PCA9451_BUCK123_B3_DVS_PRESET_SHIFT  (5U)
#define PCA9451_BUCK123_B3_DVS_PRESET(x)     \
    (((uint8_t)(((uint8_t)(x)) << PCA9451_BUCK123_B3_DVS_PRESET_SHIFT)) \
    & PCA9451_BUCK123_B3_DVS_PRESET_MASK)

#define PCA9451_BUCK123_B1_DVS_PRESET_MASK   (0x18U)
#define PCA9451_BUCK123_B1_DVS_PRESET_SHIFT  (3U)
#define PCA9451_BUCK123_B1_DVS_PRESET(x)     \
    (((uint8_t)(((uint8_t)(x)) << PCA9451_BUCK123_B1_DVS_PRESET_SHIFT)) \
    & PCA9451_BUCK123_B1_DVS_PRESET_MASK)

#define PCA9451_BUCK123_B2_DVS_PRESET_MASK   (0x7U)
#define PCA9451_BUCK123_B2_DVS_PRESET_SHIFT  (0U)
#define PCA9451_BUCK123_B2_DVS_PRESET(x)     \
    (((uint8_t)(((uint8_t)(x)) << PCA9451_BUCK123_B2_DVS_PRESET_SHIFT)) \
    & PCA9451_BUCK123_B2_DVS_PRESET_MASK)

/* Local Types */

/* Local Functions */

static bool PCA9451_ConvertVolts2Code(uint8_t regulator, uint32_t microVolt,
    uint8_t *voltCode);
static bool PCA9451_ConvertCode2Volts(uint8_t regulator, uint8_t voltCode,
    uint32_t *microVolt);
static bool PCA9451_BuckCtrlAddr(uint8_t buckId, uint8_t *ctrlAddr);
static bool PCA9451_BuckVoltAddr(uint8_t buckId, uint8_t state,
    uint8_t *voltAddr);
static bool PCA9451_LdoCtrlAddr(uint8_t ldoId, uint8_t *ctrlAddr);

static status_t BRD_SM_LPI2C_Send(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t subAddressSize, uint8_t *txBuff,
    uint8_t txBuffSize, uint32_t flags);
static status_t BRD_SM_LPI2C_Receive(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t subAddressSize, uint8_t *rxBuff,
    uint8_t rxBuffSize, uint32_t flags);

/* Local Variables */

/* Global Variables */

/*--------------------------------------------------------------------------*/
/* Initialize PMIC                                                          */
/*--------------------------------------------------------------------------*/
bool PCA9451_Init(PCA9451_Type *dev, uint8_t wdogbResp,
    uint8_t i2cLtEn)
{
    bool rc = true;

    /* Read PF53 device id regs */
    for (uint8_t addr = 0U; addr < PCA9451_ID_LEN; addr++)
    {
        rc = PCA9451_PmicRead(dev, addr, &(dev->id[addr]));
        if (!rc)
        {
            break;
        }
    }

    /* Table 19: CHIP_ID is bits [7:4] = 1001b; mask lower nibble (reserved) */
    if (rc && ((dev->id[0U] & 0xF0U) == PCA9451_CHIP_ID))
    {
        rc = PCA9451_ConfigWdogbResponseSet(dev, wdogbResp);
        if (rc)
        {
            rc = PCA9451_ConfigI2cLevelTransSet(dev, i2cLtEn);
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get info                                                                 */
/*--------------------------------------------------------------------------*/
bool PCA9451_PmicInfoGet(PCA9451_Type *dev, uint8_t **info,
    uint8_t *len)
{
    bool rc = true;

    /* Get device Id */
    if (dev->id[0] == 0U)
    {
        rc = PCA9451_PmicRead(dev, PCA9451_REG_DEV_ID, &(dev->id[0U]));
    }

    /* Return results */
    if (rc)
    {
        *info = dev->id;
        *len = PCA9451_ID_LEN;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Register write                                                           */
/*--------------------------------------------------------------------------*/
bool PCA9451_PmicWrite(const PCA9451_Type *dev, uint8_t regAddr, uint8_t val,
    uint8_t mask)
{
    bool rc = false;

    if (regAddr < PCA9451_NUM_REG)
    {
        /* If not updating entire register, perform a read-mod-write */
        if (mask != 0xFFU)
        {
            uint8_t rxBuf;

            if (BRD_SM_LPI2C_Receive(dev->i2cBase, dev->devAddr, regAddr,
                1U, &rxBuf, 1U, 0U) == kStatus_Success)
            {
                uint8_t txBuf = (val & mask) | (rxBuf & ((uint8_t) ~mask));

                if (BRD_SM_LPI2C_Send(dev->i2cBase, dev->devAddr, regAddr,
                    1U, &txBuf, 1U, 0U) == kStatus_Success)
                {
                    rc = true;
                }
            }
        }
        else
        {
            if (BRD_SM_LPI2C_Send(dev->i2cBase, dev->devAddr, regAddr,
                1U, &val, 1U, 0U) == kStatus_Success)
            {
                rc = true;
            }
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Register read                                                            */
/*--------------------------------------------------------------------------*/
bool PCA9451_PmicRead(const PCA9451_Type *dev, uint8_t regAddr, uint8_t *val)
{
    bool rc = false;

    if (regAddr < PCA9451_NUM_REG)
    {
        if (BRD_SM_LPI2C_Receive(dev->i2cBase, dev->devAddr, regAddr, 1U,
            val, 1U, 0U) == kStatus_Success)
        {
            rc = true;
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get regulator info                                                       */
/*--------------------------------------------------------------------------*/
bool PCA9451_RegulatorInfoGet(uint8_t regulator, PCA9451_RegInfo *regInfo)
{
    bool rc = true;

    if (regInfo == NULL)
    {
        rc = false;
    }
    else
    {
        switch (regulator)
        {
            case PCA9451_REG_SW1:
            case PCA9451_REG_SW3:
                /* Table 15 / Table 43: 0.65 V – 2.2375 V, 12.5 mV step */
                regInfo->minV  = 650000U;
                regInfo->maxV  = 2237500U;
                regInfo->stepV = 12500U;
                break;
            case PCA9451_REG_SW2:
                /* Table 15 / Table 44: 0.60 V – 2.1875 V, 12.5 mV step */
                regInfo->minV  = 500000U;
                regInfo->maxV  = 2087500U;
                regInfo->stepV = 12500U;
                break;
            case PCA9451_REG_SW4:
            case PCA9451_REG_SW5:
                /* Table 15 / Table 51: 0.60 V – 3.40 V, 25 mV step */
                regInfo->minV  = 600000U;
                regInfo->maxV  = 3400000U;
                regInfo->stepV = 25000U;
                break;
            case PCA9451_REG_SW6:
                /* set min/max/step in microvolts */
                regInfo->minV = 550000U;
                regInfo->maxV = 3550000U;
                regInfo->stepV = 25000U;
                break;
            case PCA9451_REG_LDO1:
                /* Table 16 / Table 53: 1.6–1.9 V and 3.0–3.3 V, 100 mV step */
                regInfo->minV  = 1600000U;
                regInfo->maxV  = 3300000U;
                regInfo->stepV = 100000U;
                break;
            case PCA9451_REG_LDO3:
                /* set min/max/step in microvolts */
                regInfo->minV = 800000U;
                regInfo->maxV = 3300000U;
                regInfo->stepV = 100000U;
                break;
            case PCA9451_REG_LDO4:
                /* Table 16 / Table 55: 0.8375 V – 3.46 V, 100 mV step */
                regInfo->minV  = 837500U;
                regInfo->maxV  = 3460000U;
                regInfo->stepV = 100000U;
                break;
            case PCA9451_REG_LDO5_L:
            case PCA9451_REG_LDO5_H:
                /* Table 16 / Table 57: 1.8 V – 3.3 V, 100 mV step */
                regInfo->minV  = 1800000U;
                regInfo->maxV  = 3300000U;
                regInfo->stepV = 100000U;
                break;
            case PCA9451_REG_LDSW:
                /* set min/max/step in microvolts */
                regInfo->minV = 3300000U;
                regInfo->maxV = 3300000U;
                break;
            default:
                rc = false;
                break;
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set buck enable mode                                                     */
/*--------------------------------------------------------------------------*/
bool PCA9451_SWModeSet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t mode)
{
    bool rc;
    uint8_t ctrlAddr = 0U;

    rc = PCA9451_BuckCtrlAddr(buckId, &ctrlAddr);
    if (rc)
    {
        /* Bx_ENMODE is bits [1:0] of the SWxCTRL register */
        rc = PCA9451_PmicWrite(dev, ctrlAddr,
            (uint8_t)(mode << PCA9451_BUCKCTRL_ENMODE_SHIFT),
            PCA9451_BUCKCTRL_ENMODE_MASK);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get buck enable mode                                                     */
/*--------------------------------------------------------------------------*/
bool PCA9451_SWModeGet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t *mode)
{
    bool rc;
    uint8_t ctrlAddr = 0U;

    if (mode == NULL)
    {
        rc = false;
    }
    else
    {
        rc = PCA9451_BuckCtrlAddr(buckId, &ctrlAddr);
        if (rc)
        {
            uint8_t val;

            rc = PCA9451_PmicRead(dev, ctrlAddr, &val);
            if (rc)
            {
                *mode = (val & PCA9451_BUCKCTRL_ENMODE_MASK)
                    >> PCA9451_BUCKCTRL_ENMODE_SHIFT;
            }
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set buck DVS mode                                                        */
/*--------------------------------------------------------------------------*/
bool PCA9451_DVSModeSet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t mode)
{
    bool rc;
    uint8_t ctrlAddr = 0U;

    if ((buckId >= PCA9451_REG_SW1) &&
        (buckId <= PCA9451_REG_SW3))
    {
        rc = PCA9451_BuckCtrlAddr(buckId, &ctrlAddr);
        if (rc)
        {
            /* Bx_ENMODE is bits [1:0] of the SWxCTRL register */
            rc = PCA9451_PmicWrite(dev, ctrlAddr,
                (uint8_t)(mode << PCA9451_BUCKCTRL_DVSCTRL_SHIFT),
                PCA9451_BUCKCTRL_DVSCTRL_MASK);
        }
    }
    else
    {
        /* Set the status */
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get buck dvs mode                                                        */
/*--------------------------------------------------------------------------*/
bool PCA9451_DVSModeGet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t *mode)
{
    bool rc;
    uint8_t ctrlAddr = 0U;

    if (mode == NULL)
    {
        rc = false;
    }
    else
    {
        if ((buckId >= PCA9451_REG_SW1) &&
            (buckId <= PCA9451_REG_SW3))
        {
            rc = PCA9451_BuckCtrlAddr(buckId, &ctrlAddr);
            if (rc)
            {
                uint8_t val;

                rc = PCA9451_PmicRead(dev, ctrlAddr, &val);
                if (rc)
                {
                    *mode = (val & PCA9451_BUCKCTRL_DVSCTRL_MASK)
                        >> PCA9451_BUCKCTRL_DVSCTRL_SHIFT;
                }
            }
        }
        else
        {
            /* Set the status */
            rc = false;
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable LDO regulator                                             */
/*--------------------------------------------------------------------------*/
bool PCA9451_LdoEnable(const PCA9451_Type *dev, uint8_t ldoId, uint8_t mode)
{
    bool rc;
    uint8_t ctrlAddr = 0U;

    rc = PCA9451_LdoCtrlAddr(ldoId, &ctrlAddr);
    if (rc)
    {
        /* ENMODE is bits [7:6] of the LDOxCTRL register */
        rc = PCA9451_PmicWrite(dev, ctrlAddr,
            (uint8_t)(mode << PCA9451_LDOCTRL_ENMODE_SHIFT),
            PCA9451_LDOCTRL_ENMODE_MASK);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable LDSW regulator                                            */
/*--------------------------------------------------------------------------*/
bool PCA9451_LdSwEnable(const PCA9451_Type *dev, uint8_t mode)
{
    bool rc;
    uint8_t ctrlAddr = PCA9451_REG_LOADSW_CTRL;

    /* ENMODE is bits [7:6] of the LDOxCTRL register */
    rc = PCA9451_PmicWrite(dev, ctrlAddr,
        (uint8_t)(mode << PCA9451_LDSWCTRL_ENMODE_MASK),
        PCA9451_LDSWCTRL_ENMODE_SHIFT);

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get LDO enable mode                                                      */
/*--------------------------------------------------------------------------*/
bool PCA9451_LdoIsEnabled(const PCA9451_Type *dev, uint8_t ldoId,
    uint8_t *mode)
{
    bool rc;
    uint8_t ctrlAddr = 0U;

    if (mode == NULL)
    {
        rc = false;
    }
    else
    {
        rc = PCA9451_LdoCtrlAddr(ldoId, &ctrlAddr);
        if (rc)
        {
            uint8_t val;

            rc = PCA9451_PmicRead(dev, ctrlAddr, &val);
            if (rc)
            {
                *mode = (val & PCA9451_LDOCTRL_ENMODE_MASK)
                    >> PCA9451_LDOCTRL_ENMODE_SHIFT;
            }
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get LDSW enable mode                                                     */
/*--------------------------------------------------------------------------*/
bool PCA9451_LdSwIsEnabled(const PCA9451_Type *dev, uint8_t *mode)
{
    bool rc;
    uint8_t ctrlAddr = PCA9451_REG_LOADSW_CTRL;

    if (mode == NULL)
    {
        rc = false;
    }
    else
    {
        uint8_t val;

        rc = PCA9451_PmicRead(dev, ctrlAddr, &val);
        if (rc)
        {
            *mode = (val & PCA9451_LDSWCTRL_ENMODE_MASK)
                >> PCA9451_LDSWCTRL_ENMODE_SHIFT;
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set regulator voltage in microvolts                                      */
/*--------------------------------------------------------------------------*/
bool PCA9451_VoltageSet(const PCA9451_Type *dev, uint8_t regulator,
    uint8_t state, uint32_t microVolt)
{
    bool rc = true;
    uint8_t voltCode = 0U;
    uint8_t voltAddr = 0U;
    uint8_t writeMask = 0xFFU;

    /* STBY state is only valid for SW1-3 (DVS1 registers) */
    if ((state > PCA9451_STATE_STBY) ||
        ((state == PCA9451_STATE_STBY) && (regulator > PCA9451_REG_SW3)))
    {
        rc = false;
    }

    if (rc)
    {
        /* Convert voltage to register code */
        rc = PCA9451_ConvertVolts2Code(regulator, microVolt, &voltCode);
    }

    if (rc)
    {
        /* Get the voltage register address */
        rc = PCA9451_BuckVoltAddr(regulator, state, &voltAddr);
    }

    if (rc)
    {
        /* Determine write mask based on regulator type */
        switch (regulator)
        {
            case PCA9451_REG_SW1:
            case PCA9451_REG_SW2:
            case PCA9451_REG_SW3:
                /* DVS registers: bit[7] is reserved, bits[6:0] are voltage */
                writeMask = PCA9451_BUCKDVS_VOUT_MASK;
                break;
            case PCA9451_REG_SW4:
            case PCA9451_REG_SW5:
            case PCA9451_REG_SW6:
                /* SW4/5/6 OUT registers: bit [7] is reserved, bits [6:0] */
                writeMask = PCA9451_BUCK456_VOUT_MASK;
                break;
            case PCA9451_REG_LDO1:
                /* LDO1CTRL: voltage in bits [2:0] */
                writeMask = PCA9451_LDO1_VOUT_MASK;
                break;
            case PCA9451_REG_LDO3:
                /* LDO1CTRL: voltage in bits [2:0] */
                writeMask = PCA9451_LDO3_VOUT_MASK;
                break;
            case PCA9451_REG_LDO4:
                /* LDO4CTRL: voltage in bits [4:0] */
                writeMask = PCA9451_LDO4_VOUT_MASK;
                break;
            case PCA9451_REG_LDO5_L:
            case PCA9451_REG_LDO5_H:
                /* LDO5CTRL_L: voltage in bits [3:0] */
                /* LDO5CTRL_H: voltage in bits [3:0] */
                writeMask = PCA9451_LDO5_VOUT_MASK;
                break;
            default:
                rc = false;
                break;
        }
    }

    if (rc)
    {
        rc = PCA9451_PmicWrite(dev, voltAddr, voltCode, writeMask);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get regulator voltage in microvolts                                      */
/*--------------------------------------------------------------------------*/
bool PCA9451_VoltageGet(const PCA9451_Type *dev, uint8_t regulator,
    uint8_t state, uint32_t *microVolt)
{
    bool rc = true;
    uint8_t voltCode = 0U;
    uint8_t voltAddr = 0U;
    uint8_t readMask = 0xFFU;

    if (microVolt == NULL)
    {
        rc = false;
    }

    /* STBY state is only valid for SW1-3 (DVS1 registers) */
    if (rc && ((state > PCA9451_STATE_STBY) ||
        ((state == PCA9451_STATE_STBY) && (regulator > PCA9451_REG_SW3))))
    {
        rc = false;
    }

    if (rc)
    {
        rc = PCA9451_BuckVoltAddr(regulator, state, &voltAddr);
    }

    if (rc)
    {
        uint8_t val;

        rc = PCA9451_PmicRead(dev, voltAddr, &val);
        if (rc)
        {
            /* Mask to relevant bits per regulator type */
            switch (regulator)
            {
                case PCA9451_REG_SW1:
                case PCA9451_REG_SW2:
                case PCA9451_REG_SW3:
                    readMask = PCA9451_BUCKDVS_VOUT_MASK;
                    break;
                case PCA9451_REG_SW4:
                case PCA9451_REG_SW5:
                case PCA9451_REG_SW6:
                    readMask = PCA9451_BUCK456_VOUT_MASK;
                    break;
                case PCA9451_REG_LDO1:
                    readMask = PCA9451_LDO1_VOUT_MASK;
                    break;
                case PCA9451_REG_LDO3:
                    readMask = PCA9451_LDO3_VOUT_MASK;
                    break;
                case PCA9451_REG_LDO4:
                    readMask = PCA9451_LDO4_VOUT_MASK;
                    break;
                case PCA9451_REG_LDO5_L:
                case PCA9451_REG_LDO5_H:
                    readMask = PCA9451_LDO5_VOUT_MASK;
                    break;
                default:
                    rc = false;
                    break;
            }

            if (rc)
            {
                voltCode = val & readMask;
            }
        }
    }

    if (rc)
    {
        rc = PCA9451_ConvertCode2Volts(regulator, voltCode, microVolt);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get die temperature status                                               */
/*--------------------------------------------------------------------------*/
bool PCA9451_TempGet(const PCA9451_Type *dev, int32_t *temp)
{
    bool rc;
    uint8_t status1;

    if (temp == NULL)
    {
        rc = false;
    }
    else
    {
        /* STATUS1 register (0x03): THERM_125S[0], THERM_105S[1] */
        rc = PCA9451_PmicRead(dev, PCA9451_REG_STATUS1, &status1);
        if (rc)
        {
            if ((status1 & PCA9451_STATUS1_THERM_125S_MASK) != 0U)
            {
                /* Die temp at or above 125 °C threshold */
                *temp = 125;
            }
            else if ((status1 & PCA9451_STATUS1_THERM_105S_MASK) != 0U)
            {
                /* Die temp at or above 105 °C threshold */
                *temp = 105;
            }
            else
            {
                /* Die temp below both thresholds */
                *temp = 104;
            }
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set temperature event                                                    */
/*--------------------------------------------------------------------------*/
bool PCA9451_TempSet(const PCA9451_Type *dev, int32_t temp)
{
    bool rc;
    uint8_t mask = 0U;

    /* PCA9451_REG_INT1_MSK (0x02): THERM_125S[0], THERM_105S[1] */
    rc = PCA9451_PmicRead(dev, PCA9451_REG_INT1_MSK, &mask);
    if (rc)
    {
        if (temp >= PCA9451_TEMP_MAX_VALID)
        {
            /* Invalid temperature range */
            mask |= (PCA9451_INT1_THERM_105_MSK |
                PCA9451_INT1_THERM_125_MSK);
        }
        else if (temp <= PCA9451_TEMP_BELOW_105)
        {
            /* Temp threshold below or equal to 105°C */
            /* coverity[cert_int31_c_violation] */
            mask &= (uint8_t)(~PCA9451_INT1_THERM_105_MSK);
        }
        else if (temp <= PCA9451_TEMP_below_125)
        {
            /* Temp threshold between 105°C and below 125°C */
            /* coverity[cert_int31_c_violation] */
            mask &= (uint8_t)(~(PCA9451_INT1_THERM_105_MSK |
                PCA9451_INT1_THERM_125_MSK));
        }
        else /* temp >= 125 and within valid range */
        {
            /* Temp threshold above or equal to 125°C */
            /* coverity[cert_int31_c_violation] */
            mask &= (uint8_t)(~PCA9451_INT1_THERM_125_MSK);
        }

        /* Unmask the temperature event based on theshold value */
        rc = PCA9451_PmicWrite(dev, PCA9451_REG_INT1_MSK, mask,
            PCA9451_INT1_MASK);
    }

    /* Return Status */
    return rc;
}
/*--------------------------------------------------------------------------*/
/* Enable/disable INT1 interrupt bits                                       */
/*--------------------------------------------------------------------------*/
bool PCA9451_IntEnable(const PCA9451_Type *dev, uint8_t mask, bool enable)
{
    bool rc;
    uint8_t val;

    /*
     * INT1_MSK (0x02): a bit set to 1 masks (disables) the interrupt;
     * a bit set to 0 unmasks (enables) it.
     */
    if (enable)
    {
        /* Unmask: clear the specified mask bits */
        val = 0x00U;
    }
    else
    {
        /* Mask: set the specified mask bits */
        val = mask;
    }

    rc = PCA9451_PmicWrite(dev, PCA9451_REG_INT1_MSK, val, mask);

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Read and clear INT1 interrupt status                                     */
/*--------------------------------------------------------------------------*/
bool PCA9451_IntStatus(const PCA9451_Type *dev, uint8_t *mask)
{
    bool rc;

    if (mask == NULL)
    {
        rc = false;
    }
    else
    {
        /* INT1 (0x01) is a Read-and-Clear register per Table 20 */
        rc = PCA9451_PmicRead(dev, PCA9451_REG_INT1, mask);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Read and clear the fault flag                                            */
/*--------------------------------------------------------------------------*/
bool PCA9451_FaultFlags(const PCA9451_Type *dev, uint8_t *val)
{
    bool rc;

    if (val == NULL)
    {
        rc = false;
    }
    else
    {
        /* PWRON_STAT (0x05) is a Read-and-Clear register per Table 18 */
        rc = PCA9451_PmicRead(dev, PCA9451_REG_PWRON_STAT, val);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get VR fault status                                                      */
/*--------------------------------------------------------------------------*/
bool PCA9451_FaultGet(const PCA9451_Type *dev, uint8_t *flt1, uint8_t *flt2,
    bool clear)
{
    bool rc;

    if ((flt1 == NULL) || (flt2 == NULL))
    {
        rc = false;
    }
    else
    {
        /* Read VRFLT1_STS (0x2B) */
        rc = PCA9451_PmicRead(dev, PCA9451_REG_VRFLT1_STS, flt1);

        if (rc)
        {
            /* Read VRFLT2_STS (0x2C) */
            rc = PCA9451_PmicRead(dev, PCA9451_REG_VRFLT2_STS, flt2);
        }

        if (rc && clear)
        {
            /* Write-back 1s to clear latched fault bits (R/W/C type) */
            if (*flt1 != 0U)
            {
                rc = PCA9451_PmicWrite(dev, PCA9451_REG_VRFLT1_STS, *flt1,
                    0xFFU);
            }

            if (rc && (*flt2 != 0U))
            {
                rc = PCA9451_PmicWrite(dev, PCA9451_REG_VRFLT2_STS, *flt2,
                    0xFFU);
            }
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Software reset                                                           */
/*--------------------------------------------------------------------------*/
bool PCA9451_SwReset(const PCA9451_Type *dev, uint8_t rstVal)
{
    /*
     * SW_RST register (0x06, Table 25):
     * 0x05 = Reset all registers to default
     * 0x14 = Cold reset (recycle all except LDO1)
     * 0x35 = Warm reset (toggle POR_B 20 ms)
     * 0x64 = Cold reset (recycle all regulators)
     * Other values = no action
     */
    return PCA9451_PmicWrite(dev, PCA9451_REG_SW_RST, rstVal, 0xFFU);
}

/*--------------------------------------------------------------------------*/
/* Convert voltage to buck DVS preset voltage code                          */
/*--------------------------------------------------------------------------*/
bool PCA9451_BuckDvsVoltage2CodeConvert(uint32_t buckIdx, uint32_t microVolt,
    uint32_t *voltCode)
{
    bool rc = true;

    switch (buckIdx)
    {
        /* Table 30: B1_DVS_PRESET / B3_DVS_PRESET
         * 00b=0.80V, 01b=0.85V, 10b=0.90V, 11b=0.95V
         */
        case 1U:
        case 3U:
            switch (microVolt)
            {
                case 800000U:
                    *voltCode = 0U;
                    break;
                case 850000U:
                    *voltCode = 1U;
                    break;
                case 900000U:
                    *voltCode = 2U;
                    break;
                case 950000U:
                    *voltCode = 3U;
                    break;
                default:
                    rc = false;
                    break;
            }
            break;
        case 2U:
            switch (microVolt)
            {
                case 500000U:
                    *voltCode = 0U;
                    break;
                case 600000U:
                    *voltCode = 1U;
                    break;
                case 700000U:
                    *voltCode = 2U;
                    break;
                case 980000U:
                    *voltCode = 3U;
                    break;
                case 1000000U:
                    *voltCode = 4U;
                    break;
                default:
                    rc = false;
                    break;
            }
            break;
        default:
            rc = false;
            break;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set DVS buck voltages                                                    */
/*--------------------------------------------------------------------------*/
bool PCA9451_BuckDvsVoltageSet(const PCA9451_Type *dev, uint8_t presetEn,
    uint8_t b1voltCode, uint8_t b2voltCode, uint8_t b3voltCode)
{
    uint8_t val = PCA9451_BUCK123_DVS_PRESET_EN(presetEn) |
        PCA9451_BUCK123_B3_DVS_PRESET(b3voltCode) |
        PCA9451_BUCK123_B1_DVS_PRESET(b1voltCode) |
        PCA9451_BUCK123_B2_DVS_PRESET(b2voltCode);

    return PCA9451_PmicWrite(dev, PCA9451_REG_BUCK123_DVS, val, 0xFFU);
}

/*--------------------------------------------------------------------------*/
/* Convert buck DVS voltage code to voltage                                 */
/*--------------------------------------------------------------------------*/
bool PCA9451_BuckDvsCode2VoltageConvert(uint32_t buckIdx, uint32_t voltCode,
    uint32_t *microVolt)
{
    bool rc = true;

    switch (buckIdx)
    {
        /* Table 30: B1_DVS_PRESET / B3_DVS_PRESET
         * 00b=0.80V, 01b=0.85V, 10b=0.90V, 11b=0.95V
         */
        case 1U:
        case 3U:
            switch (voltCode)
            {
                case 0U:
                    *microVolt = 800000U;
                    break;
                case 1U:
                    *microVolt = 850000U;
                    break;
                case 2U:
                    *microVolt = 900000U;
                    break;
                case 3U:
                    *microVolt = 950000U;
                    break;
                default:
                    rc = false;
                    break;
            }
            break;
        case 2U:
            switch (voltCode)
            {
                case 0U:
                    *microVolt = 500000U;
                    break;
                case 1U:
                    *microVolt = 600000U;
                    break;
                case 2U:
                    *microVolt = 700000U;
                    break;
                case 3U:
                    *microVolt = 980000U;
                    break;
                case 4U:
                    *microVolt = 1000000U;
                    break;
                default:
                    rc = false;
                    break;
            }
            break;
        default:
            rc = false;
            break;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get DVS buck voltages                                                    */
/*--------------------------------------------------------------------------*/
bool PCA9451_BuckDvsVoltageGet(const PCA9451_Type *dev, uint8_t *presetEn,
    uint8_t *b1voltCode, uint8_t *b2voltCode, uint8_t *b3voltCode)
{
    uint8_t val;
    bool rc;

    rc = PCA9451_PmicRead(dev, PCA9451_REG_BUCK123_DVS, &val);

    if (rc)
    {
        *presetEn  = (val & PCA9451_BUCK123_DVS_PRESET_EN_MASK)
            >> PCA9451_BUCK123_DVS_PRESET_EN_SHIFT;
        *b1voltCode = (val & PCA9451_BUCK123_B1_DVS_PRESET_MASK)
            >> PCA9451_BUCK123_B1_DVS_PRESET_SHIFT;
        *b2voltCode = (val & PCA9451_BUCK123_B2_DVS_PRESET_MASK)
            >> PCA9451_BUCK123_B2_DVS_PRESET_SHIFT;
        *b3voltCode = (val & PCA9451_BUCK123_B3_DVS_PRESET_MASK)
            >> PCA9451_BUCK123_B3_DVS_PRESET_SHIFT;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set buck run voltage                                                     */
/*--------------------------------------------------------------------------*/
bool PCA9451_BuckRunVoltageSet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t voltCode)
{
    bool rc = false;
    uint8_t regAddr = 0U;

    switch (buckId)
    {
        case 1U:
            regAddr = PCA9451_REG_BUCK1OUT_DVS0;
            break;
        case 2U:
            regAddr = PCA9451_REG_BUCK2OUT_DVS0;
            break;
        case 3U:
            regAddr = PCA9451_REG_BUCK3OUT_DVS0;
            break;
        case 4U:
            regAddr = PCA9451_REG_BUCK4OUT;
            break;
        case 5U:
            regAddr = PCA9451_REG_BUCK5OUT;
            break;
        case 6U:
            regAddr = PCA9451_REG_BUCK6OUT;
            break;
        default:
            ; /* Intentional empty default */
            break;
    }

    /* SWxOUT_DVS0/SWxOUT registers: bit[7] reserved, bits[6:0] are voltage */
    if (regAddr != 0U)
    {
        rc = PCA9451_PmicWrite(dev, regAddr, voltCode, 0x7FU);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set buck standby voltage                                                 */
/*--------------------------------------------------------------------------*/
bool PCA9451_BuckStbyVoltageSet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t voltCode)
{
    bool rc = false;
    uint8_t regAddr = 0U;

    /* Only SW1/2/3 have DVS1 (standby) registers */
    switch (buckId)
    {
        case 1U:
            regAddr = PCA9451_REG_BUCK1OUT_DVS1;
            break;
        case 2U:
            regAddr = PCA9451_REG_BUCK2OUT_DVS1;
            break;
        case 3U:
            regAddr = PCA9451_REG_BUCK3OUT_DVS1;
            break;
        default:
            ; /* Intentional empty default */
            break;
    }

    /* SWxOUT_DVS1 registers: bit [7] reserved, bits [6:0] are voltage */
    if (regAddr != 0U)
    {
        rc = PCA9451_PmicWrite(dev, regAddr, voltCode, 0x7FU);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set buck preset enable                                                   */
/*--------------------------------------------------------------------------*/
bool PCA9451_SWPresetSet(const PCA9451_Type *dev, uint8_t presetEn)
{
    return PCA9451_PmicWrite(dev, PCA9451_REG_BUCK123_DVS,
        PCA9451_BUCK123_DVS_PRESET_EN(presetEn),
        PCA9451_BUCK123_DVS_PRESET_EN_MASK);
}

/*--------------------------------------------------------------------------*/
/* Set I2C level translation                                                */
/*--------------------------------------------------------------------------*/
bool PCA9451_ConfigI2cLevelTransSet(const PCA9451_Type *dev,
    uint8_t i2cLtEn)
{
    return PCA9451_PmicWrite(dev, PCA9451_REG_CONFIG2,
        PCA9451_CONFIG2_I2C_LT_EN(i2cLtEn),
        PCA9451_CONFIG2_I2C_LT_EN_MASK);
}

/*--------------------------------------------------------------------------*/
/* Set WDOG_B response                                                      */
/*--------------------------------------------------------------------------*/
bool PCA9451_ConfigWdogbResponseSet(const PCA9451_Type *dev,
    uint8_t wdogbResp)
{
    return PCA9451_PmicWrite(dev, PCA9451_REG_RESET_CTRL,
        PCA9451_RESET_CTRL_WDOG_B_CFG(wdogbResp),
        PCA9451_RESET_CTRL_WDOG_B_CFG_MASK);
}

/*--------------------------------------------------------------------------*/
/* Set BUCK Out Limit value                                                 */
/*--------------------------------------------------------------------------*/
bool PCA9451_BuckLimitSet(const PCA9451_Type *dev,
    uint8_t buckId, uint32_t microVolt)
{
    bool rc = false;
    uint8_t code = 0U;

    if ((buckId >= PCA9451_REG_SW1) &&
        (buckId <= PCA9451_REG_SW3))
    {
        rc = PCA9451_ConvertVolts2Code(buckId,
            microVolt, &code);
    }

    if (rc == true)
    {
        /* Write the voltage code to BUCK limit register */
        rc = PCA9451_PmicWrite(dev, buckId + PCA9451_BUCKOUT_LIMIT_OFFSET,
            code, PCA9451_BUCK123_OUT_LIMIT_MASK);
    }

    /* return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get BUCK Out Limit value                                                 */
/*--------------------------------------------------------------------------*/
bool PCA9451_BuckLimitGet(const PCA9451_Type *dev,
    uint8_t buckId, uint32_t *microVolt)
{
    bool rc = false;
    uint8_t code = 0U;

    if ((buckId >= PCA9451_REG_SW1) &&
        (buckId <= PCA9451_REG_SW3))
    {
        /* Read the voltage code */
        rc = PCA9451_PmicRead(dev, buckId + PCA9451_BUCKOUT_LIMIT_OFFSET,
            &code);
        if (rc == true)
        {
            rc = PCA9451_ConvertCode2Volts(buckId,
                (code & PCA9451_BUCK123_OUT_LIMIT_MASK), microVolt);
        }
        else
        {
            rc = false;
        }
    }
    else
    {
        rc = false;
    }

    /* return status */
    return rc;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Convert microvolts to register code                                      */
/*--------------------------------------------------------------------------*/
static bool PCA9451_ConvertVolts2Code(uint8_t regulator, uint32_t microVolt,
    uint8_t *voltCode)
{
    bool rc = true;
    uint32_t code = 0U;

    switch (regulator)
    {
        case PCA9451_REG_SW1:
        case PCA9451_REG_SW3:
            /*
             * Table 43: SW1/SW3 DVS output voltage
             * 0x00 = 0.6500 V ... 0x7F = 2.2375 V, step 12.5 mV
             * Formula: code = (microVolt - 650000) / 12500
             */
            if ((microVolt >= 650000U) && (microVolt <= 2237500U))
            {
                code = (microVolt - 650000U) / 12500U;
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_SW2:
            /*
             * Table 44: SW2 output voltage
             * 0x00 = 0.6000 V ... 0x7F = 2.1875 V, step 12.5 mV
             * Formula: code = (microVolt - 600000) / 12500
             */
            if ((microVolt >= 500000U) && (microVolt <= 2087500U))
            {
                code = (microVolt - 500000U) / 12500U;
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_SW4:
        case PCA9451_REG_SW5:
            /*
             * Table 51: SW4/5/6 output voltage
             * 0x00 = 0.600 V, step 25 mV up to 0x70 = 3.400 V
             * Codes 0x71-0x7F are also clamped to 3.400 V per the table.
             * Formula: code = (microVolt - 600000) / 25000, clamped to 0x70.
             */
            if ((microVolt >= 600000U) && (microVolt <= 3400000U))
            {
                code = (microVolt - 600000U) / 25000U;
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_SW6:
            /*
             * Table 52: SW6 output voltage
             * 0x00 = 0.550 V, step 25 mV up to 0x70 = 3.350 V
             * Codes 0x71-0x7F are also clamped to 3.350 V per the table.
             * Formula: code = (microVolt - 550000) / 25000, clamped to 0x70.
             */
            if ((microVolt >= 550000U) && (microVolt <= 3350000U))
            {
                code = (microVolt - 550000U) / 25000U;
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_LDO1:
            /*
             * Table 53 (LDO1CTRL bits [2:0]):
             * 000 = 1.6 V, 001 = 1.7 V, 010 = 1.8 V, 011 = 1.9 V
             * 100 = 3.0 V, 101 = 3.1 V, 110 = 3.2 V, 111 = 3.3 V
             */
            if ((microVolt >= 1600000U) && (microVolt <= 1900000U))
            {
                code = (microVolt - 1600000U) / 100000U;       /* 0–3 */
            }
            else if ((microVolt >= 3000000U) && (microVolt <= 3300000U))
            {
                code = 4U + ((microVolt - 3000000U) / 100000U); /* 4–7 */
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_LDO3:
            /*
             * Table 56 (LDO3 output voltage):
             * 0x00 = 0.80 V → 0x18 = 3.10 V (100 mV steps)
             * 0x18 = 3.20 V
             * 0x19–0x1F = 3.30 V
             */
            if ((microVolt >= 800000U) && (microVolt <= 3100000U))
            {
                code = (microVolt - 800000U) / 100000U;    /* 0x00 – 0x17 */
            }
            else if (microVolt == 3200000U)
            {
                code = 0x18;
            }
            else if (microVolt == 3300000U)
            {
                code = 0x19U;   /* choose base of 3.3V range */
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_LDO4:
            /*
             * Table 58 (LDO4CTRL bits [4:0]):
             * 0x00 = 0.8375 V ... 0x19 = 3.46 V, step 104.9 mV
             * Codes 0x1A–0x1F are clamped to 3.46 V.
             * Formula: code = (microVolt - 837500) / 100000
             */
            if ((microVolt >= 837500U) && (microVolt <= 3460000U))
            {
                code = (microVolt - 837500U) / 104900U;
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_LDO5_L:
        case PCA9451_REG_LDO5_H:
            /*
             * Table 60, 61 (LDO5CTRL_L bits [3:0], LDO5CTRL_H bits [3:0]):
             * 0x0 = 1.80 V ... 0xF = 3.30 V, step 100 mV
             * Formula: code = (microVolt - 1800000) / 100000
             */
            if ((microVolt >= 1800000U) && (microVolt <= 3300000U))
            {
                code = (microVolt - 1800000U) / 100000U;
            }
            else
            {
                rc = false;
            }
            break;

        default:
            rc = false;
            break;
    }

    /* Return result */
    if (rc && (voltCode != NULL))
    {
        *voltCode = (uint8_t) code;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Convert register code to microvolts                                      */
/*--------------------------------------------------------------------------*/
static bool PCA9451_ConvertCode2Volts(uint8_t regulator, uint8_t voltCode,
    uint32_t *microVolt)
{
    bool rc = true;
    uint32_t microV = 0U;
    uint32_t code = (uint32_t) voltCode;

    switch (regulator)
    {
        case PCA9451_REG_SW1:
        case PCA9451_REG_SW3:
            /*
             * Table 43: 0x00 = 0.6500 V ... 0x7F = 2.2375 V, 12.5 mV step
             */
            if (code <= 0x7FU)
            {
                microV = 650000U + (code * 12500U);
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_SW2:
            /*
             * Table 44: 0x00 = 0.6000 V ... 0x7F = 2.1875 V, 12.5 mV step
             */
            if (code <= 0x7FU)
            {
                microV = 500000U + (code * 12500U);
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_SW4:
        case PCA9451_REG_SW5:
            /*
             * Table 51: 0x00 = 0.600V, 25mV step. Codes >= 0x70 clamp to 3.4V
             */
            if (code <= 0x70U)
            {
                microV = 600000U + (code * 25000U);
            }
            else if (code <= 0x7FU)
            {
                microV = 3400000U;
            }
            else
            {
                rc = false;
            }
            break;
        case PCA9451_REG_SW6:
            /*
             * Table 52: 0x00 = 0.600V, 25mV step. Codes >= 0x70 clamp to 3.4V
             */
            if (code <= 0x70U)
            {
                microV = 550000U + (code * 25000U);
            }
            else if (code <= 0x7FU)
            {
                microV = 3550000U;
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_LDO1:
            /*
             * Table 53 (bits [2:0]):
             * 0–3: 1.6–1.9 V (100 mV step); 4–7: 3.0–3.3 V (100 mV step)
             */
            if (code <= 3U)
            {
                microV = 1600000U + (code * 100000U);
            }
            else if (code <= 7U)
            {
                microV = 3000000U + ((code - 4U) * 100000U);
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_LDO3:
            /*
             * Table 56 (LDO3 output voltage):
             * 0x00 = 0.80 V → 0x17 = 3.10 V (100 mV steps)
             * 0x18 = 3.20 V
             * 0x19–0x1F = 3.30 V
             */
            if (code <= 0x17U)
            {
                microV = 800000U + (code * 100000U);
            }
            else if (code == 0x18U)
            {
                microV = 3200000U;
            }
            else if (code <= 0x1FU)
            {
                microV = 3300000U;
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_LDO4:
            /*
             * Table 58 (bits [4:0]):
             * 0x00 = 0.80 V ... 0x19 = 3.30 V, 100 mV step.
             * Codes 0x1A–0x1F clamped to 3.30 V.
             */
            if (code <= 0x19U)
            {
                microV = 837500U + (code * 104900U);
            }
            else if (code <= 0x1FU)
            {
                microV = 3460000U;
            }
            else
            {
                rc = false;
            }
            break;

        case PCA9451_REG_LDO5_L:
        case PCA9451_REG_LDO5_H:
            /*
             * Table 60, 61 (bits [3:0]):
             * 0x0 = 1.80 V ... 0xF = 3.30 V, 100 mV step
             */
            if (code <= 0xFU)
            {
                microV = 1800000U + (code * 100000U);
            }
            else
            {
                rc = false;
            }
            break;

        default:
            rc = false;
            break;
    }

    /* Return result */
    if (rc && (microVolt != NULL))
    {
        *microVolt = microV;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get SWx control register address                                         */
/*--------------------------------------------------------------------------*/
static bool PCA9451_BuckCtrlAddr(uint8_t buckId, uint8_t *ctrlAddr)
{
    bool rc = true;

    switch (buckId)
    {
        case 1U:
            *ctrlAddr = PCA9451_REG_BUCK1CTRL;
            break;
        case 2U:
            *ctrlAddr = PCA9451_REG_BUCK2CTRL;
            break;
        case 3U:
            *ctrlAddr = PCA9451_REG_BUCK3CTRL;
            break;
        case 4U:
            *ctrlAddr = PCA9451_REG_BUCK4CTRL;
            break;
        case 5U:
            *ctrlAddr = PCA9451_REG_BUCK5CTRL;
            break;
        case 6U:
            *ctrlAddr = PCA9451_REG_BUCK6CTRL;
            break;
        default:
            rc = false;
            break;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get regulator voltage register address                                   */
/*--------------------------------------------------------------------------*/
static bool PCA9451_BuckVoltAddr(uint8_t buckId, uint8_t state,
    uint8_t *voltAddr)
{
    bool rc = true;

    switch (buckId)
    {
        case PCA9451_REG_SW1:
            /* DVS0 = run, DVS1 = standby */
            *voltAddr = (state == PCA9451_STATE_STBY) ?
                PCA9451_REG_BUCK1OUT_DVS1 : PCA9451_REG_BUCK1OUT_DVS0;
            break;
        case PCA9451_REG_SW2:
            *voltAddr = (state == PCA9451_STATE_STBY) ?
                PCA9451_REG_BUCK2OUT_DVS1 : PCA9451_REG_BUCK2OUT_DVS0;
            break;
        case PCA9451_REG_SW3:
            *voltAddr = (state == PCA9451_STATE_STBY) ?
                PCA9451_REG_BUCK3OUT_DVS1 : PCA9451_REG_BUCK3OUT_DVS0;
            break;
        case PCA9451_REG_SW4:
            /* SW4-6 have single output register (no DVS1) */
            *voltAddr = PCA9451_REG_BUCK4OUT;
            break;
        case PCA9451_REG_SW5:
            *voltAddr = PCA9451_REG_BUCK5OUT;
            break;
        case PCA9451_REG_SW6:
            *voltAddr = PCA9451_REG_BUCK6OUT;
            break;
        case PCA9451_REG_LDO1:
            /* LDO voltage is in the LDOxCTRL register */
            *voltAddr = PCA9451_REG_LDO1CTRL;
            break;
        case PCA9451_REG_LDO3:
            /* LDO voltage is in the LDOxCTRL register */
            *voltAddr = PCA9451_REG_LDO3CTRL;
            break;
        case PCA9451_REG_LDO4:
            *voltAddr = PCA9451_REG_LDO4CTRL;
            break;
        case PCA9451_REG_LDO5_L:
            /* LDO5CTRL_L holds the SD_VSEL=Low voltage (run-state voltage) */
            *voltAddr = PCA9451_REG_LDO5CTRL_L;
            break;
        case PCA9451_REG_LDO5_H:
            /* LDO5CTRL_H holds the SD_VSEL=high voltage (run-state voltage) */
            *voltAddr = PCA9451_REG_LDO5CTRL_H;
            break;
        default:
            rc = false;
            break;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get LDO control register address                                         */
/*--------------------------------------------------------------------------*/
static bool PCA9451_LdoCtrlAddr(uint8_t ldoId, uint8_t *ctrlAddr)
{
    bool rc = true;

    switch (ldoId)
    {
        case PCA9451_REG_LDO1:
            *ctrlAddr = PCA9451_REG_LDO1CTRL;
            break;
        case PCA9451_REG_LDO3:
            *ctrlAddr = PCA9451_REG_LDO3CTRL;
            break;
        case PCA9451_REG_LDO4:
            *ctrlAddr = PCA9451_REG_LDO4CTRL;
            break;
        case PCA9451_REG_LDO5_L:
        case PCA9451_REG_LDO5_H:
            /* ENMODE is in LDO5CTRL_L (bits [7:6]) */
            *ctrlAddr = PCA9451_REG_LDO5CTRL_L;
            break;
        default:
            rc = false;
            break;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* LPI2C port transmit                                                      */
/*--------------------------------------------------------------------------*/
static status_t BRD_SM_LPI2C_Send(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t subAddressSize, uint8_t *txBuff,
    uint8_t txBuffSize, uint32_t flags)
{
    lpi2c_master_transfer_t xfer;

    xfer.flags          = flags;
    xfer.slaveAddress   = deviceAddress;
    xfer.direction      = kLPI2C_Write;
    xfer.subaddress     = subAddress;
    xfer.subaddressSize = subAddressSize;
    xfer.data           = txBuff;
    xfer.dataSize       = txBuffSize;

    return LPI2C_MasterTransferBlocking(base, &xfer);
}

/*--------------------------------------------------------------------------*/
/* LPI2C port receive                                                       */
/*--------------------------------------------------------------------------*/
static status_t BRD_SM_LPI2C_Receive(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t subAddressSize, uint8_t *rxBuff,
    uint8_t rxBuffSize, uint32_t flags)
{
    lpi2c_master_transfer_t xfer;

    xfer.flags          = flags;
    xfer.slaveAddress   = deviceAddress;
    xfer.direction      = kLPI2C_Read;
    xfer.subaddress     = subAddress;
    xfer.subaddressSize = subAddressSize;
    xfer.data           = rxBuff;
    xfer.dataSize       = rxBuffSize;

    return LPI2C_MasterTransferBlocking(base, &xfer);
}

