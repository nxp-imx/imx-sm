/*
** ###################################################################
**     Processors:          MIMX95_cm33
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX95RM, Internal, November. 2021
**     Version:             rev. 1.0, 2021-11-16
**     Build:               b220818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX95_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-11-16)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MIMX95_MCM.h
 * @version 1.0
 * @date 2021-11-16
 * @brief CMSIS Peripheral Access Layer for MIMX95_MCM
 *
 * CMSIS Peripheral Access Layer for MIMX95
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_MCM_H_)  /* Check if memory map has not been already included */
#define MIMX95_MCM_H_

#include "MIMX95_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Register Layout Typedef */
typedef struct
{
    __I uint16_t PCT;   /**< Processor Core Type, offset: 0x0 */
    __I uint16_t PLREV; /**< SoC-defined Platform Revision, offset: 0x2 */
    uint8_t RESERVED_0[12];
    __IO uint32_t ISCR;  /**< Interrupt Status and Control, offset: 0x10 */
    __IO uint32_t ETBCC; /**< ETB Counter Control, offset: 0x14 */
    __IO uint32_t ETBRR; /**< ETB Reload, offset: 0x18 */
    __I uint32_t ETBCV;  /**< ETB Counter Value, offset: 0x1C */
    __I uint32_t FADR;   /**< Store Buffer Fault Address, offset: 0x20 */
    __I uint32_t FATR;   /**< Store Buffer Fault Attributes, offset: 0x24 */
    __I uint32_t FDR;    /**< Store Buffer Fault Data, offset: 0x28 */
} MCM_Type;

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/*! @name PCT - Processor Core Type */
/*! @{ */

#define MCM_PCT_PCT_MASK  (0xFFFFU)
#define MCM_PCT_PCT_SHIFT (0U)
/*! PCT - This MCM design supports the Arm Cortex core. The following value identifies this core complex.
 */
#define MCM_PCT_PCT(x) (((uint16_t)(((uint16_t)(x)) << MCM_PCT_PCT_SHIFT)) & MCM_PCT_PCT_MASK)
/*! @} */

/*! @name PLREV - SoC-defined Platform Revision */
/*! @{ */

#define MCM_PLREV_PLREV_MASK  (0xFFFFU)
#define MCM_PLREV_PLREV_SHIFT (0U)
/*! PLREV - The PLREV[15:0] field is specified by an platform input signal to define a software-visible revision number.
 */
#define MCM_PLREV_PLREV(x) (((uint16_t)(((uint16_t)(x)) << MCM_PLREV_PLREV_SHIFT)) & MCM_PLREV_PLREV_MASK)
/*! @} */

/*! @name ISCR - Interrupt Status and Control */
/*! @{ */

#define MCM_ISCR_IRQ_MASK  (0x2U)
#define MCM_ISCR_IRQ_SHIFT (1U)
/*! IRQ - ETB related interrupt pending
 *  0b0..No Pending IRQ.
 *  0b1..Due to the ETB counter expiring, an IRQ is pending.
 */
#define MCM_ISCR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_IRQ_SHIFT)) & MCM_ISCR_IRQ_MASK)

#define MCM_ISCR_NMI_MASK  (0x4U)
#define MCM_ISCR_NMI_SHIFT (2U)
/*! NMI - Non-maskable Interrupt Pending
 *  0b0..No pending NMI.
 *  0b1..Due to the ETB counter expiring, an NMI is pending.
 */
#define MCM_ISCR_NMI(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_NMI_SHIFT)) & MCM_ISCR_NMI_MASK)

#define MCM_ISCR_DHREQ_MASK  (0x8U)
#define MCM_ISCR_DHREQ_SHIFT (3U)
/*! DHREQ - Debug Halt Request Indicator
 *  0b0..No debug halt request is initiated
 *  0b1..Debug halt request is initiated
 */
#define MCM_ISCR_DHREQ(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_DHREQ_SHIFT)) & MCM_ISCR_DHREQ_MASK)

