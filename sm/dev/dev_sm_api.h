/*
** ###################################################################
**
** Copyright 2023-2024 NXP
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

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the routing definition of DEV versus BRD SM calls.
 */
/*==========================================================================*/

#ifndef DEV_SM_API
#define DEV_SM_API

/* Includes */

#include "sm.h"
#include "brd_sm.h"
#include "dev_sm.h"

/* Defines */

/*!
 * @name Dev/board redirection defines
 * @{
 */

#ifndef SM_NUM_AGENT
/*! Redirector (device/board) for the max number of agents */
#define SM_NUM_AGENT            DEV_SM_NUM_AGENT
#endif

#ifndef SM_NUM_DEVICE
/*! Redirector (device/board) for the number of devices */
#define SM_NUM_DEVICE           DEV_SM_NUM_DEVICE
#endif

#ifndef SM_NUM_BASE
/*! Redirector (device/board) for the number of bases */
#define SM_NUM_BASE             DEV_SM_NUM_BASE
#endif

#ifndef SM_NUM_POWER
/*! Redirector (device/board) for the number of power domains */
#define SM_NUM_POWER            DEV_SM_NUM_POWER
#endif

#ifndef SM_NUM_POWER_STATE
/*! Redirector (device/board) for the number of power states */
#define SM_NUM_POWER_STATE      DEV_SM_NUM_POWER_STATE
#endif

#ifndef SM_NUM_REASON
/*! Redirector (device/board) for the number of reset reasons */
#define SM_NUM_REASON           DEV_SM_NUM_REASON
#endif

#ifndef SM_NUM_PERF
/*! Redirector (device/board) for the number of performance domains */
#define SM_NUM_PERF             DEV_SM_NUM_PERF
#endif

#ifndef SM_NUM_CLOCK
/*! Redirector (device/board) for the number of clocks */
#define SM_NUM_CLOCK            DEV_SM_NUM_CLOCK
#endif

#ifndef SM_NUM_SENSOR
/*! Redirector (device/board) for the number of sensors */
#define SM_NUM_SENSOR           DEV_SM_NUM_SENSOR
#endif

#ifndef SM_NUM_RESET
/*! Redirector (device/board) for the number of reset domains */
#define SM_NUM_RESET            DEV_SM_NUM_RESET
#endif

#ifndef SM_NUM_VOLT
/*! Redirector (device/board) for the number of voltage domains */
#define SM_NUM_VOLT             DEV_SM_NUM_VOLT
#endif

#ifndef SM_NUM_VOLT_MODE
/*! Redirector (device/board) for the number of voltage modes */
#define SM_NUM_VOLT_MODE        DEV_SM_NUM_VOLT_MODE
#endif

#ifndef SM_NUM_GPR
/*! Redirector (device/board) for the number of GPR */
#define SM_NUM_GPR              DEV_SM_NUM_GPR
#endif

#ifndef SM_NUM_RTC
/*! Redirector (device/board) for the number of RTC */
#define SM_NUM_RTC              DEV_SM_NUM_RTC
#endif

#ifndef SM_NUM_BUTTON
/*! Redirector (device/board) for the number of BBM resources */
#define SM_NUM_BUTTON           DEV_SM_NUM_BUTTON
#endif

#ifndef SM_NUM_CPU
/*! Redirector (device/board) for the number of peripheral LPIs */
#define SM_NUM_CPU              DEV_SM_NUM_CPU
#endif

#ifndef SM_NUM_PERLPI
/*! Redirector (device/board) for the number of CPUs */
#define SM_NUM_PERLPI           DEV_SM_NUM_PERLPI
#endif

#ifndef SM_NUM_PIN
/*! Redirector (device/board) for the number of pins */
#define SM_NUM_PIN              DEV_SM_NUM_PIN
#endif

#ifndef SM_NUM_DAISY
/*! Redirector (device/board) for the number of daisy registers */
#define SM_NUM_DAISY            DEV_SM_NUM_DAISY
#endif

#ifndef SM_NUM_CTRL
/*! Redirector (device/board) for the number of controls */
#define SM_NUM_CTRL             DEV_SM_NUM_CTRL
#endif

#ifndef SM_NUM_FAULT
/*! Redirector (device/board) for the number of faults */
#define SM_NUM_FAULT            DEV_SM_NUM_FAULT
#endif

