/*
** ###################################################################
**
**     Copyright 2026 NXP
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

#ifndef DEV_SM_PIN_H
#define DEV_SM_PIN_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX952_PIN
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the SM API for the device pins.
 */
/*==========================================================================*/

/* Includes */

#include "sm.h"

/* Defines */

/*! Number of device pin */
#define DEV_SM_NUM_PIN    140U

/*! Number of device daisy */
#define DEV_SM_NUM_DAISY  135U

/*!
 * @name Device pin indexes
 *
 * See the IOMUXC register list in the i.MX952 RM.
 */
/** @{ */
#define DEV_SM_PIN_DAP_TDI           0U    /*!< DAP TDI pin */
#define DEV_SM_PIN_DAP_TMS_SWDIO     1U    /*!< DAP TMS SWDIO pin */
#define DEV_SM_PIN_DAP_TCLK_SWCLK    2U    /*!< DAP TCLK SWCLK pin */
#define DEV_SM_PIN_DAP_TDO_TRACESWO  3U    /*!< DAP TDO TRACESWO pin */
#define DEV_SM_PIN_GPIO_IO00         4U    /*!< GPIO IO00 pin */
#define DEV_SM_PIN_GPIO_IO01         5U    /*!< GPIO IO01 pin */
#define DEV_SM_PIN_GPIO_IO02         6U    /*!< GPIO IO02 pin */
#define DEV_SM_PIN_GPIO_IO03         7U    /*!< GPIO IO03 pin */
#define DEV_SM_PIN_GPIO_IO04         8U    /*!< GPIO IO04 pin */
#define DEV_SM_PIN_GPIO_IO05         9U    /*!< GPIO IO05 pin */
#define DEV_SM_PIN_GPIO_IO06         10U   /*!< GPIO IO06 pin */
#define DEV_SM_PIN_GPIO_IO07         11U   /*!< GPIO IO07 pin */
#define DEV_SM_PIN_GPIO_IO08         12U   /*!< GPIO IO08 pin */
#define DEV_SM_PIN_GPIO_IO09         13U   /*!< GPIO IO09 pin */
#define DEV_SM_PIN_GPIO_IO10         14U   /*!< GPIO IO10 pin */
#define DEV_SM_PIN_GPIO_IO11         15U   /*!< GPIO IO11 pin */
#define DEV_SM_PIN_GPIO_IO12         16U   /*!< GPIO IO12 pin */
#define DEV_SM_PIN_GPIO_IO13         17U   /*!< GPIO IO13 pin */
#define DEV_SM_PIN_GPIO_IO14         18U   /*!< GPIO IO14 pin */
#define DEV_SM_PIN_GPIO_IO15         19U   /*!< GPIO IO15 pin */
#define DEV_SM_PIN_GPIO_IO16         20U   /*!< GPIO IO16 pin */
#define DEV_SM_PIN_GPIO_IO17         21U   /*!< GPIO IO17 pin */
#define DEV_SM_PIN_GPIO_IO18         22U   /*!< GPIO IO18 pin */
#define DEV_SM_PIN_GPIO_IO19         23U   /*!< GPIO IO19 pin */
#define DEV_SM_PIN_GPIO_IO20         24U   /*!< GPIO IO20 pin */
#define DEV_SM_PIN_GPIO_IO21         25U   /*!< GPIO IO21 pin */
#define DEV_SM_PIN_GPIO_IO22         26U   /*!< GPIO IO22 pin */
#define DEV_SM_PIN_GPIO_IO23         27U   /*!< GPIO IO23 pin */
#define DEV_SM_PIN_GPIO_IO24         28U   /*!< GPIO IO24 pin */
#define DEV_SM_PIN_GPIO_IO25         29U   /*!< GPIO IO25 pin */
#define DEV_SM_PIN_GPIO_IO26         30U   /*!< GPIO IO26 pin */
#define DEV_SM_PIN_GPIO_IO27         31U   /*!< GPIO IO27 pin */
#define DEV_SM_PIN_GPIO_IO28         32U   /*!< GPIO IO28 pin */
#define DEV_SM_PIN_GPIO_IO29         33U   /*!< GPIO IO29 pin */
#define DEV_SM_PIN_GPIO_IO30         34U   /*!< GPIO IO30 pin */
#define DEV_SM_PIN_GPIO_IO31         35U   /*!< GPIO IO31 pin */
#define DEV_SM_PIN_GPIO_IO32         36U   /*!< GPIO IO32 pin */
#define DEV_SM_PIN_GPIO_IO33         37U   /*!< GPIO IO33 pin */
#define DEV_SM_PIN_GPIO_IO34         38U   /*!< GPIO IO34 pin */
#define DEV_SM_PIN_GPIO_IO35         39U   /*!< GPIO IO35 pin */
#define DEV_SM_PIN_GPIO_IO36         40U   /*!< GPIO IO36 pin */
#define DEV_SM_PIN_GPIO_IO37         41U   /*!< GPIO IO37 pin */
#define DEV_SM_PIN_GPIO_IO38         42U   /*!< GPIO IO38 pin */
#define DEV_SM_PIN_GPIO_IO39         43U   /*!< GPIO IO39 pin */
#define DEV_SM_PIN_GPIO_IO40         44U   /*!< GPIO IO40 pin */
#define DEV_SM_PIN_LD_SPI_CS0        45U   /*!< LD SPI CS0 pin */
#define DEV_SM_PIN_LD_SPI_SCK        46U   /*!< LD SPI SCK pin */
#define DEV_SM_PIN_LD_SPI_DI         47U   /*!< LD SPI DI pin */
#define DEV_SM_PIN_LD_SPI_DO         48U   /*!< LD SPI DO pin */
#define DEV_SM_PIN_LD_HSYNC          49U   /*!< LD HSYNC pin */
#define DEV_SM_PIN_LD_VSYNC          50U   /*!< LD VSYNC pin */
#define DEV_SM_PIN_LD_GPIO0          51U   /*!< LD GPIO0 pin */
#define DEV_SM_PIN_LD_GPIO1          52U   /*!< LD GPIO1 pin */
#define DEV_SM_PIN_CCM_CLKO1         53U   /*!< CCM CLKO1 pin */
#define DEV_SM_PIN_CCM_CLKO2         54U   /*!< CCM CLKO2 pin */
#define DEV_SM_PIN_CCM_CLKO3         55U   /*!< CCM CLKO3 pin */
#define DEV_SM_PIN_CCM_CLKO4         56U   /*!< CCM CLKO4 pin */
#define DEV_SM_PIN_ENET1_MDC         57U   /*!< ENET1 MDC pin */
#define DEV_SM_PIN_ENET1_MDIO        58U   /*!< ENET1 MDIO pin */
#define DEV_SM_PIN_ENET1_TD3         59U   /*!< ENET1 TD3 pin */
#define DEV_SM_PIN_ENET1_TD2         60U   /*!< ENET1 TD2 pin */
#define DEV_SM_PIN_ENET1_TD1         61U   /*!< ENET1 TD1 pin */
#define DEV_SM_PIN_ENET1_TD0         62U   /*!< ENET1 TD0 pin */
#define DEV_SM_PIN_ENET1_TX_CTL      63U   /*!< ENET1 TX CTL pin */
#define DEV_SM_PIN_ENET1_TXC         64U   /*!< ENET1 TXC pin */
#define DEV_SM_PIN_ENET1_RX_CTL      65U   /*!< ENET1 RX CTL pin */
#define DEV_SM_PIN_ENET1_RXC         66U   /*!< ENET1 RXC pin */
#define DEV_SM_PIN_ENET1_RD0         67U   /*!< ENET1 RD0 pin */
#define DEV_SM_PIN_ENET1_RD1         68U   /*!< ENET1 RD1 pin */
#define DEV_SM_PIN_ENET1_RD2         69U   /*!< ENET1 RD2 pin */
#define DEV_SM_PIN_ENET1_RD3         70U   /*!< ENET1 RD3 pin */
#define DEV_SM_PIN_ENET2_MDC         71U   /*!< ENET2 MDC pin */
#define DEV_SM_PIN_ENET2_MDIO        72U   /*!< ENET2 MDIO pin */
#define DEV_SM_PIN_ENET2_TD3         73U   /*!< ENET2 TD3 pin */
#define DEV_SM_PIN_ENET2_TD2         74U   /*!< ENET2 TD2 pin */
#define DEV_SM_PIN_ENET2_TD1         75U   /*!< ENET2 TD1 pin */
#define DEV_SM_PIN_ENET2_TD0         76U   /*!< ENET2 TD0 pin */
#define DEV_SM_PIN_ENET2_TX_CTL      77U   /*!< ENET2 TX CTL pin */
#define DEV_SM_PIN_ENET2_TXC         78U   /*!< ENET2 TXC pin */
#define DEV_SM_PIN_ENET2_RX_CTL      79U   /*!< ENET2 RX CTL pin */
#define DEV_SM_PIN_ENET2_RXC         80U   /*!< ENET2 RXC pin */
#define DEV_SM_PIN_ENET2_RD0         81U   /*!< ENET2 RD0 pin */
#define DEV_SM_PIN_ENET2_RD1         82U   /*!< ENET2 RD1 pin */
#define DEV_SM_PIN_ENET2_RD2         83U   /*!< ENET2 RD2 pin */
#define DEV_SM_PIN_ENET2_RD3         84U   /*!< ENET2 RD3 pin */
#define DEV_SM_PIN_SD1_CLK           85U   /*!< SD1 CLK pin */
#define DEV_SM_PIN_SD1_CMD           86U   /*!< SD1 CMD pin */
#define DEV_SM_PIN_SD1_DATA0         87U   /*!< SD1 DATA0 pin */
#define DEV_SM_PIN_SD1_DATA1         88U   /*!< SD1 DATA1 pin */
#define DEV_SM_PIN_SD1_DATA2         89U   /*!< SD1 DATA2 pin */
#define DEV_SM_PIN_SD1_DATA3         90U   /*!< SD1 DATA3 pin */
#define DEV_SM_PIN_SD1_DATA4         91U   /*!< SD1 DATA4 pin */
#define DEV_SM_PIN_SD1_DATA5         92U   /*!< SD1 DATA5 pin */
#define DEV_SM_PIN_SD1_DATA6         93U   /*!< SD1 DATA6 pin */
#define DEV_SM_PIN_SD1_DATA7         94U   /*!< SD1 DATA7 pin */
#define DEV_SM_PIN_SD1_STROBE        95U   /*!< SD1 STROBE pin */
#define DEV_SM_PIN_SD2_VSELECT       96U   /*!< SD2 VSELECT pin */
#define DEV_SM_PIN_SD3_CLK           97U   /*!< SD3 CLK pin */
#define DEV_SM_PIN_SD3_CMD           98U   /*!< SD3 CMD pin */
#define DEV_SM_PIN_SD3_DATA0         99U   /*!< SD3 DATA0 pin */
#define DEV_SM_PIN_SD3_DATA1         100U  /*!< SD3 DATA1 pin */
#define DEV_SM_PIN_SD3_DATA2         101U  /*!< SD3 DATA2 pin */
#define DEV_SM_PIN_SD3_DATA3         102U  /*!< SD3 DATA3 pin */
#define DEV_SM_PIN_XSPI1_DATA0       103U  /*!< XSPI1 DATA0 pin */
#define DEV_SM_PIN_XSPI1_DATA1       104U  /*!< XSPI1 DATA1 pin */
#define DEV_SM_PIN_XSPI1_DATA2       105U  /*!< XSPI1 DATA2 pin */
#define DEV_SM_PIN_XSPI1_DATA3       106U  /*!< XSPI1 DATA3 pin */
#define DEV_SM_PIN_XSPI1_DATA4       107U  /*!< XSPI1 DATA4 pin */
#define DEV_SM_PIN_XSPI1_DATA5       108U  /*!< XSPI1 DATA5 pin */
#define DEV_SM_PIN_XSPI1_DATA6       109U  /*!< XSPI1 DATA6 pin */
#define DEV_SM_PIN_XSPI1_DATA7       110U  /*!< XSPI1 DATA7 pin */
#define DEV_SM_PIN_XSPI1_DQS         111U  /*!< XSPI1 DQS pin */
#define DEV_SM_PIN_XSPI1_SCLK        112U  /*!< XSPI1 SCLK pin */
#define DEV_SM_PIN_XSPI1_SS0_B       113U  /*!< XSPI1 SS0 B pin */
#define DEV_SM_PIN_XSPI1_SS1_B       114U  /*!< XSPI1 SS1 B pin */
#define DEV_SM_PIN_SD2_CD_B          115U  /*!< SD2 CD B pin */
#define DEV_SM_PIN_SD2_CLK           116U  /*!< SD2 CLK pin */
#define DEV_SM_PIN_SD2_CMD           117U  /*!< SD2 CMD pin */
#define DEV_SM_PIN_SD2_DATA0         118U  /*!< SD2 DATA0 pin */
#define DEV_SM_PIN_SD2_DATA1         119U  /*!< SD2 DATA1 pin */
#define DEV_SM_PIN_SD2_DATA2         120U  /*!< SD2 DATA2 pin */
#define DEV_SM_PIN_SD2_DATA3         121U  /*!< SD2 DATA3 pin */
#define DEV_SM_PIN_SD2_RESET_B       122U  /*!< SD2 RESET_B pin */
#define DEV_SM_PIN_I2C1_SCL          123U  /*!< I2C1 SCL pin */
#define DEV_SM_PIN_I2C1_SDA          124U  /*!< I2C1 SDA pin */
#define DEV_SM_PIN_I2C2_SCL          125U  /*!< I2C2 SCL pin */
#define DEV_SM_PIN_I2C2_SDA          126U  /*!< I2C2 SDA pin */
#define DEV_SM_PIN_UART1_RXD         127U  /*!< UART1 RXD pin */
#define DEV_SM_PIN_UART1_TXD         128U  /*!< UART1 TXD pin */
#define DEV_SM_PIN_UART2_RXD         129U  /*!< UART2 RXD pin */
#define DEV_SM_PIN_UART2_TXD         130U  /*!< UART2 TXD pin */
#define DEV_SM_PIN_PDM_CLK           131U  /*!< PDM CLK pin */
#define DEV_SM_PIN_PDM_BIT_STREAM0   132U  /*!< PDM BIT STREAM0 pin */
#define DEV_SM_PIN_PDM_BIT_STREAM1   133U  /*!< PDM BIT STREAM1 pin */
#define DEV_SM_PIN_SAI1_TXFS         134U  /*!< SAI1 TXFS pin */
#define DEV_SM_PIN_SAI1_TXC          135U  /*!< SAI1 TXC pin */
#define DEV_SM_PIN_SAI1_TXD0         136U  /*!< SAI1 TXD0 pin */
#define DEV_SM_PIN_SAI1_RXD0         137U  /*!< SAI1 RXD0 pin */
#define DEV_SM_PIN_WDOG_ANY          138U  /*!< WDOG ANY pin */
#define DEV_SM_PIN_FCCU_ERR0         139U  /*!< WDOG ANY pin */
/** @} */

