/*
** ###################################################################
**
** Copyright 2026 NXP
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
/*!
 * @addtogroup CONFIG_MX952EVK
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing configuration info for the TRDC SM abstraction.
 */
/*==========================================================================*/

#ifndef CONFIG_TRDC_H
#define CONFIG_TRDC_H

/* Includes */

#include "config_user.h"

/* Defines */

/*--------------------------------------------------------------------------*/
/* TRDC A Config                                                            */
/*--------------------------------------------------------------------------*/

/*! Config for TRDC A */
#define SM_TRDC_A_CONFIG \
    { \
        SM_CFG_W1(0x00000800U), 0xA00000A0U, \
        SM_CFG_W1(0x00000820U), 0xA0000012U, \
        SM_CFG_W1(0x00000840U), 0xA0000013U, \
        SM_CFG_W1(0x00000860U), 0xA0000013U, \
        SM_CFG_W1(0x00000880U), 0xA0000053U, \
        SM_CFG_W1(0x000008a0U), 0xA0000053U, \
        SM_CFG_W1(0x000008c0U), 0xA0000014U, \
        SM_CFG_W1(0x00000a00U), 0x80000002U, \
        SM_CFG_W1(0x00000a04U), 0x80000002U, \
        SM_CFG_W1(0x00000a08U), 0x80000002U, \
        SM_CFG_W1(0x00000a20U), 0xA0000053U, \
        SM_CFG_W1(0x00000a40U), 0xA0000053U, \
        SM_CFG_W1(0x00000a60U), 0xA0000053U, \
        SM_CFG_W1(0x00000a80U), 0xA0000053U, \
        SM_CFG_W1(0x00000aa0U), 0xA0000053U, \
        SM_CFG_W1(0x00000ac0U), 0xA0000053U, \
        SM_CFG_W1(0x00000ae0U), 0xA0000053U, \
        SM_CFG_W1(0x00000b00U), 0xA0000053U, \
        SM_CFG_W1(0x00000b20U), 0xA0000053U, \
        SM_CFG_W1(0x00000b40U), 0xA0000053U, \
        SM_CFG_W1(0x00000b60U), 0xA0000053U, \
        SM_CFG_W1(0x00000b80U), 0xA0000053U, \
        SM_CFG_W1(0x00000ba0U), 0xA0000053U, \
        SM_CFG_W1(0x00000bc0U), 0xA0000053U, \
        SM_CFG_W1(0x00000be0U), 0xA0000053U, \
        SM_CFG_W1(0x00000c00U), 0xA0000053U, \
        SM_CFG_W1(0x00000c20U), 0xA0000053U, \
        SM_CFG_W1(0x00000c40U), 0xA0000053U, \
        SM_CFG_W1(0x00000c60U), 0xA0000053U, \
        SM_CFG_W1(0x00000c80U), 0xA0000053U, \
        SM_CFG_W1(0x00000ca0U), 0xA00000A1U, \
        SM_CFG_W1(0x00000cc0U), 0xA00000A1U, \
        SM_CFG_W1(0x00010024U), 0x6666U, \
        SM_CFG_W1(0x00010028U), 0x7777U, \
        SM_CFG_W1(0x0001002cU), 0x6600U, \
        SM_CFG_W1(0x00010030U), 0x4444U, \
        SM_CFG_Z1(0x00010050U), \
        SM_CFG_Z1(0x00010054U), \
        SM_CFG_W1(0x00010064U), 0x00000003U, \
        SM_CFG_W1(0x00010068U), 0x00000003U, \
        SM_CFG_W1(0x00010180U), 0x000000C0U, \
        SM_CFG_Z1(0x00010250U), \
        SM_CFG_Z1(0x00010254U), \
        SM_CFG_W1(0x00010264U), 0x00000990U, \
        SM_CFG_W1(0x00010380U), 0x000000C0U, \
        SM_CFG_W1(0x00010450U), 0x30003330U, \
        SM_CFG_W1(0x00010454U), 0x03333033U, \
        SM_CFG_W1(0x00010458U), 0x00030000U, \
        SM_CFG_W1(0x0001045cU), 0x33330030U, \
        SM_CFG_W1(0x00010460U), 0x33303333U, \
        SM_CFG_W1(0x00010464U), 0x30000003U, \
        SM_CFG_W1(0x00010468U), 0x33330030U, \
        SM_CFG_W1(0x0001046cU), 0x33333333U, \
        SM_CFG_W1(0x00010470U), 0x33333333U, \
        SM_CFG_W1(0x00010474U), 0x00003000U, \
        SM_CFG_W1(0x00010580U), 0x000003C0U, \
        SM_CFG_W1(0x000105a8U), 0x00000003U, \
        SM_CFG_W1(0x000105d0U), 0x00000003U, \
        SM_CFG_W1(0x00010640U), 0x99999999U, \
        SM_CFG_W1(0x00010644U), 0x99999999U, \
        SM_CFG_W1(0x00010648U), 0x99999999U, \
        SM_CFG_W1(0x0001064cU), 0x99999999U, \
        SM_CFG_W1(0x00010650U), 0x09000309U, \
        SM_CFG_W1(0x00010654U), 0x0000C900U, \
        SM_CFG_W1(0x00010658U), 0x99909900U, \
        SM_CFG_W1(0x0001065cU), 0x00009009U, \
        SM_CFG_W1(0x00010668U), 0x00009900U, \
        SM_CFG_W1(0x0001066cU), 0x90909000U, \
        SM_CFG_W1(0x00010670U), 0x00009000U, \
        SM_CFG_W1(0x00010780U), 0x099330C0U, \
        SM_CFG_Z1(0x00010850U), \
        SM_CFG_W1(0x00010854U), 0x9000C000U, \
        SM_CFG_W1(0x00010858U), 0x00000099U, \
        SM_CFG_W1(0x0001085cU), 0x00000900U, \
        SM_CFG_W1(0x00010870U), 0x00000090U, \
        SM_CFG_W1(0x00010874U), 0x00000999U, \
        SM_CFG_W1(0x00010980U), 0x900000C0U, \
        SM_CFG_Z1(0x00010a50U), \
        SM_CFG_Z1(0x00010a54U), \
        SM_CFG_W1(0x00010b80U), 0x000000C0U, \
        SM_CFG_Z1(0x00010c50U), \
        SM_CFG_Z1(0x00010c54U), \
        SM_CFG_W1(0x00010d80U), 0x000000C0U, \
        SM_CFG_Z1(0x00010e50U), \
        SM_CFG_Z1(0x00010e54U), \
        SM_CFG_W1(0x00010f80U), 0x000000C0U, \
        SM_CFG_Z1(0x00011050U), \
        SM_CFG_Z1(0x00011054U), \
        SM_CFG_W1(0x00011064U), 0x09999000U, \
        SM_CFG_W1(0x00011180U), 0x000000C0U, \
        SM_CFG_W1(0x00011240U), 0x99999999U, \
        SM_CFG_W1(0x00011244U), 0x99999999U, \
        SM_CFG_W1(0x00011248U), 0x99999999U, \
        SM_CFG_W1(0x0001124cU), 0x99999999U, \
        SM_CFG_W1(0x00011250U), 0x99009999U, \
        SM_CFG_W1(0x00011254U), 0x99999999U, \
        SM_CFG_W1(0x00011258U), 0x99999999U, \
        SM_CFG_W1(0x0001125cU), 0x99999999U, \
        SM_CFG_W1(0x00011260U), 0x99909999U, \
        SM_CFG_W1(0x00011264U), 0x99999999U, \
        SM_CFG_W1(0x00011268U), 0x99999999U, \
        SM_CFG_W1(0x0001126cU), 0x99999999U, \
        SM_CFG_W1(0x00011270U), 0x99999999U, \
        SM_CFG_W1(0x00011274U), 0x00009999U, \
        SM_CFG_W1(0x00011380U), 0x99999990U, \
        SM_CFG_W1(0x000113a8U), 0x00000009U, \
        SM_CFG_W1(0x000113d0U), 0x00000009U, \
        SM_CFG_Z1(0x00011450U), \
        SM_CFG_Z1(0x00011454U), \
        SM_CFG_W1(0x00011580U), 0x000000C0U, \
        SM_CFG_Z1(0x00011650U), \
        SM_CFG_Z1(0x00011654U), \
        SM_CFG_W1(0x00011780U), 0x000000C0U, \
        SM_CFG_Z1(0x00011850U), \
        SM_CFG_Z1(0x00011854U), \
        SM_CFG_W1(0x00011980U), 0x000000C0U, \
        SM_CFG_Z1(0x00011a50U), \
        SM_CFG_Z1(0x00011a54U), \
        SM_CFG_W1(0x00011b80U), 0x000000C0U, \
        SM_CFG_Z1(0x00011c50U), \
        SM_CFG_Z1(0x00011c54U), \
        SM_CFG_W1(0x00011d80U), 0x000000C0U, \
        SM_CFG_Z1(0x00011e50U), \
        SM_CFG_Z1(0x00011e54U), \
        SM_CFG_W1(0x00011f80U), 0x000000C0U, \
        SM_CFG_W1(0x00012024U), 0x6666U, \
        SM_CFG_W1(0x00012028U), 0x7777U, \
        SM_CFG_W1(0x0001202cU), 0x7700U, \
        SM_CFG_W1(0x00012180U), 0x99999999U, \
        SM_CFG_W1(0x00012184U), 0x99999999U, \
        SM_CFG_W1(0x00012188U), 0x99999999U, \
        SM_CFG_W1(0x0001218cU), 0x99999999U, \
        SM_CFG_Z1(0x00012240U), \
        SM_CFG_Z1(0x00012244U), \
        SM_CFG_Z1(0x00012248U), \
        SM_CFG_Z1(0x0001224cU), \
        SM_CFG_Z1(0x00012380U), \
        SM_CFG_Z1(0x00012384U), \
        SM_CFG_Z1(0x00012388U), \
        SM_CFG_Z1(0x0001238cU), \
        SM_CFG_W1(0x00012440U), 0x33333333U, \
        SM_CFG_W1(0x00012444U), 0x33333333U, \
        SM_CFG_W1(0x00012448U), 0x33333333U, \
        SM_CFG_W1(0x0001244cU), 0x33333333U, \
        SM_CFG_W1(0x00012580U), 0x33333333U, \
        SM_CFG_W1(0x00012584U), 0x33333333U, \
        SM_CFG_W1(0x00012588U), 0x33333333U, \
        SM_CFG_W1(0x0001258cU), 0x33333333U, \
        SM_CFG_Z1(0x00012640U), \
        SM_CFG_Z1(0x00012644U), \
        SM_CFG_Z1(0x00012648U), \
        SM_CFG_Z1(0x0001264cU), \
        SM_CFG_Z1(0x00012780U), \
        SM_CFG_Z1(0x00012784U), \
        SM_CFG_Z1(0x00012788U), \
        SM_CFG_Z1(0x0001278cU), \
        SM_CFG_Z1(0x00012840U), \
        SM_CFG_Z1(0x00012844U), \
        SM_CFG_Z1(0x00012848U), \
        SM_CFG_Z1(0x0001284cU), \
        SM_CFG_Z1(0x00012980U), \
        SM_CFG_Z1(0x00012984U), \
        SM_CFG_Z1(0x00012988U), \
        SM_CFG_Z1(0x0001298cU), \
        SM_CFG_Z1(0x00012a40U), \
        SM_CFG_Z1(0x00012a44U), \
        SM_CFG_Z1(0x00012a48U), \
        SM_CFG_Z1(0x00012a4cU), \
        SM_CFG_Z1(0x00012b80U), \
        SM_CFG_Z1(0x00012b84U), \
        SM_CFG_Z1(0x00012b88U), \
        SM_CFG_Z1(0x00012b8cU), \
        SM_CFG_Z1(0x00012c40U), \
        SM_CFG_Z1(0x00012c44U), \
        SM_CFG_Z1(0x00012c48U), \
        SM_CFG_Z1(0x00012c4cU), \
        SM_CFG_Z1(0x00012d80U), \
        SM_CFG_Z1(0x00012d84U), \
        SM_CFG_Z1(0x00012d88U), \
        SM_CFG_Z1(0x00012d8cU), \
        SM_CFG_Z1(0x00012e40U), \
        SM_CFG_Z1(0x00012e44U), \
        SM_CFG_Z1(0x00012e48U), \
        SM_CFG_Z1(0x00012e4cU), \
        SM_CFG_Z1(0x00012f80U), \
        SM_CFG_Z1(0x00012f84U), \
        SM_CFG_Z1(0x00012f88U), \
        SM_CFG_Z1(0x00012f8cU), \
        SM_CFG_Z1(0x00013040U), \
        SM_CFG_Z1(0x00013044U), \
        SM_CFG_Z1(0x00013048U), \
        SM_CFG_Z1(0x0001304cU), \
        SM_CFG_Z1(0x00013180U), \
        SM_CFG_Z1(0x00013184U), \
        SM_CFG_Z1(0x00013188U), \
        SM_CFG_Z1(0x0001318cU), \
        SM_CFG_W1(0x00013240U), 0x99999999U, \
        SM_CFG_W1(0x00013244U), 0x99999999U, \
        SM_CFG_W1(0x00013248U), 0x99999999U, \
        SM_CFG_W1(0x0001324cU), 0x99999999U, \
        SM_CFG_W1(0x00013380U), 0x99999999U, \
        SM_CFG_W1(0x00013384U), 0x99999999U, \
        SM_CFG_W1(0x00013388U), 0x99999999U, \
        SM_CFG_W1(0x0001338cU), 0x99999999U, \
        SM_CFG_Z1(0x00013440U), \
        SM_CFG_Z1(0x00013444U), \
        SM_CFG_Z1(0x00013448U), \
        SM_CFG_Z1(0x0001344cU), \
        SM_CFG_Z1(0x00013580U), \
        SM_CFG_Z1(0x00013584U), \
        SM_CFG_Z1(0x00013588U), \
        SM_CFG_Z1(0x0001358cU), \
        SM_CFG_Z1(0x00013640U), \
        SM_CFG_Z1(0x00013644U), \
        SM_CFG_Z1(0x00013648U), \
        SM_CFG_Z1(0x0001364cU), \
        SM_CFG_Z1(0x00013780U), \
        SM_CFG_Z1(0x00013784U), \
        SM_CFG_Z1(0x00013788U), \
        SM_CFG_Z1(0x0001378cU), \
        SM_CFG_Z1(0x00013840U), \
        SM_CFG_Z1(0x00013844U), \
        SM_CFG_Z1(0x00013848U), \
        SM_CFG_Z1(0x0001384cU), \
        SM_CFG_Z1(0x00013980U), \
        SM_CFG_Z1(0x00013984U), \
        SM_CFG_Z1(0x00013988U), \
        SM_CFG_Z1(0x0001398cU), \
        SM_CFG_W1(0x00014024U), 0x6666U, \
        SM_CFG_Z1(0x00014240U), \
        SM_CFG_W1(0x00014244U), 0x0003C001U, \
        SM_CFG_Z1(0x0001424cU), \
        SM_CFG_Z1(0x00014254U), \
        SM_CFG_Z1(0x0001425cU), \
        SM_CFG_W1(0x00014940U), 0x00000001U, \
        SM_CFG_W1(0x00014944U), 0x0003C011U, \
        SM_CFG_Z1(0x0001494cU), \
        SM_CFG_Z1(0x00014954U), \
        SM_CFG_Z1(0x0001495cU), \
        SM_CFG_Z1(0x00010020U), \
        SM_CFG_Z1(0x00012020U), \
        SM_CFG_W1(0x00014020U), 0x7700U, \
        SM_CFG_C1(0x00000000U), 0x0000C001U, \
        SM_CFG_END \
    }

