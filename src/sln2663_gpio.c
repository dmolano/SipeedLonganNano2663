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
#include "sln2663_rcu.h"

// ---------------------------------------------------------------------
// Private Constants
// ---------------------------------------------------------------------
#define RCU_NOT_FOUND NULL
// ---------------------------------------------------------------------
// Private Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      GPIO initialization function.
    \param[in]  rcus_gpios_data_init_ptr
    \param[out] none
    \retval     none
*/
void sln2663_gpio_init(sln2663_rcu_gpio_data_init_ptr rcus_gpios_data_init_ptr, sln2663_rcu_gpio_data_init_ptr *found_rcu);

/*!
    \brief      Locate an RCU in the GPIO entity list.
    \param[in]  rcus_gpios_data_init_ptr
    \param[out] none
    \retval     none
*/
sln2663_rcu_gpio_data_init_ptr *sln2663_gpio_find_rcu(sln2663_rcu_gpio_data_init_ptr *first_rcus_gpios_data_init_ptr,
                                                      sln2663_rcu_gpio_data_init_ptr *current_rcus_gpios_data_init_ptr);

// ---------------------------------------------------------------------
// Public Bodies
// ---------------------------------------------------------------------
/*!
    \brief      GPIOs initialization function.
    \param[in]  rcus_gpios_data_init_ptr
    \param[out] none
    \retval     none
*/
void sln2663_gpios_init(sln2663_rcu_gpio_data_init_ptr *rcus_gpios_data_init_ptr)
{
    if (rcus_gpios_data_init_ptr != END_OF_RCU_GPIO_LIST)
    {
        sln2663_rcu_gpio_data_init_ptr *first_rcu_gpio_data_init_ptr;

        first_rcu_gpio_data_init_ptr = rcus_gpios_data_init_ptr;
        // The first time we should not try to locate a previous initialized RCU.
        sln2663_gpio_init(*rcus_gpios_data_init_ptr, RCU_NOT_FOUND);
        rcus_gpios_data_init_ptr++;
        while (*rcus_gpios_data_init_ptr != END_OF_RCU_GPIO_LIST)
        {
            sln2663_gpio_init(*rcus_gpios_data_init_ptr, sln2663_gpio_find_rcu(first_rcu_gpio_data_init_ptr, rcus_gpios_data_init_ptr));
            rcus_gpios_data_init_ptr++;
        }
    }
}

// ---------------------------------------------------------------------
// Private Bodies
// ---------------------------------------------------------------------
/*!
    \brief      Locate an RCU in the GPIO entity list.
    \param[in]  rcus_gpios_data_init_ptr
    \param[out] none
    \retval     none
*/
sln2663_rcu_gpio_data_init_ptr *sln2663_gpio_find_rcu(sln2663_rcu_gpio_data_init_ptr *first_rcus_gpios_data_init_ptr, sln2663_rcu_gpio_data_init_ptr *current_rcus_gpios_data_init_ptr)
{
    sln2663_rcu_gpio_data_init_ptr *result;

    result = RCU_NOT_FOUND;

    while ((first_rcus_gpios_data_init_ptr != END_OF_RCU_GPIO_LIST) &&
           (first_rcus_gpios_data_init_ptr < current_rcus_gpios_data_init_ptr))
    {
        if ((*first_rcus_gpios_data_init_ptr)->rcu_periph_enable == (*current_rcus_gpios_data_init_ptr)->rcu_periph_enable)
        {
            result = first_rcus_gpios_data_init_ptr;
            // RCU found.
            break;
        }
        first_rcus_gpios_data_init_ptr++;
    }

    return result;
}

/*!
    \brief      GPIO initialization function.
    \param[in]  rcus_gpios_data_init_ptr
    \param[in]  found_rcu
    \param[out] none
    \retval     none
*/
void sln2663_gpio_init(sln2663_rcu_gpio_data_init_ptr rcus_gpios_data_init_ptr, sln2663_rcu_gpio_data_init_ptr *found_rcu)
{
    if (rcus_gpios_data_init_ptr != END_OF_RCU_GPIO_LIST)
    {
        if (found_rcu == RCU_NOT_FOUND)
        {
            sln2663_rcu_init(rcus_gpios_data_init_ptr->rcu_periph_enable);
        }
        gpio_init(rcus_gpios_data_init_ptr->gpio_data_init.port,
                  rcus_gpios_data_init_ptr->gpio_data_init.mode,
                  rcus_gpios_data_init_ptr->gpio_data_init.frequency,
                  rcus_gpios_data_init_ptr->gpio_data_init.pin);
        GPIO_BOP(rcus_gpios_data_init_ptr->gpio_data_init.port) = rcus_gpios_data_init_ptr->gpio_data_init.pin;
    }
}
