#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SSD_interface.h"
#include "MCAL/DIO/DIO_interface.h"

static const u8 Numbers[10] = {
    // Cathode Values
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
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

    DIO_u8SetPinValue(copy_u8PowerPort, copy_u8PowerPin, copy_u8Type ? 0 : 1);
    DIO_u8SetPortValue(copy_Port, copy_u8Type ? ~Numbers[copy_u8Number] : Numbers[copy_u8Number]);

    return LocalStateError;
}