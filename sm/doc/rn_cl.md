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
| [SM-10](https://jira.sw.nxp.com/projects/SM/issues/SM-10) | Add eMcem driver to support FCCU [[detail]](@ref RN_DETAIL_SM_10) |   | Y | Y |
| [SM-30](https://jira.sw.nxp.com/projects/SM/issues/SM-30) | Support management of peripheral low-power interfaces [[detail]](@ref RN_DETAIL_SM_30) |   | Y | Y |
| [SM-66](https://jira.sw.nxp.com/projects/SM/issues/SM-66) | Support designation of A55 CPUs to wake during A55P wakeup [[detail]](@ref RN_DETAIL_SM_66) |   | Y | Y |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-14](https://jira.sw.nxp.com/projects/SM/issues/SM-14) | Include ELE status in the reset record [[detail]](@ref RN_DETAIL_SM_14) |   | Y | Y |
| [SM-23](https://jira.sw.nxp.com/projects/SM/issues/SM-23) | Vet the peripheral ID parameter in the CPU LP protocol [[detail]](@ref RN_DETAIL_SM_23) |   | Y | Y |
| [SM-59](https://jira.sw.nxp.com/projects/SM/issues/SM-59) | Support latest SCMI 3.2 BETA3 spec changes [[detail]](@ref RN_DETAIL_SM_59) |   | Y | Y |
| [SM-61](https://jira.sw.nxp.com/projects/SM/issues/SM-61) | Save/restore PLL registers impacted during MIX power gating [[detail]](@ref RN_DETAIL_SM_61) |   | Y | Y |
| [SM-62](https://jira.sw.nxp.com/projects/SM/issues/SM-62) | Update SM configurations [[detail]](@ref RN_DETAIL_SM_62) |   | Y | Y |
| [SM-64](https://jira.sw.nxp.com/projects/SM/issues/SM-64) | Disable PF09 PWRUP interrupt [[detail]](@ref RN_DETAIL_SM_64) |   | Y | Y |
| [SM-65](https://jira.sw.nxp.com/projects/SM/issues/SM-65) | Support configuring the NXP board ports to not use a debug UART [[detail]](@ref RN_DETAIL_SM_65) |   | Y | Y |
| [SM-67](https://jira.sw.nxp.com/projects/SM/issues/SM-67) | Update i.MX95 EVK port to reset board on system reset [[detail]](@ref RN_DETAIL_SM_67) |   | Y | Y |
| [SM-69](https://jira.sw.nxp.com/projects/SM/issues/SM-69) | Misc. coding standards fixes [[detail]](@ref RN_DETAIL_SM_69) |   | Y | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-63](https://jira.sw.nxp.com/projects/SM/issues/SM-63) | Fix polarity of WDOG ANY mask [[detail]](@ref RN_DETAIL_SM_63) |   | Y | Y |
| [SM-73](https://jira.sw.nxp.com/projects/SM/issues/SM-73) | Implement PLL lock timeouts and PLL power up delays [[detail]](@ref RN_DETAIL_SM_73) |   | Y | Y |
| [SM-81](https://jira.sw.nxp.com/projects/SM/issues/SM-81) | Incorrect reference to WAKEUPMIX memory slice instance [[detail]](@ref RN_DETAIL_SM_81) |   | Y | Y |

Silicon Workaround {#RN_CL_REQ}
------------

These are a mix of silicon errata workarounds and recommended usage changes.

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-54](https://jira.sw.nxp.com/projects/SM/issues/SM-54) | Add software workaround for ERR052127 (NOCMIX BLK_CTRL sync) [[detail]](@ref RN_DETAIL_SM_54) |   | Y | Y |
| [SM-58](https://jira.sw.nxp.com/projects/SM/issues/SM-58) | Add software workaround for ERR052128 (TMPSNS wait time) [[detail]](@ref RN_DETAIL_SM_58) |   | Y | Y |
| [SM-68](https://jira.sw.nxp.com/projects/SM/issues/SM-68) | Update low/nominal drive voltages per latest datasheet [[detail]](@ref RN_DETAIL_SM_68) |   | Y | Y |
| [SM-70](https://jira.sw.nxp.com/projects/SM/issues/SM-70) | Support M7 SysTick wakeup from WFI when target sleep mode set to RUN [[detail]](@ref RN_DETAIL_SM_70) |   | Y | Y |
| [SM-79](https://jira.sw.nxp.com/projects/SM/issues/SM-79) | Bypass workaround for the M7 address issue on parts with ROM patch [[detail]](@ref RN_DETAIL_SM_79) |   | Y | |
| [SM-80](https://jira.sw.nxp.com/projects/SM/issues/SM-80) | Support ROM spec change for SPI NAND boot device type [[detail]](@ref RN_DETAIL_SM_80) |   | Y | Y |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-57](https://jira.sw.nxp.com/projects/SM/issues/SM-57) | SM 2024Q1 documentation updates |   | Y | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-10: Add eMcem driver to support FCCU {#RN_DETAIL_SM_10}
----------

Added the SAF eMcem component which manages the FCCU. The FCCU supports 72 faults (see the SoC RM), but only 18 faults are currently enabled:
 * 0-1:  Temp sensor panics (ANA and A55)
 * 18-21:  Watchdogs (2 - 5)
 * 22-33:  Software generated (0-11)

The others might be enabled when a full FuSa solution is deployed. The M33/M7 reset and lockup conditions are still handled as interrupts.

The FCCU is configured to generate an SM interrupt as the initial reaction and a system cold reset as the delayed (333ms) reaction. The SM interrupt will handle faults as configured in the SM config generated with the configtool.

SM-14: Include ELE status in the reset record {#RN_DETAIL_SM_14}
----------

Updated the extended reset data for the ELE group 1-3 (interrupt 160-162) to capture the ELE reset and interrupt register status.

    Reset request: reason=cm33_exc, errId=160
      0x1FFC4A58
      0x00200020 <- ELE_RST_REQ_STAT
      0x00000020 <- ELE_IRQ_REQ_STAT

The definition of these values can be found in the Block Control - Secure AON Domain chapter of the SoC RM.

SM-23: Vet the peripheral ID parameter in the CPU LP protocol {#RN_DETAIL_SM_23}
----------

Added new per agent SCMI configuration data to store peripheral LPI access rights (perlpiPerms). The rights to specify the low-power state of a peripheral with SCMI_CpuPerLpmConfigSet() are then checked for EXCLUSIVE access rights. 

The config data is filled in by the configtool from PERLPI_* resource definitions. These new resources are linked automatically with ownership of the associated peripheral. In addition to the automatically linked rights for owning the peripheral, NXP configs also grant access to the AP secure agent to allow ATF to configure the low-power behavior of these peripherals. Customer ports will need to do the same.

SM-30: Support management of peripheral low-power interfaces {#RN_DETAIL_SM_30}
----------

Agents can configure the management of peripheral low-power interfaces using SCMI_CpuPerLpmConfigSet.  On MX95, the STOP and Q-CHAN low-power signals will be managed by SM via BLK_CTRL registers per the configuration specified by SCMI_CpuPerLpmConfigSet.  During flows that power down Cortex-M7/Cortex-A55 platforms, the specified STOP and Q-CHAN requests will be asserted.  Conversely, during flows that power up these CPU platforms, the specified STOP and Q-CHAN requests will be deasserted.  All other steps to configure the peripheral and associated clocks for low-power operation are the responsibility of the agent.

SM-54: Add software workaround for ERR052127 (NOCMIX BLK_CTRL sync) {#RN_DETAIL_SM_54}
----------

A software workaround for ERR052127 will be applied by SM each time the NOCMIX is powered on.  Per the errata description, a simple read of a NOCMIX BLK_CTRL register will be performed to synchronize the NOCMIX BLK_CTRL output signals.

SM-58: Add software workaround for ERR052128 (TMPSNS wait time) {#RN_DETAIL_SM_58}
----------

The workaround for ERR052128 calls for a 250ns delay before clearing temperature sensor interrupts. Added such a delay in the sensor interrupt handler. Delay is 1us, the minimum supported by the system delay function.

SM-59: Support latest SCMI 3.2 BETA3 spec changes {#RN_DETAIL_SM_59}
----------

Updated to the BETA3 version of the SCMI 3.2 spec. Added NEGOTIATE_PROTOCOL_VERSION messages for all protocols. Will return NOT_SUPPORTED if the requested version is not the same major version and less than or equal to the supported minor version.

SM-61: Save/restore PLL registers impacted during MIX power gating {#RN_DETAIL_SM_61}
----------

Power domains that include PLLs will experience the loss of PLL configuration when the domain is powered down.  Some agents do not have the ability to track this dependency and restore the PLL configuration after power is restored.  Support in SM was added to save/restore the context of the HSIO PLL (HSIO_TOP power domain) and the LDB PLL (display power domain) when the respective power domain is powered down/up.   Agents are still responsible for enabling the clock domains associated with these PLLs after power is restored.

SM-62: Update SM configurations {#RN_DETAIL_SM_62}
----------

Minor change to the mx95alt config to give the M33 access to the SEMA41 module. This is only to allow testing.

Updated the mk95evk config to correctly define the start/stop script for mSel 1 and 2.

SM-63: Fix polarity of WDOG ANY mask {#RN_DETAIL_SM_63}
----------

Update the board BOARD_WdogModeSet() function to correctly manage the WDOG_ANY mask bits. A new BOARD_WDOG_ANY_INIT define indicates which watchdog(s) should not drive the WDOG ANY signal to the PMIC to do a cold reboot (all except the one(s) used by the SM). The BOARD_WDOG_ANY_MASK define indicates which watchdog(s) should have this dynamically changed when reconfiguring for a cold/warm watchdog reset (used from the debug monitor wdog command).

Customers should make the same change. Without this change the SM watchdog will incorrectly do a warm reset and all the other watchdogs will always do a full system cold reset (not an LM reset).

SM-64: Disable PF09 PWRUP interrupt {#RN_DETAIL_SM_64}
----------

Added code in the board BRD_SM_SerialDevicesInit() function to disable the PF09 PWRUP interrupt. Customers should do the same if not using this interrupt for some additional PMIC management.

SM-65: Support configuring the NXP board ports to not use a debug UART {#RN_DETAIL_SM_65}
----------

Supported NXP board ports disabling UART usage by setting BOARD_DEBUG_UART_INSTANCE to 0. This can be accomplished by setting DEBUG_UART_INSTANCE to 0 in the cfg file. Note access control still applies and configuring the SM to not use a UART doesn't make it accessible to other agents. However, BOARD_DEBUG_UART_INSTANCE must be set to 0 if no UART will be made available to the SM.

Note this required changes in the board.c file. This code was also restructured to allow other suspend/resume functions to enable/disable the UART wakeup interrupt. Customer ports will require similar changes.

SM-66: Support designation of A55 CPUs to wake during A55P wakeup {#RN_DETAIL_SM_66}
----------

If all Cortex-A55 wake sources have been aggregated to the A55 platform (A55 cluster), the SM needs a way for the agents to indicate the list of A55 CPUs to be automatically awakened when the A55 platform wakes.  The SCMI_CpuSleepModeSet() function was updated to take a flags parameter that can be used to specify if the respective A55 CPU should be added to the wake list.  During the resume of the A55 platform, the SM will automatically wake all A55 CPUs specified in wake list.

SM-67: Update i.MX95 EVK port to reset board on system reset {#RN_DETAIL_SM_67}
----------

Modified the i.MX95 EVK board code to overload the SM_SYSTEMRESET function. The new board function requests cold reset by asserting WDOG_ANY to the PMIC. This is done by changing the mux to GPIO1 and directly asserting. As some PMIC are not fused to react to this, the code falls back to doing a warm SoC-only reset.

Customers should make a similar change if they wish system reset to reset the entire board via the PMIC.

SM-68: Update low/nominal drive voltages per latest datasheet {#RN_DETAIL_SM_68}
----------

Low/nominal drive mode voltage definitions for VDD_ARM and VDD_SOC were updated per the latest datasheet.

SM-69: Misc. coding standards fixes {#RN_DETAIL_SM_69}
----------

Fix various coding standard issues, copyrights, and doxygen comments.

SM-70: Support M7 SysTick wakeup from WFI when target sleep mode set to RUN {#RN_DETAIL_SM_70}
----------

Support was added to configure the Cortex-M7 platform to allow the SysTick to wake the CM7 from WFI.  Note that the targeted sleep mode of the Cortex-M7 must be set to RUN prior to entering WFI.

SM-73: Implement PLL lock timeouts and PLL power up delays {#RN_DETAIL_SM_73}
----------

A 5us delay was added between updates of PLL integer/fractional factors and power up of the PLL.  This delay is required per the PLL block guide.

Misconfiguration of PLL can cause a SM WDOG timeout during PLL lock operations.   A PLL lock timeout of 100us per PLL block guide was added to protect the SM against misconfiguration.  An error will be returned to the caller if PLL fails to lock within the 100us timeout.

SM-79: Bypass workaround for the M7 address issue on parts with ROM patch {#RN_DETAIL_SM_79}
----------

SM contains a workaround for an M33 ROM issue where an image load address is passed rather than the execute address. This change skips that workaround if the part is not an Ax part. It also skips on Ax if the ROM patch to fix this issue is applied.

SM-80: Support ROM spec change for SPI NAND boot device type {#RN_DETAIL_SM_80}
----------

An updated ROM spec changed the value for the FlexSPI NAND boot device type from 0x3 to 0x8.

SM-81: Incorrect reference to WAKEUPMIX memory slice instance {#RN_DETAIL_SM_81}
----------

A data structure containing MIX management info has an incorrect reference to the memory controller instance associated with WAKEUPMIX.  This error results in an invalid attempt to access to the memory controller instance during calls to configure WAKEUPMIX memory retention.

