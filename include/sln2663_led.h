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
#include "gd32vf103.h"

#include "sln2663_gpio.h"

#ifndef __SLN2663_LED_H
#define __SLN2663_LED_H

// ---------------------------------------------------------------------
// Public Constants
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Public Structures
// ---------------------------------------------------------------------
/*!
    \brief      LED info struct
*/
typedef struct
{
    rcu_periph_enum periph;
    sln2663_gpio_ptr gpios_ptr;
} sln2663_led, *sln2663_led_ptr;

/*!
    \brief      Configuration of the PIN electrode.
*/
typedef enum
{
    ANODE,
    CATHODE
} electrode_type_enum;

// ---------------------------------------------------------------------
// Public Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      sln2663_led_init function
    \param[in]  leds_data
    \param[out] none
    \retval     none
*/
void sln2663_leds_init(sln2663_led_ptr leds_data);

/*!
    \brief      turn on led function
    \param[in]  port
    \param[in]  pin
    \param[in]  electrode_type
    \param[out] none
    \retval     none
*/
void sln2663_led_on(uint32_t port, uint32_t pin, electrode_type_enum electrode_type);

/*!
    \brief      turn off led function
    \param[in]  port
    \param[in]  pin
    \param[in]  electrode_type
    \param[out] none
    \retval     none
*/
void sln2663_led_off(uint32_t port, uint32_t pin, electrode_type_enum electrode_type);

/*!
    \brief      flash led function
    \param[in]  port
    \param[in]  pin
    \param[in]  electrode_type
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_flash(uint32_t port, uint32_t pin, electrode_type_enum electrode_type, uint32_t count);

/*!
    \brief      flickering led function
    \param[in]  port
    \param[in]  pin
    \param[in]  electrode_type
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_flick(uint32_t port, uint32_t pin, electrode_type_enum electrode_type, uint32_t count);

#endif // __SLN2663_LED_H