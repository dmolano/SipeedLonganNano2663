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
    \brief      sln2663_led_init function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_init(sln2663_led_ptr sln2663_leds_data) {
    while(sln2663_leds_data != NULL) {
        if (sln2663_leds_data->periph != NULL) {
            sln2663_rcu_init(sln2663_leds_data->periph);
        }
        sln2663_gpio_led_init(sln2663_leds_data->port, sln2663_leds_data->pin, sln2663_leds_data->frequency);
    }
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
