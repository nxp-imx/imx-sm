/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_pcal6408a.h"

/******************************************************************************
 * Definitions
 *****************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "components.pcal6408a"
#endif

/* I2C Bus Expander Registers */
#define BUS_EXP_IN_REG     0x00U
#define BUS_EXP_OUT_REG    0x01U
#define BUS_EXP_POL_REG    0x02U
#define BUS_EXP_CONF_REG   0x03U
#define BUS_EXP_DS0_REG    0x40U
#define BUS_EXP_DS1_REG    0x41U
#define BUS_EXP_LATCH_REG  0x42U
#define BUS_EXP_PULL1_REG  0x43U
#define BUS_EXP_PULL2_REG  0x44U
#define BUS_EXP_MASK_REG   0x45U
#define BUS_EXP_STAT_REG   0x46U
#define BUS_EXP_OD_REG     0x4FU

/*******************************************************************************
 * Variables
 ******************************************************************************/

/******************************************************************************
 * Code
 *****************************************************************************/

static status_t PCAL6408A_Send(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t *txBuff);
static status_t PCAL6408A_Receive(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t *rxBuff);

/*--------------------------------------------------------------------------*/
/* Initializes a PCAL6408A device                                           */
/*--------------------------------------------------------------------------*/
bool PCAL6408A_Init(const PCAL6408A_Type *dev,
    const pcal6408a_config_t *config)
{
    bool rc = true;
    pcal6408a_config_t defConfig;
    PCAL6408A_GetDefaultConfig(&defConfig);

    /* Set output config */
    if (config->outConfig != defConfig.outConfig)
    {
        uint8_t data = config->outConfig;

        rc = PCAL6408A_Send(dev->i2cBase, dev->devAddr, BUS_EXP_OD_REG,
            &data) == kStatus_Success;
    }

    /* Set output drive strength 0 */
    if (rc && (config->drvStrength[0] != defConfig.drvStrength[0]))
    {
        uint8_t data = (uint8_t) config->drvStrength[0];

        rc = PCAL6408A_Send(dev->i2cBase, dev->devAddr, BUS_EXP_DS0_REG,
            &data) == kStatus_Success;
    }

    /* Set output drive strength 1 */
    if (rc && (config->drvStrength[1] != defConfig.drvStrength[1]))
    {
        uint8_t data = (uint8_t) config->drvStrength[1];

        rc = PCAL6408A_Send(dev->i2cBase, dev->devAddr, BUS_EXP_DS1_REG,
            &data) == kStatus_Success;
    }

    /* Set direction */
    if (rc && (config->direction != defConfig.direction))
    {
        uint8_t data = config->direction;

        rc = PCAL6408A_Send(dev->i2cBase, dev->devAddr, BUS_EXP_CONF_REG,
            &data) == kStatus_Success;
    }

    /* Set pull select */
    if (rc && (config->pullSelect != defConfig.pullSelect))
    {
        uint8_t data = config->pullSelect;

        rc = PCAL6408A_Send(dev->i2cBase, dev->devAddr, BUS_EXP_PULL2_REG,
            &data) == kStatus_Success;
    }

    /* Set pull enable */
    if (rc && (config->pullEnable != defConfig.pullEnable))
    {
        uint8_t data = config->pullEnable;

        rc = PCAL6408A_Send(dev->i2cBase, dev->devAddr, BUS_EXP_PULL1_REG,
            &data) == kStatus_Success;
    }

    /* Set polarity */
    if (rc && (config->polarity != defConfig.polarity))
    {
        uint8_t data = config->polarity;

        rc = PCAL6408A_Send(dev->i2cBase, dev->devAddr, BUS_EXP_POL_REG,
            &data) == kStatus_Success;
    }

    /* Set latch */
    if (rc && (config->inputLatch!= defConfig.inputLatch))
    {
        uint8_t data = config->inputLatch;

        rc = PCAL6408A_Send(dev->i2cBase, dev->devAddr, BUS_EXP_LATCH_REG,
            &data) == kStatus_Success;
    }

    return rc;
}

/*--------------------------------------------------------------------------*/
/* De-initializes a PCAL6408A device                                        */
/*--------------------------------------------------------------------------*/
bool PCAL6408A_Deinit(const PCAL6408A_Type *dev)
{
    return PCAL6408A_IntMaskSet(dev, 0xFFU);
}

