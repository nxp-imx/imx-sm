/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2026 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __FSL_DEVICE_REGISTERS_H__
#define __FSL_DEVICE_REGISTERS_H__

#define CPU_MIMX9375xxVZx_cm33

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */
#if (defined(CPU_MIMX9375xxVTx_ca55) || defined(CPU_MIMX9375xxVZx_ca55))
#include "MIMX9375_ca55.h"
#elif (defined(CPU_MIMX9375xxVTx_cm33) || defined(CPU_MIMX9375xxVZx_cm33))
#include "MIMX9375_cm33.h"
#elif (defined(CPU_MIMX9375xxVTx_cm7) || defined(CPU_MIMX9375xxVZx_cm7))
#include "MIMX9375_cm7.h"
#else
  #error "No valid CPU defined!"
#endif

#include "MIMX9375_elec_spec.h"

/* Interrupt mapping */
#define CM7_SYSRESETREQ_IRQn SYSREQRST_CM7_IRQn
#define CM7_LOCKUP_IRQn LOCKUP_CM7_IRQn
#define GPC_SM_REQ_IRQn LP_HDSK_GSKT_IRQn
#define TMPSNS_ANA_1_IRQn TMPSNS1_THR1_IRQn
#define TMPSNS_ANA_2_IRQn TMPSNS1_THR2_IRQn
#define TMPSNS_CORTEXA_1_IRQ TMPSNS2_THR1_IRQn
#define TMPSNS_CORTEXA_2_IRQ TMPSNS2_THR2_IRQn
#define FCCU_INT0_IRQn FCCU0_IRQn
#define ELE_Group1_IRQn ELE_GROUP1_IRQn
#define ELE_Group2_IRQn ELE_GROUP2_IRQn
#define ELE_Group3_IRQn ELE_GROUP3_IRQn

/* SWI mapping */
#define SWI_0_IRQn RESERVED64_IRQn

/* Additional base addresses */
#define MU_ELE0      ((MU_Type *)MU_ELE0_BASE)
#define MU_ELE0_BASE (0x47520000u)
#define DDR_PHY_BASE (0x5E800000u)

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
