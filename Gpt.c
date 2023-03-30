/*
 * Gpt.c
 *
 *  Created on: Feb 24, 2023
 *      Author: ahmad
 */


#include "../../Utilities/Types.h"
#include "../../Utilities/Registers.h"
#include "../../Utilities/Macros.h"
#include "../Interrupts/Interrupts.h"
#include "Gpt.h"

void (*Gpt_Callback_TIM0_COMP   )       (void) = NULL_PTR;
void (*Gpt_Callback_TIM0_OVF    )       (void) = NULL_PTR;
void (*Gpt_Callback_TIM1A_COMP  )       (void) = NULL_PTR;
void (*Gpt_Callback_TIM1B_COMP  )       (void) = NULL_PTR;
void (*Gpt_Callback_TIM1_OVF    )       (void) = NULL_PTR;
void (*Gpt_Callback_TIM1_CAPT   )       (void) = NULL_PTR;
void (*Gpt_Callback_TIM2_OVF    )       (void) = NULL_PTR;
void (*Gpt_Callback_TIM2_COMP   )       (void) = NULL_PTR;



ISR(VECTOR_TIM0_COMP) {
    if (NULL_PTR != Gpt_Callback_TIM0_COMP) {
        Gpt_Callback_TIM0_COMP();
    }
}

ISR(VECTOR_TIM0_OVF) {
    if (NULL_PTR != Gpt_Callback_TIM0_OVF) {
        Gpt_Callback_TIM0_OVF();
    }
}

ISR(VECTOR_TIM1_OVF)
{
    if (NULL_PTR != Gpt_Callback_TIM1_OVF) {
        Gpt_Callback_TIM1_OVF();
    }
}

/** TODO: Complete all ISRs (4 ISRs for Timer 1, 2 ISRs for Tomer 2)*/


Gpt_ErrorType Gpt_Init(Gpt_ChannelType channel, const Gpt_ConfigType* config)
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
    {
        switch (config->mode)
        {
        case GPT_MODE_NORMAL:
            CLR_BIT(TCCR0, 3);
            CLR_BIT(TCCR0, 6);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_MODE_CTC:
            CLR_BIT(TCCR0, 3);
            SET_BIT(TCCR0, 6);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        default:
            break;
        }
        switch (config->compareMode)
        {
        case GPT_COMP_OUT_MODE_DISCONNECTED:
            CLR_BIT(TCCR0, 4);
            CLR_BIT(TCCR0, 5);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_COMP_OUT_MODE_TOGGLE:
            SET_BIT(TCCR0, 4);
            CLR_BIT(TCCR0, 5);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_COMP_OUT_MODE_CLEAR:
            CLR_BIT(TCCR0, 4);
            SET_BIT(TCCR0, 5);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_COMP_OUT_MODE_SET:
            SET_BIT(TCCR0, 4);
            SET_BIT(TCCR0, 5);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        default:
            break;
        }
        break;
    }

    case GPT_CHANNEL_TIM1A:
    {
         switch (config->mode)
        {
        case GPT_MODE_NORMAL:
            CLR_BIT(TCCR1A, 0);
            CLR_BIT(TCCR1A, 1);
            CLR_BIT(TCCR1B, 3);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_MODE_CTC:
            CLR_BIT(TCCR1A, 0);
            CLR_BIT(TCCR1A, 1);
            SET_BIT(TCCR1B, 3);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        default:
            break;
        }
        switch (config->compareMode)
        {
        case GPT_COMP_OUT_MODE_DISCONNECTED:
            CLR_BIT(TCCR1A, 6);
            CLR_BIT(TCCR1A, 7);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_COMP_OUT_MODE_TOGGLE:
            SET_BIT(TCCR1A, 6);
            CLR_BIT(TCCR1A, 7);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_COMP_OUT_MODE_CLEAR:
            CLR_BIT(TCCR1A, 6);
            SET_BIT(TCCR1A, 7);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_COMP_OUT_MODE_SET:
            SET_BIT(TCCR1A, 6);
            SET_BIT(TCCR1A, 7);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        default:
            break;
        }
        break;
    }

    case GPT_CHANNEL_TIM1B:
    {
        switch (config->mode)
        {
        case GPT_MODE_NORMAL:
            CLR_BIT(TCCR1A, 0);
            CLR_BIT(TCCR1A, 1);
            CLR_BIT(TCCR1B, 3);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_MODE_CTC:
            CLR_BIT(TCCR1A, 0);
            CLR_BIT(TCCR1A, 1);
            SET_BIT(TCCR1B, 3);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        default:
            break;
        }
        switch (config->compareMode)
        {
        case GPT_COMP_OUT_MODE_DISCONNECTED:
            CLR_BIT(TCCR1A, 4);
            CLR_BIT(TCCR1A, 5);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_COMP_OUT_MODE_TOGGLE:
            SET_BIT(TCCR1A, 4);
            CLR_BIT(TCCR1A, 5);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_COMP_OUT_MODE_CLEAR:
            CLR_BIT(TCCR1A, 4);
            SET_BIT(TCCR1A, 5);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_COMP_OUT_MODE_SET:
            SET_BIT(TCCR1A, 4);
            SET_BIT(TCCR1A, 5);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        default:
            break;
        }
        break;
    }

    case GPT_CHANNEL_TIM2:
    {
        switch (config->mode)
        {
        case GPT_MODE_NORMAL:
            CLR_BIT(TCCR2, 4);
            CLR_BIT(TCCR2, 5);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        default:
            break;
        }
        switch (config->compareMode)
        {
        case GPT_COMP_OUT_MODE_DISCONNECTED:
            CLR_BIT(TCCR2, 4);
            CLR_BIT(TCCR2, 5);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        default:
            break;
        }
        break;
    }
    /** TODO: Complete all cases  TIM2 */
    default:
        break;
    }
	
	return ErrorState; 
}


