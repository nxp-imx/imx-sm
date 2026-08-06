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

- Added SCMI_MiscControlAttributes()

Configuration Changes {#RN_ADD_CONFIG}
=====================

- Added a lot of cfg files for i.MX937 boards
- Added a lot of cfg files for multiple freedom boards

No changes are required to customer cfg files but they **must** rebuild their config
headers due to parameter and version changes.

Optional:

- Change FUSA permissions from PRIV to ALL

Board Interface Changes {#RN_ADD_BOARD}
=======================

None

Board Implementation Changes {#RN_ADD_BOARD_IMP}
============================

- Added a board port for the i.MX95 15x15 LPDDR5 board
- Added a board port for the i.MX937 freedom board

Customers **must** make the following changes in their board port:

- Assuming board controls, add BRD_SM_ControlAttributes() and redirect

Optional, but recommended:

- For i.MX94 A1, remove glitch filter support

