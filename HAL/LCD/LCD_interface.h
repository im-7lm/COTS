#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidSendCommand(u8 Copy_u8Command); // Send Command

void LCD_voidSendData(u8 Copy_u8Data); // Send Data to display it in the screen

void LCD_voidSendString(u8 Copy_u8String[]);

void LCD_voidInit(void); // init the LCD

#endif