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

#ifndef DEV_SM_FAULT_H
#define DEV_SM_FAULT_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_SIMU_FAULT
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device faults.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device faults */
#define DEV_SM_NUM_FAULT  8U

/*!
 * @name Device fault indexes
 */
/** @{ */
#define DEV_SM_FAULT_0  0U  /*!< Test fault 0 */
#define DEV_SM_FAULT_1  1U  /*!< Test fault 1 */
#define DEV_SM_FAULT_2  2U  /*!< Test fault 2 */
#define DEV_SM_FAULT_3  3U  /*!< Test fault 3 */
#define DEV_SM_FAULT_4  4U  /*!< Test fault 4 */
#define DEV_SM_FAULT_5  5U  /*!< Test fault 5 */
#define DEV_SM_FAULT_6  6U  /*!< Test fault 6 */
#define DEV_SM_FAULT_7  7U  /*!< Test fault 7 */
/** @} */

/*! Default init for fault record */
#define DEV_SM_FAULT_REC_INIT(X) \
    { \
        .valid = true, \
        .reason = DEV_SM_REASON_FAULT, \
        .errId = (X), \
        .validErr = true \
    }

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

#include "dev_sm_fault_api.h"

#endif /* DEV_SM_FAULT_H */

