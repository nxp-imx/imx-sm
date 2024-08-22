Known Issues {#RN_KN}
============

Below is a list of known outstanding issues in this release (imx_sm_2024q3).

New Feature {#RN_KN_NEW}
============

| Key     | Summary                        | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|---|---|
| [SM-75](https://jira.sw.nxp.com/projects/SM/issues/SM-75) | Support i.MX95 B0 | | |
| [SM-107](https://jira.sw.nxp.com/projects/SM/issues/SM-107) | Support dynamic rate adjust of audio and  video PLLs | Y | Y |
| [SM-141](https://jira.sw.nxp.com/projects/SM/issues/SM-141) | Create configtool mechanism to define BOARD defines | Y | Y |

Improvement {#RN_KN_IMP}
============

| Key     | Summary                        | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|---|---|
| [SM-131](https://jira.sw.nxp.com/projects/SM/issues/SM-131) | Support system run mode | Y | Y |
| [SM-147](https://jira.sw.nxp.com/projects/SM/issues/SM-147) | Manage VDD_ARM supply during system sleep modes | Y | Y |

Bug {#RN_KN_BUG}
============

| Key     | Summary                        | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|---|---|
| [SM-38](https://jira.sw.nxp.com/projects/SM/issues/SM-38) | Round up/nearest not supported for FRACTPLL clock nodes | Y | Y |
| [SM-143](https://jira.sw.nxp.com/projects/SM/issues/SM-143) | Defining the SM LM with any DID other than 2 will fail | Y | Y |

Silicon Workaround {#RN_KN_REQ}
============

These are a mix of silicon errata workarounds and recommended usage changes.

| Key     | Summary                        | i.MX95<br> (A0) | i.MX95<br> (A1) |
|------------|-------------------------------|---|---|
| [SM-155](https://jira.sw.nxp.com/projects/SM/issues/SM-155) | Add system-level mutex to ensure atomic access of GIC WAKER | Y | Y |

