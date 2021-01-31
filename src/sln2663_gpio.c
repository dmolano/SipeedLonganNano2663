/* 
 * This file is part of the Sipeed Longan Nano Skeleton. General-purpose and alternate-function I/Os (GPIO and AFIO)
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

#include "sln2663_gpio.h"

#include "sln2663_time.h"

// ---------------------------------------------------------------------
// Private Constants
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Private Prototypes
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Public Bodies
// ---------------------------------------------------------------------
/*!
    \brief      GPIO initialization function on the board LEDs (LED_1615).
    \param[in]  none.
    \param[out] none
    \retval     none
*/
void sln2663_gpio_led_1615_init()
{
    gpio_init(RED_LED_1615_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, RED_LED_1615_GPIO_PIN);
    gpio_init(GREEN_LED_1615_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GREEN_LED_1615_GPIO_PIN);
    gpio_init(BLUE_LED_1615_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, BLUE_LED_1615_GPIO_PIN);
    GPIO_BOP(RED_LED_1615_GPIO_PORT) = RED_LED_1615_GPIO_PIN;
    GPIO_BOP(GREEN_LED_1615_GPIO_PORT) = GREEN_LED_1615_GPIO_PIN;
    GPIO_BOP(BLUE_LED_1615_GPIO_PORT) = BLUE_LED_1615_GPIO_PIN;
}