#ifndef SM_NUM_RDC
/*! Redirector (device/board) for the number of RDC */
#define SM_NUM_RDC              DEV_SM_NUM_RDC
#endif

#ifndef SM_ERRORDUMP
/*! Redirector (device/board) to dump logged errors */
#define SM_ERRORDUMP            DEV_SM_ErrorDump
#endif

#ifndef SM_POWERDOMAINNAMEGET
/*! Redirector (device/board) to get a power domain name */
#define SM_POWERDOMAINNAMEGET   DEV_SM_PowerDomainNameGet
#endif

#ifndef SM_POWERSTATENAMEGET
/*! Redirector (device/board) to get a power state name */
#define SM_POWERSTATENAMEGET    DEV_SM_PowerStateNameGet
#endif

#ifndef SM_POWERSTATESET
/*! Redirector (device/board) to set a power domain state */
#define SM_POWERSTATESET        DEV_SM_PowerStateSet
#endif

#ifndef SM_POWERSTATEGET
/*! Redirector (device/board) to get a power domain's state */
#define SM_POWERSTATEGET        DEV_SM_PowerStateGet
#endif

#ifndef SM_POWERRETMODESET
/*! Redirector (device/board) to set a power domain's retention mode */
#define SM_POWERRETMODESET      DEV_SM_PowerRetModeSet
#endif

#ifndef SM_POWERRETMASKGET
/*! Redirector (device/board) to get a power domain's retention mask */
#define SM_POWERRETMASKGET      DEV_SM_PowerRetMaskGet
#endif

#ifndef SM_SYSTEMPOWERMODESET
/*! Redirector (device/board) to set the system power mode */
#define SM_SYSTEMPOWERMODESET   DEV_SM_SystemPowerModeSet
#endif

#ifndef SM_SYSTEMRESET
/*! Redirector (device/board) to reset entire system */
#define SM_SYSTEMRESET          DEV_SM_SystemReset
#endif

#ifndef SM_SYSTEMSTAGERESET
/*! Redirector (device/board) to reset entire system to a boot stage */
#define SM_SYSTEMSTAGERESET     DEV_SM_SystemStageReset
#endif

#ifndef SM_SYSTEMSHUTDOWN
/*! Redirector (device/board) to turn off the system */
#define SM_SYSTEMSHUTDOWN       DEV_SM_SystemShutdown
#endif

#ifndef SM_SYSTEMREASONNAMEGET
/*! Redirector (device/board) to get a reset reason name */
#define SM_SYSTEMREASONNAMEGET  DEV_SM_SystemReasonNameGet
#endif

#ifndef SM_SYSTEMRSTCOMP
/*! Redirector (LMM/board) to complete a reset */
#define SM_SYSTEMRSTCOMP        LMM_SystemRstComp
#endif

#ifndef SM_SYSTEMREACTIONGET
/*! Redirector (LMM/board) to get a reset reaction */
#define SM_SYSTEMREACTIONGET    LMM_SystemReactionGet
#endif

#ifndef DEV_SM_SYSTEMRSTREASON
/*! Redirector (device/board) to get system reset reason */
#define DEV_SM_SYSTEMRSTREASON  DEV_SM_SystemRstReason
#endif

#ifndef SM_SYSTEMPOSTBOOT
/*! Redirector (device/board) to post boot clean-up */
#define SM_SYSTEMPOSTBOOT       DEV_SM_SystemPostBoot
#endif

#ifndef SM_SYSTEMERROR
/*! Redirector (device/board) to report an error */
#define SM_SYSTEMERROR          DEV_SM_SystemError
#endif

#ifndef SM_PERFNAMEGET
/*! Redirector (device/board) to get performance domain name */
#define SM_PERFNAMEGET          DEV_SM_PerfNameGet
#endif

#ifndef SM_PERFINFOGET
/*! Redirector (device/board) to get performance domain info */
#define SM_PERFINFOGET          DEV_SM_PerfInfoGet
#endif

#ifndef SM_PERFNUMLEVELSGET
/*! Redirector (device/board) to get a performance levels of a domain */
#define SM_PERFNUMLEVELSGET     DEV_SM_PerfNumLevelsGet
#endif

#ifndef SM_PERFDESCRIBE
/*! Redirector (device/board) to return info about a performance level */
#define SM_PERFDESCRIBE         DEV_SM_PerfDescribe
#endif

