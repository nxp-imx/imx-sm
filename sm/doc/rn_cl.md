Change List {#RN_CL}
===========

The tables below also indicate which patch version, if any, in the previous release (
imx_sm_2024q1) includes the change. Note some of these patches may not have been released yet and
the data could change.

SM 2024Q2 Change List {#RN_P0}
====================================

Below is a list of changes between the previous release (imx_sm_2024q1) and this release (imx_sm_2024q2_er1).

New Feature {#RN_CL_NEW}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-26](https://jira.sw.nxp.com/projects/SM/issues/SM-26) | Add support for vendor-defined SCMI system power states |   | Y | Y |
| [SM-27](https://jira.sw.nxp.com/projects/SM/issues/SM-27) | Add low-power mode entry during SM idle |   | Y | Y |
| [SM-28](https://jira.sw.nxp.com/projects/SM/issues/SM-28) | Add support for DRAM retention [[detail]](@ref RN_DETAIL_SM_28) |   | Y | Y |
| [SM-29](https://jira.sw.nxp.com/projects/SM/issues/SM-29) | Add support for PLL spread spectrum mode |   | Y | Y |
| [SM-31](https://jira.sw.nxp.com/projects/SM/issues/SM-31) | Create syslog to record info about suspend entry/exit [[detail]](@ref RN_DETAIL_SM_31) |   | Y | Y |
| [SM-32](https://jira.sw.nxp.com/projects/SM/issues/SM-32) | Add fairness/prioritization to SM IRQ/event handling |   | Y | Y |
| [SM-92](https://jira.sw.nxp.com/projects/SM/issues/SM-92) | Add SCMI function to return config info [[detail]](@ref RN_DETAIL_SM_92) |   | Y | Y |
| [SM-97](https://jira.sw.nxp.com/projects/SM/issues/SM-97) | Add SCMI CPU protocol message to get CPU info [[detail]](@ref RN_DETAIL_SM_97) |   | Y | Y |
| [SM-101](https://jira.sw.nxp.com/projects/SM/issues/SM-101) | Support LM group shutdown/reset [[detail]](@ref RN_DETAIL_SM_101) |   | Y | Y |
| [SM-108](https://jira.sw.nxp.com/projects/SM/issues/SM-108) | Support the i.MX95 15x15 EVK [[detail]](@ref RN_DETAIL_SM_108) |   | Y | Y |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-13](https://jira.sw.nxp.com/projects/SM/issues/SM-13) | Remove the FRO trim hardcoding, instead load the value from fuses. |   | Y | Y |
| [SM-16](https://jira.sw.nxp.com/projects/SM/issues/SM-16) | Support TMPSNS powerup/down and ELE enable [[detail]](@ref RN_DETAIL_SM_16) |   | Y | Y |
| [SM-17](https://jira.sw.nxp.com/projects/SM/issues/SM-17) | Implement SCMI message sequence checking [[detail]](@ref RN_DETAIL_SM_17) |   | Y | Y |
| [SM-21](https://jira.sw.nxp.com/projects/SM/issues/SM-21) | Misc. FuSa improvements [[detail]](@ref RN_DETAIL_SM_21) |   | Y | Y |
| [SM-71](https://jira.sw.nxp.com/projects/SM/issues/SM-71) | Enable/disable VDD_ARM on AP LM boot/shutdown [[detail]](@ref RN_DETAIL_SM_71) |   | Y | Y |
| [SM-74](https://jira.sw.nxp.com/projects/SM/issues/SM-74) | Support additional configs for system testing [[detail]](@ref RN_DETAIL_SM_74) |   | Y | Y |
| [SM-76](https://jira.sw.nxp.com/projects/SM/issues/SM-76) | Misc. updates to SM configurations |   | Y | Y |
| [SM-78](https://jira.sw.nxp.com/projects/SM/issues/SM-78) | Provide misc. control for ADC test voltage [[detail]](@ref RN_DETAIL_SM_78) |   | Y | Y |
| [SM-82](https://jira.sw.nxp.com/projects/SM/issues/SM-82) | Create reset reason for SM error/exit [[detail]](@ref RN_DETAIL_SM_82) |   | Y | Y |
| [SM-84](https://jira.sw.nxp.com/projects/SM/issues/SM-84) | Remove unnecessary SM clock permissions for the AP [[detail]](@ref RN_DETAIL_SM_84) |   | Y | Y |
| [SM-86](https://jira.sw.nxp.com/projects/SM/issues/SM-86) | Fix MISRA violations that resulted from new scan rules |   | Y | Y |
| [SM-93](https://jira.sw.nxp.com/projects/SM/issues/SM-93) | Add PERF_GPU to the GPU_PROT/NPROT resources [[detail]](@ref RN_DETAIL_SM_93) |   | Y | Y |
| [SM-96](https://jira.sw.nxp.com/projects/SM/issues/SM-96) | Add cfg to support a NETC shared use-case [[detail]](@ref RN_DETAIL_SM_96) |   | Y | Y |
| [SM-98](https://jira.sw.nxp.com/projects/SM/issues/SM-98) | Support SCMI agent reset when resources are shared [[detail]](@ref RN_DETAIL_SM_98) |   | Y | Y |
| [SM-100](https://jira.sw.nxp.com/projects/SM/issues/SM-100) | Support final SCMI 3.2 spec [[detail]](@ref RN_DETAIL_SM_100) |   | Y | Y |
| [SM-102](https://jira.sw.nxp.com/projects/SM/issues/SM-102) | Remove A55PER and A55P performance domains |   | Y | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-83](https://jira.sw.nxp.com/projects/SM/issues/SM-83) | IOMUXC header incorrectly overwrites the JTAG TDI mux [[detail]](@ref RN_DETAIL_SM_83) |   | Y | Y |
| [SM-85](https://jira.sw.nxp.com/projects/SM/issues/SM-85) | Release of M7 CPUWAIT during M7MIX power down may result in unterminated transactions [[detail]](@ref RN_DETAIL_SM_85) |   | Y | Y |
| [SM-95](https://jira.sw.nxp.com/projects/SM/issues/SM-95) | SCMI performance levels should avoid duplicate frequencies [[detail]](@ref RN_DETAIL_SM_95) |   | Y | Y |
| [SM-99](https://jira.sw.nxp.com/projects/SM/issues/SM-99) | Remove ADC clock access as disable can hang the SM [[detail]](@ref RN_DETAIL_SM_99) |   | Y | Y |
| [SM-103](https://jira.sw.nxp.com/projects/SM/issues/SM-103) | Monitor ELE dump and events commands do not work [[detail]](@ref RN_DETAIL_SM_103) |   | Y | Y |
| [SM-104](https://jira.sw.nxp.com/projects/SM/issues/SM-104) | Fix issue with MRCs with ELE regions not being cleared [[detail]](@ref RN_DETAIL_SM_104) |   | Y | Y |

Silicon Workaround {#RN_CL_REQ}
------------

These are a mix of silicon errata workarounds and recommended usage changes.

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-94](https://jira.sw.nxp.com/projects/SM/issues/SM-94) | Align to i.MX95 Rev 1 datasheet [[detail]](@ref RN_DETAIL_SM_94) |   | Y | Y |
| [SM-105](https://jira.sw.nxp.com/projects/SM/issues/SM-105) | Add software workaround for ERR052232 (SM handshake clock sync) |   | Y | Y |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-77](https://jira.sw.nxp.com/projects/SM/issues/SM-77) | SM 2024Q2 ER1 documentation updates |   | Y | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-16: Support TMPSNS powerup/down and ELE enable {#RN_DETAIL_SM_16}
----------

Added new DEV_SM functions for sensor power up and down. Powered down the A55 sensor when the MIX goes off. Powered up/down the ANA sensor as part of system suspend.

SM-17: Implement SCMI message sequence checking {#RN_DETAIL_SM_17}
----------

Support an SCMI message sequence requirement. Enable per channel via new config and configtool options (sequence=token). This option requires the token field of the SCMI message header to increment sequentially. Failure to do so will result in a new SCMI_ERR_SEQ_ERROR error.

Note this feature requires the agent keep and maintain the sequence number accoss all power state transitions other than SM-driven shutdown/reset which will reset the sequence to 0. This means suspend/resume may need to retain the sequence number using the SCMI_SequenceSave() and SCMI_SequenceRestore() functions. By default, checking of agent-side notification sequence is disabled unless enabled via SCMI_SequenceConfig().

SM-21: Misc. FuSa improvements {#RN_DETAIL_SM_21}
----------

Updated the SCMI FuSa protocol. Implemented support functions for exit, exception, and fault recovery. Added support for ASSERT/ENSURE. Added a board callout to allow FuSa tools to configure clocks. Cleaned-up FCCU IRQ names and removed handling of other FCCU interrupts. Fixed issues with looping, error on buffer size, FREE bit status.

SM-28: Add support for DRAM retention {#RN_DETAIL_SM_28}
----------

Added DRC driver to perform DRAM retention when entering system suspend. Relies on OEI DDR plug-in changes to handover the config so users must utilize the plug-in associated with the release.

SM-31: Create syslog to record info about suspend entry/exit {#RN_DETAIL_SM_31}
----------

Created new syslog to record information about suspend entry/exit. Added new 'syslog' monitor command to display the syslog. Can be retrieved as an array of raw 32-bit words via the new SCMI_MSG_MISC_SYSLOG and SCMI_MiscSyslog() client API function.

SM-71: Enable/disable VDD_ARM on AP LM boot/shutdown {#RN_DETAIL_SM_71}
----------

Added VOLT as an LM start/stop sequence option. Updated the mx95evk cfg file to turn on/off the VDD_ARM as part of the AP LM config. After booting all LM, the SM will turn off VDD_ARM if the AP55P power domain is not on.

SM-74: Support additional configs for system testing {#RN_DETAIL_SM_74}
----------

Added an "other" directory to the configs directory. This contains additional cfg files that are used for testing. These files are "as is" and not supported as part of the SM test and release.

Added an other config:
 * mx95evkjailhouse.cfg - used for Jailhouse testing.

Using this cfg files is identical to supported cfg files in the top-level configs. No need to specify other in the config name:

    make config=mx95evkjailhouse cfg

    make config=mx95evkjailhouse

 

SM-78: Provide misc. control for ADC test voltage {#RN_DETAIL_SM_78}
----------

To enable the ADC self-test function in the ADC driver, the self-test function requires a bandgap voltage from the BBSM domain. There is a need to set the *snvs_clkrst_ctrl[7]* register of the *BLK_CTRL_BBSM* module to provide the bandgap voltage to ADC. Hence, provided a control (6) to configure the *snvs_clkrst_ctrl[7]* register of the *BLK_CTRL_BBSM* module. The value must be in the bit[7] position (e.g. 0x80). This also includes adding permissions in all cfg files so that the owner of the ADC also has access to this control.

In addition, this change modifies the way board controls are indexed. Before they were added to the end of device controls. The problem is this requires their value change anytime new device controls are added. This was changed to move board controls to start at 0x8000. This remapping is handled in the SCMI code layer and does not impact the board port. It does require board control indexes passed via SCMI from agents be changed this once but should not be something that has to occur in the future.

Customers will need to update the indexes used in agent code. WiIl also need to regenerate their config headers from cfg files.

SM-82: Create reset reason for SM error/exit {#RN_DETAIL_SM_82}
----------

Created a new reset reason (DEV_SM_REASON_SM_ERR) to indicate the SM has errored. This will record the reset reason and reset the system. Called within the SM via SM_Error(). Also called if main() exits. The status code is stored in errId. If possible, the first extension word will contain the PC of the function that called SM_Error() or exit().

SM-83: IOMUXC header incorrectly overwrites the JTAG TDI mux {#RN_DETAIL_SM_83}
----------

Updated the fsl_iomux.h header file from the SDK. This fixes the daisy register address. Pads with no daisy should use an address of 0x0000000 rather than 0x443C0000. Without this fix configuration of most pads will overwrite the JTAG_TDI pad config.

SM-84: Remove unnecessary SM clock permissions for the AP {#RN_DETAIL_SM_84}
----------

Removed AP access to some SM clocks. Removed SM reservation of the same clocks. This was implemented prior to SCMI 3.2 BETA3 when Linux required the rights to enable these clocks. No longer required. Customers should make similar changes to their cfg files.

SM-85: Release of M7 CPUWAIT during M7MIX power down may result in unterminated transactions {#RN_DETAIL_SM_85}
----------

SoC driver-level code for the SRC indiscriminately releases the associated CPUWAIT signal during MIX soft power down.  If the M7 landing zone is not valid, the release of CPUWAIT can cause unterminated transactions.

The release of CPUWAIT during MIX soft power down is only required for A55.  The SRC driver code was updated to filter the CPUWAIT release based on CPU.

SM-92: Add SCMI function to return config info {#RN_DETAIL_SM_92}
----------

Added a new SCMI misc protocol function to get the SM config (cfg) file name and mSel value. Just the basename is returned, max of 16 characters. Also displayed in the debug monitor 'info' command.

SM-93: Add PERF_GPU to the GPU_PROT/NPROT resources {#RN_DETAIL_SM_93}
----------

Updated the GPU_PROT and GPU_NPROT resource definitions used by the configtool to give the owners of these resources the ability to call SCMI performance protocol functions on the PERF_GPU performance domain. Customers will need to rerun the configtool on their cfg.

SM-94: Align to i.MX95 Rev 1 datasheet {#RN_DETAIL_SM_94}
----------

Electrical specifications used by SM were updated based on MX95 Rev 1 datasheet.

SM-95: SCMI performance levels should avoid duplicate frequencies {#RN_DETAIL_SM_95}
----------

The SCMI specification states that performance levels are neither guaranteed to be contiguous or required to be on a linear scale.  Agents may sort the performance levels returned from performance level queries and could report warnings for duplicates.  SM exposes a "parked" performance level that is guaranteed across all voltage ranges and power domain states.  In some cases, this "parked" state was a duplicate of the "low" performance level.  The "parked" level has been updated to make it unique and, therefore, avoid duplicate warnings from agents.

SM-96: Add cfg to support a NETC shared use-case {#RN_DETAIL_SM_96}
----------

A new cfg file (mx95netc.cfg in configs/other) has been created to demonstrate a shared NETC use-case. In this use-case the M7 core owns NETC ENETC2 PSI, and I2C5/I2C7 which control the PHY. The AP core uses ENETC2 VSIs.

Also, disabled KPA for the NETC shared use-case since SMMU won't be used for this case.

During NETC VSI-PSI message communication, PSI side needs to have access to both PSI/VSI side memory so this cfg allows the M7 to read The AP core DDR memory.

SM-97: Add SCMI CPU protocol message to get CPU info {#RN_DETAIL_SM_97}
----------

Added a new CPU_INFO_GET message and associated client API SCMI_CpuInfoGet(). This returns information about a CPU such as the run and sleep modes, reset address, etc.

SM-98: Support SCMI agent reset when resources are shared {#RN_DETAIL_SM_98}
----------

When the AP LM contains both the AP core and M7 core (aux core use-case), the AP needs a way to reset the M7 SCMI state and MU. The SCMI base protocol contains such a function so long as the M7 is in another agent. The problem is this relies on knowing what state to reset based on access right configuration in the SM cfg.

In some cfgs, some resources might be shared in such a way that access rights cannot be used. This change modifies the agent reset function to instead track which agent last accessed a shared resource (e.g. clock rate) and use that info to reset the state.

 

SM-99: Remove ADC clock access as disable can hang the SM {#RN_DETAIL_SM_99}
----------

Giving an agent access to the ADC clock can allow the agent to disable the clock. An agent access then to the ADC will hang the bus, then hang the SM, and result in a watchdog reset of the system.

This change removes implicit agent access to the ADC clock if own access to the ADC. In NXP reference board ports, the ADC clock is now initialized to 80MHz.

Explicit access can be granted to the CLK_ADC resource in the cfg file but it also opens a path for the agent with access to cause an SM watchdog and reset.

SM-100: Support final SCMI 3.2 spec {#RN_DETAIL_SM_100}
----------

Updated the client and RPC protocol to match the final SCMI 3.2 spec. The previous implementation was to the BETA3 spec. The new version changed the pin control protocol messages which breaks backwards compatibility. Customers must use the OS/SDK version tested with this version of the SM.

Also added generic OEM configuration handing for clocks. This is used to support SSC.

SM-101: Support LM group shutdown/reset {#RN_DETAIL_SM_101}
----------

Introduced the concept of LM groups. Can be specified in the cfg file using the _group_ argument on the LM command. Default is to place all in group 0.

Reset/shutdown of an LM group are now options for fault reactions. Added new reset/shutdown power modes that will operate only on LM in group 0.

All this is to support leaving some LM up when resetting all the other LM to provide for a "partial" reset of the device.

SM-103: Monitor ELE dump and events commands do not work {#RN_DETAIL_SM_103}
----------

The ELE MU are different and have eight RR/TR registers instead of four. Modified the SDK MU driver to support the difference. This resolved the hang with long ELE messages.

SM-104: Fix issue with MRCs with ELE regions not being cleared {#RN_DETAIL_SM_104}
----------

Modified configtool to generate register writes to clear regions passed from ELE. Requires customers regenerate config header files.

SM-108: Support the i.MX95 15x15 EVK {#RN_DETAIL_SM_108}
----------

The i.MX95 15x15 EVK has the PF09 in ASILB mode by default. This change writes to the PMIC to change the XRESET handling.

