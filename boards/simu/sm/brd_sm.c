/*
** ###################################################################
**
** Copyright 2023-2026 NXP
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

#define BRD_SM_RST_REC_FIRST  0U     /* First GPR for shutdown record */
#define BRD_SM_RST_REC_NUM    4U     /* Number of GPR for shutdown record */
#define BRD_SM_PMIC_ADDR      8U     /* Simulated PMIC addr */
#define BRD_SM_PMIC_REG       5U     /* Simulated PMIC register number */

/* Defines to encode the reason */
#define BRD_SM_REC_REASON_MASK  (0x000000FFU)
#define BRD_SM_REC_REASON_SHIFT (0U)
#define BRD_SM_REC_REASON(x) \
    (((uint32_t)(((uint32_t)(x)) << BRD_SM_REC_REASON_SHIFT)) & \
    BRD_SM_REC_REASON_MASK)

/* Defines to encode the error ID */
#define BRD_SM_REC_EID_MASK  (0x007FFF00U)
#define BRD_SM_REC_EID_SHIFT (8U)
#define BRD_SM_REC_EID(x) \
    (((uint32_t)(((uint32_t)(x)) << BRD_SM_REC_EID_SHIFT)) & \
    BRD_SM_REC_EID_MASK)
#define BRD_SM_REC_EID_SIGN  (0x00004000U)
#define BRD_SM_REC_EID_EXT   (0xFFFF8000U)

/* Defines to encode the valid flag for the errId */
#define BRD_SM_REC_VERR_MASK  (0x00800000U)
#define BRD_SM_REC_VERR_SHIFT (23U)
#define BRD_SM_REC_VERR(x) \
    (((uint32_t)(((uint32_t)(x)) << BRD_SM_REC_VERR_SHIFT)) & \
    BRD_SM_REC_VERR_MASK)

/* Defines to encode the source/origin */
#define BRD_SM_REC_SRC_MASK  (0x0F000000U)
#define BRD_SM_REC_SRC_SHIFT (24U)
#define BRD_SM_REC_SRC(x) \
    (((uint32_t)(((uint32_t)(x)) << BRD_SM_REC_SRC_SHIFT)) & \
    BRD_SM_REC_SRC_MASK)

/* Defines to encode the valid flag for the source */
#define BRD_SM_REC_VSRC_MASK  (0x10000000U)
#define BRD_SM_REC_VSRC_SHIFT (28U)
#define BRD_SM_REC_VSRC(x) \
    (((uint32_t)(((uint32_t)(x)) << BRD_SM_REC_VSRC_SHIFT)) & \
    BRD_SM_REC_VSRC_MASK)

/* Defines to encode the extended info length */
#define BRD_SM_REC_LEN_MASK  (0x60000000U)
#define BRD_SM_REC_LEN_SHIFT (29U)
#define BRD_SM_REC_LEN(x) \
    (((uint32_t)(((uint32_t)(x)) << BRD_SM_REC_LEN_SHIFT)) & \
    BRD_SM_REC_LEN_MASK)

/* Defines to encode the valid */
#define BRD_SM_REC_VLD_MASK  (0x80000000U)
#define BRD_SM_REC_VLD_SHIFT (31U)
#define BRD_SM_REC_VLD(x) \
    (((uint32_t)(((uint32_t)(x)) << BRD_SM_REC_VLD_SHIFT)) & \
    BRD_SM_REC_VLD_MASK)

#define BRD_SM_NUM_GPR       (8U)

/* Local types */

/* Local variables */

static uint32_t s_gprValue[BRD_SM_NUM_GPR];
static u_int8_t pmicInfo[BRD_SM_PMIC_REG] = {0x20, 0x09, 0x30, 0x00, 0x01};

