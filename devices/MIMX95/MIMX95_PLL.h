/*
** ###################################################################
**     Processors:          MIMX95_cm33
**
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX95_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2023 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**
** ###################################################################
*/

/*!
 * @file MIMX95_PLL.h
 * @version
 * @date
 * @brief CMSIS Peripheral Access Layer for MIMX95_PLL
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_PLL_H_)  /* Check if memory map has not been already included */
#define MIMX95_PLL_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PLL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLL_Peripheral_Access_Layer PLL Peripheral Access Layer
 * @{
 */

/** PLL - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< PLL Control Register, offset: 0x0 */
    __IO uint32_t SET;                               /**< PLL Control Register, offset: 0x4 */
    __IO uint32_t CLR;                               /**< PLL Control Register, offset: 0x8 */
    __IO uint32_t TOG;                               /**< PLL Control Register, offset: 0xC */
  } CTRL;
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< PLL Analog Program Register, offset: 0x10 */
    __IO uint32_t SET;                               /**< PLL Analog Program Register, offset: 0x14 */
    __IO uint32_t CLR;                               /**< PLL Analog Program Register, offset: 0x18 */
    __IO uint32_t TOG;                               /**< PLL Analog Program Register, offset: 0x1C */
  } ANA_PRG;
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< PLL TEST Register, offset: 0x20 */
    __IO uint32_t SET;                               /**< PLL TEST Register, offset: 0x24 */
    __IO uint32_t CLR;                               /**< PLL TEST Register, offset: 0x28 */
    __IO uint32_t TOG;                               /**< PLL TEST Register, offset: 0x2C */
  } TEST;
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< PLL Spread Spectrum Register, offset: 0x30 */
    __IO uint32_t SET;                               /**< PLL Spread Spectrum Register, offset: 0x34 */
    __IO uint32_t CLR;                               /**< PLL Spread Spectrum Register, offset: 0x38 */
    __IO uint32_t TOG;                               /**< PLL Spread Spectrum Register, offset: 0x3C */
  } SPREAD_SPECTRUM;
  struct {                                         /* offset: 0x40 */
    __IO uint32_t RW;                                /**< PLL Numerator Register, offset: 0x40 */
    __IO uint32_t SET;                               /**< PLL Numerator Register, offset: 0x44 */
    __IO uint32_t CLR;                               /**< PLL Numerator Register, offset: 0x48 */
    __IO uint32_t TOG;                               /**< PLL Numerator Register, offset: 0x4C */
  } NUMERATOR;
  struct {                                         /* offset: 0x50 */
    __IO uint32_t RW;                                /**< PLL Denominator Register, offset: 0x50 */
    __IO uint32_t SET;                               /**< PLL Denominator Register, offset: 0x54 */
    __IO uint32_t CLR;                               /**< PLL Denominator Register, offset: 0x58 */
    __IO uint32_t TOG;                               /**< PLL Denominator Register, offset: 0x5C */
  } DENOMINATOR;
  struct {                                         /* offset: 0x60 */
    __IO uint32_t RW;                                /**< PLL Dividers Register, offset: 0x60 */
    __IO uint32_t SET;                               /**< PLL Dividers Register, offset: 0x64 */
    __IO uint32_t CLR;                               /**< PLL Dividers Register, offset: 0x68 */
    __IO uint32_t TOG;                               /**< PLL Dividers Register, offset: 0x6C */
  } DIV;
  struct {                                         /* offset: 0x70, array step: 0x20 */
    struct {                                         /* offset: 0x70 */
      __IO uint32_t RW;                                /**< DFS Control Register, offset: 0x70, not available in all instances (available on 1 out of 4) */
      __IO uint32_t SET;                               /**< DFS Control Register, offset: 0x74, not available in all instances (available on 1 out of 4) */
      __IO uint32_t CLR;                               /**< DFS Control Register, offset: 0x78, not available in all instances (available on 1 out of 4) */
      __IO uint32_t TOG;                               /**< DFS Control Register, offset: 0x7C, not available in all instances (available on 1 out of 4) */
    } DFS_CTRL;
    struct {                                         /* offset: 0x80 */
      __IO uint32_t RW;                                /**< DFS Division Register, offset: 0x80, not available in all instances (available on 1 out of 4) */
      __IO uint32_t SET;                               /**< DFS Division Register, offset: 0x84, not available in all instances (available on 1 out of 4) */
      __IO uint32_t CLR;                               /**< DFS Division Register, offset: 0x88, not available in all instances (available on 1 out of 4) */
      __IO uint32_t TOG;                               /**< DFS Division Register, offset: 0x8C, not available in all instances (available on 1 out of 4) */
    } DFS_DIV;
  } NO_OF_DFS[3];
       uint8_t RESERVED_0[32];
  __I  uint32_t PLL_STATUS;                        /**< PLL Status Register, offset: 0xF0 */
  __I  uint32_t DFS_STATUS;                        /**< DFS Status Register, offset: 0xF4, not available in all instances (available on 1 out of 4) */
} PLL_Type;