/*--------------------------------------------------------------------------*/
/* TRDC C Config                                                            */
/*--------------------------------------------------------------------------*/

/*! Config for TRDC C */
#define SM_TRDC_C_CONFIG \
    { \
        SM_CFG_W1(0x00000800U), 0xA0000053U, \
        SM_CFG_W1(0x00000820U), 0xA0000053U, \
        SM_CFG_W1(0x00000840U), 0xA0000053U, \
        SM_CFG_W1(0x00000860U), 0xA0000053U, \
        SM_CFG_W1(0x00000880U), 0xA0000053U, \
        SM_CFG_W1(0x000008a0U), 0xA0000053U, \
        SM_CFG_W1(0x000008c0U), 0xA0000053U, \
        SM_CFG_W1(0x000008e0U), 0xA0000053U, \
        SM_CFG_W1(0x00000900U), 0xA0000053U, \
        SM_CFG_W1(0x00000920U), 0xA0000053U, \
        SM_CFG_W1(0x00000940U), 0xA0000053U, \
        SM_CFG_W1(0x00000960U), 0xA0000053U, \
        SM_CFG_W1(0x00000980U), 0xA0000053U, \
        SM_CFG_W1(0x000009a0U), 0xA0000053U, \
        SM_CFG_W1(0x000009c0U), 0xA0000053U, \
        SM_CFG_W1(0x000009e0U), 0xA0000053U, \
        SM_CFG_W1(0x00000a00U), 0xA0000053U, \
        SM_CFG_W1(0x00000a20U), 0xA0000053U, \
        SM_CFG_W1(0x00000a40U), 0xA0000053U, \
        SM_CFG_W1(0x00000a60U), 0xA0000053U, \
        SM_CFG_W1(0x00000a80U), 0xA0000053U, \
        SM_CFG_W1(0x00000aa0U), 0xA0000053U, \
        SM_CFG_W1(0x00000ac0U), 0xA0000053U, \
        SM_CFG_W1(0x00000ae0U), 0xA0000053U, \
        SM_CFG_W1(0x00000b00U), 0xA0000053U, \
        SM_CFG_W1(0x00000b20U), 0xA0000053U, \
        SM_CFG_W1(0x00010024U), 0x6666U, \
        SM_CFG_W1(0x00010028U), 0x7777U, \
        SM_CFG_W1(0x0001002cU), 0x6600U, \
        SM_CFG_W1(0x00010040U), 0x00003000U, \
        SM_CFG_W1(0x00010240U), 0x00000900U, \
        SM_CFG_W1(0x00010440U), 0x00330000U, \
        SM_CFG_W1(0x00010640U), 0x99000090U, \
        SM_CFG_W1(0x00010644U), 0x09999999U, \
        SM_CFG_W1(0x00010648U), 0x99999900U, \
        SM_CFG_W1(0x0001064cU), 0x09999999U, \
        SM_CFG_W1(0x00010650U), 0x99999999U, \
        SM_CFG_W1(0x00010654U), 0x99999999U, \
        SM_CFG_W1(0x00010658U), 0x00000999U, \
        SM_CFG_Z1(0x00010840U), \
        SM_CFG_Z1(0x00010a40U), \
        SM_CFG_Z1(0x00010c40U), \
        SM_CFG_Z1(0x00010e40U), \
        SM_CFG_W1(0x00011040U), 0x00000009U, \
        SM_CFG_W1(0x00011240U), 0x99999999U, \
        SM_CFG_W1(0x00011244U), 0x09999999U, \
        SM_CFG_W1(0x00011248U), 0x99999900U, \
        SM_CFG_W1(0x0001124cU), 0x09999999U, \
        SM_CFG_W1(0x00011250U), 0x99999999U, \
        SM_CFG_W1(0x00011254U), 0x99999999U, \
        SM_CFG_W1(0x00011258U), 0x00000999U, \
        SM_CFG_Z1(0x00011440U), \
        SM_CFG_Z1(0x00011640U), \
        SM_CFG_Z1(0x00011840U), \
        SM_CFG_Z1(0x00011a40U), \
        SM_CFG_Z1(0x00011c40U), \
        SM_CFG_Z1(0x00011e40U), \
        SM_CFG_W1(0x00012024U), 0x6666U, \
        SM_CFG_W1(0x00012028U), 0x7777U, \
        SM_CFG_W1(0x0001202cU), 0x6600U, \
        SM_CFG_W1(0x00012440U), 0x00000003U, \
        SM_CFG_W1(0x00013240U), 0x00000009U, \
        SM_CFG_W1(0x00014024U), 0x6666U, \
        SM_CFG_W1(0x00014028U), 0x7777U, \
        SM_CFG_W1(0x00014640U), 0x00000009U, \
        SM_CFG_W1(0x00015240U), 0x00000009U, \
        SM_CFG_W1(0x00016024U), 0x6666U, \
        SM_CFG_W1(0x00016340U), 0x01000000U, \
        SM_CFG_W1(0x00016344U), 0x01014011U, \
        SM_CFG_Z1(0x0001634cU), \
        SM_CFG_W1(0x00016940U), 0x01000001U, \
        SM_CFG_W1(0x00016944U), 0x01014011U, \
        SM_CFG_Z1(0x0001694cU), \
        SM_CFG_Z1(0x00010020U), \
        SM_CFG_Z1(0x00012020U), \
        SM_CFG_Z1(0x00014020U), \
        SM_CFG_W1(0x00016020U), 0x7777U, \
        SM_CFG_C1(0x00000000U), 0x0000C001U, \
        SM_CFG_END \
    }