/*--------------------------------------------------------------------------*/
/* Init board                                                               */
/*--------------------------------------------------------------------------*/
/* coverity[misra_c_2012_directive_4_6_violation] */
int32_t BRD_SM_Init(int argc, const char * const argv[], uint32_t *mSel)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Get the boot mode select */
    if (argc > 1)
    {
        int32_t val = 0;

        /* coverity[misra_c_2012_rule_21_7_violation] */
        val = atoi(argv[1]);

        /* Check the val is positive */
        if (CHECK_I32_POSITIVE(val))
        {
            /* coverity[misra_c_2012_rule_21_7_violation] */
            *mSel = (uint32_t)(val);
        }
        else
        {
            /* Set the status if val is negative */
            status = SM_ERR_INVALID_PARAMETERS;
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Init the device */
        status = DEV_SM_Init();
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Exit function                                                            */
/*--------------------------------------------------------------------------*/
_Noreturn void BRD_SM_Exit(int32_t status, uint32_t pc)
{
    printf("exit %d, 0x%08X\n", status, pc);
    /* coverity[misra_c_2012_rule_21_8_violation] */
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

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get fault reaction                                                       */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_FaultReactionGet(dev_sm_rst_rec_t resetRec,
    /* coverity[misra_c_2012_rule_8_13_violation] */
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
/* Load and clear persistent shutdown record of previous boot               */
/*--------------------------------------------------------------------------*/
void BRD_SM_ShutdownRecordLoad(dev_sm_rst_rec_t *shutdownRec)
{
#if BRD_SM_RST_REC_NUM > 0
    uint32_t hdr = 0U;
    uint32_t *ePtr = &(shutdownRec->extInfo[0]);

    /* Read and clear header */
    hdr = s_gprValue[BRD_SM_RST_REC_FIRST];
    s_gprValue[BRD_SM_RST_REC_FIRST] = 0U;

    /* Valid? */
    if (((hdr & BRD_SM_REC_VLD_MASK ) >> BRD_SM_REC_VLD_SHIFT) != 0U)
    {
        shutdownRec->valid = true;

        /* Parse header */
        shutdownRec->reason = (hdr & BRD_SM_REC_REASON_MASK ) >>
            BRD_SM_REC_REASON_SHIFT;
        shutdownRec->errId = (hdr & BRD_SM_REC_EID_MASK ) >>
            BRD_SM_REC_EID_SHIFT;
        shutdownRec->validErr = ((hdr & BRD_SM_REC_VERR_MASK ) != 0U);
        shutdownRec->origin = (hdr & BRD_SM_REC_SRC_MASK ) >>
            BRD_SM_REC_SRC_SHIFT;
        shutdownRec->validOrigin = ((hdr & BRD_SM_REC_VSRC_MASK ) != 0U);
        shutdownRec->extLen = (hdr & BRD_SM_REC_LEN_MASK ) >>
            BRD_SM_REC_LEN_SHIFT;

        /* Sign extend */
        if ((shutdownRec->errId & BRD_SM_REC_EID_SIGN) != 0U)
        {
            shutdownRec->errId |= BRD_SM_REC_EID_EXT;
        }

        shutdownRec->extLen = MIN(shutdownRec->extLen, DEV_SM_NUM_EXT_INFO);
    }

    /* Copy out extended info */
    for (uint8_t idx = 1U; idx < BRD_SM_RST_REC_NUM; idx++)
    {
        if (idx <= shutdownRec->extLen)
        {
            *ePtr = s_gprValue[idx + BRD_SM_RST_REC_FIRST];
            ePtr++;
        }
        else
        {
            break;
        }
    }
#endif

}

/*--------------------------------------------------------------------------*/
/* Save shutdown record to persistent storage                               */
/*--------------------------------------------------------------------------*/
void BRD_SM_ShutdownRecordSave(dev_sm_rst_rec_t shutdownRec)
{
#if BRD_SM_RST_REC_NUM > 0
    uint32_t hdr;
    const uint32_t *ePtr = &(shutdownRec.extInfo[0]);

    /* Store extended info */
    for (uint8_t idx = 1U; idx < BRD_SM_RST_REC_NUM; idx++)
    {
        if (idx <= shutdownRec.extLen)
        {
            s_gprValue[idx + BRD_SM_RST_REC_FIRST] = *ePtr;
            ePtr++;
        }
        else
        {
            break;
        }
    }

    /* Create header */
    hdr = BRD_SM_REC_REASON(shutdownRec.reason)
        | BRD_SM_REC_EID(shutdownRec.errId)
        | BRD_SM_REC_VERR(shutdownRec.validErr ? 1U : 0U)
        | BRD_SM_REC_SRC(shutdownRec.origin)
        | BRD_SM_REC_VSRC(shutdownRec.validOrigin ? 1U : 0U)
        | BRD_SM_REC_LEN(shutdownRec.extLen)
        | BRD_SM_REC_VLD(shutdownRec.valid ? 1U : 0U);

    /* Save header */
    s_gprValue[BRD_SM_RST_REC_FIRST] = hdr;
#endif

    /* Print shutdown record */
    if (shutdownRec.reset)
    {
        BRD_SM_ResetRecordPrint("\nReset request:", shutdownRec);
    }
    else
    {
        BRD_SM_ResetRecordPrint("\nShutdown request:", shutdownRec);
    }
}

/*--------------------------------------------------------------------------*/
/* Get PMIC info                                                            */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_PmicInfoGet(uint32_t idx, uint8_t *devAddr, uint8_t **info,
    uint8_t *len)
{
    int32_t status = SM_ERR_SUCCESS;

    if (idx == 0U)
    {
        *devAddr = BRD_SM_PMIC_ADDR;
        *info = pmicInfo;
        *len = BRD_SM_PMIC_REG;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* PMIC register write                                                      */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_PmicWrite(uint8_t devAddr, uint8_t regAddr, uint8_t val,
    uint8_t mask)
{
    int32_t status = SM_ERR_SUCCESS;

    if (devAddr == BRD_SM_PMIC_ADDR)
    {
        if (regAddr < BRD_SM_PMIC_REG)
        {
            pmicInfo[regAddr] = val;
        }
        else
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }
    else
    {
        /* Invalid device address */
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* PMIC register read                                                       */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_PmicRead(uint8_t devAddr, uint8_t regAddr, uint8_t *val)
{
    int32_t status = SM_ERR_SUCCESS;

    if (devAddr == BRD_SM_PMIC_ADDR)
    {
        if (regAddr < BRD_SM_PMIC_REG)
        {
            *val = pmicInfo[regAddr];
        }
        else
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }
    else
    {
        /* Invalid device address */
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}


/*--------------------------------------------------------------------------*/
/* Set mode of specified SoC supply                                         */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SupplyModeSet(uint32_t domain, uint8_t voltMode)
{
    /* Set voltage mode */
    return BRD_SM_VoltageModeSet(domain, voltMode);
}

/*--------------------------------------------------------------------------*/
/* Get mode of specified SoC supply                                         */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SupplyModeGet(uint32_t domain, uint8_t *voltMode)
{
    /* Get voltage mode */
    return BRD_SM_VoltageModeGet(domain, voltMode);
}

/*--------------------------------------------------------------------------*/
/* Set voltage of specified SoC supply                                      */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SupplyLevelSet(uint32_t domain, int32_t microVolt)
{
    /* Set voltage level */
    return BRD_SM_VoltageLevelSet(domain, microVolt);
}

/*--------------------------------------------------------------------------*/
/* Get voltage of specified SoC supply                                      */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SupplyLevelGet(uint32_t domain, int32_t *microVolt)
{
    /* Get voltage level */
    return BRD_SM_VoltageLevelGet(domain, microVolt);
}

