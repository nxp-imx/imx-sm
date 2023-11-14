/*
 * Copyright 2023 NXP
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

#include "fsl_pf09.h"
#include "crc.h"

/* Local Defines */

#define PF09_FAMILY_ID          0x09U

#define PF09_NUM_LDO            5U
#define PF09_NUM_BUCK           3U
#define PF09_NUM_REG            0x82U

#define PF09_REG_DEV_ID         0x00U
#define PF09_REG_DEV_FAM_ID     0x01U
#define PF09_REG_REV_ID         0x02U
#define PF09_REG_PROG_ID1       0x03U
#define PF09_REG_PROG_ID2       0x04U
#define PF09_REG_SYSTEM_INT     0x05U
#define PF09_REG_STATUS1_INT    0x06U
#define PF09_REG_STATUS1_MASK   0x07U
#define PF09_REG_STATUS1_SNS    0x08U
#define PF09_REG_STATUS2_INT    0x09U
#define PF09_REG_STATUS2_MASK   0x0AU
#define PF09_REG_STATUS2_SNS    0x0BU
#define PF09_REG_STATUS3_INT    0x0CU
#define PF09_REG_STATUS3_MASK   0x0DU
#define PF09_REG_SW_MODE_INT    0x0EU
#define PF09_REG_SW_MODE_MASK   0x0FU
#define PF09_REG_SW_ILIM_INT    0x10U
#define PF09_REG_SW_ILIM_MASK   0x11U
#define PF09_REG_SW_ILIM_SNS    0x12U
#define PF09_REG_LDO_ILIM_INT   0x13U
#define PF09_REG_LDO_ILIM_MASK  0x14U
#define PF09_REG_LDO_ILIM_SNS   0x15U
#define PF09_REG_SW_UV_INT      0x16U
#define PF09_REG_SW_UV_MASK     0x17U
#define PF09_REG_SW_UV_SNS      0x18U
#define PF09_REG_SW_OV_INT      0x19U
#define PF09_REG_SW_OV_MASK     0x1AU
#define PF09_REG_SW_OV_SNS      0x1BU
#define PF09_REG_LDO_UV_INT     0x1CU
#define PF09_REG_LDO_UV_MASK    0x1DU
#define PF09_REG_LDO_UV_SNS     0x1EU
#define PF09_REG_LDO_OV_INT     0x1FU
#define PF09_REG_LDO_OV_MASK    0x20U
#define PF09_REG_LDO_OV_SNS     0x21U
#define PF09_REG_PWRON_INT      0x22U
#define PF09_REG_PWRON_MASK     0x23U
#define PF09_REG_IO_INT         0x24U

#define PF09_REG_HFAULT_FLAGS   0x2EU
#define PF09_REG_FAULT_FLAGS    0x2FU
#define PF09_REG_FS0B_CFG       0x30U
#define PF09_REG_FCCU_CFG       0x31U
#define PF09_REG_RSTB_CFG1      0x32U

#define PF09_REG_SECURE_WR1     0x35U
#define PF09_REG_SECURE_WR2     0x36U

#define PF09_REG_WD_CTRL1       0x4EU
#define PF09_REG_WD_CTRL2       0x4FU
#define PF09_REG_WD_CFG1        0x50U
#define PF09_REG_WD_CFG2        0x51U
#define PF09_REG_WD_CNT1        0x52U
#define PF09_REG_WD_CNT2        0x53U
#define PF09_REG_FAULT_CFG      0x54U
#define PF09_REG_FAULT_CNT      0x55U

