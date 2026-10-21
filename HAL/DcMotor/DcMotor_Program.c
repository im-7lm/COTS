#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DcMotor_Interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

u8 DCMOTOR_Init(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2)
{
    u8 local_u8Error1 = DIO_u8SetPinDirection(Copy_u8Port, Copy_u8Pin1, 1);
    u8 local_u8Error2 = DIO_u8SetPinDirection(Copy_u8Port, Copy_u8Pin2, 1);
    return local_u8Error1 || local_u8Error2;
}
u8 DCMOTOR_RotateDirection1(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2)
{
    u8 local_u8Error1 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin1, 1);
    u8 local_u8Error2 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin2, 0);
    return local_u8Error1 || local_u8Error2;
}
u8 DCMOTOR_RotateDirection2(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2)
{
    u8 local_u8Error1 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin1, 0);
    u8 local_u8Error2 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin2, 1);
    return local_u8Error1 || local_u8Error2;
}
u8 DCMOTOR_Stop(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2)
{
    u8 local_u8Error1 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin1, 0);
    u8 local_u8Error2 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin2, 0);
    return local_u8Error1 || local_u8Error2;
}