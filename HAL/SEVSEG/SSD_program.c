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

u8 SEVSEG_Init(SSD_t *copy_SSD)
{
    u8 LocalStateError = DIO_u8SetPortDirection(copy_SSD->Port, OUTPUT);

    return LocalStateError;
}

u8 SEVSEG_DisplayNumber(SSD_t *copy_SSD, u8 copy_u8Number)
{
    u8 LocalStateError = 0;

    if (copy_u8Number > 9)
    {
        LocalStateError = 1;
    }

    DIO_u8SetPinDirection(copy_SSD->PowerPort, copy_SSD->PowerPin, DIO_u8PIN_OUTPUT);
    DIO_u8SetPinValue(copy_SSD->PowerPort, copy_SSD->PowerPin, copy_SSD->Type ? 1 : 0);
    DIO_u8SetPortValue(copy_SSD->Port, copy_SSD->Type ? ~Numbers[copy_u8Number] : Numbers[copy_u8Number]);

    return LocalStateError;
}

u8 SEVSEG_TurnOff(SSD_t *copy_SSD)
{
    u8 LocalStateError = 0;

    if (copy_SSD->Type != SEVSEG_u8COMMON_ANODE &&
        copy_SSD->Type != SEVSEG_u8COMMON_CATHODE)
    {
        return 1;
    }

    LocalStateError = DIO_u8SetPortValue(
        copy_SSD->Port,
        copy_SSD->Type ? 0xFF : 0x00);

    return LocalStateError;
}

u8 SEVSEG_EnableDisplay(SSD_t *copy_SSD)
{
    u8 LocalStateError = 0;

    if (copy_SSD->Type != SEVSEG_u8COMMON_ANODE &&
        copy_SSD->Type != SEVSEG_u8COMMON_CATHODE)
    {
        return 1;
    }

    LocalStateError = DIO_u8SetPinDirection(
        copy_SSD->PowerPort,
        copy_SSD->PowerPin,
        DIO_u8PIN_OUTPUT);

    if (LocalStateError != 0)
    {
        return LocalStateError;
    }

    LocalStateError = DIO_u8SetPinValue(
        copy_SSD->PowerPort,
        copy_SSD->PowerPin,
        copy_SSD->Type ? DIO_u8PIN_HIGH : DIO_u8PIN_LOW);

    return LocalStateError;
}

u8 SEVSEG_DisableDisplay(SSD_t *copy_SSD)
{
    u8 LocalStateError = 0;

    if (copy_SSD->Port != SEVSEG_u8COMMON_ANODE &&
        copy_SSD->Type != SEVSEG_u8COMMON_CATHODE)
    {
        return 1;
    }

    LocalStateError = DIO_u8SetPinDirection(
        copy_SSD->PowerPort,
        copy_SSD->PowerPin,
        DIO_u8PIN_OUTPUT);

    if (LocalStateError != 0)
    {
        return LocalStateError;
    }

    LocalStateError = DIO_u8SetPinValue(
        copy_SSD->PowerPort,
        copy_SSD->PowerPin,
        copy_SSD->Type ? DIO_u8PIN_LOW : DIO_u8PIN_HIGH);

    return LocalStateError;
}