#define MCM_ISCR_CWBER_MASK  (0x10U)
#define MCM_ISCR_CWBER_SHIFT (4U)
/*! CWBER - Cache Write Buffer Error Status
 *  0b0..No error
 *  0b1..Error occurred
 */
#define MCM_ISCR_CWBER(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_CWBER_SHIFT)) & MCM_ISCR_CWBER_MASK)

#define MCM_ISCR_FIOC_MASK  (0x100U)
#define MCM_ISCR_FIOC_SHIFT (8U)
/*! FIOC - FPU Invalid Operation Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIOC(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOC_SHIFT)) & MCM_ISCR_FIOC_MASK)

#define MCM_ISCR_FDZC_MASK  (0x200U)
#define MCM_ISCR_FDZC_SHIFT (9U)
/*! FDZC - FPU Divide-by-zero Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FDZC(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZC_SHIFT)) & MCM_ISCR_FDZC_MASK)

#define MCM_ISCR_FOFC_MASK  (0x400U)
#define MCM_ISCR_FOFC_SHIFT (10U)
/*! FOFC - FPU Overflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FOFC(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFC_SHIFT)) & MCM_ISCR_FOFC_MASK)

#define MCM_ISCR_FUFC_MASK  (0x800U)
#define MCM_ISCR_FUFC_SHIFT (11U)
/*! FUFC - FPU Underflow Interrupt status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FUFC(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFC_SHIFT)) & MCM_ISCR_FUFC_MASK)

#define MCM_ISCR_FIXC_MASK  (0x1000U)
#define MCM_ISCR_FIXC_SHIFT (12U)
/*! FIXC - FPU Inexact Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIXC(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXC_SHIFT)) & MCM_ISCR_FIXC_MASK)

#define MCM_ISCR_FIDC_MASK  (0x8000U)
#define MCM_ISCR_FIDC_SHIFT (15U)
/*! FIDC - FPU Input Denormal Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIDC(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDC_SHIFT)) & MCM_ISCR_FIDC_MASK)

#define MCM_ISCR_CWBEE_MASK  (0x100000U)
#define MCM_ISCR_CWBEE_SHIFT (20U)
/*! CWBEE - Cache Write Buffer Error Enable
 *  0b0..Disable error interrupt
 *  0b1..Enable error interrupt
 */
#define MCM_ISCR_CWBEE(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_CWBEE_SHIFT)) & MCM_ISCR_CWBEE_MASK)

#define MCM_ISCR_FIOCE_MASK  (0x1000000U)
#define MCM_ISCR_FIOCE_SHIFT (24U)
/*! FIOCE - FPU Invalid Operation Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIOCE(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOCE_SHIFT)) & MCM_ISCR_FIOCE_MASK)

#define MCM_ISCR_FDZCE_MASK  (0x2000000U)
#define MCM_ISCR_FDZCE_SHIFT (25U)
/*! FDZCE - FPU Divide-by-zero Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FDZCE(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZCE_SHIFT)) & MCM_ISCR_FDZCE_MASK)

#define MCM_ISCR_FOFCE_MASK  (0x4000000U)
#define MCM_ISCR_FOFCE_SHIFT (26U)
/*! FOFCE - FPU Overflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FOFCE(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFCE_SHIFT)) & MCM_ISCR_FOFCE_MASK)

#define MCM_ISCR_FUFCE_MASK  (0x8000000U)
#define MCM_ISCR_FUFCE_SHIFT (27U)
/*! FUFCE - FPU Underflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FUFCE(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFCE_SHIFT)) & MCM_ISCR_FUFCE_MASK)

#define MCM_ISCR_FIXCE_MASK  (0x10000000U)
#define MCM_ISCR_FIXCE_SHIFT (28U)
/*! FIXCE - FPU Inexact Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIXCE(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXCE_SHIFT)) & MCM_ISCR_FIXCE_MASK)

#define MCM_ISCR_FIDCE_MASK  (0x80000000U)
#define MCM_ISCR_FIDCE_SHIFT (31U)
/*! FIDCE - FPU Input Denormal Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIDCE(x) (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDCE_SHIFT)) & MCM_ISCR_FIDCE_MASK)
/*! @} */

