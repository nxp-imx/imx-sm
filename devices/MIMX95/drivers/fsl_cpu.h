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

/*==========================================================================*/
/*!
 * @addtogroup MX95_CPU_driver
 * @{
 *
 * @file
 * @brief
 *
 * Header for MX95 CPU driver.
 */
/*==========================================================================*/

#ifndef DRV_CPU_H
#define DRV_CPU_H

/* Includes */

#include "fsl_common.h"

/* Defines */

#ifndef DOXYGEN

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

#define CPU_PER_LPI_ON_NEVER            0U
#define CPU_PER_LPI_ON_RUN              1U
#define CPU_PER_LPI_ON_RUN_WAIT         2U
#define CPU_PER_LPI_ON_RUN_WAIT_STOP    3U
#define CPU_PER_LPI_ON_ALWAYS           4U

#endif

/* Types */

/*!
 * CPU watchdog info structure
 *
 * Structure containing parameters for CPU watchdog.
 */
typedef struct
{
    IRQn_Type secIrq;       /*!< wdog secure IRQ number */
    IRQn_Type nonsecIrq;    /*!< wdog non-secure IRQ number */
    uint32_t rstLine;       /*!< wdog reset line */
} cpu_wdog_info_t;

/*!
 * CPU management info structure
 *
 * Structure containing parameters required for CPU management.
 */
typedef struct
{
    uint32_t srcMixIdx;                 /*!< CPU's SRC MIX identifier */
    __IO uint32_t *cpuWaitReg;          /*!< CPU WAIT register */
    uint32_t cpuWaitMask;               /*!< CPU WAIT register mask */
    IRQn_Type rstReqIrq;                /*!< CPU reset request IRQ number */
    IRQn_Type lockupIrq;                /*!< CPU lockup IRQ number */
    cpu_wdog_info_t const *wdogInfo;    /*!< CPU watchdog structure */
    __IO uint32_t *vectorRegHigh;       /*!< CPU vector high */
    __IO uint32_t *vectorRegLow;        /*!< CPU vector low */
    uint32_t vectorShift;               /*!< CPU vector shift */
    uint32_t cmcSysSleepCtrl;           /*!< CMC system sleep control */
    uint32_t cmcMisc;                   /*!< CMC misc control */
} cpu_mgmt_info_t;

/*!
 * LPI info structure
 *
 * Structure containing parameters required to hold LPI details.
 */
typedef struct
{
    __IO uint32_t *reqReg;  /*!< LPI request register */
    uint32_t reqMask;       /*!< LPI request register mask */
    uint32_t reqVal;        /*!< LPI request register value  */
    uint32_t lpcgIdx;       /*!< LPCG identifier */
} cpu_per_lpi_info_t;

/* Functions */

/*!
 * @name MX95 CPU driver functions
 * @{
 */

/*!
 * Initialize CMC/GPC interfaces for the CPU
 *
 * @param[in]   cpuIdx      CPU identifier
 *
 * This function allows caller to initialize CMC/GPC interface for the given
 * CPU.
 *
 * @return Returns true if CPU initiazation is performed successfully,
 *         otherwise false.
 */
bool CPU_Init(uint32_t cpuIdx);

/*!
 * Set CPU WAIT signal
 *
 * @param[in]   cpuIdx          CPU identifier
 * @param[in]   enableCpuWait   Enable flag (1=enable, 0=disable)
 *
 * This function allows caller to set the WAIT signal for the given \a cpuIdx.
 *
 * @return Returns true if WAIT signal is set successfully for the given CPU,
 *         otherwise false.
 */
bool CPU_WaitSet(uint32_t cpuIdx, bool enableCpuWait);

/*!
 * Get CPU WAIT signal
 *
 * @param[in]   cpuIdx          CPU identifier
 * @param[out]  cpuWait         CPU WAIT signal status (1=enabled, 0=disabled)
 *
 * This function allows caller to get the WAIT signal for the given \a cpuIdx.
 *
 * @return Returns true if WAIT signal get is successful for the given CPU,
 *         otherwise false.
 */
