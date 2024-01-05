Change List {#RN_CL}
===========

The tables below also indicate which patch version, if any, in the previous release (
imx_sm_2023q4_er2) includes the change. Note some of these patches may not have been released yet and
the data could change.

SM 2024Q1 Change List {#RN_P0}
====================================

Below is a list of changes between the previous release (imx_sm_2023q4_er2) and this release (imx_sm_2024q1).

New Feature {#RN_CL_NEW}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-10](https://jira.sw.nxp.com/projects/SM/issues/SM-10) | Add eMCEM driver to support FCCU |   | Y | Y |
| [SM-27](https://jira.sw.nxp.com/projects/SM/issues/SM-27) | Add low-power mode entry during SM idle |   | Y | Y |
| [SM-28](https://jira.sw.nxp.com/projects/SM/issues/SM-28) | Add support for DRAM retention |   | Y | Y |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-14](https://jira.sw.nxp.com/projects/SM/issues/SM-14) | Include ELE status in reset record [[detail]](@ref RN_DETAIL_SM_14) |   | Y | Y |
| [SM-59](https://jira.sw.nxp.com/projects/SM/issues/SM-59) | Support latest SCMI 3.2 BETA3 spec changes [[detail]](@ref RN_DETAIL_SM_59) |   | Y | Y |
| [SM-61](https://jira.sw.nxp.com/projects/SM/issues/SM-61) | Save/restore PLL registers impacted during MIX power gating |   | Y | Y |
| [SM-62](https://jira.sw.nxp.com/projects/SM/issues/SM-62) | Fix various issues with SM configurations |   | Y | Y |
| [SM-64](https://jira.sw.nxp.com/projects/SM/issues/SM-64) | Disable PF09 PWRUP interrupt [[detail]](@ref RN_DETAIL_SM_64) |   | Y | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-63](https://jira.sw.nxp.com/projects/SM/issues/SM-63) | Fix polarity of WDOG ANY mask [[detail]](@ref RN_DETAIL_SM_63) |   | Y | Y |

Silicon Workaround {#RN_CL_REQ}
------------

These are a mix of silicon errata workarounds and recommended usage changes.

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-54](https://jira.sw.nxp.com/projects/SM/issues/SM-54) | Add software workaround for ERR052127 (NOCMIX BLK_CTRL sync) |   | Y | Y |
| [SM-58](https://jira.sw.nxp.com/projects/SM/issues/SM-58) | Add software workaround for ERR052128 (TMPSNS wait time) |   | Y | Y |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-57](https://jira.sw.nxp.com/projects/SM/issues/SM-57) | SM 2024Q1 documentation updates |   | Y | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-14: Include ELE status in reset record {#RN_DETAIL_SM_14}
----------

Updated the extended reset data for the ELE group 1-3 (interrupt 160-162) to capture the ELE reset and interrupt register status.

    Reset request: reason=cm33_exc, errId=160
      0x1FFC4A58
      0x00200020 <- ELE_RST_REQ_STAT
      0x00000020 <- ELE_IRQ_REQ_STAT

SM-59: Support latest SCMI 3.2 BETA3 spec changes {#RN_DETAIL_SM_59}
----------

Updated to the BETA3 version of the SCMI 3.2 spec. Added NEGOTIATE_PROTOCOL_VERSION messages for all protocols. Will return NOT_SUPPORTED if the requested version is not the same major version and less than or equal to the supported minor version.

SM-63: Fix polarity of WDOG ANY mask {#RN_DETAIL_SM_63}
----------

Update the board BOARD_WdogModeSet() function to correctly manage the WDOG_ANY mask bits. A new BOARD_WDOG_ANY_INIT define indicates which watchdog(s) should not drive the WDOG ANY signal to the PMIC to do a cold reboot (all except the one(s) used by the SM). The BOARD_WDOG_ANY_MASK define indicates which watchdog(s) should have this dynamically changed when reconfiguring for a cold/warm watchdog reset (used from the debug monitor wdog command).

Customers should make the same change. Without this change the SM watchdog will incorrectly do a warm reset and all the other watchdogs will always do a full system cold reset (not an LM reset).

SM-64: Disable PF09 PWRUP interrupt {#RN_DETAIL_SM_64}
----------

Added code in the board BRD_SM_SerialDevicesInit() function to disable the PF09 PWRUP interrupt. Customers should do the same if not using this interrupt for some additional PMIC management.