/*--------------------------------------------------------------------------*/
/* TRDC D Config                                                            */
/*--------------------------------------------------------------------------*/

/*! Config for TRDC D */
#define SM_TRDC_D_CONFIG \
    { \
        SM_CFG_W1(0x00000800U), 0xA0000053U, \
        SM_CFG_W1(0x00000820U), 0xA0000053U, \
        SM_CFG_W1(0x00000840U), 0xA0000053U, \
        SM_CFG_W1(0x00000860U), 0xA0000053U, \
        SM_CFG_W1(0x00000880U), 0xA0000053U, \
        SM_CFG_W1(0x000008a0U), 0xA0000053U, \
        SM_CFG_W1(0x000008c0U), 0xA0000053U, \
        SM_CFG_W1(0x000008e0U), 0xA0000053U, \
        SM_CFG_W1(0x00010024U), 0x6666U, \
        SM_CFG_W1(0x00010028U), 0x7777U, \
        SM_CFG_W1(0x0001002cU), 0x6600U, \
        SM_CFG_W1(0x00010040U), 0x00003000U, \
        SM_CFG_W1(0x00010240U), 0x00000900U, \
        SM_CFG_W1(0x00010440U), 0x00330000U, \
        SM_CFG_W1(0x00010454U), 0x33333000U, \
        SM_CFG_W1(0x0001045cU), 0x30000000U, \
        SM_CFG_W1(0x00010640U), 0x99000090U, \
        SM_CFG_W1(0x00010644U), 0x99999999U, \
        SM_CFG_W1(0x00010648U), 0x00099999U, \
        SM_CFG_W1(0x00010654U), 0x00000900U, \
        SM_CFG_W1(0x00010658U), 0x00000009U, \
        SM_CFG_W1(0x00010780U), 0x99999999U, \
        SM_CFG_W1(0x00010784U), 0x99999999U, \
        SM_CFG_W1(0x00010788U), 0x99999999U, \
        SM_CFG_W1(0x0001078cU), 0x99999999U, \
        SM_CFG_W1(0x00010790U), 0x99999999U, \
        SM_CFG_W1(0x00010794U), 0x99999999U, \
        SM_CFG_W1(0x00010798U), 0x99999999U, \
        SM_CFG_W1(0x0001079cU), 0x99990999U, \
        SM_CFG_W1(0x000107a8U), 0x00000009U, \
        SM_CFG_Z1(0x00010840U), \
        SM_CFG_Z1(0x00010a40U), \
        SM_CFG_Z1(0x00010c40U), \
        SM_CFG_Z1(0x00010e40U), \
        SM_CFG_W1(0x00011040U), 0x00000009U, \
        SM_CFG_W1(0x00011240U), 0x99999999U, \
        SM_CFG_W1(0x00011244U), 0x99999999U, \
        SM_CFG_W1(0x00011248U), 0x00099999U, \
        SM_CFG_W1(0x00011254U), 0x99999900U, \
        SM_CFG_W1(0x00011258U), 0x00000009U, \
        SM_CFG_W1(0x0001125cU), 0x90000000U, \
        SM_CFG_W1(0x00011380U), 0x99999999U, \
        SM_CFG_W1(0x00011384U), 0x99999999U, \
        SM_CFG_W1(0x00011388U), 0x99999999U, \
        SM_CFG_W1(0x0001138cU), 0x99999999U, \
        SM_CFG_W1(0x00011390U), 0x99999999U, \
        SM_CFG_W1(0x00011394U), 0x99999999U, \
        SM_CFG_W1(0x00011398U), 0x99999999U, \
        SM_CFG_W1(0x0001139cU), 0x99990999U, \
        SM_CFG_W1(0x000113a8U), 0x00000009U, \
        SM_CFG_Z1(0x00011440U), \
        SM_CFG_Z1(0x00011640U), \
        SM_CFG_Z1(0x00011840U), \
        SM_CFG_Z1(0x00011a40U), \
        SM_CFG_Z1(0x00011c40U), \
        SM_CFG_Z1(0x00011e40U), \
        SM_CFG_W1(0x00012024U), 0x6666U, \
        SM_CFG_W1(0x00012028U), 0x7777U, \
        SM_CFG_W1(0x0001202cU), 0x6600U, \
        SM_CFG_W1(0x00012440U), 0x00000003U, \
        SM_CFG_W1(0x00012580U), 0x00000003U, \
        SM_CFG_W1(0x00013240U), 0x00000009U, \
        SM_CFG_W1(0x00013380U), 0x00000009U, \
        SM_CFG_W1(0x00014024U), 0x6666U, \
        SM_CFG_W1(0x00014340U), 0x01000000U, \
        SM_CFG_W1(0x00014344U), 0x01008011U, \
        SM_CFG_Z1(0x0001434cU), \
        SM_CFG_W1(0x00014940U), 0x01000001U, \
        SM_CFG_W1(0x00014944U), 0x01008011U, \
        SM_CFG_Z1(0x0001494cU), \
        SM_CFG_Z1(0x00010020U), \
        SM_CFG_Z1(0x00012020U), \
        SM_CFG_W1(0x00014020U), 0x7777U, \
        SM_CFG_C1(0x00000000U), 0x0000C001U, \
        SM_CFG_END \
    }

/*--------------------------------------------------------------------------*/
/* TRDC E Config                                                            */
/*--------------------------------------------------------------------------*/

/*! Config for TRDC E */
#define SM_TRDC_E_CONFIG \
    { \
        SM_CFG_W1(0x00000800U), 0xA8000053U, \
        SM_CFG_W1(0x00000820U), 0xA8400053U, \
        SM_CFG_W1(0x00000840U), 0xA8800053U, \
        SM_CFG_W1(0x00000860U), 0xA8C00053U, \
        SM_CFG_W1(0x00000880U), 0xA9000053U, \
        SM_CFG_W1(0x000008a0U), 0xA9400053U, \
        SM_CFG_W1(0x000008c0U), 0xA9800053U, \
        SM_CFG_W1(0x000008e0U), 0xA9C00053U, \
        SM_CFG_W1(0x00010024U), 0x6666U, \
        SM_CFG_W1(0x00010028U), 0x7777U, \
        SM_CFG_W1(0x0001002cU), 0x6600U, \
        SM_CFG_W1(0x000101a8U), 0x00003000U, \
        SM_CFG_W1(0x000103a8U), 0x00000900U, \
        SM_CFG_W1(0x000105a8U), 0x00330000U, \
        SM_CFG_W1(0x00010640U), 0x99999999U, \
        SM_CFG_W1(0x00010644U), 0x99999999U, \
        SM_CFG_W1(0x00010648U), 0x00009999U, \
        SM_CFG_W1(0x00010780U), 0x99999999U, \
        SM_CFG_W1(0x000107a8U), 0x00000090U, \
        SM_CFG_W1(0x000107acU), 0x00009909U, \
        SM_CFG_Z1(0x000109a8U), \
        SM_CFG_Z1(0x00010ba8U), \
        SM_CFG_Z1(0x00010da8U), \
        SM_CFG_Z1(0x00010fa8U), \
        SM_CFG_W1(0x000111a8U), 0x00000009U, \
        SM_CFG_W1(0x00011240U), 0x99999999U, \
        SM_CFG_W1(0x00011244U), 0x99999999U, \
        SM_CFG_W1(0x00011248U), 0x00009999U, \
        SM_CFG_W1(0x00011380U), 0x99999999U, \
        SM_CFG_W1(0x000113a8U), 0x00999999U, \
        SM_CFG_W1(0x000113acU), 0x00009909U, \
        SM_CFG_Z1(0x000115a8U), \
        SM_CFG_Z1(0x000117a8U), \
        SM_CFG_Z1(0x000119a8U), \
        SM_CFG_Z1(0x00011ba8U), \
        SM_CFG_Z1(0x00011da8U), \
        SM_CFG_Z1(0x00011fa8U), \
        SM_CFG_Z1(0x00010020U), \
        SM_CFG_C1(0x00000000U), 0x0000C001U, \
        SM_CFG_END \
    }

/*--------------------------------------------------------------------------*/
/* TRDC G Config                                                            */
/*--------------------------------------------------------------------------*/

