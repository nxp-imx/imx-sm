Change List {#RN_CL}
===========

The tables below also indicate which patch version, if any, in the previous release (
imx_sm_2026q1) includes the change. Note some of these patches may not have been released yet and
the data could change.

SM 2026Q2 Change List {#RN_P0}
====================================

Below is a list of changes between the previous release (imx_sm_2026q1) and this release (imx_sm_2026q2).

New Feature {#RN_CL_NEW}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX94<br> (A1) | MX952<br> (A0) | MX952<br> (A1) |
|------------|-------------------------------|-------|---|---|---|---|---|
| [SM-371](https://jira.sw.nxp.com/projects/SM/issues/SM-371) | Add support for i.MX94 A1 [[detail]](@ref RN_DETAIL_SM_371) |   | | | Y | | |
| [SM-402](https://jira.sw.nxp.com/projects/SM/issues/SM-402) | Add support for i.MX952 A1 [[detail]](@ref RN_DETAIL_SM_402) |   | | | | | Y |
| [SM-405](https://jira.sw.nxp.com/projects/SM/issues/SM-405) | Add shadow fuse read/write in monitor and also support no ECC finalization [[detail]](@ref RN_DETAIL_SM_405) |   | Y | Y | Y | Y | Y |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX94<br> (A1) | MX952<br> (A0) | MX952<br> (A1) |
|------------|-------------------------------|-------|---|---|---|---|---|
| [SM-317](https://jira.sw.nxp.com/projects/SM/issues/SM-317) | Test and coding standards improvements [[detail]](@ref RN_DETAIL_SM_317) |   | Y | Y | Y | Y | Y |
| [SM-329](https://jira.sw.nxp.com/projects/SM/issues/SM-329) | Remove A55 access to the GPU CGC on i.MX952 [[detail]](@ref RN_DETAIL_SM_329) |   | | | | Y | Y |
| [SM-348](https://jira.sw.nxp.com/projects/SM/issues/SM-348) | Upgrade GCC toolchain to 15.2.rel1 [[detail]](@ref RN_DETAIL_SM_348) |   | Y | Y | Y | Y | Y |
| [SM-356](https://jira.sw.nxp.com/projects/SM/issues/SM-356) | Add support to read MBC block size and block count from TRDC registers in ERR command [[detail]](@ref RN_DETAIL_SM_356) |   | Y | Y | Y | Y | Y |
| [SM-362](https://jira.sw.nxp.com/projects/SM/issues/SM-362) | Enhance monitor with volt.r range command [[detail]](@ref RN_DETAIL_SM_362) |   | Y | Y | Y | Y | Y |
| [SM-367](https://jira.sw.nxp.com/projects/SM/issues/SM-367) | Add Android config for i.MX952 [[detail]](@ref RN_DETAIL_SM_367) |   | | | | Y | Y |
| [SM-368](https://jira.sw.nxp.com/projects/SM/issues/SM-368) | Add additional init times to btime output [[detail]](@ref RN_DETAIL_SM_368) |   | Y | Y | Y | Y | Y |
| [SM-374](https://jira.sw.nxp.com/projects/SM/issues/SM-374) | Make using the SMCT config tool fails to abort when python is not available [[detail]](@ref RN_DETAIL_SM_374) |   | Y | Y | Y | Y | Y |
| [SM-375](https://jira.sw.nxp.com/projects/SM/issues/SM-375) | Fix coding standard issues from new version of scan tools [[detail]](@ref RN_DETAIL_SM_375) |   | Y | Y | Y | Y | Y |
| [SM-378](https://jira.sw.nxp.com/projects/SM/issues/SM-378) | Enable mission and parity faults [[detail]](@ref RN_DETAIL_SM_378) |   | Y | Y | Y | Y | Y |
| [SM-384](https://jira.sw.nxp.com/projects/SM/issues/SM-384) | Switch from macros to wrapper functions to enable line coverage testing [[detail]](@ref RN_DETAIL_SM_384) |   | Y | Y | Y | Y | Y |
| [SM-385](https://jira.sw.nxp.com/projects/SM/issues/SM-385) | Enable auto boot for Android on i.MX952 [[detail]](@ref RN_DETAIL_SM_385) |   | | | | Y | Y |
| [SM-386](https://jira.sw.nxp.com/projects/SM/issues/SM-386) | Add Android cfg file for i.MX95 19x19 FRDM board [[detail]](@ref RN_DETAIL_SM_386) |   | Y | | | | |
| [SM-394](https://jira.sw.nxp.com/projects/SM/issues/SM-394) | Android cfg changes to move some VPU resources into secure env [[detail]](@ref RN_DETAIL_SM_394) |   | | | | Y | Y |
| [SM-395](https://jira.sw.nxp.com/projects/SM/issues/SM-395) | Enable debug halt for M33 WDOGs during SM startup [[detail]](@ref RN_DETAIL_SM_395) |   | Y | Y | Y | Y | Y |
| [SM-396](https://jira.sw.nxp.com/projects/SM/issues/SM-396) | Move all MISRA exceptions into SM codebase as comments [[detail]](@ref RN_DETAIL_SM_396) |   | Y | Y | Y | Y | Y |
| [SM-397](https://jira.sw.nxp.com/projects/SM/issues/SM-397) | Process TMPSNS handler only if MIX is powered on [[detail]](@ref RN_DETAIL_SM_397) |   | Y | Y | Y | Y | Y |
| [SM-400](https://jira.sw.nxp.com/projects/SM/issues/SM-400) | The crc.h filename conflicts with AUTOSAR specification [[detail]](@ref RN_DETAIL_SM_400) |   | Y | Y | Y | Y | Y |
| [SM-409](https://jira.sw.nxp.com/projects/SM/issues/SM-409) | Refactor DISP1PIX and LDBPLL clock prepare functionality to board layer [[detail]](@ref RN_DETAIL_SM_409) |   | Y | Y | Y | Y | Y |
| [SM-410](https://jira.sw.nxp.com/projects/SM/issues/SM-410) | In the mx95evkrpmsg cfg give AP partial ownership of EDMA1/EDMA2 [[detail]](@ref RN_DETAIL_SM_410) |   | Y | | | | |
| [SM-411](https://jira.sw.nxp.com/projects/SM/issues/SM-411) | Request EXCLUSIVE permission for LMM protocol commands when agent controls a foreign LM [[detail]](@ref RN_DETAIL_SM_411) |   | Y | Y | Y | Y | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX94<br> (A1) | MX952<br> (A0) | MX952<br> (A1) |
|------------|-------------------------------|-------|---|---|---|---|---|
| [SM-363](https://jira.sw.nxp.com/projects/SM/issues/SM-363) | Continuous reset if DDR not configured by OEI [[detail]](@ref RN_DETAIL_SM_363) |   | | Y | | | |
| [SM-369](https://jira.sw.nxp.com/projects/SM/issues/SM-369) | Fix SCMI compliance issue with clock attribute message [[detail]](@ref RN_DETAIL_SM_369) |   | Y | Y | Y | Y | Y |
| [SM-373](https://jira.sw.nxp.com/projects/SM/issues/SM-373) | i.MX94 EVK board port does not unmask PMIC interrupt [[detail]](@ref RN_DETAIL_SM_373) |   | | Y | Y | | |
| [SM-376](https://jira.sw.nxp.com/projects/SM/issues/SM-376) | Too many arguments on monitor command overflows buffers [[detail]](@ref RN_DETAIL_SM_376) |   | Y | Y | Y | Y | Y |
| [SM-377](https://jira.sw.nxp.com/projects/SM/issues/SM-377) | Remove undefined configtool resources [[detail]](@ref RN_DETAIL_SM_377) |   | | | | Y | Y |
| [SM-381](https://jira.sw.nxp.com/projects/SM/issues/SM-381) | Insufficient error checking when parsing monitor commands [[detail]](@ref RN_DETAIL_SM_381) |   | Y | Y | Y | Y | Y |
| [SM-383](https://jira.sw.nxp.com/projects/SM/issues/SM-383) | Fuse FRO trim value not used [[detail]](@ref RN_DETAIL_SM_383) |   | Y | Y | Y | Y | Y |
| [SM-393](https://jira.sw.nxp.com/projects/SM/issues/SM-393) | Incorrect MDAC for i.MX952 VPU-related resources [[detail]](@ref RN_DETAIL_SM_393) |   | | | | Y | Y |
| [SM-401](https://jira.sw.nxp.com/projects/SM/issues/SM-401) | Add missing DAISY IOMUX permissions to config file for i.MX952 [[detail]](@ref RN_DETAIL_SM_401) |   | | | | Y | Y |
| [SM-403](https://jira.sw.nxp.com/projects/SM/issues/SM-403) | Parallel make does not handle the all target [[detail]](@ref RN_DETAIL_SM_403) |   | Y | Y | Y | Y | Y |
| [SM-406](https://jira.sw.nxp.com/projects/SM/issues/SM-406) | Incorrect handling of seenvId in FUSA SEENV state management functions [[detail]](@ref RN_DETAIL_SM_406) |   | Y | Y | Y | Y | Y |
| [SM-408](https://jira.sw.nxp.com/projects/SM/issues/SM-408) | Some SM owned pins also assigned to other LMs [[detail]](@ref RN_DETAIL_SM_408) |   | | Y | Y | | |
| [SM-412](https://jira.sw.nxp.com/projects/SM/issues/SM-412) | Add missing pins for i.MX952 [[detail]](@ref RN_DETAIL_SM_412) |   | | | | Y | Y |
| [SM-414](https://jira.sw.nxp.com/projects/SM/issues/SM-414) | Early device init errors not retained [[detail]](@ref RN_DETAIL_SM_414) |   | Y | Y | Y | Y | Y |

Silicon Workaround {#RN_CL_REQ}
------------

These are a mix of silicon errata workarounds and recommended usage changes.

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX94<br> (A1) | MX952<br> (A0) | MX952<br> (A1) |
|------------|-------------------------------|-------|---|---|---|---|---|
| [SM-342](https://jira.sw.nxp.com/projects/SM/issues/SM-342) | Implement SWA for ERR053228 (CORTEXAMIX MTR repair can fail at various clock rates) [[detail]](@ref RN_DETAIL_SM_342) |   | | Y | Y | | |
| [SM-358](https://jira.sw.nxp.com/projects/SM/issues/SM-358) | Manage WDOG instances enabled during ROM phase [[detail]](@ref RN_DETAIL_SM_358) |   | Y | Y | | Y | Y |
| [SM-365](https://jira.sw.nxp.com/projects/SM/issues/SM-365) | Support i.MX952 DDR PHY scaling restrictions for VDD_SOC |   | | | | Y | Y |
| [SM-366](https://jira.sw.nxp.com/projects/SM/issues/SM-366) | Avoid applying PF09 RevB errata workarounds to other revs [[detail]](@ref RN_DETAIL_SM_366) |   | Y | Y | Y | Y | Y |
| [SM-390](https://jira.sw.nxp.com/projects/SM/issues/SM-390) | Fix ENET clock to 266MHz on iMX952 [[detail]](@ref RN_DETAIL_SM_390) |   | | | | Y | Y |
| [SM-392](https://jira.sw.nxp.com/projects/SM/issues/SM-392) | Disable mission faults as the response time for many PCIe cards exceeds 10ms [[detail]](@ref RN_DETAIL_SM_392) |   | Y | Y | Y | Y | Y |
| [SM-398](https://jira.sw.nxp.com/projects/SM/issues/SM-398) | Enable DDR RX replica SW workaround [[detail]](@ref RN_DETAIL_SM_398) |   | | | | Y | Y |
| [SM-413](https://jira.sw.nxp.com/projects/SM/issues/SM-413) | Disable FCCU parity fault 61 due to incorrect triggers (ERR053263) [[detail]](@ref RN_DETAIL_SM_413) |   | Y | Y | Y | Y | Y |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX94<br> (A1) | MX952<br> (A0) | MX952<br> (A1) |
|------------|-------------------------------|-------|---|---|---|---|---|
| [SM-364](https://jira.sw.nxp.com/projects/SM/issues/SM-364) | SM 2026Q2 documentation updates |   | Y | Y | Y | Y | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-317: Test and coding standards improvements {#RN_DETAIL_SM_317}
----------

Added test code to increase function, statement, and branch coverage.

SM-329: Remove A55 access to the GPU CGC on i.MX952 {#RN_DETAIL_SM_329}
----------

Enable GPU auto clock gating and remove AP access to the GPU LPCG node. 

SM-342: Implement SWA for ERR053228 (CORTEXAMIX MTR repair can fail at various clock rates) {#RN_DETAIL_SM_342}
----------

Add a delay to the reset de-assert phase of the mix power up sequence. 
 

SM-348: Upgrade GCC toolchain to 15.2.rel1 {#RN_DETAIL_SM_348}
----------

Moved to the 15.2.rel1 version of the GCC toolchain. No code changes required.

[arm-gnu-toolchain-15.2.rel1-x86_64-arm-none-eabi.tar.xz](https://developer.arm.com/-/media/Files/downloads/gnu/15.2.rel1/binrel/arm-gnu-toolchain-15.2.rel1-x86_64-arm-none-eabi.tar.xz)

SM-356: Add support to read MBC block size and block count from TRDC registers in ERR command {#RN_DETAIL_SM_356}
----------

Logic added to read the MBC slave memory block sizes and the number of blocks from the global configuration register which will enable accurate calculation of the block number for addresses reported in the Domain Error Word Register during access violation detection by the MBC.

SM-358: Manage WDOG instances enabled during ROM phase {#RN_DETAIL_SM_358}
----------

A fuse can be blown to configure the ROM to enable a watchdog (usually WDOG1) at boot. As WDOG1 does not go to the FCCU, the SM uses WDOG2 which does. As a result, the SM needs to disable (or mask in the SRC which is faster) WDOG1 after WDOG2 is configured and providing protection.

This change is to modify NXP reference board ports to mask WDOG1 immediately after full configuration of WDOG2. If customers plan to use the ROM WDOG feature, they will need similar code in their board port (board.c).

SM-362: Enhance monitor with volt.r range command {#RN_DETAIL_SM_362}
----------

Monitor command "volt.r" has been enhanced to support "range" option.

    volt.r [vlt]            display mode/microvolts of vlt (default = all)
    volt.r [vlt] range      display range of vlt (default = all)

SM-363: Continuous reset if DDR not configured by OEI {#RN_DETAIL_SM_363}
----------

Added code to check DDR clocks to see if enabled by OEI. If not, power down the DDR MIX.

SM-366: Avoid applying PF09 RevB errata workarounds to other revs {#RN_DETAIL_SM_366}
----------

Used PF09 silicon rev to apply errata workarounds.

SM-367: Add Android config for i.MX952 {#RN_DETAIL_SM_367}
----------

Added a new mx952evk-android.cfg file for use with Android. This file is in the others directory so the cfg must be built.

SM-368: Add additional init times to btime output {#RN_DETAIL_SM_368}
----------

Added output of device and board init times with new "btime init" command (actually btime with any argument). Customers should add the same board code metrics capture to their board port. This will allow customers to optimize their board design and initialization.

SM-369: Fix SCMI compliance issue with clock attribute message {#RN_DETAIL_SM_369}
----------

The SCMI CLOCK_ATTRIBUTES message was missing a new field added in SCMI 3.1 final. This field is clockEnableDelay. This fix adds the field and always sets to 0 in order to be compliant. This change is not backwards compatible as it makes the response message longer.

Depending on the agent SCMI implementation, this change may require the agent be updated to accept the longer message response. SPL/ATF/u-boot/Linux/MCUX-SDK must all be on the 2026 Q2 version or later.

SM-371: Add support for i.MX94 A1 {#RN_DETAIL_SM_371}
----------

Modified the i.MX94 device support to conditionalize some behaviors based on silicon rev. This includes using the glitch filter bypass on A1 (or later) and only enabling the glitch filter for A0. Only keeping the FRO enabled during suspend on A0 (the FRO clocks the glitch filter).

SM-373: i.MX94 EVK board port does not unmask PMIC interrupt {#RN_DETAIL_SM_373}
----------

Updated the PCAL6416A_INITIAL_MASK define for the i.MX94 EVK board port. It did not unmask the interrupt from the PMIC. Customers only need to do this if they have copied the bus expander logic from the EVK.

SM-374: Make using the SMCT config tool fails to abort when python is not available {#RN_DETAIL_SM_374}
----------

New way of launching the 'smct' configuration tool during build process. The 'make cfg SMCT=1' will attempt to lauch the smct tool assuming it is installed on PATH. Alternatively, use the 'make cfg SMCT=smct-dir'. 

SM-375: Fix coding standard issues from new version of scan tools {#RN_DETAIL_SM_375}
----------

Fixed MISRA issues identified by Coverity scan.

SM-376: Too many arguments on monitor command overflows buffers {#RN_DETAIL_SM_376}
----------

Added buffer overflow checks to the monitor code. Increased the buffer size to 30 to allow the 24+3 word commands to extctrl.w for the PCA2131 RTC.

SM-377: Remove undefined configtool resources {#RN_DETAIL_SM_377}
----------

Removed unused configtool resources. None of these were used so removal does not change the resulting config header files.
 
- CLK_ELE
- ATU_M
- GPV_MAIN
- JTAG
- SRAM_CTL_N
- CLOCK_ISI
- CAN_FD4
- CAN_FD5
- PCI2_LUT0
- PCI2_LUT1
- PCI2_LUT2
- PCI2_LUT3
- PCI2_LUT4
- PCI2_LUT5
- PCI2_LUT6
- PCI2_LUT7
- PCIE2_OUT
- PCIE2_ROOT
- SPDIF1

Customers should also remove.

SM-378: Enable mission and parity faults {#RN_DETAIL_SM_378}
----------

Enable Mission and Parity Faults. Set the NOC fabric timeouts to maximum. 

SM-381: Insufficient error checking when parsing monitor commands {#RN_DETAIL_SM_381}
----------

The SM debug monitor did not fully check arguments for validity in a few cases. All failing cases are parsing where a numerical argument is expected but instead a text argument is entered. In these cases, the text is treated as 0 rather than an invalid input. This could result in an unexpected result or it might still result in an error (maybe different error) if 0 is not a valid parameter.

- perf.w domain text
- clock.r clock ex text
- clock.w clock ex text text
- md text text
- mm text text
- pmic.r text text
- pmic.w text text text


SM-383: Fuse FRO trim value not used {#RN_DETAIL_SM_383}
----------

Ensure the fuses are initialized very early in the boot sequence.

SM-384: Switch from macros to wrapper functions to enable line coverage testing {#RN_DETAIL_SM_384}
----------

The methodology for testing error handling has been changed. Before SM_TEST macros were placed in the code to force error responses. Those have all been removed and instead the GNU linker wrap feature is used. This feature allows linker phase wrapping of lower-level functions to then alter response behavior to for calls from upper layer code.

SM-385: Enable auto boot for Android on i.MX952 {#RN_DETAIL_SM_385}
----------

Updated Android cfg to boot the AP core on button press.

SM-386: Add Android cfg file for i.MX95 19x19 FRDM board {#RN_DETAIL_SM_386}
----------

Add Android cfg file for i.MX95 19x19 FRDM board. The file is mx95frdm-pro-android.cfg and in the other directory so the cfg must be built.

SM-390: Fix ENET clock to 266MHz on iMX952 {#RN_DETAIL_SM_390}
----------

Drop ENET clock to 266MHz to support both SGMII and RGMII modes

SM-392: Disable mission faults as the response time for many PCIe cards exceeds 10ms {#RN_DETAIL_SM_392}
----------

Disable NOCMIX and WakeupMIX mission faults since the max timeout allowed by current HW design is lower than the minimum timeout specified by many PCIE devices. 

SM-393: Incorrect MDAC for i.MX952 VPU-related resources {#RN_DETAIL_SM_393}
----------

Updated the VPU resource mapping to be consistent with the i.MX952 RM.

SM-394: Android cfg changes to move some VPU resources into secure env {#RN_DETAIL_SM_394}
----------

Moved the following resources from AP-NS to AP-S.

- VPU_DEC
- VPU_DEC1
- VPU_DEC2

This is to support secure video decode in Android.

SM-395: Enable debug halt for M33 WDOGs during SM startup {#RN_DETAIL_SM_395}
----------

Modified startup code to configure WDOG 1/2 to halt when a debugger is attached. Adding a looper before this at the reset vector will result in a reset if WDOG1 is enabled in ROM. Halting with a debugger at the reset vector will also result in a reset.

SM-396: Move all MISRA exceptions into SM codebase as comments {#RN_DETAIL_SM_396}
----------

Most MISRA violations were only exceptioned in the scan tool server. Moved exception info to the source code using scan tool exception comments and a comment with the explanation.

SM-397: Process TMPSNS handler only if MIX is powered on {#RN_DETAIL_SM_397}
----------

Updated the TMPSNS sensor handler to access sensor registers only when the associated MIX power domain is powered on.

SM-398: Enable DDR RX replica SW workaround {#RN_DETAIL_SM_398}
----------

Modified the i.MX952 configs to enable DDR RX Replica SW workaround.

SM-400: The crc.h filename conflicts with AUTOSAR specification {#RN_DETAIL_SM_400}
----------

Renamed crc.h to sm_crc.h and crc.c to sm_crc.c.

SM-401: Add missing DAISY IOMUX permissions to config file for i.MX952 {#RN_DETAIL_SM_401}
----------

Added USB related DAISY entries to config file. Customers would need to do the same for their custom config files. 

SM-402: Add support for i.MX952 A1 {#RN_DETAIL_SM_402}
----------

No SM changes required for this new i.MX952 silicon revision.

SM-403: Parallel make does not handle the all target {#RN_DETAIL_SM_403}
----------

Modified makefile all target to serialize clean and image build.

SM-405: Add shadow fuse read/write in monitor and also support no ECC finalization {#RN_DETAIL_SM_405}
----------

Added sfuse.r/sfuse.w commands to interact with fuse shadows. Added 3rd parameter to fuse.w to not finalize the ECC.

| Command                     | Description                                                  |
|-----------------------------|--------------------------------------------------------------|
| fuse.r *wordIdx* [*count*]  | display *count* number of fuse words starting at *wordIdx*   |
| fuse.w *wordIdx* *value* [*noecc*]   | write *value* to fuse *wordIdx* (try) *noecc* update|
| sfuse.r *wordIdx* [*count*] | display *count* no of words starting at *wordIdx* frm shadows|
| sfuse.w *wordIdx* *value*   | write *value* to fuse shadows *wordIdx* (if possible)        |


SM-406: Incorrect handling of seenvId in FUSA SEENV state management functions {#RN_DETAIL_SM_406}
----------

Fixed incorrect seenvId handling in FUSA SEENV state management functions:

- LMM_FusaSeenvStateGet(): Updated to use target->seenvId to get the seenvState.
- LMM_FusaSeenvStateSet(): Updated to use seenvState paramete to set the seenvState.
- SCMI RPC handlers: Updated to add offset adjustments to caller's seenvId in FusaSeenvStateGet() and FusaSeenvStateSet() functions.

SM-408: Some SM owned pins also assigned to other LMs {#RN_DETAIL_SM_408}
----------

Removed duplicate SM-owned pin assignments and corrected LM ownership in imx94evk configuration.

SM-409: Refactor DISP1PIX and LDBPLL clock prepare functionality to board layer {#RN_DETAIL_SM_409}
----------

Some operating systems, such as Linux, do not currently support automatically setting the parent rate of SCMI-based clocks. An example of this can be seen with the DISP1PIX clock on the i.MX 95 SoC. This means only a single parent frequency is supported at
runtime, and any set rate calls for a clock root (such as DISP1PIX) must request a rate that is divisible from this initial parent PLL frequency.

This code redirects an incoming clock set rate call from the operating system and will automatically set the parent clock's rate based on a table of known working frequency combinations. This mechanism is referred to as clock source preparation, and at present only the DISP1PIX and LDBPLL clocks are supported.

The SM device layer maintains a state variable (SRCPRE) to indicate if clock source preparation should occur. By default, the clock source preparation behavior is ENABLED.
This variable can be changed with the clock extended function using the DEV_SM_CLOCK_EXT_SRCPRE value. An agent, such as Linux, can call SCMI_ClockConfigSet() to disable it. When SRCPRE is enabled and a set rate request is received for a supported clock, the appropriate board code may:

- Detect known pixel clock rates (e.g. 297MHz, 148.5MHz, etc.)
- Compute PLL parameters (mfi, mfn, odiv)
- Program the appropriate PLL directly via: FRACTPLL_UpdateRate()
- Force rounding mode to CLK_ROUND_AUTO

Customers may want to duplicate this functionality in their board ports and fine tune it for their specific display use-case.

SM-410: In the mx95evkrpmsg cfg give AP partial ownership of EDMA1/EDMA2 {#RN_DETAIL_SM_410}
----------

In the mx95evkrpmsg.cfg file, moved most of the eDMA1/2 resource from the M7 to AP-NS.

SM-411: Request EXCLUSIVE permission for LMM protocol commands when agent controls a foreign LM {#RN_DETAIL_SM_411}
----------

SCMI LMM protocol permission check updated. An EXCLUSIVE permission level is required when a client agent controls a foreign LM. The PRIV level remains good to access agent's own parent LM. 

SM-412: Add missing pins for i.MX952 {#RN_DETAIL_SM_412}
----------

Added the following missing pins:

    GPIO_IO38   42U
    GPIO_IO39   43U
    GPIO_IO40   44U
    LD_SPI_CS0  45U
    LD_SPI_SCK  46U
    LD_SPI_DI   47U
    LD_SPI_DO   48U
    LD_HSYNC    49U
    LD_VSYNC    50U
    LD_GPIO0    51U
    LD_GPIO1    52U

SM-413: Disable FCCU parity fault 61 due to incorrect triggers (ERR053263) {#RN_DETAIL_SM_413}
----------

Disable fault 61 due to ERR053263. 

SM-414: Early device init errors not retained {#RN_DETAIL_SM_414}
----------

During device init, early error responses were overwritten with DEV_SM_SUCCESS. This would cause additional init steps to be run and possibly bus error. Code restructured to no do this overwrite. 

