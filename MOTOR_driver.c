#include "MOTOR_driver.h"

void L298_Init(L298_Config *config)
{
    GPIO_PinInit(&config->IN1);
    GPIO_PinInit(&config->IN2);
    GPIO_PinInit(&config->EN);
}

void L298_Forward(L298_Config *config)
{
    GPIO_WritePin(&config->IN1, GPIO_HIGH);
    GPIO_WritePin(&config->IN2, GPIO_LOW);
    GPIO_WritePin(&config->EN, GPIO_HIGH);
}

void L298_Backward(L298_Config *config)
{
    GPIO_WritePin(&config->IN1, GPIO_LOW);
    GPIO_WritePin(&config->IN2, GPIO_HIGH);
    GPIO_WritePin(&config->EN, GPIO_HIGH);
}

void L298_Stop(L298_Config *config)
{
    GPIO_WritePin(&config->IN1, GPIO_LOW);
    GPIO_WritePin(&config->IN2, GPIO_LOW);
    GPIO_WritePin(&config->EN, GPIO_LOW);
}