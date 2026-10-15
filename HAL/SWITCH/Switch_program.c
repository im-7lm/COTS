#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Switch_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

u8 SWITCH_Init(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8ConnectionType)
{
    u8 Local_u8ErrorState = 0;

    if ((copy_u8ConnectionType != SWITCH_CONNECTION_PULLUP) &&
        (copy_u8ConnectionType != SWITCH_CONNECTION_PULLDOWN))
    {
        return 1;
    }

    Local_u8ErrorState = DIO_u8SetPinDirection(
        copy_u8Port, copy_u8Pin, DIO_u8PIN_INPUT);

    if (Local_u8ErrorState != 0)
    {
        return Local_u8ErrorState;
    }

    if (copy_u8ConnectionType == SWITCH_CONNECTION_PULLUP)
    {
        Local_u8ErrorState = DIO_u8SetPinValue(
            copy_u8Port, copy_u8Pin, DIO_u8PIN_HIGH);
    }
    else
    {
        Local_u8ErrorState = DIO_u8SetPinValue(
            copy_u8Port, copy_u8Pin, DIO_u8PIN_LOW);
    }

    return Local_u8ErrorState;
}

u8 SWITCH_GetState(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8ConnectionType, u8 *copy_pu8State)
{
    u8 Local_u8ErrorState = 0;
    u8 Local_u8State;

    if (copy_pu8State == NULL)
    {
        return 1;
    }

    if ((copy_u8ConnectionType != SWITCH_CONNECTION_PULLUP) &&
        (copy_u8ConnectionType != SWITCH_CONNECTION_PULLDOWN))
    {
        return 1;
    }

    Local_u8ErrorState = DIO_u8GetPinValue(
        copy_u8Port, copy_u8Pin, &Local_u8State);

    if (Local_u8ErrorState != 0)
    {
        return Local_u8ErrorState;
    }

    if (copy_u8ConnectionType == SWITCH_CONNECTION_PULLUP)
    {
        *copy_pu8State = (Local_u8State == DIO_u8PIN_LOW)
                             ? PRESSED
                             : RELEASED;
    }
    else
    {
        *copy_pu8State = (Local_u8State == DIO_u8PIN_HIGH)
                             ? PRESSED
                             : RELEASED;
    }

    return 0;
}