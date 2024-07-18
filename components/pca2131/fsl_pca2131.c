/*
 * Copyright 2024 NXP
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

#include "fsl_pca2131.h"

/* Local Defines */

#define PCA2131_NUM_REG              0x37U

#define PCA2131_REG_CONTROL_1        0x00U
#define PCA2131_REG_CONTROL_2        0x01U
#define PCA2131_REG_CONTROL_3        0x02U
#define PCA2131_REG_CONTROL_4        0x03U
#define PCA2131_REG_CONTROL_5        0x04U
#define PCA2131_REG_SR_RESET         0x05U
#define PCA2131_REG_100TH_SECONDS    0x06U
#define PCA2131_REG_SECONDS          0x07U
#define PCA2131_REG_MINUTES          0x08U
#define PCA2131_REG_HOURS            0x09U
#define PCA2131_REG_DAYS             0x0AU
#define PCA2131_REG_WEEKDAYS         0x0BU
#define PCA2131_REG_MONTHS           0x0CU
#define PCA2131_REG_YEARS            0x0DU
#define PCA2131_REG_SECONDS_ALARM    0x0EU
#define PCA2131_REG_MINUTES_ALARM    0x0FU
#define PCA2131_REG_HOURS_ALARM      0x10U
#define PCA2131_REG_DAYS_ALARM       0x11U
#define PCA2131_REG_WEEKDAYS_ALARM   0x12U
#define PCA2131_REG_CLKOUT_CTL       0x13U
#define PCA2131_REG_TIMESTP_CTL1     0x14U
#define PCA2131_REG_SEC_TIMESTP1     0x15U
#define PCA2131_REG_MIN_TIMESTP1     0x16U
#define PCA2131_REG_HOUR_TIMESTP1    0x17U
#define PCA2131_REG_DAY_TIMESTP1     0x18U
#define PCA2131_REG_MON_TIMESTP1     0x19U
#define PCA2131_REG_YEAR_TIMESTP1    0x1AU
#define PCA2131_REG_TIMESTP_CTL2     0x1BU
#define PCA2131_REG_SEC_TIMESTP2     0x1CU
#define PCA2131_REG_MIN_TIMESTP2     0x1DU
#define PCA2131_REG_HOUR_TIMESTP2    0x1EU
#define PCA2131_REG_DAY_TIMESTP2     0x1FU
#define PCA2131_REG_MON_TIMESTP2     0x20U
#define PCA2131_REG_YEAR_TIMESTP2    0x21U
#define PCA2131_REG_TIMESTP_CTL3     0x22U
#define PCA2131_REG_SEC_TIMESTP3     0x23U
#define PCA2131_REG_MIN_TIMESTP3     0x24U
#define PCA2131_REG_HOUR_TIMESTP3    0x25U
#define PCA2131_REG_DAY_TIMESTP3     0x26U
#define PCA2131_REG_MON_TIMESTP3     0x27U
#define PCA2131_REG_YEAR_TIMESTP3    0x28U
#define PCA2131_REG_TIMESTP_CTL4     0x29U
#define PCA2131_REG_SEC_TIMESTP4     0x2AU
#define PCA2131_REG_MIN_TIMESTP4     0x2BU
#define PCA2131_REG_HOUR_TIMESTP4    0x2CU
#define PCA2131_REG_DAY_TIMESTP4     0x2DU
#define PCA2131_REG_MON_TIMESTP4     0x2EU
#define PCA2131_REG_YEAR_TIMESTP4    0x2FU
#define PCA2131_REG_AGING_OFFSET     0x30U
#define PCA2131_REG_INT_A_MASK1      0x31U
#define PCA2131_REG_INT_A_MASK2      0x32U
#define PCA2131_REG_INT_B_MASK1      0x33U
#define PCA2131_REG_INT_B_MASK2      0x34U
#define PCA2131_REG_WATCHDG_TIM_CTL  0x35U
#define PCA2131_REG_WATCHDG_TIM_VAL  0x36U

#define PCA2131_SECONDS_OSF          0x80U
#define PCA2131_CONTROL_3_BLF        0x04U

/* Local Types */

/* Local Functions */

static uint8_t PCA2131_Dec2Bcd(uint32_t dec);
static uint32_t PCA2131_Bcd2Dec(uint8_t bcd);
static status_t PCA2131_LPI2C_Send(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t subAddressSize, uint8_t *txBuff,
    uint8_t txBuffSize, uint32_t flags);
static status_t PCA2131_LPI2C_Receive(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t subAddressSize, uint8_t *rxBuff,
    uint8_t rxBuffSize, uint32_t flags);

/* Local Variables */

/*--------------------------------------------------------------------------*/
/* Initialize RTC                                                           */
/*--------------------------------------------------------------------------*/
bool PCA2131_Init(const PCA2131_Type *dev)
{
    return true;
}

