#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidSendCommand(u8 Copy_u8Command); // Send Command

void LCD_voidSendData(u8 Copy_u8Data); // Send Data to display it in the screen

void LCD_voidSendString(u8 Copy_u8String[]);

void LCD_voidInit(void); // init the LCD

void LCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8Ypos);

void LCD_voidWriteCustomCharacter(u8 *Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_XPo, u8 Copy_YPo);

#endif