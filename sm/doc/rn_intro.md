Introduction {#mainpage}
============

This document contains release notes for the i.MX9 System Manager (SM). This includes:

- [Highlights](@ref RN_HIGH)
- [Changes from the previous release](@ref RN_CL)
- [Known issues](@ref RN_KN)
- [Additional info](@ref RN_ADD)

It is **critical** customers review the [Additional Info](@ref RN_ADD) section for changes
required to board ports and agent APIs.

The table below lists the release information:

| Release Info      |                             |
|-------------------|-----------------------------|
| Release name      | #SM_VERSION                 |
| Previous release  | #SM_PREV_VER                |
| Branch            | #SM_BRANCH                  |
| Build number      | #SM_BUILD                   |
| Commit ID         | #SM_COMMIT                  |
| Build date        | #SM_DATE                    |
| Supported devices | #SM_DEVICES, and phantoms   |
| Tested ELE FW     | #SM_ELE_VER                 |
| Tested mkimage    | #MKIMAGE_BRANCH             |
| Tested Linux      | #MKIMAGE_BUILD              |

\htmlonly
<font color="red">\endhtmlonly

This is an engineering release! It is "as is" and not production quality.

\htmlonly
</font>\endhtmlonly

<br>

Highlights {#RN_HIGH}
==========

- Added system suspend/resume support
- Added support for the i.MX95 15x15 EVK
- Misc. improvements and bug fixes

Note these are highlights of the original release. These do not cover changes
in subsequent patch releases.

