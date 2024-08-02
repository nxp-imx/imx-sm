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
/* File containing the implementation of the configuration functions        */
/*==========================================================================*/

/* Includes */

#include <sm.h>
#include <brd_sm.h>
#include <gcov.h>
#include <gcov_dump.h>

/* Local defines */

#define BUFFER_SIZE  500U

/* Local types */

/* Local variables */

/* External variables from linker */

extern const struct gcov_info *const __gcov_info_start[];
extern const struct gcov_info *const __gcov_info_end[];

/* Local functions */

static void GCOV_Dump(const void *ptr, unsigned len, void *arg);
static void GCOV_FileName(const char *fileName, void *arg);
static void* GCOV_Allocate(unsigned len, void *arg);

/*--------------------------------------------------------------------------*/
/* Dump GCOV info                                                           */
/*--------------------------------------------------------------------------*/
void GCOV_InfoDump(void)
{
    const struct gcov_info *const *info = __gcov_info_start;
    const struct gcov_info *const *end = __gcov_info_end;

    /* Prevent compiler optimizations */
    __asm__ ("" : "+r" (info));

    /* Loop over each file */
    while (info != end)
    {
        /* Dump file GCOV data */
        __gcov_info_to_gcda(*info, GCOV_FileName, GCOV_Dump, GCOV_Allocate,
            NULL);
        info++;
    }

    printf("\n");
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Dump GCOV byte list                                                      */
/*--------------------------------------------------------------------------*/
static void GCOV_Dump(const void *ptr, unsigned len, void *arg)
{
    const uint8_t *p = (const uint8_t*) ptr;

    /* Tick wdog */
    BOARD_WdogRefresh();

    printf("GCOV_D:");

    /* Dump data */
    for (uint32_t idx = 0U; idx < len; idx++)
    {
        printf (" %02x", p[idx]);
    }

    printf("\n");
}

/*--------------------------------------------------------------------------*/
/* Dump filename                                                            */
/*--------------------------------------------------------------------------*/
static void GCOV_FileName(const char *fileName, void *arg)
{
    if (fileName != NULL)
    {
        printf("GCOV_H: file=%s\n", fileName);
    }
}

/*--------------------------------------------------------------------------*/
/* Allocate working memory                                                  */
/*--------------------------------------------------------------------------*/
static void* GCOV_Allocate(unsigned len, void *arg)
{
    static uint8_t buf[BUFFER_SIZE];

    /* Check length */
    if (len > BUFFER_SIZE)
    {
        printf("error: GCOV bufer overflow\n");
    }

    return (void*) &buf;
}

