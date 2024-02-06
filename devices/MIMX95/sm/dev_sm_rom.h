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

#ifndef DEV_SM_ROM_H
#define DEV_SM_ROM_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX95_ROM
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device ROM.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*!
 * See the RM (ROM spec).
 *
 * @cond Doxygen_Suppress
 */

/*! Max number of container images */
#define HANDOVER_MAX_IMG  10U

/*!
 * @name Device ROM image types
 */
/** @{ */
#define DEV_SM_ROM_IMG_EXEC   0U
#define DEV_SM_ROM_IMG_DATA   1U
/** @} */

/*!
 * @name Device ROM boot mode
 */
/** @{ */
#define DEV_SM_ROM_BM_FUSE    0x0U
#define DEV_SM_ROM_BM_USB     0x1U
#define DEV_SM_ROM_BM_NORMAL  0x2U
#define DEV_SM_ROM_BM_LOOP    0x3U
#define DEV_SM_ROM_BM_TEST    0x4U
/** @} */

/*!
 * @name Device ROM card mode
 */
/** @{ */
#define DEV_SM_ROM_CM_BYTE     0x0U
#define DEV_SM_ROM_CM_SECTION  0x1U
/** @} */

/*!
 * @name Device ROM boot stage
 */
/** @{ */
#define DEV_SM_ROM_BS_PRIMARY    0x6U
#define DEV_SM_ROM_BS_SECONDARY  0x9U
#define DEV_SM_ROM_BS_RECOVERY   0xAU
#define DEV_SM_ROM_BS_SERIAL     0x5U
/** @} */

/*!
 * @name Device ROM boot device
 */
/** @{ */
#define DEV_SM_ROM_BD_PRELOAD      0x0U
#define DEV_SM_ROM_BD_SD           0x1U
#define DEV_SM_ROM_BD_MMC          0x2U
#define DEV_SM_ROM_BD_FLEXSPINOR   0x4U
#define DEV_SM_ROM_BD_LPSPIEEPROM  0x6U
#define DEV_SM_ROM_BD_FLEXSPINAND  0x8U
#define DEV_SM_ROM_BD_USB          0xEU
/** @} */

/*! @endcond */

/* Types */

/*! This type is used to store a CPU start request */
typedef struct
{
    uint64_t addr;   //!< 64-bit address to boot from
    uint16_t cpu;    //!< CPU to start
    uint16_t resv;   //!< Reserved
    uint32_t flags;  //!< Start flags
} rom_bootlist_t;

/*! This type is used pass handover from the ROM to the SM */
typedef struct
{
    uint32_t barker;                       //!< Barker code
    uint16_t ver;                          //!< Version
    uint16_t size;                         //!< Size, 0x100
    uint8_t num;                           //!< Number images in list
    uint8_t resv0[3];                      //!< Reserved
    uint32_t flags;                        //!< Boot data flags
    rom_bootlist_t img[HANDOVER_MAX_IMG];  //!< image list
    uint32_t resv1[4];                     //!< was SCD address
} rom_handover_t;

/*! This type is used to pass passover data from the ROM to the AP */
typedef struct
{
    uint16_t tag;               //!< Tag
    uint8_t size;               //!< Size, 0x80
    uint8_t ver;                //!< Version
    uint32_t bootMode;          //!< Boot mode
    uint32_t cardAddrMode;      //!< SD card address mode
    uint32_t badBlksOfImgSet1;  //!< NAND bad block count skipped 1
    uint32_t resv0;             //!< Reserved
    uint32_t badBlksOfImgSet2;  //!< NAND bad block count skipped 1
    uint8_t bootStage;          //!< Boot stage
    uint8_t imgSetSel;          //!< Image set booted from
    uint8_t resv1[2];           //!< Reserved
    uint32_t imgSetEnd;         //!< Offset of Image End
    uint32_t romVersion;        //!< ROM version
    uint8_t bootDevState;       //!< Boot device state
    uint8_t bootDevInst;        //!< Boot device instance
    uint8_t bootDevType;        //!< Boot device type
    uint8_t rsv1;               //!< Reserved
    uint32_t devPageSize;       //!< Boot device page size
    uint32_t cntHeaderOfs;      //!< Container header offset
    uint32_t imgOfs;            //!< Image offset
} rom_passover_t;

/* Functions */

/** @} */

/* Include SM device API */

#include "dev_sm_rom_api.h"

#endif /* DEV_SM_ROM_H */

