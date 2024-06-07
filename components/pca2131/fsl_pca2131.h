/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_PCA2131_H
#define FSL_PCA2131_H

#include "fsl_lpi2c.h"

/*!
 * @addtogroup pca2131
 * @{
 * @file
 * @brief
 *
 * Header file containing the API for the PCA2131 RTC.
 */

/******************************************************************************
 * Definitions
 *****************************************************************************/

/*! PCA2131 driver version. */
#define FSL_PCA2131_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))

/*! PCA2131 device info. */
typedef struct
{
    LPI2C_Type *i2cBase;  /*!< I2C base address */
    uint8_t devAddr;      /*!< Device I2C address */
} PCA2131_Type;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * Initialize a PCA2131.
 *
 * @param[in]     dev        Device info.
 *
 * @return True if successful.
 */
bool PCA2131_Init(const PCA2131_Type *dev);

/*!
 * Write a PCA2131 register.
 *
 * @param[in]     dev      Device info.
 * @param[in]     regAddr  Register address.
 * @param[in]     val      Value to write.
 * @param[in]     mask     Mask for RMW.
 *
 * @return True if successful.
 */
bool PCA2131_RtcWrite(const PCA2131_Type *dev, uint8_t regAddr, uint8_t val,
    uint8_t mask);

/*!
 * Read a PCA2131 register.
 *
 * @param[in]     dev      Device info.
 * @param[in]     regAddr  Register address.
 * @param[out]    val      Pointer to return value.
 *
 * @return True if successful.
 */
bool PCA2131_RtcRead(const PCA2131_Type *dev, uint8_t regAddr, uint8_t *val);

/*!
 * Write the date/time into the PCA2131.
 *
 * @param[in]     dev      Device info.
 * @param[in]     year     Year (0-99).
 * @param[in]     month    Month (1-12).
 * @param[in]     day      Day (1-31).
 * @param[in]     hour     Hour (0-23).
 * @param[in]     min      Minute (0-59).
 * @param[in]     sec      Second (0-59).
 * @param[in]     hun      100ths of seconds (0-99).
 * @param[in]     weekday  Day of the week (0-6).
 *
 * @return True if successful.
 */
bool PCA2131_RtcSet(const PCA2131_Type *dev, uint32_t year, uint32_t month,
    uint32_t day, uint32_t hour, uint32_t min, uint32_t sec, uint32_t hun,
    uint32_t weekday);

/*!
 * Read the date/time from the PCA2131.
 *
 * @param[in]     dev      Device info.
 * @param[in]     year     Pointer to return year (0-99).
 * @param[out]    month    Pointer to return month (1-12).
 * @param[out]    day      Pointer to return day (1-31).
 * @param[out]    hour     Pointer to return hour (0-23).
 * @param[out]    min      Pointer to return minute (0-59).
 * @param[out]    sec      Pointer to return second (0-59).
 * @param[out]    hun      Pointer to return 100ths of seconds (0-99).
 * @param[out]    weekday  Pointer to return day of the week (0-6).
 *
 * @return True if successful.
 */
bool PCA2131_RtcGet(const PCA2131_Type *dev, uint32_t *year, uint32_t *month,
    uint32_t *day, uint32_t *hour, uint32_t *min, uint32_t *sec,
    uint32_t *hun, uint32_t *weekday);

/*!
 * Write the alarm into the PCA2131.
 *
 * @param[in]     dev      Device info.
 * @param[in]     day      Day (1-31).
 * @param[in]     hour     Hour (0-23).
 * @param[in]     min      Minute (0-59).
 * @param[in]     sec      Second (0-59).
 * @param[in]     weekday  Day of the week (0-6).
 *
 * @return True if successful.
 */
bool PCA2131_AlarmSet(const PCA2131_Type *dev, uint32_t day, uint32_t hour,
    uint32_t min, uint32_t sec, uint32_t weekday);

/*!
 * Set the PCA2131 power mode.
 *
 * @param[in]     dev      Device info.
 * @param[in]     mode     Power mode.
 *
 * @return True if successful.
 */
bool PCA2131_PowerModeSet(const PCA2131_Type *dev, uint32_t mode);

/*!
 * Enable/disable the interrupt.
 *
 * @param[in]     dev      Device info.
 * @param[in]     enable   True to enable.
 *
 * @return True if successful.
 */
bool PCA2131_IntEnable(const PCA2131_Type *dev, bool enable);

/*!
 * Clear the alarm.
 *
 * @param[in]     dev      Device info.
 *
 * @return True if successful.
 */
bool PCA2131_IntClear(const PCA2131_Type *dev);

/*!
 * Get the time status.
 *
 * @param[in]     dev      Device info.
 * @param[out]    status   Pointer to return the status of the time.
 *
 * The status is true if the time value has been lost and the
 * clock integrity is not guaranteed. This is usually due to a
 * low battery.
 *
 * @return True if successful.
 */
bool PCA2131_TimeStatusGet(const PCA2131_Type *dev, bool *status);

/*!
 * Get the battery status.
 *
 * @param[in]     dev      Device info.
 * @param[out]    status   Pointer to return the status of the battery.
 *
 * The status is true if the battery is low. Note this cannot be read
 * unless the power mode is set to use the battery.
 *
 * @return True if successful.
 */
bool PCA2131_BattStatusGet(const PCA2131_Type *dev, bool *status);

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/** @} */

#endif /* FSL_PCA2131_H */

