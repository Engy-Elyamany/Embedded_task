#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "GPIO_driver.h"

typedef struct
{
    GPIO_PinConfig IN1;
    GPIO_PinConfig IN2;
    GPIO_PinConfig EN;
} L298_Config;

void L298_Init(L298_Config *config);

void L298_Forward( L298_Config *config);

void L298_Backward( L298_Config *config);

void L298_Stop( L298_Config *config);

#endif