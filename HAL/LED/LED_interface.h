#ifndef LED_H
#define LED_H

#include "STD_TYPES.h"

u8 LED_u8TurnOn(u8 Copy_u8Port, u8 Copy_u8Pin);

u8 LED_u8TurnOff(u8 Copy_u8Port, u8 Copy_u8Pin);

u8 LED_u8Toggle(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif