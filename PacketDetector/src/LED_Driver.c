/*
 * LED_Driver.c
 *
 *  Created on: Sep 23, 2018
 *      Author: krollcj
 */

#include "LED_Driver.h"

void init_led_pins()
{
	//enable RCC for GPIOA
	*(RCC_AHB1ENR) |= (1<<GPIOAEN);

	//set ODR to output for PA5-7
	*(GPIOA_MODER) |= (0b010101<<10);
	}

void set_LED(char position)
{
	if(position == 'r')
	{
		*(GPIOA_ODR) |= (0b1<<5);
	}
	else if(position == 'y')
	{
		*(GPIOA_ODR) |= (0b1<<6);
	}
	else if(position == 'g')
	{
		*(GPIOA_ODR) |= (0b1<<7);
	}
	}

void set_All_LEDS()
{
	*(GPIOA_ODR) |= (0b111<<5);
	}

void clear_LEDS()
{
	*(GPIOA_ODR) &= (0x00000000);
	}