/*! Config for TRDC G */
#define SM_TRDC_G_CONFIG \
    { \
        SM_CFG_W1(0x00000800U), 0xA0000053U, \
        SM_CFG_W1(0x00000820U), 0xA0000053U, \
        SM_CFG_W1(0x00010024U), 0x6666U, \
        SM_CFG_W1(0x00010028U), 0x7777U, \
        SM_CFG_W1(0x0001002cU), 0x6600U, \
        SM_CFG_W1(0x00010040U), 0x00003000U, \
        SM_CFG_W1(0x00010240U), 0x00000900U, \
        SM_CFG_W1(0x00010440U), 0x00330030U, \
        SM_CFG_Z1(0x00010640U), \
        SM_CFG_Z1(0x00010840U), \
        SM_CFG_Z1(0x00010a40U), \
        SM_CFG_Z1(0x00010c40U), \
        SM_CFG_Z1(0x00010e40U), \
        SM_CFG_W1(0x00011040U), 0x00000009U, \
        SM_CFG_W1(0x00011240U), 0x00999999U, \
        SM_CFG_Z1(0x00011440U), \
        SM_CFG_Z1(0x00011640U), \
        SM_CFG_Z1(0x00011840U), \
        SM_CFG_Z1(0x00011a40U), \
        SM_CFG_Z1(0x00011c40U), \
        SM_CFG_Z1(0x00011e40U), \
        SM_CFG_W1(0x00012340U), 0x4D900000U, \
        SM_CFG_W1(0x00012344U), 0x4DD7C011U, \
        SM_CFG_Z1(0x0001234cU), \
        SM_CFG_Z1(0x00012354U), \
        SM_CFG_Z1(0x0001235cU), \
        SM_CFG_W1(0x00012940U), 0x4D900000U, \
        SM_CFG_W1(0x00012944U), 0x4DD7C011U, \
        SM_CFG_Z1(0x0001294cU), \
        SM_CFG_Z1(0x00012954U), \
        SM_CFG_Z1(0x0001295cU), \
        SM_CFG_Z1(0x00010020U), \
        SM_CFG_W1(0x00012020U), 0x6666U, \
        SM_CFG_C1(0x00000000U), 0x0000C001U, \
        SM_CFG_END \
    }

/*--------------------------------------------------------------------------*/
/* TRDC H Config                                                            */
/*--------------------------------------------------------------------------*/

/*! Config for TRDC H */
#define SM_TRDC_H_CONFIG \
    { \
        SM_CFG_W1(0x00000800U), 0xA0000053U, \
        SM_CFG_W1(0x00000820U), 0xA0000053U, \
        SM_CFG_W1(0x00000840U), 0xA0000053U, \
        SM_CFG_W1(0x00000860U), 0xA0000053U, \
        SM_CFG_W1(0x00000880U), 0xA0000053U, \
        SM_CFG_W1(0x000008a0U), 0xA0000053U, \
        SM_CFG_W1(0x000008c0U), 0xA0000053U, \
        SM_CFG_W1(0x000008e0U), 0xA0000053U, \
        SM_CFG_W1(0x00000900U), 0xA0000053U, \
        SM_CFG_W1(0x00000920U), 0xA0000053U, \
        SM_CFG_W1(0x00010024U), 0x6666U, \
        SM_CFG_W1(0x00010028U), 0x7777U, \
        SM_CFG_W1(0x0001002cU), 0x6600U, \
        SM_CFG_W1(0x000101a8U), 0x00003000U, \
        SM_CFG_W1(0x000103a8U), 0x00000900U, \
        SM_CFG_W1(0x000105a8U), 0x03330000U, \
        SM_CFG_W1(0x00010640U), 0x99999999U, \
        SM_CFG_W1(0x00010644U), 0x99999999U, \
        SM_CFG_W1(0x00010780U), 0x99999999U, \
        SM_CFG_W1(0x00010784U), 0x99999999U, \
        SM_CFG_W1(0x000107a8U), 0x90000090U, \
        SM_CFG_W1(0x000107d0U), 0x99999999U, \
        SM_CFG_W1(0x000107d4U), 0x99999999U, \
        SM_CFG_W1(0x000107d8U), 0x99999999U, \
        SM_CFG_Z1(0x000109a8U), \
        SM_CFG_Z1(0x00010ba8U), \
        SM_CFG_Z1(0x00010da8U), \
        SM_CFG_Z1(0x00010fa8U), \
        SM_CFG_W1(0x000111a8U), 0x00000009U, \
        SM_CFG_W1(0x00011240U), 0x99999999U, \
        SM_CFG_W1(0x00011244U), 0x99999999U, \
        SM_CFG_W1(0x00011380U), 0x99999999U, \
        SM_CFG_W1(0x00011384U), 0x99999999U, \
        SM_CFG_W1(0x000113a8U), 0x99999999U, \
        SM_CFG_W1(0x000113d0U), 0x99999999U, \
        SM_CFG_W1(0x000113d4U), 0x99999999U, \
        SM_CFG_W1(0x000113d8U), 0x99999999U, \
        SM_CFG_Z1(0x000115a8U), \
        SM_CFG_Z1(0x000117a8U), \
        SM_CFG_Z1(0x000119a8U), \
        SM_CFG_Z1(0x00011ba8U), \
        SM_CFG_Z1(0x00011da8U), \
        SM_CFG_Z1(0x00011fa8U), \
        SM_CFG_W1(0x00012024U), 0x6666U, \
        SM_CFG_W1(0x00012028U), 0x7777U, \
        SM_CFG_W1(0x00012640U), 0x00099999U, \
        SM_CFG_W1(0x00012780U), 0x00099999U, \
        SM_CFG_W1(0x00013240U), 0x00099999U, \
        SM_CFG_W1(0x00013380U), 0x00099999U, \
        SM_CFG_Z1(0x00010020U), \
        SM_CFG_Z1(0x00012020U), \
        SM_CFG_C1(0x00000000U), 0x0000C001U, \
        SM_CFG_END \
    }

/*--------------------------------------------------------------------------*/
/* TRDC N Config                                                            */
/*--------------------------------------------------------------------------*/