/* ----------------------------------------------------------------------------
   -- PLL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLL_Register_Masks PLL Register Masks
 * @{
 */

/*! @name CTRL - PLL Control Register */
/*! @{ */

#define PLL_CTRL_POWERUP_MASK       (0x1U)
#define PLL_CTRL_POWERUP_SHIFT      (0U)
/*! POWERUP - POWERUP
 *  0b0..PLL is Disabled
 *  0b1..PLL is Enabled
 */
#define PLL_CTRL_POWERUP(x)         (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_POWERUP_SHIFT)) & PLL_CTRL_POWERUP_MASK)

#define PLL_CTRL_CLKMUX_EN_MASK     (0x2U)
#define PLL_CTRL_CLKMUX_EN_SHIFT    (1U)
/*! CLKMUX_EN - CLKMUX ENABLE
 *  0b0..Disable the output clock
 *  0b1..Enable the output clock
 */
#define PLL_CTRL_CLKMUX_EN(x)       (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_CLKMUX_EN_SHIFT)) & PLL_CTRL_CLKMUX_EN_MASK)

#define PLL_CTRL_CLKMUX_BYPASS_MASK (0x4U)
#define PLL_CTRL_CLKMUX_BYPASS_SHIFT (2U)
/*! CLKMUX_BYPASS - CLKMUX_BYPASS
 *  0b0..Normal mode
 *  0b1..PLL Bypass mode
 */
#define PLL_CTRL_CLKMUX_BYPASS(x)   (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_CLKMUX_BYPASS_SHIFT)) & PLL_CTRL_CLKMUX_BYPASS_MASK)

#define PLL_CTRL_SPREADCTL_MASK     (0x100U)
#define PLL_CTRL_SPREADCTL_SHIFT    (8U)
/*! SPREADCTL - Modulation type selection
 *  0b0..Modulation centered around nominal frequency.
 *  0b1..Modulation spread below nominal frequency.
 */
#define PLL_CTRL_SPREADCTL(x)       (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_SPREADCTL_SHIFT)) & PLL_CTRL_SPREADCTL_MASK)

#define PLL_CTRL_DITHER_EN1_MASK    (0x200U)
#define PLL_CTRL_DITHER_EN1_SHIFT   (9U)
/*! DITHER_EN1 - Dither Enable 1
 *  0b0..Normal mode
 *  0b1..Dither enable for first stage of fractional modulator.
 */
#define PLL_CTRL_DITHER_EN1(x)      (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_DITHER_EN1_SHIFT)) & PLL_CTRL_DITHER_EN1_MASK)

#define PLL_CTRL_DITHER_EN2_MASK    (0x400U)
#define PLL_CTRL_DITHER_EN2_SHIFT   (10U)
/*! DITHER_EN2 - Dither Enable 2
 *  0b0..Normal mode
 *  0b1..Dither enable for second stage of fractional modulator.
 */
#define PLL_CTRL_DITHER_EN2(x)      (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_DITHER_EN2_SHIFT)) & PLL_CTRL_DITHER_EN2_MASK)

#define PLL_CTRL_DITHER_EN3_MASK    (0x800U)
#define PLL_CTRL_DITHER_EN3_SHIFT   (11U)
/*! DITHER_EN3 - Dither Enable 3
 *  0b0..Normal mode
 *  0b1..Dither enable for third stage of fractional modulator.
 */
#define PLL_CTRL_DITHER_EN3(x)      (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_DITHER_EN3_SHIFT)) & PLL_CTRL_DITHER_EN3_MASK)

