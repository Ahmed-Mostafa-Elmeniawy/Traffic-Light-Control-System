#ifndef INC_LED_H_
#define INC_LED_H_

#include "Dio.h"
#include "Led_config.h"


typedef enum{
	LED_ERROR_STATE_OK,
	LED_ERROR_STATE_WRONG
}Led_ErrorType;


Led_ErrorType Led_Init (Dio_PortType port, Dio_PinType pin);
Led_ErrorType Led_TurnOn (Dio_PortType port, Dio_PinType pin);
Led_ErrorType Led_TurnOff (Dio_PortType port, Dio_PinType pin);

/********* In both functions you need to write the LED_PORT and LED_PIN as parameters to the function *********/
#define Led_Flip			Dio_FlipPin
#define Led_ReadState		Dio_ReadPin



#endif /* INC_LED_H_ */
