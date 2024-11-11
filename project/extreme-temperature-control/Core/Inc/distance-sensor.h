/*
 * distance-sensor.h
 *
 *  Created on: May 10, 2024
 *      Author: hitmachut
 */

#ifndef INC_DISTANCE_SENSOR_H_
#define INC_DISTANCE_SENSOR_H_

#include "main.h"

#define TRIG_PIN GPIO_PIN_8
#define TRIG_PORT GPIOA
#define ECHO_PIN GPIO_PIN_9
#define ECHO_PORT GPIOA
#define TIMER_GAP 10
#define SPEED_OF_SOUND 0.0343

static float Distance;

Status_t init_distance_sensor(TIM_HandleTypeDef * timer);
int read_distance(TIM_HandleTypeDef *sensorTimer);
void task_periodic_measure_distance(void *timer);

#endif /* INC_DISTANCE_SENSOR_H_ */