/*!
 * @name Device pin daisy indexes
 */
/** @{ */
#define DEV_SM_DAISY_CAN1_RX                 0U  /*!< CAN1_RX */
#define DEV_SM_DAISY_PDM_BITSTREAM_0         1U  /*!< PDM_BITSTREAM_0 */
#define DEV_SM_DAISY_PDM_BITSTREAM_1         2U  /*!< PDM_BITSTREAM_1 */
#define DEV_SM_DAISY_PDM_BITSTREAM_2         3U  /*!< PDM_BITSTREAM_2 */
#define DEV_SM_DAISY_PDM_BITSTREAM_3         4U  /*!< PDM_BITSTREAM_3 */
#define DEV_SM_DAISY_SAI1_MCLK               5U  /*!< SAI1_MCLK */
#define DEV_SM_DAISY_EXT1_CLK                6U  /*!< EXT1_CLK */
#define DEV_SM_DAISY_USB1_OVERCURRENT        7U  /*!< USB1 OVERCURRENT */
#define DEV_SM_DAISY_USB2_OVERCURRENT        8U  /*!< USB2 OVERCURRENT */
#define DEV_SM_DAISY_NETC_EMDC               9U  /*!< EMDC_IN */
#define DEV_SM_DAISY_NETC_EMDIO              10U  /*!< EMDIO_IN */
#define DEV_SM_DAISY_NETC_ETH0_RMII_RX_ER    11U  /*!< NETC_ETH0_RMII_RX_ER */
#define DEV_SM_DAISY_NETC_ETH1_RMII_RX_ER    12U /*!< NETC_ETH1_RMII_RX_ER */
#define DEV_SM_DAISY_NETC_TMR_1588_TRIG1     13U /*!< NETCMIX_TMR_1588_TRIG1 */
#define DEV_SM_DAISY_NETC_TMR_1588_TRIG2     14U /*!< NETCMIX_TMR_1588_TRIG2 */
#define DEV_SM_DAISY_SAI2_RXDATA_6           15U /*!< SAI2_RXDATA_6 */
#define DEV_SM_DAISY_SAI2_RXDATA_7           16U /*!< SAI2_RXDATA_7 */
#define DEV_SM_DAISY_CAN2_RX                 17U /*!< CAN2_RX */
#define DEV_SM_DAISY_CAN3_RX                 18U /*!< CAN3_RX */
#define DEV_SM_DAISY_FLEXIO1_26              19U /*!< FLEXIO1_26 */
#define DEV_SM_DAISY_FLEXIO1_27              20U /*!< FLEXIO1_27 */
#define DEV_SM_DAISY_FLEXIO1_30              21U /*!< FLEXIO1_30 */
#define DEV_SM_DAISY_FLEXIO1_31              22U /*!< FLEXIO1_31 */
#define DEV_SM_DAISY_FLEXIO1_0               23U /*!< FLEXIO1_0 */
#define DEV_SM_DAISY_FLEXIO1_1               24U /*!< FLEXIO1_1 */
#define DEV_SM_DAISY_FLEXIO1_2               25U /*!< FLEXIO1_2 */
#define DEV_SM_DAISY_FLEXIO1_3               26U /*!< FLEXIO1_3 */
#define DEV_SM_DAISY_FLEXIO1_4               27U /*!< FLEXIO1_4 */
#define DEV_SM_DAISY_FLEXIO1_5               28U /*!< FLEXIO1_5 */
#define DEV_SM_DAISY_FLEXIO1_6               29U /*!< FLEXIO1_6 */
#define DEV_SM_DAISY_FLEXIO1_7               30U /*!< FLEXIO1_7 */
#define DEV_SM_DAISY_FLEXIO1_8               31U /*!< FLEXIO1_8 */
#define DEV_SM_DAISY_FLEXIO1_9               32U /*!< FLEXIO1_9 */
#define DEV_SM_DAISY_FLEXIO1_10              33U /*!< FLEXIO1_10 */
#define DEV_SM_DAISY_FLEXIO1_11              34U /*!< FLEXIO1_11 */
#define DEV_SM_DAISY_FLEXIO1_12              35U /*!< FLEXIO1_12 */
#define DEV_SM_DAISY_FLEXIO1_13              36U /*!< FLEXIO1_13 */
#define DEV_SM_DAISY_FLEXIO1_14              37U /*!< FLEXIO1_14 */
#define DEV_SM_DAISY_FLEXIO1_15              38U /*!< FLEXIO1_15 */
#define DEV_SM_DAISY_FLEXIO1_16              39U /*!< FLEXIO1_16 */
#define DEV_SM_DAISY_FLEXIO1_17              40U /*!< FLEXIO1_17 */
#define DEV_SM_DAISY_FLEXIO1_18              41U /*!< FLEXIO1_18 */
#define DEV_SM_DAISY_FLEXIO1_19              42U /*!< FLEXIO1_19 */
#define DEV_SM_DAISY_FLEXIO1_20              43U /*!< FLEXIO1_20 */
#define DEV_SM_DAISY_FLEXIO1_21              44U /*!< FLEXIO1_21 */
#define DEV_SM_DAISY_FLEXIO1_22              45U /*!< FLEXIO1_22 */
#define DEV_SM_DAISY_FLEXIO1_23              46U /*!< FLEXIO1_23 */
#define DEV_SM_DAISY_FLEXIO1_24              47U /*!< FLEXIO1_24 */
#define DEV_SM_DAISY_FLEXIO1_25              48U /*!< FLEXIO1_25 */
#define DEV_SM_DAISY_I3C2_SCL                49U /*!< I3C2_SCL_IN */
#define DEV_SM_DAISY_I3C2_SDA                50U /*!< I3C2_SDA_IN */
#define DEV_SM_DAISY_LPI2C3_SCL              51U /*!< LPI2C3_SCL */
#define DEV_SM_DAISY_LPI2C3_SDA              52U /*!< LPI2C3_SDA */
#define DEV_SM_DAISY_LPI2C4_SCL              53U /*!< LPI2C4_SCL */
#define DEV_SM_DAISY_LPI2C4_SDA              54U /*!< LPI2C4_SDA */
#define DEV_SM_DAISY_LPI2C5_SCL              55U /*!< LPI2C5_SCL */
#define DEV_SM_DAISY_LPI2C5_SDA              56U /*!< LPI2C5_SDA */
#define DEV_SM_DAISY_LPI2C6_SCL              57U /*!< LPI2C6_SCL */
#define DEV_SM_DAISY_LPI2C6_SDA              58U /*!< LPI2C6_SDA */
#define DEV_SM_DAISY_LPI2C7_SCL              59U /*!< LPI2C7_SCL */
#define DEV_SM_DAISY_LPI2C7_SDA              60U /*!< LPI2C7_SDA */
#define DEV_SM_DAISY_LPI2C8_SCL              61U /*!< LPI2C8_SCL */
#define DEV_SM_DAISY_LPI2C8_SDA              62U /*!< LPI2C8_SDA */
#define DEV_SM_DAISY_LPSPI4_PCS_0            63U /*!< LPSPI4_PCS_0 */
#define DEV_SM_DAISY_LPSPI4_PCS_1            64U /*!< LPSPI4_PCS_1 */
#define DEV_SM_DAISY_LPSPI4_PCS_2            65U /*!< LPSPI4_PCS_2 */
#define DEV_SM_DAISY_LPSPI4_SCK              66U /*!< LPSPI4_SCK */
#define DEV_SM_DAISY_LPSPI4_SDI              67U /*!< LPSPI4_SDI */
#define DEV_SM_DAISY_LPSPI4_SDO              68U /*!< LPSPI4_SDO */
#define DEV_SM_DAISY_LPTMR2_0                69U /*!< LPTMR2_0 */
#define DEV_SM_DAISY_LPTMR2_1                70U /*!< LPTMR2_1 */
#define DEV_SM_DAISY_LPTMR2_2                71U /*!< LPTMR2_2 */
#define DEV_SM_DAISY_LPUART3_CTS             72U /*!< LPUART3_CTS_N */
#define DEV_SM_DAISY_LPUART3_RXD             73U /*!< LPUART3_RXD */
#define DEV_SM_DAISY_LPUART3_TXD             74U /*!< LPUART3_TXD */
#define DEV_SM_DAISY_LPUART4_CTS             75U /*!< LPUART4_CTS_N */
#define DEV_SM_DAISY_LPUART4_RXD             76U /*!< LPUART4_RXD */
#define DEV_SM_DAISY_LPUART4_TXD             77U /*!< LPUART4_TXD */
#define DEV_SM_DAISY_LPUART5_CTS             78U /*!< LPUART5_CTS_N */
#define DEV_SM_DAISY_LPUART5_RXD             79U /*!< LPUART5_RXD */
#define DEV_SM_DAISY_LPUART5_TXD             80U /*!< LPUART5_TXD */
#define DEV_SM_DAISY_LPUART6_CTS             81U /*!< LPUART6_CTS_N */
#define DEV_SM_DAISY_LPUART6_RXD             82U /*!< LPUART6_RXD */
#define DEV_SM_DAISY_LPUART6_TXD             83U /*!< LPUART6_TXD */
#define DEV_SM_DAISY_LPUART7_RXD             84U /*!< LPUART7_RXD */
#define DEV_SM_DAISY_LPUART7_TXD             85U /*!< LPUART7_TXD */
#define DEV_SM_DAISY_SAI3_RXBCLK             86U /*!< SAI3_RXBCLK */
#define DEV_SM_DAISY_SAI3_RXSYNC             87U /*!< SAI3_RXSYNC */
#define DEV_SM_DAISY_SAI4_RXBCLK             88U /*!< SAI4_RXBCLK */
#define DEV_SM_DAISY_SAI4_RXDATA_0           89U /*!< SAI4_RXDATA_0 */
#define DEV_SM_DAISY_SAI4_RXSYNC             90U /*!< SAI4_RXSYNC */
#define DEV_SM_DAISY_SAI4_TXBCLK             91U /*!< SAI4_TXBCLK */
#define DEV_SM_DAISY_SAI4_TXSYNC             92U /*!< SAI4_TXSYNC */
#define DEV_SM_DAISY_SAI5_RXBCLK             93U /*!< SAI5_RXBCLK */
#define DEV_SM_DAISY_SAI5_RXDATA_0           94U /*!< SAI5_RXDATA_0 */
#define DEV_SM_DAISY_SAI5_RXDATA_1           95U /*!< SAI5_RXDATA_1 */
#define DEV_SM_DAISY_SAI5_RXDATA_2           96U /*!< SAI5_RXDATA_2 */
#define DEV_SM_DAISY_SAI5_RXDATA_3           97U /*!< SAI5_RXDATA_3 */
#define DEV_SM_DAISY_SAI5_RXSYNC             98U /*!< SAI5_RXSYNC */
#define DEV_SM_DAISY_SAI5_TXBCLK             99U /*!< SAI5_TXBCLK */
#define DEV_SM_DAISY_SAI5_TXSYNC             100U /*!< SAI5_TXSYNC */
#define DEV_SM_DAISY_SAI6_LOOPBACK_RXDATA_0  101U /*!< SAI6_LOOPBACK_RXDATA_0 */
#define DEV_SM_DAISY_TLM_TCK                 102U /*!< TLM_TCK */
#define DEV_SM_DAISY_TLM_TDI                 103U /*!< TLM_TDI */
#define DEV_SM_DAISY_TLM_TMS                 104U /*!< TLM_TMS */
#define DEV_SM_DAISY_USDHC3_CLK              105U /*!< USDHC3_CARD_CLK_IN */
#define DEV_SM_DAISY_USDHC3_CMD              106U /*!< USDHC3_CMD_IN */
#define DEV_SM_DAISY_USDHC3_DAT0             107U /*!< USDHC3_DAT0_IN */
#define DEV_SM_DAISY_USDHC3_DAT1             108U /*!< USDHC3_DAT1_IN */
#define DEV_SM_DAISY_USDHC3_DAT2             109U /*!< USDHC3_DAT2_IN */
#define DEV_SM_DAISY_USDHC3_DAT3             110U /*!< USDHC3_DAT3_IN */
#define DEV_SM_DAISY_XSPI1_CK_FA_P           111U /*!< XSPI1_CK_FA_P */
#define DEV_SM_DAISY_XSPI1_DQS_FA            112U /*!< XSPI1_DQS_FA */
#define DEV_SM_DAISY_XSPI1_INTFA_B           113U /*!< XSPI1_INTFA_B */
#define DEV_SM_DAISY_XSPI1_IO_FA_0           114U /*!< XSPI1_IO_FA_0 */
#define DEV_SM_DAISY_XSPI1_IO_FA_1           115U /*!< XSPI1_IO_FA_1 */
#define DEV_SM_DAISY_XSPI1_IO_FA_2           116U /*!< XSPI1_IO_FA_2 */
#define DEV_SM_DAISY_XSPI1_IO_FA_3           117U /*!< XSPI1_IO_FA_3 */
#define DEV_SM_DAISY_XSPI1_IO_FA_4           118U /*!< XSPI1_IO_FA_4 */
#define DEV_SM_DAISY_XSPI1_IO_FA_5           119U /*!< XSPI1_IO_FA_5 */
#define DEV_SM_DAISY_XSPI1_IO_FA_6           120U /*!< XSPI1_IO_FA_6 */
#define DEV_SM_DAISY_XSPI1_IO_FA_7           121U /*!< XSPI1_IO_FA_7 */
#define DEV_SM_DAISY_XSPI1_PCS_FA1_B         122U /*!< XSPI1_PCS_FA1_B */
#define DEV_SM_DAISY_XSPI1_PCS_FA2_B         123U /*!< XSPI1_PCS_FA2_B */
#define DEV_SM_DAISY_XSPI_CS                 124U /*!< XSPI_CS */
#define DEV_SM_DAISY_XSPI_DQS                125U /*!< XSPI_DQS */
#define DEV_SM_DAISY_XSPI_SCK                126U /*!< XSPI_SCK */
#define DEV_SM_DAISY_XSPI_SLV_IO_0           127U /*!< XSPI_SLV_IO_0 */
#define DEV_SM_DAISY_XSPI_SLV_IO_1           128U /*!< XSPI_SLV_IO_1 */
#define DEV_SM_DAISY_XSPI_SLV_IO_2           129U /*!< XSPI_SLV_IO_2 */
#define DEV_SM_DAISY_XSPI_SLV_IO_3           130U /*!< XSPI_SLV_IO_3 */
#define DEV_SM_DAISY_XSPI_SLV_IO_4           131U /*!< XSPI_SLV_IO_4 */
#define DEV_SM_DAISY_XSPI_SLV_IO_5           132U /*!< XSPI_SLV_IO_5 */
#define DEV_SM_DAISY_XSPI_SLV_IO_6           133U /*!< XSPI_SLV_IO_6 */
#define DEV_SM_DAISY_XSPI_SLV_IO_7           134U /*!< XSPI_SLV_IO_7 */
/** @} */

/*!
 * @name Device pin config types
 */
/** @{ */
#define DEV_SM_PIN_TYPE_MUX     0U  /*!< Pin mux */
#define DEV_SM_PIN_TYPE_CONFIG  1U  /*!< Pin config */
#define DEV_SM_PIN_TYPE_DAISY   2U  /*!< Pin daisy */
#define DEV_SM_PIN_TYPE_EXT     3U  /*!< Pin extended */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

/* coverity[misra_c_2012_rule_20_1_violation] */
#include "dev_sm_pin_api.h"

#endif /* DEV_SM_PIN_H */

