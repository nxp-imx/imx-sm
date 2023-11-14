Implementation Details {#IMPLEMENTATION}
======================

System Manager Structure {#STRUCTURE}
========================

The SM structure contains an upper-level that is hardware independent and a lower-level
that is hardware dependent. The upper-level deals with RPC and logical machine management
and the lower-level abstracts the device (aka SoC) and the board.

Hardware Independent Structure
------------------------------

The figure below shows the logical structure of the hardware independent modules of the SM.
This includes the RPC modules (mailbox, transport, protocol) and the logical machine manager. 
These modules support multiple instances (i.e. configuration/dynamic data) of the function
and the figure shows how these instances interact with each other.

<br>
@image html structure.jpg "SM Structure" width=75%
@image rtf structure.jpg "SM Structure"
@image latex structure.jpg "SM Structure"
<br>

These modules are configured and their instances linked together using configuration data.
This data is constant and defined using header files. See @ref CONFIGURATION for more info
on these structures and how they are constructed. These modules also maintain dynamic data
for each of the instances. Examples include specified power domain state, notification
enablement, etc.

Various IDs used for identifying modules and module istances are as follows:

| Construct        | External Ref           | Internal Ref |
|------------------|------------------------|--------------|
| Mailbox instance | mbType+mbInst          | *various*    |
| SMT channel      | xportType+xportChannel | smtChannel   |
| SCMI channel     | rpcType+rpcChannel     | scmiChannel  |
| SCMI agent       |                        | agentId      |
| SCMI instance    | rpcType+rpcInst        | scmiInst     |
| LM               | lmId                   | lmId         |

### Mailboxes

Mailbox modules connect physical hardware to transport channels. Some provide only doorbells (aka
interrupts) while others may provide a serial communication stream. Mailbox modules support multiple
instances and these instances can support multiple doorbells. There is usually one instance per
hardware module and one channel/doorbell per transport channel.

The SM as delivered supports two mailbox modules. One is for the MU IP and one is for loopback
testing. The @ref MB_MU interfaces the SDK MU driver with transport modules. One instance per
MU. Each MU has four general purpose interrupts and these are used as doorbell interrupts. The
@ref MB_LOOPBACK provides a doorbell between unit tests and the transport for the simulation
build. Both of these only provide a doorbell and do not move data. They are intended to work with
transports that use shared memory for the data transport (e.g. SMT). One requirement imposed by the
SCMI standard is that a mailbox IP (e.g. MU) cannot be shared between multiple users, agents in the
case of SCMI.

### Transports

Transports connect mailboxes to protocols. They are responsible for moving the message payload data.
This is done via shared memory or streamed via a serial protocol. Transports also do any required
data copy and CRC checking of the data. Transports support multiple independent streams of data
called channels. Each channel requires a mailbox doorbell and connects to a protocol channel.

The only transport delivered with the SM is the @ref RPC_SMT. This transport supports multiple
channels, each with a dedicated shared memory buffer. Each channel has 128 bytes of shared memory
and the same buffer is used for transmit and receive.

### Protocols

Protocols are used to parse RPC requests and turn them into calls to the LMM. Multiple protocols
can exist, but [SCMI](@ref RPC_SCMI) is the default supported by the SM. Protocols are bound to
transport channels and logical machines. Protocols may support multiple logical instances. These
have common code but different configuration and dynamic data. A single protocol instance is bound
to an LM but might be bound to multiple transport channels. A channel might be used for API calls
while another channel might be used for asynchronous notifications. Protocols are referenced by
adjacent modules using *rpcType* and *rpcInst*.

The [SCMI](@ref RPC_SCMI) protocol supports multiple instances denoted internally by *scmiInst*.
A single instance can be bound to an LM. SCMI also supports the concept of multiple clients. Examples
include ATF and Linux. Both run on a common core/cluster and are defined as a single LM. They make
use of a single instance of SCMI, but each needs a communication channel with defined access rights
and each has individual state. SCMI calls denotes each of these clients as an agent. These are denoted
using an *agentId*. Configuration and dynamic data are maintained for each agent. Each agent is then
bound to transport channels, usually multiple. State passed to the LM is aggregated across all agents
in the SCMI instance.

The definition of SCMI instances and agents within those instances depends on the desired interaction.
Clients that are in different LMs must be in different RPC instances. Clients that work together,
interact with each other via the protocol, boot together, reboot together, have a common power state,
etc. would typically be in a single RPC instance.

Protocols really only have a few functions to call. For example, the SCMI protocol has the
RPC_SCMI_Init() function to initialize the protocol, RPC_SCMI_Dispatch() to dispatch an incoming
message, RPC_SCMI_Reset() to reset an instance (used when the LM reboots), and RPC_SCMI_Trigger()
to trigger a notification.

### Logical Machines

The @ref LMM manages multiple logical machines (LM). Example logical machines include
the M33 running the SM, or a Cortex-A cluster running Linux. These are denoted using a logical
machine ID (*lmId*). All of the API calls for this module take an *lmId* parameter to indicate which
LM the operation should affect. The operation usually results in state being aggregated across all
LM and passed to the device or board. While not required, most LM are bound to an RPC protocol.
Note an LM can only be bound to one protocol. Binding is done via constant configuration data. The
LMM_PowerStateSet() function is an example of an LMM function.

Hardware Dependent Structure {#DEV_API_STRUCTURE}
----------------------------

The figure below shows the logical structure of the hardware dependent modules of the SM.
This includes the Device/Board SM abstraction layer and the MCUXpresso SDK. These modules support
a single instance (i.e. configuration/dynamic data) of the function. They manage the state of
the system as a whole and have no understanding that the device has been logically divided by
the LMM.

<br>
@image html dev_struct.jpg "Device/Board Structure" width=40%
@image rtf dev_struct.jpg "Device/Board Structure"
@image latex dev_struct.jpg "Device/Board Structure" width=3.5in
<br>

### DEV_SM_API Redirection

The LMM calls the [Device SM abstraction layer API](@ref DEV_SM_API). This will call the DEV_SM or
BRD_SM depending on the definition of the redirect defines (e.g. ::SM_POWERSTATESET). By default,
these point to the DEV_SM layer. The BRD_SM layer can redefine these to point to itself. This is usually
done to add board resources to the lists of resources (power domains, clocks, sensors, voltages, etc.)
managed by the SM. When added these are managed by the LMM and exposed via the RPC just like device
resources. An example is adding the PMIC temp sensor. The ::SM_NUM_SENSOR define is overridden to add the
sensor to the number and associated functions can then also be overridden. For example the
::SM_SENSORREADINGGET define is overridden to point to BRD_SM_SensorReadingGet(). The board functions
then call the DEV_SM layer for device resources and directly handle board resources.

### SM Device/Board Abstraction

There are two SM abstractions to the hardware support code: device (DEV_SM) and board (BRD_SM).

The DEV_SM interface abstracts the MCUXpresso SDK but also provides additional functionality
required by the SM. For example, the DEV_SM_PowerStateSet() function is a simple abstraction of
calls to the SDK functions PWR_MixSoftPowerUp() and PWR_MixSoftPowerDown(). However the
DEV_SM_PowerDomainNameGet() function returns the text names of the domains which is not available
via any SDK call. Note DEV_SM function sometimes call board functions as well. For example,
DEV_SM_PerfLevelSet() calls BRD_SM_SupplyLevelSet() to set the PMIC supply voltage when doing a
DVFS operating point change.

The BRD_SM interface abstracts the MCUXpresso SDK board port. It is primarily used to add
board-level resources by redirecting functions that control resources (power domains, clocks,
sensors) using the DEV_SM_API redirection capability. These functions then usually call board functions
for the new resources and call DEV_SM functions for the device resources. An example of this is
supporting PMIC temperature sensors.

### MCUXpresso SDK

- TODO

Bootflow {#BOOTFLOW}
========

The boot flow starts in main(). This then has the following flow:

- BRD_SM_Init() - to initialize the hardware, usually does something like:
  - BOARD_InitHardware() - initialize the board hardware
  - BRD_SM_SerialDevicesInit() - initialize board serial devices
  - DEV_SM_RomBootCpuGet() - get the mSel value from the boot container
  - DEV_SM_Init() - initialize the device (aka SoC)
- Prints the SM Hello banner
- LMM_Init() - initialize the LM manager
  - Initializes all the LMM cmponents via init functions like LMM_ClockInit()
  - Initializes the RPC interface for each LM via a function like RPC_SCMI_Init()
- LMM_Boot() - starts the LMs as configured
  - Loops over all the LM and optionally starts them depending on the mSel and boot order
  - Call SWI_Trigger() to trigger an interrupt to do the start
- TEST_Config() - called if a unit test is to be run (T=\<test\>)
- TEST() - called if a unit test is to be run (T=\<test\>)
- MONITOR_Cmd() - called if the monitor is included (M=1)
- Loops forever calling WFI to enter a low power state

The mSel value is used to selected from multiple boot configurations. The board code usually gets the
value from the boot container but may also get/modify the mSel from reading GPIO. The mSel can also be
obtained/modified from the FuSa component in some cases. See mSel references in @ref CONFIGURATION.

The LM [configuration data](@ref LMM_CONFIG) has two variables that affect boot: boot and bootskip.
These are arrays with a value per mSel index. The boot variable indicates the boot order 1-n, 0
indicates not to boot. It two LM have the same boot order then they start in LM index order. The
bootSkip parameter indicates if an error starting a CPU should be ignored. When ignored the error
is just recorded in the LM status but the boot process will continue. bootSkip values are 0=error
is fatal and boot process stops (default), 1=skip error and continue with the next LM.

Example Client RPC Flow {#RPC_EXAMPLE}
=======================

The following is an example code flow of an RPC call to the SM. It originates from an MU
interrupt. The request is to power up a power domain via the SCMI POWER_STATE_SET message.

- **MU1_A_IRQHandler()** - shim from the vector table to the associated mailbox handler
  - Just calls MB_MU_Handler()
- **MB_MU_Handler()** - bind function from the MB_MU to the transport
  - Transport channel is identified by the const MB_MU config structure (mb_mu_config_t
    s_mbMuConfig[])
    - *xportType[]* is the RPC type (e.g. ::SM_XPORT_SMT) for each interrupt (aka doorbell)
    - *xportChannel[]* is the channel number within the transport for each interrupt (aka
      doorbell)
  - Reads the MU status via MU_GetStatusFlags() then clears all pending interrupts via
    MU_ClearStatusFlags(); both are SDK driver functions
  - Loops over all pending interrupts and calls the dispatch function for that doorbell;
    for SMT the dispatch function is RPC_SMT_Dispatch()
- **RPC_SMT_Dispatch()** - bind function from SMT to the RPC channel
  - Channel is identified by the const SMT config structure (rpc_smt_chn_config_t s_smtConfig[])
    - *rpcType* is the RPC type (e.g. ::SM_RPC_SCMI)
    - *rpcChannel* is the channel number within the RPC
  - For SCMI this would call RPC_SCMI_Dispatch()
- **RPC_SCMI_Dispatch()** function to dispatch the SCMI request depending on channel type
  - Channel type found in the const SCMI channel config structure (scmi_chn_config_t
    ::g_scmiChannelConfig[])
    - *type* indicates A2P or P2A  (e.g. ::SM_SCMI_CHN_A2P)
  - For a client RPC call (A2P) this calls RPC_SCMI_A2pDispatch()
  - Note for a P2A channel RPC_SCMI_P2aDispatch() will be called (see @ref NOTIFY_EXAMPLE)
- **RPC_SCMI_A2pDispatch()** - function to dispatches the call to the associated SCMI protocol
  - Reads and records caller information into a caller structure (scmi_caller_t)
  - *agentId* from SCMI channel config structure (scmi_chn_config_t ::g_scmiChannelConfig[])
  - *lmId* from the SCMI instance config structure (scmi_config_t ::g_scmiConfig[])
  - Obtains the address of the payload buffer via RPC_SCMI_HdrAddrGet()
  - Calls RPC_SCMI_A2pRx() to make a copy of the payload
    - This calls RPC_SMT_Rx() to read the SMT payload
    - Will return SM_ERR_CRC_ERROR if it fails the CRC check **on the copy**
    - Records the length in the caller info
  - Records the SCMI header (*protocolId*, *messageId*, type, token)
  - Calls RPC_SCMI_A2pSubDispatch() to dispatch to a protocol handler
  - On return calls RPC_SCMI_A2pTx() to send back the result
    - Calls RPC_SMT_Tx() to send back the payload
    - RPC_SMT_Tx() will calculate and append the CRC
- **RPC_SCMI_A2pSubDispatch()** - calls a protocol specific dispatch handler
  - Calls the SCMI protocol-specific dispatch function; for this example that is
    RPC_SCMI_PowerDispatchCommand()
- **RPC_SCMI_PowerDispatchCommand()** - calls the appropriate local parse function based on
  the *messageID* from the header
  - For this example, that would be ParsePowerStateSet()
- **ParsePowerStateSet()** - parses the payload for a POWER_STATE_SET message
  - Calls PowerStateSet() using the parameters passed in the payload
- **PowerStateSet()** - Does the SCMI power state set function
  - Bounds checks the *domainID*
  - Checks the access rights of the caller *agentId* to set this power domain state
  - Checks that async flag is defined as per the ARM SCMI spec
  - Translates the SCMI defined power state to the device specific state
  - Calls PowerStateUpdate() to update the state for this *agentId*
- **PowerStateUpdate()** - saves the agentId-specific state and does aggregation
  - Saves the power state locally; storage is per *agentId*
  - Loop over all agents to find the maximum power state
  - Calls LMM_PowerStateSet() to request the aggregate state for the *lmId*
- **LMM_PowerStateSet()** - aggregates the power state across all LM and calls the
  device/board
  - Bounds checks the *lmId*
  - Records the new state in local per LM storage
  - Aggregates by looping over all LM and finding the maximum power state value
  - Calls the device/board function via the ::SM_POWERSTATESET redirect macro
- **DEV_SM_PowerStateSet()** - sets the specified power domain state
  - Bounds checks the power domain
  - Checks power dependencies uing PWR_MixIsParentPowered() or PWR_MixAnyChildPowered()
  - Calls the SDK function PWR_MixSoftPowerUp() or PWR_MixSoftPowerDown()
- **PWR_MixSoftPowerUp()** - power up a SRC MIX slice

Example Client Notification Flow {#NOTIFY_EXAMPLE}
================================

The following is an example code flow of a notification. It originates from the BBM RTC
alarm interrupt. The purpose is to notify clients that the RTC alarm has occurred.

- **BBNSM_IRQHandler()** - shim from the vector table to the associated device handler
  - Just calls DEV_SM_BbmHandler()
- **DEV_SM_BbmHandler()** - BBM interrupt handler
  - Calls BBNSM_GetStatusFlags() and BBNSM_ClearStatusFlags() to identify and clear the
    BBM events; both are SDK driver functions
  - Calls the LMM to report the event; In the case of an RTC alarm that call is to
    LMM_BbmRtcAlarmEvent()
- **LMM_BbmRtcAlarmEvent()** - report alarm event to the LMM
  - Loops over all LM finding those with an expired RTC alarm; on expiration:
    - Clears the LM-specific alarm enable
    - Calls LMM_RpcNotificationTrigger() to trigger an alarm event for that LM
  - Before returning, calls LMM_BbmRtcAlarmUpdate() to load the next alarm into the
    BBM RTC
- **LMM_RpcNotificationTrigger()** bind function from LMM to the RPC instance
  - Instance is identified by the const LMM config structure (lmm_config_t ::g_lmmConfig[])
    - *rpcType* is the RPC type (e.g. ::SM_RPC_SCMI)
    - *rpcInst* is the instance of the RPC
  - For SCMI this would call RPC_SCMI_Trigger() 
- **RPC_SCMI_Trigger()** - trigger an SCMI notification for an SCMI instance
  - Calls the protocol specific notification function; passes the event and information
    on the protocol and message to be sent
  - For this example, calls RPC_SCMI_BbmDispatchNotification() to report an RTC event
- **RPC_SCMI_BbmDispatchNotification()** - dispatch BBM protocol notification
  - Routes call depending on type of BBM notification (RTC versus button)
  - BbmRtcEvent() for an RTC event (this example) or BbmButtonEvent() for the ON/OFF button
- **BbmRtcEvent()** - dispatch RTC event
  - Extracts kind of RTC event (alarm versus rollover)
  - Loops over all agents; encodes notification via ParseBbmRtcEvent() if that agent has
    requested it
- **ParseBbmRtcEvent()** - encodes BBM RTC event
  - Encodes message into a protocol-defined message structure
  - Enqueues message via RPC_SCMI_P2aTxQ()
- **RPC_SCMI_P2aTxQ()** - enueue message to send on P2A channel
  - Queue maintained per agent
  - Drops request if too big to fit in available queue space; fault report is TBD
  - Generates header and copies message into queue
  - Triggers message dispatch on agent P2A channel via RPC_SCMI_P2aDispatch()
- **RPC_SCMI_P2aDispatch()** - dispatch P2A transmit request
  - Calls RPC_SCMI_ChannelFree() to see if the channel is free to send; if busy returns,
    RPC_SCMI_P2aDispatch() will then get called again when the client rings the doorbell
    on the P2A channel (after they have consumed the existing message and marked free)
  - Gets the transport address via RPC_SCMI_HdrAddrGet()
  - Copies message from queue to transport buffer
  - Requests transport via RPC_SCMI_P2aTx()
- **RPC_SCMI_P2aTx()** - bind function from the RPC to the transport
  - Transport channel is identified by the const SCMI channel config structure (
    scmi_chn_config_t ::g_scmiChannelConfig[])
    - *xportType* is the RPC type (e.g. ::SM_XPORT_SMT) for the channel
    - *xportChannel* is the channel number within the transport
- **RPC_SMT_Tx()** - transmit SMT payload
  - Gets the buffer address via RPC_SMT_SmaGet()
  - Checks if the message will fit in the shared memory area
  - Optionally generates CRC (e.g. calls CRC_Crc32())
  - Requests doorbell interrupt via RPC_SMT_DoorbellRing()
- **RPC_SMT_DoorbellRing()** - bind function from SMT to the mailbox
  - Channel is identified by the const SMT config structure (rpc_smt_chn_config_t s_smtConfig[])
    - *mbType* is the mailbox type (e.g. ::SM_MB_MU)
    - *mbInst* is the instance number within the mailbox
    - *mbDoorbell* is the doorbell to ring within the mailbox instance
  - For MB_MU this would call MB_MU_DoorbellRing()
- **MB_MU_DoorbellRing()** - assert doorbell interrupt for MB_MU instance
  - MU is identified by the const MB_MU config structure (mb_mu_config_t
    s_mbMuConfig[])
    - *mu* specifies the index into the SDK base pointer array as defined by MU_BASE_PTRS 
- **MU_TriggerInterrupts()** - SDK MU driver function to trigger the specified MU interrupt

Example Fault Flow {#FAULT_EXAMPLE}
==================

- TODO

Event Processing {#EVENTS}
================

- TODO
- Interrupt/event list
  - Where are interrupts used and for what purpose?