/*! Config for TRDC N */
#define SM_TRDC_N_CONFIG \
    { \
        SM_CFG_W1(0x00000800U), 0x80008003U, \
        SM_CFG_W1(0x00000804U), 0x80008003U, \
        SM_CFG_W1(0x00000808U), 0x80008003U, \
        SM_CFG_W1(0x0000080cU), 0x80008003U, \
        SM_CFG_W1(0x00000820U), 0x80008003U, \
        SM_CFG_W1(0x00000824U), 0x80008003U, \
        SM_CFG_W1(0x00000828U), 0x80008003U, \
        SM_CFG_W1(0x0000082cU), 0x80008003U, \
        SM_CFG_W1(0x00000840U), 0x80008003U, \
        SM_CFG_W1(0x00000844U), 0x80008003U, \
        SM_CFG_W1(0x00000848U), 0x80008003U, \
        SM_CFG_W1(0x0000084cU), 0x80008003U, \
        SM_CFG_W1(0x00000860U), 0x80008003U, \
        SM_CFG_W1(0x00000864U), 0x80008003U, \
        SM_CFG_W1(0x00000868U), 0x80008003U, \
        SM_CFG_W1(0x0000086cU), 0x80008003U, \
        SM_CFG_W1(0x00000880U), 0xA0000053U, \
        SM_CFG_W1(0x000008a0U), 0xA0000053U, \
        SM_CFG_W1(0x000008c0U), 0x80000004U, \
        SM_CFG_W1(0x00010024U), 0x6666U, \
        SM_CFG_W1(0x00010028U), 0x7777U, \
        SM_CFG_W1(0x0001002cU), 0x6600U, \
        SM_CFG_W1(0x00010040U), 0x00300000U, \
        SM_CFG_W1(0x00010180U), 0x00300000U, \
        SM_CFG_W1(0x000101a8U), 0x00003000U, \
        SM_CFG_W1(0x000101d0U), 0x00003000U, \
        SM_CFG_W1(0x00010240U), 0x00009000U, \
        SM_CFG_W1(0x00010380U), 0x00009000U, \
        SM_CFG_W1(0x000103a8U), 0x00000900U, \
        SM_CFG_W1(0x000103d0U), 0x00000900U, \
        SM_CFG_W1(0x00010440U), 0x33000333U, \
        SM_CFG_W1(0x00010444U), 0x00003303U, \
        SM_CFG_W1(0x00010450U), 0x30000000U, \
        SM_CFG_W1(0x00010580U), 0x33000333U, \
        SM_CFG_W1(0x00010584U), 0x00003303U, \
        SM_CFG_W1(0x00010590U), 0x30000000U, \
        SM_CFG_W1(0x000105a8U), 0x00030030U, \
        SM_CFG_W1(0x000105d0U), 0x00030030U, \
        SM_CFG_Z1(0x00010640U), \
        SM_CFG_Z1(0x00010780U), \
        SM_CFG_Z1(0x00010840U), \
        SM_CFG_W1(0x00010844U), 0x00090000U, \
        SM_CFG_Z1(0x00010980U), \
        SM_CFG_W1(0x00010984U), 0x00090000U, \
        SM_CFG_Z1(0x00010a40U), \
        SM_CFG_Z1(0x00010b80U), \
        SM_CFG_Z1(0x00010c40U), \
        SM_CFG_Z1(0x00010d80U), \
        SM_CFG_Z1(0x00010e40U), \
        SM_CFG_Z1(0x00010f80U), \
        SM_CFG_W1(0x00011040U), 0x00090000U, \
        SM_CFG_W1(0x00011180U), 0x00090000U, \
        SM_CFG_W1(0x000111a8U), 0x00000009U, \
        SM_CFG_W1(0x000111d0U), 0x00000009U, \
        SM_CFG_W1(0x00011240U), 0x99999999U, \
        SM_CFG_W1(0x00011244U), 0x00099909U, \
        SM_CFG_W1(0x00011250U), 0x90000000U, \
        SM_CFG_W1(0x00011380U), 0x99999999U, \
        SM_CFG_W1(0x00011384U), 0x00099909U, \
        SM_CFG_W1(0x00011390U), 0x90000000U, \
        SM_CFG_W1(0x000113a8U), 0x00099999U, \
        SM_CFG_W1(0x000113d0U), 0x00099999U, \
        SM_CFG_Z1(0x00011440U), \
        SM_CFG_Z1(0x00011580U), \
        SM_CFG_Z1(0x00011640U), \
        SM_CFG_Z1(0x00011780U), \
        SM_CFG_Z1(0x00011840U), \
        SM_CFG_Z1(0x00011980U), \
        SM_CFG_Z1(0x00011a40U), \
        SM_CFG_Z1(0x00011b80U), \
        SM_CFG_Z1(0x00011c40U), \
        SM_CFG_Z1(0x00011d80U), \
        SM_CFG_Z1(0x00011e40U), \
        SM_CFG_Z1(0x00011f80U), \
        SM_CFG_W1(0x00012024U), 0x6666U, \
        SM_CFG_W1(0x00012028U), 0x7777U, \
        SM_CFG_W1(0x0001202cU), 0x6600U, \
        SM_CFG_W1(0x00012440U), 0x33333333U, \
        SM_CFG_W1(0x00012444U), 0x03333333U, \
        SM_CFG_W1(0x00012580U), 0x33333333U, \
        SM_CFG_W1(0x00012584U), 0x03333333U, \
        SM_CFG_W1(0x00012640U), 0x99999999U, \
        SM_CFG_W1(0x00012644U), 0x09999999U, \
        SM_CFG_W1(0x00012780U), 0x99999999U, \
        SM_CFG_W1(0x00012784U), 0x09999999U, \
        SM_CFG_W1(0x00013240U), 0x99999999U, \
        SM_CFG_W1(0x00013244U), 0x09999999U, \
        SM_CFG_W1(0x00013380U), 0x99999999U, \
        SM_CFG_W1(0x00013384U), 0x09999999U, \
        SM_CFG_W1(0x00014024U), 0x6666U, \
        SM_CFG_W1(0x00014028U), 0x7777U, \
        SM_CFG_W1(0x0001402cU), 0x7700U, \
        SM_CFG_W1(0x00014040U), 0x99999999U, \
        SM_CFG_W1(0x00014044U), 0x99999999U, \
        SM_CFG_W1(0x00014048U), 0x00999999U, \
        SM_CFG_W1(0x00014180U), 0x99999999U, \
        SM_CFG_W1(0x00014184U), 0x99999999U, \
        SM_CFG_W1(0x00014188U), 0x00999999U, \
        SM_CFG_Z1(0x00014440U), \
        SM_CFG_Z1(0x00014444U), \
        SM_CFG_Z1(0x00014448U), \
        SM_CFG_Z1(0x00014580U), \
        SM_CFG_Z1(0x00014584U), \
        SM_CFG_Z1(0x00014588U), \
        SM_CFG_W1(0x00014640U), 0x33333333U, \
        SM_CFG_W1(0x00014644U), 0x33333333U, \
        SM_CFG_W1(0x00014648U), 0x00AAAAAAU, \
        SM_CFG_W1(0x00014780U), 0x33333333U, \
        SM_CFG_W1(0x00014784U), 0x33333333U, \
        SM_CFG_W1(0x00014788U), 0x00AAAAAAU, \
        SM_CFG_W1(0x000147a8U), 0x99999999U, \
        SM_CFG_W1(0x000147acU), 0x00000009U, \
        SM_CFG_W1(0x000147d0U), 0x99999999U, \
        SM_CFG_W1(0x000147d4U), 0x00000009U, \
        SM_CFG_Z1(0x00014840U), \
        SM_CFG_Z1(0x00014844U), \
        SM_CFG_Z1(0x00014848U), \
        SM_CFG_Z1(0x00014980U), \
        SM_CFG_Z1(0x00014984U), \
        SM_CFG_Z1(0x00014988U), \
        SM_CFG_Z1(0x00014a40U), \
        SM_CFG_Z1(0x00014a44U), \
        SM_CFG_Z1(0x00014a48U), \
        SM_CFG_Z1(0x00014b80U), \
        SM_CFG_Z1(0x00014b84U), \
        SM_CFG_Z1(0x00014b88U), \
        SM_CFG_Z1(0x00014c40U), \
        SM_CFG_Z1(0x00014c44U), \
        SM_CFG_Z1(0x00014c48U), \
        SM_CFG_Z1(0x00014d80U), \
        SM_CFG_Z1(0x00014d84U), \
        SM_CFG_Z1(0x00014d88U), \
        SM_CFG_Z1(0x00014e40U), \
        SM_CFG_Z1(0x00014e44U), \
        SM_CFG_Z1(0x00014e48U), \
        SM_CFG_Z1(0x00014f80U), \
        SM_CFG_Z1(0x00014f84U), \
        SM_CFG_Z1(0x00014f88U), \
        SM_CFG_W1(0x00015240U), 0x99999999U, \
        SM_CFG_W1(0x00015244U), 0x99999999U, \
        SM_CFG_W1(0x00015248U), 0x00999999U, \
        SM_CFG_W1(0x00015380U), 0x99999999U, \
        SM_CFG_W1(0x00015384U), 0x99999999U, \
        SM_CFG_W1(0x00015388U), 0x00999999U, \
        SM_CFG_W1(0x000153a8U), 0x99999999U, \
        SM_CFG_W1(0x000153acU), 0x00000009U, \
        SM_CFG_W1(0x000153d0U), 0x99999999U, \
        SM_CFG_W1(0x000153d4U), 0x00000009U, \
        SM_CFG_Z1(0x00015440U), \
        SM_CFG_Z1(0x00015444U), \
        SM_CFG_Z1(0x00015448U), \
        SM_CFG_Z1(0x00015580U), \
        SM_CFG_Z1(0x00015584U), \
        SM_CFG_Z1(0x00015588U), \
        SM_CFG_Z1(0x00015640U), \
        SM_CFG_Z1(0x00015644U), \
        SM_CFG_Z1(0x00015648U), \
        SM_CFG_Z1(0x00015780U), \
        SM_CFG_Z1(0x00015784U), \
        SM_CFG_Z1(0x00015788U), \
        SM_CFG_W1(0x00016024U), 0x6666U, \
        SM_CFG_W1(0x00016028U), 0x7777U, \
        SM_CFG_W1(0x0001602cU), 0x6600U, \
        SM_CFG_W1(0x000161a8U), 0x00003000U, \
        SM_CFG_W1(0x000161d0U), 0x00003000U, \
        SM_CFG_W1(0x00016240U), 0x00000900U, \
        SM_CFG_W1(0x00016380U), 0x00000900U, \
        SM_CFG_W1(0x000163a8U), 0x00000900U, \
        SM_CFG_W1(0x000163d0U), 0x00000900U, \
        SM_CFG_W1(0x00016440U), 0x33300030U, \
        SM_CFG_W1(0x00016444U), 0x00000033U, \
        SM_CFG_W1(0x00016580U), 0x33300030U, \
        SM_CFG_W1(0x00016584U), 0x00000033U, \
        SM_CFG_W1(0x000165a8U), 0x33300000U, \
        SM_CFG_W1(0x000165d0U), 0x33300000U, \
        SM_CFG_W1(0x00016644U), 0x00000090U, \
        SM_CFG_W1(0x00016784U), 0x00000090U, \
        SM_CFG_W1(0x000167a8U), 0x00000090U, \
        SM_CFG_W1(0x000167d0U), 0x00000090U, \
        SM_CFG_W1(0x00017040U), 0x00000009U, \
        SM_CFG_W1(0x00017180U), 0x00000009U, \
        SM_CFG_W1(0x000171a8U), 0x00000009U, \
        SM_CFG_W1(0x000171d0U), 0x00000009U, \
        SM_CFG_W1(0x00017240U), 0x99900999U, \
        SM_CFG_W1(0x00017244U), 0x00000099U, \
        SM_CFG_W1(0x00017380U), 0x99900999U, \
        SM_CFG_W1(0x00017384U), 0x00000099U, \
        SM_CFG_W1(0x000173a8U), 0x99909999U, \
        SM_CFG_W1(0x000173d0U), 0x99909999U, \
        SM_CFG_W1(0x00018024U), 0x6666U, \
        SM_CFG_W1(0x00018028U), 0x7777U, \
        SM_CFG_W1(0x0001802cU), 0x6600U, \
        SM_CFG_W1(0x00018440U), 0x33333333U, \
        SM_CFG_W1(0x00018580U), 0x33333333U, \
        SM_CFG_W1(0x00019240U), 0x99999999U, \
        SM_CFG_W1(0x00019380U), 0x99999999U, \
        SM_CFG_W1(0x0001a024U), 0x4444U, \
        SM_CFG_W1(0x0001a028U), 0x7777U, \
        SM_CFG_W1(0x0001a02cU), 0x7700U, \
        SM_CFG_W1(0x0001a040U), 0x08000000U, \
        SM_CFG_W1(0x0001a044U), 0x87FFFC11U, \
        SM_CFG_Z1(0x0001a04cU), \
        SM_CFG_Z1(0x0001a054U), \
        SM_CFG_Z1(0x0001a05cU), \
        SM_CFG_Z1(0x0001a244U), \
        SM_CFG_Z1(0x0001a24cU), \
        SM_CFG_Z1(0x0001a254U), \
        SM_CFG_Z1(0x0001a25cU), \
        SM_CFG_W1(0x0001a340U), 0x08800002U, \
        SM_CFG_W1(0x0001a344U), 0x089FFC11U, \
        SM_CFG_W1(0x0001a348U), 0x08A00003U, \
        SM_CFG_W1(0x0001a34cU), 0x08DFFC01U, \
        SM_CFG_W1(0x0001a350U), 0x08E00002U, \
        SM_CFG_W1(0x0001a354U), 0x87FFFC11U, \
        SM_CFG_Z1(0x0001a35cU), \
        SM_CFG_W1(0x0001a440U), 0x08000002U, \
        SM_CFG_W1(0x0001a444U), 0x089FFC11U, \
        SM_CFG_Z1(0x0001a44cU), \
        SM_CFG_Z1(0x0001a454U), \
        SM_CFG_Z1(0x0001a45cU), \
        SM_CFG_Z1(0x0001a544U), \
        SM_CFG_Z1(0x0001a54cU), \
        SM_CFG_Z1(0x0001a554U), \
        SM_CFG_Z1(0x0001a55cU), \
        SM_CFG_Z1(0x0001a644U), \
        SM_CFG_Z1(0x0001a64cU), \
        SM_CFG_Z1(0x0001a654U), \
        SM_CFG_Z1(0x0001a65cU), \
        SM_CFG_Z1(0x0001a744U), \
        SM_CFG_Z1(0x0001a74cU), \
        SM_CFG_Z1(0x0001a754U), \
        SM_CFG_Z1(0x0001a75cU), \
        SM_CFG_Z1(0x0001a844U), \
        SM_CFG_Z1(0x0001a84cU), \
        SM_CFG_Z1(0x0001a854U), \
        SM_CFG_Z1(0x0001a85cU), \
        SM_CFG_W1(0x0001a940U), 0x08000000U, \
        SM_CFG_W1(0x0001a944U), 0x089FFC11U, \
        SM_CFG_W1(0x0001a948U), 0x08800000U, \
        SM_CFG_W1(0x0001a94cU), 0x089FFC11U, \
        SM_CFG_W1(0x0001a950U), 0x08A00000U, \
        SM_CFG_W1(0x0001a954U), 0x08DFFC11U, \
        SM_CFG_W1(0x0001a958U), 0x08E00000U, \
        SM_CFG_W1(0x0001a95cU), 0x87FFFC11U, \
        SM_CFG_Z1(0x0001aa44U), \
        SM_CFG_Z1(0x0001aa4cU), \
        SM_CFG_Z1(0x0001aa54U), \
        SM_CFG_Z1(0x0001aa5cU), \
        SM_CFG_Z1(0x0001ab44U), \
        SM_CFG_Z1(0x0001ab4cU), \
        SM_CFG_Z1(0x0001ab54U), \
        SM_CFG_Z1(0x0001ab5cU), \
        SM_CFG_W1(0x0001ac40U), 0x08000001U, \
        SM_CFG_W1(0x0001ac44U), 0x08AFFC11U, \
        SM_CFG_W1(0x0001ac48U), 0x08B00000U, \
        SM_CFG_W1(0x0001ac4cU), 0x08BFFC11U, \
        SM_CFG_W1(0x0001ac50U), 0x08C00001U, \
        SM_CFG_W1(0x0001ac54U), 0x87FFFC11U, \
        SM_CFG_Z1(0x0001ac5cU), \
        SM_CFG_Z1(0x00010020U), \
        SM_CFG_Z1(0x00012020U), \
        SM_CFG_Z1(0x00014020U), \
        SM_CFG_Z1(0x00016020U), \
        SM_CFG_Z1(0x00018020U), \
        SM_CFG_W1(0x0001a020U), 0x6666U, \
        SM_CFG_C1(0x00000000U), 0x0000C001U, \
        SM_CFG_END \
    }

