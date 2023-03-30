#include"Types.h"
#include"Dio.h"
#include"SSD_config.h"
#include"SSD.h"

void Ssd_init(void)
{
	Dio_SetPinMode(SSD_PORT, SSD_PINA, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT, SSD_PINB, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT, SSD_PINC, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT, SSD_PIND, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT, SSD_PINE, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT, SSD_PINF, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT, SSD_PING, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT, SSD_DOT,  DIO_MODE_OUTPUT);
}

void Ssd_DisplayNumber(u8 number)
{
	switch (number)
	{
		case 0:
			Dio_SetPinLevel(SSD_PORT, SSD_PINA, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINB, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINC, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PIND, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINE, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINF, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PING, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_DOT,  SSD_OFF);
			break;
		case 1:
			Dio_SetPinLevel(SSD_PORT, SSD_PINA, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINB, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINC, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PIND, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINE, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINF, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PING, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_DOT,  SSD_OFF);
			break;
		case 2:
			Dio_SetPinLevel(SSD_PORT, SSD_PINA, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINB, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINC, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PIND, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINE, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINF, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PING, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_DOT,  SSD_OFF);
			break; 
		case 3:
			Dio_SetPinLevel(SSD_PORT, SSD_PINA, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINB, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINC, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PIND, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINE, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINF, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PING, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_DOT,  SSD_OFF);
			break;
		case 4:
			Dio_SetPinLevel(SSD_PORT, SSD_PINA, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINB, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINC, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PIND, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINE, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINF, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PING, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_DOT,  SSD_OFF);
			break;
		case 5:
			Dio_SetPinLevel(SSD_PORT, SSD_PINA, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINB, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINC, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PIND, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINE, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINF, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PING, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_DOT,  SSD_OFF);
			break;
		case 6:
			Dio_SetPinLevel(SSD_PORT, SSD_PINA, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINB, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINC, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PIND, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINE, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINF, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PING, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_DOT,  SSD_OFF);
			break;
		case 7:
			Dio_SetPinLevel(SSD_PORT, SSD_PINA, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINB, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINC, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PIND, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINE, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINF, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PING, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_DOT,  SSD_OFF);
			break;
		case 8:
			Dio_SetPinLevel(SSD_PORT, SSD_PINA, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINB, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINC, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PIND, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINE, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINF, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PING, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_DOT,  SSD_OFF);
			break;
		case 9:
			Dio_SetPinLevel(SSD_PORT, SSD_PINA, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINB, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINC, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PIND, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PINE, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINF, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_PING, SSD_ON);
			Dio_SetPinLevel(SSD_PORT, SSD_DOT,  SSD_OFF);
			break;
	default:
			Dio_SetPinLevel(SSD_PORT, SSD_PINA, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINB, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINC, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PIND, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINE, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PINF, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_PING, SSD_OFF);
			Dio_SetPinLevel(SSD_PORT, SSD_DOT,  SSD_OFF);
		break;
	}
}

/****************************************************** For a second ssd ******************************************************/
void Ssd_init2(void)
{
	Dio_SetPinMode(SSD_PORT2, SSD_PINA, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT2, SSD_PINB, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT2, SSD_PINC, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT2, SSD_PIND, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT2, SSD_PINE, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT2, SSD_PINF, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT2, SSD_PING, DIO_MODE_OUTPUT);
	Dio_SetPinMode(SSD_PORT2, SSD_DOT, DIO_MODE_OUTPUT);
}

void Ssd_DisplayNumber2(u8 number)
{
	switch (number)
	{
	case 0:
		Dio_SetPinLevel(SSD_PORT2, SSD_PINA, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINB, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINC, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PIND, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINE, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINF, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PING, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_DOT, SSD_OFF);
		break;
	case 1:
		Dio_SetPinLevel(SSD_PORT2, SSD_PINA, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINB, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINC, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PIND, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINE, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINF, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PING, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_DOT, SSD_OFF);
		break;
	case 2:
		Dio_SetPinLevel(SSD_PORT2, SSD_PINA, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINB, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINC, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PIND, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINE, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINF, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PING, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_DOT, SSD_OFF);
		break;
	case 3:
		Dio_SetPinLevel(SSD_PORT2, SSD_PINA, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINB, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINC, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PIND, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINE, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINF, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PING, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_DOT, SSD_OFF);
		break;
	case 4:
		Dio_SetPinLevel(SSD_PORT2, SSD_PINA, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINB, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINC, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PIND, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINE, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINF, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PING, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_DOT, SSD_OFF);
		break;
	case 5:
		Dio_SetPinLevel(SSD_PORT2, SSD_PINA, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINB, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINC, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PIND, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINE, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINF, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PING, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_DOT, SSD_OFF);
		break;
	case 6:
		Dio_SetPinLevel(SSD_PORT2, SSD_PINA, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINB, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINC, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PIND, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINE, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINF, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PING, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_DOT, SSD_OFF);
		break;
	case 7:
		Dio_SetPinLevel(SSD_PORT2, SSD_PINA, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINB, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINC, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PIND, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINE, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINF, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PING, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_DOT, SSD_OFF);
		break;
	case 8:
		Dio_SetPinLevel(SSD_PORT2, SSD_PINA, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINB, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINC, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PIND, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINE, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINF, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PING, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_DOT, SSD_OFF);
		break;
	case 9:
		Dio_SetPinLevel(SSD_PORT2, SSD_PINA, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINB, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINC, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PIND, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINE, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINF, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_PING, SSD_ON);
		Dio_SetPinLevel(SSD_PORT2, SSD_DOT, SSD_OFF);
		break;
	default:
		Dio_SetPinLevel(SSD_PORT2, SSD_PINA, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINB, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINC, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PIND, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINE, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PINF, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_PING, SSD_OFF);
		Dio_SetPinLevel(SSD_PORT2, SSD_DOT, SSD_OFF);
		break;
	}
}
