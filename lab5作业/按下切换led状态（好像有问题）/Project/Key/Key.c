#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"

void Key_Init(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

uint8_t Key_Scan(void)
{
  if( GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == KEY_ON )
    {
      Delay_ms(5);
      if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == KEY_ON)
        {
// À… ÷ºÏ≤‚
          while( GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == KEY_ON );
          return KEY_ON;
        }
      else
        {
          return KEY_OFF;
        }
    }
  else
    {
      return KEY_OFF;
    }
}

