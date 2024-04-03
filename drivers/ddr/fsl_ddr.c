/*
 ** ###################################################################
 **
 **     Copyright 2024 NXP
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

#define DEBUG_26        (DDRC_BASE + 0xF64U)

#define Dwc_Ddrphy_Apb_Wr(addr, data) \
    (*(uint32_t *)(DDR_PHY_BASE + Ddrphy_AddrRemap(addr)) = (data))

#define Dwc_Ddrphy_Apb_Rd(addr) \
    *(uint32_t *)(DDR_PHY_BASE + Ddrphy_AddrRemap(addr))

/* Local Functions */

static uint32_t Ddrphy_AddrRemap(uint32_t paddr);
static bool Check_DdrcIdle(uint32_t flag);
static bool Ddrc_Mrs(uint32_t csSel, uint32_t opcode, uint32_t mr);
static bool Mr_Write(uint32_t mr_Rank, uint32_t mr_Addr, uint32_t mr_Data);
static bool Ddr_PhyInit(const struct ddr_info *ddrp);
static bool Check_Dfi_Init_Complete(void);
static bool Ddrc_Init(const struct ddr_info *ddrp);

/*--------------------------------------------------------------------------*/
/* DDR PHY address remap to 32-bit addressing                               */
/*--------------------------------------------------------------------------*/
static uint32_t Ddrphy_AddrRemap(uint32_t paddr)
{
    return (paddr << 2U);
}

/*--------------------------------------------------------------------------*/
/* DDR Controller Idle status                                               */
/*--------------------------------------------------------------------------*/
static bool Check_DdrcIdle(uint32_t flag)
{
    while ((DDRC_CTRL->DDRDSR_2 & flag) != flag) {};

    /* Return status */
    return true;
}

