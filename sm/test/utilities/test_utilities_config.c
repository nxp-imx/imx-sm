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
/* Unit test for the Config                                                 */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include "test.h"
#include "config.h"
#include "string.h"

/* Local defines */

/* Used to convert element indexes into hex values */
#define OFFSET(X)   ((X)*(sizeof(uint32_t)))

/* Local types */

/* Local variables */

/* Local functions */

/* Configuration Tests
    STAGE 1:
        - SM_CFG_W1
        - SM_CFG_WN
        - SM_CFG_RP (Write)
        - SM_CFG_C1 (false)
        - SM_CFG_CN (false)
        - SM_CFG_FN
    STAGE 2:
        - SM_CFG_Z1 (overwrite prev load)
        - SM_CFG_ZN (overwrite prev load)
        - SM_CFG RP (Zero : overwrite)
        - SM_CFG_C1 (true)
        - SM_CFG_CN (true)
        - SM_CFG_FN (Zero : overwrite)
    STAGE 3:
        - SM_CFG_RP (INVALID_PARAMS)
 */
void TEST_UtilitiesConfig(void)
{
    /* Config tests */
    printf("**** Config Load Tests ***\n\n");

#ifdef SIMU
    uint32_t s_loadArr[30] __attribute__ ((aligned (65536)));

    /* STAGE 1 : =================================================== */
    {
        printf("\n** Stage 1 ***\n\n");

        /* Condition set to false */
        CONFIG_Condition(false);

        /* Comparison Array One */
        const uint32_t compArrOne[] =
        {
            0xDEADBEEF, 0xFEEBDAED,
            0x1, 0x2, 0x3, 0x4,
            0x1, 0x2, 0x3, 0x4,
            0x0, 0x0,
            0x0, 0x0, 0x0, 0x0,
            0xBEEF, 0xBEEF, 0xBEEF, 0xBEEF,
            0xABF
        };

        /* Get the size of the array, used to loop through later */
#define COMP_SIZE_ONE (sizeof(compArrOne) / sizeof(uint32_t))

        /* Command Array One */
        const uint32_t commandArrOne[] =
        {
            SM_CFG_W1(OFFSET(0)), 0xDEADBEEF,
            SM_CFG_W1(OFFSET(1)), 0xFEEBDAED,
            SM_CFG_WN(OFFSET(2), 4), 0x1, 0x2, 0x3, 0x4,
            SM_CFG_RP(OFFSET(6)),
            SM_CFG_C1(OFFSET(10)), 0xDEADBEEF,
            SM_CFG_C1(OFFSET(11)), 0xFEEBDAED,
            SM_CFG_CN(OFFSET(12), 4), 0x6, 0x7, 0x8, 0x9,
            SM_CFG_FN(OFFSET(16), 4), 0xBEEF,
            SM_CFG_WA( (uint32_t) &s_loadArr[20]), 0xABF,
            SM_CFG_END
        };

        /* Load */
        CHECK(CONFIG_Load(s_loadArr, commandArrOne));

        /* Check values for correctness */
        for (uint32_t index = 0; index < COMP_SIZE_ONE; index++)
        {
            printf("   compArrOne[%u]=%x = s_loadArr[%u]=%x\n",
                index, compArrOne[index], index, s_loadArr[index]);
            BCHECK(compArrOne[index] == s_loadArr[index]);
        }
    }

    /* STAGE 2 : =================================================== */
    {
        printf("\n** Stage 2 ***\n\n");

        /* Condition set to false */
        CONFIG_Condition(true);

        /* Comparison Array Two */
        const uint32_t compArrTwo[] =
        {
            0x0, 0x0,
            0x0, 0x0, 0x0, 0x0,
            0x0, 0x0, 0x0, 0x0,
            0xDEADBEEF, 0xFEEBDAED,
            0x6, 0x7, 0x8, 0x9,
            0x0, 0x0, 0x0, 0x0
        };

        /* Get the size of the array, used to loop through later */
#define COMP_SIZE_TWO (sizeof(compArrTwo) / sizeof(uint32_t))

        /* Command Array Two */
        const uint32_t commandArrTwo[] =
        {
            SM_CFG_Z1(OFFSET(0)),
            SM_CFG_Z1(OFFSET(1)),
            SM_CFG_ZN(OFFSET(2), 4),
            SM_CFG_RP(OFFSET(6)),
            SM_CFG_C1(OFFSET(10)), 0xDEADBEEF,
            SM_CFG_C1(OFFSET(11)), 0xFEEBDAED,
            SM_CFG_CN(OFFSET(12), 4), 0x6, 0x7, 0x8, 0x9,
            SM_CFG_FN(OFFSET(16), 4), 0X0,
            SM_CFG_END
        };

        /* Load */
        CHECK(CONFIG_Load(s_loadArr, commandArrTwo));

        /* Check values for correctness */
        for (uint32_t index = 0; index < COMP_SIZE_TWO; index++)
        {
            printf("   compArrTwo[%u]=%x = s_loadArr[%u]=%x\n",
                index, compArrTwo[index], index, s_loadArr[index]);
            BCHECK(compArrTwo[index] == s_loadArr[index]);
        }
    }

    /* STAGE 3 : =================================================== */
    {
        printf("\n** Stage 3 ***\n\n");

        /* Command Array Three */
        const uint32_t commandArrThree[] =
        {
            SM_CFG_RP(OFFSET(0)),
            SM_CFG_END
        };

        /* Command Array Four */
        const uint32_t commandArrFour[] =
        {
            0xFFFFFFFC,
            SM_CFG_END
        };

        /* Load */
        NECHECK(CONFIG_Load(s_loadArr, commandArrThree),
            SM_ERR_INVALID_PARAMETERS);
        printf("   Successfully caught Invalid Parameters...\n");

        NECHECK(CONFIG_Load(s_loadArr, commandArrFour),
            SM_ERR_NOT_FOUND);
        printf("   Successfully caught Error Not Found...\n");
    }
#else
    printf("Skipped.\n");
#endif

    printf("\n");
}