#define PF09_REG_SW1_VRUN       0x5EU
#define PF09_REG_SW1_VSTBY      0x5FU
#define PF09_REG_SW1_MODE       0x60U
#define PF09_REG_SW1_CFG1       0x61U
#define PF09_REG_SW1_CFG2       0x62U
#define PF09_REG_SW2_VRUN       0x63U
#define PF09_REG_SW2_VSTBY      0x64U
#define PF09_REG_SW2_MODE       0x65U
#define PF09_REG_SW2_CFG1       0x66U
#define PF09_REG_SW2_CFG2       0x67U
#define PF09_REG_SW3_VRUN       0x68U
#define PF09_REG_SW3_VSTBY      0x69U
#define PF09_REG_SW3_MODE       0x6AU
#define PF09_REG_SW3_CFG1       0x6BU
#define PF09_REG_SW3_CFG2       0x6CU
#define PF09_REG_SW4_VRUN       0x6DU
#define PF09_REG_SW4_VSTBY      0x6EU
#define PF09_REG_SW4_MODE       0x6FU
#define PF09_REG_SW4_CFG1       0x70U
#define PF09_REG_SW4_CFG2       0x71U
#define PF09_REG_SW5_VRUN       0x72U
#define PF09_REG_SW5_VSTBY      0x73U
#define PF09_REG_SW5_MODE       0x74U
#define PF09_REG_SW5_CFG1       0x75U
#define PF09_REG_SW5_CFG2       0x76U
#define PF09_REG_LDO1_RUN       0x77U
#define PF09_REG_LDO1_STBY      0x78U
#define PF09_REG_LDO1_CFG2      0x79U
#define PF09_REG_LDO2_RUN       0x7AU
#define PF09_REG_LDO2_STBY      0x7BU
#define PF09_REG_LDO2_CFG2      0x7CU
#define PF09_REG_LDO3_RUN       0x7EU
#define PF09_REG_LDO3_STBY      0x7EU
#define PF09_REG_LDO3_CFG2      0x7FU

#define STATUS2_I_BIT           1U
#define STATUS1_MSK             1U
#define STATUS2_MSK             2U
#define STATUS3_MSK             3U

/* Local Types */

typedef struct
{
    uint8_t addr;
    uint8_t sysStat;
} mask_reg_t;

/* Local Functions */

static bool PF09_ConvertVolts2Code(uint8_t regulator, uint32_t microVolt,
    uint8_t *voltCode);
static bool PF09_ConvertCode2Volts(uint8_t regulator, uint8_t voltCode,
    uint32_t *microVolt);
static bool PF09_RegulatorAddr(uint8_t regulator, uint8_t state,
    uint8_t *addr);
static status_t PF09_LPI2C_Send(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t subAddressSize, uint8_t *txBuff,
    uint8_t txBuffSize, uint32_t flags);
static status_t PF09_LPI2C_Receive(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t subAddressSize, uint8_t *rxBuff,
    uint8_t rxBuffSize, uint32_t flags);

/* Local Variables */

/* Array of mask register addresses and system status bit mask */
static const mask_reg_t maskInfo[PF09_MASK_LEN] =
{
    {PF09_REG_STATUS1_INT,  0x01},
    {PF09_REG_STATUS2_INT,  0x02},
    {PF09_REG_STATUS3_INT,  0x02},
    {PF09_REG_SW_MODE_INT,  0x04},
    {PF09_REG_SW_ILIM_INT,  0x08},
    {PF09_REG_LDO_ILIM_INT, 0x08},
    {PF09_REG_SW_UV_INT,    0x10},
    {PF09_REG_SW_OV_INT,    0x20},
    {PF09_REG_LDO_UV_INT,   0x10},
    {PF09_REG_LDO_OV_INT,   0x20},
    {PF09_REG_PWRON_INT,    0x40},
    {PF09_REG_IO_INT,       0x40}
};

/* Global Variables */

