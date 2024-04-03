Porting Guide {#PORT_GUIDE}
=============

The System Manager (SM) has to be ported to specific boards. This is to accommodate the variations in
regulator (PMIC) management and DDR. Also abstracts system-level board devices like SM-owned I2C bus
expanders, RTCs, temp sensors, misc. resets, persistent storage of fault info, etc.

Porting consists of creating a new port for the board and a new configuration that uses the board
port. For most customers, there should be no need to modify any of the other SM files. For those
that require FuSa, modifying other files might negate ISO/IEC pre-certification of the SM.

Section Contents
----------------

- [Overall structure of the board code files](@ref PORT_FILES)
- [Description of NXP reference ports](@ref PORT_NXP)
- [Steps to create a new board port](@ref PORT_CREATE)
- [Porting the client API](@ref PORT_CLIENT)

Board Code Structure {#PORT_FILES}
====================

Board ports exist as [directories](@ref GUIDE_FILES) of code in the *boards* directory. Each board port
is given a unique directory name and this name is referenced in the [configuration](@ref CONFIGURATION)
being compiled.

The board port directory contains two sets of files. One set is the MCUXpresso SDK defined board port
files and the other is the added abstraction and implementation specific to the SM.

The [MCUXpresso SDK files](@ref PORT_MCUX) in a board port directory are as follows:

| File            | Contents                                                                      |
|-----------------|-------------------------------------------------------------------------------|
| [board.h](@ref mcimx95evk/board.h)         | MCUXpresso SDK header for board-specific code      |
| board.c         | MCUXpresso SDK implementation of board-specific code                          |
| [pin_mux.h](@ref mcimx95evk/pin_mux.h)       | MCUXpresso SDK header for pin configuration      |
| pin_mux.c       | MCUXpresso SDK implementation of pin configuration                            |

The [SM files](@ref PORT_SM) in a board port directory are as follows:

| File            | Contents                                                                      |
|-----------------|-------------------------------------------------------------------------------|
| sm/Makefile     | SM Makefile to build the board port                                           |
| sm/brd_sm.dox   | SM doxygen file for the board port                                            |
| [sm/brd_sm.h](@ref mcimx95evk/sm/brd_sm.h) | SM interface (configuration and custom functions) to the board port |
| sm/brd_sm.c     | SM implementation of board-specific code                                      |
| sm/brd_sm_*.*   | Optional SM files for redirection of LMM device calls to the board port       |

MCUXpresso SDK Board Implementation {#PORT_MCUX}
-----------------------------------

These files are defined by the MCUXpresso SDK as abstractions for the SDK drivers and the common SDK
BOARD_InitHardware() initialization function found in hardware_init.c. The functions initialize both
board-specific as well as some SoC device resources.

| Function                 | Files       | Purpose                                                   |
|--------------------------|-------------|-----------------------------------------------------------|
| BOARD_ConfigMPU()        | board.h/c   | Configure the M33 MPU and enable the caches               |
| BOARD_InitClocks()       | board.h/c   | Init clocks (e.g. external input clocks)                  |
| BOARD_GetDebugUart()     | board.h/c   | Get info about the SM debug UART                          |
| BOARD_InitDebugConsole() | board.h/c   | Init the debug UART                                       |
| BOARD_InitHandlers()     | board.h/c   | Init interrupt handlers, enable in NVIC                   |
| BOARD_InitTimers()       | board.h/c   | Init timers (e.g. system counter, M33 systick, RTC, WDOG) |
| BOARD_WdogModeSet()      | board.h/c   | Set the watchdog mode (COLD, IRQ, OFF, etc.)              |
| BOARD_WdogRefresh()      | board.h/c   | Service the watchdog                                      |
| BOARD_InitSerialBus()    | board.h/c   | Init serial buses (e.g. I2C to PMIC, bus expander)        |
| BOARD_InitPins()         | pin_mux.h/c | Config pin muxing and optionally electrical features      |

SM Board Implementation {#PORT_SM}
-----------------------

The SM directory contains a *Makefile* for the entire board port. The makefile defines several paths
as well as the directories and the object files to include. This file should be modified to include
any additional drivers or components (e.g. PMIC) required for the board port.

There is also a *brd_sm.dox* file which defines the board-specific group and provides a description
of the port.

The code files are defined by the SM as abstractions for the entire SM (boot, LMM, DEV_SM, monitor, etc.).
The prototype of all these functions is in brd_sm_api.h and is common across all boards. The
[brd_sm.h](@ref mcimx95evk/sm/brd_sm.h) file includes mostly configuration defines and includes of header
files for redirection functions.

| Function                    | File     | Purpose                                                   |
|-----------------------------|----------|-----------------------------------------------------------|
| BRD_SM_Init()               | brd_sm.c | Board init, calls BOARD_InitHardware() and DEV_SM_Init()  |
| BRD_SM_Exit()               | brd_sm.c | Board exit, calls SM_SYSTEMERROR()/loops for non-prod     |
| BRD_SM_TimerTick()          | brd_sm.c | Board periodic tick, usually services the wdog            |
| BRD_SM_Custom()             | brd_sm.c | Board custom function, only called from the monitor       |
| BRD_SM_FaultReactionGet()   | brd_sm.c | Allow board override of fault reaction                    |
| BRD_SM_CustomFault()        | brd_sm.c | Custom reaction to a fault                                |
| BRD_SM_ResetRecordPrint()   | brd_sm.c | Print a reset record                                      |
| BRD_SM_ShutdownRecordLoad() | brd_sm.c | Load shutdown record from persistent storage              |
| BRD_SM_ShutdownRecordSave() | brd_sm.c | Store shutdown record to persistent storage               |
| BRD_SM_PmicInfoGet()        | brd_sm.c | Get PMIC info, only called from monitor                   |
| BRD_SM_PmicWrite()          | brd_sm.c | Write a PMIC register, only called from monitor           |
| BRD_SM_PmicRead()           | brd_sm.c | Read a PMIC register, only called from monitor            |
| BRD_SM_SupplyModeSet()      | brd_sm.c | Set a SoC voltage mode (ON/OFF)                           |
| BRD_SM_SupplyModeGet()      | brd_sm.c | Get a SoC voltage mode                                    |
| BRD_SM_SupplyLevelSet()     | brd_sm.c | Set a SoC voltage level in microvolts                     |
| BRD_SM_SupplyLevelGet()     | brd_sm.c | Get a SoC voltage level in microvolts                     |

In addition, there are often additional sm/brd_sm_*.* files which support board-defined resources such
as voltages, controls, resets, sensors, clocks, etc. The SM is structured so that all these normally point
to the [DEV_SM](@ref DEV_SM) layer of code but can be redirected to the BRD_SM layer of code. The mapping
is defined in dev_sm_api.h but those defines can be overridden in [brd_sm.h](@ref mcimx95evk/sm/brd_sm.h)
or any header files it includes. The LMM calling structure is as follows (more [info](@ref DEV_API_STRUCTURE)):

<br>
@image html dev_struct.jpg "Device/Board Structure" width=40%
@image rtf dev_struct.jpg "Device/Board Structure"
@image latex dev_struct.jpg "Device/Board Structure" width=3.5in
<br>

For example, the i.MX95 EVK port supports the temp sensor in the PMIC. This is exposed via the standard
SCMI sensor protocol. The sm/dev/dev_sm_sensor_api.h file supports the two temp sensors in the SoC. By
default, in dev_sm_api.h these are directed to the [DEV_SM](@ref DEV_SM) layer as follows (only one example
function shown):

    #ifndef SM_NUM_SENSOR
    /* Redirector (device/board) for the number of sensors */
    #define SM_NUM_SENSOR           DEV_SM_NUM_SENSOR
    #endif

    #ifndef SM_SENSORREADINGGET
    /*! Redirector (device/board) to get a sensor value */
    #define SM_SENSORREADINGGET     DEV_SM_SensorReadingGet
    #endif

The EVK port adds support for the PMIC sensor by implementing most of the same functions in the DEV_SM file
in a board-spefic [brd_sm_sensor.h](@ref mcimx95evk/sm/brd_sm_sensor.h) file included in the build for that
board. That header redirects the LMM function calls to the board implementation as follows:

    #define SM_SENSORNAMEGET       BRD_SM_SensorNameGet       /* Sensor name */
    #define SM_SENSORDESCRIBE      BRD_SM_SensorDescribe      /* Sensor describe */
    #define SM_SENSORREADINGGET    BRD_SM_SensorReadingGet    /* Sensor read */
    #define SM_SENSORTRIPPOINTSET  BRD_SM_SensorTripPointSet  /* Sensor trip point */
    #define SM_SENSORENABLE        BRD_SM_SensorEnable        /* Sensor enable */
    #define SM_SENSORISENABLED     BRD_SM_SensorIsEnabled     /* Sensor status */

    /* Number of board sensors */
    #define BRD_SM_NUM_SENSOR  1U

    /* Total number of sensors */
    #define SM_NUM_SENSOR  (DEV_SM_NUM_SENSOR + BRD_SM_NUM_SENSOR)

The functions in that file check to see if the resource is a device resource and if so call the DEV_SM
function, else they handle the board resources. The implemented functions are then:

| Function                    | File              | Purpose                                          |
|-----------------------------|-------------------|--------------------------------------------------|
| BRD_SM_SensorNameGet()      | brd_sm_sensor.h/c | Get a board sensor name                          |
| BRD_SM_SensorDescribe()     | brd_sm_sensor.h/c | Get a board sensor description                   |
| BRD_SM_SensorReadingGet()   | brd_sm_sensor.h/c | Read a board sensor                              |
| BRD_SM_SensorTripPointSet() | brd_sm_sensor.h/c | Configure a trip point for a board sensor        |
| BRD_SM_SensorEnable()       | brd_sm_sensor.h/c | Enable/disable a board sensor                    |
| BRD_SM_SensorIsEnabled()    | brd_sm_sensor.h/c | Get enable/disable state of a board sensor       |
| BRD_SM_SensorHandler()      | brd_sm_sensor.h/c | Sensor interrupt handler                         |

This same concept can be used to add voltages, controls, resets, clocks, perf domains, RTCs, etc.

NXP Reference Board Ports  {#PORT_NXP}
=========================

The SM release contains the following NXP ports that can be used as source/reference for a new
board port.

| Board Port                       | Description                                                                         |
|----------------------------------|-------------------------------------------------------------------------------------|
| [mcimx95evk](@ref PORT_MX95_EVK) | i.MX95 EVK, PF09/53 PMICs, PCAL6408A bus expander, added controls, voltages, sensor |
| [mcimx95stub](@ref PORT_MX95_SB) | i.MX95 stub, no PMIC or board resources                                             |
| simu                             | Simulated board, no PMIC, added sensor for test, **only for simulation builds**     |

These can have multiple [configurations](@ref CONFIGURATION) linked to them.

NXP i.MX95 EVK  {#PORT_MX95_EVK}
--------------

This port supports i.MX95 on both the LPDDR4X and LPDDR5 EVKs. This board consists of a base board and CPU
daughter card. The board design allocates LPI2C1, GPIO1, and LPUART2 as interfaces to be managed exclusively
by the SM running on the CM33. Connected to LPI2C1 is a PF09 PMIC, 2x PF53 PMICs, and a PCAL6408A I2C bus
expander. The interrupts from these goes to the bus exapnder (along with other wakeup signals) and the
interrupt from the bus expander goes to GPIO1.10. LPUART2 is connected to an FTDI chip to convert to USB
serial.

The port makes use of the following additional drivers: [RGPIO](@ref rgpio), [PF09](@ref pf09),
[PF53](@ref pf53), and [PCAL6408A](@ref pcal6408a). In addition it adds voltage domains, a sensor, and
controls. These are implemented in corresponding [brd_sm_voltage.h/c](@ref mcimx95evk/sm/brd_sm_voltage.h),
[brd_sm_sensor.h/c](@ref mcimx95evk/sm/brd_sm_sensor.h), and
[brd_sm_control.h/c](@ref mcimx95evk/sm/brd_sm_control.h) files. These define redirection macros to route
the LMM function calls for these type of resources to these files. They then append the following resources
to the existing device resources:

| Resource                  | Protocol | Description                      |
|---------------------------|----------|----------------------------------|
| DEV_SM_VOLT_SOC           | Voltage  | i.MX95 VDD_SOC via PF53          |
| DEV_SM_VOLT_ARM           | Voltage  | i.MX95 VDD_ARM via PF53          |
| BRD_SM_VOLT_VDD_GPIO_3P3  | Voltage  | i.MX95 VDD_GPIO_3P3 via PF09 SW1 |
| BRD_SM_VOLT_VDD_ANA_0P8   | Voltage  | i.MX95 VDD_ANA_0P8 via PF09 SW2  |
| BRD_SM_VOLT_VDD_GPIO_1P8  | Voltage  | i.MX95 VDD_GPIO_1P8 via PF09 SW3 |
| BRD_SM_VOLT_VDDQ_DDR      | Voltage  | i.MX95 VDDQ_DDR via PF09 SW4     |
| BRD_SM_VOLT_VDD2_DDR      | Voltage  | i.MX95 VDD2_DDR via PF09 SW5     |
| BRD_SM_VOLT_SD_CARD       | Voltage  | i.MX95 SD_CARD via PF09 LDO1     |
| BRD_SM_VOLT_NVCC_SD2      | Voltage  | i.MX95 NVCC_SD2 via PF09 LDO2    |
| BRD_SM_SENSOR_TEMP_PF09   | Sensor   | PF09 temp sensor                 |
| BRD_SM_SENSOR_TEMP_PF5301 | Sensor   | PF5301 temp sensor               |
| BRD_SM_SENSOR_TEMP_PF5302 | Sensor   | PF5302 temp sensor               |
| BRD_SM_CTRL_SD3_WAKE      | Misc     | SD3 wakeup via PCAL6408A.0       |
| BRD_SM_CTRL_PCIE1_WAKE    | Misc     | PCIE1 wakeup via PCAL6408A.4     |
| BRD_SM_CTRL_BT_WAKE       | Misc     | BT wakeup via PCAL6408A.5        |
| BRD_SM_CTRL_PCIE2_WAKE    | Misc     | PCIE2 wakeup via PCAL6408A.6     |
| BRD_SM_CTRL_BUTTON        | Misc     | SW2 button via PCAL6408A.7       |

Voltages can be enabled/disabled and their level can be read and written. The sensor can be read (limited
discrete temps 110C, 125C, 140C, 155C. Temps below 110F are reported as 105C. A trip point can be used
to generate a notification. The controls can be read and can generate notifications (also generate a wake up)
on state change.

Board interrupt support is implementd in [brd_sm_handlers.h/c](@ref mcimx95evk/sm/brd_sm_handlers.h). This
makes used of GPIO1 signal 10 to get an interrupt from a PCAL6408A. This gets wakeup signals as well as an
interrupt from the PF09.

The BRD_SM_ShutdownRecordLoad() and BRD_SM_ShutdownRecordSave() functions record information in the BBNSM
persistent storage. They makes use of GPR0-3. Access to these should not be granted to other agents in the
configuration files.

The default configuration for this board is [mx95evk](@ref CONFIG_MX95EVK). It defines the following boot
mode select (mSel) options which can be specified using the MSEL=\<mSel\> option with mkimage.

| mSel        | Description                                                                             |
|-------------|-----------------------------------------------------------------------------------------|
| 0 (default) | Boot LM1 (M7) and/or LM2 (AP) if images found in container, no errors if images missing |
| 1           | Boot LM1 (M7), error if no image in container                                           |
| 2           | Boot nothing                                                                            |

NXP i.MX95 Stub  {#PORT_MX95_SB}
---------------

This port provides limited support for i.MX95 on LPDDR4X/LPDDR5 EVKs, and emulation systems. It assumes
no other devices connected via LPI2C or GPIO. It adds no additional board resources to the API. It does
support the device voltages but these are just saved and returned locally. It is useful for board bring-up
and early boot and DDR testing.

| Resource                  | Protocol | Description                      |
|---------------------------|----------|----------------------------------|
| DEV_SM_VOLT_SOC           | Voltage  | Save/return                      |
| DEV_SM_VOLT_ARM           | Voltage  | Save/return                      |

The port makes use of no additional drivers. It adds no additional voltage domains, sensors, or controls.
It does declare redefinition macros to redirect DEV_SM_SystemReset(), DEV_SM_SystemStageReset(), and
DEV_SM_SystemShutdown() to functions that just print a message and loop forever. This is to aid in bring-up
and debug and **should not be copied to a real board port**.

Reset Record Output  {#PORT_NXP_PRINT}
-------------------

Output of reset information is board port specific. For debug reasons, reset/shutdown event information can
be useful to output to the SM debug UART. This is done for two cases, when the event occurs and when recorded
events are displayed via the @ref MONITOR. This info can also be read via the SCMI_MiscResetReason() function.

When the event occurs, a call is made to the board BRD_SM_FaultReactionGet() function to allow the reaction
to be overloaded. This also allows for outputting a message about the event. For NXP ports, this displays
a preamble about the type of event and then calls BRD_SM_ResetRecordPrint(). Types include LM/system reset,
shutdown, board, and FuSa.

The BRD_SM_FaultReactionGet() function and the monitor then call BRD_SM_ResetRecordPrint() to output the
remainder of the message. NXP ports then output the message  with the following form:

    <reaction>: reason=<reason>, errId=<errId>, srcLm=<origin>
      <extInfo[0]>
      <extInfo[1]>
      ...

The *reaction* depends on the resulting reaction (e.g. ::LMM_REACT_SYS_RESET). *Reason* indicates why the
event occurred (e.g. ::DEV_SM_REASON_CM33_LOCKUP). The *errId* and *extInfo[]* are optional and depend on the
reason. The *srcLm* indicates which LM caused the event and is optional as some events are hardware initiated.

An example use of the *errId* is to contain the exception number for the ::DEV_SM_REASON_CM33_EXC reason.
Exception numbers are basically the CM33 exception/interrupt index. Negative for exceptions and positive for
fault indicating interrupts. For exceptions, the extended info array, *extInfo[]*, contains the stack pointer,
fault status, and faulting address.

Common reset reasons (for example ::DEV_SM_REASON_CM33_LOCKUP)

| Reason       | errId      | Description                      |
|--------------|------------|----------------------------------|
| cm33_lockup  |            | CM33 lockup                      |
| cm33_swreq   |            | CM33 SW request                  |
| cm7_lockup   |            | CM7 lockup                       |
| cm7_swreq    |            | CM7 SW request                   |
| fccu         | faultId    | FCCU                             |
| jtag_sw      |            | JTAG SW                          |
| ele          |            | ELE                              |
| tempsense    |            | ANA sensor panic                 |
| wdog1        |            | WDOG 1                           |
| wdog2        |            | WDOG 2                           |
| wdog3        |            | WDOG 3                           |
| wdog4        |            | WDOG 4                           |
| wdog5        |            | WDOG 5                           |
| jtag         |            | JTAG                             |
| cm33_exc     | ex/IRQ     | CM33 exception                   |
| bbm          | BBM flags  | BBM boot/shutdown (button, RTC)  |
| sw           | agent      | SW requested                     |
| sm_err       | status     | SM error/exit                    |
| fusa_sreco   | status     | FuSa error/exit                  |
| por          |            | Power on reset                   |

Note that once the FCCU is configured some of the above become FCCU
faults (e.g. WDOG2). BBM flags is a bit mask. An example flag is
::DEV_SM_BBM_BOOT_OFF. Most other status is SM error codes such as
::SM_ERR_NOT_SUPPORTED.

Typical CM33 exceptions/interrupts (::DEV_SM_REASON_CM33_EXC):

| Exception         | errId | Description                            |
|-------------------|-------|----------------------------------------|
| Non-maskable IRQ  |  -14  | Non Maskable Interrupt                 |
| Hard fault        |  -13  | Cortex-M33 SV Hard Fault Interrupt     |
| Memory management |  -12  | Cortex-M33 Memory Management Interrupt |
| Bus fault         |  -11  | Cortex-M33 Bus Fault Interrupt         |
| Usage fault       |  -10  | Cortex-M33 Usage Fault Interrupt       |
| Secure fault      |   -9  | Cortex-M33 Secure Fault Interrupt      |
| WDOG 1            |   31  | Watchdog 1 Interrupt                   |
| WDOG 2            |   32  | Watchdog 2 Interrupt                   |
| ELE Group 1       |  160  | ELE Group 1 no clock                   |
| ELE Group 2       |  161  | ELE Group 2 clock too slow             |
| ELE Group 3       |  162  | ELE Group 3 fault                      |

For the ELE group exceptions:

    Reset request: reason=cm33_exc, errId=160
      0x1FFC4A58 <- M33 PC
      0x00200020 <- ELE_RST_REQ_STAT
      0x00000020 <- ELE_IRQ_REQ_STAT

For the ::DEV_SM_REASON_FCCU reason, *errId* contains an FCCU faultId
such as ::DEV_SM_FAULT_TMP_ANA. Below is a list of some faults:

| Fault         | errId | Description                                |
|---------------|-------|--------------------------------------------|
| TMPSNS ANA    |   0   | Temp sensor over-temperature (ANA)         |
| TMPSNS A55    |   1   | Temp sensor over-temperature (CORTEX-A)    |
| WDOG 2        |  18   | WDOG2 timeout (Watchdog reset request)     |
| WDOG 3        |  19   | WDOG3 timeout (Watchdog reset request)     |
| WDOG 4        |  20   | WDOG4 timeout (Watchdog reset request)     |
| WDOG 5        |  21   | WDOG5 timeout (Watchdog reset request)     |

For the WDOG2 fault:

    Reset request: reason=fccu, errId=18
      0x1FFD39CA <- M33 PC

See the SoC RM for a complete list of faults.

Creating a New Port  {#PORT_CREATE}
===================

Follow these stesp to create a new SM board port. Note these steps may not be comprehensive for
complex board ports.

-#  Copy an existing board port for the same SoC to a new board name:

        cp -r boards/mcimx95evk boards/mcimx95new

-#  [Create a new config](@ref CONFIGURATION) and modify it to point to the new board:

        cp configs/mx95evk.cfg configs/mx95new.cfg

    Note as additional changes are made to the board port, this config has to be modified to assign any
    new resources/memory required to the SM. Beyond that it must eventually be updated to reflect the
    complete use-case including the LMs for the various cores, all the resource assignments, and fault
    reactions.

-#  Modify the *configs/mx95new.cfg* file to link to the new board:

        MAKE    soc=MIMX95, board=mcimx95new, build=gcc_cross

-#  Modify the new board *sm/Makefile* to update the BOARD definition.

-#  [Compile the SM](@ref GUIDE_COMPILE) to ensure all things have been copied and linked:

        make really-clean && make config=mx95new cfg && make config=mx95new all

   This should still boot and function on the board the source port was written for. Continue to
   check the build throughout the remainder of these steps.

-#  Modify the new *sm/brd_sm.dox* file to:
  - Change the defgroup name to a new group name
  - Update the title
  - Update the brief description
  - Update the detailed description

-#  Search and replace all instances of the group name in the new board files.

-#  Add a the new defgroup name at the end of *sm/brd/brd_sm_api.dox*.

-#  Add the new board directory in the INPUT section of the *sm/doc/common.cfg* file.

-#  [optional] Update the SCMI_SUB_VENDOR string in the new board *sm/brd_sm.h* file.

-#  [Compile the documentation](@ref GUIDE_DOC) and ensure the new board port looks correct in the board
    modules section:

        cd sm/doc; make html; cd ../..

    Open *sm/doc/build/html/index.html* in a browser.

-#  Create any new components required (new PMIC, I2C expanders, etc.) in the top-level *components*
    directory or in a *components* directory within the new board port directory.

-#  Copy in any new drivers from the MCUXpresso SDK. Examples might be an lpspi driver.

-#  Modify the new board *sm/Makefile* to update the INCLUDE, VPATH, and OBJS definitions to remove
    unused components and add any new drivers or components.

-#  Modify the BOARD_InitPins() function in the new *pin_mux.c*. This should initialize any pins needed by
    the SM including those for any LPUART, LPI2C, GPIO, etc.

-#  Modify the functions in the new *board.c*:
  - Defines to configure the SYSTICK, WDOG, handlers, etc.
  - BOARD_InitClocks() - configure external clocks
  - BOARD_GetDebugUart() - return debug UART info
  - BOARD_InitDebugConsole() - init the UART used for SM debug and monitor
  - BOARD_InitHandlers() - enable handlers used by the SM and board code (for example a new GPIO
    interrupt)
  - BOARD_InitTimers() - configure SM timers and watchdogs
  - BOARD_WdogModeSet() - configure watchdog for various modes
  - BOARD_WdogRefresh() - refresh the timeout for the watchdog used by the SM
  - BOARD_InitSerialBus() - init serial interfaces like the LPI2C to the PMIC

-#  Modify the functions in the new *brd_sm.c*:
  - Defines to configure the persistent storage of the shutdown record.
  - BRD_SM_Init() - init all hardware, includes calls to BOARD_InitHardware(), BRD_SM_SerialDevicesInit(),
     and DEV_SM_Init()
  - BRD_SM_Exit() - implement exit behavior (NXP ports loop for debug!)
  - BRD_SM_Custom() - implement behavior to run from the monitor 'custom' command
  - BRD_SM_FaultReactionGet() - implement dynamic override of fault reaction configuration
  - BRD_SM_CustomFault() - implement a custom fault reaction (e.g. reset some CPUs, etc.)
  - BRD_SM_ResetRecordPrint() - modify for any custom reason printing; default [here](@ref PORT_NXP_PRINT)
  - BRD_SM_ShutdownRecordLoad() - load a shutdown record (NSP ports load from BBNSM GPR)
  - BRD_SM_ShutdownRecordSave() - save a shutdown record (NSP ports save to BBNSM GPR)
  - BRD_SM_PmicInfoGet() - call associated PMIC driver(s) to get the device ID (used by the monitor)
  - BRD_SM_PmicWrite() - call associated PMIC driver(s) to write a random register (used by the monitor)
  - BRD_SM_PmicRead() - call associated PMIC driver(s) to read a random register (used by the monitor)
  - BRD_SM_SupplyModeSet() - call associated PMIC driver(s) to enable/disable a PMIC supply to the SoC
  - BRD_SM_SupplyModeGet() - call associated PMIC driver(s) to get the state of a PMIC supply to the SoC
  - BRD_SM_SupplyLevelSet() - call associated PMIC driver(s) to set the voltage of a PMIC supply to the SoC
  - BRD_SM_SupplyLevelGet() - call associated PMIC driver(s) to get the voltage of a PMIC supply to the SoC

  Note the supply functions only apply to SoC supplies. To manage other voltages the board port needs to
  redirect the DEV_SM_Voltage*() functions found in dev_sm_voltage_api.h.

  The BRD_SM_ShutdownRecordLoad() and BRD_SM_ShutdownRecordSave() functions should save/load shutdown
  information in persistent storage. This is often GPR0-3 in the BBNSM. Access to these GPR should not be
  granted to other agents in the cfg file. Using these GPR for other things requires changing the
  implementation of these functions. Note these could save nothing or save only the first word and set
  extLen to 0 on load.

-#  Implement desire redirection functions:
  - Normally done by adding brd_sm_*.h/c files. Some can be copied from other board ports to start.
  - Header file usually started from the associated dev_sm_*_api.h file.
  - Implementation file usually started from the device-specific dev_sm_*.c file.
  - Rename all DEV_SM functions to BRD_SM functions.
  - In the header add redirection defines.
  - Include the header in brd_sm.h before the include of brd_sm_api.h.

  Note most redirection functions will check the resource and if in the range for device resources call
  the DEV_SM function. If beyond that range, will implement the desired behavior for the added board
  resources. In this way, the board code can add board-level resources for almost any protocol. This is
  common for voltages, sensors, and controls.

-#  Modify the new board *sm/Makefile* to update the OBJS definition to add the new redirection file(s).

Porting the Client API  {#PORT_CLIENT}
======================

Clients must make RPC calls to the SM. A [reference API](@ref scmi_proto) is provided that can be ported
to a client SW system such as the MCUXpresso SDK. The following rules determine if the reference is
directly usable:

- If the SCMI API will be fully interrupt driven then the reference implementation is not directly usable.
- If the SCMI API will be used from a super loop where send and receive have to be split then the reference
  implementation is not directly usable.

If not usable then a custom implementation can be made using the info found in the @ref SCMI_PROTO section.

If usable, then the following steps are required to port:

- Copy the *components/scmi*, *components/smt*, and *components/crc* to the code base
- Include these in the compile and header file path
- Include the SDK MU1 driver or modify the SMT component to use a custom driver
- In the client code, call SMT_ChannelConfig() for each channel to configure. For example:


    SMT_ChannelConfig(SCMI_A2P, SCMI_MU, 0, 0);     /* 0: A2P channel */
    SMT_ChannelConfig(SCMI_NOTIFY, SCMI_MU, 1, 0);  /* 1: P2A notification channel */
    SMT_ChannelConfig(SCMI_P2A, SCMI_MU, 3, 0);     /* 2: FuSa notification channel */

In addition, critical section locks may be required depending on usage of the API. These
are implemented by defining in scmi_internal.h the callout defines: SCMI_A2P_LOCK, SCMI_A2P_UNLOCK,
SCMI_P2A_LOCK, SCMI_P2A_UNLOCK.

The following lock guidelines apply:

- If the SCMI API will only be called from single-threaded non-interrupt code then critical sections
  are not required.
- If the above is true and only notification interrupts will call the SCMI API and only call notification
  functions then critical sections are not required.
- If multithreaded SCMI API calls are required then SCMI_A2P_LOCK/UNLOCK need to acquire a per channel lock.
- If non-notification SCMI API calls will be made from notification interrupts then SCMI_A2P_LOCK/UNLOCK
  need to disable/restore the MU or notification interrupt. Recommended to not do this and instead have the
  notification interrupt schedule a task or thread to complete the notification processing.
- If SCMi API calls will be made from non-notification interrupts, then SCMI_A2P_LOCK/UNLOCK need to also
  disable/restore those interrupts. Recommended to not do this and instead have the interrupt schedule a
  task or thread to complete the event processing.
- If SCMI API notification functions will be called from a non-interrupt context then SCMI_P2A_LOCK/UNLOCK
  need to work the same as SCMI_A2P_LOCK/UNLOCK.
- Any SCMI API call that can be made from both an interrupt and non-interrupt contexts will need to have
  the associate lock implementation check the CPU state and not acquire a lock or disable any interrupts
  when called while in an interrupt context.

