/*
 * temperature-sensor.c
 *
 *  Created on: May 28, 2024
 *      Author: hitmachut
 */


#include "temperature-sensor.h"

uint16_t adc_value;

Status_t init_temperature_sensor(ADC_HandleTypeDef *adc){
	HAL_ADC_Start(adc);
	return xSUCCESS;
}
int read_temperature(ADC_HandleTypeDef* adc){
	HAL_ADC_PollForConversion(adc, 50);
	adc_value = HAL_ADC_GetValue(adc);
	return (adc_value * (VOLOTAGE_SUPPLY / ANALOG_RANGE) )/ MILIVOLT_PER_SECOND;
}
void task_measure_temperature(void* adc){
	ADC_HandleTypeDef* hadc = (ADC_HandleTypeDef*)adc;
	while(1){
		xSemaphoreTake(temperature_mutex,200);
		temperature	= read_temperature(hadc);
		xSemaphoreGive(temperature_mutex);
		HAL_Delay(100);
	}
}
