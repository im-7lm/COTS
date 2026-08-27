#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR, BIT) (VAR |= (1 << BIT))
#define CLEAR_BIT(VAR, BIT) (VAR &= ~(1 << BIT))
#define TOGGLE_BIT(VAR, BIT) (VAR ^= (1 << BIT))
#define GET_BIT(VAR, BIT) ((VAR >> BIT) & 1)

#endif