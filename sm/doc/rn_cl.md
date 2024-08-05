Change List {#RN_CL}
===========

The tables below also indicate which patch version, if any, in the previous release (
imx_sm_2024q2) includes the change. Note some of these patches may not have been released yet and
the data could change.

SM 2024Q3 Change List {#RN_P0}
====================================

Below is a list of changes between the previous release (imx_sm_2024q2) and this release (imx_sm_2024q3).

New Feature {#RN_CL_NEW}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-123](https://jira.sw.nxp.com/projects/SM/issues/SM-123) | Add minimal support for the PCA2131 RTC [[detail]](@ref RN_DETAIL_SM_123) |   | Y | Y |
| [SM-130](https://jira.sw.nxp.com/projects/SM/issues/SM-130) | Support BBM button/alarm booting LMs [[detail]](@ref RN_DETAIL_SM_130) |   | Y | Y |
| [SM-137](https://jira.sw.nxp.com/projects/SM/issues/SM-137) | Support system sleep modes [[detail]](@ref RN_DETAIL_SM_137) |   | Y | Y |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-19](https://jira.sw.nxp.com/projects/SM/issues/SM-19) | Optimize boot time [[detail]](@ref RN_DETAIL_SM_19) |   | Y | Y |
| [SM-87](https://jira.sw.nxp.com/projects/SM/issues/SM-87) | Improve unit test coverage [[detail]](@ref RN_DETAIL_SM_87) |   | Y | Y |
| [SM-111](https://jira.sw.nxp.com/projects/SM/issues/SM-111) | Enable QoS to be driven from CAMERAMIX block control [[detail]](@ref RN_DETAIL_SM_111) |   | Y | Y |
| [SM-117](https://jira.sw.nxp.com/projects/SM/issues/SM-117) | Update subvendor to "IMX" to be generic, move board name [[detail]](@ref RN_DETAIL_SM_117) |   | Y | Y |
| [SM-118](https://jira.sw.nxp.com/projects/SM/issues/SM-118) | Enhance LM start/stop script options [[detail]](@ref RN_DETAIL_SM_118) |   | Y | Y |
| [SM-121](https://jira.sw.nxp.com/projects/SM/issues/SM-121) | Update eMcem component [[detail]](@ref RN_DETAIL_SM_121) |   | Y | Y |
| [SM-122](https://jira.sw.nxp.com/projects/SM/issues/SM-122) | Support newer version of SRC/CCM [[detail]](@ref RN_DETAIL_SM_122) |   | Y | Y |
| [SM-134](https://jira.sw.nxp.com/projects/SM/issues/SM-134) | Misc. updates to SM configurations [[detail]](@ref RN_DETAIL_SM_134) |   | Y | Y |
| [SM-136](https://jira.sw.nxp.com/projects/SM/issues/SM-136) | Misc. FuSa enhancements [[detail]](@ref RN_DETAIL_SM_136) |   | Y | Y |
| [SM-140](https://jira.sw.nxp.com/projects/SM/issues/SM-140) | Save/restore the DDRMIX block control during retention [[detail]](@ref RN_DETAIL_SM_140) |   | Y | Y |
| [SM-142](https://jira.sw.nxp.com/projects/SM/issues/SM-142) | Support parent relationship of PLL clock nodes [[detail]](@ref RN_DETAIL_SM_142) |   | Y | Y |
| [SM-144](https://jira.sw.nxp.com/projects/SM/issues/SM-144) | Support a larger ELE info response |   | Y | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-115](https://jira.sw.nxp.com/projects/SM/issues/SM-115) | FRO frequency is not correct in case of open-loop [[detail]](@ref RN_DETAIL_SM_115) |   | Y | Y |
| [SM-124](https://jira.sw.nxp.com/projects/SM/issues/SM-124) | FRO not enabled after resume from system suspend [[detail]](@ref RN_DETAIL_SM_124) |   | Y | Y |
| [SM-126](https://jira.sw.nxp.com/projects/SM/issues/SM-126) | SM debug monitor exit does not return to idle [[detail]](@ref RN_DETAIL_SM_126) |   | Y | Y |
| [SM-129](https://jira.sw.nxp.com/projects/SM/issues/SM-129) | Preconditions required when switching SRC between SW and HW control [[detail]](@ref RN_DETAIL_SM_129) |   | Y | Y |
| [SM-132](https://jira.sw.nxp.com/projects/SM/issues/SM-132) | SM error handling can fail if LMM not initialized [[detail]](@ref RN_DETAIL_SM_132) |   | Y | Y |

Silicon Workaround {#RN_CL_REQ}
------------

These are a mix of silicon errata workarounds and recommended usage changes.

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-110](https://jira.sw.nxp.com/projects/SM/issues/SM-110) | SM may WDOG reset during non-cooperative reset of A55 [[detail]](@ref RN_DETAIL_SM_110) |   | Y | Y |
| [SM-125](https://jira.sw.nxp.com/projects/SM/issues/SM-125) | PF53 are reset by a transition to system suspend [[detail]](@ref RN_DETAIL_SM_125) |   | Y | Y |
| [SM-127](https://jira.sw.nxp.com/projects/SM/issues/SM-127) | Manage GPC wake configuration when updating CPU run mode [[detail]](@ref RN_DETAIL_SM_127) |   | Y | Y |
| [SM-139](https://jira.sw.nxp.com/projects/SM/issues/SM-139) | Disable LFAST CREF_EN at boot [[detail]](@ref RN_DETAIL_SM_139) |   | Y | Y |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-106](https://jira.sw.nxp.com/projects/SM/issues/SM-106) | Add dox to MX9 and MX95 device driver headers |   | Y | Y |
| [SM-120](https://jira.sw.nxp.com/projects/SM/issues/SM-120) | SM 2024Q3 documentation updates |   | Y | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-19: Optimize boot time {#RN_DETAIL_SM_19}
----------

Significant boot time comes from accessing the BBNSM as accesses are synced to 32K. Moved clearing of any boot condition flags to later in the boot after other cores are started. If those cores request this info then it will be read and cleared then (or later automatically after starting all of them).

SM-87: Improve unit test coverage {#RN_DETAIL_SM_87}
----------

Improved the statement coverage and branch coverage by:

- Adding new tests and test cases
- Made simulation configuration changes
- Increasing monitor test coverage
- Add a new test mode to allow forcing error conditions

For the simulation build, coverage increased to 90+%.

SM-110: SM may WDOG reset during non-cooperative reset of A55 {#RN_DETAIL_SM_110}
----------

During a non-cooperative reset of the A55, outstanding transactions between the Cortex-A55 domain and the system may not complete during SM attempts to reset the Cortex-A55.  The SM has been updated to implement a timeout mechanism that utilizes LPCG1 to abort the SSI Q-channel handshake between CORTEXMIX and NOCMIX in cases where outstanding transactions cannot be retired.

SM-111: Enable QoS to be driven from CAMERAMIX block control {#RN_DETAIL_SM_111}
----------

Added QoS enable so that each regulator passes the value upstream. This required ownership of CLK_CAMISI be moved to the SM.

SM-115: FRO frequency is not correct in case of open-loop {#RN_DETAIL_SM_115}
----------

The FRO was not generating the desired frequency as per the trim value configured in the fuse (ANA_CFG4), when configured in open-loop configuration. After analysis it was found that a hardcoded trim temperature value is getting programmed into the FRO trim register. But In order to generate desired the frequency, the trim temperature values should be read from fuses (ANA_CFG4) and written to the FRO trim register.

Note this change requires the full trim fuse value be passed to FRO_SetTrim(). This is called in board code and customers **must make a change in their board code to pass the full 32-bit trim**.

Hence added support to read the fuses and write the trim temperature value to the FRO. Additionally, improved the coding standard i.e. removal of the hardcoding values and replace them with macros, consistent with the comments and getting the reference clock value from the clock header files. 

SM-117: Update subvendor to "IMX" to be generic, move board name {#RN_DETAIL_SM_117}
----------

The BASE_DISCOVER_SUB_VENDOR message now always returns "IMX". This allows Linux to use a common SCMI vendor-extension across all i.MX/boards.

This used to return a board-specific value. That value can now be returned using a new SCMI misc protocol MISC_BOARD_INFO message and SCMI_MiscBoardInfo() function.

Note this required SCMI_SUB_VENDOR be changed to BRD_SM_NAME in brd_sm.h. Customers will have to make the same change.

SM-118: Enhance LM start/stop script options {#RN_DETAIL_SM_118}
----------

The LM start/stop scripts now support RST and CTRL types. The RST type can be used to assert/negate/toggle a reset domain on start/stop. The CTRL type can be used to set a control to a value on start/stop. These could be device or board resources.

SM-121: Update eMcem component {#RN_DETAIL_SM_121}
----------

Integrated new release of the eMcem component. No functional changes.

SM-122: Support newer version of SRC/CCM {#RN_DETAIL_SM_122}
----------

Support SRC/GPC as found in some other i.MX9 SoC. This includes API changes for LPCG.

SM-123: Add minimal support for the PCA2131 RTC {#RN_DETAIL_SM_123}
----------

Added a PCA2313 component driver. Minimal support to read/write clock and use alarm. Added support to the i.M95 EVK 15x15 board port to expose this RTC as an additional BBM RTC. Read/write clock in seconds, set alarm, etc. Many features of the PCA2131 that do not have an SM API are not supported. In addition:
- Assigned the PCA_2131 to the M7 LM
- Added an SCMI_BbmRtcState() function to allow reading the state of an RTC (if available), state include battery low, and if the clock was reset
- Renamed DEV_SM_RTC_BBM to DEV_SM_RTC_BBNSM, requires config be regenerated
- Updated monitor to support multiple RTC
- Added extended control support (set get with address/len)
- Used extended support to add an EVK  board control for the PFA2131 to allow raw multi-byte I2C read/write.


SM-124: FRO not enabled after resume from system suspend {#RN_DETAIL_SM_124}
----------

SM was updated to ensure FRO is enabled after resume from system suspend.

SM-125: PF53 are reset by a transition to system suspend {#RN_DETAIL_SM_125}
----------

The standby signal for the PF53s is not connected on the EVK boards. Instead, GPIOs from the PF09 are connected to the power signal of each PF53. These GPIO are configured in the PF09 OTP to de-assert when the PF09 enters standby. This results in them powering down when the system enters standby but when it exits standby the PF53s reset and reload their OTP settings (inc. voltage and output enabled).

To solve the output enable problem of the PF53 driving VDD_ARM, when the SM wants to disable VDD_ARM it has been changed to de-assert the GPIO in RUN mode. This makes it power down and the state is retained across a standby.

To solve the voltage reset of both PF53s, their voltage setting is cached and reloaded on a suspend exit. To minimize setting this, the SM needs to know the OTP voltage of the PMICs.  See the BOARD_VOLT_SOC and BOARD_VOLT_ARM defines in board.h.

Note this fix requires the OTP value of the PF53 driving VDD_SOC be sufficiently high to guarantee the SM can run on standby exit. This usually means it **must be at the max the SoC will use**. 

All these changes are only in board port code and customers may require similar changes depending on number of PF53 and how they are connected.

SM-126: SM debug monitor exit does not return to idle {#RN_DETAIL_SM_126}
----------

This makes two changes:

- For the M=1 compile option, the monitor 'exit' command will now leave the monitor and enter a permanent SM idle state. There is no way to return to the monitor once exited. Before it incorrectly entered a non-idle busy loop.
- A new M=2 compile option has been added. In this mode, the SM will by default be in an idle state and SM UART activity is required to run the debug monitor. The 'exit' command will leave the monitor and return to the idle loop awaiting input.

As before, the debug monitor must be disabled with M=0 for production builds. The SM cannot be guaranteed to operate with the debug monitor enabled. M=0 is also required for MISRA compliance. 

SM-127: Manage GPC wake configuration when updating CPU run mode {#RN_DETAIL_SM_127}
----------

During CPU shut down operations, wake sources must be masked at the GPC CMC level to ensure the respective CPU does not prevent the system from sleeping.  Conversely, these GPC CMC-level wake sources should be unmasked to match the GPC CMC hardware reset condition when starting the CPU.

SM-129: Preconditions required when switching SRC between SW and HW control {#RN_DETAIL_SM_129}
----------

In some reset/recovery scenarios, SM violated SRC hardware preconditions when switching a MIX between SW-control and HW-control (AUTHEN_CTRL[LPM_MODE]).  The associated reset/recovery flows were updated to meet these preconditions.

SM-130: Support BBM button/alarm booting LMs {#RN_DETAIL_SM_130}
----------

Added new config option to allow an LM to be designated to boot on the BBNSM ON/OFF button press or RTC alarm. This assumes the LM has the associated alarm and/or notification(s) enabled before it shuts down. The new config option is auto=option on the LM line and the options are none (default), button, rtc, or both.

Changed the android cfg file to enable boot on BBNSM button for the AP LM.

SM-132: SM error handling can fail if LMM not initialized {#RN_DETAIL_SM_132}
----------

If ASSERT/ENSURE errors occur before the LMM is initialized then failures can occur when the reset tries to send notifications to agents. This change makes ASSERT/ENSURE errors directly call reset (no notifications) prior to LMM initialization.

SM-134: Misc. updates to SM configurations {#RN_DETAIL_SM_134}
----------

Made the following cfg file (or included SoC cfg file) changes:

- Remove V2XPK association with V2X (leaves owned by SM)
- Change second CMU_W1 reference to CMU_W2

SM-136: Misc. FuSa enhancements {#RN_DETAIL_SM_136}
----------

Fixed issue with cached PF09/PF53 version info. Only one version cached but there can be multiple PMICs of the same type.

Passed array length info for the PMIC driver IRQ functions. This required an additional parameter in PF09_IntEnable(), PF09_IntStatus(), and PF09_IntClear(). As called from board code, **customers will have to changed their board port**.

SM-137: Support system sleep modes {#RN_DETAIL_SM_137}
----------

During system sleep entry, SM will now inspect the vendor-defined flags passed to SCMI_SystemPowerStateSet() to configure the system sleep mode.  These sleep modes allow the system to remain active at the specified performance level to support low-power data flows and use cases.

This change not only changes what is passed for a sleep mode and flags in SCMI_SystemPowerStateSet(), but it also adds both parameters to the board system sleep functions (e.g. BOARD_SystemSleepPrepare()). **Customers must change these functions in their board port.**

SM-139: Disable LFAST CREF_EN at boot {#RN_DETAIL_SM_139}
----------

Per ERR052319, the current reference for LFAST I/O is enabled out of reset.  This reference is only needed during PCIe operation and consumes power on the VDD_ANA_1V8 supply.  SM has been updated to disable the LFAST I/O current reference during the early stages of SM boot.  The agent owing PCIe is expected to manage this current reference after the initial SM boot.

SM-140: Save/restore the DDRMIX block control during retention {#RN_DETAIL_SM_140}
----------

Added code to save and restore the DDRMIX BLK_CTRL registers when the DDRMIX power state changes and the state is lost. This includes the state of the auto clock gating which was not retained and would result in higher power after a system suspend.

SM-142: Support parent relationship of PLL clock nodes {#RN_DETAIL_SM_142}
----------

SCMI agents can use the clock management protocol for clock tree discovery.  The clock nodes of PLLs (VCO, CLKO, DFS/PFD) are exposed using individual clock domain IDs.  SM has been updated to add the parent-child relationships between these PLL clock nodes to allow discovery of such relationships.

