/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_bbnsm.h"
#include "sm_test_mode.h"

/* External real functions */

extern void __real_BBNSM_SystemPowerOff(BBNSM_Type *base);

/*--------------------------------------------------------------------------*/
/* Turn off system power                                                    */
/*--------------------------------------------------------------------------*/
void __wrap_BBNSM_SystemPowerOff(BBNSM_Type *base)
{
    int32_t status = true;

    SM_TEST_MODE_ERR(SM_TEST_MODE_DRV_LVL1, false)

    if (status)
    {
        __real_BBNSM_SystemPowerOff(base);
    }
}