#define PLL_CTRL_MULTIPHASE_SDM_DISABLE_MASK (0x1000U)
#define PLL_CTRL_MULTIPHASE_SDM_DISABLE_SHIFT (12U)
/*! MULTIPHASE_SDM_DISABLE - MULTIPHASE_SDM_DISABLE
 *  0b0..Normal mode
 *  0b1..MULTIPHASE_SDM_DISABLE_MODE
 */
#define PLL_CTRL_MULTIPHASE_SDM_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_MULTIPHASE_SDM_DISABLE_SHIFT)) & PLL_CTRL_MULTIPHASE_SDM_DISABLE_MASK)

#define PLL_CTRL_HW_CTRL_SEL_MASK   (0x10000U)
#define PLL_CTRL_HW_CTRL_SEL_SHIFT  (16U)
/*! HW_CTRL_SEL - Hardware control select
 *  0b0..Hardware Control Select Disable.
 *  0b1..Hardware Control Select Enable.
 */
#define PLL_CTRL_HW_CTRL_SEL(x)     (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_HW_CTRL_SEL_SHIFT)) & PLL_CTRL_HW_CTRL_SEL_MASK)

#define PLL_CTRL_LOCK_BYPASS_MASK   (0x80000000U)
#define PLL_CTRL_LOCK_BYPASS_SHIFT  (31U)
/*! LOCK_BYPASS - Lock Bypass
 *  0b0..Lock bypassing disabled.
 *  0b1..Lock bypassing enabled.
 */
#define PLL_CTRL_LOCK_BYPASS(x)     (((uint32_t)(((uint32_t)(x)) << PLL_CTRL_LOCK_BYPASS_SHIFT)) & PLL_CTRL_LOCK_BYPASS_MASK)
/*! @} */

/*! @name ANA_PRG - PLL Analog Program Register */
/*! @{ */

#define PLL_ANA_PRG_HALF_LF_MASK    (0x1U)
#define PLL_ANA_PRG_HALF_LF_SHIFT   (0U)
/*! HALF_LF - HALF_LF
 *  0b0..Normal mode
 *  0b1..Reduces the frequency of loop filter by 2x
 */
#define PLL_ANA_PRG_HALF_LF(x)      (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_HALF_LF_SHIFT)) & PLL_ANA_PRG_HALF_LF_MASK)

#define PLL_ANA_PRG_DOUBLE_LF_MASK  (0x2U)
#define PLL_ANA_PRG_DOUBLE_LF_SHIFT (1U)
/*! DOUBLE_LF - DOUBLE_LF
 *  0b0..Normal mode
 *  0b1..Increase the frequency of loop filter by 2x
 */
#define PLL_ANA_PRG_DOUBLE_LF(x)    (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_DOUBLE_LF_SHIFT)) & PLL_ANA_PRG_DOUBLE_LF_MASK)

#define PLL_ANA_PRG_LOCKCTRL_MASK   (0xCU)
#define PLL_ANA_PRG_LOCKCTRL_SHIFT  (2U)
/*! LOCKCTRL - LOCKCTRL
 *  0b00..+/-1.5%
 *  0b01..+/-2.5%
 *  0b10..+/-4.5%
 *  0b11..+/-8.5%
 */
#define PLL_ANA_PRG_LOCKCTRL(x)     (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_LOCKCTRL_SHIFT)) & PLL_ANA_PRG_LOCKCTRL_MASK)

#define PLL_ANA_PRG_UNLOCKCTRL_MASK (0x30U)
#define PLL_ANA_PRG_UNLOCKCTRL_SHIFT (4U)
/*! UNLOCKCTRL - UNLOCKCTRL
 *  0b00..+/-4.5%
 *  0b01..+/-8.5%
 *  0b10..+/-16.5%
 *  0b11..+/-2.5%
 */
#define PLL_ANA_PRG_UNLOCKCTRL(x)   (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_UNLOCKCTRL_SHIFT)) & PLL_ANA_PRG_UNLOCKCTRL_MASK)

#define PLL_ANA_PRG_LOCK_WAIT_MASK  (0xC0U)
#define PLL_ANA_PRG_LOCK_WAIT_SHIFT (6U)
/*! LOCK_WAIT - LOCK_WAIT
 *  0b00..8 cycles
 *  0b01..4 cycles
 *  0b10..16 cycles
 *  0b11..31 cycles
 */
#define PLL_ANA_PRG_LOCK_WAIT(x)    (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_LOCK_WAIT_SHIFT)) & PLL_ANA_PRG_LOCK_WAIT_MASK)

