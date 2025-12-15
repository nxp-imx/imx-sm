## ###################################################################
##
## Copyright 2026 NXP
##
## Detailed license terms of software usage can be found in the license.txt
## file located in the root folder of this package.
## ###################################################################

SAF_DIR = $(ROOT_DIR)/components/SAF
SAF_CFG_DIR = $(SAF_DIR)/devices/MIMX952

INCLUDE += \
	-I$(SAF_DIR)/eMcem/include  \
	-I$(SAF_DIR)/base/include  \
	-I$(SAF_DIR)/SafetyBase/include  \
	-I$(SAF_CFG_DIR)/include

VPATH += \
	$(SAF_DIR)/eMcem/src  \
	$(SAF_CFG_DIR)/src  \
	$(SAF_DIR)/stubs

OBJS += \
	$(OUT)/eMcem.o  \
	$(OUT)/eMcem_cVfccu_Irq.o  \
	$(OUT)/eMcem_Ddr.o  \
	$(OUT)/eMcem_DdrcChannels_MIMX9.o  \
	$(OUT)/eMcem_Eim.o  \
	$(OUT)/eMcem_EimChannels_MIMX952X.o  \
	$(OUT)/eMcem_Erm.o  \
	$(OUT)/eMcem_ErmApi.o  \
	$(OUT)/eMcem_ErmChannels_MIMX952X.o  \
	$(OUT)/eMcem_ExtDiagApi.o  \
	$(OUT)/eMcem_Lib_MIMX9.o \
	$(OUT)/eMcem_Sramc.o  \
	$(OUT)/eMcem_SramcAddrCalc_MIMX9.o  \
	$(OUT)/eMcem_SramcChannels_MIMX9.o  \
	$(OUT)/eMcem_TestApi.o  \
	$(OUT)/eMcem_Vfccu.o  \
	$(OUT)/eMcem_Vfccu_MIMX952X.o  \
	$(OUT)/eMcem_Cfg.o  \
	$(OUT)/eMcem_Stubs.o  \
	$(OUT)/sBase_Stubs.o