/*--------------------------------------------------------------------------*/
/* Registers write                                                          */
/*--------------------------------------------------------------------------*/
bool PCA2131_RtcWrite(const PCA2131_Type *dev, uint8_t regAddr, uint8_t len,
    uint8_t *val)
{
    bool rc = true;

    if (regAddr < PCA2131_NUM_REG)
    {
        if ((dev == NULL) || (val == NULL))
        {
            rc = false;
        }
        else
        {
            /* Write data */
            rc = (PCA2131_LPI2C_Send(dev->i2cBase, dev->devAddr,
                regAddr, 1U, val, len, 0U) == kStatus_Success);
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
/* Registers read                                                           */
/*--------------------------------------------------------------------------*/
bool PCA2131_RtcRead(const PCA2131_Type *dev, uint8_t regAddr, uint8_t len,
    uint8_t *val)
{
    bool rc = true;

    if (regAddr < PCA2131_NUM_REG)
    {
        if ((dev == NULL) || (val == NULL))
        {
            rc = false;
        }
        else
        {
            /* Read data */
            rc = (PCA2131_LPI2C_Receive(dev->i2cBase, dev->devAddr,
                regAddr, 1U, val, len, 0U) == kStatus_Success);
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
/* Register write one byte                                                  */
/*--------------------------------------------------------------------------*/
bool PCA2131_RtcWriteOne(const PCA2131_Type *dev, uint8_t regAddr,
    uint8_t val, uint8_t mask)
{
    bool rc = true;

    if (regAddr < PCA2131_NUM_REG)
    {
        if (dev == NULL)
        {
            rc = false;
        }
        else
        {
            uint8_t data = val;

            /* If not updating entire register, perform a read-mod-write */
            if (mask != 0xFFU)
            {
                /* Read data */
                rc = PCA2131_RtcRead(dev, regAddr, 1U, &data);
                if (rc)
                {
                    data = (val & mask) | (data & (~mask));
                }
            }

            /* Write data */
            if (rc)
            {
                rc = (PCA2131_LPI2C_Send(dev->i2cBase, dev->devAddr,
                    regAddr, 1U, &data, 1U, 0U) == kStatus_Success);
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
/*  Write RTC time                                                          */
/*--------------------------------------------------------------------------*/
bool PCA2131_RtcSet(const PCA2131_Type *dev, uint32_t year, uint32_t month,
    uint32_t day, uint32_t hour, uint32_t min, uint32_t sec, uint32_t hun,
    uint32_t weekday)
{
    bool rc;

    /* Stop timer */
    rc = PCA2131_RtcWriteOne(dev, PCA2131_REG_CONTROL_1, 0x20U, 0x20U);

    if (rc)
    {
        uint8_t txBuf[8];

        /* Convert to BCD */
        txBuf[0] = PCA2131_Dec2Bcd(hun);
        txBuf[1] = PCA2131_Dec2Bcd(sec);
        txBuf[2] = PCA2131_Dec2Bcd(min);
        txBuf[3] = PCA2131_Dec2Bcd(hour);
        txBuf[4] = PCA2131_Dec2Bcd(day);
        txBuf[5] = PCA2131_Dec2Bcd(weekday);
        txBuf[6] = PCA2131_Dec2Bcd(month);
        txBuf[7] = PCA2131_Dec2Bcd(year);

        /* Set all date/time values */
        rc = PCA2131_RtcWrite(dev, PCA2131_REG_100TH_SECONDS, 8U, txBuf);
    }

    if (rc)
    {
        /* Start timer */
        rc = PCA2131_RtcWriteOne(dev, PCA2131_REG_CONTROL_1, 0x00U, 0x20U);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/*  Read RTC time                                                           */
/*--------------------------------------------------------------------------*/
bool PCA2131_RtcGet(const PCA2131_Type *dev, uint32_t *year, uint32_t *month,
    uint32_t *day, uint32_t *hour, uint32_t *min, uint32_t *sec,
    uint32_t *hun, uint32_t *weekday)
{
    bool rc;
    uint8_t rxBuf[8] = { 0 };

    /* Read all date/time values */
    rc = PCA2131_RtcRead(dev, PCA2131_REG_100TH_SECONDS, 8U, rxBuf);

    if (rc)
    {
        /* Clear OSF */
        rxBuf[1] &= (uint8_t) ~PCA2131_SECONDS_OSF;

        /* Convert from BCD */
        *hun = PCA2131_Bcd2Dec(rxBuf[0]);
        *sec = PCA2131_Bcd2Dec(rxBuf[1]);
        *min = PCA2131_Bcd2Dec(rxBuf[2]);
        *hour = PCA2131_Bcd2Dec(rxBuf[3]);
        *day = PCA2131_Bcd2Dec(rxBuf[4]);
        *weekday = PCA2131_Bcd2Dec(rxBuf[5]);
        *month = PCA2131_Bcd2Dec(rxBuf[6]);
        *year = PCA2131_Bcd2Dec(rxBuf[7]);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/*  Write RTC alarm                                                         */
/*--------------------------------------------------------------------------*/
bool PCA2131_AlarmSet(const PCA2131_Type *dev, uint32_t day, uint32_t hour,
    uint32_t min, uint32_t sec, uint32_t weekday)
{
    bool rc;

    /* Disable and clear alarm */
    rc = PCA2131_IntEnable(dev, false);

    if (rc)
    {
        uint8_t txBuf[5];

        /* Convert to BCD */
        txBuf[0] = PCA2131_Dec2Bcd(sec);
        txBuf[1] = PCA2131_Dec2Bcd(min);
        txBuf[2] = PCA2131_Dec2Bcd(hour);
        txBuf[3] = PCA2131_Dec2Bcd(day);
        txBuf[4] = PCA2131_Dec2Bcd(weekday);

        /* Set all alarm date/time values */
        rc = PCA2131_RtcWrite(dev, PCA2131_REG_SECONDS_ALARM, 5U, txBuf);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/*  Set power mode                                                          */
/*--------------------------------------------------------------------------*/
bool PCA2131_PowerModeSet(const PCA2131_Type *dev, uint32_t mode)
{
    bool rc;

    /* Set mode */
    rc = PCA2131_RtcWriteOne(dev, PCA2131_REG_CONTROL_3,
        ((uint8_t) mode) << 5U, 0xE0U);

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/*  Configure interrupt enable                                              */
/*--------------------------------------------------------------------------*/
bool PCA2131_IntEnable(const PCA2131_Type *dev, bool enable)
{
    bool rc;
    uint8_t val = enable ? 0xFFU : 0x00U;

    /* Set AIE */
    rc = PCA2131_RtcWriteOne(dev, PCA2131_REG_CONTROL_2, val, 0x02U);

    /* Set mask */
    if (rc)
    {
        rc = PCA2131_RtcWriteOne(dev, PCA2131_REG_INT_A_MASK1, ~val, 0x04U);
    }

    /* Clear interrupt if disable */
    if (rc && !enable)
    {
        rc = PCA2131_RtcWriteOne(dev, PCA2131_REG_CONTROL_2, 0U, 0x10U);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/*  Clear interrupt                                                         */
/*--------------------------------------------------------------------------*/
bool PCA2131_IntClear(const PCA2131_Type *dev)
{
    bool rc;

    /* Clear interrupt */
    rc = PCA2131_RtcWriteOne(dev, PCA2131_REG_CONTROL_2, 0U, 0x10U);

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/*  Get status of the time                                                  */
/*--------------------------------------------------------------------------*/
bool PCA2131_TimeStatusGet(const PCA2131_Type *dev, bool *status)
{
    bool rc;
    uint8_t val;

    /* Set mode */
    rc = PCA2131_RtcRead(dev, PCA2131_REG_SECONDS, 1U, &val);

    /* Return status */
    if (rc)
    {
        *status = ((val & PCA2131_SECONDS_OSF) != 0U);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/*  Get status of the battery                                               */
/*--------------------------------------------------------------------------*/
bool PCA2131_BattStatusGet(const PCA2131_Type *dev, bool *status)
{
    bool rc;
    uint8_t val;

    /* Set mode */
    rc = PCA2131_RtcRead(dev, PCA2131_REG_CONTROL_3, 1U, &val);

    /* Return status */
    if (rc)
    {
        *status = ((val & PCA2131_CONTROL_3_BLF) != 0U);
    }

    /* Return status */
    return rc;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Convert decimal to BCD                                                   */
/*--------------------------------------------------------------------------*/
static uint8_t PCA2131_Dec2Bcd(uint32_t dec)
{
    uint32_t mod100 = dec % 100U;
    uint8_t dec8 = (uint8_t) mod100;

    return (((dec8 / 10U) << 4U) | (dec8 % 10U));
}

/*--------------------------------------------------------------------------*/
/* Convert BCD to decimal                                                   */
/*--------------------------------------------------------------------------*/
static uint32_t PCA2131_Bcd2Dec(uint8_t bcd)
{
    uint32_t bcd32 = (uint32_t) bcd;

    return (((bcd32 >> 4U) & 0x0FU) * 10U) + (bcd32 & 0x0FU);
}

/*--------------------------------------------------------------------------*/
/* LPI2C port transmit                                                      */
/*--------------------------------------------------------------------------*/
static status_t PCA2131_LPI2C_Send(LPI2C_Type *base, uint8_t deviceAddress,
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
static status_t PCA2131_LPI2C_Receive(LPI2C_Type *base, uint8_t deviceAddress,
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

