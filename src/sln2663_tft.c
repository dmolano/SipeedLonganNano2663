/* 
 * This file is part of the Sipeed Longan Nano 2663 Skeleton.
 * Copyright (c) 2021 Dionisio Molano Robledo.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "sln2663_tft.h"

// ---------------------------------------------------------------------
// Private Constants
// ---------------------------------------------------------------------
#define SCL_TFT_RCU_PERIPH RCU_GPIOA
#define SDA_TFT_RCU_PERIPH RCU_GPIOA
#define CS_TFT_RCU_PERIPH RCU_GPIOB
#define RS_TFT_RCU_PERIPH RCU_GPIOB
#define RST_TFT_RCU_PERIPH RCU_GPIOB

#define SCL_TFT_GPIO_PORT GPIOA
#define SDA_TFT_GPIO_PORT GPIOA
#define CS_TFT_GPIO_PORT GPIOB
#define RS_TFT_GPIO_PORT GPIOB
#define RST_TFT_GPIO_PORT GPIOB

#define SCL_TFT_GPIO_PIN GPIO_PIN_5
#define SDA_TFT_GPIO_PIN GPIO_PIN_7
#define CS_TFT_GPIO_PIN GPIO_PIN_2
#define RS_TFT_GPIO_PIN GPIO_PIN_0
#define RST_TFT_GPIO_PIN GPIO_PIN_1 // RST=RES

#define SCL_TFT_GPIO_MODE GPIO_MODE_AF_PP
#define SDA_TFT_GPIO_MODE GPIO_MODE_AF_PP
#define CS_TFT_GPIO_MODE GPIO_MODE_OUT_PP
#define RS_TFT_GPIO_MODE GPIO_MODE_OUT_PP
#define RST_TFT_GPIO_MODE GPIO_MODE_OUT_PP

#define TFT_FREQUENCY GPIO_OSPEED_50MHZ

#define TFT_DISABLE_WAIT_MS 1
#define TFT_RESET_WAIT_MS 5

// ---------------------------------------------------------------------
// Private Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      Initializing function of TFT device.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_tft_rcu_gpio_init();

/*!
    \brief      Initializing function of TFT device.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_tft_rcus_init();

// ---------------------------------------------------------------------
// Public Bodies
// ---------------------------------------------------------------------
/*!
    \brief      Disabling function of TFT device.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_tft_disable()
{
    gpio_bit_set(CS_TFT_GPIO_PORT, CS_TFT_GPIO_PIN);
}

/*!
    \brief      Enabling function of TFT device.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_tft_enable()
{
    gpio_bit_reset(CS_TFT_GPIO_PORT, CS_TFT_GPIO_PIN);
}

/*!
    \brief      Enabling function of TFT device.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_tft_reset()
{
    gpio_bit_set(RST_TFT_GPIO_PORT, RST_TFT_GPIO_PIN);
}

/*!
    \brief      Initializing function of TFT device.
    \param[in]  extern_rcu_init
    \param[in]  extern_rcu_gpio_init
    \param[in]  extern_deinit_init
    \param[in]  extern_configure_init
    \param[out] none
    \retval     none
*/
void sln2663_tft_init(uint32_t (*extern_rcu_init)(), uint32_t (*extern_rcu_gpio_init)(), uint32_t (*extern_deinit_init)(), uint32_t (*extern_configure_init)(uint32_t))
{
    uint32_t error = NO_ERROR_INIT_SLN2663;

    if (extern_rcu_init != NULL)
    {
        error = (*extern_rcu_init)();
    }
    if (error == NO_ERROR_INIT_SLN2663)
    {
        sln2663_tft_rcus_init();
        if (extern_rcu_gpio_init != NULL)
        {
            error = (*extern_rcu_gpio_init)();
        }
        if (error == NO_ERROR_INIT_SLN2663)
        {
            sln2663_tft_rcu_gpio_init();
            sln2663_tft_disable();
            sln2663_time_delay_ms(TFT_DISABLE_WAIT_MS);
            sln2663_tft_reset();
            sln2663_time_delay_ms(TFT_RESET_WAIT_MS);
            spi_i2s_deinit(SPI0);
            if (extern_deinit_init != NULL)
            {
                error = (*extern_deinit_init)();
            }
            if (error == NO_ERROR_INIT_SLN2663)
            {
                if (extern_configure_init != NULL)
                {
                    error = (*extern_configure_init)(SPI0);
                }
                if (error == NO_ERROR_INIT_SLN2663)
                {
                    SPI_CTL0(SPI0) = (uint32_t)(SPI_MASTER | SPI_TRANSMODE_FULLDUPLEX | SPI_FRAMESIZE_8BIT | SPI_NSS_SOFT | SPI_ENDIAN_MSB | SPI_CK_PL_LOW_PH_1EDGE | SPI_PSC_8);
                    SPI_CTL1(SPI0) = (uint32_t)(SPI_CTL1_DMATEN);
                    spi_enable(SPI0);
                    sln2663_tft_enable();
                }
            }
        }
    }
}
// sln2663_tft_dma_rcu_gpio_init();
// sln2663_tft_disable();
// sln2663_time_delay_ms(TFT_DISABLE_WAIT_MS);
// // sln2663_tft_reset();
// // sln2663_time_delay_ms(TFT_RESET_WAIT_MS);
// // sln2663_tft_spi_dma_init();
// // sln2663_tft_enable();
// // sln2663_tft_lcd_init();
// // sln2663_tft_lcd_clear();
// // sln2663_tft_structure_init();

