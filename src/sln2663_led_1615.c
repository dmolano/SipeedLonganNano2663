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

#include "sln2663_led_1615.h"
#include "sln2663_led.h"

// ---------------------------------------------------------------------
// Private Constants
// ---------------------------------------------------------------------
#define RED_LED_1615_RCU_PERIPH RCU_GPIOC
#define GREEN_LED_1615_RCU_PERIPH RCU_GPIOA
#define BLUE_LED_1615_RCU_PERIPH RCU_GPIOA

#define RED_LED_1615_GPIO_PORT GPIOC
#define GREEN_LED_1615_GPIO_PORT GPIOA
#define BLUE_LED_1615_GPIO_PORT GPIOA

#define RED_LED_1615_GPIO_PIN GPIO_PIN_13
#define GREEN_LED_1615_GPIO_PIN GPIO_PIN_1
#define BLUE_LED_1615_GPIO_PIN GPIO_PIN_2

#define LED_1615_FREQUENCY GPIO_OSPEED_50MHZ

#define LED_1615_ELECTRODE_TYPE ANODE

// ---------------------------------------------------------------------
// Private Prototypes
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Public Bodies
// ---------------------------------------------------------------------
/*!   
    \brief      Turning on and off the blue part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_flash(uint32_t count)
{
    sln2663_led_flash(BLUE_LED_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count);
}

/*!
    \brief      Flashing times the blue part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_flash_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    sln2663_led_flash_times(BLUE_LED_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count, times, off_count);
}

/*!
    \brief      Flicking the blue part function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_flick(uint32_t count)
{
    sln2663_led_flick(BLUE_LED_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count);
}

/*!
    \brief      Flicking times the blue part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_flick_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    sln2663_led_flick_times(BLUE_LED_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count, times, off_count);
}

/*!
    \brief      Turning on the blue part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_on()
{
    sln2663_led_on(BLUE_LED_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE);
}

/*!
    \brief      Turning off the blue part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_off()
{
    sln2663_led_off(BLUE_LED_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE);
}

/*!   
    \brief      Turning on and off the green part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_flash(uint32_t count)
{
    sln2663_led_flash(GREEN_LED_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count);
}

/*!
    \brief      Flashing times the green part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_flash_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    sln2663_led_flash_times(GREEN_LED_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count, times, off_count);
}

/*!
    \brief      Flicking the green part function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_flick(uint32_t count)
{
    sln2663_led_flick(GREEN_LED_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count);
}

/*!
    \brief      Flicking times the green part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_flick_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    sln2663_led_flick_times(GREEN_LED_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count, times, off_count);
}

/*!
    \brief      Turning on the green part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_on()
{
    sln2663_led_on(GREEN_LED_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE);
}

/*!
    \brief      Turning off the green part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_off()
{
    sln2663_led_off(GREEN_LED_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE);
}

/*!
    \brief      Initializer function of LED 1615.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_init()
{
    // RED LED_1615
    sln2663_gpio_data_init red_led_1615_gpio = {RED_LED_1615_GPIO_PORT, GPIO_MODE_OUT_PP, LED_1615_FREQUENCY, RED_LED_1615_GPIO_PIN};
    sln2663_rcu_gpio_data_init red_led_1615 = {RED_LED_1615_RCU_PERIPH, red_led_1615_gpio};

    // GREEN LED_1615
    sln2663_gpio_data_init green_led_1615_gpio = {GREEN_LED_1615_GPIO_PORT, GPIO_MODE_OUT_PP, LED_1615_FREQUENCY, GREEN_LED_1615_GPIO_PIN};
    sln2663_rcu_gpio_data_init green_led_1615 = {GREEN_LED_1615_RCU_PERIPH, green_led_1615_gpio};

    // BLUE LED_1615
    sln2663_gpio_data_init blue_led_1615_gpio = {BLUE_LED_1615_GPIO_PORT, GPIO_MODE_OUT_PP, LED_1615_FREQUENCY, BLUE_LED_1615_GPIO_PIN};
    sln2663_rcu_gpio_data_init blue_led_1615 = {BLUE_LED_1615_RCU_PERIPH, blue_led_1615_gpio};

    // LED_1615
    sln2663_rcu_gpio_data_init_ptr led_1615_ptr[] = {&red_led_1615, &green_led_1615, &blue_led_1615, END_OF_RCU_GPIO_LIST};

    sln2663_leds_init(led_1615_ptr);
}

/*!   
    \brief      Turning on and off the red part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_flash(uint32_t count)
{
    sln2663_led_flash(RED_LED_1615_GPIO_PORT, RED_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count);
}

/*!
    \brief      Flashing times the red part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_flash_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    sln2663_led_flash_times(RED_LED_1615_GPIO_PORT, RED_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count, times, off_count);
}

/*!
    \brief      Flicking the red part function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_flick(uint32_t count)
{
    sln2663_led_flick(RED_LED_1615_GPIO_PORT, RED_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count);
}

/*!
    \brief      Flicking times the red part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_flick_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    sln2663_led_flick_times(RED_LED_1615_GPIO_PORT, RED_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count, times, off_count);
}

/*!
    \brief      Turning on the red part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_on()
{
    sln2663_led_on(RED_LED_1615_GPIO_PORT, RED_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE);
}

/*!
    \brief      Turning off the red part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_off()
{
    sln2663_led_off(RED_LED_1615_GPIO_PORT, RED_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE);
}

// ---------------------------------------------------------------------
// Private Bodies
// ---------------------------------------------------------------------
