#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(R, index) (R |= (1 << (index)))
#define CLR_BIT(R, index) (R &= ~(1 << (index)))
#define TOG_BIT(R, index) (R ^= (1 << (index)))
#define GET_BIT(R, index) ((R >> (index)) & 1)

#endif