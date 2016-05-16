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

#include "cordlib/cord_connection.h"

#include <8051.h>
#include <stdbool.h>
#include "settings.h"

#define NONE_PARITY      0
#define ODD_PARITY       1
#define EVEN_PARITY      2
#define MARK_PARITY      3
#define SPACE_PARITY     4

#define PARITYBIT NONE_PARITY

volatile bool transmitting;

void setup_uart() {
#if (PARITYBIT == NONE_PARITY)
    SCON = 0x50;
#elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
    SCON = 0xda;
#elif (PARITYBIT == SPACE_PARITY)
    SCON = 0xd2;
#endif

#ifdef T6
    TH1 = TL1 = -(FOSC /  6 / 32 / BAUD); // auto-reload vaule
#else
    TH1 = TL1 = -(FOSC / 12 / 32 / BAUD); // auto-reload vaule
#endif
    TR1 = 1; // start timer1
    ES = 1; // unable UART interrupt
}

void uart_step() {
    // TODO implement a callback in cordlib for that?
    if (!transmitting && cord_connection_output_size() > 0) {
        transmitting = true;
        SBUF = cord_connection_output_pull();
    }
}

void uart_isr() __interrupt (4) __using (1) {
    //char received;
    if (RI) { // Receive
        RI = 0; //Clear receive interrupt flag
        //received = SBUF;
        //chr++;
        //if (chr > 'z')
        //chr = 'a';
        //SBUF = received;
        //SBUF = received + 1;
        cord_connection_input_put(SBUF);
    }
    if (TI) { // Send
        TI = 0; //Clear transmit interrupt flag
        if (cord_connection_output_size() > 0)
            SBUF = cord_connection_output_pull();
        else
            transmitting = false;
    }
}
