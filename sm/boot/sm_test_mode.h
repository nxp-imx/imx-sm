/*
** ###################################################################
**
** Copyright 2024 NXP
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
 * @addtogroup BOOT
 * @{
 *
 * @file
 * @brief
 *
 * Header file for test mode functionality.
 */
/*==========================================================================*/

#ifndef SM_TEST_MODE_H
#define SM_TEST_MODE_H

#if defined(RUN_TEST) || defined(MONITOR)

/* Includes */

/* Defines */

/*! Indicator test mode support is included */
#define HAS_SM_TEST_MODE

/*!
 * @name SM test modes
 */
/** @{ */
#define SM_TEST_MODE_OFF        0U    /*!< None */
#define SM_TEST_MODE_DEV_LVL1   100U  /*!< Device first level error response */
#define SM_TEST_MODE_DEV_ALT1   120U  /*!< Device alt reponse 1 */
#define SM_TEST_MODE_BRD_LVL1   200U  /*!< Board first level error response */
#define SM_TEST_MODE_LMM_LVL1   300U  /*!< LMM first level error response */
#define SM_TEST_MODE_LMM_LVL2   301U  /*!< LMM second level error response */
#define SM_TEST_MODE_RPC_LVL1   400U  /*!< RPC first level error response */
/** @} */

/*! Set status on mode */
#define SM_TEST_MODE_ERR(testMode, testErr) \
    if (g_testMode == (testMode)) \
    { \
        status = (testErr); \
    }

/* Global Variables */

/*! Current test mode */
extern uint32_t g_testMode;

#else

/* Defines */

#define SM_TEST_MODE_ERR(testMode, testErr)

#endif

#endif /* SM_TEST_MODE_H */

/** @} */

