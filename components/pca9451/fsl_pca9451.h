/*
 * Copyright 2023, 2026 NXP
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
 * Header file containing the API for the PCA9451 PMIC.
 */

/******************************************************************************
 * Definitions
 *****************************************************************************/

/*! PCA9451 driver version. */
#define FSL_PCA9451_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))

/*! PCA9451 device ID length. */
#define PCA9451_ID_LEN  1U

/*! Buckout limit register offset. */
#define PCA9451_BUCKOUT_LIMIT_OFFSET 0x0CU

/*! PCA9451 device info. */
typedef struct
{
    LPI2C_Type *i2cBase;      /*!< I2C base address */
    uint8_t devAddr;          /*!< Device I2C address */
    uint8_t id[PCA9451_ID_LEN];  /*!< Id buffer */
} PCA9451_Type;

/*! PCA9451 regulator info. */
typedef struct
{
    uint32_t minV;  /*!< Regulator Min Voltage in microvolts */
    uint32_t maxV;  /*!< Regulator Max Voltage in microvolts */
    uint32_t stepV; /*!< Regulator step in microvolts */
} PCA9451_RegInfo;

/*!
 * @name PCA9451 regulators
 */
/** @{ */
#define PCA9451_REG_SW1                1U  /*!< SW1 (dual-phase with SW3) */
#define PCA9451_REG_SW2                2U  /*!< SW2 */
#define PCA9451_REG_SW3                3U  /*!< SW3 (dual-phase with SW1) */
#define PCA9451_REG_SW4                4U  /*!< SW4 */
#define PCA9451_REG_SW5                5U  /*!< SW5 */
#define PCA9451_REG_SW6                6U  /*!< SW6 */
#define PCA9451_REG_LDO1               7U  /*!< LDO1 */
#define PCA9451_REG_LDO3               8U  /*!< LDO1 */
#define PCA9451_REG_LDO4               9U  /*!< LDO4 */
#define PCA9451_REG_LDO5_L             10U /*!< LDO5_L */
#define PCA9451_REG_LDO5_H             11U /*!< LDO5_H */
#define PCA9451_REG_LDSW               12U /*!< LDSW */
/** @} */

/*!
 * @name PCA9451 registers
 */
/** @{ */
#define PCA9451_NUM_REG                0x2FU /*!< PCA9451 num registers */
/** @} */

/*!
 * @name PCA9451 registers
 */
