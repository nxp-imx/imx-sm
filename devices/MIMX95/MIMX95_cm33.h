/*
** ###################################################################
**     Processors:          MIMX95_cm33
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX95_cm33
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**
** ###################################################################
*/

/*!
 * @file MIMX95_cm33.h
 * @version 0.0
 * @date 0-00-00
 * @brief CMSIS Peripheral Access Layer for MIMX95_cm33
 *
 * CMSIS Peripheral Access Layer for MIMX95_cm33
 */

/* Prevention from multiple including the same memory map */
#if !defined(MIMX95_H_)  /* Check if memory map has not been already included */
#define MIMX95_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "MIMX95_BBNSM.h"
#include "MIMX95_BLK_CTRL_NS_AONMIX.h"
#include "MIMX95_BLK_CTRL_S_AONMIX.h"
#include "MIMX95_BLK_CTRL_NOCMIX.h"
#include "MIMX95_BLK_CTRL_WAKEUPMIX.h"
#include "MIMX95_CCM.h"
#include "MIMX95_CM33_MCM.h"
#include "MIMX95_DDRC.h"
#include "MIMX95_FRO.h"
#include "MIMX95_FSB.h"
#include "MIMX95_GICR.h"
#include "MIMX95_GPC_CPU_CTRL.h"
#include "MIMX95_GPC_GLOBAL.h"
#include "MIMX95_IOMUXC.h"
#include "MIMX95_IOMUXC_GPR.h"
#include "MIMX95_LPI2C.h"
#include "MIMX95_LPUART.h"
#include "MIMX95_M33_CACHE_MCM.h"
#include "MIMX95_MCM.h"
#include "MIMX95_MU.h"
#include "MIMX95_OSC24M.h"
#include "MIMX95_PLL.h"
#include "MIMX95_RGPIO.h"
#include "MIMX95_SRC_GEN.h"
#include "MIMX95_SRC_MEM.h"
#include "MIMX95_SRC_XSPR.h"
#include "MIMX95_SYS_CTR_COMPARE.h"
#include "MIMX95_SYS_CTR_CONTROL.h"
#include "MIMX95_SYS_CTR_READ.h"
#include "MIMX95_TMPSNS.h"
#include "MIMX95_WDOG.h"
#include "MIMX95_XCACHE.h"

#endif  /* #if !defined(MIMX95_H_) */
