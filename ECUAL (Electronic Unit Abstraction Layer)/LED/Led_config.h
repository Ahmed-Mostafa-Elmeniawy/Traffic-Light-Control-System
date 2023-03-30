/*
 * Led_config.h
 *
 *  Created on: Feb 3, 2023
 *      Author: mirage
 */

#ifndef INC_LED_CONFIG_H_
#define INC_LED_CONFIG_H_

#include "Dio.h"

#define LED_ON			DIO_LEVEL_HIGH
#define LED_OFF			DIO_LEVEL_LOW

#define LED_PORT_CAR	DIO_PORTA

#define LED_PORT_PED	DIO_PORTC


#define LED_PIN			DIO_PIN0
#define LED_PIN2		DIO_PIN1
#define LED_PIN3		DIO_PIN2

#define LED_PIN4		DIO_PIN0
#define LED_PIN5		DIO_PIN1
#define LED_PIN6		DIO_PIN2

#endif /* INC_LED_CONFIG_H_ */
