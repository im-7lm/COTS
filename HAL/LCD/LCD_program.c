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