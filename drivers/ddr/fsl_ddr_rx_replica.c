/*
** ###################################################################
**
**     Copyright 2025 NXP
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
/* File containing the implementation of the DDR RX Replica workaround.     */
/*==========================================================================*/

/* Includes */

#include "fsl_ddr.h"
#include "fsl_sysctr.h"
#include "fsl_ddr_rx_replica.h"

/* Local Defines */

#define DDR_FLOAT_WA_FACTOR  100U

/* Enable general debug print messages */
#if 0
#define DEBUG_INIT_PRINT_EN
#endif

#if 0
/* Enable ddr_rxclkdely_init() print */
#define DEBUG_PRINT_INIT_RUNTIME
#endif

#if 0
/* Enable periodic DDR_RxReplicaWa() prints */
#define DEBUG_PRINT_WA_RUNTIME
#endif

/* Not relock PHY CSRs for continued debug access,
   should be uncommented for production */
#define DEBUG_RELOCK_PHY_CSRS

/* Local Functions */

static uint32_t DDR_SimpleDivRound(uint32_t val, uint32_t denom);

/*--------------------------------------------------------------------------*/
/* Init DDR Replica Workaround                                              */
/*--------------------------------------------------------------------------*/
bool DDR_RxClkDelayInit(ddr_rxclkdelay_wa_data_t *ddrRxcWa, uint16_t count)
{
    bool rc = true;
    uint32_t idx;
#if defined(INC_LIBC) && defined(DEBUG_PRINT_INIT_RUNTIME)
    uint64_t start;
#endif

/*----------------------------------------------------------*/
#define PMRO_FUSE_TT 5075U
#define PMRO_SCALE_OFFSET 3500U
#define TT_SCALE_FACTOR 84U
/*----------------------------------------------------------*/

    /* Check if NULL or illegal count */
    if ((ddrRxcWa == NULL) || (count > DDR_RXCLK_DELAY_CNT))
    {
        rc = false;
    }

    /* Check if DDR is ON */
    if (rc && (ddrRxcWa->dramFreqMhz == 0U))
    {
        ddrRxcWa->initComplete = false;
        rc = false;
#if defined(INC_LIBC) && defined(DEBUG_PRINT_INIT_RUNTIME)
        printf("DDR not enabled\n");
#endif
    }

    if (rc)
    {
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
            ddrRxcWa->dbytes = 2U;
        }
        else
        {
            ddrRxcWa->dbytes = 4U;
        }

#ifdef DEBUG_INIT_PRINT_EN
        printf("PMRO fuse val = %u\n", ddrRxcWa->pmro);
#endif

        /* Disable the RxReplica circuit if pmro */
        if (ddrRxcWa->pmro == 0U)
        {
            /* CSR bus: MCU--,PIE/DMA/TDR/APB++ */
            DWC_DDRPHY_APB_WR(0xd0000U, 0x0U);

            for (idx = 0U; idx < ddrRxcWa->dbytes; idx++)
            {
                /* Disable RxReplica */
                /* Clear  RxReplicaTrackEn */
                DWC_DDRPHY_APB_WR(((0x1000fU + (idx << 12U))),
                    DWC_DDRPHY_APB_RD((0x1000fU + (idx << 12U))) & 0xFFFEU);
            }

            /* CSR bus: MCU/PIE/DMA++,TDR/APB-- */
            DWC_DDRPHY_APB_WR(0xd0000U, 0x1U);

            ddrRxcWa->initComplete = false;
            rc = false;
        }
    }

    if (rc)
    {
        /* CSR bus: MCU--,PIE/DMA/TDR/APB++ */
        DWC_DDRPHY_APB_WR(0xd0000U, 0x0U);

        for (idx = 0U; idx < ddrRxcWa->dbytes; idx++)
        {
            /* Check RxReplicaTrackEn */
            uint32_t enabled = DWC_DDRPHY_APB_RD((0x1000fU
                + (idx << 12U))) & 1U;

            if (enabled != 1U)
            {
                ddrRxcWa->initComplete = false;
                rc = false;
            }
        }

        /* CSR bus: MCU/PIE/DMA++,TDR/APB-- */
        DWC_DDRPHY_APB_WR(0xd0000U, 0x1U);
    }

    if (rc)
    {
#if defined(INC_LIBC) && defined(DEBUG_PRINT_INIT_RUNTIME)
        start = SYSCTR_GetUsec64();
#endif
        /* Calculate the freqRatio */
        ddrRxcWa->freqRatio =
            ((6400U * DDR_FLOAT_WA_FACTOR) / (ddrRxcWa->dramFreqMhz * 8U));

        ddrRxcWa->count = count;
        ddrRxcWa->aIndex = 0U;
        ddrRxcWa->aEmpty = true;

        /* CSR bus: MCU--,PIE/DMA/TDR/APB++ */
        DWC_DDRPHY_APB_WR(0xd0000U, 0x0U);

        /* Clear PMIenable to pause any PPT1 actions */
        DWC_DDRPHY_APB_WR(0x20054U, 0U);

        /* Wait to ensure any remaining PPT1 actions are completed */
        SystemTimeDelay(10U);

        /* Reset PMIenable to ensure PPT1 not overriding PMIenable again */
        DWC_DDRPHY_APB_WR(0x20054U, 0U);

        /* Obtain the initial trained receive delay line values */
        for (idx = 0U; idx < ddrRxcWa->dbytes; idx++)
        {
            uint8_t bit;
            uint16_t loop = count;
            uint32_t sumpathphase = 0U;

            /* Trained Read DQS_t/c to RxClk_t/c Delay,
             * 9-bits across 4 byte lanes */
            for (bit = 0U; bit <= 8U; bit++)
            {
                /* RxClkT2UIDlyTg0 RxClkT2UIDlyTg1 RxClkC2UIDlyTg0
                   RxClkC2UIDlyTg1 */
                /* RxClkT2UIDlyTg0: Timing Group 0 = RANK0 */
                ddrRxcWa->rxclkinitv[idx][bit][0U] =
                    DWC_DDRPHY_APB_RD(0x10000U + (idx << 12U) + 0x10U
                    + (bit * 0x100U)) & 0xFFFFU;

                /* RxClkT2UIDlyTg1: Timing Group 1 = RANK1 */
                ddrRxcWa->rxclkinitv[idx][bit][1U] =
                    DWC_DDRPHY_APB_RD(0x10000U + (idx << 12U) + 0x11U
                    + (bit * 0x100U)) & 0xFFFFU;

                /* RxClkC2UIDlyTg0: Timing Group 0 = RANK0 */
                ddrRxcWa->rxclkinitv[idx][bit][2U] =
                    DWC_DDRPHY_APB_RD(0x10000U + (idx << 12U) + 0x12U
                    + (bit * 0x100U)) & 0xFFFFU;

                /* RxClkC2UIDlyTg1: Timing Group 1 = RANK1 */
                ddrRxcWa->rxclkinitv[idx][bit][3U] =
                    DWC_DDRPHY_APB_RD(0x10000U + (idx << 12U) + 0x13U
                    + (bit * 0x100U)) & 0xFFFFU;

            }

            /* Get path select */
            /* RxReplicaCtl01: Specify which of the five
            * RxReplicaPathPhase[0..4]
            * to use for computing RxReplicaRatioNow. */
            ddrRxcWa->pathsel[idx] =
                U32_U16(DWC_DDRPHY_APB_RD(0x10000U + (idx << 12U) + 0xadU));

            /* Read DDRC DDR_MTP0 for special code key that indicate that
             * the RxReplica pathPhase initialization was performed in the OEI
             */
            if (DDRC->DDR_MTP[0] != 0x0C0DE0E1U)
            {
                /* Initial pathphase collection must be performed in OEI;
                 * this is left for backwards compatibility, will be removed.
                 */
                while (loop-- != 0U)
                {
                    sumpathphase += DWC_DDRPHY_APB_RD(0x10000U +
                        (idx << 12U) + 0xd0U + ddrRxcWa->pathsel[idx]);
                }

                /* Got Pathphase init values*/
                ddrRxcWa->init[idx] = U32_U16(DDR_SimpleDivRound(sumpathphase,
                    count));
            }
            else
            {
                /* Read RxReplicaCtl03 which stored in OEI */
                ddrRxcWa->init[idx] = U32_U16(DWC_DDRPHY_APB_RD(0x10000U
                    + (idx << 12U) + 0xafU));
            }

            ddrRxcWa->rxclkoffset[idx] = 0;
        }

        /* Re-enable PHY Master interface */
        DWC_DDRPHY_APB_WR(0x20054U, 0x1U);

#ifdef DEBUG_RELOCK_PHY_CSRS // Re-lock PHY CSRs if this is defined
        DWC_DDRPHY_APB_WR(0xd0000U, 0x1U);
#endif
        /* Set init completed to true */
        ddrRxcWa->initComplete = true;

        /* For pmro fused parts, if PMRO fuse is programmed, proceed to use
           the fuse information */
        uint32_t pmroScaleFactor = (ddrRxcWa->pmro / 4U) - PMRO_SCALE_OFFSET;
        uint32_t pmroToTtRatio = ((PMRO_FUSE_TT - PMRO_SCALE_OFFSET)
            * DDR_FLOAT_WA_FACTOR) / (pmroScaleFactor);
        ddrRxcWa->processScaleFactor = (pmroToTtRatio
            * TT_SCALE_FACTOR) / (DDR_FLOAT_WA_FACTOR);

#ifdef DEBUG_INIT_PRINT_EN
        printf("pmroScaleFactor: %u pmroToTtRatio = %u processScaleFactor = %u\n",
            pmroScaleFactor, pmroToTtRatio,
            (ddrRxcWa->processScaleFactor));
#endif

#if defined(INC_LIBC) && defined(DEBUG_PRINT_INIT_RUNTIME)
        printf("RX CLK init took = %u\n", (uint32_t) (SYSCTR_GetUsec64()
            - start));
#endif
    }

