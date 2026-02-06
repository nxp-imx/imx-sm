/*
 * Copyright 2023-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_PF09_H
#define FSL_PF09_H

#include "fsl_lpi2c.h"

/*!
 * @addtogroup pf09
 * @{
 * @file
 * @brief
 *
 * Header file containing the API for the PF09A PMIC.
 */

/******************************************************************************
 * Definitions
 *****************************************************************************/

/*! PF09 driver version. */
#define FSL_PF09_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))

/*! PF09 device ID length. */
#define PF09_ID_LEN  5U

/*! PF09 device info. */
typedef struct
{
    LPI2C_Type *i2cBase;      /*!< I2C base address */
    uint8_t devAddr;          /*!< Device I2C address */
    bool crcEn;               /*!< CRC enabled */
    bool secureEn;            /*!< Secure writes enabled */
    uint8_t id[PF09_ID_LEN];  /*!< Id buffer */
} PF09_Type;

/*! PF09 regulator info. */
typedef struct
{
    uint32_t minV;  /*!< Regulator Min Voltage in microvolts */
    uint32_t maxV;  /*!< Regulator Max Voltage in microvolts */
    uint32_t stepV; /*!< Regulator step in microvolts */
} PF09_RegInfo;

/*!
 * @name PF09 regulators
 */
/** @{ */
#define PF09_REG_SW1   1U  /*!< SW1 buck regulator */
#define PF09_REG_SW2   2U  /*!< SW2 buck regulator */
#define PF09_REG_SW3   3U  /*!< SW3 buck regulator */
#define PF09_REG_SW4   4U  /*!< SW4 buck regulator */
#define PF09_REG_SW5   5U  /*!< SW5 buck regulator */
#define PF09_REG_LDO1  6U  /*!< LDO1 linear regulator */
#define PF09_REG_LDO2  7U  /*!< LDO2 linear regulator */
#define PF09_REG_LDO3  8U  /*!< LDO3 linear regulator */
/** @} */

/*!
 * @name PF09 Buck regulator operation mode
 */
/** @{ */
#define PF09_SW_MODE_OFF  0U  /*!< Switcher off */
#define PF09_SW_MODE_PWM  1U  /*!< Switcher PWM */
#define PF09_SW_MODE_PFN  2U  /*!< Switcher PFN */
/** @} */

/*!
 * @name PF09 GPIO
 */
/** @{ */
#define PF09_GPIO1  0U  /*!< GPIO1 */
#define PF09_GPIO2  1U  /*!< GPIO2 */
#define PF09_GPIO3  2U  /*!< GPIO3 */
#define PF09_GPIO4  3U  /*!< GPIO4 */
/** @} */

/*!
 * @name PF09 voltage state
 */
/** @{ */
#define PF09_STATE_VRUN   0U  /*!< RUN voltage */
#define PF09_STATE_VSTBY  1U  /*!< STBY voltage */
/** @} */

/*! Number of mask words */
#define PF09_MASK_LEN  12U

/*!
 * @name PF09 voltage state
 */
/** @{ */
#define PF09_MASK_IDX_STATUS1   0U   /*!< Status 1 mask */
#define PF09_MASK_IDX_STATUS2   1U   /*!< Status 2 mask */
#define PF09_MASK_IDX_STATUS3   2U   /*!< Status 3 mask */
#define PF09_MASK_IDX_SW_MODE   3U   /*!< Switcher mode mask */
#define PF09_MASK_IDX_SW_ILIM   4U   /*!< Switcher current limit mask */
#define PF09_MASK_IDX_LDO_ILIM  5U   /*!< LDO current limit mask */
#define PF09_MASK_IDX_SW_UV     6U   /*!< Switcher under volt mask */
#define PF09_MASK_IDX_SW_OV     7U   /*!< Switcher over volt mask */
#define PF09_MASK_IDX_LDO_UV    8U   /*!< LDO uncer volt mask */
#define PF09_MASK_IDX_LDO_OV    9U   /*!< LDO over volt mask */
#define PF09_MASK_IDX_PWRON     10U  /*!< Power on mask */
#define PF09_MASK_IDX_IO        11U  /*!< I/O mask */
/** @} */

/*!
 * @name PF09 voltage monitors
 */
/** @{ */
#define PF09_VMON1     1U  /*!< VMON1 monitor */
#define PF09_VMON2     2U  /*!< VMON2 monitor */
/** @} */

/*!
 * @name PF09 faults
 */
