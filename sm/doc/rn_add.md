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

- Updated to SCMI 3.2 BETA3
- Added a CPU peripheral low-power interface configuration message
- Added a platform wake flag to the CPU sleep mode flags

Configuration Changes {#RN_ADD_CONFIG}
=====================

- Updated mx95alt to allow M33 access to the SEMA41 (for testing)
- Updated mx95evk:
  - fault reactions (for testing)
  - to give AP secure (ATF) access to the peripheral LPI
  - to fix issues with mSel 1 and 2 start/stop script 

Customers will require the LPI changes if running ATF. They should also configure fault
handling as required.

Board Interface Changes {#RN_ADD_BOARD}
=======================

These are changes to the board interface:

- Defined a debug UART config structure
- Changed the BOARD_GetDebugUart() prototype

Customers will require similar changes to their ports.

Board Implementation Changes {#RN_ADD_BOARD_IMP}
============================

These are changes to the NXP reference ports:

- Added BRD_SM_SystemReset() overload to reset system instead of just the SoC
- Supported WDOG configuration for FCCU, configured for FCCU mode after FCCU init
- Moved to WDOG2 as it goes through the FCCU
- Enabled the three FCCU interrupts, disable the WDOG interrupt
- Fixed polarity of the WDOG_ANY flags
- Refactored the debug UART configuration
- Supported disable of the debug UART from the cfg file
- Disabled PF09 voltage monitors
- Disabled the PF09 PWRUP interrupt

Customers will require similar changes to their ports.

