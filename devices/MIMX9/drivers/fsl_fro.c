/*
 * Copyright 2024 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Includes */

#include "fsl_fro.h"

/* Local Defines */

#define REF_CNT(x,y)    ((4000U*x)/y)
#define TEXPCNT(x,y)    ((REF_CNT(x,y))*y/x)
#define TEXPRANGE(x,y)  (uint32_t)((((FRO->CNFG1.RW) & \
    FRO_CNFG1_RFCLKCNT_MASK) >> \
    FRO_CNFG1_RFCLKCNT_SHIFT)*y/x)

/* Local Variables */

static bool s_froEnabled = false;
static FRO_config_info_t s_configInfo =
{
    .outputFreq  = 256U,
    .mode        = OPEN_LOOP,
    .trimVal     = 2035U
};

/*--------------------------------------------------------------------------*/
/* Set the default FRO configuration                                        */
/*--------------------------------------------------------------------------*/
bool FRO_SetDefaultConfig(const FRO_config_info_t defConfig)
{
    bool rc = true;

    /* Check the FRO running status */
    if (!s_froEnabled)
    {
        s_configInfo = defConfig;
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get the default FRO configuration                                        */
/*--------------------------------------------------------------------------*/
bool FRO_GetDefaultConfig(FRO_config_info_t *config)
{
    bool rc = true;

    /* Check for a valid address */
    if (config != NULL)
    {
        config->outputFreq = s_configInfo.outputFreq;
        config->mode = s_configInfo.mode;
        config->trimVal = s_configInfo.trimVal;
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set the FRO Mode                                                         */
/*--------------------------------------------------------------------------*/
bool FRO_SetMode(FRO_mode mode)
{
    bool rc = true;

    /* Check the FRO running status */
    if (!s_froEnabled)
    {
        s_configInfo.mode = mode;
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get the FRO Mode                                                         */
/*--------------------------------------------------------------------------*/
bool FRO_GetMode(FRO_mode *mode)
{
    bool rc = true;

    /* Check for a valid address */
    if (mode != NULL)
    {
        *mode = s_configInfo.mode;
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set the FRO Trim value                                                   */
/*--------------------------------------------------------------------------*/
bool FRO_SetTrim(uint32_t trimVal)
{
    bool rc = true;

    /* Check the FRO running status */
    if (!s_froEnabled)
    {
        s_configInfo.trimVal = trimVal;
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get the FRO trim value                                                   */
/*--------------------------------------------------------------------------*/
bool FRO_GetTrim(uint32_t *trim)
{
    bool rc = true;

    /* Check for a valid address */
    if (trim != NULL)
    {
        /* Check the FRO running status */
        if (s_froEnabled)
        {
            /* Open-loop mode */
            if (s_configInfo.mode == OPEN_LOOP)
            {
                /* Return the FROTRIM register value */
                *trim = FRO->FROTRIM.RW;
            }
            /* Closed-loop mode */
            else
            {
                /* Checking for the CSR.lock-bit set or not */
                if ((FRO->CSR.RW & FRO_CSR_TRIM_LOCK_MASK) == 0U)
                {
                    /* If frequency is not locked, returning the zero */
                    *trim = 0U;
                    rc = false;
                }
                else
                {
                    /* If frequency is locked, returning the Trim value from
                       the AUTOTRIM register */
                    *trim = FRO->AUTOTRIM.RW;
                }
            }
        }
        /* FRO not running */
        else
        {
            *trim = s_configInfo.trimVal;
        }
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Set the FRO output Frequency                                             */
/*--------------------------------------------------------------------------*/
bool FRO_SetRate(uint32_t rate)
{
    bool rc = true;

    /* Check the FRO running status */
    if (!s_froEnabled)
    {
        s_configInfo.outputFreq = rate;
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get the FRO output Frequency                                             */
/*--------------------------------------------------------------------------*/
bool FRO_GetRate(uint32_t *rate)
{
    bool rc = true;

    /* Check for a valid address */
    if (rate != NULL)
    {
        *rate = s_configInfo.outputFreq;
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Enable/disable the FRO                                                   */
/*--------------------------------------------------------------------------*/
bool FRO_SetEnable(bool enable)
{
    bool rc = true;

    /* Enable the FRO if it is not enabled */
    if (enable && (!s_froEnabled))
    {
        /* Configure the FRO for open-loop mode */
        if (s_configInfo.mode == OPEN_LOOP)
        {
            /* Configure the FRO trim value */
            FRO->FROTRIM.RW = (FRO_FROTRIM_TRIMTEMP(31U) |
                (s_configInfo.trimVal & FRO_AUTOTRIM_AUTOTRIM_MASK));

            /* Enable the FRO */
            FRO->CSR.SET = FRO_CSR_FROEN_MASK;

            /* Set the froEnable flag */
            s_froEnabled = true;
        }
        /* Configure the FRO for closed-loop mode */
        else
        {
            /* Configure the FRO trim value to correct the
               start frequency */
            FRO->FROTRIM.RW = (FRO_FROTRIM_TRIMTEMP(31U) |
                (s_configInfo.trimVal & FRO_AUTOTRIM_AUTOTRIM_MASK));

            /* Configure the reference count value based on
               the reference clock value */
            FRO->CNFG1.RW = (FRO_CNFG1_RFCLKCNT(REF_CNT(24U,
                s_configInfo.outputFreq)) | FRO_CNFG1_REFDIV(0U));

            /* Configure the expected FRO count based on output freq */
            FRO->TEXPCNT.RW = (FRO_TEXPCNT_TEXPCNT(TEXPCNT(24U,
                s_configInfo.outputFreq)) |
                FRO_TEXPCNT_TEXPCNT_RANGE(TEXPRANGE(24U, 5U)));

            /* Configure the trim delay count  */
            FRO->CNFG2.RW |= FRO_CNFG2_TRIM1_DELAY(2400U);

            /* Enable FRO, Trim enable, Trim Update enable */
            FRO->CSR.SET = FRO_CSR_FROEN_MASK | FRO_CSR_TREN_MASK
                | FRO_CSR_TRUPEN_MASK;

            /* Set the froEnable flag */
            s_froEnabled = true;
        }
    }
    /* Disable the FRO if it is enabled already */
    else if ((!enable) && (s_froEnabled))
    {
        if (s_configInfo.mode == OPEN_LOOP)
        {
            /* Clear the Trim temp and Trim value configured in the
               FROTRIM register */
            FRO->FROTRIM.CLR = (FRO_FROTRIM_TRIMTEMP_MASK |
                FRO_FROTRIM_COARSE_TRIM_MASK | FRO_FROTRIM_FINE_TRIM_MASK);

            /* Disable the FRO */
            FRO->CSR.CLR = FRO_CSR_FROEN_MASK;

            /* Clear the froEnable flag */
            s_froEnabled = false;
        }
        else
        {
            /* Clear the Trim temp and Trim value, programmed in the
               FROTRIM register */
            FRO->FROTRIM.CLR = (FRO_FROTRIM_TRIMTEMP_MASK |
                FRO_FROTRIM_COARSE_TRIM_MASK | FRO_FROTRIM_FINE_TRIM_MASK);

            /* Clear the Reference count value, disable the autotuner
               interrupts and clear the reference clock devisor */
            FRO->CNFG1.CLR = (FRO_CNFG1_RFCLKCNT_MASK |
                FRO_CNFG1_TRUPREQ_IE_MASK | FRO_CNFG1_TUNE_ERR_IE_MASK |
                FRO_CNFG1_LOL_ERR_IE_MASK | FRO_CNFG1_REFDIV_MASK);

            /* Clear the programmed trim delay and range value */
            FRO->TEXPCNT.CLR = (FRO_TEXPCNT_TEXPCNT_RANGE_MASK |
                FRO_TEXPCNT_TEXPCNT_MASK);
            FRO->CNFG2.CLR = (FRO_CNFG2_TRIM1_DELAY_MASK |
                FRO_CNFG2_CLKGATE_MASK | FRO_CNFG2_FRODIV_MASK);

            /* Disable FRO, clear the Trim enable and Trim Update
               enable bits */
            FRO->CSR.CLR = (FRO_CSR_TUNEONCE_DONE_MASK |
                FRO_CSR_TRIM_LOCK_MASK | FRO_CSR_TRUPREQ_MASK |
                FRO_CSR_TUNE_ERR_MASK | FRO_CSR_LOL_ERR_MASK |
                FRO_CSR_TUNEONCE_MASK | FRO_CSR_COARSEN_MASK |
                FRO_CSR_TRUPEN_MASK | FRO_CSR_TREN_MASK |
                FRO_CSR_SMODE_MASK | FRO_CSR_FROEN_MASK);

            /* Clear the froEnable flag */
            s_froEnabled = false;
        }
    }
    /* Case to handle disable request when FRO already disabled */
    else if ((!enable) && (!s_froEnabled))
    {
        rc = false;
    }
    else
    {
        rc = false;
    }

    /* Return status */
    return rc;
}

/*--------------------------------------------------------------------------*/
/* Get FRO enable status                                                    */
/*--------------------------------------------------------------------------*/
bool FRO_GetEnable(void)
{
    /* Return enable state */
    return s_froEnabled;
}

