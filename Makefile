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

# SM root directory
ROOT_DIR ?= .

# Configure verbose logging
ifdef v
    V := $(v)
endif
ifeq ($(V),1)
    AT :=
else
    AT := @
endif
export AT

# Configure tests
ifdef t
    T := $(t)
endif
ifndef T
    T := NONE
	FLAGS += -DLMM_INIT_FLAGS=1
else
	FLAGS += -DLMM_INIT_FLAGS=0 -DRUN_TEST
	DEBUG ?= 1
	INC_LIBC ?= 1
endif
ifeq ($(T),all)
	FLAGS += -DTEST_ALL
	M ?= 0
endif
UTEST := $(shell echo $(T) | sed -r "s/(\<|_)([[:alnum:]])/\U\2/g")
FLAGS += -DTEST=TEST_$(UTEST)

# Configure monitor
ifdef m
    M := $(m)
endif
M ?= 1
ifneq ($(M),0)
	FLAGS += -DMONITOR
	INC_LIBC ?= 1
endif
INC_LIBC ?= 0
DEBUG ?= 0
FLAGS += -DMONITOR_MODE=$(M)

ifeq ($(DEBUG),1)
    FLAGS += -DDEBUG
endif

ifeq ($(INC_LIBC),1)
    FLAGS += -DINC_LIBC
endif

# Configure RDC
ifdef r
    R := $(r)
endif
R ?= 1
ifeq ($(R),1)
	FLAGS += -DRDC
endif

# Configure config
ifdef config
    CONFIG := $(config)
endif

# Default to MX95 EVK
CONFIG ?= mx95evk

# Configure output
BUILD = $(ROOT_DIR)/build
OUT = $(ROOT_DIR)/$(BUILD)/$(CONFIG)
INCLUDE = -I$(OUT)

# Include configuration specific make info
-include $(ROOT_DIR)/configs/$(CONFIG)/config.mak

# Defaults
ROM_IMG ?= none
USES_FUSA ?= 0

ifeq ($(USES_FUSA),1)
	FLAGS += -DUSES_FUSA
endif

INCLUDE += -I$(ROOT_DIR)/configs/$(CONFIG)

# Include boot
include $(ROOT_DIR)/sm/boot/Makefile

# Include config utilities
include $(ROOT_DIR)/sm/utilities/config/Makefile

# Include monitor
ifneq ($(M),0)
	include $(ROOT_DIR)/sm/utilities/monitor/Makefile
endif

# Include tests
ifneq ($(T),NONE)
	include $(ROOT_DIR)/sm/test/Makefile
endif

ifneq ($(SOC),simu)
    OBJS += $(HW_OBJS)
endif

ifneq ($(T), NONE)
	INCLUDE += $(TEST_INCLUDE)
	VPATH += $(TEST_VPATH)
	OBJS += $(TEST_OBJS)
endif

ifeq ($(BUILD_ROM), 1)
	TARGETS = $(OUT)/$(TARGET) $(OUT)/$(ROM_TARGET)
else
	TARGETS = $(OUT)/$(TARGET)
endif

ifeq ($(BUILD_EMU), 1)
	FLAGS += -DBUILD_EMU
endif

img : cfg.exists $(TARGETS)

all: clean img

.SUFFIXES :

DEPS := $(OBJS:.o=.d)

-include $(DEPS)

cfg.exists:
	@if [ ! -d "$(ROOT_DIR)/configs/$(CONFIG)" ]; then (echo "Incorrect/missing $(CONFIG) config"; exit 1); fi

$(OUT)/%.o : %.c $(OUT)/build_info.h
	@echo "Compiling $<"
	$(AT)mkdir -p $(dir $@)
	$(AT)${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

$(OUT)/%.o : %.S
	@echo "Assembling $<"
	$(AT)mkdir -p $(dir $@)
	$(AT)${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

$(OUT)/$(IMG) : $(OBJS)
	@echo "Linking $@ ...."
	$(AT)$(LD) -o $@ $(OBJS) $(LFLAGS) 

$(OUT)/$(IMG).elf : $(OBJS)
	@echo "Linking $@ ...."
	$(AT)$(LD) -o $@ $(OBJS) $(LFLAGS)
	$(AT)$(OBJCOPY) -O binary --gap-fill 0x0 $(OUT)/$(IMG).elf $(OUT)/$(IMG).bin --strip-debug
	$(AT)$(SIZE) $(OUT)/$(IMG).elf

$(OUT)/$(IMG).srec : $(OUT)/$(IMG).elf
	@echo "Generating srec $@ ...."
	$(AT)$(OBJCOPY) -O srec --gap-fill 0x0 --pad-to 0x10000 $(OUT)/$(IMG).elf $(OUT)/$(IMG).srec --strip-debug

$(OUT)/$(IMG).hex : $(OUT)/$(IMG).srec
	@echo "Generating hex $@ ...."
	$(AT)$(SREC_CAT) $(OUT)/$(IMG).srec -byte_swap 4 -crop 0x00000000 0xffffffff $(SREC_CAT_IMG_FLAGS) -output $(OUT)/$(IMG).hex -vmem 32

$(OUT)/$(ROM_IMG) : $(ROM_OBJS)
	@echo "Linking $@ ...."
	$(AT)$(LD) -o $@ $(OBJS) $(LFLAGS) 

$(OUT)/$(ROM_IMG).elf : $(ROM_OBJS)
	@echo "Linking $@ ...."
	$(AT)$(LD) -o $@ $(ROM_OBJS) $(ROM_LFLAGS)
	$(AT)$(OBJCOPY) -O binary --gap-fill 0x0 $(OUT)/$(ROM_IMG).elf $(OUT)/$(ROM_IMG).bin --strip-debug
	$(AT)$(SIZE) $(OUT)/$(ROM_IMG).elf

$(OUT)/$(ROM_IMG).srec : $(OUT)/$(ROM_IMG).elf
	@echo "Generating srec $@ ...."
	$(AT)$(OBJCOPY) -O srec --gap-fill 0x0 --pad-to 0x10000 $(OUT)/$(ROM_IMG).elf $(OUT)/$(ROM_IMG).srec --strip-debug

$(OUT)/$(ROM_IMG).hex : $(OUT)/$(ROM_IMG).srec
	@echo "Generating hex $@ ...."
	$(AT)$(SREC_CAT) $(OUT)/$(ROM_IMG).srec -byte_swap 4 -crop 0x00000000 0xffffffff $(SREC_CAT_ROM_FLAGS) -output $(OUT)/$(ROM_IMG).hex -vmem 32

clean:
	@echo "Cleaning ...."
	$(AT)rm -f $(OUT)/*

really-clean:
	@echo "Cleaning ...."
	$(AT)rm -rf $(BUILD)
	$(AT)rm -f sm/doc/build_info

include ./sm/makefiles/build_info.mak
include ./sm/makefiles/configtool.mak
include ./sm/makefiles/cppcheck.mak

