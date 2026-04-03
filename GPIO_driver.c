#include "GPIO_driver.h"

void GPIO_PinInit(GPIO_PinConfig *config)
{
      volatile unsigned char *tris = TRIS_REG[config->port];
      volatile unsigned char *port = PORT_REG[config->port];
      if (config->direction == GPIO_INPUT)
      {
            // write 1 in tris register at the corresponding pin location
            *tris |= (1 << config->pin);
      }
      else
      {
            // write 0 in tris register at the corresponding pin location
            *tris &= ~(1 << config->pin);
            if (config->initial_state == GPIO_LOW)
            {
                  *port &= ~(1 << config->pin);
            }
            else
            {
                  *port |= (1 << config->pin);
            }
      }
}

void GPIO_WritePin(GPIO_PinConfig *config, uint8 value)
{
      volatile unsigned char *port = PORT_REG[config->port];
      if (value == GPIO_HIGH)
      {
            *port |= (1 << config->pin);
      }
      else
      {
            *port &= ~(1 << config->pin);
      }
}

uint8 GPIO_ReadPin(GPIO_PinConfig *config)
{

      return 0;
}

void GPIO_TogglePin(GPIO_PinConfig *config)
{
}