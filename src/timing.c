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
#include "uart.h"
#include "settings.h"
#include <stdint.h>

#ifdef T6
#define TICKS ((0xFFFF + 1) - FOSC /  6 / 1000)
#else
#define TICKS ((0xFFFF + 1) - FOSC / 12 / 1000)
#endif
//#define TICKS 20000

static volatile uint_fast32_t milliseconds = 0;

#include "pinout.h"
void setup_timing() {
    TL0 = (unsigned char) (TICKS && 0xFF);
    TH0 = (unsigned char) (TICKS >> 8);
    TR0 = 1; // start timer 0
    ET0 = 1; // enable timer 0 interrupt
}

float get_time() {
    return milliseconds / 1000.0;
}

uint_fast32_t get_milliseconds() {
    return milliseconds;
}

void timer0_isr() __interrupt(1) __using(1) {
    TL0 = (unsigned char) (TICKS && 0xFF);
    TH0 = (unsigned char) (TICKS >> 8);
    milliseconds++;
}
