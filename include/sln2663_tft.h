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
#include "sln2663_rcu.h"
#include "sln2663_gpio.h"

#ifndef __SLN2663_TFT_H
#define __SLN2663_TFT_H

// ---------------------------------------------------------------------
// Public Constants
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Public Structures
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Public Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      Initializing function of TFT device.
    \param[in]  rcus_gpios_data_init_ptr : Pointer to the data of the init TFT.
    \param[out] none
    \retval     none
*/
void sln2663_tft_rcu_gpio_init(sln2663_rcu_gpio_data_init_ptr *rcus_gpios_data_init_ptr);

#endif // __SLN2663_TFT_H