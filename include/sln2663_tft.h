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

#include "sln2663.h"
#include "sln2663_rcu.h"
#include "sln2663_gpio.h"
#include "sln2663_time.h"

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
    \brief      Disabling function of TFT device.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_tft_disable();

/*!
    \brief      Enabling function of TFT device.
    \param[in]  none
    \param[out] none
    \retval     none
*/
void sln2663_tft_enable();

/*!
    \brief      Initializing function of TFT device.
    \param[in]  extern_rcu_init
    \param[in]  extern_rcu_gpio_init
    \param[in]  extern_deinit_init
    \param[in]  extern_configure_init
    \param[out] none
    \retval     none
*/
void sln2663_tft_init(uint32_t (*extern_rcu_init)(), uint32_t (*extern_rcu_gpio_init)(), uint32_t (*extern_deinit_init)(), uint32_t (*extern_configure_init)(uint32_t));
#endif // __SLN2663_TFT_H