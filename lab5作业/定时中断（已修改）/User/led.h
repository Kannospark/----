#ifndef __LED_H__
#define __LED_H__

#include "sys.h"

#define LED_GPIO_PIN   GPIO_Pin_5
#define LED_GPIO_PORT  GPIOB
#define LED_GPIO_CLK  RCC_APB2Periph_GPIOB

void LED_GPIO_Config(void);
void LED_Change(void);

#endif