#define PLL_ANA_PRG_IPTAT_CP_CTRL_MASK (0x300U)
#define PLL_ANA_PRG_IPTAT_CP_CTRL_SHIFT (8U)
/*! IPTAT_CP_CTRL - IPTAT_CP_CTRL */
#define PLL_ANA_PRG_IPTAT_CP_CTRL(x) (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_IPTAT_CP_CTRL_SHIFT)) & PLL_ANA_PRG_IPTAT_CP_CTRL_MASK)

#define PLL_ANA_PRG_V2I_CP_CTRL_MASK (0xC00U)
#define PLL_ANA_PRG_V2I_CP_CTRL_SHIFT (10U)
/*! V2I_CP_CTRL - V2I_CP_CTRL */
#define PLL_ANA_PRG_V2I_CP_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_V2I_CP_CTRL_SHIFT)) & PLL_ANA_PRG_V2I_CP_CTRL_MASK)

#define PLL_ANA_PRG_ICP_CTRL_MASK   (0x3000U)
#define PLL_ANA_PRG_ICP_CTRL_SHIFT  (12U)
/*! ICP_CTRL - ICP_CTRL
 *  0b00..I
 *  0b01..0.5 I
 *  0b10..2 I
 *  0b11..1.5 I
 */
#define PLL_ANA_PRG_ICP_CTRL(x)     (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_ICP_CTRL_SHIFT)) & PLL_ANA_PRG_ICP_CTRL_MASK)

#define PLL_ANA_PRG_V2I_CTRL_MASK   (0xC000U)
#define PLL_ANA_PRG_V2I_CTRL_SHIFT  (14U)
/*! V2I_CTRL - V2I_CTRL
 *  0b00..I
 *  0b01..0.75 I
 *  0b10..1.5 I
 *  0b11..1.25 I
 */
#define PLL_ANA_PRG_V2I_CTRL(x)     (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_V2I_CTRL_SHIFT)) & PLL_ANA_PRG_V2I_CTRL_MASK)

#define PLL_ANA_PRG_IREF_CTRL_MASK  (0x30000U)
#define PLL_ANA_PRG_IREF_CTRL_SHIFT (16U)
/*! IREF_CTRL - IREF_CTRL */
#define PLL_ANA_PRG_IREF_CTRL(x)    (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_IREF_CTRL_SHIFT)) & PLL_ANA_PRG_IREF_CTRL_MASK)

#define PLL_ANA_PRG_WIN_PER_MASK    (0xC0000U)
#define PLL_ANA_PRG_WIN_PER_SHIFT   (18U)
/*! WIN_PER - WIN_PER
 *  0b00..200 VCO cycles
 *  0b01..300 VCO cycles
 *  0b10..400 VCO cycles
 *  0b11..100 VCO cycles
 */
#define PLL_ANA_PRG_WIN_PER(x)      (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_WIN_PER_SHIFT)) & PLL_ANA_PRG_WIN_PER_MASK)

#define PLL_ANA_PRG_SSC_LOCK_RELAX_DISABLE_MASK (0x100000U)
#define PLL_ANA_PRG_SSC_LOCK_RELAX_DISABLE_SHIFT (20U)
/*! SSC_LOCK_RELAX_DISABLE - SSC_LOCK_RELAX_DISABLE
 *  0b0..Enable the lock/unlock accuracy relax feature during SSCG mode
 *  0b1..Disable the lock/unlock accuracy relax feature during SSCG mode
 */
#define PLL_ANA_PRG_SSC_LOCK_RELAX_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_SSC_LOCK_RELAX_DISABLE_SHIFT)) & PLL_ANA_PRG_SSC_LOCK_RELAX_DISABLE_MASK)

#define PLL_ANA_PRG_LOCK_BYP_DELAY_MASK (0xE00000U)
#define PLL_ANA_PRG_LOCK_BYP_DELAY_SHIFT (21U)
/*! LOCK_BYP_DELAY - LOCK_BYP_DELAY
 *  0b000..128 reference clock cycles
 *  0b001..192 reference clock cycles
 *  0b010..256 reference clock cycles
 *  0b011..384 reference clock cycles
 *  0b100..512 reference clock cycles
 *  0b101..768 reference clock cycles
 *  0b110..1023 reference clock cycles
 *  0b111..64 reference clock cycles
 */
