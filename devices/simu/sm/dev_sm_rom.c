/*
** ###################################################################
**
**     Copyright 2023-2024 NXP
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
/* File containing the implementation of the device ROM access functions.   */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"

/* Local defines */

#define HANDOVER_BASE     0x3003DC00U
#define HANDOVER_BARKER   0xC0FFEE16U
#define HANDOVER_VER      0x2U
#define HANDOVER_SIZE     0x100U

#define PASSOVER_BASE     0x3003DE00U
#define PASSOVER_TAG      0x504FU
#define PASSOVER_SIZE     0x80U
#define PASSOVER_VER      0x2U

/* ROM handover image flags */
#define ROM_HANDOVER_IMG_CPU(x)    (((x) & 0x00FFU) >> 0U)
#define ROM_HANDOVER_IMG_TYPE(x)   (((x) & 0xFF00U) >> 8U)
#define ROM_HANDOVER_IMG_MSEL(x)   (((x) & 0x00FF0000U) >> 16U)
#define ROM_HANDOVER_IMG_FLAGS(x)  (((x) & 0xFF000000U) >> 24U)

/* Local types */

/* Local variables */

static uint32_t s_imageIdx = 0U;

/* Global variables */

rom_passover_t g_romPassover =
{
    .tag = PASSOVER_TAG,
    .size = PASSOVER_SIZE,
    .ver = PASSOVER_VER
};

/*--------------------------------------------------------------------------*/
/* Return handover data                                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_RomHandoverGet(const rom_handover_t **handover)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Storage for fake handover data */
    static const rom_handover_t s_romHandover =
    {
        .barker = HANDOVER_BARKER,
        .ver = HANDOVER_VER,
        .size = HANDOVER_SIZE,
        .num = 3U,
        .img[0] =
        {
            .flags = DEV_SM_CPU_1,
            .addr = 0x12345678U
        },
        .img[1] =
        {
            .flags = (DEV_SM_ROM_IMG_DATA << 8U),
            .addr = 0xDEADBEEFU
        },
        .img[2] =
        {
            .flags = DEV_SM_CPU_2,
            .addr = 0x12345678U
        }
    };

    /* Return pointer to data */
    *handover = &s_romHandover;

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return passover data                                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_RomPassoverGet(const rom_passover_t **passover)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return pointer to data */
    *passover = &g_romPassover;

    SM_TEST_MODE_ERR(SM_TEST_MODE_DEV_LVL1, SM_ERR_TEST)

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return first image                                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_RomBootImg1Get(uint32_t type, uint32_t *cpuId,
    uint64_t *addr, uint32_t *mSel, uint32_t *flags)
{
    s_imageIdx = 0U;

    return DEV_SM_RomBootImgNGet(type, cpuId, addr, mSel, flags);
}

/*--------------------------------------------------------------------------*/
/* Return next image                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_RomBootImgNGet(uint32_t type, uint32_t *cpuId,
    uint64_t *addr, uint32_t *mSel, uint32_t *flags)
{
    int32_t status;
    const rom_handover_t *ptr;

    /* Get handover pointer */
    status = DEV_SM_RomHandoverGet(&ptr);

    /* Loop looking for next image type */
    while ((status == SM_ERR_SUCCESS) && (s_imageIdx < ptr->num))
    {
        const rom_bootlist_t *img = &(ptr->img[s_imageIdx]);

        /* Image type found? */
        if (type == ROM_HANDOVER_IMG_TYPE(img->flags))
        {
            break;
        }
        else
        {
            /* Next image */
            s_imageIdx++;
        }
    }

    /* Found? */
    if ((status == SM_ERR_SUCCESS) && (s_imageIdx < ptr->num))
    {
        const rom_bootlist_t *img = &(ptr->img[s_imageIdx]);

        /* Return data */
        *cpuId = ROM_HANDOVER_IMG_CPU(img->flags);
        *mSel = ROM_HANDOVER_IMG_MSEL(img->flags);
        *flags = ROM_HANDOVER_IMG_FLAGS(img->flags);
        *addr = img->addr;

        /* Next image on next call */
        s_imageIdx++;
    }
    else
    {
        status = SM_ERR_NOT_FOUND;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get CPU boot data                                                        */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_RomBootCpuGet(uint32_t cpuId, uint64_t *resetVector,
    uint32_t *mSel, uint32_t *flags)
{
    int32_t status;
    uint32_t cpu;
    uint64_t addr;
    uint32_t sel;
    uint32_t fl;

    /* Get first image */
    status = DEV_SM_RomBootImg1Get(DEV_SM_ROM_IMG_EXEC, &cpu, &addr,
        &sel, &fl);

    /* Loop over images */
    while (status == SM_ERR_SUCCESS)
    {
        /* Found? */
        if (cpuId == cpu)
        {
            /* Return data */
            *resetVector = addr;
            *mSel = sel;
            *flags = fl;
            break;
        }

        /* Get next image */
        status = DEV_SM_RomBootImgNGet(DEV_SM_ROM_IMG_EXEC, &cpu, &addr,
            &sel, &fl);
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set boot stage                                                           */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_RomStageSet(uint32_t stage)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set boot container                                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_RomContainerSet(uint32_t container)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