/** @{ */
#define PF09_HFAULT_FLG  0x01U  /*!< Hard fault */
#define PF09_SFAULT_FLG  0x02U  /*!< OV/UV/ILIM) */
#define PF09_XRESET_FLG  0x04U  /*!< XRESET or FCCU */
#define PF09_WD_FLG      0x08U  /*!< Watchdog */
#define PF09_XFAIL_FLG   0x10U  /*!< XFAILB pin */
#define PF09_VIN_OV_FLG  0x20U  /*!< VIN_OV condition */
#define PF09_DFS_FLG     0x40U  /*!< DFS state */
#define PF09_DCRC_FLG    0x80U  /*!< Dynamic CRC */
/** @} */

/*!
 * @name PF09 hard faults
 */
/** @{ */
#define PF09_TSD_FAIL     0x01U  /*!< Thermal shutdown */
#define PF09_REG_FAIL     0x02U  /*!< Regulator */
#define PF09_FLTCNT_FAIL  0x04U  /*!< Fault counter */
#define PF09_RESET_FAIL   0x08U  /*!< Reset counter */
#define PF09_PU_FAIL      0x10U  /*!< Power-up failure */
#define PF09_RSTB_FAIL    0x20U  /*!< RSTB pin */
#define PF09_UVDET_FAIL   0x40U  /*!< UVDET threshold */
/** @} */

/*!
 * @name PF09 registers
 */
/** @{ */
#define PF09_FAMILY_ID          0x09U  /*!< PF09 family id */
#define PF09_REV_B0             0x20U  /*!< PF09 silicon rev B0 */
#define PF09_REV_C0             0x30U  /*!< PF09 silicon rev C0 */

#define PF09_NUM_LDO            5U     /*!< Number of LDO regulators */
#define PF09_NUM_BUCK           3U     /*!< Number of buck regulators */
#define PF09_NUM_REG            0x82U  /*!< Total number of registers */

