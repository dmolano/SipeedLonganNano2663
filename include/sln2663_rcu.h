/* 
 * This file is part of the Sipeed Longan Nano Skeleton. Reset and clock unit (RCU).
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

#ifndef __SLN2663_RCU_H
#define __SLN2663_RCU_H

// ---------------------------------------------------------------------
// Public Constants
// ---------------------------------------------------------------------

// ---------------------------------------------------------------------
// Public Prototypes
// ---------------------------------------------------------------------

/*!
    \brief      RCUs initialization function.
    \param[in]  Pointer to a non-repeating list of rcu_periph_enum.
                The list will end when two contiguous items are repeated.
    \param[out] none
    \retval     none
*/
void sln2663_rcu_init(rcu_periph_enum *rcu_periph);

#endif // __SLN2663_RCU_H