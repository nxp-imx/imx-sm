/*
** ###################################################################
**
**     Copyright 2026 NXP
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/* File containing the implementation of the device memory.                 */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "fsl_ddr.h"
#ifdef USES_RX_REPLICA
#include "fsl_ddr_rx_replica.h"
#endif

/* Local defines */

/* Local types */

/* Local variables */

static BLK_CTRL_DDRMIX_Type s_ddrBlkCtrl;
static struct dram_info info;
#ifdef USES_RX_REPLICA
static ddr_rxclkdelay_wa_data_t s_rxClkDelay;
static uint32_t s_ddrMseconds = 0U;
#endif

/* Local functions */

#ifdef USES_RX_REPLICA
static void DEV_SM_RxReplicaInit(void);
static void DEV_SM_RxReplicaDeinit(void);
static void DEV_SM_RxReplicaReinit(void);
#endif

/* Externs */

/*! External pointer to the DDR info */
extern uint32_t *__DdrInfo;

/*--------------------------------------------------------------------------*/
/* Initialize memory functions                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_MemInit(void)
{
    /* Default to no DDR regions */
    info.totalRegions = 0U;

    /* Check power state of DDRMIX */
    if (SRC_MixIsPwrReady(DEV_SM_PD_DDR))
    {
        const struct ddr_info *ddr = (struct ddr_info*) &__DdrInfo;

#ifdef USES_RX_REPLICA
        /* Init RX Replica workaround */
        DEV_SM_RxReplicaInit();
#endif

        /* Get DDR info */
        if (!DDR_GetDRAMInfo(ddr, &info))
        {
            info.totalRegions = 0U;
        }
    }

    /* Return status */
    return SM_ERR_SUCCESS;
}

