Developer's Guide {#DEV_GUIDE}
=================

This section describes how to compile a System Manager image and stitch it into a boot
image that can boot on a supported platform.

The SM application can be compiled for two primary variants: target or simulation. Target
builds are compiled with a cross compiler and will only run on i.MX9 hardware. Simulation
builds run on the host computer and make use of fake HW functions in the code to simulate
the hardware. Documentation is also compiled.

Section Contents
----------------

- [Build Environment](@ref GUIDE_BUILD)
- [Compiling the SM](@ref GUIDE_COMPILE)
- [Running the SM](@ref GUIDE_RUN)
- [Documentation](@ref GUIDE_DOC)
- [Source Code Structure](@ref GUIDE_FILES)

In addition, see @ref MONITOR for more information on using the CLI.

Build Environment {#GUIDE_BUILD}
=================

The SM application is a 32-bit program compiled using the GNU C compiler (gcc), debugged
using the GNU debugger (gdb/ddd), and documented using doxygen. As a result, a GNU-compliant
build environment is required.

Linux
-----

The only supported build environment is a native Linux host. Ubuntu 22.04 has been confirmed to work well.

Prerequisites
-------------

Assuming an Ubuntu 22.04 host, the following packages need to be installed for normal development:

    sudo apt -y install git meld
    sudo apt -y install make gcc g++-multilib ddd
    sudo apt -y install srecord cppcheck

Tool Chain {#GUIDE_TOOLCHAIN}
------------

Compiling requires an ARM cross-compiler. Download and install the required arm-none-eabi toolchain from
the [Arm GNU Toolchain Downloads](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
website. For example, from the x86_64 Linux hosted cross toolchains AArch32 bare-metal target
(arm-none-eabi) section, download the *.xv file to a directory for the tool chain (e.g. tools) and then:

    tar xvf *.mv

The latest toolchain should work but it is highly recommended to use the specific version listed in the
release notes as this version was used for testing. Note the Linux-based ARM cross-compile toolchain
requires a 64-bit Linux to run.

The makefile looks for the compiler using \$(TOOLS)/arm-gnu-toolchain-*-none-eabi.
If using bash, then set the TOOLS environment variable as follows:

    export TOOLS=<directory contain the GCC compiler directory>

So for example if the GCC toolchain is installed in
~/tools/arm-gnu-toolchain-12.3.rel1-x86_64-arm-none-eabi then set *TOOLS=~/tools*.

Compiling the SM {#GUIDE_COMPILE}
==================

The SM application can be fully compiled using the Makefile. The command format is:

Usage: make TARGET OPTIONS

TARGET is optional. Possible TARGET parameters are as follows:

| Target           | Action                                                  |
|------------------|---------------------------------------------------------|
| \<none\>         | Defaults to img                                         |
| clean            | Delete output files (but not build directory)           |
| really-clean     | Delete build directory                                  |
| img              | Compile an image for the specified configuration        |
| all              | Do a clean and then compile an image                    |
| cfg              | Generate config using the [configtool](@ref CONFIGTOOL) |
| cppcheck         | Perform a cppcheck                                      |

There are several options that can be specified on the make command line:

| Option             | Action                                     |
|--------------------|--------------------------------------------|
| CONFIG=\<config\>  | Specify the desired configuration          |
| V=0                | quiet output (default)                     |
| V=1                | verbose output                             |
| M=0                | no debug monitor                           |
| M=1                | include debug monitor (default)            |
| T=\<test\>         | run tests rather than boot next core       |
| GCOV=1             | Compile with gcov info. Simulation only.   |

**The debug monitor is not intended for production images.** Always disable for
production.

The CONFIG option specifies what configuration directory to use. See the
@ref CONFIGURATION section for more info.

| CONFIG             | Description                                           |
|--------------------|-------------------------------------------------------|
| mx95evk            | MX95 EVK, Linux and M7                                |
| mx95alt            | MX95 EVK, AP or M7, for BSP testing and DDR test tool |
| simu               | Simulation build, uses a simulated device and board.  |

Look in the configs directory to see the complete list of options. If a new configuration
is required, see the [configtool](@ref CONFIGTOOL) section.

Example steps would be:

    cp configs/mx95evk.cfg configs/mx95new.cfg

Modify the new cfg file to the new configuration, then:

    make cfg config=mx95new

Then compile the SM:

    make all config=mx95new

The output of the compile is in the build/\<CONFIG\> directory. The files of interest
are the *m33_image.bin* which is used to build boot containers and the *m33_image.elf*
which is used for loading via JTAG tools. For simulation builds the output is an
executable named *sm*.

Running the SM {#GUIDE_RUN}
==============

The general flow to program all the things on an SDCARD for boot are as follows:

- If booting Linux, program a complete Linux SDCARD image
- Download the mkimage tool
- Use the mkimage tool to download all the other binaries like ATF, u-boot, SM
- Optionally, use a prebuilt SM, rebuild the boot container, and program it
- Optionally, build the SM, rebuild the boot container, and program it

Follow the README instructions to use Yocto to build a Linux BSP image for the target
platform:

- [Embedded Linux for i.MX Applications Processors](https://www.nxp.com/design/software/embedded-software/i-mx-software/embedded-linux-for-i-mx-applications-processors:IMXLINUX?).

This will also produce the individual binary images required for the mkimage tool.

To download mkimage:

    git clone https://github.com/nxp-imx/imx-mkimage

See the [example](@ref GUIDE_EXP_RUN) below for a complete programming sequence.

Once you have a programmed SDCARD, see the User Manual for the board to understand
connections, configuration, **bootmode**, and UART usage.

Normally, connection of the DBG USB to a PC will cause new COM ports to be available.
One of these will be the SM debug UART. This needs to be configured for 115200 baud.

On Linux, putty or minicom can be used for a terminal program. The USB-based serial ports
can be listed with:

    ls -la /dev/ttyUSB*

Note you need to belong to the group owned by the above device entries.

Programming Linux on an SDCARD
------------------------------

If Linux is needed on an SDCARD, the programming sequence is as follows:

- program a complete SDCARD image
- program an updated boot container (if desired)

The complete SDCARD image contains a ELE FW, SM, M7 image, ATF, u-boot, Linux kernel, and
Linux RFS. These are the combined set that was tested. The SM is compiled to include debug but
no debug monitor.

Programming an SDCARD image requires creating an SDCARD image using Yocto. Find the appropriate SDCARD
image and program using dd. The image typically is a file compressed with bzip2 or zstd. Unzip using
bunzip2/zstd. The dd command is something like the following:

    sudo dd if=imx-image-core-imx95evk.rootfs.wic of=/dev/sdc bs=8M oflag=direct status=progress
    sync

Note the bunzip2 and dd steps can be done at the same time to save disk space:

    bunzip2 -dc imx-image-core-imx95evk.rootfs.wic.bz2 | sudo dd of=/dev/sdc bs=8M iflag=fullblock oflag=direct status=progress

Or for zstd:

    zstd --no-progress -dc imx-image-core-imx95evk.rootfs.wic.zst | sudo dd of=/dev/sdc bs=8M iflag=fullblock oflag=direct status=progress
    sync

**Note in the above to replace the device (e.g. /dev/sdc) with the correct one for the SD/MMC in your
system. Failure to do this could overwrite other drives including the boot drive. The drive mapping can
move on different Linux boots!**

Images can also be loaded and/or programmed using [uuu](https://github.com/NXPmicro/mfgtools)
(supported on Linux and Windows). This can be done using downloaded images or URL links. The SDCARD should
boot with just this uuu programmed images. Replacing the boot container is then only required if a
different SM, ELE FW, or M7 code is desired. Programming an updated boot container
follows the sequence below.

Rebuilding and Flashing the Boot Container {#GUIDE_EXP_RUN}
------------------------------------------

The boot container can be rebuilt from component parts including ELE FW, SM, ATF, and u-boot.
The Linux kernel and RFS are stored on the card separately and not part of the boot container. The
boot container can be written to the card without overwriting the Linux kernel and RFS.

The container building tool is mkimage:

- mkimage repo: [imx-mkimage](https://github.com/nxp-imx/imx-mkimage)

The required binaries can be obtained from the Yacto build. Replace any binaries as desired
(see @ref GUIDE_COMPILE for info on building the SM) and then build for a target and program
an SDCARD:

    make SOC=iMX95 flash_lpboot_sm_all
    sudo dd if=iMX95/flash.bin of=/dev/sdc bs=1k seek=32 oflag=direct status=progress
    sync

There are many container targets and they can vary by board. See the mkimage [README]
(https://bitbucket.sw.nxp.com/projects/IMX/repos/imx-mkimage/browse/README) for more info. Common
ones include:

| Target                 | Build          |
|------------------------|----------------|
| flash_lpboot_sm        | SM only        |
| flash_lpboot_a55       | SM+AP          |
| flash_lpboot_sm_m7     | SM+M7          |
| flash_lpboot_sm_m7_ddr | SM+M7(DDR)     |
| flash_lpboot_sm_all    | SM+AP+M7(DDR)  |

Note for DDR, LPDDR_TYPE=lpddr4x|lpdd5 OEI=YES are also required.

On Windows platforms, [cfimager](https://github.com/NXPmicro/cfimager) can be used to program SDCARD
images.

Insert the SDCARD into the dev board, connect the debug USB to a PC, configure terminals for the
four comm ports at 115200 baud, and power up the board.

The SM in the above process is the same as the one found in the original Linux SDCARD image. If
none of the files are replaced, the result should be the same. This process however allows for any
of the component binaries to be replaced with alternate versions. This include using a different
SM prebuilt binary or one compiled from the source.

Programming to FlexSPI
----------------------

- TODO

Running a Simulation Build
--------------------------

The simulation builds can be run on the same host used to compile it. The executable (sm) is
found in build's associated output directory (see @ref GUIDE_COMPILE above). The simulation
build takes one optional argument which sets the mSel value.

Documentation {#GUIDE_DOC}
=============

The documentation is compiled via [doxygen](https://www.doxygen.nl/). This tool can
generate PDF, HTML, and RTF documentation from the source code and supplemental markdown
files.

Also ensure the Linux installation is up-to-date and then install:

    sudo apt-get -y install make doxygen texlive texlive-latex-extra

Then change to the documentation directory (sm/doc) and execute the following:

    make <TARGET>

Where target can be html, rtf, latex, pdf, or clean. No target will result in building
all the documentation types. The output is written to the build directory (sm/doc/build)
in directories with the associated document type. The top level for the html output
is the index.html file.

Source Code Structure {#GUIDE_FILES}
=====================

Doxygen includes a [structured list of the files](files.html) documented using the
tool. This should include all headers that define public interfaces. The table below
adds information about the locations of files not covered in the doxygen list.

| Directory                | Contents                                                                  |
|--------------------------|---------------------------------------------------------------------------|
| boards/\<BOARD\>         | Board support files, included from the [config makefile](@ref MAKE_CONFIG)|
| CMSIS/Core               | [ARM CMSIS](https://arm-software.github.io/CMSIS_5/Core/html/index.html)  |
| components/\<COMPONENT\> | Generic SDK components (e.g. PMIC driver)                                 |
| configs/\<CONFIG\>       | [Configuration files](@ref CONFIG_FILES), make option config=\<CONFIG\>   |
| devices/\<DEVICE\>       | SoC support files, included from the [config makefile](@ref MAKE_CONFIG)  |
| drivers/\<DRIVER\>       | Generic SDK drivers, not SoC specific                                     |
| sm/boot                  | SM main() entrypoint for the SM                                           |
| sm/brd                   | SM common interface to the board                                          |
| sm/dev                   | SM common interface to the device                                         |
| sm/doc                   | SM [Documentation](@ref GUIDE_DOC)                                        |
| sm/lmm                   | SM [Logical Machine Manager](@ref LMM)                                    |
| sm/makefiles             | SM support makefiles included from other top-level makefiles              |
| sm/rpc                   | SM platform-side RPC modules (e.g. [SCMI](@ref RPC_SCMI), [SMT](@ref RPC_SMT)) |
| sm/test                  | SM [unit test code](@ref TEST)                                            |
| sm/utilities             | SM [utilities](@ref UTIL) and [debug monitor](@ref MONITOR)               |
| utilities/newlib         | GCC embedded C library                                                    |

