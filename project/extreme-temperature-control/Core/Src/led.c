/*
 * led.c
 *
 *  Created on: May 28, 2024
 *      Author: hitmachut
 */

#include "led.h"


void init_led(void){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10 , GPIO_PIN_RESET);
}
void led_on(void){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10 , GPIO_PIN_SET);
}
void led_off(void){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10 , GPIO_PIN_RESET);
}
void led_blink(uint32_t frequency){
	while(1){
		led_on();
		HAL_Delay(frequency);
		led_off();
		HAL_Delay(frequency);
	}
}
void led_pwm(TIM_HandleTypeDef *htim3,uint16_t pulseWidth){
	TIM_OC_InitTypeDef sConfigOC;
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = pulseWidth;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(htim3, &sConfigOC, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(htim3, TIM_CHANNEL_1);
}

void task_blink_led(){
	while(1)
	{
		if(led_s==xOn)
			led_on();
		else if(led_s==xOff)
			led_off();
		else
			led_blink(100);
		vTaskDelay(50);

	}
}
