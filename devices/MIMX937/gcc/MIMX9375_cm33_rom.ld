/*
** ###################################################################
**     Processors:          MIMX9375xxVTx_cm33
**                          MIMX9375xxVZx_cm33
**
**     Compiler:            GNU C Compiler
**     Reference manual:    iMX937RM Rev. 1 Draft A
**     Version:             rev. 1.0, 2026-04-09
**     Build:               b260410
**
**     Abstract:
**         Linker file for the GNU C Compiler
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
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
