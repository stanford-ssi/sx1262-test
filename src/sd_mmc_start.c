/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file or main.c
 * to avoid loosing it when reconfiguring.
 */

#include "sd_mmc.h"

#include "conf_sd_mmc.h"
#include "sd_mmc_start.h"
#include "hpl_sdhc_config.h"
#include "hal_gpio.h"

#define SD_CMD GPIO(GPIO_PORTA, 8)
#define SD_DAT0 GPIO(GPIO_PORTA, 9)
#define SD_DAT1 GPIO(GPIO_PORTA, 10)
#define SD_DAT2 GPIO(GPIO_PORTA, 11)
#define SD_DAT3 GPIO(GPIO_PORTB, 10)
#define SD_CLK GPIO(GPIO_PORTB, 11)

static struct mci_sync_desc MCI_0;

void MCI_0_PORT_init(void)
{

	gpio_set_pin_direction(SD_CLK, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SD_CLK, false);

	gpio_set_pin_pull_mode(SD_CLK, GPIO_PULL_OFF);

	gpio_set_pin_function(SD_CLK, PINMUX_PB11I_SDHC0_SDCK);

	gpio_set_pin_direction(SD_CMD, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SD_CMD, false);

	gpio_set_pin_pull_mode(SD_CMD, GPIO_PULL_OFF);

	gpio_set_pin_function(SD_CMD, PINMUX_PA08I_SDHC0_SDCMD);

	gpio_set_pin_direction(SD_DAT0, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SD_DAT0, false);

	gpio_set_pin_pull_mode(SD_DAT0, GPIO_PULL_OFF);

	gpio_set_pin_function(SD_DAT0, PINMUX_PA09I_SDHC0_SDDAT0);

	gpio_set_pin_direction(SD_DAT1, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SD_DAT1, false);

	gpio_set_pin_pull_mode(SD_DAT1, GPIO_PULL_OFF);

	gpio_set_pin_function(SD_DAT1, PINMUX_PA10I_SDHC0_SDDAT1);

	gpio_set_pin_direction(SD_DAT2, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SD_DAT2, false);

	gpio_set_pin_pull_mode(SD_DAT2, GPIO_PULL_OFF);

	gpio_set_pin_function(SD_DAT2, PINMUX_PA11I_SDHC0_SDDAT2);

	gpio_set_pin_direction(SD_DAT3, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SD_DAT3, false);

	gpio_set_pin_pull_mode(SD_DAT3, GPIO_PULL_OFF);

	gpio_set_pin_function(SD_DAT3, PINMUX_PB10I_SDHC0_SDDAT3);
}

void MCI_0_CLOCK_init(void)
{
	hri_mclk_set_AHBMASK_SDHC0_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, SDHC0_GCLK_ID, CONF_GCLK_SDHC0_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SDHC0_GCLK_ID_SLOW, CONF_GCLK_SDHC0_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
}

void MCI_0_init(void)
{
	MCI_0_CLOCK_init();
	mci_sync_init(&MCI_0, SDHC0);
	MCI_0_PORT_init();
}

/* Card Detect (CD) pin settings */
static sd_mmc_detect_t SDMMC_ACCESS_0_cd[CONF_SD_MMC_MEM_CNT] = {

    {-1, CONF_SD_MMC_0_CD_DETECT_VALUE},
};

/* Write Protect (WP) pin settings */
static sd_mmc_detect_t SDMMC_ACCESS_0_wp[CONF_SD_MMC_MEM_CNT] = {

    {-1, CONF_SD_MMC_0_WP_DETECT_VALUE},
};

static uint8_t sd_mmc_block[512];

/*
 * Example
 */
void SDMMC_ACCESS_0_example(void)
{
	while (SD_MMC_OK != sd_mmc_check(0)) {
		/* Wait card ready. */
	}
	if (sd_mmc_get_type(0) & (CARD_TYPE_SD | CARD_TYPE_MMC)) {
		/* Read card block 0 */
		sd_mmc_init_read_blocks(0, 0, 1);
		sd_mmc_start_read_blocks(sd_mmc_block, 1);
		sd_mmc_wait_end_of_read_blocks(false);
	}
#if (CONF_SDIO_SUPPORT == 1)
	if (sd_mmc_get_type(0) & CARD_TYPE_SDIO) {
		/* Read 22 bytes from SDIO Function 0 (CIA) */
		sdio_read_extended(0, 0, 0, 1, sd_mmc_block, 22);
	}
#endif
}

void sd_mmc_stack_init(void)
{

	sd_mmc_init(&MCI_0, SDMMC_ACCESS_0_cd, SDMMC_ACCESS_0_wp);
}
