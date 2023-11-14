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

/*==========================================================================*/
/* Implementation of the SM debug monitor TRDC commands.                    */
/*==========================================================================*/

/* Includes */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>
#include "sm.h"
#include "monitor.h"
#include "monitor_trdc.h"
#include "monitor_reg.h"
#include "dev_sm_api.h"

/* Defines */

/* Types */

/* Local Functions */

static void MONITOR_DisplayGlbac(uint32_t glbac);
static void MONITOR_DisplayBlkCfg(uint32_t mbc, uint32_t did, uint32_t mem,
    uint32_t addr, uint32_t nblks);
static void MONITOR_DumpRegion(uint32_t addr, uint32_t len);
static void MONITOR_DisplayErr(uint32_t rdcId, uint32_t did,
    uint32_t derrloc);
static void MONITOR_DisplayDErr(char rdcLabel, bool mrc, uint32_t inst,
    TRDC_DERR_Type *derr);
static int32_t MONITOR_TrdcNameToBase(const char *trdcName,
    uint32_t *trdcBase);

/* Local Variables */

/*--------------------------------------------------------------------------*/
/* TRDC command                                                             */
/*--------------------------------------------------------------------------*/
int32_t MONITOR_CmdTrdc(int32_t argc, const char * const argv[])
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t baseAddr;
    const TRDC_MGR_Type *mgr;
    uint32_t ldid = 0U, hdid = 15U;

    /* Parse argument */
    if (argc > 0)
    {
        status = MONITOR_TrdcNameToBase(argv[0], &baseAddr);

        if (argc > 1)
        {
            uint32_t did = 0U;

            errno = 0;
            did = strtoul(argv[1], NULL, 0);
            if (errno == 0)
            {
                ldid = did;
                hdid = did;
            }
        }
    }
    else
    {
        status = SM_ERR_MISSING_PARAMETERS;
    }

    /* Probe for access */
    if (status == SM_ERR_SUCCESS)
    {
        mgr = (TRDC_MGR_Type*) baseAddr;

        uint32_t v = 0U;
        uint32_t a = (uint32_t) &(mgr->TRDC_CR);

        if (SystemMemoryProbe((void*) a, &v, 32U) != 0U)
        {
            status = SM_ERR_POWER;
        }
    }

    /* Dump TRDC */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t v = 0U;
        uint32_t ndid = ((mgr->TRDC_HWCFG0 & TRDC_TRDC_HWCFG0_NDID_MASK)
            >> TRDC_TRDC_HWCFG0_NDID_SHIFT);
        uint32_t nmstr = ((mgr->TRDC_HWCFG0 & TRDC_TRDC_HWCFG0_NMSTR_MASK)
            >> TRDC_TRDC_HWCFG0_NMSTR_SHIFT);
        uint32_t nmbc = ((mgr->TRDC_HWCFG0 & TRDC_TRDC_HWCFG0_NMBC_MASK)
            >> TRDC_TRDC_HWCFG0_NMBC_SHIFT);
        uint32_t nmrc = ((mgr->TRDC_HWCFG0 & TRDC_TRDC_HWCFG0_NMRC_MASK)
            >> TRDC_TRDC_HWCFG0_NMRC_SHIFT);
        uint32_t mid = ((mgr->TRDC_HWCFG0 & TRDC_TRDC_HWCFG0_MID_MASK)
            >> TRDC_TRDC_HWCFG0_MID_SHIFT);
        uint32_t did = ((mgr->TRDC_HWCFG1 & TRDC_TRDC_HWCFG1_DID_MASK)
            >> TRDC_TRDC_HWCFG1_DID_SHIFT);

        /* Tick wdog */
        BOARD_WdogRefresh();

        /* Display MGR info */
        printf("CR:      0x%08X\n", mgr->TRDC_CR);
        printf("HWCFG0:  0x%08X, MID=%u NMRC=%u NMBC=%u NMSTR=%u NDID=%u\n",
            mgr->TRDC_HWCFG0, mid, nmrc, nmbc, nmstr, ndid);
        printf("HWCFG1:  0x%08X, DID=%u\n",
            mgr->TRDC_HWCFG1, did);

        if (SystemMemoryProbe((void*) (uint32_t) &(mgr->TRDC_HWCFG2),
            &v, 32U) == 0U)
        {
            if (v != 0U)
            {
                printf("HWCFG2:  0x%08X, PIDPn[31-00]=0x%08X\n", v, v);
            }
        }

        if (SystemMemoryProbe((void*) (uint32_t) &(mgr->TRDC_HWCFG3),
            &v, 32U) == 0U)
        {
            if (v != 0U)
            {
                printf("HWCFG3:  0x%08X, PIDPn[63-32]=0x%08X\n", v, v);
            }
        }

        for (uint32_t mstr = 0U; mstr < nmstr; mstr++)
        {
            uint8_t ncm = ((mgr->DACFG[mstr] & TRDC_DACFG_NCM_MASK)
                >> TRDC_DACFG_NCM_SHIFT);
            uint8_t nmdar = ((mgr->DACFG[mstr] & TRDC_DACFG_NMDAR_MASK)
                >> TRDC_DACFG_NMDAR_SHIFT);

            /* Skip if not valid */
            if (nmdar == 0U) { continue; }

            printf("DACFG%u:  0x%02X, NCM=%u NMDAR=%u\n",
                mstr, mgr->DACFG[mstr], ncm, nmdar);
        }
        printf("IDAU_CR: 0x%08X\n", mgr->TRDC_IDAU_CR);
        printf("\n");

        /* Print DAC */
        for (uint32_t mstr = 0U; mstr < nmstr; mstr++)
        {
            uint8_t nmdar = ((mgr->DACFG[mstr] & TRDC_DACFG_NMDAR_MASK)
                >> TRDC_DACFG_NMDAR_SHIFT);

            for (uint32_t mdar = 0U; mdar < ((uint32_t) nmdar); mdar++)
            {
                uint32_t vld = ((mgr->MDA[mstr][mdar]
                    & TRDC_MDA_W_DFMT0_VLD_MASK)
                    >> TRDC_MDA_W_DFMT0_VLD_SHIFT);
                uint32_t lk1 = ((mgr->MDA[mstr][mdar]
                    & TRDC_MDA_W_DFMT0_LK1_MASK)
                    >> TRDC_MDA_W_DFMT0_LK1_SHIFT);
                uint32_t dfmt = ((mgr->MDA[mstr][mdar]
                    & TRDC_MDA_W_DFMT0_DFMT_MASK)
                    >> TRDC_MDA_W_DFMT0_DFMT_SHIFT);
                uint32_t kpa = ((mgr->MDA[mstr][mdar]
                    & 0x10000000U)
                    >> 28U);
                uint32_t sid = ((mgr->MDA[mstr][mdar]
                    & 0x0FC00000U)
                    >> 22U);

                /* Skip if not valid */
                if (vld == 0U) { continue; }

                printf("MDA_W%u_%u_DFMT%u: 0x%08X, VLD=%u",
                    mdar, mstr, dfmt, mgr->MDA[mstr][mdar], vld);
                if (lk1 != 0U)
                {
                    printf(" LK1=%u", lk1);
                }
                if (dfmt == 0U)
                {
                    uint32_t pe = ((mgr->MDA[mstr][mdar]
                        & TRDC_MDA_W_DFMT0_PE_MASK)
                        >> TRDC_MDA_W_DFMT0_PE_SHIFT);

                    if (pe != 0U)
                    {
                        printf(" PID=%u", (mgr->MDA[mstr][mdar]
                            & TRDC_MDA_W_DFMT0_PID_MASK)
                            >> TRDC_MDA_W_DFMT0_PID_SHIFT);
                        printf(", PIDM=%u", (mgr->MDA[mstr][mdar]
                            & TRDC_MDA_W_DFMT0_PIDM_MASK)
                            >> TRDC_MDA_W_DFMT0_PIDM_SHIFT);
                        printf(" PE=%u", (mgr->MDA[mstr][mdar]
                            & TRDC_MDA_W_DFMT0_PE_MASK)
                            >> TRDC_MDA_W_DFMT0_PE_SHIFT);
                    }
                    printf(" SA=%u", (mgr->MDA[mstr][mdar]
                        & TRDC_MDA_W_DFMT0_SA_MASK)
                        >> TRDC_MDA_W_DFMT0_SA_SHIFT);
                    printf(" DIDS=%u", (mgr->MDA[mstr][mdar]
                        & TRDC_MDA_W_DFMT0_DIDS_MASK)
                        >> TRDC_MDA_W_DFMT0_DIDS_SHIFT);
                }
                else
                {
                    printf(" DIDB=%u", (mgr->MDA[mstr][mdar]
                        & TRDC_MDA_W_DFMT1_DIDB_MASK)
                        >> TRDC_MDA_W_DFMT1_DIDB_SHIFT);
                    printf(" SA=%u", (mgr->MDA[mstr][mdar]
                        & TRDC_MDA_W_DFMT1_SA_MASK)
                        >> TRDC_MDA_W_DFMT1_SA_SHIFT);
                    printf(" PA=%u", (mgr->MDA[mstr][mdar]
                        & TRDC_MDA_W_DFMT1_PA_MASK)
                        >> TRDC_MDA_W_DFMT1_PA_SHIFT);
                }

                if (kpa != 0U)
                {
                    printf(" KPA=%u", kpa);
                }

                if (sid != 0U)
                {
                    printf(" SID=0x%02X", sid);
                }

                printf(" DID=%d\n", (mgr->MDA[mstr][mdar]
                    & TRDC_MDA_W_DFMT0_DID_MASK)
                    >> TRDC_MDA_W_DFMT0_DID_SHIFT);
            }
        }

        /* Print MBC */
        baseAddr += 0x10000U;
        for (uint32_t mbc = 0U; mbc < nmbc; mbc++)
        {
            TRDC_MBC_Type *base = (TRDC_MBC_Type*) baseAddr;
            uint32_t nblks[4];

            /* Tick wdog */
            BOARD_WdogRefresh();

            printf("\n");

            for (uint32_t mem = 0U; mem < 4U; mem++)
            {
                nblks[mem] = ((base->MEM[mem].GLBCFG
                    & TRDC_MBC_MEM_GLBCFG_NBLKS_MASK)
                    >> TRDC_MBC_MEM_GLBCFG_NBLKS_SHIFT);

                if (nblks[mem] != 0U)
                {
                    uint32_t size = ((base->MEM[mem].GLBCFG
                        & TRDC_MBC_MEM_GLBCFG_SIZE_LOG2_MASK)
                        >> TRDC_MBC_MEM_GLBCFG_SIZE_LOG2_SHIFT);

                    /* Calc size in kbytes */
                    size = (1UL << size) / 1024U;

                    printf("MBC%u_MEM%u_GLBCFG: 0x%08X", mbc, mem,
                        base->MEM[mem].GLBCFG);
                    printf(", SIZE=%uK", size);
                    printf(" NBLKS=%u\n", nblks[mem]);
                }
            }

            for (uint32_t ac = 0U; ac < 8U; ac++)
            {
                printf("MBC%u_MEMN_GLBAC%u: 0x%08X", mbc, ac,
                    base->GLBAC[ac]);
                MONITOR_DisplayGlbac(base->GLBAC[ac]);
            }

            for (uint32_t d = ldid; d <= hdid; d++)
            {
                /* Tick wdog */
                BOARD_WdogRefresh();

                MONITOR_DisplayBlkCfg(mbc, d, 0U, (uint32_t)
                    &(base->DOM[d].MEM0_BLK_CFG),
                    nblks[0]);

                for (uint32_t w = 0U; w < 16U; w++)
                {
                    if (nblks[0] > (w * 32U))
                    {
                        printf("MBC%u_DOM%u_MEM0_BLK_NSE_W%u:  ",
                            mbc, d, w);

                        if (d < 10U)
                        {
                            printf(" ");
                        }

                        printf("0x%08X\n",
                            base->DOM[d].MEM0_BLK_NSE[w]);
                    }
                }

                for (uint32_t mem = 1U; mem < 4U; mem++)
                {
                    MONITOR_DisplayBlkCfg(mbc, d, mem, (uint32_t)
                        &(base->DOM[d].MEM[mem - 1U].BLK_CFG),
                        nblks[mem]);

                    for (uint32_t w = 0U; w < 2U; w++)
                    {
                        if (nblks[mem] > (w * 32U))
                        {
                            printf("MBC%u_DOM%u_MEM%u_BLK_NSE_W%u:  ",
                                mbc, d, mem, w);

                            if (d < 10U)
                            {
                                printf(" ");
                            }

                            printf("0x%08X\n",
                                base->DOM[d].MEM[mem - 1U].BLK_NSE[w]);
                        }
                    }
                }
            }

            baseAddr += 0x2000U;
        }

        /* Print MRC */
        for (uint32_t mrc = 0U; mrc < nmrc; mrc++)
        {
            const TRDC_MRC_Type *base = (TRDC_MRC_Type*) baseAddr;

            /* Tick wdog */
            BOARD_WdogRefresh();

            printf("\n");

            uint32_t nrgns = ((base->GLBCFG
                & TRDC_MRC_GLBCFG_NRGNS_MASK)
                >> TRDC_MRC_GLBCFG_NRGNS_SHIFT);

            printf("MRC%u_GLBCFG: 0x%08X", mrc, base->GLBCFG);
            printf(", NRGNS=%u\n", nrgns);

            for (uint32_t ac = 0U; ac < 8U; ac++)
            {
                printf("MRC%u_MEMN_GLBAC%u: 0x%08X", mrc, ac,
                    base->GLBAC[ac]);
                MONITOR_DisplayGlbac(base->GLBAC[ac]);
            }

            for (uint32_t d = ldid; d <= hdid; d++)
            {
                /* Tick wdog */
                BOARD_WdogRefresh();

                for (uint32_t r = 0U; r < nrgns; r++)
                {
                    uint32_t w0 = base->DOM[d].RGN[r].W0;
                    uint32_t w1 = base->DOM[d].RGN[r].W1;

                    uint32_t vld = ((w1
                        & TRDC_MRC_DOM0_RGD_W_VLD_MASK)
                        >> TRDC_MRC_DOM0_RGD_W_VLD_SHIFT);

                    if (vld != 0U)
                    {
                        printf("MRC%u_DOM%u_RGD%u_W0: 0x%08X", mrc, d, r,
                            w0);
                        printf(", START_ADDR=0x%08X", (w0
                            & TRDC_MRC_DOM0_RGD_W_STRT_ADDR_MASK));
                        printf(", MRACSEL=%u\n", (w0
                            & TRDC_MRC_DOM0_RGD_W_MRACSEL_MASK)
                            >> TRDC_MRC_DOM0_RGD_W_MRACSEL_SHIFT);
                        printf("MRC%u_DOM%u_RGD%u_W1: 0x%08X", mrc, d, r,
                            w1);
                        printf(", END_ADDR=0x%08X", (w1
                            & TRDC_MRC_DOM0_RGD_W_END_ADDR_MASK)
                            | 0x3FFFU);
                        printf(", NSE=%u", (w1
                            & TRDC_MRC_DOM0_RGD_W_NSE_MASK)
                            >> TRDC_MRC_DOM0_RGD_W_NSE_SHIFT);
                        printf(", VLD=%u\n", vld);
                    }
                }
            }

            baseAddr += 0x1000U;
        }

    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* TRDC raw command                                                         */
