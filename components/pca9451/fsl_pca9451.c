/*
 * Copyright 2022 NXP
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

#define PCA9451_NUM_LDO                5U
#define PCA9451_NUM_BUCK               6U
#define PCA9451_NUM_REG                0x2FU

#define PCA9451_REG_DEV_ID             0x00U
#define PCA9451_REG_INT1               0x01U
#define PCA9451_REG_INT1_MSK           0x02U
#define PCA9451_REG_STATUS1            0x03U
#define PCA9451_REG_STATUS2            0x04U
#define PCA9451_REG_PWRON_STAT         0x05U
#define PCA9451_REG_SW_RST             0x06U
#define PCA9451_REG_PWR_CTRL           0x07U
#define PCA9451_REG_RESET_CTRL         0x08U
#define PCA9451_REG_CONFIG1            0x09U
#define PCA9451_REG_CONFIG2            0x0AU
#define PCA9451_REG_BUCK123_DVS        0x0CU
#define PCA9451_REG_BUCK1OUT_LIMIT     0x0DU
#define PCA9451_REG_BUCK2OUT_LIMIT     0x0EU
#define PCA9451_REG_BUCK3OUT_LIMIT     0x0FU
#define PCA9451_REG_BUCK1CTRL          0x10U
#define PCA9451_REG_BUCK1OUT_DVS0      0x11U
#define PCA9451_REG_BUCK1OUT_DVS1      0x12U
#define PCA9451_REG_BUCK2CTRL          0x13U
#define PCA9451_REG_BUCK2OUT_DVS0      0x14U
#define PCA9451_REG_BUCK2OUT_DVS1      0x15U
#define PCA9451_REG_BUCK3CTRL          0x16U
#define PCA9451_REG_BUCK3OUT_DVS0      0x17U
#define PCA9451_REG_BUCK3OUT_DVS1      0x18U
#define PCA9451_REG_BUCK4CTRL          0x19U
#define PCA9451_REG_BUCK4OUT           0x1AU
#define PCA9451_REG_BUCK5CTRL          0x1BU
#define PCA9451_REG_BUCK5OUT           0x1CU
#define PCA9451_REG_BUCK6CTRL          0x1DU
#define PCA9451_REG_BUCK6OUT           0x1EU
#define PCA9451_REG_LDO_AD_CTRL        0x20U
#define PCA9451_REG_LDO1CTRL           0x21U
#define PCA9451_REG_LDO2CTRL           0x22U
#define PCA9451_REG_LDO3CTRL           0x23U
#define PCA9451_REG_LDO4CTRL           0x24U
#define PCA9451_REG_LDO5CTRL_L         0x25U
#define PCA9451_REG_LDO5CTRL_H         0x26U
#define PCA9451_REG_LOADSW_CTRL        0x2AU
#define PCA9451_REG_VRFLT1_STS         0x2BU
#define PCA9451_REG_VRFLT2_STS         0x2CU
#define PCA9451_REG_VRFLT1_MASK        0x2DU
#define PCA9451_REG_VRFLT2_MASK        0x2EU

#define PCA9451_RESET_CTRL_WDOG_B_CFG_MASK  (0xC0U)
#define PCA9451_RESET_CTRL_WDOG_B_CFG_SHIFT (6U)
#define PCA9451_RESET_CTRL_WDOG_B_CFG(x)    (((uint8_t)(((uint8_t)(x)) << PCA9451_RESET_CTRL_WDOG_B_CFG_SHIFT)) & PCA9451_RESET_CTRL_WDOG_B_CFG_MASK)

#define PCA9451_CONFIG2_I2C_LT_EN_MASK      (0x03U)
#define PCA9451_CONFIG2_I2C_LT_EN_SHIFT     (0U)
#define PCA9451_CONFIG2_I2C_LT_EN(x)        (((uint8_t)(((uint8_t)(x)) << PCA9451_CONFIG2_I2C_LT_EN_SHIFT)) & PCA9451_CONFIG2_I2C_LT_EN_MASK)

#define PCA9451_BUCK123_DVS_PRESET_EN_MASK  (0x80U)
#define PCA9451_BUCK123_DVS_PRESET_EN_SHIFT (7U)
#define PCA9451_BUCK123_DVS_PRESET_EN(x)    (((uint8_t)(((uint8_t)(x)) << PCA9451_BUCK123_DVS_PRESET_EN_SHIFT)) & PCA9451_BUCK123_DVS_PRESET_EN_MASK)

#define PCA9451_BUCK123_B3_DVS_PRESET_MASK  (0x60U)
#define PCA9451_BUCK123_B3_DVS_PRESET_SHIFT (5U)
#define PCA9451_BUCK123_B3_DVS_PRESET(x)    (((uint8_t)(((uint8_t)(x)) << PCA9451_BUCK123_B3_DVS_PRESET_SHIFT)) & PCA9451_BUCK123_B3_DVS_PRESET_MASK)

#define PCA9451_BUCK123_B1_DVS_PRESET_MASK  (0x18U)
#define PCA9451_BUCK123_B1_DVS_PRESET_SHIFT (3U)
#define PCA9451_BUCK123_B1_DVS_PRESET(x)    (((uint8_t)(((uint8_t)(x)) << PCA9451_BUCK123_B1_DVS_PRESET_SHIFT)) & PCA9451_BUCK123_B1_DVS_PRESET_MASK)

#define PCA9451_BUCK123_B2_DVS_PRESET_MASK  (0x7U)
#define PCA9451_BUCK123_B2_DVS_PRESET_SHIFT (0U)
#define PCA9451_BUCK123_B2_DVS_PRESET(x)    (((uint8_t)(((uint8_t)(x)) << PCA9451_BUCK123_B2_DVS_PRESET_SHIFT)) & PCA9451_BUCK123_B2_DVS_PRESET_MASK)

/* Local Types */

