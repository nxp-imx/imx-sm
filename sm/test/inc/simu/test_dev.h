/*
** ###################################################################
**
** Copyright 2024-2026 NXP
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** o Redistributions of source code must retain the above copyright notice, this list
**   of conditions and the following disclaimer.
**
** o Redistributions in binary form must reproduce the above copyright notice, this
**   list of conditions and the following disclaimer in the documentation and/or
**   other materials provided with the distribution.
**
** o Neither the name of the copyright holder nor the names of its
**   contributors may be used to endorse or promote products derived from this
**   software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
** ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
** ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

#ifndef TEST_DEV_H
#define TEST_DEV_H

/* Includes */

/* Defines */

#define ROM_CONTAINER_1                 0x0U
#define ROM_CONTAINER_2                 0x1U

#define DEV_SM_CPU_TEST                 DEV_SM_CPU_0
#define DEV_SM_CPU_SYS_TEST             DEV_SM_CPU_2
#define DEV_SM_PLAT_TEST                DEV_SM_CPU_8
#define DEV_SM_TEST_SRC_MIX             3U

#define FUSA_LM_SAFE_TYPE_ERROR         3U
#define FUSA_LM_ACCESS_DENIED           7U
#define DEV_SM_FAULT_TEST_0             3U
#define MAX_MISC_BRD_CTRL_ID            0x8005

#define DEV_SM_SENSOR_TEMP_ANA          DEV_SM_SENSOR_0   /*!< ANA sensor */
#define DEV_SM_SENSOR_TEMP_A55          DEV_SM_SENSOR_1   /*!< CA55 sensor */
#define SM_NUM_THRESHOLDS               3U
#define SM_NUM_EVENTCONTROLS            6U
#define DEV_SM_PERF_DEFAULT             DEV_SM_PERF_0

#define BRD_SM_CONTROL_COMMON           BRD_SM_CTRL_0
#define BRD_SM_CTRL_EXT_TEST            BRD_SM_CTRL_TEST_E
#define SENSOR_0                        DEV_SM_SENSOR_0


#define FAULT_SET_TEST_0                DEV_SM_FAULT_0
#define FAULT_SET_TEST_1                DEV_SM_FAULT_1
#define FAULT_SET_TEST_2                DEV_SM_FAULT_2
#define FAULT_SET_TEST_3                DEV_SM_FAULT_3
#define FAULT_SET_TEST_4                DEV_SM_FAULT_4
#define FAULT_SET_TEST_5                DEV_SM_FAULT_5
#define FAULT_SET_TEST_6                DEV_SM_FAULT_6
#define FAULT_SET_TEST_7                DEV_SM_FAULT_7
#define FAULT_SET_TEST_8                DEV_SM_FAULT_8
#define FAULT_SET_TEST_9                DEV_SM_FAULT_9
#define FAULT_SET_TEST_10               DEV_SM_FAULT_10

#define FAULT_SET_TEST_START            FAULT_SET_TEST_0
#define FAULT_SET_TEST_END              FAULT_SET_TEST_10

#define FAULT_0                         DEV_SM_FAULT_0
#define FAULT_1                         DEV_SM_FAULT_1
#define FAULT_2                         DEV_SM_FAULT_2
#define FAULT_3                         DEV_SM_FAULT_3
#define FAULT_4                         DEV_SM_FAULT_4
#define FAULT_5                         DEV_SM_FAULT_5
#define FAULT_6                         DEV_SM_FAULT_6
#define FAULT_7                         DEV_SM_FAULT_7
#define FAULT_8                         DEV_SM_FAULT_8

#define DEV_SM_FAULT_STATE_TEST         DEV_SM_FAULT_6

#define DEV_SM_REASON_TEST              DEV_SM_REASON_FAULT
#define DEV_SM_DAISY_TEST               0U

#define DEV_SM_TEST_CPU                 DEV_SM_CPU_0
#define DEV_SM_SYS_TEST_CPU             DEV_SM_CPU_2

#define DEV_SM_TEST_NUM_SLEEP_MODE      5U

#define CPU_TEST_PERCONFIGS_VAL         SM_NUM_PERLPI

#define DEV_SM_TEST_REASON_UNUSED       DEV_SM_REASON_SW

#define TEST_SSC_CLOCK                  DEV_SM_CLK_SRC_5
#define TEST_RESERVED_CLK               DEV_SM_CLK_4

#define DEV_SM_PD_TEST_0                DEV_SM_PD_0
#define DEV_SM_PD_TEST_1                DEV_SM_PD_1
#define DEV_SM_PD_TEST_2                DEV_SM_PD_2
#define DEV_SM_PD_TEST_3                DEV_SM_PD_3
#define DEV_SM_PD_TEST_4                DEV_SM_PD_4
#define DEV_SM_PD_TEST_5                DEV_SM_PD_5
#define DEV_SM_PD_TEST_6                DEV_SM_PD_6

#define TEST_CPU_ID                     1U
#define TEST_RESET_VECTOR_VAL           0x12345678UL

#define INVALID_CPU_ID_TEST             0xFU

#define SYSTEM_IDLE_HALT_TEST

/* Local defines */

/* Types */

#endif /* TEST_DEV_H */

