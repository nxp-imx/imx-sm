/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*${header:start}*/
#include "board.h"
#include "pin_mux.h"

/*${header:end}*/

/*${function:start}*/
void BOARD_InitHardware(void)
{
    // coverity[misra_c_2012_rule_2_2_violation:FALSE]
    BOARD_InitClocks();
    BOARD_ConfigMPU();
    // coverity[misra_c_2012_rule_2_2_violation:FALSE]
    BOARD_InitPins();
    // coverity[misra_c_2012_rule_2_2_violation:FALSE]
    BOARD_InitDebugConsole();
    BOARD_InitHandlers();
    BOARD_InitTimers();
    // coverity[misra_c_2012_rule_2_2_violation:FALSE]
    BOARD_InitSerialBus();
}
/*${function:end}*/

