/*
** ###################################################################
**
**     Copyright 2024 NXP
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/*!
 * @addtogroup BRD_SM_SIMU
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the board controls.
 */
/*==========================================================================*/

#ifndef BRD_SM_CONTROL_H
#define BRD_SM_CONTROL_H

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Defines */

/*!
 * @name Board redirection defines
 * @{
 */
#define SM_CONTROLSET          BRD_SM_ControlSet          /*!< Control set */
#define SM_CONTROLGET          BRD_SM_ControlGet          /*!< Control get */
#define SM_CONTROLEXTSET       BRD_SM_ControlExtSet       /*!< Extended control set */
#define SM_CONTROLEXTGET       BRD_SM_ControlExtGet       /*!< Extended control get */
/** @} */

/*! Number of board controls */
#define BRD_SM_NUM_CTRL  3UL

/*! Total number of controls */
#define SM_NUM_CTRL  (DEV_SM_NUM_CTRL + BRD_SM_NUM_CTRL)

/*!
 * @name BRD_SM control domain indexes
 */
/** @{ */
#define BRD_SM_CTRL_0       (DEV_SM_NUM_CTRL + 0U)  /*!< Sample ctrl */
#define BRD_SM_CTRL_TEST    (DEV_SM_NUM_CTRL + 1U)  /*!< Test ctrl */
#define BRD_SM_CTRL_TEST_E  (DEV_SM_NUM_CTRL + 2U)  /*!< Test ext ctrl */
/** @} */

/* Types */

/* Functions */

/*!
 * @name Board control functions
 * @{
 */

/*!
 * Set a board control value.
 *
 * @param[in]     ctrlId   Index of control to write
 * @param[in]     numVal   Number of array elements
 * @param[in]     val      Pointer to array of values to set
 *
 * This function allows a caller to write an array of values for
 * a control.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if ctrlId is not valid.
 */
int32_t BRD_SM_ControlSet(uint32_t ctrlId, uint32_t numVal,
    const uint32_t *val);

/*!
 * Get a board control value.
 *
 * @param[in]     ctrlId   Index of control to read
 * @param[out]    numRtn   Return pointer to number of array elements
 * @param[out]    rtn      Pointer to array to store return
 *
 * This function allows a caller to read an array of values for
 * a control.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if ctrlId is not valid.
 */
int32_t BRD_SM_ControlGet(uint32_t ctrlId, uint32_t *numRtn, uint32_t *rtn);

/*!
 * Set an extended board control value.
 *
 * @param[in]     ctrlId   Index of control to write
 * @param[in]     addr     Address of write
 * @param[in]     numVal   Number of array elements
 * @param[in]     val      Pointer to array of values to set
 *
 * This function allows a caller to write an array of values for
 * a control. Extra parameters allow this write to be more complex
 * such as to an I2C.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if ctrlId is not valid.
 * - ::SM_ERR_INVALID_PARAMETERS: if addr or numVal are not valid.
 */
int32_t BRD_SM_ControlExtSet(uint32_t ctrlId, uint32_t addr,
    uint32_t numVal, const uint32_t *val);

/*!
 * Get an extended board control value.
 *
 * @param[in]     ctrlId   Index of control to read
 * @param[in]     addr     Address of read
 * @param[in]     numRtn   Number of array elements
 * @param[out]    rtn      Pointer to array to store return
 *
 * This function allows a caller to read an array of values for
 * a control. Extra parameters allow this read to be more complex
 * such as from an I2C.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 *
 * Return errors (see @ref STATUS "SM error codes"):
 * - ::SM_ERR_NOT_FOUND: if ctrlId is not valid.
 * - ::SM_ERR_INVALID_PARAMETERS: if addr or numRtn are not valid.
 */
int32_t BRD_SM_ControlExtGet(uint32_t ctrlId, uint32_t addr,
    uint32_t numRtn, uint32_t *rtn);

/*!
 * Control handler.
 *
 * @param[in]     status   Interrupt status
 * @param[in]     val      Signal state
 */
void BRD_SM_ControlHandler(uint8_t status, uint8_t val);

/** @} */

#endif /* BRD_SM_CONTROL_H */

/** @} */