/*--------------------------------------------------------------------------*/
/* TRDC V Config                                                            */
/*--------------------------------------------------------------------------*/

/*! Config for TRDC V */
#define SM_TRDC_V_CONFIG \
    { \
        SM_CFG_W1(0x00000800U), 0xA0000053U, \
        SM_CFG_W1(0x00000820U), 0xA0000053U, \
        SM_CFG_W1(0x00000840U), 0xA0000053U, \
        SM_CFG_W1(0x00000860U), 0xA0000053U, \
        SM_CFG_W1(0x00000880U), 0xA0000053U, \
        SM_CFG_W1(0x000008a0U), 0xA0000053U, \
        SM_CFG_W1(0x000008c0U), 0xA0000053U, \
        SM_CFG_W1(0x000008e0U), 0xA0000053U, \
        SM_CFG_W1(0x00000900U), 0xA0000053U, \
        SM_CFG_W1(0x00000920U), 0xA0000053U, \
        SM_CFG_W1(0x00000940U), 0xA0000053U, \
        SM_CFG_W1(0x00000960U), 0xA0000053U, \
        SM_CFG_W1(0x00000980U), 0xA0000053U, \
        SM_CFG_W1(0x000009a0U), 0xA0000053U, \
        SM_CFG_W1(0x000009c0U), 0xA0000053U, \
        SM_CFG_W1(0x00010024U), 0x6666U, \
        SM_CFG_W1(0x00010028U), 0x7777U, \
        SM_CFG_W1(0x0001002cU), 0x6600U, \
        SM_CFG_W1(0x00010040U), 0x00003000U, \
        SM_CFG_W1(0x00010180U), 0x00003000U, \
        SM_CFG_W1(0x00010240U), 0x00000900U, \
        SM_CFG_W1(0x00010380U), 0x00000900U, \
        SM_CFG_W1(0x00010440U), 0x00330000U, \
        SM_CFG_W1(0x00010450U), 0x00000003U, \
        SM_CFG_W1(0x00010580U), 0x00330000U, \
        SM_CFG_W1(0x00010590U), 0x00000003U, \
        SM_CFG_W1(0x00010640U), 0x99000090U, \
        SM_CFG_W1(0x00010644U), 0x99999999U, \
        SM_CFG_W1(0x00010648U), 0x99999999U, \
        SM_CFG_W1(0x0001064cU), 0x00000099U, \
        SM_CFG_W1(0x00010650U), 0x00099990U, \
        SM_CFG_W1(0x00010780U), 0x99000090U, \
        SM_CFG_W1(0x00010784U), 0x99999999U, \
        SM_CFG_W1(0x00010788U), 0x99999999U, \
        SM_CFG_W1(0x0001078cU), 0x00000099U, \
        SM_CFG_W1(0x00010790U), 0x00099990U, \
        SM_CFG_Z1(0x00010840U), \
        SM_CFG_Z1(0x00010980U), \
        SM_CFG_Z1(0x00010a40U), \
        SM_CFG_Z1(0x00010b80U), \
        SM_CFG_Z1(0x00010c40U), \
        SM_CFG_Z1(0x00010d80U), \
        SM_CFG_Z1(0x00010e40U), \
        SM_CFG_Z1(0x00010f80U), \
        SM_CFG_W1(0x00011040U), 0x00000009U, \
        SM_CFG_W1(0x00011180U), 0x00000009U, \
        SM_CFG_W1(0x00011240U), 0x99999999U, \
        SM_CFG_W1(0x00011244U), 0x99999999U, \
        SM_CFG_W1(0x00011248U), 0x99999999U, \
        SM_CFG_W1(0x0001124cU), 0x00000099U, \
        SM_CFG_W1(0x00011250U), 0x00099999U, \
        SM_CFG_W1(0x00011380U), 0x99999999U, \
        SM_CFG_W1(0x00011384U), 0x99999999U, \
        SM_CFG_W1(0x00011388U), 0x99999999U, \
        SM_CFG_W1(0x0001138cU), 0x00000099U, \
        SM_CFG_W1(0x00011390U), 0x00099999U, \
        SM_CFG_Z1(0x00011440U), \
        SM_CFG_Z1(0x00011580U), \
        SM_CFG_Z1(0x00011640U), \
        SM_CFG_Z1(0x00011780U), \
        SM_CFG_Z1(0x00011840U), \
        SM_CFG_Z1(0x00011980U), \
        SM_CFG_Z1(0x00011a40U), \
        SM_CFG_Z1(0x00011b80U), \
        SM_CFG_Z1(0x00011c40U), \
        SM_CFG_Z1(0x00011d80U), \
        SM_CFG_Z1(0x00011e40U), \
        SM_CFG_Z1(0x00011f80U), \
        SM_CFG_Z1(0x00010020U), \
        SM_CFG_C1(0x00000000U), 0x0000C001U, \
        SM_CFG_END \
    }

/*--------------------------------------------------------------------------*/
/* TRDC W Config                                                            */
/*--------------------------------------------------------------------------*/

