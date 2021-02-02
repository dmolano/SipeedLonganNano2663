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
#define LED_1615_RCU_COUNT 2
#define SENTINEL_NODE_COUNT 1

#define RED_LED_1615_RCU_PERIPH RCU_GPIOC
#define GREEN_BLUE_LEDS_1615_RCU_PERIPH RCU_GPIOA

#define RED_LED_1615_GPIO_PORT GPIOC
#define GREEN_BLUE_LEDS_1615_GPIO_PORT GPIOA

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
    sln2663_led_flash(GREEN_BLUE_LEDS_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count);
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
    sln2663_led_flash_times(GREEN_BLUE_LEDS_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count, times, off_count);
}

/*!
    \brief      Flicking the blue part function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_flick(uint32_t count)
{
    sln2663_led_flick(GREEN_BLUE_LEDS_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count);
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
    sln2663_led_flick_times(GREEN_BLUE_LEDS_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count, times, off_count);
}

/*!
    \brief      Turning on the blue part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_on()
{
    sln2663_led_on(GREEN_BLUE_LEDS_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE);
}

/*!
    \brief      Turning off the blue part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_off()
{
    sln2663_led_off(GREEN_BLUE_LEDS_1615_GPIO_PORT, GREEN_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE);
}

/*!   
    \brief      Turning on and off the green part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_flash(uint32_t count)
{
    sln2663_led_flash(GREEN_BLUE_LEDS_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count);
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
    sln2663_led_flash_times(GREEN_BLUE_LEDS_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count, times, off_count);
}

/*!
    \brief      Flicking the green part function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_flick(uint32_t count)
{
    sln2663_led_flick(GREEN_BLUE_LEDS_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count);
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
    sln2663_led_flick_times(GREEN_BLUE_LEDS_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE, count, times, off_count);
}

/*!
    \brief      Turning on the green part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_on()
{
    sln2663_led_on(GREEN_BLUE_LEDS_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE);
}

/*!
    \brief      Turning off the green part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_off()
{
    sln2663_led_off(GREEN_BLUE_LEDS_1615_GPIO_PORT, BLUE_LED_1615_GPIO_PIN, LED_1615_ELECTRODE_TYPE);
}

/*!
    \brief      Initializer function of LED 1615.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_init()
{
    sln2663_gpio red_gpio = {RED_LED_1615_GPIO_PORT, GPIO_MODE_OUT_PP, LED_1615_FREQUENCY, RED_LED_1615_GPIO_PIN};
    sln2663_gpio_ptr red_gpios_ptr[] = {&red_gpio, (sln2663_gpio_ptr)NULL};
    sln2663_led red_led = {RED_LED_1615_RCU_PERIPH, red_gpios_ptr};

    sln2663_gpio green_gpio = {GREEN_BLUE_LEDS_1615_GPIO_PORT, GPIO_MODE_OUT_PP, LED_1615_FREQUENCY, GREEN_LED_1615_GPIO_PIN};
    sln2663_gpio blue_gpio = {GREEN_BLUE_LEDS_1615_GPIO_PORT, GPIO_MODE_OUT_PP, LED_1615_FREQUENCY, BLUE_LED_1615_GPIO_PIN};
    sln2663_gpio_ptr green_blue_gpios_ptr[] = {&green_gpio, &blue_gpio, (sln2663_gpio_ptr)NULL};

    sln2663_led green_blue_led = {GREEN_BLUE_LEDS_1615_RCU_PERIPH, green_blue_gpios_ptr};
    sln2663_led_ptr leds_ptr[] = {&red_led, &green_blue_led, NULL};

    sln2663_leds_init(leds_ptr);
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
