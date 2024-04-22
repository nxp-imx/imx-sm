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
/* File containing the implementation of the SM abstraction for the board.  */
/*==========================================================================*/

/* Includes */

#include <stdlib.h>
#include <errno.h>
#include "sm.h"
#include "brd_sm.h"
#include "dev_sm.h"
#include "lmm.h"

/* Local defines */

/* Local types */

/* Local variables */

static uint8_t s_voltMode[DEV_SM_NUM_VOLT];
static uint32_t s_voltLevel[DEV_SM_NUM_VOLT];

/*--------------------------------------------------------------------------*/
/* Init board                                                               */
/*--------------------------------------------------------------------------*/
// coverity[misra_c_2012_directive_4_6_violation:FALSE]
int32_t BRD_SM_Init(int argc, const char * const argv[], uint32_t *mSel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Get the boot mode select */
    if (argc > 1)
    {
        // coverity[misra_c_2012_rule_21_7_violation:FALSE]
        *mSel = (uint32_t) atoi(argv[1]);
    }

    /* Init the device */
    status = DEV_SM_Init();

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Exit function                                                            */
/*--------------------------------------------------------------------------*/
void BRD_SM_Exit(int32_t status, uint32_t pc)
{
    printf("exit %d, 0x%08X\n", status, pc);
    // coverity[misra_c_2012_rule_21_8_violation:FALSE]
    exit(status);
}

/*--------------------------------------------------------------------------*/
/* Board timer tick                                                         */
/*--------------------------------------------------------------------------*/
void BRD_SM_TimerTick(uint32_t msec)
{
    /* Tick BBM */
    BRD_SM_BbmHandler();

    /* Tick sensor */
    BRD_SM_SensorHandler();
}

/*--------------------------------------------------------------------------*/
/* Custom monitor function                                                  */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_Custom(int32_t argc, const char * const argv[])
{
    int32_t status = SM_ERR_SUCCESS;

    if (argc > 0)
    {
        /* Convert argument */
        errno = 0;
        int32_t temp = strtol(argv[0], NULL, 0);

        /* Return as status  for monitor testing */
        if (errno == 0)
        {
            status = temp;
        }
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* Get fault reaction                                                       */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_FaultReactionGet(dev_sm_rst_rec_t resetRec,
    // coverity[misra_c_2012_rule_8_13_violation:FALSE]
    uint32_t *reaction, uint32_t *lm)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Print reaction */
    switch (*reaction)
    {
        case LMM_REACT_SYS_RESET:
        case LMM_REACT_SYS_SHUTDOWN:
            ; /* Intentional empty as will print elsewhere */
            break;
        case LMM_REACT_GRP_RESET:
            printf("\nReset group %u", *lm);
            BRD_SM_ResetRecordPrint(",", resetRec);
            break;
        case LMM_REACT_GRP_SHUTDOWN:
            printf("\nShutdown group %u", *lm);
            BRD_SM_ResetRecordPrint(",", resetRec);
            break;
        case LMM_REACT_LM_RESET:
            printf("\nReset LM %u", *lm);
            BRD_SM_ResetRecordPrint(",", resetRec);
            break;
        case LMM_REACT_LM_SHUTDOWN:
            printf("\nShutdown LM %u", *lm);
            BRD_SM_ResetRecordPrint(",", resetRec);
            break;
        case LMM_REACT_BOARD:
            printf("\nBoard %u", *lm);
            BRD_SM_ResetRecordPrint(",", resetRec);
            break;
        case LMM_REACT_FUSA:
            printf("\nFuSa %u", *lm);
            BRD_SM_ResetRecordPrint(",", resetRec);
            break;
        case LMM_REACT_NONE:
            ; /* Intentional empty case */
            break;
        default:
            status = SM_ERR_INVALID_PARAMETERS;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Custom fault handler                                                     */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_CustomFault(dev_sm_rst_rec_t resetRec, uint32_t lm)
{
    /* Return status */
    return SM_ERR_SUCCESS;
}

/*--------------------------------------------------------------------------*/
/* Print reset record                                                       */
/*--------------------------------------------------------------------------*/
void BRD_SM_ResetRecordPrint(string name, dev_sm_rst_rec_t resetRec)
{
    if (resetRec.valid)
    {
        int32_t status;
        string reasonNameAddr;

        /* Get name */
        status = LMM_SystemReasonNameGet(0U, resetRec.reason,
            &reasonNameAddr, NULL);

        /* Print reason */
        printf("%s reason=", name);
        if (status == SM_ERR_SUCCESS)
        {
            printf("%s", reasonNameAddr);
        }
        else
        {
            printf("%u", resetRec.reason);
        }
        if (resetRec.validErr)
        {
            printf(", errId=%d", (int32_t) resetRec.errId);
        }
        if (resetRec.validOrigin)
        {
            printf(", srcLm=%u", resetRec.origin);
        }
        printf("\n");

        /* Print extended info */
        for (uint32_t ex = 0U; ex < resetRec.extLen; ex++)
        {
            printf("  0x%08X\n", resetRec.extInfo[ex]);
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Set mode of specified SoC supply                                         */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SupplyModeSet(uint32_t domain, uint8_t voltMode)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Load for tests */
    if (domain < DEV_SM_NUM_VOLT)
    {
        s_voltMode[domain] = voltMode;
    }
    else
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get mode of specified SoC supply                                         */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SupplyModeGet(uint32_t domain, uint8_t *voltMode)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Load for tests */
    if (domain < DEV_SM_NUM_VOLT)
    {
        *voltMode = s_voltMode[domain];
    }
    else
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set voltage of specified SoC supply                                      */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SupplyLevelSet(uint32_t domain, uint32_t microVolt)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Load for tests */
    if (domain < DEV_SM_NUM_VOLT)
    {
        s_voltLevel[domain] = microVolt;
    }
    else
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get voltage of specified SoC supply                                      */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SupplyLevelGet(uint32_t domain, uint32_t *microVolt)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Load for tests */
    if (domain < DEV_SM_NUM_VOLT)
    {
        *microVolt = s_voltLevel[domain];
    }
    else
    {
        status = SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

