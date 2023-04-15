/*
 * Dio.h
 *
 *  Created on: Feb 1, 2023
 *      Author: mirage
 */

#ifndef INC_DIO_H_
#define INC_DIO_H_

/***************************** Types definitions *****************************/

typedef enum {
	DIO_MODE_INPUT_FLOATING,
	DIO_MODE_INPUT_PULLUP,
	DIO_MODE_OUTPUT
}Dio_ModeType;

typedef enum {
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}Dio_PortType;

typedef enum {
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,
}Dio_PinType;

typedef enum {
	DIO_LEVEL_LOW,
	DIO_LEVEL_HIGH
}Dio_LevelType;

typedef enum {
	DIO_ERROR_STATE_OK,
	DIO_ERROR_STATE_WRONG
}Dio_ErrorType;

/******************************* Functions prototype *******************************/



/// <summary>
/// The fuction sets the dicrection of the pin (input or output)
/// </summary>
/// <param name="port: ">	The port that contains the connected pin		</param>		
/// <param name="pin:  ">	The connected pin								</param>		
/// <param name="mode: ">	Direction of the pin (input or output)			</param>		
Dio_ErrorType Dio_SetPinMode(Dio_PortType port, Dio_PinType pin, Dio_ModeType mode);



/// <summary>
/// The fuction sets the value of the pin (HIGH or LOW)
/// </summary>
/// <param name="port:	">	The port that contains the connected pin		</param>		
/// <param name="pin:	">	The connected pin								</param>
/// <param name="level: ">	The pin value (HIGH or LOW)						</param>	
Dio_ErrorType Dio_SetPinLevel(Dio_PortType port, Dio_PinType pin, Dio_LevelType level);



/// <summary>
/// The fuction reads the pin value 
/// </summary>
/// <param name="port: ">	The port that contains the connected pin		</param>		
/// <param name="pin:  ">	The connected pin								</param>
/// <returns>				The pin value									</returns>				 
Dio_ErrorType Dio_ReadPin(Dio_PortType port, Dio_PinType pin, Dio_LevelType* level);



/// <summary>
/// The fuction flips the pin value
/// </summary>
/// <param name="port: ">	The port that contains the connected pin		</param>		
/// <param name="pin:  ">	The connected pin								</param>
/// <returns>				The new value/state								</returns>				
Dio_ErrorType Dio_FlipPin(Dio_PortType port, Dio_PinType pin, Dio_LevelType* level);

#endif /* INC_DIO_H_ */
