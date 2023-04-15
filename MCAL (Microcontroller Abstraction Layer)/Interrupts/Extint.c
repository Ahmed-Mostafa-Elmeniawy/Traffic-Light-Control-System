#include "../../Utilities/Types.h"
#include "../../Utilities/Macros.h"
#include "../../Utilities/Registers.h"
#include "Extint.h"

void (*Callback_Int0) (void) = NULL_PTR;
void (*Callback_Int1) (void) = NULL_PTR;
void (*Callback_Int2) (void) = NULL_PTR;

ISR(VECTOR_INT0)
{
	if (NULL_PTR != Callback_Int0) {
		Callback_Int0();
	}
}
/*
ISR(VECTOR_INT1)
{
	if (NULL_PTR != Callback_Int1) {
		Callback_Int1();
	}
}

ISR(VECTOR_INT2)
{
	if (NULL_PTR != Callback_Int2) {
		Callback_Int2();
	}
}
*/
Extint_ErrorType ExtInt_Init(ExtInt_ChannelType channel)
{
	Extint_ErrorType ErrorState = EXTINT_ERROR_STATE_WRONG;
	
	switch (channel)
	{
		case EXTINT_CHANNEL_INT0:
		Dio_SetPinMode(EXTINT_PIN_INT0, DIO_MODE_INPUT_PULLUP);
		ErrorState = EXTINT_ERROR_STATE_OK;
			break;

		case EXTINT_CHANNEL_INT1:
		Dio_SetPinMode(EXTINT_PIN_INT1, DIO_MODE_INPUT_PULLUP);
		ErrorState = EXTINT_ERROR_STATE_OK;
			break;

		case EXTINT_CHANNEL_INT2:
		Dio_SetPinMode(EXTINT_PIN_INT2, DIO_MODE_INPUT_PULLUP);
		ErrorState = EXTINT_ERROR_STATE_OK;
			break;
			
		default:
			break;
	}
	
	
	return ErrorState;
}

Extint_ErrorType ExInt_SetCallback(ExtInt_ChannelType channel, void (*funcPtr) (void))
{
	Extint_ErrorType ErrorState = EXTINT_ERROR_STATE_WRONG;
	
	switch (channel)
	{
		case EXTINT_CHANNEL_INT0:
		Callback_Int0 = funcPtr;
		ErrorState = EXTINT_ERROR_STATE_OK;
			break;
		case EXTINT_CHANNEL_INT1:
		Callback_Int1 = funcPtr;
		ErrorState = EXTINT_ERROR_STATE_OK;
			break;
		case EXTINT_CHANNEL_INT2:
		Callback_Int2 = funcPtr;
		ErrorState = EXTINT_ERROR_STATE_OK;
			break;
		
		default:
			break;
	}
	
	
	return ErrorState;
}