/** @{ */
#define PCA9451_REG_DEV_ID             0x00U /*!< PCA9451 device id reg */
#define PCA9451_REG_INT1               0x01U /*!< PCA9451 interrupt stat reg */
#define PCA9451_REG_INT1_MSK           0x02U /*!< PCA9451 interrupt mask reg */
#define PCA9451_REG_STATUS1            0x03U /*!< PCA9451 status1 reg */
#define PCA9451_REG_STATUS2            0x04U /*!< PCA9451 status2 reg */
#define PCA9451_REG_PWRON_STAT         0x05U /*!< PCA9451 power on stat reg */
#define PCA9451_REG_SW_RST             0x06U /*!< PCA9451 sw reset reg */
#define PCA9451_REG_PWR_CTRL           0x07U /*!< PCA9451 power control reg */
#define PCA9451_REG_RESET_CTRL         0x08U /*!< PCA9451 reset control reg */
#define PCA9451_REG_CONFIG1            0x09U /*!< PCA9451 config1 reg */
#define PCA9451_REG_CONFIG2            0x0AU /*!< PCA9451 config2 reg */
#define PCA9451_REG_BUCK123_DVS        0x0CU /*!< PCA9451 BUCK1OUT_DVS reg */
#define PCA9451_REG_BUCK1OUT_LIMIT     0x0DU /*!< PCA9451 BUCK1OUT_LIMIT reg */
#define PCA9451_REG_BUCK2OUT_LIMIT     0x0EU /*!< PCA9451 BUCK2OUT_LIMIT reg */
#define PCA9451_REG_BUCK3OUT_LIMIT     0x0FU /*!< PCA9451 BUCK3OUT_LIMIT reg */
#define PCA9451_REG_BUCK1CTRL          0x10U /*!< PCA9451 BUCK1CTRL reg */
#define PCA9451_REG_BUCK1OUT_DVS0      0x11U /*!< PCA9451 BUCK1OUT_DVS0 reg */
#define PCA9451_REG_BUCK1OUT_DVS1      0x12U /*!< PCA9451 BUCK1OUT_DVS1 reg */
#define PCA9451_REG_BUCK2CTRL          0x13U /*!< PCA9451 BUCK2CTRL reg */
#define PCA9451_REG_BUCK2OUT_DVS0      0x14U /*!< PCA9451 BUCK2OUT_DVS0 reg */
#define PCA9451_REG_BUCK2OUT_DVS1      0x15U /*!< PCA9451 BUCK2OUT_DVS1 reg */
#define PCA9451_REG_BUCK3CTRL          0x16U /*!< PCA9451 BUCK3CTRL reg */
#define PCA9451_REG_BUCK3OUT_DVS0      0x17U /*!< PCA9451 BUCK3OUT_DVS0 reg */
#define PCA9451_REG_BUCK3OUT_DVS1      0x18U /*!< PCA9451 BUCK3OUT_DVS1 reg */
#define PCA9451_REG_BUCK4CTRL          0x19U /*!< PCA9451 BUCK4CTRL reg */
#define PCA9451_REG_BUCK4OUT           0x1AU /*!< PCA9451 BUCK4OUT reg */
#define PCA9451_REG_BUCK5CTRL          0x1BU /*!< PCA9451 BUCK5CTRL reg */
#define PCA9451_REG_BUCK5OUT           0x1CU /*!< PCA9451 BUCK5OUT reg */
#define PCA9451_REG_BUCK6CTRL          0x1DU /*!< PCA9451 BUCK6CTRL reg */
#define PCA9451_REG_BUCK6OUT           0x1EU /*!< PCA9451 BUCK6OUT reg */
#define PCA9451_REG_LDO_AD_CTRL        0x20U /*!< PCA9451 LDO_AD_CTRL reg */
#define PCA9451_REG_LDO1CTRL           0x21U /*!< PCA9451 LDO1CTRL reg */
#define PCA9451_REG_LDO3CTRL           0x23U /*!< PCA9451 LDO3CTRL reg */
#define PCA9451_REG_LDO4CTRL           0x24U /*!< PCA9451 LDO4CTRL reg */
#define PCA9451_REG_LDO5CTRL_L         0x25U /*!< PCA9451 LDO5CTRL_L reg */
#define PCA9451_REG_LDO5CTRL_H         0x26U /*!< PCA9451 LDO5CTRL_H reg */
#define PCA9451_REG_LOADSW_CTRL        0x2AU /*!< PCA9451 LOADSW_CTRL reg */
#define PCA9451_REG_VRFLT1_STS         0x2BU /*!< PCA9451 VRFLT1_STS reg */
#define PCA9451_REG_VRFLT2_STS         0x2CU /*!< PCA9451 VRFLT2_STS reg */
#define PCA9451_REG_VRFLT1_MASK        0x2DU /*!< PCA9451 VRFLT1_MASK reg */
#define PCA9451_REG_VRFLT2_MASK        0x2EU /*!< PCA9451 VRFLT2_MASK reg */
/** @} */

/*!
 * @name PCA9451 voltage state
 */
/** @{ */
/*! RUN voltage (DVS0 for SW1-3, direct for others) */
#define PCA9451_STATE_RUN   0U
/*! STANDBY voltage (DVS1, only SW1-3 support this) */
#define PCA9451_STATE_STBY  1U
/** @} */

/*!
 * @name I2C level translator enable control (I2C_LVL_TRANS_EN)
 */
/** @{ */
/*! Forcedly disable */
#define PCA9451_I2C_LVL_TRANS_DISABLE            0x0
/*! Enable only in STANDBY and RUN modes */
#define PCA9451_I2C_LVL_TRANS_STBY_RUN_ENABLE    0x1
/*! Enable only in RUN mode */
#define PCA9451_I2C_LVL_TRANS_RUN_ONLY_ENABLE    0x2
/*! Forcedly enable */
#define PCA9451_I2C_LVL_TRANS_FORCE_ENABLE       0x3
/** @} */

