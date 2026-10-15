#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define OUTPUT 0xFF
#define INPUT 0x00

#define SEVSEG_u8COMMON_CATHODE 0
#define SEVSEG_u8COMMON_ANODE 1

#define SEVSEG_HIGH 1

u8 SEVSEG_Init(u8 copy_u8Port);
u8 SEVSEG_TurnOff(u8 copy_Port, u8 copy_u8Type);

u8 SEVSEG_DisplayNumber(u8 copy_Port, u8 copy_u8Number, u8 copy_u8Type, u8 copy_u8PowerPin, u8 copy_u8PowerPort);

u8 SEVSEG_EnableDisplay(u8 copy_u8PowerPort, u8 copy_u8PowerPin, u8 copy_u8Type);

u8 SEVSEG_DisableDisplay(u8 copy_u8PowerPort, u8 copy_u8PowerPin, u8 copy_u8Type);

#endif