/*--------------------------------------------------------------------------*/
/* Return DDR memory region info                                            */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_MemDdrInfoGet(uint32_t ddrRgdId, uint32_t *numRgd,
    uint32_t *ddrType, uint32_t *ddrWidth, bool *eccEnb, uint32_t *mts,
    uint64_t *startAddr, uint64_t *endAddr)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Check if the DDR was powered and initialized */
    if (info.totalRegions == 0U)
    {
        status = SM_ERR_POWER;
    }
    /* Check region */
    else if (ddrRgdId == 0U)
    {
        *numRgd = info.totalRegions;
        *ddrWidth = info.sdramDatabusWidth;
        *eccEnb = info.eccEnb;
        *mts = info.mts;
        *startAddr = info.startAddr;
        *endAddr = info.endAddr;

        /* Map DDRC SDRAM type to api */
        if (info.sdramType == 0x4U)
        {
            *ddrType = DEV_SM_DDR_TYPE_LPDDR4X;
        }
        else
        {
            *ddrType = DEV_SM_DDR_TYPE_LPDDR5;
        }
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Place the DDR into retention                                             */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_MemDdrRetentionEnter(void)
{
    int32_t status = SM_ERR_SUCCESS;
    const struct ddr_info* ddr = (struct ddr_info*) &__DdrInfo;
    uint8_t powerState = DEV_SM_POWER_STATE_OFF;

    /* Get power state of DDRMIX */
    status = DEV_SM_PowerStateGet(DEV_SM_PD_DDR, &powerState);
    if (status == SM_ERR_SUCCESS)
    {
        /* DDRMIX must be ON to apply retention */
        if (powerState != DEV_SM_POWER_STATE_ON)
        {
            status = SM_ERR_POWER;
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Save DDRMIX block control */
        s_ddrBlkCtrl.HWFFC_CTRL = BLK_CTRL_DDRMIX->HWFFC_CTRL;
        s_ddrBlkCtrl.DDRC_STOP_CTRL = BLK_CTRL_DDRMIX->DDRC_STOP_CTRL;
        s_ddrBlkCtrl.AUTO_CG_CTRL = BLK_CTRL_DDRMIX->AUTO_CG_CTRL;
        s_ddrBlkCtrl.DDRC_EXCLUSIVE_EN = BLK_CTRL_DDRMIX->DDRC_EXCLUSIVE_EN;
        s_ddrBlkCtrl.DDRC_URGENT_EN = BLK_CTRL_DDRMIX->DDRC_URGENT_EN;
        s_ddrBlkCtrl.RT_MASTER_ID_0_1 = BLK_CTRL_DDRMIX->RT_MASTER_ID_0_1;
        s_ddrBlkCtrl.RT_MASTER_ID_2_3 = BLK_CTRL_DDRMIX->RT_MASTER_ID_2_3;
        s_ddrBlkCtrl.AXI_PARITY_ERR_INJECT =
            BLK_CTRL_DDRMIX->AXI_PARITY_ERR_INJECT;
        s_ddrBlkCtrl.RT_MASTER_ID_4_5 = BLK_CTRL_DDRMIX->RT_MASTER_ID_4_5;
        s_ddrBlkCtrl.RT_MASTER_ID_6_7 = BLK_CTRL_DDRMIX->RT_MASTER_ID_6_7;

#ifdef USES_RX_REPLICA
        DEV_SM_RxReplicaDeinit();
#endif

        /* Enter retention */
        if (!DDR_EnterRetention(ddr))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Assert DDRPHY Reset */
        if (!SRC_MixSetResetLine(RST_LINE_DDRPHY_RESETN,
            RST_LINE_CTRL_ASSERT))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Deassert BP_PWROK */
        if (!SRC_MixSetResetLine(RST_LINE_DDRMIX_PHY,
            RST_LINE_CTRL_DEASSERT))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Exit the DDR from retention                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_MemDdrRetentionExit(void)
{
    int32_t status = SM_ERR_SUCCESS;
    const struct ddr_info* ddr = (struct ddr_info*) &__DdrInfo;
    uint8_t powerState = DEV_SM_POWER_STATE_OFF;

    /* Get power state of DDRMIX */
    status = DEV_SM_PowerStateGet(DEV_SM_PD_DDR, &powerState);
    if (status == SM_ERR_SUCCESS)
    {
        /* DDRMIX must be ON to remove retention */
        if (powerState != DEV_SM_POWER_STATE_ON)
        {
            status = SM_ERR_POWER;
        }
    }

    /**
     * BIT(8) => src_ipc_ddrphy_presetn, PRESETN
     * BIT(9) => src_ipc_ddrphy_reset_n, RESET_N
     * for some reason BIT(8)=1 at this point, so PRESETN go LOW after power-up
     * Ensure PRESETN go HIGH after power-up
     * Ensure RESET_N go LOW  after power-up
     */
    if (status == SM_ERR_SUCCESS)
    {
        if (!SRC_MixSetResetLine(RST_LINE_DDRPHY_PRESETN, RST_LINE_CTRL_DEASSERT))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* sleep for a while, just random */
        SystemTimeDelay(15U);

        /* set PRESETN LOW after power-up */
        if (!SRC_MixSetResetLine(RST_LINE_DDRPHY_PRESETN,
            RST_LINE_CTRL_ASSERT))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* The delay below must be at least 16 APBCLK
         * APBCLK is @200MHz in waveform. Timer clock is @24MHz =>
         * => (16 * 24.000.000 / 200.000.000) = 1.92us minimum
         * => set x4 = 8us */
        SystemTimeDelay(15U);

        /* set PRESETN HIGH */
        if (!SRC_MixSetResetLine(RST_LINE_DDRPHY_PRESETN,
            RST_LINE_CTRL_DEASSERT))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* The delay below shall be 0 according to PHY PUB, set 8 just in case */
        SystemTimeDelay(15U);

        /* set RESET_N HIGH */
        if (!SRC_MixSetResetLine(RST_LINE_DDRPHY_RESETN,
            RST_LINE_CTRL_DEASSERT))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* The duration for the delay below is not mentioned in PHY PUB,
           set 8 just in case */
        SystemTimeDelay(15U);

        status = DEV_SM_ClockEnable(DEV_SM_CLK_DRAMPLL_VCO, true);
    }

    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_ClockEnable(DEV_SM_CLK_DRAMPLL, true);
    }

    if (status == SM_ERR_SUCCESS)
    {
        /* Exit retention */
        if (!DDR_ExitRetention(ddr))
        {
            status = SM_ERR_HARDWARE_ERROR;
        }

        /* Restore DDRMIX block control */
        BLK_CTRL_DDRMIX->HWFFC_CTRL = s_ddrBlkCtrl.HWFFC_CTRL;
        BLK_CTRL_DDRMIX->DDRC_STOP_CTRL = s_ddrBlkCtrl.DDRC_STOP_CTRL;
        BLK_CTRL_DDRMIX->AUTO_CG_CTRL = s_ddrBlkCtrl.AUTO_CG_CTRL;
        BLK_CTRL_DDRMIX->DDRC_EXCLUSIVE_EN = s_ddrBlkCtrl.DDRC_EXCLUSIVE_EN;
        BLK_CTRL_DDRMIX->DDRC_URGENT_EN = s_ddrBlkCtrl.DDRC_URGENT_EN;
        BLK_CTRL_DDRMIX->RT_MASTER_ID_0_1 = s_ddrBlkCtrl.RT_MASTER_ID_0_1;
        BLK_CTRL_DDRMIX->RT_MASTER_ID_2_3 = s_ddrBlkCtrl.RT_MASTER_ID_2_3;
        BLK_CTRL_DDRMIX->AXI_PARITY_ERR_INJECT =
            s_ddrBlkCtrl.AXI_PARITY_ERR_INJECT;
        BLK_CTRL_DDRMIX->RT_MASTER_ID_4_5 = s_ddrBlkCtrl.RT_MASTER_ID_4_5;
        BLK_CTRL_DDRMIX->RT_MASTER_ID_6_7 = s_ddrBlkCtrl.RT_MASTER_ID_6_7;

#ifdef USES_RX_REPLICA
        /* Perform one-time RxReplica work-around prior to DDR accesses and
         * before enabling periodic operation */
        DEV_SM_RxReplicaReinit();
#endif
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Memory timer tick                                                        */
/*--------------------------------------------------------------------------*/
void DEV_SM_MemTick(uint32_t msec)
{
#ifdef USES_RX_REPLICA
    /* Tick DDR */
    /*
     * False Positive: The msec value is 10
     * and the base rolls to 0 at 1000.
     */
    /* coverity[cert_int30_c_violation:FALSE] */
    s_ddrMseconds += msec;

    /* Handle DDR periodic tick */
    if (s_ddrMseconds >= 1000U)
    {
        s_ddrMseconds = 0U;
        DDR_RxReplicaWa(&s_rxClkDelay, 16U);
    }
#endif
}

/*==========================================================================*/

#ifdef USES_RX_REPLICA
/*--------------------------------------------------------------------------*/
/* DDR RX Replica workaround Init                                           */
/*--------------------------------------------------------------------------*/
static void DEV_SM_RxReplicaInit(void)
{
    uint64_t rate;
    int32_t status = SM_ERR_SUCCESS;

    status = DEV_SM_ClockRateGet(DEV_SM_CLK_DRAMPLL, &rate);

    if (status == SM_ERR_SUCCESS)
    {
        s_rxClkDelay.dramFreqMhz = U64_U32(rate / 1000000U);
        s_rxClkDelay.pmro = DEV_SM_FuseGet(DEV_SM_FUSE_PMRO);

        (void) DDR_RxClkDelayInit(&s_rxClkDelay, DDR_RXCLK_DELAY_CNT);
    }
}

/*--------------------------------------------------------------------------*/
/* DDR RX Replica workaround Deinit                                         */
/*--------------------------------------------------------------------------*/
static void DEV_SM_RxReplicaDeinit(void)
{
    s_rxClkDelay.initComplete = false;
    s_ddrMseconds = 0U;
}

/*--------------------------------------------------------------------------*/
/* DDR RX Replica workaround Reinit                                         */
/*--------------------------------------------------------------------------*/
static void DEV_SM_RxReplicaReinit(void)
{
    s_ddrMseconds = 0U;
    s_rxClkDelay.initComplete = true;
    DDR_RxReplicaWa(&s_rxClkDelay, 128U);
}
#endif

