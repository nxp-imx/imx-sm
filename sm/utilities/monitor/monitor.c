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
/* Implementation of the debug monitor.                                     */
/*==========================================================================*/

/* Includes */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>
#include <sys/errno.h>
#include "sm.h"
#include "monitor.h"
#include "monitor_cmds.h"
#ifdef SIMU
#include <unistd.h>
#include <termios.h>
#endif
#ifndef SIMU
#include "fsl_lpuart.h"
#endif

/* Defines */

#define HIST_SIZE      5U
#define MAXLINE        128U
#define ESC            '\x1B'
#ifdef SIMU
#define BS             '\x7F'
#define DEL            '\x7E'
#else
#define BS             '\x08'
#define DEL            '\x7F'
#endif

#define DELETE_CHAR()     printf(" \b")
#define DISPLAY_PROMPT()  printf(">$ ")
#define ERASE_LINE()      printf("%c[2K\r", ESC)
#define CURSOR_FORWARD()  printf("%c[1C", ESC)
#define CURSOR_BACK()     printf("%c[1D", ESC)

/* Types */

/* Local Functions */

#ifdef SIMU
static char MONITOR_RawCharGet(bool echo);
#endif
static int32_t MONITOR_CharGet(char *buf, uint32_t len, bool echo);
static char* MONITOR_LineRead(void);
static char* MONITOR_HistRestore(const char *histBuf);
static void MONITOR_HistAdd(char *histBuf);
static int32_t MONITOR_LineRedraw(void);
static char* MONITOR_CharInsert(char *buf, char *bufEnd, char c);
static char* MONITOR_CharRemove(char *buf);
static void MONITOR_CursorPosRestore(const char *start, const char *end);

/* Local Variables */

static char line[MAXLINE];
static char hist[HIST_SIZE][MAXLINE];
static volatile int c_insert = EOL;
#if !defined(SIMU)
static uint32_t priMask;
#endif

