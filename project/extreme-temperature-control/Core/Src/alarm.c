/*
 * alarm.c
 *
 *  Created on: Jun 18, 2024
 *      Author: hitmachut
 */

#include "alarm.h"
#include "main.h"

Status_t init_alarm(){
	init_led();
	return xSUCCESS;
}
void alarm_temperature(){
	int temp;
	Status_temperature temp_t;
	xSemaphoreTake(temperature_mutex,200);
	temp = temperature;
	xSemaphoreGive(temperature_mutex);

	if(temp>TEMP_LED_BLINK)
		temp_t = EXTREME_TEMPERATURE;
	else if(temp>TEMP_LED_ON)
		temp_t = HIGH_TEMPERATURE;
	else if(temp>TEMP_LED_OFF)
		temp_t = OK_TEMPERATURE;
	else
		temp_t = LOW_TEMPERATURE;

	xSemaphoreTake(temperature_t_mutex,200);
	temperature_t = temp;
	xSemaphoreGive(temperature_t_mutex);

}
void task_alarm(){
	while(1){
		alarm_temperature();
		vTaskDelay(100);
	}
}
