/*
 * This file is part of the LibreRVAC project
 *
 * Copyright © 2015-2016
 *     Aleks-Daniel Jakimenko-Aleksejev <alex.jakimenko@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <8051.h>
#include "setup.h"
#include "uart.h"
#include "timing.h"
#include "cordlib/cord_init.h"
#include "cordlib/cord_hw.h"

#define FIRMWARE_VERSION "0.0.1"

const char* get_version() {
    return FIRMWARE_VERSION;
}


#include "pinout.h"
void step() {
    uart_step();
    //bumper_step();
    //leds_step();
}

void main() {
    // set_callback_get_version(&get_version);
    set_callback_setup(&setup);
    set_callback_step(&step);
    set_callback_get_time(&get_time);
    set_callback_get_milliseconds(&get_milliseconds);
    // set_callback_process_beeps(&process_beeps);
    // set_callback_set_motor_throttle(&set_motor_throttle);
    // set_callback_get_battery_status(&get_battery_status);
    // set_callback_get_battery_voltage(&get_battery_voltage_after_shunt);
    // set_callback_get_battery_current(&get_battery_current);
    // set_callback_get_battery_temperature(&get_battery_temperature);
    //setup();
    cord_event_init();
    while (1);
}