#define PF09_REG_DEV_ID         0x00U  /*!< Device ID */
#define PF09_REG_DEV_FAM_ID     0x01U  /*!< Device family ID */
#define PF09_REG_REV_ID         0x02U  /*!< Silicon revision ID */
#define PF09_REG_PROG_ID1       0x03U  /*!< Programmed ID 1 */
#define PF09_REG_PROG_ID2       0x04U  /*!< Programmed ID 2 */
#define PF09_REG_SYSTEM_INT     0x05U  /*!< System interrupt status */
#define PF09_REG_STATUS1_INT    0x06U  /*!< Status group 1 interrupt */
#define PF09_REG_STATUS1_MASK   0x07U  /*!< Status group 1 interrupt mask */
#define PF09_REG_STATUS1_SNS    0x08U  /*!< Status group 1 sense */
#define PF09_REG_STATUS2_INT    0x09U  /*!< Status group 2 interrupt */
#define PF09_REG_STATUS2_MASK   0x0AU  /*!< Status group 2 interrupt mask */
#define PF09_REG_STATUS2_SNS    0x0BU  /*!< Status group 2 sense */
#define PF09_REG_STATUS3_INT    0x0CU  /*!< Status group 3 interrupt */
#define PF09_REG_STATUS3_MASK   0x0DU  /*!< Status group 3 interrupt mask */
#define PF09_REG_SW_MODE_INT    0x0EU  /*!< Switcher mode interrupt */
#define PF09_REG_SW_MODE_MASK   0x0FU  /*!< Switcher mode interrupt mask */
#define PF09_REG_SW_ILIM_INT    0x10U  /*!< Switcher current-limit interrupt */
#define PF09_REG_SW_ILIM_MASK   0x11U  /*!< Switcher current-limit mask */
#define PF09_REG_SW_ILIM_SNS    0x12U  /*!< Switcher current-limit sense */
#define PF09_REG_LDO_ILIM_INT   0x13U  /*!< LDO current-limit interrupt */
#define PF09_REG_LDO_ILIM_MASK  0x14U  /*!< LDO current-limit mask */
#define PF09_REG_LDO_ILIM_SNS   0x15U  /*!< LDO current-limit sense */
#define PF09_REG_SW_UV_INT      0x16U  /*!< Switcher undervoltage interrupt */
#define PF09_REG_SW_UV_MASK     0x17U  /*!< Switcher undervoltage mask */
#define PF09_REG_SW_UV_SNS      0x18U  /*!< Switcher undervoltage sense */
#define PF09_REG_SW_OV_INT      0x19U  /*!< Switcher overvoltage interrupt */
#define PF09_REG_SW_OV_MASK     0x1AU  /*!< Switcher overvoltage mask */
#define PF09_REG_SW_OV_SNS      0x1BU  /*!< Switcher overvoltage sense */
#define PF09_REG_LDO_UV_INT     0x1CU  /*!< LDO undervoltage interrupt */
#define PF09_REG_LDO_UV_MASK    0x1DU  /*!< LDO undervoltage mask */
#define PF09_REG_LDO_UV_SNS     0x1EU  /*!< LDO undervoltage sense */
#define PF09_REG_LDO_OV_INT     0x1FU  /*!< LDO overvoltage interrupt */
#define PF09_REG_LDO_OV_MASK    0x20U  /*!< LDO overvoltage mask */
#define PF09_REG_LDO_OV_SNS     0x21U  /*!< LDO overvoltage sense */
#define PF09_REG_PWRON_INT      0x22U  /*!< Power-on event interrupt */
#define PF09_REG_PWRON_MASK     0x23U  /*!< Power-on event interrupt mask */
#define PF09_REG_IO_INT         0x24U  /*!< I/O interrupt */
#define PF09_REG_IO_MSK         0x25U  /*!< I/O interrupt mask */
#define PF09_REG_IO_SNS         0x26U  /*!< I/O sense */
#define PF09_REG_IOSHORT_SNS    0x27U  /*!< I/O short-circuit sense */
#define PF09_REG_ABIST_OV1      0x28U  /*!< ABIST overvoltage result 1 */
#define PF09_REG_ABIST_OV2      0x29U  /*!< ABIST overvoltage result 2 */
#define PF09_REG_ABIST_UV1      0x2AU  /*!< ABIST undervoltage result 1 */
#define PF09_REG_ABIST_UV2      0x2BU  /*!< ABIST undervoltage result 2 */
#define PF09_REG_ABIST_IO       0x2CU  /*!< ABIST I/O test result */
#define PF09_REG_TEST_FLAGS     0x2DU  /*!< Test flags */
#define PF09_REG_HFAULT_FLAGS   0x2EU  /*!< Hard fault flags */
#define PF09_REG_FAULT_FLAGS    0x2FU  /*!< Fault flags */
#define PF09_REG_FS0B_CFG       0x30U  /*!< FS0B config */
#define PF09_REG_FCCU_CFG       0x31U  /*!< FCCU config */
#define PF09_REG_RSTB_CFG1      0x32U  /*!< RSTB config 1 */
#define PF09_REG_SECURE_WR1     0x35U  /*!< Secure write 1 */
#define PF09_REG_SECURE_WR2     0x36U  /*!< Secure write 2 */
#define PF09_REG_VMON_CFG1      0x37U  /*!< Voltage monitor config 1 */
#define PF09_REG_SYS_CFG1       0x38U  /*!< System config 1 */
#define PF09_REG_GPO_CFG        0x39U  /*!< GPIO config */
#define PF09_REG_GPO_CTRL       0x3AU  /*!< GPIO ctrl */
#define PF09_REG_PWRUP_CFG      0x3BU  /*!< Power-up config */
#define PF09_REG_RSTB_PWRUP     0x3CU  /*!< RSTB power-up config */
#define PF09_REG_GPIO1_PWRUP    0x3DU  /*!< GPIO1 power-up config */
#define PF09_REG_GPIO2_PWRUP    0x3EU  /*!< GPIO2 power-up config */
#define PF09_REG_GPIO3_PWRUP    0x3FU  /*!< GPIO3 power-up config */
#define PF09_REG_GPIO4_PWRUP    0x40U  /*!< GPIO4 power-up config */
#define PF09_REG_VMON1_PWRUP    0x41U  /*!< VMON1 power-up config */
#define PF09_REG_VMON2_PWRUP    0x42U  /*!< VMON2 power-up config */
#define PF09_REG_SW1_PWRUP      0x43U  /*!< SW1 power-up config */
#define PF09_REG_SW2_PWRUP      0x44U  /*!< SW2 power-up config */
#define PF09_REG_SW3_PWRUP      0x45U  /*!< SW3 power-up config */
#define PF09_REG_SW4_PWRUP      0x46U  /*!< SW4 power-up config */
#define PF09_REG_SW5_PWRUP      0x47U  /*!< SW5 power-up config */
#define PF09_REG_LDO1_PWRUP     0x48U  /*!< LDO1 power-up config */
#define PF09_REG_LDO2_PWRUP     0x49U  /*!< LDO2 power-up config */
#define PF09_REG_LDO3_PWRUP     0x4AU  /*!< LDO3 power-up config */
#define PF09_REG_WD_CTRL1       0x4EU  /*!< Watchdog ctrl 1 */
#define PF09_REG_WD_CTRL2       0x4FU  /*!< Watchdog ctrl 2 */
#define PF09_REG_WD_CFG1        0x50U  /*!< Watchdog config 1 */
#define PF09_REG_WD_CFG2        0x51U  /*!< Watchdog config 2 */
#define PF09_REG_WD_CNT1        0x52U  /*!< Watchdog counter 1 */
#define PF09_REG_WD_CNT2        0x53U  /*!< Watchdog counter 2 */
#define PF09_REG_FAULT_CFG      0x54U  /*!< Fault handling config */
#define PF09_REG_FAULT_CNT      0x55U  /*!< Fault counter */
#define PF09_REG_DFS_CNT        0x56U  /*!< DFS counter/status */
#define PF09_REG_AMUX_CFG       0x57U  /*!< Analog mux config */
#define PF09_REG_VMON1_RUN_CFG  0x58U  /*!< VMON1 run config */
#define PF09_REG_VMON1_STBY_CFG 0x59U  /*!< VMON1 standby config */
#define PF09_REG_VMON1_CTRL     0x5AU  /*!< VMON1 ctrl register */
#define PF09_REG_VMON2_RUN_CFG  0x5BU  /*!< VMON2 run config */
#define PF09_REG_VMON2_STBY_CFG 0x5CU  /*!< VMON2 standby config */
#define PF09_REG_VMON2_CTRL     0x5DU  /*!< VMON2 ctrl */
#define PF09_REG_SW1_VRUN       0x5EU  /*!< SW1 run voltage */
#define PF09_REG_SW1_VSTBY      0x5FU  /*!< SW1 standby voltage */
#define PF09_REG_SW1_MODE       0x60U  /*!< SW1 mode */
#define PF09_REG_SW1_CFG1       0x61U  /*!< SW1 config 1 */
#define PF09_REG_SW1_CFG2       0x62U  /*!< SW1 config 2 */
#define PF09_REG_SW2_VRUN       0x63U  /*!< SW2 run voltage */
#define PF09_REG_SW2_VSTBY      0x64U  /*!< SW2 standby voltage */
#define PF09_REG_SW2_MODE       0x65U  /*!< SW2 mode */
#define PF09_REG_SW2_CFG1       0x66U  /*!< SW2 config 1 */
#define PF09_REG_SW2_CFG2       0x67U  /*!< SW2 config 2 */
#define PF09_REG_SW3_VRUN       0x68U  /*!< SW3 run voltage */
#define PF09_REG_SW3_VSTBY      0x69U  /*!< SW3 standby voltage */
#define PF09_REG_SW3_MODE       0x6AU  /*!< SW3 mode */
#define PF09_REG_SW3_CFG1       0x6BU  /*!< SW3 config 1 */
#define PF09_REG_SW3_CFG2       0x6CU  /*!< SW3 config 2 */
#define PF09_REG_SW4_VRUN       0x6DU  /*!< SW4 run voltage */
#define PF09_REG_SW4_VSTBY      0x6EU  /*!< SW4 standby voltageg */
#define PF09_REG_SW4_MODE       0x6FU  /*!< SW4 mode */
#define PF09_REG_SW4_CFG1       0x70U  /*!< SW4 config 1 */
#define PF09_REG_SW4_CFG2       0x71U  /*!< SW4 config 2 */
#define PF09_REG_SW5_VRUN       0x72U  /*!< SW5 run voltage */
#define PF09_REG_SW5_VSTBY      0x73U  /*!< SW5 standby voltage */
#define PF09_REG_SW5_MODE       0x74U  /*!< SW5 mode */
#define PF09_REG_SW5_CFG1       0x75U  /*!< SW5 config 1 */
#define PF09_REG_SW5_CFG2       0x76U  /*!< SW5 config 2 */
#define PF09_REG_LDO1_RUN       0x77U  /*!< LDO1 run voltage */
#define PF09_REG_LDO1_STBY      0x78U  /*!< LDO1 standby voltage */
#define PF09_REG_LDO1_CFG2      0x79U  /*!< LDO1 config 2 */
#define PF09_REG_LDO2_RUN       0x7AU  /*!< LDO2 run voltage */
#define PF09_REG_LDO2_STBY      0x7BU  /*!< LDO2 standby voltage */
#define PF09_REG_LDO2_CFG2      0x7CU  /*!< LDO2 config 2 */
#define PF09_REG_LDO3_RUN       0x7DU  /*!< LDO3 run voltage */
#define PF09_REG_LDO3_STBY      0x7EU  /*!< LDO3 standby voltage */
#define PF09_REG_LDO3_CFG2      0x7FU  /*!< LDO3 config 2 */
#define PF09_REG_VAON_CFG1      0x80U  /*!< VAON config 1 */
#define PF09_REG_VAON_CFG2      0x81U  /*!< VAON config 2 */
#define PF09_REG_SYS_DIAG       0x82U  /*!< System diagnostics */
/** @} */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * Initialize a PF09
 *
 * @param[in]     dev        Device info.
 *
 * @return True if successful.
 */
