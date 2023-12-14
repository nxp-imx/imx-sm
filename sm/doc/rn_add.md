Additional Notes {#RN_ADD}
================

This section details any additional notes about the original release. These do not cover
changes in patch releases.

General {#RN_ADD_GEN}
=======

When the SM is compiled for release into production devices, it is critical that this is
done without the debug monitor (M=0). The default is monitor enabled (M=1). For example:

	make config=mx95evk M=0

Turning off the debug monitor will eliminate the linking of the standard C library.

The tool chain used with this SM is Arm GNU Toolchain Version **12.3.Rel1** obtained from 
[Arm GNU Toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain).
Use the x86_64 Linux hosted AArch32 bare-metal target (arm-none-eabi) toolchain.

SCMI API Changes {#RN_ADD_API}
================

- Final updates for SCMI version 3.2
- Added new CLOCK_GET_PERMISSIONS; removed NXP-specific permission attributes

Configuration Changes {#RN_ADD_CONFIG}
=====================

For all NXP reference configs:

- Defined an ACCESS macro to indicate access only, not owning the bus master DID
- Used ACCESS to give the M33 (SM) access to the GIC
- Moved BUTTON access from AP secure to AP non-secure
- Gave AP non-secure execute access to the ISP OCRAM
- Cleaned up of some duplicate assignments
- Updated BLK_CTRL names in configtool to match latest SoC RM:
  - BLK_CTRL_C -> BLK_CTRL_CAMERAMIX
  - BLK_CTRL_D -> BLK_CTRL_DISPLAYMIX
  - BLK_CTRL_G -> BLK_CTRL_GPUMIX
  - BLK_CTRL_H -> BLK_CTRL_HSIOMIX
  - BLK_CTRL_E -> BLK_CTRL_NETCMIX
  - BLK_CTRL_V -> BLK_CTRL_VPUMIX
- Updated V2X names:
  - V2X_APP1 -> V2X_SHE1
  - V2X_SHE -> V2X_SHE0
- Updated V2X_FH ownership to V2X (DID=12) and no MDAC DID assignment for AP-NS (mdid=none)

**Customers must make similar changes to their cfg files.**

Board Interface Changes {#RN_ADD_BOARD}
=======================

None

Board Implementation Changes {#RN_ADD_BOARD_IMP}
============================

For all NXP reference board ports:

- Fixed an issue with bus expander control flag polarity
- Changed resource text (e.g. board sensors, voltages) to lower-case
- Disabled the PF09 monitoring of the PF53 voltages.

**Customers should make similar changes to their board port.**