/*!
 *
 * @name PCA9451 switcher enable modes (Bx_ENMODE[1:0])
 */
/** @{ */
/*! Switcher regulator OFF */
#define PCA9451_SW_MODE_OFF   0U
/*! Switcher ON when PMIC_ON_REQ = H */
#define PCA9451_SW_MODE_ON    1U
/*! Switcher ON when PMIC_ON_REQ=H && PMIC_STBY_REQ=L */
#define PCA9451_SW_MODE_STBY  2U
/** @} */

/*!
 *
 * @name PCA9451 LDSW regulator enable modes (SWEN[1:0])
 */
/** @{ */
/*! Switcher regulator OFF */
#define PCA9451_LDSW_MODE_OFF       0U
/*! Enable by SW_EN */
#define PCA9451_LDSW_MODE_SW_PIN    1U
/*! LDSW forced enabled */
#define PCA9451_LDSW_MODE_FORCE_EN  3U
/** @} */
/*!

 * @name DVS control selection (DVS_CTRL)
 */
/** @{ */
/*! BUCK2VOUT DVS0 register determines BUCK voltage regardless of
 *   PMIC_STBY_REQ */
#define PCA9451_DVS_CTRL_BY_REGISTER      0
/*! DVS control through PMIC_STBY_REQ */
#define PCA9451_DVS_CTRL_BY_PMIC_STBY_REQ 1
/** @} */

/*!
 * @name BUCK123 output voltage selection (BUCK123_VSEL)
 */
/** @{ */
/*! BUCK voltage is determined by BUCKxOUT_DVS0 or BUCKxOUT_DVS1 */
#define PCA9451_BUCK123_VOLT_BY_DVS0_DVS1   0
/*! BUCK voltage is determined by Bx_DVS_PRESET bits */
#define PCA9451_BUCK123_VOLT_BY_PRESET      1
/** @} */

/*!
 * @name WDOG_B reset behavior configuration (WDOG_RST_CFG)
 */
/** @{ */
/*! WDOG_B reset is disabled */
#define PCA9451_WDOG_RST_DISABLED        0x0
/*! Warm Reset, POR_B pin is asserted LOW for 20 ms */
#define PCA9451_WDOG_RST_WARM            0x1
/*! Cold Reset, all voltage regulators are recycled except LDO1 */
#define PCA9451_WDOG_RST_COLD_KEEP_LDO1  0x2
/*! Cold Reset, all voltage regulators are recycled */
#define PCA9451_WDOG_RST_COLD_ALL        0x3
/** @} */

/*!
 * @name PMIC status flags mask
 */
/** @{ */
/*! Power ON triggered by PMIC_ON_REQ */
#define PCA9451_PMIC_STATUS_PWRON_MASK     (1U << 7)
/*! Cold reset caused by WDOG_B pin */
#define PCA9451_PMIC_STATUS_WDOG_MASK      (1U << 6)
/*! Cold reset caused by SW_RST bit */
#define PCA9451_PMIC_STATUS_SW_RST_MASK    (1U << 5)
/*! Cold reset caused by PMIC_RST_B */
#define PCA9451_PMIC_STATUS_PMIC_RST_MASK  (1U << 4)
/** @} */

/*!
 * @name PCA9451 LDO enable modes (ENMODE[7:6])
 */
/** @{ */
/*! LDO OFF */
#define PCA9451_LDO_MODE_OFF      0U
/*! LDO ON when PMIC_ON_REQ = H */
#define PCA9451_LDO_MODE_ON       1U
/*! LDO ON when PMIC_ON_REQ=H && PMIC_STBY_REQ=L */
#define PCA9451_LDO_MODE_STBY     2U
/*! LDO always ON */
#define PCA9451_LDO_MODE_ALWAYS   3U
/** @} */

/*!
 * @name PCA9451 SW_RST values (0x06)
 */
