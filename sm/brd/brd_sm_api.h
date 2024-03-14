/*
** ###################################################################
**
** Copyright 2023 NXP
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
 * @addtogroup BRD_SM_API
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the SM abstraction of the board.
 */
/*==========================================================================*/

#ifndef BRD_SM_API_H
#define BRD_SM_API_H

/* Includes */

#include "sm.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * @name Board module functions
 * @{
 */

/*!
 * Board initialization.
 *
 * This function initializes the board.
 *
 * @param[in]     argc  Number of arguments
 * @param[in]     argv  Array of arguments
 * @param[in,out] mSel  Pointer to return the boot mode selection
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
// coverity[misra_c_2012_directive_4_6_violation:FALSE]
int32_t BRD_SM_Init(int argc, const char * const argv[], uint32_t *mSel);

/*!
 * Board exit.
 *
 * @param[in]     status        Exit status
 * @param[in]     pc            PC of calling function
 *
 * This is the general exit function for the SM. Would normally be
 * implemented to result in a fault/reboot.
 */
void BRD_SM_Exit(int32_t status, uint32_t pc);

/*!
 * Board timer tick.
 *
 * @param[in]     msec          Period in milliseconds
 *
 * This function is called periodically by a timer.
 */
void BRD_SM_TimerTick(uint32_t msec);

/*!
 * Board custom function. Called from the debug monitor.
 *
 * Called from the debug monitor.
 *
 * @param[in]     argc          Argument count
 * @param[in]     argv          Array of arguments
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t BRD_SM_Custom(int32_t argc, const char * const argv[]);

/*!
 * Get board override of fault reaction.
 *
 * @param[in]     resetRec      Reset record
 * @param[in,out] reaction      Fault reaction
 * @param[in,out] lm            Target LM
 *
 * Allows the board code to override the configured fault reaction.
 * Can also be used to print/log the reaction info.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t BRD_SM_FaultReactionGet(dev_sm_rst_rec_t resetRec,
    uint32_t *reaction, uint32_t *lm);

/*!
 * Get board override of fault reaction.
 *
 * @param[in]     resetRec      Reset record
 * @param[in]     lm            Target LM
 *
 * Allows the board code to handle a fault in a custom way. Called
 * if the fault reaction is ::LMM_REACT_BOARD.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t BRD_SM_CustomFault(dev_sm_rst_rec_t resetRec, uint32_t lm);

/*!
 * Print a reset record.
 *
 * @param[in]     name          Prepended name
 * @param[in]     resetRec      Reset record
 *
 * Print a reset record for debug.
 */
void BRD_SM_ResetRecordPrint(string name, dev_sm_rst_rec_t resetRec);

/*!
 * Load shutdown record.
 *
 * @param[out]    shutdownRec   Pointer to record to load
 *
 * Load a shutdown record from persistent storage.
 */
void BRD_SM_ShutdownRecordLoad(dev_sm_rst_rec_t *shutdownRec);

/*!
 * Store a shutdown record.
 *
 * @param[in]     shutdownRec   Record to save
 *
 * Save a shutdown record to persistent storage.
 */
void BRD_SM_ShutdownRecordSave(dev_sm_rst_rec_t shutdownRec);

#ifdef BOARD_HAS_PMIC

/*!
 * Get PMIC info
 *
 * @param[in]     idx      PMIC index.
 * @param[in]     devAddr  Return PMIC I2C address.
 * @param[out]    info     Pointer to return PMIC info.
 * @param[out]    len      Pointer to return the info size.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t BRD_SM_PmicInfoGet(uint32_t idx, uint8_t *devAddr, uint8_t **info,
    uint8_t *len);

/*!
 * Write a PMIC register
 *
 * @param[in]     devAddr  I2C address of the PMIC.
 * @param[in]     regAddr  Register address.
 * @param[in]     val      Value to write.
 * @param[in]     mask     Mask for RMW.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t BRD_SM_PmicWrite(uint8_t devAddr, uint8_t regAddr, uint8_t val,
    uint8_t mask);

/*!
 * Read a PMIC register
 *
 * @param[in]     devAddr  I2C address of the PMIC.
 * @param[in]     regAddr  Register address.
 * @param[out]    val      Pointer to return value.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t BRD_SM_PmicRead(uint8_t devAddr, uint8_t regAddr, uint8_t *val);

#endif

/*!
 * Set a SoC supply mode.
 *
 * @param[in]     domain        Identifier for the voltage domain
 * @param[in]     voltMode      Voltage mode to set
 *
 * This function allows the caller to set the current mode of
 * a SoC supply.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_HARDWARE_ERROR: if there is an issue setting the mode.
 */
int32_t BRD_SM_SupplyModeSet(uint32_t domain, uint8_t voltMode);

/*!
 * Get a SoC supply mode.
 *
 * @param[in]     domain        Identifier for the voltage domain
 * @param[out]    voltMode      Pointer to return the voltage mode
 *
 * This function allows the caller to request the current mode of
 * a Soc supply.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_HARDWARE_ERROR: if there is an issue getting the mode.
 */
int32_t BRD_SM_SupplyModeGet(uint32_t domain, uint8_t *voltMode);

/*!
 * Set a SoC supply voltage.
 *
 * @param[in]     domain        Identifier for the voltage domain
 * @param[in]     microVolt     Voltage level to set in uV
 *
 * This function allows the caller to set the current level of
 * a SoC supply.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_HARDWARE_ERROR: if there is an issue setting the voltage.
 */
int32_t BRD_SM_SupplyLevelSet(uint32_t domain, uint32_t microVolt);

/*!
 * Get a SoC supply voltage.
 *
 * @param[in]     domain        Identifier for the voltage domain
 * @param[out]    microVolt     Pointer to return the voltage level
 *
 * This function allows the caller to request the current level of
 * a Soc supply.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_HARDWARE_ERROR: if there is an issue getting the voltage.
 */
int32_t BRD_SM_SupplyLevelGet(uint32_t domain, uint32_t *microVolt);

/** @} */

#endif /* BRD_SM_API_H */

/** @} */