/*--------------------------------------------------------------------------*/
/* Initialize PMIC                                                          */
/*--------------------------------------------------------------------------*/
bool PF09_Init(const PF09_Type *dev)
{
    uint8_t devId;

    bool rc = PF09_PmicRead(dev, PF09_REG_DEV_FAM_ID, &devId);

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get info                                                                 */
/*--------------------------------------------------------------------------*/
bool PF09_PmicInfoGet(const PF09_Type *dev, uint8_t **info, uint8_t *len)
{
    bool rc = true;
    static uint8_t devId[5];

    if ((info == NULL) || (len == NULL))
    {
        rc = false;
    }
    else
    {
        if (devId[1] == 0U)
        {
            for (uint8_t addr = 0U; addr < 5U; addr++)
            {
                rc = PF09_PmicRead(dev, addr, &devId[addr]);
                if (!rc)
                {
                    break;
                }
            }
        }
    }

    /* Return results */
    if (rc)
    {
        *info = devId;
        *len = 5U;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Register write                                                           */
/*--------------------------------------------------------------------------*/
bool PF09_PmicWrite(const PF09_Type *dev, uint8_t regAddr, uint8_t val,
    uint8_t mask)
{
    bool rc = true;

    if (regAddr < PF09_NUM_REG)
    {
        uint8_t data[2];

        if (dev == NULL)
        {
            rc = false;
        }
        else
        {
            /* If not updating entire register, perform a read-mod-write */
            data[0] = val;
            if (mask != 0xFFU)
            {
                uint8_t rxBuf;

                /* Read data */
                rc = PF09_PmicRead(dev, regAddr, &rxBuf);
                if (rc)
                {
                    data[0] = (val & mask) | (rxBuf & (~mask));
                }
            }

            /* CRC required? */
            if (dev->crcEn)
            {
                uint8_t crcBuf[3];

                /* Get CRC */
                crcBuf[0] = dev->devAddr << 1U;
                crcBuf[1] = regAddr;
                crcBuf[2] = data[0];
                data[1] = CRC_J1850(crcBuf, 3U);
            }

            /* Write data */
            if (rc)
            {
                rc = (PF09_LPI2C_Send(dev->i2cBase, dev->devAddr, regAddr,
                    1U, data, dev->crcEn ? 2U : 1U, 0U) == kStatus_Success);
            }
        }
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Register read                                                            */
/*--------------------------------------------------------------------------*/
bool PF09_PmicRead(const PF09_Type *dev, uint8_t regAddr, uint8_t *val)
{
    bool rc = true;

    if (regAddr < PF09_NUM_REG)
    {
        uint8_t data[2];

        if ((dev == NULL) || (val == NULL))
        {
            rc = false;
        }
        else
        {
            /* Read data */
            rc = (PF09_LPI2C_Receive(dev->i2cBase, dev->devAddr, regAddr, 1U,
                data, dev->crcEn ? 2U : 1U, 0U) == kStatus_Success);
            if (rc)
            {
                /* Return data */
                *val = data[0];

                /* CRC required? */
                if (dev->crcEn)
                {
                    uint8_t crcBuf[3];
                    uint8_t crc;

                    /* Get CRC */
                    crcBuf[0] = (dev->devAddr << 1U) | 0x1U;
                    crcBuf[1] = regAddr;
                    crcBuf[2] = data[0];
                    crc = CRC_J1850(crcBuf, 3U);

                    /* Check CRC */
                    if (crc != data[1])
                    {
                        rc = false;
                    }
                }
            }
        }
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/*  Interrupt enable/disable                                                */
/*--------------------------------------------------------------------------*/
bool PF09_IntEnable(const PF09_Type *dev, const uint8_t *mask, bool enable)
{
    bool rc = true;

    /* Loop over all mask registers */
    for (uint32_t idx = 0U; idx < PF09_MASK_LEN; idx++)
    {
        /* State change? */
        if (mask[idx] != 0U)
        {
            if (enable)
            {
                rc = PF09_PmicWrite(dev, maskInfo[idx].addr + 1U, 0x00U,
                    mask[idx]);
            }
            else
            {
                rc = PF09_PmicWrite(dev, maskInfo[idx].addr + 1U, 0xFFU,
                    mask[idx]);
            }
        }

        /* Exit on error */
        if (!rc)
        {
            break;
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/*  Interrupt status                                                        */
/*--------------------------------------------------------------------------*/
bool PF09_IntStatus(const PF09_Type *dev, uint8_t *mask)
{
    bool rc = true;
    uint8_t stat;

    rc = PF09_PmicRead(dev, PF09_REG_SYSTEM_INT, &stat);
    if (rc)
    {
        /* Loop over all mask registers */
        for (uint32_t idx = 0U; idx < PF09_MASK_LEN; idx++)
        {
            if ((stat & maskInfo[idx].sysStat) != 0U)
            {
                rc = PF09_PmicRead(dev, maskInfo[idx].addr, &mask[idx]);

                /* Exit on error */
                if (!rc)
                {
                    break;
                }
            }
            else
            {
                mask[idx] = 0U;
            }
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/*  Interrupt clear                                                         */
/*--------------------------------------------------------------------------*/
bool PF09_IntClear(const PF09_Type *dev, const uint8_t *mask)
{
    bool rc = true;

    /* Loop over all mask registers */
    for (uint32_t idx = 0U; idx < PF09_MASK_LEN; idx++)
    {
        /* Clear any? */
        if (mask[idx] != 0U)
        {
            rc = PF09_PmicWrite(dev, maskInfo[idx].addr, mask[idx], 0xFFU);

            /* Exit on error */
            if (!rc)
            {
                break;
            }
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get regulator info                                                       */
/*--------------------------------------------------------------------------*/
bool PF09_RegulatorInfoGet(uint8_t regulator, PF09_RegInfo *regInfo)
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
            case PF09_REG_SW1:
                {
                    /* set min/max/step in microvolts */
                    regInfo->minV = 500000U;
                    regInfo->maxV = 3300000U;
                    regInfo->stepV = 25000U;
                }
                break;
            case PF09_REG_SW2:
            case PF09_REG_SW3:
            case PF09_REG_SW4:
            case PF09_REG_SW5:
                {
                    /* set min/max/step in microvolts */
                    regInfo->minV = 300000U;
                    regInfo->maxV = 3300000U;
                    regInfo->stepV = 25000U;
                }
                break;
            case PF09_REG_LDO1:
                {
                    /* set min/max/step in microvolts */
                    regInfo->minV = 750000U;
                    regInfo->maxV = 3300000U;
                    regInfo->stepV = 100000U;
                }
                break;
            case PF09_REG_LDO2:
            case PF09_REG_LDO3:
                {
                    /* set min/max/step in microvolts */
                    regInfo->minV = 650000U;
                    regInfo->maxV = 3300000U;
                    regInfo->stepV = 100000U;
                }
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
/* Change Buck regulator run/stby operation mode                            */
/*--------------------------------------------------------------------------*/
bool PF09_SwModeSet(const PF09_Type *dev, uint8_t regulator, uint8_t state,
    uint8_t mode)
{
    bool rc = true;

    if ((state > PF09_STATE_VSTBY) || (mode > PF09_SW_MODE_PWM))
    {
        rc = false;
    }
    else
    {
        /* Check regulator index */
        if ((regulator >= PF09_REG_SW1) && (regulator <= PF09_REG_SW5))
        {
            uint8_t modeVal = mode << (state * 2U);
            uint8_t modeMask = 3U << (state * 2U);

            rc = PF09_PmicWrite(dev,
                PF09_REG_SW1_MODE + ((regulator - 1U) * 5U),
                modeVal, modeMask);
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get Buck regulator run/stby operation mode                               */
/*--------------------------------------------------------------------------*/
bool PF09_SwModeGet(const PF09_Type *dev, uint8_t regulator, uint8_t state,
    uint8_t *mode)
{
    bool rc = true;

    if ((state > PF09_STATE_VSTBY) || (mode == NULL))
    {
        rc = false;
    }
    else
    {
        /* Check regulator index */
        if ((regulator >= PF09_REG_SW1) && (regulator <= PF09_REG_SW5))
        {
            /* 0x3 or 0xC for mode bits depending on state */
            uint8_t modeMask = 3U << (state * 2U);

            rc = PF09_PmicRead(dev,
                PF09_REG_SW1_MODE + ((regulator - 1U) * 5U), mode);

            /* Mask and shift the mode bits */
            *mode = ((*mode) & modeMask) >> (state * 2U);
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Enable/Disable linear regulator run/standby output                       */
/*--------------------------------------------------------------------------*/
bool PF09_LdoEnable(const PF09_Type *dev, uint8_t regulator, uint8_t state,
    bool ldoEn)
{
    bool rc = true;

    if (state > PF09_STATE_VSTBY)
    {
        rc = false;
    }
    else
    {
        uint8_t enable;

        if (ldoEn == true)
        {
            /* Set LDO_EN bit */
            enable = 0x20U;
        }
        else
        {
            /* Clear LDO_EN */
            enable = 0x0U;
        }

        /* Check regulator index */
        if ((regulator >= PF09_REG_LDO1) && (regulator <= PF09_REG_LDO3))
        {
            uint8_t addr = PF09_REG_LDO1_RUN + ((regulator
                - PF09_REG_LDO1) * 3U) + state;

            rc = PF09_PmicWrite(dev, addr, enable, 0x20U);
        }
        else
        {
            rc = false;
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Check linear regulator output status                                     */
/*--------------------------------------------------------------------------*/
bool PF09_LdoIsEnabled(const PF09_Type *dev, uint8_t regulator, uint8_t state,
    bool *ldoEn)
{
    bool rc = true;

    if ((state > PF09_STATE_VSTBY) || (ldoEn == NULL))
    {
        rc = false;
    }
    else
    {
        uint8_t enable;

        /* Check regulator index */
        if ((regulator >= PF09_REG_LDO1) && (regulator <= PF09_REG_LDO3))
        {
            uint8_t addr = PF09_REG_LDO1_RUN + ((regulator
                - PF09_REG_LDO1) * 3U) + state;

            rc = PF09_PmicRead(dev, addr, &enable);
            if (rc)
            {
                *ldoEn = (((0x20U & enable) >> 5U) == 1U);
            }
            else
            {
                *ldoEn = false;
            }
        }
        else
        {
            rc = false;
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set regulator run/standby voltage in micro volts                         */
/*--------------------------------------------------------------------------*/
bool PF09_VoltageSet(const PF09_Type *dev, uint8_t regulator, uint8_t state,
    uint32_t microVolt)
{
    bool rc = true;
    uint8_t voltCode = 0U, addr = 0U;

    /* Check regulator index */
    if ((regulator >= PF09_REG_SW1) && (regulator <= PF09_REG_LDO3))
    {
        /* Convert microvolts to code */
        rc = PF09_ConvertVolts2Code(regulator, microVolt, &voltCode);
        if (rc)
        {
            /* Get regulator address */
            rc = PF09_RegulatorAddr(regulator, state, &addr);
        }
    }

    if (rc == true)
    {
        switch (regulator)
        {
            case PF09_REG_SW1:
            case PF09_REG_SW2:
            case PF09_REG_SW3:
            case PF09_REG_SW4:
            case PF09_REG_SW5:
                {
                    /* Write 8-bits */
                    rc = PF09_PmicWrite(dev, addr, voltCode, 0xFFU);
                }
                break;
            case PF09_REG_LDO1:
            case PF09_REG_LDO2:
            case PF09_REG_LDO3:
                {
                    /* Write 5-bits */
                    rc = PF09_PmicWrite(dev, addr, voltCode, 0x1FU);
                }
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
/* Get regulator run/standby voltage in micro volts                         */
/*--------------------------------------------------------------------------*/
bool PF09_VoltageGet(const PF09_Type *dev, uint8_t regulator, uint8_t state,
    uint32_t *microVolt)
{
    bool rc = true;
    uint8_t voltCode = 0U;
    uint8_t addr = 0U;

    /* Check microVolt is not NULL */
    if (microVolt == NULL)
    {
        rc = false;
    }
    /* Check regulator index */
    else if ((regulator >= PF09_REG_SW1) && (regulator <= PF09_REG_LDO3))
    {
        /* Get regulator address */
        rc = PF09_RegulatorAddr(regulator, state, &addr);
    }
    else
    {
        ; /* Intentional empty else */
    }

    if (rc == true)
    {
        switch (regulator)
        {
            case PF09_REG_SW1:
            case PF09_REG_SW2:
            case PF09_REG_SW3:
            case PF09_REG_SW4:
            case PF09_REG_SW5:
                {
                    /* Read 8-bits */
                    rc = PF09_PmicRead(dev, addr, &voltCode);
                }
                break;
            case PF09_REG_LDO1:
            case PF09_REG_LDO2:
            case PF09_REG_LDO3:
                {
                    /* Read 5-bits */
                    rc = PF09_PmicRead(dev, addr, &voltCode);
                    voltCode &= 0x1FU;
                }
                break;
            default:
                rc = false;
                break;
        }
    }

    if (rc)
    {
        /* convert code to microvolts */
        rc = PF09_ConvertCode2Volts(regulator, voltCode, microVolt);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get temp                                                                 */
/*--------------------------------------------------------------------------*/
bool PF09_TempGet(const PF09_Type *dev, int32_t *temp)
{
    bool rc = true;
    uint8_t sns;

    rc = PF09_PmicRead(dev, PF09_REG_STATUS2_SNS, &sns);
    if (rc)
    {
        /* Check for 155C */
        if ((sns & 0x08U) != 0U)
        {
            *temp = 155;
        }
        /* Check for 140C */
        else if ((sns & 0x04U) != 0U)
        {
            *temp = 140;
        }
        /* Check for 125C */
        else if ((sns & 0x02U) != 0U)
        {
            *temp = 125;
        }
        /* Check for 110C */
        else if ((sns & 0x01U) != 0U)
        {
            *temp = 110;
        }
        /* else 105C */
        else
        {
            *temp = 105;
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set temp alarm                                                           */
/*--------------------------------------------------------------------------*/
bool PF09_TempAlarmSet(const PF09_Type *dev, int32_t temp)
{
    bool rc = true;

    /* Disable all */
    rc = PF09_PmicWrite(dev, PF09_REG_STATUS2_MASK, 0x0FU, 0x0FU);

    if (rc)
    {
        uint8_t mask;

        if (temp > 155)
        {
            mask = 0x00U;
        }
        else if (temp > 140)
        {
            mask = 0x08U;
        }
        else if (temp > 125)
        {
            mask = 0x04U;
        }
        else if (temp > 110)
        {
            mask = 0x02U;
        }
        else
        {
            mask = 0x01U;
        }

        /* Enable desired interrupt */
        rc = PF09_PmicWrite(dev, PF09_REG_STATUS2_MASK, 0x00U, mask);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Watchdog Enable/Disable                                                  */
/*--------------------------------------------------------------------------*/
bool PF09_WdogEnable(const PF09_Type *dev, bool wdogEn)
{
    uint8_t wdEn;
    bool rc = true;

    if (wdogEn == true)
    {
        /* Set WD_EN bit */
        wdEn = 0x80U;
    }
    else
    {
        /* Clear WD_EN */
        wdEn = 0x0U;
    }

    rc = PF09_PmicWrite(dev, PF09_REG_WD_CFG1, wdEn, 0x80U);

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Service the watchdog in open window                                      */
/*--------------------------------------------------------------------------*/
bool PF09_WdogService(const PF09_Type *dev, uint8_t wdogMode)
{
    bool rc = true;
    uint8_t wd_seed = 0xA5U;

    /* Dynamic mode of Wdog */
    if (wdogMode == 1U)
    {
        /* Read dynamic seed */
        rc = PF09_PmicRead(dev, PF09_REG_WD_CTRL1, &wd_seed);
    }

    if (rc)
    {
        /* Write seed into WD_Clear to service the wdog */
        rc = PF09_PmicWrite(dev, PF09_REG_WD_CTRL2, ~wd_seed, 0xFFU);
    }

    /* Return status */
    return rc;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Convert micro voltage to pf09 code                                       */
/*--------------------------------------------------------------------------*/
static bool PF09_ConvertVolts2Code(uint8_t regulator, uint32_t microVolt,
    uint8_t *voltCode)
{
    bool rc = true;
    uint32_t code;

    switch (regulator)
    {
        case PF09_REG_SW1:
            /* Micro volts between 0.5V and 1.35V */
            if ((microVolt >= 500000U) && (microVolt <= 1350000U))
            {
                code = 0x9U + ((microVolt - 500000U) / 6250U);
            }
            else if (microVolt == 1500000U)
            {
                code = 0x9FU;
            }
            /* Micro volts between 1.8V and 2.5V */
            else if ((microVolt >= 1800000U) && (microVolt <= 2500000U))
            {
                code = 0xA0U + ((microVolt - 1800000U) / 12500U);
            }
            /* Micro volts between 2.8V and 3.3V */
            else if ((microVolt >= 2800000U) && (microVolt <= 3300000U))
            {
                code = 0xE0U + ((microVolt - 2800000U) / 25000U);
            }
            else
            {
                rc = false;
            }
            break;
        case PF09_REG_SW2:
        case PF09_REG_SW3:
        case PF09_REG_SW4:
        case PF09_REG_SW5:
            /* 0.3V volts */
            if (microVolt == 300000U)
            {
                code = 0x0U;
            }
            /* Micro volts between 0.45V and 1.35V */
            else if ((microVolt >= 450000U) && (microVolt <= 1350000U))
            {
                code = 0x1U + ((microVolt - 450000U) / 6250U);
            }
            /* 1.5V volts */
            else if (microVolt == 1500000U)
            {
                code = 0x9FU;
            }
            /* Micro volts between 1.8V and 2.5V */
            else if ((microVolt >= 1800000U) && (microVolt <= 2500000U))
            {
                code = 0xA0U + ((microVolt - 1800000U) / 12500U);
            }
            /* Micro volts between 2.8V and 3.3V */
            else if ((microVolt >= 2800000U) && (microVolt <= 3300000U))
            {
                code = 0xE0U + ((microVolt - 2800000U) / 25000U);
            }
            else
            {
                rc = false;
            }
            break;
        case PF09_REG_LDO1:
            /* Micro volts between 0.75V volts and 1.5V */
            if ((microVolt >= 750000U) && (microVolt <= 1500000U))
            {
                code = 0x0U + ((microVolt - 750000U) / 50000U);
            }
            /* Micro volts between 1.8V and 3.3V */
            else if ((microVolt >= 1800000U) && (microVolt <= 3300000U))
            {
                code = 0x10U + ((microVolt - 1800000U) / 100000U);
            }
            else
            {
                rc = false;
            }
            break;
        case PF09_REG_LDO2:
        case PF09_REG_LDO3:
            /* Micro volts between 0.65V and 1.30V */
            if ((microVolt >= 650000U) && (microVolt <= 1300000U))
            {
                code = 0x0U + ((microVolt - 650000U) / 50000U);
            }
            /* Micro volts between 1.4V and 1.5V */
            else if ((microVolt >= 1400000U) && (microVolt <= 1500000U))
            {
                code = 0xEU + ((microVolt - 1400000U) / 100000U);
            }
            /* Micro volts between 1.8V and 3.3V */
            else if ((microVolt >= 1800000U) && (microVolt <= 3300000U))
            {
                code = 0x10U + ((microVolt - 1800000U) / 100000U);
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

    /* Return result, check voltCode */
    if ((rc) && (voltCode != NULL))
    {
        *voltCode = (uint8_t) code;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Convert pf09 code to micro voltage                                       */
/*--------------------------------------------------------------------------*/
static bool PF09_ConvertCode2Volts(uint8_t regulator, uint8_t voltCode,
    uint32_t *microVolt)
{
    bool rc = true;
    uint32_t microV = 0U, code = (uint32_t) voltCode;

    switch (regulator)
    {
        case PF09_REG_SW1:
            /* Volts code between 0x9 and 0x91 */
            if ((code >= 0x9U) && (code <= 0x91U))
            {
                microV = 500000U + ((code - 0x9U) * 6250U);
            }
            else if (code ==0x9FU)
            {
                microV = 1500000U;
            }
            /* Volts code between 0xA0 and 0xD8 */
            else if ((code >= 0xA0U) && (code <= 0xD8U))
            {
                microV = 1800000U + ((code - 0xA0U) * 12500U);
            }
            /* Volts code between 0xE0 and 0xF4 */
            else if ((code >= 0xE0U) && (code <= 0xF4U))
            {
                microV = 2800000U + ((code - 0xE0U) * 25000U);
            }
            else
            {
                rc = false;
            }
            break;
        case PF09_REG_SW2:
        case PF09_REG_SW3:
        case PF09_REG_SW4:
        case PF09_REG_SW5:
            /* Volt code 0  */
            if (code == 0U)
            {
                microV = 300000U;
            }
            /* Volts code between 0x1 and 0x91 */
            else if (code <= 0x91U)
            {
                microV = 450000U + ((code - 0x1U) * 6250U);
            }
            /* Volts code 0x9F */
            else if (code == 0x9FU)
            {
                microV = 1500000U;
            }
            /* Volts code between 0xA0 and 0xD8 */
            else if ((code >= 0xA0U) && (code <= 0xD8U))
            {
                microV = 1800000U + ((code - 0xA0U) * 12500U);
            }
            /* Volts code between 0xE0 and 0xF4  */
            else if ((code >= 0xE0U) && (code <= 0xF4U))
            {
                microV = 2800000U + ((code - 0xE0U) * 25000U);
            }
            else
            {
                rc = false;
            }
            break;
        case PF09_REG_LDO1:
            /* Volts code between 0x0 and 0xF */
            if (code <= 0xFU)
            {
                microV = 750000U + ((code - 0U) * 50000U);
            }
            /* Volts code between 0x10 and 0x1F */
            else if (code <= 0x1FU)
            {
                microV = 1800000U + ((code - 0x10U) * 100000U);
            }
            else
            {
                rc = false;
            }
            break;
        case PF09_REG_LDO2:
        case PF09_REG_LDO3:
            /* Volts code between 0x0 and 0xD*/
            if (code <= 0xDU)
            {
                microV = 650000U + ((code - 0U) * 50000U);
            }
            /* Volts code between 0xE and 0xF */
            else if (code <= 0xFU)
            {
                microV = 1400000U + ((code - 0xEU) * 100000U);
            }
            /* Volts code between 0x10 and 0x1F */
            else if (code <= 0x1FU)
            {
                microV = 1800000U + ((code - 0x10U) * 100000U);
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

    /* Return result, check microVolt */
    if ((rc) && (microVolt != NULL))
    {
        *microVolt = microV;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Find regulator's address                                                 */
/*--------------------------------------------------------------------------*/
static bool PF09_RegulatorAddr(uint8_t regulator, uint8_t state,
    uint8_t *addr)
{
    bool rc = true;

    /* RUN=0; STBY=1 */
    if ((state > PF09_STATE_VSTBY) || (addr == NULL))
    {
        rc = false;
    }
    else
    {
        switch (regulator)
        {
            case PF09_REG_SW1:
            case PF09_REG_SW2:
            case PF09_REG_SW3:
            case PF09_REG_SW4:
            case PF09_REG_SW5:
                /* Each buck regulator block is 5 words long */
                *addr = PF09_REG_SW1_VRUN
                    + ((regulator - PF09_REG_SW1) * 5U)
                    + state;
                break;
            case PF09_REG_LDO1:
            case PF09_REG_LDO2:
            case PF09_REG_LDO3:
                /* Each linear regulator block is 3 words long */
                *addr = PF09_REG_LDO1_RUN
                    + ((regulator - PF09_REG_LDO1) * 3U)
                    + state;
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
/* LPI2C port transmit                                                      */
/*--------------------------------------------------------------------------*/
static status_t PF09_LPI2C_Send(LPI2C_Type *base, uint8_t deviceAddress,
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
static status_t PF09_LPI2C_Receive(LPI2C_Type *base, uint8_t deviceAddress,
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

