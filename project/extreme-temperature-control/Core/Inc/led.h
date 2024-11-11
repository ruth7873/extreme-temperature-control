/*
 * led.h
 *
 *  Created on: May 28, 2024
 *      Author: hitmachut
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"

typedef enum Led_Status{
	xOn=0,
	xOff,
	xBlink
}Led_Status;
static Led_Status led_s;


void init_led(void);
void led_on(void);
void led_off(void);
void blink(uint32_t frequency);
void led_pwm(TIM_HandleTypeDef *htim3,uint16_t pulseWidth);
void task_blink_led();


#endif /* INC_LED_H_ */
