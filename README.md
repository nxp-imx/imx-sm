The System Manager (SM) is an application that runs on a Cortex-M processor on many NXP i.MX processors.
The Cortex-M is the boot core, runs the boot ROM which loads the SM (and other boot code), and then
branches to the SM. The SM then configures some aspects of the hardware such as isolation mechanisms
and then starts other cores in the system. After starting these cores, it enters a service mode where
it provides access to clocking, power, sensor, and pin control via a client RPC API based on ARM's
[System Control and Management Interface (SCMI)](https://developer.arm.com/documentation/den0056/latest/).
To facilitate isolation between cores, the SM partitions the SoC into logical machines (LM) which have
statically configurable access rights to both hardware and RPC API calls.

Installing the Toolchain
========================

Compiling requires an ARM cross-compiler. Download and install the required arm-none-eabi toolchain from
the [Arm GNU Toolchain Downloads](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
website. For example, from the x86_64 Linux hosted cross toolchains AArch32 bare-metal target
(arm-none-eabi) section, download the *.xv file to a directory for the tool chain (e.g. tools) and then:

    tar xvf *.xv

Set the TOOLS shell variable to the directory the toolchain is installed in. For example:

    export TOOLS=~/tools

When the toolchain is in a directory like arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi in this
*tools* directory.

Also ensure the Linux installation is up-to-date and then install:

    sudo apt-get -y install make gcc g++-multilib srecord

See the *Release Notes* for the exact toolchain version the SM was tested with.

Compiling an SM Image
=====================

To get started with the SM on an NXP board, download the [github](https://github.com/nxp-imx/imx-sm)
repository and then compile the SM for the target configuration.

For example, in the top directory of the code base:

    make config=mx95evk all

Then copy the resulting binary image file, *build/mx95evk/m33_image.bin*, to the iMX95 directory of the
[mkimage tool](https://github.com/nxp-imx/imx-mkimage). Build a boot container using mkimage, program
it to the boot device, and boot the board. The SM will display a debug monitor prompt on the M33 debug
UART.

The above config is for Linux+M7 system testing. Another config is delivered for MCUXpresso testing:

    make config=mx95alt all

Customers will usually create their own config that partitions resources between the AP and M7 for
their use-case.

Building the Documentation
==========================

To build the full documentation, install the required tools:

    sudo apt-get -y install make doxygen texlive texlive-latex-extra

Then change to the documentation directory (sm/doc) and execute the following:

    make html

The output is written to the build directory (sm/doc/build/html). The top level for the html output
is the *index.html* file.

To build the release notes:

    make rn

The output is sm/doc/sm-rn.pdf (also an html version in sm/doc/build/html).

