Change List {#RN_CL}
===========

The tables below also indicate which patch version, if any, in the previous release (
imx_sm_2023q4_er1) includes the change. Note some of these patches may not have been released yet and
the data could change.

SM 2023Q4 Change List {#RN_P0}
====================================

Below is a list of changes between the previous release (imx_sm_2023q4_er1) and this release (imx_sm_2023q4_er2).

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) |
|------------|-------------------------------|-------|---|
| [SM-12](https://jira.sw.nxp.com/projects/SM/issues/SM-12) | Load temp sensor trim from fuses and configure panic [[detail]](@ref RN_DETAIL_SM_12) |   | Y |
| [SM-18](https://jira.sw.nxp.com/projects/SM/issues/SM-18) | Support final SCMI 3.2 spec changes [[detail]](@ref RN_DETAIL_SM_18) |   | Y |
| [SM-20](https://jira.sw.nxp.com/projects/SM/issues/SM-20) | Add V2X TRDC MDAC mapping and update configs |   | Y |
| [SM-22](https://jira.sw.nxp.com/projects/SM/issues/SM-22) | Add PMIC voltage ramp delay |   | Y |
| [SM-36](https://jira.sw.nxp.com/projects/SM/issues/SM-36) | Return lower-case strings for all resource names [[detail]](@ref RN_DETAIL_SM_36) |   | Y |
| [SM-40](https://jira.sw.nxp.com/projects/SM/issues/SM-40) | Add device controls for some AON/WAKE peripherals [[detail]](@ref RN_DETAIL_SM_40) |   | Y |
| [SM-50](https://jira.sw.nxp.com/projects/SM/issues/SM-50) | Update configtool names to match latest SoC RM [[detail]](@ref RN_DETAIL_SM_50) |   | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) |
|------------|-------------------------------|-------|---|
| [SM-34](https://jira.sw.nxp.com/projects/SM/issues/SM-34) | Cortex-A55 LM reset may leave the GIC in an unusable state |   | Y |
| [SM-41](https://jira.sw.nxp.com/projects/SM/issues/SM-41) | Fix misc. issues with SM configurations [[detail]](@ref RN_DETAIL_SM_41) |   | Y |
| [SM-43](https://jira.sw.nxp.com/projects/SM/issues/SM-43) | Board MISC control notification broken in the mx95evk board port [[detail]](@ref RN_DETAIL_SM_43) |   | Y |
| [SM-44](https://jira.sw.nxp.com/projects/SM/issues/SM-44) | Returned SCMI perf levels not limited by part speed [[detail]](@ref RN_DETAIL_SM_44) |   | Y |
| [SM-47](https://jira.sw.nxp.com/projects/SM/issues/SM-47) | Reset associated MU modules during CPU stop sequence |   | Y |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) |
|------------|-------------------------------|-------|---|
| [SM-42](https://jira.sw.nxp.com/projects/SM/issues/SM-42) | SM 2023Q4 ER2 documentation updates |   | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-12: Load temp sensor trim from fuses and configure panic {#RN_DETAIL_SM_12}
----------

Use TMPSNS trim from fuses. Enable interrupts. Configure panic based on market segment fusing.

SM-18: Support final SCMI 3.2 spec changes {#RN_DETAIL_SM_18}
----------

Updated the SCMI clock implementation to conform to the final ARM SCMI 3.2 spec. Removed extra clock attributes and added support for the CLOCK_GET_PERMISSIONS message.

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

Note adding these will cause board misc. controls to shift in number. This will require agent code to change the value passed in the misc. control API calls.

SM-41: Fix misc. issues with SM configurations {#RN_DETAIL_SM_41}
----------

Changed cfg files and associated generated headers:

- Move BUTTON access to AP non-secure from AP secure
- Clean-up of some duplicate assignments

SM-43: Board MISC control notification broken in the mx95evk board port {#RN_DETAIL_SM_43}
----------

Fixed i.MX95 EVK board code to invert flag state before applying to the i2C bus expander. Customers may need to do the same if they copied the control code from an NXP reference board port.

SM-44: Returned SCMI perf levels not limited by part speed {#RN_DETAIL_SM_44}
----------

SCMI performance levels for Cortex-A55 are limited based on speed grade fuses.   Only devices with Cortex-A55 speed grade fusing of 2.0 GHz and above will support the super-overdrive performance level for Cortex-A55.

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

