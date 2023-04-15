#include "../../Utilities/Types.h"
#include "../../MCAL (Microcontroller Abstraction Layer)/DIO/Dio.h"
#include "../../Utilities/Macros.h"
#include "Led.h"


Led_ErrorType Led_Init(Dio_PortType port, Dio_PinType pin) {
    Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
    Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;

    ErrorState_dio =  Dio_SetPinMode(port, pin, DIO_MODE_OUTPUT);
    if (ErrorState_dio == DIO_ERROR_STATE_OK)
    {
        ErrorState_led = LED_ERROR_STATE_OK;
    }

    return ErrorState_led;
}

Led_ErrorType Led_TurnOn(Dio_PortType port, Dio_PinType pin) {
    Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
    Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG; 

    ErrorState_dio = Dio_SetPinLevel(port, pin, DIO_LEVEL_HIGH);

    if (ErrorState_dio == DIO_ERROR_STATE_OK)
    {
        ErrorState_led = LED_ERROR_STATE_OK;
    }

    return ErrorState_led;
}

Led_ErrorType Led_TurnOff(Dio_PortType port, Dio_PinType pin) {
    Led_ErrorType ErrorState_led = LED_ERROR_STATE_WRONG;
    Dio_ErrorType ErrorState_dio = DIO_ERROR_STATE_WRONG;

    ErrorState_dio = Dio_SetPinLevel(port, pin, DIO_LEVEL_LOW);

    if (ErrorState_dio == DIO_ERROR_STATE_OK)
    {
        ErrorState_led = LED_ERROR_STATE_OK;
    }

    return ErrorState_led;
}