Gpt_ErrorType Gpt_Start(Gpt_ChannelType channel, Gpt_PrescalerType prescaler) 
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
    {
        switch (prescaler)
        {
        case GPT_PRESCALER_1:
            SET_BIT(TCCR0, 0);
            CLR_BIT(TCCR0, 1);
            CLR_BIT(TCCR0, 2);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_PRESCALER_8:
            CLR_BIT(TCCR0, 0);
            SET_BIT(TCCR0, 1);
            CLR_BIT(TCCR0, 2);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_PRESCALER_64:
            SET_BIT(TCCR0, 0);
            SET_BIT(TCCR0, 1);
            CLR_BIT(TCCR0, 2);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_PRESCALER_256:
            CLR_BIT(TCCR0, 0);
            CLR_BIT(TCCR0, 1);
            SET_BIT(TCCR0, 2);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_PRESCALER_1024:
            SET_BIT(TCCR0, 0);
            CLR_BIT(TCCR0, 1);
            SET_BIT(TCCR0, 2);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_PRESCALER_EXT_FALLING:
            CLR_BIT(TCCR0, 0);
            SET_BIT(TCCR0, 1);
            SET_BIT(TCCR0, 2);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        case GPT_PRESCALER_EXT_RISING:
            SET_BIT(TCCR0, 0);
            SET_BIT(TCCR0, 1);
            SET_BIT(TCCR0, 2);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        default:
            break;
        }
        TCNT0 = 0;
        break;
    }
    break;

    case GPT_CHANNEL_TIM1:
    {
        switch (prescaler)
        {
        case GPT_PRESCALER_8:
            CLR_BIT(TCCR1B, 0);
            SET_BIT(TCCR1B, 1);
            CLR_BIT(TCCR1B, 2);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        }
    }
    break;

    case GPT_CHANNEL_TIM2:
    {
        switch (prescaler)
        {
        case GPT_PRESCALER_1024:
            SET_BIT(TCCR2, 0);
            SET_BIT(TCCR2, 1);
            SET_BIT(TCCR2, 2);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        }
    }
    break;
    default:
        break;
    }
	
	return ErrorState;
}


Gpt_ErrorType Gpt_Stop(Gpt_ChannelType channel) 
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        CLR_BIT(TCCR0, 2);
        CLR_BIT(TCCR0, 1);
        CLR_BIT(TCCR0, 0);
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_CHANNEL_TIM1:
        CLR_BIT(TCCR1A, 0);
        CLR_BIT(TCCR1A, 1);
        CLR_BIT(TCCR1B, 3);
        CLR_BIT(TCCR1B, 4);
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_CHANNEL_TIM2:
        CLR_BIT(TCCR2, 6);
        CLR_BIT(TCCR2, 3);
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    default:
        break;
    }
	
	return ErrorState;
}


Gpt_ErrorType Gpt_Reset(Gpt_ChannelType channel) 
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        TCNT0 = 0;
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_CHANNEL_TIM1:
        TCNT1L = 0; 
        TCNT1H = 0;
		ErrorState = GPT_ERROR_STATE_OK;
        break;
        /** TODO: Complete all Cases  TIM2 **/
    default:
        break;
    }
	
	return ErrorState;
}


Gpt_ErrorType Gpt_SetCounterValue(Gpt_ChannelType channel, uint16_t value) 
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        TCNT0 = value;
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_CHANNEL_TIM1:
        TCNT1L = ( (uint8_t) (value & 0x00FF) ); // Taking the first 8 bits 
        TCNT1H = ( (uint8_t) (value >> 8) );      // Taking the last 8 bits
		ErrorState = GPT_ERROR_STATE_OK;
        break;
        /** TODO: Complete all Cases TIM2 **/
    default:
        break;
    }
	
	return ErrorState;
}


Gpt_ErrorType Gpt_SetCompareValue(Gpt_CompareRegType reg, uint16_t value) 
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (reg)
    {
    case GPT_COMP_REG_TIM0:
        OCR0 = value;
		ErrorState = GPT_ERROR_STATE_OK;
        break;
        /** TODO: Complete all Cases (TIM1A, TIM1B, TIM2)*/
    default:
        break;
    }
	
	return ErrorState;
}