Extint_ErrorType ExtInt_SetTriggerEdge(ExtInt_ChannelType channel, ExtInt_TriggerEdgeType edge)
{
	Extint_ErrorType ErrorState = EXTINT_ERROR_STATE_WRONG;
	
	switch (channel)
	{
	case EXTINT_CHANNEL_INT0:
		switch (edge)
		{
		case EXTINT_TRIGGER_LOW_LEVEL:
			CLR_BIT(MCUCR, MCUCR_ISC10);
			CLR_BIT(MCUCR, MCUCR_ISC11);
			ErrorState = EXTINT_ERROR_STATE_OK;
			break;
		case EXTINT_TRIGGER_ON_CHANGE:
			SET_BIT(MCUCR, MCUCR_ISC10);
			CLR_BIT(MCUCR, MCUCR_ISC11);
			ErrorState = EXTINT_ERROR_STATE_OK;
			break;
		case EXTINT_TRIGGER_FALLING_EDGE:
			CLR_BIT(MCUCR, MCUCR_ISC10);
			SET_BIT(MCUCR, MCUCR_ISC11);
			ErrorState = EXTINT_ERROR_STATE_OK;
			break;
		case EXTINT_TRIGGER_RISING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC10);
			SET_BIT(MCUCR, MCUCR_ISC11);
			ErrorState = EXTINT_ERROR_STATE_OK;
			break;
		}
		break;
	case EXTINT_CHANNEL_INT1:
		switch (edge)
		{
			case EXTINT_TRIGGER_LOW_LEVEL:
				CLR_BIT(MCUCR, MCUCR_ISC00);
				CLR_BIT(MCUCR, MCUCR_ISC01);
				ErrorState = EXTINT_ERROR_STATE_OK;
				break;
			case EXTINT_TRIGGER_ON_CHANGE:
				SET_BIT(MCUCR,  MCUCR_ISC00);
				CLR_BIT(MCUCR,  MCUCR_ISC01);
				ErrorState = EXTINT_ERROR_STATE_OK;
				break;
			case EXTINT_TRIGGER_FALLING_EDGE:
				CLR_BIT(MCUCR,  MCUCR_ISC00);
				SET_BIT(MCUCR,  MCUCR_ISC01);
				ErrorState = EXTINT_ERROR_STATE_OK;
				break;
			case EXTINT_TRIGGER_RISING_EDGE:
				SET_BIT(MCUCR,  MCUCR_ISC00);
				SET_BIT(MCUCR,  MCUCR_ISC01);
				ErrorState = EXTINT_ERROR_STATE_OK;
				break;
		}
		break;
	case EXTINT_CHANNEL_INT2:
		switch (edge)
		{
		case EXTINT_TRIGGER_FALLING_EDGE:
			CLR_BIT(MCUCSR, MCUCSR_ISC2);
			ErrorState = EXTINT_ERROR_STATE_OK;
			break;
		case EXTINT_TRIGGER_RISING_EDGE:
			SET_BIT(MCUCSR, MCUCSR_ISC2);
			ErrorState = EXTINT_ERROR_STATE_OK;
			break;
		}
		break;
	default:  
		/*Do Nothing*/
		break;
	}
	
	
	return ErrorState;
}


Extint_ErrorType ExtInt_EnableNotification(ExtInt_ChannelType channel)
{
	Extint_ErrorType ErrorState = EXTINT_ERROR_STATE_WRONG;
	
	switch (channel)
	{
	case EXTINT_CHANNEL_INT0:
		SET_BIT(GICR, GICR_INT0);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	case EXTINT_CHANNEL_INT1:
		SET_BIT(GICR, GICR_INT1);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	case EXTINT_CHANNEL_INT2:
		SET_BIT(GICR, GICR_INT2);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	default:
		break;
	}
	
	return ErrorState;
}


Extint_ErrorType ExtInt_DisableNotification(ExtInt_ChannelType channel)
{
	Extint_ErrorType ErrorState = EXTINT_ERROR_STATE_WRONG;
	
	switch (channel)
	{
	case EXTINT_CHANNEL_INT0:
		CLR_BIT(GICR, GICR_INT0);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	case EXTINT_CHANNEL_INT1:
		CLR_BIT(GICR, GICR_INT1);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	case EXTINT_CHANNEL_INT2:
		CLR_BIT(GICR, GICR_INT2);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	default:
		break;
	}
	
	return ErrorState;
}


Extint_ErrorType ExtInt_ClearFlag(ExtInt_ChannelType channel)
{
	Extint_ErrorType ErrorState = EXTINT_ERROR_STATE_WRONG;

	switch (channel)
	{
	case EXTINT_CHANNEL_INT0:
		SET_BIT(GIFR, GIFR_INTF0);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	case EXTINT_CHANNEL_INT1:
		SET_BIT(GIFR, GIFR_INTF1);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	case EXTINT_CHANNEL_INT2:
		SET_BIT(GIFR, GIFR_INTF2);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	default:
		break;
		
	return ErrorState;
	}
}

Extint_ErrorType ExtInt_ReadFlag(ExtInt_ChannelType channel, uint8_t* retrunFlagValue)
{
	Extint_ErrorType ErrorState = EXTINT_ERROR_STATE_WRONG;
	
	switch (channel)
	{
	case EXTINT_CHANNEL_INT0:
		*retrunFlagValue = GET_BIT(GIFR, GIFR_INTF0);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	case EXTINT_CHANNEL_INT1:
		*retrunFlagValue = GET_BIT(GIFR, GIFR_INTF1);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	case EXTINT_CHANNEL_INT2:
		*retrunFlagValue = GET_BIT(GIFR, GIFR_INTF2);
		ErrorState = EXTINT_ERROR_STATE_OK;
		break;
	default:
		break;
	}

	return ErrorState;
}