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

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) |
|------------|-------------------------------|-------|---|
| [SM-35](https://jira.sw.nxp.com/projects/SCF/issues/SM-35) | Sending SCMI CPU_SLEEP_MODE_SET for the A55 cluster should not impact A55 CPUs   [[detail]](@ref RN_DETAIL_SM_35) |   | Y |
| [SM-39](https://jira.sw.nxp.com/projects/SCF/issues/SM-39) | Allow access to the ISP OCRAM [[detail]](@ref RN_DETAIL_SM_39) |   | Y |

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

SM-35: Sending SCMI CPU_SLEEP_MODE_SET for the A55 cluster should not impact A55 CPUs   {#RN_DETAIL_SM_35}
----------

The implementation of SCMI CPU_SLEEP_MODE_SET was updated such that when called with the CPU ID parameter set to the A55 cluster, only the target sleep mode for the A55 cluster is updated (target sleep mode of the respective A55 CPUs will remain unmodified).

SM-39: Allow access to the ISP OCRAM {#RN_DETAIL_SM_39}
----------

Address space for OCRAM_C is not the system address space. Addresses seems to be modified to a local camera space address before getting to the TRDC MRC. The TRDC MRC config for the OCRAM_C had to be changed to this new address space.