#ifndef SM_PERFLEVELSET
/*! Redirector (device/board) to set a performance level */
#define SM_PERFLEVELSET         DEV_SM_PerfLevelSet
#endif

#ifndef SM_PERFLEVELGET
/*! Redirector (device/board) to get a performance level */
#define SM_PERFLEVELGET         DEV_SM_PerfLevelGet
#endif

#ifndef SM_CLOCKNAMEGET
/*! Redirector (device/board) to get a clock name */
#define SM_CLOCKNAMEGET         DEV_SM_ClockNameGet
#endif

#ifndef SM_CLOCKDESCRIBE
/*! Redirector (device/board) to get clock range info */
#define SM_CLOCKDESCRIBE        DEV_SM_ClockDescribe
#endif

#ifndef SM_CLOCKMUXGET
/*! Redirector (device/board) to get clock mux */
#define SM_CLOCKMUXGET          DEV_SM_ClockMuxGet
#endif

#ifndef SM_CLOCKRATESET
/*! Redirector (device/board) to set a clock rate */
#define SM_CLOCKRATESET         DEV_SM_ClockRateSet
#endif

#ifndef SM_CLOCKRATEGET
/*! Redirector (device/board) to get a clock rate */
#define SM_CLOCKRATEGET         DEV_SM_ClockRateGet
#endif

#ifndef SM_CLOCKENABLE
/*! Redirector (device/board) to set a clock enable */
#define SM_CLOCKENABLE          DEV_SM_ClockEnable
#endif

#ifndef SM_CLOCKISENABLED
/*! Redirector (device/board) to get a clock enable state */
#define SM_CLOCKISENABLED       DEV_SM_ClockIsEnabled
#endif

#ifndef SM_CLOCKPARENTSET
/*! Redirector (device/board) to set a clock parent */
#define SM_CLOCKPARENTSET       DEV_SM_ClockParentSet
#endif

#ifndef SM_CLOCKPARENTGET
/*! Redirector (device/board) to get a clock parent */
#define SM_CLOCKPARENTGET       DEV_SM_ClockParentGet
#endif

#ifndef SM_CLOCKEXTENDEDSET
/*! Redirector (device/board) to set extended clock data */
#define SM_CLOCKEXTENDEDSET     DEV_SM_ClockExtendedSet
#endif

#ifndef SM_CLOCKEXTENDEDGET
/*! Redirector (device/board) to get extended clock data */
#define SM_CLOCKEXTENDEDGET     DEV_SM_ClockExtendedGet
#endif

#ifndef SM_SENSORNAMEGET
/*! Redirector (device/board) to get a sensor name */
#define SM_SENSORNAMEGET        DEV_SM_SensorNameGet
#endif

#ifndef SM_SENSORDESCRIBE
/*! Redirector (device/board) to get a sensor description */
#define SM_SENSORDESCRIBE       DEV_SM_SensorDescribe
#endif

#ifndef SM_SENSORREADINGGET
/*! Redirector (device/board) to get a sensor value */
#define SM_SENSORREADINGGET     DEV_SM_SensorReadingGet
#endif

#ifndef SM_SENSORTRIPPOINTSET
/*! Redirector (device/board) to set set a sensor alarm */
#define SM_SENSORTRIPPOINTSET   DEV_SM_SensorTripPointSet
#endif

#ifndef SM_SENSORENABLE
/*! Redirector (device/board) to set a sensor enable */
#define SM_SENSORENABLE         DEV_SM_SensorEnable
#endif

#ifndef SM_SENSORISENABLED
/*! Redirector (device/board) to get a sensor enable state */
#define SM_SENSORISENABLED      DEV_SM_SensorIsEnabled
#endif

#ifndef SM_RESETDOMAINNAMEGET
/*! Redirector (device/board) to get a reset domain name */
#define SM_RESETDOMAINNAMEGET   DEV_SM_ResetDomainNameGet
#endif

#ifndef SM_RESETDOMAIN
/*! Redirector (device/board) to reset a reset domain name */
#define SM_RESETDOMAIN          DEV_SM_ResetDomain
#endif

#ifndef SM_VOLTAGENAMEGET
/*! Redirector (device/board) to get a voltage name */
#define SM_VOLTAGENAMEGET       DEV_SM_VoltageNameGet
#endif