bool CPU_WaitGet(uint32_t cpuIdx, bool *cpuWait);

/*!
 * Generate software wakeup event
 *
 * @param[in]   cpuIdx          CPU identifier
 *
 * This function allows caller to generate software wakeup event (used for CPU
 * hotplug) for the given \a cpuIdx.
 *
 * @return Returns true if the software wakeup signal is generated successfully
 *         for the given CPU, otherwise false.
 */
bool CPU_SwWakeup(uint32_t cpuIdx);

/*!
 * Set CPU IRQs
 *
 * @param[in]   cpuIdx          CPU identifier
 * @param[in]   enableCpuIrq    Enable flag (1=enable, 0=disable)
 *
 * This function allows caller to set (enable/disable) IRQ for the given
 * \a cpuIdx.
 *
 * @return Returns true if the IRQs are set successfully for the given CPU,
 *         otherwise false.
 */
bool CPU_IrqSet(uint32_t cpuIdx, bool enableCpuIrq);

/*!
 * Set GPC handshakes associated with CPU
 *
 * @param[in]   cpuIdx              CPU identifier
 * @param[in]   enableHandshake     Enable flag (1=enable, 0=disable)
 *
 * This function allows caller to set (enable/disable) GPC handshake associated
 * with the given \a cpuIdx. It configures LP SM handshake.
 *
 * @return Returns true if GPC handshake is set (enable/disable) successfully
 *         for the given CPU, otherwise false.
 */
bool CPU_GpcHandshakeSet(uint32_t cpuIdx,bool enableHandshake);

/*!
 * Get CPU FSM state
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[out]      fsmState        CPU FSM state
 *
 * This function allows caller to get (enable/disable) FSM state for given
 * \a cpuIdx.
 *
 * @return Returns true if FSM state of the CPU is retrieved successfully,
 *         otherwise false.
 */
bool CPU_FsmStateGet(uint32_t cpuIdx, uint32_t *fsmState);

/*!
 * Set CPU reset signal
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[in]       resetType       Reset type
 *
 * This function allows caller to set CPU reset signal for given \a cpuIdx.
 *
 * @return Returns true if CPU reset signal is set successfully,
 *         otherwise false.
 */
bool CPU_ResetSet(uint32_t cpuIdx, uint32_t resetType);

/*!
 * Get CPU reset signal
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[out]      resetType       Reset type
 *
 * This function allows caller to get CPU reset signal value for given
 * \a cpuIdx.
 *
 * @return Returns true if CPU reset signal is retrieved successfully,
 *         otherwise false.
 */
bool CPU_ResetGet(uint32_t cpuIdx, uint32_t *resetType);

/*!
 * Set CPU run mode
 *
 * @param[in]       cpuIdx      CPU identifier
 * @param[in]       runMode     CPU run mode
 *
 * This function allows caller to set CPU run mode. Based on the current run
 * mode of the CPU, different programming sequence is followed to set the
 * desired run mode for the given CPU.
 *
 * @return Returns true if CPU run mode is set successfully, otherwise false.
 */
bool CPU_RunModeSet(uint32_t cpuIdx, uint32_t runMode);

/*!
 * Get CPU run mode
 *
 * @param[in]       cpuIdx      CPU identifier
 * @param[out]      runMode     CPU run mode
 *
 * This function allows caller to get CPU run mode based on the power status
 * of the MIX and CPU wait signal.
 *
 * @return Returns true if CPU run mode is retrieved successfully, otherwise
 *         false.
 */
bool CPU_RunModeGet(uint32_t cpuIdx, uint32_t *runMode);

