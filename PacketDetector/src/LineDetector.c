/*
 * LineDetector.c
 *
 *  Created on: Sep 23, 2018
 *      Author: krollcj
 */
#include "GPIO.h"

int main(){
	init_led();
	*(GPIOA_ODR) |= (0b111<<5);
}

void init_led()
{
	//enable RCC for GPIOA
	*(RCC_AHB1ENR) |= (1<<GPIOAEN);

	//set ODR to output for PA5-7
	*(GPIOA_MODER) |= (0b010101<<10);
	}