/*! Config for TRDC W */
#define SM_TRDC_W_CONFIG \
    { \
        SM_CFG_W1(0x00000800U), 0x80000004U, \
        SM_CFG_W1(0x00000820U), 0xA0000053U, \
        SM_CFG_W1(0x00000840U), 0xA0000053U, \
        SM_CFG_W1(0x00000860U), 0xA0000053U, \
        SM_CFG_W1(0x00000880U), 0xA0000053U, \
        SM_CFG_W1(0x000008a0U), 0xA0000053U, \
        SM_CFG_W1(0x000008c0U), 0xA0000053U, \
        SM_CFG_W1(0x000008e0U), 0xA0000053U, \
        SM_CFG_W1(0x00000900U), 0xA0000053U, \
        SM_CFG_W1(0x00000920U), 0xA0000053U, \
        SM_CFG_W1(0x00000940U), 0xA0000053U, \
        SM_CFG_W1(0x00000960U), 0xA0000053U, \
        SM_CFG_W1(0x00000980U), 0xA0000053U, \
        SM_CFG_W1(0x000009a0U), 0xA0000053U, \
        SM_CFG_W1(0x000009c0U), 0xA0000053U, \
        SM_CFG_W1(0x000009e0U), 0xA0000053U, \
        SM_CFG_W1(0x00000a00U), 0xA0000053U, \
        SM_CFG_W1(0x00000a20U), 0xA0000053U, \
        SM_CFG_W1(0x00000a40U), 0xA0000053U, \
        SM_CFG_W1(0x00000a60U), 0xA0000053U, \
        SM_CFG_W1(0x00000a80U), 0xA0000053U, \
        SM_CFG_W1(0x00000aa0U), 0xA0000053U, \
        SM_CFG_W1(0x00000ac0U), 0xA0000053U, \
        SM_CFG_W1(0x00000ae0U), 0xA0000053U, \
        SM_CFG_W1(0x00000b00U), 0xA0000053U, \
        SM_CFG_W1(0x00000b20U), 0xA0000053U, \
        SM_CFG_W1(0x00000b40U), 0xA0000053U, \
        SM_CFG_W1(0x00000b60U), 0xA0000053U, \
        SM_CFG_W1(0x00000b80U), 0xA0000053U, \
        SM_CFG_W1(0x00000ba0U), 0xA0000053U, \
        SM_CFG_W1(0x00000bc0U), 0xA0000053U, \
        SM_CFG_W1(0x00000be0U), 0xA0000053U, \
        SM_CFG_W1(0x00000c00U), 0xA0000053U, \
        SM_CFG_W1(0x00000c20U), 0xA0000053U, \
        SM_CFG_W1(0x00000c40U), 0xA0000053U, \
        SM_CFG_W1(0x00010024U), 0x6666U, \
        SM_CFG_W1(0x00010028U), 0x7777U, \
        SM_CFG_W1(0x0001002cU), 0x6600U, \
        SM_CFG_Z1(0x00010044U), \
        SM_CFG_Z1(0x00010064U), \
        SM_CFG_W1(0x00010070U), 0x00003000U, \
        SM_CFG_W1(0x000101a8U), 0x00000003U, \
        SM_CFG_Z1(0x00010244U), \
        SM_CFG_W1(0x00010250U), 0x00009000U, \
        SM_CFG_Z1(0x00010264U), \
        SM_CFG_W1(0x00010440U), 0x00033000U, \
        SM_CFG_W1(0x00010444U), 0x00000033U, \
        SM_CFG_W1(0x00010458U), 0x30000000U, \
        SM_CFG_W1(0x0001045cU), 0x00333300U, \
        SM_CFG_W1(0x00010464U), 0x00030000U, \
        SM_CFG_W1(0x000105d0U), 0x33333333U, \
        SM_CFG_W1(0x000105d4U), 0x33333333U, \
        SM_CFG_W1(0x000105d8U), 0x00000003U, \
        SM_CFG_W1(0x00010640U), 0x90900000U, \
        SM_CFG_W1(0x00010644U), 0x09099000U, \
        SM_CFG_W1(0x00010648U), 0x99999999U, \
        SM_CFG_W1(0x0001064cU), 0x99999909U, \
        SM_CFG_W1(0x00010650U), 0x00000900U, \
        SM_CFG_W1(0x00010654U), 0x99999000U, \
        SM_CFG_W1(0x00010658U), 0x00999999U, \
        SM_CFG_W1(0x00010660U), 0x00099999U, \
        SM_CFG_Z1(0x00010664U), \
        SM_CFG_W1(0x00010780U), 0x00000009U, \
        SM_CFG_W1(0x00010840U), 0x09000000U, \
        SM_CFG_W1(0x00010844U), 0x90900900U, \
        SM_CFG_W1(0x0001084cU), 0x00000090U, \
        SM_CFG_W1(0x00010858U), 0x09000000U, \
        SM_CFG_W1(0x00010864U), 0x90000000U, \
        SM_CFG_Z1(0x00010a44U), \
        SM_CFG_Z1(0x00010a64U), \
        SM_CFG_Z1(0x00010c44U), \
        SM_CFG_Z1(0x00010c64U), \
        SM_CFG_Z1(0x00010e44U), \
        SM_CFG_Z1(0x00010e64U), \
        SM_CFG_Z1(0x00011044U), \
        SM_CFG_W1(0x00011050U), 0x00090000U, \
        SM_CFG_Z1(0x00011064U), \
        SM_CFG_W1(0x00011240U), 0x99999000U, \
        SM_CFG_W1(0x00011244U), 0x99999999U, \
        SM_CFG_W1(0x00011248U), 0x99999999U, \
        SM_CFG_W1(0x0001124cU), 0x99999999U, \
        SM_CFG_W1(0x00011250U), 0x00099900U, \
        SM_CFG_W1(0x00011254U), 0x99999000U, \
        SM_CFG_W1(0x00011258U), 0x99999999U, \
        SM_CFG_W1(0x0001125cU), 0x00999900U, \
        SM_CFG_W1(0x00011260U), 0x00099999U, \
        SM_CFG_W1(0x00011264U), 0x90090000U, \
        SM_CFG_W1(0x00011270U), 0x00009000U, \
        SM_CFG_W1(0x00011380U), 0x00000009U, \
        SM_CFG_W1(0x000113a8U), 0x00000009U, \
        SM_CFG_W1(0x000113d0U), 0x99999999U, \
        SM_CFG_W1(0x000113d4U), 0x99999999U, \
        SM_CFG_W1(0x000113d8U), 0x00000009U, \
        SM_CFG_Z1(0x00011444U), \
        SM_CFG_Z1(0x00011464U), \
        SM_CFG_Z1(0x00011644U), \
        SM_CFG_Z1(0x00011664U), \
        SM_CFG_Z1(0x00011844U), \
        SM_CFG_Z1(0x00011864U), \
        SM_CFG_Z1(0x00011a44U), \
        SM_CFG_Z1(0x00011a64U), \
        SM_CFG_Z1(0x00011c44U), \
        SM_CFG_Z1(0x00011c64U), \
        SM_CFG_Z1(0x00011e44U), \
        SM_CFG_Z1(0x00011e64U), \
        SM_CFG_W1(0x00012024U), 0x6666U, \
        SM_CFG_W1(0x00012028U), 0x7777U, \
        SM_CFG_W1(0x0001202cU), 0x6600U, \
        SM_CFG_W1(0x00012260U), 0x09000000U, \
        SM_CFG_W1(0x00012460U), 0x30000000U, \
        SM_CFG_W1(0x00012464U), 0x00330000U, \
        SM_CFG_W1(0x00012640U), 0x99999999U, \
        SM_CFG_W1(0x00012644U), 0x99999999U, \
        SM_CFG_W1(0x00012648U), 0x99999999U, \
        SM_CFG_W1(0x0001264cU), 0x99999999U, \
        SM_CFG_W1(0x00012650U), 0x99999999U, \
        SM_CFG_W1(0x00012654U), 0x99999999U, \
        SM_CFG_W1(0x00012658U), 0x99999999U, \
        SM_CFG_W1(0x0001265cU), 0x99999999U, \
        SM_CFG_W1(0x00012660U), 0x00999999U, \
        SM_CFG_W1(0x00012664U), 0x00009999U, \
        SM_CFG_W1(0x00012780U), 0x00000009U, \
        SM_CFG_W1(0x000127a8U), 0x00000009U, \
        SM_CFG_W1(0x000127d0U), 0x00000009U, \
        SM_CFG_W1(0x00013240U), 0x99999999U, \
        SM_CFG_W1(0x00013244U), 0x99999999U, \
        SM_CFG_W1(0x00013248U), 0x99999999U, \
        SM_CFG_W1(0x0001324cU), 0x99999999U, \
        SM_CFG_W1(0x00013250U), 0x99999999U, \
        SM_CFG_W1(0x00013254U), 0x99999999U, \
        SM_CFG_W1(0x00013258U), 0x99999999U, \
        SM_CFG_W1(0x0001325cU), 0x99999999U, \
        SM_CFG_W1(0x00013260U), 0x99999999U, \
        SM_CFG_W1(0x00013264U), 0x00999999U, \
        SM_CFG_W1(0x00013380U), 0x00000009U, \
        SM_CFG_W1(0x000133a8U), 0x00000009U, \
        SM_CFG_W1(0x000133d0U), 0x00000009U, \
        SM_CFG_W1(0x00014024U), 0x6666U, \
        SM_CFG_W1(0x00014028U), 0x7777U, \
        SM_CFG_W1(0x00014640U), 0x00000009U, \
        SM_CFG_W1(0x00014644U), 0x90000000U, \
        SM_CFG_W1(0x0001464cU), 0x90000000U, \
        SM_CFG_W1(0x0001465cU), 0x99000000U, \
        SM_CFG_W1(0x00014660U), 0x00000099U, \
        SM_CFG_W1(0x0001466cU), 0x99900000U, \
        SM_CFG_W1(0x00014670U), 0x00000009U, \
        SM_CFG_W1(0x00015240U), 0x00000009U, \
        SM_CFG_W1(0x00015244U), 0x90000000U, \
        SM_CFG_W1(0x0001524cU), 0x90000000U, \
        SM_CFG_W1(0x0001525cU), 0x99000000U, \
        SM_CFG_W1(0x00015260U), 0x00000099U, \
        SM_CFG_W1(0x0001526cU), 0x99900000U, \
        SM_CFG_W1(0x00015270U), 0x00000009U, \
        SM_CFG_W1(0x00016024U), 0x6666U, \
        SM_CFG_W1(0x00016028U), 0x7777U, \
        SM_CFG_W1(0x00016640U), 0x00999909U, \
        SM_CFG_W1(0x00016780U), 0x00999909U, \
        SM_CFG_W1(0x00016840U), 0x00000090U, \
        SM_CFG_W1(0x00016980U), 0x00000090U, \
        SM_CFG_W1(0x00017240U), 0x00999999U, \
        SM_CFG_W1(0x00017380U), 0x00999999U, \
        SM_CFG_W1(0x00018024U), 0x6666U, \
        SM_CFG_Z1(0x00018244U), \
        SM_CFG_Z1(0x0001824cU), \
        SM_CFG_Z1(0x00018254U), \
        SM_CFG_Z1(0x0001825cU), \
        SM_CFG_Z1(0x00018340U), \
        SM_CFG_W1(0x00018344U), 0xFFFFC011U, \
        SM_CFG_Z1(0x0001834cU), \
        SM_CFG_Z1(0x00018354U), \
        SM_CFG_Z1(0x0001835cU), \
        SM_CFG_Z1(0x00018444U), \
        SM_CFG_Z1(0x0001844cU), \
        SM_CFG_Z1(0x00018454U), \
        SM_CFG_Z1(0x0001845cU), \
        SM_CFG_Z1(0x00018544U), \
        SM_CFG_Z1(0x0001854cU), \
        SM_CFG_Z1(0x00018554U), \
        SM_CFG_Z1(0x0001855cU), \
        SM_CFG_Z1(0x00018644U), \
        SM_CFG_Z1(0x0001864cU), \
        SM_CFG_Z1(0x00018654U), \
        SM_CFG_Z1(0x0001865cU), \
        SM_CFG_Z1(0x00018744U), \
        SM_CFG_Z1(0x0001874cU), \
        SM_CFG_Z1(0x00018754U), \
        SM_CFG_Z1(0x0001875cU), \
        SM_CFG_Z1(0x00018844U), \
        SM_CFG_Z1(0x0001884cU), \
        SM_CFG_Z1(0x00018854U), \
        SM_CFG_Z1(0x0001885cU), \
        SM_CFG_W1(0x00018940U), 0x00000001U, \
        SM_CFG_W1(0x00018944U), 0xFFFFC011U, \
        SM_CFG_Z1(0x0001894cU), \
        SM_CFG_Z1(0x00018954U), \
        SM_CFG_Z1(0x0001895cU), \
        SM_CFG_Z1(0x00018a44U), \
        SM_CFG_Z1(0x00018a4cU), \
        SM_CFG_Z1(0x00018a54U), \
        SM_CFG_Z1(0x00018a5cU), \
        SM_CFG_Z1(0x00018b44U), \
        SM_CFG_Z1(0x00018b4cU), \
        SM_CFG_Z1(0x00018b54U), \
        SM_CFG_Z1(0x00018b5cU), \
        SM_CFG_Z1(0x00018c44U), \
        SM_CFG_Z1(0x00018c4cU), \
        SM_CFG_Z1(0x00018c54U), \
        SM_CFG_Z1(0x00018c5cU), \
        SM_CFG_W1(0x00019024U), 0x6666U, \
        SM_CFG_W1(0x00019040U), 0x4A030000U, \
        SM_CFG_W1(0x00019044U), 0x4A03C001U, \
        SM_CFG_Z1(0x0001904cU), \
        SM_CFG_Z1(0x00019054U), \
        SM_CFG_Z1(0x0001905cU), \
        SM_CFG_W1(0x00019140U), 0x4A020001U, \
        SM_CFG_W1(0x00019144U), 0x4A02C011U, \
        SM_CFG_Z1(0x0001914cU), \
        SM_CFG_Z1(0x00019154U), \
        SM_CFG_Z1(0x0001915cU), \
        SM_CFG_W1(0x00019240U), 0x4A050000U, \
        SM_CFG_W1(0x00019244U), 0x4A0AC001U, \
        SM_CFG_Z1(0x0001924cU), \
        SM_CFG_Z1(0x00019254U), \
        SM_CFG_Z1(0x0001925cU), \
        SM_CFG_Z1(0x00019344U), \
        SM_CFG_Z1(0x0001934cU), \
        SM_CFG_Z1(0x00019354U), \
        SM_CFG_Z1(0x0001935cU), \
        SM_CFG_W1(0x00019440U), 0x4A060001U, \
        SM_CFG_W1(0x00019444U), 0x4A09C011U, \
        SM_CFG_W1(0x00019448U), 0x20380001U, \
        SM_CFG_W1(0x0001944cU), 0x2047C011U, \
        SM_CFG_Z1(0x00019454U), \
        SM_CFG_Z1(0x0001945cU), \
        SM_CFG_Z1(0x00019544U), \
        SM_CFG_Z1(0x0001954cU), \
        SM_CFG_Z1(0x00019554U), \
        SM_CFG_Z1(0x0001955cU), \
        SM_CFG_Z1(0x00019644U), \
        SM_CFG_Z1(0x0001964cU), \
        SM_CFG_Z1(0x00019654U), \
        SM_CFG_Z1(0x0001965cU), \
        SM_CFG_Z1(0x00019744U), \
        SM_CFG_Z1(0x0001974cU), \
        SM_CFG_Z1(0x00019754U), \
        SM_CFG_Z1(0x0001975cU), \
        SM_CFG_Z1(0x00019844U), \
        SM_CFG_Z1(0x0001984cU), \
        SM_CFG_Z1(0x00019854U), \
        SM_CFG_Z1(0x0001985cU), \
        SM_CFG_W1(0x00019940U), 0x4A020001U, \
        SM_CFG_W1(0x00019944U), 0x4A02C011U, \
        SM_CFG_W1(0x00019948U), 0x4A030001U, \
        SM_CFG_W1(0x0001994cU), 0x4A03C011U, \
        SM_CFG_W1(0x00019950U), 0x4A050001U, \
        SM_CFG_W1(0x00019954U), 0x4A0AC011U, \
        SM_CFG_W1(0x00019958U), 0x4A060001U, \
        SM_CFG_W1(0x0001995cU), 0x4A09C011U, \
        SM_CFG_W1(0x00019960U), 0x20380001U, \
        SM_CFG_W1(0x00019964U), 0x2047C011U, \
        SM_CFG_Z1(0x00019a44U), \
        SM_CFG_Z1(0x00019a4cU), \
        SM_CFG_Z1(0x00019a54U), \
        SM_CFG_Z1(0x00019a5cU), \
        SM_CFG_Z1(0x00019b44U), \
        SM_CFG_Z1(0x00019b4cU), \
        SM_CFG_Z1(0x00019b54U), \
        SM_CFG_Z1(0x00019b5cU), \
        SM_CFG_Z1(0x00019c44U), \
        SM_CFG_Z1(0x00019c4cU), \
        SM_CFG_Z1(0x00019c54U), \
        SM_CFG_Z1(0x00019c5cU), \
        SM_CFG_Z1(0x00010020U), \
        SM_CFG_Z1(0x00012020U), \
        SM_CFG_Z1(0x00014020U), \
        SM_CFG_Z1(0x00016020U), \
        SM_CFG_W1(0x00018020U), 0x7777U, \
        SM_CFG_W1(0x00019020U), 0x6600U, \
        SM_CFG_C1(0x00000000U), 0x0000C001U, \
        SM_CFG_END \
    }

