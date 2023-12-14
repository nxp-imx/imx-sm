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

#include "fsl_pf53.h"
#include "crc.h"

/* Local Defines */

#define PF53_NUM_REG            0x1AU

#define PF53_REG_DEV_ID         0x00U
#define PF53_REG_REV_ID         0x01U
#define PF53_REG_EMREV_ID       0x02U
#define PF53_REG_PROG_ID        0x03U
#define PF53_REG_CONFIG1        0x04U
#define PF53_REG_INT_STATUS1    0x05U
#define PF53_REG_INT_SENSE1     0x06U
#define PF53_REG_INT_STATUS2    0x07U
#define PF53_REG_INT_SENSE2     0x08U

#define PF53_REG_SW1_VOLT       0x0DU
#define PF53_REG_SW1_STBY_VOLT  0x0EU
#define PF53_REG_SW1_CTRL1      0x0FU
#define PF53_REG_SW1_CTRL2      0x10U
#define PF53_REG_CLK_CTRL       0x11U

#define PF53_REG_RANDOM_CHK     0x14U
#define PF53_REG_RANDOM_GEN     0x15U
#define PF53_REG_WD_CTRL1       0x16U
#define PF53_REG_WD_SEED        0x17U
#define PF53_REG_WD_ANSWER      0x18U
#define PF53_REG_FLT_CNT1       0x19U
#define PF53_REG_FLT_CNT2       0x1AU

/* Local Types */

/* Local Functions */

static bool PF53_ConvertVolts2Code(uint8_t regulator, uint32_t microVolt,
    uint8_t *voltCode);
static bool PF53_ConvertCode2Volts(uint8_t regulator, uint8_t voltCode,
    uint32_t *microVolt);
static status_t PF53_LPI2C_Send(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t subAddressSize, uint8_t *txBuff,
    uint8_t txBuffSize, uint32_t flags);
static status_t PF53_LPI2C_Receive(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t subAddressSize, uint8_t *rxBuff,
    uint8_t rxBuffSize, uint32_t flags);

/* Local Variables */

/* Global Variables */