#ifndef SM_VOLTAGEMODENAMEGET
/*! Redirector (device/board) to get a power state name */
#define SM_VOLTAGEMODENAMEGET   DEV_SM_VoltageModeNameGet
#endif

#ifndef SM_VOLTAGEDESCRIBE
/*! Redirector (device/board) to get votlage range info */
#define SM_VOLTAGEDESCRIBE      DEV_SM_VoltageDescribe
#endif

#ifndef SM_VOLTAGEMODESET
/*! Redirector (device/board) to set a voltage mode */
#define SM_VOLTAGEMODESET       DEV_SM_VoltageModeSet
#endif

#ifndef SM_VOLTAGEMODEGET
/*! Redirector (device/board) to get a voltage mode */
#define SM_VOLTAGEMODEGET       DEV_SM_VoltageModeGet
#endif

#ifndef SM_VOLTAGELEVELSET
/*! Redirector (device/board) to set a voltage level */
#define SM_VOLTAGELEVELSET      DEV_SM_VoltageLevelSet
#endif

#ifndef SM_VOLTAGELEVELGET
/*! Redirector (device/board) to get a voltage level */
#define SM_VOLTAGELEVELGET      DEV_SM_VoltageLevelGet
#endif

#ifndef SM_PINNAMEGET
/*! Redirector (device/board) to get a pin name */
#define SM_PINNAMEGET           DEV_SM_PinNameGet
#endif

#ifndef SM_PINCONFIGSET
/*! Redirector (device/board) to get a pin name */
#define SM_PINCONFIGSET         DEV_SM_PinConfigSet
#endif

#ifndef SM_PINCONFIGGET
/*! Redirector (device/board) to get a pin name */
#define SM_PINCONFIGGET         DEV_SM_PinConfigGet
#endif

#ifndef SM_BBMGETBOOTSTATUS
/*! Redirector (device/board) to write a BBM GPR */
#define SM_BBMGETBOOTSTATUS     DEV_SM_BbmGetBootStatus
#endif

#ifndef SM_BBMGPRSET
/*! Redirector (device/board) to write a BBM GPR */
#define SM_BBMGPRSET            DEV_SM_BbmGprSet
#endif

#ifndef SM_BBMGPRGET
/*! Redirector (device/board) to read a BBM GPR */
#define SM_BBMGPRGET            DEV_SM_BbmGprGet
#endif

#ifndef SM_BBMRTCNAMEGET
/*! Redirector (device/board) to set the BBM RTC time */
#define SM_BBMRTCNAMEGET        DEV_SM_BbmRtcNameGet
#endif

#ifndef SM_BBMRTCDESCRIBE
/*! Redirector (device/board) to get BBM RTC info */
#define SM_BBMRTCDESCRIBE       DEV_SM_BbmRtcDescribe
#endif

#ifndef SM_BBMRTCTIMESET
/*! Redirector (device/board) to set the BBM RTC time */
#define SM_BBMRTCTIMESET        DEV_SM_BbmRtcTimeSet
#endif

#ifndef SM_BBMRTCTIMEGET
/*! Redirector (device/board) to get the BBM RTC time */
#define SM_BBMRTCTIMEGET        DEV_SM_BbmRtcTimeGet
#endif

#ifndef SM_BBMRTCALARMSET
/*! Redirector (device/board) to set the BBM RTC alarm */
#define SM_BBMRTCALARMSET       DEV_SM_BbmRtcAlarmSet
#endif

#ifndef SM_BBMRTCROLLOVER
/*! Redirector (device/board) to enable the BBM RTC rollover interrupt */
#define SM_BBMRTCROLLOVER       DEV_SM_BbmRtcRollover
#endif

#ifndef SM_BBMBUTTONGET
/*! Redirector (device/board) to read the BBM button state */
#define SM_BBMBUTTONGET         DEV_SM_BbmButtonGet
#endif

#ifndef SM_CPUNAMEGET
/*! Redirector (device/board) to get a CPU name */
#define SM_CPUNAMEGET           DEV_SM_CpuNameGet
#endif

#ifndef SM_CPUINFOGET
/*! Redirector (device/board) to get CPU info */
#define SM_CPUINFOGET           DEV_SM_CpuInfoGet
#endif

#ifndef SM_CPUSTART
/*! Redirector (device/board) to start a CPU */
#define SM_CPUSTART             DEV_SM_CpuStart
#endif