/** @{ */
/*! No action */
#define PCA9451_SW_RST_NONE          0x00U
/*! Reset all registers to default */
#define PCA9451_SW_RST_REGS          0x05U
/*! Cold reset, recycle all except LDO1 */
#define PCA9451_SW_RST_COLD_NO_LDO1  0x14U
/*! Warm reset, toggle POR_B 20 ms */
#define PCA9451_SW_RST_WARM          0x35U
/*! Cold reset, recycle all regulators */
#define PCA9451_SW_RST_COLD          0x64U
/** @} */

/*!
 * @name PCA9451 INT1 mask bits (register 0x01 / 0x02)
 */
/** @{ */
#define PCA9451_INT1_MASK           0xDFU  /*!< PCA9451 interrupt reg mask */
#define PCA9451_INT1_PWRON_MSK      0x80U  /*!< PMIC_ON_REQ status change */
#define PCA9451_INT1_WDOGB_MSK      0x40U  /*!< WDOG_B pin status change */
#define PCA9451_INT1_VR_FLT1_MSK    0x10U  /*!< VR Fault group 1 */
#define PCA9451_INT1_VR_FLT2_MSK    0x08U  /*!< VR Fault group 2 */
#define PCA9451_INT1_LOWVSYS_MSK    0x04U  /*!< Low VSYS voltage */
#define PCA9451_INT1_THERM_105_MSK  0x02U  /*!< Die temp 105 °C threshold */
#define PCA9451_INT1_THERM_125_MSK  0x01U  /*!< Die temp 125 °C threshold */
/** @} */

/*!
 * @name PCA9451 VRFLT1_STS fault bits (register 0x2B)
 */
/** @{ */
#define PCA9451_FLT1_SW_OCP  0x80U  /*!< Load switch OCP */
#define PCA9451_FLT1_SW6     0x20U  /*!< SW6 fault */
#define PCA9451_FLT1_SW5     0x10U  /*!< SW5 fault */
#define PCA9451_FLT1_SW4     0x08U  /*!< SW4 fault */
#define PCA9451_FLT1_SW3     0x04U  /*!< SW3 fault */
#define PCA9451_FLT1_SW2     0x02U  /*!< SW2 fault */
#define PCA9451_FLT1_SW1     0x01U  /*!< SW1 fault */
/** @} */

/*!
 * @name PCA9451 VRFLT2_STS fault bits (register 0x2C)
 */
/** @{ */
#define PCA9451_FLT2_LDO5   0x10U  /*!< LDO5 fault */
#define PCA9451_FLT2_LDO4   0x08U  /*!< LDO4 fault */
#define PCA9451_FLT2_LDO1   0x01U  /*!< LDO1 fault */
/** @} */

/*!
 * @name PCA9451 temperature thresholds (STATUS1 bits)
 */
/** @{ */
#define PCA9451_TEMP_BELOW_105  105  /*!< Die temp below 105 °C */
#define PCA9451_TEMP_AT_105     106  /*!< Die temp at or above 105 °C */
#define PCA9451_TEMP_below_125  125  /*!< Die temp at or below 125 °C */
#define PCA9451_TEMP_AT_125     126  /*!< Die temp at or above 125 °C */
#define PCA9451_TEMP_MAX_VALID  155  /*!< Die temp at 155 °C */
/** @} */

/*! Number of INT1 interrupt bits */
#define PCA9451_INT1_LEN  1U

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * Initialize a PCA9451
 *
 * @param[in]     dev        Device info.
 * @param[in]     wdogbResp  WDOG_B config (WDOG_B_CFG bits).
 * @param[in]     i2cLtEn    I2C level translator enable config.
 *
 * @return True if successful.
 */
