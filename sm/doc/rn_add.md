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

The tool chain used with this SM is Arm GNU Toolchain Version **$TC_VER** obtained from
[Arm GNU Toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain).
Use the x86_64 Linux hosted AArch32 bare-metal target (arm-none-eabi) toolchain.

Supported development environments include Ubuntu 2020.04, 2022.04, and 2024.04. Supported
versions of doxygen include 1.8.17, 1.9.1, and 1.9.8.

SCMI API Changes {#RN_ADD_API}
================

- Added new SCMI_ERR_TIMEOUT vendor status code

Configuration Changes {#RN_ADD_CONFIG}
=====================

The following are cfg file changes that customers **must** make to their cfg files
and rebuild their config headers.

- On i.MX95, removed references to CLOCK_DISP2PIX and CLOCK_DISP3PIX

Optional:

- For V2X fast hash:
  - Gave V2X read-only access to all of DDR
  - On i.MX95, gave ELE ownership of EDMA2_CH0_1 and access to EDMA2_MP
  - On i.MX94, moved ownership of ATU_V2X to AP-NS

Board Interface Changes {#RN_ADD_BOARD}
=======================

None

Board Implementation Changes {#RN_ADD_BOARD_IMP}
============================

Customers **must** make the following changes in their board port:

- Fixed issue with the PCA2131 RTC domain index
- Increased ELE group interrupts to preempt critical
- LDO3 change if using PF53B
- PMIC init changes

Optional, but recommended:

- Added range checking to support code for the PCA2131 RTC
- On i.MX94, removed unused UART3 pin settings

