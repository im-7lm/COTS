#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#define PRESSED 1
#define RELEASED 0

#define SWITCH_CONNECTION_PULLUP 0
#define SWITCH_CONNECTION_PULLDOWN 1

#include "../../LIB/STD_TYPES.h"

/**
 * @brief Initializes the switch pin.
 * @param copy_u8Port The port connected to the switch.
 * @param copy_u8Pin The pin connected to the switch.
 * @param copy_u8ConnectionType PULLUP uses the internal resistor;
 * PULLDOWN requires an external resistor.
 */
u8 SWITCH_Init(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8ConnectionType);

u8 SWITCH_GetState(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8ConnectionType, u8 *copy_pu8State);

#endif