bool PCA9451_Init(PCA9451_Type *dev, uint8_t wdogbResp,
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
bool PCA9451_PmicInfoGet(PCA9451_Type *dev, uint8_t **info,
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
 * Get PCA9451 regulator info (min/max/step voltages)
 *
 * @param[in]     regulator  Regulator index (PCA9451_REG_SWx / PCA9451_REG_LDOx).
 * @param[out]    regInfo    Pointer to regulator info struct.
 *
 * @return True if successful.
 */
bool PCA9451_RegulatorInfoGet(uint8_t regulator, PCA9451_RegInfo *regInfo);

/*!
 * Set buck enable mode
 *
 * @param[in]     dev        Device info.
 * @param[in]     buckId     Switcher regulator index (1-6).
 * @param[in]     mode       Enable mode (PCA9451_SW_MODE_OFF/ON/STBY).
 *
 * @return True if successful.
 */
bool PCA9451_SWModeSet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t mode);

/*!
 * Get buck enable mode
 *
 * @param[in]     dev        Device info.
 * @param[in]     buckId     Switcher regulator index (1-6).
 * @param[out]    mode       Pointer to return the enable mode.
 *
 * @return True if successful.
 */
bool PCA9451_SWModeGet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t *mode);

/*!
 * Set buck DVS mode
 *
 * @param[in]     dev        Device info.
 * @param[in]     buckId     Switcher regulator index (1-3).
 * @param[in]     mode       DVS mode (DVS_CTRL_BY_REGISTER/DVS_CTRL_BY_PMIC_STBY_REQ).
 *
 * @return True if successful.
 */
bool PCA9451_DVSModeSet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t mode);

/*!
 * Get buck dvs mode
 *
 * @param[in]     dev        Device info.
 * @param[in]     buckId     Switcher regulator index (1-3).
 * @param[out]    mode       Pointer to return the DVS mode.
 *
 * @return True if successful.
 */
bool PCA9451_DVSModeGet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t *mode);

/*!
 * Set BUCK Output Limit voltage
 *
 * @param[in] dev            Device info.
 * @param[in] buckId         Switcher regulator index (1-3).
 * @param[in] microVolt      Desired voltage in microvolts.
 *
 * @return True if successful.
 */
bool PCA9451_BuckLimitSet(const PCA9451_Type *dev, uint8_t buckId,
    uint32_t microVolt);

/*!
 * Get BUCK Output Limit voltage
 *
 * @param[in]  dev          Device info.
 * @param[in]  buckId       Switcher regulator index (1-3).
 * @param[out] microVolt    Pointer to store voltage in microvolts.
 *
 * @return True if successful.
 */
bool PCA9451_BuckLimitGet(const PCA9451_Type *dev, uint8_t buckId,
    uint32_t *microVolt);
/*!
 * Enable or disable an LDO regulator
 *
 * @param[in]     dev        Device info.
 * @param[in]     ldoId      LDO regulator index (PCA9451_REG_LDO1/4/5).
 * @param[in]     mode       Enable mode (PCA9451_LDO_MODE_OFF/ON/STBY/ALWAYS).
 *
 * @return True if successful.
 */
bool PCA9451_LdoEnable(const PCA9451_Type *dev, uint8_t ldoId, uint8_t mode);

/*!
 * Enable or disable an LDSW regulator
 *
 * @param[in]     dev        Device info.
 * @param[in]     mode       Enable mode (PCA9451_LDSW_MODE_OFF/ENABLE BY SWEN/FORCED ON/FORCED ON).
 *
 * @return True if successful.
 */
bool PCA9451_LdSwEnable(const PCA9451_Type *dev, uint8_t mode);

/*!
 * Get LDO enable mode
 *
 * @param[in]     dev        Device info.
 * @param[in]     ldoId      LDO regulator index (PCA9451_REG_LDO1/4/5).
 * @param[out]    mode       Pointer to return the enable mode.
 *
 * @return True if successful.
 */
bool PCA9451_LdoIsEnabled(const PCA9451_Type *dev, uint8_t ldoId,
    uint8_t *mode);

/*!
 * Get LDSW enable mode
 *
 * @param[in]     dev        Device info.
 * @param[out]    mode       Pointer to return the mode.
 *
 * @return True if successful.
 */
bool PCA9451_LdSwIsEnabled(const PCA9451_Type *dev, uint8_t *mode);

