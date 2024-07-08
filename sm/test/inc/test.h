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
 * @addtogroup TEST TEST: Unit Test
 * @brief Unit tests for SM.
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for unit tests.
 */
/*==========================================================================*/

#ifndef TEST_H
#define TEST_H

/* Includes */

#include "test_config.h"
#include "sm.h"
#include "brd_sm.h"
#include "test_dev.h"

/* Defines */

#ifdef INC_LIBC

/*!
 * Wrapper for a check with exit and error report on fail.
 *
 * @param[in]     X  Condition to check
 */
#define CHECK(X) \
    { \
        int32_t lstat = (X); \
        if (lstat != SM_ERR_SUCCESS) \
        { \
            printf("  error @ line %d: %d\n", __LINE__, lstat); \
            SM_Error(lstat); \
        } \
    }

/*!
 * Wrapper for a check with exit and error report on fail.
 *
 * @param[in]     X  Condition to check
 */
#define BCHECK(X) \
    { \
        if (!(X)) \
        { \
            printf("  error @ line %d: %d\n", __LINE__, SM_ERR_TEST); \
            SM_Error(SM_ERR_TEST); \
        } \
    }

/*!
 * Wrapper for a check with exit and error report on success.
 *
 * @param[in]     X  Condition to check
 */
#define NCHECK(X) \
    { \
        int32_t lstat = (X); \
        if (lstat == SM_ERR_SUCCESS) \
        { \
            printf("  no error @ line %d: %d\n",  __LINE__, lstat);                  \
            SM_Error(SM_ERR_TEST); \
        } \
    }

/*!
 * Wrapper for a check with exit and error report.
 *
 * @param[in]     X  Polarity of check
 * @param[in]     Y  Condition to check
 */
#define XCHECK(X,Y) \
    { \
        int32_t lstat = (Y); \
        if ((X) && (lstat != SM_ERR_SUCCESS)) \
        { \
            printf("  error @ line %d: %d\n", __LINE__, lstat); \
            SM_Error(lstat); \
        } \
        if ((!(X)) && (lstat == SM_ERR_SUCCESS)) \
        { \
            printf("  no error @ line %d: %d\n", __LINE__, lstat); \
            SM_Error(SM_ERR_TEST); \
        } \
    }

/*!
 * Wrapper for a check with exit and error report on success.
 *
 * @param[in]     X  Condition to check
 * @param[in]     Y  Desired Error Code
 */
#define NECHECK(X,Y) \
    { \
        int32_t lstat = (X); \
        if (lstat != (Y)) \
        { \
            printf("  no error @ line %d: %d\n", __LINE__, lstat); \
            SM_Error(SM_ERR_TEST); \
        } \
    }

/*!
 * Wrapper to check if an agent has access and returns the proper
 * error code.
 *
 * @param[in]     X  Access Rights
 * @param[in]     Y  Condition to check
 * @param[in]     Z  Desired Error Code
 */
#define XECHECK(X,Y,Z) \
    { \
        int32_t lstat = (Y); \
        if ((X) && (lstat != SM_ERR_SUCCESS)) \
        { \
            printf("  error @ line %d: %d\n", __LINE__, lstat); \
            SM_Error(lstat); \
        } \
        if ((!(X)) && (lstat != (Z))) \
        { \
            printf("  error @ line %d: %d\n", __LINE__, lstat); \
            SM_Error(SM_ERR_TEST); \
        } \
    }

#else

/*!
 * Wrapper for a check with exit and error report on fail.
 *
 * @param[in]     X  Condition to check
 */
#define CHECK(X) \
    { \
        int32_t lstat = (X); \
        if (lstat != SM_ERR_SUCCESS) \
        { \
            SM_Error(lstat); \
        } \
    }

/*!
 * Wrapper for a check with exit and error report on fail.
 *
 * @param[in]     X  Condition to check
 */
#define BCHECK(X) \
    { \
        if (!(X)) \
        { \
            SM_Error(SM_ERR_TEST); \
        } \
    }

/*!
 * Wrapper for a check with exit and error report on success.
 *
 * @param[in]     X  Condition to check
 */
#define NCHECK(X) \
    { \
        int32_t lstat = (X); \
        if (lstat == SM_ERR_SUCCESS) \
        { \
            SM_Error(SM_ERR_TEST); \
        } \
    }

/*!
 * Wrapper for a check with exit and error report.
 *
 * @param[in]     X  Polarity of check
 * @param[in]     Y  Condition to check
 */
#define XCHECK(X,Y) \
    { \
        int32_t lstat = (Y); \
        if ((X) && (lstat != SM_ERR_SUCCESS)) \
        { \
            SM_Error(lstat); \
        } \
        if ((!(X)) && (lstat == SM_ERR_SUCCESS)) \
        { \
            SM_Error(SM_ERR_TEST); \
        } \
    }

/*!
 * Wrapper for a check with exit and error report on success.
 *
 * @param[in]     X  Condition to check
 * @param[in]     Y  Desired Error Code
 */
#define NECHECK(X,Y) \
    { \
        int32_t lstat = (X); \
        if (lstat != (Y)) \
        { \
            SM_Error(SM_ERR_TEST); \
        } \
    }

/*!
 * Wrapper to check if an agent has access and returns the proper
 * error code.
 *
 * @param[in]     X  Access Rights
 * @param[in]     Y  Condition to check
 * @param[in]     Z  Desired Error Code
 */
#define XECHECK(X,Y,Z) \
    { \
        int32_t lstat = (Y); \
        if ((X) && (lstat != SM_ERR_SUCCESS)) \
        { \
            SM_Error(lstat); \
        } \
        if ((!(X)) && (lstat != (Z))) \
        { \
            SM_Error(SM_ERR_TEST); \
        } \
    }

#endif

/* Types */

/* Functions */

/*!
 * Test entry point.
 */
void TEST(void);

#ifdef TEST_ALL
void TEST_BrdSmSensor(void);
void TEST_BrdSm(void);
void TEST_DevSmPower(void);
void TEST_DevSmClock(void);
void TEST_DevSmSensor(void);
void TEST_DevSmVoltage(void);
void TEST_DevSmPerf(void);
void TEST_DevSmBbm(void);
void TEST_DevSmCpu(void);
void TEST_DevSmReset(void);
void TEST_DevSmControl(void);
void TEST_DevSmSystem(void);
void TEST_DevSmRdc(void);
void TEST_DevSmPin(void);
void TEST_DevSmFault(void);
void TEST_DevSm(void);
void TEST_LmmClock(void);
void TEST_LmmPerf(void);
void TEST_LmmPower(void);
void TEST_LmmSys(void);
void TEST_LmmCpu(void);
void TEST_LmmSensor(void);
void TEST_LmmMisc(void);
void TEST_LmmFuSa(void);
void TEST_LmmVoltage(void);
void TEST_Scmi(void);
void TEST_ScmiBase(void);
void TEST_ScmiPower(void);
void TEST_ScmiSystem(void);
void TEST_ScmiPerf(void);
void TEST_ScmiClock(void);
void TEST_ScmiCpu(void);
void TEST_ScmiSensor(void);
void TEST_ScmiVoltage(void);
void TEST_ScmiPinctrl(void);
void TEST_ScmiLmm(void);
void TEST_ScmiBbmGpr(void);
void TEST_ScmiBbmRtc(void);
void TEST_ScmiBbmButton(void);
void TEST_ScmiMisc(void);
void TEST_ScmiReset(void);
void TEST_ScmiFusa(void);
void TEST_UtilitiesConfig(void);
#endif

#endif /* TEST_H */

/** @} */

