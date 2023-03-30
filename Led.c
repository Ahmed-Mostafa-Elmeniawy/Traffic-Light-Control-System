#include "../../Utilities/Types.h"
#include "../../MCAL (Microcontroller Abstraction Layer)/DIO/Dio.h"
#include "../../Utilities/Macros.h"
#include "Led.h"

/********************************	Functions for 1st led ********************************/

Led_ErrorType Led_init(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinMode(LED_PORT_CAR, LED_PIN, DIO_MODE_OUTPUT);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOn(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_CAR, LED_PIN, LED_ON);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOff(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_CAR, LED_PIN, LED_OFF);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}



/********************************	Functions for 2nd led ********************************/

Led_ErrorType Led_init2(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinMode(LED_PORT_CAR, LED_PIN2, DIO_MODE_OUTPUT);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOn2(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_CAR, LED_PIN2, LED_ON);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOff2(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_CAR, LED_PIN2, LED_OFF);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}



/********************************	Functions for 3rd led ********************************/

Led_ErrorType Led_init3(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinMode(LED_PORT_CAR, LED_PIN3, DIO_MODE_OUTPUT);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOn3(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_CAR, LED_PIN3, LED_ON);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOff3(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_CAR, LED_PIN3, LED_OFF);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


/********************************	Functions for 4th led ********************************/

Led_ErrorType Led_init4(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinMode(LED_PORT_PED, LED_PIN4, DIO_MODE_OUTPUT);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOn4(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_PED, LED_PIN4, LED_ON);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOff4(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_PED, LED_PIN4, LED_OFF);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


/********************************	Functions for 5th led ********************************/

Led_ErrorType Led_init5(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinMode(LED_PORT_PED, LED_PIN5, DIO_MODE_OUTPUT);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOn5(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_PED, LED_PIN5, LED_ON);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOff5(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_PED, LED_PIN5, LED_OFF);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


/********************************	Functions for 6th led ********************************/

Led_ErrorType Led_init6(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinMode(LED_PORT_PED, LED_PIN6, DIO_MODE_OUTPUT);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOn6(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_PED, LED_PIN6, LED_ON);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}


Led_ErrorType Led_TurnOff6(void)
{
	Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
	
	Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
	
	ErrorState_dio = Dio_SetPinLevel(LED_PORT_PED, LED_PIN6, LED_OFF);
	
	if (ErrorState_dio == DIO_ERROR_STATE_OK)
	{
		ErrorState_led = LED_ERROR_STATE_OK;
	}
	
	return ErrorState_led;
}
