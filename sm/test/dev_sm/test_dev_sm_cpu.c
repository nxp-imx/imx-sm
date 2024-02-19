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
/* Unit test for the device SM CPU API.                                     */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test.h"
#include "dev_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Test device SM CPU                                                       */
/*--------------------------------------------------------------------------*/
void TEST_DevSmCpu(void)
{
    string name;
    int32_t len = 0;

    printf("**** Device SM CPU API Tests ***\n\n");

    /* Test API bounds */
    printf("\n**** Device SM CPU API Err Tests ***\n\n");

    /* Name Get */
    {
        /* Invalid cpuId  */
        printf("DEV_SM_CpuNameGet(%u)\n", DEV_SM_NUM_CPU);
        NECHECK(DEV_SM_CpuNameGet(DEV_SM_NUM_CPU, &name, &len),
            SM_ERR_NOT_FOUND);
    }

    /* CPU Start */
    {
        /* Invalid cpuId */
        printf("DEV_SM_CpuStart(%u)\n", DEV_SM_NUM_CPU);
        NECHECK(DEV_SM_CpuStart(DEV_SM_NUM_CPU),
            SM_ERR_NOT_FOUND);
    }

    /* CPU Stop */
    {
        /* Invalid cpuId */
        printf("DEV_SM_CpuStop(%u)\n", DEV_SM_NUM_CPU);
        NECHECK(DEV_SM_CpuStop(DEV_SM_NUM_CPU),
            SM_ERR_NOT_FOUND);
    }

    /* Reset Vector Check */
    {
        uint64_t resetVector = 0U;
        bool table = true;

        /* Invalid cpuId */
        printf("DEV_SM_CpuResetVectorCheck(%u)\n", DEV_SM_NUM_CPU);
        NECHECK(DEV_SM_CpuResetVectorCheck(DEV_SM_NUM_CPU, resetVector,
            table), SM_ERR_NOT_FOUND);
    }

    /* Reset Vector Set */
    {
        uint64_t resetVector = 0U;

        /* Invalid cpuId */
        printf("DEV_SM_CpuResetVectorSet(%u)\n", DEV_SM_NUM_CPU);
        NECHECK(DEV_SM_CpuResetVectorSet(DEV_SM_NUM_CPU, resetVector),
            SM_ERR_NOT_FOUND);
    }

    /* Sleep Mode Set */
    {
        uint32_t sleepMode = 0U;

        /* Invalid cpuId */
        printf("DEV_SM_CpuSleepModeSet(%u)\n", DEV_SM_NUM_CPU);
        NECHECK(DEV_SM_CpuSleepModeSet(DEV_SM_NUM_CPU, sleepMode, 0U),
            SM_ERR_NOT_FOUND);

        /* Invalid Sleep Mode
            July 18, 2023 -- 0U <= x <= 4U are valid */
        // sleepMode = 5U;

        // printf("DEV_SM_CpuSleepModeSet(%u)\n", 0U);
        // NECHECK(DEV_SM_CpuSleepModeSet(0U, sleepMode),
        //     SM_ERR_INVALID_PARAMETERS);
    }

    /* IRQ wake set */
    {
        uint32_t maskIdx = 0U;
        uint32_t maxVal = 0U;

        /* Invalid cpuId */
        printf("DEV_SM_CpuIrqWakeSet(%u)\n", DEV_SM_NUM_CPU);
        NECHECK(DEV_SM_CpuIrqWakeSet(DEV_SM_NUM_CPU, maskIdx,
            maxVal), SM_ERR_NOT_FOUND);
    }

    /* Non IRQ wake set */
    {
        uint32_t maskIdx = 0U;
        uint32_t maxVal = 0U;

        /* Invalid cpuId */
        printf("DEV_SM_CpuNonIrqWakeSet(%u)\n", DEV_SM_NUM_CPU);
        NECHECK(DEV_SM_CpuNonIrqWakeSet(DEV_SM_NUM_CPU, maskIdx,
            maxVal), SM_ERR_NOT_FOUND);
    }

    printf("\n");
}