/*--------------------------------------------------------------------------*/
/* Get the default configuration structure                                  */
/*--------------------------------------------------------------------------*/
void PCAL6408A_GetDefaultConfig(pcal6408a_config_t *config)
{
    config->polarity = 0x00U;        /* No inversion */
    config->direction = 0xFFU;       /* All inputs */
    config->drvStrength[0] = 0xFFU;  /* Full drive */
    config->drvStrength[1] = 0xFFU;  /* Full drive */
    config->inputLatch = 0x00U;      /* Not latched */
    config->pullEnable = 0x00U;      /* No pull */
    config->pullSelect = 0xFFU;      /* 100K pull-up */
    config->outConfig = 0x00U;       /* Push-pull */
}

/*--------------------------------------------------------------------------*/
/* Read a PCAL6408A device's input pins                                     */
/*--------------------------------------------------------------------------*/
bool PCAL6408A_InputGet(const PCAL6408A_Type *dev, uint8_t *inData)
{
    return PCAL6408A_Receive(dev->i2cBase, dev->devAddr, BUS_EXP_IN_REG,
        inData) == kStatus_Success;
}

/*--------------------------------------------------------------------------*/
/* Read a PCAL6408A device's output setting                                 */
/*--------------------------------------------------------------------------*/
bool PCAL6408A_OutputGet(const PCAL6408A_Type *dev, uint8_t *outData)
{
    return PCAL6408A_Receive(dev->i2cBase, dev->devAddr, BUS_EXP_OUT_REG,
        outData) == kStatus_Success;
}

/*--------------------------------------------------------------------------*/
/* Write a PCAL6408A device's output pins                                   */
/*--------------------------------------------------------------------------*/
bool PCAL6408A_OutputSet(const PCAL6408A_Type *dev, uint8_t outData)
{
    uint8_t data = outData;

    return PCAL6408A_Send(dev->i2cBase, dev->devAddr, BUS_EXP_OUT_REG,
        &data) == kStatus_Success;
}

/*--------------------------------------------------------------------------*/
/* Get a PCAL6408A device's interrupt mask                                  */
/*--------------------------------------------------------------------------*/
bool PCAL6408A_IntMaskGet(const PCAL6408A_Type *dev, uint8_t *mask)
{
    return PCAL6408A_Receive(dev->i2cBase, dev->devAddr, BUS_EXP_MASK_REG,
        mask) == kStatus_Success;
}

/*--------------------------------------------------------------------------*/
/* Configure a PCAL6408A device's interrupt mask                            */
/*--------------------------------------------------------------------------*/
bool PCAL6408A_IntMaskSet(const PCAL6408A_Type *dev, uint8_t mask)
{
    uint8_t data = mask;

    return PCAL6408A_Send(dev->i2cBase, dev->devAddr, BUS_EXP_MASK_REG,
        &data) == kStatus_Success;
}

/*--------------------------------------------------------------------------*/
/* Read a PCAL6408A device's interrupt status                               */
/*--------------------------------------------------------------------------*/
bool PCAL6408A_IntStatusGet(const PCAL6408A_Type *dev, uint8_t *status)
{
    return PCAL6408A_Receive(dev->i2cBase, dev->devAddr, BUS_EXP_STAT_REG,
        status) == kStatus_Success;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* LPI2C port transmit                                                      */
/*--------------------------------------------------------------------------*/
static status_t PCAL6408A_Send(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t *txBuff)
{
    lpi2c_master_transfer_t xfer;

    xfer.flags          = 0U;
    xfer.slaveAddress   = deviceAddress;
    xfer.direction      = kLPI2C_Write;
    xfer.subaddress     = subAddress;
    xfer.subaddressSize = 1U;
    xfer.data           = txBuff;
    xfer.dataSize       = 1U;

    return LPI2C_MasterTransferBlocking(base, &xfer);
}

/*--------------------------------------------------------------------------*/
/* LPI2C port receive                                                       */
/*--------------------------------------------------------------------------*/
static status_t PCAL6408A_Receive(LPI2C_Type *base, uint8_t deviceAddress,
    uint32_t subAddress, uint8_t *rxBuff)
{
    lpi2c_master_transfer_t xfer;

    xfer.flags          = 0U;
    xfer.slaveAddress   = deviceAddress;
    xfer.direction      = kLPI2C_Read;
    xfer.subaddress     = subAddress;
    xfer.subaddressSize = 1U;
    xfer.data           = rxBuff;
    xfer.dataSize       = 1U;

    return LPI2C_MasterTransferBlocking(base, &xfer);
}