bool PF09_Init(PF09_Type *dev);

/*!
 * Get PF09 info
 *
 * @param[in]     dev      Device info.
 * @param[out]    info     Pointer to return pointer to info.
 * @param[out]    len      Number of info bytes.
 *
 * @return True if successful.
 */
bool PF09_PmicInfoGet(PF09_Type *dev, uint8_t **info, uint8_t *len);

/*!
 * Write a PF09 register
 *
 * @param[in]     dev      Device info.
 * @param[in]     regAddr  Register address.
 * @param[in]     val      Value to write.
 * @param[in]     mask     Mask for RMW.
 *
 * @return True if successful.
 */
bool PF09_PmicWrite(const PF09_Type *dev, uint8_t regAddr, uint8_t val,
    uint8_t mask);

/*!
 * Read a PF09 register
 *
 * @param[in]     dev      Device info.
 * @param[in]     regAddr  Register address.
 * @param[out]    val      Pointer to return value.
 *
 * @return True if successful.
 */
bool PF09_PmicRead(const PF09_Type *dev, uint8_t regAddr, uint8_t *val);

/*!
 * Interrupt enable/disable
 *
 * @param[in]     dev      Device info.
 * @param[in]     mask     Array of masks to modify.
 * @param[in]     enable   true = enable, false = disable.
 * @param[in]     maskLen  length in bytes of the mask array.
 *
 * @return True if successful.
 */
