/*
 * Copyright 2023-2024 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DRV_CPU_H
#define DRV_CPU_H

/*!
 * @addtogroup CPU_driver
 * @{
 */

/*! @file */

/* Includes */
#include "fsl_common.h"

/* Defines */
#define CPU_NUM_IDX         9U

#define CPU_IDX_M33P        0U
#define CPU_IDX_M7P         1U
#define CPU_IDX_A55C0       2U
#define CPU_IDX_A55C1       3U
#define CPU_IDX_A55C2       4U
#define CPU_IDX_A55C3       5U
#define CPU_IDX_A55C4       6U
#define CPU_IDX_A55C5       7U
#define CPU_IDX_A55P        8U

#define CPU_IDX_A55C_LAST   CPU_IDX_A55C5

#define CPU_NUM_RUN_MODES       3U

#define CPU_RUN_MODE_START      0U
#define CPU_RUN_MODE_HOLD       1U
#define CPU_RUN_MODE_STOP       2U
#define CPU_RUN_MODE_SLEEP      3U

#define CPU_NUM_SLEEP_MODES     4U

#define CPU_SLEEP_MODE_RUN      0U
#define CPU_SLEEP_MODE_WAIT     1U
#define CPU_SLEEP_MODE_STOP     2U
#define CPU_SLEEP_MODE_SUSPEND  3U

#define CPU_NUM_PD_LPM              5U

#define CPU_PD_LPM_ON_NEVER         0U
#define CPU_PD_LPM_ON_RUN           1U
#define CPU_PD_LPM_ON_RUN_WAIT      2U
#define CPU_PD_LPM_ON_RUN_WAIT_STOP 3U
#define CPU_PD_LPM_ON_ALWAYS        4U

#define CPU_FSM_STATE_IDLE_RUN          0x00U
#define CPU_FSM_STATE_SLEEP_A55_HDSK    0x01U
#define CPU_FSM_STATE_SLEEP_SYSMAN      0x02U
#define CPU_FSM_STATE_SLEEP_SSAR        0x03U
#define CPU_FSM_STATE_SLEEP_RESET       0x08U
#define CPU_FSM_STATE_SLEEP_SYS         0x0BU
#define CPU_FSM_STATE_IDLE_SLEEP        0x0CU
#define CPU_FSM_STATE_WAKEUP_SYS        0x0DU
#define CPU_FSM_STATE_WAKEUP_POWER      0x0FU
#define CPU_FSM_STATE_WAKEUP_SSAR       0x16U
#define CPU_FSM_STATE_WAKEUP_SYSMAN     0x17U
#define CPU_FSM_STATE_WAKEUP_A55_HDSK   0x18U

#define CPU_NUM_PER_LPI_IDX             21U

#define CPU_PER_LPI_IDX_GPIO1           0U
#define CPU_PER_LPI_IDX_GPIO2           1U
#define CPU_PER_LPI_IDX_GPIO3           2U
#define CPU_PER_LPI_IDX_GPIO4           3U
#define CPU_PER_LPI_IDX_GPIO5           4U
#define CPU_PER_LPI_IDX_CAN1            5U
#define CPU_PER_LPI_IDX_CAN2            6U
#define CPU_PER_LPI_IDX_CAN3            7U
#define CPU_PER_LPI_IDX_CAN4            8U
#define CPU_PER_LPI_IDX_CAN5            9U
#define CPU_PER_LPI_IDX_LPUART1         10U
#define CPU_PER_LPI_IDX_LPUART2         11U
#define CPU_PER_LPI_IDX_LPUART3         12U
#define CPU_PER_LPI_IDX_LPUART4         13U
#define CPU_PER_LPI_IDX_LPUART5         14U
#define CPU_PER_LPI_IDX_LPUART6         15U
#define CPU_PER_LPI_IDX_LPUART7         16U
#define CPU_PER_LPI_IDX_LPUART8         17U
#define CPU_PER_LPI_IDX_WDOG3           18U
#define CPU_PER_LPI_IDX_WDOG4           19U
#define CPU_PER_LPI_IDX_WDOG5           20U

#define CPU_PER_LPI_LPCG_OFFSET         128U

#define CPU_PER_LPI_ON_NEVER            0U
#define CPU_PER_LPI_ON_RUN              1U
#define CPU_PER_LPI_ON_RUN_WAIT         2U
#define CPU_PER_LPI_ON_RUN_WAIT_STOP    3U
#define CPU_PER_LPI_ON_ALWAYS           4U