/*!
 * Set regulator output voltage
 *
 * @param[in]     dev        Device info.
 * @param[in]     regulator  Regulator index (PCA9451_REG_SWx / PCA9451_REG_LDOx).
 * @param[in]     state      Voltage state: PCA9451_STATE_RUN or PCA9451_STATE_STBY.
 * @param[in]     microVolt  Desired voltage in microvolts.
 *
 * @return True if successful.
 */
bool PCA9451_VoltageSet(const PCA9451_Type *dev, uint8_t regulator,
    uint8_t state, uint32_t microVolt);

/*!
 * Get regulator output voltage
 *
 * @param[in]     dev        Device info.
 * @param[in]     regulator  Regulator index (PCA9451_REG_SWx / PCA9451_REG_LDOx).
 * @param[in]     state      Voltage state: PCA9451_STATE_RUN or PCA9451_STATE_STBY.
 * @param[out]    microVolt  Pointer to return the voltage in microvolts.
 *
 * @return True if successful.
 */
bool PCA9451_VoltageGet(const PCA9451_Type *dev, uint8_t regulator,
    uint8_t state, uint32_t *microVolt);

/*!
 * Get die temperature status
 *
 * Returns the approximate die temperature based on THERM_105S and THERM_125S
 * status bits in the STATUS1 register (0x03).
 *
 * @param[in]     dev        Device info.
 * @param[out]    temp       Pointer to return the temperature threshold in °C.
 *
 * @return True if successful.
 */
bool PCA9451_TempGet(const PCA9451_Type *dev, int32_t *temp);

/*!
 * Set die temperature event
 *
 * Set the Die temperature event.
 *
 * @param[in]     dev        Device info.
 * @param[in]    temp        Temperature threshold in °C.
 *
 * @return True if successful.
 */
bool PCA9451_TempSet(const PCA9451_Type *dev, int32_t temp);

/*!
 * Enable or disable INT1 interrupt bits
 *
 * @param[in]     dev      Device info.
 * @param[in]     mask     Bitmask of INT1 bits to modify (PCA9451_INT1_xxx).
 * @param[in]     enable   true = enable (unmask), false = disable (mask).
 *
 * @return True if successful.
 */
bool PCA9451_IntEnable(const PCA9451_Type *dev, uint8_t mask, bool enable);

/*!
 * Read and clear PWRON_STAT status
 *
 * Reading the PWRON_STAT register clears it.
 *
 * @param[in]     dev      Device info.
 * @param[out]    val      Pointer to return the PWRON_STAT register value.
 *
 * @return True if successful.
 */
bool PCA9451_FaultFlags(const PCA9451_Type *dev, uint8_t *val);

/*!
 * Read and clear INT1 interrupt status
 *
 * Reading the INT1 register clears it and releases IRQ_B if all bits are clear.
 *
 * @param[in]     dev      Device info.
 * @param[out]    mask     Pointer to return the INT1 register value.
 *
 * @return True if successful.
 */
bool PCA9451_IntStatus(const PCA9451_Type *dev, uint8_t *mask);

/*!
 * Get voltage regulator fault status
 *
 * Reads VRFLT1_STS (0x2B) and VRFLT2_STS (0x2C).
 *
 * @param[in]     dev      Device info.
 * @param[out]    flt1     Pointer to return VRFLT1_STS byte.
 * @param[out]    flt2     Pointer to return VRFLT2_STS byte.
 * @param[in]     clear    true = write-back 1s to clear latched bits.
 *
 * @return True if successful.
 */
bool PCA9451_FaultGet(const PCA9451_Type *dev, uint8_t *flt1, uint8_t *flt2,
    bool clear);

/*!
 * Issue a software reset
 *
 * @param[in]     dev      Device info.
 * @param[in]     rstVal   Reset command (PCA9451_SW_RST_xxx).
 *
 * @return True if successful.
 */
bool PCA9451_SwReset(const PCA9451_Type *dev, uint8_t rstVal);

/*!
 * Set the DVS regulator preset enable bit only
 *
 * @param[in]     dev         Device info.
 * @param[in]     presetEn    1 = use Bx_DVS_PRESET bits, 0 = use DVS0/DVS1 regs.
 *
 * @return True if successful.
 */
