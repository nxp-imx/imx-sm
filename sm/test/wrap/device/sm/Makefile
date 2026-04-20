## ###################################################################
##
## Copyright 2026 NXP
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

LFLAGS += \
	-Wl,--wrap=DEV_SM_BbmGetBootStatus \
	-Wl,--wrap=DEV_SM_BbmRtcNameGet \
	-Wl,--wrap=DEV_SM_BbmRtcStateGet \
	-Wl,--wrap=DEV_SM_ClockDescribe \
	-Wl,--wrap=DEV_SM_ClockNameGet \
	-Wl,--wrap=DEV_SM_ClockParentGet \
	-Wl,--wrap=DEV_SM_CpuIsActive \
	-Wl,--wrap=DEV_SM_CpuNameGet \
	-Wl,--wrap=DEV_SM_PerfNameGet \
	-Wl,--wrap=DEV_SM_PinNameGet \
	-Wl,--wrap=DEV_SM_PowerDomainNameGet \
	-Wl,--wrap=DEV_SM_ResetDomainNameGet \
	-Wl,--wrap=DEV_SM_RomContainerSet \
	-Wl,--wrap=DEV_SM_RomHandoverGet \
	-Wl,--wrap=DEV_SM_RomPassoverGet \
	-Wl,--wrap=DEV_SM_RomStageSet \
	-Wl,--wrap=DEV_SM_SensorNameGet \
	-Wl,--wrap=DEV_SM_SensorReadingGet \
	-Wl,--wrap=DEV_SM_SiInfoGet \
	-Wl,--wrap=DEV_SM_SyslogDump \
	-Wl,--wrap=DEV_SM_SyslogGet \
	-Wl,--wrap=DEV_SM_SystemShutdownRecSet \
	-Wl,--wrap=DEV_SM_VoltageNameGet \
	-Wl,--wrap=DEV_SM_SystemHalt \
	-Wl,--wrap=DEV_SM_FaultComplete

VPATH += \
	$(WRAP_DIR)/device/sm

OBJS += \
	$(OUT)/wrap_dev_sm_bbm.o \
	$(OUT)/wrap_dev_sm_clock.o \
	$(OUT)/wrap_dev_sm_common.o \
	$(OUT)/wrap_dev_sm_cpu.o \
	$(OUT)/wrap_dev_sm_perf.o \
	$(OUT)/wrap_dev_sm_pin.o \
	$(OUT)/wrap_dev_sm_power.o \
	$(OUT)/wrap_dev_sm_reset.o \
	$(OUT)/wrap_dev_sm_rom.o \
	$(OUT)/wrap_dev_sm_sensor.o \
	$(OUT)/wrap_dev_sm_system.o \
	$(OUT)/wrap_dev_sm_voltage.o \
	$(OUT)/wrap_dev_sm_fault.o

