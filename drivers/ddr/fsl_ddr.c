/*
 ** ###################################################################
 **
 **     Copyright 2024-2025 NXP
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
/* File containing the implementation of the DDR Retention.                 */
/*==========================================================================*/

/* Includes */

#include "fsl_ddr.h"
#include "fsl_sysctr.h"

/* Local Defines */

#define DEBUG_2   (DDRC_BASE + 0xF04U)
#define DEBUG_26  (DDRC_BASE + 0xF64U)
#define REF_RATE_MULTIPLIER 0xFU

/* Local Variables */

static bool s_srFastWakeEn = false;

/* Local Functions */

static bool DDR_CheckDdrcIdle(uint32_t flag);
static bool DDR_DdrcMrs(uint32_t csSel, uint32_t opcode, uint32_t mr);
static bool DDR_MrWrite(uint32_t mrRank, uint32_t mrAddr, uint32_t mrData);
static bool DDR_PhyInit(const struct ddr_info *ddrp);
static bool DDR_CheckDfiInitComplete(void);
static bool DDR_DdrcInit(const struct ddr_info *ddrp);
static uint32_t DDR_GetRefreshDivider(void);

/*--------------------------------------------------------------------------*/
/* DDR Enter Retention                                                      */
/*--------------------------------------------------------------------------*/
bool DDR_EnterRetention(const struct ddr_info *ddrp)
{
    bool rc;

    if (ddrp != NULL)
    {
        uint32_t eccEn = 0U;
        uint32_t waitFlag = 0U;

        /* Is ECC enabled? */
        if ((DDRC->ERR_EN & DDRC_ERR_EN_INLINE_ECC_EN_MASK) != 0U)
        {
            eccEn = 1U;
        }

        /* Check if TX_CFG_1 WWATER enabled with ECC */
        if ((eccEn == 1U) && ((DDRC->TX_CFG_1 &
            DDRC_TX_CFG_1_WWATER_MASK) != 0U))
        {
            DDRC->TX_CFG_1 &= ~DDRC_TX_CFG_1_WWATER_MASK;
        }

        /* Save fast wake state */
        s_srFastWakeEn = ((DDRC->DDR_SDRAM_CFG_3 &
            DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_MASK) != 0U);

        /* Update wait flag as per ECC enabled */
        if (eccEn == 1U)
        {
            waitFlag = (DDRC_DDRDSR_2_NML_MASK | DDRC_DDRDSR_2_IDLE_MASK);
        }
        else
        {
            waitFlag = DDRC_DDRDSR_2_IDLE_MASK;
        }

        /* Polling for DDRDSR_2[IDLE] & ECC complete to be set */
        rc  = DDR_CheckDdrcIdle(waitFlag);

        if (rc)
        {
            uint32_t altTrnInt = 0U;
            uint32_t dynRefEn = 0U;
            uint32_t val = 0U;
            uint32_t refIntOriginal;

            /* ERR052794:
             * Step 1, Wait for IDLE, previously performed above.
             * Step 2: Clear (disable) DDR_SDRAM_CFG_3[DYN_REF_RATE_EN] and
             *         DDR_SDRAM_CFG_6[ALT_TRN_INT] (MRR snoop)
             *
             * Note: When DYN_REF is disabled, the auto refresh rate is
             * reverted back to nominal (1x). However, if the DRAM requires
             * a higher refresh rate at elevated temperatures, we need to
             * adjust the DDR_SDRAM_INTERVAL[REFINT] to compensate for
             * this while DYN_REF is disabled and then restore the
             * original value when re-enabling DYN_REF.
             * Get original refint to restore later in case DYN_REF enable
             */
            refIntOriginal = ((DDRC->DDR_SDRAM_INTERVAL &
                DDRC_DDR_SDRAM_INTERVAL_REFINT_MASK) >>
                DDRC_DDR_SDRAM_INTERVAL_REFINT_SHIFT);

            /* Disable ALT_TRN_INT if enabled */
            if ((DDRC_CTRL->DDR_SDRAM_CFG_6 &
                 DDRC_DDR_SDRAM_CFG_6_ALT_TRN_INT_MASK) != 0U)
            {
                /* Save altTrnInt setting (MRR snoop interval) to
                   restore later */
                altTrnInt = ((DDRC_CTRL->DDR_SDRAM_CFG_6 &
                    DDRC_DDR_SDRAM_CFG_6_ALT_TRN_INT_MASK) >>
                    DDRC_DDR_SDRAM_CFG_6_ALT_TRN_INT_SHIFT);

                /* Disable MRR snoop, set altTrnInt = 0 */
                DDRC_CTRL->DDR_SDRAM_CFG_6 &=
                    (~DDRC_DDR_SDRAM_CFG_6_ALT_TRN_INT_MASK);

                /* Delay to ensure all MRR Snoop (ALT_TRN_INT) operations are
                   complete prior to any MRR/MRW
                 */
                SystemTimeDelay(100U);
            }

            /* Disable DYN_REF if enabled */
            if ((DDRC->DDR_SDRAM_CFG_3 &
                 DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_MASK) != 0U)
            {
                uint32_t refint, refRateDivider;

                /* Save dyn_ref_Rate_en setting to restore later */
                dynRefEn = ((DDRC->DDR_SDRAM_CFG_3 &
                    DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_MASK) >>
                    DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_SHIFT);

                /* Get the maximum reported refresh rate divider to apply to
                 * refresh rate interval: div-by-1, 2, 4, or 8 (LP5 only) */
                refRateDivider = DDR_GetRefreshDivider();
                /* Apply refresh rate divider */
                refint = refIntOriginal/refRateDivider;

                /* Before disabling DYN_REF_RATE_EN, check MPR5[MPR_VLD] for
                 * latest MR4 to complete */
                /* clear MPR_VLD so that the next MR4 read will set it */
                DDRC_CTRL->DDR_SDRAM_MPR5 = 0x0U;

                /* Wait till MPR_VLD is set (MR4 read done) then immediately
                 * disable DYN_REF */
                while ((DDRC_CTRL->DDR_SDRAM_MPR5 & 0x1U) == 0U)
                {
                    ; /* Intentional empty while */
                }

                /* Disable dyn_ref_rate_en */
                DDRC->DDR_SDRAM_CFG_3 &=
                    (~DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN_MASK);

                /* Update DDR_SDRAM_INTERVAL[REFINT] to compensate for
                 * elevated temperature */
                val = DDRC_CTRL->DDR_SDRAM_INTERVAL;
                val &= (~DDRC_DDR_SDRAM_INTERVAL_REFINT_MASK);
                val |= DDRC_DDR_SDRAM_INTERVAL_REFINT(refint);
                DDRC_CTRL->DDR_SDRAM_INTERVAL = val;
            }

            /* MEM HALT */
            DDRC->DDR_SDRAM_CFG
                |= (1U << DDRC_DDR_SDRAM_CFG_MEM_HALT_SHIFT);

            /* Check if LPDDR5 */
            if ((Read32(&DDRC->DDR_SDRAM_CFG) &
                (1UL << DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_SHIFT)) != 0U)
            {
                /* STOP ZQCAL for two ranks */
                rc = DDR_MrWrite(3U, 28U, 2U);
                /* Wait tZQSTOP(30ns) */
                SystemTimeDelay(1U);
            }

            if (rc)
            {
                /* PState set as 0x1F: Retention/Enter LP3 */
                DDRC->DDR_SDRAM_CFG_4 &=
                    ~(0x3FFU << DDRC_DDR_SDRAM_CFG_4_FRQCH_RET_SHIFT);

                /* Why DEBUG_26 ? */
                Write32(DEBUG_26, Read32(DEBUG_26) | (0x1FUL << 12U));

                /* Clear SR_FAST_WK_EN */
                DDRC->DDR_SDRAM_CFG_3 &=
                    ~(1U << DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_SHIFT);

                /* Clear DDR_ZQ_CNTL register */
                DDRC->DDR_ZQ_CNTL = 0x0U;

                /* We will want to set DDR_SDRAM_CFG_3[4] to force the */
                /* PD entry by the DDRC for retention mode only. */
                DDRC->DDR_SDRAM_CFG_3 |= (1U << 4U);

                /* Force the DDRC to enter self refresh */
                DDRC->DDR_SDRAM_CFG_2 |=
                    (1UL << DDRC_DDR_SDRAM_CFG_2_FRC_SR_SHIFT);

                /* ERR052794:
                 * Step 3: Enter self refresh, previously performed above
                 * Step 4: Wait DEBUG_2[3] (SR) to be set
                 *         If SR=1: Memory controller is in self refresh
                 */
                while ((Read32(DEBUG_2) & 0x4U) != 0U)
                {
                    ; /* Intentional empty while */
                }

                /* Clear PHY INIT complete: BIT2 PHY_INIT_CMPLT W1C */
                do
                {
                    DDRC->DDRDSR_2 |=
                        (1U << DDRC_DDRDSR_2_PHY_INIT_CMPLT_SHIFT);
                }
                while ((DDRC->DDRDSR_2 &
                    (1U << DDRC_DDRDSR_2_PHY_INIT_CMPLT_SHIFT)) != 0U);

                /* Clear DDR_INTERVAL(this disables refreshes */
                DDRC->DDR_SDRAM_INTERVAL = 0x0U;

                /* Set DDR_SDRAM_MD_CNTL (forces CKE to remain low) */
                DDRC->DDR_SDRAM_MD_CNTL =
                    (1UL << DDRC_DDR_SDRAM_MD_CNTL_MD_EN_SHIFT) |
                    (1UL << DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL_SHIFT);

                /* T_STAB */
                DDRC->TIMING_CFG_10 |=
                    (0x7FFFU << DDRC_TIMING_CFG_10_T_STAB_SHIFT);

                /* ERR052794:
                 * Step 5: After self-refresh entry, restore:
                 *         CFG_6[ALT_TRN_INT] and CFG_3[DYN_REF_RATE_EN]
                 */
                val = DDRC_CTRL->DDR_SDRAM_CFG_6;
                val &= (~DDRC_DDR_SDRAM_CFG_6_ALT_TRN_INT_MASK);
                val |=  DDRC_DDR_SDRAM_CFG_6_ALT_TRN_INT(altTrnInt);
                DDRC_CTRL->DDR_SDRAM_CFG_6 = val;

                /* Before enabling DYN_REF, restore REFINT */
                val = DDRC->DDR_SDRAM_INTERVAL;
                val &= (~DDRC_DDR_SDRAM_INTERVAL_REFINT_MASK);
                val |= DDRC_DDR_SDRAM_INTERVAL_REFINT(refIntOriginal);
                DDRC->DDR_SDRAM_INTERVAL = val;

                /* Restore dyn_ref_rate_en */
                DDRC->DDR_SDRAM_CFG_3 |=
                        DDRC_DDR_SDRAM_CFG_3_DYN_REF_RATE_EN(dynRefEn);

                /* Exit self refresh */
                DDRC->DDR_SDRAM_CFG_2 &=
                    ~(1UL << DDRC_DDR_SDRAM_CFG_2_FRC_SR_SHIFT);

                /* Wait PHY INIT complete */
                while ((DDRC->DDRDSR_2 &
                    (1U << DDRC_DDRDSR_2_PHY_INIT_CMPLT_SHIFT)) == 0U)
                {
                    ; /* Intentional empty while */
                }
            }
        }
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* DDR Exit Retention                                                       */
/*--------------------------------------------------------------------------*/
bool DDR_ExitRetention(const struct ddr_info *ddrp)
{
    bool rc;

    if (ddrp->ddrphy_trained_csr_num > 0U)
    {
        /* Reload the DDRPHY config */
        rc = DDR_PhyInit(ddrp);
    }
    else
    {
        rc = true;
    }

    if (rc)
    {
        /* Reload the ddrc config */
        rc = DDR_DdrcInit(ddrp);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* DDR PHY address remap to 32-bit addressing                               */
/*--------------------------------------------------------------------------*/
uint32_t DDR_PhyAddrRemap(uint32_t paddr)
{
    return (paddr << 2U);
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* DDR Controller Idle status                                               */
/*--------------------------------------------------------------------------*/
static bool DDR_CheckDdrcIdle(uint32_t flag)
{
    while ((DDRC->DDRDSR_2 & flag) != flag)
    {
        ; /* Intentional empty while */
    }

    /* Return status */
    return true;
}

/*--------------------------------------------------------------------------*/
/* DDR MR write                                                             */
/*--------------------------------------------------------------------------*/
static bool DDR_DdrcMrs(uint32_t csSel, uint32_t opcode, uint32_t mr)
{
    uint32_t val;
    uint8_t caShift = 6U;
    bool rc;

    /* LP4x or LP5 */
    if ((DDRC->DDR_SDRAM_CFG &
            DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_MASK) != 0U)
    {
        caShift = 7U;
    }

    val = DDRC_DDR_SDRAM_MD_CNTL_MD_SEL(csSel) | (opcode << caShift) | (mr);
    DDRC->DDR_SDRAM_MD_CNTL = val;
    DDRC->DDR_SDRAM_MD_CNTL |= DDRC_DDR_SDRAM_MD_CNTL_MD_EN_MASK;

    while ((DDRC->DDR_SDRAM_MD_CNTL & DDRC_DDR_SDRAM_MD_CNTL_MD_EN_MASK)
        == DDRC_DDR_SDRAM_MD_CNTL_MD_EN_MASK)
    {
        ; /* Intentional empty while */
    }

    rc = DDR_CheckDdrcIdle(DDRC_DDRDSR_2_IDLE_MASK);

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Mode register write                                                      */
/*--------------------------------------------------------------------------*/
static bool DDR_MrWrite(uint32_t mrRank, uint32_t mrAddr, uint32_t mrData)
{
    uint32_t chip_Select;
    bool rc;

    if (mrRank == 1U)
    {
        chip_Select = 0U; /* CS0 */
    }
    else if (mrRank == 2U)
    {
        chip_Select = 1U; /* CS1 */
    }
    else
    {
        chip_Select = 4U; /* CS0 & CS1 */
    }

    rc = DDR_DdrcMrs(chip_Select, mrData, mrAddr);

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Restore the DDR PHY config                                               */
/*--------------------------------------------------------------------------*/
static bool DDR_PhyInit(const struct ddr_info *ddrp)
{
    const struct ddrphy *cfg;
    bool rc = true;

    if (ddrp != NULL)
    {
        uint32_t i;

        /* APB access enable of CSR bus */
        DWC_DDRPHY_APB_WR(0xd0000U, 0x0U);
        /* HclkEn and UcclkEn set enable */
        DWC_DDRPHY_APB_WR(0xc0080U, 0x3U);

        /* Steps to restore Impedance Calibration values.
         * Restore Pull-up impedance calibration code by overriding
         * csr_ZQCalCodeOvrPU with saved initial value.
         * user must replace Subfield: ZQCalCodeOvrEnPU 0:0 with 0x1,
         * user must replace Subfield: ReservedZQCalCodeOvrEnPU 7:1 with 0x0,
         * user must replace Subfield: ZQCalCodeOvrValPU 15:8 with the actual
         * saved initial ZQCalCodePU value,
         * Restore Pull-down impedance calibration code by overriding
         * csr_ZQCalCodeOvrPD with saved initial value
         * user must replace Subfield: ZQCalCodeOvrEnPD 0:0 with 0x1,
         * user must replace Subfield: ReservedZQCalCodeOvrEnPD 7:1 with 0x0,
         * user must replace Subfield: ZQCalCodeOvrValPD 15:8 with the actual
         * saved initial ZQCalCodePD value,
         */
        DWC_DDRPHY_APB_WR(0x20326U, 0x1U | (ddrp->ZQCalCodePU & 0xFF00U));
        DWC_DDRPHY_APB_WR(0x20327U, 0x1U | (ddrp->ZQCalCodePD & 0xFF00U));

        /* Assert ZCalReset to force impedance calibration FSM to idle. */
        /* DWC_DDRPHYA_MASTER0_p0_ZCalReset */
        DWC_DDRPHY_APB_WR(0x20310U, 0x1U);
        /* DWC_DDRPHYA_MASTER0_p0_ZQCalCodeOvrPU, Clear ZQCalCodeOvrPU */
        DWC_DDRPHY_APB_WR(0x20326U, 0x0U);
        /* DWC_DDRPHYA_MASTER0_p0_ZQCalCodeOvrPD, Clear ZQCalCodeOvrPD */
        DWC_DDRPHY_APB_WR(0x20327U, 0x0U);

        /* Restore the DDR PHY CSRs */
        cfg = ddrp->trained_csr;
        for (i = 0U; i < ddrp->ddrphy_trained_csr_num; i++)
        {
            DWC_DDRPHY_APB_WR(cfg->reg, cfg->val);
            cfg++;
        }

        /* Step 'D' - Wait for full ZQ calibration sequence */
        /* write csrPwrOkDlyCtrl = 1*/
        DWC_DDRPHY_APB_WR(0x20090U, 0x1U);
        /* write csrPstate that corresponds to DfiClk frequency */
        DWC_DDRPHY_APB_WR(0x2008bU, 0x0U);

        if (ddrp->pstate_num > 2U)
        {
            uint32_t dficycle;

            /* In case NumPState > 2, Host writes
             * csrZcalDfiClkTicksPer1uS_p0[10:0] = DfiClk cycle
             * count to make 1us at the PState during LP3 exit and csrPState
             * = 0 should be kept */
            dficycle = (ddrp->pstate_freq[0U] / 8U);
            if ((ddrp->pstate_freq[0U] % 8U) != 0U)
            {
                dficycle++;
            }

            /* number of DfiClks in 1us */
            DWC_DDRPHY_APB_WR(0x20004U, dficycle);
        }

        /* Reset the calibrator to its idle state */
        DWC_DDRPHY_APB_WR(0x20310U, 0x0U);
        /* triggers the impedance calibration sequence */
        DWC_DDRPHY_APB_WR(0x20311U, 0x1U);

        /* Host waits for completions of ZQ Calibration (35us) */
        SystemTimeDelay(35U);

        /* UcclkEn disable, HclkEn enable */
        DWC_DDRPHY_APB_WR(0xc0080U, 0x2U);
        /* disable APB access to csr bus */
        DWC_DDRPHY_APB_WR(0xd0000U, 0x1U);
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Check status of DFI Init                                                 */
/*--------------------------------------------------------------------------*/
static bool DDR_CheckDfiInitComplete(void)
{
    do
    {
        if ((Read32(&DDRC->DDRDSR_2) &
                DDRC_DDRDSR_2_PHY_INIT_CMPLT_MASK) != 0U)
        {
            break;
        }
    } while (true);

    Write32(&DDRC->DDRDSR_2,
        DDRC->DDRDSR_2 | DDRC_DDRDSR_2_PHY_INIT_CMPLT_MASK);

    /* Return status */
    return true;
}

/*--------------------------------------------------------------------------*/
/* Restore the DDR Controller config                                        */
/*--------------------------------------------------------------------------*/
static bool DDR_DdrcInit(const struct ddr_info *ddrp)
{
    bool rc;

    if (ddrp != NULL)
    {
        uint32_t i;
        const struct ddrc *ddrc_cfg = ddrp->ddrc_cfg;

        for (i = 0; i < ddrp->ddrc_cfg_num; i++)
        {
            /* With ECC, MTCR is used to clear DDR
             * skip it in retention exit */
            if (((ddrc_cfg[i].reg ^ (uint32_t)(&DDRC->DDR_MTCR)) &
                0xFFFFFU) == 0U)
            {
                continue;
            }

            /* Skip DDRC EN */
            if (((ddrc_cfg[i].reg ^ (uint32_t)(&DDRC->DDR_SDRAM_CFG)) &
                0xFFFFFU) == 0U)
            {
                Write32(ddrc_cfg[i].reg, ddrc_cfg[i].val & 0x7FFFFFFFU);
                continue;
            }

            /* Skip the dram init as we resume from retention */
            if (((ddrc_cfg[i].reg ^ (uint32_t)(&DDRC->DDR_SDRAM_CFG_2)) &
                0xFFFFFU) == 0U)
            {
                Write32(ddrc_cfg[i].reg, ddrc_cfg[i].val & ~(1U << 4));
            }
            else
            {
                Write32(ddrc_cfg[i].reg, ddrc_cfg[i].val);
            }
        }

        /* Check pstate */
        if (ddrp->pstate != NULL)
        {
            ddrc_cfg = ddrp->pstate[0].cfg;
            for (i = 0;  i < ddrp->pstate[0].cfg_num; i++)
            {
                Write32(ddrc_cfg[i].reg, ddrc_cfg[i].val);
            }
        }

        /* Check dfi init status */
        rc = DDR_CheckDfiInitComplete();

        if (rc)
        {
            /* Enable the DDRC */
            Write32(&DDRC->DDR_SDRAM_CFG,
                Read32(&DDRC->DDR_SDRAM_CFG) |
                        DDRC_DDR_SDRAM_CFG_MEM_EN_MASK);

            rc = DDR_CheckDdrcIdle(DDRC_DDRDSR_2_IDLE_MASK);
        }
    }
    else
    {
        rc = false;
    }

    if (s_srFastWakeEn)
    {
        DDRC->DDR_SDRAM_CFG_3
            |= DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN(1U);
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get the DDR Info                                                         */
/*--------------------------------------------------------------------------*/
bool DDR_GetDRAMInfo(const struct ddr_info *ddrp, struct dram_info *info)
{
    bool rc = true;

    if ((ddrp != NULL) && (info != NULL))
    {
        uint32_t addr;

        /* Update total address region */
        info->totalRegions = 1U;

        /* 001b - LPDDR5 SDRAM, 100b - LPDDR4X SDRAM*/
        info->sdramType = (DDRC->DDR_SDRAM_CFG
            & DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_MASK)
            >> DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_SHIFT;

        /* Detect how many bytes are used in the DDR interface
         * Read DDRC DDR_SDRAM_CFG: DBW (Data Bus Width) and DC (Dual Channel)
         * DBW=10b (16-bit interface) and DC=0 (Dual Channel Disable):
         *  16-bit interface (2 bytes)
         * DBW=10b (16-bit interface) and DC=1 (Dual Channel Enable):
         *  16-bit dual channel mode, means entire 32-bit intf used (4 bytes)
         * DBW=01b (32-bit interface) and DC=0 (Dual Channel Disable):
         *  32-bit interface (4 bytes)
         * DBW=01b (32-bit interface) and DC=1 (Dual Channel Enable):
         *  Not an allowable configuration */
        if (((DDRC->DDR_SDRAM_CFG & DDRC_DDR_SDRAM_CFG_DBW_MASK)
            == 0x00100000U) && ((DDRC->DDR_SDRAM_CFG
            & DDRC_DDR_SDRAM_CFG_DC_EN_MASK) == 0U))
        {
            info->sdramDatabusWidth = 16U;
        }
        else
        {
            info->sdramDatabusWidth = 32U;
        }

        /* Check if Inline ECC enabled */
        if ((DDRC->ERR_EN & DDRC_ERR_EN_INLINE_ECC_EN_MASK) != 0U)
        {
            info->eccEnb = true;
        }
        else
        {
            info->eccEnb = false;
        }

        /* Extract MTS from DDR info */
        info->mts = ddrp->pstate_freq[0];

        /* Start address from CS0 bounds (top 12 of 36 bits addr)
           + DDR AXI start */
        addr = ((DDRC->CS_BNDS[0].CS_BNDS & DDRC_CS_BNDS_SA_MASK)
            >> DDRC_CS_BNDS_SA_SHIFT);
        info->startAddr = U64(addr);
        info->startAddr <<= 24U;
        info->startAddr += 0x80000000ULL;

        /* End address from CS0 bounds if Rank interleaving set
           + DDR AXI start */
        if (((DDRC->DDR_SDRAM_CFG & DDRC_DDR_SDRAM_CFG_BA_INTLV_CTL_MASK)
            != 0U) || ((DDRC->CS_CONFIG[1] & DDRC_CS_CONFIG_CS_EN_MASK)
            == 0U))
        {
            /* End address from CS0 bounds if Rank interleaving set
               + DDR AXI start */
            addr = ((DDRC->CS_BNDS[0].CS_BNDS
                & DDRC_CS_BNDS_EA_MASK)
                >> DDRC_CS_BNDS_EA_SHIFT);
        }
        else
        {
            /* End address from CS1 bounds + DDR AXI start */
            addr = ((DDRC->CS_BNDS[1].CS_BNDS
                & DDRC_CS_BNDS_EA_MASK)
                >> DDRC_CS_BNDS_EA_SHIFT);
        }
        info->endAddr = U64(addr);
        info->endAddr <<= 24U;
        info->endAddr += 0xFFFFFFULL;
        info->endAddr += 0x80000000ULL;
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get the auto refresh rate divider based on the max refresh rate reported */
/* from the DRAM for cases when DYN_REF_RATE_EN is manually disabled.       */
/*--------------------------------------------------------------------------*/
static uint32_t DDR_GetRefreshDivider(void)
{
    uint32_t maxRefRate;
    uint32_t ref_rate_cs0, ref_rate_cs1, ref_rate_cs0_chb, ref_rate_cs1_chb;
    bool lpddr5 = false;
    uint32_t refRateDivider = 1U;

    /* Check if LP5 */
    if ((DDRC->DDR_SDRAM_CFG &
        (1UL << DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_SHIFT)) != 0U)
    {
        lpddr5 = true;
    }

    /* First, obtain the maximum refresh rate reported from DRAM */
    maxRefRate = DDRC_CTRL->DDR_SDRAM_REF_RATE;
    ref_rate_cs1 = ((maxRefRate &
                     DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_MASK) >>
                     DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_SHIFT);
    ref_rate_cs0 = ((maxRefRate &
                     DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_MASK) >>
                     DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_SHIFT);
    ref_rate_cs1_chb = ((maxRefRate &
                         DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_CHB_MASK) >>
                         DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS1_CHB_SHIFT);
    ref_rate_cs0_chb = ((maxRefRate &
                         DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_CHB_MASK) >>
                         DDRC_DDR_SDRAM_REF_RATE_REF_RATE_CS0_CHB_SHIFT);

    /* Apply mask on reported refresh rate to obtain only the DRAM
     * refresh rate nultiplier */
    ref_rate_cs1 &= REF_RATE_MULTIPLIER;
    ref_rate_cs0 &= REF_RATE_MULTIPLIER;
    ref_rate_cs1_chb &= REF_RATE_MULTIPLIER;
    ref_rate_cs0_chb &= REF_RATE_MULTIPLIER;

    /* Check if CS1 refresh rate higher the CS0 */
    if (ref_rate_cs1 > ref_rate_cs0)
    {
        maxRefRate = ref_rate_cs1;
    }
    else
    {
        maxRefRate = ref_rate_cs0;
    }

    /* Check if CS1 refresh rate higher the CS0 for Chn B*/
    if (ref_rate_cs1_chb > maxRefRate)
    {
        maxRefRate = ref_rate_cs1_chb;
    }

    if (ref_rate_cs0_chb > maxRefRate)
    {
        maxRefRate = ref_rate_cs0_chb;
    }

    /* Determine if refresh rate divider reported by the DRAM MR4 is
     * greater than nominal to adjust refresh rate acordingly
     */
    if (lpddr5 == true)
    {
        /* When refRate (MR4) is 0xA or 0xB, set to 0.5x refresh */
        if ( (maxRefRate > 0x9U) && (maxRefRate < 0xCU))
        {
            refRateDivider = 2U;
        }
        /* When refRate (MR4) is 0xC or 0xD, set to 0.25x refresh */
        else if ( (maxRefRate > 0xBU) && (maxRefRate < 0xEU))
        {
            refRateDivider = 4U;
        }
        /* When refRate (MR4) is > 0xD set to 0.125x refresh */
        else if ( maxRefRate > 0xDU )
        {
            refRateDivider = 8U;
        }
        else
        {
            refRateDivider = 1U;
        }
    }
    else  /* LPDDR4/4x */
    {
        /* When refRate (MR4) is 0x4, set to 0.5x refresh */
        if (maxRefRate == 0x4U)
        {
            refRateDivider = 2U;
        }
        /* When refRate (MR4) > 0x4, set to 0.25x refresh */
        else if (maxRefRate > 0x4U)
        {
            refRateDivider = 4U;
        }
        else
        {
            refRateDivider = 1U;
        }
    }

    /* Return divider */
    return refRateDivider;
}

