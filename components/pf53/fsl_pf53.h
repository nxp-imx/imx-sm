/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_PF53_H
#define FSL_PF53_H

#include "fsl_lpi2c.h"

/*!
 * @addtogroup pf53
 * @{
 * @file
 * @brief
 *
 * Header file containing the API for the PF53 PMIC.
 */

/******************************************************************************
 * Definitions
 *****************************************************************************/

/*! PF53 driver version. */
#define FSL_PF53_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))

/*! PF53 device info. */
typedef struct
{
    LPI2C_Type *i2cBase;  /*!< I2C base address */
    uint8_t devAddr;      /*!< Device I2C address */
    bool crcEn;           /*!< CRC enabled */
    bool secureEn;        /*!< Secure writes enabled */
} PF53_Type;

/*! PF53 regulator info. */
typedef struct
{
    uint32_t minV;  /*!< Regulator Min Voltage in microvolts */
    uint32_t maxV;  /*!< Regulator Max Voltage in microvolts */
    uint32_t stepV; /*!< Regulator step in microvolts */
} PF53_RegInfo;

/*!
 * @name PF53 regulators
 */
/** @{ */
#define PF53_REG_SW1   1U  /*!< SW1 buck regulator */
/** @} */

/*!
 * @name PF53 Buck regulator operation mode
 */
/** @{ */
#define PF53_SW_MODE_OFF  0U  /*!< Switcher off */
#define PF53_SW_MODE_PWM  3U  /*!< Switcher PWM */
/** @} */

/*!
 * @name PF53 voltage state
 */
/** @{ */
#define PF53_STATE_VRUN   0U  /*!< RUN voltage of regulator */
#define PF53_STATE_VSTBY  1U  /*!< STBY voltage of regulator */
/** @} */

/*! Number of mask words */
#define PF53_MASK_LEN  2U

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * Initialize a PF53
 *
 * @param[in]     dev        Device info.
 *
 * @return True if successful.
 */
bool PF53_Init(const PF53_Type *dev);

/*!
 * Get PF53 info
 *
 * @param[in]     dev      Device info.
 * @param[out]    info     Pointer to return pointer to info.
 * @param[out]    len      Number of info bytes.
 *
 * @return True if successful.
 */
bool PF53_PmicInfoGet(const PF53_Type *dev, uint8_t **info, uint8_t *len);

/*!
 * Write a PF53 register
 *
 * @param[in]     dev      Device info.
 * @param[in]     regAddr  Register address.
 * @param[in]     val      Value to write.
 * @param[in]     mask     Mask for RMW.
 *
 * @return True if successful.
 */
bool PF53_PmicWrite(const PF53_Type *dev, uint8_t regAddr, uint8_t val,
    uint8_t mask);

/*!
 * Read a PF53 register
 *
 * @param[in]     dev      Device info.
 * @param[in]     regAddr  Register address.
 * @param[out]    val      Pointer to return value.
 *
 * @return True if successful.
 */
bool PF53_PmicRead(const PF53_Type *dev, uint8_t regAddr, uint8_t *val);

/*!
 * Get interrupt status
 *
 * @param[in]     dev      Device info.
 * @param[in]     mask     Array of status masks.
 *
 * @return True if successful.
 */
bool PF53_IntStatus(const PF53_Type *dev, uint8_t *mask);

/*!
 * Get PF53 regulator Info
 *
 * @param[in]     regulator  Regulator name SW or LDO.
 * @param[out]    regInfo    Regulator info.
 *
 * @return True if successful.
 */
bool PF53_RegulatorInfoGet(uint8_t regulator, PF53_RegInfo *regInfo);

/*!
 * Set the Buck regulator mode for the state
 *
 * @param[in]     dev        Device info.
 * @param[in]     regulator  Regulator name SW or LDO.
 * @param[in]     state      RUN or STBY voltage.
 * @param[in]     mode       Regulator operation mode.
 *
 * @return True if successful.
 */
bool PF53_SwModeSet(const PF53_Type *dev, uint8_t regulator, uint8_t state,
    uint8_t mode);

/*!
 * Get the Buck regulator mode for the state
 *
 * @param[in]     dev        Device info.
 * @param[in]     regulator  Regulator name SW or LDO.
 * @param[in]     state      RUN or STBY voltage.
 * @param[out]    mode       Pointer to return the operation mode.
 *
 * @return True if successful.
 */
bool PF53_SwModeGet(const PF53_Type *dev, uint8_t regulator, uint8_t state,
    uint8_t *mode);

/*!
 * Get the regulator voltage microVolts
 *
 * @param[in]     dev        Device info.
 * @param[in]     regulator  Regulator name SW or LDO.
 * @param[in]     state      RUN or STBY voltage.
 * @param[out]    microVolt  Pointer to return the regulator microVolts.
 *
 * Get the voltage preset codes for SW1-5, LDO1-3.
 *
 * @return True if successful.
 */
bool PF53_VoltageGet(const PF53_Type *dev, uint8_t regulator, uint8_t state,
    uint32_t *microVolt);

/*!
 * Set the regulator voltage microVolts
 *
 * @param[in]     dev        Device info.
 * @param[in]     regulator  Regulator name SW or LDO.
 * @param[in]     state      RUN or STBY voltage.
 * @param[in]     microVolt  Regulator microVolts.
 *
 * @return True if successful.
 */
bool PF53_VoltageSet(const PF53_Type *dev, uint8_t regulator, uint8_t state,
    uint32_t microVolt);

/*!
 * Get sensor temp
 *
 * @param[in]     dev        Device info.
 * @param[out]    temp       Pointer to return the temp in C.
 *
 * @return True if successful.
 */
bool PF53_TempGet(const PF53_Type *dev, int32_t *temp);

/*!
 * Enable PF53 WatchDog
 *
 * @param[in]     dev       Device info.
 * @param[in]     wdogEn    WDOG Enable.
 *
 * @return True if successful.
 */
bool PF53_WdogEnable(const PF53_Type *dev, bool wdogEn);

/*!
 * Service PF53 Static/Dynamic WatchDog in Open window
 *
 * @param[in]     dev        Device info.
 * @param[in]     wdogMode   Static or Challenger mode of wdog.
 *
 * @return True if successful.
 */
bool PF53_WdogService(const PF53_Type *dev, uint8_t wdogMode);

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/** @} */

#endif /* FSL_PF53_H */