/*--------------------------------------------------------------------------*/
/* TRDC X Config                                                            */
/*--------------------------------------------------------------------------*/

/*! Config for TRDC X */
#define SM_TRDC_X_CONFIG \
    { \
        SM_CFG_W1(0x00000800U), 0xA0000053U, \
        SM_CFG_W1(0x00000820U), 0xA0000053U, \
        SM_CFG_W1(0x00000840U), 0xA00000A8U, \
        SM_CFG_W1(0x00000860U), 0xA0000053U, \
        SM_CFG_W1(0x00000880U), 0xA0000053U, \
        SM_CFG_W1(0x000008a0U), 0xA00000A9U, \
        SM_CFG_W1(0x000008c0U), 0xA00000A9U, \
        SM_CFG_W1(0x000008e0U), 0xA00000ACU, \
        SM_CFG_W1(0x00000900U), 0xA0000053U, \
        SM_CFG_W1(0x00000920U), 0xA0000053U, \
        SM_CFG_W1(0x00000940U), 0xA0000053U, \
        SM_CFG_W1(0x00000960U), 0xA0000053U, \
        SM_CFG_W1(0x00000980U), 0xA0000053U, \
        SM_CFG_W1(0x000009a0U), 0xA0000053U, \
        SM_CFG_W1(0x000009c0U), 0xA0000053U, \
        SM_CFG_W1(0x000009e0U), 0xA0000053U, \
        SM_CFG_W1(0x00000a00U), 0xA0000053U, \
        SM_CFG_W1(0x00000a20U), 0xA0000053U, \
        SM_CFG_W1(0x00000a40U), 0xA0000053U, \
        SM_CFG_W1(0x00000a60U), 0xA0000053U, \
        SM_CFG_W1(0x00000a80U), 0xA0000053U, \
        SM_CFG_W1(0x00000aa0U), 0xA0000053U, \
        SM_CFG_W1(0x00000ac0U), 0xA0000053U, \
        SM_CFG_W1(0x00000ae0U), 0xA0000053U, \
        SM_CFG_W1(0x00000b00U), 0xA0000053U, \
        SM_CFG_W1(0x00000b20U), 0xA0000053U, \
        SM_CFG_W1(0x00000b40U), 0xA0000053U, \
        SM_CFG_W1(0x00000b60U), 0xA0000053U, \
        SM_CFG_W1(0x00000b80U), 0xA0000053U, \
        SM_CFG_W1(0x00000ba0U), 0xA0000053U, \
        SM_CFG_W1(0x00000bc0U), 0xA0000053U, \
        SM_CFG_W1(0x00000be0U), 0xA0000053U, \
        SM_CFG_W1(0x00000c00U), 0xA0000053U, \
        SM_CFG_W1(0x00000c20U), 0xA0000053U, \
        SM_CFG_W1(0x00000c40U), 0xA0000053U, \
        SM_CFG_W1(0x00000c60U), 0xA0000053U, \
        SM_CFG_W1(0x00000c80U), 0xA0000053U, \
        SM_CFG_W1(0x00000ca0U), 0xA0000053U, \
        SM_CFG_W1(0x00000cc0U), 0xA0000053U, \
        SM_CFG_W1(0x00000ce0U), 0xA0000053U, \
        SM_CFG_W1(0x00000d00U), 0xA0000053U, \
        SM_CFG_W1(0x00000d20U), 0xA0000053U, \
        SM_CFG_W1(0x00000d40U), 0xA00000ACU, \
        SM_CFG_W1(0x00000d60U), 0xA0000053U, \
        SM_CFG_W1(0x00000d80U), 0xA0000014U, \
        SM_CFG_W1(0x00000da0U), 0xA0000053U, \
        SM_CFG_W1(0x00000dc0U), 0xA0000053U, \
        SM_CFG_W1(0x00000de0U), 0xA0000053U, \
        SM_CFG_W1(0x00000e00U), 0xA0000053U, \
        SM_CFG_C1(0x00000000U), 0x0000C001U, \
        SM_CFG_END \
    }

#endif /* CONFIG_TRDC_H */

/** @} */

