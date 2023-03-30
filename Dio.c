#include "../../Utilities/Types.h"
#include "../../Utilities/Macros.h"
#include "../../Utilities/Registers.h"
#include "Dio.h"

Dio_ErrorType Dio_SetPinMode(Dio_PortType port, Dio_PinType pin, Dio_ModeType mode)
{
	Dio_ErrorType ErrorState = DIO_ERROR_STATE_WRONG;
	
	switch (port)
	{
	case DIO_PORTA:
		if (mode == DIO_MODE_INPUT_PULLUP)
		{
			CLR_BIT(DDRA, pin);
			SET_BIT(PORTA, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (mode == DIO_MODE_INPUT_FLOATING)
		{
			CLR_BIT(DDRA, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (mode == DIO_MODE_OUTPUT)
		{
			SET_BIT(DDRA, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else
		{
			/*Do nothing*/
		}
		break;
	case DIO_PORTB:
		if (mode == DIO_MODE_INPUT_PULLUP)
		{
			CLR_BIT(DDRB, pin);
			SET_BIT(PORTB, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (mode == DIO_MODE_INPUT_FLOATING)
		{
			CLR_BIT(DDRB, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (mode == DIO_MODE_OUTPUT)
		{
			SET_BIT(DDRB, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else
		{
			/*Do nothing*/
		}
		break;
	case DIO_PORTC:
		if (mode == DIO_MODE_INPUT_PULLUP)
		{
			CLR_BIT(DDRC, pin);
			SET_BIT(PORTC, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (mode == DIO_MODE_INPUT_FLOATING)
		{
			CLR_BIT(DDRC, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (mode == DIO_MODE_OUTPUT)
		{
			SET_BIT(DDRC, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else
		{
			/*Do nothing*/
		}
		break;
	case DIO_PORTD:
		if (mode == DIO_MODE_INPUT_PULLUP)
		{
			CLR_BIT(DDRD, pin);
			SET_BIT(PORTD, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (mode == DIO_MODE_INPUT_FLOATING)
		{
			CLR_BIT(DDRD, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (mode == DIO_MODE_OUTPUT)
		{
			SET_BIT(DDRD, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else
		{
			/*Do nothing*/
		}
		break;
	default:
		break;
	}

	return ErrorState;
}


Dio_ErrorType Dio_SetPinLevel(Dio_PortType port, Dio_PinType pin, Dio_LevelType level)
{
	Dio_ErrorType ErrorState = DIO_ERROR_STATE_WRONG;
	
	switch (port)
	{
	case DIO_PORTA:
		if (level == DIO_LEVEL_HIGH)
		{
			SET_BIT(PORTA, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (level == DIO_LEVEL_LOW)
		{
			CLR_BIT(PORTA, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else
		{
			/*Do nothing*/
		}
		break;
	case DIO_PORTB:
		if (level == DIO_LEVEL_HIGH)
		{
			SET_BIT(PORTB, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (level == DIO_LEVEL_LOW)
		{
			CLR_BIT(PORTB, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else
		{
			/*Do nothing*/
		}
		break;
	case DIO_PORTC:
		if (level == DIO_LEVEL_HIGH)
		{
			SET_BIT(PORTC, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (level == DIO_LEVEL_LOW)
		{
			CLR_BIT(PORTC, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else
		{
			/*Do nothing*/
		}
		break;
	case DIO_PORTD:
		if (level == DIO_LEVEL_HIGH)
		{
			SET_BIT(PORTD, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else if (level == DIO_LEVEL_LOW)
		{
			CLR_BIT(PORTD, pin);
			ErrorState = DIO_ERROR_STATE_OK;
		}
		else
		{
			/*Do nothing*/
		}
		break;
	default:
		break;
	}
	
	return ErrorState;
}


Dio_ErrorType Dio_ReadPin(Dio_PortType port, Dio_PinType pin, Dio_LevelType* level)
{
	Dio_ErrorType ErrorState = DIO_ERROR_STATE_WRONG;
	
	*level = DIO_LEVEL_LOW;
	switch (port)
	{
	case DIO_PORTA:
		*level = GET_BIT(PINA, pin);
		 ErrorState = DIO_ERROR_STATE_OK;
		break;
	case DIO_PORTB:
		*level = GET_BIT(PINB, pin);
		ErrorState = DIO_ERROR_STATE_OK;
		break;
	case DIO_PORTC:
		*level = GET_BIT(PINC, pin);
		ErrorState = DIO_ERROR_STATE_OK;
		break;
	case DIO_PORTD:
		*level = GET_BIT(PIND, pin);
		ErrorState = DIO_ERROR_STATE_OK;
		break;
	default:
		break;
	}

	return ErrorState;
}


Dio_ErrorType Dio_FlipPin(Dio_PortType port, Dio_PinType pin, Dio_LevelType* level)
{
	Dio_ErrorType ErrorState = DIO_ERROR_STATE_WRONG;
	
	*level = DIO_LEVEL_LOW;
	switch (port)
	{
	case DIO_PORTA:
		TOG_BIT(PORTA, pin);
		*level = GET_BIT(PINA, pin);
		ErrorState = DIO_ERROR_STATE_OK;
		break;
	case DIO_PORTB:
		TOG_BIT(PORTB, pin);
		*level = GET_BIT(PINB, pin);
		ErrorState = DIO_ERROR_STATE_OK;
		break;
	case DIO_PORTC:
		TOG_BIT(PORTC, pin);
		*level = GET_BIT(PINC, pin);
		ErrorState = DIO_ERROR_STATE_OK;
		break;
	case DIO_PORTD:
		TOG_BIT(PORTD, pin);
		*level = GET_BIT(PIND, pin);
		ErrorState = DIO_ERROR_STATE_OK;
		break;
	default:
		break;
	}

	return ErrorState;
}
