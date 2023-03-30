


#include "app.h"


extern Gpt_ConfigType Gpt_Configuration[3];

volatile uint8_t overflow	= 0;
volatile uint8_t led_counter_car = 0;
volatile uint8_t button_status = 0;


void Handler_Int0(void)
{
	button_status = 1;
}


void Handler_Tim0_OVF(void)
{
	overflow++;
	if (overflow == 152)
	{
		overflow = 0;
		Gpt_Reset(GPT_CHANNEL_TIM0);

		switch (led_counter_car)
		{
			case 0:
			led_counter_car++;
			break;
			case 1:
			led_counter_car++;
			break;
			case 2:
			led_counter_car++;
			break;
			case 3:
			led_counter_car++;
			break;
			default:
			break;
		}
	}
	
}


void App_Start(void)
{
	Led_ErrorType		ErrorState_led		= LED_ERROR_STATE_WRONG;
	Gpt_ErrorType		ErrorState_gpt		= GPT_ERROR_STATE_WRONG;
	Extint_ErrorType	ErrorState_extint	= EXTINT_ERROR_STATE_WRONG;
	
	//Car lights
	ErrorState_led = Led_init();
	ErrorState_led = Led_init2();
	ErrorState_led = Led_init3();

	//Pedestrian lights
	ErrorState_led = Led_init4();
	ErrorState_led = Led_init5();
	ErrorState_led = Led_init6();

	ErrorState_gpt = Gpt_Init(GPT_CHANNEL_TIM0, &Gpt_Configuration[0] );
	ErrorState_gpt = Gpt_SetCallback(GPT_INT_SOURCE_TIM0_OVF, Handler_Tim0_OVF);

	ErrorState_extint = ExtInt_Init(EXTINT_CHANNEL_INT0);
	ErrorState_extint = ExInt_SetCallback(EXTINT_CHANNEL_INT0, Handler_Int0);
	ErrorState_extint = ExtInt_SetTriggerEdge(EXTINT_CHANNEL_INT0, EXTINT_TRIGGER_FALLING_EDGE);
	ErrorState_extint = ExtInt_EnableNotification(EXTINT_CHANNEL_INT0);

	ErrorState_gpt = Gpt_EnableNotification(GPT_INT_SOURCE_TIM0_OVF);
	ErrorState_gpt = Gpt_Start(GPT_CHANNEL_TIM0, GPT_PRESCALER_1024);

	ErrorState_led = Led_TurnOn();
	ErrorState_led = Led_TurnOn6();

	ErrorState_led = Led_TurnOff2();
	ErrorState_led = Led_TurnOff3();
	ErrorState_led = Led_TurnOff5();
	ErrorState_led = Led_TurnOff4();

	Gie_Enable();

	while (1)
	{
		if (button_status == 0)
		{

			if (led_counter_car == 1)
			{
				ErrorState_led = Led_TurnOn();		//Car red light is ON
				ErrorState_led = Led_TurnOn6(); 		//Pedestrian green light is ON

				//Yellow light blinks while car red light is ON and pedestrian green light is ON
				ErrorState_led = Led_TurnOn2();
				ErrorState_led = Led_TurnOn5();

				ErrorState_gpt = Gpt_Delay(350);

				ErrorState_led = Led_TurnOff5();
				ErrorState_led = Led_TurnOff2();

				ErrorState_gpt = Gpt_Delay(300);

				ErrorState_led = Led_TurnOn2();
				ErrorState_led = Led_TurnOn5();

				ErrorState_gpt = Gpt_Delay(350);
			}
			else if (led_counter_car == 2)
			{
				ErrorState_led = Led_TurnOff();		//Car red light is OFF
				ErrorState_led = Led_TurnOff6();		//Pedestrian green light is OFF

				ErrorState_led = Led_TurnOff2();		//Car yellow light is OFF
				ErrorState_led = Led_TurnOff5();		//Pedestrian yellow light is OFF

				ErrorState_led = Led_TurnOn3();		//Car green light is ON
				ErrorState_led = Led_TurnOn4();		//Pedestrian red light is ON
			}
			else if (led_counter_car == 3)
			{
				ErrorState_led = Led_TurnOn3();		//Car green light is ON
				ErrorState_led = Led_TurnOn4();		//Pedestrian red light is ON

				//Yellow light blinks while car green light is ON and pedestrian red light is ON
				ErrorState_led = Led_TurnOn2();
				ErrorState_led = Led_TurnOn5();

				ErrorState_gpt = Gpt_Delay(350);

				ErrorState_led = Led_TurnOff5();
				ErrorState_led = Led_TurnOff2();

				ErrorState_gpt = Gpt_Delay(300);

				ErrorState_led = Led_TurnOn2();
				ErrorState_led = Led_TurnOn5();

				ErrorState_gpt = Gpt_Delay(350);

			}
			else if (led_counter_car == 4)
			{
				ErrorState_led = Led_TurnOff3();		//Car green light is OFF
				ErrorState_led = Led_TurnOff4();		//Pedestrian red light is OFF

				ErrorState_led = Led_TurnOff2();		//Car yellow light is OFF
				ErrorState_led = Led_TurnOff5();		//Pedestrian yellow light is OFF

				ErrorState_led = Led_TurnOn();		//Car red light is ON
				ErrorState_led = Led_TurnOn6();		//Pedestrian green light is ON

				led_counter_car = 0;
			}

		}
		else if ((button_status == 1) && (led_counter_car == 1))
		{
			button_status = 0;
			// The pedstrian green light is already ON
		}
		else if ((button_status == 1) && (led_counter_car == 2))
		{
			button_status = 0;
			led_counter_car = 3;
		}
		else if ((button_status == 1) && (led_counter_car == 3))
		{
			button_status = 0;
			// The yellow lights blinks and the next step is to activate the pedestrian green light
		}
		else if ((button_status == 1) && (led_counter_car == 4))
		{
			button_status = 0;
			// Do nothing
		}


	}
	
}