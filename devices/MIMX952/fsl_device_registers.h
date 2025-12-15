/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2026 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __FSL_DEVICE_REGISTERS_H__
#define __FSL_DEVICE_REGISTERS_H__

#define CPU_MIMX95294AVTN_cm33

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */
#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7.h"
#else
#error "No valid CPU defined!"
#endif

#include "MIMX952_elec_spec.h"

/* Interrupt mapping */
#define CM7_SYSRESETREQ_IRQn RESERVED183_IRQn
#define CM7_LOCKUP_IRQn RESERVED184_IRQn
#define GPC_SM_REQ_IRQn LP_HDSK_GSKT_IRQn
#define TMPSNS_ANA_1_IRQn RESERVED96_IRQn
#define TMPSNS_ANA_2_IRQn RESERVED97_IRQn
#define TMPSNS_CORTEXA_1_IRQ RESERVED99_IRQn
#define TMPSNS_CORTEXA_2_IRQ RESERVED100_IRQn
#define FCCU_INT0_IRQn RESERVED226_IRQn
#define ELE_Group1_IRQn RESERVED176_IRQn
#define ELE_Group2_IRQn RESERVED177_IRQn
#define ELE_Group3_IRQn RESERVED178_IRQn

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
