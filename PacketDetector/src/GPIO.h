#ifndef GPIO_H_
#define GPIO_H_

#include <inttypes.h>
#include <stdio.h>

//RCC Registers
#define RCC_AHB1ENR (volatile uint32_t*) 0x40023830
#define RCC_APB1ENR (volatile uint32_t*) 0x40023840
#define RCC_APB2ENR (volatile uint32_t*) 0x40023844

#define GPIOAEN 0
#define GPIOBEN 1

// GPIOA registers
#define GPIOA_MODER (volatile uint32_t*) 0x40020000
#define GPIOA_ODR (volatile uint32_t*) 0x40020014
#define GPIOA_IDR (volatile uint32_t*) 0x40020010

//GPIOB registers
#define GPIOB_MODER (volatile uint32_t*) 0x40020400
#define GPIOB_ODR (volatile uint32_t*) 0x40020414

#endif /* GPIO_H_ */
