
#include "Application/app.h"




int main(void)
{
	
	App_Start();
	
		/************************Testing the DIO driver*************************/
		/************************Run the code only when you delete App_Start() function*************************/
		#if 0
		Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;
		Dio_LevelType* level = NULL_PTR;


		ErrorState_dio = Dio_SetPinMode(LED_PIN1_CAR, DIO_MODE_OUTPUT);
		if (ErrorState_dio == DIO_ERROR_STATE_OK)
		{
			ErrorState_dio = Dio_SetPinMode(DIO_PORTA, DIO_PIN2, DIO_MODE_INPUT_PULLUP);
			if (ErrorState_dio == DIO_ERROR_STATE_OK)
			{
				ErrorState_dio = Dio_SetPinLevel(LED_PIN1_CAR, DIO_LEVEL_HIGH);
			}
		}
		

		
		while (1)
		{
			ErrorState_dio = Dio_ReadPin(DIO_PORTA, DIO_PIN2, &level);
			if ((level == DIO_LEVEL_LOW) && (ErrorState_dio == DIO_ERROR_STATE_OK))
			{
				ErrorState_dio = Dio_FlipPin(LED_PIN1_CAR, &level);
				if ((level == DIO_LEVEL_LOW) && (ErrorState_dio == DIO_ERROR_STATE_OK))
				{
					ErrorState_dio = Dio_FlipPin(LED_PIN1_CAR, &level);
					
				}
			}
		}



		#endif
	
}