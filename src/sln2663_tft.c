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
#define SCL_SDA_TFT_RCU_PERIPH RCU_GPIOA
#define RS_RST_CS_TFT_RCU_PERIPH RCU_GPIOB

#define SCL_SDA_TFT_GPIO_PORT GPIOA
#define RS_RST_CS_TFT_GPIO_PORT GPIOB

#define SCL_TFT_GPIO_PIN GPIO_PIN_5
#define SDA_TFT_GPIO_PIN GPIO_PIN_7
#define RS_TFT_GPIO_PIN GPIO_PIN_0
#define RST_TFT_GPIO_PIN GPIO_PIN_1 // RST=RES
#define CS_TFT_GPIO_PIN GPIO_PIN_2

#define SCL_SDA_TFT_GPIO_MODE GPIO_MODE_AF_PP
#define RS_RST_CS_TFT_GPIO_MODE GPIO_MODE_OUT_PP

#define TFT_FREQUENCY GPIO_OSPEED_50MHZ

// ---------------------------------------------------------------------
// Private Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      Initializing function of TFT device.
    \param[in]  rcus_gpios_data_init_ptr : Pointer to the data of the init TFT.
    \param[out] none
    \retval     none
*/
void sln2663_tft_rcu_gpio_intern_init(sln2663_rcu_gpio_data_init_ptr *rcus_gpios_data_init_ptr);

// ---------------------------------------------------------------------
// Public Bodies
// ---------------------------------------------------------------------
/*!
    \brief      Initializing function of TFT device.
    \param[in]  rcus_gpios_data_init_ptr : Pointer to the data of the init TFT.
    \param[out] none
    \retval     none
*/
void sln2663_tft_rcu_gpio_init(sln2663_rcu_gpio_data_init_ptr *rcus_gpios_data_init_ptr)
{
    // sln2663_gpio scl_gpio = {SCL_SDA_TFT_GPIO_PORT, SCL_SDA_TFT_GPIO_MODE, TFT_FREQUENCY, SCL_TFT_GPIO_PIN};
    // sln2663_gpio sda_gpio = {SCL_SDA_TFT_GPIO_PORT, SCL_SDA_TFT_GPIO_MODE, TFT_FREQUENCY, SDA_TFT_GPIO_PIN};
    // sln2663_gpio_ptr scl_sda_gpios_ptr[] = {&scl_gpio, &sda_gpio, (sln2663_gpio_ptr)NULL};
    // sln2663_tft_init scl_sda_tft = {SCL_SDA_TFT_RCU_PERIPH, scl_sda_gpios_ptr};

    // sln2663_gpio rs_gpio = {RS_RST_CS_TFT_GPIO_PORT, RS_RST_CS_TFT_GPIO_MODE, TFT_FREQUENCY, RS_TFT_GPIO_PIN};
    // sln2663_gpio rst_gpio = {RS_RST_CS_TFT_GPIO_PORT, RS_RST_CS_TFT_GPIO_MODE, TFT_FREQUENCY, RST_TFT_GPIO_PIN};
    // sln2663_gpio cs_gpio = {RS_RST_CS_TFT_GPIO_PORT, RS_RST_CS_TFT_GPIO_MODE, TFT_FREQUENCY, CS_TFT_GPIO_PIN};
    // sln2663_gpio_ptr rs_rst_cs_gpios_ptr[] = {&rs_gpio, &rst_gpio, &cs_gpio, (sln2663_gpio_ptr)NULL};
    // sln2663_tft_init rs_rst_cs_tft = {RS_RST_CS_TFT_RCU_PERIPH, rs_rst_cs_gpios_ptr};

    // sln2663_tft_init af_tft = {RCU_AF, NULL};

    // sln2663_tft_init spi_tft = {RCU_SPI0, NULL};

    // sln2663_tft_init_ptr tfts_ptr[] = {&scl_sda_tft, &rs_rst_cs_tft, &af_tft, &spi_tft, NULL};

    // sln2663_tft_rcu_gpio_intern_init(tfts_ptr);
    // sln2663_tft_rcu_gpio_intern_init(tft_data);
}

// ---------------------------------------------------------------------
// Private Bodies
// ---------------------------------------------------------------------
/*!
    \brief      Initializing function of TFT device.
    \param[in]  rcus_gpios_data_init_ptr : Pointer to the data of the init TFT.
    \param[out] none
    \retval     none
*/
void sln2663_tft_rcu_gpio_intern_init(sln2663_rcu_gpio_data_init_ptr *rcus_gpios_data_init_ptr)
{
    // while (*tft_data != NULL)
    // {
    //     sln2663_rcu_init((*tft_data)->periph);
    //     sln2663_gpios_init((*tft_data)->gpios_ptr);
    //     tft_data++;
    // }
}
