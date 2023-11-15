/*
** ###################################################################
**
**     Copyright 2023 NXP
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

#define HANDOVER_BASE    0x2003DC00U
#define HANDOVER_BARKER  0xC0FFEE16U
#define HANDOVER_VER     0x2U
#define HANDOVER_SIZE    0x100U

#define PASSOVER_BASE  0x2003DE00U
#define PASSOVER_TAG   0x504FU
#define PASSOVER_SIZE  0x80U
#define PASSOVER_VER   0x2U

/* ROM handover image flags */
#define ROM_HANDOVER_IMG_CPU(x)    (((x) & 0x00FFU) >> 0U)
#define ROM_HANDOVER_IMG_TYPE(x)   (((x) & 0xFF00U) >> 8U)
#define ROM_HANDOVER_IMG_MSEL(x)   (((x) & 0x00FF0000U) >> 16U)
#define ROM_HANDOVER_IMG_FLAGS(x)  (((x) & 0xFF000000U) >> 24U)

#define ROM_STAGE_SHIFT  24U
#define ROM_STAGE_MASK   0x0F000000UL

#define ROM_CONTAINER_1  0x55CCU
#define ROM_CONTAINER_2  0xAA33U

/* Local types */

/* Local variables */

static uint32_t s_imageIdx = 0U;
static uint64_t s_m7Addr = 0U;
static bool s_m7AddValid = false;

/*--------------------------------------------------------------------------*/
/* Init passover data                                                       */
/*--------------------------------------------------------------------------*/
void DEV_SM_RomInit(void)
{
    if (SRC_MixIsPwrSwitchOn(DEV_SM_PD_M7))
    {
        s_m7AddValid = CPU_ResetVectorGet(DEV_SM_CPU_M7P, &s_m7Addr);
    }
}

/*--------------------------------------------------------------------------*/
/* Return handover data                                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_RomHandoverGet(const rom_handover_t **handover)
{
    int32_t status = SM_ERR_SUCCESS;
    const rom_handover_t *ptr = (const rom_handover_t *) HANDOVER_BASE;

    /* Check barker */
    if (ptr->barker != HANDOVER_BARKER)
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check version */
    if ((status == SM_ERR_SUCCESS) && (ptr->ver != HANDOVER_VER))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check size */
    if ((status == SM_ERR_SUCCESS) && (ptr->size < sizeof(rom_handover_t)))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Return pointer to data */
    if (status == SM_ERR_SUCCESS)
    {
        *handover = ptr;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Return passover data                                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_RomPassoverGet(const rom_passover_t **passover)
{
    int32_t status = SM_ERR_SUCCESS;
    const rom_passover_t *ptr = (const rom_passover_t *) PASSOVER_BASE;

    /* Check tag */
    if (ptr->tag != PASSOVER_TAG)
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check version */
    if ((status == SM_ERR_SUCCESS) && (ptr->ver != PASSOVER_VER))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Check size */
    if ((status == SM_ERR_SUCCESS) && (ptr->size < sizeof(rom_passover_t)))
    {
        status = SM_ERR_NOT_SUPPORTED;
    }

    /* Return pointer to data */
    if (status == SM_ERR_SUCCESS)
    {
        *passover = ptr;
    }

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

        /* TODO: Temp fix for ROM address patch */
        if (s_m7AddValid && (*cpuId == DEV_SM_CPU_M7P))
        {
            *addr = s_m7Addr;
        }

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
    uint32_t temp;

    /* Configure stage */
    temp = SRC_GEN->GPR16 & ~ROM_STAGE_MASK;
    SRC_GEN->GPR16 = temp | ((stage << ROM_STAGE_SHIFT) & ROM_STAGE_MASK);

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set boot container                                                       */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_RomContainerSet(uint32_t container)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Configure container */
    if (container == 0U)
    {
        SRC_GEN->GPR15 = ROM_CONTAINER_1;
    }
    else if (container == 1U)
    {
        SRC_GEN->GPR15 = ROM_CONTAINER_2;
    }
    else
    {
        status = SM_ERR_INVALID_PARAMETERS;
    }

    /* Return status */
    return status;
}

