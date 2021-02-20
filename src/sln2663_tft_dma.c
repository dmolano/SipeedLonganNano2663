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

#include "sln2663_tft_dma.h"

// ---------------------------------------------------------------------
// Private Constants
// ---------------------------------------------------------------------
#define DMA0_RCU_PERIPH RCU_DMA0

// ---------------------------------------------------------------------
// Private Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      Deinit function with DMA.
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
uint32_t sln2663_tft_dma_configure_init(uint32_t spi_periph);

/*!
    \brief      Deinit function with DMA.
    \param[in]  none
    \param[out] none
    \retval     none
*/
uint32_t sln2663_tft_dma_deinit_init();

/*!
    \brief      RCU initializer function with DMA.
    \param[in]  none
    \param[out] none
    \retval     none
*/
uint32_t sln2663_tft_dma_rcu_init();

/*!
    \brief      RCU & GPIO initializer function with DMA.
    \param[in]  none
    \param[out] none
    \retval     none
*/
uint32_t sln2663_tft_dma_rcu_gpio_init();

// ---------------------------------------------------------------------
// Public Bodies
// ---------------------------------------------------------------------
/*!
    \brief      TFT initializer function with DMA.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_tft_dma_init()
{
    sln2663_tft_init(sln2663_tft_dma_rcu_init, sln2663_tft_dma_rcu_gpio_init, sln2663_tft_dma_deinit_init, sln2663_tft_dma_configure_init);
}

// ---------------------------------------------------------------------
// Private Bodies
// ---------------------------------------------------------------------
/*!
    \brief      Deinit function with DMA.
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
uint32_t sln2663_tft_dma_configure_init(uint32_t spi_periph)
{
    DMA_CHCTL(DMA0, DMA_CH1) = (uint32_t)(DMA_PRIORITY_ULTRA_HIGH | DMA_CHXCTL_MNAGA); // Receive.
    DMA_CHCTL(DMA0, DMA_CH2) = (uint32_t)(DMA_PRIORITY_ULTRA_HIGH | DMA_CHXCTL_DIR);   // Transmit.
    DMA_CHPADDR(DMA0, DMA_CH1) = (uint32_t)&SPI_DATA(spi_periph);
    DMA_CHPADDR(DMA0, DMA_CH2) = (uint32_t)&SPI_DATA(spi_periph);
    return NO_ERROR_INIT_SLN2663;
}

/*!
    \brief      Deinit function with DMA.
    \param[in]  none
    \param[out] none
    \retval     none
*/
uint32_t sln2663_tft_dma_deinit_init()
{
    dma_deinit(DMA0, DMA_CH1);
    dma_deinit(DMA0, DMA_CH2);
    return NO_ERROR_INIT_SLN2663;
}

/*!
    \brief      RCU initializer function with DMA.
    \param[in]  none
    \param[out] none
    \retval     none
*/
uint32_t sln2663_tft_dma_rcu_init()
{
    // DMA0
    rcu_periph_enum dma0_tft = {DMA0_RCU_PERIPH};
    // DMAs
    rcu_periph_enum_ptr dmas_tft[] = {&dma0_tft, END_OF_RCU_LIST};

    sln2663_rcus_init(dmas_tft);
    return NO_ERROR_INIT_SLN2663;
}

/*!
    \brief      RCU & GPIO initializer function with DMA.
    \param[in]  none
    \param[out] none
    \retval     none
*/
uint32_t sln2663_tft_dma_rcu_gpio_init()
{
    return NO_ERROR_INIT_SLN2663;
}