/*!
 * Set CPU sleep mode
 *
 * @param[in]   cpuIdx      CPU identifier
 * @param[in]   sleepMode   CPU sleep mode
 *
 * This function allows caller to set sleep mode for the given CPU. When a CPU
 * executes WFI/WFE event, it enters to WAIT/STOP/SUSPEND state (or stay in
 * RUN mode) based on given \a sleepMode configuration.
 *
 * @return Returns true if CPU sleep mode is set successfully, otherwise false.
 */
bool CPU_SleepModeSet(uint32_t cpuIdx, uint32_t sleepMode);

/*!
 * Get CPU sleep mode
 *
 * @param[in]       cpuIdx      CPU identifier
 * @param[out]      sleepMode   CPU sleep mode
 *
 * This function allows caller to get sleep mode for the given CPU.
 *
 * @return Returns true if CPU sleep mode is retrieved successfully, otherwise
 *         false.
 */
bool CPU_SleepModeGet(uint32_t cpuIdx, uint32_t *sleepMode);

/*!
 * Set CPU sleep force control
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[in]       sleepForce      Sleep force flag (1=enable, 0=disable)
 *
 * This function allows caller to force the given CPU in sleep state. When
 * enabled, GPC will ignore the CMC system sleep mode requirement for the
 * CPU.
 *
 * @return Returns true if CPU sleep force is configured successfully,
 *         otherwise false.
 */
bool CPU_SleepForceSet(uint32_t cpuIdx, bool sleepForce);

/*!
 * Get CPU sleep force control
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[out]      sleepForce      Sleep force flag (1=enable, 0=disable)
 *
 * This function allows caller to get force sleep status of given CPU.
 *
 * @return Returns true if CPU force sleep configuration is retrieved
 *         successfully, otherwise false.
 */
bool CPU_SleepForceGet(uint32_t cpuIdx, bool *sleepForce);

/*!
 * Set system-level sleep control
 *
 * @param[in]       cpuIdx      CPU identifier
 * @param[in]       sysSleep    System sleep request configuration
 *
 * This function allows caller to configure system-level sleep control
 * configuration for the given CPU/CMC. The system is put into system sleep
 * mode only when all the CMC request the system to enter system sleep mode.
 *
 * @return Returns true if CPU system-level sleep control is configured
 *         successfully, otherwise false.
 */
bool CPU_SystemSleepSet(uint32_t cpuIdx, uint32_t sysSleep);

/*!
 * Get system-level sleep control
 *
 * @param[in]       cpuIdx      CPU identifier
 * @param[out]      sysSleep    System sleep request configuration
 *
 * This function allows caller to get system-level sleep control configuration
 * for the given CPU/CMC.
 *
 * @return Returns true if CPU system-level sleep control configuration is
 *         retrieved successfully, otherwise false.
 */
bool CPU_SystemSleepGet(uint32_t cpuIdx, uint32_t *sysSleep);

/*!
 * Get system-level sleep status
 *
 * @param[out]      sysSleepStat    System sleep status
 *
 * This function allows caller to get system-level sleep status. It returns
 * lowest CPU mode among all the CPUs.
 *
 * @return Returns true if CPU system-level sleep status is retrieved
 *         successfully, otherwise false.
 */
bool CPU_SystemSleepStatusGet(uint32_t *sysSleepStat);

/*!
 * Set wake mux (IRQ/GIC)
 *
 * @param[in]       cpuIdx      CPU identifier
 * @param[in]       gicWake     GIC wakeup flag
 *
 * This function allows caller to set wakeup event source between IRQ (default)
 * and GIC for the given CPU.
 *
 * @return Returns true if wakeup event selection is configured successfully,
 *         otherwise false.
 */
bool CPU_WakeMuxSet(uint32_t cpuIdx, bool gicWake);

/*!
 * Get wake mux (IRQ/GIC)
 *
 * @param[in]       cpuIdx      CPU identifier
 * @param[out]      gicWake     GIC wakeup flag
 *
 * This function allows caller to get wakeup event source (IRQ/GIC) for the
 * given CPU.
 *
 * @return Returns true if wakeup event selection is retrieved successfully,
 *         otherwise false.
 */
