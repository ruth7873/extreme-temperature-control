/*
 * task_manager.h
 *
 *  Created on: Jun 18, 2024
 *      Author: hitmachut
 */

#ifndef INC_TASK_MANAGER_H_
#define INC_TASK_MANAGER_H_
#include "main.h"
#include "task.h"
#include "distance-sensor.h"
#include "temperature-sensor.h"



#define MIN_QUEUE_DEPTH 10
#define READ_DISTANCE_TASK_PRIORITY 8
#define MEASURE_TEMP_TASK_PRIORITY 10
#define ALARM_TASK_PRIORITY 12
#define LED_OPERATE_PRIORITY 14
#define FREQUENCY 200

void create_tasks(TIM_HandleTypeDef *timer, ADC_HandleTypeDef *adc);
void create_read_distance_task(TIM_HandleTypeDef *timer);
void create_measure_temperature_task(ADC_HandleTypeDef *adc);
void create_alarm_task();
void create_led_operate();

#endif /* INC_TASK_MANAGER_H_ */
