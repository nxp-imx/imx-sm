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

None

Configuration Changes {#RN_ADD_CONFIG}
=====================

The following are cfg file changes that customers **must** make to their cfg files
and rebuild their config headers.

- Added BOARD command to define board parameters, replaces UART and PMIC commands
- Added sema parameter for CPUs. **Must** be defined for the Cortex-A platform resource,
  otherwise Linux will not boot.
- Moved 256K of OCRAM to secure for ATF
- Removed A55 ROM
- Added new clock resources (CLOCK_EXT, CLOCK_DISP1PIX, etc.)
- Reduced ELE DDR range
- Move user manual config from config_dev.h to config_user.h.

The following are changes made to NXP configurations that are customer optional:

- Lots of cleanup (sort items, full 36-bit memory addresses, move some resources/APIs to
  correct section)
- Moved MSGINTR1 to the M7
- Removed AP access to M7 TCM
- Added missing clocks used by the SM (LM0)
- Gave AP rights to set PCA2131 alarm
- Fixed incorrect reference to msel=2 (should be 1)
- Added configinfo to dump a cfg file in an md table format
- Added permission defines to cfg files to better support configinfo
- Updated all API sections to use permission defines
- Updated ELE section of cfg files to use memory defines
- Updated V2X section to use owner defines
- Disabled CRC for M7 SMT channels in the mx95alt.cfg file

Board Interface Changes {#RN_ADD_BOARD}
=======================

None

Board Implementation Changes {#RN_ADD_BOARD_IMP}
============================

Customers **must** make the following changes in their board port:

- PMIC configuration changes to workaround PMIC errata
- Changes to save/restore the PF53 voltages across system sleep
- Define BOARD_PMIC_RESUME_TICKS for optimal resume time

The following are changes made to NXP ports that are customer optional but
strongly recommended:

- Update shutdown record from PMIC fault status
- Coding standards fixes