bool CPU_WakeMuxGet(uint32_t cpuIdx, bool *gicWake);

/*!
 * Set GPC IRQ wake-up mask
 *
 * @param[in]       cpuIdx      CPU identifier
 * @param[in]       maskIdx     IRQ wake-up mask register index
 * @param[in]       maskVal     IRQ wake-up mask register value
 *
 * If the wakeup event source for the given CPU is configured as IRQ, this
 * function allows caller to configure IRQ wake-up mask register to set which
 * interrupts lines can wakeup the CPU.
 * Bit value of 1 in the \a maskVal means IRQ cannot wake-up the CPU.
 *
 * @return Returns true if IRQ wake-up mask is configured successfully,
 *         otherwise false.
 */
bool CPU_IrqWakeSet(uint32_t cpuIdx, uint32_t maskIdx, uint32_t maskVal);

/*!
 * Get GPC IRQ wake-up mask
 *
 * @param[in]       cpuIdx      CPU identifier
 * @param[in]       maskIdx     IRQ wake-up mask register index
 * @param[out]      maskVal     IRQ wake-up mask register value
 *
 * If the wakeup event source for the given CPU is configured as IRQ, this
 * function allows caller to get IRQ wake-up mask register configuration to
 * know which interrupts lines can wakeup the CPU.
 * Bit value of 1 in the \a maskVal means IRQ cannot wake-up the CPU.
 *
 * @return Returns true if IRQ wake-up mask is retrieved successfully,
 *         otherwise false.
 */
bool CPU_IrqWakeGet(uint32_t cpuIdx, uint32_t maskIdx, uint32_t *maskVal);

/*!
 * Set GPC non-IRQ wakeup mask
 *
 * @param[in]       cpuIdx      CPU identifier
 * @param[in]       maskVal     IRQ wake-up mask register value
 *
 * This function allows caller to set wake-up events which are not interrupts.
 * Bit value of 1 in the \a maskVal means event cannot wakeup the CPU.
 *
 * @return Returns true if non-IRQ wakeup mask is configured successfully,
 *         otherwise false.
 */
bool CPU_NonIrqWakeSet(uint32_t cpuIdx, uint32_t maskVal);

/*!
 * Get GPC non-IRQ wakeup mask
 *
 * @param[in]       cpuIdx      CPU identifier
 * @param[out]      maskVal     IRQ wake-up mask register value
 *
 * This function allows caller to get wake-up events which are not interrupts.
 * Bit value of 1 in the \a maskVal means event cannot wakeup the CPU.
 *
 * @return Returns true if non-IRQ wakeup mask is retrieved successfully,
 *         otherwise false.
 */
bool CPU_NonIrqWakeGet(uint32_t cpuIdx, uint32_t *maskVal);

/*!
 * Set CPU power domain LPM config
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[in]       srcMixIdx       MIX identifier
 * @param[in]       lpmSetting      LPM setting for the MIX
 * @param[in]       retMask         Retention mode mask of MEM slices
 *
 * This function allows caller to configure LPM setting of the given
 * \a srcMixIdx for the given CPU. It also configures memory retention
 * mode of MEM slices for the given \a srcMixIdx.
 *
 * @return Returns true if CPU power domain LPM configuration is applied
 *         successfully, otherwise false.
 */
bool CPU_LpmConfigSet(uint32_t cpuIdx, uint32_t srcMixIdx,
    uint32_t lpmSetting, uint32_t retMask);

/*!
 * Initialize CPU power domain LPM config
 *
 * @param[in]       cpuIdx          CPU identifier
 *
 * This function allows caller to initialize CPU power domain LPM
 * configuration and include CPU sleep status in evaluation of system suspend.
 *
 * @return Returns true if CPU power domain LPM configuration is applied
 *         successfully, otherwise false.
 */
bool CPU_LpmConfigInit(uint32_t cpuIdx);

