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
	-Wl,--wrap=LMM_BbmRtcTimeSet \
	-Wl,--wrap=LMM_BootTimeGet \
	-Wl,--wrap=LMM_ClockEnable \
	-Wl,--wrap=LMM_ClockExtendedGet \
	-Wl,--wrap=LMM_ClockExtendedSet \
	-Wl,--wrap=LMM_CpuBootCheck \
	-Wl,--wrap=LMM_CpuHold \
	-Wl,--wrap=LMM_CpuPdLpmConfigSet \
	-Wl,--wrap=LMM_CpuResetVectorSet \
	-Wl,--wrap=LMM_CpuStart \
	-Wl,--wrap=LMM_CpuStop \
	-Wl,--wrap=LMM_LmNameGet \
	-Wl,--wrap=LMM_MiscControlFlagsSet \
	-Wl,--wrap=LMM_PerfLevelSet \
	-Wl,--wrap=LMM_PowerStateSet \
	-Wl,--wrap=LMM_SensorEnable \
	-Wl,--wrap=LMM_SystemGrpBoot \
	-Wl,--wrap=LMM_SystemGrpReset \
	-Wl,--wrap=LMM_SystemGrpShutdown \
	-Wl,--wrap=LMM_SystemLmBoot \
	-Wl,--wrap=LMM_SystemLmCheck \
	-Wl,--wrap=LMM_SystemLmPowerOn \
	-Wl,--wrap=LMM_SystemLmReset \
	-Wl,--wrap=LMM_SystemLmShutdown \
	-Wl,--wrap=LMM_SystemLmSuspend \
	-Wl,--wrap=LMM_SystemLmWake \
	-Wl,--wrap=LMM_SystemShutdown \
	-Wl,--wrap=LMM_SystemSleepModeSet \
	-Wl,--wrap=LMM_SystemSuspend \
	-Wl,--wrap=LMM_SystemWake \
	-Wl,--wrap=LMM_VoltageModeSet \
	-Wl,--wrap=LM_SystemLmReason \
	-Wl,--wrap=LM_SystemLmStatus

VPATH += \
	$(WRAP_DIR)/lmm

OBJS += \
	$(OUT)/wrap_lmm.o \
	$(OUT)/wrap_lmm_bbm.o \
	$(OUT)/wrap_lmm_clock.o \
	$(OUT)/wrap_lmm_cpu.o \
	$(OUT)/wrap_lmm_misc.o \
	$(OUT)/wrap_lmm_perf.o \
	$(OUT)/wrap_lmm_power.o \
	$(OUT)/wrap_lmm_sensor.o \
	$(OUT)/wrap_lmm_sys.o \
	$(OUT)/wrap_lmm_voltage.o

