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
| [SM-13](https://jira.sw.nxp.com/projects/SM/issues/SM-13) | Load FRO trim from fuses and run closed-loop |   | Y |
| [SM-18](https://jira.sw.nxp.com/projects/SM/issues/SM-18) | Support final SCMI 3.2 spec changes [[detail]](@ref RN_DETAIL_SM_18) |   | Y |
| [SM-22](https://jira.sw.nxp.com/projects/SM/issues/SM-22) | Add PMIC voltage ramp delay |   | Y |
| [SM-36](https://jira.sw.nxp.com/projects/SM/issues/SM-36) | Return lower-case strings for all resource names [[detail]](@ref RN_DETAIL_SM_36) |   | Y |
| [SM-40](https://jira.sw.nxp.com/projects/SM/issues/SM-40) | Add device controls for some AON/WAKE peripherals |   | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) |
|------------|-------------------------------|-------|---|
| [SM-34](https://jira.sw.nxp.com/projects/SM/issues/SM-34) | Cortex-A55 LM reset may leave the GIC in an unusable state |   | Y |
| [SM-41](https://jira.sw.nxp.com/projects/SM/issues/SM-41) | Fix misc. issues with SM configurations |   | Y |
| [SM-43](https://jira.sw.nxp.com/projects/SM/issues/SM-43) | Board MISC control notification broken in the mx95evk board port [[detail]](@ref RN_DETAIL_SM_43) |   | Y |
| [SM-44](https://jira.sw.nxp.com/projects/SM/issues/SM-44) | Returned SCMI perf levels not limited by part speed |   | Y |
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

SM-43: Board MISC control notification broken in the mx95evk board port {#RN_DETAIL_SM_43}
----------

Fixed i.MX95 EVK board code to invert flag state before applying to the i2C bus expander. Customers may need to do the same if they copied the control code from an NXP reference board port.

