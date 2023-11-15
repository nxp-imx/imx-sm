/*
** ###################################################################
**
**     Copyright 2023 NXP
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
 * @addtogroup DEV_SM_SIMU
 *
 * @{
 * @file
 * @brief
 *
 * Header file containing the SM API for the device.
 */
/*==========================================================================*/

#ifndef DEV_SM_H
#define DEV_SM_H

/* Includes */

#include "sm.h"
#include "dev_sm_config.h"
#include "dev_sm_power.h"
#include "dev_sm_system.h"
#include "dev_sm_perf.h"
#include "dev_sm_clock.h"
#include "dev_sm_sensor.h"
#include "dev_sm_reset.h"
#include "dev_sm_voltage.h"
#include "dev_sm_bbm.h"
#include "dev_sm_cpu.h"
#include "dev_sm_pin.h"
#include "dev_sm_control.h"
#include "dev_sm_rdc.h"
#include "dev_sm_common.h"
#include "dev_sm_rom.h"
#include "dev_sm_fault.h"

/* Defines */

/* Types */

/* Functions */

/*!
 * Initialize the device.
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_Init(void);

/*!
 * Return lists of resources used by the SM.
 *
 * @param[in]  numClock    Number of clocks
 * @param[in]  clockList   Return pointer to array of clocks
 */
void DEV_SM_LmmInitGet(uint32_t *numClock, const uint32_t **clockList);

/*!
 * Configure power domain hardware after power up.
 *
 * @param[in]  domainId    power domain powered up
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_PowerUpPost(uint32_t domainId);

/*!
 * Configure power domain hardware before power down.
 *
 * @param[in]  domainId    power domain to be powered down
 *
 * @return Returns the status (::SM_ERR_SUCCESS = success).
 */
int32_t DEV_SM_PowerDownPre(uint32_t domainId);

#endif /* DEV_SM_H */

/** @} */

