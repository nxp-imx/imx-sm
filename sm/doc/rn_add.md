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

- Fixed non-compliance issue with the clock protocol, added clockEnableDelay to
  SCMI_ClockAttributes(), **not backwards compatible**

Configuration Changes {#RN_ADD_CONFIG}
=====================

The following are cfg file changes that customers **must** make to their cfg files
and rebuild their config headers.

- For i.MX94, removed AP-NS access to SM owned pins
- For i.MX952, removed unused resources, added new pins (assigned to AP-NS)

Optional:

- Defined fault reactions for mission and parity faults (default is system reset)
- Lots of changes to cfg files delivered in *other*

Board Interface Changes {#RN_ADD_BOARD}
=======================

None

Board Implementation Changes {#RN_ADD_BOARD_IMP}
============================

Customers **must** make the following changes in their board port:

- Disallowed ROM WDOG from resetting the system after SM WDOG enabled
- Made debounce setting specific to rev B0 PMIC only
- For i.MX94 boards, fixed bus expander mask to enable PMIC interrupts

Optional, but recommended:

- Added clock overrides for display clocks (required for Linux)
- Added capture of board init times
- Use DEV_SM_SystemHalt() in place of infinite while loop (halting)
- Use PMIC register defines
- For i.MX94 boards, made init of the glitchfilter optional based on silicon rev,
  let FRO go off in system suspend
- Misc. coding standards and test coverage fixes


