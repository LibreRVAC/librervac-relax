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

#pragma once
#include <8051.h>

#define PIN_ENCODER_RIGHT_WHEEL       P0_0
#define PIN_SENSOR_BOTTOM_RIGHT_RIGHT P0_1 // TODO what?
#define PIN_SENSOR_WALL               P0_2
#define PIN_SENSOR_BOTTOM_FRONT_RIGHT P0_3
#define PIN_ENCODER_LEFT_WHEEL        P0_4
#define PIN_UNKNOWN_SERVICE           P0_5
#define PIN_SENSOR_BOTTOM_FRONT_LEFT  P0_6
#define PIN_SENSOR_BOTTOM_LEFT_LEFT   P0_7

//#define PIN_SENSOR_WALL P1_0 // TODO that's photoresistor
#define PIN_CURRENT_SENSE_MOTOR_RIGHT P1_1
#define PIN_BATTERY_OK                P1_2
#define PIN_MOTOR_RIGHT_BACK          P1_3
#define PIN_MOTOR_RIGHT_FORWARD       P1_4
#define PIN_CURRENT_SENSE_VACUUM_AND_SIDE_BRUSH P1_5
#define PIN_MOTOR_VACUUM_AND_SIDE_BRUSH P1_6
#define PIN_WHEEL_RIGHT_LIFT          P1_7


#define PIN_MOTOR_LEFT_BACK           P2_0
#define PIN_MOTOR_LEFT_FORWARD        P2_1
#define PIN_SENSOR_LEFT               P2_2 // TODO what?
#define PIN_BUZZER                    P2_3
#define PIN_CURRENT_SENSE_BRUSH       P2_4
#define PIN_MOTOR_MAIN_BRUSH          P2_5
#define PIN_CURRENT_SENSE_MOTOR_LEFT  P2_6
#define PIN_SENSORS_ALL               P2_7

/*
// These are now connected to the linux board
#define PIN_LED_3       P3_0
#define PIN_BUTTON_3    P3_1
#define PIN_BUTTON_2    P3_2
#define PIN_BUTTON_1    P3_3
#define PIN_LEDS_OK     P3_4
#define PIN_LED_UNKNOWN P3_5
#define PIN_LED_2       P3_6
#define PIN_LED_1       P3_7
*/
