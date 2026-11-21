#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "MCAL/DIO/DIO_interface.h"

u8 LED_u8Init(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 Local_u8StateError = 0;

    Local_u8StateError = DIO_u8SetPinDirection(
        Copy_u8Port,
        Copy_u8Pin,
        DIO_u8PIN_OUTPUT);

    return Local_u8StateError;
}

u8 LED_u8TurnOn(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ConnectionType)
{
    u8 Local_u8StateError = 0;

    if (Copy_u8ConnectionType != LED_u8SOURCE &&
        Copy_u8ConnectionType != LED_u8SINK)
    {
        return 1;
    }

    Local_u8StateError = DIO_u8SetPinValue(
        Copy_u8Port,
        Copy_u8Pin,
        Copy_u8ConnectionType == LED_u8SOURCE ? DIO_u8PIN_HIGH : DIO_u8PIN_LOW);

    return Local_u8StateError;
}

u8 LED_u8TurnOff(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ConnectionType)
{
    u8 Local_u8StateError = 0;

    if (Copy_u8ConnectionType != LED_u8SOURCE &&
        Copy_u8ConnectionType != LED_u8SINK)
    {
        return 1;
    }

    Local_u8StateError = DIO_u8SetPinValue(
        Copy_u8Port,
        Copy_u8Pin,
        Copy_u8ConnectionType == LED_u8SOURCE ? DIO_u8PIN_LOW : DIO_u8PIN_HIGH);

    return Local_u8StateError;
}

u8 LED_u8Toggle(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 Local_u8StateError = 0;
    u8 Local_u8PinValue = 0;

    Local_u8StateError = DIO_u8GetPinValue(
        Copy_u8Port,
        Copy_u8Pin,
        &Local_u8PinValue);

    if (Local_u8StateError == 0)
    {
        Local_u8PinValue = !Local_u8PinValue;

        Local_u8StateError = DIO_u8SetPinValue(
            Copy_u8Port,
            Copy_u8Pin,
            Local_u8PinValue);
    }

    return Local_u8StateError;
}