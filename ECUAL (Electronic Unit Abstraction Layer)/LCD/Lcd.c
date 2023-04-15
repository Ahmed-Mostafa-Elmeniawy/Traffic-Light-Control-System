/*
 * Lcd.c
 *
 *  Created on: Feb 3, 2023
 *      Author: ahmad
 */

#include "Types.h"
#include "Dio.h"
#include "Macros.h"
#include "Delay.h"
#include "Lcd_config.h"
#include "Lcd.h"


static void Lcd_SendCommand(u8 command);
static void Lcd_SendData(u8 data);


void Lcd_Init(void)
{
	Dio_SetPinMode(LCD_PIN_RS, DIO_MODE_OUTPUT);
	Dio_SetPinMode(LCD_PIN_RW, DIO_MODE_OUTPUT);
	Dio_SetPinMode(LCD_PIN_EN, DIO_MODE_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D0, DIO_MODE_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D1, DIO_MODE_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D2, DIO_MODE_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D3, DIO_MODE_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D4, DIO_MODE_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D5, DIO_MODE_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D6, DIO_MODE_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D7, DIO_MODE_OUTPUT);


	/* Function Set 
	*	N: 1 for two lines, F: 1 for font 5x7
	*/
	Lcd_SendCommand( (u8) 0b00111100);


	/* Display ON/OFF Control 
	*	D: 1 for display is ON, B: 1 the cursor blink is ON, C: 1 for cursor is ON
	*/
	Lcd_SendCommand( (u8) 0b00001111);


	/* Clear Display */
	Lcd_SendCommand( (u8) 0b00000001);
}

static void Lcd_SendCommand(u8 command)
{
	Dio_SetPinLevel(LCD_PIN_RS, DIO_LEVEL_LOW);
	Dio_SetPinLevel(LCD_PIN_RW, DIO_LEVEL_LOW);
	
	Dio_SetPinLevel(LCD_PIN_D0, GET_BIT(command, 0) );
	Dio_SetPinLevel(LCD_PIN_D1, GET_BIT(command, 1) );
	Dio_SetPinLevel(LCD_PIN_D2, GET_BIT(command, 2) );
	Dio_SetPinLevel(LCD_PIN_D3, GET_BIT(command, 3) );
	Dio_SetPinLevel(LCD_PIN_D4, GET_BIT(command, 4) );
	Dio_SetPinLevel(LCD_PIN_D5, GET_BIT(command, 5) );
	Dio_SetPinLevel(LCD_PIN_D6, GET_BIT(command, 6) );
	Dio_SetPinLevel(LCD_PIN_D7, GET_BIT(command, 7) );

	Dio_SetPinLevel(LCD_PIN_EN, DIO_LEVEL_HIGH);
	_delay_ms(2);
	Dio_SetPinLevel(LCD_PIN_EN, DIO_LEVEL_LOW);
}


static void Lcd_SendData(u8 data)
{
	Dio_SetPinLevel(LCD_PIN_RS, DIO_LEVEL_HIGH);
	Dio_SetPinLevel(LCD_PIN_RW, DIO_LEVEL_LOW);

	Dio_SetPinLevel(LCD_PIN_D0, GET_BIT(data, 0));
	Dio_SetPinLevel(LCD_PIN_D1, GET_BIT(data, 1));
	Dio_SetPinLevel(LCD_PIN_D2, GET_BIT(data, 2));
	Dio_SetPinLevel(LCD_PIN_D3, GET_BIT(data, 3));
	Dio_SetPinLevel(LCD_PIN_D4, GET_BIT(data, 4));
	Dio_SetPinLevel(LCD_PIN_D5, GET_BIT(data, 5));
	Dio_SetPinLevel(LCD_PIN_D6, GET_BIT(data, 6));
	Dio_SetPinLevel(LCD_PIN_D7, GET_BIT(data, 7));

	Dio_SetPinLevel(LCD_PIN_EN, DIO_LEVEL_HIGH);
	_delay_ms(2);
	Dio_SetPinLevel(LCD_PIN_EN, DIO_LEVEL_LOW);
}


void Lcd_DisplayCharcter(char data)
{
	Lcd_SendData(data);
}


void Lcd_DisplayString(const char* str)
{
	u8 index = 0;

	/* Loop to send the string characters one by one */
	while (str[index] != '\0')
	{
		Lcd_DisplayCharcter(str[index]);
		index++;
	}
}


