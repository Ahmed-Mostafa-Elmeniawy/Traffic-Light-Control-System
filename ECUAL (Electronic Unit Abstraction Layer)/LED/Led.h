#ifndef INC_LED_H_
#define INC_LED_H_

#include "Dio.h"
#include "Led_config.h"


typedef enum{
	LED_ERROR_STATE_OK,
	LED_ERROR_STATE_WRONG
}Led_ErrorType;


/// <summary>
/// Initiates the led pin by setting it as an output pin
/// </summary>
Led_ErrorType Led_init(void);



/// <summary>
/// Turns on led
/// </summary>
Led_ErrorType Led_TurnOn(void);


/// <summary>
/// Turn off led
/// </summary>
Led_ErrorType Led_TurnOff(void);

/********* In both functions you need to write the LED_PORT and LED_PIN as parameters to the function *********/
#define Led_Flip			Dio_FlipPin
#define Led_ReadState		Dio_ReadPin

/********************************	Functions for 2nd led ********************************/
Led_ErrorType Led_init2(void);
Led_ErrorType Led_TurnOn2(void);
Led_ErrorType Led_TurnOff2(void);


/********************************	Functions for 3rd led ********************************/
Led_ErrorType Led_init3(void);
Led_ErrorType Led_TurnOn3(void);
Led_ErrorType Led_TurnOff3(void);

/********************************	Functions for 4th led ********************************/
Led_ErrorType Led_init4(void);
Led_ErrorType Led_TurnOn4(void);
Led_ErrorType Led_TurnOff4(void);

/********************************	Functions for 5th led ********************************/
Led_ErrorType Led_init5(void);
Led_ErrorType Led_TurnOn5(void);
Led_ErrorType Led_TurnOff5(void);

/********************************	Functions for 6th led ********************************/
Led_ErrorType Led_init6(void);
Led_ErrorType Led_TurnOn6(void);
Led_ErrorType Led_TurnOff6(void);


#endif /* INC_LED_H_ */
