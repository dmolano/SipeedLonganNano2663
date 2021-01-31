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

#include "main.h"

#include "sln2663_led_1615.h"
#include "sln2663_time.h"

// ---------------------------------------------------------------------
// Private Constants
// ---------------------------------------------------------------------
#define NO_ERROR_INIT_SLN2663 0

#define FOREVER 1

// ---------------------------------------------------------------------
// Private Prototypes
// ---------------------------------------------------------------------
/*!
    \brief      init function
    \param[in]  sln2663_ptr Sipeed Longan Nano data
    \param[out] none
    \retval     system error
*/
int main_init(sln2663_ptr sln_data_ptr);

/*!
    \brief      loop function
    \param[in]  sln2663_ptr Sipeed Longan Nano data
    \param[out] none
    \retval     system error
*/
int main_loop(sln2663_ptr sln_data_ptr);

// ---------------------------------------------------------------------
// Bodies
// ---------------------------------------------------------------------
/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    sln2663 sln_data;
    int result;

    result = main_init(&sln_data);
    if (result == NO_ERROR_INIT_SLN2663)
    {
        result = main_loop(&sln_data);
    }
    return result;
}

/*!
    \brief      init function
    \param[in]  sipeed_longan_nano Sipeed Longan Nano data
    \param[out] none
    \retval     system error
*/
int main_init(sln2663_ptr sln_data_ptr)
{
    int result = NO_ERROR_INIT_SLN2663;

    sln2663_led_1615_init();

    return result;
}

/*!
    \brief      loop function
    \param[in]  sipeed_longan_nano Sipeed Longan Nano data
    \param[out] none
    \retval     system error
*/
int main_loop(sln2663_ptr sln_data_ptr)
{
    int result = NO_ERROR_INIT_SLN2663;
    int condition = FOREVER;

    while (condition == FOREVER)
    {
        sln2663_led_1615_red_flash_times(ONE_SECOND_TIME/10, 3, ONE_SECOND_TIME/10);
        sln2663_time_delay_ms(ONE_SECOND_TIME);
        // sln2663_led_1615_green_flash_times(ONE_SECOND_TIME/10, 3, ONE_SECOND_TIME/10);
        // sln2663_time_delay_ms(ONE_SECOND_TIME);
        // sln2663_led_1615_blue_flash_times(ONE_SECOND_TIME/10, 3, ONE_SECOND_TIME/10);
        // sln2663_time_delay_ms(ONE_SECOND_TIME);
    }
    return result;
}
