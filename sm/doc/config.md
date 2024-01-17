Configuration {#CONFIGURATION}
=============

The configuration of the system manager is **static** and driven from header files. It must be
ported to a specific board, but even for a single board, multiple configurations are often
required. For example, a single board might have a Linux configuration that is different from
an Android configuration as logical machines, RPC/transport binding, and RPC API permissions
could vary.

This is accomplished with a collection of configuration data structures filled from header
file defines. The header files are collected into a configuration directory and specified
using the CONFIG= option at compile time. The resulting directory is configs/\<CONFIG\>. It's
best to use the [configtool](@ref CONFIGTOOL) to generate this data. Alternatively, copy
an existing config and modify. See @ref CONFIG_STRUCT for a diagram showing how the
structures are linked.

The configuration directory contains the following files:

| Configuration Item | Configuration File                        |
|--------------------|-------------------------------------------|
| Configtool         | [configtool.cfg](@ref CONFIGTOOL)         |
| Make Includes      | [config.mak](@ref MAKE_CONFIG)            |
| MU Mailbox         | [config_mb_mu.h](@ref MB_MU_CONFIG)       |
| Loopback Mailbox   | [config_mb_loopback.h](@ref MB_LB_CONFIG) |
| SMT                | [config_smt.h](@ref SMT_CONFIG)           |
| SCMI               | [config_scmi.h](@ref SCMI_CONFIG)         |
| LMM                | [config_lmm.h](@ref LMM_CONFIG)           |
| Board              | [config_board.h](@ref BOARD_CONFIG)       |
| Device (SoC)       | [config_dev.h](@ref DEV_CONFIG)           |
| Block Control      | [config_bctrl.h](@ref BCTRL_CONFIG)       |
| TRDC               | [config_trdc.h](@ref TRDC_CONFIG)         |
| Unit Tests         | [config_test.h](@ref TEST_CONFIG)         |
| Doxygen            | [config.dox](@ref DOX_CONFIG)             |

Each of these files is associated with an [SM module](@ref ARCH_FW).

Note when configuring the SM LM0 is always the SM itself. Many resources need to be
exclusively owned by the SM. The @ref PHY_ARCH section lists which IP the SM uses. Some
additional resources such as most bus clocks, AON/WAKE/NOC power domains, etc. are also
used by the SM. Some (e.g. BBNSM GPR0-3, I2C1 or 2, UART 1 or 2, GPIO1, etc.) are often
used by [NXP reference board ports](@ref PORT_MX95_EVK).

SM Configuration Structure {#CONFIG_STRUCT}
--------------------------

The configuration files contain initialization data for a set of interlinked configuration
structures and arrays of structures. The relationship between the configuration structures
is shown in the following diagram. Some of the configuration items bind the mailboxes to
transport (SMT) to RPC (SCMI) to a logical machine (LM). The LM then sits on top of the
board port and device (SoC). Any parameter not specified in a configuration will be
assigned to 0. As a result 0 is used to indicate the detault state for each parameter.

<br>
@image html cfg_struct.jpg "SM Configuration Structure" width=100%
@image rtf cfg_struct.jpg "SM Configuration Structure"
@image latex cfg_struct.jpg "SM Configuration Structure"
<br>

Configuration Files {#CONFIG_FILES}
===================

The following sections detail what is in each configuration file.

Make {#MAKE_CONFIG}
----

- **File:** config.mak

This makefile is included when the SM is compiled. It usually defines make variables and
includes other makefiles. For example:

    include ./devices/MIMX95/sm/Makefile
    include ./boards/mcimx95evk/sm/Makefile
    include ./sm/lmm/Makefile
    include ./sm/rpc/mb_mu/Makefile
    include ./sm/rpc/scmi/Makefile
    include ./sm/rpc/smt/Makefile
    include ./sm/makefiles/gcc_cross.mak

The above includes support for the i.MX95 device, the i.MX95 EVK board,
and modules for the LMM, MU MB, SCMI, and SMT. It also includes the GCC
cross-compile toolchain info (targets, flags, warnings, libraries, linker control
files, etc.).

MU Mailbox {#MB_MU_CONFIG}
----------------

- **File:** [config_mb_mu.h](@ref configs/mx95evk/config_mb_mu.h)
- **Structures:** mb_mu_config_t

Configures the MU mailbox module. The defines in this file are as follows:

- **SM_MB_MUn_CONFIG** - fills a single mb_mu_config_t structure for an MU mailbox
  - *mu* - Index to MU SDK driver, see MU_BASE_PTRS
  - *sma* - Shared memory address, undefined (0) indicates the MU SRAM
  - *xportType[]* - array of transport types, one per doorbell of the MB
  - *xportChannel[]* - array of transport channels, one per doorbell of the MB
- **SM_NUM_MB_MU** - number of MU mailboxes
- **SM_MB_MU_CONFIG_DATA** - fills in the s_mbMuConfig array of mb_mu_config_t
  structures, one per mailbox

This primarily binds an MU to a transport. The *mu* value is an index into the MCUXpresso
SDK MU_BASE_ADDRS array. The SM_MB_MUn_CONFIG define name must use the same *mu* number as
the *n* in the define name. The *sma* value is the base address of the transport memory.
This is specified here as on i.MX9 the buffer is embedded in the MU IP. The *xportType*
and *xportChannel* values link an MU doorbell to a transport channel. For example, a
type of ::SM_XPORT_SMT and channel of 2.

MUs have four possible doorbells (one per general-purpose interrupt). Usually two
doorbells are used for SCMI communication, the first for the A2P channel and the
second for the P2A notification channel.

Loopback Mailbox {#MB_LB_CONFIG}
----------------

- **File:** [config_mb_loopback.h](@ref configs/simu/config_mb_loopback.h)
- **Structures:** mb_lb_config_t

Configures the loopback mailbox module. The defines in this file are as follows:

- **SM_MB_LOOPBACKn_CONFIG** - fills a single mb_lb_config_t structure for a
  loopback mailbox
  - *xportType[]* - array of transport types, one per doorbell of the MB
  - *xportChannel[]* - array of transport channels, one per doorbell of the MB
- **SM_NUM_MB_LOOPBACK** - number of loopback mailboxes
- **SM_MB_LOOPBACK_CONFIG_DATA** - fills in the s_mbLbConfig array of mb_lb_config_t
  structures, one per mailbox

This primarily binds a loopback mailbox to a transport. This loopback mechanism is used
in simulation builds to allow unit tests to make SCMI RPC calls. The *xportType* and
*xportChannel* values link a doorbell to a transport channel. For example, a
type of ::SM_XPORT_SMT and channel of 2.

SMT {#SMT_CONFIG}
----------------

- **File:** [config_smt.h](@ref configs/mx95evk/config_smt.h)
- **Structures:** rpc_smt_chn_config_t

Configures the shared memory transport (SMT). The defines in this file are as follows:

- **SM_SMT_CHNn_CONFIG** - fills a single rpc_smt_chn_config_t structure for an
  SMT channel
  - *rpcType* - RPC type to link, for example ::SM_RPC_SCMI
  - *rpcChannel* - RPC channel to link
  - *mbType* - mailbox type to link, for example ::SM_MB_MU
  - *mbInst* - mailbox instance to link
  - *mbDoorbell* - mailbox doorbell to link
  - *crc* - CRC algorithm to use for this channel, for example ::SM_SMT_CRC_CRC32
- **SM_NUM_SMT_CHN** - number of SMT channels
- **SM_SMT_CHN_CONFIG_DATA** - fills in the s_smtConfig array of rpc_smt_chn_config_t
  structures, one per SMT channel
- **USES_MB_MU** - if defined, includes the MB MU code in the build
- **USES_MB_LOOPBACK** - if defined, includes the MB LB code in the build
- **USES_CRC_XOR** - if defined, includes the XOR CRC code in the build
- **USES_CRC_J1850** - if defined, includes the J1850 CRC code in the build
- **USES_CRC_CRC32** - if defined, includes the CRC32 code in the build

This primarily binds an SMT transport channel to an RPC channel and a mailbox
instance+doorbell. There can be multiple SMT channels per mailbox instance so long
as there is only one per doorbell. Usually there are two SMT channels per RPC agent,
the first for the A2P channel and the second for the P2A notification channel.

SCMI {#SCMI_CONFIG}
----------------

- **File:** [config_scmi.h](@ref configs/mx95evk/config_scmi.h)
- **Structures:** scmi_chn_config_t, scmi_agnt_config_t, scmi_config_t

Configures the SCMI RPC. The defines in this file are as follows:

- **SM_SCMI_AGNTn_CONFIG** - fills a single scmi_agnt_config_t structure for an
  SCMI agent
  - *name* - agent name
  - *domId* - RDC domain ID (DID)
  - *secure* - security state, 1=secure, 0=not secure
  - *scmiInst* - SCMI instance this agent belongs to
  - *basePerms[]* - array of base protocol permissions, one per agent, device
  - *pdPerms[]* - array of power protocol permissions, one per power domain
  - *sysPerms* - system protocol permission
  - *perfPerms[]* - array of perf protocol permissions, one per performance domain
  - *clkPerms[]* - array of clock protocol permissions, one per clock
  - *sensorPerms[]* - array of sensor protocol permissions, one per sensor
  - *rstPerms[]* -array of reset protocol permissions, one per reset domain
  - *voltPerms[]* - array of voltage protocol permissions, one per voltage domain
  - *lmmPerms[]* - array of LMM protocol permissions, one per LM
  - *gprPerms[]* - array of BBM protocol GPR permissions, one per GPR
  - *rtcPerms[]* - array of BBM protocol RTC permissions, one per RTC
  - *buttonPerms[]* - array of BBM protocol button permissions, one per button
  - *cpuPerms[]* - array of CPU protocol permissions, one per CPU
  - *perlpiPerms[]* - array of CPU protocol permissions, one per peripheral
  - *pinPerms[]* - array of pin control protocol permissions, one per pin
  - *daisyPerms[]* - array of pin control protocol daisy permissions, one per daisy register
  - *ctrlPerms[]* - array of control protocol permissions, one per control
  - *faultPerms[]* - array of FuSa protocol fault permissions, one per fault
  - *crcPerms[]* - array of FuSa protocol CRC permissions, one per CRC channel
  - *fusaPerms* - FuSa protocol permission (F-EENV)
- **SM_SCMI_CHNn_CONFIG** - fills a single scmi_chn_config_t structure
  - *agentId* - agent this channel linked with
  - *type* - type of SCMI channel, for example ::SM_SCMI_CHN_A2P
  - *xportType* - transport type to link, for example ::SM_XPORT_SMT
  - *xportChannel* - transport channel to link
- **SM_SCMIn_CONFIG** - fills a single scmi_config_t structure
  - *lmId* - ID of logical machine linked to this SCMI instance
  - *numAgents* - number of agents in this SCMI instance
  - *firstAgent* - first agent in agent array associated with this SCMI instance
- **SM_SCMI_NUM_AGNT** - total number of SCMI agents
- **SM_SCMI_AGNT_CONFIG_DATA** - fills in the ::g_scmiAgentConfig array of
  scmi_agnt_config_t structures, one per SCMI agent
- **SM_SCMI_NUM_CHN** - total number of SCMI channels
- **SM_SCMI_CHN_CONFIG_DATA** - fills in the ::g_scmiChannelConfig array of
  scmi_chn_config_t structures, one per SCMI channel
- **SM_NUM_SCMI** - total number of SCMI instances
- **SM_SCMI_CONFIG_DATA** - fills in the ::g_scmiConfig array of scmi_config_t
  structures, one per SCMI instance
- **SM_SCMI_MAX_NOTIFY** - size of notifications buffer (in words) per agent

Permission arrays are normally one element per protocol resource (e.g. SCMI protocol
power domain). All use a consistent set of permissions values. These are defined as
follows:

- ::SM_SCMI_PERM_NONE - no access (default)
- ::SM_SCMI_PERM_GET - allow to read
- ::SM_SCMI_PERM_NOTIFY - allow to request notifications
- ::SM_SCMI_PERM_SET - allow to set (setting per agent, aggregated across agents
  and LM)
- ::SM_SCMI_PERM_PRIV - privileged access (one setting per LM, aggregated across LM)
- ::SM_SCMI_PERM_EXCLUSIVE - exclusive access (one setting for the entire system)
- ::SM_SCMI_PERM_ALL - full access

The permissions are accumulative (aka hierarchical) and higher permissions imply the
lower ones. The ::SM_SCMI_PERM_ALL permissions is currently equivalent to
::SM_SCMI_PERM_EXCLUSIVE.

Note the configtool and SM implementation do not prevent violating the isolation by
giving multiple agents access where aggregation does not occur. It then becomes the
client's responsibility to manage access exclusivity. This is sometimes acceptable
because of temporal division (maybe during boot or via an explicit software handoff).

For those API calls that require ::SM_SCMI_PERM_SET, the SCMI layer will aggregate
all the agents for an LM and the LMM will aggregate all LM. So every agent can
potentially call and the SM will ensure the HW is in a viable state. For example, a
clock will be on if any agent needs the clock on. It is turned off only if all have
it off. So SCMI_ClockConfigSet() requires SET.

For those that require ::SM_SCMI_PERM_PRIV, the SCMI layer does not aggregate but the
LMM does. So one agent in each LM can make a call (if more than one do then they are
overwriting each other) but each LM has a unique state and the LMM will aggregate. So
if two agents in an LM are given this right to the same resource then some mechanism
outside of the SM is required to ensure isolation.

For those that require ::SM_SCMI_PERM_EXCLUSIVE, no aggregation is done. If two agents
(regardless of LM) make calls they will be overwriting each other. This is the case for
setting the RTC time via SCMI_BbmRtcTimeSet() for example. Even more difficult to ensure
they don't interfere but still useful for some use-cases. Handing a display over from
one LM to another for example.

The permission level required (default none) for messages can be found in the
[SCMI Protocol](@ref SCMI_PROTO) message list (see the Access Control column).

LMM {#LMM_CONFIG}
----------------

- **File:** [config_lmm.h](@ref configs/mx95evk/config_lmm.h)
- **Structures:** lmm_config_t

Configures the [logical machine](@ref SYS_ARCH_LM) manager. The defines in this file are
as follows:

- **SM_LMn_CONFIG** - fills a single lmm_config_t structure for an LM
  - *name* - LM name
  - *rpcType* - RPC type to link, for example ::SM_RPC_SCMI
  - *rpcInst* - RPC instance to link
  - *safeType* - safety classification, 0=NS-EENV, 1=F-EENV, 2=S-EENV
  - *boot[]* - Array of boot order of LM (0=no boot, else 1, 2, 3, ...) per mSel
  - *bootSkip[]* - Array of allow boot skip if no image (1=skip, def=0) per mSel
  - *rtime* - boot time of LM in uS, relative to start of LM boot loop
  - *start* - index into start array + 1, 0 = none
  - *stop* -  index into stop array + 1, 0 = none
- **SM_NUM_LM** - total number of LM
- **SM_LM_CONFIG_DATA** - fills in the ::g_lmmConfig array of lmm_config_t
  structures, one per LM
- **SM_LM_DEFAULT** - default LM used by the debug monitor
- **SM_LM_NUM_START** - total number of start array entries
- **SM_LM_START_DATA** - fills in the s_lmmStart array of lmm_start_t
  structures, one per start item
  - *lmId* - associated logical machine (LM)
  - *mSel* - mode select tor start command
  - *ss* - start/stop command (see table below)
  - *rsrc* - resource command should apply to
  - *numArg* - number of arguments
  - *arg* - array of 64-bit arguments
- **SM_LM_NUM_STOP** - total number of stop array entries
- **SM_LM_STOP_DATA** - fills in the s_lmmStop array of lmm_stop_t
  structures, one per stop item
  - *lmId* - associated logical machine (LM)
  - *mSel* - mode select tor stop command
  - *ss* - start/stop command (see table below)
  - *rsrc* - resource command should apply to
- **SM_LM_FAULT_DATA** - fills in the s_lmmfault array of lmm_fault_t
  - *reaction* - fault reaction
  - *lm* - associated logical machine (LM)

The boot value will determine if the LM will be booted when the SM boots. The
value indicates if it should not (0=no) or the order (1, 2, 3, ...) if it should.
If not, it can be booted later using LMM_Boot() or via SCMI using SCMI_LmmBoot().
If bootSkip != 0 then skip an error due to no image in the boot container.

The rtime value is the relative time the LM should boot in microseconds (max 178
seconds). The time is relative to the time the SM starts to boot LMs. It is useful to
delay the start of an AP core to give RT cores a change to boot and make many calls to
the SM. For example, in an automotive use case, rtime for the M7 LM running a CAN stack
would be 0 and the rtime for the AP LM could be 50000 (50ms). This keeps the AP boot\
from competing with the RT core boot and the SM calls it makes to do startup configuration.

The start and stop values index into the start and stop arrays. These arrays contain
start and stop commands to be executed when an LM is booted or shutdown. Commands
are executed in order until the end of the array or another LM item is encountered.

Start/stop commands supported are:

| Command        | Start                            | Stop                     |
|----------------|----------------------------------|--------------------------|
| ::LMM_SS_PD    | Power on power domain            | Power off power domain   |
| ::LMM_SS_PERF  | Set perf level to arg[0]         | Set perf level to arg[0] | 
| ::LMM_SS_CLK   | Set clock parent to arg[0], rate to arg[1] and enable | Disable clock |
| ::LMM_SS_CPU   | Start CPU                        | Stop CPU                 |

Note for ::LMM_SS_CLK the arguments are optional. With none, the clock will just
be enabled. Any argument less than the ::SM_NUM_CLOCK will also be set as the parent
and any larger set as the rate.

Fault reactions supported are:

| Reaction                   | Start                            |
|----------------------------|----------------------------------|
| ::LMM_REACT_SYS_RESET      | Reset the system                 |
| ::LMM_REACT_SYS_SHUTDOWN   | Shutdown (power off) the system  |
| ::LMM_REACT_LM_RESET       | Reset an LM                      |
| ::LMM_REACT_LM_SHUTDOWN    | Shutdown (power off) an LM       |
| ::LMM_REACT_BOARD          | Custom board handling            |
| ::LMM_REACT_FUSA           | Clear via FuSa notifications     |
| ::LMM_REACT_NONE           | No reaction                      |

All will send FuSa fault notifications on set and clear. The ::LMM_REACT_FUSA reaction
requires a S-EENV to call back using SCMI_FusaFaultSet() to clear the fault condition.
The ::LMM_REACT_BOARD reaction will call BRD_SM_CustomFault() to resolve.

Board {#BOARD_CONFIG}
----------------

- **File:** [config_board.h](@ref configs/mx95evk/config_board.h)

Configures the board. The parameters are a **function of the board implementation**.
For NXP reference board ports, the defines in this file are as follows:

- **BOARD_DEBUG_UART_INSTANCE** - Debug monitor UART instance
- **BOARD_DEBUG_UART_BAUDRATE** - Debug monitor UART baudrate (e.g. 115200)
- **BOARD_I2C_INSTANCE** - PMIC I2C instance
- **BOARD_I2C_BAUDRATE** - PMIC I2C baudrate (e.g. 400000)

The instance numbers are the index into the SDK base array for that driver.

Device {#DEV_CONFIG}
----------------

- **File:** [config_dev.h](@ref configs/mx95evk/config_dev.h)

This file contains configuration info used to load register data into mix IP when
the mix powers up after losing state. This can be a sequence and/or a function
per mix. This configuration must only write to registers accessible to the SM
and contained in the mix being powered.

### Sequence ###

This file contains a collection of defines, SM_mix_CONFIG, one for each mix (e.g.
SM_AON_CONFIG, SM_WKUP_CONFIG). These defines specify a programming sequence to be
applied when the mix powers up.

For example:

    #define SM_WKUP_CONFIG \
    { \
        SM_CFG_WA(0x42420028U), 0x00000003U, \
        SM_CFG_END \
    }

The only supported sequence type is the absolute data write type:

    SM_CFG_WA(addr), value

The address is **absolute** (full address). All defines must exist and all must end
with SM_CFG_END.

### Function ###

In addition, an **inline** function can be added to this file for a mix. Calling this
is then indicated by a define with the name SM_mix_CONFIG_FUNC. For example,
SM_AON_CONFIG_FUNC or SM_WKUP_CONFIG_FUNC.

    #define SM_AON_CONFIG_FUNC ExampleConfig

    inline int32_t ExampleConfig(void)
    {
        Write32(0x42846104, 0x4);

        return SM_ERR_SUCCESS;
    }

This function can be used as an alternative to the RDC programming sequence.
It will be called after the programming sequence is applied but before the
RDC programming sequence described below is applied.

The function can make use of the CONFIG_Load() function if it needs to load a lot
of data into a specific peripherals. This function is used by the TRDC config file
below which describes the sequence macros that can be used.

Device {#BCTRL_CONFIG}
----------------

- **File:** [config_bctrl.h](@ref configs/mx95evk/config_bctrl.h)

This file contains configuration info used to load register data into mix block
control IP when the mix powers up after losing state. This configuration must only
write to registers accessible to the SM and contained in the mix being powered.

### Sequence ###

This file contains a collection of defines, SM_BCTRL_b_CONFIG, one for each block
control (e.g. SM_BCTRL_A_CONFIG, SM_BCTRL_W_CONFIG). These defines specify a programming
sequence to be applied when the mix containing the block control powers up.

For example:

    #define SM_BCTRL_A_CONFIG \
        { \
            SM_CFG_W1(0x00000008U), 0x00000808U, \
            SM_CFG_W1(0x0000000CU), 0x000077F7U, \
            SM_CFG_W1(0x00000010U), 0x000077F7U, \
            SM_CFG_END \
        }

The sequence type is the same type as described below for TRDC. All defines must exist
and all must end with SM_CFG_END.

TRDC {#TRDC_CONFIG}
----------------

- **File:** [config_trdc.h](@ref configs/mx95evk/config_trdc.h)

This file contains configuration info used to load register data into a TRDC when
the mix containing the TRDC powers up after losing state. It contains a collection
of defines, SM_TRDC_n_CONFIG, one for each TRDC (e.g. SM_TRDC_A_CONFIG,
SM_TRDC_W_CONFIG). These defines specify a programming sequence to be applied when
the mix powers up. The sequence is encoded in order to save space.

For example:

    #define SM_TRDC_H_CONFIG \
    { \
        SM_CFG_W1(0x00000800U), 0xB0000063U, \
        SM_CFG_Z1(0x00011780U), \
        SM_CFG_END \
    }

Supported sequence types are as follows:

| Sequence Type                    | Comment                                         |
|----------------------------------|-------------------------------------------------|
| ::SM_CFG_END                     | End of sequence, **must** be present            |
| SM_CFG_W1(addr), value           | Write 32-bit *value* to *addr*                  |
| SM_CFG_WN(addr, len), value, ... | Write *len* 32-bit values to *addr*             |
| SM_CFG_C1(addr), value           | Conditionly write 32-bit *value* to *addr*      |
| SM_CFG_CN(addr, len), value, ... | Conditionly write *len* 32-bit values to *addr* |
| SM_CFG_Z1(addr)                  | Zero one 32-bit word                            |
| SM_CFG_ZN(addr, len)             | Zero *len* 32-bit words                         |
| SM_CFG_FN(addr, len), value      | Fill *len* words with 32-bit *value*            |
| SM_CFG_RP(addr)                  | Repeat previous sequence but at *addr*          |

All addresses are **relative** to the start of the TRDC. The addresses must
be no more than 20-bits and word aligned. All defines must exist and all must
end with SM_CFG_END.

Conditional writes occur only if the build enables the RDC (default). The R=0 option
will disable the RDC, but only when the ELE does not enable by default like some
emulation/simulation environments. This feature is normally used to control the write
that enables the TRDC.

Unit Tests {#TEST_CONFIG}
----------------

- **File:** [config_test.h](@ref configs/mx95evk/config_test.h)
- **Structures:** test_chn_config_t, test_scmi_config_t

Configures the unit tests. The defines in this file are as follows:

- **SM_TEST_CHNn_CONFIG** - fills a single test_chn_config_t structure
  - *mbInst* - index to MU SDK driver, see MU_BASE_PTRS
  - *mbDoorbell* - mailbox doorbell to use
  - *agentId* - agent ID the test is from
  - *sma* - shared memory address, undefined (0) indicates the MU SRAM
- **SM_NUM_TEST_CHN** - total number of test channels
- **SM_TEST_CHN_CONFIG_DATA** - fills in the s_testConfig array of
  test_chn_config_t structures, one per test channel
- **SM_SCMI_NUM_TEST** - total number of tests
- **SM_SCMI_TEST_CONFIG_DATA** - fills in the s_testScmiConfig array of
  test_scmi_config_t structures, one per test
  - *testId* - protocol to test
  - *channel* - test channel to use
  - *rsrc* - resource test should be done with
- **SM_TEST_DEFAULT_CHN** - specifies the default test channel

The *testId* parameter for each test comes from the following table:

| Test Protocol      | Comment                              |
|--------------------|--------------------------------------|
| ::TEST_BASE        | Test using the base protocol         |
| ::TEST_PD          | Test using the power domain protocol |
| ::TEST_SYS         | Test using the system power protocol |
| ::TEST_PERF        | Test using the performance protocol  |
| ::TEST_CLK         | Test using the clock protocol        |
| ::TEST_SENSOR      | Test using the sensor protocol       |
| ::TEST_RST         | Test using the reset protocol        |
| ::TEST_VOLT        | Test using the voltage protocol      |
| ::TEST_LMM         | Test using the LMM protocol          |
| ::TEST_GPR         | Test using the BBM GPR protocol      |
| ::TEST_RTC         | Test using the BBM RTC protocol      |
| ::TEST_BUTTON      | Test using the BBM button protocol   |
| ::TEST_CPU         | Test using the CPU protocol          |
| ::TEST_PIN         | Test using the pin control protocol  |
| ::TEST_CTRL        | Test using the control protocol      |
| ::TEST_FUSA        | Test using the FuSA EENV protocol    |
| ::TEST_FAULT       | Test using the FuSa fault protocol   |

Doxygen {#DOX_CONFIG}
-------

- **File:** config.dox

Contains doxygen comments to define the group for the config. For example:

    /*!

    @defgroup CONFIG_MX95EVK CONFIG_MX95EVK: i.MX95 EVK Configuration Data

    @brief Module for i.MX95 EVK Configuration Data.

    */

The group then is used in the other configuration files.

Configuration Tool {#CONFIGTOOL}
==================

The SM implementation includes a command-line tool to process a single configuration
(\<file\>.cfg) file and generate the collection of configuration files describes
[above](@ref CONFIG_FILES). It generates all the required files. Because the
[config_dev.h](@ref DEV_CONFIG) file is custom raw config of IP registers the
generated file is just a skeleton to be filled in manually.

The tool is a perl script and located in configs and is named configtool.pl.
The usage info is as follows:

    Usage: configtool.pl [OPTIONS]...
    Generate SM configuration files.

      -i  specify input file
      -o  specify output directory
      -l  specify optional log file
      -v  display processing steps
      -h  display this help and exit

    The input configuration file is loaded, processed, and
    configuration header files written to the output directory

The input file is a text file that describes the [logical machines](@ref SYS_ARCH_LM),
binding from machines to RPC to transport to mailbox drivers, and ownership of peripherals
and memory. This ownership info is then used to determine API access rights to resources
(clocks, pins, etc.) and CPU access to peripherals and memory (.e. RDC configuration). Note
because the [config_dev.h](@ref DEV_CONFIG) file usually has manual customizations, it will
not be overwritten if it exits.

The cfg files are also usually stored in the configs directory. So an example usage is:

    cd configs
    ./configtool -i <name>.cfg -o <name>

where \<name\> is the configuration name. This can also be accomplished using make:

    make config=<name> cfg

To create a new config, its best to copy a config for the NXP (e.g. EVK) board for the
same SoC device to a new config file name, modify it, and generate the header files.
See @ref NEW_CONFIG.

The log file dumps the configuration data at various stages of processing:

- Raw input files
- Parsed data (all defines substituted)
- Mailbox info
- Transport info
- SCMI channel info
- SCMI agent info
- LMM start/stop info
- LMM info
- TRDC info
- Raw TRDC data
- TRDC processed data
- Test data

The general format of the file consists of the following on each line:

- **include** - include keyword followed by a file to include, formatted the same,
  path relative to the top-level configuration file
- **command** - a command keyword with key=value pairs after, space/comma separated,
  see the [command list](@ref CONFIGTOOL_CMDS) for more info
- **resource(s)** - one or more device-specific resources, for example PD_WAKEUP, with
  key=value pairs after, space/comma separated, can also be RDC resources (e.g. MBC_W0=0.96),
  see the [resource section](@ref CONFIGTOOL_RSRC) for more info
- **define** - a define name followed immediately with a colon (:), the remainder of
  the line is the define value, value applies until redefined
- **comment** - a comment line that starts with a hash (#)

Line can be continued to the next line by ending with a backslash (\\).

Many commands bracket other commands or resource lines (e.g. DOM, LM, SCMI_AGENT). For example,
an SCMI agent command (SCMI_AGENTn) starts the definitions of a new agent. All commands and
resources then apply to that until the next SCMI_AGENTn (or LMn) command.

    SCMI_AGENT1         name="AP-S", secure

    Command for agent 1
    Resource assignment for agent 1
    ...
    
    SCMI_AGENT2         name="AP-NS"

Configuration files normally include a device-specific file that then defines peripheral and
memory names that specify all the resources associated with the peripherals or memory.

    include ../../devices/MIMX95/configtool/device.cfg

Subsequent configuration can then use the name to configure all the API access rights for all
the resources and all the RDC access rights for the associated RDC components. For example:

    CAN_FD3:            PD_WAKEUP, CLK_CAN3, MBC_W0=0.96, DAISY_CAN3_RX

This will define CAN_FD3 to have the specified power domain, clocks, daisy, and TRDC component.
The define can then be used in config file to apply key=value pairs.

    CAN_FD3             perm=rw, api=all

This will apply the specific permissions to the MBC_W0=0.96 TRDC resource and the API
permissions the power domain, clock, and daisy resources. Note these defines do not
have to be used. Configuration files can always directly use resource and RDC names.
Some resources are never associated with a define.

Configtool Commands {#CONFIGTOOL_CMDS}
-------------------

The configtool supports the following commands and key=value pairs in the input file.

| Command     | Key     | Value                                        |
|-------------|---------|----------------------------- ----------------|
| MAKE        | soc     | Build includes ./devices/\<VAL\>/sm/Makefile |
|             | board   | Build includes ./boards/\<VAL\>/sm/Makefile |
|             | build   | Build includes ./sm/makefiles/\<VAL\>.mak |
| DOX         | name    | Define doxygen group CONFIG_\<VAL\>, use group for all config files |
|             | desc    | Group description, quoted |
| DOMn        | did     | Starts a domain (aka DID) section *n*, ends with another DOMn or LMn command, used for resources not part of an LM such as ELE, MTR, DAP, etc.,  the DID is usually defined in the RM and sometimes must be a fixed value e.g. ELE=0, MTR=1 |
| LMn         | name    | Starts an LM section *n*, *n* starts at 0 and should increment, LM name string, quoted, 15 characters max |
|             | rpc     | Linked RPC is SM_RPC_\<VAL\>, e.g. ::SM_RPC_SCMI |
|             | boot    | Optional, boot order starting with 1, undefined/0 = do not boot |
|             | skip    | Optional, if not 0, ignore error on boot if no image in boot container |
|             | rtime   | Optional, boot time of LM in uS, relative to start of LM boot loop, max 178 seconds |
|             | did     | RDC DID for this LM |
|             | safe    | Safety type is LMM_SAFE_TYPE_\<VAL\>, e.g. ::LMM_SAFE_TYPE_SEENV, deault is NSEENV |
|             | default | The deault LM for the debug monitor |
| MODE        | msel    | Alternate boot config index |
|             | boot    | Optional, boot order starting with 1, undefined/0 = do not boot |
|             | skip    | Optional, if not 0, ignore error on boot if no image in boot container |
| SCMI_AGENTn | name    | Starts an SCMI agent section *n*, *n* starts at 0 and should increment, agent name string, quoted, 15 characters max |
|             | secure  | Agent is secure (no =value) |
| MAILBOX     | type    | Define a mailbox of type SM_MB_<VAL\>, e.g. ::SM_MB_MU, one per agent |
|             | mu      | Index into SDK MU base pointer array, platform side |
|             | test    | Index into SDK MU base pointer array, client side for testing |
|             | sma     | Shared memory area address, undefined/0 = MU SRAM |
| CHANNEL     | xport   | Define a channel of type SM_XPORT_<VAL\>, e.g. ::SM_XPORT_SMT, up to four per mailbox |
|             | db      | Mailbox doorbell, 0-3 |
|             | rpc     | RPC type of SM_RPC_<VAL\>, e.g. ::SM_RPC_SCMI |
|             | type    | SCMI channel type of SM_SCMI_CHN_<VAL\>, e.g. ::SM_SCMI_CHN_A2P |
|             | check   | CRC algorithm to use (e.g. crc32 for ::SM_SMT_CRC_CRC32), default is none |
|             | notify  | Depth of notification buffer, **one setting applies to all channels** |
|             | test    | =default, use this channel as the default for unit tests |
| DEBUG       | did     | Specify DID (usually 9) used by the DAP/ETR that should have access to everything |
| MIX         | name    | Add dev config for the mix |


While any DID can be used, it is recommended to use the standard mapping defined in
the TRDC section of the SoC RM.

Configtool Resources {#CONFIGTOOL_RSRC}
--------------------

In SCMI terminology, resources are things like clocks, power domains, voltage domains,
etc. They are not IP "resources" as referenced in the SoC RM (called peripherals in this
tool). Resources can be of the following types (see the device and board module header
files for a list of each resource type):

- **BASE_n** - Agent *n*, used to configure base protocol access to agents
- **PD_a** -  Device/board power domain *a* (e.g. PD_GPU)
- **SYS** - Used to define access rights to the system power protocol
- **PERF_a** - Device/board performance domain *a* (e.g. PERF_A55)
- **CLK_a** -  Device/board clock *a* (e.g. CLK_LPI2C3)
- **SENSOR_a** - Device/board sensor *a*
- **RST_a** - Device/board reset domain *a* (e.g. RST_DPHY_PHYRESETIN)
- **VOLT_a** - Device/board voltage domain *a*
- **LMM_n** - LM *n*, used to configure LMM protocol access to LM
- **GPR_n** - Device/board GPR *n*
- **RTC_a** - Device/board RTC *a*
- **BUTTON_n** - Device button *n*
- **CPU_a** - Device peripheral LPI *a* (e.g. CPU_A55C0)
- **PERLPI_a** - Device CPU *a* (e.g. PERLPI_GPIO1)
- **PIN_a** - Device pin control *a* (e.g. PIN_SD2_DATA0)
- **DAISY_a** - Device pin daisy *a* (e.g. DAISY_CAN3_RX)
- **CTRL_a** - Device/board control *a*
- **FUSA** - Used to define access rights to the F-EENV functions (for FuSa)
- **FAULT_a** - Device/board fault *a* (for FuSa)
- **CRC_a** - Device/board CRC channel *a* (for FuSa)
- **TRDC_CONFIG_a** - TRDC *a* configuration info
- **MDAC_am=r** - TRDC *a*, MDA_Wr_m, *m* is the master, *r* is register (can be
  a range r1-r2)
- **MBC_am=s.b** - TRDC *a*, MBCm_MEMs, *m* is the MBC instance, *s* is the memory,
  and *b* is the block (can be a range b1-b2)
- **MRC_am=0** - TRDC *a*, MRCm, *m* is the MRC instance

Resources support the following key=value pairs.

| Resource       | Key       | Value                                         |
|----------------|-----------|----------------------------- -----------------|
| \<RSRC\>       | api       | API permission for all resources on that line |
|                | \<PROTO\> | API permission for resources of that protocol type on that line |
|                | start     | Call config function on that resource when the LM boots |
|                | stop      | Call config function on that resource when the LM shuts down |
|                | msel      | Mode for a start/stop (default 0) |
|                | test      | Perform SCMI unit tests on the resource (no =value) |
|                | BCTRL_a_b | *a* is the letter index, b the register name, value is address (for CPUs) or bit |
| FAULT_a        | reaction  | Define a reaction of type LMM_REACT_<VAL\>, e.g. ::LMM_REACT_SYS_RESET |
|                | lm        | LM fault affects (default to LM fault configured in) |
| TRDC_CONFIG_a  | ndid      | Number of DID |
|                | nmstr     | Number of masters |
|                | nmbc      | Number of MBC |
|                | nmrc      | Number of MRC |
| MDAC_am=r1-r2  | sa        | Security attribute (secure, nonsecure, bypass), range (-r2) optional|
|                | pa        | Privileged attribute (privileged, user, bypass)|
|                | mdid      | Override LM/DOM DID, mdid=none will skip MDAC |
|                | sid       | Stream ID |
|                | kpa       | Known physical address (default to 1) |
| MBC_am=s.b1-b2 | perm      | Permission value (see table below), range (-b2) optional |
|                | did       | Override LM/DOM DID, can be range (d1-d2) |
|                | nblks     | Number of blocks supported by the MBC |
| MBC_am=s       | perm      | Permission value (see table below)|
|                | did       | Override LM/DOM DID |
|                | origin    | Starting address of a memory |
|                | begin     | Start of a range to define permissions |
|                | end       | End of range to define permissions |
|                | size      | Alternative to end, size of range to define permissions |
|                | nblks     | Number of blocks supported by the MBC |
|                | blksize   | Size of the MBC blocks |
| MRC_am=0       | perm      | Permission value (see table below)|
|                | did       | Override LM/DOM DID |
|                | begin     | Start of a range to define permissions |
|                | end       | End of range to define permissions |
|                | size      | Alternative to end, size of range to define permissions |
|                | nrgns     | Number of regions |

Notes:

- Access control takes two forms, API access via an agent's MU and TRDC access for a DID.
  Each LM is a unique DID and can have multiple agents which all have the same DID.
- For API permissions, list resources for that agent with the desired access rights (if access
  is desired). So if two agents both need API access then that resource must be listed for each,
  regardless of which LM they are in. So for example, if ATF and Linux both need to make API
  calls on a resource then the it must be listed for each.
- For RDC, there are unique permission registers for each DID. So each LM must list what that
  DID should be able to access. When multiple agents are in the same LM, RDC rights can
  only be divided by secure/non-secure. The RDC programming model assumes anything accessible
  in NS is also accessible in secure. So for example, resources that need to be accessed by
  both ATF and Linux only need to be listed in the Linux section, but because of the API 
  permissions they are often listed in the ATF section also.
- See the [SCMI config file](@ref SCMI_CONFIG) for a list of protocols and permissions.
  Note only a portion of the protocol and permission is used and is lowercase. For example,
  clk for the clock protocol and notify for the SM_SCMI_PERM_NOTIFY permission.
- When the *api* key is used, it is replaced during processing with \<PROTO\> keys for each
  type of protocol resource found on the same line.
- If no MBC/MRC resources are on the line then any *perm* key will be removed during
  processing. The value is also erplaced with the numerical value defined in the TRDC
  section in the SoC RM and listed below.
- See the [LMM config file](@ref LMM_CONFIG) for start/stop commands associated with
  resource types. The parameter is of the format a|b|c where *a* is the order, *b* is
  arg1 and *c* is arg2. Arguments are optional.
- See the [LMM config file](@ref LMM_CONFIG) for info on defining fault reactions.
- For block control, the BCTRL_a_b value pair is matched between a CPU resource and a
  peripheral resource. If they match then the CPU value is the relative address offset in
  the block control for that CPU and the value for the peripheral is the bit mask. All
  matching peripheral values are ORed together for the register name *b* and added to
  the configuration define for block control *a*.
- The device include files use two macros that must be defined in the top-level config
  file (each LMM/agent section): DFMT0 and DFMT1. DFMT0 will be used by the following CPUs
  to apply parameters for the TRDC DAC. DFMT1 will be used by the following non-CPU bus
  masters to apply parameters for their DACs.

Permissions consist of a 16-bit value, divided into four 4-bit values. Each 4-bit value
conists of bits for read, write, and execute (0RWX). The four groups are secure-privileged,
secure-user, nonsecure-privileged, nonsecure-user. The table below lists the permission
setting defines (besides an actual 0xXXXX value):

| Permission  | Value  |
|-------------|--------|
| none        | 0x0000 |
| sec_r       | 0x4400 |
| secpriv_rx  | 0x5000 |
| secpriv_rw  | 0x6000 |
| secpriv_rwx | 0x7000 |
| sec_rw      | 0x6600 |
| rw          | 0x6666 |
| sec_rwx     | 0x7700 |
| ro          | 0x4444 |
| nspriv_r    | 0x7740 |
| ns_r        | 0x7744 |
| nspriv_rw   | 0x6660 |
| nspriv_rwx  | 0x7770 |
| full        | 0x7777 |

Example Configuration {#CONFIGTOOL_EXP}
---------------------

The following configuration file is an example for i.MX95. The configuration is a simple
LM for the SM itself with no RPC and an LM for the M7 with a single SCMI agent.

@includelineno example.cfg

Below is an explanation of each line:

- **Line 3** - Specify the config is for i.MX9, the i.MX9 EVK, and uses the gcc cross compiler
- **Line 4** - Specify the name and description to be used in the doxygen generated
  documentation
- **Lines 12-13** - Indicate the UART and baud rate for the SM debug output and monitor
- **Line 19** - Start a new LM section for the SM, no RPC, TRDC DID=2 (see SoC RM TRDC section)
- **Lines 21-23** - Defines, OWNER and EXEC used below, DFMT0 used in include files for CPU masters
- **Line 27** - Give LM0 the M33 core. M33P and OWNER are defines and expand to:
@code
    DEV_SM_PD_M33P DEV_SM_CLK_M33 DEV_SM_CLK_M33SYSTICK DEV_SM_CPU_M33P sa=secure MDAC_A16C=0-2 pd=all clk=all cpu=all 
@endcode
  This configures the MDACs for secure (DID=2 from LM), ALL perms for the M33 related power
  domain, clocks, and CPU protocols.
- **Line 27** - Give LM0 LPUART1. LPUART1 and OWNER are defines and expand to:
@code
    DEV_SM_CLK_LPUART1 MBC_A0=0.56 perm=0x6600 clk=all 
@endcode
  This configures the LPUART1 block of the MBC for secure R/W access for DID=2, and all perms for
  the LPUART clock.
- **Line 32** - Give LM0 the I2C1_SCL pin. PIN_I2C1_SCL and OWNER are defines and expand to:
@code
    DEV_SM_PIN_I2C1_SCL pin=all 
@endcode
  This configures ALL perms for the pinctrl protocol.
- **Line 36** - Give LM0 access to all of the M33 code TCM. M33_TCM_CODE and EXEC are defines and
  expand to:
@code
    MBC_A1=0 origin=0x201C0000 nblks=32 blksize=8K perm=0x7700 begin=0x201C0000 size=256K 
@endcode
  This configures all blocks of the TRDC A MBC1 for secure RWX access by the M33 (DID=2).
- **Line 37** - Same as line 36 but for the M33 system TCM.
- **Line 43** - Start a new LM section for the M7, RPC is SCMI, TRDC DID=4 (see SoC RM TRDC section)
- **Lines 45-47** - Defines, OWNER and DATA used below, DFMT0 used in include files for CPU masters
- **Line 51** - Indicates this core should start and stop when LM1 is booted and shutdown.
- **Line 55** - Sart a new SCMI agent section with the specified name
- **Line 56** - Sart a new mailbox section, type is MU, use SDK MU base pointer array index 9 for
  the platform side and index 8 for the unit test side.
- **Lines 57-58** - Define a channel on doorbell 0. Transport is SMT, use CRC32, linked RPC is SCMI,
  and the SCMI channel type is A2P (agent to platform). The channel is also the default to use for
  unit testing.
- **Lines 59-60** - Define a channel on doorbell 1. Transport is SMT, use CRC32, linked RPC is SCMI,
  and the SCMI channel type is P2A_NOTIFY (platform to agent for notification). The notification
  buffer size for all channels combined is 24 words.
- **Line 64** - Give LM1 the M7 core. Similar to line 27.
- **Lines 65** - Give LM1 LPUART2. Similar to line 28. 

Note no memory was given to the M7 as it always has full access to its TCM.

Configuration Debug {#CONFIG_DEBUG}
===================

This section provides suggestions for debugging configuration issues. Most configuration has to do
with access controls, either API access or TRDC access. 

API Access Issues
-----------------

For API access the key to a identifying a configuration issue is to always check error responses.
The only response related to configuration is ::SCMI_ERR_DENIED. This indicates the configuration
does not allow the desired operation on the associated resource. The required access level for
functions can be found in the @ref SCMI_PROTO section.

The SM logs any error response to an API call. It records one error per agent and will not overwrite
this log until cleared. The [debug monitor](@ref MONITOR) "err" command will display and clear this log.
If it does not list any API errors then the SM did not return one to an agent.

If an API access issue, then check the configuration of the associated [config_scmi.h](@ref SCMI_CONFIG)
file. This should list the configured permission level for the resource for the agent. If not, revisit the
configuration given to the [configtool](@ref CONFIGTOOL). When run directly, the tool can generate a log
file that can be used to identify cfg file issues.

Hardware Access Issues
----------------------

Access issues related to an RDC (e.g. TRDC) are usually discovered due to getting a bus fault accessing
a peripheral or memory.

The fist step is to identify if the issue is due to an RDC violation. Similar to the API logging above,
the TRDC hardware will log the first occurrence of a returned bus error for each DID for each TRDC
component. The same debug monitor "err" command mentioned above will also list and clear these for any
component powered up. If not listed, then the TRDC was not the cause of the error. Other causes include
not having the component powered up via the [power protocol](@ref scmi_proto_power), lack of clocks,
incorrect address, incorrect MPU/MMU/SMMU configuration, caching, etc.

If the "err" command does show a TRDC access violation, confirm the address is correct. Also confirm the
access type (read/write/execute, secure/non-secure, privileged/user) is correct. Confirm the DID (aka
DOM) is correct. If not then the issue could be a disconnect between the access request and the TRDC config.

The TRDC can be dumped using the debug monitor "trdc" command. The first parameter is the TRDC. The list of
TRDCs can be found in the dev_sm_rdc.c file for the SoC. The optional second parameter is the DID (aka DOM)
and can be used to limit the output scope. For example:

    trdc aon 3

Will dump the TRDC_A config for DID 3. Compare this configuration using the SoC RM to the desired config and the
error presented with the "err" command. If this is incorrect, then check the [config_trdc.h](@ref TRDC_CONFIG)
for correctness. If wrong then debug the cfg file using the configtool log.

If an access causes a client to fault, a message may be output on the SM debug UART. See @ref PORT_NXP_PRINT.

