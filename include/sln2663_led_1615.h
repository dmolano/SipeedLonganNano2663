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

#ifndef __SLN2663_LED_1615_H
#define __SLN2663_LED_1615_H

// ---------------------------------------------------------------------
// Public Constants
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Public Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      Initializer function of LED 1615.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_init();

/*!   
    \brief      Turning on and off the red part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_flash(uint32_t count);

/*!
    \brief      Flashing times the red part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_flash_times(uint32_t count, uint32_t times, uint32_t off_count);

/*!
    \brief      Flicking the red part function
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_flick(uint32_t count);

/*!
    \brief      Flicking times the red part of the RGB LED function
    \param[in]  count: count in milliseconds
    \param[in]  times: instances
    \param[in]  off_count: off count in milliseconds
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_flick_times(uint32_t count, uint32_t times, uint32_t off_count);

/*!
    \brief      Turning on the red part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_on();

/*!
    \brief      Turning off the red part of the RGB LED function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_led_1615_red_off();

#endif // __SLN2663_LED_1615_H