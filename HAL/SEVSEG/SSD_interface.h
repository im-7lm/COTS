#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define OUTPUT 1
#define INPUT 0

#define SEVSEG_u8COMMON_CATHODE 0
#define SEVSEG_u8COMMON_ANODE 1

#define SEVSEG_HIGH 1

u8 SEVSEG_Init(u8 copy_u8Port);
u8 SEVSEG_DisplayNumber(u8 copy_Port, u8 copy_Number, u8 copy_Type, u8 copy_PowerPin, u8 copy_PowerPort);

#endif