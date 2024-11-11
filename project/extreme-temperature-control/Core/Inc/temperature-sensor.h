/*
 * temperature_sensor.h
 *
 *  Created on: May 28, 2024
 *      Author: hitmachut
 */

#ifndef INC_TEMPERATURE_SENSOR_H_
#define INC_TEMPERATURE_SENSOR_H_

#include "main.h"


#define VOLOTAGE_SUPPLY 3300.0
#define ANALOG_RANGE 4096
#define MILIVOLT_PER_SECOND 10


//static float Temperature;
Status_t init_temperature_sensor(ADC_HandleTypeDef *adc);
int read_temperature(ADC_HandleTypeDef* adc);
void task_measure_temperature(void *);
#endif /* INC_TEMPERATURE_SENSOR_H_ */