/*--------------------------------------------------------------------------*/
/* Debug Monitor                                                            */
/*--------------------------------------------------------------------------*/
void MONITOR_Cmd(string banner)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Zero initialize command and history buffers */
    (void)memset((void *)line, 0, (size_t)MAXLINE);
    (void)memset((void *)hist, 0, (((size_t)MAXLINE)*((size_t)HIST_SIZE)));

    printf("%s", banner);

    /* Command loop */
    while (status != SM_ERR_LAST)
    {
        /* Display prompt */
        printf("\n>$ ");

        /* Read user input from console */
        MONITOR_LineRead();
        printf("\n");

        /* Dispatch */
#ifdef SIMU
        status = MONITOR_Dispatch(line);
#else
        priMask = DisableGlobalIRQ();
        status = MONITOR_Dispatch(line);
        EnableGlobalIRQ(priMask);
#endif

        /* Clean up input buffer */
        while (MONITOR_CharPending() != false)
        {
            char c;
            MONITOR_CharGet(&c, 1U, false);
        }

        /* Check for non-fatal error */
        if (status == SM_ERR_SUCCESS)
        {
            continue;
        }

        switch (status)
        {
            case SM_ERR_NOT_SUPPORTED:
                printf("Function not supported!\n");
                break;
            case SM_ERR_INVALID_PARAMETERS:
                printf("Invalid parameter(s)!\n");
                break;
            case SM_ERR_DENIED:
                printf("Operation denied!\n");
                break;
            case SM_ERR_NOT_FOUND:
                printf("Unknown command or parameter not found!\n");
                break;
            case SM_ERR_OUT_OF_RANGE:
                printf("Parameter out of range!\n");
                break;
            case SM_ERR_BUSY:
                printf("Busy!\n");
                break;
            case SM_ERR_GENERIC_ERROR:
                printf("Generic error!\n");
                break;
            case SM_ERR_HARDWARE_ERROR:
                printf("Hardware error!\n");
                break;
            case SM_ERR_MISSING_PARAMETERS:
                printf("Missing parameter!\n");
                break;
            case SM_ERR_POWER:
                printf("Power dependency!\n");
                break;
            case SM_ERR_LAST:
                break;
            default:
                printf("Unknown err (%d)!\n", status);
                break;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Insert command                                                           */
/*--------------------------------------------------------------------------*/
void MONITOR_LineUpdateDispatch(const char *my_string)
{
    strcpy(line, my_string);
    c_insert = '\n';
}

#ifdef SIMU
/*--------------------------------------------------------------------------*/
/* SystemMemoryProbe(addr, val, width)                                      */
/*--------------------------------------------------------------------------*/
uint32_t SystemMemoryProbe(const void *addr, void *val, uint8_t width)
{
    uint32_t rtn = 0U;
    uint32_t pAddr = (uint32_t) addr;

    if ((pAddr >= 0x80000000UL) && (pAddr < 0x80010000UL))
    {
        // Perform the probe
        switch(width)
        {
            default:
                *((uint8_t *) val) = *((const uint8_t *) addr);
                break;
            case 16:
                *((uint16_t *) val) = *((const uint16_t *) addr);
                break;
            case 32:
                *((uint32_t *) val) = *((const uint32_t *) addr);
                break;
        }
    }
    else
    {
        rtn = 1U;
    }

    return rtn;
}
#endif

/*--------------------------------------------------------------------------*/
/* Search for string                                                        */
/*--------------------------------------------------------------------------*/
int32_t MONITOR_Find(string const *list, int32_t max, const char *str)
{
    int32_t r;

    for (r = 0; r < max; r++)
    {
        if (strcasecmp(str, list[r]) == 0)
        {
            break;
        }
    }

    return r;
}

/*--------------------------------------------------------------------------*/
/* Search for string (limit length)                                         */
/*--------------------------------------------------------------------------*/
int32_t MONITOR_FindN(string const *list, int32_t max, const char *str)
{
    int32_t r;

    for (r = 0; r < max; r++)
    {
        if (list[r] != NULL)
        {
            if (strncasecmp(str, list[r], strlen(list[r])) == 0)
            {
                break;
            }
        }
    }

    return r;
}

/*--------------------------------------------------------------------------*/
/* Parse line                                                               */
/*--------------------------------------------------------------------------*/
void MONITOR_ParseLine(char *lineStr, int32_t *argc, const char *argv[])
{
    char *p = lineStr;
    int32_t arg = 0;

    /* Parse Line */
    while (*p != EOL)
    {
        /* Skip white space */
        while (*p == ' ')
        {
            p++;
        }

        /* Save pointer */
        if ((*p != EOL) && (*p != '\n') && (*p != '\r'))
        {
            argv[arg] = p;
            arg++;
        }

        /* Find end */
        while ((*p != ' ') && (*p != EOL) && (*p != '\n') && (*p != '\r'))
        {
            p++;
        }

        /* Mark end */
        if (*p != EOL)
        {
            *p = EOL;
            p++;
        }
    }

    /* Return count */
    *argc = arg;
}

/*--------------------------------------------------------------------------*/
/* Check if char pending                                                    */
/*--------------------------------------------------------------------------*/
bool MONITOR_CharPending(void)
{
#if defined(SIMU)
    return false;
#else
    const board_uart_config_t *uartConfig = BOARD_GetDebugUart();
    bool rtn = false;

    if (uartConfig->base != NULL)
    {
        uint32_t status = LPUART_GetStatusFlags(uartConfig->base);

        if ((status & ((uint32_t) kLPUART_RxFifoEmptyFlag)) == 0U)
        {
            rtn = true;
        }
    }

    return rtn;
#endif
}

/*--------------------------------------------------------------------------*/
/* Allow other interrupts                                                   */
/*--------------------------------------------------------------------------*/
void MONITOR_Yield(void)
{
#if !defined(SIMU)
    EnableGlobalIRQ(priMask);
    priMask = DisableGlobalIRQ();
#endif
}

/*==========================================================================*/

#ifdef SIMU
/*--------------------------------------------------------------------------*/
/* Raw getc function for SIMU                                               */
/*--------------------------------------------------------------------------*/
static char MONITOR_RawCharGet(bool echo)
{
    char buf = 0;
    struct termios old = {0};
    ssize_t res;

    fflush(stdout);
    tcgetattr(0, &old);
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &old);
    res = read(0, &buf, 1);
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    tcsetattr(0, TCSADRAIN, &old);

    if (res > 0)
    {
        if ((buf != ESC) && echo)
        {
            if (buf == BS)
            {
                printf("\b");
            }
            else
            {
                printf("%c", buf);
            }
            fflush(stdout);
        }
    }
    else
    {
        buf = EOL;
    }

    return buf;
}
#endif

/*--------------------------------------------------------------------------*/
/* Raw getc function                                                        */
/*--------------------------------------------------------------------------*/
static int32_t MONITOR_CharGet(char *buf, uint32_t len, bool echo)
{
#ifdef SIMU
    *buf = MONITOR_RawCharGet(echo);

    return 1;
#else
    const board_uart_config_t *uartConfig = BOARD_GetDebugUart();
    int32_t rtn;

    if (uartConfig->base != NULL)
    {
        LPUART_ReadBlocking(uartConfig->base, (uint8_t*) buf, len);

        if ((*buf != ESC) && echo)
        {
            // Echo received characters
            LPUART_WriteBlocking(uartConfig->base, (uint8_t*) buf, len);
        }

        for (uint32_t i = 0U; i < len; i++)
        {
            if (buf[i] == '\r')
            {
                buf[i] = '\n';
            }
        }

        rtn = (int32_t) len;
    }
    else
    {
        errno = EBADF;
        rtn = -1;
    }

    return rtn;
#endif
}

/*--------------------------------------------------------------------------*/
/* Read line from console                                                   */
/*--------------------------------------------------------------------------*/
static char* MONITOR_LineRead(void)
{
    /* Maintain pointers to the beginning and end of the command buffer */
    char * const buf_start = line;
    const char * const buf_end = line + MAXLINE;

    /* Points to end of the current command */
    char* end_of_cmd = line;

    /* Pointer used for inserting characters into command buffer */
    char *buf = line;

    /* Character received from UART */
    char input = EOL;

    /* Initialize seek and insert indices - seek is used for traversing
     * the history buffer using the up and down arrow keys, and insert
     * is for indicating the next location to insert the next command
     */
    static uint8_t cur_hist_size = 0U;
    static uint8_t insert_idx = 0U;

    uint8_t seek_cnt = 0U;

    /***************************************************************************/

    /* Clear command buffer */
    (void)memset((void *)buf, 0, (size_t)MAXLINE);

    /* Get first character */
    MONITOR_CharGet(&input, 1U, true);

    /* Main processing loop */
    while ((input != '\n') && (input != '\r') && (buf != buf_end))
    {
        if (input == BS) /* Backspace */
        {
            if (buf != buf_start)
            {
                if (buf == end_of_cmd) /* Check if backspacing from the end of the line */
                {
                    /* Remove previous character from buffer */
                    buf--;
                    *buf = EOL;

                    /* Update end pointer */
                    end_of_cmd--;

                    /* Clear character on console */
                    DELETE_CHAR();
                }
                else
                {
                    /* Remove previous character from buffer */
                    buf--;
                    MONITOR_CharRemove(buf);

                    /* Update end pointer */
                    end_of_cmd--;

                    /* Print updated command to console */
                    printf("%s", buf);

                    /* Remove extra character from end of line */
                    DELETE_CHAR();

                    MONITOR_CursorPosRestore(buf, end_of_cmd);
                }

            }
            else /* No more characters to backspace */
            {
                printf(" ");
            }

        }
        else if (input == DEL) /* Delete */
        {
            if ((buf != end_of_cmd) && (*buf != EOL))
            {
                /* Remove character underneath cursor */
                MONITOR_CharRemove(buf);

                /* Update end pointer */
                end_of_cmd--;

                /* Print updated command and remove extra character */
                printf("%s", buf);
                DELETE_CHAR();

                MONITOR_CursorPosRestore(buf, end_of_cmd);
            }
        }
        else if (input == ESC) /* Escape character */
        {
            /* Get second character of escape sequence */
            MONITOR_CharGet(&input, 1U, false);

            if (input == '[')
            {
                /* Get last character of escape sequence */
                MONITOR_CharGet(&input, 1U, false);

                if (input == 'A') /* Up arrow key */
                {
                    /* Once the seek counter is equal to the current size of the
                     * history buffer, we have displayed all available commands */
                    if (seek_cnt < cur_hist_size)
                    {
                        uint8_t seek_idx;
                        seek_cnt++;

                        /* Compute seek position based on offset from insert position */
                        seek_idx = ((insert_idx-seek_cnt) + HIST_SIZE) % HIST_SIZE;

                        /* Erase contents of current command buffer and
                         * replace with the previous command */
                        (void)memset((void *)buf_start, 0, (size_t)MAXLINE);
                        end_of_cmd = MONITOR_HistRestore(hist[seek_idx]);

                        /* Set buffer pointer to end of buffer */
                        buf = end_of_cmd;

                        /* Update console to display previous command */
                        MONITOR_LineRedraw();
                    }

                }
                else if (input == 'B') /* Down arrow key */
                {
                    if (seek_cnt > 1U)
                    {
                        uint8_t seek_idx;
                        seek_cnt--;

                        /* Compute seek position based on offset from insert position */
                        seek_idx = ((insert_idx-seek_cnt) + HIST_SIZE) % HIST_SIZE;

                        /* Erase contents of current command buffer and
                         * replace with the previous command */
                        (void)memset((void *)buf_start, 0, (size_t)MAXLINE);
                        end_of_cmd = MONITOR_HistRestore(hist[seek_idx]);

                        /* Set buffer pointer to end of buffer */
                        buf = end_of_cmd;

                        /* Update console to display previous command */
                        MONITOR_LineRedraw();
                    }
                    else /* No more commands to display, so clear the line */
                    {
                        /* Update console */
                        ERASE_LINE();
                        DISPLAY_PROMPT();

                        (void)memset((void *)buf_start, 0, (size_t)MAXLINE);

                        /* Update buffer pointers */
                        buf = buf_start;
                        end_of_cmd = buf_start;

                        /* Reset seek counter */
                        seek_cnt = 0U;
                    }

                }
                else if (input == 'C') /* Right arrow key */
                {
                    if (buf != end_of_cmd) /* Check if not at EOL */
                    {
                        buf++;
                        CURSOR_FORWARD();
                    }
                }
                else if (input == 'D') /* Left arrow key */
                {
                    if (buf != buf_start) /* Check if no more characters remain */
                    {
                        buf--;
                        CURSOR_BACK();
                    }
                }
                else if (input == '\x33') /* Delete */
                {
#ifdef SIMU
                    MONITOR_CharGet(&input, 1U, false);
#endif
                    if ((buf != end_of_cmd) && (*buf != EOL))
                    {
                        /* Remove character underneath cursor */
                        MONITOR_CharRemove(buf);

                        /* Update end pointer */
                        end_of_cmd--;

                        /* Print updated command and remove extra character */
                        printf("%s", buf);
                        DELETE_CHAR();

                        MONITOR_CursorPosRestore(buf, end_of_cmd);
                    }
                }
                else
                {
                    ; /* Intentional empty else */
                }
            }
        }
        else /* Normal character */
        {
            if (buf == end_of_cmd) /* Add character to the end */
            {
                /* Write character to command buffer */
                *buf = input;
                buf++;
                end_of_cmd++;
            }
            else /* Insert character */
            {
                MONITOR_CharInsert(buf, end_of_cmd, input);

                /* Update pointers */
                buf++;
                end_of_cmd++;

                /* Print updated command */
                printf("%s", buf);

                MONITOR_CursorPosRestore(buf, end_of_cmd);
            }
        }

        /* Get next character from console */
        MONITOR_CharGet(&input, 1U, true);
    }

    /* Check that a valid character is stored in the command buffer */
    if ((*buf_start != '\n') && (*buf_start != '\r') && (*buf_start != EOL))
    {
        uint8_t seek_idx = (insert_idx + HIST_SIZE - 1U) % HIST_SIZE;

        /* Don't add command to history if most recent command is identical */
        if (strcasecmp(line, hist[seek_idx]) != 0)
        {
            /* Add current command to history buffer */
            MONITOR_HistAdd(hist[insert_idx]);

            /* Move to next address in history buffer */
            insert_idx = (insert_idx + 1U) % HIST_SIZE;

            /* Current size of history buffer can never be larger than total
             * size of buffer */
            if (cur_hist_size < HIST_SIZE)
            {
                cur_hist_size++;
            }
        }
    }

    return hist[insert_idx];
}

/*--------------------------------------------------------------------------*/
/* Write previous command into command buffer                               */
/*--------------------------------------------------------------------------*/
static char* MONITOR_HistRestore(const char *histBuf)
{
    static char* rtn = NULL;

    /* Null pointer check */
    if (histBuf != NULL)
    {
        uint8_t idx = 0U;

        /* Copy contents of history buffer into
         * current command buffer */
        while ((idx < MAXLINE) && (histBuf[idx] != EOL))
        {
            line[idx] = histBuf[idx];
            idx++;
        }

        rtn = &line[idx];
    }

    /* Return pointer to end of command buffer */
    return rtn;
}

/*--------------------------------------------------------------------------*/
/* Write current command to command history buffer                          */
/*--------------------------------------------------------------------------*/
static void MONITOR_HistAdd(char *histBuf)
{
    /* Null pointer check */
    if (histBuf != NULL)
    {
        uint8_t idx = 0U;

        /* Copy contents of current command buffer into
         * command history buffer */
        while ((*line != '\n') && (*line != '\r') && (*line != EOL)
            && (idx < MAXLINE))
        {
            histBuf[idx] = line[idx];
            idx++;
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Overwrite current line with previous command                             */
/*--------------------------------------------------------------------------*/
static int32_t MONITOR_LineRedraw(void)
{
    /* Erase current line on console */
    ERASE_LINE();

    /* Re-display prompt */
    DISPLAY_PROMPT();

    printf("%s", line);

    return SM_ERR_SUCCESS;
}

/*--------------------------------------------------------------------------*/
/* Insert character into command buffer                                     */
/*--------------------------------------------------------------------------*/
static char* MONITOR_CharInsert(char *buf, char *bufEnd, char c)
{
    char *bufEndPtr = bufEnd;

    while (bufEndPtr > buf)
    {
        *bufEndPtr = *(bufEndPtr - 1);
        bufEndPtr--;
    }
    *bufEndPtr = c;

    return buf;
}

/*--------------------------------------------------------------------------*/
/* Remove character from command buffer                                     */
/*--------------------------------------------------------------------------*/
static char* MONITOR_CharRemove(char *buf)
{
    char *ptr = buf;

    while (*ptr != EOL)
    {
        *ptr = *(ptr + 1);
        ptr++;
    }

    return ptr;
}

/*--------------------------------------------------------------------------*/
/* Set cursor back to correct position after character insert/delete        */
/*--------------------------------------------------------------------------*/
static void MONITOR_CursorPosRestore(const char *start, const char *end)
{
    for (int32_t idx = (end - start); idx > 0; idx--)
    {
        printf("\b");
    }
}

/*--------------------------------------------------------------------------*/
/* Convert resource name to an ID                                           */
/*--------------------------------------------------------------------------*/
int32_t MONITOR_NameToId(const char *rsrcName, uint32_t *id,
    func_t func, uint32_t max)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t index;

    /* Lookup domain name */
    for (index = 0U; index < max; index++)
    {
        string name;

        status = func(0U, index, &name, NULL);

        if ((status == SM_ERR_SUCCESS)
            && (strcasecmp(rsrcName, name) == 0))
        {
            break;
        }
    }

    /* Assume index if not name */
    if (index >= max)
    {
        char *endPtr;

        errno = 0;
        index = strtoul(rsrcName, &endPtr, 0);

        if ((errno !=0) || (*endPtr != EOL))
        {
            status = SM_ERR_INVALID_PARAMETERS;
        }
    }

    /* Check if invalid */
    if (index >= max)
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }
    else
    {
        *id = index;
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Convert U32                                                              */
/*--------------------------------------------------------------------------*/
int32_t MONITOR_ConvU32(const char *str, uint32_t *val)
{
    int32_t status = SM_ERR_SUCCESS;

    errno = 0;
    uint32_t temp = strtoul(str, NULL, 0);

    if (errno == 0)
    {
        *val = temp;
    }
    else
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Convert U64                                                              */
/*--------------------------------------------------------------------------*/
int32_t MONITOR_ConvU64(const char *str, uint64_t *val)
{
    int32_t status = SM_ERR_SUCCESS;

    errno = 0;
    uint64_t temp = strtoull(str, NULL, 0);

    if (errno == 0)
    {
        *val = temp;
    }
    else
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Convert I32                                                              */
/*--------------------------------------------------------------------------*/
int32_t MONITOR_ConvI32(const char *str, int32_t *val)
{
    int32_t status = SM_ERR_SUCCESS;

    errno = 0;
    int32_t temp = strtol(str, NULL, 0);

    if (errno == 0)
    {
        *val = temp;
    }
    else
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    return status;
}

