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

SCMI_DIR = $(ROOT_DIR)/sm/rpc/scmi

INCLUDE += \
	-I$(SCMI_DIR)

VPATH += \
	$(SCMI_DIR)

OBJS += \
	$(OUT)/rpc_scmi.o  \
	$(OUT)/rpc_scmi_base.o  \
	$(OUT)/rpc_scmi_bbm.o  \
	$(OUT)/rpc_scmi_clock.o  \
	$(OUT)/rpc_scmi_config.o  \
	$(OUT)/rpc_scmi_cpu.o  \
	$(OUT)/rpc_scmi_lmm.o  \
	$(OUT)/rpc_scmi_misc.o  \
	$(OUT)/rpc_scmi_perf.o  \
	$(OUT)/rpc_scmi_pinctrl.o  \
	$(OUT)/rpc_scmi_power.o  \
	$(OUT)/rpc_scmi_sensor.o  \
	$(OUT)/rpc_scmi_reset.o  \
	$(OUT)/rpc_scmi_sys.o  \
	$(OUT)/rpc_scmi_voltage.o

ifeq ($(USES_FUSA),1)
OBJS += \
	$(OUT)/rpc_scmi_fusa.o
endif

