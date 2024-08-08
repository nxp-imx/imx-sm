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
/* All unit tests.                                                          */
/*==========================================================================*/

/* TEST_00010 TEST_00020 TEST_00030 */

/* Include Config */

/* Includes */

#include <stdlib.h>
#include "sm.h"
#include "test.h"
#if defined(GCOV) && !defined(SIMU)
#include "gcov_dump.h"
#endif

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test all                                                                 */
/*--------------------------------------------------------------------------*/
void TEST_All(void)
{
#ifndef TEST_MIN
    /* Run device SM tests */
    TEST_DevSmPower();
    TEST_DevSmClock();
    TEST_DevSmPerf();
#ifdef SIMU
    TEST_DevSmSensor();
#endif
    TEST_DevSmReset();
    TEST_DevSmVoltage();
    TEST_DevSmBbm();
    TEST_DevSmCpu();
    TEST_DevSmControl();
    TEST_DevSmSystem();
    TEST_DevSmRdc();
    TEST_DevSmPin();
    TEST_DevSmFault();
    TEST_DevSm();

    /* Run board SM tests */
#ifdef SIMU
    TEST_BrdSmSensor();
    TEST_BrdSm();
    TEST_BrdSmControl();
#endif

    /* Run LMM tests */
    TEST_LmmClock();
    TEST_LmmPerf();
    TEST_LmmSys();
    TEST_LmmCpu();
    TEST_LmmSensor();
    TEST_LmmMisc();
    TEST_LmmFuSa();
    TEST_LmmVoltage();
    TEST_LmmPower();
#endif

    /* Run SCMI tests */
    TEST_Scmi();
    TEST_ScmiBase();
    TEST_ScmiPower();
    TEST_ScmiSystem();
    TEST_ScmiPerf();
    TEST_ScmiClock();
    TEST_ScmiSensor();
    TEST_ScmiReset();
    TEST_ScmiVoltage();
    TEST_ScmiPinctrl();
    TEST_ScmiLmm();
    TEST_ScmiBbmGpr();
    TEST_ScmiBbmRtc();
    TEST_ScmiBbmButton();
    TEST_ScmiCpu();
    TEST_ScmiFusa();
    TEST_ScmiMisc();

    /* Run Utility tests */
    TEST_UtilitiesConfig();

#if defined(GCOV) && !defined(SIMU)
    /* Dump GCOV info */
    GCOV_InfoDump();
#endif

    /* Exit */
    BRD_SM_Exit(SM_ERR_SUCCESS, 0U);
}

