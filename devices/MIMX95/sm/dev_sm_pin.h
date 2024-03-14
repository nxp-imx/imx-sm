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

#ifndef DEV_SM_PIN_H
#define DEV_SM_PIN_H

/*==========================================================================*/
/*!
 * @addtogroup DEV_SM_MX95_PIN
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
#define DEV_SM_NUM_PIN    129U

/*! Number of device daisy */
#define DEV_SM_NUM_DAISY  132U

/*!
 * @name Device pin indexes
 *
 * See the IOMUXC register list in the i.MX95 RM.
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
#define DEV_SM_PIN_CCM_CLKO1         42U   /*!< CCM CLKO1 pin */
#define DEV_SM_PIN_CCM_CLKO2         43U   /*!< CCM CLKO2 pin */
#define DEV_SM_PIN_CCM_CLKO3         44U   /*!< CCM CLKO3 pin */
#define DEV_SM_PIN_CCM_CLKO4         45U   /*!< CCM CLKO4 pin */
#define DEV_SM_PIN_ENET1_MDC         46U   /*!< ENET1 MDC pin */
#define DEV_SM_PIN_ENET1_MDIO        47U   /*!< ENET1 MDIO pin */
#define DEV_SM_PIN_ENET1_TD3         48U   /*!< ENET1 TD3 pin */
#define DEV_SM_PIN_ENET1_TD2         49U   /*!< ENET1 TD2 pin */
#define DEV_SM_PIN_ENET1_TD1         50U   /*!< ENET1 TD1 pin */
#define DEV_SM_PIN_ENET1_TD0         51U   /*!< ENET1 TD0 pin */
#define DEV_SM_PIN_ENET1_TX_CTL      52U   /*!< ENET1 TX CTL pin */
#define DEV_SM_PIN_ENET1_TXC         53U   /*!< ENET1 TXC pin */
#define DEV_SM_PIN_ENET1_RX_CTL      54U   /*!< ENET1 RX CTL pin */
#define DEV_SM_PIN_ENET1_RXC         55U   /*!< ENET1 RXC pin */
#define DEV_SM_PIN_ENET1_RD0         56U   /*!< ENET1 RD0 pin */
#define DEV_SM_PIN_ENET1_RD1         57U   /*!< ENET1 RD1 pin */
#define DEV_SM_PIN_ENET1_RD2         58U   /*!< ENET1 RD2 pin */
#define DEV_SM_PIN_ENET1_RD3         59U   /*!< ENET1 RD3 pin */
#define DEV_SM_PIN_ENET2_MDC         60U   /*!< ENET2 MDC pin */
#define DEV_SM_PIN_ENET2_MDIO        61U   /*!< ENET2 MDIO pin */
#define DEV_SM_PIN_ENET2_TD3         62U   /*!< ENET2 TD3 pin */
#define DEV_SM_PIN_ENET2_TD2         63U   /*!< ENET2 TD2 pin */
#define DEV_SM_PIN_ENET2_TD1         64U   /*!< ENET2 TD1 pin */
#define DEV_SM_PIN_ENET2_TD0         65U   /*!< ENET2 TD0 pin */
#define DEV_SM_PIN_ENET2_TX_CTL      66U   /*!< ENET2 TX CTL pin */
#define DEV_SM_PIN_ENET2_TXC         67U   /*!< ENET2 TXC pin */
#define DEV_SM_PIN_ENET2_RX_CTL      68U   /*!< ENET2 RX CTL pin */
#define DEV_SM_PIN_ENET2_RXC         69U   /*!< ENET2 RXC pin */
#define DEV_SM_PIN_ENET2_RD0         70U   /*!< ENET2 RD0 pin */
#define DEV_SM_PIN_ENET2_RD1         71U   /*!< ENET2 RD1 pin */
#define DEV_SM_PIN_ENET2_RD2         72U   /*!< ENET2 RD2 pin */
#define DEV_SM_PIN_ENET2_RD3         73U   /*!< ENET2 RD3 pin */
#define DEV_SM_PIN_SD1_CLK           74U   /*!< SD1 CLK pin */
#define DEV_SM_PIN_SD1_CMD           75U   /*!< SD1 CMD pin */
#define DEV_SM_PIN_SD1_DATA0         76U   /*!< SD1 DATA0 pin */
#define DEV_SM_PIN_SD1_DATA1         77U   /*!< SD1 DATA1 pin */
#define DEV_SM_PIN_SD1_DATA2         78U   /*!< SD1 DATA2 pin */
#define DEV_SM_PIN_SD1_DATA3         79U   /*!< SD1 DATA3 pin */
#define DEV_SM_PIN_SD1_DATA4         80U   /*!< SD1 DATA4 pin */
#define DEV_SM_PIN_SD1_DATA5         81U   /*!< SD1 DATA5 pin */
#define DEV_SM_PIN_SD1_DATA6         82U   /*!< SD1 DATA6 pin */
#define DEV_SM_PIN_SD1_DATA7         83U   /*!< SD1 DATA7 pin */
#define DEV_SM_PIN_SD1_STROBE        84U   /*!< SD1 STROBE pin */
#define DEV_SM_PIN_SD2_VSELECT       85U   /*!< SD2 VSELECT pin */
#define DEV_SM_PIN_SD3_CLK           86U   /*!< SD3 CLK pin */
#define DEV_SM_PIN_SD3_CMD           87U   /*!< SD3 CMD pin */
#define DEV_SM_PIN_SD3_DATA0         88U   /*!< SD3 DATA0 pin */
#define DEV_SM_PIN_SD3_DATA1         89U   /*!< SD3 DATA1 pin */
#define DEV_SM_PIN_SD3_DATA2         90U   /*!< SD3 DATA2 pin */
#define DEV_SM_PIN_SD3_DATA3         91U   /*!< SD3 DATA3 pin */
#define DEV_SM_PIN_XSPI1_DATA0       92U   /*!< XSPI1 DATA0 pin */
#define DEV_SM_PIN_XSPI1_DATA1       93U   /*!< XSPI1 DATA1 pin */
#define DEV_SM_PIN_XSPI1_DATA2       94U   /*!< XSPI1 DATA2 pin */
#define DEV_SM_PIN_XSPI1_DATA3       95U   /*!< XSPI1 DATA3 pin */
#define DEV_SM_PIN_XSPI1_DATA4       96U   /*!< XSPI1 DATA4 pin */
#define DEV_SM_PIN_XSPI1_DATA5       97U   /*!< XSPI1 DATA5 pin */
#define DEV_SM_PIN_XSPI1_DATA6       98U   /*!< XSPI1 DATA6 pin */
#define DEV_SM_PIN_XSPI1_DATA7       99U   /*!< XSPI1 DATA7 pin */
#define DEV_SM_PIN_XSPI1_DQS         100U  /*!< XSPI1 DQS pin */
#define DEV_SM_PIN_XSPI1_SCLK        101U  /*!< XSPI1 SCLK pin */
#define DEV_SM_PIN_XSPI1_SS0_B       102U  /*!< XSPI1 SS0 B pin */
#define DEV_SM_PIN_XSPI1_SS1_B       103U  /*!< XSPI1 SS1 B pin */
#define DEV_SM_PIN_SD2_CD_B          104U  /*!< SD2 CD B pin */
#define DEV_SM_PIN_SD2_CLK           105U  /*!< SD2 CLK pin */
#define DEV_SM_PIN_SD2_CMD           106U  /*!< SD2 CMD pin */
#define DEV_SM_PIN_SD2_DATA0         107U  /*!< SD2 DATA0 pin */
#define DEV_SM_PIN_SD2_DATA1         108U  /*!< SD2 DATA1 pin */
#define DEV_SM_PIN_SD2_DATA2         109U  /*!< SD2 DATA2 pin */
#define DEV_SM_PIN_SD2_DATA3         110U  /*!< SD2 DATA3 pin */
#define DEV_SM_PIN_SD2_RESET_B       111U  /*!< SD2 RESET B pin */
#define DEV_SM_PIN_I2C1_SCL          112U  /*!< I2C1 SCL pin */
#define DEV_SM_PIN_I2C1_SDA          113U  /*!< I2C1 SDA pin */
#define DEV_SM_PIN_I2C2_SCL          114U  /*!< I2C2 SCL pin */
#define DEV_SM_PIN_I2C2_SDA          115U  /*!< I2C2 SDA pin */
#define DEV_SM_PIN_UART1_RXD         116U  /*!< UART1 RXD pin */
#define DEV_SM_PIN_UART1_TXD         117U  /*!< UART1 TXD pin */
#define DEV_SM_PIN_UART2_RXD         118U  /*!< UART2 RXD pin */
#define DEV_SM_PIN_UART2_TXD         119U  /*!< UART2 TXD pin */
#define DEV_SM_PIN_PDM_CLK           120U  /*!< PDM CLK pin */
#define DEV_SM_PIN_PDM_BIT_STREAM0   121U  /*!< PDM BIT STREAM0 pin */
#define DEV_SM_PIN_PDM_BIT_STREAM1   122U  /*!< PDM BIT STREAM1 pin */
#define DEV_SM_PIN_SAI1_TXFS         123U  /*!< SAI1 TXFS pin */
#define DEV_SM_PIN_SAI1_TXC          124U  /*!< SAI1 TXC pin */
#define DEV_SM_PIN_SAI1_TXD0         125U  /*!< SAI1 TXD0 pin */
#define DEV_SM_PIN_SAI1_RXD0         126U  /*!< SAI1 RXD0 pin */
#define DEV_SM_PIN_WDOG_ANY          127U  /*!< WDOG ANY pin */
#define DEV_SM_PIN_FCCU_ERR0         128U  /*!< FCCU ERR0 pin */
/** @} */