/*--------------------------------------------------------------------------*/
int32_t MONITOR_CmdTrdcRaw(int32_t argc, const char * const argv[])
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t baseAddr;
    const TRDC_MGR_Type *mgr;
    uint32_t ldid = 0U, hdid = 15U;

    /* Parse argument */
    if (argc > 0)
    {
        status = MONITOR_TrdcNameToBase(argv[0], &baseAddr);

        if (argc > 1)
        {
            uint32_t did = 0U;

            errno = 0;
            did = strtoul(argv[1], NULL, 0);
            if (errno == 0)
            {
                ldid = did;
                hdid = did;
            }
        }
    }
    else
    {
        status = SM_ERR_MISSING_PARAMETERS;
    }

    /* Probe for access */
    if (status == SM_ERR_SUCCESS)
    {
        mgr = (TRDC_MGR_Type*) baseAddr;

        uint32_t v = 0U;
        uint32_t a = (uint32_t) &(mgr->TRDC_CR);

        if (SystemMemoryProbe((void*) a, &v, 32U) != 0U)
        {
            status = SM_ERR_POWER;
        }
    }

    /* Dump TRDC */
    if (status == SM_ERR_SUCCESS)
    {
        uint32_t nmbc = ((mgr->TRDC_HWCFG0 & TRDC_TRDC_HWCFG0_NMBC_MASK)
            >> TRDC_TRDC_HWCFG0_NMBC_SHIFT);
        uint32_t nmrc = ((mgr->TRDC_HWCFG0 & TRDC_TRDC_HWCFG0_NMRC_MASK)
            >> TRDC_TRDC_HWCFG0_NMRC_SHIFT);

        MONITOR_DumpRegion((uint32_t)&(mgr->TRDC_CR), 16U);
        MONITOR_DumpRegion((uint32_t)&(mgr->TRDC_IDAU_CR), 16U);
        MONITOR_DumpRegion((uint32_t)&(mgr->PID), sizeof(mgr->PID));
        MONITOR_DumpRegion((uint32_t)&(mgr->MDA), sizeof(mgr->MDA));

        /* Dump MBC */
        baseAddr += 0x10000U;
        for (uint32_t mbc = 0U; mbc < nmbc; mbc++)
        {
            TRDC_MBC_Type *base = (TRDC_MBC_Type*) baseAddr;

            MONITOR_DumpRegion((uint32_t)&(base->GLBAC),
                sizeof(base->GLBAC));

            for (uint32_t did = ldid; did <= hdid; did++)
            {
                MONITOR_DumpRegion((uint32_t)&(base->DOM[did]),
                    sizeof(base->DOM[did]) - 72U);
            }

            baseAddr += 0x2000U;
        }

        /* Dump MRC */
        for (uint32_t mrc = 0U; mrc < nmrc; mrc++)
        {
            TRDC_MRC_Type *base = (TRDC_MRC_Type*) baseAddr;

            MONITOR_DumpRegion((uint32_t)&(base->GLBAC),
                sizeof(base->GLBAC));

            for (uint32_t did = ldid; did <= hdid; did++)
            {
                MONITOR_DumpRegion((uint32_t)&(base->DOM[did]),
                    sizeof(base->DOM[did]) - 72U);
            }

            baseAddr += 0x1000U;
        }
    }

    return status;
}

