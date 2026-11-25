#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

void LCD_voidSendCommand(u8 Copy_u8Command)
{
    // Set RS pin to LOW for Command
    DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_LOW);

    // Set RW to LOW for Write
    DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);

    // Set Command to Data Pins
    DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Command);

    // Send Enable Pulse
    DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
    // Set RS pin to LOW for Data
    DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_HIGH);

    // Set RW to LOW for Write
    DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);

    // Set Command to Data Pins
    DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Data);

    // Send Enable Pulse
    DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_LOW);
}

void LCD_voidSendString(u8 *Copy_u8String)
{
    u8 i = 0;

    while (Copy_u8String[i] != '\0')
    {
        LCD_voidSendData(Copy_u8String[i]);
        i++;
    }
}

void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8Ypos)
{
    u8 Local_u8Address;

    if (Copy_u8XPos == 0)
    {
        Local_u8Address = Copy_u8Ypos;
    }
    else if (Copy_u8XPos == 1)
    {
        Local_u8Address = Copy_u8Ypos + 0x40;
    }

    LCD_voidSendCommand(Local_u8Address + 128);
}

void LCD_voidWriteCustomCharacter(u8 *Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_XPo, u8 Copy_YPo)
{
    u8 Local_u8CGRAMAddress = 0, Local_u8Iterator;

    // Calc the CGRAM Address
    Local_u8CGRAMAddress = Copy_u8PatternNumber * 8; // 8 is each Block size in the CGRAM Memory

    LCD_voidSendCommand(Local_u8CGRAMAddress + 64); // Send CGRAM address command to LCD with bit 6, clearing bit 7

    // write the pattern into CGRAM
    for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
    {
        LCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
    }

    // go back to the DDRAM to display the pattern
    LCD_voidGoToXY(Copy_XPo, Copy_YPo);

    // diaplay the pattern in the CGRAM
    LCD_voidSendData(Copy_u8PatternNumber);
}

void LCD_voidInit(void)
{
    DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_u8PORT_OUTPUT);

    DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, DIO_u8PIN_OUTPUT);
    DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, DIO_u8PIN_OUTPUT);
    DIO_u8SetPinDirection(LCD_CTRL_PORT, LCD_E_PIN, DIO_u8PIN_OUTPUT);
    // wait for more than 30ms
    _delay_ms(40);

    // Function set command: 2 lines, 5*8 Font size
    LCD_voidSendCommand(0b00111000);

    // Display on off control: Display engable, disable cursor, no blink cursor
    LCD_voidSendCommand(0b00001100);

    // Clear Display
    LCD_voidSendCommand(1); // 0b00000001

    // End of initializing
}