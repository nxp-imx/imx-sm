/*
** ###################################################################
**
** Copyright 2025-2026 NXP
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** o Redistributions of source code must retain the above copyright notice, this list
**   of conditions and the following disclaimer.
**
** o Redistributions in binary form must reproduce the above copyright notice, this
**   list of conditions and the following disclaimer in the documentation and/or
**   other materials provided with the distribution.
**
** o Neither the name of the copyright holder nor the names of its
**   contributors may be used to endorse or promote products derived from this
**   software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
** ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
** ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

#ifndef TEST_DEV_H
#define TEST_DEV_H

/* Includes */

#include "MIMX94_SRC_GEN.h"

/* Defines */

#define ROM_CONTAINER_1                 0x55CCU
#define ROM_CONTAINER_2                 0xAA33U
#define MAX_MISC_BRD_CTRL_ID            0x8009

#define FUSA_LM_SAFE_TYPE_ERROR         10U
#define DEV_SM_FAULT_TEST_0             DEV_SM_FAULT_SWNCF02

#define HANDLER_TEST

#define NMI_INT_TRIGGER                 NonMaskableInt_IRQn
#define HARD_FAULT_INT_TRIGGER          HardFault_IRQn
#define MEM_MANAGEMENT_FAULT_INT        MemoryManagement_IRQn
#define BUS_FAULT_INT_TRIGGER           BusFault_IRQn
#define USAGE_FAULT_INT_TRIGGER         UsageFault_IRQn
#define PEND_SV_SET_INT_TRIGGER         PendSV_IRQn
#define WDOG1_IRQ_HANDLER               WDOG1_IRQn
#define WDOG2_IRQ_HANDLER               WDOG2_IRQn
#define WDOG3_IRQ_HANDLER               WDOG3_IRQn
#define WDOG4_IRQ_HANDLER               WDOG4_IRQn
#define WDOG5_IRQ_HANDLER               WDOG5_IRQn
#define WDOG6_IRQ_HANDLER               WDOG6_IRQn
#define WDOG7_IRQ_HANDLER               WDOG7_IRQn
#define WDOG8_IRQ_HANDLER               WDOG8_IRQn
#define TMPSNS_ANA1_IRQ_HANDLER         TMPSNS_ANA_1_IRQn
#define TMPSNS_ANA2_IRQ_HANDLER         TMPSNS_ANA_2_IRQn
#define TMPSNS_CRTX1_IRQ_HANDLER        TMPSNS_CORTEXA_1_IRQ
#define TMPSNS_CRTX2_IRQ_HANDLER        TMPSNS_CORTEXA_2_IRQ
#define ELE_GRP1_IRQ_HANDLER            ELE_Group1_IRQn
#define ELE_GRP2_IRQ_HANDLER            ELE_Group2_IRQn
#define ELE_GRP3_IRQ_HANDLER            ELE_Group3_IRQn
#define CM7_RESET_IRQ_HANDLER           CM7_0_SYSRESETREQ_IRQn
#define CM7_LOCKUP_IRQ_HANDLER          CM7_0_LOCKUP_IRQn
#define CM71_RESET_IRQ_HANDLER          CM7_1_SYSRESETREQ_IRQn
#define CM71_LOCKUP_IRQ_HANDLER         CM7_1_LOCKUP_IRQn
#define CM33S_RESET_IRQ_HANDLER         CM33_1_SYSRESETREQ_IRQn
#define CM33S_LOCKUP_IRQ_HANDLER        CM33_1_LOCKUP_IRQn
#define MU1_A_IRQ_HANDLER               MU1_A_IRQn
#define MU2_A_IRQ_HANDLER               MU2_A_IRQn
#define MU3_A_IRQ_HANDLER               MU3_A_IRQn
#define MU3_B_IRQ_HANDLER               MU3_B_IRQn
#define MU4_A_IRQ_HANDLER               MU4_A_IRQn
#define MU4_B_IRQ_HANDLER               MU4_B_IRQn
#define MU5_A_IRQ_HANDLER               MU5_A_IRQn
#define MU6_A_IRQ_HANDLER               MU6_A_IRQn
#define MU6_B_IRQ_HANDLER               MU6_B_IRQn
#define MU7_A_IRQ_HANDLER               MU7_A_IRQn
#define MU7_B_IRQ_HANDLER               MU7_B_IRQn
#define MU8_A_IRQ_HANDLER               MU8_A_IRQn
#define MU8_B_IRQ_HANDLER               MU8_B_IRQn
#define MU9_A_IRQ_HANDLER               MU9_A_IRQn
#define MU9_B_IRQ_HANDLER               MU9_B_IRQn

#define HARDFAULT_IRQ_TRIGGER           HardFault_IRQn

#define HAS_FUSE_GET_SPEED

#define DEV_SM_FAULT_ID                 DEV_SM_FAULT_RESV98

