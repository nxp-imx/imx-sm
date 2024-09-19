Change List {#RN_CL}
===========

The tables below also indicate which patch version, if any, in the previous release (
imx_sm_2024q3) includes the change. Note some of these patches may not have been released yet and
the data could change.

SM 2024Q4 Change List {#RN_P0}
====================================

Below is a list of changes between the previous release (imx_sm_2024q3) and this release (imx_sm_2024q4).

New Feature {#RN_CL_NEW}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-107](https://jira.sw.nxp.com/projects/SM/issues/SM-107) | Support dynamic rate adjust of audio and  video PLLs |   | Y | Y |
| [SM-141](https://jira.sw.nxp.com/projects/SM/issues/SM-141) | Create configtool mechanism to define BOARD defines [[detail]](@ref RN_DETAIL_SM_141) |   | Y | Y |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-131](https://jira.sw.nxp.com/projects/SM/issues/SM-131) | Support system run mode |   | Y | Y |
| [SM-145](https://jira.sw.nxp.com/projects/SM/issues/SM-145) | Improve unit test coverage |   | Y | Y |
| [SM-146](https://jira.sw.nxp.com/projects/SM/issues/SM-146) | Add CPU state to monitor cpu.r output |   | Y | Y |
| [SM-147](https://jira.sw.nxp.com/projects/SM/issues/SM-147) | Manage VDD_ARM supply during system sleep modes [[detail]](@ref RN_DETAIL_SM_147) |   | Y | Y |
| [SM-152](https://jira.sw.nxp.com/projects/SM/issues/SM-152) | Misc. FuSa improvements |   | Y | Y |
| [SM-159](https://jira.sw.nxp.com/projects/SM/issues/SM-159) | Relocate where MUs are reset [[detail]](@ref RN_DETAIL_SM_159) |   | Y | Y |
| [SM-161](https://jira.sw.nxp.com/projects/SM/issues/SM-161) | Misc. updates to SM configurations |   | Y | Y |
| [SM-165](https://jira.sw.nxp.com/projects/SM/issues/SM-165) | Support requesting LMM notifications for all LM [[detail]](@ref RN_DETAIL_SM_165) |   | Y | Y |
| [SM-169](https://jira.sw.nxp.com/projects/SM/issues/SM-169) | Optimize system suspend/resume times |   | Y | Y |
| [SM-170](https://jira.sw.nxp.com/projects/SM/issues/SM-170) | Updates to allow the SCMI client to be used on 64-bit agents [[detail]](@ref RN_DETAIL_SM_170) |   | Y | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-38](https://jira.sw.nxp.com/projects/SM/issues/SM-38) | Round up/nearest not supported for FRACTPLL clock nodes |   | Y | Y |
| [SM-163](https://jira.sw.nxp.com/projects/SM/issues/SM-163) | Incorrect group reset/boot handling for skipped LM [[detail]](@ref RN_DETAIL_SM_163) |   | Y | Y |
| [SM-164](https://jira.sw.nxp.com/projects/SM/issues/SM-164) | CCM ROOT configuration limitation |   | Y | Y |

Silicon Workaround {#RN_CL_REQ}
------------

These are a mix of silicon errata workarounds and recommended usage changes.

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-155](https://jira.sw.nxp.com/projects/SM/issues/SM-155) | Add system-level mutex to ensure atomic access of GIC WAKER |   | Y | Y |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-160](https://jira.sw.nxp.com/projects/SM/issues/SM-160) | SM 2024Q4 documentation updates |   | Y | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-141: Create configtool mechanism to define BOARD defines {#RN_DETAIL_SM_141}
----------

New method to set board defines. New BOARD command. For example:

    DEBUG_UART_INSTANCE  2
    PMIC_I2C_BAUDRATE    400000

becomes:

    BOARD               DEBUG_UART_INSTANCE=2
    BOARD               I2C_BAUDRATE=400000

This allows customers to set other BOARD defines used by their board port. 

Customers must make similar changes to their existing UART/I2C configuration commands.

SM-147: Manage VDD_ARM supply during system sleep modes {#RN_DETAIL_SM_147}
----------

i.MX95 EVK board port changed to track and disable VDD_ARM when entering active system sleep modes. This change reduces power consumption but at the expense of suspend and resume times.

SM-159: Relocate where MUs are reset {#RN_DETAIL_SM_159}
----------

Move the MU reset code from the CPU driver to the MU mailbox driver. This driver is called when logical machines are reset.

SM-163: Incorrect group reset/boot handling for skipped LM {#RN_DETAIL_SM_163}
----------

Do not return an error if a LM identified as skippable in the config is reset using the group reset function. Do not return an error if the caller is not one of the LM being reset.

SM-165: Support requesting LMM notifications for all LM {#RN_DETAIL_SM_165}
----------

Passing an lmId of 0 to SCMI_LmmNotify() will apply the setting to all LM the caller has NOTIFY permissions for. This is useful for Cortex-M test code to enable notifications for all LM it can manage.

SM-170: Updates to allow the SCMI client to be used on 64-bit agents {#RN_DETAIL_SM_170}
----------

Changed some integers used for storing pointer to uintptr_t instead of uint32_t.