/*--------------------------------------------------------------------------*/
/* DDR MR write                                                             */
/*--------------------------------------------------------------------------*/
static bool Ddrc_Mrs(uint32_t csSel, uint32_t opcode, uint32_t mr)
{
    uint32_t val;
    uint8_t caShift = 6U;
    bool rc = true;

    /* LP4x or LP5 */
    if ((DDRC_CTRL->DDR_SDRAM_CFG &
            DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_MASK) != 0U)
    {
        caShift = 7U;
    }

    val = DDRC_DDR_SDRAM_MD_CNTL_MD_SEL(csSel) | (opcode << caShift) | (mr);
    DDRC_CTRL->DDR_SDRAM_MD_CNTL = val;
    DDRC_CTRL->DDR_SDRAM_MD_CNTL |= DDRC_DDR_SDRAM_MD_CNTL_MD_EN_MASK;

    while ((DDRC_CTRL->DDR_SDRAM_MD_CNTL & DDRC_DDR_SDRAM_MD_CNTL_MD_EN_MASK)
            == DDRC_DDR_SDRAM_MD_CNTL_MD_EN_MASK) {};

    rc = Check_DdrcIdle(DDRC_DDRDSR_2_IDLE_MASK);

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Mode register write                                                      */
/*--------------------------------------------------------------------------*/
static bool Mr_Write(uint32_t mr_Rank, uint32_t mr_Addr, uint32_t mr_Data)
{
    uint32_t chip_Select;
    bool rc = true;

    if(mr_Rank == 1U)
    {
        chip_Select = 0U; /* CS0 */
    }
    else if (mr_Rank == 2U)
    {
        chip_Select = 1U; /* CS1 */
    }
    else
    {
        chip_Select = 4U; /* CS0 & CS1 */
    }

    rc = Ddrc_Mrs(chip_Select, mr_Data, mr_Addr);

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* DDR Enter Retention                                                      */
/*--------------------------------------------------------------------------*/
bool DDR_EnterRetention(const struct ddr_info *ddrp)
{
    bool rc = true;

    if (ddrp != NULL)
    {
        uint32_t eccEn = 0U;
        uint32_t waitFlag = 0U;

        /* Is ECC enabled? */
        if ((DDRC_CTRL->ERR_EN & DDRC_ERR_EN_INLINE_ECC_EN_MASK) != 0U)
        {
            eccEn = 1U;
        }

        /* Check if TX_CFG_1 WWATER enabled with ECC */
        if ((eccEn == 1U) && ((DDRC_CTRL->TX_CFG_1 &
                DDRC_TX_CFG_1_WWATER_MASK) != 0U))
        {
            DDRC_CTRL->TX_CFG_1 &= ~DDRC_TX_CFG_1_WWATER_MASK;
        }

        /* update wait flag as per ECC enabled */
        if (eccEn == 1U)
        {
            waitFlag = (DDRC_DDRDSR_2_NML_MASK | DDRC_DDRDSR_2_IDLE_MASK);
        }
        else
        {
            waitFlag = DDRC_DDRDSR_2_IDLE_MASK;
        }

        /* Polling for DDRDSR_2[IDLE] & ECC complete to be set */
        rc  = Check_DdrcIdle(waitFlag);

        if (rc != false)
        {
            /* MEM HALT */
            DDRC_CTRL->DDR_SDRAM_CFG |= (1U << DDRC_DDR_SDRAM_CFG_MEM_HALT_SHIFT);

            /* check if LPDDR5 */
            if ((Read32(&DDRC_CTRL->DDR_SDRAM_CFG) &
                (1UL << DDRC_DDR_SDRAM_CFG_SDRAM_TYPE_SHIFT)) != 0U)
            {
                /* STOP ZQCAL for two ranks */
                rc = Mr_Write(3U, 28U, 2U);
                /* Wait tZQSTOP(30ns) */
                SystemTimeDelay(1U);
            }

            if (rc != false)
            {
                /* PState set as 0x1F: Retention/Enter LP3 */
                DDRC_CTRL->DDR_SDRAM_CFG_4 &=
                    ~(0x3FFU << DDRC_DDR_SDRAM_CFG_4_FRQCH_RET_SHIFT);

                /* why DEBUG_26 ? */
                Write32(DEBUG_26, Read32(DEBUG_26) | (0x1FUL << 12U));

                /* Clear SR_FAST_WK_EN */
                DDRC_CTRL->DDR_SDRAM_CFG_3 &=
                    ~(1U << DDRC_DDR_SDRAM_CFG_3_SR_FAST_WK_EN_SHIFT);

                /* Clear DDR_ZQ_CNTL register */
                DDRC_CTRL->DDR_ZQ_CNTL = 0x0U;

                /* we will want to set DDR_SDRAM_CFG_3[4] to force the */
                /* PD entry by the DDRC for retention mode only. */
                DDRC_CTRL->DDR_SDRAM_CFG_3 |= (1U << 4U);

                /* Force the DDRC to enter self refresh */
                DDRC_CTRL->DDR_SDRAM_CFG_2 |=
                    (1UL << DDRC_DDR_SDRAM_CFG_2_FRC_SR_SHIFT);

                /* clear PHY INIT complete: BIT2 PHY_INIT_CMPLT W1C */
                do
                {
                    DDRC_CTRL->DDRDSR_2 |=
                        (1U << DDRC_DDRDSR_2_PHY_INIT_CMPLT_SHIFT);
                } while((DDRC_CTRL->DDRDSR_2 &
                (1U << DDRC_DDRDSR_2_PHY_INIT_CMPLT_SHIFT)) != 0U);

                /* Clear DDR_INTERVAL(this disables refreshes */
                DDRC_CTRL->DDR_SDRAM_INTERVAL = 0x0U;

                /* Set DDR_SDRAM_MD_CNTL (forces CKE to remain low) */
                DDRC_CTRL->DDR_SDRAM_MD_CNTL =
                    (1UL << DDRC_DDR_SDRAM_MD_CNTL_MD_EN_SHIFT) |
                    (1UL << DDRC_DDR_SDRAM_MD_CNTL_CKE_CNTL_SHIFT);

                /* T_STAB */
                DDRC_CTRL->TIMING_CFG_10 |=
                (0x7FFFU << DDRC_TIMING_CFG_10_T_STAB_SHIFT);

                /* Exit self refresh */
                DDRC_CTRL->DDR_SDRAM_CFG_2 &=
                    ~(1UL << DDRC_DDR_SDRAM_CFG_2_FRC_SR_SHIFT);

                /* Wait PHY INIT complete */
                while((DDRC_CTRL->DDRDSR_2 &
                    (1U << DDRC_DDRDSR_2_PHY_INIT_CMPLT_SHIFT)) == 0U) {};
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
/* Restore the DDR PHY config                                               */
/*--------------------------------------------------------------------------*/
static bool Ddr_PhyInit(const struct ddr_info *ddrp)
{
    const struct ddrphy *cfg;
    bool rc = true;

    if (ddrp != NULL)
    {
        uint32_t i;

        /* APB access enable of CSR bus */
        Dwc_Ddrphy_Apb_Wr(0xd0000U, 0x0U);
        /* HclkEn and UcclkEn set enable */
        Dwc_Ddrphy_Apb_Wr(0xc0080U, 0x3U);

        /* Steps to restore Impedance Calibration values.
         * Restore Pull-up impedance calibration code by overriding csr_ZQCalCodeOvrPU with saved initial value.
         * user must replace Subfield: ZQCalCodeOvrEnPU 0:0 with 0x1,
         * user must replace Subfield: ReservedZQCalCodeOvrEnPU 7:1 with 0x0,
         * user must replace Subfield: ZQCalCodeOvrValPU 15:8 with the actual saved initial ZQCalCodePU value,
         * Restore Pull-down impedance calibration code by overriding csr_ZQCalCodeOvrPD with saved initial value
         * user must replace Subfield: ZQCalCodeOvrEnPD 0:0 with 0x1,
         * user must replace Subfield: ReservedZQCalCodeOvrEnPD 7:1 with 0x0,
         * user must replace Subfield: ZQCalCodeOvrValPD 15:8 with the actual saved initial ZQCalCodePD value,
         */
        Dwc_Ddrphy_Apb_Wr(0x20326U, 0x1U | (ddrp->ZQCalCodePU & 0xFF00U));
        Dwc_Ddrphy_Apb_Wr(0x20327U, 0x1U | (ddrp->ZQCalCodePD & 0xFF00U));

        /* Assert ZCalReset to force impedance calibration FSM to idle. */
        /* DWC_DDRPHYA_MASTER0_p0_ZCalReset */
        Dwc_Ddrphy_Apb_Wr(0x20310U, 0x1U);
        /* DWC_DDRPHYA_MASTER0_p0_ZQCalCodeOvrPU, Clear ZQCalCodeOvrPU */
        Dwc_Ddrphy_Apb_Wr(0x20326U, 0x0U);
        /* DWC_DDRPHYA_MASTER0_p0_ZQCalCodeOvrPD, Clear ZQCalCodeOvrPD */
        Dwc_Ddrphy_Apb_Wr(0x20327U, 0x0U);

        /* Restore the DDR PHY CSRs */
        cfg = ddrp->trained_csr;
        for (i = 0U; i < ddrp->ddrphy_trained_csr_num; i++)
        {
            Dwc_Ddrphy_Apb_Wr(cfg->reg, cfg->val);
            cfg++;
        }

        /* Step 'D' - Wait for full ZQ calibration sequence */
        /* write csrPwrOkDlyCtrl = 1*/
        Dwc_Ddrphy_Apb_Wr(0x20090U, 0x1U);
        /* write csrPstate that corresponds to DfiClk frequency */
        Dwc_Ddrphy_Apb_Wr(0x2008bU, 0x0U);

        if (ddrp->pstate_num > 2U)
        {
            uint32_t dficycle;

            /* In case NumPState > 2, Host writes csrZcalDfiClkTicksPer1uS_p0[10:0] = DfiClk cycle
             * count to make 1us at the PState during LP3 exit and csrPState = 0 should be kept */
            dficycle = (ddrp->pstate_freq[0U] / 8U);
            if ((ddrp->pstate_freq[0U] % 8U) != 0U)
            {
                dficycle++;
            }

            /* number of DfiClks in 1us */
            Dwc_Ddrphy_Apb_Wr(0x20004U, dficycle);
        }

        /* reset the calibrator to its idle state */
        Dwc_Ddrphy_Apb_Wr(0x20310U, 0x0U);
        /* triggers the impedance calibration sequence */
        Dwc_Ddrphy_Apb_Wr(0x20311U, 0x1U);

        /* Host waits for completions of ZQ Calibration (35us) */
        SystemTimeDelay(35U);

        /* UcclkEn disable, HclkEn enable */
        Dwc_Ddrphy_Apb_Wr(0xc0080U, 0x2U);
        /* disable APB access to csr bus */
        Dwc_Ddrphy_Apb_Wr(0xd0000U, 0x1U);
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
static bool Check_Dfi_Init_Complete(void)
{
    do
    {
        if ((Read32(&DDRC_CTRL->DDRDSR_2) &
                DDRC_DDRDSR_2_PHY_INIT_CMPLT_MASK) != 0U)
        {
            break;
        }
    } while (true);

    Write32(&DDRC_CTRL->DDRDSR_2,
        DDRC_CTRL->DDRDSR_2 | DDRC_DDRDSR_2_PHY_INIT_CMPLT_MASK);

    /* Return status */
    return true;
}

/*--------------------------------------------------------------------------*/
/* Restore the DDR Controller config                                        */
/*--------------------------------------------------------------------------*/
static bool Ddrc_Init(const struct ddr_info *ddrp)
{
    bool rc = true;

    if (ddrp != NULL)
    {
        uint32_t i;
        const struct ddrc *ddrc_cfg = ddrp->ddrc_cfg;

        for (i = 0; i < ddrp->ddrc_cfg_num; i++)
        {
            /* with ECC, MTCR is used to clear DDR
             * skip it in retention exit */
            if (ddrc_cfg[i].reg == (uint32_t)(&DDRC_CTRL->DDR_MTCR))
            {
                continue;
            }

            /* Skip DDRC EN */
            if (ddrc_cfg[i].reg == (uint32_t)(&DDRC_CTRL->DDR_SDRAM_CFG))
            {
                Write32(ddrc_cfg[i].reg, ddrc_cfg[i].val & 0x7FFFFFFFU);
                continue;
            }

            /* skip the dram init as we resume from retention */
            if (ddrc_cfg[i].reg == (uint32_t)(&DDRC_CTRL->DDR_SDRAM_CFG_2))
            {
                Write32(ddrc_cfg[i].reg, ddrc_cfg[i].val & ~(1U << 4));
            }
            else
            {
                Write32(ddrc_cfg[i].reg, ddrc_cfg[i].val);
            }
        }

        /* check pstate */
        if (ddrp->pstate != NULL)
        {
            ddrc_cfg = ddrp->pstate[0].cfg;
            for (i = 0;  i < ddrp->pstate[0].cfg_num; i++)
            {
                Write32(ddrc_cfg[i].reg, ddrc_cfg[i].val);
            }
        }

        /* check dfi init status */
        rc = Check_Dfi_Init_Complete();

        if (rc != false)
        {
            /* Enable the DDRC */
            Write32(&DDRC_CTRL->DDR_SDRAM_CFG,
                Read32(&DDRC_CTRL->DDR_SDRAM_CFG) |
                        DDRC_DDR_SDRAM_CFG_MEM_EN_MASK);

            rc = Check_DdrcIdle(DDRC_DDRDSR_2_IDLE_MASK);
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
    bool rc = true;

    /* Reload the DDRPHY config */
    rc = Ddr_PhyInit(ddrp);

    if (rc != false)
    {
        /* Reload the ddrc config */
        rc = Ddrc_Init(ddrp);
    }

    /* Return status */
    return rc;
}

