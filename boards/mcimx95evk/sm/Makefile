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

BOARD ?= mcimx95evk
BRD_SM_API_DIR = $(ROOT_DIR)/sm/brd
BOARDS_DIR = $(ROOT_DIR)/boards
BOARD_DIR = $(BOARDS_DIR)/$(BOARD)

INCLUDE +=  \
	-I$(BRD_SM_API_DIR)  \
	-I$(BOARDS_DIR)  \
	-I$(BOARD_DIR)  \
	-I$(BOARD_DIR)/sm \
	-I$(COMPONENTS_DIR)/pcal6408a  \
	-I$(COMPONENTS_DIR)/pf09  \
	-I$(COMPONENTS_DIR)/pf53

VPATH +=  \
	$(BRD_SM_API_DIR)  \
	$(BOARDS_DIR)  \
	$(BOARD_DIR)  \
	$(BOARD_DIR)/sm  \
	$(COMPONENTS_DIR)/pcal6408a  \
	$(COMPONENTS_DIR)/pf09  \
	$(COMPONENTS_DIR)/pf53

OBJS += \
	$(OUT)/board.o  \
	$(OUT)/brd_sm.o  \
	$(OUT)/brd_sm_handlers.o  \
	$(OUT)/brd_sm_control.o  \
	$(OUT)/brd_sm_sensor.o  \
	$(OUT)/brd_sm_voltage.o  \
	$(OUT)/fsl_pcal6408a.o  \
	$(OUT)/fsl_pf09.o  \
	$(OUT)/fsl_pf53.o