#define PLL_ANA_PRG_LOCK_BYP_DELAY(x) (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_LOCK_BYP_DELAY_SHIFT)) & PLL_ANA_PRG_LOCK_BYP_DELAY_MASK)

#define PLL_ANA_PRG_ANA_MISC_MASK   (0xFF000000U)
#define PLL_ANA_PRG_ANA_MISC_SHIFT  (24U)
/*! ANA_MISC - Analog miscellaneous bits */
#define PLL_ANA_PRG_ANA_MISC(x)     (((uint32_t)(((uint32_t)(x)) << PLL_ANA_PRG_ANA_MISC_SHIFT)) & PLL_ANA_PRG_ANA_MISC_MASK)
/*! @} */

/*! @name TEST - PLL TEST Register */
/*! @{ */

#define PLL_TEST_ANAMUX_CTRL_MASK   (0x7U)
#define PLL_TEST_ANAMUX_CTRL_SHIFT  (0U)
/*! ANAMUX_CTRL - Analog test signal selection. Valid when TEST_MUX_ENABLE is 1'b1
 *  0b000..Bring out PLL 0.8V supply voltage through the atpsense pin.
 *  0b110..Bring out PLL Vring voltage through the atpsense pin.
 *  0b001..Bring out V2I test current through the atpsense pin.
 *  0b010..Bring out Charge Pump UP Current through the atpsense pin.
 *  0b011..Bring out Charge Pump DN Current through the atpsense pin.
 *  0b101..Bring out PLL control voltage through atpsense pin.
 *  0b100..Bring out IREF test current through atpsense pin.
 *  0b111..Bring out PLL 0.8V supply voltage through the atpsense pin.
 */
#define PLL_TEST_ANAMUX_CTRL(x)     (((uint32_t)(((uint32_t)(x)) << PLL_TEST_ANAMUX_CTRL_SHIFT)) & PLL_TEST_ANAMUX_CTRL_MASK)

#define PLL_TEST_TEST_MUX_ENABLE_MASK (0x8U)
#define PLL_TEST_TEST_MUX_ENABLE_SHIFT (3U)
/*! TEST_MUX_ENABLE - TEST_MUX_ENABLE
 *  0b0..Disable TEST MUX. atpsense pin remains tristated.
 *  0b1..Enable TEST MUX. ANAMUX_CTRL values are reflected on TEST MUX.
 */
#define PLL_TEST_TEST_MUX_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << PLL_TEST_TEST_MUX_ENABLE_SHIFT)) & PLL_TEST_TEST_MUX_ENABLE_MASK)

#define PLL_TEST_OPEN_LOOP_MODE_MASK (0x100U)
#define PLL_TEST_OPEN_LOOP_MODE_SHIFT (8U)
/*! OPEN_LOOP_MODE - OPEN_LOOP_MODE
 *  0b0..Normal mode
 *  0b1..PLL is in DVS mode.
 */
#define PLL_TEST_OPEN_LOOP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << PLL_TEST_OPEN_LOOP_MODE_SHIFT)) & PLL_TEST_OPEN_LOOP_MODE_MASK)

#define PLL_TEST_MODE_MASK          (0x200U)
#define PLL_TEST_MODE_SHIFT         (9U)
/*! MODE - 1:1 MODE */
#define PLL_TEST_MODE(x)            (((uint32_t)(((uint32_t)(x)) << PLL_TEST_MODE_SHIFT)) & PLL_TEST_MODE_MASK)

#define PLL_TEST_STRESS_MODE_MASK   (0x400U)
#define PLL_TEST_STRESS_MODE_SHIFT  (10U)
/*! STRESS_MODE - STRESS_MODE
 *  0b0..Normal mode
 *  0b1..PLL is in EVS mode.
 */
#define PLL_TEST_STRESS_MODE(x)     (((uint32_t)(((uint32_t)(x)) << PLL_TEST_STRESS_MODE_SHIFT)) & PLL_TEST_STRESS_MODE_MASK)
/*! @} */

/*! @name SPREAD_SPECTRUM - PLL Spread Spectrum Register */
/*! @{ */

#define PLL_SPREAD_SPECTRUM_STEP_MASK (0x7FFFU)
#define PLL_SPREAD_SPECTRUM_STEP_SHIFT (0U)
/*! STEP - STEP */
#define PLL_SPREAD_SPECTRUM_STEP(x) (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_STEP_SHIFT)) & PLL_SPREAD_SPECTRUM_STEP_MASK)

