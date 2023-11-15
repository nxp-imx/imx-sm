/*
** ###################################################################
**     Processors:          MIMX95_cm33
**
**     Compiler:            GNU C Compiler
**     Reference manual:    IMX95RM, Internal, November. 2021
**     Version:             rev. 1.0, 2021-11-16
**     Build:               b220818
**
**     Abstract:
**         Linker file for the GNU C Compiler
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

/* Entry Point */
ENTRY(RomReset_Handler)

/* Specify the memory areas */
MEMORY
{
  m_rom                 (RX)  : ORIGIN = 0x00000000, LENGTH = 0x00020000
}

/* Define output sections */
SECTIONS
{
  /* Vector table and code to emulate ROM */
  .rom :
  {
    . = ALIGN(8);
    KEEP(*(.rom))
    . = ALIGN(0x80);
  } > m_rom
}
