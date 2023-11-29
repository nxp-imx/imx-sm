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
/* File containing the implementation of the device pins.                   */
/*==========================================================================*/

/* Includes */

#include "sm.h"
#include "dev_sm.h"
#include "fsl_iomuxc.h"

/* Local defines */

/* Local types */

/* Local variables */

/*--------------------------------------------------------------------------*/
/* Return pin name                                                          */
/*--------------------------------------------------------------------------*/
int32_t DEV_SM_PinNameGet(uint32_t identifier, string *pinNameAddr,
    int32_t *len)
{
    int32_t status = SM_ERR_SUCCESS;
    static int32_t s_maxLen = 0;

    static string const s_name[DEV_SM_NUM_PIN] =
    {
        "daptdi",
        "daptmsswdio",
        "daptclkswclk",
        "daptdotraceswo",
        "gpioio00",
        "gpioio01",
        "gpioio02",
        "gpioio03",
        "gpioio04",
        "gpioio05",
        "gpioio06",
        "gpioio07",
        "gpioio08",
        "gpioio09",
        "gpioio10",
        "gpioio11",
        "gpioio12",
        "gpioio13",
        "gpioio14",
        "gpioio15",
        "gpioio16",
        "gpioio17",
        "gpioio18",
        "gpioio19",
        "gpioio20",
        "gpioio21",
        "gpioio22",
        "gpioio23",
        "gpioio24",
        "gpioio25",
        "gpioio26",
        "gpioio27",
        "gpioio28",
        "gpioio29",
        "gpioio30",
        "gpioio31",
        "gpioio32",
        "gpioio33",
        "gpioio34",
        "gpioio35",
        "gpioio36",
        "gpioio37",
        "ccmclko1",
        "ccmclko2",
        "ccmclko3",
        "ccmclko4",
        "enet1mdc",
        "enet1mdio",
        "enet1td3",
        "enet1td2",
        "enet1td1",
        "enet1td0",
        "enet1txctl",
        "enet1txc",
        "enet1rxctl",
        "enet1rxc",
        "enet1rd0",
        "enet1rd1",
        "enet1rd2",
        "enet1rd3",
        "enet2mdc",
        "enet2mdio",
        "enet2td3",
        "enet2td2",
        "enet2td1",
        "enet2td0",
        "enet2txctl",
        "enet2txc",
        "enet2rxctl",
        "enet2rxc",
        "enet2rd0",
        "enet2rd1",
        "enet2rd2",
        "enet2rd3",
        "sd1clk",
        "sd1cmd",
        "sd1data0",
        "sd1data1",
        "sd1data2",
        "sd1data3",
        "sd1data4",
        "sd1data5",
        "sd1data6",
        "sd1data7",
        "sd1strobe",
        "sd2vselect",
        "sd3clk",
        "sd3cmd",
        "sd3data0",
        "sd3data1",
        "sd3data2",
        "sd3data3",
        "xspi1data0",
        "xspi1data1",
        "xspi1data2",
        "xspi1data3",
        "xspi1data4",
        "xspi1data5",
        "xspi1data6",
        "xspi1data7",
        "xspi1dqs",
        "xspi1sclk",
        "xspi1ss0b",
        "xspi1ss1b",
        "sd2cdb",
        "sd2clk",
        "sd2cmd",
        "sd2data0",
        "sd2data1",
        "sd2data2",
        "sd2data3",
        "sd2resetb",
        "i2c1scl",
        "i2c1sda",
        "i2c2scl",
        "i2c2sda",
        "uart1rxd",
        "uart1txd",
        "uart2rxd",
        "uart2txd",
        "pdmclk",
        "pdmbitstream0",
        "pdmbitstream1",
        "sai1txfs",
        "sai1txc",
        "sai1txd0",
        "sai1rxd0",
        "wdogany",
        "fccuerr0"
    };

    /* Get max string width */
    DEV_SM_MaxStringGet(len, &s_maxLen, s_name, DEV_SM_NUM_PIN);

    /* Check domain */
    if (identifier >= DEV_SM_NUM_PIN)
    {
        status = SM_ERR_NOT_FOUND;
    }
    else
    {
        /* Return pointer to name */
        *pinNameAddr = s_name[identifier];
    }

    /* Return status */
    return status;
}

/*--------------------------------------------------------------------------*/
/* Set pin config                                                           */
/*--------------------------------------------------------------------------*/
void DEV_SM_PinConfigSet(uint32_t type, uint32_t identifier, uint32_t value)
{
    /* Handle Mux */
    if (type == DEV_SM_PIN_TYPE_MUX)
    {
        uint32_t muxRegister = IOMUXC_BASE + (identifier * 4U);
        uint32_t inputOnfield = 0U;

        /* Extract SION */
        if ((value & ((uint32_t) IOMUXC_PAD_SION_MASK)) != 0U)
        {
            inputOnfield = 1U;
        }

        IOMUXC_SetPinMux(muxRegister, value, 0U, 0U, 0U, inputOnfield);
    }

    /* Handle Config */
    else if (type == DEV_SM_PIN_TYPE_CONFIG)
    {
        uint32_t configRegister = IOMUXC_BASE + (DEV_SM_NUM_PIN * 4U)
            + (identifier * 4U);

        IOMUXC_SetPinConfig(0U, 0U, 0U, 0U, configRegister, value);
    }

    /* Handle Daisy */
    else if (type == DEV_SM_PIN_TYPE_DAISY)
    {
        uint32_t daisyRegister = IOMUXC_BASE + (DEV_SM_NUM_PIN * 8U)
            + (identifier * 4U);

        IOMUXC_SetPinMux(0U, 0U, daisyRegister, value, 0U, 0U);
    }

    /* Else */
    else
    {
        ; /* Intentional empty else */
    }
}

/*--------------------------------------------------------------------------*/
/* Get pin config                                                           */
/*--------------------------------------------------------------------------*/
void DEV_SM_PinConfigGet(uint32_t type, uint32_t identifier, uint32_t *value)
{
    /* Handle Mux */
    if (type == DEV_SM_PIN_TYPE_MUX)
    {
        uint32_t muxRegister = IOMUXC_BASE + (identifier * 4U);

        *value = *((volatile uint32_t*) muxRegister);
    }

    /* Handle Config */
    else if (type == DEV_SM_PIN_TYPE_CONFIG)
    {
        uint32_t configRegister = IOMUXC_BASE + (DEV_SM_NUM_PIN * 4U)
            + (identifier * 4U);

        *value =  *((volatile uint32_t*) configRegister);
    }

    /* Handle Daisy */
    else if (type == DEV_SM_PIN_TYPE_DAISY)
    {
        uint32_t daisyRegister = IOMUXC_BASE + (DEV_SM_NUM_PIN * 8U)
            + (identifier * 4U);

        *value = *((volatile uint32_t*) daisyRegister);
    }

    /* Else */
    else
    {
        ; /* Intentional empty else */
    }
}

