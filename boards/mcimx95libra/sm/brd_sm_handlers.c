/*
** ###################################################################
**
** Copyright 2023-2025 NXP
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
/* File containing the implementation of the handlers for the board.        */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "brd_sm.h"
#include "dev_sm.h"
#include "fsl_lpi2c.h"
#include "fsl_rgpio.h"

/* Local defines */

/* I2C device addresses */
#define BOARD_PF09_DEV_ADDR         0x08U
#define BOARD_PF5301_DEV_ADDR       0x2AU
#define BOARD_PF5302_DEV_ADDR       0x29U

/* Local types */

/* Local variables */

/* Global variables */

PF09_Type g_pf09Dev = {0};
PF53_Type g_pf5301Dev = {0};
PF53_Type g_pf5302Dev = {0};

irq_prio_info_t g_brdIrqPrioInfo[BOARD_NUM_IRQ_PRIO_IDX] = { };

uint32_t g_pmicFaultFlags = 0U;

/* Local functions */

static void BRD_SM_Pf09Handler(void);

/*--------------------------------------------------------------------------*/
/* Init serial devices                                                      */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_SerialDevicesInit(void) {
    int32_t status = SM_ERR_SUCCESS;
    LPI2C_Type *const s_i2cBases[] = LPI2C_BASE_PTRS;

    /* Fill in PF09 PMIC handle */
    g_pf09Dev.i2cBase = s_i2cBases[BOARD_I2C_INSTANCE];
    g_pf09Dev.devAddr = BOARD_PF09_DEV_ADDR;
    g_pf09Dev.crcEn = true;

    /* Initialize PF09 PMIC */
    if (!PF09_Init(&g_pf09Dev)) {
	    printf("pf09 init failed\n");
	    return SM_ERR_HARDWARE_ERROR;
    }

    /* Disable voltage monitor 1 */
    if (status == SM_ERR_SUCCESS) {
	    if (!PF09_MonitorEnable(&g_pf09Dev, PF09_VMON1, false))
		    status = SM_ERR_HARDWARE_ERROR;
    }

    /* Disable voltage monitor 2 */
    if (status == SM_ERR_SUCCESS) {
	    if (!PF09_MonitorEnable(&g_pf09Dev, PF09_VMON2, false))
		    status = SM_ERR_HARDWARE_ERROR;
    }

    /* Disable the PWRUP interrupt */
    if (status == SM_ERR_SUCCESS) {
	    const uint8_t mask[PF09_MASK_LEN] = {
		    [PF09_MASK_IDX_STATUS1] = 0x08U
	    };

	    if (!PF09_IntEnable(&g_pf09Dev, mask, PF09_MASK_LEN, false))
		    status = SM_ERR_HARDWARE_ERROR;
    }

    /* Change the LDO3 sequence */
    if (status == SM_ERR_SUCCESS) {
	    if (!PF09_PmicWrite(&g_pf09Dev, 0x4AU, 0x1EU, 0xFFU))
		    status = SM_ERR_HARDWARE_ERROR;
    }

    /* Set the LDO3 OV bypass */
    if (status == SM_ERR_SUCCESS) {
	    if (!PF09_PmicWrite(&g_pf09Dev, 0x7FU, 0xFCU, 0xFFU))
		    status = SM_ERR_HARDWARE_ERROR;
    }

    /* Enable the LDO3 in RUN mode */
    if (status == SM_ERR_SUCCESS) {
        if (!PF09_PmicWrite(&g_pf09Dev, 0x7DU, 0x20U, 0xFFU))
            status = SM_ERR_HARDWARE_ERROR;
    }

    /* Set the OV debounce to 50us due to errata ER011/12 */
    if (status == SM_ERR_SUCCESS) {
	    if (!PF09_PmicWrite(&g_pf09Dev, 0x37U, 0x94U, 0xFFU))
		    status = SM_ERR_HARDWARE_ERROR;
    }

    /* Save and clear any fault flags */
    if (status == SM_ERR_SUCCESS) {
	    if (!PF09_FaultFlags(&g_pf09Dev, &g_pmicFaultFlags, true))
		    status = SM_ERR_HARDWARE_ERROR;
    }

    /* Handle any already pending PF09 interrupts */
    if (status == SM_ERR_SUCCESS)
	    BRD_SM_Pf09Handler();

    if (status == SM_ERR_SUCCESS) {
        /* Fill in PF5301 PMIC handle */
        g_pf5301Dev.i2cBase = s_i2cBases[BOARD_I2C_INSTANCE];
        g_pf5301Dev.devAddr = BOARD_PF5301_DEV_ADDR;

        /* Initialize PF5301 PMIC */
        if (!PF53_Init(&g_pf5301Dev))
            return SM_ERR_HARDWARE_ERROR;

    }

    if (status == SM_ERR_SUCCESS) {
        /* Fill in PF5302 PMIC handle */
        g_pf5302Dev.i2cBase = s_i2cBases[BOARD_I2C_INSTANCE];
        g_pf5302Dev.devAddr = BOARD_PF5302_DEV_ADDR;

        /* Initialize PF5302 PMIC */
        if (!PF53_Init(&g_pf5302Dev))
            return SM_ERR_HARDWARE_ERROR;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set bus expander interrupt mask                                          */
/*--------------------------------------------------------------------------*/
int32_t BRD_SM_BusExpMaskSet(uint8_t val, uint8_t mask) {
    return SM_ERR_SUCCESS;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* PF09 handler                                                             */
/*--------------------------------------------------------------------------*/
static void BRD_SM_Pf09Handler(void) {
    uint8_t stat[PF09_MASK_LEN] = { 0 };

    /* Read status of interrupts */
    (void) PF09_IntStatus(&g_pf09Dev, stat, PF09_MASK_LEN);

    /* Clear pending */
    (void) PF09_IntClear(&g_pf09Dev, stat, PF09_MASK_LEN);

    /* Handle pending temp interrupts */
    if ((stat[PF09_MASK_IDX_STATUS2] & 0x0FU) != 0U)
        BRD_SM_SensorHandler();
}
