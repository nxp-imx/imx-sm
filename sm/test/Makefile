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

TEST_DIR = $(ROOT_DIR)/sm/test

TEST_INCLUDE += \
	-I$(TEST_DIR)

TEST_VPATH += \
	$(TEST_DIR) $(TEST_DIR)/dev $(TEST_DIR)/dev_sm $(TEST_DIR)/scmi \
	$(TEST_DIR)/utilities $(TEST_DIR)/brd_sm $(TEST_DIR)/lmm \
	$(TEST_DIR)/sm

ifneq ($(T), NONE)
OBJS += \
	$(OUT)/test_$(T).o  \
	$(OUT)/test_config.o
endif

ifeq ($(T), all)
	OBJS += \
		$(OUT)/test_brd_sm_sensor.o     \
		$(OUT)/test_lmm_clock.o         \
		$(OUT)/test_lmm_perf.o          \
		$(OUT)/test_lmm_power.o         \
		$(OUT)/test_lmm_sys.o           \
		$(OUT)/test_lmm_cpu.o           \
		$(OUT)/test_lmm_voltage.o       \
		$(OUT)/test_dev_sm_power.o      \
		$(OUT)/test_dev_sm_sensor.o     \
		$(OUT)/test_dev_sm_voltage.o    \
		$(OUT)/test_dev_sm_perf.o       \
		$(OUT)/test_dev_sm_bbm.o        \
		$(OUT)/test_dev_sm_cpu.o        \
		$(OUT)/test_dev_sm_reset.o      \
		$(OUT)/test_dev_sm_clock.o      \
		$(OUT)/test_dev_sm_control.o    \
		$(OUT)/test_dev_sm_system.o     \
		$(OUT)/test_dev_sm_rdc.o        \
		$(OUT)/test_dev_sm_pin.o        \
		$(OUT)/test_dev_sm.o            \
		$(OUT)/test_scmi.o              \
		$(OUT)/test_scmi_base.o         \
		$(OUT)/test_scmi_power.o        \
		$(OUT)/test_scmi_system.o       \
		$(OUT)/test_scmi_perf.o         \
		$(OUT)/test_scmi_clock.o        \
		$(OUT)/test_scmi_cpu.o          \
		$(OUT)/test_scmi_sensor.o       \
		$(OUT)/test_scmi_reset.o        \
		$(OUT)/test_scmi_voltage.o      \
		$(OUT)/test_scmi_pinctrl.o      \
		$(OUT)/test_scmi_lmm.o          \
		$(OUT)/test_scmi_bbm_gpr.o      \
		$(OUT)/test_scmi_bbm_rtc.o      \
		$(OUT)/test_scmi_bbm_button.o   \
		$(OUT)/test_scmi_fusa.o         \
		$(OUT)/test_scmi_misc.o         \
		$(OUT)/test_utilities_config.o
endif

