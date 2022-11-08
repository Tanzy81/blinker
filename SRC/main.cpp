/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "stdio.h"
#include "tempSense.h"
#include "constants.h"




// global variables

    DigitalOut led(LED1);
 

int main()
{
 
    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);

        float tempTherm = readTemp();
        printf("The Temperature is %2.1fC\n", tempTherm);
    }
}
