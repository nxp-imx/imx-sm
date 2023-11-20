Change List {#RN_CL}
===========

The tables below also indicate which patch version, if any, in the previous release (
None) includes the change. Note some of these patches may not have been released yet and
the data could change.

SM 2023Q4 Change List {#RN_P0}
====================================

Below is a list of changes between the previous release (None) and this release (imx_sm_2023q4_er1).

New Feature {#RN_CL_NEW}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) |
|------------|-------------------------------|-------|---|
| [SM-1](https://jira.sw.nxp.com/projects/SCF/issues/SM-1) | Initial development of the SM |   | Y |
| [SM-4](https://jira.sw.nxp.com/projects/SCF/issues/SM-4) | Add support for i.MX95 [[detail]](@ref RN_DETAIL_SM_4) |   | Y |
| [SM-6](https://jira.sw.nxp.com/projects/SCF/issues/SM-6) | Add support for the i.MX95 EVK [[detail]](@ref RN_DETAIL_SM_6) |   | Y |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) |
|------------|-------------------------------|-------|---|
| [SM-25](https://jira.sw.nxp.com/projects/SCF/issues/SM-25) | Configure IP-level PCEe ISO controls based on feature fuses [[detail]](@ref RN_DETAIL_SM_25) |   | Y |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) |
|------------|-------------------------------|-------|---|
| [SM-11](https://jira.sw.nxp.com/projects/SCF/issues/SM-11) | SM 2023Q4 ER1 documentation updates |   | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-4: Add support for i.MX95 {#RN_DETAIL_SM_4}
----------

Added device port for the i.MX95 (MIMX95) and common supporting drivers (MIMX9).

SM-6: Add support for the i.MX95 EVK {#RN_DETAIL_SM_6}
----------

Added the following board ports:
 * i.MX95 EVK (mcimx95evk) - full EVK board port
 * i.MX95 Stub (mci95stub) - board port with no SM use of board components such as I2C bus expanders, PMICs, or GPIO

Added the following configs:
 * i.MX95 EVK (mx95evk) - default for AP+M7
 * i.MX95 Alt (mx95alt) - alternate for AP or M7 used for OS and SDK testing

SM-25: Configure IP-level PCEe ISO controls based on feature fuses {#RN_DETAIL_SM_25}
----------

Modified the i.MX95 boards ports (EVK and stub) to read the PCIe feature fuses and configure the PCIe ISOs accordingly.