/*! @name ETBCC - ETB Counter Control */
/*! @{ */

#define MCM_ETBCC_CNTEN_MASK  (0x1U)
#define MCM_ETBCC_CNTEN_SHIFT (0U)
/*! CNTEN - Counter Enable
 *  0b0..ETB counter is disabled
 *  0b1..ETB counter is enabled
 */
#define MCM_ETBCC_CNTEN(x) (((uint32_t)(((uint32_t)(x)) << MCM_ETBCC_CNTEN_SHIFT)) & MCM_ETBCC_CNTEN_MASK)

#define MCM_ETBCC_RSPT_MASK  (0x6U)
#define MCM_ETBCC_RSPT_SHIFT (1U)
/*! RSPT - Response Type
 *  0b00..No response when the ETB count expires
 *  0b01..Generate a normal interrupt when the ETB count expires
 *  0b10..Generate an NMI when the ETB count expires
 *  0b11..Generate a debug halt when the ETB count expires
 */
#define MCM_ETBCC_RSPT(x) (((uint32_t)(((uint32_t)(x)) << MCM_ETBCC_RSPT_SHIFT)) & MCM_ETBCC_RSPT_MASK)

#define MCM_ETBCC_RLRQ_MASK  (0x8U)
#define MCM_ETBCC_RLRQ_SHIFT (3U)
/*! RLRQ - Reload Request
 *  0b0..No effect
 *  0b1..Clear pending debug halt, NMI, or IRQ interrupt requests
 */
#define MCM_ETBCC_RLRQ(x) (((uint32_t)(((uint32_t)(x)) << MCM_ETBCC_RLRQ_SHIFT)) & MCM_ETBCC_RLRQ_MASK)
/*! @} */

/*! @name ETBRR - ETB Reload */
/*! @{ */

#define MCM_ETBRR_RELOAD_MASK  (0x7FFU)
#define MCM_ETBRR_RELOAD_SHIFT (0U)
/*! RELOAD - Byte Count Reload Value
 */
#define MCM_ETBRR_RELOAD(x) (((uint32_t)(((uint32_t)(x)) << MCM_ETBRR_RELOAD_SHIFT)) & MCM_ETBRR_RELOAD_MASK)
/*! @} */

/*! @name ETBCV - ETB Counter Value */
/*! @{ */

#define MCM_ETBCV_COUNTER_MASK  (0x7FFU)
#define MCM_ETBCV_COUNTER_SHIFT (0U)
/*! COUNTER - Byte Count Counter Value
 */
#define MCM_ETBCV_COUNTER(x) (((uint32_t)(((uint32_t)(x)) << MCM_ETBCV_COUNTER_SHIFT)) & MCM_ETBCV_COUNTER_MASK)
/*! @} */

/*! @name FADR - Store Buffer Fault Address */
/*! @{ */

#define MCM_FADR_ADDRESS_MASK  (0xFFFFFFFFU)
#define MCM_FADR_ADDRESS_SHIFT (0U)
/*! ADDRESS - Fault address
 */
#define MCM_FADR_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << MCM_FADR_ADDRESS_SHIFT)) & MCM_FADR_ADDRESS_MASK)
/*! @} */

/*! @name FATR - Store Buffer Fault Attributes */
/*! @{ */

#define MCM_FATR_BEDA_MASK  (0x1U)
#define MCM_FATR_BEDA_SHIFT (0U)
/*! BEDA - Bus Error Data Access Type
 *  0b0..Instruction
 *  0b1..Data
 */
#define MCM_FATR_BEDA(x) (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEDA_SHIFT)) & MCM_FATR_BEDA_MASK)