Gpt_ErrorType Gpt_EnableNotification(Gpt_InterruptSourceType source) 
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (source)
    {
    case GPT_INT_SOURCE_TIM0_COMP:
        SET_BIT(TIMSK, 1);
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_INT_SOURCE_TIM0_OVF:
        SET_BIT(TIMSK, 0);
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_INT_SOURCE_TIM1_OVF:
        SET_BIT(TIMSK, 2);
		ErrorState = GPT_ERROR_STATE_OK;
        break;
        /** TODO: Complete all Cases (4 ISRs for Timer 1, 2 ISRs for Tomer 2)*/
    default:
        break;
    }
	
	return ErrorState;
}


Gpt_ErrorType Gpt_DisableNotification(Gpt_InterruptSourceType source) 
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (source)
    {
    case GPT_INT_SOURCE_TIM0_COMP:
        CLR_BIT(TIMSK, 1);
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_INT_SOURCE_TIM0_OVF:
        CLR_BIT(TIMSK, 0);
		ErrorState = GPT_ERROR_STATE_OK;
        break;
        /** TODO: Complete all Cases (4 ISRs for Timer 1, 2 ISRs for Tomer 2)*/
    default:
        break;
    }
	
	return ErrorState;
}


Gpt_ErrorType Gpt_SetCallback(Gpt_InterruptSourceType source, void (*funcPtr) (void)) 
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (source)
    {
    case GPT_INT_SOURCE_TIM0_COMP:
        Gpt_Callback_TIM0_COMP = funcPtr;
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_INT_SOURCE_TIM0_OVF:
        Gpt_Callback_TIM0_OVF = funcPtr;
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_INT_SOURCE_TIM1_OVF:
        Gpt_Callback_TIM1_OVF = funcPtr;
		ErrorState = GPT_ERROR_STATE_OK;
        break;
        /** TODO: Complete all Cases (4 ISRs for Timer 1, 2 ISRs for Tomer 2)*/
    default:
        break;
    }
	
	return ErrorState;
}


Gpt_ErrorType Gpt_GetElapsedTime(Gpt_ChannelType channel, uint16_t* returnValue)
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        *returnValue = TCNT0;
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_CHANNEL_TIM1:
        /** TODO: */
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_CHANNEL_TIM2:
        /** TODO: */
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    default:
        break;
    }
    return ErrorState;
}


Gpt_ErrorType Gpt_GetOverflowFlag(Gpt_ChannelType channel, volatile uint8_t* returnValue)
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        *returnValue = GET_BIT(TIFR, 0);
		ErrorState = GPT_ERROR_STATE_OK;
        break;
    case GPT_CHANNEL_TIM2:
        *returnValue = GET_BIT(TIFR, 6);
		ErrorState = GPT_ERROR_STATE_OK;
        break;
        /* Continue the remaining cases of TIM1 */
    default:
        break;
    }

    return ErrorState;
}

Gpt_ErrorType Gpt_ClearFlag(Gpt_ChannelType channel, Gpt_InterruptSourceType interrupt_type)
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    switch (channel)
    {
    case GPT_CHANNEL_TIM0:
        switch (interrupt_type)
        {
        case GPT_INT_SOURCE_TIM0_OVF:
            SET_BIT(TIFR, 0);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        default:
            break;
        }
        /*Continue the rest*/
        break;

    case GPT_CHANNEL_TIM2:
        switch (interrupt_type)
        {
        case GPT_INT_SOURCE_TIM2_OVF:
            SET_BIT(TIFR, 6);
			ErrorState = GPT_ERROR_STATE_OK;
            break;
        default:
            break;
        }
        /*Continue the rest*/
        break;

        /*Continue the rest*/
    default:
        break;
    }
	
	return ErrorState;
}

Gpt_ErrorType Gpt_Delay(uint16_t milli_sec)
{
	Gpt_ErrorType ErrorState = GPT_ERROR_STATE_WRONG;
	
    volatile uint8_t overflow_counter = 0;
    volatile uint8_t No_of_overflows = 0;
	volatile uint8_t overflow_flag = 0;

    No_of_overflows = milli_sec / 33; // The number 33 is the overflow duration in milli-seconds of a 1024 prescaler

    Gpt_Start(GPT_CHANNEL_TIM2, GPT_PRESCALER_1024);

    while (overflow_counter < No_of_overflows)
    {
        overflow_counter++;
				
        while ((Gpt_GetOverflowFlag(GPT_CHANNEL_TIM2, &overflow_flag) == GPT_ERROR_STATE_OK) && (overflow_flag == 0))
		{
				ErrorState = GPT_ERROR_STATE_OK;
		} //Busy wait

		if (Gpt_ClearFlag(GPT_CHANNEL_TIM2, GPT_INT_SOURCE_TIM2_OVF) == GPT_ERROR_STATE_OK)
		{
			ErrorState = GPT_ERROR_STATE_OK;
		}
		
    }

    overflow_counter = 0;
	
	if (Gpt_Stop(GPT_CHANNEL_TIM2) == GPT_ERROR_STATE_OK)
	{
		ErrorState = GPT_ERROR_STATE_OK;
	}
	
	return ErrorState;
}
