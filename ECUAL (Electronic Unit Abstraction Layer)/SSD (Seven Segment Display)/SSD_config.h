/*
 * SSD_config.h
 *
 *  Created on: Feb 3, 2023
 *      Author: mirage
 */

#ifndef INC_SSD_CONFIG_H_
#define INC_SSD_CONFIG_H_

#include"Dio.h"

#define SSD_COMMON_CATHODE			0
#define SSD_COMMON_ANODE			1
#define SSD_TYPE					SSD_COMMON_CATHODE

#if SSD_TYPE == SSD_COMMON_CATHODE
		#define SSD_ON				DIO_LEVEL_HIGH
		#define SSD_OFF				DIO_LEVEL_LOW
#elif SSD_TYPE == SSD_COMMON_ANODE
		#define SSD_ON				DIO_LEVEL_LOW
		#define SSD_OFF				DIO_LEVEL_HIGH
#else
		#error "Invalid SSD type"
#endif

#define SSD_PORT					DIO_PORTA

#define SSD_PINA					DIO_PIN0
#define SSD_PINB					DIO_PIN1
#define SSD_PINC					DIO_PIN2
#define SSD_PIND					DIO_PIN3
#define SSD_PINE					DIO_PIN4
#define SSD_PINF					DIO_PIN5
#define SSD_PING					DIO_PIN6
#define SSD_DOT						DIO_PIN7


/******************** For a second ssd ********************/
#define SSD_PORT2					DIO_PORTD


#endif /* INC_SSD_CONFIG_H_ */
