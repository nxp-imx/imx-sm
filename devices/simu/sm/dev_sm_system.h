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

#ifndef DEV_SM_SYSTEM_H
#define DEV_SM_SYSTEM_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_SIMU_SYS
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device system.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device boot/shutdown/reset reasons */
#define DEV_SM_NUM_REASON  5UL

/*!
 * @name Device boot/shutdown/reset reason indexes
 */
/** @{ */
#define DEV_SM_REASON_POR     0U  /*!< Power on reset */
#define DEV_SM_REASON_FAULT   1U  /*!< Fault */
#define DEV_SM_REASON_BBM     2U  /*!< BBM boot/shutdown */
#define DEV_SM_REASON_SW      3U  /*!< SW requested */
#define DEV_SM_REASON_SM_ERR  4U  /*!< SM error/exit */
/** @} */

/*! Number of device reset reasons */
#define DEV_SM_NUM_EXT_INFO  3U

/*! Default record for POR */
#define DEV_SM_RST_REC_POR \
    { \
        .reason = DEV_SM_REASON_POR, \
        .valid = true \
    }

/*! Default record for SW */
#define DEV_SM_RST_REC_SW \
    { \
        .reason = DEV_SM_REASON_SW, \
        .origin = 0U, \
        .validOrigin = true, \
        .valid = true \
    }

/*! Default record for BBM */
#define DEV_SM_RST_REC_BBM \
    { \
        .reason = DEV_SM_REASON_BBM, \
        .valid = true \
    }

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

#include "dev_sm_system_api.h"

#endif /* DEV_SM_SYSTEM_H */