bool PF09_IntEnable(const PF09_Type *dev, const uint8_t *mask,
    uint32_t maskLen, bool enable);

/*!
 * Get interrupt status
 *
 * @param[in]     dev      Device info.
 * @param[in]     mask     Array of status masks.
 * @param[in]     maskLen  length in bytes of the mask array.
 *
 * @return True if successful.
 */
bool PF09_IntStatus(const PF09_Type *dev, uint8_t *mask, uint32_t maskLen);

/*!
 * Clear interrupts
 *
 * @param[in]     dev      Device info.
 * @param[in]     mask     Array of masks to clear.
 * @param[in]     maskLen  length in bytes of the mask array.
 *
 * @return True if successful.
 */
bool PF09_IntClear(const PF09_Type *dev, const uint8_t *mask,
    uint32_t maskLen);

/*!
 * Get PF09 regulator Info
 *
 * @param[in]     regulator  Regulator name SW or LDO.
 * @param[out]    regInfo    Regulator info.
 *
 * @return True if successful.
 */
bool PF09_RegulatorInfoGet(uint8_t regulator, PF09_RegInfo *regInfo);

/*!
 * Set the buck regulator mode for the state
 *
 * @param[in]     dev        Device info.
 * @param[in]     regulator  Regulator name SW or LDO.
 * @param[in]     state      RUN or STBY voltage.
 * @param[in]     mode       Regulator operation mode.
 *
 * @return True if successful.
 */
bool PF09_SwModeSet(const PF09_Type *dev, uint8_t regulator, uint8_t state,
    uint8_t mode);

/*!
 * Get the buck regulator mode for the state
 *
 * @param[in]     dev        Device info.
 * @param[in]     regulator  Regulator name SW or LDO.
 * @param[in]     state      RUN or STBY voltage.
 * @param[out]    mode       Pointer to return the operation mode.
 *
 * @return True if successful.
 */
bool PF09_SwModeGet(const PF09_Type *dev, uint8_t regulator, uint8_t state,
    uint8_t *mode);