#define PLL_SPREAD_SPECTRUM_ENABLE_MASK (0x8000U)
#define PLL_SPREAD_SPECTRUM_ENABLE_SHIFT (15U)
/*! ENABLE - ENABLE
 *  0b0..Disable spread spectrum modulation.
 *  0b1..Enable spread spectrum modulation.
 */
#define PLL_SPREAD_SPECTRUM_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_ENABLE_SHIFT)) & PLL_SPREAD_SPECTRUM_ENABLE_MASK)

#define PLL_SPREAD_SPECTRUM_STOP_MASK (0xFFFF0000U)
#define PLL_SPREAD_SPECTRUM_STOP_SHIFT (16U)
/*! STOP - Stop */
#define PLL_SPREAD_SPECTRUM_STOP(x) (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_STOP_SHIFT)) & PLL_SPREAD_SPECTRUM_STOP_MASK)
/*! @} */

/*! @name NUMERATOR - PLL Numerator Register */
/*! @{ */

#define PLL_NUMERATOR_MFN_MASK      (0xFFFFFFFCU)
#define PLL_NUMERATOR_MFN_SHIFT     (2U)
/*! MFN - Numerator */
#define PLL_NUMERATOR_MFN(x)        (((uint32_t)(((uint32_t)(x)) << PLL_NUMERATOR_MFN_SHIFT)) & PLL_NUMERATOR_MFN_MASK)
/*! @} */

/*! @name DENOMINATOR - PLL Denominator Register */
/*! @{ */

#define PLL_DENOMINATOR_MFD_MASK    (0x3FFFFFFFU)
#define PLL_DENOMINATOR_MFD_SHIFT   (0U)
/*! MFD - Denominator */
#define PLL_DENOMINATOR_MFD(x)      (((uint32_t)(((uint32_t)(x)) << PLL_DENOMINATOR_MFD_SHIFT)) & PLL_DENOMINATOR_MFD_MASK)
/*! @} */

/*! @name DIV - PLL Dividers Register */
/*! @{ */

#define PLL_DIV_ODIV_MASK           (0xFFU)
#define PLL_DIV_ODIV_SHIFT          (0U)
/*! ODIV - Output frequency divider for clock output
 *  0b00000000..Divide by 2
 *  0b00000001..Divide by 3
 *  0b00000010..Divide by 2
 *  0b00000011..Divide by 3
 *  0b00000100..Divide by 4
 *  0b00000101..Divide by 5
 *  0b00000110..Divide by 6
 *  0b00001010..Divide by 10
 *  0b10000010..Divide by 130
 *  0b11111111..Divide by 255
 */
#define PLL_DIV_ODIV(x)             (((uint32_t)(((uint32_t)(x)) << PLL_DIV_ODIV_SHIFT)) & PLL_DIV_ODIV_MASK)

#define PLL_DIV_RDIV_MASK           (0xE000U)
#define PLL_DIV_RDIV_SHIFT          (13U)
/*! RDIV - Input clock predivider
 *  0b000..Divide by 1
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 3
 *  0b100..Divide by 4
 *  0b101..Divide by 5
 *  0b110..Divide by 6
 *  0b111..Divide by 7
 */
#define PLL_DIV_RDIV(x)             (((uint32_t)(((uint32_t)(x)) << PLL_DIV_RDIV_SHIFT)) & PLL_DIV_RDIV_MASK)

#define PLL_DIV_MFI_MASK            (0x1FF0000U)
#define PLL_DIV_MFI_SHIFT           (16U)
/*! MFI - Integer portion of loop divider */
#define PLL_DIV_MFI(x)              (((uint32_t)(((uint32_t)(x)) << PLL_DIV_MFI_SHIFT)) & PLL_DIV_MFI_MASK)
/*! @} */

/*! @name NO_OF_DFS - DFS Control Register */
/*! @{ */

#define PLL_NO_OF_DFS_HW_CTRL_SEL_MASK (0x10000U)
#define PLL_NO_OF_DFS_HW_CTRL_SEL_SHIFT (16U)
/*! HW_CTRL_SEL - Hardware control select
 *  0b0..Hardware control select disable. DFS is control by register
 *  0b1..Hardware control select enable.DFS is control by hardware inputs.
 */
