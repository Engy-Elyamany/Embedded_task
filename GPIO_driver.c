#include "GPIO_driver.h"
#include "BIT_MATH.h"

void GPIO_PinInit(GPIO_PinConfig *config)
{
      volatile unsigned char *tris = TRIS_REG[config->port];
      volatile unsigned char *port = PORT_REG[config->port];
      if (config->direction == GPIO_INPUT)
      {
            // write 1 in tris register at the corresponding pin location
            SET_BIT(*tris,config->pin);
            //*tris |= (1 << config->pin);
      }
      else
      {
            // write 0 in tris register at the corresponding pin location
            *tris &= ~(1 << config->pin);
            if (config->initial_state == GPIO_LOW)
            {      CLR_BIT(*port, config->pin);
                  //*port &= ~(1 << config->pin);
            }
            else
            {      SET_BIT(*port,config->pin);
                  //*port |= (1 << config->pin);
            }
      }
}

void GPIO_WritePin(GPIO_PinConfig *config, uint8 value)
{
      volatile unsigned char *port = PORT_REG[config->port];
      if (value == GPIO_HIGH)
      {      SET_BIT(*port,config->pin);
            //*port |= (1 << config->pin);
      }
      else
      {      CLR_BIT(*port, config->pin);
            //*port &= ~(1 << config->pin);
      }
}

uint8 GPIO_ReadPin(GPIO_PinConfig *config)
{
      if(GET_BIT(*port,config->pin))
            return GPIO_HIGH;
      return GPIO_LOW;
}

void GPIO_TogglePin(GPIO_PinConfig *config)
{
      TOG_BIT(*port,config->pin);
}