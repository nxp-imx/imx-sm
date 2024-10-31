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
| [SM-107](https://jira.sw.nxp.com/projects/SM/issues/SM-107) | Support dynamic rate adjust of audio and  video PLLs [[detail]](@ref RN_DETAIL_SM_107) |   | Y | Y |

Improvement {#RN_CL_IMP}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-141](https://jira.sw.nxp.com/projects/SM/issues/SM-141) | Create configtool mechanism to define BOARD defines [[detail]](@ref RN_DETAIL_SM_141) |   | Y | Y |
| [SM-145](https://jira.sw.nxp.com/projects/SM/issues/SM-145) | Improve unit test coverage [[detail]](@ref RN_DETAIL_SM_145) |   | Y | Y |
| [SM-147](https://jira.sw.nxp.com/projects/SM/issues/SM-147) | Manage VDD_ARM supply during system sleep modes [[detail]](@ref RN_DETAIL_SM_147) |   | Y | Y |
| [SM-152](https://jira.sw.nxp.com/projects/SM/issues/SM-152) | Misc. FuSa improvements [[detail]](@ref RN_DETAIL_SM_152) |   | Y | Y |
| [SM-159](https://jira.sw.nxp.com/projects/SM/issues/SM-159) | Relocate where MUs are reset [[detail]](@ref RN_DETAIL_SM_159) |   | Y | Y |
| [SM-161](https://jira.sw.nxp.com/projects/SM/issues/SM-161) | Misc. updates to SM configurations [[detail]](@ref RN_DETAIL_SM_161) |   | Y | Y |
| [SM-165](https://jira.sw.nxp.com/projects/SM/issues/SM-165) | Support requesting LMM notifications for all LM [[detail]](@ref RN_DETAIL_SM_165) |   | Y | Y |
| [SM-169](https://jira.sw.nxp.com/projects/SM/issues/SM-169) | Optimize system suspend/resume times [[detail]](@ref RN_DETAIL_SM_169) |   | Y | Y |
| [SM-170](https://jira.sw.nxp.com/projects/SM/issues/SM-170) | Updates to allow the SCMI client to be used on 64-bit agents [[detail]](@ref RN_DETAIL_SM_170) |   | Y | Y |
| [SM-173](https://jira.sw.nxp.com/projects/SM/issues/SM-173) | Return PMIC faults as reset reason [[detail]](@ref RN_DETAIL_SM_173) |   | Y | Y |
| [SM-174](https://jira.sw.nxp.com/projects/SM/issues/SM-174) | Misc. coding standard fixes |   | Y | Y |
| [SM-177](https://jira.sw.nxp.com/projects/SM/issues/SM-177) | Update ELE dump format [[detail]](@ref RN_DETAIL_SM_177) |   | Y | Y |

Bug {#RN_CL_BUG}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-38](https://jira.sw.nxp.com/projects/SM/issues/SM-38) | Unimplemented rounding rules for clock sources should return error code [[detail]](@ref RN_DETAIL_SM_38) |   | Y | Y |
| [SM-163](https://jira.sw.nxp.com/projects/SM/issues/SM-163) | Incorrect group reset/boot handling for skipped LM [[detail]](@ref RN_DETAIL_SM_163) |   | Y | Y |
| [SM-175](https://jira.sw.nxp.com/projects/SM/issues/SM-175) | Missing LPSPI4 daisy links in device config file [[detail]](@ref RN_DETAIL_SM_175) |   | Y | Y |
| [SM-179](https://jira.sw.nxp.com/projects/SM/issues/SM-179) | Configtool incorrectly assigns non-agent resources to previous agent [[detail]](@ref RN_DETAIL_SM_179) |   | Y | Y |
| [SM-180](https://jira.sw.nxp.com/projects/SM/issues/SM-180) | mx95evksof configuration has bad include path for device.cfg |   | Y | Y |
| [SM-181](https://jira.sw.nxp.com/projects/SM/issues/SM-181) | ELE requires CPU reset handshake enabled for CPU stop/start [[detail]](@ref RN_DETAIL_SM_181) |   | Y | Y |
| [SM-185](https://jira.sw.nxp.com/projects/SM/issues/SM-185) | Avoid implicit activation of PLL nodes during rate set operations [[detail]](@ref RN_DETAIL_SM_185) |   | Y | Y |

Silicon Workaround {#RN_CL_REQ}
------------

These are a mix of silicon errata workarounds and recommended usage changes.

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-155](https://jira.sw.nxp.com/projects/SM/issues/SM-155) | Add system-level mutex to ensure atomic access of GIC WAKER [[detail]](@ref RN_DETAIL_SM_155) |   | Y | Y |
| [SM-176](https://jira.sw.nxp.com/projects/SM/issues/SM-176) | Implement workarounds for PF09 ER011/12 errata  [[detail]](@ref RN_DETAIL_SM_176) |   | Y | Y |

Documentation {#RN_CL_DOC}
------------

| Key     | Summary                        | Patch | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|-------|---|---|
| [SM-160](https://jira.sw.nxp.com/projects/SM/issues/SM-160) | SM 2024Q4 documentation updates |   | Y | Y |

Details {#CL_DETAIL}
=======

This section provides details for select changes.

SM-38: Unimplemented rounding rules for clock sources should return error code {#RN_DETAIL_SM_38}
----------

SM does not support overclocking of CCM clock sources (e.g. PLL clock nodes).  If an agent requests to set the rate of a CCM clock source with a round-auto rule, SM will treat this rule as round-down and will not return an error.  If an agent requests to set the rate of a CCM clock source with a round-up rule, SM will return an error if the calculated rate is not equal to the requested rate (i.e. the CCM clock node can be configured to the exact rate requested).

SM was also updated to the nearest Hz for PLL output (ODIV) and PFD clock nodes.  This prevents the agent from needing to add 1 Hz in cases where the rate ends in a fractional 1/3 or 2/3 thus causing SM to round down during integer rate calculations.

SM-107: Support dynamic rate adjust of audio and  video PLLs {#RN_DETAIL_SM_107}
----------

Support for dynamic MFN update of fractional PLLs has been added.  An agent request to set the rate of a VCO clock node that is currently enabled will dynamically update the VCO rate if the rate change can be achieved with an MFN-only update.

Note that SM "centers" the MFI and MFN VCO factors to allow for the greatest range of dynamic updates.  This centering occurs in the following cases:
 * VCO rate set with the VCO disabled
 * VCO rate set with VCO enabled and new rate cannot be met dynamically

SM only restricts the dynamic MFN update based on the MFN/MFD ratio restrictions provided in the RM. 

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

SM-145: Improve unit test coverage {#RN_DETAIL_SM_145}
----------

Changes made to increase test coverage and add support for automated test code coverage metrics.

SM-147: Manage VDD_ARM supply during system sleep modes {#RN_DETAIL_SM_147}
----------

i.MX95 EVK board port changed to track and disable VDD_ARM when entering active system sleep modes. This change reduces power consumption but at the expense of suspend and resume times.

SM-152: Misc. FuSa improvements {#RN_DETAIL_SM_152}
----------

Misc. FuSa changes:

- Added configtool error checking to ensure LM0 is for SM and has DID=2
- Added preemption check
- Updated FuSa API permissions
- Fixed test failure due to buffer free in wrong place
- Removed unused fault functions, moved test, improved CPU check


SM-155: Add system-level mutex to ensure atomic access of GIC WAKER {#RN_DETAIL_SM_155}
----------

During non-cooperative reset of A55, SM uses the GIC WAKER interface to quiesce the GIC.  There is no hardware method to hold off the A55 from taking the GIC out of quiescence during the reset sequence.  A system-level software mutex in shared MU memory has been added to ensure SM has atomic access to the GIC WAKER.  This atomic access relies on the A55 agent to block on the same system-level mutex implemented in shared MU memory.

Location of the semaphore is defined in the cfg file using the sema option on the Cortex-A platform resource. Customer must make the same change.

SM-159: Relocate where MUs are reset {#RN_DETAIL_SM_159}
----------

Move the MU reset code from the CPU driver to the MU mailbox driver. This driver is called when logical machines are reset.

SM-161: Misc. updates to SM configurations {#RN_DETAIL_SM_161}
----------

Many misc. updates to the cfg files and generated header files:

- Lots of cleanup (sort items, full 36-bit memory addresses, move some resources/APIs to correct section)
- Moved 256K of OCRAM to secure for ATF
- Moved MSGINTR1 to the M7
- Removed AP access to M7 TCM
- Removed A55 ROM
- Added missing clocks used by the SM (LM0)
- Added new clock resources (CLOCK_EXT, CLOCK_DISP1PIX, etc.)
- Gave AP rights to set PCA2131 alarm
- Fixed incorrect reference to msel=2 (should be 1)
- Reduced ELE DDR range
- Added configinfo to dump a cfg file in an md table format
- Added permission defines to cfg files to better support configinfo
- Updated all API sections to use permission defines
- Updated ELE section of cfg files to use memory defines
- Updated V2X section to use owner defines
- Disabled CRC for M7 SMT channels in the mx95alt.cfg file


SM-163: Incorrect group reset/boot handling for skipped LM {#RN_DETAIL_SM_163}
----------

Do not return an error if a LM identified as skippable in the config is reset using the group reset function. Do not return an error if the caller is not one of the LM being reset.

SM-165: Support requesting LMM notifications for all LM {#RN_DETAIL_SM_165}
----------

Passing an lmId of 0 to SCMI_LmmNotify() will apply the setting to all LM the caller has NOTIFY permissions for. This is useful for Cortex-M test code to enable notifications for all LM it can manage.

SM-169: Optimize system suspend/resume times {#RN_DETAIL_SM_169}
----------

Added support for the board port to specify how long the PMIC resume should take. A new BOARD_PMIC_RESUME_TICKS parameter is used in board.h. This should be set based on how long it takes the PMIC(s) to exit standby and resume the voltages.

SM-170: Updates to allow the SCMI client to be used on 64-bit agents {#RN_DETAIL_SM_170}
----------

Changed some integers used for storing pointer to uintptr_t instead of uint32_t.

SM-173: Return PMIC faults as reset reason {#RN_DETAIL_SM_173}
----------

Added functions to the PF09 driver to read and clear the fault status registers. Modified the NXP EVK board ports to read and clear the fault status at boot and use the status to provide a PMIC reset reason.

SM-175: Missing LPSPI4 daisy links in device config file {#RN_DETAIL_SM_175}
----------

The LPSPI4_PCS daisy references were missing for the LPSPI4 resource. Customers will need to rebuild their config.

SM-176: Implement workarounds for PF09 ER011/12 errata  {#RN_DETAIL_SM_176}
----------

- Change the sequence of the LDO3 to the last slot in the pier up sequence (slot 29 in BA1)
- Set the LDO3 OV bypass, UV bypass to 1 and the PG_EN = 0 to make sure the LDO3 does not have any impact in terms of fault counting and asserting the PGOOD pin.
- Set the OV_DBNC = 01 (50us debounce) to prevent the false OV detection described in the errata from generating flags and asserting the PGOOD pin each time an LDO is enabled or when transitioning from STBY to RUN.

Customers may require the same changes depending on OTP and board design.

SM-177: Update ELE dump format {#RN_DETAIL_SM_177}
----------

Updated format to support ELE debug tools. Service WDOG during dump.

SM-179: Configtool incorrectly assigns non-agent resources to previous agent {#RN_DETAIL_SM_179}
----------

The configtool did not correctly support resource assignments outside of the scope of an agent but within the scope of an LM. The resource API permissions would get assigned to the last agent of the previous LM. The hardware access rights did get correctly assigned. With this fix, the API permissions will go unassigned as expected.

SM-181: ELE requires CPU reset handshake enabled for CPU stop/start {#RN_DETAIL_SM_181}
----------

The ELE requires CPU reset/power ELE handshakes to be enabled during a CPU stop operation to prevent a subsequent CPU start from failing (ELE will not release CPUWAIT).  The code supporting CPU stop/start operations has been updated to keep ELE handshakes for CPU reset/power events enabled during these operations.

SM-185: Avoid implicit activation of PLL nodes during rate set operations {#RN_DETAIL_SM_185}
----------

The SM device layer for the clock management protocol was implicitly activating PLL clock nodes during CLOCK_RATE_SET commands.  Implicitly activating these PLL nodes can cause issues during the reboot/reset of agents.  The clock management device layer has been updated to remove implicit activation of PLL clock nodes during CLOCK_RATE_SET commands.

