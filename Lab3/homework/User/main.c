#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "PWM.h"

uint8_t i;

int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
}