/*!
 * Output enable/disable of LDO
 *
 * @param[in]     dev        Device info.
 * @param[in]     regulator  Regulator name of LDO.
 * @param[in]     state      RUN or STBY voltage.
 * @param[in]     ldoEn      Enable or Disable LDO output.
 *
 * @return True if successful.
 */
bool PF09_LdoEnable(const PF09_Type *dev, uint8_t regulator, uint8_t state,
    bool ldoEn);

/*!
 * Status of LDO
 *
 * @param[in]     dev         Device info.
 * @param[in]     regulator   Regulator name of LDO.
 * @param[in]     state       RUN or STBY voltage.
 * @param[out]    ldoEn       Pointer to return the status of LDO.
 *
 * @return True if successful.
 */
bool PF09_LdoIsEnabled(const PF09_Type *dev, uint8_t regulator, uint8_t state,
    bool *ldoEn);

/*!
 * Set the GPIO control
 *
 * @param[in]     dev        Device info.
 * @param[in]     gpio       GPIO name.
 * @param[in]     state      RUN or STBY voltage.
 * @param[in]     ctrl       Control value.
 *
 * @return True if successful.
 */
bool PF09_GpioCtrlSet(const PF09_Type *dev, uint8_t gpio, uint8_t state,
    bool ctrl);

/*!
 * Get the GPIO control
 *
 * @param[in]     dev        Device info.
 * @param[in]     gpio       GPIO name.
 * @param[in]     state      RUN or STBY voltage.
 * @param[out]    ctrl       Pointer to return the control value.
 *
 * @return True if successful.
 */
bool PF09_GpioCtrlGet(const PF09_Type *dev, uint8_t gpio, uint8_t state,
    bool *ctrl);

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
bool PF09_VoltageGet(const PF09_Type *dev, uint8_t regulator, uint8_t state,
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
bool PF09_VoltageSet(const PF09_Type *dev, uint8_t regulator, uint8_t state,
    uint32_t microVolt);

/*!
 * Get sensor temp
 *
 * @param[in]     dev        Device info.
 * @param[out]    temp       Pointer to return the temp in C.
 *
 * @return True if successful.
 */
bool PF09_TempGet(const PF09_Type *dev, int32_t *temp);

/*!
 * Set temp sensor alarm
 *
 * @param[in]     dev        Device info.
 * @param[out]    temp       Temp in C.
 *
 * @return True if successful.
 */
bool PF09_TempAlarmSet(const PF09_Type *dev, int32_t temp);

/*!
 * Enable PF09 WatchDog
 *
 * @param[in]     dev       Device info.
 * @param[in]     wdogEn    WDOG Enable.
 *
 * @return True if successful.
 */
bool PF09_WdogEnable(const PF09_Type *dev, bool wdogEn);

/*!
 * Service PF09 Static/Dynamic WatchDog in Open window
 *
 * @param[in]     dev        Device info.
 * @param[in]     wdogMode   Static or Dynamic mode of wdog.
 *
 * @return True if successful.
 */
bool PF09_WdogService(const PF09_Type *dev, uint8_t wdogMode);

/*!
 * Set the monitor voltage in microVolts
 *
 * @param[in]     dev        Device info.
 * @param[in]     monitor    Monitor name.
 * @param[in]     state      RUN or STBY voltage.
 * @param[in]     microVolt  Regulator microVolts.
 *
 * @return True if successful.
 */
bool PF09_MonitorSet(const PF09_Type *dev, uint8_t monitor, uint8_t state,
    uint32_t microVolt);

/*!
 * Enable/disable the monitor
 *
 * @param[in]     dev        Device info.
 * @param[in]     monitor    Monitor name.
 * @param[in]     monEn      Enable or disable voltage monitoring.
 *
 * @return True if successful.
 */
bool PF09_MonitorEnable(const PF09_Type *dev, uint8_t monitor, bool monEn);

/*!
 * Enable/disable XRESET monitoring in STANDBY
 *
 * @param[in]     dev        Device info.
 * @param[in]     xrstEn     Enable or disable XRESET monitoring.
 *
 * @return True if successful.
 */
bool PF09_XrstStbyEnable(const PF09_Type *dev, bool xrstEn);

/*!
 * Save and clear fault flags
 *
 * @param[in]     dev      Device info.
 * @param[out]    flags    Pointer to retufn fault flags.
 * @param[in]     clear    true = clear fault flags.
 *
 * @return True if successful.
 */
bool PF09_FaultFlags(const PF09_Type *dev, uint32_t *flags, bool clear);

#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/** @} */

#endif /* FSL_PF09_H */