/*--------------------------------------------------------------------------*/
/* TRDC error command                                                       */
/*--------------------------------------------------------------------------*/
int32_t MONITOR_CmdTrdcErr(int32_t argc, const char * const argv[])
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t rdcId = 0U;

    /* Loop over TRDC */
    while (status != SM_ERR_NOT_FOUND)
    {
        uint32_t trdcBase;
        const TRDC_MGR_Type *mgr;

        status = DEV_SM_RdcInfoGet(rdcId, NULL, NULL, &trdcBase);

        /* Probe for access */
        if (status == SM_ERR_SUCCESS)
        {
            mgr = (TRDC_MGR_Type*) trdcBase;

            uint32_t v = 0U;
            uint32_t a = (uint32_t) &(mgr->TRDC_CR);

            if (SystemMemoryProbe((void*) a, &v, 32U) != 0U)
            {
                status = SM_ERR_POWER;
            }
        }

        if (status == SM_ERR_SUCCESS)
        {
            uint32_t ndid = ((mgr->TRDC_HWCFG0 & TRDC_TRDC_HWCFG0_NDID_MASK)
                >> TRDC_TRDC_HWCFG0_NDID_SHIFT);

            /* Loop over all domains */
            for (uint32_t d = 0U; d < ndid; d++)
            {
                uint32_t derrloc = mgr->TRDC_DERRLOC[d];

                /* Error reported? */
                if (derrloc != 0U)
                {
                    MONITOR_DisplayErr(rdcId, d, derrloc);

                }
            }
        }

        /* Next TRDC */
        rdcId++;
    }

    return SM_ERR_SUCCESS;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Display GLBAC                                                            */
