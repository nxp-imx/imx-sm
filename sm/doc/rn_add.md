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

Supported development environments include Ubuntu 2020.04, 2022.04, and 2024.04. Supported
versions of doxygen include 1.8.17, 1.9.1, and 1.9.8.

SCMI API Changes {#RN_ADD_API}
================

The following changes can affect clients (aka agent software):

- Added SCMI_MSG_NEGOTIATE_PROTOCOL_VERSION support for all protocols, the SM only supports
  the SCMI 3.2 version of the protocols
- Added new macros for sleep mode/flags to the SYSTEM power protocol
- Added SCMI_MiscBoardInfo(), SCMI_MiscControlExtSet(), and SCMI_MiscControlExtGet() to
  the MISC protocol
- Added SCMI_BbmRtcState() to the BBM protocol

Configuration Changes {#RN_ADD_CONFIG}
=====================

The following are cfg file changes that customers **must** make to their cfg files
and rebuild their config headers.

- Move CLK_CAMISI ownership to the SM LM
- Correct second CMU_W1 to be CMU_W2

Board Interface Changes {#RN_ADD_BOARD}
=======================

The following interface changes will require customers make similar change to their port.

- Replaced SCMI_SUB_VENDOR with BRD_SM_NAME, added board attributes (BRD_SM_ATTR)
- Added sleep flags to the BOARD_SystemSleepPrepare(), BOARD_SystemSleepEnter(),
  BOARD_SystemSleepExit(), and BOARD_SystemSleepUnprepare() functions. Before these were
  passed as the sleep mode. The mode is now a new parameter.

Board Implementation Changes {#RN_ADD_BOARD_IMP}
============================

Customers may require some of the following changes in their board port.

- Passed full trim value to FRO_SetTrim(), **without this the FRO will run at the wrong
  frequency**
- Added sleep flags to the various system sleep function
- Passed new mask length parameter to PF09_IntEnable(), PF09_IntStatus(),
  and PF09_IntClear()
- Fixed issue with UART config even for a production build
- Added BBM/control support for the PCA2131 RTC found on the 15x15 EVK
- Control VDD_ARM PF53 via PF09 GPIO rahter then I2C
- Cache PF53 voltages and restore state after system sleep

**The FRO trim change is mandatory.**

