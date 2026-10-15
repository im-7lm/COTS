#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SSD_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

static const u8 Numbers[10] = {
    // Cathode Values
    0b0111111,
    0b0000110,
    0b1011011,
    0b1001111,
    0b1100110,
    0b1101101,
    0b1111101,
    0b0000111,
    0b1111111,
    0b1101111,
};

u8 SEVSEG_Init(u8 copy_Port)
{
    u8 LocalStateError = DIO_u8SetPortDirection(copy_Port, OUTPUT);

    return LocalStateError;
}

u8 SEVSEG_DisplayNumber(u8 copy_Port, u8 copy_u8Number, u8 copy_u8Type, u8 copy_u8PowerPin, u8 copy_u8PowerPort)
{
    u8 LocalStateError = 0;

    if (copy_u8Number > 9)
    {
        LocalStateError = 1;
    }

    DIO_u8SetPinDirection(copy_u8PowerPort, copy_u8PowerPin, DIO_u8PIN_OUTPUT);
    DIO_u8SetPinValue(copy_u8PowerPort, copy_u8PowerPin, copy_u8Type ? 1 : 0);
    DIO_u8SetPortValue(copy_Port, copy_u8Type ? ~Numbers[copy_u8Number] : Numbers[copy_u8Number]);

    return LocalStateError;
}

u8 SEVSEG_TurnOff(u8 copy_Port, u8 copy_u8Type)
{
    u8 LocalStateError = 0;

    if (copy_u8Type != SEVSEG_u8COMMON_ANODE &&
        copy_u8Type != SEVSEG_u8COMMON_CATHODE)
    {
        return 1;
    }

    LocalStateError = DIO_u8SetPortValue(
        copy_Port,
        copy_u8Type ? 0xFF : 0x00);

    return LocalStateError;
}

u8 SEVSEG_EnableDisplay(u8 copy_u8PowerPort, u8 copy_u8PowerPin, u8 copy_u8Type)
{
    u8 LocalStateError = 0;

    if (copy_u8Type != SEVSEG_u8COMMON_ANODE &&
        copy_u8Type != SEVSEG_u8COMMON_CATHODE)
    {
        return 1;
    }

    LocalStateError = DIO_u8SetPinDirection(
        copy_u8PowerPort,
        copy_u8PowerPin,
        DIO_u8PIN_OUTPUT);

    if (LocalStateError != 0)
    {
        return LocalStateError;
    }

    LocalStateError = DIO_u8SetPinValue(
        copy_u8PowerPort,
        copy_u8PowerPin,
        copy_u8Type ? DIO_u8PIN_HIGH : DIO_u8PIN_LOW);

    return LocalStateError;
}

u8 SEVSEG_DisableDisplay(u8 copy_u8PowerPort, u8 copy_u8PowerPin, u8 copy_u8Type)
{
    u8 LocalStateError = 0;

    if (copy_u8Type != SEVSEG_u8COMMON_ANODE &&
        copy_u8Type != SEVSEG_u8COMMON_CATHODE)
    {
        return 1;
    }

    LocalStateError = DIO_u8SetPinDirection(
        copy_u8PowerPort,
        copy_u8PowerPin,
        DIO_u8PIN_OUTPUT);

    if (LocalStateError != 0)
    {
        return LocalStateError;
    }

    LocalStateError = DIO_u8SetPinValue(
        copy_u8PowerPort,
        copy_u8PowerPin,
        copy_u8Type ? DIO_u8PIN_LOW : DIO_u8PIN_HIGH);

    return LocalStateError;
}