#define MCM_FATR_BEMD_MASK  (0x2U)
#define MCM_FATR_BEMD_SHIFT (1U)
/*! BEMD - Bus Error Privilege level
 *  0b0..User mode
 *  0b1..Supervisor/privileged mode
 */
#define MCM_FATR_BEMD(x) (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEMD_SHIFT)) & MCM_FATR_BEMD_MASK)

#define MCM_FATR_BESZ_MASK  (0x30U)
#define MCM_FATR_BESZ_SHIFT (4U)
/*! BESZ - Bus Error Size
 *  0b00..8-bit access
 *  0b01..16-bit access
 *  0b10..32-bit access
 *  0b11..Reserved
 */
#define MCM_FATR_BESZ(x) (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BESZ_SHIFT)) & MCM_FATR_BESZ_MASK)

#define MCM_FATR_BEWT_MASK  (0x80U)
#define MCM_FATR_BEWT_SHIFT (7U)
/*! BEWT - Bus Error Write
 *  0b0..Read access
 *  0b1..Write access
 */
#define MCM_FATR_BEWT(x) (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEWT_SHIFT)) & MCM_FATR_BEWT_MASK)

#define MCM_FATR_BEMN_MASK  (0xF00U)
#define MCM_FATR_BEMN_SHIFT (8U)
/*! BEMN - Bus Error Master Number
 */
#define MCM_FATR_BEMN(x) (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEMN_SHIFT)) & MCM_FATR_BEMN_MASK)

#define MCM_FATR_BEOVR_MASK  (0x80000000U)
#define MCM_FATR_BEOVR_SHIFT (31U)
/*! BEOVR - Bus Error Overrun
 *  0b0..No bus error overrun
 *  0b1..Bus error overrun occurred. The FADR and FDR registers and the other FATR bits will not be updated to reflect
 * this new bus error.
 */
#define MCM_FATR_BEOVR(x) (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEOVR_SHIFT)) & MCM_FATR_BEOVR_MASK)
/*! @} */

/*! @name FDR - Store Buffer Fault Data */
/*! @{ */

#define MCM_FDR_DATA_MASK  (0xFFFFFFFFU)
#define MCM_FDR_DATA_SHIFT (0U)
/*! DATA - Fault Data
 */
#define MCM_FDR_DATA(x) (((uint32_t)(((uint32_t)(x)) << MCM_FDR_DATA_SHIFT)) & MCM_FDR_DATA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MCM_Register_Masks */

/* MCM - Peripheral instance base addresses */
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE & 0x2))
/** Peripheral PPB_MCM2_CM4 base address */
#define PPB_MCM2_CM4_BASE (0xF0080000u)
/** Peripheral PPB_MCM2_CM4 base address */
#define PPB_MCM2_CM4_BASE_NS (0xE0080000u)
/** Peripheral PPB_MCM2_CM4 base pointer */
#define PPB_MCM2_CM4 ((MCM_Type *)PPB_MCM2_CM4_BASE)
/** Peripheral PPB_MCM2_CM4 base pointer */
#define PPB_MCM2_CM4_NS ((MCM_Type *)PPB_MCM2_CM4_BASE_NS)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS    \
    {                     \
        PPB_MCM2_CM4_BASE \
    }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS \
    {                 \
        PPB_MCM2_CM4  \
    }
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS_NS    \
    {                        \
        PPB_MCM2_CM4_BASE_NS \
    }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS_NS \
    {                    \
        PPB_MCM2_CM4_NS  \
    }
#else
/** Peripheral PPB_MCM2_CM4 base address */
#define PPB_MCM2_CM4_BASE (0xE0080000u)
/** Peripheral PPB_MCM2_CM4 base pointer */
#define PPB_MCM2_CM4      ((MCM_Type *)PPB_MCM2_CM4_BASE)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS    \
    {                     \
        PPB_MCM2_CM4_BASE \
    }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS \
    {                 \
        PPB_MCM2_CM4  \
    }
#endif

/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */

#endif  /* #if !defined(MIMX95_MCM_H_) */
