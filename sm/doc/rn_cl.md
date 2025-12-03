Change List {#RN_CL}
===========

The tables below also indicate which patch version, if any, in the previous release (
imx_sm_2025q4) includes the change. Note some of these patches may not have been released yet and
the data could change.

SM 2026Q1 Change List {#RN_P0}
====================================

Below is a list of changes between the previous release (imx_sm_2025q4) and this release (imx_sm_2026q1).

New Feature {#RN_CL_NEW}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX952<br> (A0) |
|------------|-------------------------------|-------|---|---|---|
| [SM-156](https://jira.sw.nxp.com/projects/SM/issues/SM-156) | Add support for i.MX952 |   | | | Y |
| [SM-158](https://jira.sw.nxp.com/projects/SM/issues/SM-158) | Add support for the i.MX952 EVK |   | | | Y |
| [SM-321](https://jira.sw.nxp.com/projects/SM/issues/SM-321) | Add config file for the FRDM-IMX95-PRO board [[detail]](@ref RN_DETAIL_SM_321) |   | Y | | |
| [SM-328](https://jira.sw.nxp.com/projects/SM/issues/SM-328) | i.MX95 Support dynamic video mode switching |   | Y | | |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX952<br> (A0) |
|------------|-------------------------------|-------|---|---|---|
| [SM-317](https://jira.sw.nxp.com/projects/SM/issues/SM-317) | Test and coding standards improvements |   | Y | Y | Y |
| [SM-322](https://jira.sw.nxp.com/projects/SM/issues/SM-322) | Give AP NS LMM 1 API access in mx95evksof [[detail]](@ref RN_DETAIL_SM_322) |   | Y | | |
| [SM-323](https://jira.sw.nxp.com/projects/SM/issues/SM-323) | Improve ELE reset logging |   | Y | Y | Y |
| [SM-324](https://jira.sw.nxp.com/projects/SM/issues/SM-324) | Support fuse.r reading multiple fuses [[detail]](@ref RN_DETAIL_SM_324) |   | Y | Y | Y |
| [SM-332](https://jira.sw.nxp.com/projects/SM/issues/SM-332) | Sync misc. changes across SoC |   | Y | Y | Y |
| [SM-334](https://jira.sw.nxp.com/projects/SM/issues/SM-334) | Implement SWA for ERR052794 (DDR Self refresh workaround) |   | Y | Y | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX952<br> (A0) |
|------------|-------------------------------|-------|---|---|---|
| [SM-327](https://jira.sw.nxp.com/projects/SM/issues/SM-327) | Resources associated with mixes disabled in fuses should not be accessible |   | Y | Y | Y |
| [SM-330](https://jira.sw.nxp.com/projects/SM/issues/SM-330) | Configtool does not support hash comments unless at the start of a line [[detail]](@ref RN_DETAIL_SM_330) |   | Y | Y | Y |
| [SM-333](https://jira.sw.nxp.com/projects/SM/issues/SM-333) | Duplicate atomic resources used in MIMX94 XSPI_RESPONDR macro [[detail]](@ref RN_DETAIL_SM_333) |   | | Y | |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | MX95<br> (B0) | MX94<br> (A0) | MX952<br> (A0) |
|------------|-------------------------------|-------|---|---|---|
| [SM-331](https://jira.sw.nxp.com/projects/SM/issues/SM-331) | SM 2026Q1 documentation updates |   | Y | Y | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-321: Add config file for the FRDM-IMX95-PRO board {#RN_DETAIL_SM_321}
----------

Added a new cfg file for the FRDM-PRO-IMX95 board. The file is in other/mx95frdm-pro.cfg. It can be used by building the config and then compiling.

make config=mx95frdm-pro cfg
make config=mx95frdm-pro all

SM-322: Give AP NS LMM 1 API access in mx95evksof {#RN_DETAIL_SM_322}
----------

Modified the cfg file to give the AP core control over the M7 LM.

SM-324: Support fuse.r reading multiple fuses {#RN_DETAIL_SM_324}
----------

Enhanced the SM debug monitor to support the fuse.r command with an optional second argument specifying the number of sequential fuse words to read and display. If the second argument is not passed, the default is 1.
 * When reading a single word (default or one argument) and an error occurs, the error is displayed.
 * When reading multiple words, any unreadable fuse words are skipped without stopping the loop.
 * Added bounds checking to ensure the requested range does not exceed the maximum number of fuses.
 * Verified that reading from 0 to max does not trigger the watchdog; if it does, the loop will service the watchdog as needed.
 * Updated monitor.md documentation to reflect the new command behavior and usage.

SM-330: Configtool does not support hash comments unless at the start of a line {#RN_DETAIL_SM_330}
----------

Add code to the configtool to remove trailing comments from a line. Existing code only removed comment lines (complete lines started with a hash).

Also fixed issue when cfg files had CR/LF line endings.

SM-333: Duplicate atomic resources used in MIMX94 XSPI_RESPONDR macro {#RN_DETAIL_SM_333}
----------

Removed the duplicate DAISY entries. Results in no changes to the generated header files. This change is to satisfy error checking in the FuSa config tool.