/*--------------------------------------------------------------------------*/
/* Initialize PMIC                                                          */
/*--------------------------------------------------------------------------*/
bool PF53_Init(const PF53_Type *dev)
{
    uint8_t devId;

    bool rc = PF53_PmicRead(dev, PF53_REG_DEV_ID, &devId);

    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get info                                                                 */
/*--------------------------------------------------------------------------*/
bool PF53_PmicInfoGet(const PF53_Type *dev, uint8_t **info, uint8_t *len)
{
    bool rc = true;
    static uint8_t devId[4];

    if ((info == NULL) || (len == NULL))
    {
        rc = false;
    }
    else
    {
        if (devId[0] == 0U)
        {
            for (uint8_t addr = 0U; addr < 4U; addr++)
            {
                rc = PF53_PmicRead(dev, addr, &devId[addr]);
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
        *len = 4U;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Register write                                                           */
/*--------------------------------------------------------------------------*/
bool PF53_PmicWrite(const PF53_Type *dev, uint8_t regAddr, uint8_t val,
    uint8_t mask)
{
    bool rc = true;

    if (regAddr < PF53_NUM_REG)
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
                rc = PF53_PmicRead(dev, regAddr, &rxBuf);
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
                rc = (PF53_LPI2C_Send(dev->i2cBase, dev->devAddr, regAddr,
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
bool PF53_PmicRead(const PF53_Type *dev, uint8_t regAddr, uint8_t *val)
{
    bool rc = true;

    if (regAddr < PF53_NUM_REG)
    {
        uint8_t data[2];

        if ((dev == NULL) || (val == NULL))
        {
            rc = false;
        }
        else
        {
            /* Read data */
            rc = (PF53_LPI2C_Receive(dev->i2cBase, dev->devAddr, regAddr, 1U,
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
/*  Interrupt status                                                        */
/*--------------------------------------------------------------------------*/
bool PF53_IntStatus(const PF53_Type *dev, uint8_t *mask)
{
    bool rc = false;

    if (mask != NULL)
    {
        rc = PF53_PmicRead(dev, PF53_REG_INT_STATUS1, &mask[0]);
        if (rc)
        {
            rc = PF53_PmicRead(dev, PF53_REG_INT_STATUS2, &mask[1]);
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get regulator info                                                       */
/*--------------------------------------------------------------------------*/
bool PF53_RegulatorInfoGet(uint8_t regulator, PF53_RegInfo *regInfo)
{
    bool rc = true;

    if (regInfo == NULL)
    {
        rc = false;
    }
    else
    {
        /* Check regulator index */
        if (regulator == PF53_REG_SW1)
        {
            /* set min/max/step in microvolts */
            regInfo->minV = 500000U;
            regInfo->maxV = 1200000U;
            regInfo->stepV = 5000U;
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
/* Change Buck regulator run/stby operation mode                            */
/*--------------------------------------------------------------------------*/
bool PF53_SwModeSet(const PF53_Type *dev, uint8_t regulator, uint8_t state,
    uint8_t mode)
{
    bool rc = true;

    if ((state > PF53_STATE_VSTBY) || (mode > PF53_SW_MODE_PWM))
    {
        rc = false;
    }
    else
    {
        /* Check regulator index */
        if (regulator == PF53_REG_SW1)
        {
            uint8_t modeVal = mode << ((state * 2U) + 2U);
            uint8_t modeMask = 3U << ((state * 2U) + 2U);

            rc = PF53_PmicWrite(dev, PF53_REG_SW1_CTRL1,
                modeVal, modeMask);

            /* Wait for write to latch and voltage to ramp */
            SystemTimeDelay(100U);
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get Buck regulator run/stby operation mode                               */
/*--------------------------------------------------------------------------*/
bool PF53_SwModeGet(const PF53_Type *dev, uint8_t regulator, uint8_t state,
    uint8_t *mode)
{
    bool rc = true;

    if ((state > PF53_STATE_VSTBY) || (mode == NULL))
    {
        rc = false;
    }
    else
    {
        /* Check regulator index */
        if (regulator == PF53_REG_SW1)
        {
            /* 0x3 or 0xC for mode bits depending on state */
            uint8_t modeMask = 3U << ((state * 2U) + 2U);

            rc = PF53_PmicRead(dev, PF53_REG_SW1_CTRL1, mode);

            /* Mask and shift the mode bits */
            *mode = ((*mode) & modeMask) >> (2U + (state * 2U));
        }
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set regulator run/standby voltage in micro volts                         */
/*--------------------------------------------------------------------------*/
bool PF53_VoltageSet(const PF53_Type *dev, uint8_t regulator, uint8_t state,
    uint32_t microVolt)
{
    bool rc = true;
    uint8_t voltCode = 0U;

    /* Check regulator index */
    if (regulator == PF53_REG_SW1)
    {
        /* Convert microvolts to code */
        rc = PF53_ConvertVolts2Code(regulator, microVolt, &voltCode);
    }

    if ((state <= PF53_STATE_VSTBY) && (rc == true))
    {
        /* Check regulator index */
        if (regulator == PF53_REG_SW1)
        {
            /* Write 8-bits */
            rc = PF53_PmicWrite(dev, PF53_REG_SW1_VOLT + state,
                voltCode, 0xFFU);

            /* Wait for write to latch and voltage to ramp */
            SystemTimeDelay(100U);
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
/* Get regulator run/standby voltage in micro volts                         */
/*--------------------------------------------------------------------------*/
bool PF53_VoltageGet(const PF53_Type *dev, uint8_t regulator, uint8_t state,
    uint32_t *microVolt)
{
    bool rc = true;
    uint8_t voltCode = 0U;

    /* Check microVolt is not NULL */
    if ((microVolt == NULL) || (state >= PF53_STATE_VSTBY))
    {
        rc = false;
    }
    else
    {
        ; /* Intentional empty else */
    }

    if (rc == true)
    {
        /* Check regulator index */
        if (regulator == PF53_REG_SW1)
        {
            /* Read 8-bits */
            rc = PF53_PmicRead(dev, PF53_REG_SW1_VOLT + state,
                &voltCode);
        }
        else
        {
            rc = false;
        }
    }

    if (rc)
    {
        /* convert code to microvolts */
        rc = PF53_ConvertCode2Volts(regulator, voltCode, microVolt);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get temp                                                                 */
/*--------------------------------------------------------------------------*/
bool PF53_TempGet(const PF53_Type *dev, int32_t *temp)
{
    bool rc = true;
    uint8_t sns;

    rc = PF53_PmicRead(dev, PF53_REG_INT_SENSE2, &sns);
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
/* Watchdog Enable/Disable                                                  */
/*--------------------------------------------------------------------------*/
bool PF53_WdogEnable(const PF53_Type *dev, bool wdogEn)
{
    uint8_t wdEn;
    bool rc = true;

    if (wdogEn == true)
    {
        /* Set WD_EN bit */
        wdEn = 0x01U;
    }
    else
    {
        /* Clear WD_EN */
        wdEn = 0x0U;
    }

    rc = PF53_PmicWrite(dev, PF53_REG_WD_CTRL1, wdEn, 0x01U);

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Service the watchdog in open window                                      */
/*--------------------------------------------------------------------------*/
bool PF53_WdogService(const PF53_Type *dev, uint8_t wdogMode)
{
    bool rc = true;
    uint8_t wd_seed = 0x5BU;

    /* Challenger mode of Wdog */
    if (wdogMode == 1U)
    {
        /* Read dynamic seed */
        rc = PF53_PmicRead(dev, PF53_REG_WD_SEED, &wd_seed);
        /* bitwise inversion of seed */
        wd_seed = ~wd_seed;
    }

    if (rc)
    {
        /* Write seed into WD_Clear to service the wdog */
        rc = PF53_PmicWrite(dev, PF53_REG_WD_ANSWER, wd_seed, 0xFFU);
    }

    /* Return status */
    return rc;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Convert micro voltage to pf53 code                                       */
/*--------------------------------------------------------------------------*/
static bool PF53_ConvertVolts2Code(uint8_t regulator, uint32_t microVolt,
    uint8_t *voltCode)
{
    bool rc = true;
    uint32_t code;

    /* Check regulator index */
    if (regulator == PF53_REG_SW1)
    {
        /* Micro volts between 0.5V and 1.20V */
        if ((microVolt >= 500000U) && (microVolt <= 1200000U))
        {
            code = ((microVolt - 500000U) / 5000U);
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

    /* Return result, check voltCode */
    if ((rc) && (voltCode != NULL))
    {
        *voltCode = (uint8_t) code;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Convert pf53 code to micro voltage                                       */
/*--------------------------------------------------------------------------*/
static bool PF53_ConvertCode2Volts(uint8_t regulator, uint8_t voltCode,
    uint32_t *microVolt)
{
    bool rc = true;
    uint32_t microV = 0U, code = (uint32_t) voltCode;

    /* Check regulator index */
    if (regulator == PF53_REG_SW1)
    {
        /* Volts code between 0x0 and 0x8C */
        if (code <= 0x8CU)
        {
            microV = 500000U + (code * 5000U);
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

    /* Return result, check microVolt */
    if ((rc) && (microVolt != NULL))
    {
        *microVolt = microV;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* LPI2C port transmit                                                      */
/*--------------------------------------------------------------------------*/
static status_t PF53_LPI2C_Send(LPI2C_Type *base, uint8_t deviceAddress,
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
static status_t PF53_LPI2C_Receive(LPI2C_Type *base, uint8_t deviceAddress,
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

