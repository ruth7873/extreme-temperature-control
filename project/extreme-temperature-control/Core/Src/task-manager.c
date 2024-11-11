/*
 * task-manager.c
 *
 *  Created on: Jun 18, 2024
 *      Author: hitmachut
 */

#include "task-manager.h"
#include "led.h"
#include "alarm.h"

void create_tasks(TIM_HandleTypeDef *timer, ADC_HandleTypeDef *adc){
	create_read_distance_task(timer);
	create_measure_temperature_task(adc);
	create_alarm_task();
	create_led_operate();
}
void create_read_distance_task(TIM_HandleTypeDef *timer){
	xTaskCreate(task_periodic_measure_distance, "Read Distance", MIN_QUEUE_DEPTH, timer, READ_DISTANCE_TASK_PRIORITY, NULL);
}
void create_measure_temperature_task(ADC_HandleTypeDef *adc){
	xTaskCreate(task_measure_temperature, "Read Temp", MIN_QUEUE_DEPTH,	adc, MEASURE_TEMP_TASK_PRIORITY, NULL);
}
void create_alarm_task(){
	xTaskCreate(task_alarm, "Alarm Task", MIN_QUEUE_DEPTH, NULL, ALARM_TASK_PRIORITY, NULL);
}
void create_led_operate(){
	xTaskCreate(task_blink_led,"Led Operate",MIN_QUEUE_DEPTH,NULL,LED_OPERATE_PRIORITY,NULL);
}