/* Types */
typedef struct
{
    IRQn_Type secIrq;
    IRQn_Type nonsecIrq;
    uint32_t rstLine;
} cpu_wdog_info_t;

typedef struct
{
    uint32_t srcMixIdx;
    __IO uint32_t *cpuWaitReg;
    uint32_t cpuWaitMask;
    IRQn_Type rstReqIrq;
    IRQn_Type lockupIrq;
    cpu_wdog_info_t const *wdogInfo;
    __IO uint32_t *vectorRegHigh;
    __IO uint32_t *vectorRegLow;
    uint32_t vectorShift;
    uint32_t cmcSysSleepCtrl;
    uint32_t cmcMisc;
} cpu_mgmt_info_t;

typedef struct
{
    __IO uint32_t *reqReg;
    uint32_t reqMask;
    uint32_t reqVal;
    uint32_t lpcgIdx;
} cpu_per_lpi_info_t;

/* Functions */
bool CPU_Init(uint32_t cpuIdx);
bool CPU_WaitSet(uint32_t cpuIdx, bool enableCpuWait);
bool CPU_WaitGet(uint32_t cpuIdx, bool *cpuWait);
bool CPU_SwWakeup(uint32_t cpuIdx);
bool CPU_IrqSet(uint32_t cpuIdx, bool enableCpuIrq);
bool CPU_GpcHandshakeSet(uint32_t cpuIdx,bool enableHandshake);
bool CPU_FsmStateGet(uint32_t cpuIdx, uint32_t *fsmState);
bool CPU_ResetSet(uint32_t cpuIdx, uint32_t resetType);
bool CPU_ResetGet(uint32_t cpuIdx, uint32_t *resetType);
bool CPU_RunModeSet(uint32_t cpuIdx, uint32_t runMode);
bool CPU_RunModeGet(uint32_t cpuIdx, uint32_t *runMode);
bool CPU_SleepModeSet(uint32_t cpuIdx, uint32_t sleepMode);
bool CPU_SleepModeGet(uint32_t cpuIdx, uint32_t *sleepMode);
bool CPU_SleepForceSet(uint32_t cpuIdx, bool sleepForce);
bool CPU_SleepForceGet(uint32_t cpuIdx, bool *sleepForce);
bool CPU_SystemSleepSet(uint32_t cpuIdx, uint32_t sysSleep);
bool CPU_SystemSleepGet(uint32_t cpuIdx, uint32_t *sysSleep);
bool CPU_WakeMuxSet(uint32_t cpuIdx, bool gicWake);
bool CPU_WakeMuxGet(uint32_t cpuIdx, bool *gicWake);
bool CPU_IrqWakeSet(uint32_t cpuIdx, uint32_t maskIdx, uint32_t maskVal);
bool CPU_IrqWakeGet(uint32_t cpuIdx, uint32_t maskIdx, uint32_t *maskVal);
bool CPU_NonIrqWakeSet(uint32_t cpuIdx, uint32_t maskVal);
bool CPU_NonIrqWakeGet(uint32_t cpuIdx, uint32_t *maskVal);
bool CPU_LpmConfigSet(uint32_t cpuIdx, uint32_t srcMixIdx,
    uint32_t lpmSetting, uint32_t retMask);
bool CPU_LpmConfigInit(uint32_t cpuIdx);
bool CPU_LpmConfigDeInit(uint32_t cpuIdx, uint32_t lpmSetting);
bool CPU_PerLpiConfigSet(uint32_t cpuIdx, uint32_t perLpiIdx,
    uint32_t lpmSetting);
bool CPU_PerLpiConfigGet(uint32_t cpuIdx, uint32_t perLpiIdx,
    uint32_t *lpmSetting);
bool CPU_PerLpiConfigInit(uint32_t cpuIdx);
bool CPU_PerLpiProcess(uint32_t cpuIdx, uint32_t sleepMode);
void CPU_MixPowerUpNotify(uint32_t srcMixIdx);
void CPU_MixPowerDownNotify(uint32_t srcMixIdx);
bool CPU_ResetVectorSet(uint32_t cpuIdx, uint64_t vector);
bool CPU_ResetVectorGet(uint32_t cpuIdx, uint64_t *vector);

/* Externs */

#endif /* DRV_CPU_H */

/** @} */
