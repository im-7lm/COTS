#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define LED_u8SOURCE 0
#define LED_u8SINK 1

u8 LED_u8Init(u8 Copy_u8Port, u8 Copy_u8Pin);

u8 LED_u8TurnOn(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ConnectionType);

u8 LED_u8TurnOff(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ConnectionType);

u8 LED_u8Toggle(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif