/*
 * LineDetector.c
 *
 *  Created on: Sep 23, 2018
 *      Author: krollcj
 */
#include "GPIO.h"
#include "LED_Driver.h"
#include "DataLineTimer.h"

static volatile currentState_t currentState;

void EXTI1_IRQHandler (void)
{
    //clear flags
    *(EXTI_PR) &= ~(0x20);

    switch(currentState)
        {
            case IDLE:
            	clear_LEDS();
            	currentState = BUSY;
            	set_LED('y');
                break;
            case BUSY:
                break;
            default:
            	clear_LEDS();
            	currentState = BUSY;
            	set_LED('y');
                break;
        }
}

int main(){
	init_led_pins();
	init_input_pin();

	currentState = IDLE;
	set_LED('g');

	EXTI_Config();


	while(1){}
}

void init_input_pin()
{
	//*(GPIOA_IDR) &= 0x00000000;
	//set PA3 for input
	//*(GPIOA_MODER) &= (0xFFFFFF3F);
	}
