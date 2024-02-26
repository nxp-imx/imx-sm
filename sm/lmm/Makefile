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

LMM_DIR = $(ROOT_DIR)/sm/lmm

INCLUDE += \
	-I$(LMM_DIR)

VPATH += \
	$(LMM_DIR)

OBJS += \
	$(OUT)/lmm.o  \
	$(OUT)/lmm_clock.o  \
	$(OUT)/lmm_config.o  \
	$(OUT)/lmm_perf.o  \
	$(OUT)/lmm_power.o  \
	$(OUT)/lmm_sys.o  \
	$(OUT)/lmm_sensor.o  \
	$(OUT)/lmm_reset.o  \
	$(OUT)/lmm_voltage.o  \
	$(OUT)/lmm_bbm.o  \
	$(OUT)/lmm_cpu.o  \
	$(OUT)/lmm_misc.o  \
	$(OUT)/lmm_fault.o

ifeq ($(USES_FUSA),1)
OBJS += \
	$(OUT)/lmm_fusa.o
endif

