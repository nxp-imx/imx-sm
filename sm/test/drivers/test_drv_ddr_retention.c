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
/* Unit test for the DDR retention.                                         */
/*==========================================================================*/

/* Include Config */

/* Includes */

#include <stdio.h>
#include "dev_sm.h"
#include "fsl_ddr.h"
#include "fsl_sysctr.h"
#include "fsl_systick.h"
#include "fsl_fract_pll.h"
#include "board.h"

/* Local defines */

#define KBYTE               1024U
#define MBYTE               (1024U * KBYTE)

#define MEM_SRC             0x80000000U
#define MEM_STEP            0x08000000U
#define MEM_END             0xc0000000U

#define TEST_BYTE_CNT       MEM_STEP
#define TEST_LOOP_CNT       UINT32_MAX
#define TEST_PATTERN1       0x01234567U
#define TEST_PATTERN2       0x89ABCDEFU

#define DOT_BYTE_CNT        (TEST_BYTE_CNT / 64U)

#define RETENTION_USEC      5000000U
#define DDRMIX_PWR_DOWN     1U

/* Local types */

/* Local variables */

/* Local functions */

static bool verify_memory(uint32_t start_addr, uint32_t numbytes,
    uint32_t pattern1, uint32_t pattern2);
static void write_memory(uint32_t start_addr, uint32_t numbytes,
    uint32_t pattern1, uint32_t pattern2);

/*--------------------------------------------------------------------------*/
/* Register write                                                           */
/*--------------------------------------------------------------------------*/
/* Test SM driver DDR                                                       */
/*--------------------------------------------------------------------------*/
void TEST_DrvDdrRetention(void)
{
    uint32_t success_count, loop_counter;
    uint32_t pattern1, pattern2;
    volatile uint32_t memSrc, memEnd;
    static uint32_t numbytes;

    printf("TEST_DrvDdrRetention: Begin retention Tests\n");

    pattern1 = TEST_PATTERN1;
    pattern2 = TEST_PATTERN2;
    memSrc = MEM_SRC;
    memEnd = MEM_END;
    numbytes = TEST_BYTE_CNT;
    loop_counter = TEST_LOOP_CNT;

    printf("Memory end = 0x%x\n", memEnd);

    success_count = 0U;
    while (loop_counter > 0U)
    {
        int32_t status;

        printf("Testing 0x%x - 0x%x\n\n", memSrc, memSrc
            + MEM_STEP - 1U);

        /* write tha test pattern into the memory */
        write_memory(memSrc, numbytes, pattern1, pattern2);

        /* Enter retention */
        status = DEV_SM_SystemDramRetentionEnter();

#ifdef DDRMIX_PWR_DOWN
        if (status == SM_ERR_SUCCESS)
        {
            /* Power off DDRMIX */
            status = DEV_SM_PowerStateSet(DEV_SM_PD_DDR, DEV_SM_POWER_STATE_OFF);
        }
#endif

        SYSCTR_TimeDelay(RETENTION_USEC);

#ifdef DDRMIX_PWR_DOWN
        if (status == SM_ERR_SUCCESS)
        {
            printf("Power up DDRMIX\n");
            /* Power up DDRMIX */
            status = DEV_SM_PowerStateSet(DEV_SM_PD_DDR, DEV_SM_POWER_STATE_ON);
        }
#endif

        if (status == SM_ERR_SUCCESS)
        {
            printf("Exit retention\n");
            status = DEV_SM_SystemDramRetentionExit();
        }

        if (status == SM_ERR_SUCCESS)
        {
            /* verify the test pattern integrity in memory */
            if (verify_memory(memSrc, numbytes, pattern1, pattern2) == true)
            {
                success_count++;
                loop_counter--;

                printf("Passed %u times \n\n", success_count);

                memSrc = memSrc + MEM_STEP;

                /* Check for need to wrap source address */
                if ((memSrc >= memEnd) || (memSrc < MEM_SRC))
                {
                    memSrc = MEM_SRC;
                }
            }
            else
            {
                loop_counter = 0U;
            }
        }
    }

    printf("\n");
}

/*--------------------------------------------------------------------------*/
/* Verify memory                                                            */
/*--------------------------------------------------------------------------*/
static bool verify_memory(uint32_t start_addr, uint32_t numbytes,
    uint32_t pattern1, uint32_t pattern2)
{
    bool result = true;
    uint32_t i, j;

    printf("Verifying\n\n");
    j = 0U;

    /* Verify memory source */
    for (i = 0U; i < numbytes; i+=8U)
    {
        static uint32_t reg;

        reg=Read32((start_addr+i));
        if (reg != (pattern1 + i*pattern1))
        {
            printf("Failure:  addr = 0x%08x, expected = 0x%08x, actual = 0x%08x\n\n",
                start_addr+i, (pattern1 + i*pattern1), reg);
            result = false;
        }
        reg=Read32((start_addr+(i+4U)));
        if (reg != (pattern2 +i*pattern2))
        {
            printf("Failure:  addr = 0x%08x, expected = 0x%08x, actual = 0x%08x\n\n",
                start_addr+i+4, (pattern2 + i*pattern2), reg);
            result = false;
        }
        j++;
        if (j == 32U)
        {
            j = 0U;
        }

        if ((i % DOT_BYTE_CNT) == 0U)
        {
            printf(".");
            fflush(stdout);
        }
    }
    printf("\n\n");

    return result;
}

/*--------------------------------------------------------------------------*/
/* Fill pattern into memory                                                 */
/*--------------------------------------------------------------------------*/
static void write_memory(uint32_t start_addr, uint32_t numbytes,
    uint32_t pattern1, uint32_t pattern2)
{
    printf("Filling\n\n");
    uint32_t i = 0U;

    /* Fill memory source */
    for (i = 0U; i < numbytes; i+=8U)
    {
        // update patterns pseudo-randomly by adding to them each of their unique patterns
        // in an effort to eliminate repeating patterns
        Write32((start_addr+i), pattern1 + i*pattern1);
        Write32((start_addr+(i+4U)), pattern2 + i*pattern2);

        if ((i % DOT_BYTE_CNT) == 0U)
        {
            printf(".");
            fflush(stdout);
        }
    }
    printf("\n\n");
}