#ifndef SM_CPUHOLD
/*! Redirector (device/board) to hold a CPU */
#define SM_CPUHOLD              DEV_SM_CpuHold
#endif

#ifndef SM_CPUSTOP
/*! Redirector (device/board) to stop a CPU */
#define SM_CPUSTOP              DEV_SM_CpuStop
#endif

#ifndef SM_CPURESETVECTORCHECK
/*! Redirector (device/board) to check a CPU reset vector */
#define SM_CPURESETVECTORCHECK  DEV_SM_CpuResetVectorCheck
#endif

#ifndef SM_CPURESETVECTORSET
/*! Redirector (device/board) to set a CPU reset vector */
#define SM_CPURESETVECTORSET    DEV_SM_CpuResetVectorSet
#endif

#ifndef SM_CPUSLEEPMODESET
/*! Redirector (device/board) to set a CPU sleep mode */
#define SM_CPUSLEEPMODESET      DEV_SM_CpuSleepModeSet
#endif

#ifndef SM_CPUIRQWAKESET
/*! Redirector (device/board) to set a CPU IRQ mask */
#define SM_CPUIRQWAKESET        DEV_SM_CpuIrqWakeSet
#endif

#ifndef SM_CPUNONIRQWAKESET
/*! Redirector (device/board) to set a CPU non-IRQ mask */
#define SM_CPUNONIRQWAKESET     DEV_SM_CpuNonIrqWakeSet
#endif

#ifndef SM_CPUPDLPMCONFIGSET
/*! Redirector (device/board) to set a CPU PD config */
#define SM_CPUPDLPMCONFIGSET    DEV_SM_CpuPdLpmConfigSet
#endif

#ifndef SM_CPUPERLPMCONFIGSET
/*! Redirector (device/board) to set a CPU peripheral config */
#define SM_CPUPERLPMCONFIGSET  DEV_SM_CpuPerLpmConfigSet
#endif

#ifndef SM_CONTROLSET
/*! Redirector (device/board) to write a control */
#define SM_CONTROLSET           DEV_SM_ControlSet
#endif

#ifndef SM_CONTROLGET
/*! Redirector (device/board) to read a control */
#define SM_CONTROLGET           DEV_SM_ControlGet
#endif

#ifndef SM_CONTROLACTION
/*! Redirector (device/board) to do a control action */
#define SM_CONTROLACTION        DEV_SM_ControlAction
#endif

#ifndef SM_CONTROLFLAGSSET
/*! Redirector (device/board) to do a control action */
#define SM_CONTROLFLAGSSET      DEV_SM_ControlFlagsSet
#endif

#ifndef SM_FAULTCOMPLETE
/*! Redirector (LMM/board) to complete a fault */
#define SM_FAULTCOMPLETE        LMM_FaultComplete
#endif

#ifndef SM_FAULTGET
/*! Redirector (device/board) to get a fault state */
#define SM_FAULTGET             DEV_SM_FaultGet
#endif

#ifndef SM_FAULTSET
/*! Redirector (device/board) to set a fault */
#define SM_FAULTSET             DEV_SM_FaultSet
#endif

#ifndef SM_FAULTREACTIONGET
/*! Redirector (LMM/board) to get a fault reaction */
#define SM_FAULTREACTIONGET     LMM_FaultReactionGet
#endif

#ifndef SM_ROMPASSOVERGET
/*! Redirector (device/board) to get ROM passover */
#define SM_ROMPASSOVERGET       DEV_SM_RomPassoverGet
#endif

#ifndef SM_RDCACCESSSET
/*! Redirector (device/board) to set device access */
#define SM_RDCACCESSSET         DEV_SM_RdcAccessSet
#endif

#ifndef SM_SIINFOGET
/*! Redirector (device/board) to get silicon info */
#define SM_SIINFOGET            DEV_SM_SiInfoGet
#endif

#ifndef SM_SYSLOGGET
/*! Redirector (device/board) to get the syslog */
#define SM_SYSLOGGET            DEV_SM_SyslogGet
#endif

#ifndef SM_SYSLOGDUMP
/*! Redirector (device/board) to dump the syslog */
#define SM_SYSLOGDUMP           DEV_SM_SyslogDump
#endif

/** @} */

#endif /* DEV_SM_API */

/** @} */