void Lcd_DisplayNumber(s64 number)
{
	s64 reversed = 0;
	/* Used to determine the position of zeros */
	u8 count[10] = { 0 };
	u8 index = 0;

	while (number < 0)
	{
		number *= -1;
	}

	while (number != 0)
	{
		/* Finding the zeros' positions */
		if ((number % 10) == 0)
		{
			count[index] = 1;
			index++;
			number /= 10;
			continue;
		}

		/* Reversing the number */
		reversed = (reversed * 10) + (number % 10);
		number /= 10;
		index++;
	}

	/* Decreasing index by one to fit the index of each element in the array */
	index--;

	while (reversed >= 0)
	{
		if (count[index] == 1)			/* Printing zeros in their positions */
		{
			Lcd_DisplayCharcter(0 + 48);
			index--;
		}
		else if (reversed == 0)
		{
			break;
		}
		else							/* Printing numbers in their positions */
		{
			Lcd_DisplayCharcter((reversed % 10) + 48);
			reversed /= 10;
			index--;
		}

	}
}



void Lcd_ClearDisplay(void)
{
	Lcd_SendCommand(0x00000001);
}


void Lcd_SetCursorPosition(u8 row, u8 column)
{
	/* Using Set DDRAM Instruction */
	u8 position = 0;

	/* Setting the last bit to the value of 1 */
	SET_BIT(position, 7);

	/* Calulating the position */
	position = (row * 0x40) + column;

	/* Setting the required position */
	Lcd_SendCommand(position);
	Lcd_ReturnHome();
	Lcd_ShiftCursorRight(1);
}

void Lcd_ShiftCursorLeft(u8 count)
{
	/* S/C = 1 refers to the cursor
	*	R/L = 0 refers to shift left
	*/
	u8 index;

	for (index = 0; index < count; index++)
	{
		Lcd_SendCommand( (u8) 0b00010000);
	}
}


void Lcd_ShiftCursorRight(u8 count)
{
	/* S/C = 1 refers to the cursor
	*	R/L = 1 refers to shift right
	*/
	u8 index;

	for (index = 0; index < count; index++)
	{
		Lcd_SendCommand( (u8) 0b00010100);
	}
}


void Lcd_ShiftDisplayLeft(u8 count)
{
	/* S/C = 1 refers to the display
	*	R/L = 0 refers to shift left
	*/
	u8 index;

	for (index = 0; index < count; index++)
	{
		Lcd_SendCommand( (u8) 0b00011000);
	}
}


void Lcd_ShiftDisplayRight(u8 count)
{
	/* S/C = 1 refers to the display
	*	R/L = 1 refers to shift right
	*/
	u8 index;

	for (index = 0; index < count; index++)
	{
		Lcd_SendCommand( (u8) 0b00011100);
	}
}


void Lcd_ReturnHome(void)
{
	Lcd_SendCommand(0x00000010);
}


void Lcd_ControlDisplay(const Lcd_DisplayControlType* control)
{
	u8 Display_Cursor_CursorBlink_Control	= 0b00000000;
	u8 Line_Font_Control					= 0b00000000;

	/* Display ON/OFF Control Instruction */
	SET_BIT(Display_Cursor_CursorBlink_Control, 3);

	/* Function Set Instruction */
	SET_BIT(Line_Font_Control, 5);
	/* Working in 8-bit mode */
	SET_BIT(Line_Font_Control, 4);

	switch (control->display)
	{
	case LCD_STATE_ON:
		SET_BIT(Display_Cursor_CursorBlink_Control, 2);

		/* Check the cursor */
		switch (control->cursor)
		{
		case LCD_STATE_ON:
			SET_BIT(Display_Cursor_CursorBlink_Control, 1);

			/* Check the cursor blinking */
			switch (control->cursorBlink)
			{
			case LCD_STATE_ON:
				SET_BIT(Display_Cursor_CursorBlink_Control, 0);
				break;
			default:
				/* Do Nothing */
				break;
			} 

			break;
		default:
			/* Do Nothing */
			break;
		}

		break;
	default:
		/* Do Nothing */
		break;
	}

	Lcd_SendCommand(Display_Cursor_CursorBlink_Control);


	switch (control->lines)
	{
	case LCD_LINES_2:
		SET_BIT(Line_Font_Control, 3);
		break;
	default:
		/* Do Nothing */
		break;
	}


	switch (control->font)
	{
	case LCD_FONT_5X11:
		SET_BIT(Line_Font_Control, 2);
		break;
	default:
		/* Do Nothing */
		break;
	}

	Lcd_SendCommand(Line_Font_Control);
}
