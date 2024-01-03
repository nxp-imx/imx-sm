## ###################################################################
##
## Copyright 2023-2024 NXP
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

SERIES = MIMX9
SOC = MIMX95
SOCFULL = $(SOC)
DEV_SM_API_DIR = $(ROOT_DIR)/sm/dev
CMSIS_DIR = $(ROOT_DIR)/CMSIS
DEVICE_DIR = $(ROOT_DIR)/devices
SERIES_DEVICE_DIR = $(DEVICE_DIR)/$(SERIES)
SOC_DEVICE_DIR = $(DEVICE_DIR)/$(SOC)
DRIVER_DIR = $(ROOT_DIR)/drivers
COMPONENTS_DIR = $(ROOT_DIR)/components
cpu = m33

INCLUDE += \
    -I$(DEV_SM_API_DIR)  \
	-I$(CMSIS_DIR)/Core/Include  \
	-I$(DEVICE_DIR)  \
	-I$(SERIES_DEVICE_DIR)  \
	-I$(SERIES_DEVICE_DIR)/drivers  \
	-I$(SOC_DEVICE_DIR)  \
	-I$(SOC_DEVICE_DIR)/drivers  \
	-I$(SOC_DEVICE_DIR)/sm  \
	-I$(DRIVER_DIR)/common  \
	-I$(DRIVER_DIR)/bbnsm  \
	-I$(DRIVER_DIR)/ele  \
	-I$(DRIVER_DIR)/lpi2c  \
	-I$(DRIVER_DIR)/lpuart  \
	-I$(DRIVER_DIR)/mu1  \
	-I$(DRIVER_DIR)/rgpio  \
	-I$(DRIVER_DIR)/sysctr  \
	-I$(DRIVER_DIR)/systick  \
	-I$(DRIVER_DIR)/tmpsns  \
	-I$(DRIVER_DIR)/wdog32 \
	-I$(DRIVER_DIR)/cache/xcache \
	-I$(COMPONENTS_DIR)/crc

VPATH += \
	$(DEV_SM_API_DIR)  \
	$(DEVICE_DIR)  \
    $(SERIES_DEVICE_DIR)  \
    $(SERIES_DEVICE_DIR)/drivers  \
    $(SOC_DEVICE_DIR)  \
    $(SOC_DEVICE_DIR)/drivers  \
    $(SOC_DEVICE_DIR)/sm  \
    $(SOC_DEVICE_DIR)/$(cc)  \
    $(DRIVER_DIR)/bbnsm  \
    $(DRIVER_DIR)/ele  \
    $(DRIVER_DIR)/lpi2c  \
    $(DRIVER_DIR)/lpuart  \
    $(DRIVER_DIR)/mu1  \
    $(DRIVER_DIR)/rgpio  \
    $(DRIVER_DIR)/sysctr  \
    $(DRIVER_DIR)/systick  \
    $(DRIVER_DIR)/tmpsns  \
    $(DRIVER_DIR)/wdog32 \
    $(DRIVER_DIR)/cache/xcache \
    $(COMPONENTS_DIR)/crc

SDK_OBJS = \
	$(OUT)/system_$(SOC)_c$(cpu).o  \
	$(OUT)/startup_$(SOC)_c$(cpu).o  \
	$(OUT)/hardware_init.o  \
	$(OUT)/pin_mux.o  \
	$(OUT)/fsl_ccm.o  \
	$(OUT)/fsl_clock.o  \
	$(OUT)/fsl_cpu.o  \
	$(OUT)/fsl_bbnsm.o  \
	$(OUT)/fsl_ele.o  \
	$(OUT)/fsl_fract_pll.o  \
	$(OUT)/fsl_lpi2c.o  \
	$(OUT)/fsl_lpuart.o  \
	$(OUT)/fsl_mu.o  \
	$(OUT)/fsl_rgpio.o  \
	$(OUT)/fsl_power.o  \
	$(OUT)/fsl_reset.o  \
	$(OUT)/fsl_src.o  \
	$(OUT)/fsl_sysctr.o  \
	$(OUT)/fsl_systick.o  \
	$(OUT)/fsl_tmpsns.o  \
	$(OUT)/fsl_wdog32.o \
	$(OUT)/fsl_cache.o \
	$(OUT)/crc.o

SM_OBJS = \
	$(OUT)/dev_sm.o  \
	$(OUT)/dev_sm_common.o  \
	$(OUT)/dev_sm_handlers.o  \
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
	$(OUT)/dev_sm_rdc.o  \
	$(OUT)/dev_sm_fault.o

ROM_OBJS = \
	$(OUT)/rom_$(SOC)_c$(cpu).o

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
	$(OUT)/scmi_sensor.o  \
	$(OUT)/scmi_sys.o  \
	$(OUT)/scmi_reset.o  \
	$(OUT)/scmi_voltage.o  \
	$(OUT)/smt.o

OBJS += $(SDK_OBJS) $(SM_OBJS)

ifndef SAF_CFG_DIR
    include $(COMPONENTS_DIR)/SAF/devices/$(SOC)/Makefile
endif

