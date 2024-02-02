Architecture {#ARCH}
============

Overview
========

System management is the act of controlling all the SoC features critical to it running. This includes
things like power, bus clocking, resets, pin muxing, PMIC, fault handling, etc.

The function of these IP needs to be "shared" but the HW does not support sharing. Access granularity is
the entire IP. Access must be restricted to the SW trusted to do such management. For example, on i.MX9:

- SRC has a single register for resetting any of the mixes.
- Single I2C interface to the PMIC controlling all supplies, watchdog, etc.
- BBNSM has a single programming model covering RTC, system ON/OFF, persistent storage.

The SW environment trusted to do SM is that most critical to the system--the SW/core that is most important
to remain running and not be affected by other SW/cores in the system. This varies depending on use-case.

For some systems, SM is done by the primary OS running on the application core as it is most critical. The
OS is given exclusive access to the critical IP for power, clocking, reset, etc. Some systems move SM to a
hypervisor or TF-A. These systems can include adjunct Cortex-M but these processors are managed by the
Cortex-A. This is common in consumer use-cases.

In systems targeting automotive and industrial use-cases, the primary OS running on the application core is
often least critical. The user Cortex-M has higher criticality. In this case, SM is moved to another always-on
Cortex-M or even a dedicated controller (as was the case with the SCFW on the SCU in i.MX8). This core is often
referred to as the System Control Processor (SCP). This arrangement allows both AP and user Cortex-M to be
independently booted, reset, power managed, and to access shared IP in a controlled way. The SM in this case
must provide an API and communication channels to the various user cores.

In a system with safety SW, the CPU running the safety framework usually has to run SM. This is because safety
is usually the most critical function in the system and the safety function usually needs very low latency
interaction with SM.

This document covers the NXP i.MX System Manager (SM), an application that runs on a dedicated core along with
the FuSa software (optional) to manage the system. On i.MX9, the M33 core in the AON domain is the SCP and runs
the SM. The other cores (e.g. A55, M7) are user cores and communicate with the SM via an SCMI protocol. 

In the NXP SM, the independent "systems" consisting of a collection of cores and IP is called a Logical Machine
(LM). Logical machines can be independently booted, reset, powered off, transitioned to a low power state, wake
due to a wake event, etc. just as if they were independent SoCs.

As a result, the primary SM role is to:

- **Isolate execution of different cores to prevent interference** - this includes having exclusive access
  the RDCs and loading their configuration before starting any other cores
- **Own HW IP critical to the system control processor execution** - this includes the CM33, all power
  management related SoC IP as well as the PMIC, and the FCCU
- **Provide an RPC interface to clients** - this [API](@ref scmi_proto) allows clients to interact with the
  HW they no longer have direct access to
- **Respond to system events (e.g. faults)** - this requires the SM own and program the FCCU; it then provides
  [configurable](@ref CONFIGURATION) reactions for each fault
- **Optionally integrate FuSa** - the CM33 runs safety components and those manage most of the safety IP in the
  always-on domain

Hardware used exclusively by the SM is shown in the @ref PHY_ARCH section.

Key features:

- [Logical machines (LM)](@ref SYS_ARCH_LM)
  - Partition of resources
  - Independent execution lifecycle (boot, reboot, system power state inc. suspend and shutdown)
- RPC
- ARM System Control and Management Interface (SCMI)
- Multiple agents per LM
- Independent comm channel via messaging unit (MU)
- Access control per agent, configuration (API and RDC access policies) are tool-driven and static
- Existing SCMI support in ATF, u-boot, Linux

Note the NXP SM is **optional** on some i.MX. Some i.MX9 systems can be created that have SM done by
another OS on another core and some systems might develop their own SM-type solution for a Cortex-M.
Safety always requires the SM. Some i.MX SoCs with no AP boot ROM require an SM. 

Also note the SM is doing **system** management, not just SoC management. It is responsible for the PMIC
(or a discrete regulator equivalent), board sensors and other board resources such as power domains,
clocks, etc. and the handling of system-level faults.

System View {#SYS_ARCH}
===========

Running system management outside the Cortex-A is an optional feature on i.MX9. When done, SM runs
on the Cortex-M33, aka the System Control Processor (SCP). In this case, the Cortex-M33 is not available
to run customer applications. The SM application runs on the Cotex-M33 bare metal and does not make use of
an RTOS. It isn't shareable (other than with FuSA elements such as SCST and SAF) and additional customer
functionality may interfere with the real-time response of the SM.

The following figure shows the typical usage on i.MX9. Software running on the Cortex-A and Cortex-M7
communicate to the SCP for power management, clock management, etc. Software running on these CPUs no
longer have access to the hardware IP used to control these functions as access is blocked by the TRDC
HW IP. Drivers for these functions are replaced with versions that implement SCMI and the associated
Mailbox (Mb) driver. A [reference implementation of a client side SCMI API](@ref scmi_proto) is part
of the SM code base and used for unit testing. As the SM is optional on some i.MX9, the result can be
two configurations of these software systems, one that manages the system directly and one that manages
it via SCMI.

<br>
@image html system_view.jpg "System View" width=75%
@image rtf system_view.jpg "System View"
@image latex system_view.jpg "System View"
<br>

Independent physical communication channels are used for each software component (defined by SCMI as
an agent) that might have different permissions to manage different aspects of the system. For example, on
the Cortex-A, independent interfaces are provided for TF-A, hypervisor, and each VM. Each of these agents,
as well as the Cortex-M7 agent, only have access rights to manage IP resources and functions for which they
have permission to manage. **Access rights are maintained by the SM per protocol and resource for each agent.**
These access rights are defined in [configuration information header files](@ref CONFIGURATION) and compiled
into the SM binary. These header files can be generated from [configuration tools](@ref CONFIGTOOL).

Note the SCMI supports VMs directly communicating with the SCP. For this reason, each VM will use an SCMI
channel, in addition to the hypervisor, TF-A, and M7. The above figure shows only two VMs but three is also
a common automotive configuration. Usually one VM for instrument cluster, one for IVI, and sometimes one to
act as a headless device driver VM.

Logical Machines (LM)  {#SYS_ARCH_LM}
---------------------

SCMI has no concept of a system being more than one machine. There is only one and a reset or shutdown is
the entire system. Only the entire system can enter a low power state. Only the entire system boots, or
suspends, or wakes, or resets. Watchdogs can only reboot the entire system. The ARM SCMI spec doesn't use
the term machine or processor and instead uses the term system. It doesn't define what the scope of a system
is. It is implied to be all the cores that an SCMI implementation is aware of and has agents on.

For many configurations of i.MX9, there are multiple cores/clusters (e.g. A55 and M7) that need to have
independent life cycles (boot, shutdown, suspend, reset). In that sense these are like VMs. But they aren't
VMs because they don't share a CPU and there is no hypervisor layer to manage the multiple "machines". The
solution to this is to have a unique independent "instance" of SCMI for each "machine" and have all these
presented by the SCP.

The SM adds the concept of logical machines (LMs). These are analogous to VMs and each has its own instance
of SCMI. All normal SCMI calls only apply the LM running the calling agent. That includes boot, shutdown, reset,
suspend, wake, etc. For example, a call to SCMI_SystemPowerStateSet() with power state ::SCMI_SYS_STATE_SHUTDOWN
will shutdown the LM rather than the full SoC. If a caller makes the SCMI base call to get a list of agents it
will only get those on that LM. Each LM is completely isolated from the others. This is mandatory for these to
operate independently.

This introduces a different problem. Some LM need to be able to shutdown or reset the entire SoC. This is
supported in the SM by adding additional vendor defined power states (allowed by SCMI), with restricted access
to the standard ARM SCMI [System Protocol](@ref scmi_proto_sys). In addition, there is a need for some LM to
be able to control and get notifications about other LM. This is supported via an NXP-defined vendor extension
called the [LMM Protocol](@ref scmi_proto_lmm).

SM Logical View {#LOG_ARCH}
===============

This section describes the structure of the SM application. It describes the modules that make up the
application and their relationship to each other. The following figure shows the main modules and some of
the elements that make up those modules. The main modules are the SM Framework, the Safety Framework
(SCST+SAF), MCUXpresso SDK drivers, and [ARM CMSIS](https://arm-software.github.io/CMSIS_5/Core/html/index.html).

<br>
@image html logical_view.jpg "Logical View" width=75%
@image rtf logical_view.jpg "Logical View"
@image latex logical_view.jpg "Logical View"
<br>

Top-level Structure
-------------------

- SoC Abstraction
  - ARM CMSIS; MCUXpresso SDK drivers
  -  SM device API
- Board Module
  - Board porting layer
  - Customized for PMIC, bus expanders, etc.
  - Storage of shutdown/reset information such as fault info
- Logical Machine Manager (LMM)
  - LM system state management
  - Policies to aggregate LM requests
- RPC
  - SCMI, Shared Memory Transport (SMT), MU Mailbox (MB), aggregates agent requests
- Boot
  - Init HW; start LM as configured
- Configuration Data
  - HW, TRDC, boot, SCMI, SMT, MB, fault reactions
- eMCEM (FCCU driver)
  - Used by SM even in non-safety cases to get fault interrupts
- Safety framework and core self tests

SM Framework {#ARCH_FW}
------------

The i.MX9 SM application is implemented using a custom NXP application framework implemented for System
Control Processors (SCP). This SM codebase provides the primary framework used to construct the SM
application. The following figure shows the modules within the framework. 

<br>
@image html module.jpg "SM Framework Modules" width=75%
@image rtf module.jpg "SM Framework Modules"
@image latex module.jpg "SM Framework Modules"
<br>

The framework provides:
- @ref BOOT
  - main() entry point of the SM
  - Configures the underlying device and board
  - Initializes implementation data inc. LMM, SCMI, etc.
  - Boots logical machines
  - Becomes the idle loop, transitions the system to low-power states when idle  
- @ref MONITOR
  - UART-base command line interface for SM debug
- [Configuration Data Module](@ref CONFIGURATION)
  - Header files containing configuration for the boot, mailboxes, transports, protocols, logical machines,
    device (inc. RDC), and board
  - Generated via the [configtool](@ref CONFIGTOOL)
- Remote Procedure Call (RPC) processing to provide server-side communication services. This consists of:
  - [SCMI: System Control and Management Interface](@ref SCMI_PROTO)
    - A protocol implementation based on the [Arm SCMI 3.2 Specification]
      (https://developer.arm.com/documentation/den0056/latest/)
      - [Base Protocol](@ref scmi_proto_base) - implementation info, agent discovery.
      - [Power Protocol](@ref scmi_proto_power) - manage power states of power domains (e.g. MIXs).
      - [System Protocol](@ref scmi_proto_sys) - system shutdown, suspend, and reset, notifications.
      - [Performance Protocol](@ref scmi_proto_perf) - management of DVFS.
      - [Clock Protocol](@ref scmi_proto_clock) - enable/disable and set rate of clocks/PLLs.
      - [Sensor Protocol](@ref scmi_proto_sensor) - Read sensors, configure trip points (e.g. temp).
      - [Reset Protocol](@ref scmi_proto_reset) - control of reset domains.
      - [Voltage Protocol](@ref scmi_proto_voltage) - configuration of voltage levels.
      - [Pin Control Protocol](@ref scmi_proto_pinctrl) - management of pins.
    - NXP vendor extensions:     
      - [LMM Protocol](@ref scmi_proto_lmm) - boot, reboot, power off LMs; notifications.
      - [BBM Protocol](@ref scmi_proto_bbm) - RTC, persistent storage, button; notifications.
      - [CPU Protocol](@ref scmi_proto_cpu) - management of CPUs.
      - [Misc Protocol](@ref scmi_proto_misc) - management of misc. controls and functions.
      - [FuSa Protocol](@ref scmi_proto_fusa) - safety service/notifications (fault/recovery/test
        events, heartbeat monitor).
    - Enhanced to support the concept of instances; configuration and dynamic state information is
      divided into instances to allow different logical machines to each have their own isolated SCMI
      function
    - Note the above protocols manage SoC resources but can be extended in board code to manage board
      resoruces (e.g. PMIC temp sensor, board RTC).
  - @ref RPC_SMT
    - A transport implementation used to convey message data via shared memory; also conforms to the
      Arm SCMI Specification
  -	Mailbox drivers to provide doorbell interrupts from clients
    - @ref MB_MU - provides client doorbells via message unit (MU) 
    - @ref MB_LOOPBACK - provides loopback doorbells for simulation
- @ref LMM
  -	Provides a logical machine management service independent of the RPC
  - Not a component of SCMI; required to subdivide the system into logical constructs that can each
    have a different RPC, power state, and execution lifecycle
  -	Defines each logical machine (LM) including CPUs, initial boot state of all resources such as
    power domains, clocks, etc.
  - Linked to an RPC (e.g. SCMI) instance
  -	Policies for aggregating RPC requests on shared resources to then forward to the device and board
    modules
  -	Aggregates system power state of each LM into an overall system power state
  -	Ability to boot, reset, and power off individual LMs
  - Notification routing back to the protocol used by an LM
  - Reacts to faults as configured
- @ref DEV_SM - device-specific abstraction for the SM:
  -	Provides a device-independent API for the LMM implementation
  -	Implemented to support the specific device and SDK
  -	Supports system, power, performance, reset, clock, sensor, etc. access
  - Receives faults from the eMCEM and reports them to the LMM
- @ref BRD_SM - board-specific abstraction for the SM:
  -	Provides a board-independent API for the LMM implementation
  -	Implemented to support the specific board
  -	Supports voltage, power, performance, clock, sensor, etc. access for board components like PMICs,
    I2C bus expander, RTC, etc.

The basic relationship of these modules is as follows:
- The device module abstracts the SoC and SDK
- The board module abstracts the board; can also add additional power domains, clocks to manage
- The LMM module then divides the system (device+board) into logical machines; these are similar in
  concept to virtual machines; it maintains state for each LM and aggregates that state down to the
  dev/board
- Each LM links to an RPC instance; all of the CPUs and SW elements in an LM use the same RPC instance
- The RPC layer handles protocol processing for an LM; RPC implementations support instances so that
  unrelated LMs can each have an isolated RPC behavior; various LMs could have no RPC or use different
  RPC protocols (e.g. SCMI, AutoSAR)
- Some protocols support multiple clients; SCMI supports this and calls these *agents*; not all protocols
  support multiple clients within an instance; when supported the RPC must also aggregate all the agent
  requests into a single request for an LM
- RPC agents need multiple channels of communication; this is done by mapping them to transport channels;
  SMT is one such transport, note RPC implementations without an agent concept would map the RPC directly
  to a transport
- Transports then map to mailboxes; these provide underlying communicate capability; for SMT the mailbox
  is only used to generate doorbells (aka interrupts) in both directions
- The eMCEM component reports FCCU faults to the SM. The SM provides configurable reactions to all FCCU
  faults. Reactions include reset or shutdown of the system, reset or shutdown of an LM, custom board
  reaction, notification to a safe S-EENV to handle the fault, or do nothing. 
- See @ref STRUCTURE for more information on the structure of the SM and the relationship between
  mailboxes, transports, RPC (protocols, agents), and logical machines.

Client RPC calls consist of the following basic sequence:
  - Mailbox doorbell interrupt
  - Transport parsing
  - Protocol parsing
  - LMM call
  - Device/board call
  - See @ref RPC_EXAMPLE for more info.

Client notifications consist of the following basic sequence:
  - Device/board/SAF calls LMM to request notification
  - LMM routes request to the protocol used by the LM
  - Protocol queues notification message for registered agents
  - Mailbox doorbell interrupt is used to transmit next queued message
  - See @ref NOTIFY_EXAMPLE for more info.

Faults consist of the following basic sequence:
  - FCCU IRQ handler runs and calls eMcem (FCCU) component
  - eMcem calls bound handlers for each fault type
  - eMcem handlers request device fault handling
  - Device fault handler request LMM fault handling
  - LMM fault handler logs fault and applies configured reaction (reset system LM, shutdown system/LM,
    etc.)
  - See @ref FAULT_EXAMPLE for more info.

Safety Framework (SAF)
----------------------

Details on the SAF are beyond the scope of this section. The SAF is encapsulated conditional callouts to
it from the SM. It does not run as a thread or process (no RTOS) and instead operates via interrupts from
safety IP or API calls. It directly interacts with safety IP like the FCCU.

Note the eMCEM component (FCCU driver) is used by the SM even in non-safety cases. This provides interrupts
for all of the fault conditions, many of which are system faults having nothing to do with safety.

MCUXpresso SDK  {#ARCH_SDK}
--------------

The SM implementation makes use of drivers from the NXP MCUXpresso SDK implementation for i.MX9. This SDK
provides low-level drivers for access to the IP commonly used by Cortex-M cores on NXP MCUs, including
those embedded in i.MX. The following table lists the MCUXpresso SDK drivers used by the SM.

- BBNSM
- CACHE
- CLOCK
- CPU
- ELE
- IOMUXC
- LPI2C
- LPUART
- MU1
- PMIC
- POWER
- RESET
- RGPIO
- SUPPLY
- SYSCTR
- SYSTICK
- TMPSNS
- WDOG32

Arm CMSIS
---------

The SM utilizes the [Common Microcontroller Software Interface Standard (CMSIS)]
(https://arm-software.github.io/CMSIS_5/Core/html/index.html) from ARM. This provides an abstraction for
the Cortex-M33. It includes a Cortex-M HAL, exception handling, system initialization, and intrinsic
functions.

Physical Architecture {#PHY_ARCH}
=====================

This section describes the physical architecture of the SM application. The following figure shows all the
hardware elements that the SM configures or makes use of. The TRDC is configured to restrict access to
these IP to the CM33.

<br>
@image html physical_view.jpg "Physical View" width=75%
@image rtf physical_view.jpg "Physical View"
@image latex physical_view.jpg "Physical View"
<br>

The SM application runs on the Cortex-M33 and uses all of the TCM coupled to it. The SM makes use of the
IP blocks shown in the following table. Most are in always-on power domains (AONMIX, ANAMIX, CCMSRCGPC,
BBNSM).

| IP Block           | Mix       | Use                                                  |
|--------------------|-----------|------------------------------------------------------|
| M33P               | AON       | Executes the SM application                          |
| ATU_A              | AON       | Isolate memory translations                          |
| AXBS_AON           | AON       | Configure QoS                                        |
| BLK_CTRL_NS_AON    | AON       | Misc. controls                                       |
| BLK_CTRL_S_AON     | AON       | Misc. controls                                       |
| CMU                | AON       | Safety IP used by SAF                                |
| CRC                | AON       | Safety IP used by SAF                                |
| ELE (MU0)          | AON       | Communication to ELE                                 |
| FCCU               | AON       | Safety IP used by SAF                                |
| GPIO1              | AON       | Arbitrates shared access                             |
| INTM               | AON       | Safety IP used by SAF                                |
| IOMUXC             | AON       | Arbitrate shared access                              |
| IOMUX_GPR          | AON       | Arbitrate shared access                              |
| LPI2C1/2           | AON       | Communicate to PMIC                                  |
| LPUART1/2          | AON       | Debug output                                         |
| MSGINTR1           | AON       | Message interrupts                                   |
| MU1-6              | AON       | Provides communication channels from clients         |
| ROMCP_M33          | AON       | Access to callback functions                         |
| SYSCTR_CTL         | AON       | Configured to provide a timebase to the system       |
| TRDC_A             | AON       | Configures to enforce HW isolation (via ELE)         |
| TSTMR1             | AON       | Arbitrate shared access                              |
| WDOG1              | AON       | Monitors the health of SM application                |
| WDOG2              | AON       | Monitors the health of SM application                |
| CCM                | CCMSRCGPC | Clock management, arbitrate shared access            |
| GPC                | CCMSRCGPC | Power management, arbitrate shared access            |
| PLL Control        | ANA       | Clock management, arbitrate shared access            |
| SRC                | CCMSRCGPC | Reset management, arbitrate shared access            |
| Temp Sensor        | ANA       | Arbitrate shared access                              |
| XTAL OSC Ctrl      | ANA       | Initialization, clock management                     |
| BBNSM              | BBSM      | Arbitrate shared access                              |
| BLK_CTRL_BBSMMIX   | BBSM      | Misc. controls                                       |
| BLK_CTRL_DDRMIX    | DRC       | Misc. controls                                       |
| DRC/PHY/PLL        | DRC       | Configured for shared use, power management          |
| ATU_M              | WAKE      | Configure QoS                                        |
| BLK_CTRL_WAKEUPMIX | WAKE      | Misc. controls                                       |
| DAP                | WAKE      | Debug IP                                             |
| GPV_MAIN           | WAKE      | Configure QoS                                        |
| GPV_MEGA           | WAKE      | Configure QoS                                        |
| TRDC_M             | WAKE      | Configured to enforce HW isolation                   |
| TRDC_W             | WAKE      | Configured to enforce HW isolation                   |
| V2X (MU0 only)     | WAKE      | Communication to V2X                                 |
| BLK_CTRL_NOCMIX    | NOC       | Misc. controls                                       |
| GPV_CENTRAL        | NOC       | Configure QoS                                        |
| TRDC_N             | NOC       | Configures to enforce HW isolation                   |
| GPV_HSIO           | HSIO      | Configure QoS                                        |
| TRDC_H             | HSIO      | Configures to enforce HW isolation                   |
| GPV_VPU            | VPU       | Configure QoS                                        |
| TRDC_V             | VPU       | Configures to enforce HW isolation                   |
| GPV_CAMERA         | CAMERA    | Configure QoS                                        |
| TRDC_C             | CAMERA    | Configures to enforce HW isolation                   |
| GPV_DISPLAY        | DISPLAY   | Configure QoS                                        |
| TRDC_D             | DISPLAY   | Configures to enforce HW isolation                   |
| TRDC_E             | NETC      | Configures to enforce HW isolation                   |
| TRDC_G             | GPU       | Configures to enforce HW isolation                   |
| TEMP_A55           | CA55      | Arbitrate shared access                              |

All the IP in the DRCMIX is owned by the SM. The DDR controller, phy (inc. FW load), and PLL are initially
configured by a DDR initialization firmware called by the M33 ROM. These IP are subsequently managed as
part of power state changes.

There are also IP in many of the other mixes that the SM owns and must configure whenever the mix is
powered up and/or reset:

- The TRDC(s) have to be reloaded. Also, the configuration can change depending on the state of a client
  and if code is being reloaded and authenticated. Configuration occurs via messages to the ELE.
- BLK_CTRL components are shared and exposed via SCMI. They must also be reloaded.
- The NOC GPV is optionally configured when the QoS needs to be changed from the default.

The Cotex-M33 may also be granted access to other IP in order to allow them to be checked by the SAF.
This is configured for specific customer use-cases.

Note the above list is based on i.MX95. Other i.MX9 family members have similar IP (TRDC, GPV, BLK_CTRL,
etc.) for each mix owned exclusively by the SM.

SCFW versus SM {#SCFW_ARCH}
==============

The System Manager (SM) on i.MX9 has a similar function as the system controller firmware (SCFW)
did on i.MX8. Below is a comparison of the API:

|SCFW Services | SCMI Protocols | Comment|
|--------------|----------------|--------|
| Power Management (PM) | Power Domain Management<BR>System Power Management<BR>Performance Domain Management<BR>Clock Management<BR>Reset Domain Management<BR>Voltage Domain Management<BR>Logical Machine Management (LMM)<BR>CPU Management | |
| Misc. | Misc.<BR>Base<BR>Sensor Management | |
| Timer | Battery-Backed Module (BBM) | No virtual wdog, system counter |
| Pad | Pin Control | |
| Security | N/A | Client access to ELE/V2X |
| IRQ (i.e. notifications) | N/A | Embedded in other protocols |

Of particular note, security functions do not go through the SM. Clients are expected to communicate
directly to the ELE/V2X elements.

Licensing
=========

The System Manager application source code is 3-Clause BSD license as it provides flexibility. The
BSD 3-clause license allows customers almost unlimited freedom with the software so long as they include
the BSD copyright and license notice in it (found in Fulltext). Also, it enables interlinking
with different software components like MCUXpresso SDK, TF-A, CMSIS, etc. SM releases require compliance
with the associated EULA.

Note safety components may have a different license and limited source. Safety certification also
limits what aspects of the SM can be modified without voiding the safety certification.

Source Code Release
===================

The System Manager application fully open-source and all source code is made accessible to customers.
The releases are made via NXP public repository by sharing release branches and tags to GitHub.

Note this does not include safety components like SCST and SAF. Also, modification of some SM components
(anything other than the configuration and board code) could affect FuSa pre-certifications.