/*!
 * Deinitialize CPU power domain LPM config
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[in]       lpmSetting      LPM setting for the MIX
 *
 * This function allows caller to deinitialize CPU power domain LPM
 * configuration and remove CPU sleep status in evaluation of system suspend.
 *
 * @return Returns true if deinitialization of CPU power domain LPM
 *         configuration is performed successfully, otherwise false.
 */
bool CPU_LpmConfigDeInit(uint32_t cpuIdx, uint32_t lpmSetting);

/*!
 * Set CPU peripheral low-power interface config
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[in]       perLpiIdx       CPU low power interface identifier
 * @param[in]       lpmSetting      LPM setting for the MIX
 *
 * This function allows caller to set CPU peripheral LPI configuration.
 *
 * @return Returns true if CPU LPI configuration is applied successfully,
 *         otherwise false.
 */
bool CPU_PerLpiConfigSet(uint32_t cpuIdx, uint32_t perLpiIdx,
    uint32_t lpmSetting);

/*!
 * Get CPU peripheral low-power interface config
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[in]       perLpiIdx       CPU low power interface identifier
 * @param[out]      lpmSetting      LPM setting for the MIX
 *
 * This function allows caller to get CPU peripheral LPI configuration.
 *
 * @return Returns true if CPU LPI configuration is retrieved  successfully,
 *         otherwise false.
 */
bool CPU_PerLpiConfigGet(uint32_t cpuIdx, uint32_t perLpiIdx,
    uint32_t *lpmSetting);

/*!
 * Initialize CPU peripheral low-power interface config
 *
 * @param[in]       cpuIdx          CPU identifier
 *
 * This function allows caller to initialize CPU peripheral low-power interface
 * config, which eventually sets a virtual LPCG low-power mode setting for
 * specified CPU.
 *
 * @return Returns true if CPU peripheral low-power interface configuration
 *         initialization is successful, otherwise false.
 */
bool CPU_PerLpiConfigInit(uint32_t cpuIdx);

/*!
 * Process all peripheral low-power interfaces for specified CPU
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[in]       sleepMode       CPU sleep mode
 *
 * This function processes all peripheral LPI for the specified CPU. It
 * compares peripheral LPM setting against CPU sleep mode to assert/deassert
 * peripheral LPI.
 *
 * @return Returns true if processing of all peripheral low-power interfaces
 *         for specified CPU is successful, otherwise false.
 */
bool CPU_PerLpiProcess(uint32_t cpuIdx, uint32_t sleepMode);

/*!
 * Handle notification of MIX power up
 *
 * @param[in]       srcMixIdx       SRC MIX identifier
 *
 * This function release CPU(s)s with all dependencies done for the given
 * \a srcMixIdx.
 */
void CPU_MixPowerUpNotify(uint32_t srcMixIdx);

/*!
 * Handle notification of MIX power down
 *
 * @param[in]       srcMixIdx       SRC MIX identifier
 *
 * This function assert CPUWAIT for the CPU which has MIX dependency.
 */
void CPU_MixPowerDownNotify(uint32_t srcMixIdx);

/*!
 * Set CPU reset vector
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[in]       vector          CPU vector value
 *
 * This function sets vector for the given CPU.
 *
 * @return Returns true if vector is set successfully for the given CPU,
 *         otherwise false.
 */
bool CPU_ResetVectorSet(uint32_t cpuIdx, uint64_t vector);

/*!
 * Get CPU reset vector
 *
 * @param[in]       cpuIdx          CPU identifier
 * @param[out]      vector          CPU vector value
 *
 * This function gets vector for the given CPU.
 *
 * @return Returns true if vector is retrieved successfully for the given CPU,
 *         otherwise false.
 */
bool CPU_ResetVectorGet(uint32_t cpuIdx, uint64_t *vector);

/** @} */

/* Externs */

#endif /* DRV_CPU_H */

/** @} */