/*!
 * @name Device pin daisy indexes
 */
/** @{ */
#define DEV_SM_DAISY_CAN1_RX               0U    /*!< CAN1 RX daisy */
#define DEV_SM_DAISY_PDM_BITSTREAM_0       1U    /*!< PDM BITSTREAM 0 daisy */
#define DEV_SM_DAISY_PDM_BITSTREAM_1       2U    /*!< PDM BITSTREAM 1 daisy */
#define DEV_SM_DAISY_PDM_BITSTREAM_2       3U    /*!< PDM BITSTREAM 2 daisy */
#define DEV_SM_DAISY_PDM_BITSTREAM_3       4U    /*!< PDM BITSTREAM 3 daisy */
#define DEV_SM_DAISY_SAI1_MCLK             5U    /*!< SAI1 MCLK daisy */
#define DEV_SM_DAISY_EXT1_CLK              6U    /*!< EXT1 CLK daisy */
#define DEV_SM_DAISY_NETC_EMDC             7U    /*!< NETC EMDC daisy */
#define DEV_SM_DAISY_NETC_EMDIO            8U    /*!< NETC EMDIO daisy */
#define DEV_SM_DAISY_NETC_ETH0_RMII_RX_ER  9U    /*!< NETC ETH0 RMII RX ER daisy */
#define DEV_SM_DAISY_NETC_ETH1_RMII_RX_ER  10U   /*!< NETC ETH1 RMII RX ER daisy */
#define DEV_SM_DAISY_NETC_TMR_1588_TRIG1   11U   /*!< NETC TMR 1588 TRIG1 daisy */
#define DEV_SM_DAISY_NETC_TMR_1588_TRIG2   12U   /*!< NETC TMR 1588 TRIG2 daisy */
#define DEV_SM_DAISY_SAI2_RXDATA_6         13U   /*!< SAI2 RXDATA 6 daisy */
#define DEV_SM_DAISY_SAI2_RXDATA_7         14U   /*!< SAI2 RXDATA 7 daisy */
#define DEV_SM_DAISY_CAN2_RX               15U   /*!< CAN2 RX daisy */
#define DEV_SM_DAISY_CAN3_RX               16U   /*!< CAN3 RX daisy */
#define DEV_SM_DAISY_CAN4_RX               17U   /*!< CAN4 RX daisy */
#define DEV_SM_DAISY_CAN5_RX               18U   /*!< CAN5 RX daisy */
#define DEV_SM_DAISY_EARC_PHY_SPDIF        19U   /*!< EARC PHY SPDIF daisy */
#define DEV_SM_DAISY_FLEXIO1_26            20U   /*!< FLEXIO1 26 daisy */
#define DEV_SM_DAISY_FLEXIO1_27            21U   /*!< FLEXIO1 27 daisy */
#define DEV_SM_DAISY_FLEXIO1_30            22U   /*!< FLEXIO1 30 daisy */
#define DEV_SM_DAISY_FLEXIO1_31            23U   /*!< FLEXIO1 31 daisy */
#define DEV_SM_DAISY_FLEXIO1_0             24U   /*!< FLEXIO1 0 daisy */
#define DEV_SM_DAISY_FLEXIO1_1             25U   /*!< FLEXIO1 1 daisy */
#define DEV_SM_DAISY_FLEXIO1_2             26U   /*!< FLEXIO1 2 daisy */
#define DEV_SM_DAISY_FLEXIO1_3             27U   /*!< FLEXIO1 3 daisy */
#define DEV_SM_DAISY_FLEXIO1_4             28U   /*!< FLEXIO1 4 daisy */
#define DEV_SM_DAISY_FLEXIO1_5             29U   /*!< FLEXIO1 5 daisy */
#define DEV_SM_DAISY_FLEXIO1_6             30U   /*!< FLEXIO1 6 daisy */
#define DEV_SM_DAISY_FLEXIO1_7             31U   /*!< FLEXIO1 7 daisy */
#define DEV_SM_DAISY_FLEXIO1_8             32U   /*!< FLEXIO1 8 daisy */
#define DEV_SM_DAISY_FLEXIO1_9             33U   /*!< FLEXIO1 9 daisy */
#define DEV_SM_DAISY_FLEXIO1_10            34U   /*!< FLEXIO1 10 daisy */
#define DEV_SM_DAISY_FLEXIO1_11            35U   /*!< FLEXIO1 11 daisy */
#define DEV_SM_DAISY_FLEXIO1_12            36U   /*!< FLEXIO1 12 daisy */
#define DEV_SM_DAISY_FLEXIO1_13            37U   /*!< FLEXIO1 13 daisy */
#define DEV_SM_DAISY_FLEXIO1_14            38U   /*!< FLEXIO1 14 daisy */
#define DEV_SM_DAISY_FLEXIO1_15            39U   /*!< FLEXIO1 15 daisy */
#define DEV_SM_DAISY_FLEXIO1_16            40U   /*!< FLEXIO1 16 daisy */
#define DEV_SM_DAISY_FLEXIO1_17            41U   /*!< FLEXIO1 17 daisy */
#define DEV_SM_DAISY_FLEXIO1_18            42U   /*!< FLEXIO1 18 daisy */
#define DEV_SM_DAISY_FLEXIO1_19            43U   /*!< FLEXIO1 19 daisy */
#define DEV_SM_DAISY_FLEXIO1_20            44U   /*!< FLEXIO1 20 daisy */
#define DEV_SM_DAISY_FLEXIO1_21            45U   /*!< FLEXIO1 21 daisy */
#define DEV_SM_DAISY_FLEXIO1_22            46U   /*!< FLEXIO1 22 daisy */
#define DEV_SM_DAISY_FLEXIO1_23            47U   /*!< FLEXIO1 23 daisy */
#define DEV_SM_DAISY_FLEXIO1_24            48U   /*!< FLEXIO1 24 daisy */
#define DEV_SM_DAISY_FLEXIO1_25            49U   /*!< FLEXIO1 25 daisy */
#define DEV_SM_DAISY_FLEXSPI1_DQS          50U   /*!< FLEXSPI1 DQS daisy */
#define DEV_SM_DAISY_FLEXSPI1_0            51U   /*!< FLEXSPI1 0 daisy */
#define DEV_SM_DAISY_FLEXSPI1_1            52U   /*!< FLEXSPI1 1 daisy */
#define DEV_SM_DAISY_FLEXSPI1_2            53U   /*!< FLEXSPI1 2 daisy */
#define DEV_SM_DAISY_FLEXSPI1_3            54U   /*!< FLEXSPI1 3 daisy */
#define DEV_SM_DAISY_FLEXSPI1_4            55U   /*!< FLEXSPI1 4 daisy */
#define DEV_SM_DAISY_FLEXSPI1_5            56U   /*!< FLEXSPI1 5 daisy */
#define DEV_SM_DAISY_FLEXSPI1_6            57U   /*!< FLEXSPI1 6 daisy */
#define DEV_SM_DAISY_FLEXSPI1_7            58U   /*!< FLEXSPI1 7 daisy */
#define DEV_SM_DAISY_FLEXSPI1_SCK          59U   /*!< FLEXSPI1 SCK daisy */
#define DEV_SM_DAISY_I3C2_SCL              60U   /*!< I3C2 SCL daisy */
#define DEV_SM_DAISY_I3C2_SDA              61U   /*!< I3C2 SDA daisy */
#define DEV_SM_DAISY_LPI2C3_SCL            62U   /*!< LPI2C3 SCL daisy */
#define DEV_SM_DAISY_LPI2C3_SDA            63U   /*!< LPI2C3 SDA daisy */
#define DEV_SM_DAISY_LPI2C4_SCL            64U   /*!< LPI2C4 SCL daisy */
#define DEV_SM_DAISY_LPI2C4_SDA            65U   /*!< LPI2C4 SDA daisy */
#define DEV_SM_DAISY_LPI2C5_SCL            66U   /*!< LPI2C5 SCL daisy */
#define DEV_SM_DAISY_LPI2C5_SDA            67U   /*!< LPI2C5 SDA daisy */
#define DEV_SM_DAISY_LPI2C6_SCL            68U   /*!< LPI2C6 SCL daisy */
#define DEV_SM_DAISY_LPI2C6_SDA            69U   /*!< LPI2C6 SDA daisy */
#define DEV_SM_DAISY_LPI2C7_SCL            70U   /*!< LPI2C7 SCL daisy */
#define DEV_SM_DAISY_LPI2C7_SDA            71U   /*!< LPI2C7 SDA daisy */
#define DEV_SM_DAISY_LPI2C8_SCL            72U   /*!< LPI2C8 SCL daisy */
#define DEV_SM_DAISY_LPI2C8_SDA            73U   /*!< LPI2C8 SDA daisy */
#define DEV_SM_DAISY_LPSPI4_PCS_0          74U   /*!< LPSPI4 PCS 0 daisy */
#define DEV_SM_DAISY_LPSPI4_PCS_1          75U   /*!< LPSPI4 PCS 1 daisy */
#define DEV_SM_DAISY_LPSPI4_PCS_2          76U   /*!< LPSPI4 PCS 2 daisy */
#define DEV_SM_DAISY_LPSPI4_SCK            77U   /*!< LPSPI4 SCK daisy */
#define DEV_SM_DAISY_LPSPI4_SDI            78U   /*!< LPSPI4 SDI daisy */
#define DEV_SM_DAISY_LPSPI4_SDO            79U   /*!< LPSPI4 SDO daisy */
#define DEV_SM_DAISY_LPTMR2_0              80U   /*!< LPTMR2 0 daisy */
#define DEV_SM_DAISY_LPTMR2_1              81U   /*!< LPTMR2 1 daisy */
#define DEV_SM_DAISY_LPTMR2_2              82U   /*!< LPTMR2 2 daisy */
#define DEV_SM_DAISY_LPUART3_CTS           83U   /*!< LPUART3 CTS daisy */
#define DEV_SM_DAISY_LPUART3_RXD           84U   /*!< LPUART3 RXD daisy */
#define DEV_SM_DAISY_LPUART3_TXD           85U   /*!< LPUART3 TXD daisy */
#define DEV_SM_DAISY_LPUART4_CTS           86U   /*!< LPUART4 CTS daisy */
#define DEV_SM_DAISY_LPUART4_RXD           87U   /*!< LPUART4 RXD daisy */
#define DEV_SM_DAISY_LPUART4_TXD           88U   /*!< LPUART4 TXD daisy */
#define DEV_SM_DAISY_LPUART5_CTS           89U   /*!< LPUART5 CTS daisy */
#define DEV_SM_DAISY_LPUART5_RXD           90U   /*!< LPUART5 RXD daisy */
#define DEV_SM_DAISY_LPUART5_TXD           91U   /*!< LPUART5 TXD daisy */
#define DEV_SM_DAISY_LPUART6_CTS           92U   /*!< LPUART6 CTS daisy */
#define DEV_SM_DAISY_LPUART6_RXD           93U   /*!< LPUART6 RXD daisy */
#define DEV_SM_DAISY_LPUART6_TXD           94U   /*!< LPUART6 TXD daisy */
#define DEV_SM_DAISY_LPUART7_RXD           95U   /*!< LPUART7 RXD daisy */
#define DEV_SM_DAISY_LPUART7_TXD           96U   /*!< LPUART7 TXD daisy */
#define DEV_SM_DAISY_SAI3_RXBCLK           97U   /*!< SAI3 RXBCLK daisy */
#define DEV_SM_DAISY_SAI3_RXSYNC           98U   /*!< SAI3 RXSYNC daisy */
#define DEV_SM_DAISY_SAI4_RXBCLK           99U   /*!< SAI4 RXBCLK daisy */
#define DEV_SM_DAISY_SAI4_RXDATA_0         100U  /*!< SAI4 RXDATA 0 daisy */
#define DEV_SM_DAISY_SAI4_RXSYNC           101U  /*!< SAI4 RXSYNC daisy */
#define DEV_SM_DAISY_SAI4_TXBCLK           102U  /*!< SAI4 TXBCLK daisy */
#define DEV_SM_DAISY_SAI4_TXSYNC           103U  /*!< SAI4 TXSYNC daisy */
#define DEV_SM_DAISY_SAI5_RXBCLK           104U  /*!< SAI5 RXBCLK daisy */
#define DEV_SM_DAISY_SAI5_RXDATA_0         105U  /*!< SAI5 RXDATA 0 daisy */
#define DEV_SM_DAISY_SAI5_RXDATA_1         106U  /*!< SAI5 RXDATA 1 daisy */
#define DEV_SM_DAISY_SAI5_RXDATA_2         107U  /*!< SAI5 RXDATA 2 daisy */
#define DEV_SM_DAISY_SAI5_RXDATA_3         108U  /*!< SAI5 RXDATA 3 daisy */
#define DEV_SM_DAISY_SAI5_RXSYNC           109U  /*!< SAI5 RXSYNC daisy */
#define DEV_SM_DAISY_SAI5_TXBCLK           110U  /*!< SAI5 TXBCLK daisy */
#define DEV_SM_DAISY_SAI5_TXSYNC           111U  /*!< SAI5 TXSYNC daisy */
#define DEV_SM_DAISY_USDHC3_CLK            112U  /*!< USDHC3 CLK daisy */
#define DEV_SM_DAISY_USDHC3_CMD            113U  /*!< USDHC3 CMD daisy */
#define DEV_SM_DAISY_USDHC3_DAT0           114U  /*!< USDHC3 DAT0 daisy */
#define DEV_SM_DAISY_USDHC3_DAT1           115U  /*!< USDHC3 DAT1 daisy */
#define DEV_SM_DAISY_USDHC3_DAT2           116U  /*!< USDHC3 DAT2 daisy */
#define DEV_SM_DAISY_USDHC3_DAT3           117U  /*!< USDHC3 DAT3 daisy */
#define DEV_SM_DAISY_XSPI_CS               118U  /*!< XSPI CS daisy */
#define DEV_SM_DAISY_XSPI_DQS              119U  /*!< XSPI DQS daisy */
#define DEV_SM_DAISY_XSPI_SCK              120U  /*!< XSPI SCK daisy */
#define DEV_SM_DAISY_XSPI_0                121U  /*!< XSPI 0 daisy */
#define DEV_SM_DAISY_XSPI_1                122U  /*!< XSPI 1 daisy */
#define DEV_SM_DAISY_XSPI_2                123U  /*!< XSPI 2 daisy */
#define DEV_SM_DAISY_XSPI_3                124U  /*!< XSPI 3 daisy */
#define DEV_SM_DAISY_XSPI_4                125U  /*!< XSPI 4 daisy */
#define DEV_SM_DAISY_XSPI_5                126U  /*!< XSPI 5 daisy */
#define DEV_SM_DAISY_XSPI_6                127U  /*!< XSPI 6 daisy */
#define DEV_SM_DAISY_XSPI_7                128U  /*!< XSPI 7 daisy */
#define DEV_SM_DAISY_JTAG_TCK              139U  /*!< JTAG TCK daisy */
#define DEV_SM_DAISY_JTAG_TDI              130U  /*!< JTAG TDI daisy */
#define DEV_SM_DAISY_JTAG_TMS              131U  /*!< JTAG TMS daisy */
/** @} */

/*!
 * @name Device pin config types
 */
/** @{ */
#define DEV_SM_PIN_TYPE_MUX     0U  /*!< Pin mux */
#define DEV_SM_PIN_TYPE_CONFIG  1U  /*!< Pin config */
#define DEV_SM_PIN_TYPE_DAISY   2U  /*!< Pin daisy */
/** @} */

/* Types */

/* Functions */

/** @} */

/* Include SM device API */

// coverity[misra_c_2012_rule_20_1_violation:FALSE]
#include "dev_sm_pin_api.h"

#endif /* DEV_SM_PIN_H */

