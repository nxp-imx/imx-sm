/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_PCA9451_H
#define FSL_PCA9451_H

#include "fsl_lpi2c.h"

/*!
 * @addtogroup pca9451
 * @{
 * @file
 * @brief
 *
 * Header file containing the API for the PCA9451A PMIC.
 */

/******************************************************************************
 * Definitions
 *****************************************************************************/

/*! PCA9451 driver version. */
#define FSL_PCA9451_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))

/*! PCA9451 device info. */
typedef struct
{
    LPI2C_Type *i2cBase;  /*!< I2C base address */
    uint8_t devAddr;      /*!< Device I2C address */
} PCA9451_Type;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * Initialize a PCA9451A
 *
 * @param[in]     dev        Device info.
 * @param[in]     wdogbResp  WDOG_B config.
 * @param[in]     i2cLtEn    I2C config.
 *
 * @return True if successful.
 */
bool PCA9451_Init(const PCA9451_Type *dev, uint8_t wdogbResp,
    uint8_t i2cLtEn);

/*!
 * Get PCA9451 info
 *
 * @param[in]     dev      Device info.
 * @param[out]    info     Pointer to return pointer to info.
 * @param[out]    len      Number of info bytes.
 *
 * @return True if successful.
 */
bool PCA9451_PmicInfoGet(const PCA9451_Type *dev, uint8_t **info,
    uint8_t *len);

/*!
 * Write a PCA9451 register
 *
 * @param[in]     dev      Device info.
 * @param[in]     regAddr  Register address.
 * @param[in]     val      Value to write.
 * @param[in]     mask     Mask for RMW.
 *
 * @return True if successful.
 */
bool PCA9451_PmicWrite(const PCA9451_Type *dev, uint8_t regAddr, uint8_t val,
    uint8_t mask);

/*!
 * Read a PCA9451 register
 *
 * @param[in]     dev      Device info.
 * @param[in]     regAddr  Register address.
 * @param[out]    val      Pointer to return value.
 *
 * @return True if successful.
 */
bool PCA9451_PmicRead(const PCA9451_Type *dev, uint8_t regAddr, uint8_t *val);

/*!
 * Convert a voltage to a voltage code
 *
 * @param[in]     buckIdx    Buck index.
 * @param[in]     microVolt  voltage in microvolts.
 * @param[out]    voltCode   Pointer to return the voltage code.
 *
 * @return True if successful.
 */
bool PCA9451_BuckDvsVoltage2CodeConvert(uint32_t buckIdx, uint32_t microVolt,
    uint32_t *voltCode);

/*!
 * Set the DVS buck voltage presets
 *
 * @param[in]     dev         Device info.
 * @param[in]     presetEn    Enable presets.
 * @param[in]     b1voltCode  BUCK 1 voltage code.
 * @param[in]     b2voltCode  BUCK 2 voltage code.
 * @param[in]     b3voltCode  BUCK 3 voltage code.
 *
 * Set the voltage preset codes for BUCK 1, 2, & 3.
 *
 * @return True if successful.
 */
bool PCA9451_BuckDvsVoltageSet(const PCA9451_Type *dev, uint8_t presetEn,
    uint8_t b1voltCode, uint8_t b2voltCode, uint8_t b3voltCode);

/*!
 * Convert a voltage code to a voltage
 *
 * @param[in]     buckIdx    Buck index.
 * @param[in]     voltCode   Pointer to return the voltage code.
 * @param[out]    microVolt  voltage in microvolts.
 *
 * @return True if successful.
 */
bool PCA9451_BuckDvsCode2VoltageConvert(uint32_t buckIdx, uint32_t voltCode,
    uint32_t *microVolt);

/*!
 * Get the DVS buck voltage presets
 *
 * @param[in]     dev         Device info.
 * @param[out]    presetEn    Pointer to return the enable presets.
 * @param[out]    b1voltCode  Pointer to return the BUCK 1 voltage code.
 * @param[out]    b2voltCode  Pointer to return the BUCK 2 voltage code.
 * @param[out]    b3voltCode  Pointer to return the BUCK 3 voltage code.
 *
 * Set the voltage preset codes for BUCK 1, 2, & 3.
 *
 * @return True if successful.
 */
bool PCA9451_BuckDvsVoltageGet(const PCA9451_Type *dev, uint8_t *presetEn,
    uint8_t *b1voltCode, uint8_t *b2voltCode, uint8_t *b3voltCode);

/*!
 * Set a buck run voltage code
 *
 * @param[in]     dev        Device info.
 * @param[in]     buckId     Buck index.
 * @param[in]     voltCode   Voltage code.
 *
 * @return True if successful.
 */
bool PCA9451_BuckRunVoltageSet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t voltCode);

/*!
 * Set a buck standby voltage code
 *
 * @param[in]     dev        Device info.
 * @param[in]     buckId     Buck index.
 * @param[in]     voltCode   Voltage code.
 *
 * Only valud for the DVS buck outputs (1-3).
 *
 * @return True if successful.
 */
bool PCA9451_BuckStbyVoltageSet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t voltCode);

/*!
 * Set the DVS buck preset enable
 *
 * @param[in]     dev         Device info.
 * @param[in]     presetEn    Enable presets.
 *
 * Set the preset enable for BUCK 1, 2, & 3.
 *
 * @return True if successful.
 */
bool PCA9451_BuckPresetSet(const PCA9451_Type *dev, uint8_t presetEn);

/*!
 * Configure the I2C level translator enable
 *
 * @param[in]     dev        Device info.
 * @param[in]     i2cLtEn    I2C config.
 *
 * @return True if successful.
 */
bool PCA9451_ConfigI2cLevelTransSet(const PCA9451_Type *dev,
    uint8_t i2cLtEn);

/*!
 * Configure the WDOG_B control
 *
 * @param[in]     dev        Device info.
 * @param[in]     wdogbResp  WDOG_B config.
 *
 * @return True if successful.
 */
bool PCA9451_ConfigWdogbResponseSet(const PCA9451_Type *dev,
    uint8_t wdogbResp);

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/** @} */

#endif /* FSL_PCA9451_H */

