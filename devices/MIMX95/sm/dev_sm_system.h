/*
** ###################################################################
**
**     Copyright 2023-2024 NXP
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

#ifndef DEV_SM_SYSTEM_H
#define DEV_SM_SYSTEM_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX95_SYS
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device system.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device boot/shutdown/reset reasons */
#define DEV_SM_NUM_REASON  RST_NUM_REASONS

/*!
 * @name Device boot/shutdown/reset reason indexes
 *
 * See the SRESR register description in the System Reset Controller (SRC) section
 * of the i.MX95 RM.
 */
/** @{ */
#define DEV_SM_REASON_CM33_LOCKUP  RST_REASON_CM33_LOCKUP  /*!< 0: CM33 lockup */
#define DEV_SM_REASON_CM33_SWREQ   RST_REASON_CM33_SWREQ   /*!< 1: CM33 SW request */
#define DEV_SM_REASON_CM7_LOCKUP   RST_REASON_CM7_LOCKUP   /*!< 2: CM7 lockup */
#define DEV_SM_REASON_CM7_SWREQ    RST_REASON_CM7_SWREQ    /*!< 3: CM7 SW request */
#define DEV_SM_REASON_FCCU         RST_REASON_FCCU         /*!< 4: FCCU */
#define DEV_SM_REASON_JTAG_SW      RST_REASON_JTAG_SW      /*!< 5: JTAG SW */
#define DEV_SM_REASON_ELE          RST_REASON_SENTINEL     /*!< 6: ELE */
#define DEV_SM_REASON_TEMPSENSE    RST_REASON_TEMPSENSE    /*!< 7: Sensor panic */
#define DEV_SM_REASON_WDOG1        RST_REASON_WDOG1        /*!< 8: WDOG 1 */
#define DEV_SM_REASON_WDOG2        RST_REASON_WDOG2        /*!< 9: WDOG 2 */
#define DEV_SM_REASON_WDOG3        RST_REASON_WDOG3        /*!< 10: WDOG 3 */
#define DEV_SM_REASON_WDOG4        RST_REASON_WDOG4        /*!< 11: WDOG 4 */
#define DEV_SM_REASON_WDOG5        RST_REASON_WDOG5        /*!< 12: WDOG 5 */
#define DEV_SM_REASON_JTAG         RST_REASON_JTAG         /*!< 13: JTAG */
#define DEV_SM_REASON_CM33_EXC     RST_REASON_CM33_EXC     /*!< 14: CM33 exception */
#define DEV_SM_REASON_BBM          RST_REASON_UNUSED0      /*!< 15: BBM boot/shutdown */
#define DEV_SM_REASON_SW           RST_REASON_UNUSED1      /*!< 16: SW requested */
#define DEV_SM_REASON_SM_ERR       RST_REASON_UNUSED2      /*!< 17: SM error/exit */
#define DEV_SM_REASON_FUSA_SRECO   RST_REASON_UNUSED3      /*!< 18: FuSa global recovery */
#define DEV_SM_REASON_UNUSED4      RST_REASON_UNUSED4      /*!< 19: Unused */
#define DEV_SM_REASON_UNUSED5      RST_REASON_UNUSED5      /*!< 20: Unused */
#define DEV_SM_REASON_UNUSED6      RST_REASON_UNUSED6      /*!< 21: Unused */
#define DEV_SM_REASON_UNUSED7      RST_REASON_UNUSED7      /*!< 22: Unused */
#define DEV_SM_REASON_UNUSED8      RST_REASON_UNUSED8      /*!< 23: Unused */
#define DEV_SM_REASON_UNUSED9      RST_REASON_UNUSED9      /*!< 24: Unused */
#define DEV_SM_REASON_UNUSED10     RST_REASON_UNUSED10     /*!< 25: Unused */
#define DEV_SM_REASON_UNUSED11     RST_REASON_UNUSED11     /*!< 26: Unused */
#define DEV_SM_REASON_UNUSED12     RST_REASON_UNUSED12     /*!< 27: Unused */
#define DEV_SM_REASON_UNUSED13     RST_REASON_UNUSED13     /*!< 28: Unused */
#define DEV_SM_REASON_UNUSED14     RST_REASON_UNUSED14     /*!< 20: Unused */
#define DEV_SM_REASON_UNUSED15     RST_REASON_UNUSED15     /*!< 30: Unused */
#define DEV_SM_REASON_POR          RST_REASON_POR          /*!< 31: Power on reset */
/** @} */

/*! Number of device reset reasons */
#define DEV_SM_NUM_EXT_INFO  3U

/*! Default record for POR */
#define DEV_SM_RST_REC_POR \
    { \
        .reason = DEV_SM_REASON_POR, \
        .valid = true \
    }

/*! Default record for SW */
#define DEV_SM_RST_REC_SW \
    { \
        .reason = DEV_SM_REASON_SW, \
        .origin = 0U, \
        .validOrigin = true, \
        .valid = true \
    }

/*! Default record for BBM */
#define DEV_SM_RST_REC_BBM \
    { \
        .reason = DEV_SM_REASON_BBM, \
        .valid = true \
    }

/*!
 * @name System power mode flags
 */
/** @{ */
#define DEV_SM_SPM_SM_ACTIVE_MASK           (1U << 0U)  /*!< Keep SM active */
#define DEV_SM_SPM_FRO_ACTIVE_MASK          (1U << 1U)  /*!< Keep FRO active */
#define DEV_SM_SPM_SYSCTR_ACTIVE_MASK       (1U << 2U)  /*!< Keep SYSCTR active */
#define DEV_SM_SPM_PMIC_STBY_INACTIVE_MASK  (1U << 3U)  /*!< No PMIC_STBY assertion */
#define DEV_SM_SPM_OSC24M_ACTIVE_MASK       (1U << 4U)  /*!< Keep OSC24M active */
#define DEV_SM_SPM_DRAM_ACTIVE_MASK         (1U << 5U)  /*!< Keep DRAM active */
/** @} */

/* Types */

/*!
 * System sleep record
 */
typedef struct
{
    /*! System sleep entry latency */
    uint32_t sleepEntryUsec;

    /*! System sleep exit latency */
    uint32_t sleepExitUsec;

    /*! System sleep counter */
    uint32_t sleepCnt;

    /*! IRQ/exception causing system wake */
    uint32_t wakeSource;

    /*! MIX power status */
    uint32_t mixPwrStat;

    /*! MEM power status */
    uint32_t memPwrStat;

    /*! PLL power status */
    uint32_t pllPwrStat;

    /*! System power mode */
    uint32_t sysPwrMode;
} dev_sm_sys_sleep_rec_t;

/* Functions */

/* Externs */

/*! External pointer to the DRAM info */
extern uint32_t *__DramInfo;

/** @} */

/* Include SM device API */

// coverity[misra_c_2012_rule_20_1_violation:FALSE]
#include "dev_sm_system_api.h"

#endif /* DEV_SM_SYSTEM_H */

