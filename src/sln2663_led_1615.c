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

// ---------------------------------------------------------------------
// Private Constants
// ---------------------------------------------------------------------
#define LED_1615_RCU_COUNT 2
#define SENTINEL_NODE_COUNT 1


// ---------------------------------------------------------------------
// Private Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      function
    \param[in]  none
    \param[out] none
    \retval     system error
*/

// ---------------------------------------------------------------------
// Public Bodies
// ---------------------------------------------------------------------
/*!
    \brief      sln2663_led_1615_init function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_init()
{
    rcu_periph_enum rcu_periph[LED_1615_RCU_COUNT + SENTINEL_NODE_COUNT] = {RCU_GPIOA, RCU_GPIOC, RCU_GPIOC};
    // Sentinel node ---------------------------^ (The same item as above.)

    /* enable the leds clock in board */
    sln2663_rcu_init((rcu_periph_enum *)&rcu_periph);
    /* configure led GPIO ports */
    sln2663_gpio_led_1615_init();
}

/*!
    Turn on and off the X part of the RGB LED
    by clearing its bit.
    \brief      sln2663_led_1615_rgb_flash function
    \param[in]  count: count in milliseconds
    \param[in]  sln2663_led_1615_rgb_on: led RGB on function
    \param[in]  sln2663_led_1615_rgb_off: led RGB off function
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_rgb_flash(uint32_t count, void (*sln2663_led_1615_rgb_on)(void), void (*sln2663_led_1615_rgb_off)(void))
{
    sln2663_led_1615_rgb_on();
    sln2663_time_delay_ms(count);
    sln2663_led_1615_rgb_off();
}

/*!
    Flash times the X part of the RGB LED
    by clearing its bit
    \brief      sln2663_led_1615_rgb_flash_times function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[in]  sln2663_led_1615_rgb_flash: led RGB flash function
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_rgb_flash_times(uint32_t count, uint32_t times, uint32_t off_count, void (*sln2663_led_1615_rgb_flash)(uint32_t))
{
    while (times--)
    {
        sln2663_led_1615_rgb_flash(count);
        if (times)
        {
            sln2663_time_delay_ms(off_count);
        }
    }
}

/*!
    Turn on the red part of the RGB LED
    by clearing PC13
    \brief      sln2663_led_1615_red_on function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_on()
{
    GPIO_BC(GPIOC) = GPIO_PIN_13;
}

/*!
    Turn off the red part of the RGB LED
    by setting PC13
    \brief      sln2663_led_1615_red_off function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_off()
{
    GPIO_BOP(GPIOC) = GPIO_PIN_13;
}

/*!
    Turn on and off the red part of the RGB LED
    by flashing PC13
    \brief      sln2663_led_1615_red_flash function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_flash(uint32_t count)
{
    sln2663_led_1615_rgb_flash(count, &sln2663_led_1615_red_on, &sln2663_led_1615_red_off);
}

/*!
    Turn on the red part of the RGB LED
    by flashing PC13
    \brief      sln2663_led_1615_red_flash_times function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_flash_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    sln2663_led_1615_rgb_flash_times(count, times, off_count, &sln2663_led_1615_red_flash);
}

/*!
    Turn on the blue part of the RGB LED
    by clearing PA1
    \brief      sln2663_led_1615_green_on function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_on()
{
    GPIO_BC(GPIOA) = GPIO_PIN_1;
}

/*!
    Turn off the green part of the RGB LED
    by setting PA1
    \brief      sln2663_led_1615_green_off function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_off()
{
    GPIO_BOP(GPIOA) = GPIO_PIN_1;
}

/*!
    Turn on and off the green part of the RGB LED
    by flashing PA1
    \brief      sln2663_led_1615_green_flash function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_flash(uint32_t count)
{
    sln2663_led_1615_rgb_flash(count, &sln2663_led_1615_green_on, &sln2663_led_1615_green_off);
}

/*!
    Turn on the green part of the RGB LED
    by flashing PA1
    \brief      sln2663_led_1615_green_flash_times function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_green_flash_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    sln2663_led_1615_rgb_flash_times(count, times, off_count, &sln2663_led_1615_green_flash);
}

/*!
    Turn on the blue part of the RGB LED
    by clearing PA2
    \brief      sln2663_led_1615_blue_on function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_on()
{
    GPIO_BC(GPIOA) = GPIO_PIN_2;
}

/*!
    Turn off the blue part of the RGB LED
    by setting PA2
    \brief      sln2663_led_1615_blue_off function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_off()
{
    GPIO_BOP(GPIOA) = GPIO_PIN_2;
}

/*!
    Turn on the blue part of the RGB LED
    by flashing PA1
    \brief      sln2663_led_1615_blue_flash function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_flash(uint32_t count)
{
    sln2663_led_1615_rgb_flash(count, &sln2663_led_1615_blue_on, &sln2663_led_1615_blue_off);
}

/*!
    Turn on the blue part of the RGB LED
    by flashing PA1
    \brief      sln2663_led_1615_blue_flash_times function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_blue_flash_times(uint32_t count, uint32_t times, uint32_t off_count)
{
    sln2663_led_1615_rgb_flash_times(count, times, off_count, &sln2663_led_1615_blue_flash);
}

// ---------------------------------------------------------------------
// Private Bodies
// ---------------------------------------------------------------------
/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
