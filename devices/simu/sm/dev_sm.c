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
/* File containing the implementation of the device foundation functions.   */
/*==========================================================================*/

/* Includes */

#include "sm.h"
// coverity[misra_c_2012_rule_21_5_violation:FALSE]
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>
#include "dev_sm.h"
#include "brd_sm.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

static void DEV_SM_Tick(union sigval timer_data);

/*--------------------------------------------------------------------------*/
/* Init device                                                              */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_Init(void)
{
    int32_t status;
    struct sigevent signalEvent = { 0 };
    timer_t timer = NULL;
    struct itimerspec timerPeriod = { 0 };
    uint32_t prot = (((uint32_t) PROT_READ)
        | ((uint32_t) PROT_WRITE));
    uint32_t flags = (((uint32_t) MAP_PRIVATE)
        | ((uint32_t) MAP_ANONYMOUS));

    /* Create a POSIX timer */
    signalEvent.sigev_notify = SIGEV_THREAD;
    signalEvent.sigev_notify_function = &DEV_SM_Tick;
    signalEvent.sigev_value.sival_ptr = NULL;
    // coverity[misra_c_2012_rule_19_2_violation:FALSE]
    signalEvent.sigev_notify_attributes = NULL;
    (void) timer_create(CLOCK_MONOTONIC, &signalEvent, &timer);

    /* Configure timer for 1 second periodic */
    timerPeriod.it_value.tv_sec = 1;
    timerPeriod.it_value.tv_nsec = 0;
    timerPeriod.it_interval.tv_sec = 1;
    timerPeriod.it_interval.tv_nsec = 0;

    /* Start timer */
    (void) timer_settime(timer, 0, &timerPeriod, NULL);

    /* Allocate DDR */
    // coverity[misra_c_2012_directive_4_12_violation:FALSE]
    // coverity[misra_c_2012_rule_11_6_violation:FALSE]
    // coverity[misra_c_2012_directive_4_6_violation:FALSE]
    (void) mmap((void*) 0x80000000U, 0x10000, (int) prot, (int) flags,
        -1, 0);

    /* Init fault handling */
    status = DEV_SM_FaultInit();

    /* Initialize sensors */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_SensorInit();
    }

    /* Configure BBM */
    if (status == SM_ERR_SUCCESS)
    {
        status = DEV_SM_BbmInit();
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Get default resource state for LM0 (SM)                                  */
/*--------------------------------------------------------------------------*/
void DEV_SM_LmmInitGet(uint32_t *numClock, const uint32_t **clockList)
{
    /* List of clocks used by SM to be kept on */
    static const uint32_t clocks[] = {DEV_SM_CLK_3};

    /* Return list */
    *numClock = ARRAY_SIZE(clocks);
    *clockList = clocks;
}

/*--------------------------------------------------------------------------*/
/* Init power domain state                                                  */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerUpPost(uint32_t domainId)
{
    int32_t status = SM_ERR_SUCCESS;

    switch (domainId)
    {

        case DEV_SM_PD_0:
            status = DEV_SM_Pd0ConfigLoad();
            break;
        case DEV_SM_PD_1:
            status = DEV_SM_Pd1ConfigLoad();
            break;
        case DEV_SM_PD_2:
            status = DEV_SM_Pd2ConfigLoad();
            break;
        case DEV_SM_PD_3:
            status = DEV_SM_Pd3ConfigLoad();
            break;
        case DEV_SM_PD_4:
            status = DEV_SM_Pd4ConfigLoad();
            break;
        case DEV_SM_PD_5:
            status = DEV_SM_Pd5ConfigLoad();
            break;
        case DEV_SM_PD_6:
            status = DEV_SM_Pd6ConfigLoad();
            break;
        default:
            status = SM_ERR_NOT_FOUND;
            break;
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Power domain preamble for power-down                                     */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PowerDownPre(uint32_t domainId)
{
    int32_t status = SM_ERR_SUCCESS;

    /* Return status */
    return status;
}

/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Timer tick                                                               */
/*--------------------------------------------------------------------------*/
// coverity[misra_c_2012_rule_19_2_violation:FALSE]
static void DEV_SM_Tick(union sigval timer_data)
{
    /* Call board tick */
    BRD_SM_TimerTick(1000U);

    /* Tick BBM */
    DEV_SM_BbmHandler();

    /* Tick control */
    DEV_SM_ControlHandler();

    /* Tick sensor */
    DEV_SM_SensorHandler(0U, 0U);
}

