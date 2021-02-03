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
    \brief      GPIOs initialization function.
    \param[in]  gpios_ptr
    \param[out] none
    \retval     none
*/
void sln2663_gpios_init(sln2663_gpio_ptr *gpios_ptr)
{
    while (*gpios_ptr != NULL)
    {
        gpio_init((*gpios_ptr)->port, (*gpios_ptr)->mode, (*gpios_ptr)->frequency, (*gpios_ptr)->pin);
        GPIO_BOP((*gpios_ptr)->port) = (*gpios_ptr)->pin;
        gpios_ptr++;
    }
}
