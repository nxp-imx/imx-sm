Debug {#DEBUG}
=====

This section covers various debug topics such as SCMI API error responses, configuration issues, errors
during boot, and debugging reset or suspend issues.

Section Contents
----------------

This section covers or links to the following debug topics:

- [Debug monitor](@ref MONITOR)
- [SCMI error codes](@ref STATUS)
- [Reset/shutdown messages and causes](@ref DEBUG_RESET)
- [Suspend/resume issues](@ref DEBUG_SUSPEND)
- [Debugging SCMI API and peripheral access issues](@ref DEBUG_CONFIG)
- [Errors during boot](@ref DEBUG_BOOT)

Reset Debug {#DEBUG_RESET}
===========

Reset events can occur for the entire system or for a [logical machine (LM)](@ref SYS_ARCH_LM). A system
reset will result in a cold boot of the SoC (some board components may reset) and an LM reset just resets
a specific LM. With a system reset, the SoC/board resets, the ROMs runs again, images are reloaded (inc.
the SM), the SM is run from the start, and LMs are started according to the config. Basically the entire
[bootflow](@ref BOOTFLOW) is rerun. For LM resets, only the requested LM resets (all state is lost) and
the SM continues to execute and any state of the SM is retained.

Information about resets is maintained for two phases: shutdown and boot. These occur as part of a reset but
can also occur separately for different reasons and with a gap in time between them. The information can be
accessed in several ways: output to the debug UART when they happen, output using [monitor](@ref MONITOR)
commands, or read from the SM by agents via the [SCMI API](@ref scmi_proto).

| Reset Type   | Monitor Command  | SCMI API               |
|--------------|------------------|------------------------|
| System Reset | reason           | SCMI_MiscResetReason() |
| LM Reset     | lm [*lm*] reason | SCMI_LmmResetReason()  |

The SCMI API function descriptions describe the info returned. The section below describes what is displayed
when the reset event occurs or when displayed with the monitor command.

Reset Record Output
-------------------

Output of reset information is board port specific as the BRD_SM_ShutdownRecordSave() function is implemented
as part of the [board port](@ref PORT_GUIDE). NXP ports output the message with the following form:

    <reaction>: reason=<reason>, errId=<errId>, srcLm=<origin>
      <extInfo[0]>
      <extInfo[1]>
      ...

The *reaction* could be boot, shutdown, reset, or boot+shutdown depending on the sequence of events.
*Reason* indicates why the event occurred (e.g. ::DEV_SM_REASON_CM33_LOCKUP). The *errId* and *extInfo[]*
are optional syndrome info and depend on the reason. The *srcLm* indicates which LM requested/caused the
event and is optional as some events are hardware initiated.

An example use of the *errId* is to contain the exception number for the ::DEV_SM_REASON_CM33_EXC reason.
Exception numbers are basically the CM33 exception/interrupt index. Negative for exceptions and positive for
fault indicating interrupts. For exceptions, the extended info array, *extInfo[]*, contains the M33 PC,
fault status, and faulting address.

Reset events can cause a reset directly via the reset controller (SRC on i.MX9), via interrupts taken by
the M33 SM, or via the FCCU. Those **directly to the reset controller cannot record any additional
information into non-volatile storage and will be lost if the power supply for the reset controller is
bounced**. Those fielded by the M33 via interrupts or FCCU may have additional info recorded, assuming the
M33 can take the interrupt.

Common reset reasons (for example ::DEV_SM_REASON_CM33_LOCKUP):

| Reason       | Description                      | errId        | extInfo[]                         |
|--------------|----------------------------------|--------------|-----------------------------------|
| cm33_lockup  | CM33 lockup                      |              |                                   |
| cm33_swreq   | CM33 SW request                  |              |                                   |
| cm33_exc     | CM33 exception                   | ex/IRQ       | Varies, see exception table below |
| cm7_lockup   | CM7 lockup                       |              |                                   |
| cm7_swreq    | CM7 SW request                   |              |                                   |
| fccu         | FCCU                             | faultId      | Varies, see fault table below     |
| jtag         | JTAG                             |              |                                   |
| jtag_sw      | JTAG SW                          |              |                                   |
| ele          | ELE                              |              |                                   |
| tempsense    | ANA sensor panic                 |              |                                   |
| wdog1        | WDOG 1                           |              |                                   |
| wdog2        | WDOG 2                           |              |                                   |
| wdog3        | WDOG 3                           |              |                                   |
| wdog4        | WDOG 4                           |              |                                   |
| wdog5        | WDOG 5                           |              |                                   |
| wdog6        | WDOG 6                           |              |                                   |
| wdog7        | WDOG 7                           |              |                                   |
| wdog8        | WDOG 8                           |              |                                   |
| bbm          | BBM boot/shutdown (button, RTC)  | BBM flags    |                                   |
| sw           | SW requested                     | agent        |                                   |
| sm_err       | SM error/exit                    | error status |                                   |
| fusa_sreco   | FuSa error/exit                  | error status |                                   |
| pmic         | PMIC fault                       |              | [15:8]=hfault, [7:0]=fault        |
| por          | Power on reset                   |              |                                   |

Note that once the SM has enabled various interrupts some of the above get recorded as exceptions into
non-volatile storage with additional info. Once the FCCU is configured some of the above become FCCU
faults (e.g. WDOGs) with additional info. Only a small number of FCCU faults are enabled by the non-FuSa
SM. See SoC specific list below. The RM contains a list of all available faults. BBM indicates the action
came from the battery backed module and BBM flags are a bit mask read from the BBM. An example flag
is ::DEV_SM_BBM_BOOT_OFF. Most other status is SM error status codes such as ::SM_ERR_NOT_SUPPORTED.
For the ::DEV_SM_REASON_FCCU reason, *errId* contains an FCCU faultId such as ::DEV_SM_FAULT_TMP_ANA.

Exceptions always results in a reset. Depending on [configuration](@ref FAULT_REACTIONS), faults may
result in nothing, a system reset, system shutdown, LM reset, LM shutdown, or FuSa protocol notification.

i.MX95 Exceptions and Faults:
-----------------------------

If the reset reason is an M33 exception (cm33_exc) and the M33 SM was able to take an interrupt:

|  errId  | Exception Description                  | extInfo[]            |
|---------|----------------------------------------|----------------------|
|  -14    | Non maskable interrupt                 | M33 PC               |
|  -13    | Cortex-M33 SV hard fault interrupt     | M33 PC, HFSR         |
|  -12    | Cortex-M33 memory management interrupt | M33 PC, CFSR, MMFAR  |
|  -11    | Cortex-M33 bus fault interrupt         | M33 PC, CFSR, BFAR   |
|  -10    | Cortex-M33 usage fault interrupt       | M33 PC, CFSR         |
|   31    | Watchdog 1 interrupt                   | M33 PC               |
|   32    | Watchdog 2 interrupt                   | M33 PC               |
|   38    | M7 lockup Error                        |                      |
|   39    | M7 reset request                       |                      |
|  160    | ELE group 1 no clock                   | ELE_RST/IRQ_REQ_STAT |
|  161    | ELE group 2 clock too slow             | ELE_RST/IRQ_REQ_STAT |
|  162    | ELE group 3 fault                      | ELE_RST/IRQ_REQ_STAT |

ELE group resets come from the secure element (ELE). These resets can be due to ELE abort,
glitch/voltage/freq detectors, etc. Some syndrome data is captured but that doesn't differentiate
these causes. Debug of faults with a PC can be done using the map file generated during complilation.

If the reset reason is an FCCU fault (fccu) and the M33 SM was able to take an interrupt:

| errId | Fault Description                          | extInfo[]                |
|-------|--------------------------------------------|--------------------------|
|   0   | Temp sensor over-temperature (ANA)         |                          |
|   1   | Temp sensor over-temperature (CORTEX-A)    |                          |
|   3   | DDR ECC multi-bit error                    |                          |
|  18   | WDOG2 timeout (watchdog reset request)     | M33 PC                   |
|  19   | WDOG3 timeout (watchdog reset request)     |                          |
|  20   | WDOG4 timeout (watchdog reset request)     |                          |
|  21   | WDOG5 timeout (watchdog reset request)     |                          |
| 22-33 | Software generated fault 0-11              |                          |
|  58   | FlexNOC_Main Mission Fault                 | Wakeup Initiator timeout |
|  59   | FlexNOC_Mega Mission Fault                 | Wakeup Initiator timeout |
|  60   | FlexNOC_Central Mission Fault              | NOC Initiator timeout    |
|  61   | AXBS_M33_0 AON domain parity               |                          |
|  62   | AXBS AON domain parity                     |                          |
|  64   | AON parity (non AXBS_M33_0 and AXBS)       |                          |
|  65   | Wakeup domain parity                       |                          |
|  66   | NOC domain parity gaskets                  |                          |
|  67   | Cortex-M7 domain parity                    |                          |
|  68   | DDR domain parity                          |                          |
|  69   | NPU domain parity                          |                          |

These are the faults enabled by default in the non-FuSa SM. See section @ref FCCU_CONFIG for info
on configuring the FCCU. See the SoC RM for a complete list of faults. SW generated faults 0-5
can be generated by the SM directly or via the SCMI FuSa protocol SCMI_FusaFaultSet() function.
The others come from the MCM associated with other CPUs.

i.MX94 Exceptions and Faults:
-----------------------------

If the reset reason is an M33 exception (cm33_exc) and the M33 SM was able to take an interrupt:

|  errId | Exception Description                  | extInfo[]            |
|--------|----------------------------------------|----------------------|
|  -14   | Non maskable interrupt                 | M33 PC               |
|  -13   | Cortex-M33 SV hard fault interrupt     | M33 PC, HFSR         |
|  -12   | Cortex-M33 memory management interrupt | M33 PC, CFSR, MMFAR  |
|  -11   | Cortex-M33 bus fault interrupt         | M33 PC, CFSR, BFAR   |
|  -10   | Cortex-M33 usage fault interrupt       | M33 PC, CFSR         |
|   36   | Watchdog 1 interrupt                   | M33 PC               |
|   37   | Watchdog 2 interrupt                   | M33 PC               |
|   38   | M7 0 lockup Error                      |                      |
|   39   | M7 0 reset request                     |                      |
|   74   | M7 1 lockup Error                      |                      |
|   75   | M7 1 reset request                     |                      |
|   87   | M33S lockup Error                      |                      |
|   88   | M33S reset request                     |                      |
|  303   | ELE group 1 no clock                   | ELE_RST/IRQ_REQ_STAT |
|  304   | ELE group 2 clock too slow             | ELE_RST/IRQ_REQ_STAT |
|  305   | ELE group 3 fault                      | ELE_RST/IRQ_REQ_STAT |

ELE group resets come from the secure element (ELE). These resets can be due to ELE abort,
glitch/voltage/freq detectors, etc. Some syndrome data is captured but that doesn't differentiate
these causes. Debug of faults with a PC can be done using the map file generated during complilation.

If the reset reason is an FCCU fault (fccu) and the M33 SM was able to take an interrupt:

| errId   | Fault Description                          | extInfo[]                |
|---------|--------------------------------------------|--------------------------|
|   0     | Temp sensor over-temperature (ANA)         |                          |
|   1     | Temp sensor over-temperature (CORTEX-A)    |                          |
|   3     | DDR ECC multi-bit error                    |                          |
|  18     | WDOG2 timeout (watchdog reset request)     | M33 PC                   |
|  19     | WDOG3 timeout (watchdog reset request)     |                          |
|  20     | WDOG4 timeout (watchdog reset request)     |                          |
|  21     | WDOG5 timeout (watchdog reset request)     |                          |
| 22-33   | Software generated fault 0-11              |                          |
|  58     | FlexNOC Main Mission Fault                 | Wakeup Initiator timeout |
|  60     | FlexNOC Central Mission Fault              | NOC Initiator timeout    |
|  61     | AXBS_M33_0 AON domain parity               |                          |
|  62     | AXBS AON domain parity                     |                          |
|  64     | AON parity (non AXBS_M33_0 and AXBS)       |                          |
|  65     | Wakeup domain parity                       |                          |
|  66     | NOC domain parity gaskets                  |                          |
|  67     | Cortex-M7 domain parity                    |                          |
|  68     | DDR domain parity                          |                          |
|  69     | NPU domain parity                          |                          |
|  84     | WDOG6 timeout (Watchdog reset request)     |                          |
|  85     | WDOG7 timeout (Watchdog reset request)     |                          |
|  86     | WDOG8 timeout (Watchdog reset request)     |                          |
| 101-112 | Software generated fault 12-23             |                          |

These are the faults enabled by default in the non-FuSa SM. See section @ref FCCU_CONFIG for info
on configuring the FCCU. See the SoC RM for a complete list of faults. SW generated faults 0-5
can be generated by the SM directly or via the SCMI FuSa protocol SCMI_FusaFaultSet() function.
The others come from the MCM associated with other CPUs.

i.MX952 Exceptions and Faults:
------------------------------

If the reset reason is an M33 exception (cm33_exc) and the M33 SM was able to take an interrupt:

|  errId  | Exception Description                  | extInfo[]            |
|---------|----------------------------------------|----------------------|
|  -14    | Non maskable interrupt                 | M33 PC               |
|  -13    | Cortex-M33 SV hard fault interrupt     | M33 PC, HFSR         |
|  -12    | Cortex-M33 memory management interrupt | M33 PC, CFSR, MMFAR  |
|  -11    | Cortex-M33 bus fault interrupt         | M33 PC, CFSR, BFAR   |
|  -10    | Cortex-M33 usage fault interrupt       | M33 PC, CFSR         |
|   31    | Watchdog 1 interrupt                   | M33 PC               |
|   32    | Watchdog 2 interrupt                   | M33 PC               |
|   38    | M7 lockup Error                        |                      |
|   39    | M7 reset request                       |                      |
|  160    | ELE group 1 no clock                   | ELE_RST/IRQ_REQ_STAT |
|  161    | ELE group 2 clock too slow             | ELE_RST/IRQ_REQ_STAT |
|  162    | ELE group 3 fault                      | ELE_RST/IRQ_REQ_STAT |

ELE group resets come from the secure element (ELE). These resets can be due to ELE abort,
glitch/voltage/freq detectors, etc. Some syndrome data is captured but that doesn't differentiate
these causes. Debug of faults with a PC can be done using the map file generated during complilation.

If the reset reason is an FCCU fault (fccu) and the M33 SM was able to take an interrupt:

| errId | Fault Description                          | extInfo[]                |
|-------|--------------------------------------------|--------------------------|
|   0   | Temp sensor over-temperature (ANA)         |                          |
|   1   | Temp sensor over-temperature (CORTEX-A)    |                          |
|   3   | DDR ECC multi-bit error                    |                          |
|  18   | WDOG2 timeout (watchdog reset request)     | M33 PC                   |
|  19   | WDOG3 timeout (watchdog reset request)     |                          |
|  20   | WDOG4 timeout (watchdog reset request)     |                          |
|  21   | WDOG5 timeout (watchdog reset request)     |                          |
| 22-33 | Software generated fault 0-11              |                          |
|  58   | FlexNOC Main Mission Fault                 | Wakeup Initiator timeout |
|  60   | FlexNOC Central Mission Fault              | NOC Initiator timeout    |
|  61   | AXBS_M33_0 AON domain parity               |                          |
|  62   | AXBS AON domain parity                     |                          |
|  64   | AON parity (non AXBS_M33_0 and AXBS)       |                          |
|  65   | Wakeup domain parity                       |                          |
|  66   | NOC domain parity gaskets                  |                          |
|  67   | Cortex-M7 domain parity                    |                          |
|  68   | DDR domain parity                          |                          |
|  69   | NPU domain parity                          |                          |


These are the faults enabled by default in the non-FuSa SM. See section @ref FCCU_CONFIG for info
on configuring the FCCU. See the SoC RM for a complete list of faults. SW generated faults 0-5
can be generated by the SM directly or via the SCMI FuSa protocol SCMI_FusaFaultSet() function.
The others come from the MCM associated with other CPUs.

Example Reset Records
---------------------

**Results from the SM monitor 'reason' command:**

System reset due to ELE group 1 exception:

    Reset: reason=cm33_exc, errId=160
      0x1FFC4A58 <- M33 PC
      0x00200020 <- ELE_RST_REQ_STAT
      0x00000020 <- ELE_IRQ_REQ_STAT

System reset due WDOG2 trigger (M33 SM):

    Reset: reason=fccu, errId=18
      0x1FFD39CA <- M33 PC

System reset request via SCMI API call from LM1 agent 1:

    Reset: reason=sw, errId=1, srcLm=1

System reset due to PMIC thermal alarm:

    Reset: reason=pmic
      0x00000101 <- PF09 hfault/fault flags

System reset due to an FCCU NOCMIX mission fault:

    Reset: reason=fccu, errId=60
      0x00000020 <- NOCMIX Initiator timeout status, cortex-a55 domain (m_e_1b_rd port) read timeout

System powered off and on via the ON/OFF button:

    Boot:     reason=bbm, errId=3

System powered off via SM monitor, powered on via RTC alarm:

    Shutdown: reason=sw, errId=0, srcLm=0
    Boot:     reason=bbm, errId=5

**Results from SM monitor 'lm [lm] reason' command:**

LM1 reset due to WDOG5 timeout:

    Reset: reason=fccu, errId=21

LM2 shutdown requested by LM1. LM2 then booted by request of LM0 (SM)

    Shutdown: reason=sw, errId=1, srcLm=1
    Boot:     reason=sw, errId=0, srcLm=0

Anomalous POR
-------------

The above information can help identify the source of a reset/shutdown based on the reported event. More
challenging is when the reported reset reason is POR but there is no known cause of the POR. This usually
requires that two conditions exist:

- The board design bounces the supply (e.g. VDD_SOC) for the reset controller (e.g. SRC) when the
  WDOG_ANY signal is asserted.
- The SM is in a state where interrupts cannot be taken (hung or looping with interrupts disabled).

If the reset controller supply is bounced, then any reason it might record in hardware is lost. If the SM
is incapable of taking an interrupt then it also cannot record a reason in persistent storage. On reboot,
the SM uses both of these sources of information to report the reset reason and both have to be missing to
get an anomalous POR reason (other than a pure hardware/power supply failure).

The SM debug monitor can be used to disable the WDOG_ANY assertion before the failing use-case is run.

    >$ wdog warm

This will only work if the board is capable of rebooting without asserting WDOG_ANY.

- The boot device may require WDOG_ANY to reset. This can possibly be mitigated by cutting the trace only
  to the PMIC and leaving WDOG_ANY enabled to drive the boot device.
- The boot device may require the power supply bounce to reset. Maybe a transistor can be used to bounce the
  boot device supply pin without bouncing the i.MX power supply. Maybe the problem can be reproduced when
  booted from another boot device that does not require resetting. If the boot fails because the boot device
  is not reset, it may be possible to connect with a JTAG debugger after the reset and read the reset reason
  directly from the reset controller (e.g. SRC).
- The i.MX may require the supply voltages to go back to boot level in order for the i.MX to boot properly.
  This can be mitigated by disabling any function that might lower the primary i.MX voltage (e.g. VDD_SOC)
  before running the failing use-case. DVFS and SM board port BOARD_BOOT_LEVEL settings might have to be
  changed.

Another possible way to debug such an issue is to disable the SM WDOG before running the failing use-case:

    >$ wdog off

This will usually result in the failure just hanging instead of resetting the system. Then a JTAG debugger
can be attached to see where the M33 (running the SM) is stuck. If the JTAG debugger can't attach, it
usually means the M33 is hung instead of looping. A hang can be because of hardware failure or SM bug
causing an access to something not powered, clocked, etc. In this case, the only course of debug is to
incrementally disable SM functionality until the reset behavior changes.

Suspend/Resume Debug {#DEBUG_SUSPEND}
====================

TBD

Configuration Debug {#DEBUG_CONFIG}
===================

This section provides suggestions for debugging configuration issues. Most configuration has to do
with access controls, either permissions for agents to send SCMI API messages or TRDC access rights
for an agent to access the memory address range of a peripheral.

SCMI API Permission Issues
--------------------------

For SCMI API access problems the key to a identifying a configuration issue is for agents to always check
[error responses](@ref STATUS) to SCMI messages/function calls. The only response related to configuration
is ::SCMI_ERR_DENIED. This indicates the configuration does not allow the desired operation on the associated
resource. The required access level for functions can be found in the @ref SCMI_PROTO section. Any other error
response is related to the requested operation and its parameters. The [function description](@ref scmi_proto)
for every SCMI API call documents the possible error responses and what they mean.

In addition to returning an error to the calling agent, the SM logs error responses to API calls. It records
**one** error per agent and will not overwrite this log until cleared. The [debug monitor](@ref MONITOR)
'[err](@ref DEBUG_ERR)' command will display and clear this log. If it does not list any API errors then the
SM did not return one to an agent.

If an API access issue exists, check the configuration of the associated [config_scmi.h](@ref SCMI_CONFIG)
file. This should list the configured permission level for the resource for the agent. If not listed or if the
level isn't sufficient, revisit the configuration given to the [configtool](@ref CONFIGTOOL). When run directly,
the tool can generate a log file that can be used to identify cfg file issues. See the @ref CONFIGURATION
section for more info.

Hardware Access Issues
----------------------

Agent bus errors when accessing peripherals or memory are often related to access control policies configured
in the hardware Resource Domain Controller (RDC). These policies are written to the RDC (TRDC on i.MX9) by
the SM whenever an RDC instance is powered up. This configuration is static and comes from header files
generated from the cfg file by the [configtool](@ref CONFIGTOOL).

The fist step is to identify if the issue is due to an RDC violation. Similar to the API logging above,
the TRDC hardware will log the first occurrence of a returned bus error for each domain ID (DID) for each
TRDC component. The same debug monitor '[err](@ref DEBUG_ERR)' command mentioned above will also list and
clear these for any component powered up. If not listed, then the TRDC was not the cause of the error. Other
causes include not having the component powered up via the [power protocol](@ref scmi_proto_power), lack of
clocks, incorrect address, incorrect MPU/MMU/SMMU configuration, caching, etc.

If the '[err](@ref DEBUG_ERR)' command does show a TRDC access violation, confirm the address is correct. Also
confirm the access type (read/write/execute, secure/non-secure, privileged/user) is correct. Confirm the DID
(aka DOM) is correct. If not then the issue could be a disconnect between the access request and the TRDC config.

The TRDC can be dumped using the debug monitor "trdc" command. The first parameter is the TRDC. The list of
TRDCs can be found in the dev_sm_rdc.c file for the SoC. The optional second parameter is the DID (aka DOM)
and can be used to limit the output scope. For example:

    trdc aon 3

Will dump the TRDC_A config for DID 3. Compare this configuration using the SoC RM to the desired config and the
error presented with the '[err](@ref DEBUG_ERR)' command. If this is incorrect, then check the
[config_trdc.h](@ref TRDC_CONFIG) for correctness. If wrong then debug the cfg file using the configtool log.

If an access causes a client to fault, a message may be output on the SM debug UART. See @ref PORT_NXP_PRINT.

Understanding SM monitor 'err' output {#DEBUG_ERR}
-------------------------------------

As mentioned above, the debug monitor 'err' command will list all the API and Hardware access issues reported
so far, and clear the error log. Only the first error for each agent is logged, until cleared. See below examples
of the "err" command output, and how to interpret them:

* API access issues: *SCMI err (chn=0): protocolId=0x81, messageId=0xA, status=-3*
    - chn=0 identifies the SMT channel used. Channels numbers are assigned in their declaration order in the
      configuration file. chn=0 is the first channel declared. In the `mx95evk.cfg` file, this is the A2P
      channel in the SCMI_AGENT0: the communication channel from M7 to system manager.
    - [protocolId, messageId](@ref SCMI_PROTO) and status identify which SCMI access generated the error.
      As mentioned above, status will always be -3 (ERR_DENIED) if rejected by SM configuration. The protocol
      and message IDs are listed in the include files in the `components/scmi` directory in the SM source tree.
    - The example above will occur when the M7 agent tries to call the BBM_RTC_NOTIFY SCMI RPC.
* Device init error: *DEV init err: 0x00000008*
    - Indicates an error occurred during boot but boot continued. The code is a bit mask of possible
      error conditions. These masks are device specific. For i.MX95 the list is as follows:
      - Bit 0 - BOARD_InitClocks() error
      - Bit 1 - BOARD_InitDebugConsole() error
      - Bit 2 - BOARD_InitTimers() error
      - Bit 3 - BOARD_InitSerialBus() error
* Hardware access issues: *DOM3 ns prv write to 0x2002F914, MBC_A1=1.2, MBC1_DOM3_MEM1_BLK_CFG_W0[2]*
    - DOM3 identifies the domain ID of the LM or processor performing the incorrect access.
      For the `mx95evk.cfg` file, this corresponds to did=3, that is the LM2 (A55 processor).
    - The next part describes the access: here a non-secure privileged write to address 0x2002F914.
    - The last part shows the corresponding TRDC registers (sometimes this is decoded incorrectly).
    - The example above will occur when the A55 tries to do a non-secure write to address 0x2002F914.

Note agents often loop over resources until they get back an error, so API errors don't necessarily indicate
a problem. But since only the first is recorded, it may be necessary to issue an 'err' command before a 
failing operation in order to capture error responses. Agents also sometime probe for hardware which can
result in the TRDC logging access errors. The 'err' command should be used to clear these also before running
a failing use-case under debug.

Boot Debug {#DEBUG_BOOT}
==========

When the SM boots, it records several kinds of info that can be used to debug boot problems:

- If any of the main boot steps fail and return an error code to main(), this will be displayed as a
  standard [SCMI error code](@ref SCMI_STATUS). When these kinds of errors occur, the following steps
  are not executed until the boot flow gets to the monitor. The most common is -9 error
  (::SCMI_ERR_HARDWARE_ERROR) which can be seen if any of the board hardware failed to initialize
  (typically serial devices over I2C).

        Hello from SM (Build 719, Commit 6f9b3d33, Sep 30 2025 12:22:21)

        Init error: -9

        *** SM Debug Monitor ***

        >$

- Boot errors from some board initialization functions will set a bit in the device error word. These
  are errors in functions that don't return a status code. This word can be displayed with the
  '[err](@ref DEBUG_ERR)' command:

        >$ err
        DEV init err: 0x00000004

    The meaning of the bits varies by SoC and board port. See [above](@ref DEBUG_ERR) for an example for
    i.MX95. This word is also part of the syslog that can be displayed with the
  'syslog' command:

        >$ syslog
        Wake vector = 0
        Sys sleep mode = 0
        Sys sleep flags = 0x00000000
        MIX power status = 0x00000000
        MEM power status = 0x00000000
        PLL power status = 0x00000000
        Sleep latency = 0 usec
        Wake latency = 0 usec
        Sleep count = 0
        Device err log = 0x00000004

  This can also retrieved by an agent with the SCMI_MiscSyslog() function.
- When the SM cfg file indicates an LM should boot when the system boots, any error in starting the LM will
  be recorded as LM status. This can be displayed using the 'lm info' command.

        Hello from SM (Build 719, Commit 6f9b3d33, Sep 30 2025 12:29:37)

        Init error: -130

        *** SM Debug Monitor ***

        >$ lm info
        000: SM = on
        001: M7 = off, err = -130
        002: AP = off (default)

  This can also be retrived using the SCMI_LmmAttributes() function. The most common issue is configuring
  an LM to boot but not including an image for that LM in the boot container. Note if the LM has skip=1
  configured for the LM in the cfg file then lack of an image will **not** result in a -130 error
  (::SCMI_ERR_MISSING_PARAMETERS).

