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


#define LED_PIN1_CAR			DIO_PORTA,DIO_PIN0
#define LED_PIN2_CAR			DIO_PORTA,DIO_PIN1
#define LED_PIN3_CAR			DIO_PORTA,DIO_PIN2

#define LED_PIN4_PED			DIO_PORTC,DIO_PIN0
#define LED_PIN5_PED			DIO_PORTC,DIO_PIN1
#define LED_PIN6_PED			DIO_PORTC,DIO_PIN2

#endif /* INC_LED_CONFIG_H_ */
