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

#include "sm.h"
#include "brd_sm.h"
#include "dev_sm.h"
#include "lmm.h"
#include "fsl_lpi2c.h"
#include "fsl_bbnsm.h"
#include "fsl_rgpio.h"
#include "fsl_iomuxc.h"

/* Local defines */

#define BRD_SM_RST_REC_FIRST  4U     /* First GPR for shutdown record */
#define BRD_SM_RST_REC_NUM    4U     /* Number of GPR for shutdown record */

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

/* Performance parameters */
#define BOARD_BOOT_LEVEL  DEV_SM_PERF_LVL_ODV  /* Boot perf level */
#define BOARD_PERF_LEVEL  DEV_SM_PERF_LVL_ODV  /* Target perf level */
#define BOARD_PERF_VDROP  20000                /* Perf voltage drop */

/* Local types */

/* Local variables */

/* Local functions */

static int32_t BRD_SM_InitComplete(uint32_t mSel);

/*--------------------------------------------------------------------------*/
/* Init board                                                               */
/*--------------------------------------------------------------------------*/
// coverity[misra_c_2012_directive_4_6_violation:FALSE]
int32_t BRD_SM_Init(int argc, const char * const argv[], uint32_t *mSel)
{
    int32_t status;
    uint64_t addr;
    uint32_t ms;
    uint32_t flags;

    /* Init board hardware */
    BOARD_InitHardware();

    /* Get the boot mode select */
    if (DEV_SM_RomBootCpuGet(DEV_SM_CPU_M33P, &addr, &ms, &flags)
        == SM_ERR_SUCCESS)
    {
        *mSel = ms;
    }

    /* Initialize devices connected to serial buses (PMIC, IOExp, etc) */
    status = BRD_SM_SerialDevicesInit();

    if (status == SM_ERR_SUCCESS)
    {
        /* Init the device */
        status = DEV_SM_Init(BOARD_BOOT_LEVEL, BOARD_PERF_LEVEL);
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Complete board init after device init */
        status = BRD_SM_InitComplete(*mSel);
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Disallow ANA TMPSNS to generate internal warm reset */
        SRC_GEN->SRMASK |= BIT32(RST_REASON_TEMPSENSE);

        /* Switch WDOG to FCCU mode */
        BOARD_WdogModeSet(BOARD_WDOG_MODE_FCCU);
    }

    /* TODO: Remove when A0 support dropped */
    /* Configure ISO controls based on feature fuses */
    uint32_t ipIsoMask = 0U;

    /* Deassert PCIe ISO if corresponding module is enabled */
    uint32_t fuseHwCfg2 = FSB->FUSE[FSB_FUSE_HW_CFG2];

    /* PCIe1 is tied to HSIO ISO[0] */
    if ((fuseHwCfg2 & FSB_FUSE_HW_CFG2_PCIE1_DISABLE_MASK) == 0U)
    {
        ipIsoMask |= SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_0_MASK;
    }

    /* PCIe2 is tied to HSIO ISO[1] */
    if ((fuseHwCfg2 & FSB_FUSE_HW_CFG2_PCIE2_DISABLE_MASK) == 0U)
    {
        ipIsoMask |= SRC_XSPR_SLICE_SW_CTRL_ISO_CTRL_1_MASK;
    }

    /* Apply ISO mask */
    if (ipIsoMask != 0U)
    {
        SRC_XSPR_HSIOMIX_TOP->SLICE_SW_CTRL &= (~ipIsoMask);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Exit function                                                            */
/*--------------------------------------------------------------------------*/
void BRD_SM_Exit(int32_t status, uint32_t pc)
{
#if defined(MONITOR) || defined(RUN_TEST)
    printf("exit %d, 0x%08X\n", status, pc);

    /* Disable watchdog */
    BOARD_WdogModeSet(BOARD_WDOG_MODE_OFF);
#else
    SM_SYSTEMERROR(status, pc);
    // coverity[misra_c_2012_rule_2_2_violation:FALSE]
    SystemExit();
#endif

    /* Hang */
    while (true)
    {
        ; /* Intentional empty while */
    }
}

/*--------------------------------------------------------------------------*/
/* Board timer tick                                                         */
/*--------------------------------------------------------------------------*/
void BRD_SM_TimerTick(uint32_t msec)
{
    /* Kick the dog */
    BOARD_WdogRefresh();
}

/*--------------------------------------------------------------------------*/
/* Custom monitor function                                                  */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_Custom(int32_t argc, const char * const argv[])
{
    return SM_ERR_SUCCESS;
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
    switch(*reaction)
    {
        case LMM_REACT_SYS_RESET:
        case LMM_REACT_SYS_SHUTDOWN:
            ; /* Intentional empty as will print elsewhere */
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
    (void) BBNSM_GprGetValue(BBNSM, BRD_SM_RST_REC_FIRST, &hdr);
    (void) BBNSM_GprSetValue(BBNSM, BRD_SM_RST_REC_FIRST, 0U);

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
            (void) BBNSM_GprGetValue(BBNSM, idx + BRD_SM_RST_REC_FIRST,
                ePtr);
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
            (void) BBNSM_GprSetValue(BBNSM, idx + BRD_SM_RST_REC_FIRST,
                *ePtr);
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
    (void) BBNSM_GprSetValue(BBNSM, BRD_SM_RST_REC_FIRST, hdr);
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
/* Reset board                                                              */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SystemReset(void)
{
    int32_t status = SM_ERR_SUCCESS;
    rgpio_pin_config_t gpioConfig =
    {
        kRGPIO_DigitalOutput,
        0U
    };

    /* Drive WDOG_ANY to reset PMIC */
    RGPIO_PinInit(GPIO1, 15U, &gpioConfig);
    IOMUXC_SetPinMux(IOMUXC_PAD_WDOG_ANY__GPIO1_IO_BIT15, 0U);

    /* Wait for PMIC to react */
    SystemTimeDelay(1000U);

    /* Fall back to warm reset of the device */
    status = DEV_SM_SystemReset();

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get PMIC info                                                            */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_PmicInfoGet(uint32_t idx, uint8_t *devAddr, uint8_t **info,
    uint8_t *len)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Call PMIC driver to get info */
    switch (idx)
    {
        case 0U:
            *devAddr = pf09Dev.devAddr;
            if (!PF09_PmicInfoGet(&pf09Dev, info, len))
            {
                status = SM_ERR_HARDWARE_ERROR;
            }
            break;
        case 1U:
            *devAddr = pf5301Dev.devAddr;
            if (!PF53_PmicInfoGet(&pf5301Dev, info, len))
            {
                status = SM_ERR_HARDWARE_ERROR;
            }
            break;
        case 2U:
            *devAddr = pf5302Dev.devAddr;
            if (!PF53_PmicInfoGet(&pf5302Dev, info, len))
            {
                status = SM_ERR_HARDWARE_ERROR;
            }
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
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

    /* Call PF09 driver write data */
    if (devAddr == pf09Dev.devAddr)
    {
        if (!PF09_PmicWrite(&pf09Dev, regAddr, val, mask))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }
    /* Call PF5301 driver write data */
    else if (devAddr == pf5301Dev.devAddr)
    {
        if (!PF53_PmicWrite(&pf5301Dev, regAddr, val, mask))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }
    /* Call PF5302 driver write data */
    else if (devAddr == pf5302Dev.devAddr)
    {
        if (!PF53_PmicWrite(&pf5302Dev, regAddr, val, mask))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }
    /* Invalid device address */
    else
    {
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

    /* Call PF09 driver read data */
    if (devAddr == pf09Dev.devAddr)
    {
        if (!PF09_PmicRead(&pf09Dev, regAddr, val))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }
    /* Call PF5301 driver read data */
    else if (devAddr == pf5301Dev.devAddr)
    {
        if (!PF53_PmicRead(&pf5301Dev, regAddr, val))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }
    /* Call PF5302 driver read data */
    else if (devAddr == pf5302Dev.devAddr)
    {
        if (!PF53_PmicRead(&pf5302Dev, regAddr, val))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }
    /* Invalid device address */
    else
    {
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
int32_t BRD_SM_SupplyLevelSet(uint32_t domain, uint32_t microVolt)
{
    /* Set voltage level */
    return BRD_SM_VoltageLevelSet(domain, ((int32_t) microVolt)
        + BOARD_PERF_VDROP);
}

/*--------------------------------------------------------------------------*/
/* Get voltage of specified SoC supply                                      */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SupplyLevelGet(uint32_t domain, uint32_t *microVolt)
{
    /* Get voltage level */
    return BRD_SM_VoltageLevelGet(domain, (int32_t*) microVolt);
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Complete init after DEV_SM init                                          */
/*--------------------------------------------------------------------------*/
static int32_t BRD_SM_InitComplete(uint32_t mSel)
{
    /* Safe to call DEV_SM functions to init hardware. For example, to
       enabled a power domain, configure a clock SSC, clock rate, or pin.
       Not safe to call LMM functions! */

    return SM_ERR_SUCCESS;
}

