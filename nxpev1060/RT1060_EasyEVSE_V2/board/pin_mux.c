/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v12.0
processor: MIMXRT1062xxxxA
package_id: MIMXRT1062DVL6A
mcu_data: ksdk2_0
processor_version: 12.0.1
board: MIMXRT1060-EVK
pin_labels:
- {pin_num: G11, pin_signal: GPIO_AD_B0_03, label: 'USB_OTG1_OC/J24[1]', identifier: RC_633_IRQ}
- {pin_num: G10, pin_signal: GPIO_AD_B0_11, label: 'JTAG_nTRST/J21[3]/INT2_COMBO/LCD_TOUCH_INT/J22[3]/U32[9]', identifier: INT2_COMBO;SE_RST}
- {pin_num: J11, pin_signal: GPIO_AD_B1_00, label: 'I2C1_SCL/CSI_I2C_SCL/J35[20]/J23[6]/U13[17]/U32[4]', identifier: I2C_SCL_FXOS8700CQ;CSI_I2C_SCL;I2C_CLK}
- {pin_num: K11, pin_signal: GPIO_AD_B1_01, label: 'I2C1_SDA/CSI_I2C_SDA/J35[22]/J23[5]/U13[18]/U32[6]', identifier: I2C_SDA_FXOS8700CQ;CSI_I2C_SDA;I2C_SDA}
- {pin_num: L11, pin_signal: GPIO_AD_B1_02, label: 'SPDIF_OUT/J22[7]', identifier: SPDIF_OUT;Meter_TX}
- {pin_num: M12, pin_signal: GPIO_AD_B1_03, label: 'SPDIF_IN/J22[8]', identifier: SPDIF_IN;Meter_RX}

 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
    BOARD_InitI2CPins();
    BOARD_Init_NFCPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: L14, peripheral: LPUART1, signal: RX, pin_signal: GPIO_AD_B0_13, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
  - {pin_num: K14, peripheral: LPUART1, signal: TX, pin_signal: GPIO_AD_B0_12, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
  - {pin_num: A7, peripheral: ENET, signal: enet_mdc, pin_signal: GPIO_EMC_40, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Up_100K_Ohm,
    pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_200, drive_strength: R0_5, slew_rate: Fast}
  - {pin_num: C7, peripheral: ENET, signal: enet_mdio, pin_signal: GPIO_EMC_41, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Up_100K_Ohm,
    pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Enable, speed: MHZ_50, drive_strength: R0_5, slew_rate: Fast}
  - {pin_num: B13, peripheral: ENET, signal: enet_ref_clk, pin_signal: GPIO_B1_10, software_input_on: Enable, hysteresis_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm,
    pull_keeper_select: Keeper, pull_keeper_enable: Disable, open_drain: Disable, speed: MHZ_50, drive_strength: R0_6, slew_rate: Fast}
  - {pin_num: E12, peripheral: ENET, signal: 'enet_rx_data, 0', pin_signal: GPIO_B1_04, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Up_100K_Ohm,
    pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_200, drive_strength: R0_5, slew_rate: Fast}
  - {pin_num: D12, peripheral: ENET, signal: 'enet_rx_data, 1', pin_signal: GPIO_B1_05, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Up_100K_Ohm,
    pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_200, drive_strength: R0_5, slew_rate: Fast}
  - {pin_num: C12, peripheral: ENET, signal: enet_rx_en, pin_signal: GPIO_B1_06, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Up_100K_Ohm,
    pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_200, drive_strength: R0_5, slew_rate: Fast}
  - {pin_num: C13, peripheral: ENET, signal: enet_rx_er, pin_signal: GPIO_B1_11, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Up_100K_Ohm,
    pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_200, drive_strength: R0_5, slew_rate: Fast}
  - {pin_num: B12, peripheral: ENET, signal: 'enet_tx_data, 0', pin_signal: GPIO_B1_07, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Up_100K_Ohm,
    pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_200, drive_strength: R0_5, slew_rate: Fast}
  - {pin_num: A12, peripheral: ENET, signal: 'enet_tx_data, 1', pin_signal: GPIO_B1_08, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Up_100K_Ohm,
    pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_200, drive_strength: R0_5, slew_rate: Fast}
  - {pin_num: A13, peripheral: ENET, signal: enet_tx_en, pin_signal: GPIO_B1_09, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Up_100K_Ohm,
    pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_200, drive_strength: R0_5, slew_rate: Fast}
  - {pin_num: F14, peripheral: GPIO1, signal: 'gpio_io, 09', pin_signal: GPIO_AD_B0_09, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Up_100K_Ohm,
    pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_5, slew_rate: Fast}
  - {pin_num: G13, peripheral: GPIO1, signal: 'gpio_io, 10', pin_signal: GPIO_AD_B0_10, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Up_100K_Ohm,
    pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_5, slew_rate: Fast}
  - {pin_num: M12, peripheral: LPUART2, signal: RX, pin_signal: GPIO_AD_B1_03, identifier: Meter_RX}
  - {pin_num: L11, peripheral: LPUART2, signal: TX, pin_signal: GPIO_AD_B1_02, identifier: Meter_TX}
  - {pin_num: D7, peripheral: LCDIF, signal: lcdif_clk, pin_signal: GPIO_B0_00}
  - {pin_num: C8, peripheral: LCDIF, signal: 'lcdif_data, 00', pin_signal: GPIO_B0_04}
  - {pin_num: D11, peripheral: LCDIF, signal: 'lcdif_data, 15', pin_signal: GPIO_B1_03}
  - {pin_num: C11, peripheral: LCDIF, signal: 'lcdif_data, 14', pin_signal: GPIO_B1_02}
  - {pin_num: B11, peripheral: LCDIF, signal: 'lcdif_data, 13', pin_signal: GPIO_B1_01}
  - {pin_num: A11, peripheral: LCDIF, signal: 'lcdif_data, 12', pin_signal: GPIO_B1_00}
  - {pin_num: E11, peripheral: LCDIF, signal: 'lcdif_data, 11', pin_signal: GPIO_B0_15}
  - {pin_num: E10, peripheral: LCDIF, signal: 'lcdif_data, 10', pin_signal: GPIO_B0_14}
  - {pin_num: D10, peripheral: LCDIF, signal: 'lcdif_data, 09', pin_signal: GPIO_B0_13}
  - {pin_num: C10, peripheral: LCDIF, signal: 'lcdif_data, 08', pin_signal: GPIO_B0_12}
  - {pin_num: A10, peripheral: LCDIF, signal: 'lcdif_data, 07', pin_signal: GPIO_B0_11}
  - {pin_num: D9, peripheral: LCDIF, signal: 'lcdif_data, 06', pin_signal: GPIO_B0_10}
  - {pin_num: C9, peripheral: LCDIF, signal: 'lcdif_data, 05', pin_signal: GPIO_B0_09}
  - {pin_num: B9, peripheral: LCDIF, signal: 'lcdif_data, 04', pin_signal: GPIO_B0_08}
  - {pin_num: A9, peripheral: LCDIF, signal: 'lcdif_data, 03', pin_signal: GPIO_B0_07}
  - {pin_num: A8, peripheral: LCDIF, signal: 'lcdif_data, 02', pin_signal: GPIO_B0_06}
  - {pin_num: B8, peripheral: LCDIF, signal: 'lcdif_data, 01', pin_signal: GPIO_B0_05}
  - {pin_num: E7, peripheral: LCDIF, signal: lcdif_enable, pin_signal: GPIO_B0_01}
  - {pin_num: E8, peripheral: LCDIF, signal: lcdif_hsync, pin_signal: GPIO_B0_02}
  - {pin_num: D8, peripheral: LCDIF, signal: lcdif_vsync, pin_signal: GPIO_B0_03}
  - {pin_num: M11, peripheral: GPIO1, signal: 'gpio_io, 02', pin_signal: GPIO_AD_B0_02}
  - {pin_num: B14, peripheral: GPIO2, signal: 'gpio_io, 31', pin_signal: GPIO_B1_15}
  - {pin_num: G10, peripheral: GPIO1, signal: 'gpio_io, 11', pin_signal: GPIO_AD_B0_11, identifier: SE_RST, direction: OUTPUT}
  - {pin_num: J4, peripheral: LPSPI1, signal: SCK, pin_signal: GPIO_SD_B0_00, identifier: RC_663_SPI_CLK, direction: OUTPUT}
  - {pin_num: J1, peripheral: LPSPI1, signal: SDO, pin_signal: GPIO_SD_B0_02, identifier: RC_633_SPI_MOSI, direction: OUTPUT}
  - {pin_num: K1, peripheral: LPSPI1, signal: SDI, pin_signal: GPIO_SD_B0_03, identifier: RC_633_SPI_MISO, direction: INPUT}
  - {pin_num: J3, peripheral: LPSPI1, signal: PCS0, pin_signal: GPIO_SD_B0_01, identifier: RC_633_SPI_SSEL, direction: OUTPUT}
  - {pin_num: G11, peripheral: GPIO1, signal: 'gpio_io, 03', pin_signal: GPIO_AD_B0_03, direction: INPUT, gpio_interrupt: kGPIO_IntFallingEdge}
  - {pin_num: H13, peripheral: GPIO1, signal: 'gpio_io, 24', pin_signal: GPIO_AD_B1_08, identifier: RC_633_nPDOWN, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           

  /* GPIO configuration of RC_633_IRQ on GPIO_AD_B0_03 (pin G11) */
  gpio_pin_config_t RC_633_IRQ_config = {
      .direction = kGPIO_DigitalInput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_IntFallingEdge
  };
  /* Initialize GPIO functionality on GPIO_AD_B0_03 (pin G11) */
  GPIO_PinInit(GPIO1, 3U, &RC_633_IRQ_config);
  /* Enable GPIO pin interrupt on GPIO_AD_B0_03 (pin G11) */
  GPIO_PortEnableInterrupts(GPIO1, 1U << 3U);

  /* GPIO configuration of SE_RST on GPIO_AD_B0_11 (pin G10) */
  gpio_pin_config_t SE_RST_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_B0_11 (pin G10) */
  GPIO_PinInit(GPIO1, 11U, &SE_RST_config);

  /* GPIO configuration of RC_633_nPDOWN on GPIO_AD_B1_08 (pin H13) */
  gpio_pin_config_t RC_633_nPDOWN_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_AD_B1_08 (pin H13) */
  GPIO_PinInit(GPIO1, 24U, &RC_633_nPDOWN_config);

  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_02_GPIO1_IO02, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_03_GPIO1_IO03, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_09_GPIO1_IO09, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_10_GPIO1_IO10, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_11_GPIO1_IO11, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_LPUART1_TX, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_LPUART1_RX, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_LPUART2_TX, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_LPUART2_RX, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_08_GPIO1_IO24, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_00_LCD_CLK, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_01_LCD_ENABLE, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_02_LCD_HSYNC, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_03_LCD_VSYNC, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_04_LCD_DATA00, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_05_LCD_DATA01, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_06_LCD_DATA02, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_07_LCD_DATA03, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_08_LCD_DATA04, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_09_LCD_DATA05, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_10_LCD_DATA06, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_11_LCD_DATA07, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_12_LCD_DATA08, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_13_LCD_DATA09, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_14_LCD_DATA10, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B0_15_LCD_DATA11, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_00_LCD_DATA12, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_01_LCD_DATA13, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_02_LCD_DATA14, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_03_LCD_DATA15, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_04_ENET_RX_DATA00, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_05_ENET_RX_DATA01, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_06_ENET_RX_EN, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_07_ENET_TX_DATA00, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_08_ENET_TX_DATA01, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_09_ENET_TX_EN, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_10_ENET_REF_CLK, 1U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_11_ENET_RX_ER, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_B1_15_GPIO2_IO31, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_40_ENET_MDC, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_41_ENET_MDIO, 0U); 
  IOMUXC_GPR->GPR26 = ((IOMUXC_GPR->GPR26 &
    (~(BOARD_INITPINS_IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK))) 
      | IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL(0x00U) 
    );
  IOMUXC_GPR->GPR27 = ((IOMUXC_GPR->GPR27 &
    (~(BOARD_INITPINS_IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL_MASK))) 
      | IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL(0x00U) 
    );
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_09_GPIO1_IO09, 0xB0A9U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_10_GPIO1_IO10, 0xB0A9U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_12_LPUART1_TX, 0x10B0U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_13_LPUART1_RX, 0x10B0U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_04_ENET_RX_DATA00, 0xB0E9U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_05_ENET_RX_DATA01, 0xB0E9U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_06_ENET_RX_EN, 0xB0E9U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_07_ENET_TX_DATA00, 0xB0E9U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_08_ENET_TX_DATA01, 0xB0E9U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_09_ENET_TX_EN, 0xB0E9U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_10_ENET_REF_CLK, 0x31U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_11_ENET_RX_ER, 0xB0E9U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_40_ENET_MDC, 0xB0E9U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_41_ENET_MDIO, 0xB829U); 
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitI2CPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: J11, peripheral: LPI2C1, signal: SCL, pin_signal: GPIO_AD_B1_00, identifier: I2C_CLK, software_input_on: Enable, pull_up_down_config: Pull_Up_22K_Ohm,
    open_drain: Enable, drive_strength: R0_7, slew_rate: Fast}
  - {pin_num: K11, peripheral: LPI2C1, signal: SDA, pin_signal: GPIO_AD_B1_01, identifier: I2C_SDA, software_input_on: Enable, pull_up_down_config: Pull_Up_22K_Ohm,
    open_drain: Enable, drive_strength: R0_7, slew_rate: Fast}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitI2CPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitI2CPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           

  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_LPI2C1_SCL, 1U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_LPI2C1_SDA, 1U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_00_LPI2C1_SCL, 0xD8B9U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_01_LPI2C1_SDA, 0xD8B9U); 
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_Init_NFCPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: H12, peripheral: LPSPI3, signal: PCS0, pin_signal: GPIO_AD_B1_12}
  - {pin_num: J14, peripheral: LPSPI3, signal: SCK, pin_signal: GPIO_AD_B1_15}
  - {pin_num: H11, peripheral: LPSPI3, signal: SDI, pin_signal: GPIO_AD_B1_13}
  - {pin_num: G12, peripheral: LPSPI3, signal: SDO, pin_signal: GPIO_AD_B1_14}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_Init_NFCPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_Init_NFCPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);

#if BOARD_NFC_ARDUINO_HEADER
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_00_LPSPI1_SCK, 0U);
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_01_LPSPI1_PCS0, 0U);
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_02_LPSPI1_SDO, 0U);
  IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_03_LPSPI1_SDI, 0U);
#else
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_12_LPSPI3_PCS0, 0U);
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_13_LPSPI3_SDI, 0U);
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_14_LPSPI3_SDO, 0U);
#if FSL_IOMUXC_DRIVER_VERSION >= MAKE_VERSION(2, 0, 4)
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_15_LPSPI3_SCK, 0U);
#endif
#endif /* BOARD_NFC_ARDUINO_HEADER */
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/