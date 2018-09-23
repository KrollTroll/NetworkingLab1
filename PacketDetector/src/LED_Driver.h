/*
 * LED_Driver.h
 *
 *  Created on: Sep 23, 2018
 *      Author: krollcj
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "GPIO.h"

//LED initializer method
void init_led_pins();
//set individual LED
void set_LED(char position);
//set all LEDs
void set_All_LEDS();
//clear all LEDs
void clear_LEDS();

#endif /* LED_DRIVER_H_ */
