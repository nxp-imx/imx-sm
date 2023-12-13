Known Issues {#RN_KN}
============

Below is a list of known outstanding issues in this release (imx_sm_2023q4_er2).

New Feature {#RN_KN_NEW}
============

| Key     | Summary                        | i.MX95<br> (A0) |
|------------|-------------------------------|---|
| [SM-10](https://jira.sw.nxp.com/projects/SM/issues/SM-10) | Add eMCEM driver to support FCCU | Y |
| [SM-21](https://jira.sw.nxp.com/projects/SM/issues/SM-21) | Implement interfaces to FuSa SAF/SCST | Y |
| [SM-26](https://jira.sw.nxp.com/projects/SM/issues/SM-26) | Add support for vendor-defined SCMI system power states | Y |
| [SM-27](https://jira.sw.nxp.com/projects/SM/issues/SM-27) | Add low-power mode entry during SM idle | Y |
| [SM-28](https://jira.sw.nxp.com/projects/SM/issues/SM-28) | Add support for DRAM retention | Y |
| [SM-29](https://jira.sw.nxp.com/projects/SM/issues/SM-29) | Add support for PLL spread spectrum mode | Y |
| [SM-30](https://jira.sw.nxp.com/projects/SM/issues/SM-30) | Support management of peripheral low-power signals (WAIT/DOZE/STOP/QCHAN) | Y |
| [SM-31](https://jira.sw.nxp.com/projects/SM/issues/SM-31) | Create log for SUSPEND entry/exit | Y |
| [SM-32](https://jira.sw.nxp.com/projects/SM/issues/SM-32) | Add fairness/prioritization to SM IRQ/event handling | Y |

Improvement {#RN_KN_IMP}
============

| Key     | Summary                        | i.MX95<br> (A0) |
|------------|-------------------------------|---|
| [SM-13](https://jira.sw.nxp.com/projects/SM/issues/SM-13) | Load FRO trim from fuses and run closed-loop | Y |
| [SM-14](https://jira.sw.nxp.com/projects/SM/issues/SM-14) | Include ELE status in reset record | Y |
| [SM-15](https://jira.sw.nxp.com/projects/SM/issues/SM-15) | Support reporting SCMI notification queue overflow as a fault | Y |
| [SM-16](https://jira.sw.nxp.com/projects/SM/issues/SM-16) | Reset voltages and retention masks on LM reset | Y |
| [SM-17](https://jira.sw.nxp.com/projects/SM/issues/SM-17) | Implement SCMI message sequence checking | Y |
| [SM-19](https://jira.sw.nxp.com/projects/SM/issues/SM-19) | Optimize boot time | Y |
| [SM-23](https://jira.sw.nxp.com/projects/SM/issues/SM-23) | Vet PD and CLK parameters in CPU LP protocol | Y |
| [SM-24](https://jira.sw.nxp.com/projects/SM/issues/SM-24) | Align reset toggle delay with SoC specification | Y |

Bug {#RN_KN_BUG}
============

| Key     | Summary                        | i.MX95<br> (A0) |
|------------|-------------------------------|---|
| [SM-38](https://jira.sw.nxp.com/projects/SM/issues/SM-38) | Round up/nearest not supported for FRACTPLL clock nodes | Y |

Silicon Workaround {#RN_KN_REQ}
============

These are a mix of silicon errata workarounds and recommended usage changes.

| Key     | Summary                        | i.MX95<br> (A0) |
|------------|-------------------------------|---|
| [SM-54](https://jira.sw.nxp.com/projects/SM/issues/SM-54) | Add software workaround for ERR052127 (NOCMIX BLK_CTRL sync) | Y |

