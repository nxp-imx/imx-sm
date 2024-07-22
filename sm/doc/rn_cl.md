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
| [SM-107](https://jira.sw.nxp.com/projects/SM/issues/SM-107) | Support dynamic rate adjust of audio and  video PLLs |   | Y | Y |
| [SM-123](https://jira.sw.nxp.com/projects/SM/issues/SM-123) | Add minimal support for the PCA2131 RTC [[detail]](@ref RN_DETAIL_SM_123) |   | Y | Y |
| [SM-130](https://jira.sw.nxp.com/projects/SM/issues/SM-130) | Support BBM button/alarm booting LMs [[detail]](@ref RN_DETAIL_SM_130) |   | Y | Y |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-19](https://jira.sw.nxp.com/projects/SM/issues/SM-19) | Optimize boot time [[detail]](@ref RN_DETAIL_SM_19) |   | Y | Y |
| [SM-87](https://jira.sw.nxp.com/projects/SM/issues/SM-87) | Improve unit test coverage |   | Y | Y |
| [SM-111](https://jira.sw.nxp.com/projects/SM/issues/SM-111) | Enable QoS to be driven from CAMERAMIX block control [[detail]](@ref RN_DETAIL_SM_111) |   | Y | Y |
| [SM-115](https://jira.sw.nxp.com/projects/SM/issues/SM-115) | Code clean-up and coding standard improvements |   | Y | Y |
| [SM-117](https://jira.sw.nxp.com/projects/SM/issues/SM-117) | Update subvendor to "IMX" to be generic, move board name [[detail]](@ref RN_DETAIL_SM_117) |   | Y | Y |
| [SM-118](https://jira.sw.nxp.com/projects/SM/issues/SM-118) | Enhance LM start/stop script options [[detail]](@ref RN_DETAIL_SM_118) |   | Y | Y |
| [SM-121](https://jira.sw.nxp.com/projects/SM/issues/SM-121) | Update eMcem component [[detail]](@ref RN_DETAIL_SM_121) |   | Y | Y |
| [SM-122](https://jira.sw.nxp.com/projects/SM/issues/SM-122) | Support newer version of SRC/CCM |   | Y | Y |
| [SM-134](https://jira.sw.nxp.com/projects/SM/issues/SM-134) | Misc. updates to SM configurations |   | Y | Y |
| [SM-136](https://jira.sw.nxp.com/projects/SM/issues/SM-136) | Misc. FuSa enhancements [[detail]](@ref RN_DETAIL_SM_136) |   | Y | Y |
| [SM-137](https://jira.sw.nxp.com/projects/SM/issues/SM-137) | Support system sleep modes |   | Y | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-124](https://jira.sw.nxp.com/projects/SM/issues/SM-124) | FRO not enabled after resume from system suspend [[detail]](@ref RN_DETAIL_SM_124) |   | Y | Y |
| [SM-125](https://jira.sw.nxp.com/projects/SM/issues/SM-125) | PF53 are reset by a transition to system suspend |   | Y | Y |
| [SM-126](https://jira.sw.nxp.com/projects/SM/issues/SM-126) | SM debug monitor exit does not return to idle [[detail]](@ref RN_DETAIL_SM_126) |   | Y | Y |
| [SM-129](https://jira.sw.nxp.com/projects/SM/issues/SM-129) | Preconditions required when switching SRC between SW and HW control |   | Y | Y |
| [SM-131](https://jira.sw.nxp.com/projects/SM/issues/SM-131) | Shutdown of suspended LM may result in SM WDOG |   | Y | Y |
| [SM-132](https://jira.sw.nxp.com/projects/SM/issues/SM-132) | SM error handling can fail if LMM not initialized [[detail]](@ref RN_DETAIL_SM_132) |   | Y | Y |

Silicon Workaround {#RN_CL_REQ}
------------

These are a mix of silicon errata workarounds and recommended usage changes.

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-110](https://jira.sw.nxp.com/projects/SM/issues/SM-110) | SM may WDOG reset during non-cooperative reset of A55 |   | Y | Y |
| [SM-127](https://jira.sw.nxp.com/projects/SM/issues/SM-127) | Manage GPC wake configuration when updating CPU run mode |   | Y | Y |

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

SM-111: Enable QoS to be driven from CAMERAMIX block control {#RN_DETAIL_SM_111}
----------

Added QoS enable so that each regulator passes the value upstream.

SM-117: Update subvendor to "IMX" to be generic, move board name {#RN_DETAIL_SM_117}
----------

The BASE_DISCOVER_SUB_VENDOR message now always returns "IMX". This allows Linux to use a common SCMI vendor-extension across all i.MX/boards.

This used to return a board-specific value. That value can now be returned using a new SCMI misc protocol MISC_BOARD_INFO message.

Note this required SCMI_SUB_VENDOR be changed to BRD_SM_NAME in brd_sm.h. Customers will have to make the same change.

SM-118: Enhance LM start/stop script options {#RN_DETAIL_SM_118}
----------

The LM start/stop scripts now support RST and CTRL types. The RST type can be used to assert/negate/toggle a reset domain on start/stop. The CTRL type can be used to set a control to a value on start/stop. These could be device or board resources.

SM-121: Update eMcem component {#RN_DETAIL_SM_121}
----------

Integrated new release of the eMcem component. No functional changes.

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

SM-126: SM debug monitor exit does not return to idle {#RN_DETAIL_SM_126}
----------

This makes two changes:

- For the M=1 compile option, the monitor 'exit' command will now leave the monitor and enter a permanent SM idle state. There is no way to return to the monitor once exited. Before it incorrectly entered a non-idle busy loop.
- A new M=2 compile option has been added. In this mode, the SM will by default be in an idle state and SM UART activity is required to run the debug monitor. The 'exit' command will leave the monitor and return to the idle loop awaiting input.

As before, the debug monitor must be disabled with M=0 for production builds. The SM cannot be guaranteed to operate with the debug monitor enabled. M=0 is also required for MISRA compliance. 

SM-130: Support BBM button/alarm booting LMs {#RN_DETAIL_SM_130}
----------

Added new config option to allow an LM to be designated to boot on the BBNSM ON/OFF button press or RTC alarm. This assumes the LM has the associated alarm and/or notification(s) enabled before it shuts down. The new config option is auto=option on the LM line and the options are none (default), button, rtc, or both.

Changed the android cfg file to enable boot on BBNSM button for the AP LM.

SM-132: SM error handling can fail if LMM not initialized {#RN_DETAIL_SM_132}
----------

If ASSERT/ENSURE errors occur before the LMM is initialized then failures can occur when the reset tries to send notifications to agents. This change makes ASSERT/ENSURE errors directly call reset (no notifications) prior to LMM initialization.

SM-136: Misc. FuSa enhancements {#RN_DETAIL_SM_136}
----------

Fixed issue with cached PF09/PF53 version info. Only one version cached but there can be multiple PMICs of the same type.

Passed array length info for the PMIC driver IRQ functions.

