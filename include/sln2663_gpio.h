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
#include "gd32vf103.h"

#ifndef __SLN2663_GPIO_H
#define __SLN2663_GPIO_H

// ---------------------------------------------------------------------
// Public Constants
// ---------------------------------------------------------------------
#define END_OF_RCU_GPIO_LIST NULL

// ---------------------------------------------------------------------
// Public Structures
// ---------------------------------------------------------------------
/*!
    \brief      GPIO data init struct
*/
typedef struct SLN2663_GPIO_INIT
{
    uint32_t port;
    uint32_t mode;
    uint32_t frequency;
    uint32_t pin;
} sln2663_gpio_data_init, *sln2663_gpio_data_init_ptr;

/*!
    \brief      RCUs & GPIOs data init struct
*/
typedef struct SLN2663_RCU_GPIO_DATA_INIT
{
    rcu_periph_enum rcu_periph_enable;
    sln2663_gpio_data_init gpio_data_init;
} sln2663_rcu_gpio_data_init, *sln2663_rcu_gpio_data_init_ptr;

// ---------------------------------------------------------------------
// Public Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      GPIOs initialization function.
    \param[in]  rcus_gpios_data_init_ptr
    \param[out] none
    \retval     none
*/
void sln2663_gpios_init(sln2663_rcu_gpio_data_init_ptr *rcus_gpios_data_init_ptr);

#endif // __SLN2663_GPIO_H