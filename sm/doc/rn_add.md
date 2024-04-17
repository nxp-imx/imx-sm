Additional Notes {#RN_ADD}
================

This section details any additional notes about the original release. These do not cover
changes in patch releases.

General {#RN_ADD_GEN}
=======

When the SM is compiled for release into production devices, it is **critical** that this
is done without the debug monitor (M=0). The default is monitor enabled (M=1). For example:

	make config=mx95evk M=0

Turning off the debug monitor will eliminate the linking of the standard C library.

The tool chain used with this SM is Arm GNU Toolchain Version **12.3.Rel1** obtained from 
[Arm GNU Toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain).
Use the x86_64 Linux hosted AArch32 bare-metal target (arm-none-eabi) toolchain.

SCMI API Changes {#RN_ADD_API}
================

The following changes can affect client (aka agent software):

- Updated to the final SCMI 3.2 spec, **not backwards compatible to BETA3**
- Added sequence functions SCMI_SequenceConfig(), SCMI_SequenceSave(), SCMI_SequenceRestore()
- Added clock state and extended clock identifiers
- Added a new SCMI_ERR_SEQ_ERROR error type
- Added new SCMI_MSG_CPU_INFO_GET message and SCMI_CpuInfoGet() function
- Added CPU run modes
- Updated FuSa protocol functions
- Added SCMI_LmmPowerOn()
- Added new SCMI_MSG_MISC_CFG_INFO message and SCMI_MiscCfgInfo() function
- Added new SCMI_MSG_MISC_SYSLOG message and SCMI_MiscSyslog() function
- Split misc device and board controls, **board controls now start at 0x8000**

Client software **must* update to the final SCMI 3.2 protocols.

Configuration Changes {#RN_ADD_CONFIG}
=====================

The following are cfg file changes that customers **must** make to their cfg files
and rebuild their config headers.

- Assigned CLK_ELE to the SM
- Fixed assignment of EIM_NPU and ERM_NPU
- Update SW faults to reserve FAULT_SW4 for FuSa use
- Added VDD_SOC enable/disable via new VOLT start/stop options
- Gave ATF all access to SYS
- Removed assignment of SM clocks to AP-NS (Linux no longer requires)
- Split DC into small functional resources
- Update NETC, PCI, and USB SMMU parameters (KPA, SID) for Linux

Board Interface Changes {#RN_ADD_BOARD}
=======================

The following interface changes will require customers make similar change to their port.

- Added pc to BRD_SM_Exit()
- Added *perLpiId* to *board_uart_config_t*
- Added BOARD_SystemSleepPrepare(), BOARD_SystemSleepEnter(), BOARD_SystemSleepExit()
  and BOARD_SystemSleepUnprepare() to support system suspend

Board Implementation Changes {#RN_ADD_BOARD_IMP}
============================

Customers may require some of the following changes in their board port.

- Fixed issue with *errId* sign extension
- Added BRD_SM_InitComplete() to allow DEV_SM init calls
- Modified BRD_SM_Exit() to pass the PC
- Added LM group reactions to BRD_SM_FaultReactionGet()
- Added function override for BRD_SM_ControlSet()
- Added support for a BRD_SM_CTRL_TEST control
- Set a default ADC clock rate of 80MHz
- Moved the watchdog config to be file static
- Added low-power interface data structures and functions
- Renamed FCCU0_IRQn to FCCU_INT0_IRQn
- Removed FCCU 1/2 interrupt enables

