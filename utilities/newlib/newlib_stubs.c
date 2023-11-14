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

#include <sys/stat.h>
#include <sys/errno.h>
#include <sys/unistd.h>
#include "fsl_device_registers.h"
#include "fsl_lpuart.h"
#include "brd_sm.h"

#undef errno
extern int errno;

#ifdef DEBUG
char term_emul_getc(void)
{
    char c;
    volatile uint32_t *rx = SM_DBG_RX_PTR;

    /* Wait for debugger to send char */
    do
    {
        c = *rx;
        BOARD_WdogRefresh();
    } while(c == (char) 0);

    /* ACK the character received to debugger */
    *rx = 0;

    return c;
}

void term_emul_putc(char c)
{
    volatile uint32_t *tx = SM_DBG_TX_PTR;

    /* Write char to terminal emulation TX address */
    *tx = c;

    /* Wait for debugger to read char */
    while(*tx != 0U)
    {
        BOARD_WdogRefresh();
    }
}
#endif

int _read(int file, char *buf, int len)
{
    LPUART_Type *base = BOARD_GetDebugUart(NULL, NULL, NULL);

    if ((base != NULL) && (file == STDIN_FILENO))
    {
        (void) LPUART_ReadBlocking(base, (uint8_t*) buf, len);

        // Echo received characters
        LPUART_WriteBlocking(base, (uint8_t*) buf, len);

        for (int i = 0; i < len; i++)
        {
            if (buf[i] == '\r')
                buf[i] = '\n';
        }

        return len;
    }
#ifdef DEBUG
    else if (SM_DBG_READY == 2U)
    {
        int idx = 0;

        while((len--) != 0)
        {
            char c;

            /* Get character */
            c = term_emul_getc();

            /* Convert CR into LF */
            if (c == '\r')
            {
                c = '\n';
            }
            buf[idx++] = c;

            /* Echo received character */
            term_emul_putc(c);
        }

        return idx;
    }
#endif
    else
    {
        errno = EBADF;
        return -1;
    }
}

int _write(int file, char *buf, int len)
{
    int ret_len = len;
    uint8_t cr = '\r';

    LPUART_Type *base = BOARD_GetDebugUart(NULL, NULL, NULL);

    if ((base != NULL) && (file == STDOUT_FILENO || file == STDERR_FILENO))
    {
        while((len--) != 0)
        {
            if (*buf == '\n')
            {
                LPUART_WriteBlocking(base, &cr, 1);
            }

            LPUART_WriteBlocking(base, (uint8_t*) buf, 1);
            buf++;
        }
        return ret_len;
    }
#ifdef DEBUG
    else if (SM_DBG_READY == 2U)
    {
        /* Use ipg_stop to halt WDOG */
        DSC_SC->GPR_CTRL[1].SET = (1U << 21U);

        while((len--) != 0)
        {
            char c = *buf;

            /* Put character */
            term_emul_putc(c);

            buf++;
        }

        /* Resume WDOG */
        DSC_SC->GPR_CTRL[1].CLR = (1U << 21U);
        return ret_len;
    }
#endif
    else
    {
        errno = EBADF;
        return -1;
    }
}

void _exit(int status)
{
    (void) _write(STDOUT_FILENO, "exit", 4);
    SystemExit();
    while (1)
    {
    }
}

int _getpid(void)
{
    return 1;
}

int _kill(int pid, int sig)
{
    errno = EINVAL;
    return -1;
}

caddr_t _sbrk(int incr)
{
    static uint8_t *heap_end;
    uint8_t *prev_heap_end;
    extern char __HeapBase[];
    extern char HEAP_SIZE[];
    uint8_t *heapbase;
    uint8_t *size;

    size  = (uint8_t *)HEAP_SIZE;
    heapbase = (uint8_t *)__HeapBase;

    /* initialize */
    if(heap_end == NULL)
    {
        heap_end = heapbase;
    }

    prev_heap_end = heap_end;

    if(((heap_end + incr) - heapbase) > (int)size)
    {
        /* heap overflow */
        (void) _write(STDERR_FILENO, "Heap overflow!\n", 15);
        errno = ENOMEM;
        return (caddr_t) -1;
    }
    heap_end += incr;

    return (caddr_t)prev_heap_end;
}

int _close(int file)
{
    return -1;
}

int _lseek(int file, int ptr, int dir)
{
    return 0;
}

int _isatty(int file)
{
    switch (file)
    {
        case STDOUT_FILENO:
        case STDERR_FILENO:
        case STDIN_FILENO:
            return 1;
        default:
            errno = EBADF;
            return 0;
    }
}

int _fstat(int file, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

int _fork(void)
{
    errno = EAGAIN;
    return -1;
}

int _link(char *old, char *new)
{
    errno = EMLINK;
    return -1;
}

int _unlink(char *name)
{
    errno = ENOENT;
    return -1;
}