#define DEV_SM_CPU_TEST                 DEV_SM_CPU_A55C0
#define DEV_SM_CPU_SYS_TEST             DEV_SM_CPU_A55C0
#define DEV_SM_PLAT_TEST                DEV_SM_CPU_A55P

#define DEV_SM_TEST_SRC_MIX             PWR_MIX_SLICE_IDX_A55C0

#define SM_NUM_THRESHOLDS               3U
#define SM_NUM_EVENTCONTROLS            6U

#define DEV_SM_TEST_REASON_UNUSED       DEV_SM_REASON_UNUSED5

#define TEST_LPI_IDX                    DEV_SM_NUM_PERLPI

#define DEV_SM_PERF_DEFAULT             DEV_SM_PERF_LVL_PRK

#define BRD_SM_CONTROL_COMMON           BRD_SM_CTRL_BT_WAKE
#define BRD_SM_CTRL_EXT_TEST            BRD_SM_CTRL_PCA2131
#define SENSOR_0                        DEV_SM_SENSOR_TEMP_ANA

#define FAULT_SET_TEST_0                DEV_SM_FAULT_TEMP_HIGH
#define FAULT_SET_TEST_1                DEV_SM_FAULT_TEMP2_HIGH
#define FAULT_SET_TEST_2                DEV_SM_FAULT_DDRC
#define FAULT_SET_TEST_3                DEV_SM_FAULT_DDR_MBE
#define FAULT_SET_TEST_4                DEV_SM_FAULT_OCRAM_MBE
#define FAULT_SET_TEST_5                DEV_SM_FAULT_NPUSRAM_MBE
#define FAULT_SET_TEST_6                DEV_SM_FAULT_M33TCM_MBE
#define FAULT_SET_TEST_7                DEV_SM_FAULT_M33CACHE_MBE
#define FAULT_SET_TEST_8                DEV_SM_FAULT_M7TCM_MBE
#define FAULT_SET_TEST_9                DEV_SM_FAULT_M7CACHE_MBE
#define FAULT_SET_TEST_10               DEV_SM_FAULT_RESV10

#define FAULT_SET_TEST_START            FAULT_SET_TEST_0
#define FAULT_SET_TEST_END              FAULT_SET_TEST_10

#define FAULT_0                         DEV_SM_FAULT_SWNCF03
#define FAULT_1                         DEV_SM_FAULT_SWNCF04
#define FAULT_2                         DEV_SM_FAULT_DDR_MBE
#define FAULT_3                         DEV_SM_FAULT_NOC_MAIN
#define FAULT_4                         DEV_SM_FAULT_NOC_CENTRAL
#define FAULT_5                         DEV_SM_FAULT_M33_SYNC_RST
#define FAULT_6                         DEV_SM_FAULT_WDOG7
#define FAULT_7                         DEV_SM_FAULT_WDOG8
#define FAULT_8                         DEV_SM_FAULT_M7_LOCKUP

#define DEV_SM_FAULT_STATE_TEST         DEV_SM_FAULT_WDOG2

#define DEV_SM_REASON_TEST              DEV_SM_REASON_PMIC
#define DEV_SM_DAISY_TEST               DEV_SM_DAISY_CAN2_RX

#define DEV_SM_TEST_CPU                 DEV_SM_CPU_M33P

#define DEV_SM_TEST_NUM_SLEEP_MODE      CPU_NUM_SLEEP_MODES

#define CPU_TEST_PERCONFIGS_VAL         SM_NUM_PERLPI

#define TEST_SSC_CLOCK                  CLOCK_SRC_AUDIOPLL1_VCO
#define TEST_RESERVED_CLK               CLOCK_SRC_RESERVED20

#define TEST_CPU_ID                     7U
#define TEST_RESET_VECTOR_VAL           0x20480000UL

#ifdef DEV_SM_PD_A55C0
#define DEV_SM_PD_TEST_0                DEV_SM_PD_A55C0
#endif
#ifdef DEV_SM_PD_A55C1
#define DEV_SM_PD_TEST_1                DEV_SM_PD_A55C1
#endif
#ifdef DEV_SM_PD_A55C2
#define DEV_SM_PD_TEST_2                DEV_SM_PD_A55C2
#endif
#ifdef DEV_SM_PD_A55C3
#define DEV_SM_PD_TEST_3                DEV_SM_PD_A55C3
#endif
#ifdef DEV_SM_PD_A55C4
#define DEV_SM_PD_TEST_4                DEV_SM_PD_A55C4
#endif
#ifdef DEV_SM_PD_A55C5
#define DEV_SM_PD_TEST_5                DEV_SM_PD_A55C5
#endif

#define INVALID_CPU_ID_TEST             0xFU

/* Local defines */

/* Types */

#endif /* TEST_DEV_H */

