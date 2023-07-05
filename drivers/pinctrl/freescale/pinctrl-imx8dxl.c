// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright 2019~2020 NXP
 */

#include <dt-bindings/pinctrl/pads-imx8dxl.h>
#include <linux/err.h>
#include <linux/firmware/imx/sci.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/pinctrl/pinctrl.h>

#include "pinctrl-imx.h"

static const struct pinctrl_pin_desc imx8dxl_pinctrl_pads[] = {
	IMX_PINCTRL_PIN(IMX8DXL_PCIE_CTRL0_PERST_B),
	IMX_PINCTRL_PIN(IMX8DXL_PCIE_CTRL0_CLKREQ_B),
	IMX_PINCTRL_PIN(IMX8DXL_PCIE_CTRL0_WAKE_B),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_PCIESEP),
	IMX_PINCTRL_PIN(IMX8DXL_USB_SS3_TC0),
	IMX_PINCTRL_PIN(IMX8DXL_USB_SS3_TC1),
	IMX_PINCTRL_PIN(IMX8DXL_USB_SS3_TC2),
	IMX_PINCTRL_PIN(IMX8DXL_USB_SS3_TC3),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_3V3_USB3IO),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_CLK),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_CMD),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_DATA0),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_DATA1),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_DATA2),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_DATA3),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_DATA4),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_DATA5),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_DATA6),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_DATA7),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_STROBE),
	IMX_PINCTRL_PIN(IMX8DXL_EMMC0_RESET_B),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_SD1FIX0),
	IMX_PINCTRL_PIN(IMX8DXL_USDHC1_RESET_B),
	IMX_PINCTRL_PIN(IMX8DXL_USDHC1_VSELECT),
	IMX_PINCTRL_PIN(IMX8DXL_CTL_NAND_RE_P_N),
	IMX_PINCTRL_PIN(IMX8DXL_USDHC1_WP),
	IMX_PINCTRL_PIN(IMX8DXL_USDHC1_CD_B),
	IMX_PINCTRL_PIN(IMX8DXL_CTL_NAND_DQS_P_N),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_VSELSEP),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_TXC),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_TX_CTL),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_TXD0),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_TXD1),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_TXD2),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_TXD3),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_ENET_ENETB0),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_RXC),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_RX_CTL),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_RXD0),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_RXD1),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_RXD2),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_RGMII_RXD3),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_ENET_ENETB1),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_REFCLK_125M_25M),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_MDIO),
	IMX_PINCTRL_PIN(IMX8DXL_ENET0_MDC),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_GPIOCT),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_TXC),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_TXD2),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_TX_CTL),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_TXD3),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_RXC),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_RXD3),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_RXD2),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_RXD1),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_TXD0),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_TXD1),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_RXD0),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_RGMII_RX_CTL),
	IMX_PINCTRL_PIN(IMX8DXL_ENET1_REFCLK_125M_25M),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_GPIORHB),
	IMX_PINCTRL_PIN(IMX8DXL_SPI3_SCK),
	IMX_PINCTRL_PIN(IMX8DXL_SPI3_SDO),
	IMX_PINCTRL_PIN(IMX8DXL_SPI3_SDI),
	IMX_PINCTRL_PIN(IMX8DXL_SPI3_CS0),
	IMX_PINCTRL_PIN(IMX8DXL_SPI3_CS1),
	IMX_PINCTRL_PIN(IMX8DXL_MCLK_IN1),
	IMX_PINCTRL_PIN(IMX8DXL_MCLK_IN0),
	IMX_PINCTRL_PIN(IMX8DXL_MCLK_OUT0),
	IMX_PINCTRL_PIN(IMX8DXL_UART1_TX),
	IMX_PINCTRL_PIN(IMX8DXL_UART1_RX),
	IMX_PINCTRL_PIN(IMX8DXL_UART1_RTS_B),
	IMX_PINCTRL_PIN(IMX8DXL_UART1_CTS_B),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_GPIORHK),
	IMX_PINCTRL_PIN(IMX8DXL_SPI0_SCK),
	IMX_PINCTRL_PIN(IMX8DXL_SPI0_SDI),
	IMX_PINCTRL_PIN(IMX8DXL_SPI0_SDO),
	IMX_PINCTRL_PIN(IMX8DXL_SPI0_CS1),
	IMX_PINCTRL_PIN(IMX8DXL_SPI0_CS0),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_GPIORHT),
	IMX_PINCTRL_PIN(IMX8DXL_ADC_IN1),
	IMX_PINCTRL_PIN(IMX8DXL_ADC_IN0),
	IMX_PINCTRL_PIN(IMX8DXL_ADC_IN3),
	IMX_PINCTRL_PIN(IMX8DXL_ADC_IN2),
	IMX_PINCTRL_PIN(IMX8DXL_ADC_IN5),
	IMX_PINCTRL_PIN(IMX8DXL_ADC_IN4),
	IMX_PINCTRL_PIN(IMX8DXL_FLEXCAN0_RX),
	IMX_PINCTRL_PIN(IMX8DXL_FLEXCAN0_TX),
	IMX_PINCTRL_PIN(IMX8DXL_FLEXCAN1_RX),
	IMX_PINCTRL_PIN(IMX8DXL_FLEXCAN1_TX),
	IMX_PINCTRL_PIN(IMX8DXL_FLEXCAN2_RX),
	IMX_PINCTRL_PIN(IMX8DXL_FLEXCAN2_TX),
	IMX_PINCTRL_PIN(IMX8DXL_UART0_RX),
	IMX_PINCTRL_PIN(IMX8DXL_UART0_TX),
	IMX_PINCTRL_PIN(IMX8DXL_UART2_TX),
	IMX_PINCTRL_PIN(IMX8DXL_UART2_RX),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_GPIOLH),
	IMX_PINCTRL_PIN(IMX8DXL_JTAG_TRST_B),
	IMX_PINCTRL_PIN(IMX8DXL_PMIC_I2C_SCL),
	IMX_PINCTRL_PIN(IMX8DXL_PMIC_I2C_SDA),
	IMX_PINCTRL_PIN(IMX8DXL_PMIC_INT_B),
	IMX_PINCTRL_PIN(IMX8DXL_SCU_GPIO0_00),
	IMX_PINCTRL_PIN(IMX8DXL_SCU_GPIO0_01),
	IMX_PINCTRL_PIN(IMX8DXL_SCU_PMIC_STANDBY),
	IMX_PINCTRL_PIN(IMX8DXL_SCU_BOOT_MODE1),
	IMX_PINCTRL_PIN(IMX8DXL_SCU_BOOT_MODE0),
	IMX_PINCTRL_PIN(IMX8DXL_SCU_BOOT_MODE2),
	IMX_PINCTRL_PIN(IMX8DXL_SNVS_TAMPER_OUT1),
	IMX_PINCTRL_PIN(IMX8DXL_SNVS_TAMPER_OUT2),
	IMX_PINCTRL_PIN(IMX8DXL_SNVS_TAMPER_OUT3),
	IMX_PINCTRL_PIN(IMX8DXL_SNVS_TAMPER_OUT4),
	IMX_PINCTRL_PIN(IMX8DXL_SNVS_TAMPER_IN0),
	IMX_PINCTRL_PIN(IMX8DXL_SNVS_TAMPER_IN1),
	IMX_PINCTRL_PIN(IMX8DXL_SNVS_TAMPER_IN2),
	IMX_PINCTRL_PIN(IMX8DXL_SNVS_TAMPER_IN3),
	IMX_PINCTRL_PIN(IMX8DXL_SPI1_SCK),
	IMX_PINCTRL_PIN(IMX8DXL_SPI1_SDO),
	IMX_PINCTRL_PIN(IMX8DXL_SPI1_SDI),
	IMX_PINCTRL_PIN(IMX8DXL_SPI1_CS0),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_GPIORHD),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0A_DATA1),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0A_DATA0),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0A_DATA3),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0A_DATA2),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0A_SS0_B),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0A_DQS),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0A_SCLK),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_QSPI0A),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0B_SCLK),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0B_DQS),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0B_DATA1),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0B_DATA0),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0B_DATA3),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0B_DATA2),
	IMX_PINCTRL_PIN(IMX8DXL_QSPI0B_SS0_B),
	IMX_PINCTRL_PIN(IMX8DXL_COMP_CTL_GPIO_1V8_3V3_QSPI0B)
};


