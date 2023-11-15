## ###################################################################
##
## Copyright 2023 NXP
##
## Redistribution and use in source and binary forms, with or without modification,
## are permitted provided that the following conditions are met:
##
## o Redistributions of source code must retain the above copyright notice, this list
##   of conditions and the following disclaimer.
##
## o Redistributions in binary form must reproduce the above copyright notice, this
##   list of conditions and the following disclaimer in the documentation and/or
##   other materials provided with the distribution.
##
## o Neither the name of the copyright holder nor the names of its
##   contributors may be used to endorse or promote products derived from this
##   software without specific prior written permission.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
## ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
## WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
## DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
## ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
## (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
## LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
## ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
## SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
##
##
## ###################################################################

SOC = simu
DEV_SM_API_DIR = ./sm/dev
DEVICE_DIR = ./devices
SOC_DEVICE_DIR = $(DEVICE_DIR)/$(SOC)
DRIVER_DIR = ./drivers
COMPONENTS_DIR = ./components

INCLUDE += \
    -I$(DEV_SM_API_DIR)  \
	-I$(DEVICE_DIR)  \
	-I$(SOC_DEVICE_DIR)  \
	-I$(SOC_DEVICE_DIR)/sm \
	-I$(COMPONENTS_DIR)/crc

VPATH += \
	$(DEV_SM_API_DIR)  \
	$(DEVICE_DIR)  \
    $(SOC_DEVICE_DIR)  \
    $(SOC_DEVICE_DIR)/sm \
    $(COMPONENTS_DIR)/crc

SM_OBJS = \
	$(OUT)/dev_sm.o  \
	$(OUT)/dev_sm_common.o  \
	$(OUT)/dev_sm_config.o  \
	$(OUT)/dev_sm_power.o  \
	$(OUT)/dev_sm_system.o  \
	$(OUT)/dev_sm_perf.o  \
	$(OUT)/dev_sm_clock.o  \
	$(OUT)/dev_sm_sensor.o  \
	$(OUT)/dev_sm_reset.o  \
	$(OUT)/dev_sm_voltage.o  \
	$(OUT)/dev_sm_bbm.o  \
	$(OUT)/dev_sm_cpu.o  \
	$(OUT)/dev_sm_pin.o  \
	$(OUT)/dev_sm_control.o  \
	$(OUT)/dev_sm_rom.o  \
	$(OUT)/dev_sm_rdc.o \
	$(OUT)/dev_sm_fault.o  \
	$(OUT)/crc.o

TEST_INCLUDE += \
	-I$(COMPONENTS_DIR)/scmi  \
	-I$(COMPONENTS_DIR)/smt

TEST_VPATH += \
	$(COMPONENTS_DIR)/scmi  \
	$(COMPONENTS_DIR)/smt

TEST_OBJS += \
	$(OUT)/scmi.o  \
	$(OUT)/scmi_base.o  \
	$(OUT)/scmi_bbm.o  \
	$(OUT)/scmi_clock.o  \
	$(OUT)/scmi_cpu.o  \
	$(OUT)/scmi_fusa.o  \
	$(OUT)/scmi_lmm.o  \
	$(OUT)/scmi_misc.o  \
	$(OUT)/scmi_perf.o  \
	$(OUT)/scmi_pinctrl.o  \
	$(OUT)/scmi_power.o  \
	$(OUT)/scmi_reset.o  \
	$(OUT)/scmi_sensor.o  \
	$(OUT)/scmi_sys.o  \
	$(OUT)/scmi_voltage.o  \
	$(OUT)/smt.o

OBJS += $(SM_OBJS)

