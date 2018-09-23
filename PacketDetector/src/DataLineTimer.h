/*
 * DataLineTimer.h
 *
 *  Created on: Sep 23, 2018
 *      Author: krollcj
 */

#ifndef DATALINETIMER_H_
#define DATALINETIMER_H_

#include "GPIO.h"

//TIM4 registers for interrupt help
#define TIM4_CR1 	(volatile uint32_t*) 0x40000800
#define TIM4_DIER 	(volatile uint32_t*) 0x4000080C
#define TIM4_SR 	(volatile uint32_t*) 0x40000810
#define TIM4_ARR 	(volatile uint32_t*) 0x4000082C
#define NVIC_ISER0 	(volatile uint32_t*) 0xE000E100

//syscfg/exti
#define SYSCFG_EXTICR1	(volatile uint32_t*) 0x40013808
#define EXTI_IMR		(volatile uint32_t*) 0x40013C00
#define EXTI_EMR		(volatile uint32_t*) 0x40013C04
#define EXTI_RTSR		(volatile uint32_t*) 0x40013C08
#define EXTI_FTSR		(volatile uint32_t*) 0x40013C0C
#define EXTI_SWIER		(volatile uint32_t*) 0x40013C10
#define EXTI_PR 		(volatile uint32_t*) 0x40013C14

//NVIC
#define NVIC_ISER0		(volatile uint32_t*) 0xE000E100

#define delay_ms 	16000
#define TIM4EN 		2
#define SYSCFG_EN   14
#define TIM4_ISREN	30
#define EXTI_1_ISREN 7

void TIM4_Config();

void EXTI_Config();

typedef enum
{
    IDLE,
    BUSY,
    COLLISION
} currentState_t;

#endif /* DATALINETIMER_H_ */
