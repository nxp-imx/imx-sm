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
        "DAPTDI",
        "DAPTMSSWDIO",
        "DAPTCLKSWCLK",
        "DAPTDOTRACESWO",
        "GPIOIO00",
        "GPIOIO01",
        "GPIOIO02",
        "GPIOIO03",
        "GPIOIO04",
        "GPIOIO05",
        "GPIOIO06",
        "GPIOIO07",
        "GPIOIO08",
        "GPIOIO09",
        "GPIOIO10",
        "GPIOIO11",
        "GPIOIO12",
        "GPIOIO13",
        "GPIOIO14",
        "GPIOIO15",
        "GPIOIO16",
        "GPIOIO17",
        "GPIOIO18",
        "GPIOIO19",
        "GPIOIO20",
        "GPIOIO21",
        "GPIOIO22",
        "GPIOIO23",
        "GPIOIO24",
        "GPIOIO25",
        "GPIOIO26",
        "GPIOIO27",
        "GPIOIO28",
        "GPIOIO29",
        "GPIOIO30",
        "GPIOIO31",
        "GPIOIO32",
        "GPIOIO33",
        "GPIOIO34",
        "GPIOIO35",
        "GPIOIO36",
        "GPIOIO37",
        "CCMCLKO1",
        "CCMCLKO2",
        "CCMCLKO3",
        "CCMCLKO4",
        "ENET1MDC",
        "ENET1MDIO",
        "ENET1TD3",
        "ENET1TD2",
        "ENET1TD1",
        "ENET1TD0",
        "ENET1TXCTL",
        "ENET1TXC",
        "ENET1RXCTL",
        "ENET1RXC",
        "ENET1RD0",
        "ENET1RD1",
        "ENET1RD2",
        "ENET1RD3",
        "ENET2MDC",
        "ENET2MDIO",
        "ENET2TD3",
        "ENET2TD2",
        "ENET2TD1",
        "ENET2TD0",
        "ENET2TXCTL",
        "ENET2TXC",
        "ENET2RXCTL",
        "ENET2RXC",
        "ENET2RD0",
        "ENET2RD1",
        "ENET2RD2",
        "ENET2RD3",
        "SD1CLK",
        "SD1CMD",
        "SD1DATA0",
        "SD1DATA1",
        "SD1DATA2",
        "SD1DATA3",
        "SD1DATA4",
        "SD1DATA5",
        "SD1DATA6",
        "SD1DATA7",
        "SD1STROBE",
        "SD2VSELECT",
        "SD3CLK",
        "SD3CMD",
        "SD3DATA0",
        "SD3DATA1",
        "SD3DATA2",
        "SD3DATA3",
        "XSPI1DATA0",
        "XSPI1DATA1",
        "XSPI1DATA2",
        "XSPI1DATA3",
        "XSPI1DATA4",
        "XSPI1DATA5",
        "XSPI1DATA6",
        "XSPI1DATA7",
        "XSPI1DQS",
        "XSPI1SCLK",
        "XSPI1SS0B",
        "XSPI1SS1B",
        "SD2CDB",
        "SD2CLK",
        "SD2CMD",
        "SD2DATA0",
        "SD2DATA1",
        "SD2DATA2",
        "SD2DATA3",
        "SD2RESETB",
        "I2C1SCL",
        "I2C1SDA",
        "I2C2SCL",
        "I2C2SDA",
        "UART1RXD",
        "UART1TXD",
        "UART2RXD",
        "UART2TXD",
        "PDMCLK",
        "PDMBITSTREAM0",
        "PDMBITSTREAM1",
        "SAI1TXFS",
        "SAI1TXC",
        "SAI1TXD0",
        "SAI1RXD0",
        "WDOGANY",
        "FCCUERR0"
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

