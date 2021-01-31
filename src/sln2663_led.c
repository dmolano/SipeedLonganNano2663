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

#include "sln2663_led.h"

#include "sln2663_rcu.h"
#include "sln2663_gpio.h"
#include "sln2663_time.h"

// ---------------------------------------------------------------------
// Private Constants
// ---------------------------------------------------------------------

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
    \brief      Initializing function of LED devices.
    \param[in]  leds_data : Pointer to the data of the LEDs.
    \param[out] none
    \retval     none
*/
void sln2663_leds_init(sln2663_led_ptr leds_data)
{
    while (leds_data != NULL)
    {
        sln2663_rcu_init(leds_data->periph);

        leds_data->gpios_ptr->mode = GPIO_MODE_OUT_PP;
        sln2663_gpios_init(leds_data->gpios_ptr);

        leds_data++;
    }
}

/*!
    \brief      flashing led function
    \param[in]  port
    \param[in]  pin
    \param[in]  electrode_type
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_flash(uint32_t port, uint32_t pin, electrode_type_enum electrode_type, uint32_t count)
{
    sln2663_led_on(port, pin, electrode_type);
    sln2663_time_delay_ms(count);
    sln2663_led_off(port, pin, electrode_type);
}

/*!
    \brief      flashing led function
    \param[in]  port
    \param[in]  pin
    \param[in]  electrode_type
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_flash_times(uint32_t port, uint32_t pin, electrode_type_enum electrode_type, uint32_t count, uint32_t times, uint32_t off_count)
{
    while (times--)
    {
        sln2663_led_flash(port, pin, electrode_type, count);
        if (times)
        {
            sln2663_time_delay_ms(off_count);
        }
    }
}

/*!
    \brief      flickering led function
    \param[in]  port
    \param[in]  pin
    \param[in]  electrode_type
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_flick(uint32_t port, uint32_t pin, electrode_type_enum electrode_type, uint32_t count)
{
    sln2663_led_off(port, pin, electrode_type);
    sln2663_time_delay_ms(count);
    sln2663_led_on(port, pin, electrode_type);
}

/*!
    \brief      flashing led function
    \param[in]  port
    \param[in]  pin
    \param[in]  electrode_type
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_flick_times(uint32_t port, uint32_t pin, electrode_type_enum electrode_type, uint32_t count, uint32_t times, uint32_t off_count)
{
    while (times--)
    {
        sln2663_led_flick(port, pin, electrode_type, count);
        if (times)
        {
            sln2663_time_delay_ms(off_count);
        }
    }
}

/*!
    \brief      turning on led function
    \param[in]  port
    \param[in]  pin
    \param[in]  electrode_type
    \param[out] none
    \retval     none
*/
void sln2663_led_on(uint32_t port, uint32_t pin, electrode_type_enum electrode_type)
{
    if (electrode_type == ANODE)
    {
        GPIO_BC(port) = pin;
    }
    else
    {
        GPIO_BOP(port) = pin;
    }
}

/*!
    \brief      turning off led function
    \param[in]  port
    \param[in]  pin
    \param[in]  electrode_type
    \param[out] none
    \retval     none
*/
void sln2663_led_off(uint32_t port, uint32_t pin, electrode_type_enum electrode_type)
{
    if (electrode_type == ANODE)
    {
        GPIO_BOP(port) = pin;
    }
    else
    {
        GPIO_BC(port) = pin;
    }
}

// ---------------------------------------------------------------------
// Private Bodies
// ---------------------------------------------------------------------
