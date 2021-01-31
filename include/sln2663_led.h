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
    uint32_t port;
    uint32_t pin;
    uint32_t frequency;
} sln2663_led, *sln2663_led_ptr;

// ---------------------------------------------------------------------
// Public Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      sln2663_led_init function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_init(sln2663_led_ptr sln2663_leds_data);


#endif // __SLN2663_LED_H