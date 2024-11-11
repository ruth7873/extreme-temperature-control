/*
 * alarm.h
 *
 *  Created on: Jun 18, 2024
 *      Author: hitmachut
 */

#ifndef INC_ALARM_H_
#define INC_ALARM_H_

#include "main.h"

#define TEMP_LED_OFF 30
#define TEMP_LED_ON 50
#define TEMP_LED_BLINK 70

Status_t init_alarm();
void alarm_temperature();
void task_alarm();
#endif /* INC_ALARM_H_ */
//הועתק מברכי
