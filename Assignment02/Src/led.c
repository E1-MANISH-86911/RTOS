/*
 * led.c
 *
 *  Created on: Oct 2, 2023
 *      Author: sunbeam
 */
#include"led.h"

void led_init(uint16_t pin)
{
	// enable clock for gpio D port
	RCC->AHB1ENR |= BV(GPIOD_CLK_ENB);

	// select mode of GPIO pins as output
	LED_GPIO->MODER |= BV(2 * pin);
	LED_GPIO->MODER &= ~BV(2 * pin + 1);

	// select output type as push pull
	LED_GPIO->OTYPER &= ~BV(pin);

	// select output speed as low
	LED_GPIO->OSPEEDR &= ~(BV(2 * pin ) | BV(2 * pin + 1));

	// do not select pull up / pull down resistor
	LED_GPIO->PUPDR &=~(BV(2 * pin ) | BV(2 * pin + 1));
}
void led_on(uint16_t pin)
{
	// write 1 on respective bits of ODR
	LED_GPIO->ODR |= BV(pin);
}
void led_off(uint16_t pin)
{
	// write 0 on respective bits of ODR
	LED_GPIO->ODR &= ~BV(pin);
}
void led_toggle(uint16_t pin)
{
	LED_GPIO->ODR ^= BV(pin);
}