#if defined(INC_LIBC) && defined(DEBUG_PRINT_INIT_RUNTIME)
    if (rc == false)
    {
        printf("RX replica WA init failed\n");
    }
#endif

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* DDR Replica Workaround                                                   */
/*--------------------------------------------------------------------------*/
void DDR_RxReplicaWa(ddr_rxclkdelay_wa_data_t *ddrRxcWa, uint16_t newSamples)
{
    bool rc = true;

    /* Check if NULL */
    if (ddrRxcWa == NULL)
    {
        rc = false;
    }

    if (rc)
    {
        /* Check if init completed */
        if (ddrRxcWa->initComplete == false)
        {
            rc = false;
        }

        /* Check if illegal new samples count */
        if ((newSamples > ddrRxcWa->count) ||
            (newSamples > DDR_RXCLK_DELAY_CNT))
        {
            rc = false;
        }
    }

    if (rc)
    {
        int32_t scaled_delta[4] = { 0 };
        uint32_t processScaleFactor = ddrRxcWa->processScaleFactor;
#if defined(INC_LIBC) && defined(DEBUG_PRINT_WA_RUNTIME)
        uint64_t start = SYSCTR_GetUsec64();
#endif

        /* CSR bus: MCU--,PIE/DMA/TDR/APB++ */
        DWC_DDRPHY_APB_WR(0xd0000U, 0x0U);

        /* Clear PMIenable to pause any PPT1 actions */
        DWC_DDRPHY_APB_WR(0x20054U, 0U);

        /* Wait to ensure any remaining PPT1 actions are completed */
        SystemTimeDelay(10U);

        /* Reset PMIenable to ensure PPT1 not overriding PMIenable again */
        DWC_DDRPHY_APB_WR(0x20054U, 0U);

        uint16_t count = 0U;
        /* Check saved data status */
        if (ddrRxcWa->aEmpty)
        {
            count = ddrRxcWa->count;
        }
        else
        {
            count = newSamples;
        }

        while (count-- != 0U)
        {
            for (uint32_t idx = 0U; idx < ddrRxcWa->dbytes; idx++)
            {
                uint16_t pathphase;

                /* Read PathPhase */
                /* This detemines which RxReplicaPathPhase (Phase 0, 1, 2, 3, or 4)
                 * to read based on what was saved initially to d->pathsel[j]
                 * RxReplicaCtl01: Specify which of the RxReplicaPathPhase[0..4]
                 * to use for computing RxReplicaRatioNow.
                 * RxReplicaPathPhase[4:0]: where [4:0] is the path phase
                 * determined from initial d->pathsel[j]
                 * Measurement result by RxReplica cell of a replica of the path
                 * from DQS pad to RxClk LCDL. Units of LCDL Phase stepsize
                 * Smallest value of RxReplicaPhase which causes the RxReplica
                 * phd_out[4:0] to set */
                pathphase = U32_U16(DWC_DDRPHY_APB_RD(0x10000U +
                    (idx << 12U) + 0xd0U + ddrRxcWa->pathsel[idx]));

                ddrRxcWa->aPathphase[idx][ddrRxcWa->aIndex % ddrRxcWa->count]
                    = (pathphase & 0x1FFU);
            }

            ddrRxcWa->aIndex++;
        }

        /* Update saved data status */
        if (ddrRxcWa->aEmpty)
        {
            ddrRxcWa->aEmpty = false;
        }

        /* Average it */
        for (uint32_t idx = 0U; idx < ddrRxcWa->dbytes; idx++)
        {
            uint8_t cnt;
            int32_t delta[4] = { 0 };
            uint16_t avePathphase[4] = { 0 };
            uint16_t sumPathphase[4] = { 0 };

            for (cnt = 0; cnt < ddrRxcWa->count; cnt++)
            {
                /*
                 * False Positive: The value of aPathphase is 9 bits,
                 * so max can be 511. Count is 128, so upon summation
                 * it could be as big as 511*128 = 65408. which is  still
                 * smaller then UINT16_MAX
                 */
                /* coverity[cert_int30_c_violation] */
                sumPathphase[idx] += ddrRxcWa->aPathphase[idx][cnt];
            }

            avePathphase[idx] = U32_U16(DDR_SimpleDivRound(
                (uint32_t) sumPathphase[idx], ddrRxcWa->count));

            delta[idx] = (int32_t)avePathphase[idx]
                - (int32_t) ddrRxcWa->init[idx];

            /* Scale pathphase based on process corner */
            if (delta[idx] < 0)
            {
                uint32_t unsignedDeltaVal = DDR_SimpleDivRound(((
                    (uint32_t)(-delta[idx]) *
                    (processScaleFactor * DDR_FLOAT_WA_FACTOR)) /
                    ddrRxcWa->freqRatio), DDR_FLOAT_WA_FACTOR);

                /* Check for the overflow */
                if (unsignedDeltaVal <= (uint32_t)INT32_MAX)
                {
                    scaled_delta[idx] = -1 * (int32_t)unsignedDeltaVal;
                }
                else
                {
                    /* Handle the overflow */
                    SM_Error(SM_ERR_GENERIC_ERROR);
                }
            }
            else
            {
                uint32_t unsignedDeltaVal = DDR_SimpleDivRound(((
                    (uint32_t) delta[idx] * (processScaleFactor
                        * DDR_FLOAT_WA_FACTOR)) / ddrRxcWa->freqRatio),
                    DDR_FLOAT_WA_FACTOR);

                if (unsignedDeltaVal <= (uint32_t)INT32_MAX)
                {
                    scaled_delta[idx] = (int32_t)unsignedDeltaVal;
                }
                else
                {
                    /* Handle the overflow */
                    SM_Error(SM_ERR_GENERIC_ERROR);
                }
            }

#ifdef DEBUG_INIT_PRINT_EN
            // For printing out PMRO Fuse specific parameters
            uint32_t tempPathSel = 0U;
            tempPathSel = DWC_DDRPHY_APB_RD(0x10000U + (idx << 12U) + 0xadU);

            printf("dbyte %d, delta %d scaled_delta %d processScaleFactor %d "
                "avePathphase %d init %d pathSel %d\n",
                idx, delta[idx], scaled_delta[idx], processScaleFactor,
                avePathphase[idx], ddrRxcWa->init[idx], tempPathSel);
            printf("freqRatio: %d\n", ddrRxcWa->freqRatio);
#endif
        }

        /* Set delta to rxclkdelay */
        /* Per above, when we calculated the delta or change needed to apply to
         * the initially trained RxClkT2UIDlyTg0, RxClkT2UIDlyTg1, RxClkC2UIDlyTg0,
         * RxClkC2UIDlyTg1 */
        for (uint32_t idx = 0U; idx < ddrRxcWa->dbytes; idx++)
        {
            int32_t offset = scaled_delta[idx];

            if (offset != ddrRxcWa->rxclkoffset[idx])
            {
                for (uint8_t bit = 0U; bit <= 8U; bit++)
                {
                    /* Apply offset to RxClkT2UIDlyTg0, RxClkT2UIDlyTg1,
                     * RxClkC2UIDlyTg0, RxClkC2UIDlyTg1 */
                    DWC_DDRPHY_APB_WR(0x10000U + (idx << 12U) + 0x10U
                        + (bit * 0x100U), ddrRxcWa->rxclkinitv[idx][bit][0U]
                        + (uint32_t)offset);

                    DWC_DDRPHY_APB_WR(0x10000U + (idx << 12U) + 0x11U
                        + (bit * 0x100U), ddrRxcWa->rxclkinitv[idx][bit][1U]
                        + (uint32_t)offset);

                    DWC_DDRPHY_APB_WR(0x10000U + (idx << 12U) + 0x12U
                        + (bit * 0x100U), ddrRxcWa->rxclkinitv[idx][bit][2U]
                        + (uint32_t)offset);

                    DWC_DDRPHY_APB_WR(0x10000U + (idx << 12U) + 0x13U
                        + (bit * 0x100U), ddrRxcWa->rxclkinitv[idx][bit][3U]
                        + (uint32_t)offset);
                }
            }

            ddrRxcWa->rxclkoffset[idx] = (int16_t) offset;
        }

        /* Re-enable PHY Master interface */
        DWC_DDRPHY_APB_WR(0x20054U, 0x1U);

#ifdef DEBUG_RELOCK_PHY_CSRS // Re-lock PHY CSRs if this is defined
        DWC_DDRPHY_APB_WR(0xd0000U, 0x1U);
#endif

#if defined(INC_LIBC) && defined(DEBUG_PRINT_WA_RUNTIME)
        printf("RX WA took = %u\n", (uint32_t) (SYSCTR_GetUsec64()
            - start));
#endif
    }
}

/*--------------------------------------------------------------------------*/
/* Divide and round (up or down) function                                   */
/*--------------------------------------------------------------------------*/
static uint32_t DDR_SimpleDivRound(uint32_t val, uint32_t denom)
{
    uint32_t oneOrZero;
    uint32_t absV;

    oneOrZero = ((val % denom) >= (denom / 2U)) ? 1U : 0U;

    /*
     * False Positive: The variable oneOrZero can only have values 0 or 1.
     * There is a theoretical wraparound scenario when val equals UINT32_MAX
     * and denom is 1. However, the count variable is always either 128 or 100,
     * which ensures that wrapping cannot occur.
     * Therefore, this is a false positive.
     */
    /* coverity[cert_int30_c_violation] */
    absV = (val / denom) + oneOrZero;

    return absV;
}

