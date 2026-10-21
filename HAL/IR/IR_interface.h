#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

#define IR_DETECTED 1
#define IR_NOT_DETECTED 0

u8 IR_Init(u8 copy_u8Port, u8 copy_u8Pin);

u8 IR_GetState(u8 copy_u8Port, u8 copy_u8Pin, u8 *copy_pu8State);

#endif