#define PLL_NO_OF_DFS_HW_CTRL_SEL(x) (((uint32_t)(((uint32_t)(x)) << PLL_NO_OF_DFS_HW_CTRL_SEL_SHIFT)) & PLL_NO_OF_DFS_HW_CTRL_SEL_MASK)

#define PLL_NO_OF_DFS_BYPASS_EN_MASK (0x800000U)
#define PLL_NO_OF_DFS_BYPASS_EN_SHIFT (23U)
/*! BYPASS_EN - Bypass the DFS.
 *  0b0..DFS Clock output.
 *  0b1..Bypass clock output
 */
#define PLL_NO_OF_DFS_BYPASS_EN(x)  (((uint32_t)(((uint32_t)(x)) << PLL_NO_OF_DFS_BYPASS_EN_SHIFT)) & PLL_NO_OF_DFS_BYPASS_EN_MASK)

#define PLL_NO_OF_DFS_CLKOUT_DIVBY2_EN_MASK (0x20000000U)
#define PLL_NO_OF_DFS_CLKOUT_DIVBY2_EN_SHIFT (29U)
/*! CLKOUT_DIVBY2_EN - Enable the DFS divide by 2 output clock.
 *  0b0..DFS divide by 2 clock output is disable.
 *  0b1..DFS divide by 2 clock output is enable
 */
#define PLL_NO_OF_DFS_CLKOUT_DIVBY2_EN(x) (((uint32_t)(((uint32_t)(x)) << PLL_NO_OF_DFS_CLKOUT_DIVBY2_EN_SHIFT)) & PLL_NO_OF_DFS_CLKOUT_DIVBY2_EN_MASK)

#define PLL_NO_OF_DFS_CLKOUT_EN_MASK (0x40000000U)
#define PLL_NO_OF_DFS_CLKOUT_EN_SHIFT (30U)
/*! CLKOUT_EN - Enable the DFS output clock.
 *  0b0..DFS Clock output is disable.
 *  0b1..DFS Clock output is enable
 */
#define PLL_NO_OF_DFS_CLKOUT_EN(x)  (((uint32_t)(((uint32_t)(x)) << PLL_NO_OF_DFS_CLKOUT_EN_SHIFT)) & PLL_NO_OF_DFS_CLKOUT_EN_MASK)

#define PLL_NO_OF_DFS_ENABLE_MASK   (0x80000000U)
#define PLL_NO_OF_DFS_ENABLE_SHIFT  (31U)
/*! ENABLE - Enable the DFS Block.
 *  0b0..DFS block is disable.
 *  0b1..DFS block is enable
 */
#define PLL_NO_OF_DFS_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << PLL_NO_OF_DFS_ENABLE_SHIFT)) & PLL_NO_OF_DFS_ENABLE_MASK)
/*! @} */

/*! @name NO_OF_DFS - DFS Division Register */
/*! @{ */

#define PLL_NO_OF_DFS_MFN_MASK      (0x7U)
#define PLL_NO_OF_DFS_MFN_SHIFT     (0U)
#define PLL_NO_OF_DFS_MFN(x)        (((uint32_t)(((uint32_t)(x)) << PLL_NO_OF_DFS_MFN_SHIFT)) & PLL_NO_OF_DFS_MFN_MASK)

#define PLL_NO_OF_DFS_MFI_MASK      (0xFF00U)
#define PLL_NO_OF_DFS_MFI_SHIFT     (8U)
#define PLL_NO_OF_DFS_MFI(x)        (((uint32_t)(((uint32_t)(x)) << PLL_NO_OF_DFS_MFI_SHIFT)) & PLL_NO_OF_DFS_MFI_MASK)
/*! @} */

/*! @name PLL_STATUS - PLL Status Register */
/*! @{ */

#define PLL_PLL_STATUS_PLL_LOCK_MASK (0x1U)
#define PLL_PLL_STATUS_PLL_LOCK_SHIFT (0U)
/*! PLL_LOCK - PLL_LOCK */
#define PLL_PLL_STATUS_PLL_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << PLL_PLL_STATUS_PLL_LOCK_SHIFT)) & PLL_PLL_STATUS_PLL_LOCK_MASK)

