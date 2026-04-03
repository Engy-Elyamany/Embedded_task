#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

typedef unsigned char uint8;
/* Direction */
#define GPIO_INPUT 1
#define GPIO_OUTPUT 0

/* Logic Levels */
#define GPIO_LOW 0
#define GPIO_HIGH 1

/* Port IDs */
#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3
#define PORTE_ID 4

typedef struct
{
    uint8 port;
    uint8 pin;
    uint8 direction;
    uint8 initial_state;

} GPIO_PinConfig;

static volatile unsigned char *TRIS_REG[] =
    {
        &TRISA,
        &TRISB,
        &TRISC,
        &TRISD,
        &TRISE};

static volatile unsigned char *PORT_REG[] =
    {
        &PORTA,
        &PORTB,
        &PORTC,
        &PORTD,
        &PORTE};

void GPIO_PinInit(GPIO_PinConfig *config);

void GPIO_WritePin(GPIO_PinConfig *config, uint8 value);

uint8 GPIO_ReadPin(GPIO_PinConfig *config);

void GPIO_TogglePin(GPIO_PinConfig *config);

#endif