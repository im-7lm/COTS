#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "IR_interface.h"

u8 IR_Init(u8 copy_u8Port, u8 copy_u8Pin)
{
    return DIO_u8SetPinDirection(
        copy_u8Port,
        copy_u8Pin,
        DIO_u8PIN_INPUT);
}

u8 IR_GetState(u8 copy_u8Port, u8 copy_u8Pin, u8 *copy_pu8State)
{
    u8 Local_u8ErrorState = 0;
    u8 Local_u8PinValue;

    if (copy_pu8State == NULL)
    {
        return 1;
    }

    Local_u8ErrorState = DIO_u8GetPinValue(
        copy_u8Port,
        copy_u8Pin,
        &Local_u8PinValue);

    if (Local_u8ErrorState != 0)
    {
        return Local_u8ErrorState;
    }

    if (Local_u8PinValue == DIO_u8PIN_LOW)
    {
        *copy_pu8State = IR_DETECTED;
    }
    else
    {
        *copy_pu8State = IR_NOT_DETECTED;
    }

    return 0;
}