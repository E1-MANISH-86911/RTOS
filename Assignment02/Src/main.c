/*
**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void vLedTask(void *pvParam) {
    uint16_t *Data = (uint16_t *)pvParam;
    uint16_t ledno = (uint16_t *)Data[0];
    uint16_t rate = (uint16_t *)Data[1];
    while (1) {
        led_toggle(ledno);
        vTaskDelay(rate / portTICK_RATE_MS);
    }
    vTaskDelete(NULL);
}

int main(void) {
    led_init(12);
    led_init(13);
    led_init(14);
    led_init(15);

    static uint16_t led1[2] = {12, 1500};
    static uint16_t led2[2] = {13, 2000};
    static uint16_t led3[2] = {14, 1200};
    static uint16_t led4[2] = {15, 1000};
    xTaskCreate(vLedTask, "LED Task 1", configMINIMAL_STACK_SIZE, led1, 4, NULL);
    xTaskCreate(vLedTask, "LED Task 2", configMINIMAL_STACK_SIZE, led2, 4, NULL);
    xTaskCreate(vLedTask, "LED Task 3", configMINIMAL_STACK_SIZE, led3, 4, NULL);
    xTaskCreate(vLedTask, "LED Task 4", configMINIMAL_STACK_SIZE, led4, 4, NULL);

    vTaskStartScheduler();
    while (1);
}









