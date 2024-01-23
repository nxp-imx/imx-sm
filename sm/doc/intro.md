Introduction {#mainpage}
============

The System Manager (SM) is a low-level system function which runs on a System Control Processor (SCP) to
support isolation and management of power domains, clocks, resets, sensors, pins, etc. on complex application
processors. It often runs on a Cortex-M processor and provides an abstraction to many of the underlying
features of the hardware. The primary purpose of the SM is to allow isolation between software running on
different cores in the SoC. It does this by having exclusive access to critical resources such as those
controlling power, clocks, reset, PMIC, etc. and then providing an RPC interface to those clients. This
allows the SM to provide access control, arbitration, and aggregation policies for those shared critical
resources.

This document covers all the information necessary to understand, maintain, port, and deploy the SM
on supported processors.

The SM implements an interface compliant with the [Arm SCMI 3.2 Specification]
(https://developer.arm.com/documentation/den0056/latest/) with vendor specific extensions. This document
describes both the [client-side](@ref scmi_proto) and [server-side](@ref RPC_SCMI). The client-side is
provided with the SM for unit testing and for reference. Clients like Linux already contain an SCMI
implementation. Others like the MCUXpresso SDK do not and instead integrate the client API delivered
with the SM.

Of critical note, due to the SM abstraction, some hardware described in the SoC RM that is used by the SM is
not directly accessible to other cores. See the [SM Physical View](@ref PHY_ARCH) for more info.

The SM has a debug monitor presented on a debug UART. See the @ref MONITOR section for an overview of the
commands and output (e.g. faults).

Supported Platforms
-------------------

See the @ref PORT_NXP section for a list of supported platforms and devices. Customers can adapt the System
Manager configuration and have it run on their own board, if it features a supported SoC.

Table of Contents
-----------------

- [Getting Started](@ref START)
- [Release Notes](@ref RN_INTRO)
- [Architecture](@ref ARCH)
- [Developer's Guide](@ref DEV_GUIDE)
- [Configuration](@ref CONFIGURATION)
- [Porting Guide](@ref PORT_GUIDE)
- [Platform-side System Control and Management Interface](@ref SCMI_PROTO)
- [Client-side System Control and Management Interface](@ref scmi_proto)
  - ARM-defined Protocols
    - [Base Protocol](@ref scmi_proto_base) - describes the properties of the implementation.
    - [Power Protocol](@ref scmi_proto_power) - management of power states of power domains.
    - [System Protocol](@ref scmi_proto_sys) - self and system shutdown, and reset.
    - [Performance Protocol](@ref scmi_proto_perf) - management of groups of devices or APs that run
      in the same performance (DVFS) domain.
    - [Clock Protocol](@ref scmi_proto_clock) - management of clocks.
    - [Sensor Protocol](@ref scmi_proto_sensor) - management of platform sensors.
    - [Reset Protocol](@ref scmi_proto_reset) - control of reset capable domains in the platform.
    - [Voltage Protocol](@ref scmi_proto_voltage) - management of voltage levels and modes
      of voltage domains.
    - [Pin Control Protocol](@ref scmi_proto_pinctrl) - management of pins.
  - NXP Vendor Extensions
    - [LMM Protocol](@ref scmi_proto_lmm) - management (boot, shutdown, reset) of other logical
      machines.
    - [BBM Protocol](@ref scmi_proto_bbm) - access to the battery-backed module (e.g. RTC).
    - [CPU Protocol](@ref scmi_proto_cpu) - management of CPUs.
    - [Misc Protocol](@ref scmi_proto_misc) - management of misc. controls and functions.
    - [FuSa Protocol](@ref scmi_proto_fusa) - safety services and notifications.

Document List {#DOCS}
=============

The following documents are referenced in this manual:

- [Arm SCMI 3.2 Specification](https://developer.arm.com/documentation/den0056/latest/)
- [Arm PSCI Specification](https://developer.arm.com/documentation/den0022/latest/)
- [ARM CMSIS](https://arm-software.github.io/CMSIS_5/Core/html/index.html)

Terms and Abbreviations {#DEFINITIONS}
=======================

Note many terms are defined by Arm. See section 1.2 and 3 in the [SCMI specification]
(https://developer.arm.com/documentation/den0056/latest/). A few are listed here as
well as additional terms used in the SM not defined by Arm. References are to sections
in the Arm SCMI spec.

| Term         | Meaning |
|--------------|---------|
| agent        | Entity that sends commands to the platform using SCMI. See 4.1.1 |
| channel      | The transport link over which the agent communicates to the platform. See 4.1.1 |
| command      | A message that is sent from an agent to the platform. See 1.2. |
| FCCU         | The Fault Collection and Control Unit - HW IP to collect and manage faults. |
| LM           | [Logical Machine](@ref SYS_ARCH_LM), a partition of the SoC resources that looks like a unique SoC. For example, the AP cluster and all the resources and memory is uses. |
| LMM          | [LM Manager](@ref LMM). Software component that manages logical machines. |
| MB           | Mailbox, an interface to send transport streams or generate doorbells |
| message      | An individual communication from an agent to the platform or from the platform to an agent. See 4.1.1 |
| notification | A message that is sent from the platform to an agent to alert of a change in state. See 1.2. |
| platform     | The set of system components that interpret the SCMI messages and provide the necessary functionality. See 1.2. |
| protocol     | Group of related SCMI functions. See 2. |
| PSCI         | Power State Coordination Interface. See 1.2. |
| resource     | Any component of the hardware platform which can be controlled using SCMI messages. For example, a power domain is a resource. See 3. |
| SAF          | Safety Application Framework. |
| SCMI         | [System Control and Management Interface](@ref RPC_SCMI). See 1.2. |
| SCP          | System Control Processor. For example, the AON Cortex-M33 in i.MX9. See 1.2. |
| SM           | System manager, an implementation of the platform that runs on an SCP. |
| SMT          | [Shared Memory Transport](@ref RPC_SMT). See 5.1. |
| transport    | A mechanism to communicate messages between agents and the platform. See 2. |

