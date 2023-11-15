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
/* File containing the implementation of the SM device configuration        */
/* loading functions.                                                       */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "config_dev.h"

/* Local defines */

/* Local types */

/* Local variables */

/* Local functions */

/*--------------------------------------------------------------------------*/
/* Load PD0 power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_Pd0ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_PD0_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_PD0_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_PD0_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load PD1 power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_Pd1ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_PD1_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_PD1_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_PD1_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load PD2 power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_Pd2ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_PD2_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_PD2_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_PD2_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load PD3 power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_Pd3ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_PD3_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_PD3_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_PD3_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load PD4 power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_Pd4ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_PD4_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_PD4_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_PD4_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load PD5 power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_Pd5ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_PD5_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_PD50_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_PD5_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Load PD6 power domain configuration                                      */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_Pd6ConfigLoad(void)
{
    int32_t status;
    static const uint32_t s_configData[] = SM_PD6_CONFIG;

    /* Load device config */
    status = CONFIG_Load(NULL, s_configData);

#ifdef SM_PD6_CONFIG_FUNC
    /* Run device config function */
    if (status == SM_ERR_SUCCESS)
    {
        status = SM_PD6_CONFIG_FUNC();
    }
#endif

    /* Return status */
    return status;
}

