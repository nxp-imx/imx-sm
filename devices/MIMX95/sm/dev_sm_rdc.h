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

#ifndef DEV_SM_RDC_H
#define DEV_SM_RDC_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX95_RDC
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device RDC.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device RDC */
#define DEV_SM_NUM_RDC  10U

/*!
 * @name Device RDC indexes
 */
/** @{ */
#define DEV_SM_TRDC_A  0U  /*!< AON TRDC */
#define DEV_SM_TRDC_M  1U  /*!< Mega TRDC */
#define DEV_SM_TRDC_W  2U  /*!< Wakeup TRDC */
#define DEV_SM_TRDC_C  3U  /*!< Camera TRDC */
#define DEV_SM_TRDC_H  4U  /*!< HSIO TRDC */
#define DEV_SM_TRDC_N  5U  /*!< NOC TRDC */
#define DEV_SM_TRDC_D  6U  /*!< Display TRDC */
#define DEV_SM_TRDC_E  7U  /*!< NETC TRDC */
#define DEV_SM_TRDC_G  8U  /*!< GPU TRDC */
#define DEV_SM_TRDC_V  9U  /*!< VPU TRDC */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

// coverity[misra_c_2012_rule_20_1_violation:FALSE]
#include "dev_sm_rdc_api.h"

#endif /* DEV_SM_RDC_H */