#define PLL_PLL_STATUS_PLL_LOL_MASK (0x2U)
#define PLL_PLL_STATUS_PLL_LOL_SHIFT (1U)
/*! PLL_LOL - PLL_LOL */
#define PLL_PLL_STATUS_PLL_LOL(x)   (((uint32_t)(((uint32_t)(x)) << PLL_PLL_STATUS_PLL_LOL_SHIFT)) & PLL_PLL_STATUS_PLL_LOL_MASK)

#define PLL_PLL_STATUS_ANA_MFN_MASK (0xFFFFFFFCU)
#define PLL_PLL_STATUS_ANA_MFN_SHIFT (2U)
/*! ANA_MFN - ANA_MFN */
#define PLL_PLL_STATUS_ANA_MFN(x)   (((uint32_t)(((uint32_t)(x)) << PLL_PLL_STATUS_ANA_MFN_SHIFT)) & PLL_PLL_STATUS_ANA_MFN_MASK)
/*! @} */

/*! @name DFS_STATUS - DFS Status Register */
/*! @{ */

#define PLL_DFS_STATUS_DFS_OK_MASK  (0x7U)
#define PLL_DFS_STATUS_DFS_OK_SHIFT (0U)
/*! DFS_OK - Status of clockout ok signal.
 *  0b000..The corresponding dfs output clock is not valid.
 *  0b001..The corresponding dfs output clock is valid.
 */
#define PLL_DFS_STATUS_DFS_OK(x)    (((uint32_t)(((uint32_t)(x)) << PLL_DFS_STATUS_DFS_OK_SHIFT)) & PLL_DFS_STATUS_DFS_OK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PLL_Register_Masks */


/* PLL - Peripheral instance base addresses */
/** Peripheral SYS_PLL1 base address */
#define SYS_PLL1_BASE               (0x44481000u)
/** Peripheral SYS_PLL1 base pointer */
#define SYS_PLL1                    ((PLL_Type *)SYS_PLL1_BASE)
/** Peripheral AUDIO_PLL1 base address */
#define AUDIO_PLL1_BASE             (0x44481100u)
/** Peripheral AUDIO_PLL1 base pointer */
#define AUDIO_PLL1                  ((PLL_Type *)AUDIO_PLL1_BASE)
/** Peripheral AUDIO_PLL2 base address */
#define AUDIO_PLL2_BASE             (0x44481200u)
/** Peripheral AUDIO_PLL2 base pointer */
#define AUDIO_PLL2                  ((PLL_Type *)AUDIO_PLL2_BASE)
/** Peripheral VIDEO_PLL1 base address */
#define VIDEO_PLL1_BASE             (0x44481300u)
/** Peripheral VIDEO_PLL1 base pointer */
#define VIDEO_PLL1                  ((PLL_Type *)VIDEO_PLL1_BASE)
/** Peripheral ARM_PLL base address */
#define ARM_PLL_BASE                (0x44481600u)
/** Peripheral ARM_PLL base pointer */
#define ARM_PLL                     ((PLL_Type *)ARM_PLL_BASE)
/** Peripheral DRAM_PLL base address */
#define DRAM_PLL_BASE               (0x44481700u)
/** Peripheral DRAM_PLL base pointer */
#define DRAM_PLL                    ((PLL_Type *) DRAM_PLL_BASE)
/** Peripheral HSIO_PLL base address */
#define HSIO_PLL_BASE               (0x44481800u)
/** Peripheral HSIO_PLL base pointer */
#define HSIO_PLL                    ((PLL_Type *) HSIO_PLL_BASE)
/** Peripheral LDB_PLL base address */
#define LDB_PLL_BASE                (0x44481900u)
/** Peripheral LDB_PLL base pointer */
#define LDB_PLL                     ((PLL_Type *)LDB_PLL_BASE)


/** Array initializer of PLL peripheral base addresses */
#define PLL_BASE_ADDRS              { SYS_PLL1_BASE, AUDIO_PLL1_BASE, AUDIO_PLL2_BASE, VIDEO_PLL1_BASE, ARM_PLL_BASE, DRAM_PLL_BASE, HSIO_PLL_BASE, LDB_PLL_BASE }
/** Array initializer of PLL peripheral base pointers */
#define PLL_BASE_PTRS               { SYS_PLL1, AUDIO_PLL1, AUDIO_PLL2, VIDEO_PLL1, ARM_PLL, DRAM_PLL, HSIO_PLL, LDB_PLL }

/*!
 * @}
 */ /* end of group PLL_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_PLL_H_) */
