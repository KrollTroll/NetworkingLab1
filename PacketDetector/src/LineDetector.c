/*
 * LineDetector.c
 *
 *  Created on: Sep 23, 2018
 *      Author: krollcj
 */
#include "GPIO.h"
#include "LED_Driver.h"

int main(){
	init_led_pins();
	init_input_pin();
	set_All_LEDS();
	while(1)
	{
		if((*(GPIOA_IDR) & 0b10) == 0b10)
		{
			set_All_LEDS();
		}
		else
		{
			clear_LEDS();
		}
	}
}

void init_input_pin()
{
	//*(GPIOA_IDR) &= 0x00000000;
	//set PA3 for input
	//*(GPIOA_MODER) &= (0xFFFFFF3F);
	}
