Change List {#RN_CL}
===========

The tables below also indicate which patch version, if any, in the previous release (
imx_sm_2025q4) includes the change. Note some of these patches may not have been released yet and
the data could change.

SM 2026Q1 Change List {#RN_P0}
====================================

Below is a list of changes between the previous release (imx_sm_2025q4) and this release (imx_sm_2026q1_er1).

New Feature {#RN_CL_NEW}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX952<br> (A0) |
|------------|-------------------------------|-------|---|---|---|
| [SM-156](https://jira.sw.nxp.com/projects/SM/issues/SM-156) | Add support for i.MX952 [[detail]](@ref RN_DETAIL_SM_156) |   | | | Y |
| [SM-158](https://jira.sw.nxp.com/projects/SM/issues/SM-158) | Add support for the i.MX952 EVK [[detail]](@ref RN_DETAIL_SM_158) |   | | | Y |
| [SM-321](https://jira.sw.nxp.com/projects/SM/issues/SM-321) | Add config file for the FRDM-IMX95-PRO board [[detail]](@ref RN_DETAIL_SM_321) |   | Y | | |
| [SM-328](https://jira.sw.nxp.com/projects/SM/issues/SM-328) | Add MX95 device-level support to configure VIDEO_PLL1 during DISP1PIX rate set [[detail]](@ref RN_DETAIL_SM_328) |   | Y | | |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX952<br> (A0) |
|------------|-------------------------------|-------|---|---|---|
| [SM-322](https://jira.sw.nxp.com/projects/SM/issues/SM-322) | Give AP NS LMM 1 API access in mx95evksof [[detail]](@ref RN_DETAIL_SM_322) |   | Y | | |
| [SM-323](https://jira.sw.nxp.com/projects/SM/issues/SM-323) | Improve ELE reset logging [[detail]](@ref RN_DETAIL_SM_323) |   | Y | Y | Y |
| [SM-324](https://jira.sw.nxp.com/projects/SM/issues/SM-324) | Support fuse.r reading multiple fuses [[detail]](@ref RN_DETAIL_SM_324) |   | Y | Y | Y |
| [SM-332](https://jira.sw.nxp.com/projects/SM/issues/SM-332) | Sync misc. changes across SoC [[detail]](@ref RN_DETAIL_SM_332) |   | Y | Y | Y |
| [SM-337](https://jira.sw.nxp.com/projects/SM/issues/SM-337) | Disallow RTC time and alarm configuration outside of range [[detail]](@ref RN_DETAIL_SM_337) |   | Y | Y | Y |
| [SM-339](https://jira.sw.nxp.com/projects/SM/issues/SM-339) | Support V2X fast hash for uboot and kernel containers authentication [[detail]](@ref RN_DETAIL_SM_339) |   | Y | Y | Y |
| [SM-343](https://jira.sw.nxp.com/projects/SM/issues/SM-343) | Assign GPIO2 to M7 in the mx952evkrpmsg cfg [[detail]](@ref RN_DETAIL_SM_343) |   | | | Y |
| [SM-347](https://jira.sw.nxp.com/projects/SM/issues/SM-347) | Update to latest SDK header files for i.MX952 [[detail]](@ref RN_DETAIL_SM_347) |   | | | Y |
| [SM-350](https://jira.sw.nxp.com/projects/SM/issues/SM-350) | Give SEMA41 access to SM for testing on i.MX952 [[detail]](@ref RN_DETAIL_SM_350) |   | | | Y |
| [SM-351](https://jira.sw.nxp.com/projects/SM/issues/SM-351) | Misc. coding standards fixes [[detail]](@ref RN_DETAIL_SM_351) |   | | | Y |
| [SM-353](https://jira.sw.nxp.com/projects/SM/issues/SM-353) | Add alt mode selections to start M70 or M71 [[detail]](@ref RN_DETAIL_SM_353) |   | | Y | |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX952<br> (A0) |
|------------|-------------------------------|-------|---|---|---|
| [SM-327](https://jira.sw.nxp.com/projects/SM/issues/SM-327) | Resources associated with mixes disabled in fuses should not be accessible [[detail]](@ref RN_DETAIL_SM_327) |   | Y | Y | Y |
| [SM-330](https://jira.sw.nxp.com/projects/SM/issues/SM-330) | Configtool does not support hash comments unless at the start of a line [[detail]](@ref RN_DETAIL_SM_330) |   | Y | Y | Y |
| [SM-333](https://jira.sw.nxp.com/projects/SM/issues/SM-333) | Duplicate atomic resources used in MIMX94 XSPI_RESPONDR macro [[detail]](@ref RN_DETAIL_SM_333) |   | | Y | |
| [SM-335](https://jira.sw.nxp.com/projects/SM/issues/SM-335) | Only first BBNSM RTC rollover generates a notification [[detail]](@ref RN_DETAIL_SM_335) |   | Y | Y | Y |
| [SM-336](https://jira.sw.nxp.com/projects/SM/issues/SM-336) | Incorrect index assigned for board RTC instance [[detail]](@ref RN_DETAIL_SM_336) |   | Y | Y | Y |
| [SM-341](https://jira.sw.nxp.com/projects/SM/issues/SM-341) | SCMI misc unit test fails if no OEI init of DDR [[detail]](@ref RN_DETAIL_SM_341) |   | Y | Y | Y |
| [SM-346](https://jira.sw.nxp.com/projects/SM/issues/SM-346) | Fix DDR RX Replica sequence: re-enable PHY master before locking PHY CSRs [[detail]](@ref RN_DETAIL_SM_346) |   | Y | Y | Y |
| [SM-349](https://jira.sw.nxp.com/projects/SM/issues/SM-349) | Allow M7 to access EDMA2_MP for i.MX95EVK-RPSMG & SOF [[detail]](@ref RN_DETAIL_SM_349) |   | Y | | |
| [SM-354](https://jira.sw.nxp.com/projects/SM/issues/SM-354) | Incorrect source input for dram_apb_clk_root [[detail]](@ref RN_DETAIL_SM_354) |   | Y | | Y |

Silicon Workaround {#RN_CL_REQ}
------------

These are a mix of silicon errata workarounds and recommended usage changes.

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX952<br> (A0) |
|------------|-------------------------------|-------|---|---|---|
| [SM-334](https://jira.sw.nxp.com/projects/SM/issues/SM-334) | Implement SWA for ERR052794 (DDR Self refresh workaround) [[detail]](@ref RN_DETAIL_SM_334) |   | Y | Y | Y |
| [SM-345](https://jira.sw.nxp.com/projects/SM/issues/SM-345) | Manage CGCs that interfere with CPU shutdown [[detail]](@ref RN_DETAIL_SM_345) |   | | | Y |
| [SM-355](https://jira.sw.nxp.com/projects/SM/issues/SM-355) | Reassign V2X MDAC to workaround a V2X ROM authentication issue [[detail]](@ref RN_DETAIL_SM_355) |   | | | Y |
| [SM-359](https://jira.sw.nxp.com/projects/SM/issues/SM-359) | Add optional code to bounce the BBSM supply on reset [[detail]](@ref RN_DETAIL_SM_359) |   | | | Y |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX952<br> (A0) |
|------------|-------------------------------|-------|---|---|---|
| [SM-331](https://jira.sw.nxp.com/projects/SM/issues/SM-331) | SM 2026Q1 documentation updates |   | Y | Y | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-156: Add support for i.MX952 {#RN_DETAIL_SM_156}
----------

Added device support for [i.MX952 family devices](@ref DEV_SM_MX952) inc. i.MX9529. See the devices/MIMX952 directory.

Cfg files targeted at this device should include the following:

    MAKE soc=MIMX952, board=<board name>, build=gcc_cross

    include ../devices/MIMX952/configtool/device.cfg

Note the list of resources, memory areas, etc. are different from i.MX95. See the configs/mx952evk.cfg file for reference.

SM-158: Add support for the i.MX952 EVK {#RN_DETAIL_SM_158}
----------

Added board support for the [i.MX952 EVK](@ref BRD_SM_MX952EVK). See the boards/mcimx952evk directory. Compile with the following:

    make config=mx952evk

Information about this port can be found in the [NXP i.MX952 EVK](@ref PORT_MX952_EVK) section of the RM.

Cfg files targeted at this board should include the following:

    MAKE soc=MIMX952, board=mcimx952evk, build=gcc_cross

Also added board support for the [i.MX952 stub](@ref BRD_SM_MX952STUB) (minimal board access). See the boards/mcimx952stub directory.

Information about this port can be found in the [NXP i.MX952 Stub](@ref PORT_MX952_SB) section of the RM.

Cfg files targeted at this board should include the following:

    MAKE soc=MIMX952, board=mcimx952stub, build=gcc_cross

This port is used mostly for emulation, early bring-up, and the DDR stress test tool. It does not contain code that will access PMICs, I2C devices, or GPIO.

SM-321: Add config file for the FRDM-IMX95-PRO board {#RN_DETAIL_SM_321}
----------

Added a new cfg file for the FRDM-PRO-IMX95 board. The file is in other/mx95frdm-pro.cfg. It can be used by building the config and then compiling.

make config=mx95frdm-pro cfg
make config=mx95frdm-pro all

SM-322: Give AP NS LMM 1 API access in mx95evksof {#RN_DETAIL_SM_322}
----------

Modified the cfg file to give the AP core control over the M7 LM.

SM-323: Improve ELE reset logging {#RN_DETAIL_SM_323}
----------

Made ELE group resets preemptive. Centralized the handling of these resets. Modified the ELE debug dump function to timeout. This allows customer modification of the ELE handler to perform an ELE debug dump. Added a new SCMI status code (SCMI_ERR_TIMEOUT) that will be returned on hardware timeouts, including an ELE dump request.

Note this requires changes to the board port to increase the ELE group resets to IRQ_PRIO_PREEMPT_CRITICAL. Customers should make the same change.

SM-324: Support fuse.r reading multiple fuses {#RN_DETAIL_SM_324}
----------

Enhanced the SM debug monitor to support the fuse.r command with an optional second argument specifying the number of sequential fuse words to read and display. If the second argument is not passed, the default is 1.
 * When reading a single word (default or one argument) and an error occurs, the error is displayed.
 * When reading multiple words, any unreadable fuse words are skipped without stopping the loop.
 * Added bounds checking to ensure the requested range does not exceed the maximum number of fuses.
 * Verified that reading from 0 to max does not trigger the watchdog; if it does, the loop will service the watchdog as needed.
 * Updated monitor.md documentation to reflect the new command behavior and usage.

SM-327: Resources associated with mixes disabled in fuses should not be accessible {#RN_DETAIL_SM_327}
----------

Clock/perf/power/reset dumps from SM will only list resources that are not disabled by fuses.

On i.MX95, removed CLOCK_DISP2PIX and CLOCK_DISP3PIX as they don't exist in hardware.

SM-328: Add MX95 device-level support to configure VIDEO_PLL1 during DISP1PIX rate set {#RN_DETAIL_SM_328}
----------

Problem: Some host operating systems do not support multiple VIDEOPLL1 and VIDEOPLL1_VCO frequencies, which limits supported video modes to those which have a pixel clock divisible from a single VIDEOPLL1 frequency.

Fix: Add support for dynamically configuring VIDEOPLL1 and VIDEOPLL1_VCO frequencies. The code maps a known set of pixel clock rates to suitable VIDEOPLL1 and VIDEOPLL1_VCO frequencies. Currently supported MIPI DSI pixel clock rates (in MHz):
  297, 296.703, 241.5, 148.5, 148.352, 108.108, 74.25, 74.176, 71, 65, 54.054, 54, 40, 27.027, 27, 25.2, 25.175.

SM-330: Configtool does not support hash comments unless at the start of a line {#RN_DETAIL_SM_330}
----------

Add code to the configtool to remove trailing comments from a line. Existing code only removed comment lines (complete lines started with a hash).

Also fixed issue when cfg files had CR/LF line endings.

SM-332: Sync misc. changes across SoC {#RN_DETAIL_SM_332}
----------

Copied various header changes to align SoC.

SM-333: Duplicate atomic resources used in MIMX94 XSPI_RESPONDR macro {#RN_DETAIL_SM_333}
----------

Removed the duplicate DAISY entries. Results in no changes to the generated header files. This change is to satisfy error checking in the FuSa config tool.

SM-334: Implement SWA for ERR052794 (DDR Self refresh workaround) {#RN_DETAIL_SM_334}
----------

Implemented errata workaround as mentioned for ERR052794.

SM-335: Only first BBNSM RTC rollover generates a notification {#RN_DETAIL_SM_335}
----------

Prevent clearing of the BBNSM RTC rollover interrupt within its interrupt handler. This ensures the BBNSM RTC continues to generate interrupts for all subsequent rollovers.

SM-336: Incorrect index assigned for board RTC instance {#RN_DETAIL_SM_336}
----------

Updated board RTC instances to start after device RTC instances. Customers should make the same fix to their board port if they use the PCA2131 RTC.

SM-337: Disallow RTC time and alarm configuration outside of range {#RN_DETAIL_SM_337}
----------

Added validation checks to prevent invalid RTC time and alarm configurations outside the permitted range. Customers should make the same changes to their board port if they use the PCA2131 RTC.

SM-339: Support V2X fast hash for uboot and kernel containers authentication {#RN_DETAIL_SM_339}
----------

Made cfg updates to support V2X fast hash. The changes required vary by SoC.

On i.MX95:
- Give ELE ownership of EDMA2 channels 0 and 1
- Remove AP-NS access to the above DMA channels
- Give ELE access to the EDMA2 MP (shared with AP-NS)
- Give V2X read-only access to all of DDR excluding the DDR region for the V2X FW (R/W)

On i.MX94:
- Move ownership of the ATU_V2X to AP-NS (from the SM)
- Give V2X read-only access to all of DDR excluding the DDR region for the V2X FW (R/W)

If customers want to support V2X fast hash then they will need similar changes in their cfg file.
 

SM-341: SCMI misc unit test fails if no OEI init of DDR {#RN_DETAIL_SM_341}
----------

Fixed unit test issue when the DRC has not been initialized.

SM-343: Assign GPIO2 to M7 in the mx952evkrpmsg cfg {#RN_DETAIL_SM_343}
----------

Updated the mx952evkrpmsg.cfg file to assign GPIO2 to the M7.

SM-345: Manage CGCs that interfere with CPU shutdown {#RN_DETAIL_SM_345}
----------

CGC (Clock Gate Control) nodes can be assigned to agents to provide granular control of clock gating within the SoC.  Agent accesses to peripheral interfaces clocked from a CGC that is disabled can result in an unrecoverable system hang.  SM will enable CGC outputs impacting CPU shutdown operations to avoid such hazards.

SM-346: Fix DDR RX Replica sequence: re-enable PHY master before locking PHY CSRs {#RN_DETAIL_SM_346}
----------

Fix code sequence issue, where re-enabling of PHY master interface should be performed before re-locking of the PHY CSRs

SM-347: Update to latest SDK header files for i.MX952 {#RN_DETAIL_SM_347}
----------

Updated i.MX952 SDK headers to rev. 2.0.

SM-349: Allow M7 to access EDMA2_MP for i.MX95EVK-RPSMG & SOF {#RN_DETAIL_SM_349}
----------

Updated the noted cfg files. Both were missing the definition of the ACCESS macro for the M7.

SM-350: Give SEMA41 access to SM for testing on i.MX952 {#RN_DETAIL_SM_350}
----------

Update the mx952alt.cfg file to give SM access to the SEMA41 module.

SM-351: Misc. coding standards fixes {#RN_DETAIL_SM_351}
----------

Resolved several MISRA issues with the i.MX952 EVK board port.

SM-353: Add alt mode selections to start M70 or M71 {#RN_DETAIL_SM_353}
----------

mSel 4 and 5 options added to the mx95alt.cfg file to allow starting the M70 or M71 cores.

SM-354: Incorrect source input for dram_apb_clk_root {#RN_DETAIL_SM_354}
----------

Source input2 of dram_apb_clk_root was updated for i.MX95_B0 and i.MX952_A0.  SM clock root tables were updated to reflect that input2 is connected to SYS_PLL1_DFS1_CLK (800MHz) instead of SYS_PLL1_DFS1_DIV2_CLK (400MHz).

SM-355: Reassign V2X MDAC to workaround a V2X ROM authentication issue {#RN_DETAIL_SM_355}
----------

Moved one of the MU MDACS to V2X and moved a spare MDAC to the MU.

SM-359: Add optional code to bounce the BBSM supply on reset {#RN_DETAIL_SM_359}
----------

The EVK reference port includes example code to bounce the BBSM supply on a reset. To enable this, add the following define to the local defines section of  boards/mcimx952evk/sm/brd_sm_handlers.c and then recompile the SM.

#define PMIC_BOUNCE_BBSM

If customers desire this behavior, add the block of code in this file enabled by this define to the customer board port.