/*--------------------------------------------------------------------------*/
static void MONITOR_DisplayGlbac(uint32_t glbac)
{
    string const accessNames[] =
    {
        "...",
        "..X",
        ".W.",
        ".WX",
        "R..",
        "R.X",
        "RW.",
        "RWX"
    };

    printf(", LK=%u", (glbac >> 31U) & 0x1U);
    printf(" SP=%s", accessNames[(glbac >> 12U) & 0xFU]);
    printf(" SU=%s", accessNames[(glbac >> 8U) & 0xFU]);
    printf(" NP=%s", accessNames[(glbac >> 4U) & 0xFU]);
    printf(" NU=%s\n", accessNames[glbac & 0xFU]);
}

/*--------------------------------------------------------------------------*/
/* Display block config                                                     */
/*--------------------------------------------------------------------------*/
static void MONITOR_DisplayBlkCfg(uint32_t mbc, uint32_t did, uint32_t mem,
    uint32_t addr, uint32_t nblks)
{
    const uint32_t *ptr = (uint32_t*) addr;
    uint32_t blk = 0U;
    uint32_t w = 0U;

    while (blk < nblks)
    {
        uint32_t top_blk;

        printf("MBC%u_DOM%u_MEM%u_BLK_CFG_W%u: ", mbc, did, mem, w);

        if (did < 10U)
        {
            printf(" ");
        }
        if (w < 10U)
        {
            printf(" ");
        }

        printf("0x%08X, BLK[", *ptr);

        top_blk = blk + 7U;

        if (top_blk > nblks)
        {
            top_blk = nblks;
        }

        printf("%u:%u]", top_blk, blk);

        if (top_blk < 10U)
        {
            printf(" ");
        }
        if (top_blk < 100U)
        {
            printf(" ");
        }
        if (blk < 10U)
        {
            printf(" ");
        }
        if (blk < 100U)
        {
            printf(" ");
        }

        printf(" = %08X\n", (*ptr) & 0x77777777U);

        ptr++;
        blk += 8U;
        w++;
    }
}

