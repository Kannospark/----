/*********************************
芯片：STM32F103ZET6
实现功能：输出100Hz方波
引脚：PA4
*************************************/

#include "stm32f10x.h" 
#include "led.h"
#include "timer_time.h"

uint16_t time=0;

int main(void)
{
	  static uint8_t i=0;
	  LED_GPIO_Config();
	  // 设置中断组为0
      NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	
	  
	  BASIC_TIM_Init();  
	
	  while(1)
		{
				if( time == 5)
				{
					time = 0;
					switch(i)
					{
					  case 0:LED_ON();i++;break;
  				      case 1:LED_OFF();i=0;break;
					}
				}		
	  	}
}






