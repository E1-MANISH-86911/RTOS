/*
 * led.h
 *
 *  Created on: Oct 2, 2023
 *      Author: sunbeam
 */

#ifndef LED_H_
#define LED_H_

#include<stm32f407xx.h>

#define BV(n)	(1 << (n))

#define GPIOD_CLK_ENB	3

#define LED_GPIO	GPIOD

#define LED_GREEN	12
#define LED_ORANGE	13
#define LED_RED		14
#define LED_BLUE	15

void led_init(uint16_t pin);
void led_on(uint16_t pin);
void led_off(uint16_t pin);
void led_toggle(uint16_t pin);


#endif /* LED_H_ */
