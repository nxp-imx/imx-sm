## ###################################################################
##
## Copyright 2024 NXP
##
## Detailed license terms of software usage can be found in the license.txt 
## file located in the root folder of this package. 
## ###################################################################

SAF_DIR = $(ROOT_DIR)/components/SAF
SAF_CFG_DIR = $(SAF_DIR)/devices/MIMX95

INCLUDE += \
	-I$(SAF_DIR)/eMcem/include  \
	-I$(SAF_DIR)/base/include  \
	-I$(SAF_DIR)/SafetyBase/include  \
	-I$(SAF_CFG_DIR)/include

VPATH += \
	$(SAF_DIR)/eMcem/src  \
	$(SAF_CFG_DIR)/src

OBJS += \
	$(OUT)/eMcem.o  \
	$(OUT)/eMcem_ExtDiagApi.o  \
	$(OUT)/eMcem_Vfccu.o  \
	$(OUT)/eMcem_Vfccu_MIMX95XX.o  \
	$(OUT)/eMcem_VfccuFaultList_MIMX95XX.o  \
	$(OUT)/eMcem_Lib_MIMX95XX.o \
	$(OUT)/eMcem_cVfccu_Irq.o  \
	$(OUT)/eMcem_Cfg.o