/*--------------------------------------------------------------------------*/
/* Dump region                                                              */
/*--------------------------------------------------------------------------*/
static void MONITOR_DumpRegion(uint32_t addr, uint32_t len)
{
    uint32_t *x = (uint32_t*) (addr & ~0x3U);
    uint32_t v = 0U;
    uint32_t siz = len;

    /* Tick wdog */
    BOARD_WdogRefresh();

    /* Min one word */
    if (siz < 4U)
    {
        siz = 4U;
    }

    siz /= 4U;

    /* Loop over region */
    for (uint32_t i = 0U; i < siz; i++)
    {
        if (SystemMemoryProbe(&(x[i]), &v, 32U) == 0U)
        {
            printf("0x%08X = 0x%08X\n", (uint32_t) &(x[i]), v);
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Display TRDC errors                                                      */
/*--------------------------------------------------------------------------*/
static void MONITOR_DisplayErr(uint32_t rdcId, uint32_t did,
    uint32_t derrloc)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t trdcBase;
    char rdcLabel;

    /* Get RDC info */
    status = DEV_SM_RdcInfoGet(rdcId, NULL, &rdcLabel, &trdcBase);

    if (status == SM_ERR_SUCCESS)
    {
        TRDC_MGR_Type *mgr = (TRDC_MGR_Type*) trdcBase;
        uint32_t mbcinst = ((derrloc & TRDC_TRDC_DERRLOC_MBCINST_MASK)
            >> TRDC_TRDC_DERRLOC_MBCINST_SHIFT);
        uint32_t mrcinst = ((derrloc & TRDC_TRDC_DERRLOC_MRCINST_MASK)
            >> TRDC_TRDC_DERRLOC_MRCINST_SHIFT);

        /* Page to did bank */
        mgr->TRDC_FDID = did;

        /* MBC error? */
        if (mbcinst != 0U)
        {
            uint32_t nmbc = ((mgr->TRDC_HWCFG0
                & TRDC_TRDC_HWCFG0_NMBC_MASK)
                >> TRDC_TRDC_HWCFG0_NMBC_SHIFT);

            /* Loop over MBC */
            for (uint32_t mbc = 0U; mbc < nmbc; mbc++)
            {
                if ((mbcinst & (1UL << mbc)) != 0U)
                {
                    MONITOR_DisplayDErr(rdcLabel, false, mbc,
                        (TRDC_DERR_Type*) &(mgr->MBC_DERR[mbc]));
                }
            }
        }

        /* MRC error? */
        if (mrcinst != 0U)
        {
            uint32_t nmrc = ((mgr->TRDC_HWCFG0
                & TRDC_TRDC_HWCFG0_NMRC_MASK)
                >> TRDC_TRDC_HWCFG0_NMRC_SHIFT);

            /* Loop over MRC */
            for (uint32_t mrc = 0U; mrc < nmrc; mrc++)
            {
                if ((mrcinst & (1UL << mrc)) != 0U)
                {
                    MONITOR_DisplayDErr(rdcLabel, true, mrc,
                        (TRDC_DERR_Type*) &(mgr->MRC_DERR[mrc]));
                }
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
/* Convert resource name to an ID                                           */
/*--------------------------------------------------------------------------*/
static void MONITOR_DisplayDErr(char rdcLabel, bool mrc, uint32_t inst,
    TRDC_DERR_Type *derr)
{
    uint32_t blk = ((derr->W0 & 0x007F0000UL)
        >> 16);
    bool eaddr = false;
    uint32_t est = ((derr->W1 & TRDC_W1_EST_MASK)
        >> TRDC_W1_EST_SHIFT);
    uint32_t edid = ((derr->W1 & TRDC_W1_EDID_MASK)
        >> TRDC_W1_EDID_SHIFT);
    uint32_t erw = ((derr->W1 & TRDC_W1_ERW_MASK)
        >> TRDC_W1_ERW_SHIFT);
    uint32_t eport = ((derr->W1 & TRDC_W1_EPORT_MASK)
        >> TRDC_W1_EPORT_SHIFT);
    uint32_t eatr = ((derr->W1 & TRDC_W1_EATR_MASK)
        >> TRDC_W1_EATR_SHIFT);

    /* Next word if EST not set */
    if (est == 0U)
    {
        eaddr = true;
        edid = ((derr->W2 & TRDC_W1_EDID_MASK)
            >> TRDC_W1_EDID_SHIFT);
        erw = ((derr->W2 & TRDC_W1_ERW_MASK)
            >> TRDC_W1_ERW_SHIFT);
        eport = ((derr->W2 & TRDC_W1_EPORT_MASK)
            >> TRDC_W1_EPORT_SHIFT);
        eatr = ((derr->W2 & TRDC_W1_EATR_MASK)
            >> TRDC_W1_EATR_SHIFT);
    }

    /* Print error */
    printf("DOM%u ", edid);
    if ((eatr & 0x4U) != 0U)
    {
        printf("ns ");
    }
    else
    {
        printf("sec ");
    }
    if ((eatr & 0x1U) != 0U)
    {
        if (erw != 0U)
        {
            printf("write to ");
        }
        else
        {
            printf("read from ");
        }
    }
    else
    {
        printf("fetch from ");
    }
    printf("0x");
    if (eaddr)
    {
        printf("%01X", derr->W1);
    }
    printf("%08X, ", derr->W0);

    /* Print TRDC info */
    if (mrc)
    {
        printf("MRC_%c%u=%u, ", rdcLabel, inst, eport);
        printf("MRC%u_DOM%u\n", inst, edid);
    }
    else
    {
        printf("MBC_%c%u=%u.%u, ", rdcLabel, inst, eport, blk);
        printf("MBC%u_DOM%u_MEM%u_BLK_CFG_W%u[%u]\n",
            inst, edid, eport, blk / 8U, blk % 8U);
    }

    /* Clear error */
    derr->W3 = TRDC_W3_RECR(1U);
}

/*--------------------------------------------------------------------------*/
/* Convert resource name to an ID                                           */
/*--------------------------------------------------------------------------*/
static int32_t MONITOR_TrdcNameToBase(const char *trdcName,
    uint32_t *trdcBase)
{
    int32_t status = SM_ERR_SUCCESS;
    uint32_t index = 0U;

    /* Lookup TRDC name */
    while (status != SM_ERR_NOT_FOUND)
    {
        string name;

        status = DEV_SM_RdcInfoGet(index, &name, NULL, trdcBase);

        if (((status == SM_ERR_SUCCESS) || (status == SM_ERR_POWER))
            && (strcasecmp(trdcName, name) == 0))
        {
            break;
        }

        /* Next TRDC */
        index++;
    }

    return status;
}