// ---------------------------------------------------------------------
// Private Bodies
// ---------------------------------------------------------------------
/*!
    \brief      Initializing function of TFT device.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_tft_rcu_gpio_init()
{
    // SCL TFT
    sln2663_gpio_data_init scl_tft_gpio = {SCL_TFT_GPIO_PORT, SCL_TFT_GPIO_MODE, TFT_FREQUENCY, SCL_TFT_GPIO_PIN};
    sln2663_rcu_gpio_data_init scl_tft = {SCL_TFT_RCU_PERIPH, scl_tft_gpio};

    // SDA TFT
    sln2663_gpio_data_init sda_tft_gpio = {SDA_TFT_GPIO_PORT, SDA_TFT_GPIO_MODE, TFT_FREQUENCY, SDA_TFT_GPIO_PIN};
    sln2663_rcu_gpio_data_init sda_tft = {SDA_TFT_RCU_PERIPH, sda_tft_gpio};

    // CS TFT
    sln2663_gpio_data_init cs_tft_gpio = {CS_TFT_GPIO_PORT, CS_TFT_GPIO_MODE, TFT_FREQUENCY, CS_TFT_GPIO_PIN};
    sln2663_rcu_gpio_data_init cs_tft = {CS_TFT_RCU_PERIPH, cs_tft_gpio};

    // RS TFT
    sln2663_gpio_data_init rs_tft_gpio = {RS_TFT_GPIO_PORT, RS_TFT_GPIO_MODE, TFT_FREQUENCY, RS_TFT_GPIO_PIN};
    sln2663_rcu_gpio_data_init rs_tft = {RS_TFT_RCU_PERIPH, rs_tft_gpio};

    // RST TFT
    sln2663_gpio_data_init rst_tft_gpio = {RST_TFT_GPIO_PORT, RST_TFT_GPIO_MODE, TFT_FREQUENCY, RST_TFT_GPIO_PIN};
    sln2663_rcu_gpio_data_init rst_tft = {RST_TFT_RCU_PERIPH, rst_tft_gpio};

    // TFT
    sln2663_rcu_gpio_data_init_ptr tft_ptr[] = {&scl_tft, &sda_tft, &cs_tft, &rs_tft, &rst_tft, END_OF_RCU_GPIO_LIST};

    sln2663_gpios_init(tft_ptr);
}

/*!
    \brief      Initializing function of TFT device.
    \param[in]  rcus_periph_enum_ptr : Pointer to the data of the init TFT.
    \param[out] none
    \retval     none
*/
void sln2663_tft_rcus_init()
{
    // AF
    rcu_periph_enum af_tft = {RCU_AF};
    // SPI0
    rcu_periph_enum spi0_tft = {RCU_SPI0};
    // DMAs
    rcu_periph_enum_ptr af_spi0_tft[] = {&af_tft, &spi0_tft, END_OF_RCU_LIST};

    sln2663_rcus_init(af_spi0_tft);
}
