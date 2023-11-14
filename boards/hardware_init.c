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
    BOARD_InitClocks();
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_InitDebugConsole();
    BOARD_InitHandlers();
    BOARD_InitTimers();
    BOARD_InitSerialBus();
}
/*${function:end}*/
