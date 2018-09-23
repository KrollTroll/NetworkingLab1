/*
 * DataLineTimer.c
 *
 *  Created on: Sep 23, 2018
 *      Author: krollcj
 */

#include "DataLineTimer.h"

//initialization for TIM4 and it's interrupt
void TIM4_Config()
{
    //TIM4 INITIALIZATION
    *(RCC_APB1ENR) |= (1<<TIM4EN);

    //load ARR with value for 1ms time
    *(TIM4_ARR) |= delay_ms* 100;

    //enable interrupt
    *(TIM4_DIER) |= (1);
    //enable timer
    *(TIM4_CR1) |= (1);

    //enable TIM4 interrupt in NVIC
    *(NVIC_ISER0) |= (1 << TIM4_ISREN);
}

//initialization for EXTI interrupt enables
void EXTI_Config(){

    //enable SYSCFG
    *(RCC_APB2ENR) |= (1 << SYSCFG_EN);

    //connect PA1 to EXTI1
    *(SYSCFG_EXTICR1) &= (0x0<<4);

    //unmask EXTI1 in EXTI
    *(EXTI_IMR) |= (0x2);

    //set for rising and falling
    *(EXTI_RTSR) |= (0x2);
    *(EXTI_FTSR) |= (0x2);

    //enable in NVIC, EXTI lines 9:5
    *(NVIC_ISER0) |= (1 << EXTI_1_ISREN);
}
