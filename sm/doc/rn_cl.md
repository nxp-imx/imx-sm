Change List {#RN_CL}
===========

The tables below also indicate which patch version, if any, in the previous release (
imx_sm_2023q4_er1) includes the change. Note some of these patches may not have been released yet and
the data could change.

SM 2023Q4 Change List {#RN_P0}
====================================

Below is a list of changes between the previous release (imx_sm_2023q4_er1) and this release (imx_sm_2023q4_er2).

New Feature {#RN_CL_NEW}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-55](https://jira.sw.nxp.com/projects/SM/issues/SM-55) | Add PF09 voltage monitor functions [[detail]](@ref RN_DETAIL_SM_55) |   | Y | Y |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-12](https://jira.sw.nxp.com/projects/SM/issues/SM-12) | Load temp sensor trim from fuses and configure panic [[detail]](@ref RN_DETAIL_SM_12) |   | Y | Y |
| [SM-18](https://jira.sw.nxp.com/projects/SM/issues/SM-18) | Support final SCMI 3.2 spec changes [[detail]](@ref RN_DETAIL_SM_18) |   | Y | Y |
| [SM-20](https://jira.sw.nxp.com/projects/SM/issues/SM-20) | Add V2X TRDC MDAC mapping and update configs [[detail]](@ref RN_DETAIL_SM_20) |   | Y | Y |
| [SM-22](https://jira.sw.nxp.com/projects/SM/issues/SM-22) | Add PMIC voltage ramp delay [[detail]](@ref RN_DETAIL_SM_22) |   | Y | Y |
| [SM-36](https://jira.sw.nxp.com/projects/SM/issues/SM-36) | Return lower-case strings for all resource names [[detail]](@ref RN_DETAIL_SM_36) |   | Y | Y |
| [SM-40](https://jira.sw.nxp.com/projects/SM/issues/SM-40) | Add device controls for some AON/WAKE peripherals [[detail]](@ref RN_DETAIL_SM_40) |   | Y | Y |
| [SM-50](https://jira.sw.nxp.com/projects/SM/issues/SM-50) | Update configtool names to match latest SoC RM [[detail]](@ref RN_DETAIL_SM_50) |   | Y | Y |
| [SM-53](https://jira.sw.nxp.com/projects/SM/issues/SM-53) | Add SCMI misc function to get silicon info [[detail]](@ref RN_DETAIL_SM_53) |   | Y | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-34](https://jira.sw.nxp.com/projects/SM/issues/SM-34) | Cortex-A55 LM reset may leave the GIC in an unusable state [[detail]](@ref RN_DETAIL_SM_34) |   | Y | Y |
| [SM-41](https://jira.sw.nxp.com/projects/SM/issues/SM-41) | Fix various issues with SM configurations [[detail]](@ref RN_DETAIL_SM_41) |   | Y | Y |
| [SM-43](https://jira.sw.nxp.com/projects/SM/issues/SM-43) | Board MISC control notification broken in the mx95evk board port [[detail]](@ref RN_DETAIL_SM_43) |   | Y | Y |
| [SM-44](https://jira.sw.nxp.com/projects/SM/issues/SM-44) | Returned SCMI perf levels not limited by part speed [[detail]](@ref RN_DETAIL_SM_44) |   | Y | Y |
| [SM-47](https://jira.sw.nxp.com/projects/SM/issues/SM-47) | Reset associated MU modules during CPU stop sequence [[detail]](@ref RN_DETAIL_SM_47) |   | Y | Y |
| [SM-51](https://jira.sw.nxp.com/projects/SM/issues/SM-51) | Incorrect scan of voltage level required for SCMI performance domains [[detail]](@ref RN_DETAIL_SM_51) |   | Y | Y |
| [SM-52](https://jira.sw.nxp.com/projects/SM/issues/SM-52) | Enabling hardware LPM control must consider MIX power state [[detail]](@ref RN_DETAIL_SM_52) |   | Y | Y |
| [SM-56](https://jira.sw.nxp.com/projects/SM/issues/SM-56) | Move VPUJPEG clock ownership to SM [[detail]](@ref RN_DETAIL_SM_56) |   | Y | Y |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-42](https://jira.sw.nxp.com/projects/SM/issues/SM-42) | SM 2023Q4 ER2 documentation updates |   | Y | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-12: Load temp sensor trim from fuses and configure panic {#RN_DETAIL_SM_12}
----------

Use TMPSNS trim from fuses. Enable interrupts. Configure panic based on market segment fusing.

SM-18: Support final SCMI 3.2 spec changes {#RN_DETAIL_SM_18}
----------

Updated the SCMI clock implementation to conform to the final ARM SCMI 3.2 spec. Removed extra NXP-added clock attributes and added support for the new ARM-defined CLOCK_GET_PERMISSIONS message.

SM-20: Add V2X TRDC MDAC mapping and update configs {#RN_DETAIL_SM_20}
----------

Updated cfg names of V2X resources:
 * V2X_APP1 -> V2X_SHE1
 * V2X_SHE -> V2X_SHE0

Modified cfg files to make the V2X (DID=12) owner of the V2X_FH IP. Do not assign the V2X_FH the Linux DID but still allow access (mdid=none for V2X_FH in AP-NS agent).

Customers must make similar changes to their cfg files.

SM-22: Add PMIC voltage ramp delay {#RN_DETAIL_SM_22}
----------

Added delay after PMIC voltage change or state change for voltage to ramp up/down.

SM-34: Cortex-A55 LM reset may leave the GIC in an unusable state {#RN_DETAIL_SM_34}
----------

The interface between GIC and the associated Cortex-A55 CPU must be quiesced prior to reset of a Cortex-A55 CPU.  During a non-cooperative shutdown/reset of a logical machine, SM cannot rely on the Cortex-A55 to leave the GIC in a quiescent state or recover the GIC interface after restart.  SM was updated to use the GICR_WAKER to quiesce interfaces between GIC and Cortex-A55 during the CPU stop operation.

SM-36: Return lower-case strings for all resource names {#RN_DETAIL_SM_36}
----------

All resource names changed to lower-case. This was done to enable reuse of Linux test scripts from prior i.MX. Resource text strings exist in the device and board code. Customers need to update their board code to do the same.

SM-40: Add device controls for some AON/WAKE peripherals {#RN_DETAIL_SM_40}
----------

Added i.MX95 device misc. controls for various BLK_CTRL settings:
 - 0: DEV_SM_CTRL_PDM_CLK_SEL - AON mix PDM clock select
 - 1: DEV_SM_CTRL_MQS1_SETTINGS - AON mix MQS settings
 - 2: DEV_SM_CTRL_SAI1_MCLK - AON mix SAI1 MCLK
 - 3: DEV_SM_CTRL_SAI3_MCLK - WAKE mix SAI3 MCLK
 - 4: DEV_SM_CTRL_SAI4_MCLK - WAKE mix SAI4 MCLK
 - 5: DEV_SM_CTRL_SAI5_MCLK - WAKE mix SAI5 MCLK

Note adding these will cause board misc. controls to shift in number (+6). This will require agent code to change the value passed in the misc. control API calls.

SM-41: Fix various issues with SM configurations {#RN_DETAIL_SM_41}
----------

Changed cfg files and associated generated headers:

- Move BUTTON access to AP non-secure from AP secure
- Clean-up of some duplicate assignments

SM-43: Board MISC control notification broken in the mx95evk board port {#RN_DETAIL_SM_43}
----------

Fixed i.MX95 EVK board control code to support flag for control assert (bit0) and negate (bit1). Inverted state sent to the bus expander enable (enabled low). Customers may need to do the same if they copied the control code from an NXP reference board port.

SM-44: Returned SCMI perf levels not limited by part speed {#RN_DETAIL_SM_44}
----------

SCMI performance levels for Cortex-A55 are limited based on speed grade fuses.   Only devices with Cortex-A55 speed grade fusing of 2.0 GHz and above will support the super-overdrive performance level for Cortex-A55.

SM-47: Reset associated MU modules during CPU stop sequence {#RN_DETAIL_SM_47}
----------

The MU modules in AONMIX include connections for power state awareness of the remote side.  Subsequently, these MUs require the remote side to be powered during a soft reset of the module issued from the local side.  The SM issues a soft reset of impacted MU modules during shutdown/reset of a logical machine.  SM was updated to perform a soft reset of impacted MU modules during the CPU stop operation to ensure the remote side is powered.

SM-50: Update configtool names to match latest SoC RM {#RN_DETAIL_SM_50}
----------

Updated BLK_CTRL names in configtool to match latest SoC RM:
 * BLK_CTRL_C -> BLK_CTRL_CAMERAMIX
 * BLK_CTRL_D -> BLK_CTRL_DISPLAYMIX
 * BLK_CTRL_G -> BLK_CTRL_GPUMIX
 * BLK_CTRL_H -> BLK_CTRL_HSIOMIX
 * BLK_CTRL_E -> BLK_CTRL_NETCMIX
 * BLK_CTRL_V -> BLK_CTRL_VPUMIX

This requires customers to update their cfg files.

SM-51: Incorrect scan of voltage level required for SCMI performance domains {#RN_DETAIL_SM_51}
----------

Updating the level of an SCMI performance domain results in SM scanning all performance domains that share the same voltage supply to determine if the respective voltage can be raised or lowered.  This scanning procedure within the SM was updated to ensure that all dependent performance domains are considered in the evaluation of the required voltage.

SM-52: Enabling hardware LPM control must consider MIX power state {#RN_DETAIL_SM_52}
----------

The SRC module does not allow hardware-based power control of a MIX to be enabled when a MIX is powered down.  During SM initialization, the power status of a MIX is checked prior to updating the respective hardware-based control power control.

SM-53: Add SCMI misc function to get silicon info {#RN_DETAIL_SM_53}
----------

Added new SCMI MISC_SI_INFO message to obtain the silicon info (deviceId, siRev, partNum, etc.). Reference API function is SCMI_MiscSiInfo().

SM-55: Add PF09 voltage monitor functions {#RN_DETAIL_SM_55}
----------

Added PF09 PMIC driver functions to configure the voltage monitors:
 * PF09_MonitorSet()
 * PF09_MonitorEnable()

Called functions from the i.MX95 EVK BRD_SM_SerialDevicesInit() function to disable the PF09 monitoring of the PF53 voltages (SOC and ARM). Customers may need to do the same in their board port. 

SM-56: Move VPUJPEG clock ownership to SM {#RN_DETAIL_SM_56}
----------

Moved the VPUJPEG clock ownership to SM. This clock is used by HW MTR when the VPUMIX is powered on and agents cannot be allowed to turn it off. This change must also be made in customer cfg files.