/* Local Functions */

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
bool PCA9451_Init(const PCA9451_Type *dev, uint8_t wdogbResp,
    uint8_t i2cLtEn)
{
    uint8_t devId;

    bool rc = PCA9451_PmicRead(dev, PCA9451_REG_DEV_ID, &devId);

    if (rc && (devId == PCA9451_CHIP_ID))
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
bool PCA9451_PmicInfoGet(const PCA9451_Type *dev, uint8_t **info,
    uint8_t *len)
{
    bool rc = true;
    static uint8_t devId;

    /* Get device Id */
    if (devId == 0U)
    {
        rc = PCA9451_PmicRead(dev, PCA9451_REG_DEV_ID, &devId);
    }

    /* Return results */
    if (rc)
    {
        *info = &devId;
        *len = 1U;
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
                uint8_t txBuf = (val & mask) | (rxBuf & (~mask));

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
/* Convert voltage to buck voltage code                                     */
/*--------------------------------------------------------------------------*/
bool PCA9451_BuckDvsVoltage2CodeConvert(uint32_t buckIdx, uint32_t microVolt,
    uint32_t *voltCode)
{
    bool rc = true;

    switch (buckIdx)
    {
        case 1U:
        case 3U:
            switch(microVolt)
            {
                case 750000U:
                    *voltCode = 0U;
                    break;
                case 800000U:
                    *voltCode = 1U;
                    break;
                case 850000U:
                    *voltCode = 2U;
                    break;
                case 900000U:
                    *voltCode = 3U;
                    break;
                default:
                    rc = false;
                    break;
            }
            break;
        case 2U:
            switch(microVolt)
            {
                case 600000U:
                    *voltCode = 0U;
                    break;
                case 700000U:
                    *voltCode = 1U;
                    break;
                case 800000U:
                    *voltCode = 2U;
                    break;
                case 900000U:
                    *voltCode = 3U;
                    break;
                case 1100000U:
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
/* Convert buck voltage code to voltage                                     */
/*--------------------------------------------------------------------------*/
bool PCA9451_BuckDvsCode2VoltageConvert(uint32_t buckIdx, uint32_t voltCode,
    uint32_t *microVolt)
{
    bool rc = true;

    switch (buckIdx)
    {
        case 1U:
        case 3U:

            switch(voltCode)
            {
                case 0U:
                    *microVolt = 750000U;
                    break;
                case 1U:
                    *microVolt = 800000U;
                    break;
                case 2U:
                    *microVolt = 850000U;
                    break;
                case 3U:
                    *microVolt = 900000U;
                    break;
                default:
                    rc = false;
                    break;
            }
            break;
        case 2U:
            switch(voltCode)
            {
                case 0U:
                    *microVolt = 600000U;
                    break;
                case 1U:
                    *microVolt = 700000U;
                    break;
                case 2U:
                    *microVolt = 800000U;
                    break;
                case 3U:
                    *microVolt = 900000U;
                    break;
                case 4U:
                    *microVolt = 1100000U;
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
        *presetEn = (val & PCA9451_BUCK123_DVS_PRESET_EN_MASK)
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

    switch(buckId)
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

    if (regAddr != 0U)
    {
        rc = PCA9451_PmicWrite(dev, regAddr, voltCode, 0xFFU);
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

    switch(buckId)
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

    if (regAddr != 0U)
    {
        rc = PCA9451_PmicWrite(dev, regAddr, voltCode, 0xFFU);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set buck preset enable                                                   */
/*--------------------------------------------------------------------------*/
bool PCA9451_BuckPresetSet(const PCA9451_Type *dev, uint8_t presetEn)
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

/*==========================================================================*/

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

