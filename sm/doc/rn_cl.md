Change List {#RN_CL}
===========

The tables below also indicate which patch version, if any, in the previous release (
imx_sm_2026q2) includes the change. Note some of these patches may not have been released yet and
the data could change.

SM 2026Q3 Change List {#RN_P0}
====================================

Below is a list of changes between the previous release (imx_sm_2026q2) and this release (imx_sm_2026q3).

New Feature {#RN_CL_NEW}
------------

| Key     | Summary                        | Patch | MX937<br> (A1) | MX94<br> (A1) | MX95<br> (B0) | MX95<br> (B1) | MX952<br> (A1) |
|------------|-------------------------------|-------|---|---|---|---|---|
| [SM-372](https://jira.sw.nxp.com/projects/SM/issues/SM-372) | Remove support for i.MX94 A0 [[detail]](@ref RN_DETAIL_SM_372) |   | | | | | |
| [SM-379](https://jira.sw.nxp.com/projects/SM/issues/SM-379) | Add support for i.MX937 [[detail]](@ref RN_DETAIL_SM_379) |   | Y | | | | |
| [SM-380](https://jira.sw.nxp.com/projects/SM/issues/SM-380) | Add support for the i.MX937 freedom board [[detail]](@ref RN_DETAIL_SM_380) |   | Y | | | | |
| [SM-416](https://jira.sw.nxp.com/projects/SM/issues/SM-416) | Add perf.r possible command [[detail]](@ref RN_DETAIL_SM_416) |   | Y | Y | Y | Y | Y |
| [SM-440](https://jira.sw.nxp.com/projects/SM/issues/SM-440) | Add support for the i.MX95 freedom board LP5 15x15 [[detail]](@ref RN_DETAIL_SM_440) |   | | | Y | Y | |
| [SM-443](https://jira.sw.nxp.com/projects/SM/issues/SM-443) | Add i.MX937 jailhouse and rpmsg configuration files [[detail]](@ref RN_DETAIL_SM_443) |   | Y | | | | |
| [SM-444](https://jira.sw.nxp.com/projects/SM/issues/SM-444) | Add Android support for i.MX95 15x15 freedom LPDDR5 board [[detail]](@ref RN_DETAIL_SM_444) |   | | | Y | Y | |
| [SM-445](https://jira.sw.nxp.com/projects/SM/issues/SM-445) | Add rpmsg support for FRDM-IMX952 [[detail]](@ref RN_DETAIL_SM_445) |   | | | | | Y |
| [SM-447](https://jira.sw.nxp.com/projects/SM/issues/SM-447) | Add i.MX95 LPDDR5 FRDM jailhouse and rpmsg configuration files [[detail]](@ref RN_DETAIL_SM_447) |   | | | Y | Y | |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | MX937<br> (A1) | MX94<br> (A1) | MX95<br> (B0) | MX95<br> (B1) | MX952<br> (A1) |
|------------|-------------------------------|-------|---|---|---|---|---|
| [SM-399](https://jira.sw.nxp.com/projects/SM/issues/SM-399) | Test and coding standards improvements [[detail]](@ref RN_DETAIL_SM_399) |   | Y | Y | Y | Y | Y |
| [SM-422](https://jira.sw.nxp.com/projects/SM/issues/SM-422) | Change agent seenvId numbering from one-based to zero-based [[detail]](@ref RN_DETAIL_SM_422) |   | Y | Y | Y | Y | Y |
| [SM-425](https://jira.sw.nxp.com/projects/SM/issues/SM-425) | Remove redundant MX95 power domain dependency tracking [[detail]](@ref RN_DETAIL_SM_425) |   | | | Y | Y | |
| [SM-431](https://jira.sw.nxp.com/projects/SM/issues/SM-431) | Move display CM0+ resources to the secure domain for Android [[detail]](@ref RN_DETAIL_SM_431) |   | | | | | Y |
| [SM-435](https://jira.sw.nxp.com/projects/SM/issues/SM-435) | Sync common changes across devices [[detail]](@ref RN_DETAIL_SM_435) |   | Y | Y | Y | Y | Y |
| [SM-437](https://jira.sw.nxp.com/projects/SM/issues/SM-437) | Add MISC protocol API to get control attributes [[detail]](@ref RN_DETAIL_SM_437) |   | Y | Y | Y | Y | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | MX937<br> (A1) | MX94<br> (A1) | MX95<br> (B0) | MX95<br> (B1) | MX952<br> (A1) |
|------------|-------------------------------|-------|---|---|---|---|---|
| [SM-420](https://jira.sw.nxp.com/projects/SM/issues/SM-420) | Configtool ends with success (0) even on error [[detail]](@ref RN_DETAIL_SM_420) |   | Y | Y | Y | Y | Y |
| [SM-429](https://jira.sw.nxp.com/projects/SM/issues/SM-429) | Restrict access to resources which are disabled in fuses [[detail]](@ref RN_DETAIL_SM_429) |   | Y | Y | Y | Y | Y |
| [SM-430](https://jira.sw.nxp.com/projects/SM/issues/SM-430) | i.MX943 EVK I2C2 pinmuxing is impossible [[detail]](@ref RN_DETAIL_SM_430) |   | | Y | | | |
| [SM-432](https://jira.sw.nxp.com/projects/SM/issues/SM-432) | Minor errors in alt and emul config files [[detail]](@ref RN_DETAIL_SM_432) |   | | Y | | | |
| [SM-451](https://jira.sw.nxp.com/projects/SM/issues/SM-451) | PF09 temp sensor enable broken on the i.MX95 FRDM LPDDR5 board [[detail]](@ref RN_DETAIL_SM_451) |   | | | Y | Y | |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | MX937<br> (A1) | MX94<br> (A1) | MX95<br> (B0) | MX95<br> (B1) | MX952<br> (A1) |
|------------|-------------------------------|-------|---|---|---|---|---|
| [SM-407](https://jira.sw.nxp.com/projects/SM/issues/SM-407) | Remove support for i.MX952 A0 [[detail]](@ref RN_DETAIL_SM_407) |   | | | | | |
| [SM-421](https://jira.sw.nxp.com/projects/SM/issues/SM-421) | SM 2026Q3 documentation updates |   | Y | Y | Y | Y | Y |
| [SM-439](https://jira.sw.nxp.com/projects/SM/issues/SM-439) | SCMI_FusaFaultSet() documentation has incorrect flag use [[detail]](@ref RN_DETAIL_SM_439) |   | Y | Y | Y | Y | Y |
| [SM-442](https://jira.sw.nxp.com/projects/SM/issues/SM-442) | mx94alt mSel description incomplete in docs [[detail]](@ref RN_DETAIL_SM_442) |   | | Y | | | |
| [SM-446](https://jira.sw.nxp.com/projects/SM/issues/SM-446) | Add support for i.MX95 B1 [[detail]](@ref RN_DETAIL_SM_446) |   | | | | Y | |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-372: Remove support for i.MX94 A0 {#RN_DETAIL_SM_372}
----------

Removed support for i.MX94 A0. This included removing the dynamic glitch filter code. All changes are in the board port so in theory a customer and make A0 work, but note this release and all future releases will not be tested on A0.

SM-379: Add support for i.MX937 {#RN_DETAIL_SM_379}
----------

Added device support for [i.MX937 family devices](@ref DEV_SM_MX937) inc. i.MX9375. See the devices/MIMX937 directory.

SM configuration files targeted at this device should include the following:

MAKE soc=MIMX937, board=<board name>, build=gcc_cross

include ../devices/MIMX937/configtool/device.cfg

Note the list of resources, memory areas, etc. are different from i.MX95. See the configs/mx937frdm.cfg file for reference.

SM-380: Add support for the i.MX937 freedom board {#RN_DETAIL_SM_380}
----------

Added board support for the [i.MX937 FRDM](@ref BRD_SM_MX937FRDM). See the boards/mcimx937frdm directory. Compile with the following:

make config=mx937frdm

Information about this port can be found in the [NXP i.MX937 FRDM](@ref PORT_MX937_FRDM) section of the RM.

SM configuration files targeted at this board should include the following:

MAKE soc=MIMX937, board=mcimx937frdm, build=gcc_cross

SM-399: Test and coding standards improvements {#RN_DETAIL_SM_399}
----------

Removed the SIMU macro dependency and updated the test and simulation code to run all tests across all boards and SIMU. No customer impact.

Reminder that non-production builds (the default) contain test code including function wrappers. These *MUST* be disabled for production builds using the M=0 compile option.

SM-407: Remove support for i.MX952 A0 {#RN_DETAIL_SM_407}
----------

Removed support for i.MX952 A0. This is just a doc change. Also note i.MX952 A0 is no longer tested as part of the SM release.

SM-416: Add perf.r possible command {#RN_DETAIL_SM_416}
----------

Added the perf.r [domainId] possible command to display all available performance levels and corresponding max frequencies for a given domain (defaults to all domains if not specified).

SM-420: Configtool ends with success (0) even on error {#RN_DETAIL_SM_420}
----------

Modified configtool script to return 1 on all exits due to an error.

SM-422: Change agent seenvId numbering from one-based to zero-based {#RN_DETAIL_SM_422}
----------

Modified configtool to create 0-based ssenvId values. Updated the configtool version to 3. Modified the FuSa protocol RPC functions to use the cfg value and not subtract one. Customers need to regenerate headers after this change. 

SM-425: Remove redundant MX95 power domain dependency tracking {#RN_DETAIL_SM_425}
----------

The SM device-layer support for MX95 SCMI CPU protocol previously included software logic for power domain dependency tracking of DDRMIX, NOCMIX, and WAKEUPMIX.  This logic is now redundant and has been removed to align with other members of the MX9 family. No customer impact.

SM-429: Restrict access to resources which are disabled in fuses {#RN_DETAIL_SM_429}
----------

Resources disabled in fuses are kept reserved. Clock/perf/power/reset dumps from SM will only list resources that are not disabled by fuses.

SM-430: i.MX943 EVK I2C2 pinmuxing is impossible {#RN_DETAIL_SM_430}
----------

Moved conflicting pinmux setting code under correct ifdef. 

SM-431: Move display CM0+ resources to the secure domain for Android {#RN_DETAIL_SM_431}
----------

Moved ownership of the M0+ core in the display mix to the AP-S (aka secure) agent.

SM-432: Minor errors in alt and emul config files {#RN_DETAIL_SM_432}
----------

Fixed an i.MX94 ALT config issue with an M7 start step using an already used step. Removed some unused resource names. No customer impact unless error copied into the customer's board port, in which case a similar fix is required.

SM-435: Sync common changes across devices {#RN_DETAIL_SM_435}
----------

Remove the code and update the header files to incorporate the FRO coarsen bit and GPC_EFUSE_CTRL changes in the GPC global configuration across all platforms, in alignment with the updated CRR headers received from the SDK team. Also fixed various coding standards issues. No customer impact.

SM-437: Add MISC protocol API to get control attributes {#RN_DETAIL_SM_437}
----------

Added a new SCMI MISC protocol message, ::SCMI_MSG_MISC_CONTROL_ATTRIBUTES. This message can be called with the client SCMI_MiscControlAttributes() function. It is used to get the attributes of a control. Attributes indicate which MISC message/functions are valid for that control: NOTIFY, SET, GET, EXT_SET, EXT_GET, ACTION.

SM-439: SCMI_FusaFaultSet() documentation has incorrect flag use {#RN_DETAIL_SM_439}
----------

Update dox for SCMI_FusaFaultSet() to swap 0 and 1 for the set/clear flag options.

SM-440: Add support for the i.MX95 freedom board LP5 15x15 {#RN_DETAIL_SM_440}
----------

Added support for the i.MX95 FRDM LP5 (15x15) board. Refer the boards/mcimx95frdm directory for the board-specific implementation.

Build command:

    make config=mx95frdm

SM-442: mx94alt mSel description incomplete in docs {#RN_DETAIL_SM_442}
----------

The cfg skip feature is for LM only, not CPUs in an LM. As the mx94alt cfg defines only a single user LM, the skip feature is useless. Removed all use of the skip flag from this cfg. Reminder the alt cfg files are not for production. They are only for NXP testing. 

Updated porting docs to reflect the correct behavior for various mSel.



SM-443: Add i.MX937 jailhouse and rpmsg configuration files {#RN_DETAIL_SM_443}
----------

Added two new SM config files: mx937frdmjailhouse.cfg and mx937frdmrpmsg.cfg.

Build command:

    make config=mx937frdmjailhouse cfg
    make config=mx937frdmjailhouse

And:

    make config=mx937frdmrpmsg cfg
    make config=mx937frdmrpmsg


SM-444: Add Android support for i.MX95 15x15 freedom LPDDR5 board {#RN_DETAIL_SM_444}
----------

Added an SM config file for running Android on the i.MX95 LPDDR5 Freedom board.

    make config=mx95frdm-android cfg
    make config=mx95frdm-android

Note builds for the i.MX95 LPDDR4 Freedom board should use the EVK versions of the configuration file as at the SM-level that board is compatible with the EVK. The LPDDR5 board is not due to PMIC changes.

SM-445: Add rpmsg support for FRDM-IMX952 {#RN_DETAIL_SM_445}
----------

Added a new config file for rpmsg use with the i.MX952 Freedom board. Compile with:

    make config=mx952frdmrpmsg cfg
    make config=mx952frdmrpmsg

SM-446: Add support for i.MX95 B1 {#RN_DETAIL_SM_446}
----------

Added support for i.MX95 B1. This is just a doc and test coverage change.

SM-447: Add i.MX95 LPDDR5 FRDM jailhouse and rpmsg configuration files {#RN_DETAIL_SM_447}
----------

Added two new SM config files: mx95frdmjailhouse.cfg and mx95frdmrpmsg.cfg.

Build command:

    make config=mx95frdmjailhouse cfg
    make config=mx95frdmjailhouse

And:

    make config=mx95frdmrpmsg cfg
    make config=mx95frdmrpmsg

SM-451: PF09 temp sensor enable broken on the i.MX95 FRDM LPDDR5 board {#RN_DETAIL_SM_451}
----------

This issue was caused by improper handling of board sensors (PMIC sensor) enable/disable operations in the BRD_SM_SensorEnable() function for the i.MX95-FRDM-LP5 board. The implementation has been updated to correctly manage PMIC sensor states.

 

