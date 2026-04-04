#include "embedded/GPIO_driver.h"
#include "embedded/MOTOR_driver.h"

// Configure which port the LCD is connected to
sbit LCD_RS at RC0_bit;
sbit LCD_EN at RC1_bit;
sbit LCD_D4 at RC2_bit;
sbit LCD_D5 at RC3_bit;
sbit LCD_D6 at RC4_bit;
sbit LCD_D7 at RC5_bit;

sbit LCD_RS_Direction at TRISC0_bit;
sbit LCD_EN_Direction at TRISC1_bit;
sbit LCD_D4_Direction at TRISC2_bit;
sbit LCD_D5_Direction at TRISC3_bit;
sbit LCD_D6_Direction at TRISC4_bit;
sbit LCD_D7_Direction at TRISC5_bit;

void main(void)
{

    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Out(1, 1, "Forward");

    GPIO_PinConfig sw1 = {PORTB_ID, 1, GPIO_INPUT, GPIO_LOW};
    GPIO_PinConfig sw2 = {PORTB_ID, 2, GPIO_INPUT, GPIO_LOW};
    GPIO_PinConfig sw3 = {PORTB_ID, 3, GPIO_INPUT, GPIO_LOW};

    L298_Config motor =
        {
            {PORTD_ID, 0, GPIO_OUTPUT, GPIO_LOW},
            {PORTD_ID, 1, GPIO_OUTPUT, GPIO_LOW},
            {PORTD_ID, 2, GPIO_OUTPUT, GPIO_LOW}};

    GPIO_PinInit(&sw1);
    GPIO_PinInit(&sw2);
    GPIO_PinInit(&sw3);

    L298_Init(&motor);

    while (1)
    {
        if (GPIO_ReadPin(&sw1) == GPIO_HIGH)
        {
            L298_Forward(&motor);
        }
        else if (GPIO_ReadPin(&sw2) == GPIO_HIGH)
        {
            L298_Backward(&motor);
        }
        else if (GPIO_ReadPin(&sw3) == GPIO_HIGH)
        {
            L298_Stop(&motor);
        }
    }
}