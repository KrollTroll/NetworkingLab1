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

    currentState = BUSY;
    clear_LEDS();
    set_LED('y');

    //enable timer
    *(TIM4_CR1) |= (1);
    //load ARR with value for 1ms time
    *(TIM4_ARR) |= delay_ms* 110;
}

void TIM4_IRQHandler (void)
{
    //clear flags
    *(TIM4_SR) &= ~(0x1);
    //disable timer
    *(TIM4_CR1) &= ~(1);

    if((*(GPIOA_IDR) & 0b10) == 0b10)
	{
		currentState = IDLE;
		clear_LEDS();
		set_LED('g');
	}
	else
	{
		currentState = COLLISION;
		clear_LEDS();
		set_LED('r');
	}
    }

int main(){
	init_led_pins();

	currentState = IDLE;
	set_LED('g');

	EXTI_Config();
	TIM4_Config();

	while(1){}
}