bool PCA9451_SWPresetSet(const PCA9451_Type *dev, uint8_t presetEn);

/*!
 * Configure the I2C level translator enable
 *
 * @param[in]     dev        Device info.
 * @param[in]     i2cLtEn    I2C level translator mode (I2C_LT_EN[1:0]).
 *
 * @return True if successful.
 */
bool PCA9451_ConfigI2cLevelTransSet(const PCA9451_Type *dev,
    uint8_t i2cLtEn);

/*!
 * Configure the WDOG_B response behavior
 *
 * @param[in]     dev        Device info.
 * @param[in]     wdogbResp  WDOG_B_CFG bits (0=disabled, 1=warm, 2=cold no LDO1, 3=cold).
 *
 * @return True if successful.
 */
bool PCA9451_ConfigWdogbResponseSet(const PCA9451_Type *dev,
    uint8_t wdogbResp);

/*!
 * Set DVS buck voltages
 *
 * @param[in]     dev         Device info.
 * @param[in]     presetEn    Preset enable (1 = use preset, 0 = use DVS0/DVS1).
 * @param[in]     b1voltCode  BUCK1 DVS preset voltage code.
 * @param[in]     b2voltCode  BUCK2 DVS preset voltage code.
 * @param[in]     b3voltCode  BUCK3 DVS preset voltage code.
 *
 * @return True if successful.
 */
bool PCA9451_BuckDvsVoltageSet(const PCA9451_Type *dev, uint8_t presetEn,
    uint8_t b1voltCode, uint8_t b2voltCode, uint8_t b3voltCode);

/*!
 * Convert buck DVS voltage code to voltage
 *
 * @param[in]     buckIdx    Buck regulator index (1, 2, or 3).
 * @param[in]     voltCode   Voltage code.
 * @param[out]    microVolt  Pointer to return voltage in microvolts.
 *
 * @return True if successful.
 */
bool PCA9451_BuckDvsCode2VoltageConvert(uint32_t buckIdx, uint32_t voltCode,
    uint32_t *microVolt);

/*!
 * Get DVS buck voltages
 *
 * @param[in]     dev         Device info.
 * @param[out]    presetEn    Pointer to return preset enable status.
 * @param[out]    b1voltCode  Pointer to return BUCK1 DVS preset voltage code.
 * @param[out]    b2voltCode  Pointer to return BUCK2 DVS preset voltage code.
 * @param[out]    b3voltCode  Pointer to return BUCK3 DVS preset voltage code.
 *
 * @return True if successful.
 */
bool PCA9451_BuckDvsVoltageGet(const PCA9451_Type *dev, uint8_t *presetEn,
    uint8_t *b1voltCode, uint8_t *b2voltCode, uint8_t *b3voltCode);

/*!
 * Set buck run voltage
 *
 * @param[in]     dev        Device info.
 * @param[in]     buckId     Buck regulator index (1-6).
 * @param[in]     voltCode   Voltage code.
 *
 * @return True if successful.
 */
bool PCA9451_BuckRunVoltageSet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t voltCode);

/*!
 * Set buck standby voltage
 *
 * @param[in]     dev        Device info.
 * @param[in]     buckId     Buck regulator index (1-3).
 * @param[in]     voltCode   Voltage code.
 *
 * @return True if successful.
 */
bool PCA9451_BuckStbyVoltageSet(const PCA9451_Type *dev, uint8_t buckId,
    uint8_t voltCode);

/*!
 * Convert voltage to buck DVS preset voltage code
 *
 * @param[in]     buckIdx    Buck regulator index (1, 2, or 3).
 * @param[in]     microVolt  Voltage in microvolts.
 * @param[out]    voltCode   Pointer to return the voltage code.
 *
 * @return True if successful.
 */
bool PCA9451_BuckDvsVoltage2CodeConvert(uint32_t buckIdx, uint32_t microVolt,
    uint32_t *voltCode);

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/** @} */

#endif /* FSL_PCA9451_H */

