#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define OUTPUT 0xFF
#define INPUT 0x00

typedef struct
{
    u8 Port;
    u8 Type;
    u8 PowerPin;
    u8 PowerPort;

} SSD_t;

#define SEVSEG_u8COMMON_CATHODE 0
#define SEVSEG_u8COMMON_ANODE 1

#define SEVSEG_HIGH 1

u8 SEVSEG_Init(SSD_t *copy_SSD);

u8 SEVSEG_DisplayNumber(SSD_t *copy_SSD, u8 copy_u8Number);

u8 SEVSEG_TurnOff(SSD_t *copy_SSD);

u8 SEVSEG_EnableDisplay(SSD_t *copy_SSD);

u8 SEVSEG_DisableDisplay(SSD_t *copy_SSD);

#endif