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
 * @file MIMX95_BLK_CTRL_BBSMIX.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for MIMX95_BLK_CTRL_BBSMIX
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_BLK_CTRL_BBSMIX_H_)  /* Check if memory map has not been already included */
#define MIMX95_BLK_CTRL_BBSMIX_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_BBSMMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_BBSMMIX_Peripheral_Access_Layer BLK_CTRL_BBSMMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_BBSMMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t SXOSC_CTRL;                        /**< SXOSC Control Register, offset: 0x0 */
  __IO uint32_t SNVS_CLKRST_CTRL;                  /**< snvs_clkrst Control Register, offset: 0x4 */
} BLK_CTRL_BBSMMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_BBSMMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_BBSMMIX_Register_Masks BLK_CTRL_BBSMMIX Register Masks
 * @{
 */

/*! @name SXOSC_CTRL - SXOSC Control Register */
/*! @{ */

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_CUR_PRG_MASK (0xEU)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_CUR_PRG_SHIFT (1U)
/*! cur_prg - Controls the tail current of comparator */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_CUR_PRG(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_CUR_PRG_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_CUR_PRG_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_GM_SEL_LV_MASK (0x70U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_GM_SEL_LV_SHIFT (4U)
/*! gm_sel_lv - Controls transconductance of GM stage
 *  0b000..2.9 uS
 *  0b001..8.9 uS
 *  0b010..17 uS
 *  0b011..26 uS
 *  0b100..35 uS
 *  0b101..43 uS
 *  0b110..52 uS
 *  0b111..61.7 uS
 */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_GM_SEL_LV(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_GM_SEL_LV_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_GM_SEL_LV_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_GM_TEST_SEL_LV_MASK (0x80U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_GM_TEST_SEL_LV_SHIFT (7U)
/*! gm_test_sel_lv - Enables GM testing in bench
 *  0b0..GM testing disable
 *  0b1..GM testing enable
 */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_GM_TEST_SEL_LV(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_GM_TEST_SEL_LV_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_GM_TEST_SEL_LV_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_CTRL0_IN_LV_MASK (0x100U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_CTRL0_IN_LV_SHIFT (8U)
/*! misc_ctrl0_in_lv - Miscellaneous control 0 input
 *  0b1..Miscellaneous control enable
 *  0b0..Miscellaneous control disable
 */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_CTRL0_IN_LV(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_CTRL0_IN_LV_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_CTRL0_IN_LV_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_CTRL1_IN_LV_MASK (0x200U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_CTRL1_IN_LV_SHIFT (9U)
/*! misc_ctrl1_in_lv - Miscellaneous control 1 input
 *  0b0..Miscellaneous control disable
 *  0b1..Miscellaneous control enable
 */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_CTRL1_IN_LV(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_CTRL1_IN_LV_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_CTRL1_IN_LV_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_TEST0_IN_LV_MASK (0x400U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_TEST0_IN_LV_SHIFT (10U)
/*! misc_test0_in_lv - Miscellaneous test 0 input
 *  0b1..Miscellaneous test enable
 *  0b0..Miscellaneous test disable
 */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_TEST0_IN_LV(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_TEST0_IN_LV_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_TEST0_IN_LV_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_TEST1_IN_LV_MASK (0x800U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_TEST1_IN_LV_SHIFT (11U)
/*! misc_test1_in_lv - Miscellaneous test 1 input
 *  0b0..Miscellaneous test disable
 *  0b1..Miscellaneous test enable
 */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_TEST1_IN_LV(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_TEST1_IN_LV_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_MISC_TEST1_IN_LV_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_OSC_TEST_MUX_EN_MASK (0x1000U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_OSC_TEST_MUX_EN_SHIFT (12U)
/*! osc_test_mux_en - OSC test mux input
 *  0b0..OSC test mux disable
 *  0b1..OSC test mux enable
 */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_OSC_TEST_MUX_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_OSC_TEST_MUX_EN_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_OSC_TEST_MUX_EN_MASK)

#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_PWD_LV_MASK (0x10000U)
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_PWD_LV_SHIFT (16U)
/*! pwd_lv - Power down/enable signal
 *  0b0..Power up
 *  0b1..Power down
 */
#define BLK_CTRL_BBSMMIX_SXOSC_CTRL_PWD_LV(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SXOSC_CTRL_PWD_LV_SHIFT)) & BLK_CTRL_BBSMMIX_SXOSC_CTRL_PWD_LV_MASK)
/*! @} */

/*! @name SNVS_CLKRST_CTRL - snvs_clkrst Control Register */
/*! @{ */

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_CLK_TRIM_MASK (0xFU)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_CLK_TRIM_SHIFT (0U)
/*! clk_trim - Internal oscillator clock trim
 *  0b1000..22.31 kHz
 *  0b1001..23.15 kHz
 *  0b1010..24.07 kHz
 *  0b1011..25.07 kHz
 *  0b1100..26.16 kHz
 *  0b1101..27.35 kHz
 *  0b1110..28.65 kHz
 *  0b1111..30.07 kHz
 *  0b0000..31.64 kHz
 *  0b0001..33.4 kHz
 *  0b0010..35.36 kHz
 *  0b0011..37.58 kHz
 *  0b0100..40.08 kHz
 *  0b0101..43 kHz
 *  0b0110..46.32 kHz
 *  0b0111..50.27 kHz
 */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_CLK_TRIM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_CLK_TRIM_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_CLK_TRIM_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TEST_SEL_MASK (0xF0U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TEST_SEL_SHIFT (4U)
/*! test_sel - Test select inputs
 *  0b0001..Test clock bypass mode
 *  0b0000..Function mode
 *  0b0100..Reference current test
 *  0b0010..Reference voltage test
 */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TEST_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TEST_SEL_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TEST_SEL_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_VREG_ENB_MASK (0x100U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_VREG_ENB_SHIFT (8U)
/*! vreg_enb - SNVS core regulator control
 *  0b0..SNVS core regulator enable
 *  0b1..SNVS core regulator disable
 */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_VREG_ENB(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_VREG_ENB_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_VREG_ENB_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_VREG_TRIM_MASK (0x1E00U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_VREG_TRIM_SHIFT (9U)
/*! vreg_trim - Voltage regulator trim
 *  0b0110..730 mV
 *  0b0111..742 mV
 *  0b0100..754 mV
 *  0b0101..766 mV
 *  0b0010..778 mV
 *  0b0011..790 mV
 *  0b0000..802 mV
 *  0b0001..814 mV
 *  0b1110..826 mV
 *  0b1111..838 mV
 *  0b1100..850 mV
 *  0b1101..862 mV
 *  0b1010..874 mV
 *  0b1011..886 mV
 *  0b1000..898 mV
 *  0b1001..910 mV
 */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_VREG_TRIM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_VREG_TRIM_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_VREG_TRIM_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TST_XTAL_FAST_MASK (0x2000U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TST_XTAL_FAST_SHIFT (13U)
/*! tst_xtal_fast - Indicates fast external XTAL crystal
 *  0b0..Fast external XTAL crystal disable
 *  0b1..Fast external XTAL crystal enable
 */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TST_XTAL_FAST(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TST_XTAL_FAST_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TST_XTAL_FAST_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TST_XTAL_SLOW_MASK (0x4000U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TST_XTAL_SLOW_SHIFT (14U)
/*! tst_xtal_slow - Indicates slow external XTAL crystal
 *  0b1..Slow external XTAL crystal enable
 *  0b0..Slow external XTAL crystal disable
 */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TST_XTAL_SLOW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TST_XTAL_SLOW_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_TST_XTAL_SLOW_MASK)

#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_XTAL_OK_MASK (0x8000U)
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_XTAL_OK_SHIFT (15U)
/*! xtal_ok - Indicates XTAL clock is in frequency range and source of 32 kHz clock
 *  0b0..XTAL clock is not in frequency range and source of 32 KHz clock
 *  0b1..XTAL clock is in frequency range and source of 32 KHz clock
 */
#define BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_XTAL_OK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_XTAL_OK_SHIFT)) & BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_XTAL_OK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_BBSMMIX_Register_Masks */


/* BLK_CTRL_BBSMMIX - Peripheral instance base addresses */
/** Peripheral BLK_CTRL_BBSMMIX_BBSMMIX1 base address */
#define BLK_CTRL_BBSMMIX_BBSMMIX1_BASE     (0x44410000u)
/** Peripheral BLK_CTRL_BBSMMIX_BBSMMIX1 base pointer */
#define BLK_CTRL_BBSMMIX_BBSMMIX1          ((BLK_CTRL_BBSMMIX_Type *)BLK_CTRL_BBSMMIX_BBSMMIX1_BASE)
/** Array initializer of BLK_CTRL_BBSMMIX peripheral base addresses */
#define BLK_CTRL_BBSMMIX_BASE_ADDRS         { BLK_CTRL_BBSMMIX_BBSMMIX1_BASE }
/** Array initializer of BLK_CTRL_BBSMMIX peripheral base pointers */
#define BLK_CTRL_BBSMMIX_BASE_PTRS          { BLK_CTRL_BBSMMIX_BBSMMIX1 }

/*!
 * @}
 */ /* end of group BLK_CTRL_BBSMIX_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_BLK_CTRL_BBSMIX_H_) */