static struct imx_pinctrl_soc_info imx8dxl_pinctrl_info = {
	.pins = imx8dxl_pinctrl_pads,
	.npins = ARRAY_SIZE(imx8dxl_pinctrl_pads),
	.flags = IMX_USE_SCU,
	.imx_pinconf_get = imx_pinconf_get_scu,
	.imx_pinconf_set = imx_pinconf_set_scu,
	.imx_pinctrl_parse_pin = imx_pinctrl_parse_pin_scu,
};

static const struct of_device_id imx8dxl_pinctrl_of_match[] = {
	{ .compatible = "fsl,imx8dxl-iomuxc", },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, imx8dxl_pinctrl_of_match);

static int imx8dxl_pinctrl_probe(struct platform_device *pdev)
{
	int ret;

	ret = imx_pinctrl_sc_ipc_init(pdev);
	if (ret)
		return ret;

	return imx_pinctrl_probe(pdev, &imx8dxl_pinctrl_info);
}

static struct platform_driver imx8dxl_pinctrl_driver = {
	.driver = {
		.name = "fsl,imx8dxl-iomuxc",
		.of_match_table = of_match_ptr(imx8dxl_pinctrl_of_match),
		.suppress_bind_attrs = true,
	},
	.probe = imx8dxl_pinctrl_probe,
};

static int __init imx8dxl_pinctrl_init(void)
{
	return platform_driver_register(&imx8dxl_pinctrl_driver);
}
arch_initcall(imx8dxl_pinctrl_init);

MODULE_AUTHOR("Anson Huang <Anson.Huang@nxp.com>");
MODULE_DESCRIPTION("NXP i.MX8DXL pinctrl driver");
MODULE_LICENSE("GPL v2");
