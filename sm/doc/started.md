Getting Started {#START}
===============

This section gives an overview of the steps needed to configure and build a System Manager binary. It aims to
give a high level view of the System Manager generation process. More detailed explanations can be found in
the following sections.

Installing the Toolchain
========================

Compiling requires an ARM cross-compiler. Download and install the required arm-none-eabi toolchain from
the [Arm GNU Toolchain Downloads](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
website. For example, from the x86_64 Linux hosted cross toolchains AArch32 bare-metal target
(arm-none-eabi) section, download the *.xv file to a directory for the tool chain (e.g. tools) and then:

    tar xvf *.mv

Set the TOOLS shell variable to the directory the toolchain is installed in. For example:

    export TOOLS=~/tools

When the toolchain is in a directory like arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi in this
*tools* directory.

Also ensure the Linux installation is up-to-date and then install:

    sudo apt-get -y install make gcc g++-multilib srecord

See the *Release Notes* for the exact toolchain version the SM was tested with. More information on
the toolchain can be found in the @ref DEV_GUIDE.

Compiling an SM Image
=====================

To get started with the SM on an NXP board, download the [github](https://github.com/nxp-imx/imx-sm)
repository and then compile the SM for the target configuration.

For example, in the top directory of the code base:

    make config=mx95evk all

The resulting binary image file will be *build/mx95evk/m33_image.bin*, and can be integrated into a boot
image using the [mkimage tool](https://github.com/nxp-imx/imx-mkimage). Once booted on a hardware platform,
the SM will display a @ref MONITOR prompt on the M33 debug UART.

More information and examples for compiling the SM, programming it to boot media, and using it can be found
in the @ref DEV_GUIDE.

Configuring the SM {#NEW_CONFIG}
==================

Configuration header files determine how the SoC will be divided between LM, which LM will boot at POR,
and what RPC API functions the agents on those LM can call. The SM comes from NXP with example
configurations for use on NXP boards with reference software ports (Linux, MCUXpresso SDK, etc.). The
configuration header files are generated using a @ref CONFIGTOOL. One thing the configuration specifies
is the associated SoC and board. Almost always a new configuration must be created for a customer product.

For example, to create a new configuration, in the top directory of the code base:

    cp configs/mx95evk.cfg configs/mx95cust.cfg

Modify the *configs/mx95cust.cfg* file. Then:

    make config=mx95cust cfg

The new configuration can then be compiled by using the new config name in the make command:

    make config=mx95cust all

More information on configuration and the configtool can be in the @ref CONFIGURATION section.

Porting the SM
==============

To run on different boards, the SM must be ported to them. The SM has a [board layer of code](@ref BRD_SM)
which abstracts board specific components such as the PMIC and other board components involved in system
management.

To start, copy an existing board port for the same SoC:

    cp -r boards/mcimx95evk boards/mcimx95cust

Then modify the new *board.h*, *board.c*, *brd_sm.h*, and *brd_sm.c* files to reflect the new board. To
use the new board, modify the board parameter on the MAKE line of the new configuration created above:

    MAKE    soc=MIMX95, board=mcimx95cust, build=gcc_cross

And then compile using the new configuration. See the @ref PORT_GUIDE for more information.

Porting the Client API
======================

Clients must make RPC calls to the SM. A [reference API](@ref scmi_proto) is provided that can be ported
to a client SW system such as the MCUXpresso SDK.

The following steps are required:

- Copy the *components/scmi*, *components/smt*, and *components/crc* to the code base
- Include these in the compile and header file path
- Include the SDK MU1 driver or modify the SMT component to use a custom driver
- In the client code, call SMT_ChannelConfig() for each channel to configure. For example:


    SMT_ChannelConfig(SCMI_A2P, SCMI_MU, 0, 0);     /* 0: A2P channel */
    SMT_ChannelConfig(SCMI_NOTIFY, SCMI_MU, 1, 0);  /* 1: P2A notification channel */
    SMT_ChannelConfig(SCMI_P2A, SCMI_MU, 3, 0);     /* 2: FuSa notification channel */

See the [Client API](@ref PORT_CLIENT) section of the Porting Guide.

Building the Documentation
==========================

To build the full documentation, install the required tools as described in the @ref GUIDE_DOC
section. Then change to the documentation directory (sm/doc) and execute the following:

    make <TARGET>

Where target can be html, rtf, latex, pdf, or clean. No target will result in building
all the documentation types. The output is written to the build directory (sm/doc/build)
in directories with the associated document type. The top level for the html output
is the *index.html* file.

To build the release notes:

    make rn

The output is sm/doc/sm-rn.pdf (also an html version in sm/doc/build/html).

