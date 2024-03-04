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

- TBD

Configuration Changes {#RN_ADD_CONFIG}
=====================

- TBD

Board Interface Changes {#RN_ADD_BOARD}
=======================

- TBD

Board Implementation Changes {#RN_ADD_BOARD_IMP}
============================

- TBD

