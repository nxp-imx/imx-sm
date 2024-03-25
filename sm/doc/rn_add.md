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

- Split misc device and board controls, **board controls start at 0x8000**
- Added new SCMI_MSG_CPU_INFO_GET message and SCMI_CpuInfoGet() function
- Added new SCMI_MSG_MISC_CFG_INFO message and SCMI_MiscCfgInfo() function
- Updated FuSa protocol functions
- Added sequence functions SCMI_SequenceConfig(), SCMI_SequenceSave(), SCMI_SequenceRestore()
- Added a new SCMI_ERR_SEQ_ERROR error type

Configuration Changes {#RN_ADD_CONFIG}
=====================

The following are cfg file changes that customers will probably need to make to their cfg
files.

- Assigned CLK_ELE to the SM
- Fixed assignment of EIM_NPU and ERM_NPU
- Added VDD_SOC enable/disable via new VOLT start/stop options
- Removed assignment of SM clocks to AP-NS (Linux no longer requires)
- Update NETC, PCI, and USB SMMU parameters (KPA, SID) for Linux
- Update SW faults to reserve FAULT_SW4 for FuSa use

Board Interface Changes {#RN_ADD_BOARD}
=======================

The following interface changes will require customers make similar change to their port.

- Added BOARD_SystemSleepPrepare(), BOARD_SystemSleepEnter(), BOARD_SystemSleepExit()
  and BOARD_SystemSleepUnprepare() to support system suspend
- Added *perLpiId* to *board_uart_config_t*

Board Implementation Changes {#RN_ADD_BOARD_IMP}
============================

Customers will require the following changes to their board port.

- Modify BRD_SM_Exit() to pass the PC
- Fix issue with *errId* sign extension
- Added low-power interface data structures and functions
- Remove FCCU 1/2 interrupt enables
- Move the watchdog config to be file static

