/*
** ###################################################################
**
** Copyright 2023-2024 NXP
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

/*==========================================================================*/
/*!
 * @addtogroup CONFIG_SIMU
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing coniguration info for the logical machine manager.
 */
/*==========================================================================*/

#ifndef CONFIG_LMM_H
#define CONFIG_LMM_H

/* Defines */

/*--------------------------------------------------------------------------*/
/* LM0 Config (SM)                                                          */
/*--------------------------------------------------------------------------*/

/*! Config for LM0 */
#define SM_LM0_CONFIG \
    { \
        .name = "SM", \
        .rpcType = SM_RPC_NONE, \
        .boot[0] = 1U, \
        .safeType = LMM_SAFE_TYPE_FEENV, \
    }

/*--------------------------------------------------------------------------*/
/* LM1 Config (M7)                                                          */
/*--------------------------------------------------------------------------*/

/*! Config for LM1 */
#define SM_LM1_CONFIG \
    { \
        .name = "M7", \
        .rpcType = SM_RPC_SCMI, \
        .rpcInst = 0U, \
        .boot[0] = 2U, \
        .safeType = LMM_SAFE_TYPE_SEENV, \
        .start = 1U, \
        .stop = 1U, \
    }

/*--------------------------------------------------------------------------*/
/* LM2 Config (AP)                                                          */
/*--------------------------------------------------------------------------*/

/*! Config for LM2 */
#define SM_LM2_CONFIG \
    { \
        .name = "AP", \
        .rpcType = SM_RPC_SCMI, \
        .rpcInst = 1U, \
        .boot[0] = 3U, \
        .safeType = LMM_SAFE_TYPE_SEENV, \
        .start = 5U, \
        .stop = 5U, \
    }

/*--------------------------------------------------------------------------*/
/* LM3 Config (TEST)                                                        */
/*--------------------------------------------------------------------------*/

/*! Config for LM3 */
#define SM_LM3_CONFIG \
    { \
        .name = "TEST", \
        .rpcType = SM_RPC_SCMI, \
        .rpcInst = 2U, \
        .boot[0] = 4U, \
        .safeType = LMM_SAFE_TYPE_SEENV, \
    }

/*--------------------------------------------------------------------------*/
/* LM Config                                                                */
/*--------------------------------------------------------------------------*/

/*! Config for number of LM */
#define SM_NUM_LM  4U

/*! Config data array for LM */
#define SM_LM_CONFIG_DATA \
    SM_LM0_CONFIG, \
    SM_LM1_CONFIG, \
    SM_LM2_CONFIG, \
    SM_LM3_CONFIG

/*! Number of  mSel */
#define SM_LM_NUM_MSEL  1U

/*! Number of  S-EENV */
#define SM_LM_NUM_SEENV  4U

/*! Config name */
#define SM_LM_CFG_NAME  "simu"

/*! Default LM for monitor */
#define SM_LM_DEFAULT  3U

/*--------------------------------------------------------------------------*/
/* LM Start/Stop Lists                                                      */
/*--------------------------------------------------------------------------*/

/*! Config for number of start */
#define SM_LM_NUM_START  7U

/*! LM start list */
#define SM_LM_START_DATA \
    {.lmId = 1U, .mSel = 0U, .ss = LMM_SS_PD, .rsrc = DEV_SM_PD_4}, \
    {.lmId = 1U, .mSel = 0U, .ss = LMM_SS_CLK, .rsrc = DEV_SM_CLK_1}, \
    {.lmId = 1U, .mSel = 0U, .ss = LMM_SS_CPU, .rsrc = DEV_SM_CPU_1}, \
    {.lmId = 1U, .mSel = 0U, .ss = LMM_SS_VOLT, .rsrc = DEV_SM_VOLT_1}, \
    {.lmId = 2U, .mSel = 0U, .ss = LMM_SS_PD, .rsrc = DEV_SM_PD_2}, \
    {.lmId = 2U, .mSel = 0U, .ss = LMM_SS_PERF, .rsrc = DEV_SM_PERF_0, \
     .numArg = 1, .arg[0] = 3U,}, \
    {.lmId = 2U, .mSel = 0U, .ss = LMM_SS_CPU, .rsrc = DEV_SM_CPU_2},

/*! Config for number of stop */
#define SM_LM_NUM_STOP  7U

/*! LM stop list */
#define SM_LM_STOP_DATA \
    {.lmId = 1U, .mSel = 0U, .ss = LMM_SS_CLK, .rsrc = DEV_SM_CLK_1}, \
    {.lmId = 1U, .mSel = 0U, .ss = LMM_SS_CPU, .rsrc = DEV_SM_CPU_1}, \
    {.lmId = 1U, .mSel = 0U, .ss = LMM_SS_VOLT, .rsrc = DEV_SM_VOLT_1}, \
    {.lmId = 1U, .mSel = 0U, .ss = LMM_SS_PD, .rsrc = DEV_SM_PD_4}, \
    {.lmId = 2U, .mSel = 0U, .ss = LMM_SS_CPU, .rsrc = DEV_SM_CPU_2}, \
    {.lmId = 2U, .mSel = 0U, .ss = LMM_SS_PD, .rsrc = DEV_SM_PD_2}, \
    {.lmId = 2U, .mSel = 0U, .ss = LMM_SS_PERF, .rsrc = DEV_SM_PERF_0},

/*--------------------------------------------------------------------------*/
/* LM Fault Lists                                                           */
/*--------------------------------------------------------------------------*/

/*! LM fault reactions */
#define SM_LM_FAULT_DATA \
    [DEV_SM_FAULT_0] = {.reaction = LMM_REACT_SYS_RESET, .lm = 0U}, \
    [DEV_SM_FAULT_1] = {.reaction = LMM_REACT_SYS_SHUTDOWN, .lm = 0U}, \
    [DEV_SM_FAULT_8] = {.reaction = LMM_REACT_GRP_RESET, .lm = 0U}, \
    [DEV_SM_FAULT_9] = {.reaction = LMM_REACT_GRP_SHUTDOWN, .lm = 0U}, \
    [DEV_SM_FAULT_10] = {.reaction = LMM_REACT_BOARD, .lm = 0U}, \
    [DEV_SM_FAULT_2] = {.reaction = LMM_REACT_LM_RESET, .lm = 1U}, \
    [DEV_SM_FAULT_3] = {.reaction = LMM_REACT_LM_SHUTDOWN, .lm = 1U}, \
    [DEV_SM_FAULT_6] = {.reaction = LMM_REACT_FUSA, .lm = 1U}, \
    [DEV_SM_FAULT_7] = {.reaction = LMM_REACT_NONE, .lm = 1U}, \
    [DEV_SM_FAULT_4] = {.reaction = LMM_REACT_LM_RESET, .lm = 2U}, \
    [DEV_SM_FAULT_5] = {.reaction = LMM_REACT_LM_SHUTDOWN, .lm = 2U},

#endif /* CONFIG_LMM_H */

/** @} */

